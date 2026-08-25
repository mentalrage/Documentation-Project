** TARGET-REPORT-UID:000288 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID000288 StartupWindowNoticePointerData Source-Quality Report

## Finalized Report / Current Recommendation

- Implemented target: [UID:000288][0x00670260-0x00670268.StartupWindowNoticePointerData](by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md).
- Implemented target state: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, `EMITTER_POSITION_OPTIONAL:0`, `Nested:0`.
- Implemented source disposition: two source-declared, file-local, writable pointer objects whose pointees are const ANSI string literals. The pointer objects belong in `NexusTK/app/StartupWindow.cpp`; the linker-generated addresses and pooled literal storage remain generated-binary consequences of those declarations.
- Formal C++ remains the accepted two declarations byte-for-byte. Position `0` now places the data before all unpositioned StartupWindow consumers.
- Completed callback scope: target plus bounded detail-only synchronization in [UID:0000O5] `by-file/StartupWindow.md`, [UID:0000DZ] `by-class/StartupWindow.md`, [UID:0001IO] aggregate, [UID:00026K] read-only data, [UID:0004CS] modeled consumer, and [UID:0004D2] raw consumer. Support scores and formal C++ remain unchanged.
- B004 completed the ordinary implementation, scoped validators, lease releases, and waited generated verification. B004 performed no manual coverage edit, report execution, lifecycle, move, or archive command; those states remain external supervisor/validator-owned.

## Supporting Research

- Exact search terms: `UID000288`, `0x00670260`, `0x00670268`, `StartupWindowNoticePointerData`, `g_szBaramNoticeWndClass`, `g_szNoticeTitle`, `0x005819d0`, `StartupWindowUnmodeledNoticeHelpers`, `StartupWindowRunUpdateCheck`, `StartupWindow`, notice class/title pointer, owner `0000O5`, and source family `NexusTK/app/StartupWindow.cpp`.
- Active report roots searched: `tools/leaser/Agents/Agent-B001/research`, `Agent-B002/research`, `Agent-B003/research`, `Agent-B004/research`, and `Agent-B005/research`. No matching active report existed when searched, so no active callback collision was found.
- `tools/leaser/Agents/Older-Research` and `tools/leaser/Agents/SpecialReports` were searched with the same terms and returned no match.
- The actual project archive root `archived` was searched with the same terms and returned no matching Markdown report.
- Opened `executed-b-agent-research/B008/0000O5-StartupWindow-empty-emitter-family-source-quality.md`, SHA256 `0F71C41B76F6A83DBB3BEA9A1FA838436960BAEF9574196DD58B7E2672448`. It introduced the current two pointer declarations but explicitly left UID000288 at `86/90` because symbol spelling was inferred. It is a broad family report, not a target-specific pointer type/order audit.
- Opened `executed-b-agent-research/B010/0001IO-StartupWindowUpdateCheck-source-quality.md`, SHA256 `02575EA90F4BAC091D75B9C12AAD4D6D1163BCFF3FCAE76FFA941B8DBAD47854`. It established the aggregate split, pointer values, consumers, and raw helper boundary, but did not resolve pointer cv-qualification or generated declaration order.
- Opened `executed-b-agent-research/B006/0004D2-StartupNoticeCreateWindowRaw-source-quality.md`, SHA256 `A9643739204BC26799E6D05D017E5093AF3D802EB40B084E5CD9C73B9D9DF69D`. It independently validates the exact raw helper range and both target references while leaving UID000288 itself already-present support.
- Opened `executed-b-agent-research/B001/00026K-startupwindow-rdata-source-quality.md`, SHA256 `C2DC5CE9D68CE1F2C945A2E8B3C6B7D68DDDB756246850159469E66E4B04A12B`. It proves each literal has one pointer-slot xref and correctly separates `.rdata` from UID000288's writable pointer objects. Its non-formal illustrative array constants are a lead only; array-only source would not explain the required `.data` indirection.
- The central executed search also matched exact StartupWindow sibling reports under B003/B004/B007/B008/B010/B011/B012. Those reports were classified as helper-specific support because they either consume the same StartupWindow union or preserve UID000288 as already-present data; none supplies a competing direct target disposition.
- `executed-b-agent-research/B007/0000NS-Socket-empty-emitter-family-source-quality.md` was classified as adjacent-boundary support for UID000287. `executed-b-agent-research/B004/000286-PacketTransformAlternateSizeAndLut-source-quality.md`, B001 `0001DS`, B002 `0001IE`, and B011 `0000OA` were incidental term/address-family matches and contain no direct UID000288 source declaration evidence.

## Target

- UID: `000288`.
- Canonical path: `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`.
- Exact half-open range: `0x00670260-0x00670268`, eight bytes.
- Current source route: [UID:0000O5][StartupWindow](by-file/StartupWindow.md), generated path `NexusTK/app/StartupWindow.cpp`.
- Physical content: dword at `0x00670260` equals `0x0062d418`; dword at `0x00670264` equals `0x0062d430`.
- Logical content: class-name pointer to ANSI `"BaramNoticeWnd_Class"` and title pointer to ANSI `"Notice"`.
- Target bytes SHA256: `1502ACE13FE106819C8F6EC155F1AE3EB772FCF7BBFFBAAFBC581676078C20B4` over `18 d4 62 00 30 d4 62 00`.
- Pointed class literal SHA256: `D532EF399F3762A8079BDACC1E307D7510D184D64EA3472DD9AF16C4B92C7A96` over 21 bytes including NUL.
- Pointed title literal SHA256: `E71B4BFA296C669DF54CB91B8673A819AEB3EF0278F4D4F07ED16F89E3FCDB34` over seven bytes including NUL.

## Current Target State

- Current target snapshot after callback: SHA256 `C01394BB209D3D093B8616189CF0FF78DF6F6DA765C12E1445635EB3F8265CD3`, 11,617 bytes, 90 lines, read after final command `000000015372` on 2026-07-20.
- Current metadata is `92/94`, owner/emitter `0000O5`, reconstructable true, emitter position `0`, and `Nested:0`. The exact two-line formal block is unchanged from the accepted report.
- Current externally generated `auto-generated/NexusTK/app/StartupWindow.cpp`: validator command/header `000000015372`, refreshed `2026-07-20T15:05:38-04:00`, SHA256 `C5BD35AB002EED0B1AFDB2D52201643B1134E0ED73A1676722C0A41D38594CEC`, 22,815 bytes, 520 lines.
- The current generated file has UID000288 exactly once at line 7, declarations at lines 8-9 before all uses, class-name token count five, title token count three, one `StartupWindow::RunUpdateCheck` definition, one `StartupNoticeCreateWindow` definition, zero Empty Emitter Markers, and no duplicate pointer/array/address-constant source. Command `000000015346` is the historical pre-callback ordering-defect snapshot.
- At the final B004 readback, the externally generated tracker snapshot is command/header `000000015377`, refreshed `2026-07-20T15:18:52-04:00`, SHA256 `B231DDF0F1614AA621BAC4EF5347C07A0E01C29918A9D9D98672AAE1CDD81083`, 1,531,190 bytes, 6,205 lines. Its UID000288 row is `92/94`, reconstructable true, position `0`. Commands `000000015372`, `000000015375`, and `000000015376` are historical implementation-time/later external checkpoints; commands `000000015359` and `000000015362` are earlier historical research/report-writing checkpoints.
- Current manual coverage snapshots remain by-memory SHA256 `FD736C41C2133C3A156F2D2F10F11CBDA63C9A98C947F9832BAF4B563D648995` (1,858,852 bytes/4,408 lines), by-class SHA256 `1C99690F0274C88C578EE49F995563D39757C256B719B297D3CE7CE606EA5219` (240,512/623), and by-file SHA256 `8C0F1C85550A7C8803F9913116B72943F3A2A312C57E21C0600F92B8128A2F52` (137,887/316). The UID000288, UID0000DZ, and UID0000O5 rows are still stale and the exact supervisor-owned replacements below remain unapplied.
- Report validation, execution, counting, path movement, and archive state are external supervisor/validator-owned facts and are not asserted by this artifact.

## Executive Recommendation

UID000288 remains one exact emitting data page and is now `92/94` with its UID/path/range/owner/emitter/reconstructable/Nested state preserved, `EMITTER_POSITION_OPTIONAL:0`, and the exact formal declarations retained. The two writable `.data` slots are observable runtime pointer objects, not aliases for direct arrays. Their targets are immutable `.rdata` string literals. `const char *` is the strongest source model: const pointee, mutable pointer object, static file linkage. `const char *const` remains rejected because top-level const would normally remove the writable data object; array-only declarations remain rejected because consumers load through pointer slots. No child split, global page, class member, imported source, or no-code disposition was introduced.

## Supervisor Active Recheck

- B004 reread every destination under its short lease and preserved the complete then-current StartupWindow union while applying only the accepted UID000288 pointer declaration/type/order evidence and stale wording corrections.
- Independent report review, manual coverage application, execution, counting, path movement, and archive state are external supervisor/validator-owned and are authoritative only in external audit/lifecycle records.
- Generated, tracker, and manual coverage hashes below are current at the final B004 readback; later unrelated validator epochs must be classified externally rather than treated as changes to the durable implementation proof.
- All B004 ordinary leases were released. B004 performed no report lifecycle operation.

## Inference Research Guidance Check

- Exact: addresses, eight bytes, pointer values, strings, segment placement, xref counts/sites, operand direction, raw helper boundaries, modeled consumer, adjacent dwords, and generated ordering.
- Strong inference: `static` internal linkage because every known code use is in the StartupWindow source family and no external pointer route exists.
- Strong inference: `const char *` because the strings are literal storage, APIs consume `LPCSTR`, and no writes target the pointees, while the pointer objects themselves occupy writable `.data`.
- Bounded naming inference: `g_szBaramNoticeWndClass` and `g_szNoticeTitle` are accepted project source-facing names. IDA's `lpClassName` and `lpWindowName` are API-role labels, not recovered original symbols.
- Generated-binary boundary: absolute addresses, relocations, and literal pooling are linker/compiler results. The two initialized pointer declarations are handwritten source and must emit.

## Heuristic / Inference Reanalysis And Validation

| Blocker | Investigation | Resolution |
| --- | --- | --- |
| Pointer or array source | Compared slot loads, string xrefs, segment placement, and B001 array lead. | Pointer objects are required; array-only source is rejected. |
| Pointee constness | Checked literals, APIs, xrefs, and writes. | `const char *` is the highest-probability source type. |
| Top-level pointer constness | Checked `.data` placement and writable object identity. | Do not add top-level `const`; retain mutable pointer object. |
| Linkage | Checked all four references and owner family. | File-local `static` is strongest; no header/global API page is needed. |
| Names | Compared IDA role labels, current project names, literals, and sibling source style. | Retain current `g_sz...` names; confidence cap only. |
| Alternate helper liveness | Rechecked exact bytes, function model, xrefs, refs, and boundaries. | Source-shaped retained private helper; no direct entry route remains a helper confidence cap, not target deadness. |
| Range | Rechecked previous/next dwords and xrefs. | Exact eight-byte target; no split or extension. |
| Generated disposition | Inspected current generated source. | Source declarations are correct but ordered too late; position `0` resolves it. |
| Score | Applied score-blocker audit to every current 86/90 caveat. | All investigable blockers are resolved; only original spelling remains bounded. Recommend 92/94. |

## Evidence Standards Used

- Live IDA MCP evidence was mandatory and used from database `9b0396a3` after fresh `idb_list` and healthy `server_health`.
- Binary facts are separated from source inferences. Every inference is ranked and alternatives are explicitly rejected.
- Prior reports are revalidated leads, not substitutes for direct target bytes/xrefs/type analysis.
- Current ordinary, generated, tracker, and manual coverage files were read only.
- The score recommendation follows the project score-blocker standard: no unresolved investigable blocker is used to justify retaining 86/90.
- Generated-source readiness includes declaration ordering, uniqueness, absence of empty markers, and no duplicate source storage.

## Evidence Checked

- MCP `idb_list`: one active adopted worker session `9b0396a3`, PID 15732, NexusTK IDB.
- MCP `server_health`: status `ok`; image base `0x00400000`; auto-analysis, Hex-Rays, and string cache ready.
- MCP bounded `get_bytes`: target/adjacent bytes at `0x00670250-0x00670270`; exact literals at `0x0062d418` and `0x0062d430`; four predecessor `0xcc` bytes at `0x005819cc`; eleven successor `0xcc` bytes at `0x00581b75`.
- MCP `get_global_value`: slots resolve to `0x0062d418` and `0x0062d430`.
- MCP `get_string`: exact values `BaramNoticeWnd_Class` and `Notice`.
- MCP `entity_query`: target names `lpClassName`/`lpWindowName` in `.data`; pointed strings of lengths 20/6 in `.rdata`.
- MCP `xrefs_to`: two target-slot refs each; one string-target ref each from its slot; adjacent UID000287 refs; zero refs to `0x00670268`.
- MCP `lookup_funcs`: no function at either target slot or raw helper start/end; successor `0x00581b80` is modeled size `0x166`.
- MCP function/decompile/disassembly pass: `StartupWindow__RunUpdateCheck` at `0x00580870`, size `0x88d`, loads class slot at `0x005808ac`, title slot at `0x00580ab1`, and uses them in registration/window creation.
- MCP raw disassembly pass: `0x005819d0-0x00581b75` consumes the class slot at `0x005819e1`, title slot at `0x00581b47`, WndProc at `0x005819fc`, class atom at `0x00581af4/0x00581b08`, and stores the created HWND at `0x00581b61`.
- Exact current target/support docs, generated StartupWindow.cpp, tracker, all three affected manual coverage files, prior reports, and root searches listed under Supporting Research.

## Claim And Incorporation Ledger

| Claim ID | Atomic claim | Confidence | Evidence | Destination | Action | Verification State |
| --- | --- | --- | --- | --- | --- | --- |
| C288-001 | UID000288 is exactly `0x00670260-0x00670268`, eight bytes. | certain | Target range/detail retained; validator `15365`, final `15372`. | target | incorporate | applied |
| C288-002 | Slot `0x00670260` contains pointer `0x0062d418`. | certain | Exact bytes/value recorded in target. | target | incorporate | applied |
| C288-003 | Slot `0x00670264` contains pointer `0x0062d430`. | certain | Exact bytes/value recorded in target. | target | incorporate | applied |
| C288-004 | `0x0062d418` is 20-character ANSI `BaramNoticeWnd_Class` plus NUL. | certain | Exact literal/hash recorded in target and UID00026K; validators `15365`/`15369`. | target/rdata | incorporate | applied |
| C288-005 | `0x0062d430` is six-character ANSI `Notice` plus NUL. | certain | Exact literal/hash recorded in target and UID00026K; validators `15365`/`15369`. | target/rdata | incorporate | applied |
| C288-006 | Pointer objects are in `.data`; literals are in `.rdata`. | certain | Storage distinction recorded in target/UID00026K. | target/rdata | incorporate | applied |
| C288-007 | Each pointer slot has exactly two code reads. | certain | Complete four-reference inventory recorded in target. | target | incorporate | applied |
| C288-008 | Each pointed string has exactly one data xref, from its pointer slot. | certain | One-xref evidence recorded in target/UID00026K. | target/rdata | incorporate | applied |
| C288-009 | No observed instruction writes either pointer slot or either literal. | very strong | Negative write evidence retained in target. | target | incorporate | applied |
| C288-010 | Modeled `RunUpdateCheck` reads class at `0x005808ac` and title at `0x00580ab1`. | certain | Exact refs recorded in target and UID0004CS; validators `15365`/`15370`. | target/UID0004CS | incorporate | applied |
| C288-011 | RunUpdateCheck uses class for WNDCLASS registration/CreateWindow and title for CreateWindow. | certain | Argument-flow detail recorded without changing UID0004CS body. | target/UID0004CS | incorporate | applied |
| C288-012 | Raw helper reads class at `0x005819e1` and title at `0x00581b47`. | certain | Exact refs recorded in target and UID0004D2; validators `15365`/`15371`. | target/UID0004D2 | incorporate | applied |
| C288-013 | Raw helper is exactly `0x005819d0-0x00581b75`, 421 bytes. | very strong | Exact range/length preserved in target and UID0004D2. | target/UID0004D2 | incorporate | applied |
| C288-014 | Raw helper has four predecessor and eleven successor `0xcc` bytes. | certain | Boundary evidence preserved in target/UID0004D2. | target/UID0004D2 | incorporate | applied |
| C288-015 | IDA has no function object at raw start or end. | certain | Historical MCP fact recorded as current evidence-time fact in target/UID0004D2. | target/UID0004D2 | incorporate | applied |
| C288-016 | No direct xref/pointer route reaches raw start. | very strong | No-route evidence preserved in target/UID0004D2. | target/UID0004D2 | incorporate | applied |
| C288-017 | Raw body is source-shaped and retained despite absent direct route. | strong | Retained-helper disposition preserved in target/UID0004D2. | target/UID0004D2 | incorporate | applied |
| C288-018 | UID000287 ends immediately before target and owns the prior pointer pair. | certain | Left-boundary evidence recorded; UID000287 unchanged. | target | incorporate | applied |
| C288-019 | UID000289 begins at `0x00670268`; that boundary has zero xrefs. | certain | Right-boundary evidence recorded; UID000289 unchanged. | target | incorporate | applied |
| C288-020 | No target split or range extension is warranted. | very strong | One-page disposition retained in target. | target | incorporate | applied |
| C288-021 | Source must declare pointer objects; arrays alone cannot explain slot loads. | very strong | Array-only alternative explicitly rejected in target/UID00026K. | target | reject-invalid | applied |
| C288-022 | Pointee type is best represented as `const char`. | strong | Type proof recorded; exact formal retained. | target | incorporate | applied |
| C288-023 | Pointer object is not top-level const because it occupies writable `.data`. | strong | Top-level-const alternative explicitly rejected in target. | target | reject-invalid | applied |
| C288-024 | Internal `static` linkage is strongest because all uses are StartupWindow-local. | strong | Linkage/source-placement proof recorded in target/by-file. | target/file | incorporate | applied |
| C288-025 | Current `g_szBaramNoticeWndClass` name is retained as best source-facing inference. | strong | Accepted spelling/formal preserved byte-for-byte. | target/support | already-present | already-present |
| C288-026 | Current `g_szNoticeTitle` name is retained as best source-facing inference. | strong | Accepted spelling/formal preserved byte-for-byte. | target/support | already-present | already-present |
| C288-027 | IDA names `lpClassName`/`lpWindowName` are role aliases, not original symbols. | very strong | Aliases historicalized in target and UID0001IO. | target/aggregate | historicalize | applied |
| C288-028 | Canonical source owner remains by-file UID0000O5. | very strong | Owner preserved and validated by `15365`. | target | already-present | already-present |
| C288-029 | Emitter remains UID0000O5 and path remains `NexusTK/app/StartupWindow.cpp`. | very strong | Emitter/route preserved; generated readback command `15372`. | target | already-present | already-present |
| C288-030 | Target remains reconstructable and source-emitting. | very strong | Reconstructable true retained; declarations emitted exactly once. | target | already-present | already-present |
| C288-031 | Target `Nested:0` is correct; it is not a split child hierarchy transition. | certain | `Nested:0` preserved in validated target. | target | already-present | already-present |
| C288-032 | Exact formal declarations already match the highest-probability source. | strong | Managed block preserved byte-for-byte; generated declarations exact. | target | already-present | already-present |
| C288-033 | Position must change from blank to `0` so declarations precede unpositioned consumers. | certain | Position `0` applied; command `15372` emits declarations at lines 8-9 before uses. | target | incorporate | applied |
| C288-034 | Literal bytes and absolute addresses are generated consequences, not extra handwritten arrays. | very strong | Separation/rejection recorded in target/UID00026K; generated has no duplicate arrays/constants. | target/rdata | reject-invalid | applied |
| C288-035 | Target is file-static data, not StartupWindow class members. | very strong | Non-member disposition recorded in target/by-class. | target/class | reject-invalid | applied |
| C288-036 | Target is not compiler-only/no-code data. | very strong | Source-declared emitting disposition recorded and generated. | target | reject-invalid | applied |
| C288-037 | Stale target wording `unmodeled alternate setup bytes` must name exact child UID0004D2. | certain | Stale wording replaced in target/UID0001IO. | target | reject-stale | applied |
| C288-038 | Parent UID0001IO uses source-facing names while preserving IDA labels as historical aliases and preserving addresses. | strong | Source-facing table labels and historical aliases applied; validator `15368`. | UID0001IO | incorporate | applied |
| C288-039 | Class UID0000DZ describes two file-static mutable pointers to const ANSI literals. | strong | Exact non-member pointer semantics applied; validator `15367`. | by-class | incorporate | applied |
| C288-040 | File UID0000O5 records pointer ownership and the position-before-consumers requirement. | very strong | Exact owner/order detail applied; validator `15366`. | by-file | incorporate | applied |
| C288-041 | Rdata UID00026K should preserve literal ownership separation and reject array-only substitution. | strong | Exact xrefs/source distinction/rejection applied; validator `15369`. | UID00026K | incorporate | applied |
| C288-042 | UID0004CS formal use is already exact; only add pointer declaration provenance detail. | very strong | Provenance detail applied; formal/score preserved; validator `15370`. | UID0004CS | already-present | applied |
| C288-043 | UID0004D2 formal use is already exact; only refresh current target type/liveness detail. | very strong | Type/liveness detail applied; formal/range/score preserved; validator `15371`. | UID0004D2 | already-present | applied |
| C288-044 | UID0000VI remains non-emitting verify-only and needs no callback edit. | very strong | UID0000VI hash `0E8946F3DEDB54DC99A25A0FD898429DD6AA2E68DAB072D72EC36046BDC30744` unchanged. | UID0000VI | not-applicable | excluded-with-reason |
| C288-045 | Raise target from `86/90` to `92/94`; support scores stay unchanged. | strong | Target `92/94` applied; all six support scores retained. | target/support | incorporate | applied |
| C288-046 | Manual coverage needs exact target/class/file row replacements; tracker stays validator-owned. | certain | Exact rows retained below; manual files untouched; final-read tracker externally refreshed by validator `15377`. | coverage handoff/report | incorporate | applied |

