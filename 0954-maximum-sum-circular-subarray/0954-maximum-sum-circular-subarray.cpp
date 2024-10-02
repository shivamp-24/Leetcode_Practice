class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //2 cases
        //normal kadane
        //kadane to find minimum subarray sum
        int maxi=nums[0], mini=nums[0];
        int sum1=0, sum2=0, sum=0;
        for(auto &it: nums){
            //normal
            if(sum1<0) sum1=0;
            sum1+=it;
            maxi=max(maxi, sum1);
            //mini
            if(sum2>0) sum2=0;
            sum2+=it;
            mini=min(mini, sum2);
            sum+=it;
        }
        if(sum==mini) return maxi;
        return max(maxi, sum-mini);
    }
};