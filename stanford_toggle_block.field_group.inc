<?php
/**
 * @file
 * stanford_toggle_block.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_toggle_block_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_toggle_block_item|field_collection_item|field_s_toggle_tab|form';
  $field_group->group_name = 'group_s_toggle_block_item';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_toggle_tab';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content & Images',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_toggle_content',
      1 => 'field_s_toggle_image',
      2 => 'field_s_toggle_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Content & Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_s_toggle_block_item|field_collection_item|field_s_toggle_tab|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_toggle_block_link|field_collection_item|field_s_toggle_tab|form';
  $field_group->group_name = 'group_toggle_block_link';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_toggle_tab';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add/Edit Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_toggle_content',
      1 => 'field_s_toggle_image',
      2 => 'field_s_toggle_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add/Edit Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_toggle_block_link|field_collection_item|field_s_toggle_tab|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add/Edit Content');
  t('Content & Images');

  return $field_groups;
}
