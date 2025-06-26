int fibonaci(int n){
    if(n<=1) return n;
    return fibonaci(n-1)+fibonaci(n-2);
}

class Solution {
public:
    int fib(int n) {
        int val;
        val = fibonaci(n);
        return val;
    }
};