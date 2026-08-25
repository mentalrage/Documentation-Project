** TARGET-REPORT-UID:0002T5 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0002T5 g_pActiveBrowserWindow Source-Quality Report


## Finalized Report / Current Recommendation

Current recommendation: promote UID0002T5 to a source-ready Browser module global declaration for the active `BrowserWindow` singleton storage at `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md`.

Final disposition: source-authored module/global pointer storage, not padding, not compiler-only data, and not a permanent blank marker. Current MCP-backed bytes and integer reads show zero-filled storage; older `0xffffffff` initializer wording is historical/stale for the current IDB evidence. The active IDB has no recovered source-quality global symbol or UDT for this slot, but the bytes, xrefs, constructor/destructor behavior, BrowserWindow class evidence, and Browser source-root precedent are strong enough for an exact first-draft declaration.

Implementation callback status: accepted details have been applied to the target and stale support docs. The target by-memory page is now `COMPLETION:90`, `CONFIDENCE:92`, keeps `CANONICAL_OWNER:0000Q6`, keeps `RECONSTRUCTABLE:TRUE`, keeps `EMITTER_UIDS:0000Q6`, keeps the optional emitter position blank, and contains the formal C++ block below. Support docs now historicalize the older `0xffffffff` initializer and provisional-linkage blocker while preserving final Browser one-file versus split-file uncertainty as a confidence cap. Gate 2 repair resolved the generated-emitter route by adding the explicit by-global `[[CHILDREN]]` insertion marker and validating with `--wait-generated`; current generated `Browser.cpp` now contains the UID0002T5 block and declaration. Agent-B004 did not run `execute_report` or any lifecycle/archive command.

Confidence: high for address, width, current zero initialization, exact xref inventory, BrowserWindow type, owner route, and no explicit initializer; medium-high for exact original linkage/source-split spelling. The best current first-draft is file-local `static BrowserWindow *g_pActiveBrowserWindow;` because all proven users remain in the Browser source root and no Application/external consumer was found for this slot.

## Supporting Research

Historical report-only pass: B004 originally created this report without editing target/support by-* docs, generated files, coverage reports, validator state, report lifecycle/archive state, queues, registries, or supervisor ledgers, and without running validators or lifecycle commands. Current callback/repair state: supervisor Gate 1 passed the report at SHA256 `8F4B8C8F151AF6FFC99BE632269B562B860C7F7FF57A78289AF711DD1F4DEDD3`; B004 then edited the accepted target/support by-* docs, ran scoped file validators only for changed by-* docs, released/confirmed leases, and stopped short of `execute_report`. After supervisor MCP restart, B004 revalidated the UID0002T5 evidence on current MCP session `ba171fe4`; prior `ddf5b602` evidence is historical only.

Local search covered current Agent folders, executed B-agent reports, current by-* docs, generated Browser output, and Browser source-family terms for `0002T5`, `g_pActiveBrowserWindow`, `0x0067ab94`, `dword_67AB94`, `unk_67AB94`, `BrowserWindow`, `BrowserWindowCore`, and `BrowserWindowAcceleratorTranslateMessage`. No prior exact report named for UID0002T5 exists. Strongest prior leads:

- Executed B002 `0000HV-Browser-empty-emitter-family-source-quality.md`: lists UID0002T5 as `86/88`, exact storage proven zero-initialized, with a near-term declaration after linkage decision.
- Executed B001 `00020U-browser-accelerator-source-quality.md`: ties `0x0046a510` to `g_pActiveBrowserWindow + 0x18` and classifies it as a retained BrowserWindow-specific accelerator helper.
- Historical B014 active report `0002WH-g_pBrowserDialogOld-source-quality.md`: sibling-source lead only; it recorded then-active MCP session `ddf5b602` seeing neighboring singleton slots as zero-filled and recommended source declarations for exact singleton storage after linkage analysis. Current UID0002T5 proof is from B004 session `ba171fe4`.
- Current `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md`: accepted sibling declaration `BrowserDialog *g_pBrowserDialog;` after current zero-byte recheck.
- Current `by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md`: accepted Browser module static declarations for internal Browser thread/current-host storage, useful precedent for file-local globals when all users stay inside the Browser module.

Generated `auto-generated/NexusTK/browser/Browser.cpp` currently has validator-command-id `000000006620`, refreshed by validator-owned background generation at `2026-07-04T21:00:37-04:00` after B004's scoped current-session repair validators. The repaired snapshot shows [UID:0000Q6] as the coverage parent, immediately expands [UID:0002T5], and contains exactly one `static BrowserWindow *g_pActiveBrowserWindow;` declaration. No generated file was hand-edited. Historical context: supervisor fresh validation command `000000006590` exposed the pre-repair defect where the generated file only had the UID0000Q6 coverage comment and did not include a UID0002T5 generated block; B004 command `000000006593` first repaired the generated-emitter route.

## Target

- Target UID: `0002T5`
- Target path: `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md`
- Address range: `0x0067ab94-0x0067ab98`
- Entity kind: four-byte `.data` pointer storage for the active embedded `BrowserWindow` host.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current supervisor classification: reconstructable exact singleton-storage child under by-global [UID:0000Q6] `g_pActiveBrowserWindow`, routed to Browser source root [UID:0000HV].
- Current implemented scores and parent state: target `90/92`, by-global parent [UID:0000Q6] `89/91`, Browser file [UID:0000HV] `87/89`, BrowserWindow class [UID:00001B] `85/88`. Historical pre-callback state was target `86/88` and by-global `86/88`.
- Recommended score after implementation: target `90/92`, by-global support `89/91`, Browser file unchanged.

## Current Target State

- Current implemented metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000Q6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000Q6`, blank optional emitter position, and formal C++ `static BrowserWindow *g_pActiveBrowserWindow;`.
- Current owner/emitter/reconstructable state: exact storage child is assigned to direct by-global parent [UID:0000Q6], and the by-global parent routes through Browser [UID:0000HV]. By-global support now scores `89/91` and carries a formal coverage comment plus `[[CHILDREN]]` insertion marker rather than duplicating the target declaration.
- Current generated state after Gate 2/current-session repair validation: `auto-generated/NexusTK/browser/Browser.cpp` header is command `000000006620`; UID0000Q6 appears as a coverage comment pointing to UID0002T5, UID0002T5 appears as a generated child block at the next lines, and the file contains exactly one `static BrowserWindow *g_pActiveBrowserWindow;` declaration. Generated refresh remains validator-owned; no generated file was hand-edited.
- Historical pre-callback blockers/stale assumptions: target and support docs preserved older `0xffffffff`/`dword_67AB94` initializer language and treated `static BrowserWindow*` linkage as provisional. Current by-* docs historicalize that wording and use zero-filled `unk_67AB94` storage with source-ready `static BrowserWindow *g_pActiveBrowserWindow;`.
- Related docs checked: `by-global/g_pActiveBrowserWindow.md`, `by-file/Browser.md`, `by-class/BrowserWindow.md`, `by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md`, `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`, `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`, sibling Browser global pages/storage pages, generated `Browser.cpp`, and exact-match executed/active B reports.
- Current artifact/lifecycle status: implementation repair callback is complete and ready for supervisor Gate 2 re-review. Agent-B004 did not run `execute_report`, dry-run/probe variants, lifecycle/archive commands, registry commands, manual report moves, manual generated-file edits, or coverage-report edits.

## Executive Recommendation

Promote UID0002T5 to a source-ready declaration:

```cpp
static BrowserWindow *g_pActiveBrowserWindow;
```

Use no explicit initializer. Current `get_bytes`, `get_int`, and `get_global_value` evidence reports `0`, so C++ static zero initialization represents the storage correctly. Historical `0xffffffff` wording should be retained only as superseded older evidence where useful.

Use `static` in the first draft. Unlike `g_activeBrowserPane`, the current direct refs to UID0002T5 are the BrowserWindow constructor/destructor family, one BrowserWindow-specific retained accelerator helper, and one tiny Browser cleanup thunk. No Application, non-Browser module, or public external singleton consumer was found. A later Browser source split could replace true file-local linkage with a private-header declaration or accessor, but that is a source-organization cap, not a reason to leave the exact storage blank.

## Supervisor Active Recheck

Historical supervisor instruction for the initial assignment required UID0002T5 report-only research, current IDA MCP evidence, exact required headings/provenance, no by-* edits, no generated/coverage edits, no validators, no `execute_report`, and bounded MCP calls only. Current supervisor repair instruction requires replacing stale current-session `ddf5b602` wording with current MCP session `ba171fe4` evidence while preserving the accepted generated-emitter repair.

Compliance/evidence state:

- MCP initialized successfully through `http://127.0.0.1:13337/mcp`.
- `idb_list` returned one active worker session `ba171fe4` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid/worker_pid 12196`, `is_analyzing:false`, `is_active:true`.
- `server_health` for `ba171fe4` returned `status: ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Calls used for the current repair were exact-address or tightly filtered: `lookup_funcs`, `get_bytes`, `get_global_value`, `xrefs_to`, `entity_query`, `type_query`, `find_bytes`, and `decompile`.
- No MCP mutation/process-management tools were used.

## Inference Research Guidance Check

Existing docs were treated as leads, not proof. Older docs use `dword_67AB94`, historical `0xffffffff` initialization, and provisional `static` wording. Current MCP verifies the role but changes the active evidence wording:

- Active IDB value/name state on `ba171fe4`: decompiler output renders the slot as `unk_67AB94`; `get_global_value 0x0067ab94` and `get_global_value unk_67AB94` return `0x0`; `get_global_value g_pActiveBrowserWindow` is `Not found`; `entity_query` returns no `names` or `globals` rows for `g_pActiveBrowserWindow|unk_67AB94|dword_67AB94`.
- Source-facing name: keep `g_pActiveBrowserWindow` because current target/global docs, BrowserWindow constructor/destructor behavior, and Browser source naming style establish that name as the best source-level reconstruction.
- Source-facing type: use `BrowserWindow *` because constructor/deconstructor vtable stores are `BrowserWindow`, the active helper reads `[g_pActiveBrowserWindow + 0x18]`, and BrowserWindow class/core docs document the host object layout.
- Linkage: choose `static` for the first draft because all current xrefs remain inside Browser/BrowseWindow source-root code and no separate translation-unit consumer was found. Reject an external default for this target unless a later source-split pass proves the BrowserWindow helper/global is referenced from another file.
- Wave2/Wave3 artifacts were used only as historical/generated leads; current MCP and current by-* docs drive the recommendation.

## Heuristic / Inference Reanalysis And Validation

The score/source-quality blockers were initializer bytes, active IDA naming, type proof, linkage, owner/emitter route, mixed singleton aggregate relationship, and formal C++ readiness.

Initializer blocker: resolved. Current `get_bytes 0x0067ab94 size 4` and wider reads over `0x0067ab80-0x0067aba4` return all zero bytes. `get_int u32le/i32le` and byte-level `u8` reads at `0x0067ab94-0x0067ab97` return `0`. `get_global_value 0x0067ab94` and `get_global_value dword_67AB94` return `0x0`. Therefore the source declaration needs no explicit initializer.

Historical initializer contradiction: bounded `make_signature_for_range` on the data range returned nonunique `FF FF FF FF` for `0x0067ab94-0x0067ab98` and `FF` bytes for the whole `0x0067ab90-0x0067aba4` cluster. That matches older documentation, but it contradicts current `get_bytes`, `get_int`, and `get_global_value` on the same active session. I treat the signature helper as unsuitable for current data-initializer proof on this data range and preserve `0xffffffff` only as historical/superseded wording to repair in docs.

Name/type blocker: resolved to source-quality inference. MCP has no saved `g_pActiveBrowserWindow` global/type row and no local `BrowserWindow` UDT, but decompiled refs name `unk_67AB94` in functions that install/restore BrowserWindow vtables, publish/clear the pointer, and query the stored object's `+0x18` browser object. The exact original variable spelling is not recovered, but the source-facing name and `BrowserWindow *` type are strong enough.

Linkage blocker: resolved to first-draft `static`. Current xrefs are `0x004696a3`, `0x004696aa`, `0x00469a71`, `0x0046a535`, and `0x00470240`. Those map to BrowserWindow construction, BrowserWindow teardown, the BrowserWindow-specific retained accelerator helper, and a tiny clear thunk. This is narrower than non-static `g_activeBrowserPane` and `g_pBrowserDialog`, whose docs record external/non-tight consumers. It is closest to the accepted `static BrowserThread *g_pBrowserThread;`/`static Browser *g_pCurrentBrowserHost;` Browser module precedent.

Owner route blocker: resolved. Keep direct by-global parent [UID:0000Q6], because that page is the canonical symbol page for the exact storage. Keep source placement under Browser [UID:0000HV]. Do not bypass by-global ownership by reowning directly to BrowserWindow class; the class explains type/lifecycle, not the symbol/documentation home.

Mixed aggregate blocker: resolved. Parent [UID:0002AE] remains a non-emitting coverage index across Browser and WebBoardDialog globals. UID0002T5 is the exact four-byte source declaration route for the BrowserWindow slot.

Rejected alternatives: no-code/blank target, raw `DWORD`, `void *`, `LONG`, `Browser *`, `BrowserPane *`, `BrowserControlPane *`, external declaration by default, explicit `= NULL`, `= (BrowserWindow *)-1`, direct BrowserWindow class ownership, mixed aggregate emission, BrowserDialog/WebBoardDialog ownership, and using the retained accelerator helper as the declaration owner.

## Evidence Standards Used

Evidence ladder applied:

1. Current MCP-backed IDB facts: session health, exact bytes, exact integer values, exact xrefs, current IDB name/type absence, current decompiles, current function lookups.
2. Current by-* docs: target metadata, by-global symbol page, Browser file/source-root page, BrowserWindow class/core pages, exact accelerator helper page, mixed singleton aggregate.
3. Executed/current B reports as leads only, rechecked against current MCP and current docs before using claims.
4. Generated Browser output as freshness/status context only, not as proof that blank output is correct.
5. Source-shape inference after direct binary facts: late-1999 through mid-2000s C++ file-static module pointer for a Browser-internal active host window.

Confidence is capped below final-audit quality because exact original file split (`Browser.cpp` versus `BrowserWindow.cpp`/private header), exact original global linkage, and recovered IDA UDT/global typing are unavailable.

## Evidence Checked

Current MCP session `ba171fe4`:

- `idb_list`: active worker `ba171fe4` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid/worker_pid 12196`, `is_analyzing:false`, `is_active:true`.
- `server_health`: status ok, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- `lookup_funcs`: `0x0067ab94` is not a function. Related functions: `sub_469640` at `0x00469640` size `0x3d7`, misleadingly named `??1exception@boost@@MAE@XZ` at `0x00469a20` size `0x6a`, `sub_46A510` at `0x0046a510` size `0x107`, and `sub_470240` at `0x00470240` size `0xb`.
- `get_bytes`: `0x0067ab94 size 4` returns `0x0 0x0 0x0 0x0`; `0x0067ab90 size 20` returns all zero bytes across the neighboring browser singleton cluster.
- `get_global_value`: `0x0067ab94` returns `0x0`; `unk_67AB94` returns `0x0`; `g_pActiveBrowserWindow` returns `Not found`.
- `xrefs_to 0x0067ab94`: exactly five data xrefs: `0x004696a3`, `0x004696aa`, `0x00469a71`, `0x0046a535`, `0x00470240`.
- `xrefs_to 0x0067ab95`, `0x0067ab96`, and `0x0067ab97`: zero xrefs. `xrefs_to 0x0067ab98`: successor slot has its own ten xrefs; those are not interior refs to UID0002T5.
- `find_bytes`: VA pattern `94 AB 67 00` appears at `0x004696a4`, `0x004696ac`, `0x00469a73`, `0x0046a536`, and `0x00470242`, matching the five operand/xref sites. RVA pattern `94 AB 27 00` has zero matches. Successor VA pattern `98 AB 67 00` has ten separate matches and successor RVA pattern `98 AB 27 00` has zero matches.
- `entity_query`: `names`/`globals` for `g_pActiveBrowserWindow|unk_67AB94|dword_67AB94` returned zero rows.
- `type_query BrowserWindow` and `g_pActiveBrowserWindow`: zero local type rows.
- Historical session `ddf5b602` is retained only as prior corroborating evidence from before the supervisor MCP restart, not as current proof.
- `decompile 0x00469640`: BrowserWindow constructor publishes `unk_67AB94 = this` or clears it on a sentinel/fallback path, then installs five BrowserWindow vtable slices and creates/registers the host window/browser COM object.
- `decompile 0x00469a20`: BrowserWindow ordinary destructor body restores BrowserWindow vtables, releases `this+0x18` through vslot `+8`, and clears `unk_67AB94`.
- `decompile 0x0046a510`: BrowserWindow-specific accelerator helper checks `unk_67AB94`, reads `[unk_67AB94 + 24]`, queries `IID_IOleInPlaceActiveObject`-like GUID data, handles Ctrl+N/Escape, and releases the queried interface.
- `decompile 0x00470240`: tiny clear thunk `unk_67AB94 = 0`.
- `get_bytes` around the xref instructions: constructor stores include `a3 94 ab 67 00` and `c7 05 94 ab 67 00 00...`; destructor/clear paths include `c7 05 94 ab 67 00 00...`; accelerator helper begins `a1 94 ab 67 00`.
- `make_signature_for_range`: returned nonunique `FF` signatures over the data range; treated as a tool limitation/historical file-view lead, not current initializer proof, because current byte/value APIs on the same session return zero.

Local/documentation evidence:

- Target and by-global pages route the exact storage through [UID:0000Q6] and Browser [UID:0000HV]; after Gate 2 repair, the target carries the formal C++ declaration and by-global carries a non-duplicating coverage comment plus `[[CHILDREN]]` insertion marker.
- `by-class/BrowserWindow.md` and `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md` document constructor/destructor global state, BrowserWindow vtable slices, and Browser source placement.
- `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md` documents this global as the retained BrowserWindow helper's active-object source and rejects the active BrowserControlPane route as a duplicate owner.
- Generated `Browser.cpp` command `000000006620` shows UID0000Q6 as a coverage comment pointing to UID0002T5, a UID0002T5 generated child block, and exactly one `static BrowserWindow *g_pActiveBrowserWindow;` declaration. Generated files were not manually edited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002T5-01 | UID0002T5 is exact four-byte `.data` storage at `0x0067ab94-0x0067ab98`, not code and not part of a larger source object. | High | Current MCP `ba171fe4` `lookup_funcs` says not a function; `get_bytes` confirms exact 4-byte slot; target path. | Target `Range`/`Summary`; validator `000000006489`. | incorporate | applied: target summary/evidence now records exact four-byte storage and non-code storage role with current `ba171fe4` proof. |
| C-0002T5-02 | Current active bytes/value are zero-filled; older `0xffffffff` initializer notes are historical/stale for current evidence. | High | Current MCP `ba171fe4` `get_bytes` and `get_global_value` return zero; prior `ddf5b602` is historical corroboration only. | Target Evidence; by-global Evidence; Browser.md singleton row; aggregate Evidence; validators `000000006489`, `000000006490`, `000000006494`, `000000006500`, current-session repair docs. | historicalize | applied: all edited docs label `0xffffffff`/`dword_67AB94` and stale current-session `ddf5b602` wording as historical or superseded for UID0002T5. |
| C-0002T5-03 | Current IDB source-facing symbol is not recovered: decompiler uses `unk_67AB94`, `g_pActiveBrowserWindow` is not found as a current global/name/type row. | High | Current MCP `ba171fe4` decompiles; `entity_query`; `type_query`; `get_global_value`. | Target Evidence; by-global Status/Evidence; Browser.md singleton row; aggregate row; validator batch. | incorporate | applied: active `unk_67AB94` and no recovered source symbol/UDT caveat recorded in target/support using `ba171fe4`; prior `ddf5b602` wording historicalized. |
| C-0002T5-04 | Constructor `0x00469640` publishes `this` to the slot or clears it on a sentinel/fallback path before BrowserWindow vtable/host setup. | High | MCP xrefs and decompile at `0x00469640`; bytes around `0x0046969a`. | Target Evidence; by-global Observed Evidence; BrowserWindow class sync; BrowserWindowCore already-present. | incorporate | applied: target/by-global/class include constructor publish/fallback-clear role; BrowserWindowCore already had constructor global-state evidence. |
| C-0002T5-05 | BrowserWindow destructor at `0x00469a20` clears the slot after BrowserWindow vtable restores and browser-object release. | High | MCP xrefs/decompile at `0x00469a20`; BrowserWindowCore docs. | Target Evidence; by-global Observed Evidence; BrowserWindow class sync; BrowserWindowCore already-present. | incorporate | applied: target/by-global/class include destructor clear role; BrowserWindowCore already had destructor global-state evidence. |
| C-0002T5-06 | Retained BrowserWindow accelerator helper `0x0046a510` reads the slot and uses `[g_pActiveBrowserWindow + 0x18/0x18 decimal 24]` as active browser-object source. | High | MCP decompile at `0x0046a510`; UID00020U docs; `get_bytes` at `0x0046a535`. | Target Evidence; accelerator support page; validator `000000006502`. | incorporate | applied: target records `+0x18` use and UID00020U now historicalizes `dword_67AB94` while preserving no-code helper policy. |
| C-0002T5-07 | Tiny thunk `0x00470240` clears the slot; it is evidence of lifecycle/reset behavior, not the declaration owner. | High | MCP decompile/bytes at `0x00470240`; xref list. | Target Evidence; by-global Observed Evidence; Browser.md singleton row. | incorporate | applied: clear-thunk role recorded as behavior evidence; no support doc was reowned to the thunk. |
| C-0002T5-08 | The successor `0x0067ab98` has separate xrefs and declaration route; there are no interior xrefs to `0x0067ab95-0x0067ab97`. | High | MCP `xrefs_to` interior and successor addresses. | Target Evidence; aggregate support row; Browser.md singleton row; successor page check. | incorporate | applied: target/Browser/aggregate record no interior refs and separate successor BrowserDialog storage; successor page already-present and not edited. |
| C-0002T5-09 | Source-facing type is `BrowserWindow *`. | High | Constructor/destructor vtable refs, BrowserWindow class/core docs, accelerator `+0x18` object read. | Target formal C++; by-global Type/Emission Model; BrowserWindow class note. | incorporate | applied: target formal C++ uses `BrowserWindow *`; support docs keep class as type/lifecycle evidence. |
| C-0002T5-10 | First-draft formal declaration should be `static BrowserWindow *g_pActiveBrowserWindow;` with no explicit initializer. | Medium-high | Zero bytes; all xrefs stay in Browser source-root code; BrowserThreadHost static precedent; no external consumer found. | Target `RECONSTRUCTION_CPP CODE`; by-global coverage comment plus `[[CHILDREN]]` source model; validators `000000006489`, `000000006593`. | incorporate | applied: target formal block contains exact declaration; by-global carries coverage comment plus child insertion marker to emit the target declaration without duplicating it. |
| C-0002T5-11 | Keep owner/emitter route through [UID:0000Q6] under Browser [UID:0000HV]. | High | Current metadata; by-global symbol page; Browser file source-root docs. | Target metadata; by-global support; Browser file support. | already-present | applied: target owner/emitter remained `0000Q6`; by-global owner/emitter remained Browser `0000HV`; Browser.md unchanged score. |
| C-0002T5-12 | Mixed aggregate UID0002AE remains non-emitting coverage index; exact UID0002T5 owns this slot's declaration route. | High | by-structure split; aggregate mixes Browser and WebBoardDialog slots; exact child exists. | Aggregate storage/evidence/reconstruction notes; validator `000000006500`. | incorporate | applied: aggregate row now points UID0002T5 to current `unk_67AB94`/historical `dword_67AB94` and stays non-emitting. |
| C-0002T5-13 | Generated Browser.cpp empty marker or coverage-only parent output is stale implementation state, not no-code evidence. | High | Historical generated command `000000006447`; supervisor failed fresh validation command `000000006590`; repaired `--wait-generated` command `000000006593`. | Generated freshness observation; by-global formal block; Target/Browser docs. | reject-stale | applied: current checked `Browser.cpp` no longer shows a UID0002T5 empty marker, shows UID0000Q6 coverage comment, expands the UID0002T5 child block, and contains exactly one `static BrowserWindow *g_pActiveBrowserWindow;`; no generated file was edited manually. |
| C-0002T5-14 | Recommended target metadata is `90/92`, reconstructable true, owner/emitter unchanged. | High | Complete bytes/xrefs/lifecycle/type/linkage decision; remaining exact source split cap. | Target metadata; validator `000000006489`. | incorporate | applied: target metadata is `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter unchanged, reconstructable true. |
| C-0002T5-15 | No IDA DB rename/type/comment mutation is requested by B004. | High | Supervisor constraints; evidence sufficient without mutation. | IDA Rename / Type / Comment Recommendations; implementation notes. | not-applicable | excluded-with-reason: no IDA DB edits were authorized or needed during callback. |

