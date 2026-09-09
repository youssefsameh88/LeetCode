#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, string> map = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
        {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"},
        {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"},
        {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
        {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"},
        {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}
    };

    string numberToWords(int num) {
        if(!num) return map[num];
        vector<int> v;
        while(num){
            v.push_back(num%1000);
            num /= 1000;
        }
        reverse(v.begin(), v.end());
        string ans = "";
        for(int i = 0; i < v.size(); i++){
            string h = helper1(v[i]);
            string end = h.empty() ? "" : helper2(i,v.size());      
            ans +=  h + end;
        }
        while(ans.back() == ' ')ans.pop_back();
        return ans;

    }
    string helper1(int num){
        if(!num) return "";
        string s = to_string(num), ret = "";
        if(num %100 == 0) return map[s[0]-'0'] + " Hundred";
        if(num < 21 || (num < 101 && num % 10 == 0)) return map[num];

        bool tens;
        if(s.size() > 2){
            tens = map.count(10*(s[1]-'0') + (s[2]-'0'));
            ret += map[(s[0]-'0')] + " Hundred ";
            if(tens) ret += map[10*(s[1]-'0') + (s[2]-'0')];
            else ret += map[10*(s[1]-'0')] + " " + map[s[2]-'0'];
            return ret; 
        } 
        if(s.size() > 1){
            bool tens = map.count(10*(s[0]-'0') + (s[1]-'0'));
            if(tens) return map[10*(s[0]-'0') + (s[1]-'0')];
            return map[10*(s[0]-'0')] + " " + map[s[1]-'0'];

        } 
        return map[s[0] - '0'];
    }
    string helper2(int i, int size){
        int p = size - i - 1;
        if(p) return " " + map[pow(1000,p)] + " ";
        return ""; 
    }
};