simple AP{                              // 각 source file에서 override할 structure를 선언
    @display("i=device/accesspoint");   // Experiment 1, 2의 유선 문선 구현방법을 반영해
    gates:                              // Experiment2의 AP 와 router 사이의 유선 환경을 connection으로 구성해 주었다.
        input in;
        input radioIn @directIn;        // NED file에서는 크게 parameter와 gate의 module의 structure의 선언과
        output out;                     // 각 module의 gate간의 connection을 설정해 준다. 
}                                       // 각 module에서 msg를 수신시 gate의 출력 관련한 동작은 source code에서 구성한다.
                                        
simple client{
    @display("i=device/wifilaptop");
    gates:
        input radioIn @directIn;
}

simple router{                                  
    @display("i=device/accesspoint");
    gates:
        input in1;
        input in2;
        output out1;
        output out2;
}

simple server{
    @display("i=device/wifilaptop");
    gates:
        input radioIn @directIn;
}

network Network3
{
    submodules:
        server: server {
            @display("p=server_ip");
        }
        client: client {
            @display("p=client_ip");
        }
        AP1: AP {
            @display("i=device/accesspoint;p=AP1_ip");
        }
        AP2: AP {
            @display("i=device/accesspoint;p=AP2_ip");
        }
        router: router {
            @display("i=device/router;p=router_ip");
        }

    connections:                        // AP와 router의 gate간의 유선연결에 100ms 의 delay를 설정해주었다. 
        AP2.out --> {  delay = 100ms; } --> router.in2;
        router.out1 --> {  delay = 100ms; } --> AP1.in;
        AP1.out --> {  delay = 100ms; } --> router.in1;       
        router.out2 --> {  delay = 100ms; } --> AP2.in;
}