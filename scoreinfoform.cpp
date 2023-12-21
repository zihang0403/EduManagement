#include "scoreinfoform.h"
#include "ui_scoreinfoform.h"

ScoreInfoForm::ScoreInfoForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScoreInfoForm)
{
    ui->setupUi(this);
}

ScoreInfoForm::~ScoreInfoForm()
{
    delete ui;
}
