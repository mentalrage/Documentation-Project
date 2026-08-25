** TARGET-REPORT-UID:000154 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000154 FolderSelectDialog Memory-Island Source-Quality / Split Research

Agent: B013
Assignment id: B013-rework-000154-folder-select-dialog-20260626
Mode: report rework only
Date: 2026-06-26

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:000154] `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md` into exact constructor, command-handler, retained-helper, cleanup/thunk, and destructor children, then apply the child-level formal C++/marker/no-code dispositions in the rework section below.
- Final disposition: [UID:000154] is not a cohesive source item for formal C++. It is a contiguous compiler output island for one class: source-authored methods, source-declared/generated-binary cleanup, vtable adjustor thunks, padding, and a scalar deleting destructor.
- Required action: supervisor should validate this report, then send an implementation callback to create or update exact child pages and convert the parent into a non-emitting split/container page. If the supervisor defers child creation, keep the current aggregate metadata and C++ blank, but add the fresh MCP evidence and split plan.
- Confidence: high for owner/source placement, exact boundaries, retained-helper policy, and child C++ disposition. The constructor remains a deliberate child-level no-code marker because its exact UI-control construction APIs are not source-safe enough for a body.

## Supporting Research

## Target

- Target UID: `000154`
- Target path: `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`
- Source queue/report row at assignment time: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, row `76/84`, combined `80.0`, reconstructable `true`, reports `0`.
- Current supervisor classification: report-only B-agent source-quality and split research; no by-* edits allowed before supervisor acceptance.
- Current source-page scores and parent state: target file currently says `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000059`, blank formal C++. The generated tracker and auto coverage are stale relative to the source page and still show the older `76/84` row.

## Current Target State

