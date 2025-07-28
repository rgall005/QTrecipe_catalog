#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QWebEngineView>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(3); //starts on homepage
    ui->stackedWidget->widget(0)->setStyleSheet("QWidget#page{border-image: url("+folder+"images/world-map.jpg);}");
    ui->HomePage->setStyleSheet("border-image: url("+folder+"images/start page.jpg);");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_recipes(QString text) //function get the recipes and display them
{
    //gets the appropriate pdf file path
    QStringList list = text.split(","); //get country name such as the 2 Congos
    QString path=folder+"pdf_file/" + list[0] +".pdf";
    QFileInfo fileInfo(path);

    //sets QVBoxLayout as page 3 on stackedwidget and creates the map_return button
    ui->stackedWidget->widget(2)->setLayout(layout);
    ui->stackedWidget->widget(2)->setStyleSheet("background-color: #f9f9f9; border:1px solid #ccc;border-radius:8px");
    QPushButton *map_return=new QPushButton(this);
    map_return->setText("Return to Map");
    map_return->setStyleSheet("font-size: 15px; color: black; qproperty-alignment: AlignHCenter");
    map_return->connect(map_return, &QPushButton::clicked, this, &MainWindow::on_map_return_clicked);

    //if a PDF exists for the selected area creates a title for the reciped page and displays the pdf viewer
    if (fileInfo.exists() && fileInfo.isFile()) {
    QLabel *title=new QLabel("Recipes from "+text, this);
    title->setStyleSheet("font-size: 30px; font-weight: bold; padding:10px; color: blue; qproperty-alignment: AlignHCenter");
    layout->addWidget(title);
    pdfDocument=new QPdfDocument(this);
    pdfView=new QPdfView(this);
    pdfView->setDocument(pdfDocument);
    layout->addWidget(pdfView);
    pdfDocument->load(path);
    pdfView->setZoomMode(QPdfView::ZoomMode::FitInView);
    pdfView->setPageMode(QPdfView::PageMode::MultiPage);
    layout->addWidget(map_return);
    } else {//if no pdf exists creates and displays an error with the return button
        QLabel *error=new QLabel("Recipes for "+text+" not found.", this);
        error->setStyleSheet("font-size: 30px; font-weight: bold; padding:10px; color: red; qproperty-alignment: AlignCenter; background-color:lightyellow");
        layout->addWidget(error);
        layout->addWidget(map_return);
    }
    ui->stackedWidget->setCurrentIndex(2); //navigates to stackedwidget page 3
}

void MainWindow::populateComboBox(QStringList input) //populates country/region selection list on page 2
{
    ui->comboBox->clear();
    ui->comboBox->addItems(input);
}

void MainWindow::on_pb_na_clicked() //north american pushbutton to navigate to page 2 and set conditions
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setText("Regions");
    ui->stackedWidget->widget(1)->setStyleSheet("QWidget#page_2{border-image: url("+folder+"images/north_america.jpg);}");
    poplist = {
        "The Far North",
        "West Coast",
        "Prarie Provinces",
        "South Canada",
        "French Canada",
        "Northeast",
        "Mountain West",
        "Midwest",
        "Southwest",
        "South"
    };
    populateComboBox(poplist);
}

void MainWindow::on_pb_mx_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setText("Countries");
    ui->stackedWidget->widget(1)->setStyleSheet("QWidget#page_2{border-image: url("+folder+"images/mexico.jpg);}");
    poplist = {
        "Mexico",
        "Guatemala",
        "Belize",
        "Honduras",
        "El_Salvador",
        "Nicaragua",
        "Costa Rica",
        "Panama"
    };
    populateComboBox(poplist);
}

void MainWindow::on_pb_carib_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setText("Countries");
    ui->stackedWidget->widget(1)->setStyleSheet("QWidget#page_2{border-image: url("+folder+"images/carib.jpg);}");
    poplist = {
        "Cuba",
        "Haiti",
        "Jamaica",
        "Dominican Republic",
        "Puerto Rico",
        "Virgin Islands",
        "Trinidad and Tobago",
        "Cayman Islands"
    };
    populateComboBox(poplist);
}

