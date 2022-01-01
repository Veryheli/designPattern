/**
 * 合成复用原则    继承和组合优先使用组合
 */
#include <iostream>
class AbstructCar{
public:
    virtual void run() = 0;
    virtual ~AbstructCar(){}
};
class CarA : public AbstructCar{
public:
    CarA(){}
    virtual void run(){
        std::cout<<"玛莎拉蒂启动"<<std::endl;
    }
};
class CarB : public AbstructCar{
public:
    CarB(){}
    virtual void run(){
        std::cout<<"拖拉机启动"<<std::endl;
    }
};
class Person{
public:
    Person(){}
    void drive(AbstructCar* car){
        car->run();
    }
};
void test(){
    AbstructCar* cara = new CarA;
    Person *p  =new Person;
    p->drive(cara);
    delete cara;
    delete p;
}
int main(){
    test();
    return 0;
}
