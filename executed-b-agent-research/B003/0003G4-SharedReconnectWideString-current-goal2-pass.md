** TARGET-REPORT-UID:0003G4 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G4 **
# 0003G4 SharedReconnectWideString Current Goal 2 Pass

## Finalized Recommendation

Keep [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) unchanged:

```text
COMPLETION:89
CONFIDENCE:94
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N0,0000OI
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

This is a correct no-owner pooled UTF-16 button-label literal. Live IDA MCP evidence and raw PE evidence prove source-use routes in both [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md), but no source-quality evidence proves a single canonical declaration owner.

No split, merge, reclassification, by-memory edit, IDA repair, coverage-report replacement, or C++ reconstruction entry is required.

## Target And Scope

- Assigned target: [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](../../../../../by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md).
- Address range: `0x00622f28-0x00622f3c`.
- Size: `0x14` bytes.
- Entity kind: `string-data`.
- Current generated state in `auto-generated/-ag-memory-coverage.md`: `no-owner`, canonical owner `NONE`, emitters `0000N0,0000OI`.
- Prior report checked only as background: `research/executed/0003G4-SharedReconnectWideString-second-pass.md`.

The current pass rechecked the by-memory page, generated coverage rows, related emitter docs, containing string map, related function/memory pages, live IDA MCP evidence, and raw PE evidence. Existing documentation was treated as a lead, not final authority.

## Evidence Standards Used

- `CANONICAL_OWNER` requires a direct semantic declaration or source-unit owner, not merely adjacency, physical pooling, generated output convenience, or a caller that happens to use the literal.
- `EMITTER_UIDS` may list every proven source-use output route when a reconstructable pooled literal has no defensible single owner.
- Shared string literals may remain `CANONICAL_OWNER:NONE` when multiple real source-use families consume the same physical `.rdata` bytes and no shared declaration owner is proven.
- Code-entry or reconstruction recommendations require at least `90/90` source-quality evidence. This item remains `89/94`, so no C++ literal declaration is entered.

## Current Documentation Facts

The target page currently identifies the range as UTF-16LE `Reconnect`:

```text
0x00622f28: 52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
```

The page records IDA's start name `off_622F28` and suffix name `aConnect` at `0x00622f2c` as string-pooling artifacts, not separate source strings or pointer-table evidence.

The containing map [UID:0003CW][0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) is a non-emitting physical string-tail map with these exact source-literal children:

| UID | Range | Role |
| --- | --- | --- |
| `0003G3` | `0x00622f1c-0x00622f28` | shared UTF-16 `Leave` label, same source-use families |
| `0003G4` | `0x00622f28-0x00622f3c` | target UTF-16 `Reconnect` label |
| `0003G5` | `0x00622f3c-0x00622f44` | UTF-16 `No` copy-window label |
| `0003G6` | `0x00622f44-0x00622f4c` | UTF-16 `Yes` copy-window label |
| `0003G7` | `0x00622f4c-0x00622f54` | ANSI `baram` route string, same source-use families |

This containing map is mixed physical storage, not a canonical owner for the target string.

## Live IDA MCP Facts

IDA MCP session:

- Active session: `b001_0003gy`.
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Image base: `0x00400000`.
- Auto-analysis and Hex-Rays status: ready.

Function lookup:

| Address | Function | Finding |
| --- | --- | --- |
| `0x00553c44` | `sub_553C10` | `ConnectionClosedDialog` constructor variant use |
| `0x00553cf4` | `sub_553CC0` | `ConnectionClosedDialog` constructor path use |
| `0x0055435e` | `sub_554210` | `ReconnectDialog::OnButtonClick` replacement prompt use |
| `0x0058b5b1` | `sub_58B470` | `TerminalPane::OnDisconnect` prompt use |
| `0x00622f28` | not a function | target `.rdata` string |
| `0x00622f2c` | not a function | false interior suffix name |
| `0x006288a2` / `0x006288b0` | not functions | separate later `kServerReconnect` storage and suffix |

IDA bytes at the containing map decode as:

```text
0x00622f1c: UTF-16LE "Leave"
0x00622f28: UTF-16LE "Reconnect"
0x00622f3c: UTF-16LE "No"
0x00622f44: UTF-16LE "Yes"
0x00622f4c: ANSI "baram"
```

IDA xrefs to the target start are exactly:

| Xref | Function | Source route |
| --- | --- | --- |
| `0x00553c44` | `sub_553C10` | `ReconnectDialog.cpp` / `ConnectionClosedDialog` constructor variant |
| `0x00553cf4` | `sub_553CC0` | `ReconnectDialog.cpp` / `ConnectionClosedDialog` constructor path |
| `0x0055435e` | `sub_554210` | `ReconnectDialog.cpp` / reconnect button path replacement prompt |
| `0x0058b5b1` | `sub_58B470` | `TerminalPane.cpp` / disconnect reconnect prompt |

IDA xrefs to the adjacent `Leave` start at `0x00622f1c` are the paired operands in the same four functions: `0x00553c3f`, `0x00553cef`, `0x00554359`, and `0x0058b5ac`.

IDA xrefs to false target interiors are absent:

```text
0x00622f2c: 0 refs
0x00622f30: 0 refs
0x00622f34: 0 refs
0x00622f38: 0 refs
```

IDA xrefs to the later `kServerReconnect` spelling and its suffix are absent:

```text
0x006288a2: 0 refs
0x006288b0: 0 refs
```

Hex-Rays decompilation confirms the label-pair use:

```text
sub_553C10: sub_49FEB0(v2, v4, &off_622F28, &off_622F1C);
sub_553CC0: sub_49FEB0(v3, a2, &off_622F28, &off_622F1C);
sub_554210: sub_49FEB0(v8, v11, &off_622F28, &off_622F1C);
sub_58B470: sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C);
```

The `TerminalPane` path also stores callback `sub_58B620` immediately before constructing the prompt, matching [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](../../../../../by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md).

## Raw PE Evidence

Local PE inspection of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms:

```text
imagebase: 0x00400000
.rdata: 0x0060d000-0x0066c200
target raw range: 0x221928-0x22193c
target bytes: 52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
decoded target: UTF-16LE "Reconnect"
```

Literal occurrence scan:

| Pattern | Count | VA hits |
| --- | ---: | --- |
| UTF-16LE `Reconnect\0` | 2 | `0x00622f28`, `0x006288b0` |
| UTF-16LE `kServerReconnect\0` | 1 | `0x006288a2` |
| ASCII `Reconnect\0` | 0 | none |
| UTF-16LE `Leave\0` | 1 | `0x00622f1c` |
| UTF-16LE `No\0` | 1 | `0x00622f3c` |
| UTF-16LE `Yes\0` | 1 | `0x00622f44` |
| ANSI `baram\0` | 1 | `0x00622f4c` |

`.text` reference-form scan for target VA `0x00622f28` found exactly four absolute-immediate operand hits and no RVA-form hits:

```text
abs immediate operand bytes for 0x00622f28:
0x00553c45
0x00553cf5
0x0055435f
0x0058b5b2

RVA-form hits for 0x00622f28:
none
```

These operand byte addresses correspond to the IDA xref instruction starts at `0x00553c44`, `0x00553cf4`, `0x0055435e`, and `0x0058b5b1`.

Reference-form scan for target interiors found no absolute or RVA references. A blind relative-displacement scan produced one mathematical hit for `0x00622f38` at `0x0057df4c`, but live IDA identifies that instruction as `call sub_57E9A0` in `sub_57D9C0`; it is not a data xref and IDA reports zero xrefs to `0x00622f38`. This is not evidence for a separate suffix string.

Reference-form scan for the later spelling found no code references:

```text
0x006288a2: no abs/RVA/rel32 refs
0x006288b0: no abs/RVA/rel32 refs
```

The later `0x006288b0` occurrence is therefore only the suffix of the separate UTF-16 string `kServerReconnect` at `0x006288a2`, not a source-use route for this target.

## Function And Child Inventory

| UID / Address | Current owner evidence | Relevance |
| --- | --- | --- |
| `00023O` / `0x00553c10-0x00553cbf` | [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) source family | Constructor variant passes `Reconnect` and `Leave` label pair. |
| `00038J` / `0x00553cc0-0x00553e5b` | `ConnectionClosedDialog` methods under ReconnectDialog source file | Constructor path passes the same label pair. |
| `00038L` / `0x00553f40-0x005544b8` | `ReconnectDialog` methods under ReconnectDialog source file | Replacement connection-closed prompt passes the same label pair. |
| `0001JB` / `0x0058af50-0x0058c350` | [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) source family | `TerminalPane::OnDisconnect` passes the same label pair. |
| `0001JD` / `0x0058b620-0x0058b64f` | [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) source family | Callback used by the terminal-pane reconnect/leave prompt. |
| `0003CW` / `0x00622f1c-0x00622f54` | no emitting owner | Physical mixed string map; not a semantic declaration owner. |
| `0x006288a2` / `0x006288b0` | no current xrefs | Separate `kServerReconnect` storage and suffix; not part of this target. |

## Xrefs And Callers

Direct target xrefs:

```text
0x00553c44 -> 0x00622f28
0x00553cf4 -> 0x00622f28
0x0055435e -> 0x00622f28
0x0058b5b1 -> 0x00622f28
```

Direct paired `Leave` xrefs:

```text
0x00553c3f -> 0x00622f1c
0x00553cef -> 0x00622f1c
0x00554359 -> 0x00622f1c
0x0058b5ac -> 0x00622f1c
```

The caller/use inventory supports two source-use routes:

- `0000N0` emits through ReconnectDialog-family code, including `ConnectionClosedDialog` prompt construction.
- `0000OI` emits through TerminalPane disconnect prompt construction.

It does not support one route owning the other, and it does not support a third source route.

## Ownership Analysis

1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI` is the best fit.

   The same physical UTF-16LE `Reconnect` bytes are used from both ReconnectDialog-family prompt construction and TerminalPane disconnect prompt construction. Both routes are source-quality output routes. No evidence proves a common source declaration such as a shared `constexpr`, resource table entry, localization table, or UI constants owner.

