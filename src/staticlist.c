#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "staticlist.h"

List *create_list(void) {
	List *li_p = (List *) malloc(sizeof(List));
	
	if (li_p != NULL) li_p->quantity = 0;
	
	return li_p;
}

void release_list(List *li_p) {
	free(li_p);
}

int size_list(List *li_p) {
	if (li_p == NULL) return -1;
	
	return li_p->quantity;
}

int list_full(List *li_p) {
	if (li_p == NULL) return -1;
	
	return (li_p->quantity == MAX_LIST_SIZE);
}

int list_empty(List *li_p) {
	if (li_p == NULL) return -1;
	
	return (li_p->quantity == 0);
}

_Bool insert_list_final(List *li_p, Students students_s) {
	if (li_p == NULL) return 0;
	if (list_full(li_p)) return 0;
	
	li_p->data[li_p->quantity] = students_s;
	li_p->quantity++;

	return 1;
}

_Bool insert_list_begin(List *li_p, Students students_s) {
	int i;

	if (li_p == NULL) return 0;
	if (list_full(li_p)) return 0;

	for (i = li_p->quantity - 1; i >= 0; i--) {
		li_p->data[i + 1] = li_p->data[i];
	}
	
	li_p->data[0] = students_s;
	li_p->quantity++;
	
	return 1;
}
