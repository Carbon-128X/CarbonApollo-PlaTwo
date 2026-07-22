#pragma once
#include <string>
#include <vector>
#include "protocol.h"
#include "../logic/gameMediator.h"

using namespace std;

class GameSession {
private:
    GameMediator* game_;
    int localPlayer_;
    int gaveupBy_;      // 0 = nobody, otherwise who gave up or had time over
    string lastChat_;

    int otherPlayer(int player) const;

public:
    GameSession(GameMediator* game, int localPlayer);

    // Each one returns the messages that must be sent to the other side.
    vector<string> makeLocalMove(const Move& move);
    void handleMessage(const string& line);      // receiving a line from the other side
    vector<string> sendChat(const string& text);
    vector<string> giveupLocal();      // gave up or time over

    // -------------------- read access for UI --------------------
    const GameMediator* game() const;
    int localPlayer() const;
    bool isMyTurn() const;
    bool isOver() const;
    int winner() const;      // same as GameMediator, but knows about giving up
    string lastChat() const;
};
