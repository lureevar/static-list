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

START_TEST(get_elements_list) {
	int i;

	List *li_p = list_start(sizeof(Students));
	Students students_s_1;

	for (i = 0; i < 5; i++) {
		list_insert(li_p, students_s[i].registration, &students_s[i]);
	}

	list_get(li_p, 1, &students_s_1);

	ck_assert_int_eq(students_s_1.registration, students_s[0].registration);
	ck_assert_str_eq(students_s_1.name, students_s[0].name);

	for (i = 0; i < 3; i++) {
		ck_assert_uint_eq(students_s_1.grades[i], students_s[0].grades[i]);
	}

	list_end(li_p);
} END_TEST

Suite *insertion_suite(void) {
	Suite *suite_p;
	TCase *tc_core_p;

	suite_p = suite_create("Geters");
	tc_core_p = tcase_create("Core");

	tcase_add_test(tc_core_p, get_elements_list);

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
