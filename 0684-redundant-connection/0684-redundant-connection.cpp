class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i, size[i]=1;
    }
    int findUP(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUP(parent[node]);
    }
    void Union(int u, int v){
        int uu=findUP(u);
        int uv=findUP(v);
        if(uu==uv) return;
        if(size[uu]<size[uv]){
            parent[uu]=uv;
            size[uv]+=uu;
        }
        else{
            parent[uv]=uu;
            size[uu]+=size[uv];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n=edges.size();
        DisjointSet ds(n);
        for(auto &it: edges){
            int u=it[0], v=it[1];
            if(ds.findUP(u)==ds.findUP(v)){
                ans={u,v};
            }
            else ds.Union(u,v);
        }
        return ans;
    }
};