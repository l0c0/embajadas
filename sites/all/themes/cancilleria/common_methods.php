<?php

/* Common Drupal methods definitons using in Artisteer theme export */

/**
 * Generate the HTML representing a given menu with Artisteer style.
 *
*/
function art_menu_worker($content = NULL, $show_sub_menus, $menu_class) {
  if (!$content) {
    return '';
  }

  $output = $content;
  // used to support Menutrails module
  //$output = str_replace("active-trail", "active-trail active", $output);
  
  $empty_str = '';
  $menu_str = ' class="menu"';
  if(strpos($output, $menu_str) !== FALSE) {
    $pattern = '/class="menu"/i';
    $replacement = 'class="'. $menu_class .'"';
    $output = preg_replace($pattern, $replacement, $output, 1);
    $output = str_replace($menu_str, $empty_str, $output);
  }

  if (class_exists('DOMDocument')) {
    $output = art_menu_xml_parcer($output, $show_sub_menus, $menu_class);
    /* Support Block Edit Link module */
	  $output = str_replace('<!DOCTYPE root>', $empty_str, $output);
  }
  else {
    $output = preg_replace('~(<a [^>]*>)([^<]*)(</a>)~', '$1<span class="l"></span><span class="r"></span><span class="t">$2</span>$3', $output);
  }
  
  return $output;
}

function art_menu_xml_parcer($content, $show_sub_menus, $menu_class) {
  $parent_id = $menu_class . '-id';

  $doc = art_xml_document_creator($content, $parent_id);
  if ($doc === FALSE) {
    return $content; // An error occurred while reading XML content
  }

  $parent = $doc->documentElement;
  $elements = $parent->childNodes;
  $ul_elements = $doc->getElementsByTagName("ul");
  if ($ul_elements == NULL || !$ul_elements->length) return $content;
  $ul = NULL;
  foreach($ul_elements as $ul) {
    // First ul element with css-class Cancilleria_hmenu or Cancilleria_vmenu
    if (($ul->getAttribute('class') == "Cancilleria_vmenu") || ($ul->getAttribute('class') == "Cancilleria_hmenu"))
        break;
    continue;
  }
  if ($ul == NULL) $ul = $ul_elements->item(0);
  art_menu_set_active($doc, $menu_class);
  $ul_children = art_menu_style_parcer($doc, $ul->childNodes, $show_sub_menus);

  $parent->appendChild($ul);
  while ($ul->previousSibling)
    $parent->removeChild($ul->previousSibling);

  $children = $parent->childNodes;
  $innerHTML = '';
  foreach ($children as $child) {
    $tmp_doc = new DOMDocument();
    $tmp_doc->appendChild($tmp_doc->importNode($child,true));       
    $innerHTML .= $tmp_doc->saveHTML();
  }

  return html_entity_decode($innerHTML, ENT_NOQUOTES, "UTF-8");
}

function art_xml_document_creator($content, $parent_id) {
  $old_error_handler = set_error_handler('art_handle_xml_error');
  $dom = new DOMDocument();
  /* Support Block Edit Link module */
  $doc_content = <<< XML
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE root [
<!ENTITY nbsp "&#160;">
]>
<div class="$parent_id">$content</div>
XML;
 
  @$dom->loadXml($doc_content);   
  restore_error_handler();
  return $dom;
}

function art_handle_xml_error($errno, $errstr, $errfile, $errline) {
  if ($errno==E_WARNING && (substr_count($errstr,"DOMDocument::loadXML()")>0))
   return false; // An error occurred while reading XML content
  else 
    return true; // Successful
}

function art_menu_style_parcer($doc, $elements, $show_sub_menus) {
  $parentNodes_to_delete = array();
  $childNodes_to_delete = array();
  
  foreach ($elements as $element) {
    if (is_a($element, "DOMElement") && ($element->tagName == "li")) {
      $children = $element->childNodes;
      
      foreach ($children as $child) {
        if (is_a($child, "DOMElement") && ($child->tagName == "a")) {
          $caption = $child->nodeValue;
          if (empty($caption)) {
            $childNodes_to_delete[] = $child;
            $parentNodes_to_delete[] = $element;
            break;
          }

          $child->nodeValue = check_plain($caption);
        }
        else if (!$show_sub_menus) {
          $childNodes_to_delete[] = $child;
        }
      }
    }
  }

  art_remove_elements($childNodes_to_delete);
  art_remove_elements($parentNodes_to_delete);
  return $elements;
}

function art_menu_set_active($doc, $menu_class) {
	$xpath = new DOMXPath($doc);
	$query = "//ul[contains(concat(' ',@class,' '), ' $menu_class ')]//a[contains(concat(' ',@class,' '), ' active ')]";
	$items = $xpath->query($query, $doc);
	if ($items->length == 0) return;
	
	$active_a = $items->item(0);
	//$query = "ancestor::li[contains(concat(' ',@class,' '), ' active-trail ')]";
  $query = "ancestor::li";
	$items = $xpath->query($query, $active_a);
	
	foreach ($items as $item) {
		$class_attr = $item->getAttribute("class");
		if (strpos(' '.$class_attr.' ', ' active ') === FALSE) {
			$item->setAttribute("class", $class_attr.' active');
		}
		
    
		$children = $item->childNodes;
		foreach($children as $child) {
      if (is_a($child, "DOMElement")) {
			  $class_attr = $child->getAttribute("class");
			  if (strpos(' '.$class_attr.' ', ' active ') === FALSE) {
				  $child->setAttribute("class", $class_attr.' active');
			  }
		  }
    }
	}
}

