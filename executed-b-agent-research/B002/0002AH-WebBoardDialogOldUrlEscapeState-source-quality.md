** TARGET-REPORT-UID:0002AH **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002AH WebBoardDialogOldUrlEscapeState Ownership / Split Research


## Finalized Report / Current Recommendation

- Callback-complete target state: UID0002AH is the sole source emitter for the old WebBoard URL escape guard and 256-byte table at `92/94`, owner/emitter UID0000P9, `EMITTER_POSITION_OPTIONAL:1`, reconstructable true, and `Nested:0`.
- Final disposition: `[0x0067acb0,0x0067adb8)` is one coherent source-level file-static state group containing two declarations separated in the binary by seven compiler/linker alignment bytes. It is not one C++ aggregate, class storage, or generic Browser state.
- Applied source route: UID0002AH emits `s_oldWebBoardUrlEscapeInitialized` and `s_oldWebBoardUrlEscapeTable` once at position `1`; UID000214 is `90/92` at position `2`, emits both old character-set literals plus the complete unchanged `EscapeOldWebBoardUrl` body, and no longer duplicates the state declarations. State and helper now precede old parser use without a header prototype or cross-translation-unit declaration.
- Applied support: UID000278 is `90/94` with the exact nonduplicating covered-literal marker; UID0000P9 remains `91/92` with complete position `0/1/2`, one-definition, and internal-linkage prose. UID0000ZD, UID0000G3, UID0002AG, UID0000Z9, UID0003V1, and UID0000G2 were reread and remain unchanged.
- Collision rebase: supervisor-executed B005 UID0002AG artifact `executed-b-agent-research/B005/0002AG-WebBoardDialogUrlEscapeState-source-quality.md`, post-lifecycle SHA256 `069B260B11C7014FC11AA70A647E86190018FF22908334D7AEED51B057D5FA6D`, was reread before edits. Its active position-0 state, literals, initializer, helper, handler, class, and file union is preserved byte-for-byte on every B005-owned ordinary page; B002 added only the accepted old position-1/position-2 delta.
- Callback validation is complete: scoped commands `15611`-`15614` passed, lease-free waited command `15615` passed, generated order and one-definition assertions passed, and B002 has zero leases. Manual coverage and report lifecycle remain supervisor-owned external state.
- Confidence remains very strong for address boundaries, BSS-zero disposition, types, xrefs, active/old separation, one-definition routing, generated ordering, and behavior; strong rather than original-symbol proof for the inferred source spellings.

## Supporting Research

- The report is a new direct report for UID0002AH. No earlier direct `TARGET-REPORT-UID:0002AH` artifact was found in the canonical central executed, legacy archived, general archived, or active roots.
- Central executed reports were opened as leads and independently checked against live MCP and current docs:
  - `executed-b-agent-research/B004/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md`, SHA256 `94486C5A772C26FF1D58AC8D11E5D6AF9ABD761B5D328F84E81D2F2C20B68A0D`, 29,605 bytes / 662 lines: accepted the complete old raw-helper body and corrected BSS-zero state, but its helper-local state placement did not survive pre-callback generated-order inspection.
  - `executed-b-agent-research/B006/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md`, SHA256 `070D61282EAA5565B3948FB144903E04A63A67C6B6488291F66924851C13BF27`, 28,228 bytes / 443 lines: independently retained the old helper/body and descriptive-name cap; it did not prove the current target marker's claimed source order.
  - `executed-b-agent-research/B003/0003V1-WebBoardDialogUrlEscapeHelper-source-quality.md`, SHA256 `5FE6166F1D03E64A9C3FC75095A42B4B33D428583CFCA0870BA22DA18D546FD6`, 62,121 bytes / 465 lines: established the active raw helper's no-function/no-entry-xref/94-instruction twin behavior and covered-by route.
  - `executed-b-agent-research/B010/0000P9-WebBoardDialog-empty-emitter-family-source-quality.md`, SHA256 `E6CD4DE8D7DA8FE9535E31EF7F9755F1654EBBF89941BAA8317D09B43E1BFBC5`, 81,233 bytes / 1,211 lines: established the complete active/old file union, but its old helper-before-parser statement was contradicted by pre-callback generated line order and is superseded by command `15615`.
  - `executed-b-agent-research/B008/0000G3-WebBoardDialogOld-class-source-quality.md`, SHA256 `38EE577B909AA0755837D70709C71E5F8785FDDFEB45D9F4DA0AAFC8D40B4C1C`, 34,372 bytes / 402 lines: supports class context while correctly leaving the raw helper file-local.
  - `executed-b-agent-research/B001/000210-webboard-render-escape-source-split.md`, SHA256 `D80CD9E2EFB4A07295EDC168E83A70BAF2D82D1DCFE913620E6A6D97AC06D283`, 37,877 bytes / 556 lines: supports exact active-helper splitting and raw-helper range treatment.
- The B005 report's accepted pre-callback SHA `2D0743DF79B8A4A29467A20CBC91C22F133F9C48976BBAEB2C3325F237830C42`, intermediate callback SHA `3AAC37D766F35C8240E41E299C3CD1FCD02A97B40503F3C03CB772DCBE692ED7`, and terminal active-path SHA `A366A6A16DD2B2FDBC02BC24393E8FDBEDC6CCC56AC24908E9AAF5614F58D775` are historical coordination evidence. Current corroborating artifact: `executed-b-agent-research/B005/0002AG-WebBoardDialogUrlEscapeState-source-quality.md`, post-lifecycle SHA256 `069B260B11C7014FC11AA70A647E86190018FF22908334D7AEED51B057D5FA6D`, 75,571 bytes / 691 lines, executed by validator command `000000015610`. It records UID0002AG at `92/94` and position `0`, preserves UID0000Z9/UID0003V1 active routes, and identifies command `15599` as its final target-specific generated proof. B002 independently reread the ordinary union and did not treat report provenance as a substitute for current docs.
- Search roots and exact outcomes:
  - Central executed root `executed-b-agent-research/`: six relevant reports above; no direct UID0002AH report.
  - Legacy executed archive root `archived/b-agent-reports-20260623/`: no match for the exact UID, range, or target name.
  - General archived roots `archived/invalidated/` and `archived/duplicate-loose-b-agent-reports/`: no direct relevant report.
  - Evidence-time active root `tools/leaser/Agents/*/research/`: B005 UID0002AG was the only directly overlapping active report; no duplicate UID0002AH report. It is now centralized in the executed root as recorded above.
- Search terms used across all roots: `UID0002AH`, `0x0067acb0`, `0x0067adb8`, `WebBoardDialogOldUrlEscapeState`, `UID000214`, `0x0046ee80`, `0x0046efda`, `EscapeOldWebBoardUrl`, `UID0000ZD`, `0x0046eaa0`, `UID000278`, `0x0066d430`, `UID0002AG`, `0x0067aba8`, `UID0003V1`, `0x0046da70`, `WebBoardDialog`, `old URL escape`, `guard`, `table`, `source order`, and `one definition`.

## Target

- Target UID: `0002AH`.
- Target path: `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` / `### Not-Covered Files - Reconstructable`; evidence-time row 1,570 was `86/90`, reconstructable true, `Nested:0`.
- Current supervisor classification: accepted implementation callback completed; this same report is reconciled for independent supervisor Gate 2 review.
- Current scores and parent state: `92/94`, `CANONICAL_OWNER:0000P9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P9`, emitter position `1`, exact declaration formal, `Nested:0`.
- Exact range: half-open `[0x0067acb0,0x0067adb8)`, `0x108` / 264 bytes. Project `tools/int_convert.py` independently returned `0x108 == 264`.

## Current Target State

- Evidence-time/pre-callback target SHA256 was `35D62924D6C6F7B523A6B977A0E93FB94664367F988288F1D5475577D20CA176`, 8,257 bytes / 80 lines, at `86/90`, blank position, and marker-only formal. Its helper-before-parser wording was false in generated command `15599` and is retained only as superseded history.
- Current target SHA256 is `0DCADACF421DBDF838A6DECC6670C9DA0371A122942EC4B84061C5006285E585`, 10,057 bytes / 87 lines. It is `92/94`, owner/emitter UID0000P9, reconstructable true, position `1`, `Nested:0`, and the sole exact old guard/table declaration emitter.
- Current UID000214 SHA256 is `D146E682B77F7D7B13867A3F4ED1EA1800A5961C99EF53724FE395C37D1D3714`, 20,265 bytes / 200 lines. It is `90/92`, position `2`, and its formal begins with the old literal arrays; only the duplicate state pair was removed, while the complete helper body and behavior remain unchanged.
- Current UID000278 SHA256 is `21D8046970B36CC492FFCBD927D9BE3E8BFAFAF879DB28DB71C5BC2CE6E3BC7A`, 17,473 bytes / 132 lines, at `90/94` with the exact nonduplicating active/old literal marker. Current UID0000P9 SHA256 is `9830F9EAA2E6FD08351C67E5BCBDDE9838A16C38BFF2FC567DFE3AE0DBF7291D`, 48,353 bytes / 200 lines, still `91/92` with the no-loss file union and position `0/1/2` prose.
- The executed B005 active union remains byte-identical on its owned pages: UID0002AG `265A70D4B2B764416B5C691F23B372CB9DE725FC7DEECA5A30F7EB14BE658506`; UID0000Z9 `C9D9566ABFF39F7CF3F12E99D848F59EE9295A12BA32B6E6E896EB1AAA75C93A`; UID0003V1 `D4038A5B88276C9ECB075C220529C64ED2C5C1DB24612F3C4B40628A664780F0`; by-class UID0000G2 `339BEFD0F6A28F73D1C4D2C4909C43DAD19BD96C90CC44D0CC2F48826CB3DE3B`. Verify-only UID0000ZD remains `58CDD3BECFC5AEE6AC0A09C841006DDC8BB9DD3D7B3EB08A5D42F06956A51447`; UID0000G3 remains `773F2643FEBFB8DFA1ED4A50761C5B4E62D16484F4F683CEEA7F8D4F26099B04`.
- Final waited generated readback: command/header `000000015615`, refreshed `2026-07-21T08:58:37-04:00`, SHA256 `6B9F3ED0FF77FD287F0B2C42AF7AEEB2911347C93A73477ACDC9875B2F16F62E`, 26,562 bytes / 759 lines. Exact declarations are active guard/table lines `8/9`, old guard/table lines `12/13`, old helper definition line `19`, and old parser definition line `683`. Each declaration/definition occurs once; UID0002AH/UID000214/UID000278 Empty Emitter Markers are zero; the UID0003V1 no-duplicate marker remains present; and no active B005 source regressed.
- Current generated tracker at the same command is SHA256 `74220541F117DC0F4D1169A97175573102D9BA32E67D13361AB556639DEBB605`, 1,536,943 bytes / 6,223 lines. UID0002AH is row 3,273 at `92/94`, reconstructable true, `Nested:0`.
- Current read-only manual snapshots are by-memory `6451FC58E3A7222B0C249DC44AD77C7E07B95A901EED5CAA2CF257169761003D` (1,875,002 bytes / 4,427 lines), by-class `970D999177D83E7D50EFAE7E1DC6283FAD6EC95D2F7C06B678BCA17ED6976330` (243,181 / 623), and by-file `D6EB85E56B3AFF244FBD8972ABEBB61CFA8FA87C606B676D77D165C3809A56A5` (140,719 / 316). The four B002 rows remain stale and the exact supervisor-owned replacements below remain required; B002 did not edit coverage.
- Callback work, validators, generated verification, and leases are complete. Exact current/future report path, coverage application, execution, movement, and archive state remain external supervisor/validator-owned facts rather than B002 assertions.

## Executive Recommendation

- Direct owner/source file: UID0000P9 `NexusTK/ui/dialogs/WebBoardDialog.cpp`.
- Target source representation: two file-static definitions, not a class field and not a synthetic struct.
- Exact source order: active state UID0002AG position `0`; old state UID0002AH position `1`; old literals and `EscapeOldWebBoardUrl` definition UID000214 position `2`; class/method children follow in normal blank-position order.
- This arrangement is preferred over a forward declaration because it matches a conventional mid-2000s `.cpp` layout: file-static data and file-local helper definitions precede member-function definitions. It is preferred over helper-local state duplication because the exact storage page can now emit source safely.
- The old parser UID0000ZD remains unchanged. Its existing call becomes compile-visible because UID000214 moves before it.
- The active state/helper family remains separate and unchanged after B005. The byte-identical algorithm does not justify sharing mutable state, literals, or helper identity across the active and old variants.

## Supervisor Active Recheck

- The accepted callback resolved and applied the marker/definition/source-order question, old/active state evidence, names/types/linkage, scores, exact formals, and manual handoff without a range split or new UID.
- The seven-byte gap remains alignment inside the two-declaration state group and has no source-bearing child.
- Every source-bearing blocker is closed in current ordinary/generated state: UID0002AH emits old storage at position `1`; UID000214 emits old literals/helper at position `2`; UID000278 is the covered-literal evidence page; UID0000ZD retains the calling body; UID0000P9 records exact source order and internal linkage.
- B005's executed artifact and all active ordinary destinations were reread before callback and after final generation. Their hashes remain unchanged except UID0000P9, where B002 added only the accepted old-order prose after a no-loss reread. No material contradiction or collision remains.

## Inference Research Guidance Check

- `by-structure.md` requires source-bearing singular pages to use their own formal emitter metadata and states that positioned children sort before blank-position children. That rule directly resolves the current compile-order defect.
- IDA labels `byte_67ACB0` and `byte_67ACB8` were treated as generated traceability aliases, not source names.
- Existing pre-callback claims that the image contains initialized `0xff` bytes and that UID000214 already appeared before the parser were treated as uncertain and rechecked; both were false. The callback corrected source order without changing the binary facts.
- Direct facts, documentation evidence, and inference are separated:
  - Direct: zero bytes, PE virtual-tail mapping, exact xrefs, instruction bodies, no raw-helper entry xrefs, line order.
  - Documentation: current owner/file/class/support routes and prior accepted first-draft bodies.
  - Inference: source spellings and conventional file-static declaration order.
- Wave2/Wave3 documents were not used. Any such historical references encountered through broad repository search were ignored as stale under the current workflow.

## Heuristic / Inference Reanalysis And Validation

- **Generated names:** `byte_67ACB0` and `byte_67ACB8` are rejected as source-facing names. The mirrored active names, paired users, and role support `s_oldWebBoardUrlEscapeInitialized` and `s_oldWebBoardUrlEscapeTable`.
- **Guard type:** all four guard operations are byte comparisons/stores of `0`/`1`; `bool` is the strongest period-plausible source type. `unsigned char` is behavior-compatible but less descriptive and rejected.
- **Table type:** every entry is a byte, indexed by an unsigned source byte over all 256 values, and stores only `0` or `1`; `unsigned char[256]` is exact.
- **Gap:** `0x0067acb1-0x0067acb8` has seven zero bytes and zero xrefs. A source `reserved[7]`, struct padding member, or third declaration is rejected.
- **Aggregate question:** guard and table are distinct declarations but one coherent source-level state group. A synthetic struct is rejected because users address separate absolute symbols and the gap is alignment.
- **Raw-helper liveness:** `0x0046ee80` is not an IDA function and has zero entry xrefs, but its 94-instruction source-shaped body has a normal prologue/return and the modeled old parser contains an inline-equivalent clone. It is retained source, not dead padding.
- **Source ordering:** current scan order places blank-position UID000214 after UID0000ZD, making the generated call precede the definition. Positioning UID0002AH at 1 and UID000214 at 2 makes storage and helper visible before all blank-position class/method children.
- **Header question:** no header declaration is needed. Both objects and helper are `static` and remain confined to one `.cpp`; exporting any declaration would weaken internal linkage and risk a second definition.
- **Old/active sharing:** active and old ranges are distinct, separately guarded, separately initialized, and use duplicated but distinct character arrays. A shared state table/helper is rejected despite algorithm identity.
- **Threading/lifetime:** both initializers use an unsynchronized lazy byte guard and have no cleanup/reset. Adding locks, `std::call_once`, explicit initialization, destructor cleanup, or reset logic would not preserve observed source-era behavior.
- **Format spelling:** the live literal is `%%%2X`. Rewriting it to `%02X` is rejected even if cosmetically attractive.
- **Length/signature:** source and destination lengths are signed 16-bit values in the raw helper. Replacing them with `size_t` or adding null/capacity validation would alter behavior.
- **No-call question:** absence of raw-helper entry xrefs does not justify blank C++. The paired modeled parser clone explains runtime behavior and the retained standalone clone is source-shaped; current accepted helper body is the highest-probability source reconstruction.
- **Scores:** the target blocker was not lack of bytes/xrefs but false emission/order. Resolving that supports `92/94`; helper order/route closure supports `90/92`; exact literal placement closure supports UID000278 `90/94`.

## Evidence Standards Used

- Live read-only IDA MCP: `idb_list`, `server_health`, bounded `get_bytes`, `lookup_funcs`, `xref_query`, `insn_query`, `analyze_function`, and decompile evidence.
- Local read-only binary evidence: PE section mapping from `NexusTK.exe`.
- Current canonical docs: target, old/active handlers/helpers/state, character sets, classes, file root, coverage rows, tracker, and generated source.
- Historical reports: treated only as leads and checked against current facts.
- Negative evidence: no raw-helper entry/tail xrefs, no gap-byte xrefs, no separate table owner, no cleanup/reset, no cross-file route, no direct helper call, and no evidence for a source struct.
- Evidence strength is sufficient because independent binary storage, two consumers, exact duplicated active/old behavior, and validator ordering rules converge on one compile-valid arrangement. Confidence is capped below original-symbol certainty only for spelling.

## Evidence Checked

- MCP session: transport session `afe9c8c6-ca28-4b57-981c-6fd5717f83d3`, database `9b0396a3`; `idb_list` returned the active NexusTK session and `server_health` returned `ok` with auto-analysis, Hex-Rays, and strings ready. These are evidence-collection-time observations, not claims of future availability.
- `get_bytes`:
  - `0x0067acb0`, 264 bytes: all zero, SHA256 `44B8AA4D28701168922ACF61435EA4BB442F97B0B14AD7A2510ED68874EE2A72`.
  - `0x0046ee80`, 346 bytes: SHA256 `856648EAD62CEF3FDC89E2DDA509FD7D2953D4FA43AB892E6D19A3B1E9B17ECE`.
  - `0x0046eaa0`, 986 bytes: SHA256 `F8EC50C2AF0FCD9AEB830B991CDD6623A003B28BF7B76443F497E90B19DFE8F4`.
  - `0x0066d430`, 56 bytes: SHA256 `0808FD26696FCC16908F02635BA922CECA9F6BF669607D617AFD0B61219A9608`.
  - Active twin `0x0046da70`, 346 bytes: SHA256 `39202EB05BE8C03580D212C1CFDE8ACBBA24E0A89E4C13C0156D7820E0FBAE6D`.
  - Active state `0x0067aba8`, 264 zero bytes: same zero-block hash as the old state.
- PE mapping: `.data` begins at RVA `0x26d000`, virtual size `0x2fe24`, raw size `0xd800`, raw pointer `0x26ac00`; raw-backed data ends at RVA `0x27a800` / VA `0x0067a800`. UID0002AH begins `0x4b0` / 1,200 bytes beyond that raw end and is loader-zero virtual tail. `tools/int_convert.py` verified `0x4b0 == 1200`.
- Xref checks:
  - old guard: exactly four refs at `0x46ec27`, `0x46ecf4`, `0x46ee84`, `0x46ef54`;
  - old table: exactly 24 refs split 12/12 between modeled parser and raw helper;
  - old charsets: `0x66d44c` refs at `0x46ec5c`/`0x46eebd`, `0x66d458` refs at `0x46ece0`/`0x46ef40`;
  - active mirror: four guard refs and 24 table refs in the corresponding active parser/raw helper;
  - zero refs to each byte `0x67acb1-0x67acb7`;
  - zero refs to raw-helper entry `0x46ee80` and tail `0x46efda`.
