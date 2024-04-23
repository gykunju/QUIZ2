#include <stdio.h>
#include <stdlib.h>

struct list{
    int value;
    struct list *next;
};

struct list* reversed(struct list *head);


int main()
{
    struct list *list1 = (struct list*)malloc(sizeof(struct list));
    struct list *list2 = (struct list*)malloc(sizeof(struct list));
    struct list *list3 = (struct list*)malloc(sizeof(struct list));
    struct list *list4 = (struct list*)malloc(sizeof(struct list));

    list1->value = 1;
    list1->next = list2;
    list2->value = 2;
    list2->next = list3;
    list3->value = 3;
    list3->next = list4;
    list4->value = 4;

    printf("list4: %p\n", list4);
    printf("reversed: %p", reversed(list1));

    return 0;
}

struct list* reversed(struct list *head){
    struct list *current = head;
    struct list *previous = NULL;
    struct list *following = NULL;

    while(current != NULL){
        following = current->next;
        current->next = previous;
        previous = current;
        current = following;
    }

    return previous;
}
