** TARGET-REPORT-UID:0001C2 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001C2 ServerItemMenuItemList Scalar Deleting Destructor Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: retain UID0001C2 as class-owned reconstructable ABI coverage at implemented `90/94` with the exact formal covered-by comment to ordinary/source-bearing ServerItemMenuItemList range UID0001BP.
- Final disposition: compiler-generated MSVC scalar deleting destructor wrapper generated from the source-visible `ServerItemMenuItemList::~ServerItemMenuItemList()` semantics already carried by UID0001BP. It is not a separately authored NexusTK method.
- Required action: exact-artifact Gate 1, the accepted B001 ordinary-document callback, supervisor Gate 2A documentation verification, and supervisor Gate 2B IDA closure are complete. Supervisor-only execution/archive is authorized. The validator-owned `REPORT-VALIDATION-STATUS` / `VALIDATOR-REPORT-HISTORY` footer and lifecycle registry are authoritative for whether execution/archive has occurred at the current path before or after archive; the supervisor applies the remaining manual coverage rows only after those records confirm execution.
- Confidence: very strong. Live IDA proves the complete wrapper, every incoming route, all direct callees, exact object size, exact bytes/hash, ordinary-destructor parity, and both alignment boundaries.

## Supporting Research

- Current report lifecycle: exact report SHA `1C55DDB8147EFA2C66FEEF4A6604EB3E74183758499A2DB38DE949F47D069602` passed supervisor Gate 1; the B001 ordinary-document callback and supervisor Gate 2A/Gate 2B are complete, and this reconciled artifact is cleared for supervisor-only execution/archive. Six authorized by-* files were edited and scoped-validated. B001 did not mutate IDA, edit coverage/generated/audit/goal/lifecycle state directly, or invoke report execution. The validator-owned footer and lifecycle registry, rather than this durable body text, are authoritative for the report's current executed/archive state before and after archive.
- Historical lead `executed-b-agent-research/B002/0001BP-ServerItemMenuItemList-source-quality.md`: accepted for the ItemMenuDialogs source family, corrected `g_pItemHelpPane` interpretation, ordinary destructor ownership, and source-facing class reconstruction. Its 2026-06-18 MCP-unavailable confidence cap is historical and is superseded for this exact wrapper by the healthy live session below.
- Historical lead `executed-b-agent-research/B002/0001BX-MenuDialogDestructorThunks-source-quality.md`: accepted for the destructor-island inventory and non-source-authored wrapper classification. It is aggregate context, not direct evidence for this target.
- Historical lead `executed-b-agent-research/B004/0001PD-g_pItemHelpPane-source-quality.md`: accepted for the five-write/fifteen-read singleton inventory and the `0x00520d00` ServerItemMenuItemList teardown read. Its current UID0001C2 verify-only state is revalidated here.
- Historical lead `executed-b-agent-research/B001/0001C1-SharedListPaneScalarDeletingDestructor-source-quality.md`: accepted only as a sibling ABI-pattern comparison. UID0001C1 is shared by three list classes and cannot substitute for UID0001C2's class-specific vtable restores and item-help close.
- Current documentation comparator UID000339 BrowserControlPane and UID0001DM LightingObjectPane scalar deleting destructors establish the current project policy: retain class-owned reconstructable wrapper coverage and use a formal covered-by comment to the ordinary destructor source rather than handwritten delete-flag code or a blank emitter.
- No Wave2/Wave3 result was used as evidence. Any legacy mention in older material was ignored as stale under the current workflow.

## Target

- Target UID: `0001C2`.
- Additional target UIDs: none. Support-page recommendations do not declare report coverage for those UIDs.
- Declared-target inventory: `by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md`, exact class-specific scalar deleting destructor ABI range.
- Target path: `by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md`.
- Assignment-time queue row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> not-covered reconstructable row at `86/91`, weighted `88.5`, direct/additional/total report counts `0/0/0`. Generated tracker refresh/coverage registration remains supervisor lifecycle work.
- Current supervisor classification: callback-implemented reconstructable by-memory target with exact ordinary-source/compiler-ABI disposition and a nonempty covered-by formal marker.
- Current scores and parent state: target `90/94`; direct canonical owner/emitter UID0000D0 remains `88/89`; source file UID0000KF remains `88/89`. The direct-parent and final-file routes clear the active gate.

## Current Target State

