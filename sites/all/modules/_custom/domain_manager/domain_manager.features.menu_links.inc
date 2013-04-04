<?php
/**
 * @file
 * domain_manager.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function domain_manager_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:domain/sites
  $menu_links['navigation:domain/sites'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'domain/sites',
    'router_path' => 'domain/sites',
    'link_title' => 'Domains logos and site names.',
    'options' => array(
      'attributes' => array(
        'title' => 'Domains logos and site names.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Domains logos and site names.');


  return $menu_links;
}
