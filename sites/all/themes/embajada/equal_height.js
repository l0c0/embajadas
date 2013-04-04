(function ($) {
	
	$(document).ready(function() {
		var highestCol = Math.max($('.first-menu .pane-content').height(),$('.middle-menu .pane-content').height(),$('.last-menu .pane-content').height());
		$('.front #region-content .panel-panel.grid-4').height(highestCol + 50);
		$('.first-menu .pane-content, .middle-menu .pane-content, .last-menu .pane-content').height(highestCol);
		
		
		
		
		});
	
})(jQuery);  
