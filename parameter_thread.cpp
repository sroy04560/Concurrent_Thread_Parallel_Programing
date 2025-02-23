#include<iostream>
#include<thread>
#include<chrono>
#include<queue>
void fuc_1(int x,int y){
    std::cout<<"x+y "<<x+y<<std::endl;
}

void func_2(int &x){
    while(true){
        std::cout<<"func_2 x "<<x<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
}

int main(){
    // int x=10;
    // int y=20;
    // std::thread t1(fuc_1,x,y);
    // t1.join();
    int n=9;
    
    std::cout<<"main thread n "<<n<<std::endl; 
    std::thread t2(func_2,std::ref(n));
    std::this_thread::sleep_for(std::chrono::seconds(5));
    n=15;
    std::cout<<"main thread n "<<n<<std::endl;
    t2.join();



    return 0;
}