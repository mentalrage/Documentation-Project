*** UID:00006O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class InterfaceEfxMgr : public Pane, public Singleton<InterfaceEfxMgr>
{
public:
    InterfaceEfxMgr();
    virtual ~InterfaceEfxMgr();

    void TriggerInterfaceEffect(int effectId);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    InterfaceEfx *m_characterEffect;
    InterfaceEfx *m_magicEffect;
    InterfaceEfx *m_itemEffect;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# InterfaceEfxMgr

## Status

- Confidence: very strong for role, direct bases, EBO/layout, legacy lifetime, fields, exact source/compiler split, and focused source route.
- Source file: [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- Address range: [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- Evidence basis: current live IDA MCP bytes/functions/xrefs/vtables/RTTI/PMDs/decompilation, current executable PE evidence, and current support docs; generated source is routing evidence only.

## Class Purpose

`InterfaceEfxMgr` manages old-layout interface visual effects. Its constructor creates persistent character, magic, and item interface effects, registers the manager hook with the shared effect scheduler, and stores [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md). It can trigger one of the persistent effects and periodically spawn randomized left/right frame effects.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0004V0][0x004e9d00-0x004e9e78.InterfaceEfxMgrConstructor](by-memory/0x004e9d00-0x004e9e78.InterfaceEfxMgrConstructor.md) | Constructs Pane mode 4, creates three persistent effects, and schedules the initial timer. |
| ordinary destructor | [UID:0004V1][0x004e9e80-0x004e9edf.InterfaceEfxMgrDestructor](by-memory/0x004e9e80-0x004e9edf.InterfaceEfxMgrDestructor.md) | Deletes persistent character, magic, and item effects; Singleton clear/vptr/base teardown remain lowering. |
| `TriggerInterfaceEffect` | [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) | If the `Shadow` graphics option byte is enabled, plays character/item/magic effects based on the legacy side-panel tab/effect id. The exact child now emits first-draft C++. |
| `OnTimer` | [UID:0004V2][0x004e9f40-0x004ea05e.InterfaceEfxMgrOnTimer](by-memory/0x004e9f40-0x004ea05e.InterfaceEfxMgrOnTimer.md) | TimerHandler virtual callback creating transient frame effects, optionally playing them, and rescheduling after 120000-299999 ms. |
| constructor EH singleton-clear cleanup funclet | [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) | Non-emitting constructor-unwind rollback glue that clears `g_pInterfaceEfxMgr` if construction fails after publishing the singleton. It is not a handwritten `ClearSingleton` source helper. |
| adjustor thunks | [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) | Compiler-generated secondary/tertiary destructor adjustors. They should be regenerated from class inheritance/vtable layout and the destructor declaration, not hand-authored. |
| scalar deleting destructor | [UID:0004V3][0x004ea090-0x004ea121.InterfaceEfxMgrScalarDeletingDestructor](by-memory/0x004ea090-0x004ea121.InterfaceEfxMgrScalarDeletingDestructor.md) | Non-emitting compiler wrapper covered by ordinary destructor/class declaration. |

## Aggregate And Child Split Status

The constructor UID0004V0, ordinary destructor UID0004V1, trigger UID00018H, OnTimer UID0004V2, compiler island UID00018I, and scalar wrapper UID0004V3 are now exact children under non-emitting split index UID00018G.

[UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) is already the exact source child for `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)` and emits first-draft C++. [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) is already the exact non-emitting compiler/EH child for constructor singleton rollback and destructor adjustor thunks.

[UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md) is false/non-emitting with blank formal C++; class-level `[[CHILDREN]]` inserts exact authored children without aggregate/compiler duplication.

## Direct Inheritance And Layout

- RTTI resolves direct `Pane` followed by empty `Singleton<InterfaceEfxMgr>`.
- GrafPort, LObject, EventHandler, and TimerHandler are transitive Pane ancestry.
- Singleton PMD `+0xf8,-1,0` overlaps `m_characterEffect` through EBO.
- Size `0x104` is proved by startup allocation and scalar free.
- Persistent fields occupy `+0xf8/+0xfc/+0x100`.
- Manager vtable views are `0x0061c63c/0x0061c688/0x0061c6b8`; TimerHandler OnTimer slot is `0x0061c6bc`.

## Source And Compiler Boundary

- Authored: constructor, ordinary destructor, TriggerInterfaceEffect, OnTimer.
- Generated: Singleton publication/clear, constructor-EH rollback, vptr stores, base teardown, adjustors, scalar wrapper, RTTI, and vtables.
- UID0002VQ, UID00018I, UID0004V3, and UID0003BS intentionally emit no source.
- Source order is class 10, semantic global 20, constructor 30, destructor 40, trigger 50, OnTimer 60.

## Owned State And Resources

| State/resource | Role |
| --- | --- |
| `g_pInterfaceEfxMgr` / `0x0069b360` | Constructor publishes the manager pointer, constructor EH cleanup and scalar deleting destructor clear it, and the legacy tab-switch UI reads it before calling `TriggerInterfaceEffect`. |
| `InterfaceEfxMgr +0xf8` | `m_characterEffect`, the persistent `CHREFX.EPD` character interface effect. Trigger ids `0` and `1` play this effect. |
| `InterfaceEfxMgr +0xfc` | `m_magicEffect`, the persistent `MAGEFX.EPD` magic interface effect. Trigger id `3` plays this effect. |
| `InterfaceEfxMgr +0x100` | `m_itemEffect`, the persistent `ITEMEFX.EPD` item interface effect. Trigger id `2` plays this effect. |
| `FRMLEFX.EPD` / `FRMREFX.EPD` | Transient left/right frame effects allocated by `0x004e9f40`; they are played only when the interface-effect option byte is enabled. |
| `g_pConfig +0x28de5e` | `Shadow` graphics option byte (`shadowEnabled` / `showShadow` descriptive name) checked by both the direct trigger helper and the periodic frame-effect spawner. |
| `dword_69B364` / `dword_69B368` | Main UI layer/context arguments passed into persistent and transient InterfaceEfx constructors. |

## Evidence Notes

- IDA `callers 0x004e9d00` reports the sole constructor call from [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f8ad8`, in the older-layout branch.
- IDA `xrefs_to 0x004e9ee0` reports a call from [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) at `0x004b880b`.
- IDA `decompile 0x004e9ee0` confirms the `Shadow` option gate and dispatch to the manager-owned `CHREFX.EPD`, `ITEMEFX.EPD`, and `MAGEFX.EPD` effects.
- IDA `xrefs_to 0x0069b360` confirms singleton writes/clears from the constructor, constructor EH cleanup funclet, and destructor.
- IDA `xrefs_to 0x004ea060` confirms the singleton-clear body is reached only through the constructor EH cleanup funclet; `xrefs_to 0x004ea06b` and `xrefs_to 0x004ea076` confirm the destructor adjustors are vtable-referenced secondary/tertiary thunks.
- Live IDA decompilation of `0x004e9d00` shows three 348-byte allocations followed by `InterfaceEfx` constructor calls for `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD`, then a scheduler add call for the manager timer subobject at `this +0xa4`.
- Live IDA decompilation of `0x004e9f40` shows allocation of `FRMLEFX.EPD` and `FRMREFX.EPD`, two `InterfaceEfx::Play` calls gated by the same client option byte, and rescheduling for `120000..299999` ms via `rand()`.
- Live IDA decompilation of `0x004ea090` shows virtual deletion of the three persistent effect pointers at `+0xf8/+0xfc/+0x100`, `g_pInterfaceEfxMgr` clear, base cleanup, and conditional storage free.
- Vtable xrefs at `0x0061c63c`, `0x0061c688`, and `0x0061c6b8` are written in the constructor and scalar deleting destructor, confirming the three-manager-vptr inherited layout.
- The following function `0x004ea130` is an `InventoryPane`-side constructor and should not be absorbed into this range.

## 2026-06-16 A001 Evidence Refresh

Live IDA MCP on database `b001_mappane_0001AW_20260616` reconfirmed the manager island. `lookup_funcs` reports the constructor at `0x004e9d00` size `0x178`, trigger helper at `0x004e9ee0` size `0x4d`, frame spawner at `0x004e9f40` size `0x11e`, singleton clear and adjustor thunks at `0x004ea060`, `0x004ea06b`, and `0x004ea076` size `0xb` each, scalar deleting destructor at `0x004ea090` size `0x91`, non-function end `0x004ea121`, and unrelated successor `0x004ea130` size `0xd2`.

Current xrefs still show one constructor call from `InitializeMainUiGraph` at `0x004f8ad8`, one trigger call from `GeneralPurposePanel` at `0x004b880b`, one vtable data ref to the frame spawner at `0x0061c6bc`, one constructor-EH call to the singleton rollback body, and vtable refs to the two destructor adjustors. `xrefs_to 0x0069b360` returns the seven singleton refs: GeneralPurposePanel read, constructor write/guard clear, constructor cleanup, EH rollback clear, scalar destructor clear, and map cleanup.

Decompilation confirms the constructor publishes `g_pInterfaceEfxMgr`, installs the three manager vtables, allocates three 348-byte `InterfaceEfx` objects for `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD`, and schedules the timer subobject at `this + 0xa4`. The frame spawner allocates `FRMLEFX.EPD` and `FRMREFX.EPD`, gates playback on `g_pConfig +0x28de5e`, then reschedules itself with `rand() % 180000 + 120000`. The destructor releases persistent effect pointers at `+0xf8/+0xfc/+0x100`, clears `g_pInterfaceEfxMgr`, tears down the base state, and conditionally frees the object.

Resource-string xrefs still distinguish manager-private and shared assets: `CHREFX.EPD` is manager-only; `MAGEFX.EPD`, `ITEMEFX.EPD`, and `INTEFX.PAD` also have InventoryPane/SpellInventoryPane consumers documented in [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md). `search_structs InterfaceEfxMgr` and `search_structs InterfaceEfx` returned no local UDT records, so final member spelling, timer callback member spelling, and one-file versus split-manager source placement remain below final-audit quality. The target [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) now uses the descriptive `m_characterEffect`, `m_magicEffect`, `m_itemEffect`, and `shadowEnabled` names as evidenced first-draft source names.

## 2026-06-20 B006 Singleton/Thunk No-Code Decision

[UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) is now treated as non-emitting compiler/EH glue while keeping this class as semantic owner. The `0x004ea060` body is a constructor EH cleanup funclet that rolls back `g_pInterfaceEfxMgr` after a failed construction path; it has no ordinary callers, no `this` access, and is not called by the scalar deleting destructor, which clears the same singleton inline at `0x004ea0e2`. The `0x004ea06b` and `0x004ea076` entries are MSVC adjustor thunks for the secondary and tertiary manager vtable views and tail-jump into `0x004ea090`.

For source reconstruction, represent this behavior through the constructor's failure/unwind semantics, the scalar deleting destructor's inline singleton clear, and the `InterfaceEfxMgr` inheritance/vtable declarations. Do not introduce `ClearInterfaceEfxMgrSingleton`, `InterfaceEfxMgr::ClearSingleton`, or raw `sub_4EA060` as source-authored methods.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | Complete declaration, direct bases, EBO/layout/size, authored child bodies, compiler exclusions, semantic global route, caller lifetime, positions, and historical corrections are represented. |
| Confidence | 94 | RTTI PMDs, allocation/free size, raw bytes, vtables, exact call operands, seven global refs, and startup/consumer/teardown behavior converge. |

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md)
- [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md)
- [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md)

## Changes

- 2026-06-20 B006 Rule 26 sync: updated the [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) method rows and evidence wording after reclassification to non-emitting compiler/EH glue. Score unchanged because the manager page already had the singleton lifecycle and vtable evidence; the update resolves source-authorship and prevents artificial clear-helper C++.
- 2026-06-17 B003 trigger-helper source-quality sync: refreshed the `TriggerInterfaceEffect` method row, persistent effect member names, and `g_pConfig +0x28de5e` wording after [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) was raised to `88/91` and populated with first-draft C++. Score unchanged because this class already covered the manager island; the update resolves target-local open questions without proving final original member spelling for the whole class.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md) because this class is 80/82 and the parent file is 86/80. Live IDA MCP on `NexusTK.exe` confirmed manager methods at `0x004e9d00`, `0x004e9ee0`, `0x004e9f40`, singleton/thunk functions `0x004ea060`, `0x004ea06b`, `0x004ea076`, scalar deleting destructor `0x004ea090`, and sole constructor caller `0x004f8ad8`.
- Completion/confidence score update: existed before as `0/0`; changed to `80/82`. Summary: old-layout effect manager role, persistent effect construction, trigger helper, random frame effect spawning, singleton/thunk/destructor handling, constructor caller, and source-split caveat are documented; confidence remains medium-strong because exact source split from `InterfaceEfx` is still open. Evidence: `InterfaceEfxAndMgr`, `InterfaceEfxMgrTriggerInterfaceEffect`, `InterfaceEfxMgrSingletonAndThunks`, `g_pInterfaceEfxMgr`, `interface-efx-resources`, and `InitializeMainUiGraph` caller evidence.
- 2026-06-06: Corrected [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) from the stale `0x004ea080` endpoint to `0x004ea081` and corrected the scalar deleting destructor end to `0x004ea121`; live IDA MCP confirmed the third adjustor is size `0xb` and the destructor includes the final `retn 4` byte at `0x004ea120`.
- 2026-06-06 A005 evidence refresh: raised completion/confidence from `80/82` to `84/86` after live IDA MCP reconfirmed manager constructor allocations, persistent effect resources and offsets, option-gated trigger/spawner behavior, random reschedule interval, scalar deleting destructor cleanup, singleton xrefs, and manager vtable xrefs; final source split from `InterfaceEfx` remains open.
- 2026-06-16 A001 target refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`.
  - Evidence: live IDA MCP on `b001_mappane_0001AW_20260616` reconfirmed function sizes, constructor/trigger/spawner/destructor xrefs, seven singleton refs, vtable refs, resource string refs, and decompiled persistent/transient effect behavior. The stale generated-source provenance line was replaced with IDA/docs-only evidence wording. Final C++ remains blank because source-facing member names and the manager-file split are still unproven after IDA type and support-doc checks.
- 2026-07-03 B011 aggregate-marker sync: clarified that the manager constructor, frame spawner, and scalar deleting destructor still reside inside [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md), while [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) already emits and [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) remains non-emitting compiler/EH glue. [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md) now uses an aggregate marker plus `[[CHILDREN]]`; exact child pages are required before the remaining manager method bodies emit formal C++.
