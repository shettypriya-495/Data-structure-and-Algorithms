#include<assert.h>
#include"bst.h"
void test_empty_bst()
{
  BST b=bst_new();
  BST *tree=&b;
  assert(tree->mass==0);
  
}
void test_three_level_bst()
{
  BST b=bst_new();
  BST *tree=&b;

  tree=bst_add_node(tree,50);
  assert(bst_count(tree)==1);
 // tree=bst_delete_node(tree,50);
  tree=bst_add_node(tree,30);
  
  tree=bst_add_node(tree,60);
  tree=bst_add_node(tree,70);
  assert(bst_count(tree)==4);
  assert(bst_lookup(tree,60)==1);
  tree=bst_in_order(tree);
  
}
int main()
{
	test_empty_bst();
	test_three_level_bst();
	return 0;
}
