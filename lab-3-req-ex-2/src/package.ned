package lab_3_req_ex_2;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    parameters:
        int N;

        @display("bgb=410,178");
    submodules:
        nodes[N]: Node;
    connections:
        for i=0..N-1 {
            nodes[i].port++ <--> nodes[i+1].port++ if i < N-1;
            nodes[i].port++ <--> nodes[0].port++ if i == N-1;
        }
}

