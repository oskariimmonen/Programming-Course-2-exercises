/* Hanoi / disk.cpp
 *
 * Desc:
 * This file includes functions of Disk class.
 * Functions create and draw the disks.
 * set_peg_position and grab_disk are for the movement of the disks
 *
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 * */
#include "peg.hh"
#include "disk.hh"
#include <QPainter>

disk::disk(int size, peg* peg,int pos, QWidget* par)
{
  this->size = size;
  this->on = peg;
  this->pos = pos;
  this->setParent(par);
  show();
}


void disk::paintEvent(QPaintEvent *event){

    Q_UNUSED(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QColor edgeDiskColor(0, 0, 0);
    p.setPen(edgeDiskColor);

    int width = (size*3)+60;

    QColor colors[] = {QColor(0,0,255),QColor(0,255,0),QColor(255,255,0),  QColor(0,255,255), QColor(160,32,240), QColor(52, 76, 18), QColor(190,96,74), QColor(255,0,0) };
    QColor diskTop = colors[size-1];
    QColor diskShadow = diskTop.darker(200);
    p.setBrush(diskShadow);
    p.drawEllipse(QPointF(130,(100 + 260 - 5)-23*(pos+1)),width,25);

    p.setBrush(diskTop);
    p.drawEllipse(QPointF(130,(100 + 250 - 5)-23*(pos+1)),width,25);

    QColor baseColor(100,100,100);
    p.setBrush(edgeDiskColor);
    p.drawEllipse(QPointF(130,(100 + 250 - 5)-23*(pos+1)),width/4,8);

}


void disk::set_peg_position(peg*d, int p){

     if(On() != d){
       on = d;
       setParent(d->parentWidget());
       show();
     }
     pos = p;
     repaint();
}


void disk::grab_disk(){
    pos=12;
    repaint();
}

