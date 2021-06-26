/*
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. 
You may return the answer in any order.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
*/


vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, int> umap;
        vector<string> f;
        vector<int> x;
        
        for(int i = 0; i < pattern.length(); i++){
            if(umap.find(pattern[i]) != umap.end())
                x.push_back(umap[pattern[i]]);
            else{
                umap[pattern[i]] = i;
                x.push_back(i);
            }
        }
        
        int umap_size = umap.size();
        
        for(auto word: words)
        {
            int flag = 0;
            unordered_set<char> s;
            for(int i = 0; i < word.size(); i++)
            {
                s.insert(word[i]);
                if(word[i] != word[x[i]])
                {
                    flag = 1;
                    break;                    
                }
            }
            if(flag == 0 && umap_size == s.size())
                f.push_back(word);
        }
        
        return f;
    }
