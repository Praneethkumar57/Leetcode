bool check(long long val, int n){
    if(val==n){
        return true;
    }
    else if(val > n){
        return false;
    }
    return check(3*val,n);
}

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        else if(n==1){
            return true;
        }
        long long val = 3;
        return check(val,n);
    }
};