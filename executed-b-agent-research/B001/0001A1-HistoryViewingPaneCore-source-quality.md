** TARGET-REPORT-UID:0001A1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B001 B-report: [UID:0001A1] HistoryViewingPaneCore source-quality

Target: `source-3/project-documentation/by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md`

Implementation callback status: accepted Gate 1 report details have been applied to the approved target/support by-* docs, scoped validators passed, generated freshness was checked read-only, and no `execute_report` or lifecycle/archive command was run.

## Finalized Report / Current Recommendation

Recommend updating UID0001A1 from `COMPLETION:86`, `CONFIDENCE:89` to `COMPLETION:89`, `CONFIDENCE:91`, with `CANONICAL_OWNER:0000JW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JW`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0` unchanged.

Recommend replacing the blank formal C++ block with a first-draft `HistoryViewingPane` core block covering only the source-authored functions inside this target: constructor, `OnKeyDown`, `IsInteractive`, `OnMouseEvent`, and `OnDraw`. Do not absorb [UID:0001A0] `AdvancePage`, [UID:0001AG] destructor source, [UID:0001A7] singleton-clear helper, [UID:0001AB] destructor thunks, retained MainMenu launch helpers, or the constructor-adjacent cleanup island as separate handwritten source bodies.

Historical pre-callback generated symptom, no longer current: `auto-generated/NexusTK/login/HistoryViewingPane.cpp` header `validator-command-id: 000000007492`, refreshed `2026-07-06T00:43:04-04:00`, emitted UID0001A0 and UID0001AG bodies but still showed `UID:0001A1 ... Completion:86 | Confidence:89 | Empty Emitter Marker`. Current post-callback generated output refreshed to validator command `000000007522` at `2026-07-06T01:15:35-04:00` and emits UID0001A1 source code between the separate UID0001A0 and UID0001AG child bodies.

## Supporting Research

I read the current target page, file/class/global/resource context, exact child pages, retained launch helper pages, MainMenuPane source-route context, current generated output, tracker/coverage generated summaries, and prior executed B-agent reports for related HistoryViewingPane/BackStory decisions.

Key support docs checked:

- `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md`
- `by-file/HistoryViewingPane.md`
- `by-class/HistoryViewingPane.md`
- `by-global/g_pHistoryViewingPane.md`
- `by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md`
- `by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md`
- `by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md`
- `by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md`
- `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md`
- `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md`
- `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md`
- `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md`
- `by-file/MainMenuPane.md`
- `by-class/MainMenuPane.md`
- `by-resource/main-menu-history-resources.md`
- `executed-b-agent-research/B006/0001A0-HistoryViewingPaneAdvancePage-source-quality.md`
- `executed-b-agent-research/B007/0001AG-HistoryViewingPaneDestructor-source-quality.md`
- `executed-b-agent-research/B004/00019R-HistoryViewingPaneLaunchHelpers-source-quality.md`
- `executed-b-agent-research/B014/0001A2-BackStoryDialogPaneCore-source-quality.md`
- `auto-generated/NexusTK/login/HistoryViewingPane.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`

## Target

[UID:0001A1] `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md`

Current target summary: pre-login full-screen story/history frame viewer core under [UID:0000JW] `HistoryViewingPane`.

## Current Target State

Gate 1 baseline metadata before this implementation callback:

| Field | Pre-callback value | Post-callback value |
| --- | --- | --- |
| `COMPLETION` | `86` | `89` |
| `CONFIDENCE` | `89` | `91` |
| `CANONICAL_OWNER` | `0000JW` | `0000JW` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000JW` | `0000JW` |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |
| `Nested` | `0` | `0` |
| formal `RECONSTRUCTION_CPP CODE` | blank | populated with accepted first-draft core block |

Pre-callback tracker state: `auto-generated/-ag-research-tracker.md` listed UID0001A1 at `86/89`, combined `87.5`, reconstructable `true`, reports `0`.

Post-callback generated state: `auto-generated/NexusTK/login/HistoryViewingPane.cpp` refreshed to validator command `000000007522` at `2026-07-06T01:15:35-04:00` and emits UID0001A1 source code between separate UID0001A0 and UID0001AG child bodies. UID0001A1 no longer appears as an `Empty Emitter Marker`.

## Heuristic / Inference Reanalysis And Validation

UID0001A1 is not merely a parent/index page and is not a no-owner raw-helper cluster. It contains the source-authored `HistoryViewingPane` constructor and four virtual/input/draw methods. The page also contains padding and one constructor-adjacent cleanup island that should be documented as compiler/EH support, not emitted as a separate handwritten source body.

Current MCP session and health:

- Session: `supervisor_recovery_20260705`
- Server health: `status:"ok"`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- `auto_analysis_ready:true`
- `hexrays_ready:true`
- `strings_cache_ready:true`
- `strings_cache_size:2067`

Current MCP function inventory:

| Address | MCP result | Source disposition |
| --- | --- | --- |
| `0x004ffd40` | `sub_4FFD40`, size `0x39` | Exact child [UID:0001A0] `AdvancePage`; do not paste into UID0001A1. |
| `0x004ffd79` | not a function | Seven-byte padding continues to constructor start. |
| `0x004ffd80` | `sub_4FFD80`, size `0x149` | `HistoryViewingPane::HistoryViewingPane`. |
| `0x004ffec9` | not a function | Modeled constructor end followed by padding and cleanup island. |
| `0x004ffed0` | not a function | Constructor-adjacent cleanup island, not a separate source method. |
| `0x004fff10` | `sub_4FFF10`, size `0x74` | `HistoryViewingPane::OnKeyDown`. |
| `0x004fff90` | `sub_4FFF90`, size `0x5` | true-return interactive virtual slot. |
| `0x004fffa0` | `sub_4FFFA0`, size `0x7a` | `HistoryViewingPane::OnMouseEvent`. |
| `0x00500020` | `sub_500020`, size `0x6b` | `HistoryViewingPane::OnDraw`. |
| `0x0050008b` | not a function | Target exclusive end; five `0xcc` bytes follow before successor. |
| `0x00500090` | `sub_500090`, size `0x353` | Successor `BackStoryDialogPane`, not part of UID0001A1. |

Current MCP byte/padding facts:

- `0x004ffd79-0x004ffd80`: seven `0xcc` bytes after UID0001A0 and before this target's constructor.
- `0x004ffec9-0x004ffed0`: seven `0xcc` bytes after the modeled constructor.
- `0x004ffed0-0x004fff0a`: nonfunction constructor cleanup island. Disassembly shows vtable restores, `sub_582B70` string release, `unk_69B494 = 0`, then jump to `sub_544580` base cleanup.
- `0x004fff0a-0x004fff10`: alignment before the key handler.
- `0x004fff84-0x004fff90`: twelve `0xcc` bytes before the true-return slot.
- `0x004fff95-0x004fffa0`: eleven `0xcc` bytes before the mouse handler.
- `0x0050001a-0x00500020`: six `0xcc` bytes before draw.
- `0x0050008b-0x00500090`: five `0xcc` bytes before `BackStoryDialogPane`.

Constructor behavior from current MCP decompile:

- Calls `sub_544460((char *)this, 0)` for base pane construction.
- Publishes `this` to `unk_69B494` / `g_pHistoryViewingPane`, with a compiler fallback clear path.
- Installs the three `HistoryViewingPane` vtables at primary `+0x0`, secondary `+0xa0`, and secondary `+0xa4`.
- Initializes the `+0x104` resource-name field through `sub_582B20`.
- Sets `+0xf8` frame index to `0`.
- Queries `dword_67A744` through `sub_4D1780(resourceName)` and stores `frameCount - 1` at `+0xfc`.
- Stores `10000` at `+0x100` as the timer delay.
- Assigns the constructor resource name into `+0x104` through `sub_582D20`.
- Initializes full-screen bounds through `sub_4B7C50(&bounds, 0, 0, word_66DA94, word_66DA98)`.
- Creates/places the pane through `sub_544C70(this, &bounds, 0, 0, unk_69B378)`.
- Installs cursor/render context through `sub_544D30(this, 0, dword_67A7CC)`.
- Schedules the first timer/update on the `+0xa4` subobject through `sub_5975E0(this + 0xa4, 0, delay, 0, 0)`.

Input and draw behavior from current MCP decompile:

- `OnKeyDown` accepts event type `8`, narrows the key through `std::ctype<char>::do_narrow`, handles Enter `13`, Escape `27`, and Space `32`, calls UID0001A0 `AdvancePage()` while `m_frameIndex < m_totalFrames`, then cancels/reschedules the timer. When no pages remain it calls the pane close/delete path.
- `IsInteractive` returns `true` and has no callees.
- `OnMouseEvent` accepts event types `3` and `6`, closes when the page index is at/over the total, otherwise performs the same clamp-to-`3`/increment/invalidate behavior inline and cancels/reschedules the timer.
- `OnDraw` initializes a local frame/image object, reads `dword_67A744`, resolves `m_resourceName` through `sub_584540`, fetches the current frame by `m_frameIndex` through `sub_4D02F0`, and draws using `NPAL4.PAL` through `sub_4B9980`.

Caller/xref evidence:

