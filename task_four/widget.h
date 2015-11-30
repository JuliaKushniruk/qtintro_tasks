#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QRadioButton>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>

class Widget : public QWidget
{
    Q_OBJECT

    QRadioButton *red_button;
    QRadioButton *orange_button;
    QRadioButton *green_button;

    QPushButton* start_button;
    QPushButton* stop_button;

    QLabel* red_label;
    QLabel* orange_label;
    QLabel* green_label;
public slots:
    void red_light_on();
    void orange_light_on();
    void green_light_on();
    void disable_lights();
    void enable_lights();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
