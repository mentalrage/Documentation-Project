*** UID:000074 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class LegendPane : public TextEditPane
{
public:
    LegendPane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LegendPane

## Status

- Confidence: very strong for constructor bounds, behavior, callers, three vtable views, exact input-override slots, complete declaration/source order, and shared `ui/panels/` placement; strong for final original field/helper spelling.
- Likely source file: [UID:0000KM][LegendPane](by-file/LegendPane.md), with a documented broader look-pane split caveat.
- Address range: [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- Current recovered file: `source-3/simroot_v2/class_LegendPane.cpp`
- Vtable/layout anchor: [UID:00038P][LegendPaneVtables](by-type/by-vtable/LegendPaneVtables.md)

## Class Purpose

`LegendPane` is a small read-only legend/key child pane used by look-panel views. The constructor chooses resolution-dependent geometry, initializes the common pane/text-edit base, installs `LegendPane` vtables, and stores inherited `m_verticalScrollBarOffset = 63` at offset `0x104`. UID0001HB is source-ready as `LegendPane::LegendPane()`; the older `m_displayMode` token is a superseded placeholder, not a separate LegendPane field.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x0056c400-0x0056c493` | Source-ready `LegendPane::LegendPane()` (`88/91`): calls `TextEditPane` with `g_useEpfAssets` geometry, passes `IsLegacyAssetMode()` through the word argument, and sets inherited `m_verticalScrollBarOffset` at `this+0x104` to `63`. |
| `HandleKeyOrTextEvent` | `0x0056c4a0-0x0056c4a5` | Protected EventHandler secondary `+0x08` override; accepts one Event pointer, ignores it, and returns false. |
| `OnMouseEvent` | `0x0056c4b0-0x0056c4b5` | Protected primary `+0x60` override reached by inherited ScrollablePane pointer/mouse fallback; accepts one Event pointer, ignores it, and returns false. |

## Evidence Notes

- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md) records IDA-confirmed exact bounds, raw bytes, surrounding `0xcc` padding, the [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` resolution branch, `sub_4B60B0` and `sub_58DCE0` callees, and the `this+0x104 = 63` state write.
- UID0001GL/UID0000CF ScrollablePane constructor/layout/recompute evidence fixes inherited `+0x100/+0x104/+0x108` as horizontal offset, vertical offset, and trailing inset. UID0003RU independently writes value 49 through this same LegendPane `+0x104` field in EPF mode, confirming the constructor's value 63 is an instance-specific vertical-scrollbar offset rather than display mode.
- IDA caller/xref checks in the memory page confirm exactly three direct constructor callers: `SelfLookPane::SelfLookPane` at `0x0056571c`, `SelfLookPane2::SelfLookPane2` at `0x0056ff6e`, and `UserLookPane::UserLookPane` at `0x0059f428`.
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) records `LegendPane` vtable bases at `0x00624388`, `0x00624400`, and `0x00624430`; current generated metadata reporting no vtables is a Wave3 data issue, not source-layout evidence.
- [UID:0000KM][LegendPane](by-file/LegendPane.md) has a valid `NexusTK/ui/panels/` reconstruction path and documents why `LegendPane` is a shared look/status child instead of being exclusively owned by either self-look or user-look source.
- 2026-06-11 Batch 232 IDA MCP reconfirmed `LegendPane` constructor bounds `0x0056c400-0x0056c493`, caller refs from `SelfLookPane`, `SelfLookPane2`, and `UserLookPane`, table bases `0x00624388`, `0x00624400`, `0x00624430`, store refs `0x0056c466`, `0x0056c46e`, `0x0056c478`, and the `GroupPane` boundary at `0x00624438`.
- 2026-06-15 A003 live IDA route correction confirms [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md) is `LegendPane`-owned: `0x0056c4a0` has a data ref from slot `0x00624408`, `0x0056c4b0` has a data ref from slot `0x006243e8`, and both slots are inside [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md).
- 2026-06-16 A001 live IDA/PE refresh reconfirmed the constructor function object at `0x0056c400` size `0x93`, false-return stub function objects at `0x0056c4a0` and `0x0056c4b0` size `0x5`, successor `GroupPane` start `0x0056c4c0`, exactly three direct constructor branches from `0x0056571c`, `0x0056ff6e`, and `0x0059f428`, one constructor-store xref to each `LegendPane` vtable view, and no PE VA/RVA/direct-branch hits to the false stubs outside their vtable slots.
- 2026-07-04 B009 implementation callback records UID0001HB as source-ready at `88/91`: current MCP session `aa3930bd` reconfirmed `sub_56C400` at `0x0056c400` size `0x93`, clean end at `0x0056c493`, exact callers `0x0056571c`, `0x0056ff6e`, `0x0059f428`, callees `0x004b60b0` / `IsLegacyAssetMode` and `0x0058dce0` / `TextEditPane`, vtable stores at `0x0056c466`, `0x0056c46e`, `0x0056c478`, full bytes/padding, and separate false-stub starts at `0x0056c4a0` and `0x0056c4b0`. The constructor body now emits through the target memory page; the class declaration is limited to `LegendPane();` plus children and does not invent unrelated fields.
- 2026-07-16 B001 live MCP session `64c11373` resolves the two former generic stubs independently. Primary vtable base `0x00624388 + 0x60` points to `LegendPane::OnMouseEvent`; secondary EventHandler base `0x00624400 + 0x08` points to `LegendPane::HandleKeyOrTextEvent`. Adjacent inherited cells retain the ScrollablePane pointer/mouse dispatcher at secondary `+0x04` and TextEditPane key handler at primary `+0x64`.
- The two functions have separate starts and sole vtable xrefs, so they are distinct source overrides rather than one folded/default implementation. Both use AL-only false returns and `retn 4`, supporting `bool` plus one `Event *` argument.
- Class source order is declaration, UID0001HB constructor, then UID00023W key/text and mouse definitions. The class closes before `[[CHILDREN]]`; qualified method definitions must never be nested inside the class body.

## Autogen Status

- Reconstructable: true for the class and constructor semantics.
- Parent: [UID:0000KM][LegendPane](by-file/LegendPane.md), the current shared `ui/panels/LegendPane.cpp` source bucket.
- Code: the complete bounded class declaration is present here. UID0001HB emits the constructor body and UID00023W emits the two accepted input-override definitions after the class closes.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | The page now carries a complete source-legal declaration, closes the class before child definitions, and documents the constructor plus both exact input overrides, source order, slot/facet behavior, ownership, and compiler-data exclusions. |
| Confidence | 93 | Constructor, callers, vtable views, slot identities, ABI, inherited vertical-offset identity, and generated source route are exact. Original helper/global spelling and physical header/file factoring remain lexical confidence caps. |

## Cross-References

- [UID:0000KM][LegendPane](by-file/LegendPane.md)
- [UID:00038P][LegendPaneVtables](by-type/by-vtable/LegendPaneVtables.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md)
- [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)

## Changes

- 2026-07-20 B002 UID0003RM additive source-closure callback: preserved `91/93`, owner/emitter UID0000KM, reconstructable state, complete declaration, source order, and all constructor/input evidence; synchronized `+0x104` to inherited `m_verticalScrollBarOffset`, linked the independent value-49 UserLook consumer, and historicalized the former `m_displayMode` placeholder.
- 2026-07-16 B001 UID00023W accepted implementation callback:
  - Raised `86/89 -> 91/93`.
  - Replaced the constructor-only class shell with the complete bounded declaration containing protected bool `HandleKeyOrTextEvent(Event *)` and `OnMouseEvent(Event *)`.
  - Closed the class before `[[CHILDREN]]`, documented exact primary/secondary slots and source order, and preserved all constructor, caller, `m_displayMode`, owner/emitter, and historical evidence.
- 2026-07-04 B009 UID0001HB implementation callback:
  - Added a minimal `LegendPane : public TextEditPane` declaration with `LegendPane();` and `[[CHILDREN]]`.
  - Recorded UID0001HB as source-ready `88/91` through `LegendPane::LegendPane()` in the target memory page, with `g_useEpfAssets` geometry, `IsLegacyAssetMode()` helper use, accepted `TextEditPane` constructor shape, and placeholder `m_displayMode` for observed `this+0x104 = 63`.
  - Preserved support boundaries: false virtual stubs remain separate/blank until slot names are accepted; vtable data remains generated-binary support; SelfLookPane, SelfLookPane2, UserLookPane, and GroupPane are not constructor owners.
- 2026-06-16 A001 file-completion support refresh: raised `85/88 -> 86/89`.
  - Evidence: live IDA MCP reconfirmed constructor/stub/successor function records, xrefs, vtable stores, and decompilation; section-mapped PE scanning found the three constructor branches and only vtable pointer hits for the false stubs.
  - Scope: owner/emitter remain [UID:0000KM][LegendPane](by-file/LegendPane.md); C++ stays blank because final helper/base names and standalone-versus-merged source placement remain unresolved.
- 2026-06-15 A003 support correction: added the `0x0056c4a0-0x0056c4b5` false virtual stubs as `LegendPane` methods after live IDA showed their only data refs are `LegendPane` vtable slots `0x00624408` and `0x006243e8`; score unchanged.
- 2026-06-11 Agent-A001 Batch 232: Raised from `82/86` to `85/88`.
  - Before: the class cleared confidence but not completion for the strict parent gate, and the source-local vtable page remained blocked on this parent.
  - After: added current live IDA evidence for constructor callers, vtable stores, exact vtable child routing, and the source-local [UID:00038P][LegendPaneVtables](by-type/by-vtable/LegendPaneVtables.md) parent.
  - Evidence: live IDA MCP reconfirmed constructor bounds/callers, the three `LegendPane` table bases, constructor stores, and the `GroupPane` boundary; [UID:0000KM][LegendPane](by-file/LegendPane.md) now clears at `85/86`.
- 2026-06-07 A008 alias cleanup: normalized the constructor's `byte_66DA97` resolution branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- Completion/confidence score update: existed before as `0/0`; changed to `72/74`. Summary: the small constructor-only class has clear behavior, vtable family, geometry, and caller evidence, but final source-file ownership remains only medium confidence. Evidence: constructor range, look-pane xrefs, `UserLookPane` storage evidence, and self-look path caveat.
- 2026-06-03 source-owner and score update:
  - What existed before: the page was scored `72/74`, had no reconstructable/autogen parent metadata, and summarized vtable/caller evidence indirectly.
  - Changed to: scores `82/86`; `RECONSTRUCTABLE:TRUE`; parent [UID:0000KM][LegendPane](by-file/LegendPane.md) at position `5`; C++ block remains empty.
  - Summary/evidence: exact memory documentation, source-root placement, and look-pane vtable-family documentation now support stronger class metadata. Final source C++ remains gated by unresolved helper/base names and the standalone-versus-merged look-pane source split.
