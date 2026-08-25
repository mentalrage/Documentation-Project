** TARGET-REPORT-UID:00007M **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00007M MailListPane Class Source-Quality Report

Assignment: `B002-goal2-mail-list-pane-class-source-quality-00007M-20260619`

Target: [UID:00007M] `by-class/MailListPane.md`

Expected report path: `tools/leaser/Agents/Agent-B002/research/00007M-MailListPane-class-source-quality.md`

Scope: report-only B-agent source-quality reanalysis. No by-* documentation file, generated file, or coverage report was edited during this pass. No A/C agent coordination was used. This report and `Agent-B002/notes.md` are the only intended writes.

## Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00007M-MailListPane-class-source-quality-removed.md](00007M-MailListPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- Status: `ok: 1`
- Target row: `ok           00007M by-class/MailListPane.md UID header exists`
- Generated/stat behavior: dry-run only. The output included `stats_incremental_skip 00007M project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows` and multiple `autogen_*_noop`/`autogen_emitter_has_no_code` lines.
- No validator `--apply` mode was run.

## Evidence Checked

- Read target page `by-class/MailListPane.md`.
- Read support pages:
  - `by-file/MailDialogs.md`
  - `by-class/MailListDialog.md`
  - `by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md`
  - `by-memory/0x00479110-0x0047ec2b.MailDialogs.md`
  - `by-type/by-vtable/MailDialogCoreVtables.md`
  - `by-type/by-vtable/MailDialogVtableFamily.md`
  - `by-class/ListPane.md`
  - `by-file/ListPane.md`
  - `by-global/g_useEpfAssets.md`
  - `by-global/g_packetSender.md`
  - `by-file/PacketBuffer.md`
  - `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
  - `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- Read generated/emitter state:
  - `auto-generated/NexusTK/ui/dialogs/MailDialogs.cpp` currently has only empty emitter markers for this class/memory child. It does not supply source-quality C++ for `MailListPane`.
- Read available recovered snippets:
  - `rg --files -g '*MailListPane*'` found `unrefined-source-backup/source/MailListPane.cpp`, `hooks-generation/cached/search/MailListPane.txt`, and several `re-agent/reports/code/0x0047a*MailListPane*.cpp` snippets.
  - The target page's recorded `source-3/simroot_v2/class_MailListPane.cpp` path was not found by that file search, so I treated the available unrefined/re-agent snippets as generated evidence, not canonical source.
  - The cached search file only lists five MailListPane functions, while the current docs and PE scan prove a larger island. That means generated snippets are incomplete and must not define final source coverage by themselves.
- Attempted live IDA MCP at `http://127.0.0.1:13337/mcp`. The connection was unavailable, so this pass used current by-* evidence plus a local read-only PE/Capstone scan of `E:\NTK\Resources\NexusTK\NexusTK.exe`.
- Local PE/Capstone scan:
  - Parsed the PE image locally. Image base was `0x00400000`.
  - Disassembled the target range and nearby mail-dialog range.
  - Scanned `.text` for direct `call rel32` references to relevant function starts.
  - Scanned `.text` for little-endian dword references to relevant function/vtable addresses.
  - Decoded relevant UTF-16 string literals at `0x006148d0`, `0x006148d8`, and `0x0061066c`.

## Current Target State

Current metadata:

- `COMPLETION:85`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000KZ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KZ`
- `RECONSTRUCTION_CPP`: blank

Current source placement:

- The class is assigned to [UID:0000KZ] `MailDialogs`.
- The broad memory aggregate is [UID:0000ZO] `0x00479110-0x0047ec2b.MailDialogs`.
- The exact child memory page is [UID:0003PV] `0x0047a8a0-0x0047b110.MailListPaneCore`.

Current target page limitation:

- It describes a "compact nine-function pane/helper island".
- The nine functions are real, but the pass found five additional source-shaped no-direct-route helper pockets inside the same range:
  - `0x0047a9e0-0x0047aa8d`
  - `0x0047aa90-0x0047ab66`
  - `0x0047ab70-0x0047ab90`
  - `0x0047aba0-0x0047abfa`
  - `0x0047ac00-0x0047ac27`
- The target and child memory page should not continue saying only nine modeled functions without acknowledging these helper pockets.

## Aggregate Boundary And Split Status

The existing `0x0047a8a0-0x0047b110` memory child boundary remains mostly correct as a source-quality island, but its internal inventory is incomplete.

Confirmed modeled functions already in the target:

| Address | Current role | Boundary status |
| --- | --- | --- |
| `0x0047a8a0-0x0047a8f9` | constructor | Exact. Ends before `int3` padding and the next helper start. |
| `0x0047a900-0x0047a9de` | add/update row | Exact. Stack row size and cookie epilogue confirm body. |
| `0x0047ac30-0x0047ac88` | lazy page request | Exact. Ends before padding and `FindMailIdIndex`. |
| `0x0047acd0-0x0047ad13` | find row by mail id | Exact. Linear search. |
| `0x0047ad80-0x0047add5` | scroll virtual slot | Exact. Vtable-only reachability. |
| `0x0047ade0-0x0047ae29` | selection virtual slot | Exact. Vtable-only reachability. |
| `0x0047ae30-0x0047ae43` | selected-mail request helper slot | Exact. Current name is misleading; see inference section. |
| `0x0047ae50-0x0047b071` | row draw virtual slot | Exact. Vtable-only reachability. |
| `0x0047b080-0x0047b110` | file-local mail page packet helper | Exact, but not class-exclusive. |

Additional source-shaped helper pockets found between documented bodies:

| Address | Best-supported role | Reachability evidence |
| --- | --- | --- |
| `0x0047a9e0-0x0047aa8d` | `RequestSelectedMailAndMarkRead` / `SendSelectedMailReadRequest` | No direct `call rel32` refs and no dword refs found in local `.text` scan. Source-shaped body clears row unread flag and sends a 7-byte mail-read/request packet. Not safe to call padding or compiler residue. |
| `0x0047aa90-0x0047ab66` | `SendDeleteRequestsForSelectedMail` | No direct `call rel32` refs and no dword refs found. Source-shaped loop over selected rows sending 6-byte delete packets. |
| `0x0047ab70-0x0047ab90` | `RemoveMailEntryById` | No direct refs found. Source-shaped `FindMailIdIndex` plus `RemoveItems(index, 1)`. |
| `0x0047aba0-0x0047abfa` | `RemoveSelectedMailEntries` | No direct refs found. Source-shaped selected-index removal loop with index adjustment. |
| `0x0047ac00-0x0047ac27` | `RequestInitialMailPage` / `RequestNewestMailPage` | No direct refs found except its own direct call to `0x0047b080`. Source-shaped wrapper for current pane mail type and top-page id `0x7fff`. |

Split recommendation:

- Keep [UID:0003PV] as the exact `MailListPaneCore` memory child for this island, but update its inventory from "nine modeled functions" to "nine modeled documented functions plus five source-shaped no-direct-route helper pockets".
- Do not split the five helper pockets into separate ownership pages unless the supervisor prefers one child per no-direct-route pocket. They share the same `MailListPane` row state, field layout, and mail packet family, so the lower-friction implementation is to document them in the target class and memory child.
- Keep broad [UID:0000ZO] as the non-emitting aggregate. Do not emit C++ from the aggregate.

## Row Record Layout

Best source-facing declaration:

```cpp
struct MailListEntryRow {
    unsigned short mailId;       // +0x000
    unsigned char unreadFlag;    // +0x002, nonzero draws unread color and is cleared by read/request helper
    unsigned char month;         // +0x003
    unsigned char day;           // +0x004
    unsigned char pad_005;       // +0x005, alignment/padding
    wchar_t sender[256];         // +0x006, first packet text and narrow left text column
    wchar_t subject[256];        // +0x206, second packet text and wide right text column
};                               // sizeof == 0x406
```

Evidence:

- Constructor calls the `ListPane` base constructor with row record size `0x406` and row height `14`.
- `AddOrUpdateMailEntry` uses a stack row at `[ebp-0x40c]` and calls the wide-copy helper twice:
  - `row + 0x006` from argument 3, maximum `0x100` wide characters.
  - `row + 0x206` from argument 6, maximum `0x100` wide characters.
- `DrawEntry`:
  - Formats `row.mailId` with UTF-16 literal `%5d` at `0x006148d0` and draws at `x + 0`.
  - Copies `row + 0x006`, truncates with literal `...` at `0x0061066c` to width `80`, and draws at `x + 35`.
  - Formats `row.month` and `row.day` with UTF-16 literal `%2d/%2d` at `0x006148d8` and draws at `x + 110`.
  - Copies `row + 0x206`, truncates to width `208`, and draws at `x + 150`.
- The draw layout supports the existing target description: id, sender, date, subject.
- Generated snippets avoid source-facing row names and represent the row pointer as `std::int16_t *param_2`; this is a type-recovery artifact and should be replaced by `MailListEntryRow *` in target/source docs.
- The `sender`/`subject` inference is strong but still source-name-level, not binary-layout-level. If a later resource caption proves the narrow first text column is subject and the wide second text column is sender, only the field names should be swapped. The offsets, sizes, packet order, and draw columns should stay as above.

## Field And Vtable Layout

`MailListPane` extends/embeds `ListPane` and has at least these class-owned fields:

| Offset | Proposed name | Type | Evidence |
| --- | --- | --- | --- |
| `+0x14c` | `m_mailType` or `m_mailListId` | `unsigned short` | Constructor stores argument 2. Packet helpers write it as big-endian 16-bit field after opcode/subopcode. All page/read/delete packets use it. |
| `+0x14e` | `m_pageRequestPending` | `unsigned char` / `bool` | Constructor clears to `0`. `RequestOlderMailIfNeeded` sets it to `1` after queueing a page request. Scroll and selection virtuals guard lazy-load calls on the same byte through the secondary subobject view at `+0xae`. |

Constructor evidence at `0x0047a8a0-0x0047a8f9`:

- Calls `ListPane` constructor at `0x004f3a50` with arguments:
  - row width/size `0x406`
  - style/flags field `0x1000`
  - height argument from caller
  - row height `0x0e`
  - flag `0`
  - flag `1`
  - flag `1`
- Writes `m_mailType` at `+0x14c`.
- Stores three vtable views:
  - primary `0x006142d8`
  - secondary `0x00614360`
  - tertiary `0x00614390`
- Clears byte `+0x14e`.
- Allocation sites in `MailListDialog` allocate `0x150` bytes, consistent with the last field at `+0x14e` plus padding.

Vtable evidence:

- Constructor writes:
  - `0x006142d8` at `0x0047a8d1`
  - `0x00614360` at `0x0047a8d7`
  - `0x00614390` at `0x0047a8e1`
- Dword reference scan confirms:
  - `0x00614364 -> 0x0047ad80`
  - `0x00614368 -> 0x0047ade0`
  - `0x00614354 -> 0x0047ae30`
  - `0x00614358 -> 0x0047ae50`
- `by-type/by-vtable/MailDialogCoreVtables.md` and `MailDialogVtableFamily.md` already have the correct vtable-family placement.

## Method Semantics And Source-Facing Names

### `MailListPane::MailListPane` at `0x0047a8a0`

Best source shape:

```cpp
MailListPane::MailListPane(short height, unsigned short mailType)
    : ListPane(0x406, 0x1000, height, 14, 0, 1, 1),
      m_mailType(mailType),
      m_pageRequestPending(false)
{
}
```

Notes:

- The exact `ListPane` constructor argument names should be synchronized with `ListPane.md`; do not invent final flag names on this page.
- Vtable stores are compiler constructor artifacts and should not be emitted as source statements.

### `MailListPane::AddOrUpdateMailEntry` at `0x0047a900`

Best source-facing signature direction:

```cpp
void MailListPane::AddOrUpdateMailEntry(
    unsigned char unreadFlag,
    unsigned short mailId,
    const wchar_t *sender,
    unsigned char month,
    unsigned char day,
    const wchar_t *subject);
```

Evidence and behavior:

- Builds a local `MailListEntryRow`.
- Writes `mailId`, `unreadFlag`, `month`, and `day`.
- Copies first and second text arguments into the two 256-wide-character fields.
- Calls `FindMailIdIndex(mailId)`.
- If a prior row exists, removes exactly one item at that index.
- Then scans existing rows using `GetItemCount` and item-fetch helper.
- Duplicate guard: if the scanned row already has the same mail id, return without insert.
- Sorted insertion rule: insert before the first row whose existing `mailId < newMailId`. This is descending mail-id order.
- If no earlier insertion point is found, inserts at the end.

Important correction:

- Current target says "updates an existing mail-id row when present, or inserts the row in sorted position." The exact operation is remove-then-insert, with a second duplicate guard during sorted scan. It does not update in place.

### `MailListPane::RequestSelectedMailAndMarkRead` at `0x0047a9e0`

Best source-facing role:

- `RequestSelectedMailAndMarkRead`
- Alternate acceptable lower-level name: `SendSelectedMailReadRequest`

Evidence:

- Reads selected index from the list state.
- If selected index is negative, returns.
- Fetches the selected row.
- Saves `row.mailId`.
- Clears `row.unreadFlag` at `+0x02`.
- Builds a packet:
  - byte `0x3b`
  - byte `0x03`
  - big-endian `m_mailType`
  - big-endian `mailId`
  - local trailing zero for stack hygiene, not sent as protocol length
- Calls `QueueAndSendPacket(g_packetSender, packet, 7)`.

Reachability:

- No direct `call rel32` references to `0x0047a9e0` were found in the local scan.
- No dword pointer references to `0x0047a9e0` were found in the local scan.
- This should be recorded as a no-direct-route retained source helper, not as dead code. It is valid source behavior and directly uses class row layout.

### `MailListPane::SendDeleteRequestsForSelectedMail` at `0x0047aa90`

Best source-facing role:

- `SendDeleteRequestsForSelectedMail`
- Alternate acceptable lower-level name: `SendSelectedMailDeleteRequests`

Evidence:

- Calls `ListPane::GetSelectedIndices(out, 0x100)` style helper at `0x004f3e80`.
- Iterates selected indices.
- Fetches each row by index.
- Builds a delete packet:
  - byte `0x3b`
  - byte `0x05`
  - big-endian `m_mailType`
  - big-endian selected `mailId`
- Calls `QueueAndSendPacket(g_packetSender, packet, 6)` for each selected row.
- Writes a local zero after the payload, but sends length `6`; do not model that zero as part of the protocol.

Reachability:

- No direct `call rel32` references and no dword pointer references found.
- Keep as no-direct-route source helper pending higher-level callback route identification.

### `MailListPane::RemoveMailEntryById` at `0x0047ab70`

Best source-facing role:

- `RemoveMailEntryById`

Evidence:

- Calls `FindMailIdIndex(mailId)`.
- If index is not `-1`, calls `ListPane::RemoveItems(index, 1)`.
- Returns with one stack argument.

Reachability:

- No direct `call rel32` references and no dword pointer references found.
- Strongly class-owned because it depends only on `MailListPane` row ids and the `ListPane` removal helper.

### `MailListPane::RemoveSelectedMailEntries` at `0x0047aba0`

Best source-facing role:

- `RemoveSelectedMailEntries`

Evidence:

- Calls `GetSelectedIndices(out, 0x100)`.
- Iterates selected indices.
- Removes each selected row with `RemoveItems(index - removedCount, 1)` to compensate for prior removals.

Reachability:

- No direct `call rel32` references and no dword pointer references found.
- This is the local UI list-removal counterpart to the delete packet sender.

### `MailListPane::RequestInitialMailPage` at `0x0047ac00`

Best source-facing role:

- `RequestInitialMailPage`
- Alternate acceptable name: `RequestNewestMailPage`

Evidence:

- Calls the file-local page request helper with:
  - `m_mailType`
  - `0x7fff`
  - layout-dependent offset derived from `g_useEpfAssets`
- Does not set `m_pageRequestPending` in this wrapper in the recovered body.

Reachability:

- No direct refs found to the wrapper start.
- The wrapper has a direct call to `0x0047b080`, so it is real source-shaped code. Do not classify as padding.

### `MailListPane::RequestOlderMailIfNeeded` at `0x0047ac30`

Best source-facing role:

- `RequestOlderMailIfNeeded`

Evidence:

- If item count is nonzero:
  - Fetches the last row.
  - Computes `upperBoundMailId = lastRow.mailId - 1`.
  - If `upperBoundMailId <= 0`, returns without sending.
- If item count is zero:
  - Uses `upperBoundMailId = 0x7fff`.
- Computes layout offset:
  - `-20` when `g_useEpfAssets == 1`
  - `-16` otherwise
  - Sent through an 8-bit packet writer, so protocol byte is `0xec` or `0xf0`.
- Calls `SendMailListPageRequest(m_mailType, upperBoundMailId, layoutOffset)`.
- Sets `m_pageRequestPending = true`.

Current target correction:

- The function checks the last row, not the first row. The lazy load is "older mail" by using the last row id minus one.

### `MailListPane::FindMailIdIndex` at `0x0047acd0`

Best source-facing role:

- `FindMailIdIndex`

Evidence:

- Loops from `0` to `GetItemCount() - 1`.
- Fetches each row via the list item-fetch helper.
- Compares `row.mailId`.
- Returns index or `-1`.

### `MailListPane::OnScrollChanged` at `0x0047ad80`

Best source-facing role:

- `OnScrollChanged`
- Alternate if naming follows `ListPane`: `OnScrollPositionChanged`

Evidence:

- Vtable-only route through secondary subobject view.
- Calls base handler at `0x0055ef50`.
- If base handler returns true, compares scroll target/current values using helpers at `0x0055e950` and `0x0055e910`.
- If the end condition is reached and `m_pageRequestPending` is false, calls `RequestOlderMailIfNeeded()` on the owner object.

Receiver adjustment:

- The decompiled/recovered view treats `this` as the `+0xa0` subobject and owner as `this - 0xa0`.
- The pending implementation should not expose a fake `ownerPane_0xA0` field as source; it should document this as a multiple-inheritance/subobject-adjusted virtual.

### `MailListPane::OnItemSelected` at `0x0047ade0`

Best source-facing role:

- `OnItemSelected`
- Alternate if matching UI framework names: `OnSelectionChanged`

Evidence:

- Vtable-only route through secondary subobject view.
- Calls base handler at `0x0055f0d0`.
- If base handler returns true, compares the selected row index against `GetItemCount() - 1`.
- If the final row is selected and `m_pageRequestPending` is false, calls `RequestOlderMailIfNeeded()`.

### `MailListPane::RequestSelectedMail` at `0x0047ae30`

Best source-facing role:

- `RequestSelectedMail`
- Alternate acceptable name: `OpenSelectedMail`

Rejected current/generated name:

- `GetSelectedMailId` is not source-quality enough. The body does not simply return a selected row id. It performs two virtual owner/parent lookups and tail-calls `0x00479d30`, the `MailListDialog` mail request helper. That helper sends/initiates the selected-mail read/open action.

Evidence:

- Body calls virtual slot `+0x1c` on `this`, then slot `+0x1c` on that result, then jumps to the mail-list dialog helper at `0x00479d30`.
- It is installed at `0x00614354`.
- It has side-effecting dialog/mail-request semantics through the target dialog, not pure id extraction.

### `MailListPane::DrawEntry` at `0x0047ae50`

Best source-facing role:

- `DrawEntry`
- Alternate if matching base class: `DrawItem`

Evidence:

- Vtable-only route at `0x00614358`.
- Tests selection using `ListPane::IsItemSelected` at `0x004f3f00`.
- If selected:
  - Temporarily clears draw-state byte `+0x70`.
  - Sets draw color `0x25`.
  - Calls render/fill callback via `[0x0069b3fc]`.
  - Uses selected background color `0x80`.
- If not selected, uses background color `0x8f`.
- If `row.unreadFlag != 0`, overrides background color to `0x0e`.
- Calls background-color helper at `0x004b9680`.
- Restores draw-state byte `+0x70` to `1`.
- Computes text y-coordinate from the row rectangle midpoint plus 6.
- Draws:
  - id at `x + 0`
  - first text field at `x + 35`, truncated to `80`
  - month/day at `x + 110`
  - second text field at `x + 150`, truncated to `208`

Helper names:

- `0x004ba820`: best source-facing name `TruncateTextWithEllipsis` or `FitTextWithSuffix`.
- `0x0041b9b0`: source-level wide formatting helper, effectively `swprintf`/`wsprintf` style.
- `0x004bab70`: draw UTF-16 text helper.
- `[0x0069b3fc]`: render/fill callback through the surface/GrafPort rendering layer. Do not source-name it as a simple invalidation helper unless the render docs prove that exact role.

### `SendMailListPageRequest` at `0x0047b080`

Best source-facing role:

- `static int __stdcall SendMailListPageRequest(unsigned short mailType, short upperBoundMailId, short layoutOffset)`
- Alternate acceptable name: `SendMailNavigatePacket`, if the callback wants to preserve the broader recovered/generated naming.

Why it is file-local, not class-exclusive:

- It uses only arguments and `g_packetSender`; it does not receive `this`.
- Direct callers exist outside `MailListPane`.
- It should be placed as a `static`/anonymous-namespace helper in `MailDialogs.cpp`, not as a `MailListPane` member.

Packet layout:

| Offset | Write | Meaning |
| --- | --- | --- |
| `0` | byte `0x3b` | mail opcode |
| `1` | byte `0x02` | page/list request subopcode |
| `2..3` | big-endian arg1 | mail list/type id |
| `4..5` | big-endian arg2 | upper-bound mail id |
| `6` | byte arg3 low byte | layout/page offset |
| `7` | local zero only | not transmitted |

Sends exactly 7 bytes through `QueueAndSendPacket(g_packetSender, packet, 7)`.

Direct callers found:

| Call site | Source-family interpretation |
| --- | --- |
| `0x0047a056` | Helper before `MailListDialog::OnAction`; walks the dialog control child at `this + 0x1fc` and sends initial/top page with `0x7fff`. |
| `0x0047ac21` | No-direct-route wrapper `0x0047ac00`, current pane initial/top page. |
| `0x0047ac7a` | `RequestOlderMailIfNeeded`, lazy older-page load. |
| `0x0047d812` | NewMailDialog path; obtains previous dialog/list pane through `DialogSession` helper `0x004a1250` and sends top-page refresh. |
| `0x0047e0e1` | MailTransferReplyAlert confirm path; finds previous mail dialog/list pane and refreshes it, then optionally pops the session. |

## Direct Call And Data Reference Summary

Direct `call rel32` scan:

| Target | Direct call sites |
| --- | --- |
| `0x0047a8a0` | `0x00479273`, `0x00479815` |
| `0x0047a900` | `0x00479406`, `0x004799a8`, `0x0047a70e` |
| `0x0047a9e0` | none found |
| `0x0047aa90` | none found |
| `0x0047ab70` | none found |
| `0x0047aba0` | none found |
| `0x0047ac00` | none found |
| `0x0047ac30` | `0x0047adc8`, `0x0047ae1c` |
| `0x0047acd0` | `0x00479f61`, `0x0047a96d`, `0x0047ab79`, `0x0047c4e2`, `0x0047e7f9` |
| `0x0047ad80` | none found; vtable-only |
| `0x0047ade0` | none found; vtable-only |
| `0x0047ae30` | none found; vtable-only |
| `0x0047ae50` | none found; vtable-only |
| `0x0047b080` | `0x0047a056`, `0x0047ac21`, `0x0047ac7a`, `0x0047d812`, `0x0047e0e1` |

Dword reference scan:

| Address | References |
| --- | --- |
| `0x006142d8` | constructor store at `0x0047a8d3` |
| `0x00614360` | constructor store at `0x0047a8dd` |
| `0x00614390` | constructor store at `0x0047a8e7` |
| `0x0047ad80` | vtable data at `0x00614364` |
| `0x0047ade0` | vtable data at `0x00614368` |
| `0x0047ae30` | vtable data at `0x00614354` |
| `0x0047ae50` | vtable data at `0x00614358` |
| `0x0047b080` | no dword pointer refs found |

## Heuristic / Inference Reanalysis And Validation

This section is intentionally source-quality oriented. Every unresolved generated/raw/helper name or ownership question from the target is either resolved to the best-supported direction or bounded with exact evidence checked and impact.

### Source Placement

Best-supported placement:

- `MailListPane` remains under [UID:0000KZ] `NexusTK/ui/dialogs/MailDialogs.cpp`.
- The file-local packet helper `0x0047b080` should also live in `MailDialogs.cpp`.
- The broad aggregate [UID:0000ZO] remains non-emitting.

Rejected alternatives:

- Standalone `MailListPane.cpp`: rejected. Constructor callers, packet handlers, refresh paths, vtable family, and `SendMailListPageRequest` callers all sit in the mail-dialog family. The target's "Current recovered file" is a generated/recovered artifact, not source placement proof.
- `PacketBuffer.cpp` ownership for `0x0047b080`: rejected. It uses packet-buffer scalar writers, but the opcode/subopcode and mail-list semantics are feature-level `MailDialogs` behavior.
- `Socket.cpp` ownership for `0x0047b080`: rejected. It calls `QueueAndSendPacket`, but the helper constructs a mail feature packet. `g_packetSender` remains Socket-owned support, not owner.
- `MailListDialog` as sole owner of `0x0047b080`: rejected. Callers include `MailListPane`, `MailListDialog`, `NewMailDialog`, and `MailTransferReplyAlert`, so file-local `MailDialogs.cpp` helper is the safer source placement.

### Class And Field Names

Best-supported class field names:

- `m_mailType` or `m_mailListId` at `+0x14c`
  - Recommendation: use `m_mailType` in the class page because current docs already use "mail type" and packet builders write it as a small route/list selector.
  - `m_mailListId` is acceptable if the broader MailDialogs source uses "list id" consistently later.
- `m_pageRequestPending` at `+0x14e`
  - Recommendation: use `m_pageRequestPending` because it is set after sending an older-page request and gates scroll/selection-triggered lazy load.
  - `m_isLoading` is weaker because there is no direct clear observed in this range. A later packet handler may clear it, but this target evidence only proves a pending/request-in-flight guard.

Rejected alternatives:

- `m_tailActionSuppressed` from generated subobject snippets: rejected as too local to a subobject decompiler view. It is the same `+0x14e` field as `m_pageRequestPending`.
- A signed short for `m_mailType`: not preferred. It is written with a big-endian 16-bit packet helper and compared/transported as an id. `unsigned short` is the safer header declaration, with casts at writer sites if helper signatures use `short`.

### Row Type And Field Names

Best-supported row type:

- `MailListEntryRow`

Best-supported fields:

- `mailId`
- `unreadFlag`
- `month`
- `day`
- `sender[256]`
- `subject[256]`

Rejected alternatives:

- Keeping raw `param_2`/`std::int16_t *` from generated draw snippets: rejected. The row size, copies, byte fields, and draw offsets prove a structured record.
- `subject` at `+0x006` and `sender` at `+0x206`: rejected for now. The first field draws in the narrow left text column before the date and the second draws in the wider right text column after the date. That matches the target purpose "sender, date, subject" and common mail-list UI ordering.
- Naming byte `+0x02` as `readFlag`: rejected because draw uses nonzero to select unread color and the read/request helper clears it before sending a read/open packet. `unreadFlag` is the direct behavioral name.

Open question closure:

- The exact original member names cannot be proven from binary alone. The above names are high-probability source-facing names. This should not block C++ readiness because layout and behavior are exact; later caption/resource evidence can rename fields without changing code shape.

### Helper Names

Best-supported helper/function names:

- `0x0047a900`: `AddOrUpdateMailEntry`
- `0x0047a9e0`: `RequestSelectedMailAndMarkRead` or `SendSelectedMailReadRequest`
- `0x0047aa90`: `SendDeleteRequestsForSelectedMail`
- `0x0047ab70`: `RemoveMailEntryById`
- `0x0047aba0`: `RemoveSelectedMailEntries`
- `0x0047ac00`: `RequestInitialMailPage`
- `0x0047ac30`: `RequestOlderMailIfNeeded`
- `0x0047acd0`: `FindMailIdIndex`
- `0x0047ad80`: `OnScrollChanged`
- `0x0047ade0`: `OnItemSelected` or `OnSelectionChanged`
- `0x0047ae30`: `RequestSelectedMail` / `OpenSelectedMail`
- `0x0047ae50`: `DrawEntry`
- `0x0047b080`: `SendMailListPageRequest`

Rejected alternatives:

- `GetSelectedMailId` for `0x0047ae30`: rejected as misleading, because it delegates to the dialog mail-request helper and is not a pure getter.
- `SendMailNavigatePacket` for `0x0047b080`: acceptable as an internal alternate, but less precise for this target. The packet is specifically the mail list page request opcode/subopcode.
- Treating `0x0047a9e0-0x0047ac27` as dead code: rejected. The bodies are complete, source-shaped, and use real class state and packet helpers. Lack of direct refs only limits reachability confidence.

### Support Helper/Global Names

Best-supported support names:

- `0x00575380`: `PacketBufferWriteUInt8`
- `0x005753a0`: `PacketBufferWriteUInt16BE`
- `0x00574bb0`: `QueueAndSendPacket`
- `0x0067a7ec`: `g_packetSender`
- `0x0066da97`: `g_useEpfAssets`
- `0x004ba820`: `TruncateTextWithEllipsis` or `FitTextWithSuffix`
- `0x004f3bd0`: `ListPane::GetItemCount`
- `0x004f3c00`: `ListPane::InsertItem`
- `0x004f3d60`: `ListPane::RemoveItems`
- `0x004f3dc0`: `ListPane` item-fetch helper, best local use name `GetItemAt` / `GetItemDataAt`
- `0x004f3e80`: `ListPane::GetSelectedIndices`
- `0x004f3f00`: `ListPane::IsItemSelected`

Open question closure:

- The exact source spelling of the item-fetch helper at `0x004f3dc0` is not proven in this pass. It is safe to describe its role as "item-fetch helper" in the class page and use a local readable wrapper name in first-draft C++.
- The exact source spelling of `0x004ba820` is not proven. Use a descriptive name and cross-link a text-fit helper page if one exists or is later created. Its semantics are exact: fit/truncate a wide string with suffix `...` to a pixel width.

### Caller And Reachability

Best-supported reachability:

- Constructor and add/update helper have ordinary direct callers in mail-list dialog parse/setup code.
- Scroll/select/draw/request-selected slots are vtable-routed.
- `0x0047b080` is direct-called by multiple MailDialogs-family callers.
- The five helper pockets between `0x0047a9e0` and `0x0047ac27` have no direct or dword route found in the local scan, but are still source-shaped and should be documented as no-direct-route helpers.

Open question closure:

- I cannot safely prove the UI/action callback route for the five no-direct-route helpers without live IDA cross-reference state or a broader virtual/action table audit. The exact evidence checked was direct relative call refs and dword pointer refs across `.text`; both were negative. This should cap confidence below 90 but does not justify ignoring the code.

### C++ Readiness

Active supervisor gate from `Supervisor.md` Rule 20 uses reconstructable true, nonblank valid emitter, and average completion/confidence above 85, while still requiring source readiness. The current target is `85/86`, average `85.5`, reconstructable, and has emitter `0000KZ`, so it is gate-eligible.

Source-quality readiness finding:

- The class is eligible for first-draft C++ after the implementation callback synchronizes the target and support docs with this report.
- Do not insert final C++ before documenting the five helper pockets and the file-local ownership of `0x0047b080`; otherwise emitted code would preserve the target's stale "nine functions only" model.
- This is not a no-code target. The exact no-code proof does not apply because the class has source-shaped UI logic, stable owner/emitter, exact row layout, and packet helper behavior.

## First-Draft C++ Recommendation

Recommendation: emit first-draft C++ in the later implementation callback, after the target/support docs are updated. The following is a source-quality draft to incorporate, not a byte-for-byte final header. It intentionally uses local helper names that should be synchronized with `ListPane`, `PacketBuffer`, `QueueAndSendPacket`, and render/text helper pages.

```cpp
struct MailListEntryRow {
    unsigned short mailId;
    unsigned char unreadFlag;
    unsigned char month;
    unsigned char day;
    unsigned char pad_005;
    wchar_t sender[256];
    wchar_t subject[256];
};

class MailListPane : public ListPane {
public:
    MailListPane(short height, unsigned short mailType);

    void AddOrUpdateMailEntry(
        unsigned char unreadFlag,
        unsigned short mailId,
        const wchar_t *sender,
        unsigned char month,
        unsigned char day,
        const wchar_t *subject);

    void RequestSelectedMailAndMarkRead();
    void SendDeleteRequestsForSelectedMail();
    void RemoveMailEntryById(unsigned short mailId);
    void RemoveSelectedMailEntries();
    void RequestInitialMailPage();
    void RequestOlderMailIfNeeded();
    int FindMailIdIndex(unsigned short mailId) const;

    bool OnScrollChanged(int delta);
    bool OnItemSelected(unsigned int index);
    int RequestSelectedMail();
    void DrawEntry(unsigned int index, const MailListEntryRow *row, const RECT *rowRect);

private:
    unsigned short m_mailType;
    unsigned char m_pageRequestPending;
};

static int __stdcall SendMailListPageRequest(
    unsigned short mailType,
    short upperBoundMailId,
    short layoutOffset)
{
    unsigned char packet[0x104];

    unsigned char *out = packet;
    out = PacketBufferWriteUInt8(out, 0x3b);
    out = PacketBufferWriteUInt8(out, 0x02);
    out = PacketBufferWriteUInt16BE(out, mailType);
    out = PacketBufferWriteUInt16BE(out, static_cast<unsigned short>(upperBoundMailId));
    out = PacketBufferWriteUInt8(out, static_cast<unsigned char>(layoutOffset));

    return QueueAndSendPacket(g_packetSender, packet, 7);
}

MailListPane::MailListPane(short height, unsigned short mailType)
    : ListPane(0x406, 0x1000, height, 14, 0, 1, 1),
      m_mailType(mailType),
      m_pageRequestPending(0)
{
}

void MailListPane::AddOrUpdateMailEntry(
    unsigned char unreadFlag,
    unsigned short mailId,
    const wchar_t *sender,
    unsigned char month,
    unsigned char day,
    const wchar_t *subject)
{
    MailListEntryRow row;
    row.mailId = mailId;
    row.unreadFlag = unreadFlag;
    row.month = month;
    row.day = day;
    row.pad_005 = 0;
    wcscpy(row.sender, sender);
    wcscpy(row.subject, subject);

    int existingIndex = FindMailIdIndex(mailId);
    if (existingIndex != -1) {
        RemoveItems(existingIndex, 1);
    }

    int count = GetItemCount();
    for (int i = 0; i < count; ++i) {
        const MailListEntryRow *existing = static_cast<const MailListEntryRow *>(GetItemAt(i));
        if (existing->mailId == mailId) {
            return;
        }
        if (existing->mailId < mailId) {
            InsertItem(i, &row);
            return;
        }
    }

    InsertItem(count, &row);
}

void MailListPane::RequestSelectedMailAndMarkRead()
{
    int selectedIndex = GetPrimarySelectedIndex();
    if (selectedIndex < 0) {
        return;
    }

    MailListEntryRow *row = static_cast<MailListEntryRow *>(GetItemAt(selectedIndex));
    unsigned short mailId = row->mailId;
    row->unreadFlag = 0;

    unsigned char packet[0x104];
    unsigned char *out = packet;
    out = PacketBufferWriteUInt8(out, 0x3b);
    out = PacketBufferWriteUInt8(out, 0x03);
    out = PacketBufferWriteUInt16BE(out, m_mailType);
    out = PacketBufferWriteUInt16BE(out, mailId);
    QueueAndSendPacket(g_packetSender, packet, 7);
}

