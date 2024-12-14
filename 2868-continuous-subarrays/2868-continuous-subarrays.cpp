class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=0;
        multiset<int> st;
        long long ans=0;
        int maxi=0, mini=1e9;
        while(r<n){
            st.insert(nums[r]);
            maxi=max(maxi, nums[r]);
            mini=min(mini, nums[r]);
            r++;
            while((maxi-mini)>2){
                st.erase(st.find(nums[l]));
                l++;
                maxi=*(--st.end());
                mini=*st.begin();
            }
            ans+=(r-l);
        }
        return ans;
    }
};