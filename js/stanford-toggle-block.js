Drupal.behaviors.stanford_toggle_block = {
  attach: function(context, settings) {

  (function ($) {

    // TODO: Make this in to a plugin.
    $(".toggle-block", context).each(function(i, v) {
      $me = $(v);
      $links = $me.find(".su-toggle-links a");

      $links.click(function(e) {
        e.preventDefault();
        $links = $(this).parents(".toggle-block").find(".su-toggle-links a");
        $features = $(this).parents(".toggle-block").find(".toggle-block-feature");
        $features.removeClass("active");
        $index = $links.index($(this));
        $features.eq($index).addClass("active");
      });

    });

  })(jQuery);

  }
};
