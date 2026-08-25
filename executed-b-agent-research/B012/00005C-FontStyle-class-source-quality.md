** TARGET-REPORT-UID:00005C **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B012 source-quality report: [UID:00005C] FontStyle

Status: FINISHED

## Target

- UID: `00005C`
- Target doc: `source-3/project-documentation/by-class/FontStyle.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/00005C-FontStyle-class-source-quality.md`
- Assignment: B-agent class source-quality and heuristic/inference pass.
- Constraints followed: no by-* documentation was edited and `by-memory/-coverage-report.md` was not edited.

## Evidence Checked

- B012 instructions:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B012/goal.md`
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
- Target/support docs:
  - `by-class/FontStyle.md`
  - `by-file/FontStyle.md`
  - `by-type/by-struct/FontStyleLayout.md`
  - `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`
  - `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`
  - `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`
  - `by-class/StaticTextControlPane2.md`
  - `by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md`
  - `by-memory/0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore.md`
  - `by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md`
  - `by-class/HelpPane.md`
  - `by-class/HelpPane__SimpleHelpTextPartPane.md`
  - `by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md`
  - `by-class/MiniMapDialog.md`
  - `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md`
  - `by-class/NewMailDialog.md`
  - `by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md`
- Prior reports used as read-only evidence leads:
  - `tools/leaser/Agents/Agent-B006/research/00011T-FontStyleCore-source-quality.md`
  - `tools/leaser/Agents/Agent-B013/research/000064-HelpPane__SimpleHelpTextPartPane-source-quality.md`
- Current generated output:
  - `auto-generated/NexusTK/ui/controls/FontStyle.cpp`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/-ag-type-coverage.md`
  - `auto-generated/-ag-memory-coverage.md`
- Coverage/status rows:
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `by-type/by-struct/-coverage-report.md`
  - `by-memory/-coverage-report.md`
  - `project-level/-auto-completion-stats.md`
- Local exported function facts from `source-3/core/data/cache/prewave`:
  - `functions/0x00499f10.json`
  - `functions/0x00499f60.json`
  - `functions/0x00499f90.json`
  - `functions/0x004536e0.json`
  - `functions/0x0049ac60.json`
  - decompiled bundles and caller bundles for the same functions.

No fresh live IDA MCP was available in this session. This report uses current project docs, current generated output, and local prewave exported function facts already present in the workspace. I did not use wave2/wave3 source data as authoritative evidence.

## Current State

`FontStyle.md` is currently `84/88`, reconstructable, owner/emitter [UID:0000JI] `FontStyle.cpp`, and has blank formal C++. The generated output confirms this is not a routing failure:

```text
// UID:00005C | by-class\FontStyle.md | Completion:84 | Confidence:88 | Empty Emitter Marker
// UID:0000XM | ...FontStyleClearRules.md | Completion:86 | Confidence:92 | Empty Emitter Marker
// UID:00011T | ...FontStyleCore.md | Completion:84 | Confidence:90 | Empty Emitter Marker
// UID:0001UN | ...FontStyleLayout.md | Completion:85 | Confidence:90 | Empty Emitter Marker
```

The current generated `FontStyle.cpp` has the right path and parent route, but only empty emitter markers. The implementation blocker is a missing source-quality declaration shell and child method C++, not ownership.

## Function And Layout Evidence

### `0x00499f10` constructor

Local export:

- IDA/Ghidra size: `0x41` / 65 bytes.
- Signature evidence: `__thiscall`, returns `this`.
- Callers: 7 total, including `MiniMapDialog`, `0x004523d0`, `NewMailDialog`, `HelpPane`, and `0x00451c90`.
- No callees.

Decompiled behavior:

- `+0x14`, `+0x18`, and `+0x1c` set to zero.
- `+0x00` byte set to `1`.
- `+0x04` and `+0x08` set to `0.2f` (`0x3e4ccccd`).
- `+0x0c` set to `1`.
- `+0x10` set to `0x80`.

