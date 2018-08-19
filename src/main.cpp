/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2017 Deepin, Inc.
 *               2011 ~ 2017 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "constant.h"
#include "main_window.h"
#include "utils.h"
#include <DApplication>
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <DWidgetUtil>
#include <iostream>
#include <sys/types.h>
#include <thread>
#include <unistd.h>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();

    DApplication app(argc, argv);

    const QString socket_path(QString("deepin-desktop-monitor_%1").arg(getuid()));
    if (app.setSingleInstance(socket_path)) {
        app.loadTranslator();

        app.setOrganizationName("deepin");
        app.setApplicationName("deepin-desktop-monitor");
        app.setApplicationDisplayName(QObject::tr("Deepin Desktop Monitor"));
        app.setApplicationVersion("1.0");

        app.setProductIcon(QPixmap::fromImage(QImage(Utils::getQrcPath("logo_96.svg"))));
        app.setProductName(QApplication::tr("Deepin Desktop Monitor"));
        
        app.setWindowIcon(QIcon(Utils::getQrcPath("logo_48.png")));

        MainWindow window;
        window.show();
        window.registerDesktop();

        return app.exec();
    }

    return 0;
}