## Positive Evidence Summary

- The target contains exactly two valid image-relative pointers, not padding or an arbitrary table.
- Both pointers resolve to exact NUL-terminated ANSI strings in the StartupWindow read-only island.
- Both consumers use the pair with the same WNDCLASS/CreateWindow roles.
- The four target refs are complete and read-only; the two literal refs are complete and come only from the slots.
- The modeled consumer and raw helper independently corroborate the same order: class first, title second.
- The exact existing formal declarations preserve the required indirection and literal contents.
- The generated defect is mechanically localized to child order and is resolved by established emitter-position semantics.

## IDA MCP Facts

- Database/session: `9b0396a3`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID 15732 when checked.
- Health: `ok`; module `NexusTK.exe`; input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; image base `0x00400000`; analysis/Hex-Rays/strings ready.
- Target bytes: `18 d4 62 00 30 d4 62 00`.
- Target names/segments: `lpClassName` at `0x00670260` in `.data`; `lpWindowName` at `0x00670264` in `.data`.
- Literal entities: 20-byte string at `0x0062d418` and six-byte string at `0x0062d430`, both `.rdata`.
- Slot xrefs: class `0x005808ac`, raw `0x005819e1`; title `0x00580ab1`, raw `0x00581b47`.
- Literal xrefs: `0x0062d418 <- 0x00670260`; `0x0062d430 <- 0x00670264`; no direct code xref bypasses the pointers.
- Raw helper function lookup: none at `0x005819d0` or `0x00581b74`; modeled successor begins `0x00581b80`.

## Function / Child Inventory

| Range/entity | Current UID | Kind | Target relationship | Disposition |
| --- | --- | --- | --- | --- |
| `0x00580870-0x005810fd` | 0004CS | modeled method | reads both slots | source-bearing, formal already exact |
| `0x005819d0-0x00581b75` | 0004D2 | raw file-local helper | reads both slots | source-bearing retained helper, no direct route |
| `0x00581b75-0x00581b80` | ignored support | alignment | helper successor boundary | compiler padding |
| `0x0062d418-0x0062d42d` | within 00026K | class literal | target of first slot | generated literal storage from source initializer |
| `0x0062d430-0x0062d437` | within 00026K | title literal | target of second slot | generated literal storage from source initializer |
| `0x00670258-0x00670260` | 000287 | predecessor pointer pair | exact left boundary | separate Socket source data |
| `0x00670260-0x00670268` | 000288 | target pointer pair | exact source data | one page, no split |
| `0x00670268-0x00670294` | 000289 | successor sentinel data | exact right boundary | separate StringBuffer data |

## Direct Xref / Caller Inventory

