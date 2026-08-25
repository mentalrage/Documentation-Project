*** UID:00005C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FontStyle.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FontStyle

## Status

- Confidence: very strong for behavior, natural layout, owner/emitter route, complete CPP/H split, compiler/source distinction, and method source shape; high for exact stripped field spelling.
- Likely source file: [UID:0000JI][FontStyle](by-file/FontStyle.md)
- Generated route: [UID:00005C] `FontStyle` -> [UID:0000JI][FontStyle](by-file/FontStyle.md) `FontStyle.cpp` -> `auto-generated/NexusTK/ui/controls/FontStyle.cpp`
- Exact authored source-bearing memory doc: [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md). [UID:0000XM][0x004536e0-0x00453732.FontStyleImplicitDestructor](by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md) is compiler-emitted and non-emitting.
- Compiler/vector support: [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) remains non-reconstructable and non-emitting.
- Direct StaticTextControlPane2 consumer: [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md) legally expresses enabled state, parent/text opacity, and foreground/background color reads through the six inline accessors now present in the declaration.

## Class Purpose

`FontStyle` is a compact reusable text-rendering style descriptor. It stores enabled/opacity/scalar style fields and a vector-style collection of 16-byte `FontStyleRule` records. Static text and help panes consume these records to apply text color, secondary/background/outline/shadow color, effect mode, and alignment while MiniMap and NewMail use the same type as caller-side style setup.

## Layout Summary

The recovered object is 0x20 bytes:

| Offset | Declaration field | Evidence and caveat |
| --- | --- | --- |
| `+0x00` | `m_enabled` | Constructor sets byte `1`; HelpPane style-copy logic treats zero as disabled/no-style. |
| `+0x01..+0x03` | natural alignment gap | Padding for the following float; no source-visible field is declared. |
| `+0x04` | `m_parentOpacity` | Constructor writes `0.2f`; HelpPane copies/uses it as the outer or parent/pane opacity scalar. |
| `+0x08` | `m_textOpacity` | Constructor writes `0.2f`; HelpPane text-part path uses the paired copied text opacity/scalar, making this the stronger active opacity name. |
| `+0x0c` | `m_foregroundColor` | Constructor writes `1`; HelpPane paint/style propagation supports a foreground/primary color role. |
| `+0x10` | `m_backgroundColor` | Constructor writes `0x80`; HelpPane paint/style propagation supports a background/secondary color role. |
| `+0x14/+0x18/+0x1c` | `m_rules` | Begin/end/capacity triplet for 16-byte `FontStyleRule` records, source-expressed as a vector-style collection. |

See [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md) for the field-level caveats.

Rule records are 16 bytes:

| Offset | Declaration field | Evidence and caveat |
| --- | --- | --- |
| `+0x00` | `m_textColor` | First `Configure` argument; StaticText2 and HelpPane draw consumers pass it to text-color setup. |
| `+0x04` | `m_secondaryColor` | Second `Configure` argument; consumers use it as secondary/background/outline/shadow color. |
| `+0x08` | `m_effect` | Low byte of third `Configure` argument; consumers branch on effect-like values for normal/outlined/shadowed text. |
| `+0x09..+0x0b` | natural alignment gap | Compiler padding before the dword at `+0x0c`; no source-visible field is declared. |
| `+0x0c` | `m_alignment` | Fourth `Configure` argument; HelpPane/StaticText2 consumers copy it into text alignment state before drawing. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| implicit `~FontStyle` lowering | [UID:0000XM][0x004536e0-0x00453732.FontStyleImplicitDestructor](by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md) | Compiler-emitted vector teardown. The source omits an explicit destructor. |
| `FontStyle` | `0x00499f10-0x00499f51` | Initializes defaults: `m_enabled`, both float fields `0.2f`, scalar color values `1` and `0x80`, and empty rule storage. |
| `GetRule` | `0x00499f60-0x00499f85` | Void bounded copy helper: copies one 16-byte rule record into the caller buffer when the requested index is in range; callers ignore the raw return register. |
| `Configure` | `0x00499f90-0x00499fda` | Builds a `FontStyleRule { m_textColor, m_secondaryColor, m_effect, m_alignment }` record and appends it to `m_rules`. |

