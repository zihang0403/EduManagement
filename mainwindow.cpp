#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QButtonGroup>
#include <QMessageBox>

// 登录属性：学生/教师
static bool loginProperty = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // 将设计的用户界面加载到此类中，并设置对应的属性，信号，槽等，完成相应的初始化工作
    ui->setupUi(this);

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

    // 创建ButtonGroup
    QButtonGroup *buttonGroup = new QButtonGroup(parent);

    // 使用ButtonGroup将两个RadioButtion绑定
    buttonGroup->addButton(ui->stuRadioButton);
    buttonGroup->addButton(ui->teacherRadioButton);

    // 将学生按钮设置为默认选中
    ui->stuRadioButton->setChecked(true);

    // 两个QRadioButton按钮，信号为按钮点击，绑定同一槽函数但传递不同参数
    connect(ui->stuRadioButton, &QPushButton::clicked, this, [=](){
        // lambda表达式通过捕获使用当前类的成员函数
        setLoginProperty(false);
    });
    connect(ui->teacherRadioButton, &QPushButton::clicked, this, [=](){
        // 使用lambda表达式即可通过触发信号传递槽函数的参数
        setLoginProperty(true);
    });

    // 登录按钮点击信号绑定LoginButtonClick函数，执行登录时操作
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::LoginButtonClick);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// 重新打开主窗口
void MainWindow::reShowMainWindow()
{
    this->show();
}

// 获取当前主窗口对象并返回，用于重新打开主窗口
MainWindow *MainWindow::getInstance()
{
    static MainWindow *instance;
    return instance;
}

// 设置登录属性
void MainWindow::setLoginProperty(bool prop = false)
{
    loginProperty = prop;
}

// 开始登录
void MainWindow::LoginButtonClick()
{
    QString loginPropertyStr = loginProperty ? "true" : "false";
    QMessageBox::information(this, "登录状态", "loginProperty = " + loginPropertyStr);
    qWarning() << "loginProperty = " << loginProperty;
}
