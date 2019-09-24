#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief init double link list
 *
 * @param list : Dlist
 * @param destroy : func to destroy data when dilist_destroy() is called
 */
void dlist_init(DList* list, void (*destroy)(void* data))
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->destroy = destroy;
}

/**
 * @brief revmoe all list element, destroy the data of element if list->destroy is not NULL
 *
 * @param list : list to be destroied
 */
void dlist_destroy(DList* list)
{
    void* data;

    while (dlist_size(list) > 0) {
        if (dlist_remove(list, dlist_tail(list), (void**)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(DList));
}

/**
 * @brief insert after element
 *
 * @param list : Dlist
 * @param element : if element == NULL, size of dlist must be 0
 * @param data : data add to list
 *
 * @return 0:success, -1:fail
 */
int dlist_ins_next(DList* list, DListElmt* element, const void* data)
{
    DListElmt* new;

    if (list == NULL || data == NULL) {
        return -1;
    }

    if (element == NULL && dlist_size(list) != 0) {
        return -1;
    }

    new = malloc(sizeof(DListElmt));
    if (NULL == new) {
        return -1;
    }
    new->data = (void*)data;

    if (dlist_size(list) == 0) {
        list->head = new;
        list->tail = new;
        new->prev = NULL;
        new->next = NULL;
    } else {
        if (!dlist_is_tail(element)) {
            element->next->prev = new;
        } else {
            list->tail = new;
        }
        new->next = element->next;
        new->prev = element;
        element->next = new;
    }

    list->size++;
    return 0;
}

/**
 * @brief insert before element
 *
 * @param list : Dlist
 * @param element : if element == NULL, size of dlist must be 0
 * @param data : data add to list
 *
 * @return 0:success, -1:fail
 */
int dlist_ins_prev(DList* list, DListElmt* element, const void* data)
{
    DListElmt* new;

    if (list == NULL || data == NULL) {
        return -1;
    }

    if (element == NULL && dlist_size(list) != 0) {
        return -1;
    }

    new = malloc(sizeof(DListElmt));
    if (NULL == new) {
        return -1;
    }
    new->data = (void*)data;

    if (dlist_size(list) == 0) {
        list->head = new;
        list->tail = new;
        new->prev = NULL;
        new->next = NULL;
    } else {
        if (!dlist_is_head(element)) {
            element->prev->next = new;
        } else {
            list->head = new;
        }
        new->next = element;
        new->prev = element->prev;
        element->prev = new;
    }

    list->size++;
    return 0;
}

/**
 * @brief remove a element
 *
 * @param list
 * @param element
 * @param data
 *
 * @return 0:success, -1:fail
 */
int dlist_remove(DList* list, DListElmt* element, void** data)
{
    if (element == NULL || dlist_size(list) == 0) {
        return -1;
    }

    *data = element->data;

    if (dlist_is_head(element)) {
        list->head = element->next;
        if (element->next == NULL) {
            list->tail = NULL;
        } else {
            element->next->prev = NULL;
        }
    } else {
        element->prev->next = element->next;
        if (element->next == NULL) {
            list->tail = element->prev;
        } else {
            element->next->prev = element->prev;
        }
    }

    free(element);
    list->size--;
}
