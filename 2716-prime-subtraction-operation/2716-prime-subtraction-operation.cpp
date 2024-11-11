class Solution {
public:
    bool isPrime(int x){
        for(int i=3;i*i<=x;i++) if(x%i==0) return false;
        return true;
    }

    bool primeSubOperation(vector<int>& arr) {
        int maxi=0;
        int n=arr.size();
        for(auto &it: arr) maxi=max(maxi, it);
        vector<int> primes;
        if(maxi>=2) primes.push_back(2);
        for(int i=3;i<=maxi+100;i+=2){
            if(isPrime(i)) primes.push_back(i);
        }
        for(auto &it: primes) cout<<it<<" ";
        cout<<endl;
        int last=0;
        for(int i=0;i<n;i++){
            int diff=arr[i]-last;
            if(diff<=0) return false;
            auto it=lower_bound(primes.begin(), primes.end(), diff);
            // if(it==primes.begin()) return false;
            cout<<diff<<" "<<*it<<endl;
            if(it!=primes.begin()) it--;
            int val=*it;
            if(arr[i]-val>last)
                arr[i]-=val;
            last=arr[i];
            cout<<arr[i]<<endl;
        }
        return true;
    }
};