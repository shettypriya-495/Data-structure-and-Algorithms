#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_
#include<stdint.h>

typedef struct _node_ Node;
typedef struct _slist_ Slist;

struct _node_
{
	int32_t data;
	Node *next;	
};
struct _slist_
{
	Node *head;
	Node *tail;
	uint32_t len;
};

/* Public interfaces for user */
Slist slist_new();
static Node* new_node(int32_t element);
uint32_t slist_length(const Slist *list);
uint32_t lookup(const Slist *list, int32_t key);
Slist* add_head(Slist *list, int32_t element);
Slist* add_tail(Slist *list, int32_t element);
Slist* delete_head(Slist *list);
Slist* delete_tail(Slist *list);
uint32_t maximum(Slist* list);
uint32_t minimum(Slist* list);
Slist* add_element_after_specified(Slist *list, int32_t ele, int32_t after );
Slist* delete_specified(Slist *list, int32_t ele);


#endif
