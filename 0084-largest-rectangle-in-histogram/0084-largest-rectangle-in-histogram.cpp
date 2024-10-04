class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        stack<int> st;
        int ans=0;
        while(i<n){
            if(st.empty() || arr[st.top()]<=arr[i]) st.push(i++);
            else{
                int top=st.top();
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width=(i-st.top()-1);
                int area=arr[top]*width;
                ans=max(ans, area);
            }
        }
        while(!st.empty()){
            int top=st.top();
            st.pop();
            int width;
            if(st.empty()) width=i;
            else width=(i-st.top()-1);
            int area=arr[top]*width;
            ans=max(ans, area);
        }
        return ans;
    }
};