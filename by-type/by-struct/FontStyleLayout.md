*** UID:0001UN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FontStyleLayout

## Status

- Confidence: very strong for object/rule sizes, natural alignment, vector layout, constructor/cleanup behavior, caller fanout, and rule semantics; high for stripped historical spelling.
- Owner: [UID:00005C][FontStyle](by-class/FontStyle.md)
- Source candidate: [UID:0000JI][FontStyle](by-file/FontStyle.md)
- Evidence: current exact bodies at `0x00499f10`, `0x00499f60`, `0x00499f90`, `0x004536e0`, and `0x0049ac60`, plus HelpPane/StaticText consumer field use and live IDA UDT inspection.
- Reconstructable: true as source-level layout evidence, but non-emitting. [UID:00005C][FontStyle](by-class/FontStyle.md) formal H is the sole declaration owner; both formal channels here are intentionally blank.

## Object Layout

Recovered `FontStyle` size: 0x20 bytes.

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `+0x00` | 1 | `m_enabled` | Constructor sets `1`; HelpPane treats zero as disabled/no-style. |
| `+0x01` | 3 | natural alignment gap | Padding before the first float; no source-visible field is declared. |
| `+0x04` | 4 | `m_parentOpacity` | Constructor sets `0.2f`; HelpPane style-state copies use it as the parent/pane or outer opacity scalar. |
| `+0x08` | 4 | `m_textOpacity` | Constructor sets `0.2f`; HelpPane text-part state uses the paired text/inner opacity scalar, making this the stronger active text-opacity slot. |
| `+0x0c` | 4 | `m_foregroundColor` | Constructor sets `1`; HelpPane paint/style propagation supports a foreground/primary color role. |
| `+0x10` | 4 | `m_backgroundColor` | Constructor sets `0x80`; HelpPane paint/style propagation supports a background/secondary color role. |
| `+0x14` | 4 | `m_rules._First` | Begin pointer for 16-byte `FontStyleRule` records. |
| `+0x18` | 4 | `m_rules._Last` | Current end pointer. |
| `+0x1c` | 4 | `m_rules._End` | Allocation end pointer. |

## Rule Layout

Recovered rule size: 0x10 bytes.

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `+0x00` | 4 | `m_textColor` | First `Configure` argument; StaticText2 and HelpPane consumers use it as text color. |
| `+0x04` | 4 | `m_secondaryColor` | Second `Configure` argument; consumers use it as secondary/background/outline/shadow color. |
| `+0x08` | 1 | `m_effect` | Third `Configure` argument low byte; consumers branch on effect-like normal/outline/shadow behavior. |
| `+0x09` | 3 | natural alignment gap | Compiler padding before dword `m_alignment`; no source-visible field is declared. |
| `+0x0c` | 4 | `m_alignment` | Fourth `Configure` argument; consumers copy it into text alignment state before drawing. |

## Notes

- The vector entry is named `FontStyleRule`; the three pointer fields match the usual `std::vector<FontStyleRule>` storage pattern.
- Live IDA decompilation of `FontStyle::FontStyle` at `0x00499f10` writes `this[5]`, `this[6]`, and `this[7]` to zero, then writes the enabled byte, two `0.2f` values, scalar `1`, and scalar `128`. This proves the vector triplet begins at `+0x14` and the scalar header occupies the first 20 bytes.
- Live IDA decompilation of the bounded rule lookup at `0x00499f60` computes `(rulesEnd - rulesBegin) >> 4` and copies one `_OWORD` from `rulesBegin + 16 * index` when the index is in range. This proves the rule stride and copy width.
- Live IDA decompilation of `FontStyle::Configure` at `0x00499f90` builds a 16-byte stack rule from `m_textColor`, `m_secondaryColor`, low byte `m_effect`, and `m_alignment`, then appends it at `this + 0x14`; this proves the low-byte effect/padding caveat.
- The implicit destructor lowering at `0x004536e0` reads and clears the same `+0x14/+0x18/+0x1c` triplet and uses the large-allocation validation pattern seen in MSVC vector destructors before calling the shared free helper.
- [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) grows a vector of 16-byte entries and is currently called only from `FontStyle::Configure` in live IDA caller output. Treat it as compiler/template support, not an extra source-facing method.
- `HelpPane::SimpleHelpTextPartPane::DrawStyledTextSegment` and exact [UID:0004LB][0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine](by-memory/0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine.md) provide the current consumer evidence for rule semantics: rule `+0x00` feeds text color, `+0x04` feeds secondary/background/outline/shadow color, `+0x08` selects effects `0/1/3`, bytes `+0x09..+0x0b` remain padding, and `+0x0c` is copied into alignment state. [UID:0004L8][0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint](by-memory/0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint.md) initializes only those four semantic fields and relies on out-of-range GetRule preserving the current record.
- Observed effect values include `0` for normal text, `1` for outlined label text, and `3` for shadowed/special label text.
- Exact historical spelling is not proven. Earlier B006 names `paneOpacity`, `fillColor`, `frameColor`, `textBackColor`, and `textAlign` are retained as historical spelling attempts, but the B012 `m_parentOpacity`, `m_foregroundColor`, `m_backgroundColor`, `m_secondaryColor`, and `m_alignment` names better match the current source-facing role analysis. Do not revert to generic `styleValue0/styleValue1` without new evidence.
- Rejected rule names: generated MiniMap field names (`m_flags`, `m_bold`, `m_italic`, `m_color`, `m_size`), old generic `firstValue`/`secondValue`/`fourthValue`, and count/container-only `GetRule` interpretations.

