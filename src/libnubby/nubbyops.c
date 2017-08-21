#include "nubbyops.h"

#include <assert.h>
#include <stddef.h>


RangeStats range_stats(const long* array, IxRange range) {
  assert(array != NULL);
  
  RangeStats stats = {
    .min = array[range.begin],
    .max = array[range.begin],
    .sum = array[range.begin]
  };
  
  for (size_t i = range.begin + 1; i <= range.end; i++) {
    if (stats.min > array[i])
      stats.min = array[i];
    else
      if (stats.max < array[i])
        stats.max = array[i];
    
    stats.sum += array[i];
  }
  
  return stats;
}
