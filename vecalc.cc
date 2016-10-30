#include <cstdio>
#include <stdint.h>
#include <limits>
#include <cstdlib>
#include <assert.h>

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
    	return false;
}

// alloc_vec:
//	Allocate an empty (zero-length) vector.
// In:
//	No input values.
// Out:
//	return	:: pointer to an empty vector if successful.
//		:: NULL if unsuccessful.
Vector* alloc_vec(void) {
  	return NULL;
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
  
}

// extend_vec:
//	Allocate a new vector one element greater in size than v.
//	Copy elements in v to new vector.
//	Add new element e to the end of the new vector.
// In:
//	v != NULL
//	e != NULL.
// Out:
//	return	:: pointer to the newly allocated vector.
//	effect	:: Input vector (v) is not modified.
Vector* extend_vec(Vector* v, Elem e) {
  	return NULL;
}

// scalar_plus:
// 	Adds e to each element in v.
// In:
//	v != NULL
//	v->size != 0
//	e != NULL
// Out:

//	return	:: pointer to the modified vector.
Vector* scalar_plus(Vector* v, Elem e) {
  	return NULL;
}

// scalar_minus:
//	subtracts e from each element in v.
// In:
//	v != NULL
//	v->size != 0
//	e != NULL
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
//	e != NULL
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
//	e != NULL
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

/*****************************************************/

// main:
//	Program entry point.
// In:
//	argc > 0
//	argv[0 .. argc-1] != NULL
// Out:
//	return	:: EXIT_SUCCESS if program terminates normally.
//		:: EXIT_FAILURE otherwise

int main(int argv, char* argc[]) {

#ifdef TESTING
	// Test alloc_vec
  	Vector* v = alloc_vec();
  	assert(v !=  NULL);
  	
  	// Test extend_vec
  	v = extend_vec(v, 1.0);
        assert(v != NULL);
  	assert(v->size == 1);
  	assert(v->elements[0] ==  1.0);
        v = extend_vec(v, 2.14);
        assert(v != NULL);
        assert(v->size == 2);
        assert(v->elements[1] == 2.14);

        // Test print_vec.
        bool printed = print_vec(v);
        assert(printed);

        // Test scalar_plus
        assert(scalar_plus(v, 10.0) != NULL);
        assert(v->elements[0] == 11.0);
        assert(v->elements[1] == 12.14);

        // Test scalar_minus
        assert(scalar_minus(v, 1.0) != NULL);
        assert(v->elements[0] == 10.0);
        assert(v->elements[1] == 11.14);
        
        // Test scalar_multiply
        assert(scalar_multiply(v, 2.0); != NULL);
        assert(v->elements[0] == 20.0);
        assert(v->elements[1] == 22.28);

        // Test scalar_divide
        assert(scalar_divide(v, 2.0); != NULL);
        assert(v->elements[0] == 10.0);
        assert(v->elements[1] == 11.14);

        // Test dealloc_vec:
        // Unfortunately, no way to be completely sure that
        // deallocation occurred successfully.
        dealloc_vec(v);	
	
#endif // TESTING
	return EXIT_SUCCESS;
}
