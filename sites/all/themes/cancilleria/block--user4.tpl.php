<div class="<?php if (isset($classes)) print $classes; ?>" id="<?php print $block_html_id; ?>"<?php print $attributes; ?>>
<div class="Cancilleria_box Cancilleria_post">
<div class="Cancilleria_box-body Cancilleria_post-body">
<article class="Cancilleria_post-inner Cancilleria_article">
<?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
<h2 class="Cancilleria_postheader"><?php print $block->subject ?></h2>
<?php endif;?>
<?php print render($title_suffix); ?>
<div class="Cancilleria_postcontent">
<div class="Cancilleria_article content">
<?php print $content; ?>
</div>
</div>
<div class="cleared"></div>
</article>
<div class="cleared"></div>
</div>
</div>
</div>
