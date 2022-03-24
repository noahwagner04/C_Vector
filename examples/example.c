#include <stdio.h>
#include "../include/vector.h"

int main() {
	Vector v = {1, 2, 3};

	vector_scale(&v, 2);

	vector_rotate(&v, 0.4, 3, -1);

	vector_add_const(&v, 4);

	vector_scale(&v, 0.7);

	vector_subtract_const(&v, 12);

	printf("Length: %f, {%f, %f, %f}\n", vector_get_mag(&v), v.x, v.y, v.z);
	return 0;
}