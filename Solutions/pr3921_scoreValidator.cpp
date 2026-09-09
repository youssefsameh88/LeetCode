#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0, i = 0;
        while(i < events.size() && counter < 10){
            if(events[i] == "WD" || events[i] == "NB") score++;
            else if(events[i] == "W") counter++;
            else score += stoi(events[i]);
            i++;
        }
        return {score, counter};
    }
};