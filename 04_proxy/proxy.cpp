#include <bits/stdc++.h>

using namespace std;

// 抽象主题角色
class Subject {
public:
    virtual void request() = 0;
    Subject(){}
    ~Subject(){}
};

// 具体主题角色
class RealSubject : public Subject {
public:
    void request() override {
        cout << "RealSubject request!" << endl;
    }
};

class Proxy : public Subject {
private:
    shared_ptr<RealSubject> m_RealSubject; 
public:
    Proxy() {
        m_RealSubject = shared_ptr<RealSubject>(new RealSubject());
    }
    ~Proxy(){}
    void request() override {
        m_RealSubject -> request();
    }
};

signed main() {
    shared_ptr<Subject> proxy = shared_ptr<Proxy>(new Proxy());
    proxy -> request();
    return 0;
}