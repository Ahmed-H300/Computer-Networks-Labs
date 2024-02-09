package lab_1_req;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=612,200");
    submodules:
        tic: Node {
            @display("p=158,82");
        }
        toc: Node {
            @display("p=434,82");
        }
    connections:
        tic.out --> toc.in;
        toc.out --> tic.in;
}

