class Solution {
public:
    const int mod=1e9+7;

    int sumOfGoodSubsequences(vector<int>& arr) {
        int n=arr.size();
        map<int,int> cnt, sum;
        for(auto i: arr){
            cnt[i]+=(cnt[i-1]+cnt[i+1]+1)%mod;
            cnt[i]%=mod;
            sum[i]+=(sum[i-1]+sum[i+1])%mod;
            sum[i]%=mod;
            sum[i]+=((1ll*(cnt[i-1]+cnt[i+1]+1)%mod) * i)%mod;
            sum[i]%=mod;
        }
        int ans=0;
        for(auto &it: sum){
            ans+=it.second;
            ans%=mod;
        }
        return ans;
    }
};