class OrderedStream {
public:
    unordered_map<int,string> map;
    int ptr = 1;

    OrderedStream(int n) {
        
    }
    
    vector<string> insert(int idKey, string value) {
        if (idKey != ptr) {
            map[idKey] = value;
            return {};
        }

        map[idKey] = value; // not necessary 
        ptr++;

        vector<string> ans;
        ans.push_back(value);

        while (map.contains(ptr)) {
            ans.push_back(map[ptr]);
            ptr++;
        }

        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */