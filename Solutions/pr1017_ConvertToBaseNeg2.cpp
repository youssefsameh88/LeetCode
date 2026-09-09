#include <iostream>
using namespace std;
class Solution {
public:
    string baseNeg2(int n) {
        string ans = "";
        if(n == 0) return "0";
        while(n != 0){
            if(n%(-2) == 0){
                ans += '0' ;
                n/= -2;
            }
            else{
                ans += '1';
                n = (n-1)/-2 ;
            }
            
        }
        int l = ans.length();
        for(int i = 0 ; i < l/2 ; i++){
            ans[i] ^= ans[l-i-1];
            ans[l-i-1] ^= ans[i];
            ans[i] ^= ans[l-i-1];
        }
        return ans;
    }
  
};
int main(){
    Solution s;
    for(int i = 0 ; i < 10000000 ; i++){
        string test = s.baseNeg2(i);
        int p = 1 , m = test.length() -1;
        int answer = 0;
        while(m >=0){
            answer += (test[m]-'0') *p;
            p *= -2;
            m--;
        } 
        cout << i <<" --> "<<test<<" --> "<<answer<< "\n";
    } 
     
}