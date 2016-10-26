#include <cstdio>
#include <cstdint>
#include <limits>

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
//	v != NULL, v->size > 0, v->elements != NULL.
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
//		:: null if unsuccessful.
Vector* alloc_vec(void) {
  return null;
}

// dealloc_vec:
//	Deallocate a vector and its contents.
// In:
//	v != NULL, v->elements != NULL.
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
//	v != NULL, e != NULL.
// Out:
//	return	:: pointer to the newly allocated vector.
//	effect	:: Input vector (v) is not modified.
Vector* extend_vec(Vector* v, Elem e) {
  return null;
}

// Usage
//  Instruct user on how to use this program; i.e. the commands it
//  supports and the syntax of those commands.
// In: 
//    none
// Out:
//    output produced on standard output
// Author :: Prof. Anthony Kusalik
//    (Solution to function provided for assignment).
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


int main() {
  // Just some testing for limits and type sizes that I'll use later.
	printf("Sizeof Float: %zu\n", sizeof(float));
	printf("MAX of uint16: %i\n", std::numeric_limits<uint16_t>::max());
	printf("epsilong of float: %.16f\n", std::numeric_limits<float>::epsilon());
	return 0;
}
