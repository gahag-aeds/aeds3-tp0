#include <assert.h>

#include "nubbymat.h"


struct NubbyMat {
  const Allocator* allocator;
  
  const long* source;
  size_t size;
  
  RangeStats (*data)[]; // Array of pointers to RangeStats.
};


NubbyMat* new_nubbymat(const Allocator* allocator, long* array, size_t size) {
  assert(allocator != NULL);
  assert(array != NULL);
  assert(size > 0);
  
  NubbyMat* mat = al_alloc(allocator, 1, sizeof(NubbyMat) + sizeof(RangeStats[size][size]));
  
  mat->allocator = allocator;
  mat->source = array;
  mat->size = size;
  
  nubbymat_update(mat);
  
  return mat;
}

void delete_nubbymat(NubbyMat** _mat) {
  assert(_mat != NULL);
  
  NubbyMat* mat = *_mat;
  
  if (mat != NULL) {
    al_dealloc(mat->allocator, mat);
    *_mat = NULL;
  }
}


RangeStats* nubbymat_query(NubbyMat* mat, IxRange range) {
  assert(mat != NULL);
  
  RangeStats (*data)[mat->size][mat->size] = (void*) &(mat->data);
  
  return &(*data)[range.begin][range.end];
}


void nubbymat_update(NubbyMat* mat) {
  assert(mat != NULL);
  
  for (size_t i = 0; i < mat->size; i++)
    for (size_t j = i; j < mat->size; j++) {
      IxRange range = { i, j } ;
      // Nubby matrix is symmetric:
      *nubbymat_query(mat, (IxRange) { j, i }) =
      *nubbymat_query(mat, range) = range_stats(mat->source, range);
    }
}
