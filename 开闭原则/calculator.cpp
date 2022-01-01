/**
 * 开闭原则    对拓展开放，对修改关闭
 * 增加功能是通过增加代码来实现的，而不是通过修改源代码实现的
 */
//写一个计算器抽象类
#include <iostream>

class AbstractCalculator{
public:
    virtual int getResult() = 0;
    virtual void setNum(int a,int b){
        this->m_numa = a;
        this->m_numb = b;
    }
protected:
    int m_numa;
    int m_numb;

};
//加法计算机类 继承计算机抽象类
class AddCalculator : public AbstractCalculator{
public:
    AddCalculator(int a,int b){
        setNum(a,b);
    }
    virtual int getResult(){
        return m_numa + m_numb;
    }
};
//减法计算机 继承计算机抽象类
class SubCalculator : public AbstractCalculator{
public:
    SubCalculator(int a,int b){
        setNum(a,b);
    }
    virtual int getResult(){
        return m_numa - m_numb;
    }
};
//乘法计算机 继承计算机抽象类
class MultiCalculator : public AbstractCalculator{
public:
    MultiCalculator(int a,int b){
        setNum(a,b);
    }
    virtual int getResult(){
        return m_numa * m_numb;
    }
};
//除法计算机 继承计算机抽象类
class DevideCalculator : public AbstractCalculator{
public:
    DevideCalculator(int a,int b){
        setNum(a,b);
    }
    virtual int getResult(){
        return m_numa / m_numb;
    }
};
void test(){
    int a = 20;
    int b = 4;
    AddCalculator add(a,b);
    SubCalculator sub(a,b);
    MultiCalculator multi(a,b);
    DevideCalculator devide(a,b);
    std::cout<<" a = 20 , b = 4"<<std::endl;
    std::cout<<" a + b = "<<add.getResult()<<std::endl;
    std::cout<<" a - b = "<<sub.getResult()<<std::endl;
    std::cout<<" a * b = "<<multi.getResult()<<std::endl;
    std::cout<<" a / b = "<<devide.getResult()<<std::endl;
    std::cout<<"\n a = 25 , b = 5"<<std::endl;
    add.setNum(25,5);
    sub.setNum(25,5);
    multi.setNum(25,5);
    devide.setNum(25,5);
    std::cout<<" a + b = "<<add.getResult()<<std::endl;
    std::cout<<" a - b = "<<sub.getResult()<<std::endl;
    std::cout<<" a * b = "<<multi.getResult()<<std::endl;
    std::cout<<" a / b = "<<devide.getResult()<<std::endl;

}
int main(){
    test();
    return 0;
}