function art_remove_elements($elements_to_delete) {
  if (!isset($elements_to_delete)) return;
  foreach($elements_to_delete as $element) {
    if ($element != null) {
      $element->parentNode->removeChild($element);
    }
  }
}

function art_node_worker($node) {
  $links_output = art_links_woker($node->links);
  $terms_output = art_terms_worker($node->taxonomy);

  $output = $links_output;
  if (!empty($links_output) && !empty($terms_output)) {
    $output .= '&nbsp;|&nbsp;';
  }
  $output .= $terms_output;
  return $output;
}

/*
 * Split out taxonomy terms by vocabulary.
 *
 * @param $terms
 *   An object providing all relevant information for displaying terms:
 *
 * @ingroup themeable
 */
function art_terms_worker($terms) {
  $result = '';
  $terms = get_terms_D7($content);
if (!empty($terms)) {
ob_start();?>
<span class="Cancilleria_posttagicon"><?php
$result .= ($result == '') ? ob_get_clean() : '&nbsp;|&nbsp;' . ob_get_clean();
$result .= '<div class="Cancilleria_tags">' . render($terms) . '</div>';
ob_start();?>
</span><?php
$result .= ob_get_clean();
}

  return $result;
}

/**
 * Return a themed set of links.
 *
 * @param $links
 *   A keyed array of links to be themed.
 * @param $attributes
 *   A keyed array of attributes
 * @return
 *   A string containing an unordered list of links.
 */
function art_links_woker($links, $attributes = array('class' => 'links')) {
  $output = '';

  if (!empty($links)) {
    $output = '';

    $num_links = count($links);
    $index = 0;

    foreach ($links as $key => $link) {
      $class = $key;
      if (strpos ($class, "read_more") !== FALSE) {
        continue;
      }

      // Automatically add a class to each link and also to each LI
      if (isset($link['attributes']) && isset($link['attributes']['class'])) {
        $link['attributes']['class'] .= ' ' . $key;
      }
      else {
        $link['attributes']['class'] = $key;
      }

      // Add first and last classes to the list of links to help out themers.
      $extra_class = '';
      if ($index == 1) {
        $extra_class .= 'first ';
      }
      if ($index == $num_links) {
        $extra_class .= 'last ';
      }

      $link_output = get_html_link_output($link);
      if (!empty($class)) {
        if (strpos ($key, "comment") !== FALSE) {
if ($index > 0 && !empty($link_output) && !empty($output)) {
$output .= '&nbsp;|&nbsp;';
}
ob_start();?>
<span class="Cancilleria_postcommentsicon"><?php
$output .= ob_get_clean();
$output .= $link_output;
$index++;
ob_start();?>
</span><?php
$output .= ob_get_clean();
continue;}

        if ($index > 0 && !empty($link_output) && !empty($output)) {
$output .= '&nbsp|&nbsp';
}
ob_start();?>
<span class="Cancilleria_postcategoryicon"><?php
$output .= ob_get_clean();
$output .= $link_output;
$index++;
ob_start();?>
</span><?php
$output .= ob_get_clean();

      }
      else {
        $output .= '&nbsp;|&nbsp;' . $link_output;
        $index++;
      }
    }
  }

  return $output;
}

function get_html_link_output($link) {
  $output = '';
  // Is the title HTML?
  $html = isset($link['html']) ? $link['html'] : NULL;

  // Initialize fragment and query variables.
  $link['query'] = isset($link['query']) ? $link['query'] : NULL;
  $link['fragment'] = isset($link['fragment']) ? $link['fragment'] : NULL;

  if (isset($link['href'])) {
    if (get_drupal_major_version() == 5) {
      $output = l($link['title'], $link['href'], $link['attributes'], $link['query'], $link['fragment'], FALSE, $html);
    }
    else {
      $output = l($link['title'], $link['href'], array('language' => $link['language'], 'attributes'=>$link['attributes'], 'query'=>$link['query'], 'fragment'=>$link['fragment'], 'absolute'=>FALSE, 'html'=>$html));
    }
  }
  else if ($link['title']) {
    if (!$html) {
      $link['title'] = check_plain($link['title']);
    }
    $output = $link['title'];
  }

  return $output;
}

