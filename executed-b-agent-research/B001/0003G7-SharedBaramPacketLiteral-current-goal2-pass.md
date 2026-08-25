** TARGET-REPORT-UID:0003G7 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G7 **
# 0003G7 SharedBaramPacketLiteral Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](../../../../../by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000N0,0000OI`.
- Final disposition: reconstructable pooled/source-use ANSI packet literal. It should be emitted through the two proven source-use routes, [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md), not assigned to a single canonical owner.
- Required action: no by-memory split, merge, rename, reclassification, score change, emitter change, or coverage-report replacement is required.
- Confidence: high for the current no-owner-with-emitters state; retain target score `89/94`. Do not enter reconstruction C++ because the item is below the current `90/90+` code-entry gate and has no single source declaration owner.

## Supporting Research

## Target
- Target UID: `0003G7`.
- Target path: `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md`.
- Source queue/report row: current `auto-generated/-ag-memory-coverage.md` lists this as `no-owner`, `CANONICAL_OWNER:NONE`, with emitters `0000N0`,`0000OI`.
- Current supervisor classification: Goal 2 no-owner memory current pass, one target only.
- Current scores and parent state: `COMPLETION:89`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `RECONSTRUCTION_CPP`.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B002/research/executed/0003G7-SharedBaramPacketLiteral-second-pass.md`.

## Executive Recommendation
- Keep the target as a shared reconstructable literal with no canonical owner and two emitters.
- The direct IDA facts prove two independent source-use contexts for the same physical literal: `sub_554210` in the ReconnectDialog flow and `sub_58B130` in the TerminalPane parser flow.
- Neither caller is a better semantic declaration owner than the other. The physical `.rdata` bytes are linker-pooled, and by-structure allows `CANONICAL_OWNER:NONE` with multiple emitters for shared literals when source-use output routes are proven.
- No split is needed. The byte range is exactly the ANSI `baram` spelling plus terminator/tail alignment, and there are no refs to suffix/interior starts or to the successor `Region` vtable boundary.

## Supervisor Active Recheck
- This report responds to the assigned current Goal 2 B-agent target `[UID:0003G7] by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md`.
- The assigned item did not require split repair before final reporting. The target is already an exact 8-byte child of the mixed parent [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md).
- Every source-bearing route in scope was rechecked against current documentation plus live IDA MCP and raw PE evidence. No in-scope documentation repair was required.

## Inference Research Guidance Check
- `by-structure.md` treats string literals as source-declared/generated-binary data and separates semantic ownership from output routing. It explicitly allows shared/pooled literals to stay `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for all proven source-use contexts.
- `inference_research.md` cautions that adjacency is weak ownership evidence. This matters here because `baram` sits beside reconnect/copy strings and immediately before Region vtable data, but the direct xrefs, not adjacency, determine the source-use routes.
- Existing documentation was treated as a lead, not authority. The target page, parent aggregate pages, ReconnectDialog, TerminalPane, Socket, ProtocolSend, Session, Palette, and Region pages were checked against live IDA facts where relevant.
- IDA fact: one physical ANSI `baram` literal and two direct code xrefs. Documentation evidence: current by-file/by-memory pages map those callers to ReconnectDialog and TerminalPane. Inference: because both source-use routes are real and no declaration owner is proven, `NONE` plus both emitters remains the strongest model.

## Evidence Standards Used
- Evidence types used: IDA MCP `server_health`, `lookup_funcs`, `get_string`, `get_bytes`, `entity_query`, `xrefs_to`, `xref_query`, `trace_data_flow`, `find_bytes`, `disasm`, `search_text`, and `analyze_component`; raw PE byte scanning and VA/RVA pattern searches; current generated coverage rows; by-memory, by-file, by-class, and placeholder file documentation.
- The evidence is strong enough for the ownership/emitter decision because the literal bytes, xrefs, function bounds, instruction sequence, exact length argument, and negative suffix/RVA refs are all directly confirmed.
- Confidence is not raised above `94` and completion remains `89` because the original source declaration shape is still not recoverable as a single source owner, and the current code-entry gate is not met.

