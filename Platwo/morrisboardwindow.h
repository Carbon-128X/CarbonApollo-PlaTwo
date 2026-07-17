#ifndef MORRISBOARDWINDOW_H
#define MORRISBOARDWINDOW_H

#include <QWidget>

namespace Ui {
class MorrisBoardWindow;
}

class MorrisBoardWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MorrisBoardWindow(QWidget *parent = nullptr);
    ~MorrisBoardWindow();

private:
    Ui::MorrisBoardWindow *ui;
};

#endif // MORRISBOARDWINDOW_H
