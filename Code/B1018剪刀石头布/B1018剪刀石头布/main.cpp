//
//  main.cpp
//  B1018剪刀石头布
//
//  Created by 陈伟多 on 2020/6/2.
//  Copyright © 2020 陈. All rights reserved.
//

#include <cstdio>
int main()
{
    int N;
    scanf("%d",&N);
    int count[4]={0};
//    int A[3],B[3];
    for(int i=0;i<N;i++){
        char c1,c2;
        scanf("%c%c",&c1,&c2);
        if(c1==c2){
            count[0]++;
        }
        if(c1=='C' && c2=='J'){
            count[1]++;
        }
        if(c1=='J' && c2=='B'){
            count[2]++;
        }if(c1=='B'&& c2=='C'){
            count[3]++;
        }
    }
    int awin = count[1]+count[2]+count[3];
    int bwin = N-awin-count[0];
    printf("\n");
    printf("%d %d %d\n",awin,count[0],bwin);
    printf("%d %d %d\n",bwin,count[0],awin);
    return 0;
}
