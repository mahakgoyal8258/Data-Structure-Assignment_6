
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

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int n, x, count = 0;

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
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Size of Doubly Linked List: "
         << count << endl;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

