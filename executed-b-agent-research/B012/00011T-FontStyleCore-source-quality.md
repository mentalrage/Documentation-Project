** TARGET-REPORT-UID:00011T **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B012 Source-Quality Report: [UID:00011T] FontStyleCore

Status: FINISHED report-only research. No by-* documentation, generated output, IDA database, project-level report, or coverage report was edited.

## Target Paths

- Target by-memory doc: `source-3/project-documentation/by-memory/0x00499f10-0x00499fda.FontStyleCore.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/00011T-FontStyleCore-source-quality.md`
- Owner/emitter under review: [UID:00005C] `source-3/project-documentation/by-class/FontStyle.md`
- Source/file support under review: [UID:0000JI] `source-3/project-documentation/by-file/FontStyle.md`
- Layout support under review: [UID:0001UN] `source-3/project-documentation/by-type/by-struct/FontStyleLayout.md`
- Slow-path support under review: [UID:00011W] `source-3/project-documentation/by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`

## Assignment Result

`FontStyleCore` should remain source-bearing and emit through `FontStyle`. The current page is below source quality mostly because it has a blank C++ section, generic parameter/field names, a stale `GetRule` return explanation, and no target-specific source-shape recommendation. The evidence supports a first-draft mid-2000s C++ implementation for the constructor, bounded rule copy, and rule append method.

Recommended target metadata:

| Field | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `COMPLETION` | `84` | `86` | Source shape, field roles, method signatures, support route, and C++ draft are now resolved enough for implementation callback. |
| `CONFIDENCE` | `90` | `91` | Function boundaries, caller set, vector triplet, rule stride, and one-caller growth support agree across target docs and prewave/IDA exports. Confidence remains below final because exact original member spelling is inferred. |
| `CANONICAL_OWNER` | `00005C` | `00005C` | Correct reusable `FontStyle` class owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | This is source-authored class logic, not standalone compiler glue. |
| `EMITTER_UIDS` | `00005C` | `00005C` | Emit as `FontStyle` methods under the `FontStyle` file route. |

## Evidence Checked

- Read target doc `0x00499f10-0x00499fda.FontStyleCore.md`.
- Read support docs: `FontStyle.md`, `FontStyle.cpp` file doc, `FontStyleLayout.md`, `FontStyleClearRules.md`, `FontStyleRuleVectorGrowth.md`, `SimpleHelpTextPartPaneCore.md`, `StaticTextControlPane2.md`, `StaticTextControlPane2__SimpleHelpTextPartPane.md`, `HelpPaneCore.md`, `MiniMapDialog.md`, and `NewMailDialog.md`.
- Read generated state at `auto-generated/NexusTK/ui/controls/FontStyle.cpp`; it currently contains empty emitter markers for `00005C`, `0000XM`, `00011T`, and `0001UN`, so no source-bearing output exists yet.
- Read prior B-agent leads:
  - `Agent-B012/research/00005C-FontStyle-class-source-quality.md`
  - `Agent-B006/research/00011T-FontStyleCore-source-quality.md`
- Read prewave exported function records:
  - `source-3/core/data/cache/prewave/functions/0x00499f10.json`
  - `source-3/core/data/cache/prewave/functions/0x00499f60.json`
  - `source-3/core/data/cache/prewave/functions/0x00499f90.json`
  - `source-3/core/data/cache/prewave/functions/0x0049ac60.json`
- Read decompiled bundles for those functions and caller/xref bundles for direct callsite confirmation.
- Checked current coverage rows for `00011T`, `00011W`, `00005C`, `0000JI`, and `0001UN`.

## Function Boundary And Padding Findings

The current target split is correct and should not be merged with adjacent StaticText code:

| Range | Size | Source role | Evidence |
| --- | ---: | --- | --- |
| `0x00499f10-0x00499f51` | `0x41` / 65 | `FontStyle::FontStyle()` | Prewave `0x00499f10` has size 65, zeroes vector triplet, sets defaults, returns `this`. |
| `0x00499f51-0x00499f60` | 15 bytes | alignment | Current target records fifteen `0xcc` bytes. |
| `0x00499f60-0x00499f85` | `0x25` / 37 | `FontStyle::GetRule(...) const` | Prewave `0x00499f60` has size 37 and copies one 16-byte record if in range. |
| `0x00499f85-0x00499f90` | 11 bytes | alignment | Current target records eleven `0xcc` bytes. |
| `0x00499f90-0x00499fda` | `0x4a` / 74 | `FontStyle::Configure(...)` | Prewave `0x00499f90` has size 74, builds a 16-byte stack record, appends inline or calls vector growth. |
| `0x00499fda-0x00499fe0` | 6 bytes | alignment before StaticText child constructor | Current target records six `0xcc` bytes before `SimpleHelpTextPartPaneCore`. |

