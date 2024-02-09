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

#include "receiver.h"
#include <cstring>
#include <vector>
#include <bitset>
#include "message1_m.h"
Define_Module(Receiver);

void Receiver::initialize()
{
    // TODO - Generated method body
}

void Receiver::handleMessage(cMessage *msg)
{

                Message1_Base* cmsg = check_and_cast<Message1_Base *>(msg);
                std::string messa=cmsg->getM_Payload();

                         std::vector<std::bitset<8> > v;
                         for (int i = 0; i < cmsg->getM_Payload().length(); i++) {
                             //push each character into the vector
                             v.push_back(std::bitset<8>(cmsg->getM_Payload()[i]));
                         }
                         std::bitset<8> err_check(0);
                         //calculate the new parity
                         for (int i = 0; i < v.size(); ++i) {

                             err_check ^= v[i];
                         }
                         err_check^=std::bitset<8>( cmsg->getM_Trailer());

                         int bool_check = (int)err_check.to_ulong();
                         EV<<"parity: "<<bool_check<<std::endl;
                         EV<<"trailer: "<<cmsg->getM_Trailer()<<std::endl;
                         //if its =zero so there is an error
                         if(bool_check != 0){
                             std::cout<< "error message." << endl;
                             cmsg->setM_Type(0);
                         }
                         else{

                             cmsg->setM_Type(1);

                             std::string final_msg = "";
                             for (int i = 0; i < cmsg->getM_Payload().length(); ++i) {
                                 //convert the bits into characters
                                 final_msg += (char)v[i].to_ulong();
                             }
                             std::cout<< "The original message is "<< final_msg << endl;
                         }
                         send(cmsg, "nic$o");


   EV << "(N)ACK Message type: " << cmsg->getM_Type() << std::endl;
                                                                EV << "(N)ACK Message header: "  << cmsg->getM_Header() << std::endl;
                                                                EV << "(N)ACK Message trailer: " << cmsg->getM_Trailer() << std::endl;


}
