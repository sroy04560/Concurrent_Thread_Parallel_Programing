#include<iostream>
#include<thread>
using namespace std;

void A(){
    cout << "Hello from A\n";
    thread threadC([]{
        cout << "Hello from test\n";
    });
    threadC.join();
}

void B(){
    cout << "Hello from B\n";
    
}
void main_thread(){
    thread threadA (A);
    thread threadB (B);
    cout << "Hello from main thread\n";
    threadA.join();
    threadB.join();
}

int main(){
    thread thread1 (main_thread);
    thread1.join();
    return 0;
}