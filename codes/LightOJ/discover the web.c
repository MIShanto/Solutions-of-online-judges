#include<stdio.h>
#include<string.h>

int main()
{
    int v,cV,cB,b,F,cF,i,j,count,t,k,all[100],presence;
    char input[10],vInput[100],site[100][100];
    scanf("%d",&t);
    for(i=1; i<=t; i++){
            site[0][0]='h';
            site[0][1]='t';
            site[0][2]='t';
            site[0][3]='p';
            site[0][4]=':';
            site[0][5]='/';
            site[0][6]='/';
            site[0][7]='w';
            site[0][8]='w';
            site[0][9]='w';
            site[0][10]='.';
            site[0][11]='l';
            site[0][12]='i';
            site[0][13]='g';
            site[0][14]='h';
            site[0][15]='t';
            site[0][16]='o';
            site[0][17]='j';

            site[0][18]='.';
            site[0][19]='c';
            site[0][20]='o';
            site[0][21]='m';
            site[0][22]='/';
            site[0][23]='\0';
        cV=cB=cF=0;
        v=0;
   //     presence=0;
        printf("Case %d:\n",i);
        while(1){
            scanf("%s",input);
            if(input[0]=='V'){
                cV++;
                v++;
                scanf("%s",site[v]);
                printf("%s\n",site[v]);
                presence = v;
                cB=cF=0;

                }

            else if(input[0]=='Q')
            break;

            // puts(site[0]);
            else if(input[0]=='B'){

               v--;
               if(cV==0 || v<0){
                    printf("Ignored\n");
                    v=0;
               }

                else{
                    cB++;
                    puts(site[v]);
                }
            }
            else if(input[0]=='F'){
                v++;
                if(cF==cB || cV==0){
                    printf("Ignored\n");
                    v--;

                }
                else{
                    cF++;
                    puts(site[v]);
                }
            }

            }
        }
        return 0;
}
