package lab4new;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=624,353");
    submodules:
        sender: Sender {
            @display("p=87,110");
        }
        receiver: Receiver {
            @display("p=520,111");
        }
    connections:
        sender.port <--> receiver.port;
}