- Existing metadata: `88/91`, owner [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md), reconstructable true, emitter [UID:000059], `Nested:0`, blank formal C++.
- Existing owner/emitter/reconstructable state: correct for the current unsplit aggregate as a FolderSelectDialog source island, but not sufficient for method-body emission.
- Existing C++/emitter state: blank by design. The target already says aggregate method-body C++ would conflate constructor source, EH cleanup/padding, command handler, retained helper, adjustor thunks, and scalar deleting destructor lowering.
- Existing open questions/blockers: exact child split is pending. The `0x004b1a00` helper is now resolved as retained/no-entry; FunctionObjects callback spelling and drive-list control/helper names are bounded below as inferred source names rather than blockers for the split.
- Related target/support docs checked: `by-class/FolderSelectDialog.md`, `by-file/FolderSelectDialog.md`, `by-class/FolderTreePane.md`, `by-file/FunctionObjects.md`, `by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md`, `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`, `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`, `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md`, executed B014 `000059-FolderSelectDialog-class-source-quality.md`, executed B008 `00005A-FolderTreePane-class-source-quality.md`, `by-structure.md`, `by-project-structure/proposed-source-tree.md`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md`.

## Executive Recommendation

Best direct owner remains [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md), emitted through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md). MusicControlDialog is the caller/concrete callback construction site, FolderTreePane is the hosted reusable tree control, and FunctionObjects owns the shared callback-template family.

The target should be split. The preferred implementation callback should create or update these exact children. The source-authored method children should emit at file scope through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), not through the in-class `[[CHILDREN]]` marker, so their formal blocks do not become nested method definitions inside `class FolderSelectDialog`.

| Proposed child | Range | Source disposition | Recommended initial metadata |
| --- | --- | --- | --- |
| `FolderSelectDialogConstructor` | `0x004b1590-0x004b18d6` | source-authored constructor with exact no-code marker until support APIs are source-safe | owner `000059`, reconstructable true, emitter `0000JF`, position `10`, `84/90`, formal marker comment |
| `FolderSelectDialogConstructorCleanupAndPadding` | `0x004b18d6-0x004b1920` | constructor EH/vtable cleanup plus padding, compiler artifact | owner `NONE`, reconstructable false, no emitter, `84/88`, no-code proof |
| `FolderSelectDialogOnCommand` | `0x004b1920-0x004b1a00` | source-authored virtual command handler | owner `000059`, reconstructable true, emitter `0000JF`, position `20`, `87/91`, first-draft body below |
| `FolderSelectDialogPopulateDriveList` | `0x004b1a00-0x004b1b05` | source-shaped retained/no-entry private helper | owner `000059`, reconstructable true, emitter `0000JF`, position `30`, `86/90`, first-draft body plus no-entry proof |
| `FolderSelectDialogAdjustorThunksAndPadding` | `0x004b1b05-0x004b1b20` | compiler-generated secondary/tertiary adjustor thunks plus `CC` padding | owner `NONE`, reconstructable false, no emitter, `88/92`, no-code proof |
| `FolderSelectDialogScalarDeletingDestructor` | `0x004b1b20-0x004b1b87` | source-declared/generated-binary destructor support | owner `000059`, reconstructable true, emitter `0000JF`, position `40`, `86/90`, formal marker comment |

After those exact children exist, [UID:000154] should become a non-emitting split/container page: keep [UID:000059] as the semantic owner for the island, set `EMITTER_UIDS:` and formal C++ blank, and use `RECONSTRUCTABLE:FALSE` because the parent would then be an audit/container rather than a source-level object. If the supervisor wants a two-stage implementation, the minimum first-stage update is to keep the current `RECONSTRUCTABLE:TRUE` aggregate state at `88/91`, add the fresh B013 MCP evidence, keep the aggregate C++ blank, and apply the child dispositions in the split callback.

## Supervisor Active Recheck

- Active instruction: user assigned Agent-B013 to produce a report-only research report for [UID:000154], use IDA MCP as mandatory evidence, not spawn subagents, and not edit target/support by-* docs or generated/state/coverage files before supervisor acceptance.
- Split requirement: yes. The target contains multiple function bodies and generated artifacts under one by-memory page. The report-only pass cannot perform the split, so this report supplies the exact implementation-ready plan.
- Source-bearing child coverage: each source-bearing subrange is identified above. The only no-entry child is `0x004b1a00-0x004b1b05`; it has been actively checked through MCP xrefs, byte search, and source-shape analysis rather than deferred.

## Inference Research Guidance Check

The `by-structure.md` owner/emitter split and the B-agent inference rules drove the recommendation:

- IDA MCP facts are separated from documentation evidence and inference.
- Address adjacency alone was not used as ownership proof. Owner conclusions use constructor/caller routes, vtable/data refs, class/file docs, proposed source tree, and rejected alternatives.
- Decompiler labels such as `boost::exception`, `asc_66DA88`, `sub_4B1A00`, and generated class pollution are treated as search labels only.
- The generated tracker and auto coverage rows were treated as stale inputs because the current source target and support docs have newer scores and B014 incorporation.
- No current Wave2/Wave3 source material was accepted as authority. `simroot_v2` and generated labels were used only as provenance/pollution context.

## Heuristic / Inference Reanalysis And Validation

### Cohesion And Split

The range is cohesive as a compiler output island for `FolderSelectDialog`, but not as one source item. MCP `entity_query` over `0x004b1580-0x004b1ba0` lists seven function starts in and around the island: `0x004b1590`, `0x004b1920`, `0x004b1a00`, `0x004b1b05`, `0x004b1b10`, `0x004b1b20`, and successor `0x004b1b90`. `get_bytes` shows `CC` padding before the constructor, cleanup/padding at `0x004b18d6-0x004b1920`, five `CC` bytes at `0x004b1b1b-0x004b1b20`, and nine `CC` bytes after the destructor before `FolderTreePane::FolderTreePane`.

Accepted inference: split the source methods and generated artifacts. Do not emit method-body C++ from the aggregate.

### Owner And Source Placement

Accepted owner remains [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), `NexusTK/ui/dialogs/FolderSelectDialog.cpp`.

Rejected alternatives:

- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md): only caller/concrete callback binding. MCP xref to constructor is `0x0052986d` inside `sub_529790`; that proves reachability, not ownership.
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md): hosted control constructed at `0x004b178b` and used by `OnCommand`, but its control implementation starts at `0x004b1b90` and is separately documented under `ui/controls/FolderTreePane.cpp`.
- FunctionObjects: owns the reusable callback family, not the dialog or its method island.
- A combined `FolderSelectDialog`/`FolderTreePane` file: rejected by current by-file docs, proposed-source-tree entries, vtable/data split, and B008/B014 accepted source-quality reports.

### Field, Global, And Helper Names

Accepted source-facing names remain:

- `this+0x26c`: `m_folderTreePane`.
- `this+0x270`: `m_resultCallback`.
- `DialogPane+0x1fc`: inherited control-manager/list infrastructure, not a direct `FolderSelectDialog` field.
- `0x0061a4f4`: source literal `L"X:\\"` or `kDefaultDriveRootLiteral`.
- `0x0066da88`: `s_driveRootBuffer` preferred over `s_driveRootName` because constructor/helper mutate the first WCHAR.
- `0x004b1a00`: `PopulateDriveList()` as retained/no-entry private helper.

Rejected placeholders: `sub_4B1A00`, `FUN_004b1a00`, `asc_66DA88`, `mbr_26c`, `mbr_270`, `field_1fc`, `ChattingColorPane`, `TransferReplyAlert`, and `boost::exception` as final source names.

### Retained Helper Liveness

The `0x004b1a00-0x004b1b05` helper is source-shaped and FolderSelectDialog-local, but still no-entry in the checked binary:

- MCP `lookup_funcs` returns `sub_4B1A00`, size `0x105`.
- MCP `decompile` shows `GetLogicalDrives`, `GetCurrentDirectoryA(0x104)`, `_toupper`, a 32-slot drive loop, writes to `asc_66DA88[0]`, `StringMenuItem` construction through `0x00516ff0`, list append/select helpers, and current-drive selection.
- MCP `xref_query` reports no code or data xrefs to `0x004b1a00`.
- MCP `find_bytes` for little-endian absolute pointer `00 1A 4B 00` returns zero matches.
- It is not one of the `FolderSelectDialog` vtable slots: vtable data points at `0x004b1b20`, `0x004b1920`, `0x004b1b05`, and `0x004b1b10`.

Accepted inference: keep it as a retained private helper under FolderSelectDialog, document no inbound route, and do not invent a constructor call. If emitted later, the exact child must carry the no-entry proof and the source/linker retention policy.

### Callback Type And Source Shape

The semantic callback role is closed enough for ownership but not for final template spelling:

- Constructor stores the callback argument at `this+0x270`.
- `OnCommand` invokes vtable slot `+12` for OK and cancel results.
- Destructor reads `this+0x270` and invokes virtual slot `+0` with deleting flag `1`.
- MusicControlDialog constructs a concrete `PlainMemberFunctionObjectT<MusicControlDialog, String>` wrapper; FunctionObjects owns the reusable template family.

Accepted source-facing role: `FolderSelectCallback *m_resultCallback`. The exact original alias/template spelling is unproven, but the local alias is bounded through FunctionObjects and is sufficient for the child-level first drafts below.

## 2026-06-26 Rework Reanalysis - Exact Child Specs And C++ Disposition

This section supersedes the earlier child table and the old blank-C++ policy. It preserves the original evidence above, but closes the rejected items with exact page metadata, exact item summaries, formal C++ insertion text or no-code proof, retained-helper policy, and a callback-ready checklist. Current read-only worktree context already contains candidate child pages [UID:000457] through [UID:00045C]; an implementation callback should update those pages rather than create duplicates if the supervisor keeps those UIDs.

### Final Parent Container Spec

- UID/path/range: [UID:000154] `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`, range `0x004b1590-0x004b1b87`.
- Metadata after split: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position, `Nested:6`.
- Exact `Item Summary`: `Non-emitting FolderSelectDialog split container; six exact children cover the constructor, cleanup/padding, OnCommand, retained drive helper, adjustor thunks/padding, and scalar deleting destructor.`
- Children, in address order: [UID:000457] constructor, [UID:000458] cleanup/padding, [UID:000459] OnCommand, [UID:00045A] retained drive helper, [UID:00045B] adjustor thunks/padding, [UID:00045C] scalar deleting destructor.
- Formal C++ insertion text: empty block.
- No-code proof: [UID:000154] is an address-order audit/container after split. The aggregate crosses one source-authored constructor, constructor cleanup/padding, one virtual command handler, a retained helper with no inbound route, two compiler adjustor thunks plus padding, and scalar deleting destructor lowering. Emitting any body from the parent would cross source-item boundaries and duplicate child-owned code.

### Child Page Specs

#### [UID:000457] FolderSelectDialogConstructor

- Filename/range: `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`, range `0x004b1590-0x004b18d6`.
- Metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, optional emitter position `10`, `Nested:0`.
- Exact `Item Summary`: `Source-authored FolderSelectDialog constructor body; exact child range initializes the dialog, stores the callback, builds drive and folder controls, enumerates drives, and optionally selects the initial path.`
- Formal C++ insertion text:

```cpp
// No first-draft constructor body for 0x004b1590-0x004b18d6:
// the range is source-authored, but exact DialogPane/control construction
// and layout helper APIs are not source-safe enough to emit without inventing
// source declarations. Do not substitute sub_ labels or add a synthetic
// call to PopulateDriveList(); the constructor contains its own drive loop.
```

- No-code proof: constructor decompilation is source-authored but depends on unresolved control-construction/layout APIs at `0x004b15e4-0x004b1735` and `0x004b17aa-0x004b17e9`. Known roles are strong: callback stored at `this+0x270`, tree pane stored at `this+0x26c`, inherited control id `0` is the drive list, and the constructor duplicates the drive enumeration loop. The exact source-safe body is not recoverable yet without inventing `DialogPane` and control constructor overload names, so the child must use the nonblank marker above rather than a generic blank formal block.

#### [UID:000458] FolderSelectDialogConstructorCleanupAndPadding

- Filename/range: `by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md`, range `0x004b18d6-0x004b1920`.
- Metadata: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position, `Nested:0`.
- Exact `Item Summary`: `Constructor cleanup/tail and padding after FolderSelectDialog constructor; non-source compiler artifact with vtable restoration, not a reconstructable method.`
- Formal C++ insertion text: empty block.
- No-code proof: MCP disassembly shows constructor cleanup/tail code plus alignment, not a standalone source function. It restores FolderSelectDialog vtable views, releases the callback through `[this+0x270]` when needed, tail-jumps to the polluted base-destructor label, and ends in padding before `0x004b1920`. It should be documented as generated cleanup/padding with no owner/emitter, not as constructor C++.

#### [UID:000459] FolderSelectDialogOnCommand

- Filename/range: `by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md`, range `0x004b1920-0x004b1a00`.
- Metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, optional emitter position `20`, `Nested:0`.
- Exact `Item Summary`: `Source-authored FolderSelectDialog virtual command handler; vtable-routed OK/cancel/drive-list notification behavior with callback dispatch and tree-root reset.`
- Formal C++ insertion text:

```cpp
void FolderSelectDialog::OnCommand(int commandId, int notifyCode)
{
    if (commandId == 1) {
        if (m_resultCallback != 0) {
            SimpleUString selectedPath;
            m_folderTreePane->BuildSelectedPath(selectedPath);
            m_resultCallback->Invoke(selectedPath);
        }
        Close();
        return;
    }

    if (commandId == 2) {
        if (m_resultCallback != 0) {
            SimpleUString emptyPath;
            m_resultCallback->Invoke(emptyPath);
        }
        Close();
        return;
    }

    if (commandId == 0 && notifyCode == 10) {
        PopupMenuControlPane *driveList =
            static_cast<PopupMenuControlPane *>(GetControl(0));
        const int selectedIndex = driveList->GetSelectedIndex();
        StringMenuItem *item =
            static_cast<StringMenuItem *>(driveList->GetItem(selectedIndex));
        wchar_t selectedRoot[100];
        item->CopyText(selectedRoot, 100);
        m_folderTreePane->SetRootNodeName(selectedRoot);
    }
}
```

- Name bounds: `BuildSelectedPath`, `Close`, `GetControl`, `GetSelectedIndex`, `GetItem`, `CopyText`, and `SetRootNodeName` are inferred source-facing names backed by current support docs and MCP behavior. They are preferable to raw `sub_` labels; exact original spelling is not symbol-proven.

#### [UID:00045A] FolderSelectDialogPopulateDriveList

- Filename/range: `by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md`, range `0x004b1a00-0x004b1b05`.
- Metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, optional emitter position `30`, `Nested:0`.
- Exact `Item Summary`: `Retained source-shaped FolderSelectDialog drive-list population helper; exact no-entry proof blocks inventing a caller while preserving implementation-ready drive enumeration behavior.`
- Retained/no-entry policy: keep this child reconstructable and emitting as a private helper, but do not invent a constructor call. The constructor contains its own drive loop; MCP `xref_query` total `0`, absolute pointer byte search total `0`, and vtable/data checks show no inbound route. The helper is source-shaped retained code, probably kept by source/build/link behavior outside the current xref graph.
- Formal C++ insertion text:

```cpp
void FolderSelectDialog::PopulateDriveList()
{
    PopupMenuControlPane *driveList =
        static_cast<PopupMenuControlPane *>(GetControl(0));
    const DWORD driveMask = GetLogicalDrives();

    char currentDirectory[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, currentDirectory);
    const int currentDrive =
        toupper(static_cast<unsigned char>(currentDirectory[0])) - 'A';

    for (int drive = 0; drive < 32; ++drive) {
        if ((driveMask & (1u << drive)) == 0) {
            continue;
        }

        s_driveRootBuffer[0] = static_cast<wchar_t>(L'A' + drive);
        driveList->AppendItem(new StringMenuItem(s_driveRootBuffer));

        if (drive == currentDrive) {
            driveList->SetSelectedIndex(driveList->GetItemCount() - 1);
        }
    }
}
```

- Return-type decision: use source-facing `void PopulateDriveList()` to match the current class declaration and helper role. The decompiler leaves `LogicalDrives` in `EAX`, but no caller consumes a return value and no inbound route exists. A `DWORD` source signature would overstate evidence.

#### [UID:00045B] FolderSelectDialogAdjustorThunksAndPadding

- Filename/range: `by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md`, range `0x004b1b05-0x004b1b20`.
- Metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position, `Nested:0`.
- Exact `Item Summary`: `Compiler-generated FolderSelectDialog destructor adjustor thunks and padding; non-source vtable support for secondary-base destruction routes.`
- Formal C++ insertion text: empty block.
- No-code proof: MCP disassembly shows two adjustor thunks only: `sub ecx, 0xa0; jmp 0x004b1b20` and `sub ecx, 0xa4; jmp 0x004b1b20`, followed by `CC` padding. Xrefs are vtable-only. This is generated ABI support, not source C++.

#### [UID:00045C] FolderSelectDialogScalarDeletingDestructor

- Filename/range: `by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md`, range `0x004b1b20-0x004b1b87`.
- Metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, optional emitter position `40`, `Nested:0`.
- Exact `Item Summary`: `FolderSelectDialog scalar deleting destructor lowering for the source destructor; restores vtables, releases the callback, performs base cleanup, and conditionally deletes.`
- Formal C++ insertion text:

```cpp
// Compiler-emitted scalar deleting destructor for FolderSelectDialog::~FolderSelectDialog().
// Source destructor ownership and declarations are covered by UID 000059;
// the exact deleting-destructor wrapper is regenerated by the compiler.
```

- No-code proof: the body is compiler lowering for the source destructor and deleting flag. It restores all three FolderSelectDialog vtable views, releases `m_resultCallback`, calls the polluted base-destructor label, and conditionally frees memory. Handwritten destructor-wrapper code would be decompiler-shaped ABI output, so the child should carry this exact marker rather than a fake source body.

### Resolved Naming And Policy Boundaries

- FunctionObjects spelling: use `FolderSelectCallback` as the local source-facing alias for the semantic callback role, with `FunctionObjectT<SimpleUString>` as the bounded placeholder already documented by FunctionObjects. Exact original template spelling is unproven but no longer blocks this split or the OnCommand/Populate first drafts.
- Drive-list control/helper naming: use inferred source-facing `PopupMenuControlPane`, `StringMenuItem`, `AppendItem`, `GetItem`, `GetItemCount`, `GetSelectedIndex`, `SetSelectedIndex`, and `CopyText`. These names are support-backed and should replace raw helper labels in child C++.
- Folder tree helpers: use inferred `BuildSelectedPath`, `SetRootNodeName`, and `SelectNodeByPath` for source-facing docs. The constructor marker keeps `SelectNodeByPath` out of emitted code until the broader constructor body is source-safe.
- Emitter routing: method-body children route to file [UID:0000JF] with explicit positions. This avoids placing out-of-class method definitions inside the [UID:000059] class declaration block.

## Evidence Standards Used

- IDA MCP was used as mandatory ground truth for function starts/sizes, decompilation, disassembly, xrefs, bytes, data refs, and live IDB/session provenance.
- Existing by-* docs and executed B reports were used as accepted context only after fresh MCP recheck.
- Negative evidence includes no-xref, no-absolute-pointer, no-vtable-slot, no-normal-caller, and generated-label rejection checks.
- Tool limitations: MCP/IDA does not prove original source names, exact template spelling, or original source filename. Those remain source-quality inferences from behavior and current project docs.

## Evidence Checked

IDA MCP session/provenance:

- Endpoint `http://127.0.0.1:13337/mcp` responded to `initialize` with server `ida-pro-mcp`, version `1.0.0`.
- `idb_list` active session: `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`.
- `server_health`: status `ok`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready true, Hex-Rays ready true.

