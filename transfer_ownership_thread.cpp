#include<iostream>
#include<thread>


void foo() {
    std::cout << "Hello from foo\n"<< std::endl;
}

void bar() {
    std::cout << "Hello from bar\n"<< std::endl;
}
int main(){
    std:: thread thread1(foo);
    std::thread thread2=std::move(thread1);
    thread1=std::thread(bar);
    thread1.join();
    thread2.join();
}