** TARGET-REPORT-UID:0003KI **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003KI DialogPaneRemoveControlByPointer Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: the implemented validator-managed path is `by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md`, retaining UID0003KI and exact half-open range `[0x0049dca0,0x0049dcf8)`; the stale `DialogPaneSelectControlById` path is historical only.
- Final disposition: source-authored protected overload `void DialogPane::RemoveControl(ControlPane *control)`, implemented in source-facing form as guarded composition of accepted `FindControlIndex(const ControlPane *) const` and `RemoveControl(int)` helpers. The compiler-expanded binary preserves the exact List scan and one-element removal semantics.
- Callback state: C01-C20 are incorporated. Target is `92/93` with the exact managed C++ block, owner/emitter UID00003T, `RECONSTRUCTABLE:TRUE`, blank optional emitter position, and `Nested:0` preserved.
- Confidence: very strong for range, ABI, owner, source placement, List type and slots, all ten call sites, first-match behavior, non-owning semantics, and factorization. Exact original private spelling and whether the original header wrote the overloads inline are inferred rather than symbol-proven.

## Supporting Research

- B003 performed an independent report-only pass on 2026-07-12 using current by-* documentation, generated output as a lead, matching executed B-agent reports as leads, and fresh IDA MCP evidence.
- The originally assigned MCP session `bf5519ae` had expired. Correctly serialized requests `2111`/`2121` returned an empty session list and `2112`/`2122` returned `Session not found`; no fallback evidence was accepted. The supervisor reopened the IDB as `supervisor_20260712`.
- Evidence-time request `2201` listed exactly one active NexusTK session, `supervisor_20260712`, backed by `E:/NTK/Resources/NexusTK/NexusTK.exe.i64`; request `2202` returned `status:ok`, imagebase `0x400000`, and analysis, Hex-Rays, and strings cache ready.
- Matching report searches used `0003KI`, `0x0049dca0`, `DialogPaneSelectControlById`, `DialogPaneRemoveControlByPointer`, `RemoveControl(ControlPane`, `m_controlManager`, `GetElementAt`, and `RemoveAt`. Relevant leads were B004 UID00012T, B011 UID00003T, and B002 UID00012S; each material claim was rechecked against current MCP or current accepted by-* support.
- Wave2/Wave3 material was not used as authority. Historical generated command `000000008818` established the pre-callback empty-emitter/path state; callback command `000000008856` proves the emitted result.
- The initial report-only pass created only this report. During the accepted callback B003 used short one-file leases, edited/renamed the eight listed by-* pages, ran each scoped validator and final waited generated verification, and released each lease immediately. B003 did not manually edit generated/coverage/tracker/supervisor/validator state, mutate IDA, or run execute/lifecycle/move/archive commands.

## Target

- Target UID: `0003KI`.
- Historical pre-callback target path: `by-memory/0x0049dca0-0x0049dcf8.DialogPaneSelectControlById.md`.
- Implemented target path: `by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`.
- Supervisor classification: accepted implementation callback for report SHA `EBF1941FFD134BB39AF43782D23BD8BBB54FFC8E9421BBDF8512E3F4F90DEB54`.
- Implemented scores and parent state: `92/93`, `CANONICAL_OWNER:00003T`, `EMITTER_UIDS:00003T`, `RECONSTRUCTABLE:TRUE`, blank optional position, `Nested:0`.

## Current Target State

- Historical pre-callback state: B004 had corrected title/summary/prose but retained the stale physical filename, `86/89`, and blank formal C++; generated command `000000008818` therefore emitted an Empty Emitter Marker.
- Implemented content identifies generic `List *m_controlManager` at `DialogPane+0x1fc`, four-byte `ControlPane *` entries, exact helper factorization, all ten MiniMap teardown call sites, first-match/null/duplicate behavior, caller-owned destruction, protected access, void return, and source placement.
- Implemented source composes public pointer lookup UID0003KJ and protected integer removal UID00012T. Direct owner-field/List access remains compiler-expanded binary evidence, not the source body.
- Final waited generated command `000000008856`, refreshed `2026-07-12T21:37:33-04:00`, emits exactly one UID0003KI body/signature/factorized call under the new path, with no target Empty Emitter Marker or stale old-path annotation.
- Related docs checked: UID00003T, UID0000IT, UID0001U4, UID00012S, UID0003KH, UID00012T, UID0003KJ, UID0003KK, UID000079, UID0003JW, UID0003JZ, UID00008C, UID0000LE, and UID0000XK.
- Callback implementation and required validator/generated verification are complete. Report validation/execution, count/path state, move/archive state, and any later generated state are external supervisor/validator-owned and are not asserted or directed by this artifact.

## Executive Recommendation

- Direct class owner/emitter UID00003T `DialogPane` and source root UID0000IT `NexusTK/ui/core/DialogPane.cpp` are preserved.
- Only the target basename was renamed from stale `DialogPaneSelectControlById` to `DialogPaneRemoveControlByPointer`; UID, range, metadata route, and corrected H1 subject remain stable.
- The exact factorized source body below is implemented, preserving expanded binary behavior while using accepted class API boundaries.
- Target is `86/89 -> 92/93` and class UID00003T is `89/91 -> 90/92`; broader file/layout/aggregate/List/MiniMap scores remain unchanged.
- Do not rename UID0003KJ in this assignment. Its current title, signature, Item Summary, and formal body already say `FindControlIndex(const ControlPane *) const`; its stale `ById` basename remains a separate historical path issue, not a blocker to this exact target rename/body.

## Supervisor Active Recheck

- The supervisor accepted report SHA `EBF1941FFD134BB39AF43782D23BD8BBB54FFC8E9421BBDF8512E3F4F90DEB54` and assigned C01-C20 implementation; rename, exact body, callers, List semantics, scores, supports, scoped validators, and waited generated proof are complete.
- No split execution is authorized or required. The target is one modeled function, and its predecessor/successor padding remains outside the page.
- Every source-bearing item needed by the factorization already exists: UID0003KJ owns the pointer lookup body, UID00012T owns indexed removal, and UID000079/UID0003JW/UID0003JZ own the generic List API evidence.

## Inference Research Guidance Check

- IDA facts, current documentation evidence, and source-shape inference are separated below.
- Assumptions treated as uncertain were the stale `SelectControlById` identity, direct-loop source shape, integer argument type, source return type, concrete manager type, pointer ownership, method access, overload spelling, and target filename stability.
- Fresh MCP resolves the ABI and expanded behavior. Current List and DialogPane children resolve source-facing API names and types. Factorization is inferred from exact sibling-body correspondence and the otherwise unexplained signed result guard.
- `Nested:0` is preserved as validator relative address-sorted delta metadata. It is not changed to ten because caller count is not child count or nesting depth.
- Wave2/Wave3 artifacts encountered in search output were ignored as stale authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best supported resolution | Evidence class |
| --- | --- | --- |
| Stale identity | `RemoveControl(ControlPane *control)`, not select/by-id behavior. | Direct binary plus ten callers |
| Return type | `void`; all exits return no stable value and all ten callers ignore EAX. | Direct disassembly/callers |
| Argument type | One four-byte `ControlPane *`; target compares pointer value to stored pointer entries. | Direct target/caller data flow |
| Receiver | Primary `DialogPane` subobject; callers pass derived `MiniMapDialog` `this`. | Direct calls plus class hierarchy |
| Access | Protected; all direct external calls are in derived MiniMap teardown methods, matching the accepted class declaration. | Caller set plus current class surface |
| Field at `+0x1fc` | `List *m_controlManager`, not a custom manager. | UID0003KH allocation and List vtable |
| Element representation | Four-byte `ControlPane *` value stored by `Append(1, &control)`; `GetElementAt` returns slot storage and requires one dereference. | Constructor/Add/List evidence |
| Count | Snapshot of inline `List::GetCount()` / `m_count+0x0c` before the loop. | Direct target and accepted List accessor |
| Pointer lookup | Source-facing call to `FindControlIndex(control)`; target expands the same null/count/GetElementAt/first-match sequence as UID0003KJ. | Exact sequence comparison |
| Indexed removal | Source-facing call to `RemoveControl(controlIndex)` under `>=0`; target expands UID00012T's `RemoveAt(index,1)` body. | Exact tail comparison |
| Null manager | Lookup returns `-1`; guarded removal makes no call. | Target null branch and UID0003KJ |
| Empty/no match | Returns without mutation. | Count test and loop exhaustion |
| Null argument | No explicit argument guard; if a null pointer entry existed, the first null entry would match. | Direct pointer comparison |
| Duplicate pointer | Removes only the first matching entry. | First-match branch and count `1` |
| Ownership | List removal is non-owning; caller destroys and clears its saved pointer afterward. | All ten call-site sequences |
| Source placement | `DialogPane.cpp`, not MiniMap source or List source. | Receiver state, adjacent class band, support route |
| Filename | Validator-managed rename is required because the durable UID can preserve identity while the stale basename misstates source behavior. | Current by-structure naming rule |

Factorization validation:

- Target `0x49dca7-0x49dcd6` and UID0003KJ `0x49dd28-0x49dd56` perform the same `+0x1fc` null test, `+0x0c` count snapshot, zero-based loop, virtual `GetElementAt` call through slot `+0x10`, slot dereference, direct pointer comparison, increment, and bound test.
- UID0003KJ returns the matching index or `-1`; the target branches directly out on null/empty/no-match and retains the matching index in ESI.
- Target `0x49dcdf-0x49dcee` tests that index for `>=0`, then performs the exact UID00012T operation: load `m_controlManager`, push count `1`, push index, and call virtual slot `+0x1c`.
- The signed-index test is redundant for a hand-written loop index initialized to zero, but it is exactly the source guard required after `FindControlIndex` can return `-1`. This makes overload composition more plausible than direct private List code.
- Emitted standalone copies of UID0003KJ and UID00012T do not contradict inlining; optimized C++ may retain externally used out-of-line bodies while inlining their small definitions into a same-class helper.

Rejected alternatives:

