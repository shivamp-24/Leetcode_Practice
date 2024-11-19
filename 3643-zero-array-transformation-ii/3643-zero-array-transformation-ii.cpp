class Solution {
public:

    bool ok(int mid, vector<int> &arr, vector<vector<int>> &que){
        int n=arr.size();
        vector<int> pre(n,0);
        for(int i=0;i<mid;i++){
            int l=que[i][0], r=que[i][1], val=que[i][2];
            if(l>=0) pre[l]-=val;
            if(r+1<n) pre[r+1]+=val;
        }
        for(int i=0;i<n;i++){
            if(i>0) pre[i]+=pre[i-1];
            if(arr[i]+pre[i]>0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& arr, vector<vector<int>>& que) {
        int low=0, high=que.size(), mid, ans=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(ok(mid, arr, que)){
                ans=mid; 
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};