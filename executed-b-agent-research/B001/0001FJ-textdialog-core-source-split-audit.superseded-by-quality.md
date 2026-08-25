** TARGET-REPORT-UID:0001FJ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001FJ TextDialogCore Source Split Audit

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:0001FJ][by-memory/0x00552110-0x005534a0.TextDialogCore.md] into exact source-bearing children and reclassify `0001FJ` as a non-emitting split/index page.
- Final disposition: split/create/ignore. Create three exact child pages, add four internal ignored rows, keep the already-created [UID:0003GL][by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md] outside TextDialog, and repair stale TextDialog class/file/coverage text.
- Required action: supervisor allocates three new UIDs, creates child docs, updates the parent/support docs and `by-memory/-ignored.md`, then applies the coverage replacement block below. B001 did not edit by-* docs or coverage reports.
- Confidence: high for exact boundaries, padding/table classification, and TextDialog versus NexonclubProxy ownership; medium-high for the unreferenced `0x00553350` helper's final source name because it is source-shaped but has no xrefs.

## Target

- Target UID: `0001FJ`
- Target path: `by-memory/0x00552110-0x005534a0.TextDialogCore.md`
- Source queue/report row: `project-level/-auto-completion-stats.md` lists `0001FJ` at `82/86`; `auto-generated/by-memory-tool-report.md` lists `0x00552110-0x005534a0` as a 5008-byte reconstructable leaf.
- Current header state: `COMPLETION:82`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000OL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OL`.
- Current local issue: the physical range is not one source body. It contains two IDA-modeled TextDialog functions, compiler switch data, padding, and a raw no-xref string reply helper.

## Executive Recommendation

Reclassify the broad page:

```text
UID:0001FJ
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000EL
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

Create exact source-bearing children:

| Proposed UID | New path | Range | Type | Reconstructable | Owner/emitter | Score | C++ |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0003VQ` if still next | `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md` | `0x00552110-0x0055317a` | constructor | true | `0000EL` / `0000EL` | `86/89` | blank |
| `0003VR` if still next | `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` | `0x00553180-0x00553338` | virtual method | true | `0000EL` / `0000EL` | `87/91` | blank |
| `0003VS` if still next | `by-memory/0x00553350-0x00553495.TextDialogRawStringReplyPacketHelper.md` | `0x00553350-0x00553495` | raw member/helper body | true | `0000EL` / `0000EL` | `85/86` | blank |

Current validator state check showed `last_used_uid = 0003VP`. If that is still true when applying this report, allocate `0003VQ`, `0003VR`, and `0003VS` in that order. If another agent has advanced the UID counter, allocate the next three UIDs in order and substitute them consistently in the rows/templates below.

Ignored/support ranges:

| Range | Classification | Evidence |
| --- | --- | --- |
| `0x0055317a-0x00553180` | padding | six `0xcc` bytes after constructor rangecheck-failure tail and before `sub_553180`. |
| `0x00553338-0x00553348` | compiler switch table | four dword targets for `sub_553180`: `0x005531be`, `0x005531aa`, `0x005531b4`, `0x00553316`. |
| `0x00553348-0x00553350` | padding | eight `0xcc` bytes after switch table. |
| `0x00553495-0x005534a0` | padding | eleven `0xcc` bytes between raw helper and proxy callback. |

Do not assign or emit the aggregate `0001FJ` after the split. The exact children carry the source ownership. The parent should remain only an audit/inventory page for the TextDialog method neighborhood.

## Supervisor Active Recheck

The user assigned a report-only B001 heavy inference/source-split audit for `0001FJ` and prohibited direct by-* documentation and coverage edits. This report therefore gives executable recommendations instead of applying them.

The item does require split repair before it can leave the memory-tool leaf list. Keeping `0001FJ` as one reconstructable source item hides the function/table/raw-helper split and preserves stale coverage text that still says `0x00552110-0x00553609`.

## Evidence Standards Used

Evidence used:

- Live IDA MCP session `a001_goal2_00023O`: function inventory, boundary lookup, xrefs, decompilation/disassembly observations, vtable references, and raw byte classification.
- Read-only PE pointer scan of `NexusTK.exe`: absolute VA, RVA, and direct relative call/jump hits for the relevant starts.
- Existing docs: target page, TextDialog class/file pages, TextDialog vtable data, MessageDialog wrapper page, HeadSelectDialog boundary page, NexonclubProxy callback page, coverage and ignored ledgers.
- Generated evidence: `auto-generated/by-memory-tool-report.md`, `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`.
- Wave2/simroot evidence as generated leads only: Wave2/simroot confirm `TextDialog.cpp` and `HandleDialogAction` naming, but are stale for `0x005534a0` and do not model `0x00553350`.

## IDA MCP Facts

Function/range facts:

- `0x00552110` is IDA function `sub_552110`, size `0x106a`, exact half-open range `0x00552110-0x0055317a`.
- `0x00553180` is IDA function `sub_553180`, size `0x1b8`, exact half-open range `0x00553180-0x00553338`.
- `0x00553338` is not an IDA function. It is data referenced by the action handler switch.
- `0x00553350` is not an IDA function but disassembles as a complete prologue/body/epilogue source-shaped helper ending at `0x00553495`.
- `0x005534a0` is IDA function `sub_5534A0`, size `0x169`, exact half-open range `0x005534a0-0x00553609`, already documented as [UID:0003GL] NexonclubProxy callback.
- `0x00553610` is the following NexonclubProxyDialog constructor.

Byte/table/padding facts:

- Constructor tail: `0x00553172 retn 0Ch`; rangecheck-failure call/tail at `0x00553175-0x0055317a`; then `0x0055317a-0x00553180` is `cc cc cc cc cc cc`.
- Action handler tail: rangecheck-failure tail at `0x00553333-0x00553338`; function ends at `0x00553338`.
- Switch data `0x00553338-0x00553348` bytes are `be 31 55 00 aa 31 55 00 b4 31 55 00 16 33 55 00`, four little-endian targets inside `sub_553180`.
- `0x00553348-0x00553350` is eight `0xcc` bytes.
- Raw helper starts `55 8b ec 81 ec 08 03 00 00 a1 24 2f 67 00 33 c5 89 45 fc...`, uses a security cookie, writes an opcode `0x3a` packet, and ends at `0x00553495`.
- `0x00553495-0x005534a0` is eleven `0xcc` bytes.
- `0x00553609-0x00553610` remains seven `0xcc` bytes after the proxy callback, not after TextDialog.

Xref facts:

| Address | IDA/scan xrefs | Meaning |
| --- | --- | --- |
| `0x00552110` | four direct relative calls from wrappers at `0x0054c8b7`, `0x0054c917`, `0x0054c977`, `0x0054c9d7`; no abs32/RVA hits | TextDialog constructor reached through message-dialog allocation wrappers. |
| `0x00553180` | one abs32/data hit at file offset `0x2213a0`, matching vtable slot `0x006229a0`; no code calls | Virtual action handler. |
| `0x00553338` | data abs32 hit at file offset `0x1525a6`, matching action-handler switch table reference | Switch table owned by `sub_553180`, not a function. |
| `0x00553350` | no IDA xrefs; PE scan found no abs32, RVA32, or direct rel32 call/jmp hits | Source-shaped but currently statically unreferenced helper. |
| `0x005534a0` | abs32/data hit at file offset `0x152c98`, matching `0x00553895` proxy constructor callback install | NexonclubProxy callback, not TextDialog. |
| `0x00553610` | one direct relative call from proxy allocation wrapper `0x0054ca33` | NexonclubProxy constructor. |

Vtable/global/type facts:

- [UID:0003DC][by-memory/0x00622954-0x006229f0.TextDialogVtableData.md] records TextDialog RTTI/vtables with constructor stores at `0x00552161`, `0x00552167`, `0x00552171`.
- The action handler has vtable data ref at `0x006229a0`.
- `auto-generated/-ag-class-coverage.md` shows [UID:0000EL][by-class/TextDialog.md] emits through [UID:0000OL][by-file/TextDialog.md], so `0000EL` is a valid direct owner/emitter route that surfaces to `auto-generated/NexusTK/ui/dialogs/TextDialog.cpp`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00552110-0x005534a0` | `0001FJ` / target | reviewed split index over TextDialog constructor/action/raw helper/table/padding | false | `0000EL` as index context; blank emitters | `88/90` | reclassify |
| `0x00552110-0x0055317a` | new `TextDialogConstructor` | TextDialog constructor | true | `0000EL` | `86/89` | create |
| `0x0055317a-0x00553180` | `0000VN` ignored | padding | false | none | `100/strong` | add ignored row |
| `0x00553180-0x00553338` | new `TextDialogHandleDialogAction` | virtual action handler | true | `0000EL` | `87/91` | create |
| `0x00553338-0x00553348` | `0000VN` ignored | compiler switch table for action handler | false | none | `100/strong` | add ignored row |
| `0x00553348-0x00553350` | `0000VN` ignored | padding | false | none | `100/strong` | add ignored row |
| `0x00553350-0x00553495` | new `TextDialogRawStringReplyPacketHelper` | no-xref raw source-shaped string reply helper | true | `0000EL` | `85/86` | create |
| `0x00553495-0x005534a0` | `0000VN` ignored | padding | false | none | `100/strong` | add ignored row |
| `0x005534a0-0x00553609` | `0003GL` / proxy callback | NexonclubProxyDialog string callback | true | `00009H` | `86/90` | keep outside TextDialog |

