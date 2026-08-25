** TARGET-REPORT-UID:00019A **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# 00019A LObjectUnregisterChangeListener Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00019A] as the exact inherited `LObject::UnregisterChangeListener` member at `0x004f4b50-0x004f4b6c`, owned and emitted by [UID:00007D] `LObject` through [UID:0000KV] `NexusTK/util/LObject.cpp`.
- Final disposition: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00007D`, `EMITTER_UIDS:00007D`, blank optional position, exact formal CPP body, and blank target H block because the declaration already belongs inside the class-owner block.
- Completion status: ordinary implementation, post-Gate2B documentation reconciliation, independent supervisor post-IDA Gate 2A validation, supervisor manual coverage application, and coverage validation are complete. Supervisor Gate 2B remains `APPLIED_VERIFIED` with the exact historical prestate/backup/action/readback/save evidence preserved. Only fresh exact-artifact Gate 1/Gate 2 audit and supervisor report execution remain.
- Recommended target score: `COMPLETION:93`, `CONFIDENCE:94` (`92/94 -> 93/94`).
- Confidence: very strong for behavior, ABI, range, owner/emitter, source placement, source types, and formal C++; the exact original identifier spellings and access/header arrangement remain inferred rather than symbol-recovered.
- Current lifecycle state: unexecuted artifact after ordinary implementation, Gate 2B `APPLIED_VERIFIED`, post-IDA Gate 2A validation, and supervisor-applied/validated manual coverage. The report alone is ready for a fresh exact-artifact Gate 1/Gate 2 audit and supervisor-only execution. B007 did not mutate IDA, edit manual coverage, or execute/move the report.

## Supporting Research

- Historical 2026-07-08 B007 work is preserved as a useful intermediate result. MCP session `2cb2455b` proved the exact bytes, one callee, seven callers, five `g_pBackPane` receivers, two `g_pApplication` receivers, and the failure of direct `Application` class ownership. That pass selected a source-neutral Application-file helper only because it had not yet completed the common-base constructor-chain proof.
- Historical B007 implementation metadata `88/90`, owner/emitter `0000HG`, and the free-helper form using `void *owner`, `ChangeListener`, and `ChangeMessageScope` are superseded, not erased. They remain evidence of how the incorrect direct-Application route was rejected.
- The executed B003 `0000ZW-ChangeManRegister-source-quality.md` report supplied the missing common-base lead on 2026-07-13: `Application` and `BackPane` both construct `LObject` at object offset zero. It also replaced the temporary free-helper source shape with adjacent inherited `LObject` members.
- This B007 repair did not merely copy the B003 conclusion. Current live IDA MCP database `5a570ede` independently reconfirmed the target, callee, callers, data xrefs, bytes, comments, prototypes, and both constructor chains.
- The old report's scoped validator command history (`000000008009` through `000000008013`) is historical implementation provenance only. No validator or report execution command was run during this report-only repair.
- Generated files are read-only corroboration. Current `auto-generated/NexusTK/util/LObject.cpp` emits the class declaration and exact UID00019A member definition; `Application.cpp` no longer owns a duplicate wrapper. Generated output was not edited.

## Target

- Target UID: `00019A`.
- Additional target UIDs: none.
- Declared-target inventory: `by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md`, exact function-level documentation and source-emitting leaf.
- Report artifact: `tools/leaser/Agents/Agent-B007/research/00019A-ApplicationUnregisterChangeListener-source-quality.md`; the filename preserves the historical assignment name, while this report records the current LObject semantic identity.
- Source queue/report row: historical low-score Application wrapper assignment, now a current source-quality refresh of the renamed UID-preserving LObject target.
- Current supervisor classification: reconstructable by-memory method with exact source body, completed Gate 2A/Gate 2B closure, and supervisor-applied/validated manual coverage.
- Implemented scores and parent state: `93/94`, owner/emitter `00007D`, blank position, parent class [UID:00007D] `LObject`, file route [UID:0000KV] `LObject`.

## Current Target State

- Implemented metadata: `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:00007D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007D`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`.
- Implemented C++ state: the formal CPP block preserves the exact `void LObject::UnregisterChangeListener(LObject *, MessageType, bool)` definition. The target H block remains blank.
- Implemented target prose records the current named/typed function, mixed BackPane/Application receivers, both complete offset-zero constructor chains, filtered callee, exact range/padding negatives, generated route, rejected owners, lexical uncertainty, and exact singleton prestate/action/readback. The stale raw-name/type-query/generated-mismatch statements were replaced as current state without deleting the dated historical route.
- Preserved target history keeps the temporary B007 source-neutral helper route explicitly superseded by the constructor-chain/common-base proof.
- Implemented support state: `by-class/LObject.md` remains `90/92` with exact wrapper addresses `0x004f4b30`, `0x004f4b50`, and `0x004f4b70`. UID0000QI remains `91/90` as sole semantic definition; UID0001P4 remains `88/91` as nonduplicating raw-storage evidence. UID00019A, UID0000QI, and UID0001P4 now preserve the four-head state as historical supervisor prestate and record the exact current one-item Gate 2B readback/save evidence.
- Current IDA state was changed only by the supervisor and is now verified: `[0x0067ab2c,0x0067ab30)` is one size-4 `is_data:true` item named `g_pChangeMan`, typed `ChangeMan *`, with the exact accepted comments, unchanged bytes/xrefs, unchanged neighbors, and successful post-save readback. B007 performed no IDA mutation.
- Current manual coverage state is supervisor-applied and validated: by-memory UID00019A has the exact `93%` LObject row with supervisor-verified IDA readback wording; by-memory UID0001P4 has the exact `88%` row; by-global UID0000QI has the exact `91%` row.
- Related docs checked: target, sibling register/forward wrappers, wrapper aggregate, LObject runtime shell, LObject class/file, Application class/file, ChangeMan class/file/methods, `g_pChangeMan` global/storage, caller-class pages, generated LObject/Application/caller output, matching reports, and all relevant manual coverage rows.
- Current artifact/lifecycle status: ordinary implementation, post-Gate2B reconciliation, supervisor Gate 2A, manual coverage application, and coverage validation are complete; supervisor Gate 2B remains `APPLIED_VERIFIED`. Only fresh exact-artifact audit and supervisor execution remain. Older pre-callback acceptance/implementation claims remain historical only.

## Executive Recommendation

- Retain the current direct owner/emitter [UID:00007D] `LObject`. The wrapper's implicit ECX owner, ordinary `__thiscall` cleanup, physical adjacency to the register/forward wrappers, mixed concrete receivers, and offset-zero construction of both receiver families jointly prove inherited base-member source shape.
- Retain [UID:0000KV] `NexusTK/util/LObject.cpp` as source placement. `Application.cpp`, pane source files, and `ChangeMan.cpp` are consumer/callee routes, not the definition route.
- Preserve the exact range `0x004f4b50-0x004f4b6c`; preserve `0x004f4b6c-0x004f4b70` as separate alignment padding; do not merge the function into the non-emitting UID000199 pair index.
- Preserve the exact formal CPP body and blank H child block. The class owner already supplies the declaration in its class definition.
- The callback-applied `92/94 -> 93/94` completion increase is independently Gate 2A validated and reflects current live evidence, exact Gate 2B closure, stale-support correction, and applied/validated manual coverage. Confidence remains 94 because no original symbol/header survives to prove spelling or access text.
- Supervisor Gate 2B normalized `0x0067ab2c` as one four-byte `ChangeMan *g_pChangeMan` data item with the exact comments below and verified all protected/no-change constraints. No other IDA mutation is justified or recorded.

## Supervisor Active Recheck

- Triggering instruction: resume this exact unexecuted B007 report, preserve valid detail, convert it to the current literal 33-section template and `CHATGPT | 5.6 | xHigh` provenance, refresh all binary facts through live IDA MCP, and remain report-only.
- Split repair: no new split is required. The target is already the exact function child; UID000199 is the non-emitting pair/index; the four-byte trailing padding is already outside the function endpoint.
- Source-bearing child state: UID00019A itself is source-bearing and exact. The sibling UID000198 and UID00019B source bodies were inspected as corroboration but are not declared targets of this report.
- Required current-state repairs are complete: target prose/score, LObject support address correction, `g_pChangeMan` historical prestate plus applied/readback/save evidence, and exact manual coverage rows all passed the supplied supervisor validations.
- No source-quality blocker is left as "needs investigation". Every blocker inherited from the old B007 report was rechecked and either resolved, reduced to a documented spelling uncertainty, or converted into an exact supervisor action.

