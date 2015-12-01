#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QRadioButton>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QTimer>
class Widget : public QWidget
{
    Q_OBJECT
    QRadioButton *red_button;
    QRadioButton *yellow_button;
    QRadioButton *green_button;

    QPushButton* start_button;
    QPushButton* stop_button;

    QTimer *timer;

    bool toRed;


public slots:
    void change_light();
    void disable_lights();
    void enable_lights();
    void set_timer_start();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
