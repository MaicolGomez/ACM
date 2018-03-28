#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int cases, count;
char tel[10005][11];
int i, j;
 
int cmp(const void *a, const void *b)
{
    return strcmp( (char*)a,(char*)b );
}
 
int main()
{
    scanf("%d",&cases);
    while(cases--)
    {
        bool flag = true;
        scanf("%d",&count);
        for(i = 0; i < count; i++)
            scanf("%s",tel[i]);
        qsort(tel,count,sizeof(char)*11,cmp);
        int len1, len2;
        for(i = 1; i < count; i++)
        {
            len1 = strlen(tel[i-1]);
            len2 = strlen(tel[i]);
            j = 0;
            if(len1 <= len2)
            {
                while(tel[i-1][j] == tel[i][j] && j < len1)
                    j++;
                if(j == len1)
                    flag = false;
            }
            if(!flag)
                break;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}