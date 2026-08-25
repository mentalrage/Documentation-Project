** TARGET-REPORT-UID:0000JO **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000JO] FunctionObjects Empty-Emitter Family Source-Quality Report

**Agent:** Agent-B013  
**Assignment:** B013-report-0000JO-FunctionObjects-empty-emitter-family-20260629  
**Report Date:** 2026-06-29  
**Target:** [UID:0000JO] `by-file/FunctionObjects.md`  
**Report Path:** `tools/leaser/Agents/Agent-B013/research/0000JO-FunctionObjects-empty-emitter-family-source-quality.md`  
**Disposition:** FINISHED_IMPLEMENTATION. Accepted by-* documentation changes were applied, scoped validators ran, generated FunctionObjects output was inspected, and no accepted item remains unapplied.

## Current Recommendation

[UID:0000JO] `by-file/FunctionObjects.md` is a valid FunctionObjects source-root target, but its generated file still contains 20 empty-emitter rows under `auto-generated/NexusTK/util/FunctionObjects.cpp`. Current MCP evidence supports resolving the full empty-emitter family without adding raw vtable arrays or hand-written compiler glue.

Recommended implementation:

- Update `by-file/FunctionObjects.md` with a 2026-06-29 family closeout section at report-level detail.
- Raise target metadata from `COMPLETION:87` / `CONFIDENCE:85` to `COMPLETION:90` / `CONFIDENCE:89`.
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
- Keep `CANONICAL_OWNER:FILE`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:` blank on the by-file target.
- Preserve the generated target as `auto-generated/NexusTK/util/FunctionObjects.cpp`, but resolve the empty rows by applying the row-specific actions in this report.
- Use [UID:0001WQ] `FunctionObjectTemplates.md` as the central source-declaration carrier for reusable callback template names and source placement.
- Convert class/instantiation rows into exact formal comment markers that point to UID0001WQ and the concrete factory/invoke rows instead of duplicating template declarations.
- Convert vtable and RTTI data rows into exact formal comment markers that state they are compiler/linker generated and covered by the relevant source declarations.
- Clear `EMITTER_UIDS` on scalar deleting destructor rows UID000123, UID0001CQ, and UID0002N3; their formal C++ blocks must remain blank because they are compiler-generated scalar deleting destructors already covered by source declarations and concrete vtables.
- Repair overly broad owner/emitter metadata on FunctionObject0 and Application raw RTTI/vtable data rows so the direct owner is the narrow class/instantiation rather than the file root.

Expected generated-output result after implementation and scoped validation:

- `auto-generated/NexusTK/util/FunctionObjects.cpp` should have zero `Empty Emitter Marker` entries for UID0000JO.
- If the validator recomputes total emitters after clearing scalar destructor `EMITTER_UIDS`, the total may decrease from the current 28; this is acceptable. The required state is zero empty markers, not preservation of the old total count.
- No generated file should be manually edited.

## MCP Availability And Session

MCP was available during this report. The active database/session was the current supervisor-provided session:

- JSON-RPC endpoint used: `http://127.0.0.1:13337/mcp`
- Database/session: `supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Worker PID observed in `idb_list`: `17592`
- `is_analyzing:false`
- `server_health` result: `status: ok`
- Auto-analysis: ready
- Hex-Rays: ready
- Strings cache: ready, size `2067`

Schema notes observed:

- `xrefs_to` required `addrs`, not stale `addr`.
- `entity_query` accepted `queries` objects with `kind`, `min_ea`, `max_ea`, and `count`; a stale `limit` field was rejected.

No fallback-only research was used.

## Current Generated State

`auto-generated/NexusTK/util/FunctionObjects.cpp` currently has validator header:

- validator command id: `000000001373`
- validator refreshed at: `2026-06-29T22:40:00-04:00`
- source UID: `0000JO`

Project tracker state:

- `auto-generated/-ag-research-tracker.md`: UID0000JO, 28 total emitters, 8 filled, 20 empty, 28.6 percent, generated file `auto-generated/NexusTK/util/FunctionObjects.cpp`.
- `project-level/-auto-completion-stats.md`: UID0000JO currently `87/85`, average `86.0`.

Current filled generated entries:

| UID | Current generated state |
| --- | --- |
| UID0002VM | Actual source-equivalent `CreateUserPaneDoubleParamCallback` factory. |
| UID0001N5 | Comment marker for UserPane double-param invoke wrapper. |
| UID00014W | Comment marker for MixItemDialog double-param invoke wrapper. |
| UID000324 | Comment marker for Application zero-arg invoke wrapper. |
| UID00032C | Comment marker for Application callback object-size helper. |
| UID0000V8 | Comment marker covered by another row. |
| UID00011X | Comment marker for PopupMenu callback invoke wrapper. |
| UID0002N2 | Comment marker for MusicControlDialog folder callback invoke wrapper. |

Current empty generated entries requiring resolution:

| UID | Path | Current issue |
| --- | --- | --- |
| UID000040 | `by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md` | Concrete instantiation routed to FunctionObjects but formal block is blank. |
| UID0002YW | `by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md` | Vtable-data row routed to concrete class but formal block is blank. |
| UID000041 | `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md` | Concrete instantiation routed to FunctionObjects but formal block is blank. |
| UID00005K | `by-class/FunctionObject.md` | Abstract base class routed to FunctionObjects but formal block is blank. |
| UID00005L | `by-class/FunctionObject0.md` | Abstract zero-arg base class routed to FunctionObjects but formal block is blank. |
| UID00005M | `by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md` | String specialization routed to FunctionObjects but formal block is blank. |
| UID00005N | `by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md` | Const-string specialization routed to FunctionObjects but formal block is blank. |
| UID0000AJ | `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md` | Application callback instantiation routed to FunctionObjects but formal block is blank. |
| UID0003GK | `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md` | NexonclubProxyDialog callback instantiation routed to FunctionObjects but formal block is blank. |
| UID0003DF | `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md` | Vtable/COL data routed to concrete class but formal block is blank. |
| UID0000AL | `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md` | MusicControlDialog callback instantiation routed to FunctionObjects but formal block is blank. |
| UID0000AK | `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md` | PopupMenu callback instantiation routed to FunctionObjects but formal block is blank. |
| UID000123 | `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md` | Compiler scalar deleting destructor routed to FunctionObjects despite accepted scalar-destructor non-emit policy. |
| UID0001CQ | `by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md` | Compiler scalar deleting destructor routed to FunctionObjects despite accepted scalar-destructor non-emit policy. |
| UID0002N3 | `by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md` | Compiler scalar deleting destructor routed to FunctionObjects despite accepted scalar-destructor non-emit policy. |
| UID000482 | `by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md` | RTTI locator pointer routed to FunctionObjects but formal block is blank. |
| UID0003OE | `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md` | Vtable-data row has overly broad file owner/emitter and blank formal block. |
| UID000486 | `by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md` | RTTI locator pointer has overly broad file owner/emitter and blank formal block. |
| UID0003OF | `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md` | Vtable-data row has overly broad file owner/emitter and blank formal block. |
| UID0001WQ | `by-type/by-template/FunctionObjectTemplates.md` | Central template page has source-shaped snippets but blank formal block. |

## Source Documents Read

Target and support documents read:

- `by-file/FunctionObjects.md`
- `by-type/by-template/FunctionObjectTemplates.md`
- `by-class/FunctionObject.md`
- `by-class/FunctionObject0.md`
- `by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md`
- `by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md`
- `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md`
- `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md`
- `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md`
- `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md`
- `by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md`
- `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md`
- `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md`
- `by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md`
- `by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md`
- `by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md`
- `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`
- `by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md`
- `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md`
- `by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md`
- `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`
- `by-class/LObject.md`
- `auto-generated/NexusTK/util/FunctionObjects.cpp`
- `auto-generated/NexusTK/util/LObject.cpp`
- `auto-generated/NexusTK/app/Application.cpp`
- `auto-generated/NexusTK/ui/dialogs/NexonclubProxyDialog.cpp`
- `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp`
- `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp`
- `auto-generated/-ag-research-tracker.md`
- `project-level/-auto-completion-stats.md`

During the original report-only pass no target/support by-* document was edited. During the accepted implementation callback, only the target/support by-* docs listed in the implementation results section were edited.

## MCP Evidence Summary

### Scalar Deleting Destructors

UID000123 `0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md`:

- `lookup_funcs(0x0049b090)` returned `sub_49B090`, size `0x3e`.
- Bytes:
  `55 8b ec 56 8b f1 c7 06 a8 86 61 00 e8 ef 99 05 00 8b 45 08 a8 01 74 1f a8 04 75 10 56 e8 0e 9a 05 00 83 c4 04 8b c6 5e 5d c2 04 00 6a 18 56 e8 dc 05 f8 ff 83 c4 08 8b c6 5e 5d c2 04 00`
- Decompile writes `FunctionObject::vftable`, calls `sub_4F4A90`, then conditionally calls `sub_4F4AC0` depending on scalar/vector delete flags.
- Callees: `sub_4F4A90`, `sub_4F4AC0`, `_guard_check_icall_nop@4`.
- `xrefs_to(0x0049b090)` returned four data refs: `0x006187e8`, `0x0061a3b0`, `0x00620184`, `0x0062dde8`.
- This is compiler-generated scalar deleting destructor glue. It should not emit hand-written C++ or a comment marker under UID0000JO; it should be non-emitting with a blank formal block.

UID0001CQ `0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md`:

- `lookup_funcs(0x0052a460)` returned `sub_52A460`, size `0x3e`.
- Bytes:
  `55 8b ec 56 8b f1 c7 06 d4 fc 61 00 e8 1f a6 fc ff 8b 45 08 a8 01 74 1f a8 04 75 10 56 e8 3e a6 fc ff 83 c4 04 8b c6 5e 5d c2 04 00 6a 04 56 e8 0c fa ee ff 83 c4 08 8b c6 5e 5d c2 04 00`
- Decompile writes `FunctionObjectT<StringBase>::vftable`, calls cleanup/delete support, and conditionally deletes.
- Callees: `sub_4F4A90`, `sub_4F4AC0`, `_guard_check_icall_nop@4`.
- `xrefs_to(0x0052a460)` returned one data ref: `0x0061fcd4`.
- This is compiler-generated scalar deleting destructor glue for the StringBase callback specialization. It should be non-emitting with a blank formal block.

UID0002N3 `0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md`:

- `lookup_funcs(0x0052a4a0)` returned `sub_52A4A0`, size `0x3e`.
- Bytes are the same scalar-deleting-destructor shape as UID0001CQ, with vtable reset to the FunctionObjectT/String family and scalar delete size `0x18`.
- Decompile writes `FunctionObjectT<StringBase>::vftable`, calls cleanup/delete support, and conditionally deletes.
- Disassembly confirms the guard branch and `push 18h` object delete size.
- Callees: `sub_4F4A90`, `sub_4F4AC0`, `_guard_check_icall_nop@4`.
- `xrefs_to(0x0052a4a0)` returned one data ref: `0x0061fcec`.
- This is compiler-generated scalar deleting destructor glue for the concrete MusicControlDialog folder callback instantiation. It should be non-emitting with a blank formal block.

### UserPane Double-Param Factory And Vtable

UID0002VM factory support at `0x005b7450`:

- `lookup_funcs(0x005b7450)` returned `sub_5B7450`, size `0x8d`.
- Decompile allocates 24 bytes via `sub_4F4AA0(24)`, calls `sub_4F4A80`, stores vtable `0x00630a78`, stores callback/member-adjust data at offsets `+8` and `+12`, target at `+16`, and bound byte arguments at `+20` and `+21`.
- Callees: `sub_4F4AA0`, `sub_4F4A80`.
- `xrefs_to(0x005b7450)` returned code refs at `0x005b46d6`, `0x005b4a05`, `0x005b4ec0`, and `0x005b5198`.
- This confirms UID0002VM already carries the source-equivalent allocation/factory body. UID000040 should not duplicate that body.

UID0002YW data at `0x00630a78-0x00630a90`:

- `entity_query(0x00630a78)` returned decorated vtable name `??_7?$DoubleParamMemberFunctionObject0@P8UserPane@@AEXC_N@ZV1@C_N@@6B@`.
- `xrefs_to(0x00630a78)` returned construction store ref at `0x005b7495` in `sub_5B7450`.
- Dword layout:
  - `0x00630a78 -> 0x004671f0`
  - `0x00630a7c -> 0x004f4b10`
  - `0x00630a80 -> 0x0041b6c0`
  - `0x00630a84 -> 0x005b77b0`
  - `0x00630a88 -> 0x004673f0`
  - `0x00630a8c -> 0x00000000`
- Successor at `0x00630a90` is the next string, so the range is exact.
- Vtable data should receive a formal no-raw-vtable marker, not a dword array.

UID0001N5 invoke wrapper support at `0x005b77b0`:

- `lookup_funcs(0x005b77b0)` returned `sub_5B77B0`, size `0x18`.
- Decompile dispatches through the stored member pointer at `this+8`, adjusts target using the member adjustor and stored object pointer, and passes bound byte arguments from the callback object.
- `xrefs_to(0x005b77b0)` returned one data ref at `0x00630a84`.
- UID0001N5 already has a filled comment marker in generated output.

### NexonclubProxyDialog Callback Vtable

UID0003DF data at `0x00622cf0-0x00622d08`:

- `get_bytes(0x00622cf0, 0x18)` returned the COL pointer plus vtable slots.
- `entity_query(0x00622cf4)` returned decorated name for `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBase&>`.
- Dword layout:
  - `0x00622cf0 -> 0x0064e8d4` COL pointer
  - `0x00622cf4 -> 0x0052f7c0`
  - `0x00622cf8 -> 0x004f4b10`
  - `0x00622cfc -> 0x0041b6c0`
  - `0x00622d00 -> 0x0049af00`
  - `0x00622d04 -> 0x004673f0`
- Successor at `0x00622d08` is `DLGMSGH.EPF`.
- Current docs show the concrete construction expression:
  `new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(this, &NexonclubProxyDialog::OnReplyText)`.
- Vtable data should receive a formal no-raw-vtable marker under UID0003GK and UID0001WQ coverage.

UID0003GK construction/source placement:

- Class metadata is currently `86/91`, `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`, formal block blank.
- This row is the direct class/instantiation owner for UID0003DF, but the reusable declaration belongs in UID0001WQ.
- It should receive a formal covered-by marker and retain the narrow child ownership relationship for UID0003DF.

### FunctionObject0 RTTI And Vtable

UID000482 data at `0x00612628-0x0061262c`:

- Bytes/dword decode: `0x00612628 -> 0x006421e0`.
- `entity_query(0x0061262c)` returned `??_7FunctionObject0@@6B@`.
- `xrefs_to(0x00612628)` returned no refs, which is expected for a COL pointer immediately preceding a vtable.
- This is compiler/linker-generated RTTI locator pointer data derived from the FunctionObject0 class declaration.
- Metadata should be narrowed from the file root to UID00005L:
  - `CANONICAL_OWNER:00005L`
  - `EMITTER_UIDS:00005L`

UID0003OE data at `0x0061262c-0x00612640`:

- Decorated name: `??_7FunctionObject0@@6B@`.
- Dword layout:
  - `0x0061262c -> 0x004672c0`
  - `0x00612630 -> 0x004f4b10`
  - `0x00612634 -> 0x0041b6c0`
  - `0x00612638 -> 0x005ca28c`
  - `0x0061263c -> 0x005ca28c`
- Successor at `0x00612640` is `aWin9502d02d`.
- `xrefs_to(0x0061262c)` returned refs at `0x004671f6` in `sub_4671F0` and `0x004672c6` in `sub_4672C0`.
- Metadata should be narrowed from file root to UID00005L:
  - `CANONICAL_OWNER:00005L`
  - `EMITTER_UIDS:00005L`
- Formal output should be a no-raw-vtable marker covered by UID00005L and UID0001WQ.

### PlainMemberFunctionObject0<Application> RTTI And Vtable

UID000486 data at `0x00612e3c-0x00612e40`:

- Dword decode: `0x00612e3c -> 0x0064222c`.
- `entity_query(0x00612e40)` returned `??_7?$PlainMemberFunctionObject0@P8Application@@AEXXZV1@@@6B@`.
- `xrefs_to(0x00612e3c)` returned no refs, which is expected for a COL pointer immediately preceding a vtable.
- Metadata should be narrowed from file root to UID0000AJ:
  - `CANONICAL_OWNER:0000AJ`
  - `EMITTER_UIDS:0000AJ`
- Formal output should be a no-raw-RTTI marker covered by UID0000AJ and UID0001WQ.

UID0003OF data at `0x00612e40-0x00612e54`:

- Decorated name: `??_7?$PlainMemberFunctionObject0@P8Application@@AEXXZV1@@@6B@`.
- Dword layout:
  - `0x00612e40 -> 0x004671f0`
  - `0x00612e44 -> 0x004f4b10`
  - `0x00612e48 -> 0x0041b6c0`
  - `0x00612e4c -> 0x004671a0`
  - `0x00612e50 -> 0x004673f0`
- Successor at `0x00612e54` is string `aE`.
- `xrefs_to(0x00612e40)` returned one construction ref at `0x00464ec6` in `sub_464E40` (`Application::RequestExit` family).
- Metadata should be narrowed from file root to UID0000AJ:
  - `CANONICAL_OWNER:0000AJ`
  - `EMITTER_UIDS:0000AJ`
- Formal output should be a no-raw-vtable marker covered by UID0000AJ, UID0001WQ, and the Application construction row.

UID000324 / UID00032C support:

- UID000324 already emits a comment marker for the Application invoke wrapper.
- UID00032C already emits a comment marker for the Application object-size helper.
- UID0000AJ should not duplicate those wrappers; it should receive a covered-by marker.

### LObject Support

`by-class/LObject.md` and `auto-generated/NexusTK/util/LObject.cpp` confirm the shared utility base:

- `0x004f4a80` constructor, size `0x9`, writes `LObject::vftable`.
- `0x004f4a90` destructor body, size `0x7`, restores `LObject::vftable`.
- `0x004f4aa0` allocator, size `0x14`.
- `0x004f4ac0` delete/free support, size `0x40`.
- `0x004f4b10` runtime-class accessor, size `0x6`.
- `0x0041b6c0` nullsub/no-op, size `0x3`.

FunctionObjects callback vtables consistently share `0x004f4b10` and `0x0041b6c0`, which confirms the callback objects are LObject-derived utility wrappers. The exact internal LObject instance layout does not need to be duplicated in FunctionObjects; UID0001WQ should carry source-level template declarations, while vtable/RTTI rows remain compiler/linker generated.

## Source Placement And Ownership

Source placement conclusion:

- The source-level owner remains `NexusTK/util/FunctionObjects` for the shared callback wrapper family.
- The original code was likely header-heavy: `FunctionObjects.h` contains base callback declarations and callback object templates; `FunctionObjects.cpp` may contain little or no hand-written implementation.
- The current generated framework emits by-file UID0000JO to `auto-generated/NexusTK/util/FunctionObjects.cpp`; this report respects the existing generated path and resolves rows through formal blocks/markers.
- UID0001WQ is the correct place to carry the central source-declaration text because it is the by-template row for the shared callback wrapper family.
- Concrete class/instantiation rows are evidence and ownership anchors. They should not each emit duplicate template declarations.
- Scalar deleting destructor rows are compiler-generated from source declarations and should not route to generated source.
- Raw RTTI/vtable data rows are compiler/linker-generated from declarations and concrete instantiations. They should receive comment-only formal markers, not C++ arrays.

Direct owner repair:

| UID | Current owner/emitter | Recommended owner/emitter | Reason |
| --- | --- | --- | --- |
| UID000482 | `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO` | `CANONICAL_OWNER:00005L`, `EMITTER_UIDS:00005L` | RTTI locator pointer belongs to FunctionObject0, not the file root. |
| UID0003OE | `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO` | `CANONICAL_OWNER:00005L`, `EMITTER_UIDS:00005L` | FunctionObject0 vtable data belongs to the FunctionObject0 class row. |
| UID000486 | `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO` | `CANONICAL_OWNER:0000AJ`, `EMITTER_UIDS:0000AJ` | RTTI locator pointer belongs to the PlainMemberFunctionObject0<Application> instantiation. |
| UID0003OF | `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO` | `CANONICAL_OWNER:0000AJ`, `EMITTER_UIDS:0000AJ` | Application callback vtable data belongs to the Application callback instantiation row. |

Rows whose owner/emitter should remain:

| UID | Recommended owner/emitter |
| --- | --- |
| UID0002YW | Keep `CANONICAL_OWNER:000040`, `EMITTER_UIDS:000040`. |
| UID0003DF | Keep `CANONICAL_OWNER:0003GK`, `EMITTER_UIDS:0003GK`. |
| UID000040 | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID000041 | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID00005K | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID00005L | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID00005M | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID00005N | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID0000AJ | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID0003GK | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID0000AL | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID0000AK | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`. |
| UID0001WQ | Keep `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`; set `EMITTER_POSITION_OPTIONAL:0` so the central declaration block appears before child markers in generated output. |

