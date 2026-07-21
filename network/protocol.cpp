#include "protocol.h"
#include <sstream>

string convertMove(const Move& move) {
    string converted = "MOVE " + to_string(move.from) + " " + to_string(move.to);
    return converted;
}

string convertChat(const string& text) {
    return "CHAT " + text;
}

string convertGiveup() {
    return "GIVEUP";
}

Message parseMessage(const string& line) {
    Message msg;
    istringstream is(line);

    string type;
    is >> type;

    if (type == "MOVE")
    {
        int from = -1;
        int to = -1;

        if (is >> from >> to)      // we check for both numbers to exist
        {
            msg.type = MSG_MOVE;
            msg.move = Move{ from, to };
        }
    }
    else if (type == "CHAT")
    {
        msg.type = MSG_CHAT;
        getline(is, msg.text);
        if (!msg.text.empty() && msg.text[0] == ' ')
            msg.text.erase(0, 1);      // drop the space after the word CHAT
    }
    else if (type == "GIVEUP")
    {
        msg.type = MSG_GIVEUP;
    }

    return msg;      // msg stays MSG_UNKNOWN if nothing matched
}

vector<string> takeMessages(string& buffer) {
    vector<string> messages;

    while (true)
    {
        size_t end = buffer.find('\n');
        if (end == string::npos)      // npos(means no position and not found) -> didn't find any complete message
            break;

        messages.push_back(buffer.substr(0, end));
        buffer.erase(0, end + 1);      // removing the line and '\n'
    }

    return messages;      // everything left in buffer is not complete
}