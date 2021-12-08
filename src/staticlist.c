#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "staticlist.h"

typedef struct {
	int key;
	void *info;
} Item;

struct list {
	int quantity, size_type;
	Item data[MAX];
};

List* list_start(int size_type) {
	List *li_p = (List *) malloc(sizeof(struct list));

	if (li_p != NULL) {
		li_p->quantity = 0;
		li_p->size_type = size_type;
	}

	return li_p;
}

void list_end(List *li_p) {
	int i;

	for(i = 0; i < li_p->quantity; i++){
		free(li_p->data[i].info);
	}

	free(li_p);
}

void list_get(List *li_p, int key, void *data) {
	int i = 0;

	if (li_p == NULL) exit(1); // Without memory

	while (i < li_p->quantity && li_p->data[i].key != key) i++;

	if (i == li_p->quantity) exit(1); // Item is not in the list

	memcpy(data, li_p->data[i].info, li_p->size_type);
}

void list_insert(List *li_p, int key, void *data) {
	int j, i = 0;

	void *new = malloc(li_p->size_type);

	if (li_p == NULL || new == NULL) exit(1); // Without memory
	if (li_p->quantity == MAX) exit(1); // List is full

	memcpy(new, data, li_p->size_type);

	while (i < li_p->quantity && li_p->data[i].key < key) i++;
	for (j = li_p->quantity - 1; j >= i; j--) li_p->data[j + 1] = li_p->data[j];

	li_p->data[i].key = key;
	li_p->data[i].info = new;

	li_p->quantity++;
}

void list_remove(List *li_p, int key) {
	int j, i = 0;

	if (li_p == NULL) exit(1); // Without memory
	if (li_p->quantity == 0) exit(1); // List is empty

	while (i < li_p->quantity && li_p->data[i].key != key) i++;

	if (i == li_p->quantity) exit(1); // Item is not in the list

	free(li_p->data[i].info);

	for (j = i; j < li_p->quantity - 1;  j++) {
		li_p->data[j] = li_p->data[j + 1];
	}

	li_p->quantity--;
}

void list_printf(List *li_p, void (*print_format)(void *)) {
	int i;

	if (li_p == NULL) exit(1); // Without memory

	for (i = 0; i < li_p->quantity; i++) {
		printf("Key %d°\n", li_p->data[i].key);
		print_format(li_p->data[i].info);
	}
}

int list_size(List *li_p) {
	if (li_p == NULL) exit(1); // Without memory

	return li_p->quantity;
}

_Bool list_full(List *li_p) {
	if (li_p == NULL) exit(1); // Without memory

	return (li_p->quantity == MAX);
}

_Bool list_empty(List *li_p) {
	if (li_p == NULL) exit(1); // Without memory

	return (li_p->quantity == 0);
}
