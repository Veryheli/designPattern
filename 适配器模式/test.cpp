/**
 * 已经写好的接口不符合目标需求时，将已经写好的接口转化为
 * 符合目标需求的接口
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//已经写好的的接口
struct MyPrint{
    void operator()(int a,int b){
        cout<<a + b<<" ";
    }
};

//需要适配成的目标接口
class Target{
public:
    virtual void operator()(int a) = 0;
};

//写适配器
class Adaptor : public Target{
public:
    Adaptor(int param){
        this->param = param;
    }
    virtual void operator()(int a){
        print(a,param);
    }
private:
    MyPrint print;
    int param;
};

void test(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    //这里不能直接使用适配前的函数对象
    for_each(v.begin(),v.end(),Adaptor(10));
    cout<<endl;
}
int main(){
    test();
    return 0;
}
