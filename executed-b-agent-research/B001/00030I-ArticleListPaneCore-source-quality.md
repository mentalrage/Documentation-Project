** TARGET-REPORT-UID:00030I **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00030I ArticleListPaneCore MCP-Backed Source-Quality Redo

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00030I] `0x004748f0-0x004751b1.ArticleListPaneCore` assigned to direct owner/emitter [UID:00000L] `ArticleListPane`; keep source routing through [UID:0000HT] `BoardDialogs`; do not split, rename, reroute, or enter C++ in this pass.
- Final disposition: report-only MCP-backed redo of the moved-back offline report. Active IDA MCP session `b880584f` validates the previous local PE/Capstone body findings and removes the old "MCP unavailable" evidence caveat.
- Implementation callback status: accepted by supervisor and applied to the target/support by-* docs; offline-evidence wording is now replaced or superseded with MCP session `b880584f` facts. No `-coverage-report.md` file was edited by B001; supervisor-owned coverage replacement text remains supplied below.
- Confidence: high for owner/source placement, exact range, helper body recovery, row/member layout, `m_pageRequestPending` polarity, and stale generated-name rejection. Remaining uncertainty is source-facing original spellings, opcode `0x3b` subcommand `7` user-facing semantics, and synchronized declarations needed before final C++.

## Supporting Research

## Target

- Target UID: `00030I`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004748f0-0x004751b1.ArticleListPaneCore.md`
- Assignment: `B001-redo-article-list-pane-core-source-quality-00030I-mcp-20260623`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\00030I-ArticleListPaneCore-source-quality.md`
- Queue score in `goal.md`: `85/87`, from the moved-back offline assignment record.
- Current target header checked during this redo: `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:00000L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000L`, blank formal `RECONSTRUCTION_CPP`.
- Current direct class parent: [UID:00000L] `ArticleListPane`, currently `88/88`, owner/emitter [UID:0000HT] `BoardDialogs`.
- Current file parent: [UID:0000HT] `BoardDialogs`, currently `86/87`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.

## Current Target State

- The by-* docs already contain the prior accepted B001 facts at report-level detail: raw helper body roles, no-direct-reference results, exact `0xcc` padding, `ArticleListEntry` `0x406` layout, `m_boardId` at `+0x14c`, `m_pageRequestPending` at `+0x14e`, opcode `0x3b` selected read/subcmd7/delete/page-request behavior, `0x00474f70` activation/read-selected route, stale `categoryId` / `GetBulletinSession` / `ChattingColorListPane` rejection, optional split guidance, and no-partial-C++ proof.
- The material defect was evidence provenance, not the substantive disposition: before this callback, the target and class pages still said the 2026-06-23 B001 pass used local PE/Capstone because current-session MCP was unavailable. This implementation callback replaces/supersedes that wording with live IDA MCP session `b880584f` evidence.
- The current score is already the recommended post-incorporation score. No score raise is recommended solely for replacing the evidence basis.

## Executive Recommendation

Keep the current metadata:

- `COMPLETION:88`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00000L`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000L`
- blank formal C++

Implementation callback result: updated the target, [UID:00000L] `ArticleListPane`, [UID:0000HT] `BoardDialogs`, and the narrow [UID:00000K] `ArticleListDialog` support note to state that B001 MCP redo session `b880584f` confirms the body/boundary/xref/layout facts. Old "MCP unavailable" caveats are replaced or explicitly superseded. The already-applied facts remain valid and are no longer described as raw PE/Capstone-only evidence.

No exact child split is required before source-quality acceptance. Optional exact helper children may be useful for review granularity, but all raw helper spans are ArticleListPane-local and no alternate direct owner is supported.

## Supervisor Active Recheck

- The supervisor reassigned this moved-back report because the previous active report said IDA MCP was unavailable.
- Active MCP endpoint used: `http://127.0.0.1:13337/mcp`.
- Active session used: `b880584f`.
- `idb_list` confirmed one active owned worker session `b880584f`, PID/worker PID `27504`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`.
- `server_health` confirmed status `ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- `tools/list` was rechecked. The server schema requires `database` arguments for IDB tools.
- The listed `callers` tool returned `Method 'callers' not found`; this is not an MCP availability blocker because the same caller evidence was obtained through working MCP `xrefs_to` and `analyze_batch include_callers`. Record this as a tool-schema inconsistency to avoid relying on the broken method.
- No by-* docs, generated/project-level files, IDA DB/tool state, or coverage reports were edited during this report-only pass.

## Inference Research Guidance Check

- Existing raw PE/Capstone/generated facts were treated as leads only and rechecked through IDA MCP before being retained.
- Direct IDA facts are separated from documentation evidence and inference below.
- Generated source under `simroot_v2` remains non-authoritative. It still contains stale `categoryId`, `GetBulletinSession`, shared `ListPane` helper ownership, and `InsertOrReplaceEntryText` pollution; those are rejected by MCP/body/source-route evidence.
- No Wave2/Wave3 material was used as proof. Generated output is only evidence of historical pollution and current autogen emission state.

## Evidence Checked

MCP calls performed against session `b880584f`:

