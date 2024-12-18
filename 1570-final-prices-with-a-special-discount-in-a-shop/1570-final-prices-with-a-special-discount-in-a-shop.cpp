class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=arr[i];
            else{
                ans[i]=arr[i]-st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};