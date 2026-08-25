** TARGET-REPORT-UID:0003G4 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G4 **
# 0003G4 SharedReconnectWideString Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0003G4] `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` reconstructable but parent-blank.
- Final disposition: no split, no rename, no new shared source owner, no `AUTOGEN_PARENT_UID`; recreate `L"Reconnect"` at each real prompt-construction use site instead of modeling the pooled `.rdata` address as a standalone global.
- Required action: do not assign this child to `ReconnectDialog`, `TerminalPane`, `AlertPanes`, a class page, or a new shared-label file. Recommended supervisor-only evidence refresh is listed in `Follow-Up Actions`.
- Confidence: `89/94` for the no-parent/no-split decision. Live IDA MCP confirms the exact target bytes, the paired `Leave`/`Reconnect` xref set, negative interior/start-table checks, and the unrelated nature of the later `kServerReconnect` suffix.

## Supporting Research

## Target
- Target UID: `0003G4`.
- Target path: `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`.
- Source queue/report row: active `Supervisor_notes.md`, Batch `B001-0003G4`; `auto-generated/-ag-memory-coverage.md` reports the item as `unassigned`.
- Current supervisor classification: `reviewed-85-but-ownership-unknown-under-review`.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, blank `AUTOGEN_PARENT_UID`, blank C++.
- Target range: `0x00622f28-0x00622f3c`, 20 bytes, UTF-16LE `Reconnect`.

## Executive Recommendation

Keep the physical `0x00622f28` `Reconnect` literal parent-blank. It is a source-authored button label, but the one physical `.rdata` occurrence is shared by two real source families:

- `ReconnectDialog.cpp` / `ConnectionClosedDialog` paths use it at three sites.
- `TerminalPane.cpp` uses it once from `TerminalPane::OnDisconnect`.

The literal is always paired with [UID:0003G3] `SharedLeaveWideString` at the same four prompt-construction sites. A single `AUTOGEN_PARENT_UID` would overclaim the pooled memory cell for one source family and incorrectly route the other source family's legitimate local literal use through that parent. The final source should write ordinary prompt labels at the call sites and allow the compiler/linker to pool or duplicate them.

No split is needed. The current range is already the exact atomic UTF-16LE `Reconnect` literal. The interior IDA name `aConnect` at `0x00622f2c` has no xrefs and is an artifact of IDA decoding a UTF-16 string at the wrong offset.

## Supervisor Active Recheck
- Triggering instruction: Batch `B001-0003G4` asked for deeper ownership/source-family research after A003 Batch 329 raised the child to `88/93` but left the parent blank because `ReconnectDialog` and `TerminalPane` both clear the strict gate and both use the pooled `Reconnect` literal.
- Split repair required: no. The target is already an exact child of [UID:0003CW] `ReconnectTerminalCopyStringTailMap`.
- Source-bearing child status: [UID:0003G4] remains source-authored/reconstructable. Its containing map and siblings are already split; no related child/parent repair is required before this recommendation.

## Inference Research Guidance Check
- `by-structure.md` requires `AUTOGEN_PARENT_UID` to be the true direct semantic owner, not the highest-count consumer.
- `by-structure.md` also treats string literals as source-authored/source-declared data, but for pooled string literals the source text should be recreated at the semantic use sites rather than as an address-owned global.
- `inference_research.md` warns that address adjacency and pooled constants are weak source-file evidence without xref, metadata, local/static, initializer, or table evidence.
- Existing docs were treated as hypotheses. The target page, sibling [UID:0003G3], containing map [UID:0003CW], `ReconnectDialog`, `TerminalPane`, `AlertPanes`, and the later `0x006288b0` spelling were independently checked against live IDA MCP evidence.

