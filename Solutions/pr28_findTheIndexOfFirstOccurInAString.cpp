#include <iostream>
#include <string>
using namespace std;

class Solution28 {
public:
    int strStr(string haystack, string needle) {

        if(needle.length() <= haystack.length())
        for(int i = 0; i <= haystack.length() - needle.length() ; i++){
            if(haystack.substr(i,needle.length()) == needle)
            return i;
        }
        return -1;
        
    }
};
int main(){
    Solution28 s;
    cout << s.strStr("aaa" , "aaaa");
    
}