- `lookup_funcs`: old parser `sub_46EAA0`, size `0x3da`; active parser `sub_46D580`, size `0x4e3`; neither old nor active raw-helper entry/tail is modeled as a function.
- `insn_query`: 94 old raw-helper instructions across `[0x46ee80,0x46efda)`, including lazy table construction, 9 reserved writes, 15 unsafe writes, guard store, signed-short bounded scan, `%%%2X` formatting, direct copy, terminator, return, and range-failure tail.
- `analyze_function`/decompile: old parser has 28 basic blocks, reads old state/charsets directly in an inline-equivalent initializer/escape sequence, and remains reached from the old response route; it has no direct call to the retained raw helper.
- Source docs opened: UID0002AH, UID000214, UID0000ZD, UID0000G3, UID0000P9, UID000278, UID0002AG, UID0003V1, UID0000Z9, UID0000G2, predecessor UID0002AG, successor UID0002AI, and `by-memory/-ignored.md`.
- Generated source was searched for every state/helper/literal UID and spelling. The exact old call-before-definition defect was reproduced.
- Failed or skipped checks: no IDA mutation, original symbol/PDB lookup, validator, compilation, or lifecycle command was attempted because the assignment is read-only report research. Lack of original symbols limits lexical certainty but not behavior, type, placement, or formal readiness.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0002AH is exactly 264 zero bytes. | very strong | MCP bytes/hash | Destination 1 target evidence; target SHA `0DCAD...E585` | incorporate | applied |
| C02 | The target is PE virtual-tail/BSS-zero storage, not explicit `0xff` initialized data. | very strong | PE mapping/raw end | Destination 1 evidence/history; stale `0xff` wording explicitly superseded | reject-stale | applied |
| C03 | `0x67acb0` is a one-byte lazy-init guard with four refs. | very strong | exact xref inventory | Destination 1 storage/xrefs; target validated by `15611` | incorporate | applied |
| C04 | `0x67acb8` is a 256-byte decision table with 24 refs. | very strong | exact xref inventory | Destination 1 storage/xrefs; target validated by `15611` | incorporate | applied |
| C05 | The seven intervening bytes are unreferenced compiler/linker alignment. | very strong | per-byte zero-xref checks | Destination 1 layout; no source padding member added | incorporate | applied |
| C06 | Old and active state groups are distinct mirrored storage. | very strong | addresses/xrefs/bytes | target/file prose; generated command `15615` emits separate pairs | incorporate | applied |
| C07 | Old character sets are exact duplicated initialized literals. | very strong | bytes/hash/xrefs | Destination 3 UID000278 SHA `21D804...BC7A` | incorporate | applied |
| C08 | Raw UID000214 has no function object or entry/tail xref. | very strong | lookup/xref negative checks | Destination 2 evidence preserved; helper SHA `D146E6...3714` | incorporate | applied |
| C09 | UID000214 is retained source-shaped code despite no entry xrefs. | strong | 94 instructions + inline clone | Destination 2 disposition retained and validator `15612` passed | incorporate | applied |
| C10 | The raw helper performs exact lazy initialization and bounded escaping. | very strong | disassembly | Destination 2 body remained byte-equal after removal of only state declarations | already-present | already-present |
| C11 | The source guard type is `bool`. | strong | byte compare/store semantics | Destination 1 exact formal line 12 in generated output | incorporate | applied |
| C12 | The source table type is `unsigned char[256]`. | very strong | indexing/value semantics | Destination 1 exact formal line 13 in generated output | incorporate | applied |
| C13 | `s_oldWebBoardUrlEscapeInitialized` is the best source-facing guard name. | strong | active twin/role/style | target formal/name history and generated line 12 | incorporate | applied |
| C14 | `s_oldWebBoardUrlEscapeTable` is the best source-facing table name. | strong | active twin/role/style | target formal/name history and generated line 13 | incorporate | applied |
| C15 | UID0002AH must become the sole old-state definition emitter. | very strong | exact range + one-definition analysis | Destination 1 and generated exact count one | incorporate | applied |
| C16 | UID0002AH must use position `1`. | very strong | validator ordering rule | Destination 1 metadata; validator registry update `15611` | incorporate | applied |
| C17 | UID000214 must use position `2`. | very strong | pre-callback call-before-definition proof | Destination 2 metadata; validator registry update `15612` | incorporate | applied |
| C18 | UID000214 must remove only the two old-state declarations. | very strong | one-definition plan | Destination 2 exact formal; literals/body preserved | incorporate | applied |
| C19 | UID000214 retains both old literals and full helper body. | very strong | current accepted body/charset range | Destination 2 and generated helper definition line 19 | already-present | already-present |
| C20 | No header or cross-TU prototype is required. | very strong | same `.cpp` positioned order | UID0000P9 internal-linkage prose and generated order | reject-invalid | applied |
| C21 | UID000278 remains a non-duplicating covered-literal page. | very strong | exact sole literal sites | Destination 3 marker; no target Empty Emitter Marker | incorporate | applied |
| C22 | UID0000ZD body remains unchanged. | very strong | existing call/source body | verify-only SHA `58CDD3...A51447` | already-present | already-present |
| C23 | UID0000G3 remains class context, not helper owner. | very strong | no `this`; file-static code | verify-only SHA `773F26...99B04` | already-present | already-present |
| C24 | UID0000P9 remains semantic/file owner. | very strong | complete file union | file metadata unchanged; bounded prose SHA `9830F9...7291D` | already-present | already-present |
| C25 | Active UID0002AG position-0 route remains intact. | very strong | executed B005 docs/generated | active verify-only SHA `265A70...506` | already-present | already-present |
| C26 | UID0000Z9 retains active literals/initializer/helper/handler. | very strong | executed B005 ordinary union | active verify-only SHA `C9D956...5C93A` | already-present | already-present |
| C27 | UID0003V1 remains a no-duplicate raw-helper marker. | very strong | B003/B005/current doc | active verify-only SHA `D4038A...80F0`; marker present after `15615` | already-present | already-present |
| C28 | Synthetic struct/source padding members are invalid. | very strong | separate symbols/no gap xrefs | target history/rejections; exact two declarations emitted | reject-invalid | applied |
| C29 | Shared active/old mutable state is invalid. | very strong | separate addresses/consumers | file/source rationale; two independent generated pairs | reject-invalid | applied |
| C30 | Thread synchronization/reset/cleanup must not be invented. | strong | absent binary behavior | target/helper negative evidence retained | reject-invalid | applied |
| C31 | `%%%2X` must be preserved exactly. | very strong | live literal/call | Destination 2 formal/body unchanged | already-present | already-present |
| C32 | Signed-short lengths and current tail behavior must be preserved. | very strong | raw instructions | Destination 2 formal/body unchanged | already-present | already-present |
| C33 | Target score should rise to `92/94`. | strong | blocker closure | target metadata and tracker command `15615` | incorporate | applied |
| C34 | UID000214 score should rise to `90/92`. | strong | liveness/body/order closure | helper metadata validated by `15612` | incorporate | applied |
| C35 | UID000278 score should rise to `90/94`. | strong | bytes/names/placement closure | charset metadata validated by `15613` | incorporate | applied |
| C36 | UID0000P9 score remains `91/92`. | strong | unrelated residual name gaps | file metadata unchanged after `15614` | already-present | already-present |
| C37 | Current target marker's helper-before-parser wording is stale. | very strong | historical generated lines 649/695 | target/file history labels it superseded | reject-stale | applied |
| C38 | Pre-callback generated old state/helper ordering was compile-invalid. | very strong | historical direct source readback | repaired by generated lines 12/13/19 before parser line 683 | incorporate | applied |
| C39 | Four exact manual coverage row replacements are required. | very strong | current read-only row comparison | exact supervisor-owned handoff retained; B002 coverage edits prohibited | incorporate | excluded-with-reason |
| C40 | Final generated output must prove one old state pair and one helper before use with no active regression. | very strong | one-definition/order contract | waited command `15615`, SHA `6B9F3E...F62E`, all assertions passed | incorporate | applied |

## Positive Evidence Summary

