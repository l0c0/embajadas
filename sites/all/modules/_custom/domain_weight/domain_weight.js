/*
* Josi:
*  
*/
(function ($) {
$(document).ready(function() {

	$('.not-front.logged-in.page-node-add #edit-field-domain-weight-js').bind('change', function(){
		/* index and value of select all weights*/
		var position = this.selectedIndex;
		var value = $(this).attr("value"); 
  
		/* each for all select update */
		$('#field-domain-weight-add-more-wrapper select').each(function(index) {
		/* set value for enabled select */
		 if($(this).is('[disabled]') == false){ $(this).attr("value",value) };
		});
  
	});


});  
}(jQuery));



