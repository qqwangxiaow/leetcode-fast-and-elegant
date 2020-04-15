//priority_queue to keep less time tweetId
//friends to keep friend 
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter():time(0){
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(time++,tweetId));

    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int>ret;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int n=tweets[userId].size()-1;
        for(int i=n;i>=0&&i>n-10;i--)
        {
            q.push(tweets[userId][i]);
            if(q.size()>10)
                q.pop();
        }
        for(auto person:friends[userId])
        {
            int n=tweets[person].size()-1;
            for(int i=n;i>=0&&i>n-10;--i)
            {
                q.push(tweets[person][i]);
                if(q.size()>10)
                    q.pop();
            }
            
        }
        while(!q.empty())
        {
            ret.push_back(q.top().second);
            q.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;


    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        {
            friends[followerId].insert(followeeId);
        }

    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(friends[followerId].find(followeeId)!=friends[followerId].end())
        {
            friends[followerId].erase(followeeId);
        }
    }
private:
    int time;
    unordered_map<int,unordered_set<int>>friends;
    unordered_map<int,vector<pair<int,int>>>tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */