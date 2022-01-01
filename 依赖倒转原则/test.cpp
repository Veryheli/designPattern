/**
 * 顶层业务逻辑和中间业务逻辑都依赖于抽象层
 */
#include <iostream>
//抽象层
class AbstructWorker{
public:
    virtual void doWork() = 0;
    virtual ~AbstructWorker(){}
};
//实现层
class SaveBankWorker : public AbstructWorker{
public:
    SaveBankWorker(){}
    virtual void doWork(){
        std::cout << "办理存款业务..." << std::endl;
    }
};
class TransferBankWorker : public AbstructWorker{
public:
    TransferBankWorker(){}
    virtual void doWork(){
        std::cout << "办理转账业务..." << std::endl;
    }
};
class WithdrawBankWorker : public AbstructWorker{
public:
    WithdrawBankWorker(){}
    virtual void doWork(){
        std::cout << "办理取款业务..." << std::endl;
    }
};
//中间层
class DoWork{
public:
    DoWork(){}
    void startWork(AbstructWorker* worker){
        worker->doWork();
    }
};
//顶层业务逻辑
void test(){
    AbstructWorker* worker = new WithdrawBankWorker;
    DoWork* doer = new DoWork;
    doer->startWork(worker);
    delete worker;
    delete doer;
}
int main(){
    test();
    return 0;
}
