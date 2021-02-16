
//For Symbol table
typedef struct sym_node_struct sym_node_t;

struct sym_node_struct {
  char* symbol;
  int address;
  sym_node_t* left;
  sym_node_t* right;
};

//function prototypes
void sym_table_insert(sym_node_t ** g_symboltable_ptr, char* sym, int addr);
int sym_table_lookup(sym_node_t * g_symboltable_ptr, char* sym);
void sym_table_free(sym_node_t *g_symboltable_ptr);

