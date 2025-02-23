#include<iostream>
#include<thread>
#include<chrono>
using namespace std;


void foo(){
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Hello from foo\n";

}

// void bar(){
//     this_thread::sleep_for(chrono::seconds(2));

//     cout << "Hello from bar\n";
// }

void other_opp(){

    cout << "Hello from bar\n";
    throw runtime_error("Exception from other");
}
void run (){
    // thread foo_thread1(foo);
    // thread bar_thread2(bar);
    // bar_thread2.detach();
    // cout<<"after bar detach "<<endl;
    
    // foo_thread1.join();
    // cout << "after foo join "<<endl;    

    thread foo_thread(foo);
    try
    {
        
            other_opp();
            foo_thread.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        foo_thread.join();

    }
    

}

int main(){
    run();
    return 0;
}