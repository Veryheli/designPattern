
/**
 * 工厂方法模式 = 简单工厂模式 + 开闭原则    在简单工厂模式基础之上满足了开闭原则
 * 优点：1. 满足开闭原则
 *       2. 不需要记住具体的类名，甚至连参数都不需要记
 *       3. 实现了对象的创建和使用的分离
 *       4. 系统的可拓展性提高，不需要修改接口和原类
 *       
 * 缺点：1. 类的个数成倍增加，维护成本更高,增加了系统的抽象性，理解难度和复杂程度增加
 *       2. 创造类的时候需要客户端自己判断需要创造一个什么样的类，而简单工厂模式在工厂类中进行了判断
 * 使用场景：1. 客户端不需要知道他所需要的对象的类
 *           2. 抽象工厂类通过其子类来指定创建哪个对象
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
    virtual Fruit* create() = 0;
    virtual ~Factory(){};
};
//专门生产apple的工厂
class AppleFactory : public Factory{
public:
    AppleFactory(){};
    virtual Fruit* create(){
        return new Apple;
    }
};
//专门生产banana的工厂
class BananaFactory : public Factory{
public:
    BananaFactory(){};
    virtual Fruit* create(){
        return new Banana;
    }
};
//专门生产Pear的工厂
class PearFactory : public Factory{
public:
    PearFactory(){};
    virtual Fruit* create(){
        return new Pear;
    }
};
void test(){
    Factory* applefactory= new AppleFactory;
    Factory* bananafactory = new BananaFactory;
    Factory* pearfactory = new PearFactory;
    Fruit* apple = applefactory->create();
    Fruit* banaba = bananafactory->create();
    Fruit* pear = pearfactory->create();
    apple->showName();
    banaba->showName();
    pear->showName();
    delete applefactory;
    delete bananafactory;
    delete pearfactory;
    delete apple;
    delete pear;
    delete banaba;
}
int main(){
    test();
    return 0;
}
