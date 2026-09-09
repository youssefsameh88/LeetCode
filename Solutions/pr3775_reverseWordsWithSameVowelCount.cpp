#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        if(s == "") return s;
        while(i < s.length() && s[i] != ' ')
            i++;
            if(i == s.length()) return s;

        int v1Num = vowelCount(s.substr(0,i));
        int vNum = 0;

        int l = i+1, r = i+1 ;
        int end = s.length();

        while(l < end){
            i = r;
            while(i < end && s[i] != ' ' ) i++ ;
            r = i;
            string sub = s.substr(l , r-l);
            vNum = vowelCount(sub);

            if(vNum == v1Num){
                int length = r-l ;
                 for(int i = l ; i < l + (length/2) ; i++){
            s[i] ^= s[l+length-1-(i-l)];
            s[l+length-1-(i-l)] ^= s[i];
            s[i] ^= s[l+length-1-(i-l)];
                }
            }
            
            r++;
            l = r;
        }

            return s;
    }

    int vowelCount(string s){
        int count = 0;
        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
        }
        return count;
    }
    
};

int main(){
    Solution s;
    cout << s.reverseWords("banana healthy");

}