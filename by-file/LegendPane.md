*** UID:0000KM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# LegendPane

## Status

- Confidence: very strong for constructor behavior, both input override identities, vtable ownership, exact source contents/order, and `ui/panels/` placement; strong for final original helper/field spellings and physical source factoring.
- Proposed module: `ui/panels/LegendPane.cpp`; UID000074 emits the complete class declaration, UID0001HB emits the constructor, and UID00023W emits the two input overrides. The exact original standalone-versus-broader look/status source split remains a low-impact placement caveat.
- Current recovered source: `class_LegendPane.cpp`
- Main address doc: [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- Vtable/layout anchor: [UID:00038P][LegendPaneVtables](by-type/by-vtable/LegendPaneVtables.md)
- Exact vtable data: [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md)

## File Role

`LegendPane` is a small reusable legend/key child pane used by look/status panels. It initializes a `TextEditPane`-style read-only pane with resolution-dependent geometry, installs the `LegendPane` vtable views, stores inherited `m_verticalScrollBarOffset = 63`, and overrides the EventHandler key/text route plus the primary mouse-event fallback with unconditional false results.

IDA confirms `LegendPane` vtable bases at `0x00624388`, `0x00624400`, and `0x00624430`. Current generated metadata reports `vtable_count: 0`, so the family page is the stronger layout anchor.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `LegendPane` constructor | `0x0056c400-0x0056c493` | Source-ready `LegendPane::LegendPane()` through UID0001HB: `g_useEpfAssets` geometry, `IsLegacyAssetMode()` word argument, accepted `TextEditPane` constructor shape, and inherited `m_verticalScrollBarOffset = 63` at `this+0x104`. |
| `LegendPane::HandleKeyOrTextEvent` | `0x0056c4a0-0x0056c4a5` | Source-ready bool EventHandler secondary `+0x08` override; accepts Event, ignores it, returns false. |
| `LegendPane::OnMouseEvent` | `0x0056c4b0-0x0056c4b5` | Source-ready bool primary `+0x60` override reached by inherited pointer/mouse fallback; accepts Event, ignores it, returns false. |
| `LegendPane` RTTI/vtables | `0x00624384-0x00624438` | Source-declared/generated-binary class data with primary, secondary, and tertiary vtable views. |

## Source Placement And Boundaries

- Keep the current projected root at `NexusTK/ui/panels/`. The class is constructed by both self-look and user-look code, so attaching it exclusively to either caller would hide the shared child-pane role.
- UID0001HB emits here as a shared child-pane constructor. Do not absorb it into SelfLookPane, SelfLookPane2, UserLookPane, GroupPane, vtable data, or the false-stub UID; the three look-panel callsites are consumer evidence rather than ownership evidence.
- Treat [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md) as class declaration output for this source root, not as hand-written data to port byte-for-byte.
- Do not merge the constructor range into [UID:0000P0][UserLookPane](by-file/UserLookPane.md) or [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) without a broader look-pane source-layout pass; the written caller evidence proves shared use, not original local nesting.
- Keep the constructor range ending at `0x0056c493`; the `0x0056c493-0x0056c4a0` bytes remain padding. The following [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md) range is a separate `LegendPane` vtable target pair, and [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md) starts after `0xcc` padding at `0x0056c4c0`.

## Evidence Notes

- 2026-06-01 IDA MCP confirms `LegendPane::LegendPane` is exactly `0x0056c400-0x0056c493`; the previous bytes `0x0056c3f1-0x0056c400` and following bytes `0x0056c493-0x0056c4a0` are `0xcc` alignment.
- IDA confirms constructor xrefs from `SelfLookPane::SelfLookPane` at `0x0056571c`, `SelfLookPane2::SelfLookPane2` at `0x0056ff6e`, and `UserLookPane::UserLookPane` at `0x0059f428`.
- IDA confirms constructor-only callees `sub_4B60B0` and `sub_58DCE0`; the body uses [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` for resolution-dependent geometry, installs vtables `0x00624388`, `0x00624400`, and `0x00624430`, and initializes inherited vertical-scrollbar offset `+0x104` to `63`.
- UID0001GL/UID0000CF ScrollablePane constructor/layout/recompute evidence resolves `+0x104` as `m_verticalScrollBarOffset`; UID0003RU independently writes 49 through the same inherited LegendPane field in EPF UserLook mode. Historical `m_displayMode` was only an unresolved placeholder and is superseded without adding a LegendPane member.
- [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md) records the exact RTTI/vtable subrange between the `SpelledPane` and `GroupPane` clusters, including constructor store xrefs at `0x0056c466`, `0x0056c46e`, and `0x0056c478`.
- Because both self-look and user-look construct it, this page is a shared `ui/panels/` source root candidate rather than an attachment to either one caller. Final migration can still merge the class into a broader look/status source if stronger original-source evidence appears.
- 2026-06-11 Batch 232 IDA MCP reconfirmed constructor bounds `0x0056c400-0x0056c493`, caller refs at `0x0056571c`, `0x0056ff6e`, and `0x0059f428`, table bases `0x00624388`, `0x00624400`, `0x00624430`, store refs `0x0056c466`, `0x0056c46e`, `0x0056c478`, and the `GroupPane` boundary at `0x00624438`.
- 2026-06-15 A003 live IDA route correction confirms `0x0056c4a0` and `0x0056c4b0` are `LegendPane` vtable targets, not GroupPane-owned stubs: data refs come from `0x00624408` and `0x006243e8` inside [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md).
- 2026-06-16 A001 live IDA/PE refresh reconfirmed `sub_56C400` size `0x93`, the adjacent false-return stubs at `0x0056c4a0` and `0x0056c4b0`, the successor `GroupPane` boundary at `0x0056c4c0`, exactly three direct constructor branches from self-look/self-look2/user-look callers, one vtable-store xref to each of `0x00624388`, `0x00624400`, and `0x00624430`, no direct branches to the false stubs, and section-mapped PE pointer hits to the false stubs only from the two `LegendPane` vtable slots.
- 2026-07-04 B009 current MCP session `aa3930bd` rechecked UID0001HB for source emission: modeled function `sub_56C400` at `0x0056c400` size `0x93`, clean end at `0x0056c493`, exactly three direct callers (`0x0056571c`, `0x0056ff6e`, `0x0059f428`), only callees `0x004b60b0` and `0x0058dce0`, vtable stores from `0x0056c466`, `0x0056c46e`, `0x0056c478`, bytes/padding through the false-stub island, and generated `auto-generated/NexusTK/ui/panels/LegendPane.cpp` still empty before this callback. This supports emitting the constructor here and keeping UID00023W blank/separate.
- 2026-07-16 B001 session `64c11373` resolves UID00023W completely: primary base `0x00624388 + 0x60` points to `OnMouseEvent`, secondary EventHandler base `0x00624400 + 0x08` points to `HandleKeyOrTextEvent`, and the adjacent inherited cells retain pointer/mouse dispatch at secondary `+0x04` and TextEditPane key handling at primary `+0x64`.
- Final generated source order is: complete class declaration closed before children, UID0001HB constructor, UID00023W `HandleKeyOrTextEvent`, then UID00023W `OnMouseEvent`. Vtable/RTTI bytes and all alignment remain compiler-generated support.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | The source root now has complete class, constructor, two exact input methods, source order, vtable generation route, boundaries, shared callers, and compiler exclusions. |
| Confidence | 92 | Binary/source routing and inherited vertical-offset identity are exact. Original helper spelling and physical standalone-versus-broader source factoring remain the material caps. |

## Cross-References

- [UID:000074][LegendPane](by-class/LegendPane.md)
- [UID:00038P][LegendPaneVtables](by-type/by-vtable/LegendPaneVtables.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md)
- [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)

## Changes

- 2026-07-20 B002 UID0003RM additive source-closure callback: preserved `90/92`, FILE ownership, `NexusTK/ui/panels/`, the complete class/constructor/input union, and all source-boundary evidence; synchronized inherited `m_verticalScrollBarOffset = 63`, linked the value-49 UserLook consumer, and retained `m_displayMode` only as a superseded historical placeholder.
- 2026-07-16 B001 UID00023W accepted implementation callback:
  - Raised `86/88 -> 90/92`.
  - Replaced the false-stub blocker with exact bool `HandleKeyOrTextEvent(Event *)` and `OnMouseEvent(Event *)` contents and source order.
  - Recorded complete class closure, constructor/method ordering, exact primary/secondary slots, generated expectations, and compiler-only vtable/RTTI/padding handling while preserving shared caller and physical-source caps.
- 2026-07-04 B009 UID0001HB implementation callback:
  - Recorded UID0001HB as source-emitting through this `NexusTK/ui/panels/LegendPane.cpp` root with `LegendPane::LegendPane()` now present in the target memory page.
  - Added current MCP session `aa3930bd` facts for exact range/size, caller/callee set, vtable stores, bytes/padding, `g_useEpfAssets` geometry, `IsLegacyAssetMode()` helper use, accepted `TextEditPane` constructor route, and separate false-stub status.
  - Preserved the shared source-placement rationale and rejected exclusive SelfLookPane/SelfLookPane2/UserLookPane/GroupPane/vtable ownership.
- 2026-06-16 A001 file-completion refresh: raised `85/86 -> 86/88`.
  - Evidence: live IDA MCP reconfirmed constructor/stub/successor boundaries, three direct constructor callers, three vtable-store refs, and no direct false-stub branches; section-mapped PE scanning matched the IDA refs and found only vtable pointer hits for the false stubs.
  - Scope: source root remains `NexusTK/ui/panels/LegendPane.cpp`; final C++ stays blank because helper/base names and the standalone-versus-merged look-pane source shape remain below source-quality entry.
- 2026-06-15 A003 support correction: added [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md) to the proposed contents and replaced the stale GroupPane exclusion wording with live `LegendPane` vtable-slot evidence; score unchanged.
- 2026-06-11 Agent-A001 Batch 232: Raised from `82/84` to `85/86`.
  - Evidence: live IDA MCP reconfirmed constructor bounds/callers, vtable stores, the exact [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md) child, and the [UID:00038P][LegendPaneVtables](by-type/by-vtable/LegendPaneVtables.md) source-local vtable parent.
  - Scope: file remains `NexusTK/ui/panels/LegendPane.cpp`; no final C++ was emitted because helper/base names and standalone-versus-merged source shape remain below final-source quality.
- 2026-06-07 A010 file-source consolidation: raised `COMPLETION` from `80` to `82` and `CONFIDENCE` from `82` to `84`.
  - Evidence: integrated the exact [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md) source-declared data range, constructor store xrefs, source-placement boundaries, and neighboring [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md) boundary context into the file page.
  - Scope: no final C++ and no source-tree move. IDA MCP was unavailable in this session, so the score remains conservative and relies on existing written memory/class/vtable evidence.
- 2026-06-07 A008 alias cleanup: normalized the constructor's `byte_66DA97` geometry branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-06-01: Assigned projected path `NexusTK/ui/panels/` and raised metadata from `76/78` to `80/82`.
  - Evidence: `by-project-structure/proposed-source-tree.md` already lists `ui/panels/LegendPane.cpp`; IDA MCP confirms the exact constructor range, three look-panel constructor callers, vtable stores, resolution global refs, and surrounding padding.
  - Scope: source folder/root assignment only. The final standalone-versus-merged translation-unit question remains documented, and no reconstructed C++ is emitted.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:78`.
  - Summary/evidence: constructor role, look/status panel callers, vtable/layout anchor, and source-ownership caveat are documented; completion remains moderate because the page is concise and final ownership depends on the broader self-look/user-look split.