## Inference Research Guidance Check

- Binary facts, documentation evidence, and inference are separated throughout this report. IDA establishes machine behavior and object flow; current by-* docs establish project-wide type/name conventions; source shape is inferred only after both agree.
- Existing documentation was not treated as authority. The old Application-member route and later source-neutral free-helper route were both challenged against all caller receivers and constructor chains.
- The inference discipline from the project skill and `by-structure.md` requires human-looking mid-2000s C++ that preserves exact behavior. It rejects both raw `sub_`/`unk_` labels and an invented helper when ordinary inherited member syntax explains the ABI.
- The current names `LObject`, `UnregisterChangeListener`, `MessageType`, `allMessages`, and `g_pChangeMan` are best project-consistent source-facing inferences. They are not represented as recovered PDB text.
- Consistency was used only after behavior and human source shape: the register/unregister/forward family shares one member API, but no behavior was changed merely to match naming style.
- Wave2/Wave3 wording in historical material was ignored as stale workflow provenance. It had no evidentiary weight and no current override applies.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence rechecked | Best defensible resolution | Status / score effect |
| --- | --- | --- | --- |
| Direct owner | Seven callers plus both receiver constructor chains | `LObject` member; both `BackPane` and `Application` contain primary `LObject` at offset zero | resolved |
| Application ownership | Five BackPane receivers, only two Application receivers | reject direct `Application` definition; Application is an inherited consumer | resolved |
| Free-helper alternative | Target is ordinary `__thiscall`, passes implicit ECX as owner, and uses `retn 0x0c` | reject nonstandard explicit-owner free helper | resolved |
| ChangeMan ownership | Wrapper loads singleton then calls ChangeMan method; it does not access ChangeMan fields through its own ECX | `ChangeMan` owns the callee and global, not this wrapper | resolved |
| Listener type | Current target and callee prototypes use `LObject *`; ChangeMan entries/callback vtables use LObject-family objects | `LObject *listener` | resolved |
| Message type | Four-byte argument; ChangeMan entry comparison and project API use `MessageType` | `MessageType`, inferred typedef spelling over raw `unsigned int` | implementation-ready |
| Boolean flag | Stack slot at `+0x10`, bool prototype, callee boolean branch, every current caller passes false | `bool allMessages`; reject historical scope enum | resolved |
| Return type | Current IDA prototype is void; wrapper has no source return use; callee is void | `void` | resolved |
| Method spelling | Current IDA/project sibling family consistently uses `RegisterChangeListener`, `UnregisterChangeListener`, `ForwardMessage` | keep descriptive human name; exact original spelling remains a confidence cap | implementation-ready |
| Source file | LObject runtime shell, class owner, generated current route, adjacent family | `NexusTK/util/LObject.cpp` | resolved |
| Header placement | Class page already declares the member; target is an out-of-class definition leaf | leave target H blank; do not duplicate a namespace-scope declaration | resolved |
| Function boundary | Function object and bytes stop at `0x004f4b6c`; following four bytes are `0xcc` with zero refs | exact half-open range, no split/merge | resolved |
| Singleton IDA name/width | Historical prestate was four one-byte heads over four zero bytes with 11 xrefs; supervisor readback now reports one exact size-4 `g_pChangeMan` / `ChangeMan *` data item with accepted comments and unchanged refs | Gate 2B `APPLIED_VERIFIED`; historical prestate retained | resolved and reconciled |
| Caller constants | `0x676f6f67` and `0x7465726d` are proven values; caller docs use local source-facing tag names | preserve raw values and caller-local inferred names; do not invent one global enum member here | resolved |
| Generated-output pollution | Current generated LObject source now has exact wrapper; historical Application mismatch is obsolete | replace stale current-state prose; retain dated mismatch only as history | resolved |
| Manual coverage drift | historical stale rows and exact replacement payloads were documented | supervisor applied exact by-memory/by-global rows and validated both reports | resolved and supervisor-validated |

Rejected alternatives: direct Application member, direct BackPane member, direct ChangeMan member, namespace/free helper with explicit owner, emission from UID000199, body duplication in caller source files, broad range merge, H-block duplicate declaration, and retaining raw IDA names in final C++.

No in-scope interpretation remains unsafe. The only non-binary facts still uncertain are exact original spelling/access/header organization; the best human-source choices are explicit and do not alter runtime behavior.

## Evidence Standards Used

- Live IDA MCP: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, decompile/disassembly, bytes, item inspection, comments, callers/callees, xrefs, and constructor-chain inspection.
- Exact-address evidence: target, endpoint, padding, singleton storage, callee, all seven call sites, sibling wrappers, and every constructor-chain hop.
- ABI evidence: ECX receiver, three stack arguments, `retn 0x0c`, current prototypes, callee parameter use, and absence of return consumers.
- Ownership evidence: receiver types plus offset-zero base construction, not physical adjacency or one consumer alone.
- Type/name evidence: current IDA types, ChangeMan/ChangeManEntry/LObject docs, sibling family, and generated current output, with historical labels treated as leads only.
- Negative evidence: no function at the endpoint/padding, no padding refs, no direct-Application-only receiver set, no ChangeMan-field receiver use, no original symbol/header, and no reason to duplicate H or aggregate emission.
- Evidence ladder result: behavior/range/ownership are direct and very strong; source spelling/access is inferred but project-consistent. Current `auto_analysis_ready:false` does not invalidate the pass because server health is `ok`, Hex-Rays is ready, the session is active/not analyzing, and all bounded required calls succeeded.

## Evidence Checked

