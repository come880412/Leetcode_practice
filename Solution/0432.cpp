class AllOne {
public:
    AllOne() {
    }
    
    void inc(string key) {
        auto it = m_.find(key);
        if (it == m_.end()) {
            if (l_.empty() || l_.front().val != 1) {
                Data tmp(1, key);
                l_.push_front(tmp);
            } 
            else l_.front().s.insert(key);
            m_[key] = l_.begin();
        }
        else {
            auto currit = it->second;
            auto nextit = next(currit);
            
            if (nextit == l_.end() || nextit->val != currit->val + 1) {
                Data tmp(currit->val + 1, key);
                nextit = l_.insert(nextit, tmp);
            }
            else nextit->s.insert(key);
            m_[key] = nextit;

            currit->s.erase(key);
            if (currit->s.empty()) l_.erase(currit);
        }
    }
    
    void dec(string key) {
        auto it = m_.find(key);
        if (it == m_.end()) return;
        
        auto currit = it->second;
        if (currit->val == 1) m_.erase(key);
        else {
            auto previt = prev(currit);
            if (currit == l_.begin() || currit->val - 1 != previt->val) {
                Data tmp(currit->val - 1, key);
                previt = l_.insert(currit, tmp);
            }
            else previt->s.insert(key);
            m_[key] = previt;
        }
        currit->s.erase(key);
        if (currit->s.empty()) l_.erase(currit);
    }
    
    string getMaxKey() {
        return l_.empty() ? "" : *l_.back().s.begin();
    }
    
    string getMinKey() {
        return l_.empty() ? "" : *l_.front().s.begin();
    }

private:
    struct Data {
        int val;
        unordered_set<string> s;

        Data(int val, string key) : val(val) {
            s.insert(key);
        }
    };

    unordered_map<string, list<Data>::iterator> m_;
    list<Data> l_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */