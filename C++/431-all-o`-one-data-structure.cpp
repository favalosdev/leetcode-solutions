class AllOne {
public:
    unordered_map<string, int> count;
    bool check_max;
    bool check_min;
    string maxKey;
    string minKey;
    
    AllOne()
    {
        count.max_load_factor(0.75);
        check_max = check_min = false;
        maxKey = minKey = "";
    }
    
    void inc(string key)
    {   
        if (count.find(key) != count.end()) {
            count[key] += 1;
        } else {            
            count[key] = 1;
        }
        
        check_max = check_min = true;
    }
    
    void dec(string key)
    {
        count[key] -= 1;
        
        if (count[key] == 0) {
            count.erase(key);
        }
        
        check_max = check_min = true;
    }
    
    string getMaxKey()
    {
        if (check_max) {
            int max = -1;
            string chosen = "";

            for (auto& it : count) {
                if (it.second > max) {
                    max = it.second;
                    chosen = it.first;
                }
            }
            
            maxKey = chosen;
            check_max = false;
        }
        
        return maxKey;
    }
    
    string getMinKey()
    {
        if (check_min) {
            string chosen = "";
            int min = -1;

            for (auto& it : count) {            
                if (it.second < min || min == -1) {
                    min = it.second;
                    chosen = it.first;
                }
            }
            
            minKey = chosen;
            check_min = false;
        }
        
        return minKey;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */