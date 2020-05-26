class Trie {
private:
    class TrieNode {
        private:
            map<char, TrieNode*> mp;
            bool last;
        
        public:
            TrieNode() {last = false; }
            bool isLast() {return last; }
            void setLast(bool x) {last = x; }
            TrieNode* child(char c) {return mp[c];} 
            void ins(char c, TrieNode* ch) {mp[c] = ch; }
    };
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            if(curr->child(c) != NULL) curr = curr->child(c);
            else {
                TrieNode* ch = new TrieNode();
                curr->ins(c, ch);
                curr = ch;
            }
        }
        curr->setLast(true);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            if(curr->child(c) == NULL) return false;
            curr = curr->child(c);
        }
        return curr->isLast();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix) {
            if(curr->child(c) == NULL) return false;
            curr = curr->child(c);
        }
        return true;
    }
};
​
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