Scalar destructor rows should become non-emitting:

| UID | Recommended metadata |
| --- | --- |
| UID000123 | Keep `CANONICAL_OWNER:0000JO`, keep `RECONSTRUCTABLE:TRUE`, clear `EMITTER_UIDS:`, clear `EMITTER_POSITION_OPTIONAL:`, keep formal C++ blank. |
| UID0001CQ | Keep `CANONICAL_OWNER:0000JO`, keep `RECONSTRUCTABLE:TRUE`, clear `EMITTER_UIDS:`, clear `EMITTER_POSITION_OPTIONAL:`, keep formal C++ blank. |
| UID0002N3 | Keep `CANONICAL_OWNER:0000AL`, keep `RECONSTRUCTABLE:TRUE`, clear `EMITTER_UIDS:`, clear `EMITTER_POSITION_OPTIONAL:`, keep formal C++ blank. |

## Exact Formal C++ Recommendation

### UID0001WQ - Central FunctionObject Template Declarations

Replace the blank formal block in `by-type/by-template/FunctionObjectTemplates.md` with this formal block. This is the only recommended actual source-declaration block in the empty-emitter family. It centralizes the shared names and source placement; child class rows should not duplicate it.

```cpp
class FunctionObject : public LObject
{
public:
    virtual ~FunctionObject() {}
    virtual void Invoke(unsigned long value) = 0;
    virtual unsigned int GetObjectSize() const = 0;
};

class FunctionObject0 : public LObject
{
public:
    virtual ~FunctionObject0() {}
    virtual void Invoke() = 0;
    virtual unsigned int GetObjectSize() const = 0;
};

template <class TArg>
class FunctionObjectT : public LObject
{
public:
    virtual ~FunctionObjectT() {}
    virtual void Invoke(TArg value) = 0;
    virtual unsigned int GetObjectSize() const = 0;
};

template <class TMember, class TObject>
class PlainMemberFunctionObject0 : public FunctionObject0
{
public:
    PlainMemberFunctionObject0(TMember callback, int thisAdjust, TObject *object)
        : m_callback(callback), m_thisAdjust(thisAdjust), m_object(object)
    {
    }

    virtual void Invoke()
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)();
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
};

template <class TMember, class TObject, class TArg>
class PlainMemberFunctionObject : public FunctionObjectT<TArg>
{
public:
    PlainMemberFunctionObject(TMember callback, int thisAdjust, TObject *object)
        : m_callback(callback), m_thisAdjust(thisAdjust), m_object(object)
    {
    }

    virtual void Invoke(TArg value)
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(value);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
};

template <class TMember, class TObject, class TArg>
class PlainMemberFunctionObjectT : public FunctionObjectT<TArg>
{
public:
    PlainMemberFunctionObjectT(TMember callback, int thisAdjust, TObject *object)
        : m_callback(callback), m_thisAdjust(thisAdjust), m_object(object)
    {
    }

    PlainMemberFunctionObjectT(TObject *object, TMember callback)
        : m_callback(callback), m_thisAdjust(0), m_object(object)
    {
    }

    virtual void Invoke(TArg value)
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(value);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
};

template <class TMember, class TObject, class TArg0, class TArg1>
class DoubleParamMemberFunctionObject0 : public FunctionObject0
{
public:
    DoubleParamMemberFunctionObject0(TMember callback,
                                     int thisAdjust,
                                     TObject *object,
                                     TArg0 arg0,
                                     TArg1 arg1)
        : m_callback(callback),
          m_thisAdjust(thisAdjust),
          m_object(object),
          m_arg0(arg0),
          m_arg1(arg1)
    {
    }

    virtual void Invoke()
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(m_arg0, m_arg1);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
    TArg0 m_arg0;
    TArg1 m_arg1;
};

template <class TMember, class TObject, class TInvokeArg, class TArg0, class TArg1>
class DoubleParamMemberFunctionObject : public FunctionObjectT<TInvokeArg>
{
public:
    DoubleParamMemberFunctionObject(TMember callback,
                                    int thisAdjust,
                                    TObject *object,
                                    TArg0 arg0,
                                    TArg1 arg1)
        : m_callback(callback),
          m_thisAdjust(thisAdjust),
          m_object(object),
          m_arg0(arg0),
          m_arg1(arg1)
    {
    }

    virtual void Invoke(TInvokeArg value)
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(value, m_arg0, m_arg1);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
    TArg0 m_arg0;
    TArg1 m_arg1;
};
```

