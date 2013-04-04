(function ($) {
	
	$(document).ready(function() {
		var site_title = $('header .views-field-title a');
		var block_title = $('.first-menu h2.pane-title');
		if ((site_title.text().substring(0,24).toLowerCase())== "embajada de colombia en ") {
			block_title.html( Drupal.t("Colombian Embassy in @consulate", {'@consulate':site_title.text().substring(24, site_title.text().length)}) );
			}
		
		});
	
})(jQuery);  
