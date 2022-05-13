#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_hide_triggered();

    void on_fix_triggered();

    void on_table_triggered();

    void on_treeWidget_clicked(const QModelIndex &index);

    void on_treeWidget_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