- Agent instructions: `Agent-B007/goal.md`; full `ntk-b-agent-workflow` skill and references; literal report template; score-blocker audit standard; `by-structure.md`.
- Current target and support: UID00019A, UID000198, UID00019B, UID000199, UID000195, UID00007D, UID0000KV, Application class/file, ChangeMan class/file/method pages, UID0000QI, UID0001P4, and caller support pages.
- Matching research search terms: `00019A`, `ApplicationUnregisterChangeListener`, `LObjectUnregisterChangeListener`, `0x004f4b50`, `ChangeMan_Unregister`, `common-base`, `g_pBackPane`, `g_pApplication`, and `g_pChangeMan`. The executed B003 `0000ZW` report was the strongest ownership lead; the old B007 report and sibling B004/B011 material were revalidated rather than copied.
- Generated read-only checks: `auto-generated/NexusTK/util/LObject.cpp`, `app/Application.cpp`, `ui/core/FrameChrome.cpp`, `map/MapPane.cpp`, and `ui/core/VideoPlayerPane.cpp`.
- Manual coverage evidence: historical by-memory UID00019A/UID0001P4 and by-global UID0000QI rows were read and exact replacement payloads drafted; supervisor later applied those payloads. By-class UID00007D and by-file UID0000KV required no replacement.
- Live IDA MCP database: `5a570ede`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x400000`.
- Live session recheck: MCP transport session `4ad6d5f9-cf66-4145-92ca-16bb4cf62b8d`; final health `status:ok`, Hex-Rays ready, strings cache ready (`2068`), session active and not analyzing. Final bounded lookup reconfirmed `LObject_UnregisterChangeListener` and `ChangeMan_Unregister`.
- Gate 1 repair live recheck: call `10` `idb_list` reconfirmed database `5a570ede` active and not analyzing; call `11` `server_health` returned `status:ok`, `hexrays_ready:true`, and strings cache ready; call `12` `inspect_items` inventoried every byte-item at `0x0067ab2c` through `0x0067ab2f` plus the following boundary; call `13` `get_comments` read regular/repeatable comments independently at every affected byte; calls `14` and `15` independently inventoried and comment-read the protected preceding/following boundary heads `0x0067ab28` and `0x0067ab30`.
- Negative checks: endpoint lookup, padding xrefs, direct-caller receiver diversity, target/callee caller counts, singleton data extent/comments, original-name evidence, duplicated generated definition, and header-declaration ownership.
- Failed/unavailable checks: none required for this conclusion. No MCP required call failed and the IDB session remained present through final recheck.
- Callback execution: B007 used short-lived edit leases only for ordinary destination docs, ran scoped validators, released every lease, and read back destinations/generated topology. B007 skipped report execution, IDA writes, manual coverage edits, and direct generated/audit/catalog/lifecycle edits as required. Subsequent Gate 2A, IDA, and manual coverage actions are explicitly supervisor-owned evidence.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 00019A | Exact function range is `0x004f4b50-0x004f4b6c`, size `0x1c`. | direct | lookup/function object, bytes, endpoint check | target Status/Evidence | incorporate | applied; B007 destination readback verified |
| C02 | 00019A | `0x004f4b6c-0x004f4b70` is separate four-byte `0xcc` padding with zero refs. | direct | item/bytes/xrefs | target Evidence/Range | incorporate | applied; B007 destination readback verified |
| C03 | 00019A | Target is ordinary `__thiscall` with implicit LObject owner and three stack args. | direct | assembly, `retn 0x0c`, prototype | target Behavior/ABI | incorporate | applied; B007 destination readback verified |
| C04 | 00019A | Sole internal callee is `ChangeMan_Unregister` at `0x0047ed80`. | direct | analyze/callees/xrefs | target Behavior/Evidence | incorporate | applied; B007 destination readback verified |
| C05 | 00019A | Seven callers comprise five BackPane receivers and two Application receivers. | direct | all caller decompiles/disassembly | target caller table | incorporate | preserved and B007 destination readback verified |
| C06 | 00019A | BackPane and Application both carry LObject at offset zero. | direct/inferred source | current constructor chains | target ownership analysis | incorporate | applied with both exact chains; B007 readback verified |
| C07 | 00019A | Best source shape is inherited `LObject::UnregisterChangeListener`, not Application or a free helper. | strong inference | C03+C05+C06+sibling family | target status/C++ | preserve | applied with rejected-owner evidence; B007 readback verified |
| C08 | 00019A | Parameter types are `LObject *`, `MessageType`, and `bool allMessages`. | direct plus spelling inference | target/callee types and branch use | target ABI/C++ | preserve | exact CPP/prose preserved; B007 readback verified |
| C09 | 00019A | Source return type is `void`. | direct | current prototype, callee, no consumer | target C++ | preserve | exact CPP/prose preserved; B007 readback verified |
| C10 | 00019A | Exact CPP block already matches the best behavior/source reconstruction. | very strong | target, live body, generated LObject.cpp | target formal CPP | preserve verbatim | applied verbatim; target and generated LObject readback verified |
| C11 | 00019A | Target H block must remain blank because declaration belongs in UID00007D class block. | strong | current class declaration/emitter structure | target formal H | preserve blank | preserved blank; class declaration readback verified |
| C12 | 00019A | Score moved `92/94 -> 93/94` after current evidence/handoff incorporation. | high | blocker audit, implemented repairs, independent supervisor validation | target metadata/rationale | preserve implemented score | applied `93/94`; supervisor Gate 2A command `000000018425` passed exit `0`, `ok: 1` |
| C13 | 00019A | Historical B007 source-neutral route remains useful but is superseded by constructor proof. | direct history | old report + executed B003 + live recheck | target Changes/history | historicalize | preserved and explicitly superseded; B007 readback verified |
| C14 | 00007D | Wrapper address sentence must use `0x004f4b30`, `0x004f4b50`, `0x004f4b70`. | direct | current function map | `by-class/LObject.md` Live IDA Evidence | correct text | applied exactly; validator `000000018351`; B007 readback verified |
| C15 | 0000QI/0001P4 | `0x0067ab2c` is a four-byte zero-initialized `ChangeMan *` singleton with 11 refs. | direct | bytes, item, xrefs, lifecycle docs | global/storage evidence | record semantic interval plus literal prestate | applied without claiming IDA mutation; validators `000000018352`/`000000018353`; B007 readback verified |
| C16 | 0000QI/0001P4 | Historical head byte `unk_67AB2C` plus three separately inventoried unnamed/untyped trailing byte-items were replaced by one four-byte `g_pChangeMan` item with exact type/comments. | direct + supervisor-verified action | historical per-byte prestate, verified backup, `make_data`, four-address readback, bytes/xrefs/neighbors, final save/hash | supervisor Gate 2B | preserve exact applied/readback state | `APPLIED_VERIFIED` by supervisor; reconciled into UID00019A/UID0000QI/UID0001P4; B007 performed no IDA mutation |
| C17 | 00019A | Historical by-memory target row required the exact `93%` LObject replacement with supervisor-verified IDA wording. | direct + supervisor validation | historical row, exact payload, current supervisor-applied row, command `000000018430` | by-memory manual coverage | preserve applied row | supervisor applied and validated; exit `0`, `ok: 1` |
| C18 | 0001P4/0000QI | Historical storage/global rows trailed source scores and required exact `88%`/`91%` replacements. | direct + supervisor validation | historical rows, exact payloads, current supervisor-applied rows, commands `000000018430`/`000000018421` | by-memory/by-global manual coverage | preserve applied rows | supervisor applied and validated; both exit `0`, `ok: 1` |
| C19 | 00019A | Current generated route is LObject.cpp and no duplicate Application definition remains. | direct generated read | current generated files | target generated-state prose | update current state | applied; post-validator B007 readback found exact UID00019A definition only in `util/LObject.cpp` and no matching definition/call in `app/Application.cpp` |
| C20 | 00019A | Caller-local tag values are exact; source constant spellings remain caller-owned. | direct/inferred | call sites and caller docs | target caller evidence | preserve values, avoid overclaim | preserved in caller table/negative evidence; B007 readback verified |

## Positive Evidence Summary

- Exact 28-byte body forwards implicit ECX plus listener/message/flag to the singleton ChangeMan unregister method and returns with callee cleanup for three stack arguments.
- All seven code callers were inspected, not sampled. Five load `g_pBackPane`; two load `g_pApplication`; all pass `false`.
- `Application` calls the LObject constructor on its primary object address before installing Application vtables.
- `BackPane` calls `Pane`, which calls `GrafPort`, which calls the same LObject constructor at the same object address before installing derived vtables.
- Adjacent `RegisterChangeListener` and `ForwardMessage` use the same implicit-receiver/singleton-forwarder pattern inside the LObject runtime shell.
- ChangeMan callee behavior exactly matches filtered unregister: same-owner scan, null-listener wildcard, all-messages or matching-type condition, one-entry removal, and index/count repair.
- Current IDA already has human names/prototypes for the target and callee. Current generated LObject output independently reflects the same source shape.
- Strongest inference chain: mixed receivers exclude direct Application/BackPane ownership; offset-zero LObject construction unifies both; ordinary member ABI plus adjacent family fixes the LObject member route.

## IDA MCP Facts

- Function map: `0x004f4b30` `LObject_RegisterChangeListener` size `0x1c`; `0x004f4b50` `LObject_UnregisterChangeListener` size `0x1c`; `0x004f4b6c` not a function; `0x004f4b70` `LObject_ForwardMessage` size `0x16`; `0x0047ed80` `ChangeMan_Unregister` size `0x98`.
- Target prototype: `void __thiscall(LObject *this, LObject *listener, unsigned int messageType, bool allMessages)`.
- Target bytes: `55 8b ec ff 75 10 ff 75 0c ff 75 08 51 8b 0d 2c ab 67 00 e8 18 a2 f8 ff 5d c2 0c 00`.
- Target assembly: push `allMessages`, `messageType`, `listener`, and ECX owner; load singleton from `0x0067ab2c`; call `ChangeMan_Unregister`; `retn 0x0c`.
- Target analysis: one basic block, cyclomatic complexity 1, no strings, seven callers, one callee.
- Target current comments: address regular absent; address repeatable absent; function regular exactly `LObject::UnregisterChangeListener inherited wrapper forwarding to g_pChangeMan.`; function repeatable absent.
- Padding item: `[0x004f4b6c,0x004f4b70)`, size 4, bytes `cc cc cc cc`, name absent, type absent, regular/repeatable comments absent, zero xrefs.
- Singleton bytes: `[0x0067ab2c,0x0067ab30)` are `00 00 00 00`.
- Historical singleton prestate head: head `0x0067ab2c`, end `0x0067ab2d`, size 1, name `unk_67AB2C`, type `ChangeMan *`, regular comment absent, repeatable comment absent.
- Historical singleton prestate trailing items: `0x0067ab2d`, `0x0067ab2e`, and `0x0067ab2f` were three distinct one-byte items, each with its queried address as head, the next byte as end, size/width 1, name absent, type absent, `is_code:false`, `is_data:false`, regular comment absent, and repeatable comment absent.
- Current supervisor-verified singleton item: all queries at `0x0067ab2c-0x0067ab2f` resolve to one head `0x0067ab2c`, end `0x0067ab30`, size 4, `is_data:true`, name `g_pChangeMan`, type `ChangeMan *`, and the exact accepted regular/repeatable comments.
- Protected boundary heads: `0x0067ab28` remains a separate item typed `BrowserControlPane *` with name/comments absent; `0x0067ab30` remains a separate item typed `EventDispatcher *` with name/comments absent. The current ChangeMan item ends exactly at, and does not consume, `0x0067ab30`.
- Singleton xrefs: exactly 11 at `0x00464c3e`, `0x0046792f`, `0x00467abf`, `0x0047ecb2`, `0x0047ecb9`, `0x0047ed3f`, `0x0047ef40`, `0x0047ef72`, `0x004f4b3d`, `0x004f4b5d`, and `0x004f4b77`.
- Constructor chain: `Application` `0x00463310 -> LObject` `0x004f4a80` at offset zero; `BackPane` `0x00467830 -> Pane` `0x00544460 -> GrafPort` `0x004b8bf0 -> LObject` `0x004f4a80`, preserving the primary object address.
- Final health/readback: active IDB `5a570ede`, `status:ok`, `hexrays_ready:true`, strings ready; post-Gate2B bounded lookups returned the exact target/callee and singleton/protected states above. Final `idb_save` returned `ok:true`; packed IDB size is `143190108` bytes, SHA256 `4BC619B7E9B9D2866DB15B1A5DF260AACAD08A520CDD2BDFB9D4776DA975512E`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f4b50-0x004f4b6c` | UID00019A target | exact unregister member | true | UID00007D LObject | `92/94 -> 93/94` | source-ready leaf |
| `0x004f4b6c-0x004f4b70` | no separate UID | alignment padding | no source | UID000199 index context | n/a | protected non-code |
| `0x004f4b30-0x004f4b4c` | UID000198 | sibling register member | true | UID00007D | `92/94` | corroborating, no target change |
| `0x004f4b70-0x004f4b86` | UID00019B | sibling forward member | true | UID00007D | `91/94` | corroborating, no target change |
| `0x004f4b30-0x004f4b6c` | UID000199 | pair/index container | false | none | `90/94` | non-emitting |
| `0x0047ed80-0x0047ee18` | UID0000ZY | ChangeMan filtered unregister | true | ChangeMan | current support score | sole target callee |
| `0x0067ab2c-0x0067ab30` | UID0001P4 / UID0000QI | singleton storage/semantic global | true | ChangeMan file | `88/91`, `91/90` | Gate 2B `APPLIED_VERIFIED`; exact one-item readback reconciled |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004612ed` | AboveFrame ordinary destructor path | `g_pBackPane->UnregisterChangeListener(this, 0x676f6f67, false)` |
| `0x00461734` | AboveFrame scalar-deleting path | same inherited call; compiler wrapper listener is the object block |
| `0x004b756d` | FramePartPane ordinary destructor path | BackPane receiver, listener `this`, tag `0x676f6f67`, false |
| `0x004b7604` | FramePartPane scalar-deleting path | same inherited call through compiler wrapper |
| `0x00504584` | MapPane cleanup | BackPane receiver, MapPane listener, tag `0x676f6f67`, false |
| `0x005c00dd` | VideoPlayerPane ordinary destructor | Application receiver, listener `this`, tag `0x7465726d`, false |
| `0x005c03f4` | VideoPlayerPane scalar-deleting destructor | same Application inherited call through compiler wrapper |
| `0x004f4b63 -> 0x0047ed80` | sole direct callee edge | target calls `ChangeMan_Unregister`; callee has no other direct caller |
| `0x004f4b5d -> 0x0067ab2c` | singleton data read | wrapper obtains ChangeMan receiver from global slot |

The eleven singleton refs additionally cover ChangeMan publication/clear lifecycle, Application cleanup, BackPane teardown, and all three adjacent LObject wrappers. They support singleton identity but do not move UID00019A into ChangeMan ownership.

## Documentation Evidence And IDA Status

- Current target and LObject class/file docs support the LObject member conclusion and exact source body.
- Application class/file docs now correctly describe inherited use and no duplicate definition.
- ChangeMan docs support the `LObject *owner/listener`, `MessageType`, and `bool allMessages` API and filtered unregister semantics.
- UID000198 and UID00019B corroborate the adjacent member family; UID000199 correctly remains a no-emission index.
- The executed B003 report's common-base result is confirmed by current live constructor chains.
- Stale target content: old current-state `sub_4F4B50`/raw prototype/type-query/generated mismatch claims should be dated or replaced with current IDA/generated state.
- Stale support content: `by-class/LObject.md` line 93 uses three incorrect wrapper addresses.
- Manual coverage: historical target/storage/global rows were stale; supervisor applied the exact replacement payloads and validated current by-memory/by-global reports.
- Current IDA status: target/callee names and types remain source-facing; supervisor Gate 2B replaced only the historical four one-byte singleton heads with one verified size-4 `g_pChangeMan` / `ChangeMan *` data item and preserved all bounded no-change constraints.

## Ranked Ownership Analysis

### 1. LObject class / LObject.cpp

- Evidence for: implicit ECX owner; mixed BackPane/Application receivers; both receivers construct LObject at offset zero; adjacent register/forward members; LObject runtime-shell placement; current IDA name/type; current generated route.
- Evidence against: no PDB/header text proves exact method spelling/access qualifier.
- Decision: accepted direct owner/emitter and source route. The spelling uncertainty affects confidence, not ownership or code eligibility.

### 2. Application class / Application.cpp

- Evidence for: two callers use `g_pApplication`; historical docs once modeled an Application method.
- Evidence against: five callers use `g_pBackPane`; an Application member cannot legally receive BackPane; current Application docs/generated output treat the calls as inherited.
- Decision: rejected as definition owner; accepted only as one derived receiver/consumer.

### 3. Source-neutral free helper

- Evidence for: historical B007 intermediate route could represent both receiver values with an explicit `owner` parameter.
- Evidence against: machine ABI is ordinary member `__thiscall`, both receivers share a proven base at offset zero, and adjacent wrappers form the base API. A free helper would be less plausible precompiled source and would require a nonstandard source signature.
- Decision: rejected and retained only as historical reasoning.

### 4. ChangeMan class / ChangeMan.cpp

- Evidence for: target calls ChangeMan and reads its singleton.
- Evidence against: target's ECX is the LObject owner; ChangeMan is loaded separately; wrapper has a distinct caller surface and source responsibility.
- Decision: rejected as target owner; accepted callee/global support owner.

### 5. UID000199 aggregate or caller classes

- Evidence for: aggregate spans the pair; caller classes provide receiver/listener context.
- Evidence against: aggregate is intentionally non-emitting; callers consume inherited API and do not define it.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Not applicable. The established `NexusTK/util/LObject.cpp` route is exact; no new helper file, class, interface, aggregate, or UID is warranted.

## Source Placement

- Recommended source: `NexusTK/util/LObject.cpp`, class `LObject`, as an out-of-class member definition.
- Header declaration ownership: the [UID:00007D] class declaration, conceptually `LObject.h`; do not emit a duplicate declaration from this by-memory child.
- Why it fits: the constructor/vtable shell and adjacent notification wrappers are common base-object infrastructure used by UI and Application-derived objects.
- Rejected `Application.cpp`: only one receiver family and inherited consumer expressions.
- Rejected `ChangeMan.cpp`: owns implementation of registration storage/filtering, not the caller-facing LObject convenience API.
- Rejected pane files: call sites only.
- Remaining uncertainty: exact original filesystem capitalization/header split and access section are not recoverable from the binary, but the class/file route is not meaningfully uncertain.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x004f4b50,0x004f4b6c)`, 28 bytes.
- Preceding bytes `[0x004f4b4c,0x004f4b50)` are four `0xcc` bytes separating UID000198.
- Following bytes `[0x004f4b6c,0x004f4b70)` are four `0xcc` bytes separating UID00019A from UID00019B. Current IDA models this as a four-byte data/padding item with no name/type/comments/xrefs.
- No instruction, xref, fallthrough, exception edge, or decompiler body crosses the endpoint.
- UID000199 remains a reviewed non-emitting index over exact child wrappers and intervening padding. It must not absorb or duplicate UID00019A source.
- No child creation, range expansion, merge, ignored-range reclassification, or UID change is recommended.
- Protected boundary rule: Gate 2B must not functionize, rename, type, or comment the padding as source data.

