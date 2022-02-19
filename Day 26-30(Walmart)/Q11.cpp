#define mod 1000000007
    static bool compare(pair<int,int>& p1, pair<int,int>& p2) {
        if(p1.first>p2.first)return true;//decreasing order
        return false;
    }

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

        priority_queue<int, vector<int>, greater<int>> heap;//min heap of size k for speeds
        vector<pair<int,int>> worker;

        for(int i = 0; i < n; i++)
            worker.push_back({efficiency[i],speed[i]});

        sort(worker.begin(), worker.end(),compare);//decresing order of efficiency,reason for taking decreasing order explained down

        long res = 0;
        long total = 0;
        long minE;
        for (int i = 0; i < k; i++) {
            minE = worker[i].first;
            total += worker[i].second;
            res = max(res, total*minE);//since we have at most k engineers so we cal res for 1 to k engineers
            heap.push(worker[i].second);
        }

        for (int i = k; i < n; i++) {
            //if speed of curr worker is less than speed top then no need to update res
            //since efficiencies are in decreasing order so efficiency of this worker ie minE is less than
            //efficiency of k workers already in heap and speed is also less,so total will dec if add this speed to
            //heap and remove the top of heap,so minE*total will surely be less than res

            if (worker[i].second > heap.top())//heap top will have min speed out of k speeds
            {
                total += (-heap.top()+worker[i].second);
                minE = worker[i].first;
                res = max(res, total*minE);
                heap.pop();
                heap.push(worker[i].second);
            }
        }
        return (int)(res%mod);
    }
