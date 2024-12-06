class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> vis(10010,0);
        for(auto &it: banned){
            vis[it]++;
        }
        int ans=0, sum=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                if((sum+i)<=maxSum){
                    ans++;
                    sum+=i;
                }
                else return ans;
            }
        }
        return ans;
    }
};