MCP calls performed:

- `tools/list` schema check.
- `lookup_funcs` for `0x004b1590`, `0x004b1920`, `0x004b1a00`, `0x004b1b05`, `0x004b1b10`, `0x004b1b20`, `0x004b1b90`, `0x00529790`, `0x0052986d`, `0x0052a3e0`, and `0x0052a4a0`.
- `decompile` for `0x004b1920`, `0x004b1a00`, and `0x004b1b20`; `analyze_batch` included constructor decompilation.
- `callees` and `analyze_component` for `0x004b1590`, `0x004b1920`, `0x004b1a00`, and `0x004b1b20`.
- `xref_query` for all function starts, vtable slots, caller/callee instructions, `0x0061a4f4`, and `0x0066da88`.
- `disasm` for `0x004b1b05`, `0x004b1b10`, and `0x004b18d6`.
- `get_bytes` for boundary/padding/vtable/data ranges.
- `get_int` for vtable slot dwords and UTF-16 data words.
- `get_string`, `entity_query`, `trace_data_flow`, and `find_bytes`.

Docs and generated reports checked:

- `by-structure.md` IDA MCP/metadata rules and score/C++ gates.
- `by-project-structure/proposed-source-tree.md` entries for `ui/dialogs/FolderSelectDialog.cpp`, `ui/controls/FolderTreePane.cpp`, `ui/dialogs/MusicControlDialog.cpp`, and `util/FunctionObjects.cpp`.
- Current target and support pages listed in `Current Target State`.
- Executed B014 `000059-FolderSelectDialog-class-source-quality.md` and B008 `00005A-FolderTreePane-class-source-quality.md`.
- `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md`.

