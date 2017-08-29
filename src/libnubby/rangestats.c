#include "rangestats.h"

#include <assert.h>
#include <limits.h>
#include <stddef.h>


static void* rangestats_clear(void*);
static void* rangestats_append(void*, const void*);

const Monoid rangestats_monoid = {
  .clear = rangestats_clear,
  .append = rangestats_append
};


RangeStats rangestats(const long* array, IxRange range) {
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


// Monoid instance:
static void* rangestats_clear(void* _rs) {
  RangeStats* rs = _rs;
  
  *rs = (RangeStats) {
    .min = LONG_MAX,
    .max = LONG_MIN,
    .sum = 0
  };
  
  return rs;
}

static void* rangestats_append(void* _out, const void* _in) {
  RangeStats* out = _out;
  const RangeStats* in = _in;
  
  *out = (RangeStats) {
    .min = out->min < in->min ? out->min : in->min,
    .max = out->max > in->max ? out->max : in->max,
    .sum = out->sum + in->sum
  };
  
  return out;
}
