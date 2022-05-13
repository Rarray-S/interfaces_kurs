#ifndef TABLEEDIT_H
#define TABLEEDIT_H

#include <QMainWindow>

namespace Ui {
class TableEdit;
}

class TableEdit : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableEdit(QWidget *parent = nullptr);
    ~TableEdit();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::TableEdit *ui;
};

#endif // TABLEEDIT_H
