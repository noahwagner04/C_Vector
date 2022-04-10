#ifndef VECTOR_H
#define VECTOR_H

/*
all vectors have a z attribute, if the is_2d attribute 
is set to 1, all vector functions will ignore the z attribute
*/
typedef struct {
	double x, y, z;
	int is_2d;
} Point;

typedef Point Vector;

// init functions, ensures that every member of the struct is correctly set
void vector_init_3d(Vector *v, double x, double y, double z);
void vector_init_2d(Vector *v, double x, double y);

// magnitude functions
double vector_get_mag_sq(Vector *v);
double vector_get_mag(Vector *v);

// if the magnitude is 0, this function doesn't do anything
void vector_set_mag(Vector *v, double new_mag);

// this function is functionally equivalent to vector_set_mag(v, 1)
void vector_normalize(Vector *v);

// distance between two vector functions
double vector_get_dist_btw(Vector *v1, Vector *v2);
double vector_get_dist_sq_btw(Vector *v1, Vector *v2);

// finds the dot product between two vectors
double vector_dot(Vector *v1, Vector *v2);

// rotates the vector, if the vector is 2d pitch is the only angle used, so set yaw and roll to 0
void vector_rotate(Vector *v, double pitch, double yaw, double roll);

// add functions, vector_add changes the first vector
void vector_add(Vector *v1, Vector *v2);
void vector_add_const(Vector *v, double c);

// subtract functions, vector_subtract changes the first vector
void vector_subtract(Vector *v1, Vector *v2);
void vector_subtract_const(Vector *v, double c);

// get the angle between two vectors in radians
double vector_get_angle_btw(Vector *v1, Vector *v2);

// gets the length of v1 projected onto v2
double vector_get_scalar_proj(Vector *v1, Vector *v2);

// projects v1 onto v2, and sets dest to that newly projected vector
void vector_proj(Vector *v1, Vector *v2, Vector *dest);

// scale the vector by a constant
void vector_scale(Vector *v, double scalar);

#endif