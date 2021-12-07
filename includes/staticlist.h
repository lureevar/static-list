#ifndef INCLUDE_STATIC_LIST_H
#define INCLUDE_STATIC_LIST_H

#define MAX_LIST_SIZE 100
#define MAX_STRING_LEN 30

typedef struct {
	int registration;
	char name[MAX_STRING_LEN];
	float grades[3];
} Students;

typedef struct {
	int quantity;
	Students data[MAX_LIST_SIZE];
} List;

List *create_list(void);
void release_list(List *li_p);

int size_list(List *li_p);
int list_full(List *li_p);
int list_empty(List *li_p);

_Bool insert_list_final(List *li_p, Students students_s);
_Bool insert_list_begin(List *li_p, Students students_s);

#endif