## IDA MCP Facts
- Function/range facts:
  - `server_health` on database `b001_0003gy` reports `NexusTK.exe`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - `lookup_funcs` reports `0x00622f4c`, `0x00622f4d`, `0x00622f50`, `0x00622f54`, and `0x006217c4` are not functions.
  - `lookup_funcs 0x00554210` and `0x00554276` both resolve to `sub_554210`, size `0x1f6`.
  - `lookup_funcs 0x0058b130` and `0x0058b3fc` both resolve to `sub_58B130`, size `0x31c`.
  - `lookup_funcs 0x00574bb0` resolves to `sub_574BB0`, size `0x63`; `lookup_funcs 0x00574d40` resolves to `sub_574D40`, size `0x104`.
- Data/table/padding facts:
  - `get_bytes 0x00622f4c size 8`: `62 61 72 61 6d 00 00 00`.
  - `get_string 0x00622f4c`: `baram`; `get_string 0x00622f54`: no string.
  - `get_bytes 0x00622f1c size 56` shows the preceding wide strings `Leave`, `Reconnect`, `No`, `Yes`, then the target `baram` bytes at the tail.
  - `get_bytes 0x00622f54 size 16`: `bc eb 64 00 00 4b 55 00 10 4b 4f 00 c0 b6 41 00`, the successor Region vtable slice.
  - `entity_query` over `0x00622f1c-0x00622f64` finds one string at `0x622f4c`, text `baram`, and names `aBaram_0` at `0x622f4c` plus `??_7Region@@6B@` at `0x622f58`.
  - `get_bytes 0x006217c4 size 24` shows UTF-16LE `baram.pal` bytes, proving the similar Palette filename spelling is a separate wide-string item.
- Xref facts:
  - `xrefs_to 0x00622f4c` reports exactly two data xrefs: `0x00554276` in `sub_554210` and `0x0058b3fc` in `sub_58B130`.
  - `xref_query include_fn` confirms the same two xrefs and function identities.
  - `xrefs_to` / `xref_query` for `0x00622f4d`, `0x00622f50`, and `0x00622f54` report zero refs.
  - `xrefs_to 0x006217c4` reports three Palette constructor refs in `sub_543700`, separating `baram.pal` from this packet literal.
  - `trace_data_flow backward 0x00622f4c` reports `db 'baram',0` reached by `push offset aBaram_0` at `0x554276` and `0x58b3fc`.
- Caller instruction facts:
  - In `sub_554210`, the relevant block is:
    - `0x554276`: `push offset aBaram_0; "baram"`
    - `0x554287`: `call sub_443A00`
    - `0x55429b`: `push 5; int`
    - `0x55429e`: `call sub_574BB0`
    - `0x5542a9`: `call sub_574D40`
  - In `sub_58B130`, the parallel block is:
    - `0x58b3fc`: `push offset aBaram_0; "baram"`
    - `0x58b40d`: `call sub_443A00`
    - `0x58b421`: `push 5; int`
    - `0x58b424`: `call sub_574BB0`
    - `0x58b42f`: `call sub_574D40`
  - `analyze_component` reports both `sub_554210` and `sub_58B130` contain string `baram`, both call `sub_574BB0`, and both call `sub_574D40`. It lists shared global `aBaram_0` accessed by `sub_554210` and `sub_58B130`.
- Vtable/global/type facts:
  - The successor at `0x00622f54` is Region RTTI/vtable data, not part of the literal. This is consistent with [UID:0002OP][RegionVtableData](../../../../../by-memory/0x00622f54-0x00622f64.RegionVtableData.md), which owns `0x00622f54-0x00622f64` under Region.
  - The send global `dword_67A7EC` appears in both caller blocks before calls to `sub_574BB0` and `sub_574D40`; this supports use of the generic send path, not ownership of the literal by Socket or ProtocolSend.
