** TARGET-REPORT-UID:0003G3 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G3 **
# 0003G3 SharedLeaveWideString Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0003G3] `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` reconstructable but parent-blank.
- Final disposition: no split, no rename, no new source owner, no `AUTOGEN_PARENT_UID`; recreate `L"Leave"` at each real source use site instead of modeling the physical pooled `.rdata` address as a standalone global.
- Required action: do not assign this child to `ReconnectDialog`, `TerminalPane`, `AlertPanes`, a class page, or a new shared-label file. Recommended supervisor-only evidence refresh is listed in `Follow-Up Actions`.
- Confidence: `89/94` for the no-parent/no-split ownership decision. The direct binary facts are stronger than the current `88/93` page score, but final source spelling and call-site source cleanup are still below the `95+` final-audit gate.

## Supporting Research

## Target
- Target UID: `0003G3`.
- Target path: `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`.
- Source queue/report row: active `Supervisor_notes.md`, Batch `B001-0003G3`; `auto-generated/-ag-memory-coverage.md` reports the item as `unassigned`.
- Current supervisor classification: `reviewed-85-but-ownership-unknown-under-review`.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, blank `AUTOGEN_PARENT_UID`, blank C++.
- Target range: `0x00622f1c-0x00622f28`, 12 bytes, UTF-16LE `Leave`.

## Executive Recommendation

The best source-reconstruction result is to keep the physical pooled literal unassigned and document it as a source-authored string literal reused by two source families:

- `ReconnectDialog.cpp` / `ConnectionClosedDialog` paths use the literal at three code sites.
- `TerminalPane.cpp` uses the same physical literal once from `TerminalPane::OnDisconnect`.

That makes the literal reconstructable but not directly owned by any one existing parent. A single `AUTOGEN_PARENT_UID` would misrepresent the source layout by routing the full physical `.rdata` object through one consumer while the other consumer also has a legitimate source-level `L"Leave"` use. The final C++ should contain ordinary local string literals at the relevant prompt construction call sites and let the compiler/linker decide whether to pool them.

No split is needed. The target is already the exact atomic UTF-16LE literal, and the interior IDA name `aAve` at `0x00622f20` is a false string start with no xrefs.

## Supervisor Active Recheck
- Triggering instruction: Batch `B001-0003G3` asked for deeper ownership/source-family research for [UID:0003G3] after A002 Batch 328 raised the child to `88/93` but left the parent blank because `ReconnectDialog` and `TerminalPane` both clear the strict gate and both use the pooled `Leave` literal.
- Split repair required: no. The exact child range already covers one complete UTF-16LE literal and is nested under [UID:0003CW] `ReconnectTerminalCopyStringTailMap`.
- Source-bearing child status: [UID:0003G3] remains source-authored/reconstructable. Its containing mixed map and siblings already have exact child pages; none need repair before this ownership recommendation.

## Inference Research Guidance Check
- `by-structure.md` requires `AUTOGEN_PARENT_UID` to be the correct direct semantic owner, not the strongest consumer or an output-routing convenience.
- `by-structure.md` also treats string literals as source-authored/source-declared data that should be recreated at real use sites when linker pooling is the explanation.
- `inference_research.md` specifically warns that nearby `.rdata` adjacency and pooled constants are weak source-file evidence unless xref clusters or metadata prove ownership.
- Existing documentation was treated as a lead, not proof. The current target page, the containing map, `ReconnectDialog`, `TerminalPane`, `AlertPanes`, and the exact executable children were checked against live IDA MCP evidence before ranking ownership.

## Evidence Standards Used
- Live IDA MCP on 2026-06-12 against database/session `b001_nexustk`: `server_health`, `get_bytes`, `xrefs_to`, `find_bytes`, `get_string`, `entity_query`, and `analyze_function`.
- Documentation evidence: target page [UID:0003G3], sibling [UID:0003G4], containing map [UID:0003CW], aggregate [UID:000269], `ReconnectDialog` [UID:0000N0], `TerminalPane` [UID:0000OI], `TerminalPaneReconnectLeaveCallback` [UID:0001JD], and `AlertPanes` [UID:0000HE].
- Negative evidence: no interior xrefs to `0x00622f20`, no ASCII `Leave` spelling, no RVA-form references to `0x00622f1c`, no broad alert infrastructure ownership signal, and no table/global source owner for the physical string cell.

## IDA MCP Facts

