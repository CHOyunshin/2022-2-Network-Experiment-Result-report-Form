#include <string.h>
#include <omnetpp.h>
using namespace omnetpp;
// Experiment 1 에서는 gate를 거치지 않고 바로 tatget의 모듈을 받아 msg를 전송했다. 
// Experiment 2 에서는 각 모듈의 gate의 in & out을 .NED에서 정의해주고 이를 같은 namespace를 공유하는 package상의 
// cSimpleModule의 subclass 상에서 msg 전송과 관련된 gate의 parameter들을 override 해서 각 모듈의 동작을 정의해준다.

class tictoc : public cSimpleModule
{
	protected:
		virtual void initialize() override;
		virtual void handleMessage(cMessage *msg) override;
};

Define_Module(tictoc);

void tictoc::initialize()
{                                             // strcmp 로 2 string을 비교해 동일할때 0을 return
	if (strcmp("tic", getName()) == 0) {  //simulation이 시작되고 들어오는 submodule의 이름이 tic일때
		cMessage *msg = new cMessage("tictocMsg");
		send(msg, "out");             // tic.out의 gate에서 message를 전송한다.
	}
}
void tictoc::handleMessage(cMessage *msg)     // handlemessage는 msg를 수신한 module의 동작을 정의 
{                                         
	send(msg, "out");                     // 수신받은 msg를 out gate로 전송한다. 이때의 connection은
}                                         /aa/ Network2.ned에서 정의