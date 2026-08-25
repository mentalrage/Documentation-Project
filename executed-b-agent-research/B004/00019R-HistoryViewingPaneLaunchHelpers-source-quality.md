** TARGET-REPORT-UID:00019R **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00019R HistoryViewingPaneLaunchHelpers Source-Quality Report

Assignment: `B004-report-00019R-HistoryViewingPaneLaunchHelpers-source-quality-20260629`; accepted implementation callback `B004-implement-00019R-HistoryViewingPaneLaunchHelpers-20260629`
Agent: Agent-B004
Mode: accepted implementation callback completed after report-only research
Target: [UID:00019R] `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md`

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00019R] as a non-emitting split/index page, but implement source-quality cleanup on its exact child helpers and support alias docs.
- Final disposition: the aggregate itself should remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank formal C++; the source-authored code belongs to [UID:0003H6] `OpenStoryViewingPane` and [UID:0003H7] `OpenHistoryViewingPane`.
- Required action: update the target and support docs to replace stale "below 95/95/final-audit gate" wording with the current code-entry rule, add first-draft formal C++ to the two exact child memory pages, and keep by-global aliases support-only to avoid duplicate body emission.
- Confidence: high for range/body/source placement; medium-high for retained liveness because no caller/callback/pointer route to either helper entry was recovered.

## Target

- Target UID: `00019R`
- Target path: `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md`
- Source queue/report row: assigned from `auto-generated/-ag-research-tracker.md`, row still showing stale `80/86`, average `83`, `RECONSTRUCTABLE:true`, report count `0`.
- Current source page state: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP CODE`.
- Current supervisor classification: accepted implementation callback; by-* edits applied and validated.

## Current Target State

The target page is already a split/index aggregate. It covers:

| Range | Current child | Current disposition |
| --- | --- | --- |
| `0x004f90c0-0x004f913f` | [UID:0003H6] `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md` | implemented callback state `88/90`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000L0] `MainMenuPane`, first-draft `static void OpenStoryViewingPane()` C++ |
| `0x004f913f-0x004f9140` | internal padding | one `0xcc` byte |
| `0x004f9140-0x004f91bf` | [UID:0003H7] `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md` | implemented callback state `88/90`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000L0] `MainMenuPane`, first-draft `static void OpenHistoryViewingPane()` C++ |

The target page itself is correctly non-emitting because it is not a source-level function or source object. The report-only pass found stale rationale around child C++ readiness: the target and child/support pages still framed blank code as a "below final-audit/95/95" issue. The accepted callback replaced that stale rationale on the edited docs. Current `by-structure.md` allows formal C++ when the target is reconstructable, has a confirmed emitter route to generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`. Both exact child pages satisfy that minimum gate and now carry first-draft formal C++ through [UID:0000L0] `MainMenuPane`.

Related target/support docs checked:

- `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md`
- `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md`
- `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md`
- `by-global/OpenStoryViewingPane_4F90C0.md`
- `by-global/OpenHistoryViewingPane_4F9140.md`
- `by-file/MainMenuPane.md`
- `by-class/MainMenuPane.md`
- `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`
- `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`
- `by-file/HistoryViewingPane.md`
- `by-class/HistoryViewingPane.md`
- `by-resource/main-menu-history-resources.md`
- `by-resource/main-menu-story-resources.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md` and read-only generated reports for stale-state checks only.

## Supervisor Active Recheck

The active assignment required current IDA MCP evidence, exact function/range inventory, xrefs/callers, UI/class/file owner candidates, helper roles, field/global names, split/merge needs, and formal C++ or exact no-code disposition. MCP was available and used. No fallback-only evidence is used.

## IDA MCP Status

MCP endpoint `http://127.0.0.1:13337/mcp` responded to `initialize` and `tools/list`.

Current session proof:

| Check | Result |
| --- | --- |
| `idb_list` | session `992d23de`, `NexusTK.exe.i64`, active worker backend, PID/worker PID `12076`, `is_analyzing:false` |
| `server_health database=992d23de` | `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067` |

One initial `xrefs_to` attempt used stale `addr` parameters and returned a schema error requiring `addrs`; the calls were retried successfully with the active schema. One `get_bytes` attempt used `start` instead of active `addr` in region objects and was retried successfully. These were parameter mistakes, not MCP availability failures.

## Evidence Checked

IDA MCP calls used:

- `lookup_funcs` for `0x004f90c0`, `0x004f913f`, `0x004f9140`, `0x004f91bf`, `0x004f91c0`, `0x004f7a10`, `0x004ffd80`, and `0x004f4aa0`.
- `analyze_function include_asm=true` for `0x004f90c0` and `0x004f9140`.
- `analyze_function` for `0x004f7a10` and `0x004ffd80`.
- `xrefs_to addrs` for helper entries, constructor target `0x004ffd80`, story/history resource literals, and `g_pHistoryViewingPane`.
- `callees addrs` for the two child helpers.
- `find_bytes` for VA/RVA pointer byte patterns `c0 90 4f 00`, `40 91 4f 00`, `c0 90 0f 00`, and `40 91 0f 00`.
- `get_bytes` for padding at `0x004f90b4`, `0x004f913f`, `0x004f91bf`, and the UTF-16 literal cluster at `0x0061e128`.
- `int_convert` for `0x7f` = 127 and `0x108` = 264.

Old report/search gate:

- Searched active Agent folders and central executed reports for `00019R`, `0x004f90c0`, `0x004f9140`, `0x004f91bf`, `HistoryViewingPaneLaunchHelpers`, `OpenStoryViewingPane`, `OpenHistoryViewingPane`, `0003H6`, `0003H7`, and retained `MainMenuPane` launcher terms.
- No prior B-report for UID00019R was found.
- Relevant matching reports opened as leads:
  - `executed-b-agent-research/B010/00019Q-OpenChangePasswordDialog-source-quality.md`
  - `executed-b-agent-research/B003/0002Q6-OpenTransferServerDialog-source-quality.md`
  - `executed-b-agent-research/B014/0001A2-BackStoryDialogPaneCore-source-quality.md`
- The B003 and B010 reports are important precedent: retained/no-xref main-menu launch helpers can still be formal-C++ ready when the exact body, owner/emitter route, dependencies, and source-facing shape are resolved; the no-route finding remains a confidence cap.

Generated/read-only state checked before callback:

- `auto-generated/-ag-research-tracker.md` still lists UID00019R as stale `80/86`, `RECONSTRUCTABLE:true`.
- `auto-generated/-ag-coverage-report-by-memory.md` still lists UID00019R as stale `80%` reconstructable and does not show exact child rows [UID:0003H6]/[UID:0003H7].
- `auto-generated/NexusTK/login/MainMenuPane.cpp` was refreshed at validator command `000000000358` on `2026-06-29T02:19:04-04:00`; it contains first-draft [UID:0002Q6] and [UID:00019Q] bodies, but only stale empty markers for by-global [UID:0000TC]/[UID:0000TE] at `84/88` and no emitted [UID:0003H6]/[UID:0003H7] bodies.
- `by-memory/-coverage-report.md` is manual and stale for this block; it still lists UID00019R as reconstructable `80%`. It was read only.

