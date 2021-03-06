/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _PROCESS_DNLD_H_
#define _PROCESS_DNLD_H_

#include <QObject>
#include <QString>
#include <QStringList>

class ProgressWidget;
class QProcess;
class QTimer;

class DnldProcess : public QObject
{
  Q_OBJECT

public:
  enum DnldPhase { READING, WRITING, FLASHING };
  DnldProcess(const QString &cmd, const QStringList &args, ProgressWidget *progress, enum DnldPhase dnldPhase = READING);
  ~DnldProcess();
  bool run();
  

signals:
  void finished();

protected slots:
  void onStarted();
  void onReadyReadStandardOutput();
  void onReadyReadStandardError();
  void onFinished(int);
  void onKillTimerElapsed();

protected:
  void analyseStandardOutput(const QString &text);
  void analyseStandardError(const QString &text);
  void errorWizard();
  ProgressWidget *progress;
  const QString cmd;
  const QStringList args;
  QProcess *process;
  bool hasErrors;
  QString currStdoutLine;
  QString currStderrLine;
  DnldPhase dnldPhase;
  int itemsProcessed;
#if !__GNUC__
  QTimer *killTimer;
#endif
};

#endif // _PROCESS_FLASH_H_
