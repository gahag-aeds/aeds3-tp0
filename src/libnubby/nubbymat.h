#ifndef __LIBNUBBY_NUBBYMAT_H__
#define __LIBNUBBY_NUBBYMAT_H__

#include <stddef.h>

#include <libaeds/memory/allocator.h>

#include <libnubby/nubbyops.h>


typedef struct NubbyMat NubbyMat;


NubbyMat* new_nubbymat(const Allocator* allocator, long* array, size_t size);
void delete_nubbymat(NubbyMat**);

RangeStats* nubbymat_query(NubbyMat*, IxRange range);

void nubbymat_update(NubbyMat*);


#endif /* __LIBNUBBY_NUBBYMAT_H__ */
