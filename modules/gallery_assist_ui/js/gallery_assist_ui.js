
(function ($) {

  Drupal.behaviors.ga_sort_items = function (context) {
    $("DIV#sort-items").sortable({
      update: ga_sort_save_changes,
      forcePlaceholderSize: true,
      revert: true
    });
    $("DIV#sort-items").disableSelection();
  }

  var ga_sort_save_changes = function () {
    var changes_array = $("DIV#sort-items").sortable('toArray');
    if (changes_array) {
      $.ajax({
        type: "POST",
        url: Drupal.settings.ga_settings.base_url + "/gallery_assist/ga_sort/js",
        data: "ga_sort_results="+changes_array,
        cache: false,
        dataType: "json"
      });
    }
  }
})(jQuery);
