#include <stdio.h>
#include <stdlib.h>


typedef int elem;
typedef struct _item item;

item *criar_item(elem x);
void set_valor(item *e, elem x);
elem get_valor(item *e);
void apagar_item(item **e);
