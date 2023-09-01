#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QWidget>
#include <QTabWidget>

// Function to read and display the contents of a file in a QPlainTextEdit
void readFileAndDisplay(QTabWidget& tabWidget, const QString& filename, const QString& tabTitle)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString fileContents = in.readAll();

        QPlainTextEdit* textEdit = new QPlainTextEdit(&tabWidget);
        textEdit->setPlainText(fileContents);

        tabWidget.addTab(textEdit, tabTitle);

        file.close();
    }
    else
    {
        QPlainTextEdit* errorTextEdit = new QPlainTextEdit(&tabWidget);
        errorTextEdit->setPlainText("Error: Could not open " + filename + ".");

        tabWidget.addTab(errorTextEdit, tabTitle + " (Error)");
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Text File Viewer");
    window.setGeometry(100, 100, 400, 300);

    QTabWidget tabWidget(&window);
    tabWidget.setGeometry(10, 10, 380, 280);

    // Read and display the contents of test_1.txt
    readFileAndDisplay(tabWidget, "../test_1.txt", "Test 1");

    // Read and display the contents of test_2.txt
    readFileAndDisplay(tabWidget, "../test_2.txt", "Test 2");

    window.show();

    return app.exec();
}
