Node *constructHelper(vector<vector<int>> &grid, int len, int x, int y)
    {
        int flag = grid[x][y];
        for (int i = x; i < x + len; i++)
            for (int j = y; j < y + len; j++)
                //if not a leaf, go deeper
                if (flag != grid[i][j])
                {
                    Node *tl = constructHelper(grid, len / 2, x, y);
                    Node *tr = constructHelper(grid, len / 2, x, y + len / 2);
                    Node *bl = constructHelper(grid, len / 2, x + len / 2, y);
                    Node *br = constructHelper(grid, len / 2, x + len / 2, y + len / 2);
                    return new Node(true, false, tl, tr, bl, br);
                }
        return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return (n == 0) ? nullptr : constructHelper(grid, n, 0, 0);
    }