### Function/range facts
- `server_health` reported `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready.
- `get_bytes 0x00622f1c size 56` returned:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00
59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
```

This decodes as UTF-16LE `Leave\0`, UTF-16LE `Reconnect\0`, UTF-16LE `No\0` plus padding, UTF-16LE `Yes\0`, and ANSI `baram\0` plus padding.

### Data/table/padding facts
- The exact target bytes are one complete UTF-16LE literal: `4c 00 65 00 61 00 76 00 65 00 00 00`.
- `get_string` demonstrates IDA's current typing is wrong for this island: `0x00622f1c` reads as `"L"`, `0x00622f20` reads as `"ave"`, and `0x00622f28` reads as `"R"`.
- `entity_query names 0x00622f10-0x00622f60` lists `aAve` at `0x00622f20`, `aConnect` at `0x00622f2c`, `aNo` at `0x00622f3c`, `aBaram_0` at `0x00622f4c`, `CopyWindow` vtable data before the target, and `Region` vtable data after the string tail. These names are decode artifacts around the UTF-16 data, not independent source owners.
- `entity_query strings regex Leave|Reconnect|baram|No|Yes` in `.rdata` lists `baram` but not `Leave` or `Reconnect`, reinforcing that IDA string cache misses the UTF-16 labels.

### Xref facts
- `xrefs_to 0x00622f1c` returns exactly four xrefs:
  - `0x00553c3f` inside `sub_553C10`, current `ConnectionClosedDialog` constructor variant documentation [UID:00023O].
  - `0x00553cef` inside `sub_553CC0`, current `ConnectionClosedDialog` method cluster documentation [UID:00038J].
  - `0x00554359` inside `sub_554210`, current `ReconnectDialog::OnButtonClick` candidate documentation [UID:00038L].
  - `0x0058b5ac` inside `sub_58B470`, current `TerminalPane::OnDisconnect` documentation [UID:0001JB] and callback child [UID:0001JD].
- `xrefs_to 0x00622f20` returns zero xrefs. The false interior `aAve` string does not need its own child or owner.
- `xrefs_to 0x00622f28` returns the same four sites for sibling `SharedReconnectWideString`, proving the `Leave` and `Reconnect` labels are passed as a pair.

### Pattern-search facts
- Full UTF-16LE `Leave\0` pattern `4c 00 65 00 61 00 76 00 65 00 00 00`: one match at `0x00622f1c`.
- UTF-16LE `Leave` without terminator: one match at `0x00622f1c`.
- ASCII `Leave\0` pattern `4c 65 61 76 65 00`: zero matches.
- Absolute little-endian VA `0x00622f1c` pattern `1c 2f 62 00`: exactly four operand-byte hits at `0x00553c40`, `0x00553cf0`, `0x0055435a`, and `0x0058b5ad`.
- Interior `0x00622f20` pattern `20 2f 62 00`: zero matches.
- Sibling `0x00622f28` pattern `28 2f 62 00`: exactly four operand-byte hits at `0x00553c45`, `0x00553cf5`, `0x0055435f`, and `0x0058b5b2`.

### Function ownership facts
- `analyze_function 0x00553c10`: decompilation calls `sub_49FEB0(v2, dword_67A740, &off_622F28, &off_622F1C)`, writes `dword_67AB54`, and installs `ConnectionClosedDialog` vtables.
- `analyze_function 0x00553cc0`: decompilation calls `sub_49FEB0(v3, a2, &off_622F28, &off_622F1C)`, writes `dword_67AB54`, and installs `ConnectionClosedDialog` vtables.
- `analyze_function 0x00554210`: reconnect-button logic formats/sends `"baram"` on one branch, and on the replacement connection-closed path calls `sub_49FEB0(v8, dword_67A740, &off_622F28, &off_622F1C)` before installing `ConnectionClosedDialog` vtables.
- `analyze_function 0x0058b470`: `TerminalPane::OnDisconnect` builds a callback object, stores callback target `sub_58B620` at `0x0058b56d`, then calls `sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C)`.
- `analyze_function 0x0058b620`: callback dispatch calls `sub_5975E0(0,0,0,0)` for reconnect/nonzero and `sub_464E40()` for leave/zero. The callback has no direct callers, only the callback-pointer store from `0x0058b56d`.

