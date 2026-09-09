struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next) return head;

        head = reverse(head);
        ListNode* curr = head;
        int maxVal = head->val;
        while(curr &&curr->next){
            if(curr->next->val < maxVal){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
                maxVal = curr->val;
            }
        }
        return reverse(head);
    }
     ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};