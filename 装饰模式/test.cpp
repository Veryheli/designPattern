#include <iostream>
/**
 * 装饰模式
 * 装饰模式又叫包装模式，通过对客户端透明的方式来扩展功
 * 能，时继承关系的一种替代。
 * 装饰模式就是把要附加的功能分别放在单独的类中，并让这
 * 个类包含它要装饰的对象，当需要执行时，客户端就可以有
 * 选择的、按顺序的使用装饰功能包装对象。
 * 需要注意的是，装饰之后不改变原本的性质，假如原来是个
 * 人物，那么加上装饰器之后就还是个人物
 */

/**
 * 人物的基类
 */
class Charactor{
public:
    virtual ~Charactor(){}
    virtual void showStatus() = 0;
    int atk;
    int dfc;
};
//英雄类
class Hero : public Charactor{
public:
    Hero(){
        atk = 1;
        dfc = 1;
    }
    virtual void showStatus(){
        std::cout << "攻击力："<< atk << std::endl;
        std::cout << "防御力："<< dfc << std::endl;
    }
};
/**
 * 装饰器基类 
 * 装饰器也要继承他所装饰的对象的基类，因为被装饰器装饰的对象的性质不变
 */
class Equipment :public Charactor{
public:
    Equipment(Charactor* hero){
        this->phero = hero;
    }
    virtual void showStatus(){} //基类有该方法，但是我们可以不去实现，留给子类去实现
protected:
    Charactor* phero;
};

//装备 皮衣 的装饰器
class Clothe : public Equipment{
public:
    Clothe(Charactor* hero) : Equipment(hero){//调用基类构造函数
        equipChothe();
    } 
    virtual void showStatus(){
        std::cout << "攻击力："<< atk << std::endl;
        std::cout << "防御力："<< dfc << std::endl;
    }
protected:
    void equipChothe(){
        atk = phero->atk;
        dfc = phero->dfc + 20;
        delete phero;
    }
};

//装备 小刀 的装饰器
class Knife : public Equipment{
public:
    Knife(Charactor* hero) : Equipment(hero){
        equipKnife();
    }
    virtual void showStatus(){
        std::cout << "攻击力："<< atk << std::endl;
        std::cout << "防御力："<< dfc << std::endl;
    }
protected:
    void equipKnife(){
        atk = phero->atk + 80;
        dfc = phero->dfc;
        delete phero;
    }
};

void test(){
    Charactor* hero = new Hero;
    hero->showStatus();
    std::cout << "====装备衣服后=========" << std::endl;
    hero = new Clothe(hero);
    hero->showStatus();
    std::cout << "====装备小刀后=========" << std::endl;
    hero = new Knife(hero);
    hero->showStatus();
}
int main(){
    test();
    return 0;
}