### Negative IDA facts
- No xrefs to the false interior address `0x00622f20`.
- No extra absolute code/data references to `0x00622f1c` beyond the four expected operand hits.
- No ASCII spelling of `Leave`.
- No IDA-recognized independent global/table that owns the `Leave` cell.
- No evidence that `TerminalPane::OnDisconnect` calls a `ReconnectDialog` helper for its prompt; it constructs its own callback-backed `VersatileAlertPane`-style prompt.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f28` | [UID:0003G3] `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` | Pooled UTF-16LE `Leave` label | `TRUE` | blank | `88/93` current; `89/94` recommended | Keep unassigned |
| `0x00622f28-0x00622f3c` | [UID:0003G4] `SharedReconnectWideString` | Pooled UTF-16LE `Reconnect` label paired with `Leave` | `TRUE` | blank | `88/93` | Same ownership pattern |
| `0x00622f3c-0x00622f44` | [UID:0003G5] `CopyWindowNoButtonWideString` | `CopyWindow` `No` label | `TRUE` | [UID:000039] `CopyWindow` | documented | Assigned; not a candidate for `Leave` ownership |
| `0x00622f44-0x00622f4c` | [UID:0003G6] `CopyWindowYesButtonWideString` | `CopyWindow` `Yes` label | `TRUE` | [UID:000039] `CopyWindow` | documented | Assigned; not a candidate for `Leave` ownership |
| `0x00622f4c-0x00622f54` | [UID:0003G7] `SharedBaramPacketLiteral` | ANSI `baram` packet literal | `TRUE` | blank | `88/93` | Shared reconnect/terminal packet literal |
| `0x00622f1c-0x00622f54` | [UID:0003CW] `ReconnectTerminalCopyStringTailMap` | Mixed-owner string island | `FALSE` | blank | `89/93` | Correct non-emitting container |
| `0x00553c10-0x00553cbf` | [UID:00023O] `ConnectionClosedDialogConstructorVariant` | Constructor variant using labels | `TRUE` | [UID:0000N0] | `82/86` | Reconnect source-family use |
| `0x00553cc0-0x00553e5b` | [UID:00038J] `ConnectionClosedDialogMethods` | Constructor/method cluster using labels | `TRUE` | [UID:000036] | `86/89` | Reconnect source-family use |
| `0x00553f40-0x005544b8` | [UID:00038L] `ReconnectDialogMethods` | Reconnect/cancel flow using labels | `TRUE` | [UID:0000BR] | `86/89` | Reconnect source-family use |
| `0x0058af50-0x0058c350` | [UID:0001JB] `TerminalPaneAndSetup` | Terminal-pane code including prompt construction | `TRUE` | [UID:0000OI] | `85/86` | Terminal source-family use |
| `0x0058b620-0x0058b64f` | [UID:0001JD] `TerminalPaneReconnectLeaveCallback` | Callback installed by `TerminalPane::OnDisconnect` | `TRUE` | [UID:0000OI] | `85/91` | Confirms TerminalPane's independent prompt path |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00553c3f` | `sub_553C10` pushes/passes `&off_622F1C`; `0x00553c44` pairs `&off_622F28` | `ConnectionClosedDialog` constructor variant creates a reconnect/leave alert |
| `0x00553cef` | `sub_553CC0` pushes/passes `&off_622F1C`; `0x00553cf4` pairs `&off_622F28` | Alternate `ConnectionClosedDialog` constructor path creates the same label pair |
| `0x00554359` | `sub_554210` pushes/passes `&off_622F1C`; `0x0055435e` pairs `&off_622F28` | `ReconnectDialog::OnButtonClick` replacement connection-closed path creates the same prompt |
| `0x0058b5ac` | `sub_58B470` pushes/passes `&off_622F1C`; `0x0058b5b1` pairs `&off_622F28` | `TerminalPane::OnDisconnect` creates a callback-backed reconnect/leave prompt |
| `0x0058b56d` | Stores callback target `sub_58B620` into callback object | Proves TerminalPane owns its prompt callback path, separate from `ReconnectDialog` |
| `0x0058b620` | Callback target calls reconnect helper or application shutdown helper | Confirms the literal text matches the two terminal alert choices |

## Documentation Evidence And IDA Status

### Existing docs that support the conclusion
- [UID:0003G3] already states the physical bytes are a pooled UTF-16 literal used by both reconnect/connection-closed code and `TerminalPane::OnDisconnect`. Live IDA MCP confirmed the exact xref set and the false IDA string typing.
- [UID:0003G4] has the same four-owner pattern for `Reconnect`, reinforcing that the two labels are a pooled pair, not independent single-owner labels.
- [UID:0003CW] correctly treats the tail as a `RECONSTRUCTABLE:FALSE` non-emitting mixed map whose exact children carry source ownership.
- [UID:0000N0] `ReconnectDialog` clears the strict parent gate and owns the three reconnect/connection-closed uses, but its own documentation excludes the interleaved `CopyWindow` island and acknowledges source-family boundaries.
- [UID:0000OI] `TerminalPane` clears the strict parent gate and owns the terminal prompt/callback use. [UID:0001JD] documents the exact callback installed by the prompt.
- [UID:0000HE] `AlertPanes` documents reusable alert infrastructure and explicitly says feature-specific reconnect alerts should remain with feature modules unless later xrefs prove common alert-helper source ownership.

### Existing docs that are stale, incomplete, or contradicted
- No current target-doc contradiction was found. The only improvement is that B001 adds uniqueness, no-ASCII, no-interior-xref, no-RVA-form, and AlertPanes/new-owner rejection evidence.
- IDA names `off_622F1C`, `aAve`, `off_622F28`, and `aConnect` are contradicted by byte decoding and xref evidence. They should remain described as IDA artifacts, not used as source names.
- The by-memory coverage report search in this session did not find an existing `0003G3` row. If the supervisor has a generated or pending row elsewhere, the replacement row below should be used; otherwise insert it in low-to-high address order.

### Generated/coverage report state
- `auto-generated/-ag-memory-coverage.md` currently reports [UID:0003G3] as `unassigned`, which is the correct autogen state.
- No manual edit should be made to `auto-generated/-ag-memory-coverage.md`.
- No direct edit was made to `by-memory/-coverage-report.md`.

## Ranked Ownership Analysis

### 1. Parent-blank pooled source literal - accepted
- Evidence for:
  - The full UTF-16LE `Leave\0` spelling exists exactly once in the image at `0x00622f1c`.
  - The physical string has exactly four absolute-immediate references, split across reconnect/connection-closed code and TerminalPane code.
  - All four `Leave` references are paired with the sibling `Reconnect` literal.
  - Two distinct source-file roots clear the strict gate: [UID:0000N0] `ReconnectDialog` for three refs and [UID:0000OI] `TerminalPane` for one ref.
  - String pooling explains the single physical `.rdata` address better than any one-file source owner.
- Evidence against:
  - Rebuild still needs the literal text in source code. Leaving `AUTOGEN_PARENT_UID` blank does not mean the text is ignorable.
- Decision:
  - Accepted. Keep the memory item reconstructable but unassigned; spell the literal at each real source use site in final source.

### 2. [UID:0000N0] `ReconnectDialog` - best if forced, rejected
- Evidence for:
  - Three of four refs are in `ConnectionClosedDialog` and `ReconnectDialog` code.
  - The sibling `Reconnect` label and `baram` packet literal are semantically tied to reconnect/cancel behavior.
  - `ReconnectDialog` clears `87/88` and has a plausible `network/ReconnectDialog.cpp` source root.
- Evidence against:
  - One live, direct, independent `Leave` consumer is `TerminalPane::OnDisconnect` at `0x0058b5ac`.
  - `TerminalPane::OnDisconnect` constructs its own callback object and calls `sub_4A0690`; it does not simply delegate the prompt to a `ReconnectDialog` method.
  - Assigning the pooled address to `ReconnectDialog` would cause TerminalPane's real source literal use to be routed through the wrong direct owner.
- Decision:
  - Rejected. It is the strongest consumer but not the direct owner of the full physical pooled literal.

### 3. [UID:0000OI] `TerminalPane` - rejected
- Evidence for:
  - `TerminalPane` clears `87/85`.
  - The terminal use is direct and well-supported: `TerminalPane::OnDisconnect` builds the prompt and installs `TerminalPaneReconnectLeaveCallback`.
  - The callback semantics match the label pair: reconnect versus leave/shutdown.
- Evidence against:
  - Only one of the four direct refs is TerminalPane-owned.
  - The three reconnect/connection-closed uses are not TerminalPane code and have separate class/file documentation.
- Decision:
  - Rejected. TerminalPane proves shared use, not sole ownership.

