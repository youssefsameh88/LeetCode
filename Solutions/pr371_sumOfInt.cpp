#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
private:
    int numOfBits = 11 , signBit = 1;
    int n = numOfBits + signBit;
public:
    int getSum(int a, int b) {
        int power = 1,  sum = 0 ;
         string answer = add(toBin(a) , toBin(b));
        for(int j = 0 ; j < n ; j++){
            sum += (answer[j]-'0') * power;
            power *= 2;
        }
        if(answer[n-1] == '1') sum -= power;
       return  sum;   
    }

    string toBin(int num){
        string s = "";
        bool Negative = num < 0;
        if(Negative) num = -num;
        
        while(num > 0){
        s += to_string(num%2);
        num/=2;
        }
        
       int l = s.length();
        
        for(int j = l ; j < n ; j++){
            s += "0" ;
        }
        if(Negative){
            for(int i = 0 ; i < s.length() ; i++){
                if(s[i] =='0') s[i] = '1';
                else s[i] = '0';
            }
            string one = "100000000000";
            s = add(s , one);

        }
        return s;
    }
    vector <int> fullAdder(int a , int b , int Cin){
        vector <int> ans;
        ans.push_back(a ^ b ^ Cin);
        ans.push_back((a & b) | (a & Cin) | (b & Cin));
        return ans;
    }
    string add(string a , string b){
        string answer = "";
        int Cout = 0;
        vector <int> v;

        for(int i = 0 ; i < n ; i++){
            v = fullAdder(a[i]-'0' , b[i]-'0' , Cout) ;

            answer += to_string(v[0]);
            Cout = v[1];
        }
        
        return answer;
    }
};
int main(){
Solution s;
cout << s.getSum(500,-1000); 
}



/*
*********************THE OPTIMAL SOLUTION**********************
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
*/