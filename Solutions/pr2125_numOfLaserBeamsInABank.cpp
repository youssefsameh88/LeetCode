#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, curr = 0, ans = 0;
        for(int i = 0; i < bank.size(); i++){
            curr = 0;
            for(int j = 0; j < bank[0].size(); j++){
                if(bank[i][j] == '1') curr++;
            }
            if(!curr) continue;
            ans += curr * prev;
            prev = curr;
        }
        return ans;
    }
};