** TARGET-REPORT-UID:0003G4 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G4 **
# 0003G4 SharedReconnectWideString Post-Migration Ownership / Emitter Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G4] `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` at `CANONICAL_OWNER:NONE`, keep `RECONSTRUCTABLE:TRUE`, keep score `89/94`, keep blank reconstruction C++, keep blank `EMITTER_POSITION_OPTIONAL`, and change `EMITTER_UIDS` from blank to `0000N0,0000OI`.
- Final disposition: no canonical owner, but not non-emitting. This is a pooled UTF-16 `Reconnect` button-label literal with no defensible single declaration owner, while live IDA MCP and raw PE evidence prove source-use contexts in [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](by-file/TerminalPane.md).
- Required action: supervisor should update the target header `EMITTER_UIDS` to `0000N0,0000OI`, optionally refresh the target narrative to describe the post-migration emitter route, replace the `by-memory/-coverage-report.md` row text shown below, then regenerate generated reports through normal tooling. Do not hand-edit `auto-generated/-ag-memory-coverage.md`.
- Confidence: `95/100` for bytes, range, xrefs, and no-split state; `92/100` for `CANONICAL_OWNER:NONE` plus the two-emitter route. Remaining uncertainty is only original source spelling form, such as repeated local literals versus an unrecovered macro/header constant; it does not affect the proven output routes.

## Supporting Research

## Target

- Target UID: `0003G4`.
- Target path: `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`.
- Assignment: `B001-0003G4-post-migration`.
- Source report row: `auto-generated/-ag-memory-coverage.md` currently reports the target as `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and no output route.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003G4`, assigned to Agent-B001 for post-migration owner/emitter recheck.
- Previous report: `tools/leaser/Agents/Agent-B001/research/executed/0003G4-SharedReconnectWideString-B001-0003G4.md`.
- Current metadata: `COMPLETION:89`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.

## Executive Recommendation

The previous no-owner conclusion remains correct for canonical ownership. The blank-emitter conclusion is stale under the current owner/emitter split.

The page documents one physical `.rdata` object: UTF-16LE `Reconnect` plus terminator at `0x00622f28-0x00622f3c`. IDA reports exactly four direct references to that address:

| Emitter route | Proven source-use sites | Why this route clears |
| --- | --- | --- |
| [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) | `0x00553c44` in `sub_553C10`, `0x00553cf4` in `sub_553CC0`, and `0x0055435e` in `sub_554210` | These are `ConnectionClosedDialog` constructor paths and `ReconnectDialog::OnButtonClick` replacement-alert logic. The file root is `87/88`, has `CANONICAL_OWNER:FILE`, proposes `NexusTK/network/`, and documents `network/ReconnectDialog.cpp` as the source for `ReconnectDialog` plus `ConnectionClosedDialog`. |
| [UID:0000OI][TerminalPane](by-file/TerminalPane.md) | `0x0058b5b1` in `sub_58B470` | `TerminalPane::OnDisconnect` builds its own reconnect/leave callback-backed prompt, stores callback target `sub_58B620`, then passes `Reconnect` and `Leave` labels to the alert builder. The file root is `87/85`, has `CANONICAL_OWNER:FILE`, and proposes `NexusTK/login/TerminalPane.cpp`. |

Use file roots as emitters rather than class pages. The physical literal spans `ConnectionClosedDialog`, `ReconnectDialog`, and `TerminalPane` source-use contexts, while no narrower class, global, table, or shared constants object owns the complete pooled cell. The final reconstructed source should spell the label naturally at the semantic call sites when those function pages are ready; this B-agent report does not write final reconstruction C++.

## Supervisor Active Recheck

- Supervisor instruction: perform a post-migration owner/emitter recheck for the current no-owner/non-emitting `Reconnect` literal and specifically test whether one or more emitters are justified even if `CANONICAL_OWNER:NONE` remains correct.
- Split repair required: no. The target is already the exact child `0x00622f28-0x00622f3c`; IDA confirms no xrefs to the false interior `0x00622f2c` / `aConnect` suffix, and `0x00622f3c` begins the separate `No` child.
- Parent/source repair required before action: no. Both selected file roots clear the `85/85` route gate. The direct class pages also support the source-use contexts, but emitter routing should use the file roots for this pooled literal.
- Coverage-report direct edit: not performed. Exact replacement text is included for supervisor application.
- Lease status: no shared by-* documentation files were edited during this pass; only this Agent-B001 research report was created in the assigned research folder.

## Inference Research Guidance Check

`by-structure.md` now separates `CANONICAL_OWNER` from `EMITTER_UIDS`. It states that `CANONICAL_OWNER` is semantic ownership, while `EMITTER_UIDS` is generated-output routing. It explicitly permits `CANONICAL_OWNER:NONE` with multiple emitters for compiler/linker-pooled string literals when no single declaration/source owner is proven but source-use contexts are proven.

That rule applies directly here. The old report correctly rejected assigning the physical pooled address to the consumer with the most xrefs. The current-system correction is to keep no canonical owner while routing output through every proven source-use file root.

`inference_research.md` warns that `.rdata` adjacency and string pooling are weak source-file evidence. This report therefore does not use the nearby `Leave`, `No`, `Yes`, or `baram` strings as ownership proof. Direct xrefs, behavior, and scored source-root docs drive the emitter recommendation.

Facts, documentation evidence, and inference are separated as follows:

- IDA facts: exact bytes, decoded wide text, xrefs, containing functions, decompilation, sibling-pair use with `Leave`, no interior xrefs, and no xrefs to the later `kServerReconnect` suffix.
- Raw PE facts: the target `Reconnect` bytes occur at the target and as the suffix of one unreferenced `kServerReconnect` string; the target VA occurs only as the four expected code immediates; interior and RVA-form scans are negative.
- Documentation evidence: target page, previous executed B001 report, no-owner tracker, current file/class pages, sibling/container pages, and generated coverage state.
- Inference: the physical string is a pooled source literal with no defensible declaration owner, but `ReconnectDialog.cpp` and `TerminalPane.cpp` both need the label in their reconstructed source-use contexts.

## Evidence Standards Used

- IDA MCP session: `b001_0003gy`, active worker for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA tools used: `idb_list`, `server_health`, `get_bytes`, `get_string`, `xrefs_to`, `lookup_funcs`, `trace_data_flow`, `analyze_component`, `search_text`, and `decompile`.
- Raw PE checks: PowerShell byte scan of `NexusTK.exe` for exact UTF-16 `Reconnect`, ASCII `Reconnect`, UTF-16 `kServerReconnect`, absolute VA dwords for target/interior/successor/later-suffix addresses, and RVA dwords.
- Documentation checks: target page, prior executed B001 report, no-owner tracker, `by-structure.md`, `inference_research.md`, `ReconnectDialog`, `TerminalPane`, `AlertPanes`, consumer by-memory pages, proposed source tree, current `auto-generated/-ag-memory-coverage.md`, and current `by-memory/-coverage-report.md`.

## IDA MCP Facts

Function/range facts:

- `server_health` reported module `NexusTK.exe`, IDB `NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs 0x00622f28` returns `Not a function`.
- `lookup_funcs` maps the four target refs to `sub_553C10` size `0xaf`, `sub_553CC0` size `0xae`, `sub_554210` size `0x1f6`, and `sub_58B470` size `0x170`.
- `lookup_funcs 0x0058b620` returns `sub_58B620`, size `0x2f`, the callback stored by `TerminalPane::OnDisconnect`.

Data/string facts:

- `get_bytes 0x00622f28 size 20` returns `52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00`, UTF-16LE `Reconnect`.
- `get_bytes 0x00622f1c size 56` decodes the containing tail as UTF-16LE `Leave`, UTF-16LE `Reconnect`, UTF-16LE `No`, UTF-16LE `Yes`, then ANSI `baram`.
- `get_string` shows IDA's typing is unreliable for this UTF-16 island: `0x00622f28` reads as `R`, and `0x00622f2c` reads as `connect`. These are decode artifacts, not separate source items.
- `get_bytes 0x006288a0 size 64` shows the later `Reconnect` spelling is the suffix of UTF-16LE `kServerReconnect` beginning at `0x006288a2`.