### Inline Consumer-Proven Accessors

| Accessor | Exact source role in StaticTextControlPane2 |
| --- | --- |
| `IsEnabled()` | Gates parent and embedded-child style application from byte `m_enabled`. |
| `SetEnabled(bool)` | Constructor disables its default local style before optional deep-copy assignment. |
| `GetParentOpacity()` | Drives outer mode 1 versus mode 3/alpha thresholds. |
| `GetTextOpacity()` | Drives embedded text-part mode 1 versus mode 3/alpha thresholds. |
| `GetForegroundColor()` | Supplies StaticTextControlPane2 fill color. |
| `GetBackgroundColor()` | Supplies StaticTextControlPane2 frame color. |

These are direct field reads/writes in the consumer and are most plausibly small header-inline methods. They add no new binary entry points, preserve the complete existing layout/body/history, and avoid illegal private-member access from UID0000E4.

Vector growth at `0x0049ac60-0x0049ad74` is a one-caller compiler/template helper generated by `m_rules.push_back(rule)`, not a source-facing method.

## Caller Evidence

- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) constructs a local `FontStyle`, configures it, and passes it to `StaticTextControlPane2` labels for NPC/Portal and coordinate text.
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md) constructs/configures a local style for the EPF compose dialog's "Keep a copy" label.
- [UID:000063][HelpPane](by-class/HelpPane.md) embeds a compatible style record and copies caller-provided style data into it.
- [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md) calls the bounded rule lookup at `0x00499f60` from two line-drawing sites.
- Cleanup callers are currently minimap-local scoped-style cleanup/unwind paths. The function itself is generic rule-vector teardown and should stay with `FontStyle`.

## Source Placement And Rejected Alternatives

The accepted route is `NexusTK/ui/controls/FontStyle.cpp`. The type is reusable UI text-style support, not a feature-owned helper.

Rejected alternatives:

- `MiniMapDialog` / [UID:0000LE][MiniMap](by-file/MiniMap.md) `MiniMap`: MiniMap constructs local style objects, but NewMail and HelpPane use the same class and rule semantics.
- `NewMailDialog` / [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) `MailDialogs`: NewMail is one caller/consumer for an EPF label, not the owner of the reusable style descriptor.
- `HelpPane` / [UID:0000JU][HelpPanes](by-file/HelpPanes.md) `HelpPanes`: HelpPane is the most important `GetRule` consumer, but constructor/configure fan-out is broader than HelpPane.
- `StaticTextControlPane2`: plausible physical-source fallback, but weaker than the current reusable `FontStyle.cpp` route and cross-feature fan-out.
- Container-only interpretation: rejected for this class because constructor, `GetRule`, and `Configure` are source-facing `FontStyle` methods; only `0x0049ac60` is compiler/container support.
- Generated MiniMap field names such as `m_flags`, `m_bold`, `m_italic`, `m_color`, and `m_size`: rejected as caller-local/generated artifacts and not shared `FontStyleRule` names.
- Count-returning `GetRule`: rejected. The raw helper computes a count for bounds checking, but the in-range path changes `eax` to the output pointer and known callers ignore the return register.

## Final CPP/H Reconstruction Policy

The formal CPP includes `FontStyle.h` and expands `[[CHILDREN]]`. The formal H is the sole declaration owner for `FontStyleRule`, `FontStyle`, six inline accessors, and three out-of-line method declarations. Exact authored method bodies are emitted only by [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md) at source position 10. UID0000XM, UID0001UN, and UID00011W emit no source.

The declaration intentionally uses `bool`, natural alignment, and `std::vector<FontStyleRule>`. This is the correct developer source shape for the 0x20 object, 0x10 rules, implicit destructor/copy/assignment operations, and non-emitting vector-growth slow path. Do not emit explicit padding arrays, an empty destructor, raw vector triplets, or manual heap/free code.

