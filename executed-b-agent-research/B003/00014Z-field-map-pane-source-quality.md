** TARGET-REPORT-UID:00014Z **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00014Z] FieldMapPane Source Quality Review

Agent: Agent-B003  
Supervisor assignment: B003-goal2-field-map-pane-source-quality-00014Z-20260617  
Primary target: `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`  
Generated route under review: `NexusTK/map/FieldMapPane.cpp`  
Revision date: 2026-06-17

## Finalized Report / Current Recommendation

Current recommendation: raise `[UID:00014Z] FieldMapPane` from `82/88` to `85/90` after applying the exact target-body evidence update below.

Final disposition: keep reconstructable, keep canonical owner/emitter `[UID:0000JA] FieldMapPane`, and keep generated output route `NexusTK/map/FieldMapPane.cpp`.

Required action: update the primary by-memory page evidence and score, refresh the stale coverage rows, and leave the formal `RECONSTRUCTION_CPP CODE` block blank.

Confidence: strong for the source-quality gate recommendation. The remaining issues are now classified precisely: they cap final C++ and higher audit scores, but they do not justify keeping completion below 85.

## Supervisor Active Recheck

The rejected report under-scored the primary target because it treated three unresolved issues as below-85 blockers. I rechecked those issues directly:

- Constructor no-direct-xref: still no direct constructor caller, but this does not block the aggregate source-quality gate because class identity, vtables, method inventory, source route, and field layout are independently proved.
- Raw `0x004b1130` liveness: still no live caller, but additional binary scans strengthen the conclusion that this is an exact unreferenced FieldMapPane rectangle-helper child, already documented at `85/88`; it blocks formal C++, not 85 completion for the aggregate.
- Request packet field names: no independent protocol-layout name source was found, but the opcode, byte count, field order, source offsets, and packet-helper semantics are exact enough for structural documentation at 85 completion.

This is not a defended no-85 result. It is an executable 85/85+ recommendation for UID 00014Z.

## Scope Checks

- I read `tools/leaser/Agents/Agent-B003/goal.md` and followed the report-only revision scope.
- I did not edit by-memory, by-file, by-class, generated source, IDA databases, generated reports, or `by-memory/-coverage-report.md`.
- I searched prior executed B reports for UID 00014Z and the contained/sibling targets. No executed B report directly owned this UID as the primary target. Relevant leads covered the shared `.EPF` suffix, nearby wide-string/path-helper neighborhood, predecessor ExchangeDialogTail boundary, and preceding padding.

## Target

- Target UID: `00014Z`
- Target path: `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`
- Current documented score: `82/88`
- Recommended score: `85/90`
- Current owner/emitter: `[UID:0000JA] FieldMapPane`
- Recommended owner/emitter: unchanged
- Current generated route: `auto-generated/NexusTK/map/FieldMapPane.cpp`
- Recommended generated route: unchanged

## Evidence Standards Used

Evidence used:

- IDA MCP function lookup, function-list, xrefs, decompilation, raw bytes, signatures, and data-flow checks from the active `NexusTK.exe.i64` database.
- PE-aware raw-binary searches for absolute VA pointers and rel32 call/jump edges for the named blocker addresses.
- Existing by-memory, by-class, by-file, by-item, by-global, proposed-source-tree, generated coverage, and project-level unresolved/resolved reports as documentation leads.
- Prior executed B reports as leads only, not authority.

Why the evidence is enough for 85 completion:

- Every byte range inside the aggregate is accounted for as a modeled method, exact raw child, thunk, destructor, or padding boundary.
- The child pages for the two formerly weak internal helpers now already meet 85+ and support the aggregate.
- The unresolved parts are source-polish and final-C++ blockers, not unresolved owner/range/split blockers.

Why the evidence is not enough for higher/final scores:

- No original source names or packet-layout document proves final request-field semantic names.
- No caller to raw `0x004b1130` exists in IDA or the PE-aware scans.
- The constructor allocation/call site remains unknown, so standalone source-file placement remains best-inference rather than original-source proof.

## Live Evidence Used

IDA MCP session evidence:

- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Health: auto-analysis ready, Hex-Rays ready, strings cache ready
- Adopted session: `b001_00014a_eventhandler_base_20260617`

Additional local binary checks:

- Absolute pointer byte scan in `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - `0x004b0bb0` constructor VA bytes: `0` hits
  - `0x004b1130` raw-helper VA bytes: `0` hits
  - `0x004b11a0` request-helper VA bytes: `0` hits
- PE-aware rel32 edge scan:
  - `call`/`jmp` to `0x004b0bb0`: `0` hits
  - `call`/`jmp` to `0x004b1130`: `0` hits
  - `call` to `0x004b11a0`: `3` hits at `0x004b0dfe`, `0x004b0ea7`, and `0x004b0f0e`
  - `jmp` to `0x004b11a0`: `0` hits
- Documentation/protocol search for opcode/name evidence:
  - Searches for `opcode 0x3f`, `field-map request`, `requestFieldId`, `requestCoord`, and the `+0x8a/+0x90/+0x8c` order found FieldMapPane docs, FieldMapPane class/file pages, the helper page, and proposed-source-tree notes.
  - No independent packet-layout page or protocol document was found that names the three payload fields beyond the FieldMapPane structural evidence.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b0bb0-0x004b129b` | `00014Z` / `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md` | FieldMapPane method aggregate | true | `0000JA` | recommend `85/90` | keep aggregate |
| `0x004b1130-0x004b119d` | `000150` / `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md` | raw rectangle helper child | true | `0000JA` | `85/88` | exact child already clears support gate |
| `0x004b11a0-0x004b1242` | `000151` / `by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md` | request helper child | true | `0000JA` | `85/90` | exact child already clears support gate |
| `0x004b8220-0x004b8284` | `00015U` / `by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md` | constructor-only path helper | true | `0000JA` | `84/88` | source-route support, not in aggregate range |
| `0x0061a3c4-0x0061a44c` | `0003P8` / FieldMapPane vtable data | class RTTI/vtable data | true | `00004U` | `86/91` | supports class identity |
| `0x0061a44c-0x0061a458` | `0003P9` / shared `.EPF` suffix | pooled string literal | true | none, emitters `0000JA`,`0000L3`,`0000PB` | `87/92` | shared, not exclusive FieldMapPane data |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b0bb0` | IDA xrefs: none; PE-aware direct edges: none; absolute pointer scan: none | Constructor allocation site unresolved; not a class/source ownership blocker |
| `0x004b1130` | IDA xrefs: none; PE-aware direct edges: none; absolute pointer scan: none | Raw helper is unreferenced in current binary evidence |
| `0x004b11a0` | `0x004b0dfe`, `0x004b0ea7`, `0x004b0f0e` | Request helper is FieldMapPane input-only |
| `0x004b8220` | `0x004b0c0d` from constructor | Path helper is FieldMapPane constructor-only |
| `0x0061a3c8` | constructor store at `0x004b0bf3` | primary FieldMapPane vtable |
| `0x0061a414` | constructor store at `0x004b0bf9` | secondary FieldMapPane vtable |
| `0x0061a444` | constructor store at `0x004b0c03` | tertiary FieldMapPane vtable |
| `0x0061a44c` | refs from FieldMapPane, MapPane, and WorldMapPane | shared `.EPF` suffix; no exclusive FieldMapPane data ownership |

## Aggregate Source Shape

UID 00014Z should remain a class aggregate, not a standalone free-function blob. The range contains:

- Constructor-like initialization at `0x004b0bb0`.
- Mouse, key, and render virtual methods at `0x004b0d30`, `0x004b0e50`, and `0x004b0fb0`.
- Raw helper-shaped rectangle code at `0x004b1130-0x004b119d`.
- FieldMap request helper at `0x004b11a0-0x004b1242`.
- Two adjustor thunks and a destructor at `0x004b1242`, `0x004b124d`, and `0x004b1260`.

The aggregate score should rise because the weak spots now have exact classifications:

- The raw rectangle helper is not a mystery gap; it is exact raw FieldMapPane-related code with a child page.
- The request helper is not ownership-confused fitting-room code; it is FieldMapPane-only by caller evidence.
- The constructor no-xref state is a known reachability limitation, not evidence against the class or source route.

## Source Placement

Best placement remains:

```text
NexusTK/map/FieldMapPane.cpp
```

Accepted evidence:

- RTTI/vtable names identify `FieldMapPane`.
- The behavior is map-domain UI: EPF map path, field-entry labels, mouse/key selection, rendering, and field-map request sending.
- `0x004b11a0` has exactly three FieldMapPane handler callers.
- `0x004b8220` has exactly one caller, the FieldMapPane constructor.
- Proposed source tree already lists `map/FieldMapPane.cpp`.
- The shared `.EPF` suffix has map-family source-use refs from FieldMapPane, MapPane, and WorldMapPane.

Rejected placements:

- Network module: request serialization uses packet-buffer dependencies, but the opcode and payload selection are owned by FieldMapPane.
- Cash-shop/FittingRoom module: generated names around `dword_67A7EC` are alias pollution; no non-FieldMap caller reaches the request helper.
- FolderSelectDialog module: FolderSelect data begins after the FieldMapPane read-only range; adjacency is not ownership.
- MapPane/WorldMapPane module: they share `.EPF` suffix use, but do not own FieldMapPane methods.
- Larger field/dialog module: still possible in original source, but no constructor call site or source-path evidence proves it. This caps confidence above 90, not completion at 85.

## FieldMapPane Layout Evidence

Decompiler decimal offsets were converted with `tools/int_convert.py`.

Object-level fields:

| Offset | Recommended descriptive name | Evidence |
|---:|---|---|
| `+0x0f8` | `fieldMapEpfPath` | Constructor writes path stem via `0x004b8220`, then appends shared `.EPF` with `_wcscat_s(..., 0x80, aE)` |
| `+0x1f8` | `entries` | First field-entry record base; constructor, mouse, render, request, and raw helper all use it |
| `+0x95f8` | `entryCount` | Constructor stores count; mouse/render/key loops compare against it |
| `+0x95fa` | `selectedIndex` | Constructor initializes it; render highlight and enter key use it |
| `+0x95fc` | `cancelIndex` or `defaultExitIndex` | Escape/q request path uses it |
| `+0x95fe` | `requestInFlight` | Request helper sets it; mouse/enter paths check it |

Per-entry stride: `0x94`.

Per-entry fields:

| Entry offset | Recommended descriptive name | Evidence |
|---:|---|---|
| `+0x00` | `centerY` | Used in top/bottom rectangle math |
| `+0x04` | `centerX` | Used in left/right rectangle math |
| `+0x08` | `label[0x40]` | Constructor copies with `_wcscpy_s(..., 0x40, sourceLabel)` and text-width helper measures here |
| `+0x88` | `auxFieldWord` | Constructor copies a word; no render/input/request consumer found |
| `+0x8a` | `requestFieldId` | First serialized request word |
| `+0x8c` | `requestCoordA` | Third serialized request word; constructor stores a dword, sender serializes low 16 bits |
| `+0x90` | `requestCoordB` | Second serialized request word; constructor stores a dword, sender serializes low 16 bits |

These are descriptive names, not proven original names. They are good enough for documentation at 85 completion because they preserve exact offsets, exact use, and exact packet order.

## Request Packet Evidence

`0x004b11a0` should remain a FieldMapPane-owned request helper.

Packet construction:

- `sub_575380(0x3f, &Src)` writes the opcode byte.
- `sub_5753A0(*(WORD *)(entry + 0x8a), ...)` serializes the first payload word.
- `sub_5753A0(*(DWORD *)(entry + 0x90), ...)` serializes the second payload word, truncated by the helper to the 16-bit packet field.
- `sub_5753A0(*(DWORD *)(entry + 0x8c), ...)` serializes the third payload word, also effectively 16-bit in the packet.
- `sub_574BB0(dword_67A7EC, &Src, 7)` sends seven bytes.
- `this[0x95fe] = 1` marks request in flight.

Protocol-name blocker resolved for gate purposes:

- Exact original names such as `destinationMapId`, `targetX`, and `targetY` are not proven and should not be entered as final source names.
- Structural names `requestFieldId`, `requestCoordB`, and `requestCoordA` are defensible for documentation because they are tied to exact offsets and packet order.
- Lack of independent protocol names blocks final C++ and higher confidence, but it does not cap aggregate completion below 85.

## Raw `0x004b1130` Rectangle Helper

UID 000150 should remain an exact FieldMapPane-owned child at `0x004b1130-0x004b119d`.

Evidence checked:

- `lookup_funcs`: no IDA function at `0x004b1130`, `0x004b119a`, or `0x004b119d`.
- `xrefs_to` / callers: no incoming refs to `0x004b1130`.
- Data-flow trace: no incoming edge to the helper start.
- Raw bytes: normal prologue at `0x004b1130`, `retn 8` at `0x004b119a-0x004b119c`, `0xcc` alignment at `0x004b119d-0x004b11a0`.
- Concrete range signature: unique.
- PE-aware direct edge scan: no `call` or `jmp` to `0x004b1130`.
- Absolute pointer scan: no little-endian VA pointer bytes for `0x004b1130`.
- Behavior match: computes `this + 0x1f8 + index * 0x94`, measures label width and line height, and writes a centered rectangle matching the mouse/render layout.

Best defensible inference:

This is an unreferenced out-of-line rectangle helper or source-authored helper clone that survived in `.text`. It is not padding, not a vtable method, and not request-helper code. It is FieldMapPane-related by layout and helper-call evidence.

Why it does not cap UID 00014Z below 85 completion:

- It is already split as child UID 000150 with `85/88`.
- Its exact range, byte behavior, source owner, and no-reference state are documented.
- The aggregate can be complete enough at 85 while still preserving the no-live-caller caveat.

What it still blocks:

- Formal C++ for UID 00014Z.
- Any score implying final source readiness.
- Any claim that `CalculateFieldItemRect` is a confirmed live method.

## Constructor No-Direct-Xref Reanalysis

Evidence checked:

- IDA `xrefs_to 0x004b0bb0`: no direct xrefs.
- PE-aware direct edge scan: no `call` or `jmp` to `0x004b0bb0`.
- Absolute pointer scan: no little-endian VA pointer bytes for `0x004b0bb0`.
- Vtable store evidence: constructor writes FieldMapPane primary/secondary/tertiary vtables at `0x004b0bf3`, `0x004b0bf9`, and `0x004b0c03`.
- Constructor body evidence: initializes field-entry layout, builds `this+0x0f8` EPF path, appends shared `.EPF`, and populates selection/request state.
- Documentation search: prior reports use the constructor as successor-boundary/class evidence, but no report supplies a missing caller.

Best defensible inference:

The constructor is definitely FieldMapPane class code, but the allocation or construction call site is absent from direct xrefs and simple binary pointer/edge evidence. It may be reached through factory code not recovered by direct xref, linker/LTCG behavior, or an unmodeled construction pattern.

Rejected alternatives:

- Rejecting FieldMapPane ownership: contradicted by vtable stores, RTTI, method slots, and body behavior.
- Moving to a larger field-dialog source file: possible but unproven; there is no constructor caller or source-path string to support that move.
- Treating no-direct-xref as dead code: contradicted by vtable/read-only data and method cluster consistency.

Why it does not cap UID 00014Z below 85 completion:

The target is a memory aggregate over class code, not an allocation-site ownership proof. Constructor caller absence limits original-source-file certainty and keeps confidence at 90 rather than higher, but all owned bytes and class relationships inside the aggregate are documented.

## Aggregate Versus Child Emission Policy

The current generated file `auto-generated/NexusTK/map/FieldMapPane.cpp` is zero bytes because formal C++ blocks are blank. The route is valid; the missing source is an emission-policy and final-C++ readiness issue.

Recommended emission policy:

- UID 00014Z: keep as aggregate/source-shape page; do not add method bodies to formal C++.
- UID 000150: keep exact raw helper child; no formal C++ until raw-helper policy is settled.
- UID 000151: exact request helper child; could later receive C++ once structural packet names are accepted.
- UID 00015U: exact path helper child outside this aggregate; could later receive C++ once buffer names are accepted.
- UID 0000JA: file-level owner for final `NexusTK/map/FieldMapPane.cpp` composition.

This policy supports `85/90` for the primary page while preventing duplicate child emission.

## Heuristic / Inference Reanalysis And Validation

### Issue 1: Primary Score Gate

Best inference: UID 00014Z should clear the active 85/85 gate at `85/90`.

Evidence checked:

- Exact function endpoints and padding.
- Vtable stores and slots.
- Field-entry layout across constructor, mouse, render, request helper, and raw helper.
- Child support pages UID 000150 and UID 000151, both at 85+.
- Current class/file pages, also at 85+.
- PE-aware negative evidence for constructor/raw-helper direct reachability.

Rejected alternative: keeping completion below 85. That is no longer justified because the unresolved items are classified and bounded. They block formal source, not aggregate documentation completion.

Final impact: raise primary completion to 85 and confidence to 90 after applying the target-body snippet below.

### Issue 2: Raw Helper Liveness

Best inference: unreferenced FieldMapPane-related rectangle helper or out-of-line helper clone.

Evidence checked:

- No IDA function object.
- No IDA xrefs or callers.
- No PE-aware direct `call`/`jmp` edges.
- No absolute VA pointer bytes.
- Unique concrete signature.
- Exact match to FieldMap entry layout and text measurement behavior.

Rejected alternatives:

- Padding: rejected by executable helper body and `retn 8`.
- Confirmed live method: rejected by no xrefs, no modeled function, and no pointer evidence.
- Non-FieldMap helper: rejected by FieldMap-specific record layout and placement.

Final impact: keep child UID 000150 at `85/88`; do not use this to hold the aggregate below 85; continue to block formal C++.

### Issue 3: Constructor No-Direct-Xref

Best inference: constructor is class-owned FieldMapPane code with unresolved allocation site.

Evidence checked:

- IDA xrefs, PE-aware direct edges, and absolute pointer scan for `0x004b0bb0`.
- Constructor decompilation.
- Vtable stores and class RTTI.
- Surrounding predecessor/successor boundary docs.

Rejected alternatives:

- No-owner/dead constructor: rejected by class RTTI/vtable and coherent body.
- Larger field-dialog source owner: not enough evidence.
- MapPane/WorldMapPane owner: only shared suffix evidence, no method ownership.

Final impact: source placement remains `map/FieldMapPane.cpp`; confidence capped below final audit, but completion can be 85.

### Issue 4: Request Packet Field Names

Best inference: structural field names are defensible; original protocol names are not.

Evidence checked:

- IDA decompilation of `0x004b11a0`.
- Packet helper docs for `sub_575380` and `sub_5753A0`.
- Queue/send doc for `sub_574BB0`.
- FieldMapPane constructor source offsets.
- Documentation search for opcode `0x3f` and field-map packet names.

Rejected alternatives:

- Naming the fields as proven map id/x/y: rejected because no packet-layout doc confirms those names.
- Leaving all fields unknown: rejected because exact offsets and serialization order are known.
- Moving helper to network/socket ownership: rejected because packet helpers are callees only.

Final impact: use descriptive structural names in docs, keep formal C++ blank until source names are accepted, and let the aggregate reach 85 completion.

### Issue 5: Source Route

Best inference: `NexusTK/map/FieldMapPane.cpp`.

Evidence checked:

- Proposed source tree.
- by-file and by-class docs.
- RTTI/vtable names.
- Map-domain EPF suffix sharing.
- Request/path helper caller locality.
- Rejected owner candidates.

Final impact: keep owner/emitter `[UID:0000JA]`; no new source file needed.

### Issue 6: Existing Docs And Reports

Validated:

- Primary owner/emitter `[UID:0000JA]`.
- Child split for UID 000150 and UID 000151.
- Shared `.EPF` suffix treatment as no-owner with multiple emitters.
- FieldMapPane class/file route.

Rejected/stale:

- Coverage row for UID 000150 still has stale range and score text.
- Coverage row for UID 000151 is malformed and stale relative to the actual by-memory page.
- Previous 82 completion on UID 00014Z should be replaced after adding the deeper gate evidence.

## Exact Primary Target Changes Recommended

Apply these supervisor/A-agent edits to `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`.

### Metadata

Replace:

```text
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

With:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Body Snippet

Add this section after the existing live IDA evidence/source placement notes, or immediately before the current score rationale/change log:

```markdown
## 2026-06-17 B003 Source-Quality Gate Recheck

- B003 rechecked the active 85/85 gate for this aggregate and recommends raising the page to `85/90` while keeping formal C++ blank.
- Constructor reachability is now bounded: IDA reports no direct xrefs to `0x004b0bb0`; a PE-aware direct `call`/`jmp` scan found no edges to `0x004b0bb0`; and a raw absolute-VA byte scan found no pointer bytes for `0x004b0bb0`. This leaves the allocation site unresolved but does not weaken FieldMapPane ownership because the constructor stores the three FieldMapPane vtables and initializes the exact FieldMap path, field-entry, selection, and request state.
- Raw helper liveness is now bounded: IDA still has no function object or incoming xrefs for `0x004b1130`; PE-aware direct `call`/`jmp` scanning found no edges to `0x004b1130`; a raw absolute-VA byte scan found no pointer bytes for `0x004b1130`; and the helper signature is unique. Keep [UID:000150][FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md) as an exact FieldMapPane child documenting an unreferenced rectangle-helper body.
- Request packet naming is source-quality bounded but structurally resolved: [UID:000151][FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md) has exactly three FieldMapPane callers, opcode `0x3f`, seven-byte send length, and payload order from entry offsets `+0x8a`, `+0x90`, and `+0x8c`. No independent packet-layout doc was found for final semantic names, so use descriptive structural field names and keep final C++ blank.
- The unresolved constructor caller, raw-helper liveness, and exact protocol names cap final-source readiness and scores above `85/90`, but they no longer justify keeping this aggregate below 85 completion because all ranges, source ownership, child support pages, field layout, request order, and output route are documented.
```