This proves a 0x20-byte object with a 0x14-byte scalar header and a 12-byte vector triplet.

### `0x00499f60` bounded rule copy

Local export:

- IDA/Ghidra size: `0x25` / 37 bytes.
- IDA signature: `unsigned int __thiscall(_DWORD *this, unsigned int, _OWORD *)`.
- Ghidra signature is void-like and copies four dwords.
- Callers: 2, both from `0x004c6630` / HelpPane text drawing.
- No callees.

Important source-quality correction: this should not be modeled as a meaningful `unsigned int` return in first-draft C++.

The IDA decompile leaves `EAX` as either the rule count on the out-of-range path or the output-buffer pointer after a successful copy. That is not a coherent source return contract. Ghidra treats the function as void, and the known HelpPane callers use it for the side-effect copy. Best source-facing signature:

```cpp
void FontStyle::GetRule(unsigned int index, FontStyleRule *outRule) const;
```

Behavior: compute `(rulesEnd - rulesBegin) >> 4`; when `index < count`, copy one 16-byte rule record to `outRule`; otherwise leave `outRule` unchanged. Do not add a null-check: none exists in the target.

Rejected return alternatives:

- `unsigned int GetRule(...)`: rejected because the in-range return is the output pointer, not the count.
- `bool GetRule(...)`: rejected because the function does not normalize the return to `0/1`.
- `FontStyleRule *GetRule(...)`: rejected because callers pass an output buffer and the out-of-range path returns count-like arithmetic.
- `operator[]`: rejected because out-of-range is tolerated and the function copies into caller storage.

### `0x00499f90` rule append/configure

Local export:

- IDA/Ghidra size: `0x4a` / 74 bytes.
- IDA signature: `_OWORD *__thiscall(void *this, int, int, char, int)`.
- Ghidra signature: `void __thiscall(..., uint, uint, undefined1, uint)`.
- Callers: 7, including `MiniMapDialog`, `0x004523d0`, `NewMailDialog`, and `0x00451c90`.
- Callees: one, `0x0049ac60`.

Decompiled behavior:

- Builds a 16-byte stack rule from four arguments.
- Stores argument 1 at rule `+0x00`.
- Stores argument 2 at rule `+0x04`.
- Stores only the low byte of argument 3 at rule `+0x08`.
- Stores argument 4 at rule `+0x0c`.
- If the vector has spare capacity, copies one OWORD and advances end by 16.
- If the vector is full, calls `0x0049ac60`.

Best source-facing name remains `Configure` because current docs and caller prose already use it, but `AddRule` or `AddStyleRule` is a valid fallback if a later source-naming pass standardizes append semantics. The first-draft signature should be:

```cpp
void FontStyle::Configure(unsigned int textColor,
                          unsigned int textBackColor,
                          unsigned char effect,
                          unsigned int textAlign);
```

### `0x004536e0` cleanup

Local export:

- IDA/Ghidra size: `0x52` / 82 bytes.
- Signature: `void __thiscall(_DWORD *this)`.
- Callers: 10 total. Eight are EH/unwind entries; the two normal callers are in the MiniMap/local-style family at `0x004523d0` and `0x00451c90`.
- Callees: `_invalid_parameter_noinfo_noreturn` and `sub_5C7526` free helper.

Behavior:

- Reads `rulesBegin` at `+0x14`.
- If non-null, performs the MSVC large-allocation header guard when the rounded capacity span is at least `0x1000`.
- Frees either the user pointer or the aligned-allocation base.
- Clears `+0x14/+0x18/+0x1c`.

Best source-shape inference: this is ordinary `FontStyle` destructor/vector cleanup, not MiniMap-owned code and not product-specific runtime behavior. The existing `ClearRules` name is a useful behavior label, but the caller mix is destructor-like: local scoped style objects plus unwind funclets. If implementation changes the source signature, prefer:

```cpp
FontStyle::~FontStyle();
```

Fallback if the supervisor wants to preserve the existing page title: keep the page title `FontStyleClearRules` but add that the source-facing method is probably `~FontStyle()` or a destructor-delegated private clear helper. Do not move it to MiniMap.

### `0x0049ac60` vector growth

Local export and current doc agree:

- IDA/Ghidra size: `0x114` / 276 bytes.
- Caller count: 1, from `0x00499f90`.
- Callees: capacity/error helper, allocator, `memmove`, invalid-parameter, and free helper.
- Decompile computes 16-byte record counts, grows capacity by about 1.5x, copies/moves records, frees the old allocation, and updates begin/end/capacity.

Conclusion: keep [UID:00011W] as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++. First-draft source should express this as `m_rules.push_back(rule)`, letting the compiler/library generate growth support.

## Rule Layout And Field Names

Recovered rule size is 16 bytes. StaticText2 and HelpPane consumer docs support stronger names than the current generic `firstValue/secondValue/selector/fourthValue` layout:

```cpp
struct FontStyleRule {
    unsigned int m_textColor;      // +0x00
    unsigned int m_textBackColor;  // +0x04, secondary/effect color
    unsigned char m_effect;        // +0x08, low byte only: 0 normal, 1 outlined, 3 shadowed
    unsigned char m_reserved[3];   // +0x09..+0x0b
    unsigned int m_textAlign;      // +0x0c
};
```

Evidence:

- `SimpleHelpTextPartPaneCore` says the draw-line helper consumes foreground color `+0x00`, secondary color `+0x04`, mode byte `+0x08`, and saved field `+0x0c`.
- B013 HelpPane reanalysis ties `+0x0c` to inherited `GrafPort::m_textAlign` / `+0x8c`.
- The low-byte-only write in `Configure` proves `+0x09..+0x0b` should remain padding/reserved in source, not named style fields.
- Effect values `0`, `1`, and `3` dispatch to normal, outlined, and shadowed text rendering.

Rejected rule names:

- `m_fontValue` for `+0x04`: weaker than the current StaticText/HelpPane consumer evidence. `m_textBackColor` or `m_secondaryColor` is better.
- `m_drawMode` for `+0x08`: acceptable, but `m_effect` better matches normal/outlined/shadowed dispatch.
- `m_extraStyle` for `+0x0c`: too generic after HelpPane evidence tied it to text alignment.
- Generated MiniMap labels `m_flags`, `m_bold`, `m_italic`, `m_color`, and `m_size`: reject as generated caller-side names, not class layout evidence.

## Object Fields

Recommended declaration-level fields:

```cpp
class FontStyle {
public:
    FontStyle();
    ~FontStyle();

    void GetRule(unsigned int index, FontStyleRule *outRule) const;
    void Configure(unsigned int textColor,
                   unsigned int textBackColor,
                   unsigned char effect,
                   unsigned int textAlign);

private:
    unsigned char m_enabled;      // +0x00
    unsigned char m_reserved0[3]; // +0x01..+0x03
    float m_paneOpacity;          // +0x04
    float m_textOpacity;          // +0x08
    unsigned int m_fillColor;     // +0x0c
    unsigned int m_frameColor;    // +0x10
    std::vector<FontStyleRule> m_rules; // +0x14/+0x18/+0x1c
};
```

Confidence details:

- `m_enabled` is strong: constructor sets it to `1`; HelpPane checks zero/non-zero.
- `m_paneOpacity` and `m_textOpacity` are medium-high: B013 HelpPane evidence uses `+0x04` for parent/base opacity and `+0x08` for child/text opacity. If the project prefers the current `inner/outer` naming, update the docs to state exact consumer direction instead of treating them as interchangeable.
- `m_fillColor` and `m_frameColor` are medium: HelpPane copies `FontStyle +0x0c/+0x10` to paint color fields, but exact historical names remain unproven. If the implementation callback wants lower-risk names, use `m_primaryColor` and `m_secondaryColor` with the HelpPane paint-color note.
- `m_rules` is strong: constructor, lookup, configure, cleanup, and growth all agree on a 12-byte vector triplet at `+0x14`.

