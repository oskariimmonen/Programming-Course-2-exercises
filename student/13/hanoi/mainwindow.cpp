/* Hanoi / mainwindow.cpp
 *
 * Desc:
 * Programs main solutuin is in this file.
 * Program calls peg, disk and movement classes to draw and move disks and also to draw pegs
 * GUI features three pushbuttons on which pegs are drawn. Disks can be moved from peg to another by choosing
 * initial peg first and then pressing the target peg. There is a bar at the top from which user is able to start
 * a new game, change the amount of disks or exit the game.
 *
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 * */
#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "mainwindow.hh"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>


disk*movement = NULL;

Hanoi::Hanoi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hanoi)
{
    ui->setupUi(this);
    amount_of_disks = 6;

    pegs[0] = new peg(0, amount_of_disks,ui->pushPEG1);
    pegs[1] = new peg(1, 0,ui->pushPEG2);
    pegs[2] = new peg(2, 0,ui->pushPEG3);

}



Hanoi::~Hanoi()
{
    delete ui;
    for (int i=0;i<3;i++){

        delete pegs[i];
    }
    movement = NULL;

}

void Hanoi::peg_pressed(peg* p)
{
    if(!movement){
        movement = p->take_disk();

    }else{
        int from = movement->On()->disk_index();
        if(p->is_eligible(movement)){
            int target = p->disk_index();
            Move mov(from,target);
            ui->statusLabel->setText("");

            movement = NULL;
            int x = p->number_of_disks();
            if (x == amount_of_disks and p != pegs[0]) {
                ui->statusLabel->setText("Game over, YOU WON!  "
                                         "  Press settings ---> New Game to play again or EXIT to close the game");

               ui->pushPEG1->setEnabled(false);
               ui->pushPEG2->setEnabled(false);
               ui->pushPEG3->setEnabled(false);

               ui->pushButton->setEnabled(false);
               ui->pushButton_2->setEnabled(false);
               ui->pushButton_3->setEnabled(false);
            }



        }else{
            movement->On()->is_eligible(movement);
            movement = NULL;
            ui->statusLabel->setText("ILLEGAL MOVE!: You can't put larger disks on smaller ones!");
        }
    }
}



void Hanoi::on_action_New_triggered()
{
    for (int i=0;i<3;i++){

        delete pegs[i];
    }
    if(movement){
        delete movement;
    }
    movement = NULL;

    pegs[0] = new peg(0, amount_of_disks,ui->pushPEG1);
    pegs[1] = new peg(1, 0,ui->pushPEG2);
    pegs[2] = new peg(2, 0,ui->pushPEG3);

    ui->pushPEG1->setEnabled(true);
    ui->pushPEG2->setEnabled(true);
    ui->pushPEG3->setEnabled(true);
    ui->statusLabel->setText("");

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
}


void Hanoi::on_action_2_triggered()
{
    amount_of_disks = 2;
    ui->action_New->trigger();
}


void Hanoi::on_action_3_triggered()
{
    amount_of_disks = 3;
    ui->action_New->trigger();
}


void Hanoi::on_action_4_triggered()
{
    amount_of_disks = 4;
    ui->action_New->trigger();
}


void Hanoi::on_action_5_triggered()
{
    amount_of_disks = 5;
    ui->action_New->trigger();
}


void Hanoi::on_action_6_triggered()
{
    amount_of_disks = 6;
    ui->action_New->trigger();
}


void Hanoi::on_action_7_triggered()
{
    amount_of_disks = 7;
    ui->action_New->trigger();
}


void Hanoi::on_action_8_triggered()
{
    amount_of_disks = 2;
    ui->action_New->trigger();
}


void Hanoi::on_pushPEG1_pressed()
{
 peg_pressed(pegs[0]);
}


void Hanoi::on_pushPEG2_pressed()
{
    peg_pressed(pegs[1]);
}


void Hanoi::on_pushPEG3_pressed()
{
    peg_pressed(pegs[2]);
}

void Hanoi::on_pushButton_pressed()
{
    peg_pressed(pegs[0]);
}

void Hanoi::on_pushButton_2_pressed()
{
    peg_pressed(pegs[1]);
}

void Hanoi::on_pushButton_3_pressed()
{
    peg_pressed(pegs[2]);
}



void Hanoi::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A and ui->pushPEG1->isEnabled()) { //is disabled if game is won
        peg_pressed(pegs[0]);
    }

    if(event->key() == Qt::Key_S and ui->pushPEG1->isEnabled()) {
        peg_pressed(pegs[1]);
    }

    if(event->key() == Qt::Key_D and ui->pushPEG1->isEnabled()) {
        peg_pressed(pegs[2]);
    }
}
