# 0003A1 ScreenPaneLayerIndexLookup Source-Quality Report
** TARGET-REPORT-UID:0003A1 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Report state: accepted implementation callback complete for all B006-owned CKF-001 through CKF-035. Six scoped owning validators passed, the final generated refresh completed, current generated CPP/H were physically reread, and the artifact now requires wholly fresh Supervisor Gate 1 and Gate 2. No IDA mutation/save/manage, lifecycle/report execution, manual coverage/generated edit, audit edit, or report movement occurred.
- Recommendation: reconstruct `[0x00559360,0x005593a2)` as private `int ScreenPane::FindLayerIndex(const Layer *layer) const`, move direct semantic ownership/emission from file UID0000NB to class UID0000CB, populate the target CPP channel, and keep the target H channel blank because the class H owns the declaration.
- Source behavior: snapshot `m_rootLayerList->GetCount()`, scan zero-based entries, dereference each four-byte `Layer *` slot returned by `List::GetElementAt`, return the first matching signed index, and return `-1` for empty or absent matches. Do not add a null-list guard.
- Directly dependent repair is implemented: `ScreenPane::SetLayerFrame` and `ScreenPane::DetachLayerFrame` declarations/bodies are exact, all three direct-storage casts in UID0003A3 traversal are repaired, and UID0003A2 carries the required predecessor link. The broad UID0001G5 aggregate remains exactly non-reconstructable/non-emitting.
- Current mechanics: 33 exact H2 headings; 51 ordered Claim/Checklist twins; 35 checked B006-owned rows and 16 unchecked Supervisor-owned rows; three rename dry runs, eight independently staged persistent IDA mutations, four cache invalidations, eight literal protection entities, 112 phase/entity protection evaluations across fourteen phases, and exactly one terminal lifecycle marker after the completed callback checklist/audit content.

## Supporting Research

The assigned target is [UID:0003A1](../../../../../by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md). Dated `2026-08-25` read-only research used then-canonical session `supervisor_uid0003vm_final_20260825_1236` at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The supervisor-promoted IDB SHA256 observed at that time was `97A82F22C113675744D850FB18834AC247D4EDEDC210B3E6D347CE2CFACC0077`; the observed backing PE was `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. These are dated research receipts, not an active-session or continuing canonical-state assertion.

The dated public `runtime_attestation` at `2026-08-25T12:40:32Z` returned schema version 1, `ok:true`, no attestation errors, exact session/path binding, listener nonce `9c0b157250ebb93439d2ecec84a714f9`, and worker nonce `fb83956a56a1fb32ee42d3c22bfaa418` on worker PID 2792 / parent PID 10124 / route port 49248. At that observation, `server_health` returned `status:"ok"`, image base `0x400000`, Hex-Rays ready, strings ready with 2067 entries, and `auto_analysis_ready:false`. The same dated `func_profile`, `disasm`, `inspect_items`, `get_comments`, exact-regex `entity_query`, `xref_query`, and bounded `get_bytes` reads revalidated P01-P08 byte-for-byte and reproduced every reported name, generic prototype, complete frame, blank comment channel, item, metric, registered-name envelope, and xref without drift. The bounded Gate 1 research repair also ran four independent anchored `entity_query(kind:"names")` reads in that session: `^sub_559360$`, `^ScreenPane__FindLayerIndex$`, `^sub_556D20$`, and `^ScreenPane__DetachLayerFrame$` each returned `kind:"names"`, `data:[]`, `total:0`, `error:null`, and `next_offset:null`; function identity/size/prototype were separately established by the dated `func_profile` and item/frame reads.

Earlier superseded research history used session `supervisor_uid0003oc_final_20260825_1145` against the same path and then-observed IDB SHA256 `C67FF607291D4441F503B434B5503CCED54AFAC4C6529A5821918BC083389A11`; its `runtime_attestation` at `2026-08-25T12:13:08Z` also returned `ok:true`. Both session/SHA receipts are retained only as dated `2026-08-25` research provenance. Neither session is asserted active or current, and every later gate/transaction must establish fresh runtime, path, and disk authority independently.

Dated `2026-08-25` superseded Gate 2B no-save history: fresh isolated execution against report SHA256 `8D062BBB57901B97CE63E0C971D7D7A6BB1532DAD955E91308B6C151FC5E4AE1` passed complete baseline, DR01, and A01, then hard-stopped before A02 when the post-A01 desired-name registry query returned exactly `{"kind":"names","data":[{"kind":"name","addr":"0x559360","name":"ScreenPane__FindLayerIndex"}],"next_offset":null,"total":1,"error":null}` and the then-active report incorrectly rejected mandatory row member `kind:"name"`. Worker PID 10412 was terminated without save; canonical, working, and backup files remained byte-identical at 143211870 bytes and SHA256 `97A82F22C113675744D850FB18834AC247D4EDEDC210B3E6D347CE2CFACC0077`, and the proposed TX never existed. This failed attempt supplies response-schema evidence only: it earns no Gate 2B, save, persistence, or lifecycle credit, and all later gates must start wholly fresh against the repaired artifact.

Dated `2026-08-25T16:18:51Z` superseded Gate 2B no-save frame-contract history: fresh isolated execution against report SHA256 `127AC29D92FB69D6FC8A80E271109AA14E6353C51E10CB5B0A135A85C1B925FB` recovered the complete declared state through A04 and safely completed DR02/A05/A06 in disposable memory. A04's function `set_type` produced public prototype `void __thiscall(ScreenPane *this, Layer *layer, const Layer *beforeLayer)`, but the immediate complete physical frame remained `__saved_registers +0x04/4 _DWORD`, `__return_address +0x08/4 _UNKNOWN *`, `layer +0x0c/4 Layer *`, and `layerContext +0x10/4 int`. The transaction hard-stopped before save because the then-active report incorrectly assigned the physical name/type delta to the function-type action without a stack action. Worker PID 33796 was terminated without `idb_save`; canonical, working, and backup `.i64` files remained byte-identical at 143211870 bytes and SHA256 `97A82F22C113675744D850FB18834AC247D4EDEDC210B3E6D347CE2CFACC0077`, and the proposed TX never existed. This receipt proves function type and occupied physical-frame metadata are independent; it grants no Gate 2B, mutation, save, persistence, or lifecycle credit and is superseded only by the repaired declarative sequence below.

Accepted Gate 1 physical documentation prestate, retained as dated callback history:

| File | SHA256 | Bytes | UTC mtime | Role |
| --- | --- | ---: | --- | --- |
| `by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md` | `3B2D3CA07EE4DD93FCF16DA56345EA6C1FFBC0916BA2589168BC74AF85F31193` | 3953 | `2026-07-24T23:57:11.1940415Z` | Assigned target; blank CPP/H and stale 85/88 file-owner state. |
| `by-class/ScreenPane.md` | `E61AF0E067334F746CBB1C8C5D575D5F71145C442812541559589576E3E3A56A` | 73884 | `2026-08-24T19:27:34.8123054Z` | Then-current 93/94 class source owner; helper declarations were stale. |
| `by-file/ScreenPane.md` | `5554CF9E9D1DCAD4D678E00109CC64D0B9DABF6364D1C6C72D71BB74BDCE4EF9` | 61372 | `2026-08-18T09:58:34.0961966Z` | Then-current 93/94 `ScreenPane.cpp` route; target inventory row was absent. |
| `by-memory/0x00556910-0x00557132.ScreenPane.md` | `C886FBAA86D0FCE2FEB8D4340D94563E1C71875A8FF6DDCA15C07C2B88FC8EF7` | 32968 | `2026-08-12T18:45:29.6077944Z` | Then-current 91/93 non-emitting aggregate; helper semantics were stale. |
| `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` | `F27B0A0F4112AA1573A71B9F60F4F33403FDC69A96468DB2F015C171BE6F1F9C` | 21212 | `2026-08-12T03:23:37.5388104Z` | Then-current 90/92 source child; three List-slot casts omitted dereference. |
| `by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md` | `AADCAADD8144045636EF132BC87357A0A0A6142BA0CEA7BCBA693B887244CA26` | 18584 | `2026-08-12T09:47:34.5568765Z` | Predecessor source child; no edit required. |
| `by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md` | `FE16C4456C1F950814041E29F098E3BAAE5DBE612D945D1933929FA736CF5C36` | 15437 | `2026-07-24T23:57:11.1940415Z` | Raw successor source child; no semantic edit was required, but its then-current Cross-References list lacked UID0003A1 and established the bounded insertion prestate. |

Current post-callback physical documentation evidence:

| File | SHA256 | Bytes | UTC mtime | Current disposition |
| --- | --- | ---: | --- | --- |
| `by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md` | `3F942DED40F5E6DB52A694D121A0DFD01C7B122891401360D588E3509B8773C2` | 8275 | `2026-08-25T14:08:37.1223239Z` | Exact 90/92 target source, class owner/emitter, blank H, complete behavior/range/IDA evidence. |
| `by-class/ScreenPane.md` | `E851441EA30896B0A327E5361F3F686BC3C4703F8058590301BEAF607EA975E3` | 76689 | `2026-08-25T14:09:45.4788287Z` | Exact helper definitions/declarations, private lookup declaration, List-slot evidence; 93/94 preserved. |
| `by-file/ScreenPane.md` | `F7A9D3968A48A4DFE103457ADBFD3F22B4E884F2CAB9635F6F5EE894A9EE6CD4` | 64894 | `2026-08-25T14:16:01.0183906Z` | UID0003A1 inventory/source route and corrected helper/traversal semantics; 93/94 preserved. |
| `by-memory/0x00556910-0x00557132.ScreenPane.md` | `E565768B9755A4729483C96E015F9D1E7BF2960B8F59CC6494D2F3FB7115E198` | 33447 | `2026-08-25T14:11:04.3218959Z` | Correct active Set/Detach inventory/callers; 91/93, reconstructable false, blank CPP/H, and non-emitting role preserved. |
| `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` | `2F7A9738A679374892C9FAB1451449DE734367934B3FF67EA389055A33A8F234` | 22058 | `2026-08-25T14:12:38.9089104Z` | Exact three `Layer **` slot dereferences and current source semantics; 90/92 preserved. |
| `by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md` | `AADCAADD8144045636EF132BC87357A0A0A6142BA0CEA7BCBA693B887244CA26` | 18584 | `2026-08-12T09:47:34.5568765Z` | Physically reread and byte-identical; exact predecessor end/padding preserved with no edit. |
| `by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md` | `E1B41B9881D32D9CB1EFB54828DCB4038A05B656761EAF17C5B53448100C73A4` | 15565 | `2026-08-25T14:11:51.7940050Z` | Raw source semantics/88/88 preserved; exact UID0003A1 predecessor Cross-References row added. |

Duplicate searches covered target UID, range, `sub_559360`, `ScreenPaneLayerIndexLookup`, `FindLayerIndex`, ScreenPane layer-list terms, active Agent reports, archived/executed filename space, tracker references, and current leases. No competing active report or lease was found at the dated research observation. Relevant accepted context is the close analog UID0003KJ `DialogPane::FindControlIndex(const ControlPane *) const`, plus previously executed ScreenPane transition/traversal work. Historical reports are evidence leads only; the dated MCP and physical documentation reads support this report but do not replace fresh gate authority.

## Target

| Field | Accepted pre-callback documentation | Current callback disposition |
| --- | --- | --- |
| UID/path | UID0003A1, `by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md` | Same UID and physical path; no rename/split. |
| Exact range | `[0x00559360,0x005593a2)` | Preserve exactly. |
| IDA identity | Dated read-only prestate `sub_559360` | No callback IDA action; desired supervisor transaction identity remains `ScreenPane__FindLayerIndex`. |
| Source identity | Generic ScreenPane layer-index helper | Implemented private `int ScreenPane::FindLayerIndex(const Layer *layer) const`. |
| Documentation metadata | 85/88, owner/emitter UID0000NB, reconstructable true | Implemented 90/92, owner/emitter UID0000CB, reconstructable true. |
| CPP channel | Blank | Exact method definition from Section 22 is present. |
| H channel | Blank | Remains blank; class UID0000CB H declares the method. |
| Source file | `NexusTK/ui/core/ScreenPane.cpp` | Unchanged physical route through class UID0000CB and file UID0000NB. |

No additional target UID is claimed for coverage. Support UIDs remain independent documentation items and are changed only to keep the accepted target source/type contract internally consistent.

## Current Target State

- Dated `2026-08-25` research recheck observation: session `supervisor_uid0003vm_final_20260825_1236`, then-promoted IDB SHA256 `97A82F22C113675744D850FB18834AC247D4EDEDC210B3E6D347CE2CFACC0077`, attestation `ok:true`; P01-P08, separate function/item evidence, and all four independent exact-name registry envelopes matched this section and Section 21 at that observation. This is historical report evidence, not active current authority.
- The dated `func_profile` observation reported `sub_559360`, size `0x42`, 33 instructions, five basic blocks, two callers, no direct named callee, no strings, and public prototype `int __thiscall(_DWORD *this, int)`.
- The apparent self-callee row is the indirect `List::GetElementAt` dispatch artifact; exact disassembly has no direct recursive call.
- Complete dated frame: `__saved_registers@+0x0c`, size 4, type `_DWORD`; `__return_address@+0x10`, size 4, type `_UNKNOWN *`; `arg_0@+0x14`, size 4, type `_DWORD`.
- All four comment channels are absent/empty: address regular, address repeatable, function regular, and function repeatable.
- Exact body SHA256 is `9D18D37863AD595447A9D4BE4ED51B0B581C06DC941657452F2895D11B45B517` over 66 bytes.
- Exact incoming xrefs are code calls `0x00556cf9` and `0x00556d29`. No data/immediate pointer route was found, and VA/RVA little-endian entry-pattern searches found zero hits.
- Separate dated function evidence is one modeled `sub_559360` function at `0x00559360`, size `0x42`, with the exact generic prototype above. Independent anchored `entity_query(kind:"names")` registry observations are old/desired `0/0`: generated alias `^sub_559360$` and desired registered name `^ScreenPane__FindLayerIndex$` both returned `data:[],total:0`. Generic address parsing or a function-item lookup of `sub_559360` is non-registry behavior and cannot prove registered-name presence or absence.
- Dated pre-callback state: target CPP and H were blank, and the `2026-08-25T07:10:28-04:00` generated observation contained one UID0003A1 Empty Emitter Marker and no target body. That observation is superseded callback history.
- Current post-callback state: target CPP contains the exact `FindLayerIndex` body, target H remains blank under the class-header convention, and the fresh generated reread at `2026-08-25T14:16:25Z` contains exactly one UID0003A1 body and zero UID0003A1 Empty Emitter Markers.

## Executive Recommendation

Accept the target as a normal handwritten private ScreenPane method. The constructor establishes a non-null `List(4,4)` at `ScreenPane+0x10c`; the target snapshots count, dereferences each List element storage slot as `Layer *`, and returns first index or `-1`. The exact analog in DialogPane establishes the project source idiom and resolves the list-access blocker.

The accepted bounded callback incorporated the target together with every required compile/source dependency: the class page now carries the two public mutation helpers and private lookup declaration, UID0003A3 dereferences the same pointer slots in all three accesses, and UID0003A2 carries the UID0003A1 predecessor cross-reference while preserving raw-helper source and semantics. This remained a bounded support repair, not a ScreenPane-wide rewrite.

## Supervisor Active Recheck

Fresh post-repair Gate 1 must physically reread this exact report artifact and current destination docs. The prior Gate 1 pass for pre-callback SHA256 `F8FB24B978AC908308201507678027B371859CB8BD6496C698E7E4AC8290388B` and the later Gate 1/Gate 2A review of pre-repair SHA256 `8D062BBB57901B97CE63E0C971D7D7A6BB1532DAD955E91308B6C151FC5E4AE1` are historical and do not authorize the repaired revision. Fresh Gate 2A must independently verify the six current scoped validator receipts, final generated-wait result, current destination hashes, and physical generated `ScreenPane.cpp`/`.h` readback recorded below.

Gate 2B must start from the supervisor's current collision-safe isolated-copy procedure. The dated research session name above is evidence only. Every `idb_open` must use `run_auto_analysis:false`; every later MCP request must use the exact returned database identifier. Fresh `runtime_attestation`, canonical/working disk identity, function/item/frame/comment/xref readback, 56 independent exact-name registry requests across fourteen phases, and every protection must pass before any action/save. Any busy/unavailable MCP, active-path ambiguity, stale prestate, unexpected response shape, type promotion, frame drift, or protection mismatch is a hard stop with no save.

## Inference Research Guidance Check

- Exact original private method symbols are unavailable, so naming was resolved by behavior, same-project conventions, caller factorization, and the accepted DialogPane analog.
- `FindLayerIndex` outranks `GetLayerIndex`, `IndexOfLayer`, and the filename phrase `ScreenPaneLayerIndexLookup`: it names first-match search semantics and matches `FindControlIndex`.
- `const Layer *` is supported because the target only compares the supplied pointer. The method is source-const because it performs no ScreenPane/List mutation.
- IDA's C-style explicit-receiver function declaration cannot encode the trailing C++ member `const`; its analysis prototype therefore intentionally uses mutable `ScreenPane *this` while formal source uses trailing `const`. This is source/analysis representation, not an ABI or frame difference.
- `m_rootLayerList` is already the accepted class field at `+0x10c`; no new member or container type is invented.
- `Layer *entry = *static_cast<Layer **>(GetElementAt(index))` is mandatory. A direct cast treats element storage as the object pointer and contradicts `cmp [eax],ecx`.

## Heuristic / Inference Reanalysis And Validation

| Question | Alternatives tested | Resolution |
| --- | --- | --- |
| Owner | ScreenPane, Pane, Surface, MapPane, free helper | ScreenPane accepted: receiver field `+0x10c`, both direct callers, constructor/destructor list lifecycle, and class analog converge. Others are base/dependency/neighborhood/generated-owner explanations only. |
| Method name | `FindLayerIndex`, `GetLayerIndex`, `IndexOfLayer`, raw lookup title | `FindLayerIndex` accepted as best-supported project spelling; exact original spelling remains a confidence cap only. |
| Access | public, protected, private | Private accepted: only two same-class helper methods call it; no external/vtable/pointer route exists. |
| Argument | integer/id, `Layer *`, `const Layer *` | `const Layer *` accepted: caller passes a Layer pointer and body compares the stored pointer directly without dereferencing Layer state. |
| Return | bool, unsigned index, signed int | Signed `int` accepted: exact `-1` miss and nonnegative zero-based index success. |
| Container | custom ScreenLayerEntry array, generic List of pointers | Generic `List *` accepted: constructor `List(4,4)`, count `+0x0c`, virtual GetElementAt slot `+0x10`, and pointer-slot dereference. |
| Null behavior | source null guard, constructor invariant | No list guard accepted: binary dereferences the list before any guard; constructor/destructor establish owned lifetime. A null search pointer remains comparable and can match a stored null. |
| Duplicate behavior | last match, all matches, first match | First match accepted because equality branches immediately to the success return. |
| Compiler disposition | handwritten helper, compiler thunk, inlined artifact | Handwritten method accepted: ordinary prologue/epilogue, explicit loop/control flow, two source-level callers, and no ABI-helper pattern. |

The source-quality blocker is resolved, not deferred: concrete List layout plus UID0003KJ prove the element-slot dereference and exact C++03 expression. The remaining uncertainty is original private spelling only, which is represented by score rather than a raw label in source.

## Evidence Standards Used

- Dated pre-callback by-* content and hashes establish the accepted Gate 1 documentation prestate; current post-callback hashes and physical rereads establish implementation results.
- Live read-only public MCP calls establish IDA function/item/type/frame/comment/xref/registry state.
- Exact byte hashes and end-exclusive ranges protect physical identity.
- Constructor/destructor and List documentation establish field/container lifetime and API semantics.
- Direct callers establish argument role, mutation relationship, and method access.
- Accepted same-project source analogs resolve source idiom where symbols are absent.
- Generated output is dynamic authority. The dated pre-callback observation is history; command `000000028163` completed the authorized generated wait, and the immediately following physical CPP/H hashes and semantic reread are the current callback receipt for fresh gate verification.
- Historical audit/report text is provenance or a search lead, never a substitute for fresh current evidence.

## Evidence Checked

Dated `2026-08-25` read-only MCP evidence included `runtime_attestation`, `server_health`, `func_profile`, `disasm`, `decompile`, `inspect_items`, `get_comments`, `entity_query`, `xref_query`, bounded `get_bytes`, and VA/RVA entry-pattern searches for target and support boundaries. The then-public schemas were inspected for `rename`, `set_type`, `set_function_comments`, `force_recompile`, `entity_query`, `func_profile`, `disasm`, `inspect_items`, `get_comments`, and `xref_query`. These are research observations rather than continuing session authority, and no mutation endpoint was invoked.

Physical documentation checked the target, ScreenPane class/file/aggregate, transition predecessor, raw palette successor, traversal child, List class/file/member semantics, DialogPane FindControlIndex analog, generated ScreenPane CPP/H, three manual coverage reports, validator-owned tracker, active/archived report filename searches, audit references, goal, workflow skill, status instructions, and current lease report. Before callback, the UID0003A2 `Cross-References` block contained no UID0003A1 link, converting its support action from conditional to unconditional. Post-callback physical reread confirms the literal link is present, the predecessor page remains byte-identical, and each other destination matches the current hash table above.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| CKF-001 | 0003A1 | Preserve exact target range 0x00559360-0x005593a2, 66-byte body SHA256 9D18D37863AD595447A9D4BE4ED51B0B581C06DC941657452F2895D11B45B517, 33 instructions, and five blocks. | exact | Live disasm, bytes, func_profile. | Target Status, Address Range, IDA Evidence. | incorporate | callback-verified |
| CKF-002 | 0003A1 | Record dated IDA name sub_559360, generic prototype, complete three-row frame, and four absent comment channels as prestate. | exact | Live func_profile, disasm, get_comments. | Target IDA MCP Evidence. | incorporate | callback-verified |
| CKF-003 | 0003A1 | Record exactly two incoming code xrefs at 0x00556cf9 and 0x00556d29 and no data/immediate/pointer-table route. | exact | Live xref_query and byte-pattern searches. | Target callers/xrefs. | incorporate | callback-verified |
| CKF-004 | 0003A1 | Preserve seven-byte predecessor padding, fourteen-byte successor padding, and raw 92-byte successor beginning 0x005593b0 as separate exact items. | exact | inspect_items, bytes, hashes, zero boundary xrefs. | Target range/boundary analysis. | incorporate | callback-verified |
| CKF-005 | 0003A1 | Record ScreenPane constructor allocation of List(4,4) at m_rootLayerList +0x10c and destructor ownership/lifetime. | very strong | Constructor/decompile, class layout, destructor docs. | Target behavior and ownership. | incorporate | callback-verified |
| CKF-006 | 0003A1 | Model List GetElementAt as returning four-byte element storage that must be dereferenced to obtain Layer *. | exact | cmp [eax],ecx, List slot +0x10, UID0003KJ analog. | Target behavior/source notes. | incorporate | callback-verified |
| CKF-007 | 0003A1 | Preserve count snapshot, signed empty/miss -1, first-match return, duplicate-first behavior, null search-pointer comparability, and no null-list guard. | exact | Target control flow and constructor invariant. | Target Behavior. | incorporate | callback-verified |
| CKF-008 | 0003A1 | Use private source signature int ScreenPane::FindLayerIndex(const Layer *layer) const; retain original spelling as a score cap only. | very strong | Caller scope, source convention, no mutation. | Target status/signature/access. | incorporate | callback-verified |
| CKF-009 | 0003A1 | Change direct semantic owner/emitter from UID0000NB to class UID0000CB while retaining ScreenPane.cpp file route through UID0000NB. | very strong | Class method semantics and project class-child convention. | Target metadata/ownership. | incorporate | callback-verified |
| CKF-010 | 0003A1 | Classify target as ordinary handwritten source and reject compiler thunk, raw helper, and standalone file routes. | exact | Ordinary function shape, callers, behavior. | Target compiler/source disposition. | incorporate | callback-verified |
| CKF-011 | 0003A1 | Populate target CPP with the exact FindLayerIndex body in Section 22. | very strong | Complete source reconstruction. | Target RECONSTRUCTION_CPP. | incorporate | callback-verified |
| CKF-012 | 0003A1 | Keep target H exactly blank because owning class H carries the private declaration. | exact | Existing child/header convention. | Target RECONSTRUCTION_H. | incorporate | callback-verified |
| CKF-013 | 0003A1 | Raise target metadata 85/88 to 90/92 and replace Item Summary with exact source/behavior/route wording. | very strong | Closed source/type/range/owner evidence; spelling cap. | Target metadata and Item Summary. | incorporate | callback-verified |
| CKF-014 | 0003A1 | Replace stale target prose and links with current exact behavior, caller, owner, range, source, edge, and support relationships. | exact | Full report evidence. | Target body/cross-references/Changes. | incorporate | callback-verified |
| CKF-015 | 0000CB | Replace public SetLayerFrame declaration with void SetLayerFrame(Layer *layer, const Layer *beforeLayer). | exact | Live helper prototype/body and call arguments. | ScreenPane class H. | incorporate | callback-verified |
| CKF-016 | 0000CB | Replace public int DetachLayerFrame with void DetachLayerFrame(Layer *layer). | exact | Live helper body, ignored return, RemoveAt dispatch. | ScreenPane class H. | incorporate | callback-verified |
| CKF-017 | 0000CB | Add private int FindLayerIndex(const Layer *layer) const before BlitSurfaceToDisplay. | very strong | Access and source contract. | ScreenPane class H. | incorporate | callback-verified |
| CKF-018 | 0000CB | Add exact SetLayerFrame definition before existing OnFrameUpdate in class CPP. | exact | 0x00556ce0 branch and InsertAt(index,1,&layer). | ScreenPane class CPP. | incorporate | callback-verified |
| CKF-019 | 0000CB | Add exact DetachLayerFrame definition before existing OnFrameUpdate in class CPP without an index guard. | exact | 0x00556d20 FindLayerIndex then RemoveAt(index,1). | ScreenPane class CPP. | incorporate | callback-verified |
| CKF-020 | 0000CB | Add current helper/lookup/List evidence and historicalize stale slot/int/return wording without changing 93/94. | exact | Live support analysis. | ScreenPane class prose/Changes. | incorporate | callback-verified |
| CKF-021 | 0000NB | Add UID0003A1 to ScreenPane.cpp inventory/source role and describe class-owned child emission. | exact | Accepted prestate file inventory omission and owner route. | ScreenPane file Proposed Contents/evidence. | incorporate | callback-verified |
| CKF-022 | 0000NB | Correct root helper and traversal List-slot/source-completion prose without changing file 93/94. | exact | Live callers and generated gaps. | ScreenPane file role/evidence/Changes. | incorporate | callback-verified |
| CKF-023 | 0001G5 | Correct active SetLayerFrame/DetachLayerFrame inventory and caller prose to pointer insertion/removal semantics. | exact | Live helper disassembly. | Broad ScreenPane aggregate inventory/evidence. | incorporate | callback-verified |
| CKF-024 | 0001G5 | Preserve aggregate 91/93, reconstructable false, blank CPP/H, and non-emitting role; exact child/class routes own source. | exact | Current aggregate architecture. | Broad aggregate status/rationale. | already-present | callback-verified |
| CKF-025 | 0003A3 | Replace all three direct Layer casts with dereferenced Layer ** slot accesses in formal CPP. | exact | Live traversal disassembly at all three accesses and List contract. | Traversal RECONSTRUCTION_CPP. | incorporate | callback-verified |
| CKF-026 | 0003A3 | Historicalize active stale direct-cast/no-blocker prose and state exact Layer-pointer slot semantics; preserve 90/92. | exact | Accepted prestate formal source versus binary. | Traversal current state/behavior/Changes. | incorporate | callback-verified |
| CKF-027 | 0003A0 | Preserve predecessor method pair, exact end 0x00559359, and following seven-byte padding; no semantic edit. | exact | Current doc and live boundary. | Transition page readback. | already-present | callback-verified |
| CKF-028 | 0003A2 | Preserve raw successor 0x005593b0-0x0055940c and its source route; unconditionally add the exact UID0003A1 predecessor link absent at accepted prestate from Cross-References, then scoped-validate and physically reread the page. | exact | Live raw code item and accepted/current physical Cross-References readbacks. | Raw successor Cross-References/Validator Results. | incorporate/validate/read back | callback-verified |
| CKF-029 | 0003A1 | State that target owns no file-global/static-data island; m_rootLayerList and Layer/List types are external class dependencies. | exact | No data/immediate xrefs and class field ownership. | Target source placement/negative evidence. | incorporate | callback-verified |
| CKF-030 | 0003A1 | Run scoped owning validator for the target during accepted callback. | exact | Workflow validator contract. | Validator Results. | incorporate | callback-verified |
| CKF-031 | 0000CB | Run scoped owning validator for ScreenPane class after CPP/H repair. | exact | Workflow validator contract. | Validator Results. | incorporate | callback-verified |
| CKF-032 | 0000NB | Run final scoped owning validator for ScreenPane file with documented generated wait. | exact | File owner/generator route. | Validator Results. | incorporate | callback-verified |
| CKF-033 | 0001G5 | Run scoped owning validator for broad aggregate after prose correction. | exact | Workflow validator contract. | Validator Results. | incorporate | callback-verified |
| CKF-034 | 0003A3 | Run scoped owning validator for traversal after formal CPP correction. | exact | Workflow validator contract. | Validator Results. | incorporate | callback-verified |
| CKF-035 | 0003A1 | Physically reread fresh generated ScreenPane.cpp/H, verify exact bodies/declarations/order and no UID0003A1 empty marker or duplicate target body, and add current receipts to report. | exact | Dynamic generated-authority rule. | Validator Results/Changed Files. | incorporate | callback-verified |
| CKF-036 | 0003A1 | Insert exact manual by-memory coverage row after UID0003A0 and before UID0003A3. | exact | Current manual coverage omission. | by-memory/-coverage-report.md. | incorporate | proposed |
| CKF-037 | 0000CB | Replace exact manual by-class coverage row with current helper/lookup/List wording at unchanged 93. | exact | Current row and support repair. | by-class/-coverage-report.md. | incorporate | proposed |
| CKF-038 | 0000NB | Replace exact manual by-file coverage row with target/helper/traversal completeness wording at unchanged 93. | exact | Current row and source route. | by-file/-coverage-report.md. | incorporate | proposed |
| CKF-039 | 0003A1 | DR01 perform the literal pure target rename dry run; require the closed `func[]`/summary schema, exact old/name/address echoes, complete unchanged function/item/frame/comment/xref state, and independent old/desired registry `data:[],total:0`; enforce the shared exact `{kind:"name",addr,name}` schema for every later present row. | exact | Current MCP rename/entity_query schemas. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-040 | 0003A1 | A01 perform only the pure target rename under the closed persistent response schema; retain immediate generic type and require the independent target desired-name transition to `total:1` with exactly one `{kind:"name",addr,name}` row at numeric `0x559360` and the exact desired name, while both old-name states and detach desired state remain exact zero states. | exact | Rename/entity_query schemas and no-promotion contract. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-041 | 0003A1 | A02 apply the exact named target function declaration; require one mandatory exact edit echo and the complete three-row post-type frame. | exact | Current set_type schema and frame delta. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-042 | 0003A1 | A03 set only the exact regular function comment; require exactly one top-level `result` member containing exactly one `{addr,error?}` row, mandatory string `addr` numerically equal to `0x559360`, and optional string `error` physically absent or exactly `""`; forbid every other row or top-level member, preserve the complete four-channel `get_comments` postread, and preserve every non-comment protection. | exact | Current set_function_comments schema and exact target response contract. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-043 | 0001G5 | Execute the repaired SetLayerFrame chain in exact order: A04-F applies only the function declaration and must retain physical `layerContext +0x10/4 int`; DR04 dry-runs only `layerContext -> beforeLayer` under the closed stack response schema with no state change; A04-R applies that name-only stack rename and must retain type `int`; A04-T applies only the occupied-row stack type `const Layer *`; require both cache refreshes, every complete immediate frame, and no unlisted delta. | exact | Failed no-save A04 receipt, repair-time current public rename/set_type schemas, current complete frame, and prior successful occupied-stack evidence. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-044 | 0001G5 | DR02 perform the literal pure detach rename dry run; require the closed `func[]`/summary schema, complete unchanged state, detach old/desired registry `data:[],total:0`, and the unchanged target desired-name `total:1` state as exactly one `{kind:"name",addr,name}` row. | exact | Current MCP rename/entity_query schemas. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-045 | 0001G5 | A05 perform only the pure detach rename under the closed persistent response schema; retain immediate generic type and require target/detach desired-name `total:1` states each as exactly one `{kind:"name",addr,name}` row at its numeric action target with its exact desired name, while both old-name states remain exact zero states. | exact | Rename/entity_query schemas and no-promotion contract. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-046 | 0001G5 | A06 apply the exact named detach function declaration; require one mandatory exact edit echo and the complete three-row post-type frame. | exact | Live helper semantics and set_type schema. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-047 | 0003A1 | Evaluate eight literal protections independently at all 14 phases, for exactly 112 evaluations; preserve all bytes/items/xrefs and hard-stop before save on any mismatch. | exact | Section 21 phase/protection contract. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-048 | 0003A1 | Supervisor performs wholly fresh exact-artifact Gate 1 on the post-callback report before Gate 2. | exact | B-agent lifecycle. | Supervisor Gate 1. | incorporate | proposed |
| CKF-049 | 0003A1 | Supervisor performs Gate 2A after callback using fresh docs, validator receipts, and generated physical readback. | exact | B-agent lifecycle. | Supervisor Gate 2A. | incorporate | proposed |
| CKF-050 | 0003A1 | Supervisor performs the isolated fourteen-phase Gate 2B sequence with three dry runs, eight atomic persistent mutations, four cache invalidations, 56 registry reads, 112 protection evaluations, sole save only after S00, fresh reopen R00, and guarded rollback on failure. | exact | Section 21 transaction handoff. | Supervisor Gate 2B. | incorporate | proposed |
| CKF-051 | 0003A1 | Supervisor alone executes report lifecycle after Gates 1, 2A, and 2B pass. | exact | Workflow lifecycle boundary. | Supervisor lifecycle. | incorporate | proposed |

## Positive Evidence Summary

- Exact target body is small, bounded, internally coherent, and fully understood.
- Two direct callers are exactly the insertion and removal methods over the same ScreenPane list.
- Constructor allocation `List(4,4)` proves four-byte Layer pointer elements; destructor proves owner lifetime.
- The comparison instruction is `cmp [eax],ecx`, directly proving element-storage dereference.
- Signed `jle`, signed loop compare, and `or eax,0xffffffff` prove exact count and miss behavior.
- UID0003KJ provides an accepted same-project first-match List-pointer source pattern.
- The direct semantic owner and physical source route already exist and clear the parent gate at 93/94.
- No external data island, pointer-table route, compiler-wrapper behavior, or split ambiguity blocks source.

## IDA MCP Facts

### Target `0x00559360`

| Property | Exact dated `2026-08-25` observed value |
| --- | --- |
| Function | `sub_559360 [0x00559360,0x005593a2)`, size `0x42` |
| Prototype | `int __thiscall(_DWORD *this, int)` |
| Metrics | 33 instructions, five blocks, two callers |
| Body SHA256 | `9D18D37863AD595447A9D4BE4ED51B0B581C06DC941657452F2895D11B45B517` |
| Frame | `__saved_registers +0x0c/4 _DWORD`; `__return_address +0x10/4 _UNKNOWN *`; `arg_0 +0x14/4 _DWORD` |
| Comments | Address regular/repeatable absent; function regular/repeatable absent |
| Xrefs | `0x00556cf9`, `0x00556d29`, both code |
| Registry / modeled item | Anchored `kind:"names"` old/desired registry counts `0/0`; independently, one modeled function exists at target `0x00559360`. |

Instruction-level semantics: `[ebx+0x10c]` loads `m_rootLayerList`; `[list+0x0c]` snapshots count; `jle` selects miss for nonpositive count; vtable slot `+0x10` retrieves element storage; `cmp [eax],ecx` compares stored Layer pointer; equality returns ESI index; miss returns `-1`; both epilogues use `retn 4`.

### Support `0x00556ce0`

The dated research observation for `ScreenPane_SetLayerFrame [0x00556ce0,0x00556d1b)` was 59 bytes, SHA256 `077953A582CDB9430AF2B7FB03882E7220FEB0BF7721105B140B5D71358A0B67`, 24 instructions, four blocks, public prototype `void __thiscall(ScreenPane *this, Layer *layer, int layerContext)`, and blank comments. The observed frame was `__saved_registers +0x04/4 _DWORD`, `__return_address +0x08/4 _UNKNOWN *`, `layer +0x0c/4 Layer *`, and `layerContext +0x10/4 int`.

Repair-time read-only MCP at `2026-08-25T16:22:03Z` used active canonical session `1105c43d` only as a dated observation. `runtime_attestation` returned `ok:true` for exact canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; exact-address `func_profile` returned `ScreenPane_SetLayerFrame`, size `0x3b`, 24 instructions, four blocks, and no public prototype text, while independent `stack_frame` reproduced the same complete four physical rows above. Current public schemas expose occupied-row `rename.batch.stack {func_addr,old,new}` with collision-safe dry run and `set_type {addr,kind:"stack",name,variable,ty}`; prior successful xHigh evidence establishes `declare_stack` as creation-only. Therefore this occupied row must use rename plus stack type, never `declare_stack`, `delete_stack`, or function-signature propagation. This dated read/schema observation is research evidence only and does not bind a future transaction database.

If the second argument is non-null, it calls the target to obtain the insertion index; otherwise it uses current count. It then calls List slot `+0x14`, exact `InsertAt(index,1,&layer)`. Ten direct call addresses are `0x004f6331`, `0x004f6340`, `0x004f634f`, `0x004f635e`, `0x004f636d`, `0x004f637c`, `0x0050f349`, `0x00512748`, `0x00546c04`, and `0x00546cb5`.

### Support `0x00556d20`

The dated research observation for `sub_556D20 [0x00556d20,0x00556d41)` was 33 bytes, SHA256 `2B037E3C214AEE930888F6DAF3C9A6359833C4EFAF744AF56A53DDCA6BCDF47C`, 14 instructions, one block, public prototype `int __thiscall(int this, int)`, and blank comments. The observed frame was `__saved_registers +0x04/4 _DWORD`, `__return_address +0x08/4 _UNKNOWN *`, and `arg_0 +0x0c/4 _DWORD`.

It calls the target, then calls List slot `+0x1c`, exact `RemoveAt(index,1)`, without guarding `-1`. All observed callers ignore incidental EAX. Ten direct call addresses are `0x004f64cc`, `0x004f64dd`, `0x004f64ee`, `0x004f64ff`, `0x004f6510`, `0x004f6521`, `0x005045bb`, `0x0050489c`, `0x005108aa`, and `0x00546db3`.

## Function / Child Inventory

| Range | Current model | Source disposition |
| --- | --- | --- |
| `0x00559359-0x00559360` | One unnamed/untyped seven-byte data item, SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`, bytes all `cc` | Alignment only; predecessor UID0003A0 ends exactly at 0x00559359. |
| `0x00559360-0x005593a2` | Modeled target function | Handwritten private `ScreenPane::FindLayerIndex`; target CPP emits. |
| `0x005593a2-0x005593b0` | One unnamed/untyped fourteen-byte data item, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, bytes all `cc` | Alignment only. |
| `0x005593b0-0x0055940c` | Raw code, no modeled function, 92 bytes, SHA256 `4EE9B5D73EFF5D1AB5F4063E21EED4ED23A5BA9AA5C1876A306A4CA1B0E9B6D9` | Existing UID0003A2 file-static source helper; separate sibling. |
| `0x00556ce0-0x00556d1b` | Modeled SetLayerFrame helper | Existing class method; class CPP/H correction. |
| `0x00556d1b-0x00556d20` | Five `cc` bytes, SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329` | Alignment only. |
| `0x00556d20-0x00556d41` | Modeled detach helper | Existing class method; class CPP/H correction. |
| `0x00556d41-0x00556d50` | Fifteen `cc` bytes, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C` | Alignment only. |

