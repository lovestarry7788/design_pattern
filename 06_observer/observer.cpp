#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

class Subject; // Observer 与 Subject 相互引用
class Observer { // 观察者
protected:
    Subject *subject;
public:
    virtual void update() = 0;
};

class Subject {
private:
    list<Observer*> observers;
    int state;
public:
    int getState() { return state; }
    void setState(int state) {
        this -> state = state;
        notifyAllObservers();
    }
    void attach(Observer *observer) {
        observers.push_back(observer);
    }
    void notifyAllObservers() {
        for (auto u: observers) {
            u -> update();
        }
    }
};

class BinaryObserver : public Observer {
public:
    explicit BinaryObserver(Subject *subject) {
        this -> subject = subject;
        this -> subject -> attach(this);
    }
    void printBinary(int x) {
        char ch[256]; int len = 0;
        while(x) ch[++len] = x%2 + '0', x/=2;
        for(int i=len;i>=1;i--) printf("%c",ch[i]);
    }
    virtual void update() {
        printf("Binary String: ");
        printBinary(subject -> getState());
        printf("\n");
    }
};

class OctalObserver : public Observer {
public:
    explicit OctalObserver(Subject *subject) {
        this -> subject = subject;
        this -> subject -> attach(this);
    }
    virtual void update() {
        printf("Octal String: %o\n" , subject -> getState());
    }
};

class HexaObserver : public Observer {
public:
    explicit HexaObserver(Subject *subject) {
        this -> subject = subject;
        this -> subject -> attach(this);
    }
    virtual void update() {
        printf("Hex String: %x\n" , subject -> getState());
    }
};

int main() {

    Subject *subject = new Subject();
    Observer *binaryObserver = new BinaryObserver(subject);
    Observer *octalObserver = new OctalObserver(subject);
    Observer *hexaObserver = new HexaObserver(subject);
    subject -> setState(10);

    subject -> setState(15);

    return 0;
}