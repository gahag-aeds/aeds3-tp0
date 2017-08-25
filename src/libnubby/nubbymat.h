#ifndef __LIBNUBBY_NUBBYMAT_H__
#define __LIBNUBBY_NUBBYMAT_H__

#include <stddef.h>

#include <libaeds/data/array.h>
#include <libaeds/memory/allocator.h>

#include <libnubby/rangestats.h>


typedef struct NubbyMat NubbyMat;


NubbyMat* new_nubbymat(const Allocator* allocator, long* array, size_t size);
void delete_nubbymat(NubbyMat**);

Array nubbymat_source(const NubbyMat*);

RangeStats* nubbymat_query(const NubbyMat*, IxRange range);

void nubbymat_update(NubbyMat*);


#endif /* __LIBNUBBY_NUBBYMAT_H__ */
