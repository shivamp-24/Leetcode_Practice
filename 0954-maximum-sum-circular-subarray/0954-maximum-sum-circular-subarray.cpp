class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //2 cases
        //normal kadane
        //kadane to find minimum subarray sum
        int maxi=INT_MIN, mini=INT_MAX;
        int sum1=0, sum2=0, sum=0;
        for(auto &it: nums){
            //normal
            sum1+=it;
            maxi=max(maxi, sum1);
            if(sum1<0) sum1=0;
            //mini
            sum2+=it;
            mini=min(mini, sum2);
            if(sum2>0) sum2=0;
            sum+=it;
        }
        if(sum==mini) return maxi;
        return max(maxi, sum-mini);
    }
};