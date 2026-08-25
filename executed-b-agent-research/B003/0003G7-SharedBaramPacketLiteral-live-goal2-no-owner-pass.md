** TARGET-REPORT-UID:0003G7 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G7 **
# Final Recommendation

Keep [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](../../../../../by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) unchanged:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N0,0000OI`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE` blank
- Scores unchanged at `COMPLETION:89`, `CONFIDENCE:94`

Fresh live IDA MCP evidence on 2026-06-14 confirms this is one ANSI `baram` packet literal at `0x00622f4c-0x00622f54`, with exactly two direct source-use references: `0x00554276` in ReconnectDialog method `sub_554210`, and `0x0058b3fc` in TerminalPane stream parser `sub_58B130`. Both callers format `"baram"`, send five bytes through `sub_574BB0`, and then call `sub_574D40`. No single canonical declaration owner is proven, and neither consumer should be promoted to semantic owner of the pooled literal.

The correct current output-emission model is therefore no canonical owner with both proven file-root emitters: [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md). No split, merge, reclassification, new child page, IDA repair, owner change, emitter change, score change, or shared coverage-report edit is recommended.

## Target And Scope

- Assignment: Agent-B003 live Goal 2 no-owner memory pass.
- Target UID: `0003G7`.
- Target path: `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md`.
- Current generated state: `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000N0,0000OI`, `RECONSTRUCTABLE:TRUE`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, active 2026-06-14 live Goal 2 no-owner memory pass.
- Prior report read as evidence only: `Agent-B001/research/executed/0003G7-SharedBaramPacketLiteral-fresh-no-owner-pass.md`.
- This pass used current documentation and fresh IDA MCP evidence. Prior reports were not treated as authority.

## Current Documentation Context

The target page currently describes the exact bytes:

```text
0x00622f4c: 62 61 72 61 6d 00 00 00
```

That is ANSI `baram`, followed by tail alignment before the `Region` data at `0x00622f54`.

The target is the final child of [UID:0003CW][0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md), a non-emitting mixed tail map. The enclosing map's exact children are:

| Range | UID | Current route |
| --- | --- | --- |
| `0x00622f1c-0x00622f28` | `0003G3` | shared UTF-16 `Leave`, no canonical owner, emitters `0000N0,0000OI` |
| `0x00622f28-0x00622f3c` | `0003G4` | shared UTF-16 `Reconnect`, no canonical owner, emitters `0000N0,0000OI` |
| `0x00622f3c-0x00622f44` | `0003G5` | CopyWindow-only UTF-16 `No`, assigned to CopyWindow |
| `0x00622f44-0x00622f4c` | `0003G6` | CopyWindow-only UTF-16 `Yes`, assigned to CopyWindow |
| `0x00622f4c-0x00622f54` | `0003G7` | shared ANSI `baram`, no canonical owner, emitters `0000N0,0000OI` |

[UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) is a valid file-root emitter at `NexusTK/network/ReconnectDialog.cpp`, currently `87/88`. Its ReconnectDialog class child [UID:0000BR][ReconnectDialog](../../../../../by-class/ReconnectDialog.md) is `86/88`, and exact method page [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](../../../../../by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) covers `sub_554210`.

[UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) is a valid file-root emitter at `NexusTK/login/TerminalPane.cpp`, currently `87/85`. Its class page [UID:0000EG][TerminalPane](../../../../../by-class/TerminalPane.md) is `87/88`, and exact stream parser page [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](../../../../../by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) documents `sub_58B130` as TerminalPane stream parsing.

Generated coverage currently lists `0003G7` as no-owner with emitters `0000N0,0000OI`. The primary generated output column shows `auto-generated/NexusTK/network/ReconnectDialog.cpp`; the emitter-detail section lists both ReconnectDialog and TerminalPane.

## Live IDA MCP Evidence

IDA MCP session used for this pass:

- Session: `a001_goal2_class_batch`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`

Numeric conversion note: IDA MCP `int_convert` checked `0x8 -> 8`, `0x38 -> 56`, `0x1f6 -> 502`, and `0x31c -> 796` during this pass.

### Byte And String Facts

- `get_bytes(0x00622f4c, 8)` returned `62 61 72 61 6d 00 00 00`.
- `get_string(0x00622f4c)` returned `baram`.
- `get_bytes(0x00622f1c, 0x48)` showed the surrounding tail sequence: UTF-16 `Leave`, UTF-16 `Reconnect`, UTF-16 `No`, UTF-16 `Yes`, ANSI `baram`, then the Region vtable/RTTI data.
- `get_bytes(0x00622f54, 16)` returned `bc eb 64 00 00 4b 55 00 10 4b 4f 00 c0 b6 41 00`, confirming the successor data starts immediately after the target.
- `get_bytes(0x006217c4, 24)` returned UTF-16LE `baram.pal` bytes, proving the separate Palette string is a different encoding and context.

IDA string rendering for the surrounding wide strings is unreliable because some UTF-16 starts are interpreted as names/pointers, so the byte decoding above is the stronger fact for the tail map.

### Xref Facts

`xref_query` for the target and boundaries reported:

| Address | Result |
| --- | --- |
| `0x00622f4c` | two data refs: `0x00554276` in `sub_554210`; `0x0058b3fc` in `sub_58B130` |
| `0x00622f4d` | no xrefs |
| `0x00622f50` | no xrefs |
| `0x00622f54` | no xrefs to the boundary as part of this literal |
| `0x006217c4` | three Palette constructor refs inside `sub_543700` |

Surrounding child refs also support the existing map split:

- `0x00622f1c` and `0x00622f28` each have four reconnect/terminal prompt refs.
- `0x00622f3c` and `0x00622f44` each have two CopyWindow constructor refs.
- `0x00622f4c` has only the two ReconnectDialog/TerminalPane packet refs.

### Search Facts

IDA MCP `find_bytes` found:

- ANSI `62 61 72 61 6d 00 00 00`: one match, `0x622f4c`.
- ANSI `62 61 72 61 6d 00`: one match, `0x622f4c`.
- bare UTF-16LE `baram\0`: zero matches.
- UTF-16LE `baram.pal`: one match, `0x6217c4`.
- absolute target address bytes `4C 2F 62 00`: two matches, `0x554277` and `0x58b3fd`.
- `push 0x00622f4c` bytes `68 4C 2F 62 00`: two matches, `0x554276` and `0x58b3fc`.
- suffix/boundary address patterns for `0x00622f4d`, `0x00622f50`, and `0x00622f54`: zero push-immediate matches.

### Function And Decompile Facts

`lookup_funcs` reported:

- `0x00554210` / `0x00554276` is `sub_554210`, size `0x1f6` / 502 bytes, Verified with IDA MCP `int_convert`.
- `0x0058b130` / `0x0058b3fc` is `sub_58B130`, size `0x31c` / 796 bytes, Verified with IDA MCP `int_convert`.
- `0x00574bb0` is `sub_574BB0`, size `0x63`.
- `0x00574d40` is `sub_574D40`, size `0x104` / 260 bytes, Verified with IDA MCP `int_convert`.
- `0x00622f4c`, `0x00622f54`, and `0x006217c4` are not functions.

Instruction and decompile evidence:

- `sub_554210` at `0x00554276` executes `push offset aBaram_0; "baram"`.
- The same ReconnectDialog path formats `"baram"` into a local `Buffer`, calls `sub_574BB0(Buffer, 5)` at `0x0055429e`, then calls `sub_574D40(dword_67A7EC)` at `0x005542a9`.
- `sub_58B130` at `0x0058b3fc` executes `push offset aBaram_0; "baram"`.
- The same TerminalPane stream-parser branch formats `"baram"` into local `Src`, calls `sub_574BB0(Src, 5)` at `0x0058b424`, then calls `sub_574D40(dword_67A7EC)` at `0x0058b42f`.
- `xref_query(0x00574d40, direction=to, xref_type=code)` returned exactly two callers: `0x005542a9` and `0x0058b42f`.
- `xref_query(0x00574bb0, direction=to, xref_type=code)` reports broad fan-in, with 416 total code refs. That confirms it is shared Socket send infrastructure, not a semantic owner for this literal.
- `analyze_component(0x00554210,0x0058b130,0x00574bb0,0x00574d40)` lists shared global/string usage `0x622f4c aBaram_0` only by `sub_554210` and `sub_58B130`, with internal call edges from both source-use functions to `sub_574BB0` and `sub_574D40`.

## Candidate Owner And Emitter Analysis

### Accepted Model: No Canonical Owner With Two Emitters

`CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI` is the strongest current model.

Evidence for:

- The target is one physical ANSI literal with exactly two direct source-use references.
- The two direct references sit in different source families: ReconnectDialog and TerminalPane.
- Both source-use paths perform equivalent semantic work: format `"baram"`, send five bytes through the packet queue helper, then call position update.
- Both file roots clear the current emitter gate and route to generated source roots.
- IDA does not show a standalone shared constant, table, initializer, or source-level declaration owner.
- Current by-structure guidance allows pooled literals to remain `CANONICAL_OWNER:NONE` while emitting through multiple proven source-use contexts.

Evidence against:

- The stripped binary cannot prove whether the original source contained two independent local string literals that were pooled, or one named shared constant used by both paths.

Decision: accept. The remaining uncertainty argues against choosing a canonical owner, while the two direct source-use contexts justify both emitters.

### ReconnectDialog As Canonical Owner

Evidence for:

- `sub_554210` directly references `0x00622f4c`.
- The ReconnectDialog file and class pages clear `85/85`.
- The ReconnectDialog path formats and sends the literal as part of reconnect button handling.

Evidence against:

- TerminalPane has an equally direct source-use reference.
- No IDA fact shows ReconnectDialog declared a shared literal for TerminalPane to consume.
- Assigning ReconnectDialog as canonical owner would hide the TerminalPane source-use route.

Decision: reject as canonical owner; keep as emitter `0000N0`.

### TerminalPane As Canonical Owner

Evidence for:

- `sub_58B130` directly references `0x00622f4c`.
- The TerminalPane file and class pages clear `85/85`.
- The TerminalPane stream-parser path formats and sends the same five-byte literal during terminal login handoff.

Evidence against:

- ReconnectDialog has an equally direct source-use reference.
- No IDA fact shows TerminalPane declared a shared literal for ReconnectDialog to consume.
- The exact parser method page is below `85/85`, although the file/class roots are strong enough for emitter routing.

Decision: reject as canonical owner; keep as emitter `0000OI`.

### Socket / QueueAndSendPacket / SendPositionUpdate

Evidence for:

- Both source-use paths call `sub_574BB0` and `sub_574D40` after formatting `"baram"`.
- These helpers are network-send infrastructure.

Evidence against:

- The literal is already formatted into caller-local buffers before `sub_574BB0` is invoked.
- `sub_574BB0` has 416 code refs, so it is a generic queue helper, not the semantic owner of this one packet spelling.
- `sub_574D40` has exactly two callers but does not reference the literal itself; it builds the follow-up position/status packet.
- Existing docs route these helpers to Socket class/source ownership, not to a shared packet-literal owner.

Decision: reject as owner and emitter for `0003G7`. Socket is a dependency of both emitters, not the source-use placement for the literal.

### ProtocolSend / Session / New Shared Packet Literal File

Evidence for:

- The literal is protocol-adjacent and used by two feature paths.
- A shared named constant is theoretically possible.

Evidence against:

- [UID:0000MV][ProtocolSend](../../../../../by-file/ProtocolSend.md) and [UID:0000NP][Session](../../../../../by-file/Session.md) both have `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and are non-output planning placeholders.
- IDA shows no source-level shared constant object, packet-literal table, initializer, or dedicated function around `0x00622f4c`.
- The surrounding range is mixed UI/string-tail and Region vtable adjacency, not a cohesive protocol constants table.
- Creating a new packet-literals file from one pooled string would invent source structure.

