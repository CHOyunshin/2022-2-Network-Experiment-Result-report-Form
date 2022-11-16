#include <string.h>
#include <omnetpp.h>
                                // 코드와 함수의 설명은 유선연결을 가정한 Experiment 2의 tictoc과 동일하여 생략하고 flow만 언급한다.
using namespace omnetpp;

class AP : public cSimpleModule{
    protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(AP);                              // tic 과 toc과 같이 AP1, AP2의 module을 정의한다. 
void AP::initialize(){}                         // simulation이 시작되면 client에서 frame을 보내오기에 별도 동작정의할 필요 x

void AP::handleMessage(cMessage *msg){          // handlemessage가 수신받은 message의 parameter를 받음  
    if (strcmp("AP1", getName()) == 0)          // out gate 1개에서 AP1, AP2 각각 message를 받고 동작을 작성
    {                                               
        if (msg->getSenderModule() == getParentModule()->getSubmodule("router"))
        {                                       // AP1 은 router에서 전송된 msg를 그대로 server로 전송한다.
            cModule *target = getParentModule()->getSubmodule("server");
            sendDirect(msg, target, "radioIn"); // server는 무선연결을 가정하고, 별도의 gate가 없기 때문에 직접 module로 msg 전송
        } 
        if (msg->getSenderModule() == getParentModule()->getSubmodule("server"))
        {                                       // 무선 연결인 server로 부터 gate가 아닌 직접 moudle로 message가 온다면 
            send(msg, "out");                   // AP1.out gate 에서 메세지가 전송된다.
        }                                       // 이때 AP1.out gate의 connection은 Network3.ned에서 정의해 준다.
    }
    else if (strcmp("AP2", getName()) == 0){     
        if (msg->getSenderModule() == getParentModule()->getSubmodule("router"))
        {                                       // AP2 는 router에서 전송된 msg를 그대로 client에 전송한다.
            cModule *target = getParentModule()->getSubmodule("client");
            sendDirect(msg, target, "radioIn"); // client는 무선연결을 가정하고, 별도의 gate가 없기 때문에 직접 module로 msg 전송
        }
        if (msg->getSenderModule() == getParentModule()->getSubmodule("client"))
        {                                       // 무선 연결인 client로 부터 gate가 아닌 직접 moudle로 message가 온다면 
            send(msg, "out");                   // AP2.out gate 에서 메세지가 전송된다.
        }                                       // 이때 AP1.out gate의 connection은 Network3.ned에서 정의해 준다.
    }
}