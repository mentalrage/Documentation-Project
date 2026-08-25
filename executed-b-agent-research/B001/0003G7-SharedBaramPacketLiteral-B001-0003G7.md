** TARGET-REPORT-UID:0003G7 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G7 **
# 0003G7 SharedBaramPacketLiteral Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0003G7] `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md` reconstructable but parent-blank.
- Final disposition: no split, no rename, no new packet/source owner, no `AUTOGEN_PARENT_UID`; recreate the ANSI `"baram"` packet text at each real source send site and let the compiler/linker decide whether to pool it.
- Required action: do not assign this child to `ReconnectDialog`, `TerminalPane`, `Socket`, `ProtocolSend`, `Session`, the physical `.rdata` container, `Palette`, or a new shared packet-literal file. Optional supervisor-only score/evidence refresh text is listed in `Follow-Up Actions`.
- Confidence: `89/94` for the no-parent/no-split recommendation. The live IDA facts are stronger than the current `88/93` page evidence, but stripped-binary evidence still cannot prove whether the original source wrote duplicated local literals or a small local helper in one feature file.

## Supporting Research

## Target
- Target UID: `0003G7`.
- Target path: `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md`.
- Source queue/report row: active `Supervisor_notes.md`, Batch `B001-0003G7`; `auto-generated/-ag-memory-coverage.md` line `3043` reports the item as `unassigned`.
- Current supervisor classification: `reviewed-85-but-ownership-unknown-under-review`.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, blank `AUTOGEN_PARENT_UID`, blank C++.
- Target range: `0x00622f4c-0x00622f54`, 8 bytes, ANSI `baram` followed by two zero alignment bytes before the Region RTTI/vtable data.

## Executive Recommendation

Keep the physical `0x00622f4c` ANSI `baram` literal parent-blank. It is source-authored packet text, but the one physical `.rdata` cell is referenced by two independently owned source paths:

- [UID:00038L] `ReconnectDialog::OnButtonClick` pushes `aBaram_0`, formats it into a stack buffer, calls [UID:0001HU] `QueueAndSendPacket` with length `5`, and then calls [UID:0001HW] `SendPositionUpdate`.
- [UID:0001JC] `TerminalPane::ParseTerminalStream` does the same `baram` format/send sequence during the terminal stream login handoff, then calls [UID:0001HW] `SendPositionUpdate`.

Both call sites are legitimate source uses. [UID:0000N0] `ReconnectDialog` and [UID:0000OI] `TerminalPane` both clear the 85/85 gate, but neither owns the full physical pooled literal. [UID:0000DD] `Socket` owns the queue/send and position-update mechanics, not this feature-level packet text. [UID:0000MV] `ProtocolSend` and [UID:0000NP] `Session` remain non-promoted placeholders and should not absorb this one literal.

No split is needed. The target is already the atomic ANSI string plus alignment. Interior suffix starts `0x00622f4d` and `0x00622f50` have no xrefs, and the successor [UID:0002OP] `RegionVtableData` starts cleanly at `0x00622f54`.

## Supervisor Active Recheck
- Triggering instruction: Batch `B001-0003G7` asked for deeper ownership/source-family inference after A003 Batch 332 raised the child to `88/93` but left the parent blank because `ReconnectDialog` and `TerminalPane` both clear 85/85 and both consume the pooled `baram` packet literal.
- Split repair required: no. The range is already an exact child of [UID:0003CW] `ReconnectTerminalCopyStringTailMap`.
- Source-bearing child status: [UID:0003G7] remains source-authored/reconstructable. The containing map and sibling strings are already split; this report only recommends an evidence/score refresh and no parent assignment.

## Inference Research Guidance Check
- `by-structure.md` requires `AUTOGEN_PARENT_UID` to identify the true direct semantic owner, not the nearest consumer or an output-routing convenience.
- `by-structure.md` also allows source-authored literals to remain reconstructable but parent-blank when pooling gives one physical address multiple valid source use sites.
- `inference_research.md` warns that address adjacency and pooled constants are weak source-file evidence without metadata, local/static declaration evidence, initializer/table evidence, or a single-owner xref cluster.
- Existing documentation was treated as hypothesis. The target page, containing maps, `ReconnectDialog`, `TerminalPane`, `Socket`, `ProtocolSend`, `Session`, `client_network`, and the separate Palette `baram.pal` spelling were checked against live IDA MCP or direct documentation evidence before ranking ownership.

