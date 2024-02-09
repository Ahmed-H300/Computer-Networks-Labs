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

#include "Player1.h"

Define_Module(Player1);

void Player1::initialize()
{
    // TODO - Generated method body
    EV << "The random number chosen for the game:" << par("rand").intValue() << endl;
    EV << "send Start" << endl;
    cMessage *msg = new cMessage("start");
    send(msg,"out");
}

void Player1::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    const char* messageName = msg->getName();
    int number = std::atoi(messageName);
    EV << "The number received: "<< messageName << endl;
    if(number == par("rand").intValue())
    {
        msg->setName("correct guess");
        EV << "send: " << msg->getName() << endl;
        send(msg,"out");
    }
    else{
        msg->setName("wrong guess");
        EV << "send: " << msg->getName() << endl;
        send(msg,"out");
    }

}
