#ifndef QML_JULIA_DISPLAY_H
#define QML_JULIA_DISPLAY_H

#include <cxx_wrap.hpp>

#include <QObject>
#include <QPixmap>
#include <QQuickPaintedItem>

namespace qmlwrap
{

/// Groups signals (defined using QML) that can be emitted from Julia
class JuliaDisplay : public QQuickPaintedItem
{
  Q_OBJECT

public:
  JuliaDisplay(QQuickItem *parent = 0);

  void paint(QPainter *painter);

  void load_png(cxx_wrap::ArrayRef<unsigned char> data);

  void clear();

protected:
  void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry);

private:
  QPixmap m_pixmap;
};

} // namespace qmlwrap

#endif
