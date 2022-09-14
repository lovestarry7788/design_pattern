#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

class SingleInstance {
private:
    SingleInstance() { cout << "constructor called!" << endl; };
    ~SingleInstance() { cout << "deconstructor called!" << endl; };
    SingleInstance(const SingleInstance&) = delete;
    SingleInstance& operator=(const SingleInstance&) = delete;
    static SingleInstance* m_SingleInstance;
public:
    static SingleInstance* getInstance() {
        if(m_SingleInstance == nullptr) {
            m_SingleInstance = new SingleInstance();
        }
        return m_SingleInstance;
    }
    static void deleteInstance() {
        if(m_SingleInstance == nullptr) {
            delete m_SingleInstance;
            m_SingleInstance = nullptr;
        }
    }
};

SingleInstance* SingleInstance::m_SingleInstance = nullptr;

int main() {

    SingleInstance *p1 = SingleInstance::getInstance();
    SingleInstance *p2 = SingleInstance::getInstance();

    SingleInstance::deleteInstance();
    return 0;
}