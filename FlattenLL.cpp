class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr)
        {
            return head;
        }
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->child != nullptr) {  //agr child exist krta hai tohh...
                Node* aglaNode = curr->next; //curr ke agle waale node ko store kr lege.....kyu mujhe phle curr ke child ko add krn ah 
                curr->next = flatten(curr->child); //rest list ka kaam recursion kr dega
                curr->next->prev = curr; //DLL hai toh jo recursion return krega uske prev me curr add krna padega
                curr->child = nullptr; //flat bnane ke baad child ko null krna padega

                while (curr->next != nullptr) {  //curr ka child add krne ke baad mujhe tail prr jana hai...kuki jo maine node store kiya tha curr ke aage kaa use add krna h
                    curr = curr->next;
                }

                //tail pr pahucne ke baad check krege ki jo curr ke aage ke node exist krta haii...
                if (aglaNode != nullptr) {
                    curr->next = aglaNode;   //krta hai toh tail ke next me agla node add kr dege 
                    aglaNode->prev = curr; //DLL hai toh agle node ke prev me curr add krna padega
                }
            }
            curr = curr->next;
        }
        return head;
    }