## Ownership And Source Routing

Keep the existing route:

```text
00005C FontStyle -> 0000JI FontStyle.cpp -> auto-generated/NexusTK/ui/controls/FontStyle.cpp
```

Reasons:

- Constructor/configure callers are spread across MiniMap, NewMail, and HelpPane/static text controls.
- HelpPane is the strongest `GetRule` consumer, but it does not own construction/configuration.
- MiniMap and NewMail construct transient local style objects and pass them to static labels; they should not own the reusable type.
- StaticTextControlPane2 is a plausible physical-source fallback because it consumes the style records, but the current separate [UID:0000JI] `FontStyle.cpp` route is cleaner for documentation and already resolves autogen routing.
- `0x0049ac60` is generated vector support and should remain no-owner/non-emitting even though it is only called by `FontStyle::Configure`.

Rejected ownership alternatives:

- `MiniMapDialog`: rejected; it is a caller and cleanup/unwind host, not owner.
- `NewMailDialog`: rejected; it constructs one local style for a label.
- `HelpPane`: rejected; it embeds/copies a compatible style record and calls `GetRule`, but other construction/configuration users exist.
- `StaticTextControlPane2`: plausible fallback only if future header/source-order evidence proves `FontStyle` was local to static text controls. Current cross-feature fanout favors a small reusable support file.
- STL/vector helper ownership: rejected for the class and core methods; only `0x0049ac60` belongs in the ignored compiler/container support bucket.

## First-Draft C++ Readiness

The class target is ready for first-draft C++ after this report is accepted. Because this is a by-class page, the class C++ should be a declaration/type shell, not method bodies. Method bodies belong in the child memory pages.

Recommended class-level draft for `by-class/FontStyle.md`:

```cpp
#include <vector>

struct FontStyleRule {
    unsigned int m_textColor;
    unsigned int m_textBackColor;
    unsigned char m_effect;
    unsigned char m_reserved[3];
    unsigned int m_textAlign;
};

class FontStyle {
public:
    FontStyle();
    ~FontStyle();

    void GetRule(unsigned int index, FontStyleRule *outRule) const;
    void Configure(unsigned int textColor,
                   unsigned int textBackColor,
                   unsigned char effect,
                   unsigned int textAlign);

private:
    unsigned char m_enabled;
    unsigned char m_reserved0[3];
    float m_paneOpacity;
    float m_textOpacity;
    unsigned int m_fillColor;
    unsigned int m_frameColor;
    std::vector<FontStyleRule> m_rules;
};
```

Recommended method-level drafts for support pages:

```cpp
FontStyle::FontStyle()
    : m_enabled(1),
      m_paneOpacity(0.2f),
      m_textOpacity(0.2f),
      m_fillColor(1),
      m_frameColor(0x80)
{
}
```

```cpp
FontStyle::~FontStyle()
{
}
```

The empty destructor body is source-style intentional: the `std::vector<FontStyleRule>` member releases the backing storage after the destructor body. If the docs keep the `ClearRules` method name, do not emit raw heap/free code; preserve it as a destructor-like cleanup helper.

```cpp
void FontStyle::GetRule(unsigned int index, FontStyleRule *outRule) const
{
    if (index < m_rules.size()) {
        *outRule = m_rules[index];
    }
}
```

```cpp
void FontStyle::Configure(unsigned int textColor,
                          unsigned int textBackColor,
                          unsigned char effect,
                          unsigned int textAlign)
{
    FontStyleRule rule;
    rule.m_textColor = textColor;
    rule.m_textBackColor = textBackColor;
    rule.m_effect = effect;
    rule.m_textAlign = textAlign;
    m_rules.push_back(rule);
}
```

