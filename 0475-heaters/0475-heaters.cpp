int mod(int n1, int n2){
    if(n1-n2>=0){
        return(n1-n2);
    }
    return(n2-n1);
}

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = INT_MIN;
        for(int i=0;i<houses.size();i++){
            int mini = INT_MAX;
            for(int j=0; j<heaters.size(); j++){
                mini = min(mini, mod(houses[i], heaters[j]));
            }
            res = max(res, mini);
        }
        return res;
    }
};