Failed/unavailable checks:

- One initial `find_bytes` call used `pattern` instead of the current schema's `patterns`; this was a request-shape error, not MCP unavailability. The call was rerun successfully with `patterns`.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| UID 000154 should split before method-body C++ | High | MCP function inventory, decompile/disasm, padding bytes, by-structure C++ range rule | Existing aggregate docs and B014 report checked; no single source item covers the full range | Implementation callback must create/register children |
| Direct owner is FolderSelectDialog | High | Constructor/vtable/destructor/data refs, class/file docs, proposed source tree | MusicControlDialog caller and FolderTreePane hosted-control alternatives rejected | Original source filename not proven |
| `0x004b1a00` is retained/no-entry `PopulateDriveList` | High | Decompile/callees/source-shaped body; xref_query total 0; absolute pointer byte search 0 | Vtable slots and data refs checked; no caller found | Emit as retained private helper through file UID 0000JF, but do not invent a constructor call |
| `this+0x26c` is `m_folderTreePane` | High | Constructor store, OnCommand selected-path/root calls, FolderTreePane docs | Generic `mbr_26c` rejected | Exact original field spelling not proven |
| `this+0x270` is owned `m_resultCallback` | High | Constructor store, OK/cancel invoke slot `+12`, destructor release slot `+0` | MusicControl-specific field type rejected | Exact FunctionObjects type spelling remains open |
| `0x004b1b05/0x004b1b10` are compiler adjustor thunks | High | Two-instruction disasm: `sub ecx, 0xa0/0xa4; jmp 0x004b1b20`; vtable-only xrefs | No source method body or normal caller | None for source docs; keep non-emitting |

## Positive Evidence Summary

- MCP confirms exact function starts and sizes: constructor `0x004b1590` size `0x346`, OnCommand `0x004b1920` size `0xe0`, helper `0x004b1a00` size `0x105`, thunks `0x004b1b05`/`0x004b1b10` size `0x0b`, scalar deleting destructor `0x004b1b20` size `0x67`, successor FolderTreePane constructor `0x004b1b90` size `0x155`.
- Constructor has one code xref from `0x0052986d` in MusicControlDialog command handling.
- OnCommand is vtable-routed through data at `0x0061a4a4 -> 0x004b1920`.
- Destructor and thunks are vtable-routed: `0x0061a45c -> 0x004b1b20`, `0x0061a4bc -> 0x004b1b05`, `0x0061a4ec -> 0x004b1b10`.
- Mutable drive-root buffer `0x0066da88` has exactly four MCP data-flow refs: constructor write/use at `0x004b183f`/`0x004b185b` and helper write/use at `0x004b1a8b`/`0x004b1aaa`.
- Proposed source-tree docs explicitly place FolderSelectDialog under `ui/dialogs/` and FolderTreePane under `ui/controls/`.

