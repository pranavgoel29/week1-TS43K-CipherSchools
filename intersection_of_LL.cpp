
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// node* swap(node *head, int x, int y)
// {
//     //   Nothing to do if x and y are same
//     if (x == y)
//         return head;

//     // Search for x (keep track of prevX and CurrX
//     node *prevX = NULL, *currX = head;
//     while (currX && currX->data != x) {
//         prevX = currX;
//         currX = currX->next;
//     }

//     // Search for y (keep track of prevY and CurrY
//     node *prevY = NULL, *currY = head;
//     while (currY && currY->data != y) {
//         prevY = currY;
//         currY = currY->next;
//     }

//     // If either x or y is not present, nothing to do
//     if (currX == NULL || currY == NULL)
//         return head;

//     // If x is not head of linked list
//     if (prevX != NULL)
//         prevX->next = currY;
//     else // Else make y as new head
//         head = currY;

//     // If y is not head of linked list
//     if (prevY != NULL)
//         prevY->next = currX;
//     else // Else make x as new head
//         head = currX;

//     // Swap next pointers
//     node* temp = currY->next;
//     currY->next = currX->next;
//     currX->next = temp;

//     return head;
// }

node *getIntesectionNode(node *head1, node *head2)
{
    while (head2)
    {
        node *temp = head1;
        while (temp)
        {
            // if both Nodes are same
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    // intersection is not present between the lists
    return NULL;
}

void insertathead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}

void printll(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    system("cls");
    node *head = NULL;
    // node *head1 = new node();
    node *head1 = NULL;
    insertathead(head, 4);
    insertathead(head, 3);
    insertathead(head, 2);
    insertathead(head, 1);
    insertathead(head, 0);

    cout << "Linked List 1: \n";
    printll(head);

    insertathead(head1, 4);
    insertathead(head1, 3);
    insertathead(head1, 2);
    insertathead(head1, 3);
    insertathead(head1, 4);
    // head = swap(head, 1, 3);
    cout << "\nLinked List 2: \n";
    printll(head1);
    // cout << "\nAfter Swap: \n";
    // printll(head);

    node *point = getIntesectionNode(head, head1);
    if (!point)
        cout << "\nNo Intersection Point \n";
    else
        cout << "\nIntersection Point: "<< point->data << endl;
}