Xref facts:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x00622f1c` | four data refs at `0x00553c3f`, `0x00553cef`, `0x00554359`, `0x0058b5ac` | Sibling `Leave` label is paired at the same four prompt-construction sites. |
| `0x00622f28` | exactly four data refs | Current target is shared by reconnect-dialog and terminal-pane source-use contexts. |
| `0x00553c44` | `push offset off_622F28` in `sub_553C10` | `ConnectionClosedDialog` constructor variant source-use site. |
| `0x00553cf4` | `push offset off_622F28` in `sub_553CC0` | Alternate `ConnectionClosedDialog` constructor source-use site. |
| `0x0055435e` | `push offset off_622F28` in `sub_554210` | `ReconnectDialog::OnButtonClick` replacement-alert path source-use site. |
| `0x0058b5b1` | `push offset off_622F28` in `sub_58B470` | `TerminalPane::OnDisconnect` callback-backed prompt source-use site. |
| `0x00622f2c` | zero xrefs | The interior `aConnect` suffix is not a child or owner. |
| `0x00622f3c` | two refs to successor `No` data | Successor child starts separately. |
| `0x006288a2` / `0x006288b0` | zero xrefs | The later `kServerReconnect` string/suffix is not a source-use route for this item. |

Behavior facts:

- `trace_data_flow backward 0x00622f28` reaches exactly the four `Reconnect` refs and, at depth two, the four adjacent `Leave` pushes. This proves the target and sibling are used as a prompt label pair.
- `search_text off_622F28` in `0x00553000-0x0058c700` returns exactly four hits at `0x00553c44`, `0x00553cf4`, `0x0055435e`, and `0x0058b5b1`.
- `analyze_component` on the five relevant functions reports `sub_554210 -> sub_553CC0` as an internal call edge inside the reconnect-dialog family, while `sub_58B470` and callback `sub_58B620` are separate terminal-pane logic.
- `decompile 0x00553c10` and `decompile 0x00553cc0` both call `sub_49FEB0(..., &off_622F28, &off_622F1C)` after resolving alert text id `154`, then install `ConnectionClosedDialog` vtables and publish the connection-closed dialog singleton.
- `decompile 0x00554210` shows the reconnect/cancel handler can construct a replacement `ConnectionClosedDialog` inline and calls `sub_49FEB0(v8, dword_67A740, &off_622F28, &off_622F1C)`.
- `decompile 0x0058b470` shows `TerminalPane::OnDisconnect` creates a `PlainMemberFunctionObject` callback, stores `sub_58B620` at `0x0058b56d`, then calls `sub_4A0690(..., &off_622F28, &off_622F1C)`.
- `decompile 0x0058b620` shows the terminal callback chooses between `sub_5975E0(0,0,0,0)` and `sub_464E40()`, matching reconnect versus leave prompt behavior.

Negative IDA facts:

- No xrefs to the false interior `0x00622f2c`.
- No xrefs to `0x006288a2` or `0x006288b0`.
- No recognized vtable, constructor, initializer, pointer table, RTTI item, global object, or helper function owns `0x00622f28`.
- No IDA evidence ties the reconnect-dialog and terminal-pane refs through a modeled shared constants module.
- No extra code xrefs beyond the three reconnect-dialog-family sites and one terminal-pane site justify additional emitters.

## Raw PE Facts

PowerShell PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found:

| Pattern | Result | Meaning |
| --- | --- | --- |
| UTF-16LE `Reconnect\0` | two hits at file offsets `0x221928` and `0x2272B0` | Target occurrence plus later suffix occurrence. |
| ASCII `Reconnect\0` | zero hits | No ASCII prompt spelling. |
| UTF-16LE `kServerReconnect\0` | one hit at file offset `0x2272A2` | The later `Reconnect` bytes are only this unreferenced suffix. |
| Absolute VA `0x00622f28` little-endian | four hits at file offsets `0x153045`, `0x1530F5`, `0x15375F`, `0x18A9B2` | Immediate operand bytes for the four IDA refs. |
| Absolute VA `0x00622f2c` little-endian | zero hits | No hidden interior/suffix pointer. |
| Absolute VA `0x00622f3c` little-endian | two hits at file offsets `0x1532BC`, `0x1538C6` | Separate successor `No` child refs. |
| Absolute VAs `0x006288a2` and `0x006288b0` little-endian | zero hits | No hidden pointer to the later unreferenced spelling. |
| RVA-form `0x00222f28`, `0x00222f2c`, `0x002288a2`, `0x002288b0` little-endian | zero hits | No RVA-form table/pointer owner found. |

Command/result summary:

```text
UTF16_Reconnect_NUL count=2
  file+0x221928
  file+0x2272B0
