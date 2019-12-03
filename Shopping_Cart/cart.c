#include<stdlib.h>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<stdio.h>
#include"cart.h"

CART new_cart()
{
	CART c={NULL,NULL,0};
	return c;
}

Available new_available()
{
	Available a={NULL,NULL,0};
	return a;
}
uint32_t list_length(Available *a)
{
	return a->tc;
}
static Product* new_product(char *s1, char *s2, uint32_t price, uint32_t quantity)
{
	Product *new_node=(Product *) malloc(sizeof(Product));

	strcpy(new_node->Pid,s1);
	strcpy(new_node->Name,s2);
	new_node->Price=price;
	new_node->Quantity=quantity;
	new_node->next=NULL;

	return new_node;
}

Available* add_item_avail(Available *a, char *s1, char *s2, uint32_t price, uint32_t quantity)
{
	assert(a!=NULL);
	Product *node=new_product(s1,s2, price, quantity);
    node->next=a->head;
	a->head=node;
	if(a->tail==NULL)
	{
		a->tail=node;
		
	}
	++a->tc;
    assert(((a->tc==1)&&(a->head==a->tail))||
     	((a->tc>0)&&(a->head!=a->tail)));
	
    
    return a;
}

void display_products(Available *a)
{
	assert(a!=NULL);
	Product *cur;
	for(cur=a->head;cur!=NULL;cur=cur->next)
	{
		printf("\nProduct ID:%s \t Name: %s \t Price:%d\tQuantity: %d\n",cur->Pid,
			cur->Name,cur->Price,cur->Quantity);

		
	}
}

CART* add_item_cart(Available *a, CART *c, char *s1, uint32_t req_quant)
{
	Product *temp;
	assert(a!=NULL && c!=NULL);
	for(temp=a->head;temp!=NULL;temp=temp->next)
	{
		if(!strcmp(temp->Pid,s1))
		{
			Product *node=new_product(temp->Pid,temp->Name, temp->Price, req_quant);
    node->next=c->start;
	c->start=node;
	if(c->end==NULL)
	{
		c->end=node;
		
	}
	++c->total;
			break;
		}
	}
	
    assert(((c->total==1)&&(c->start==c->end))||
     	((c->total>1)&&(c->start!=c->end)));
	Product *cur;
	for(cur=a->head;cur!=NULL;cur=cur->next)
	{
		if(!strcmp(cur->Pid,s1))
		{
			cur->Quantity=cur->Quantity - req_quant;
			break;
		}
	}
      
    
    return c;
}

CART* delete_item(Available *a,CART *c, char *s1, uint32_t req_quant)
{
	
	assert(a!=NULL && c!=NULL);
	Product *cur;
	for(cur=a->head;cur!=NULL;cur=cur->next)
	{
		if(!strcmp(cur->Pid,s1))
		{
			cur->Quantity=cur->Quantity + req_quant;
			break;
		}
	}
	
	 Product *cur1=c->start, *temp;
      if(!strcmp(cur1->Pid,s1))
       {
         c->start=cur1->next;
         free(cur);
       }

      else
      {
         
      for(cur1=c->start;cur1!=NULL;cur1=cur1->next)
		{
			if(!strcmp(cur1->next->Pid,s1))
			{
                temp=cur1->next;
				break;
			}
		}
      
      cur1->next=temp->next;
      temp->next=NULL;
      free(temp);
   
	}
	 return c;
}

void _bill_(CART *c)
{
	assert(c!=NULL);
	Product *cur;
	for(cur=c->start;cur!=NULL;cur=cur->next)
	{
		printf("\nProduct ID:%s \t Name: %s \t Price:%d\tQuantity: %d\n",cur->Pid,
			cur->Name,cur->Price,cur->Quantity);

		
	}
}
/*uint32_t lookup(const Available *a, char *s)
{
	assert(a!=NULL);
	Product *cur;
	for(cur=a->head;cur!=NULL;cur=cur->next)
	{
		if(!strcmp(a->Pid,s))
		{
			break;
		}
	}
	return (cur!=NULL);
}*/
