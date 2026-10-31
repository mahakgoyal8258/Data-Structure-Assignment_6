
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeginning(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

// Insert at end
void insertEnd(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after a specific node
void insertAfter(int key, int x) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = x;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    cout << "Node inserted\n";
}

// Insert before a specific node
void insertBefore(int key, int x) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (temp == head) {
        insertBeginning(x);
        return;
    }

    Node* newNode = new Node();
    newNode->data = x;

    newNode->prev = temp->prev;
    newNode->next = temp;

    temp->prev->next = newNode;
    temp->prev = newNode;

    cout << "Node inserted\n";
}

// Delete a specific node
void deleteNode(int key) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;

    cout << "Node deleted\n";
}

// Search a node
void searchNode(int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node found at position " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;
    }

    cout << "Node not found\n";
}

// Display list
void display() {
    Node* temp = head;

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    int choice, x, key;

    do {
        cout << "\n--- DOUBLY LINKED LIST ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertBeginning(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insertEnd(x);
                break;

            case 3:
                cout << "Enter existing node value: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> x;
                insertAfter(key, x);
                break;

            case 4:
                cout << "Enter existing node value: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> x;
                insertBefore(key, x);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteNode(key);
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}

