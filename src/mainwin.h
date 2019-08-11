/*-
 * Copyright (c) 2019 Marcel Kaiser. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QItemSelection>
#include <QListView>
#include <QComboBox>

#include "model.h"
#include "list.h"

class MainWin : public QMainWindow {
        Q_OBJECT
public:
	MainWin(QWidget *parent = 0);
	void closeEvent(QCloseEvent *event);
public slots:
	void catchSelectionChanged(const QItemSelection &selected,
	    const QItemSelection &deselected);
	void catchItemDroped(QStringList &files);
	void removeWallpaper(void);
	void addWallpaper(void);
	void setWallpaper(void);
	void undo(void);
	void redo(void);
	void quit(void);
private:
	void    errWin(QString message);
	QIcon   loadIcon(const char *name, ...);
	QFrame  *mkLine(void);
	QString getHomeDir(void);
private:
	Model	    *model;
	List	    *list;
	QComboBox   *modeCB;
	QPushButton *removePB;
	QPushButton *setPB;
	QPushButton *undoPB;
	QPushButton *redoPB;
};
