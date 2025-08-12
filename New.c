#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertEnd(struct node **head, int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node *temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newnode;
}

void reverseList(struct node **head) {
    struct node *prev = NULL, *curr = *head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int isPalindrome(struct node *head) {
    struct node *slow = head, *fast = head, *prev = NULL, *second = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if (fast) slow = slow->next;
    prev->next = NULL;
    reverseList(&slow);
    second = slow;
    while (head && second) {
        if (head->data != second->data) return 0;
        head = head->next;
        second = second->next;
    }
    return 1;
}

int main() {
    int n, i, x;
    struct node *head = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head, x);
    }
    if (isPalindrome(head))
        printf("Number is a palindrome\n");
    else
        printf("Number is not a palindrome\n");
    return 0;
}
    else
        printf("Number is not a palindrome\n");
    return 0;
}
