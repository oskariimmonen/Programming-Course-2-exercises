/* Hanoi
 *
 * Desc:
 * This file includes functions from class: "peg"
 * Functions draw the pegs and disks and also help to move them in user interface when wanted
 *
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 * */
#include "peg.hh"
#include "disk.hh"
#include <QWidget>
#include <QPainter>



peg::peg(int index, int disk_count, QWidget * parent)
{

     this->index = index;
     this->disk_count = disk_count;

     this->setParent(parent);

     for(int i=0;i<disk_count;i++){
        disk* d = new disk(disk_count - i,this,i, parent);
        pile[i] = d;
    }
     setEnabled(true);
     show();
     raise();

}


void peg::paintEvent(QPaintEvent *event){

    Q_UNUSED(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QColor pegColor(210, 162, 97);
    QColor edgeColor(0, 0, 0);
    p.setPen(edgeColor);
    p.setBrush(pegColor);
    p.drawRoundedRect(120,90,20,260-(disk_count*23),10,8);
    raise();

}


peg::~peg(){
    setParent(NULL);
    for (int i=0;i<disk_count;i++){
        delete pile[i];
    }
}


disk* peg::take_disk(){
  disk *d = NULL;
    if(disk_count>0){
      d = pile[--disk_count];
      pile[disk_count]=NULL;
      d->grab_disk();
}
return d;

}


bool peg::is_eligible(disk* d){

    if(disk_count == 0){
        pile[0] = d;
        disk_count++;
        d->set_peg_position(this,0);
        raise();
        return true;
    }else{
        if(pile[disk_count-1]->disk_size() < d->disk_size()){
            return false;

        }else{
            pile[disk_count] = d;
            disk_count++;
            d->set_peg_position(this,disk_count-1);
            raise();

            return true;
        }
    }

}


int peg::disk_index(){
    return index;
}