- Current metadata: `COMPLETION:90`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000D0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D0`, blank optional position, exact covered-by formal block, and `Nested:0`.
- Current owner/emitter/reconstructable state: preserved. `ServerItemMenuItemList` is the narrow direct owner; that class routes to `ItemMenuDialogs` UID0000KF, while UID0001BP supplies ordinary destructor source semantics.
- Current C++/emitter state: the formal block contains exactly one UID0001BP covered-by comment and no scalar-wrapper body. Generated `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp` contains UID0001C2 once and that exact comment once; UID0001C2 has zero empty-emitter markers.
- Remaining supervisor-only work: use the lifecycle command when the validator-owned footer/registry does not yet record execution/archive, then apply C1C2-25 manual coverage replacements only after those authoritative records confirm execution. Gate 2A and C1C2-20 through C1C2-23 Gate 2B closure are complete; no accepted ordinary-document or IDA blocker remains.
- Related docs checked: UID0001BP main method range, UID0001BZ adjustor thunks, UID0000D0 class, UID0000KF file, UID00031Z item-menu vtables, UID0000R9 singleton global, UID00007A ListPane class, ListPane destructor documentation, UID0001BX aggregate, current generated C++, generated memory coverage, research tracker, and manual coverage reports.
- Post-callback destination/generated metrics after all six scoped validators:

| Artifact | Bytes / lines / H2 | SHA256 |
| --- | --- | --- |
| UID0001C2 target | `13,712 / 118 / 10` | `F824BA466D4D38EFF8A5B0751D9CB33B8BE5FFC073624003240AE6607CF696DE` |
| UID0001BP source-bearing range | `25,761 / 308 / 11` | `9CD78B05D9BA35D326E90DA8505DE99AAF72C9A619C4413864565B94FFB53A2E` |
| UID0001BZ thunk page | `7,260 / 73 / 8` | `CC7ED68094D1C0E54FF8A518069AB8226E014DF1AC8E2A2122E3BD963F420954` |
| UID0000D0 class | `14,064 / 107 / 9` | `81F29C7476CA36F07F30209DF60C3CE0619B6E0DBEFD7CC1B72079CB25494DB5` |
| UID0000KF file | `24,383 / 141 / 10` | `9AE46C364061335E93A6DDA2780443A54CF9CAC8644E5F7B1994AAEA66E1164A` |
| UID00031Z vtable page | `10,521 / 86 / 7` | `42189F6F20E04BF34E90D3E3CA61AE6A60AB2B88E68DED2F3D2A10C7F9924BD2` |
| ItemMenuDialogs generated C++ | `14,121 / 458 / not applicable` | `FC9EC1F19B0F5B3C6ACF5FEFFB34941CF6D5DF7190AA3E93FF367E40BE79DD42` |

All six ordinary destinations contain zero non-ASCII bytes. Generated readback is stamped `validator-command-id: 000000016985` and `validator-refreshed-at: 2026-07-23T23:55:40-04:00`.

## Executive Recommendation

- Keep `CANONICAL_OWNER:0000D0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D0`, blank position, and `Nested:0`.
- The exact target is now `90/94` after incorporating this report's exhaustive current-session facts.
- The exact formal covered-by comment to UID0001BP is present. No source method named scalar deleting destructor, vptr writes, delete flags, operator-delete routing, or guard calls were emitted.
- Keep ordinary source destruction in UID0001BP and the `ServerItemMenuItemList` class/file route. The current source-facing helper spelling `CloseItemHelpPaneSingleton()` is a defensible project-local abstraction for the exact null-safe virtual delete sequence; direct `delete g_pItemHelpPane;` is behavior-equivalent but is not preferred over the established helper name in current documentation.
- Supervisor Gate 2B applied and independently verified the wrapper/thunk names, prototypes, and comments; the exact ordinary-destructor function; and the existing singleton's pointer type while preserving compiler-generated classification and verified no-change entities. The complete saved-IDB readback is recorded below.
- Scoped validation refreshed generated output through command `000000016985`; UID0001C2 is now a traceable covered-by comment instead of an empty emitter marker.

## Supervisor Active Recheck

- Trigger: the updated B001 goal assigned direct new report coverage for UID0001C2 and required every empty-emitter/source-quality blocker to be resolved rather than repeated.
- Split decision: no split is needed. The target is exactly one modeled function and excludes all surrounding `0xcc` padding.
- Child/source decision: the two adjustor thunks already have exact UID0001BZ; the ordinary destructor and source-visible class behavior already live in UID0001BP. No new by-memory child is needed.
- Every source-bearing item in scope has a precise route: ordinary destructor semantics -> UID0001BP -> UID0000KF; scalar wrapper ABI evidence -> UID0001C2 -> UID0000D0 -> UID0000KF; adjustor glue -> UID0001BZ, non-reconstructable/no emitter.

## Inference Research Guidance Check

- `by-structure.md` lines 261-267 control the disposition. In particular, a reconstructable item intentionally covered by another emitter must use a minimal formal coverage comment rather than remain an empty emitter.
- IDA facts, documentation facts, and inferences are separated below. Old report statements were treated as leads and replayed against the current IDB.
- Existing assumptions challenged: blank formal until `95/95`, `char` as the delete-flag type, vague observer wording, inability to improve because the ordinary destructor is raw/unmodeled, and the possibility that compiler glue should be `RECONSTRUCTABLE:FALSE`.
- Current conclusion: the wrapper remains class-owned reconstructable ABI coverage under established project policy, but authored source is the ordinary destructor. A covered-by marker records this without duplicating generated ABI code.
- Wave2/Wave3 references were ignored and had no role in the recommendation.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best supported resolution | Evidence | Classification |
| --- | --- | --- | --- |
| Historical `sub_520CE0` name | `ServerItemMenuItemList_scalar_deleting_destructor` | decorated vtable heads, exact vtable slot routes, class vptr restores, ordinary-body parity | descriptive compiler-ABI name, very strong; applied/verified at Gate 2B |
| Historical `char a2` type | `unsigned int deleteFlags` | four-byte stack argument, `retn 4`, bit `1` and bit `4` tests, current typed MessageShowPane comparator | ABI inference, very strong; applied/verified at Gate 2B |
| Object size | `sizeof(ServerItemMenuItemList) == 0x15c` | exact bit-4 immediate plus known final field at `+0x158` | exact binary/layout fact |
| `0x0069ae04` role | `ItemHelpPane *g_pItemHelpPane` | current IDA name, 4-byte `.data`, 20 xrefs, target null-check and virtual slot-0 call with flag `1` | accepted source-facing global |
| Source destructor location | ordinary destructor at `[0x0051af00,0x0051af35)` in UID0001BP | 53 live bytes, four-byte predecessor padding, eleven-byte successor padding, 47-byte common prefix with wrapper after wrapper frame setup | exact range plus source inference |
| Close spelling | retain established `CloseItemHelpPaneSingleton()` in source-facing reconstruction | exact equivalent helper exists; direct sequence is classic `delete g_pItemHelpPane`; current project source already uses helper spelling | selected descriptive source shape |
| Wrapper source visibility | no handwritten scalar-wrapper method | vtable/thunk-only entry, compiler flags, free helper, guarded-size branch, no ordinary callers | exact compiler-generated disposition |
| Empty emitter | formal covered-by comment to UID0001BP | explicit by-structure rule and current analogous scalar-wrapper pages | required project routing repair |
| Source file | `NexusTK/ui/dialogs/ItemMenuDialogs.cpp` | owner class/file route, inline construction, decorated vtables, neighboring server/client family | strong source placement |

Rejected alternatives:

- Reject `RECONSTRUCTABLE:FALSE`/blank emitter. It conflicts with current covered-by policy and established class-owned scalar-wrapper handling.
- Reject a handwritten `ServerItemMenuItemList::ScalarDeletingDestructor(unsigned int)` method. No such developer-facing method is required; it would encode MSVC ABI output as source.
- Reject direct ownership by `ListPane`, `ItemHelpPane`, or MemoryMan. They are a base cleanup dependency, a deleted singleton dependency, and a deallocation dependency respectively.
- Reject `g_serverItemMenuObserver` and generic observer notification. The current named global and complete xref inventory prove `g_pItemHelpPane`.
- Reject `char` delete flags. Only AL is tested, but the ABI consumes one four-byte stack parameter and comparison wrappers use `unsigned int deleteFlags`.
- Reject treating the bit-4 branch as a real sized free. It calls the one-byte `C3` stub `@_guard_check_icall_nop@4` after pushing `this` and `0x15c`; it does not free in this executable.
- Reject expanding the target into `[0x00520ce0,0x00520d50)`. The exact function ends at `0x00520d47`, followed by nine `0xcc` bytes before the successor at `0x00520d50`.

## Evidence Standards Used

- Primary authority: healthy live IDA MCP session `7be8cc9f` for `NexusTK.exe.i64`, auto-analysis ready, Hex-Rays ready, and strings cache ready with 2,067 entries.
- Binary identity: input executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, MD5 `4247E04E20B65D6414C7238AA8FF5515`.
- Direct evidence: `lookup_funcs`, `analyze_function`, `decompile`, `get_bytes`, `get_int`, `xrefs_to`, `xref_query`, `callees`, `entity_query`, `list_globals`, `type_query`, and bounded comparisons with current typed scalar-wrapper functions.
- Supporting evidence: current by-* pages, existing executed reports as historical leads, generated route/output, research tracker, and manual coverage rows.
- Collection-time negative evidence: no ordinary caller, no xref to the then-raw ordinary destructor start, no modeled function at endpoint/padding/ordinary start, no `ServerItemMenuItemList` UDT in the research-session type catalog, and no evidence for alternative ownership. Gate 2B subsequently created only the exact ordinary function and opaque class declaration; it did not change caller/xref or ownership evidence.
- Confidence is limited to `94`, the ordinary-research ceiling, because no original private symbols or final rebuild/compiler byte-equivalence test exists. This does not leave a current implementation blocker.

## Evidence Checked

- Live target analysis: exact 103-byte function, seven basic blocks, cyclomatic complexity three, complete assembly/decompile, three incoming refs, three direct named callees, and no ordinary callers.
- Raw bytes: target, predecessor/successor padding, both adjustor thunks, raw ordinary destructor, and guard stub.
- Vtables: complete-object-locator cells at `0x0061ef40/0x0061efc8/0x0061eff8`, primary/secondary/tertiary vtable heads, first entries, vptr writes, and all target refs.
- Global: current `g_pItemHelpPane` name, 4-byte `.data` storage, all 20 xrefs, target read, and existing ItemHelpPane type-catalog entry.
- Helpers: exact `ListPane_Destructor` body, MemoryMan-backed `NexusTK_operator_delete_wrapper`, and one-byte guard stub.
- Boundaries: predecessor function `sub_520CA0` ends at `0x00520cdb`; five `0xcc` bytes lead to the target. Target ends at `0x00520d47`; nine `0xcc` bytes lead to `sub_520D50` at `0x00520d50`.
- Ordinary source body: at collection time `[0x0051af00,0x0051af35)` was unmodeled but bounded by four and eleven `0xcc` bytes. Its first 47 bytes exactly match the wrapper from `0x00520ce3` through the divergence at the cleanup transfer; Gate 2B subsequently created and verified the exact bounded function without consuming padding.
- Documentation: all target/support/current generated/manual artifacts listed under Current Target State and Supporting Research.
- No research evidence check failed and IDA MCP remained healthy. During the initial report-only phase, IDA mutation, validators, leases, and report lifecycle commands were intentionally not used. During the accepted callback, B001 still made no IDA/lifecycle mutation but used the six short edit leases and scoped validators recorded below.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C1C2-01 | 0001C2 | Exact range is `[0x00520ce0,0x00520d47)`, 103 bytes. | very strong | live lookup/analyze/get-bytes | target Covered Range/IDA evidence | applied | target lines/metrics current; validator `000000016980` passed |
| C1C2-02 | 0001C2 | Target SHA256 is `26F97394E0C4E8A48290B31A4A5E9E46825D91576F9E40CFDEEEFC698B7C2061`. | very strong | live 103-byte read and local SHA256 | target Covered Range/IDA evidence | applied | exact hash present; validator `000000016980` passed |
| C1C2-03 | 0001C2 | Five predecessor and nine successor bytes are `0xcc`; no padding belongs to target. | very strong | bounded live bytes/function lookup | target Covered Range | applied | both alignment spans and successor documented; validator passed |
| C1C2-04 | 0001C2 | Function is an MSVC `__thiscall` scalar deleting destructor with one four-byte unsigned flags word. | very strong | assembly, `retn 4`, comparator type | target Covered Range/Behavior | applied | unsigned `deleteFlags` ABI recorded; validator passed |
| C1C2-05 | 0001C2 | Primary route is `0x0061ef44 -> 0x00520ce0`. | very strong | live u32/xrefs/decorated name | target and UID00031Z route tables | applied | target `000000016980`; vtable `000000016985` passed |
| C1C2-06 | 0001C2 | Secondary route is `0x0061efcc -> 0x00520b13`, then `this -= 0xa0`. | very strong | live u32/analyze/xrefs | target, UID0001BZ, UID0000D0, UID00031Z | applied | all four destinations document exact route; validators passed |
| C1C2-07 | 0001C2 | Tertiary route is `0x0061effc -> 0x00520b1e`, then `this -= 0xa4`. | very strong | live u32/analyze/xrefs | target, UID0001BZ, UID0000D0, UID00031Z | applied | all four destinations document exact route; validators passed |
| C1C2-08 | 0001C2 | Wrapper restores all three class vptrs at `+0`, `+0xa0`, `+0xa4`. | very strong | exact assembly/decompile | target Behavior/Source split | applied | exact offsets preserved; validator passed |
| C1C2-09 | 0001C2 | `0x0069ae04` is active `g_pItemHelpPane`; null-safe slot-0 flag-1 dispatch is deletion/close. | very strong | current global/xrefs/decompile | target, UID0001BP, UID0000D0, UID0000KF | applied | four edited destinations synchronized; global verified unchanged |
| C1C2-10 | 0001C2 | Wrapper and ordinary destructor have a 47-byte common semantic prefix after the wrapper EBP prologue. | very strong | live target/ordinary bytes | target, UID0001BP, UID0000D0, UID0000KF | applied | parity recorded at report-level detail; validators passed |
| C1C2-11 | 0001C2 | `ListPane_Destructor` destroys owned lists at `+0x130/+0x138` and tail-chains base cleanup. | very strong | live helper analysis | target Behavior; ListPane docs verify-only | applied/verified | target updated; UID0003TZ/ListPane docs independently agree, no edit needed |
| C1C2-12 | 0001C2 | Flags bit `1` clear returns without freeing. | very strong | target control flow | target Behavior | applied | exact no-free return documented; validator passed |
| C1C2-13 | 0001C2 | Bit `1` set and bit `4` clear calls MemoryMan-backed operator delete. | very strong | target/helper analysis | target Behavior | applied | exact normal-free condition/helper documented; validator passed |
| C1C2-14 | 0001C2 | Bit `4` path pushes `this` and exact complete-object size `0x15c` to one-byte no-op guard stub. | very strong | assembly/get-bytes | target Behavior; UID0000D0/UID0000KF support | applied | no-free guard and size documented; validators passed |
| C1C2-15 | 0001C2 | Only incoming routes are two thunk jumps and one primary vtable data ref; no ordinary callers exist. | very strong | xrefs/callers | target reachability; UID0001BZ/UID00031Z | applied | complete route inventory recorded; validators passed |
| C1C2-16 | 0001C2 | Source authors wrote the ordinary destructor semantics; compiler generated this wrapper and adjustors. | very strong | ordinary parity plus ABI mechanics | all six edited destinations | applied | source/compiler split synchronized without duplicate code |
| C1C2-17 | 0001C2 | Formal output must be a covered-by comment to UID0001BP. | very strong | by-structure rule and exact source owner | target formal block | applied | exact one-line marker present; validator/generated readback passed |
| C1C2-18 | 0001C2 | Owner/reconstructable/emitter metadata remains `0000D0/TRUE/0000D0`. | very strong | class/vtable/source route | target metadata | preserved | post-validator metadata readback exact |
| C1C2-19 | 0001C2 | Score should rise to `90/94`. | strong | exhaustive closure in this report | target metadata/rationale | applied | validator `000000016980` recorded completion/confidence updates |
| C1C2-20 | 0001C2 | IDA wrapper should receive exact descriptive name/type/comment. | very strong | current raw name/type versus comparator | supervisor Gate 2B | applied/verified | session `supervisor_gate2b_0002OT_20260723` renamed, typed, commented, and reread `0x00520ce0`; B001 made no IDA mutation |
| C1C2-21 | 0001C2 | Raw ordinary destructor should be promoted as exact `[0x0051af00,0x0051af35)`. | very strong | live bytes/padding/parity | supervisor Gate 2B and UID0001BP | applied/verified | exact function created/renamed/typed/commented; end `0x0051af35` and adjacent padding preserved and reread |
| C1C2-22 | 0001C2 | Adjustor thunks should receive exact names/types/comments without source emission. | very strong | exact bodies/vtable-only refs | supervisor Gate 2B and UID0001BZ | applied/verified | `0x00520b13` and `0x00520b1e` renamed/typed/commented and reread; source-emission disposition unchanged |
| C1C2-23 | 0001C2 | Existing `g_pItemHelpPane` name remains; apply pointer type only. | very strong | current name/size/type catalog | supervisor Gate 2B | applied/verified | existing name preserved, `ItemHelpPane *` applied, and 20 xrefs reread |
| C1C2-24 | 0001C2 | Generated UID0001C2 empty marker should become the formal covered-by comment. | very strong | generated readback | generated `ItemMenuDialogs.cpp` | applied/verified | command `000000016985`: UID once, comment once, UID-specific empty marker zero |
| C1C2-25 | 0001C2 | Stale manual rows for target and directly edited support pages require supervisor replacements. | very strong | current manual rows versus page metadata | manual coverage reports | pending supervisor | exact payload preserved below; apply only after execute/archive |

## Positive Evidence Summary

- The target's primary vtable entry is exactly its start; both other class vtable views route through exact adjusted-this thunks to the same start.
- The wrapper writes the same three decorated class vtables as inline setup, the raw constructor, and the raw ordinary destructor.
- Its item-help close sequence and vptr restores are byte-identical to the ordinary destructor for 47 bytes after frame setup.
- Its only additional work is compiler-shaped base cleanup, delete-flag handling, optional deallocation, guarded object-size handling, and returning `this`.
- The exact object size `0x15c` agrees with class state extending through pointer field `+0x158`.
- The complete source route already exists: UID0001BP contains `ServerItemMenuItemList::~ServerItemMenuItemList()` and emits through ItemMenuDialogs.
- Current analogous project pages use class-owned reconstructable status plus a formal covered-by comment for this exact source/compiler split.

## IDA MCP Facts

- Health at collection: session `7be8cc9f`, status `ok`, `NexusTK.exe.i64`, image base `0x00400000`, analysis ready, Hex-Rays ready, string cache ready.
- Collection-time `lookup_funcs`: historical `sub_520CE0` at `0x00520ce0`, size `0x67`; no function at `0x00520d47`; successor `sub_520D50` at `0x00520d50`, size `0x48`. Gate 2B subsequently renamed the target while preserving its exact bounds and successor separation.
- Collection-time target prototype: `_DWORD *__thiscall(_DWORD *Block, char)`. Gate 2B replaced this mechanically usable but source/ABI-poor form with the exact applied/verified prototype recorded in the IDA section.
- Exact target bytes SHA256: `26F97394E0C4E8A48290B31A4A5E9E46825D91576F9E40CFDEEEFC698B7C2061`.
- Target decompile: three class vptr writes, null-safe `g_pItemHelpPane` slot-0 dispatch with argument `1`, `ListPane_Destructor`, flags tests, optional `NexusTK_operator_delete_wrapper`, and guarded size path.
- Target xrefs: code at `0x00520b19` and `0x00520b24`; data at `0x0061ef44`; no ordinary callers.
- Vtable first entries: `0x0061ef44 = 0x00520ce0`, `0x0061efcc = 0x00520b13`, and `0x0061effc = 0x00520b1e`. Their complete-object-locator pointers are `0x0064ba2c`, `0x0064ba90`, and `0x0064baa4`.
- Vtable decorated names are already `??_7ServerItemMenuItemList@@6B@`, `_0`, and `_1`.
- At collection time `g_pItemHelpPane` was already named at `0x0069ae04`, size 4 in `.data`, with 20 xrefs, but its pointer type was not surfaced by global readback. Gate 2B preserved the name, applied `ItemHelpPane *`, and reread all 20 xrefs.
- `ListPane_Destructor` is already typed `void __thiscall(ListPane *this)`, size `0x45`, and deletes the two owned list pointers before base teardown.
- `NexusTK_operator_delete_wrapper` is already typed `void __cdecl(void *block)`, size `0x40`, and routes through MemoryMan.
- `@_guard_check_icall_nop@4` is already named, size one, exact byte `C3`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0051af00-0x0051af35` | UID0001BP | ordinary non-deleting destructor source body | true | UID0000KF | `88/89` | source-bearing; exact IDA function created/verified at Gate 2B |
| `0x00520b13-0x00520b1e` | UID0001BZ | `+0xa0` deleting-destructor adjustor | false | none | `88/92` | exact compiler glue |
| `0x00520b1e-0x00520b29` | UID0001BZ | `+0xa4` deleting-destructor adjustor | false | none | `88/92` | exact compiler glue |
| `0x00520ce0-0x00520d47` | UID0001C2 | class-specific scalar deleting wrapper | true | UID0000D0 | `86/91 -> 90/94` | covered by ordinary source after callback |
| `0x00520d47-0x00520d50` | no child | alignment padding | false | aggregate only | not applicable | nine `0xcc` bytes |
| `0x00520d50-0x00520d98` | adjacent target | TextInputMenuDialog scalar wrapper | outside scope | outside scope | unchanged | exact successor starts at `0x00520d50` |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061ef44 -> 0x00520ce0` | primary vtable data ref | complete-object destructor dispatch |
| `0x0061efcc -> 0x00520b13 -> 0x00520ce0` | secondary vtable plus thunk | adjusts `this` by `-0xa0` |
| `0x0061effc -> 0x00520b1e -> 0x00520ce0` | tertiary vtable plus thunk | adjusts `this` by `-0xa4` |
| `0x00520d00 -> 0x0069ae04` | global read | load active item-help singleton |
| `0x00520d0e` | indirect slot-0 call with `1` | null-safe virtual delete/close |
| `0x00520d12 -> 0x004f3b60` | direct callee | ordinary ListPane-owned cleanup |
| `0x00520d23 -> 0x004f4ac0` | direct callee | normal scalar-delete free path |
| `0x00520d38 -> 0x0041b6a0` | direct callee | bit-4 guarded size/no-free path |
| ordinary callers | none | wrapper is reached through vtables/thunks only |

## Documentation Evidence And IDA Status

- UID0001C2 now records exact bytes/hash, full boundary proof, source/compiler policy, formal covered-by comment, modern type/name handoff, current-session ordinary parity, complete behavior, and `90/94` rationale.
- UID0001BP remains the correct ordinary-source destination. Its Item Summary/status/evidence/generated caveats now historicalize the old observer/final-blocked/zero-output/MCP-unavailable statements and add exact ordinary hash/padding/parity.
- UID0001BZ retains exact bodies and false/no-owner/non-emitting classification; its documented name/type/comment handoff was applied and verified by the supervisor at Gate 2B without changing its source-emission disposition.
- UID0000D0 and UID0000KF retain ownership/source placement and now record the exact ordinary-versus-scalar split, complete-object size, covered-by route, and no-duplicate-ABI rule.
- UID00031Z retains `88/92` and now records exact first-slot routes, complete-object-locator cells, and ordinary-source/compiler-regeneration disposition.
- UID0000R9 is current and correct at `92/94`; no ordinary doc change is required.
- Generated memory coverage routes UID0001C2 through UID0000D0 to `ItemMenuDialogs.cpp`; generated source now contains the exact covered-by comment and no UID0001C2 empty-emitter marker.
- Manual rows for UID0001C2, UID0001BP, UID0001BZ, UID0000D0, and UID0000KF are stale relative to current/recommended source pages.

## Ranked Ownership Analysis

### 1. UID0000D0 ServerItemMenuItemList

- Evidence for: exact decorated vtables, all three vptr restores, two class-specific adjustor routes, ordinary destructor parity, and class allocation size.
- Evidence against: none material.
- Decision: retain as direct canonical owner and emitter.

### 2. UID0001BP ServerItemMenuItemList source-bearing method range

- Evidence for: owns the raw ordinary destructor and existing human source destructor body that regenerates this wrapper.
- Evidence against: it is a by-memory sibling/source destination, not the target's semantic class owner.
- Decision: use as the formal covered-by destination, not `CANONICAL_OWNER`.

### 3. UID0000KF ItemMenuDialogs

- Evidence for: final source root for the server/client item-menu family.
- Evidence against: broader than the narrow class owner.
- Decision: retain as final emitter root through UID0000D0, not direct owner.

### Rejected dependency owners

- ListPane owns base cleanup only.
- ItemHelpPane/g_pItemHelpPane is an object deleted by the destructor, not the destructor owner.
- MemoryMan owns deallocation only.
- The mixed MenuDialog destructor aggregate is an index, not a source owner.

### Proposed new file/grouping, if applicable

- Not applicable. Existing `NexusTK/ui/dialogs/ItemMenuDialogs.cpp` is the strongest route and no new class/file/grouping is justified.

## Source Placement

- Recommended source placement: `ServerItemMenuItemList::~ServerItemMenuItemList()` remains with UID0001BP under `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`.
- UID0001C2 contributes a traceability comment only, routed through UID0000D0 to the same source root.
- This fits the inline server-dialog list construction, server/client item-menu locality, exact vtable family, opcode `0x39` helpers, and current proposed source tree.
- Rejected placements: `ListPane.cpp`, `HelpPanes.cpp`, MemoryMan, a compiler-glue source file, or the broad mixed destructor aggregate.
- Standalone-versus-folded `ItemDialogs.cpp` is a broader historical filename question, not a blocker. Current project routing decisively uses `ItemMenuDialogs.cpp`.

## Range / Split / Padding / Reclassification Analysis

- Target start `0x00520ce0` is exact. Previous `sub_520CA0` ends at `0x00520cdb`; `[0x00520cdb,0x00520ce0)` is five-byte `0xcc` alignment.
- Target end `0x00520d47` is exact and non-function. `[0x00520d47,0x00520d50)` is nine-byte `0xcc` alignment.
- Successor `sub_520D50` starts exactly at `0x00520d50`; no successor byte belongs to UID0001C2.
- The two adjusted thunks are already split into UID0001BZ. Do not merge them into UID0001C2 and do not make them reconstructable.
- The formerly raw ordinary destructor is already inside UID0001BP and was promoted to an exact bounded IDA function at Gate 2B. Do not create a duplicate by-memory page.
- Reclassification to false/non-emitting is rejected. Class-owned reconstructable ABI coverage is retained and the former blank body is repaired with the required comment.

## Negative Evidence Summary

- No ordinary direct caller targets `0x00520ce0`; only two thunk jumps and one primary vtable cell do.
- No xref targets raw ordinary start `0x0051af00`; this absence does not negate the exact bounded body because vtable dispatch targets the scalar wrapper and the ordinary body is compiler/linker-retained class cleanup.
- The research-session IDB had no `ServerItemMenuItemList` UDT. Gate 2B added only the required opaque declaration; no evidence supports fabricating a full member layout merely to improve decompilation.
- No evidence supports the old observer interpretation of `0x0069ae04`.
- No evidence supports a separate source-visible scalar-wrapper method, direct operator-delete call in authored destructor source, or source-visible guarded-size logic.
- No evidence supports including either alignment span in the target.
- No evidence supports moving source responsibility to a callee/consumer module.

## IDA Rename / Type / Comment Recommendations

Status: `APPLIED_VERIFIED`. Supervisor Gate 2A passed before Gate 2B. Gate 2B was performed in session `supervisor_gate2b_0002OT_20260723`; B001 made no IDA mutation. The pre-mutation backup is `E:\NTK\Resources\NexusTK\NexusTK.pre-gate2b-0001C2-20260724-0014.i64`, SHA256 `E777BF866139609847360F9BD11835D93F8C32716AF5CCFFF67C480147392F92`.

| Address/entity | Historical pre-Gate-2B state | Applied supervisor action | Verified saved-IDB readback |
| --- | --- | --- | --- |
| `0x00520ce0` function | Historical raw state: `sub_520CE0`; `_DWORD *__thiscall(_DWORD *Block, char)`; generic local comments. | Renamed `ServerItemMenuItemList_scalar_deleting_destructor`; applied `ServerItemMenuItemList *__thiscall(ServerItemMenuItemList *this, unsigned int deleteFlags)`; applied repeatable comment `Compiler-generated ServerItemMenuItemList scalar deleting destructor. Source semantics are covered by the ordinary destructor at 0x0051AF00 / UID0001BP. deleteFlags bit 0 requests operator delete; bit 2 selects the guarded 0x15C-byte no-free path. Incoming routes are primary vtable 0x61EF44 and adjustors 0x520B13/0x520B1E.` | Name, prototype, and comment reread at the exact wrapper; compiler-generated classification remains explicit. |
| supporting type | Historical type query had no `ServerItemMenuItemList` UDT. | Declared only opaque `struct ServerItemMenuItemList;` to support pointer prototypes; no members or fabricated full layout were added. The exact complete-object size remains a comment invariant, `0x15c`. | Opaque declaration is present and pointer prototypes parse without a fabricated class layout. |
| `0x00520b13` function | Historical raw state: `sub_520B13`; `_DWORD *__thiscall(_DWORD *this, char)`. | Renamed `ServerItemMenuItemList_scalar_deleting_destructor_adjustor_a0`; applied `void *__thiscall(void *thisAdjusted, unsigned int deleteFlags)`; applied repeatable comment `Compiler-generated secondary-vtable deleting-destructor adjustor: subtracts 0xA0 from this and tail-jumps to 0x00520CE0; no handwritten source method.` | Name, prototype, and comment reread; exact adjusted-pointer body and compiler-only classification preserved. |
| `0x00520b1e` function | Historical raw state: `sub_520B1E`; `_DWORD *__thiscall(_DWORD *this, char)`. | Renamed `ServerItemMenuItemList_scalar_deleting_destructor_adjustor_a4`; applied `void *__thiscall(void *thisAdjusted, unsigned int deleteFlags)`; applied repeatable comment `Compiler-generated tertiary-vtable deleting-destructor adjustor: subtracts 0xA4 from this and tail-jumps to 0x00520CE0; no handwritten source method.` | Name, prototype, and comment reread; exact adjusted-pointer body and compiler-only classification preserved. |
| `[0x0051af00,0x0051af35)` code | Historical raw pre-state: exact bounded executable bytes with no modeled function and no start xrefs. | Created a function on exactly the half-open range, renamed it `ServerItemMenuItemList_destructor`, applied `void __thiscall ServerItemMenuItemList_destructor(ServerItemMenuItemList *this)`, and applied repeatable comment `Source-visible ServerItemMenuItemList ordinary destructor: restores three class vptrs, null-safely closes g_pItemHelpPane through virtual deleting destructor flag 1, and tail-chains ListPane::~ListPane(). This body supplies the source semantics covered by UID0001C2.` | Function start/end, name, prototype, and comment reread; end `0x0051af35` and the four/eleven-byte alignment spans remain preserved. |
| `0x0069ae04` data | Historical state: correct name `g_pItemHelpPane`, 4-byte `.data`, with pointer type not surfaced by global readback. | Preserved the existing name and applied `ItemHelpPane *g_pItemHelpPane`; no duplicate global or storage item was created. | Name and pointer type reread; complete 20-xref inventory remains present. |
| vtable heads `0x0061ef44/cc/ffc` | Correct decorated names and exact first entries. | `NO_CHANGE_VERIFIED`; no rename or type overwrite. | All three decorated vtables and complete-object-locator associations reread unchanged. |
| `0x004f3b60`, `0x004f4ac0`, `0x0041b6a0` | Source-quality ListPane destructor, delete helper, and guard-stub identities were already present. | `ALREADY_PRESENT_VERIFIED`; no mutation. | Existing names/types/semantics reread and retained. |

Gate 2B persistence/readback:

- `idb_save`: `ok`.
- Saved-IDB report checkpoint: 143,184,914 bytes, SHA256 `5E9FD5FECF60D2FAC1A6A1FFFE42487AC1EE5451FA917D61EDDC93B72439BAE2` at the UID0001C2 Gate 2B save. This is a report-time checkpoint, not a claim that the mutable IDB will retain this hash indefinitely.
- The backup hash and saved-IDB checkpoint are distinct: the first records the pre-Gate-2B rollback artifact; the second records the post-Gate-2B saved IDB verified for this report.

Safety constraints:

- Do not create a function at `0x00520d47`, in either padding span, or across `0x0051af35`.
- Do not rename the scalar wrapper as source destructor `~ServerItemMenuItemList`; reserve source-destructor identity for `0x0051af00`.
- Do not invent a full class layout, force vtable data types, change decorated vtable names, or type adjustor `thisAdjusted` as a complete-object pointer before the subtraction.
- Do not overwrite the already correct singleton/helper names.
- Supervisor reread names, function bounds, prototypes, comments, vtable entries, xrefs, and padding before marking Gate 2B `APPLIED_VERIFIED`.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, but only as the required formal covered-by comment. No executable source body belongs on this wrapper page.
- Exact target formal block replacement:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact behavior: UID0001BP already expresses the source-visible destructor semantics. The compiler regenerates the scalar wrapper, adjusted vtable routes, delete flags, free path, and guarded size path.
- Reason it matches plausible original source: mid-2000s C++ developers authored a virtual/ordinary destructor, not a method exposing MSVC scalar-deleting flags.
- Source-facing names: `ServerItemMenuItemList`, `CloseItemHelpPaneSingleton`, `g_pItemHelpPane`, and `ListPane::~ListPane`; no `sub_`, `dword_`, `Block`, or `a2` label enters source.
- Naming style: retain the existing project/class spelling and helper abstraction; compiler-only IDA names use the established lowercase `_scalar_deleting_destructor` convention.
- Third-party import directive: not applicable.
- Exact no-body proof: only vtable/thunk entry, 47-byte ordinary-body parity, compiler flags/free/guard tail, and an existing ordinary source destructor. A second body would duplicate source and expose compiler ABI mechanics.

## Final Recommendation

- Exact target expansion, score `90/94`, unchanged owner/emitter/reconstructable metadata, and formal covered-by comment are applied.
- Support synchronization to UID0001BP, UID0001BZ, UID0000D0, UID0000KF, and UID00031Z is applied without declaring those support UIDs as report targets.
- Exact-artifact Gate 1 passed and B001 completed the authorized ordinary-document callback, six serial scoped validators, generated readback, and report reconciliation without touching IDA, coverage, or lifecycle state.
- Supervisor Gate 2A documentation/ledger/generated verification passed, and supervisor Gate 2B applied and independently read back every accepted IDA action above.
- Supervisor-only report execution/archive is authorized. Its current state is recorded by the validator-owned footer and lifecycle registry, which remain authoritative before and after archive; the supervisor replaces the remaining stale manual coverage rows only after those records confirm execution.
- No target blocker remains. Exact original private symbol spelling is unavailable, but the report selects project-consistent human names and does not carry raw labels into source.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md`.
- Implemented `COMPLETION:90` and `CONFIDENCE:94`.
- Preserved `CANONICAL_OWNER:0000D0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D0`, blank position, and `Nested:0`.
- Inserted the exact formal covered-by comment shown above.
- Replaced stale current-facing `below 95/95` and blank-emitter wording with current by-structure policy while retaining historical entries as superseded history.
- Added exact target byte hash, calling convention, flags type, complete control flow, object size, vtable first-entry table, complete xrefs, helper identities, ordinary-body parity, padding, generated-output expectation, and source/compiler split.
- Added a 2026-07-23 B001 change entry identifying this report as the source-quality implementation basis.

## Recommended Support Doc Changes

1. `by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md`:
   - Preserve score/metadata/formal C++.
   - Correct the Item Summary so it no longer says observer linkage or final C++ is blocked.
   - Make B002 MCP unavailability explicitly historical; add current session proof for the ordinary destructor only.
   - Record exact `[0x0051af00,0x0051af35)` bytes hash `33D2282C2082BD8A9C26F862709936EC0BFD90FEB0ECBDF2A2EF53F5CD67039A`, padding, 47-byte scalar-wrapper parity, and UID0001C2 covered-by relation.
   - Corrected generated-output wording with assignment-time nonzero `13,983` bytes/458 lines and post-callback readback `14,121` bytes/458 lines under command `000000016985`.

2. `by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md`:
   - Preserve `88/92`, false/no-owner/non-emitting metadata, and blank formal C++.
   - Current session IDA names/types/comments are recorded as supervisor Gate 2B `APPLIED_VERIFIED` while exact vtable-only/no-source disposition remains unchanged.

3. `by-class/ServerItemMenuItemList.md`:
   - Preserve `88/89`, owner/emitter UID0000KF, and existing class behavior.
   - Add the exact ordinary destructor/scalar wrapper split, `0x15c` complete-object size, UID0001C2 formal covered-by relation, and no-handwritten-wrapper constraint.

4. `by-file/ItemMenuDialogs.md`:
   - Preserve `88/89` and proposed path.
   - Add source responsibility: ordinary `ServerItemMenuItemList::~ServerItemMenuItemList()` belongs here; UID0001C2/UID0001BZ are regenerated compiler ABI output and must not be separately authored.

5. `by-type/by-vtable/ItemMenuDialogVtables.md`:
   - Preserve `88/92` and current owner.
   - Add the exact primary/secondary/tertiary destructor first-entry routes and state that UID0001C2 is covered by UID0001BP ordinary source.

6. Verify-only, no ordinary change: `by-global/g_pItemHelpPane.md`, ListPane docs, and UID0001BX aggregate. Their current facts support this report and do not need target-driven score changes.

## Score And Metadata Recommendation

- Assignment-time target: `86/91`, owner UID0000D0, true, emitter UID0000D0, blank position/formal.
- Current implemented target: `90/94`, same owner/reconstructable/emitter/position, exact nonblank covered-by formal comment.
- Completion rises because exact bytes/hash, boundaries/padding, complete control flow, ABI flags, all vtable routes, no-caller proof, complete-object size, ordinary parity, source responsibility, IDA handoff, generated expectation, and manual coverage handoff are now closed.
- Confidence rises because a healthy current IDB independently confirms all target claims and removes the historical MCP-unavailable cap.
- Reason not higher: `95+` requires a separate extreme final-audit decision and final compiler/rebuild equivalence proof. This report reaches the ordinary research ceiling without pretending original private symbol spellings were recovered.
- Score-improvement attempt:
  - Blank emitter -> resolved by exact by-structure covered-by marker.
  - Raw ordinary destructor -> resolved by exact live bytes/hash/padding/parity and supervisor Gate 2B function creation/readback on the exact bounded range.
  - Generated names/types -> resolved by exact project-consistent IDA names/prototypes/comments.
  - Observer/global ambiguity -> resolved as `g_pItemHelpPane` with current name and 20-xref inventory.
  - Caller/reachability -> resolved as vtable/thunk-only with exhaustive current xrefs.
  - Source placement -> resolved through UID0001BP/UID0000D0/UID0000KF.
  - Object size/guard behavior -> resolved as exact `0x15c` and one-byte no-op guard path.

