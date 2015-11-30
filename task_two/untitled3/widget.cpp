#include "widget.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QString>
#include<QLabel>
#include<QPushButton>
#include<QTextEdit>

#include<QProgressBar>
#include<QSlider>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout=new QHBoxLayout;
    QPushButton *button1=new QPushButton("Push me to see some magic!");
    QLabel *label=new QLabel("Just some text here))))))))))))))))))))))");
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(button1);
    layout->addWidget(label);
        connect(button1,SIGNAL(clicked(bool)),label,SLOT(hide()));
    QVBoxLayout *layout1=new QVBoxLayout;
    layout1->addLayout(layout);
QLabel *label1=new QLabel("Cool, huh?");
layout1->addWidget(label1);
label1->setAlignment(Qt::AlignCenter);
label1->hide();
connect(button1,SIGNAL(clicked(bool)),label1,SLOT(show()));
    QHBoxLayout *layout2=new QHBoxLayout;
    QProgressBar *bar=new QProgressBar;
    QSlider *slider=new QSlider;
    QLabel *label2=new QLabel("The progress bar will change along with the slider");
    label2->setAlignment(Qt::AlignCenter);
    layout2->addWidget(label2);
    layout2->addWidget(slider);
    layout2->addWidget(bar);
    connect(slider,SIGNAL(valueChanged(int)),bar,SLOT(setValue(int)));

    QHBoxLayout *layout3=new QHBoxLayout;
    layout3->addStretch();
    QPushButton* button2=new QPushButton("Close");
    layout3->addWidget(button2);

    connect(button2,SIGNAL(clicked(bool)),this,SLOT(close()));

    QVBoxLayout* final_layout=new QVBoxLayout;
    final_layout->addLayout(layout1);
    final_layout->addLayout(layout2);
    final_layout->addLayout(layout3);
    setLayout(final_layout);
}

Widget::~Widget()
{

}
