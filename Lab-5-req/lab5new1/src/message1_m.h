//
// Generated file, do not edit! Created by opp_msgtool 6.0 from message1.msg.
//

#ifndef __MESSAGE1_M_H
#define __MESSAGE1_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class Message1;
// cplusplus {{
#include <string>
// }}

/**
 * Class generated from <tt>message1.msg:24</tt> by opp_msgtool.
 * <pre>
 * packet Message1
 * {
 *     \@customize(true);  // see the generated C++ header for more info
 *     char M_Header;
 *     string M_Payload;
 *     char M_Trailer;
 *     int M_Type; // 2 for data, 1 for ack, 0 for notack
 * 
 * }
 * </pre>
 *
 * Message1_Base is only useful if it gets subclassed, and Message1 is derived from it.
 * The minimum code to be written for Message1 is the following:
 *
 * <pre>
 * class Message1 : public Message1_Base
 * {
 *   private:
 *     void copy(const Message1& other) { ... }

 *   public:
 *     Message1(const char *name=nullptr, short kind=0) : Message1_Base(name,kind) {}
 *     Message1(const Message1& other) : Message1_Base(other) {copy(other);}
 *     Message1& operator=(const Message1& other) {if (this==&other) return *this; Message1_Base::operator=(other); copy(other); return *this;}
 *     virtual Message1 *dup() const override {return new Message1(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from Message1_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(Message1)
 * </pre>
 */
class Message1_Base : public ::omnetpp::cPacket
{
  protected:
    char M_Header = 0;
    std::string M_Payload;
    char M_Trailer = 0;
    int M_Type = 0;

  private:
    void copy(const Message1_Base& other);

  protected:
    bool operator==(const Message1_Base&) = delete;
    // make constructors protected to avoid instantiation
    // make assignment operator protected to force the user override it
    Message1_Base& operator=(const Message1_Base& other);
    Message1_Base(const Message1_Base& other);


  public:
    Message1_Base(const char *name=nullptr, short kind=0);

    virtual ~Message1_Base();
    virtual Message1_Base *dup() const override {
           return new Message1_Base(*this);
       }
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual char getM_Header() const;
    virtual void setM_Header(char M_Header);

    virtual std::string getM_Payload() const;
    virtual void setM_Payload(std::string M_Payload);

    virtual char getM_Trailer() const;
    virtual void setM_Trailer(char M_Trailer);

    virtual int getM_Type() const;
    virtual void setM_Type(int M_Type);
};


namespace omnetpp {

template<> inline Message1_Base *fromAnyPtr(any_ptr ptr) { return check_and_cast<Message1_Base*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __MESSAGE1_M_H

