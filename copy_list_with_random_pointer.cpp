#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    map<Node *, Node *> m;
    int i = 0;
    Node *ptr = head;
    while (ptr)
    {
        m[ptr] = new Node(ptr->val);
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr)
    {
        m[ptr]->next = m[ptr->next];
        m[ptr]->random = m[ptr->random];
        ptr = ptr->next;
    }
    return m[head];
}

int main()
{
}