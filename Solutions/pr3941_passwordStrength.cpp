#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        int score = 0;
        unordered_set<char> seen;
        for(char c : password){
            if(seen.count(c)) continue;

            if(islower(c)) score++;
            else if(isupper(c)) score += 2;
            else if(isdigit(c)) score += 3;
            else score += 5;
            seen.insert(c);
        }
        return score;
    }
};
