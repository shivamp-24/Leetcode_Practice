class Solution {
public:

    const int mod=1e9+7;

    int func(int i, int absent, int late, vector<vector<vector<int>>> &dp, int n){
        if(i==n){
            if(absent==2) return 0;
            return 1;
        }
        if(dp[i][absent][late]!=-1) return dp[i][absent][late];
        int ans=0;
        //'A'
        ans=(ans+func(i+1, min((int)2, absent+1), 0, dp,n))%mod;
        //'L'
        if(late<=1){
            ans=(ans+ func(i+1, absent, late+1, dp,n))%mod;
        }
        //'P'
        ans=(ans+ func(i+1, absent, 0, dp,n))%mod;
        return dp[i][absent][late]=ans;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3,vector<int>(3,-1)));
        //dp[index][absent][late]
        return func(0,0,0,dp,n);
    }
};