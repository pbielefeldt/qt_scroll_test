#ifndef FILETAB_H
#define FILETAB_H

#include <QObject>
#include <QTabWidget>
#include <QFileSystemWatcher>

class FileTab : public QObject
{
    Q_OBJECT

public:
    FileTab(QTabWidget &tabWidget, const QString &filename, const QString &tabTitle);

private:
    QTabWidget &tabWidget_;
    QString filename_;
    QString tabTitle_;
    QFileSystemWatcher fileWatcher;

    void readFileAndDisplay();
    void refreshFileContent();

public slots:
    void scrollToBottom();
};

#endif // FILETAB_H
