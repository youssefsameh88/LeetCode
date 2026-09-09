#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    std::less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        ordered_set<pair<int,int>> t;
        int idx = 0;
        for(int num : nums) {
            t.insert({num,idx++});
        }
        int ans = 0;
        for(int num : nums){
            if(t.size()-t.order_of_key({num,INT_MAX}) >= k) ans++;
        }
        return ans;
    }
};