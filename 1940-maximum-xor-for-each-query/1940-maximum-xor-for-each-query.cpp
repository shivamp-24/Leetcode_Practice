class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int tp=(1<<maximumBit)-1;
        int xr=0;
        vector<int> ans;
        for(auto &it: nums){
            xr^=it;
            ans.push_back(tp-xr);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};