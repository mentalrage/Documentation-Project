*** UID:000059 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FolderSelectDialog.h"

#include <ctype.h>
#include <string.h>
#include <windows.h>

#include "../MainUiGraph.h"
#include "../controls/ButtonControlPane.h"
#include "../controls/FolderTreePane.h"
#include "../core/RectBounds.h"
#include "../menu/PopupMenuControls.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_DIALOGS_FOLDERSELECTDIALOG_H
#define NEXUSTK_UI_DIALOGS_FOLDERSELECTDIALOG_H

#include "../../util/FunctionObjects.h"
#include "../../util/StringBase.h"
#include "../core/DialogPane.h"

class FolderTreePane;

typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;
typedef FunctionObjectT<StringBaseW> FolderSelectCallback;

class FolderSelectDialog : public DialogPane
{
public:
    FolderSelectDialog(FolderSelectCallback *resultCallback,
                       const wchar_t *initialPath);
    virtual ~FolderSelectDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    void PopulateDriveList();

    FolderTreePane *m_folderTreePane;
    FolderSelectCallback *m_resultCallback;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FolderSelectDialog

## Status

- Confidence: very strong for class responsibility, source placement, method-island boundaries, callback ownership/dispatch, direct `FolderTreePane` member ownership, drive-root data ownership, vtable/thunk classification, and the FolderSelectDialog/FolderTreePane source split.
- Likely source file: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), `NexusTK/ui/dialogs/FolderSelectDialog.cpp`.
- Address range: [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md).
- Exact split children: [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md), [UID:000458][0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding](by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md), [UID:000459][0x004b1920-0x004b1a00.FolderSelectDialogOnCommand](by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md), [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md), [UID:00045B][0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding](by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md), and [UID:00045C][0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor](by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md).
- Exact vtable data: [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md), class-owned source-declared/generated-binary data now covered by an explicit formal marker emitted through this class declaration rather than left as an empty emitter.
- Dialog drive-root literal: [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md), file-scope source literal `L"X:\\"` / `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";` emitted through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), not through this class formal block.
- Mutable drive-root buffer: [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md), accepted file-static source declaration `s_driveRootBuffer` at `94/96`, emitted through UID0000JF at position `5`. The earlier alternative spelling `s_driveRootName` is retained only as historical naming uncertainty.
- Related hosted control: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), owned separately by [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) in `NexusTK/ui/controls/FolderTreePane.cpp`.
- Concrete caller/callback binding: [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md) constructs this dialog for music folder selection and supplies a concrete member-function callback; MusicControlDialog is not the owner of this class.
- Generated recovery hint: `class_FolderSelectDialog.cpp`; use only as a search/provenance hint. Generated labels such as `boost::exception`, `TransferReplyAlert`, `ChattingColorPane`, `asc_66DA88`, raw `sub_4B1A00`, `mbr_26c`, `mbr_270`, and final-source use of `field_1fc` are rejected source names.
- Current size: `0x274` (`628`) bytes in Wave3/Ghidra struct data.
- Autogen parent/emitter: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md). The class page emits the CPP include/root and complete H declaration; method bodies come from exact children through UID0000JF. UID000457 supplies the constructor at position `10`, UID000459 supplies `OnControlCommand` at `20`, UID00045A supplies retained `PopulateDriveList` at `30`, and UID00045C supplies the ordinary destructor at `40`. UID0003PA/UID0003BF remain compiler-evidence markers.

## Class Purpose

`FolderSelectDialog` is a `DialogPane`-derived modal folder picker. It creates a drive-list control through inherited DialogPane control-manager/list infrastructure, hosts a [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), provides OK/cancel image buttons, and returns either the selected folder path or an empty result through an owned string-result callback.

The dialog is used by [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md) for local music folder selection. That caller constructs the exact concrete `PlainMemberFunctionObjectT<FolderPathCallback, MusicControlDialog, StringBaseW>` wrapper targeting `MusicControlDialog::FolderPathSelected`, then passes the wrapper into the `FolderSelectDialog` constructor. The older `PlainMemberFunctionObjectT<MusicControlDialog, String>` spelling was a superseded documentation shorthand and is retained here only as historical evidence, not current source authority. The wrapper/template implementation remains under [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); this class owns only the callback pointer and invocation policy.

## Source Ownership And Split

Best-supported owner/emitter: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), `NexusTK/ui/dialogs/FolderSelectDialog.cpp`.

Accepted split:

- `FolderSelectDialog.cpp` owns the modal folder picker class, dialog construction, drive-list setup, OK/cancel result dispatch, the retained/no-entry drive-list helper, drive-root data, vtable/declaration consequences, and the ordinary destructor definition.
- `FolderTreePane.cpp` owns the reusable filesystem tree pane: filesystem enumeration, tree/template helpers, `FolderTreePane::SetRootNodeName`, `FolderTreePane::SelectNodeByPath`, selected-path construction, painting, input, and tree/vector support.
- `MusicControlDialog.cpp` owns the caller route and concrete callback construction for music-folder selection only. It does not own the folder picker class, its vtables, its drive-root buffer/literal, or the tree-control implementation.

Rejected ownership alternatives:

- Folding the class into MusicControlDialog is rejected. The checked binary has a separate constructor, command handler, destructor/thunks, vtable data, drive-root literal/buffer, and source island for FolderSelectDialog.
- Folding FolderTreePane into FolderSelectDialog is rejected. The tree pane has its own class/file pages, reusable control behavior, tree templates, vector support, vtables, and source path under `NexusTK/ui/controls/FolderTreePane.cpp`.
- Using generated `ChattingColorPane`, `TransferReplyAlert`, or `boost::exception` owner labels is rejected as generated/decompiler pollution.

## Layout And Field Names

| Offset or data | Source-facing name | Interpretation |
| --- | --- | --- |
| `DialogPane + 0x1fc` | inherited DialogPane control manager/list infrastructure | FolderSelectDialog uses the base `List *m_controlManager`, whose virtual `GetElementAt(int)` returns a four-byte element slot. Constructor, OnControlCommand, and retained helper dereference that slot for child zero; current source support expresses it as `GetChild<PopupMenuControlPane>(0)`. It is not a dedicated `FolderSelectDialog` member field and should not be named `field_1fc` or `m_driveList`. |
| `this + 0x26c` | `FolderTreePane *m_folderTreePane` | Constructor allocates/constructs the hosted tree pane at `0x004b178b`, stores it here, and `OnControlCommand` uses it for root reset and selected-path construction. |
| `this + 0x270` | `FolderSelectCallback *m_resultCallback` | Owned `FunctionObjectT<StringBaseW>` result callback. Constructor stores it, `OnControlCommand` invokes virtual slot `+12`, and the destructor releases it through virtual slot `+0` with deleting flag `1`. |
| [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md) `0x0061a4f4-0x0061a4fc` | `kDefaultDriveRootLiteral` / `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";` | Read-only UTF-16 default drive-root literal used by constructor setup; B006 MCP session `43ccf853` confirms two constructor dword loads at `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`. |
| [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) `0x0066da88-0x0066da90` | `s_driveRootBuffer` | Mutable file-static `wchar_t[]` initialized to `X:\`, emitted at position `5`. Constructor and retained helper rewrite only the first WCHAR; StringMenuItem synchronously copies the result, so prior labels do not retain or observe later mutations. |

`m_resultCallback` is preferred over `m_selectionCallback` because both OK and cancel return a result value: OK sends the selected path and cancel sends an empty string.

## Method And Helper Inventory

| Method or helper | Address | Role | Source-quality disposition |
| --- | --- | --- | --- |
| [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md) | `0x004b1590-0x004b18d6` | Builds controls, creates `FolderTreePane`, populates drives inline, selects current drive, and optionally navigates to the initial path. B003 MCP session `2ec9c08f` reconfirmed size `0x346` / 838, `0x004b18d6` not a function, callback store at `+0x270` / 624, tree member at `+0x26c` / 620, inherited control/list infra at `+0x1fc` / 508, `FolderTreePane` allocation `0x17c` / 380, `StringMenuItem` allocation `0x118` / 280, and the MusicControlDialog caller at `0x0052986d` with dialog allocation `0x274` / 628 and callback wrapper allocation `0x18`. | Source-authored method at `94/94`; the exact accepted constructor body emits through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md). It preserves inline drive population and does not invent a call to retained helper `PopulateDriveList()`, which still has zero xrefs. |
| [UID:000458][0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding](by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md) | `0x004b18d6-0x004b1920` | Constructor EH cleanup/vtable cleanup tail plus padding. | Compiler artifact/padding; exact non-emitting child, not handwritten source. |
| [UID:000459][0x004b1920-0x004b1a00.FolderSelectDialogOnCommand](by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md) | `0x004b1920-0x004b1a00` | Handles drive-list notification, OK selected-path result, cancel empty result, and dialog close. Its drive notification uses the same inherited typed child-zero lookup as the constructor and retained helper. | Source-authored virtual `OnControlCommand` at `94/95`, vtable slot V19 at `0x0061a4a4`; exact CPP emits through UID0000JF. |
| [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md) | `0x004b1a00-0x004b1b05` | Private retained helper that obtains typed child zero, enumerates a DWORD drive mask, copies each mutable drive root into an owned StringMenuItem, and selects the just-appended current-drive row. | Source-shaped method at `93/95` with zero checked code/data/immediate/rel32/VA/RVA/vtable inbound route. Its body preserves signed-byte `_toupper`, API and allocation edge behavior, and the no-invented-caller policy. |
| [UID:00045B][0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding](by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md) | `0x004b1b05-0x004b1b20` | Secondary and tertiary `this` adjustor thunks plus five bytes of `0xcc` padding. | Compiler-generated/non-emitting artifact child. |
| [UID:00045C][0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor](by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md) | `0x004b1b20-0x004b1b87` | Deletes the owned callback before implicit DialogPane teardown; the binary also contains derived-vptr, scalar-flag, storage-free, guarded-size, return, and adjustor lowering. | Source-ready ordinary `FolderSelectDialog::~FolderSelectDialog()` definition at `94/96`, emitted through UID0000JF at position `40` as `delete m_resultCallback;`. Compiler mechanics are documented but intentionally absent from handwritten C++. |

## Class-Owned Data Inventory

| Data child | Address | Role | Source-quality disposition |
| --- | --- | --- | --- |
| [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) | `0x0061a45c-0x0061a4f4` | Exactly 38 cells across primary V01-V23, secondary COL V24/view V25-V35, and tertiary COL V36/view V37-V38. V19 targets `OnControlCommand`, V01 targets the scalar destructor wrapper, and V25/V37 target the adjustors. | Source-declared/generated-binary data; compiler bytes derive from the H declaration and the page emits only the accepted no-handwritten-vtable marker. |

B010 MCP session `supervisor_20260628_resume` reconfirmed [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) before implementation: `0x0061a45c -> 0x004b1b20`, `0x0061a4a4 -> 0x004b1920`, `0x0061a4bc -> 0x004b1b05`, `0x0061a4ec -> 0x004b1b10`, exact IDB vtable names at `0x0061a45c`, `0x0061a4bc`, and `0x0061a4ec`, constructor/cleanup/destructor vptr stores for all three views, and successor bytes `58 00 3a 00 5c 00 00 00` at `0x0061a4f4` for the `X:\` string child. This confirms the vtable range is class-declaration output, not a separate handwritten table or a method-body child.

## Behavior

Constructor behavior:

- Initializes the `DialogPane` base and three `FolderSelectDialog` vtable views.
- Stores the caller-provided callback at `this + 0x270` as an owned callback pointer.
- Builds the drive-list child control through inherited DialogPane control/list infrastructure rather than a dedicated `FolderSelectDialog` field.
- Allocates and constructs a `0x17c` byte `FolderTreePane`, positions it in the dialog, and stores it at `this + 0x26c`.
- Enumerates logical drives with `GetLogicalDrives`, reads the current drive with `GetCurrentDirectoryA` and `_toupper`, rewrites `s_driveRootBuffer[0]`, creates `StringMenuItem` entries, and selects the current drive.
- Uses the read-only `L"X:\\"` literal at [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md), emitted at file scope as `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`, and the mutable [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) buffer during drive setup. Keep these as separate data children: the literal is read-only `.rdata`, while the buffer is mutable `.data`.
- Optionally calls `FolderTreePane::SelectNodeByPath` at `0x004b2730` to navigate to the caller's initial path.
- 2026-07-03 B003 MCP refresh: session `2ec9c08f` ran against active `NexusTK.exe.i64` with `server_health ok`; `lookup_funcs` confirmed the constructor size as `0x346` / 838 and `0x004b18d6` as not a function; padding signatures preserve the half-open range; `xrefs_to` reconfirmed vtable stores to `0x0061a45c`, `0x0061a4bc`, and `0x0061a4ec`, the drive literal ref at `0x004b173a`, mutable buffer refs at `0x004b183f` / `0x004b185b`, and zero xrefs to retained helper `0x004b1a00`.

`OnControlCommand` behavior:

- OK/confirm path builds the selected path through the FolderTreePane selected-path helper at `0x004b3090`, invokes `m_resultCallback` through virtual slot `+12`, destroys the temporary string, and closes the dialog.
- Cancel path constructs an empty string through `0x00582b20`, invokes `m_resultCallback`, destroys the temporary string through `0x00582b70`, and closes the dialog.
- Drive-list notification path (`notifyCode == 10`) reads the selected drive-list item through the inherited control manager/list, copies the label with `StringMenuItem::CopyText`, and calls `FolderTreePane::SetRootNodeName` at `0x004b25e0`.
- The accepted source expression for child zero is `GetChild<PopupMenuControlPane>(0)`, backed by current DialogPane/List declarations and the exact element-slot double dereference. The former `GetControl(0)` expression was an undefined stale draft and is superseded in both OnControlCommand and PopulateDriveList.
- The command handler is reached through the vtable slot at `0x0061a4a4`; no normal code caller is expected.

Retained drive helper behavior:

- `0x004b1a00` has a normal prologue, SEH/security-cookie setup, 96 primary instructions, ten main-flow blocks plus three compiler EH blocks, a 260-byte ANSI path local, WinAPI calls, control-list calls, allocation, and a real loop over `0x20` drive bits. Exact byte SHA256 is `655962B7DBE4BDA3163366C27DE0A7719309CA5A9072FFE50A2BCE760272C1BF`.
- Exact order is inherited typed child lookup, `GetLogicalDrives`, ignored-return `GetCurrentDirectoryA`, signed-byte `_toupper`, then 32 DWORD bit tests. `1u` preserves defined bit-31 source behavior; no guard repairs a zero drive mask, failed/uninitialized path, empty path, UNC prefix, null control, or null allocation.
- Each set bit rewrites only `s_driveRootBuffer[0]`, allocates `0x118` bytes, constructs a StringMenuItem that copies inline text, appends ownership, and, when the drive index matches, selects `GetItemCount() - 1`. EH cleanup frees storage if construction throws; it is compiler lowering, not handwritten source.
- The constructor span `0x004b17e0-0x004b188f` repeats the same order, constants, data, allocation, construction, append/count/select calls, and loop limit. Manual retained duplication/refactor ranks above automatic inlining because the helper is large and EH-bearing; automatic inlining remains possible, different-build retention is unsupported, and no source call may be synthesized.
- MCP plus raw code/data/immediate/rel32/VA/RVA/vtable scans found zero inbound route to `0x004b1a00`. Treat this as a source-shaped retained/no-entry helper, not padding, a thunk, compiler-only code, a free/static helper, or a proven constructor call.

Destructor behavior:

- Source-facing destructor is explicit, non-empty `FolderSelectDialog::~FolderSelectDialog()`; UID00045C defines it as deletion of owned `m_resultCallback` before automatic base teardown.
- Binary forms include two adjustor thunks and a scalar deleting destructor.
- The callback is stored by the constructor, invoked with selected or empty `StringBaseW` results by OnControlCommand, and deleted by the destructor. This complete lifecycle rules out a borrowed pointer and rules out defaulted/implicit/empty destruction for the raw member.
- The scalar deleting form restores all three vtable views, lowers callback deletion to a null-safe virtual slot-zero call, invokes DialogPane/base cleanup, tests scalar bits `0x01`/`0x04`, and chooses normal storage free or guarded-size no-op support. Those mechanics, plus return ABI and adjustor routes, are compiler output.
- Generated/decompiler labels that call this `boost::exception` or `TransferReplyAlert` cleanup are owner pollution and must not be used in final source.

## Heuristic / Inference Reanalysis And Validation

### Owner And Source Placement

Best-supported inference: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) is the direct file owner and emitter, with generated output under `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp`.

Evidence checked:

- [UID:000059] already routed to owner/emitter `0000JF` and is reconstructable.
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) owns the dialog source module and lists the vtable data, drive-root literal, mutable drive-root buffer, method island, and class as direct contents.
- Constructor xref at `0x0052986d` is inside MusicControlDialog command handling, which proves caller/consumer relationship only.
- `FolderTreePane` begins at `0x004b1b90`, has separate class/file docs, separate vtables, template/storage helpers, and a proposed `NexusTK/ui/controls/FolderTreePane.cpp` source home.

Rejected alternatives:

- MusicControlDialog ownership is rejected because it only supplies a concrete callback binding.
- FolderTreePane ownership is rejected because the dialog hosts the tree control but does not own its tree-control source.
- A monolithic `FolderSelectDialogAndTree.cpp` is rejected because the object model and current by-file split support a dialog/control boundary.

### Constructor Signature And Callback Type

Best source-facing constructor:

```cpp
FolderSelectDialog::FolderSelectDialog(FolderSelectCallback *resultCallback,
                                       const wchar_t *initialPath);
