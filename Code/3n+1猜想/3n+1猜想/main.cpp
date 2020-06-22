//
//  main.cpp
//  3n+1猜想
//
//  Created by 陈伟多 on 2020/6/2.
//  Copyright © 2020 陈. All rights reserved.
//

#include <cstdio>
int main()
{
    int N,k=0;
    scanf("%d",&N);
    while(N!=1){
        if(N%2 == 0){
            N/=2;
        }else{
            N=3*N+1;
        }
        k++;
    }
    printf("%d\n",k);
    return 0;
}
