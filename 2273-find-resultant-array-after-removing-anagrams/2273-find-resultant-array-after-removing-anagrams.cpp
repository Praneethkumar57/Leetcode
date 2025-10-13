bool isAnagram(string& s1,string& s2){
    vector<int> arr1(26,0);
    vector<int> arr2(26,0);
    int n=s1.size();
    int m=s2.size();
    for(int i=0;i<n;i++){
        arr1[s1[i]-'a'] += 1;
    }
    for(int i=0;i<m;i++){
        arr2[s2[i]-'a'] += 1;
    }

    for(int i=0;i<26;i++){
        if(arr1[i]!=arr2[i]){
            return 0;
        }
    }
    return 1;
}

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        int n=words.size();
        for(int i=1;i<n;i++){
            if(isAnagram(words[i-1],words[i])==0){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};