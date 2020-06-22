#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000010;

struct Node {
    int Address;
    int key;
    int next;
    bool flag;
}node[maxn];

bool cmp(Node a,Node b){
    if(a.flag == false || b.flag == false)
        return a.flag > b.flag;
    else  //两者都是有效结点
        return a.key < b.key; //按照key值増序排列
}

int main(){
    int N,addr;
    scanf("%d%d",&N,&addr);
    //初始化结构数组
    for(int i=0;i<maxn;i++){
        node[i].flag = false;
    }
    for(int i=0;i<N;i++){
        int address,next,key;
        scanf("%d%d%d",&address,&key,&next);
        node[address].key = key;
        node[address].next = next;
        node[address].Address = address;
    }
    int p = addr,count=0; //count用于计数有多少个有效结点
    while(p!=-1){
        node[p].flag = true;
        p =node[p].next;
        count++;
    }
    if(count == 0){
        printf("0 -1"); //防止-1被05d化提前判断
    }else{
        sort(node,node+maxn,cmp);  //从node[0]到node[maxn]区间进行排序
        printf("%d %05d\n",count,node[0].Address);
    }
    for(int i=0;i<count;i++){
        if(i!=count-1){
            printf("%05d %d %05d\n",node[i].Address,node[i].key,node[i+1].Address);  //此处不能填写node[i].next,如何那样写会不符合提题意，他要你写出一条新的链表
        }else{
            printf("%05d %d -1\n",node[i].Address,node[i].key);
        }
    }
    return 0;
}
