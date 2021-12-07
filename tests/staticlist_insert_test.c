#include <stdio.h>
#include <snow/snow.h>

#include "staticlist.h"

describe(Insertion) {
	it("Inserting two element on the list (begin, final)") {
		int i;
	
		List *li_p = create_list();
		Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};

		insert_list_final(li_p, students_s);
		insert_list_begin(li_p, students_s);

		asserteq(size_list(li_p), 2);

		release_list(li_p);
	}
	
	it("Inserting the max amount of elements (begin)") {
		int i;
	
		List *li_p = create_list();
		Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};
		
		for (i = 0; i < MAX_LIST_SIZE; i++) {
			insert_list_begin(li_p, students_s);
		}

		asserteq(insert_list_begin(li_p, students_s), 0);

		release_list(li_p);
	}
	
	it("Inserting the max amount of elements (final)") {
		int i;
	
		List *li_p = create_list();
		Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};
		
		for (i = 0; i < MAX_LIST_SIZE; i++) {
			insert_list_final(li_p, students_s);
		}

		asserteq(insert_list_final(li_p, students_s), 0);

		release_list(li_p);
	}
}

snow_main();