Required accompanying text in UID0001WQ:

- State that this block is the shared source-declaration carrier for FunctionObjects callback wrappers.
- State that exact binary destructor and vtable emission is compiler/linker output, not manually reconstructed source.
- State that concrete construction and binding proof is carried by feature/factory rows such as UID0002VM, Application request-exit rows, NexonclubProxyDialog construction rows, MusicControlDialog rows, and PopupMenuControlPane rows.
- State that scalar deleting destructor rows remain non-emitting blank-formal rows unless a supervisor explicitly changes the scalar-destructor policy.
- Recommended metadata: raise UID0001WQ from `85/89` to `88/90`; set `EMITTER_POSITION_OPTIONAL:0`.

Score cap note: this declaration block closes the empty-emitter source-placement blocker, but it should not drive the family to 95+ because exact original header spelling, typedef aliases, and MSVC pointer-to-member layout details remain below final-source certainty.

## Exact Formal Markers For Class/Instantiation Rows

Each row below should keep `RECONSTRUCTABLE:TRUE` and receive the exact formal comment marker shown. These are not raw code bodies because UID0001WQ is the central reusable declaration carrier and the exact concrete factories/invoke helpers already live on their own rows.

### UID000040

`by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md`

```cpp
// Concrete UserPane item-action callback instantiation.
// The reusable FunctionObjects template declaration is emitted by [UID:0001WQ];
// concrete allocation and binding are emitted by [UID:0002VM], and the invoke wrapper is covered by [UID:0001N5].
```