## IDA MCP Facts

Function/range facts:

- `0x004b1590-0x004b18d6`: constructor, IDA name `sub_4B1590`, size `0x346`, prototype `int __thiscall(int this, int, wchar_t *)`.
- `0x004b18d6-0x004b1920`: no standalone function. Disasm from `0x004b18d6` shows alignment, vtable cleanup writes at `0x004b18e9`, `0x004b18ef`, `0x004b18f9`, callback release through `[this+0x270]`, a tail jump to currently polluted `boost::exception` destructor label at `0x004b1910`, then alignment before `sub_4B1920`.
- `0x004b1920-0x004b1a00`: command handler, decompile shows OK selected-path callback, cancel empty-string callback, close call, drive-list notification `a3 == 10`, selected item copy, and `FolderTreePane::SetRootNodeName`.
- `0x004b1a00-0x004b1b05`: drive-list helper, decompile shows `GetLogicalDrives`, current directory read, `_toupper`, 32-drive loop, `asc_66DA88[0] = driveIndex + 65`, item allocation/construction, append, and selected-drive update.
- `0x004b1b05` and `0x004b1b10`: two-instruction adjustor thunks.
- `0x004b1b20-0x004b1b87`: scalar deleting destructor, decompile writes all three FolderSelectDialog vtable views, releases `this+0x270`, calls a polluted base destructor label, and conditionally frees through `0x004f4ac0`.

Data/table/padding facts:

- `get_bytes 0x004b1585 size 11`: eleven `0xcc` bytes before the constructor.
- `get_bytes 0x004b1b1b size 5`: five `0xcc` bytes before scalar deleting destructor.
- `get_bytes 0x004b1b87 size 9`: nine `0xcc` bytes before `FolderTreePane::FolderTreePane`.
- `get_int 0x0061a45c`: `4922144` (`0x004b1b20`).
- `get_int 0x0061a4a4`: `4921632` (`0x004b1920`).
- `get_int 0x0061a4bc`: `4922117` (`0x004b1b05`).
- `get_int 0x0061a4ec`: `4922128` (`0x004b1b10`).
- `get_bytes` for `0x0061a4f4` and `0x0066da88`: `58 00 3a 00 5c 00 00 00`.
- `get_int` for `0x0066da88/8a/8c/8e`: UTF-16 words `88`, `58`, `92`, `0`, i.e. `X`, `:`, `\`, terminator.

Xref facts:

- `xref_query 0x004b1a00`: total `0`, no cross-references.
- `trace_data_flow 0x0066da88 backward`: four code refs listed above.
- `trace_data_flow 0x0061a4f4 backward`: one constructor data ref at `0x004b173a`.
- `entity_query` `.rdata` names around `0x0061a450-0x0061a510`: `FolderSelectDialog` vtable names at `0x0061a45c`, `0x0061a4bc`, `0x0061a4ec`, followed by `Tree<FolderTreePane::TreeElem>` vtable names at `0x0061a500` and `0x0061a510`.

Negative IDA facts:

- No MCP xrefs to `0x004b1a00`.
- No absolute little-endian pointer bytes `00 1A 4B 00` found by MCP `find_bytes`.
- No vtable/data slot points to `0x004b1a00`.
- No standalone function exists at `0x004b18d6`; it is cleanup/padding before `0x004b1920`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b1590-0x004b1b87` | UID 000154 current target | aggregate compiler output island | currently true, should become false after split | 000059 | 88/91 current, 90/92 after split | split container, no emitter |
| `0x004b1590-0x004b18d6` | UID 000457 `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md` | constructor | true | 000059 | 84/90 | emit marker through 0000JF position 10 |
| `0x004b18d6-0x004b1920` | UID 000458 `by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md` | constructor cleanup/padding | false | NONE | 84/88 | no emitter, no-code proof |
| `0x004b1920-0x004b1a00` | UID 000459 `by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md` | `OnCommand` | true | 000059 | 87/91 | emit first-draft body through 0000JF position 20 |
| `0x004b1a00-0x004b1b05` | UID 00045A `by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md` | retained/no-entry `PopulateDriveList` | true | 000059 | 86/90 | emit retained helper body through 0000JF position 30, no invented caller |
| `0x004b1b05-0x004b1b20` | UID 00045B `by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md` | adjustor thunks plus padding | false | NONE | 88/92 | no emitter, no-code proof |
| `0x004b1b20-0x004b1b87` | UID 00045C `by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md` | scalar deleting destructor support | true as generated-binary source-destructor support | 000059 | 86/90 | emit marker through 0000JF position 40 |
| `0x004b1b90-...` | UID 000155 and successors | FolderTreePane control | true | 00005A/0000JG | existing | separate owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0052986d -> 0x004b1590` | code call inside `sub_529790` | MusicControlDialog constructs FolderSelectDialog |
| `0x004b178b -> 0x004b1b90` | code call inside constructor | FolderSelectDialog constructs hosted FolderTreePane |
| `0x004b18b1 -> 0x004b2730` | constructor callee | optional initial path selection |
| `0x0061a4a4 -> 0x004b1920` | vtable data slot | OnCommand virtual route |
| `0x004b197f -> 0x004b3090` | OnCommand callee | selected path construction from FolderTreePane selection |
| `0x004b19e9 -> 0x004b25e0` | OnCommand callee | drive-root reset on list notification |
| `0x0061a45c -> 0x004b1b20` | vtable slot | scalar deleting destructor |
| `0x0061a4bc -> 0x004b1b05` | vtable slot | secondary adjustor thunk |
| `0x0061a4ec -> 0x004b1b10` | vtable slot | tertiary adjustor thunk |

## Documentation Evidence And IDA Status

- Current target page already contains most accepted B014 facts but keeps the exact child split pending.
- `by-class/FolderSelectDialog.md` and `by-file/FolderSelectDialog.md` already have class/file-level C++ and source split policy; method bodies/markers should now be routed through the exact child pages above.
- `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md` source page is current at `87/92`, but auto-generated coverage still shows stale `86/90` and stale "unassigned because parent below gate" wording. Do not manually edit generated coverage; validator refresh should correct it after source validation/executed report flow.
- `auto-generated/-ag-research-tracker.md` and `project-level/-auto-completion-stats.md` are stale for UID 000154 and related pages. Use current source docs as authority, and refresh generated state through validator commands only after accepted implementation.

## Ranked Ownership Analysis

### 1. FolderSelectDialog class / FolderSelectDialog.cpp

- Evidence for: constructor/destructor/vtable/data refs, class/file pages, proposed source tree, drive-root data refs, caller only from MusicControl, hosted FolderTreePane field, B014 accepted report.
- Evidence against: exact original source path not recovered; final original FunctionObjects type spelling unproven.
- Decision: accepted owner route [UID:000059] and file-scope emitter route [UID:0000JF] for source-authored child method text.

### 2. MusicControlDialog

- Evidence for: one constructor call at `0x0052986d`; concrete callback wrapper target belongs to MusicControlDialog.
- Evidence against: caller/consumer only; no ownership of vtables, drive-root data, command handler, or destructor; MusicControl page explicitly says `FolderSelectDialog::Show` is source-level convenience shorthand for allocation plus constructor.
- Decision: rejected as owner.

### 3. FolderTreePane

- Evidence for: constructed by FolderSelectDialog, used for selected-path and root reset.
- Evidence against: separate class/file docs and source tree; successor function starts at `0x004b1b90`; tree control has own vtables, fields, tree templates, and B008 accepted owner.
- Decision: rejected as owner; keep as hosted control dependency.

### 4. FunctionObjects

- Evidence for: callback object family and concrete MusicControl wrapper.
- Evidence against: owns callback declarations/support, not the dialog island.
- Decision: support dependency only.

## Source Placement

- Recommended source file/class placement: `NexusTK/ui/dialogs/FolderSelectDialog.cpp` / likely `FolderSelectDialog.h` under [UID:0000JF] and [UID:000059].
- Why this fits source-tree/subsystem context: proposed-source-tree lists `ui/dialogs/FolderSelectDialog.cpp` and `ui/controls/FolderTreePane.cpp` together, with MusicControlDialog as the caller. The dialog builds a modal folder picker and delegates filesystem tree work to a reusable control.
- Rejected placements: `MusicControlDialog.cpp`, `FolderTreePane.cpp`, and `util/FunctionObjects.cpp` for the reasons above.
- Remaining placement uncertainty: exact original source filename/header split is inferred, not symbol-proven.

## Range / Split / Padding / Reclassification Analysis

Exact split recommendation:

- Create exact source children for constructor, OnCommand, retained helper, and scalar deleting destructor support.
- Create exact generated-artifact children for cleanup/padding and adjustor-thunk/padding ranges.
- After child creation, update UID 000154 from a source-bearing aggregate into a non-emitting split/container page with child links and blank C++.
- Preserve current boundary facts in the parent. The parent is still useful as an address-order audit page, but it should not own final method body source once children exist.

Padding/table/code distinctions:

- `0x004b1585-0x004b1590` and `0x004b1b87-0x004b1b90` are outside the target.
- `0x004b18d6-0x004b18e0` and `0x004b1915-0x004b1920` are alignment/padding around constructor cleanup code.
- `0x004b1b1b-0x004b1b20` is padding after the two adjustor thunks.

## Negative Evidence Summary

- Consumer/caller relationship from MusicControlDialog does not prove ownership.
- FolderTreePane use from constructor/OnCommand does not prove tree-control ownership by the dialog file.
- IDA/decompiler type label `boost::exception` in destructor decompilation is pollution; vtable writes and class docs prove FolderSelectDialog destructor support.
- `0x004b1a00` has no normal caller, xref, absolute pointer, or vtable slot in the current IDB. The report therefore closes the liveness blocker as retained/no-entry rather than leaving it for a future pass.
- Generated tracker rows are stale; they do not override current by-* source metadata.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested or allowed in this report-only pass. Source-facing documentation should use:

- `FolderSelectDialog::FolderSelectDialog`
- `FolderSelectDialog::OnCommand`
- `FolderSelectDialog::PopulateDriveList`
- `FolderSelectDialog::~FolderSelectDialog` / scalar deleting destructor support
- `m_folderTreePane`
- `m_resultCallback`
- `s_driveRootBuffer`
- `kDefaultDriveRootLiteral` or inline `L"X:\\"`

Names resolved or bounded for this report:

- `FolderSelectCallback` remains the local source-facing alias; exact original FunctionObjects spelling is unproven but no longer blocks child C++ policy.
- `PopupMenuControlPane`, `StringMenuItem`, `AppendItem`, `GetItem`, `GetItemCount`, `GetSelectedIndex`, `SetSelectedIndex`, and `CopyText` are the inferred drive-list/control helper names for first-draft source.
- `DialogPane` base cleanup and constructor helper names are bounded but not source-safe enough for a constructor body; that child uses the exact marker/no-code proof above.

## First-Draft C++ Recommendation

- Eligible for draft C++: not at the UID 000154 aggregate level. The current page has owner/emitter and combined score above the minimum gate, but `by-memory` C++ must stay within the page's own source item, and this page is a multi-body aggregate with compiler artifacts.
- Recommended code at the parent level: none. UID 000154 should keep an empty formal block after it becomes a split container.
- Child C++ disposition: apply the exact marker/no-code/body text in `2026-06-26 Rework Reanalysis - Exact Child Specs And C++ Disposition`. OnCommand and PopulateDriveList have first-draft bodies; constructor and scalar deleting destructor have nonblank marker comments; cleanup/padding and adjustor-thunk pages have formal no-code proofs.
- Exact no-code proof for the parent: MCP confirms separate function starts and artifact spans inside the range, including source methods at `0x004b1590`, `0x004b1920`, `0x004b1a00`, generated thunks at `0x004b1b05/0x004b1b10`, scalar deleting destructor support at `0x004b1b20`, and cleanup/padding at `0x004b18d6-0x004b1920`.

## Final Recommendation

- Exact changes recommended: split UID 000154 into the six child pages listed above, preserve fresh B013 MCP evidence in parent/support docs, apply the child formal C++/marker/no-code text from the rework section, and refresh generated reports through validators only.
- Exact parent assignments recommended: source-authored method children keep owner [UID:000059] and emit through file [UID:0000JF]; cleanup/padding and adjustor-thunk children remain owner `NONE`, reconstructable false; the scalar deleting destructor marker keeps owner [UID:000059] and emits through [UID:0000JF].
- Exact items left no-owner/non-emitting: constructor cleanup/padding child, adjustor thunks/padding child, and UID 000154 parent after split.
- Exact later polish outside this assignment scope: no blocker remains for the split report. Later polish may replace inferred helper spellings only if stronger source-name evidence appears.

## Recommended Target Doc Changes

Target path: `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`

Incorporate:

- B013 2026-06-25 IDA MCP session facts and tool list/session provenance.
- Exact split recommendation and child list.
- Current IDA evidence that generated tracker/auto coverage rows are stale relative to source page metadata.
- Stronger no-code proof for aggregate C++.
- If children are created in the implementation callback, reclassify the parent as a non-emitting split/container page, clear `EMITTER_UIDS`, keep C++ blank, and use a concise `Item Summary` describing the parent as an address-order split container.

Metadata:

- Before split: current source-page `88/91`, owner/emitter `000059`, reconstructable true can remain.
- After split: recommended parent container `90/92`, `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++, `Nested` updated to cover the created children.

