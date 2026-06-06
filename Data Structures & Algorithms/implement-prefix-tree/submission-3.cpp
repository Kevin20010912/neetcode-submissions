class PrefixTree {
    struct TrieNode{
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    TrieNode* head = new TrieNode();
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        TrieNode* cur = head;
        for(char c : word){
            int idx = c - 'a';
            if(cur->children[idx] == nullptr){
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = head;
        for(char c : word){
            int idx = c - 'a';
            if(cur->children[idx] == nullptr){
                return false;
            }
            cur = cur->children[idx];
        }
        
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = head;
        for(char c : prefix){
            int idx = c - 'a';
            if(cur->children[idx] == nullptr){
                return false;
            }
            cur = cur->children[idx];
        }
        
        return true;
    }
};
