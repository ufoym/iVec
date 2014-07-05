#ifndef LIVEWIREQTPANEL_H
#define LIVEWIREQTPANEL_H

#include "WeightCalculator.h"
#include "LivewireCalculator.h"

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QVector>

namespace Livewire
{
	class QtPanel : public QWidget
	{
		Q_OBJECT

	private:
		/// <summary>The pen used to draw the active livewire</summary>
		static const QPen LivewirePen;

		/// <summary>The pen used to draw the static previous wires</summary>
		static const QPen PrevwirePen;

		/// <summary>The pen used to draw the wrapping livewire</summary>
		static const QPen WrapwirePen;

		static const QBrush MouseBrush;
		static const QBrush PointBrush;

	private:
		QImage image;
		uint w, h;
		QPoint mouse;
		QVector<QPoint> points;
		WeightCalculator *weights;
		LivewireCalculator *livewire;
		LivewireCalculator *wrapwire;
		QImage prevwires;

		void Cleanup();

	public:
		QtPanel(QWidget *parent = NULL);
		~QtPanel();

		void SetImage(QImage &img);
		/// <summary>Reset the current state of the livewires</summary>
		void Reset();

	protected:
		void paintEvent(QPaintEvent *evnt);
		void mouseMoveEvent(QMouseEvent *evnt);
		void mousePressEvent(QMouseEvent *evnt);
		void mouseDoubleClickEvent(QMouseEvent *evnt);

	private:
		/// <summary>Handles mouse clicking and double clicking. </summary>
		/// <param name="evnt">The mouse event arguments</param>
		/// <param name="dbl">True if the mouse double clicked</param>
		void MouseClicked(QMouseEvent *evnt, bool dbl);

		void AddEventsToThreaded(const Threaded *t) const;

		/// <summary>Moves the point to be within the bounds of the image</summary>
		/// <param name="p">The point to move</param>
		/// <returns>The adjusted point</returns>
		void getPointInBounds(QPoint &p);
	};
}

#endif
