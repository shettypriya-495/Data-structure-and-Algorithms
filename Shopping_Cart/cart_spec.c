#include<stdlib.h>
#include<assert.h>
#include<stdint.h>
#include<stdio.h>
#include"cart.h"
int main()
{

	Available al = new_available();
	Available *a = &al;

	CART ca = new_cart();
	CART *c = &ca;

	a = add_item_avail(a,"CP_2001","Cell-phone",28000,2);
	assert (list_length(a) == 1);
	a = add_item_avail(a,"Bt_2003","Bottles",8000,6);
	a = add_item_avail(a,"wt_2004","Watch",3400,15);
	a = add_item_avail(a,"LP_6233","Laptop",5000,10);
	assert (list_length(a) == 4);

	printf("\n Available items" );
	display_products(a);

	c=add_item_cart(a,c,"Bt_2003",2);
	c=add_item_cart(a,c,"wt_2004",2);

	printf("\n Afetr adding Bt_2003:2 and wt_2004:2 to cart:Available items" );
	display_products(a);

    printf("\n Items in cart:" );
	_bill_(c);

	c=delete_item(a,c,"Bt_2003",2);

	printf("\n Afetr  deleting Bt_2003:2 Available items" );
	display_products(a);

	printf("\n Items in cart:" );
	_bill_(c);
	
}