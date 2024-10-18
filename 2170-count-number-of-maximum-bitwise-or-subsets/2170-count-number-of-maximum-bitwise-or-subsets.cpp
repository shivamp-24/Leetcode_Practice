class Solution {
public:
    int maxi=0;
    map<int,int> mp;

    void func(int i, vector<int> &nums, int val){
        if(i==nums.size()){
            if(val>maxi) maxi=val;
            mp[val]++;
            return;
        }
        func(i+1, nums, val);
        func(i+1, nums, val|nums[i]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        func(0, nums, 0);
        return mp[maxi];
    }
};