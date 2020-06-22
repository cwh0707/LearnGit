#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;

struct Node{
    long long int x;
    long long int y;
    bool flag;
}node[maxn];

bool cmp(Node a,Node b){
    if( a.x != b.x){
        return a.x > b.x; //从小到大排序
    }
    return a.y > b.y; //从小到大排序
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<maxn;i++){ //结构体初始化
        node[i].flag = false;
    }
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&node[i].x,&node[i].y);
        node[i].flag = true;
    }

    sort(node,node+maxn,cmp); //对其排序
    
    int k[maxn]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i){
                if(node[j].x == (node[i].x) + 1 && node[j].y == node[i].y && node[j].flag == true){  //右边
                    k[i]++;
                }
                if(node[j].x == node[i].x && node[j].y == (node[i].y)+1 && node[j].flag == true){ //上边
                    k[i]++;
                }
                if(node[j].x == (node[i].x)-1 && node[j].y == node[i].y && node[j].flag == true){ //左边
                    k[i]++;
                }
                if(node[j].x == node[i].x && node[j].y == (node[i].y)-1 && node[j].flag == true){  //下边
                    k[i]++;
                }
            }
        }
    }
    
    int ans[5] = {0};

    for(int i=0;i<n;i++){
        int rank = 0;
        if(k[i] == 4){
            for(int j = 0;j<n;j++){
                if(j!=i){
                    if(node[j].x == (node[i].x)-1 && node[j].y == (node[i].y)+1 && node[j].flag == true){ //左上
                        rank++;
                    }
                    if(node[j].x == (node[i].x)+1 && node[j].y == (node[i].y)+1 && node[j].flag == true){ //右上
                        rank++;
                    }
                    if(node[j].x == (node[i].x)-1 && node[j].y == (node[i].y)-1 && node[j].flag == true){ //左下
                        rank++;
                    }
                    if(node[j].x == (node[i].x)+1 && node[j].y == (node[i].y)-1 && node[j].flag == true){ //右下
                        rank++;
                    }
                }
            }
            ans[rank]++;
        }
    }
    
    for(int i=0;i<5;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
