# Vector
## A simple vector library implemented in c
### How to build
This library only contains 2 files, vector.c and vector.h, so compiling is stright forward. If you want, you can use the provided makefile by running the following commands in the project root.
```
mkdir build
make
```
A libvector.a file will be generated in the build directory.
### How to use
The Vector struct holds 3 doubles: x, y, and z. All vectors have the z attribute, if you want 2d functionality just set z to 0. The Point struct is equivalent to the Vector struct, and can be treated as if it were a Vector (although getting the magnitude of a point doesn't really make sense). The code below demonstrates all the functionality of this library.
```c
Vector v1 = {1, 2, 3};
Vector v2 = {4, 5, 6};

// gets the squared magnitude of the vector
double length_sq = vector_get_mag_sq(&v1);

// gets the actual magnitude of the vector
double length = vector_get_mag(&v1);

// sets the magnitude of the vector to 10, doesn't do anything if the magnitude is already 0
vector_set_mag(&v1, 10);

// this function is functionally equivalent to vector_set_mag(v, 1)
vector_normalize(&v1);

// gets the distance between two vectors
double distance = vector_get_dist_btw(&v1, &v2);

// gets the squared distance between two vectors
double distance_sq = vector_get_dist_sq_btw(&v1, &v2);

// finds the dot product between two vectors
double dot_product = vector_dot(&v1, &v2);

// rotates the vector 0.2 radians around the x axis, 0.9 around the y, and -0.7 around the z (+ is anticlockwise, - is clockwise)
vector_rotate(&v1, 0.2, 0.9, -0.7);

// add the two vectors, this function changes the first vector
vector_add(&v1, &v2);

// adds 3 to all x, y, z attributes
vector_add_const(&v1, 3);

// subtract the two vectors, this function changes the first vector
vector_subtract(&v1, &v2);

// subtracts 5 to all x, y, z attributes
vector_subtract_const(&v1, 5);

// multiplies all x, y, z attributes by 2
vector_scale(&v1, 2);
```

### References
* https://www.youtube.com/watch?v=DOMg0lXWatM&t=105s
* https://en.wikipedia.org/wiki/Rotation_matrix
* https://youtu.be/fNk_zzaMoSs
* https://www.youtube.com/watch?v=mWJkvxQXIa8&list=PLRqwX-V7Uu6ZwSmtE13iJBcoI-r4y7iEc
* https://www.youtube.com/watch?v=bKEaK7WNLzM&list=PLRqwX-V7Uu6ZV4yEcW3uDwOgGXKUUsPOM&index=10
* https://natureofcode.com/book/chapter-1-vectors/