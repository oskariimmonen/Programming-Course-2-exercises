/* Hanoi / mainwindow.hh
 *
 * Desc:
 *
 * This is a headerfile for mainwindow.cpp. Includes functons' declarations and comments.
 * All actions triggered from user interface are declared here.
 *
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 * */
#define MAINWINDOW_HH
#include <QMainWindow>
#ifndef HANOI_HH
#define HANOI_HH
#include "peg.hh"
#include "disk.hh"
#include "movement.hh"
#include <QStack>
#include <QMainWindow>
#include <QTimer>
#include <QQueue>

namespace Ui {
class Hanoi;
}

class Hanoi : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hanoi(QWidget *parent = 0);
    ~Hanoi();


private slots:


    //Sets the amount of disks in the game to 2 or starts a new game with selected amount of disks
    void on_action_2_triggered();

    //Sets the amount of disks in the game to 3 or starts a new game with selected amount of disks
    void on_action_3_triggered();

    //Sets the amount of disks in the game to 4 or starts a new game with selected amount of disks
    void on_action_4_triggered();

    //Sets the amount of disks in the game to 5 or starts a new game with selected amount of disks
    void on_action_5_triggered();

    //Sets the amount of disks in the game to 6 or starts a new game with selected amount of disks
    void on_action_6_triggered();

    //Sets the amount of disks in the game to 7 or starts a new game with selected amount of disks
    void on_action_7_triggered();

    //Sets the amount of disks in the game to 8 or starts a new game with selected amount of disks
    void on_action_8_triggered();


    //Program runs this when peg1 is pressed (far left)
    void on_pushPEG1_pressed();

    //Program runs this when peg2 is pressed (middle peg)
    void on_pushPEG2_pressed();

    //Program runs this when peg1 is pressed (far right peg)
    void on_pushPEG3_pressed();

    //Performs actions when user pressed new game-button
    //Deletes pegs (and disks) and draws them again in the initial peg
    //sets pushbuttons acticve in case player won last round and they were disabled
    void on_action_New_triggered();

    //Triggers actions to choose the peg on the left
    void on_pushButton_pressed();

    //Triggers actions to choose the middle peg
    void on_pushButton_2_pressed();

    //Triggers actions to choose the peg on the right
    void on_pushButton_3_pressed();



private:

    Ui::Hanoi *ui;
    peg* pegs[3]; //pegs are stored like this to help drawing and destroying them when needed
    int amount_of_disks; //Value is the amount of disks on the game, can be changed

    //Program runs this when user presses a peg. Takes the pressed peg as a parameter
    // and then performs a series of actions to it depending on what the user presses next (movement)
    void peg_pressed(peg* p);

    //function for playing the game with keyboard
    //defines keys for choosing a peg
    void keyPressEvent(QKeyEvent *);


};

#endif // HANOI_H