- Negative IDA facts:
  - No xrefs to `0x00622f4d`, `0x00622f50`, or `0x00622f54`.
  - No additional IDA string entries matching `baram` besides `0x00622f4c`.
  - The UTF-16LE `baram.pal` spelling at `0x006217c4` has Palette constructor refs only, not packet-send refs.

## PE / Raw Evidence
- Raw file scanned: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- File length: `0x28e200` bytes. MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- PE imagebase: `0x00400000`.
- Relevant sections:
  - `.text`: VA `0x00401000-0x0060c4ac`, raw `0x400-0x20ba00`.
  - `.rdata`: VA `0x0060d000-0x0066c0be`, raw `0x20ba00-0x26ac00`.
  - `.data`: VA `0x0066d000-0x0069ce24`, raw `0x26ac00-0x278400`.
  - `.rsrc`: VA `0x0069d000-0x006b2c38`, raw `0x278400-0x28e200`.
- Pattern results:
  - `62 61 72 61 6d 00 00 00`: one hit, file `+0x22194c`, VA `0x00622f4c`.
  - `62 61 72 61 6d 00`: one hit, file `+0x22194c`, VA `0x00622f4c`.
  - UTF-16LE bare `baram\0`: zero hits.
  - UTF-16LE `baram.pal\0`: one hit, file `+0x2201c4`, VA `0x006217c4`.
  - `68 4c 2f 62 00` (`push 0x00622f4c`): two hits, file `+0x153676` VA `0x00554276` and file `+0x18a7fc` VA `0x0058b3fc`.
  - `4c 2f 62 00` (VA immediate `0x00622f4c`): two hits, file `+0x153677` VA `0x00554277` and file `+0x18a7fd` VA `0x0058b3fd`.
  - VA immediates for `0x00622f4d`, `0x00622f50`, and `0x00622f54`: zero hits.
  - RVA-style immediates for `0x00222f4c`, `0x00222f4d`, `0x00222f50`, and `0x00222f54`: zero hits.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00622f4c-0x00622f54` | [UID:0003G7](../../../../../by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | ANSI `baram` packet literal | `TRUE` | `NONE` | `89/94` | Keep `EMITTER_UIDS:0000N0,0000OI` |
| `0x00622f1c-0x00622f54` | [UID:0003CW](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) | Non-reconstructable exact-child map containing shared/copy strings | `FALSE` | `NONE` | `89/93` | Correct container; no edit |
| `0x00622d24-0x00622f54` | [UID:000269](../../../../../by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md) | Larger mixed read-only aggregate | `FALSE` | `NONE` | `88/94` | Correct non-emitting container |
| `0x00554210-0x00554406` | [UID:00038L](../../../../../by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | ReconnectDialog button handler route | `TRUE` | ReconnectDialog class/file context | `86/89` | Proves emitter `0000N0` route |
| `0x0058b130-0x0058b44c` | [UID:0001JC](../../../../../by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) | TerminalPane parser route | `TRUE` | `0000OI` | `82/84` | Function page is below 85/85, but live IDA plus file root prove emitter `0000OI` route |
| `NexusTK/network/ReconnectDialog.cpp` | [UID:0000N0](../../../../../by-file/ReconnectDialog.md) | Source-use emitter for reconnect button route | File root | `FILE` | `87/88` | Keep as emitter |
| `NexusTK/login/TerminalPane.cpp` | [UID:0000OI](../../../../../by-file/TerminalPane.md) | Source-use emitter for terminal login handoff route | File root | `FILE` | `87/85` | Keep as emitter |
| `0x00574bb0-0x00574c13` | [UID:0001HU](../../../../../by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) | Generic queue-and-send helper called by both routes | `TRUE` | Socket class/file context | `89/91` | Reject as literal owner/emitter |
| `0x00574d40-0x00574e44` | [UID:0001HW](../../../../../by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md) | Generic position update helper called after the literal packet send | `TRUE` | Socket class/file context | `87/90` | Reject as literal owner/emitter |
| `0x0062179c-0x006219e8` | [UID:000262](../../../../../by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md) | Palette vtables and wide palette filenames | `TRUE` | `0000MA` | `82/88` | Separate `baram.pal` item, not this target |
| `0x00622f54-0x00622f64` | [UID:0002OP](../../../../../by-memory/0x00622f54-0x00622f64.RegionVtableData.md) | Successor Region vtable data | `TRUE` | `0000BV` | `87/92` | Clean boundary after target |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00554276 -> 0x00622f4c` | `sub_554210` pushes `aBaram_0` | ReconnectDialog route uses the literal directly. |
| `0x00554287` | `sub_554210` calls `sub_443A00` after pushing `baram` and buffer arguments | Formats/copies the literal into a local packet buffer. |
| `0x0055429b` | `sub_554210` pushes `5` | Uses exactly the 5-byte `baram` payload length. |
| `0x0055429e` | `sub_554210` calls `sub_574BB0` | Queues/sends the local packet buffer. |
| `0x005542a9` | `sub_554210` calls `sub_574D40` | Follows with the shared position update path. |
| `0x0058b3fc -> 0x00622f4c` | `sub_58B130` pushes `aBaram_0` | TerminalPane route uses the same literal directly. |
| `0x0058b40d` | `sub_58B130` calls `sub_443A00` after pushing `baram` and buffer arguments | Formats/copies the literal into a local packet buffer. |
| `0x0058b421` | `sub_58B130` pushes `5` | Uses exactly the 5-byte `baram` payload length. |
| `0x0058b424` | `sub_58B130` calls `sub_574BB0` | Queues/sends the local packet buffer. |
| `0x0058b42f` | `sub_58B130` calls `sub_574D40` | Follows with the shared position update path. |
| `0x00622f4d`, `0x00622f50`, `0x00622f54` | No xrefs and no VA/RVA immediate hits | No suffix split or boundary merge is supported. |
| `0x006217c4` | Three refs from `sub_543700` | Separate Palette filename `baram.pal`, not a packet literal. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - The target page already records exact bytes, two xrefs, `CANONICAL_OWNER:NONE`, and `EMITTER_UIDS:0000N0,0000OI`; live IDA and raw PE checks confirmed those facts.
  - [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) documents the reconnect dialog source file and clears `87/88`; live IDA confirms its route uses the literal and queues five bytes.
  - [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) documents the terminal/login pane source file and clears `87/85`; live IDA confirms its parser route uses the same literal and queues five bytes.
  - [UID:0003CW][ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) correctly treats the surrounding map as a non-reconstructable container with exact children.
  - [UID:0002OP][RegionVtableData](../../../../../by-memory/0x00622f54-0x00622f64.RegionVtableData.md) confirms the successor boundary at `0x00622f54`.
  - [UID:000262][PaletteReadOnlyData](../../../../../by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md) confirms the similar wide `baram.pal` spelling belongs to Palette filename data, not the packet literal.
  - [UID:0000DD][Socket](../../../../../by-class/Socket.md), [UID:0001HU][QueueAndSendPacket](../../../../../by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), and [UID:0001HW][SendPositionUpdate](../../../../../by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md) explain the generic send helper path without making it the owner of high-level feature packet strings.
  - [UID:0000MV][ProtocolSend](../../../../../by-file/ProtocolSend.md) and [UID:0000NP][Session](../../../../../by-file/Session.md) remain non-promoted placeholders, matching the rejection of those as current emitters or owners.