## Function Body Evidence

### `0x00552110-0x0055317a` constructor

IDA and existing docs agree this is `TextDialog::TextDialog`. The function:

- receives the packet pointer and two dialog-mode flags from the `0x0054c870`, `0x0054c8d0`, `0x0054c930`, and `0x0054c990` allocation wrappers;
- constructs the `DialogPane` base and writes TextDialog vtables at `this`, `this+0xa0`, and `this+0xa4`;
- parses packet fields into `this+0x26c`, `this+0x270`, `this+0x274`, and `this+0x276`;
- parses variable object/body/button/input text through packet/string helpers, `MultiByteToWideChar`, and the object status parser at `0x004d1f30`;
- allocates and attaches `EPFImageControlPane`, `ImageButtonControlPane`, `StaticTextControlPane`, `TextEditControlPane`, and optional `ObjectImageControlPane` children;
- chooses `DLGMSG5`, `DLGMSG51`, `DLGMSG6`, `.EPD` variants, and `NPAL8.PAL` resource paths depending on layout/state;
- ends after the rangecheck-failure guard at `0x0055317a`.

Final C++ decision: keep blank. The method is source-authored and reconstructable, but final names for packet fields, constructor flag meanings, local layout variants, child member fields, and exception/cleanup state are not source-grade. Candidate signature remains `TextDialog::TextDialog(uint8_t *packetData, char layoutFlag, char inputModeFlag)`; `layoutFlag`/`inputModeFlag` are intentionally not final names.

### `0x00553180-0x00553338` action handler

IDA and Wave2 both identify this as the TextDialog virtual action handler. It:

- switches on action id `1..4`;
- case `1` fetches the edit control from the child/control path rooted at `this+0x1fc`, calls the text-read forwarder at `0x00498c10` with max length `255`, and sends an opcode `0x3a` typed-text packet;
- writes packet fields from `this+0x26c`, `this+0x270`, `this+0x274`, and `this+0x276 + 1`;
- writes subtype byte `2`, converts the wide string with `WideCharToMultiByte`, appends it to the packet through `0x00516220`, queues via `g_packetSender` / `0x00574bb0`, then closes through `0x0049dad0`;
- cases `2`, `3`, and `4` call the shared previous/next/current helpers at `0x0054cc30`, `0x0054ccd0`, and `0x0054cd70`, then close the dialog.

Final C++ decision: keep blank. The action handler is cleaner than the constructor and should score higher, but final C++ still depends on stable command enum names, child-control field names, the edit-control accessor route, packet field names, and the final source home of the shared navigation helpers.

### `0x00553350-0x00553495` raw string reply helper

This is not padding and not a jump table. It is source-shaped code:

- standard prologue/security-cookie setup;
- `ECX` is used as `this`;
- a pointer argument supplies wide text;
- calls packet setup/writer helpers `0x00516030`, `0x00575380`, `0x005753f0`, `0x005753a0`, `WideCharToMultiByte`, `0x00516220`, and `0x00574bb0`;
- writes opcode `0x3a`, the same dialog packet fields from `this+0x26c/+0x270/+0x274/+0x276`, subtype byte `2`, and the converted string;
- uses rangecheck failure on oversize output.

Negative evidence is also strong:

- IDA `xrefs_to(0x00553350)` found no refs.
- PE scan found no abs32, no RVA32, and no direct call/jmp rel32 references to `0x00553350`.
- Wave2/simroot did not provide a method entry for `0x00553350`.

Decision: create the exact child and assign it to TextDialog anyway, with the lower `85/86` score and blank C++. The body is source-authored, uses the TextDialog packet field layout, sits in the TextDialog physical island after the action-handler switch table, and is separated from the proven proxy callback by `0xcc` padding. The safest name is descriptive rather than claiming a final original name: `TextDialogRawStringReplyPacketHelper`. Do not ignore it and do not fold it into the action handler.

Final C++ decision: keep blank. The remaining uncertainty is reachability and final source name. It may be dead/unreferenced old code, a stripped member callback, or an unmodeled helper whose reference was optimized out. None of those possibilities changes the fact that it is source-shaped TextDialog-family code.

