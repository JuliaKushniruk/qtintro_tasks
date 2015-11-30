#include "widget.h"

void Widget::red_light_on()
{
    red_label->setStyleSheet("background-color: red;");
    orange_label->setStyleSheet("background-color: white;");
    green_label->setStyleSheet("background-color: white;");
}

void Widget::orange_light_on()
{
    red_label->setStyleSheet("background-color: white;");
    orange_label->setStyleSheet("background-color: yellow;");
    green_label->setStyleSheet("background-color: white;");
}

void Widget::green_light_on()
{
    red_label->setStyleSheet("background-color: white;");
    orange_label->setStyleSheet("background-color: white;");
    green_label->setStyleSheet("background-color: green;");
}

void Widget::disable_lights()
{
    red_label->setStyleSheet("background-color: grey;");
    orange_label->setStyleSheet("background-color: grey;");
    green_label->setStyleSheet("background-color: grey;");
    disconnect(red_button,SIGNAL(clicked(bool)),this,SLOT(red_light_on()));
    disconnect(orange_button,SIGNAL(clicked(bool)),this,SLOT(orange_light_on()));
    disconnect(green_button,SIGNAL(clicked(bool)),this,SLOT(green_light_on()));
}

void Widget::enable_lights()
{
    red_label->setStyleSheet("background-color: white;");
    orange_label->setStyleSheet("background-color: white;");
    green_label->setStyleSheet("background-color: white;");
    connect(red_button,SIGNAL(clicked(bool)),this,SLOT(red_light_on()));
    connect(orange_button,SIGNAL(clicked(bool)),this,SLOT(orange_light_on()));
    connect(green_button,SIGNAL(clicked(bool)),this,SLOT(green_light_on()));
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    red_button=new QRadioButton("red");
    orange_button=new QRadioButton("orange");
    green_button=new QRadioButton("green");
    QVBoxLayout *layout1=new QVBoxLayout;
    layout1->addWidget(red_button);
    layout1->addWidget(orange_button);
    layout1->addWidget(green_button);

    red_label=new QLabel;
    orange_label=new QLabel;
    green_label=new QLabel;
    QVBoxLayout *layout2=new QVBoxLayout;
    layout2->addWidget(red_label);
    layout2->addWidget(orange_label);
    layout2->addWidget(green_label);

    QHBoxLayout* top_layout=new QHBoxLayout;
    top_layout->addLayout(layout1);
    top_layout->addLayout(layout2);

    start_button=new QPushButton("start");
    stop_button=new QPushButton("stop");
    QHBoxLayout *bottom_layout=new QHBoxLayout;
    bottom_layout->addStretch();
    bottom_layout->addWidget(start_button);
    bottom_layout->addWidget(stop_button);


    QVBoxLayout *final_layout=new QVBoxLayout;
    final_layout->addLayout(top_layout);
    final_layout->addLayout(bottom_layout);

    connect(start_button,SIGNAL(clicked(bool)),this,SLOT(enable_lights()));
    connect(stop_button,SIGNAL(clicked(bool)),this,SLOT(disable_lights()));

    red_label->setStyleSheet("background-color: grey;");
    orange_label->setStyleSheet("background-color: grey;");
    green_label->setStyleSheet("background-color: grey;");
    setLayout(final_layout);
}

Widget::~Widget()
{

}
