#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        for(string t : tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int x = s.top(); s.pop();
                int y = s.top();s.pop();
                s.push(eval(y,x,t));
            }
            else s.push(stoi(t));
        }
            return s.top();
    }
    int eval(int a, int b, string op){
        if(op =="+") return a+b;
        if(op =="-") return a-b;
        if(op =="*") return a*b;
        return a/b;
    }
};
