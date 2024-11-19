class Solution {
public:
    bool isZeroArray(vector<int>& arr, vector<vector<int>>& que) {
        int n=arr.size();
        vector<int> pre(n,0);
        for(auto &it: que){
            int l=it[0], r=it[1];
            if(l>=0) pre[l]--;
            if(r+1<n) pre[r+1]++;
        }
        for(int i=1;i<n;i++) {
            pre[i]+=pre[i-1];
            if(pre[i]+arr[i]>0) return false;
        }
        return true;
    }
};