- `initialize`, `tools/list`
- `idb_list`, `server_health`
- `lookup_funcs` for `0x004748f0`, `0x00474990`, raw helper starts, modeled virtuals, and `0x004751c0`
- `xrefs_to` for modeled function starts, raw helper starts, vtable stores/entries, and `0x004751c0`
- `xref_query` both-direction checks for the eight raw helper starts
- `find` `code_ref`, `data_ref`, and `immediate` for the eight raw helper starts
- `get_bytes` for raw helper first bytes and all boundary padding spans
- `insn_query` for each raw helper body and selected dialog/parser call-site ranges
- `analyze_batch` for `0x004748f0`, `0x00474990`, `0x00474da0`, `0x00474e10`, `0x00474ec0`, `0x00474f20`, `0x00474f70`, `0x00474f90`, `0x004751c0`, `0x00472ca0`, `0x004739b0`, `0x00474470`, `0x00473dc0`, and `0x00473e00`
- `entity_query` for names/strings around the target and ArticleListPane vtables
- `get_int` for ArticleListPane vtable slot values
- `int_convert` for `0x406`, `0x14c`, `0x14e`, `0x50c`, `0x104`, `0x404`, `0x7fff`, `-0x14`, and `-0x10`

Docs and generated/source leads checked:

- `Agent-B001/goal.md`
- `ntk-b-agent-workflow` skill and B-agent research workflow reference
- `by-structure.md`
- `by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md`
- `by-class/ArticleListPane.md`
- `by-class/ArticleListDialog.md`
- `by-file/BoardDialogs.md`
- `by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md`
- `by-type/by-vtable/BoardArticleDialogVtableFamily.md`
- `by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`
- `source-3/simroot_v2/class_ArticleListPane.cpp`
- archived B014 `00030I` report and active B001 moved-back report
- relevant tracker/search hits in `SupervisorAssignments.md`, `b-agent-rule26-incorporation-tracker.md`, and archived B001 `0000ZK` report

## IDA MCP Facts

### Function / Range Facts

`lookup_funcs` in session `b880584f` returns:

| Address | IDA state |
| --- | --- |
| `0x004748f0` | `sub_4748F0`, size `0x93` |
| `0x00474990` | `sub_474990`, size `0xde` |
| `0x00474a70` | `Not a function` |
| `0x00474b20` | `Not a function` |
| `0x00474c00` | `Not a function` |
| `0x00474ce0` | `Not a function` |
| `0x00474d10` | `Not a function` |
| `0x00474d70` | `Not a function` |
| `0x00474da0` | `sub_474DA0`, size `0x58` |
| `0x00474e00` | `Not a function` |
| `0x00474e10` | `sub_474E10`, size `0x43` |
| `0x00474e60` | `Not a function` |
| `0x00474ec0` | `sub_474EC0`, size `0x55` |
| `0x00474f20` | `sub_474F20`, size `0x49` |
| `0x00474f70` | `sub_474F70`, size `0x13` |
| `0x00474f90` | `sub_474F90`, size `0x221` |
| `0x004751c0` | `sub_4751C0`, size `0x90` |

This confirms the current exact target range and the modeled/raw split already documented in by-* pages.

### Xref / Caller / Callee Facts

Working MCP caller-equivalent evidence:

- `xrefs_to 0x004748f0`: code refs at `0x00472e04` and `0x00473410`, both inside `sub_472CA0` (`ArticleListDialog` constructor/setup).
- `xrefs_to 0x00474990`: code refs at `0x00472f96`, `0x004735a3`, and `0x00474666`; the latter is inside `sub_474470` list-update parser.
- `xrefs_to 0x00474da0`: code refs at `0x00474f08` inside `sub_474EC0` and `0x00474f5c` inside `sub_474F20`.
- `xrefs_to 0x00474e10`: refs at `0x00473d01`, `0x004749fd`, `0x00474ce9`, `0x004763f2`, and `0x0047e469`.
- `xrefs_to 0x00474ec0`, `0x00474f20`, `0x00474f70`, and `0x00474f90`: data refs from ArticleListPane vtable entries `0x00613ed8`, `0x00613edc`, `0x00613ec8`, and `0x00613ecc`.
- `xrefs_to 0x004751c0`: seven code refs at `0x00473df6`, `0x00474d91`, `0x00474dea`, `0x004771a2`, `0x00478232`, `0x00479031`, and `0x004790f1`, confirming shared file-level use beyond ArticleListPane.

`analyze_batch` callees:

- `0x004748f0`: `sub_4F3A50`, `sub_4F3DD0`
- `0x00474990`: `_wcscpy_s`, `sub_474E10`, `sub_4F3D60`, `sub_4F3BD0`, `sub_4F3DC0`, `sub_4F3C00`, `@__security_check_cookie@4`
- `0x00474da0`: `sub_4F3BD0`, `sub_4F3DC0`, `sub_4751C0`
- `0x00474e10`: `sub_4F3BD0`, `sub_4F3DC0`
- `0x00474ec0`: `sub_55EF50`, `sub_55E950`, `sub_55E910`, `sub_474DA0`
- `0x00474f20`: `sub_55F0D0`, `sub_4F3BD0`, `sub_474DA0`
- `0x00474f70`: no direct callees reported because the body uses two indirect virtual calls and tail-jumps to `sub_4739B0`
- `0x00474f90`: `sub_4F3F00`, draw/fill/text helpers, `_wcscpy_s`, and security cookie check
- `0x004751c0`: `sub_575380`, `sub_5753A0`, `sub_574BB0`, and security cookie check

### Negative Raw-Start Route Facts

For the eight raw helper starts `0x00474a70`, `0x00474b20`, `0x00474c00`, `0x00474ce0`, `0x00474d10`, `0x00474d70`, `0x00474e00`, and `0x00474e60`:

