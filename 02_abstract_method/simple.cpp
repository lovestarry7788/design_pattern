#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

// 抽象产品类 1
class Book {
public:
    virtual ~Book() {}
    virtual void Show() = 0;
};

// 具体产品类 1
class HelloBook : public Book{
public:
    void Show() { cout << "Show HelloBook" << endl; }
};

class HiBook : public Book{
public:
    void Show() { cout << "Show HiBook" << endl;}
};

// 抽象产品类 2
class Paper {
public:
    virtual ~Paper(){}
    virtual void Show() = 0;
};

// 具体产品类 2
class HelloPaper : public Paper {
public:
    void Show() { cout << "Show HelloPaper" << endl;}  
};

class HiPaper : public Paper {
public:
    void Show() { cout << "Show HiPaper" << endl; }
};


// 抽象工厂类
class Factory {
public:
    virtual Book* CreateBook() = 0;
    virtual Paper* CreatePaper() = 0;
    virtual ~Factory() {}
};

// 具体工厂类
class HiFactory : public Factory {
public:
    Book* CreateBook(){return new HiBook();}
    Paper* CreatePaper(){return new HiPaper();}
};

int main(int argc, char const *argv[]) {
    
    Factory *hiFactory = new HiFactory();
    Book* hiBook = hiFactory -> CreateBook();
    Paper* hiPaper = hiFactory -> CreatePaper();
    hiBook -> Show();
    hiPaper -> Show();
    delete hiPaper;
    delete hiBook;
    delete hiFactory;
    
    return 0;
}