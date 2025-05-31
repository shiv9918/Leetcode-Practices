 Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*>
            hashmap; // isko use krege random node search krne ke liye ki wo
                     // kisko point kr rha h
        Node* newHead =
            new Node(head->val); // copy list ke liye nya head banayege
        Node* oldTemp =
            head->next; // puraani list ke next ko point kr rhaa....kyuki phle
                        // node maine uper copy kr liye h
        Node* newTemp = newHead;
        hashmap[head] =
            newHead; // old list ke head ko new head ke address ke sath hash me
                     // store kr dege.....ki pta chalee jo old list ka random
                     // pointer thaa ....uska nya node kaha bna h
        while (oldTemp != nullptr) {
            Node* copyNode = new Node(oldTemp->val); // new list me copy krege
            hashmap[oldTemp] =
                copyNode; // hashmap me old list ke saare node ko new list ke
                          // node ke sath hash me store krege
            newTemp->next = copyNode; // new list me jo new node copy bna rhe
                                      // usko add krte jaayege
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Random pointer assign krne ke liye
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != nullptr) {
            newTemp->random =
                hashmap[oldTemp->random]; // new list ke random pointer ko
                                          // assign krne ke liye hashmao me
                                          // dekhege ki old lis ke node ka
                                          // random pointer kaha assign hua
                                          // thaa....use new list ke node ke
                                          // sath assign kr dege
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
