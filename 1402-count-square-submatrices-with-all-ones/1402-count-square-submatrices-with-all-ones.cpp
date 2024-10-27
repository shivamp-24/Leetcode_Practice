class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n=arr.size(), m=arr[0].size();
        int ans=0;
        vector<vector<int>> pre(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up=(i>=1) ? pre[i-1][j] : 0;
                int left=(j>=1) ? pre[i][j-1] : 0;
                int diag=(i>=1 && j>=1) ? pre[i-1][j-1] : 0;
                pre[i][j]=up+left+arr[i][j]-diag;
            }
        }
        int tp=min(n,m);
        for(int len=1;len<=tp;len++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int up=i-len+1, left=j-len+1;
                    int tot=pre[i][j];
                    if(up>=1) tot-=pre[up-1][j];
                    if(left>=1) tot-=pre[i][left-1];
                    if(up>=1 && left>=1) tot+=pre[up-1][left-1];
                    if(tot==(len*len)) ans++;
                }
            }
        }
        return ans;
    }
};