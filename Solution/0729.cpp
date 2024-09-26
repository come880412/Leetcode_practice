class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& [memStart, memEnd] : memory_) {
            if (start < memEnd && end > memStart) return false;
        }
        memory_.emplace_back(make_pair(start, end));
        return true;
    }

private:
    vector<pair<int, int>> memory_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */