//
//  main.cpp
//  B1012数字分类
//
//  Created by 陈伟多 on 2020/6/2.
//  Copyright © 2020 陈. All rights reserved.
//

#include <cstdio>
int A1=0,A2=0,A3=0,A5=-1,k=1,count=0;
double A4=0;
int main(){
    int N;
    scanf("%d",&N);
    int A[N];
    int Count[5] = {0};
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        if(A[i]%5==0 && A[i]%2==0){ //处理A1
            A1=A1+A[i];
            Count[0]++;
        }
        if(A[i]%5 == 1){  //处理A2
            if(k%2!=0){
                A2 = A2+A[i];
            }else{
                A2 = A2-A[i];
            }
            k++;
            Count[1]++;
        }
        if(A[i]%5==2){
            A3++;
            Count[2]++;
        }
        if(A[i]%5==3){
            A4 = A4+A[i];
            count++;
            Count[3]++;
        }
        if(A[i]%5==4){
            if(A[i]>A5)
                A5 = A[i];
            Count[4]++;
        }
    }
    if(Count[0]!=0)
        printf("%d ",A1);
    else
        printf("N ");
    if(Count[1]!=0)
        printf("%d ",A2);
    else
        printf("N ");
    if(Count[2]!=0)
        printf("%d ",A3);
    else
        printf("N ");
    if(Count[3]!=0)
        printf("%.1lf ",A4/count);
    else
        printf("N ");
    if(Count[4]!=0)
        printf("%d",A5);
    else
        printf("N");
    return 0;
}