Also add current evidence text:

- UID0002VM allocates 24 bytes, installs vtable `0x00630a78`, stores callback/adjustor/target at `+8/+12/+16`, and stores bound byte arguments at `+20/+21`.
- UID0002YW is the vtable data child and should use a no-raw-vtable marker.

### UID000041

`by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md`

```cpp
// Concrete MixItemDialog double-parameter callback instantiation.
// The reusable FunctionObjects template declaration is emitted by [UID:0001WQ];
// the generated invoke wrapper is covered by [UID:00014W].
```

Also add current evidence text:

- UID00014W is already generated as a comment marker and remains the exact invoke-wrapper row.
- The class row is a concrete instantiation anchor, not a second copy of the shared template declaration.

### UID00005K

`by-class/FunctionObject.md`

```cpp
// FunctionObject abstract callback base declaration is emitted by [UID:0001WQ].
// Scalar deleting destructor bytes such as [UID:000123] are compiler-generated from that declaration.
```

Also add current evidence text:

- UID000123 revalidated as a 0x3e-byte scalar deleting destructor that resets `FunctionObject::vftable`, calls LObject cleanup, and conditionally deletes.
- The exact scalar deleting destructor remains non-emitting with blank formal C++.

### UID00005L

`by-class/FunctionObject0.md`

```cpp
// FunctionObject0 abstract zero-argument callback base declaration is emitted by [UID:0001WQ].
// Its RTTI and vtable ranges are compiler/linker-generated and covered by [UID:000482] and [UID:0003OE].
```

Also add current evidence text:

- UID000482 and UID0003OE should be direct children of UID00005L.
- UID0003OE vtable slots are `0x004672c0`, `0x004f4b10`, `0x0041b6c0`, `0x005ca28c`, `0x005ca28c`.

### UID00005M

`by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md`

```cpp
// FunctionObjectT<StringBaseW> specialization is covered by the shared FunctionObjectT declaration in [UID:0001WQ].
// The scalar deleting destructor [UID:0001CQ] is compiler-generated and intentionally non-emitting.
```

Also add current evidence text:

- UID0001CQ has a single vtable data ref at `0x0061fcd4`, no code callers, and the same cleanup/delete scalar-destructor structure as other FunctionObjects destructor glue.

### UID00005N

`by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md`

```cpp
// FunctionObjectT<const StringBaseW&> specialization is covered by the shared FunctionObjectT declaration in [UID:0001WQ].
// Concrete string callback wrappers are documented on their direct instantiation and vtable rows.
```

Also add current evidence text:

- This row remains a typed specialization evidence page, not a duplicated template declaration.
- The existing scalar-destructor policy for const-string generated glue should remain unchanged.

### UID0000AJ

`by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md`

```cpp
// Concrete PlainMemberFunctionObject0<Application> instantiation.
// The reusable declaration is emitted by [UID:0001WQ]; the invoke and object-size helpers are covered by [UID:000324] and [UID:00032C].
```

Also add current evidence text:

- UID000486 and UID0003OF should be direct data children of UID0000AJ.
- UID0003OF has a sole construction/data ref from `Application::RequestExit` family at `0x00464ec6`.

### UID0003GK

`by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md`

```cpp
// Concrete PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&> instantiation.
// The reusable declaration is emitted by [UID:0001WQ]; the concrete vtable data is covered by [UID:0003DF].
```

Also add current evidence text:

- Source construction expression remains `new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(this, &NexonclubProxyDialog::OnReplyText)`.
- UID0003DF range ends at the `DLGMSGH.EPF` successor string and should not emit raw dwords.

### UID0000AL

`by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md`

```cpp
// Concrete PlainMemberFunctionObjectT<MusicControlDialog, StringBaseW> instantiation.
// The reusable declaration is emitted by [UID:0001WQ]; the invoke wrapper is covered by [UID:0002N2].
```

Also add current evidence text:

- UID0002N3 is the scalar deleting destructor child but must become non-emitting and keep blank formal C++.
- The source-level construction belongs to the MusicControlDialog command-handler family, not this utility class row.

### UID0000AK

`by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md`

```cpp
// Concrete PlainMemberFunctionObject<PopupMenuControlPane, long> instantiation.
// The reusable declaration is emitted by [UID:0001WQ]; the invoke wrapper is covered by [UID:00011X].
```

Also add current evidence text:

- UID00011X is already generated as the invoke-wrapper marker.
- Shared destructor data routed through UID000123 should be non-emitting scalar-deleting-destructor glue.

## Exact Formal Markers For Vtable And RTTI Rows

These rows should receive exact formal comment markers. They must not emit raw dword arrays.

### UID0002YW

`by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md`

```cpp
// Compiler-emitted DoubleParamMemberFunctionObject0<UserPane, signed char, bool> vtable data.
// Rebuilt from the shared FunctionObjects template declaration [UID:0001WQ],
// the concrete callback instantiation [UID:000040], and the factory binding [UID:0002VM].
// Do not hand-port raw vtable dwords into generated source.
```

Required doc evidence:

- Decorated vtable name `??_7?$DoubleParamMemberFunctionObject0@P8UserPane@@AEXC_N@ZV1@C_N@@6B@`.
- Construction store ref `0x005b7495` in `sub_5B7450`.
- Dwords: `0x004671f0`, `0x004f4b10`, `0x0041b6c0`, `0x005b77b0`, `0x004673f0`, terminator `0`.

### UID0003DF

`by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`

