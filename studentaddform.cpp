#include "Student.h"
#include "studentaddform.h"
#include "ui_studentaddform.h"

#include <QDate>

StudentAddForm::StudentAddForm(QWidget *parent, Teacher *teacher)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::StudentAddForm)
{
    ui->setupUi(this);

    QStringList sex;
    sex << "男" << "女";
    ui->sex->addItems(sex);

    connect(ui->submit, &QPushButton::clicked, this, [=]{
        submitButtonClick(ui, teacher);
    });
}

StudentAddForm::~StudentAddForm()
{
    delete ui;
}

void StudentAddForm::submitButtonClick(Ui::StudentAddForm *ui, Teacher *teacher)
{
    Student *student = new Student(
        ui->studentid->text(),
        ui->studentid->text(),
        ui->name->text(),
        ui->sex->currentText(),
        ui->bornday->date(),
        teacher->getInstitute());
    delete student;
}