Historical/stale assumptions to preserve:

- Older "unresolved helper caller" wording is superseded by no-entry proof from IDA `xref_query` total 0 and absolute pointer byte search total 0.
- Older B014 raw PE evidence remains useful but should be explicitly supplemented by B013 current MCP evidence.

## Recommended Support Doc Changes

Support paths and facts:

- `by-class/FolderSelectDialog.md`: add a short B013 support sync noting that UID 000154 split is now implementation-ready; class-level C++ remains declaration-only with `[[CHILDREN]]`.
- `by-file/FolderSelectDialog.md`: add exact child split plan and retained/no-entry helper policy; keep source path unchanged.
- `by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md`: no metadata change required; optionally add B013 dword/xref confirmation for `0x0061a4a4`, `0x0061a4bc`, `0x0061a4ec`.
- `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`: no metadata change required; optionally add B013 `trace_data_flow` confirmation of the single constructor ref.
- `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`: source page already has correct `87/92`; ensure any stale Item Summary/coverage wording about parent below gate is fixed only in source metadata/body and refreshed through validator, not by editing generated coverage.
- `by-memory` new child pages: create/register exact pages with validator; do not guess UIDs.

## Score And Metadata Recommendation

- Current score/metadata: source page `88/91`, owner/emitter `000059`, reconstructable true, blank C++; generated tracker row stale `76/84`.
- Recommended score/metadata if no child split happens in the callback: keep `88/91`, owner/emitter `000059`, reconstructable true, C++ blank; add B013 current-MCP evidence and explicit split-ready plan.
- Recommended score/metadata after child split: parent [UID:000154] becomes non-emitting split container at about `90/92`, `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++, updated `Nested`.
- Score rationale: the aggregate is well evidenced, but it cannot move to final-audit quality or C++ readiness while exact child pages are absent and method-body source would cross multiple source/function/artifact boundaries.
- Reason not higher: the constructor body still has a deliberate no-code marker because exact UI-control construction APIs are not source-safe; original FunctionObjects/control-helper spellings remain inferred rather than symbol-proven.
- Score-improvement attempt: the main blockers named by the target were split/range, no-entry helper liveness, owner/source placement, field/global names, and C++ readiness. This report attacks all of them with current MCP evidence and supplies the implementation-ready repair plan rather than deferring investigation.

## Open Questions With Attempted Resolution

- Is UID 000154 cohesive enough to emit C++? Resolved: no, because it is a multi-body aggregate with generated artifacts.
- Should owner/emitter routing change? Resolved: no for source-authored children; keep [UID:000059]/[UID:0000JF]. After split, parent container should not emit.
- Is `0x004b1a00` live? Resolved for current evidence: source-shaped retained/no-entry; no current xref, absolute pointer, or vtable route.
- Are `m_folderTreePane`, `m_resultCallback`, `s_driveRootBuffer`, and `PopulateDriveList` defensible source-facing names? Resolved: yes as inferred/descriptive names; exact original spelling not proven.
- What remains unresolved? Exact original callback template/interface spelling and exact original helper spellings remain unproven, but they are bounded by the inferred names in this report and do not block split implementation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or generated tracker row text is requested. Do not edit `by-memory/-coverage-report.md` or `auto-generated/-ag-*` reports manually.

Generated refresh expectation: after accepted implementation and scoped validator runs, validator-owned generated reports should refresh from the source by-* metadata and current `Item Summary`/`Nested` lines. The current generated rows for UID 000154 and UID 00027D are stale and should be corrected by validator refresh, not manual edits.

## Follow-Up Actions

- Supervisor: verify this implementation claim by claim, then execute this report through the validator if accepted.
- B013 implementation callback: completed on 2026-06-26. Existing child pages were updated in place; no duplicates were created.
- Later source-C++ pass: optional polish only for original FunctionObjects/control helper spellings. The accepted child-level first-draft C++ and marker/no-code text is now present in the relevant child formal blocks.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for keeping current aggregate below final-audit and for split necessity; high for exact child metadata because the existing child pages have now been updated or verified in place.
- Remaining uncertainty: original source filename/header split and exact original FunctionObjects/control-helper spellings. Retained-helper emission/retention policy is resolved for this report as emitting retained private helper code with no invented inbound call.

## Validator Results

- Validator commands run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x004b1590-0x004b1b87.FolderSelectDialog.md --apply --queue-timeout 240` -> command id `000000003592`, timestamp `2026-06-26T22:44:41-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory\0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md --apply --queue-timeout 240` -> command id `000000003593`, timestamp `2026-06-26T22:44:46-04:00`, exit `0`, `ok: 1`, generated refresh deferred; autogen registry updated emitter `000059 -> 0000JF`, position blank to `10`, code blank to block.
  - `python .\tools\validator.py --mode file --file by-memory\0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md --apply --queue-timeout 240` -> command id `000000003594`, timestamp `2026-06-26T22:44:48-04:00`, exit `0`, `ok: 1`, generated refresh deferred; completion updated to `87`, emitter `000059 -> 0000JF`, position blank to `20`, code blank to block.
  - `python .\tools\validator.py --mode file --file by-memory\0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md --apply --queue-timeout 240` -> command id `000000003595`, timestamp `2026-06-26T22:44:50-04:00`, exit `0`, `ok: 1`, generated refresh deferred; completion updated to `86`, emitter `000059 -> 0000JF`, position blank to `30`, code blank to block.
  - `python .\tools\validator.py --mode file --file by-memory\0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md --apply --queue-timeout 240` -> command id `000000003596`, timestamp `2026-06-26T22:44:51-04:00`, exit `0`, `ok: 1`, generated refresh deferred; emitter `000059 -> 0000JF`, position blank to `40`, code blank to block.
  - `python .\tools\validator.py --mode file --file by-class\FolderSelectDialog.md --apply --queue-timeout 240` -> command id `000000003597`, timestamp `2026-06-26T22:44:53-04:00`, exit `0`, `ok: 1`, generated refresh deferred; validator inserted the missing generated UID link annotation for `0000JF`.
  - `python .\tools\validator.py --mode file --file by-file\FolderSelectDialog.md --apply --queue-timeout 240` -> command id `000000003598`, timestamp `2026-06-26T22:44:55-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- Queue/generation status checks:
  - `python .\tools\validator.py --queue-status` -> command id `000000003602`, timestamp `2026-06-26T22:45:44-04:00`, exit `0`, file queue empty, generated refresh still queued/processing.
  - `python .\tools\validator.py --queue-status` -> command id `000000003605`, timestamp `2026-06-26T22:48:32-04:00`, exit `0`, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- Generated output was not used for final verification and no manual generated/project-level edits were made.
- Validator-owned side effects reported: projected path completion section refresh and autogen registry/code-hash updates. No manual edits were made to generated files, any `-coverage-report.md`, validator state, tool state, or IDA DB.

## Changed Files

- Updated in place: `tools/leaser/Agents/Agent-B013/research/000154-FolderSelectDialog-source-quality.md`
- Edited by-* files:
  - `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`
  - `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`
  - `by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md`
  - `by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md`
  - `by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md`
  - `by-class/FolderSelectDialog.md`
  - `by-file/FolderSelectDialog.md`
- Verified already present, not edited: `by-memory/0x004b18d6-0x004b1920.FolderSelectDialogConstructorCleanupAndPadding.md`, `by-memory/0x004b1b05-0x004b1b20.FolderSelectDialogAdjustorThunksAndPadding.md`, `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`, `by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md`, and `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`.
- Created in this implementation: none.
- Renamed: none.
- Report execution: leave blank during the B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` after verification.
- Leases: first B013 lease batch covered parent, all six children, class, and file support pages but expired before validation; B013 re-leased the seven changed by-* files for validation and released them immediately after validators. Final shared lease report showed no active B013 leases.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report for implementation in the 2026-06-26 callback.
- [x] Target/support docs to update. Proof: edited parent `000154`, constructor `000457`, OnCommand `000459`, PopulateDriveList `00045A`, scalar deleting destructor `00045C`, class `000059`, and file `0000JF`; verified cleanup/padding `000458`, adjustor thunks `00045B`, drive-root buffer `00027D`, vtable data `0003BF`, and drive-root string `0003BG` already contained the accepted detail.
- [x] Current target state and actual evidence checked recorded. Proof: parent/child/class/file pages preserve MCP session facts, boundaries, xrefs, vtable slots, bytes, data refs, no-entry helper evidence, stale generated report state, and rejected generated labels.
- [x] Metadata/score changes applied. Proof: parent remains `90/92`, owner `000059`, `RECONSTRUCTABLE:FALSE`, blank emitter/code, `Nested:6`; OnCommand now `87/91`; PopulateDriveList now `86/90`; constructor, cleanup, adjustor, scalar scores match accepted report.
- [x] Score-limiting blockers researched to resolution or implementation-ready repair. Proof: docs now preserve exact split, retained/no-entry helper proof, owner/source placement, aggregate no-code proof, and bounded helper/type spellings.
- [x] Owner/emitter/reconstructable changes applied. Proof: source-owned child emitters updated to `0000JF` positions `10/20/30/40`; cleanup/padding and adjustor-thunk pages verified `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter; parent verified non-emitting.
- [x] Split/rename/new-child changes applied. Proof: existing UIDs `000457` through `00045C` were updated/verified in place; no duplicate child pages were created; no renames were needed.
- [x] Source-placement/range/padding/reclassification changes applied or verified. Proof: source placement remains `NexusTK/ui/dialogs/FolderSelectDialog.cpp`; parent/children preserve exact ranges; cleanup and adjustor pages remain compiler artifacts; no IDA DB edits were made.
- [x] First-draft C++ or no-code proof applied. Proof: parent formal block blank; constructor marker inserted; cleanup no-code proof already present; OnCommand body inserted; PopulateDriveList body/no-entry proof inserted; adjustor no-code proof already present; scalar deleting destructor marker inserted.
- [x] Exact target/support doc facts incorporated at report-level detail. Proof: changed docs preserve function sizes/boundaries, xrefs, vtable dwords/slots, data refs, helper no-entry proof, owner rejections, field/global names, generated-label rejection, and stale generated-report state.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve MusicControl caller-only rejection, FolderTreePane owner rejection, FunctionObjects support-only role, stale generated tracker/coverage caveat, no xrefs to `0x004b1a00`, and no absolute pointer byte match.
- [x] Wave2/Wave3/generated pollution handled. Proof: docs continue to reject generated/simroot/decompiler labels such as `boost::exception`, `TransferReplyAlert`, `ChattingColorPane`, raw `sub_4B1A00`, `mbr_26c`, `mbr_270`, and `asc_66DA88` as final source names.
- [x] Open questions closed or bounded. Proof: exact original FunctionObjects/helper spellings remain bounded/inferred; retained-helper policy is closed as retained private helper with no invented inbound call.
- [x] Validators run. Proof: file-mode `--apply` validators ran for every changed by-* file with command ids `000000003592` through `000000003598`, exit `0`, `ok: 1`; details recorded above.
- [x] Generated report refresh/manual coverage expectation handled. Proof: validator initially reported generated refresh deferred for changed files; final queue-status command `000000003605` showed no queued or processing generated-refresh jobs. Generated output was not relied on, and no manual coverage/tracker text was requested or edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` assignment id `B013-implement-000154-folder-select-dialog-split-source-quality-20260626`.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: edited/verified files and exact applied dispositions are listed above.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: source-owned child emitter routing and code/marker changes applied; cleanup/adjustor/data/vtable/string pages were already at accepted disposition and left unchanged; no duplicate child pages or renames were needed.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs retain rejected owner alternatives, generated-label rejection, retained no-entry proof, and stale generated-state caveats.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: retained-helper liveness closed as retained/no-entry; exact original helper/template spelling remains bounded/inferred with score/C++ impact stated.
- [x] Validators run and results recorded. Proof: command ids `000000003592` through `000000003598`, exit `0`, `ok: 1`, generated refresh deferred.
- [x] Generated report refresh/manual coverage state recorded. Proof: final queue-status command id `000000003605` showed file queue empty and no queued or processing generated-refresh jobs; no manual generated or coverage edits were made.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none. All accepted implementation items are edited or already present at same-or-greater detail.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/000154-FolderSelectDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/000154-FolderSelectDialog-source-quality.md","timestamp":"2026-06-26T22:50:46","uid":"000154"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
