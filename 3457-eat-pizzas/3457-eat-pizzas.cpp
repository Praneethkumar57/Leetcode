class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());

        long long ans = 0;
        int n = pizzas.size();
        int o = (n+7)/8;
        int e = n/8;
        int i = n-1;
        while(o--) ans += pizzas[i--];
        while(e--){ ans += pizzas[--i]; i--;}

        return ans;
    }
};