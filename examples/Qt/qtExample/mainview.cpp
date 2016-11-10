#include "mainview.h"
#include "ui_mainview.h"
#include <QLibrary>
#include <QMessageBox>
#include <wchar.h>

typedef  wchar_t *(* NUM2AW_FUNC) (
        double num,
        const wchar_t *itemName,
        const wchar_t *itemNameWithTanween,
        const wchar_t *dualItemName,
        const wchar_t *pluralItemName,
        int ig
        );

typedef int (*GET_NUM2AW_FUNC)(
                                wchar_t *dest,
                                int dest_len,
                                double num,
                                const wchar_t *itemName,
                                const wchar_t *itemNameWithTanween,
                                const wchar_t *dualItemName,
                                const wchar_t *pluralItemName,
                                int ig
                                );

typedef wchar_t * (* FNUM2AW_FUNC)(
        double num,
        const wchar_t *itemName,
        const wchar_t *itemNameWithTanween,
        const wchar_t *dualItemName,
        const wchar_t *pluralItemName,
        int ig,
        const wchar_t *fractionalItemName,
        const wchar_t *fractionalItemNameWithTanween,
        const wchar_t *fractionalDualItemName,
        const wchar_t *fractionalPluralItemName,
        int fig,
        int decimalPlace
        );

typedef int (*GET_FNUM2AW_FUNC)(
                        wchar_t *dest,
                        int dest_len,
                        double num,
                        const wchar_t *itemName,
                        const wchar_t *itemNameWithTanween,
                        const wchar_t *dualItemName,
                        const wchar_t *pluralItemName,
                        int ig,
                        const wchar_t *fractionalItemName,
                        const wchar_t *fractionalItemNameWithTanween,
                        const wchar_t *fractionalDualItemName,
                        const wchar_t *fractionalPluralItemName,
                        int fig,
                        int decimalPlace
                        );
typedef void (* N2A_CLEAN_FUNC)(void *ptr);

#define MAX_NUMBER_NAME_LENGTH 2048



MainView::MainView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_btnNum2aW_clicked()
{
    ui->edResult->clear();
    QLibrary lib("num2a");
    lib.load();
    if(lib.isLoaded())
    {
        NUM2AW_FUNC fnc = (NUM2AW_FUNC)lib.resolve("num2aW");
        N2A_CLEAN_FUNC clean = (N2A_CLEAN_FUNC)lib.resolve("n2a_clean");
        if(fnc && clean)
        {
            wchar_t *res = NULL;
            wchar_t *itemName = NULL, *itemNameWithTanween = NULL, *dualItemName = NULL,
                    *pluralItemName = NULL;
            int ig = ui->cbItemGender->currentIndex();
            double num = ui->edNumber->text().toDouble();

            if(!ui->edItemName->text().isEmpty())
            {
                itemName = (wchar_t*)malloc((ui->edItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edItemName->text().toWCharArray(itemName);
                itemName[ui->edItemName->text().length()] = L'\0';
            }
            if(!ui->edItemNameWithTanween->text().isEmpty())
            {
                itemNameWithTanween = (wchar_t*)malloc((ui->edItemNameWithTanween->text().length() + 1)*sizeof(wchar_t));
                ui->edItemNameWithTanween->text().toWCharArray(itemNameWithTanween);
                itemNameWithTanween[ui->edItemNameWithTanween->text().length()] = L'\0';
            }
            if(!ui->edDualItemName->text().isEmpty())
            {
                dualItemName = (wchar_t*)malloc((ui->edDualItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edDualItemName->text().toWCharArray(dualItemName);
                dualItemName[ui->edDualItemName->text().length()] = L'\0';
            }
            if(!ui->edPluralItemName->text().isEmpty())
            {
                pluralItemName = (wchar_t*)malloc((ui->edPluralItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edPluralItemName->text().toWCharArray(pluralItemName);
                pluralItemName[ui->edPluralItemName->text().length()] = L'\0';
            }
            res = fnc(num, itemName, itemNameWithTanween, dualItemName, pluralItemName, ig);
            if(res)
            {
                ui->edResult->setText(QString::fromWCharArray(res));
            }

            if(itemName)
                free(itemName);
            if(itemNameWithTanween)
                free(itemNameWithTanween);
            if(dualItemName)
                free(dualItemName);
            if(pluralItemName)
                free(pluralItemName);
            if(res)
                clean(res);
        }
    }
    else
        QMessageBox::critical(this, "", lib.errorString());
}

void MainView::on_btnFnum2aW_clicked()
{
    ui->edResult->clear();
    QLibrary lib("num2a");
    lib.load();
    if(lib.isLoaded())
    {
        FNUM2AW_FUNC fnc = (FNUM2AW_FUNC)lib.resolve("fnum2aW");
        N2A_CLEAN_FUNC clean = (N2A_CLEAN_FUNC)lib.resolve("n2a_clean");
        if(fnc && clean)
        {
            wchar_t *res = NULL;
            wchar_t *itemName = NULL, *itemNameWithTanween = NULL, *dualItemName = NULL,
                    *pluralItemName = NULL;
            wchar_t *fractionalItemName = NULL,
            *fractionalItemNameWithTanween = NULL,
            *fractionalDualItemName = NULL,
            *fractionalPluralItemName = NULL;
            int ig = ui->cbItemGender->currentIndex();
            double num = ui->edNumber->text().toDouble();
            int fig = ui->cbFractionalItemNameGender->currentIndex();
            int decimalPlace = ui->edDecimalPlace->value();

            if(!ui->edItemName->text().isEmpty())
            {
                itemName = (wchar_t*)malloc((ui->edItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edItemName->text().toWCharArray(itemName);
                itemName[ui->edItemName->text().length()] = L'\0';
            }
            if(!ui->edItemNameWithTanween->text().isEmpty())
            {
                itemNameWithTanween = (wchar_t*)malloc((ui->edItemNameWithTanween->text().length() + 1)*sizeof(wchar_t));
                ui->edItemNameWithTanween->text().toWCharArray(itemNameWithTanween);
                itemNameWithTanween[ui->edItemNameWithTanween->text().length()] = L'\0';
            }
            if(!ui->edDualItemName->text().isEmpty())
            {
                dualItemName = (wchar_t*)malloc((ui->edDualItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edDualItemName->text().toWCharArray(dualItemName);
                dualItemName[ui->edDualItemName->text().length()] = L'\0';
            }
            if(!ui->edPluralItemName->text().isEmpty())
            {
                pluralItemName = (wchar_t*)malloc((ui->edPluralItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edPluralItemName->text().toWCharArray(pluralItemName);
                pluralItemName[ui->edPluralItemName->text().length()] = L'\0';
            }
            if(!ui->edFractionalItemName->text().isEmpty())
            {
                fractionalItemName = (wchar_t*)malloc((ui->edFractionalItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edFractionalItemName->text().toWCharArray(fractionalItemName);
                fractionalItemName[ui->edFractionalItemName->text().length()] = L'\0';
            }
            if(!ui->edFractionalItemNameWithTanween->text().isEmpty())
            {
                fractionalItemNameWithTanween = (wchar_t*)malloc((ui->edFractionalItemNameWithTanween->text().length() + 1)*sizeof(wchar_t));
                ui->edFractionalItemNameWithTanween->text().toWCharArray(fractionalItemNameWithTanween);
                fractionalItemNameWithTanween[ui->edFractionalItemNameWithTanween->text().length()] = L'\0';
            }
            if(!ui->edFractionalDualItemName->text().isEmpty())
            {
                fractionalDualItemName = (wchar_t*)malloc((ui->edFractionalDualItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edFractionalDualItemName->text().toWCharArray(fractionalDualItemName);
                fractionalDualItemName[ui->edFractionalDualItemName->text().length()] = L'\0';
            }
            if(!ui->edFractionalPluralItemName->text().isEmpty())
            {
                fractionalPluralItemName = (wchar_t*)malloc((ui->edFractionalPluralItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edFractionalPluralItemName->text().toWCharArray(fractionalPluralItemName);
                fractionalPluralItemName[ui->edFractionalPluralItemName->text().length()] = L'\0';
            }



            res = fnc(
                        num,
                        itemName,
                        itemNameWithTanween,
                        dualItemName,
                        pluralItemName,
                        ig,
                        fractionalItemName,
                        fractionalItemNameWithTanween,
                        fractionalDualItemName,
                        fractionalPluralItemName,
                        fig,
                        decimalPlace
                        );
            if(res)
            {
                ui->edResult->setText(QString::fromWCharArray(res));
            }

            if(itemName)
                free(itemName);
            if(itemNameWithTanween)
                free(itemNameWithTanween);
            if(dualItemName)
                free(dualItemName);
            if(pluralItemName)
                free(pluralItemName);
            if(fractionalItemName)
                free(fractionalItemName);
            if(fractionalItemNameWithTanween)
                free(fractionalItemNameWithTanween);
            if(fractionalDualItemName)
                free(fractionalDualItemName);
            if(fractionalPluralItemName)
                free(fractionalPluralItemName);
            if(res)
                clean(res);
        }
    }
    else
        QMessageBox::critical(this, "", lib.errorString());
}

void MainView::on_btnGetFnum2aW_clicked()
{
    ui->edResult->clear();
    QLibrary lib("num2a");
    lib.load();
    if(lib.isLoaded())
    {
        GET_FNUM2AW_FUNC fnc = (GET_FNUM2AW_FUNC)lib.resolve("get_fnum2aW");
        N2A_CLEAN_FUNC clean = (N2A_CLEAN_FUNC)lib.resolve("n2a_clean");
        if(fnc && clean)
        {
            wchar_t res[MAX_NUMBER_NAME_LENGTH];
            wchar_t *itemName = NULL, *itemNameWithTanween = NULL, *dualItemName = NULL,
                    *pluralItemName = NULL;
            wchar_t *fractionalItemName = NULL,
            *fractionalItemNameWithTanween = NULL,
            *fractionalDualItemName = NULL,
            *fractionalPluralItemName = NULL;
            int ig = ui->cbItemGender->currentIndex();
            double num = ui->edNumber->text().toDouble();
            int fig = ui->cbFractionalItemNameGender->currentIndex();
            int decimalPlace = ui->edDecimalPlace->value();

            if(!ui->edItemName->text().isEmpty())
            {
                itemName = (wchar_t*)malloc((ui->edItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edItemName->text().toWCharArray(itemName);
                itemName[ui->edItemName->text().length()] = L'\0';
            }
            if(!ui->edItemNameWithTanween->text().isEmpty())
            {
                itemNameWithTanween = (wchar_t*)malloc((ui->edItemNameWithTanween->text().length() + 1)*sizeof(wchar_t));
                ui->edItemNameWithTanween->text().toWCharArray(itemNameWithTanween);
                itemNameWithTanween[ui->edItemNameWithTanween->text().length()] = L'\0';
            }
            if(!ui->edDualItemName->text().isEmpty())
            {
                dualItemName = (wchar_t*)malloc((ui->edDualItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edDualItemName->text().toWCharArray(dualItemName);
                dualItemName[ui->edDualItemName->text().length()] = L'\0';
            }
            if(!ui->edPluralItemName->text().isEmpty())
            {
                pluralItemName = (wchar_t*)malloc((ui->edPluralItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edPluralItemName->text().toWCharArray(pluralItemName);
                pluralItemName[ui->edPluralItemName->text().length()] = L'\0';
            }
            if(!ui->edFractionalItemName->text().isEmpty())
            {
                fractionalItemName = (wchar_t*)malloc((ui->edFractionalItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edFractionalItemName->text().toWCharArray(fractionalItemName);
                fractionalItemName[ui->edFractionalItemName->text().length()] = L'\0';
            }
            if(!ui->edFractionalItemNameWithTanween->text().isEmpty())
            {
                fractionalItemNameWithTanween = (wchar_t*)malloc((ui->edFractionalItemNameWithTanween->text().length() + 1)*sizeof(wchar_t));
                ui->edFractionalItemNameWithTanween->text().toWCharArray(fractionalItemNameWithTanween);
                fractionalItemNameWithTanween[ui->edFractionalItemNameWithTanween->text().length()] = L'\0';
            }
            if(!ui->edFractionalDualItemName->text().isEmpty())
            {
                fractionalDualItemName = (wchar_t*)malloc((ui->edFractionalDualItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edFractionalDualItemName->text().toWCharArray(fractionalDualItemName);
                fractionalDualItemName[ui->edFractionalDualItemName->text().length()] = L'\0';
            }
            if(!ui->edFractionalPluralItemName->text().isEmpty())
            {
                fractionalPluralItemName = (wchar_t*)malloc((ui->edFractionalPluralItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edFractionalPluralItemName->text().toWCharArray(fractionalPluralItemName);
                fractionalPluralItemName[ui->edFractionalPluralItemName->text().length()] = L'\0';
            }



            if( fnc(res, MAX_NUMBER_NAME_LENGTH, num, itemName, itemNameWithTanween,
                dualItemName, pluralItemName, ig, fractionalItemName, fractionalItemNameWithTanween,
                fractionalDualItemName, fractionalPluralItemName, fig, decimalPlace ))
            {
                ui->edResult->setText(QString::fromWCharArray(res));
            }

            if(itemName)
                free(itemName);
            if(itemNameWithTanween)
                free(itemNameWithTanween);
            if(dualItemName)
                free(dualItemName);
            if(pluralItemName)
                free(pluralItemName);
            if(fractionalItemName)
                free(fractionalItemName);
            if(fractionalItemNameWithTanween)
                free(fractionalItemNameWithTanween);
            if(fractionalDualItemName)
                free(fractionalDualItemName);
            if(fractionalPluralItemName)
                free(fractionalPluralItemName);
        }
    }
    else
        QMessageBox::critical(this, "", lib.errorString());
}

void MainView::on_btnGetnum2aW_clicked()
{
    ui->edResult->clear();
    QLibrary lib("num2a");
    lib.load();
    if(lib.isLoaded())
    {
        GET_NUM2AW_FUNC fnc = (GET_NUM2AW_FUNC)lib.resolve("get_num2aW");
        N2A_CLEAN_FUNC clean = (N2A_CLEAN_FUNC)lib.resolve("n2a_clean");
        if(fnc && clean)
        {
            wchar_t res[MAX_NUMBER_NAME_LENGTH];
            wchar_t *itemName = NULL, *itemNameWithTanween = NULL, *dualItemName = NULL,
                    *pluralItemName = NULL;
            int ig = ui->cbItemGender->currentIndex();
            double num = ui->edNumber->text().toDouble();

            if(!ui->edItemName->text().isEmpty())
            {
                itemName = (wchar_t*)malloc((ui->edItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edItemName->text().toWCharArray(itemName);
                itemName[ui->edItemName->text().length()] = L'\0';
            }
            if(!ui->edItemNameWithTanween->text().isEmpty())
            {
                itemNameWithTanween = (wchar_t*)malloc((ui->edItemNameWithTanween->text().length() + 1)*sizeof(wchar_t));
                ui->edItemNameWithTanween->text().toWCharArray(itemNameWithTanween);
                itemNameWithTanween[ui->edItemNameWithTanween->text().length()] = L'\0';
            }
            if(!ui->edDualItemName->text().isEmpty())
            {
                dualItemName = (wchar_t*)malloc((ui->edDualItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edDualItemName->text().toWCharArray(dualItemName);
                dualItemName[ui->edDualItemName->text().length()] = L'\0';
            }
            if(!ui->edPluralItemName->text().isEmpty())
            {
                pluralItemName = (wchar_t*)malloc((ui->edPluralItemName->text().length() + 1)*sizeof(wchar_t));
                ui->edPluralItemName->text().toWCharArray(pluralItemName);
                pluralItemName[ui->edPluralItemName->text().length()] = L'\0';
            }

            if(fnc(res, MAX_NUMBER_NAME_LENGTH, num, itemName, itemNameWithTanween, dualItemName, pluralItemName, ig))
            {
                ui->edResult->setText(QString::fromWCharArray(res));
            }

            if(itemName)
                free(itemName);
            if(itemNameWithTanween)
                free(itemNameWithTanween);
            if(dualItemName)
                free(dualItemName);
            if(pluralItemName)
                free(pluralItemName);
        }
    }
    else
        QMessageBox::critical(this, "", lib.errorString());

}