- `SelectControlById`, `RemoveControlById`, numeric-id lookup, selection state, category switching, or a refresh flag are rejected: no control member/id/state is read, and literal `1` is List removal count.
- A direct source loop over `m_controlManager` is behaviorally equivalent but rejected as the best source reconstruction because it duplicates two accepted class helpers and does not explain the retained `index >= 0` test as naturally as factorization.
- `return bool`, `return int`, or returning the removed pointer is rejected because callers ignore EAX and different exits leave unrelated incidental values.
- Removing all duplicates, destroying the payload, clearing the caller field, deleting the List, or invalidating UI state is rejected because none occurs inside the target.
- Public access is not required by the observed target callers; unlike UID0003KJ's PopupMenu callers, all UID0003KI callers are in the derived MiniMap class family.
- MiniMap, generic List, `ControlPane`, no-owner, compiler-generated wrapper, and aggregate ownership are rejected for the exact method.

## Evidence Standards Used

- Direct evidence: fresh MCP session listing/health, function lookup, decompilation, full disassembly, raw bytes, exact xrefs, caller bodies, callee listing, List vtable integers, and function signature bytes.
- Documentation evidence: current exact DialogPane/List method pages, class/file/layout/aggregate support, current generated C++, and matching executed reports used only as leads.
- Inference: period-appropriate overload spelling, protected placement, factorized source expression, local name `controlIndex`, and exact original inline/header placement.
- The evidence is strong enough for formal first-draft C++ because every branch and side effect maps through already accepted source-facing helpers. Confidence remains below 95 because private names and original inline placement are not symbol-proven.

## Evidence Checked

- MCP `2201-2208`: active session/health, target and neighboring functions, profile, target decompile/disassembly, ten xrefs, and boundary bytes.
- MCP `2211-2214`: complete MiniMap destructor and teardown-helper decompilation/disassembly, including all removal/destructor/clear sequences.
- MCP `2221-2226`: `AddControl`, indexed `RemoveControl`, and pointer `FindControlIndex` bodies and ABIs.
- MCP `2231-2237`: List constructor, `GetElementAt`, `RemoveAt`, disassembly, and vtable/xref support.
- MCP `2241-2244`: List vtable integer targets, indexed-removal and pointer-lookup xrefs, target/caller callees, and target signature.
- `int_convert.py` verified List vtable integer results as `0x004f3810`, `0x004f32b0`, `0x004f33c0`, and `0x004f33e0` for slots `+0x00`, `+0x10`, `+0x18`, and `+0x1c`.
- Docs checked: target, DialogPane class/file/layout/aggregate, Add/Remove/Find/Count children, List class/GetElementAt/RemoveAt, MiniMap class/file/aggregate, generated DialogPane.cpp, B004 UID00012T, B011 UID00003T, and B002 UID00012S.
- Negative checks: no target data/vtable xref, no caller outside two MiniMap functions, no source-stable return consumer, no id/state read, no payload destruction or clear in target, no second-match loop after removal, and no boundary overlap.
- Initial session `bf5519ae` was unavailable and was not used. No valid call against `supervisor_20260712` failed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence-time IDB `supervisor_20260712` was healthy and ready. | Direct/strong | 2201-2202 | target / MCP Evidence | incorporate | applied; target `000000008842` |
| C02 | Exact function is `[0x49dca0,0x49dcf8)`, size `0x58`, followed by eight `0xcc` bytes. | Direct/strong | 2203, 2206, 2208 | target / range | incorporate | applied; target `000000008842` |
| C03 | Signature is protected `void DialogPane::RemoveControl(ControlPane *control)`. | Strong | 2204-2207, callers/class | target/class | incorporate | applied; `000000008842`, `000000008845`, generated `000000008856` |
| C04 | `this+0x1fc` is generic `List *m_controlManager`. | Direct/strong | 2221-2222, 2231-2232 | target/layout/class | incorporate | applied; `000000008842`, `000000008845`, `000000008849` |
| C05 | List is constructed as `List(4,20)` with count `+0x0c` and data `+0x10`. | Direct/strong | 2221-2222, 2232 | target/layout/aggregate | incorporate | applied; `000000008842`, `000000008849`, `000000008851` |
| C06 | Vtable `+0x10` is `GetElementAt`; `+0x1c` is `RemoveAt`. | Direct/strong | 2233-2236, 2241 | target/List references | incorporate | applied; target `000000008842`; List support already-present |
| C07 | Each element is slot storage for one four-byte `ControlPane *` and requires dereference. | Direct/strong | Add/List/target bodies | target/class/layout | incorporate | applied; `000000008842`, `000000008845`, `000000008849` |
| C08 | Null manager, empty list, and no match do nothing; null argument has no special guard; first duplicate only is removed. | Direct/strong | 2205-2206 | target behavior/negatives | incorporate | applied; target `000000008842`, lookup `000000008854` |
| C09 | Target scan is the inlined source-facing `FindControlIndex(control)` body. | Strong inference | 2206 versus 2225-2226 | target/formal; UID0003KJ support | incorporate | applied; `000000008842`, `000000008854`, generated `000000008856` |
| C10 | Guarded tail is the inlined source-facing `RemoveControl(controlIndex)` body. | Strong inference | 2206 versus 2223-2224 | target/formal; UID00012T support | incorporate | applied; `000000008842`, `000000008852`, generated `000000008856` |
| C11 | Removal is non-owning; destruction and storage clear belong to callers. | Direct/strong | 2211-2214 | target/MiniMap support | incorporate | applied; `000000008842`, `000000008845`, `000000008847`, `000000008849`, `000000008851`, `000000008852`, `000000008855` |
| C12 | Exactly ten call sites exist at 45137c, 4513bb, 45141b, 45147b, 4514be, 452d2e, 452d6f, 452dcb, 452e2b, 452e70. | Direct/strong | 2207, 2211-2214 | target caller inventory | incorporate | applied; target `000000008842`, MiniMapDialog `000000008855` |
| C13 | Direct owner/emitter remains UID00003T and source root UID0000IT. | Strong | receiver/class/adjacency | target metadata/class/file | already-present | already-present; confirmed by `000000008842`, `000000008845`, `000000008847` |
| C14 | Rename stale target basename to `DialogPaneRemoveControlByPointer` with UID/range stable. | Strong | behavior plus by-structure | target path/references | incorporate | applied; path update `000000008842` |
| C15 | Target score moves `86/89 -> 92/93`. | Strong | all blockers resolved | target metadata | incorporate | applied; target `000000008842` |
| C16 | Preserve reconstructable true, blank position, owner/emitter, and `Nested:0`; no split/child. | Direct/strong | current metadata/range | target metadata | already-present | already-present; confirmed by target `000000008842` |
| C17 | DialogPane class moves `89/91 -> 90/92` and records exact factorized source-ready child. | Strong | complete method surface | by-class/DialogPane.md | incorporate | applied; class `000000008845` |
| C18 | File/layout/aggregate and two sibling pages receive exact path/factorization support with scores/routes unchanged. | Strong | current broader state | listed support docs | incorporate | applied; `000000008847`, `000000008849`, `000000008851`, `000000008852`, `000000008854` |
| C19 | MiniMapDialog records ten consumer call sites and remove/destroy/clear order without ownership movement or score change. | Strong | 2207, 2211-2214 | by-class/MiniMapDialog.md | incorporate | applied; MiniMapDialog `000000008855` |
| C20 | Preserve stale-name history, caller-owned lifetime, rejected ID/selection/destruction semantics, generated pre-callback marker, and B004/B005/B011 useful evidence. | Strong | docs plus fresh negatives | target/support history | historicalize | applied across all eight scoped validators; generated `000000008856` |

