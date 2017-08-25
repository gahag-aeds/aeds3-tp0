#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libaeds/data/array.h>
#include <libaeds/data/container/segtree.h>
#include <libaeds/data/ix/range.h>
#include <libaeds/data/resources/memory.h>
#include <libaeds/data/resources/resource.h>
#include <libaeds/memory/allocator.h>

#include <libnubby/nubbyops.h>
#include <libnubby/rangestats.h>


void data_init(void* _ar_elem, void* _rs) {
  long* ar_elem = _ar_elem;
  RangeStats* rs = _rs;
  
  *rs = (RangeStats) {
    .min = *ar_elem,
    .max = *ar_elem,
    .sum = *ar_elem
  };
}

void m_clear(void* _rs) {
  RangeStats* rs = _rs;
  *rs = (RangeStats) {
    .min = LONG_MAX,
    .max = 0,
    .sum = 0
  };
}

void m_append(void* _out, const void* _in) {
  RangeStats* out = _out;
  const RangeStats* in = _in;
  
  *out = (RangeStats) {
    .min = out->min < in->min ? out-> min : in->min,
    .max = out->max > in->max ? out-> max : in->max,
    .sum = out->sum + in->sum
  };
}


int main() {
  Allocator allocator = std_allocator(abort);
  Resources res = new_resources(&allocator);
  
  unsigned long array_size, queries_count;
  
  long* array;
  //SegTree segtree;
  
  
  if (scanf("%lu %lu", &array_size, &queries_count) != 2)
    return delete_resources(&res), -1;
  
  array = rs_register_alloc(
    allocator, array_size, sizeof(*array),
    rs_disposer_al(&allocator),
    &res
  );
  
  for (unsigned long i = 0; i < array_size; i++)
    if (scanf("%ld", &array[i]) != 1)
      return delete_resources(&res), -1;
  
  
  SegTree segtree = new_segtree(
    &allocator,
    (Array) {
      .data = array,
      .size = array_size,
      .elem_size = sizeof(*array)
    },
    sizeof(RangeStats),
    data_init,
    (Monoid) {
      .clear = m_clear,
      .append = m_append
    }
  );
  rs_register(
    &segtree,
    rs_disposer((void (*)(void*)) delete_segtree),
    &res
  );
  
  
  for (unsigned long i = 0; i < queries_count; i++) {
    char op[4];
    IxRange range;
    
    if (scanf("%3s %lu %lu", op, &range.begin, &range.end) != 3)
      return delete_resources(&res), -1;
    
    nubby_tree_op(segtree, op, range);
  }
  
  
  return delete_resources(&res), 0;
}
