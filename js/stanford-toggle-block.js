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

  })(jQuery);

  }
};