- `xrefs_to 0x004ffd80`: exactly six code refs: active `MainMenuPane::ActivateMenuItem` call sites `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, `0x004f7c3d`, plus retained helper calls `0x004f912b` in `OpenStoryViewingPane` and `0x004f91ab` in `OpenHistoryViewingPane`.
- `xref_query 0x004ffd80` data refs: zero.
- `find_bytes 80 FD 4F 00`: zero saved absolute pointer hits for the constructor start.
- `xrefs_to 0x004ffd40`: one code ref at `0x004fff52` inside `OnKeyDown`.
- `xrefs_to 0x004fff10`: one data ref at vtable slot `0x0061da24`.
- `xrefs_to 0x004fffa0`: one data ref at vtable slot `0x0061da20`.
- `xrefs_to 0x004fff90`: one data ref at vtable slot `0x0061da50`.
- `xrefs_to 0x00500020`: one data ref at vtable slot `0x0061da14`.
- `xrefs_to 0x0069b494`: six lifecycle refs at `0x004f69dd`, `0x004ffdd6`, `0x004ffddd`, `0x004ffefa`, `0x005023b0`, and `0x0050278d`.
- `xrefs_to 0x0061d9d0`, `0x0061da1c`, and `0x0061da4c`: constructor/destructor parity refs at constructor stores, cleanup-island/restoration refs, and destructor stores.
- `xrefs_to 0x0061e514`: one draw-path ref at `0x00500061` for `NPAL4.PAL`.
- `type_query *HistoryViewingPane*`: no local UDT/type declaration was found, so class/member spelling remains documentation-inferred.
- `entity_query names HistoryViewingPane`: decorated vtable and RTTI names exist for `HistoryViewingPane` and `Singleton<HistoryViewingPane>`, supporting class ownership despite absent local UDTs.

## Evidence Standards Used

I used current live IDA MCP evidence as the required runtime/provenance source. Calls were narrow and schema-current: `idb_list`, `server_health`, exact-address `lookup_funcs`, capped `get_bytes`, single-function `decompile`, capped `callees`, capped `xrefs_to`, scoped `xref_query`, capped `find_bytes`, capped `type_query`, capped `entity_query`, `get_string`, `make_signature_for_function`, and one capped disassembly of the constructor cleanup gap. No broad function list, unbounded search, unbounded callgraph, IDA mutation, IDB save, patching, rename, type application, or lifecycle command was used.

For source-quality judgment I treated direct current MCP facts as stronger than older target prose. I also preserved accepted child-page decisions: UID0001A0 and UID0001AG own their exact source bodies; UID0001A7 and UID0001AB remain compiler support/no-code pages; UID00019R is a non-emitting split/index while UID0003H6 and UID0003H7 own retained MainMenu opener bodies.

## Evidence Checked

| Evidence class | Result |
| --- | --- |
| Active IDA MCP session | `supervisor_recovery_20260705`, health `ok`, imagebase `0x400000`. |
| Target function boundaries | Five source functions confirmed: `0x004ffd80`, `0x004fff10`, `0x004fff90`, `0x004fffa0`, `0x00500020`. |
| Internal nonfunction support | Constructor cleanup island at `0x004ffed0-0x004fff0a` is not a function and should be documented as compiler/EH support. |
| Padding/successor | Local padding split confirmed; successor `BackStoryDialogPane` starts at `0x00500090`. |
| Constructor xrefs | Six code refs exactly; zero data refs; no saved constructor-start pointer bytes. |
| Vtable refs | `OnDraw`, `OnMouseEvent`, `OnKeyDown`, and `IsInteractive` each have one vtable data ref. |
| Singleton refs | Six `g_pHistoryViewingPane` lifecycle refs, including constructor publish/fallback, cleanup island, clear helper, destructor, and main-menu cleanup read. |
| Generated output | Historical pre-callback command `000000007492` showed UID0001A1 as an `Empty Emitter Marker`; current post-callback command `000000007522` emits UID0001A1 source code while exact UID0001A0 and UID0001AG child bodies remain separate. |
| Owner route | `HistoryViewingPane.cpp` route remains best; `MainMenuPane` owns resource selection/openers, not viewer internals. |
| C++ blockers | Exact original member names/helper names are not fully recovered, but current evidence is sufficient for first-draft C++ with documented inferred names and confidence caps. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0001A1-01 | Current MCP session `supervisor_recovery_20260705` is healthy with imagebase `0x400000` and Hex-Rays ready. | High | `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `hexrays_ready:true`. | Target `Current IDA MCP Evidence`; support evidence notes | incorporate | applied: target and support pages record session/health/imagebase/Hex-Rays-ready proof. |
| C-0001A1-02 | UID0001A1 contains five source functions at `0x004ffd80`, `0x004fff10`, `0x004fff90`, `0x004fffa0`, and `0x00500020`. | High | `lookup_funcs` sizes `0x149`, `0x74`, `0x5`, `0x7a`, `0x6b`. | Target `Covered Range` and `Current IDA MCP Evidence`; class method notes | incorporate | applied: target and class page record exact half-open source ranges and roles. |
| C-0001A1-03 | The target also contains a nonfunction constructor cleanup island at `0x004ffed0-0x004fff0a`; it is compiler/EH support, not a separate source method. | High | `lookup_funcs 0x004ffed0` not a function; disasm shows vtable restores, `sub_582B70`, singleton clear, jump to `sub_544580`. | Target `Covered Range`, `Behavior Summary`, no-code caveat; class/source layout note | incorporate | applied: target and class page document the cleanup island as no-code compiler/EH support. |
| C-0001A1-04 | Padding/boundaries are now precise, including seven `cc` bytes before constructor, internal alignment, and five `cc` bytes before successor `0x00500090`. | High | Current `get_bytes` over boundary windows; successor `lookup_funcs 0x00500090 -> sub_500090`. | Target `Covered Range` and `Current IDA MCP Evidence` | incorporate | applied: target range table and evidence notes record all padding/successor facts. |
| C-0001A1-05 | Constructor behavior is source-ready: base construction, singleton publish, three vtable installs, resource-name field, frame count, timer delay, full-screen bounds, placement, cursor/context, and timer scheduling. | High | Current decompile `0x004ffd80`; refs to `unk_69B494`, vtables, `dword_67A744`, `word_66DA94`, `word_66DA98`, `unk_69B378`, `dword_67A7CC`. | Target `Behavior Summary`, formal C++ block; class method notes | incorporate | applied: target formal C++ and prose include constructor source shape and confidence caps. |
| C-0001A1-06 | `OnKeyDown` handles event type `8`, keys Enter/Escape/Space, calls UID0001A0 while pages remain, reschedules timer, and closes when exhausted. | High | Current decompile `0x004fff10`; xref to `0x004ffd40`; callees `sub_597600`, `sub_5975E0`, `sub_544690`. | Target `Behavior Summary`, formal C++ block; class method notes | incorporate | applied: target formal C++ and prose include accepted key-handler behavior. |
| C-0001A1-07 | `OnMouseEvent` handles event types `3` and `6`, inlines the advance behavior, invalidates bounds, reschedules timer, and closes when exhausted. | High | Current decompile `0x004fffa0`; no call to `0x004ffd40`; callees `sub_597600`, `sub_5975E0`, `sub_544690`. | Target `Behavior Summary`, formal C++ block; class method notes | incorporate | applied: target formal C++ and prose include accepted mouse-handler behavior. |
| C-0001A1-08 | `IsInteractive` is a true-return virtual slot. | High | `lookup_funcs 0x004fff90 size 0x5`; decompile returns `1`; vtable data ref at `0x0061da50`. | Target `Covered Range`, formal C++ block; class method notes | incorporate | applied: target formal C++ and class method table record true-return slot. |
| C-0001A1-09 | `OnDraw` resolves `m_resourceName` and `m_frameIndex` through EPF library state and draws with `NPAL4.PAL`. | High | Current decompile `0x00500020`; xref `0x00500061 -> 0x0061e514`; `get_string 0x0061e514 -> NPAL4.PAL`. | Target `Behavior Summary`, formal C++ block; class method notes | incorporate | applied: target formal C++ and prose include accepted draw behavior. |
| C-0001A1-10 | Constructor call reachability is exactly four active MainMenuPane call sites plus two retained launch helper call sites. | High | `xrefs_to 0x004ffd80` returned six code refs: `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, `0x004f7c3d`, `0x004f912b`, `0x004f91ab`. | Target `Current IDA MCP Evidence`, ownership analysis; support evidence notes | incorporate | applied: target and support evidence notes record the six-call inventory. |
| C-0001A1-11 | Constructor start has zero data xrefs and zero saved absolute pointer hits, so no hidden pointer-table owner route is proven. | High | `xref_query 0x004ffd80 data total 0`; `find_bytes 80 FD 4F 00` zero matches. | Target negative evidence and rejected alternatives | incorporate | applied: target evidence records zero data refs/pointer hits and rejects hidden owner routes. |
| C-0001A1-12 | Vtable ownership remains `HistoryViewingPane`: virtual method refs at `0x0061da14`, `0x0061da20`, `0x0061da24`, `0x0061da50`, plus RTTI/decorated names. | High | `xrefs_to` for four functions; `entity_query` returned decorated `HistoryViewingPane` vtables/RTTI. | Target `Source Ownership Notes`, class support note | incorporate | applied: target and class support note record vtable refs and ownership. |
| C-0001A1-13 | UID0001A0 and UID0001AG exact child bodies must remain separate and must not be pasted into UID0001A1. | High | Child pages now source-ready with formal C++; generated `HistoryViewingPane.cpp` emits both child bodies. | Target `Source Boundary And No-Duplication Policy`; support docs | already-present / reinforce | applied: target and support pages explicitly preserve exact child emissions; child pages unchanged as already-present. |
| C-0001A1-14 | UID0001A7 and UID0001AB remain non-reconstructable compiler support/no-code pages. | High | Current support docs: singleton clear helper and destructor thunks are compiler/EH or ABI glue. | Target related support; rejected alternatives | already-present / reinforce | already-present: existing support pages already had no-code proof; target now reinforces the boundary. |
| C-0001A1-15 | Historical pre-callback generated output showed the stale empty-emitter state for UID0001A1 after child emissions; post-callback generated output now proves marker removal and current UID0001A1 source emission. | High | `auto-generated/NexusTK/login/HistoryViewingPane.cpp`, command `000000007492`, included UID0001A1 Empty Emitter Marker; command `000000007522` emits UID0001A1 source code. | Target generated-output note; report validator/generated freshness sections | incorporate | applied: generated file refreshed to command `000000007522` and UID0001A1 now emits code; no UID0001A1 empty marker remains. |
| C-0001A1-16 | `MainMenuPane` owns story/history resource selection and retained opener helpers; it is not the direct canonical owner/emitter for UID0001A1. | High | MainMenuPane docs and retained opener pages construct `HistoryViewingPane`; core behavior/vtables/singleton belong to HistoryViewingPane. | Target ownership analysis; support docs if stale | reject-stale | applied: target and support pages keep MainMenuPane as caller/resource context only. MainMenuPane/opener docs unchanged because already at same-or-greater detail. |
| C-0001A1-17 | Chat/color/history UI owner pollution remains rejected; this is pre-login story/history viewer code. | High | `by-file/HistoryViewingPane.md` and `by-class/HistoryViewingPane.md` record owner pollution; current MCP vtable/RTTI confirms HistoryViewingPane. | Target `Source Ownership Notes`, support docs | reject-stale | applied: target rejects chat/color/backstory/staff/global/no-owner alternatives; file/class already carried owner-pollution caveat and were reinforced. |
| C-0001A1-18 | Missing local UDT and exact helper/member spelling cap confidence but do not block first-draft C++. | Medium-high | `type_query *HistoryViewingPane*` returned zero local types; behavior and field offsets are directly proven. | Target score rationale and open questions; class support note | incorporate | applied: target score rationale and support note record confidence caps while formal C++ is populated. |

## Positive Evidence Summary

- Current live MCP confirms the exact target function inventory and the successor boundary.
- The constructor, input handlers, true-return virtual slot, and draw method all have coherent source-level behavior under `HistoryViewingPane`.
- Vtable, RTTI, singleton, constructor callers, and generated route all point to [UID:0000JW] `HistoryViewingPane`.
- Exact child source bodies for `AdvancePage` and destructor are already emitted separately, proving the file route and field names used by this family.
- The target's `RECONSTRUCTABLE:TRUE` plus nonblank emitter remains correct; the historical pre-callback stale parts were the blank formal C++ block and insufficient documentation of the cleanup island.

## Negative Evidence Summary

- No data refs and no saved absolute pointer hits point to constructor start `0x004ffd80`; there is no hidden table owner route for another module.
- No local UDT named `HistoryViewingPane` is available in IDA, so final member declarations and exact method signatures remain inferred from documentation and binary behavior.
- The constructor cleanup island is not a function start and should not become a separate source function.
- MainMenuPane owns the menu/resource launch decision only; it does not own the viewer's constructor/input/draw implementation.
- UID0001A0 and UID0001AG already own their exact C++ bodies; UID0001A1 should not duplicate them.

## Ranked Ownership Analysis

1. [UID:0000JW] `HistoryViewingPane` - accepted direct owner/emitter. Evidence: constructor/vtable/singleton/destructor parity, class docs, file docs, generated route, current decorated names, and direct source behavior.
2. [UID:000066] `HistoryViewingPane` class - class context and declaration route; not the by-file emitter itself.
3. [UID:0000L0] `MainMenuPane` - caller/resource-selection context only. It constructs this pane at active menu sites and retained helper sites but does not own this target's methods.
4. [UID:00019R] / [UID:0003H6] / [UID:0003H7] retained launch helpers - constructor callers only; exact helper bodies already route to MainMenuPane.
5. [UID:0001A0] / [UID:0001AG] exact child pages - same class/file family, but separate function bodies outside UID0001A1.
6. [UID:0001A7] / [UID:0001AB] compiler support pages - no handwritten body ownership.
7. ChattingColorPane, chat-history UI, BackStoryDialogPane, NewHistoryDialogPane, StaffsDialogPane, global singleton page, raw no-owner route - rejected by current vtable, caller, range, resource, and singleton evidence.

## Source Placement

Keep source placement in:

```text
NexusTK/login/HistoryViewingPane.cpp
```

The page should remain under [UID:0000JW] `HistoryViewingPane`. The support source route should mention that `MainMenuPane.cpp` owns `OpenStoryViewingPane` / `OpenHistoryViewingPane` and resource selection, while `HistoryViewingPane.cpp` owns the full-screen frame viewer behavior, singleton lifecycle, draw path, input handlers, and destructor.

## First-Draft C++ Recommendation

Replace the target's blank formal C++ block with this first-draft source block. The helper/member names `Create`, `SetCursor`, `m_timerHandler.Cancel/Start`, `MarkForDeletion`, `GetFrameCount`, `GetFrame`, and `DrawEpfFrame` are source-facing names inferred from documented behavior and existing project naming; exact spelling remains a confidence cap. The compiler/EH cleanup island at `0x004ffed0-0x004fff0a`, vtable stores, and base cleanup should stay out of source prose or comments, not in handwritten C++.

```cpp
HistoryViewingPane::HistoryViewingPane(const wchar_t *resourceName)
    : Pane(0),
      m_frameIndex(0),
      m_totalFrames(g_pEPFLib->GetFrameCount(resourceName) - 1),
      m_delayTimer(10000)
{
    g_pHistoryViewingPane = this;
    m_resourceName.Assign(resourceName);

    RectBounds bounds;
    InitRectBounds(&bounds, 0, 0, g_screenWidth, g_screenHeight);
    Create(bounds, 0, 0, g_pMainUiLayer);
    SetCursor(0, g_pCursorManager);
    m_timerHandler.Start(0, m_delayTimer, 0, 0);
}

