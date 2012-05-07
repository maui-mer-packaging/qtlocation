/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtLocation module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
** This file is part of the Ovi services plugin for the Maps and
** Navigation API.  The use of these services, whether by use of the
** plugin or by other means, is governed by the terms and conditions
** described by the file OVI_SERVICES_TERMS_AND_CONDITIONS.txt in
** this package, located in the directory containing the Ovi services
** plugin source code.
**
****************************************************************************/

#ifndef QGEOROUTINGMANAGER_NOKIA_H
#define QGEOROUTINGMANAGER_NOKIA_H

#include "qgeoserviceproviderplugin_nokia.h"

#include <qgeoserviceprovider.h>
#include <qgeoroutingmanagerengine.h>

QT_BEGIN_NAMESPACE

class QGeoNetworkAccessManager;
class QGeoUriProvider;

class QGeoRoutingManagerEngineNokia : public QGeoRoutingManagerEngine
{
    Q_OBJECT
public:
    QGeoRoutingManagerEngineNokia(QGeoNetworkAccessManager *networkInterface,
                                  const QMap<QString, QVariant> &parameters,
                                  QGeoServiceProvider::Error *error,
                                  QString *errorString);
    ~QGeoRoutingManagerEngineNokia();

    QGeoRouteReply *calculateRoute(const QGeoRouteRequest &request);
    QGeoRouteReply *updateRoute(const QGeoRoute &route, const QGeoCoordinate &position);

private Q_SLOTS:
    void routeFinished();
    void routeError(QGeoRouteReply::Error error, const QString &errorString);

private:
    QString calculateRouteRequestString(const QGeoRouteRequest &request);
    QString updateRouteRequestString(const QGeoRoute &route, const QGeoCoordinate &position);
    QString routeRequestString(const QGeoRouteRequest &request) const;
    bool checkEngineSupport(const QGeoRouteRequest &request,
                            QGeoRouteRequest::TravelModes travelModes) const;
    QString modesRequestString(const QGeoRouteRequest &request,
                               QGeoRouteRequest::TravelModes travelModes) const;
    static QString trimDouble(double degree, int decimalDigits = 10);

    QGeoNetworkAccessManager *m_networkManager;
    QGeoUriProvider *m_uriProvider;
    QString m_appId;
    QString m_token;
};

QT_END_NAMESPACE

#endif