### 4. [UID:0000HE] `AlertPanes` / `VersatileAlertPane` - rejected
- Evidence for:
  - The terminal path uses a callback-backed alert constructor shape through `sub_4A0690`.
  - `AlertPanes` owns reusable alert classes and clears `85/88`.
  - A broad label such as `OK` can legitimately attach to shared alert infrastructure when fan-in proves that ownership pattern.
- Evidence against:
  - `Leave` has only four direct refs and all are reconnect/terminal feature prompts.
  - The reconnect/connection-closed constructor paths use alert infrastructure but are feature-specific alerts, not alert-library declarations.
  - `AlertPanes.md` explicitly excludes feature-specific reconnect alerts unless later xrefs prove common alert-helper source ownership.
  - There is no broad constructor fan-in or general dialog-button evidence like [UID:0001OC] `DialogOkButtonString`.
- Decision:
  - Rejected. `AlertPanes` owns the generic alert classes, not this feature-specific pooled label.

### 5. Class-level candidates - rejected
- Evidence for:
  - [UID:000036] `ConnectionClosedDialog`, [UID:0000BR] `ReconnectDialog`, and [UID:0000EG] `TerminalPane` each cover part of the code that uses the literal.
- Evidence against:
  - No class covers all four xrefs.
  - The physical item is a pooled `.rdata` literal, not a vtable, member, or class-static object tied to one class declaration.
- Decision:
  - Rejected. Class-level parentage would be narrower but still wrong for the complete physical range.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path considered:
  - `NexusTK/network/ReconnectTerminalLabels.cpp`
  - `NexusTK/login/SessionRecoveryLabels.cpp`
  - `NexusTK/ui/dialogs/SharedDialogLabels.cpp`
  - a by-global `g_reconnectLeaveLabels` / `ReconnectLeaveButtonLabels` owner
- Likely full contents if such a file existed:
  - `L"Leave"` [UID:0003G3].
  - `L"Reconnect"` [UID:0003G4].
  - Possibly ANSI `baram` [UID:0003G7] if the grouping were reconnection/session recovery rather than dialog UI.
  - It should not include `No`/`Yes` [UID:0003G5]/[UID:0003G6], because those are `CopyWindow` labels with a proven class parent.
- Candidate related items rejected:
  - [UID:0003G3] and [UID:0003G4] are ordinary local button-label literals with no table object, no initializer, no address-taken metadata outside immediate call operands, and no separate symbol that would imply a hand-authored shared declaration.
  - [UID:0003G7] is an ANSI packet literal shared by reconnect and terminal flow, but the same pooling logic applies and no grouping object is present.
  - [UID:0003G5]/[UID:0003G6] are `CopyWindow` class labels and are already assigned.
- Standalone, narrow, or broad source-file inference:
  - Rejected as a false source artifact. The evidence supports linker/compiler literal pooling, not a standalone source file or shared constants module. A source file containing only a few user-facing string constants would be less plausible than ordinary literals in mid-2000s C++ UI construction code, and there is no binary evidence for an addressable string table declaration.

## Negative Evidence Summary
- Checked direct xrefs to the target start and the false interior address. The target has exactly four refs; the interior has zero.
- Checked byte patterns for full UTF-16LE `Leave`, UTF-16LE without terminator, ASCII `Leave`, target absolute VA, target interior absolute VA, and sibling absolute VA. The results support one physical UTF-16 spelling and exactly the expected absolute consumers.
- Checked IDA string/name state. IDA's current names are decode artifacts and should not drive split decisions.
- Checked the containing map and exact siblings. The range is already split to atomic child strings; only `No`/`Yes` have a single direct class owner.
- Checked `ReconnectDialog` and `TerminalPane` file pages. Both clear the gate and both are legitimate owners of their own call-site literals, but neither is sole owner of the physical pooled memory child.
- Checked `AlertPanes`. It owns reusable alert implementation, not feature-specific reconnect/terminal labels.
- Checked possible new shared-label owners. No xref, table, initializer, symbol, address-taken cluster, or source-family content supports creating one.

## Final Recommendation
- Exact changes applied:
  - Created this research report only.
  - No by-* target documentation was edited.
  - No coverage report was edited.
- Exact parent assignments recommended:
  - Leave `AUTOGEN_PARENT_UID` blank on [UID:0003G3].
  - Leave `AUTOGEN_PARENT_POSITION_OPTIONAL` blank.
  - Leave `RECONSTRUCTION_CPP CODE` blank.