- The target range is directly read as 264 zero bytes and lies wholly in the PE virtual tail.
- Guard and table have exact mirrored active/old users, widths, values, lifetimes, and lazy initialization.
- The old raw helper is a complete source-shaped function clone with exact behavior and a modeled parser inline counterpart.
- The validator position rule gave a deterministic compile-order repair with no new child, split, header, or external declaration.
- Historical generated command `15599` proves the pre-callback defect; current command `15615` proves the correction and byte-for-byte preservation of B005's active route while old support occupies positions 1 and 2.

## IDA MCP Facts

- Function/range facts: old parser `0x46eaa0-0x46ee7a` is modeled; old helper `0x46ee80-0x46efda` is raw/non-modeled; the six-byte gap to the next function is `0xcc` padding.
- Data/table facts: guard `0x67acb0`, alignment `0x67acb1-0x67acb8`, table `0x67acb8-0x67adb8`; all target bytes zero.
- Xref facts: four guard refs, 24 table refs, four old charset-start refs, zero gap refs, zero helper-entry/tail refs.
- Type facts: one-byte guard semantics, one-byte table entries, unsigned byte indexing, signed-short source/destination lengths.
- Negative IDA facts: no source symbol, no aggregate type, no class-field route, no cleanup/reset, no direct retained-helper caller.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067aba8-0x0067acb0` active state | UID0002AG | active guard/table | true | UID0000P9 | `92/94` | B005-applied position 0; read-only dependency |
| `0x0067acb0-0x0067acb1` | UID0002AH target subrange | old guard | true | UID0000P9 | applied `92/94` | source declaration 1 |
| `0x0067acb1-0x0067acb8` | UID0002AH target subrange | alignment | non-source | UID0000P9 | included | no child/source field |
| `0x0067acb8-0x0067adb8` | UID0002AH target subrange | old 256-byte table | true | UID0000P9 | applied `92/94` | source declaration 2 |
| `0x0066d430-0x0066d468` | UID000278 | active/old literals | true | UID0000P9 | applied `90/94` | covered literal evidence |
| `0x0046da70-0x0046dbca` | UID0003V1 | active raw helper | true | UID0000P9 | `86/89` | B005/B003 marker; unchanged |
| `0x0046ee80-0x0046efda` | UID000214 | old raw helper | true | UID0000P9 | applied `90/92` | sole old literals/helper body, position 2 |
| `0x0046d580-0x0046da63` | UID0000Z9 | active parser/helper emitter | true | UID0000G2 | `89/91` | B005 union; unchanged |
| `0x0046eaa0-0x0046ee7a` | UID0000ZD | old parser | true | UID0000G3 | `89/91` | existing caller body; unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x67acb0` | reads `0x46ec27`, `0x46ee84`; writes `0x46ecf4`, `0x46ef54` | modeled parser and raw helper each lazily initialize old state |
| `0x67acb8` | 12 parser refs and 12 raw-helper refs | both code copies seed and query the same old table |
| `0x66d44c` | `0x46ec5c`, `0x46eebd` | old reserved-character literal consumed by both copies |
| `0x66d458` | `0x46ece0`, `0x46ef40` | old unsafe-character literal consumed by both copies |
| `0x46ee80` | zero inbound xrefs | retained raw helper has no runtime direct caller |
| `0x46eaa0` | old response route callers at `0x46e850` and `0x46ea1e` | modeled parser is live |
| historical generated call | command `15599`, UID0000ZD line 649 -> `EscapeOldWebBoardUrl` | pre-callback source call existed before definition |
| historical generated definition | command `15599`, UID000214 line 702 | pre-callback blank-position order was not compile-visible |
| current generated definitions | command `15615`, UID0002AH lines 12/13 and UID000214 line 19 | state and helper now precede UID0000ZD parser definition at line 683 |

## Documentation Evidence And IDA Status

- Evidence-time/pre-callback UID0002AH correctly documented the guard/gap/table split and old WebBoard ownership, but its marker-only placement and generated-order sentence were stale. Current UID0002AH is the `92/94` position-1 declaration emitter.
- UID000214 retains the strongest behavior-identical body at current `90/92` position `2`; only the duplicate state declarations were removed.
- UID000278 retains exact bytes, xrefs, active/old names, and literal placement and is now `90/94` with the exact covered marker.
- UID0000ZD already calls the source helper and needs no body change.
- UID0000G3 correctly treats UID000214 as file-local class-context support rather than a member.
- UID0000P9 owns the full file family and preserves the executed B005 active union; its current prose includes the old position-1/2 ordering without loss.
- Historical B005 commands `15576` and `15599` prove the active route and pre-callback old-order defect. Current B002 waited command `15615` emits one active pair, one old pair, and one old helper in compile-visible order with no duplicate target markers.

## Ranked Ownership Analysis

### 1. UID0000P9 WebBoardDialog file

- Evidence for: every target xref is in active/old WebBoard response/escape code; both classes and both static helper families already emit to this source file; generated route exists.
- Evidence against: none.
- Decision: retain as canonical owner/emitter.

### 2. UID0000G3 WebBoardDialogOld class

- Evidence for: old parser and context belong to this class.
- Evidence against: target state and helper have no `this`, absolute file-static addresses, and process lifetime.
- Decision: class context only, not declaration owner.

### 3. UID000214 helper-local ownership

- Evidence-time basis: helper consumed the state and carried the declarations before this callback.
- Evidence against helper-local ownership: the exact state page safely emits directly; the former helper-local placement was after first use and repeated ownership outside its exact range.
- Applied decision: retain helper/literals only at UID000214 position `2`; emit state definitions from UID0002AH position `1`.

### Proposed new file/grouping, if applicable

- Not applicable. `WebBoardDialog.cpp` already exists and owns the complete active/old family.
- No new UID, child, header, source file, ignored range, or split is needed.

## Source Placement

- Applied module: `NexusTK/ui/dialogs/WebBoardDialog.cpp` through UID0000P9.
- File-static internal linkage is retained for both state declaration pairs and both helper/literal families.
- Generated deterministic order after command `15615`: UID0002AG/0, UID0002AH/1, UID000214/2, then blank-position class/method children.
- No `extern` declaration, public header declaration, anonymous struct, namespace relocation, or cross-TU source route was introduced.
- Executed B005 active source remains independent and byte-for-byte preserved on every B005-owned ordinary destination.

## Range / Split / Padding / Reclassification Analysis

- Predecessor UID0002AG ends exactly at `0x0067acb0`.
- Target ends exactly at `0x0067adb8`.
- Successor UID0002AI begins exactly at `0x0067adb8`.
- The target range required no split because guard and table share owner, users, initialization routine, lifetime, and source placement.
- Seven alignment bytes are generated layout only. They remain documented but produce no C++ member/array.
- Applied reclassification is from marker-only covered storage to direct source-bearing file-static state, not from data to code and not from global to class storage.

## Negative Evidence Summary

- No helper entry/tail xrefs or function object were found; this rejects claiming a direct runtime call but does not reject retained source because the inline clone and full raw body are present.
- No xrefs to the seven-byte gap were found; this rejects a source field.
- No xrefs outside WebBoard response/escape code were found; generic Browser ownership is rejected.
- No shared active/old storage refs were found; a shared table is rejected.
- No cleanup, reset, lock, constructor-time initialization, or explicit 256-byte initializer was found.
- No original symbol/PDB evidence was found; source names remain strongly inferred and confidence is capped accordingly.
- Existing documentation, not binary evidence, caused the historical call-before-definition defect repaired by command `15615`.

