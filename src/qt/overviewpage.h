// Copyright (c) 2011-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2018-2020 The STAKEC developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_OVERVIEWPAGE_H
#define BITCOIN_QT_OVERVIEWPAGE_H

#include "amount.h"

#include <QWidget>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>
#include <QXmlStreamReader>
#include <QUrl>

class ClientModel;
class TransactionFilterProxy;
class TxViewDelegate;
class WalletModel;

namespace Ui
{
class OverviewPage;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget* parent = 0);
    ~OverviewPage();

    void setClientModel(ClientModel* clientModel);
    void setWalletModel(WalletModel* walletModel);
    void showOutOfSyncWarning(bool fShow);

public Q_SLOTS:
    void updateNewsList();

public slots:
    void setBalance(const CAmount& balance, const CAmount& unconfirmedBalance, const CAmount& immatureBalance, const CAmount& watchOnlyBalance, const CAmount& watchUnconfBalance, const CAmount& watchImmatureBalance);
    void newsFinished(QNetworkReply *reply);
    void newsReadyRead();
    void newsMetaDataChanged();
    void newsError(QNetworkReply::NetworkError);

signals:
    void transactionClicked(const QModelIndex& index);

private:
    QTimer* timer;
    Ui::OverviewPage* ui;
    ClientModel* clientModel;
    WalletModel* walletModel;
    CAmount currentBalance;
    CAmount currentUnconfirmedBalance;
    CAmount currentImmatureBalance;
    CAmount currentWatchOnlyBalance;
    CAmount currentWatchUnconfBalance;
    CAmount currentWatchImmatureBalance;
    int nDisplayUnit;

    TxViewDelegate* txdelegate;
    TransactionFilterProxy* filter;

    void parseXml();
    void newsGet(const QUrl &url);

    QXmlStreamReader xml;

    QNetworkAccessManager manager;
    QNetworkReply *currentReply;

    void SetLinks();

private slots:
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex& index);
    void updateAlerts(const QString& warnings);
    void updateWatchOnlyLabels(bool showWatchOnly);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

};

#endif // BITCOIN_QT_OVERVIEWPAGE_H
