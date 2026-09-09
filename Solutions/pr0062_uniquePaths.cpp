#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
int uniquePaths(int m, int n) {
        vector<vector<int>> v(m+1 , vector<int>(n+1 , 0));
        return paths(m , n , v);
       
    }
    int paths(int m , int n , vector<vector<int>> &v){
        if( n <= 1 || m <= 1) return 1;
        if(v[m][n]) return v[m][n];

        v[m][n] = paths(m-1 , n , v) + paths(m , n-1 , v);
        return v[m][n];
    }
};

int main(){
    Solution s;
    cout << s.uniquePaths(51,9);
}