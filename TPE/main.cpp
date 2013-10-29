#include <QApplication>
#include <cstdlib>
#include <iostream>
#include "gui/MainWindow.hpp"
#include "Pikachu.hpp"

using namespace std;

void init();
bool test();

int main(int argc, char* argv[])
{
    init();
    QApplication app(argc, argv);

    if(test()) {
        return 0;
    }

    MainWindow w;
    w.show();

    return app.exec();
}

void init()
{
    qsrand(time(0));
    cout << endl;
}

#include "PikachuGenerator.hpp"
#include "math/Fraction.hpp"
#include "GWTree.hpp"
#include "GWEntity.hpp"
#include "math/Math.hpp"

bool test()
{
    tpe::example1();
    return false;
}
