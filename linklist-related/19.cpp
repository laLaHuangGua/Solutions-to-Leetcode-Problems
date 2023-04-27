#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Exceed Time Limit
// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         std::vector<ListNode *> nodes{};

//         ListNode *current = head;
//         while (current != nullptr)
//             nodes.push_back(current);

//         ListNode *deleteNode{};
//         if (nodes.size() == n)
//         {
//             deleteNode = head;
//             head = head->next;
//         }
//         else
//         {
//             ListNode *targetNodePrev = nodes[nodes.size() - n - 1];
//             deleteNode = targetNodePrev->next;
//             targetNodePrev->next = targetNodePrev->next->next;
//         }

//         delete deleteNode;
//         return head;
//     }
// };

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *delPrev = dummyHead;
        ListNode *current = dummyHead;

        n++;
        while (n-- > 0)
            current = current->next;
        while (current != nullptr)
        {
            delPrev = delPrev->next;
            current = current->next;
        }
        ListNode *del = delPrev->next;
        delPrev->next = delPrev->next->next;
        head = dummyHead->next;

        delete del;
        delete dummyHead;
        return head;
    }
};