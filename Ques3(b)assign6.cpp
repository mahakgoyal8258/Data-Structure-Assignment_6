
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
            tail = newNode;
        }
    }

    if (head != NULL)
        tail->next = head;

    if (head != NULL)
    {
        Node* temp = head;

        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
    }

    cout << "Size of Circular Linked List: "
         << count << endl;

    // Break the circle and free memory
    if (tail != NULL)
        tail->next = NULL;

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

