/* Author: Yuriy Kuzin
 */
#ifndef QJSONDIFF_H
#define QJSONDIFF_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QMargins>
#include <QPushButton>
#include <QModelIndex>
#include <QScrollBar>

#include "qjsoncontainer.h"
#include"qjsonitem.h"
#include"qjsonmodel.h"

class QPaintEvent;

class QJsonDiff : public QWidget
{
    Q_OBJECT

public:
    explicit QJsonDiff(QWidget *parent = 0);
    ~QJsonDiff();
    QJsonContainer *left_cont;
    QJsonContainer *right_cont;
    void loadJsonLeft(QJsonDocument data);
    void loadJsonLeft(QString data);
    void loadJsonRight(QJsonDocument data);
    void loadJsonRight(QString data);
    QTreeView* getLeftTreeView();
    QTreeView* getRightTreeView();
    QJsonModel* getLeftJsonModel();
    QJsonModel* getRightJsonModel();
    QGridLayout *qjsoncontainer_layout;
    QGroupBox *container_left_groupbox;
    QGroupBox *container_right_groupbox;
    QGroupBox * common_groupbox;
    QVBoxLayout *common_layout;
    QPushButton *compare_pushbutton;
    void expandIt();
    QCheckBox *syncScroll_checkbox;
	QCheckBox *extractModeEnable;

    void compareModels(QJsonModel *modelLeft, const QModelIndex &parentLeft, QJsonModel *modelRight);
    int findIndexInModel(QJsonModel *modelLeft, QJsonTreeItem *itemLeft, QModelIndex idxLeft, QJsonModel *modelRight, const QModelIndex &parentRight);
    int fixColors(QJsonModel *model, const QModelIndex &parent);
    int prevLeftScroll;
    int prevRightScroll;
    void startComparison();
    void setBrowseVisible(bool state);

	void saveExtractFile(const QString &filename, const QJsonObject &obj);
	QJsonObject fileObj;
	void openJson(const QString &filename);
signals:

public slots:
    void on_compare_pushbutton_clicked();
    void on_lefttreeview_clicked(const QModelIndex&);
    void on_righttreeview_clicked(const QModelIndex&);
    void on_lefttreeview_scroll_valuechanged(int);
    void on_righttreeview_scroll_valuechanged(int);
    void reinitRightModel();
    void reinitLeftModel();


protected:
    void paintEvent(QPaintEvent *);
};

#endif // QJSONDIFF_H
