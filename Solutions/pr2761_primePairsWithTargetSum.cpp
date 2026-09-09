#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector <int> primes(n + 1 , true);
        primes[0] = primes[1] = 0;
        vector <vector<int>> finalAns;
        vector <int> ans;

        int p = 2 , l = 0 , r = n  , sum = 0;
        bool stop = false;

        while( p * p <= n){
            if(primes[p]){
                for(int i = p*p ; i < n+1 ; i += p ) primes[i] = false;
            }
            p++;   
        }

        while(l <= r){
            while(!primes[l]) {
                l++;
                if (l > r){
                    stop = true;
                    break;
                }
            }
            if(stop) break;
            while(!primes[r]) {
                r--;
                if (r < l){
                    stop = true;
                    break;
                }
            }
            if(stop) break;

            sum = l + r;
            if(sum > n) r--;
            else if (sum < n) l++;
            else{
                ans.push_back(l);
                ans.push_back(r);
                finalAns.push_back(ans);
                ans.clear();
                l++;
                r--;
            }
            
        }
        return finalAns;
     }
};

int main(){
Solution s;
vector < vector <int>> hell = s.findPrimePairs(20);

for (size_t i = 0; i < hell.size(); i++){

    cout << "["<<hell[i][0] << "," << hell[i][1] <<"]"<<endl;
}


}