2. [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) is a proven emitter, not a canonical owner.

   Three of the four target xrefs are in ReconnectDialog-family code. That proves output routing through `ReconnectDialog.cpp`, but assigning canonical ownership to `0000N0` would overclaim the independent TerminalPane source-use route at `0x0058b5b1`.

3. [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) is a proven emitter, not a canonical owner.

   `TerminalPane::OnDisconnect` constructs the reconnect/leave alert and uses this exact literal, but assigning canonical ownership to `0000OI` would overclaim the ReconnectDialog-family constructor and replacement-prompt routes.

4. [UID:0000HE][AlertPanes](../../../../../by-file/AlertPanes.md) is rejected as canonical owner and emitter.

   AlertPanes owns reusable alert framework behavior. The observed xrefs are feature-specific prompt uses in ReconnectDialog-family and TerminalPane code, not generic alert-framework declaration or emission.

5. Class-level owners are rejected.

   `ConnectionClosedDialog`, `ReconnectDialog`, and `TerminalPane` class pages are useful behavioral leads, but the output routes are file-level roots. A class-level canonical owner would still fail to cover all uses without overclaiming.

6. A new shared-label owner is rejected.

   The executable has pooled `.rdata` storage, but no debug path, symbol, xref pattern, or decompilation evidence proves a source-level shared label constant. Creating a new shared owner would be invented structure.

7. Split, merge, and reclassification are rejected.

   The target is an exact 20-byte UTF-16LE string. IDA reports no xrefs to the false interior suffix `0x00622f2c`, raw PE scan finds no real target-interior references, and the later `0x006288b0` spelling is part of a separate unreferenced `kServerReconnect` string. The current child boundary is correct.

## Exact Required Edits

No direct documentation edits are required.

No replacement text is required for `by-memory/-coverage-report.md`. The current generated state is acceptable:

```text
[UID:0003G4] 0x00622f28-0x00622f3c.SharedReconnectWideString | no-owner | CANONICAL_OWNER:NONE | EMITTER_UIDS:0000N0,0000OI
```

No target header change is required:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

## Validation

No validator was run because no by-memory, by-file, by-class, coverage, or generated documentation file was edited. This pass did not use a dry run.

The only created file is this current-pass research report, placed in the assigned Agent-B003 research root.

## Confidence

- Completion remains `89`: exact bytes, source-use xrefs, raw PE reference forms, negative interior-reference evidence, and emitter routing are documented, but the item should not receive C++ reconstruction text below the `90/90` gate.
- Confidence remains `94`: IDA xrefs, Hex-Rays decompilation, raw executable bytes, operand scans, containing-map structure, and source-file docs all agree that this is a no-owner pooled literal with emitters `0000N0,0000OI`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G4","source_path":"executed-b-agent-research/B003/0003G4-SharedReconnectWideString-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
