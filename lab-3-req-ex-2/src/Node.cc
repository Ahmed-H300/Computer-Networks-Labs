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

#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
    // TODO - Generated method body
    EV << "Starting Node " << getIndex() << endl;
    if (getIndex() == 0){
        std::string start_mess = "Start discover Node " + std::to_string(getIndex());
        scheduleAt(0, new cMessage(start_mess.c_str()));
    }

}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if (msg->isSelfMessage()){
        msg->setName("discover");
        msg->setKind(1);
        send(msg, "port$o", 0);
    }
    else{
        std::string start_mess = msg->getName();
        size_t found = start_mess.find_first_of("0123456789");
        int number = std::atoi(start_mess.c_str() + found);
        if (number == getIndex()){
            EV << "The number of nodes in the network is " << msg->getKind() << endl;
            EV << "Discovery is Finished" << endl;
            EV << "Simulation is Finished" << endl;
            cancelAndDelete(msg);
        }
        else{
            int curr_num = msg->getKind() + 1;
            msg->setKind(curr_num);
            send(msg, "port$o", 1);
        }

    }
}
