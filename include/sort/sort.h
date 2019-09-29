#ifndef __SORT_H__
#define __SORT_H__

/**
 * @brief insert sort implement, (suitable for small sets of data)
 *
 * @param data : array of elements in data
 * @param size : the number of elements in data
 * @param esize : the size of each element
 * @param compare : function pointer compare between elements
 *
 * @return 0 if sorting is successful, or -1 otherwise
 */
int insert_sort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));


#endif /* end of include guard */
