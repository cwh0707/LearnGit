
#include <cstdio>
#include <string>

const int maxn = 100010;
struct Node{
    int next;
    char data;
    bool flag;
}node[maxn];


int main(){
    int addr1,addr2,N;
    scanf("%d%d%d",&addr1,&addr2,&N);
    for(int i=0;i<maxn;i++){  //初始化结构数组中的flag
        node[i].flag = false;
    }
    int address,next;
    char data;
    for(int i=0;i<N;i++){
        scanf("%d %c %d",&address,&data,&next);
        node[address].data = data;
        node[address].next = next;
    }
    int p=addr1;
    while(p!=-1){
        node[p].flag = true;
        p=node[p].next;
    }
    p = addr2;
    while(p!=-1){
        if(node[p].flag == true)
            break;
        p=node[p].next;
    }
    if(p!=-1){
        printf("%05d",p);
    }else{
        printf("-1");
    }
    return 0;
}
