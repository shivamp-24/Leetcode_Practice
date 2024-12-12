class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        long long sum=0;
        priority_queue<int> pq;
        for(auto &it: gifts) {
            sum+=it;
            pq.push(it);
        }
        for(int i=0;i<k;i++){
            int tp=pq.top();
            pq.pop();
            sum-=(tp-sqrt(tp));
            pq.push(sqrt(tp));
        }
        return sum;
    }
};