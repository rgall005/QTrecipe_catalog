#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPdfView>
#include <QPdfDocument>
#include <QWebEngineView>
#include <QBoxLayout>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pb_na_clicked();
    void on_pb_europe_clicked();
    void on_pb_mx_clicked();
    void on_pb_carib_clicked();
    void on_pb_asia_clicked();
    void on_pb_sa_clicked();
    void on_pb_africa_clicked();
    void on_pb_australia_clicked();
    void on_go_back_clicked();
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void get_recipes(QString text);
    void on_map_return_clicked();
    void clear_layout(QVBoxLayout *layout);

    void on_HomePage_clicked();

private:
    Ui::MainWindow *ui;
    QPdfView *pdfView;
    QPdfDocument *pdfDocument;
    QStringList poplist;
    void populateComboBox(QStringList input);
    QVBoxLayout *layout=new QVBoxLayout(this);
    QString folder = "C:/Users/rober/OneDrive - Yorktown Systems Group, Inc/Documents/0_QT Builds/recipe_catalog/";
};

#endif // MAINWINDOW_H
