#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
class MedianFinder {
public:
    int idx = 0;
    ordered_set<pair<double,int>> t;
    MedianFinder() {

    }
    
    void addNum(int num) {
        t.insert({num,idx++});
    }
    
    double findMedian() {
        if(t.empty()) return 0;
        int mid = t.size()/2;
        double m1 = t.find_by_order(mid)->first;
        if(t.size()%2) return m1;
        else return (m1 + (--t.find_by_order(mid))->first) / 2;
    }
};