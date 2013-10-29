QT += core gui widgets
TARGET = TPE
TEMPLATE = app
QMAKE_CXXFLAGS += --std=c++0x

qSFMLDir = "/home/zerp/Projects/QSFML"

LIBS += -L$$qSFMLDir/libs -lQSFML \
	-lsfml-system -lsfml-graphics -lsfml-window

INCLUDEPATH += $$qSFMLDir/include


SOURCES += \
    main.cpp \
    Pikachu.cpp \
    gui/MainWindow.cpp \
    gui/WidgetAnimation.cpp \
    math/Fraction.cpp \
    math/Fraction.tpp \
    math/Probability.cpp \
    PikachuGenerator.cpp \
    GWTree.cpp \
    GWEntity.cpp \
    GWRules.cpp \
    gui/QSizedTableWidget.cpp \
    math/Math.cpp \
    math/Math.tpp \
    Example.cpp

HEADERS += \
    Pikachu.hpp \
    global.hpp \
    gui/MainWindow.hpp \
    gui/WidgetAnimation.hpp \
    math/Fraction.hpp \
    math/Probability.hpp \
    PikachuGenerator.hpp \
    GWTree.hpp \
    GWEntity.hpp \
    GWRules.hpp \
    gui/QSizedTableWidget.hpp \
    math/Math.hpp

FORMS += \
    gui/MainWindow.ui
