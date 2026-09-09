#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> p = {2,3,5};
        priority_queue<long, vector<long>,greater<long>> pq;
        unordered_set<long> set;
        pq.push(1);
        set.insert(1);

        long x;
        for(int i = 0; i < n; i++){
            x = pq.top();
            pq.pop();
            for(int num : p){
                long y = x * num;
                if(!set.count(y)){
                    pq.push(y);
                    set.insert(y);
                }
            }
        }
        return (int) x;
    }
};