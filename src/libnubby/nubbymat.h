#ifndef __LIBNUBBY_NUBBYMAT_H__
#define __LIBNUBBY_NUBBYMAT_H__

#include <stddef.h>

#include <libaeds/memory/allocator.h>

#include <libnubby/rangestats.h>


typedef struct NubbyMat NubbyMat;


NubbyMat* new_nubbymat(const Allocator* allocator, long* array, size_t size);
void delete_nubbymat(NubbyMat**);

long* nubbymat_source(const NubbyMat*);
size_t nubbymat_size(const NubbyMat*);

RangeStats* nubbymat_query(const NubbyMat*, IxRange range);

void nubbymat_update(NubbyMat*);


#endif /* __LIBNUBBY_NUBBYMAT_H__ */
