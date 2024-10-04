class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum=0;
        int n=skill.size();
        for(auto &it: skill) sum+=it;
        if(sum%(n/2)!=0) return -1;
        sort(skill.begin(),skill.end());
        int req=sum/(n/2);
        long long ans=0;
        for(int i=0;i<(n/2);i++){
            if(skill[i]+skill[n-i-1]!=req) return -1;
            ans+=(skill[i]*skill[n-i-1]);
        }
        return ans;
    }
};