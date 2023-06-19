#include <bits/stdc++.h>
using namespace std;


class ListNode {
    public:
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode *mergeTwoList(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    ListNode *tail = new ListNode(0);
    ListNode *ptr = tail;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
    }
    if (list1 != NULL)
        tail->next = list1;
    if (list2 != NULL)
        tail->next = list2;

    return ptr->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
    {
        return NULL;
    }
    if (lists.size() == 1)
    {
        return lists[0];
    }
    ListNode *ans = mergeTwoList(lists[0], lists[1]);
    for (int i = 2; i < lists.size(); i++)
    {
        ans = mergeTwoList(ans, lists[i]);
    }
    return ans;
}

int main()
{
}