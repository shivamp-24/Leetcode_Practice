class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse(n),pse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<pse[i]<<" "<<nse[i]<<endl;
            int tp=(nse[i]-pse[i]-1)*arr[i];
            // cout<<tp<<endl;
            ans=max(ans, tp);
        }
        return ans;
    }
};