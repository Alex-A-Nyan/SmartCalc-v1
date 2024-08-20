// Copyright 2023 valeryje

#ifndef CALCULATOR_C_H
#define CALCULATOR_C_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator_C; }
QT_END_NAMESPACE

class Calculator_C : public QMainWindow
{
    Q_OBJECT

public:
    Calculator_C(QWidget *parent = nullptr);
    ~Calculator_C();

private:
    Ui::Calculator_C *ui;

private slots:

    void on_Button_dot_clicked();
    void on_Button_AC_clicked();
    void on_Button_0_clicked();
    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_5_clicked();
    void on_Button_6_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();

    void on_Button_oper_plus_clicked();
    void on_Button_oper_minus_clicked();
    void on_Button_oper_unar_plus_clicked();
    void on_Button_oper_unar_minus_clicked();
    void on_Button_oper_multi_clicked();
    void on_Button_oper_divide_clicked();
    void on_Button_oper_mod_clicked();
    void on_Button_oper_power_clicked();
    void on_Button_oper_sqrt_clicked();
    void on_Button_oper_open_clicked();
    void on_Button_oper_close_clicked();
    void on_Button_oper_count_clicked();

    void on_Button_func_sin_clicked();
    void on_Button_func_cos_clicked();
    void on_Button_func_tan_clicked();
    void on_Button_func_asin_clicked();
    void on_Button_func_acos_clicked();
    void on_Button_func_atan_clicked();
    void on_Button_func_log_clicked();
    void on_Button_func_ln_clicked();
    void on_Button_func_fx_clicked();
    void on_Button_func_ceil_clicked();
    void on_Button_func_eps_clicked();
    void on_Button_func_Pi_clicked();
    void on_Button_delete_clicked();

    void on_X_count_box_clicked();
    void on_Plot_settings_box_clicked();

    void on_Plot_settings_box_stateChanged(int arg1);
    void on_X_count_box_stateChanged(int arg1);

    void plot(double x, double y);
//    void plot(std::string equation);
};

#endif // CALCULATOR_C_H
