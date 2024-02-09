//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Hub.h"

Define_Module(Hub);

void Hub::initialize()
{
    // TODO - Generated method body
    EV << "Starting Hub " << endl;
    std::string start_mess = "Start sending to Nodes";
    scheduleAt(0, new cMessage(start_mess.c_str()));
}

void Hub::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if (msg->isSelfMessage()){
        int n = getParentModule()->par("N");
        int m = int(uniform(0, n));
        EV << "The Node chosen randomly is: " << m << endl;
        msg->setName("Hello from Hub");
        EV << "sending: " << m << endl;
        send(msg, "port$o", m);
    }
    else{
        EV << "Received: " << msg->getName() << endl;
        double interval = exponential(2.0);
        EV << "Interval is: " << interval << endl;
        scheduleAt(simTime() + interval, msg);
    }


}