## Positive Evidence Summary

- Exact storage is one four-byte pointer slot at `0x0067ab94-0x0067ab98`.
- Current MCP byte/value APIs report zero-filled storage, so no explicit initializer is needed.
- Exactly five data xrefs touch the slot: constructor set/fallback clear, destructor clear, retained accelerator read, and tiny cleanup clear.
- No interior refs exist at `0x0067ab95-0x0067ab97`; successor `0x0067ab98` has its own separate BrowserDialog singleton refs.
- BrowserWindow constructor/destructor vtable evidence directly ties the slot to `BrowserWindow *`.
- Accelerator helper `0x0046a510` reads the slot as the active BrowserWindow and uses the object at `+0x18` for active browser/OLE accelerator handling.
- Browser source-root support pages already place BrowserWindow, its helpers, and browser globals under [UID:0000HV].

## IDA MCP Facts

- Function/range facts: `0x0067ab94` and `0x0067ab98` are not functions. Referenced functions are `sub_469640` size `0x3d7`, `0x00469a20` size `0x6a` with stale/misleading symbol `??1exception@boost@@MAE@XZ`, `sub_46A510` size `0x107`, and `sub_470240` size `0xb`.
- Data/table/padding facts: `0x0067ab80-0x0067aba4` currently reads as zero-filled writable pointer storage by `get_bytes`; target slot `u32le == 0`.
- Xref facts: five direct xrefs to target start; zero interior xrefs; separate successor refs at `0x0067ab98`.
- Vtable/global/type facts: decompiled constructor/destructor refs name `unk_67AB94` and BrowserWindow vtable symbols; no current `g_pActiveBrowserWindow` global/name/type row exists in MCP queries.
- Negative IDA facts: no function at the data address, no current source-quality IDA variable name, no local BrowserWindow UDT from `type_query`, no RVA pointer-pattern hit for `94 AB 27 00`, and no unmodeled VA pattern hits beyond the five known operand/xref sites.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067ab94-0x0067ab98` | [UID:0002T5] `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md` | Exact active BrowserWindow pointer storage | true | [UID:0000Q6] `g_pActiveBrowserWindow` | implemented `90/92` | Source declaration applied |
| `g_pActiveBrowserWindow` | [UID:0000Q6] `by-global/g_pActiveBrowserWindow.md` | Canonical symbol/support page for target storage | true | [UID:0000HV] Browser | implemented support sync `89/91` | Coverage/support page for exact target declaration |
| `0x0067ab90-0x0067aba4` | [UID:0002AE] `BrowserAndWebBoardDialogSingletons` | Mixed singleton coverage index | false | none | `88/92` | Keep non-emitting mixed index; historicalize target initializer wording |
| `0x00469640-0x0046a39c` | [UID:0000Z4] `BrowserWindowCore` | Constructor/destructor/core evidence owner | true | [UID:0000HV] Browser | `86/90` | Support page; not declaration owner |
| `0x0046a510-0x0046a617` | [UID:00020U] `BrowserWindowAcceleratorTranslateMessage` | Retained BrowserWindow accelerator helper that reads the slot | true | [UID:0000HV] Browser | `85/90` | Support page; not declaration owner |
| `0x0067ab98-0x0067ab9c` | [UID:0002WI] `g_pBrowserDialog` | Successor BrowserDialog singleton declaration | true | [UID:0000HV] Browser | `88/89` | Separate slot; external-linkage sibling but not proof UID0002T5 must be external |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004696a3` | data xref in `sub_469640` | Constructor stores `this`/constructor object value into `unk_67AB94`. |
| `0x004696aa` | data xref in `sub_469640` | Constructor fallback/sentinel branch clears `unk_67AB94`. |
| `0x00469a71` | data xref in `0x00469a20` BrowserWindow destructor body | Destructor clears active BrowserWindow global after vtable restore and browser object release. |
| `0x0046a535` | data xref in `sub_46A510` | Retained BrowserWindow accelerator helper reads the active BrowserWindow pointer. |
| `0x00470240` | data xref in `sub_470240` | Tiny Browser cleanup thunk clears the active BrowserWindow pointer. |
| `0x0067ab95-0x0067ab97` | no xrefs | Confirms no interior subslot/ref split. |
| `0x0067ab98` | ten separate xrefs | Successor BrowserDialog singleton; not part of UID0002T5. |

## Documentation Evidence And IDA Status

Current docs that support the conclusion:

- Target page states this is exact `g_pActiveBrowserWindow` storage, routes it to [UID:0000Q6], and contains the formal `static BrowserWindow *g_pActiveBrowserWindow;` declaration.
- By-global page [UID:0000Q6] identifies BrowserWindow constructor/destructor behavior, active accelerator helper behavior, current `unk_67AB94` evidence, and the coverage-comment route to UID0002T5.
- BrowserWindow class/core pages document BrowserWindow constructor/destructor, vtable slices, Browser source placement, and global state.
- UID00020U accelerator helper page records `g_pActiveBrowserWindow + 0x18` behavior, now labels `dword_67AB94` as historical for current `unk_67AB94`, and rejects BrowserControlPane/Application route confusion.
- Browser source-root page [UID:0000HV] now lists UID0002T5 as an accepted source-emitting Browser module global declaration, while preserving Browser.cpp versus split BrowserWindow source/header caveat.

Historical pre-callback docs that were stale/incomplete and are now repaired:

- Target, by-global, Browser file, accelerator helper, and aggregate pages had older `0xffffffff`/`dword_67AB94` or provisional-linkage language. The edited docs now historicalize that wording for UID0002T5.
- By-global page previously said generated owner file `class_BrowserWindow.cpp` and kept `static` provisional. It now routes through Browser and records that the target emits the declaration while by-global carries a coverage comment plus `[[CHILDREN]]` marker.
- Historical generated Browser.cpp command `000000006447` had UID0002T5/UID0000Q6 empty markers. Supervisor validation command `000000006590` proved the first callback state was still generated-incomplete because the file stopped at the UID0000Q6 coverage comment. B004 command `000000006593` repaired the generator route, and current command `000000006620` still has no UID0002T5 empty marker, shows UID0000Q6 coverage, expands UID0002T5, and emits the static declaration exactly once.

Generated/coverage state:

- `auto-generated/NexusTK/browser/Browser.cpp` header: validator-command-id `000000006620`, refreshed `2026-07-04T21:00:37-04:00`.
- UID0002T5 does not appear as an empty marker in the checked generated snapshot. UID0000Q6 appears as `Completion:89 | Confidence:91` with a coverage comment pointing to UID0002T5, followed by the UID0002T5 generated block and exactly one `static BrowserWindow *g_pActiveBrowserWindow;` declaration. Generated refresh completed through the scoped by-global validator with `--wait-generated`; no generated file was hand-edited.

## Ranked Ownership Analysis

### 1. [UID:0000Q6] g_pActiveBrowserWindow by-global page under Browser

- Evidence for: target already uses [UID:0000Q6] as canonical owner/emitter; the by-global page is the narrow symbol record; Browser file parent is qualified and source-root consistent; exact storage belongs to this symbol.
- Evidence against: historical pre-callback state had blank by-global formal C++ and generated output that marked [UID:0000Q6] and [UID:0002T5] as empty. The first callback state fixed the docs but lacked the explicit by-global `[[CHILDREN]]` marker, so supervisor validation command `000000006590` still generated only the UID0000Q6 coverage comment. Current repaired state has by-global [UID:0000Q6] carrying a coverage comment plus insertion marker, target [UID:0002T5] emitting the declaration, and checked generated `Browser.cpp` including the UID0002T5 block and static declaration exactly once.
- Decision: keep [UID:0000Q6] as canonical owner/emitter route. Exact storage target carries the formal declaration and by-global carries the coverage/support comment plus child insertion marker to avoid duplicate definitions while making generator output complete.

### 2. [UID:0000HV] Browser file/source root

- Evidence for: all proven users are in Browser/BrowseWindow source-root code; sibling Browser globals emit here; BrowserWindow class/routes already sit under Browser.
- Evidence against: exact original source may have been split into `BrowserWindow.cpp`; the project currently uses broad Browser root for the family.
- Decision: use Browser source root now. Preserve source split caveat as confidence cap.

### 3. [UID:00001B] BrowserWindow class

- Evidence for: stored object is a BrowserWindow; constructor/destructor vtable refs prove class identity; retained accelerator helper is BrowserWindow-specific.
- Evidence against: class owns object methods, not process/module-level storage declaration; current metadata points to by-global symbol page; similar globals route through Browser/global pages.
- Decision: support/type owner only, not canonical declaration owner.

### 4. [UID:0002AE] mixed singleton aggregate

- Evidence for: target is one slot inside its range.
- Evidence against: aggregate crosses Browser and WebBoardDialog ownership and is marked `RECONSTRUCTABLE:FALSE`; exact children are required by split policy.
- Decision: reject as emitter/owner; keep as non-emitting coverage index.

### 5. Function/helper writers such as UID0000Z4, UID00020U, and `sub_470240`

- Evidence for: they write/read/clear the slot.
- Evidence against: writers/consumers do not own the declaration; `0x0046a510` is itself retained/no-caller, and `0x00470240` is a tiny clear thunk.
- Decision: support evidence only.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Use current Browser source root `NexusTK/browser/Browser.cpp` and optional future `BrowserWindow.cpp`/private header only as source-tree follow-up.
- Likely full contents: Browser globals and BrowserWindow class/helper declarations already grouped under Browser docs.
- Candidate related items that belong: [UID:0000Q6], [UID:0002T5], BrowserWindow constructor/destructor/core, BrowserWindow retained accelerator helper, BrowserWindow host WndProc, BrowserWindow class string.
- Candidate related items rejected: WebBoardDialog singletons in the same aggregate, BrowserDialog singleton successor as a separate global, BrowserControlPane active globals.
- Standalone/narrow/broad inference: narrow exact global declaration under broad Browser root.

## Source Placement

Recommended source placement: Browser module, currently `NexusTK/browser/Browser.cpp`, through exact target storage [UID:0002T5] and symbol page [UID:0000Q6].

Why this placement fits: all current uses are BrowserWindow/BrowseWindow helper code; Browser file parent already owns BrowserWindow, BrowserThread/static globals, BrowserDialog globals, and browser COM host helpers. The `static` declaration aligns with file-local Browser module state for current evidence.

Rejected placements:

- `BrowserWindow` class static member: no evidence of class static syntax, and by-global/page model records process/module storage.
- Application/global root: no Application direct xrefs found.
- BrowserControlPane or BrowserPane: related active browser paths use different globals (`g_activeBrowserControlPane`, `g_activeBrowserPane`).
- WebBoardDialog: successor/mixed aggregate neighbors include web-board globals, but UID0002T5 xrefs are BrowserWindow-only.

Remaining placement uncertainty: if the final source tree splits BrowserWindow into a separate source file while keeping helper code elsewhere, the exact linkage may move to a private header/accessor. Current evidence still supports file-local Browser-root storage as the first draft.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target is exactly `0x0067ab94-0x0067ab98`, four bytes. The previous slot `0x0067ab90-0x0067ab94` is BrowserDialogOld storage, and successor `0x0067ab98-0x0067ab9c` is BrowserDialog storage.
- Children/subranges: no split needed. Interior addresses `0x0067ab95-0x0067ab97` have zero xrefs; successor `0x0067ab98` has its own separate ten-ref inventory.
- Padding/table/data/code distinctions: this is writable zero-filled pointer storage, not code, padding, vtable, RTTI, jump table, or resource data.
- Parent/container impact: aggregate [UID:0002AE] remains non-emitting mixed coverage index. UID0002T5 is the exact source declaration route for this one Browser-owned slot.

## Negative Evidence Summary

- No current MCP name/global/type row proves the exact original symbol or UDT.
- No function exists at `0x0067ab94`; it is data only.
- No xrefs to interior bytes `0x0067ab95-0x0067ab97`.
- No RVA pattern `94 AB 27 00` hits; VA pattern hits are exactly the five modeled operand/xref sites.
- No external/Application consumer was found for this slot, unlike `g_activeBrowserPane`.
- Do not use successor `0x0067ab98` xrefs to justify UID0002T5 external linkage; that is a separate BrowserDialog global.
- The signature helper's `FF` output is not accepted as current initializer proof because current byte/value APIs on the same active session return zero.
- Constructor/destructor/cleanup sites are lifecycle evidence, not declaration-owner evidence.
- The retained BrowserWindow accelerator helper reads this global but has no live caller/table route; that does not block the storage declaration.

## IDA Rename / Type / Comment Recommendations

Proposed source-facing names/types/comments:

- Source-facing variable name: `g_pActiveBrowserWindow`.
- Source-facing type: `BrowserWindow *`.
- Optional future IDA data rename: `unk_67AB94` -> `g_pActiveBrowserWindow`.
- Optional future IDA type/comment: pointer data item with a comment such as `Active BrowserWindow singleton; constructor publishes, destructor/cleanup clear, retained accelerator helper reads +0x18 browser object.`

Evidence:

- Name is established by current target/by-global docs and BrowserWindow singleton role.
- Type is supported by BrowserWindow vtable stores in constructor/destructor and `[global + 0x18]` BrowserWindow member use in the accelerator helper.
- Current MCP `entity_query` and `type_query` return no active IDB global/type rows, so the name/type remain source-quality reconstruction rather than recovered debug information.

Items intentionally left unchanged:

- No IDA DB mutation was requested in the historical report-only phase or authorized during the implementation callback.
- Do not rename `sub_470240` as the owner of the global; it is only a clear thunk.
- Do not force a BrowserWindow UDT in IDA before a broader COM layout/type pass.
- Do not apply `static` as an IDA type concept; it is source-linkage reasoning, not a database data type.

IDA DB edits were not requested in the historical report-only phase and were not authorized during this implementation callback.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. This is source-declared/generated-binary global pointer storage, and the source declaration is now evidence-ready.

Applied code: the target formal block now contains this exact declaration:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static BrowserWindow *g_pActiveBrowserWindow;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact original behavior: static/global zero initialization produces the current `0` storage value; constructor/destructor/cleanup code writes the runtime pointer/reset values; no explicit nonzero initializer is needed.

Reason it matches plausible original source shape: a file-local browser module pointer for the current active embedded browser host window is a natural late-1990s/early-2000s C++ module-global pattern, especially when all observed refs stay inside Browser/BrowserWindow support code.

Inferred source-facing names/types/fields used instead of IDA/decompiler labels: use `BrowserWindow` and `g_pActiveBrowserWindow` instead of `unk_67AB94`, `dword_67AB94`, or `LONG`.

Naming/coding style convention: project Browser globals use `g_`/`g_p` names and pointer spacing such as `BrowserPane *g_activeBrowserPane;`, `static BrowserThread *g_pBrowserThread;`, and `BrowserDialog *g_pBrowserDialog;`. Use `static BrowserWindow *g_pActiveBrowserWindow;` to match that local style.

Reason code should remain blank: not applicable. The prior blank state was caused by unresolved initializer/linkage proof and is now resolved to an applied first-draft declaration with explicit confidence cap.

Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

Current applied disposition: UID0002T5 is implemented and ready for supervisor Gate 2 re-review. The target is source-ready exact singleton storage with formal C++ `static BrowserWindow *g_pActiveBrowserWindow;`, current zero-byte evidence, exact five-xref inventory, active IDB name/type caveats, synchronized support docs, and current generated Browser.cpp output containing the UID0002T5 declaration. Agent-B004 ran only scoped file validators and did not run `execute_report`, registry lifecycle commands, report moves, manual generated/coverage edits, or supervisor-ledger edits.

Exact parent assignments applied: kept [UID:0000Q6] as canonical owner/emitter and Browser [UID:0000HV] as source root. The target was not reassigned directly to BrowserWindow class or mixed aggregate.

Exact items left no-owner/non-emitting: mixed aggregate UID0002AE stays non-emitting and reconstructable false; it is a coverage index only.

Future work outside this assignment: broader Browser source split/header pass may decide whether BrowserWindow receives a separate `.cpp`/private header, and an IDA type pass may eventually define a BrowserWindow UDT. Neither blocks this target declaration.

## Recommended Target Doc Changes

Target path: `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md`.

Current applied target doc facts:

- Current MCP session `ba171fe4`, active path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, and server-health evidence are recorded; prior `ddf5b602` wording is historical only.
- Exact zero-filled bytes/value at `0x0067ab94` are recorded; older `0xffffffff` initializer wording is historicalized.
- The slot and successor are documented as non-functions.
- The exact five data refs are recorded: `0x004696a3`, `0x004696aa`, `0x00469a71`, `0x0046a535`, `0x00470240`.
- No interior refs to `0x0067ab95-0x0067ab97` are recorded; successor `0x0067ab98` is documented as separate BrowserDialog storage.
- Constructor publish/fallback-clear, destructor clear, accelerator helper `+0x18` / decimal `24` read, and tiny clear-thunk behavior are documented.
- Current IDB `unk_67AB94`, absent recovered `g_pActiveBrowserWindow` global/name/type row, and inferred source-facing name/type caveats are recorded.
- VA byte-pattern and RVA negative evidence are preserved.
- The nonunique `FF` data-range signature caveat is preserved as historical/tool-caveat evidence, not current initializer proof.

Current applied metadata/score/owner/emitter/reconstructable/C++ state:

- `COMPLETION:90`, `CONFIDENCE:92`.
- `CANONICAL_OWNER:0000Q6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000Q6`, blank optional position retained.
- Formal C++ block contains `static BrowserWindow *g_pActiveBrowserWindow;`.

Historical/stale assumptions and negative evidence preserved:

- Older `dword_67AB94` and `0xffffffff` initializer notes are historical.
- Do not claim recovered original name/UDT proof.
- Do not use mixed aggregate, BrowserWindow class, retained accelerator helper, or clear thunk as declaration owner.

## Recommended Support Doc Changes

Support path: `by-global/g_pActiveBrowserWindow.md`.

- Applied: active proof now cites MCP session `ba171fe4`, zero-filled bytes, five xrefs, active `unk_67AB94`/no-current-source-name caveat, and exact declaration readiness; prior `ddf5b602` evidence is historicalized.
- Applied: provisional linkage wording is replaced with the current model where exact storage [UID:0002T5] emits the first-draft static definition.
- Applied: formal coverage comment plus `[[CHILDREN]]` insertion marker points to [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md); by-global does not duplicate the target declaration and now generator-expands the child block.
- Applied: support metadata is `COMPLETION:89`, `CONFIDENCE:91`.

Support path: `by-file/Browser.md`.

- Applied: UID0002T5/[UID:0000Q6] is described as an accepted source-ready Browser module global declaration, not a near-term empty-emitter blocker.
- Applied: current MCP session `ba171fe4`, zero initialization, five xrefs, static declaration, and remaining Browser.cpp versus split BrowserWindow source caveat are documented; prior `ddf5b602` evidence is historicalized.
- Applied: Browser file score remains unchanged.

Support path: `by-class/BrowserWindow.md`.

- Applied: narrow note states UID0002T5 owns the source declaration for active BrowserWindow singleton storage, while BrowserWindow constructor/destructor are lifecycle/type evidence and not direct declaration ownership. Source-root split caveat remains.

Support path: `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`.

- Already-present / not edited: BrowserWindowCore already documented constructor/destructor global-state evidence at same-or-greater route detail, and it does not emit the global declaration.

Support path: `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`.

- Applied: helper reads source-facing `g_pActiveBrowserWindow`, current IDB `unk_67AB94` / historical `dword_67AB94`, and this report resolves the storage declaration. Retained helper itself remains blank/no-call-route.

Support path: `by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md`.

- Applied: UID0002T5 row now records current `unk_67AB94` / historical `dword_67AB94`, zero-filled current evidence, exact five refs, and exact-child declaration route. Aggregate remains a non-emitting mixed coverage index.

Support path: `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md`.

- Already-present / not edited: successor BrowserDialog storage already documents the separate `0x0067ab98` singleton and zero-initialized state, so no boundary repair was needed.

Generated output:

- Applied/check recorded: generated Browser.cpp was not edited manually. Supervisor validation command `000000006590` proved the first callback state was coverage-only and missing the child declaration. B004 repaired the by-global child marker with scoped validator `000000006593`; current generated command `000000006620` still shows UID0000Q6 as a non-duplicate coverage comment, UID0002T5 as a generated child block, and `static BrowserWindow *g_pActiveBrowserWindow;` exactly once.

## Score And Metadata Recommendation