```cpp
// Compiler-emitted PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&> RTTI/vtable data.
// Rebuilt from the shared FunctionObjects template declaration [UID:0001WQ],
// the concrete callback instantiation [UID:0003GK], and the NexonclubProxyDialog construction site.
// Do not hand-port raw RTTI or vtable dwords into generated source.
```

Required doc evidence:

- COL pointer `0x0064e8d4`, vtable base `0x00622cf4`.
- Slots: `0x0052f7c0`, `0x004f4b10`, `0x0041b6c0`, `0x0049af00`, `0x004673f0`.
- Successor `0x00622d08` is `DLGMSGH.EPF`.

### UID000482

`by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md`

Metadata repair:

- `CANONICAL_OWNER:0000JO` -> `CANONICAL_OWNER:00005L`
- `EMITTER_UIDS:0000JO` -> `EMITTER_UIDS:00005L`

Formal marker:

```cpp
// Compiler/linker-generated FunctionObject0 RTTI locator pointer.
// Covered by the FunctionObject0 declaration [UID:00005L] and the shared FunctionObjects declaration block [UID:0001WQ].
// No raw RTTI dword is emitted into generated source.
```

Required doc evidence:

- Dword `0x00612628 -> 0x006421e0`.
- Immediate successor vtable name at `0x0061262c`: `??_7FunctionObject0@@6B@`.
- No refs to the COL pointer itself, consistent with pre-vtable RTTI data.

### UID0003OE

`by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md`

Metadata repair:

- `CANONICAL_OWNER:0000JO` -> `CANONICAL_OWNER:00005L`
- `EMITTER_UIDS:0000JO` -> `EMITTER_UIDS:00005L`

Formal marker:

```cpp
// Compiler-emitted FunctionObject0 vtable data.
// Rebuilt from the FunctionObject0 declaration [UID:00005L] and the shared FunctionObjects declaration block [UID:0001WQ].
// Do not hand-port raw vtable dwords into generated source.
```

Required doc evidence:

- Decorated name `??_7FunctionObject0@@6B@`.
- Slots: `0x004672c0`, `0x004f4b10`, `0x0041b6c0`, `0x005ca28c`, `0x005ca28c`.
- Refs at `0x004671f6` and `0x004672c6`.
- Successor string at `0x00612640`.

### UID000486

`by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md`

Metadata repair:

- `CANONICAL_OWNER:0000JO` -> `CANONICAL_OWNER:0000AJ`
- `EMITTER_UIDS:0000JO` -> `EMITTER_UIDS:0000AJ`

Formal marker:

```cpp
// Compiler/linker-generated PlainMemberFunctionObject0<Application> RTTI locator pointer.
// Covered by the concrete Application callback instantiation [UID:0000AJ] and the shared declaration block [UID:0001WQ].
// No raw RTTI dword is emitted into generated source.
```

Required doc evidence:

- Dword `0x00612e3c -> 0x0064222c`.
- Immediate successor vtable name at `0x00612e40`: `??_7?$PlainMemberFunctionObject0@P8Application@@AEXXZV1@@@6B@`.
- No refs to the COL pointer itself, consistent with pre-vtable RTTI data.

### UID0003OF

`by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`

Metadata repair:

- `CANONICAL_OWNER:0000JO` -> `CANONICAL_OWNER:0000AJ`
- `EMITTER_UIDS:0000JO` -> `EMITTER_UIDS:0000AJ`

Formal marker:

```cpp
// Compiler-emitted PlainMemberFunctionObject0<Application> vtable data.
// Rebuilt from the concrete Application callback instantiation [UID:0000AJ],
// the shared FunctionObjects declaration block [UID:0001WQ], and the Application construction site.
// Do not hand-port raw vtable dwords into generated source.
```

Required doc evidence:

- Decorated name `??_7?$PlainMemberFunctionObject0@P8Application@@AEXXZV1@@@6B@`.
- Slots: `0x004671f0`, `0x004f4b10`, `0x0041b6c0`, `0x004671a0`, `0x004673f0`.
- Sole construction/data ref `0x00464ec6` in `sub_464E40`.
- Successor string at `0x00612e54`.

## Exact No-Emit Scalar Destructor Dispositions

The scalar destructor rows below should not receive comment markers. The exact formal C++ block remains empty. Their `EMITTER_UIDS` should be blank so they stop producing empty markers in `FunctionObjects.cpp`.

### UID000123

`by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md`

Metadata:

- Keep `CANONICAL_OWNER:0000JO`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Clear `EMITTER_UIDS:`.
- Clear `EMITTER_POSITION_OPTIONAL:`.
- Keep formal `RECONSTRUCTION_CPP CODE` blank.

Required no-code proof text:

`2026-06-29 MCP recheck: 0x0049b090 is a 0x3e-byte compiler scalar deleting destructor that resets FunctionObject::vftable, calls LObject cleanup support, and conditionally calls delete support based on scalar/vector delete flags. Its only incoming refs are vtable-data refs at 0x006187e8, 0x0061a3b0, 0x00620184, and 0x0062dde8. There is no standalone source body to reconstruct; source-level behavior is regenerated from the FunctionObject declaration in [UID:0001WQ]. Formal C++ and EMITTER_UIDS intentionally remain blank.`

### UID0001CQ

`by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md`

Metadata:

- Keep `CANONICAL_OWNER:0000JO`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Clear `EMITTER_UIDS:`.
- Clear `EMITTER_POSITION_OPTIONAL:`.
- Keep formal `RECONSTRUCTION_CPP CODE` blank.

Required no-code proof text:

`2026-06-29 MCP recheck: 0x0052a460 is a 0x3e-byte compiler scalar deleting destructor for FunctionObjectT<StringBaseW> that resets the FunctionObjectT<StringBaseW> vtable, calls LObject cleanup support, and conditionally calls delete support. Its only incoming ref is the vtable-data ref at 0x0061fcd4. There is no standalone source body to reconstruct; source-level behavior is regenerated from the FunctionObjectT declaration in [UID:0001WQ]. Formal C++ and EMITTER_UIDS intentionally remain blank.`

### UID0002N3

`by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md`

Metadata:

- Keep `CANONICAL_OWNER:0000AL`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Clear `EMITTER_UIDS:`.
- Clear `EMITTER_POSITION_OPTIONAL:`.
- Keep formal `RECONSTRUCTION_CPP CODE` blank.

Required no-code proof text:

`2026-06-29 MCP recheck: 0x0052a4a0 is a 0x3e-byte compiler scalar deleting destructor for the MusicControlDialog FunctionObjectT<StringBaseW> callback instantiation. It resets the FunctionObjectT<StringBaseW> vtable, calls LObject cleanup support, conditionally calls delete support, and uses scalar delete size 0x18. Its only incoming ref is the concrete callback vtable-data ref at 0x0061fcec. The source-level representation is the shared declaration in [UID:0001WQ] plus the concrete MusicControlDialog callback instantiation [UID:0000AL]; formal C++ and EMITTER_UIDS intentionally remain blank.`

## Rejected Alternatives

Rejected: emit raw vtable arrays for UID0002YW, UID0003DF, UID0003OE, UID0003OF.

- Reason: These ranges are compiler/linker-generated vtable data derived from declarations and concrete instantiations. Existing project style uses comment-only markers for generated vtable data; raw dword arrays would create non-source artifacts in generated C++.

Rejected: emit raw RTTI/COL dwords for UID000482 and UID000486.

- Reason: The data is compiler/linker-generated RTTI metadata. The source-level requirement is the class/template declaration; the raw pointers are rebuild artifacts.

Rejected: emit formal comment markers for UID000123, UID0001CQ, and UID0002N3 while leaving `EMITTER_UIDS` nonblank.

- Reason: `FunctionObjectTemplates.md` already states scalar deleting destructor targets should remain source-declared/generated-binary with blank formal C++ and blank `EMITTER_UIDS` unless a supervisor explicitly approves markers. MCP confirms these rows are destructor glue with only vtable-data refs. Clearing emitters is the exact accepted policy and prevents the generated file from carrying no-source destructor rows.

Rejected: duplicate the shared FunctionObjects template declaration on every concrete class row.

- Reason: The concrete rows are instantiation/evidence anchors. Duplicating template declarations would create inconsistent source fragments and confuse ownership. UID0001WQ is the central source-declaration carrier.

