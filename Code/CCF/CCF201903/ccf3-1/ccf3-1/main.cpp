#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;

bool cmp(int a,int b){
    return a > b;
}

int main(){
    int n;
    scanf("%d",&n);
    int data[n];
    for(int i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    sort(data,data+maxn,cmp);
    for(int i=0;i<maxn;i++){
        printf("%d ",data[i]);
    }
    return 0;
}
