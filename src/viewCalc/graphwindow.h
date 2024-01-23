#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QMainWindow>

//#include "../controller.h" // path - controller

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

private slots:
    void on_pushButton_draw_clicked();

private:
    Ui::GraphWindow *ui;
};

#endif // GRAPHWINDOW_H
