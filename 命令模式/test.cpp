/**
 * 命令模式:
 *     将一个请求封装为一个对象，从而让我们可用不同的请求对
 *     客户进行参数化;对请求排队或者记录请求日志，以及支持
 *     可撤销的操作。命令模式是一种对象行为模式模式，其别名
 *     为动作（Action）模式或事务（Transaction）模式。
 *
 *     命令模式可以将请求发送者和接收者完全解耦，发送者与接收
 *     者之间没有直接引用关系，发送请求的对象只需要知道如何发
 *     送请求，而不不知道如何完成请求
 */

#include <iostream>
#include <queue>
using std::queue;
/**
 * 服务器处理客户端的请求，将这些请求封装成类
 */

/**
 * 处理客户端请求协议的类
 */
class ClientHandleProtocol{
public:
    void addMoney(){
         std::cout << "增加金钱请求" << std::endl;
    }
    void addDiomand(){
        std::cout << "增加钻石请求" << std::endl;
    }
    void addEquipment(){
        std::cout << "增加装备请求" << std::endl;
    }
};

/**
 * 处理命令的基类
 */
class Command{
public:
    virtual void handle() = 0;
    virtual ~Command(){}
protected:
    ClientHandleProtocol* protocol;
};
/**
 * 处理具体命令的类
 */
class AddMoneyCommand : public Command{
public:
    AddMoneyCommand(ClientHandleProtocol* protocol){
        this->protocol = protocol;
    }
    virtual void handle(){
        protocol->addMoney();
    }
};
class AddDiamondCommand : public Command{
public:
    AddDiamondCommand(ClientHandleProtocol* protocol){
        this->protocol = protocol;
    }
    virtual void handle(){
        protocol->addDiomand();
    }
};
class AddEquipment : public Command{
public:
    AddEquipment(ClientHandleProtocol* protocol){
        this->protocol = protocol;
    }
    virtual void handle(){
        protocol->addEquipment();
    }
};

//服务端类
class Server{
public:
    void addCommand(Command* command){
        commands.push(command);
    }
    void startCommand(){
        while(!commands.empty()){
            commands.front()->handle();
            commands.pop();
        }
    }
private:
    queue<Command*> commands;
};
void test(){
    ClientHandleProtocol* protocol = new ClientHandleProtocol;
    Server* server = new Server;
    Command* addmoney = new AddMoneyCommand(protocol);
    Command* adddiomand = new AddDiamondCommand(protocol);
    Command* addequipment = new AddEquipment(protocol);
    server->addCommand(adddiomand);
    server->addCommand(addmoney);
    server->addCommand(addequipment);
    server->addCommand(addequipment);
    server->startCommand();
    delete protocol;
    delete server;
    delete addmoney;
    delete adddiomand;
    delete addequipment;
}
int main(){
    test();
    return 0;
}
