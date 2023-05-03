#include <stack>

using std::stack;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Remove Node Instead of Copying Value
// class Solution
// {
// public:
//     ListNode *reverseBetween(ListNode *head, int left, int right)
//     {
//         if (head->next == nullptr || left == right)
//             return head;

//         ListNode *dummmyHead = new ListNode(0, head);
//         ListNode *pre = dummmyHead;
//         for (int i = 0; i < left - 1; i++)
//             pre = pre->next;

//         ListNode *current = pre->next;
//         for (int i = 0; i < right - left; i++)
//         {
//             ListNode *next = current->next;
//             current->next = next->next;
//             next->next = pre->next;
//             pre->next = next;
//         }

//         head = dummmyHead->next;
//         delete dummmyHead;
//         return head;
//     }
// };

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head->next == nullptr || left == right)
            return head;

        ListNode *leftNode = head;
        ListNode *rightNode = head;
        for (int gap = right - left; gap > 0; gap--)
            rightNode = rightNode->next;
        for (int dist = left - 1; dist > 0; dist--)
        {
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }

        stack<int> s;
        ListNode *p = leftNode;
        while (p != rightNode->next)
        {
            s.push(p->val);
            p = p->next;
        }
        while (leftNode != rightNode->next)
        {
            leftNode->val = s.top();
            s.pop();
            leftNode = leftNode->next;
        }
        return head;
    }
};
