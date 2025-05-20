// Operating Systems in medical Devices (eg., heart monitors): Must 


#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
using namespace chrono;
void task(string name, int period, int exe_time){
    while(true){
        auto start = high_resolution_clock::now();
        cout<<name<<" execution for "<<exe_time<<" ms."<<endl;
        this_thread::sleep_for(microseconds(exe_time));
        auto end = high_resolution_clock::now();
        auto elapsed = duration_cast<milliseconds>(end - start);
        auto next_period = milliseconds(period)-elapsed;
        if(next_period.count() > 0){
            this_thread::sleep_for(next_period);
            break;
        }
    }
}

int main(){
    thread t1(task, "user1", 10000, 20);
    thread t2(task, "user2", 20000, 30);
    t1.join();
    t2.join();
    return 0;
}