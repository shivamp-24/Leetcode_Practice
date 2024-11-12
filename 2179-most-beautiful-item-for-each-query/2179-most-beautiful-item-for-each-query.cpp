class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& arr, vector<int>& que) {
        vector<int> ans;
        map<int,int> mp;
        for(auto &it: arr){
            int p=it[0], b=it[1];
            mp[p]=max(mp[p], b);
        }
        int maxi=0;
        for(auto &it: mp){
            maxi=max(maxi, it.second);
            mp[it.first]=maxi;
        }
        // for(auto &it: mp) cout<<it.first<<" "<<it.second<<endl;
        for(auto &i: que){
            auto it=mp.upper_bound(i);
            if(it==mp.begin()){
                ans.push_back(0);
                continue;
            }
            it--;
            ans.push_back((*it).second);
        }
        return ans;
    }
};