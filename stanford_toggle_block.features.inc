<?php
/**
 * @file
 * stanford_toggle_block.features.inc
 */

/**
 * Implements hook_bean_types_api_info().
 */
function stanford_toggle_block_bean_types_api_info($module = NULL, $api = NULL) {
  if ($module == "bean" && $api == "types") {
    return array("version" => "5");
  }
}

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_toggle_block_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
