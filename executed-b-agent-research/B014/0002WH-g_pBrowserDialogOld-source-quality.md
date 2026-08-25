** TARGET-REPORT-UID:0002WH **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0002WH g_pBrowserDialogOld Source-Quality Report

## Finalized Report / Current Recommendation

Current recommendation: UID0002WH has been implemented by B014 as a source-ready Browser module global declaration for the legacy browser dialog singleton storage at `by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md`.

Final disposition: source-authored global storage declaration, not a no-code artifact. The current IDB has no recovered source-quality variable name or UDT, but MCP-backed bytes, xrefs, constructor/destructor behavior, sibling global precedent, and support docs are strong enough for a first-draft source declaration.

Implementation disposition: the target by-memory page is now `COMPLETION:90`, `CONFIDENCE:92`, with `CANONICAL_OWNER:0000QB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QB`, blank optional position, and the formal C++ block below. Support docs now historicalize the older `0xffffffff` initializer and `static`-linkage blocker while keeping the Browser source-root caveat as a confidence cap. B014 did not run `execute_report`; supervisor owns later execution/archive.

Confidence: high for address, bytes, lifecycle, consumers, type family, owner route, and no explicit initializer; medium-high for final original linkage spelling because the current source tree may still split legacy Browser code later.

## Supporting Research

Historical report-only pass: the original Gate 1 artifact for UID0002WH did not edit target/support by-* docs, generated files, coverage reports, validator state, report lifecycle/archive state, or supervisor ledgers, and did not run validators or lifecycle/archive commands.

Current implementation callback: B014 edited the accepted target/support by-* docs only, used scoped file validators for every changed by-* doc, and used validator-owned generated refresh to check `auto-generated/NexusTK/browser/Browser.cpp`. B014 did not manually edit generated files, coverage reports, validator state, report lifecycle/archive state, supervisor ledgers, or run `execute_report`, dry-run/probe execute variants, or lifecycle/archive commands.

Local search covered current Agent folders, executed B-agent reports, relevant by-* docs, and generated Browser output for `0002WH`, `g_pBrowserDialogOld`, `0x0067ab90`, `BrowserDialogOld`, `g_pBrowserDialog`, and Browser source-family terms. Before this report, no direct B-agent report named for UID0002WH existed. The strongest prior leads were:

- Executed B002 `0000HV-Browser-empty-emitter-family-source-quality.md`: states `0x0067ab90..0x0067ab9f` was zero-initialized and leaves UID0002WH as "near-term declaration after linkage decision."
- Executed B010 `00033B-BrowserDialogOldScalarDeletingDestructor-source-quality.md`: classifies the scalar deleting destructor as no-code wrapper glue and preserves UID0002WH as the singleton storage/source declaration route.
- Executed B013 `0000Z3-BrowserDialogOldCore-source-quality.md`: anchors BrowserDialogOld constructor/destructor behavior and the old-dialog source owner relation.
- Executed B007 `0002VO-ScreenPaneBrowserNotificationHandler-source-quality.md`: uses `g_pBrowserDialogOld` as a guarded close target in a non-Browser consumer, supporting external visibility or at least non-local source use.

Historical pre-callback generated lead: `auto-generated/NexusTK/browser/Browser.cpp` from validator command `000000006422` at `2026-07-04T18:25:08-04:00` emitted `BrowserDialog *g_pBrowserDialog;`, `BrowserPane *g_activeBrowserPane;`, and paired BrowserThread globals, but left UID0000QB and UID0002WH as empty markers.

Current post-callback generated freshness: validator command `000000006467` at `2026-07-04T19:07:58-04:00` refreshes `auto-generated/NexusTK/browser/Browser.cpp` with `// UID:0002WH ... Completion:90 | Confidence:92` followed by exactly one `BrowserDialogOld *g_pBrowserDialogOld;` declaration and no UID0002WH empty marker.

## Target

- UID: `0002WH`
- Target path: `by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md`
- Address range: `0x0067ab90-0x0067ab94`
- Entity kind: four-byte `.data` pointer storage for the legacy BrowserDialogOld singleton.
- Pre-callback metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000QB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QB`, blank optional position, blank formal C++.
- Current metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000QB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QB`, blank optional position, formal C++ `BrowserDialogOld *g_pBrowserDialogOld;`.

## Current Target State

The target page now identifies the storage as `g_pBrowserDialogOld` under direct by-global parent [UID:0000QB], records the current zero-byte evidence from MCP session `ddf5b602`, active label `unk_67AB90`, missing current name/global/type records, exactly eight xrefs and writer/consumer roles, and emits the source declaration `BrowserDialogOld *g_pBrowserDialogOld;`.

