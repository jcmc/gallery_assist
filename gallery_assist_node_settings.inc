<?php
// $Id: gallery_assist_node_settings.inc,v 1.8 2010/04/22 16:28:33 jcmc Exp $

/**
 * @file
 * 
 * This contain the form elements for the "Settings to this Gallery"."
 */

function gallery_assist_settings_tothis_node(&$node, $data) {

  $form['load_modi'] = array(
    '#type' => 'fieldset',
    '#title' => t('Items order'),
  );

  $form['load_modi']['ga_db_order_field'] = array(
    '#type' => 'select',
    '#title' => t('Field to order'),
    '#default_value' => $node->gallconf[$node->type]['ga_db_order_field'],
    '#options' => array('a.weight' => 'Weight', 'f.timestamp' => 'Upload date', 'a.filename' => 'File name', 'tp.ptitle' => 'Image title'),
   // '#prefix' => '<div class="gallery-assist-settings-left-half">',
   // '#suffix' => '</div>',
  );

  $form['load_modi']['ga_db_order'] = array(
    '#type' => 'select',
    '#title' => t('Order type'),
    '#default_value' => $node->gallconf[$node->type]['ga_db_order'],
    '#options' => array('DESC' => 'Descending', 'ASC' => 'Ascending'),
   // '#prefix' => '<div class="gallery-assist-settings-left-half">',
   // '#suffix' => '</div>',
  );

  $form['common'] = array(
    '#type' => 'fieldset',
    '#title' => t('Common'),
   // '#prefix' => '<div class="gallery-assist-settings">',
    '#access' => $data['common_settings_allowed'],
  );

  $form['common']['prefix'] = array(
    '#type' => 'markup',
    '#value' => '<div class="gallery-assist-settings-left-half">',
  );

  $h_li = array(
    t('privat: <em>Only the owner can see the gallery.</em>'),
    t('public: <em>Public for all authenticated users.</em>'),
    t('public for all: <em>Public for all users and anonymous.</em>'),
  );
  $form['common']['ga_public_status'] = array(
    '#type' => 'select',
    '#title' => t('Gallery Public Status'),
    '#default_value' => $node->gallconf[$node->type]['ga_public_status'],
    '#options' => array(0 => t('privat'), 1 => t('public'), 2 => t('public for all')),
    '#access' => $data['gallery_public_status_allowed'],
    '#description' => theme('item_list', $h_li, NULL, 'ul'),
  );

  $form['common']['gallery_assist_weight'] = array(
    '#type' => 'select',
    '#title' => t('Gallery container weight'),
    '#default_value' => $node->gallery_assist_weight,
    '#options' => drupal_map_assoc(range(-50, 50)),
    '#description' => t('Choose the gallery container position on this node.'),
    '#access' => $data['gallery_container_weight_allowed'],
  );

  $form['common']['show_layout'] = array(
    '#type' => 'select',
    '#title' => t('Show this gallery as'),
    '#default_value' => empty($node->gallconf[$node->type]['show_layout']) ? 'grid' : $node->gallconf[$node->type]['show_layout'],
    '#options' => array('list' => t('List'), 'grid' => t('Grid')),
    '#access' => $data['container_format_allowed'],
  );

  $form['common']['suffix0'] = array(
    '#type' => 'markup',
    '#value' => '</div><div>',
  );

  $this['show_title'] = $node->show_title == 1 ? t('Uncheck to hide the images titles.') : t('Check to display the image titles.');
  $form['common']['show_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show titles'),
    '#default_value' => $node->show_title,
    '#description' => $this['show_title'],
    '#access' => $data['show_titles_allowed'],
  );

  // Toggle to display or hide items shadows.
  // Now work this option only in Windows Firefox and Safary.
  $this['shadow'] = $node->shadow == 1 ? t('Uncheck to desable the items shadow. (only win)') : t('Check to enable the items shadow. (only win)');
  $form['common']['shadow'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shadow'),
    '#default_value' => $node->shadow,
    '#description' => $this['shadow'],
    '#access' => $data['gallery_items_shadow_allowed'], 
  );

  $form['common']['in_profile'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show in user profile'),
    '#default_value' => $node->in_profile,
    '#description' => '',
    '#access' => $data['show_in_userprofile_allowed'],
  );

  if ($node->uid == $user->uid || user_access('administer gallery_assist', $user) ||
    user_access('administer gallery_assist_'. $node->type, $user)) {
    $this['help']['block'] = array(
      'module' => 'gallery_assist',
      'help_link' => 'gallery-assist-block-options',
      'text' => t('Check to display this Gallery in the Site Galleries Block.'),
    );
    $help_string = gallery_assist_advanced_help_builder($this['help']['block']);
    $form['common']['show_in_homepage_block'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show in block'),
      '#default_value' => $node->show_in_homepage_block,
      '#description' => $help_string,
      '#access' => $data['show_in_homepage_block_allowed']
    );
  }

  $form['common']['endfix'] = array(
    '#type' => 'markup',
    '#value' => '</div>',
  );

  $this['help']['layout'] = array(
    'module' => 'gallery_assist',
    'help_link' => 'gallery-assist-node-layout-settings',
    'text' => t(''),
  );
  $form['layout'] = array(
    '#type' => 'fieldset',
    '#title' => t('Extra layout settings'),
    //'#collapsible' => TRUE,
    //'#collapsed' => TRUE,
    '#access' => $data['extra_layout_settings_allowed'],
    //'#description' => gallery_assist_advanced_help_builder($this['help']['layout']),
  );

  $form['layout']['teaser'] = array(
    '#type' => 'fieldset',
    '#title' => t('Teaser container'),
   // '#prefix' => '<div class="gallery-assist-settings-left">',
   // '#suffix' => '</div>',
    '#description' => t('Settings of the gallery container in the teaser view.'),
  );

  $form['layout']['page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page container'),
   // '#prefix' => '<div class="gallery-assist-settings-left">',
   // '#suffix' => '</div>',
    '#description' => t('Settings of the gallery container in the page view.'),
  );

  $form['layout']['preview'] = array(
    '#type' => 'fieldset',
    '#title' => t('Preview'),
   // '#prefix' => '<div class="gallery-assist-settings-left">',
   // '#suffix' => '</div>',
    '#description' => t('Settings of the gallery container in the image preview.'),
    '#access' => $data['display_download_link_allowed'],
  );

  $form['layout']['teaser']['ga_align'] = array(
    '#type' => 'select',
    '#title' => t('Align'),
    '#default_value' => $node->gallconf[$node->type]['layout']['ga_align'],
    '#options' => array('none' => t('none'), 'left' => t('left'), 'center' => t('center'), 'right' => t('right')),
  );

  $form['layout']['teaser']['t_ga_float'] = array(
    '#type' => 'select',
    '#title' => t('Float'),
    '#default_value' => $node->gallconf[$node->type]['layout']['t_ga_float'],
    '#options' => array('none' => t('none'), 'left' => t('left'), 'right' => t('right')),
  );

  $form['layout']['page']['gap_align'] = array(
    '#type' => 'select',
    '#title' => t('Align'),
    '#default_value' => $node->gallconf[$node->type]['layout']['gap_align'],
    '#options' => array('none' => t('none'), 'left' => t('left'), 'center' => t('center'), 'right' => t('right')),
  );

  $form['layout']['page']['p_ga_float'] = array(
    '#type' => 'select',
    '#title' => t('Float'),
    '#default_value' => $node->gallconf[$node->type]['layout']['p_ga_float'],
    '#options' => array('none' => t('none'), 'left' => t('left'), 'right' => t('right')),
  );

  $this['help']['hide_teaser'] = array(
    'module' => 'gallery_assist',
    'help_link' => 'gallery-assist-node-layout-settings',
    'text' => t('If checked Gallery Assist will not show the gallery container in the teaser view.'),
  );
  $help_string = gallery_assist_advanced_help_builder($this['help']['hide_teaser']);
  $form['layout']['teaser']['hide_in_teaser'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide container in teaser'),
    '#default_value' => $node->gallconf[$node->type]['hide_in_teaser'],
    '#description' => $help_string,
    '#access' => $data['hide_teaser_container_allowed'],
  );

  $form['layout']['preview']['show_download_link'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display the download link'),
    '#default_value' => $node->gallconf[$node->type]['show_download_link'],
   // '#prefix' => '<div class="gallery-assist-settings-left-30">',
   // '#suffix' => '</div>',
    '#access' => $data['display_download_link_allowed'],
    '#disabled' => empty($node->gallconf[$node->type]['show_download_link']) ? TRUE : FALSE,
  );

  $form['layout']['preview']['show_download_link_old'] = array(
    '#type' => 'hidden',
    '#value' => $node->gallconf[$node->type]['show_download_link'],
  );

  if (module_exists('gallery_assist_comments')) {
    $form['layout']['preview']['comments'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable or disable comments for the items of this gallery'),
      '#default_value' => $node->comments,
      '#access' =>  empty($data['comments']) || $data['comments'] == 0 ? FALSE : TRUE,
    );
    $form['layout']['preview']['comments_old'] = array(
      '#type' => 'hidden',
      '#value' => $node->comments,
      '#access' =>  empty($data['comments']) || $data['comments'] == 0 ? FALSE : TRUE,
    );
  }

  return $form;
}
