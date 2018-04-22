class MyCalendar {
public:
    vector<pair<int,int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto iter=events.begin();
        for(;iter!=events.end();iter++)
        {
            if(iter->first>=start) break;
        }
        if(iter!=events.begin())
        {
            auto iter2=iter-1;
            if(iter2->second>start) return false;
        }
        if(iter!=events.end() && iter->first<end) return false;
        events.insert(iter,pair<int,int>(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */