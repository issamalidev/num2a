#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QDialog>

namespace Ui {
class MainView;
}

class MainView : public QDialog
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private slots:
    void on_btnNum2aW_clicked();

    void on_btnFnum2aW_clicked();

    void on_btnGetFnum2aW_clicked();

    void on_btnGetnum2aW_clicked();

private:
    Ui::MainView *ui;
};

#endif // MAINVIEW_H