### Score Rationale Replacement / Addition

If the target has a score rationale table, replace the current row text with:

```markdown
| Completion | 85 | The aggregate now documents exact modeled method endpoints, vtable slots/stores, constructor/path setup, field-entry layout, mouse/key/render behavior, the exact raw rectangle-helper child, the exact request-helper child, packet opcode/order/length, source route, padding boundaries, and negative reachability evidence for the constructor and raw helper. Completion is not higher because formal aggregate C++ remains unsafe and exact protocol/source names are not proven. |
| Confidence | 90 | Confidence is strong because live IDA evidence, PE-aware binary scans, existing child pages, class/file docs, and generated route all agree on FieldMapPane ownership and source placement. It remains below final audit quality because the constructor allocation site is unresolved, `0x004b1130` has no live caller, and request field names are descriptive rather than original-proof. |
```

## Exact Support-Doc Changes Recommended

These support updates are not required to lift UID 00014Z if the primary target receives the snippet above, because UID 000150 and UID 000151 already clear 85/85. They are still recommended to keep the support pages aligned with the deeper gate evidence.

### UID 000150 FieldMapRectHelper

Add under `## 2026-06-15 Live IDA Refresh` or the next evidence section:

```markdown
- 2026-06-17 B003 gate recheck added PE-aware negative evidence: a direct `call`/`jmp` scan over the executable sections found no rel32 edge to `0x004b1130`, and a raw absolute-VA byte scan found no little-endian pointer to `0x004b1130`. This strengthens the current treatment as an exact unreferenced FieldMapPane rectangle-helper body. It does not lower the child score because the byte range, behavior, owner route, and no-live-caller caveat are now explicit; it continues to block formal C++.
```