Decision: reject. No new owner or source file is justified.

### Physical Containers, Palette, Region, Or CopyWindow

Evidence for:

- The target is physically in a mixed tail map after Reconnect/CopyWindow labels and before Region data.
- A separate UTF-16 `baram.pal` spelling exists in Palette read-only data.

Evidence against:

- [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) and [UID:000269][QueueReconnectCopyReadOnlyData](../../../../../by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md) are non-emitting index/container pages.
- `0x00622f54` starts [UID:0002OP][RegionVtableData](../../../../../by-memory/0x00622f54-0x00622f64.RegionVtableData.md), and IDA finds no xrefs to it as part of the `baram` literal.
- The UTF-16 `baram.pal` at `0x006217c4` has Palette constructor refs, not ReconnectDialog/TerminalPane packet refs.
- CopyWindow owns the `No`/`Yes` sibling strings, not this ANSI packet literal.

Decision: reject all as canonical owners or emitters for this target.

## Split, Merge, Reclassification, And IDA Repair Analysis

- No split is needed. The range is one complete ANSI `baram\0` literal plus alignment tail, and IDA finds no direct references to `0x00622f4d` or `0x00622f50`.
- No merge with predecessor is justified. The predecessor `No`/`Yes` and shared reconnect labels have different xref sets and source routes.
- No merge with successor is justified. `0x00622f54` begins `RegionVtableData` and is not a string continuation.
- No reclassification is justified. This is reconstructable source-authored string data; the exact storage is compiler/linker output, but the source-use literal must be represented in reconstructed source.
- No IDA repair is needed. The IDA label `aBaram_0` is mechanically acceptable and the documentation name `SharedBaramPacketLiteral` is accurate.
- No final target-level C++ should be added. A standalone declaration would overclaim source shape. Future ReconnectDialog and TerminalPane method rewrites should spell `"baram"` at the two proven use sites.

