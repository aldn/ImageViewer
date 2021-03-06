#pragma once

#include <QColorDialog>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QWidget>

class Display : public QWidget {
public:
    Display(QWidget* parent = Q_NULLPTR);
    ~Display();

    QString bgColorSlideshow();
    QString bgColorView();

    void setBgColorSlideshow(QString colorName);
    void setBgColorView(QString colorName);

private:
    void setup();
    void setConnections();
    void setWidgets();

    void pickBackgroundColorSlideshow();
    void pickBackgroundColorView();

    QGridLayout* backgroundColorSelection();

    QString m_colorView;
    QString m_colorSlideshow;

    QPushButton* m_selectColorSlideshow;
    QPushButton* m_selectColorView;
    QVBoxLayout* m_layout;
};