Implementation caveats:

- Do not emit `0x0049ac60` as a named method or helper.
- Do not emit `sub_5C7526` heap-free code in source.
- Do not explicitly assign `m_reserved` unless the validator/source style requires deterministic padding. The original code only proves the low byte at rule `+0x08`.
- Do not model `GetRule` with the decompiler's unstable return value.
- Keep declarations before child method bodies in generated `FontStyle.cpp`.

## Open Questions And Attempted Resolution

- Exact original source/header placement: best current route is standalone `NexusTK/ui/controls/FontStyle.cpp` with likely `FontStyle.h`. A private declaration inside `StaticTextControlPane.cpp` or `HelpPanes.cpp` remains possible, but weaker than the current separate file route and cross-feature fanout.
- Exact name of `0x00499f60`: `GetRule` is best because it copies an indexed style rule to caller storage and HelpPane asks for per-line rules. `GetStyleRule` or `CopyRule` are acceptable alternates; container-only naming is rejected.
- Exact name of `0x00499f90`: `Configure` is best for consistency with current docs. `AddRule`/`AddStyleRule` is semantically more explicit but not yet proven by caller source shape.
- Exact name of `0x004536e0`: best high-probability inference is `FontStyle::~FontStyle()` or compiler-emitted destructor cleanup. Existing `ClearRules` title can stay as a behavior/page name until the implementation callback decides whether to rename source-facing inventory.
- Exact names for `+0x0c/+0x10`: `m_fillColor`/`m_frameColor` best match HelpPane paint consumers, but `m_primaryColor`/`m_secondaryColor` are safer if the supervisor wants less semantic commitment.
- Exact historical spelling of `FontStyleRule`: no local IDA UDT records are available. `FontStyleRule` is still the best documentation type name because 16-byte records are produced by `FontStyle::Configure` and consumed by text rendering.

## Recommended Implementation Checklist

If the supervisor accepts this report, apply these changes in an implementation callback:

1. Update `by-class/FontStyle.md` metadata to `COMPLETION:87`, `CONFIDENCE:89`; keep `CANONICAL_OWNER:0000JI`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JI`.
2. Add the class-level `FontStyleRule` and `FontStyle` declaration draft to `by-class/FontStyle.md`.
3. Update `by-class/FontStyle.md` method table:
   - Rename `bounded rule lookup` to `GetRule` / `GetStyleRule`.
   - Change the source signature to `void GetRule(unsigned int index, FontStyleRule *outRule) const`.
   - Change `ClearRules` wording to "destructor-like cleanup, likely `~FontStyle()`; existing page title is behavior label".
4. Update `by-type/by-struct/FontStyleLayout.md`:
   - Replace generic rule slots with `m_textColor`, `m_textBackColor`/`m_secondaryColor`, `m_effect`, `m_reserved[3]`, and `m_textAlign`.
   - Add the consumer evidence from StaticText2 and HelpPane.
   - Replace `innerOpacityOrValue`/`outerOpacityOrValue` with `m_paneOpacity`/`m_textOpacity` or explicitly document the `+0x04` parent and `+0x08` text opacity direction.
   - Replace scalar style field notes with `m_fillColor`/`m_frameColor` as best current names, with `primary/secondary color` as conservative fallback.
5. Update `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`:
   - Add first-draft constructor, `GetRule`, and `Configure` C++.
   - Correct `GetRule` return handling: no meaningful source return; callers use copy side effect.
   - Keep `0x0049ac60` documented only as vector growth support emitted by `m_rules.push_back(rule)`.
6. Update `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`:
   - Add destructor-like source-shape evidence from normal local cleanup and EH unwind callers.
   - Prefer `FontStyle::~FontStyle()` as source-facing signature, or preserve `ClearRules` as behavior label if the page path is not renamed.
   - Do not emit manual heap/free code if the class declaration uses `std::vector<FontStyleRule>`.
7. Update `by-file/FontStyle.md`:
   - State that the generated file currently has the right route but only empty markers.
   - State that `FontStyle.cpp` should contain the declaration shell before child methods.
   - Keep the fallback note that a future header/source-order pass could fold declarations into StaticText/HelpPanes, but no current evidence requires moving ownership.
8. Leave `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md` metadata unchanged and non-emitting.
9. Update supervisor-owned coverage rows with the exact text below if score changes are accepted.
10. Run the validation commands listed in this report and inspect generated `FontStyle.cpp`.

## Score And Metadata Recommendation

Target class:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000JI
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JI
```