- `xrefs_to` returns zero cross-references for each start.
- `find type=code_ref` returns zero matches for each start.
- `find type=data_ref` returns zero matches for each start.
- `find type=immediate` returns zero matches for each start.
- `xref_query direction=both` returns only each raw instruction head's own fall-through `from` entry, not an inbound owner/caller route.

This preserves the no-direct-route caveat, but MCP `insn_query` confirms the bytes are clean source-shaped bodies rather than unrecovered junk or padding.

### Vtable / Name / String Facts

- `xrefs_to 0x00613e4c`, `0x00613ed4`, and `0x00613f04` returns constructor stores at `0x00474942`, `0x00474948`, and `0x00474952` inside `sub_4748F0`.
- `get_int u32le` confirms vtable entries:
  - `0x00613ec8 -> 0x00474f70`
  - `0x00613ecc -> 0x00474f90`
  - `0x00613ed8 -> 0x00474ec0`
  - `0x00613edc -> 0x00474f20`
- `entity_query names` in `0x004748f0-0x004751c0` returns no source names for the helper bodies.
- `entity_query names` around ArticleListPane vtables returns `??_7ArticleListPane@@6B@`, `??_7ArticleListPane@@6B@_0`, and `??_7ArticleListPane@@6B@_1`.
- `entity_query strings` for `ArticleListPane|ChattingColorListPane|GetBulletinSession|categoryId` returns class strings `. ?AVArticleListPane@@` and `. ?AVChattingColorListPane@@` in `.data`; it does not prove generated helper ownership or source-level names for the target.

### Boundary / Padding Facts

MCP `get_bytes` confirms all expected boundary bytes are `0xcc`:

| Boundary | Padding |
| --- | --- |
| `0x004748ea-0x004748f0` | 6 bytes |
| `0x00474983-0x00474990` | 13 bytes |
| `0x00474a6e-0x00474a70` | 2 bytes |
| `0x00474b19-0x00474b20` | 7 bytes |
| `0x00474bf6-0x00474c00` | 10 bytes |
| `0x00474cd6-0x00474ce0` | 10 bytes |
| `0x00474d02-0x00474d10` | 14 bytes |
| `0x00474d6a-0x00474d70` | 6 bytes |
| `0x00474d97-0x00474da0` | 9 bytes |
| `0x00474df8-0x00474e00` | 8 bytes |
| `0x00474e53-0x00474e60` | 13 bytes |
| `0x00474eb6-0x00474ec0` | 10 bytes |
| `0x00474f15-0x00474f20` | 11 bytes |
| `0x00474f69-0x00474f70` | 7 bytes |
| `0x00474f83-0x00474f90` | 13 bytes |
| `0x004751b1-0x004751c0` | 15 bytes |

### Raw Helper Body Facts

MCP `get_bytes` confirms the first 32 bytes already recorded in the docs. MCP `insn_query` confirms these source-facing roles:

| Range | MCP-backed role | Key instructions / facts |
| --- | --- | --- |
| `0x00474a70-0x00474b19` | `RequestSelectedArticleRead` / selected read packet helper | Reads selected index `[this+0x134]`; negative index returns; calls `sub_4F3DC0`; reads `word [this+0x14c]` and row `word [entry+0]`; writes opcode `0x3b`, subcmd `3`, board id, article id, trailing zero; calls `sub_574BB0` with length `7`. |
| `0x00474b20-0x00474bf6` | `SendSelectedArticleSubcommand7Requests` | Calls `sub_4F3E80` with cap `0x100`; loops selected indices; sends opcode `0x3b`, subcmd `7`, board id, article id; calls `sub_574BB0` with length `6`. |
| `0x00474c00-0x00474cd6` | `SendSelectedArticleDeleteRequests` | Same selected-index loop shape; sends opcode `0x3b`, subcmd `5`, board id, article id; calls `sub_574BB0` with length `6`. |
| `0x00474ce0-0x00474d02` | `RemoveArticleEntryById` | Pushes argument, calls `sub_474E10`; if result is not `-1`, calls `sub_4F3D60(index, 1)`; returns with `retn 4`. |
| `0x00474d10-0x00474d6a` | `RemoveSelectedArticleEntries` | Gets selected indices with cap `0x100`; loops with removal-count adjustment `selectedIndex - removedCount`; calls `sub_4F3D60(index, 1)`. |
| `0x00474d70-0x00474d97` | `RequestInitialArticlePage` / `RequestNewestArticlePage` | Reads `word [this+0x14c]`; tests `byte_66DA97`; computes `-20` when EPF flag is `1`, else `-16`; pushes `0x7fff`, board id, offset; calls `sub_4751C0`. |
| `0x00474e00-0x00474e10` | `SetPageRequestPending(bool)` | Writes byte arg to `[this+0x14e]`; returns `retn 4`. |
| `0x00474e60-0x00474eb6` | `FindArticleInsertIndex` | Scans rows through `sub_4F3BD0` / `sub_4F3DC0`; compares row article id against argument; returns `-1` on duplicate, current index when existing id is lower, otherwise item count. |

### Modeled Body Facts