No target split, child creation, range extension, padding absorption, or raw-successor conversion is warranted.

## Direct Xref / Caller Inventory

| Target | Direct call sites | Caller function roles |
| --- | --- | --- |
| `0x00559360` | `0x00556cf9`, `0x00556d29` | SetLayerFrame computes insertion-before index; DetachLayerFrame computes removal index. |
| `0x00556ce0` | Ten exact addresses listed in Section 13 | Startup registers six root UI layers; map/world-map and FlyingParcel paths insert layers relative to another Layer or append with null. |
| `0x00556d20` | Ten exact addresses listed in Section 13 | Shutdown removes six root UI layers; map/effect/FlyingParcel cleanup removes registered Layer pointers. |

At the dated research observation, target start had no data/immediate route, while target end `0x005593a2`, predecessor padding head `0x00559359`, and raw successor start `0x005593b0` had zero incoming xrefs in the bounded queries. The helper call sites prove same-class composition but do not make their external callers owners.

## Documentation Evidence And IDA Status

Accepted pre-callback target state: the 85/88 prose identified ScreenPane ownership generally but left formal source blank and used the file page as direct semantic owner. Current target state is 90/92 with exact CPP, blank H, and class UID0000CB direct ownership/emission.

Accepted pre-callback class state was 93/94 and source-bearing but had contradictory active declarations `int SetLayerFrame(int slot, Layer *layer)` and `int DetachLayerFrame(Layer *layer)`, while generated `ScreenPane.cpp` lacked both definitions. Current class remains 93/94 and now contains the exact public declarations/definitions plus private `FindLayerIndex` declaration.

