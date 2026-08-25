*** UID:0001Y6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ModelessDialogPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md).
- Likely source file: [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md).
- Layout docs: [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md).
- Exact memory page: [UID:00036P][0x00618c44-0x00618ce0.ModelessDialogPaneVtableData](by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md).
- Autogen parent: [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md), which already clears the strict gate and routes to [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md).
- Confidence: very strong for vtable bases, constructor stores, method slots, and table extents.
- Verification: IDA MCP `list_globals`, `py_eval`, `xrefs_to`, `lookup_funcs`, and `disasm` checks on 2026-05-26/2026-06-11, plus B015 raw PE source-quality recheck on 2026-06-22. Wave3 `vtable_count:0` is known stale for this class.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00618c48` | `0x004a07bd` | `+0x00` | Primary `DialogPane`/pane view for the modeless dialog object. |
| secondary | `0x00618ca8` | `0x004a07c4` | `+0xa0` | Event/input view passed to `EventDispatcher::AddToModalList`. |
| tertiary | `0x00618cd8` | `0x004a07ca` | `+0xa4` | Short event/update-handler view matching the common pane/DialogPane ABI. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00618c48` | `+0x00` | `0x0048c350` | Reused `DialogPane` scalar deleting destructor. `ModelessDialogPane` has no class-specific destructor body identified in this pass. |
| primary `0x00618c48` | `+0x30` | `0x0049dfd0` | Inherited dialog bounds/layout initialization virtual. |
| primary `0x00618c48` | `+0x3c` | `0x0049e190` | Inherited dialog show/list registration behavior. |
| primary `0x00618c48` | `+0x44` | `0x0049f090` | Inherited dialog focus/selection drawing virtual. |
| primary `0x00618c48` | `+0x50` | `0x0049f1d0` | Inherited dialog content drawing virtual. |
| primary `0x00618c48` | `+0x54` | `0x0049f2e0` | Inherited dialog border drawing virtual. |
| primary `0x00618c48` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| secondary `0x00618ca8` | `+0x00` | `0x0048c27b` | `DialogPane` secondary destructor adjustor thunk, subtracts `0xa0` then jumps to `0x0048c350`. |
| secondary `0x00618ca8` | `+0x04` | `0x004a0840` | `ModelessDialogPane::HandlePointerOrMouseEvent(Event *)`. |
| secondary `0x00618ca8` | `+0x08` | `0x004a0830` | `ModelessDialogPane::IsModal`, returns false. |
| secondary `0x00618ca8` | `+0x1c` | `0x004a89f0` | Shared dialog/event-support slot inherited from nearby dialog infrastructure. |
| tertiary `0x00618cd8` | `+0x00` | `0x0048c286` | `DialogPane` tertiary destructor adjustor thunk, subtracts `0xa4` then jumps to `0x0048c350`. |
| tertiary `0x00618cd8` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

The primary table ends before the secondary RTTI dword at `0x00618ca4`; the secondary table ends before the tertiary RTTI dword at `0x00618cd4`; the tertiary table ends before the neighboring data/string region at `0x00618ce0`. Do not treat `0x00618ce0` or following `DLGFRAME.*` string data as additional `ModelessDialogPane` virtual slots.

## IDA MCP Evidence

- `list_globals *ModelessDialogPane*` reports vtable bases at `0x00618c48`, `0x00618ca8`, and `0x00618cd8`, plus RTTI records at `0x006466d0`, `0x00646730`, and `0x00646744`.
- `xrefs_to` the three vtable bases reports constructor stores at `0x004a07bd`, `0x004a07c4`, and `0x004a07ca` inside `0x004a0760`.
- `xrefs_to 0x004a0840` reports the secondary-table data ref at `0x00618cac`; `xrefs_to 0x004a0830` reports the secondary-table data ref at `0x00618cb0`.
- `lookup_funcs` confirms `0x004a0760`, `0x004a0830`, `0x004a0840`, `0x0048c350`, `0x0048c27b`, and `0x0048c286` as function starts.
- `disasm` confirms the constructor writes the three vtables, then calls dialog bounds init `0x0049dfd0`, pane interaction init `0x00544d30`, and event-dispatcher registration `0x004a6fc0` with `this + 0xa0`.
- Current Wave3 metadata for `class_ModelessDialogPane.meta_wave3` reports `vtable_count: 0`, so the generated vtable inventory is incomplete despite active constructor code assigning the three symbolic vtables.
- 2026-05-31 IDA MCP recheck confirms the constructor stores the same three vtable bases and that secondary slots at `0x00618cac` and `0x00618cb0` point to the method now named `HandlePointerOrMouseEvent` and to `IsModal`. `get_u32` confirms `0x00618ca8` starts with `0x0048c27b`, followed by `0x004a0840` and `0x004a0830`; `0x00618cd8` starts with `0x0048c286`, followed by `0x00544e90`.
- 2026-06-11 live IDA MCP recheck against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) confirms the exact [UID:00036P][0x00618c44-0x00618ce0.ModelessDialogPaneVtableData](by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md) child range. `lookup_funcs` reports stable bounds for constructor `0x004a0760-0x004a0827`, `IsModal` `0x004a0830-0x004a0835`, `HandleMouseEvent` `0x004a0840-0x004a0c8e`, inherited destructor/adjustor slots, and default event slot `0x00544e90-0x00544e95`. `xrefs_to` reports constructor stores at `0x004a07bd`, `0x004a07c4`, and `0x004a07ca`, plus secondary-table refs to `HandleMouseEvent` and `IsModal` at `0x00618cac` and `0x00618cb0`.
- 2026-06-11 A003 supervisor-row recheck against the same IDB MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed constructor `0x004a0760-0x004a0827`, `IsModal` `0x004a0830-0x004a0835`, `HandleMouseEvent` `0x004a0840-0x004a0c8e`, `DialogPane` adjustor thunks `0x0048c27b-0x0048c291`, and default event slot `0x00544e90-0x00544e95`. It also re-read the primary table dwords starting `0x0048c350`, the secondary table dwords `0x0048c27b`, `0x004a0840`, `0x004a0830`, `0x0049ea60`, and the tertiary table dwords `0x0048c286`, `0x00544e90`, followed by `0x004c0044` at `0x00618ce0`, confirming the following dword is outside the tertiary table.
- B015 raw PE scan confirms the generated `vtable_count:0` metadata is stale: constructor stores are the only immediate references to primary `0x00618c48` at `0x004a07bd`, secondary `0x00618ca8` at `0x004a07c4`, and tertiary `0x00618cd8` at `0x004a07ca`; `IsModal` and `HandleMouseEvent` have only secondary-table VA refs at `0x00618cb0` and `0x00618cac`; and `0x00618ce0` is adjacent data/string material, not a third tertiary slot.