- `0x004748f0`: `analyze_batch` decompile shows ListPane setup with row size `1030`, style `4096`, caller height, row height `14`, vtable stores, `*(WORD *)(this+332)=a3`, `*(BYTE *)(this+334)=0`, then `sub_4F3DD0(this,1)`.
- `0x00474990`: decompile builds the row stack frame, writes status byte, month, day, article id, bounded-copies title and author with max `0x100`, removes existing id via `sub_474E10`/`sub_4F3D60`, then inserts in descending id order with `sub_4F3C00`.
- `0x00474da0`: decompile requests `lastArticleId - 1` if rows exist and positive, otherwise `0x7fff`; calls `sub_4751C0(boardId, requestId, offset)` and sets `[this+334]=1`.
- `0x00474e10`: decompile scans row ids and returns index or `-1`.
- `0x00474ec0`: decompile calls base input/scroll handler, checks end-scroll helpers, and calls `sub_474DA0(this-0xa0)` only when the pending byte is zero.
- `0x00474f20`: decompile calls base key/selection handler, compares selected index to `GetItemCount()-1`, and calls `sub_474DA0(this-0xa0)` only when the pending byte is zero.
- `0x00474f70`: disassembly performs two indirect virtual calls at slot `+0x1c` and tail-jumps to `sub_4739B0`; decompile confirms it is not a pure getter.
- `0x00474f90`: decompile draws selected/background colors, status color `0x0e`, id `%5d`, date `%2d/%2d`, title at row `+0x006`, author at row `+0x206`, with `...` truncation.
- `0x004751c0`: decompile sends opcode `0x3b`, subcmd `2`, two 16-bit args and one byte arg, then queues length `7`.

### Dialog-Side Facts

- `insn_query 0x00472df0-0x00472e20` and `0x004733f0-0x00473420` show `ArticleListDialog` pushes `word [edi+274h]` as the second constructor argument before calls to `sub_4748F0` at `0x00472e04` and `0x00473410`; this is board id, not generic `categoryId`.
- `insn_query 0x00474470-0x004746ab` shows the parser clears `mov byte ptr [eax+14Eh], 0` at `0x004744f5` before row insertion. It then pushes author, day, month, title, article id, and status byte into `sub_474990` at `0x00474666`.
- `analyze_batch 0x004739b0` shows selected-read packet construction with opcode `0x3b`, subcmd `3`, board id from pane `+0x14c`, selected article id, trailing zero, length `7`; `xrefs_to` includes `0x00474f7e` from the pane activation helper.
- `analyze_batch 0x00473dc0` shows page request through `sub_4751C0(..., 0x7fff, offset)`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Direct MCP facts | Best source-quality decision | Rejected alternatives |
| --- | --- | --- | --- |
| Direct owner | Constructor callers are `ArticleListDialog`; constructor stores `ArticleListPane` vtables; all local helpers use pane row state. | Keep direct owner/emitter [UID:00000L] `ArticleListPane`. | Reject direct `ArticleListDialog`, `BoardDialogs`, `ListPane`, and `ChattingColorListPane` ownership. |
| Source file route | `BoardDialogs` owns current class/file route; shared navigation helper callers span board/article classes. | Keep source route through [UID:0000HT] `BoardDialogs`; possible future `ArticleDialogs.cpp` split remains broad file-work, not target-local. | Reject `ListPane.cpp` or a new file solely for this target. |
| Range/split | MCP confirms modeled/raw starts and all `0xcc` boundary padding. | Keep one exact class method island; optional raw-helper child splits only for review granularity. | Reject merge with `0x004751c0` because that helper has seven cross-class refs. |
| `+0x14c` | Constructor writes arg to `[this+0x14c]`; packet helpers serialize it as board id. | Use `m_boardId`, constructor arg `boardId`. | Reject generated `categoryId`. |
| `+0x14e` | Constructor clears `0`; parser clears `0`; older-page helper sets `1`; end-scroll/key handlers require zero; setter writes arg. | Use `m_pageRequestPending` or narrower `m_nextPageRequestPending`; prefer `m_pageRequestPending`. `0` means allowed/not pending, `1` means request pending/suppress automatic repeat. | Reject final names `m_pageRequestBlocked`, `m_nextPageRequestSuppressed`, or `sortEnabled` as primary names. |
| Row layout | Constructor row size `0x406`; add-entry stack row; paint offsets; parser arg order. | Use `ArticleListEntry` layout listed below. | Reject `author[257]`, `readStatus`/`replyFlag` for date bytes, and final read/unread polarity for status byte. |
| `0x00474f70` | Two virtual owner hops then tail-jump to `sub_4739B0`; read packet target confirmed. | Name role `OnArticleActivated` / `OnItemActivated` / activation-read callback. | Reject `GetBulletinSession` as a pure getter. |
| Raw helpers | MCP `insn_query` recovers every raw body; direct refs remain absent. | Use descriptive helper names in docs; no IDA DB function definitions requested. | Reject "unrecovered body" blocker and reject force-defining functions as a documentation fix. |
| Generated pollution | `simroot_v2` still has `categoryId`, `GetBulletinSession`, `InsertOrReplaceEntryText`, and shared `ListPane` methods under ArticleListPane. | Preserve these as stale lead/pollution notes only. | Do not allow generated source to override MCP-backed ownership/body facts. |
| C++ readiness | Target clears minimum score/emitter gate, but declarations and helper API names remain unsynchronized. | Keep formal C++ blank; future full aggregate or split-first C++ is viable. | Reject partial helper-only C++ that would mix recovered bodies with unresolved declarations. |

## ArticleListEntry Layout

MCP confirms `0x406 == 1030`, `0x14c == 332`, `0x14e == 334`, `0x50c == 1292`, `0x104 == 260`, `0x404 == 1028`, `0x7fff == 32767`, `-0x14 == -20`, and `-0x10 == -16` through MCP `int_convert`.

Recommended row layout:

```cpp
struct ArticleListEntry {
    unsigned short articleId;      // +0x000
    unsigned char statusByte;      // +0x002; paint treats nonzero as color/background 0x0e
    unsigned char month;           // +0x003
    unsigned char day;             // +0x004
    unsigned char pad_005;         // +0x005
    wchar_t title[256];            // +0x006
    wchar_t author[256];           // +0x206
}; // sizeof == 0x406
```

Use neutral `statusByte` or `articleStatusByte` until packet/server or UI-language evidence proves final read/unread/type polarity.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004748f0-0x004751b1` | [UID:00030I] target | ArticleListPane constructor/helper/virtual cluster | true | [UID:00000L] | `88/89` current | Keep assigned; update evidence basis from offline to MCP. |
| `0x004748f0-0x00474983` | in target | constructor, `boardId`, `m_pageRequestPending=0` | true | [UID:00000L] | included | MCP modeled function. |
| `0x00474990-0x00474a6e` | in target | `AddOrUpdateArticleEntry` | true | [UID:00000L] | included | MCP modeled function. |
| `0x00474a70-0x00474b19` | in target | selected article read/open packet helper | true | [UID:00000L] | included | MCP raw no-function body, no direct refs. |
| `0x00474b20-0x00474bf6` | in target | selected subcmd `7` packet helper | true | [UID:00000L] | included | MCP raw no-function body, no direct refs. |
| `0x00474c00-0x00474cd6` | in target | selected delete packet helper | true | [UID:00000L] | included | MCP raw no-function body, no direct refs. |
| `0x00474ce0-0x00474d02` | in target | remove entry by id | true | [UID:00000L] | included | MCP raw no-function body, no direct refs. |
| `0x00474d10-0x00474d6a` | in target | remove selected entries | true | [UID:00000L] | included | MCP raw no-function body, no direct refs. |
| `0x00474d70-0x00474d97` | in target | initial/newest page request wrapper | true | [UID:00000L] | included | MCP raw no-function body, no direct refs. |
| `0x00474da0-0x00474df8` | in target | older-page request helper | true | [UID:00000L] | included | MCP modeled function. |
| `0x00474e00-0x00474e10` | in target | `SetPageRequestPending` | true | [UID:00000L] | included | MCP raw no-function body, no direct refs. |
| `0x00474e10-0x00474e53` | in target | `FindArticleById` | true | [UID:00000L] | included | MCP modeled function. |
| `0x00474e60-0x00474eb6` | in target | `FindArticleInsertIndex` | true | [UID:00000L] | included | MCP raw no-function body, no direct refs. |
| `0x00474ec0-0x00474f15` | in target | end-scroll/input page-request hook | true | [UID:00000L] | included | Vtable-routed MCP modeled function. |
| `0x00474f20-0x00474f69` | in target | key/selection end-of-list hook | true | [UID:00000L] | included | Vtable-routed MCP modeled function. |
| `0x00474f70-0x00474f83` | in target | activation/read-selected callback | true | [UID:00000L] | included | Vtable-routed MCP modeled function. |
| `0x00474f90-0x004751b1` | in target | draw article row | true | [UID:00000L] | included | Vtable-routed MCP modeled function. |
| `0x004751c0-0x004753df` | [UID:00030H] | shared article navigation helper island | true | [UID:0000HT] | `85/89` current | Remains separate file-level dependency. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00472e04`, `0x00473410` | code refs to `0x004748f0` from `sub_472CA0` | ArticleListDialog constructs ArticleListPane with board id. |
| `0x00472f96`, `0x004735a3`, `0x00474666` | code refs to `0x00474990` | ArticleListDialog setup/list-update parser populates rows. |
| `0x004744f5` | `mov byte ptr [eax+14Eh], 0` | Parser clears `m_pageRequestPending`. |
| `0x00474f08`, `0x00474f5c` | code refs to `0x00474da0` | Scroll/key end-of-list paths request older page only when pending byte is zero. |
| `0x00613ec8`, `0x00613ecc`, `0x00613ed8`, `0x00613edc` | vtable entries to `0x00474f70`, `0x00474f90`, `0x00474ec0`, `0x00474f20` | Vtable-routed ArticleListPane virtuals. |
| `0x00474d91`, `0x00474dea` | refs/calls to `0x004751c0` | ArticleListPane reaches shared file-level article navigation helper. |
| `0x00473df6`, `0x004771a2`, `0x00478232`, `0x00479031`, `0x004790f1` | other refs to `0x004751c0` | Rejects absorbing shared helper into ArticleListPane. |

## Documentation Evidence And IDA Status

- Target/support docs already carry the valid facts but should remove or supersede statements that the current B001 evidence pass lacked IDA MCP.
- `by-memory/-coverage-report.md` currently has the correct score/disposition but says raw helper bodies were recovered by local PE/Capstone disassembly. Replace with MCP-backed wording if the supervisor chooses to update coverage.
- `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` has empty emitter markers for `ArticleListPane` and [UID:00030I]. This matches the no-code recommendation.
- `simroot_v2/class_ArticleListPane.cpp` still has stale generated names (`categoryId`, `GetBulletinSession`) and unrelated shared/distant helper ownership (`InsertOrReplaceEntryText`, `ListPane` helpers). Treat as pollution, not source truth.

## Ranked Ownership Analysis

### 1. [UID:00000L] ArticleListPane

- Evidence for: constructor callers from `ArticleListDialog`, vtable stores and entries, row state at `0x406`, board id at `+0x14c`, pending byte at `+0x14e`, selected read/delete/page helpers, row painting, and class docs all align.
- Evidence against: eight helper starts have no direct inbound refs, and generated source polluted this class with unrelated/shared helpers.
- Decision: accepted. No-direct raw helpers remain confidence caps, not ownership blockers, because their MCP bodies use ArticleListPane row/member state inside the exact island.

