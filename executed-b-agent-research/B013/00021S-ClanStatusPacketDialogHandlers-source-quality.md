** TARGET-REPORT-UID:00021S **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00021S ClanStatusPacketDialogHandlers Source-Quality / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00021S] as a documented `social/Clan.cpp` source-authored packet/dialog helper island for now, but do not populate its aggregate `RECONSTRUCTION_CPP CODE` block. If formal C++ is to be emitted, split this range into method-level child pages first.
- Final disposition: mixed but coherent Clan source island. The three live dispatcher-called helpers are `ClanStatusPane` packet/view helpers; the no-xref dialog opener siblings are retained `Clan.cpp` file-local helper bodies that mirror dispatcher inline branches.
- Required action: update target/support docs with the corrected `ClanStatusPane` vs `ClanEnlistInputDialog` placement, keep current owner/emitter route until a split is performed, raise the target to `86/91`, and apply the exact coverage replacement row below if accepted.
- Confidence: high for range, xref, packet/action, field-offset, scratch-buffer, and dispatcher-inline conclusions; medium-high for final source names and retained-helper declaration form.

## Supporting Research

## Target

- Target UID: [UID:00021S]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B013\research\00021S-ClanStatusPacketDialogHandlers-source-quality.md`
- Current supervisor classification: B-preferred heuristic/source-quality assignment.
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I8`, blank C++.
- Current coverage row: `0x004877d0-0x00488594 | packet-handler cluster | ClanStatusPacketDialogHandlers : reconstructable : 84% : strong`.

## Executive Recommendation

The current aggregate should not receive aggregate-level C++ even though it meets the active code-entry gate by score and emitter. Its range contains twelve separate functions with two different source roles:

- `0x004877d0`, `0x004879e0`, and `0x00487ea0` are live `ClanStatusPane` handlers called by [UID:00021C].
- `0x00487c40`, `0x00487d70`, `0x00487e20`, `0x00488170`, `0x00488220`, `0x004882d0`, `0x00488370`, `0x00488460`, and `0x00488510` are no-xref retained dialog opener helpers in `Clan.cpp`.

The strongest current action is a source-quality repair, not immediate code insertion. Keep the existing file-level owner/emitter while this remains one page, but document that method-level child pages are required before formal C++ emission. When split, the three live handlers should route through [UID:00002K] `ClanStatusPane`; the opener siblings should route as `Clan.cpp` file-local helpers unless later source-layout evidence proves a committed `ClanDialogs.cpp` split.

## Supervisor Active Recheck

- Active assignment rechecked from `Agent-B013/goal.md`: [UID:00021S] `ClanStatusPacketDialogHandlers` source-quality.
- Temporary coverage edit ban remains active. I did not edit `by-memory/-coverage-report.md`.
- I did not perform a by-memory split in this pass. The assignment asks for source-quality reanalysis and the split decision. The conclusion is that a split is required before final C++ emission, but the current one-page island can remain as the research/container page until the supervisor schedules the child-page split.
- No source-bearing child pages were created by this report; proposed child ranges and owners are listed below.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest true semantic owner for documentation and allows blank C++ when emitter route, dependencies, names, or source shape are not ready.
- The current source tree places the broader Clan feature in `NexusTK/social/Clan.cpp`, with `ClanDialogs.cpp` only a split candidate.
- Existing docs were treated as leads, not proof. The key stale claim is the `ClanEnlistInputDialog` method label for the first, second, and sixth subranges; binary and support-doc evidence now support `ClanStatusPane` instead.

## Evidence Standards Used

- Documentation evidence: target page [UID:00021S], dispatcher [UID:00021C], [UID:00002K] `ClanStatusPane`, [UID:00002B] `ClanEnlistInputDialog`, [UID:0000I8] `Clan`, [UID:0000IA] `ClanDialogs`, [UID:0002B7] `WideCharStrGlobalBuffer`, [UID:00035D] `ClanStringListPaneInsertOrReplaceText`, [UID:0000VN] ignored padding, and prior executed B reports.
- Raw binary evidence: local PE `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247E04E20B65D6414C7238AA8FF5515`, image base `0x00400000`, Capstone 5.0.7 disassembly, direct rel32 target scans, and exact VA/RVA pointer scans.
- IDA MCP status: unavailable in this session at `http://127.0.0.1:13337/mcp` (`Unable to connect to the remote server`). Existing accepted docs record prior live IDA MCP lookup/decompile/xref evidence; current raw PE checks were used to revalidate reachability and instruction facts.

## Raw Binary / IDA Facts

Function/range facts:

- The target contains twelve function bodies separated by alignment already listed in [UID:0000VN].
- The current page's function sizes match prior IDA evidence: starts at `0x004877d0`, `0x004879e0`, `0x00487c40`, `0x00487d70`, `0x00487e20`, `0x00487ea0`, `0x00488170`, `0x00488220`, `0x004882d0`, `0x00488370`, `0x00488460`, and `0x00488510`.
- Local PE rel32 scan found direct calls only to:
  - `0x00484fdb -> 0x004877d0`
  - `0x00484fec -> 0x004879e0`
  - `0x00485181 -> 0x00487ea0`
- The same scan found zero direct rel32 call/jump targets to the other nine opener starts.
- Exact absolute VA and RVA pointer scans found zero pointer hits to all twelve starts. This confirms the no-xref opener caveat and also shows the live helper calls are ordinary relative calls, not table pointers.

Instruction facts:

- Dispatcher `0x00484f70-0x0048540b` calls `0x004877d0`, `0x004879e0`, and `0x00487ea0`; its other dialog branches inline equivalent construction/opening logic.
- `0x004877d0` uses `0x0067adf0`, capacity constants `0x10000` and `0x20000`, sets receiver byte `+0xf8` to `2`, refreshes child pointers `+0x2514`, `+0x2510`, and `+0x2518`, then configures selected child `+0x2510`.
- `0x004879e0` rejects nonzero `packet[2]`, clears/fills child `+0x2514`, calls [UID:00035D] at `0x00487b56`, sets receiver byte `+0xf8` to `3`, then configures selected child `+0x2514`.
- `0x00487ea0` switches on `packet[2]`: action `0` fills child `+0x2518`, calls [UID:00035D] at `0x0048807b`, sets view byte `+0xf8` to `4`, then configures selected child `+0x2518`; action `1` allocates `0x870`, calls `0x00489600`, and installs `ClanEnlistInputDialog` vtables; action `2` returns success.
- The opener siblings use helper `0x00516030`, action-byte tests, allocation sizes `0x270`, `0x26c`, or `0x870`, base constructors `0x00488b40`, `0x00489600`, `0x0048a1c0`, or `0x0048a810`, and derived Clan dialog vtable stores.

## Function / Child Inventory

