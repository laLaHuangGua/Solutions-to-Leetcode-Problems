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

class Solution
{
public:
    static ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *current = head;
        stack<int> s;
        while (current != nullptr)
        {
            s.push(current->val);
            current = current->next;
        }
        current = head;
        while (!s.empty())
        {
            current->val = s.top();
            current = current->next;
            s.pop();
        }
        return head;
    }
};