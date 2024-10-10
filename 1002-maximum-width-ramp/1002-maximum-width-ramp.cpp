class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> ind(n);
        for(int i=0;i<n;i++) ind[i]=i;
        sort(ind.begin(), ind.end(),[&](int i, int j){
            if(nums[i]!=nums[j]) return nums[i]<nums[j];
            return i<j;
        });
        int mini=ind[0];
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans, ind[i]-mini);
            mini=min(mini, ind[i]);
        }
        return ans;
    }
};