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
#include <bitset>

Define_Module(Receiver);

void Receiver::initialize()
{
    // TODO - Generated method body
}

void Receiver::handleMessage(cMessage *msg)
{

           std::string rec_mess = msg->getName();
           std::vector<std::bitset<8> > v;
           for (int i = 0; i < rec_mess.length(); ++i) {
               //push each character into the vector
               v.push_back(std::bitset<8>(rec_mess[i]));
           }
           std::bitset<8> err_check(0);
           //calculate the new parity
           for (int i = 0; i < v.size(); ++i) {

               err_check ^= v[i];
           }
           int bool_check = (int)err_check.to_ulong();
           //if its =zero so there is an error
           if(bool_check != 0){
               std::cout<< "error message." << endl;
           }
           else{
               int mes_size = (int)v[0].to_ulong();
               std::string final_msg = "";
               for (int i = 1; i < mes_size - 1; ++i) {
                   //convert the bits into characters
                   final_msg += (char)v[i].to_ulong();
               }
               std::cout<< "The original message is "<< final_msg << endl;
           }
           msg->setName("Start-Transmission");
           send(msg, "port$o");
}
