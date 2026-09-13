/*
 * SPDX-FileCopyrightText: 2026 HarryManager Developers
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef AIPANEL_H
#define AIPANEL_H

#include "panels/panel.h"

class QLabel;
class QLineEdit;
class QPushButton;

/**
 * @brief Panel providing AI assistant capabilities.
 */
class AIPanel : public Panel
{
    Q_OBJECT

public:
    explicit AIPanel(QWidget *parent = nullptr);
    ~AIPanel() override;

protected:
    bool urlChanged() override;

private:
    QLabel *m_titleLabel;
    QLabel *m_currentFolderLabel;
    QLineEdit *m_promptInput;
    QPushButton *m_searchButton;
    QLabel *m_statusLabel;
};

#endif // AIPANEL_H
