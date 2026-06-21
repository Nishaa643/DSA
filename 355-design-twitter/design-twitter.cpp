class Twitter {
public:
    int timer;

    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        for(auto &tweet : tweetMap[userId]) {
            pq.push(tweet);
        }

        for(int followee : followMap[userId]) {
            for(auto &tweet : tweetMap[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */