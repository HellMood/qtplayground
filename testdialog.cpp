#include "testdialog.h"
#include "ui_testdialog.h"
#include <Rcpp.h>

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this);
}

TestDialog::~TestDialog()
{
    delete ui;
}

void _r_test ()
{
    double test = R::rpois(1.2);

}

void TestDialog::on_buttonBox_accepted()
{

}
