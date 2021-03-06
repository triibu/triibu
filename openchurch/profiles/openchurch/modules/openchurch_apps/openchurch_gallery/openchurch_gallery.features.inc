<?php
/**
 * @file
 * openchurch_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openchurch_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function openchurch_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function openchurch_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: oc_album_cover.
  $styles['oc_album_cover'] = array(
    'name' => 'oc_album_cover',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 170,
          'height' => 110,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'oc_album_cover',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function openchurch_gallery_node_info() {
  $items = array(
    'openchurch_gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('Galleries are collections of images with descriptions.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
