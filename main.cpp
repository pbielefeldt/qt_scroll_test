#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create a QWidget (window)
    QWidget window;
    window.setWindowTitle("Text File Viewer");
    window.setGeometry(100, 100, 400, 300);

    // Create a QLabel to display the file contents
    QLabel label(&window);
    label.setGeometry(10, 10, 380, 280);

    // Read the contents of the text file
    QFile file("../test_1.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContents = in.readAll();

        // Display the file contents in the QLabel
        label.setText(fileContents);

        file.close();
    } else {
        // Display an error message if the file couldn't be opened
        label.setText("Error: Could not open the file.");
    }

    // Show the window
    window.show();

    return app.exec();
}
