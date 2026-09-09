#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int idx = 0, total = 0, mod = 1e9 + 7;
        ordered_set<pair<int,int>> t;
        t.insert({instructions[0], idx++});
        for(int i = 1 ; i < instructions.size(); i++){
            int x = t.order_of_key({instructions[i],-1});
            int y = t.order_of_key({instructions[i],INT_MAX});
            int cost = min(x, (int)t.size()-y);
            total = (total%mod + cost) % mod;
            t.insert({instructions[i], idx++});
        }
        return total;
    }
};
