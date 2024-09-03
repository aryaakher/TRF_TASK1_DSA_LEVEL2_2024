#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        result = insertAtEnd(result, sum % 10);
    }

    return result;
}

struct Node* LinkedListIP(int number) {
    struct Node* head = NULL;
    do {
        head = insertAtEnd(head, number % 10);
        number /= 10;
    } while (number != 0);
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    struct Node* l1 = LinkedListIP(num1);
    struct Node* l2 = LinkedListIP(num2);

    struct Node* sumList = addTwoNumbers(l1, l2);

    printf("First number (stored in reverse order): ");
    printList(l1);

    printf("Second number (stored in reverse order): ");
    printList(l2);

    printf("Sum of the two numbers (stored in reverse order): ");
    printList(sumList);

    return 0;
}
