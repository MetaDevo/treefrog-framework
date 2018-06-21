#ifndef TABLESCHEMA_H
#define TABLESCHEMA_H

#include <QString>
#include <QList>
#include <QPair>
#include <QSqlRecord>
#include <QVariant>


class TableSchema
{
public:
    TableSchema(const QString &table, const QString &env = "dev");
    bool exists() const;
    QList<QPair<QString, QString>> getFieldList() const;
    QList<QPair<QString, QVariant::Type>> getFieldTypeList() const;
    QMap<QString, QVariant::Type> getFieldTypeMap() const;
    int primaryKeyIndex() const;
    QString primaryKeyFieldName() const;
    int autoValueIndex() const;
    QString autoValueFieldName() const;
    QPair<QString, QString> getPrimaryKeyField() const;
    QPair<QString, QVariant::Type> getPrimaryKeyFieldType() const;
    QString tableName() const { return tablename; }
    int lockRevisionIndex() const;
    bool hasLockRevisionField() const;
    static QStringList databaseDrivers();
    static QStringList tables(const QString &env = "dev");
    QMap<QString, QPair<QString, QString>> getParentTables() const;
    QMap<QPair<QString, QString>, QString> getChildTables() const;

protected:
    bool openDatabase(const QString &env) const;
    bool isOpen() const;

private:
    QString tablename;
    QSqlRecord tableFields;
};

#endif // TABLESCHEMA_H
