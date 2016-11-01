/* vecalc.cc
 * author: Michael van der Kamp
 * 11190459 --- mjv761
 * mjv761@mail.usask.ca
 * CMPT 214
 * October 31, 2016
 * 
 * Written for submission for Assignment 02.
 * 
 * Created with Kate editor.
 */

#include <stdio.h>  // for: puts(), printf(), fputs()
#include <stdint.h> // for: uint16_t type
#include <stdlib.h> // for: EXIT_SUCCESS, EXIT_FAILURE
#include <assert.h> // for: assert()
#include <float.h>  // for: FLT_MAX

using namespace std;

// An Elem is a single-precision floating point value.
typedef float Elem;
// ... (Elem e, ...) {
//  ... = e + ...;
//  ... = e - ...;
//  ... = e / ...; // a non-zero value.
//  ... = e * ...;
// }

// A Vector is a dynamic array of type Elem.
struct Vector {
    uint16_t size;
    Elem* elements;
};
// ... (Vector v, ...) {
//  for (int i = 0; i < v.size; i++) {
//      v.elements[i] ...;
//  }
// }
// ... (Vector* v, ...) {
//  for (int i = 0; i < v->size; i++) {
//      v->elements[i] ...;
//  }
// }

// print_vec:
//  Print contents of Vector v to stdout.
// In:
//  v != NULL
//  v->size > 0
//  v->elements != NULL.
// Out:
//  return  :: true if print successful.
//      :: false if print unsuccessful.
bool print_vec(Vector* v) {
    if ( NULL == v) {
        fputs("ERROR: print_vec() failed.\n", stderr);
        return false;
    }
    puts("Printing vector contents...");
    for (uint16_t i = 0; i < v->size; i++) {
        printf("%g\n",  v->elements[i]);
    }
    puts("... done.");
    return true;
}

// alloc_vec:
//  Allocate an empty (zero-length) vector.
// In:
//  No input values.
// Out:
//  return  :: pointer to an empty vector if successful.
//      :: NULL if unsuccessful.
Vector* alloc_vec(void) {
    Vector* v = new Vector;
    if ( NULL == v ) {
        fputs("ERROR: alloc_vec() failed.\n", stderr);
        return NULL;
    }
    v->size = 0;
    v->elements = NULL;
    return v;
}

// dealloc_vec:
//  Deallocate a vector and its contents.
// In:
//  v != NULL
//  v->elements != NULL.
// Out:
//  No return value.
//  effect  :: v deallocated.
void dealloc_vec(Vector* v) {
    delete [] v->elements;
    delete v;
}

// extend_vec:
//  Allocate a new vector one element greater in size than v.
//  Copy elements in v to new vector.
//  Add new element e to the end of the new vector.
// In:
//  v != NULL
//  v->size < 65535
// Out:
//  return  :: pointer to the newly allocated vector.
//  effect  :: Input vector (v) is not modified.
Vector* extend_vec(Vector* v, Elem e) {
    Vector* f = alloc_vec(); 
    if (    ( NULL ==  v)           || 
            ( 65535 <=  v->size)    || 
            ( NULL ==  f)   ) {
        fputs("ERROR: extend_vec() failed.\n", stderr);
        return NULL;
    }

    f->elements = new Elem[v->size + 1];

    for (uint16_t i = 0; i < v->size; i++) {
        f->size++;
        f->elements[i] = v->elements[i];
    }
    f->elements[f->size] = e;
    f->size++;
    return f;
}

// scalar_plus:
//  Adds e to each element in v.
// In:
//  v != NULL
//  v->size != 0
//  v->elements[0 .. size-1] + e < FLT_MAX
// Out:
//  return  :: pointer to the modified vector.
Vector* scalar_plus(Vector* v, Elem e) {
    if (    ( NULL == v )   ||
            ( 0 == v->size) ) {
        fputs("ERROR: scalar_plus() failed.\n", stderr);
        return NULL;
    }
    for (uint16_t i = 0; i < v->size; i++) {
        if ( e > ( FLT_MAX - v->elements[i] ) ) {
            fputs("ERROR: FLT_MAX exceeded in scalar_plus().\n", stderr);
            return NULL;
        }
        v->elements[i] += e;
    }
    return v;
}

// scalar_minus:
//  subtracts e from each element in v.
// In:
//  v != NULL
//  v->size != 0
// Out:
//  return  :: pointer to the modified vector.
Vector* scalar_minus(Vector* v, Elem e) {
    fputs("ERROR: scalar_minus() failed.\n", stderr);
    return NULL;
}

// scalar_multiply:
//  Multiply each element in v by e.
// In:
//  v != NULL
//  v->size != 0
// Out:
//  return  :: pointer to the modified vector.
Vector* scalar_mult(Vector* v, Elem e) {
    fputs("ERROR: scalar_mult() failed.\n", stderr);
    return NULL;
}

// scalar_divide:
//  Divides each element in v by e.
// In:
//  v != NULL
//  v->size != 0
//  e != 0
// Out:
//  return  :: pointer to the modified vector.
Vector* scalar_div(Vector* v, Elem e) {
    fputs("ERROR: scalar_div() failed.\n", stderr);
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
//  Program entry point.
// In:
//  argc > 0
//  argv[0 .. argc-1] != NULL
// Out:
//  return  :: EXIT_SUCCESS if program terminates normally.
//      :: EXIT_FAILURE otherwise
int main(int, char**) {

#ifdef TESTING

    // Test alloc_vec
    Vector* v = alloc_vec();
    assert( NULL != v );
    assert( 0 == v->size );
    
    Vector* f = alloc_vec();
    assert( NULL != f );
    assert( 0 == f->size );
    
    // Test extend_vec
    f = extend_vec( v, 1.0 );
    assert( NULL != f );
    assert( 1 == f->size);
    assert( 1.0 == f->elements[0] );
    
    dealloc_vec(v);
    v = f;
    
    f = extend_vec( v, 2.0 );
    assert( NULL != f );
    assert( 2 == f->size );
    assert( 1.0 == f->elements[0] );
    assert( 2.0 == f->elements[1] );
    
    dealloc_vec(v);
    v = f;

    // Test print_vec.
    assert( print_vec(v) );

    // Test scalar_plus
    assert( NULL != scalar_plus(v, 10.0) );
    assert( 11.0 == v->elements[0] );
    assert( 12.0 == v->elements[1] );

    // Test scalar_minus
    assert( NULL != scalar_minus(v, 1.0) );
    assert( 10.0 == v->elements[0] );
    assert( 11.0 == v->elements[1] );
        
    // Test scalar_mult
    assert( NULL != scalar_mult(v, 2.0) );
    assert( 20.0 == v->elements[0] );
    assert( 22.0 == v->elements[1] );

    // Test scalar_div
    assert( NULL != scalar_div(v, 2.0) );
    assert( 10.0 == v->elements[0] );
    assert( 11.0 == v->elements[1] );

    // Test dealloc_vec:
    // Unfortunately, no way to be completely sure that
    // deallocation occurred successfully.
    dealloc_vec(v); 
    
#endif // TESTING

    return EXIT_SUCCESS;
}
