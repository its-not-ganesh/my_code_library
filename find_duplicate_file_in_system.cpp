/*
Given a list paths of directory info, including the directory path, and all the files with contents in this directory, 
return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.

A group of duplicate files consists of at least two files that have the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". 
Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of groups of duplicate file paths. 
For each group, it contains all the file paths of the files that have the same content.
A file path is a string that has the following format:
"directory_path/file_name.txt"

*/
vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        vector<string> path;
        vector<pair<string, string>> pairs;
        for(auto i: paths){
            auto len = i.find(" ");
            string root = i.substr(0, len);
            string content = i.substr(len+1, i.length());
            while(content.length() != 0){
                auto para_1 = content.find("(");
                auto para_2 = content.find(")");
                string x = content.substr(para_1+1, para_2 - para_1 - 1);
                string dir = content.substr(0, para_1);
                dir = root + "/" + dir;
                pair<string, string> f = make_pair(x, dir);
                pairs.push_back(f);
                if(content[para_2 + 1] == ' ')
                    para_2 += 1;
                content = content.substr(para_2+1, content.length());
            }
        }
        
        sort(pairs.begin(), pairs.end());
        string x = pairs[0].first;
        vector<string> same;
        int count = 0;
        for(auto f : pairs){    
            if(f.first == x)
            {
                count++;
                same.push_back(f.second);
            }
            else{
                x = f.first;
                if(count!=1){
                    ans.push_back(same);
                    count = 1;
                }                
                same.clear();
                same.push_back(f.second);
            }
        }
        if(same.size() > 1)
            ans.push_back(same);
        if(ans.size() == pairs.size())
            return {};
        return ans;
    }