| Range | Proposed child/source name | Role | Direct parent if split | Status |
| --- | --- | --- | --- | --- |
| `0x004877d0-0x004879d8` | `ClanStatusPane::HandleClanEnlistRequestPacket` | subtype `1`; decode clan name/request text, fill info child, show view `2` | [UID:00002K] | live helper; split before C++ |
| `0x004879e0-0x00487c37` | `ClanStatusPane::HandleClanJoinListPacket` | subtype `2`, action `0`; fill join-list child, show view `3` | [UID:00002K] | live helper; split before C++ |
| `0x00487c40-0x00487d61` | `OpenClanLeaveConfirmDialogFromPacket` | subtype `3`; decode name and open leave confirm dialog | [UID:0000I8] | retained file-local opener |
| `0x00487d70-0x00487e13` | `OpenClanDepositMoneyDialogFromPacket` | subtype `4`; action `0` opens money dialog, action `1` success/no dialog | [UID:0000I8] | retained file-local opener |
| `0x00487e20-0x00487e9c` | `OpenClanDepositItemDialogFromPacket` | subtype `5`; action `0` opens deposit item dialog | [UID:0000I8] | retained file-local opener |
| `0x00487ea0-0x00488167` | `ClanStatusPane::HandleClanMemberListOrEnlistDialogPacket` | subtype `6`; action `0` fills enlist/member list, action `1` opens `ClanEnlistInputDialog`, action `2` success | [UID:00002K] | live helper; split before C++ |
| `0x00488170-0x00488213` | `OpenClanExpelNameDialogFromPacket` | subtype `7`; action `0` opens expel dialog, action `1` success/no dialog | [UID:0000I8] | retained file-local opener |
| `0x00488220-0x004882c3` | `OpenClanSummonNameDialogFromPacket` | subtype `8`; action `0` opens summon dialog, action `1` success/no dialog | [UID:0000I8] | retained file-local opener |
| `0x004882d0-0x0048836b` | `OpenClanAppearNameDialogFromPacket` | subtype `9`; action `0` opens appear dialog | [UID:0000I8] | retained file-local opener |
| `0x00488370-0x0048845d` | `OpenClanChangeDialogFromPacket` | subtype `10`; action `0` opens name dialog, action `1` opens attr dialog, action `2` success/no dialog | [UID:0000I8] | retained file-local opener |
| `0x00488460-0x00488503` | `OpenClanWithdrawMoneyDialogFromPacket` | subtype `11`; action `0` opens withdraw-money dialog, action `1` success/no dialog | [UID:0000I8] | retained file-local opener |
| `0x00488510-0x00488594` | `OpenClanWithdrawItemDialogFromPacket` | subtype `12`; action `0` opens withdraw-item dialog, action `1` success/no dialog | [UID:0000I8] | retained file-local opener |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x00484fdb` | rel32 call to `0x004877d0` | dispatcher case `1` live helper route |
| `0x00484fec` | rel32 call to `0x004879e0` | dispatcher case `2` live helper route |
| `0x00485181` | rel32 call to `0x00487ea0` | dispatcher case `6` live helper route |
| nine opener starts | zero rel32 target hits and zero VA/RVA pointer hits | retained/no-xref functions, not hidden direct-call helpers |
| `0x00487b56`, `0x0048807b` | calls to [UID:00035D] | join/enlist list insertion/update helper |
| `0x0048789b`, `0x004878cf`, `0x004878f6`, `0x0048791a` | references to `0x0067adf0` path in docs/raw disasm | subtype `1` text decode uses the wide scratch buffer |

## Packet Subtype / Action Semantics

| Subtype | Active dispatcher form | Retained helper form | Action semantics |
| --- | --- | --- | --- |
| `1` | direct call `0x004877d0` | same body | request/info text packet; show `m_infoListPane` view `2` |
| `2` | direct call `0x004879e0` | same body | action `0` join-list payload; nonzero rejects |
| `3` | inline branch | no-xref `0x00487c40` | action `0` opens leave confirm; nonzero accepted by dispatcher |
| `4` | inline branch | no-xref `0x00487d70` | action `0` opens deposit-money dialog; action `1` accepted |
| `5` | inline branch | no-xref `0x00487e20` | action `0` opens deposit-item dialog; other actions reject |
| `6` | direct call `0x00487ea0` | same body | action `0` fills enlist/member list; action `1` opens enlist dialog; action `2` accepted |
| `7` | inline branch | no-xref `0x00488170` | action `0` opens expel dialog; action `1` accepted |
| `8` | inline branch | no-xref `0x00488220` | action `0` opens summon dialog; action `1` accepted |
| `9` | inline branch | no-xref `0x004882d0` | action `0` opens appear dialog |
| `10` | inline branch | no-xref `0x00488370` | action `0` opens change-name dialog; action `1` opens change-attr dialog; action `2` accepted |
| `11` | inline branch | no-xref `0x00488460` | action `0` opens withdraw-money dialog; action `1` accepted |
| `12` | inline branch | no-xref `0x00488510` | action `0` opens withdraw-item dialog; action `1` accepted |

## Documentation Evidence And Status

Existing docs that support the conclusion:

- [UID:00021C] documents `ClanStatusPane` dispatcher ownership, the `this - 0xa0` adjustment, direct calls only for cases `1`, `2`, and `6`, and inline dialog branches for the rest.
- [UID:00002K] documents `m_currentClanStatusView` at `+0xf8`, status header storage at `+0xfe`, and child panes at `+0x2510`, `+0x2514`, and `+0x2518`.
- [UID:0002B7] proves the `0x004877d0` text path uses a Clan-owned wide scratch buffer at `0x0067adf0`.
- [UID:00035D] proves join/enlist list insert calls come only from `0x004879e0` and `0x00487ea0`.
- [UID:0000IA] treats `ClanDialogs.cpp` as a split candidate and already rejects moving [UID:00010B] and [UID:00021C] there.

Existing docs that need support cleanup:

- [UID:00021S] still labels the first, second, and sixth subranges as `ClanEnlistInputDialog::...` in the range table. These should be changed to `ClanStatusPane` helper names.
- [UID:00002B] `ClanEnlistInputDialog` still lists the three [UID:00021S] subranges as methods. Those rows should be removed or rewritten as related `ClanStatusPane` packet handlers that may open/fill the enlist dialog.
- [UID:0000IA] `ClanDialogs` says `ClanEnlistInputDialog` owns "parser/handlers and submitter." The "parser/handlers" wording should be removed for [UID:00021S]; only the raw constructor and submitter are direct dialog-class content.
- [UID:0000I8] `Clan` correctly places the page in `Clan.cpp`, but its `ClanEnlistInputDialog` row should not describe the packet-handler caveats as dialog ownership.

## Ranked Ownership Analysis

### 1. [UID:00002K] ClanStatusPane for the three live helpers

- Evidence for: dispatcher [UID:00021C] is a `ClanStatusPane` secondary-vtable method; direct calls happen from that dispatcher; callees mutate `+0xf8`, `+0xfe`, `+0x2510`, `+0x2514`, and `+0x2518`; the same fields are documented as `ClanStatusPane` state/children.
- Evidence against: not all twelve functions in the current aggregate are `ClanStatusPane` methods.
- Decision: accepted for split children `0x004877d0`, `0x004879e0`, and `0x00487ea0`; rejected as aggregate owner for the full page.

### 2. [UID:0000I8] Clan / `social/Clan.cpp` for the aggregate and opener siblings

- Evidence for: all functions sit inside the dense Clan source island, share opcode `0x43` dialog semantics, construct Clan modal dialogs, and match the dispatcher inline branches. `Clan.cpp` is the currently stronger source owner than `ClanDialogs.cpp`.
- Evidence against: using the file as direct owner for the three live helpers hides their narrower `ClanStatusPane` method ownership.
- Decision: accepted for the current unsplit aggregate and for the no-xref opener siblings. If split, use `ClanStatusPane` for the live handlers and `Clan.cpp` file-local ownership for the opener siblings.

### 3. [UID:00002B] ClanEnlistInputDialog

- Evidence for: `0x00487ea0` action `1` allocates `0x870`, calls `0x00489600`, and installs `ClanEnlistInputDialog` vtables. The class page historically listed the three handlers.
- Evidence against: the three live helpers receive and mutate `ClanStatusPane` storage. `ClanEnlistInputDialog` is constructed by one branch, not the receiver/owner of the handler island. Existing Wave2/class ownership for `0x004842b0` and `0x00487370` has already been corrected as stale.
- Decision: rejected as direct owner for [UID:00021S] subranges. Keep `ClanEnlistInputDialog` ownership only for its raw constructor and submitter.

### 4. [UID:0000IA] ClanDialogs / [UID:0000I9] ClanBank

- Evidence for: many no-xref openers instantiate modal dialogs, and item dialogs have stronger class behavior in the ClanBank family.
- Evidence against: opener bodies are packet-dispatch helpers in the Clan status packet island, not dialog methods. [UID:0000IA] is a split candidate, not the current stronger owner; ClanBank owns active item dialog behavior, not these no-xref opener mirrors.
- Decision: rejected for the current target. Add cross-notes only if helpful.

## Negative Evidence Summary

- No exact-start absolute VA or RVA pointers were found for any of the twelve function starts in the local PE.
- No direct rel32 call/jump target exists for the nine opener starts.
- The negative results are meaningful because the same rel32 scan finds the three dispatcher calls to live helper starts.
- Consumer evidence from dialog constructors/vtables proves the opened dialog classes, not direct ownership of the opener helper bodies.
- Address adjacency alone is not the reason for Clan ownership; the conclusion also uses dispatcher relationship, packet subtype sequence, field offsets, vtable construction targets, and prior Clan source-family docs.

## Heuristic / Inference Reanalysis And Validation

### Stale `ClanEnlistInputDialog` handler labels

Best inference: the live helpers are `ClanStatusPane` handlers, not `ClanEnlistInputDialog` methods.

Evidence checked: [UID:00021C] dispatcher ownership and receiver adjustment; raw disassembly of the helpers; [UID:00002K] field names; [UID:00002B] stale method list; action `1` construction of `ClanEnlistInputDialog` from `0x00487ea0`.

Rejected alternatives:

- `ClanEnlistInputDialog::Handle...`: rejected because the helpers write `ClanStatusPane` view and child fields.
- `ClanDialogs.cpp` packet handlers: rejected because the handler receiver is status-pane state and the dispatcher is not a dialog class.

Remaining blocker: original source names for these helpers are not recovered. This limits completion but not ownership.

### Retained no-xref dialog-opener siblings

Best inference: source-authored retained `Clan.cpp` file-local helper bodies, not padding, compiler artifacts, or proven live hidden callbacks.

Evidence checked: function-shaped bodies, standard prologues/EH where present, shared packet text decode helper, action-byte tests, coherent subtype order, allocation sizes, base constructor calls, vtable stores, exact alignment padding, rel32 scans, VA/RVA scans, and dispatcher inline mirrors.

Rejected alternatives:

- Ignored/dead padding: rejected because these are valid executable dialog-opening function bodies.
- Active hidden indirect targets: not supported; exact-start pointer and direct branch scans are zero.
- Class methods on the opened dialog classes: rejected because they allocate/construct dialogs rather than receive an existing dialog `this`.

Remaining blocker: without object-file/linker metadata or source symbols, the original reason these no-xref bodies are present cannot be proven. Keep them reconstructable with blank formal C++.

### Source placement

Best inference: `social/Clan.cpp` remains the current source file. `ClanDialogs.cpp` remains a split candidate for dialog classes, not for this packet helper island.

Evidence checked: proposed source tree, [UID:0000I8] Clan contents, [UID:0000IA] ClanDialogs caveats, [UID:00021C] dispatcher source placement, B001/B012 executed reports, and local PE reachability.

Rejected alternatives:

- Move aggregate to `ClanDialogs.cpp`: rejected because status-pane packet handlers and file-local dispatch helpers are not a modal-dialog implementation unit.
- Move item openers to `ClanBank.cpp`: rejected because active item dialog methods can be ClanBank-owned while these no-xref packet openers remain in the Clan packet island.

### Packet/protocol field semantics

Best inference: opcode `0x43`, subtype at `packet[1]`, action/state at `packet[2]` for subtypes with dialog-opening variants. Outbound opcode `0x4b` helpers in adjacent docs name the request side, but this target is inbound handler/open behavior.

Evidence checked: [UID:00021C] action matrix, current target range table, B001 opcode `0x4b` helper report, raw disassembly of `cmp byte ptr [packet+2]`, and constructor/open branches.

Remaining blocker: final enum names for subtype/action values are still project-wide provisional.

### Child-pane field and global scratch-buffer names

Best inference:

- `+0xf8`: `m_currentClanStatusView`
- `+0xfe`: `m_statusHeaderText` / current clan-name heading text
- `+0x2510`: `m_infoListPane`
- `+0x2514`: `m_joinListPane`
- `+0x2518`: `m_enlistListPane`
- `0x0067adf0`: Clan-owned wide scratch buffer, likely file-local or TU global

Evidence checked: [UID:00002K], [UID:0002B7], [UID:00035D], raw disassembly tails for `0x004877d0`, `0x004879e0`, and `0x00487ea0`.

Remaining blocker: final C++ member names are inferred/descriptive, not source-proven.

### Split/range decision

Best inference: keep current page as a research/source-island page until the supervisor performs child split, but require method-level child pages before C++ emission.

Evidence checked: by-structure child/aggregate rules, current target metadata, exact function boundaries, mixed direct owner roles, existing raw no-xref constructor/helper precedent, and active code-entry rule.

Rejected alternatives:

- Emit all twelve functions from the aggregate now: rejected because it would mix `ClanStatusPane` methods and file-local helpers in one C++ block and misrepresent dispatcher-inline branches.
- Mark aggregate non-reconstructable immediately without child pages: rejected because the current page still carries real source-authored executable functions and no exact child pages exist yet.

### Final C++ readiness

Best inference: formal aggregate C++ should stay blank.

Evidence checked: current `(84 + 90) / 2 > 85` gate, emitter route, dispatcher inline-vs-helper distinction, no-xref opener liveness, child source-owner split, unresolved packet/event type, unresolved final helper names, and dependency names.

Blocker impact: this should cap the current aggregate below final-source scores and require an explicit no-code proof. It does not require lowering below the active routing gate because the behavior and owner are strongly documented.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:00021S] in its current aggregate form.

Exact no-code proof:

- The page covers twelve functions, not one coherent source method.
- The three live functions should become `ClanStatusPane` child pages if emitted.
- The nine opener siblings have no direct caller, no exact-start pointer evidence, and are mirrored by inline branches in [UID:00021C].
- A helperized C++ block would misstate the observed dispatcher call graph; an inline-only C++ block would discard the retained function bodies.
- The event/payload type, final packet enum names, and final file-local helper declaration style are still not final-source quality.

Permitted review sketch only, not formal C++:

```cpp
// Review-only source shape. Do not insert into 00021S as aggregate C++.
bool ClanStatusPane::HandleClanEnlistRequestPacket(const unsigned char* packet);
bool ClanStatusPane::HandleClanJoinListPacket(const unsigned char* packet);
bool ClanStatusPane::HandleClanMemberListOrEnlistDialogPacket(const unsigned char* packet);

