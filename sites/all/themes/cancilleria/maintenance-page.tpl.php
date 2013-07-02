<?php
$vars = get_defined_vars();
$view = get_artx_drupal_view();
$view->print_maintenance_head($vars);
if (isset($page))
foreach (array_keys($page) as $name)
$$name = & $page[$name];
$art_sidebar_left = isset($sidebar_left) && !empty($sidebar_left) ? $sidebar_left : NULL;
$art_sidebar_right = isset($sidebar_right) && !empty($sidebar_right) ? $sidebar_right : NULL;
if (!isset($vnavigation_left)) $vnavigation_left = NULL;
if (!isset($vnavigation_right)) $vnavigation_right = NULL;
$tabs = (isset($tabs) && !(empty($tabs))) ? '<ul class="arttabs_primary">'.render($tabs).'</ul>' : NULL;
$tabs2 = (isset($tabs2) && !(empty($tabs2))) ?'<ul class="arttabs_secondary">'.render($tabs2).'</ul>' : NULL;
?>

<div id="Cancilleria_main">
    <div class="Cancilleria_sheet clearfix">
<header class="Cancilleria_header clearfix"><?php if (!empty($art_header)) { echo render($art_header); } ?>


    <div class="Cancilleria_shapes">


            </div>

<?php if (!empty($navigation) || !empty($extra1) || !empty($extra2)): ?>
<nav class="Cancilleria_nav clearfix">
     
    <?php if (!empty($extra1)) : ?>
<div class="Cancilleria_hmenu-extra1"><?php echo render($extra1); ?></div>
<?php endif; ?>
<?php if (!empty($extra2)) : ?>
<div class="Cancilleria_hmenu-extra2"><?php echo render($extra2); ?></div>
<?php endif; ?>
<?php if (!empty($navigation)) : ?>
<?php echo art_hmenu_output(render($navigation)); ?>
<?php endif; ?>
</nav><?php endif; ?>


                    
</header>
<?php if (!empty($banner1)) { echo '<div id="banner1">'.render($banner1).'</div>'; } ?>
<?php echo art_placeholders_output(render($top1), render($top2), render($top3)); ?>
<div class="Cancilleria_layout-wrapper clearfix">
                <div class="Cancilleria_content-layout">
                    <div class="Cancilleria_content-layout-row">
                        <?php if (!empty($art_sidebar_left) || !empty($vnavigation_left)) : ?>
<div class="Cancilleria_layout-cell Cancilleria_sidebar1 clearfix"><?php echo render($vnavigation_left); ?>
<?php echo render($art_sidebar_left); ?>
</div><?php endif; ?>
                        <div class="Cancilleria_layout-cell Cancilleria_content clearfix"><?php if (!empty($banner2)) { echo '<div id="banner2">'.render($banner2).'</div>'; } ?>
<?php if ((!empty($user1)) && (!empty($user2))) : ?>
<table class="position" cellpadding="0" cellspacing="0" border="0">
<tr valign="top"><td class="half-width"><?php echo render($user1); ?></td>
<td><?php echo render($user2); ?></td></tr>
</table>
<?php else: ?>
<?php if (!empty($user1)) { echo '<div id="user1">'.render($user1).'</div>'; }?>
<?php if (!empty($user2)) { echo '<div id="user2">'.render($user2).'</div>'; }?>
<?php endif; ?>
<?php if (!empty($banner3)) { echo '<div id="banner3">'.render($banner3).'</div>'; } ?>

<?php if (!empty($breadcrumb)): ?>
<article class="Cancilleria_post Cancilleria_article">
                                
                                                
                <div class="Cancilleria_postcontent"><?php { echo $breadcrumb; } ?>
</div>
                                
                </article><?php endif; ?>
<?php $art_post_position = strpos(render($content), "Cancilleria_postcontent"); ?>
<?php if (($is_front) || (isset($node) && isset($node->nid))): ?>

<?php if (!empty($tabs) || !empty($tabs2)): ?>
<article class="Cancilleria_post Cancilleria_article">
                                
                                                
                <div class="Cancilleria_postcontent"><?php if (!empty($tabs)) { echo $tabs.'<div class="cleared"></div>'; }; ?>
<?php if (!empty($tabs2)) { echo $tabs2.'<div class="cleared"></div>'; } ?>
</div>
                                
                </article><?php endif; ?>