| Address | Reference | Function/model | Meaning |
| --- | --- | --- | --- |
| `0x00670260` | `0x005808ac` | `StartupWindow__RunUpdateCheck` | loads class pointer for WNDCLASS/CreateWindow |
| `0x00670260` | `0x005819e1` | raw UID0004D2 | loads class pointer for alternate WNDCLASS/CreateWindow |
| `0x00670264` | `0x00580ab1` | `StartupWindow__RunUpdateCheck` | pushes notice title for CreateWindowExA |
| `0x00670264` | `0x00581b47` | raw UID0004D2 | pushes notice title for CreateWindowExA |
| `0x0062d418` | `0x00670260` | data | only reference to class literal |
| `0x0062d430` | `0x00670264` | data | only reference to title literal |
| `0x005819d0` | none | no IDA function | no direct helper entry route found |

## Documentation Evidence And IDA Status

- Target: SHA256 `C01394BB209D3D093B8616189CF0FF78DF6F6DA765C12E1445635EB3F8265CD3`, 11,617 bytes/90 lines, `92/94`.
- by-file UID0000O5: SHA256 `13DCCA5CF9CBA280CC4A540F0197EADC1F6476FB26DF8747EF3D7662CBEE34B1`, 49,765/233, `89/88` unchanged.
- by-class UID0000DZ: SHA256 `A77A27D5FADE4A51C3F1BDA1AA584E450920F9AEC729C42C005391B9B90E0895`, 35,469/173, `88/89` unchanged.
- parent UID0001IO: SHA256 `3A13E0DA6C82FE0811415FDB6A29EE2BAE53AD5CE455CF84A33F9A16E0655225`, 53,349/259, `88/90`, non-emitting split index unchanged.
- modeled consumer UID0004CS: SHA256 `1B01DF443B0E707499A5D68C1601E53625742F21AA2F700052CBB35F22F71C2B`, 14,433/205, `88/90` unchanged.
- raw consumer UID0004D2: SHA256 `DA8BD71DE74153C201EC84A76E5EC0EF425999594EBBEAAF3D7C7E99A1698EDD`, 8,281/96, `88/90` unchanged.
- read-only support UID00026K: SHA256 `88072B2C4BEB3BC8D21C2B5642D7688D5B175B9B876BFDFBDD6B5F507BA70A8F`, 15,437/131, `88/92` unchanged.
- verify-only raw tracker UID0000VI: SHA256 `0E8946F3DEDB54DC99A25A0FD898429DD6AA2E68DAB072D72EC36046BDC30744`, 23,994/153, `88/90`, non-emitting.
- Live MCP was healthy when the recorded evidence was collected. No IDA mutation was performed.
- Final B004 readback found the seven ordinary destinations and UID0000VI stable at the hashes above. Generated StartupWindow.cpp authority is external validator command `15372`; final-read tracker authority is the later external command `15377`; current manual snapshots and unapplied rows are recorded exactly below.

## Ranked Ownership Analysis

1. [UID:0000O5] by-file StartupWindow, very strong. Every code use is in modeled or raw StartupWindow notice setup, and both exact children emit through this file.
2. [UID:0000DZ] StartupWindow class, rejected as declaration owner. Absolute storage is file-static and neither access uses a `this` offset.
3. [UID:00026K] read-only data, rejected as pointer owner. It owns the literal storage evidence but the writable pointer objects are physically separate in `.data`.
4. UID0004CS or UID0004D2, rejected as sole owner. Both consume the same pair; neither should duplicate declarations.
5. Shared Win32/global support, rejected. The pair is source-specific configuration, not an imported API object or general registry.

## Source Placement

- File: `NexusTK/app/StartupWindow.cpp` through emitter UID0000O5.
- Linkage: file-local `static`.
- Placement: emitter position `0`, before the unpositioned StartupWindow class and method/helper definitions.
- Declaration shape: mutable pointer object to const characters.
- Literal placement: compiler/linker-controlled `.rdata` pooling from initializers; no standalone hand-authored address table.
- Header placement is rejected because no external consumer or source API surface exists.

## Range / Split / Padding / Reclassification Analysis

- Exact target length is two dwords. Both have one coherent owner and paired use, so a two-child split would add documentation fragmentation without source or binary benefit.
- Predecessor values at `0x00670258/0x0067025c` point to Socket parser strings and have their own refs under UID000287.
- Successor starts `ff ff ff ff 00 00 00 00` at `0x00670268` under UID000289; it is not part of either StartupWindow pointer object.
- Raw helper range remains exact `0x005819d0-0x00581b75`; four predecessor and eleven successor `0xcc` bytes exclude padding from the helper.
- No target rename is needed. `StartupWindowNoticePointerData` accurately names both storage and source role.
- Reclassification is source-declared emitting data, not compiler-only/no-code data and not direct read-only literals.

## Negative Evidence Summary

- No code directly references either literal; both go through the target slots.
- No write xref targets either slot after image initialization.
- No external file, header, callback table, virtual slot, constructor field, or import owns the pair.
- No function object, entry xref, pointer pattern, or public route was found for raw helper start `0x005819d0`.
- No fallthrough crosses the helper's predecessor or successor padding.
- No evidence supports `char *` mutation of the literals.
- No evidence supports top-level-const pointer storage in `.rdata`.
- No evidence supports separate named literal arrays in addition to the pointer declarations.
- No evidence supports using IDA's parameter-like labels as exact original global names.

## IDA Rename / Type / Comment Recommendations

- Do not mutate IDA during this assignment.
- If a future supervisor-owned IDA naming pass occurs, prefer `g_szBaramNoticeWndClass` at `0x00670260` and `g_szNoticeTitle` at `0x00670264`; type each as pointer to const char, not array and not top-level-const pointer.
- Preserve comments with exact references: modeled `0x005808ac/0x00580ab1`, raw `0x005819e1/0x00581b47`, and literal targets.
- Do not create an IDA function at `0x005819d0` from this data-target callback; UID0004D2 already carries the source disposition and no-route caveat.

## First-Draft C++ Recommendation

Destination 1, exact complete managed formal block for UID000288:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const char *g_szBaramNoticeWndClass = "BaramNoticeWnd_Class";
static const char *g_szNoticeTitle = "Notice";
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is formal insertion text, not an example. Preserve it byte-for-byte. Do not add array declarations, address constants, comments inside the formal block, a class wrapper, or a covered-by marker.

## Final Recommendation

The bounded callback is complete. UID000288 is source-declared StartupWindow file data, emits through UID0000O5 at position `0`, retains the exact two-line formal, and is scored `92/94`. Stale raw-helper wording now names exact UID0004D2, while support provenance is synchronized without support score or body changes. The declaration spelling remains inferred but is no longer a source-quality blocker. Validator command `15372` proves exactly one declaration of each pointer before all uses while retaining the full StartupWindow union.

## Recommended Target Doc Changes

Destination 1: `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`.

Implementation disposition: applied and scoped-validated by commands `15365` and final waited `15372`; the accepted details below are retained as the exact callback specification and proof baseline.

- Preserve UID/path/range/owner/emitter/reconstructable/Nested and the exact managed formal block.
- Change `86/90 -> 92/94`.
- Change blank `EMITTER_POSITION_OPTIONAL` to `0`.
- Item Summary replacement: `Source-declared StartupWindow file-local ANSI notice class/title pointer objects at 0x00670260-0x00670268; exact .data slots point to .rdata literals, feed modeled RunUpdateCheck and raw UID0004D2, and emit before all consumers.`
- Add target-byte and literal hashes, exact segments, complete xref inventory, pointer-versus-array/type/linkage analysis, generated ordering defect and position fix, raw helper exact range/liveness, adjacent UID000287/UID000289 boundaries, rejected alternatives, prior-report classification, and score rationale from this report.
- Historicalize the old phrase `unmodeled alternate notice setup bytes`; the helper is now exact source child UID0004D2 even though IDA still has no function object/direct route.

## Recommended Support Doc Changes

Implementation disposition: Destinations 2-7 were applied under isolated leases and scoped-validated by commands `15366` through `15371`; the accepted no-loss specifications below remain the comparison baseline.

Destination 2: `by-file/StartupWindow.md`.

- Preserve `89/88`, FILE owner, source route, complete contents, all formal/source child dispositions, and unrelated historical detail.
- Expand the globals/data inventory to state that UID000288 owns two file-local mutable pointer objects to const ANSI literals, emitted at position `0` before both consumers.
- Record exact slot values/refs and source-declared versus generated-literal distinction. Do not duplicate the declarations in the by-file page.

Destination 3: `by-class/StartupWindow.md`.

- Preserve `88/89`, class marker formal, complete method/helper union, and unrelated details.
- Replace broad `ANSI window-class/title strings` wording with exact file-static pointer-object semantics and clarify they are not class members.
- Add current exact modeled/raw refs and declaration-order requirement; class formal remains unchanged.

Destination 4: `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` (UID0001IO).

- Preserve `88/90`, false/non-emitting split-index state, all child inventory, and blank formal.
- Replace source-facing table labels `lpClassName`/`lpWindowName` with `g_szBaramNoticeWndClass`/`g_szNoticeTitle`, retaining IDA labels as historical aliases and retaining all four exact ref addresses.
- Replace `unmodeled alternate setup helper` with exact raw child UID0004D2/no-function/no-direct-route wording.

Destination 5: `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md` (UID00026K).

- Preserve `88/92`, owner/emitter, mixed read-only/compiler disposition, blank aggregate formal, exact boundaries, and all unrelated literals/vtable facts.
- Add that each leading literal has only its corresponding UID000288 slot xref and that direct pointer initializers are the accepted source cause. Retain B001's array names only as historical illustrative alternatives, not destination C++.

Destination 6: `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md` (UID0004CS).

- Preserve `88/90` and the complete formal body exactly.
- Add detail-only provenance that both `g_sz...` values are file-static pointer objects emitted by UID000288 before this method; preserve exact references `0x005808ac/0x00580ab1`.

Destination 7: `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md` (UID0004D2).

- Preserve `88/90`, exact range, source body, formal C++, no-public-route caveat, and all unrelated behavior.
- Add detail-only provenance that both `g_sz...` values are file-static pointer objects emitted by UID000288 before this helper; preserve refs `0x005819e1/0x00581b47` and current no-function/no-direct-route evidence.

Verify-only, unchanged: UID0000VI raw-helper tracker, UID000287 predecessor, UID000289 successor, data-section maps, atom/singleton pages, WndProc, and all other StartupWindow siblings.

## Score And Metadata Recommendation

| Field | Pre-callback | Implemented | Reason |
| --- | --- | --- | --- |
| Completion | 86 | 92 | Exact type/storage/linkage/uses/boundaries/source disposition and generated ordering are resolved. |
| Confidence | 90 | 94 | Independent modeled/raw uses and complete slot/literal xrefs strongly constrain the source; only original spelling remains inferred. |
| Canonical owner | 0000O5 | 0000O5 | StartupWindow file owns every use. |
| Reconstructable | TRUE | TRUE | Required source pointer declarations are exact. |
| Emitter | 0000O5 | 0000O5 | `NexusTK/app/StartupWindow.cpp` is the unique source route. |
| Position | blank | 0 | Declarations must precede unpositioned consumers. |
| Nested | 0 | 0 | Independent data item, no hierarchy delta. |
| Formal | two declarations | unchanged | Existing declaration shape is highest probability and behavior exact. |

Support scores remain unchanged. The supervisor-owned manual class/file rows remain stale and the exact replacements below retain their ordinary page completion values (`88` and `89`) while adding exact target detail.

## Open Questions With Attempted Resolution

- Original global spelling: not recoverable from stripped binary. Searched prior reports, IDA names, literals, and current source family. Retain established project names; this caps confidence but does not block implementation.
- `LPCSTR` versus `const char *`: both are source-compatible, but current project style and direct pointer declarations favor `const char *`; no typedef-specific debug evidence exists.
- `const char *const`: rejected because the pointer objects are in writable `.data`; there are no writes at runtime, but physical storage is the stronger toolchain signal.
- Named arrays plus pointer aliases: possible source but unsupported and needlessly adds symbols. Array-only source is behavior/codegen-incompatible with the observed pointer loads.
- Raw helper caller: exhaustive direct start route remains absent. This affects UID0004D2 naming/liveness confidence only; the helper physically reads both target slots and cannot negate their source need.
- Declaration order: resolved through `EMITTER_POSITION_OPTIONAL:0` under the documented validator rule that positioned items sort before unpositioned items.
- No investigable blocker remains.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual coverage is read-only for B004. At the final B004 readback, by-memory SHA256 `FD736C41C2133C3A156F2D2F10F11CBDA63C9A98C947F9832BAF4B563D648995` (1,858,852 bytes/4,408 lines), by-class SHA256 `1C99690F0274C88C578EE49F995563D39757C256B719B297D3CE7CE606EA5219` (240,512/623), and by-file SHA256 `8C0F1C85550A7C8803F9913116B72943F3A2A312C57E21C0600F92B8128A2F52` (137,887/316) still contain stale UID000288/UID0000DZ/UID0000O5 rows. The following remain literal destination-ready replacement rows; no insertion/deletion is required.

