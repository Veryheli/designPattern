/**
 * 单例模式    系统中只有一个对象
 * 实现单例的步骤：
 *     1. 构造函数私有化
 *     2. 增加静态私有的指向当前类的指针
 *     3. 对外提供静态接口访问唯一实例化对象
 *  单例模式分为懒汉式和饿汉式
 *
 *  单例的释放问题：
 *      程序中只有一个堆区的实例化对象，内存不会溢出,在程序推出时自动释放所有资源，
 *      因此没有必要手动管理单例的释放
 */

/**
 * 懒汉式    
 * 只有在第一次使用时才创建对象
 *
 * 懒汉式在多线程中是线程不安全的，可能多个线程同时判断到instace == nullptr,然后都创建了对象，这就不是单例了
 * 饿汉式不存在这样的问题
 */
#include <iostream>
class Lazzy{
public:
    static Lazzy* getInstance(){
        if(instance == nullptr){
            instance = new Lazzy;
        }
        return instance;
    }
private:
    Lazzy(){}
    static Lazzy* instance;
};
//类外初始化时不要创建对象
Lazzy* Lazzy::instance = nullptr;

/**
 * 饿汉式    
 * 在初始化时就已经创建对象
 */
class Hungry{
public:
    static Hungry* getInstance(){
        return instance;
    }
private:
    Hungry(){};
    static Hungry* instance;
};
//类外初始化时创建对象
Hungry* Hungry::instance = new Hungry;
void test(){
    Lazzy* pl1= Lazzy::getInstance();
    Lazzy* pl2= Lazzy::getInstance();
    if(pl1 == pl2){
        std::cout << "两个指针指向同一块内存，是单例" << std::endl;
    }else{
        std::cout << "不是单例" << std::endl;
    }
    Hungry* ph1 = Hungry::getInstance();
    Hungry* ph2 = Hungry::getInstance();
    if(ph1 == ph2){
        std::cout << "两个指针指向同一块内存，是单例" << std::endl;
    }else{
        std::cout << "不是单例" << std::endl;
    }
}
int main(){
    test();
    return 0;
}
