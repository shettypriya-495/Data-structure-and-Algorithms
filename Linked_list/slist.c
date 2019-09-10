#include <stdlib.h>
#include<stddef.h>
#include<assert.h>
#include"slist.h"

Slist slist_new()
{
	Slist s={NULL,NULL,0};
	return s;
}

static Node* new_node(int32_t element)
{
	Node *new_node=(Node *) malloc(sizeof(Node));
	new_node->data=element;
	new_node->next=NULL;
	return new_node;
}

uint32_t slist_length(const Slist *list)
{
	assert(list!=NULL);
	return list->len;
}
uint32_t lookup(const Slist *list, int32_t key)
{
	assert(list!=NULL);
	Node *cur;
	for(cur=list->head;cur!=NULL;cur=cur->next)
	{
		if(cur->data==key)
		{
			break;
		}
	}
	return (cur!=NULL);
}

Slist* add_head(Slist *list, int32_t element)
{
	assert(list!=NULL);
	Node *node=new_node(element);
        node->next=list->head;
	list->head=node;
	if(list->tail==NULL)
	{
		list->tail=node;
		
	}
++list->len;
     assert(((list->len==1)&&(list->head==list->tail))||((list->len>0)&&(list->head!=list->tail)));
	
    
    return list;
}

Slist* add_tail(Slist *list, int32_t element)
{
	assert(list!=NULL);
	Node *node=new_node(element);
	if(list->head==NULL)
	{
		list->head=list->tail=node;
		node->next=NULL;
	}
	else
	{
		list->tail->next=node;
		list->tail=node;
	}
	
	++list->len;
    return list;
}

Slist* delete_head(Slist *list)
{
	assert(list!=NULL);
	Node *temp;
	if(list->head!=NULL)
	{
		temp=list->head;
		list->head=list->head->next;
                if(list->head==NULL)
                {
                   list->tail=NULL;
                }
		--list->len;
		free(temp);
	}
	
    return list;
}
Slist* delete_tail(Slist *list)
{	
        assert(list!=NULL);
	Node *cur, *tail1;
	if(list->tail!=NULL)
	{
		tail1=list->tail;
		if(list->len>1)
		{
			for(cur=list->head;cur->next!=tail1;cur=cur->next);
			list->tail=cur;
		    cur->next=NULL;
                 }
        if(list->tail==NULL)
        {
        	list->head=NULL;
        }

		--list->len;
		
	}
	
    return list;
}

uint32_t maximum(Slist* list)
{
  assert(list!=NULL);
  Node *cur=list->head;
  uint32_t max=cur->data;
 
 if(list->len==1)
  {
    return list->head->data;
  }
  else if(list->len==0)
   {
      return 0;
   }
else{

   
     for(cur;cur!=NULL;cur=cur->next)
     {
       if(cur->data>=max)
         {
           max=cur->data;
         }
        
     } return max;
    }
   
}
    


uint32_t minimum(Slist* list)
{
   Node *cur=list->head;
   uint32_t min=cur->data;
 assert(list!=NULL);
 if(list->len==1)
  {
    return list->head->data;
  }
  else if(list->len==0)
   {
      return 0;
   }
else{

   
     for(cur;cur!=NULL;cur=cur->next)
     {
       if(cur->data<min)
         {
           min=cur->data;
         }
        
     } return min;
    }
   
}

Slist* add_element_after_specified(Slist *list, int32_t ele, int32_t after )
{
	assert(list!=NULL);
	Node *cur, *temp;
	
	Node *node=new_node(ele);

	if((list->head->data==after)&&(list->head->next==NULL))
	{
		list->tail=list->head->next=node;
	}
	else if((list->tail->data==after)&&(list->tail->next==NULL))
	{
		list->tail->next=node;
		node->next=NULL;
	}
	else
	{
		for(cur=list->head;cur!=NULL;cur=cur->next)
		{
			if(cur->data==after)
			{
				node->next=cur->next;
				cur->next=node;
			}
		}
	}
	++list->len;
	return list;
}

Slist* delete_specified(Slist *list, int32_t ele)
{
      assert(list!=NULL);
      Node *cur=list->head, *temp;
      if(cur->data==ele)
       {
         list->head=cur->next;
         free(cur);
       }

      else
      {
         
      for(cur=list->head;cur!=NULL;cur=cur->next)
		{
			if(cur->next->data==ele)
			{
                                temp=cur->next;
				break;
			}
		}
      
      cur->next=temp->next;
      temp->next=NULL;
      free(temp);
     }
	
    return list;
}




