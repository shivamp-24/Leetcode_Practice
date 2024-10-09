class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int c1=0;
        for(auto &it: s){
            if(it==')') {
                if(c1) c1--;
                else ans++;
            }
            else c1++;
        }
        return ans+c1;
    }
};