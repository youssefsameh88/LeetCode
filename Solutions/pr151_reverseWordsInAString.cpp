#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
vector <string> v;
    string reverseWords(string s) {
        string answer ="";
        string a = "";
        int l = 0;
        int h = 0;
        int k = s.length() -1;

        while( l <= k){
            if(s[l] == ' '){
                l++;
                h++;
                continue;
            }
            else{
                while(s[h] != ' ' && h <= k)
                    h++;
                    
                
                a = s.substr(l,h-l) ;
                v.push_back(a);
                a = "";
                l = h;
                if(l == k)
                break;
            }

        }
        for(int j = v.size() -1 ; j >= 0;j--){
            answer += v[j] +' ';
        }
         answer.pop_back();
        return answer;
        
    }
};