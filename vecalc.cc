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

#include <stdio.h>  // for: puts(), printf()
#include <stdint.h> // for: uint16_t type
#include <stdlib.h> // for: EXIT_SUCCESS, EXIT_FAILURE
#include <assert.h> // for: assert()
#include <float.h>  // for: FLT_MAX

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
    if ( NULL != v ) {
        if ( NULL != v->elements ) {
            delete [] v->elements;
        }
        delete v;
    }
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
    // To protect data, use second vector for addition,
    // then return second vector if addition was successful.
    // Vector remains unchanged this way if error is encountered
    // halfway through operation.
    Vector* f = alloc_vec();
    if (    ( NULL == v )   ||
            ( 0 == v->size) ||
            ( NULL == f )   ) {       
        return NULL;
    }

    f->size = v->size;
    f->elements = new Elem[f->size];

    if ( NULL == f->elements ) {
        return NULL;
    }

    for (uint16_t i = 0; i < v->size; i++) {
        if ( e > ( FLT_MAX - v->elements[i] ) ) {         
            return NULL;
        }
        f->elements[i] = v->elements[i] + e;
    }
    return f;
}

// scalar_minus:
//  subtracts e from each element in v.
// In:
//  v != NULL
//  v->size != 0
// Out:
//  return  :: pointer to the modified vector.
Vector* scalar_minus(Vector* v, Elem e) { 
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

    // Test dealloc_vec
    // NOTE: No way to know for sure that deallocation worked.
    // Can test on NULL values to prevent crashes though.
    dealloc_vec(f); // f->elements is NULL.
    dealloc_vec(NULL);
    
    // Test extend_vec
    f = extend_vec( v, 1.0 );
    assert( NULL != f );
    assert( 1 == f->size );
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

#ifdef TEST_OVERFLOW
    // Test overflow protection on v->size.
    Vector* o = alloc_vec();
    assert( NULL != o );
    assert( 0 == o->size );
    for (uint16_t i = 0; i < 65535; i++) {
        f = extend_vec( o, 2.0 );
        assert( NULL != f );
        assert( i + 1 == f->size );
        assert( 2.0 == f->elements[i] );
        dealloc_vec(o);
        o = f;
    }
    f = extend_vec( o, 2.0 );
    assert( NULL == f );
    dealloc_vec(o);
#endif // TEST_OVERFLOW

    // Test fail condition.
    f = extend_vec( NULL, 100 );
    assert( NULL == f );

    // Test print_vec.
    assert( print_vec(v) );
    assert( !print_vec(NULL) );

    // Test scalar_plus
    f = scalar_plus( v, 10.0 );
    assert( NULL != f );
    assert( 11.0 == f->elements[0] );
    assert( 12.0 == f->elements[1] );
    dealloc_vec(v);
    v = f;
    assert( NULL == scalar_plus(NULL, 100) );

    // Test overflow protection in scalar_plus
    f = scalar_plus( v, 4.40282e+38 );
    assert( NULL == f );

    // Test original data persists after failed scalar_plus.
    assert( 11.0 == v->elements[0] );
    assert( 12.0 == v->elements[1] );

    // Test scalar_minus
    f = scalar_minus( v, 1.0 );
    assert( NULL != f );
    assert( 10.0 == f->elements[0] );
    assert( 11.0 == f->elements[1] );
    dealloc_vec(v);
    v = f;
    assert( NULL == scalar_minus(NULL, 100) );
        
    // Test scalar_mult
    f = scalar_mult( v, 2.0 );
    assert( NULL != f );
    assert( 20.0 == f->elements[0] );
    assert( 22.0 == f->elements[1] );
    dealloc_vec(v);
    v = f;
    assert( NULL == scalar_mult(NULL, 100) );

    // Test scalar_div
    f = scalar_div( v, 2.0 );
    assert( NULL != f );
    assert( 10.0 == f->elements[0] );
    assert( 11.0 == f->elements[1] );
    dealloc_vec(v);
    v = f;
    assert( NULL == scalar_div(NULL, 100) );

    // Test dealloc_vec:
    // Unfortunately, no way to be completely sure that
    // deallocation occurred successfully.
    dealloc_vec(v); 
    
#endif // TESTING

    return EXIT_SUCCESS;
}