### `0x005534a0-0x00553609` proxy callback

Do not move this back under TextDialog. [UID:0003GL] already records the decisive evidence:

- `sub_5534A0` is a `0x169`-byte function.
- Its method pointer is installed by [UID:0001FK] `NexonclubProxyDialog` constructor at `0x00553895`.
- It consumes the same proxy packet fields initialized by the proxy constructor.
- It sends opcode `0x3a` or dispatches the current-dialog helper on invalid/empty callback text.

The stale Wave2/simroot name `TextDialog::SendRegionSelectionPacket` for `0x005534a0` is contradicted by live IDA. Treat Wave2 here as stale generated-owner pollution.

## Documentation Evidence And IDA Status

Supporting docs:

- `by-file/TextDialog.md` already correctly says `0x005534a0-0x00553609` belongs to [UID:0003GL] / NexonclubProxy and that `0x00553610` starts the proxy constructor.
- `by-memory/0x00622954-0x006229f0.TextDialogVtableData.md` supports `0000EL` as the direct TextDialog class owner for vtable-adjacent method evidence.
- `by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md` gives the constructor call wrappers and confirms the TextDialog allocation family.
- `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md` confirms the preceding boundary and separately ignored `0x005520e5-0x00552110` switch/padding span.
- `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md` confirms the old `TextDialog` tail is proxy-owned.

Stale/incomplete docs:

- `by-memory/-coverage-report.md` currently links to `0x00552110-0x005534a0.TextDialogCore.md` but displays range `0x00552110-0x00553609` and still describes a region helper/proxy-adjacency mix.
- The same coverage block omits the exact `0003GL` proxy callback row before the `0x00553609-0x00553610` padding row.
- `by-class/TextDialog.md` still lists `0x005534a0-0x00553609` as `SendRegionSelectionPacket`; this contradicts the current proxy callback page and live IDA.
- `by-file/TextDialog.md` still describes `0x00553338-0x005534a0` as a local switch/alignment tail. Live bytes show `0x00553350-0x00553495` is real code.

Generated state:

- `auto-generated/by-memory-tool-report.md` currently lists the full target as a 5008-byte reconstructable leaf.
- `project-level/-auto-completion-stats.md` currently lists `0001FJ` at `82/86`.
- `auto-generated/-ag-memory-coverage.md` routes `0001FJ` through `0000OL` and `0003GL` through `00009H`; after the split, the new children should route through `0000EL` and then surface through `0000OL`.

## Ranked Ownership Analysis

### 1. [UID:0000EL] TextDialog class

Evidence for:

- `0x00552110` writes TextDialog vtables and initializes TextDialog fields.
- `0x00553180` is vtable-referenced from TextDialog vtable data.
- `0x00553350` consumes the same TextDialog packet field layout and sits before the proxy callback boundary.
- `0000EL` already emits through `0000OL`, and TextDialog vtable data uses `0000EL` as direct owner/emitter.

Evidence against:

- The old `0001FJ` page used file owner `0000OL`.
- The raw helper has no direct xrefs and no final source name.

Decision: use `0000EL` as the direct owner/emitter for the three exact source-bearing child pages. The file page remains the source-module context.

### 2. [UID:0000OL] TextDialog file

Evidence for:

- `by-file/TextDialog.md` is the source module that emits `TextDialog.cpp`.
- Generated/simroot evidence points to `TextDialog.cpp`.
- The current broad `0001FJ` routes through `0000OL`.

Evidence against:

- Exact method clusters in nearby dialog families often attach to direct by-class parents.
- The TextDialog vtable data child already uses `0000EL`, showing the class route is valid and more precise.

Decision: keep as secondary source-file route. Do not use it as the direct owner for the exact child methods unless the supervisor chooses to preserve legacy file-level routing for consistency.

### 3. [UID:0000LZ]/[UID:00009H] NexonclubProxyDialog

Evidence for:

- `0x005534a0-0x00553609` is definitely proxy callback code.
- The old Wave2 `SendRegionSelectionPacket` confusion involved the same opcode `0x3a` packet shape.

Evidence against:

- `0x00553350` has no xref from the proxy constructor or proxy callback object.
- `0x00553350` physically precedes the proxy callback and is separated from it by padding.
- Proxy ownership has a decisive function-pointer store only for `0x005534a0`, not for `0x00553350`.

Decision: accept proxy ownership only for existing `0003GL`, reject proxy ownership for the new TextDialog raw helper.

### 4. [UID:0000LA] MessageDialogs / shared dialog helpers

