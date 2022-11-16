#include <omnetpp.h>
                                // 코드와 함수의 설명은 무선연결을 가정한 Experiment 1의 client와 동일하여 생략하고 flow만 언급한다.
class client : public omnetpp::cSimpleModule{
    omnetpp::cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(omnetpp::cMessage *msg);
};

Define_Module(client);                          // simulation은 client에서 initial message를 보내는것으로 시작된다. 
void client::initialize(){                      // initialize 동작으로 self message를 random한 시간에서 보내는것으로 시작한다.
    EV << "client initialize"<< "\n";
    msg = new omnetpp::cMessage("frame");
    scheduleAt(omnetpp::simTime() + dblrand(), msg->dup());
    EV << "client initialize complete"<< "\n";
}

void client::handleMessage(omnetpp::cMessage *msg)
{
    EV << "client handle message initialize" << "\n";
    cModule *target;
    msg = new omnetpp::cMessage("frame");      // simulation이 시작될때 initialize에서 생성되어 보내진 self - msg를 client가 수신하고 
    target = getParentModule()->getSubmodule("AP2");       
    sendDirect(msg, target, "radioIn");        // handleMessage 동작으로 AP2 모듈에 "frame" msg를 랜덤한 시간 사이에서 직접 전송한다. 
}