#ifndef __LIBNUBBY_RANGESTATS_H__
#define __LIBNUBBY_RANGESTATS_H__

#include <libaeds/class/monoid.h>
#include <libaeds/data/ix/range.h>


typedef struct RangeStats {
  long min, max, sum;
} RangeStats;

extern const Monoid rangestats_monoid; // Monoid instance for RangeStats.


// Compute the RangeStats for the given range in an array.
// Complexity: O(ixrange_size(range)).
RangeStats rangestats(const long*, IxRange);


#endif /* __LIBNUBBY_RANGESTATS_H__ */