```

`FolderSelectCallback` is the accepted local alias for the existing shared FunctionObjects contract. The class-level H uses:

```cpp
typedef FunctionObjectT<StringBaseW> FolderSelectCallback;
```

`StringBaseW` is `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`. Current FunctionObjects declarations and the concrete MusicControlDialog member-function wrapper independently support the one-value callback contract.

Evidence:

- Constructor stores its callback argument at `this+0x270`.
- OK/cancel paths invoke virtual slot `+12` on that pointer.
- Destructor invokes virtual slot `+0` with deleting flag `1`, proving owned lifetime.
- MusicControlDialog case `7` constructs the exact 24-byte three-parameter `PlainMemberFunctionObjectT<FolderPathCallback, MusicControlDialog, StringBaseW>` wrapper targeting `MusicControlDialog::FolderPathSelected`.

Rejected names:

- `MusicControlDialogCallback *` is too narrow: MusicControlDialog is one concrete caller, while the dialog only requires a string-result callback interface.
- A proven binary `FolderSelectDialog::Show` method is not supported by this class evidence. If a MusicControl source draft uses `Show`, document it as source-level convenience shorthand over allocation plus constructor, not as a recovered method.

### Field Names And Inherited State

Best-supported names:

- `this+0x26c`: `m_folderTreePane`.
- `this+0x270`: `m_resultCallback`.
- `DialogPane+0x1fc`: inherited control manager/list infrastructure.

Rejected/generated placeholders:

- `field_1fc` as a FolderSelectDialog member: rejected because the DialogPane layout documentation and local access patterns show inherited control-management state.
- `mbr_26c` / `field_26C`: replace with `m_folderTreePane`.
- `mbr_270` / `field_270`: replace with `m_resultCallback`.
- `asc_66DA88`: replace with the sole accepted source-facing name `s_driveRootBuffer`. The earlier `s_driveRootName` alternative is superseded because the formal declaration and current file/class/memory documentation converge on `s_driveRootBuffer`.

### Drive-List Helper Liveness

Best-supported name: `FolderSelectDialog::PopulateDriveList()`.

Historical alternatives `RefreshDriveList()` and `BuildDriveList()` are weaker: the method appends without clearing or refreshing existing state. `PopulateDriveList()` remains the best current descriptive name; exact original spelling/access are symbol-level confidence caps.

Validated facts:

- Real function body at `0x004b1a00-0x004b1b05`.
- Uses `GetLogicalDrives`, `GetCurrentDirectoryA`, `_toupper`, `StringMenuItem` construction, the inherited drive-list control, `s_driveRootBuffer`, and selection helpers.
- Zero checked rel32 inbound references and zero checked absolute pointer references.
- Not a vtable slot.
- Not padding, not dead alignment, and not a compiler thunk.

Final disposition: keep with FolderSelectDialog as a private retained/no-entry helper declaration. The exact aggregate is now split, and [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md) carries the accepted retained-helper body while preserving the no-invented-caller policy.

### Drive-Root Data Ownership

Accepted names and ownership:

- [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md) is the read-only source literal `L"X:\\"`, emitted through the file page as `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`.
- [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) is the mutable file-static `s_driveRootBuffer`, `94/96`, position `5`, with exact eight bytes and only four constructor/helper write/use refs.

Evidence:

- [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md) bytes decode as UTF-16 `X:\`. B006 MCP session `43ccf853` reconfirmed health `ok`, not-a-function status, and two constructor dword reads at `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`; the duplicate byte pattern at `0x0066da88` belongs to the separate mutable buffer.
- [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) has the same initial bytes in `.data` and has constructor write/use xrefs plus helper write/use xrefs.
- Both data items are dialog-specific drive-list setup state, not FolderTreePane state and not MusicControlDialog state.

### Destructor, Thunks, And Generated Labels

Source-facing destructor: `FolderSelectDialog::~FolderSelectDialog()`.

Compiler-generated binary artifacts:

- `0x004b1b05`: adjustor thunk subtracting `0xa0`.
- `0x004b1b10`: adjustor thunk subtracting `0xa4`.
- `0x004b1b20`: scalar deleting destructor.

Rejected generated pollution:

- `boost::exception::~exception`.
- `TransferReplyAlert::~DialogPane` or `TransferReplyAlert` ownership.
- Any `ChattingColorPane` label in this dialog's source path.

### Remaining Source-Quality Limits

Closed for this class page:

- Owner/emitter/source placement.
- FolderTreePane split.
- MusicControl caller/callback role.
- `+0x1fc` inherited-control interpretation.
- `m_folderTreePane` and `m_resultCallback` field names.
- Drive-root literal/buffer ownership.
- Retained/no-entry classification for `0x004b1a00`.
- Destructor/thunk pollution.

Closed by the accepted whole-file pass:

- The callback spelling is `FunctionObjectT<StringBaseW>` through the local `FolderSelectCallback` alias.
- The drive-list source uses `PopupMenuControlPane`, `GetChild`, `GetItemCount`, `GetSelectedIndex`, and `StringMenuItem` declarations already present in support headers.
- The constructor, `OnControlCommand`, `PopulateDriveList`, and ordinary destructor have complete accepted child bodies. UID000458/UID00045B and scalar-wrapper portions of UID00045C remain compiler-only.

## First-Draft C++ Rationale

[UID:000059] is eligible for class-level first-draft C++ because it is reconstructable, has owner/emitter [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), and has a combined score above the current code-entry gate. The class page is the correct level for source declarations, member names, and child insertion.

The CPP channel now emits the include/root and `[[CHILDREN]]`; the H channel emits the guarded class declaration. Source-authored child output is routed directly through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) at file scope: UID0003BG emits the const literal at `2`, UID00027D emits the mutable buffer at `5`, UID000457 emits the constructor at `10`, UID000459 emits `OnControlCommand` at `20`, UID00045A emits retained `PopulateDriveList` at `30`, and UID00045C emits the destructor at `40`. Compiler artifacts UID000458/UID00045B remain non-emitting; UID0003PA/UID0003BF contribute only compiler-evidence markers.

The source-ready alias is `typedef FunctionObjectT<StringBaseW> FolderSelectCallback;`. It matches the owned callback lifecycle and the MusicControlDialog concrete binding without introducing a feature-specific callback base.

## Score Rationale

| Field | Rationale |
| --- | --- |
| Completion `95` | Complete CPP/H routing, constructor/command/helper/destructor source, 0x274 layout, callback contract, 38-cell vtable, 20-record reachable RTTI graph, and compiler-only exclusions are all documented and routed. |
| Confidence `96` | Raw IDA evidence, support declarations, xrefs, caller binding, frame/type proof, vtable slots, RTTI records, data refs, and destructor lowering agree. Residual uncertainty is limited to unrecoverable original identifier/include ordering. |

## Cross-References

- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
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
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0000AL][PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6](by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)

## 2026-08-23 Accepted Whole-Class Closure

- Physical class size is 0x274/628 bytes. DialogPane/base storage occupies the leading span; m_folderTreePane is the four-byte pointer at +0x26c and owned FolderSelectCallback *m_resultCallback is at +0x270.
- The source inheritance is FolderSelectDialog : DialogPane. Reachable RTTI proves the DialogPane, Pane, GrafPort, LObject, EventHandler at +0xa0, and TimerHandler at +0xa4 base views. Shared base BCD/TypeDescriptor records remain owned by those classes.
- Constructor signature is FolderSelectDialog(FolderSelectCallback *resultCallback, const wchar_t *initialPath). The callback is owned; OnControlCommand invokes it with selected/empty StringBaseW values and the ordinary destructor deletes it.
- Source order is class include/root, const literal position 2, mutable buffer position 5, constructor 10, OnControlCommand 20, retained no-entry PopulateDriveList 30, and ordinary destructor 40. Cleanup, adjustors, scalar-wrapper ABI, RTTI/vtable bytes, and padding are compiler-generated.

### Complete Vtable Consequences

All cells are distinct four-byte data items. V01/V19/V25/V37 derive from this class's virtual declarations/bodies; inherited slots retain their external source owners. No handwritten vtable array is emitted.

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

### Complete Reachable RTTI Consequences

R01-R07/R20 are FolderSelectDialog compiler records or alignment; R08-R19 are exact shared base dependencies. Each shared BCD CHD pointer is the ownership boundary to the external class graph.

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


## Historical Assumptions And Corrections

- Older text treated `this+0x1fc` as a drive-list member pointer. This is superseded: the accepted interpretation is inherited DialogPane control-manager/list infrastructure.
- Older text left the `0x004b1a00` helper as a generic reachability caveat. This is superseded: it is source-shaped `PopulateDriveList()` with no checked inbound route, so keep it as retained/no-entry and do not invent a caller.
- Older generated source labels used `TransferReplyAlert`, `boost::exception`, `ChattingColorPane`, `mbr_26c`, `mbr_270`, and `asc_66DA88`. These are retained only as search/provenance aliases and are rejected final source names.
- Older source-split wording left FolderTreePane co-location as plausible. The accepted split keeps `FolderTreePane` separate under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) / `NexusTK/ui/controls/FolderTreePane.cpp`.

## Changes

- 2026-07-14 B005 accepted UID00045C implementation callback:
  - Preserved class `88/90`, owner/emitter UID0000JF, alias, declaration, fields, methods, `[[CHILDREN]]`, and the complete formal block byte-for-byte.
  - Synchronized the destructor inventory, owned callback lifecycle, source/compiler separation, and file-scope rationale: UID00045C now supplies `FolderSelectDialog::~FolderSelectDialog()` as `delete m_resultCallback;` before implicit DialogPane teardown.
  - Historicalized the earlier scalar-wrapper marker-only disposition as superseded while retaining all compiler-mechanics exclusions, polluted-name rejection, and callback typedef confidence limits.
- 2026-07-14 B005 accepted UID00045A support synchronization:
  - Preserved class `88/90`, owner/emitter UID0000JF, and the complete formal class block.
  - Synchronized target `92/94`, buffer `90/94` at position `5`, inherited typed child-zero lowering, exact hash/CFG/behavior/API/signedness/allocation/data evidence, exhaustive no-entry negatives, constructor duplicate ranking, source-name alternatives, and file-scope emitter order. No class field, declaration, route, or unrelated score was changed.

- 2026-07-07 B006 [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md) support sync:
  - What existed before: the class page identified UID0003BG as `L"X:\\"` / `kDefaultDriveRootLiteral`, but did not record that the exact child now emits a file-scope declaration or that B006 MCP found the second constructor dword load.
  - Changed to: documented UID0003BG as the file-scope declaration `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";` emitted through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), kept this class formal block declaration-only, and preserved the separate mutable-buffer child.
  - Summary/evidence: B006 MCP session `43ccf853` returned `server_health ok`, bytes `58 00 3a 00 5c 00 00 00`, not-a-function status, constructor reads `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`, duplicate byte pattern only at [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md), and `0x0061a4fc -> 0x0064791c` successor boundary.
