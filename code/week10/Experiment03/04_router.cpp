#include <string.h>
#include <omnetpp.h>
                        // 코드와 함수의 설명은 유선연결을 가정한 Experiment 2의 tictoc과 동일하여 생략하고 flow만 언급한다.
using namespace omnetpp;

class router : public cSimpleModule{
    protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(router);                  // 각 AP1, AP2를 처리하기 위해서  out1, out2 gate를 가지는 router 생성
                                        // in gate는 1개만 사용하고 message의 parent module을 확인하여
void router::initialize(){}             // 수신한 msg의 송신 module이 AP2 이면 router.out1 gate, AP2 이면 router.out2 
                                        // gate에서 msg를 전달한다. connection은 Network3.ned 에서 정의해 주었다.
void router::handleMessage(cMessage *msg){
    if (msg->getSenderModule() == getParentModule()->getSubmodule("AP2")){
        send(msg, "out1");
    }
    if (msg->getSenderModule() == getParentModule()->getSubmodule("AP1")){
        send(msg, "out2");
    }
}