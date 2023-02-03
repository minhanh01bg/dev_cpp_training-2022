#include<cstdio>
#include<cstring>

using namespace std;
#define MAXC 85
#define MAXR 32
#define MAX 109

char maze[MAXR][MAXC];

struct  dt{int a, b;
} stars[MAX];

int row, col;

void dfs(int i, int j);

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, k, len;
    int test, maxstar;
    scanf("%d", &test);
    getchar();
    while(test--)
    {
        col = row = 0;
        memset(maze, 0, sizeof(maze));
        for(i = 0; 1; i++)
        {
            gets(maze[i]);
            if(maze[i][0] == '_')
                break;
            len = strlen(maze[i]);
            if(len > col)
                col = len;
        }
        row = i;
        for(i = 0, k = 0; i < row ; i++)
            for(j = 0;j < col; j++)
        {
            if(maze[i][j] == '*')
            {
                maze[i][j] = ' ';
                stars[k].a = i;
                stars[k++].b = j;
            }
        }
        maxstar = k;
        for(i = 0; i < k; i++)
            dfs(stars[i].a, stars[i].b);
        for(i = 0; i <= row; i++)
            puts(maze[i]);
    }
    return 0;
}

void dfs(int i, int j)
{
    if(maze[i][j] != ' ')
        return;
    maze[i][j] = '#';
    if(i > 0)
        dfs(i-1, j);
    if(i + 1 < row)
        dfs(i+1, j);
    if(j > 0)
        dfs(i,j-1);
    if(j+1 < col)
        dfs(i,j+1);
    return;
}