The six accessors are declaration-inline source support. They do not move FontStyle into StaticTextControlPane.cpp, alter UID0000JI ownership/emission, duplicate FontStyleCore bodies, or convert vector growth/shared EH cleanup into handwritten code.

## Caveats

- Exact historical field spelling remains inferred. The declaration field names are source-facing best names supported by constructor, Configure, StaticText2, and HelpPane consumers.
- `m_foregroundColor` and `m_backgroundColor` are medium confidence from HelpPane paint/style propagation. Earlier B006 names `fillColor`/`frameColor` are preserved as a historical spelling attempt but are weaker than the B012 foreground/background recommendation.
- `m_secondaryColor` is preferred over the older `textBackColor` because the same slot serves text-back, outline, shadow, or secondary-color roles depending on draw effect.
- The third `Configure` argument is byte-sized. The three bytes before dword `m_alignment` are natural alignment and intentionally have no source field.
- `0x0049ac60` remains ignored as compiler/vector support; final source expresses it as `m_rules.push_back(rule)`.

## Cross-References

- [UID:0000JI][FontStyle](by-file/FontStyle.md)
- [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md)
- [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md)
- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)

## Changes

- 2026-08-17 B006 accepted UID0000JI whole-file callback:
  - Raised `89/91 -> 94/95`; retained owner/emitter UID0000JI and `RECONSTRUCTABLE:TRUE`.
  - Moved the complete declaration from CPP to formal H; CPP now contains only `#include "FontStyle.h"` and `[[CHILDREN]]`.
  - Replaced explicit padding and byte-backed boolean source with natural `bool`/MSVC alignment, omitted the explicit destructor, retained six inline accessors, and preserved exact 0x20/0x10 ABI.
  - Fixed the dangling vector-growth row and made compiler destructor/growth dispositions explicit. Earlier empty-destructor, CPP-shell, reserved-array, and source-placement caveats below are historical superseded assumptions.

- 2026-07-13 B002 accepted UID00011V callback:
  - Raised `87/89 -> 89/91` while retaining UID0000JI ownership/emission and every existing declaration, layout, body, vector-growth, and history claim.
  - Added exact inline `IsEnabled`, `SetEnabled`, parent/text opacity, and foreground/background color accessors required by UID0000E4's legal source expression; direct field behavior proves each accessor and no standalone binary entry is invented.
- 2026-06-21 B012 FontStyle source-quality incorporation: kept the class at `87/89`, updated the declaration and prose to B012 source-facing `m_*` field names, documented `m_secondaryColor` and `m_alignment` as the preferred rule names over older `textBackColor`/`textAlign`, kept the exact `GetRule` void side-effect-copy model, and retained `0x0049ac60` as compiler/vector support generated by `m_rules.push_back(rule)`.
- 2026-06-20 B006 FontStyle source-quality implementation: raised the class to `87/89`, added declaration-level first-draft C++ for `FontStyleRule` and `FontStyle` with `[[CHILDREN]]`, refined rule fields to `textColor`, `textBackColor`, `effect`, `reserved`, and `textAlign`, corrected `GetRule` to a void side-effect copy helper, documented destructor-like cleanup/source placement, rejected MiniMap/NewMail/HelpPane ownership and generated MiniMap names, and kept `0x0049ac60` as non-emitting vector growth support.
- 2026-06-05: A004 raised the class to `84/88`, attached it to [UID:0000JI][FontStyle](by-file/FontStyle.md), removed stale recovered-file provenance, added the live `0x00499f60` bounded rule lookup, and documented the HelpPane text-renderer callers. Final C++ remains blank because field names and original source placement are still below the final reconstruction gate.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the class-owned function starts `0x004536e0`, `0x00499f10`, `0x00499f90`, and helper `0x0049ac60`; parent attachment was deferred at that time until this page crossed the completion gate.
- 2026-05-30: Scored the class page from 0/0 to 72/84 and linked the `ClearRules` method row to its detailed by-memory page. Evidence: IDA MCP recheck of `0x004536e0` confirms bounds, caller/callee set, and rule-vector teardown offsets; existing docs already cover constructor/configure/layout/caller fanout.
