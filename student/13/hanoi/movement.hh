/* Hanoi
 *
 * Desc:
 * Headers for movement class. Disks are moved with help from this class.
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 * */
#ifndef MOVE_HH
#define MOVE_HH

class Move
{
private:
    int from;
    int to;
public:

    Move(int f,int t);
    Move();

};

#endif // MOVE_H

