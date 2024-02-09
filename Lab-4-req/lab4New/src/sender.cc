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

#include "sender.h"
#include <bitset>
Define_Module(Sender);

const int BYTE_SZ=8;
void Sender::initialize()
{
    // TODO - Generated method body
    scheduleAt(0, new cMessage("Start-Transmission"));
}

void Sender::handleMessage(cMessage *msg)
{
    // TODO - Generated method body



           std::cout<< "Please enter the message to be sent " << endl;
           std::string mess;
           std::cin >> mess;
           std::cout<< "You entered " << mess << endl;
           int m_size = mess.size();
           std::vector<std::bitset<8> > v;
           std::bitset<8> paritySet(0);
           //add character count
           v.push_back(std::bitset<8>((m_size + 2)));
           //make xor between the parity and the character count
           paritySet ^= v[0];
           for (int i = 0; i < m_size; ++i) {
               std::bitset<8> temp(mess[i]);
               //xoring each character in message with parity
               paritySet ^= temp;
               //put the character bitset inside the vector
               v.push_back(temp);
           }
           v.push_back(paritySet);
           std::cout<< "The frame that will be sent before checking error chance" << endl;
           for (int i = 0; i < v.size(); ++i) {
               std::cout<< v[i].to_string() << endl;
           }
           std::cout<< endl;
           std::cout<< "1 Means there will be error and 0 means there will be no error" << endl;
           int err_chance  = par("rand").intValue();
           std::cout<< "the err_chance is: " << err_chance << endl;
           if(err_chance == 1){
               int ran_chr = int(uniform(0, v.size()));
               int ran_bit = int(uniform(0, BYTE_SZ ));
               std::cout<< "The character that will have the error: " << ran_chr +1 << endl;
               std::cout<< "The bit that will have the error: " << ran_bit << endl;
               v[ran_chr][ran_bit] = v[ran_chr][ran_bit] ^ 1;
           }
           std::cout<< "The frame that will be sent After checking error chance" << endl;
           for (int i = 0; i < v.size(); ++i) {
               std::cout<< v[i].to_string() << endl;
           }
           std::string final_msg = "";
           //Sending it in a characters form not bit form
           for (int i = 0; i < v.size(); ++i) {
               final_msg += (char)v[i].to_ulong();
           }
           msg->setName(final_msg.c_str());
           send(msg, "port$o");



}
