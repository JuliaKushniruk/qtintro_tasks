#include "widget.h"

void Widget::change_light()
{
    if(red_button->isChecked()==true)
    {
        red_button->setChecked(false);
        yellow_button->setChecked(true);

        red_button->setStyleSheet("background-color: grey;");
        yellow_button->setStyleSheet("background-color: yellow;");
        toRed=false;
    }
    else if(yellow_button->isChecked()==true)
    {
        yellow_button->setChecked(false);
        yellow_button->setStyleSheet("background-color: grey;");

        if(toRed)
        {
            red_button->setChecked(true);
            red_button->setStyleSheet("background-color: red;");
        }
        else
        {
             green_button->setChecked(true);
             green_button->setStyleSheet("background-color: green;");
        }
    }

    else if(green_button->isChecked()==true)
    {
        green_button->setChecked(false);
        yellow_button->setChecked(true);

        yellow_button->setStyleSheet("background-color: yellow;");
        green_button->setStyleSheet("background-color: grey;");
        toRed=true;
    }
    else
    {
        red_button->setChecked(true);
        red_button->setStyleSheet("background-color: red;");
    }
}
void Widget::disable_lights()
{
    red_button->setCheckable(false);
    yellow_button->setCheckable(false);
    green_button->setCheckable(false);

    red_button->setStyleSheet("background-color: grey;");
    yellow_button->setStyleSheet("background-color: grey;");
    green_button->setStyleSheet("background-color: grey;");
}

void Widget::enable_lights()
{
    toRed=false;

    red_button->setCheckable(true);
    yellow_button->setCheckable(true);
    green_button->setCheckable(true);

}

void Widget::set_timer_start()
{
    timer->start(1000);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    red_button=new QRadioButton("red");
    yellow_button=new QRadioButton("yellow");
    green_button=new QRadioButton("green");

    start_button=new QPushButton("start");
    stop_button=new QPushButton("stop");

    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(red_button);
    layout->addWidget(yellow_button);
    layout->addWidget(green_button);
    layout->addWidget(start_button);
    layout->addWidget(stop_button);


    red_button->setStyleSheet("background-color: grey;");
    yellow_button->setStyleSheet("background-color: grey;");
    green_button->setStyleSheet("background-color: grey;");

    timer=new QTimer;
    disable_lights();
    connect(start_button,SIGNAL(clicked(bool)),this,SLOT(set_timer_start()));
    connect(start_button,SIGNAL(clicked(bool)),this,SLOT(enable_lights()));

    connect(stop_button,SIGNAL(clicked(bool)),timer,SLOT(stop()));
    connect(stop_button,SIGNAL(clicked(bool)),this,SLOT(disable_lights()));

    connect(timer,SIGNAL(timeout()),this,SLOT(change_light()));
   setLayout(layout);
}

Widget::~Widget()
{

}
