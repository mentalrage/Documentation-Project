// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JI
// Source by-file doc: by-file/FontStyle.md
// UID:00005C | by-class/FontStyle.md | Completion:94 | Confidence:95
#pragma once

#include <vector>

struct FontStyleRule
{
    unsigned int m_textColor;
    unsigned int m_secondaryColor;
    unsigned char m_effect;
    unsigned int m_alignment;
};

class FontStyle
{
public:
    FontStyle();

    bool IsEnabled() const { return m_enabled; }
    void SetEnabled(bool enabled) { m_enabled = enabled; }
    float GetParentOpacity() const { return m_parentOpacity; }
    float GetTextOpacity() const { return m_textOpacity; }
    unsigned int GetForegroundColor() const { return m_foregroundColor; }
    unsigned int GetBackgroundColor() const { return m_backgroundColor; }

    void GetRule(unsigned int index, FontStyleRule *outRule) const;
    void Configure(unsigned int textColor,
                   unsigned int secondaryColor,
                   unsigned char effect,
                   unsigned int alignment);

private:
    bool m_enabled;
    float m_parentOpacity;
    float m_textOpacity;
    unsigned int m_foregroundColor;
    unsigned int m_backgroundColor;
    std::vector<FontStyleRule> m_rules;
};
