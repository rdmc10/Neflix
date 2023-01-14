#ifndef WISHLISTPAGE_H
#define WISHLISTPAGE_H

#include <QWidget>
#include "User.h"
#include "CSVMovie.h"
#include "MoviePage.h"

namespace Ui {
class WishlistPage;
}

class WishlistPage : public QWidget
{
    Q_OBJECT

public:
    explicit WishlistPage(const User& user, QWidget *parent = nullptr);
    ~WishlistPage();

private:
    Ui::WishlistPage *ui;
    User m_user;

private slots:
    void onCloseButtonClick();

};

#endif // WISHLISTPAGE_H
