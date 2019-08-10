#include "lib.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    head_t *head = malloc(sizeof(*head));
    list_t *list = malloc(sizeof(*list));
    initialisation(head, list);
    insertion(head, 456);
    insertion_end(head, 520);
    insertion_at(head, 0 , 666);
    afficherListe(head);
    delet(head);
    afficherListe(head);
    delete_all(head);
    afficherListe(head);
   return (0);
}

int initialisation(head_t *head,list_t *elements)
{
    if (head == NULL || elements == NULL)
        exit(1);
    elements->nb = 120;
    elements->next = NULL;
    head->first = elements;
    head->size = 1;
    return (0);
}

int insertion(head_t *head, int nb)
{
    list_t *new = malloc(sizeof(*new));

    if (head == NULL || new == NULL)
        exit(EXIT_FAILURE);
    new->nb = nb;
    new->next = head->first;
    head->first = new;
    head->size += 1;
    return (0);
} 

int insertion_end(head_t *head, int nb)
{
    list_t *new = malloc(sizeof(*new));
    list_t *tmp;

    if (head == NULL || new == NULL)
        exit(EXIT_FAILURE);
    tmp = head->first;
    new->nb = nb;
    new->next = NULL;
    for(int i = 0;i < head->size - 1; i++)
        tmp = tmp->next;
    tmp->next = new;
    head->size++;
    return (0);
} 

int insertion_at(head_t *head ,int position ,int nb)
{
    list_t *new = malloc(sizeof(*new));
    list_t *actuel;
    list_t *tmp;

    if (position > head->size - 1)
        return (1);
    actuel = head->first;
    for(int i = 0;i < position;i++)
        actuel = actuel->next;
    new->nb = nb;
        tmp = actuel->next;
        actuel->next = new;
        new->next = tmp;
    head->size++;
    return (0);
}

int afficherListe(head_t *head)
{
    list_t *actuel;

    if (head == NULL)
        exit(EXIT_FAILURE);
    actuel = head->first;
    for(int i = 0;i < head->size;i++){
        printf("%d \n", actuel->nb);
        actuel = actuel->next;
    }
    //printf("\n");
    return (0);
}

int delete_all(head_t *head)
{
    list_t *delete;

    if (head == NULL)
        exit(EXIT_FAILURE);
    delete = head->first;
        while (head->first != NULL) {
            delete = head->first;
            head->first = head->first->next;
            free(delete);
        }
    head->size = 0;
    return (0);
}

int delet(head_t *head)
{
    list_t *delete;

    if (head == NULL)
        exit(EXIT_FAILURE);
    if (head->first != NULL) {
        delete = head->first;
        head->first = head->first->next;
        free(delete);
    }
    head->size -= 1;
    return (0);
}