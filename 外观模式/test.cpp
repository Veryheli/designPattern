/**
 * 外观模式就是将复杂的子类系统抽象到同一个接口进行管理，外界
 * 只需要通过此接口与子类系统进行交互，而不必直接与复杂的子类
 * 系统进行交互
 */
#include <iostream>
class Electrical{
public:
    virtual void On() = 0;
    virtual ~Electrical(){}
};

class Television : public Electrical{
public:
    Television(){}
    virtual void On(){
        std::cout << "电视打开" << std::endl;
    }
    virtual void Off(){
        std::cout << "电视关闭" << std::endl;
    }
};

class Light : public Electrical{
public:
    Light(){}
    virtual void On(){
        std::cout << "灯打开" << std::endl;
    }
    virtual void Off(){
        std::cout << "灯关闭" << std::endl;
    }
};
class Game : public Electrical{
public:
    Game(){}
    virtual void On(){
        std::cout << "游戏机打开" << std::endl;
    }
    virtual void Off(){
        std::cout << "游戏机关闭" << std::endl;
    }
};

class Dvd : public Electrical{
public:
    Dvd(){}
    virtual void On(){
        std::cout << "DVD打开" << std::endl;
    }
    virtual void Off(){
        std::cout << "DVD关闭" << std::endl;
    }
};

class Audio : public Electrical{
public:
    Audio(){}
    virtual void On(){
        std::cout << "音响打开" << std::endl;
    }
    virtual void Off(){
        std::cout << "音响关闭" << std::endl;
    }
};

class Microphone : Electrical{
public:
    Microphone(){}
    virtual void On(){
        std::cout << "麦克风打开" << std::endl;
    }
    virtual void Off(){
        std::cout << "麦克风关闭" << std::endl;
    }
};
class KtvMode{
private:
    Television* tel;
    Light* light;
    Dvd* dvd;
    Audio* audio;
    Microphone* microphone;
public:
    KtvMode(){
        tel = new Television;
        light = new Light;
        dvd = new Dvd;
        audio = new Audio;
        microphone = new Microphone;
    }
    void On(){
        std::cout << "开启KTV模式...." << std::endl;
        tel->On();
        light->Off();
        dvd->On();
        audio->On();
        microphone->On();
    }
    void Off(){
        std::cout << "关闭KTV模式...." << std::endl;
        tel->Off();
        light->On();
        dvd->Off();
        audio->Off();
        microphone->Off();
    }
    ~KtvMode(){
        if(tel != nullptr)
            delete tel;
        if(light != nullptr)
            delete light;
        if(dvd != nullptr)
            delete dvd;
        if(audio != nullptr)
            delete audio;
        if(microphone != nullptr)
            delete microphone;
    }

};
class GameMode{
private:
    Television* tel;
    Game* game;
    Audio* audio;
public:
    GameMode(){
        tel = new Television;
        game = new Game;
        audio = new Audio;
    }
    void On(){
        std::cout << "打开游戏模式...." << std::endl;
        tel->On();
        game->On();
        audio->On();
    }
    void Off(){
        std::cout << "关闭游戏模式...." << std::endl;
        tel->Off();
        game->Off();
        audio->Off();
    }
    ~GameMode(){
        if(tel != nullptr){
            delete tel;
        }
        if(game != nullptr){
            delete game;
        }
        if(audio != nullptr){
            delete audio;
        }
    }
};


void test(){
    KtvMode *ktvmode = new KtvMode;
    std::cout << "--------------ktv模式----------------" << std::endl;
    ktvmode->On();
    ktvmode->Off();
    std::cout << "--------------游戏模式----------------" << std::endl;
    GameMode* gamemode = new GameMode;
    gamemode->On();
    gamemode->Off();
    delete ktvmode;
    delete gamemode;
}
int main(){
    test();
    return 0;
}
