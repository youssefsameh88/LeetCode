#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        for(char c : s) map[c]++;
        
        int count = 0 ;
        bool single = false;
        for(auto [a,b] : map){
            if(b%2 == 0) count += b; 
            else {
                count += (b-1);
                single = true;
            }
        }
        return count + single;
    }
};
