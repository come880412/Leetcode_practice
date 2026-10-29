class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        this->history.push_back(homepage);
    }
    
    void visit(string url) {
        ++this->curr;
        if (this->curr == this->history.size())
            this->history.push_back(url);
        else
            this->history[this->curr] = url;

        this->last = this->curr;
    }
    
    string back(int steps) {
        this->curr = max(0, this->curr - steps);
        return this->history[this->curr];
    }
    
    string forward(int steps) {
        this->curr = min(this->last, this->curr+steps);
        return this->history[this->curr];
    }
private:
    vector<string> history;
    int curr = 0;
    int last = 0;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */