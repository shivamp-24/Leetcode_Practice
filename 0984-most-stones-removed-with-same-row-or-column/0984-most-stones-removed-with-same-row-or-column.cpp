class DisjointSet {
    public:
    vector<int> parent,size,rank;
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++) parent[i]=i;
        }
        
        int findUPar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUPar(parent[node]);
        }
        
        void unionByRank(int u, int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_u]=ulp_v;
                rank[ulp_v]++;
            }
        }
        
        void unionBySize(int u, int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        unordered_map<int,vector<int>> mx,my;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            int x=stones[i][0],y=stones[i][1];
            if(mx[x].size()){
                ds.unionByRank(i,mx[x][0]);
            }
            if(my[y].size()){
                ds.unionByRank(i,my[y][0]);
            }
            mx[x].push_back(i);
            my[y].push_back(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) ans++;
        }
        return n-ans;
    }
};