#include <thread>
#include<atomic>
#include <iostream>
using namespace std;

//using thread_local ensures that each thread has its own copy of i
//so the output will be 1 1 1
//if we remove thread_local, the output will be 1 2 3

thread_local atomic<int> i=0;


void foo(){
    ++i;
    cout << i << endl;
}

int main(){
    thread t1(foo);
    thread t2(foo);
    thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}