** TARGET-REPORT-UID:0003G7 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G7 **
# 0003G7 SharedBaramPacketLiteral Post-Migration Recheck

## Final Recommendation

Keep [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](../../../../../by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) unchanged:

| Field | Recommendation |
|---|---|
| `COMPLETION` | `89` |
| `CONFIDENCE` | `94` |
| `RECONSTRUCTABLE` | `TRUE` |
| `CANONICAL_OWNER` | `NONE` |
| `EMITTER_UIDS` | `0000N0,0000OI` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Split/merge/reclass | none |
| IDA repair | none |
| C++ code-entry | do not add C++ yet; completion is below the active `90/90+` gate and this literal should be represented at its proven call sites rather than as a standalone declaration |

This is a valid no-owner-with-emitters state under the current owner/emitter model. The ANSI packet literal is source-authored and reconstructable, but the evidence proves two independent source-use contexts and does not prove one original declaration owner, shared constants object, or central packet-literal source file. The exact output routes remain [UID:0000N0][ReconnectDialog](../../../../../by-file/ReconnectDialog.md) and [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md).

No supervisor edits are required. Do not change `by-memory/-coverage-report.md` for this item; the current generated and coverage rows already express the correct state.

## Evidence Summary

| Evidence | Finding | Ownership/emitter impact |
|---|---|---|
| Target metadata | Current page is `89/94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`. | Current metadata already matches the supported recommendation. |
| IDA MCP xrefs | `0x00622f4c` has exactly two data xrefs: `0x00554276` in `sub_554210` and `0x0058b3fc` in `sub_58B130`. | Exactly two proven source-use emitters; no single owner. |
| IDA MCP negative xrefs | `0x00622f4d`, `0x00622f50`, and successor `0x00622f54` have zero xrefs. | No suffix/interior split and no overlap into `RegionVtableData`. |
| Raw PE scan | `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`; bytes at `0x00622f4c` are `62 61 72 61 6d 00 00 00`; only one ANSI `baram\0` / full-target spelling exists. | Range and literal identity are exact. |
| Raw PE pointer scan | Only absolute target dword hits are push operands at `0x00554277` and `0x0058b3fd`, instruction starts `0x00554276` and `0x0058b3fc`; no RVA-form or interior/successor pointer hits. | Confirms the two direct emitter sites and blocks hidden-table/standalone-owner theories. |
| IDA disassembly | Both sites push `aBaram_0`, format into a stack buffer through `sub_443A00`, queue exactly `5` bytes through `sub_574BB0`, then call `sub_574D40`. | Both ReconnectDialog and TerminalPane materially emit the packet text in source context. |
| Palette control | Separate UTF-16LE `baram` hit is `baram.pal` at `0x006217c4`, with Palette constructor refs. | Not a packet-literal owner/emitter lead. |

## IDA MCP Evidence

Session: `b001_0003gy`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.

### Direct literal xrefs

`xrefs_to` for `0x00622f4c`, `0x00622f4d`, `0x00622f50`, `0x00622f54`, `0x006217c4`, `0x00574bb0`, and `0x00574d40` returned:

| Address | IDA result |
|---|---|
| `0x00622f4c` | two data xrefs: `0x00554276` in `sub_554210` size `0x1f6`; `0x0058b3fc` in `sub_58B130` size `0x31c` |
| `0x00622f4d` | zero xrefs |
| `0x00622f50` | zero xrefs |
| `0x00622f54` | zero xrefs |
| `0x006217c4` | three data xrefs at `0x0054384f`, `0x00543887`, `0x005438c3` in `sub_543700`; this is the Palette filename control |
| `0x00574bb0` | broad generic helper fan-in; first page of results already exceeds 100 refs |
| `0x00574d40` | exactly two code xrefs: `0x005542a9` in `sub_554210` and `0x0058b42f` in `sub_58B130` |

`lookup_funcs` also placed:

| Query | Function result |
|---|---|
| `0x00554210`, `0x00554276`, `0x00554287`, `0x0055429e`, `0x005542a9` | `sub_554210`, size `0x1f6` |
| `0x0058b130`, `0x0058b3fc`, `0x0058b40d`, `0x0058b424`, `0x0058b42f`, `0x0058b44b` | `sub_58B130`, size `0x31c` |
| `0x00574bb0` | `sub_574BB0`, size `0x63` |
| `0x00574d40` | `sub_574D40`, size `0x104` |
| `0x00622f4c`, `0x00622f54`, `0x006217c4` | not functions |

### ReconnectDialog source-use site

IDA disassembly at `0x00554276`:

| Address | Instruction |
|---|---|
| `0x00554276` | `push offset aBaram_0; "baram"` |
| `0x00554287` | `call sub_443A00` |
| `0x0055429b` | `push 5` |
| `0x0055429d` | `push eax` |
| `0x0055429e` | `call sub_574BB0` |
| `0x005542a9` | `call sub_574D40` |

IDA decompilation of `sub_554210` shows the same shape in the `a2 == 1` branch:

```c
sub_443A00(Buffer, 0x80u, "baram", ...);
sub_574BB0(Buffer, 5);
sub_574D40(dword_67A7EC);
```

Current documentation maps this function to [UID:00038L][ReconnectDialogMethods](../../../../../by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md), and [ReconnectDialog](../../../../../by-file/ReconnectDialog.md) records `ReconnectDialog::OnButtonClick` as handling cancel/reconnect branches, packet cleanup/reconnect messages, and `SendPositionUpdate`. That file page clears the emitter gate at `87/88` with proposed source path `NexusTK/network/`.

Emitter decision: keep `0000N0`.

### TerminalPane source-use site

IDA disassembly at `0x0058b3fc`:

| Address | Instruction |
|---|---|
| `0x0058b3fc` | `push offset aBaram_0; "baram"` |
| `0x0058b40d` | `call sub_443A00` |
| `0x0058b421` | `push 5` |
| `0x0058b423` | `push eax` |
| `0x0058b424` | `call sub_574BB0` |
| `0x0058b42f` | `call sub_574D40` |

IDA decompilation of `sub_58B130` shows the same terminal-handoff sequence:

```c
sub_443A00(Src, 0x80u, "baram", ...);
sub_574BB0(Src, 5);
sub_574D40(dword_67A7EC);
```

Current documentation maps this function to [UID:0001JC][TerminalPaneStreamParser](../../../../../by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md), and [TerminalPane](../../../../../by-file/TerminalPane.md) records the stream parser, reconnect/leave callback, and pre-login terminal handoff under `login/TerminalPane.cpp`. The file page clears the emitter gate at `87/85` with proposed source path `NexusTK/login/`.

Emitter decision: keep `0000OI`.

## Raw PE Evidence

Command used: local Python PE-header section parse plus byte/dword scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

| Item | Result |
|---|---|
| MD5 | `4247e04e20b65d6414c7238aa8ff5515` |
| Imagebase | `0x400000` |
| Target VA/file offset/section | `0x00622f4c` / `0x22194c` / `.rdata` |
| Target bytes | `62 61 72 61 6d 00 00 00` |
| Target decoded | ANSI `baram` followed by two zero alignment bytes |
| Parent tail bytes | `4c 00 65 00 61 00 76 00 65 00 00 00 52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00 4e 00 6f 00 00 00 00 00 59 00 65 00 73 00 00 00 62 61 72 61 6d 00 00 00 bc eb 64 00 00 4b 55 00 10 4b 4f 00 c0 b6 41 00` |
| ANSI `baram\0` hits | one, at `0x00622f4c` |
| Full `baram\0\0\0` hits | one, at `0x00622f4c` |
| UTF-16LE `baram` hits | one, at `0x006217c4` as part of `baram.pal` |
| Absolute dword `0x00622f4c` hits | `0x00554277` and `0x0058b3fd`, each preceded by opcode `0x68`, so pushes at `0x00554276` and `0x0058b3fc` |
| Dword `0x00622f4d` | no hits |
| Dword `0x00622f50` | no hits |
| Dword `0x00622f54` | no hits |
| RVA `0x00222f4c` | no hits |
| Palette dword `0x006217c4` | push operands at `0x0054384f`, `0x00543887`, `0x005438c3` |

