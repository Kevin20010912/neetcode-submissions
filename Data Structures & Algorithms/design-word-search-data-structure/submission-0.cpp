class WordDictionary {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    TrieNode* head;
public:
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = head;
        for(char c : word){
            int idx = c - 'a';
            if(cur->children[idx] == nullptr){
                cur->children[idx] = new TrieNode;
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, head);
    }
    bool dfs(string word, int index, TrieNode* node){
        if(node == nullptr){
            return false;
        }

        if(word.size() == index){
            return node->isEnd;
        }
        
        char c = word[index];

        if(word[index] != '.'){
            int idx = c - 'a';
            return dfs(word, index + 1, node->children[idx]);
        }

        for(int i = 0; i < 26; i++){
            if(node->children[i] == nullptr){
                continue;
            }
            if(dfs(word, index + 1, node->children[i])){
                return true;
            }
            
        }
        return false;
    }
};
