#ifndef RECOMMANDATIONWINDOW_H
#define RECOMMANDATIONWINDOW_H

#include <QWidget>
#include "User.h"
#include "Movie.h"
#include "CSVMovie.h"
#include "CosineSimilarity.h"
#include "Database.h"
#include "MoviePage.h"

namespace Ui {
class RecommandationWindow;
}

class RecommandationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RecommandationWindow(const User& user, QWidget *parent = nullptr);
    ~RecommandationWindow();

private:
    Ui::RecommandationWindow *ui;
    User m_user;

private slots:
    void onReturnClick();
    void onMovieDoubleClick(QListWidgetItem* item);
};

#endif // RECOMMANDATIONWINDOW_H
