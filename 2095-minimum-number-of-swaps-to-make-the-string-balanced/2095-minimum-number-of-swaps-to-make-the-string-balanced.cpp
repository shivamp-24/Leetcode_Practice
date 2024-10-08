class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        for(auto &it: s){
            if(it=='[') ans++;
            else{
                if(ans>0) ans--;
            }
        }
        return (ans+1)/2;
    }
};