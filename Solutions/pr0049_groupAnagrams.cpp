#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <vector<string>> ans;
        if(strs.size() == 1){
            ans.push_back(strs);
            return ans;
        } 
        unordered_map <string,int> map;
        int i = 0;
        for(string s : strs){
            string temp = sortString(s);
            if(map.find(temp) != map.end()){
                    ans[map[temp]].push_back(s);
            }
            else{
                ans.push_back({s});
                map[temp] = i;
                i++;
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    string sortString(string s){
     sort(s.begin() , s.end());
        return s;
    }
};
int main(){
    Solution k;
    string h ="hello";
    k.sortString(h);
    cout << k.sortString(h);

}