- 2026-07-03 B003 accepted implementation callback:
  - What existed before: the constructor method inventory still carried the older `84/90` disposition and older evidence wording.
  - Changed to: constructor child [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md) is documented at `86/91` with current MCP session `2ec9c08f` evidence; class metadata remains `88/90` and class-level C++ remains declaration-only.
  - Summary/evidence: B003 reconfirmed active `NexusTK.exe.i64`, `server_health ok`, function size `0x346` / 838, half-open boundary at non-function `0x004b18d6`, vtable stores, `m_resultCallback`, `m_folderTreePane`, inherited control/list offset, FolderTreePane allocation, inline drive-loop behavior, MusicControlDialog caller/callback-provider route, and zero xrefs to retained `PopulateDriveList()`.
- 2026-06-28 B010 accepted empty-emitter repair:
  - What existed before: [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) was listed as exact vtable data but generated output still treated it as an empty emitter because the child formal block was blank.
  - Changed to: documented [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) as class-owned source-declared/generated-binary data with a one-line covered-by marker emitted through this class declaration; method-body routing remains unchanged and stays on exact children/file scope.
  - Summary/evidence: B010 MCP session `supervisor_20260628_resume` reconfirmed the three vtable bases, `0x0061a4a4 -> 0x004b1920`, `0x0061a45c -> 0x004b1b20`, `0x0061a4bc -> 0x004b1b05`, `0x0061a4ec -> 0x004b1b10`, constructor/cleanup/destructor vptr stores, and the `0x0061a4f4` `X:\` successor boundary.
- 2026-06-26 B013 accepted report implementation:
  - What existed before: the class page correctly emitted declaration-only C++ with `[[CHILDREN]]`, but still described all exact child formal C++ blocks as blank/deferred under the earlier split-stage callback.
  - Changed to: kept class-level declarations only, documented file-scope child routing through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), and synchronized the method inventory with the accepted constructor marker, `OnCommand` body, retained `PopulateDriveList` body/no-entry policy, scalar-deleting-destructor marker, and non-emitting cleanup/thunk children.
  - Summary/evidence: class fields and declarations remain `FolderSelectCallback`, `m_folderTreePane`, `m_resultCallback`, private `PopulateDriveList`, and `[[CHILDREN]]`; method bodies are not inserted into the class page.
- 2026-06-26 B001 accepted split implementation callback:
  - What existed before: method inventory listed raw address subranges and still described method-body C++ as waiting for the aggregate split.
  - Changed to: added exact child UID links [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md), [UID:000458][0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding](by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md), [UID:000459][0x004b1920-0x004b1a00.FolderSelectDialogOnCommand](by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md), [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md), [UID:00045B][0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding](by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md), and [UID:00045C][0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor](by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md); kept class-level declarations only with `[[CHILDREN]]`.
  - Summary/evidence: the child split was implemented. The old blank-child policy is superseded by the B013 child dispositions above.
- 2026-06-19 B014 accepted implementation callback:
  - What existed before: `COMPLETION:85`, `CONFIDENCE:86`; the page still treated `+0x1fc` as a drive-list field, left helper/source names and callback type as blockers, did not reject all generated pollution labels, had blank C++, and left FolderTreePane split language less final.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged as [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), added class-level first-draft C++ only, and incorporated the accepted B014 source-quality report.
  - Summary/evidence: raw PE/IDA evidence confirms constructor `0x004b1590-0x004b18d6`, cleanup/padding through `0x004b1920`, `OnCommand` `0x004b1920-0x004b1a00`, retained/no-entry helper `0x004b1a00-0x004b1b05`, adjustor thunks `0x004b1b05`/`0x004b1b10`, scalar deleting destructor `0x004b1b20-0x004b1b87`, constructor caller `0x0052986d`, command vtable slot `0x0061a4a4`, drive-root data refs, `m_folderTreePane` at `+0x26c`, owned `m_resultCallback` at `+0x270`, and inherited control-manager/list use at `DialogPane+0x1fc`.
- 2026-06-11 A003 Batch 213 parent-gate repair:
  - What existed before: `COMPLETION:78`, `CONFIDENCE:84`; the class page summarized executable behavior but did not own an exact vtable-data child, and the file parent was below the strict 85/85 gate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`, added exact vtable/string children and synchronized the file parent to `85/86`.
  - Summary/evidence: live IDA confirmed vtable bases `0x0061a45c`, `0x0061a4bc`, `0x0061a4ec`, their constructor/cleanup/destructor stores, the `0x0061a4f4` UTF-16 `X:\` constructor xref, and the `0x0061a4fc` handoff to FolderTreePane tree RTTI.
- 2026-06-07 A005 evidence consolidation:
  - What existed before: `COMPLETION:74`, `CONFIDENCE:82`, with exact function evidence present but the class page did not summarize drive-list state, callback ownership, `asc_66DA88` cleanup, or score rationale in one place.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:84`, added touched-state/dependency and score-rationale sections, replaced the generated recovered-file wording with a provenance caveat, and documented `asc_66DA88` as the drive-root buffer.
- Completion/confidence score update: existed before as `0/0`; changed to `68/78`. Summary: dialog responsibility, control composition, method/helper ranges, and key field offsets were documented; exact field names and some base-destructor naming remained medium-confidence.
- 2026-06-03 MCP verification and parent attachment:
  - What existed before: the class remained unassigned at `68/78`; it documented the dialog role and key offsets but did not carry the later vtable, drive-buffer, callback, and thunk verification directly on the class page.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md).
  - Summary/evidence: live IDA MCP lookup/caller/callee/xref/decompile/disassembly checks reconfirmed function boundaries, the MusicControlDialog constructor caller, selected-path callback flow, drive-list helper behavior, vtable xrefs, drive-root buffer xrefs, and destructor/adjustor thunk shape.
