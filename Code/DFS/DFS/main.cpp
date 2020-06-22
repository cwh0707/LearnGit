//
//  main.cpp
//  DFS
//
//  Created by cwh on 2020/4/12.
//  Copyright © 2020 陈. All rights reserved.
//

#include <cstdio>
//实现搜索函数 递归实现
const int N=30;
int n,V,maxValue;
int w[N],v[N];

void DFS(int index,int maxW,int maxV){
    if(index == n){
        if(maxW <= V && maxV > maxValue){
            maxValue = maxV;
        }
        return;
    }
    //岔路口
    DFS(index+1,maxW,maxV); //未选中的情况
    DFS(index+1,maxW+w[index],maxV+v[index]);
}

int main(){
    scanf("%d%d",&n,&V);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    DFS(0,0,0);
    printf("%d\n",maxValue);
    return 0;
}
