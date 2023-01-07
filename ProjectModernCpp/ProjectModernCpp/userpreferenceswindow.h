#ifndef USERPREFERENCESWINDOW_H
#define USERPREFERENCESWINDOW_H

#include <QWidget>

namespace Ui {
class UserPreferencesWindow;
}

class UserPreferencesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserPreferencesWindow(QWidget *parent = nullptr);
    ~UserPreferencesWindow();

private:
    Ui::UserPreferencesWindow *ui;
};

#endif // USERPREFERENCESWINDOW_H
