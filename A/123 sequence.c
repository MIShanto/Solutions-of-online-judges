#include<stdio.h>

int main()
{
    int n,a,i,c1=0,c2=0,c3=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){

        scanf("%d",&a);
        if(a==1){

            c1++;

        }
        else if(a==2){

            c2++;

        }
        else if(a==3){

            c3++;

        }

    }
   // printf("%d %d %d\n",c1,c2,c3);
    if(c1>=c2 && c1>=c3){
        printf("%d\n",n-c1);
    }
    else if(c2>=c1 && c2>=c3){
        printf("%d\n",n-c2);
    }
    else{
        printf("%d\n",n-c3);
    }
    return 0;
}
