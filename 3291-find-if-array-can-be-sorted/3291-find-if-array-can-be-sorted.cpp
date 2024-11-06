class Solution {
public:
    bool canSortArray(vector<int>& arr) {
        int maxi=0;
        int i=0;
        int n=arr.size();
        while(i<n){
            int mini=arr[i], mx=arr[i];
            int bits=0;
            for(int j=8;j>=0;j--) if(arr[i]&(1<<j)) bits++;
            int tp=bits;
            while(i<n && tp==bits){
                mini=min(mini, arr[i]);
                mx=max(mx, arr[i]);
                i++;
                if(i>=n) break;
                tp=0;
                for(int j=8;j>=0;j--) if(arr[i]&(1<<j)) tp++;
            }
            if(mini<maxi) return false;
            maxi=mx;
        }
        return true;
    }
};