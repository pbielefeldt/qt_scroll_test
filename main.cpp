#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create a QWidget (window)
    QWidget window;
    window.setWindowTitle("Text File Viewer");
    window.setGeometry(100, 100, 400, 300);

    // Create a QPlainTextEdit to display the file contents
    QPlainTextEdit textEdit(&window);
    textEdit.setGeometry(10, 10, 380, 280);

    // Read the contents of the text file
    QFile file("../test_1.txt"); // Adjust the file path as needed
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString fileContents = in.readAll();

        // Set the file contents in the QPlainTextEdit
        textEdit.setPlainText(fileContents);

        file.close();
    }
    else
    {
        // Display an error message if the file couldn't be opened
        textEdit.setPlainText("Error: Could not open the file.");
    }

    // Show the window
    window.show();

    return app.exec();
}