Replace the UID000288 row in `by-memory/-coverage-report.md` in place, after UID000287 and before UID000289:

```text
    - [UID:000288][0x00670260-0x00670268.StartupWindowNoticePointerData](by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md) 0x00670260-0x00670268 | source-declared StartupWindow notice ANSI pointer pair | StartupWindowNoticePointerData : reconstructable : 92% : very-strong : Exact eight-byte .data pair contains 0x0062d418/0x0062d430 pointers to .rdata "BaramNoticeWnd_Class"/"Notice" literals; each slot has exactly two read refs from modeled UID0004CS and raw UID0004D2, each literal is referenced only through its slot, file owner/emitter UID0000O5 and position 0 place the exact static const-char-pointer declarations before consumers, adjacent UID000287/UID000289 boundaries are exact, and array-only/top-level-const/class-member/compiler-only alternatives are rejected.
```

Replace the UID0000DZ row in `by-class/-coverage-report.md` in place, after UID0000DY and before UID0000E0:

```text
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md) : reconstructable : 88% : strong : Live IDA confirms WinMain-only entry points, vtable/singleton/global writes, WndProc callback refs, startup-local curl/string helpers, read-only notice strings, and raw helper boundary debt under the StartupWindow file parent; UID000288 is the exact non-member .data pair of file-static mutable pointers to const ANSI class/title literals, consumed by modeled UID0004CS and raw UID0004D2 and emitted before both consumers without changing the complete class/helper union.
```

Replace the UID0000O5 row in `by-file/-coverage-report.md` in place, after UID0000O4 and before UID0000O6:

```text
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md) : reconstructable : 89% : strong : Startup update-notice window with Win32/browser/curl/minimap behavior, proposed contents, callback evidence, ownership boundaries, exact A003 startup global split, and corrected 85/85 parent-gate evidence documented; the file owns UID000288's exact source-declared mutable pointers to const ANSI notice class/title literals at position 0 before modeled RunUpdateCheck and raw StartupNoticeCreateWindow consumers, while pooled literal addresses remain generated read-only data and no child body or declaration is duplicated.
```

Tracker handling: no hand-authored tracker row. At final B004 readback, external validator command `15377` derives UID000288 `92/94`, reconstructable true, and emitter position `0` from the ordinary target; no B004 tracker edit remains. No by-item or other manual coverage row changes are required.

## Follow-Up Actions

- Implementation of Destinations 1-7, all scoped validators, lease releases, and the final waited generated readback are complete; no implementation item remains.
- Generated acceptance is proven at command `15372`: exactly one UID000288 provenance comment; one declaration each; class-name token count five and title token count three; both declarations before first use; UID0004CS and UID0004D2 definitions preserved once; zero Empty Emitter Markers; zero duplicate arrays/pointers/address constants.
- The exact target/class/file manual coverage replacements remain unapplied and supervisor-owned. No other manual row is required.
- Independent report validation, manual coverage application, execution, count, path, move, and archive state are external supervisor/validator-owned and are neither asserted nor directed by this artifact. B004 performed none of those lifecycle actions.

## Confidence

Overall recommendation confidence is `94`. Exact bytes, values, segments, strings, complete refs, consumer roles, adjacent boundaries, and generated ordering are directly verified. Static linkage and `const char *` are strongly constrained by the complete source family and toolchain storage shape. Exact original symbol spelling is not recoverable and is the remaining bounded cap. The recommendation is implementation-ready without inventing a helper, child, class member, address table, or no-code exception.

## Validator Results

- All commands were run from `source-3/project-documentation`; every scoped file result was exit `0`, `ok:1`, with no target-specific warning or failure.
- `000000015365`, `2026-07-20T15:00:22-04:00`: target validation. Side effects: autogen registry update `1`, completion/confidence `92/94`, UID link update `1`, reference-index additions `2`, projected-stat refresh, generated refresh deferred.
- `000000015366`, `2026-07-20T15:01:08-04:00`: by-file UID0000O5. Side effects: UID link updates `3`, reference-index addition `1`, projected-stat refresh, generated refresh deferred.
- `000000015367`, `2026-07-20T15:01:49-04:00`: by-class UID0000DZ. Side effects: UID link update `1`, reference-index addition `1`, projected-stat refresh, generated refresh deferred.
- `000000015368`, `2026-07-20T15:02:40-04:00`: aggregate UID0001IO. Side effects: UID link update `1`, projected-stat refresh, generated refresh deferred.
- `000000015369`, `2026-07-20T15:03:34-04:00`: read-only support UID00026K. Side effects: UID link update `1`, projected-stat refresh, generated refresh deferred.
- `000000015370`, `2026-07-20T15:04:13-04:00`: modeled consumer UID0004CS. Side effects: UID link update `1`, reference-index addition `1`, projected-stat refresh, generated refresh deferred.
- `000000015371`, `2026-07-20T15:04:55-04:00`: raw consumer UID0004D2. Side effects: projected-stat refresh, generated refresh deferred.
- `000000015372`, `2026-07-20T15:05:38-04:00`: final target validation with `--wait-generated`. Side effects: completed generated refresh; autogen registry rebuilt to 5,166 nodes/4,152 edges; metadata refresh `280`; pre-existing repository warnings remained `children fallback:13`, `children marker missing:86`, and `emitter no code:137`; none is target-specific.
- Generated readback: `StartupWindow.cpp` command/header `15372`, SHA256 `C5BD35AB002EED0B1AFDB2D52201643B1134E0ED73A1676722C0A41D38594CEC`, 22,815 bytes/520 lines. UID000288 occurs once; declarations occur once each before use; class token count five; title token count three; UID0004CS and UID0004D2 definitions occur once each; Empty Emitter Marker count is zero; legacy array names and duplicate address-constant source count are zero.
- Tracker readback: final-read external validator command/header `15377`, refreshed `2026-07-20T15:18:52-04:00`, SHA256 `B231DDF0F1614AA621BAC4EF5347C07A0E01C29918A9D9D98672AAE1CDD81083`, 1,531,190 bytes/6,205 lines; UID000288 is `92/94`, reconstructable true, position `0`. Commands `15372`, `15375`, and `15376`, plus commands `15346`, `15359`, and `15362`, are historical checkpoints.
- B004 ran no manual coverage validator, report validator, lifecycle probe, `execute_report`, move, or archive command.

## Changed Files

