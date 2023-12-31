#include "Student.h"
#include "mainwindow.h"
#include "mysqlconnector.h"
#include "ui_mainwindow.h"
#include "studentinfowindow.h"
#include "teacherinfowindow.h"

#include <QFile>
#include <QButtonGroup>
#include <QMessageBox>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // 将设计的用户界面加载到此类中，并设置对应的属性，信号，槽等，完成相应的初始化工作
    ui->setupUi(this);

    // 创建ButtonGroup
    QButtonGroup *buttonGroup = new QButtonGroup(parent);

    // 使用ButtonGroup将两个RadioButtion绑定
    buttonGroup->addButton(ui->stuRadioButton);
    buttonGroup->addButton(ui->teacherRadioButton);

    // 将学生按钮设置为默认选中
    ui->stuRadioButton->setChecked(true);
    loginProperty = false;

    // 两个QRadioButton按钮，信号为按钮点击，绑定同一槽函数但传递不同参数
    connect(ui->stuRadioButton, &QPushButton::clicked, this, [=](){
        // lambda表达式通过捕获使用当前类的成员函数
        setLoginProperty(false);
    });
    connect(ui->teacherRadioButton, &QPushButton::clicked, this, [=](){
        // 使用lambda表达式即可通过触发信号传递槽函数的参数
        setLoginProperty(true);
    });

    ui->stuRadioButton->setShortcut(Qt::Key_BraceLeft);
    ui->teacherRadioButton->setShortcut(Qt::Key_BraceRight);
    ui->loginButton->setShortcut(Qt::Key_Return);

    // 登录按钮点击信号绑定LoginButtonClick函数，执行登录时操作
    connect(ui->loginButton, &QPushButton::clicked, this, [=](){
        QString userName = ui->userName->text();
        QString password = ui->password->text();
        LoginButtonClick(userName, password);
    });

    }

MainWindow::~MainWindow()
{
    delete ui;
}

// 设置登录属性
void MainWindow::setLoginProperty(bool prop = false)
{
    loginProperty = prop;
}

// 开始登录
void MainWindow::LoginButtonClick(const QString &userName, const QString &password)
{
//    QString loginPropertyStr = loginProperty ? "true" : "false";
//    QMessageBox::information(this, "登录状态", "loginProperty = " + loginPropertyStr);
//    qWarning() << "loginProperty = " << loginProperty;

    MySqlConnector *conn = new MySqlConnector;
    if(!conn->DataBaseConnect())
    {
        qDebug() << "连接失败！" << Qt::endl;
            return;
    }


    QString sql;
    QSqlQuery query;

    if(loginProperty)
    {
        sql = "SELECT * FROM teacherinfo WHERE teacherid = :id";
    }
    else
    {
        sql = "SELECT * FROM studentinfo WHERE studentid = :id";
    }

    if(query.prepare(sql))
    {
        query.bindValue(":id", userName);
        if(query.exec())
        {
            if(query.next())
            {
                QString pwd = query.value("password").toString();
                if(pwd == password)
                {
                    QMessageBox::information(this, "提示", "登录成功！", QMessageBox::Ok);
                    this->hide();

                    QString name = query.value("name").toString();
                    QString sex = query.value("sex").toString();
                    QString institute = query.value("institute").toString();
                    QDate bornDay = query.value("bornday").toDate();
                    if(loginProperty)
                    {

                        QString position = query.value("position").toString();
//                        QString teachCourse = query.value("teachcourse").toString();
                        Teacher *tea = new Teacher(userName, pwd, name, sex, position, institute, bornDay);
                        showTeacherInfoWindow(tea);
                    }
                    else
                    {
                        Student *stu = new Student(userName, pwd, name, sex, bornDay, institute);
                        showStudentInfoWindow(stu);
                    }
                }
                else
                {
                    QMessageBox::information(this, "提示", "密码错误！请检查输入的密码是否正确！", QMessageBox::Ok);
                }
            }
            else
            {
                QMessageBox::information(this, "提示", "账号错误", QMessageBox::Ok);
            }
        }
        else
        {
            qDebug() << "查询失败！：" << query.lastError().text();
        }
    }
    else
    {
        qDebug() << "准备查询失败！：" << query.lastError().text();
    }

    conn->DataBaseClose();
    delete conn;
}

void MainWindow::showMainWindow()
{
    QLineEdit *password = findChild<QLineEdit*>("password");
    password->clear();
    show();
}

void MainWindow::showStudentInfoWindow(Student *student)
{
    StudentInfoWindow *studentInfoWindow = new StudentInfoWindow(this, student);
    connect(studentInfoWindow, &StudentInfoWindow::returnToMainWindow, this, &MainWindow::showMainWindow);
    studentInfoWindow->show();
}

void MainWindow::showTeacherInfoWindow(Teacher *teacher)
{
    TeacherInfoWindow *teacherInfoWindow = new TeacherInfoWindow(this, teacher);
    connect(teacherInfoWindow, &TeacherInfoWindow::returnToMainWindow, this, &MainWindow::showMainWindow);
    teacherInfoWindow->show();
}
