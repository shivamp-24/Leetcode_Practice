class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUP(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUP(parent[u]);
    }
    void Union(int u, int v){
        int uu=findUP(u);
        int uv=findUP(v);
        if(uu==uv) return;
        if(size[uu]<size[uv]){
            parent[uu]=uv;
            size[uv]+=size[uu];
        }
        else{
            parent[uv]=uu;
            size[uu]+=size[uv];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& eq) {
        DisjointSet ds(26);
        for(auto &it: eq){
            if(it[1]=='='){
                ds.Union(it[0]-'a', it[3]-'a');
            }
        }
        for(auto &it: eq){
            if(it[1]=='!'){
                int p1=ds.findUP(it[0]-'a');
                int p2=ds.findUP(it[3]-'a');
                if(p1==p2) return false;
            }
        }
        return true;
    }
};