<?php if (!empty($mission) || !empty($help) || !empty($messages) || !empty($action_links)): ?>
<article class="Cancilleria_post Cancilleria_article">
                                
                                                
                <div class="Cancilleria_postcontent"><?php if (isset($mission) && !empty($mission)) { echo '<div id="mission">'.$mission.'</div>'; }; ?>
<?php if (!empty($help)) { echo render($help); } ?>
<?php if (!empty($messages)) { echo $messages; } ?>
<?php if (isset($action_links) && !empty($action_links)): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
</div>
                                
                </article><?php endif; ?>

<?php if ($art_post_position === FALSE): ?>
<article class="Cancilleria_post Cancilleria_article">
                                
                                                
                <div class="Cancilleria_postcontent"><?php endif; ?>
<?php echo art_content_replace(render($content)); ?>
<?php if ($art_post_position === FALSE): ?>
</div>
                                
                </article><?php endif; ?>

<?php else: ?>

<article class="Cancilleria_post Cancilleria_article">
                                
                                                
                <div class="Cancilleria_postcontent"><?php if (!empty($title)): print '<h2'. ($tabs ? ' class="with-tabs"' : '') .'>'. $title .'</h2>'; endif; ?>
<?php if (!empty($tabs)) { echo $tabs.'<div class="cleared"></div>'; }; ?>
<?php if (!empty($tabs2)) { echo $tabs2.'<div class="cleared"></div>'; } ?>
<?php if (isset($mission) && !empty($mission)) { echo '<div id="mission">'.$mission.'</div>'; }; ?>
<?php if (!empty($help)) { echo render($help); } ?>
<?php if (!empty($messages)) { echo $messages; } ?>
<?php if (isset($action_links) && !empty($action_links)): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
<?php if ($art_post_position): ?>
      </div>
    </article>
  <?php echo art_content_replace(render($content)); ?>
<?php else: ?>
  <?php echo art_content_replace(render($content)); ?>
</div>
                                
                </article>
<?php endif; ?>
<?php endif; ?>

<?php if (!empty($banner4)) { echo '<div id="banner4">'.render($banner4).'</div>'; } ?>
<?php if ((!empty($user3)) && (!empty($user4))) : ?>
<table class="position" cellpadding="0" cellspacing="0" border="0">
<tr valign="top"><td class="half-width"><?php echo render($user3); ?></td>
<td><?php echo render($user4); ?></td></tr>
</table>
<?php else: ?>
<?php if (!empty($user3)) { echo '<div id="user3">'.render($user3).'</div>'; }?>
<?php if (!empty($user4)) { echo '<div id="user4">'.render($user4).'</div>'; }?>
<?php endif; ?>
<?php if (!empty($banner5)) { echo '<div id="banner5">'.render($banner5).'</div>'; } ?>
</div>
                    </div>
                </div>
            </div><?php echo art_placeholders_output(render($bottom1), render($bottom2), render($bottom3)); ?>
<?php if (!empty($banner6)) { echo '<div id="banner6">'.render($banner6).'</div>'; } ?>
<footer class="Cancilleria_footer clearfix"><?php
$footer = render($footer_message);
if (isset($footer) && !empty($footer) && (trim($footer) != '')) { echo $footer; } // From Drupal structure
elseif (!empty($art_footer) && (trim($art_footer) != '')) { echo $art_footer; } // From Artisteer Content module
else { // HTML from Artisteer preview
ob_start(); ?>

<div class="Cancilleria_content-layout-wrapper layout-item-old-0">
<div class="Cancilleria_content-layout layout-item-old-1">
<div class="Cancilleria_content-layout-row">
<div class="Cancilleria_layout-cell layout-item-old-2" style="width: 100%">
<p><strong>Ministerio de Relaciones Exteriores</strong></p>
<p>Palacio de San Carlos: Calle 10 No. 5-51 Bogotá D.C., Colombia - Horario de atención: lunes a viernes de 8:00 am a 5:00 pm<br>
Conmutador: (57-1) 3814000 - Fax. (57-1) 3814747 - Líneas de quejas y reclamos: 01 8000 979899 - Trámites: 3826999 24 horas</p>
</div>
</div>
</div>
</div>
<?php
  $footer = str_replace('%YEAR%', date('Y'), ob_get_clean());
  echo art_replace_image_path($footer);
}
?>
<?php if (!empty($copyright)) { echo '<div id="copyright">'.render($copyright).'</div>'; } ?>
</footer>

    </div>
</div>


<?php $view->print_closure($vars); ?>
