#include "pathselect.h"
#include "ui_pathselect.h"
#include <QFileDialog>
#include <QMessageBox>
#include "stock.h"
#include "dialog.h"

PathSelect::PathSelect(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PathSelect)
{
    setWindowTitle("路径选择");
    ui->setupUi(this);
}

PathSelect::~PathSelect()
{
    delete ui;
}

void PathSelect::on_pushButton_clicked()
{
    QString selectedFile = QFileDialog::getOpenFileName(this, "选择文件", QDir::homePath(), "All Files (*)");

    if(selectedFile.isEmpty()) {
        QMessageBox::information(this, "提示", "您取消了选择文件操作。");
    } else {
        QMessageBox::information(this, "选择的文件", "您选择了文件：" + selectedFile);
        inputFile = selectedFile.toStdString();
    }
    this->show();
}


void PathSelect::on_pushButton_2_clicked()
{
    QString selectedFile = QFileDialog::getExistingDirectory(this, "选择文件夹", QDir::homePath());

    if(selectedFile.isEmpty()) {
        QMessageBox::information(this, "提示", "您取消了选择文件夹操作。");
    } else {
        QMessageBox::information(this, "选择的文件", "您选择了文件夹：" + selectedFile);
        outputPath = selectedFile.toStdString();
    }
    this->show();
    QMessageBox::information(nullptr, "提示", "开始外排序");
    /*进行外排序*/
    Stock data(inputFile, outputPath, outputPath+"\\index.txt");
    data.externSort();
    QMessageBox msgBox(QMessageBox::Question,
                       "提示",
                       "是否要开始创建索引？",
                       QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);

    int ret = msgBox.exec();

    // 如果用户点击了 "Ok" 按钮，就执行索引创建操作
    if (ret == QMessageBox::Ok) {
        data.createIndex();
    }
    QMessageBox::information(nullptr, "提示", "索引创建结束");
    Dialog *dialog = new Dialog(nullptr, data);
    dialog->setAttribute(Qt::WA_DeleteOnClose); // 确保窗口关闭时自动删除
    dialog->show();
}

std::string PathSelect::getInput()
{
    return inputFile;
}

std::string PathSelect::getOutput()
{
    return outputPath;
}

