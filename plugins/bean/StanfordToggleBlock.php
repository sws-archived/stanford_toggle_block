<?php
/**
 * @file
 * StanfordToggleBlock
 */

class StanfordToggleBlock extends BeanDefault {

  /**
   * Return the block content.
   *
   * @TODO: change both left and right to views.)
   *
   * @param $bean
   *   The bean object being viewed.
   * @param $content
   *   The default content array created by Entity API.  This will include any
   *   fields attached to the entity.
   * @param $view_mode
   *   The view mode passed into $entity->view().
   * @return
   *   Return a renderable content array.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {

    // Holders for content.
    $left = NULL;
    $right = NULL;

    if (!isset($content['bean'][$bean->delta]['field_s_toggle_tab'])) {
      drupal_set_message("Could not find field_s_toggle_tab on toggle block", "error", TRUE);
      return $content;
    }

    // Nuke the existing content.
    $content = array();

    // Set up the theme render arrays.
    $right['links']['#theme'] = "item_list";
    $right['links']['#items'] = array();
    $right['links']['#type'] = 'ul';
    $right['links']['#attributes'] = array("class" => "su-toggle-links", "id" => "toggle-block-" . $bean->delta);

    // Loop through the field collections and create the toggle links.
    // And feature content.

    // Get the ids for the field collections from the field.
    $field_collection_ids = array_map(
      function($field_values) {
        return $field_values['value'];
      },
      $bean->field_s_toggle_tab[LANGUAGE_NONE]
    );

    // Load all the field collections.
    $field_collections = entity_load("field_collection_item", $field_collection_ids);

    $first = TRUE;
    foreach ($field_collections as $fc) {

      // Toggle Links.
      $toggle_link = isset($fc->field_s_toggle_links[LANGUAGE_NONE][0]['url']) ? $fc->field_s_toggle_links[LANGUAGE_NONE][0]['url'] : "#";
      $right['links']['#items'][] = l($fc->field_s_toggle_link_label[LANGUAGE_NONE][0]['value'], $toggle_link);

      // Active on #1.
      $active = "";
      if ($first) {
        $active = "active";
        $first = FALSE;
      }

      // Feature block.
      $left[$fc->item_id]["#prefix"] = "<div class=\"toggle-block-feature $active\" id=\"toggle-feature-" . $fc->item_id . "\">";
      $left[$fc->item_id]["#suffix"] = "</div>";

      // Image.
      $left[$fc->item_id]['image'] = field_view_field('field_collection_item', $fc, 'field_s_toggle_image', array("label" => "hidden"));
      $left[$fc->item_id]['image']["#prefix"] = "<div class=\"toggle-block-image\">";
      $left[$fc->item_id]['image']["#suffix"] = "</div>";
      $left[$fc->item_id]['image']["#weight"] = 0;

      // Content.
      $left[$fc->item_id]['content'] = field_view_field('field_collection_item', $fc, 'field_s_toggle_content', array("label" => "hidden"));
      $left[$fc->item_id]['content']["#prefix"] = "<div class=\"toggle-block-content\">";
      $left[$fc->item_id]['content']["#suffix"] = "</div>";
      $left[$fc->item_id]['content']["#weight"] = 10;

      // Links.
      $left[$fc->item_id]['links'] = field_view_field('field_collection_item', $fc, 'field_s_toggle_links', array("label" => "hidden"));
      $left[$fc->item_id]['links']["#prefix"] = "<div class=\"toggle-block-links\">";
      $left[$fc->item_id]['links']["#suffix"] = "</div>";
      $left[$fc->item_id]['links']["#weight"] = 20;

    }

    $content["#prefix"] = "<div class=\"toggle-block\" id=\"toggle-block-" . drupal_clean_css_identifier($bean->delta) . "\">";
    $content["#suffix"] = "</div>";

    // Set the left and right content.
    $content['left'] = $left;
    $content['left']["#prefix"] = "<div class=\"left-side\">";
    $content['left']["#suffix"] = "</div>";

    $content['right'] = $right;
    $content['right']["#prefix"] = "<div class=\"right-side\">";
    $content['right']["#suffix"] = "</div>";

    // Add some CSS and JS.
    $content["#attached"] = array(
      "js" => array(drupal_get_path("module", "stanford_toggle_block") . "/js/stanford-toggle-block.js"),
      "css" => array(drupal_get_path("module", "stanford_toggle_block") . "/css/stanford-toggle-block.css"),
    );

    // Return it.
    return $content;
  }

}