bool HistoryViewingPane::OnKeyDown(const KeyEvent &event)
{
    if (event.type == 8) {
        const char key = NarrowKeyEvent(event);
        if (key == 13 || key == 27 || key == 32) {
            if (m_frameIndex < m_totalFrames) {
                AdvancePage();
                m_timerHandler.Cancel();
                m_timerHandler.Start(0, m_delayTimer, 0, 0);
                return true;
            }

            MarkForDeletion();
        }
    }

    return true;
}

bool HistoryViewingPane::IsInteractive() const
{
    return true;
}

bool HistoryViewingPane::OnMouseEvent(const MouseEvent &event)
{
    if (event.type != 3 && event.type != 6) {
        return true;
    }

    if (m_frameIndex >= m_totalFrames) {
        MarkForDeletion();
        return true;
    }

    if (m_frameIndex < 3) {
        m_frameIndex = 3;
    } else {
        ++m_frameIndex;
    }

    Invalidate(&m_bounds);
    m_timerHandler.Cancel();
    m_timerHandler.Start(0, m_delayTimer, 0, 0);
    return true;
}

void HistoryViewingPane::OnDraw()
{
    EpfFrame frame;
    g_pEPFLib->GetFrame(m_resourceName.CStr(), m_frameIndex, &frame);
    DrawEpfFrame(frame, m_bounds, L"NPAL4.PAL", 0);
}
```

Do not include `HistoryViewingPane::AdvancePage()` or `HistoryViewingPane::~HistoryViewingPane()` in this block; they are already exact child emissions. Do not emit the `0x004ffed0` cleanup island as C++.

## Final Recommendation

Implement UID0001A1 as a source-ready `HistoryViewingPane` core method cluster:

- Set target metadata to `COMPLETION:89`, `CONFIDENCE:91`.
- Keep owner/emitter `0000JW`, `RECONSTRUCTABLE:TRUE`, blank emitter position, and `Nested:0`.
- Insert the first-draft C++ block above.
- Update target prose to include current MCP session/health/imagebase, exact function inventory, cleanup island, padding/successor boundary, xrefs, vtable refs, singleton refs, historical pre-callback generated empty-marker state, post-callback marker removal/source emission, rejected alternatives, and confidence caps.
- Preserve child/source boundaries so UID0001A0, UID0001AG, UID0001A7, UID0001AB, UID0003H6, UID0003H7, and UID00019R are not duplicated or re-owned by UID0001A1.

## Recommended Target Doc Changes

Target-only metadata changes:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the blank formal `RECONSTRUCTION_CPP CODE` body with the first-draft block in this report.

Add report-level target prose:

- Current MCP session `supervisor_recovery_20260705`, status `ok`, imagebase `0x400000`.
- Exact half-open modeled function ranges:
  - `0x004ffd80-0x004ffec9` constructor.
  - `0x004fff10-0x004fff84` `OnKeyDown`.
  - `0x004fff90-0x004fff95` `IsInteractive`.
  - `0x004fffa0-0x0050001a` `OnMouseEvent`.
  - `0x00500020-0x0050008b` `OnDraw`.
- The current target table should stop implying the constructor-to-key gap is only padding; document `0x004ffed0-0x004fff0a` as a nonfunction constructor cleanup island and keep it out of source C++.
- Confirm target exclusive end `0x0050008b`, five-byte successor padding `0x0050008b-0x00500090`, and successor `BackStoryDialogPane` at `0x00500090`.
- Record exact constructor xrefs, zero data refs/pointer hits to constructor start, vtable refs for virtual methods, and singleton refs.
- Preserve no-duplication with UID0001A0 and UID0001AG child emissions.
- Replace old blank-C++ rationale with current source-ready rationale and remaining confidence caps.

Callback validator command run from `source-3/project-documentation` after accepted target edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001A1-HistoryViewingPaneCore-source-quality-removed.md](0001A1-HistoryViewingPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-callback generated freshness verification: `auto-generated/NexusTK/login/HistoryViewingPane.cpp` was inspected read-only after validation and compared against callback validator metadata. The generated file refreshed to command `000000007522` at `2026-07-06T01:15:35-04:00`, UID0001A1 no longer appears as an `Empty Emitter Marker`, and UID0001A0/UID0001AG remain separate emitted child bodies. `auto-generated/-ag-coverage-report-by-memory.md` and `auto-generated/-ag-research-tracker.md` refreshed to command `000000007523`; no generated files were manually edited.

## Recommended Support Doc Changes

Support docs were edited during the implementation callback only where same-or-greater detail was missing:

- `by-file/HistoryViewingPane.md`: recorded that UID0001A1 now owns first-draft core constructor/input/draw C++ while UID0001A0 and UID0001AG remain exact child emissions; generated-output wording no longer presents UID0001A1 as a current empty marker.
- `by-class/HistoryViewingPane.md`: added the current source-ready core method state, cleanup-island/no-code caveat, and confidence caps for exact member/helper spellings.
- `by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md`: no edit expected; already states that core must not absorb the child body.
- `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md`: no edit expected; already states destructor source lives on its exact child.
- `by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md` and `by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md`: no edit expected; already no-code compiler support.
- `by-file/MainMenuPane.md`, `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md`, `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md`, `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md`: no edit expected unless they still describe UID0001A1 as blank/unready; their current source-route role is caller/resource selection context only.

Do not edit generated files, project-level generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers during callback.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `86` | `89` | Current MCP confirms exact function inventory, cleanup island, padding, xrefs, behavior, owner/emitter route, and first-draft C++ readiness; historical pre-callback generated stale-marker state is now resolved by post-callback source emission. |
| `CONFIDENCE` | `89` | `91` | Strong current MCP and support-doc agreement; capped by absent local UDT, inferred helper/member spellings, and not-final exact signatures. |
| `CANONICAL_OWNER` | `0000JW` | `0000JW` | `HistoryViewingPane.cpp` remains direct owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored core methods are reconstructable. |
| `EMITTER_UIDS` | `0000JW` | `0000JW` | Generated route is `auto-generated/NexusTK/login/HistoryViewingPane.cpp`. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No special position needed. |
| `Nested` | `0` | `0` | No evidence supports nesting change. |

## Open Questions With Attempted Resolution

- Exact original names for timer methods, draw helper, cursor/context setter, and close/delete method remain unresolved. Resolution: use source-facing inferred names in first-draft C++ and cap confidence; do not leave the core blank.
- Exact event struct declarations remain unresolved. Resolution: use `KeyEvent` / `MouseEvent` placeholders consistent with documented behavior and vtable callbacks; cap confidence.
- No local `HistoryViewingPane` UDT exists in current IDA. Resolution: rely on support docs and current field-offset evidence for `m_frameIndex`, `m_totalFrames`, `m_delayTimer`, `m_resourceName`, `m_bounds`, and timer subobject naming; cap confidence.
- Constructor cleanup island is not a function. Resolution: document it as compiler/EH cleanup support and omit from formal C++.
- Whether `OnMouseEvent` was originally written by duplicating advance logic or by a call that the compiler inlined remains unresolved. Resolution: first-draft C++ duplicates the observed clamp/increment/invalidate logic to avoid inventing a direct call not present in the binary.

## Validator Results

Scoped validators run from `source-3/project-documentation` during the implementation callback:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | `python .\tools\validator.py --mode file --file by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md --apply --queue-timeout 240` | `000000007518` | `2026-07-06T01:15:13-04:00` | `0` | `1` | Updated UID0001A1 completion/confidence, C++ registry from blank to block, generated refresh deferred. |
| `by-file/HistoryViewingPane.md` | `python .\tools\validator.py --mode file --file by-file/HistoryViewingPane.md --apply --queue-timeout 240` | `000000007520` | `2026-07-06T01:15:25-04:00` | `0` | `1` | Generated refresh deferred and then observed current in `HistoryViewingPane.cpp`, research tracker. |
| `by-class/HistoryViewingPane.md` | `python .\tools\validator.py --mode file --file by-class/HistoryViewingPane.md --apply --queue-timeout 240` | `000000007522` | `2026-07-06T01:15:35-04:00` | `0` | `1` | Class support validator passed; generated refresh deferred. |

Warnings/side effects: validators reported validator-owned generated refreshes as deferred. `auto-generated/NexusTK/login/HistoryViewingPane.cpp` caught up to command `000000007522` at `2026-07-06T01:15:35-04:00` and contains UID0001A1 source code, not an `Empty Emitter Marker`; UID0001A0 and UID0001AG remain separate emitted child bodies. `auto-generated/-ag-coverage-report-by-memory.md` refreshed to command `000000007523` at `2026-07-06T01:15:37-04:00` and records UID0001A1 `emits_code:true`, `89%`, `very-strong`. `auto-generated/-ag-research-tracker.md` refreshed to command `000000007523` at `2026-07-06T01:15:37-04:00` and lists UID0001A1 as `89/91`, combined `90.0`, reconstructable `true`.

No `execute_report`, dry-run/probing execute variant, registry lifecycle command, report move, archive move, or manual generated edit was run.

## Changed Files

Callback changed by-* files:

- `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md`
- `by-file/HistoryViewingPane.md`
- `by-class/HistoryViewingPane.md`

Report status updated:

- `tools/leaser/Agents/Agent-B001/research/0001A1-HistoryViewingPaneCore-source-quality.md`

Validator-owned generated side effects observed but not manually edited:

- `auto-generated/NexusTK/login/HistoryViewingPane.cpp`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-research-tracker.md`
- `project-level/-auto-completion-stats.md`

