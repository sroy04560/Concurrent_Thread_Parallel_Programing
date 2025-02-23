
#include<iostream>
#include<thread>
#include<chrono>
class thread_guard
{
	std::thread & t;
public:
	explicit thread_guard(std::thread & _t):t(_t)
	{}
 
	~thread_guard()
	{
		if(t.joinable())
		{
			t.join();
		}
	}
 
	thread_guard(const thread_guard & ) = delete;
	thread_guard & operator= (const thread_guard & ) = delete;
};

void cleaning(){
    std::cout<<"Cleaning is start"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"Cleaning is done"<<std::endl;
}
void full_speed_ahead(){
    std::cout<<"Full speed ahead"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"Engine Is on full speed "<<std::endl;
}

void stop_engin(){
    std::cout<<"Stop Engine"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"Engine is off"<<std::endl;
}

void run(){
    std::cout<<"Captain "<<std::endl;

    std::thread cleaning_thread(cleaning);
    thread_guard cleaning_guard(cleaning_thread);

    std::thread full_speed_ahead_thread(full_speed_ahead);
    thread_guard full_speed_ahead_guard(full_speed_ahead_thread);
    
    std::thread stop_engin_thread(stop_engin);
    thread_guard stop_engin_guard(stop_engin_thread);
    
    int n;
    while(true){
        std::cin>>n;
        if(n==1){
            cleaning_thread.detach();
        }
        else if(n==2){
            full_speed_ahead_thread.join();
        }
        else if(n==1){
            stop_engin_thread.join();
        }

        else if(n==100){
            std::cout<<"Quiteing"<<std::endl;
            break;
        }
        else{
            std::cout<<"Invalid input"<<std::endl;
        }
    }

}

int main(){
    run();
    return 0;
}