function art_content_replace($content) {
  $first_time_str = '<div id="first-time"';
  $article_str = ' class="Cancilleria_article"';
  $pos = strpos($content, $first_time_str);
  if($pos !== FALSE)
  {
    $output = str_replace($first_time_str, $first_time_str . $article_str, $content);
    $output = <<< EOT
    <div class="Cancilleria_box Cancilleria_post">
      <div class="Cancilleria_box-body Cancilleria_post-body">
  <article class="Cancilleria_post-inner Cancilleria_article">
   <div class="Cancilleria_postcontent">
      $output
    </div>
  <div class="cleared"></div>
    </article>
  <div class="cleared"></div>
  </div>
  </div>
EOT;
  }
  else 
  {
    $output = $content;
  }
  return $output;
}

function art_placeholders_output($var1, $var2, $var3) {
  $output = '';
  if (!empty($var1) && !empty($var2) && !empty($var3)) {
    $output .= <<< EOT
      <table class="position" cellpadding="0" cellspacing="0" border="0">
        <tr valign="top">
          <td class="third-width">$var1</td>
          <td class="third-width">$var2</td>
          <td>$var3</td>
        </tr>
      </table>
EOT;
  }
  else if (!empty($var1) && !empty($var2)) {
    $output .= <<< EOT
      <table class="position" cellpadding="0" cellspacing="0" border="0">
        <tr valign="top">
          <td class="third-width">$var1</td>
          <td>$var2</td>
        </tr>
      </table>
EOT;
  }
  else if (!empty($var2) && !empty($var3)) {
    $output .= <<< EOT
      <table class="position" cellpadding="0" cellspacing="0" border="0">
        <tr valign="top">
          <td class="two-thirds-width">$var2</td>
          <td>$var3</td>
        </tr>
      </table>
EOT;
  }
  else if (!empty($var1) && !empty($var3)) {
    $output .= <<< EOT
      <table class="position" cellpadding="0" cellspacing="0" border="0">
        <tr valign="top">
          <td class="half-width">$var1</td>
          <td>$var3</td>
        </tr>
      </table>
EOT;
  }
  else {
    if (!empty($var1)) {
      $output .= <<< EOT
        <div id="var1">$var1</div>
EOT;
    }
    if (!empty($var2)) {
      $output .= <<< EOT
        <div id="var1">$var2</div>
EOT;
    }
    if (!empty($var3)) {
      $output .= <<< EOT
        <div id="var1">$var3</div>
EOT;
    }
  }

  return $output;
}

function art_get_sidebar($sidebar, $vnavigation, $class) {
  $result = 'Cancilleria_layout-cell ';
  if (empty($sidebar) && empty($vnavigation)) {
    $result .= 'Cancilleria_content';
  }
  else {
    $result .= $class;
  }

  $output = '<div class="'.$result.'">'.render($vnavigation) . render($sidebar).'</div>'; 
  return $output;
}

function art_submitted_worker($date, $author) {
  $output = '';
  if ($date != '') {
    ob_start();?>
<span class="Cancilleria_postdateicon"><?php
$output .= ob_get_clean();
$output .= $date;
ob_start();?>
</span><?php $output .= ob_get_clean();

  }
  if ($author != '') {
    ob_start();?>
<span class="Cancilleria_postauthoricon"><?php if ($output != '') {
$output .= '&nbsp;|&nbsp;';
}
$output .= ob_get_clean();
$output .= $author;
ob_start();?>
</span><?php $output .= ob_get_clean();

  }
  return $output;
}

function is_art_links_set($links) {
  $size = sizeof($links);
  if ($size == 0) {
    return FALSE;
  }

  //check if there's "Read more" in node links only  
  $read_more_link = $links['node_read_more'];
  if ($read_more_link != NULL && $size == 1) {
    return FALSE;
  }

  return TRUE;
}

/**
 * Method to define node title output.
 *
*/
function art_node_title_output($title, $node_url, $page) {
  $output = '';
  if (!$page)
    $output = '<a href="' . $node_url . '" title="' . $title . '">' . $title . '</a>';
  else
    $output = $title;
  return $output;
}

function art_hmenu_output($content) {
  $menu = art_menu_worker($content, true, 'Cancilleria_hmenu');
  $result = preg_replace('~(<div [^>]*>)([^<]*)(</div>)~', '$2', $menu);
  return $result;
}

function art_vmenu_output($subject, $content) {
  if (empty($content))
    return;

  $result = '';
  $vmenu =	art_menu_worker($content, true, 'Cancilleria_vmenu');
  $result .= <<< EOT
<div class="Cancilleria_vmenublock clearfix">
        <div class="Cancilleria_vmenublockcontent">$vmenu
</div>
</div>
EOT;

  return $result;
}

function art_replace_image_path($content) {
  $content = preg_replace_callback('/(src=)([\'"])(?:images[\/\\\]?)?(.*?)\2()/', 'art_real_path', $content);
  $content = preg_replace_callback('/(url\()([\'"])(?:images[\/\\\]?)?(.*?)\2(\))/', 'art_real_path', $content);
  return $content;
}

function art_real_path($match) {
  list($str, $start, $quote, $filename, $end) = $match;
  $full_path = get_full_path_to_theme().'/images';
  return $start . $quote . $full_path . '/' . $filename . $quote . $end;
}