Rejected: move UID0000JO to a UI feature source file.

- Reason: The family is shared utility callback machinery used by Application, UserPane, PopupMenuControlPane, MusicControlDialog, MixItemDialog, NexonclubProxyDialog, and other feature files. The correct source root is `NexusTK/util/FunctionObjects`.

## Score Rationale

Recommended target score change:

- `by-file/FunctionObjects.md`: `COMPLETION:87 -> 90`
- `by-file/FunctionObjects.md`: `CONFIDENCE:85 -> 89`

Rationale:

- The current MCP session proves the active database, generated output state, scalar destructor behavior, callback factory behavior, vtable layouts, decorated names, xrefs, and source-placement relationships.
- The 20 current empty emitters have exact implementation actions: one central formal declaration block, ten concrete class/instantiation covered-by markers, six RTTI/vtable no-raw-data markers with two direct-owner metadata repairs, and three scalar destructor non-emits.
- The source route is now implementation-ready and should clear the generated empty markers.
- The score should remain below 95 because exact original header spelling, typedef ordering, include placement, and MSVC pointer-to-member layout details are still not proven at final-source certainty.

Recommended support score changes:

| UID | Path | Recommended score |
| --- | --- | --- |
| UID0001WQ | `by-type/by-template/FunctionObjectTemplates.md` | `85/89 -> 88/90` after formal declaration block and source-placement update. |
| UID000040 | UserPane concrete instantiation class | No score change required; add marker/evidence only. |
| UID000041 | MixItemDialog concrete instantiation class | No score change required; add marker/evidence only. |
| UID00005K | FunctionObject class | No score change required; add marker/evidence only. |
| UID00005L | FunctionObject0 class | No score change required; add marker/evidence only. |
| UID00005M | FunctionObjectT<StringBaseW> class | No score change required; add marker/evidence only. |
| UID00005N | FunctionObjectT<const StringBaseW&> class | No score change required; add marker/evidence only. |
| UID0000AJ | Application callback instantiation class | No score change required; add marker/evidence only. |
| UID0003GK | NexonclubProxy callback instantiation class | No score change required; add marker/evidence only. |
| UID0000AL | MusicControlDialog callback instantiation class | No score change required; add marker/evidence only. |
| UID0000AK | PopupMenu callback instantiation class | No score change required; add marker/evidence only. |
| UID0002YW | UserPane vtable data | No score change required; add marker/evidence only. |
| UID0003DF | NexonclubProxy vtable data | No score change required; add marker/evidence only. |
| UID000482 | FunctionObject0 RTTI pointer | No score change required; metadata repair only. |
| UID0003OE | FunctionObject0 vtable data | No score change required; metadata repair only. |
| UID000486 | Application callback RTTI pointer | No score change required; metadata repair only. |
| UID0003OF | Application callback vtable data | No score change required; metadata repair only. |
| UID000123 | Shared FunctionObject scalar destructor | No score change required; clear emitter only. |
| UID0001CQ | FunctionObjectT<StringBaseW> scalar destructor | No score change required; clear emitter only. |
| UID0002N3 | MusicControlDialog callback scalar destructor | No score change required; clear emitter only. |

## Implementation Targets

Primary target:

- `by-file/FunctionObjects.md`

Required by-* support docs:

- `by-type/by-template/FunctionObjectTemplates.md`
- `by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md`
- `by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md`
- `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md`
- `by-class/FunctionObject.md`
- `by-class/FunctionObject0.md`
- `by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md`
- `by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md`
- `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md`
- `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md`
- `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`
- `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md`
- `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md`
- `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md`
- `by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md`
- `by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md`
- `by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md`
- `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md`
- `by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md`
- `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`

Optional support doc:

- `by-meta/client_callback_dispatch.md` may receive a concise cross-reference note if the implementer wants a global callback-dispatch breadcrumb. This is optional because the required row-level docs and UID0000JO target can carry the closeout without changing by-meta score.

Explicitly excluded:

- `by-class/-coverage-report.md`
- `by-memory/-coverage-report.md`
- Any other manual `-coverage-report.md`
- Generated files under `auto-generated/`
- Project-level generated files
- Validator state
- IDA database
- Executed archives
- Supervisor ledgers
- Lock files

