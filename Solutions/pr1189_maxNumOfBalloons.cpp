#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(5);
        for(int i = 0; i < text.size(); i++){
            if(text[i] == 'b') v[0]++;
            else if(text[i] == 'a') v[1]++;
            else if(text[i] == 'l') v[2]++;
            else if(text[i] == 'o') v[3]++;
            else if(text[i] == 'n') v[4]++;
        }
        return min({v[0], v[1], v[2]/2, v[3]/2, v[4]});
    }
};