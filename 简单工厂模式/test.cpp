/**
 * 简单工厂模式    自己不创建对象，将创建对象的任务交给工厂实现
 * 优点：1. 客户端不与要创建对象，与这些类解耦
 *       2. 对于某些创建过程很复杂的类，我们不需要自己考虑，交给工厂考虑
 * 缺点：1. 类的责任太大,如果该类出现问题，很多使用该类的业务都会受到影响
 *       2. 增加功能需要修改源代码，不符合开闭原则
 * 使用场景：1. 工厂需要创建的对象数量较少，由于创建的对象少，不会造成工厂中的业务逻辑太过复杂
 *           2. 客户只知道传入工厂的参数，对于如何创建对象并不关心
 */
#include <iostream>
#include <string>
using std::string;
class Fruit{
public:
    virtual void showName() = 0;
    virtual ~Fruit(){}
};

class Apple : public Fruit{
public:
    Apple(){}
    virtual void showName(){
        std::cout << "Apple" << std::endl;
    }
};
class Banana : public Fruit{
public:
    Banana(){}
    virtual void showName(){
        std::cout << "Banana" << std::endl;
    }
};
class Pear : public Fruit{
public:
    Pear(){}
    virtual void showName(){
        std::cout << "Pear" << std::endl;
    }
};
//负责生产水果的工厂类
class Factory{
public:
    Factory(){}
    Fruit * creatrFruit(string name){
        if(name == "Apple"){
            return new Apple;
        }else if(name == "Banana"){
            return new Banana;
        }else if(name == "Pear"){
            return new Pear;
        }else{
            return nullptr;
        }
    }
};
void test(){
    Factory* factory = new Factory;
    Fruit* apple = factory->creatrFruit("Apple");
    Fruit* banaba = factory->creatrFruit("Banana");
    Fruit* pear = factory->creatrFruit("Pear");
    apple->showName();
    banaba->showName();
    pear->showName();
    delete factory;
    delete apple;
    delete pear;
    delete banaba;
}
int main(){
    test();
    return 0;
}
