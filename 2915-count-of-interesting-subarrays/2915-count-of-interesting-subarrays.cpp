class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long pre=0,ans=0;
        unordered_map<int,int> mp;
        int n=nums.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k) pre=(pre+1)%modulo;
            ans+=mp[(pre-k+modulo)%modulo];
            mp[pre]++;
        }
        return ans;
    }
};