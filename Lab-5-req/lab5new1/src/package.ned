package lab5new1;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=467,268");
    submodules:
        sender: Sender {
            @display("p=50,105");
        }
        receiver: Receiver {
            @display("p=381,100");
        }
    connections:
        sender.nic <--> receiver.nic;
}

