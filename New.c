#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

struct node* reverseList(struct node* head) {
    struct node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int isPalindrome(struct node* head) {
    struct node *slow = head, *fast = head, *prevHalf = NULL, *secondHalf = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        prevHalf = slow;
        slow = slow->next;
    }
    if (fast) slow = slow->next;
    secondHalf = reverseList(slow);
    struct node *p1 = head, *p2 = secondHalf;
    while (p2) {
        if (p1->data != p2->data) return 0;
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;
}

int main() {
    int n, x, i;
    struct node *head = NULL, *temp = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        struct node* newnode = createNode(x);
        if (!head) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    if (isPalindrome(head))
        printf("Number is a palindrome\n");
    else
        printf("Number is not a palindrome\n");
    return 0;
}
