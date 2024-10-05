class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        unordered_map<char,int> mp1;
        for(auto &it: s1) mp1[it]++;
        unordered_map<char,int> mp2;
        int len=0;
        for(int i=0;i<m;i++){
            if(mp1.find(s2[i])==mp1.end()){
                mp2.clear();
                len=0;
            }
            else{
                mp2[s2[i]]++;
                if(mp2[s2[i]]<=mp1[s2[i]]){
                    len++;
                    if(len==n) return true;
                }
                else{
                    while(mp2[s2[i]]>mp1[s2[i]]){
                        mp2[s2[i-len]]--;
                        len--;
                    }
                    len++;
                }
            }
            cout<<len<<" ";
        }
        return false;
    }
};