No split/merge change is recommended. `0x0049ac60-0x0049ad74` is a related support helper, but it is not in the target range and should not be emitted as a `FontStyle` method body.

## Layout And Type Findings

Recovered `FontStyle` object size remains `0x20`.

Recommended source-facing layout names for first-draft C++:

| Offset | Recommended name | Type | Evidence and confidence |
| --- | --- | --- | --- |
| `+0x00` | `m_enabled` | `unsigned char` or `bool` with explicit padding | Constructor writes `1`; HelpPane raw style-state helper checks `[style + 0]` as enabled. High confidence. |
| `+0x01..+0x03` | `m_padding0` | `unsigned char[3]` | Natural padding before 32-bit fields. High confidence as padding, not semantic state. |
| `+0x04` | `m_parentOpacity` | `float` | Constructor writes `0.2f`; support docs identify this as the paired opacity/style scalar. Medium-high semantic confidence. |
| `+0x08` | `m_textOpacity` | `float` | Constructor writes `0.2f`; raw HelpPane style-state helper reads `[style + 8]`, compares it to `0.0f`/`1.0f`, and copies it to child opacity at `+0x90`. High confidence this is the active opacity. |
| `+0x0c` | `m_foregroundColor` | `unsigned int` | Constructor writes `1`; HelpPane docs describe these scalar fields as foreground/background-compatible style state. Medium confidence. |
| `+0x10` | `m_backgroundColor` | `unsigned int` | Constructor writes `0x80`; paired with `+0x0c` in support docs. Medium confidence. |
| `+0x14` | `m_rules._First` / `m_rulesBegin` | `FontStyleRule *` | Constructor zeroes it, lookup/configure/clear/growth use it as vector begin. High confidence. |
| `+0x18` | `m_rules._Last` / `m_rulesEnd` | `FontStyleRule *` | Constructor zeroes it, lookup computes count from `end - begin`, configure advances it by 16. High confidence. |
| `+0x1c` | `m_rules._End` / `m_rulesCapacity` | `FontStyleRule *` | Constructor zeroes it; configure compares it to end before growth. High confidence. |

`std::vector<FontStyleRule> m_rules` is the best source-level declaration. The raw triplet names should remain in layout notes only if the docs cannot introduce a vector declaration yet.

Recommended 16-byte `FontStyleRule` shape:

| Offset | Recommended name | Type | Evidence and confidence |
| --- | --- | --- | --- |
| `+0x00` | `m_textColor` | `unsigned int` | First `Configure` argument; SimpleHelpTextPartPane docs call this foreground/draw color. High confidence. |
| `+0x04` | `m_secondaryColor` | `unsigned int` | Second `Configure` argument; consumed as secondary/background color for outlined or shadowed drawing. High confidence for secondary color role, lower for final spelling. |
| `+0x08` | `m_effect` | `unsigned char` | Third `Configure` argument is byte-sized; draw consumers dispatch modes `0`, `1`, and `3`. High confidence. |
| `+0x09..+0x0b` | padding/reserved | bytes | Ghidra shows the high three bytes of this dword as not explicitly source-written by the appender. Treat as padding/reserved. High confidence. |
| `+0x0c` | `m_alignment` | `unsigned int` | Fourth `Configure` argument; draw support records it as saved field copied into pane state at `+0x8c`. Medium confidence; `m_textAlign` is an acceptable alternate if the broader text layout pass prefers that spelling. |

## Heuristic / Inference Reanalysis And Validation

### Constructor source shape

Prewave/IDA decompilation for `0x00499f10`:

- writes `this[5]`, `this[6]`, `this[7]` to zero, proving the vector triplet at `+0x14/+0x18/+0x1c`;
- writes byte `+0x00 = 1`;
- writes both `+0x04` and `+0x08` as `0x3e4ccccd` / `0.2f`;
- writes `+0x0c = 1` and `+0x10 = 128`;
- has no callees and returns `this`.

This is normal constructor source. It should emit as a member initializer list or equivalent assignments, not raw decompiler output.

### Accessor signature

The best source-facing signature is:

```cpp
void FontStyle::GetRule(unsigned int index, FontStyleRule *outRule) const
```

Reasoning:

- Ghidra types the function as `void` and shows only an in-range copy side effect.
- The actual body computes `ruleCount = (rulesEnd - rulesBegin) >> 4`, and if `index < ruleCount`, copies exactly 16 bytes from `rulesBegin + index`.
- Out-of-range behavior leaves the caller output unchanged.
- IDA's `unsigned int` return is a decompiler artifact: in the out-of-range path EAX still holds the count, while in the in-range path EAX is reused for the output pointer. Those mixed values do not form a stable source return.
- The only direct callsites are two HelpPane draw-path calls at `0x004c6723` and `0x004c67b3`; their purpose is to fill a local rule record for drawing, not to consume a count return.

Rejected alternative: `unsigned int GetRule(...)` or `unsigned int CopyRule(...)` returning count. This preserves an IDA artifact but would expose a source API whose two control-flow paths return different meanings. It should not be emitted.

### Configure/helper signature

The best source-facing signature is:

```cpp
void FontStyle::Configure(unsigned int textColor,
                          unsigned int secondaryColor,
                          unsigned char effect,
                          unsigned int alignment)
```

Reasoning:

- The current corpus already calls the helper `Configure`, and no stronger original source name has been recovered.
- The helper appends one `FontStyleRule`; `AddRule` or `AddTextRule` would describe the mechanics, but changing the method name would diverge from existing by-* support without hard source evidence.
- Caller values map to text-effect usage:
  - MiniMap uses `Configure(0x80, 6, 1, 0)`, matching an outlined label style.
  - NewMail uses `Configure(128, 128, 3, 0)`, matching a shadow/special label style.
  - StaticText/HelpPane consumers document mode byte `0` normal, `1` outlined, `3` shadowed.
- The inline path writes a 16-byte record and advances `rulesEnd` by 16.
- The full-capacity path calls `0x0049ac60` with the vector triplet at `this + 0x14`, insertion pointer, and stack rule address.

Rejected alternative: make `0x0049ac60` a named `FontStyle::GrowRules` method. It is a one-caller MSVC/Dinkumware-style vector growth routine over 16-byte records, with allocator/memmove/free/invalid-parameter behavior. Source should express `m_rules.push_back(rule)`.

### Padding and high-byte caveat

Ghidra shows `uStack_c = CONCAT31(uStack_c._1_3_, param_3)` and IDA shows only `LOBYTE(v7[2]) = a4` before copying the whole 16-byte record. This proves only the low byte at rule `+0x08` is source-meaningful. The high three bytes are padding/reserved from the source layout and should not be named as a 32-bit mode value. First-draft C++ can use a local `FontStyleRule rule;` and assign only `m_effect`, which matches the binary-level lack of explicit high-byte initialization. If the project style requires deterministic padding, use `FontStyleRule rule = {};` but note that zeroing may not match the observed compiler shape.

### Owner and source-file route

`FontStyleCore` should stay under `FontStyle` and `NexusTK/ui/controls/FontStyle.cpp`.

Evidence:

- Constructor and Configure callers spread across MiniMap, NewMail, HelpPane, and static text setup. That fan-out argues against ownership by any one consumer.
- `HelpPane` embeds a layout-compatible style block and uses rule lookup in the draw path.
- `StaticTextControlPane2` owns an embedded text-part consumer of the rule shape, but the constructor/configure helpers are shared setup utilities.
- Current generated file route already points `00005C`, `00011T`, and `0001UN` to `auto-generated/NexusTK/ui/controls/FontStyle.cpp`; it is empty only because C++ bodies are blank.

Rejected alternative: fold this target into `StaticTextControlPane.cpp`. The adjacent `0x00499fe0` StaticText child constructor explains adjacency, not ownership; `NewMailDialog`, `MiniMapDialog`, and `HelpPane` callers show broader reuse.

### C++ readiness

