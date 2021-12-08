#ifndef INCLUDE_STATIC_LIST_H
#define INCLUDE_STATIC_LIST_H

#define MAX 100

typedef struct list List;

List* list_start(int size_type);

void list_end(List *li_p);
void list_get(List *li_p, int key, void *data);
void list_insert(List *li_p, int key, void *data);
void list_remove(List *li_p, int key);
void list_printf(List *li_p, void (*print_format)(void *));

int list_size(List *li_p);

_Bool list_full(List *li_p);
_Bool list_empty(List *li_p);

#endif
