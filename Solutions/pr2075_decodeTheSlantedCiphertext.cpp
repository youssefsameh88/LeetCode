#include <iostream>
using namespace std;
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText == "" || rows == 1) return encodedText;
        int cols = encodedText.size() / rows;
        string ans = "";
        for(int i = 0; i < cols ; i++){
            for(int j = 0; j < rows ; j++){
                int x = i+j*(cols+1);
                if(x >= encodedText.size())break;
                ans += encodedText[x]; 
            }
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};

int main(){
    Solution s;
    string h = "iveo    eed   l te   olc";
    cout << s.decodeCiphertext(h,4);
}