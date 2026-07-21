#pragma once
#include <string>
#include <vector>
#include "../logic/Move.h"

using namespace std;

//   "MOVE # $"      moving from # to $
//   "CHAT text"      a chat message
//   "GIVEUP"      time over or player gave up

enum MessageType {
    MSG_UNKNOWN = 0,      // missed message
    MSG_MOVE,
    MSG_CHAT,
    MSG_GIVEUP
};

struct Message {
    MessageType type = MSG_UNKNOWN;
    Move move;      // we just use it with MSG_MOVE type
    string text;      // we just use it with MSG_CHAT type
};

// -------------------- converting to text --------------------
string convertMove(const Move& move);
string convertChat(const string& text);
string convertGiveup();

// -------------------- converting to Message struct --------------------
Message parseMessage(const string& line);


vector<string> takeMessages(string& buffer);
