/* Hanoi
 *
 * Desc:
 *
 *Functions to move the disks. from point a to point b
 * Points are expressed with int numbers.
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 * */
#include "movement.hh"

Move::Move(int f, int t):
    from(f),
    to(t)
{

}

Move::Move(): from(0),to(0){}


