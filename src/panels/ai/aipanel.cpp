/*
 * SPDX-FileCopyrightText: 2026 HarryManager Developers
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "aipanel.h"

#include <KLocalizedString>

#include <QFont>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

AIPanel::AIPanel(QWidget *parent)
    : Panel(parent)
{
    m_titleLabel = new QLabel(i18n("AI Assistant"), this);
    QFont titleFont = m_titleLabel->font();
    titleFont.setBold(true);
    titleFont.setPointSize(titleFont.pointSize() + 1);
    m_titleLabel->setFont(titleFont);

    m_promptInput = new QLineEdit(this);
    m_promptInput->setPlaceholderText(i18n("Ask about this folder..."));
    m_promptInput->setAccessibleName(i18n("Ask about this folder"));

    m_searchButton = new QPushButton(QIcon::fromTheme(QStringLiteral("system-search")), i18n("Search"), this);

    m_statusLabel = new QLabel(i18n("No AI provider configured."), this);
    m_statusLabel->setWordWrap(true);
    m_statusLabel->setStyleSheet(QStringLiteral("color: gray;"));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(8);

    layout->addWidget(m_titleLabel);
    layout->addWidget(m_promptInput);
    layout->addWidget(m_searchButton);
    layout->addWidget(m_statusLabel);
    layout->addStretch();
}

AIPanel::~AIPanel() = default;

bool AIPanel::urlChanged()
{
    return true;
}

#include "moc_aipanel.cpp"
