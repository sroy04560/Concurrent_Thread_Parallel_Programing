#include <iostream>
#include <thread>
using namespace std;
void foo() {
    std::cout << "Hello from foo\n"<< this_thread::get_id() << endl;
}
class call_cls{
    public:
    void operator()(){
        std::cout << "\nHello from call_cls\n"<< this_thread::get_id() << endl;
    }
};
void run() {
    thread thread1(foo);
    call_cls obj;
    thread thread2(obj);
    thread thread3([]{
        std::cout << "\nHello from lambda\n"<< this_thread::get_id() << endl;
    });

    thread1.join();
    thread2.join();
    thread3.join();
    std::cout << "Hello from run\n";
}


int main(){
    run();
    return 0;
}
