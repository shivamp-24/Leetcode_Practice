class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        int i=0;
        map<int,int> mp;
        int n=nums.size();
        long long ans=0;
        while(i<n){
            if(i<k){
                sum+=nums[i];
                mp[nums[i]]++;
            }
            else{
                mp[nums[i-k]]--;
                if(mp[nums[i-k]]==0) mp.erase(nums[i-k]);
                sum-=nums[i-k];
                sum+=nums[i];
                mp[nums[i]]++;
            }
            if(mp.size()==k){
                if(sum>ans) ans=sum;
            }
            i++;
        }  
        return ans;
    }
};