The previous stale blockers are resolved as implementation state: `0xffffffff` initializer wording is historicalized, blank formal C++ is replaced, and generated Browser output no longer has a UID0002WH empty marker after command `000000006467`. The remaining old/new Browser source split and final header/export spelling are confidence caps only.

## Executive Recommendation

UID0002WH now emits this source-ready declaration:

```cpp
BrowserDialogOld *g_pBrowserDialogOld;
```

Do not add `= NULL` because the zero-filled `.data`/BSS-like storage is represented by the default C++ zero initialization. Do not use `static` in the formal target body for this pass: current readers include non-constructor/non-destructor consumers outside the tight old-dialog range, and the accepted sibling `g_pBrowserDialog` source body uses external linkage. A later source-tree/header pass may add an `extern` declaration in a private header, but the defining storage line should remain a single Browser module definition.

## Supervisor Active Recheck

Original supervisor instruction for the Gate 1 research turn required report-only research, current IDA MCP evidence, exact target binding because of global/Browser alias risk, and no by-* or generated edits. Compliance state from that turn:

- MCP initialized successfully and `idb_list` returned active worker session `ddf5b602` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid/worker_pid 20820`.
- `server_health` for `ddf5b602` returned `status: ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- B014 did not call `idb_open`, `idb_close`, IDA process/session management, patching/mutation tools, validators, or lifecycle/archive commands during the report-only pass.
- One broad `insn_query` over a large code span timed out after 60 seconds. I stopped using broad scans and replaced it with bounded function-scoped `insn_query`, `xrefs_to`, `xref_query`, `trace_data_flow`, `get_bytes`, and `decompile` calls.

Implementation callback compliance: B014 used leases only for edited by-* files, released all leases, ran scoped file validators only for changed by-* docs, used `--wait-generated` only for generated Browser.cpp freshness checks, and did not perform IDA DB mutation or lifecycle/archive actions.

## Inference Research Guidance Check

The exact original source spelling is not recovered from IDA. Current MCP `entity_query` over `0x0067ab80-0x0067aba8` returns no `names` or `globals`, `list_globals "*g_pBrowser*"` returns no source global rows, and `type_query "*BrowserDialogOld*"` returns no local UDT/type records. Under the current source-quality rules, that absence does not justify blank output when the data size, role, type family, xrefs, and sibling source pattern are strong.

Inference decisions:

- Keep source-facing name `g_pBrowserDialogOld`: it is established by target/global/support docs, Browser naming style, sibling `g_pBrowserDialog`, and decompiler/consumer roles.
- Use type `BrowserDialogOld *`: constructor publishes a BrowserDialogOld `this`, destructor/wrapper restore BrowserDialogOld vtables, RTTI/vtable globals for `BrowserDialogOld` exist, and consumers call through the dialog vtable.
- Use external defining declaration, not `static`: current consumers include `0x00508da9`, `0x005145f3`, and `0x00556fbe` outside the tight old-dialog construction/destruction region; sibling `g_pBrowserDialog` already uses external declaration.
- Omit explicit initializer: MCP bytes are zero, and default zero initialization expresses the storage without encoding stale `0xffffffff`.

## Heuristic / Inference Reanalysis And Validation

The target is a data declaration, not a function body. The source-quality question is whether this exact storage can emit the C++ declaration safely despite missing IDA type/name recovery.

Range/split decision: keep exact child UID0002WH as the emitting storage row. Do not emit the mixed parent `0x0067ab90-0x0067aba4` because it crosses Browser and WebBoardDialog ownership. Do not move the source declaration into UID0000Z3 or UID00033B; those pages explain writers/clears but do not own the global storage declaration.

Owner route decision: keep `CANONICAL_OWNER:0000QB` and `EMITTER_UIDS:0000QB`. The by-global page is the canonical symbol page for this exact storage and itself routes under Browser [UID:0000HV]. This avoids bypassing the symbol page while preserving Browser source placement.

Rejected alternatives:

- `static BrowserDialogOld *g_pBrowserDialogOld;`: plausible historical by-global hypothesis, but weaker than current sibling and consumer evidence.
- `BrowserDialogOld *g_pBrowserDialogOld = NULL;`: behaviorally equivalent but less source-shaped for zero-initialized storage and inconsistent with accepted `g_pBrowserDialog` sibling.
- `void *`, `DialogPane *`, `Singleton<BrowserDialogOld> *`, or raw `DWORD`: contradicted by constructor/destructor/vtable evidence.
- No-code/blank formal C++: contradicted by source declaration readiness and by sibling Browser globals already emitted.
- Emitting through `BrowserDialogOld::~BrowserDialogOld()` or scalar deleting wrapper: wrong ownership; those write/clear the storage but do not declare it.

Remaining caps: final header placement and one-file `Browser.cpp` versus possible legacy split remain unresolved, but they do not block this first-draft storage declaration.

