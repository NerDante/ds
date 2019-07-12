#include "clist.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief init a list specified by list
 *
 * @param list: pointer to List
 * @param destroy: func pointer used to destroy data
 */
void clist_init(CList* list, void (*destroy)(void* data))
{
    list->size = 0;
    list->head = NULL;
    list->destroy = destroy;
}

/**
 * @brief destroy all the list, every data will destroied by destroy func pass
 *        to list_init()
 *
 * @param list : CList *
 */
void clist_destroy(CList* list)
{
    void* data;

    while (list->size > 0) {
        if (clist_rem_next(list, list->head, (void**)&data) == 0 && data != NULL) {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(CList));
}

/**
 * @brief insert after element to list
 *
 * @param list : CList to handle
 * @param element : if element is NULL, insert to head
 * @param data : insert data
 *
 * @return 0:success, -1:fail
 */
int clist_ins_next(CList* list, CListElmt* element, const void* data)
{
    CListElmt* new;

    if (element == NULL && list->size != 0) {
        return -1;
    }

    new = malloc(sizeof(CListElmt));
    if (NULL == new) {
        return -1;
    }

    new->data = (void*)data;

    if (list->size == 0) {
        list->head = new;
        new->next = new;
    } else {
        new->next = element->next;
        element->next = new;
    }

    list->size++;
    return 0;
}

/**
 * @brief remove after element from list
 *
 * @param list : CList to handle
 * @param element : if element is NULL, will remove head
 * @param data : hold the data of element, how to use depend to user
 *
 * @return  0:succes, -1:fail
 */
int clist_rem_next(CList* list, CListElmt* element, void** data)
{
    CListElmt* old;

    if (NULL == list || NULL == data) {
        return -1;
    }

    // not allowed for empty list
    if (clist_size(list) == 0) {
        return -1;
    }

    *data = element->next->data;
    if (element->next == element) {
        old = element->next;
        list->head = NULL;
    } else {
        old = element->next;
        element->next = old->next;
        if (element->next == list->head) {
            list->head = old->next;
        }
    }

    list->size--;
    free(old);

    return 0;
}
