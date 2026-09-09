#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> set(word.begin(), word.end());
        int count = 0;
        for(auto& c : set)
            if(set.count(c+32) || set.count(c-32))
                count++;
        return count/2;
    }
};
