#include "nubbyops.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <libaeds/data/arithmetic.h>
#include <libaeds/data/array.h>


void nubby_op(NubbyMat* nubbymat, char op[4], IxRange range) {
  assert(nubbymat != NULL);
  assert(op != NULL);
  
  range.begin--;  // Input is 1-indexed.
  range.end--;
    
  if (strcmp(op, "Add") == 0) {
    array_fmap_range(
      nubbymat_source(nubbymat),
      sizeof(long),
      range,
      &inc_long
    );
    
    nubbymat_update(nubbymat);
  }
  else if (strcmp(op, "Sub") == 0) {
    array_fmap_range(
      nubbymat_source(nubbymat),
      sizeof(long),
      range,
      &dec_long
    );
    
    nubbymat_update(nubbymat);
  }
  else if (strcmp(op, "Sum") == 0)
    printf("%ld\n", nubbymat_query(nubbymat, range)->sum);
  else if (strcmp(op, "Min") == 0)
    printf("%ld\n", nubbymat_query(nubbymat, range)->min);
  else if (strcmp(op, "Max") == 0)
    printf("%ld\n", nubbymat_query(nubbymat, range)->max);
}
