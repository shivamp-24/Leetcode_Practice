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
    int makeConnected(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int ex=0;
        for(auto &it: edge){
            int u=it[0], v=it[1];
            if(ds.findUPar(u)==ds.findUPar(v)) ex++;
            else ds.unionBySize(u, v);
        }
        int cc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cc++;
        }
        int req=cc-1;
        if(ex>=req) return req;
        return -1;
    }
};