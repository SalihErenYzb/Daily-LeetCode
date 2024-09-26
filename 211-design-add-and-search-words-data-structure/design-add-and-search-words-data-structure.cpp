class WordDictionary {
public:
    bool isWord = false;
    WordDictionary* next[26] = {nullptr};

    WordDictionary() {
        
    }
    
    void addWord(string word, int i = 0) {
        if (word.size() == i){
            isWord = true;
            return;
        }
        if (!next[word[i]-'a'])
            next[word[i]-'a'] = new WordDictionary();
        next[word[i]-'a']->addWord(word,i+1);
    }
    
    bool search(string word, int i = 0) {
        if (word.size() == i){
            return isWord;
        }
        if (word[i] == '.'){
            for (auto possible: next){
                if (possible && possible->search(word,i+1)){
                    return true;
                }
            }
            return false;
        }
        if (!next[word[i]-'a']){
            return false;
        }
        return next[word[i]-'a']->search(word,i+1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */