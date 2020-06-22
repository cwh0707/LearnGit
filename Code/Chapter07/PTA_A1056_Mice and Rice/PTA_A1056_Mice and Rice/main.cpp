#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010;

struct Mouse{
    int mass;  //质量
    int rank;  //排名
}Mouse[maxn];

int main(){
    int NP,NG,order;
    scanf("%d%d",&NP,&NG);
    for(int i=0;i<NP;i++){
        scanf("%d",&Mouse[i].mass);
    }
    queue<int> q;
    for(int i=0;i<NP;i++){
        scanf("%d",&order);
        q.push(order);
    }
    int temp = NP,group;
    while(q.size()!= 1){
        //计算group
        if(temp%NG == 0)
            group = temp/NG;
        else
            group = (temp/NG)+1;
        for(int i=0;i<group;i++){
            int k =q.front(); //k存放该组质量最大的Mouse
            for(int j=0;j<NG;j++){
                if(i*NG+j >= temp) //如果最后一组老鼠数不足NG时起作用，跳出循环，为什么是>=是因为是从0开始循环的 故0 1 2 要加上等号
                    break;
                int front = q.front();
                if(Mouse[front].mass > Mouse[k].mass)
                    k = front;
                //如果小于的话
                Mouse[front].rank = group+1;
                q.pop(); //将老鼠出队
            }
            q.push(k);
        }
        temp = group; //group只老鼠晋级
    }
    Mouse[q.front()].rank = 1;
    
    for(int i=0;i<NP;i++){
        printf("%d",Mouse[i].rank);
        if(i<NP-1){
            printf(" ");
        }
    }
    return 0;
}
