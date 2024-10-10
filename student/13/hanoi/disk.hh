/* Hanoi / disk.hh
 *
 * Desc:
 * This is a headerfile for disk-class
 * Included definitions for functions and variables
 *
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 * */
#ifndef DISK_HH
#define DISK_HH
#endif // DISK_HH
#include<QWidget>

class peg;
class disk: public QWidget
{
private:

    int pos; // int number is a index for position... bottom is zero
    int size;
    peg* on; //includes information about on what peg is the disk on



public:



      //Paintevent paints the created disks
      void paintEvent(QPaintEvent * event);

      //Creates the disks. Parameters are disk size, disk target pole and position on the pole
      //Doesn't return anything
      disk(int size, peg* on,int pos, QWidget*);

      void set_peg_position(peg*d, int p);

      //Lifts the chosen disk above the peg so it appears to be chosen on gui
      void grab_disk();

      //returns the peg where the disk is.
      peg* On(){return on;}

      //returns the size of the asked disk as a int
      int disk_size(){return size;}

};


