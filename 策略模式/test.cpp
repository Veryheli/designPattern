/**
 * 策略模式
 */
#include <iostream>
//武器策略
class Wepon{
public:
    virtual void useWepon() = 0;
    virtual ~Wepon(){}
};
//策略1 飞刀
class Knife : public Wepon{
public:
    Knife(){}
    virtual void useWepon(){
        std::cout << "挥舞小刀" << std::endl;
    }
};
//策略2 Ak47
class Ak47 : public Wepon{
public:
    Ak47(){}
    virtual void useWepon(){
        std::cout << "Ak47 突突突..." << std::endl;
    }
};

//玩家可以选取不同地武器策略
class Player{
public:
    Player(){}
    void setWepon(Wepon* wepon){
        this->wepon  = wepon;
    }
    void fight(){
        wepon->useWepon();
    }
private:
    Wepon* wepon;
};

void test(){
    Wepon* knife = new Knife;
    Wepon* ak  = new Ak47;
    Player* player = new Player;
    player->setWepon(knife);
    player->fight();
    delete knife;
    player->setWepon(ak);
    player->fight();
    delete player;
    delete ak;
}
int main(){
    test();
    return 0;
}
