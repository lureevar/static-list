#include <stdlib.h>
#include <check.h>

#include "staticlist.h"

START_TEST(list_start_0_values) {
	List *li_p = create_list();

	ck_assert_int_eq(size_list(li_p), 0);

	release_list(li_p);
} END_TEST

START_TEST(insert_max_elements_making_list_full) {
	int i;

	List *li_p = create_list();
	Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};

	for (i = 0; i < MAX_LIST_SIZE; i++) {
		insert_list_begin(li_p, students_s);
	}

	ck_assert_int_eq(list_full(li_p), 1);

	release_list(li_p);
} END_TEST

START_TEST(list_empty_initialization_and_not_full) {
	List *li_p = create_list();

	ck_assert_int_eq(list_empty(li_p), 1);
	ck_assert_int_ne(list_full(li_p), 1);

	release_list(li_p);
} END_TEST

START_TEST(list_not_empty_when_added_element) {
	List *li_p = create_list();
	Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};

	insert_list_begin(li_p, students_s);

	ck_assert_int_ne(list_empty(li_p), 1);

	release_list(li_p);
} END_TEST

Suite *information_suite(void) {
	Suite *suite_p;
	TCase *tc_core_p;

	suite_p = suite_create("Information");
	tc_core_p = tcase_create("Core");

	tcase_add_test(tc_core_p, list_start_0_values);
	tcase_add_test(tc_core_p, insert_max_elements_making_list_full);
	tcase_add_test(tc_core_p, list_empty_initialization_and_not_full);
	tcase_add_test(tc_core_p, list_not_empty_when_added_element);

	suite_add_tcase(suite_p, tc_core_p);

	return suite_p;
}

int main(void) {
	int number_failed;
	Suite *suite_p;
	SRunner *srunner_p;

	suite_p = information_suite();
	srunner_p = srunner_create(suite_p);

	srunner_run_all(srunner_p, CK_NORMAL);
	number_failed = srunner_ntests_failed(srunner_p);
	srunner_free(srunner_p);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
