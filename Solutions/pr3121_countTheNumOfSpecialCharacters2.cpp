#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> freq;
        for(int i = 0; i < word.size(); i++){
            if(word[i] > 96 || freq.find(word[i]) == freq.end())
                freq[word[i]] = i;
        }
        int count = 0;
        for(auto& [a,b] : freq){
            if(!freq.count(a-32)) continue;
            if(b < freq[a-32]) count++;
        }
        return count;
    }
};