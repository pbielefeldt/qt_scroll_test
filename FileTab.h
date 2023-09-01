#ifndef FILETAB_H
#define FILETAB_H

#include <QObject>
#include <QTabWidget>

class FileTab : public QObject
{
    Q_OBJECT

public:
    FileTab(QTabWidget &tabWidget, const QString &filename, const QString &tabTitle);

private:
    QTabWidget &tabWidget_;
    QString filename_;
    QString tabTitle_;

    void readFileAndDisplay();

public slots:
    void scrollToBottom();
};

#endif // FILETAB_H
