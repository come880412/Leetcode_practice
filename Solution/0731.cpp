class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for (const auto& [start_, end_] : overlapped_) {
            if (isOverlap(start, end, start_, end_)) return false;
        }
        cout << endl;

        for (int i = 0; i < sucessfulBooking_.size(); ++i) {
            const auto& [start_, end_] = sucessfulBooking_[i];
            if (isOverlap(start, end, start_, end_)) {
                pair<int, int> overlappedInterval = make_pair(max(start_, start), min(end_, end));
                overlapped_.emplace_back(overlappedInterval);
            }
        }
        sucessfulBooking_.emplace_back(make_pair(start, end));
        return true;
    }
private:
    bool isOverlap(int start, int end, int start_, int end_) {
        return (start < end_ && end > start_);
    }
    vector<pair<int, int>> sucessfulBooking_;
    vector<pair<int, int>> overlapped_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */