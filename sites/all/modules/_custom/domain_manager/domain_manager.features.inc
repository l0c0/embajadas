<?php
/**
 * @file
 * domain_manager.features.inc
 */

/**
 * Implements hook_views_api().
 */
function domain_manager_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_default_filefield_paths().
 */
function domain_manager_default_filefield_paths() {
  $settings = array();

  // Exported node::site_domain::field_domain_site_flag
  $settings['node::site_domain::field_domain_site_flag'] = array(
    'type' => 'node::site_domain',
    'field' => 'field_domain_site_flag',
    'filename' => array(
      'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'theme/[node:field_domain]/flag',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'active_updating' => '0',
  );
  // Exported node::site_domain::field_domain_site_logo
  $settings['node::site_domain::field_domain_site_logo'] = array(
    'type' => 'node::site_domain',
    'field' => 'field_domain_site_logo',
    'filename' => array(
      'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'theme/[node:field_domain]/logo',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'active_updating' => '0',
  );

  return $settings;
}

/**
 * Implements hook_node_info().
 */
function domain_manager_node_info() {
  $items = array(
    'site_domain' => array(
      'name' => 'New site',
      'base' => 'node_content',
      'description' => t('Sets the domain, site name, email address and the administrator.'),
      'has_title' => '1',
      'title_label' => t('Site name'),
      'help' => t('The steps to create a new site are:<br/>
1) Create the !user_account the local managed (with local-admin role).<br />
2) Create the new !new_domain.<br />
3) Create a new site (complete this form).<br />
4) Configure cpanel to accept the new sub-domain.<br />', array(
  '!user_account' => l(t('user account'), 'admin/people/create', array('attributes' => array('target' => '_blank'))),
  '!new_domain' => l(t('sub-domain'), 'admin/structure/domain', array('attributes' => array('target' => '_blank')))
  )
  )
  )
  );
  return $items;
}
