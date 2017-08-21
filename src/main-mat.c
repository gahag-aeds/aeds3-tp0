#include <stdio.h>
#include <stdlib.h>

#include <libaeds/data/ix/range.h>
#include <libaeds/memory/allocator.h>

#include <libnubby/nubbymat.h>


int main() {
  Allocator allocator = std_allocator(abort);
  
  unsigned long array_size, queries_count;
  
  long* array;
  
  
  if (scanf("%lu %lu", &array_size, &queries_count) != 2)
    return -1;
  
  array = al_alloc(&allocator, array_size, sizeof(long));
  
  for (unsigned long i = 0; i < array_size; i++)
    if (scanf("%ld", &array[i]) != 1)
      return al_dealloc(&allocator, array), -1;
  
  //
  NubbyMat* nm = new_nubbymat(&allocator, array, array_size);
  
  for (size_t i = 0; i < array_size; i++) {
    for (size_t j = 0; j < array_size; j++) {
      RangeStats* stats = nubbymat_query(nm, (IxRange) { i, j });
      printf("(%ld, %ld, %ld) ", stats->min, stats->max, stats->sum);
    }
    puts("");
  }
  //
  
  for (unsigned long i = 0; i < queries_count; i++) {
    char str[4];
    IxRange range;
    
    if (fgets(str, 4, stdin) == NULL)
      return al_dealloc(&allocator, array), -1;
    
    if (scanf("%lu %lu", &range.begin, &range.end) != 2)
      return al_dealloc(&allocator, array), -1;
  }
  
  
  return al_dealloc(&allocator, array), 0;
}