| Field | Historical pre-callback state | Current post-callback state | Rationale |
| --- | ---: | ---: | --- |
| Target `COMPLETION` | 86 | 90 | Exact storage, current zero bytes, five direct refs, lifecycle roles, type, linkage, owner route, support sync, and formal declaration are documented. |
| Target `CONFIDENCE` | 88 | 92 | Current MCP evidence resolves initializer/xref/type route; confidence remains below final audit because exact original source split/linkage and IDA UDT/global name are not recovered. |
| Target `CANONICAL_OWNER` | `0000Q6` | `0000Q6` | Direct by-global symbol page remains the narrow owner. |
| Target `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source declaration required and applied. |
| Target `EMITTER_UIDS` | `0000Q6` | `0000Q6` | Existing direct symbol route under Browser is preserved. |
| Target optional position | blank | blank | No ordering override needed. |
| By-global support `COMPLETION` | 86 | 89 | Support page now records active proof, coverage-comment route, and exact target declaration ownership. |
| By-global support `CONFIDENCE` | 88 | 91 | Support confidence rises with current zero-byte/five-xref evidence while retaining source-split/name/type caps. |

Score-improvement attempts:

- Initializer: checked current bytes/ints/global value and resolved stale `0xffffffff` note.
- Xrefs/reachability: checked start, interior, successor, VA/RVA patterns, and decompiled all five xref functions.
- Type/name: checked current IDA name/global/type catalogs and resolved source-facing name/type by behavior/docs.
- Linkage: compared all refs and neighboring emitted Browser globals; chose `static` with source-split cap.
- Owner/source placement: ranked by-global, Browser file, BrowserWindow class, aggregate, and helper writers.
- C++ readiness: exact formal block is present in the target; blank state is no longer justified.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Remaining impact | Future evidence needed |
| --- | --- | --- | --- |
| Is the current initializer zero or `0xffffffff`? | Current MCP session `ba171fe4` `get_bytes 0x0067ab94 size 4` returns four zero bytes, and `get_global_value 0x0067ab94` / `unk_67AB94` return `0x0`. Prior `ddf5b602` zero evidence is historical corroboration only; the older signature helper `FF` result remains unsuitable for current data-initializer proof. | No explicit initializer; historicalize older `0xffffffff`. | Supervisor/tool follow-up only if validator disputes the current byte/value APIs. |
| Is exact source name recovered? | `entity_query`/`get_global_value` found no `g_pActiveBrowserWindow`; decompiler uses `unk_67AB94`. | Name is inferred/source-facing, not debug-recovered. Confidence cap only. | Future IDA rename/type pass if approved. |
| Should declaration be static or external? | All five xrefs stay in BrowserWindow/Browser helper code; no external/Application consumer found; BrowserThreadHost static precedent supports static. | Use `static` now; keep source split cap. | A future browser source-tree/header pass proving cross-file use. |
| Should target or by-global emit? | Existing target has exact storage and by-global owner. Pattern from `g_pBrowserDialogOld` proves the generator-compatible route: exact storage emits the declaration and by-global carries a coverage comment plus `[[CHILDREN]]` marker. | Resolved in Gate 2 repair: target formal block remains the declaration owner; by-global has the child insertion marker and does not duplicate code. | None for this callback; future source split work may still revisit true file-local versus private-header linkage. |
| Does retained accelerator helper block declaration? | No. It is only a consumer of the global; its own no-caller policy remains separate. | None for storage declaration. | Separate UID00020U source policy if desired. |

No unresolved question requires keeping the target blank. Remaining uncertainty caps score at `90/92`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. This report does not request manual edits to any `-coverage-report.md` or validator-owned generated tracker. The source target/support docs were updated through the accepted implementation callback and scoped validators only; generated reports refreshed from validator output only.

## Follow-Up Actions

- Supervisor actions: verify callback results and run supervisor-owned execution after Gate 2 approval.
- A-agent actions: none requested.
- B004 future research actions: none unless supervisor requests a follow-up Browser source split/header pass or report-text repair.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `90/92`; not higher because exact original linkage, final source split, and recovered IDA UDT/global name remain unavailable.
- Remaining uncertainty: whether original source used true file-local `static` in one broad `Browser.cpp` or a private declaration in a split BrowserWindow source/header. Current evidence supports `static` as best first draft.

## Validator Results

- Target validator: `python .\tools\validator.py --mode file --file by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md --apply --queue-timeout 240`; command_id `000000006489`; timestamp `2026-07-04T19:19:38-04:00`; exit `0`; `ok: 1`; completion/confidence updated to `90/92`; registry hash updated; generated_refresh `deferred`.
- By-global validator: `python .\tools\validator.py --mode file --file by-global/g_pActiveBrowserWindow.md --apply --queue-timeout 240`; command_id `000000006490`; timestamp `2026-07-04T19:19:46-04:00`; exit `0`; `ok: 1`; completion/confidence updated to `89/91`; validator inserted missing UID0002T5 link; generated_refresh `deferred`.
- Browser file validator: `python .\tools\validator.py --mode file --file by-file/Browser.md --apply --queue-timeout 240`; command_id `000000006494`; timestamp `2026-07-04T19:20:00-04:00`; exit `0`; `ok: 1`; warnings: existing `missing_ref_uid` warnings for unrelated Browser child UIDs (`000408`, `00040B`, `0003OH`, `000407`, `000409`, `00040A`, `00040C`, plus five suppressed); generated_refresh `deferred`.
- BrowserWindow class validator: `python .\tools\validator.py --mode file --file by-class/BrowserWindow.md --apply --queue-timeout 240`; command_id `000000006498`; timestamp `2026-07-04T19:20:10-04:00`; exit `0`; `ok: 1`; validator inserted missing UID links/reference index entries; generated_refresh `deferred`.
- Aggregate validator: `python .\tools\validator.py --mode file --file by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md --apply --queue-timeout 240`; command_id `000000006500`; timestamp `2026-07-04T19:20:18-04:00`; exit `0`; `ok: 1`; generated_refresh `deferred`.
- Accelerator support validator: `python .\tools\validator.py --mode file --file by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md --apply --queue-timeout 240`; command_id `000000006502`; timestamp `2026-07-04T19:20:29-04:00`; exit `0`; `ok: 1`; validator added UID0002T5 reference index entry; generated_refresh `deferred`.
- Supervisor Gate 2 fresh validation failure evidence: supervisor command `000000006590` with `--wait-generated` refreshed `auto-generated/NexusTK/browser/Browser.cpp` but produced only the UID0000Q6 coverage comment for this route, with no UID0002T5 generated block and no `static BrowserWindow *g_pActiveBrowserWindow;` declaration.
- Gate 2 repair validator: `python .\tools\validator.py --mode file --file by-global/g_pActiveBrowserWindow.md --apply --queue-timeout 240 --wait-generated`; command_id `000000006593`; timestamp `2026-07-04T20:42:58-04:00`; exit `0`; `ok: 1`; important warnings/side effects: `autogen_children_fallback_insert: 16`, `autogen_children_marker_missing: 84`, `autogen_emitter_has_no_code: 222`, `autogen_cpp_update: 1`, `autogen_registry_update: 1`, `autogen_registry_rebuild: 1`, `generated_metadata_refresh: 282`, `projected_stats_update: 1`, and `generated_refresh: completed`.
- Current-session MCP evidence repair: JSON-RPC tool calls on session `ba171fe4` covered `idb_list`, `server_health`, `get_bytes`, `get_global_value`, `xrefs_to`, `lookup_funcs`, `entity_query`, `type_query`, `find_bytes`, and targeted `decompile` calls for `0x00469640`, `0x00469a20`, `0x0046a510`, and `0x00470240`. No MCP mutation/process-management tools were used.
- Current-session target validator: `python .\tools\validator.py --mode file --file by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md --apply --queue-timeout 240`; command_id `000000006608`; timestamp `2026-07-04T20:58:20-04:00`; exit `0`; `ok: 1`; generated_refresh `deferred`; projected stats update only.
- Current-session by-global validator: `python .\tools\validator.py --mode file --file by-global/g_pActiveBrowserWindow.md --apply --queue-timeout 240 --wait-generated`; command_id `000000006609`; timestamp `2026-07-04T20:58:22-04:00`; exit `0`; `ok: 1`; generated_refresh `completed`; side effects included `autogen_cpp_update: 1`, `autogen_report_update: 1`, `memory_auto_coverage_update: 1`, `research_tracker_update: 1`, `autogen_registry_rebuild: 1`, and recurring unrelated generator warnings (`autogen_children_marker_missing`, `autogen_emitter_has_no_code`).
- Current-session Browser file validator: `python .\tools\validator.py --mode file --file by-file/Browser.md --apply --queue-timeout 240`; command_id `000000006610`; timestamp `2026-07-04T20:58:37-04:00`; exit `0`; `ok: 1`; existing unrelated `missing_ref_uid: 15` warnings for Browser child UIDs; generated_refresh `deferred`.
- Current-session BrowserWindow class validator: `python .\tools\validator.py --mode file --file by-class/BrowserWindow.md --apply --queue-timeout 240`; command_id `000000006611`; timestamp `2026-07-04T20:58:39-04:00`; exit `0`; `ok: 1`; generated_refresh `deferred`; stats rows updated for UID00001B.
- Current-session aggregate validator: `python .\tools\validator.py --mode file --file by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md --apply --queue-timeout 240`; command_id `000000006612`; timestamp `2026-07-04T20:58:49-04:00`; exit `0`; `ok: 1`; generated_refresh `deferred`.
- Current-session accelerator support validator: `python .\tools\validator.py --mode file --file by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md --apply --queue-timeout 240`; command_id `000000006613`; timestamp `2026-07-04T20:58:57-04:00`; exit `0`; `ok: 1`; generated_refresh `deferred`.
- Generated freshness after the generated-emitter repair: `auto-generated/NexusTK/browser/Browser.cpp` reported validator-command-id `000000006593`, refreshed `2026-07-04T20:42:58-04:00`, and contained UID0002T5 plus exactly one declaration.
- Current generated freshness after the MCP-session wording repair validators and validator-owned background refresh: `auto-generated/NexusTK/browser/Browser.cpp` header now reports validator-command-id `000000006620`, refreshed `2026-07-04T21:00:37-04:00`. The checked snapshot shows UID0000Q6 coverage comment pointing to UID0002T5, immediately followed by UID0002T5 generated child block and exactly one `static BrowserWindow *g_pActiveBrowserWindow;` declaration. No generated files were edited manually.

## Changed Files

- Modified by B004 callback:
  - `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md`
  - `by-global/g_pActiveBrowserWindow.md`
  - `by-file/Browser.md`
  - `by-class/BrowserWindow.md`
  - `by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md`
  - `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`
  - `tools/leaser/Agents/Agent-B004/research/0002T5-g_pActiveBrowserWindow-source-quality.md`
- Gate 2 repair delta:
  - `by-global/g_pActiveBrowserWindow.md` received the explicit `[[CHILDREN]]` insertion marker and prose sync.
  - `tools/leaser/Agents/Agent-B004/research/0002T5-g_pActiveBrowserWindow-source-quality.md` records the repair, validator command, generated proof, ledger, and checklist update.
- Current-session stale-MCP repair delta:
  - `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md`, `by-global/g_pActiveBrowserWindow.md`, `by-file/Browser.md`, `by-class/BrowserWindow.md`, `by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md`, and `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md` now cite current MCP session `ba171fe4` for UID0002T5 or clearly label `ddf5b602` as historical.
  - This report now records the `ba171fe4` MCP evidence pass, current validators `000000006608`-`000000006613`, and current generated Browser.cpp header `000000006620`.
- Validator side effects from authorized scoped validators:
  - `auto-generated/NexusTK/browser/Browser.cpp` refreshed to command `000000006620`; it now includes the UID0002T5 block and static declaration.
  - `tools/validator.ini` registry/hash/reference state updated by scoped validators.
  - `project-level/-auto-completion-stats.md` projected/stat rows updated by scoped validators.
  - Generated coverage reports and generated C++ metadata refreshed by validator commands including `000000006609`, `000000006611`, and background refresh `000000006620`.
- Renamed: none.
- Already-present / not edited: `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md` already documented the separate successor BrowserDialog slot and zero-initialized state; `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md` already documented constructor/destructor global-state evidence. BrowserDialog support did not need boundary repair.
- Leases: B004 leased the six original callback by-* docs immediately before editing. Release attempt after validators succeeded for the accelerator page and returned `Rejected[No active lease]` for the other five, indicating no active lease remained by release time. For the generated-emitter repair, B004 leased `by-global/g_pActiveBrowserWindow.md`, edited and validated it, then released it successfully. For the current-session stale-MCP repair, B004 leased all six affected by-* docs, edited and validated them, then attempted release; each release returned `Rejected[No active lease]`, and the shared lease report then showed no active leases.
- Report execution: not run by B004. Agent-B004 did not run `execute_report`, dry-run/probe variants, lifecycle/archive commands, registry commands, or manual report moves.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: Gate 1 passed for SHA256 `8F4B8C8F151AF6FFC99BE632269B562B860C7F7FF57A78289AF711DD1F4DEDD3`.
- [x] Target doc updated: `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md`.
- [x] Target metadata applied: `COMPLETION:90`, `CONFIDENCE:92`; kept `CANONICAL_OWNER:0000Q6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000Q6`, blank optional position.
- [x] Target formal C++ inserted exactly: `static BrowserWindow *g_pActiveBrowserWindow;`.
- [x] Target evidence incorporated and refreshed: current MCP session `ba171fe4`, zero bytes/value, five xrefs, no interior refs, separate successor refs, no current source-name/type row, constructor/destructor/accelerator/clear-thunk details, VA/RVA pattern results, and historical data-range signature caveat. Prior `ddf5b602` evidence is kept only as historical corroboration.
- [x] Historical/stale assumptions preserved as superseded: older `dword_67AB94`/`0xffffffff` initializer wording and blank-C++ linkage blocker.
- [x] Rejected alternatives preserved: no-code/blank, external by default, explicit initializer, raw `DWORD`/`void *`, Browser class/BrowserPane/BrowserControlPane/WebBoardDialog ownership, mixed aggregate emission, helper/thunk declaration ownership, and recovered original-name claim.
- [x] Required support sync applied: `by-global/g_pActiveBrowserWindow.md` active evidence/linkage/coverage comment, `[[CHILDREN]]` insertion marker, and support score `89/91`.
- [x] Stale support sync applied where needed: `by-file/Browser.md`, `by-class/BrowserWindow.md`, `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`, and `by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md`.
- [x] Already-present support recorded: `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md` and `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md` did not require edits.
- [x] Generated output checked after Gate 2/current-session repair: `auto-generated/NexusTK/browser/Browser.cpp` command `000000006620` shows no UID0002T5 empty marker, includes UID0000Q6 coverage comment pointing to UID0002T5, immediately emits UID0002T5, and contains exactly one `static BrowserWindow *g_pActiveBrowserWindow;`.
- [x] Scoped validators run for each changed by-* file: original callback command IDs `000000006489`, `000000006490`, `000000006494`, `000000006498`, `000000006500`, `000000006502`; generated-emitter repair command ID `000000006593` with `--wait-generated`; current-session wording repair command IDs `000000006608` through `000000006613`.
- [x] Claim And Incorporation Ledger updated with `applied`, `already-present`, and `excluded-with-reason` proof for all claims.
- [x] No generated files, manual coverage reports, validator state, lifecycle state, supervisor ledgers, or report moves edited/run by B004.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Validators run and results recorded.
- [x] Generated refresh/freshness checked and recorded.
- [x] Remaining unapplied accepted items: none. IDA DB rename/type/comment mutation excluded because it was not requested or authorized.

Gate 2 repair pass:

- [x] Investigated supervisor failure: command `000000006590 --wait-generated` proved current generated Browser.cpp lacked the UID0002T5 block/declaration despite target formal C++.
- [x] Compared local generator-compatible Browser globals and found `by-global/g_pBrowserDialogOld.md` uses the formal coverage comment plus `[[CHILDREN]]` marker while still avoiding duplicate declarations.
- [x] Repaired the minimum by-* file: `by-global/g_pActiveBrowserWindow.md` now has the same non-duplicating child insertion marker and prose sync.
- [x] Ran scoped validator with `--wait-generated`: command `000000006593`, timestamp `2026-07-04T20:42:58-04:00`, exit `0`, `ok: 1`, generated_refresh `completed`.
- [x] Verified generated Browser.cpp current output: command `000000006620` contains UID0000Q6 coverage, UID0002T5 child block, exactly one static declaration, and no duplicate declarations.
- [x] Updated Claim And Incorporation Ledger, Current Target State, Recommended Support Doc Changes, Validator Results, Changed Files, and this checklist with the repair delta.

Current-session stale-MCP repair pass:

- [x] Revalidated UID0002T5 facts on active MCP session `ba171fe4`: health/path, zero bytes/value, five refs, no interior refs, separate successor refs, targeted decompiles, no recovered source symbol/UDT, and VA/RVA pointer-pattern evidence.
- [x] Historicalized prior `ddf5b602` current-session wording in the report and six affected by-* docs.
- [x] Preserved generated-emitter repair: target formal C++, by-global `[[CHILDREN]]`, and generated Browser.cpp UID0002T5 block.
- [x] Ran scoped validators for all changed by-* docs: `000000006608`, `000000006609`, `000000006610`, `000000006611`, `000000006612`, and `000000006613`.
- [x] Verified current generated Browser.cpp output: command `000000006620`, UID0000Q6 coverage, UID0002T5 child block, exactly one static declaration.
- [x] Leases released/cleared: final shared lease report shows no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000006631","destination_path":"executed-b-agent-research/B004/0002T5-g_pActiveBrowserWindow-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002T5-g_pActiveBrowserWindow-source-quality.md","timestamp":"2026-07-04T21:07:53-04:00","uid":"0002T5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