No coverage-report files, validator state, supervisor ledgers, lifecycle/archive files, or executed-report locations were manually edited.

## Implementation Tracking Checklist

- [x] Lease `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` only immediately before callback editing; release immediately after the edit/validator/generated-freshness batch. Proof: leased target plus `by-file/HistoryViewingPane.md` and `by-class/HistoryViewingPane.md` as `B001`, then released all three successfully; final lease report shows no active B001 leases.
- [x] Apply target metadata `COMPLETION:89`, `CONFIDENCE:91`, preserving owner/emitter/reconstructable/emitter-position/`Nested:0`. Proof: target validator `000000007518` reported `completion_update 0001A1 ... 89` and `confidence_update 0001A1 ... 91`.
- [x] Replace the blank target formal C++ block with the report's first-draft core block only; do not include UID0001A0 or UID0001AG bodies. Proof: target validator `000000007518` reported C++ registry `blank -> block`; generated `HistoryViewingPane.cpp` shows UID0001A1 constructor/input/draw core while UID0001A0 and UID0001AG remain separate.
- [x] Add current MCP session/health/imagebase, exact function inventory, cleanup island, padding/successor boundary, constructor/input/draw facts, xref inventory, singleton/vtable refs, pointer negatives, historical pre-callback generated empty-marker state, post-callback marker removal/source emission, and rejected alternatives to the target at report-level detail. Proof: target `Covered Range`, `Behavior Summary`, `Current IDA MCP Evidence`, `Generated Output State`, `Source Ownership Notes`, and `Source Boundary And No-Duplication Policy`.
- [x] Preserve child/source boundaries for UID0001A0, UID0001AG, UID0001A7, UID0001AB, UID00019R, UID0003H6, and UID0003H7. Proof: target no-duplication section and support pages keep exact child/compiler support/caller-only routes.
- [x] Edit support docs only if callback authorizes them and same-or-greater detail is missing; otherwise mark rows already-present/excluded-with-reason in this report's ledger/checklist. Proof: edited `by-file/HistoryViewingPane.md` and `by-class/HistoryViewingPane.md`; left UID0001A0, UID0001AG, UID0001A7, UID0001AB, UID00019R, UID0003H6, UID0003H7, and MainMenuPane docs unchanged as already-present/caller-only/support-only.
- [x] Run `python .\tools\validator.py --mode file --file by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md --apply --queue-timeout 240` from `source-3/project-documentation`. Proof: command `000000007518`, timestamp `2026-07-06T01:15:13-04:00`, exit `0`, `ok:1`.
- [x] Run scoped validators for every edited support by-* file, if any. Proof: `by-file/HistoryViewingPane.md` command `000000007520`, exit `0`, `ok:1`; `by-class/HistoryViewingPane.md` command `000000007522`, exit `0`, `ok:1`.
- [x] Inspect `auto-generated/NexusTK/login/HistoryViewingPane.cpp` after validation and compare `validator-command-id` / `validator-refreshed-at` to callback validator metadata; confirm UID0001A1 is no longer an `Empty Emitter Marker`. Proof: generated header `validator-command-id: 000000007522`, `validator-refreshed-at: 2026-07-06T01:15:35-04:00`; UID0001A1 appears with source code at `89/91` and no UID0001A1 empty marker; UID0001A0 and UID0001AG remain separate emitted bodies.
- [x] Inspect generated memory coverage/tracker freshness if refreshed by validator; do not edit generated files manually. Proof: coverage report header `000000007523` records UID0001A1 `emits_code:true`, `89%`, `very-strong`; research tracker header `000000007523` lists UID0001A1 `89/91`, combined `90.0`; generated files were read-only observations.
- [x] Update this report's Claim And Incorporation Ledger with `applied`, `already-present`, `excluded-with-reason`, or `blocked` for every accepted claim after callback. Proof: ledger rows C-0001A1-01 through C-0001A1-18 updated above; no row is blocked.
- [x] Update `Validator Results`, `Changed Files`, and this checklist after callback. Proof: current sections contain validator command metadata, changed by-* files/report file, generated freshness, lease release proof, and no remaining blockers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000007528","destination_path":"executed-b-agent-research/B001/0001A1-HistoryViewingPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001A1-HistoryViewingPaneCore-source-quality.md","timestamp":"2026-07-06T04:27:01-04:00","uid":"0001A1"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001A1-HistoryViewingPaneCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001A1-HistoryViewingPaneCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001A1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
