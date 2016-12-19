#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QLabel>
#include<QDebug>
#include<QMessageBox>
#include<QImage>
#include<QErrorMessage>
#include<QFile>
#include<QTextStream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Stegn()
{
    const char *c_str4 ;
    QString progname;
    int flag = 0;
    if(FileName1.endsWith(".ppm"))
        flag = 0;
    else if(FileName1.endsWith(".bmp"))
        flag = 1;
    else
        flag = 2;

    if(flag == 0)
        progname = "./stegn3 ";
    if(flag == 1)
        progname = "./stegnbmp ";
    if(flag == 2)
        progname = "./stegnjpg ";
    progname.append(FileName1);    
    if(FileName1.isNull() == true)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Cover image not specified");
        msgBox.exec();
        return;

    }
    PreviousFile1 = FileName1;
    if(FileName2.isNull() == true)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Secret file not specified");
        msgBox.exec();
        return;
    }
   if(ui->checkBox->isChecked())
   {    QString passwd = "password";
       passwd = ui->lineEdit->text();
       if(passwd.isEmpty())
       {
           QMessageBox msgBox;
           msgBox.setIcon(QMessageBox::Critical);
           msgBox.setText("Key not Entered");
           msgBox.exec();
           return;
       }
        QString cmd1 = "aes128/./a.out ";
        cmd1.append(FileName2);
        cmd1.append(" temp g ");
        cmd1.append(passwd);

        QByteArray ba2 = cmd1.toLocal8Bit();
              const char *c_str3 = ba2.data();
              system(c_str3);
              QByteArray ba3 = FileName2.toLocal8Bit();
                    c_str4 = ba3.data();
                    FileName2 =  basename(c_str4);
                    rename("temp",basename(c_str4));
                    if(flag == 0)
                    {
        progname.append(" stegnimg/sTegn1.ppm ");
        PreviousFile = "stegnimg/sTegn1.ppm";
                    }
                   else if(flag == 1)
                    {
        progname.append(" stegnimg/sTegn1.bmp ");
        PreviousFile = "stegnimg/sTegn1.bmp";
                    }
                   else
                    {
        progname.append(" stegnimg/sTegn1.ppm ");
        PreviousFile = "stegnimg/sTegn1.ppm";
                    }
        progname.append(FileName2);


    }
