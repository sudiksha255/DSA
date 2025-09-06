class TrieNode{
    public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        endOfWord=false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
        
    }
    
    void insert(string word) {
        TrieNode*curr=root;
        for(char c:word){
            int i=c-'a';
            if(curr->children[i]==nullptr){
                curr->children[i]=new TrieNode();
            }
            curr=curr->children[i];
        }
        curr->endOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char c:word){
            int i=c-'a';
            if(curr->children[i]==nullptr){
                return false;
            }
            curr=curr->children[i];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char c:prefix){
            int i=c-'a';
            if(curr->children[i]==nullptr){
                return false;
            }
            curr=curr->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */