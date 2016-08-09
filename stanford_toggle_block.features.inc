<?php
/**
 * @file
 * stanford_toggle_block.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_toggle_block_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "bean" && $api == "types") {
    return array("version" => "5");
  }
}