### 2. [UID:0000HT] BoardDialogs

- Evidence for: current file bucket owns board/article dialog family and the shared article-navigation helper.
- Evidence against: this range is class method code with ArticleListPane vtables, not file-local free helper code.
- Decision: keep as source file route, not direct canonical owner.

### 3. [UID:00000K] ArticleListDialog

- Evidence for: constructs the pane, produces row data, clears pending byte in parser, and owns selected-read dialog logic.
- Evidence against: constructor/control ownership is not ownership of the child class methods; the target has its own vtables and row renderer.
- Decision: reject as direct owner, retain as caller/producer support.

### 4. [UID:00007A] / [UID:0000KT] ListPane

- Evidence for: shared base helper calls dominate row storage operations.
- Evidence against: shared helper implementation is elsewhere; this target contains derived ArticleListPane behavior and board/article packet policy.
- Decision: reject for this target. Keep shared helpers in ListPane docs.

### 5. ChattingColorListPane / generated class owners

- Evidence for: generated/simroot pollution and class string existence only.
- Evidence against: no MCP refs, no target-range ownership evidence, wrong address island, and no chat-specific row state in these bodies.
- Decision: reject.

## Source Placement

- Recommended placement: `ArticleListPane` methods under current [UID:0000HT] `BoardDialogs` route, projected to `NexusTK/ui/dialogs/`.
- Broader source-tree note: a future original-source split could rename or split `BoardDialogs.cpp` into `ArticleDialogs.cpp` or `BulletinDialogs.cpp`, but this target does not justify a route change by itself.
- Shared `0x004751c0` navigation helper remains [UID:00030H] file-level support because callers span article-list dialog/pane, normal new-article, predefined-form article, and transfer-reply alert paths.

## Range / Split / Padding / Reclassification Analysis

- Exact range `0x004748f0-0x004751b1` remains correct.
- Internal raw starts are source-shaped bodies, not padding, and not IDA-modeled functions.
- All expected boundary padding bytes are `0xcc`, including before the target and before successor [UID:00030H].
- No helper body has evidence of a different direct owner.
- Recommendation: no required split/reclassify/rename. Optional exact helper children are acceptable for review granularity only; they are not a prerequisite for target ownership/source placement.

## IDA Rename / Type / Comment Recommendations

- No IDA DB edits are requested in this report-only pass.
- Source-facing names to use in docs/future C++:
  - `ArticleListPane::ArticleListPane(..., unsigned short boardId)`
  - `AddOrUpdateArticleEntry` or existing `AddArticleEntry` with update semantics
  - `RequestSelectedArticleRead` / `SendSelectedArticleReadRequestFromPane`
  - `SendSelectedArticleSubcommand7Requests`
  - `SendSelectedArticleDeleteRequests`
  - `RemoveArticleEntryById`
  - `RemoveSelectedArticleEntries`
  - `RequestInitialArticlePage` / `RequestNewestArticlePage`
  - `RequestOlderArticlesIfNeeded` / `RequestNextArticlePage`
  - `SetPageRequestPending`
  - `FindArticleById`
  - `FindArticleInsertIndex`
  - `OnArticleActivated` / `OnItemActivated`
  - `DrawArticleListItem` / `OnPaintItem`
- Keep exact original-name confidence conservative. These are source-facing descriptive names inferred from MCP body behavior, not PDB-proven original spellings.

## MailListPane Comparison

[UID:0003PV] `MailListPaneCore` is the closest current precedent:

- It has the same `0x406` row-size family, row id/status/month/day/two wide-text buffer layout, `+0x14c` list selector, `+0x14e` pending byte, selected read/delete helpers, initial/older page requests, and vtable-routed draw/scroll/selection helpers.
- MailListPane has first-draft C++ for source-ready bodies but leaves some virtual/draw declarations synchronized through its class/file support. ArticleListPane can follow the same source shape later.
- Difference: ArticleListPane still has subcmd `7` semantic uncertainty and should first replace stale MCP-unavailable evidence in docs before a full aggregate C++ pass. MailListPane also clears read/unread status on selected read; ArticleListPane selected-read helper does not clear the row status byte, so `RequestSelectedArticleRead` is safer than `MarkSelectedArticleRead`.

## First-Draft C++ Recommendation

- Eligible by minimum gate: yes, current target is `88/89`, reconstructable, and has nonblank emitter [UID:00000L].
- Recommendation: keep formal `RECONSTRUCTION_CPP` blank for this callback.
- No-code proof: MCP confirms all raw helper bodies, but final aggregate C++ still needs synchronized declarations for `ArticleListPane`, `ArticleListEntry`, shared `ListPane` row APIs, packet writer/send helpers, draw/text-fit helpers, color constants, virtual signatures, and final source-facing names. A partial helper-only C++ block would mix recovered bodies with unresolved declarations and imply the whole exact covered range is source-ready.
- Future C++ path: either emit one full `ArticleListPaneCore` aggregate after declarations are synchronized, or split exact helper children first and emit child-level bodies. Do not emit only the easiest helpers while leaving the rest as undocumented pseudo-source.

## Score And Metadata Recommendation

