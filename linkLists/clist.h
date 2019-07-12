#ifndef __LIST_H__
#define __LIST_H__

/*struct define*/
typedef struct CListElmt_ {
    void *data;
    struct CListElmt_ *next;
}CListElmt;

typedef struct CList_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    CListElmt *head;
}CList;

/*public interface*/
void clist_init(CList *list, void(*destroy)(void *data));
void clist_destroy(CList *list);
int clist_ins_next(CList *list, CListElmt *element, const void *data);
int clist_rem_next(CList *list, CListElmt *element, void **data);

#define clist_size(list) ((list)->size)
#define clist_head(list) ((list)->head)
#define clist_data(element) ((element)->data)
#define clist_next(element) ((element)->next)

#endif /* __LIST_H__ */
