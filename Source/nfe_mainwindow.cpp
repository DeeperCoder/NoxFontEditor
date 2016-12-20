#include "nfe_mainwindow.h"
#include "ui_nfe_mainwindow.h"
#include "qlabel.h"
#include <QFileDialog>
#include "noxfontfile.h"

NFE_MainWindow::NFE_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NFE_MainWindow)
{
    ui->setupUi(this);
    QAction *OpenNFF = new QAction("&Открыть", this);
    QAction *SaveNFF = new QAction("&Сохранить", this);
    QAction *SaveAsNFF = new QAction("&Сохранить как...", this);
    ui->mainToolBar->addAction(OpenNFF);
    ui->mainToolBar->addAction(SaveNFF);
    ui->mainToolBar->addAction(SaveAsNFF);

    QLabel *StatusLabel = new QLabel(this);
    StatusLabel->setText("Worked 2!!!");

    QStatusBar *StatusBar = new QStatusBar(this);
    StatusBar->setSizeGripEnabled(false);
    StatusBar->addWidget(StatusLabel);
    setStatusBar(StatusBar);
}

NFE_MainWindow::~NFE_MainWindow()
{
    delete ui;
}

void NFE_MainWindow::on_pushButton_clicked()
{
    ui->listWidget->addItem("Русские буквы");

       QGraphicsScene *scene;
       scene = new QGraphicsScene(this);
       ui->SymbolView->setSceneRect(0, 0, 300, 300);
       ui->SymbolView->setScene(scene);

        QBrush greenBrush(Qt::green);
        QBrush blueBrush(Qt::blue);
        QPen outlinePen(Qt::black);
        outlinePen.setWidth(2);

        scene->addRect(0, 0, 80, 100, outlinePen, blueBrush);

        // addEllipse(x,y,w,h,pen,brush)
        scene->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);

        scene->addText("bogotobogo.com", QFont("Arial", 20) );
        scene->addText("LOL");
        scene->addRect(0, 0, 1, 1, QPen(), QBrush(Qt::SolidPattern));
//        double rad = 10;
//        int x, y = 0;
//        scene->addEllipse(x-rad, y-rad, rad*2.0, rad*2.0,
//                    QPen(), QBrush(Qt::SolidPattern));
        // movable text
//        text->setFlag(QGraphicsItem::ItemIsMovable);
}

void NFE_MainWindow::on_action_5_triggered()
{
    QApplication::quit();
}

void NFE_MainWindow::on_pushButton_2_clicked()
{
//    QFileDialog OpenFileDialog(this);
//    OpenFileDialog.setFileMode(QFileDialog::AnyFile);
//    OpenFileDialog.setNameFilter(tr("Nox Font File (*.fnt)"));
//    if (OpenFileDialog.exec()){
//        NoxFontFile Nfnt(OpenFileDialog.getOpenFileName(this));
//    }
    NoxFontFile Nfnt("E:\\Develop\\Nox Font Editor_Delphi\\garett_fonts\\default_3.fnt");

}
