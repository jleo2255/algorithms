#ifndef MGSORT_H
#define MGSORT_H

int mgsort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2));

#endif