Generated/read-only state after callback:

- `auto-generated/NexusTK/login/MainMenuPane.cpp` header now reports `validator-command-id: 000000000423`, `validator-refreshed-at: 2026-06-29T06:22:13-04:00`, and `validator-refresh-source: foreground-generated-refresh`.
- The generated file contains [UID:0003H6] `static void OpenStoryViewingPane()` at lines 134-141 and [UID:0003H7] `static void OpenHistoryViewingPane()` at lines 143-150.
- The generated file keeps by-global [UID:0000TC]/[UID:0000TE] as empty emitter markers at lines 214/216, matching the accepted support-only alias disposition.

## IDA MCP Facts

Function/range facts:

- `lookup_funcs` reports `sub_4F90C0` at `0x004f90c0`, size `0x7f` / 127 bytes (Verified with MCP `int_convert`), and `sub_4F9140` at `0x004f9140`, size `0x7f` / 127 bytes (Verified with MCP `int_convert`).
- `0x004f913f` and `0x004f91bf` are not function heads.
- Successor `sub_4F91C0` starts at `0x004f91c0`, size `0xbd`.
- `get_bytes` reconfirms `0x004f90b4-0x004f90c0` as twelve `0xcc` bytes, `0x004f913f` as one `0xcc`, and `0x004f91bf` as one `0xcc`.

Story helper facts:

- `analyze_function 0x004f90c0` decompiles to a no-argument helper with `byte_66DA97 == 1`, `sub_4F4AA0(264)`, null check, and `sub_4FFD80(result, &aSt_0)` or `sub_4FFD80(result, &aSt)`.
- Disassembly shows `cmp byte_66DA97, 1` at `0x004f90e3`, `push 108h` at `0x004f90ea`, resource pushes at `0x004f9107` and `0x004f9124`, and constructor dispatch at `0x004f912b`.
- `callees` reports only `sub_4F4AA0` and `sub_4FFD80`.
- `callers` is empty and `xrefs_to 0x004f90c0` returns `xref_count:0`.
- `find_bytes` returns zero matches for both VA pointer bytes `c0 90 4f 00` and RVA pointer bytes `c0 90 0f 00`.

History helper facts:

- `analyze_function 0x004f9140` decompiles to a no-argument helper with `byte_66DA97 == 1`, `sub_4F4AA0(264)`, null check, and `sub_4FFD80(result, L"HISTORY.EPF")` or `sub_4FFD80(result, L"HISTORY.EPD")`.
- Disassembly shows `cmp byte_66DA97, 1` at `0x004f9163`, `push 108h` at `0x004f916a`, resource pushes at `0x004f9187` and `0x004f91a4`, and constructor dispatch at `0x004f91ab`.
- `callees` reports only `sub_4F4AA0` and `sub_4FFD80`.
- `callers` is empty and `xrefs_to 0x004f9140` returns `xref_count:0`.
- `find_bytes` returns zero matches for both VA pointer bytes `40 91 4f 00` and RVA pointer bytes `40 91 0f 00`.

Constructor and active duplicate facts:

- `xrefs_to 0x004ffd80` returns six constructor call sites: active `MainMenuPane::ActivateMenuItem` calls at `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, `0x004f7c3d`, plus retained helper calls at `0x004f912b` and `0x004f91ab`.
- `analyze_function 0x004f7a10` shows selected menu item case `3` directly allocating 264 bytes and constructing `HistoryViewingPane` with `STORY.EPF` or `STORY.EPD`, and case `4` directly allocating 264 bytes and constructing with `HISTORY.EPF` or `HISTORY.EPD`.
- `analyze_function 0x004ffd80` confirms `HistoryViewingPane` constructor writes `g_pHistoryViewingPane` at `0x0069b494`, installs three vtable pointers, initializes frame/resource state, sizes the pane from screen dimensions, and returns `this`.
- `xrefs_to 0x0069b494` returns six lifecycle refs: main-menu cleanup read at `0x004f69dd`, constructor writes at `0x004ffdd6`/`0x004ffddd`, constructor-adjacent cleanup write at `0x004ffefa`, singleton clear helper `0x005023b0`, and destructor clear `0x0050278d`.

Resource literal facts:

- `xrefs_to 0x0061e128` (`STORY.EPF`) returns active menu `0x004f7b86`, retained helper `0x004f9107`, and BackStoryDialogPane refs `0x0050015d`/`0x00500230`.
- `xrefs_to 0x0061e13c` (`STORY.EPD`) returns active menu `0x004f7bbc`, retained helper `0x004f9124`, and BackStoryDialogPane refs `0x00500297`/`0x00500367`.
- `xrefs_to 0x0061e150` (`HISTORY.EPF`) returns active menu `0x004f7c00` and retained helper `0x004f9187`.
- `xrefs_to 0x0061e168` (`HISTORY.EPD`) returns active menu `0x004f7c36` and retained helper `0x004f91a4`.
- `get_bytes 0x0061e128 size 100` decodes the contiguous UTF-16 cluster as `STORY.EPF`, `STORY.EPD`, `HISTORY.EPF`, and `HISTORY.EPD`, followed by the next string data.

Tool limitation / non-proof:

- `analyze_function include_asm=true` renders EH cleanup/tail chunks outside the primary linear ranges, such as `0x006015fd` and `0x0060162e`. `lookup_funcs` still reports primary modeled sizes as `0x7f`, and no current by-memory page was found for those EH support addresses. This report treats them as compiler-generated EH cleanup support outside UID00019R's primary linear ranges, not as extra child source bodies.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f90c0-0x004f913f` | [UID:0003H6] `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md` | retained story viewer opener | TRUE | [UID:0000L0] `MainMenuPane` | `86/90` now, recommend `88/90` | formal C++ ready |
| `0x004f913f-0x004f9140` | ignored padding | one `0xcc` byte | FALSE | none | 100% ignored in support ledger | already documented |
| `0x004f9140-0x004f91bf` | [UID:0003H7] `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md` | retained history viewer opener | TRUE | [UID:0000L0] `MainMenuPane` | `86/90` now, recommend `88/90` | formal C++ ready |
| `0x004f90c0-0x004f91bf` | [UID:00019R] target aggregate | split/index only | FALSE | none | `86/90`, recommend unchanged | no C++, child-owned bodies |
| `by-global/OpenStoryViewingPane_4F90C0.md` | [UID:0000TE] | symbol/search alias | TRUE but support-only body | [UID:0000L0] | `86/90`, recommend unchanged | blank C++; body belongs to [UID:0003H6] |
| `by-global/OpenHistoryViewingPane_4F9140.md` | [UID:0000TC] | symbol/search alias | TRUE but support-only body | [UID:0000L0] | `86/90`, recommend unchanged | blank C++; body belongs to [UID:0003H7] |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f90c0` | zero xrefs/callers; zero VA/RVA pointer-byte matches | no recovered direct route to retained story helper |
| `0x004f9140` | zero xrefs/callers; zero VA/RVA pointer-byte matches | no recovered direct route to retained history helper |
| `0x004f912b` | code xref to `0x004ffd80` inside `sub_4F90C0` | retained story helper constructor call |
| `0x004f91ab` | code xref to `0x004ffd80` inside `sub_4F9140` | retained history helper constructor call |
| `0x004f7b8d`, `0x004f7bc3` | active `MainMenuPane::ActivateMenuItem` story constructor calls | active duplicate path |
| `0x004f7c07`, `0x004f7c3d` | active `MainMenuPane::ActivateMenuItem` history constructor calls | active duplicate path |
| `0x004f9107`, `0x004f9124` | story resource data refs inside retained helper | `STORY.EPF` / `STORY.EPD` |
| `0x004f9187`, `0x004f91a4` | history resource data refs inside retained helper | `HISTORY.EPF` / `HISTORY.EPD` |

## Heuristic / Inference Reanalysis And Validation

The older source-quality blocker was framed as "blank C++ because retained helper reachability and final-audit threshold remain unresolved." Current evidence supports a narrower conclusion:

- Direct reachability remains unresolved. No direct callers, code xrefs, VA pointer bytes, or RVA pointer bytes were recovered for either helper entry.
- That unresolved route is a confidence cap, not a no-code proof for the exact child pages. The two child pages are exact modeled functions with clean boundaries, known dependencies, valid owner/emitter route, and source-facing names.
- The active `MainMenuPane::ActivateMenuItem` cases duplicate each helper body inline and ignore the constructed pointer. Combined with `HistoryViewingPane` constructor singleton publication at `g_pHistoryViewingPane`, this supports a side-effect opener shape, not a returned-pointer source API.
- The target aggregate should stay non-emitting because it is only a split/index container over two exact children plus padding. Its blank C++ is justified by `RECONSTRUCTABLE:FALSE` and child-owned bodies, not by the stale 95/95 language.

Rejected alternatives:

| Alternative | Rejection reason |
| --- | --- |
| Keep exact child C++ blank solely because no caller/callback route was recovered | Rejected by B003/B010 retained-launcher precedent and current code-entry rule; no-route evidence caps confidence but does not block a source-ready exact child. |
| Emit code on UID00019R aggregate | Rejected because the aggregate is a non-source split/index page containing two exact functions plus padding. |
| Emit duplicate bodies on by-global aliases [UID:0000TE]/[UID:0000TC] | Rejected by `by-global/-guidance.md`: full free/helper function bodies belong on exact `by-memory` pages. Alias pages should preserve symbol/xref/source-placement evidence and stay blank/support-only. |
| Move helpers to `HistoryViewingPane.cpp` | Rejected because the helpers choose main-menu story/history resources and launch the viewer; `HistoryViewingPane` owns viewer behavior, fields, singleton lifecycle, and draw/input logic, not menu resource dispatch. |
| Treat helpers as non-reconstructable/dead | Rejected because they are real source-authored functions with valid behavior, constructor/resource refs, and coherent placement in the retained `MainMenuPane` launcher band. |
| Use returned-pointer source APIs | Rejected because no caller consumes a return value and the active duplicate cases ignore the constructed pointer; `HistoryViewingPane` constructor publishes singleton state. |

Open issue preserved:

- No current evidence recovers the original registration/callback route or explains why these duplicate helpers were retained. This keeps confidence below final audit and should remain documented.

## Ranked Ownership Analysis

### 1. MainMenuPane.cpp / [UID:0000L0]

Evidence for:

- Active `MainMenuPane::ActivateMenuItem` cases `3` and `4` duplicate story/history viewer construction.
- [UID:0000L0] already groups retained login/main-menu launch helpers, including implemented [UID:0002Q6] and [UID:00019Q].
- The helpers only choose main-menu story/history resources and launch a viewer; they do not implement viewer behavior.
- [UID:0000L0] is `89/86` with valid `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, so the emitter route surfaces to generated source.

