#ifndef __LIBNUBBY_NUBBYMAT_H__
#define __LIBNUBBY_NUBBYMAT_H__

#include <libaeds/data/array.h>
#include <libaeds/memory/allocator.h>

#include <libnubby/rangestats.h>


typedef struct NubbyMat NubbyMat; // Opaque type for a nubby matrix.


// Creates a nubbymat for the given array.
// Complexity: O(size^2)
NubbyMat* new_nubbymat(const Allocator* allocator, long* array, size_t size);

// Delete a nubbymat, deallocating the memory used.
// Complexity: O(1)
void delete_nubbymat(NubbyMat**);


// Get the source array of the nubbymat.
Array nubbymat_source(const NubbyMat*);


// Queries the rangestats for a given range.
// The range must be fully contained in [0, size - 1].
// Complexity: O(1)
RangeStats* nubbymat_query(const NubbyMat*, IxRange range);


// Recomputes the matrix for the source array.
// This function should be called when one or
// more elements of the source array are modified.
// Complexity: O(size^2)
void nubbymat_update(NubbyMat*);


#endif /* __LIBNUBBY_NUBBYMAT_H__ */