## Validator Plan For Implementation Callback

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0000JO-FunctionObjects-empty-emitter-family-source-quality-removed.md](0000JO-FunctionObjects-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After scoped validators, check generated freshness and empty-marker state without editing generated files:

> Executable block R002 was removed from this report and preserved verbatim in [0000JO-FunctionObjects-empty-emitter-family-source-quality-removed.md](0000JO-FunctionObjects-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Implementation callback must report:

- validator command id(s)
- validator timestamp(s)
- exit code for each scoped validator
- ok count for each scoped validator
- generated refresh state for `auto-generated/NexusTK/util/FunctionObjects.cpp`
- remaining `Empty Emitter Marker` count for `FunctionObjects.cpp`
- leases used and released
- changed files
- any accepted row not applied, already present, or excluded with reason

## Claim And Incorporation Ledger

| Claim | Source Evidence | Implementation Action | Verification State |
| --- | --- | --- | --- |
| UID0000JO is the correct FunctionObjects source root for this family. | `by-file/FunctionObjects.md`, generated path `auto-generated/NexusTK/util/FunctionObjects.cpp`, multiple consumer files. | Add family closeout and raise score to 90/89. | Applied: `by-file/FunctionObjects.md` metadata and `2026-06-29 FunctionObjects Empty-Emitter Family Closeout`; validator `000000001514`, exit 0, `ok:1`. |
| Current generated file has 20 empty FunctionObjects emitter rows. | `auto-generated/NexusTK/util/FunctionObjects.cpp`, tracker row. | Resolve every listed row by code, marker, metadata repair, or non-emit. | Applied: all rows resolved by code, marker, metadata repair, or non-emit; generated `FunctionObjects.cpp` command id `000000001534`, empty-marker count `0`. |
| UID0001WQ should carry central source declarations. | `FunctionObjectTemplates.md`, class rows, generated consumer code. | Add formal declaration block and `EMITTER_POSITION_OPTIONAL:0`; raise to 88/90. | Applied: `by-type/by-template/FunctionObjectTemplates.md` formal block, position `0`, score `88/90`; validator `000000001515`, exit 0, `ok:1`. |
| UID000040 is a concrete UserPane callback instantiation. | UID0002VM decompile and UID0002YW vtable name/xref. | Add exact covered-by marker and MCP evidence. | Applied: UID000040 formal marker and closeout evidence; validator `000000001516`, exit 0, `ok:1`. |
| UID0002YW is compiler-emitted UserPane vtable data. | Vtable name, dwords, xref at `0x005b7495`. | Add no-raw-vtable marker. | Applied: UID0002YW item summary, formal no-raw-vtable marker, and closeout evidence; validator `000000001517`, exit 0, `ok:1`. |
| UID000041 is a concrete MixItemDialog callback instantiation. | Existing class doc and UID00014W filled generated marker. | Add exact covered-by marker. | Applied: UID000041 formal marker and closeout evidence; validator `000000001518`, exit 0, `ok:1`. |
| UID00005K is covered by central FunctionObject declaration. | UID000123 destructor evidence and FunctionObject class doc. | Add exact covered-by marker and scalar destructor proof reference. | Applied: UID00005K formal marker and scalar proof reference; validator `000000001519`, exit 0, `ok:1`. |
| UID00005L is covered by central FunctionObject0 declaration. | UID000482/UID0003OE RTTI/vtable evidence. | Add exact covered-by marker and child-data note. | Applied: UID00005L formal marker and child-data evidence; validator `000000001520`, exit 0, `ok:1`. |
| UID00005M is a FunctionObjectT<StringBaseW> specialization, not standalone source. | UID0001CQ scalar destructor evidence and class doc. | Add exact covered-by marker. | Applied: UID00005M formal marker and scalar proof reference; validator `000000001521`, exit 0, `ok:1`. |
| UID00005N is a FunctionObjectT<const StringBaseW&> specialization, not standalone source. | Class doc and NexonclubProxy callback usage. | Add exact covered-by marker. | Applied: UID00005N formal marker and closeout evidence; validator `000000001522`, exit 0, `ok:1`. |
| UID0000AJ is the direct Application callback instantiation. | UID000486/UID0003OF data and xref `0x00464ec6`; UID000324/UID00032C markers. | Add exact covered-by marker. | Applied: UID0000AJ formal marker and child-data evidence; validator `000000001523`, exit 0, `ok:1`. |
| UID0003GK is the direct NexonclubProxy callback instantiation. | UID0003DF vtable data and construction expression. | Add exact covered-by marker. | Applied: UID0003GK formal marker and vtable/construction evidence; validator `000000001524`, exit 0, `ok:1`. |
| UID0003DF is compiler-emitted NexonclubProxy RTTI/vtable data. | Dwords, decorated name, successor `DLGMSGH.EPF`. | Add no-raw-data marker. | Applied: UID0003DF item summary, no-raw-data marker, and evidence; validator `000000001525`, exit 0, `ok:1`. |
| UID0000AL is the concrete MusicControlDialog callback instantiation. | UID0002N2 filled marker and UID0002N3 destructor evidence. | Add exact covered-by marker. | Applied: UID0000AL formal marker and UID0002N3 proof reference; validator `000000001526`, exit 0, `ok:1`. |
| UID0000AK is the concrete PopupMenu callback instantiation. | UID00011X filled marker and UID000123 shared destructor. | Add exact covered-by marker. | Applied: UID0000AK formal marker and UID000123 proof reference; validator `000000001527`, exit 0, `ok:1`. |
| UID000123 is compiler scalar deleting destructor glue. | MCP bytes/decompile/callees/xrefs. | Clear emitter, keep blank formal block, add no-code proof. | Applied: UID000123 `EMITTER_UIDS` blank, formal block blank, no-code proof added; validator `000000001528`, exit 0, `ok:1`. |
| UID0001CQ is compiler scalar deleting destructor glue. | MCP bytes/decompile/callees/single xref. | Clear emitter, keep blank formal block, add no-code proof. | Applied: UID0001CQ `EMITTER_UIDS` blank, formal block blank, no-code proof added; validator `000000001529`, exit 0, `ok:1`. |
| UID0002N3 is compiler scalar deleting destructor glue. | MCP bytes/decompile/callees/single xref, delete size 0x18. | Clear emitter, keep blank formal block, add no-code proof. | Applied: UID0002N3 `EMITTER_UIDS` blank, formal block blank, no-code proof added; validator `000000001530`, exit 0, `ok:1`. |
| UID000482 direct owner is UID00005L, not file root. | COL pointer immediately precedes `FunctionObject0` vtable. | Repair owner/emitter and add no-raw-RTTI marker. | Applied: UID000482 owner/emitter `00005L`, no-raw-RTTI marker and evidence; validator `000000001531`, exit 0, `ok:1`. |
| UID0003OE direct owner is UID00005L, not file root. | Decorated `FunctionObject0` vtable name and refs. | Repair owner/emitter and add no-raw-vtable marker. | Applied: UID0003OE owner/emitter `00005L`, no-raw-vtable marker and evidence; validator `000000001532`, exit 0, `ok:1`. |
| UID000486 direct owner is UID0000AJ, not file root. | COL pointer immediately precedes Application callback vtable. | Repair owner/emitter and add no-raw-RTTI marker. | Applied: UID000486 owner/emitter `0000AJ`, no-raw-RTTI marker and evidence; validator `000000001533`, exit 0, `ok:1`. |
| UID0003OF direct owner is UID0000AJ, not file root. | Decorated Application callback vtable name and sole Application xref. | Repair owner/emitter and add no-raw-vtable marker. | Applied: UID0003OF owner/emitter `0000AJ`, no-raw-vtable marker and evidence; validator `000000001534`, exit 0, `ok:1`. |
| Raw dword arrays should not be emitted for vtable/RTTI rows. | Project style and source-declared/generated-binary evidence. | Use exact comment markers instead of arrays. | Applied: UID0002YW, UID0003DF, UID000482, UID0003OE, UID000486, and UID0003OF use comment-only no-raw-data markers; generated output has zero empty markers. |
| Generated file should have zero empty markers after implementation. | Current 20-row inventory and row-specific dispositions. | Run scoped validators and check generated `FunctionObjects.cpp` freshness/marker count. | Applied: generated `auto-generated/NexusTK/util/FunctionObjects.cpp` header `validator-command-id: 000000001534`, refreshed `2026-06-29T23:25:18-04:00`, empty-marker count `0`. |

## Implementation Tracking Checklist

- [x] Lease only the by-* files to be edited, immediately before editing, and release leases immediately after the edit/validator batch. Proof: B013 leased the 21 accepted by-* docs, refreshed the lease before the validator rerun, and `leaser.py B013 unlease` released every file; `current_leases.md` reports no active leases.
- [x] Update `by-file/FunctionObjects.md` metadata to `COMPLETION:90`, `CONFIDENCE:89`. Proof: validator `000000001514`, exit 0, `ok:1`.
- [x] Add a 2026-06-29 FunctionObjects empty-emitter family closeout section to `by-file/FunctionObjects.md` with current MCP evidence, generated state, row disposition table, source-placement rationale, rejected alternatives, and score rationale. Proof: section `2026-06-29 FunctionObjects Empty-Emitter Family Closeout`; validator `000000001514`.
- [x] Update `by-type/by-template/FunctionObjectTemplates.md` with the exact central declaration formal block, source-placement text, scalar destructor policy, `EMITTER_POSITION_OPTIONAL:0`, and score `88/90`. Proof: formal block populated, position `0`, score `88/90`; validator `000000001515`.
- [x] Add the exact formal covered-by marker and evidence to UID000040. Proof: `by-class/DoubleParamMemberFunctionObject0...UserPane...md`; validator `000000001516`.
- [x] Add the exact formal no-raw-vtable marker and evidence to UID0002YW. Proof: `by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md`; validator `000000001517`.
- [x] Add the exact formal covered-by marker and evidence to UID000041. Proof: `by-class/DoubleParamMemberFunctionObject...MixItemDialog...md`; validator `000000001518`.
- [x] Add the exact formal covered-by marker and evidence to UID00005K. Proof: `by-class/FunctionObject.md`; validator `000000001519`.
- [x] Add the exact formal covered-by marker and evidence to UID00005L. Proof: `by-class/FunctionObject0.md`; validator `000000001520`.
- [x] Add the exact formal covered-by marker and evidence to UID00005M. Proof: `by-class/FunctionObjectT_class_mystr__StringBase...md`; validator `000000001521`.
- [x] Add the exact formal covered-by marker and evidence to UID00005N. Proof: `by-class/FunctionObjectT_near_class_mystr__StringBase...const...md`; validator `000000001522`.
- [x] Add the exact formal covered-by marker and evidence to UID0000AJ. Proof: `by-class/PlainMemberFunctionObject0...Application...md`; validator `000000001523`.
- [x] Add the exact formal covered-by marker and evidence to UID0003GK. Proof: `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md`; validator `000000001524`.
- [x] Add the exact formal no-raw-data marker and evidence to UID0003DF. Proof: `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`; validator `000000001525`.
- [x] Add the exact formal covered-by marker and evidence to UID0000AL. Proof: `by-class/PlainMemberFunctionObjectT...MusicControlDialog...md`; validator `000000001526`.
- [x] Add the exact formal covered-by marker and evidence to UID0000AK. Proof: `by-class/PlainMemberFunctionObject...PopupMenuControlPane...md`; validator `000000001527`.
- [x] Clear `EMITTER_UIDS` and `EMITTER_POSITION_OPTIONAL` on UID000123; keep formal block blank; add current no-code proof. Proof: `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md`; validator `000000001528`.
- [x] Clear `EMITTER_UIDS` and `EMITTER_POSITION_OPTIONAL` on UID0001CQ; keep formal block blank; add current no-code proof. Proof: `by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md`; validator `000000001529`.
- [x] Clear `EMITTER_UIDS` and `EMITTER_POSITION_OPTIONAL` on UID0002N3; keep formal block blank; add current no-code proof. Proof: `by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md`; validator `000000001530`.
- [x] Repair UID000482 owner/emitter to UID00005L and add exact formal no-raw-RTTI marker/evidence. Proof: validator `000000001531`, owner/emitter `00005L`.
- [x] Repair UID0003OE owner/emitter to UID00005L and add exact formal no-raw-vtable marker/evidence. Proof: validator `000000001532`, owner/emitter `00005L`.
- [x] Repair UID000486 owner/emitter to UID0000AJ and add exact formal no-raw-RTTI marker/evidence. Proof: validator `000000001533`, owner/emitter `0000AJ`.
- [x] Repair UID0003OF owner/emitter to UID0000AJ and add exact formal no-raw-vtable marker/evidence. Proof: validator `000000001534`, owner/emitter `0000AJ`.
- [x] Decide whether to add the optional `by-meta/client_callback_dispatch.md` breadcrumb. Excluded with reason: the callback explicitly forbade editing the optional by-meta breadcrumb, and row-level docs plus UID0000JO carry the accepted closeout sufficiently.
- [x] Do not edit manual `-coverage-report.md` files. Proof: no manual coverage report was edited.
- [x] Do not edit generated files, validator state, project-level generated files, IDA DB, executed archives, supervisor ledgers, or lock files. Proof: no manual edits were made to those files; scoped validators produced validator-owned side effects including generated C++ refresh, autogen registry updates, and project-level stats updates, which are reported below.
- [x] Run scoped validator for `by-file/FunctionObjects.md`; record command id, timestamp, exit code, and ok count. Proof: `000000001514`, `2026-06-29T23:24:08-04:00`, exit 0, `ok:1`.
- [x] Run scoped validator for `by-type/by-template/FunctionObjectTemplates.md`; record command id, timestamp, exit code, and ok count. Proof: `000000001515`, `2026-06-29T23:24:14-04:00`, exit 0, `ok:1`.
- [x] Run scoped validators for every changed by-class and by-memory support doc listed above; record command id, timestamp, exit code, and ok count. Proof: validator table below, all exit 0 and `ok:1`.
- [x] Check generated `auto-generated/NexusTK/util/FunctionObjects.cpp` freshness and `Empty Emitter Marker` count after validators. Proof: generated header `validator-command-id: 000000001534`, `validator-refreshed-at: 2026-06-29T23:25:18-04:00`, empty-marker count `0`.
- [x] Update this report ledger/checklist during implementation callback with applied/already-present/excluded status, validator results, generated refresh state, leases used/released, changed files, and unapplied accepted items. Proof: this callback section is updated; no accepted item remains unapplied.

## Implementation Callback Results

Changed by-* docs:

- `by-file/FunctionObjects.md`
- `by-type/by-template/FunctionObjectTemplates.md`
- `by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md`
- `by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md`
- `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md`
- `by-class/FunctionObject.md`
- `by-class/FunctionObject0.md`
- `by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md`
- `by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md`
- `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md`
- `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md`
- `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`
- `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md`
- `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md`
- `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md`
- `by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md`
- `by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md`
- `by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md`
- `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md`
- `by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md`
- `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`

Validator commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with:

`python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`

| File | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `by-file/FunctionObjects.md` | `000000001514` | `2026-06-29T23:24:08-04:00` | 0 | 1 | `missing_ref_uid` for pre-existing UIDs `0003LP`, `000366`, `0003OQ`; projected stats updated. |
| `by-type/by-template/FunctionObjectTemplates.md` | `000000001515` | `2026-06-29T23:24:14-04:00` | 0 | 1 | `missing_ref_uid` for pre-existing UIDs `0003LP`, `000366`, `000365`, `00036G`; projected stats updated. |
| `by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md` | `000000001516` | `2026-06-29T23:24:22-04:00` | 0 | 1 | Autogen hash update; pre-existing missing UID `000366`; projected stats updated. |
| `by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md` | `000000001517` | `2026-06-29T23:24:29-04:00` | 0 | 1 | Autogen hash update; projected stats updated. |
| `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md` | `000000001518` | `2026-06-29T23:24:30-04:00` | 0 | 1 | Autogen hash update; pre-existing missing UID `0003IH`; stats/projected stats updated. |
| `by-class/FunctionObject.md` | `000000001519` | `2026-06-29T23:24:32-04:00` | 0 | 1 | Autogen hash update; pre-existing missing UID `0003LP`; stats/projected stats updated. |
| `by-class/FunctionObject0.md` | `000000001520` | `2026-06-29T23:24:34-04:00` | 0 | 1 | Autogen hash update; stats/projected stats updated. |
| `by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md` | `000000001521` | `2026-06-29T23:24:35-04:00` | 0 | 1 | Autogen hash update; projected stats updated. |
| `by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md` | `000000001522` | `2026-06-29T23:24:37-04:00` | 0 | 1 | Autogen hash update; projected stats updated. |
| `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md` | `000000001523` | `2026-06-29T23:24:39-04:00` | 0 | 1 | Autogen hash update; stats/projected stats updated. |
| `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md` | `000000001524` | `2026-06-29T23:24:41-04:00` | 0 | 1 | Autogen hash update; projected stats updated. |
| `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md` | `000000001525` | `2026-06-29T23:24:43-04:00` | 0 | 1 | Autogen hash update; projected stats updated. |
| `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md` | `000000001526` | `2026-06-29T23:24:45-04:00` | 0 | 1 | Autogen hash update; projected stats updated. |
| `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md` | `000000001527` | `2026-06-29T23:24:46-04:00` | 0 | 1 | Autogen hash update; stats/projected stats updated. |
| `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md` | `000000001528` | `2026-06-29T23:24:48-04:00` | 0 | 1 | Stats/projected stats updated; no remaining emitter. |
| `by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md` | `000000001529` | `2026-06-29T23:24:50-04:00` | 0 | 1 | Projected stats updated; no remaining emitter. |
| `by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md` | `000000001530` | `2026-06-29T23:24:56-04:00` | 0 | 1 | Projected stats updated; no remaining emitter. |
| `by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md` | `000000001531` | `2026-06-29T23:25:05-04:00` | 0 | 1 | Autogen hash update; owner/emitter `00005L`; projected stats updated. |
| `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md` | `000000001532` | `2026-06-29T23:25:14-04:00` | 0 | 1 | Autogen hash update; owner/emitter `00005L`; projected stats updated. |
| `by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md` | `000000001533` | `2026-06-29T23:25:16-04:00` | 0 | 1 | Autogen hash update; owner/emitter `0000AJ`; projected stats updated. |
| `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md` | `000000001534` | `2026-06-29T23:25:18-04:00` | 0 | 1 | Autogen hash update; owner/emitter `0000AJ`; projected stats updated. |

Generated output inspection:

- File: `auto-generated/NexusTK/util/FunctionObjects.cpp`
- Header after waiting for deferred generated refresh: `validator-command-id: 000000001534`
- Header timestamp: `validator-refreshed-at: 2026-06-29T23:25:18-04:00`
- `Empty Emitter Marker` count: `0`
- Accepted UID0000JO rows are no longer empty markers. UID0001WQ now emits the central declaration block; class/vtable/RTTI rows emit comment markers; scalar destructor rows UID000123, UID0001CQ, and UID0002N3 no longer route to this generated output.

Leases:

- Initial B013 lease batch succeeded for all 21 by-* docs.
- The initial lease window expired before the first validator batch completed, so B013 reacquired a fresh lease for the same 21 docs and reran the scoped validators under that fresh lease.
- `python .\leaser.py B013 unlease` released all 21 docs successfully.
- `current_leases.md` confirmed no active leases afterward.

Validator-owned side effects:

- Scoped validators updated `tools/validator.ini` autogen registry entries.
- Scoped validators updated generated/project-level stats such as `project-level/-auto-completion-stats.md`.
- Deferred generated refresh updated `auto-generated/NexusTK/util/FunctionObjects.cpp`.
- No generated file, project-level generated file, validator state file, lock file, IDA DB, executed archive, supervisor ledger, optional by-meta breadcrumb, or manual `-coverage-report.md` was manually edited.

Unapplied accepted items:

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0000JO-FunctionObjects-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0000JO-FunctionObjects-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T23:33:33","uid":"0000JO"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000JO-FunctionObjects-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0000JO-FunctionObjects-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000JO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
