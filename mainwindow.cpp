#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QColor>
#include <QFontComboBox>
#include <tableedit.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Open->setIcon(QIcon(":/icons/icons/icons8-opened-folder-50.png"));
    ui->Save->setIcon(QIcon(":/icons/icons/icons8-save-50.png"));
    ui->SaveAs->setIcon(QIcon(":/icons/icons/icons8-save-as-50.png"));
    ui->ExportDFX->setIcon(QIcon(":/icons/icons/icons8-document-50.png"));
    ui->actionJPEG->setIcon(QIcon(":/icons/icons/icons8-jpg-50.png"));
    ui->actionPNG->setIcon(QIcon(":/icons/icons/icons8-png-50.png"));
    ui->actionGIF->setIcon(QIcon(":/icons/icons/icons8-gif-50.png"));
    ui->table->setIcon(QIcon(":/icons/icons/icons8-data-sheet-50.png"));
    ui->actionRAW->setIcon(QIcon(":/icons/icons/icons8-raw-50.png"));
    ui->dot->setIcon(QIcon(":/icons/icons/icons8-map-pin-50.png"));
    ui->label->setIcon(QIcon(":/icons/icons/icons8-text-50.png"));
    ui->line->setIcon(QIcon(":/icons/icons/icons8-line-50.png"));
    ui->generate->setIcon(QIcon(":/icons/icons/icons8-play-50.png"));
    ui->group->setIcon(QIcon(":/icons/icons/icons8-group-objects-50.png"));
    ui->ungroup->setIcon(QIcon(":/icons/icons/icons8-ungroup-objects-50.png"));
    ui->delete_2->setIcon(QIcon(":/icons/icons/icons8-trash-can-50.png"));
    ui->hide->setIcon(QIcon(":/icons/icons/icons8-eye-50.png"));
    ui->fix->setIcon(QIcon(":/icons/icons/icons8-unlock-50.png"));
    QSpinBox *spin1 = new QSpinBox(), *spin2 = new QSpinBox();
    spin1->setMaximum(1200);
    spin1->setValue(200);
    spin2->setMaximum(1200);
    spin2->setValue(200);
    ui->toolBar_4->addWidget(spin1);
    ui->toolBar_4->addWidget(new QLabel("x"));
    ui->toolBar_4->addWidget(spin2);
    ui->toolBar_4->addSeparator();
    QPixmap a(50,50);
    a.fill();
    ui->color->setIcon(QIcon(a));
    ui->toolBar_4->addAction(ui->color);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->toolBar_4->clear();
    ui->group->setEnabled(false);
    ui->ungroup->setEnabled(false);
    if (ui->treeWidget->selectedItems().size() == 1)
        {
            if(item->text(0) == "Надпись") {
                QSpinBox *spin1 = new QSpinBox();
                spin1->setMaximum(1200);
                spin1->setValue(14);
                ui->toolBar_4->addWidget(new QFontComboBox());
                ui->toolBar_4->addWidget(spin1);
                ui->toolBar_4->addSeparator();
                QPixmap a(50,50);
                a.fill();
                ui->color->setIcon(QIcon(a));
                ui->toolBar_4->addAction(ui->color);
            } else if (item->text(0) == "Линия") {
                QSpinBox *spin1 = new QSpinBox();
                QComboBox *combo = new QComboBox();
                combo->addItem("Сплошная");
                combo->addItem("Пунктирная");
                spin1->setMaximum(1200);
                spin1->setValue(14);
                ui->toolBar_4->addWidget(new QLabel("Стиль линии:"));
                ui->toolBar_4->addWidget(combo);
                ui->toolBar_4->addWidget(new QLabel("   Толщина линии:"));
                ui->toolBar_4->addWidget(spin1);
                ui->toolBar_4->addSeparator();
                QPixmap a(50,50);
                a.fill();
                ui->color->setIcon(QIcon(a));
                ui->toolBar_4->addAction(ui->color);
            } else if (item->text(0) == "Точка") {
                QSpinBox *spin1 = new QSpinBox();
                spin1->setMaximum(1200);
                spin1->setValue(14);
                ui->toolBar_4->addWidget(new QLabel("Размер:"));
                ui->toolBar_4->addWidget(spin1);
                ui->toolBar_4->addSeparator();
                QPixmap a(50,50);
                a.fill();
                ui->color->setIcon(QIcon(a));
                ui->toolBar_4->addAction(ui->color);
            } else if (item->text(0) == "Группа") {
                ui->ungroup->setEnabled(true);
            }
        } else {
        ui->group->setEnabled(true);
    }
    ui->toolBar_4->addSeparator();
    ui->hide->setToolTip("Скрыть");
    ui->hide->setIcon(QIcon(":/icons/icons/icons8-eye-50.png"));
    ui->fix->setToolTip("Закрепить");
    ui->fix->setIcon(QIcon(":/icons/icons/icons8-unlock-50.png"));
    ui->toolBar_4->addAction(ui->hide);
    ui->toolBar_4->addAction(ui->fix);
}


void MainWindow::on_hide_triggered()
{
    if (ui->hide->toolTip() == "Скрыть") {
        ui->hide->setToolTip("Раскрыть");
        ui->hide->setIcon(QIcon(":/icons/icons/icons8-closed-eye-50.png"));
    } else if (ui->hide->toolTip() == "Раскрыть") {
        ui->hide->setToolTip("Скрыть");
        ui->hide->setIcon(QIcon(":/icons/icons/icons8-eye-50.png"));
    }
}


void MainWindow::on_fix_triggered()
{
    if (ui->fix->toolTip() == "Закрепить") {
        ui->fix->setToolTip("Открепить");
        ui->fix->setIcon(QIcon(":/icons/icons/icons8-lock-50.png"));
    } else if (ui->fix->toolTip() == "Открепить") {
        ui->fix->setToolTip("Закрепить");
        ui->fix->setIcon(QIcon(":/icons/icons/icons8-unlock-50.png"));
    }
}


void MainWindow::on_table_triggered()
{
    TableEdit *w = new TableEdit(this);
    w->show();
}


void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    if (ui->treeWidget->selectedItems().size() == 0) {
    ui->toolBar_4->clear();
    QSpinBox *spin1 = new QSpinBox(), *spin2 = new QSpinBox();
    spin1->setMaximum(1200);
    spin1->setValue(200);
    spin2->setMaximum(1200);
    spin2->setValue(200);
    ui->toolBar_4->addWidget(spin1);
    ui->toolBar_4->addWidget(new QLabel("x"));
    ui->toolBar_4->addWidget(spin2);
    ui->toolBar_4->addSeparator();
    QPixmap a(50,50);
    a.fill();
    ui->color->setIcon(QIcon(a));
    ui->toolBar_4->addAction(ui->color);
    }
}


void MainWindow::on_treeWidget_itemSelectionChanged()
{
}

