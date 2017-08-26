#include <assert.h>

#include "nubbymat.h"


struct NubbyMat {
  const Allocator* allocator;
  
  long* source; // The source array.
  size_t size;  // The size of the source array.
  
  RangeStats data[]; // 2d flexible member array for the matrix.
};


// O(size^2)
NubbyMat* new_nubbymat(const Allocator* allocator, long* array, size_t size) {
  assert(allocator != NULL);
  assert(array != NULL);
  assert(size > 0);
  
  NubbyMat* mat = al_alloc(
    allocator,
    1,
    sizeof(NubbyMat) + sizeof(RangeStats[size][size])
  );
  
  mat->allocator = allocator;
  mat->source = array;
  mat->size = size;
  
  nubbymat_update(mat); // O(size^2).
  
  return mat;
}

// O(1)
void delete_nubbymat(NubbyMat** _mat) {
  assert(_mat != NULL);
  
  NubbyMat* mat = *_mat;
  
  if (mat != NULL) {
    al_dealloc(mat->allocator, mat);
    *_mat = NULL;
  }
}


Array nubbymat_source(const NubbyMat* mat) {
  assert(mat != NULL);
  
  return (Array) {
    .data = mat->source,
    .size = mat->size,
    .elem_size = sizeof(long)
  };
}


// O(1)
RangeStats* nubbymat_query(const NubbyMat* mat, IxRange range) {
  assert(mat != NULL);
  assert(range.end < mat->size && range.begin < mat->size);
  
  RangeStats (*data)[mat->size][mat->size] = (void*) &(mat->data);
  
  return &(*data)[range.begin][range.end];
}


// O(size^2)
void nubbymat_update(NubbyMat* mat) {
  assert(mat != NULL);
  
  // Nubby matrix is symmetric:
  for (size_t i = 0; i < mat->size; i++)
    for (size_t j = i; j < mat->size; j++) {
      IxRange range = { i, j };
      
      *nubbymat_query(mat, range) =
      *nubbymat_query(mat, (IxRange) { j, i }) = rangestats(mat->source, range);
    }
}
