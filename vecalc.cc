/* vecalc.cc
 * author: Michael van der Kamp
 * 11190459 --- mjv761
 * mjv761@mail.usask.ca
 * CMPT 214
 * October 31, 2016
 * 
 * Written for submission for Assignment 02.
 */

#include <stdio.h>	// for: puts()
#include <stdint.h>	// for: uint16_t type
//#include <limits.h>	// for: numeric_limits
#include <stdlib.h>	// for: EXIT_SUCCESS, EXIT_FAILURE
#include <assert.h>	// for: assert()
#include <float.h>	// for: FLT_EPSILON
#include <math.h>	// for: fabs()

using namespace std;

// An Elem is a single-precision floating point value.
typedef float Elem;
// ... (Elem e, ...) {
//	... = e + ...;
//	... = e - ...;
//	... = e / ...; // a non-zero value.
//	... = e * ...;
// }

// A Vector is a dynamic array of type Elem.
struct Vector {
  	uint16_t size;
  	Elem* elements;
};
// ... (Vector v, ...) {
//	for (int i = 0; i < v.size; i++) {
//		v.elements[i] ...;
//	}
// }
// ... (Vector* v, ...) {
//	for (int i = 0; i < v->size; i++) {
//		v->elements[i] ...;
//	}
// }

// print_vec:
//	Print contents of Vector v to stdout.
// In:
//	v != NULL
//	v->size > 0
//	v->elements != NULL.
// Out:
//	return 	:: true if print successful.
//		:: false if print unsuccessful.
bool print_vec(Vector* v) {
  if ( NULL == v) {
    return false;
  }
  puts("Printing vector contents...");
  for (uint16_t i = 0; i < v->size; i++) {
    printf("%f\n",  v->elements[i]);
  }
  puts("... done.");
}

// alloc_vec:
//	Allocate an empty (zero-length) vector.
// In:
//	No input values.
// Out:
//	return	:: pointer to an empty vector if successful.
//		:: NULL if unsuccessful.
Vector* alloc_vec(void) {
  Vector* v = new Vector;
  if ( NULL == v ) {
    return NULL;
  }
  v->size = 0;
  v->elements = new Elem[v->size];
  if ( NULL == v->elements) {
    return NULL;
  }
  return v;
}

// dealloc_vec:
//	Deallocate a vector and its contents.
// In:
//	v != NULL
//	v->elements != NULL.
// Out:
//	No return value.
//	effect	:: v deallocated.
void dealloc_vec(Vector* v) {
  delete [] v->elements;
  delete v;
}

// extend_vec:
//	Allocate a new vector one element greater in size than v.
//	Copy elements in v to new vector.
//	Add new element e to the end of the new vector.
// In:
//	v != NULL
// 	v->size < 65535
// Out:
//	return	:: pointer to the newly allocated vector.
//	effect	:: Input vector (v) is not modified.
Vector* extend_vec(Vector* v, Elem e) {
  Vector* f = alloc_vec();
  
  if (	( NULL ==  v) 		|| 
	( 65535 <=  v->size) 	|| 
	( NULL ==  f)	) {
   return NULL;
 }
  
  for (uint16_t i = 0; i < v->size; i++) {
    f->size++;
    f->elements[i] =  v->elements[i];
  }
  f->elements[f->size] = e;
  f->size++;
  return f;
}

// scalar_plus:
// 	Adds e to each element in v.
// In:
//	v != NULL
//	v->size != 0
// Out:
//	return	:: pointer to the modified vector.
Vector* scalar_plus(Vector* v, Elem e) {
  if ( NULL == v ) {
    return NULL;
  }
  for (uint16_t i = 0; i < v->size; i++) {
    v->elements[i] += e;
  }
  return v;
}

// scalar_minus:
//	subtracts e from each element in v.
// In:
//	v != NULL
//	v->size != 0
// Out:
//	return	:: pointer to the modified vector.
Vector* scalar_minus(Vector* v, Elem e) {
  	return NULL;
}

// scalar_multiply:
//	Multiply each element in v by e.
// In:
//	v != NULL
//	v->size != 0
// Out:
//	return	:: pointer to the modified vector.
Vector* scalar_mult(Vector* v, Elem e) {
  	return NULL;
}

// scalar_divide:
//	Divides each element in v by e.
// In:
//	v != NULL
//	v->size != 0
//	e != 0
// Out:
//	return	:: pointer to the modified vector.
Vector* scalar_div(Vector* v, Elem e) {
  	return NULL;
}

// Usage
//  Instruct user on how to use this program; i.e. the commands it
//  supports and the syntax of those commands.
// In: 
//    none
// Out:
//    output produced on standard output
void usage( void ) {
  
    puts( " Usage:" );
    puts( "  p   - print vector" );
    puts( "  q,e - quit, end" );
    puts( "  h   - print usage help" );
    puts( "  + <operand> - add <operand> to each element of vector" );
    puts( "  - <operand> - subtract <operand> from each element of vector" );
    puts( "  * <operand> - multiple each element of vector by <operand>" );
    puts( "  / <operand> - divide each element of vector by <operand>" );
    puts( "  a <value> - extend vector by additional value" );
}

// fAreEqual:
//	Determines whether two floats are equal within margin of error.
// 	NOTE: I added this in case more general equality tests may be
// 		needed at a later date.
// In:
//	f1, f2 are of float type.
// Out:
//	return: true if they are equal within margin of error.
//		false otherwise.
bool fAreEqual(float f1, float f2) {
  return (fabs( f1 - f2 ) < FLT_EPSILON);
}

/*****************************************************/

// main:
//	Program entry point.
// In:
//	argc > 0
//	argv[0 .. argc-1] != NULL
// Out:
//	return	:: EXIT_SUCCESS if program terminates normally.
//		:: EXIT_FAILURE otherwise
int main(int, char**) {

#ifdef TESTING
	// Test alloc_vec
  	Vector* v = alloc_vec();
  	assert(v !=  NULL);
  	
  	// Test extend_vec
  	v = extend_vec(v, 1.0);
        assert(v != NULL);
  	assert(v->size == 1);
  	assert(v->elements[0] ==  1.0);
        v = extend_vec(v, 2.0);
        assert(v != NULL);
        assert(v->size == 2);
	assert(v->elements[0] == 1.0);
        assert(v->elements[1] == 2.0);

        // Test print_vec.
        bool printed = print_vec(v);
        assert(printed);

        // Test scalar_plus
        assert(scalar_plus(v, 10.0) != NULL);
        assert(v->elements[0] == 11.0);
        assert(v->elements[1] == 12.0);

        // Test scalar_minus
        assert(scalar_minus(v, 1.0) != NULL);
        assert(v->elements[0] == 10.0);
        assert(v->elements[1] == 11.0);
        
        // Test scalar_mult
        assert(scalar_mult(v, 2.0) != NULL);
        assert(v->elements[0] == 20.0);
        assert(v->elements[1] == 22.0);

        // Test scalar_div
        assert(scalar_div(v, 2.0) != NULL);
        assert(v->elements[0] == 10.0);
        assert(v->elements[1] == 11.0);

        // Test dealloc_vec:
        // Unfortunately, no way to be completely sure that
        // deallocation occurred successfully.
        dealloc_vec(v);	
	
#endif // TESTING
	return EXIT_SUCCESS;
}
