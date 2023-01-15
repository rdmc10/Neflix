#pragma once

#include <QMainWindow>
#include "ui_RecommandationWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RecommandationWindowClass; };
QT_END_NAMESPACE

class RecommandationWindow : public QMainWindow
{
	Q_OBJECT

public:
	RecommandationWindow(QWidget *parent = nullptr);
	~RecommandationWindow();

private:
	Ui::RecommandationWindowClass *ui;
};
