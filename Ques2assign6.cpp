
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
    int n, x;

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

    if (head == NULL)
        return 0;

    // Make the list circular
    tail->next = head;

    cout << "Output: ";

    Node* temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    // Print the head value one extra time
    cout << head->data << endl;

    // Break the circular link before deleting nodes
    tail->next = NULL;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

