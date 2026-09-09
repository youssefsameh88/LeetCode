#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findTheWinner(int n, int k){
        vector<bool> v(n, true);
        int T = n;
        int count = 1, i = 0;
        while (T > 1){

            if (v[i % n]){
                if (count == k){
                    v[i % n] = false;
                    T--;
                    count = 0;
                }
                count++;
            }
            i++;
        }
        for (int i = 0; i < v.size(); i++)
            if (v[i])
                return i + 1;

        return -1;
    }
};

int main(){
    Solution s;
    cout << s.findTheWinner(500,100000);
}