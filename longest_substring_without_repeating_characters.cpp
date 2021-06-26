/*
 
*/

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n == 0)
        return n;
    set<char> c;
    int ans = 0, left = 0, right = 0, len = 0;
    while (right < n)
    {
        if (c.find(s[right]) == c.end())
        {
            c.insert(s[right]);
            right++;
            len = right - left;
            ans = max(len, ans);
        }
        else
        {
            c.erase(s[left]);
            left++;
        }
        ans = max(len, ans);
        // for (int i = left; i < right; i++)
        //     cout << s[i];
        // cout << endl;
    }

    return ans;
    }