## IDA Rename / Type / Comment Recommendations

- Proposed source names/types:
  - `byte_67ACB0` -> `static bool s_oldWebBoardUrlEscapeInitialized`.
  - `byte_67ACB8` -> `static unsigned char s_oldWebBoardUrlEscapeTable[256]`.
  - retain `EscapeOldWebBoardUrl` as the strongest descriptive file-local helper name.
  - retain `kOldWebBoardUrlReservedChars` and `kOldWebBoardUrlUnsafeChars`.
- IDA raw names remain useful search aliases only. Exact original lexical spelling is not proven.
- A safe future IDA rename could use the source-facing names, but this assignment does not authorize IDA mutation; no IDA comments/types/names were changed.

## First-Draft C++ Recommendation

- Eligible: UID0002AH and UID000214 are source-bearing. UID000278 needs a non-empty exact no-duplicate marker rather than literal definitions.
- Destination 1: replace the complete formal header/block in `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md` exactly:

*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static bool s_oldWebBoardUrlEscapeInitialized;
static unsigned char s_oldWebBoardUrlEscapeTable[256];
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 2: replace the complete formal header/block in `by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md` exactly:

*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const char kOldWebBoardUrlReservedChars[] = "$&+,/:=?@";
static const char kOldWebBoardUrlUnsafeChars[] = " \"<>#%{}|\\^~[]`";

