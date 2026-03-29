class EventManager {
public:
    set<pair<int, int>> pq;
    unordered_map<int,int> priority_map;
    
    EventManager(vector<vector<int>>& events) {
        for (auto event: events) {
            int id = event[0];
            int priority = event[1];
            pq.insert({-priority, id});
            priority_map[id] = priority;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int old_priority = priority_map[eventId];
        pq.erase({-old_priority, eventId});
        pq.insert({-newPriority, eventId});
        priority_map[eventId] = newPriority;
    }
    
    int pollHighest() {
        if (pq.empty()) {
            return -1;
        }

        auto iter = pq.begin();
        int id = iter->second;
        pq.erase(iter);
        priority_map.erase(id);
        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
