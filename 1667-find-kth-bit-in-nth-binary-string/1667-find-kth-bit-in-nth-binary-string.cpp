class Solution {
public:

    string inv(string &s){
        string tp;
        for(auto &it: s){
            if(it=='1') tp.push_back('0');
            else tp.push_back('1');
        }
        reverse(tp.begin(), tp.end());
        return tp;
    }

    char findKthBit(int n, int k) {
        string s="0";
        if(k==1) return '0';
        for(int j=2;j<=n;j++){
            string tp=inv(s);
            s=s+'1'+tp;
            int len=s.size();
            if(k<=len) return s[k-1];
        }
        return s[k-1];
    }
};