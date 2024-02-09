package lab_3_req_ex_1;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    parameters:
        int N;
    @display("bgb=656,322");
    submodules:
        hub: Hub;
        nodes[N]: Node;
    connections:
        for i=0..N-1 {
            hub.port++ <--> nodes[i].port;
        }
}

