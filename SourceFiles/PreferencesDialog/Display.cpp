#include "Display.h"

Display::Display(QWidget* parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout(this);
    m_selectColorSlideshow = new QPushButton(this);
    m_selectColorView = new QPushButton(this);

    setup();
}

Display::~Display()
{
}

void Display::setup()
{
    setLayout(m_layout);
    setConnections();
    setWidgets();
}

void Display::setWidgets()
{
    m_selectColorView->setStyleSheet(
        "QPushButton { background-color: #ffffff; }");

    m_layout->addWidget(new QLabel("<b>Background color</b>", this));
    m_layout->addLayout(backgroundColorView());
    m_layout->addLayout(backgroundColorSlideshow());
}

QHBoxLayout* Display::backgroundColorView()
{
    QHBoxLayout* layout = new QHBoxLayout(m_layout->widget());

    layout->addWidget(new QLabel("\tView mode"));
    layout->addWidget(m_selectColorView);

    return (layout);
}

void Display::setConnections()
{
    connect(m_selectColorSlideshow, &QPushButton::clicked, this,
        &Display::pickBackgroundColorSlideshow);
    connect(m_selectColorView, &QPushButton::clicked, this,
        &Display::pickBackgroundColorView);
}

void Display::pickBackgroundColorView()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) {
        return;
    }

    setBgColorView(color.name());
}

QHBoxLayout* Display::backgroundColorSlideshow()
{
    QHBoxLayout* layout = new QHBoxLayout(m_layout->widget());

    layout->addWidget(new QLabel("\tSlideshow mode"));
    layout->addWidget(m_selectColorSlideshow);

    return (layout);
}

QString Display::bgColorView()
{
    return (m_colorView);
}

void Display::setBgColorView(QString colorName)
{
    m_colorView = colorName;
    m_selectColorView->setStyleSheet(
        "QPushButton { background-color: " + colorName + "; }");
}

QString Display::bgColorSlideshow()
{
    return (m_colorSlideshow);
}

void Display::setBgColorSlideshow(QString colorName)
{
    m_colorSlideshow = colorName;
    m_selectColorSlideshow->setStyleSheet(
        "QPushButton { background-color: " + colorName + "; }");
}

void Display::pickBackgroundColorSlideshow()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) {
        return;
    }

    setBgColorSlideshow(color.name());
}