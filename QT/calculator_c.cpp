// Copyright 2023 valeryje

#include "calculator_c.h"
#include "./ui_calculator_c.h"
#include "../lib.h"
#include <QRegularExpression>
#include <string>

Calculator_C::Calculator_C(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator_C)
{
    ui->setupUi(this);

    QPixmap bkgnd("/Users/valeryje/School21/C7-Calculator/NewCalc/src/QT/Reverse.jpeg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui->X_value->setVisible(false);
    ui->Button_func_fx->setVisible(false);

    ui->X_min->setVisible(false);
    ui->X_max->setVisible(false);
    ui->Y_min->setVisible(false);
    ui->Y_max->setVisible(false);
    ui->Label_x_min->setVisible(false);
    ui->Label_x_max->setVisible(false);
    ui->Label_y_min->setVisible(false);
    ui->Label_y_max->setVisible(false);
    ui->Plotter->setVisible(false);

}

Calculator_C::~Calculator_C() {
    delete ui;
}

void Calculator_C::on_Button_dot_clicked() {
    if (ui->Equation->hasFocus()) {
        if (ui->Equation->text() == "") {
            ui->Equation->setText("0.");
        } else if (ui->Equation->text() != "") {
            if (ui->Equation->text().back() == '+' || ui->Equation->text().back() == '-' || ui->Equation->text().back() == '*' ||
                    ui->Equation->text().back() == '/' || ui->Equation->text().back() == '%' ||
                    ui->Equation->text().back() == '^' || ui->Equation->text().back() == '(') {
                ui->Equation->setText(ui->Equation->text() + "0.");
            } else {
                ui->Equation->setText(ui->Equation->text() + ".");
            }
        }
    }
    if (ui->X_value->hasFocus()) {
        if (ui->X_value->text() == "") {
            ui->X_value->setText("0.");
        } else {
            ui->X_value->setText(".");
        }
    }
}

void Calculator_C::on_Button_AC_clicked() {
    if (ui->Equation->hasFocus()) {
        ui->Equation->setText("");
        ui->Answer->setText("0");
    }
    if (ui->X_value->hasFocus()) ui->X_value->setText("");
}

void Calculator_C::on_Button_0_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "0");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "0");
}

void Calculator_C::on_Button_1_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "1");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "1");
}

void Calculator_C::on_Button_2_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "2");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "2");
}

void Calculator_C::on_Button_3_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "3");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "3");
}

void Calculator_C::on_Button_4_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "4");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "4");
}

void Calculator_C::on_Button_5_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "5");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "5");
}

void Calculator_C::on_Button_6_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "6");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "6");
}

void Calculator_C::on_Button_7_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "7");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "7");
}

void Calculator_C::on_Button_8_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "8");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "8");
}

void Calculator_C::on_Button_9_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "9");
    if (ui->X_value->hasFocus()) ui->X_value->setText(ui->X_value->text() + "9");
}

void Calculator_C::on_Button_func_sin_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "sin(");
}

void Calculator_C::on_Button_func_cos_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "cos(");
}

void Calculator_C::on_Button_func_tan_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "tan(");
}

void Calculator_C::on_Button_func_asin_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "asin(");
}

void Calculator_C::on_Button_func_acos_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "acos(");
}

void Calculator_C::on_Button_func_atan_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "atan(");
}

void Calculator_C::on_Button_func_log_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "log(");
}

void Calculator_C::on_Button_func_ln_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "ln(");
}

void Calculator_C::on_Button_func_ceil_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "ceil(");
}

void Calculator_C::on_Button_func_eps_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "2.7182818");
}

void Calculator_C::on_Button_func_Pi_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "3.1415927");
}

void Calculator_C::on_Button_func_fx_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "x");
}

void Calculator_C::on_Button_oper_plus_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "+");
}

void Calculator_C::on_Button_oper_minus_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "-");
}

void Calculator_C::on_Button_oper_unar_plus_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "(+");
}

void Calculator_C::on_Button_oper_unar_minus_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "(-");
}

void Calculator_C::on_Button_oper_multi_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "*");
}

void Calculator_C::on_Button_oper_divide_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "/");
}

void Calculator_C::on_Button_oper_mod_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "%");
}

void Calculator_C::on_Button_oper_power_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "^");
}

void Calculator_C::on_Button_oper_sqrt_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "sqrt(");
}

void Calculator_C::on_Button_oper_open_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + "(");
}

void Calculator_C::on_Button_oper_close_clicked() {
    if (ui->Equation->hasFocus()) ui->Equation->setText(ui->Equation->text() + ")");
}

