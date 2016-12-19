#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStringList>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

~MainWindow();
    QString FileName1;
    QString FileName2;
    QString FileName3;
    QString PreviousFile;
    QString PreviousFile1;

public slots:
    void Stegn();
    void GetCoverImageName();
    void GetSecretFileName();
    void GetStegoFileName();
    void Invstegn();
    void ViewCoverImage();
    void ViewStegoImage();
    void ViewPreviousFile();
    void ViewOriginalImage();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
