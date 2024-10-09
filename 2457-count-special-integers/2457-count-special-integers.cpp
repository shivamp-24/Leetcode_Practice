class Solution {
public:
    int dp[10][2][2][1<<10];

    int func(string &str, int i, int started, int limit, int mask){
        if(i==str.size()){
            if(started) return 1;
            return 0;
        }
        int hp=limit==1 ? str[i]-'0' : 9;
        int ansHere=0;
        for(int x=0;x<=hp;x++){
            int newstarted = started==1 ? 1 : (x>0 ? 1 : 0);
            int newlimit = limit==0 ? 0 : (x==str[i]-'0' ? 1 : 0);
            if(started==1){
                if(!(mask&(1<<x))){
                    ansHere+=func(str, i+1, newstarted, newlimit, mask|(1<<x));
                }
            }
            else{
                if(x==0) ansHere+=func(str, i+1, newstarted, newlimit, mask);
                else ansHere+=func(str, i+1, newstarted, newlimit, mask|(1<<x));
            }
        }
        return dp[i][started][limit][mask]=ansHere;
    }

    int countSpecialNumbers(int n) {
        string str=to_string(n);
        memset(dp,-1, sizeof(dp));
        return func(str, 0, 0, 1, 0);
    }
};