void Calculator_C::on_Plot_settings_box_stateChanged(int arg1) {
    if (arg1 && ui->X_value->text() == "") ui->X_value->setText("0");
}

void Calculator_C::on_X_count_box_stateChanged(int arg1) {
    if (arg1 && ui->X_value->text() == "") ui->X_value->setText("0");
}

void Calculator_C::on_Button_delete_clicked() {
    QString buffer = ui->Equation->text();
    buffer.chop(1);
    ui->Equation->setText(buffer);
}

void Calculator_C::on_X_count_box_clicked() {
    if (ui->X_count_box->isChecked()) {
        ui->X_value->setVisible(true);
        ui->Button_func_fx->setVisible(true);
    } else {
        ui->X_value->setVisible(false);
        ui->Button_func_fx->setVisible(false);
    }
}

void Calculator_C::on_Plot_settings_box_clicked() {
    if (ui->Plot_settings_box->isChecked()) {
        ui->X_min->setVisible(true);
        ui->X_max->setVisible(true);
        ui->Y_min->setVisible(true);
        ui->Y_max->setVisible(true);
        ui->Label_x_min->setVisible(true);
        ui->Label_x_max->setVisible(true);
        ui->Label_y_min->setVisible(true);
        ui->Label_y_max->setVisible(true);
        ui->Plotter->setVisible(true);
    } else {
        ui->X_min->setVisible(false);
        ui->X_max->setVisible(false);
        ui->Y_min->setVisible(false);
        ui->Y_max->setVisible(false);
        ui->Label_x_min->setVisible(false);
        ui->Label_x_max->setVisible(false);
        ui->Label_y_min->setVisible(false);
        ui->Label_y_max->setVisible(false);
        ui->Plotter->setVisible(false);
    }
}

void Calculator_C::on_Button_oper_count_clicked() {

    std::string eq = (ui->Equation->text() + "=").toStdString();
    std::string x = (ui->X_value->text()).toStdString();
// расчет единичного Х
    char* res;
    if (ui->X_count_box->isChecked()) {
        res = smartcalc(eq.c_str(), x.c_str());
    } else {
        res = smartcalc(eq.c_str(), "");
    }
    ui->Answer->setText(res);
// расчет графика
    if (ui->Plot_settings_box->isChecked()) {
        double x_min = ui->X_min->text().toFloat();
        double x_max = ui->X_max->text().toFloat();
        double y_min = ui->Y_min->text().toFloat();
        double y_max = ui->Y_max->text().toFloat();
//        if (x_min < -1000000) x_min = -10;
//        if (x_max > 1000000) x_max = 10;
//        if (y_min < -1000000) x_min = -10;
//        if (y_max > 1000000) x_max = 10;

        double size_x = ui->X_max->text().toDouble() - ui->X_min->text().toDouble();
        int dots = 5000;
//        if (size_x <= 2000) {
//            dots = 101;
//        } else if (size_x <= 20000) {
//            dots = 101+ceil((size_x-2000)/45.);
//        } else if (size_x <= 200000) {
//            dots = 501;
//        } else if (size_x <= 400000) {
//            dots = 501+ceil((size_x-200000)/2000.);
//        } else if (size_x <= 800000) {
//            dots = 601+ceil((size_x-400000)/1333.);
//        } else if (size_x <= 1400000) {
//            dots = 901+ceil((size_x-800000)/1000.);
//        } else if (size_x <= 1800000) {
//            dots = 1500+ceil((size_x-1400000)/800.);
//        } else if (size_x > 1800000 && size_x <= 2000000) {
//            dots = 2001;
//        }
//        double step = size_x/dots;
        double step = size_x/dots;
        QList<double> x_values, y_values;
        double x_current = ui->X_min->text().toDouble();
        int error = 1;
         for (int i = 0; i < dots; i++) {
             x_current += step;
             char* y = smartcalc(eq.c_str(), std::to_string(x_current).c_str());
             if (('0' <= *y && *y <= '9') || *y == '-' || *y == 'n' || *y == 'i') {
                 x_values.push_back(x_current);
                 y_values.push_back(std::stod(y));
             } else {
                 error = 0;
                 break;
             }
         }
         if (error) {
             ui->Plotter->addGraph();
             ui->Plotter->graph(0)->setData(x_values, y_values);
             ui->Plotter->xAxis->setLabel("x");
             ui->Plotter->yAxis->setLabel("y");
             ui->Plotter->xAxis->setRange(x_min, x_max);
             ui->Plotter->yAxis->setRange(y_min, y_max);
             ui->Plotter->replot();
         }
    }
 free(res);
}