static bool OpenClanLeaveConfirmDialogFromPacket(const unsigned char* packet);
static bool OpenClanDepositMoneyDialogFromPacket(const unsigned char* packet);
static bool OpenClanDepositItemDialogFromPacket(const unsigned char* packet);
static bool OpenClanExpelNameDialogFromPacket(const unsigned char* packet);
static bool OpenClanSummonNameDialogFromPacket(const unsigned char* packet);
static bool OpenClanAppearNameDialogFromPacket(const unsigned char* packet);
static bool OpenClanChangeDialogFromPacket(const unsigned char* packet);
static bool OpenClanWithdrawMoneyDialogFromPacket(const unsigned char* packet);
static bool OpenClanWithdrawItemDialogFromPacket(const unsigned char* packet);
```

## Recommended Metadata And Score

Recommended target metadata after support text is incorporated:

```text
*** COMPLETION:86
*** CONFIDENCE:91
*** CANONICAL_OWNER:0000I8
*** RECONSTRUCTABLE:TRUE
*** EMITTER_UIDS:0000I8
```

Rationale:

- Completion should rise from `84` to `86` because the live helper owner, no-xref sibling status, split-before-C++ rule, support-doc stale routes, local PE liveness check, and no-code proof are now resolved.
- Confidence should rise from `90` to `91` because local PE scans independently confirm the direct-call and no-xref facts already recorded by prior live IDA docs. It should remain below final because source names, original declarations, and final split/code form are not recovered.
- Keep owner/emitter as [UID:0000I8] while the page remains unsplit. If child pages are created later, convert the aggregate to a non-emitting container or leave it as a source-island index according to by-structure rules at that time.

## Exact Coverage Row Replacement

Do not edit `by-memory/-coverage-report.md` directly. If the score/support recommendation is accepted, replace the existing [UID:00021S] row in low-to-high address order with:

```markdown
    - [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) 0x004877d0-0x00488594 | packet-handler cluster | ClanStatusPacketDialogHandlers : reconstructable : 86% : strong : B013 source-quality recheck resolves the three live dispatcher-called helpers as `ClanStatusPane` packet/view handlers, keeps the no-xref dialog opener siblings as retained `Clan.cpp` file-local helper bodies, confirms direct rel32 calls only at `0x00484fdb`, `0x00484fec`, and `0x00485181`, confirms zero exact-start VA/RVA pointer hits for the helper starts in the local PE, documents opcode `0x43` subtype/action semantics, child-pane fields `+0xf8/+0xfe/+0x2510/+0x2514/+0x2518`, wide scratch-buffer use at `0x0067adf0`, dispatcher inline-branch relationship, and the no-aggregate-C++ proof; formal C++ requires method-level child pages or an explicit final source-shape decision.