## Negative Evidence Summary

- Mixed caller receivers disprove direct Application ownership; consumer count alone does not establish definition ownership.
- Physical adjacency to LObject corroborates but does not independently prove ownership; constructor chains and ABI provide the proof.
- Reading `g_pChangeMan` and calling `ChangeMan_Unregister` do not make the wrapper a ChangeMan member because ChangeMan is loaded into ECX only after the LObject owner has been pushed.
- No code/xref reaches `0x004f4b6c`; it is not a hidden tail, thunk, helper, or source constant.
- No original symbol, header, or string proves exact `UnregisterChangeListener`, `MessageType`, `allMessages`, public access, or filename spelling. Raw IDA labels are therefore not retained; best human names are inferred from behavior and project convention.
- Historical `ChangeListener` and `ChangeMessageScope` declarations are contradicted by the completed LObject/ChangeMan family analysis and bool behavior.
- No caller consumes a target return, and current target/callee types are void; returning an integer would preserve a decompiler artifact, not developer source.
- No independent H fragment belongs to this exact range. Emitting one would duplicate or misplace the class declaration.

## IDA Rename / Type / Comment Recommendations

The B agent remained read-only. Supervisor Gate 2B is `APPLIED_VERIFIED` in active IDB/session `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` / `5a570ede`; B007 performed no IDA mutation. The literal four-head state below is the preserved historical supervisor prestate, followed by the exact supervisor operation and final readback.

