long long lower_bound(vector<int> &arr, long long low,long long high,long long n){
    long long res=arr.size();
    while(low<=high){
        long long mid = (low + high)/2;
        if(arr[mid]>=n){
            res = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return res;
}

class Solution {
public:
    int hIndex(vector<int>& citations) {

        if(citations.size()==1){
            if(citations[0] == 0){
                return 0;
            }
            else{
                return 1;
            }
        }
        long long low = 0;
        long long high = citations.size();
        long long size = citations.size();

        while(low<=high){
            long long mid = (low + high)/2;
            long long ind = lower_bound(citations,0,citations.size()-1, mid);
            long long res = size - ind;
            if(res >= mid){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return (int)high;
    }
};