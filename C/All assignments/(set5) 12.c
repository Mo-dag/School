/*
 *  Using bit operators in C
 *
 *  Samples:
 *  - bit_operators
 *
 *  See also https://en.wikipedia.org/wiki/Bitwise_operations_in_C
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Test macros
#define CHECK_IF_EQUAL(v1, v2) printf( (v1) == (v2) ? "OK\n" : "not OK\n")
#define CHECK_IF_BYTE_EQUAL(S1, S2) (S1 ^ S2) == 0 ? printf("OK\n") : printf("not Ok\n")


// A shorter type name (byte_t) for unsigned char (i.e. a byte)
typedef unsigned char byte_t;

// ---------- Declarations --------------

byte_t byte_set_index(byte_t byte, int index);

bool byte_get_index(byte_t byte, int index);

byte_t byte_clear_index(byte_t byte, int index);

byte_t byte_and(byte_t b1, byte_t b2);

bool byte_equals(byte_t b1, byte_t b2);

byte_t byte_or(byte_t b1, byte_t b2);

// Are both bytes true at a common bit
bool byte_intersect(byte_t b1, byte_t b2);


int main() {

    CHECK_IF_EQUAL(byte_or(0x00, 0x01), 0x01);


    CHECK_IF_EQUAL(byte_and(0x01, 0x01), 0x01);

    CHECK_IF_EQUAL(byte_intersect(0xFA, 0x0A), true);
    CHECK_IF_EQUAL(byte_intersect(0xF0, 0x0F), false);

    CHECK_IF_BYTE_EQUAL(byte_set_index(0x00, 0), 0x01);
    CHECK_IF_BYTE_EQUAL(byte_set_index(0x00, 1), 0x02);
    CHECK_IF_BYTE_EQUAL(byte_set_index(0x00, 2), 0x04);

    CHECK_IF_BYTE_EQUAL(byte_get_index(0x0F, 0), true);  // I.e. bit 0 is set to 1
    CHECK_IF_BYTE_EQUAL(byte_get_index(0x0F, 4), false); // Bit 4 is 0

    CHECK_IF_BYTE_EQUAL(byte_clear_index(0xFF, 0), 0xFE);
    CHECK_IF_BYTE_EQUAL(byte_clear_index(0xFF, 1), 0xFD);
    CHECK_IF_BYTE_EQUAL(byte_clear_index(0xFF, 2), 0xFB);

    CHECK_IF_EQUAL(byte_equals(0xFA, 0xFA), true);
    CHECK_IF_EQUAL(byte_equals(0xFE, 0xFA), false);


    return 0;
}


// ----------- Implementations of functions ---------------------

byte_t byte_or(byte_t b1, byte_t b2) {
    // TODO
    byte_t result = b1|b2;
    return result;
}

// TODO Rest of the implementations.
byte_t byte_and(byte_t b1,byte_t b2){
    byte_t and = b1&b2;
    return and;
}

bool byte_equals(byte_t b1, byte_t b2){
    if(b1==b2){
        return true;
    }
    return false;
}

bool byte_intersect(byte_t b1, byte_t b2){
    return (b1 & b2) !=0;
}

byte_t byte_set_index(byte_t byte,int index){
    byte_t shift = 1 << index;
    return (byte | shift); 
}

bool byte_get_index(byte_t byte, int index){
    byte_t shift = 1<<index;
    return (byte & shift)!=0; 
} 

byte_t byte_clear_index(byte_t byte,int index){
    byte_t shift = ~(1<<index);
    return (byte & shift);
}
