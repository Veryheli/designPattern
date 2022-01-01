/**
 * 观察者模式
 * 观察者模式用于建立一种对象与对象之间的依赖关系，一个
 * 对象发生改变时将自动通知其他对象，其他对象将相应做出
 * 反应。在观察者模式中，发生改变的对象称为观察目标，而
 * 被通知的对象称为观察者，一个观察目标可以对应多个观察
 *
 */
#include <iostream>
#include <list>
using std::list;
/**
 * 观察者基类,观察目标通过调用观察者的update方法类通知观察者
 */
class AbstructObserver{
public:
    virtual void update() = 0;
    virtual ~AbstructObserver(){}
};
/**
 * 具体的观察者
 */

class ObserverA : public AbstructObserver{
public:
    ObserverA(){
        std::cout << "A正在等待..." << std::endl;
    }
    virtual void update(){
        std::cout << "A开始行动..." << std::endl;
    }
};
class ObserverB : public AbstructObserver{
public:
    ObserverB(){
        std::cout << "B正在等待..." << std::endl;
    }
    virtual void update(){
        std::cout << "B开始行动..." << std::endl;
    }
};
class ObserverC : public AbstructObserver{
public:
    ObserverC(){
        std::cout << "C正在等待..." << std::endl;
    }
    virtual void update(){
        std::cout << "C开始行动..." << std::endl;
    }
};
class ObserverD : public AbstructObserver{
public:
    ObserverD(){
        std::cout << "D正在等待..." << std::endl;
    }
    virtual void update(){
        std::cout << "D开始行动..." << std::endl;
    }
};

/**
 * 观察目标类
 */
class Target{
public:
    void addObserver(AbstructObserver* observer){
        observers.push_back(observer);
    }
    void deleteObserver(AbstructObserver* observer){
        observers.remove(observer);
    }
    void notify(){
        for(AbstructObserver* i : observers){
            i->update();
        }
    }
private:
    list<AbstructObserver*> observers;
};
void test(){
    Target* target = new Target;
    AbstructObserver* a  = new ObserverA;
    AbstructObserver* b = new ObserverB;
    AbstructObserver* c = new ObserverC;
    AbstructObserver* d = new ObserverD;
    target->addObserver(a);
    target->addObserver(b);
    target->addObserver(c);
    target->addObserver(d);
    target->notify();
    std::cout << "---------------" << std::endl;
    target->deleteObserver(d);
    target->notify();
    delete target;
    delete a;
    delete b;
    delete c;
    delete d;
}
int main(){
    test();
    return 0;
}
