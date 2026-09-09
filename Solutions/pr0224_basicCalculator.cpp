#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        string s1 = "";
        for (int i = 0; i < s.size(); i++){
            if(s[i] != ' ') s1.push_back(s[i]);
        }
        int x = s1.rfind('(');
        while(x != -1){
            int i = x;
            while(s1[i] !=')') i++;
            s1.replace(x,i-x+1,to_string(calcInside(s1.substr(x,i-x+1))));
            x = s1.rfind('(');
        }
        string s2 = "(" + s1 + ")";
        return calcInside(s2);
    }
    int calcInside(string s){
        if(s.size() < 3) return 0;
        int i = 1, sum = 0;
        int sign = 1;
        if(s[i] != '+' && s[i] != '-') sign = 1;
        while(i < s.size() - 1){
            string a = "";
             if(s[i] == '+' || s[i] == '-'){
                int countM = 0;
                while(s[i] == '+' || s[i] == '-'){
                    if(s[i] == '-') countM++;
                    i++;
                }
                sign = (countM%2) ? -1 : 1; 
            }
            else{ 
                while(i < s.size()-1 && (s[i] != '+' && s[i] != '-')) a += s[i++];
                if(a != "") sum += stol(a) * sign;
            }
        }
        return sum;
    }
};

int main(){
Solution s;
string p = "1 + 3 + 4 + 5 ++++ 5";
cout << s.calculate(p);
}