Evidence against:

- No caller/callback table to the helper entries has been recovered.

Decision: accepted. The no-route evidence is a confidence cap, not an owner rejection.

### 2. HistoryViewingPane.cpp / [UID:0000JW]

Evidence for:

- Both helpers allocate and construct `HistoryViewingPane`.
- The constructor target and singleton lifecycle belong to [UID:0000JW]/[UID:000066].

Evidence against:

- Constructor target is dependency evidence, not launcher ownership.
- Resource selection is a main-menu action decision.
- Active duplicate code lives in `MainMenuPane::ActivateMenuItem`.

Decision: rejected as canonical owner for the launch helpers. Keep `HistoryViewingPane.cpp` as the viewer implementation owner.

### 3. No-owner / non-emitting

Evidence for:

- No direct route into the retained helpers has been recovered.

Evidence against:

- The exact child functions are modeled, source-authored, have coherent resource/constructor behavior, and match the retained helper pattern already accepted for adjacent main-menu launchers.

Decision: rejected for child helpers. Accepted only for the aggregate page as a non-emitting split/index container with `RECONSTRUCTABLE:FALSE`.

## Source Placement

Recommended placement:

```text
login/MainMenuPane.cpp
```

Recommended source-facing helper shapes:

- `static void OpenStoryViewingPane()`
- `static void OpenHistoryViewingPane()`

The names should omit address suffixes in emitted C++. Keep `OpenStoryViewingPane_4F90C0` and `OpenHistoryViewingPane_4F9140` only as support/search aliases on by-global pages.

## Range / Split / Padding / Reclassification Analysis

No split repair is needed. The current split is correct:

- The aggregate target [UID:00019R] is a non-emitting split/index page.
- The two exact child pages [UID:0003H6] and [UID:0003H7] carry the source-authored reconstructable functions.
- The internal byte `0x004f913f` and successor byte `0x004f91bf` are alignment padding, already represented in `by-memory/-ignored.md`.
- The preceding `0x004f90b4-0x004f90c0` twelve-byte padding row is already represented in `by-memory/-ignored.md`.

Recommended reclassification:

- Keep UID00019R `RECONSTRUCTABLE:FALSE`.
- Keep child UIDs `0003H6` and `0003H7` `RECONSTRUCTABLE:TRUE`.
- Do not merge the child helpers back into UID00019R.

## First-Draft C++ Recommendation

Eligible for draft C++:

- [UID:0003H6] `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md`
- [UID:0003H7] `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md`

Not eligible / no-code:

- [UID:00019R] target aggregate: exact no-code proof is `RECONSTRUCTABLE:FALSE` split/index page; code belongs to exact children.
- [UID:0000TE]/[UID:0000TC] by-global aliases: support-only symbol pages; do not duplicate the child bodies.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0003H6]:

```cpp
static void OpenStoryViewingPane()
{
    if (g_useEpfAssets == 1)
        new HistoryViewingPane(L"STORY.EPF");
    else
        new HistoryViewingPane(L"STORY.EPD");
}
```

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0003H7]:

```cpp
static void OpenHistoryViewingPane()
{
    if (g_useEpfAssets == 1)
        new HistoryViewingPane(L"HISTORY.EPF");
    else
        new HistoryViewingPane(L"HISTORY.EPD");
}
```

Why this preserves original behavior:

- The binary compares `byte_66DA97` with `1`, so the draft preserves the exact `== 1` branch semantics instead of using a looser nonzero test.
- The binary allocates 264 bytes and calls the `HistoryViewingPane` constructor with the selected UTF-16 resource string; project source shape already models similar allocation wrappers as `new Type(...)`.
- The source-facing return type is `void` because there is no inbound caller, no returned-pointer consumer, and the active duplicate menu cases ignore the constructed pointer. `HistoryViewingPane` constructor publishes singleton state through `g_pHistoryViewingPane`, making construction side effect the meaningful source result.
- The exact no-route evidence is preserved as a confidence cap.

Rejected C++ alternatives:

- `static HistoryViewingPane *OpenStoryViewingPane()` and `static HistoryViewingPane *OpenHistoryViewingPane()`: rejected because no current caller or active duplicate path consumes a pointer return.
- Ternary-argument single `new` expression: rejected as less faithful to the two-branch allocation/constructor shape produced by the binary.
- `if (g_useEpfAssets)`: rejected because the binary compares the byte to literal `1`.
- Leaving child formal C++ blank: rejected under the current code-entry rule.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| HVP-001 | UID00019R remains a non-emitting split/index page at exact source `86/90`, `RECONSTRUCTABLE:FALSE`; current MCP refresh and stale child-C++ rationale cleanup do not justify target score or metadata movement, and generated tracker/coverage rows are stale. | High | target header; generated tracker row; generated by-memory coverage row; score-blocker audit in this report | target Status/Autogen/Score; generated notes in report/checklist | incorporate | applied: target doc keeps `86/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/C++; validator `000000000412` exit 0, `ok:1`, `generated_refresh:deferred`, refreshed registry false state. |
| HVP-002 | Current MCP session `992d23de` is healthy and was used for this report. | High | `idb_list`, `server_health` | target/support evidence notes | incorporate | applied: target, child, by-global, MainMenuPane file/class, and aggregate support docs cite B004 MCP session `992d23de`; validators `000000000410`-`000000000414`, `000000000417`, `000000000419`, and `000000000421` passed. |
| HVP-003 | `0x004f90c0` and `0x004f9140` are exact `0x7f`/127-byte functions; `0x004f913f` and `0x004f91bf` are non-function padding boundaries; successor `0x004f91c0` is `sub_4F91C0`. | High | `lookup_funcs`, `int_convert`, `get_bytes` | target Covered Range/IDA MCP Evidence; child pages | incorporate | applied: target and both child pages record exact `0x7f`/127-byte children, padding bytes, and successor context; validators `000000000410`, `000000000411`, and `000000000412` passed. |
| HVP-004 | `0x004f90c0` allocates 264 bytes and constructs `HistoryViewingPane` with `STORY.EPF` or `STORY.EPD` selected by `g_useEpfAssets == 1`. | High | `analyze_function`, disassembly, resource xrefs | [UID:0003H6] Behavior/IDA Evidence; by-global alias | incorporate | applied: [UID:0003H6] and [UID:0000TE] now record the `0x108`/264-byte allocation, `g_useEpfAssets == 1`, and `STORY.EPF`/`STORY.EPD`; validators `000000000410` and `000000000413` passed. |
| HVP-005 | `0x004f9140` allocates 264 bytes and constructs `HistoryViewingPane` with `HISTORY.EPF` or `HISTORY.EPD` selected by `g_useEpfAssets == 1`. | High | `analyze_function`, disassembly, resource xrefs | [UID:0003H7] Behavior/IDA Evidence; by-global alias | incorporate | applied: [UID:0003H7] and [UID:0000TC] now record the `0x108`/264-byte allocation, `g_useEpfAssets == 1`, and `HISTORY.EPF`/`HISTORY.EPD`; validators `000000000411` and `000000000414` passed. |
| HVP-006 | Both helpers currently have zero direct entry xrefs/callers and zero VA/RVA pointer-byte matches. | High | `xrefs_to`, `analyze_function callers`, `find_bytes` | target/child/source-shape caveats | incorporate | applied: target, children, by-global aliases, MainMenuPane support docs, and aggregate support doc record the no-xref/no-pointer route as a confidence cap; all scoped validators passed. |
| HVP-007 | `MainMenuPane::ActivateMenuItem` cases 3 and 4 duplicate the same story/history construction paths inline. | High | `analyze_function 0x004f7a10` | child pages; MainMenuPane support docs; aggregate support doc | incorporate | applied: child pages, `by-file/MainMenuPane.md`, `by-class/MainMenuPane.md`, and `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` now cite active cases `3`/`4`; validators `000000000410`, `000000000411`, `000000000417`, `000000000419`, and `000000000421` passed. |
| HVP-008 | `HistoryViewingPane` constructor has six call sites: four active menu calls plus two retained helper calls. | High | `xrefs_to 0x004ffd80`; `analyze_function 0x004ffd80` | HistoryViewingPane docs as already present; child evidence | already-present | already-present: `by-file/HistoryViewingPane.md` change note already records six constructor xrefs and retained launcher resource xrefs; `by-class/HistoryViewingPane.md` already lists the wrapper call sites and direct active menu branch. No edit required. |
| HVP-009 | `HistoryViewingPane` constructor publishes `g_pHistoryViewingPane`, supporting side-effect opener source shape. | High | `analyze_function 0x004ffd80`; `xrefs_to 0x0069b494` | child C++ rationale; HistoryViewingPane support docs | incorporate | applied: both child pages document constructor singleton publication as the reason for `static void` opener shape; HistoryViewingPane docs already retained lifecycle/singleton facts. Validators `000000000410` and `000000000411` passed. |
| HVP-010 | `STORY.EPF`, `STORY.EPD`, `HISTORY.EPF`, and `HISTORY.EPD` literal identities and xrefs are current and match existing resource docs. | High | `get_bytes 0x0061e128`; `xrefs_to` resource literals; resource docs | child/resource evidence; resource pages already present | already-present | already-present: `by-resource/main-menu-history-resources.md` already lists all four literals, active menu and retained-helper refs, literal cluster decoding, and DAT/package notes; no accepted contradiction found, so no edit required. |
| HVP-011 | Child pages [UID:0003H6]/[UID:0003H7] are above the current formal C++ gate and should no longer cite stale 95/95/final-audit gate language as a blank-C++ blocker. | High | child headers `86/90`, emitter `0000L0`, current `by-structure.md` rule | child C++ status; target source-shape note; MainMenuPane support docs | incorporate | applied: child pages are now exact `88/90` with formal C++; target/alias/support docs explain no-route as confidence cap, not stale no-code gate. Validators `000000000410`-`000000000414`, `000000000417`, `000000000419`, and `000000000421` passed. |
| HVP-012 | [UID:0003H6] should receive formal first-draft `static void OpenStoryViewingPane()` C++ exactly as provided in this report. | High | HVP-004/HVP-006/HVP-007/HVP-009 | [UID:0003H6] formal C++ block | incorporate | applied: [UID:0003H6] formal block inserted and validated by `000000000410` (`--wait-generated`, exit 0, `ok:1`, `generated_refresh:completed`); generated `MainMenuPane.cpp` lines 134-141 contain the body. |
| HVP-013 | [UID:0003H7] should receive formal first-draft `static void OpenHistoryViewingPane()` C++ exactly as provided in this report. | High | HVP-005/HVP-006/HVP-007/HVP-009 | [UID:0003H7] formal C++ block | incorporate | applied: [UID:0003H7] formal block inserted and validated by `000000000411` (`--wait-generated`, exit 0, `ok:1`, `generated_refresh:completed`); generated `MainMenuPane.cpp` lines 143-150 contain the body. |
| HVP-014 | By-global aliases [UID:0000TE]/[UID:0000TC] should remain support/search aliases at exact `86/90` with blank formal C++; exact child pages own the function bodies. | High | `by-global/-guidance.md`; B010 alias precedent; current docs | by-global Autogen/C++ Status/Source-Shape sections | incorporate | applied: by-global alias pages keep exact `86/90` and blank C++; they now state exact child pages own bodies. Validators `000000000413` and `000000000414` passed, and generated lines 214/216 keep empty emitter markers. |
| HVP-015 | `MainMenuPane.cpp` remains the correct source placement; `HistoryViewingPane.cpp` is rejected for helper ownership. | High | active duplicate cases; MainMenuPane docs; HistoryViewingPane docs | target/child/source placement; MainMenuPane support docs | incorporate | applied: target/children and MainMenuPane file/class docs preserve `MainMenuPane.cpp` source placement; HistoryViewingPane ownership remains viewer behavior only. Validators `000000000410`, `000000000411`, `000000000417`, and `000000000419` passed. |
| HVP-016 | Padding rows around and between the helpers are already represented in `by-memory/-ignored.md`; no split repair is needed. | High | `get_bytes`; `by-memory/-ignored.md` | target Range/Split section; ignored ledger already present | already-present | already-present: `by-memory/-ignored.md` lines 904/908 already cover `0x004f913f-0x004f9140`, `0x004f91bf-0x004f91c0`, and neighboring retained-helper padding with UID00019R ownership links; no edit required. |
| HVP-017 | Manual `by-memory/-coverage-report.md` and validator-owned generated reports are stale for UID00019R/child state; replacement text must keep UID00019R at exact `86%` ignored/non-emitting target coverage while child rows carry exact `88%`; B004 must not edit those files. | High | read-only `Select-String` checks; workflow rules; manual coverage text in this report | report generated/tracker notes; implementation checklist | not-applicable | excluded-with-reason: manual coverage and generated reports are prohibited edit targets. This report preserves exact supervisor-owned manual text; validators refreshed generated source through normal tooling, with current read-only `MainMenuPane.cpp` header at command `000000000423`. |
| HVP-018 | No previous UID00019R report was found; executed B003/B010 reports are precedent for retained-launcher C++ readiness; B014 confirms BackStory is not the active story path. | Medium-high | `rg` old-report search and opened reports | report Evidence Checked; support notes only if useful | incorporate | applied: report evidence retains the prior-report search and B003/B010/B014 precedent; child/source-shape and MainMenuPane support docs preserve retained-launcher precedent without moving ownership to BackStory/HistoryViewingPane. |
| HVP-019 | IDA DB rename/type/comment edits are not requested. | High | assignment restriction; no need for DB mutation | report IDA recommendations | not-applicable | excluded-with-reason: no IDA DB writes were made, matching assignment restrictions and the report's IDA recommendations. |
| HVP-020 | Remaining unresolved item is original retention/registration route; this caps confidence for the aggregate at exact `90` and does not block child C++ because the children have exact bodies, owner/emitter route, and side-effect opener shape. | High | no-xref/no-pointer facts; retained-launcher precedent; target split/index status | target/child Score Rationale/Open Questions | incorporate | applied: target and child score/source-shape sections preserve unresolved retention route as confidence cap; UID00019R remains exact `86/90`, children are `88/90` with C++. Validators `000000000410`-`000000000414`, `000000000417`, `000000000419`, and `000000000421` passed. |

## Positive Evidence Summary

- Current MCP confirms the exact split and function bodies with no reliance on stale generated output.
- Both child helpers are simple, self-contained allocation-and-construction wrappers with known resource strings, known global mode byte, and known constructor target.
- Active `MainMenuPane::ActivateMenuItem` duplicates both wrappers, proving the source-family and main-menu action context.
- Adjacent B003/B010 retained-helper reports establish a project precedent: no direct helper route remains a confidence cap, not a formal-C++ blocker, when exact body/source shape and emitter route are strong.
- Existing [UID:0000L0] `MainMenuPane` is a valid generated source root and already owns neighboring retained helpers.

## Negative Evidence Summary

- No direct caller, xref, callback table, VA pointer, or RVA pointer route to either helper start was recovered.
- No evidence supports moving the helpers into `HistoryViewingPane.cpp`.
- No evidence supports duplicate by-global body emission.
- No evidence supports a pointer-returning public source API; active duplicate paths and singleton publication support side-effect openers.
- Generated reports are stale and cannot be used as authority for current source page state.

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target UID00019R already records split/index status, exact child pages, padding, decoded strings, constructor xrefs, no-entry-xref checks, and duplicate active cases.
- [UID:0003H6]/[UID:0003H7] already record exact child behavior and owner/emitter [UID:0000L0].
- [UID:0000L0] `MainMenuPane` already lists the retained story/history helpers as MainMenu-owned launcher helpers.
- `HistoryViewingPane` class/file docs already separate viewer implementation ownership from main-menu resource selection.
- Resource docs already separate `STORY.*`/`HISTORY.*` viewer resources from BackStory/NewHistory dialog resource roles.
- `by-memory/-ignored.md` already covers the padding spans.

Report-only pass found these stale or incomplete docs; the accepted callback resolved them as follows:

- UID00019R and child/by-global pages had stale "below 95/95" or "final-audit threshold" rationale for blank C++; callback edits replaced that rationale with split/index no-code proof for the aggregate, current-gate first-draft C++ for the exact children, and support-only blank-C++ rationale for aliases.
- [UID:0003H6]/[UID:0003H7] had blank `Item Summary` fields and blank formal C++; callback edits added nonblank summaries, exact `88/90` scores, and formal C++.
- [UID:0000TE]/[UID:0000TC] needed explicit support/search alias language; callback edits now state exact by-memory children own body emission.
- [UID:00019I], [UID:0000L0], and [UID:00007O] needed retained helper inventory updates; callback edits now describe source-ready child C++ with no-route confidence caps.
- Generated tracker/coverage state remains validator/supervisor-owned; B004 did not edit generated reports or manual coverage. Current generated `MainMenuPane.cpp` read-only header shows validator metadata `000000000423`.

Wave2/Wave3 status:

- No current Wave2/Wave3 source data was used as authority. Any generated/simroot-style names were treated as leads only. Current IDA MCP, current by-* docs, and executed reports were used for proof.

## Recommended Target Doc Changes

Target path: `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md`

Recommended metadata:

- Keep `COMPLETION:86`, `CONFIDENCE:90` exactly.
- Keep `CANONICAL_OWNER:NONE`.
- Keep `RECONSTRUCTABLE:FALSE`.
- Keep `EMITTER_UIDS:` blank.
- Keep aggregate formal C++ blank.

Exact facts to incorporate:

- Add current MCP session `992d23de` evidence for function inventory, no-entry-xref state, pointer-byte negative checks, resource xrefs, constructor xrefs, and padding bytes.
- Replace stale child-C++ rationale with: the aggregate stays blank because it is `RECONSTRUCTABLE:FALSE` split/index; exact child pages [UID:0003H6]/[UID:0003H7] own the source-authored bodies and are now first-draft C++ ready under the current gate.
- Preserve no-route/retention uncertainty as a confidence cap already represented by exact `CONFIDENCE:90`.
- Record the score-blocker audit conclusion: the current MCP refresh reconfirms, but does not change, the aggregate split/index facts; stale child-C++ rationale cleanup belongs to the child pages and does not add new target-owned source behavior.
- Preserve rejected `HistoryViewingPane.cpp` ownership and no-owner/non-emitting alternatives for the child helpers.

## Recommended Support Doc Changes

`by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md`:

- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged [UID:0000L0], `RECONSTRUCTABLE:TRUE`.
- Add nonblank `Item Summary` covering exact `0x7f` body, `g_useEpfAssets == 1`, 264-byte allocation, `STORY.EPF`/`STORY.EPD`, `HistoryViewingPane` constructor call, zero entry xrefs/pointer hits, active duplicate case `3`, and first-draft formal C++.
- Insert the formal C++ block from this report.
- Replace stale 95/95/final-audit no-code wording with current-gate source readiness plus no-route confidence cap.
- Preserve EH tail-chunk caveat only as compiler-generated support outside the primary linear range if added.

`by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md`:

- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged [UID:0000L0], `RECONSTRUCTABLE:TRUE`.
- Add nonblank `Item Summary` covering exact `0x7f` body, `g_useEpfAssets == 1`, 264-byte allocation, `HISTORY.EPF`/`HISTORY.EPD`, `HistoryViewingPane` constructor call, zero entry xrefs/pointer hits, active duplicate case `4`, and first-draft formal C++.
- Insert the formal C++ block from this report.
- Replace stale 95/95/final-audit no-code wording with current-gate source readiness plus no-route confidence cap.

`by-global/OpenStoryViewingPane_4F90C0.md` and `by-global/OpenHistoryViewingPane_4F9140.md`:

- Update status/source-shape language to match B010 alias precedent: these are address-suffixed support/search alias pages; exact by-memory children own the emitted bodies.
- Keep score exact `86/90`; record the current MCP refresh and support-only C++ disposition without alias score movement.
- Keep formal C++ blank on the alias pages. Do not duplicate child bodies.
- Preserve owner/emitter [UID:0000L0] and current alias empty-marker routing; alias emitter-policy changes are out of scope for this report.

`by-file/MainMenuPane.md` and `by-class/MainMenuPane.md`:

- Update retained helper inventory rows for `OpenStoryViewingPane` and `OpenHistoryViewingPane` from "currently not emitted standalone" to first-draft/source-ready exact children under [UID:0003H6]/[UID:0003H7].
- Add current MCP session `992d23de` evidence summary: exact `0x7f` bodies, no direct xrefs, zero VA/RVA pointer-byte routes, matching active cases `3`/`4`, and `HistoryViewingPane` constructor/singleton side-effect rationale.
- Preserve no-route confidence cap and `HistoryViewingPane.cpp` rejection.
- No file/class score change required.

`by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`:

- Update the UID00019R row/evidence to say the aggregate remains non-emitting while exact children [UID:0003H6]/[UID:0003H7] are source-ready with first-draft C++.
- No aggregate score/metadata change required.

`by-memory/-ignored.md`:

- Already contains the relevant padding. No required edit for this callback.

`by-file/HistoryViewingPane.md`, `by-class/HistoryViewingPane.md`, and resource docs:

- No required edit. They already contain the relevant constructor/resource facts and correct ownership split. If edited for synchronization, keep it limited to "the retained MainMenuPane child helpers now own first-draft opener C++; HistoryViewingPane still owns viewer behavior."

## Score And Metadata Recommendation

Target UID00019R:

- Recommended metadata: keep `86/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- Score movement recommendation: none. The target is a split/index container, so its score does not move when child pages receive formal C++ or when stale child-C++ rationale is corrected.