### Exact historical per-byte item and comment inventory

Before mutation, `inspect_items` and `get_comments` were called with every affected address, not only the proposed item head. Empty returned strings are recorded literally as absent. `Width` below is historical prestate item width, not the intended 32-bit pointer width.

| Queried address | Current head | Current end | Current size / width | Current name | Current type | Current classification | Regular comment | Repeatable comment |
| --- | --- | --- | ---: | --- | --- | --- | --- | --- |
| `0x0067ab2c` | `0x0067ab2c` | `0x0067ab2d` | 1 byte | `unk_67AB2C` | `ChangeMan *` | `is_code:false`; `is_data:false` | absent | absent |
| `0x0067ab2d` | `0x0067ab2d` | `0x0067ab2e` | 1 byte | absent | absent | `is_code:false`; `is_data:false` | absent | absent |
| `0x0067ab2e` | `0x0067ab2e` | `0x0067ab2f` | 1 byte | absent | absent | `is_code:false`; `is_data:false` | absent | absent |
| `0x0067ab2f` | `0x0067ab2f` | `0x0067ab30` | 1 byte | absent | absent | `is_code:false`; `is_data:false` | absent | absent |

Historical bounded-neighbor inventory: queried `0x0067ab28` had head `0x0067ab28`, end `0x0067ab29`, size/width 1 byte, name absent, type `BrowserControlPane *`, `is_code:false`, `is_data:false`, and both comments absent. Queried `0x0067ab30` had head `0x0067ab30`, end `0x0067ab31`, size/width 1 byte, name absent, type `EventDispatcher *`, `is_code:false`, `is_data:false`, and both comments absent. These protected boundary items were not inputs to the ChangeMan item replacement.

Verified backup before mutation: `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B007-UID00019A-20260728_1615.i64`, `143190107` bytes, SHA256 `6DEB6CF617A6461568CA19BF32AFB8980BA876F27D1A1102F82E4A9FAED95F19`, byte-identical to the packed pre-mutation IDB.

| Address / entity | Literal historical prestate | Supervisor action/current readback | Evidence / confidence | Disposition and safety/readback |
| --- | --- | --- | --- | --- |
| `0x004f4b50-0x004f4b6c`, function | Name `LObject_UnregisterChangeListener`; declaration `void __thiscall(LObject *this, LObject *listener, unsigned int messageType, bool allMessages)`; function extent size `0x1c`; address regular comment absent; address repeatable comment absent; function regular comment exactly `LObject::UnregisterChangeListener inherited wrapper forwarding to g_pChangeMan.`; function repeatable comment absent. | No mutation. Current readback preserves the exact function name, size `0x1c`, member prototype, boundary, and function comment. | Current body, all callers, constructor chains, and sibling family. Very strong. | `NO_CHANGE / APPLIED_VERIFIED constraint`. Byte/type/comment identity passed post-save readback. |
| `0x0067ab2c-0x0067ab30`, singleton data | Four separate one-byte items exactly inventoried above: the head byte was named/typed, while `0x0067ab2d`, `0x0067ab2e`, and `0x0067ab2f` were independently unnamed, untyped, and uncommented. Bytes were `00 00 00 00`; the slot had 11 xrefs. | Supervisor `make_data` replaced only those four heads with one size-4 `is_data:true` item over `[0x0067ab2c,0x0067ab30)`, named `g_pChangeMan`, typed `ChangeMan *`, regular comment exactly `Process-wide ChangeMan singleton pointer used by LObject registration, unregistration, and dispatch wrappers.`, repeatable comment exactly `ChangeMan *g_pChangeMan;`. All four queried addresses resolve to head `0x0067ab2c`, end `0x0067ab30`, size 4, exact name/type/comments. | Four-byte pointer storage, lifecycle writes/clears, 11 refs, current source declaration, wrapper family. Very strong. | `APPLIED_VERIFIED`. Bytes remain `00 00 00 00`; exact refs remain `0x464c3e`, `0x46792f`, `0x467abf`, `0x47ecb2`, `0x47ecb9`, `0x47ed3f`, `0x47ef40`, `0x47ef72`, `0x4f4b3d`, `0x4f4b5d`, `0x4f4b77`; protected neighbors remain separate with exact historical types and blank names/comments. |
| `0x004f4b6c-0x004f4b70`, padding data | Name absent; type absent; item extent size 4; bytes `cc cc cc cc`; regular comment absent; repeatable comment absent; zero xrefs. | No mutation. Current readback remains `cc cc cc cc` padding and a non-function. | Boundary bytes and negative xrefs. Direct. | `NO_CHANGE / APPLIED_VERIFIED constraint`. Protected padding readback passed. |

Supporting dependencies needed no Gate 2B action: `g_pBackPane` at `0x0067a740` was already a size-4 `BackPane *` named global; `g_pApplication` at `0x0067ab1c` was already a size-4 `Application *` named global. Their existing comments and types remain unchanged.

Required supporting type invariant: 32-bit x86 pointer width is four bytes; `ChangeMan *` must cover exactly `[0x0067ab2c,0x0067ab30)`. No UDT layout or local-variable action is required.

Final `idb_save` returned `ok:true`. The packed IDB is `143190108` bytes with SHA256 `4BC619B7E9B9D2866DB15B1A5DF260AACAD08A520CDD2BDFB9D4776DA975512E`; post-save health and all bounded readbacks passed.

## First-Draft C++ Recommendation

