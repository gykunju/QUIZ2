#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list{
    int value;
    struct list *next;
};

bool cycle(struct list *head){
    if(head == NULL || head->next == NULL){
        return false;
    }

    struct list *slow = head;
    struct list *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main()
{
    struct list *head = (struct list*)malloc(sizeof(struct list));
    struct list *list1 = (struct list*)malloc(sizeof(struct list));
    struct list *list2 = (struct list*)malloc(sizeof(struct list));

    head->value = 1;
    head->next = list1;
    list1->value = 2;
    list1->next = list2;
    list2->value = 3;
    list2->next = list2;

    bool answer = cycle(head);
    printf("%s", answer ? "true" : "false");
    return 0;
}


