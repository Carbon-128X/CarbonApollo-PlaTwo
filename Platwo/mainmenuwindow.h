#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H
#include <QWidget>

namespace Ui {
class MainMenuWindow;
}

class MainMenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWindow(QWidget *parent = nullptr);
    ~MainMenuWindow();

private:
    Ui::MainMenuWindow *ui;
};

#endif // MAINMENUWINDOW_H