- Eligible for draft/final reconstruction: yes. Behavior, ABI, owner, range, and types are sufficiently resolved.
- CPP block disposition: preserve/apply this exact formal block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LObject::UnregisterChangeListener(LObject *listener,
                                       MessageType messageType,
                                       bool allMessages)
{
    g_pChangeMan->Unregister(this, listener, messageType, allMessages);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- H block disposition: preserve/apply this exact blank formal block:

```cpp
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

- Exact no-header-code proof: UID00019A owns only the out-of-class definition range. UID00007D already declares `UnregisterChangeListener(LObject *, MessageType, bool)` inside `class LObject`; a child H fragment would be a duplicate or invalid namespace-scope member declaration.
- Behavior preservation: the source emits the same implicit owner, singleton load, argument order, filtered unregister call, and void return contract.
- Human source shape: ordinary inherited member syntax, descriptive project-wide types, no explicit `__thiscall`, no raw addresses, no `sub_`/`unk_` labels, no manual stack operations, and no compiler deleting-wrapper artifacts.
- Naming style: PascalCase methods/types, `g_p` global pointer prefix, lower camel parameter names, consistent with current LObject/ChangeMan project docs.
- Third-party import directive: not applicable; this is original NexusTK project code.

## Final Recommendation

- UID00019A remains exact LObject-owned/emitted reconstructable source at the current path/range.
- Preserve owner/emitter `00007D`, blank optional position, `Nested:0`, exact CPP, and blank target H.
- Target completion `92 -> 93` is callback-applied; confidence remains `94`.
- Current live function/caller/callee/constructor/global facts and corrected generated/IDA wording are callback-applied while dated B007/B003 history is preserved.
- The three wrapper addresses in `by-class/LObject.md` are callback-corrected.
- Supervisor Gate 2B is `APPLIED_VERIFIED`: the exact `0x0067ab2c` item/action/readback/save evidence is reconciled, and target/padding no-change constraints passed.
- Supervisor applied the exact manual coverage rows below and validated both coverage reports; B007 did not edit them.
- No new UID, split, merge, source file, aggregate emission, Application definition, ChangeMan definition, caller-file definition, or target H code is recommended.
- Future work outside this assignment: project-wide recovery of original identifier/access/header spelling if new source symbols appear. No such future evidence is required for current C++.

## Recommended Target Doc Changes

- Callback state: every ordinary target-doc change listed below, including post-Gate2B reconciliation, was applied by B007 and independently validated by the supervisor under post-IDA Gate 2A; these are completed states, not future instructions.
- Callback-applied target path: `by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md`.
- Callback-applied metadata: changed `COMPLETION:92` to `COMPLETION:93`; preserved all other metadata and `Nested:0`.
- Callback-applied formal blocks: preserved the exact CPP and blank H text above.
- Callback-applied current evidence: replaced stale current-state IDA prose with current names/prototype/comments, exact one-block analysis, endpoint/padding state, and final health/session evidence.
- Callback-applied constructor proof: added the complete Application and BackPane offset-zero LObject constructor chains.
- Callback-preserved history: retained the seven-caller table and historical B007 mixed-receiver finding, and explicitly marked the source-neutral helper/free-helper route superseded by current common-base proof.
- Callback-applied generated-state prose: replaced the stale mismatch with current read-only state, including the exact definition in `auto-generated/NexusTK/util/LObject.cpp`, no duplicate definition in `Application.cpp`, and inherited caller expressions in their existing source routes.
- Callback-applied Gate 2B reconciliation: preserved the four-one-byte state as historical supervisor prestate and added the exact verified backup, operation, one-item readback, unchanged bytes/xrefs/neighbors/target/padding, final save, packed-IDB hash/size, and post-save health. B007 recorded supervisor evidence and performed no IDA mutation.
- Callback-applied rationale: expanded the score rationale to cover every investigated blocker and why the implemented state is `93/94`, not merely that the old route was accepted.
- Callback-preserved negative evidence: retained rejected Application, free-helper, ChangeMan, aggregate, and caller ownership alternatives as historical/negative evidence.

## Recommended Support Doc Changes

- Callback state: the ordinary support-doc corrections, historical prestates, and post-IDA readback reconciliations below were applied by B007 and independently validated by the supervisor under post-IDA Gate 2A. No further B007 support-doc reconciliation remains.
- `by-class/LObject.md`: callback applied the exact address correction from `0x004f4aa0`, `0x004f4ae0`, and `0x004f4b40` to `0x004f4b30`, `0x004f4b50`, and `0x004f4b70`, preserving the rest of the sentence and metadata; supervisor Gate 2A command `000000018426` passed exit `0`, `ok: 1`.
- `by-global/g_pChangeMan.md`: callback preserved the literal four-one-byte-item state as historical supervisor prestate, then reconciled the exact verified backup, `make_data`, one-item name/type/comments/readback, unchanged bytes/11 refs/neighbors/target/padding, final save/hash, and post-save health while preserving `91/90`, owner/emitter UID0000I2, and the sole semantic source definition; supervisor Gate 2A command `000000018427` passed exit `0`, `ok: 1`.
- `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md`: callback preserved historical `dword_67AB2C dd ?` semantics and four-head pre-mutation evidence, then reconciled the exact current one-item IDA state and full backup/action/readback/save evidence while preserving the raw-storage/no-duplicate-emission role and `88/91` metadata; supervisor Gate 2A command `000000018429` passed exit `0`, `ok: 1`.
- `by-class/Application.md` and `by-file/Application.md`: inspected; current inherited LObject route is correct, so no change recommended.
- UID000198, UID00019B, UID000199, UID000195, ChangeMan class/file/methods, and caller docs: inspected; no target-specific content change required.
- Generated/audit/catalog files: B007 made no direct edits. Callback validators and generated readback are already recorded under `Validator Results`; any later refresh or reconciliation remains supervisor-authorized only.

## Score And Metadata Recommendation

- Pre-callback/historical target state: `92/94`, owner/emitter `00007D`, reconstructable true, blank position, exact CPP, blank H, `Nested:0`.
- Current implemented and supervisor-validated target state: `93/94`; all ownership/emitter/reconstructable/position/nested/formal states remain unchanged. Independent post-IDA Gate 2A command `000000018425` passed exit `0`, `ok: 1`.
- Implemented completion-increase rationale: the callback incorporated current live IDA names/types/comments, all current constructor chains, the historical singleton prestate plus supervisor-applied exact action/readback/save evidence, final MCP liveness evidence, current generated state, stale-support correction, exhaustive blocker audit, and exact manual coverage payloads now applied/validated by the supervisor.
- Confidence unchanged: direct machine/ownership evidence is already very strong, while exact original method/typedef/parameter/access/header spelling is still inferred. Raising confidence would misstate source-text recovery.
- Reason not higher: no PDB/original header/source proves exact identifier spelling, access qualifier, or header organization; Gate 2B is applied/verified and no longer a confidence blocker, but UID00019A alone cannot settle unrelated LObject runtime-class/string-family questions.
- Reason not lower: every instruction, boundary, caller, callee, receiver, constructor chain, argument semantic, singleton ref, source route, and formal line has current direct or independently corroborated support.
- Score-improvement attempts:
  - Ownership blocker: all callers plus both complete constructor chains; resolved to LObject.
  - Free-helper blocker: ABI and common base; rejected.
  - Type blocker: target/callee prototypes, entry layout, branch behavior, all caller values; resolved to LObject/MessageType/bool.
  - Return blocker: current void prototypes and no consumers; resolved.
  - Name blocker: current IDA/project family and rejected raw names; best human names selected, exact original spelling retained only as confidence uncertainty.
  - Range blocker: exact function/padding items, bytes, endpoint, xrefs; resolved.
  - Source/header blocker: class/file owner and class declaration; resolved, target H blank with proof.
  - Singleton compiler-name/width blocker: Gate 2B `APPLIED_VERIFIED`; exact current one-item readback/save evidence reconciled.
  - Generated/manual coverage blocker: exact rows are supervisor-applied and coverage validators passed; resolved.

## Open Questions With Attempted Resolution

- Exact original method spelling/access: searched current IDA names/types/comments, strings/type leads, sibling APIs, generated source, current by-* docs, and matching reports. No original symbol/header survives. Best resolution is public-looking `UnregisterChangeListener` in the existing LObject API; this is high-probability human source and does not block code. It caps confidence at 94.
- `MessageType` exact typedef spelling: current IDA sees `unsigned int`; ChangeMan/LObject project docs consistently use `MessageType`, and caller tags are 32-bit. Best resolution is `MessageType`; exact original typedef text remains unrecoverable and does not alter behavior.
- `allMessages` exact parameter spelling: current bool behavior and API family strongly support the name. Historical `scope`/enum wording is rejected. Exact spelling remains inferred only.
- Header file/access section: class declaration belongs in the LObject class owner; exact original header filename/access section is not embedded in the executable. Blank target H is still exact for emitter composition.
- Singleton current IDA shape: fully resolved and `APPLIED_VERIFIED`. Historical four-head prestate, verified backup, exact action/safety/readback, unchanged protected state, final IDB save/hash, and post-save health are recorded; B007 performed no IDA mutation.
- Gate 2A/manual coverage state: fully resolved. Four independent ordinary-doc validators and both coverage-report validators passed the explicit supervisor checks; only fresh exact-artifact report audit/execution remains.
- No unresolved in-scope question prevents score movement, source emission, ownership, range, support repair, or supervisor execution.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-application rows:
  - `by-memory/-coverage-report.md` line 2071 had stale Application title/path, `82%`, and an unassigned/blank-C++ description.
  - `by-memory/-coverage-report.md` line 4491 had UID0001P4 `84%` while the source page was `88`.
  - `by-global/-coverage-report.md` line 61 had UID0000QI `89%` while the source page was `91`.
  - `by-class/-coverage-report.md` line 289: UID00007D `90%`, very-strong, current route; no replacement needed.
  - `by-file/-coverage-report.md` line 148: UID0000KV `90%`, very-strong, current route; no replacement needed.
- Supervisor-applied payload for the exact UID00019A row in `by-memory/-coverage-report.md`:

```markdown
    - [UID:00019A][0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener](by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md) 0x004f4b50-0x004f4b6c | method | LObjectUnregisterChangeListener : reconstructable : 93% : very-strong : Exact inherited LObject member forwards this, an LObject listener, MessageType, and bool allMessages to g_pChangeMan->Unregister; seven callers, mixed BackPane/Application receivers, offset-zero common-base construction, callee behavior, range padding, exact C++, and supervisor-verified IDA readback are documented.
```

- Supervisor-applied payload for the exact UID0001P4 row in `by-memory/-coverage-report.md`:

```markdown
    - [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md) 0x0067ab2c-0x0067ab30 | global pointer | g_pChangeMan : reconstructable : 88% : strong : ChangeMan singleton pointer storage with exact four-byte zero state, 11 lifecycle/consumer xrefs, semantic-global coverage, and supervisor-verified IDA data width, name, type, and comments documented.
```

- Supervisor-applied payload for the exact UID0000QI row in `by-global/-coverage-report.md`:

```markdown
- [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md) : reconstructable : 91% : strong : ChangeMan singleton definition with exact 0x0067ab2c four-byte storage, 11 lifecycle/consumer xrefs, source definition, and supervisor-verified IDA data width, name, type, and comments documented; final header declaration spelling remains inferred.
```

- Applied/validation state: the supervisor applied all three exact payloads. `by-memory/-coverage-report.md` command `000000018430` (`2026-07-28T16:22:31-04:00`) passed exit `0`, `ok: 1`; only unrelated existing missing refs UID0003MT, UID00039L, and UID0003T6 remained. `by-global/-coverage-report.md` command `000000018421` passed exit `0`, `ok: 1`; only unrelated existing missing ref UID0003MS remained.
- B007 attribution: B007 did not edit either coverage report. Manual coverage remained supervisor-owned throughout.
- No validator-owned `auto-generated/-ag-*` text is proposed.

## Follow-Up Actions

- Supervisor Gate 2A: complete; commands `000000018425`, `000000018426`, `000000018427`, and `000000018429` independently passed and matched destination/formal/generated topology.
- Supervisor Gate 2B: `APPLIED_VERIFIED`; no repeat IDA action is requested or implied.
- Supervisor manual coverage and coverage validation: complete under commands `000000018430` and `000000018421`; unrelated missing refs remain outside UID00019A scope.
- Remaining supervisor lifecycle: perform a fresh exact-artifact Gate 1/Gate 2 audit on this current report revision, then run only the supervisor-owned report execution flow. B007 must not execute or move the report.
- A-agent actions: none.
- B007 future research: none unless Gate 1 identifies a literal omission or current evidence contradiction; repair this same artifact rather than rewriting it.

## Confidence

- Recommendation confidence: 94/100. Owner, behavior, range, source route, and formal code are independently supported by current binary facts and project structure.
- Score confidence: high. `93/94` reflects complete target-specific documentation without claiming recovered source text.
- Closure confidence: high. Supervisor Gate 2A, Gate 2B, exact manual coverage application, and both coverage validators are complete from explicit command/readback evidence; only exact-artifact audit and execution remain lifecycle work.
- Remaining uncertainty: exact original method/typedef/parameter/access/header spelling only. These are resolved by best human-source inference for current reconstruction and do not justify raw decompiler names or blank code.

## Validator Results

- `python .\tools\validator.py --mode file --file "by-memory\0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md" --apply --queue-timeout 240`: command `000000018350`, timestamp `2026-07-28T15:52:55-04:00`, exit `0`, `ok: 1`, completion update UID00019A to `93`, generated refresh deferred.
- `python .\tools\validator.py --mode file --file "by-class\LObject.md" --apply --queue-timeout 240`: command `000000018351`, timestamp `2026-07-28T15:53:21-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- `python .\tools\validator.py --mode file --file "by-global\g_pChangeMan.md" --apply --queue-timeout 240`: command `000000018352`, timestamp `2026-07-28T15:53:51-04:00`, exit `0`, `ok: 1`, stats-row update UID0000QI, generated refresh deferred.
- `python .\tools\validator.py --mode file --file "by-memory\0x0067ab2c-0x0067ab30.g_pChangeMan.md" --apply --queue-timeout 240`: command `000000018353`, timestamp `2026-07-28T15:54:20-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- Historical pre-Gate2B destination readback confirmed UID00019A `93/94`, owner/emitter `00007D`, exact CPP/blank H; exact UID00007D address correction; unchanged UID0000QI `91/90` semantic definition and UID0001P4 `88/91` no-duplicate marker; then-pending IDA text on both singleton pages; and no B007 leases remaining. Later Gate 2B/reconciliation evidence below supersedes only that pending-state wording.
- Generated readback: `auto-generated/NexusTK/util/LObject.cpp` contains the UID00019A marker at completion `93`, confidence `94`, followed by the exact `LObject::UnregisterChangeListener` definition. Search of `auto-generated/NexusTK/app/Application.cpp` returned no `Application::UnregisterChangeListener`, `LObject::UnregisterChangeListener`, or `UnregisterChangeListener` match, so no duplicate Application definition remains. B007 did not directly edit either generated file.
- Post-Gate2B reconciliation validator: `python .\tools\validator.py --mode file --file "by-memory\0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md" --apply --queue-timeout 240 --wait-generated`: command `000000018420`, timestamp `2026-07-28T16:15:15-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- Post-Gate2B reconciliation validator: `python .\tools\validator.py --mode file --file "by-global\g_pChangeMan.md" --apply --queue-timeout 240 --wait-generated`: command `000000018422`, timestamp `2026-07-28T16:16:27-04:00`, exit `0`, `ok: 1`, UID0000QI stats-row update, generated refresh completed.
- Post-Gate2B reconciliation validator: `python .\tools\validator.py --mode file --file "by-memory\0x0067ab2c-0x0067ab30.g_pChangeMan.md" --apply --queue-timeout 240 --wait-generated`: command `000000018424`, timestamp `2026-07-28T16:17:25-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- Intermediate generated readback after `000000018424`: LObject and ChangeMan output retained exact UID00019A/UID0000QI/UID0001P4 source roles and scores.
- Final target-rationale reconciliation validator: `python .\tools\validator.py --mode file --file "by-memory\0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md" --apply --queue-timeout 240 --wait-generated`: command `000000018428`, timestamp `2026-07-28T16:21:38-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- Final generated readback: `auto-generated/NexusTK/util/LObject.cpp` has validator-owned header command `000000018426`, timestamp `2026-07-28T16:21:25-04:00`, and exact UID00019A `93/94` member source. `auto-generated/NexusTK/app/ChangeMan.cpp` has foreground header command `000000018428`, timestamp `2026-07-28T16:21:38-04:00`, contains UID0000QI `91/90` as the sole `ChangeMan *g_pChangeMan = NULL;` definition, and retains UID0001P4 `88/91` as covered-by-global comments only.
- Fresh independent supervisor post-IDA Gate 2A validators:
  - UID00019A target command `000000018425`, `2026-07-28T16:21:23-04:00`, exit `0`, `ok: 1`.
  - UID00007D class command `000000018426`, `2026-07-28T16:21:25-04:00`, exit `0`, `ok: 1`.
  - UID0000QI global command `000000018427`, `2026-07-28T16:21:28-04:00`, exit `0`, `ok: 1`.
  - UID0001P4 raw-storage command `000000018429`, `2026-07-28T16:21:40-04:00`, exit `0`, `ok: 1`.
- Supervisor Gate 2A result: all current destination states match the Gate 2B applied/readback/save evidence and exact formal/generated topology.
- Supervisor coverage validators:
  - `by-memory/-coverage-report.md` command `000000018430`, `2026-07-28T16:22:31-04:00`, exit `0`, `ok: 1`; only unrelated existing missing refs UID0003MT, UID00039L, and UID0003T6.
  - `by-global/-coverage-report.md` command `000000018421`, exit `0`, `ok: 1`; only unrelated existing missing ref UID0003MS.
- Unresolved target-specific validator warnings/errors: none. The listed missing refs are unrelated existing coverage issues. Project-wide advisory counts and validator-owned generated/projected-stat/registry refreshes are not direct B007 edits.
- `execute_report`, dry-run execution, lifecycle/registry/archive commands, and manual report moves were not run.

## Changed Files

- Created: none.
- Modified ordinary docs:
  - `by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md`
  - `by-class/LObject.md`
  - `by-global/g_pChangeMan.md`
  - `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md`
- Post-Gate2B reconciliation ordinary edits were limited to UID00019A, UID0000QI, and UID0001P4. `by-class/LObject.md` was inspected and required no current-state reconciliation edit.
- Modified report: `tools/leaser/Agents/Agent-B007/research/00019A-ApplicationUnregisterChangeListener-source-quality.md`.
- Final report-state reconciliation callback: B007 modified only this same report; no ordinary, coverage, generated, audit/catalog/lifecycle, goal/notes, or IDA file was edited by B007 in this callback.
- Renamed: none.
- Explicit no-change support docs inspected and preserved: `by-class/Application.md`, `by-file/Application.md`, UID000198, UID00019B, UID000199, UID000195, ChangeMan class/file/method pages, and caller docs.
- Manual coverage/audit/catalog/goal/notes/lifecycle/archive files: no B007 edits. Generated files were read only by B007; post-Gate2B validators completed generated refresh under commands `000000018420`, `000000018422`, `000000018424`, and `000000018428`, with final LObject header command `000000018426` and ChangeMan header command `000000018428`. `project-level/-auto-completion-stats.md`, generated reports/C++, and `tools/validator.ini` received validator-owned refreshes, not direct B007 edits.
- Supervisor-owned current changes: exact UID00019A/UID0001P4 by-memory coverage rows and UID0000QI by-global coverage row were applied by the supervisor and validated under commands `000000018430`/`000000018421`; B007 did not edit those reports.
- IDA database: no B007 mutation. The report/docs record the supervisor-provided Gate 2B `APPLIED_VERIFIED` operation/readback/save evidence.
- Report execution: not run.

## Implementation Tracking Checklist

Initial report-only pass:

These rows originated in the report-only pass. Current checked states now also record explicit supervisor-provided Gate 2A, Gate 2B, manual coverage, and coverage-validation facts; they do not claim B007 performed supervisor-owned actions.

- [x] Supervisor validation required before implementation: callback authorized exact report SHA `BFAA49B2FD2744600309BD4087154FC6A33B89F9F2CD485B41A19FF4E961DB2F`.
- [x] Planned target/support destinations recorded: UID00019A target; UID00007D address correction; UID0000QI/UID0001P4 post-IDA evidence.
- [x] Additional-UID declaration audited: no additional target UIDs declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger accepted for callback and independently verified through the supplied supervisor Gate 2A/Gate 2B/coverage evidence.
- [x] Metadata/score implementation plan recorded: UID00019A `92/94 -> 93/94`; other target metadata unchanged.
- [x] Score-limiting blockers researched to resolution or exact source-spelling uncertainty.
- [x] Owner/emitter/reconstructable recommendation confirmed unchanged at `00007D` / `00007D` / true.
- [x] Split/rename/new-child research completed and confirmed not applicable.
- [x] Source placement, range/padding, and no-aggregate-emission dispositions researched and recorded.
- [x] Reserved supervisor-owned Gate 2B handoff row: every affected byte-item and protected neighbor prestate, exact action, type, comments, safety constraints, and expected readback were drafted; supervisor reported `APPLIED_VERIFIED`. This check records supervisor evidence, not B007 self-certification.
- [x] Exact target CPP block and blank H proof recorded.
- [x] Third-party import directive researched and confirmed not applicable.
- [x] Exact target/support facts accepted for incorporation without summarizing away caller, constructor, negative, or historical detail.
- [x] Historical B007 free-helper route preserved as superseded evidence.
- [x] Wave2/Wave3 artifacts encountered in historical context and ignored as stale.
- [x] Open questions researched and closed to high-probability human-source inference.
- [x] Supervisor callback identified scoped serial file validators; commands `000000018350` through `000000018353` completed with exit `0` and `ok: 1`.
- [x] Exact supervisor-owned manual coverage replacement text drafted, applied by the supervisor, and validated under `000000018430`/`000000018421`; B007 did not edit coverage.

Implementation callback pass:

- [x] Reserved supervisor-owned IDA row: Gate 2B is `APPLIED_VERIFIED` by the supervisor and was not applied or independently certified by B007.
- [x] Report accepted by supervisor for implementation at exact SHA `BFAA49B2FD2744600309BD4087154FC6A33B89F9F2CD485B41A19FF4E961DB2F`.
- [x] All accepted target/support details incorporated at report-level detail.
- [x] UID00019A verified independently against ledger and destination docs.
- [x] Claim ledger verification states updated only after actual destination checks.
- [x] Score/formal/support changes applied exactly or explicitly retained unchanged with reason.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions retained only with evidence-backed resolution text.
- [x] Scoped validators run and literal results recorded after implementation and reconciliation: original `000000018350`-`000000018353`; post-Gate2B `000000018420`, `000000018422`, `000000018424`, `000000018428`; all exit `0`, `ok: 1`.
- [x] Generated output touched only through authorized validator/generator flow; final LObject header `000000018426` and ChangeMan header `000000018428` readback recorded, with no direct B007 generated edit.
- [x] Supervisor-provided Gate 2B backup/action/readback/save evidence incorporated without compression into UID00019A, UID0000QI, UID0001P4, and this report; B007 performed no IDA mutation.
- [x] B007 released every implementation lease immediately after each edit/validation batch; final lease report has no B007 entry.
- [x] B007 returns `READY_FOR_SUPERVISOR_EXECUTE`; B007 does not execute or move the report.

Supervisor closeout pass:

- [x] Supervisor post-IDA Gate 2A ordinary-document verification completed under `000000018425`, `000000018426`, `000000018427`, and `000000018429`; the current report awaits only fresh exact-artifact audit before execution.
- [x] Supervisor Gate 2B reported `APPLIED_VERIFIED`: exact backup, operation, four-address readback, unchanged bytes/xrefs/neighbors/target/padding, final save/hash, and post-save health recorded; this check reflects explicit supervisor evidence, not B007 self-certification.
- [x] Manual by-memory/by-global coverage rows replaced exactly by the supervisor.
- [x] Changed ordinary by-* docs and coverage reports validated; target-specific results are exit `0`, `ok: 1`.
- [x] Supervisor confirms B007 did not directly edit generated or manual coverage files; supervisor/validator ownership is recorded explicitly.
- [ ] Supervisor runs report execution only after all claims and checklist items are independently verified.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000018457","destination_path":"executed-b-agent-research/B007/00019A-ApplicationUnregisterChangeListener-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00019A-ApplicationUnregisterChangeListener-source-quality.md","timestamp":"2026-07-28T16:42:28-04:00","uid":"00019A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
