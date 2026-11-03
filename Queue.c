#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}


int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        front = rear = -1;
        return -1;
    } else {
        int deletedItem = queue[front];
        front++;
        printf("Deleted %d from the queue.\n", deletedItem);
        return deletedItem;
    }
}


void updateElement(int oldValue, int newValue) {
    int found = 0;
    for (int i = front; i <= rear; i++) {
        if (queue[i] == oldValue) {
            queue[i] = newValue;
            printf("Updated element %d to %d successfully.\n", oldValue, newValue);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the queue.\n", oldValue);
    }
}

// Display queue elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    updateElement(20, 25); // Updating element
    display();

    dequeue(); // Deleting element
    display();

    return 0;
}