```

## Recommended Support Changes

For [UID:00021S], replace the three `ClanEnlistInputDialog::...` roles in the range table with:

```text
`0x004877d0-0x004879d8` | `0x004877d0` | `ClanStatusPane::HandleClanEnlistRequestPacket` | Dispatch case `1`; decodes a clan name plus request text, writes the long text through the global wide scratch buffer, copies the heading to `+0xfe`, and switches the status pane to info child view `2`.
`0x004879e0-0x00487c37` | `0x004879e0` | `ClanStatusPane::HandleClanJoinListPacket` | Dispatch case `2`; accepts only action `0`, decodes a heading and counted clan-name list into `m_joinListPane` at `+0x2514`, then switches to view `3`.
`0x00487ea0-0x00488167` | `0x00487ea0` | `ClanStatusPane::HandleClanMemberListOrEnlistDialogPacket` | Dispatch case `6`; action `0` fills `m_enlistListPane` at `+0x2518` and switches to view `4`, action `1` opens `ClanEnlistInputDialog`, and action `2` is accepted with no dialog.
```

For [UID:00002B] `ClanEnlistInputDialog`, remove the three [UID:00021S] method rows from the method table and add this evidence note:

```text
[UID:00021S] subranges `0x004877d0`, `0x004879e0`, and `0x00487ea0` are related clan status packet handlers, not direct `ClanEnlistInputDialog` methods. Current dispatcher and field-offset evidence shows they receive the adjusted `ClanStatusPane` object and mutate `m_currentClanStatusView`, `m_statusHeaderText`, `m_infoListPane`, `m_joinListPane`, and `m_enlistListPane`. `0x00487ea0` action `1` constructs `ClanEnlistInputDialog`, which is why this class remains a callee/constructed dialog in that flow.
```

For [UID:0000IA] `ClanDialogs`, replace the `ClanEnlistInputDialog` candidate-contents role text with:

```text
Enlistment attribute dialog raw constructor and submit path. [UID:00021S] action `1` at `0x00487ea0` constructs this dialog, but the packet handlers at `0x004877d0`, `0x004879e0`, and `0x00487ea0` are `ClanStatusPane`/`social/Clan.cpp` packet-view helpers rather than `ClanDialogs.cpp` ownership targets.
```

For [UID:00002K] `ClanStatusPane`, add a method/evidence note linking the three live subranges as child packet helpers:

```text
[UID:00021S] contains three live dispatcher-called `ClanStatusPane` packet helper bodies: `0x004877d0` for subtype `1` info/request text, `0x004879e0` for subtype `2` join-list data, and `0x00487ea0` for subtype `6` enlist/member-list or enlist-dialog open behavior. They share the same child-view configuration pattern as `ShowInfoList`, `ShowJoinList`, and `ShowEnlistList`, but are currently documented in one mixed helper island until method-level child pages are created.
```

For [UID:0000I8] `Clan`, update the `ClanEnlistInputDialog` row so it no longer implies ownership of the three packet handlers:

```text
`ClanEnlistInputDialog` owns its raw constructor [UID:00021W] and submitter [UID:0002O3]. [UID:00021S] action `1` at `0x00487ea0` constructs this dialog, but the live packet handlers inside [UID:00021S] are `ClanStatusPane` packet/view helpers; the no-xref opener siblings remain retained `Clan.cpp` file-local helpers.
```

## Final Recommendation

- Exact changes applied: created this research report only.
- Exact parent assignments recommended: keep [UID:00021S] aggregate owner/emitter [UID:0000I8] until split; if split, assign the three live handler child pages to [UID:00002K] and the no-xref opener child pages to [UID:0000I8].
- Exact items left no-owner/non-emitting: none.
- Exact future work outside this report: supervisor or an A/C agent should update [UID:00021S], [UID:00002B], [UID:00002K], [UID:0000IA], and [UID:0000I8] with the support text above; apply the coverage row; optionally schedule a method-level child split before any C++ entry.

## Follow-Up Actions

- Supervisor actions: apply support-text changes and exact coverage row if accepted; do not insert aggregate C++ for [UID:00021S].
- A-agent actions: if assigned the split, create child pages for all twelve function bodies, preserve ignored padding rows, route the three live helpers to `ClanStatusPane`, and keep no-xref opener helpers as retained `Clan.cpp` helpers unless stronger evidence appears.
- B013 future research actions: if the supervisor wants formal C++, perform or review the child split before drafting code.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high for `86/91`.
- Remaining uncertainty: original symbol names, exact source declarations for no-xref opener helpers, event/payload type names, packet enum names, and whether final source keeps dialog classes in `Clan.cpp` or later commits a `ClanDialogs.cpp` split.

## Validator Results

- Commands run: none.
- Results: no validation needed because no by-* or generated documentation files were edited.
- IDA MCP result: initialize/tools-list attempts failed with `Unable to connect to the remote server`; local PE/Capstone checks were used for current-session binary validation.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B013/research/00021S-ClanStatusPacketDialogHandlers-source-quality.md`
- Modified: none outside this report.
- Leases used: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00021S-ClanStatusPacketDialogHandlers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00021S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