Exact child pages:

- Recommend [UID:0003H6] `86/90 -> 88/90`, owner/emitter unchanged [UID:0000L0], formal C++ populated.
- Recommend [UID:0003H7] `86/90 -> 88/90`, owner/emitter unchanged [UID:0000L0], formal C++ populated.

By-global aliases:

- Recommend support-only blank-C++ update with exact score unchanged at `86/90`. Do not duplicate the C++ body.

Score blocker audit:

- Retained route/callback proof remains unresolved, but every current route was checked: direct xrefs, modeled callers, VA pointer bytes, RVA pointer bytes, active duplicate paths, constructor xrefs, resource xrefs, owner docs, and adjacent retained-helper precedent.
- For UID00019R, the unresolved route is a confidence cap, not an implementation blocker: the aggregate remains `RECONSTRUCTABLE:FALSE`, has no target-owned body to emit, and has no new owner/emitter/source-placement fact beyond the child split already documented. That keeps the exact target score at `86/90`.
- For [UID:0003H6]/[UID:0003H7], the unresolved route is not a same-pass blocker for first-draft child C++ because the exact child bodies have valid owner/emitter route and the source-facing side-effect opener shape is supported by the active duplicate cases and singleton publication.
- The current MCP refresh improved freshness only. It reconfirmed exact function sizes, padding, strings, constructor xrefs, no-entry-xrefs, and no pointer-byte route; it did not recover a target route, merge/split correction, target-owned source body, or metadata fact that would justify UID00019R score movement.
- Removing stale 95/95/final-audit child-C++ rationale is a standards cleanup for the child pages. It does not raise the aggregate target because UID00019R's no-code proof is still the split/index disposition and child-owned emission.
- Further work that could improve confidence would require recovering a callback/registration route not present in current direct xref/pointer evidence.

