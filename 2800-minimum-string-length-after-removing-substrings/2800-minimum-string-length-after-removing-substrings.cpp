class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        while(true){
            string tp;
            for(int i=0;i<s.size();){
                if(s[i]=='A' && s[i+1]=='B') i+=2;
                else if(s[i]=='C' && s[i+1]=='D') i+=2;
                else{
                    tp.push_back(s[i++]);
                }
            }
            if(tp.size()==s.size()) return s.size();
            s=tp;
        }
        return s.size();
    }
};