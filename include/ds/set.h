#ifndef __SET_H__
#define __SET_H__

#include "list.h"

//implement sets as linked list
typedef List Set;

#define set_destroy list_destroy
#define set_size(set) ((set)->size)
//interfaces of sets
void set_init(Set *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
int set_insert(Set *set, const void *data);
int set_remove(Set *set, void **data);
int set_union(Set *setu, const Set *set1, const Set *set2);
int set_intersection(Set *seti, const Set *set1, const Set *set2);
int set_difference(Set *setd, const Set *set1, const Set *set2);
int set_is_member(const Set *set, const void *data);
int set_is_subset(const Set *set1, const Set *set2);
int set_is_equal(const Set *set1, const Set *set2);

#endif 