Rationale: class route, object layout, rule layout, field names, helper signatures, generated-output blocker, consumer evidence, and non-emitting vector support are now resolved enough for first-draft class C++. Confidence stays below final-audit levels because exact historical names for the file/header, `Configure`, destructor/clear helper, and two root scalar color fields remain inferred.

Support recommendations:

- `by-file/FontStyle.md`: raise to `86/89` after adding the declaration-shell/source-route notes.
- `by-type/by-struct/FontStyleLayout.md`: raise to `86/91` after updating rule-field names and scalar direction notes.
- `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`: raise to `86/91` after adding first-draft method C++ and fixing `GetRule` return semantics.
- `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`: raise to `87/92` only if the destructor-like source-shape note is accepted.
- `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`: keep `85/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank C++.

## Exact Coverage Text

Do not edit coverage reports during this B-agent report-only pass.

Exact replacement row for `by-class/-coverage-report.md`:

```text
- [UID:00005C][FontStyle](by-class/FontStyle.md) : reconstructable : 87% : strong : B012 source-quality pass resolves the FontStyle class as reusable text-style support routed through FontStyle.cpp, stages a 0x20-byte std::vector-backed declaration, refines FontStyleRule fields to text color, secondary/back color, effect byte, and text alignment, treats 0x00499f60 as a void GetRule-style copy helper, identifies 0x004536e0 as destructor-like vector cleanup, rejects MiniMap/NewMail/HelpPane ownership and generated MiniMap field names, and keeps 0x0049ac60 as non-emitting vector-growth support.
```

Exact replacement row for `by-file/-coverage-report.md`:

```text
- [UID:0000JI][FontStyle](by-file/FontStyle.md) : reconstructable : 86% : strong : B012 source-quality pass keeps FontStyle.cpp under NexusTK/ui/controls as reusable text-style support, not MiniMap/NewMail/HelpPane ownership; current generated FontStyle.cpp is empty-marker only until the FontStyleRule/class declaration shell and child method C++ are staged; 0x0049ac60 remains ignored compiler vector growth.
```

Exact replacement row for `by-type/by-struct/-coverage-report.md`:

```text
- [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md) : reconstructable : 86% : strong : B012 source-quality pass keeps the 0x20-byte FontStyle layout and 16-byte vector rule stride, refines rule fields to textColor/textBackColor/effect/reserved/textAlign based on StaticText2 and HelpPane consumers, recommends pane/text opacity and fill/frame color scalar names with caveats, and preserves std::vector triplet/growth/cleanup evidence.
```

Exact replacement row for `by-memory/-coverage-report.md` for [UID:00011T]:

```text
    - [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md) : reconstructable : 86% : strong : B012 class-level source-quality pass refines the core as FontStyle constructor, void GetRule-style bounded OWORD copy, and Configure/AddRule rule append cluster; C++ should use textColor/textBackColor/effect/textAlign rule fields and std::vector push_back; owner/emitter remain [UID:00005C]; MiniMap/NewMail/HelpPane ownership and container-only GetRule interpretation are rejected; 0x0049ac60 remains ignored vector-growth support.