Evidence for:

- Constructor wrappers live in the MessageDialogs dispatcher.
- Shared previous/next/current helpers are used across message/menu-question/text dialogs.

Evidence against:

- `0x00552110`, `0x00553180`, and `0x00553350` use TextDialog instance layout and vtable/field evidence.
- The shared helpers are already separately documented at `0x0054cc30-0x0054ce0f`.

Decision: reject as direct owner for these exact children. Keep as caller/source-flow context only.

### 5. HeadSelectDialog / adjacent previous range

Evidence for:

- Physical adjacency before `0x00552110`.

Evidence against:

- `0x005520e5-0x00552110` is already switch-table/padding after HeadSelect.
- `0x00552110` installs TextDialog vtables.
- Message wrapper calls instantiate TextDialog, not HeadSelectDialog.

Decision: reject.

## Exact Supervisor Edits

### UID Allocation

If `tools/validator.ini` still reports `last_used_uid = 0003VP`, allocate:

```text
0003VQ = by-memory/0x00552110-0x0055317a.TextDialogConstructor.md
0003VR = by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md
0003VS = by-memory/0x00553350-0x00553495.TextDialogRawStringReplyPacketHelper.md
```

If the next UID has changed, allocate the next three UIDs and substitute them in every row/template below.

### Parent Header Change

In `by-memory/0x00552110-0x005534a0.TextDialogCore.md`, update the header to:

```text
*** UID:0001FJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended parent body disposition: replace the current "local switch/alignment tail" description with the child inventory from this report. State explicitly that the page is a reviewed non-emitting split/index over exact TextDialog child pages and ignored compiler artifacts.

### New Child File Template: `0003VQ`

Path: `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md`

```markdown
*** UID:0003VQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x00552110-0x0055317a TextDialog Constructor

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: class constructor.
- Covered class: [UID:0000EL][TextDialog](by-class/TextDialog.md).
- Source module context: [UID:0000OL][TextDialog](by-file/TextDialog.md).
- Parent split index: [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md).
- Final C++ gate: keep blank until packet-field names, constructor flag names, layout/control member fields, and cleanup state are source-grade.

## Evidence

IDA MCP confirms `sub_552110` starts at `0x00552110`, has size `0x106a`, and ends at `0x0055317a`. Four allocation wrappers in [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) call this constructor at `0x0054c8b7`, `0x0054c917`, `0x0054c977`, and `0x0054c9d7`. The body installs TextDialog vtables at `0x00622958`, `0x006229b8`, and `0x006229e8`, parses opcode `0x3a` dialog packet fields into offsets `+0x26c`, `+0x270`, `+0x274`, and `+0x276`, and builds EPF/image/button/static-text/text-edit controls with `DLGMSG5`, `DLGMSG51`, `DLGMSG6`, `.EPD`, and `NPAL8.PAL` resources.

## Boundary

The final source byte is the rangecheck-failure tail ending at `0x0055317a`. The following `0x0055317a-0x00553180` span is six `0xcc` bytes and belongs in [UID:0000VN][-ignored](by-memory/-ignored.md), not this constructor.

## Cross-References

- [UID:0000EL][TextDialog](by-class/TextDialog.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:0003DC][0x00622954-0x006229f0.TextDialogVtableData](by-memory/0x00622954-0x006229f0.TextDialogVtableData.md)

## Changes

- Created from B001 report `0001FJ-textdialog-core-source-split-audit.md` to split the broad TextDialogCore leaf into exact child pages.
```

### New Child File Template: `0003VR`

Path: `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md`

```markdown
*** UID:0003VR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x00553180-0x00553338 TextDialog Handle Dialog Action

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: virtual class method.
- Covered class: [UID:0000EL][TextDialog](by-class/TextDialog.md).
- Source module context: [UID:0000OL][TextDialog](by-file/TextDialog.md).
- Parent split index: [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md).
- Final C++ gate: keep blank until command names, child-control member names, packet-field names, and shared navigation-helper source placement are final.

## Behavior

`sub_553180` handles TextDialog command ids. Action `1` reads the editable text control, builds an opcode `0x3a` typed-text reply with fields from `this+0x26c`, `this+0x270`, `this+0x274`, and `this+0x276 + 1`, appends subtype byte `2` and converted text, queues the packet through `g_packetSender` / `QueueAndSendPacket`, then closes the dialog. Actions `2`, `3`, and `4` call the shared previous, next, and current dialog packet helpers at `0x0054cc30`, `0x0054ccd0`, and `0x0054cd70`, then close.

