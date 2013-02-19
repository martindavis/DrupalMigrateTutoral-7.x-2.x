# Drupal Migrate 7.x-2.x Migrate Example
This is a basic tutorial to show you the concepts behind Migrate and make it a little less scary the first time! At this time, the code does not actually work, but if someone wants to flush out the example, please feel free to fork and request a merge!  

# Files
The file structure consists of:  
migrate_cats/  
migrate_cats/migrate_cats.info  
migrate_cats/migrate_cats.module  
migrate_cats/migrate_cats.migrate.inc  
migrate_cats/cats.inc  
migrate_cats/xml/  
migrate_cats/xml/cats.xml  

# hook_migrate_api()
file: migrate_cats.migrate.inc  
Array of information containing migrate version and migration paths your module is creating.  

# catNodeMigration
file: cats.inc  
Migration path defintions defined as classes that extend the Migration class. ```construct()``` is always required along with everything in it. ```prepareRow()``` is optional, but useful for data manipulation. catNodeMigration path:  
```PHP
<?php
class catNodeMigration extends Migration {
  /* Set up migration / mapping */
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate them cats.');
    $this->map – MigrateMap Class instance $this->source – MigrateSource Class instance
    $this->destination – MigrateDestination Class instance
    $this->addFieldMapping – Field Mappings
  }

  /* Finesse data / fix it before saving. */
  public function prepareRow($current_row) {
    $current_row->{property}
    return TRUE; }
  }
```

# More Tutorials / Examples:  
## XDEB Migration (2011)  
Based on a slightly older version of Migrate, this tutorial will help ease you into building a practical migration:  
http://xdeb.org/node/1539  

## RedCat Migration (2011)  
Another tutorial based on a slightly older version of Migrate, this is another tutorial to help you step into using Migrate:  
http://btmash.com/article/2011-02-25/migrating-content-using-migrate-module

## Migrate Examples
Migrate has great examples that are slightly daunting for first timers and light coders. I would recommend this last after you've completed the other tutorials. Look in the migrate folder:  
sites/all/modules/migrate_example  
sites/all/modules/migrate_example_baseball  
