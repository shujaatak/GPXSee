#ifndef OZF_H
#define OZF_H

#include <QString>
#include <QSize>
#include <QColor>
#include <QVector>
#include <QFile>
#include <QPixmap>

class OZF
{
public:
	bool load(const QString &path);

	QString fileName() const {return _file.fileName();}
	bool isOpen() const {return _file.isOpen();}

	QSize size() const {return _size;}
	QSize tileSize() const {return QSize(64, 64);}
	QPixmap tile(int x, int y);

private:
	template<class T> bool readValue(T &val);
	bool readHeaders();
	bool readTileTable();

	QSize _size;
	QSize _dim;
	QVector<QRgb> _palette;
	QVector<quint32> _tiles;

	QFile _file;
};

#endif // OZF_H
