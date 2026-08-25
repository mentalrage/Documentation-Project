*** UID:0001XD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DialogSession Vtables

## Status

- Entity kind: source-declared/generated-binary vtable/RTTI type authority.
- Covered classes: [UID:00003U][DialogSession](by-class/DialogSession.md) and [UID:00003S][DialogInSession](by-class/DialogInSession.md).
- Likely source file: [UID:0000IU][DialogSession](by-file/DialogSession.md).
- Layout docs: [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md).
- Exact vtable-data page: [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md).
- Autogen status: non-emitting. The compiler regenerates the six vtables, COLs, RTTI hierarchies, deleting wrappers, and adjustors from [UID:00003U][DialogSession](by-class/DialogSession.md), [UID:00003S][DialogInSession](by-class/DialogInSession.md), and inherited [UID:00003T][DialogPane](by-class/DialogPane.md) declarations.
- Confidence: very strong for all bases, exact 18/11/2 and 23/11/2 extents, every slot identity, constructor/destructor stores, COLs, inheritance, thunk slots, compiler disposition, and source route.
- Verification: IDA MCP `list_globals`, `py_eval`, `xrefs_to`, `lookup_funcs`, and `disasm` checks on 2026-05-26. `wave3.py` was not executed for this pass.

## Vtable Bases

| Class | View | Base | Constructor store | Destructor stores | Object offset |
| --- | --- | --- | --- | --- | --- |
| `DialogSession` | primary | `0x00618d30` | `0x004a0dc1` | `0x004a0e9e`, `0x004a152e` | `+0x00` |
| `DialogSession` | secondary | `0x00618d7c` | `0x004a0dc7` | `0x004a0ea4`, `0x004a1534` | `+0xa0` |
| `DialogSession` | tertiary | `0x00618dac` | `0x004a0dd1` | `0x004a0eae`, `0x004a153e` | `+0xa4` |
| `DialogInSession` | primary | `0x00618db8` | `0x004a142d` | `0x004a1450`, `0x004a14a6` | `+0x00` |
| `DialogInSession` | secondary | `0x00618e18` | `0x004a1433` | `0x004a1456`, `0x004a14ac` | `+0xa0` |
| `DialogInSession` | tertiary | `0x00618e48` | `0x004a143d` | `0x004a1460`, `0x004a14b6` | `+0xa4` |

## Complete Primary Slot Maps

| Slot | DialogSession target / role | DialogInSession target / role |
| --- | --- | --- |
| `+0x00` | `0x004a1500`, scalar deleting wrapper for `virtual ~DialogSession()` | `0x004a14a0`, scalar deleting wrapper for `virtual ~DialogInSession()` |
| `+0x04` | `0x004f4b10`, `LObject::GetRuntimeClass()` | same |
| `+0x08` | `0x0041b6c0`, `LObject::OnChangeMessage(...)` default | same |
| `+0x0c` | `0x004b8e20`, `GrafPort::UpdateRenderRegion(...)` | same |
| `+0x10` | `0x0041d680`, Pane three-argument no-op extension hook | same |
| `+0x14` | `0x00544730`, `Pane::Show()` | same |
| `+0x18` | `0x00544750`, `Pane::Hide()` | same |
| `+0x1c` | `0x005447a0`, `Pane::GetParentPane()` | same |
| `+0x20` | `0x00544800`, `Pane::InvalidateRect(...)` | same |
| `+0x24` | `0x00544a20`, `Pane::GetDescription(...)` | same |
| `+0x28` | `0x00544b80`, `Pane::GetScreenBounds(...)` | same |
| `+0x2c` | `0x00544bd0`, `Pane::SetBounds(...)` | same |
| `+0x30` | `0x00544c70`, `Pane::AddToLayer(...)` | `0x0049dfd0`, `DialogPane::OnCreate(...)` |
| `+0x34` | `0x00544cb0`, `Pane::InsertInLayer(...)` | `0x00544cb0`, inherited `Pane::InsertInLayer(...)` |
| `+0x38` | `0x00544ce0`, `Pane::RemoveFromLayer()` | `0x0049e1c0`, `DialogPane::OnDestroy()` |
| `+0x3c` | `0x00544d30`, `Pane::SetPaneOrder(...)` | `0x0049e190`, `DialogPane::OnShow(...)` |
| `+0x40` | `0x00544d70`, `Pane::UnregisterEventHandler()` | `0x0049e210`, `DialogPane::OnHide()` |
| `+0x44` | `0x0041b6a0`, empty `Pane::OnPaint()` default | `0x0049f090`, `DialogPane::OnPaint()` |
| `+0x48` | table ends | `0x0041b6c0`, empty `OnControlCommand(int,int)` default |
| `+0x4c` | table ends | `0x0041b6a0`, empty `UpdateActionButton()` default |
| `+0x50` | table ends | `0x0049f1d0`, `DrawBackground()` |
| `+0x54` | table ends | `0x0049f2e0`, `DrawBorder()` |
| `+0x58` | table ends | `0x0049fc00`, `SetHoverControl(int)` |

## Complete Secondary And Tertiary Slot Maps

| Slot | DialogSession secondary | DialogInSession secondary |
| --- | --- | --- |
| `+0x00` | `0x004a1485`, `this-0xa0` destructor adjustor | `0x004a146f`, `this-0xa0` destructor adjustor |
| `+0x04` | `0x00544db0`, pointer/mouse default | `0x0049e240`, DialogPane pointer/mouse override |
| `+0x08` | `0x00544dc0`, key/text default | `0x0049e6e0`, DialogPane key/text override |
| `+0x0c` | `0x00544dd0`, IME default | `0x0049ea60`, DialogPane IME override |
| `+0x10` | `0x00544de0`, packet default | `0x0041d6b0`, inherited false packet default |
| `+0x14` | `0x00544df0`, system/control default | same |
| `+0x18` | `0x00544e00`, type-19 default | same |
| `+0x1c` | `0x004a89f0`, `ForwardHandlerOrder` | same |
| `+0x20` | `0x00544e10`, `GetLocalEventPair` | same |
| `+0x24` | `0x00544e30`, `GetScreenEventPair` | same |
| `+0x28` | `0x00544e70`, `ShouldAcceptEvent() const` | same |

- DialogSession tertiary is `0x004a1490` adjustor plus `0x00544e90` inherited true `OnTimer(int,int,int)`.
- DialogInSession tertiary is `0x004a147a` adjustor plus the same `0x00544e90` timer default.

## Extent Notes

- `DialogSession` primary table `0x00618d30` ends before secondary RTTI at `0x00618d78`.
- `DialogSession` secondary table `0x00618d7c` ends before tertiary RTTI at `0x00618da8`.
- `DialogSession` tertiary table `0x00618dac` has two slots and ends before `DialogInSession` RTTI at `0x00618db4`.
- `DialogInSession` primary table `0x00618db8` ends before secondary RTTI at `0x00618e14`.
- `DialogInSession` secondary table `0x00618e18` ends before tertiary RTTI at `0x00618e44`.
- `DialogInSession` tertiary table `0x00618e48` has two slots and ends before `DIBitmap` RTTI at `0x00618e50`.

## IDA MCP Evidence

- `list_globals *DialogSession*` reports vtable bases at `0x00618d30`, `0x00618d7c`, and `0x00618dac`, plus RTTI records at `0x00646794`, `0x006467a8`, and `0x006467bc`.
- `list_globals *DialogInSession*` reports vtable bases at `0x00618db8`, `0x00618e18`, and `0x00618e48`, plus RTTI records at `0x00646758`, `0x0064676c`, and `0x00646780`.
- `xrefs_to` the `DialogSession` table bases reports stores from constructor `0x004a0d80`, non-deleting destructor `0x004a0e70`, and scalar deleting destructor `0x004a1500`.
- `xrefs_to` the `DialogInSession` table bases reports stores from constructor `0x004a1400`, non-deleting destructor `0x004a1450`, and scalar deleting destructor `0x004a14a0`.
- `disasm` confirms the four adjustor thunks at `0x004a146f`, `0x004a147a`, `0x004a1485`, and `0x004a1490`; each subtracts the secondary/tertiary subobject offset and jumps to the owning scalar deleting destructor.
- Older generated metadata notes said `vtable_count: 0`; B002's 2026-06-19 recheck found current `class_DialogSession.meta_wave3` and `class_DialogInSession.meta_wave3` both report three vtables. IDA-confirmed table bases and store xrefs remain the authority.

