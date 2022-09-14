#include <iostream>
using namespace std;
#include <memory> // C++11 shared_ptr头文件
#include <mutex>  // C++11 mutex头文件
/*
*	版本2 SingletonPattern_V2 解决了V1中的问题
*
*	1. 通过加锁让线程安全了
*	2. 通过智能指针(shareptr 基于引用计数)内存没有泄露了
*/
class SingletonPattern_V2 
{
public:
	~SingletonPattern_V2() {
		std::cout << "destructor called!" << std::endl;
	}
	SingletonPattern_V2(SingletonPattern_V2&) = delete;
	SingletonPattern_V2& operator=(const SingletonPattern_V2&) = delete;
 
	//在这里实例化
	static std::shared_ptr<SingletonPattern_V2> Instance() 
	{
		//双重检查锁
		if (m_pInstance == nullptr) {
			std::lock_guard<std::mutex> lk(m_mutex);
			if (m_pInstance == nullptr) {
				m_pInstance = std::shared_ptr<SingletonPattern_V2>(new SingletonPattern_V2());
			}
		}
		return m_pInstance;
	}
 
private:
	SingletonPattern_V2() {
		std::cout << "constructor called!" << std::endl;
	}
	static std::shared_ptr<SingletonPattern_V2> m_pInstance;
	static std::mutex m_mutex;
};
 
//在类外初始化静态变量
std::shared_ptr<SingletonPattern_V2> SingletonPattern_V2::m_pInstance = nullptr;
std::mutex SingletonPattern_V2::m_mutex;
 
int main()
{
	std::shared_ptr<SingletonPattern_V2> p1 = SingletonPattern_V2::Instance();
	std::shared_ptr<SingletonPattern_V2> p2 = SingletonPattern_V2::Instance();
 
	// system("pause");
	return 0;
}