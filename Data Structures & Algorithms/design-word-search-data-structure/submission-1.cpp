class WordDictionary {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    TrieNode* head;
    bool flag = false;
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
        flag = false;
        dfs(word, 0, head);
        return flag;
    }
    void dfs(string word, int index, TrieNode* node){
        if(flag){
            return ;
        }
        
        if(node == nullptr){
            return ;
        }

        if(word.size() == index){
            if(node->isEnd){
                flag = true;
                return ;
            }
            return;
        }
        
        char c = word[index];

        if(word[index] != '.'){
            int idx = c - 'a';
            dfs(word, index + 1, node->children[idx]);
            return;
        }

        for(int i = 0; i < 26; i++){
            if(node->children[i] == nullptr){
                continue;
            }
            dfs(word, index + 1, node->children[i]);
        }
    }
};
