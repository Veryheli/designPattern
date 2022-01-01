/**
 * 抽象工厂模式    
 *     抽象工厂模式针对的是产品族，不针对产品等级结构
 *     产品族：同一产地或同一厂商，功能不同
 *     产品等级结构：功能相同，产地或厂商不同
 */
#include <iostream>
#include <string>
using std::string;
//抽象水果类
class Fruit{
public:
    virtual ~Fruit(){}
};
//抽象苹果类
class AbstructApple : public Fruit{
public:
    virtual void showApple() = 0;
    virtual ~AbstructApple(){};
};
//抽象香蕉类
class AbstructBanana : public Fruit{
public:
    virtual void showBanana() = 0;
    virtual ~AbstructBanana(){}
};
//抽象梨类
class AbstructPear : public Fruit{
public:
    virtual void showPear() = 0;
    virtual ~AbstructPear(){}
};
//抽象工厂类
class Factory{
public:
    virtual Fruit* createFruit(string fruitname) = 0;
    virtual ~Factory(){}
};
//具体水果类
//---------------------------中国水果类-----------------------
class ChinaApple : public AbstructApple{
public:
    virtual void showApple(){
        std::cout<<"中国苹果"<<std::endl;
    }
};
class ChinaBanana : public AbstructBanana{
public:
    virtual void showBanana(){
        std::cout << "中国香蕉" << std::endl;
    }
};
class ChinaPear : public AbstructPear{
public:
    virtual void showPear(){
        std::cout << "中国水梨" << std::endl;
    }
};
//---------------------------美国水果类-----------------------
class AmericaApple : public AbstructApple{
public:
    virtual void showApple(){
        std::cout<<"美国苹果"<<std::endl;
    }
};
class AmericaBanana : public AbstructBanana{
public:
    virtual void showBanana(){
        std::cout << "美国香蕉" << std::endl;
    }
};
class AmericaPear : public AbstructPear{
public:
    virtual void showPear(){
        std::cout << "美国水梨" << std::endl;
    }
};
//---------------------------日本水果类-----------------------
class JapanApple : public AbstructApple{
public:
    virtual void showApple(){
        std::cout<<"日本苹果"<<std::endl;
    }
};
class JapanBanana : public AbstructBanana{
public:
    virtual void showBanana(){
        std::cout << "日本香蕉" << std::endl;
    }
};
class JapanPear : public AbstructPear{
public:
    virtual void showPear(){
        std::cout << "日本水梨" << std::endl;
    }
};
//中国水果工厂
class ChinaFactory : public Factory{
public:
    ChinaFactory(){}
    virtual Fruit* createFruit(string fruitname){
        if(fruitname == "apple"){
            return new ChinaApple;
        }else if(fruitname == "banana"){
            return new ChinaBanana;
        }else if(fruitname == "pear"){
            return new ChinaPear;
        }else{
            return nullptr;
        }
    }
};
class AmericaFactory : public Factory{
public:
    AmericaFactory(){}
    virtual Fruit* createFruit(string fruitname){
        if(fruitname == "apple"){
            return new AmericaApple;
        }else if(fruitname == "banana"){
            return new AmericaBanana;
        }else if(fruitname == "pear"){
            return new AmericaPear;
        }else{
            return nullptr;
        }
    }
};
class JapanFactory : public Factory{
public:
    JapanFactory(){}
    virtual Fruit* createFruit(string fruitname){
        if(fruitname == "apple"){
            return new JapanApple;
        }else if(fruitname == "banana"){
            return new JapanBanana;
        }else if(fruitname == "pear"){
            return new JapanPear;
        }else{
            return nullptr;
        }
    }
};
void test(){
    Factory* factory = new JapanFactory;
    Fruit* fruit = factory->createFruit("pear");
    reinterpret_cast<AbstructPear*>(fruit)->showPear();
    delete factory;
    delete fruit;
}
int main(){
    test();
    return 0;
}
