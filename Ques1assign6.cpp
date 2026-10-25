
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x)
    {
        data = x;
        prev = next = NULL;
    }
};

class CircularDoublyList
{
    Node* head;

public:
    CircularDoublyList()
    {
        head = NULL;
    }

    void insertBeginning(int x)
    {
        Node* n = new Node(x);

        if (head == NULL)
        {
            head = n;
            n->next = n;
            n->prev = n;
            return;
        }

        Node* last = head->prev;

        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
        head = n;
    }

    void insertEnd(int x)
    {
        if (head == NULL)
        {
            insertBeginning(x);
            return;
        }

        Node* n = new Node(x);
        Node* last = head->prev;

        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
    }

    void insertBefore(int key, int x)
    {
        Node* cur = head;

        if (cur == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        do
        {
            if (cur->data == key)
            {
                if (cur == head)
                {
                    insertBeginning(x);
                    return;
                }

                Node* n = new Node(x);
                n->prev = cur->prev;
                n->next = cur;
                cur->prev->next = n;
                cur->prev = n;
                return;
            }

            cur = cur->next;
        } while (cur != head);

        cout << "Value not found\n";
    }

    void insertAfter(int key, int x)
    {
        Node* cur = head;

        if (cur == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        do
        {
            if (cur->data == key)
            {
                Node* n = new Node(x);

                n->prev = cur;
                n->next = cur->next;
                cur->next->prev = n;
                cur->next = n;
                return;
            }

            cur = cur->next;
        } while (cur != head);

        cout << "Value not found\n";
    }

    void deleteNode(int key)
    {
        Node* cur = head;

        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        do
        {
            if (cur->data == key)
            {
                if (cur->next == cur)
                {
                    head = NULL;
                }
                else
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;

                    if (cur == head)
                        head = cur->next;
                }

                delete cur;
                cout << "Node deleted\n";
                return;
            }

            cur = cur->next;
        } while (cur != head);

        cout << "Value not found\n";
    }

    void search(int key)
    {
        Node* cur = head;
        int pos = 1;

        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        do
        {
            if (cur->data == key)
            {
                cout << "Found at position "
                     << pos << endl;
                return;
            }

            cur = cur->next;
            pos++;
        } while (cur != head);

        cout << "Value not found\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* cur = head;

        do
        {
            cout << cur->data << " <-> ";
            cur = cur->next;
        } while (cur != head);

        cout << "(head)\n";
    }
};

int main()
{
    CircularDoublyList list;
    int choice, x, key;

    do
    {
        cout << "\n1.Insert Beginning";
        cout << "\n2.Insert End";
        cout << "\n3.Insert Before";
        cout << "\n4.Insert After";
        cout << "\n5.Delete Specific Node";
        cout << "\n6.Search";
        cout << "\n7.Display";
        cout << "\n0.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            list.insertBeginning(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            list.insertEnd(x);
            break;

        case 3:
            cout << "Insert before which value? ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> x;
            list.insertBefore(key, x);
            break;

        case 4:
            cout << "Insert after which value? ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> x;
            list.insertAfter(key, x);
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> key;
            list.deleteNode(key);
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> key;
            list.search(key);
            break;

        case 7:
            list.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}

