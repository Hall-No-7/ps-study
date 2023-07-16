#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Trie{
    private:
        int count = 0;
        unordered_map<char,Trie*> children;
    
    public:
        void Insert(string word){
            Trie* now = this;
            for(int i = 0; i < word.length(); i++){
                if(now->children[word[i]] == nullptr){
                    now->children[word[i]] = new Trie;
                }
                
                now = now -> children[word[i]];
                now -> count++;
            }
        }
    
        int AutoComplete(string word){
            int ans = 1;
            
            Trie* now = this->children[word[0]];
            
            for(int i = 1; i < word.length(); i++){
                if(now -> count > 1){
                    ans++;
                }
                now = now -> children[word[i]];
            }
            
            return ans;
        }
};

int solution(vector<string> words) {
    int answer = 0;
    
    Trie tt;
    
    for(string word : words){
        tt.Insert(word); 
    }
    
    for(string word : words){
        answer += tt.AutoComplete(word);
    }
    
    return answer;
}