Accepted pre-callback UID0001G5 was 91/93 and correctly non-emitting, but its active rows described a frame id/slot instead of pointer insertion-before semantics. Current aggregate remains 91/93, reconstructable false, blank, and non-emitting; its active rows now route exact semantics through the class and target child.

Accepted pre-callback UID0003A3 was 90/92 and used Layer pointers semantically, but its formal CPP directly cast `GetElementAt` storage in three places. Current UID0003A3 remains 90/92 and all three expressions now perform the required pointer-slot dereference.

Dated pre-callback generated observation only: validator command id `000000028114`, refreshed `2026-08-25T07:10:28-04:00`. `ScreenPane.cpp` SHA256 `8C60DC45696D60616A2802ACBE0CF519CAC9717670657F783FAEFA928643E76A`, 24584 bytes, UTC mtime `2026-08-25T11:10:49.2903118Z`; `ScreenPane.h` SHA256 `5CA8BEA464EC9DE53AC783A046EF28CA5432F7BFD9313C9A555443ED56199B76`, 3677 bytes, UTC mtime `2026-08-25T11:10:49.3313042Z`. This is superseded history, not continuing generated authority. Current generated authority is the command `000000028163` physical reread and hashes in Validator Results.

## Ranked Ownership Analysis

| Rank | Candidate | Evidence | Decision |
| ---: | --- | --- | --- |
| 1 | UID0000CB ScreenPane class | Receiver field +0x10c, two same-class helper callers, constructor/destructor lifecycle, existing class declaration/source route. | Accepted direct semantic owner and emitter. |
| 2 | UID0000NB ScreenPane file | Physical `ScreenPane.cpp` route and full family inventory. | Accepted source-file route, not direct semantic owner. |
| 3 | UID0000MC Pane | ScreenPane derives from Pane and Layers are panes. | Rejected direct owner; Pane has no +0x10c field and callers use ScreenPane receiver. |
| 4 | Layer | Stored element type and comparison argument. | Rejected owner; Layer is element/dependency, not receiver. |
| 5 | Surface/MapPane | Address neighborhood and external caller context. | Rejected as neighborhood/caller pollution. |
| 6 | Free/static helper | Small non-virtual body. | Rejected; thiscall receiver and private same-class calls establish a member. |

Parent gate passes: target recommendation 90/92 is below current class 93/94 and routes through current file 93/94.

## Source Placement

- Target CPP belongs in UID0003A1 and emits through class UID0000CB into `NexusTK/ui/core/ScreenPane.cpp`.
- Target H remains blank. The private declaration belongs once in UID0000CB's complete class H.
- SetLayerFrame and DetachLayerFrame definitions belong in UID0000CB CPP before existing OnFrameUpdate; their public declarations remain in UID0000CB H with corrected types.
- UID0003A3 retains its full CPP body but replaces three List element expressions. Its H stays blank under the existing class declaration route.
- UID0001G5 remains a non-emitting inventory. UID0000NB remains the file route/inventory and does not duplicate bodies.
- Source order expectation: class-owned SetLayerFrame and DetachLayerFrame precede OnFrameUpdate; existing class children remain deterministic; UID0003A0 precedes UID0003A1; file-static UID0003A2 and traversal UID0003A3 follow in address order.
- No target-owned global, file-static data island, UDT, resource, or standalone header exists. `m_rootLayerList`, `Layer`, and `List` are class/dependency declarations.

## Range / Split / Padding / Reclassification Analysis

The assigned range is already exact. The target ends at `0x005593a2`; fourteen `cc` bytes separate it from raw UID0003A2 at `0x005593b0`. Seven `cc` bytes separate predecessor UID0003A0's exact end `0x00559359` from target start. Neither padding head has a name, type, comment, or xref.

The two support helper ranges are also exact and separated by five and fifteen byte `cc` runs. Their missing source does not require child creation because UID0000CB already owns class-level method definitions and UID0001G5 intentionally remains a non-emitting aggregate. No function creation/deletion, boundary edit, make-code/data operation, or padding comment is recommended.

## Negative Evidence Summary

- No target data/immediate xrefs or VA/RVA entry-pointer hits.
- No vtable slot, exported symbol, standalone source-file evidence, or indirect dispatch.
- No target-owned global/static/data island.
- No null-list check, no index bounds correction, no second-match/all-match behavior.
- No Layer field dereference; argument is compared as a pointer.
- No source-level recursion; the apparent profile self-callee is virtual-call resolution noise.
- No evidence supports Pane, Layer, Surface, MapPane, or free-helper ownership.
- No evidence supports current class declaration's `slot` integer or either helper's `int` return.
- No reason to emit source from broad UID0001G5 or to hand-author alignment/compiler artifacts.
- No active competing B-agent report or lease was found.

## IDA Rename / Type / Comment Recommendations

### Dynamic authority and operation totals

This report specifies target mutations only; it does not replace the supervisor's backup/save/rollback procedure. Gate 2B totals are exactly three non-mutating rename dry runs, eight persistent one-mutation actions, four nonpersistent `force_recompile` cache invalidations, four independent exact-name registry requests at each of fourteen phases (`56` requests), eight protection entities, fourteen protection phases, and 112 entity evaluations. There is one sole supervisor save only after every action and pre-save protection passes.

`DB` below means the exact session identifier returned by the fresh isolated `idb_open`; every open explicitly sets `run_auto_analysis:false`. Fresh runtime attestation and complete baseline reads precede DR01.

### Exact-name registry request

At every phase issue four independent literal public `entity_query` requests against `DB`, each containing exactly one `{kind:"names",regex:<anchored-regex>,count:0,fields:["addr","name"],sort_by:"addr"}` query. The anchored regexes are `^sub_559360$`, `^ScreenPane__FindLayerIndex$`, `^sub_556D20$`, and `^ScreenPane__DetachLayerFrame$`; old and desired names are never combined into a looser expression or inferred through another endpoint. Each decoded request result must contain exactly one envelope with mandatory `kind:"names"`, `data`, and `total`. Optional `error` and `next_offset` may each be physically absent or JSON null; any non-null value fails closed, and neither optional member is required to be physically present. A zero state is exactly `data:[],total:0`. A desired-name present state is exactly `total:1` with one data row containing exactly three mandatory members: `kind:"name"`, string `addr` numerically equal to the expected action target, and exact desired `name`. Missing `kind:"name"`, duplicate/extra/reordered rows, a fourth or other unlisted row member, wrong/non-numeric address, wrong name, continuation, or any unlisted envelope/data state fails closed.

Function existence, start/end/size, public prototype, frame, and item identity are separate protections established through exact-address `func_profile`, `inspect_items`, and complete frame reads; no `kind:"names"` result is asked to carry size or prototype. A generic address-parsed `lookup_funcs("sub_559360")`/`lookup_funcs("sub_556D20")`, or the generated function name returned by exact-address function inspection, is explicitly non-registry behavior and cannot prove old registered-name presence or absence.

| Phase | Target old/desired exact registered-name state | Detach old/desired exact registered-name state |
| --- | --- | --- |
| B00, post-DR01 | old `0`; desired `0` | old `0`; desired `0` |
| post-A01 through post-A04-F, post-DR04, post-A04-R, post-A04-T, post-DR02 | old `data:[],total:0`; desired `total:1` with exactly one `{kind:"name",addr,name}` row whose `addr` is numerically `0x559360` and whose `name` is exactly `ScreenPane__FindLayerIndex` | old `data:[],total:0`; desired `data:[],total:0` |
| post-A05, post-A06, S00, R00 | old `data:[],total:0`; desired `total:1` with exactly one `{kind:"name",addr,name}` row whose `addr` is numerically `0x559360` and whose `name` is exactly `ScreenPane__FindLayerIndex` | old `data:[],total:0`; desired `total:1` with exactly one `{kind:"name",addr,name}` row whose `addr` is numerically `0x556d20` and whose `name` is exactly `ScreenPane__DetachLayerFrame` |

### DR01 target pure-rename preflight

Literal request: `rename({"database":DB,"batch":{"func":[{"addr":"0x00559360","name":"ScreenPane__FindLayerIndex"}],"dry_run":true,"pure":true,"allow_overwrite":false,"stop_on_error":true}})`.

The decoded rename payload must contain exactly the `func` and `summary` members; foreign `data`, `global_alias`, `local`, `stack`, other row collections, and every unlisted top-level member are forbidden. Require exactly one `func[]` row. Its mandatory fields are semantically exact `addr:"0x00559360"`, `old:"sub_559360"`, `name:"ScreenPane__FindLayerIndex"`, and `dry_run:true`. The only optional row fields are string `error` and `dir_error`, each physically absent or exactly empty string `""`; present null or any nonempty value fails closed. `dir`, `func_addr`, `new`, `allow_overwrite`, `stopped`, and every other unlisted row member must be physically absent. Summary mandatory fields are exactly `total:1`, `ok:1`, `failed:0`, and `dry_run:true`; its only optional fields are `stop_on_error` absent-or-true and `allow_overwrite`/`stopped` absent-or-false. `stopped_at` and every other unlisted summary member must be absent. DR01 must leave every B00 function/item/frame/comment/xref state and all four independent names-registry envelopes at exact zero `data:[],total:0`; the shared three-member present-row rule remains mandatory for every later nonzero state.

### A01 target pure rename

Literal request: `rename({"database":DB,"batch":{"func":[{"addr":"0x00559360","name":"ScreenPane__FindLayerIndex"}],"pure":true,"allow_overwrite":false,"stop_on_error":true}})`.

Apply the same exact decoded top-level and no-foreign-collection contract as DR01. Require one `func[]` row whose mandatory fields are semantically exact `addr:"0x00559360"`, `old:"sub_559360"`, and `name:"ScreenPane__FindLayerIndex"`; optional `dry_run` may be absent or false, and optional string `error`/`dir_error` may each be absent or exactly `""`. `dir`, `func_addr`, `new`, `allow_overwrite`, `stopped`, and every unlisted row member must be absent. Summary mandatory fields are exactly `total:1`, `ok:1`, and `failed:0`; its only optional fields are `dry_run`/`allow_overwrite`/`stopped` absent-or-false and `stop_on_error` absent-or-true. `stopped_at` and every unlisted summary member must be absent. Request-side `stop_on_error:true` and `allow_overwrite:false` remain mandatory even when their optional response fields are absent.

Immediate persisted poststate is mandatory and singular: name becomes `ScreenPane__FindLayerIndex`, while prototype remains exact generic `int __thiscall(_DWORD *this, int)`; the complete three-row frame, four blank comments, bytes, metrics, xrefs, and P02-P08 protections remain exact. Any richer immediate type is unexpected drift and hard-stops; no rename-induced promotion premise is allowed.

Post-A01 independent registry readback must preserve both old-name zero states and detach desired-name zero state as exact `data:[],total:0`, while target desired-name state becomes `total:1` with exactly one `{kind:"name",addr,name}` row whose `addr` is numerically equal to `0x559360` and whose `name` is exactly `ScreenPane__FindLayerIndex`, with no other row, row member, or continuation.

### A02 target function type

Literal request: `set_type({"database":DB,"edits":[{"addr":"0x00559360","kind":"function","signature":"int __thiscall ScreenPane__FindLayerIndex(ScreenPane *this, const Layer *layer)"}]})`. The decoded payload must contain only `result`, which must contain exactly one row. That row must contain mandatory `edit`, `kind:"function"`, and `ok:true`, plus only optional string `error` physically absent or exactly `""`; present null, nonempty error, or any unlisted row/top-level member fails closed. Mandatory `edit` must echo exactly and only semantically exact `addr:"0x00559360"`, `kind:"function"`, and the literal requested `signature`; a missing, partial, substituted, or extended edit echo fails closed. Then call `force_recompile({"database":DB,"items":[{"addr":"0x00559360"}]})` and perform full readback.

| Frame row | A01 prestate | A02 required poststate | Permitted delta |
| --- | --- | --- | --- |
| saved registers | `__saved_registers +0x0c/4 _DWORD` | exact same | None. |
| return address | `__return_address +0x10/4 _UNKNOWN *` | exact same | None. |
| explicit argument | `arg_0 +0x14/4 _DWORD` | `layer +0x14/4 const Layer *` | Name/type only; offset/width preserved. |

Required public prototype is exactly `int __thiscall(ScreenPane *this, const Layer *layer)` in profile/inspect normalization. Formal source trailing member-const is not represented in this explicit-receiver analysis type. Name, comments, bytes, metrics, callers, and all protections remain exact.

### A03 target regular function comment

Literal request: `set_function_comments({"database":DB,"items":[{"addr":"0x00559360","comment":"ScreenPane private layer lookup; returns the first m_rootLayerList index whose stored Layer pointer equals layer, or -1 when absent."}]})`. The decoded response must contain exactly one top-level member, `result`, whose value is an array containing exactly one row. That row has mandatory string `addr`, which must parse to numeric target `0x559360`, and its only optional member is string `error`, physically absent or exactly empty string `""`; present null, a nonempty string, or a non-string fails closed. The row must contain exactly the allowed `{addr,error?}` schema: any additional member, including a separate resolved-function-address member, fails closed. Any missing/non-string/mismatched `addr`, unlisted top-level member, extra row, non-array result, or malformed response fails closed. The complete `get_comments` postread must then return exactly the requested function-regular comment while function-repeatable, address-regular, and address-repeatable remain absent. All non-comment protections and all other cumulative state remain exact at A02.

### A04-F SetLayerFrame function type

Literal request: `set_type({"database":DB,"edits":[{"addr":"0x00556ce0","kind":"function","signature":"void __thiscall ScreenPane_SetLayerFrame(ScreenPane *this, Layer *layer, const Layer *beforeLayer)"}]})`. Apply the identical A02 exact one-row `set_type.result` contract: mandatory `kind:"function"`, `ok:true`, and exact three-member `edit` echo for address/kind/this literal signature; optional string `error` is absent or exactly `""`; all unlisted fields fail closed. Then `force_recompile({"database":DB,"items":[{"addr":"0x00556ce0"}]})`.

The failed no-save transaction proves that this function action changes the public prototype but does not deterministically rename or retype the occupied fourth physical row. Its immediate complete readback is therefore:

| Frame row | A03 prestate | A04-F required poststate | Permitted delta |
| --- | --- | --- | --- |
| saved registers | `__saved_registers +0x04/4 _DWORD` | exact same | None. |
| return address | `__return_address +0x08/4 _UNKNOWN *` | exact same | None. |
| argument 1 | `layer +0x0c/4 Layer *` | exact same | None. |
| argument 2 | `layerContext +0x10/4 int` | exact same | None at this stage. |

Required prototype is `void __thiscall(ScreenPane *this, Layer *layer, const Layer *beforeLayer)`. Name `ScreenPane_SetLayerFrame`, comments, body hash, ten xrefs, and every other protection remain exact. A04-F hard-stops if the fourth row changes at all, if another row changes, or if the public prototype is not exact; the desired physical row is produced only by DR04/A04-R/A04-T below.

### DR04 SetLayerFrame physical stack-rename preflight

Literal request: `rename({"database":DB,"batch":{"stack":[{"func_addr":"0x00556ce0","old":"layerContext","new":"beforeLayer"}],"dry_run":true,"allow_overwrite":false,"stop_on_error":true}})`. The request deliberately omits `pure`; the public endpoint rejects pure mode for stack/local rows. The decoded response must contain exactly `stack` and `summary`, with every foreign row collection and unlisted top-level member forbidden. Require exactly one `stack[]` row whose mandatory fields are semantically exact `func_addr:"0x00556ce0"`, `old:"layerContext"`, `new:"beforeLayer"`, and `dry_run:true`. Its only optional fields are string `error` and `dir_error`, each physically absent or exactly `""`; present null or any nonempty/non-string value fails closed. `addr`, `dir`, `name`, and every unlisted row member must be absent. Summary mandatory fields are exactly `total:1`, `ok:1`, `failed:0`, and `dry_run:true`; its only optional fields are `stop_on_error` absent-or-true and `allow_overwrite`/`stopped` absent-or-false. `stopped_at` and every unlisted summary member must be absent.

DR04 must leave the A04-F prototype and complete frame byte-for-byte unchanged: `__saved_registers +0x04/4 _DWORD`, `__return_address +0x08/4 _UNKNOWN *`, `layer +0x0c/4 Layer *`, `layerContext +0x10/4 int`. Require `layerContext` unique and `beforeLayer` absent before the request, the same state after it, exact cumulative comments/body/range/metrics/xrefs, all four registries, and all P01-P08 protections. Any dry-run delta, collision, partial/error row, summary mismatch, or protected-state drift hard-stops before A04-R and save.

### A04-R SetLayerFrame physical stack rename

Literal request: `rename({"database":DB,"batch":{"stack":[{"func_addr":"0x00556ce0","old":"layerContext","new":"beforeLayer"}],"dry_run":false,"allow_overwrite":false,"stop_on_error":true}})`. Apply the same exact top-level and no-foreign-collection contract as DR04. Require one `stack[]` row with mandatory exact `func_addr:"0x00556ce0"`, `old:"layerContext"`, and `new:"beforeLayer"`; optional `dry_run` may be absent or false, and optional string `error`/`dir_error` may each be absent or exactly `""`. `addr`, `dir`, `name`, and every unlisted row member must be absent. Summary mandatory fields are exactly `total:1`, `ok:1`, and `failed:0`; its only optional fields are `dry_run`/`allow_overwrite`/`stopped` absent-or-false and `stop_on_error` absent-or-true. `stopped_at` and every unlisted summary member must be absent. Request-side `stop_on_error:true` and `allow_overwrite:false` remain mandatory.

Immediate complete frame must be exactly `__saved_registers +0x04/4 _DWORD`, `__return_address +0x08/4 _UNKNOWN *`, `layer +0x0c/4 Layer *`, and `beforeLayer +0x10/4 int`. The sole permitted delta is physical row name `layerContext` to `beforeLayer`; its offset, width, and `int` type remain exact. The public function prototype remains the A04-F prototype. Any type change, row addition/removal/reorder, partial rename, old-name survival, or other protected delta hard-stops before A04-T and save.

### A04-T SetLayerFrame occupied stack type

Literal request: `set_type({"database":DB,"edits":[{"addr":"0x00556ce0","kind":"stack","name":"beforeLayer","variable":"beforeLayer","ty":"const Layer *"}]})`. Public `set_type` exposes no dry-run member, so no unsupported type preflight is invented. The decoded payload must contain only `result`, which must contain exactly one row. That row must contain mandatory `edit`, `kind:"stack"`, and `ok:true`, plus only optional string `error` physically absent or exactly `""`; present null, nonempty/non-string error, or any unlisted row/top-level member fails closed. Mandatory `edit` must echo exactly and only the five requested members and values: `addr:"0x00556ce0"`, `kind:"stack"`, `name:"beforeLayer"`, `variable:"beforeLayer"`, and `ty:"const Layer *"`.

Immediate complete frame must be exactly `__saved_registers +0x04/4 _DWORD`, `__return_address +0x08/4 _UNKNOWN *`, `layer +0x0c/4 Layer *`, and `beforeLayer +0x10/4 const Layer *`. The sole permitted A04-R-to-A04-T delta is that occupied row's type `int` to `const Layer *`; name, offset, width, every other row, public function prototype, function identity, comments, body/range/hash, metrics, ten xrefs, registries, and all protections remain exact. Then call the second `force_recompile({"database":DB,"items":[{"addr":"0x00556ce0"}]})` and repeat the complete profile/item/frame/comment/body/metric/xref/registry/protection readback. Any receipt, immediate frame, cache-refreshed frame, or protected-state mismatch hard-stops before DR02 and save. `declare_stack` is forbidden because the row is occupied, and `delete_stack`, compensating edits, generic-or-richer alternatives, and deferred discovery are not permitted.

### DR02 detach pure-rename preflight

Literal request: `rename({"database":DB,"batch":{"func":[{"addr":"0x00556d20","name":"ScreenPane__DetachLayerFrame"}],"dry_run":true,"pure":true,"allow_overwrite":false,"stop_on_error":true}})`. Apply the identical DR01 closed top-level/`func[]`/summary response contract with mandatory `old:"sub_556D20"`, `name:"ScreenPane__DetachLayerFrame"`, semantically exact address `0x00556d20`, and `dry_run:true`; `func_addr`, `new`, foreign row collections, and all other unlisted fields remain forbidden. Require complete unchanged A04-T cumulative state, independent detach old/desired registry envelopes at exact zero `data:[],total:0`, and unchanged target desired-name `total:1` state with exactly one `{kind:"name",addr,name}` row whose address is numerically `0x559360` and whose name is exactly `ScreenPane__FindLayerIndex`.

### A05 detach pure rename

Literal request: `rename({"database":DB,"batch":{"func":[{"addr":"0x00556d20","name":"ScreenPane__DetachLayerFrame"}],"pure":true,"allow_overwrite":false,"stop_on_error":true}})`. Apply the identical A01 closed persistent top-level/`func[]`/summary response contract with mandatory `old:"sub_556D20"`, `name:"ScreenPane__DetachLayerFrame"`, and semantically exact address `0x00556d20`; optional-false fields retain their A01 rules, while `func_addr`, `new`, foreign row collections, and all unlisted fields remain forbidden.

Immediate persisted poststate is mandatory: name `ScreenPane__DetachLayerFrame`, prototype still exact generic `int __thiscall(int this, int)`, unchanged three-row frame, blank comments, body, metrics, xrefs, and all protections. Any richer immediate type hard-stops.

Post-A05 independent registry readback must keep both old-name states at exact zero `data:[],total:0`; target desired-name state remains exactly one `{kind:"name",addr,name}` row with address numerically `0x559360` and exact name `ScreenPane__FindLayerIndex`, and detach desired-name state becomes exactly one `{kind:"name",addr,name}` row with address numerically `0x556d20` and exact name `ScreenPane__DetachLayerFrame`, each under its own `total:1` envelope with no duplicate, extra member, or continuation.

### A06 detach function type