## Evidence Standards Used
- Live IDA MCP on 2026-06-12 against database/session `b001_nexustk`: `server_health`, `get_bytes`, `xrefs_to`, `find_bytes`, `get_string`, `entity_query`, `trace_data_flow`, and `analyze_function`.
- Documentation evidence: target page [UID:0003G4], sibling [UID:0003G3], containing map [UID:0003CW], aggregate [UID:000269], `ReconnectDialog` [UID:0000N0], `TerminalPane` [UID:0000OI], `TerminalPaneReconnectLeaveCallback` [UID:0001JD], `AlertPanes` [UID:0000HE], and `DialogOkButtonString` [UID:0001OC] as a shared-label contrast.
- Negative evidence: no xrefs to interior `0x00622f2c`, no ASCII `Reconnect` spelling, no RVA-form refs, no xrefs or pointer hits to the later `kServerReconnect` spelling, and no shared declaration/table/global that owns the physical target cell.

## IDA MCP Facts

### Function/range facts
- `server_health` reported `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready.
- `get_bytes 0x00622f1c size 56` returned the complete containing string tail:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00
59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
```

This decodes as UTF-16LE `Leave\0`, UTF-16LE `Reconnect\0`, UTF-16LE `No\0` plus padding, UTF-16LE `Yes\0`, and ANSI `baram\0` plus padding.

### Data/table/padding facts
- The exact target bytes are one complete UTF-16LE literal:

```text
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
```

- `get_string` demonstrates IDA's current typing is wrong for this island: `0x00622f28` reads as `"R"` and `0x00622f2c` reads as `"connect"`.
- `entity_query names 0x00622f10-0x00622f60` lists false/interior names such as `aAve` and `aConnect`, plus neighboring `CopyWindow` and `Region` data. These names are decode artifacts around UTF-16 data and vtable boundaries, not source-owner proof.
- `entity_query strings regex Reconnect|connect` in `.rdata` does not list the UTF-16 target because IDA's string cache misses this wide literal. It lists unrelated ASCII socket/error strings such as `already connected` and `connection reset`.

### Second-spelling facts at `0x006288b0`
- Full UTF-16LE `Reconnect\0` occurs at `0x00622f28` and `0x006288b0`.
- The later occurrence is not another standalone button-label child. `get_bytes 0x00628840 size 192` shows a mostly zero block with UTF-16LE `kServerReconnect\0` beginning at `0x006288a2`; the `0x006288b0` `Reconnect` bytes are only its suffix.
- `get_string` reads `0x006288a2` as `"k"` and `0x006288b0` as `"R"`, again showing IDA's UTF-16 typing is unreliable.
- `xrefs_to 0x006288a0`, `0x006288a2`, `0x006288a4`, `0x006288b0`, and `0x006288b4` all return zero xrefs.
- Absolute pointer/immediate searches for nearby starts `0x00628800`, `0x00628810`, `0x00628820`, `0x00628830`, `0x00628840`, `0x00628850`, `0x00628860`, `0x00628870`, `0x00628880`, `0x00628890`, `0x006288a0`, `0x006288a2`, `0x006288c0`, `0x006288d0`, `0x006288e0`, and `0x006288f0` return no matches.
- RVA-form patterns for `0x006288a2` and `0x006288b0` also return no matches.
- Decision: this later spelling is negative context only. It does not prove a source owner for [UID:0003G4], and it should not be merged with or used to rename the target.

### Xref facts
- `xrefs_to 0x00622f28` returns exactly four xrefs:
  - `0x00553c44` inside `sub_553C10`, current `ConnectionClosedDialog` constructor variant documentation [UID:00023O].
  - `0x00553cf4` inside `sub_553CC0`, current `ConnectionClosedDialog` method cluster documentation [UID:00038J].
  - `0x0055435e` inside `sub_554210`, current `ReconnectDialog::OnButtonClick` candidate documentation [UID:00038L].
  - `0x0058b5b1` inside `sub_58B470`, current `TerminalPane::OnDisconnect` documentation [UID:0001JB] and callback child [UID:0001JD].
- `xrefs_to 0x00622f2c` returns zero xrefs. The false interior `aConnect` suffix does not need its own child or owner.
- `xrefs_to 0x00622f1c` returns the same four paired sites for sibling `SharedLeaveWideString`.
- `trace_data_flow 0x00622f28 backward max_depth=2` reaches the four `Reconnect` xrefs and then the adjacent paired `Leave` pushes at `0x00553c3f`, `0x00553cef`, `0x00554359`, and `0x0058b5ac`.

