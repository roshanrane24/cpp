#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

bool isEmpty(struct node* node)
{
    if (node == NULL)
    {
        return true;
    } else {
        return false;
    }
}

void printListRec(struct node *node)
{
    // print data & recurse until node is NULL
    if (node == NULL)
    {
        printf(" \n");
        return;
    }
    printf("%d ", node->data);
    printListRec(node->next);
}

void printList(struct node* node)
{
    struct node* element = node;

    printf("[");
    if (! isEmpty(node)) {
        while (element->next != NULL) {
            printf("%d, ", element->data);
            element = element->next;
        }
        printf("%d",element->data);
    }
    printf("]\n");

}

void printListRev(struct node *node)
{
    // recurse until node is NULL then return
    // & print data
    if (node == NULL)
    {
        printf("\n");
        return;
    }
    printListRev(node->next);
    printf("%d ", node->data);
}

void insert(struct node **node, int value, int index)
{
    struct node* leftNode = *node;
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;

    // For empty List insert at start for index 0 & -1
    if (isEmpty(*node))
    {
        if (index == 0 || index == -1) {
            newNode->next = NULL;
            *node = newNode;
        } else {
            printf("%d index is out of range. List is Empty.", index);
        }
    } else {
    // For non-empty List insert at start or end for index 0 & -1 resp. & check if out of index for others
        if (index == 0) {
            newNode->next = *node;
            *node = newNode;
        } else if (index == -1) {
            while (leftNode->next != NULL) {
                leftNode = leftNode->next;
            }
            newNode->next = NULL;
            leftNode->next = newNode;
        } else {
            for (int i = 0; i < index-1; i++) {
                if (leftNode->next != NULL)
                {
                    leftNode = leftNode->next;
                } else {
                    printf("Out of index. Last %d\n", i+1);
                }
            }
            newNode->next = leftNode->next;
            leftNode->next = newNode;
        }
    }
}

void delete(struct node** node, int index)
{
    struct node* leftNode = *node;
    // for index 0 switch head & free;
    if (index == 0) {
        *node = (*node)->next;
        free(leftNode);
    } else if (index == -1)
    {
        // iterate until node before last & free last node.
        while(leftNode->next->next != NULL)
        {
            leftNode = leftNode->next;
        }
        free(leftNode->next);
        leftNode->next = NULL;
    } else {
        for (int i=0; i < index-1; i++)
        {
            if (leftNode->next != NULL){
                leftNode = leftNode->next;
            } else {
                printf("index %d is out of range. Max %d\n", index, i+1);
                return;
            }
        }
        struct node *t = leftNode->next->next;
        free(leftNode->next);
        leftNode->next = t;
    }
}

void reverse(struct node** node)
{
    struct node *prev, *curr, *next;
    prev = NULL;
    curr = *node;

    if (! isEmpty(*node))
    {
        while (curr->next != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        *node = curr;
    }
}

void* reverseRecurcive(struct node **node)
{
    // Recurse until last node. return from last node.
    if ((*node)->next == NULL) {
        return *node;
    }
    struct node *head = reverseRecurcive(&(*node)->next);

    // Set link for next node to current node & current
    // nodes link to NULL
    (*node)->next->next = *node;
    (*node)->next = NULL;
    return head;
}

int main()
{
    // Declare Head Node NULL
    struct node* LL = NULL;

    // Insert
    insert(&LL, 1, -1);
    insert(&LL, 12, 0);
    insert(&LL, 66, -1);
    insert(&LL, 78, -1);
    insert(&LL, 21, 2);
    insert(&LL, 45, 0);
    insert(&LL, 12, 0);
    insert(&LL, 63, -1);
    insert(&LL, 21, -1);
    insert(&LL, 45, 5);
    insert(&LL, 52, -1);
    insert(&LL, 31, -1);
    insert(&LL, 12, 0);
    insert(&LL, 45, 12);
    insert(&LL, 37, 8);
    insert(&LL, 19, 4);
    insert(&LL, 38, 0);
    insert(&LL, 28, 15);
    insert(&LL, 92, -1);
    insert(&LL, 76, -1);
    insert(&LL, 67, -1);
    insert(&LL, 19, -1);
    insert(&LL, 34, -1);
    insert(&LL, 97, -1);
    insert(&LL, 56, -1);

    // Print List
    printList(LL);

    // Delete first Last & somewhere in middle
    delete(&LL, 0);
    delete(&LL, -1);
    delete(&LL, 14);
    delete(&LL, 20);

    printList(LL);

    // Reverse List
    reverse(&LL);

    printList(LL);

    // Print revese list without changes
    printListRec(LL);
    printListRev(LL);
    printf("\n");

    // reversing list recursively
    printList(LL);
    LL = reverseRecurcive(&LL);
    printList(LL);
}

