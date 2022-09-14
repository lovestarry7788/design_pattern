#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <mutex>
#include <thread>
#include <memory>

#define THREAD_NUM 10

using namespace std;

class SingleInstance {
private:
    SingleInstance(){ cout << "construct Instace" << endl; }
    SingleInstance(const SingleInstance&) = delete;
    SingleInstance& operator=(const SingleInstance&) = delete;
public:
    ~SingleInstance() {cout << "destruct Instance" << endl; }
    static shared_ptr<SingleInstance> m_SingleInstance;
    static mutex m_Mutex; 
    static shared_ptr<SingleInstance> getInstance() {
        if(m_SingleInstance == nullptr) {
            lock_guard<mutex> lock(m_Mutex);
            if(m_SingleInstance == nullptr) {
                m_SingleInstance = shared_ptr<SingleInstance>(new SingleInstance());
            }
        }
        return m_SingleInstance;
    }
    void get() {
        cout << "实例地址: " << this << endl;
    }
};

mutex SingleInstance:: m_Mutex;
shared_ptr<SingleInstance> SingleInstance:: m_SingleInstance = nullptr;

void Test() {
    shared_ptr<SingleInstance> p = SingleInstance::getInstance();
    p -> get();
}

int main() {
    thread threadArray[THREAD_NUM];
    for(int i=0;i<THREAD_NUM;i++) {
        threadArray[i] = thread(&Test);
    }
    for(int i=0;i<THREAD_NUM;i++) {
        threadArray[i].join();
    }
    return 0;
}