void Calculator_C::plot(double x, double y) {




}




//const double step = 0.0;

//    if (ui->X_count_box->isChecked() && !ui->Plot_settings_box->isChecked()) {
//        ui->Answer->setText(QString(res));
//    } else if (ui->X_count_box->isChecked() && !ui->Plot_settings_box->isChecked()){
//        ui->Answer->setText(QString(res));
//    }

//    if ((('0' <= res[0] && res[0] <= '9') || res[0] == '-' || res[0] == 'n'|| res[0] == 'i') && !XFactor.isEmpty()) {}



//void Calculator_C::plot(std::string equation) {
//    // generate some data:
//    QVector<double> x(101), y(101); // initialize with entries 0..100
//    for (int i=0; i<101; ++i)
//    {
////        std::to_string(/*double*/);
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = x[i]*x[i]; // let's plot a quadratic function
//    }








//число/ошибка      без х без вычисления без графика
//ошибка             с  х без вычисления без графика
//ошибка            без х  с вычислением без графика
//число             без х без вычисления  с графиком
//число/ошибка       с  х  с вычислением без графика
//пусто              с  х без вычисления  с графиком
//число      без х  с вычислением  с графиком
//число      без х без вычисления без графика
//число/ошибка       с  х  с вычислением  с графиком






////    if (ui->X_min->text().isEmpty()) ui->X_min->setText("-50");
////    if (ui->X_max->text().isEmpty()) ui->X_max->setText("50");
////    if (ui->Y_min->text().isEmpty()) ui->Y_min->setText("-50");
////    if (ui->Y_max->text().isEmpty()) ui->Y_max->setText("50");

////    if (ui->X_min->text()) ui->X_min->setText("-50");
////    if (ui->X_max->text().isEmpty()) ui->X_max->setText("50");
////    if (ui->Y_min->text().isEmpty()) ui->Y_min->setText("-50");
////    if (ui->Y_max->text().isEmpty()) ui->Y_max->setText("50");
//    // create graph and assign data to it:
//    ui->Plot->addGraph();
//    ui->Plot->graph(0)->setData(x, y);
//    // give the axes some labels:
//    ui->Plot->xAxis->setLabel("x");
//    ui->Plot->yAxis->setLabel("y");
//    // set axes ranges, so we see all data:
//    ui->Plot->xAxis->setRange(-1, 1);
//    ui->Plot->yAxis->setRange(0, 1);
//    ui->Plot->replot();
//}


//int output = 0;
//  int dots = 0;
//  double size_x = *x_max-*x_min;
//  double step = 0;
//  if (size_x <= 2000) {
//    dots = 101.;
//  } else if (size_x <= 20000) {
//    dots = 101+(size_x-2000)/45.;
//  } else if (size_x <= 200000) {
//    dots = 501.;
//  } else if (size_x <= 400000) {
//    dots = 501+(size_x-200000)/2000.;
//  } else if (size_x <= 800000) {
//    dots = 601+(size_x-400000)/1333.;
//  } else if (size_x <= 1400000) {
//    dots = 901+(size_x-800000)/1000.;
//  } else if (size_x <= 1800000) {
//    dots = 1500+(size_x-1400000)/800.;
//  } else if (size_x > 1800000 && size_x <= 2000000) {
//    dots = 2001.;
//  }
//  step = size_x/dots;
//  for (double current = *x_min; current <= (*x_max+0.75*step); current += step) {
//    output = processor(shrt_eq, result);
//    inner_error(output, answer);
//    if (output) break;
//  }
//  return output;
//}






//std::stod(ui->Equation->text().toStdString()); // конвертирует строку в дабл

//    connect(ui->Button_dot, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_AC, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_0, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_1, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_2, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_3, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_4, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_5, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_6, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_7, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_8, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_9, SIGNAL(clicked()),this,SLOT(digits()));

//    connect(ui->Button_oper_plus, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_minus, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_unar_plus, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_unar_minus, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_multi, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_divide, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_mod, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_power, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_sqrt, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_open, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_close, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_oper_count, SIGNAL(clicked()),this,SLOT(digits()));

//    connect(ui->Button_func_sin, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_func_cos, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_func_tan, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_func_asin, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_func_acos, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_func_atan, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_func_log, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_func_ln, SIGNAL(clicked()),this,SLOT(digits()));
//    connect(ui->Button_func_fx, SIGNAL(clicked()),this,SLOT(digits()));