Literal request: `set_type({"database":DB,"edits":[{"addr":"0x00556d20","kind":"function","signature":"void __thiscall ScreenPane__DetachLayerFrame(ScreenPane *this, Layer *layer)"}]})`. Apply the identical A02 exact one-row `set_type.result` contract: mandatory `kind:"function"`, `ok:true`, and exact three-member `edit` echo for address/kind/this literal signature; optional string `error` is absent or exactly `""`; all unlisted fields fail closed. Then `force_recompile({"database":DB,"items":[{"addr":"0x00556d20"}]})`.

| Frame row | A05 prestate | A06 required poststate | Permitted delta |
| --- | --- | --- | --- |
| saved registers | `__saved_registers +0x04/4 _DWORD` | exact same | None. |
| return address | `__return_address +0x08/4 _UNKNOWN *` | exact same | None. |
| explicit argument | `arg_0 +0x0c/4 _DWORD` | `layer +0x0c/4 Layer *` | Name/type only; offset/width preserved. |

Required prototype is `void __thiscall(ScreenPane *this, Layer *layer)`. Body hash, ten xrefs, blank comments, metrics, and all protections remain exact.

### Literal protection entities

| Protection | Exact invariant outside explicitly staged cumulative changes |
| --- | --- |
| P01 target function | Exact `[0x00559360,0x005593a2)`, size 0x42, SHA256 `9D18D37863AD595447A9D4BE4ED51B0B581C06DC941657452F2895D11B45B517`, 33 instructions, five blocks, xrefs `0x00556cf9/0x00556d29`, complete frame/comments; only A01 name, A02 type/frame argument metadata, and A03 function-regular comment may change. |
| P02 target predecessor padding | One data item `[0x00559359,0x00559360)`, unnamed/untyped, blank comments, seven `cc` bytes, SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`, zero xrefs. |
| P03 target successor padding | One data item `[0x005593a2,0x005593b0)`, unnamed/untyped, blank comments, fourteen `cc` bytes, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, zero xrefs. |
| P04 raw successor | Raw code `[0x005593b0,0x0055940c)`, no function at start, blank comments, 92-byte SHA256 `4EE9B5D73EFF5D1AB5F4063E21EED4ED23A5BA9AA5C1876A306A4CA1B0E9B6D9`, zero incoming start xrefs. |
| P05 SetLayerFrame | Exact `[0x00556ce0,0x00556d1b)`, 59-byte SHA256 `077953A582CDB9430AF2B7FB03882E7220FEB0BF7721105B140B5D71358A0B67`, 24 instructions, four blocks, name/comments/frame, and exact xrefs `0x004f6331/0x004f6340/0x004f634f/0x004f635e/0x004f636d/0x004f637c/0x0050f349/0x00512748/0x00546c04/0x00546cb5`; only A04-F may change the public function type, A04-R may change fourth-row name `layerContext` to `beforeLayer`, and A04-T may change that row type `int` to `const Layer *`. DR04 and both cache invalidations are no-mutation/no-extra-delta phases. |
| P06 Set/Detach padding | One data item `[0x00556d1b,0x00556d20)`, unnamed/untyped, blank comments, five `cc` bytes, SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`, zero xrefs. |
| P07 DetachLayerFrame | Exact `[0x00556d20,0x00556d41)`, 33-byte SHA256 `2B037E3C214AEE930888F6DAF3C9A6359833C4EFAF744AF56A53DDCA6BCDF47C`, 14 instructions, one block, frame/comments, and exact xrefs `0x004f64cc/0x004f64dd/0x004f64ee/0x004f64ff/0x004f6510/0x004f6521/0x005045bb/0x0050489c/0x005108aa/0x00546db3`; only A05 name and A06 type/argument metadata may change. |
| P08 Detach successor padding | One data item `[0x00556d41,0x00556d50)`, unnamed/untyped, blank comments, fifteen `cc` bytes, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`, zero xrefs. |

Evaluate P01-P08 independently at B00, post-DR01, post-A01, post-A02, post-A03, post-A04-F, post-DR04, post-A04-R, post-A04-T, post-DR02, post-A05, post-A06, pre-save S00, and fresh-reopen R00: exactly 112 evaluations. Every action phase must also repeat exact registries. No grouped protection response is accepted.

### Save/reopen hard stops

Do not save after any failed/ambiguous action or readback. Exact order is DR01, A01, A02, A03, A04-F, DR04, A04-R, A04-T, DR02, A05, A06, then S00; no later action may compensate for an earlier mismatch. After A06, S00 must match the complete cumulative state and all 104 scheduled B00-through-S00 protection evaluations. The supervisor then uses the one authorized isolated save from its current guarded procedure, obtains physical saved-copy receipts, closes the worker, and freshly reopens/verifies the saved transaction with `run_auto_analysis:false`. R00 supplies the final eight evaluations, for 112 total, and must reproduce names, exact prototypes, complete frames, comment channels, registries, bytes, items, metrics, and xrefs. Any mismatch triggers the supervisor's guarded rollback/classification procedure; no generic-or-richer, absent-or-present, compensating, or deferred-discovery alternative is permitted.

## First-Draft C++ Recommendation

### UID0003A1 target CPP formal insertion

```cpp
int ScreenPane::FindLayerIndex(const Layer *layer) const
{
    const int layerCount = m_rootLayerList->GetCount();
    for (int index = 0; index < layerCount; ++index) {
        Layer *entry = *static_cast<Layer **>(
            m_rootLayerList->GetElementAt(index));
        if (entry == layer)
            return index;
    }

    return -1;
}
```

UID0003A1 target H formal insertion is the empty byte sequence. Leave the existing H channel exactly blank because UID0000CB owns the complete declaration.

### UID0000CB class CPP formal insertion

Insert these definitions before the existing `OnFrameUpdate` definition:

```cpp
void ScreenPane::SetLayerFrame(Layer *layer, const Layer *beforeLayer)
{
    int layerIndex;
    if (beforeLayer != 0)
        layerIndex = FindLayerIndex(beforeLayer);
    else
        layerIndex = m_rootLayerList->GetCount();

    m_rootLayerList->InsertAt(layerIndex, 1, &layer);
}

void ScreenPane::DetachLayerFrame(Layer *layer)
{
    m_rootLayerList->RemoveAt(FindLayerIndex(layer), 1);
}
```

### UID0000CB class H formal replacement

Replace the two current public declarations and add the private declaration at the shown access locations:

```cpp
public:
    void SetLayerFrame(Layer *layer, const Layer *beforeLayer);
    void DetachLayerFrame(Layer *layer);

private:
    int FindLayerIndex(const Layer *layer) const;
