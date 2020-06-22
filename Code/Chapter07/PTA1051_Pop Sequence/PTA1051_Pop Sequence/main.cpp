#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;

int main(){
    int M,N,K;
    scanf("%d%d%d",&M,&N,&K);
    int a[N+1];
    while(K--){
        //清空栈
        while(!s.empty()){
            s.pop();
        }
        for(int i=1;i <= N;i++){
            scanf("%d",&a[i]);
        }
        int current = 1;
        bool flag = true;
        for(int i=1;i <= N;i++){
            s.push(i);
            if(s.size()>M){
                flag = false;
                break;
            }
            while(!s.empty() && s.top() == a[current]){ //如果当栈顶元素等于序列元素的话
                s.pop();
                current++;
            }
        }
        if(s.empty()==true && flag == true){
            printf("YES\n");    //如果栈空并且flag==true
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
