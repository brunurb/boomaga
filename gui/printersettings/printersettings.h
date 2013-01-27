/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 *
 * Copyright: 2012-2013 Alexander Sokoloff
 * Authors:
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#ifndef PRINTERSETTINGS_H
#define PRINTERSETTINGS_H

#include "kernel/printer.h"
#include <QDialog>
#include <QList>
#include <QHash>
#include <QListWidgetItem>

class QAbstractButton;

namespace Ui {
class PrinterSettings;
}

class PrinterSettings : public QDialog
{
    Q_OBJECT

public slots:
    static PrinterSettings *create(Printer *printer);

public:
    explicit PrinterSettings(QWidget *parent = 0);
    ~PrinterSettings();
    
    Printer *currentPrinter() const { return mPrinter; }
    void setCurrentPrinter(Printer *printer);

protected:
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void updateWidgets();
    void btnClicked(QAbstractButton *button);

    void updatePreview();

private:
    Ui::PrinterSettings *ui;
    static PrinterSettings *mInstance;
    Printer *mPrinter;
    Printer::Unit mUnit;
};

#endif // PRINTERSETTINGS_H