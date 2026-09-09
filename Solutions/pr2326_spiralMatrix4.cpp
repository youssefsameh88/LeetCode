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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
       vector<vector<int>> v(m,vector<int>(n,-1));
        int  maxRow = m-1, minRow = 0;
        int  maxCol = n-1, minCol = 0;
        int i = 0, j = 0;
        for(ListNode* curr = head ; curr ; curr = curr->next){
                v[i][j] = curr->val;
            if(i == minRow && j < maxCol){
                j++;
                if(j == maxCol)
                    minRow++;
            }
            else if(i < maxRow && j == maxCol){
                i++;
                if(i == maxRow)
                    maxCol--;
            }
            else if(i == maxRow && j > minCol){
                j--;
                if(j == minCol)
                    maxRow--;
            }
            else if(i > minRow && j == minCol){
                i--;
                if(i == minRow)
                    minCol++;
            }
        }
      return v;
    }
};