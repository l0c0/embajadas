(function ($) {

  $(document).ready(function(){

    $("#edit-tipo").change(function(event) {
      if ($("#edit-tipo").val() > 0) {
	  $.get(Drupal.t('/zcancille/@nid', {'@nid': $("#edit-tipo").val()}),
	  function(data){
		$("#markup-node").html(data);
      });
      }
    });
    
    $("#edit-finder-datepicker-popup-0-wrapper").change(function(event) {
      $('#zcancille-newsroom-calendar-form').submit();
    });
    
  });

})(jQuery);