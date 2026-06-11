*** UID:00003S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DialogInSession

## Status

- Confidence: strong.
- Likely source file: [UID:0000IU][DialogSession](by-file/DialogSession.md)
- Address range: [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- Current recovered file: `source-3/simroot_v2/class_DialogInSession.cpp`
- Type docs: [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- Vtables: [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md), exact data [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md)
- Direct autogen parent: [UID:0000IU][DialogSession](by-file/DialogSession.md)

## Class Purpose

`DialogInSession` is the base for dialogs managed by a `DialogSession`. It derives from `DialogPane`, stores a session data pointer/value at `+0x270`, stores a dialog type byte at `+0x26c`, and installs vtables used by session-bound dialog subclasses.

See [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) for the `DialogPane` base and derived tail offsets.

## Method Notes

| Method or range | Address | Role |
| --- | --- | --- |
| `DialogInSession` | `0x004a1400-0x004a144e` | Constructs the `DialogPane` base with a blank title and stores session data/dialog type. |
| non-deleting destructor | `0x004a1450-0x004a146f` | Resets `DialogInSession` vtables and destroys the `DialogPane` base. |
| destructor thunks | `0x004a146f-0x004a1485` | Secondary and tertiary adjustor thunks forwarding to `0x004a14a0`. |
| scalar deleting destructor | `0x004a14a0-0x004a14f5` | Resets vtables, destroys `DialogPane`, and conditionally deletes the object. |

## Vtable Evidence

| View | Vtable | Key slots |
| --- | --- | --- |
| primary | `0x00618db8` | Scalar deleting destructor `0x004a14a0` at `+0x00`, inherited `DialogPane` slots through `+0x58`. |
| secondary | `0x00618e18` | Adjustor thunk `0x004a146f` at `+0x00`, inherited dialog secondary-view slots including `0x0049e240`, `0x0049e6e0`, and `0x0049ea60`. |
| tertiary | `0x00618e48` | Adjustor thunk `0x004a147a` at `+0x00`, base event slot `0x00544e90` at `+0x04`. |

The constructor stores these vtables at `0x004a142d`, `0x004a1433`, and `0x004a143d`. The non-deleting destructor and scalar deleting destructor reinstall the same three vtables before base cleanup.

## Supporting Exact Evidence

- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) records the exact `0x004a1400-0x004a14f5` constructor/destructor/deleting-destructor subrange, the `DialogPane` base construction, tail writes at `+0x26c/+0x270`, vtable stores, and the surrounding `DialogSession` physical island.
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) records the `DialogInSession` tail layout and explicitly warns that `+0x26c/+0x270` are derived-tail fields, not base `DialogPane` state.
- [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md) records the primary, secondary, and tertiary `DialogInSession` vtable bases, slot extents, destructor adjustor thunks, and boundary before `DIBitmap` RTTI.

## Evidence Notes

- IDA MCP confirms `0x004a1400`, `0x004a1450`, `0x004a146f`, `0x004a147a`, and `0x004a14a0`.
- `xrefs_to 0x004a1400` shows direct construction from several bulletin/session dialog constructors.
- 2026-05-25 IDA checks show board/article deleting-destructor wrappers such as `ArticleDialog` `0x0047e950`, `ArticleListDialog` `0x0047e990`, `BulletinDialog` `0x0047ea10`, and `NewPredefinedFormArticleDialog` `0x0047ec30` all call this class's non-deleting destructor at `0x004a1450`.
- Disabled generated output lists `0x004a146f` as missing code, but IDA confirms it is a real `0xb` thunk forwarding to `0x004a14a0` with `this - 0xa0`.
- Active generated output emits a `DeletingDtorFn` alias using `BackGroundPane`; treat that as broad generated alias pollution, not source ownership evidence.
- Current Wave3 metadata reports `vtable_count: 0` for `DialogInSession` despite IDA-confirmed constructor/destructor stores for all three vtables.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000IU][DialogSession](by-file/DialogSession.md). This class is scored `85/88`, and the direct file parent is scored `86/86`, so both sides clear the corrected 85/85 gate. The relationship is direct because `DialogInSession` is the session-bound dialog base documented by the `DialogSession` source root, shares the exact [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) memory island, and shares the [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md) table cluster with `DialogSession`.

## Score Rationale

- Completion is `85` because the page now records purpose, base/tail layout, constructor/destructor/scalar-destructor methods, adjustor thunks, exact vtable views, support pages, generated alias caveats, and parent-gate reasoning.
- Confidence is `88` because class identity, layout offsets, vtable stores, destructor paths, and file ownership are corroborated by the exact memory, vtable-data, layout, and file-root pages. It remains below final confidence because source-facing tail field names and final declarations are still provisional.

## Cross-References

- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:00003U][DialogSession](by-class/DialogSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md)
- [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md)
- [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:00001C][BulletinDialog](by-class/BulletinDialog.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md)

## Changes

- 2026-06-07 A003 Batch 084 class parent-gate update:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000IU`.
  - Summary/evidence: added supporting exact evidence, assignment gate, and score rationale. Assignment to [UID:0000IU][DialogSession](by-file/DialogSession.md) is justified because the child is `85/88`, the direct file parent is `86/86`, and the exact memory/type pages document the `DialogInSession` constructor/destructor island, `+0x26c/+0x270` tail fields, and three vtable views.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/86`.
  - Summary/evidence: class role, tail layout, constructor/destructor/thunks, vtable stores, direct construction/destruction evidence, generated alias caveat, and session/dialog cross-references are documented; remaining work is mainly final source-facing names for session tail fields.
- 2026-05-31 reconstructability:
  - Before: `RECONSTRUCTABLE` was blank.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the `DialogInSession` constructor/destructor/vtable stores and construction xrefs from bulletin/session dialogs. Parent/code autogen remains blank because final declarations and tail field names are not at near-final confidence.
