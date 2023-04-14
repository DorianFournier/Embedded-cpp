#include <iostream>
#include <mqtt/async_client.h>

using namespace std;

const string s_ADDRESS{"tcp://broker.emqx.io:1883"};
const string s_CLIENT_ID{"MQTT-Receiver"};
const string s_TOPIC{"/ynov/bordeaux/"};
const string s_MESSAGE{"coucou les loulous"};
const uint8_t u8_INTERVAL{20};
const uint8_t u8_QOS_MQTT{0};

class Callback : public virtual mqtt::callback
{
public:
    virtual void connection_lost(const string &cause)
    {
        cout << "Connection lost" << endl;
    }

    virtual void delivery_complete(mqtt::delivery_token_ptr token) {}

    virtual void message_arrived(const string &topic, mqtt::message_ptr msg) {}
};

int main()
{
    try
    {
        mqtt::async_client client(s_ADDRESS, s_CLIENT_ID);
        Callback callback;
        client.set_callback(callback);

        mqtt::connect_options connOpts;
        connOpts.set_keep_alive_interval(u8_INTERVAL);
        connOpts.set_clean_session(true);

        cout << "Connecting to broker: '" << s_ADDRESS << "'..." << endl;
        mqtt::token_ptr conntok = client.connect(connOpts);
        conntok->wait();

        cout << "Connected" << endl;

        cout << "Sending message..." << endl;
        mqtt::message_ptr pubmsg = mqtt::make_message(s_TOPIC, s_MESSAGE);
        pubmsg->set_qos(u8_QOS_MQTT);
        client.publish(pubmsg)->wait();

        cout << "Message sent : " + s_MESSAGE << endl;

        cout << "Disconnecting..." << endl;
        mqtt::token_ptr disctok = client.disconnect();
        disctok->wait();

        cout << "Disconnected" << endl;
    }
    catch (const mqtt::exception &exc)
    {
        cerr << "Error: " << exc.what() << endl;
        return 1;
    }

    return 0;
}
