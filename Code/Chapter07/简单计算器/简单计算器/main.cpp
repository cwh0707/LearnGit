//
//  main.cpp
//  简单计算器
//
//  Created by 陈伟洪 on 2020/6/3.
//  Copyright © 2020 陈. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

struct node{
    double num;   //操作数
    char op;    //操作符
    bool flag;  //标志位 如果是操作数 则为true 如果是操作符 则为false
};

string str;
stack<node> s;  //存放符号栈
queue<node> q;
map<char,int> op;

void Change(){ //将中缀表达式转变为后缀表达式
    node temp;
    for(int i=0;i<str.length();){
        if(str[i] >= '0' && str[i] <='9'){  //如果是操作数
            temp.flag = true;
            temp.num = str[i++] - '0';
            while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
                temp.num = temp.num*10 + (str[i]-'0');
                i++;
            }
            q.push(temp);
        }else{
            temp.flag = false;
            while(!s.empty() && op[str[i]] <= op[s.top().op]){
                q.push(s.top());  //将符号栈压入后缀表达式队列中
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);   //将该操作符压入符号栈中
            i++;
        }
    }
    //如果将该字符串都扫描完毕还有元素的话 将栈内所有的操作符都弹出
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

double Cal(){
    double temp1,temp2;
    node cur,temp;
    while(!q.empty()){
        cur = q.front();  //cur记录队列的队首元素
        q.pop();
        if(cur.flag == true)
            s.push(cur);
        else{  //如果是操作符
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if(cur.op == '+')
                temp.num = temp1+temp2;
            if(cur.op == '-')
                temp.num = temp1-temp2;
            if(cur.op =='*')
                temp.num = temp1*temp2;
            if(cur.op == '/')
                temp.num = temp1/temp2;
            s.push(temp);
        }
    }
    return s.top().num;  //栈顶元素就是后缀表达式的值
}

int main()
{
    op['+'] = op ['-'] = 1;
    op['*'] = op['/'] = 2;
    while(getline(cin,str),str!="0"){
        for(string::iterator it = str.begin();it!=str.end();it++){
            if(*it == ' ')
                str.erase(it);
        }
        while (!s.empty()) {  //初始化栈
            s.pop();
        }
        Change();
        printf("%.2lf\n",Cal());
    }
    return 0;
}

//#include <iostream>
//#include <cstdio>
//#include <queue>
//#include <map>
//#include <stack>
//#include <string>
//using namespace std;
//
//struct node{
//    double num;
//    char op;
//    bool flag;
//};
//
//stack<node> s;
//queue<node> q;
//map<char,int> op;
//string str;
//
//void Change(){
//    node temp;
//    for(int i=0;i<str.length();){
//        if(str[i] >= '0' && str[i] <= '9'){  //如果是个操作数
//            temp.flag = true;
//            temp.num = str[i++] - '0';
//            while(i<str.length() && str[i] >= '0' && str[i] <='9'){
//                temp.num = temp.num *10 + (str[i]-'0');
//                i++;
//            }
//            q.push(temp);
//        }else{
//            temp.flag =false;
//            while(!s.empty() && op[str[i]] <= op[s.top().op]){
//                q.push(s.top());
//                s.pop();
//            }
//            temp.op = str[i];
//            s.push(temp);
//            i++;
//        }
//    }
//    while(!s.empty()){
//        q.push(s.top());
//        s.pop();
//    }
//}
//
//double Cal(){
//    double temp1,temp2;
//    node cur,temp;
//    while(!q.empty()){
//    cur = q.front();
//    q.pop();
//    if(cur.flag == true){
//        s.push(cur);
//    }
//    else{ //如果是操作符
//        temp2 = s.top().num;
//        s.pop();
//        temp1 = s.top().num;
//        s.pop();
//        temp.flag = true;
//        if(cur.op=='+'){
//            temp.num = temp1 + temp2;
//        }
//        if(cur.op=='-'){
//            temp.num = temp1 - temp2;
//        }
//        if(cur.op =='*'){
//            temp.num = temp1 * temp2;
//        }else{
//            temp.num = temp1 / temp2;
//        }
//        s.push(temp);
//    }
//    }
//    return s.top().num;
//}
//
//int main()
//{
//    op['+'] = op['-'] = 1;
//    op['*'] = op['/'] = 2;
//    while(getline(cin,str),str != "0"){
//        for(string::iterator it=str.begin();it!=str.end();it++){
//            if(*it == ' ')
//                str.erase(it);
//        }
//         while(!s.empty()){
//            s.pop();
//        }
//        Change();
//        printf("%.2lf\n",Cal());
//    }
//    return 0;
//}
