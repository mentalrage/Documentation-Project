** TARGET-REPORT-UID:00011T **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00011T FontStyleCore Source-Quality Refresh

Status: FINISHED

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00011T] as the source-authored `FontStyle` method cluster, owned by [UID:00005C] `FontStyle` and emitted through [UID:00005C] into [UID:0000JI] `FontStyle.cpp`.
- Final disposition: no split required for this implementation pass; update source-facing names, field/type names, score rationale, and first-draft C++.
- Required action: in the implementation callback, update the target, `FontStyle` class/file/layout support pages, and the destructor-like cleanup support page; do not edit `by-memory/-coverage-report.md`.
- Confidence: high for owner/emitter/range/function behavior; medium-high for final historical field spelling.

## Target

- Target UID: `00011T`
- Target path: `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00005C`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005C`.
- Current generated route: `auto-generated/NexusTK/ui/controls/FontStyle.cpp` via `00011T -> 00005C -> 0000JI`.
- Current generated output state: `auto-generated/NexusTK/ui/controls/FontStyle.cpp` contains only empty emitter markers for `00005C`, `0000XM`, `00011T`, and `0001UN`.

## Executive Recommendation

Keep the target as a compact same-owner method cluster:

| Range | Source-facing role | Recommendation |
| --- | --- | --- |
| `0x00499f10-0x00499f51` | `FontStyle::FontStyle()` | Emit constructor C++ after class declaration shell exists. |
| `0x00499f60-0x00499f85` | `void FontStyle::GetRule(unsigned int index, FontStyleRule *outRule) const` | Correct old count-return wording; source contract is side-effect copy. |
| `0x00499f90-0x00499fda` | `void FontStyle::Configure(unsigned int textColor, unsigned int textBackColor, unsigned char effect, unsigned int textAlign)` | Emit append code as `m_rules.push_back(rule)`. |

Raise [UID:00011T] to:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:00005C
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005C
```

The support pages should also be updated so the generated `FontStyle.cpp` has a declaration shell before method bodies. The target is C++ ready only as part of that combined implementation: class/type declarations must precede this target's method definitions.

## Supervisor Active Recheck

- Assignment: refresh/rework existing pending B006 report for [UID:00011T] `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`.
- Scope honored: this pass edited only this B006 report. No target/support `by-*` page and no `by-memory/-coverage-report.md` page was edited.
- Required report standard checked: no arbitrary detail cap; target/support docs, generated coverage/stats, current generated output, unresolved-name reports, B012/B013 related reports, and direct executable bytes were reviewed.
- Split requirement: checked. No split is recommended now because the three modeled functions share one class owner, one emitter route, one tight source-family purpose, and no mixed owner or generated-output pollution. If future policy requires one method per `by-memory` page, the safe future child ranges are `0x00499f10-0x00499f51`, `0x00499f60-0x00499f85`, and `0x00499f90-0x00499fda`, with the `0xcc` gaps kept as padding.

## Evidence Standards Used

Evidence types used:

- Current target/support docs under `project-documentation`.
- Current generated coverage/status reports: `auto-generated/-ag-memory-coverage.md`, `-ag-class-coverage.md`, `-ag-file-coverage.md`, `-ag-type-coverage.md`, and `project-level/-auto-completion-stats.md`.
- Current generated `auto-generated/NexusTK/ui/controls/FontStyle.cpp`.
- Related B-agent reports: B012 `00005C-FontStyle-class-source-quality.md` and B013 `000064-HelpPane__SimpleHelpTextPartPane-source-quality.md`.
- Direct PE byte/disassembly check against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` using Capstone. The IDA MCP endpoint at `http://127.0.0.1:13337/mcp` was not reachable in this session.
- Current docs already contain live IDA MCP evidence from 2026-06-05 through 2026-06-19; this report revalidated the critical byte-level points rather than collecting fresh IDA facts.

Evidence strength:

- Function ranges, direct `call rel32` caller sites, padding gaps, and `GetRule` register behavior are direct binary facts from this pass.
- Caller ownership, source module routing, and consumer field semantics are current documentation evidence, strengthened by B012/B013 reports and direct disassembly of the style-consumer helpers.
- Original source file/header names and exact member spelling remain inferred/descriptive because no PDB/source UDT metadata is available and MCP was offline.

## Direct Binary / Capstone Facts

Direct PE disassembly from `NexusTK.exe`, image base `0x00400000`, confirms:

### Constructor `0x00499f10-0x00499f51`

- Function is 65 bytes.
- Writes `rulesBegin`, `rulesEnd`, and `rulesCapacity` at `+0x14/+0x18/+0x1c` to zero.
- Sets byte `[this+0x00]` to `1`.
- Sets `[this+0x08]` and `[this+0x04]` to `0x3e4ccccd` (`0.2f`).
- Sets `[this+0x0c]` to `1`.
- Sets `[this+0x10]` to `0x80`.
- Returns `this` in `eax`.

### Bounded rule copy `0x00499f60-0x00499f85`

The exact instruction pattern is:

```asm
00499f63  mov eax, [ecx+0x18]
00499f66  mov edx, [ecx+0x14]
00499f69  sub eax, edx
00499f6b  mov ecx, [ebp+0x08]     ; index
00499f6e  sar eax, 4              ; count
00499f71  cmp ecx, eax
00499f73  jae 0x00499f81
00499f75  mov eax, [ebp+0x0c]     ; outRule
00499f78  add ecx, ecx
00499f7a  movups xmm0, [edx+ecx*8]
00499f7e  movups [eax], xmm0
00499f81  pop ebp
00499f82  ret 8
```

This closes the old report's main error. The raw function is not a coherent count-returning source method: on the out-of-range path `eax` remains count-like, while on the copy path `eax` becomes the output buffer pointer. Both known callers ignore the return register and use only the side effect. The best source-facing signature is therefore `void FontStyle::GetRule(unsigned int index, FontStyleRule *outRule) const`.

### Configure / append `0x00499f90-0x00499fda`

- Builds a 16-byte stack record at `[ebp-0x10..ebp-0x04]`.
- Stores argument 1 at `+0x00`.
- Stores argument 2 at `+0x04`.
- Stores only the low byte of argument 3 at `+0x08`; bytes `+0x09..+0x0b` are not source-proven fields.
- Stores argument 4 at `+0x0c`.
- Uses inline OWORD copy when `rulesEnd != rulesCapacity`.
- Calls `0x0049ac60` only on the full-vector path.

### Padding and caller fan-out

Direct byte checks confirm:

- `0x00499f51-0x00499f60`: fifteen `0xcc` bytes.
- `0x00499f85-0x00499f90`: eleven `0xcc` bytes.
- `0x00499fda-0x00499fe0`: six `0xcc` bytes.

Direct `call rel32` scan in `.text` found:

| Target | Direct call sites |
| --- | --- |
| `0x00499f10` constructor | `0x00450e3e`, `0x00451f32`, `0x00452408`, `0x00452887`, `0x00452ad2`, `0x0047d0d2`, `0x004c69d2` |
| `0x00499f60` GetRule | `0x004c6723`, `0x004c67b3` |
| `0x00499f90` Configure | `0x00450f22`, `0x00451f74`, `0x00451f8d`, `0x004528be`, `0x00452b09`, `0x00452c2b`, `0x0047d3fa` |
| `0x004536e0` cleanup | `0x0045214a`, `0x00452be3` |
| `0x0049ac60` vector growth | `0x00499fcf` |

## Documentation Evidence Revalidated

Target/support docs read and rechecked:

- `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`
- `by-class/FontStyle.md`
- `by-file/FontStyle.md`
- `by-type/by-struct/FontStyleLayout.md`
- `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`
- `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`
- `by-memory/0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore.md`
- `by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md`
- `by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md`
- `by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md`
- `by-class/StaticTextControlPane2.md`
- `by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md`
- `by-class/HelpPane.md`
- `by-class/HelpPane__SimpleHelpTextPartPane.md`
- `by-class/MiniMapDialog.md`
- `by-class/NewMailDialog.md`
- `by-file/HelpPanes.md`, `by-file/MiniMap.md`, and `by-file/MailDialogs.md` as source-route support.

Important current facts:

- `FontStyleLayout` is already `85/90`, owner/emitter [UID:00005C], and records live IDA evidence for constructor defaults, vector triplet, 16-byte lookup/append stride, cleanup reset, and vector growth.
- `FontStyle.cpp` is already a valid by-file generated root under `NexusTK/ui/controls/`, but generated output is empty-marker only.
- `FontStyleRuleVectorGrowth` is already `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and documents one caller from `FontStyle::Configure`.
- `SimpleHelpTextPartPaneCore`, `StaticTextControlPane2__SimpleHelpTextPartPane`, and B013's HelpPane text-part report prove both the StaticText2 and HelpPane styled text paths consume rule `+0x00/+0x04/+0x08/+0x0c` as text color, text back/secondary color, effect byte, and text alignment.
- `HelpPaneCore`, `HelpPaneFadeStateUpdate`, and `HelpPane` pages prove the root `FontStyle` object header is copied into HelpPane style state: enabled byte, base/pane opacity, child/text opacity, fill/frame color sources, borrowed child style pointer, and vector rule storage.

## Heuristic / Inference Reanalysis And Validation

### Issue: source-facing name for `0x00499f60`

- Accepted name: `FontStyle::GetRule`.
- Accepted signature: `void FontStyle::GetRule(unsigned int index, FontStyleRule *outRule) const`.
- Evidence: direct bytes show out-of-range leaves a count-like `eax`, in-range changes `eax` to `outRule`, and both callers ignore the return value before calling `DrawStyledTextSegment`.
- Rejected: `unsigned int GetRule(...)` because the in-range return is not the count.
- Rejected: `bool GetRule(...)` because the function does not normalize success/failure.
- Rejected: `FontStyleRule *GetRule(...)` because out-of-range does not return a pointer contract.
- Rejected: `operator[]` because the body tolerates out-of-range and copies to caller storage.
- Accepted alternate spelling: `GetStyleRule` or `CopyRule` only if a later source-name pass standardizes that wording; current docs already use `GetRule`.

### Issue: source-facing name for `0x00499f90`

- Accepted name: `FontStyle::Configure`.
- Evidence: current docs and caller prose use `Configure`; call sites configure local text styles for MiniMap and NewMail labels before passing them to StaticText2.
- Semantically clearer alternate: `AddRule` or `AddStyleRule`.
- Rejected as primary now: `AppendRule`, because current source route and docs already use `Configure` and callers are style setup, not generic container manipulation.
- Rejected: `SetFontStyle`, because the function appends a rule record rather than replacing object-wide state.

### Issue: `FontStyleRule` fields

Accepted first-draft declaration:

```cpp
struct FontStyleRule {
    unsigned int m_textColor;
    unsigned int m_textBackColor;
    unsigned char m_effect;
    unsigned char m_reserved[3];
    unsigned int m_textAlign;
};
```

Evidence:

- `Configure` writes first argument at rule `+0x00`, second at `+0x04`, third low byte at `+0x08`, and fourth at `+0x0c`.
- `HelpPane::SimpleHelpTextPartPane::DrawStyledTextSegment` and `StaticTextControlPane2::SimpleHelpTextPartPane::DrawTextLine` copy rule `+0x0c` into `GrafPort +0x8c` before drawing; B013 resolves that inherited field as text alignment.
- The same draw helpers pass rule `+0x00` to the text-color setter, rule `+0x04` to the text-back/secondary color setter, and dispatch rule byte `+0x08` values `0`, `1`, and `3` to normal, outlined, and shadowed text paths.
- The high three bytes after `m_effect` are not written by source-visible code and should stay padding/reserved.

Rejected names:

- Old B006 `m_fontValue` for `+0x04`: weaker than the current consumer evidence; `m_textBackColor` or `m_secondaryColor` is better.
- Old B006 `m_drawMode` for `+0x08`: acceptable descriptive fallback, but `m_effect` better captures normal/outlined/shadowed behavior.
- Old B006 `m_extraStyle` for `+0x0c`: too generic after text alignment evidence.
- Generated MiniMap names such as `m_flags`, `m_bold`, `m_italic`, `m_color`, and `m_size`: rejected as generated/caller-local artifacts.

### Issue: `FontStyle` root fields

Accepted first-draft declaration fields:

```cpp
unsigned char m_enabled;      // +0x00
unsigned char m_reserved0[3]; // +0x01..+0x03
float m_paneOpacity;          // +0x04
float m_textOpacity;          // +0x08
unsigned int m_fillColor;     // +0x0c
unsigned int m_frameColor;    // +0x10
std::vector<FontStyleRule> m_rules; // +0x14/+0x18/+0x1c
```

Evidence:

- `m_enabled`: constructor sets byte `+0x00` to `1`; HelpPane and text-part helpers gate style state on this byte.
- `m_paneOpacity`: HelpPane style-state docs use copied style `+0x04` as the base/pane opacity.
- `m_textOpacity`: HelpPane text-part docs use copied style `+0x08` as child/text opacity.
- `m_fillColor` and `m_frameColor`: HelpPane copies style fields corresponding to root `+0x0c/+0x10` into fill/frame paint fields consumed by `HelpPane::OnPaintFrame`.
- `m_rules`: constructor, lookup, configure, cleanup, and vector growth all agree on the `+0x14/+0x18/+0x1c` vector triplet.

Remaining caveat:

- `m_fillColor`/`m_frameColor` are medium-confidence source names. If the implementation callback wants lower semantic commitment, use `m_primaryColor`/`m_secondaryColor` in code and document the HelpPane fill/frame evidence in prose. I recommend `m_fillColor`/`m_frameColor` because current HelpPane docs now provide direct consumer evidence.

### Issue: cleanup helper source shape

- Best source-facing interpretation: `FontStyle::~FontStyle()` or destructor-delegated rule-vector cleanup.
- Existing page title `FontStyleClearRules` can remain as a behavior label, but support docs should state the source-facing method is destructor-like.
- Evidence: direct normal callers are MiniMap local-style cleanup/unwind sites, docs record additional EH/unwind xrefs, and the body only releases the `std::vector<FontStyleRule>`-like triplet with MSVC allocation guard behavior.
- Rejected: MiniMap ownership, because the same style object is constructed/configured by NewMail and HelpPane/static text contexts.
- Rejected: manual heap/free source in first-draft C++, because a `std::vector<FontStyleRule>` member should generate the observed storage cleanup.

### Issue: `0x0049ac60` source/emitter treatment

- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++.
- Evidence: one caller at `0x00499fcf`, allocator/memmove/free/invalid-parameter callees, 16-byte vector growth/move/copy logic, and existing ignored/support docs.
- Source expression: `m_rules.push_back(rule)`.
- Rejected: assigning it to `FontStyle` as a source-emitting helper; that would leak compiler/container support into project code.

### Issue: owner/source placement

Keep:

```text
00011T -> 00005C FontStyle -> 0000JI FontStyle.cpp -> auto-generated/NexusTK/ui/controls/FontStyle.cpp
```

Accepted source path: `NexusTK/ui/controls/FontStyle.cpp`.

Evidence:

- Constructor/configure callers span MiniMap, NewMail, and HelpPane/static text contexts.
- HelpPane is the only known `GetRule` caller family, but it is not the only constructor/configure user.
- MiniMap and NewMail construct transient local styles for labels.
- StaticTextControlPane2 and HelpPane consume the style records but do not own the reusable style descriptor.
- The proposed source tree already lists `FontStyle.cpp` under `ui/controls`, and current generated file routing is valid.

Rejected owners:

- `MiniMapDialog` / [UID:0000LE] `MiniMap`: consumer only; local style setup and cleanup do not prove ownership.
- `NewMailDialog` / [UID:0000KZ] `MailDialogs`: consumer only; one EPF label path.
- `HelpPane` / [UID:0000JU] `HelpPanes`: important consumer, but not the source owner for all construction/configuration.
- `StaticTextControlPane2`: plausible physical-source fallback, but weaker than the current reusable `FontStyle.cpp` route and cross-feature fanout.
- STL/vector helper owner: applies only to `0x0049ac60`, not to this source-authored cluster.

### Issue: split/range

- No split now.
- The page covers three exact source-facing methods and only alignment gaps.
- All three methods share the same owner/emitter and source-facing declaration context.
- No child has a different owner, different reconstruction class, or generated-output treatment.
- Future optional method split ranges are listed above, but implementing a split now would create UID churn without improving ownership, routing, or C++ readiness.

### Issue: stale unresolved/compiler names

- `project-level/-unresolved.md` still flags `sub_499F60` only in stale `by-memory/-report.old.md`.
- Current target/support pages already use source-facing wording for the live docs.
- Implementation should add IDA rename/comment recommendations but does not need to update stale old report material during this pass.

## Ranked Ownership Analysis

### 1. [UID:00005C] FontStyle, emitted through [UID:0000JI] FontStyle.cpp

- Evidence for: exact target functions operate on the 0x20-byte `FontStyle` layout; class/file/type docs already meet gate; direct callers span multiple UI features; generated output route is live.
- Evidence against: exact historical source/header placement is not proven by PDB/source metadata; standalone `FontStyle.cpp` could still be a documentation-friendly split rather than original physical file.
- Decision: accepted.

### 2. StaticTextControlPane2 / StaticTextControlPane.cpp

- Evidence for: StaticText2 consumes rule records and lies immediately after the target in memory.
- Evidence against: NewMail, MiniMap, and HelpPane use the style type across feature boundaries; HelpPane owns a separate text-part consumer; current by-file route is already valid.
- Decision: rejected as current owner; keep as plausible physical-source fallback in support docs.

### 3. HelpPanes.cpp

- Evidence for: HelpPane draw path directly calls `GetRule`, and HelpPane copies a full compatible style block.
- Evidence against: HelpPane does not own constructor/configure call fan-out; moving `FontStyle` under HelpPane would hide MiniMap/NewMail/static text usage.
- Decision: rejected.

### 4. MiniMap or MailDialogs

- Evidence for: MiniMap and NewMail configure concrete local styles with visible argument values.
- Evidence against: both are consumers creating transient label styles; neither owns the reusable descriptor or text rendering semantics.
- Decision: rejected.

### 5. Compiler/container support

- Evidence for: `0x0049ac60` is vector growth support and has one caller from `Configure`.
- Evidence against: constructor, `GetRule`, and `Configure` are source-facing `FontStyle` methods, not pure STL helper bodies.
- Decision: accepted only for [UID:00011W], rejected for [UID:00011T].

## First-Draft C++ Recommendation

Prerequisite: insert the class declaration shell into [UID:00005C] before this target's method bodies. Then populate [UID:00011T]'s formal C++ with:

```cpp
FontStyle::FontStyle()
    : m_enabled(1),
      m_paneOpacity(0.2f),
      m_textOpacity(0.2f),
      m_fillColor(1),
      m_frameColor(0x80)
{
}

