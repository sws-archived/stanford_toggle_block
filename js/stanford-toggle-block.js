Drupal.behaviors.stanford_toggle_block = {
  attach: function(context, settings) {

  (function ($) {

    // TODO: Make this in to a plugin.
    $(".toggle-block", context).each(function(i, v) {
      $me = $(v);
      $myLinks = $me.find(".toggle-links a");

      $myLinks.click(function(e) {

        // Stop the click through.
        e.preventDefault();

        // Handle the links active state.
        $links = $(this).parents(".toggle-block").find(".toggle-links a");
        $links.removeClass("active");
        $(this).addClass("active");

        // Handle the features active state.
        $features = $(this).parents(".toggle-block").find(".toggle-block-feature");
        $features.removeClass("active");
        $index = $links.index($(this));
        $features.eq($index).addClass("active");

      });

    });

    // For each toggle block
    // Find all left sidebar links
    // For each sidebar link set the tab index and increment the indexcount by 1
    // Then find all of the links in the right sidebar block that match the left link
    // Add a tab index to each of those and increment by one each time
    // Move on to the next left sidebar link and repeat

    // $(toggle-block).each()
    //  $links = $toggle-block.find("toggle-links a")
    //    $links.each()
    //      $(features).index(of toggle link).each()
    //        tabindex ++
    //

  })(jQuery);

  }
};
