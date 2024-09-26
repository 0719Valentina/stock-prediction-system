#ifndef PATHSELECT_H
#define PATHSELECT_H

#include <QMainWindow>
#include <string>
#include "dialog.h"

namespace Ui {
class PathSelect;
}

class PathSelect : public QMainWindow
{
    Q_OBJECT

public:
    explicit PathSelect(QWidget *parent = nullptr);
    ~PathSelect();
    std::string getInput();
    std::string getOutput();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PathSelect *ui;
    std::string inputFile;
    std::string outputPath;
};

#endif // PATHSELECT_H
