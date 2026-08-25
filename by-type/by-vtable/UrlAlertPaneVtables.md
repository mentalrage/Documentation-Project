*** UID:0001YZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UrlAlertPane vtable cluster generated from the UrlAlertPane class declaration and method bodies.
// Constructor/destructor/thunk behavior belongs to the class and executable method pages, not raw dwords.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UrlAlertPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md).
- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
- Confidence: strong for vtable bases, constructor/destructor stores, confirm slot, and thunk identities.
- Exact memory child: [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md).
- Autogen status: attached to the `UrlAlertPane` class page; this vtable-data/type page remains C++ blank because the table bytes are compiler-generated from the class declaration and executable method bodies, not hand-authored source.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x0062e584` | `0x00599aac` | `+0x00` | Installed after `AlertPane` base construction and singleton setup. |
| secondary | `0x0062e5ec` | `0x00599ab2` | `+0xa0` | Secondary dialog/input view. |
| tertiary | `0x0062e61c` | `0x00599abc` | `+0xa4` | Event/update-handler view. |

The same three vtables are reinstalled by the non-deleting destructor at `0x00599b20-0x00599b92` and the scalar deleting destructor at `0x00599c00-0x00599cb3`.

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x0062e584` | `+0x00` | `0x00599c00` | `UrlAlertPane::ScalarDeletingDestructor`. |
| primary `0x0062e584` | `+0x44` | `0x0049f090` | Inherited dialog focus/selection drawing virtual. |
| primary `0x0062e584` | `+0x48` | `0x004a0580` | Inherited `AlertPane::DismissDialog` action-dispatch path. |
| primary `0x0062e584` | `+0x50` | `0x0049f1d0` | Inherited dialog content drawing virtual. |
| primary `0x0062e584` | `+0x54` | `0x0049f2e0` | Inherited dialog border drawing virtual. |
| primary `0x0062e584` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| primary `0x0062e584` | `+0x5c` | `0x00599ba0` | Formal source override `UrlAlertPane::OnPrimaryButton`; semantic confirm handler that opens the stored URL and optionally exits. |
| primary `0x0062e584` | `+0x60` | `0x0041b6a0` | Base no-op/guard secondary callback slot. |
| secondary `0x0062e5ec` | `+0x00` | `0x00599bdb` | Compiler-generated adjustor thunk into scalar deleting destructor with `this - 0xa0`; no handwritten C++ body. |
| tertiary `0x0062e61c` | `+0x00` | `0x00599be6` | Compiler-generated adjustor thunk into scalar deleting destructor with `this - 0xa4`; no handwritten C++ body. |
| tertiary `0x0062e61c` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x64` as a `UrlAlertPane` virtual: it is RTTI metadata for the secondary table at `0x0062e5ec`. Likewise, secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` belongs to the following `UserInfoDialogPane` RTTI region.

## IDA MCP Evidence

- IDA MCP `py_eval` on 2026-06-01 confirms the exact RTTI-adjacent data range `0x0062e580-0x0062e624`: `0x0062e580`, `0x0062e5e8`, and `0x0062e618` point to `UrlAlertPane` RTTI records, while `0x0062e624` points to the following `UserInfoDialogPane` RTTI record and is outside this item.
- `list_globals *UrlAlertPane*` reports vtables at `0x0062e584`, `0x0062e5ec`, and `0x0062e61c`, plus RTTI records at `0x00651a74`, `0x00651b2c`, and `0x00651b40`.
- `xrefs_to` the three vtable bases reports constructor stores at `0x00599aac`, `0x00599ab2`, and `0x00599abc`, non-deleting destructor stores at `0x00599b45`, `0x00599b4b`, and `0x00599b55`, and scalar deleting destructor stores at `0x00599c2c`, `0x00599c32`, and `0x00599c3c`.
- `lookup_funcs` confirms `0x00599a40`, `0x00599b20`, `0x00599ba0`, `0x00599bd0`, `0x00599bdb`, `0x00599be6`, and `0x00599c00` as function starts. `0x00599bd0` is not a vtable thunk; it is a tiny singleton-clear helper used from constructor exception cleanup.
- `xrefs_to 0x00599ba0` reports a primary-vtable data ref at `0x0062e5e0`.
- `xrefs_to 0x00599bdb` and `0x00599be6` report secondary/tertiary vtable data refs at `0x0062e5ec` and `0x0062e61c`.
- `xrefs_to 0x00599a40` reports constructor calls from `0x00503034`, `0x00513f7e`, and `0x0051402f`.
- `0x0062e624` points to `??_R4UserInfoDialogPane@@6B@`, followed by `??_7UserInfoDialogPane@@6B@` at `0x0062e628`, proving that the URL alert vtable cluster ends before `0x0062e624`.
- 2026-06-21 B011 source-quality pass resolves the primary `+0x5c` target's formal source name as `UrlAlertPane::OnPrimaryButton()` to match the base [UID:00000B][AlertPane](by-class/AlertPane.md) declaration. `OnConfirm` remains a behavior alias in prose only. The same pass confirms that `0x00599bd0` is constructor-unwind cleanup, `0x00599bdb/0x00599be6` are pure adjustor thunks, and `0x00599c00-0x00599cb3` is scalar deleting destructor glue regenerated from `virtual ~UrlAlertPane()`.

