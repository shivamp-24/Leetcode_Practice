class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%p;
        }
        if(sum==0) return 0;
        int req=sum;
        //remainder for subarray sum should be req
        sum=0;
        int ans=n;
        mp[0]=-1;
        cout<<req<<endl;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%p;
            int need=(sum-req+p)%p;
            if(mp.find(need)!=mp.end()){
                ans=min(ans, i-mp[need]);
            }
            mp[sum]=i;
            // cout<<ans<<" ";
        }
        return ans==n ? -1 : ans;
    }
};