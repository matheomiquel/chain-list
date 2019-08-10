#ifndef MY_LIB_H_
#define MY_LIB_H_

typedef struct list_s
{
    int nb;
    struct list_s *next; 
} list_t;

typedef struct head_s
{
    list_t *first;
    int size;
} head_t;

int initialisation(head_t *head,list_t *elements);
int insertion(head_t *head, int nb);
int afficherListe(head_t *head);
int delet(head_t *head);
int delete_all(head_t *head);
int insertion_at(head_t *head ,int position ,int nb);
int insertion_end(head_t *head, int nb);

#endif