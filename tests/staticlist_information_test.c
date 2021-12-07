#include <stdio.h>
#include <snow/snow.h>

#include "staticlist.h"

describe(Information) {
	it("List start with 0 values") {
		List *li_p = create_list();

		asserteq(size_list(li_p), 0);

		release_list(li_p);
	}
	
	it("Inserting the max amount elements, making the list full") {
		int i;
	
		List *li_p = create_list();
		Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};
		
		for (i = 0; i < MAX_LIST_SIZE; i++) {
			insert_list_begin(li_p, students_s);
		}

		asserteq(list_full(li_p), 1);

		release_list(li_p);
	}
	
	it("List is empty on initialization and not full") {
		List *li_p = create_list();

		asserteq(list_empty(li_p), 1);
		assertneq(list_full(li_p), 1);

		release_list(li_p);
	}
	
	it("List is not empty when added one element") {
		List *li_p = create_list();
		Students students_s = {0, "John Doe", {7.5, 8.2, 3.5}};
		
		insert_list_begin(li_p, students_s);
		
		assertneq(list_empty(li_p), 1);
		
		release_list(li_p);
	}
}

snow_main();
