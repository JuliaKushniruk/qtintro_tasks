#include "widget.h"

void Widget::set_factor1()
{
    QString field_value=field1->text();
    factor1=field_value.toInt();
    if(field_value=="")
    {
        field1->setText("0");
    }
}

void Widget::set_factor2()
{
    QString field_value=field2->text();
    factor2=field_value.toInt();
    if(field_value=="")
    {
        field2->setText("0");
    }
}

void Widget::calculate_my_result()
{
    my_result=factor1*factor2;
}

void Widget::set_result()
{
    result->setText(QString::number(my_result));
}

void Widget::clear_fields()
{
    field1->setText("");
    field2->setText("");
    result->setText("");
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    field1=new QLineEdit;
    operation=new QLabel("*");
    field2=new QLineEdit;
    equality_sign=new QPushButton("=");
    result=new QLineEdit;

//    validator=new QValidator("//g");
//    field1->setValidator(validator);
//    field2->setValidator(validator);

    QHBoxLayout* my_layout=new QHBoxLayout;
    my_layout->addWidget(field1);
    my_layout->addWidget(operation);
    my_layout->addWidget(field2);
    my_layout->addWidget(equality_sign);
    my_layout->addWidget(result);

    clear_button=new QPushButton("Clear");
    exit_button=new QPushButton("Exit");

    connect(clear_button,SIGNAL(clicked(bool)),this,SLOT(clear_fields()));
    connect(exit_button,SIGNAL(clicked(bool)),this,SLOT(close()));

    QHBoxLayout* button_layout=new QHBoxLayout;
    button_layout->addStretch();
    button_layout->addWidget(clear_button);
    button_layout->addWidget(exit_button);

    QVBoxLayout* final_layout=new QVBoxLayout;
    final_layout->addLayout(my_layout);
    final_layout->addLayout(button_layout);

    connect(equality_sign,SIGNAL(clicked(bool)),this,SLOT(set_factor1()));
    connect(equality_sign,SIGNAL(clicked(bool)),this,SLOT(set_factor2()));
    connect(equality_sign,SIGNAL(clicked(bool)),this,SLOT(calculate_my_result()));
    connect(equality_sign,SIGNAL(clicked(bool)),this,SLOT(set_result()));

    setLayout(final_layout);
}

Widget::~Widget()
{

}
