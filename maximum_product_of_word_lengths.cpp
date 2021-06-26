/*
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. 
If no such two words exist, return 0.
*/


int maxProduct(vector<string>& words) {
        int x = 0;
        vector<int> asd;
        auto bie = [&](const string a, string b){return (a.size() > b.size());};
        sort(words.begin(), words.end(), bie);
        
        for(int i = 0; i < words.size(); i++)
        {
            int largest_flag = 0;
            // cout << "new word: " << words[i] << endl; 
            for(int j = i + 1; j < words.size(); j++)
            {
                // cout << "new test: " << words[j] << endl; 
                int count = 0;
                for(int k = 0; k < words[j].size(); k++)
                {
                    // cout << words[j][k] << endl;
                    if(words[i].find(words[j][k]) != string::npos)
                    {
                        count++;
                        largest_flag = 1;
                        break;
                    }
                }
                if(largest_flag == 0 || count == 0)
                {
                    // cout << "done\n";
                    x = words[i].size() * words[j].size();
                    asd.push_back(x);
                    break;
                }
            }
        }
        if(asd.size() != 0)
        {
            sort(asd.begin(), asd.end(), greater<int>());
            x = asd[0];
        }
        
        return x;
    }
