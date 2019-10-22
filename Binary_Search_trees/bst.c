#include<stdlib.h>
#include<assert.h>
#include<stddef.h>
#include<stdio.h>

#include"bst.h"
#include"queue.h"


BST bst_new()
{
BST btree={NULL,0};
return btree;
}

static Treenode* _bst_newnode(int32_t ele)
{
	Treenode *node=(Treenode* ) malloc(sizeof(Treenode));
	node->data=ele;
	node->left=NULL;
	node->right=NULL;
	return node;
}

uint32_t bst_count(BST *tree)
{
	assert(tree!=NULL);
	return tree->mass;
}

BST* bst_add_node(BST *tree, int32_t element)
{
	assert(tree!=NULL);
	Treenode *cur, *parent;
	cur=parent=tree->root;
	while(cur!=NULL && cur->data!=element)
	{
		parent=cur;
		if(element<cur->data)
		{
			cur=cur->left;
		}
		else if(element>cur->data)
		{
			cur=cur->right;
		}
	}
	if(cur==NULL)
	{
		Treenode *tnode=_bst_newnode(element);
		if(parent==NULL)
		{
			tree->root=tnode;
		}
		else if(element<parent->data)
		{
			parent->left=tnode;
		}
		else if(element>parent->data)
		{
			parent->right=tnode;
		}
		++tree->mass;
	}
	return tree;
}

BST* bst_delete_node(BST *tree, int32_t key)
{
	assert(tree!=NULL);
	tree -> root=delete(tree,tree->root,key);
	return tree;
}

static Treenode* delete(BST *tree, Treenode *node, int32_t key)
{
	Treenode *temp;
	if(node ==NULL)
	{
		return node;
	}
	else if(key< node->data)
	{
		node->left=delete(tree,node->left,key);
	}
	else if(key > node->data)
	{
		node->right=delete(tree,node->right,key);
	}
	else if(node->left && node->right)
	{
		temp=findmin(node->right);
		node->data=temp->data;
		node->right=delete(tree,node->right,node->data);

	}
	else
	{
		temp=node;
		if(node->right==NULL)
		{
			node=node->left;
		}
		else
		{
			node=node->right;
		}
		free(temp);
		--tree->mass;
	}
	return node;
}

static Treenode* findmin(Treenode *node)
{
	if(node->left ==NULL)
	{
		return node;
	}
	else
		return(findmin(node->left));
}

uint32_t bst_lookup(BST *tree, int32_t key)
{
	assert(tree!=NULL);
	Treenode *cur=tree->root;
	while(cur!=NULL && cur->data!=key)
	{
		if(key<cur->data)
		{
			cur=cur->left;
		}
		else if(key > cur->data)
		{
			cur=cur->right;
		}
	}
	return (cur!=NULL);
}

BST* bst_in_order(BST *tree)
{
	assert(tree!=NULL);
	_in_order_(tree->root);
}
static void _in_order_(Treenode *node)
{
	if(node)
	{
		_in_order_(node->left);
		printf("%d\t", node->data );
		_in_order_(node->left);
	}
}
BST* bst_post_order(BST *tree)
{
	assert(tree!=NULL);
	_post_order_(tree->root);
}
static void _post_order_(Treenode *node)
{
	if(node)
	{
		_post_order_(node->left);
		_post_order_(node->left);
		printf("%d\t", node->data );
	}
}

BST* bst_pre_order(BST *tree)
{
	assert(tree!=NULL);
	_pre_order_(tree->root);
}
static void _pre_order_(Treenode *node)
{
	if(node)
	{
		printf("%d\t", node->data );
		_pre_order_(node->left);
		_pre_order_(node->left);
	}
}
/*
uint32_t bst_hieght(BST *tree)
{



}
BST* bst_level_order(BST *tree)
{
	assert(tree->root!=NULL);
	Treenode *node;
	Queue bst_q=queue_new(tree->mass);
	queue *q=&bst_q;
	queue_res res;

	q=queue_add(q,tree->root,&res);
	while(!queue_empty(q))
	{
	queue_delete(q,&res);
	node=(Treenode*) res.data;
	if(node->left)
	{
	  queue_add(q,node->left,&res);
	}
	if(node->right)
	{
		queue_add(q,node->right,&res);
	
	}
	printf("%d\t", node->data);
	}
}
*/