## Positive Evidence Summary

- Target is a normal modeled `__thiscall` member with one stack argument, exact size `0x58`, ordinary `retn 4`, and ten direct derived-class call sites.
- Every caller passes a saved pane pointer, then invokes that same pointer's deleting virtual destructor with flag `1`, then clears the source field/vector slot.
- Target's first block exactly matches the accepted pointer `FindControlIndex` sequence; its tail exactly matches the accepted integer `RemoveControl` operation.
- The List constructor, vtable entries, accepted class surface, and Add/Find/Remove sibling pages independently agree on element size, pointer storage, count, lookup, and removal contracts.
- The target lies in the exact DialogPane control-helper band and uses only inherited DialogPane state, while MiniMap is only the derived consumer.

## IDA MCP Facts

- Request `2203`: `sub_49DCA0`, size `0x58`; predecessor `sub_49DC10` size `0x83`; successor `sub_49DD00` size `0x17`; pointer lookup `sub_49DD20` size `0x4b`.
- Request `2204`: 41 instructions, ten basic blocks, two caller functions, no strings, provisional `void __thiscall(_DWORD *this, int)`.
- Request `2206`: target loads `[this+0x1fc]`, snapshots `[list+0x0c]`, uses vslot `+0x10`, compares `[returnedSlot]` to the argument, tests matching index, and calls vslot `+0x1c` with `(index,1)`.
- Request `2207`: exactly ten code xrefs and no data xref.
- Request `2208`: function ends with `retn 4` at `0x49dcf5-0x49dcf7`; `0x49dcf8-0x49dcff` is eight `0xcc` bytes before `0x49dd00`.
- Requests `2233-2236`: `GetElementAt` returns `m_data + index*m_elementSize` for valid indices; `RemoveAt` compacts data, may shrink allocation, and subtracts count.
- Request `2241`: List vtable slot `+0x10` points to `0x4f32b0`; slot `+0x18` to `0x4f33c0`; slot `+0x1c` to `0x4f33e0` (Verified with `int_convert.py`).
- Request `2244`: target signature begins `55 8B EC 53 8B D9 57 8B BB`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x49dc93-0x49dca0` | alignment | thirteen `0xcc` bytes before target | false | aggregate only | n/a | preserve outside target |
| `[0x49dca0,0x49dcf8)` | UID0003KI / renamed target | pointer overload `RemoveControl(ControlPane *)` | true | UID00003T | `86/89 -> 92/93` | rename and emit exact block |
| `0x49dcf8-0x49dd00` | alignment | eight `0xcc` bytes | false | aggregate only | n/a | preserve outside target |
| `[0x49dd00,0x49dd17)` | UID00012T | integer overload `RemoveControl(int)` | true | UID00003T | `90/92` | accepted support, unchanged |
| `0x49dd17-0x49dd20` | alignment | nine `0xcc` bytes | false | aggregate only | n/a | preserve |
| `[0x49dd20,0x49dd6b)` | UID0003KJ | public pointer `FindControlIndex` | true | UID00003T | `90/92` | accepted support, unchanged |

The target has no child range. `Nested:0` is validator relative ordering metadata and remains unchanged.

## Direct Xref / Caller Inventory

| Call site | Caller | Pointer source | Observed post-call order |
| --- | --- | --- | --- |
| `0x45137c` | MiniMapDialog non-deleting destructor `0x451330` | field `+0x5d4` | deleting destructor flag 1, field zero |
| `0x4513bb` | same destructor | vector `+0x5d8..+0x5dc` entry | deleting destructor flag 1, entry zero |
| `0x45141b` | same destructor | vector `+0x5fc..+0x600` entry | deleting destructor flag 1, entry zero |
| `0x45147b` | same destructor | vector `+0x5f0..+0x5f4` entry | deleting destructor flag 1, entry zero |
| `0x4514be` | same destructor | field `+0x5d0` | deleting destructor flag 1, field zero |
| `0x452d2e` | MiniMap teardown helper `0x452d20` | field `+0x5d4` | deleting destructor flag 1, field zero |
| `0x452d6f` | same helper | vector `+0x5d8..+0x5dc` entry | deleting destructor flag 1, entry zero |
| `0x452dcb` | same helper | vector `+0x5fc..+0x600` entry | deleting destructor flag 1, entry zero |
| `0x452e2b` | same helper | vector `+0x5f0..+0x5f4` entry | deleting destructor flag 1, entry zero |
| `0x452e70` | same helper | field `+0x5d0` | deleting destructor flag 1, field zero |

These are ten static call sites across two caller functions. Three sites in each caller are loops over pointer vectors and may execute multiple times dynamically.

## Documentation Evidence And IDA Status

- UID00003T already declares protected pointer and integer `RemoveControl` overloads plus public `FindControlIndex(const ControlPane *) const`; the class parent is above the attachment/emission gate.
- UID0003KJ formal C++ already implements exact pointer lookup and returns first index or `-1`.
- UID00012T formal C++ already implements `m_controlManager->RemoveAt(controlIndex, 1)` and proves void source return.
- UID0003KH and UID000079 prove the concrete object is generic `List(4,20)`, not `DialogControlManager`.
- UID00012S already classifies the broad helper span as a non-emitting inventory with exact children; no aggregate C++ or split is needed.
- Current generated DialogPane.cpp has the correct class declarations but a UID0003KI empty marker under the stale path. Validator-generated output should emit one renamed UID0003KI method body after callback validation.
- B011's old `SelectControlById`/custom-manager wording is historical and contradicted by later accepted docs plus fresh MCP. B004's corrected pointer-removal evidence is retained and deepened, not discarded.

## Ranked Ownership Analysis

### 1. DialogPane class / DialogPane.cpp

- Evidence for: primary receiver, inherited `+0x1fc` field, exact adjacent DialogPane helper band, accepted overload declarations, source-ready sibling methods, and derived-class callers.
- Evidence against: exact private spelling is not symbol-proven.
- Decision: direct owner/emitter UID00003T; source root UID0000IT.

### 2. Generic List

- Evidence for: List owns count, element storage, lookup, compaction, capacity shrink, and removal slots.
- Evidence against: target entry receiver is DialogPane, and the wrapper translates a `ControlPane *` into a list index.
- Decision: delegated dependency only, not target owner.

### 3. MiniMapDialog / MiniMap source

- Evidence for: all ten direct calls are in two MiniMap teardown routines.
- Evidence against: calls use inherited base state; identical DialogPane methods serve other feature dialogs; MiniMap docs already exclude broad `0x49dcxx` helpers from MiniMap ownership.
- Decision: consumer/support evidence only. No ownership or file-route movement.

### 4. ControlPane, aggregate, or no-owner

- Evidence for: argument and stored payload are ControlPane pointers; aggregate physically contains the body.
- Evidence against: payload type does not own container policy, aggregate is non-emitting, and exact class/source route is strong.
- Decision: reject.

## Source Placement

- Recommended placement: protected `DialogPane` method in `NexusTK/ui/core/DialogPane.cpp`, emitted through class UID00003T and file UID0000IT.
- This placement matches the receiver, class declaration, adjacent Add/Remove/Find/Count helper family, shared derived-dialog use, and current generated route.
- Rejected placements: `map/MiniMap*.cpp`, generic `List.cpp`, `ControlPane.cpp`, an artificial `DialogControlManager.cpp`, free helper, or no-owner output.
- No remaining placement uncertainty affects implementation. Only original header-versus-cpp inline spelling is unavailable and is a confidence cap.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is `[0x0049dca0,0x0049dcf8)`, size `0x58`. The filename convention in this local child family uses the end-exclusive endpoint, so the numeric path remains correct.
- Predecessor UID0003KH ends at `0x0049dc93`; thirteen `0xcc` bytes through `0x0049dc9f` remain aggregate-only alignment.
- Successor alignment is `0x0049dcf8-0x0049dd00`, eight `0xcc` bytes, followed by UID00012T at `0x0049dd00`.
- No byte, padding, or sibling is absorbed by the target. No split, merge, child creation, range extension, or reclassification is required.
- Rename is semantic only: preserve numeric range and UID, replace stale basename with `DialogPaneRemoveControlByPointer`.
- `Nested:0` remains unchanged and must not be recalculated from the ten callers.

## Negative Evidence Summary

- No numeric control id, control-id field, selection state, category state, refresh state, UI invalidation, or event notification is read or written.
- No payload destructor, `delete`, caller-field write, List deletion, return-pointer store, or remove-all loop occurs inside the target.
- No call site consumes a return value.
- No non-MiniMap direct caller exists, but this narrows access rather than ownership: both callers are derived DialogPane methods.
- No target vtable/data pointer exists because the helper is nonvirtual.
- Consumer call concentration does not make MiniMap the owner; receiver/state/adjacent helper evidence controls ownership.
- Exact original spelling cannot be recovered from symbols, but that does not justify retaining a demonstrably false filename or blank C++.

## IDA Rename / Type / Comment Recommendations

- Documentation/source-facing name: `DialogPane::RemoveControl(ControlPane *control)`.
- Documentation filename: `0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md`.
- Accepted supporting names/types: `List *m_controlManager`, `ControlPane *control`, `int controlIndex`, `FindControlIndex`, `RemoveControl(int)`, `GetCount`, `GetElementAt`, and `RemoveAt`.
- Keep old `DialogPaneSelectControlById` only in a historical/superseded alias note for searches. Do not keep it as current title, path, method, or Item Summary identity.
- No IDA database rename/type/comment mutation is requested in this report-only assignment. `sub_49DCA0` may remain the IDB label without affecting source documentation.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Range, signature, access, owner/emitter, helper contracts, behavior, callers, and all method-level dependencies are resolved.
- Exact managed target insertion:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void DialogPane::RemoveControl(ControlPane *control)
{
    const int controlIndex = FindControlIndex(control);
    if (controlIndex >= 0)
        RemoveControl(controlIndex);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Exact behavior preservation: accepted `FindControlIndex` supplies null-manager, empty-list, first-match, null-argument, and no-match behavior; the signed guard suppresses removal on `-1`; accepted integer `RemoveControl` performs exactly `RemoveAt(index,1)` with no payload destruction.
- Plausible original source shape: a same-class overload composes two neighboring same-class helpers rather than duplicating raw List internals. The compiler-expanded target is an exact match for those two helper bodies.
- Naming style follows current DialogPane/List class declarations and ordinary early-guard Visual C++ era source, with no decompiler names, raw offsets, or modern container abstraction.
- Third-party import directive: not applicable; this is NexusTK-authored class code.

## Final Recommendation

- UID0003KI is renamed to the exact pointer-removal basename; the old basename remains only as historical search context.
- C01-C20, target `92/93`, and the exact managed body are applied; owner/emitter/reconstructable/position/nesting/range are unchanged.
- DialogPane class is `90/92`; class declaration shape and unrelated B005/B011 work remain intact.
- Named support prose/links are updated at report detail with their scores/routes unchanged unless explicitly listed otherwise.
- All predecessor/successor padding, aggregate child boundaries, caller-owned lifetime behavior, stale-name history, and rejected alternatives are preserved.
- No new owner, emitter, source file, child page, split, or manual tracker/coverage text is recommended.

## Recommended Target Doc Changes

- Renamed `by-memory/0x0049dca0-0x0049dcf8.DialogPaneSelectControlById.md` to `by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md` using the validator-managed UID/reference workflow, command `000000008842`.
- Raised `86/89 -> 92/93`; preserved UID0003KI, owner/emitter UID00003T, reconstructable true, blank optional position, `Nested:0`, exact range, and corrected title.
- Inserted the exact managed block above.
- Added evidence-time MCP provenance, exact bytes/range/padding, signature/return/access rationale, expanded and source-factorized behavior, full ten-call inventory, List layout/slots, first-match/null/duplicate semantics, caller-owned destruction, ownership/source placement, score rationale, and negative evidence.
- Historicalized B011/B002 `SelectControlById` and custom-manager wording; preserved B004's corrected pointer-removal facts and generated pre-callback Empty Emitter Marker as explicitly historical state.

## Recommended Support Doc Changes

- `by-class/DialogPane.md`: raised `89/91 -> 90/92`; retained exact declaration and unrelated B005/B011 work; added source-ready factorization and lifetime evidence. Validator `000000008845`.
- `by-file/DialogPane.md`: kept `88/88`; updated child path/name/source-ready status and factorization/non-owning evidence while retaining broader file uncertainty/route. Validator `000000008847`.
- `by-type/by-struct/DialogPaneLayout.md`: kept `86/90`; updated `+0x1fc` with renamed target, compiler-expanded helper evidence, and non-owning semantics; offsets/formal block unchanged. Validator `000000008849`.
- `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`: kept `90/91`, non-reconstructable, no owner/emitter, and blank C++; updated exact path/factorization/source-ready child status while preserving padding/children. Validator `000000008851`.
- UID00012T `by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md`: kept `90/92`, exact code/route; recorded inlined guarded removal tail. Validator `000000008852`.
- UID0003KJ `by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md`: kept `90/92`, exact code/access/current path; recorded inlined lookup prefix without a second rename. Validator `000000008854`.
- `by-class/MiniMapDialog.md`: kept `86/89`; added all ten teardown sites and remove/destroy/clear order while retaining DialogPane ownership and existing MiniMap raw-body/split decisions. Validator `000000008855`.
- `by-class/List.md`, exact List children, and `by-file/MiniMap.md` already contain same-or-greater evidence and were not edited.

## Score And Metadata Recommendation

- Target implemented: `86/89 -> 92/93`.
- Completion rises because formal C++, exact factorization, complete caller inventory, boundary/padding, ABI, List contracts, null/duplicate/non-owning semantics, ownership, rename, and support plan are resolved.
- Confidence rises because fresh IDA MCP, exact sibling instruction correspondence, accepted List vtable/method pages, and all ten callers agree. It remains below 95 because private original spellings and exact inline/header placement are inferred.
- Class UID00003T: `89/91 -> 90/92`; one formerly blank exact method now has complete source shape and corrected durable identity.
- File UID0000IT `88/88`, layout UID0001U4 `86/90`, aggregate UID00012S `90/91`, UID00012T `90/92`, UID0003KJ `90/92`, MiniMapDialog UID00008C `86/89`, and List UID000079 `92/91` remain unchanged because their remaining score caps are broader than UID0003KI.
- Metadata changes: filename and target scores only. Preserve owner, emitter, reconstructable, optional position, range, and `Nested:0`.

Score-improvement attempts:

- Range blocker: function lookup, full disassembly, bytes, and adjacent functions resolve exact half-open boundaries and padding.
- Return/signature blocker: epilogue and ten ignored-return call sites resolve `void` and one pointer argument.
- Type/layout blocker: Add constructor path, List constructor/vtable, GetElementAt, RemoveAt, and current layout resolve generic List and pointer elements.
- Source-body blocker: exact comparison with UID0003KJ/UID00012T resolves factorization and private-access concerns.
- Lifetime blocker: all ten call sequences resolve non-owning removal and caller-owned deletion/clear.
- Access blocker: complete caller set and class hierarchy support protected placement.
- Name/path blocker: false ID semantics are disproven; validator UID stability makes a semantic filename repair safe.
- Support/parent blocker: class and file parents already clear the gate; the class can defensibly move one point while broader supports retain conservative scores.

## Open Questions With Attempted Resolution

- Exact original spelling: no PDB/private symbol survives. `RemoveControl` is the strongest source-facing name because the accepted class already has the integer overload and Add/Find/Count family. This is a confidence cap, not a code blocker.
- Direct loop versus helper composition: full target, UID0003KJ, and UID00012T disassemblies were compared. The exact sequence reuse and signed result guard resolve composition as the higher-probability source shape.
- `ControlPane *` versus `const ControlPane *`: the removal overload accepts non-const `ControlPane *` in the current class surface and caller ownership flow; it forwards safely to the const lookup helper. No mutation occurs in the target.
- Protected versus public: all ten target callers are derived MiniMap methods, while the public requirement belongs to UID0003KJ's nonderived PopupMenu consumers. Protected remains best supported.
- Original inline/header placement: unavailable. Standalone sibling bodies plus expanded target prove semantics but not declaration placement. This does not affect emitted method source or score above 93.
- No unresolved question requires blank C++, lower ownership, a split, or retaining the stale target path.

## Follow-Up Actions

- B003 implementation and required scoped/generated verification are complete; no B003 implementation item remains.
- B003 performed no execute, lifecycle, move/archive, IDA mutation, or manual generated/coverage/tracker/supervisor/validator-state command.
- Report validation/execution, count/path state, move/archive state, and any later generated state are external supervisor/validator-owned; this artifact neither asserts nor directs those states.

## Confidence

- Recommendation confidence: `93/100`.
- Score confidence: strong; `92/93` reflects complete exact-range documentation while retaining original-name/inline-placement caps.
- Remaining uncertainty: private original spelling and header-versus-cpp inline placement only; no behavior, ownership, range, route, or formal-C++ blocker remains.

## Validator Results

| Command ID | Timestamp | Scope | Exit | Result |
| --- | --- | --- | --- | --- |
| `000000008842` | `2026-07-12T21:32:52-04:00` | `python tools/validator.py --mode file --file by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md --apply --queue-timeout 240` | `0` | `ok:1`; `path_update:1`; `92/93`; reconstruction `blank -> block`; generated deferred |
| `000000008845` | `2026-07-12T21:33:46-04:00` | `python tools/validator.py --mode file --file by-class/DialogPane.md --apply --queue-timeout 240` | `0` | `ok:1`; `90/92`; generated deferred |
| `000000008847` | `2026-07-12T21:34:36-04:00` | `python tools/validator.py --mode file --file by-file/DialogPane.md --apply --queue-timeout 240` | `0` | `ok:1`; `88/88`; generated deferred |
| `000000008849` | `2026-07-12T21:35:09-04:00` | `python tools/validator.py --mode file --file by-type/by-struct/DialogPaneLayout.md --apply --queue-timeout 240` | `0` | `ok:1`; `86/90`; generated deferred |
| `000000008851` | `2026-07-12T21:35:41-04:00` | `python tools/validator.py --mode file --file by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md --apply --queue-timeout 240` | `0` | `ok:1`; `90/91`; generated deferred |
| `000000008852` | `2026-07-12T21:36:17-04:00` | `python tools/validator.py --mode file --file by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md --apply --queue-timeout 240` | `0` | `ok:1`; `90/92`; generated deferred |
| `000000008854` | `2026-07-12T21:36:37-04:00` | `python tools/validator.py --mode file --file by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md --apply --queue-timeout 240` | `0` | `ok:1`; `90/92`; generated deferred |
| `000000008855` | `2026-07-12T21:37:18-04:00` | `python tools/validator.py --mode file --file by-class/MiniMapDialog.md --apply --queue-timeout 240` | `0` | `ok:1`; `86/89`; generated deferred |
| `000000008856` | `2026-07-12T21:37:33-04:00` | `python tools/validator.py --mode autogen --apply --wait-generated --queue-timeout 240` | `0` | generated refresh completed |

- Each edited/renamed by-* page received exactly one scoped validator while leased; every lease was released immediately afterward.
- B003's waited verification produced `auto-generated/NexusTK/ui/core/DialogPane.cpp` at command `000000008856`, refreshed `2026-07-12T21:37:33-04:00`. A later external validator-owned refresh advanced the observed header to command `000000008867`, refreshed `2026-07-12T21:40:37-04:00`, while retaining the exact UID0003KI result below; that later command does not change B003's captured validator proof.
- Exact generated checks: UID0003KI count `1`; method signature count `1`; `FindControlIndex(control)` factorized line count `1`; guarded indexed removal count `1`; new-path annotation count `1`; old `DialogPaneSelectControlById` annotation count `0`; UID0003KI Empty Emitter Marker count `0`.
- Generated UID comment is line 75 and method begins line 76. Existing broad-project autogen diagnostics (`16` fallback inserts, `81` missing child markers, `219` emitters without code) are unrelated to UID0003KI and did not fail any scoped command.

## Changed Files

- Historical report artifact created and callback-updated: `tools/leaser/Agents/Agent-B003/research/0003KI-DialogPaneRemoveControlByPointer-source-quality.md`.
- Renamed: `by-memory/0x0049dca0-0x0049dcf8.DialogPaneSelectControlById.md` -> `by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md` through command `000000008842`.
- Modified: `by-class/DialogPane.md`.
- Modified: `by-file/DialogPane.md`.
- Modified: `by-type/by-struct/DialogPaneLayout.md`.
- Modified: `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`.
- Modified: `by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md`.
- Modified: `by-memory/0x0049dd20-0x0049dd6b.DialogPaneFindControlIndexById.md`.
- Modified: `by-class/MiniMapDialog.md`.
- Leases: eight immediate one-file leases acquired and released; final lease report is empty.
- Validator-owned side effects: UID path/references, generated C++, generated coverage/tracker, projected stats, and validator metadata refreshed by recorded commands; B003 made no manual edit to those files.
- B003 report execution/lifecycle/move/archive commands: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Target current path, corrected path, UID, range, scores, metadata, and generated state recorded.
- [x] Fresh `idb_list` and health completed against `supervisor_20260712`; expired `bf5519ae` evidence excluded.
- [x] Exact range, predecessor/successor padding, signature, return, owner, access, and `Nested:0` disposition resolved.
- [x] All ten MiniMap call sites and remove/destroy/clear semantics recorded.
- [x] Generic List type, layout, element representation, count, GetElementAt, and RemoveAt contracts resolved.
- [x] Null manager, empty, no-match, null-argument, duplicate, first-match, and non-owning behavior resolved.
- [x] Direct-loop versus accepted-helper factorization researched and resolved.
- [x] Historical SelectControlById identity rejected and exact validator-managed rename recommended.
- [x] Exact formal managed C++ supplied.
- [x] Target/class score changes and unchanged support score caps justified.
- [x] Claim And Incorporation Ledger C01-C20 includes destinations, allowed actions, and report-only proposed state.
- [x] Positive/negative evidence, ownership/source placement, rejected alternatives, and open-question closure recorded.
- [x] Wave2/Wave3 material ignored as stale authority.
- [x] Third-party import directive confirmed not applicable.
- [x] No manual supervisor-owned coverage/tracker text is required.

Implementation callback pass:

- [x] Report SHA `EBF1941FFD134BB39AF43782D23BD8BBB54FFC8E9421BBDF8512E3F4F90DEB54` accepted by supervisor for implementation.
- [x] Renamed UID0003KI target to `by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md` through validator-managed command `000000008842`.
- [x] Applied target `86/89 -> 92/93`, exact managed body, full C01-C20 evidence, and unchanged owner/emitter/reconstructable/position/nesting/range.
- [x] Applied DialogPane class `89/91 -> 90/92` and preserved broader class/split work.
- [x] Applied destination-specific support updates to DialogPane file/layout/aggregate, UID00012T, UID0003KJ, and MiniMapDialog with specified scores/routes unchanged.
- [x] Preserved List/MiniMap already-present evidence, all padding/sibling boundaries, stale-name history, caller-owned lifetime, and rejected alternatives.
- [x] Ran exactly one scoped validator for every changed/renamed by-* file under a short lease and released each lease immediately.
- [x] Ran final waited generated verification and recorded command IDs, timestamps, exits, freshness, and exact UID/body/signature/path/marker/duplicate counts.
- [x] Updated C01-C20 verification states, Validator Results, Changed Files, current state, and checklist claim by claim.
- [x] No accepted item remains unapplied; no B003 implementation blocker remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000008884","destination_path":"executed-b-agent-research/B003/0003KI-DialogPaneRemoveControlByPointer-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003KI-DialogPaneRemoveControlByPointer-source-quality.md","timestamp":"2026-07-12T21:51:58-04:00","uid":"0003KI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
