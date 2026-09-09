#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1(nums1.begin(),nums1.end()), n2(nums2.begin(),nums2.end());
        for(int num : n1){
            if(n2.count(num)) return num;
        }
        return min(*n1.begin(),*n2.begin())*10 + max(*n1.begin(),*n2.begin());

    }
};