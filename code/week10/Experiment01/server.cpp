#include <omnetpp.h>

class server: public omnetpp::cSimpleModule{                  
    omnetpp::cMessage *msg;
    virtual void initialize();                                // cComponent의 function, server의 simulation 시작동작 정의
    virtual void handleMessage(omnetpp::cMessage *msg);       // server module에서 msg를 받고나서 msg 전송의 동작 정의
};

Define_Module(server);
void server::initialize(){}                                   // simulation 시작동작은 client에서 정의됨 
                                                              // server의 동작은 client에서 보낸 msg를 다시 보내는것
void server::handleMessage(omnetpp::cMessage *msg){
    msg = new omnetpp::cMessage("frame");                     // name이 frame인 메세지 생성 
    cModule *target = getParentModule() -> getSubmodule("laptop"); // laptop 이라는 module을 target으로 설정
    sendDirect(msg, target, "radioIn");                       // gate를 거치지 않고  target으로 직접 message를 전송
}