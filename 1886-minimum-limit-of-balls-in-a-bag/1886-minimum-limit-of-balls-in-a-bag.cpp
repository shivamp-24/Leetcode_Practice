class Solution {

    bool ok(int mid, vector<int> &arr, int k){
        int op=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid){
                op+=(arr[i]/mid);
                if(arr[i]%mid==0) op--;
            }
        }
        return op<=k;
    }

public:
    int minimumSize(vector<int>& arr, int k) {
        int n=arr.size();
        int low=1, high=1e9, mid, ans;
        while(low<=high){
            mid=low+(high-low)/2;
            if(ok(mid, arr, k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};