#include<stdio.h>
#include<stdlib.h>

int find_divisable(int x)
{
    int after;
    if(x%3==0 || x%3==1){
         after = (x/3)*2;
         //printf("%d\n",after);
    }
    else{
         after = ((x/3)*2)+1;
    }
    //printf("%d\n",after);
    return after;
}

int main()
{
    int a,b,t,i,forB,forA,sub;
    scanf("%d",&t);
    for(i=1; i<=t; i++){
        scanf("%d %d",&a,&b);
         // b=g;
        forB = find_divisable(b);
        forA = find_divisable(a);
            //printf("%d\n",after);
            sub = forB-forA;
            if(a%3==0 || a%3==2){
                printf("Case %d: %d\n",i,sub+1);
                //g++;
            }
            else{
                printf("Case %d: %d\n",i,sub);
       // g++;
            }
        }
    return 0;
}
