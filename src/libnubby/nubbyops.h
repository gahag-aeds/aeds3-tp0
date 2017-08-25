#ifndef __LIBNUBBY_NUBBYOPS_H__
#define __LIBNUBBY_NUBBYOPS_H__

#include <libaeds/data/container/segtree.h>
#include <libaeds/data/ix/range.h>

#include <libnubby/nubbymat.h>


void nubby_op(NubbyMat*, char op[4], IxRange);
void nubby_tree_op(SegTree, char op[4], IxRange);


#endif /* __LIBNUBBY_NUBBYOPS_H__ */
