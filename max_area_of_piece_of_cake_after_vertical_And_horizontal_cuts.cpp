/*
You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts.
Since the answer can be a large number, return this modulo 109 + 7.
*/

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        vector<int> hor(horizontalCuts.size()+1, 0), ver(verticalCuts.size()+1, 0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int n = horizontalCuts.size();
        for(int i = 0; i < n ; i++)
        {
            if(i == 0)
                hor[i] = horizontalCuts[i];
            else
                hor[i] = horizontalCuts[i] - horizontalCuts[i-1];
        }
        hor[n] = h - horizontalCuts[n-1];
        n = verticalCuts.size();
        for(int i = 0; i < n ; i++)
        {
            if(i == 0)
                ver[i] = verticalCuts[i];
            else
                ver[i] = verticalCuts[i] - verticalCuts[i-1];
        }
        ver[n] = w - verticalCuts[n-1];
        
        
        long long mod = 1e9 + 7;
        int f =*max_element(ver.begin(), ver.end()); 
        int g = *max_element(hor.begin(), hor.end());
        int sum = ((f % mod) * (g % mod)) % mod;
        return sum;
    }
