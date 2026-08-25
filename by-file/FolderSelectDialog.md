*** UID:0000JF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FolderSelectDialog

## Status

- Reconstructable: true. Confidence is very strong for dialog ownership, source path, class/data child routing, callback ownership/use, retained drive-list helper classification, all 38 vtable cells, the complete 20-record reachable RTTI graph, drive-root literal/buffer ownership, and the completed FolderSelectDialog/FolderTreePane split.
- Proposed source file: `ui/dialogs/FolderSelectDialog.cpp`.
- Proposed header: `ui/dialogs/FolderSelectDialog.h`.
- Current recovered source: `source-3/simroot_v2/class_FolderSelectDialog.cpp`; use only as a provenance/search hint because generated owner and field labels are polluted.
- Main class: [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md).
- Related hosted control: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), `ui/controls/FolderTreePane.cpp`.
- Main address doc: [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md).
- Exact split children: [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md), [UID:000458][0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding](by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md), [UID:000459][0x004b1920-0x004b1a00.FolderSelectDialogOnCommand](by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md), [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md), [UID:00045B][0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding](by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md), and [UID:00045C][0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor](by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md).
- Exact data children: [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) now marker-covered through [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md), [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md), [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md).
- Caller/callback consumer: [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) constructs the concrete callback object and opens the dialog; it is not the owner of this source module.
- Evidence basis: existing by-* documentation plus B014 2026-06-19 raw PE/IDA source-quality reanalysis and the B013 2026-06-26 accepted report implementation.

## File Role

`FolderSelectDialog.cpp` owns the modal folder-picker dialog used by the music settings UI. It builds a `DialogPane`, creates a drive-list child through inherited DialogPane control-manager/list infrastructure, creates and owns a [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) child control pointer, enumerates logical drives through Win32, lets the user switch drive roots, and returns either the selected path or an empty result through an owned callback object.

This file owns dialog-specific behavior:

- `FolderSelectDialog` class declaration, constructor, virtual command handler, ordinary destructor definition, and compiler-emitted vtable consequences.
- `FolderTreePane *m_folderTreePane` at `this+0x26c`.
- `FolderSelectCallback *m_resultCallback` at `this+0x270`, owned by the dialog and released by its destructor.
- Dialog drive-list setup and command handling.
- Retained/no-entry drive-list helper `PopulateDriveList()` at `0x004b1a00-0x004b1b05`.
- Read-only drive-root literal `L"X:\\"` / `kDefaultDriveRootLiteral` at [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md), emitted by that target as `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`.
- Mutable file-static drive-root buffer `s_driveRootBuffer` at [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md), `94/96`, emitted as a mutable `wchar_t[]` declaration at position `5`. The older `s_driveRootName` spelling is historical only.

This file should stay in `ui/dialogs/`. The hosted filesystem tree is a reusable control and remains separate under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), `ui/controls/FolderTreePane.cpp`.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) | `0x004b1590-0x004b1b87` | Dialog construction, command handling, callback result dispatch, retained drive-list helper, destructor declaration/definition route, and compiler-generated secondary/tertiary destructor thunks. |
| [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md) | `0x004b1590-0x004b18d6` | Builds controls, stores callback at `+0x270` / 624 as `m_resultCallback`, creates `FolderTreePane` at `+0x26c` / 620 after a `0x17c` / 380 allocation, uses inherited control/list infra at `+0x1fc` / 508, populates the drive list inline with `GetLogicalDrives`, `GetCurrentDirectoryA(0x104)` / 260, `_toupper`, 32 slots, `s_driveRootBuffer`, and `0x118` / 280 `StringMenuItem` allocations, selects current drive, optionally navigates to an initial path through `0x004b2730`, and emits the accepted complete source-authored constructor body through this file at position `10`. B003 MCP session `2ec9c08f` reconfirmed size `0x346` / 838, `0x004b18d6` not a function, the one MusicControlDialog caller at `0x0052986d`, and zero xrefs to retained helper `0x004b1a00`, so the implemented body preserves inline drive population and does not synthesize a `PopulateDriveList()` call. |
| [UID:000458][0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding](by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md) | `0x004b18d6-0x004b1920` | EH cleanup/vtable cleanup tail plus padding; compiler artifact, not a separate source method. |
| [UID:000459][0x004b1920-0x004b1a00.FolderSelectDialogOnCommand](by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md) | `0x004b1920-0x004b1a00`; vtable slot `0x0061a4a4` | Current `94/95`; handles OK selected-path callback, cancel empty callback, drive-list notification, and close behavior. Its position-`20` body uses accepted `GetChild<PopupMenuControlPane>(0)` for the shared child-zero lookup while preserving every unrelated line. |
| [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md) | `0x004b1a00-0x004b1b05` | Private retained/no-entry method at `93/95`; emits the typed-child, signed-byte-parity drive enumeration body at position `30`. Exact MCP/raw scans find no code/data/immediate/rel32/VA/RVA/vtable inbound route, so no live caller is invented. |
| [UID:00045B][0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding](by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md) | `0x004b1b05-0x004b1b20` | Compiler-generated `this` adjustors into the scalar deleting destructor plus padding; not handwritten source. |
| [UID:00045C][0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor](by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md) | `0x004b1b20-0x004b1b87` | Source-ready ordinary `FolderSelectDialog::~FolderSelectDialog()` at `94/96`; position `40` emits `delete m_resultCallback;`. Derived-vptr resets, callback vslot/flag syntax, implicit DialogPane teardown, scalar flags, storage-free/guarded-size paths, return ABI, and adjustor routes remain compiler lowering. |
| [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) | `0x0061a45c-0x0061a4f4` | Exact three-view class vtable data emitted from the `FolderSelectDialog` declaration; formal output is the covered-by marker through [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md), not an empty emitter and not a handwritten vtable array. |
| [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md) | `0x0061a4f4-0x0061a4fc` | UTF-16 `X:\` literal / `kDefaultDriveRootLiteral` emitted as `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`; constructor drive-list setup loads both dwords at `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`. |
| [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) | `0x0066da88-0x0066da90` | `94/96` mutable UTF-16 `X:\` buffer emitted at position `5`; exactly four refs are constructor/helper write-use pairs. Each StringMenuItem synchronously copies the root, so the shared non-reentrant buffer is not retained by appended items. |
| Concrete music callback wrapper | `0x0052a3e0-0x0052a4de` | Owned by [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) as reusable callback-template support and constructed by [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md), not by this file. |

## Source Split And Ownership

Accepted split:

- `FolderSelectDialog.cpp` owns the dialog/source policy and drive-root data.
- `FolderTreePane.cpp` owns the reusable tree control, tree/vector/template helpers, selected-path construction, filesystem enumeration, and tree-control vtables.
- `MusicControlDialog.cpp` owns only the caller route and concrete callback binding for music-folder selection.
- `FunctionObjects` owns the reusable callback template/base declarations and compiler-emitted invoke/destructor support for concrete callback wrappers.

The current generated `class_FolderSelectDialog.cpp` and surrounding generated output include stale or polluted labels. Reject final-source use of:

- `boost::exception` for the FolderSelectDialog destructor/base cleanup.
- `TransferReplyAlert` for DialogPane teardown.
- `ChattingColorPane` in this dialog or its callback path.
- Raw `sub_4B1A00` / `FUN_004b1a00` for the drive-list helper.
- `asc_66DA88` for the mutable drive-root buffer.
- `mbr_26c`, `mbr_270`, or `field_1fc` as final class member names.

## Evidence Notes

- Raw PE/IDA checks confirm the exact executable island boundaries: constructor `0x004b1590-0x004b18d6`, constructor cleanup/padding through `0x004b1920`, source-facing `OnControlCommand` `0x004b1920-0x004b1a00`, drive helper `0x004b1a00-0x004b1b05`, adjustor thunks `0x004b1b05` and `0x004b1b10`, scalar deleting destructor `0x004b1b20-0x004b1b87`, and padding before [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) at `0x004b1b90`.
- The constructor at `0x004b1590` has one checked rel32 caller at `0x0052986d` inside [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) command handling.
- `OnControlCommand` at `0x004b1920` is reached through vtable slot `0x0061a4a4`, not through normal code calls.
- `0x004b1a00` has a normal source body, exact SHA256 `655962B7DBE4BDA3163366C27DE0A7719309CA5A9072FFE50A2BCE760272C1BF`, 96 primary instructions, ten main-flow blocks plus three compiler EH blocks, and a 260-byte path local. Raw PE/MCP code/data/immediate/rel32/VA/RVA/vtable scans found no inbound route. It remains a retained/no-entry private method under this file, not padding, a thunk, compiler-only code, or a free/static helper.
- Constructor stores the callback at `this+0x270`; OK/cancel dispatch invoke callback virtual slot `+12`; destructor releases through virtual slot `+0` with deleting flag `1`.
- The constructor/use/destructor sequence proves an owned result callback and an explicit non-empty destructor. UID00045C is the only ordinary-destructor source anchor; no separate ordinary function or endpoint entry exists.
- Constructor stores the hosted `FolderTreePane` pointer at `this+0x26c`; `OnControlCommand` calls `FolderTreePane::BuildSelectedPath` / selected-path construction at `0x004b3090` and `FolderTreePane::SetRootNodeName` at `0x004b25e0`.
- `DialogPane+0x1fc` is inherited `List *m_controlManager` storage used to access the drive-list child. The binary invokes List's `GetElementAt(0)` virtual slot and dereferences the returned four-byte pointer slot; current source support expresses this as `GetChild<PopupMenuControlPane>(0)`. It is not a dedicated FolderSelectDialog field. The former undefined `GetControl(0)` draft is superseded.
- The read-only literal [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md) has bytes `58 00 3a 00 5c 00 00 00` (`L"X:\\"`) and is now emitted by that target as `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`. B006 MCP session `43ccf853` reconfirmed `server_health ok`, not-a-function status, and two constructor dword loads: `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`.
- The same B006 byte-pattern search found this exact byte sequence only at read-only UID0003BG and mutable [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md). Keep the two declarations separate: UID0003BG is the file-local read-only literal, while UID00027D remains mutable drive-list buffer state.
- The mutable buffer [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) starts with the same UTF-16 content and has constructor write/use refs `0x004b183f` / `0x004b185b` plus helper write/use refs `0x004b1a8b` / `0x004b1aaa`.
- The retained helper performs child lookup, `GetLogicalDrives`, ignored-return `GetCurrentDirectoryA`, signed-byte `_toupper`, then all 32 DWORD bit tests in that order. A zero drive mask still performs path normalization/tests but appends/selects nothing; failed/empty/UNC path input is not repaired; no control/API/allocation guard is introduced.
- Each available drive changes only the first WCHAR, allocates a `0x118` StringMenuItem, synchronously copies its root into owned inline text, appends in ascending bit order, and selects `GetItemCount() - 1` when the drive index matches. `1u` preserves defined bit-31 source semantics; compiler EH cleanup handles constructor throws and is not handwritten.
- Constructor `0x004b17e0-0x004b188f` contains the same control/API/data/allocation/append/count/select sequence locally. Manual retained duplication/refactor ranks above automatic inlining because the helper is large and EH-bearing; inlining remains possible, different-build retention is unsupported, and no source call is synthesized.
- Vtable data refs tie `0x0061a45c`, `0x0061a4bc`, and `0x0061a4ec` to constructor stores, constructor cleanup stores, and destructor stores; `0x0061a4a4` is the `OnControlCommand` slot and `0x0061a4bc` / `0x0061a4ec` route adjustor thunks.
- B003 MCP session `2ec9c08f` refreshed UID000457 specifically: active `NexusTK.exe.i64`, `server_health ok`, constructor size `0x346` / 838, non-function exclusive end `0x004b18d6`, preceding/successor padding signatures, vtable stores to `0x0061a45c` / `0x0061a4bc` / `0x0061a4ec`, callback/tree/control offsets `+0x270` / `+0x26c` / `+0x1fc`, `FolderTreePane` allocation `0x17c`, inline drive loop, `StringMenuItem` allocation `0x118`, initial-path call to `0x004b2730`, and `xrefs_to 0x004b1a00` total `0`.
- B010 MCP session `supervisor_20260628_resume` rechecked [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) as exact class-declaration data before the empty-emitter repair: range size `0x98` / `152`; IDB names `??_7FolderSelectDialog@@6B@`, `??_7FolderSelectDialog@@6B@_0`, and `??_7FolderSelectDialog@@6B@_1`; dwords `0x0061a45c -> 0x004b1b20`, `0x0061a4a4 -> 0x004b1920`, `0x0061a4bc -> 0x004b1b05`, and `0x0061a4ec -> 0x004b1b10`; vtable base pointer occurrences at the constructor/cleanup/destructor store sites; no direct pointer to the internal slot cell `0x0061a4a4`; and successor bytes `58 00 3a 00 5c 00 00 00` for the `X:\` child at `0x0061a4f4`. Generated `FolderSelectDialog.cpp` should show the one-line covered-by marker for [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) after validator refresh, not `Empty Emitter Marker`.

## Heuristic / Inference Reanalysis And Validation

### File Owner

Best-supported inference: keep [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) as `NexusTK/ui/dialogs/FolderSelectDialog.cpp`.

Rejected alternatives:

- `MusicControlDialog.cpp` is rejected as owner because its role is constructing a concrete callback wrapper and calling the dialog constructor. It has no ownership of the dialog vtables, data items, or method island.
- `FolderTreePane.cpp` is rejected as owner for the dialog because the tree is an owned child control stored at `+0x26c`. Tree-control method bodies and templates stay under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).
- A combined FolderSelect/FolderTree source file remains lower probability after B014 reanalysis because by-file, by-class, vtable, and method-split evidence support a dialog/control split.

### Fields And Types

Accepted names:

- `m_folderTreePane` for `this+0x26c`.
- `m_resultCallback` for `this+0x270`.
- `FolderSelectCallback` as a placeholder alias for the final FunctionObjects string-result callback type.
- `s_driveRootBuffer` for [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md). `s_driveRootName` is retained only as a lower-ranked historical spelling.
- `kDefaultDriveRootLiteral` or literal `L"X:\\"` for [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md).

Closed by the accepted whole-file reconstruction:

- The callback template/interface is synchronized with FunctionObjects as `FunctionObjectT<StringBaseW>` through the local `FolderSelectCallback` alias.
- The accepted constructor body and support declarations fix the control-creation, `GetChild<PopupMenuControlPane>(0)`, AppendItem, GetItemCount, and SetSelectedIndex contracts. Unrecoverable original lexical spelling and include order remain score-limited rather than open source-shape blockers.

### Retained Helper

`0x004b1a00` is accepted as `PopulateDriveList()` / drive-list population helper. It is not padding, not a thunk, and not compiler-only. It is also not proven to be live in the checked binary. The completed six-child split keeps method-body C++ in exact child [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md) with a no-entry note, while [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md) remains the non-emitting aggregate.

### First-Draft C++ Policy

The class page [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) emits class-level declarations with `[[CHILDREN]]`. Method bodies and source-owned markers now route directly through this file page [UID:0000JF] so out-of-class definitions do not land inside the class declaration. [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md) is a non-emitting split container; exact children carry the accepted formal dispositions:

- [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md): source-declared/generated-binary vtable data covered by the class declaration marker through [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md); generated output should no longer report it as an `Empty Emitter Marker`.
- [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md): source-declared/generated-binary read-only literal emitted through this file as `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`; do not replace it with a generated dword label, a FolderTreePane-owned datum, or the mutable UID00027D buffer declaration.
- [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md): accepted mutable file-static declaration emitted through this file at position `5`, before method markers/bodies.
- [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md): complete accepted source-authored constructor body, emitted through this file at position `10` with inline drive population and no synthetic helper call.
- [UID:000459][0x004b1920-0x004b1a00.FolderSelectDialogOnCommand](by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md): accepted exact `OnControlCommand` body, emitted through this file at position `20`.
- [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md): accepted retained-helper body, emitted through this file at position `30`, with no invented caller.
- [UID:00045C][0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor](by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md): ordinary destructor definition at position `40`; only `delete m_resultCallback;` is handwritten. The compiler supplies null-safe virtual callback destruction, vptr/base teardown, scalar flags, storage-free/guarded-size behavior, return ABI, and adjustors.
- [UID:000458][0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding](by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md) and [UID:00045B][0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding](by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md): reconstructable-true compiler artifacts under their current non-emitting routes, with blank formal C++ because the accepted constructor/destructor source produces their cleanup/thunk consequences.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 95 | The implemented route contains complete constructor, command, helper, destructor, CPP/H, data, compiler-marker, and six-child split dispositions; it records UID00045A `93/95`, UID00027D `94/96`/position `5`, exact inherited control contracts, whole-file inventory, and generated 9/9 emitter closure. |
| Confidence | 96 | Raw PE/IDA evidence, formal source, support declarations, xrefs, vtable/RTTI inventories, data refs, sole caller, and completed split agree. Residual uncertainty is limited to unrecoverable original lexical spelling and include order and does not affect behavior or compile viability. |

## Cross-References

- [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md)
- [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md)
- [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md)
- [UID:000458][0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding](by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md)
- [UID:000459][0x004b1920-0x004b1a00.FolderSelectDialogOnCommand](by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md)
- [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md)
- [UID:00045B][0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding](by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md)
- [UID:00045C][0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor](by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md)
- [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md)
- [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md)
- [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Historical Assumptions And Corrections

### Historical Primary-Page Research Receipt

- The exact preimplementation primary-page artifact was SHA256 `6340710B86429B34326F549F8F62E6D5C351F4BD73C221B2E476BEB4DD10A803`, 35,560 bytes, with completion/confidence score `88/90`. This is a historical research receipt only; current page authority comes from the current physical file and its validator receipt.

- The B013 marker-only UID00045C policy is superseded: it correctly rejected handwritten scalar-wrapper ABI mechanics but left the declared virtual destructor without a source definition. Exact callback lifecycle and absence of a separate ordinary destructor now support the one-statement position-`40` body.
- Older wording treated FolderTreePane co-location as still plausible if no other constructor users were found. That is superseded for this source-quality pass: keep the control in [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) because the object model and support docs justify a reusable `ui/controls/FolderTreePane.cpp`.
- Older wording left the drive helper as a generic active-Wave3 caveat. That is superseded by the retained/no-entry classification.
- Older wording and generated output used `asc_66DA88`, `TransferReplyAlert`, `boost::exception`, and raw `sub_4B1A00` names. These remain search hints only and are rejected final source names.
- The former active UID000459 `87/91` and file `88/90` scores are historical pre-whole-file values. Current accepted scores are UID000459 `94/95` and file `95/96` after complete source, split, vtable, RTTI, and generated-output closure.

## Accepted Source Route And Generated-History Framing

- Canonical source remains NexusTK/ui/dialogs/FolderSelectDialog.cpp with required sibling FolderSelectDialog.h.
- CPP order is UID000059 include/root, UID0003BG const literal at position 2, UID00027D mutable buffer at position 5, UID000457 constructor at position 10, UID000459 OnControlCommand at position 20, UID00045A PopulateDriveList at position 30, and UID00045C ordinary destructor at position 40. UID0003PA/UID0003BF are compiler-evidence markers; reconstructable-true UID000154/UID000458/UID00045B remain non-emitting.
- H source belongs to UID000059 only. Function children do not duplicate declarations.
- Handwritten source excludes constructor cleanup, two adjustor thunks, vtable stores, RTTI/vtable bytes, scalar-delete flags, guarded-size/storage-free paths, base teardown, and padding.
- The dated preimplementation generated snapshot from validator command 000000027069 had FolderSelectDialog.cpp at 4,379 bytes/107 LF/SHA256 E7BA104F52A1FF192714533C8CE986F134E777327A52D9F3A08A9B98D1DE376F, no sibling H, and tracker state 9 items/8 coded/1 empty/88.9 percent. That snapshot is historical; current validator-owned output is authoritative only from a fresh physical read.
- MusicControlDialog owns the sole constructor caller/callback binding. FolderTreePane owns tree selection/root behavior. Neither dependency absorbs FolderSelectDialog source ownership.

## Accepted Whole-File Atomic Inventory


The accepted compilation-unit inventory contains exactly 95 atomic rows: the prior 42 logical source/ownership rows minus five grouped vtable rows, plus 38 atomic vtable cells and 20 reachable RTTI records/padding items. The retained logical table and the V01-V38/R01-R20 refinements below are jointly exhaustive.

| # | UID/route | Range/entity | Disposition |
| --- | --- | --- | --- |
| 1 | 0000JF | FolderSelectDialog.cpp compilation root | FILE owner/emitter |
| 2 | 000059 | FolderSelectDialog class, size 0x274 | H declaration plus CPP child root |
| 3 | 000154 | 0x4b1590-0x4b1b87 aggregate | non-emitting range owner |
| 4 | 000457 | 0x4b1590-0x4b18d6 constructor | handwritten CPP |
| 5 | 000458 | 0x4b18d6-0x4b18e0 | ten CC bytes |
| 6 | 000458 | 0x4b18e0-0x4b1915 | compiler cleanup |
| 7 | 000458 | 0x4b1915-0x4b1920 | eleven CC bytes |
| 8 | 000459 | 0x4b1920-0x4b1a00 | handwritten OnControlCommand |
| 9 | 00045A | 0x4b1a00-0x4b1b05 | retained private handwritten helper |
| 10 | 00045B | 0x4b1b05-0x4b1b10 | -0xa0 adjustor thunk |
| 11 | 00045B | 0x4b1b10-0x4b1b1b | -0xa4 adjustor thunk |
| 12 | 00045B | 0x4b1b1b-0x4b1b20 | five CC bytes |
| 13 | 00045C | 0x4b1b20-0x4b1b87 | destructor source anchor/scalar wrapper |
| 14 | aggregate boundary | 0x4b1585-0x4b1590 | eleven external CC bytes |
| 15 | aggregate boundary | 0x4b1b87-0x4b1b90 | nine external CC bytes |
| 16 | 0003PA | 0x61a458-0x61a45c | RTTI locator pointer |
| 17 | 0003BF | 0x61a45c-0x61a4b8 | primary vtable |
| 18 | 0003BF | 0x61a4b8 | secondary COL pointer |
| 19 | 0003BF | 0x61a4bc-0x61a4e8 | secondary vtable view |
| 20 | 0003BF | 0x61a4e8 | tertiary COL pointer |
| 21 | 0003BF | 0x61a4ec-0x61a4f4 | tertiary vtable view |
| 22 | 0003BG | 0x61a4f4-0x61a4fc | const default-root literal |
| 23 | 00027D | 0x66da88-0x66da90 | mutable root buffer |
| 24 | 000059 | m_folderTreePane +0x26c, m_resultCallback +0x270 | class layout |
| 25 | support | FolderSelectCallback | owned FunctionObjectT<StringBaseW> |
| 26 | support | StringBaseW | StringBase<unsigned short> |
| 27 | external | shared empty title 0x60db20 | existing owner, 214 refs |
| 28 | external | UI layer context 0x69b36c | MainUiGraph owner, 101 refs |
| 29 | import | GetLogicalDrives 0x60d30c | KERNEL32 external |
| 30 | import | GetCurrentDirectoryA 0x60d1a4 | KERNEL32 external |
| 31 | CRT | toupper | runtime external |
| 32 | support | PopupMenuControlPane/StringMenuItem | existing control owner |
| 33 | support | ImageButtonControlPane | existing button owner |
| 34 | support | RectBounds | existing geometry owner |
| 35 | support | FolderTreePane | existing tree owner; one H declaration repair |
| 36 | support | FunctionObjects | existing callback templates |
| 37 | caller | MusicControlDialog 0x52986d | one caller repair |
| 38 | resource | no file-owned resource | exact no-resource disposition |
| 39 | neighbor | preceding .rdata item before 0x61a458 | external, no merge |
| 40 | neighbor | following .rdata item after 0x61a4fc | external, no merge |
| 41 | neighbor | preceding .data item before 0x66da88 | external, no merge |
| 42 | neighbor | following .data item after 0x66da90 | external, no merge |

All V01-V38 items are distinct four-byte IDA data items with absent type and empty regular/repeatable comments. Only V01, V25, and V37 have the names shown; every other cell name is empty. Every cell is physically UID0003BF FolderSelectDialog compiler vtable data and needs no handwritten array. Source effects are limited to V01/V19/V25/V37 through the FolderSelectDialog virtual destructor/OnControlCommand declarations and bodies; inherited targets remain with their external base/runtime source owners.

| ID | Exact range/head and value | Exact xrefs | Source/CPP-H disposition | Exact destination |
| --- | --- | --- | --- | --- |
| V01 | 0x61a45c-0x61a460, ??_7FolderSelectDialog@@6B@, 0x4b1b20 FolderSelectDialog_ScalarDeletingDestructor | outgoing 0x4b1b20; incoming stores 0x4b1601/0x4b18e9/0x4b1b2c; total 4 | virtual destructor H/CPP; compiler slot | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V01 |
| V02 | 0x61a460-0x61a464, 0x4f4b10 LObject__GetRuntimeClass | one outgoing 0x4f4b10 | inherited external LObject source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V02 |
| V03 | 0x61a464-0x61a468, 0x41b6c0 LObject__OnChangeMessage | one outgoing 0x41b6c0 | inherited external LObject source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V03 |
| V04 | 0x61a468-0x61a46c, 0x4b8e20 sub_4B8E20 | one outgoing 0x4b8e20 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V04 |
| V05 | 0x61a46c-0x61a470, 0x41d680 Pane_DrawOnTarget | one outgoing 0x41d680 | inherited external Pane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V05 |
| V06 | 0x61a470-0x61a474, 0x544730 sub_544730 | one outgoing 0x544730 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V06 |
| V07 | 0x61a474-0x61a478, 0x544750 sub_544750 | one outgoing 0x544750 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V07 |
| V08 | 0x61a478-0x61a47c, 0x5447a0 Pane_GetParentPane | one outgoing 0x5447a0 | inherited external Pane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V08 |
| V09 | 0x61a47c-0x61a480, 0x544800 Pane_InvalidateRect | one outgoing 0x544800 | inherited external Pane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V09 |
| V10 | 0x61a480-0x61a484, 0x544a20 Pane_GetDescription | one outgoing 0x544a20 | inherited external Pane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V10 |
| V11 | 0x61a484-0x61a488, 0x544b80 sub_544B80 | one outgoing 0x544b80 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V11 |
| V12 | 0x61a488-0x61a48c, 0x544bd0 sub_544BD0 | one outgoing 0x544bd0 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V12 |
| V13 | 0x61a48c-0x61a490, 0x49dfd0 DialogPane__OnCreate | one outgoing 0x49dfd0 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V13 |
| V14 | 0x61a490-0x61a494, 0x544cb0 sub_544CB0 | one outgoing 0x544cb0 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V14 |
| V15 | 0x61a494-0x61a498, 0x49e1c0 DialogPane_OnDestroy | one outgoing 0x49e1c0 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V15 |
| V16 | 0x61a498-0x61a49c, 0x49e190 DialogPane__OnShow | one outgoing 0x49e190 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V16 |
| V17 | 0x61a49c-0x61a4a0, 0x49e210 DialogPane_OnHide | one outgoing 0x49e210 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V17 |
| V18 | 0x61a4a0-0x61a4a4, 0x49f090 DialogPane_OnPaint | one outgoing 0x49f090 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V18 |
| V19 | 0x61a4a4-0x61a4a8, 0x4b1920 FolderSelectDialog OnControlCommand | one outgoing 0x4b1920 | virtual OnControlCommand H/CPP; compiler slot | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V19 |
| V20 | 0x61a4a8-0x61a4ac, 0x41b6a0 @_guard_check_icall_nop@4 | one outgoing 0x41b6a0 | inherited external/runtime source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V20 |
| V21 | 0x61a4ac-0x61a4b0, 0x49f1d0 DialogPane_DrawBackground | one outgoing 0x49f1d0 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V21 |
| V22 | 0x61a4b0-0x61a4b4, 0x49f2e0 DialogPane_DrawBorder | one outgoing 0x49f2e0 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V22 |
| V23 | 0x61a4b4-0x61a4b8, 0x49fc00 DialogPane_SetHoverControl | one outgoing 0x49fc00 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V23 |
| V24 | 0x61a4b8-0x61a4bc, 0x64786c secondary COL | one outgoing 0x64786c | compiler RTTI pointer; no source storage | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V24 |
| V25 | 0x61a4bc-0x61a4c0, ??_7FolderSelectDialog@@6B@_0, 0x4b1b05 adjustor | outgoing 0x4b1b05; incoming stores 0x4b1607/0x4b18ef/0x4b1b32; total 4 | virtual destructor/inheritance; compiler thunk/slot | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V25 |
| V26 | 0x61a4c0-0x61a4c4, 0x49e240 sub_49E240 | one outgoing 0x49e240 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V26 |
| V27 | 0x61a4c4-0x61a4c8, 0x49e6e0 DialogPane_HandleKeyOrTextEvent | one outgoing 0x49e6e0 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V27 |
| V28 | 0x61a4c8-0x61a4cc, 0x49ea60 DialogPane_HandleImeEvent | one outgoing 0x49ea60 | inherited external DialogPane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V28 |
| V29 | 0x61a4cc-0x61a4d0, 0x41d6b0 sub_41D6B0 | one outgoing 0x41d6b0 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V29 |
| V30 | 0x61a4d0-0x61a4d4, 0x544df0 sub_544DF0 | one outgoing 0x544df0 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V30 |
| V31 | 0x61a4d4-0x61a4d8, 0x544e00 sub_544E00 | one outgoing 0x544e00 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V31 |
| V32 | 0x61a4d8-0x61a4dc, 0x4a89f0 sub_4A89F0 | one outgoing 0x4a89f0 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V32 |
| V33 | 0x61a4dc-0x61a4e0, 0x544e10 sub_544E10 | one outgoing 0x544e10 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V33 |
| V34 | 0x61a4e0-0x61a4e4, 0x544e30 sub_544E30 | one outgoing 0x544e30 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V34 |
| V35 | 0x61a4e4-0x61a4e8, 0x544e70 sub_544E70 | one outgoing 0x544e70 | inherited external base source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V35 |
| V36 | 0x61a4e8-0x61a4ec, 0x647880 tertiary COL | one outgoing 0x647880 | compiler RTTI pointer; no source storage | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V36 |
| V37 | 0x61a4ec-0x61a4f0, ??_7FolderSelectDialog@@6B@_1, 0x4b1b10 adjustor | outgoing 0x4b1b10; incoming stores 0x4b1611/0x4b18f9/0x4b1b3c; total 4 | virtual destructor/inheritance; compiler thunk/slot | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V37 |
| V38 | 0x61a4f0-0x61a4f4, 0x544e90 Pane_OnTimer | one outgoing 0x544e90 | inherited external Pane source | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md / V38 |

R01-R19 are head data items with absent public type. The three COL heads have regular comment signature; the CHD head has signature; the array head has reference to base class decription 1; each BCD head has reference to type description; each TypeDescriptor head has reference to RTTI's vftable. Repeatable comments are empty. R20 has no name/type/comments/xrefs. FolderSelectDialog-owned records are compiler products of the UID000059 H inheritance/virtual declarations; shared base records remain externally owned and require no FolderSelectDialog CPP/H.

| ID | Exact record/range and fields | Exact graph xrefs | Owner/source and exact destination |
| --- | --- | --- | --- |
| R01 | 0x64780c-0x647820 primary COL ??_R4FolderSelectDialog@@6B@: 0,0,0, TD 0x67619c, CHD 0x647820 | incoming 0x61a458; outgoing TD/CHD | FolderSelectDialog compiler RTTI; by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md / R01 |
| R02 | 0x64786c-0x647880 secondary COL ??_R4FolderSelectDialog@@6B@_0: 0,0xa0,0, TD 0x67619c, CHD 0x647820 | incoming 0x61a4b8; outgoing TD/CHD | FolderSelectDialog compiler RTTI; by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md / R02 |
| R03 | 0x647880-0x647894 tertiary COL ??_R4FolderSelectDialog@@6B@_1: 0,0xa4,0, TD 0x67619c, CHD 0x647820 | incoming 0x61a4e8; outgoing TD/CHD | FolderSelectDialog compiler RTTI; by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md / R03 |
| R04 | 0x67619c-0x6761c0 TD ??_R0?AVFolderSelectDialog@@@8: vfptr 0x635078, spare 0, .?AVFolderSelectDialog@@ | incoming 0x647818/0x647850/0x647878/0x64788c; outgoing 0x635078 | FolderSelectDialog compiler RTTI; by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md / R04 |
| R05 | 0x647820-0x647830 CHD ??_R3FolderSelectDialog@@8: signature 0, attrs 0x100, count 7, array 0x647830 | incoming 0x64781c/0x647868/0x64787c/0x647890; outgoing 0x647830 | FolderSelectDialog compiler RTTI; by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md / R05 |
| R06 | 0x647830-0x64784c array ??_R2FolderSelectDialog@@8: 0x647850,0x640790,0x640540,0x640584,0x640348,0x6405bc,0x64060c | incoming 0x64782c; seven listed outgoing edges | FolderSelectDialog compiler RTTI; by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md / R06 |
| R07 | 0x647850-0x64786c self BCD ??_R1A@?0A@EA@FolderSelectDialog@@8: TD 0x67619c, contained 6, PMD 0/-1/0, attrs 0x40, CHD 0x647820 | incoming 0x647830; outgoing TD/CHD | FolderSelectDialog compiler RTTI; by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md / R07 |
| R08 | 0x640790-0x6407ac DialogPane BCD: TD 0x673a70, contained 5, PMD 0/-1/0, attrs 0x40, CHD 0x6407ac | total incoming 118; graph edge 0x647834; outgoing TD 0x673a70/CHD 0x6407ac | external DialogPane; by-class/DialogPane.md / FolderSelectDialog RTTI dependency R08 |
| R09 | 0x640540-0x64055c Pane BCD: TD 0x6739a0, contained 4, PMD 0/-1/0, attrs 0x40, CHD 0x64055c | total incoming 373; graph edge 0x647838; outgoing TD 0x6739a0/CHD 0x64055c | external Pane; by-class/Pane.md / FolderSelectDialog RTTI dependency R09 |
| R10 | 0x640584-0x6405a0 GrafPort BCD: TD 0x6739b4, contained 1, PMD 0/-1/0, attrs 0x40, CHD 0x6405a0 | total incoming 374; graph edge 0x64783c; outgoing TD 0x6739b4/CHD 0x6405a0 | external GrafPort; by-class/GrafPort.md / FolderSelectDialog RTTI dependency R10 |
| R11 | 0x640348-0x640364 LObject BCD: TD 0x6738c0, contained 0, PMD 0/-1/0, attrs 0x40, CHD 0x640364 | total incoming 481; graph edge 0x647840; outgoing TD 0x6738c0/CHD 0x640364 | external LObject; by-class/LObject.md / FolderSelectDialog RTTI dependency R11 |
| R12 | 0x6405bc-0x6405d8 EventHandler BCD: TD 0x6739cc, contained 0, PMD 0xa0/-1/0, attrs 0x40, CHD 0x6405d8 | total incoming 373; graph edge 0x647844; outgoing TD 0x6739cc/CHD 0x6405d8 | external EventHandler; by-class/EventHandler.md / FolderSelectDialog RTTI dependency R12 |
| R13 | 0x64060c-0x640628 TimerHandler BCD: TD 0x6739e8, contained 0, PMD 0xa4/-1/0, attrs 0x40, CHD 0x640628 | total incoming 373; graph edge 0x647848; outgoing TD 0x6739e8/CHD 0x640628 | external TimerHandler; by-class/TimerHandler.md / FolderSelectDialog RTTI dependency R13 |
| R14 | 0x673a70-0x673a8c DialogPane TD: vfptr 0x635078, spare 0, .?AVDialogPane@@ | total incoming 4 including 0x640790; outgoing 0x635078 | external DialogPane; by-class/DialogPane.md / FolderSelectDialog RTTI dependency R14 |
| R15 | 0x6739a0-0x6739b4 Pane TD: vfptr 0x635078, spare 0, .?AVPane@@ | total incoming 5 including 0x640540; outgoing 0x635078 | external Pane; by-class/Pane.md / FolderSelectDialog RTTI dependency R15 |
| R16 | 0x6739b4-0x6739cc GrafPort TD: vfptr 0x635078, spare 0, .?AVGrafPort@@ | total incoming 3 including 0x640584; outgoing 0x635078 | external GrafPort; by-class/GrafPort.md / FolderSelectDialog RTTI dependency R16 |
| R17 | 0x6738c0-0x6738d8 LObject TD: vfptr 0x635078, spare 0, .?AVLObject@@ | total incoming 3 including 0x640348; outgoing 0x635078 | external LObject; by-class/LObject.md / FolderSelectDialog RTTI dependency R17 |
| R18 | 0x6739cc-0x6739e8 EventHandler TD: vfptr 0x635078, spare 0, .?AVEventHandler@@ | total incoming 4 including 0x6405bc; outgoing 0x635078 | external EventHandler; by-class/EventHandler.md / FolderSelectDialog RTTI dependency R18 |
| R19 | 0x6739e8-0x673a04 TimerHandler TD: vfptr 0x635078, spare 0, .?AVTimerHandler@@ | total incoming 5 including 0x64060c; outgoing 0x635078 | external TimerHandler; by-class/TimerHandler.md / FolderSelectDialog RTTI dependency R19 |
| R20 | 0x64784c-0x647850 zero alignment item | xref total 0 | FolderSelectDialog compiler padding, no CPP/H; by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md / R20 |


## Changes

- 2026-07-14 B005 accepted UID00045C implementation callback:
  - Preserved file score `88/90`, `NexusTK/ui/dialogs/` route, class/file metadata, all source inventory, and unrelated method/data policy.
  - Synchronized position `40` to emit the ordinary owned-callback destructor body rather than the historical marker; all vptr/base/flags/free/guard/return/thunk mechanics remain compiler-only.
  - Added exact lifecycle, no-separate-destructor, source/compiler, polluted-name, and lexical-confidence dispositions without changing other emitter positions.
- 2026-07-14 B005 accepted UID00045A support synchronization:
  - Preserved file score `88/90`, `NexusTK/ui/dialogs/` route, class/file ownership, and unrelated source inventory.
  - Synchronized UID00027D at position `5`, OnCommand at position `20`, UID00045A at position `30`, exact typed-child/List lowering, target hash/ABI/CFG/API/signedness/allocation behavior, static buffer lifetime/copy closure, exhaustive no-entry negatives, constructor duplicate ranking, and generated-output expectations. No generated file was edited manually.

- 2026-07-07 B006 [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md) source-quality implementation:
  - What existed before: the file page listed UID0003BG as the read-only `L"X:\\"` / `kDefaultDriveRootLiteral` child, but the exact child still emitted only an empty marker and file evidence named only the first constructor read.
  - Changed to: documented UID0003BG as a source-declared/generated-binary literal emitted through this file as `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`, while preserving [UID:0000JF] as the file route and keeping [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) as separate mutable state.
  - Summary/evidence: B006 MCP session `43ccf853` returned `server_health ok`, bytes `58 00 3a 00 5c 00 00 00`, not-a-function status, full-literal constructor loads `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`, duplicate pattern only at the mutable buffer `0x0066da88`, and successor boundary `0x0061a4fc -> 0x0064791c`.
- 2026-07-03 B003 accepted implementation callback:
  - What existed before: the file page described UID000457's constructor marker and behavior from earlier B013/B014 evidence but did not include the refreshed `2ec9c08f` session details or updated target score.
  - Changed to: UID000457 is documented as `86/91`, still emitting the formal marker through this file at position `10`; file metadata remains `88/90`.
  - Summary/evidence: B003 current MCP evidence reconfirmed the exact half-open function range, constructor boundary/padding, vtable stores, callback/tree/control offsets, FolderTreePane and StringMenuItem allocation sizes, inline drive loop, initial-path route, MusicControlDialog caller/callback provider route, and zero xrefs to retained `PopulateDriveList()`.
- 2026-06-28 B010 accepted empty-emitter repair:
  - What existed before: [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) was listed as plain class vtable data, while generated `FolderSelectDialog.cpp` still showed it as an empty emitter.
  - Changed to: documented [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) as marker-covered class vtable data emitted through [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md), with generated output expected to contain the covered-by marker rather than `Empty Emitter Marker`.
  - Summary/evidence: B010 MCP `supervisor_20260628_resume` reconfirmed the `0x98` byte range, three `FolderSelectDialog` vtable names, slot dwords for destructor/`OnCommand`/adjustor thunks, constructor/cleanup/destructor pointer stores, and `0x0061a4f4` `X:\` successor boundary.
- 2026-06-26 B013 accepted report implementation:
  - What existed before: the file page documented the exact B001 child split but still said the child formal C++ blocks remained blank for the split-stage callback.
  - Changed to: documented file-scope child emitter routing through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md): constructor marker position `10`, `OnCommand` body position `20`, retained `PopulateDriveList` body/no-entry policy position `30`, scalar deleting destructor marker position `40`, and cleanup/adjustor children as non-emitting compiler artifacts.
  - Summary/evidence: source path remains `NexusTK/ui/dialogs/`; class page remains declaration-only, while exact by-memory children now contribute method bodies/markers directly to this file root.
- 2026-06-26 B001 accepted split implementation callback:
  - What existed before: proposed contents listed raw subranges and still treated the method/body split as pending.
  - Changed to: proposed contents now link exact child UIDs [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md), [UID:000458][0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding](by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md), [UID:000459][0x004b1920-0x004b1a00.FolderSelectDialogOnCommand](by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md), [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md), [UID:00045B][0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding](by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md), and [UID:00045C][0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor](by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md), while [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md) is documented as a non-emitting split container.
  - Summary/evidence: child pages preserve the accepted range evidence and no-entry/helper/artifact classifications. The old blank-child policy is superseded by the B013 child dispositions above.
- 2026-06-19 B014 accepted implementation callback:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:88`; source path and broad ownership were strong, but final field/helper names, `+0x1fc` inheritance, retained helper liveness, FolderTreePane split, and generated-label rejection were not fully synchronized from the accepted B014 report.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`; source path and `CANONICAL_OWNER:FILE` unchanged.
  - Summary/evidence: incorporated accepted source-quality names and roles for `m_folderTreePane`, `m_resultCallback`, `PopulateDriveList`, `s_driveRootBuffer`, `kDefaultDriveRootLiteral`, the inherited control-manager/list use at `DialogPane+0x1fc`, the MusicControl caller/callback-only role, the FunctionObjects callback-template route, and the FolderTreePane source split.
- 2026-06-11 A003 Batch 213 parent-gate repair:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:82`; the file documented executable behavior but did not include exact read-only child pages for the dialog vtables and local drive-root literal.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`, added exact read-only child references, and updated the evidence basis through the 2026-06-11 live IDA split.
  - Summary/evidence: live IDA confirmed the three vtable bases, constructor/cleanup/destructor stores, the `0x0061a4f4-0x0061a4fc` UTF-16 `X:\` literal, and the `0x0061a4fc` tree RTTI boundary.
- 2026-06-12 C001 Batch C001-007:
  - What existed before: `COMPLETION:85`, `CONFIDENCE:86`; the file parent cleared the gate, but the mutable [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) child was not listed with the exact data children and still carried stale parent-gate text in its own page.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, added the mutable drive-root buffer as an exact data child, and documented C001 session-based IDA evidence for the four `asc_66DA88` refs and shared-global ownership.
- 2026-06-01 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Summary/evidence: existing file page and proposed source-tree entry placed the modal folder picker under `ui/dialogs/`; IDA MCP recheck confirmed the constructor is reached from `MusicControlDialog::HandleControlCommand` at `0x0052986d`, while the embedded tree control remains split to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: modal folder picker role, proposed contents, drive-list helper, MusicControl callback boundary, FolderTreePane split caveat, constructor/command/destructor evidence, and cross-references were documented.
- 2026-06-03 MCP verification and attachment support:
  - What existed before: the page had a valid `NexusTK/ui/dialogs/` path and strong role documentation, but confidence remained `78`, below the parent-attachment threshold for the class.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: fresh IDA MCP lookup, caller/callee, xref, decompile, and disassembly checks reconfirmed function boundaries, MusicControlDialog caller ownership, selected-path callback flow, drive-list helper behavior, vtable xrefs, drive-root buffer ownership, and destructor thunk shape.
