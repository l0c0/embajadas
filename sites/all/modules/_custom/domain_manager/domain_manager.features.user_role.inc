<?php
/**
 * @file
 * domain_manager.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function domain_manager_user_default_roles() {
  $roles = array();

  // Exported role: local admin
  $roles['local admin'] = array(
    'name' => 'local admin',
    'weight' => '3',
  );

  return $roles;
}
