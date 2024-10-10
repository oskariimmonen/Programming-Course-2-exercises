/* Hanoi / peg.hh
 *
 * Desc:
 * This is a headerfile for peg class
 * File includes definitions and declarations for functions in this class
 *
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 * */
#ifndef POLE_HH
#define POLE_HH
#include <QWidget>



const int MAX_DISKS = 8; // Defines the maximum number of disks.

class disk;
class peg : public QWidget
{
private:

    // disks are stored to a table so we can check their index position on a peg
    //(bottom, top or somehting in between)
    disk* pile[MAX_DISKS];
    int index;
    int disk_count;


public:

    //Creates pegs
    peg(int,int, QWidget*);

    // gets the index position of a disk and returns that int number.
    int disk_index();

    //paintevent paints the created pegs
    void paintEvent(QPaintEvent *event);


    ~peg();

    //Returns the top disk of the peg.
    disk* take_disk();

    //Checks the number of disks on peg and returns it as a int number
    int number_of_disks() {return disk_count;}

    // Chech the disks size and position know if it is eligible to move there.
    //Returns true if size and pointer are ok, else false
    bool is_eligible(disk* d);

};

#endif // POLE_HH
