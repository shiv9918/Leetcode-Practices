 ListNode* swapPairs(ListNode* head) {
        ListNode*dummyNode = new ListNode(0);
        dummyNode->next = head;
       ListNode*prev = dummyNode;
       while(head!=nullptr && head->next!=nullptr)
       {
          ListNode*first = head;
          ListNode*second = head->next;
        
          prev->next = second;
          first->next = second->next;
          second->next = first;

          prev = first;
          head = first->next;
       }
       return dummyNode->next;
    }