- Current target score/metadata checked in by-* docs: `88/89`, owner/emitter [UID:00000L], reconstructable true, blank formal C++.
- Recommended target score/metadata: unchanged `88/89`, owner/emitter [UID:00000L], reconstructable true, blank formal C++.
- If comparing to the stale moved-back queue row, the previous `85/87 -> 88/89` raise remains justified because MCP now confirms every raw helper body, boundary, row/member layout, and stale-name rejection.
- Reason not higher: original names remain inferred, no direct inbound refs exist for the eight raw starts, subcmd `7` semantics remain unresolved, and final C++ declaration/API synchronization is still pending.
- Recommended support metadata: keep `ArticleListPane` at `88/88`, `BoardDialogs` at `86/87`, and `ArticleListDialog` at `85/88`.

## Recommended Target Doc Changes

For `by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md`, implementation callback applied:

- Replaced/superseded "current-session IDA MCP was unavailable" and "local PE/Capstone" evidence framing with MCP session `b880584f` evidence.
- Added explicit MCP redo evidence listing: session id, active IDB path, modeled/raw function map, raw helper `Not a function` state, zero direct `xrefs_to`/code_ref/data_ref/immediate routes for raw starts, exact `insn_query` raw body roles, vtable entry values, parser `+0x14e` clear, and all `0xcc` boundary padding.
- Kept `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:00000L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000L`, and blank formal C++.
- Preserved the no-code proof, optional split guidance, stale generated-name rejections, and unresolved subcmd `7`/source-name caveats.

## Recommended Support Doc Changes

- `by-class/ArticleListPane.md`: replaced/superseded local PE/Capstone-only and MCP-unavailable caveats with MCP `b880584f` validation; kept `88/88`; preserved row layout, `m_boardId`, `m_pageRequestPending`, raw helper names, no-direct-route evidence, stale-pollution rejections, and no-code rationale.
- `by-file/BoardDialogs.md`: updated the ArticleListPane proposed-content row / ownership notes / score rationale to say raw helper recovery and no-direct-route evidence are now MCP-backed. Score remains `86/87`.
- `by-class/ArticleListDialog.md`: updated the narrow producer-side pending-state note to cite MCP `insn_query` at `0x004744f5` clearing `ArticleListPane +0x14e` and `0x00474666` calling row insertion. Score remains `85/88`.
- No required edits to `by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md`, `by-type/by-vtable/BoardArticleDialogVtableFamily.md`, or `MailListPaneCore`; they already support the decision at sufficient detail.

## Open Questions With Attempted Resolution

1. What is opcode `0x3b` subcommand `7` source-facing meaning?
   - MCP confirms selected-row loop, board id, article id, subcmd `7`, length `6`.
   - No string/server/UI evidence in this pass proves the source semantic. Keep conservative `SendSelectedArticleSubcommand7Requests`.

2. Are exact child splits required before C++?
   - MCP confirms every raw helper body and no alternate owner.
   - Split is optional for review granularity, not required for ownership. For C++, choose either full aggregate C++ after declarations are synchronized or split-first C++.

3. What exact ListPane virtual names should be used?
   - MCP confirms roles but not original names. Use descriptive names in prose and synchronize with broader ListPane API work before formal code.

4. What is the final row status byte name/polarity?
   - MCP confirms paint treats nonzero as color/background `0x0e` and selected read does not clear the byte. It does not prove read/unread/type polarity. Keep neutral `statusByte`.

## Exact Supervisor-Owned Coverage Text

Do not let B001 edit `by-memory/-coverage-report.md` during this report-only pass. If the supervisor accepts this MCP redo and wants coverage text synchronized, replace the current [UID:00030I] row with:

```text
      - [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) 0x004748f0-0x004751b1 | class method cluster | ArticleListPaneCore : reconstructable : 88% : very strong : Assigned to [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) after child `88/89`, direct class parent `88/88`, and file parent `86/87`; B001 2026-06-23 MCP redo in active IDA session `b880584f` confirms modeled functions at `0x004748f0`, `0x00474990`, `0x00474da0`, `0x00474e10`, `0x00474ec0`, `0x00474f20`, `0x00474f70`, and `0x00474f90`, raw no-function helper bodies at `0x00474a70`, `0x00474b20`, `0x00474c00`, `0x00474ce0`, `0x00474d10`, `0x00474d70`, `0x00474e00`, and `0x00474e60`, zero direct code/data/immediate routes to those raw starts, exact `0xcc` boundary padding, `m_boardId` at `+0x14c`, `m_pageRequestPending` at `+0x14e`, exact `0x406` ArticleListEntry layout, opcode `0x3b` selected read/subcmd7/delete/page-request behavior, `OnArticleActivated` tail-call route to `0x004739b0`, and stale `categoryId`, `GetBulletinSession`, and generated `ChattingColorListPane` rejection; formal C++ remains blank until synchronized declarations support a full aggregate draft or optional exact helper splits.
```

No other coverage rows are recommended for this target.

## Follow-Up Actions

- Supervisor: verify this implementation claim-by-claim against the report/checklist and then apply supervisor-owned coverage text if desired.
- Implementation callback: completed. B001 leased only immediately before editing, updated target/support docs, ran scoped validators for each changed by-* doc, released leases immediately after the edit/validator batch, and checked off this report checklist with proof.
- Future source-quality work outside this assignment: synchronize `ArticleListPane`, `ArticleListEntry`, `ListPane`, packet, and draw helper declarations; then decide full aggregate C++ versus optional exact helper splits.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for keeping current `88/89`; no higher score is recommended.
- Remaining uncertainty: exact original source names, opcode `0x3b` subcmd `7` semantic label, first row status byte enum/polarity, final ListPane/render/packet helper declarations, and broader original file split between `BoardDialogs.cpp`, `ArticleDialogs.cpp`, or `BulletinDialogs.cpp`.