### UID 000151 FieldMapRequestHelper

Add under `## IDA Evidence`:

```markdown
- 2026-06-17 B003 gate recheck searched current docs for independent opcode `0x3f` / field-map packet names and found no packet-layout page that names the three payload fields beyond FieldMapPane structural evidence. Keep final names descriptive: first payload from entry `+0x8a`, second from `+0x90`, third from `+0x8c`. This confirms the current `85/90` score: behavior, ownership, range, and packet order are source-quality enough, while final semantic protocol names remain outside current evidence.
```

### UID 00004U FieldMapPane Class

Add to the class layout or live evidence section:

```markdown
- 2026-06-17 B003 source-quality recheck resolves the primary aggregate gate at `85/90`: constructor caller remains unresolved after IDA xref, PE-aware rel32, and absolute-pointer checks, but class ownership is still proved by vtable stores and method slots; raw `0x004b1130` remains an exact unreferenced FieldMapPane rectangle-helper child; and request payload names remain structural rather than original-proof.
```

### UID 0000JA FieldMapPane File

Add to boundary/open-question notes:

```markdown
- 2026-06-17 B003 recheck keeps `NexusTK/map/FieldMapPane.cpp` as the best source route. The constructor no-direct-xref issue blocks proving a larger field-dialog module, but not the current file route. The aggregate [UID:00014Z] can clear `85/90` as source-quality documentation while still leaving formal aggregate C++ blank to avoid duplicate child emission and unstable protocol names.
```

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for UID 00014Z.

