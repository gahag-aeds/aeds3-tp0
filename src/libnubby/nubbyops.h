#ifndef __LIBNUBBY_NUBBYOPS_H__
#define __LIBNUBBY_NUBBYOPS_H__

#include <stddef.h>

#include <libaeds/data/ix/range.h>


typedef struct RangeStats {
  long min, max, sum;
} RangeStats;


RangeStats range_stats(const long*, IxRange);


#endif /* __LIBNUBBY_NUBBYOPS_H__ */
