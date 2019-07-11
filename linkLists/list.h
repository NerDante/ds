#ifndef __LIST_H__
#define __LIST_H__

/*struct define*/
typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;
}ListElmt;

typedef struct List_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
}List;

/*public interface*/
void list_init(List *list, void(*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element)->next == (list)->head ? 1: 0)
#define list_is_tail(list, element) ((element)->next == NULL ? 1: 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#define list_add_head(list, data) list_ins_next((list), NULL, (data))
#define list_add_tail(list, data) list_ins_next((list), (list)->tail, (data))

#endif /* __LIST_H__ */
