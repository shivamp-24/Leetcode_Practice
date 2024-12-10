class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        int ans=0;
        for(char ch='a'; ch<='z'; ch++){
            priority_queue<int> pq;
            int i=0, cnt=0;
            while(i<n){
                if(s[i]==ch){
                    cnt++;
                }
                else{
                    if(cnt>0){
                        pq.push(cnt);
                    }
                    cnt=0;
                }
                i++;
            }
            if(cnt>0) pq.push(cnt);
            if(pq.size()==0) continue;
            if(pq.size()==1){
                ans=max(ans, pq.top()-2);
            }
            else if(pq.size()==2){
                int maxi=pq.top();
                pq.pop();
                int s_maxi=pq.top();
                if(maxi==s_maxi || maxi==(s_maxi+1)) ans=max(ans, maxi-1);
                else{
                    ans=max(ans, maxi-2);
                }
            }
            else{
                int maxi=pq.top();
                pq.pop();
                int s_maxi=pq.top();
                pq.pop();
                int t_maxi=pq.top();
                if(maxi==s_maxi && s_maxi==t_maxi) ans=max(ans, maxi);
                else if(maxi==s_maxi || maxi==(s_maxi+1)) ans=max(ans, maxi-1);
                else ans=max(ans, maxi-2);
            }
        }
        if(ans==0) return -1;
        return ans;
    }
};