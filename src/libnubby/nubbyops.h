#ifndef __LIBNUBBY_NUBBYOPS_H__
#define __LIBNUBBY_NUBBYOPS_H__

#include <libaeds/data/container/segtree.h>
#include <libaeds/data/ix/range.h>

#include <libnubby/nubbymat.h>


// Nubby operations:
// Add i j: add 1 to all elements in the interval [i, j].
// Sub i j: subtract 1 to all elements in the interval [i, j].
// Min i j: query the minimum element in the interval [i, j].
// Max i j: query the maximum element in the interval [i, j].
// Sum i j: query the sum of all elements in the interval [i, j].


// NubbyMat ------------------------------------------------------------------------------

// Perform a nubby operation on a NubbyMat.
void nubby_op(NubbyMat*, char op[4], IxRange);


// SegTree -------------------------------------------------------------------------------

// Init a rangestats leaf in a segtree from the correspondent element in the source array.
void rangestats_leaf_init(void* data, void* leaf);
// Perform a nubby operation on a SegTree.
void nubby_tree_op(SegTree, char op[4], IxRange);


#endif /* __LIBNUBBY_NUBBYOPS_H__ */