## Assignment Gate

This vtable cluster is assigned to [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md). It is a single-class, three-view vtable family: the RTTI records name `ModelessDialogPane`, the constructor installs all three table bases, and the secondary table owns the class-specific `HandlePointerOrMouseEvent` and `IsModal` slots. The direct class parent is `93/94` and routes to the `92/92` [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md) source root, so the strict child/direct-parent gate is satisfied. The exact `.rdata` child [UID:00036P][0x00618c44-0x00618ce0.ModelessDialogPaneVtableData](by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md) routes to this by-vtable page.

## Reconstruction Notes

Model `ModelessDialogPane` as a `DialogPane` subclass with the common three-vtable pane layout at `+0x00`, `+0xa0`, and `+0xa4`. Its class-specific behavior is concentrated in the constructor, `IsModal`, and secondary-table mouse-event handler. The handler's state accesses are secondary-view relative and map back to inherited `DialogPane` offsets, as recorded in [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md). The destructor slots are inherited `DialogPane` ABI support and should be linked to [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md), not reconstructed as standalone handwritten `ModelessDialogPane` methods.

B015 keeps this vtable page source-declared/generated-binary: do not hand-author vtable dwords, RTTI/COL records, or adjustor thunk bodies. The final `ModelessDialogPane` declaration plus child constructor/virtual methods should regenerate these records.

## UID000312 Canonical Slot Closure

- Secondary slot `0x00618cac` is the canonical `HandlePointerOrMouseEvent(Event *)` override. The physical target receives the EventHandler subobject at complete-object `+0xa0`; that ABI view does not change the source declaration.
- The three-view contract is unchanged: primary `0x00618c48`, secondary `0x00618ca8`, and two-slot tertiary `0x00618cd8`, each installed by the constructor. The generated compiler output remains the only valid representation of the RTTI, vtable dwords, adjustors, and deleting wrappers.
- The old `HandleMouseEvent` spelling is preserved in prior dated evidence as a superseded symbol hypothesis. Stale Wave-era `vtable_count:0` is likewise historical negative metadata contradicted by constructor writes and `.rdata`.
- Exact child analysis supplies the complete method body and source owner; no new hand-authored vtable emitter is created here.

## Cross-References

- [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md)
- [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md)
- [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- [UID:00036P][0x00618c44-0x00618ce0.ModelessDialogPaneVtableData](by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md)
- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## Changes

- Before: completion/confidence were `0/0`, and `RECONSTRUCTABLE` was blank despite the page containing IDA-backed vtable evidence.
- Changed to: completion `82`, confidence `88`, and `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: 2026-05-31 IDA MCP rechecked constructor stores, secondary virtual-method data references, and slot dwords for the secondary and tertiary tables. Scores remain below `95` because inherited primary-table slot naming is not yet fully audited.
- 2026-06-11 A003 normal target split and parent routing:
  - What existed before: the vtable page was `82/88` and parent-blank, while the class/file parent chain had since reached `87/85` and `89/85`.
  - Changed to: completion `85`, confidence `90`, parent [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md), and exact memory child [UID:00036P][0x00618c44-0x00618ce0.ModelessDialogPaneVtableData](by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md).
  - Summary/evidence: 2026-06-11 live IDA MCP reconfirmed the executable hash, all three constructor vtable stores, the secondary slots for `HandleMouseEvent` and `IsModal`, the inherited slot target bounds, the preceding `VersatileAlertPane` boundary, and the following `DLGFRAME.EPF` string boundary.
- 2026-06-11 A003 supervisor-row pass:
  - Changed from: `85/90`, parent [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md).
  - Changed to: `86/91`, parent unchanged.
  - Summary/evidence: live IDA re-read the constructor/method/adjustor/default-slot bounds, constructor vtable-store xrefs, secondary slot refs, and table dwords, including the tertiary-table handoff at `0x00618ce0`. Remaining inherited primary-slot naming and allocation-site gaps keep scores below final-audit range.
- 2026-06-22 B015 source-quality incorporation:
  - Changed from `86/91` to `87/92`; owner/emitter unchanged at [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md).
  - Summary/evidence: B015 raw PE recheck explicitly invalidates the stale Wave3 `vtable_count:0` value, confirms the three constructor stores at `0x004a07bd`, `0x004a07c4`, and `0x004a07ca`, confirms the vtable-only refs for `HandleMouseEvent` and `IsModal`, and preserves the two-slot tertiary table boundary before `0x00618ce0`.