## Evidence

IDA MCP confirms `sub_553180` starts at `0x00553180`, has size `0x1b8`, and ends at `0x00553338`. The method has a vtable data reference at `0x006229a0`. Wave2/simroot generated evidence independently names this behavior `HandleDialogAction`, but source-quality naming still needs final review. The following `0x00553338-0x00553348` data is the compiler switch table for this method, not part of a separate source function.

## Cross-References

- [UID:0000EL][TextDialog](by-class/TextDialog.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md)
- [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md)
- [UID:0003DC][0x00622954-0x006229f0.TextDialogVtableData](by-memory/0x00622954-0x006229f0.TextDialogVtableData.md)

## Changes

- Created from B001 report `0001FJ-textdialog-core-source-split-audit.md` to split the broad TextDialogCore leaf into exact child pages.
```

### New Child File Template: `0003VS`

Path: `by-memory/0x00553350-0x00553495.TextDialogRawStringReplyPacketHelper.md`

```markdown
*** UID:0003VS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x00553350-0x00553495 TextDialog Raw String Reply Packet Helper

## Status

- Disposition: reconstructable NexusTK project code with unresolved reachability/name.
- Entity kind: raw member/helper body.
- Covered class: [UID:0000EL][TextDialog](by-class/TextDialog.md).
- Source module context: [UID:0000OL][TextDialog](by-file/TextDialog.md).
- Parent split index: [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md).
- Final C++ gate: keep blank because no caller/callback reference or final source name has been proven.

## Behavior

The raw body uses `ECX` as a TextDialog-style `this` pointer and a wide-string argument to build an opcode `0x3a` reply packet. It writes the dialog fields at offsets `+0x26c`, `+0x270`, `+0x274`, and `+0x276 + 1`, writes subtype byte `2`, converts the supplied wide text with `WideCharToMultiByte`, appends the converted bytes through the packet buffer helper, and sends through `g_packetSender` / `QueueAndSendPacket`.

## Evidence

IDA does not model a function at `0x00553350`, but the bytes form a complete source-shaped prologue/security-cookie/body/epilogue helper from `0x00553350` through `0x00553495`. The preceding `0x00553338-0x00553348` span is the action-handler switch table, `0x00553348-0x00553350` is `0xcc` padding, and the following `0x00553495-0x005534a0` span is `0xcc` padding before the proven NexonclubProxy callback [UID:0003GL]. IDA `xrefs_to` and a read-only PE scan found no direct refs to `0x00553350`, so the final source-facing name remains provisional.

## Assignment Rationale

Assign to TextDialog because the helper consumes the same TextDialog packet field layout, is physically inside the TextDialog island, and has no proxy-constructor callback installation. Do not classify as padding or compiler output.

## Cross-References

- [UID:0000EL][TextDialog](by-class/TextDialog.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md)
- [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md)

## Changes

- Created from B001 report `0001FJ-textdialog-core-source-split-audit.md` to split the broad TextDialogCore leaf into exact child pages.
```

### `by-memory/-ignored.md` Additions

Append a new TextDialog internal entry near the existing dialog/container padding section:

```markdown
- `0x0055317a-0x00553180`, `0x00553348-0x00553350`, and `0x00553495-0x005534a0` - TextDialog internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact TextDialog constructor, action-handler, raw reply-helper, and neighboring NexonclubProxy callback ranges.
  - Evidence: 2026-06-16 B001 IDA MCP byte audit found six `0xcc` bytes at `0x0055317a-0x00553180`, eight `0xcc` bytes at `0x00553348-0x00553350`, and eleven `0xcc` bytes at `0x00553495-0x005534a0`.
  - Owner docs: [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md), [UID:0003VQ][0x00552110-0x0055317a.TextDialogConstructor](by-memory/0x00552110-0x0055317a.TextDialogConstructor.md), [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md), [UID:0003VS][0x00553350-0x00553495.TextDialogRawStringReplyPacketHelper](by-memory/0x00553350-0x00553495.TextDialogRawStringReplyPacketHelper.md), and [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md).

- `0x00553338-0x00553348` - TextDialog action-handler switch table.
  - Why ignored: compiler-generated dword target table for [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md), not a standalone source declaration.
  - Evidence: 2026-06-16 B001 IDA MCP byte audit found four little-endian targets `0x005531be`, `0x005531aa`, `0x005531b4`, and `0x00553316`, all inside `sub_553180`, with the data xref from the action handler switch dispatch.
  - Replacement/procurement: express the `HandleDialogAction` switch in source and let the compiler regenerate equivalent table data.
