struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* ptr = list1;
        for(int i = 0; i <= b+1 ; i++){
            if(i == a-1) curr1 = ptr;
            else if(i==b +1) curr2 = ptr;
            ptr=ptr->next;
        }
        curr1->next = list2;
        while(curr1->next) curr1 = curr1->next;
        curr1->next = curr2;
        return list1;
    }
};