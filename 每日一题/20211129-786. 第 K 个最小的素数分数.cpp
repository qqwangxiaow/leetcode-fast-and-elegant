//sort
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>>myvec;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                myvec.push_back({arr[i], arr[j]});
            }
        }
        sort(myvec.begin(), myvec.end(), [](const auto &p1, const auto &p2) {
            return p1.first * p2.second < p2.first * p1.second;
        });
        return {myvec[k - 1].first, myvec[k - 1].second};
    }
};