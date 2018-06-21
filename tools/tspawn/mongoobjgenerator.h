#ifndef MONGOOBJGENERATOR_H
#define MONGOOBJGENERATOR_H

#include <QString>
#include <QDir>
#include <QList>
#include <QPair>
#include <QVariant>
#include "abstractobjgenerator.h"


class MongoObjGenerator : public AbstractObjGenerator
{
public:
    MongoObjGenerator(const QString &model);

    QString generate(const QString &dstDir);
    bool createMongoObject(const QString &path);
    bool updateMongoObject(const QString &path);
    QString model() const { return modelName; }
    QList<QPair<QString, QVariant::Type>> fieldList() const { return fields; }
    QMap<QString, QVariant::Type> fieldTypeMap() const { return fieldTypeMaps; }
    QMap<QString, QPair<QString, QString>> parentTables() const { return pTables; }
    QMap<QPair<QString, QString>, QString> childTables() const { return cTables; }
    int primaryKeyIndex() const;
    int autoValueIndex() const;
    int lockRevisionIndex() const;

protected:
    QString mongoObjectFilePath(const QString &dstDir) const;

private:
    QString modelName;
    QString collectionName;
    QMap<QString, QVariant::Type> fieldTypeMaps;
    QList<QPair<QString, QVariant::Type>> fields;
    QMap<QString, QPair<QString, QString>> pTables;;
    QMap<QPair<QString, QString>, QString> cTables;;
};

#endif // MONGOOBJGENERATOR_H