### Pattern-search facts
- Full UTF-16LE `Reconnect\0` pattern `52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00`: two matches, `0x00622f28` and `0x006288b0`.
- UTF-16LE `Reconnect` without terminator: the same two matches.
- ASCII `Reconnect\0` pattern `52 65 63 6f 6e 6e 65 63 74 00`: zero matches.
- Absolute little-endian VA `0x00622f28` pattern `28 2f 62 00`: exactly four operand-byte hits at `0x00553c45`, `0x00553cf5`, `0x0055435f`, and `0x0058b5b2`.
- Interior `0x00622f2c` pattern `2c 2f 62 00`: zero matches.
- RVA-form `0x00222f28` pattern `28 2f 22 00`: zero matches.
- `kServerReconnect\0` full UTF-16 pattern beginning with `6b 00 53 00 ...`: one match at `0x006288a2`, with no pointer/RVA references.

### Function ownership facts
- `analyze_function 0x00553c10`: decompilation calls `sub_49FEB0(v2, dword_67A740, &off_622F28, &off_622F1C)`, writes `dword_67AB54`, and installs `ConnectionClosedDialog` vtables.
- `analyze_function 0x00553cc0`: decompilation calls `sub_49FEB0(v3, a2, &off_622F28, &off_622F1C)`, writes `dword_67AB54`, and installs `ConnectionClosedDialog` vtables.
- `analyze_function 0x00554210`: reconnect-button logic formats/sends `"baram"` on one branch. On the replacement connection-closed path it calls `sub_49FEB0(v8, dword_67A740, &off_622F28, &off_622F1C)` before installing `ConnectionClosedDialog` vtables.
- `analyze_function 0x0058b470`: `TerminalPane::OnDisconnect` builds a callback object, stores callback target `sub_58B620` at `0x0058b56d`, then calls `sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C)`.
- `analyze_function 0x0058b620`: callback dispatch calls `sub_5975E0(0,0,0,0)` for reconnect/nonzero and `sub_464E40()` for leave/zero. The callback has no direct callers, only the callback-pointer store from `0x0058b56d`.