## Open Questions With Attempted Resolution

Open question: why were the story/history wrappers retained when active menu cases inline the same behavior?

- Evidence checked: xrefs to both helper entries, modeled callers, VA/RVA pointer byte searches, active duplicate menu cases, adjacent retained-helper reports.
- Resolution: no route recovered. Treat the helpers as retained duplicate `MainMenuPane.cpp` launchers with confidence capped below final audit.
- Score/C++ impact: caps UID00019R confidence at exact `90`; does not block first-draft C++ for exact children.

Open question: should emitted functions return `HistoryViewingPane *`?

- Evidence checked: active duplicate cases ignore constructor result; no helper caller/callback route consumes return; constructor publishes singleton.
- Resolution: use `static void` side-effect openers.
- Score/C++ impact: resolves code-shape blocker.

Open question: should by-global aliases emit bodies?

- Evidence checked: `by-global/-guidance.md`, by-memory child pages, B010 alias precedent, generated empty marker state.
- Resolution: no duplicate body; exact by-memory pages own the source body.
- Score/C++ impact: support routing cleanup only.

## IDA Rename / Type / Comment Recommendations

No IDA DB rename, type, or comment edit is requested. Source-facing names can be documented in by-* pages without writing to IDA:

- `OpenStoryViewingPane`
- `OpenHistoryViewingPane`
- `g_useEpfAssets`

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B004 must not edit manual `-coverage-report.md` or generated reports. Normal validator/executed-report lifecycle should refresh validator-owned reports after accepted implementation.

