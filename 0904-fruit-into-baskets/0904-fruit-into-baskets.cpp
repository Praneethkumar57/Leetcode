class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int first=0,second=0;
        int ele1=fruits[0];
        while(second<fruits.size() && fruits[first]==fruits[second]){
            second = second+1;
        }
        if(second == fruits.size()){
            return second;
        }
        int ele2 = fruits[second];
        int maxi = 2;
        for(int i=0; i<fruits.size(); i++){
            if(fruits[i]!=ele1 && fruits[i]!=ele2){
                for(int j=i-1;j>=first;j--){
                    if(fruits[j]!=fruits[j-1]){
                        first=j;
                        break;
                    }
                }
                second = i;
                ele1 = fruits[first];
                ele2 = fruits[second];
                maxi = max(maxi,(second-first));
            } else {
                maxi = max(maxi, (i - first + 1));
            }
        }
        return maxi;
    
    }
};