#include "QtPanel.h"

#include <QApplication>
#include <QImage>

#include "WeightCalculator.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Livewire::QtPanel w;
	QImage img((argc > 1) ? argv[1] : "test.png");
	w.SetImage(img);
	w.show();
	return app.exec();
}
