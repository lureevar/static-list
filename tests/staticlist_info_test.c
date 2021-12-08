#include <stdlib.h>
#include <check.h>

#include "staticlist.h"

typedef struct {
	int registration;
	char name[30];
	float grades[3];
} Students;

Students students_s[5] = {
	{1, "Jim Carrey", {7.8, 8.6, 6.7}},
	{2, "Bruce Campbell", {8.3, 5.6, 4.8}},
	{3, "Robin Williams", {9.3, 7.6, 8.2}},
	{4, "William Dafoe", {5.3, 8.1, 9.8}},
	{5, "Sigourney Weaver", {8.6, 9.2, 9.3}}
};

START_TEST(check_list_size) {
	int i;

	List *li_p = list_start(sizeof(Students));

	ck_assert_int_eq(list_empty(li_p), 1);
	ck_assert_int_ne(list_full(li_p), 1);

	for (i = 0; i < 5; i++) {
		list_insert(li_p, students_s[i].registration, &students_s[i]);
	}

	ck_assert_int_ne(list_empty(li_p), 1);
	ck_assert_int_eq(list_size(li_p), 5);

	for (i = 0; i < 5; i++) {
		list_remove(li_p, students_s[i].registration);
	}

	ck_assert_int_eq(list_size(li_p), 0);
	ck_assert_int_eq(list_empty(li_p), 1);
} END_TEST

Suite *insertion_suite(void) {
	Suite *suite_p;
	TCase *tc_core_p;

	suite_p = suite_create("Information");
	tc_core_p = tcase_create("Core");

	tcase_add_test(tc_core_p, check_list_size);

	suite_add_tcase(suite_p, tc_core_p);

	return suite_p;
}

int main(void) {
	int number_failed;
	Suite *suite_p;
	SRunner *srunner_p;

	suite_p = insertion_suite();
	srunner_p = srunner_create(suite_p);

	srunner_run_all(srunner_p, CK_NORMAL);
	number_failed = srunner_ntests_failed(srunner_p);
	srunner_free(srunner_p);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
