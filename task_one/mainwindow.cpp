#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(200,90);
    button=new QPushButton(this);
    button->setText("CLOSE THIS WINDOW :c");
    QObject::connect(button,SIGNAL(clicked(bool)),this,SLOT(close()));
    QWidget *widget=new QWidget;
    setCentralWidget(widget);
    QVBoxLayout* layout=new QVBoxLayout;
    layout->addStretch();
    layout->addWidget(button);
    layout->addStretch();
    widget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
