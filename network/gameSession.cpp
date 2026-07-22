#include "gameSession.h"

GameSession::GameSession(GameMediator* game, int localPlayer) {
    game_ = game;
    localPlayer_ = localPlayer;
    gaveupBy_ = 0;
}

int GameSession::otherPlayer(int player) const {
    if (player == 1)
        return 2;
    else
        return 1;
}


vector<string> GameSession::makeLocalMove(const Move& move) {
    vector<string> toSend;

    if (isOver())
        return toSend;
    if (!isMyTurn())      // not our turn(ignoring the click)
        return toSend;
    if (!game_->applyMove(move))      // illegal move
        return toSend;

    toSend.push_back(convertMove(move));      // setting the message
    return toSend;
}

void GameSession::handleMessage(const string& line) {
    Message msg = parseMessage(line);

    if (msg.type == MSG_MOVE)
    {
        if (isOver())
            return;
        if (game_->currentPlayer() == localPlayer_)
            return;      // when it's our turn, the other player shouldn't move

        game_->applyMove(msg.move);
    }
    else if (msg.type == MSG_CHAT)
    {
        lastChat_ = msg.text;
    }
    else if (msg.type == MSG_GIVEUP)
    {
        gaveupBy_ = otherPlayer(localPlayer_);
    }

    return;
}

vector<string> GameSession::sendChat(const string& text) {
    vector<string> toSend;
    toSend.push_back(convertChat(text));
    return toSend;
}

vector<string> GameSession::giveupLocal() {
    vector<string> toSend;

    if (isOver())
        return toSend;

    gaveupBy_ = localPlayer_;
    toSend.push_back(convertGiveup());
    return toSend;
}

const GameMediator* GameSession::game() const {
    return game_;
}

int GameSession::localPlayer() const {
    return localPlayer_;
}

bool GameSession::isMyTurn() const {
    if (isOver())
        return false;
    return game_->currentPlayer() == localPlayer_;
}

bool GameSession::isOver() const {
    if (gaveupBy_ != 0)
        return true;
    return game_->isGameOver();
}

int GameSession::winner() const {
    if (gaveupBy_ != 0)
        return otherPlayer(gaveupBy_);      // the one who stayed wins
    return game_->winner();
}

string GameSession::lastChat() const {
    return lastChat_;
}
