     #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    int main()
    {
        long i,s=0,k=1,t,n;
        scanf("%ld",&t);
        while(t>0)
        {
            scanf("%ld",&n);
            for(i=1;;i++)
            {
                if(n<pow(5,k))
                break;
                else
                k++;
            }
            for(i=1;i<=k;i++)
            {
                s=s+floor(n/(pow(5,i)));
            }
            printf("%ld\n",s);
            t--;
            k=1;
            s=0;
        }
        return(0);
    }
