class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in(n,0);
        for(auto &it: edges){
            in[it[1]]++;
        }
        int cnt=0, ans;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                cnt++;
                ans=i;
            }
        }
        if(cnt==0 || cnt>1) return -1;
        return ans;
    }
};