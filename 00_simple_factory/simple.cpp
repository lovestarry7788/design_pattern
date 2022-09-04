#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class API {
public:
    virtual ~API() {}
    virtual void Say() = 0;
};

class Hello : public API{
public:
    void Say() { cout << "Hello" << endl; }
};

class Hi : public API {
public:
    void Say() { cout << "Hi" << endl;}
};

enum ProductType {
    HI,
    HELLO
};

class Factory {
public:
    API* CreateAPI(ProductType product) {
        switch(product) {
            case HI: {
                return new Hi();
            }
            case HELLO: {
                return new Hello();
            }
            default:
                return nullptr;
        }
    } 
};

int main(int argc, char const *argv[]) {
    Factory factory;
    API *Hi = factory.CreateAPI(HI);
    if(Hi != nullptr) {
        Hi -> Say();
        delete Hi;
    }
    
    API *Hello = factory.CreateAPI(HELLO);
    if(Hello != nullptr) {
        Hello -> Say();
        delete Hello;
    }
    
    return 0;
}