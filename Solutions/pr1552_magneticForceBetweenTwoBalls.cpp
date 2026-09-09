#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = *max_element(position.begin(), position.end()), ans = 0;
        while(l <= r){
            int mid = (l + r)/2;
            if(ok(mid, m, position)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
    bool ok(int mid,int m, vector<int>& pos){
        m--;
        int j = 0;
        for(int i = 1; i < pos.size(); i++){
            if(pos[i] - pos[j] >= mid){
                j = i;
                m--;
            }
            if(!m) break;
        }
        return !m;
    }
};