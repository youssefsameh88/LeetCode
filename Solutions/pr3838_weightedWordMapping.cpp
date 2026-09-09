#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s = "";
        for(int i = 0; i < words.size(); i++){
            int num = 0;
            for(int j = 0; j < words[i].size(); j++)
                num += weights[words[i][j]-'a'];
            
            s += ('a' + 25-(num%26));
        }
        return s;
    }
};