For supervisor-owned manual `by-memory/-coverage-report.md` maintenance, use this exact UID00019R row with child rows:

```text
    - [UID:00019R][0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md) 0x004f90c0-0x004f91bf | split index | HistoryViewingPaneLaunchHelpers : ignored : 86% : very strong : Non-emitting split/index over the exact story/history retained launch helpers and internal padding; current MCP session 992d23de reconfirms exact child functions, padding, resource xrefs, constructor xrefs, no helper-entry xrefs, zero VA/RVA pointer-byte routes, and duplicate active MainMenuPane cases. Exact child pages carry the reconstructable source bodies.
        - [UID:0003H6][0x004f90c0-0x004f913f.OpenStoryViewingPane](by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md) 0x004f90c0-0x004f913f | retained launcher | OpenStoryViewingPane : reconstructable : 88% : very strong : Source-ready MainMenuPane retained story opener; allocates 264 bytes and constructs HistoryViewingPane with STORY.EPF or STORY.EPD selected by g_useEpfAssets == 1; current MCP confirms zero helper-entry xrefs and zero VA/RVA pointer hits, while active ActivateMenuItem case 3 duplicates the behavior. Formal first-draft C++ emits static void OpenStoryViewingPane().
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f913f-0x004f9140 | padding | OpenStoryViewingPane to OpenHistoryViewingPane alignment : ignored : 100% : strong : Current MCP/raw-byte check shows one 0xcc byte between the two helpers.
        - [UID:0003H7][0x004f9140-0x004f91bf.OpenHistoryViewingPane](by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md) 0x004f9140-0x004f91bf | retained launcher | OpenHistoryViewingPane : reconstructable : 88% : very strong : Source-ready MainMenuPane retained history opener; allocates 264 bytes and constructs HistoryViewingPane with HISTORY.EPF or HISTORY.EPD selected by g_useEpfAssets == 1; current MCP confirms zero helper-entry xrefs and zero VA/RVA pointer hits, while active ActivateMenuItem case 4 duplicates the behavior. Formal first-draft C++ emits static void OpenHistoryViewingPane().
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f91bf-0x004f91c0 | padding | OpenHistoryViewingPane to OpenTerminalPane alignment : ignored : 100% : strong : Current MCP/raw-byte check shows one 0xcc byte before sub_4F91C0.
```

Do not write row text for validator-owned `auto-generated/-ag-*` reports.

## Validator Results

Implementation validators were run after accepted supervisor callback. All edited by-* files passed scoped validation.

| File | Command | Exit | `command_id` | `command_timestamp` | `ok` | Generated refresh | Warnings / side effects |
| --- | --- | ---: | --- | --- | ---: | --- | --- |
| `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md` | `python .\tools\validator.py --mode file --file by-memory\0x004f90c0-0x004f913f.OpenStoryViewingPane.md --apply --queue-timeout 240 --wait-generated` | 0 | `000000000410` | `2026-06-29T03:14:10-04:00` | 1 | `completed`, refresh id `000000000410`, timestamp `2026-06-29T03:14:10-04:00` | Validator-owned `autogen_cpp_update:1`, `memory_auto_coverage_update:1`, `research_tracker_update:1`, `projected_stats_update:1`, `autogen_backup_create:3`, registry rebuild/update; unrelated existing stale registry/missing-file warnings. |
| `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md` | `python .\tools\validator.py --mode file --file by-memory\0x004f9140-0x004f91bf.OpenHistoryViewingPane.md --apply --queue-timeout 240 --wait-generated` | 0 | `000000000411` | `2026-06-29T03:14:27-04:00` | 1 | `completed`, refresh id `000000000411`, timestamp `2026-06-29T03:14:27-04:00` | Validator-owned `autogen_cpp_update:1`, memory coverage/tracker/stats refresh, backup, registry update; unrelated existing stale registry/missing-file warnings. |
| `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md` | `python .\tools\validator.py --mode file --file by-memory\0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md --apply --queue-timeout 240` | 0 | `000000000412` | `2026-06-29T03:14:42-04:00` | 1 | `deferred`, refresh id `000000000412`, timestamp `2026-06-29T03:14:42-04:00` | `autogen_registry_update` for UID00019R `true -> false`, completion/confidence/owner updates, projected stats update. |
| `by-global/OpenStoryViewingPane_4F90C0.md` | `python .\tools\validator.py --mode file --file by-global\OpenStoryViewingPane_4F90C0.md --apply --queue-timeout 240` | 0 | `000000000413` | `2026-06-29T03:14:50-04:00` | 1 | `deferred`, refresh id `000000000413`, timestamp `2026-06-29T03:14:50-04:00` | `uid_link_insert 0003H6`, registry/reference updates, projected stats update. |
| `by-global/OpenHistoryViewingPane_4F9140.md` | `python .\tools\validator.py --mode file --file by-global\OpenHistoryViewingPane_4F9140.md --apply --queue-timeout 240` | 0 | `000000000414` | `2026-06-29T03:14:58-04:00` | 1 | `deferred`, refresh id `000000000414`, timestamp `2026-06-29T03:14:58-04:00` | `uid_link_insert 0003H7`, registry/reference updates, projected stats update. |
| `by-file/MainMenuPane.md` | `python .\tools\validator.py --mode file --file by-file\MainMenuPane.md --apply --queue-timeout 240` | 0 | `000000000417` | `2026-06-29T06:21:36-04:00` | 1 | `deferred`, refresh id `000000000417`, timestamp `2026-06-29T06:21:36-04:00` | `reference_index_add` for `00019R`, `0003H6`, `0003H7`; projected stats update; one stats incremental noop for generated stats list absence. |
| `by-class/MainMenuPane.md` | `python .\tools\validator.py --mode file --file by-class\MainMenuPane.md --apply --queue-timeout 240` | 0 | `000000000419` | `2026-06-29T06:21:41-04:00` | 1 | `deferred`, refresh id `000000000419`, timestamp `2026-06-29T06:21:41-04:00` | Existing `missing_ref_uid 00036Y` warnings repeated 5 times; B004 reference index adds for `0000TC`, `0000TE`, `00019R`, `0003H6`, `0003H7`; projected stats update. |
| `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` | `python .\tools\validator.py --mode file --file by-memory\0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md --apply --queue-timeout 240` | 0 | `000000000421` | `2026-06-29T06:21:57-04:00` | 1 | `deferred`, refresh id `000000000421`, timestamp `2026-06-29T06:21:57-04:00` | Existing `missing_ref_uid 00036Y` warnings repeated 5 times; B004 reference index adds for `0000TC`, `0000TE`, `0003H6`, `0003H7`; projected stats update. |

