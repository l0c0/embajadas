(function ($) {
	
	$(document).ready(function() {
		var ob_text = $('#block-search-form input:text');
		ob_text.val(Drupal.t('Enter Text'));
       
		text=ob_text.val();
	
		ob_text.bind('click focus', function() {
		if (ob_text.val() == text){
         ob_text.val('');
         }
		});

		ob_text.blur(function() {
		if ($.trim(ob_text.val())==''){
         ob_text.val(text);
         }
		});
	
 });

})(jQuery);  