The recommended `85/90` score clears the minimum emitter/code-entry gate, but the gate is not a command to enter unsafe aggregate source. Formal C++ should remain blank for concrete source-shape reasons:

- UID 00014Z is an aggregate over exact child ranges. Adding method bodies here risks duplicate output when child pages UID 000150, UID 000151, UID 00015U, and later method pages emit to `FieldMapPane.cpp`.
- Raw `0x004b1130` is exact and reconstructable but unreferenced; a formal method body would overstate liveness.
- Request packet field names are structurally known but not original-proof.
- The constructor allocation site is unresolved, so a full class/source skeleton would be more speculative than the documented aggregate should be.

Informal layout skeleton for later file-level reconstruction only:

```cpp
// Informal shape only; do not paste into UID 00014Z formal C++.
struct FieldMapEntry {
    int32_t centerY;          // +0x00
    int32_t centerX;          // +0x04
    wchar_t label[0x40];      // +0x08
    uint16_t auxFieldWord;    // +0x88
    uint16_t requestFieldId;  // +0x8a
    int32_t requestCoordA;    // +0x8c, serialized after +0x90
    int32_t requestCoordB;    // +0x90, serialized before +0x8c
};

class FieldMapPane {
    wchar_t fieldMapEpfPath[0x80]; // object +0x0f8
    FieldMapEntry entries[];       // object +0x1f8, stride 0x94
    uint16_t entryCount;           // object +0x95f8
    uint16_t selectedIndex;        // object +0x95fa
    uint16_t cancelIndex;          // object +0x95fc
    bool requestInFlight;          // object +0x95fe
};
```

