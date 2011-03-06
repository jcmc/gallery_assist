<?php
// $Id: gallery-assist-item.tpl.php,v 1.0 2009/11/19 16:11:12 jcmc Exp $

/**
 * @file
 * Default theme implementation to display a Gallery Assist Item (image in this case).
 *
 * Available variables:
 * 
 * - $item: An object with the necesary content to display the gallery item.
 *   - contains
 *     - $item->nid
 *     - $item->nodetype
 *     - $item->title
 *     - $item->submitted
 *     - $item->preview_size
 *     - $item->img
 *     - $item->ppath
 *     - $item->ptitle
 *     - $item->pdescription
 *     - $item->copyright
 *     - $item->top
 *     - $item->pager
 *     - $item->adm_link
 *     - $item->download_path
 *     - $item->link
 *     - $item->links
 *     - $item->extra_styles
 * 
 * @see theme_gallery_assist_item()
 * @see gallery_assist_item_pager()
 * @see gallery-assist-pager.tpl.php
 */
?>

<div class="clear-block">
 
 <div id="node-<?php print $item->nid; ?>" class="node">
   
   <span class="submitted"><?php print $item->submitted; ?></span>
    
    <div class="clear-block"><?php print $item->links; ?></div>
      
      <div class="content clear-block">
      
      <!-- Print the pager acord settings. -->
      <?php if ($item->top == 1 || $item->top == 3) { ?>
        
        <div id="ga-pager" class="<?php print $item->nodetype; ?> ga-pager clear-block"><?php print $item->pager; ?></div>
      
      <?php } ?>

      <!-- Print the item image. -->
      <div id="ga-image-display" class="<?php print $item->nodetype; ?> ga-image-display" style="max-width:<?php print $item->preview_size; ?>px; max-height:<?php print $item->preview_size; ?>px;<?php print $item->extra_styles . $item->img_extra_styles; ?>">
        
        <?php print $item->img; ?>
      
      </div>
    
    <!-- Print the pager acord settings. -->
    <?php if ($item->top == 0 || $item->top == 3) { ?>
      
      <div id="ga-pager" class="<?php print $item->nodetype; ?> ga-pager clear-block"><?php print $item->pager; ?></div>
    
    <? } ?>
    
    <!-- Information from Author or copyright. -->
    <?php if (!empty($item->copyright)) { ?>
      
      <div id="gallery-item-copyright" class="<?php print $item->nodetype; ?> gallery-item-copyright" style="max-width:<?php print $item->preview_size; ?>px;<?php print $item->extra_styles; ?>">&copy; <?php print $item->copyright; ?></div>
    
    <? } ?>
    
     <!-- Title of the item (image). You can use the if condition as by copyright. -->
     <div id="gallery-item-caption-title" class="<?php print $item->nodetype; ?> gallery-item-caption-title" style="max-width:<?php print $item->preview_size; ?>px;<?php print $item->extra_styles; ?>"><?php print $item->ptitle; ?></div>
     
     <!-- Gallery item description. You can use the if condition as by copyright. -->
     <div id="gallery-item-caption-text" class="<?php print $item->nodetype; ?> gallery-item-caption-text" style="max-width:<?php print $item->preview_size; ?>px;<?php print $item->extra_styles; ?>"><?php print $item->pdescription; ?></div>
   
     <!-- Download link. -->
     <div id="gallery-item-download-link" class="<?php print $item->nodetype; ?> gallery-item-download-link" style="max-width:<?php print $item->preview_size; ?>px;<?php print $item->extra_styles; ?>">
       <a title="Download original image." href="<?php print $item->download_path; ?>">download</a>
     </div>
   
   </div>
 
 </div>

</div>

