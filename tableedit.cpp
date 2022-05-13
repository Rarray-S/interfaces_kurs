#include "tableedit.h"
#include "ui_tableedit.h"

TableEdit::TableEdit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableEdit)
{
    ui->setupUi(this);
}

TableEdit::~TableEdit()
{
    delete ui;
}

void TableEdit::on_pushButton_3_clicked()
{
    close();
}

