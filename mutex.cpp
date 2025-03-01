#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<list>
using namespace std;

list<int> l;
mutex m;

void add_to_list(int  const& x){
    // m.lock();
    // m.unlock();
    lock_guard<mutex> lg(m);
    l.push_front(x);
}

void size(){
    m.lock();
    cout << l.size() << endl;
    m.unlock();
}

int main(){
    thread t1(add_to_list, 1);
    thread t2(add_to_list, 2);
    thread t3(add_to_list, 3);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}