#include "FileTab.h"
#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>

FileTab::FileTab(QTabWidget &tabWidget, const QString &filename, const QString &tabTitle)
    : QObject(nullptr), tabWidget_(tabWidget), filename_(filename), tabTitle_(tabTitle)
{
    // Read and display the contents of the file
    readFileAndDisplay();
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

void FileTab::scrollToBottom()
{
    QPlainTextEdit *currentTextEdit = qobject_cast<QPlainTextEdit *>(tabWidget_.currentWidget());
    if (currentTextEdit) {
        QTextCursor cursor = currentTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        currentTextEdit->setTextCursor(cursor);
    }
}