static char *__cdecl EscapeOldWebBoardUrl(const char *source,
                                          short sourceLength,
                                          char *dest,
                                          short destCapacity)
{
    if (!s_oldWebBoardUrlEscapeInitialized) {
        for (int ch = 0; ch < 256; ++ch) {
            s_oldWebBoardUrlEscapeTable[ch] =
                (ch < 0x20 || ch >= 0x80) ? 1 : 0;
        }

        for (int i = 0; i < 9; ++i) {
            const unsigned char ch =
                static_cast<unsigned char>(kOldWebBoardUrlReservedChars[i]);
            s_oldWebBoardUrlEscapeTable[ch] = 1;
        }

        for (int i = 0; i < 15; ++i) {
            const unsigned char ch =
                static_cast<unsigned char>(kOldWebBoardUrlUnsafeChars[i]);
            s_oldWebBoardUrlEscapeTable[ch] = 1;
        }

        s_oldWebBoardUrlEscapeInitialized = true;
    }

    short sourceIndex = 0;
    short produced = 0;

    while (sourceIndex < sourceLength && produced < destCapacity - 3) {
        const unsigned char ch =
            static_cast<unsigned char>(source[sourceIndex]);

        if (s_oldWebBoardUrlEscapeTable[ch] == 1) {
            sprintf_s(dest + produced,
                      destCapacity - produced,
                      "%%%2X",
                      static_cast<unsigned int>(ch));
            produced += 3;
        } else {
            dest[produced++] = static_cast<char>(ch);
        }

        ++sourceIndex;
    }

    dest[produced] = '\0';
    return dest;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 3: replace the complete formal header/block in `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md` exactly:

*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Active WebBoard URL escape literals are emitted once with UID0000Z9.
// Old WebBoard URL escape literals are emitted once with UID000214.
// This exact initialized-data page documents both literal pairs and must not
// emit duplicate character arrays.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- These are the only three managed formal destinations. UID0000P9 is a by-file root and must not receive reconstruction metadata.
- Behavior preservation: declarations are unchanged in type/value; helper body is byte-for-byte the accepted current body after removing only duplicate state definitions; ordering changes compile visibility only.
- Period style: file-static arrays and helper followed by class methods is conventional for the recovered Visual C++ era and current project source style.
- Third-party import: not applicable; all items are NexusTK project source/data.

## Final Recommendation

- Destinations 1-3 are applied exactly and scoped-validated by commands `15611`-`15613`.
- Destination 4, `by-file/WebBoardDialog.md`, preserves the full executed B005 active union and all unrelated source-family detail, adds only old state position `1`, old helper/literals position `2`, one-definition, no-header, and generated-order facts, remains `91/92`, and passed command `15614`.
- Destination 5 UID0000ZD and Destination 6 UID0000G3 were verified unchanged at their current hashes and same-or-greater detail.
- Destinations 7-9 UID0002AG/UID0000Z9/UID0003V1 remain byte-identical read-only B005 union controls.
- Destination 10 generated `WebBoardDialog.cpp` was changed only by authorized validator generation; command `15615` proves the exact accepted order and counts.
- No new page, rename, split, nested change, class field, public declaration, source file, duplicate definition, or active-source regression occurred.

## Recommended Target Doc Changes

- Applied to `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md`: `92/94`, owner/emitter UID0000P9, reconstructable true, position `1`, `Nested:0`, and byte-equal Destination 1.
- The current page records exact zero bytes/hash, PE mapping, guard/gap/table layout, xref inventory, old charset dependencies, separate active state, names/types, process lifetime, source order, no-header route, and score rationale.
- The `0xff` and helper-before-parser claims are explicitly historical/superseded; provenance remains intact.
- Exact range and all valid older A004/B004/B010 evidence remain as historical corroboration. Current target hash is `0DCADACF421DBDF838A6DECC6670C9DA0371A122942EC4B84061C5006285E585`.

## Recommended Support Doc Changes

- UID000214 is applied at `90/92`, position `2`, with byte-equal Destination 2, exact 346-byte hash, 94-instruction behavior, no-entry-xref retained-source rationale, parser inline clone, source ordering, and sole-helper-definition policy. Current hash: `D146E682B77F7D7B13867A3F4ED1EA1800A5961C99EF53724FE395C37D1D3714`.
- UID000278 is applied at `90/94` with byte-equal Destination 3; all 56 bytes/hash, active/old split, xrefs, names, and duplicate-safe literal sites remain. Current hash: `21D8046970B36CC492FFCBD927D9BE3E8BFAFAF879DB28DB71C5BC2CE6E3BC7A`.
- UID0000P9 remains `91/92` and now records exact source order `0/1/2` plus same-translation-unit internal linkage. The complete active/old family content and B005 details are preserved. Current hash: `9830F9EAA2E6FD08351C67E5BCBDDE9838A16C38BFF2FC567DFE3AE0DBF7291D`.
- UID0000ZD, UID0000G3, UID0002AG, UID0000Z9, UID0003V1, and UID0000G2 were verified at same-or-greater current detail and not edited.
- No by-class, by-global, by-struct, by-type, by-item, source-tree root, or header change was required.

## Score And Metadata Recommendation

- UID0002AH: applied `86/90` -> `92/94`; same UID/path/range/owner/emitter/reconstructable/Nested, position blank -> `1`, marker -> exact definitions.
- UID000214: applied `88/90` -> `90/92`; same UID/path/range/owner/emitter/reconstructable/Nested, position blank -> `2`, duplicate state declarations removed only.
- UID000278: applied `86/93` -> `90/94`; same UID/path/range/owner/emitter/reconstructable/Nested and blank position; exact covered marker refreshed.
- UID0000P9: retained `91/92`; residual original spelling/type uncertainty elsewhere in the broad file prevents a report-local increase.
- Score blockers investigated:
  - image initialization: resolved as zero-fill;
  - exact layout: resolved;
  - liveness: resolved through modeled parser plus retained raw clone;
  - names/types: strongest period-plausible names/types selected;
  - source owner/file: resolved;
  - one definition: resolved;
  - compile order: resolved by positions 1/2;
  - active overlap: resolved by callback-last no-loss rebase;
  - original lexical proof: unavailable, so confidence remains below absolute.

## Open Questions With Attempted Resolution

- Should target stay marker-only? No; exact-range source emission is safe and eliminates indirect ownership.
- Should helper retain state definitions? No; that duplicated target ownership and appeared after use before the callback. Current state emits them from UID0002AH position `1`.
- Should a forward declaration be added? No; positioning the complete helper before class methods is simpler and more original-style.
- Should the seven-byte gap be source-visible? No; exhaustive xref and PE checks prove alignment.
- Is raw helper dead? No; the full retained clone and parser inline equivalent are source-shape proof. Runtime entry reach remains absent and is documented.
- Can active and old state be merged? No; exact independent addresses and consumers reject it.
- Are exact original spellings proven? No. The chosen names are strong descriptive reconstructions; this caps confidence but does not block source-ready C++.
- No investigable blocker remains open.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only callback-return rows and hashes (`by-memory` `6451FC58E3A7222B0C249DC44AD77C7E07B95A901EED5CAA2CF257169761003D`; `by-class` `970D999177D83E7D50EFAE7E1DC6283FAD6EC95D2F7C06B678BCA17ED6976330`; `by-file` `D6EB85E56B3AFF244FBD8972ABEBB61CFA8FA87C606B676D77D165C3809A56A5`):
  - by-memory UID000214 line 626 is stale at `84% strong`.
  - by-memory UID000278 line 4,138 is stale at `84% strong`.
  - by-memory UID0002AH line 4,265 is stale at `86% strong` and retains generic A004 wording.
  - by-file UID0000P9 line 305 has current B005 active-union prose but lacks the applied B002 exact position-1/position-2 wording below.
  - by-class UID0000G3 line 600 is unchanged support and receives no B002 row action.
- B005's separate UID0002AG active-state row remains externally owned by B005/supervisor. B002's rows preserve that active union and do not replace UID0002AG.
- Manual action 1, replace UID000214 row in `by-memory/-coverage-report.md`:

`    - [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) 0x0046ee80-0x0046efda | raw file-local URL escape helper | WebBoardDialogOldUrlEscapeHelper : reconstructable : 90% : very strong : Retained old WebBoard URL escape helper; current live IDA MCP proves the exact 346-byte/94-instruction lazy table initializer and bounded percent-escape body, old state and charset refs, signed-short limits, exact %%%2X formatting, normal return/range-failure tail, no function object or inbound entry xref, and an inline-equivalent modeled old parser clone. Source emits the old literals and helper once at WebBoardDialog.cpp position 2 after UID0002AH old state and before parser use.`

- Manual action 2, replace UID000278 row in `by-memory/-coverage-report.md`:

`    - [UID:000278][0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets](by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md) 0x0066d430-0x0066d468 | character-set data | BrowserUrlEscapeCharacterSets : reconstructable : 90% : very strong : Exact 56-byte duplicated active/old WebBoard URL escape literal pairs with current live byte hash and direct modeled-parser/raw-helper xrefs; active literals emit once with UID0000Z9, old literals emit once with UID000214, and this exact initialized-data page remains a non-duplicating covered-literal marker.`

- Manual action 3, replace UID0002AH row in `by-memory/-coverage-report.md`:

`    - [UID:0002AH][0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState](by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md) 0x0067acb0-0x0067adb8 | file-static URL-escape state group | WebBoardDialogOldUrlEscapeState : reconstructable : 92% : very strong : Old WebBoardDialog file-static lazy-initialization state: current live IDA MCP and PE mapping prove 264 BSS-zero bytes, a one-byte bool guard, seven implicit compiler/linker alignment bytes, a 256-byte unsigned-byte decision table, four guard refs, 24 table refs across the modeled old response parser and retained raw helper, exact old charset dependencies, separate active state, process lifetime with no cleanup/reset, sole WebBoardDialog.cpp ownership, and one source-ready position-1 declaration pair with no duplicate storage.`

- Manual action 4, replace UID0000P9 row in `by-file/-coverage-report.md` after applying/preserving B005's active row:

`- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) : reconstructable : 91% : very strong : NexusTK/ui/dialogs/WebBoardDialog.cpp owns the complete active and old WebBoardDialog source families, exact active/old singleton children, constructors/destructors, packet/request/response paths, browser-control navigation, rendering/layout helpers, resources, compiler-wrapper exclusions, and separate URL-escape families; UID0002AG emits the sole active guard/table pair at position 0, UID0002AH emits the sole old guard/table pair at position 1, UID000214 emits the old literals and EscapeOldWebBoardUrl helper at position 2 before old parser use, UID0000Z9 retains the active literals/initializer/helper/handler, and raw helper/data pages remain duplicate-safe.`

- Placement: replace each existing UID row in place; do not add duplicates. Supervisor must re-read the current no-loss union before applying.
- B002 must not edit manual coverage; only the supervisor owns application/validation. The tracker is validator-generated and receives no manual text.

## Follow-Up Actions

- B002 callback responsibility is complete: mandatory B005 rebase, Destinations 1-4, verify-only checks 5-10, four scoped validators, lease-free waited generation, exact readback, ledger reconciliation, and lease release are recorded.
- Remaining unapplied accepted implementation items: zero. Blocked implementation claims: zero. C39 is terminally `excluded-with-reason` only because manual coverage is supervisor-owned; the exact four-row handoff remains below.
- Manual coverage application/validation and report execution/lifecycle are external supervisor/validator-owned state. This records ownership without asserting a present or future lifecycle action as B002 work.
- No A-agent or additional B-agent research is required.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong.
- Remaining uncertainty: original source spellings and whether the compiler independently chose seven-byte alignment; neither affects behavior, types, one-definition route, or generated compile order.

## Validator Results

- `000000015611`, `2026-07-21T08:55:27-04:00`: UID0002AH scoped validator, exit `0`, `ok:1`; completion `92`, confidence `94`, position `1`, formal/registry update; generated refresh deferred. Side effects were validator-owned registry/projected-stat updates only.
- `000000015612`, `2026-07-21T08:56:35-04:00`: UID000214 scoped validator, exit `0`, `ok:1`; completion `90`, confidence `92`, position `2`, formal/registry/reference update; generated refresh deferred. Side effects were validator-owned registry/reference/projected-stat updates only.
- `000000015613`, `2026-07-21T08:57:25-04:00`: UID000278 scoped validator, exit `0`, `ok:1`; completion `90`, confidence `94`, marker/registry update; generated refresh deferred. Side effects were validator-owned registry/projected-stat updates only.
- `000000015614`, `2026-07-21T08:58:25-04:00`: UID0000P9 scoped validator, exit `0`, `ok:1`; generated refresh deferred. It repeated nine pre-existing missing-registry warnings for UID0003V2/UID0003V3/UID0003V4 and changed only validator-owned projected stats.
- `000000015615`, `2026-07-21T08:58:37-04:00`: final lease-free waited UID0000P9 validation, exit `0`, `ok:1`, `generated_refresh: completed`. It repeated the same nine UID0003V2/3V3/3V4 warnings plus project-wide pre-existing counts (`84` children-marker, `13` children-fallback, `131` emitter-without-code); no accepted destination failed.
- Generated result: `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`, command/header `15615`, SHA256 `6B9F3ED0FF77FD287F0B2C42AF7AEEB2911347C93A73477ACDC9875B2F16F62E`, 26,562 bytes / 759 lines. Exact active declarations occur once at lines `8/9`; old declarations once at `12/13`; old helper definition once at `19`; old parser definition at `683`. UID0002AH/UID000214/UID000278 Empty Emitter Markers are zero; UID0003V1 remains the no-duplicate marker; active B005 pages/hashes are unchanged.
- Tracker result at command `15615`: SHA256 `74220541F117DC0F4D1169A97175573102D9BA32E67D13361AB556639DEBB605`, 1,536,943 bytes / 6,223 lines; UID0002AH row 3,273 is `92/94`, reconstructable true, `Nested:0`.
- Validators changed generated/registry/tracker/auto-coverage/projected-stat state only through authorized tool side effects. B002 did not edit any such file directly.

## Changed Files

- Same report updated in place: `tools/leaser/Agents/Agent-B002/research/0002AH-WebBoardDialogOldUrlEscapeState-source-quality.md`.
- Changed ordinary pages after scoped validation:
  - UID0002AH `0DCADACF421DBDF838A6DECC6670C9DA0371A122942EC4B84061C5006285E585` (10,057 bytes / 87 lines).
  - UID000214 `D146E682B77F7D7B13867A3F4ED1EA1800A5961C99EF53724FE395C37D1D3714` (20,265 / 200).
  - UID000278 `21D8046970B36CC492FFCBD927D9BE3E8BFAFAF879DB28DB71C5BC2CE6E3BC7A` (17,473 / 132).
  - UID0000P9 `9830F9EAA2E6FD08351C67E5BCBDDE9838A16C38BFF2FC567DFE3AE0DBF7291D` (48,353 / 200).
- Verify-only pages remained unchanged: UID0002AG `265A70...506`, UID0000Z9 `C9D956...5C93A`, UID0003V1 `D4038A...80F0`, UID0000G2 `339BEF...DE3B`, UID0000ZD `58CDD3...A51447`, UID0000G3 `773F26...99B04`.
- Validator-owned generated/tracker/registry/auto-coverage/projected-stat files changed only through commands `15611`-`15615`; manual coverage, audit, supervisor, lifecycle, IDA, and executed-archive files were not edited by B002.
- Renamed/split/created ordinary pages: none. Report execution/lifecycle command run by B002: none. Final B002 lease count: zero.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 validation passed before implementation.
- [x] Confirm ledger actions use only `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`, or `not-applicable`; callback verification states are legal terminal values.
- [x] Re-read executed B005 report, current shared docs, generated output, manual rows, tracker, and leases before callback.
- [x] Preserve UID0002AG position-0 active state exactly.
- [x] Preserve UID0000Z9 active literals/initializer/helper/handler exactly.
- [x] Preserve UID0003V1 active no-duplicate marker exactly.
- [x] Apply UID0002AH `92/94` metadata and position 1.
- [x] Apply Destination 1 exactly.
- [x] Apply exact target Item Summary without generated metadata duplication.
- [x] Incorporate target bytes/hash and PE virtual-tail proof.
- [x] Incorporate guard/gap/table and exact xref inventories.
- [x] Incorporate active/old separation and process-lifetime evidence.
- [x] Historicalize `0xff` and marker/helper-before-parser assumptions.
- [x] Apply UID000214 `90/92` metadata and position 2.
- [x] Apply Destination 2 exactly, removing only duplicate old state declarations.
- [x] Preserve exact old literal arrays and complete helper body.
- [x] Incorporate no-function/no-entry-xref and inline-clone liveness proof.
- [x] Preserve `%%%2X`, signed-short limits, null termination, and range-failure tail.
- [x] Apply UID000278 `90/94` metadata.
- [x] Apply Destination 3 exact covered-literal marker.
- [x] Preserve all 56 bytes/hash and active/old charset xrefs.
- [x] Update UID0000P9 prose only with complete position 0/1/2 source order.
- [x] Preserve UID0000P9 `91/92` and full unrelated file-family union.
- [x] Verify UID0000ZD unchanged.
- [x] Verify UID0000G3 unchanged.
- [x] Verify current active B005 destinations unchanged.
- [x] Confirm no new page, UID, rename, split, child, ignored row, or nesting change.
- [x] Confirm no header, `extern`, class field, shared table, or cross-TU route.
- [x] Confirm no third-party import applies.
- [x] Lease one ordinary file only immediately around edit/validation.
- [x] Reread/rebase each destination after leasing.
- [x] Run one scoped validator per changed ordinary page.
- [x] Record command ID, timestamp, exit, ok, warnings, side effects, and hash.
- [x] Release each lease immediately.
- [x] Run one final authorized waited generated refresh after zero ordinary leases.
- [x] Verify exact generated order 0/1/2 before blank-position methods.
- [x] Verify one old state pair, one old literal pair, and one old helper.
- [x] Verify old helper definition precedes old parser body/use.
- [x] Verify one active state/helper family and no B005 regression.
- [x] Verify no UID0002AH Empty Emitter Marker or duplicate storage/literals.
- [x] Verify UID0003V1 remains no-duplicate marker only.
- [x] Preserve all historical provenance, rejected alternatives, and negative evidence.
- [x] Update C01-C40 to legal terminal states with destination proof.
- [x] Update Current Target State, recommendations, scores, validators, changed files, hashes, and generated proof.
- [x] Preserve exact four-action supervisor-owned manual coverage handoff.
- [x] Check every implementation item only after direct proof.
- [x] Confirm no placeholder/provisional UID remains.
- [x] Confirm zero B002 leases.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] B005 shared active callback terminal, executed, and reread.
- [x] All accepted target/support details incorporated at report-level detail.
- [x] All three managed destination blocks byte-equal to their current ordinary destinations.
- [x] All C01-C40 rows terminalized with legal states and separate proof.
- [x] Metadata/score/position changes applied exactly and no others.
- [x] Same-or-greater unrelated content preserved.
- [x] Historical assumptions and rejected alternatives retained.
- [x] Scoped validators and final waited refresh recorded.
- [x] Generated assertions independently read back.
- [x] Exact manual handoff remains supervisor-owned.
- [x] Remaining blocked/unapplied accepted implementation items count is zero.
- [x] Checklist has no false checked item.
- [x] Exactly one terminal readiness marker remains.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000015649","destination_path":"executed-b-agent-research/B002/0002AH-WebBoardDialogOldUrlEscapeState-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002AH-WebBoardDialogOldUrlEscapeState-source-quality.md","timestamp":"2026-07-21T09:22:01-04:00","uid":"0002AH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