void MailListPane::SendDeleteRequestsForSelectedMail()
{
    int selectedIndices[0x100];
    int selectedCount = GetSelectedIndices(selectedIndices, 0x100);

    for (int i = 0; i < selectedCount; ++i) {
        const MailListEntryRow *row =
            static_cast<const MailListEntryRow *>(GetItemAt(selectedIndices[i]));

        unsigned char packet[0x104];
        unsigned char *out = packet;
        out = PacketBufferWriteUInt8(out, 0x3b);
        out = PacketBufferWriteUInt8(out, 0x05);
        out = PacketBufferWriteUInt16BE(out, m_mailType);
        out = PacketBufferWriteUInt16BE(out, row->mailId);
        QueueAndSendPacket(g_packetSender, packet, 6);
    }
}

void MailListPane::RemoveMailEntryById(unsigned short mailId)
{
    int index = FindMailIdIndex(mailId);
    if (index != -1) {
        RemoveItems(index, 1);
    }
}

void MailListPane::RemoveSelectedMailEntries()
{
    int selectedIndices[0x100];
    int selectedCount = GetSelectedIndices(selectedIndices, 0x100);

    int removedCount = 0;
    for (int i = 0; i < selectedCount; ++i) {
        RemoveItems(selectedIndices[i] - removedCount, 1);
        ++removedCount;
    }
}

