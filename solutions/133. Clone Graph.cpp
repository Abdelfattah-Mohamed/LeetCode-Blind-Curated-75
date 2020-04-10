/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
​
class Solution {
public:
    unordered_map<int, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        queue<Node*> que;
        que.push(node);
        Node* x = new Node(node->val);
        mp[x->val] = x;
        while(!que.empty()) {
            Node* temp = que.front();
            que.pop();
            vector<Node*> vec = temp->neighbors;
            for(Node* n : vec) {
                if(!mp.count(n->val)) {
                    Node* y = new Node(n->val);
                    mp[y->val] = y;
                    que.push(n);
                }
                mp[temp->val]->neighbors.push_back(mp[n->val]);
            }
        }
        return x;
    }
};
​
​
/*
​
    Time Complexity  => O(n)
    Space Complexity => O(n)
​
*/
