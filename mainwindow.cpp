#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vkauthenticator.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    VkAuthenticator * vkauth = new VkAuthenticator("");

    ui->setupUi(this);
    connect(ui->_button, SIGNAL(clicked(bool)), vkauth, SLOT(authenticate()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}
