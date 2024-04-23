#include <stdio.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

struct list* beggining_node(struct list *head){
    if(head == NULL){
        return NULL;
    }

    struct list *slow = head;
    struct list *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }

    if(fast == NULL || fast->next == NULL){
        return NULL
    }

    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    struct list *answer = beggining_node(head);
    printf("Hello world!\n");
    return 0;
}



