#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QString>
#include <QValidator>
class Widget : public QWidget
{
    Q_OBJECT
private:
    QLineEdit* field1;
    QLabel* operation;
    QLineEdit* field2;
    QPushButton* equality_sign;
    QLineEdit* result;
    QPushButton* clear_button;
    QPushButton* exit_button;
    int factor1, factor2, my_result;
    QValidator* validator;
public slots:
    void set_factor1();
    void set_factor2();
    void calculate_my_result();
    void set_result();
    void clear_fields();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
