#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 0;
        vector<int> arr(n,1);
        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                arr[i] = arr[i-1] + 1;
            }
        }
        for(int i = n-2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                arr[i] = max(arr[i+1] + 1, arr[i]);
            }
        }
        for(int i : arr) sum+=i;
        return sum;
    }
};


int main(){
Solution s;
               //0  1  2  3  4  5  6  7  8  9  10   11  12
vector<int> a = {4,5,6, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 1, 0}; //47
vector<int> b = {0,1,0,1,0,1,0,1}; // 12
vector<int> c = {1, 3 ,4 ,5,2};//11
vector<int> d = {1,2,3,4,5,6,7}; //5
cout<< s.candy(a) << "\n"<< s.candy(b) << "\n"<< s.candy(c) << "\n"<< s.candy(d) << "\n";

}