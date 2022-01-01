/**
 * 模板方法模式
 * 优点：
 *      1. 在父类中形式化地定义一个算法，而由它的子类来实现
 *      细节地处理，在子类实现详细地处理算法时并不会改变算
 *      法中步骤地执行次序
 *      2. 模板方法模式是一种代码复用技术，它在类库设计中尤
 *      为重要，它提取了类库中地公共行为，将公共行为放在父
 *      类中，而通过其子类来实现不同地行为，它鼓励我们恰当
 *      使用继承关系来复用代码
 *      3. 可实现一种反向控制结构，通过子类覆盖父类地方法来
 *      决定某一特定步骤是否需要执行
 *      4. 在模板方法模式中可以通过子类来覆盖父类中地基本方
 *      法，不同的子类可以提供基本方法地不同实现，更换和增
 *      加心得子类很方便，符合单一职责原则和开闭原则
 */
#include <iostream>
class DrinkTemplate{
protected:
    virtual void boidWater() = 0;//煮水
    virtual void brew() = 0;//冲泡
    virtual void pourInCup() = 0;//倒入杯中
    virtual void addSomething() = 0;//添加一些调料
public:
    virtual void make(){
        this->boidWater();
        this->brew();
        this->pourInCup();
        this->addSomething();
    }
    virtual ~DrinkTemplate(){}
};
class DrinkTea : public DrinkTemplate{
public:
    DrinkTea(){}
protected:
    virtual void boidWater(){
        std::cout << "煮水" << std::endl;
    }
    virtual void brew(){
        std::cout << "冲泡茶叶" << std::endl;
    }
    virtual void pourInCup(){
        std::cout << "将茶倒入杯中" << std::endl;
    }
    virtual void addSomething(){
        std::cout << "添加柠檬" << std::endl;
    }
};
class DrinkCoffee : public DrinkTemplate{
public:
    DrinkCoffee(){}
protected:
    virtual void boidWater(){
        std::cout << "煮水" << std::endl;
    }
    virtual void brew(){
        std::cout << "冲泡咖啡" << std::endl;
    }
    virtual void pourInCup(){
        std::cout << "将咖啡倒入杯中" << std::endl;
    }
    virtual void addSomething(){
        std::cout << "添加牛奶和糖" << std::endl;
    }
};
void test(){
    DrinkTea* drinktea = new DrinkTea;
    DrinkCoffee* drinkcoffee = new DrinkCoffee;
    drinktea->make();
    drinkcoffee->make();
    delete drinktea;
    delete drinkcoffee;
}
int main(){
    test();
    return 0;
}
