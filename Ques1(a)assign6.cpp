
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeginning(int x) {
    Node* newNode = new Node();
    newNode->data = x;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(int x) {
    Node* newNode = new Node();
    newNode->data = x;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Insert after a specific node
void insertAfter(int key, int x) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do {
        if (temp->data == key) {
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = temp->next;
            temp->next = newNode;

            cout << "Node inserted\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node not found\n";
}

// Insert before a specific node
void insertBefore(int key, int x) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->data == key) {
        insertBeginning(x);
        return;
    }

    Node* temp = head;

    while (temp->next != head && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == head) {
        cout << "Node not found\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted\n";
}

// Delete a specific node
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    do {
        if (temp->data == key) {

            // Only one node
            if (temp->next == head && temp == head) {
                head = NULL;
                delete temp;
                cout << "Node deleted\n";
                return;
            }

            // Deleting head
            if (temp == head) {
                Node* last = head;

                while (last->next != head) {
                    last = last->next;
                }

                head = head->next;
                last->next = head;
                delete temp;

                cout << "Node deleted\n";
                return;
            }

            // Deleting middle or last node
            prev->next = temp->next;
            delete temp;

            cout << "Node deleted\n";
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    cout << "Node not found\n";
}

// Search a node
void searchNode(int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    int pos = 1;

    do {
        if (temp->data == key) {
            cout << "Node found at position " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;

    } while (temp != head);

    cout << "Node not found\n";
}

// Display list
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(HEAD)\n";
}

int main() {
    int choice, x, key;

    do {
        cout << "\n--- CIRCULAR LINKED LIST ---\n";
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

