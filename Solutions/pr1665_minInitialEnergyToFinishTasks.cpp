#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b){
            return a[1] - a[0] > b[1] - b[0];
        });
        int sum = 0;
        for(int i = 0; i < tasks.size(); i++){
            sum += tasks[i][0];
        }
        int l = sum, r = 2e9, ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(tasks,mid)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }

    bool check(vector<vector<int>>& tasks, int energy){

        for(int i = 0; i < tasks.size(); i++){
            if(energy < tasks[i][1]) return false;
            else{
                if(energy < tasks[i][0]) return false;
                energy -= tasks[i][0];
            }
        }
        return true;
    }
};
