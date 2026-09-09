class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int end = total/cost1;
        long long ans = 0;
        for(int i = 0; i <= end ; i++)
            ans += (total - i*cost1)/cost2;
        
        ans += end + 1;
        return ans;
    }
};
