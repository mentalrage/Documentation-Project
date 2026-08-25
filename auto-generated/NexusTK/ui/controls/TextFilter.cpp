// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OO
// Source by-file doc: by-file/TextFilter.md
// UID:0000EQ | by-class/TextFilter.md | Completion:92 | Confidence:95
#include "TextFilter.h"

// UID:0001YY | by-type/by-vtable/TextFilterVtable.md | Completion:91 | Confidence:95
// Compiler-emitted one-slot TextFilter vtable/RTTI layout.
// Source reconstruction is covered by [UID:0000EQ][TextFilter](by-class/TextFilter.md); no raw vtable array or scalar-deleting-destructor source method is emitted here.

// UID:0000SG | by-global/g_pTextFilter.md | Completion:92 | Confidence:95
TextFilter *g_pTextFilter = 0;

template <>
Singleton<TextFilter>::Singleton()
{
    g_pTextFilter = static_cast<TextFilter *>(this);
}

template <>
Singleton<TextFilter>::~Singleton()
{
    g_pTextFilter = 0;
}

// UID:00050B | by-memory/0x00595760-0x00595795.TextFilterConstructor.md | Completion:92 | Confidence:95
TextFilter::TextFilter()
{
}

// UID:00050C | by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md | Completion:92 | Confidence:95
TextFilter::~TextFilter()
{
}

// UID:0002XT | by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md | Completion:92 | Confidence:95
// Exact loader-zero-filled storage for g_pTextFilter at 0x0067adc8.
// The sole source definition and Singleton<TextFilter> specialization bodies are emitted by [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md); do not duplicate the pointer definition from this storage child.

// UID:0000TK | by-global/SanitizeWideTextForChat.md | Completion:93 | Confidence:94
// UID:00050D | by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md | Completion:93 | Confidence:94
void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength)
{
    for (unsigned int i = 0; i < textLength; ++i) {
        wchar_t ch = text[i];
        if (ch == 0)
            break;

        if (ch == L'\n' || ch == L'\r' || (ch >= L' ' && ch <= 0x7f))
            continue;

        switch (ch) {
        case 0x00e9:
        case 0x00e8:
        case 0x00e0:
        case 0x00f9:
        case 0x00f4:
        case 0x00ee:
        case 0x00eb:
        case 0x00ef:
        case 0x00fb:
        case 0x00fa:
        case 0x00e2:
        case 0x00e7:
            continue;
        default:
            text[i] = L'?';
            break;
        }
    }
}

// UID:0001JU | by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md | Completion:92 | Confidence:94
// Exact TextFilter constructor and destructor source bodies remain class-owned but emit as ordered g_pTextFilter children after both explicit Singleton specializations; the sanitizer emits through SanitizeWideTextForChat.
// Alignment and the scalar deleting destructor are compiler-generated and are not handwritten source.