## Reconstruction Notes

Keep `DialogSession` and `DialogInSession` in one source module unless later historical source evidence proves a split. `DialogSession` is directly `Pane`-derived, while `DialogInSession` is directly `DialogPane`-derived; EventHandler and TimerHandler facets at `+0xa0/+0xa4` are inherited through Pane. Their concrete state offsets are recorded in [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md).

The four adjustor thunks and two scalar deleting wrappers are compiler ABI glue caused by ordinary virtual destructors and the multiple-inheritance layout. Do not emit literal vtable/RTTI/COL/base-array source, explicit vptr stores, adjustor arithmetic, deletion flags, or deleting-wrapper bodies.

## Ownership And Non-Emission Rationale

- Keep canonical owner [UID:0000IU][DialogSession](by-file/DialogSession.md) because this type page spans both source classes in one module.
- Keep `RECONSTRUCTABLE:FALSE`, blank emitters, and blank formal C++. Source emission belongs to the two class declarations and exact method children.
- The exact backing data remains owned by this type page through UID0002NB, but ownership does not imply handwritten source emission.
- Rejected alternatives are literal ABI arrays, a new `DialogSessionVtables.cpp`, six artificial source children, and ownership by only one of the two classes.

## Cross-References

- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:00003U][DialogSession](by-class/DialogSession.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md)
- [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md)

## Changes

- 2026-07-16 B004 UID0002NB accepted implementation callback:
  - Changed `86/90 -> 92/94`, `RECONSTRUCTABLE:TRUE -> FALSE`, and cleared emitter routing while retaining owner UID0000IU and blank managed C++.
  - Added the complete primary/secondary/tertiary slot maps, exact inherited method identities, `GetParentPane` correction, false packet default, COL/object-offset inheritance, source-declaration route, and no-handwritten-ABI proof.
  - Updated the backing child to renamed [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md) and preserved all earlier store/thunk/extent history as historical support.

- 2026-06-07 parent attachment update:
  - What existed before: the page had strong vtable evidence and an exact by-memory child, but no autogen parent, so generated output left the cluster unassigned.
  - Changed to: `COMPLETION:86` and `AUTOGEN_PARENT_UID:0000IU`, with an explicit file-level parent rationale.
  - Summary/evidence: the cluster spans both `DialogSession` and `DialogInSession`, while [UID:0000IU][DialogSession](by-file/DialogSession.md) documents that shared source module and clears the attachment gate; final C++ remains blank because the vtable page is below the `95/95` reconstruction threshold.
- 2026-06-20 B002 Rule 26 incorporation: no score change; corrected stale generated-metadata wording and documented that vtables should be regenerated from class declarations instead of hand-authored raw data.
- 2026-05-31 exact child split:
  - What existed before: the page had `COMPLETION:0`, `CONFIDENCE:0`, blank reconstructability metadata, and no exact `by-memory` vtable-data child.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, and the exact [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md) child page.
  - Summary/evidence: 2026-05-31 IDA MCP `list_globals`, `lookup_funcs`, `xrefs_to`, and dword reads reconfirm the six table bases, constructor/destructor store xrefs, destructor-adjustor thunk targets, key slots, and `0x00618e50` boundary before `DIBitmap` RTTI; score remains below `95+` because final source declarations and session helper names still need a broader final-source audit.
