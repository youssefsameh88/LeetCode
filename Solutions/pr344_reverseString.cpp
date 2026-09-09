#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector <char> reverseString(vector<char>& s) {
        int i = 0 , j = s.size() - 1;
        while(i < j){
            j = s.size() - i - 1;
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i++] ^= s[j--];
        }
        return s;
    }
};
int main(){
    Solution s;
    vector <char> c = {'h' , 'e' ,'l','l','o'};
    vector <char> v = s.reverseString(c);
    for(char c : v) cout << c << " ";


}