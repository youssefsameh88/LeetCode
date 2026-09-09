#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set <int> set(friends.begin(), friends.end());
        vector <int> ans;
        for(int i = 0 ; i < order.size();i++)
            if(set.find(order[i]) != set.end()) ans.push_back(order[i]);

        return ans;
        
    }
};