The raw executable evidence independently confirms the live IDA result: there is one ANSI packet literal, two and only two direct absolute-immediate consumers, no interior/suffix consumer, no successor consumer, and no RVA/pointer-table route.

## Documentation Evidence

| Document | Current evidence used |
|---|---|
| Target page | Header already records `89/94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N0,0000OI`. The page documents direct xrefs at `0x00554276` and `0x0058b3fc`, the clean successor boundary at `0x00622f54`, and the Palette-owned `baram.pal` negative control. |
| [ReconnectTerminalCopyStringTailMap](../../../../../by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md) | Parent `0003CW` is a `RECONSTRUCTABLE:FALSE` mixed map; exact child `0003G7` carries the ANSI `baram` literal. |
| [ReconnectDialog](../../../../../by-file/ReconnectDialog.md) | File UID `0000N0`, score `87/88`, proposed `NexusTK/network/`, includes `ReconnectDialog::OnButtonClick` packet-send/position-update behavior. |
| [TerminalPane](../../../../../by-file/TerminalPane.md) | File UID `0000OI`, score `87/85`, proposed `NexusTK/login/`, includes the `TerminalPane` stream parser and reconnect/leave flow. |
| [QueueAndSendPacket](../../../../../by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and [Socket](../../../../../by-file/Socket.md) | Queue/send wrapper is Socket-owned generic transport/request infrastructure with hundreds of cross-feature callers; feature/UI code builds packet bytes. It is not the source-use emitter for this literal. |
| [ProtocolSend](../../../../../by-file/ProtocolSend.md) | Placeholder only; no proven standalone source root; docs explicitly warn not to move feature packet builders there solely because they call the send wrapper. |
| [Session](../../../../../by-file/Session.md) | Placeholder/non-promotion boundary; no generic session source root proven for this literal. |
| [PaletteReadOnlyData](../../../../../by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md) and [Palette](../../../../../by-file/Palette.md) | Separate `baram.pal` wide filename is Palette resource data, not the ANSI network packet literal. |
| [RegionVtableData](../../../../../by-memory/0x00622f54-0x00622f64.RegionVtableData.md) | Successor starts at `0x00622f54`; no xrefs or raw pointer hits cross from the literal into the Region vtable/data child. |
| [by-structure.md](../../../../../by-structure.md) | Lines 237-249 define separate `CANONICAL_OWNER` and `EMITTER_UIDS`; line 243 allows pooled/shared literals to keep `CANONICAL_OWNER:NONE` while using multiple emitters; line 249 sets the current practical C++ code-entry gate at about `90/90+`. |

## Ranked Owner/Emitter Decision

| Candidate | Decision | Reason |
|---|---|---|
| `0000N0` ReconnectDialog | emitter only | Direct source-use at `0x00554276` is proven and the file root clears the gate. It cannot be canonical owner because TerminalPane independently uses the same pooled literal. |
| `0000OI` TerminalPane | emitter only | Direct source-use at `0x0058b3fc` is proven and the file root clears the gate. It cannot be canonical owner because ReconnectDialog independently uses the same pooled literal. |
| `NONE` canonical owner | keep | No original declaration owner, global constant object, table, or dedicated source file is proven. Under by-structure rules this is the correct owner state for a pooled/shared literal with multiple proven source-use emitters. |
| `0000DD` Socket / queue-send helpers | reject owner and emitter | `sub_574BB0` and `sub_574D40` are generic send/position helpers. They are callees of both packet-building sites but do not reference the literal or decide its packet spelling. |
| `0000MV` ProtocolSend | reject | Placeholder file; current docs explicitly require more cohesive protocol API evidence before promotion. Literal-specific evidence remains feature-local. |
| `0000NP` Session | reject | Placeholder/non-promotion boundary; no generic game-session source root or literal declaration evidence. |
| `0000MA` Palette / `000262` PaletteReadOnlyData | reject | Only related spelling is UTF-16LE `baram.pal` at `0x006217c4`, a Palette filename with Palette constructor refs. |
| `0003CW` parent map | reject | Non-emitting mixed map whose exact child pages carry source literals. |
| `0002OP` Region | reject | Successor vtable/data starts after the literal; no xrefs or raw pointer hits support overlap. |
| New shared packet-literal source file/global | reject | No symbol, table, initializer, pointer array, debug/source metadata, or cohesive shared constants island. Creating one would invent an owner solely to avoid `NONE`, which by-structure forbids. |

## Split/Reclassification/Repair Review

No split is justified. The item is exactly eight bytes: ANSI `baram\0` plus two zero tail/alignment bytes. IDA and raw PE both show no refs to `0x00622f4d`, `0x00622f50`, or `0x00622f54`. The successor `0x00622f54-0x00622f64.RegionVtableData` remains cleanly separated.

No merge is justified. The parent `0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap` is already a non-emitting mixed map, and this child has its own exact source-use evidence.

No reclassification is justified. This is not padding, a compiler artifact, a vtable, or ignored data; it is a reconstructable source literal used in packet-building code.

No IDA repair is required. IDA already names the literal `aBaram_0`, represents the two consuming functions, and shows the necessary xrefs. There is no missing function object or stale boundary that blocks routing.

## Score Review

| Score | Before | After recommendation | Rationale |
|---|---:|---:|---|
| Completion | `89` | `89` | Exact bytes, xrefs, boundary, split state, and emitter routing are proven. It remains below `90` because final source expression placement should be resolved in the eventual ReconnectDialog and TerminalPane reconstruction, not on this standalone data page. |
| Confidence | `94` | `94` | IDA MCP, raw PE scans, and current docs agree. Confidence stays below rare final-audit territory because original source-level pooling/declaration shape is not directly recoverable. |

Code-entry note: the active code-entry gate is `90/90+`; this item is `89/94`, so do not add final reconstruction C++. Even if completion later reaches `90`, the likely source representation is duplicated call-site string literal use in the two emitter files, not a standalone shared data declaration.

## Exact Supervisor Actions

No changes are required.

Retain target metadata:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Retain the current generated ownership row:

```markdown
| [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | no-owner | `NONE` | `0000N0`,`0000OI` |  | no | `auto-generated/NexusTK/network/ReconnectDialog.cpp` | `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md` |  |
```

Retain the current emitter table entry:

```markdown
| [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md` | [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md) |  | `auto-generated/NexusTK/network/ReconnectDialog.cpp` |  |
```

Retain the current no-owner-with-emitters row:

```markdown
| [UID:0003G7][0x00622f4c-0x00622f54.SharedBaramPacketLiteral](by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md) | no-owner | `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md` | `0000N0`,`0000OI` | `auto-generated/NexusTK/network/ReconnectDialog.cpp` |  |
```

Do not edit `by-memory/-coverage-report.md`; its current `0003G7` row already states the correct current evidence and routing.

## Validation and Commands

No documentation validator was run because this assignment required a report only and no by-* documentation was edited. No dry-run mode and no memory-range validator mode were used.

Research commands/results recorded:

| Command category | Result |
|---|---|
| `rg` over goal, target, generated coverage, tracker, by-structure, owner/emitter candidates, and adjacent docs | Current docs align with no-owner plus emitters `0000N0,0000OI`; no stale owner/emitter row found for this target. |
| IDA MCP `server_health` | Session `b001_0003gy` healthy; auto-analysis and Hex-Rays ready. |
| IDA MCP `xrefs_to` / `lookup_funcs` / `disasm` / `decompile` | Exact two literal xrefs and two send-helper caller paths confirmed; no interior/suffix/successor xrefs. |
| Raw PE byte/dword scan | Exact bytes, unique ANSI spelling, two absolute push operands, no RVA/interior/successor refs, separate Palette filename control confirmed. |

Changed files for this assignment:

```text
tools/leaser/Agents/Agent-B002/research/0003G7-SharedBaramPacketLiteral-post-migration-recheck.md
```

Blockers: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G7","source_path":"executed-b-agent-research/B002/0003G7-SharedBaramPacketLiteral-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
