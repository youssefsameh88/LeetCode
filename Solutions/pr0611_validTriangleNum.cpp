#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0, n = nums.size(), st = 0, end = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1, r = n - 1, ans = j;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (nums[i] + nums[j] > nums[mid]) {
                        ans = mid;
                        l = mid + 1;
                    } else
                        r = mid - 1;
                }
                count += ans - j;
            }

        }
            return count;
    }
};
