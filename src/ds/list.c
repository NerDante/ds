#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief init a list specified by list
 *
 * @param list: pointer to List
 * @param destroy: func pointer used to destroy data
 */
void list_init(List* list, void(*destroy)(void* data))
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->destroy = destroy;
}

/**
 * @brief destroy all the list, every data will destroied by destroy func pass
 *        to list_init()
 *
 * @param list : List *
 */
void list_destroy(List* list)
{
    void* data;

    while (list->size > 0) {
        if (list_rem_next(list, NULL, (void**)&data) == 0 && data != NULL) {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(List));
}

/**
 * @brief insert after element to list
 *
 * @param list : List to handle
 * @param element : if element is NULL, insert to head
 * @param data : insert data
 *
 * @return 0:success, -1:fail
 */
int list_ins_next(List* list, ListElmt* element, const void* data)
{
    ListElmt* new;

    new = malloc(sizeof(ListElmt));
    if (NULL == new) {
        return -1;
    }

    new->data = (void *)data;

    if (element == NULL) {// insert to head
        if (list_size(list) == 0) {
            list->tail = new;
        }
        new->next = list->head;
        list->head = new;
    } else {
        if (list_tail(list) == element) {
            list->tail = new;
        }
        new->next = element->next;
        element->next = new;
    }

    list->size++;
    return 0;
}

/**
 * @brief remove after element from list
 *
 * @param list : List to handle
 * @param element : if element is NULL, will remove head
 * @param data : hold the data of element, how to use depend to user
 *
 * @return  0:succes, -1:fail
 */
int list_rem_next(List* list, ListElmt* element, void** data)
{
    ListElmt *old;

    if (NULL == list || NULL == data) {
        return -1;
    }

    // not allowed for empty list
    if (list_size(list) == 0) {
        return -1;
    }

    if (element == NULL) { //rm from head
        old = list->head;
        *data = old->data;
        list->head = old->next;

        if (list_size(list) == 1) {
            list->tail = NULL;
        }
    } else {
        if (element->next == NULL) {
            return -1;
        }

        old = element->next;
        *data = old->data;
        element->next = element->next->next;
        if (element->next == NULL) {
            list->tail = NULL;
        }
    }

    list->size--;
    free(old);

    return 0;
}
