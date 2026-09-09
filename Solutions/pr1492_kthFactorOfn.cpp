#include <iostream>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        int i , counter = 1;
        if(k == 1) return 1;
        if(n%2){
            i = 3; 
            while (i <= n/3){
                if(n%i == 0) 
                    counter++;
                if(counter == k) return i;
                i += 2;
            }
            if(counter + 1 == k) return n;

        }
        else{
            i = 2;
            while(i <= n/2){
                if(n%i == 0) 
                    counter++;
                if(counter == k) return i;
                i++;
            }
            if(counter + 1 == k) return n;


        }
        return -1;

    }
};

int main(){
    Solution s;
    cout << s.kthFactor(479001600,792);

}