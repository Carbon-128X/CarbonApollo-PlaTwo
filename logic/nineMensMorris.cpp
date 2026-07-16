#include "nineMensMorris.h"

// ----------------------------------------- board data -----------------------------------------

const int MILLS[16][3] = {      // all of possible mills (sorted and based on positions)
    {0,1,2},   {2,3,4},   {4,5,6},   {6,7,0},
    {8,9,10},  {10,11,12},{12,13,14},{14,15,8},
    {16,17,18},{18,19,20},{20,21,22},{22,23,16},
    {1,9,17},  {3,11,19}, {5,13,21}, {7,15,23}
};


const vector<vector<int>> POS_NEIGHBORS = {      // neighbors of each position
    {1,7},        // 0
    {0,2,9},      // 1
    {1,3},        // 2
    {2,4,11},     // 3
    {3,5},        // 4
    {4,6,13},     // 5
    {5,7},        // 6
    {6,0,15},     // 7
    {9,15},       // 8
    {8,10,1,17},  // 9
    {9,11},       // 10
    {10,12,3,19}, // 11
    {11,13},      // 12
    {12,14,5,21}, // 13
    {13,15},      // 14
    {14,8,7,23},  // 15
    {17,23},      // 16
    {16,18,9},    // 17
    {17,19},      // 18
    {18,20,11},   // 19
    {19,21},      // 20
    {20,22,13},   // 21
    {21,23},      // 22
    {22,16,15}    // 23
};

// If 100 moves passed with no piece removed, the game is draw.
static const int DRAW_LIMIT = 100;


NineMensMorris::NineMensMorris() {
    for (int i = 0; i < 24; i++)
        board_[i] = 0;
    current_ = 1;
    toPlace_[0] = 0;
    toPlace_[1] = 9;
    toPlace_[2] = 9;
    awaitingRemoval_ = false;
    movesSinceRemoval_ = 0;
}


int NineMensMorris::otherPlayer(int player) const {
    if (player == 1)
        return 2;
    else
        return 1;
}

int NineMensMorris::countPieces(int player) const {
    int count = 0;
    for (int i = 0; i < 24; i++)
        if (board_[i] == player)
            count++;
    return count;
}

bool NineMensMorris::inPlacingPhase(int player) const {
    if (toPlace_[player] > 0)
        return true;
    else
        return false;
}

bool NineMensMorris::canFly(int player) const {
    if (!inPlacingPhase(player) && (countPieces(player) == 3)) // placing should be already done
        return true;
    else
        return false;
}

bool NineMensMorris::areNeighbours(int a, int b) const {
    const vector<int>& nb = POS_NEIGHBORS[a];
    int vectorSize = (int)nb.size();
    for (int i = 0; i < vectorSize; i++)
        if (nb[i] == b)
            return true;

    return false;
}

bool NineMensMorris::formsMill(int pos, int player) const {
    for (int i = 0; i < 16; i++)
        if (pos == MILLS[i][0] || pos == MILLS[i][1] || pos == MILLS[i][2])
            if (board_[MILLS[i][0]] == player && board_[MILLS[i][1]] == player && board_[MILLS[i][2]] == player)
                return true;

    return false;
}

bool NineMensMorris::isRemovable(int pos, int opponent) const {
    if (board_[pos] != opponent)
        return false;
    if (!formsMill(pos, opponent))
        return true;

    for (int i = 0; i < 24; i++)      // if it was in a mill, we should check all of enemy pieces if they're in mill
        if (board_[i] == opponent && !formsMill(i, opponent))      // if one of the others wasn't in mill, so pos isn't removable
            return false;
    return true;
}

vector<Move> NineMensMorris::movement(int player) const {      // legal moves but without checking gameOver(for after placing)
    vector<Move> moves;

    bool fly = canFly(player);

    for (int from = 0; from < 24; from++)
    {
        if (board_[from] != player)
            continue;

        if (fly)
            for (int to = 0; to < 24; to++)
                if (board_[to] == 0)
                    moves.push_back(Move{ from, to });
        else 
        {
            const vector<int>& neighbor = POS_NEIGHBORS[from];
            
            for (int i = 0; i < (int)neighbor.size(); i++)
                if (board_[neighbor[i]] == 0)
                    moves.push_back(Move{ from, neighbor[i] });
        }
    }

    return moves;
}