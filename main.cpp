#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include "FileTab.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Text File Viewer");
    window.setGeometry(100, 100, 400, 300);

    QTabWidget tabWidget(&window);
    tabWidget.setGeometry(10, 10, 380, 280);

    // Create instances of the FileTab class for test_1.txt and test_2.txt
    FileTab fileTab1(tabWidget, "../test_1.txt", "Test 1");
    FileTab fileTab2(tabWidget, "../test_2.txt", "Test 2");

    // Connect the slot for scrolling to the currentChanged signal
    QObject::connect(&tabWidget, &QTabWidget::currentChanged, [&fileTab1, &fileTab2](int index) {
        if (index == 0) {
            fileTab1.scrollToBottom();
        } else if (index == 1) {
            fileTab2.scrollToBottom();
        }
    });

    window.show();

    return app.exec();
}
