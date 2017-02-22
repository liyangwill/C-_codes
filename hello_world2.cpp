#include<iostream>
#include<string>
using namespace std;

void calc(int x);

int main(){
    int x = 10;
    calc(x);
    printf("%d", x);
}

void calc(int x){
    x=x+10;
}
