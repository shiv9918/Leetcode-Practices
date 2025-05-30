 ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy = new ListNode(0);
        dummy->next = head;
        ListNode*prev = dummy;
        while(head!=nullptr)
        {
            if(head->next!=nullptr && head->val==head->next->val)
            {
                while(head->next!=nullptr && head->val == head->next->val)
                {
                    head = head->next;
                }

                prev->next = head->next;
            }
            else
            {
                  prev = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
