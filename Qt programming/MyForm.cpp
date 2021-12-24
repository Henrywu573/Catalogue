#include "MyForm.h"
MyForm::MyForm(QWidget *parent) : QWidget(parent)
{
    label = new QLabel(this); //set parent to this as parent is Myform object
    label->setGeometry(30,0,50,80);

    lineEdit = new QLineEdit(this); //set parent to this as parent is Myform object
    lineEdit->setGeometry(30,80,80,20);

    button = new QPushButton(this); //set parent to this as parent is Myform object
    button->setGeometry(30,110,50,60);
    button->setText("Click");

    this->connect(button, // button generates signal
            SIGNAL(clicked()), // signal was clicked
            this, // recievr is form
            SLOT(addTextToLabel()) //the slot that executes is addTextToLabel
    );
}
void MyForm::addTextToLabel(){
   this->label->setText( lineEdit->text() ); // on this from obj

}



