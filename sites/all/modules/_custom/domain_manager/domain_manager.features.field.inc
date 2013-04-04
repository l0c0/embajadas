<?php
/**
 * @file
 * domain_manager.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function domain_manager_field_default_fields() {
  $fields = array();
  
  $domain_options = array();
    foreach (domain_domains() as $data) {
      if ($data['valid']) {
        $domain_options[$data['domain_id']] = $data['sitename'].' ('.$data['subdomain'].')';
      }
    }
    
    $form['field_domain']['und']['#options'] = $domain_options;
  
  // Exported field: 'node-site_domain-field_domain'
  $fields['node-site_domain-field_domain'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_domain',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => $domain_options,
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_integer',
    ),
    'field_instance' => array(
      'bundle' => 'site_domain',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_domain',
      'label' => 'Domain',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-site_domain-field_domain_admin'
  $fields['node-site_domain-field_domain_admin'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_domain_admin',
      'foreign keys' => array(
        'uid' => array(
          'columns' => array(
            'uid' => 'uid',
          ),
          'table' => 'users',
        ),
      ),
      'indexes' => array(
        'uid' => array(
          0 => 'uid',
        ),
      ),
      'module' => 'user_reference',
      'settings' => array(
        'profile2_private' => FALSE,
        'referenceable_roles' => array(
          2 => 0,
          3 => 0,
          4 => '4',
        ),
        'referenceable_status' => array(
          0 => 0,
          1 => '1',
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'user_reference',
    ),
    'field_instance' => array(
      'bundle' => 'site_domain',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'user_reference',
          'settings' => array(),
          'type' => 'user_reference_default',
          'weight' => '7',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_domain_admin',
      'label' => 'Administrator',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'user_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'user_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'user_reference_autocomplete',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-site_domain-field_domain_email'
  $fields['node-site_domain-field_domain_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_domain_email',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'email',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'site_domain',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_contact',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_domain_email',
      'label' => 'E-mail contact form',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => '200',
        ),
        'type' => 'email_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-site_domain-field_domain_site_flag'
  $fields['node-site_domain-field_domain_site_flag'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_domain_site_flag',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'profile2_private' => FALSE,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'site_domain',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'ffp_field_domain_site_flag' => array(
        'active_updating' => 0,
        'file_name' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        'file_name_cleanup' => array(
          'file_name_pathauto' => 0,
          'file_name_tolower' => 0,
          'file_name_transliterate' => 0,
        ),
        'file_path' => 'theme/[node:field_domain]/flag',
        'file_path_cleanup' => array(
          'file_path_pathauto' => 0,
          'file_path_tolower' => 0,
          'file_path_transliterate' => 0,
        ),
        'retroactive_update' => 0,
      ),
      'field_name' => 'field_domain_site_flag',
      'label' => 'Site flag',
      'required' => 1,
      'settings' => array(
        'alt_field' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '30x20',
        'min_resolution' => '30x20',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
            'image' => 0,
            'image_domain_flag' => 0,
            'image_domain_logo' => 0,
            'image_galleryformatter_slide' => 0,
            'image_galleryformatter_thumb' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-site_domain-field_domain_site_logo'
  $fields['node-site_domain-field_domain_site_logo'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_domain_site_logo',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'profile2_private' => FALSE,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'site_domain',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'ffp_field_domain_site_logo' => array(
        'active_updating' => 0,
        'file_name' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        'file_name_cleanup' => array(
          'file_name_pathauto' => 0,
          'file_name_tolower' => 0,
          'file_name_transliterate' => 0,
        ),
        'file_path' => 'theme/[node:field_domain]/logo',
        'file_path_cleanup' => array(
          'file_path_pathauto' => 0,
          'file_path_tolower' => 0,
          'file_path_transliterate' => 0,
        ),
        'retroactive_update' => 0,
      ),
      'field_name' => 'field_domain_site_logo',
      'label' => 'Site logo',
      'required' => 1,
      'settings' => array(
        'alt_field' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif',
        'max_filesize' => '',
        'max_resolution' => '105x105',
        'min_resolution' => '105x105',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
            'image' => 0,
            'image_domain_flag' => 0,
            'image_domain_logo' => 0,
            'image_galleryformatter_slide' => 0,
            'image_galleryformatter_thumb' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '4',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Administrator');
  t('Domain');
  t('E-mail contact form');
  t('Site flag');
  t('Site logo');

  return $fields;
}
