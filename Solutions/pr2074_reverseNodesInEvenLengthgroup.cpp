#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(!head || !head->next) return head;
        vector<ListNode*> v;
        ListNode* curr = head;
        int size = 0;
        int idx = 1;
        while(curr){
            size++;
            curr = curr->next;
        }
        curr =new ListNode(0,head);
        int numOfgroups = ceil((sqrt(1 + 8*size) - 1) / 2); 
        int groupHead = 1, toAdd = 0;
        for(int i = 1; i <= size ; i++){
            ListNode* temp = curr;
            curr = curr->next;
            if(i == groupHead){
                v.push_back(curr);
                groupHead += toAdd + 1;
                toAdd++;
            temp->next = nullptr;
            }
        }
        curr = v.back();
         size = 0;
        while(curr){
            size++;
            curr = curr->next;
        }
        for(int i = 1; i < v.size(); i+=2) v[i] = reverse(v[i]);
           ListNode* dummy = new ListNode(0);
           curr = dummy;
        for(int i = 0 ; i < v.size()-1; i++){
            curr->next = v[i];
            while(curr->next) curr = curr->next;
        }
        if(size%2 ^ v.size()%2) curr->next = reverse(v.back());
        else curr->next = v.back();
        return dummy->next;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

ListNode* convertToLinkedList(vector<int>& v){
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int i = 0;
    while(i < v.size()){
        curr->next = new ListNode(v[i++]);
        curr = curr->next;
    }
    return dummy->next;
}
int main(){
    Solution s;
    vector<int> v = {5,2,6,3,9,1,7,3,8,4};
    ListNode* head = convertToLinkedList(v);
ListNode* answer = s.reverseEvenLengthGroups(head);
while(answer){
    cout << answer->val << " ";
    answer = answer->next;
}
}