<?php
// $Id: hooks.php,v 1.1 2010/05/18 22:27:32 jcmc Exp $

/**
 * @file
 * This file provide additional documentation for doxygen.
 * These are the hooks that are invoked by the Gallery Assist core.
 *
 * Core hooks are typically called in all modules at once using
 * module_invoke_all().
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * It extend the output from a Gallery Assist image in the preview
 * with added code and implemented functionalities by other modules.
 *
 * @param string $op
 *   Action options. Posible values:
 *   - load:
 *   - view:
 * @param integer $pid
 *   The image ID.
 * @param object $node_light
 *   An object containing the following values:
 *   - nid: The node ID.
 *   - uid: The user ID.
 *   - pid: The image ID.
 *   - ref: The node translation reference ID.
 *   - gid: The gallery ID
 *   - gref: The gallery translation reference ID.
 *   - nodetype: The node type.
 *   - title: The node title.
 *   - submitted: The satinized submmited string.
 *   - preview_size: The preview size. Important to use for the layout.
 *   - img:
 *   - ppath:
 *   - ptitle:
 *   - pdescription: The description of the image.
 *   - copyright: The copiright of the image.
 *   - top:
 *   - pager:
 *   - adm_link:
 *   - allow_download:
 *   - download_path:
 *   - link:
 *   - links:
 *   - extra_styles:
 *   - img_extra_styles: Styles which are be used by the preview output.
 *   - node_settings: An array containing the settings data from the respective module.
 *
 * An example of usage of this hook is live available from:
 * @link http://www.drupal.org/project/gallery_assist_comments @endlink
 *
 */
function hook_ga_expand($op, $pid, $node_light) {
  $output = array();
  switch ($op) {
    case 'load':
      // example code here...
      break;

    case 'view':
      // The returned code can be an string.
      $output = your_output_code('String');
      // An simple array().
      $output = array(
        '#value' => example_function('Simple array'),
        '#weight' => 20,
      );
      // Or an array() with multiple keys.
      $output['field_name_1'] = array(
        '#value' => example_function('Array with '),
        '#weight' => 15,
        '#prefix' => '<div style="height:20px;background:maroon;"></div>',
        '#suffix' => '<div style="height:20px;background:maroon;"></div>'
      );
      $output['field_name_2'] = array(
        '#value' => example_function(),
        '#weight' => 15,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#prefix' => '<div style="height:20px;background:maroon;"></div>',
        '#suffix' => '<div style="height:20px;background:maroon;"></div>'
      );
      break;
  }
}

function example_function($in) {
  return '';
}