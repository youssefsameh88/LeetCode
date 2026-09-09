#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k == 0){
            for(int& num : code) num = 0;
            return code;
        }
        int n = code.size();
        vector<int> ans;
        int sum = 0;
        if(k > 0){
            for(int i = 1; i <= k; i++)
                sum += code[i];
                ans.push_back(sum);
            for(int i = (k+1)%n ; ans.size() < code.size() ; i = (i+1)%n){
                sum = sum - code[(i-k+n)%n] + code[i];
                ans.push_back(sum);
            }
        }
       else{
            for(int i = n+k; i < n; i++){
                sum += code[i];
            }
                ans.push_back(sum);
            for(int i = 0 ; ans.size() < code.size() ; i++){
                sum = sum - code[(i+k+n)%n] + code[(i+n)%n];
                ans.push_back(sum);
            }
        }
        return ans;
    }
};