void FontStyle::GetRule(unsigned int index, FontStyleRule *outRule) const
{
    if (index < m_rules.size()) {
        *outRule = m_rules[index];
    }
}

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

C++ caveats:

- Do not return a count from `GetRule`.
- Do not add a null-check for `outRule`; no such check exists in the target bytes.
- Do not initialize `FontStyleRule::m_reserved`; the original stack record leaves the high three bytes after the effect byte as unproven padding.
- Do not emit `0x0049ac60`; `m_rules.push_back(rule)` is the source-level representation.
- Do not emit heap/free code from `0x005c7526` in this target.
- Use `unsigned int` and `unsigned char`, not modern fixed-width typedefs, unless the surrounding generated source standardizes those typedefs later.

## Recommended Support-Doc Changes

### `by-class/FontStyle.md`

Recommended metadata after implementation:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000JI
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JI
```

Add class-level formal C++:

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

Body edits:

- Add a declaration/source-shape section explaining that method bodies emit from `00011T` and destructor-like cleanup from `0000XM`.
- Rename the method table row from generic "bounded rule lookup" to `GetRule`.
- State that `GetRule` has a void source contract; raw return register is not source-significant.
- State that `ClearRules` is a behavior/page label and the likely source-facing method is `~FontStyle()` or destructor-delegated cleanup.
- Add rejected alternatives: generated MiniMap field names, count-returning `GetRule`, MiniMap/NewMail/HelpPane ownership, and source-emitting vector growth.

### `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:00005C
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005C
```

Body edits:

- Add first-draft C++ exactly as shown above.
- Replace the old "returns the count" wording for `0x00499f60` with: computes the count only for the bounds test; copies one 16-byte rule when in range; callers ignore return; out-of-range leaves output unchanged.
- Replace generic parameter names with `textColor`, `textBackColor`, `effect`, and `textAlign`.
- Preserve boundary/padding notes and direct caller inventory.
- Add direct binary evidence note for the mixed `eax` return behavior.
- Keep no-split decision and exact optional future split ranges.

### `by-type/by-struct/FontStyleLayout.md`

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:00005C
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005C
```