## Coverage Report Replacement Text

If the supervisor updates `by-memory/-coverage-report.md`, replace the current three FieldMapPane rows in the same placement context between:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004b0ba5-0x004b0bb0 | padding | ExchangeDialogTail to FieldMapPane alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
```

and:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004b129b-0x004b12a0 | padding | FieldMapPane to virtual readable string helpers alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
```

Pasteable replacement rows:

```markdown
    - [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md) 0x004b0bb0-0x004b129b | class-aggregate | FieldMapPane : reconstructable : 85% : strong : B003 source-quality recheck confirms exact FieldMapPane method endpoints, vtable stores/slots, constructor EPF path setup, field-entry layout, mouse/key/render behavior, FieldMap-only request helper callers, raw `0x004b1130` rectangle-helper child, padding boundaries, PE-aware no-direct-edge/no-pointer evidence for the constructor and raw helper, and source route `NexusTK/map/FieldMapPane.cpp`; formal aggregate C++ remains blank to avoid duplicate child emission and unstable protocol names.
    - [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md) 0x004b1130-0x004b119d | raw helper | FieldMapRectHelper : reconstructable : 85% : strong : Live IDA and B003 PE-aware recheck confirm no modeled function, no incoming refs, no direct rel32 edge, no absolute pointer hit, exact `0x94`-stride field-entry lookup at `this+0x1f8`, label-width and line-height measurement calls, centered rectangle writes, final `retn 8`, and alignment before the FieldMap request helper.
    - [UID:000151][0x004b11a0-0x004b1242.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md) 0x004b11a0-0x004b1242 | helper function | FieldMapRequestHelper : reconstructable : 85% : strong : IDA and PE-aware recheck confirm exactly three FieldMapPane handler callers at `0x004b0dfe`, `0x004b0ea7`, and `0x004b0f0e`, opcode `0x3f`, payload fields from entry offsets `+0x8a`, `+0x90`, and `+0x8c`, seven-byte send through the socket queue funnel, request-in-flight flag write at object offset `+0x95fe`, and no independent protocol document proving stronger field names.
```

## Validation Commands

No validator `--apply` command was run because this revision only edits the B003 research report.

Recommended validation after supervisor/A-agent edits:

> Executable block R001 was removed from this report and preserved verbatim in [00014Z-field-map-pane-source-quality-removed.md](00014Z-field-map-pane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

Created: none in this revision.

Modified:

- `tools/leaser/Agents/Agent-B003/research/00014Z-field-map-pane-source-quality.md`

Not modified:

- by-memory docs
- by-class docs
- by-file docs
- generated source
- generated reports
- IDA database
- `by-memory/-coverage-report.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00014Z-field-map-pane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"00014Z"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014Z-field-map-pane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00014Z-field-map-pane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
