#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>     
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<
    T,null_type,less<T>,rb_tree_tag,
    tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size());
        int id = 0;
        ordered_set<pair<int,int>> s;
        for(int i = nums.size()-1; i >= 0; i--){
            counts[i] = s.order_of_key({nums[i], -1});
            s.insert({nums[i],id++});
        }
        return counts;
    }
};