Body edits:

- Replace generic root fields with `m_enabled`, `m_paneOpacity`, `m_textOpacity`, `m_fillColor`, `m_frameColor`, and `m_rules`, while marking exact historical spelling as inferred/descriptive.
- Replace rule fields with `m_textColor`, `m_textBackColor`/accepted fallback `m_secondaryColor`, `m_effect`, `m_reserved[3]`, and `m_textAlign`.
- Add consumer evidence from `HelpPane::SimpleHelpTextPartPane::DrawStyledTextSegment` and `StaticTextControlPane2::SimpleHelpTextPartPane::DrawTextLine`.
- In formal C++, emit only a comment to avoid duplicate declarations after [UID:00005C] emits the shell:

```cpp
// FontStyle layout is emitted by UID:00005C FontStyle; this page documents the recovered offsets.
```

### `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`

Recommended metadata if updated:

```text
COMPLETION:87
CONFIDENCE:92
CANONICAL_OWNER:00005C
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005C
```

Body edits:

- Keep filename/page title for continuity, but update source-facing role to destructor-like `FontStyle::~FontStyle()` or destructor-delegated vector cleanup.
- Add caller evidence: direct normal cleanup sites are local scoped-style cleanup/unwind contexts; additional xrefs are EH/unwind metadata.
- Add C++ policy: do not emit manual heap/free code; with `std::vector<FontStyleRule>`, source C++ should be the ordinary destructor shape.
- If formal C++ is populated, use:

```cpp
FontStyle::~FontStyle()
{
}
```

### `by-file/FontStyle.md`

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:89
PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"
CANONICAL_OWNER:FILE
```

Body edits:

- State that generated `FontStyle.cpp` currently routes correctly but is empty-marker only.
- State that the file should contain the `FontStyleRule`/`FontStyle` declaration shell before child method bodies.
- Preserve `FontStyle.h` as likely historical header, with fallback that declarations may be folded into the generated `.cpp` until header emission exists.
- Keep StaticTextControlPane2/HelpPanes as plausible physical-source fallback only, not current owner.

### `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`

Recommended metadata: no change.

Keep:

```text
COMPLETION:85
CONFIDENCE:90
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Optional body/coverage sync only:

- Ensure the page and coverage row both say this is compiler/template vector growth for `FontStyleRule` and not source-emitting code.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` during report-only work.

Exact replacement row for `by-memory/-coverage-report.md` [UID:00011T]:

```text
    - [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md) : reconstructable : 86% : strong : B006 refreshed source-quality pass resolves the core as FontStyle constructor, void GetRule-style bounded rule copy, and Configure rule append cluster; first-draft C++ should use FontStyleRule textColor/textBackColor/effect/textAlign fields and std::vector push_back; owner/emitter remain [UID:00005C]; MiniMap/NewMail/HelpPane ownership, count-returning GetRule, generated MiniMap field names, and container-only interpretation are rejected; no split is needed; 0x0049ac60 remains ignored vector-growth support.
```

Exact replacement row for `by-memory/-coverage-report.md` [UID:0000XM], if destructor-like support update is accepted:

```text
    - [UID:0000XM][0x004536e0-0x00453732.FontStyleClearRules](by-memory/0x004536e0-0x00453732.FontStyleClearRules.md) 0x004536e0-0x00453732 | method | FontStyle destructor-like cleanup : reconstructable : 87% : strong : B006 refreshed FontStyle source-quality pass confirms the rule-vector triplet cleanup at +0x14/+0x18/+0x1c, free/invalid-parameter callees, normal local-style cleanup plus EH/unwind caller context, and recommends source-facing treatment as FontStyle::~FontStyle or destructor-delegated ClearRules rather than MiniMap-owned code; owner/emitter stay [UID:00005C] and formal C++ should avoid manual heap/free code.
```

Exact replacement row for `by-memory/-coverage-report.md` [UID:00011W], to sync the stale coverage row with current support metadata:

```text
    - [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) : ignored : 85% : strong : Current FontStyle source-quality evidence keeps sub_49AC60 as compiler/template vector growth for 16-byte FontStyleRule records, with exact 0x114-byte boundary, 0xcc trailing padding, one caller at 0x00499fcf from FontStyle::Configure, allocator/memmove/free/invalid-parameter callees, and no NexusTK source-emitting owner; source should express this as m_rules.push_back(rule).
