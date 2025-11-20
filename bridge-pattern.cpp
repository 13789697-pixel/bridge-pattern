#include <iostream>
using namespace std;

// абстракція //
class Message {
protected:
    class IMessageSender* sender;
public:
    Message(IMessageSender* s) : sender(s) {}
    virtual void send(const string& text) = 0;
    virtual ~Message() = default;
};

// реалізація //
class IMessageSender {
public:
    virtual void sendMessage(const string& text) = 0;
    virtual ~IMessageSender() = default;
};

// реалізація //
class EmailSender : public IMessageSender {
public:
    void sendMessage(const string& text) override {
        cout << "Email: " << text << endl;
    }
};

class SmsSender : public IMessageSender {
public:
    void sendMessage(const string& text) override {
        cout << "SMS: " << text << endl;
    }
};

// розширена абстракція //
class TextMessage : public Message {
public:
    TextMessage(IMessageSender* s) : Message(s) {}
    void send(const string& text) override {
        sender->sendMessage("TextMessage: " + text);
    }
};
int main() {
    EmailSender email;
    SmsSender sms;

    TextMessage msg1(&email);
    TextMessage msg2(&sms);

    msg1.send("Hello email!");
    msg2.send("Hello SMS!");

    return 0;
}