## Reconstructable No-Owner Defense

This is not a non-emitting dead end. `RECONSTRUCTABLE:TRUE` is correct because the rebuilt source must preserve the `baram` packet text in both source paths. `CANONICAL_OWNER:NONE` is also correct because the binary proves use sites, not a single declaration owner.

The current owner/emitter model separates those two questions:

- `CANONICAL_OWNER` asks which source entity owns the semantic declaration. Current evidence does not prove one.
- `EMITTER_UIDS` asks which source roots need to surface the source item during reconstruction. Current evidence proves two: ReconnectDialog and TerminalPane.

Therefore `CANONICAL_OWNER:NONE` with nonblank `EMITTER_UIDS:0000N0,0000OI` is the correct output-emission route. It allows the generated source to contain the literal at both semantic call sites without inventing a global constant or assigning ownership to the larger consumer.

## Exact Recommended Changes

No shared documentation changes are recommended.

Keep target metadata exactly:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No replacement row is needed for `by-memory/-coverage-report.md`; the current row already states the correct owner/emitter route and supporting evidence. If the active tracker needs a close-out row, use:

```text
| `0003G7` | 0x00622f4c-0x00622f54.SharedBaramPacketLiteral | `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md` | Agent-B003 | 2026-06-14 | complete-no-change | `Agent-B003/research/0003G7-SharedBaramPacketLiteral-live-goal2-no-owner-pass.md` | `Agent-B001/research/executed/0003G7-SharedBaramPacketLiteral-fresh-no-owner-pass.md` |
```

## Validation Needs

- Leases: none acquired, because this pass only creates an Agent-B003 research report.
- Validator: not run, because no by-* documentation, validator-managed metadata, generated output, or shared coverage report was edited.
- Dry runs: none used.
- IDA MCP tools used read-only inspection only: `server_health`, `idb_list`, `get_bytes`, `get_string`, `xref_query`, `find_bytes`, `lookup_funcs`, `insn_query`, `decompile`, `entity_query`, `analyze_component`, and `int_convert`.
- Future A-agent validation should occur when method-level ReconnectDialog and TerminalPane C++ is rewritten; each method should retain the `"baram"` source-use where IDA currently proves it.

## Confidence

Recommendation confidence: high.

The exact bytes, string decoding, two source-use xrefs, caller decompilations, helper calls, sibling split, successor boundary, duplicate-literal search, pointer/immediate scan, and Palette disambiguation all agree. The only remaining uncertainty is original declaration style: the stripped binary cannot prove whether the compiler pooled two local literals or a shared named constant. That uncertainty is exactly why the item should remain `CANONICAL_OWNER:NONE` while emitting through both proven source-use file roots.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G7","source_path":"executed-b-agent-research/B003/0003G7-SharedBaramPacketLiteral-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
