#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> v;
        for(int& num : nums) freq[num]++;
        for(auto& [a,b] : freq) v.push_back(a);
 
        sort(v.begin(), v.end(),[&](int a , int b){
            return freq[a] > freq[b];
        });
        v.resize(k);
        return v;
    }
};