### Negative IDA facts
- No xrefs to the false interior address `0x00622f2c`.
- No extra absolute or RVA-form references to `0x00622f28` beyond the four expected absolute operand hits.
- No ASCII `Reconnect` spelling.
- No xrefs or pointer hits to the later `kServerReconnect` string start or suffix.
- No IDA-recognized independent table/global/source declaration that owns the target string cell.
- No evidence that `TerminalPane::OnDisconnect` delegates its prompt to `ReconnectDialog`; it constructs its own callback-backed prompt.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f28-0x00622f3c` | [UID:0003G4] `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` | Pooled UTF-16LE `Reconnect` label | `TRUE` | blank | `88/93` current; `89/94` recommended | Keep unassigned |
| `0x00622f1c-0x00622f28` | [UID:0003G3] `SharedLeaveWideString` | Pooled UTF-16LE `Leave` label paired with `Reconnect` | `TRUE` | blank | `89/94` after accepted B001 report | Same ownership pattern |
| `0x00622f3c-0x00622f44` | [UID:0003G5] `CopyWindowNoButtonWideString` | `CopyWindow` `No` label | `TRUE` | [UID:000039] `CopyWindow` | documented | Assigned; not a candidate for `Reconnect` ownership |
| `0x00622f44-0x00622f4c` | [UID:0003G6] `CopyWindowYesButtonWideString` | `CopyWindow` `Yes` label | `TRUE` | [UID:000039] `CopyWindow` | documented | Assigned; not a candidate for `Reconnect` ownership |
| `0x00622f4c-0x00622f54` | [UID:0003G7] `SharedBaramPacketLiteral` | ANSI `baram` packet literal | `TRUE` | blank | `88/93` | Shared reconnect/terminal packet literal |
| `0x00622f1c-0x00622f54` | [UID:0003CW] `ReconnectTerminalCopyStringTailMap` | Mixed-owner string island | `FALSE` | blank | `89/93` | Correct non-emitting container |
| `0x006288a2` suffix at `0x006288b0` | no current by-memory page | Unreferenced UTF-16 `kServerReconnect` string/suffix | unknown/not in this target | none | undocumented | Negative context only |
| `0x00553c10-0x00553cbf` | [UID:00023O] `ConnectionClosedDialogConstructorVariant` | Constructor variant using labels | `TRUE` | [UID:0000N0] | `82/86` | Reconnect source-family use |
| `0x00553cc0-0x00553e5b` | [UID:00038J] `ConnectionClosedDialogMethods` | Constructor/method cluster using labels | `TRUE` | [UID:000036] | `86/89` | Reconnect source-family use |
| `0x00553f40-0x005544b8` | [UID:00038L] `ReconnectDialogMethods` | Reconnect/cancel flow using labels | `TRUE` | [UID:0000BR] | `86/89` | Reconnect source-family use |
| `0x0058af50-0x0058c350` | [UID:0001JB] `TerminalPaneAndSetup` | Terminal-pane code including prompt construction | `TRUE` | [UID:0000OI] | `85/86` | Terminal source-family use |
| `0x0058b620-0x0058b64f` | [UID:0001JD] `TerminalPaneReconnectLeaveCallback` | Callback installed by `TerminalPane::OnDisconnect` | `TRUE` | [UID:0000OI] | `85/91` | Confirms TerminalPane's independent prompt path |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00553c44` | `sub_553C10` pushes/passes `&off_622F28`; `0x00553c3f` pairs `&off_622F1C` | `ConnectionClosedDialog` constructor variant creates a reconnect/leave alert |
| `0x00553cf4` | `sub_553CC0` pushes/passes `&off_622F28`; `0x00553cef` pairs `&off_622F1C` | Alternate `ConnectionClosedDialog` constructor path creates the same label pair |
| `0x0055435e` | `sub_554210` pushes/passes `&off_622F28`; `0x00554359` pairs `&off_622F1C` | `ReconnectDialog::OnButtonClick` replacement connection-closed path creates the same prompt |
| `0x0058b5b1` | `sub_58B470` pushes/passes `&off_622F28`; `0x0058b5ac` pairs `&off_622F1C` | `TerminalPane::OnDisconnect` creates a callback-backed reconnect/leave prompt |
| `0x0058b56d` | Stores callback target `sub_58B620` into callback object | Proves TerminalPane owns its prompt callback path, separate from `ReconnectDialog` |
| `0x0058b620` | Callback target calls reconnect helper or application shutdown helper | Confirms the label text matches one of TerminalPane's two prompt choices |

## Documentation Evidence And IDA Status

### Existing docs that support the conclusion
- [UID:0003G4] already records exact bytes, four xrefs, separate later spelling, and parent-blank status. Live IDA MCP confirmed the xref and byte facts and clarified the later spelling as an unreferenced `kServerReconnect` suffix.
- [UID:0003G3] was accepted/executed from B001-0003G3 with the same no-parent pooled-literal logic for the paired `Leave` label.
- [UID:0003CW] correctly treats the tail as a `RECONSTRUCTABLE:FALSE` mixed map whose exact children carry source literal evidence.
- [UID:0000N0] `ReconnectDialog` clears the strict gate and owns three of four use sites, but its own docs also separate mixed children and do not cover `TerminalPane::OnDisconnect`.
- [UID:0000OI] `TerminalPane` clears the strict gate and owns the one terminal prompt/callback use. [UID:0001JD] confirms the prompt installs a TerminalPane callback.
- [UID:0000HE] `AlertPanes` owns generic alert classes, and explicitly keeps feature-specific reconnect alerts with feature modules unless xrefs prove common alert-helper source ownership.
- [UID:0001OC] `DialogOkButtonString` is the useful contrast: it has 88 data references and attaches to `AlertPanes`; [UID:0003G4] has four feature-specific refs split between two source families.

### Existing docs that are stale, incomplete, or contradicted
- The target page's statement that a second `Reconnect` spelling exists is correct but incomplete. B001 adds that this occurrence is the suffix of unreferenced `kServerReconnect` at `0x006288a2`, not a second standalone prompt label and not a target-owner lead.
- IDA labels `off_622F28` and `aConnect` should continue to be treated as decoding artifacts, not source names.
- No current split or parent repair is required.

### Generated/coverage report state
- `auto-generated/-ag-memory-coverage.md` currently reports [UID:0003G4] as `unassigned`, which is the correct autogen state.
- `by-memory/-coverage-report.md` currently has a `0003G4` row immediately after accepted `0003G3`. A replacement row is provided below.
- No direct edit was made to `by-memory/-coverage-report.md`.

## Ranked Ownership Analysis

### 1. Parent-blank pooled source literal - accepted
- Evidence for:
  - The target is one complete UTF-16LE `Reconnect` literal.
  - It has exactly four absolute-immediate references, paired with [UID:0003G3] `Leave`.
  - The four use sites split across `ReconnectDialog`/`ConnectionClosedDialog` and `TerminalPane::OnDisconnect`.
  - Two distinct source-file roots clear the strict gate: [UID:0000N0] `ReconnectDialog` for three refs and [UID:0000OI] `TerminalPane` for one ref.
  - The later `Reconnect` bytes are not another prompt label; they are an unreferenced suffix in `kServerReconnect`.
  - String pooling explains the single physical prompt-label address better than any sole owner.
- Evidence against:
  - Rebuild still needs the string text; blank parentage should not be misunderstood as ignorable data.
- Decision:
  - Accepted. Keep the memory item reconstructable but unassigned; spell the label at each real source use site.

### 2. [UID:0000N0] `ReconnectDialog` - best if forced, rejected
- Evidence for:
  - Three of four refs are in `ConnectionClosedDialog` and `ReconnectDialog` code.
  - The label text is semantically central to the reconnect/connection-closed UI.
  - `ReconnectDialog` clears `87/88` and owns the related singleton globals and method clusters.
- Evidence against:
  - `TerminalPane::OnDisconnect` directly consumes the same physical label at `0x0058b5b1`.
  - The TerminalPane path builds its own callback object and callback-backed prompt. It does not delegate this prompt to a `ReconnectDialog` method.
  - Routing the pooled address to `ReconnectDialog` would misplace the TerminalPane source literal.
- Decision:
  - Rejected. It is the best-if-forced candidate by xref count and semantics, but it is not the direct owner of the full physical pooled literal.

### 3. [UID:0000OI] `TerminalPane` - rejected
- Evidence for:
  - `TerminalPane` clears `87/85`.
  - Its use is direct and strongly documented: `TerminalPane::OnDisconnect` builds the prompt and installs `TerminalPaneReconnectLeaveCallback`.
  - The callback branch semantics align with the prompt labels.
- Evidence against:
  - Only one of four direct target refs is TerminalPane-owned.
  - The three reconnect/connection-closed uses are separate source-family code.
- Decision:
  - Rejected. It proves shared use and blocks `ReconnectDialog` ownership, but it is not sole owner.

### 4. [UID:0000HE] `AlertPanes` / generic alert labels - rejected
- Evidence for:
  - The TerminalPane path uses callback-backed alert infrastructure through `sub_4A0690`.
  - `AlertPanes` owns reusable alert classes and clears `85/88`.
  - A truly broad shared dialog label such as [UID:0001OC] `OK` can attach to `AlertPanes`.
- Evidence against:
  - `Reconnect` has four feature-specific direct refs, not an 88-ref broad dialog-button fan-in.
  - `AlertPanes.md` explicitly excludes feature-specific reconnect alerts from generic alert ownership.
  - The reconnect/connection-closed constructor paths consume alert infrastructure but remain feature-source code.