```

If the supervisor allocates different UIDs, substitute them in these ignored rows.

### `by-class/TextDialog.md` Replacement Method Map

Replace the current `## Method Map` table with:

```markdown
## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x00552110-0x0055317a` | `TextDialog::TextDialog` | Parses dialog packet fields, chooses normal/high-resolution resources, and constructs child controls. |
| `0x00553180-0x00553338` | `HandleDialogAction` | Handles submit, previous, next, and current commands; action `1` reads the edit control and sends the typed-text opcode `0x3a` reply. |
| `0x00553350-0x00553495` | raw string reply packet helper | Source-shaped but currently unreferenced helper that builds an opcode `0x3a` reply from a supplied wide string; final original name unresolved. |

`0x00553338-0x00553348` is the compiler switch table for `HandleDialogAction`; `0x0055317a-0x00553180`, `0x00553348-0x00553350`, and `0x00553495-0x005534a0` are `0xcc` alignment padding. `0x005534a0-0x00553609` is not a TextDialog method; it belongs to [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md).
```

Recommended class score after update: `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000OL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OL`, blank C++.

### `by-file/TextDialog.md` Function Map Replacement

Replace the current TextDialog function-map lines for `0x00552110-0x005534a0` with:

```markdown
| `0x00552110-0x0055317a` | `TextDialog::TextDialog` | Parses dialog packet fields and builds normal/high-resolution layouts with `DLGMSG5`, `DLGMSG51`, or `DLGMSG6` resources. |
| `0x00553180-0x00553338` | `HandleDialogAction` | Handles submit/navigation actions; action `1` reads the edit control and sends a typed-text packet. |
| `0x00553338-0x00553348` | action switch table | Compiler-generated target table for `HandleDialogAction`; ignored support data. |
| `0x00553350-0x00553495` | raw string reply packet helper | Source-shaped TextDialog-family opcode `0x3a` string reply helper with no current direct refs; final source name unresolved. |
```

Add/replace ownership note:

```markdown
- Do not describe `0x00553338-0x005534a0` as only local switch/alignment. Live IDA byte review shows `0x00553338-0x00553348` is the action switch table, `0x00553348-0x00553350` and `0x00553495-0x005534a0` are `0xcc` padding, and `0x00553350-0x00553495` is source-shaped TextDialog packet-helper code with no current xrefs.
```

Recommended file score after update: `COMPLETION:89`, `CONFIDENCE:89`. Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and `CANONICAL_OWNER:FILE`.

### Coverage Replacement Block

In `by-memory/-coverage-report.md`, replace the current local block:

```markdown
    - [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md) 0x00552110-0x00553609 | class method cluster | TextDialogCore : reconstructable : 82% : strong : Existing IDA-backed docs confirm exact constructor/action/region helper bounds, TextDialog file/class ownership, opcode `0x3a` typed-text and region-selection packet paths, g_packetSender/QueueAndSendPacket/PacketBuffer helper dependencies, child ObjectImage/TextEdit/StaticText/EPF control dependencies, HeadSelect/Nexonclub adjacency boundaries, parent attachment to UID `0000OL`, and blank final C++ below 95/95.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00553609-0x00553610 | padding | TextDialogCore to NexonclubProxyDialogConstructor alignment : ignored : 100% : strong : Confirmed `0xcc` bytes after corrected `TextDialog` helper endpoint.
