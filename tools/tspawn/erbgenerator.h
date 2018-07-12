#ifndef ERBGENERATOR_H
#define ERBGENERATOR_H

#include <QStringList>
#include <QDir>
#include <QPair>
#include <QVariant>
#include <QMap>

class ErbGenerator
{
public:
    ErbGenerator(const QString &view, const QList<QPair<QString, QVariant::Type>> &fields, int pkIdx, int autoValIdx, const QMap<QPair<QString, QString>, QString> &childTables);
    bool generate(const QString &dstDir) const;
    QString genChildIndex(const QString &parentViewName, const QString &parentFieldName, const QString &childTableName, const QString &childFieldName) const;

private:
    QString viewName;
    QList<QPair<QString, QVariant::Type>> fieldList;
    int primaryKeyIndex;
    int autoValueIndex;
    QMap<QPair<QString, QString>, QString> childTables;
};

#endif // ERBGENERATOR_H
