//
//  main.cpp
//  B1008数组循环右移
//
//  Created by 陈伟多 on 2020/6/2.
//  Copyright © 2020 陈. All rights reserved.
//

#include <cstdio>
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    M = M % N;
    int A[N];
    for(int i=0;i<N-M;i++){
        scanf("%d",&A[i+M]);
    }
    for(int j=0;j<M;j++){
        scanf("%d",&A[j]);
    }
    for(int i=0;i<N;i++){
        printf("%d",A[i]);
        if(i<N-1){
          printf(" ");
        }
    }
    return 0;
}
