//
//  main.cpp
//  DFS带剪枝function
//
//  Created by 陈伟多 on 2020/4/12.
//  Copyright © 2020 陈. All rights reserved.
//

#include <cstdio>
const int N = 30;

int n,V;  //n是物品数量 V是背包最大载重量
int w[N],v[N];
int maxValue; //记录当前价值最大值

void DFS(int index,int sumW,int sumV){
    if(index==n){
        return;
    }
    DFS(index+1,sumW,sumV);  //不选择该物品
    //只有加入该物品后不会超重的话才可以进入下一层(继续) 如果超出是进不去的
    if(sumW+w[index] <= V){
        if(sumV+v[index] > maxValue){
            maxValue = sumV+v[index]; //更新最大值
        }
        DFS(index+1,sumW+w[index],sumV+v[index]);
    }
    
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
