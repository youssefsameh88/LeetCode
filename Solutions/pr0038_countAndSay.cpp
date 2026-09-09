#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        n--;
        while(n){
            string ans = "";
            int i = 1;
            
            while(i <= str.length()){
                int count = 1;
                while(i < str.size() && str[i] == str[i-1]){
                    count++;     
                    i++;
                }
                ans += to_string(count) + str[i-1];
                i++;
            }
            str = ans;
            n--;
        }
        return str;
    }
};

int main(){
    Solution s;
    cout << s.countAndSay(10);
}