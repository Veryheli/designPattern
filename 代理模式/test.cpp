/**
 * 代理模式为其他对象提供一种代理以控制这种对象的访问。在某些情况下一个
 * 对象不适合或者不能直接引用另一个对象，而代理对象可以在客户端和目标对
 * 象之间起到中介的作用
 */
#include <iostream>
#include <string>
using std::string;
/**
 * 公共接口类
 */
class Interface{
public:
    virtual void run() = 0;
    virtual ~Interface(){}
};
/**
 * 自己写好的实现类,但是不希望所有人都能访问
 */
class MySystem : public Interface{
public:
    MySystem(){}
    virtual void run(){
        std::cout << "系统启动..." << std::endl;
    }
};
/**
 * 向用户提供代理类 代理类，通过验证才能访问MySystem
 * 代理类也要继承自Interface
 */
class MyProxy : Interface{
public:
    explicit MyProxy(string username,string passwd){
        this->username = username;
        this->passwd = passwd;
        system = new MySystem;
    }
    virtual void run(){
        if(checkPassword()){
            std::cout << "验证通过" << std::endl;
            system->run();
        }else{
            std::cout << "用户名或密码错误" << std::endl;
        }
    }
    ~MyProxy(){
        if(system != nullptr){
            delete system;
        }
    }
private:
    MySystem* system;
    string username;
    string passwd;
    bool checkPassword(){
        if(username == "admin" and passwd == "123456"){
            return true;
        }
        return false;
    }
};
void test(){
    string username = "admin";
    string passwd = "123456";
    MyProxy* proxy = new MyProxy(username,passwd);
    proxy->run();
    delete proxy;
}
int main(){
    test();
    return 0;
}
