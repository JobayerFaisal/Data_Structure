#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct node *head = nullptr;
struct node *tail = nullptr;

void insertNewNode(int value)
{
    struct node *nnode = new node;
    nnode->val = value;
    nnode->next = nullptr;

    if (head == NULL)
    {
        head = nnode;
        tail = nnode;
    }
    else
    {
        tail->next = nnode;
        tail = nnode;
    }
}

void insertInBegining(int value)
{
    struct node *nnode = new node;
    nnode->val = value;
    nnode->next = nullptr;

    if (head == NULL)
    {
        head = nnode;
        tail = nnode;
    }
    else
    {
        nnode->next = head;
        head = nnode;
    }
}

void insertPosition(int value, int position)
{
    struct node *nnode = new node;
    struct node *temp, *temp1;
    nnode->val = value;
    nnode->next = nullptr;

    if (head == NULL)
    {
        head = nnode;
        tail = nnode;
    }
    else
    {
        temp = head;
        int i = 1;
        while (i < position && temp != NULL)
        {
            temp1 = temp;
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            cout << "WARNING!!! : position not found " << endl;
        }
        else
        {
            nnode->next = temp;
            temp1->next = nnode;
        }
    }
}

void deleteNodeEnd()
{
    if (head == nullptr)
    {
        cout << "The linked list is empty. Nothing to delete." << endl;
        return;
    }

    struct node *temp = head;
    struct node *temp1 = nullptr;
    while (temp->next != nullptr)
    {
        temp1 = temp;
        temp = temp->next;
    }

    if (temp1 == nullptr)
    {
        // Only one node in the list
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        temp1->next = nullptr;
        tail = temp1;
    }
    delete temp;
}

struct node *reverse(struct node *head)
{
    struct node *cur = head;
    struct node *pre = nullptr;
    while (cur != nullptr)
    {
        struct node *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

void deleteNodeAtPosition(int position)
{

    if (head == nullptr)
    {
        cout << "The linked list is empty. Nothing to delete." << endl;
        return;
    }

    if (position <= 0)
    {
        cout << "Invalid position. Please provide a position greater than 0." << endl;
        return;
    }

    if (position == 1)
    {
        // Deleting the first node
        struct node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    struct node *current = head;
    struct node *prev = nullptr;
    int currentPosition = 1;

    while (current != nullptr && currentPosition < position)
    {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr)
    {
        cout << "Position exceeds the length of the linked list." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
}

struct node *deleteDuplicates(struct node *head)
{
    struct node *hello = head;
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    while (hello->next != nullptr && hello != nullptr)
    {
        if (hello->val == hello->next->val)
        {
            struct node *hello1 = hello->next;
            hello->next = hello1->next;
            delete hello1;
        }
        else
            hello = hello->next;
    }
    return head;
}

void Display(struct node *head)
{
    struct node *temp = head;
    cout << "\n\n";
    cout << "Current linkedlist is : " << endl;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    while (t != 99)
    {
        int n;
        cout << "\n\n\n1. Create linked list" << endl;
        cout << "2. Insert new node at the beginning" << endl;
        cout << "3. Insert new node at any position" << endl;
        cout << "4. Delete Node from last position" << endl;
        cout << "5. Delete Node from beginning" << endl;
        cout << "6. Delete Node from any position" << endl;
        cout << "7. Reverse linkedlist" << endl;
        cout << "8. Remove Duplicate from linkedlist" << endl;
        cout << "0. Display Linked list" << endl;

        cout << "\n----PLEASE, ENTER A NUMBER TO EXECUTE ANY OPERATION----" << endl;
        cout << "----BUT AT FIRST, CREATE A NEW LINKED LIST ----" << endl;

        cin >> n;
        switch (n)
        {
        case 0:
            Display(head);
            break;
        case 1:
        {
            cout << "Please, Enter the size of the list." << endl;
            int m;
            cin >> m;
            cout << "Please, Enter your values to add: " << endl;
            while (m--)
            {

                int n;
                cin >> n;
                insertNewNode(n);
            }
            Display(head);
            break;
        }
        case 2:
        {
            cout << "Please, Enter your value to add: " << endl;
            int pp;
            cin >> pp;
            insertInBegining(pp);
            Display(head);
            break;
        }
        case 3:
        {
            cout << "Please, Enter your value to add: " << endl;
            int p, pos;
            cin >> p;
            cout << "Please, Enter your position: " << endl;
            cin >> pos;
            insertPosition(p, pos);
            Display(head);
            break;
        }
        case 4:
            deleteNodeEnd();
            Display(head);
            break;
        case 5:
            deleteNodeAtPosition(1);
            Display(head);
            break;
        case 6:
        {
            cout << "Enter the position to delete: " << endl;
            int pos;
            cin >> pos;
            deleteNodeAtPosition(pos);
            Display(head);
            break;
        }
        case 7:
        {
            struct node *hello = reverse(head);
            Display(hello);
            break;
        }
        case 8:
        {
            struct node *hello = deleteDuplicates(head);
            Display(hello);
            break;
        }
        case 99:
            t = 99;
            break;
        default:
            break;
        }
    }
    return 0;
}