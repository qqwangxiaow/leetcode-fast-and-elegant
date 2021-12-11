//upper_bound > first positon, lower_bound >= first
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> voteCount;
        int max = -1, index = -1;
        for (auto person : persons) {
            voteCount[person]++;
            if (voteCount[person] >= max) {
                max = voteCount[person];
                index = person;
            }
            this->tops.emplace_back(index);
        }
        this->times = times;
    }
    
    int q(int t) {
        auto index =  upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return tops[index];

    }
private:
    vector<int> times;
    vector<int> tops;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */