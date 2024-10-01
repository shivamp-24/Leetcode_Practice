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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> in(n+1,-1);
        int ans1=-1,ans2=-1;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(in[v]==-1) in[v]=i;
            else{
                ans1=i;
                ans2=in[v];
                break;
            }
        }
        vector<int> ans;
        //first check for ans1 and then ans2
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            if(i==ans1) continue;
            int uu=ds.findUP(edges[i][0]);
            int uv=ds.findUP(edges[i][1]);
            cout<<uu<<" "<<uv<<endl;
            ds.Union(edges[i][0], edges[i][1]);
            if(uu==uv){
                if(ans1==-1)
                    return edges[i];
                else return edges[ans2];
            }
        }
        return edges[ans1];
    }
};