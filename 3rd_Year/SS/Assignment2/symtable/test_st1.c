#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_table.h"

int main()
{
  // this code inserts some things into the symbol table;
  // it is not an exhaustive test, so you will certainly need to write
  // your own tests

  int v, errors;
  sym_node_t* root_symboltable_ptr = NULL;
  sym_table_insert(&root_symboltable_ptr, "mxxx", 1);
  sym_table_insert(&root_symboltable_ptr, "nxxx", 2);
  sym_table_insert(&root_symboltable_ptr, "kxxx", 3);

  sym_table_insert(&root_symboltable_ptr, "jxxx", 4);
  sym_table_insert(&root_symboltable_ptr, "lxxx", 5);
 
  sym_table_insert(&root_symboltable_ptr, "lzzz", 6);
  sym_table_insert(&root_symboltable_ptr, "jaaa", 7);

  errors = 0;

  if ((v = sym_table_lookup(root_symboltable_ptr, "mxxx")) != 1) {
    printf("ERROR: wrong lookup value; got %d but should be %d\n", v, 1);
    errors++;
  }
  if ((v = sym_table_lookup(root_symboltable_ptr, "nxxx")) != 2) {
    printf("ERROR: wrong lookup value; got %d but should be %d\n", v, 2);
    errors++;
  }
  if ((v = sym_table_lookup(root_symboltable_ptr, "kxxx")) != 3) {
    printf("ERROR: wrong lookup value; got %d but should be %d\n", v, 3);
    errors++;
  }
  if ((v = sym_table_lookup(root_symboltable_ptr, "jxxx")) != 4) {
    printf("ERROR: wrong lookup value; got %d but should be %d\n", v, 4);
    errors++;
  }
  if ((v = sym_table_lookup(root_symboltable_ptr, "lxxx")) != 5) {
    printf("ERROR: wrong lookup value; got %d but should be %d\n", v, 5);
    errors++;
  }
  if ((v = sym_table_lookup(root_symboltable_ptr, "lzzz")) != 6) {
    printf("ERROR: wrong lookup value; got %d but should be %d\n", v, 6);
    errors++;
  }
  if ((v = sym_table_lookup(root_symboltable_ptr, "jaaa")) != 7) {
    printf("ERROR: wrong lookup value; got %d but should be %d\n", v, 7);
    errors++;
  }

  if (errors == 0) {
    printf("Passed all tests\n");
  } 
  else {
    printf("Failed %d tests\n", errors);
  }
  
  //done with symbol table
  sym_table_free(root_symboltable_ptr);
  
  return 0;
}