- `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`: SHA256 `C01394BB209D3D093B8616189CF0FF78DF6F6DA765C12E1445635EB3F8265CD3`, 11,617 bytes/90 lines; target metadata/detail applied; validators `15365` and `15372`.
- `by-file/StartupWindow.md`: SHA256 `13DCCA5CF9CBA280CC4A540F0197EADC1F6476FB26DF8747EF3D7662CBEE34B1`, 49,765 bytes/233 lines; bounded owner/order detail; validator `15366`.
- `by-class/StartupWindow.md`: SHA256 `A77A27D5FADE4A51C3F1BDA1AA584E450920F9AEC729C42C005391B9B90E0895`, 35,469 bytes/173 lines; non-member pointer semantics; validator `15367`.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`: SHA256 `3A13E0DA6C82FE0811415FDB6A29EE2BAE53AD5CE455CF84A33F9A16E0655225`, 53,349 bytes/259 lines; exact names/raw-child correction; validator `15368`.
- `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md`: SHA256 `88072B2C4BEB3BC8D21C2B5642D7688D5B175B9B876BFDFBDD6B5F507BA70A8F`, 15,437 bytes/131 lines; literal/pointer-source separation; validator `15369`.
- `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md`: SHA256 `1B01DF443B0E707499A5D68C1601E53625742F21AA2F700052CBB35F22F71C2B`, 14,433 bytes/205 lines; provenance detail only; validator `15370`.
- `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md`: SHA256 `DA8BD71DE74153C201EC84A76E5EC0EF425999594EBBEAAF3D7C7E99A1698EDD`, 8,281 bytes/96 lines; provenance/type/liveness detail only; validator `15371`.
- `tools/leaser/Agents/Agent-B004/research/000288-StartupWindowNoticePointerData-source-quality.md`: this same accepted report, reconciled in place to terminal callback truth.
- Verify-only `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md` remains SHA256 `0E8946F3DEDB54DC99A25A0FD898429DD6AA2E68DAB072D72EC36046BDC30744`, 23,994 bytes/153 lines.
- No manual coverage, generated, tracker, audit/supervisor, validator-state, IDA, lifecycle, archive, queue, lock, or legacy-tree file was manually edited by B004. Generated/tracker changes above are validator-owned side effects.

## Implementation Tracking Checklist

- [x] Re-read UID000288 after acquiring its short lease and preserve concurrent detail.
- [x] Set UID000288 completion/confidence to `92/94`.
- [x] Preserve UID000288 owner `0000O5`, emitter `0000O5`, reconstructable true, exact range, path, and `Nested:0`.
- [x] Set UID000288 emitter position to `0`.
- [x] Preserve the Destination 1 managed formal block byte-for-byte.
- [x] Replace UID000288 Item Summary with the exact recommended text.
- [x] Add exact target/literal bytes and SHA256 values.
- [x] Add `.data` pointer-object and `.rdata` literal separation.
- [x] Add complete four-reference target inventory and two-reference literal inventory.
- [x] Add modeled UID0004CS argument-flow detail.
- [x] Add raw UID0004D2 range/reference/liveness detail.
- [x] Add pointer-versus-array and cv-qualification proof.
- [x] Add file-static linkage and source-placement proof.
- [x] Add adjacent UID000287/UID000289 boundary proof.
- [x] Add rejected array-only/top-level-const/class-member/compiler-only alternatives.
- [x] Historicalize target `unmodeled alternate` wording to exact UID0004D2 wording.
- [x] Scoped-validate UID000288 while leased; record command/timestamp/exit/ok/warnings/side effects.
- [x] Release UID000288 lease immediately after validation.
- [x] Re-read and lease by-file/StartupWindow.md only immediately before editing.
- [x] Apply Destination 2 detail without changing score/formal/unrelated union.
- [x] Scoped-validate and immediately release by-file/StartupWindow.md.
- [x] Re-read and lease by-class/StartupWindow.md only immediately before editing.
- [x] Apply Destination 3 detail without changing score/formal/unrelated union.
- [x] Scoped-validate and immediately release by-class/StartupWindow.md.
- [x] Re-read and lease UID0001IO only immediately before editing.
- [x] Apply Destination 4 source-name/raw-child corrections without changing aggregate disposition.
- [x] Scoped-validate and immediately release UID0001IO.
- [x] Re-read and lease UID00026K only immediately before editing.
- [x] Apply Destination 5 literal/pointer-source separation without changing score/formal/unrelated data.
- [x] Scoped-validate and immediately release UID00026K.
- [x] Re-read and lease UID0004CS only immediately before editing.
- [x] Apply Destination 6 provenance detail while preserving the complete formal body.
- [x] Scoped-validate and immediately release UID0004CS.
- [x] Re-read and lease UID0004D2 only immediately before editing.
- [x] Apply Destination 7 provenance detail while preserving range, score, no-route caveat, and complete formal body.
- [x] Scoped-validate and immediately release UID0004D2.
- [x] Verify UID0000VI, UID000287, UID000289, atom/singleton, WndProc, and other siblings remain unchanged.
- [x] Confirm no support score or formal C++ inflation occurred.
- [x] Confirm no target split, rename, new UID, global page, or IDA mutation occurred.
- [x] Run one final authorized target validator with `--wait-generated`.
- [x] Record every validator command ID, timestamp, exit, ok, warnings, and side effect.
- [x] Verify generated UID000288 provenance appears exactly once.
- [x] Verify each pointer declaration appears exactly once before every use.
- [x] Verify class-name token count is five and title token count is three.
- [x] Verify UID0004CS and UID0004D2 definitions remain exactly once.
- [x] Verify zero target Empty Emitter Markers and no duplicate arrays/address constants.
- [x] Re-read current manual coverage and preserve the exact no-loss replacement rows/anchors.
- [x] Leave manual coverage and tracker edits to the supervisor/validator.
- [x] Update C288-001 through C288-046 to legal terminal callback states with destination proof.
- [x] Populate Validator Results and Changed Files with exact callback evidence.
- [x] Check each implementation row only after independent truth is established.
- [x] Confirm all ordinary leases are released.
- [x] Confirm no forbidden file or lifecycle command was touched.
- [x] Preserve archive-neutral lifecycle wording in the completed report.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000015396","destination_path":"executed-b-agent-research/B004/000288-StartupWindowNoticePointerData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/000288-StartupWindowNoticePointerData-source-quality.md","timestamp":"2026-07-20T15:34:37-04:00","uid":"000288"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
