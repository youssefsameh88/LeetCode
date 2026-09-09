#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        string str = "";
        int counter = 0, ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(map.find(s[i]) == map.end()){
                str += s[i];
                map[s[i]] = i;
            }
            else{
                int pos = str.find(s[i]);
                for(int j = 0; j <= pos ; j++)
                    map.erase(str[j]);
                str.erase(0,pos + 1);
                str += s[i];
                map[s[i]] = i;
            }
            ans = max(ans, (int)str.length());
        }
        return ans;
    }
};

int main(){
    Solution s;

    string str = "fghifkl";
    cout << s.lengthOfLongestSubstring(str);
}