#include "FileTab.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QScrollBar>

FileTab::FileTab(QTabWidget &tabWidget, const QString &filename, const QString &tabTitle)
    : QObject(nullptr), tabWidget_(tabWidget), filename_(filename), tabTitle_(tabTitle)
{
    // Read and display the contents of the specified file
    readFileAndDisplay();

    // Set up QFileSystemWatcher to monitor file changes
    fileWatcher.addPath(filename_);

    // Connect fileChanged signal to refreshFileContent slot
    connect(&fileWatcher, &QFileSystemWatcher::fileChanged, this, &FileTab::refreshFileContent);
}

void FileTab::readFileAndDisplay()
{
    QFile file(filename_);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContents = in.readAll();

        QPlainTextEdit *textEdit = new QPlainTextEdit(&tabWidget_);
        textEdit->setPlainText(fileContents);

        tabWidget_.addTab(textEdit, tabTitle_);

        file.close();
    } else {
        QPlainTextEdit *errorTextEdit = new QPlainTextEdit(&tabWidget_);
        errorTextEdit->setPlainText("Error: Could not open " + filename_ + ".");

        tabWidget_.addTab(errorTextEdit, tabTitle_ + " (Error)");
    }
}

void FileTab::refreshFileContent()
{
    qDebug() << Q_FUNC_INFO << "refreshing";
    QFile file(filename_);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContents = in.readAll();

        // Find the QPlainTextEdit widget and update its content
        for (int i = 0; i < tabWidget_.count(); ++i) {
            QPlainTextEdit *textEdit = qobject_cast<QPlainTextEdit *>(tabWidget_.widget(i));
            if (textEdit && tabWidget_.tabText(i) == tabTitle_) {
                textEdit->setPlainText(fileContents);
                scrollToBottom();
                break;
            }
        }

        file.close();
    } else {
        QMessageBox::warning(nullptr, "Error", "Could not open " + filename_);
    }
}

void FileTab::scrollToBottom()
{
    qDebug() << Q_FUNC_INFO << "scrolling";
    QPlainTextEdit *currentTextEdit = qobject_cast<QPlainTextEdit *>(tabWidget_.currentWidget());
    if (currentTextEdit) {
        QScrollBar *verticalScrollBar = currentTextEdit->verticalScrollBar();
        verticalScrollBar->setValue(verticalScrollBar->maximum());
    }
}
