#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <mutex>
#include <thread>

using namespace std;

class SingleInstance {
private:
    static shared_ptr<SingleInstance> m_SingleInstant;
    SingleInstance(){cout << "constructor" << endl;}
    SingleInstance(const SingleInstance&) = delete;
    SingleInstance& operator=(const SingleInstance&) = delete;
public:
    ~SingleInstance(){cout << "deconstructor" << endl;}
    static shared_ptr<SingleInstance> getInstance() {return m_SingleInstant;}
    void get() {cout << this << endl;}
};

shared_ptr<SingleInstance> SingleInstance::m_SingleInstant = shared_ptr<SingleInstance>(new SingleInstance());

int main() {

    shared_ptr<SingleInstance> p1 = SingleInstance :: getInstance();
    shared_ptr<SingleInstance> p2 = SingleInstance :: getInstance();

    p1 -> get();
    p2 -> get();

    return 0;
}