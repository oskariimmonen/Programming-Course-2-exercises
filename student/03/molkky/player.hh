#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>

class Player
{
public:
    Player(std::string nimi);
    std::string get_name();
    int get_points();
    bool has_won();
    void add_points(int points);

private:
    std::string nimi_;
    int points_ = 0;
};

#endif // PLAYER_HH