## Open Questions With Attempted Resolution

- Is UID0001C2 a handwritten source method? Resolved: no. Ordinary-body parity plus delete-flag/free/guard mechanics prove compiler generation.
- Should it become non-reconstructable? Resolved: no. Current by-structure and analogous class scalar-wrapper pages require class-owned reconstructable coverage with a covered-by comment.
- Where does source destruction live? Resolved: UID0001BP under ItemMenuDialogs.
- What does `0x0069ae04` mean? Resolved: active `ItemHelpPane *g_pItemHelpPane`, not an observer.
- What is the flags type? Resolved: unsigned four-byte ABI word named `deleteFlags`; IDA's `char` is narrowed decompiler inference from AL tests.
- What is `0x15c`? Resolved: complete-object size, consistent with state through `+0x158`; not a row size or ListPane field.
- Is the bit-4 route a free? Resolved: no in this executable; the exact target is a one-byte return stub.
- Which source spelling should represent the close? Resolved for current reconstruction: retain established `CloseItemHelpPaneSingleton()`; direct delete is behavior-equivalent but not a reason to destabilize the current class draft.
- Remaining unresolved questions affecting owner, emitter, score, formal C++, IDA action, or implementation: none.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The B agent must not edit any `-coverage-report.md`. The current generated tracker is validator-owned and must not be hand-edited. The B001 callback, supervisor Gate 2A documentation verification, and supervisor Gate 2B IDA closure are complete. The supervisor should apply these exact manual row replacements only after the validator-owned footer/lifecycle registry confirms supervisor-only report execution/archive.