```

Preserve every unrelated declaration, field, include, inheritance edge, and the existing private `BlitSurfaceToDisplay` declaration.

### UID0003A3 traversal CPP formal replacement

Keep the complete method unchanged except for the three exact slot dereferences below:

```cpp
void ScreenPane::TraversePresentationList(Region *dirtyRegion)
{
    Region layerDirty;
    Region currentMotion;

    GetCurrentMotionRegion(&currentMotion);
    SubtractMotionFromDirtyRegion(&currentMotion);

    const int layerCount = m_rootLayerList->GetCount();
    const int lastLayer = layerCount - 1;

    for (int index = lastLayer; index >= 0; --index) {
        Layer *layer = *static_cast<Layer **>(
            m_rootLayerList->GetElementAt(index));
        layer->ClearDirtyRegion();
        layer->CollectDirtyRegion(&layerDirty, &currentMotion);
        dirtyRegion->UnionWith(layerDirty);
    }

    void *savedSurface = m_grafPort.m_surface;
    m_grafPort.m_surface = m_renderSurface;

    Point origin;
    InitPointPair(&origin, 0, 0);

    for (int index = 0; index < layerCount; ++index) {
        Layer *layer = *static_cast<Layer **>(
            m_rootLayerList->GetElementAt(index));

        if (index < lastLayer) {
            Layer *nextLayer = *static_cast<Layer **>(
                m_rootLayerList->GetElementAt(index + 1));
            layer->CopyDirtyRegion(&layerDirty);
            nextLayer->UnionDirtyRegion(&layerDirty);
        }

        layer->PropagateDirtyRegion();
        if (layer->RenderRecursive(
                &m_grafPort, origin.x, origin.y, &layerDirty, NULL)) {
            m_presentationDirty = true;
        }
        layer->EndRender();
    }

    m_grafPort.m_surface = savedSurface;

    if (m_hasPendingDirtyRegion) {
        m_presentationDirty = true;
        dirtyRegion->UnionWithRect(&m_pendingDirtyRegion);
        m_hasPendingDirtyRegion = false;
        InitRectBounds(&m_pendingDirtyRegion, 0, 0, 0, 0);
    }
}
```

UID0003A3 H remains blank under its existing class-owned declaration route.

## Final Recommendation

The accepted B006 callback has completed and independently verified CKF-001 through CKF-035. The resulting source remains deterministic: no raw labels enter formal C++, no compiler artifact is hand-authored, no list slot is miscast, no helper return is invented, and no range/padding/data ownership changes occurred. CKF-028's unconditional UID0003A1 predecessor cross-reference is now present; Section 21 independently separates registered-name envelopes from function/item evidence, requires mandatory `kind:"name"` plus exact numeric address and desired name in every present data row, and closes every supervisor-owned rename/set-type response member. The SetLayerFrame handoff now follows the proven deterministic chain `A04-F -> DR04 -> A04-R -> A04-T`: function type, no-mutation stack preflight, name-only occupied-row rename, then occupied-row type, with exact intermediate and final complete frames.

The prior Gate 1 authorized only this completed ordinary-document callback. It does not authorize IDA, coverage, or lifecycle work. CKF-036 through CKF-051 remain unchecked and supervisor-owned; fresh Gate 1 and Gate 2 are required for this exact post-callback artifact.

## Recommended Target Doc Changes

1. Implemented target completion/confidence `90/92`, canonical owner/emitter `0000CB`, reconstructable true, and blank emitter position.
2. Populated target CPP exactly from Section 22 and kept H physically blank.
3. Replaced Item Summary with: `Exact private ScreenPane::FindLayerIndex source method over m_rootLayerList; dereferences four-byte Layer pointer slots returned by List::GetElementAt, returns the first matching signed index or -1, has two direct ScreenPane mutation-helper callers, preserves exact 0x42 body and neighboring alignment, and emits through class UID0000CB into ScreenPane.cpp.`
4. Replaced stale status/behavior/IDA/ownership/gate prose with complete current evidence, source access/type/edge behavior, List construction/access, boundaries, rejected alternatives, compiler disposition, and current support links.
5. Added the current implementation, validator, lease, and generated receipts below.

## Recommended Support Doc Changes

| Destination | Exact bounded change |
| --- | --- |
| `by-class/ScreenPane.md` | Apply Section 22 helper definitions/declarations/private lookup; add exact List/caller/edge evidence; preserve all unrelated source and 93/94. |
| `by-file/ScreenPane.md` | Add UID0003A1 inventory/source route; correct helper signatures and traversal slot semantics; preserve 93/94 and all unrelated items. |
| `by-memory/0x00556910-0x00557132.ScreenPane.md` | Correct active helper rows/prose; explicitly retain 91/93 non-emitting blank aggregate. |
| `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` | Apply exactly three slot dereferences and current prose; preserve behavior/order/90/92. |
| `by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md` | Verify exact predecessor boundary; no semantic edit. |
| `by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md` | Preserve the raw helper and insert the accepted-prestate-absent UID0003A1 predecessor link under `Cross-References`: `- [UID:0003A1][0x00559360-0x005593a2.ScreenPaneLayerIndexLookup](by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md)`. Its scoped owning validator and physical reread are complete. |
| Manual coverage reports | Supervisor applies exact Section 28 insertion/replacements only. |

All ordinary support rows above were completed exactly during the accepted callback except the supervisor-owned manual coverage row. No support child creation, file rename, global/type/resource page, manual coverage/generated edit, or broad aggregate emission occurred.

## Score And Metadata Recommendation

| UID | Accepted pre-callback | Implemented current | Rationale |
| --- | --- | --- | --- |
| 0003A1 | 85/88; owner/emitter 0000NB | 90/92; owner/emitter 0000CB | Exact range/body/behavior/List contract/callers/source are closed; original private spelling remains inferred. |
| 0000CB | 93/94 | Unchanged 93/94 | Correct declarations/bodies close inconsistency but do not warrant parent inflation. |
| 0000NB | 93/94 | Unchanged 93/94 | Physical source route remains complete; bounded inventory update only. |
| 0001G5 | 91/93, non-emitting | Unchanged | Active helper semantics corrected; aggregate architecture unchanged. |
| 0003A3 | 90/92 | Unchanged | Slot-dereference correction fixes formal accuracy without adding new behavior. |
| 0003A0/0003A2 | Existing | Unchanged | Boundary/context only. |

The target confidence does not exceed class/file parents. Exact original symbol spelling and absent debug/source symbols cap 92 confidence; no unresolved runtime behavior remains.

## Open Questions With Attempted Resolution

| Question | Attempt | Resolution |
| --- | --- | --- |
| Original method spelling | Compared current project method names, behavior, caller composition, and UID0003KJ. | Use `FindLayerIndex`; keep spelling inference as score cap. |
| Public/protected/private | Searched all code/data/xrefs and caller ownership. | Private; only two same-class direct callers. |
| Method constness | Reviewed every target instruction for receiver/list mutation. | Formal trailing const accepted; IDA explicit receiver remains mutable analysis representation. |
| Null list handling | Traced constructor/destructor and target entry. | No source guard; constructor invariant matches binary. |
| List element type | Traced `List(4,4)`, GetElementAt slot, target compare, traversal loads, and analog. | Exact stored `Layer *`; dereference `Layer **` storage. |
| SetLayerFrame second argument | Traced branch/call and all caller shapes. | `const Layer *beforeLayer`, null means append. |
| SetLayerFrame physical frame repair | Compared the `2026-08-25T16:18:51Z` failed A04 readback, current complete-frame read, live public schemas, creation-only `declare_stack` implementation evidence, and prior successful occupied-stack rename/type sequence. | Function `set_type` intentionally leaves `layerContext:int`; DR04 proves collision-free no-mutation rename eligibility, A04-R changes only the name to `beforeLayer:int`, and A04-T changes only its type to `const Layer *`. No discovery or alternative endpoint remains. |
| Detach return/index guard | Inspected body and all caller result use. | Source returns void and passes `FindLayerIndex` result unguarded to RemoveAt. |
| Separate child pages for support helpers | Compared non-emitting aggregate and class CPP ownership. | Not required; class UID0000CB can own definitions without changing aggregate architecture. |
| Target-owned data/static | Searched data/immediate xrefs and field lifecycle. | None; all data/types are external class dependencies. |
| UID0003A2 predecessor cross-reference | Physically reread the complete pre-callback and post-callback UID0003A2 `Cross-References` blocks and searched for UID0003A1/range/title. | Link was absent at accepted prestate; CKF-028 inserted the literal UID0003A1 row, and post-validator physical reread confirms it exactly once while preserving the raw helper. |

No source implementation blocker remains. The former SetLayerFrame Gate 2B frame-contract blocker is closed by the exact four-stage sequence in Section 21; persistent success remains unclaimed until a wholly fresh supervisor Gate 2B executes and verifies it.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Supervisor-only manual coverage changes after accepted ordinary implementation:

Insert after UID0003A0 and before UID0003A3 in `by-memory/-coverage-report.md`:

`        - [UID:0003A1][0x00559360-0x005593a2.ScreenPaneLayerIndexLookup](by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md) 0x00559360-0x005593a2 | private method | ScreenPane::FindLayerIndex : reconstructable : 90% : very-strong : Exact private const ScreenPane Layer-pointer first-match lookup over m_rootLayerList, List(4,4) element-slot dereference, signed index-or--1 contract, two direct ScreenPane helper callers, exact 0x42/33-instruction/5-block body and neighboring 7/14-byte alignment, class UID0000CB ownership/emission through ScreenPane.cpp, formal C++03 source, and no compiler-helper or standalone-data route.`

Replace the current UID0000CB row in `by-class/-coverage-report.md` with:

`- [UID:0000CB][ScreenPane](by-class/ScreenPane.md) : reconstructable : 93% : very-strong : Root Pane/FrameHandler/Singleton<ScreenPane> controller retaining canonical singleton lifecycle and complete 0x5b4 layout; exact public SetLayerFrame(Layer *, const Layer *) and DetachLayerFrame(Layer *) mutation helpers plus private const FindLayerIndex over List(4,4) Layer-pointer storage; exact cursor, DirectDraw, browser, fade, presentation, screenshot, destructor, vtable, compiler/source, and generated-output contracts; UID0003A1 emits the signed first-match index-or--1 body through this class, and UID0003A3 dereferences all List element-storage slots before Layer use, with all unrelated accepted source and ownership preserved.`

Replace the current UID0000NB row in `by-file/-coverage-report.md` with:

`- [UID:0000NB][ScreenPane](by-file/ScreenPane.md) : reconstructable : 93% : very-strong : NexusTK/ui/core ScreenPane source root retaining canonical singleton, complete 0x5b4 class/layout, exact SetLayerFrame/DetachLayerFrame/FindLayerIndex root-layer List contracts, layer/presentation/cursor state, source-ready method children, compiler/source exclusions, and generated-output constraints; UID0003A1 emits exact private first-match Layer-pointer lookup with signed -1 miss, UID0003A3 uses exact List element-slot dereferences, and existing DirectDraw/GDI/fade/screenshot/browser/destructor/vtable routes remain unchanged.`

Do not manually edit `auto-generated/-ag-research-tracker.md` or generated coverage. Validator/lifecycle ownership must refresh those dynamically.

## Follow-Up Actions

1. Supervisor performs fresh exact-artifact Gate 1 over this post-callback report and current destinations.
2. Supervisor performs fresh Gate 2A over current docs/source, all six validator receipts, and physical generated outputs.
3. Supervisor applies CKF-036 through CKF-038 manual coverage changes only after validating the exact current rows.
4. Supervisor restarts wholly fresh at B00 and performs exact order DR01/A01/A02/A03/A04-F/DR04/A04-R/A04-T/DR02/A05/A06 under the isolated Gate 2B procedure, including the repaired three-member present-row registry contract, 56 registry reads, 112 independent P01-P08 evaluations, both SetLayerFrame complete-frame intermediates, and sole save/fresh reopen only if every gate passes.
5. Supervisor alone performs lifecycle execution after all gates pass.

## Confidence

Recommendation confidence is `very strong` at 92. Range, bytes, List layout, field, callers, behavior, edge cases, source placement, and compiler disposition are exact. The two-point cap reflects inferred original private spelling and the C-style IDA representation of trailing member constness, neither of which blocks faithful source.

## Validator Results

No validator ran during report-only research. During the accepted callback, exactly the six planned scoped commands ran from `source-3/project-documentation`; each exited 0 with `ok:1`:

- `000000028156`, `2026-08-25T10:08:42-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md --apply --queue-timeout 240`; generated refresh deferred.
- `000000028157`, `2026-08-25T10:09:51-04:00`: `python .\tools\validator.py --mode file --file by-class/ScreenPane.md --apply --queue-timeout 240`; generated refresh deferred.
- `000000028159`, `2026-08-25T10:11:15-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x00556910-0x00557132.ScreenPane.md --apply --queue-timeout 240`; generated refresh deferred.
- `000000028160`, `2026-08-25T10:11:58-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md --apply --queue-timeout 240`; generated refresh deferred.
- `000000028162`, `2026-08-25T10:13:56-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md --apply --queue-timeout 240`; generated refresh deferred.
- `000000028163`, `2026-08-25T10:16:06-04:00`: `python .\tools\validator.py --mode file --file by-file/ScreenPane.md --apply --queue-timeout 240 --wait-generated`; generated refresh completed.

Physical post-refresh receipt: `auto-generated/NexusTK/ui/core/ScreenPane.cpp` is SHA256 `090483AF77D2D00E0ACB0CDF484B8649A6C13E1215E4A51054034A2EF7A272CF`, 25308 bytes, UTC mtime `2026-08-25T14:16:25.6095646Z`; `ScreenPane.h` is SHA256 `8CCDF67326D7D239A5D2CBDA2666EFE664004918D8B3B2E0BB887AC410CED91F`, 3745 bytes, UTC mtime `2026-08-25T14:16:25.6445652Z`. CPP has exactly one each of `SetLayerFrame`, `DetachLayerFrame`, `FindLayerIndex`, and `TraversePresentationList`; lines 11/22 precede `OnFrameUpdate` line 27, and UID0003A0 `BeginFadeIn`/`BeginFadeOut` lines 488/502 precede UID0003A1 line 517, file-static UID0003A2 line 690, and UID0003A3 line 712. CPP has four total `*static_cast<Layer **>` expressions, exactly one in the target plus all three traversal accesses, and zero direct `static_cast<Layer *>` expressions. H has exactly one corrected public declaration for each helper and exactly one private `FindLayerIndex` declaration. UID0003A1 has exactly one generated source block/body and zero UID0003A1 Empty Emitter Markers; two unrelated pre-existing markers for UID00039P and UID00039U remain outside this accepted callback. No target duplicate, target empty marker, raw target IDA label, invented guard, or accepted direct-storage cast is present.

## Changed Files

Current callback changed ordinary documentation:

- `by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md`: exact target implementation and evidence; SHA/bytes/mtime in the current table above.
- `by-class/ScreenPane.md`: exact class CPP/H and support evidence.
- `by-file/ScreenPane.md`: exact file inventory/source-route and slot-semantics support.
- `by-memory/0x00556910-0x00557132.ScreenPane.md`: exact active helper inventory/caller correction, with non-emitting architecture preserved.
- `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md`: exactly three formal pointer-slot dereferences and current semantics.
- `by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md`: one exact UID0003A1 predecessor cross-reference only.
- `tools/leaser/Agents/Agent-B006/research/0003A1-ScreenPaneLayerIndexLookup-source-quality.md`: current callback receipts and checked B006 allocation.

This additive report-only repair also records the `2026-08-25T16:18:51Z` no-save A04 failure, current read-only public frame/schema evidence, the deterministic occupied-row rename/type sequence, and reconciled action/phase/protection mechanics. It changes no ordinary/generated/coverage/tracker/audit/goal/lifecycle/IDA artifact and invokes no validator, `execute_report`, mutation, save, or process operation.

Read-only unchanged support verification: `by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md` remains SHA256 `AADCAADD8144045636EF132BC87357A0A0A6142BA0CEA7BCBA693B887244CA26`, 18584 bytes, with exact end `0x00559359` and following seven-byte padding. Each ordinary destination was leased only for its immediate edit/validator/reread batch and explicitly released with `Success`; the predecessor needed no lease. Validator-owned generated/registry/stats side effects were not edited directly. No manual coverage, tracker, audit, goal/notes, lifecycle, IDB, MCP, process, another report, or generated file was edited; no `execute_report`, lifecycle, IDA mutation/save/manage/start/stop, or process action ran. The first short report lease expired during final mechanics; its explicit unlease returned `Rejected[No active lease]`. A final short report lease was then acquired only for this exact receipt correction and released immediately after editing; physical `current_leases.md` reread must show zero B006 leases.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | CKF-001 | 0003A1 | Preserve exact target range 0x00559360-0x005593a2, 66-byte body SHA256 9D18D37863AD595447A9D4BE4ED51B0B581C06DC941657452F2895D11B45B517, 33 instructions, and five blocks. | exact | Live disasm, bytes, func_profile. | Target Status, Address Range, IDA Evidence. | incorporate | callback-verified |
| [x] | CKF-002 | 0003A1 | Record dated IDA name sub_559360, generic prototype, complete three-row frame, and four absent comment channels as prestate. | exact | Live func_profile, disasm, get_comments. | Target IDA MCP Evidence. | incorporate | callback-verified |
| [x] | CKF-003 | 0003A1 | Record exactly two incoming code xrefs at 0x00556cf9 and 0x00556d29 and no data/immediate/pointer-table route. | exact | Live xref_query and byte-pattern searches. | Target callers/xrefs. | incorporate | callback-verified |
| [x] | CKF-004 | 0003A1 | Preserve seven-byte predecessor padding, fourteen-byte successor padding, and raw 92-byte successor beginning 0x005593b0 as separate exact items. | exact | inspect_items, bytes, hashes, zero boundary xrefs. | Target range/boundary analysis. | incorporate | callback-verified |
| [x] | CKF-005 | 0003A1 | Record ScreenPane constructor allocation of List(4,4) at m_rootLayerList +0x10c and destructor ownership/lifetime. | very strong | Constructor/decompile, class layout, destructor docs. | Target behavior and ownership. | incorporate | callback-verified |
| [x] | CKF-006 | 0003A1 | Model List GetElementAt as returning four-byte element storage that must be dereferenced to obtain Layer *. | exact | cmp [eax],ecx, List slot +0x10, UID0003KJ analog. | Target behavior/source notes. | incorporate | callback-verified |
| [x] | CKF-007 | 0003A1 | Preserve count snapshot, signed empty/miss -1, first-match return, duplicate-first behavior, null search-pointer comparability, and no null-list guard. | exact | Target control flow and constructor invariant. | Target Behavior. | incorporate | callback-verified |
| [x] | CKF-008 | 0003A1 | Use private source signature int ScreenPane::FindLayerIndex(const Layer *layer) const; retain original spelling as a score cap only. | very strong | Caller scope, source convention, no mutation. | Target status/signature/access. | incorporate | callback-verified |
| [x] | CKF-009 | 0003A1 | Change direct semantic owner/emitter from UID0000NB to class UID0000CB while retaining ScreenPane.cpp file route through UID0000NB. | very strong | Class method semantics and project class-child convention. | Target metadata/ownership. | incorporate | callback-verified |
| [x] | CKF-010 | 0003A1 | Classify target as ordinary handwritten source and reject compiler thunk, raw helper, and standalone file routes. | exact | Ordinary function shape, callers, behavior. | Target compiler/source disposition. | incorporate | callback-verified |
| [x] | CKF-011 | 0003A1 | Populate target CPP with the exact FindLayerIndex body in Section 22. | very strong | Complete source reconstruction. | Target RECONSTRUCTION_CPP. | incorporate | callback-verified |
| [x] | CKF-012 | 0003A1 | Keep target H exactly blank because owning class H carries the private declaration. | exact | Existing child/header convention. | Target RECONSTRUCTION_H. | incorporate | callback-verified |
| [x] | CKF-013 | 0003A1 | Raise target metadata 85/88 to 90/92 and replace Item Summary with exact source/behavior/route wording. | very strong | Closed source/type/range/owner evidence; spelling cap. | Target metadata and Item Summary. | incorporate | callback-verified |
| [x] | CKF-014 | 0003A1 | Replace stale target prose and links with current exact behavior, caller, owner, range, source, edge, and support relationships. | exact | Full report evidence. | Target body/cross-references/Changes. | incorporate | callback-verified |
| [x] | CKF-015 | 0000CB | Replace public SetLayerFrame declaration with void SetLayerFrame(Layer *layer, const Layer *beforeLayer). | exact | Live helper prototype/body and call arguments. | ScreenPane class H. | incorporate | callback-verified |
| [x] | CKF-016 | 0000CB | Replace public int DetachLayerFrame with void DetachLayerFrame(Layer *layer). | exact | Live helper body, ignored return, RemoveAt dispatch. | ScreenPane class H. | incorporate | callback-verified |
| [x] | CKF-017 | 0000CB | Add private int FindLayerIndex(const Layer *layer) const before BlitSurfaceToDisplay. | very strong | Access and source contract. | ScreenPane class H. | incorporate | callback-verified |
| [x] | CKF-018 | 0000CB | Add exact SetLayerFrame definition before existing OnFrameUpdate in class CPP. | exact | 0x00556ce0 branch and InsertAt(index,1,&layer). | ScreenPane class CPP. | incorporate | callback-verified |
| [x] | CKF-019 | 0000CB | Add exact DetachLayerFrame definition before existing OnFrameUpdate in class CPP without an index guard. | exact | 0x00556d20 FindLayerIndex then RemoveAt(index,1). | ScreenPane class CPP. | incorporate | callback-verified |
| [x] | CKF-020 | 0000CB | Add current helper/lookup/List evidence and historicalize stale slot/int/return wording without changing 93/94. | exact | Live support analysis. | ScreenPane class prose/Changes. | incorporate | callback-verified |
| [x] | CKF-021 | 0000NB | Add UID0003A1 to ScreenPane.cpp inventory/source role and describe class-owned child emission. | exact | Accepted prestate file inventory omission and owner route. | ScreenPane file Proposed Contents/evidence. | incorporate | callback-verified |
| [x] | CKF-022 | 0000NB | Correct root helper and traversal List-slot/source-completion prose without changing file 93/94. | exact | Live callers and generated gaps. | ScreenPane file role/evidence/Changes. | incorporate | callback-verified |
| [x] | CKF-023 | 0001G5 | Correct active SetLayerFrame/DetachLayerFrame inventory and caller prose to pointer insertion/removal semantics. | exact | Live helper disassembly. | Broad ScreenPane aggregate inventory/evidence. | incorporate | callback-verified |
| [x] | CKF-024 | 0001G5 | Preserve aggregate 91/93, reconstructable false, blank CPP/H, and non-emitting role; exact child/class routes own source. | exact | Current aggregate architecture. | Broad aggregate status/rationale. | already-present | callback-verified |
| [x] | CKF-025 | 0003A3 | Replace all three direct Layer casts with dereferenced Layer ** slot accesses in formal CPP. | exact | Live traversal disassembly at all three accesses and List contract. | Traversal RECONSTRUCTION_CPP. | incorporate | callback-verified |
| [x] | CKF-026 | 0003A3 | Historicalize active stale direct-cast/no-blocker prose and state exact Layer-pointer slot semantics; preserve 90/92. | exact | Accepted prestate formal source versus binary. | Traversal current state/behavior/Changes. | incorporate | callback-verified |
| [x] | CKF-027 | 0003A0 | Preserve predecessor method pair, exact end 0x00559359, and following seven-byte padding; no semantic edit. | exact | Current doc and live boundary. | Transition page readback. | already-present | callback-verified |
| [x] | CKF-028 | 0003A2 | Preserve raw successor 0x005593b0-0x0055940c and its source route; unconditionally add the exact UID0003A1 predecessor link absent at accepted prestate from Cross-References, then scoped-validate and physically reread the page. | exact | Live raw code item and accepted/current physical Cross-References readbacks. | Raw successor Cross-References/Validator Results. | incorporate/validate/read back | callback-verified |
| [x] | CKF-029 | 0003A1 | State that target owns no file-global/static-data island; m_rootLayerList and Layer/List types are external class dependencies. | exact | No data/immediate xrefs and class field ownership. | Target source placement/negative evidence. | incorporate | callback-verified |
| [x] | CKF-030 | 0003A1 | Run scoped owning validator for the target during accepted callback. | exact | Workflow validator contract. | Validator Results. | incorporate | callback-verified |
| [x] | CKF-031 | 0000CB | Run scoped owning validator for ScreenPane class after CPP/H repair. | exact | Workflow validator contract. | Validator Results. | incorporate | callback-verified |
| [x] | CKF-032 | 0000NB | Run final scoped owning validator for ScreenPane file with documented generated wait. | exact | File owner/generator route. | Validator Results. | incorporate | callback-verified |
| [x] | CKF-033 | 0001G5 | Run scoped owning validator for broad aggregate after prose correction. | exact | Workflow validator contract. | Validator Results. | incorporate | callback-verified |
| [x] | CKF-034 | 0003A3 | Run scoped owning validator for traversal after formal CPP correction. | exact | Workflow validator contract. | Validator Results. | incorporate | callback-verified |
| [x] | CKF-035 | 0003A1 | Physically reread fresh generated ScreenPane.cpp/H, verify exact bodies/declarations/order and no UID0003A1 empty marker or duplicate target body, and add current receipts to report. | exact | Dynamic generated-authority rule. | Validator Results/Changed Files. | incorporate | callback-verified |
| [ ] | CKF-036 | 0003A1 | Insert exact manual by-memory coverage row after UID0003A0 and before UID0003A3. | exact | Current manual coverage omission. | by-memory/-coverage-report.md. | incorporate | proposed |
| [ ] | CKF-037 | 0000CB | Replace exact manual by-class coverage row with current helper/lookup/List wording at unchanged 93. | exact | Current row and support repair. | by-class/-coverage-report.md. | incorporate | proposed |
| [ ] | CKF-038 | 0000NB | Replace exact manual by-file coverage row with target/helper/traversal completeness wording at unchanged 93. | exact | Current row and source route. | by-file/-coverage-report.md. | incorporate | proposed |
| [ ] | CKF-039 | 0003A1 | DR01 perform the literal pure target rename dry run; require the closed `func[]`/summary schema, exact old/name/address echoes, complete unchanged function/item/frame/comment/xref state, and independent old/desired registry `data:[],total:0`; enforce the shared exact `{kind:"name",addr,name}` schema for every later present row. | exact | Current MCP rename/entity_query schemas. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-040 | 0003A1 | A01 perform only the pure target rename under the closed persistent response schema; retain immediate generic type and require the independent target desired-name transition to `total:1` with exactly one `{kind:"name",addr,name}` row at numeric `0x559360` and the exact desired name, while both old-name states and detach desired state remain exact zero states. | exact | Rename/entity_query schemas and no-promotion contract. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-041 | 0003A1 | A02 apply the exact named target function declaration; require one mandatory exact edit echo and the complete three-row post-type frame. | exact | Current set_type schema and frame delta. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-042 | 0003A1 | A03 set only the exact regular function comment; require exactly one top-level `result` member containing exactly one `{addr,error?}` row, mandatory string `addr` numerically equal to `0x559360`, and optional string `error` physically absent or exactly `""`; forbid every other row or top-level member, preserve the complete four-channel `get_comments` postread, and preserve every non-comment protection. | exact | Current set_function_comments schema and exact target response contract. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-043 | 0001G5 | Execute the repaired SetLayerFrame chain in exact order: A04-F applies only the function declaration and must retain physical `layerContext +0x10/4 int`; DR04 dry-runs only `layerContext -> beforeLayer` under the closed stack response schema with no state change; A04-R applies that name-only stack rename and must retain type `int`; A04-T applies only the occupied-row stack type `const Layer *`; require both cache refreshes, every complete immediate frame, and no unlisted delta. | exact | Failed no-save A04 receipt, repair-time current public rename/set_type schemas, current complete frame, and prior successful occupied-stack evidence. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-044 | 0001G5 | DR02 perform the literal pure detach rename dry run; require the closed `func[]`/summary schema, complete unchanged state, detach old/desired registry `data:[],total:0`, and the unchanged target desired-name `total:1` state as exactly one `{kind:"name",addr,name}` row. | exact | Current MCP rename/entity_query schemas. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-045 | 0001G5 | A05 perform only the pure detach rename under the closed persistent response schema; retain immediate generic type and require target/detach desired-name `total:1` states each as exactly one `{kind:"name",addr,name}` row at its numeric action target with its exact desired name, while both old-name states remain exact zero states. | exact | Rename/entity_query schemas and no-promotion contract. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-046 | 0001G5 | A06 apply the exact named detach function declaration; require one mandatory exact edit echo and the complete three-row post-type frame. | exact | Live helper semantics and set_type schema. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-047 | 0003A1 | Evaluate eight literal protections independently at all 14 phases, for exactly 112 evaluations; preserve all bytes/items/xrefs and hard-stop before save on any mismatch. | exact | Section 21 phase/protection contract. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-048 | 0003A1 | Supervisor performs wholly fresh exact-artifact Gate 1 on the post-callback report before Gate 2. | exact | B-agent lifecycle. | Supervisor Gate 1. | incorporate | proposed |
| [ ] | CKF-049 | 0003A1 | Supervisor performs Gate 2A after callback using fresh docs, validator receipts, and generated physical readback. | exact | B-agent lifecycle. | Supervisor Gate 2A. | incorporate | proposed |
| [ ] | CKF-050 | 0003A1 | Supervisor performs the isolated fourteen-phase Gate 2B sequence with three dry runs, eight atomic persistent mutations, four cache invalidations, 56 registry reads, 112 protection evaluations, sole save only after S00, fresh reopen R00, and guarded rollback on failure. | exact | Section 21 transaction handoff. | Supervisor Gate 2B. | incorporate | proposed |
| [ ] | CKF-051 | 0003A1 | Supervisor alone executes report lifecycle after Gates 1, 2A, and 2B pass. | exact | Workflow lifecycle boundary. | Supervisor lifecycle. | incorporate | proposed |

Terminal self-audit:

- Exactly 33 required H2 headings are present in template order.
- Ledger/checklist contain 51/51 ordered exact twins after removing the checklist Done column; CKF-001 through CKF-035 are callback-verified and checked, while CKF-036 through CKF-051 remain proposed and unchecked.
- Allocation is 35 checked B006-owned callback rows CKF-001 through CKF-035 and 16 unchecked Supervisor-owned rows CKF-036 through CKF-051; current checked allocation is exactly 35/16.
- Section 21 contains three dry runs, eight persistent one-mutation actions, four cache invalidations, 56 independent exact-name registry requests, eight protections, fourteen phases, and 112 protection evaluations; every desired-name present data row requires exactly mandatory `kind:"name"`, numeric-target `addr`, and exact desired `name`, while zero states remain exactly `data:[],total:0`. A physical stale-contract scan finds zero active present-row requirements that omit mandatory `kind:"name"`, zero active claims that A04-F alone changes `layerContext`, and zero active two-stage or alternative SetLayerFrame frame contracts. Exact pure-function and stack-rename response members, mandatory function/stack set-type edit echoes, the corrected A03 one-row `{addr,error?}` comment response, and every immediate complete frame remain fully closed.
- Formal source appears only in Section 22's four CPP fences; no shell/Python/PowerShell executable fence exists.
- Current/dynamic generated authority is separated from dated historical generated evidence.
- No unresolved raw IDA/decompiler name enters formal source.
- Completed-callback terminal lifecycle marker count is exactly one, as the standalone final nonblank line after this checklist and audit content.
- Exactly the six authorized ordinary by-* destinations plus this report changed directly; all prohibited-operation counts are zero, and generated changes came only from authorized validator ownership.
- The first report lease expired before explicit unlease; the final receipt-correction lease is released immediately after this edit, and current B006 active-lease count is zero before completion status.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000028171","destination_path":"executed-b-agent-research/B006/0003A1-ScreenPaneLayerIndexLookup-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0003A1-ScreenPaneLayerIndexLookup-source-quality.md","timestamp":"2026-08-25T13:10:51-04:00","uid":"0003A1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
