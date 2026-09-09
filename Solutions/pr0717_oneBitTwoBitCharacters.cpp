#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int count = 0;
        for(int i = bits.size() - 2 ; i >= 0 && bits[i] != 0 ; i--) count++;

        if(count % 2) return false;
        return true;
    }
};

int main(){
    Solution s;
    vector b = {0,0};

    cout << s.isOneBitCharacter(b);
}