1. In `by-memory/-coverage-report.md`, replace current UID0001BP line 2513 with:

```text
    - [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) 0x0051ae90-0x0051b87a | class-method/raw-helper cluster | ServerItemMenuItemList : reconstructable : 88% : strong : Server item-menu row-list source range with exact constructor/destructor/helper and modeled virtual boundaries, corrected 0x408 row layout, opcode 0x39 string serializers, g_pItemHelpPane teardown/help behavior, current ordinary-destructor byte/hash proof, three-vtable routing, generated-output constraints, and first-draft human source under ItemMenuDialogs.
```

2. In `by-memory/-coverage-report.md`, replace current UID0001BZ line 2532 with:

```text
    - [UID:0001BZ][0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks](by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md) 0x00520b13-0x00520b29 | destructor adjustor thunks | ServerItemMenuItemListDestructorThunks : ignored : 88% : very-strong : Exact compiler-generated +0xa0/+0xa4 adjusted-this deleting-destructor thunks, reached only from secondary/tertiary ServerItemMenuItemList vtable heads and tail-jumping to UID0001C2; no handwritten source or emitter.
```

3. In `by-memory/-coverage-report.md`, replace current UID0001C2 line 2535 with:

```text
    - [UID:0001C2][0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor](by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md) 0x00520ce0-0x00520d47 | scalar deleting destructor | ServerItemMenuItemListScalarDeletingDestructor : reconstructable : 90% : very-strong : Exact 103-byte class-owned MSVC scalar deleting wrapper with target SHA256 26F97394E0C4E8A48290B31A4A5E9E46825D91576F9E40CFDEEEFC698B7C2061, primary/+0xa0/+0xa4 vtable routes, three vptr restores, null-safe g_pItemHelpPane delete, ListPane teardown, unsigned delete flags, normal free and guarded 0x15c-byte no-free paths, no ordinary callers, closed padding, and formal source coverage by UID0001BP rather than handwritten ABI code.
```

