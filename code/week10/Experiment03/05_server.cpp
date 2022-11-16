#include <omnetpp.h>
                                    // 코드와 함수의 설명은 Experiment 1의 server와 동일하여 생략하고 flow만 언급한다.
class server : public omnetpp::cSimpleModule{
    omnetpp::cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(omnetpp::cMessage *msg);
};

Define_Module(server);
void server::initialize(){}

void server::handleMessage(omnetpp::cMessage *msg){ // 재전송이라는 의미에서 받은 msg 를 그대로 보낼지 고민하다 Experiment1과
    msg = new omnetpp::cMessage("frame");           // 동일하게client server 의 관계를 고려하여 client에 요청에 따른 msg를
    cModule *target = getParentModule()->getSubmodule("AP1"); // 전송한다는 취지에서 새로운 frame msg 생성
    sendDirect(msg, target, "radioIn");             // 무선연결을 가정하에 AP2로 gate 없이 직접 AP1 module로 msg 전송
}