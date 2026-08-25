// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JI
// Source by-file doc: by-file/FontStyle.md
// UID:00005C | by-class/FontStyle.md | Completion:94 | Confidence:95
#include "FontStyle.h"

// UID:00011T | by-memory/0x00499f10-0x00499fda.FontStyleCore.md | Completion:94 | Confidence:96
FontStyle::FontStyle()
    : m_enabled(true),
      m_parentOpacity(0.2f),
      m_textOpacity(0.2f),
      m_foregroundColor(1),
      m_backgroundColor(0x80)
{
}

void FontStyle::GetRule(unsigned int index, FontStyleRule *outRule) const
{
    if (index < m_rules.size()) {
        *outRule = m_rules[index];
    }
}

void FontStyle::Configure(unsigned int textColor,
                          unsigned int secondaryColor,
                          unsigned char effect,
                          unsigned int alignment)
{
    FontStyleRule rule;
    rule.m_textColor = textColor;
    rule.m_secondaryColor = secondaryColor;
    rule.m_effect = effect;
    rule.m_alignment = alignment;

    m_rules.push_back(rule);
}
