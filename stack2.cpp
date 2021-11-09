void dfs(int p, int q, int k, grid_t& grid, int& cnt, int& total_cnt)
{
    if (q == grid.size()) {
        q = 0;
        ++p;
    }

    for (int i = p; i < grid.size(); ++i) {
        for (int j = q; j < grid[i].size(); ++j) {
            grid[i][j] = true;
            if (is_ok(grid, i, j)) {
                ++cnt;
                if (cnt == k) {
                    ++total_cnt;

                } else {
                    dfs(i, j + 1, k, grid, cnt, total_cnt);
                }
                --cnt;
            }
            grid[i][j] = false;
        }
        q = 0;
    }
}