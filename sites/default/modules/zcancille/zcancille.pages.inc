<?php
  function zcancille_page($node) {
    print '<h3 class="views-accordion-tramites_servicios-page_128-header">
Requisitos </h3>' . render(field_view_field('node', $node, 'body', array('label' => 'hidden'))) . '';
  }
?>