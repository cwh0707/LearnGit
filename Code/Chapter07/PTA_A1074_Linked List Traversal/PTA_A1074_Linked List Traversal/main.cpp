#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct Node{
    int address;
    int data;
    int next;
    int order;
}node[maxn];

bool cmp(Node a,Node b){
    return a.order < b.order; //按order从小到大排序
}

int main(){
    for(int i=0;i<maxn;i++){
        node[i].order = maxn;
    }
    int addr,N,K;
    scanf("%d%d%d",&addr,&N,&K);
    int address;
    for(int i=0;i<N;i++){
        scanf("%d",&address);
        scanf("%d%d",&node[address].data,&node[address].next);
        node[address].address = address;
    }
    int p = addr,count = 0;
    while(p!=-1){
        node[p].order = count++;
        p=node[p].next;
    }
    sort(node,node+maxn,cmp);
//    int group = N/K;
    int n=count;
    for(int i=0;i<n/K;i++){
        for(int j = (i+1)*K-1;j>i*K;j--){
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
        }
        printf("%05d %d ",node[i*K].address,node[i*K].data);
        if(i<n/K-1){ //如果不是最后一块的话，直接指向下一块元素排好序的第一个地址
            printf("%05d\n",node[(i+2)*K-1].address);
        }else{ //如果是最后一块的话
            if(n%K==0){
                printf("-1\n");
            }else{ //剩下不完整的块按原先顺序输出
                printf("%05d\n",node[(i+1)*K].address);
                for(int i=n/K*K;i<n;i++){
                    printf("%05d %d ",node[i].address,node[i].data);
                    if(i<n-1){
                        printf("%05d\n",node[i+1].address);
                    }else{
                        printf("-1\n");
                    }
                }
            }
        }
    }
    return 0;
}