4. In `by-class/-coverage-report.md`, replace current UID0000D0 line 490 with:

```text
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md) : reconstructable : 88% : strong : Server item-menu private list class with exact 0x408 row layout, opcode 0x39 string behavior, g_pItemHelpPane lifecycle, raw/modeled method inventory, ordinary destructor source, and compiler-regenerated scalar-wrapper/adjustor routing under ItemMenuDialogs.
```

5. In `by-file/-coverage-report.md`, replace current UID0000KF line 132 with:

```text
- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) : reconstructable : 88% : strong : Server/client item-menu dialogs and private list classes with exact split children, vtable/layout anchors, factory and constructor coupling, corrected row layouts, first-draft source, and ordinary-destructor ownership separated from compiler-generated scalar/adjustor glue.
```

Inspected and currently aligned without replacement: UID00031Z in `by-type/by-vtable/-coverage-report.md` at `88%`, and UID0000R9 in `by-global/-coverage-report.md` at `92%`.

## Follow-Up Actions

- B001 callback: complete. Six accepted ordinary destinations were leased, edited, scoped-validated serially, and immediately released; the same report now records exact results.
- Supervisor Gate 2A: passed for the ordinary documentation, ledger, validator records, and generated readback.
- Supervisor Gate 2B: `APPLIED_VERIFIED` for C1C2-20 through C1C2-23 in session `supervisor_gate2b_0002OT_20260723`; B001 performed no IDA mutation.
- Supervisor lifecycle: execution/archive is authorized. Consult the validator-owned footer and lifecycle registry for the authoritative current state before or after archive; once they confirm execution, apply the remaining exact C1C2-25 manual coverage replacements and confirm final generated ItemMenuDialogs output.
- No A-agent or additional B-agent research is required for this target.

## Confidence

- Recommendation confidence: very strong (`94`) for exact target disposition and routing.
- Score confidence: strong. `90/94` matches the detail now available and stays below rare final-audit values.
- Remaining uncertainty: original private lexical spellings and exact historical compiler configuration are not recoverable from this target alone. The report resolves them with consistent descriptive IDA names and existing human source conventions; they do not block implementation.

## Validator Results

All commands ran serially from `source-3/project-documentation` with `--apply --queue-timeout 240`; every command exited `0`, scanned one Markdown file, and returned `ok: 1`.

| Destination | Command ID / timestamp | Result and side effects |
| --- | --- | --- |
| `by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md` | `000000016980` / `2026-07-23T23:51:58-04:00` | completion `90`, confidence `94`, formal registry `blank -> block`, registry hash update, projected stats update, deferred generated refresh |
| `by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md` | `000000016981` / `2026-07-23T23:52:59-04:00` | no metadata change; projected stats update; deferred generated refresh |
| `by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md` | `000000016982` / `2026-07-23T23:53:31-04:00` | no metadata change; projected stats update; deferred generated refresh |
| `by-class/ServerItemMenuItemList.md` | `000000016983` / `2026-07-23T23:54:38-04:00` | no metadata change; projected stats update; deferred generated refresh |
| `by-file/ItemMenuDialogs.md` | `000000016984` / `2026-07-23T23:55:07-04:00` | four validator-owned UID0003U9 link-label normalizations, reference-index additions for UID0001BZ/UID0001C2/UID0003U9, projected stats update, deferred generated refresh |
| `by-type/by-vtable/ItemMenuDialogVtables.md` | `000000016985` / `2026-07-23T23:55:40-04:00` | reference-index additions for UID0001BZ/UID0001C2, projected stats update, deferred generated refresh |

