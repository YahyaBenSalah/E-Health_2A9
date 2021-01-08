#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the app style sheet
    QFile styleSheetFile("C:/Users/Bruce/Desktop/project/E-Health/SpyBot.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    MainWindow w;
       static Connection c;
       c.createconnect();
       w.show();
       return a.exec();
          }
