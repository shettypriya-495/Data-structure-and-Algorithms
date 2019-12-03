#ifndef _INCLUDED_CART_
#define _INCLUDED_CART_
#define MAX_SIZE 20
#include<stdint.h>
typedef struct _product_ Product;
typedef struct  _product_list_ Available;
typedef struct  _cart_ CART;

struct  _product_
{
	char Pid[MAX_SIZE];
	char Name[MAX_SIZE];
	uint32_t Price;
	uint32_t Quantity;
	Product *next;
};

struct _product_list_
{
	Product *head;
	Product *tail;
	uint32_t tc;
};

struct _cart_
{
	Product *start;
	Product *end;
	uint32_t total;
};
//Public interfaces

CART new_cart();
Available new_available();
uint32_t list_length(Available *a);
void display_products(Available *a);
Available* add_item_avail(Available *a, char *s1, char *s2, uint32_t price, uint32_t quantity);
CART* add_item_cart(Available *a, CART *c, char *s1, uint32_t req_quant);
CART* delete_item(Available *a, CART *c, char *s1, uint32_t req_quant);
void _bill_(CART *c);
#endif