## Current IDA UDT Status And Correction

- The current `FontStyle` UDT is size 32 and places all scalar/vector fields at the correct offsets, but exposes the natural `+0x01..+0x03` gap as a synthetic `_alignment` member. Source must use `bool m_enabled` followed by natural alignment, not an explicit padding array.
- The current `FontStyleRule` UDT is size 16 but is materially stale: it places byte `m_alignment` at `+0x09` and `_reserved[6]` at `+0x0a`. Exact Configure stores prove byte `m_effect` at `+0x08`, natural padding at `+0x09..+0x0b`, and dword `m_alignment` at `+0x0c`.
- HelpPane field xrefs corroborate `m_textColor/+0x00`, `m_secondaryColor/+0x04`, and `m_effect/+0x08`; the stale `+0x09` alignment member has no field xref. The absence is expected because the current UDT offset is wrong, not because alignment semantics are absent.
- Supervisor Gate 2B may correct both named UDTs after literal current-state recheck. No source or emitter is installed by this page; the accepted formal declaration is wholly owned by UID00005C H.

## Caller Evidence

- Live IDA caller checks on 2026-06-06 show `FontStyle::FontStyle` called from UI/text setup functions at `0x00450e3e`, `0x00451f32`, `0x00452408`, `0x00452887`, `0x00452ad2`, `0x0047d0d2`, and `0x004c69d2`.
- `FontStyle::Configure` is called from the same UI/static-label families at `0x00450f22`, `0x00451f74`, `0x00451f8d`, `0x004528be`, `0x00452b09`, `0x00452c2b`, and `0x0047d3fa`.
- The bounded rule lookup at `0x00499f60` is used by [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md)'s draw path at `0x004c6723` and `0x004c67b3`.
- Cleanup at `0x004536e0` is called from `0x0045214a` and `0x00452be3`, matching local/unwind cleanup of configured style records rather than independent product behavior.
- 2026-06-14 live IDA MCP in session `a001_goal2_class_batch` reconfirmed function sizes: constructor `0x00499f10` size `0x41`, bounded lookup `0x00499f60` size `0x25`, configure/append `0x00499f90` size `0x4a`, cleanup `0x004536e0` size `0x52`, and vector growth `0x0049ac60` size `0x114`.
- 2026-06-14 live decompilation matches the recorded offsets: constructor zeroes `this[5..7]`, writes enabled byte, two identical scalar values, `this[3] = 1`, and `this[4] = 128`; lookup computes `(this[6] - this[5]) >> 4`; configure writes a 16-byte stack record and appends through `this + 0x14`; cleanup frees and zeroes `this[5..7]`; growth moves 16-byte records and is still called only from configure.
- 2026-06-14 live xrefs reconfirm caller fan-out: seven constructor call sites, seven configure call sites, two lookup call sites from the `HelpPane` draw path, ten cleanup call sites including unwind paths, and one vector-growth caller at `0x00499fcf`.

## Score Rationale

- Completion is `94`: exact 0x20/0x10 layouts, all fields/gaps, vector storage, constructor/lookup/configure/destructor/growth behavior, cross-feature consumers, current UDT defect, sole H owner, blank formal channels, and rejected alternatives are resolved.
- Confidence is `96`: independent body/store/copy/cleanup/growth and consumer evidence agree on every offset and width. The remaining uncertainty is stripped original spelling, not ABI or source-shape closure.

## Cross-References

- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0000JI][FontStyle](by-file/FontStyle.md)
- [UID:0000XM][0x004536e0-0x00453732.FontStyleImplicitDestructor](by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md)
- [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md)
- [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md)
- [UID:0004L8][0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint](by-memory/0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint.md)
- [UID:0004LB][0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine](by-memory/0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine.md)

## Changes

- 2026-08-17 B006 accepted UID0000JI whole-file callback:
  - Raised `86/91 -> 94/96`, retained owner UID00005C and `RECONSTRUCTABLE:TRUE`, cleared `EMITTER_UIDS`, and blanked both formal channels because UID00005C H is the sole declaration owner.
  - Replaced explicit `m_padding0`/`m_reserved` source fields with exact natural alignment gaps; fixed `FontStyleRule::m_alignment` to dword `+0x0c` and documented the current stale IDA UDT at `+0x09`.
  - Reclassified `0x004536e0` as compiler-emitted implicit destruction and preserved all exact constructor/GetRule/Configure/vector/consumer evidence. Earlier comment-emitter and explicit-padding language below is historical only.

- 2026-06-21 B012 FontStyle source-quality incorporation:
  - Kept: `86/91`, owner/emitter [UID:00005C][FontStyle](by-class/FontStyle.md), and comment-only C++ emission.
  - Changed: object fields to `m_enabled`, `m_padding0`, `m_parentOpacity`, `m_textOpacity`, `m_foregroundColor`, `m_backgroundColor`, and `m_rules._First/_Last/_End`; rule fields to `m_textColor`, `m_secondaryColor`, `m_effect`, `m_reserved`, and `m_alignment`; added observed effect values `0`, `1`, and `3`.
  - Summary/evidence: B012 reanalysis kept the same object size/vector triplet/rule stride but replaced older B006 spelling with source-facing names and preserved the high-byte padding caveat after `m_effect`.
- 2026-06-20 B006 FontStyle source-quality implementation:
  - Before: `85/90`, generic root fields and generic rule fields, blank formal C++.
  - Changed to: `86/91`, source-facing fields `enabled`, `paneOpacity`, `textOpacity`, `fillColor`, `frameColor`, vector-style `rules`, and rule fields `textColor`, `textBackColor`, `effect`, `reserved`, and `textAlign`.
  - Summary/evidence: accepted B006 report revalidated constructor defaults, vector triplet, void `GetRule` copy behavior, Configure append layout, cleanup/growth support, and HelpPane/StaticText2 rule consumers. Formal C++ emits only a comment because [UID:00005C][FontStyle](by-class/FontStyle.md) emits the actual declaration shell.
- 2026-05-30: Scored the layout page from 0/0 to 76/84 after rechecking the cleanup method and confirming the vector triplet offsets. Evidence: IDA MCP decompilation of `0x004536e0` reads/writes `this[5]`, `this[6]`, and `this[7]` as `+0x14/+0x18/+0x1c`; existing constructor/configure docs support the remaining scalar and 16-byte rule layout.
- 2026-06-04: Marked `RECONSTRUCTABLE:TRUE` without changing scores.
  - Reasoning: IDA-backed constructor, configure, cleanup, and vector-growth evidence proves a real source-level `FontStyle` layout and rule-record declaration; parent attachment and C++ emission stay blank because final field semantics remain below the 95/95 bar.
- 2026-06-06: Raised completion/confidence from `76/84` to `82/88` and attached the layout to [UID:00005C][FontStyle](by-class/FontStyle.md).
  - Reasoning: live IDA now records the constructor defaults, bounded rule lookup, rule append stack layout, cleanup triplet reset, vector-growth slow path, and caller fan-out directly on this page. The parent class and this layout now both meet the 80/80 attachment gate.
  - Summary and evidence: `0x00499f10` initializes the 0x20-byte object, `0x00499f60` copies one 16-byte rule by index, `0x00499f90` appends a 16-byte stack rule through the `+0x14` vector triplet, `0x004536e0` clears the same triplet, and `0x0049ac60` is the only observed vector-growth slow path. Final field names and C++ declaration emission remain below the final reconstruction gate.
- 2026-06-14 A002 Goal2 score pass:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`, with older live evidence and parent text.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:90`.
  - Summary/evidence: IDA MCP session `a001_goal2_class_batch` reconfirmed the five layout-driving function sizes, constructor defaults, 16-byte lookup/append stride, cleanup reset, vector-growth behavior, and caller fan-out. Final C++ remains blank because scalar field names and rule declaration spelling are not source-quality.
