#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        vector <int> v;
        sort(arr.begin(), arr.end());
        if(arr[0] > 2) return "";

        for (int i = arr.size() - 1; i >= 0 ; i--){
            if(arr[i] <= 2) {
                if(i == 1 && arr[1] == 2 && arr[2] > 5) continue;
                v.push_back(arr[i]);
                arr.erase(arr.begin() + i);
                break;
            }
        }
        if(v.size() == 0) return "";
        
        for (int i = arr.size() - 1; i >= 0 ; i--){
            if(v[0] == 2) {
                if(arr[i] <= 3){
                    v.push_back(arr[i]);
                    arr.erase(arr.begin() + i);
                    break;
                }
               
            }
            else{
                     v.push_back(arr[i]);
                    arr.erase(arr.begin() + i);
                    break;
                
            }
        }
        if(v.size() == 1) return "";
        if(arr[1] > 5 && arr[0] > 5) return "";
        
        if(arr[1] > 5) {
            v.push_back(arr[0]);
            arr.erase(arr.begin());
        }
        else{
            v.push_back(arr[1]);
            arr.erase(arr.begin() + 1) ;          
        } 

        string  ans = to_string(v[0]) + to_string(v[1]) + ":" + to_string(v[2]) + to_string(arr[0]);
        return ans; 
  
    }
};

int main(){
Solution s;
vector v ={2,3,9,5};
cout << s.largestTimeFromDigits(v);

}
