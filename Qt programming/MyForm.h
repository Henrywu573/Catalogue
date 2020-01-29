#ifndef MyForm_H
#define MyForm_H
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class MyForm : public QWidget{
    Q_OBJECT
    public:
        //declare pointers of QWidgets.
        QLabel *label;
        QPushButton *button;
        QLineEdit *lineEdit;

        /* Myfrom class's constructor with parent value 0, i.e form
        * object will be the parent for all the widget objects inside it ..
        * or simply QLabel, QPushbutton etc will be childs of MyForm object when created..
        */
        MyForm(QWidget *parent = 0);

    private slots:
        /*
        *   A slot that will set the value of label to whatever was written inside QLineEdit.
        */
        void addTextToLabel();
};
#endif