```

Exact replacement row for `by-memory/-coverage-report.md` for [UID:0000XM] if the destructor-like source-shape update is accepted:

```text
    - [UID:0000XM][0x004536e0-0x00453732.FontStyleClearRules](by-memory/0x004536e0-0x00453732.FontStyleClearRules.md) 0x004536e0-0x00453732 | method | FontStyle destructor-like cleanup : reconstructable : 87% : strong : B012 source-quality pass confirms the FontStyle rule-vector triplet cleanup at +0x14/+0x18/+0x1c, free/invalid-parameter callees, normal local-style cleanup plus EH unwind callers, and recommends source-facing treatment as FontStyle::~FontStyle or destructor-delegated ClearRules rather than MiniMap-owned code; owner/emitter stay [UID:00005C].
```

No replacement is recommended for [UID:00011W]; keep the existing ignored/non-reconstructable row.

Expected regenerated project stats rows after accepted edits:

```text
| `00005C` | 87 | 89 | 88.0 | `by-class/FontStyle.md` |
| `0000JI` | 86 | 89 | 87.5 | `by-file/FontStyle.md` |
| `0001UN` | 86 | 91 | 88.5 | `by-type/by-struct/FontStyleLayout.md` |
| `00011T` | 86 | 91 | 88.5 | `by-memory/0x00499f10-0x00499fda.FontStyleCore.md` |
| `0000XM` | 87 | 92 | 89.5 | `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md` |
```

## Validation Commands After Implementation

From `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00005C-FontStyle-class-source-quality-removed.md](00005C-FontStyle-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected results:

- All file-level validator runs should report the requested UID ok.
- Autogen should regenerate `auto-generated/NexusTK/ui/controls/FontStyle.cpp`.
- Generated `FontStyle.cpp` should contain `FontStyleRule` and `FontStyle` declarations before child method bodies.
- Generated `FontStyle.cpp` should not contain a named/trampolined `sub_49AC60` body or manual heap-free helper for rule-vector growth.
- Generated `GetRule` should be void-copy source shape, not a bogus mixed return contract.

## IDA Rename, Type, And Comment Recommendations

High confidence:

- Rename `sub_499F10` to `FontStyle::FontStyle`.
- Rename `sub_499F60` to `FontStyle::GetRule` or `FontStyle::GetStyleRule`.
- Rename `sub_499F90` to `FontStyle::Configure`; `AddRule` is a valid alternate only if later caller-source naming supports it.
- Type `FontStyle` size as 0x20 bytes with vector triplet at `+0x14/+0x18/+0x1c`.
- Type `FontStyleRule` size as 16 bytes with fields `textColor`, `textBackColor`/`secondaryColor`, `effect`, padding, and `textAlign`.
- Comment `sub_499F60`: "copies selected 16-byte rule if index is in range; return register is not source-significant."
- Comment `sub_499F90`: "builds a FontStyleRule and appends it; low byte only at rule +0x08."
- Comment `sub_49AC60`: "compiler/container vector growth for FontStyleRule; single caller from FontStyle::Configure; do not emit as project method."

Medium-high confidence:

- Rename `sub_4536E0` to `FontStyle::~FontStyle` if the implementation callback accepts destructor-like source shape. Otherwise keep `FontStyle::ClearRules` with a repeatable comment: "destructor-like vector storage cleanup; normal callers are local cleanup/unwind paths."
- Name root scalar fields as `m_paneOpacity`, `m_textOpacity`, `m_fillColor`, and `m_frameColor`; use `m_primaryColor`/`m_secondaryColor` if a lower-commitment naming policy is preferred.

Rejected IDA/source actions:

- Do not type `0x00499f60` as container-only support.
- Do not keep generated MiniMap field names as shared `FontStyle` fields.
- Do not assign [UID:00011W] `0x0049ac60` to `FontStyle` as source-emitting code.
- Do not move the class under MiniMap, NewMail, or HelpPane ownership.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00005C-FontStyle-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00005C"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00005C-FontStyle-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/00005C-FontStyle-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00005C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
