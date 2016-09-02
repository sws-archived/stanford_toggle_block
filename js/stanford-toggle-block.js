Drupal.behaviors.stanford_toggle_block = {
  attach: function(context, settings) {

  /**
   * Create the toggle block show/hide functionality.
   *
   * By adding click handlers
   * to the left side links. Add accessibility improvements by setting the tab
   * index order on the links within each toggle block.
   */
  (function ($) {

    // Index counter. For the tab index attribute. Needs to be global because
    // we want to increment with the dom.
    var $tabi = 1;

    // TODO: Make this in to a real plugin.
    $(".toggle-block", context).each(function(i, v) {

      // The toggle block we are working on.
      $me = $(v);

      // The left side links that will have the click handler to change the
      // feature content.
      $myLinks = $me.find(".toggle-links a");

      // Add a click handler that then shows/hides the correct feature content
      // and prevents the default click through.
      $myLinks.click(function(e) {

        // Stop the click through.
        // TODO: Change the default url to go somewhere so it still works
        // without javscript or to change them to a title instead of a link.
        e.preventDefault();

        // Handle the links active state by removing the active class from all
        // left sidebar links in this toggle block.
        $links = $(this).parents(".toggle-block").find(".toggle-links a");
        $links.removeClass("active");

        // This is the left side link we are currently iterating on.
        $(this).addClass("active");

        // Handle the features active state.
        $features = $(this).parents(".toggle-block").find(".toggle-block-feature");
        $features.removeClass("active");

        // The feature content we want to show has the same index, or order, in
        // which is appears in the dom as the left side link. We can use that
        // index to hide and show blocks using the active class and some css.
        // Transitions happen in css as well.
        $index = $links.index($(this));
        $features.eq($index).addClass("active");

      });

      // Loop through each of the left side links and increase the tab index by
      // one but before moving along to the next link increase the links in the
      // corresponding feature block by one so that the tab index goes from left
      // side link to right side feature and then back.
      $myLinks.each(function(ii, vv) {

        $thelink = $(vv);
        $thelink.attr("tabindex", $tabi++);

        // Incremental counter, increasing the button links within the block's
        // feature content content by 1.
        var $featureLinks = $thelink
                              .parents(".toggle-block")
                              .find(".toggle-block-feature")
                              .eq(ii)
                              .find(".field-name-field-s-toggle-links a");

        $featureLinks.attr("tabindex", $tabi++);
      });

    });

  })(jQuery);

  }
};
