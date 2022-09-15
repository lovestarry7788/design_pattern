#include <iostream>
using namespace std;
class Strategy {
public:
    virtual int doOperation(int a,int b) = 0;
    ~Strategy(){}
};

class OperationAdd : public Strategy {
public:
    OperationAdd(){}
    ~OperationAdd(){}
    int doOperation(int a,int b) override {
        return a + b;
    }
};

class OperationSub : public Strategy {
public:
    OperationSub(){}
    ~OperationSub(){}
    int doOperation(int a,int b) override {
        return a - b;
    }
};

class Context {
public:
    shared_ptr<Strategy> strategy;
    Context(shared_ptr<Strategy> s) {
        strategy = s;
    }
    int executeStrategy(int a,int b) {
        return strategy -> doOperation(a,b);
    }
};

int main(int argc,char *argv[]) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    shared_ptr<OperationAdd> o1(new OperationAdd());
    shared_ptr<OperationSub> o2(new OperationSub());
    shared_ptr<Context> context1(new Context(o1));
    shared_ptr<Context> context2(new Context(o2));
    cout << context1 -> executeStrategy(1,2) << endl;
    cout << context2 -> executeStrategy(1,2) << endl;
    return 0;
}