Generated refresh caught up through command `000000016985`. `ItemMenuDialogs.cpp` is 14,121 bytes/458 lines, SHA256 `FC9EC1F19B0F5B3C6ACF5FEFFB34941CF6D5DF7190AA3E93FF367E40BE79DD42`; UID0001C2 appears once, its exact UID0001BP covered-by comment appears once, its empty-emitter marker count is zero, and four unrelated class/vtable empty-emitter markers remain. No target-specific validator warning or error remains.

## Changed Files

| Path | Callback result | Final SHA256 / bytes / lines |
| --- | --- | --- |
| `by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md` | applied C1C2-01..19/24, score/formal/source split | `F824BA466D4D38EFF8A5B0751D9CB33B8BE5FFC073624003240AE6607CF696DE` / 13,712 / 118 |
| `by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md` | applied ordinary hash/padding/parity, current evidence/history/output correction | `9CD78B05D9BA35D326E90DA8505DE99AAF72C9A619C4413864565B94FFB53A2E` / 25,761 / 308 |
| `by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md` | applied detailed Gate 2B handoff and vtable-only disposition; supervisor action subsequently applied/verified | `CC7ED68094D1C0E54FF8A518069AB8226E014DF1AC8E2A2122E3BD963F420954` / 7,260 / 73 |
| `by-class/ServerItemMenuItemList.md` | applied ordinary/scalar split, `0x15c`, route/no-wrapper constraints | `81F29C7476CA36F07F30209DF60C3CE0619B6E0DBEFD7CC1B72079CB25494DB5` / 14,064 / 107 |
| `by-file/ItemMenuDialogs.md` | applied ordinary source responsibility and no-duplicate-ABI rule | `9AE46C364061335E93A6DDA2780443A54CF9CAC8644E5F7B1994AAEA66E1164A` / 24,383 / 141 |
| `by-type/by-vtable/ItemMenuDialogVtables.md` | applied exact first-entry routes and covered-by disposition | `42189F6F20E04BF34E90D3E3CA61AE6A60AB2B88E68DED2F3D2A10C7F9924BD2` / 10,521 / 86 |

- Verify-only/no edit: `by-global/g_pItemHelpPane.md`, [UID:0003TZ]/class/file ListPane docs, and UID0001BX aggregate agree with the report; no exact contradiction was found.
- Report updated in place: `tools/leaser/Agents/Agent-B001/research/0001C2-ServerItemMenuItemListScalarDeletingDestructor-empty-emitter-source-quality.md`.
- Renamed/created ordinary docs: none.
- B001 IDA mutation: none. Supervisor-owned C1C2-20 through C1C2-23 were subsequently applied and verified during Gate 2B as recorded in the self-contained IDA section.
- Coverage/generated direct edits by B001: none. Generated output changed only through documented scoped validators; C1C2-25 manual rows remain supervisor-only after authoritative execution confirmation.
- Leases: each of the six ordinary files was leased only for its own edit/validator batch and immediately released. Final shared lease report shows no active leases.
- Report execution by B001: not run. B001 did not run, probe, dry-run, or invoke `execute_report` or any lifecycle command. The validator-owned footer and lifecycle registry are authoritative for the supervisor-owned current execution/archive state.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 passed exact pre-callback report SHA `1C55DDB8147EFA2C66FEEF4A6604EB3E74183758499A2DB38DE949F47D069602`.
- [x] Updated target `by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md` with C1C2-01 through C1C2-19 and C1C2-24; validator `000000016980` passed.
- [x] Updated support UID0001BP with current ordinary-destructor bytes/hash/padding/parity, covered-by relation, historical MCP labeling, corrected Item Summary, and current generated state; validator `000000016981` passed.
- [x] Updated support UID0001BZ with the exact IDA handoff while retaining false/non-emitting compiler-glue status; validator `000000016982` passed, and the supervisor subsequently applied/verified the handoff at Gate 2B.
- [x] Updated support UID0000D0 with ordinary/scalar split, `0x15c` size, and covered-by relation; validator `000000016983` passed.
- [x] Updated support UID0000KF with source responsibility and no-duplicate-ABI rule; validator `000000016984` passed.
- [x] Updated support UID00031Z with exact first-slot routes and covered-by source disposition; validator `000000016985` passed.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: not applicable; no additional UIDs declared.
- [x] Supervisor Gate 2A independently verified current target state, evidence, ledger, destinations, validators, and generated output.
- [x] Claim And Incorporation Ledger was accepted at Gate 1 and now records actual B001 destination/action/verification state for all 25 claims.
- [x] Applied target score `90/94` and preserved owner/reconstructable/emitter/position/nesting metadata.
- [x] Confirmed score-limiting ordinary-document blockers are closed by the evidence and callback actions.
- [x] Confirmed no split, documentation-path rename, or new child is required.
- [x] Supervisor applied/read back C1C2-20 through C1C2-23 during Gate 2B after Gate 2A; B001 preserved the full handoff and made no IDA mutation.
- [x] Inserted exact formal covered-by comment to UID0001BP with no scalar-wrapper executable C++.
- [x] Confirmed third-party import directive is not applicable.
- [x] Preserved historical observer, old 95/95 gate, MCP-unavailable, and blank-emitter assumptions only as explicitly superseded history.
- [x] Confirmed Wave2/Wave3 artifacts were ignored as stale.
- [x] Confirmed no open question remains that affects ordinary-document implementation.
- [x] Ran one serial scoped validator for each accepted ordinary by-* file while leased and released each lease immediately afterward.
- [x] Verified generated UID0001C2 output changed from Empty Emitter Marker to the exact covered-by comment.
- [ ] Supervisor applies the remaining exact manual coverage replacements only after the validator-owned footer/lifecycle registry confirms supervisor-only report execution/archive.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact Gate 1 SHA above.
- [x] All accepted ordinary target/support details incorporated at report-level detail.
- [x] Supervisor Gate 2A independently verified target UID0001C2 against every ledger row and destination.
- [x] Claim And Incorporation Ledger updated from `proposed` to actual applied/verified/pending-supervisor states.
- [x] Metadata/score/formal comment applied exactly.
- [x] Historical/stale assumptions and negative evidence preserved and current state distinguished from history.
- [x] Open questions remain closed after implementation.
- [x] Every scoped validator command ID/result/side effect recorded; no target-specific warning/error remains.
- [x] Generated readback, file hash/metrics, UID count, exact target comment count, and UID-specific empty-marker count recorded.
- [x] Remaining unapplied ordinary-document accepted items: none. C1C2-20..23 and Gate 2A/Gate 2B are complete; only the supervisor's authoritative lifecycle handling and post-execution C1C2-25 coverage remain outside B001 scope.
- [x] Supervisor-owned Gate 2B IDA actions were applied and verified after the completed B001 callback; B001 performed no IDA mutation.
- [x] After the callback, supervisor Gate 2A independently verified ordinary documentation, ledger states, validators, and generated readback.
- [x] After Gate 2A passed, supervisor Gate 2B applied/read back C1C2-20 through C1C2-23 and saved the IDB.
- [x] Supervisor-only execution/archive is authorized; the validator-owned footer and lifecycle registry are authoritative for whether it has occurred before or after archive. Manual coverage remains separately unchecked above until those records confirm execution.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000016990","destination_path":"executed-b-agent-research/B001/0001C2-ServerItemMenuItemListScalarDeletingDestructor-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001C2-ServerItemMenuItemListScalarDeletingDestructor-empty-emitter-source-quality.md","timestamp":"2026-07-24T00:22:58-04:00","uid":"0001C2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
