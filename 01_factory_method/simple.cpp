#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

// 抽象产品类
class API {
public:
    virtual ~API() {}
    virtual void Say() = 0;
};

// 具体产品类
class HelloAPI : public API{
public:
    void Say() { cout << "Hello" << endl; }
};

class HiAPI : public API {
public:
    void Say() { cout << "Hi" << endl;}
};

// 抽象工厂类
class Factory {
public:
    virtual API* CreateAPI() = 0;
    virtual ~Factory() {}
};

// 具体工厂类
class HiFactory : public Factory {
public:
    API* CreateAPI(){return new HiAPI();}
};

class HelloFactory : public Factory {
public:
    API* CreateAPI(){return new HelloAPI();}
};

int main(int argc, char const *argv[]) {
    
    Factory *hiFactory = new HiFactory();
    API *hi = hiFactory -> CreateAPI();
    hi -> Say();
    delete hi;
    delete hiFactory;

    Factory *helloFactory = new HelloFactory();
    API *hello = helloFactory -> CreateAPI();
    hello -> Say();
    delete hello;
    delete helloFactory;
    
    return 0;
}