```

Exact replacement row for `by-class/-coverage-report.md`:

```text
- [UID:00005C][FontStyle](by-class/FontStyle.md) : reconstructable : 87% : strong : B006 refreshed source-quality pass keeps FontStyle as reusable UI text-style support routed through FontStyle.cpp, stages a 0x20-byte std::vector-backed declaration, refines FontStyleRule fields to text color, text back/secondary color, effect byte, reserved padding, and text alignment, treats 0x00499f60 as a void GetRule-style copy helper, identifies 0x004536e0 as destructor-like vector cleanup, rejects MiniMap/NewMail/HelpPane ownership and generated MiniMap field names, and keeps 0x0049ac60 as non-emitting vector-growth support.
```

Exact replacement row for `by-file/-coverage-report.md`:

```text
- [UID:0000JI][FontStyle](by-file/FontStyle.md) : reconstructable : 86% : strong : B006 refreshed source-quality pass keeps FontStyle.cpp under NexusTK/ui/controls as reusable text-style support, not MiniMap/NewMail/HelpPane ownership; generated FontStyle.cpp should contain the FontStyleRule/class declaration shell before child method bodies, while 0x0049ac60 remains ignored compiler vector growth represented by std::vector push_back.
```

Exact replacement row for `by-type/by-struct/-coverage-report.md`:

```text
- [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md) : reconstructable : 86% : strong : B006 refreshed source-quality pass keeps the 0x20-byte FontStyle layout and 16-byte rule stride, refines rule fields to textColor/textBackColor/effect/reserved/textAlign from StaticText2 and HelpPane consumers, recommends pane/text opacity and fill/frame color scalar names with caveats, and preserves std::vector triplet/growth/cleanup evidence.
```

Expected regenerated project stats after accepted edits:

```text
| `00005C` | 87 | 89 | 88.0 | `by-class/FontStyle.md` |
| `0000JI` | 86 | 89 | 87.5 | `by-file/FontStyle.md` |
| `0001UN` | 86 | 91 | 88.5 | `by-type/by-struct/FontStyleLayout.md` |
| `00011T` | 86 | 91 | 88.5 | `by-memory/0x00499f10-0x00499fda.FontStyleCore.md` |
| `0000XM` | 87 | 92 | 89.5 | `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md` |
```

## Implementation Checklist For Callback

1. Lease the implementation docs before editing: `by-class/FontStyle.md`, `by-file/FontStyle.md`, `by-type/by-struct/FontStyleLayout.md`, `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`, and `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md`. Lease `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md` only if adding an optional coverage-sync note.
2. Do not lease or edit `by-memory/-coverage-report.md`; leave the exact replacement rows above for the supervisor.
3. Update `by-class/FontStyle.md` metadata to `87/89`; keep owner/emitter route. Add the declaration C++ block exactly as recommended.
4. Update `by-class/FontStyle.md` prose: method table `GetRule`, void-copy return rationale, destructor-like cleanup note, rejected MiniMap/NewMail/HelpPane ownership, rejected generated MiniMap field names, and `0x0049ac60` non-emitting policy.
5. Update `by-memory/0x00499f10-0x00499fda.FontStyleCore.md` metadata to `86/91`. Add first-draft constructor/GetRule/Configure C++. Correct all return-count wording for `0x00499f60`.
6. Update `FontStyleCore` field/parameter names to `textColor`, `textBackColor`, `effect`, and `textAlign`; preserve padding and caller evidence.
7. Update `by-type/by-struct/FontStyleLayout.md` metadata to `86/91`. Replace generic field names and add consumer evidence from HelpPane and StaticText2. Put only the one-line formal C++ comment to avoid duplicate declarations.
8. Update `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md` metadata to `87/92` only if the destructor-like source-shape note and empty destructor C++ are added. Do not emit manual heap/free code.
9. Update `by-file/FontStyle.md` metadata to `86/89`. Add generated-output route note, declaration-shell requirement, header/source fallback, and ownership rejection summary.
10. Leave `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md` metadata unchanged. If touched, only sync prose that source emits `m_rules.push_back(rule)`.
11. After file validators, inspect regenerated `auto-generated/NexusTK/ui/controls/FontStyle.cpp`; it should contain declaration shell, destructor, constructor, void `GetRule`, and `Configure`, and no source-emitted `sub_49AC60`.
12. Report changed files, lease use, validator exit codes/ok counts, generated-output inspection result, and supervisor-owned coverage rows left pending.

## Validator Commands After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00011T-FontStyleCore-source-quality-removed.md](00011T-FontStyleCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `00011W` is not edited during implementation, its file validator can be omitted; keep the supervisor-owned coverage row update in the callback report.

Manual generated-output checks:

- `auto-generated/NexusTK/ui/controls/FontStyle.cpp` has declaration shell before method definitions.
- `FontStyle::GetRule` is void and caller-side copy oriented.
- `FontStyle::Configure` emits `m_rules.push_back(rule)`.
- No generated source body or wrapper appears for `0x0049ac60` / `sub_49AC60`.
- No manual `sub_5C7526` heap-free code is emitted from the target.

## IDA Rename / Type / Comment Recommendations

High confidence:

- Rename `sub_499F10` to `FontStyle::FontStyle`.
- Rename `sub_499F60` to `FontStyle::GetRule` or `FontStyle::GetStyleRule`.
- Rename `sub_499F90` to `FontStyle::Configure`.
- Type `FontStyle` as a 0x20-byte object with `std::vector<FontStyleRule>` storage at `+0x14/+0x18/+0x1c`.
- Type `FontStyleRule` as 16 bytes: `textColor`, `textBackColor`/`secondaryColor`, `effect`, reserved padding, `textAlign`.
- Comment `sub_499F60`: "copies selected 16-byte rule into caller buffer when index is in range; return register is not source-significant."
- Comment `sub_499F90`: "builds a FontStyleRule and appends it; only low byte of effect is written."
- Comment `sub_49AC60`: "compiler/container vector growth for FontStyleRule; single caller from FontStyle::Configure; source should use push_back."

Medium-high confidence:

- Rename/comment `sub_4536E0` as `FontStyle::~FontStyle` or destructor-like `FontStyle::ClearRules` depending on accepted source-shape policy.
- Name root scalar fields as `m_paneOpacity`, `m_textOpacity`, `m_fillColor`, and `m_frameColor`; conservative fallback for the two color dwords is `m_primaryColor`/`m_secondaryColor`.

Rejected actions:

- Do not model `0x00499f60` as container-only support.
- Do not keep generated MiniMap names as shared `FontStyle` fields.
- Do not assign or emit [UID:00011W] `0x0049ac60` as `FontStyle` source code.
- Do not move [UID:00011T] under MiniMap, NewMail, HelpPane, or StaticTextControlPane2 ownership in this pass.

## Confidence And Remaining Uncertainty

- Recommendation confidence: high for current action.
- Score confidence: high for `00011T` at `86/91`; below 95 because exact historical spelling and source/header physical placement remain inferred.
- Remaining uncertainty:
  - Original file may have used `FontStyle.h` plus `FontStyle.cpp`, or declarations may have been local to a broader static/help text control source. Current generated route should stay standalone until stronger source-order evidence appears.
  - `Configure` could have been named `AddRule`/`AddStyleRule` historically. Current docs and caller setup wording support `Configure`.
  - `m_fillColor`/`m_frameColor` are best current names from HelpPane paint use, but exact original names are not proven.
  - MCP was unavailable in this session; direct PE/Capstone checks closed the target byte-level questions, but no fresh IDA decompile/type database query was collected.

## Validator Results For This Report Pass

- No by-* implementation validators were run because this report-only assignment did not edit target/support docs.
- MCP probe command attempted via PowerShell JSON-RPC `tools/list` against `http://127.0.0.1:13337/mcp`; result: connection failed, endpoint unavailable.
- Direct PE/Capstone evidence was collected read-only from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Changed Files

- Modified: `tools/leaser/Agents/Agent-B006/research/00011T-FontStyleCore-source-quality.md`
- Created: none
- Renamed: none
- Moved to executed: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00011T-FontStyleCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00011T"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00011T-FontStyleCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/00011T-FontStyleCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00011T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
