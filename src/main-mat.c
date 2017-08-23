#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libaeds/data/array.h>
#include <libaeds/data/ix/range.h>
#include <libaeds/data/resources/memory.h>
#include <libaeds/data/resources/resource.h>
#include <libaeds/memory/allocator.h>

#include <libnubby/nubbymat.h>
#include <libnubby/nubbyops.h>


int main() {
  Allocator allocator = std_allocator(abort);
  Resources res = new_resources(&allocator);
  
  unsigned long array_size, queries_count;
  
  long* array;
  NubbyMat* nubbymat;
  
  
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
  
  
  nubbymat = new_nubbymat(&allocator, array, array_size);
  rs_register(
    &nubbymat,
    rs_disposer((void (*)(void*)) delete_nubbymat),
    &res
  );
  
  
  for (unsigned long i = 0; i < queries_count; i++) {
    char op[4];
    IxRange range;
    
    if (scanf("%3s %lu %lu", op, &range.begin, &range.end) != 3)
      return delete_resources(&res), -1;
    
    nubby_op(nubbymat, op, range);
  }
  
  
  return delete_resources(&res), 0;
}
