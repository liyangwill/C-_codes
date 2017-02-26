#include<Interval>

bool myComp(const Interval &a, const Interval &b){
    return (a.start<b.start);
}


// use priority queue stores ending time of existing rooms
// largest int on top(default)

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals){
        int rooms = 0;
        priority_queue<int> pq;
        sort(intervals.begin(), intervals.end(), myComp);
        
        for (int i = 0; i!=intervals.size(); ++i) {
            
            // for a new instance, check the earliest ending in the queue
            while (!pq.empty() && -pq.top()<intervals[i].start) {
                pq.pop();
            }
            pq.push(-intervals[i].end);
            rooms = max(rooms, (int)pq.size());
        }
        return rooms;
    }
}