The target meets the current source gate for first-draft C++:

- `RECONSTRUCTABLE:TRUE`
- completion/confidence average after this report recommendation: `(86 + 91) / 2 = 88.5`
- owner/emitter route is valid and already attached;
- function boundaries and support helper split are exact;
- remaining uncertainty is name spelling, not behavior.

This should not remain no-code. The C++ should be emitted with source-shaped names and with comments only for unresolved padding semantics if the implementer chooses to mention them.

## Caller And Reachability Findings

Direct xrefs from prewave/IDA bundles:

| Target method | Direct callsites | Caller roles |
| --- | --- | --- |
| `0x00499f10` constructor | `0x00450e3e`, `0x00451f32`, `0x00452408`, `0x00452887`, `0x00452ad2`, `0x0047d0d2`, `0x004c69d2` | MiniMap/static label setup, NewMail EPF label setup, HelpPane constructor/style setup. |
| `0x00499f60` `GetRule` | `0x004c6723`, `0x004c67b3` | HelpPane text draw path retrieves style rules for styled segments. |
| `0x00499f90` `Configure` | `0x00450f22`, `0x00451f74`, `0x00451f8d`, `0x004528be`, `0x00452b09`, `0x00452c2b`, `0x0047d3fa` | MiniMap/static label and NewMail label style configuration. |
| `0x0049ac60` growth support | `0x00499fcf` | One direct call from `Configure` only. |

No dead-code or no-route concern applies to `00011T`; it is a live shared class-method cluster.

## First-Draft C++ Recommendation

Recommended method bodies for the target `RECONSTRUCTION_CPP` section, assuming support docs/class declaration define `FontStyleRule` and `std::vector<FontStyleRule> m_rules`:

```cpp
FontStyle::FontStyle()
    : m_enabled(1),
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
```

Implementation note: If the class declaration cannot yet use `std::vector`, keep the generated declaration/source route on `FontStyle` but do not expose raw triplet manipulation in source-facing C++. The growth helper evidence is strong enough to model the triplet as a vector. If the project style forbids `std::vector` in emitted code, the alternate is a project-local vector wrapper with the same three-pointer layout; the target method bodies should still express constructor defaults, bounded copy, and append rather than raw allocation.

## Recommended Exact Target Doc Changes

For `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`:

1. Change metadata to:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Fill `RECONSTRUCTION_CPP` with the first-draft C++ above, coordinated with the `FontStyle` class declaration.

3. In "Rule Lookup Behavior", replace "out-of-range indexes leave the output unchanged and return the count" with:

```text
Out-of-range indexes leave the output unchanged. Treat the IDA `unsigned int` return as a register-lifetime/decompiler artifact; Ghidra models the routine as `void`, and source callers use the caller-provided output record.
```

4. In "Configure Behavior", replace generic `firstValue`, `secondValue`, `selector`, `fourthValue` with:

```text
`Configure(textColor, secondaryColor, effect, alignment)` builds a 16-byte `FontStyleRule`: text color at `+0x00`, secondary/outline/shadow color at `+0x04`, byte-sized effect selector at `+0x08`, and alignment/saved style state at `+0x0c`.
```

5. Add a short "Source Shape" section:

```text
Source shape: `FontStyle::FontStyle`, `FontStyle::GetRule(unsigned int, FontStyleRule*) const`, and `FontStyle::Configure(unsigned int, unsigned int, unsigned char, unsigned int)` should emit under [UID:00005C][FontStyle]. `0x0049ac60` remains [UID:00011W] compiler/vector support generated from `m_rules.push_back(rule)`.
```

6. Add the caller table from this report or update the current caller bullets to mention the source roles: MiniMap/static labels, NewMail EPF label, HelpPane style construction, and HelpPane styled text draw lookup.

7. Add an explicit rejected-alternatives note:

```text
Rejected alternatives: do not route this to StaticTextControlPane despite adjacency; do not emit `0x0049ac60` as a source method; do not preserve the IDA `unsigned int` return for `GetRule`.
```

## Recommended Support-Doc Changes

For `by-class/FontStyle.md`:

