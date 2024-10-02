class Solution {
public:

    void dfs(int u, vector<vector<int>> &adj, vector<int> &vis){
        vis[u]=1;
        for(auto &v: adj[u]){
            if(!vis[v]) dfs(v, adj, vis);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int x=stones[i][0], y=stones[i][1];
            for(int j=i+1;j<n;j++){
                int x1=stones[j][0], y1=stones[j][1];
                if(x==x1 || y==y1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cc=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                cc++;
            }
        }
        return n-cc;
    }
};