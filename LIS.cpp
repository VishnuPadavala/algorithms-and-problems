#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int prev, vector<int> &nums, vector< vector<int> > &dp) {
        if (i == nums.size()) return 0;
        if (dp[i][prev+1] != -1) return dp[i][prev+1];

        int notTake = solve(i+1, prev, nums, dp);
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i+1, i, nums, dp);
        }

        return dp[i][prev+1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector< vector<int> > dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};

int main() {
    Solution obj;
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18}; // C++98 style
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
    cout << obj.lengthOfLIS(nums); // Output: 4
}

