#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>     
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
    T,null_type,less<T>,rb_tree_tag,
    tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int id = 0, count = 0;
        ordered_set<pair<long long,int>> s;
        for(int i = 0; i < nums.size(); i++){
            count += s.size() - s.order_of_key({(long long)nums[i]*2+1,-1});
            s.insert({nums[i],id++});
        }
        return count;
    }
};