ASCII_Reconnect_NUL count=0
UTF16_kServerReconnect_NUL count=1
  file+0x2272A2
VA_00622F28_LE count=4
  file+0x153045
  file+0x1530F5
  file+0x15375F
  file+0x18A9B2
VA_00622F2C_LE count=0
VA_00622F3C_LE count=2
  file+0x1532BC
  file+0x1538C6
VA_006288A2_LE count=0
VA_006288B0_LE count=0
RVA_00222F28_LE count=0
RVA_00222F2C_LE count=0
RVA_002288A2_LE count=0
RVA_002288B0_LE count=0
```

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Canonical Owner | Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x00622f1c-0x00622f54` | [UID:0003CW][ReconnectTerminalCopyStringTailMap](by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) | Mixed string-tail map | `FALSE` | `NONE` | blank | `89/93` | Keep non-emitting container. |
| `0x00622f1c-0x00622f28` | [UID:0003G3][SharedLeaveWideString](by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md) | Shared `Leave` label paired with target | `TRUE` | `NONE` | blank currently | `89/94` | Sibling; same source-use pattern, assigned to B003 post-migration. |
| `0x00622f28-0x00622f3c` | [UID:0003G4][SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | Shared `Reconnect` label | `TRUE` | `NONE` | recommend `0000N0,0000OI` | `89/94` | Current target. |
| `0x00622f3c-0x00622f44` | [UID:0003G5][CopyWindowNoButtonWideString](by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) | `CopyWindow` `No` label | `TRUE` | CopyWindow docs | existing owner route | documented | Separate successor, no merge. |
| `0x00622f44-0x00622f4c` | [UID:0003G6][CopyWindowYesButtonWideString](by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) | `CopyWindow` `Yes` label | `TRUE` | CopyWindow docs | existing owner route | documented | Separate successor, no merge. |
| `0x00622f4c-0x00622f54` | [UID:0003G7][SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | ANSI `baram` packet literal | `TRUE` | `NONE` currently | blank currently | `88/93` | Sibling; separate scope. |
| `0x006288a2` | no current child in this assignment | Unreferenced `kServerReconnect` string | unknown | none | none | undocumented | Negative context only. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page [UID:0003G4] documents the exact bytes, four direct xrefs, later `kServerReconnect` context, and prior no-owner conclusion. Live IDA/PE evidence reconfirmed the core facts.
- Previous report `0003G4-SharedReconnectWideString-B001-0003G4.md` correctly rejected a single direct parent, but it predates applying the current split owner/emitter model to this item.
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) is `87/88`, proposes `NexusTK/network/`, and documents `network/ReconnectDialog.cpp` as the source for the `ReconnectDialog` and `ConnectionClosedDialog` family.
- [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) and [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md) both route to [UID:0000N0] and document the three reconnect-dialog-family source-use contexts.
- [UID:0000OI][TerminalPane](by-file/TerminalPane.md) is `87/85`, proposes `NexusTK/login/`, and documents `login/TerminalPane.cpp` as the source for pre-login terminal connection, disconnect, and reconnect/leave decisions.
- [UID:0001JD][TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) documents the callback target stored by `TerminalPane::OnDisconnect` and directly ties the terminal prompt to [UID:0003G4].
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md) is `85/88`, but it explicitly keeps feature-specific reconnect alerts with [UID:0000N0] rather than generic alert ownership.
- Current post-migration pooled-literal precedents, including [UID:0003FY], [UID:0003G1], and [UID:0003IO], use `CANONICAL_OWNER:NONE` with multiple file-root emitters for comparable shared literal cases.

Existing docs that need migration/update:

- [UID:0003G4] still has blank `EMITTER_UIDS`; this is now incomplete for a proven pooled literal with two source-use file routes.
- `by-memory/-coverage-report.md` still records only the parent-blank conclusion; it should be updated to mention the emitter route.
- `auto-generated/-ag-memory-coverage.md` currently lists `0003G4` as no-owner with blank emitters. This should be regenerated after metadata changes, not edited by hand.

## Ranked Ownership / Routing Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI`

Evidence for:

- This exactly matches the current by-structure rule for pooled literals with no proven declaration owner but multiple proven source-use contexts.
- IDA confirms one physical prompt-label cell used by two separate source file roots.
- Raw PE scan finds no pointer table, RVA reference, interior pointer, or hidden declaration object.
- Both file roots clear `85/85` and have valid source-tree routes.
- Comparable accepted pages use file-root emitter lists while keeping canonical owner `NONE`.

Evidence against:

- Original source may have written repeated local literals and relied on linker pooling, or may have used an unrecovered macro/header constant. The stripped binary does not distinguish those source forms.

Decision: accepted. This target should be no-owner, but not non-emitting.

### 2. [UID:0000N0] `ReconnectDialog` as canonical owner

Evidence for:

- Three of four direct refs are in `ConnectionClosedDialog`/`ReconnectDialog` source-family code.
- The label is semantically central to the reconnect/connection-closed UI.
- [UID:0000N0] clears the route gate and has documented class/global/method children.

Evidence against:

- `TerminalPane::OnDisconnect` directly consumes the same physical address and builds its own callback-backed reconnect/leave prompt.
- IDA does not show the terminal prompt delegating ownership of the literal to a `ReconnectDialog` declaration.
- Assigning canonical ownership to [UID:0000N0] would overclaim the terminal-pane source-use site.

Decision: reject as canonical owner; accept [UID:0000N0] as one emitter.

### 3. [UID:0000OI] `TerminalPane` as canonical owner

Evidence for:

- `TerminalPane::OnDisconnect` directly uses the literal and stores a terminal callback target before prompt construction.
- [UID:0000OI] clears the route gate and documents the disconnect/reconnect prompt behavior.

Evidence against:

- Only one of four direct refs is terminal-pane owned.
- The other three direct refs are in separate reconnect/connection-closed code and are not incidental.

Decision: reject as canonical owner; accept [UID:0000OI] as one emitter.

### 4. [UID:0000HE] `AlertPanes` or a generic dialog-label owner

Evidence for:

- The call sites use alert/dialog construction infrastructure.
- `AlertPanes` owns generic modal alert classes.

Evidence against:

- The label is feature-specific reconnect/leave text, not a broad alert framework string such as `OK`.
- `AlertPanes.md` explicitly keeps reconnect alerts with [UID:0000N0] unless future xrefs prove generic ownership.
- No IDA evidence shows a generic alert label table or declaration owning this literal.

Decision: reject as canonical owner and as emitter.

### 5. New shared file/global owner such as `ReconnectPromptLabels`

Evidence for:

- `Reconnect` and sibling `Leave` are paired at the same four prompt sites.
- A source tree could have used a header macro or shared constant for both labels.

Evidence against:

- There is no pointer table, initializer, symbol, global object, or broader proven shared-label cluster.
- The same physical address is explained by ordinary string pooling.
- Inventing a new owner would not improve output routing beyond the two proven file emitters and would create unsupported source structure.

Decision: reject for current action. Revisit only if future source/debug/map evidence or a broader shared constants cluster appears.

### 6. Keep blank `EMITTER_UIDS`

Evidence for:

- This matched the old combined parent model because no single parent could own every use.

Evidence against:

- The current model deliberately separates semantic ownership from output routing.
- Both source-use roots are direct, material, scored above the route gate, and already documented.
- Leaving the item non-emitting would drop a real prompt label from both reconstructed source-use contexts despite strong evidence.

Decision: reject. Blank emitters are now stale for this item.

## Metadata Recommendation

Target header changes:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No score change is recommended:

- `COMPLETION:89`
- `CONFIDENCE:94`

No reconstruction C++ is recommended:

- Keep `RECONSTRUCTION_CPP CODE:[[[]]]`.
- Reason: the page is a pooled literal with no standalone source declaration owner. It should route through proven source-use emitters, while final call-site C++ belongs to the owning function/method pages when those pages are ready for code entry.

Optional target narrative update:

```text
- 2026-06-13 B001 post-migration recheck: retained `CANONICAL_OWNER:NONE` because the UTF-16LE `Reconnect` button-label literal is materially shared by `ReconnectDialog`/`ConnectionClosedDialog` prompt construction and `TerminalPane::OnDisconnect`, with no proven shared declaration owner. Added emitter routing `EMITTER_UIDS:0000N0,0000OI` because the current owner/emitter model allows no-owner pooled literals to emit through every proven source-use file root.
```

## Coverage / Generated Report Recommendation

Do not directly edit `auto-generated/-ag-memory-coverage.md`. After the target header update and normal regeneration, the current top generated row should move from blank emitters to the expected no-owner-with-emitters state:

```text
| [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` |  |
```

Replace the current `by-memory/-coverage-report.md` row under [UID:0003CW] `0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap`, immediately after [UID:0003G3] and before [UID:0003G5], with:

```text
            - [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) 0x00622f28-0x00622f3c | string-data | SharedReconnectWideString : reconstructable : 89% : very-strong : UTF-16LE `Reconnect` pooled button-label literal; B001-0003G4 post-migration recheck keeps `CANONICAL_OWNER:NONE` because ReconnectDialog, TerminalPane, AlertPanes, class-level parents, and a speculative shared-label owner each overclaim declaration ownership, but recommends `EMITTER_UIDS:0000N0,0000OI` because live IDA/PE evidence proves source-use contexts in `ReconnectDialog.cpp` / `ConnectionClosedDialog` prompt construction (`0x00553c44`, `0x00553cf4`, `0x0055435e`) and `TerminalPane::OnDisconnect` (`0x0058b5b1`); exact target bytes and four absolute target-VA immediates are confirmed, no refs target false interior `aConnect` at `0x00622f2c`, and the later `0x006288b0` spelling is only the unreferenced suffix of UTF-16 `kServerReconnect` at `0x006288a2`.
```

Expected score/coverage effects:

- Reconstructable state: unchanged.
- No-owner count: unchanged.
- No-owner with blank emitters / non-emitting reconstructable count: decreases by one.
- No-owner with emitters count: increases by one.
- Multiple-emitter routed literal count: increases by one.

## Validation / Commands Performed

No validator dry runs were used. No by-* documentation file was edited in this pass, so no project validator was required for changed by-* files.

Commands/results recorded:

- `Test-Path 'source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0003G4-SharedReconnectWideString-post-migration.md'`
  - Result before report creation: `False`.
- IDA MCP `idb_list`
  - Result: active session `b001_0003gy` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA MCP `server_health`
  - Result: `ok`, imagebase `0x400000`, Hex-Rays ready, auto-analysis ready, strings cache ready.
- IDA MCP `get_bytes`, `get_string`, `xrefs_to`, `lookup_funcs`, `trace_data_flow`, `analyze_component`, `search_text`, and `decompile`
  - Result: exact bytes, xrefs, call-site behavior, and negative interior/later-suffix evidence recorded above.
- PowerShell raw PE scan of `NexusTK.exe`
  - Result: exact target `Reconnect` appears at the target and as the suffix of unreferenced `kServerReconnect`; target VA dword occurs exactly four times; interior/tail and RVA-form scans are negative.
- `rg` checks on target, tracker, generated report, coverage report, `ReconnectDialog`, `TerminalPane`, `AlertPanes`, consumer by-memory pages, and proposed source tree
  - Result: current target and generated reports have blank emitters; [UID:0000N0] and [UID:0000OI] both clear the route gate; [UID:0000HE] excludes feature-specific reconnect alerts.

## Blockers

None. IDA MCP was available, the target split is exact, both emitter routes clear the gate, and no shared documentation file needed direct editing for this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G4","source_path":"executed-b-agent-research/B001/0003G4-SharedReconnectWideString-post-migration.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