- Existing docs that are stale, incomplete, or contradicted:
  - No current target-critical contradiction was found.
  - The TerminalPane exact function page [UID:0001JC](../../../../../by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) remains below `85/85`, so it should not be used alone as a final code-entry basis. The emitter route is still defensible through the file root `0000OI` plus live IDA caller evidence.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` current memory row lists `no-owner`, owner `NONE`, and emitters `0000N0`,`0000OI`; this is correct.
  - `auto-generated/-ag-memory-coverage.md` multiple-emitter row lists [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md); this is correct.
  - `by-memory/-coverage-report.md` already describes the two source-use routes, the raw bytes, the two refs, the lack of suffix refs, and the rejected alternative owners. No direct edit or replacement text is needed from this pass.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with emitters `0000N0,0000OI`
- Evidence for:
  - One physical ANSI literal at `0x00622f4c`, confirmed by IDA bytes and raw PE scan.
  - Exactly two direct code refs, both `push offset aBaram_0`, one in ReconnectDialog behavior and one in TerminalPane behavior.
  - Both callers format/copy the literal, push length `5`, call `sub_574BB0`, and then call `sub_574D40`.
  - By-structure permits no-owner pooled literals with multiple emitters when no single declaration owner exists but multiple source-use routes are proven.
- Evidence against:
  - The literal does have concrete source-use contexts, so it must not be treated as no-owner/non-emitting. This is already solved by the two emitters.
- Decision:
  - Accepted. This is the best current model and should remain unchanged.

### 2. [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) as sole canonical owner
- Evidence for:
  - `sub_554210` directly pushes `aBaram_0`, queues five bytes, and calls the position update path.
  - The ReconnectDialog file and related method page have strong current scores, and the current generated row's default source path points at `NexusTK/network/ReconnectDialog.cpp`.
  - If forced to pick one single owner, this is the least-bad candidate because it has the higher-scored direct method documentation and appears first in the generated source path.
- Evidence against:
  - The TerminalPane parser has an equally direct independent source-use route.
  - Assigning canonical ownership to ReconnectDialog would make a source-use literal from TerminalPane appear owned by an unrelated UI reconnect file.
  - The raw binary shape is a pooled `.rdata` literal, not a ReconnectDialog-exclusive constant or class member.
- Decision:
  - Reject as canonical owner; keep as emitter `0000N0`.

### 3. [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) as sole canonical owner
- Evidence for:
  - `sub_58B130` directly pushes `aBaram_0`, queues five bytes, and calls the position update path.
  - The TerminalPane file root clears `87/85`, and the caller behavior is live-confirmed.
- Evidence against:
  - ReconnectDialog has an equally direct independent source-use route.
  - The exact TerminalPane caller page is still only `82/84`, below child-final confidence for code entry.
  - Assigning canonical ownership to TerminalPane would misplace the reconnect source-use literal.
- Decision:
  - Reject as canonical owner; keep as emitter `0000OI`.

### 4. [UID:0000DD][Socket](../../../../../by-class/Socket.md), [UID:0001HU][QueueAndSendPacket](../../../../../by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), or [UID:0001HW][SendPositionUpdate](../../../../../by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- Evidence for:
  - Both source-use routes call the generic send helpers and use `dword_67A7EC`.
  - `QueueAndSendPacket` and `SendPositionUpdate` are well-documented Socket-related outbound helpers.
- Evidence against:
  - These helpers are consumers of caller-constructed packet bytes, not the authors of the `baram` literal.
  - `analyze_component` shows the string appears in the two caller functions, not in the helper functions.
  - Socket docs explicitly distinguish transport/queue ownership from high-level feature packet builders.
- Decision:
  - Reject as canonical owner and reject as emitter route for this literal.

### 5. [UID:0000MV][ProtocolSend](../../../../../by-file/ProtocolSend.md) or [UID:0000NP][Session](../../../../../by-file/Session.md)
- Evidence for:
  - The literal is network/session-adjacent and goes through outbound packet helpers.
- Evidence against:
  - Both pages are current non-promoted placeholders with `PROPOSED_RECONSTRUCTION_PATH:"NONE"`.
  - No live IDA evidence shows a cohesive source-level `ProtocolSend.cpp` or generic `Session.cpp` owning this literal.
  - The direct callers are feature-context methods, not a central protocol/session API.
- Decision:
  - Reject as current canonical owner or emitter.

### 6. [UID:0000MA][Palette](../../../../../by-file/Palette.md) / [UID:000262][PaletteReadOnlyData](../../../../../by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md)
- Evidence for:
  - There is a similar `baram.pal` spelling in the binary.
- Evidence against:
  - It is UTF-16LE `baram.pal`, not ANSI `baram`.
  - It lives at `0x006217c4`, not `0x00622f4c`.
  - Its xrefs are Palette constructor refs in `sub_543700`, not packet-send refs.
- Decision:
  - Reject as unrelated.

### 7. Physical containers or a new shared packet-literal owner
- Evidence for:
  - The literal sits in a mixed `.rdata` tail map and is shared by two source contexts.
- Evidence against:
  - The surrounding containers are physical grouping artifacts and are correctly non-reconstructable.
  - A new source file or global just to own one pooled packet string would violate by-structure guidance. The source-use emitters are already known.
  - No adjacent packet-literal family or centralized source declaration cluster was found.
- Decision:
  - Reject new owner/file/grouping. Keep current exact child and parent containers.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: none identified.
- Candidate related items rejected: the send helpers, `ProtocolSend`, `Session`, Socket transport, Palette filename data, and physical `.rdata` containers are all rejected for the reasons above.
- Standalone, narrow, or broad source-file inference: no new source file should be created.

## Negative Evidence Summary
- No additional ANSI `baram\0` spellings in IDA or raw PE.
- No UTF-16LE bare `baram\0` spelling; the only wide related spelling is `baram.pal\0` in Palette data.
- No xrefs to suffix starts `0x00622f4d` or `0x00622f50`.
- No xrefs or VA/RVA immediate refs to the successor boundary `0x00622f54`.
- No raw RVA-form refs for `0x00222f4c`, `0x00222f4d`, `0x00222f50`, or `0x00222f54`.
- Consumer calls to `sub_574BB0` and `sub_574D40` prove packet routing, not literal ownership.
- Nearby wide strings and successor Region vtable data do not prove source ownership; direct xrefs and route context override adjacency.

## Final Recommendation
- Exact changes applied or recommended: no by-memory, by-file, generated, project-level, or coverage-report edits are required.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:NONE`; do not assign a canonical owner.
- Exact emitters applied or recommended: keep `EMITTER_UIDS:0000N0,0000OI`.
- Exact items left no-owner/non-emitting and why: this target is left no-owner but not non-emitting. It is reconstructable through its two source-use emitters because the physical literal is pooled and no single semantic declaration owner is proven.
- Exact future work outside this assignment scope: none required for `0003G7`. A later TerminalPane pass may raise [UID:0001JC](../../../../../by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md), but that is not needed to decide this literal's emitter routing.

