
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0 || (head && head->next == nullptr))
            return head;
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *current = dummyHead;
        ListNode *rotateHeadPrev = dummyHead;
        int i = 0;
        for (i = k; i > 0; i--)
        {
            if (current->next == nullptr)
            {
                int size = k - i;
                i = k % size;
                current = dummyHead;
                break;
            }
            else
                current = current->next;
        }
        if (current->next == nullptr)
        {
            delete dummyHead;
            return head;
        }
        for (; i > 0; i--)
            current = current->next;
        while (current->next != nullptr)
        {
            rotateHeadPrev = rotateHeadPrev->next;
            current = current->next;
        }
        current->next = head;
        dummyHead->next = rotateHeadPrev->next;
        rotateHeadPrev->next = nullptr;

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