## Evidence Standards Used
- Live IDA MCP on 2026-06-12 against database/session `b001_nexustk`: `server_health`, `get_bytes`, `get_string`, `xrefs_to`, `find_bytes`, `entity_query`, `trace_data_flow`, `analyze_function`, and `disasm`.
- Documentation evidence: target page [UID:0003G7], containing map [UID:0003CW], aggregate [UID:000269], successor [UID:0002OP], [UID:00038L] `ReconnectDialogMethods`, [UID:0001JC] `TerminalPaneStreamParser`, [UID:0001HU] `QueueAndSendPacket`, [UID:0001HW] `SendPositionUpdate`, [UID:0000N0] `ReconnectDialog`, [UID:0000OI] `TerminalPane`, [UID:0000DD]/[UID:0000NS] `Socket`, [UID:0000MV] `ProtocolSend`, [UID:0000NP] `Session`, [UID:0001QH] `client_network`, [UID:000262] `PaletteReadOnlyData`, and `proposed-source-tree.md`.
- Negative evidence: no xrefs to interior suffix bytes, no RVA-form references, no hidden ANSI duplicate, no shared packet-literal table/global, no sole owner across both consumers, and no independent source/debug/metadata breadcrumb for a new owner.

## IDA MCP Facts

### Function/range facts
- `server_health` reported `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready.
- `get_bytes 0x00622f1c size 0x48` returned the containing tail and successor start:

```text
4c 00 65 00 61 00 76 00 65 00 00 00
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00
4e 00 6f 00 00 00 00 00
59 00 65 00 73 00 00 00
62 61 72 61 6d 00 00 00
bc eb 64 00 00 4b 55 00 10 4b 4f 00 c0 b6 41 00
```

- `get_bytes 0x00622f4c size 8` returned exactly `62 61 72 61 6d 00 00 00`.
- `get_bytes 0x00622f54 size 16` returned Region vtable/RTTI data, confirming the successor boundary starts after the two target alignment zeros.

### Data/table/padding facts
- `get_string 0x00622f4c` returns `baram`.
- `get_string 0x00622f4d` returns suffix `aram`, and `get_string 0x00622f50` returns suffix `m`; neither suffix address has xrefs.
- `get_string 0x00622f54` returns no string, matching the successor Region data page.
- `entity_query names 0x00622f10-0x00622f70` lists `aBaram_0` at `0x00622f4c`, `??_7Region@@6B@` at `0x00622f58`, and `??_7RightButtonMenuPane@@6B@` at `0x00622f68`. The neighboring wide-string interior names `aAve` and `aConnect` are already explained by [UID:0003G3]/[UID:0003G4] as IDA decode artifacts.

### Xref facts
- `xrefs_to 0x00622f4c` returns exactly two data xrefs:
  - `0x00554276` inside `sub_554210`, documented by [UID:00038L] as `ReconnectDialog::OnButtonClick`.
  - `0x0058b3fc` inside `sub_58B130`, documented by [UID:0001JC] as `TerminalPane::ParseTerminalStream`.
- `xrefs_to 0x00622f4d`, `0x00622f50`, and `0x00622f54` return zero xrefs. No suffix split or endpoint adjustment is justified.
- `trace_data_flow 0x00622f4c backward max_depth=2` reaches only the two string pushes and nearby control-flow predecessors:
  - `0x00554276`: `push offset aBaram_0; "baram"`.
  - `0x0058b3fc`: `push offset aBaram_0; "baram"`.

### Pattern-search facts
- ANSI `baram\0` pattern `62 61 72 61 6d 00`: one match at `0x00622f4c`.
- Full target bytes `62 61 72 61 6d 00 00 00`: one match at `0x00622f4c`.
- Absolute little-endian VA `0x00622f4c` pattern `4c 2f 62 00`: exactly two operand-byte hits at `0x00554277` and `0x0058b3fd`.
- Interior VA patterns `4d 2f 62 00` and `50 2f 62 00`: zero hits.
- RVA-form target pattern `4c 2f 22 00`: zero hits.
- UTF-16LE `baram` pattern `62 00 61 00 72 00 61 00 6d 00`: one match at `0x006217c4`, but this is the prefix of UTF-16LE `baram.pal` in [UID:000262] `PaletteReadOnlyData`, not the ANSI packet literal.

### Separate `baram.pal` disambiguation
- `get_bytes 0x006217c4 size 0x18` returns UTF-16LE `baram.pal\0` followed by the next palette filename.
- `xrefs_to 0x006217c4` returns three data xrefs from `0x00543700` / `PaletteLib` constructor code at `0x0054384f`, `0x00543887`, and `0x005438c3`.
- Absolute VA pattern `c4 17 62 00` also has exactly those three Palette constructor hits; RVA-form `c4 17 22 00` has none.
- [UID:000262] documents `0x006217c4` as the base palette filename `baram.pal`, attached to [UID:0000MA] `Palette`. It is not a packet-source or ownership lead for [UID:0003G7].

### Function ownership facts
- `analyze_function 0x00554210` shows the reconnect-button branch:

```text
sub_443A00(Buffer, 0x80u, "baram", ...);  /*0x554287*/
sub_574BB0(Buffer, 5);                     /*0x55429e*/
sub_574D40(dword_67A7EC);                  /*0x5542a9*/
```

- `disasm 0x00554210` confirms the exact instruction sequence:
  - `0x00554276`: `push offset aBaram_0; "baram"`.
  - `0x00554287`: `call sub_443A00`.
  - `0x0055429b`: `push 5`.
  - `0x0055429e`: `call sub_574BB0`.
  - `0x005542a9`: `call sub_574D40`.
- `analyze_function 0x0058b130` reports strings `%I\n</RunRegistry=`, telnet-format strings, `dumb%c%c`, and `baram`; callees include `sub_443A00`, `sub_574BB0`, and `sub_574D40`.
- `disasm 0x0058b130` confirms the terminal handoff sequence:
  - `0x0058b3fc`: `push offset aBaram_0; "baram"`.
  - `0x0058b40d`: `call sub_443A00`.
  - `0x0058b421`: `push 5`.
  - `0x0058b424`: `call sub_574BB0`.
  - `0x0058b42f`: `call sub_574D40`.
- `analyze_function 0x00574d40` confirms [UID:0001HW] `SendPositionUpdate` has exactly two direct callers: `sub_554210` and `sub_58B130`.
- [UID:0001HU] `QueueAndSendPacket` is the generic Socket-owned queue/send wrapper; its page documents 416 code refs across 197 modeled callers and warns not to move feature packet builders to [UID:0000MV] `ProtocolSend` solely because they call the wrapper.

### Negative IDA facts
- No xrefs to target interior suffix starts `0x00622f4d` or `0x00622f50`.
- No xrefs to `0x00622f54` from this target; the successor Region vtable page starts there and has its own class/vtable evidence beginning at `0x00622f58`.
- No additional ANSI `baram\0` spelling.
- No target RVA-form pointer hits.
- No table/global/initializer uses the `0x00622f4c` address outside the two direct code consumers.
- No evidence that either consumer delegates the `baram` send to a shared helper; both call sites independently format the literal and call the shared send/position helpers.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f4c-0x00622f54` | [UID:0003G7] `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md` | ANSI `baram` packet text plus two alignment bytes | `TRUE` | blank | `88/93` current; `89/94` recommended | Keep unassigned |
| `0x00622f1c-0x00622f28` | [UID:0003G3] `SharedLeaveWideString` | Pooled reconnect/terminal `Leave` label | `TRUE` | blank | `89/94` after accepted B001 report | Same pooled-literal precedent, but UI label |
| `0x00622f28-0x00622f3c` | [UID:0003G4] `SharedReconnectWideString` | Pooled reconnect/terminal `Reconnect` label | `TRUE` | blank | `89/94` after accepted B001 report | Same pooled-literal precedent, but UI label |
| `0x00622f3c-0x00622f44` | [UID:0003G5] `CopyWindowNoButtonWideString` | CopyWindow-only `No` label | `TRUE` | [UID:000039] `CopyWindow` | documented | Assigned; not a G7 owner |
| `0x00622f44-0x00622f4c` | [UID:0003G6] `CopyWindowYesButtonWideString` | CopyWindow-only `Yes` label | `TRUE` | [UID:000039] `CopyWindow` | documented | Assigned; not a G7 owner |
| `0x00622f1c-0x00622f54` | [UID:0003CW] `ReconnectTerminalCopyStringTailMap` | Mixed string tail map | `FALSE` | blank | `89/93` | Correct non-emitting container |
| `0x00622d24-0x00622f54` | [UID:000269] `QueueReconnectCopyReadOnlyData` | Mixed Queue/Reconnect/Copy/string `.rdata` index | `FALSE` | blank | `88/94` | Correct non-emitting container |
| `0x00622f54-0x00622f64` | [UID:0002OP] `RegionVtableData` | Region vtable successor | `TRUE` | [UID:0000BV] `Region` | `87/92` | Boundary successor only |
| `0x006217c4` | [UID:000262] `PaletteReadOnlyData` | UTF-16LE `baram.pal` palette filename | `TRUE` | [UID:0000MA] `Palette` | `82/88` | Separate Palette filename, not a packet lead |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00554276` | `ReconnectDialog::OnButtonClick` pushes `aBaram_0` | Reconnect-button path formats the packet text locally |
| `0x0055429e` | `ReconnectDialog::OnButtonClick` calls [UID:0001HU] `QueueAndSendPacket` after `push 5` | Sends exactly five packet bytes |
| `0x005542a9` | `ReconnectDialog::OnButtonClick` calls [UID:0001HW] `SendPositionUpdate` | Same branch sends position/status immediately after `baram` |
| `0x0058b3fc` | `TerminalPane::ParseTerminalStream` pushes `aBaram_0` | Terminal handoff path formats the same packet text locally |
| `0x0058b424` | `TerminalPane::ParseTerminalStream` calls [UID:0001HU] `QueueAndSendPacket` after `push 5` | Sends exactly five packet bytes |
| `0x0058b42f` | `TerminalPane::ParseTerminalStream` calls [UID:0001HW] `SendPositionUpdate` | Same terminal branch sends position/status immediately after `baram` |
| `0x00574d40` | `SendPositionUpdate` callers are exactly `sub_554210` and `sub_58B130` | Confirms paired reconnect/terminal use, but the helper itself is Socket-owned |
| `0x006217c4` | Palette constructor refs at `0x0054384f`, `0x00543887`, `0x005438c3` | Separate `baram.pal` filename, not the target literal |

## Documentation Evidence And IDA Status

### Existing docs that support the conclusion
- [UID:0003G7] already records exact bytes, two direct xrefs, two pointer/immediate hits, and parent-blank state. Live IDA MCP reconfirmed and sharpened those facts.
- [UID:0003CW] and [UID:000269] correctly classify the physical `.rdata` containers as non-emitting mixed-owner maps whose exact children carry source semantics.
- [UID:00038L] documents `ReconnectDialog::OnButtonClick` as owned by [UID:0000BR] `ReconnectDialog` / [UID:0000N0] `ReconnectDialog`, and live IDA confirms that method formats/sends `baram`.
- [UID:0001JC] documents the terminal stream parser as [UID:0000OI] `TerminalPane` code referenced through the terminal vtable/data slot, and live IDA confirms it formats/sends `baram`.
- [UID:0001HW] documents `SendPositionUpdate` as Socket-owned with exactly the same two direct callers. This supports a shared session handoff behavior but does not make Socket the owner of caller-local packet text.
- [UID:0001HU], [UID:0000DD], [UID:0000NS], and [UID:0001QH] document `QueueAndSendPacket` and the outbound transport as Socket/request-queue machinery, while keeping feature packet builders with their feature modules.
- [UID:0000MV] and [UID:0000NP] explicitly remain `PROPOSED_RECONSTRUCTION_PATH:"NONE"` placeholders until stronger shared owner evidence appears.
- [UID:000262] confirms the separate UTF-16 `baram.pal` match belongs to Palette filename data.

### Existing docs that are stale, incomplete, or contradicted
- The target page and current coverage row say the audit found only one `baram` spelling. That is correct for ANSI `baram\0`, but B001 found the separate UTF-16LE `baram.pal` prefix at `0x006217c4`. The recommended refresh should phrase uniqueness as "only one ANSI `baram\0` packet spelling" and explicitly reject `baram.pal` as a packet-owner lead.
- [UID:0001JC] is still only `82/84`, but its TerminalPane ownership is supported by its [UID:0000OI] file parent at `87/85`, the terminal vtable/data slot, and the live IDA call-site sequence. This does not block G7's no-parent decision because the issue is shared ownership, not a below-gate parent.
- `by-project-structure/proposed-source-tree.md` still lists `ProtocolSend.cpp` and `Session.cpp` as possible network placeholders, but both are documented as non-promoted until new helper clustering proves them.

### Generated/coverage report state
- `auto-generated/-ag-memory-coverage.md` currently reports [UID:0003G7] as `unassigned`, which is the correct autogen state.
- `by-memory/-coverage-report.md` currently has a `0003G7` row under [UID:0003CW] at line `3580`. Replacement row text is provided below.
- No direct edit was made to `by-memory/-coverage-report.md`.

## Ranked Ownership Analysis

### 1. Parent-blank pooled source packet literal - accepted
- Evidence for:
  - The target is exactly one ANSI `baram\0` packet literal plus two alignment bytes.
  - There is exactly one ANSI `baram\0` spelling in the image.
  - There are exactly two direct absolute-immediate consumers, one in `ReconnectDialog::OnButtonClick` and one in `TerminalPane::ParseTerminalStream`.
  - Both consumers independently format the literal into a local buffer, send five bytes through `QueueAndSendPacket`, and then call `SendPositionUpdate`.
  - No suffix/interior, RVA, table, global, or initializer evidence points to a shared declaration.
  - Existing B001 decisions for sibling [UID:0003G3]/[UID:0003G4] establish the correct pooled-literal handling pattern: source-authored but not owned by a single physical-address parent.
- Evidence against:
  - Rebuild still needs the text in source code. Parent-blank does not mean ignored or runtime/compiler-only.
- Decision:
  - Accepted. Keep the memory child reconstructable but unassigned; final source should write `"baram"` at each semantic send site or use a proven local helper only if a future source-level audit finds one.

### 2. [UID:0000N0] `ReconnectDialog` - best existing candidate if forced, rejected
- Evidence for:
  - One of two direct xrefs is in `ReconnectDialog::OnButtonClick`.
  - The literal is physically adjacent to `ReconnectDialog` and `ConnectionClosedDialog` vtable data in [UID:000269].
  - `ReconnectDialog` owns the reconnect/cancel branch that sends `baram`, then sends a position update.
  - `ReconnectDialog` file and class parents clear the 85/85 gate.
- Evidence against:
  - The second direct xref is an independent `TerminalPane` stream-parser handoff at `0x0058b3fc`.
  - The TerminalPane parser formats and sends `baram` itself; it does not call a `ReconnectDialog` helper for this packet text.
  - Physical adjacency in a mixed `.rdata` tail is weak evidence under the inference rules, especially after exact children show CopyWindow, ReconnectDialog, TerminalPane, and Region boundaries interleaved nearby.
- Decision:
  - Rejected. It is the marginal best existing owner if forced by adjacency and reconnect semantics, but assigning the pooled literal to `ReconnectDialog` would misroute TerminalPane's real source use.

### 3. [UID:0000OI] `TerminalPane` - rejected
- Evidence for:
  - One of two direct xrefs is in the TerminalPane stream parser.
  - The terminal use is direct and source-family coherent: the parser state reaches a login handoff branch, sends `baram`, sends position/status, closes/hides terminal state, and transitions into normal UI flow.
  - `TerminalPane` clears the file-level parent gate at `87/85`.
- Evidence against:
  - The other direct xref is in `ReconnectDialog::OnButtonClick`, not TerminalPane code.
  - The physical `.rdata` neighborhood is closer to reconnect/copy/Region data, not terminal vtables; adjacency therefore does not help TerminalPane over ReconnectDialog.
- Decision:
  - Rejected. TerminalPane proves shared use and blocks ReconnectDialog ownership, but it is not sole owner.

### 4. [UID:0000DD] / [UID:0000NS] `Socket` - rejected as direct owner of the literal
- Evidence for:
  - Both call sites pass through Socket-owned send machinery.
  - [UID:0001HU] `QueueAndSendPacket` and [UID:0001HW] `SendPositionUpdate` are attached to Socket.
  - `g_packetSender` lifetime is documented as Socket-owned.
- Evidence against:
  - Socket owns transport, queueing, final framing, and the position-update helper, not caller-local feature packet text.
  - [UID:0001HU] has hundreds of feature callers; its own docs explicitly say feature/UI code builds packet bytes before calling the shared wrapper.
  - Assigning `"baram"` to Socket would collapse feature protocol payload construction into the transport class without a shared Socket method or declaration that owns this text.
- Decision:
  - Rejected. Socket is a dependency and send-mechanism owner, not the direct source owner for [UID:0003G7].

### 5. [UID:0000MV] `ProtocolSend` or [UID:0000NP] `Session` - rejected
- Evidence for:
  - `baram` is a game-protocol/session handoff packet text used by two feature paths.
  - The paired `SendPositionUpdate` behavior could suggest a session recovery handshake.
- Evidence against:
  - Both pages are deliberate non-promoted placeholders with `PROPOSED_RECONSTRUCTION_PATH:"NONE"`.
  - `client_network.md` says feature packet builders should stay with feature files unless a central `ProtocolSend.cpp` module is proven.
  - No central helper, table, import/source provenance, generated file, or metadata ties this literal to a standalone protocol/session source unit.
- Decision:
  - Rejected. This one pooled literal is not enough to create or activate a central packet/session source owner.

### 6. Physical container parents [UID:0003CW] / [UID:000269] - rejected
- Evidence for:
  - The target is physically nested under both maps.
  - The maps document the target and sibling strings.
- Evidence against:
  - Both are non-emitting mixed-owner containers, not source-level owners.
  - Exact children carry source semantics; assigning G7 to a container would bypass direct ownership.
- Decision:
  - Rejected as direct parents. They remain useful evidence maps only.

### 7. [UID:000262] `Palette` / `baram.pal` - rejected
- Evidence for:
  - Live IDA found a separate UTF-16LE `baram` pattern at `0x006217c4`.
- Evidence against:
  - The bytes are the prefix of UTF-16LE `baram.pal`, not ANSI `baram\0`.
  - Its xrefs are three Palette constructor refs, and the documented owner is [UID:0000MA] `Palette`.
  - No xref or pointer pattern connects `0x006217c4` to `0x00622f4c`, ReconnectDialog, TerminalPane, Socket, or packet sending.
- Decision:
  - Rejected. It only corrects the uniqueness wording; it does not affect target ownership.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path considered:
  - `NexusTK/network/SessionRecoveryPackets.cpp`
  - `NexusTK/network/ProtocolSend.cpp`
  - `NexusTK/login/TerminalReconnectHandshake.cpp`
  - a by-global `ReconnectTerminalPacketLiterals` / `g_sessionRecoveryPackets`
- Likely full contents if such a source unit were real:
  - [UID:0003G7] `SharedBaramPacketLiteral`.
  - Possibly [UID:0001HW] `SendPositionUpdate` if the unit represented a session handoff API.
  - Possibly the two call-site sequences in `ReconnectDialog::OnButtonClick` and `TerminalPane::ParseTerminalStream` if there were a real shared helper such as `SendBaramAndPositionUpdate`.
  - It should not include [UID:0003G3]/[UID:0003G4] unless the file were a broad reconnect/terminal prompt-and-packet module; those are UI labels, not packet text.
  - It should not include [UID:0003G5]/[UID:0003G6] because those are proven `CopyWindow` labels.
  - It should not include [UID:000262] `baram.pal`, which is Palette-owned asset filename data.
- Candidate related items rejected:
  - [UID:0001HW] is already Socket-owned and used by exactly the same two callers; it is a shared send helper, not evidence of a shared source file for the literal.
  - [UID:0001HU] is a broad Socket queue wrapper with hundreds of feature callers.
  - [UID:0000MV] and [UID:0000NP] remain placeholders.
  - [UID:0003G3]/[UID:0003G4] are pooled UI labels with separate no-parent reports; they reinforce the pooling pattern but do not create a packet literal file.
- Standalone, narrow, or broad source-file inference:
  - Rejected. The evidence supports compiler/linker literal pooling between two feature-local packet construction sites, not a hand-authored shared packet-literal source module. A new file would have no binary-backed table, initializer, function, global, source metadata, or broader contents to own.

## Negative Evidence Summary
- Checked direct xrefs to `0x00622f4c`, target suffixes `0x00622f4d`/`0x00622f50`, and successor `0x00622f54`.
- Checked exact target bytes, ANSI text pattern, full target pattern, UTF-16 text pattern, absolute VA patterns, interior VA patterns, and RVA-form target pattern.
- Checked the separate UTF-16LE `baram.pal` match and confirmed it belongs to Palette filename data.
- Checked live disassembly around both consumers and confirmed both independently perform the same local format/send sequence.
- Checked `SendPositionUpdate` caller inventory and Socket ownership docs; this explains shared mechanics but does not transfer literal ownership.
- Checked `ProtocolSend`, `Session`, `client_network`, and source-tree placeholder notes; none proves a central packet/source owner.
- Checked containing maps and successor Region page; no boundary or split repair is needed.

## Final Recommendation
- Exact changes applied:
  - Created this research report only.
  - No by-* target documentation was edited.
  - No coverage report was edited.
- Exact parent assignments recommended:
  - Leave `AUTOGEN_PARENT_UID` blank on [UID:0003G7].
  - Leave `AUTOGEN_PARENT_POSITION_OPTIONAL` blank.
  - Leave `RECONSTRUCTION_CPP CODE` blank.
- Exact items left unassigned and why:
  - [UID:0003G7] remains unassigned because it is one physical pooled ANSI packet literal with direct source use in both `ReconnectDialog` and `TerminalPane`.
- Exact future work outside this assignment:
  - Final source reconstruction for `ReconnectDialog::OnButtonClick` and `TerminalPane::ParseTerminalStream` should spell `"baram"` naturally at each semantic send site, or introduce a local shared helper only if future high-confidence source-level analysis proves that helper existed.
  - If future PDB/map/source/debug evidence proves a real session-recovery packet constants source unit, revisit [UID:0003G7] together with [UID:0001HW], [UID:0003G3], and [UID:0003G4].

## Follow-Up Actions

### Supervisor actions
1. Keep the autogen row unassigned. No parent assignment is recommended:

```text
| [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | unassigned |  |  | no |  | `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md` |  |
```

2. Recommended target-page metadata refresh, if applying the B001 evidence update:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

3. Recommended target-page change-log text to append to `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md` if applying the metadata refresh:

```text
- 2026-06-12 Agent-B001 Batch B001-0003G7: Performed ownership/source-family audit. Live IDA MCP against `b001_nexustk` reconfirmed exact ANSI `baram` bytes, exactly one ANSI `baram\0` spelling, exactly two absolute-immediate consumers at `ReconnectDialog::OnButtonClick` and `TerminalPane::ParseTerminalStream`, zero xrefs to suffix/interior starts `0x00622f4d`/`0x00622f50`, no RVA-form target refs, and the clean `0x00622f54` Region successor boundary. B001 also checked the separate UTF-16LE `baram.pal` match at `0x006217c4` and rejected it as Palette-owned filename data, not a packet/source-owner lead. `ReconnectDialog`, `TerminalPane`, `Socket`, `ProtocolSend`, `Session`, physical container parents, Palette, and a new shared packet-literal owner were ranked and rejected as overclaiming direct ownership of the pooled packet literal. Parent remains blank; final source should spell `"baram"` at each semantic send site.
```

4. Recommended `by-memory/-coverage-report.md` replacement row. Replace the existing [UID:0003G7] row under [UID:0003CW] after [UID:0003G6] and before the `0x00622f54` Region successor:

```text
            - [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) 0x00622f4c-0x00622f54 | string-data | SharedBaramPacketLiteral : reconstructable : 89% : very strong : ANSI `baram` packet literal; B001-0003G7 live IDA MCP confirmed exact `62 61 72 61 6d 00 00 00` bytes, exactly one ANSI `baram\0` packet spelling, exactly two absolute-immediate consumers from `ReconnectDialog::OnButtonClick` and `TerminalPane::ParseTerminalStream`, both formatting/sending five bytes through [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) before [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md), zero refs to suffix/interior starts at `0x00622f4d`/`0x00622f50`, no RVA-form target refs, and clean successor boundary at [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md); separate UTF-16LE `baram.pal` at [UID:000262][0x0062179c-0x006219e8.PaletteReadOnlyData](by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md) is Palette filename data and not a packet-owner lead. Parent remains blank because [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md), [UID:0000DD][Socket](by-class/Socket.md), [UID:0000MV][ProtocolSend](by-file/ProtocolSend.md), [UID:0000NP][Session](by-file/Session.md), physical container parents, Palette, and a new shared packet-literal owner were all rejected as overclaiming pooled literal ownership.
```

### A-agent actions
- No A-agent split repair is needed for this target.
- When reconstructing the two call-site functions, preserve natural local packet text at the send sites rather than introducing a global constant solely to match pooled `.rdata`.

### B001 future research actions
- None for [UID:0003G7] unless future source/debug/map evidence appears.
- If later B-agent work revisits `ProtocolSend` or session recovery helpers, use this report as a negative constraint: the `"baram"` literal alone is not central-owner evidence.

## Confidence
- Recommendation confidence: `94`. Direct bytes, direct xrefs, pattern searches, disassembly, function analysis, and documentation all agree that this is an exact shared ANSI packet literal with two real feature consumers and no single direct owner.
- Score confidence: `89/94` is justified if the supervisor applies the evidence refresh. It stays below the 95 gate because final source reconstruction has not audited both dependent call-site bodies to final C++ quality, and stripped-binary evidence cannot prove whether original source used duplicated literals or a small local helper.
- Remaining uncertainty:
  - The original source spelling could have been two local `"baram"` literals, a macro, or a small helper local to one feature area. The binary only proves a pooled physical cell and two use sites.
  - That uncertainty does not justify parent assignment because no sole owner or shared source declaration is present.

## Validator Results
- Command run during this B001 pass on the current target:

> Executable block R001 was removed from this report and preserved verbatim in [0003G7-SharedBaramPacketLiteral-B001-0003G7-removed.md](0003G7-SharedBaramPacketLiteral-B001-0003G7-removed.md). The archived block is non-authoritative and must not be executed.

- Result: target file scanned successfully in dry-run mode; UID header exists; file reported `ok`.
- No validator command was required for this report file itself.
- No unresolved validator warnings/errors are introduced by this research report.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/0003G7-SharedBaramPacketLiteral-B001-0003G7.md`.
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none. Supervisor owns report execution and archival.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G7","source_path":"executed-b-agent-research/B001/0003G7-SharedBaramPacketLiteral-B001-0003G7.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
