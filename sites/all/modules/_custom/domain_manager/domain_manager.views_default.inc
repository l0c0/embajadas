<?php
/**
 * @file
 * domain_manager.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function domain_manager_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'domain_header';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'domain_header';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List of domains and administrators';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'time_per_domain';
  $handler->display->display_options['cache']['results_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan'] = '60';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  
  if (user_access('create site_domain content')){
    $handler->display->display_options['empty']['area']['content'] = t('No sub-domain set. Create one at !add', array('!add'=>l(t('Add Content-> New Site'), 'node/add/site-domain')));
  }else{
    $handler->display->display_options['empty']['area']['content'] = '';
  }
  
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Campo: Contenido: Site logo */
  $handler->display->display_options['fields']['field_domain_site_logo']['id'] = 'field_domain_site_logo';
  $handler->display->display_options['fields']['field_domain_site_logo']['table'] = 'field_data_field_domain_site_logo';
  $handler->display->display_options['fields']['field_domain_site_logo']['field'] = 'field_domain_site_logo';
  $handler->display->display_options['fields']['field_domain_site_logo']['label'] = '';
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['path'] = '<front>';
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_domain_site_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_domain_site_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_domain_site_logo']['field_api_classes'] = 0;
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '<front>';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Campo: Contenido: Site flag */
  $handler->display->display_options['fields']['field_domain_site_flag']['id'] = 'field_domain_site_flag';
  $handler->display->display_options['fields']['field_domain_site_flag']['table'] = 'field_data_field_domain_site_flag';
  $handler->display->display_options['fields']['field_domain_site_flag']['field'] = 'field_domain_site_flag';
  $handler->display->display_options['fields']['field_domain_site_flag']['label'] = '';
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['path'] = '<front>';
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_domain_site_flag']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_domain_site_flag']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_domain_site_flag']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_domain_site_flag']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_domain_site_flag']['field_api_classes'] = 0;
  /* Contextual filter: Contenido: Domain (field_domain) */
  $handler->display->display_options['arguments']['field_domain_value']['id'] = 'field_domain_value';
  $handler->display->display_options['arguments']['field_domain_value']['table'] = 'field_data_field_domain';
  $handler->display->display_options['arguments']['field_domain_value']['field'] = 'field_domain_value';
  $handler->display->display_options['arguments']['field_domain_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_domain_value']['default_argument_type'] = 'current_domain';
  $handler->display->display_options['arguments']['field_domain_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_domain_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_domain_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_domain_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_domain_value']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_domain_value']['not'] = 0;
  /* Filter criterion: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site_domain' => 'site_domain',
  );
  /* Filter criterion: Contenido: Título */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'starts';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Nombre del sitio web';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Contenido: Domain (field_domain) */
  $handler->display->display_options['filters']['field_domain_value']['id'] = 'field_domain_value';
  $handler->display->display_options['filters']['field_domain_value']['table'] = 'field_data_field_domain';
  $handler->display->display_options['filters']['field_domain_value']['field'] = 'field_domain_value';
  $handler->display->display_options['filters']['field_domain_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_domain_value']['expose']['operator_id'] = 'field_domain_value_op';
  $handler->display->display_options['filters']['field_domain_value']['expose']['label'] = 'Dominio';
  $handler->display->display_options['filters']['field_domain_value']['expose']['operator'] = 'field_domain_value_op';
  $handler->display->display_options['filters']['field_domain_value']['expose']['identifier'] = 'field_domain_value';
  $handler->display->display_options['filters']['field_domain_value']['expose']['reduce'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'domain_header_block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'header-domain-block';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['block_description'] = 'Site name and logo';

  /* Display: Página */
  $handler = $view->new_display('page', 'Página', 'domain_page_list');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_domain_site_logo' => 'field_domain_site_logo',
    'title' => 'title',
    'field_domain_site_flag' => 'field_domain_site_flag',
    'field_domain_admin' => 'field_domain_admin',
    'field_domain' => 'field_domain',
    'field_domain_email' => 'field_domain_email',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_domain_site_logo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_domain_site_flag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_domain_admin' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_domain' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_domain_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenido: Site logo */
  $handler->display->display_options['fields']['field_domain_site_logo']['id'] = 'field_domain_site_logo';
  $handler->display->display_options['fields']['field_domain_site_logo']['table'] = 'field_data_field_domain_site_logo';
  $handler->display->display_options['fields']['field_domain_site_logo']['field'] = 'field_domain_site_logo';
  $handler->display->display_options['fields']['field_domain_site_logo']['label'] = 'Site Logo';
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['path'] = '/';
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_domain_site_logo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_domain_site_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_domain_site_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_domain_site_logo']['field_api_classes'] = 0;
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre del sitio web';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Campo: Contenido: Site flag */
  $handler->display->display_options['fields']['field_domain_site_flag']['id'] = 'field_domain_site_flag';
  $handler->display->display_options['fields']['field_domain_site_flag']['table'] = 'field_data_field_domain_site_flag';
  $handler->display->display_options['fields']['field_domain_site_flag']['field'] = 'field_domain_site_flag';
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['path'] = '/';
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_domain_site_flag']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_domain_site_flag']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_domain_site_flag']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_domain_site_flag']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_domain_site_flag']['field_api_classes'] = 0;
  /* Campo: Contenido: Administrator */
  $handler->display->display_options['fields']['field_domain_admin']['id'] = 'field_domain_admin';
  $handler->display->display_options['fields']['field_domain_admin']['table'] = 'field_data_field_domain_admin';
  $handler->display->display_options['fields']['field_domain_admin']['field'] = 'field_domain_admin';
  $handler->display->display_options['fields']['field_domain_admin']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_domain_admin']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_domain_admin']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_domain_admin']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_domain_admin']['field_api_classes'] = 0;
  /* Campo: Contenido: Domain */
  $handler->display->display_options['fields']['field_domain']['id'] = 'field_domain';
  $handler->display->display_options['fields']['field_domain']['table'] = 'field_data_field_domain';
  $handler->display->display_options['fields']['field_domain']['field'] = 'field_domain';
  $handler->display->display_options['fields']['field_domain']['label'] = 'Dominio';
  $handler->display->display_options['fields']['field_domain']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_domain']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_domain']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_domain']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_domain']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_domain']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_domain']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_domain']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_domain']['field_api_classes'] = 0;
  /* Campo: Contenido: E-mail contact form */
  $handler->display->display_options['fields']['field_domain_email']['id'] = 'field_domain_email';
  $handler->display->display_options['fields']['field_domain_email']['table'] = 'field_data_field_domain_email';
  $handler->display->display_options['fields']['field_domain_email']['field'] = 'field_domain_email';
  $handler->display->display_options['fields']['field_domain_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_domain_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_domain_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_domain_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_domain_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_domain_email']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_domain_email']['field_api_classes'] = 0;
  /* Campo: Contenido: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Editar';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'domain/sites';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Domains logos and site names.';
  $handler->display->display_options['menu']['description'] = 'Domains logos and site names.';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['domain_header'] = array(
    t('Master'),
    t('List of domains and administrators'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No sub-domain set. Create one at !add', array('!add'=>l(t('Add Content-> New Site'), 'node/add/site-domain'))),
    // t('/'),
    t('All'),
    t('Site name'),
    t('Domain'),
    t('Block'),
    t('Site name and logo'),
    t('Page'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Site Logo'),
    t('Site flag'),
    t('Administrator'),
    t('E-mail contact form'),
    t('Edit'),
  );
  $export['domain_header'] = $view;

  return $export;
}