## Shared Report / Coverage Text
- No replacement row/block is required for supervisor application.
- Current generated state to preserve:

```text
| [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md` |  |
```

## Follow-Up Actions
- Supervisor actions: mark this current B001 pass complete/accepted if the evidence is sufficient; no coverage-report replacement is requested.
- A-agent actions: none for this target.
- B001 future research actions: none for this target.

## Confidence
- Recommendation confidence: high. Direct IDA and raw PE evidence converge on exactly two independent source-use routes and no better single owner.
- Score confidence: retain `89/94`. The score remains appropriate because boundaries/xrefs are very strong, but original source declaration ownership and final code entry remain below the `90/90+` gate.
- Remaining uncertainty: only the original source spelling placement is unknown, as expected for a pooled literal. This uncertainty is exactly why `CANONICAL_OWNER:NONE` is preferable to forcing ReconnectDialog or TerminalPane as sole owner.

## Validator Results
- Commands run: none.
- Results: no validator run was needed because no by-* documentation files were edited and no split/child registration was performed.
- Any unresolved validator warnings/errors: none from this pass.
- Dry runs: none used.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/0003G7-SharedBaramPacketLiteral-current-goal2-pass.md`.
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G7","source_path":"executed-b-agent-research/B001/0003G7-SharedBaramPacketLiteral-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
