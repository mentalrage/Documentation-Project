** TARGET-REPORT-UID:0003G4 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G4 **
# 0003G4 SharedReconnectWideString Post-Migration Recheck

## Finalized Report / Current Recommendation

- Target: [UID:0003G4] `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`.
- Recommendation: **no metadata or coverage change**. Keep this as a valid reconstructable no-owner-with-emitters pooled literal.
- Exact metadata to retain:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Canonical owner decision: keep `CANONICAL_OWNER:NONE`. The same physical UTF-16LE `Reconnect` cell is consumed by the `ReconnectDialog` / `ConnectionClosedDialog` source family and by `TerminalPane::OnDisconnect`; neither file is a defensible semantic declaration owner for the whole pooled cell.
- Emitter decision: keep `EMITTER_UIDS:0000N0,0000OI`. [UID:0000N0] `ReconnectDialog` is a proven source-use route for the three reconnect/connection-closed prompt refs, and [UID:0000OI] `TerminalPane` is a proven source-use route for the terminal disconnect prompt ref.
- Reclassification/split/merge/IDA repair: none. The target is an exact 20-byte source-authored literal. No interior `Connect` split, no merge into the mixed map, and no repair to the later `kServerReconnect` spelling is justified.
- Score: keep `89/94`. The item is below the active 90/90 reconstruction-code bar on completion and should not receive standalone final C++ in this by-memory page; final source should spell the label at each verified source-use site through the two emitters.
- Coverage-report action: no replacement row needed. The current `by-memory/-coverage-report.md` row is already correct and should remain unchanged.

## Supporting Research

## Target And Current State

Facts from the current target page:

| Field | Current value |
| --- | --- |
| UID | `0003G4` |
| Range | `0x00622f28-0x00622f3c` |
| Size | `0x14` / 20 bytes |
| Kind | `string-data` |
| Text | UTF-16LE `Reconnect` |
| Current owner | `CANONICAL_OWNER:NONE` |
| Current emitters | `0000N0,0000OI` |
| Current score | `COMPLETION:89`, `CONFIDENCE:94` |
| Current C++ | blank |

Current generated rows observed in `auto-generated/-ag-memory-coverage.md`:

```text
| [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` |  |
| [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` | [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md) |  | `auto-generated/NexusTK/network/ReconnectDialog.cpp` |  |
| [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) | no-owner | `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` | `0000N0`,`0000OI` | `auto-generated/NexusTK/network/ReconnectDialog.cpp` |  |
```

The single generated output-path cell showing `network/ReconnectDialog.cpp` is only the report's chosen display path for a no-owner item with emitters. It is not a canonical-owner assignment and does not invalidate the `TerminalPane` emitter.

Current manual coverage row observed in `by-memory/-coverage-report.md`; no replacement is recommended:

```text
            - [UID:0003G4][0x00622f28-0x00622f3c.SharedReconnectWideString](by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md) 0x00622f28-0x00622f3c | string-data | SharedReconnectWideString : reconstructable : 89% : very strong : UTF-16LE `Reconnect` pooled button-label literal; B001 post-migration and B003 second-pass reviews keep `CANONICAL_OWNER:NONE` because ReconnectDialog, TerminalPane, AlertPanes, class-level parents, and a speculative shared-label owner each overclaim declaration ownership, but retain `EMITTER_UIDS:0000N0,0000OI` because live IDA/PE evidence proves source-use contexts in `ReconnectDialog.cpp` / `ConnectionClosedDialog` prompt construction (`0x00553c44`, `0x00553cf4`, `0x0055435e`) and `TerminalPane::OnDisconnect` (`0x0058b5b1`); exact target bytes and four absolute target-VA immediates are confirmed, no refs target false interior `aConnect` at `0x00622f2c`, no target RVA refs, and the later `0x006288b0` spelling is only the unreferenced suffix of UTF-16 `kServerReconnect` at `0x006288a2`.
```

## Rule Basis

Facts from `by-structure.md`:

- `CANONICAL_OWNER` records semantic declaration ownership.
- `EMITTER_UIDS` records source-output routing and can list multiple proven emitters.
- A pooled or shared source-authored literal can validly remain `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while still listing multiple emitters for proven source-use contexts.
- Do not invent a standalone helper/global owner solely to avoid `NONE`.
- The active reconstruction-code entry bar is about `90/90+`, with owner/emitter route, dependencies, names, boundaries, and source placement sufficiently verified. `95+` remains final-audit territory, not the ordinary code-entry minimum.

Applied inference discipline from `Agent-B001/inference_research.md`: xrefs and byte evidence are facts; source-file ownership from use sites is an inference. Here, use sites prove emitter routes but do not prove a single source declaration owner for the pooled cell.

## IDA MCP Evidence

Live IDA MCP session:

| Item | Value |
| --- | --- |
| IDB | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` |
| Input | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` |
| Image base | `0x00400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |

Target bytes from `get_bytes`:

```text
0x00622f28: 52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
```

This decodes as UTF-16LE `Reconnect`.

Adjacent string-tail bytes from `get_bytes 0x00622f1c` confirm the containing mixed map:

```text
0x00622f1c: UTF-16LE "Leave"
0x00622f28: UTF-16LE "Reconnect"
0x00622f3c: UTF-16LE "No"
0x00622f44: UTF-16LE "Yes"
0x00622f4c: ANSI "baram"
```

IDA `xrefs_to 0x00622f28` found exactly four xrefs:

| Xref | Containing function | Disassembly evidence | Source-use inference |
| --- | --- | --- | --- |
| `0x00553c44` | `sub_553C10`, size `0xaf` | `push offset off_622F28`, paired with `push offset off_622F1C`, then `call sub_49FEB0` | `ConnectionClosedDialog` constructor variant under [UID:0000N0] `ReconnectDialog` |
| `0x00553cf4` | `sub_553CC0`, size `0xae` | `push offset off_622F28`, paired with `push offset off_622F1C`, then `call sub_49FEB0` | alternate `ConnectionClosedDialog` constructor/method path under [UID:0000N0] |
| `0x0055435e` | `sub_554210`, size `0x1f6` | `push offset off_622F28`, paired with `push offset off_622F1C`, then `call sub_49FEB0` | `ReconnectDialog` button/replacement connection-closed prompt path under [UID:0000N0] |
| `0x0058b5b1` | `sub_58B470`, size `0x170` | `push offset off_622F28`, paired with `push offset off_622F1C`, then `call sub_4A0690` | `TerminalPane::OnDisconnect` prompt path under [UID:0000OI] `TerminalPane` |

IDA decompile snippets:

```text
0x00553c10: sub_49FEB0(v2, v4, &off_622F28, &off_622F1C)
0x00553cc0: sub_49FEB0(v3, a2, &off_622F28, &off_622F1C)
0x00554210: sub_49FEB0(v8, v11, &off_622F28, &off_622F1C)
0x0058b470: sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C)
```

IDA `analyze_component` on `0x00553c10`, `0x00553cc0`, `0x00554210`, `0x0058b470`, and `0x0058b620` confirms:

- `0x553c10`, `0x553cc0`, and `0x554210` share `ConnectionClosedDialog` vtable globals at `0x00622d34`, `0x00622d9c`, and `0x00622dcc`.
- `0x00622f28` (`off_622F28`) is accessed by all four prompt-construction functions: `sub_553C10`, `sub_553CC0`, `sub_554210`, and `sub_58B470`.
- `0x0058b620` is a separate TerminalPane callback body, and `sub_58B470` installs it before constructing the reconnect/leave prompt.

Negative IDA evidence:

| Check | Result | Ownership effect |
| --- | --- | --- |
| `xrefs_to 0x00622f2c` | 0 | IDA's `aConnect` suffix is not a separately referenced source string. |
| `xrefs_to 0x00622f30` | 0 | No interior split point. |
| `xrefs_to 0x00622f34` | 0 | No interior split point. |
| `xrefs_to 0x00622f38` | 0 | No interior split point. |
| `xrefs_to 0x006288a2` | 0 | Later UTF-16 `kServerReconnect` spelling is not a source-use lead for this target. |
| `xrefs_to 0x006288b0` | 0 | Later `Reconnect` suffix has no refs and is not an emitter lead. |

## PE / Raw Byte Evidence

Independent PowerShell PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

| Field | Value |
| --- | --- |
| Image base | `0x00400000` |
| Target section | `.rdata` |
| Target file offset | `0x221928` |
| Target bytes | `52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00` |

Byte-pattern results:

| Pattern | Matches |
| --- | --- |
| UTF-16LE `Reconnect\0` | `0x00622f28`, `0x006288b0` |
| ASCII `Reconnect\0` | none |
| UTF-16LE `kServerReconnect\0` | `0x006288a2` |
| Little-endian target VA `28 2f 62 00` | `0x00553c45`, `0x00553cf5`, `0x0055435f`, `0x0058b5b2` |
| Instruction pattern `push 0x00622f28` / `68 28 2f 62 00` | `0x00553c44`, `0x00553cf4`, `0x0055435e`, `0x0058b5b1` |
| Interior suffix VA `0x00622f2c` | none |
| Target RVA `0x00222f28` | none |
| Later `kServerReconnect` VA `0x006288a2` | none |
| Later suffix VA `0x006288b0` | none |

Raw inference: the executable contains another UTF-16 `Reconnect` byte sequence, but it is the suffix of the unreferenced `kServerReconnect` string at `0x006288a2`. It is not a referenced source-use route for UID `0003G4`.

## Documentation Evidence

| Document | Current facts used | Effect |
| --- | --- | --- |
| Target page `0003G4` | Records exact UTF-16 bytes, four xrefs, no-owner decision, and emitters `0000N0,0000OI`. | Current page matches fresh IDA/PE evidence. |
| [UID:0000N0] `by-file/ReconnectDialog.md` | `ReconnectDialog.cpp` owns `ReconnectDialog` and `ConnectionClosedDialog`, with exact children for `0x00553c10`, `0x00553cc0`, `0x00554210`, and related cleanup. Score `87/88`. | Clears file-route gate and justifies emitter `0000N0` for the three reconnect/connection-closed prompt uses. |
| [UID:0000OI] `by-file/TerminalPane.md` | `TerminalPane.cpp` owns pre-login TerminalPane, `TerminalPane::OnDisconnect`, and callback child `0x0058b620`. Score `87/85`. | Clears file-route gate and justifies emitter `0000OI` for the terminal disconnect prompt use. |
| [UID:0000HE] `by-file/AlertPanes.md` | Owns generic reusable alert classes and explicitly keeps feature-specific reconnect alerts with `ReconnectDialog`. | Rejects `AlertPanes` as canonical owner or emitter for this label. |
| [UID:0003CW] mixed tail map | Non-emitting mixed map with exact children for `Leave`, `Reconnect`, `No`, `Yes`, and `baram`. | Confirms UID `0003G4` is already the correct exact child and that the parent map should not emit. |
| [UID:0001JD] `TerminalPaneReconnectLeaveCallback` | Documents the callback installed from `TerminalPane::OnDisconnect` and the paired `Leave`/`Reconnect` pushes at `0x0058b5ac`/`0x0058b5b1`. | Strengthens the TerminalPane emitter route. |

Prior reports were read as background only. The fresh IDA/PE evidence independently reproduces the accepted result from the B001 post-migration report and B003 second-pass report.

## Source-Use / Emitter Inventory

| Emitter UID | Source route | Proven use sites | Recommendation |
| --- | --- | --- | --- |
| `0000N0` | `NexusTK/network/ReconnectDialog.cpp` | `0x00553c44`, `0x00553cf4`, `0x0055435e` | Keep. These are direct source uses in `ConnectionClosedDialog` and `ReconnectDialog` prompt construction. |
| `0000OI` | `NexusTK/login/TerminalPane.cpp` | `0x0058b5b1` | Keep. This is a direct source use in `TerminalPane::OnDisconnect`, paired with the TerminalPane callback setup. |

Why blank emitters would be wrong: this is reconstructable source-authored UI text, and both file routes have verified source-use sites. The current owner/emitter split exists to handle exactly this kind of pooled literal: `NONE` for canonical ownership, multiple emitters for output placement.

## Ranked Owner / Route Analysis

### 1. No canonical owner, emit through `ReconnectDialog` and `TerminalPane`

Rank: best and recommended.

Facts:

- IDA and raw bytes prove exactly four references to the physical target address.
- Three refs are in the reconnect/connection-closed dialog family.
- One ref is in `TerminalPane::OnDisconnect`.
- Both file roots clear the current documentation gate: [UID:0000N0] is `87/88`, [UID:0000OI] is `87/85`.

Inference:

- The bytes are linker-pooled storage for the same source literal text used in two source files.
- Neither file owns the declaration of the physical pooled cell in a way that should suppress the other source use.

Decision:

- Keep `CANONICAL_OWNER:NONE`.
- Keep `EMITTER_UIDS:0000N0,0000OI`.

### 2. Canonical owner [UID:0000N0] `ReconnectDialog`

Rank: rejected.

Evidence for:

- Three of four references come from `ConnectionClosedDialog` / `ReconnectDialog` code.
- `ReconnectDialog.md` owns the dialog family and clears the gate.

Evidence against:

- `0x0058b5b1` is a direct, material `TerminalPane::OnDisconnect` source use.
- Assigning canonical ownership to `ReconnectDialog` would overclaim a shared literal and make the TerminalPane use look secondary even though it is an ordinary prompt construction site.

Decision: keep as emitter only.

### 3. Canonical owner [UID:0000OI] `TerminalPane`

Rank: rejected.

Evidence for:

- `TerminalPane::OnDisconnect` directly uses the target and pairs it with the callback at `0x0058b620`.
- `TerminalPane.md` clears the gate.

Evidence against:

- Only one of four refs is TerminalPane.
- Three refs are in the reconnect/connection-closed dialog family.

Decision: keep as emitter only.

### 4. [UID:0000HE] `AlertPanes`

Rank: rejected.

Evidence for:

- The target is an alert button label.

Evidence against:

- `AlertPanes.md` owns reusable alert implementation, not feature-specific reconnect prompt content.
- IDA use sites are feature call sites that pass label pointers into alert helpers.
- No direct target ref appears inside the generic `AlertPane` or `VersatileAlertPane` constructor bodies.

Decision: no owner and no emitter.

### 5. Class-level owners `ConnectionClosedDialog`, `ReconnectDialog`, or `TerminalPane`

Rank: rejected as canonical owner for this physical cell.

Evidence for:

- Each class explains some source use.

Evidence against:

- No one class covers all four references.
- The correct output routes are file-level emitters already represented by `0000N0` and `0000OI`.

Decision: do not replace file emitters with partial class-level canonical ownership.

### 6. New shared-label/constants owner

Rank: rejected.

Evidence for:

- The byte cell is physically shared.

Evidence against:

- No xref table, debug source metadata, global pointer, named string table, or source-structure evidence supports a hand-authored shared declaration.
- Ordinary linker string pooling fully explains the physical sharing.
- `by-structure.md` warns not to invent a standalone owner just to avoid `NONE`.

Decision: no new owner.

### 7. Non-reconstructable or no-emitter state

Rank: rejected.

Evidence against:

- This is a source-authored UI literal used in reconstructable source call sites.
- The two emitters are directly proven.

Decision: keep reconstructable with emitters.

## Split / Merge / Repair Decision

No split is needed:

- The target already exactly spans the UTF-16LE `Reconnect` literal and its NUL terminator.
- The false interior `aConnect` suffix at `0x00622f2c` has no xrefs and is not a separate source literal.

No merge is needed:

- The parent [UID:0003CW] mixed tail map contains strings owned or emitted through different routes (`Leave`, `Reconnect`, `No`, `Yes`, `baram`).
- The parent map is correctly non-emitting, while exact children carry source-use decisions.

No IDA repair is needed:

- IDA's `off_622F28` and interior `aConnect` labels are imperfect string-pooling artifacts but do not block documentation or routing.
- Function boundaries around the four consumer sites are stable enough for this ownership/emitter decision.

No source-output repair is needed:

- The existing emitters are the exact source-use routes known today.
- No third emitter is supported by IDA or raw-byte evidence.

## Score And Code-Entry Effect

Before: `89/94`.

After recommendation: `89/94`, unchanged.

Rationale:

- Completion remains `89` because the item has exact bytes, exact xrefs, raw pointer scan, current emitters, and negative evidence, but no standalone declaration owner and no final source-body placement in the by-memory page.
- Confidence remains `94` because IDA MCP and raw PE evidence agree on bytes, xrefs, non-xrefs, and emitter routes.
- Do not recommend standalone reconstruction C++ here. The active code-entry gate is `90/90+`; this page is `89/94`, and the correct reconstruction action is to emit `L"Reconnect"` at each semantic source-use site through [UID:0000N0] and [UID:0000OI], not to create a separate by-memory C++ declaration.

## Validation / Commands

No by-* documentation or `by-memory/-coverage-report.md` files were edited.

Commands/evidence gathered:

| Command/tool | Result |
| --- | --- |
| `Get-Content Agent-B001/goal.md` | Confirmed B-agent workflow, report placement, and no direct by-* edit constraints for this task. |
| `rg "0003G4|SharedReconnectWideString|0x00622f28" ...` | Confirmed current tracker assignment, generated rows, and manual coverage row. |
| IDA MCP `server_health` | IDB ready, `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready. |
| IDA MCP `get_bytes` | Confirmed exact target bytes and adjacent mixed-tail bytes. |
| IDA MCP `xrefs_to` | Confirmed exactly four xrefs to `0x00622f28` and zero xrefs to interior/later-suffix candidates. |
| IDA MCP `lookup_funcs` | Confirmed containing functions for the four refs and that string addresses are not functions. |
| IDA MCP `decompile` / `disasm` | Confirmed paired `Leave`/`Reconnect` pushes and alert-builder calls in the four consumer functions. |
| IDA MCP `analyze_component` | Confirmed shared prompt globals and access set across reconnect-dialog and terminal functions. |
| IDA MCP `find_bytes` | Confirmed two UTF-16 `Reconnect` byte spellings, four target-VA immediates, four `push target` encodings, and no false-suffix/RVA/later-suffix references. |
| PowerShell PE scan | Independently confirmed target `.rdata` file offset `0x221928`, exact bytes, raw target VA hits, no target RVA hits, no interior/later-suffix VA hits. |

No validator was run because this was report-only and the user prohibited dry runs and direct by-* edits. No memory-range mode was used.

## Changed Files

- Created this report only: `tools/leaser/Agents/Agent-B001/research/0003G4-SharedReconnectWideString-post-migration-recheck.md`.

No changes were made to:

- `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `tools/leaser/Agents/no_owner_b-agent-tracker.md`

## Blockers

None. Current evidence is sufficient to make the recommendation executable by the supervisor.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G4","source_path":"executed-b-agent-research/B001/0003G4-SharedReconnectWideString-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
