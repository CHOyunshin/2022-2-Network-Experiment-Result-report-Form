#include <omnetpp.h>

class client: public omnetpp::cSimpleModule{
    omnetpp::cMessage *msg;
    virtual void initialize();                                // cComponent의 function, client의 simulation 시작동작 정의 
    virtual void handleMessage(omnetpp::cMessage *msg);       // client module에서 msg를 받고나서 msg 전송의 동작 정의
};

Define_Module(client);
void client::initialize(){                                    
    EV <<"client initialize"<<"\n";
    msg = new omnetpp::cMessage("frame");                     // name 이 frame인 메세지 생성
    scheduleAt(omnetpp::simTime() + dblrand(), msg -> dup()); // 랜덤한 시간이후 schedule at을 이용해 self-message 전송
    EV <<"client initialize complete"<<"\n";            
}

void client::handleMessage(omnetpp::cMessage *msg){           // message(self-message 포함)를 받았을때의 동작 정의
    EV <<"client handle message initialize"<<"\n";
    cModule *target;
    msg = new omnetpp::cMessage("frame");
    target = getParentModule() -> getSubmodule("AP");         // AP 이라는 이름의 module을 target으로 설정
    sendDirect(msg, target,'radioIn');                        // gate를 거치지 않고 target으로 직접 messsage 전송
    scheduleAt(omnetpp::simTime() + dblrand(), msg -> dup()); // self-message와 동일하게 랜덤한 시간이후 메세지 전송
}