- Decision:
  - Rejected. `AlertPanes` owns generic alert implementation, not this feature-specific pooled prompt label.

### 5. Class-level candidates - rejected
- Evidence for:
  - [UID:000036] `ConnectionClosedDialog`, [UID:0000BR] `ReconnectDialog`, and [UID:0000EG] `TerminalPane` each cover part of the xref set.
- Evidence against:
  - No class covers all four xrefs.
  - The physical item is a pooled literal, not class vtable data, member storage, or a class-static object.
- Decision:
  - Rejected. Class ownership would be narrower but still wrong for the complete physical range.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path considered:
  - `NexusTK/network/ReconnectTerminalLabels.cpp`
  - `NexusTK/login/SessionRecoveryLabels.cpp`
  - `NexusTK/ui/dialogs/SharedDialogLabels.cpp`
  - a by-global `ReconnectLeaveButtonLabels` or `g_reconnectPromptLabels`
- Likely full contents if such a file existed:
  - `L"Reconnect"` [UID:0003G4].
  - `L"Leave"` [UID:0003G3].
  - Possibly ANSI `baram` [UID:0003G7] only if the grouping represented session recovery/packet text rather than dialog labels.
  - Not `No`/`Yes` [UID:0003G5]/[UID:0003G6], which are proven `CopyWindow` labels.
  - Not `kServerReconnect` at `0x006288a2`; it has no xrefs and no documented source family.
- Candidate related items rejected:
  - [UID:0003G3]/[UID:0003G4] are ordinary prompt literals with no table, initializer, symbol, broad xref fan-in, or addressable shared declaration.
  - [UID:0003G7] is a related shared packet literal but has the same no-single-owner problem.
  - `0x006288a2` `kServerReconnect` has no xrefs/pointer hits, so it cannot support a source family here.
- Standalone, narrow, or broad source-file inference:
  - Rejected as a false source artifact. The evidence supports compiler/linker literal pooling, not a hand-authored shared constants module.

## Negative Evidence Summary
- Checked direct xrefs to target start, sibling `Leave`, target interior `aConnect`, later `kServerReconnect` start, and later suffix. Only the target and paired `Leave` starts have the expected four refs.
- Checked full UTF-16, non-terminated UTF-16, ASCII, absolute VA, and RVA-form byte patterns. The target has four absolute operand hits and no RVA hits; the later `kServerReconnect` region has no pointer/RVA hits.
- Checked surrounding starts in the `0x00628840-0x00628900` neighborhood for table-base references. None were found.
- Checked candidate parents. `ReconnectDialog` and `TerminalPane` each own real call sites, but neither owns all use sites; `AlertPanes` owns generic alert infrastructure, not this feature-specific label.
- Checked whether a new shared-label owner would have plausible contents. The only plausible contents are ordinary literals already explained by pooling, with no binary evidence for a shared declaration.

## Final Recommendation
- Exact changes applied:
  - Created this research report only.
  - No by-* target documentation was edited.
  - No coverage report was edited.
- Exact parent assignments recommended:
  - Leave `AUTOGEN_PARENT_UID` blank on [UID:0003G4].
  - Leave `AUTOGEN_PARENT_POSITION_OPTIONAL` blank.
  - Leave `RECONSTRUCTION_CPP CODE` blank.
- Exact items left unassigned and why:
  - [UID:0003G4] remains unassigned because it is one physical pooled UTF-16 prompt label with legitimate source use in both `ReconnectDialog` and `TerminalPane`.
  - [UID:0003G3] and [UID:0003G7] should continue following the same shared-use logic unless future source/debug/map evidence proves a real shared declaration.
