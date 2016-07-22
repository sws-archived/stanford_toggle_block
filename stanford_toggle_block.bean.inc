<?php
/**
 * @file
 * stanford_toggle_block.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function stanford_toggle_block_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_toggle_block';
  $bean_type->label = 'Toggle Block';
  $bean_type->options = '';
  $bean_type->description = 'Quick tabs like toggle block';
  $export['stanford_toggle_block'] = $bean_type;

  return $export;
}
