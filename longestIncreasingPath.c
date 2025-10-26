#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int dfs(int** matrix, int m, int n, int x, int y, int** memo) {
    if (memo[x][y] != 0) return memo[x][y];
    int max = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dirs[d][0], ny = y + dirs[d][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
            max = MAX(max, 1 + dfs(matrix, m, n, nx, ny, memo));
        }
    }
    memo[x][y] = max;
    return max;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0], res = 0;
    int** memo = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        memo[i] = calloc(n, sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res = MAX(res, dfs(matrix, m, n, i, j, memo));
        }
    }
    for (int i = 0; i < m; i++) free(memo[i]);
    free(memo);
    return res;
}
