#include <stdlib.h>
#include <check.h>

#include "staticlist.h"

START_TEST(inserting_elements_list_begin_final) {
	int i;

	List *li_p = create_list();
	Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};

	insert_list_final(li_p, students_s);
	insert_list_begin(li_p, students_s);

	ck_assert_int_eq(size_list(li_p), 2);

	release_list(li_p);
} END_TEST

START_TEST(inserting_max_elements_begin) {
	int i;

	List *li_p = create_list();
	Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};

	for (i = 0; i < MAX_LIST_SIZE; i++) {
		insert_list_begin(li_p, students_s);
	}

	ck_assert_int_eq(insert_list_begin(li_p, students_s), 0);

	release_list(li_p);
} END_TEST

START_TEST(inserting_max_elements_final) {
	int i;

	List *li_p = create_list();
	Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};

	for (i = 0; i < MAX_LIST_SIZE; i++) {
		insert_list_final(li_p, students_s);
	}

	ck_assert_int_eq(insert_list_final(li_p, students_s), 0);

	release_list(li_p);
} END_TEST

Suite *insertion_suite(void) {
	Suite *suite_p;
	TCase *tc_core_p;

	suite_p = suite_create("Insertion");
	tc_core_p = tcase_create("Core");

	tcase_add_test(tc_core_p, inserting_elements_list_begin_final);
	tcase_add_test(tc_core_p, inserting_max_elements_begin);
	tcase_add_test(tc_core_p, inserting_max_elements_final);

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