- Raise to approximately `87/89`.
- Add a class declaration/source-shape section with `FontStyleRule`, constructor, destructor/cleanup policy, `GetRule`, and `Configure`.
- Replace caveat language saying final rule names are still blocking C++ with target-specific names:
  - `FontStyleRule::m_textColor`
  - `FontStyleRule::m_secondaryColor`
  - `FontStyleRule::m_effect`
  - `FontStyleRule::m_alignment`
- Keep a caveat that exact original spelling is inferred and the three reserved bytes after `m_effect` are padding/reserved.
- State that `m_rules` is source-level vector storage and [UID:00011W] is compiler/template support.

For `by-type/by-struct/FontStyleLayout.md`:

- Raise to approximately `86/91`.
- Update object field table from generic `innerOpacityOrValue`, `outerOpacityOrValue`, `styleValue0`, `styleValue1`, `rulesBegin/rulesEnd/rulesCapacity` to the recommended names above, while noting vector triplet raw offsets.
- Update rule layout from `firstValue`, `secondValue`, `selectorLowByte`, `fourthValue` to `m_textColor`, `m_secondaryColor`, `m_effect`, padding, and `m_alignment`.
- Add that mode byte values observed in draw consumers are `0` normal, `1` outlined, and `3` shadowed/special.

For `by-file/FontStyle.md`:

- Raise to approximately `86/89`.
- Record that the first source-bearing emission should live in `NexusTK/ui/controls/FontStyle.cpp` unless later recovered source proves a different split.
- Note that MiniMap, Mail, HelpPane, and StaticText are consumers, not owners.

For `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`:

- No by-doc body change is required from this target pass if the current doc already has `85/90`, `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank C++.
- The coverage row is stale and should be replaced by supervisor even if the by-doc body is left alone.

For generated output:

- After implementation callback, `auto-generated/NexusTK/ui/controls/FontStyle.cpp` should no longer be only empty emitter markers for `00005C`/`00011T`.
- Do not add raw `sub_499F10`, `sub_499F60`, `sub_499F90`, or `sub_49AC60` names to emitted source except as comments in documentation, not generated C++.

## Exact Coverage Replacement Text

No coverage file was edited. Recommended supervisor-owned replacements:

For `source-3/project-documentation/by-memory/-coverage-report.md`:

```text
    - [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md) 0x00499f10-0x00499fda | class-method cluster | FontStyleCore : reconstructable : 86% : very strong : B012 source-quality pass resolves constructor/accessor/configure ranges and padding, 0x20 FontStyle layout, +0x14/+0x18/+0x1c rule-vector triplet, byte-sized rule effect, HelpPane/MiniMap/Mail/static-text caller roles, one-caller vector-growth support, FontStyle owner/emitter route, and first-draft C++ readiness.
```

```text
    - [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) 0x0049ac60-0x0049ad74 | compiler/vector helper | FontStyleRuleVectorGrowth : ignored : 85% : strong : One-caller MSVC/Dinkumware-style vector growth slow path for FontStyle 16-byte rule records; generated from source-level `m_rules.push_back(rule)`, with allocator/memmove/free/invalid-parameter behavior and no source-facing owner/emitter.
