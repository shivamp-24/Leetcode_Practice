class Solution {
public:
    int maximumBeauty(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int l=0, r=0;
        int ans=0;
        while(r<n){
            if((arr[r]-arr[l])<=2*k){
                ans=max(ans, r-l+1);
                r++;
            }
            else l++;
        }
        return ans;
    }
};