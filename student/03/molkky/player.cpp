#include "player.hh"
#include <string>
#include<iostream>

Player::Player(std::string nimi): nimi_(nimi)
{

}


int Player::get_points() {
return points_;
}

std::string Player::get_name() {
return nimi_;
}

bool Player::has_won() {

   if (points_ < 50) {
   return false;

   }

    else if (points_ > 50) {
        points_ = 25;
        std::cout << nimi_ << " gets penalty points!" << std::endl;
    }

    if(points_ == 50) {
        return true;
    }
   return false;
}

void Player::add_points(int points)
{
 points_ = points_ + points;
 if (points_ > 50) {
     points_ = 25;
 }
}
