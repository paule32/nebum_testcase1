#include "myclass.h"

#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStandardItemModel model(5, 2);
    QTableView tableView;
    tableView.setModel(&model);

    ProgressDelegate prog;
    tableView.setItemDelegate(&prog);

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 2; ++col) {
            QModelIndex index = model.index(row, col, QModelIndex());
            model.setData(index, QVariant((row + 1) * (col + 1)));
        }
    }

    tableView.show();

    return a.exec();
}
