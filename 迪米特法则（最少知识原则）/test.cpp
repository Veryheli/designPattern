/**
 * 迪米特法则  也叫最少知识法则
 */
#include <iostream>
#include <string>
#include <vector>
using std::string;
//楼盘基类
class AbstractBuilding{
public:
    string quality;
    virtual void sale() = 0;
    virtual ~AbstractBuilding(){
        std::cout<<"抽象楼盘类析构"<<std::endl;
    } ;
};
//楼盘A
class BuildingA : public AbstractBuilding{
public:
    BuildingA(){
        quality = "高品质";
    }
    virtual void sale(){
        std::cout<<"楼盘A "<<quality<<" 被售卖"<<std::endl;
    }
    virtual ~BuildingA(){
        std::cout<<"楼盘A析构"<<std::endl;
    }
private:
};
//楼盘B
class BuildingB : public AbstractBuilding{
public:
    BuildingB (){
        quality = "低品质";
    }
    virtual void sale(){
        std::cout<<"楼盘B "<<quality<<" 被售卖"<<std::endl;
    }
    virtual ~BuildingB(){
        std::cout<<"楼盘B析构"<<std::endl;
    }
private:
};
/** 
 * 中介类，将中介类提供给别人使用,别人可以直接通过中介类来获取想
 * 要的楼盘，而不需要去与BuildingA和BuildingB类打交道
 */
class Mediator{
public:
    Mediator(){
        AbstractBuilding* ba = new BuildingA;
        AbstractBuilding* bb = new BuildingB;
        buildings.push_back(ba);
        buildings.push_back(bb);
    }

    //向用户提供的接口
    AbstractBuilding* getMybuilding(string quality){
        for(auto i : buildings){
            if(i->quality == quality)
                return i;
        }
        return nullptr;
    }
    ~Mediator(){
        for(auto i : buildings){
            if(i != nullptr){
                delete i;
            }
        }
    }
private:
    std::vector<AbstractBuilding*> buildings;
};
void test(){
    string quality = "高品质";
    Mediator med;
    AbstractBuilding* mybuilding = med.getMybuilding(quality);
    if(mybuilding != nullptr){
        mybuilding->sale();
    }else{
        std::cout<<"该质量楼盘不存在！"<<std::endl;
    }
}
int main(){
    test();
    return 0;
}
