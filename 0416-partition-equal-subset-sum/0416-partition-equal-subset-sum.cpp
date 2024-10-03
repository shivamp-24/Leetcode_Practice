class Solution {
public:
    bool func(int i, int t, vector<int> &nums, vector<vector<int>> &dp){
        if(t<0) return false;
        if(t==0) return true;
        if(i==nums.size()){
            return false;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        return dp[i][t]=(func(i+1, t-nums[i], nums, dp) || func(i+1, t, nums, dp));
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &it: nums) sum+=it;
        if(sum&1) return false;
        vector<vector<int>> dp(nums.size(), vector<int>((sum/2)+1,-1));
        return func(0, sum/2, nums, dp);
    }
};