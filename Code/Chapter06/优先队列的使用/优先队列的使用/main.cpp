//
//  main.cpp
//  优先队列的使用
//
//  Created by 陈伟多 on 2020/6/4.
//  Copyright © 2020 陈. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct fruit{
    string name;
    double price;
    //重载小于号，注意此处不能重载大于号，会导致变异错误
    friend bool operator < (fruit f1,fruit f2){
        return f1.price < f2.price;
    }
}f1,f2,f3;

int main(){
    priority_queue<fruit> q;
    f1.name = "苹果";
    f1.price=30;
    f2.name = "梨子";
    f2.price=20;
    f3.name = "草莓";
    f3.price = 88;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout<<q.top().name<<endl<<q.top().price<<endl;
    return 0;
}

