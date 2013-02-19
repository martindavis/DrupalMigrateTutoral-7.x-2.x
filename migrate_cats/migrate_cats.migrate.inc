<?php
function migrate_cats_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
      'CatNode' => array('class_name' => 'catNodeMigration')
    ),
  );
  return $api;
}
