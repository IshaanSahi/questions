/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};
class LRUCache {
public:
        unordered_map<int,Node*>mpp;
        int cap;
        Node* head,*tail;
    LRUCache(int capacity) {
        cap=capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        
        head->next = tail;
        tail->prev = head;
    }
    void insertathead(Node* node){
        Node* curr=head->next;
        head->next=node;
        node->next=curr;
        node->prev=head;
        curr->prev = node;
    }

    void deletenode(Node* node){
        Node* prev=node->prev;
        Node* next=node->next;
        prev->next=next;
        next->prev=prev;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())
            return -1;
        Node* node=mpp[key];
        deletenode(node);
        insertathead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deletenode(node);
            insertathead(node);
        }
        else {
            if(mpp.size()==cap){
                Node* node=tail->prev;
                deletenode(node);
                mpp.erase(node->key);
                delete node;
            }
            Node* node=new Node(key,value);
            mpp[key]=node;
            insertathead(node);
        }
    }
};
