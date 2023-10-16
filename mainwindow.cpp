#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "cpuinfo.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

//    ui->label->setProperty("text", "New Text");
//    ui->instructions_listWidget->addItem("test");
//    ui->instructionDescription_textBrowser->setText("test");

    ui->ProductName->setText(QString::fromStdString(cpu_name()));
    ui->Vendor->setText(QString::fromStdString(vendor_ID()));
    ui->ProcessorType->setText(QString::fromStdString(cpu_type()));

    ui->Family->setText(QString::number(cpu_family(), 16).toUpper());
    ui->Model->setText(QString::number(cpu_model()));
    ui->Stepping->setText(QString::number(cpu_stepping(), 16).toUpper());
}

MainWindow::~MainWindow()
{
    delete ui;
}
