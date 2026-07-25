class TimeMap {
public:
    map<string,vector<pair<int,string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end())return "";
        vector<pair<int,string>>& a = mpp[key];
        int low=0, high=a.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(a[mid].first==timestamp)return a[mid].second;
            else if(a[mid].first<timestamp)low=mid+1;
            else high=mid-1;
        }
        if(high==-1)return "";
        return a[high].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */