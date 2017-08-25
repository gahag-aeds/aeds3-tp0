#include "nubbyops.h"

#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <libaeds/data/arithmetic.h>
#include <libaeds/data/array.h>


void add_one(void* _rs) {
  RangeStats* rs = _rs;
  
  rs->min++;
  rs->max++;
  rs->sum++;
}

void sub_one(void* _rs) {
  RangeStats* rs = _rs;
  
  rs->min--;
  rs->max--;
  rs->sum--;
}


void nubby_op(NubbyMat* nubbymat, char op[4], IxRange range) {
  assert(nubbymat != NULL);
  assert(op != NULL);
  
  range.begin--;  // Input is 1-indexed.
  range.end--;
  
  if (range.begin > range.end) {
    size_t aux = range.begin;
    range.begin = range.end;
    range.end = aux;
  }
  
  if (strcmp(op, "Add") == 0) {
    array_fmap_range(nubbymat_source(nubbymat), range, &inc_long);
    
    nubbymat_update(nubbymat);
  }
  else if (strcmp(op, "Sub") == 0) {
    array_fmap_range(nubbymat_source(nubbymat), range, &dec_long);
    
    nubbymat_update(nubbymat);
  }
  else if (strcmp(op, "Sum") == 0)
    printf("%ld\n", nubbymat_query(nubbymat, range)->sum);
  else if (strcmp(op, "Min") == 0)
    printf("%ld\n", nubbymat_query(nubbymat, range)->min);
  else if (strcmp(op, "Max") == 0)
    printf("%ld\n", nubbymat_query(nubbymat, range)->max);
}

void nubby_tree_op(SegTree tree, char op[4], IxRange range) {
  assert(op != NULL);
  
  range.begin--;  // Input is 1-indexed.
  range.end--;
  
  if (range.begin > range.end) {
    size_t aux = range.begin;
    range.begin = range.end;
    range.end = aux;
  }
  
  if (strcmp(op, "Add") == 0)
    segtree_update(tree, range, &add_one);
  else if (strcmp(op, "Sub") == 0)
    segtree_update(tree, range, &sub_one);
  else {
    RangeStats out;
    
    segtree_query(tree, range, &out);
    
    if (strcmp(op, "Sum") == 0)
      printf("%ld\n", out.sum);
    else if (strcmp(op, "Min") == 0)
      printf("%ld\n", out.min);
    else if (strcmp(op, "Max") == 0)
      printf("%ld\n", out.max);
  }
}
