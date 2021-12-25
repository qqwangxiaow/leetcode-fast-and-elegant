class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0;
        int d = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        while (d < days.size() || !q.empty()) {
            if (d < days.size()) q.push(make_pair(days[d]+d-1, apples[d]));
            auto apple = q.top();
            // 跳过所有已经过期的苹果
            while (apple.first < d) {
                q.pop();
                if (q.size() == 0) break;
                apple = q.top();
            }
            // 如果没有没过期的苹果，继续下一天的等待
            if (q.size() == 0) { d++; continue; }
            // 如果有可以吃的苹果；我们要把这一天过期的苹果数量减1
            if (apple.second > 0) {
                q.pop();
                apple.second--;
                // 如果苹果还有剩余，我们把它放回堆中
                if (apple.second > 0) q.push(apple);
                ans++;
            }
            d++;
        }

        return ans;
    }
};
