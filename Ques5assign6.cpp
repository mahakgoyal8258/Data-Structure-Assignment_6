
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int n, x, circular;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        Node* newNode = new Node(x);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Connect last node to head? (1 = Yes, 0 = No): ";
    cin >> circular;

    if (tail != NULL && circular == 1)
        tail->next = head;

    bool isCircular = false;

    if (head != NULL)
    {
        Node* temp = head->next;

        while (temp != NULL && temp != head)
            temp = temp->next;

        if (temp == head)
            isCircular = true;
    }

    if (isCircular)
        cout << "True: Circular Linked List\n";
    else
        cout << "False: Not a Circular Linked List\n";

    // Break the circular link before freeing memory
    if (tail != NULL && circular == 1)
        tail->next = NULL;

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

