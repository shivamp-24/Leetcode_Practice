class Solution {
public:
    int minChanges(string str) {
        int n=str.size();
        int ans=0, tp=0;
        int i=0;
        while(i<n){
            char ch=str[i];
            int cnt=0;
            while(i<n && str[i]==ch){
                cnt++;
                i++;
            }
            if((tp+cnt)&1){
                ans++;
                tp=1;
            }
            else tp=0;
        }
        return ans;
    }
};