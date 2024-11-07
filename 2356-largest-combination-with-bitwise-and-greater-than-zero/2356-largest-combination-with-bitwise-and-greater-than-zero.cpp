class Solution {
public:
    int largestCombination(vector<int>& arr) {
        vector<int> hsh(30,0);
        for(auto &it: arr){
            for(int i=29;i>=0;i--){
                if(it&(1<<i)) hsh[i]++;
            }
        }
        int maxi=0;
        for(int i=0;i<30;i++) maxi=max(maxi, hsh[i]);
        return maxi;
    }
};