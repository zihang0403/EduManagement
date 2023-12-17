#include "scoremanageform.h"
#include "ui_scoremanageform.h"

ScoreManageForm::ScoreManageForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScoreManageForm)
{
    ui->setupUi(this);
}

ScoreManageForm::~ScoreManageForm()
{
    delete ui;
}
