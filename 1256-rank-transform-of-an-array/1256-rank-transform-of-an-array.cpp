class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        set<int> st;
        unordered_map<int,int> mp;
        for(auto &it: arr) st.insert(it);
        int i=1;
        for(auto &it: st){
            mp[it]=i;
            i++;
        }
        for(int i=0;i<n;i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};