## Evidence Standards Used

I applied this evidence ladder:

1. Current MCP-backed IDB evidence: active session/health, exact bytes, xrefs, scoped instruction queries, decompilation, and current IDB name/type state.
2. Current by-* documentation state: target/support metadata, owner/emitter routes, source placement notes, and accepted sibling implementation.
3. Executed B-agent reports as leads only, revalidated against current MCP and current docs before using them as claims.
4. Generated output as a freshness/implementation lead only, not as proof that blank output is correct.
5. Source-shaped inference only after direct behavior/type/owner evidence was strong and explicitly caveated.

## Evidence Checked

MCP session `ddf5b602`:

- `idb_list`: one active worker session for `NexusTK.exe.i64`.
- `server_health`: ok, imagebase `0x400000`, auto-analysis/Hex-Rays/strings cache ready.
- `get_bytes 0x0067ab88 size 32`, `0x0067ab90 size 20`, and `0x0067ab98 size 4`: all zero bytes. This supersedes older `0xffffffff` initializer notes for the target and neighboring browser dialog slots.
- `get_int`: `u32le` values at `0x0067ab90`, `0x0067ab94`, and `0x0067ab98` are all `0`.
- `lookup_funcs`: `0x0067ab90` and `0x0067ab98` are not functions. Related code functions are `sub_469290` `0x00469290` size `0x196`, `sub_469430` `0x00469430` size `0x6c`, `sub_470230` size `0xb`, `sub_4705E0` size `0xad`, `sub_507C90` size `0x1176`, `sub_514580` size `0xb6`, and `sub_556F70` size `0x100`.
- `entity_query` names/globals over `0x0067ab80-0x0067aba8`: zero rows. The current source-facing name is documentation/source inference, not an active IDB global name.
- `list_globals "*BrowserDialog*"`: current IDB has decorated BrowserDialogOld/BrowserDialog vtable/RTTI symbols but no `g_pBrowserDialogOld` global symbol row.
- `type_query "*BrowserDialogOld*"` and `type_query "*Singleton*BrowserDialogOld*"`: zero local type records. The `BrowserDialogOld *` type is inferred from vtables/RTTI/lifecycle/docs.
- `xrefs_to` / `xref_query to 0x0067ab90`: exactly 8 data xrefs and no xrefs from the storage address.
- `trace_data_flow 0x0067ab90 backward max_depth=1`: exact touching instructions are `0x004692ed`, `0x004692f4`, `0x0046947d`, `0x00470230`, `0x00470634`, `0x00508da9`, `0x005145f3`, and `0x00556fbe`.
- Function-scoped `insn_query op_any 0x0067ab90`: constructor has set and fallback clear, ordinary destructor has clear, cleanup thunk has clear, scalar wrapper has duplicate clear, and three consumers read/compare the slot.
- `decompile 0x00469290`: constructor calls dialog setup, publishes `unk_67AB90 = this` unless the decompiler's sentinel path clears it, installs BrowserDialogOld vtables, allocates/constructs the old control pane, registers/layouts the dialog, and returns `this`.
- `decompile 0x00469430`: ordinary destructor restores BrowserDialogOld vtables, calls cleanup helpers `0x0049e1c0`/`0x0049e210`, clears `unk_67AB90`, and base-cleans.
- `decompile 0x00470230`: tiny cleanup thunk `unk_67AB90 = 0`.
- `decompile 0x00514580`: chooses between new `unk_67AB98` and old `unk_67AB90` based on `byte_66DA97`; old path allocates `0x278` and calls `0x0046e640` only if `unk_67AB90` is null.
- `disasm 0x00507c90` around `0x00508da9`: switch case compares `unk_67AB98`, then compares `unk_67AB90`; if old dialog is absent it allocates `0x278` and calls `0x0046e640`.
- `decompile 0x00556f70`: notification handler checks `unk_67AB90` and calls the dialog vtable with argument `1` when present, then may allocate an AlertPane-like object with payload text.

Local/documentation evidence:

- Target UID0002WH pre-callback blank-emitted and cited the older nonzero initializer; post-callback it emits `BrowserDialogOld *g_pBrowserDialogOld;` and historicalizes that initializer.
- `by-global/g_pBrowserDialogOld.md` pre-callback had a likely `static BrowserDialogOld*` hypothesis and blank formal C++; post-callback it has a coverage comment plus `[[CHILDREN]]` marker so UID0002WH emits the accepted external defining storage without duplicate definition.
- `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md` already emits `BrowserDialog *g_pBrowserDialog;` with zero-initialized bytes and external linkage.
- Generated Browser.cpp command `000000006422` is the historical pre-callback empty-marker lead. Current command `000000006467` emits one UID0002WH declaration and no UID0002WH empty marker.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002WH-01 | UID0002WH is exact four-byte storage at `0x0067ab90-0x0067ab94`, not code and not part of a larger source object. | High | Target path; MCP `lookup_funcs` says not a function; `get_bytes` exact 4-byte slot. | Target `Status`/`Summary`/metadata. | incorporate | applied: target `Status` and `Summary` identify exact four-byte global-data pointer storage; validator `000000006461` ok. |
| C-0002WH-02 | Current bytes are zero-filled; older `0xffffffff` initializer notes are historical/stale. | High | MCP `get_bytes` and `get_int` over `0x0067ab90` and neighboring slots. | Target `Evidence`; by-global; aggregate singleton page; Browser file singleton table. | historicalize | applied: target, by-global, aggregate UID0002AE, and Browser file now state current `ddf5b602` zero-byte evidence and historicalize older `0xffffffff` wording; validators `000000006461`, `000000006467`, `000000006463`, `000000006464` ok. |
| C-0002WH-03 | Current IDB operand name is `unk_67AB90`; no current `names`/`globals` row exists for `g_pBrowserDialogOld`. | High | MCP `entity_query` no rows; `trace_data_flow` names root `unk_67AB90`. | Target evidence and rename/type recommendations. | incorporate | applied: target Item Summary/Evidence and by-global Status/Observed Evidence record active `unk_67AB90`, no name/global row, and source-facing inference; validators `000000006461` and `000000006467` ok. |
| C-0002WH-04 | The constructor at `0x00469290` publishes the constructed BrowserDialogOld object into this storage and has a fallback clear. | High | MCP `xrefs_to`, `insn_query`, and decompile at `0x00469290`. | Target `Evidence`; by-global lifetime table; BrowserDialogOldCore support. | incorporate | applied: target Evidence lists `0x004692ed` set and `0x004692f4` fallback clear; by-global lifetime table and core support note synchronized; validators `000000006461`, `000000006467`, `000000006466` ok. |
| C-0002WH-05 | Ordinary destructor, cleanup thunk, and scalar deleting wrapper clear the slot; wrapper clear is duplicate compiler lowering. | High | MCP `insn_query` at `0x00469430`, `0x00470230`, `0x004705e0`; B010 wrapper report. | Target `Evidence`/`Reconstruction Notes`; by-global; scalar wrapper support already mostly present. | incorporate | applied/already-present: target and by-global record `0x0046947d`, `0x00470230`, `0x00470634`; core support records ordinary destructor route; scalar-wrapper page was inspected and already states duplicate compiler lowering, so no edit was made. |
| C-0002WH-06 | Consumers at `0x00508da9`, `0x005145f3`, and `0x00556fbe` read/compare/call through this pointer. | High | MCP `xrefs_to`, function-scoped `insn_query`, decompile/disasm for readers. | Target `Evidence`; support docs for Browser/BrowserDialogOld if stale. | incorporate | applied: target Evidence, by-global lifetime table, Browser file source-emitting row, and BrowserDialogOld open question resolution record the three consumers; validators `000000006461`, `000000006467`, `000000006463`, `000000006465` ok. |
| C-0002WH-07 | Source-facing type is `BrowserDialogOld *` despite missing recovered UDT. | High | Constructor publishes `this`, vtables/RTTI for BrowserDialogOld, destructor/wrapper relation, docs. | Target formal C++; by-global type hypothesis; IDA type recommendation. | incorporate | applied: target formal C++ and target/by-global evidence use `BrowserDialogOld *` while preserving no-UDT caveat; generated Browser.cpp command `000000006467` emits the declaration once. |
| C-0002WH-08 | Formal C++ should be `BrowserDialogOld *g_pBrowserDialogOld;` with no explicit initializer. | High | Zero bytes, sibling `g_pBrowserDialog` precedent, source global storage rules. | Target `RECONSTRUCTION_CPP CODE`. | incorporate | applied: target formal block contains exactly `BrowserDialogOld *g_pBrowserDialogOld;`; Browser.cpp command `000000006467` emits it once and has no UID0002WH empty marker. |
| C-0002WH-09 | Do not use `static` for the accepted first draft; external defining storage better matches consumer and sibling evidence. | Medium-high | Non-tight-range readers; generated sibling `BrowserDialog *g_pBrowserDialog;`; unresolved source split remains cap. | Target notes; by-global `Type Hypothesis`; Browser support. | historicalize | applied: target notes explain no `static`; by-global Type Hypothesis replaces the old `static` snippet with accepted external declaration text and child route; Browser support row mirrors it. |
| C-0002WH-10 | Keep owner/emitter route through [UID:0000QB] under Browser [UID:0000HV]. | High | Current metadata, by-global exact symbol page, Browser source root docs. | Target metadata; support owner notes. | already-present | applied: target preserves `CANONICAL_OWNER:0000QB`, `EMITTER_UIDS:0000QB`, blank optional position; by-global remains Browser-owned and now carries `[[CHILDREN]]` route marker. |
| C-0002WH-11 | Mixed aggregate UID0002AE remains non-emitting coverage index; exact UID0002WH should emit the old-dialog declaration. | High | by-structure split; aggregate crosses Browser/WebBoardDialog; exact child exists. | Aggregate support row if stale; target cross-refs. | incorporate | applied: aggregate UID0002AE remains `RECONSTRUCTABLE:FALSE` and now states UID0002WH is source-ready on the exact child; validator `000000006464` ok. |
| C-0002WH-12 | Pre-callback generated Browser.cpp empty marker is stale implementation state, not evidence for no-code. | High | Generated command `000000006422`; target blank formal C++; current MCP declaration evidence. | Target notes; generated freshness expectation. | reject-stale | applied: report and docs now label command `000000006422` as historical pre-callback state; command `000000006467` refresh shows one UID0002WH declaration and no UID0002WH empty marker. |
| C-0002WH-13 | Recommended target metadata is `90/92`, reconstructable true, owner/emitter unchanged. | High | Complete bytes/xrefs/lifecycle/source declaration; remaining exact linkage/header cap. | Target metadata. | incorporate | applied: target metadata is `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter/reconstructable unchanged; validator `000000006461` ok. |
| C-0002WH-14 | No IDA DB rename/type mutation should be performed by B014 in report-only or callback work. | High | Supervisor constraints; MCP evidence sufficient without mutation. | IDA Rename / Type / Comment Recommendations. | not-applicable | applied: B014 did not run IDA rename/type/comment mutations, `idb_open`, `idb_close`, or process/session management; recommendations remain supervisor-owned. |

## Positive Evidence Summary

- Exact storage is narrow and fully bounded: one four-byte pointer slot at `0x0067ab90-0x0067ab94`.
- Current MCP bytes and integer reads are all zero, matching source default initialization.
- Exactly eight current data xrefs touch the slot, and all have coherent singleton lifecycle/consumer roles.
- Constructor `0x00469290` publishes `this`, then installs BrowserDialogOld vtables and constructs old browser UI state.
- Ordinary destructor `0x00469430`, cleanup thunk `0x00470230`, and scalar wrapper `0x004705e0` clear the singleton; B010 already explains the wrapper as generated duplicate cleanup.
- Readers at `0x00508da9`, `0x005145f3`, and `0x00556fbe` use the pointer as a BrowserDialogOld singleton gate/close target.
- Sibling UID0002WI already emits `BrowserDialog *g_pBrowserDialog;` under the same Browser source family after zero-byte recheck.

## Negative Evidence Summary

- No current MCP `names` or `globals` row recovers the exact source variable name at `0x0067ab90`.
- No local `BrowserDialogOld` UDT/type record is available through `type_query`.
- Older docs that say `0xffffffff` initialization are contradicted by current MCP bytes.
- The mixed parent range `0x0067ab90-0x0067aba4` cannot emit a combined declaration because it mixes Browser and WebBoardDialog globals.
- Scalar deleting destructor and cleanup thunk writes do not make those ranges source declaration owners.
- Final one-file `Browser.cpp` versus `BrowserLegacy.cpp`/`BrowserOld.cpp` split is unresolved; this affects support/header placement, not the declaration body.

## Ranked Ownership Analysis

1. [UID:0000QB] `g_pBrowserDialogOld` by-global page: accepted canonical owner for this exact storage declaration. It names the source-facing singleton, carries the semantic symbol record, and routes under [UID:0000HV][Browser](by-file/Browser.md). The implementation keeps UID0002WH's `CANONICAL_OWNER:0000QB` and `EMITTER_UIDS:0000QB`.
2. [UID:0000HV] Browser file/source root: accepted source-root and generated-output destination through UID0000QB. It owns Browser globals, BrowserDialogOld, BrowserControlPaneOld, BrowserThread, and old-browser helper context, but it is broader than the exact symbol and should not bypass the by-global owner.
3. [UID:000018] BrowserDialogOld class: semantic type owner for the object stored in the pointer. Constructor/destructor/vtable evidence proves the `BrowserDialogOld *` type family, but a class page does not own or emit module-scope singleton storage.
4. [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md): writer/clear evidence page. It proves constructor/destructor behavior and supports the declaration, but it is not the storage declaration owner and remains an aggregate method/helper page.
5. [UID:00033B][0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor](by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md): rejected as owner/emitter. Its `0x00470634` clear is compiler-generated scalar deleting destructor lowering duplicated from the ordinary destructor, not source singleton policy.
6. [UID:0002AE][0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons](by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md): rejected for emission. The range is a mixed Browser/WebBoardDialog coverage index; exact four-byte children own source declarations.

Decision: UID0002WH remains owned/emitted through [UID:0000QB] under the Browser source root. Consumer xrefs help justify external linkage and source visibility, but ownership is assigned from declaration/storage semantics, writer lifecycle, existing by-global symbol route, and by-structure split rules.

## Source Placement

The source declaration is placed in the Browser source family through [UID:0000HV][Browser](by-file/Browser.md), with exact emitted text carried by `by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md`:

```cpp
BrowserDialogOld *g_pBrowserDialogOld;
```

The exact storage child emits the definition, while `by-global/g_pBrowserDialogOld.md` now contains a coverage comment plus `[[CHILDREN]]` route marker so generated `auto-generated/NexusTK/browser/Browser.cpp` assembles the child declaration once without duplicating it on the symbol page. Final generated freshness command `000000006467` confirms this route: Browser.cpp contains one UID0002WH declaration and no UID0002WH empty marker.

The declaration intentionally omits `static` and an explicit initializer. Current `ddf5b602` MCP evidence shows zero-filled storage, and consumers at `0x00508da9`, `0x005145f3`, and `0x00556fbe` support non-tight-range visibility. A later source-tree pass may still choose an `extern` declaration in a private header, but the defining storage line belongs in Browser-family source output. A possible `BrowserLegacy.cpp` or `BrowserOld.cpp` split remains a confidence cap only; it does not change UID0002WH's source-ready declaration route.

## IDA Rename / Type / Comment Recommendations

B014 did not mutate the IDB. Optional future supervisor-owned IDA improvements:

- Rename data item `unk_67AB90` to `g_pBrowserDialogOld` if the current IDB naming policy accepts source-facing global names for this region.
- Apply data type `BrowserDialogOld *` or a pointer-to-forward-declared BrowserDialogOld type only after a broader BrowserDialogOld type pass; current `type_query` has no local UDT.
- Add a repeatable comment such as: `Legacy BrowserDialogOld singleton storage; constructor publishes, destructor/cleanup/scalar wrapper clear; source declaration belongs to g_pBrowserDialogOld under Browser.`

Do not rename the scalar deleting wrapper or cleanup thunk as the source owner of this storage.

## First-Draft C++ Recommendation

Inserted this exact formal block into `by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md` during the implementation callback:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
BrowserDialogOld *g_pBrowserDialogOld;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The declaration intentionally has no explicit initializer and no `static`. It is emitted once through the exact storage route; support pages do not duplicate the same definition.

## Final Recommendation

UID0002WH implementation is complete from B014's side and this artifact is returned for supervisor verification/execution. The target is now a source-ready singleton storage declaration at `90/92`, with formal C++ `BrowserDialogOld *g_pBrowserDialogOld;`, current zero-byte evidence, exact xref inventory, active IDB name/type caveats, and support synchronization. The remaining unresolved source split/header placement is a confidence cap, not a blank-C++ blocker. B014 did not run `execute_report`; supervisor owns execution and archive lifecycle.

## Recommended Target Doc Changes

Implementation result for `by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md`:

- Applied `COMPLETION:90`, `CONFIDENCE:92`; kept `CANONICAL_OWNER:0000QB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QB`, and blank optional position.
- Replaced the blank formal C++ with the exact formal block above.
- Updated Item Summary to mention exact four-byte zero-initialized legacy BrowserDialogOld singleton storage, eight current xrefs, source declaration readiness, and current `unk_67AB90` IDB-label caveat.
- Replaced stale `0xffffffff` initializer evidence with current MCP session `ddf5b602` zero-byte evidence.
- Added exact current xref/read-write list and writer/consumer roles:
  - `0x004692ed` set, `0x004692f4` fallback clear in constructor `0x00469290`.
  - `0x0046947d` ordinary destructor clear.
  - `0x00470230` cleanup thunk clear.
  - `0x00470634` scalar deleting wrapper duplicate clear.
  - `0x00508da9`, `0x005145f3`, `0x00556fbe` consumers.
- Stated that `BrowserDialogOld *` is source-quality inference from vtable/RTTI/lifecycle evidence because MCP has no recovered UDT or global type record.
- Preserved scalar-wrapper no-code relation and rejected wrapper ownership/emission.
- Verified generated freshness: command `000000006467` updates Browser.cpp with one `BrowserDialogOld *g_pBrowserDialogOld;` definition and no UID0002WH empty marker.

## Recommended Support Doc Changes

- `by-global/g_pBrowserDialogOld.md`: applied current `unk_67AB90`/zero-byte evidence, accepted external declaration text, and a formal coverage comment plus `[[CHILDREN]]` route marker so UID0002WH emits once without duplicate definition. Raised support score to `88/90`.
- `by-file/Browser.md`: applied UID0002WH source-emitting Browser global row beside UID0002WI, current MCP session `ddf5b602`, eight old-dialog xrefs, zero initialization, declaration readiness, and generated freshness note. No score change was made by B014.
- `by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md`: applied historicalized `0xffffffff` note for `0x0067ab90`, current zero-byte evidence, current `unk_67AB90` label, and preserved aggregate as non-emitting mixed coverage index.
- `by-class/BrowserDialogOld.md`: applied narrow support note that UID0002WH now owns the source declaration for the singleton pointer while constructor/destructor/core pages remain separate and class C++ remains blank for broader method/source split reasons.
- `by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md`: applied narrow support note that constructor/destructor set/clear facts are evidence for the UID0002WH declaration, but the aggregate still does not emit that storage declaration.
- `by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md`: inspected only; no edit made by B014 because current wording already states the wrapper clear is duplicate lowering and not source ownership.
- Generated `auto-generated/NexusTK/browser/Browser.cpp`: not manually edited; validator commands `000000006461` and final `000000006467` performed generated refresh. Final freshness is command `000000006467`.

## Score And Metadata Recommendation

Target implementation result:

| Field | Pre-callback | Current | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | 86 | 90 | Exact current bytes, xrefs, lifecycle, consumers, owner route, and formal source declaration are now documented. |
| `CONFIDENCE` | 88 | 92 | Current MCP evidence resolves initializer and xref state; remaining original linkage/source split is a cap only. |
| `CANONICAL_OWNER` | `0000QB` | `0000QB` | Direct by-global symbol page remains the precise storage owner under Browser. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source declaration, not compiler/linker-only no-code. |
| `EMITTER_UIDS` | `0000QB` | `0000QB` | Preserve current direct symbol route. |
| Optional position | blank | blank | No ordering override needed beyond current Browser/global generation. |

Support score results:

- `by-global/g_pBrowserDialogOld.md`: raised to `88/90` after current zero-byte/external-declaration sync and child-route marker.
- `by-file/Browser.md`: no B014 score change required; support note added.
- `by-class/BrowserDialogOld.md` and UID0000Z3: no B014 score change required; synchronization notes added.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Remaining impact | Future evidence needed |
| --- | --- | --- | --- |
| Was the original declaration `static`, external, or `extern` plus one definition? | Checked current readers, sibling UID0002WI, Browser globals, generated Browser.cpp, by-global hypothesis, and old reports. External defining storage is the best first draft; final header may have `extern`. | Confidence cap only; not a C++ blocker. | Recovered source/header or a broader Browser source split pass. |
| Is the exact IDA/global name recovered? | MCP `entity_query` over the address range and `list_globals` filters found no current row; trace labels it `unk_67AB90`. | Not a blocker; source-facing docs establish name. | Optional IDA rename/type pass. |
| Is `BrowserDialogOld` UDT recovered? | MCP `type_query` returned no local type records, but vtable/RTTI globals and constructor/destructor behavior identify type. | Not a blocker for pointer declaration. | Future BrowserDialogOld class/UDT reconstruction. |
| Should UID0000QB or UID0002WH carry the formal definition? | Current metadata routes target through UID0000QB; by-memory exact storage is the implementation target and by-global remains support/canonical symbol page. | Implementation should avoid duplicate definitions across both pages. | Validator/generated output after callback. |
| Does old Browser source live in one Browser.cpp or a legacy split file? | Browser file docs rank one broad Browser module as most likely, with BrowserLegacy/BrowserOld plausible but unproven. | Confidence cap only. | Source tree recovery or final source-placement pass. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B014 recommends no manual coverage-report or tracker edit. During callback, B014 did not manually edit coverage/tracker files. Validator-owned generated refresh updated generated coverage/tracker state as part of `--wait-generated`; after supervisor lifecycle commands, validator-owned report history/footer and archived report path are authoritative.

Current generated effect after implementation is that UID0002WH changed from a pre-callback empty marker to emitting:

```cpp
BrowserDialogOld *g_pBrowserDialogOld;
```

## Validator Results

Scoped validators were run only for changed by-* docs from `source-3/project-documentation`.

| Command ID | Timestamp | File | Exit | ok | Warnings / generated effect |
| --- | --- | --- | ---: | ---: | --- |
| `000000006461` | `2026-07-04T19:05:36-04:00` | `by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md` | 0 | 1 | Target completion/confidence updated; `--wait-generated` completed; generated Browser.cpp initially refreshed but still needed by-global route marker. |
| `000000006462` | `2026-07-04T19:05:54-04:00` | `by-global/g_pBrowserDialogOld.md` | 0 | 1 | Intermediate validation before route-marker repair; superseded by final by-global validation `000000006467`. |
| `000000006463` | `2026-07-04T19:05:59-04:00` | `by-file/Browser.md` | 0 | 1 | `missing_ref_uid:15` pre-existing/unrelated Browser.md references; generated refresh deferred. |
| `000000006464` | `2026-07-04T19:06:08-04:00` | `by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md` | 0 | 1 | No file-specific warnings; generated refresh deferred. |
| `000000006465` | `2026-07-04T19:06:17-04:00` | `by-class/BrowserDialogOld.md` | 0 | 1 | `reference_index_add 0002WH`; generated refresh deferred. |
| `000000006466` | `2026-07-04T19:06:27-04:00` | `by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md` | 0 | 1 | `reference_index_add 0002WH`; generated refresh deferred. |
| `000000006467` | `2026-07-04T19:07:58-04:00` | `by-global/g_pBrowserDialogOld.md` | 0 | 1 | Final route validation with `--wait-generated`; generated refresh completed and `auto-generated/NexusTK/browser/Browser.cpp` contains one UID0002WH declaration and no UID0002WH empty marker. Broad generated-refresh warnings were unrelated existing child-marker/no-code notices. |

## Changed Files

- B014 edited by-* docs:
  - `by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md`
  - `by-global/g_pBrowserDialogOld.md`
  - `by-file/Browser.md`
  - `by-memory/0x0067ab90-0x0067aba4.BrowserAndWebBoardDialogSingletons.md`
  - `by-class/BrowserDialogOld.md`
  - `by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md`
- B014 inspected but did not edit `by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md`; it was already same-or-greater detail for duplicate compiler lowering.
- B014 updated this report: `tools/leaser/Agents/Agent-B014/research/0002WH-g_pBrowserDialogOld-source-quality.md`.
- Validator-owned generated/registry/stat refresh occurred via scoped validators, including `auto-generated/NexusTK/browser/Browser.cpp`, generated coverage/tracker metadata, `tools/validator.ini`, and `project-level/-auto-completion-stats.md`. B014 did not manually edit those files.
- Leases used/released: leased the six edited by-* docs in one batch before edits and released them after validation; leased `by-global/g_pBrowserDialogOld.md` again for the route-marker repair and released it after final validation. Final shared lease report shows no active B014 leases; unrelated active leases belong to other agents.

## Implementation Tracking Checklist

- [x] Apply target metadata `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter unchanged (`applied`, C-0002WH-13; validator `000000006461`).
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block with `BrowserDialogOld *g_pBrowserDialogOld;` and no initializer (`applied`, C-0002WH-08; generated command `000000006467`).
- [x] Replace stale target initializer wording with current MCP zero-byte evidence from `ddf5b602` (`applied`, C-0002WH-02).
- [x] Add current IDB name/type caveats: active operand `unk_67AB90`, no names/globals rows, no BrowserDialogOld UDT (`applied`, C-0002WH-03, C-0002WH-07).
- [x] Record exact eight xrefs and writer/reader roles in the target (`applied`, C-0002WH-04 through C-0002WH-06).
- [x] Preserve scalar deleting wrapper as duplicate compiler lowering and reject wrapper ownership (`applied/already-present`, C-0002WH-05; scalar wrapper inspected, no edit needed).
- [x] Sync by-global `g_pBrowserDialogOld` with external first-draft declaration, current zero-byte evidence, and `[[CHILDREN]]` route marker (`applied`, C-0002WH-08, C-0002WH-09; validator `000000006467`).
- [x] Sync Browser file/global table so UID0002WH is no longer a stale empty-emitter follow-up after callback (`applied`, C-0002WH-12; validator `000000006463`).
- [x] Historicalize aggregate UID0002AE's stale `0xffffffff` note for this slot while keeping the aggregate non-emitting (`applied`, C-0002WH-02, C-0002WH-11; validator `000000006464`).
- [x] Run scoped validators only after supervisor implementation callback for every changed by-* doc (`applied`; commands `000000006461` through `000000006467` as listed above).
- [x] Check generated Browser.cpp freshness after validators; expected one UID0002WH declaration and no UID0002WH empty marker (`applied`, C-0002WH-12; final command `000000006467`).
- [x] Do not run `execute_report`, lifecycle/archive commands, generated manual edits, coverage edits, validator-state manual edits, supervisor-ledger edits, or IDA DB mutation during callback (`applied`, C-0002WH-14).

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000006513","destination_path":"executed-b-agent-research/B014/0002WH-g_pBrowserDialogOld-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0002WH-g_pBrowserDialogOld-source-quality.md","timestamp":"2026-07-04T19:27:54-04:00","uid":"0002WH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