```

For `source-3/project-documentation/by-class/-coverage-report.md`:

```text
- [UID:00005C][FontStyle](by-class/FontStyle.md) : reconstructable : 87% : strong : Compact reusable text-style descriptor with source-shaped constructor, bounded rule copy, Configure append, cleanup/vector storage policy, 0x20 layout, 16-byte FontStyleRule names, HelpPane/MiniMap/Mail/static-text consumers, and FontStyle.cpp emitter route.
```

For `source-3/project-documentation/by-file/-coverage-report.md`:

```text
- [UID:0000JI][FontStyle](by-file/FontStyle.md) : reconstructable : 86% : strong : Reusable UI text-style support file with source-ready FontStyle constructor, GetRule, Configure, cleanup/vector policy, layout/type support, vector-growth no-code proof, and MiniMap/Mail/HelpPane/static-text caller evidence.
```

For `source-3/project-documentation/by-type/by-struct/-coverage-report.md`:

```text
- [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md) : reconstructable : 86% : very strong : 0x20-byte FontStyle layout with enabled byte, opacity/color defaults, +0x14/+0x18/+0x1c rule-vector triplet, 16-byte FontStyleRule record, byte-sized effect field, observed normal/outlined/shadowed consumers, cleanup/growth support, and source-facing field-name recommendations.
```

## Validator Needs After Implementation

Run only after supervisor sends an implementation callback and by-* docs are edited:

> Executable block R001 was removed from this report and preserved verbatim in [00011T-FontStyleCore-source-quality-removed.md](00011T-FontStyleCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected results: metadata parses, target emits under `FontStyle`, no forbidden orphan emitter, and coverage rows match updated completion/confidence states.

Optional generated-output check after validation/regeneration:

> Executable block R002 was removed from this report and preserved verbatim in [00011T-FontStyleCore-source-quality-removed.md](00011T-FontStyleCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: source-shaped `FontStyle` method names are present; raw `sub_499F*` and `sub_49AC60` names are absent unless only present in comments/empty marker provenance.

## IDA Rename / Type / Comment Recommendations

Recommended if an IDA cleanup callback is later authorized:

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x00499f10` | Rename `sub_499F10` to `FontStyle_ctor` or `FontStyle::FontStyle`. | High |
| `0x00499f60` | Rename `sub_499F60` to `FontStyle_GetRule`; type as `void __thiscall(FontStyle *this, unsigned int index, FontStyleRule *outRule)`. | High |
| `0x00499f90` | Rename `sub_499F90` to `FontStyle_Configure`; type as `void __thiscall(FontStyle *this, unsigned int textColor, unsigned int secondaryColor, unsigned char effect, unsigned int alignment)`. | High |
| `0x0049ac60` | Rename/comment as `std_vector_FontStyleRule_insert_growth` or similar compiler support, not a source method. | High |
| `FontStyle` UDT | Size `0x20`; fields as recommended above, with a vector triplet or `std::vector<FontStyleRule>` overlay at `+0x14`. | Medium-high |
| `FontStyleRule` UDT | Size `0x10`; text color, secondary color, byte effect, reserved padding, alignment/saved state. | Medium-high |
| `0x00499fcf` callsite | Comment: slow path for `m_rules.push_back(rule)` when capacity is exhausted. | High |

## Open Questions And Closure

- Exact original method spelling for `Configure`: not recovered. Closed for implementation by retaining the corpus-consistent `Configure`; `AddRule` remains a descriptive but unsupported alternative.
- Exact original spelling for `m_parentOpacity`, `m_textOpacity`, `m_foregroundColor`, and `m_backgroundColor`: not recovered. Closed for first draft with source-facing descriptive names and documented confidence. `+0x08` as active text opacity is stronger than `+0x04`; color names remain medium confidence.
- Whether to zero the reserved bytes in `FontStyleRule`: binary evidence only proves the low effect byte is assigned before a 16-byte copy. Best source-shape draft leaves padding/reserved bytes implicit; implementer may zero-initialize only if project style prefers deterministic emitted C++ over byte-perfect compiler behavior.
- Whether `0x0049ac60` should be emitted: closed as no-code/compiler support. It has one caller, vector triplet semantics, 1.5x capacity growth, max-size guard, memmove, invalid-parameter guard, and free logic.
- Whether target should route to StaticText/HelpPane/MiniMap/Mail: closed as no. Those are consumers; `FontStyle` is the reusable owner.

## Implementation Callback Checklist

If supervisor accepts this report, the implementation callback can be:

1. Update `0x00499f10-0x00499fda.FontStyleCore.md` metadata to `86/91`, keep owner/emitter as `00005C`, and add first-draft C++ for constructor, `GetRule`, and `Configure`.
2. Replace the stale `GetRule` return wording with the `void` side-effect-copy explanation.
3. Rename `Configure` argument/rule fields in target behavior text.
4. Update `FontStyle.md` with class/source declaration details and `FontStyleRule` names.
5. Update `FontStyleLayout.md` field/rule tables with the recommended names and effect-byte caveat.
6. Update `FontStyle.md` file-level route to say `FontStyle.cpp` is source-ready and consumers are MiniMap/Mail/HelpPane/StaticText.
7. Do not make `00011W` source-bearing; only replace its stale coverage row.
8. Apply the exact coverage rows listed above.
9. Run the validator commands listed above and check generated `FontStyle.cpp` for source-shaped method names.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00011T-FontStyleCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00011T"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00011T-FontStyleCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/00011T-FontStyleCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00011T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
