class catNodeMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate them cats.');

    /* Map */
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'fid' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'Feline ID.',
          'alias' => 'c',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    /* Set up Source */
    $query = db_select('cats', 'c')
           ->fields('c', array('name', 'adult', 'age', 'fur'));
    // Create a MigrateSource object, which manages retrieving the input data:
    $this->source = new MigrateSourceSQL($query);

    /* Set up destination */
    $this->destination = // Set up our destination - nodes of type cats
    $this->destination = new MigrateDestinationNode('cats');

    /* Field Mappings */
    $this->addFieldMapping('title', 'name')
         ->description(t('Mapping cat name in source to node title'));

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('adult', 'age', 'fur'));
  }

  /* Finesse data / fix it before saving. */
  public function prepareRow($current_row) {
    // Make sure those pesky yard diggers don't get in!
    if($current_row->name == 'Dog') {
      return FALSE;
    }
    return TRUE;
  }
}

class catNodeXMLMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate them cats.');

    /* Map */
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'fid' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'Feline ID.',
          'alias' => 'c',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    /* Set up Source */
    $fields = array(
        'name' => t('Cat name'),
        'age' => t('Actual Age')
    );
    $xml_folder = drupal_get_path('module', 'migrate_cats') . '/xml/';
    $cats_url = $xml_folder . 'cats.xml';
    $cat_xpath = '/cats/cat';
    $cat_ID_xpath = 'felineid';
    $this->source = new MigrateSourceXML($cats_url, $cat_xpath, $cat_ID_xpath, $fields);
    // Create a MigrateSource object, which manages retrieving the input data:
    $this->source = new MigrateSourceSQL($query);

    /* Set up destination */
    $this->destination = // Set up our destination - nodes of type cats
    $this->destination = new MigrateDestinationNode('cats');

    /* Field Mappings */
    $this->addFieldMapping('title', 'name')
         ->description(t('Mapping cat name in source to node title'));

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('adult', 'age', 'fur'));
  }

  /* Finesse data / fix it before saving. */
  public function prepareRow($current_row) {
    // Make sure those pesky yard diggers don't get in!
    if($current_row->name == 'Dog') {
      return FALSE;
    }
    return TRUE;
  }
}
