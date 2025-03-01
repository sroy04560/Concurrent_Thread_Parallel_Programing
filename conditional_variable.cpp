#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include <string>
#include<condition_variable>
using namespace std;

bool i_arrive=false;
int dist_destination=10;
int dist_covered=0;
condition_variable cv;
mutex m;

bool keep_driving(){
    while(true){
        this_thread::sleep_for(chrono::seconds(1));
        dist_covered++;

        if(dist_covered==dist_destination){
            cv.notify_one();
        }
    }
}

void kepp_awak_all_night(){
    while(dist_covered<dist_destination){
        cout<<"I am awake"<<endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout<<"I am at destination distance covered"<<dist_covered<<endl;
}

void ask_driver_to_wake_up(){
    unique_lock<mutex> ul(m);
    cv.wait(ul, []{return dist_covered==dist_destination;});
    cout<<"Driver wake up"<<endl;
    cout<<"I am at destination distance covered  wake_up"<<dist_covered<<endl;

}

void set_alarm(){
    if(dist_covered<dist_destination){
        cout<<"taking nap"<<endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout<<"I am at destination distance covered from alaram"<<dist_covered<<endl;

}

int main(){
    thread t1(keep_driving);
    thread t2(ask_driver_to_wake_up);
    // thread t3(set_alarm);
    
    t1.join();
    t2.join();
    // t3.join();
    
    return 0;
}