/*
You are given an m x n binary matrix grid. 
An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/

int maxAreaOfIsland(vector<vector<int>>& grid) {
        set<int, greater<int>> s;
        int hor_size = grid[0].size();
        int ver_size = grid.size();
        // cout << grid.size() << " " << grid[0].size();
        
        vector<pair<int,int>> d4 {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        
        auto inside = [&](pair<int,int> pt){
            // auto [x,y] = pt;
            int x = pt.first;
            int y = pt.second;
            return x >= 0 and y >= 0 and x < ver_size and y < hor_size;
        };
        
        auto dfs = [&](int i, int j){
            queue<pair<int,int>> q;
            grid[i][j] = 0;
            q.push({i,j});
            int sz = 0;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx, dy] : d4){
                    int xx = x + dx;
                    int yy = y + dy;
                    if(inside({xx,yy}) && grid[xx][yy] == 1)
                    {
                        grid[xx][yy] = 0;
                        q.push({xx,yy});
                        sz++;
                    }
                }
            }
            return sz;
        };
        
        
//         for(int i = 0; i < ver_size; i++)
//         {
//             for(int j = 0; j < hor_size; j++)
//             {
         
//                 cout << grid[i][j] << " ";
//             }
//             cout << endl;
//         }
        
        for(int i = 0; i < ver_size; i++)
            for(int j = 0; j < hor_size; j++)
                if(grid[i][j] == 1)
                    s.insert(dfs(i,j));
            
        if(s.size() == 0)
            return 0;
        // sort(s.begin(), s.end(), greater<int>());
        auto it = s.begin();
        return (*it+1);
    }