else
   {
       if(flag == 0)
       {
progname.append(" stegnimg/stegn1.ppm ");
PreviousFile = "stegnimg/stegn1.ppm";
       }
      else if(flag == 1)
       {
progname.append(" stegnimg/stegn1.bmp ");
PreviousFile = "stegnimg/stegn1.bmp";
       }
      else
       {
progname.append(" stegnimg/stegn1.ppm ");
PreviousFile = "stegnimg/stegn1.ppm";
       }
       progname.append(FileName2);
   }



    QByteArray ba = progname.toLocal8Bit();
          const char *c_str2 = ba.data();
    system(c_str2);
    if(ui->checkBox->isChecked())remove(basename(c_str4));
    ui->Browse1->setText("Browse...");
    ui->Browse2->setText("Browse...");
    FileName1.clear();
    FileName2.clear();
    ui->lineEdit->clear();


}
void MainWindow::GetCoverImageName()
{
    QString temp;
    temp = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/ubuntu/Downloads", tr("Image Files (*.ppm *.bmp *.jpeg *.jpg)"));
    if(temp.isEmpty() == false)
    {
        ui->Browse1->setText("Done");
        FileName1 = temp;
    }
            //else ui->Browse1->setText("Browse...");

}
void MainWindow::GetSecretFileName()
{
    QString temp;
    temp = QFileDialog::getOpenFileName(this,
        tr("Any File"), "/home/ubuntu", tr("Any File (*)"));
    if(temp.isEmpty() == false)
    {
        ui->Browse2->setText("Done");
        FileName2 = temp;
    }
}
void MainWindow::ViewCoverImage()
{

    QString path = "eog ";
    if(FileName1.isEmpty() == true)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Cover image not specified");
        msgBox.exec();
        return;

    }
    path.append(FileName1);
    QImage img1(FileName1);

    QByteArray ba2 = path.toLocal8Bit();
          const char *c_str3 = ba2.data();
          system(c_str3);
}
void MainWindow::Invstegn()
{
    QString progname;
    int flag = 0;
    if(FileName3.endsWith(".ppm"))
        flag = 0;
    else if(FileName3.endsWith(".bmp"))
        flag = 1;
    else
        flag = 2;

    if(flag == 0)
        progname = "./invstegn3 ";
    if(flag == 1)
        progname = "./invstegnbmp ";
    if(flag == 2)
        progname = "./invstegnjpg ";
    QString passwd = "password";


    if(FileName3.isNull() == true)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Stego image not specified");
        msgBox.exec();
        return;

    }
     progname.append(FileName3);
     if(flag == 0)
     progname.append(" >> temp.log");
     QByteArray ba = progname.toLocal8Bit();
           const char *c_str2 = ba.data();
           system(c_str2);
           if(ui->lineEdit_2->isEnabled()){
           QFile file("temp.log");
           file.open(QIODevice::ReadOnly | QIODevice::Text);
           QTextStream in(&file);
           QString line = in.readLine();

           progname = "aes128/./a.out ";
           progname.append(line);
           progname.append(" temp i ");
           passwd = ui->lineEdit_2->text();
           if(passwd.isEmpty())
           {
               QMessageBox msgBox;
               msgBox.setIcon(QMessageBox::Critical);
               msgBox.setText("Key not Entered");
               msgBox.exec();
               remove("temp.log");
               return;
           }
           progname.append(passwd);
            ba = progname.toLocal8Bit();
                 c_str2 = ba.data();
                 system(c_str2);
                 ba = line.toLocal8Bit();
                      c_str2 = ba.data();
                 remove(c_str2);
                 rename("temp",c_str2);
           }
                 remove("temp.log");
                 ui->Browse3->setText("Browse...");
                 FileName3.clear();
                 ui->lineEdit_2->clear();

}
void MainWindow::GetStegoFileName()
{
    QString temp;
    temp = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/ubuntu/stegno/stegno-build-desktop-Desktop_Qt_4_8_1_for_GCC__Qt_SDK__Release/stegnimg", tr("Image Files (*.ppm *.bmp)"));
    if(temp.isEmpty() == false)
    {
        ui->Browse3->setText("Done");
        FileName3 = temp;
    }
    QByteArray ba = FileName3.toLocal8Bit();
          const char *c_str2 = ba.data();
          if((*(basename(c_str2)+1) & 0x20) != 0x20)
          {
              ui->Enterkey2->setEnabled(true);
              ui->label->setEnabled(true);
              ui->lineEdit_2->setEnabled(true);
          }
          else
          {
              ui->Enterkey2->setDisabled(true);
              ui->label->setDisabled(true);
              ui->lineEdit_2->setDisabled(true);
          }


}
void MainWindow::ViewStegoImage()
{
    QString path = "eog ";
    if(FileName3.isEmpty() == true)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Stego image not specified");
        msgBox.exec();
        return;

    }

    path.append(FileName3);
    path.append(" &");
    QByteArray ba2 = path.toLocal8Bit();
          const char *c_str3 = ba2.data();
          system(c_str3);
}
void MainWindow::ViewPreviousFile()
{
    QString Command = "eog ";
    if(PreviousFile.isEmpty() == true)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Stego image not generated");
        msgBox.exec();
        return;

    }

    Command.append(PreviousFile);
    Command.append(" &");
    QByteArray ba2 = Command.toLocal8Bit();
          const char *c_str3 = ba2.data();
          system(c_str3);
}
void MainWindow::ViewOriginalImage()
{
    QString Command = "eog ";
    if(PreviousFile1.isEmpty() == true)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Original image not specified");
        msgBox.exec();
        return;

    }

    Command.append(PreviousFile1);
     Command.append(" &");
    QByteArray ba2 = Command.toLocal8Bit();
          const char *c_str3 = ba2.data();
          system(c_str3);
}