## Validator Results

- Implementation validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted by-* edits:
  - `python .\tools\validator.py --mode file --file by-memory\0x004748f0-0x004751b1.ArticleListPaneCore.md --apply --queue-timeout 240` -> exit `0`, file mode scanned `1`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\ArticleListPane.md --apply --queue-timeout 240` -> exit `0`, file mode completed successfully, expected `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\BoardDialogs.md --apply --queue-timeout 240` -> exit `0`, file mode completed successfully, expected `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\ArticleListDialog.md --apply --queue-timeout 240` -> exit `0`, file mode completed successfully, expected `ok: 1`.
- Validator-owned side effects observed: the first file scan reported `autogen_registry_rebuild` for `tools/validator.ini` and `projected_stats_update` for `project-level/-auto-completion-stats.md`; generated C++ and generated `-ag-*` reports were reported as `autogen_cpp_noop` / `autogen_report_noop` in the validator output for this batch.
- Coverage reports: no `-coverage-report.md` file was edited.
- MCP note preserved from the report pass: the listed `callers` tool returned `Method 'callers' not found`; caller evidence was obtained through working MCP `xrefs_to` and `analyze_batch include_callers`.

## Changed Files

- Created: none.
- Modified:
  - `by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md`
  - `by-class/ArticleListPane.md`
  - `by-file/BoardDialogs.md`
  - `by-class/ArticleListDialog.md`
  - `tools/leaser/Agents/Agent-B001/research/00030I-ArticleListPaneCore-source-quality.md`
- Validator-owned side effects reported:
  - `tools/validator.ini`
  - `project-level/-auto-completion-stats.md`
- Renamed: none.
- Moved to executed: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: supervisor accepted the MCP-backed redo and issued implementation callback `B001-implement-article-list-pane-core-source-quality-00030I-mcp-20260623`.
- [x] Target/support docs to update: updated `by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md`, `by-class/ArticleListPane.md`, `by-file/BoardDialogs.md`, and narrow MCP citation in `by-class/ArticleListDialog.md`.
- [x] Current target state and actual evidence checked recorded: target remains `88/89`; report and docs record MCP session `b880584f`, health/session facts, function map, xrefs, raw helper bytes/disassembly, decompilation, vtable slots, generated pollution checks, and negative route checks.
- [x] Metadata/score changes to apply: none recommended or applied; target stays `88/89`, `ArticleListPane` stays `88/88`, `BoardDialogs` stays `86/87`, and `ArticleListDialog` stays `85/88`.
- [x] Owner/emitter/reconstructable changes to apply: none; target owner/emitter remains [UID:00000L], reconstructable remains true, and support owner/emitter routes remain unchanged.
- [x] Split/rename/new-child changes to apply: none required or applied; optional helper splits remain future review granularity only.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: docs updated only; no IDA DB rename/type/comment edits requested or performed.
- [x] First-draft C++ or no-code proof to apply: formal C++ remains blank; target and class docs now carry MCP-backed no-partial-C++ proof.
- [x] Exact target/support doc facts to incorporate at report-level detail: incorporated MCP function map, raw helper body roles, no-direct-route checks, vtable entries/stores, parser pending-clear, row layout, field names, packet subcommands, activation route, source route, stale-name rejections, and no-code proof into target/support docs.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old offline/Capstone-only evidence caveat is explicitly superseded; generated `categoryId`, `GetBulletinSession`, `ChattingColorListPane`, shared `ListPane`, and `InsertOrReplaceEntryText` pollution remain rejected history.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated `simroot_v2` and Wave-derived names remain lead/pollution evidence only; no Wave fact is used as authority in the applied docs.
- [x] Open questions to close or document as evidence-backed unresolved: subcmd `7` semantic, exact original names, status byte polarity, final API declarations, and broader file split remain documented unresolved with score/C++ impact.
- [x] Validators to run: scoped file validators ran for all four changed by-* docs with `--apply --queue-timeout 240`; all returned exit `0`.
- [x] Supervisor-owned coverage-report/tracker text to apply: exact [UID:00030I] coverage text remains supplied above for supervisor application; B001 did not edit any `-coverage-report.md`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: accepted in the 2026-06-23 implementation callback for [UID:00030I].
- [x] All accepted target/support doc details incorporated at report-level detail: target, ArticleListPane, BoardDialogs, and narrow ArticleListDialog support note now replace/supersede MCP-unavailable/local-only wording with active MCP session `b880584f` evidence.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: no metadata, score, owner, emitter, split, rename, or formal C++ changes were accepted or applied; C++ stays blank because synchronized declarations are still required before a full aggregate or split-child draft.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: docs preserve superseded local-only evidence, no-direct-route checks, rejected `categoryId`, `GetBulletinSession`, generated `ChattingColorListPane`, shared `ListPane`, and Clan `InsertOrReplaceEntryText` pollution.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: subcmd `7`, exact original names, status byte polarity, final API declarations, and broader source-file split remain evidence-backed unresolved and score/C++ limiting.
- [x] Validators run and results recorded: four scoped validator commands ran from project-documentation; all returned exit `0`; first command reported file mode scanned `1`, `ok: 1`, with normal validator-owned registry/projected-stats side effects.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact coverage row remains above; no coverage report was edited by B001.
- [x] Remaining unapplied accepted items listed with exact blocker: none; all accepted implementation items were applied or explicitly not applicable.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00030I-ArticleListPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"00030I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