void MainWindow::on_pb_europe_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setText("Countries");
    ui->stackedWidget->widget(1)->setStyleSheet("QWidget#page_2{border-image: url("+folder+"images/europe.jpg);}");
    poplist = {
        "Albania","Andorra","Armenia","Austria","Azerbaijan","Belarus","Belgium",
        "Bosnia and Herzegovina","Bulgaria","Croatia","Cyprus","Czechia","Denmark","Estonia",
        "Finland","France","Georgia","Germany","Greece","Hungary","Iceland","Ireland","Italy",
        "Kazakhstan","Kosovo","Latvia","Liechtenstein","Lithuania","Luxembourg","Malta","Moldova",
        "Monaco","Montenegro","Netherlands","North Macedonia","Norway","Poland","Portugal","Romania",
        "Russia","San Marino","Serbia","Slovakia","Slovenia","Spain","Sweden","Switzerland","Turkey",
        "Ukraine","United Kingdom","Vatican City"
    };
    populateComboBox(poplist);
}

void MainWindow::on_pb_asia_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setText("Countries");
    ui->stackedWidget->widget(1)->setStyleSheet("QWidget#page_2{border-image: url("+folder+"images/asia.jpg);}");
    poplist = {
        "Afghanistan","Armenia","Azerbaijan","Bahrain","Bangladesh","Bhutan","Brunei","Cambodia",
        "China","Cyprus","East Timor","Egypt","Georgia","India","Indonesia","Iran","Iraq","Israel",
        "Japan","Jordan","Kazakhstan","Kuwait","Kyrgyzstan","Laos","Lebanon","Malaysia","Maldives",
        "Mongolia","Myanmar","Nepal","North Korea","Oman","Pakistan","Palestine","Philippines","Qatar",
        "Russia","Saudi Arabia","Singapore","South Korea","Sri Lanka","Syria","Taiwan","Tajikistan","Thailand",
        "Turkey","Turkmenistan","United Arab Emirates","Uzbekistan","Vietnam","Yemen"
    };
    populateComboBox(poplist);
}

void MainWindow::on_pb_sa_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setText("Countries");
    ui->stackedWidget->widget(1)->setStyleSheet("QWidget#page_2{border-image: url("+folder+"images/s_america.jpg);}");
    poplist = {
        "Argentina","Bolivia","Brazil","Chile","Colombia","Ecuador",
        "Guyana","Paraguay","Peru","Suriname","Uruguay","Venezuela"
    };
    populateComboBox(poplist);
}

void MainWindow::on_pb_africa_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setText("Countries");
    ui->stackedWidget->widget(1)->setStyleSheet("QWidget#page_2{border-image: url("+folder+"images/africa.jpg);}");
    poplist = {
        "Algeria","Angola","Benin","Botswana","Burkina Faso","Burundi","Cabo Verde","Cameroon","Central African Republic",
        "Chad","Comoros","Congo, Democratic Republic of the", "Congo, Republic of the","Cote d'Ivoire","Djibouti","Egypt",
        "Equatorial Guinea","Eritrea","Eswatini","Ethiopia","Gabon","Gambia","Ghana","Guinea","Guinea-Bissau","Kenya","Lesotho",
        "Liberia","Libya","Madagascar","Malawi","Mali","Mauritania","Mauritius","Morocco","Mozambique","Namibia","Niger",
        "Nigeria","Rwanda","Sao Tome and Principe","Senegal","Seychelles","Sierra Leone","Somalia","South Africa",
        "South Sudan","Sudan","Tanzania","Togo","Tunisia","Uganda","Zambia","Zimbabwe"
    };
    populateComboBox(poplist);
}

void MainWindow::on_pb_australia_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setText("Countries");
    ui->stackedWidget->widget(1)->setStyleSheet("QWidget#page_2{border-image: url("+folder+"images/australia.jpg);}");
    poplist = {
       "Western Australia",
       "Northern Territory",
       "Queensland",
       "South Australia",
       "New South Wales",
       "Victoria",
       "Tasmania",
       "New Zealand"
    };
    populateComboBox(poplist);
}

void MainWindow::on_go_back_clicked() //returns to world map
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonBox_rejected() //returns to world map
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonBox_accepted() //when OK button clicked gets the string from the combobox and sends to get_recipe function
{
    QString selection = ui->comboBox->currentText();
    get_recipes(selection);
}

void MainWindow::on_map_return_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //returns to area map
    clear_layout(layout); //calls the layout clearing function when pushbutton is clicked
}

void MainWindow::clear_layout(QVBoxLayout *layout) //function to clear QVBoxLayout
{
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater(); // Deletes the widget safely
        }
        delete item; // Deletes the layout item
    }
}

void MainWindow::on_HomePage_clicked() //Homepage pushbutton to go to map
{
    ui->stackedWidget->setCurrentIndex(0);
}