```

with this block, substituting UID allocations if needed:

```markdown
    - [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md) 0x00552110-0x005534a0 | split/index | TextDialogCore exact-child inventory : ignored/non-emitting : 88% : very-strong : B001 source-split audit reclassifies the broad page as `RECONSTRUCTABLE:FALSE` because it spans exact TextDialog constructor/action/raw-helper children plus compiler switch data and padding; exact children carry TextDialog source ownership through [UID:0000EL][TextDialog](by-class/TextDialog.md), while the parent remains only the reviewed address-neighborhood index.
        - [UID:0003VQ][0x00552110-0x0055317a.TextDialogConstructor](by-memory/0x00552110-0x0055317a.TextDialogConstructor.md) 0x00552110-0x0055317a | constructor | TextDialogConstructor : reconstructable : 86% : strong : IDA confirms `sub_552110` exact size `0x106a`, four allocation-wrapper callers at `0x0054c8b7/0x0054c917/0x0054c977/0x0054c9d7`, TextDialog vtable stores, packet field initialization at `+0x26c/+0x270/+0x274/+0x276`, DLGMSG resource/control construction, and final C++ remains blank pending packet/layout/member naming.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055317a-0x00553180 | padding | TextDialog constructor to action-handler alignment : ignored : 100% : strong : Six `0xcc` bytes after the constructor rangecheck-failure tail and before `sub_553180`.
        - [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md) 0x00553180-0x00553338 | virtual method | TextDialogHandleDialogAction : reconstructable : 87% : very-strong : IDA confirms `sub_553180` exact size `0x1b8`, vtable data ref at `0x006229a0`, action ids for submit/previous/next/current, opcode `0x3a` typed-text reply construction, shared navigation-helper calls, and blank final C++ pending command/control/packet field naming.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00553338-0x00553348 | compiler switch table | TextDialog action-handler switch targets : ignored : 100% : strong : Four dword targets `0x005531be`, `0x005531aa`, `0x005531b4`, and `0x00553316` referenced by `sub_553180`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00553348-0x00553350 | padding | TextDialog action switch table to raw helper alignment : ignored : 100% : strong : Eight `0xcc` bytes.
        - [UID:0003VS][0x00553350-0x00553495.TextDialogRawStringReplyPacketHelper](by-memory/0x00553350-0x00553495.TextDialogRawStringReplyPacketHelper.md) 0x00553350-0x00553495 | raw member/helper body | TextDialogRawStringReplyPacketHelper : reconstructable : 85% : strong : Source-shaped no-xref helper with prologue/security cookie that writes opcode `0x3a`, TextDialog packet fields, subtype byte `2`, converts a supplied wide string with `WideCharToMultiByte`, appends bytes, sends through `g_packetSender`/`QueueAndSendPacket`, and remains blank C++ because caller/reachability and final original name are unresolved.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00553495-0x005534a0 | padding | TextDialog raw helper to NexonclubProxy callback alignment : ignored : 100% : strong : Eleven `0xcc` bytes before `sub_5534A0`.
    - [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md) 0x005534a0-0x00553609 | callback method | NexonclubProxyDialogReplyCallback : reconstructable : 86% : very-strong : Existing exact child split; live IDA ties `sub_5534A0` to the NexonclubProxy constructor callback-method-pointer store at `0x00553895`, not to TextDialog, and the body sends opcode `0x3a` callback text or falls back to the current-dialog helper.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00553609-0x00553610 | padding | NexonclubProxyDialogReplyCallback to NexonclubProxyDialogConstructor alignment : ignored : 100% : strong : Seven `0xcc` bytes after [UID:0003GL] and before [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md).
```

## Final C++ Decisions

- `0001FJ` aggregate: blank forever; it should become `RECONSTRUCTABLE:FALSE`.
- Constructor child: blank for now. Unresolved names: packet layout fields at `+0x26c/+0x270/+0x274/+0x276`, constructor flags, child-control fields, layout variant names, cleanup state shape.
- Action child: blank for now. Unresolved names: command enum values, edit-control field/accessor, packet field names, shared navigation helper source home.
- Raw helper child: blank for now. Unresolved names/evidence: no caller or callback ref, final original method/helper name, whether this is dead/unreachable retained code or an unmodeled member helper.
- Proxy callback `0003GL`: no TextDialog C++; remains NexonclubProxyDialog's callback page.

## Validation Plan

After applying the above file edits and substituting actual UIDs:

> Executable block R001 was removed from this report and preserved verbatim in [0001FJ-textdialog-core-source-split-audit.superseded-by-quality-removed.md](0001FJ-textdialog-core-source-split-audit.superseded-by-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected outcome:

- `auto-generated/by-memory-tool-report.md` no longer lists `0x00552110-0x005534a0` as a largest reconstructable leaf.
- The exact children appear as reconstructable/emitting through `0000EL`.
- The parent `0001FJ` is non-reconstructable/non-emitting and therefore not counted as a reconstructable leaf.
- `project-level/-auto-completion-stats.md` no longer lists `0001FJ` in low completion/low both for the old `82/86` state.
- `by-memory/-coverage-report.md` contains the exact `0003GL` proxy callback row between the TextDialog split block and the `0x00553609-0x00553610` padding row.

## Files Touched By B001

- Created this report only: `tools/leaser/Agents/Agent-B001/research/0001FJ-textdialog-core-source-split-audit.md`.
- No by-* documentation, coverage report, ignored ledger, validator state, or generated report was edited by B001.
- No by-* lease was acquired for this report-only pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001FJ-textdialog-core-source-split-audit.superseded-by-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001FJ"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001FJ-textdialog-core-source-split-audit.superseded-by-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001FJ-textdialog-core-source-split-audit.superseded-by-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001FJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
