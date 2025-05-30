/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    ListNode* midNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        curr->next = (list1 != nullptr) ? list1 : list2;

        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* mid = midNode(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return mergeTwoLists(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*dummyNode = new ListNode(0);
        ListNode*dummy = dummyNode;

        for(auto&list:lists)
        {
             ListNode*temp = list;
             
             while(temp!=nullptr)
             {
                dummy->next = temp;
                temp = temp->next;
                dummy = dummy->next;
             }     
        }
        return sortList(dummyNode->next);
    }
};
