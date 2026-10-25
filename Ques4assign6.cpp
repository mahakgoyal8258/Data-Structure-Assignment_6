
#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node* prev;
    Node* next;

    Node(char x)
    {
        data = x;
        prev = next = NULL;
    }
};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    string str;

    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        Node* newNode = new Node(str[i]);

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

    Node* left = head;
    Node* right = tail;
    bool palindrome = true;

    while (left != NULL && right != NULL)
    {
        if (left->data != right->data)
        {
            palindrome = false;
            break;
        }

        left = left->next;
        right = right->prev;

        if (left == right)
            break;

        if (left != NULL && left->prev == right)
            break;
    }

    if (palindrome)
        cout << "True";
    else
        cout << "False";

    cout << endl;

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

