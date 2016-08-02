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
    $content["bean"][$bean->delta]["#bundle"] = "stanford_toggle_block";

    $left['title']["#markup"] = "<h2 class=\"toggle-block-title\">" . $bean->title . "</h2>";

    // Set up the theme render arrays.
    $left['links']['#theme'] = "item_list";
    $left['links']['#items'] = array();
    $left['links']['#type'] = 'ul';
    $left['links']['#attributes'] = array("class" => "toggle-links", "id" => "toggle-block-" . $bean->delta);

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

      // Active on #1.
      $active = "";
      if ($first) {
        $active = "active";
        $first = FALSE;
      }

      // Toggle Links.
      $toggle_link = isset($fc->field_s_toggle_links[LANGUAGE_NONE][0]['url']) ? $fc->field_s_toggle_links[LANGUAGE_NONE][0]['url'] : "#";
      $left['links']['#items'][] = l($fc->field_s_toggle_link_label[LANGUAGE_NONE][0]['value'], $toggle_link, array("attributes" => array("class" => $active)));

      // Feature block.
      $right[$fc->item_id]["#prefix"] = "<div class=\"toggle-block-feature $active\" id=\"toggle-feature-" . $fc->item_id . "\">";
      $right[$fc->item_id]["#suffix"] = "</div>";

      // Image.
      $right[$fc->item_id]['image'] = field_view_field('field_collection_item', $fc, 'field_s_toggle_image', array("label" => "hidden"));
      $right[$fc->item_id]['image']["#prefix"] = "<div class=\"toggle-block-image\">";
      $right[$fc->item_id]['image']["#suffix"] = "</div>";
      $right[$fc->item_id]['image']["#weight"] = 0;

      $body = array();
      $body['body'] = field_view_field('field_collection_item', $fc, 'field_s_toggle_content', array("label" => "hidden"));
      $body['links'] = field_view_field('field_collection_item', $fc, 'field_s_toggle_links', array("label" => "hidden"));
      $body['links']['#weight'] = 5;

      // Content.
      $right[$fc->item_id]['content'] = $body;
      $right[$fc->item_id]['content']["#prefix"] = "<div class=\"toggle-block-content\">";
      $right[$fc->item_id]['content']["#suffix"] = "</div>";
      $right[$fc->item_id]['content']["#weight"] = 10;

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
