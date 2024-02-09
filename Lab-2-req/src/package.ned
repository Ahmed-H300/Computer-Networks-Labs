package lab_2_req;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=555,200");
    submodules:
        player1: Player1 {
            @display("p=51,60");
        }
        player2: Player2 {
            @display("p=421,60");
        }
    connections:
        player1.out --> player2.in;
        player2.out --> player1.in;
}

