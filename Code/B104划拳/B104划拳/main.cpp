//
//  main.cpp
//  B104划拳
//
//  Created by 陈伟多 on 2020/6/2.
//  Copyright © 2020 陈. All rights reserved.
//

#include <cstdio>
#include <math.h>
int main()
{
    int N;
    scanf("%d",&N);
    int A,PA,B,PB;
    int counta=0,countb=0;
    while(N--){
        scanf("%d%d%d%d",&A,&PA,&B,&PB);
        int sum = A+B;
        if(sum == PA && sum !=PB){ //A赢
            counta++;
        }
        if(sum == PB && sum!=PA){ //B赢
            countb++;
        }
    }
    printf("%d %d",countb,counta);
    return 0;
}