- Exact future work outside this assignment:
  - Final C++ call-site reconstruction for `ConnectionClosedDialog`, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect` should spell `L"Reconnect"` naturally at the semantic use sites.
  - The unreferenced `kServerReconnect` block around `0x006288a2` may be documented later as part of a broader `.rdata` coverage effort, but it does not need to block or alter [UID:0003G4].

## Follow-Up Actions

### Supervisor actions
1. Keep the autogen row unassigned. No parent assignment is recommended:

```text
| [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | unassigned |  |  | no |  | `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` |  |
```

2. Recommended target-page metadata refresh, if applying the B001 evidence update:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

3. Recommended target-page change-log text to append to `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` if applying the metadata refresh:

```text
- 2026-06-12 Agent-B001 Batch B001-0003G4: Performed ownership/source-family audit. Live IDA MCP against `b001_nexustk` reconfirmed exact UTF-16LE `Reconnect` bytes, exactly four absolute-immediate consumers paired with [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md), zero refs to false interior `aConnect` at `0x00622f2c`, no ASCII spelling, no RVA-form refs, and no additional referenced standalone `Reconnect` prompt. The later `0x006288b0` spelling was proven to be the unreferenced suffix of `kServerReconnect` at `0x006288a2`, not an owner lead. `ReconnectDialog`, `TerminalPane`, `AlertPanes`, class-level parents, and a new shared-label/source owner were ranked and rejected as overclaiming pooled literal ownership. Parent remains blank; final source should spell `L"Reconnect"` at each semantic use site.
```

4. Recommended `by-memory/-coverage-report.md` replacement row. Replace the existing `0003G4` row immediately after the accepted [UID:0003G3] row and before [UID:0003G5]:

```text
            - [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) 0x00622f28-0x00622f3c | string-data | SharedReconnectWideString : reconstructable : 89% : very strong : UTF-16LE `Reconnect` button label; B001-0003G4 live IDA MCP confirmed exact bytes, exactly four absolute-immediate consumers paired with [UID:0003G3][0x00622f1c-0x00622f28.SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) from `ConnectionClosedDialog` constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`, zero refs to false interior `aConnect` at 0x00622f2c, no ASCII spelling, no RVA-form refs, and no referenced second prompt spelling; later `0x006288b0` is only the unreferenced suffix of UTF-16 `kServerReconnect` at `0x006288a2`; parent remains blank because [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md), [UID:0000HE][AlertPanes](by-file/AlertPanes.md), class-level parents, and a new shared-label owner were all rejected as overclaiming pooled literal ownership.
```

### A-agent actions
- No split repair is needed for this target.
- When reconstructing the call-site pages, preserve natural source literals at each prompt-construction site instead of introducing a global `Reconnect` constant solely to match pooled `.rdata`.

### B001 future research actions
- None for [UID:0003G4] unless future source/debug/map evidence appears.
- If the unreferenced `kServerReconnect` neighborhood later appears in memory-range fallback work, document it separately from this prompt-label child.

## Confidence
- Recommendation confidence: `94`. Direct bytes, xrefs, data-flow trace, pattern searches, function decompilation, and documentation all agree.
- Score confidence: `89/94` is justified if the supervisor applies the evidence refresh. It stays below `95+` because final source reconstruction has not audited every dependent call-site body to final C++ quality, and stripped-binary evidence cannot prove exact original literal spelling versus local helper usage.
- Remaining uncertainty:
  - Whether original source wrote `L"Reconnect"` separately at every call site or used a local helper/constant inside one feature file cannot be proven from the stripped binary alone.
  - That uncertainty does not justify a parent assignment because no direct shared declaration, sole owner, or table object is present.

## Validator Results
- Command run during this B001 pass on the current target:

> Executable block R001 was removed from this report and preserved verbatim in [0003G4-SharedReconnectWideString-B001-0003G4-removed.md](0003G4-SharedReconnectWideString-B001-0003G4-removed.md). The archived block is non-authoritative and must not be executed.

- Result: target file scanned successfully in dry-run mode; UID header exists; file reported `ok`.
- No validator command was required for this report file itself.
- No unresolved validator warnings/errors are introduced by this research report.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/0003G4-SharedReconnectWideString-B001-0003G4.md`.
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none. Supervisor owns report execution and archival.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G4","source_path":"executed-b-agent-research/B001/0003G4-SharedReconnectWideString-B001-0003G4.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
