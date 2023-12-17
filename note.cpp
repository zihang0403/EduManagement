#include "note.h"
// 此文件非工程中文件
#ifdef NOTE

#include "ui_note.h"
note::note(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::note)
{
    ui->setupUi(this);
    // page->resize(500, 400);

    // //使用网格布局
    // QGridLayout *layout = new QGridLayout(page);
    // QLabel *nameL = new QLabel("姓名");
    // QLabel *name = new QLabel(userName);
    // QPushButton *exit = new QPushButton("退出登录");
    // QFont font("Arial", 20);
    // nameL->setFont(font);
    // name->setFont(font);
    // nameL->setFixedSize(150, 100);
    // name->setFixedSize(150, 100);
    // QSpacerItem *horizontalSpacer = new QSpacerItem(10, 0);
    // layout->addItem(horizontalSpacer, 0, 0);
    // layout->addItem(horizontalSpacer, 0, 1);
    // layout->addItem(horizontalSpacer, 0, 2);
    // layout->addWidget(nameL, 0, 4);
    // layout->addWidget(name, 0, 5);
    // layout->addItem(horizontalSpacer, 1, 0);
    // layout->addItem(horizontalSpacer, 1, 1);
    // layout->addItem(horizontalSpacer, 1, 2);
    // layout->addItem(horizontalSpacer, 1, 3);
    // layout->addWidget(exit, 1, 4);
    // layout->setRowStretch(0,1);

    page->resize(500, 400);
    // 使用水平布局嵌套垂直布局

    QHBoxLayout *layout2 = new QHBoxLayout(page);
    QVBoxLayout *layout = new QVBoxLayout(page);

    layout2->addLayout(layout);

    QLabel *nameL = new QLabel("姓名");
    QLabel *name = new QLabel(userName);
    QPushButton *exit = new QPushButton("退出登录");
    QFont font("Arial", 20);
    nameL->setFont(font);
    name->setFont(font);
    nameL->setFixedSize(150, 100);
    name->setFixedSize(150, 100);

    layout2->addWidget(nameL);
    layout2->addWidget(name);
    layout->addWidget(exit);

    layout2->setAlignment(nameL, Qt::AlignHCenter);
    layout2->setAlignment(name, Qt::AlignHCenter);
    layout->setAlignment(exit, Qt::AlignHCenter);

    // 读取QSS文件，绝对路径没问题相对路径有问题，背景图片布局待修改
    //    QString appDir = QCoreApplication::applicationDirPath();
    //    QFile styleFile(appDir + "/mainStyle.qss");
    ////    QFile styleFile(appDir + "/1.txt");
    //    if(styleFile.open(QFile::ReadOnly|QFile::Text))
    //    {
    //        QString styleSheet = QLatin1String(styleFile.readAll());
    //        this->setStyleSheet(styleSheet);
    //    }
    //    else
    //    {
    //        QMessageBox::information(this, "文件读取状态", "失败！");
    //    }

    // w.setWindowTitle(QString("教务管理系统"));

    //    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //    db.setHostName("localhost");
    //    db.setPort(3306);
    //    db.setUserName("root");
    //    db.setPassword("123456");
    //    db.setDatabaseName("edumanagement");

    //    if(!db.open())
    //    {
    //        QSqlError error = db.lastError();
    //        qDebug() << "Failed to connect to database:";
    //        qDebug() << "Type:" << error.type();
    //        qDebug() << "Database driver text:" << error.databaseText();
    //        qDebug() << "Driver text:" << error.driverText();
    //        qDebug() << "Text:" << error.text();
    //        return -1;
    //    }
    //    qDebug() << "连接成功！" ;
    //    QSqlQuery query;
    //    if(query.exec("select * from student"))
    //    {
    //        while(query.next())
    //        {
    //            QString id = query.value("id").toString();
    //            QString name = query.value("name").toString();
    //            qDebug() << "id:" << id << " name:" << name << Qt::endl;
    //        }
    //    }

    //    db.close();


    // 重新打开主窗口
    // void MainWindow::reShowMainWindow()
    // {
    //     qDebug() << "before" ;
    //     this->show();
    //     qDebug() << "after" ;
    // }

    // 获取当前主窗口对象并返回，用于重新打开主窗口
    // MainWindow *MainWindow::getInstance()
    // {
    //     static MainWindow *instance = new MainWindow;
    //     instance->show();
    //     return instance;
    // }

    // QListWidget sidebar;
    // ui->sidebar->setGeometry(10,10,120,1000);
    // QFont font = ui->sidebar->font();
    // font.setPointSize(14);
    // ui->sidebar->setFont(font);

    //页面
    // QStackedWidget contentStack;
    // ui->contentStack->addWidget(page1);
    // ui->contentStack->addWidget(page2);
    // ui->contentStack->addWidget(page3);
    // ui->contentStack->addWidget(page4);

    // setCentralWidget(ui->contentStack);

    // ui->sidebar->setParent(this);
    // ui->contentStack->setParent(this);
}

note::~note()
{
    delete ui;
}

#endif