void MailListPane::RequestInitialMailPage()
{
    short layoutOffset = (g_useEpfAssets == 1) ? -20 : -16;
    SendMailListPageRequest(m_mailType, 0x7fff, layoutOffset);
}

void MailListPane::RequestOlderMailIfNeeded()
{
    int count = GetItemCount();
    short upperBoundMailId = 0x7fff;

    if (count > 0) {
        const MailListEntryRow *last =
            static_cast<const MailListEntryRow *>(GetItemAt(count - 1));
        upperBoundMailId = static_cast<short>(last->mailId - 1);
        if (upperBoundMailId <= 0) {
            return;
        }
    }

    short layoutOffset = (g_useEpfAssets == 1) ? -20 : -16;
    SendMailListPageRequest(m_mailType, upperBoundMailId, layoutOffset);
    m_pageRequestPending = 1;
}

int MailListPane::FindMailIdIndex(unsigned short mailId) const
{
    int count = GetItemCount();
    for (int i = 0; i < count; ++i) {
        const MailListEntryRow *row =
            static_cast<const MailListEntryRow *>(GetItemAt(i));
        if (row->mailId == mailId) {
            return i;
        }
    }
    return -1;
}
```

Draft caveats for the callback:

- Replace placeholder `GetItemAt`, `GetPrimarySelectedIndex`, `RECT`, `RemoveItems`, `InsertItem`, `GetSelectedIndices`, and packet helper declarations with the exact local declarations accepted by the surrounding docs.
- `OnScrollChanged`, `OnItemSelected`, `RequestSelectedMail`, and `DrawEntry` should be emitted after matching the final virtual method signatures from `ListPane`/vtable docs.
- Do not emit constructor vtable writes.
- Keep `SendMailListPageRequest` file-local in `MailDialogs.cpp`, even though [UID:0003PV] includes it in the MailListPane memory child.

## Score, Metadata, And Emitter Recommendation

Target recommendation for [UID:00007M] `MailListPane`:

- `COMPLETION:88`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000KZ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KZ`
- Source file: `NexusTK/ui/dialogs/MailDialogs.cpp`

Justification:

- Completion should rise because row layout, field names, helper names, packet semantics, caller routes, vtable routes, and source placement are now substantially better resolved.
- Confidence should rise modestly because the local PE scan confirms the current docs and adds exact helper-pocket evidence.
- Confidence should stay below 90 because live IDA MCP was unavailable and five helper pockets still have no direct or dword route found.
- C++ is eligible, but implementation should first synchronize target/support docs with the newly found helper pockets and the file-local helper ownership.

Memory child recommendation for [UID:0003PV] `MailListPaneCore`:

- Raise or keep around `88/90`.
- Replace "nine modeled functions" wording with the full island inventory.
- Keep owner/emitter [UID:00007M].

## Exact Supervisor-Owned Coverage Row Text

Current exact supervisor-owned memory coverage row from `by-memory/-coverage-report.md`:

```text
      - [UID:0003PV][0x0047a8a0-0x0047b110.MailListPaneCore](by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md) 0x0047a8a0-0x0047b110 | class method island | MailListPaneCore : reconstructable : 86% : strong : Exact MailListPane list row/render/page-request island assigned to [UID:00007M][MailListPane](by-class/MailListPane.md); live IDA confirms nine modeled functions, constructor calls only from MailListDialog, vtable stores at `0x006142d8`/`0x00614360`/`0x00614390`, row operations, and local mail request helper.
```

Proposed pending replacement memory coverage row, supervisor-owned only:

```text
      - [UID:0003PV][0x0047a8a0-0x0047b110.MailListPaneCore](by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md) 0x0047a8a0-0x0047b110 | class method island | MailListPaneCore : reconstructable : 88% : strong : Exact MailListPane list row/render/page-request island assigned to [UID:00007M][MailListPane](by-class/MailListPane.md); existing live IDA evidence confirms constructor/list-update/lazy-search/virtual draw routes, while B002 PE/Capstone reanalysis confirms the `0x406`-byte `MailListEntryRow` layout, `m_mailType` at `+0x14c`, `m_pageRequestPending` at `+0x14e`, descending mail-id insertion, vtable stores at `0x006142d8`/`0x00614360`/`0x00614390`, file-local `0x0047b080` mail page request helper shared by MailDialogs callers, and source-shaped no-direct-route helper pockets at `0x0047a9e0`, `0x0047aa90`, `0x0047ab70`, `0x0047aba0`, and `0x0047ac00`.
```

Exact generated class coverage table row currently present in `auto-generated/-ag-class-coverage.md`:

```text
| [UID:00007M][MailListPane](by-class/MailListPane.md) | emits | `0000KZ` | `0000KZ` |  | no | `auto-generated/NexusTK/ui/dialogs/MailDialogs.cpp` | `by-class/MailListPane.md` |  |
```

If a supervisor-owned class narrative row is maintained elsewhere, recommended text:

```text
- [UID:00007M][MailListPane](by-class/MailListPane.md) : reconstructable : 88% : strong : MailDialogs-owned mail list pane with PE/Capstone-confirmed `0x406`-byte `MailListEntryRow` layout (`mailId`, `unreadFlag`, `month`, `day`, `sender[256]`, `subject[256]`), `m_mailType` at `+0x14c`, `m_pageRequestPending` at `+0x14e`, descending mail-id add/update semantics, vtable-only scroll/select/request/draw slots, file-local mail page request helper `0x0047b080` shared across MailDialogs callers, and newly documented no-direct-route helper pockets for selected read, selected delete, remove-by-id, remove-selected, and initial-page actions; first-draft C++ is eligible after support docs are synchronized.
```

No coverage row was edited in this pass.

## Target And Support Implementation Checklist

For the later same-agent implementation callback:

1. `by-class/MailListPane.md`
   - Update score to recommended `88/88`.
   - Replace "compact nine-function pane/helper island" with full inventory: nine documented functions plus five source-shaped no-direct-route helpers.
   - Correct `RequestOlderMailIfNeeded` wording from "current first row" to "last row id minus one; empty list uses `0x7fff`".
   - Add `MailListEntryRow` layout exactly:
     - `+0x00 unsigned short mailId`
     - `+0x02 unsigned char unreadFlag`
     - `+0x03 unsigned char month`
     - `+0x04 unsigned char day`
     - `+0x05 pad`
     - `+0x06 wchar_t sender[256]`
     - `+0x206 wchar_t subject[256]`
     - size `0x406`
   - Add class fields:
     - `+0x14c unsigned short m_mailType`
     - `+0x14e unsigned char/bool m_pageRequestPending`
   - Rename or qualify `GetSelectedMailId` as `RequestSelectedMail` / `OpenSelectedMail` with explanation that it delegates to `MailListDialog` request helper.
   - Add raw helper pockets with no-direct-route evidence:
     - `0x0047a9e0 RequestSelectedMailAndMarkRead`
     - `0x0047aa90 SendDeleteRequestsForSelectedMail`
     - `0x0047ab70 RemoveMailEntryById`
     - `0x0047aba0 RemoveSelectedMailEntries`
     - `0x0047ac00 RequestInitialMailPage`
   - Add file-local helper `0x0047b080 SendMailListPageRequest` as shared `MailDialogs.cpp` helper, not a class-exclusive member.
   - Include the first-draft C++ after adapting helper signatures to the accepted `ListPane`/packet declarations.

2. `by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md`
   - Update score around `88/90`.
   - Replace "nine modeled functions" with full inventory and range table.
   - Add PE/Capstone evidence for helper pockets and no-direct/dword refs.
   - Add packet layouts for subopcode `0x02` page request, `0x03` selected read/open request, and `0x05` selected delete request.
   - Add exact call-site table for `0x0047b080`.
   - Add row layout and field offsets.

3. `by-file/MailDialogs.md`
   - Add source-placement note that `SendMailListPageRequest` is a file-local mail dialog helper used by `MailListPane`, `MailListDialog`, `NewMailDialog`, and `MailTransferReplyAlert`.
   - Update MailListPane row to include no-direct helper pockets and first-draft C++ readiness.
   - Keep alert-specific ownership boundaries intact; do not move `MailTransferReplyAlert` class ownership because of the shared helper call.

4. `by-memory/0x00479110-0x0047ec2b.MailDialogs.md`
   - Update the MailListPane child row so it no longer says only "9 functions".
   - Add the newly found helper pockets in the aggregate inventory under the MailListPane child, or state that they are carried by [UID:0003PV].
   - Keep aggregate non-emitting.

5. `by-class/MailListDialog.md`
   - Cross-link that `MailListDialog` parser/setup callers feed `MailListPane::AddOrUpdateMailEntry`.
   - Note `0x0047a056` uses shared `SendMailListPageRequest` for initial/top page.
   - If the page still references a stale `90/90+` C++ gate, replace it with current Rule 20 language in the callback only if the supervisor wants support-gate cleanup included.

6. `by-type/by-vtable/MailDialogCoreVtables.md`
   - Optional but recommended: adjust slot display names:
     - `0x0047ad80` `MailListPane::OnScrollChanged`
     - `0x0047ade0` `MailListPane::OnItemSelected` / `OnSelectionChanged`
     - `0x0047ae30` `MailListPane::RequestSelectedMail`
     - `0x0047ae50` `MailListPane::DrawEntry`
   - No ownership change.

7. `by-type/by-vtable/MailDialogVtableFamily.md`
   - Optional: mirror the same source-facing slot names or link to `MailDialogCoreVtables`.
   - No ownership change.

8. `by-class/ListPane.md` and `by-file/ListPane.md`
   - No required edit for this target if the class page uses helper roles instead of final helper declarations.
   - Optional: add MailListPane as a consumer example for `GetItemAt`/item-fetch, `GetSelectedIndices`, and `RemoveItems`.

9. `by-global/g_useEpfAssets.md`
   - No required edit. Optional consumer note: Mail list page request offset uses `-20` for EPF/current layout and `-16` otherwise, transmitted as a byte.

10. `by-file/PacketBuffer.md`, `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`, `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`, and `by-global/g_packetSender.md`
    - No required edit unless support pages want feature-consumer examples.
    - If edited, keep ownership with PacketBuffer/Socket and only cite MailDialogs as a consumer.

11. `by-memory/-coverage-report.md`
    - Do not let B002 edit directly unless supervisor explicitly authorizes in the callback.
    - Use the proposed exact replacement row above as supervisor-owned pending coverage text.

12. `auto-generated/NexusTK/ui/dialogs/MailDialogs.cpp`
    - Do not edit manually.
    - Let the validator regenerate after by-* C++ is accepted.

## Rejected Alternatives Summary

- Standalone source file for `MailListPane`: rejected due mail-dialog family caller/source placement.
- Treating `0x0047b080` as a `MailListPane` member: rejected; shared file-local helper.
- Treating raw helper pockets as compiler junk/dead padding: rejected; bodies are source-shaped and semantically valid.
- Keeping `GetSelectedMailId` for `0x0047ae30`: rejected; body delegates to a request/open helper.
- Using generated `std::int16_t *` row type: rejected; row layout is exact.
- Letting `PacketBuffer`/`Socket` own feature packet helpers: rejected; they own support helpers/globals, not mail opcode construction.

## Open Questions And Closure Status

- Exact original source spellings for `MailListEntryRow`, `m_mailType`, `m_pageRequestPending`, and helper functions are not recoverable from binary alone. The report provides high-probability names with evidence and rejected alternatives; this should be considered closed for implementation unless source text later appears.
- The five helper pockets' runtime route is not proven. Evidence checked: direct `call rel32` refs and dword pointer refs across `.text`, both negative. They should be documented as no-direct-route source helpers, not omitted. This caps score/confidence but does not block target C++ after documentation sync.
- Exact `ListPane` helper declarations should be synchronized with `ListPane` docs during implementation. Use role names in prose where signatures are not final.
- The generated/recovered snippets are incomplete and contain subobject artifacts. They can inform vtable/subobject reasoning but must not drive final source names by themselves.

## Final Report-Only Status

- Report file created at `tools/leaser/Agents/Agent-B002/research/00007M-MailListPane-class-source-quality.md`.
- `by-*` documentation was not edited.
- `by-memory/-coverage-report.md` was not edited.
- Generated files were not edited.
- Validator baseline exited `0` with `ok: 1`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00007M-MailListPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00007M"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00007M-MailListPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00007M-MailListPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00007M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
