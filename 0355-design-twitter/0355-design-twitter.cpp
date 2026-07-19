class node{
    public:
    int tweetId;
    int time;
    node* next;
    node(int id,int t){
        tweetId=id;
        time=t;
        next=nullptr;
    }
};

class Twitter {
public:
    int timer;
    unordered_map<int,set<int>>followmap;
    unordered_map<int,node*>tweetmap;
    struct cmp{
        bool operator()(node* a,node* b){
            return a->time < b->time;
        }
    };
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        node* newTweet= new node(tweetId,++timer);
        newTweet->next=tweetmap[userId];
        tweetmap[userId]=newTweet;
    }
    
    vector<int> getNewsFeed(int userId) {
        int count=0;
        vector<int>result;
        priority_queue<node*,vector<node*>,cmp>pq;
        followmap[userId].insert(userId);
        for(int followerId:followmap[userId]){
            if(tweetmap.count(followerId))
                pq.push(tweetmap[followerId]);
        }
        while(!pq.empty()&&count!=10){
            node* nd=pq.top();
            result.push_back(nd->tweetId);
            pq.pop();
            count++;
            if(nd->next)
                pq.push(nd->next);
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        followmap[followerId].erase(followeeId);
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