Drupal.behaviors.stanford_toggle_block = {
  attach: function(context, settings) {

  (function ($) {

    var $tabi = 1;

    // TODO: Make this in to a plugin.
    $(".toggle-block", context).each(function(i, v) {
      $me = $(v);
      $myLinks = $me.find(".toggle-links a");
      $myLis = $me.find(".toggle-links > li");

      $myLinks.click(function(e) {

        // Stop the click through.
        e.preventDefault();

        // Handle the links active state.
        $lis = $(this).parents(".toggle-block").find(".toggle-links > li");
        $lis.removeClass("active");
        // Parent should be the li.
        $(this).parent().addClass("active");

        // Handle the features active state.
        $features = $(this).parents(".toggle-block").find(".toggle-block-feature");
        $features.removeClass("active");
        $index = $myLinks.index($(this));
        $features.eq($index).addClass("active");

      });

      // Incremental counter, increasing the link index count by 1
      $myLinks.each(function(ii, vv) {
        $thelink = $(vv);
        $thelink.attr("tabindex", $tabi++);
        // Incremental counter, increasing the button links within the block's content by 1
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