Read-only generated freshness proof:

- `auto-generated/NexusTK/login/MainMenuPane.cpp` now has header `validator-command-id: 000000000423`, `validator-refreshed-at: 2026-06-29T06:22:13-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- Lines 134-141 contain [UID:0003H6] `static void OpenStoryViewingPane()` with `g_useEpfAssets == 1`, `STORY.EPF`, and `STORY.EPD`.
- Lines 143-150 contain [UID:0003H7] `static void OpenHistoryViewingPane()` with `g_useEpfAssets == 1`, `HISTORY.EPF`, and `HISTORY.EPD`.
- Lines 214/216 keep [UID:0000TC]/[UID:0000TE] as empty emitter markers, proving the aliases stayed support-only.
- B004 did not manually edit generated files, generated reports, project-level generated files, manual coverage, validator/tool state, lock files, executed reports, or IDA DB.

## Changed Files

Manually modified by B004 during accepted implementation:

- `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md`
- `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md`
- `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md`
- `by-global/OpenStoryViewingPane_4F90C0.md`
- `by-global/OpenHistoryViewingPane_4F9140.md`
- `by-file/MainMenuPane.md`
- `by-class/MainMenuPane.md`
- `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`
- `tools/leaser/Agents/Agent-B004/research/00019R-HistoryViewingPaneLaunchHelpers-source-quality.md`

Verified already-present and not edited:

- `by-memory/-ignored.md`
- `by-file/HistoryViewingPane.md`
- `by-class/HistoryViewingPane.md`
- `by-resource/main-menu-history-resources.md`
- `by-resource/main-menu-story-resources.md`

Validator-owned side effects:

- Validators refreshed generated/source registry, projected stats, generated `MainMenuPane.cpp`, research tracker/coverage outputs, and reference indexes as reported above. These were not manually edited by B004.

Leases:

- Batch 1 leased and released immediately after validation: target, two exact child memory pages, and two by-global alias pages.
- Batch 2 leased and released immediately after validation: `by-file/MainMenuPane.md`, `by-class/MainMenuPane.md`, and `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`.
- Read-only lease report after release showed no active B004 leases; unrelated B007 MIDI leases were present.

Report execution:

- Not run. Supervisor owns `execute_report` after report validation and implementation verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: report accepted and converted to implementation callback by supervisor.
- [x] Target/support docs to update: all listed editable by-* docs updated; `by-memory/-ignored.md`, `by-file/HistoryViewingPane.md`, `by-class/HistoryViewingPane.md`, and story/history resource pages verified already sufficient and not edited.
- [x] Current target state and actual evidence checked recorded: current MCP session `992d23de`, target source `86/90` false/non-emitting, stale generated tracker row, exact child function inventory, xrefs, bytes, resource literals, and generated state are preserved above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: HVP-001 through HVP-020 are now `applied`, `already-present`, or `excluded-with-reason`; no `blocked` row remains.
- [x] Metadata/score changes applied: UID00019R kept exact `86/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++; [UID:0003H6]/[UID:0003H7] raised to exact `88/90`; [UID:0000TE]/[UID:0000TC] kept exact `86/90`.
- [x] Owner/emitter/reconstructable changes applied: UID00019R remains `NONE`/false/blank emitters; child owner/emitter remains [UID:0000L0] and `RECONSTRUCTABLE:TRUE`; by-global aliases remain support-only with blank body and no duplicate emitted C++.
- [x] Split/rename/new-child changes confirmed: no split/rename/new child needed; current child pages [UID:0003H6]/[UID:0003H7] preserved.
- [x] Source-placement/range/padding changes applied or confirmed not applicable: target/children record padding proof; `by-memory/-ignored.md` already covers relevant padding rows.
- [x] First-draft C++ or no-code proof applied: [UID:0003H6] and [UID:0003H7] have exact formal `static void` C++; UID00019R stays blank because non-emitting split/index; by-global aliases stay blank/support-only.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: current MCP session proof, function sizes, branch/global/resource facts, constructor xrefs, no-entry-xref/no-pointer negatives, active duplicate cases, source-placement decisions, alias/body split, stale generated state, and score rationale are present in edited docs and this report.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: stale 95/95/final-audit gate wording removed from current rationale, no-route confidence cap preserved, and rejected HistoryViewingPane ownership, duplicate alias body, pointer-return API, no-owner/non-emitting child disposition, and generated-output authority preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated/simroot names were treated as leads only; no Wave2/Wave3 source was used as authority.
- [x] Open questions closed or documented as unresolved: original retained/callback route remains unresolved after xref/caller/VA/RVA pointer checks; score/C++ impact documented as confidence cap only.
- [x] Validators run: scoped file validators ran for every edited by-* file; child memory pages used `--wait-generated`; command details are recorded in `Validator Results`.
- [x] Generated refresh and manual supervisor-owned coverage/tracker text handled: current read-only generated `MainMenuPane.cpp` header is validator command `000000000423`; exact manual by-memory coverage text remains in this report for supervisor-owned maintenance and was not manually applied by B004.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] Leases taken only for immediate edited by-* files and released immediately after each edit/validator batch; final lease report had no active B004 leases.
- [x] UID00019R target doc updated at report-level detail and validated by command `000000000412`.
- [x] [UID:0003H6] child doc updated with current evidence, `88/90`, `Item Summary`, and formal C++; validated by command `000000000410`.
- [x] [UID:0003H7] child doc updated with current evidence, `88/90`, `Item Summary`, and formal C++; validated by command `000000000411`.
- [x] By-global alias pages updated with support-only blank-C++ disposition and current evidence; no duplicate body emitted; validated by commands `000000000413` and `000000000414`.
- [x] MainMenuPane file/class and mixed aggregate support docs synchronized with child C++ readiness and no-route confidence cap; validated by commands `000000000417`, `000000000419`, and `000000000421`.
- [x] Claim And Incorporation Ledger verification state updated to `applied`, `already-present`, or `excluded-with-reason` for HVP-001 through HVP-020; no `blocked` accepted claim remains.
- [x] Scoped validators run and results recorded with command, `command_id`, `command_timestamp`, exit code, `ok` count, warnings, generated-refresh state, and side effects.
- [x] Generated `MainMenuPane.cpp` freshness checked against validator command metadata and verified to contain UID0003H6/UID0003H7 bodies.
- [x] No generated reports, generated C++ files, project-level generated files, manual coverage reports, validator state, lock files, executed reports, or IDA DB manually edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00019R-HistoryViewingPaneLaunchHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00019R-HistoryViewingPaneLaunchHelpers-source-quality.md","timestamp":"2026-06-29T06:28:57","uid":"00019R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
