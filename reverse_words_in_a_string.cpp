string reverseWords(string s) {
        string ans = "";
        vector<string> f;
        // int flag = 1
        for(auto x : s)
        {
            ans += x;
            if(x == ' ')
            {
                if(ans != " ")
                    f.push_back(ans.substr(0,ans.size()-1));
                ans = "";
            }
        }
        f.push_back(ans);
        ans = "";
        // reverse(f.begin(), f.end());
        for(int i = f.size() - 1; i >= 0; i--)
        {
            if(f[i].size() == 0)
                continue;
            ans += f[i] + " ";
        }
            // cout << x << " " << x.size() << endl;
        ans = ans.substr(0, ans.size() - 1);
        return ans;
    }
