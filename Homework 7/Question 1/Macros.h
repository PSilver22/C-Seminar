#ifndef _MACROS_H_
#define _MACROS_H_

// Swaps two variables of type t
#define SWAP(t, x, y) {      \
    t temp = (x);            \
    (x) = (y);               \
    (y) = (temp);            \
}

#endif