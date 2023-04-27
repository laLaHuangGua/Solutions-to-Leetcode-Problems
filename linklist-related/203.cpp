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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *current = dummyHead;

        while (current->next != nullptr)
        {
            if (current->next->val == val)
            {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
                current = current->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};