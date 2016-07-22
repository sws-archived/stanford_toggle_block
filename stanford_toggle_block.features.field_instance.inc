<?php
/**
 * @file
 * stanford_toggle_block.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_toggle_block_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-stanford_toggle_block-field_s_toggle_tab'.
  $field_instances['bean-stanford_toggle_block-field_s_toggle_tab'] = array(
    'bundle' => 'stanford_toggle_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 0,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_s_toggle_tab',
    'label' => 'Toggle Tab',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_s_toggle_tab-field_s_toggle_content'.
  $field_instances['field_collection_item-field_s_toggle_tab-field_s_toggle_content'] = array(
    'bundle' => 'field_s_toggle_tab',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Featured content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_s_toggle_content',
    'label' => 'Feature Content',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'content_editor_text_format' => 0,
          'filtered_html' => 'filtered_html',
          'full_html' => 0,
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'content_editor_text_format' => array(
              'weight' => -10,
            ),
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_s_toggle_tab-field_s_toggle_image'.
  $field_instances['field_collection_item-field_s_toggle_tab-field_s_toggle_image'] = array(
    'bundle' => 'field_s_toggle_tab',
    'deleted' => 0,
    'description' => 'Feature Image',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'large-scaled',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_s_toggle_image',
    'label' => 'Feature Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'toggle-block',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__3-col-header' => 0,
          'colorbox__4-col-header' => 0,
          'colorbox__6-col-banner' => 0,
          'colorbox__6-col-banner-short' => 0,
          'colorbox__6-col-banner-tall' => 0,
          'colorbox__6-col-photo-landscape' => 0,
          'colorbox__8-col-banner' => 0,
          'colorbox__8-col-banner-short' => 0,
          'colorbox__8-col-banner-tall' => 0,
          'colorbox__9-col-banner' => 0,
          'colorbox__9-col-banner-short' => 0,
          'colorbox__12-col-banner' => 0,
          'colorbox__12-col-banner-tall' => 0,
          'colorbox__banner-850x400' => 0,
          'colorbox__full-width-banner' => 0,
          'colorbox__full-width-banner-short' => 0,
          'colorbox__half-page-profile' => 0,
          'colorbox__huge-landscape' => 0,
          'colorbox__icon-profile' => 0,
          'colorbox__icon-scaled' => 0,
          'colorbox__icon-square' => 0,
          'colorbox__large' => 0,
          'colorbox__large-landscape' => 0,
          'colorbox__large-landscape-scaled' => 0,
          'colorbox__large-profile' => 0,
          'colorbox__large-profile-scaled' => 0,
          'colorbox__large-scaled' => 0,
          'colorbox__large-square' => 0,
          'colorbox__med-landscape' => 0,
          'colorbox__med-landscape-scaled' => 0,
          'colorbox__med-profile' => 0,
          'colorbox__med-profile-scaled' => 0,
          'colorbox__med-square' => 0,
          'colorbox__medium' => 0,
          'colorbox__page-width' => 0,
          'colorbox__sm-landscape' => 0,
          'colorbox__sm-profile' => 0,
          'colorbox__sm-profile-scaled' => 0,
          'colorbox__sm-scaled' => 0,
          'colorbox__sm-square' => 0,
          'colorbox__thmb-landscape' => 0,
          'colorbox__thmb-profile' => 0,
          'colorbox__thmb-square' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_3-col-header' => 0,
          'image_4-col-header' => 0,
          'image_6-col-banner' => 0,
          'image_6-col-banner-short' => 0,
          'image_6-col-banner-tall' => 0,
          'image_6-col-photo-landscape' => 0,
          'image_8-col-banner' => 0,
          'image_8-col-banner-short' => 0,
          'image_8-col-banner-tall' => 0,
          'image_9-col-banner' => 0,
          'image_9-col-banner-short' => 0,
          'image_12-col-banner' => 0,
          'image_12-col-banner-tall' => 0,
          'image_banner-850x400' => 0,
          'image_full-width-banner' => 0,
          'image_full-width-banner-short' => 0,
          'image_half-page-profile' => 0,
          'image_huge-landscape' => 0,
          'image_icon-profile' => 0,
          'image_icon-scaled' => 0,
          'image_icon-square' => 0,
          'image_large' => 0,
          'image_large-landscape' => 0,
          'image_large-landscape-scaled' => 0,
          'image_large-profile' => 0,
          'image_large-profile-scaled' => 0,
          'image_large-scaled' => 0,
          'image_large-square' => 0,
          'image_med-landscape' => 0,
          'image_med-landscape-scaled' => 0,
          'image_med-profile' => 0,
          'image_med-profile-scaled' => 0,
          'image_med-square' => 0,
          'image_medium' => 0,
          'image_page-width' => 0,
          'image_sm-landscape' => 0,
          'image_sm-profile' => 0,
          'image_sm-profile-scaled' => 0,
          'image_sm-scaled' => 0,
          'image_sm-square' => 0,
          'image_thmb-landscape' => 0,
          'image_thmb-profile' => 0,
          'image_thmb-square' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_s_toggle_tab-field_s_toggle_link_label'.
  $field_instances['field_collection_item-field_s_toggle_tab-field_s_toggle_link_label'] = array(
    'bundle' => 'field_s_toggle_tab',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_s_toggle_link_label',
    'label' => 'Toggle Link Label',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'content_editor_text_format' => 'content_editor_text_format',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'content_editor_text_format' => array(
              'weight' => -10,
            ),
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_s_toggle_tab-field_s_toggle_links'.
  $field_instances['field_collection_item-field_s_toggle_tab-field_s_toggle_links'] = array(
    'bundle' => 'field_s_toggle_tab',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Big buttony links that appear below the feature content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_s_toggle_links',
    'label' => 'Feature Links',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => 'btn feature-btn',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Big buttony links that appear below the feature content.');
  t('Feature Content');
  t('Feature Image');
  t('Feature Links');
  t('Featured content.');
  t('Toggle Link Label');
  t('Toggle Tab');

  return $field_instances;
}
