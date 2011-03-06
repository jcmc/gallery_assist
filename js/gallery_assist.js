// This is only a test behavior
// drupal_add_js(drupal_get_path('module', 'gallery_assist').'/js/gallery_assist.js', 'module', 'footer');

Drupal.behaviors.ga_warning_by_change_title = function (context) {
  $('#gallery-assist-list .form-item .form-text:not(.image-box-processed)', context).addClass('image-box-processed').keyup(function () {
    var id = $(this).attr('id');
    $('#' + id).css('background', '#FFFFDD');
    $('#my-' + id).css('display', 'block');
    $('#edit-picsubmit').css('background-color', '#F0C020');
  }).blur(function() {
    var id = $(this).attr('id');
    $('#my-' + id).css('display', 'none');
  });
}

Drupal.behaviors.ga_warning_by_change_caption = function (context) {
  $('#gallery-assist-list .form-item .form-textarea:not(.image-box-processed)', context).addClass('image-box-processed').keyup(function () {
    var id = $(this).attr('id');
    $('#' + id).css('background', '#FFFFDD');
    $('#my-' + id).css('display', 'block');
    $('#edit-picsubmit').css('background-color', '#F0C020');
  }).blur(function() {
    var id = $(this).attr('id');
    $('#my-' + id).css('display', 'none');
  });
}

Drupal.behaviors.ga_check_all = function (context) {
  $(".ga-check-all").click(function () {
    $("#gallery-assist-list .form-checkbox").attr("checked", true);
  });
  $(".ga-uncheck-all").click(function () {
    $("#gallery-assist-list .form-checkbox").attr("checked", false);
  });
}
