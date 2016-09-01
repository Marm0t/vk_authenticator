#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vkauthenticator.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->_button, SIGNAL(clicked(bool)), this, SLOT(go()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::go()
{
    VkAuthenticator * vkauth = new VkAuthenticator(ui->_appIdEdit->text(),
                                                   ui->_rightsEdit->text());
    connect(vkauth, SIGNAL(tokenReceived(QString)), this->statusBar() ,SLOT(showMessage(QString)) );
    connect(vkauth, SIGNAL(error(QString)), this->statusBar() ,SLOT(showMessage(QString)) );
    vkauth->authenticate();
}
