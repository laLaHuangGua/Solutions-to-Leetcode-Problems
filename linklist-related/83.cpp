
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
        ListNode *dummyHead = new ListNode(-101, head);
        ListNode *current = dummyHead;

        while (current->next != nullptr)
        {
            while (current->val == current->next->val)
            {
                ListNode *deleteNode = current->next;
                current->next = current->next->next;
                delete deleteNode;
                if (current->next == nullptr)
                    break;
            }
            if (current->next == nullptr)
                break;
            current = current->next;
        }
        head = dummyHead->next;

        delete dummyHead;
        return head;
    }
};