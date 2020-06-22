#include <cstdio>
int main(){
    int n;
    scanf("%d",&n);
    int count[5]={0};
    int k = 0;
    int i = 1;
    while(k!=n){
        if(i % 7 == 0 || i % 10 == 7 || (i/10)%10 == 7 || (i/100)%10 == 7){
            count[i%4]++;
        }else{
            k++;
        }
        i++;
    }
    for(int i=1;i<4;i++){
        printf("%d\n",count[i]);
    }
    printf("%d\n",count[0]);
    return 0;
}
