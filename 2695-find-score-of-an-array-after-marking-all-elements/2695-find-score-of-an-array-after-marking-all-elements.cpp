class Solution {
public:
    long long findScore(vector<int>& arr) {
        set<pair<int,int>> st;
        int n=arr.size();
        for(int i=0;i<n;i++) st.insert({arr[i],i});
        long long ans=0;
        while(st.size()>0){
            auto it=st.begin();
            int x=it->first, ind=it->second;
            ans+=x;
            st.erase(it);
            if(ind>0){
                if(st.find({arr[ind-1],ind-1})!=st.end()) st.erase({arr[ind-1],ind-1});
            }
            if(ind<n-1){
                if(st.find({arr[ind+1],ind+1})!=st.end()) st.erase({arr[ind+1],ind+1});
            }
        }
        return ans;
    }
};