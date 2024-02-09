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
#include <stdio.h>
#include <string>
#include <vector>
#include <bitset>
#include "message1_m.h"
Define_Module(Sender);
const int BYTE_SZ=8;

void Sender::sendMessage(Message1_Base *msg) {

    std::cout << "Enter the message you want to send: ";
    std::string message;
    std::cin >> message;
    std::bitset<8>charCount (message.length()+3), parity(0);
    std::vector<std::bitset<8>> words;
    for (int i = 0; i < message.length(); i++) {
        std::bitset<8> word(message[i]);
        parity = (parity ^ word);
        words.push_back(word);
    }
    std::cout<< "The frame that will be sent before checking error chance" << endl;
   for (int i = 0; i < words.size(); ++i) {
       std::cout<< words[i].to_string() << endl;
   }
   std::cout<< endl;
    int err_chance  = int(uniform(0,2));
            std::cout<< "the err_chance is: " << err_chance << endl;
            if(err_chance == 1){
                int ran_chr = int(uniform(0, words.size()));
                int ran_bit = int(uniform(0, BYTE_SZ));
                std::cout<< "The character that will have the error: " << ran_chr << endl;
                std::cout<< "The bit that will have the error: " << ran_bit << endl;
                words[ran_chr][ran_bit] = words[ran_chr][ran_bit] ^ 1;
            }
            else{

                EV<<"No errors"<<std::endl;
                std::cout<<"No errors"<<std::endl;
            }

            std::cout<< "The frame that will be sent After checking error chance" << endl;
            for (int i = 0; i < words.size(); ++i) {
                   std::cout<< words[i].to_string() << endl;
               }




    message = "";
    for (std::bitset<8> i: words) {
        message += (char)i.to_ulong();

    }

       if (msg == nullptr) msg = new Message1_Base();
       msg->setM_Header((char) charCount.to_ulong());
        msg->setM_Type(2);
    msg->setM_Payload(message);
    msg->setM_Trailer((char)parity.to_ulong());


    EV << "Message payload: " << msg->getM_Payload() << std::endl;
    EV << "Message type: " << msg->getM_Type() << std::endl;
    EV << "Message header: "  << msg->getM_Header() << std::endl;
    EV << "Message trailer: " << msg->getM_Trailer() << std::endl;

    send(msg, "nic$o");
}


void Sender::initialize()
{
    // TODO - Generated method body
    this->sendMessage(nullptr);
}

void Sender::handleMessage(cMessage *msg)
{
    this->sendMessage(check_and_cast<Message1_Base *>(msg));
}
