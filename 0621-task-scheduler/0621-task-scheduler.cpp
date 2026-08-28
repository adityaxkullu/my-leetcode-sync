class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for(char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> pq;

        for(auto x : freq) {
            pq.push({x.second});
        }

        int time = 0;
        
        while(!pq.empty()) {
            vector<int> used;

            for(int i = 0; i <= n; i++) {
               if(!pq.empty()) {
                int f = pq.top();
                pq.pop();

                f--;

                if(f > 0) {
                    used.push_back(f);
                }

                time++;

               }else {
                if(used.empty()) break;
                
                time++;
               }
            }

            for(int f : used) {
                pq.push(f);
            }

        }

        return time;    
    }
};