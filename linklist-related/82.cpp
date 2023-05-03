
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *dummyHead = new ListNode(0, head);
        ListNode *current = dummyHead;
        while (current->next && current->next->next)
        {
            if (current->next->val == current->next->next->val)
            {
                int val = current->next->val;
                while (current->next && current->next->val == val)
                {
                    ListNode *del = current->next;
                    current->next = current->next->next;
                    delete del;
                }
            }
            else
                current = current->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};