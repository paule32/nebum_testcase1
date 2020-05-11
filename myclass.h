#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMainWindow>
#include <QWidget>
#include <QProgressBar>
#include <QAbstractItemDelegate>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QModelIndex>


QT_BEGIN_NAMESPACE
namespace Ui { class MyClass; }
QT_END_NAMESPACE

class ProgressDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ProgressDelegate(QObject *parent = nullptr)
    { }

    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QProgressBar * pbar = new QProgressBar(parent);
        pbar->setMinimum(  5);
        pbar->setMaximum(100);
        pbar->setValue  ( 20);
        return pbar;
    }
    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        int value = index.model()->data(index,Qt::UserRole).toInt();
        QProgressBar *progressBar = static_cast<QProgressBar*>(editor);
        progressBar->setValue(value);
    }
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QProgressBar *progressBar = static_cast<QProgressBar*>(editor);
        int value = progressBar->value();
        model->setData(index, value, Qt::UserRole);
    }
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex&) const override {
        editor->setGeometry(option.rect);
    }
};

class MyClass : public QMainWindow
{
    Q_OBJECT

public:
    MyClass(QWidget *parent = nullptr);
    ~MyClass();

private:
    Ui::MyClass *ui;
};
#endif // MYCLASS_H