## Reconstruction Notes

Model `UrlAlertPane` as an `AlertPane` subclass with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. The class-specific data extends the base alert object with `char *m_url` at `+0x270` and `bool m_exitAfterOpen` at `+0x274`.

Keep `0x00599bd0` separate from the vtable thunks. It clears [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md) and is reached from constructor exception cleanup, while `0x00599bdb` and `0x00599be6` are the actual adjustor thunks.

Do not emit standalone vtable C++ here. The source declaration on [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md), the executable method bodies on [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md), and the virtual destructor/`OnPrimaryButton` override regenerate this vtable cluster.

## Parent Rationale

Attach this vtable cluster to [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) because the three tables are installed by the URL alert constructor and destructors, and the primary-table `+0x5c` slot is the class-specific `UrlAlertPane::OnPrimaryButton` / confirm-handler behavior. The class page is reconstructable, attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md), and documents the same exact [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) child range, `m_url`/`m_exitAfterOpen`, singleton, and constructor xrefs.

## Cross-References

- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable cluster was reconstructable but unassigned in generated type coverage even though the `UrlAlertPane` class and `AlertPanes` file roots were already parent-ready.
  - What changed: attached the vtable cluster to [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md), raised completion to `86`, and added an explicit parent rationale.
  - Summary/evidence: constructor/destructor stores at the three vtable bases, confirm-handler slot `0x00599ba0`, destructor adjustor-thunk slots, and exact [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) prove class ownership; C++ remains blank because inherited slot naming and final declarations are below the final-source gate.

- 2026-06-21 B011 source-quality incorporation:
  - Score unchanged at `86/90`.
  - Replaced formal `OnConfirm` wording with `UrlAlertPane::OnPrimaryButton` while retaining confirm-handler as a semantic alias, added no-code proof for adjustor/deleting-destructor glue, and recorded that this type page stays blank because vtable bytes are compiler-generated from the class declaration and method bodies.
- 2026-06-30 B011 empty-emitter implementation:
  - Score and metadata unchanged at `86/90`, owner/emitter [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md).
  - Added the formal vtable-cluster no-code marker. It preserves constructor callers `0x00503034`, `0x00513f7e`, and `0x0051402f`, inherited slot policy, formal `OnPrimaryButton`, destructor/thunk glue classification, exact memory child route, and no raw dword/source-array policy.

- What existed before: this page listed the three vtable bases and slot evidence, but kept completion/confidence at `0/0`, cited incomplete Wave3 metadata, and did not have a precise by-memory child range.
- What changed: completion/confidence is now `84/90`, `RECONSTRUCTABLE` is marked `TRUE`, the stale Wave3 caveat was replaced with IDA MCP boundary evidence, and the exact child range [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) was added.
- Evidence: IDA MCP `py_eval` on 2026-06-01 read the RTTI/vtable dwords and xrefs at `0x0062e580-0x0062e624`, with `UserInfoDialogPane` RTTI beginning at `0x0062e624`.
