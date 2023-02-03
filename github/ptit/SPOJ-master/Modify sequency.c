#include <stdio.h>
int main()
{
    int t, n, i, m,left,flag;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        flag=1;
        left = 0;
        for (i=0; i<n; i++)
        {
            scanf("%d", &m);
            if (i==0)
                left=m;
            else
            {
                if (m<left)
                    flag=0;
                else
                    left=(m-left);
            }
        }
        if (flag&&left==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
        return 0;
}
