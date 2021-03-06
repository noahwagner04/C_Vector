#include <math.h>
#include "vector.h"

void vector_init_3d(Vector *v, double x, double y, double z) {
	v->x = x;
	v->y = y;
	v->z = z;
	v->is_2d = 0;
}

void vector_init_2d(Vector *v, double x, double y) {
	v->x = x;
	v->y = y;
	v->z = 0;
	v->is_2d = 1;
}

double vector_get_mag_sq(Vector *v) {
	if (!v->is_2d) {
		// if we are a 3d vector...
		return (v->x * v->x + v->z * v->z) + v->y * v->y;
	} else {
		// if we are a 2d vector...
		return v->x * v->x + v->y * v->y;
	}
}

double vector_get_mag(Vector *v) {
	return sqrt(vector_get_mag_sq(v));
}

void vector_set_mag(Vector *v, double new_mag) {
	double current_mag = vector_get_mag(v);

	// don't do anything if the magnitude is 0, prevents division by 0 error
	if (current_mag == 0) return;

	if (!v->is_2d) {
		// if the vector is 3d...
		v->z *= new_mag / current_mag;
	}
	v->x *= new_mag / current_mag;
	v->y *= new_mag / current_mag;
}

void vector_normalize(Vector *v) {
	vector_set_mag(v, 1);
}

double vector_get_dist_btw(Vector *v1, Vector *v2) {
	return sqrt(vector_get_dist_sq_btw(v1, v2));
}

double vector_get_dist_sq_btw(Vector *v1, Vector *v2) {
	Vector *temp = v2;
	vector_subtract(temp, v1);
	return vector_get_mag_sq(temp);
}

double vector_dot(Vector *v1, Vector *v2) {
	if (!v1->is_2d) {
		// if we are a 3d vector...
		return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	} else {
		// if we are a 2d vector...
		return v1->x * v2->x + v1->y * v2->y;
	}
}

void vector_rotate(Vector *v, double pitch, double yaw, double roll) {

	// coefficients of the rotation matrices
	double cos_x = cos(pitch);
	double sin_x = sin(pitch);
	double cos_y = v->z ? cos(yaw) : 0;
	double sin_y = v->z ? sin(yaw) : 0;
	double cos_z = v->z ? cos(roll) : 0;
	double sin_z = v->z ? sin(roll) : 0;
	double old_x = v->x;
	double old_y = v->y;
	double old_z = v->z;

	if (!v->is_2d) {
		// if we are a 3d vector, rotate using the 3d rotation matrix
		v->x = old_x * (cos_z * cos_y) + old_y * (cos_z * sin_y * sin_x - sin_z * cos_x) + old_z * (cos_z * sin_y * cos_x + sin_z * sin_x);
		v->y = old_x * (sin_z * cos_y) + old_y * (sin_z * sin_y * sin_x + cos_z * cos_x) + old_z * (sin_z * sin_y * cos_x - cos_z * sin_x);
		v->z = old_x * (-sin_y) + old_y * (cos_y * sin_x) + old_z * (cos_y * cos_x);
	} else {
		// if we are a 2d vector, rotate using the 2d rotation matrix
		v->x = old_x * cos_x - old_y * sin_x;
		v->y = old_x * sin_x + old_y * cos_x;
	}
}

void vector_add(Vector *v1, Vector *v2) {
	v1->x += v2->x;
	v1->y += v2->y;

	if (!v1->is_2d) {
		v1->z += v2->z;
	}
}

void vector_add_const(Vector *v, double c) {
	v->x += c;
	v->y += c;

	if (!v->is_2d) {
		v->z += c;
	}
}

void vector_subtract(Vector *v1, Vector *v2) {
	v1->x -= v2->x;
	v1->y -= v2->y;

	if (!v1->is_2d) {
		v1->z -= v2->z;
	}
}

void vector_subtract_const(Vector *v, double c) {
	v->x -= c;
	v->y -= c;

	if (!v->is_2d) {
		v->z -= c;
	}
}

double vector_get_angle_btw(Vector *v1, Vector *v2) {
	return acos(vector_dot(v1, v2) / (vector_get_mag(v1) * vector_get_mag(v2)));
}

double vector_get_scalar_proj(Vector *v1, Vector *v2) {
	return vector_dot(v1, v2) / vector_get_mag(v2);
}

void vector_proj(Vector *v1, Vector *v2, Vector *dest) {
	Vector temp = *v2;
	vector_normalize(&temp);
	vector_scale(&temp, vector_get_scalar_proj(v1, v2));
	*dest = temp;
}

void vector_scale(Vector *v, double scalar) {
	v->x *= scalar;
	v->y *= scalar;

	if (!v->is_2d) {
		v->z *= scalar;
	}
}