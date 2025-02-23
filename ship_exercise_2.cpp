#include<iostream>
#include<thread>
#include<chrono>
#include<queue> 



void func_1(std::queue<int> &work){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    while(true){
        std::cout<<"work is done"<<std::endl;
        if(work.empty()){

            std::cout<<"Sleep for 2 second"<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            
        }
        else{
            work.front();
            std::cout<<"Now sleep for 1 second"<<std::endl;
            work.pop();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

void func_2(std::queue<int> &clean){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    while(true){
        std::cout<<"clean is done"<<std::endl;
        if(clean.empty()){

            std::cout<<"Sleep for 2 second"<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            
        }
        else{
            clean.front();
            std::cout<<"Now sleep for 1 second"<<std::endl;
            clean.pop();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}
void run(){
    std::cout<<"Captain "<<std::endl;
    std::queue<int> work;
    std::queue<int>clean_work;
    int work_count=0;
    int a=0;
    int clean_count=0;

    std::thread t1(func_1,std::ref(work));
    std::thread t2(func_2,std::ref(clean_work));
    
    int n;
    while(true){
        std::cin>>n;
        if(n==1){
            if(clean_count==100)continue;
            if(a==100)clean_count=100;
            clean_work.push(clean_count);


        }
        else if(n==2){
            if(work_count==100)continue;
            if(a==100)work_count=100;
            work.push(work_count);
        }
        

        else if(n==100){
            std::cout<<"Quiteing"<<std::endl;
            break;
        }
        else{
            std::cout<<"Invalid input"<<std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    t1.join();
    t2.join();

}

int main(){
    run();
    return 0;
}