- Exact items left unassigned and why:
  - [UID:0003G3] remains unassigned because it is one physical pooled UTF-16 literal with legitimate use sites in both `ReconnectDialog` and `TerminalPane`.
  - Sibling [UID:0003G4] should continue following the same logic unless a future source/debug artifact proves a shared declaration.
- Exact future work outside this assignment:
  - Final C++ call-site reconstruction for `ConnectionClosedDialog`, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect` should spell the labels naturally in those functions and let the compiler/linker pool or duplicate them.
  - If future debug/PDB/map/source evidence proves a real shared constants table, revisit [UID:0003G3], [UID:0003G4], and [UID:0003G7] together.

## Follow-Up Actions

### Supervisor actions
1. Keep the autogen row unassigned. No parent assignment is recommended:

```text
| [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | unassigned |  |  | no |  | `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` |  |
```

2. Recommended target-page metadata refresh, if applying the B001 evidence update:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

3. Recommended target-page change-log text to append to `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` if applying the metadata refresh:

```text
- 2026-06-12 Agent-B001 Batch B001-0003G3: Performed ownership/source-family audit. Live IDA MCP against `b001_nexustk` reconfirmed the exact UTF-16LE `Leave` bytes, exactly one full UTF-16 spelling, no ASCII spelling, exactly four absolute-immediate consumers, zero refs to false interior `aAve` at `0x00622f20`, and the paired `Reconnect` xref set. `ReconnectDialog`, `TerminalPane`, `AlertPanes`, class-level parents, and a new shared-label/source owner were ranked and rejected as overclaiming direct ownership of a pooled literal. Parent remains blank; final source should spell `L"Leave"` at each semantic use site.
```

4. Recommended `by-memory/-coverage-report.md` row if the supervisor wants the B001 evidence reflected there. Insert/replace in `Covered Items To Replicate` in low-to-high address order at `0x00622f1c`; do not place it under the containing map as an emitting parent:

```text
    - [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) 0x00622f1c-0x00622f28 | string-data | SharedLeaveWideString : reconstructable : 89% : very strong : UTF-16LE `Leave` button label; B001-0003G3 live IDA MCP confirmed exact bytes, exactly one UTF-16 `Leave` spelling, no ASCII spelling, no refs to false interior `aAve` at 0x00622f20, and exactly four absolute-immediate consumers paired with [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) from `ConnectionClosedDialog` constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`; parent remains blank because [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md), [UID:0000HE][AlertPanes](by-file/AlertPanes.md), class-level parents, and a new shared-label owner were all rejected as overclaiming pooled literal ownership.
```

### A-agent actions
- No A-agent split repair is needed for this target.
- When reconstructing the call-site pages, preserve natural source literals at each prompt-construction site instead of introducing a global `Leave` constant solely to match the pooled `.rdata` address.

### B001 future research actions
- None for [UID:0003G3] unless future source/debug/map evidence appears.
- The same ownership rule should be applied consistently to [UID:0003G4] `SharedReconnectWideString` and [UID:0003G7] `SharedBaramPacketLiteral` if they return to the B queue.

## Confidence
- Recommendation confidence: `94`. Direct bytes, direct xrefs, pattern search, and function-level decompilation all agree.
- Score confidence: `89/94` is justified if the supervisor applies the evidence refresh. It stays below `95+` because final source reconstruction has not audited every dependent call-site body to final C++ quality, and no original debug/source metadata proves exact source spelling or literal pooling policy.
- Remaining uncertainty:
  - Whether the original source text wrote `L"Leave"` separately at each call site or used a small local helper/constant inside one of the feature files cannot be proven from the stripped binary alone.
  - That uncertainty does not justify a parent assignment because no direct shared declaration or sole owner is present.

## Validator Results
- Command run during this B001 pass on the current target:

> Executable block R001 was removed from this report and preserved verbatim in [0003G3-SharedLeaveWideString-B001-0003G3-removed.md](0003G3-SharedLeaveWideString-B001-0003G3-removed.md). The archived block is non-authoritative and must not be executed.

- Result: target file scanned successfully in dry-run mode; UID header exists; file reported `ok`.
- No validator command was required for this report file itself.
- No unresolved validator warnings/errors are introduced by this research report.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/0003G3-SharedLeaveWideString-B001-0003G3.md`.
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none. Supervisor owns report execution and archival.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G3","source_path":"executed-b-agent-research/B001/0003G3-SharedLeaveWideString-B001-0003G3.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
