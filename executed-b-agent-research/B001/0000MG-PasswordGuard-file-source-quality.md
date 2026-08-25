# UID0000MG PasswordGuard Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000MG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Reconstruct `NexusTK/auth/PasswordGuard.cpp` and required sibling `PasswordGuard.h` as one complete guard module with three authored definitions in source order: `SetProtectedPasswordToken`, `GetProtectedPasswordToken`, and `ValidateChatInputOrThrowPasswordError`.
- Retain the two exact file statics `g_protectedPasswordToken[32]` and `g_passwordProtectSeed = 0xd544`; represent `PASS_ENG.STR` at its source use rather than as a standalone table.
- Exact by-memory children are implemented as [UID:00055E][0x00465830-0x0046588c.GetProtectedPasswordTokenRaw](by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md) and [UID:00055F][0x00612e8c-0x00612ea6.PasswordGuardPassEngString](by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md); no pre-assignment placeholder remains.
- The accepted callback corrected source order and line-loop lowering, supplied all header/declaration/include routes, restored both NewMail guard calls, repaired PasswordError child emission, and closed UID0000C5/UID000406 so the sixth SayInputPanes guard call emits from complete inline source.
- Primary ordinary metadata is implemented at `94/95`. Confidence remains below recovered-symbol certainty because original identifiers and the exact historical filename are inferred, but bytes, behavior, ownership, ABI, callers, dependencies, source placement, validation, and generated readback are complete.

## Supporting Research

- This is a whole-file audit, not a sample of UID0002VG and UID0002VH. It covers every discovered PasswordGuard code body, static, source literal, internal gap, caller, callee, declaration dependency, source owner, generated destination, and adjacent exclusion.
- Live canonical MCP session `supervisor_uid0002ox_persistverify_20260817` was enumerated before use and runtime-attested at `2026-08-17T21:48:47.132050Z` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Session identity is dated evidence; Gate 2B must enumerate and attest the then-active canonical session again.
- Dated repair recheck at `2026-08-18T00:35Z` enumerated four active sessions. The long-lived canonical worker retained stale in-memory automatic-name state, so it was not treated as fresh disk authority. Runtime-attested read-only session `supervisor_uid0000ji_postsaveverify_20260817_1948` opened a post-save verification snapshot whose exact SHA256 `83D734B1E8F429C178DE32335B395C0F03F41426E511CF905218086D7E817CA3` and 143,209,591-byte size matched the canonical disk exactly; that byte-identical snapshot reproduced the supervisor's failed-Gate-2B prestates. This is a dated evidence receipt, not a session to reuse at a later gate.
- Fresh supervisor Gate 2B preflight used canonical session `supervisor_uid0000hf_postdiscard_20260818` at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; runtime attestation was `ok:true` at `2026-08-18T04:16:59.143673+00:00`. B001 re-enumerated that active session and independently re-attested it `ok:true` at `2026-08-18T04:21:23.725258+00:00`; bounded health, item, name, comment, frame, byte, disassembly, callee, and xref reads succeeded. Canonical disk was physically reread as SHA256 `8742915867D2D6DBC728AEA295DC830F9C5FE1CEA66099D532EF8EE6163D274E`, 143,210,685 bytes. The supervisor preflight and B001 reanalysis performed no IDA mutation, backup, save, or process action; only the two explicitly recorded `dry_run:true` rename requests were issued.
- `server_health` returned `status:ok`, image base `0x400000`, Hex-Rays ready, and canonical IDB path matched. `auto_analysis_ready:false` and an initially cold string cache were non-blocking because bounded function, item, byte, comment, frame, xref, disassembly, and decompile queries succeeded.
- Matching archived reports read as leads were B001 UID0000YS and UID000275; B008 UID0002VG and UID000290; B005 UID0002VH and UID0002Q5; B013 UID0002VJ; B009 UID0002VK/Error; B010 UID0002VL; B005 UID0002NE; and the caller-family reports for UID0001KW, UID0001MC, UID0001LZ, and UID0001MF. Current docs, generated output, and fresh MCP evidence control where older wording conflicts.
- The canonical executable identity used for corroboration is SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` at both the MCP input route and preservation copy.

## Target

- Target UID: `0000MG`.
- Additional target UIDs: none. All other UIDs are support destinations, exclusions, or callback-created exact children under the primary source owner.
- Target path: `by-file/PasswordGuard.md`.
- Report path: `tools/leaser/Agents/Agent-B001/research/0000MG-PasswordGuard-file-source-quality.md`.
- Implemented ordinary metadata: `94/95`, owner `FILE`, path `NexusTK/auth/`.
- Generated destinations: `auto-generated/NexusTK/auth/PasswordGuard.cpp` and `PasswordGuard.h`; Section 31 records dated callback identities, while later gates must reread them dynamically.

## Current Target State

- UID0000MG ordinary metadata now routes the complete six-item source order: UID000290 token `10`, UID00035L seed `20`, UID0002VG setter `30`, UID00055E decoder `40`, UID0002VH validator `50`, and UID00055F literal marker `60`. UID0002VG owns the complete sibling H.
- The six stale callback padding-hash transcriptions in `by-file/PasswordGuard.md` and `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md` are corrected without changing ranges or bytes: G1 nine `cc` bytes hash `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; G2 four `cc` bytes hash `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`; G3 fourteen `cc` bytes hash `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`. Scoped validator commands `000000025808` and `000000025809` each returned `ok:1`.
- Dated generated snapshot command `000000025640` at `2026-08-17T17:20:57-04:00` produced `PasswordGuard.cpp`, SHA256 `15B7BB3628C5372A5FD39078D8113F0A643168D82F42F227047A47D564F304A5`, 2,753 bytes / 76 physical lines, and no `PasswordGuard.h`. This is callback input evidence, not continuing generated authority; Gate 2A rereads validator-owned output dynamically.
- The dated generated CPP snapshot omitted complete code `[0x00465830,0x0046588c)`, declared no public API, included none of `PasswordGuard.h`, `DATFile.h`, or `Error.h`, and used undeclared `DATFile` and `PasswordError` types. Those are historical pre-callback defects; dated completion readback in Sections 31-32 proves their accepted repairs.
- UID0002VH's former formal body was behaviorally partial: it duplicated the decoder, named stale `ReadLineRaw`, tested the first line before terminating/converting it, emitted explicit invalid-parameter calls, and cleared the decoded token for `text == NULL`. Its implemented formal body now calls UID00055E, uses `ReadLineChars`, preserves convert-before-break lowering, uses natural indexed source, and performs the exact conditional clear.
- Dated command `000000025640` generated consumer output contains the setter call and 10 of 13 validator calls. `NewMailDialog::SendMail` lacks the two exact calls at binary sites `0x0047de03` and `0x0047de0f`; `SayInputPanes.cpp` lacks UID000406's complete clan-submit child and its exact call at `0x005b23d0`; every consumer translation unit also lacks a PasswordGuard declaration include. The dated `SayInputPanes.cpp` snapshot is SHA256 `1892D74082F5159131D46F13F9E111DB54F0FC215204734CC54DD33BBFB323CC`, 16,372 bytes / 495 physical lines, with five of six family calls and `[[No Children Attached]]` under UID0000C5; its H snapshot is SHA256 `3F1DC788F540CE63C331CDE3162DBF7CB8AAE283C7AE93E470C257125A4E52C3`, 2,405 bytes / 86 physical lines, with no UID0000C5 class declaration. These are dated defect receipts, not continuing generated authority.
- At pre-callback readback, generated `Error.h` declared Error/MyError/Win32Error but not PasswordError, while `Error.cpp` contained only a PasswordError marker. Dated completion readback proves one PasswordError declaration/0x8 assertion and one constructor plus one `GetErrorName` definition through repaired UID0000A8 children.
- At pre-callback readback, `DATFile.h` contained only `LoadDatFileBuffer`, `File.cpp` embedded the File declaration, and `File.h` was absent. Dated completion readback proves guarded complete File/DATFile headers and include-plus-child CPP routes, including canonical `ReadLineChars`.
- Historical repair-cycle fact: Gate 1 and Gate 2A passed exact report SHA256 `854C265796195DCF7CD780BDBAD76169E0F7CF056025A15EF6ECE3CE2B9014CA`, then Gate 2B failed closed before mutation because I05 conflated a disassembly-only automatic alias with a public item name and I06 carried stale item name/type text. No mutation or save occurred; canonical and transaction disk identities remained SHA256 `83D734B1E8F429C178DE32335B395C0F03F41426E511CF905218086D7E817CA3`, 143,209,591 bytes. Later exact report SHA256 `2BD1732770459EC1ED83D9B709DBEF56EABA8392D4F373472A28A65DE79DF302` passed current Gate 1 and all 61 B001-owned Gate 2A claims, then fresh Gate 2B read-only preflight failed before mutation because the canonical I05/I06 prestates had advanced to the literal states now recorded in Sections 13 and 21. No mutation, backup, save, or process action occurred. This additive report revision preserves accepted ordinary implementation and requires a fresh exact-artifact Gate 1 audit before another Gate 2B attempt.
- The current report path and validator-owned status/history metadata are authoritative for lifecycle state. This ordinary body makes no current execute/archive assertion.

## Executive Recommendation

UID0000MG is the strongest and only coherent source owner. Login supplies the token through one setter call; thirteen board/mail/social/chat callers consume one shared throwing guard; both statics and the raw decoder have only PasswordGuard references. Error owns the thrown class, DATFile owns archive reading, and callers own their UI/packet logic.

The raw helper is source-authored even with zero inbound xrefs. Its complete prologue, two return paths, caller-buffer ABI, `_wcsncpy_s`, token/seed references, and return of the destination prove a function body. UID0002VH contains an exact fixed-size inlined specialization, which explains why the externally linked out-of-line copy has no retained callsite. Preserve both the source helper and the inlined binary shape.

Use a real sibling header because the setter and validator have cross-translation-unit callers and the raw helper's external retention is best explained by external linkage. Keep file statics private to CPP. Source-facing names are descriptive project names, not claimed recovered symbols.

## Supervisor Active Recheck

- Supervisor assigned UID0000MG after UID0002OX lifecycle completion and required live canonical MCP.
- Fresh MCP corrected the stale two-function inventory to three source definitions and corrected the raw helper's exclusive end from the old inclusive-style `0x0046588b` wording to `[0x00465830,0x0046588c)`.
- Fresh generated readback exposed one missing PasswordGuard sibling H, the incomplete DATFile/Error declaration chain, two NewMail call omissions, and the UID0000C5 owner-route defect that suppresses UID000406. Re-reading UID000406 then exposed its separate undeclared-helper shorthand: live `0x005b2390` proves the packet serialization is inline source, so both the child body and owner route require closure.
- The fresh Gate 2B preflight was fail-closed and mutation-free. Current-schema read-only evidence now separates UID000290's `inspect_items` effective resolver alias `unk_67A940` from the absent public named entry reported by `entity_query(kind:names)`, and proves the exact pure data-rename dry-run resolves that alias without changing either view. UID00055F is now literally a public four-byte head named `aPa_2` with type `const wchar_t[]`; the supported deterministic action is a pure rename to `aPasswordGuardPassEngResourcePath` followed by the accepted regular address comment, with all physical items, the interior public `aEngStr` suffix item, bytes, type state, xref, alignment, and successor protected.
- The same fresh public-MCP reread confirmed I01-I04 without drift: both function names/declarations/full frames/four comment channels/ranges/hashes/xrefs/callees, the raw helper item/function/frame/comment/xref state, and the seed item/name/type/comments/bytes/hash/xrefs all match their literal Section 21 prestates. Thus the ordered transaction changes only the two disputed data-stage contracts, not any earlier target protection.
- No report recommendation depends on mutable session identity. Gate 2B binds structured requests only after fresh runtime attestation.

## Inference Research Guidance Check

- Hard facts: ranges, bytes/hashes, function/item state, exact frames, comments, call/data xrefs, instructions, callees, resource bytes, generated fragments, and existing emitter metadata.
- Strong contextual inference: same-TU helper inlining, `GetProtectedPasswordToken` spelling, `auth/PasswordGuard` filename, and external header placement.
- Rejected stopping reasons: raw start, zero xrefs, unknown original symbol, decompiler return types, stale DAT method name, and absent current H. Each has an evidence-backed implementation disposition below.
- Period-appropriate source is ordinary VC6/VC7 C++ with CRT/Win32 APIs and no decompiler labels, explicit vtable mechanics, ABI throw calls, or generated range-check calls.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Disposition |
| --- | --- | --- |
| Two functions versus complete file | Token/seed xrefs expose a third complete decoded body at `0x00465830`. | Three authored definitions. |
| Raw body with zero xrefs | Full ABI body plus exact fixed-size specialization in UID0002VH. | Externally linked source helper retained; validator call inlined. |
| Helper name | Returns caller destination and mirrors setter semantics. | `GetProtectedPasswordToken`; reject IDA label or anonymous raw helper. |
| Setter/validator returns | Callers use side effects/throw contract; EAX is incidental. | Source `void`; leave IDA types unchanged in the safe handoff. |
| Validator line loop | Binary terminates and converts every line, then stops on length `<=1`. | Correct loop order; no explicit runtime-failure call in source. |
| Decoded stack clear | Binary clears only inside non-null text path after no throw. | Preserve exact conditional clear. |
| PASS string | One exact source use, no independent state. | Covered by `L"PASS_ENG.STR"`, exact child, no static table. |
| PasswordError ownership | Constructor/vtable/name belong to Error; guard only allocates/throws. | Repair Error declaration/child route; do not move class. |
| DATFile dependency | Concrete 0x14 stack object and virtual stream contract are established. | Complete File.h/DATFile.h declarations; use `ReadLineChars`. |
| Consumer declarations | Calls span seven source roots and the dated generated output has no PasswordGuard include. | Add one exact include route per source root. |
| NewMail generated parity | Binary has two calls immediately after subject/body extraction; source has zero. | Restore both before sanitization. |
| Clan generated parity | Binary has one guard call inside inline packet serialization; UID000406 abbreviates the packet as an undeclared helper and UID0000C5 suppresses the child. | Emit Section 22's complete UID000406 body through UID0000C5 CPP children and H declaration. |
| FatalError adjacency | Application-oriented fan-in and distinct semantics. | Exclude UID0002VI from PasswordGuard. |

## Evidence Standards Used

- Primary: live canonical MCP `entity_query`, `lookup_funcs`, `inspect_items`, `stack_frame`, `get_comments`, `get_bytes`, `insn_query`, `decompile`, `callees`, and `xref_query`.
- Independent hash check: every bounded MCP byte read below was hashed with .NET SHA256; values matched prior sound evidence where available.
- Corroboration: current by-* pages, generated CPP/H, manual coverage rows, exact caller source, and matching archived reports.
- Negative evidence: no raw-helper inbound xref, no desired-name collision, no file-owned class/vtable/RTTI, no non-PasswordGuard seed/token references, no PASS literal second use, and separate successor owners.

## Evidence Checked

- Enumerated active MCP sessions before selecting canonical session `supervisor_uid0000hf_postdiscard_20260818`; supervisor attestation at `2026-08-18T04:16:59.143673+00:00` and B001 re-attestation at `2026-08-18T04:21:23.725258+00:00` both returned `ok:true`, and bounded health/query checks passed against the exact canonical path.
- Read complete `[0x004657d0,0x00465af0)` code/padding band, all three bodies, all three internal gaps, exact function frames/comments/types, and every target/callee/data xref.
- Read exact data items at `0x0066d410`, `0x0067a940`, `0x0067a97e`, `0x0067a980`, `0x00612e8c`, `0x00612ea6`, and `0x00612ea8`.
- In the fresh canonical session, pre-dry-run `inspect_items(0x0067a940)` returned `[0x0067a940,0x0067a941)`, effective name `unk_67A940`, type `wchar_t`, `is_code:false`, `is_data:false`, while `entity_query(kind:names)` returned no public named entry in `[0x0067a940,0x0067a981)`. Five operands rendered `unk_67A940`. Exact request `{"database":"supervisor_uid0000hf_postdiscard_20260818","batch":{"data":{"old":"unk_67A940","new":"g_protectedPasswordToken"},"pure":true,"allow_overwrite":false,"dry_run":true,"stop_on_error":true}}` returned one resolved item at `0x67a940`, `ok:1`, `failed:0`, `stopped:false`; immediate inspect/name/comment/xref reads remained identical and the destination remained absent.
- The same fresh session returned UID00055F head `[0x00612e8c,0x00612e90)`, size four, public name `aPa_2`, type `const wchar_t[]`, `is_code:false`, `is_data:true`; `[0x00612e90,0x00612e94)` is unnamed/untyped four-byte data and `[0x00612e94,0x00612ea6)` is 18-byte data with public name `aEngStr` and type absent. Disassembly at `0x0046592d` is exactly `push offset aPa_2; path`. Exact request `{"database":"supervisor_uid0000hf_postdiscard_20260818","batch":{"data":{"old":"aPa_2","new":"aPasswordGuardPassEngResourcePath"},"pure":true,"allow_overwrite":false,"dry_run":true,"stop_on_error":true}}` likewise returned one resolved item at `0x612e8c`, `ok:1`, `failed:0`, `stopped:false`; immediate inspect/name/comment/xref reads remained identical and the destination remained absent.
- Read all 13 validator callsites and mapped them to 11 owning source definitions plus their by-memory/by-class/by-file routes.
- Re-read UID0000C5, UID000406, dated `SayInputPanes.cpp/.h`, and live `0x005b22d0`/`0x005b2390`; confirmed that the missing clan call is a broken owner/child route plus an incomplete helper-shorthand body, not a missing binary callsite.
- Read UID0000MG, UID0000YS, UID0002VG, UID0002VH, UID0002VI, UID0002VJ/VK/VL, UID00035L, UID000275, UID000290, UID000487, UID0000A8, UID00004J, UID00003G, UID00004V, and all named caller support pages.
- Read generated PasswordGuard, Error, DATFile, File, LoginDialogPane, BoardDialogs, MailDialogs, Chatting, SayInputPanes, UserListDialogPane, and SpellInputPanes outputs.
- Read current manual by-file, by-memory, and by-class coverage rows for every proposed score/path/inventory change.
- Searched desired names `SetProtectedPasswordToken`, `GetProtectedPasswordToken`, `ValidateChatInputOrThrowPasswordError`, `g_passwordProtectSeed`, `g_protectedPasswordToken`, and `aPasswordGuardPassEngResourcePath`; all returned zero current collisions.
- The initial report-only phase ran no validator or ordinary edit. The accepted callback then changed only the 22 ordinary pages listed in Section 32 through serial scoped validators; it did not edit manual coverage, generated files, IDA, audit/catalog/tracker, lifecycle state, or execute/archive this report.

## Claim And Incorporation Ledger

Post-callback allocation: `61 checked / 20 unchecked`. C001-C055 and C074-C079 are physically implemented or verified; supervisor-owned coverage C056-C064/C080-C081 and IDA C065-C073 remain unchecked/proposed. Section 33 is the exact eight-field twin after removing `Done`.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0000MG | Raise score `86/90 -> 94/95`; retain `NexusTK/auth/PasswordGuard.cpp` and add required sibling H. | Very strong | Complete code/data/caller/declaration audit. | UID0000MG metadata/Status | incorporate | applied |
| C002 | 0000MG | Record exhaustive inventory as three definitions, two file statics, one covered literal, and three internal gaps with exact raw hashes G1 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`, G2 `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`, and G3 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; no class/vtable/RTTI. | Certain | Complete bounded family scan and corrected raw-byte hash audit. | UID0000MG whole-file inventory / `by-file/PasswordGuard.md` | incorporate | applied |
| C003 | 0000MG | Historicalize dated generated omissions: no H, missing raw helper, incomplete validator, undeclared dependencies, two absent NewMail calls, and one suppressed clan-submit call. | Certain | Command 000000025640 physical readback. | UID0000MG generated-state history | historicalize | applied |
| C004 | 0000MG | Emit positions token `10`, seed `20`, setter `30`, UID00055E decoder `40`, validator `50`, UID00055F literal marker `60`. | Strong | Address order and dependency order. | UID0000MG source-order table | incorporate | applied |
| C005 | 0000MG | Keep direct owner/file placement in `auth/PasswordGuard`; reject Error, Application, login, and chat owners. | Very strong | State and caller confinement. | UID0000MG ownership/placement | already-present | already-present |
| C006 | 0002VG | Own complete guarded PasswordGuard H with all three declarations; other child H blocks stay blank to prevent duplicates. | Very strong | Cross-TU callers and raw external retention. | UID0002VG formal H | incorporate | applied |
| C007 | 000290 | Add PasswordGuard/DATFile/Error plus CRT/Win32 includes before token static. | Very strong | All emitted identifiers require declarations. | UID000290 formal CPP | incorporate | applied |
| C008 | 000290 | Preserve exact 32-wchar zero-initialized file static, bytes/hash/xrefs/boundary, and stale-alias history; score `88/91 -> 92/95`. | Certain | 64 bytes and five exact refs. | UID000290 metadata/evidence/formal CPP | incorporate | applied |
| C009 | 00035L | Preserve writable 16-bit file static initialized `0xd544`, three exact refs, and score `88/91 -> 92/95`. | Certain | Bytes `44 d5`, exact xrefs. | UID00035L metadata/evidence/formal CPP | incorporate | applied |
| C010 | 0002VG | Preserve exact setter copy, forced index-31 NUL, incrementing XOR, sole caller/callee, and source-void body; score `90/92 -> 93/95`. | Very strong | Exact body/frame/xrefs. | UID0002VG formal CPP/evidence | incorporate | applied |
| C011 | UID00055E | Create exact child `by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md`; replace label with assigned UID before readiness. | Certain | Complete raw code range and boundaries. | New exact by-memory child | incorporate | applied |
| C012 | UID00055E | Record zero-count write/return and positive-count copy, forced tail NUL, incrementing XOR decode, destination return, 40 instructions, and exact hash. | Certain | Full disassembly and bytes. | UID00055E behavior/evidence | incorporate | applied |
| C013 | UID00055E | Resolve zero-xref liveness as externally retained helper whose fixed-size call is inlined into UID0002VH; reject dead/padding classification. | Strong | Exact specialization equivalence. | UID00055E inference/history | reject-stale | applied |
| C014 | UID00055E | Emit complete decoder CPP at position `40`; H blank because UID0002VG centrally owns the declaration; recommend `93/95`. | Very strong | ABI/source reconstruction. | UID00055E metadata/formal channels | incorporate | applied |
| C015 | 0002VH | Replace validator with helper call, exact loop order, `ReadLineChars`, natural indexed source, exact conditional clear, and ordinary pointer throw. | Very strong | Full decompile/disassembly/callees. | UID0002VH formal CPP | reject-stale | applied |
| C016 | 0002VH | Keep source-void contract, move emitter `40 -> 50`, preserve 13 callers and complete stack/callee evidence, score `88/90 -> 94/95`. | Very strong | Caller use and exact frame. | UID0002VH metadata/evidence | incorporate | applied |
| C017 | UID00055F | Create exact child `by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md`; replace label with assigned UID before readiness. | Certain | Exact UTF-16 range/hash/xref. | New exact by-memory child | incorporate | applied |
| C018 | UID00055F | Route literal through UID0000MG as covered source use at position `60`; no standalone static and H blank; recommend `92/95`. | Very strong | One use in validator. | UID00055F formal channels/evidence | incorporate | applied |
| C019 | 0000YS | Record G1 `[0x465827,0x465830)` as nine `cc` bytes/hash `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`, G2 `[0x46588c,0x465890)` as four `cc` bytes/hash `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`, and G3 `[0x465ae2,0x465af0)` as fourteen `cc` bytes/hash `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, with blank CPP/H. | Certain | Exact `cc` byte reads, boundaries, and corrected raw-byte hashes. | `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md` split/padding inventory | incorporate | applied |
| C020 | 0000YS | Preserve mixed aggregate non-emitting status while adding UID00055E and corrected exact child/source ownership. | Certain | Mixed 34-function island. | UID0000YS inventory/history | incorporate | applied |
| C021 | 0002VI | Preserve Application ownership for FatalErrorDialogAndBreak; no PasswordGuard source or score change. | Certain | Fatal/application caller fan-in. | UID0002VI no-change support | already-present | already-present |
| C022 | 0000YS | Exclude `0x465af0`, `0x465b70`, `0x465b90`, `0x465bb0` and later Application functions from PasswordGuard. | Certain | Fresh decompilation and separate state. | UID0000YS exclusion inventory | incorporate | applied |
| C023 | 0000A8 | Preserve PasswordError as Error-owned class and PasswordGuard as allocation/throw consumer only. | Certain | Constructor/vtable/descriptor routes. | UID0000A8 ownership | already-present | already-present |
| C024 | 00004J | Add complete PasswordError declaration and 0x8 size assertion to the sole coordinated Error H; keep score unchanged. | Very strong | Generated H omission and exact hierarchy. | UID00004J formal H | incorporate | applied |
| C025 | 0000A8 | Replace class-level marker with `[[CHILDREN]]` CPP expansion; H remains blank because UID00004J owns declarations; score `86/90 -> 92/95`. | Very strong | Generated Error.cpp omits ready children. | UID0000A8 formal channels/metadata | reject-stale | applied |
| C026 | 0002VJ | Preserve existing constructor body and emit it through repaired UID0000A8 route; no direct PasswordGuard ownership. | Certain | Base call/vtable store/sole throw caller. | UID0002VJ already-present CPP | already-present | already-present |
| C027 | 0002VK | Preserve scalar deleting destructor as compiler-generated covered-by support; no handwritten wrapper. | Certain | Vtable-only route and cleanup/delete shape. | UID0002VK no-code evidence | already-present | already-present |
| C028 | 0002VL | Preserve existing `GetErrorName` definition and emit it through repaired UID0000A8 route. | Certain | Six-byte vtable-only accessor. | UID0002VL already-present CPP | already-present | already-present |
| C029 | 0002NE/00047X | Preserve vtable/descriptor data as compiler/source-use covered by Error declaration and name method; exclude from PasswordGuard. | Certain | Exact vtable/literal routes. | Error support pages | already-present | already-present |
| C030 | 00004V | Move the complete File declaration from formal CPP to guarded File H; CPP becomes include plus children; score unchanged. | Very strong | Generated File.h absent. | UID00004V formal CPP/H | incorporate | applied |
| C031 | 00003G | Add complete 0x14 DATFile declaration to DATFile H and owner include/children CPP route; score unchanged. | Very strong | Exact layout/vtable contract. | UID00003G formal CPP/H | incorporate | applied |
| C032 | 00003G/0002VH | Use canonical `ReadLineChars(char *, int)` and historicalize stale `ReadLineRaw` wording. | Certain | IDA callee `DATFile_ReadLineChars` and File slot map. | UID00003G and UID0002VH docs/source | reject-stale | applied |
| C033 | 0000MG | Record DATFile/Error/Win32/CRT dependencies and exact relative includes; no local duplicate type declarations. | Very strong | Compile-closure audit. | UID0000MG dependency inventory | incorporate | applied |
| C034 | 0002Q5 | Preserve sole setter call at `0x4fb60b` after login packet send; login is caller, not owner. | Certain | One target xref. | UID0002Q5/UID0000KX route | already-present | already-present |
| C035 | 00030K | Preserve validator calls `0x477606/0x477612` for article subject/body before sanitization. | Certain | Binary and dated generated source. | UID00030K caller evidence | already-present | already-present |
| C036 | 0003PY | Restore validator calls `0x47de03/0x47de0f` for mail subject/body immediately before sanitization. | Certain | Binary calls absent from dated generated source. | UID0003PY formal CPP/evidence | incorporate | applied |
| C037 | 00047G | Preserve validator call `0x59e480` in party-search source-text submission. | Certain | Binary/generated call. | UID00047G caller evidence | already-present | already-present |
| C038 | 0001KW | Preserve validator call `0x5ae0a0` in spell-string confirmation. | Certain | Binary/generated call. | UID0001KW caller evidence | already-present | already-present |
| C039 | 000401 | Preserve validator call `0x5b1680` in legacy direct-message submit. | Certain | Exact callsite. | UID000401 caller evidence | already-present | already-present |
| C040 | 000403 | Preserve validator call `0x5b1aa0` in modern direct-message submit. | Certain | Exact callsite. | UID000403 caller evidence | already-present | already-present |
| C041 | 0001LZ | Preserve validator call `0x5b1fc0` in group-message submit. | Certain | Exact callsite. | UID0001LZ caller evidence | already-present | already-present |
| C042 | 000406/0000C5 | Replace UID000406's undeclared-helper shorthand with the complete inline constructor/submit body while preserving validator call `0x5b23d0`; make UID0000C5 CPP expand `[[CHILDREN]]`, move the complete class without an explicit derived destructor to H, emit the child at namespace scope, and score `0000C5 87/90 -> 93/94`, `000406 86/90 -> 94/95`. | Certain | Live constructor/submit decompilation, exact callsite, and dated `[[No Children Attached]]` defect. | UID000406 formal CPP/evidence/metadata and UID0000C5 formal CPP/H/metadata | reject-stale | applied |
| C043 | 000416 | Preserve validator call `0x5b36d1` in normal say-chat submit. | Certain | Binary/generated call. | UID000416 caller evidence | already-present | already-present |
| C044 | 0001MC | Preserve validator call `0x5b3aa1` in chat submit. | Certain | Binary/generated call. | UID0001MC caller evidence | already-present | already-present |
| C045 | 0001MF | Preserve validator call `0x5b42b2` in shout submit. | Certain | Binary/generated call. | UID0001MF caller evidence | already-present | already-present |
| C046 | 0002VH | Record complete 13-callsite set, 11 owning definitions, no return consumers, and exact source-root mapping. | Certain | Unpaged target xrefs and caller reads. | UID0002VH callers | incorporate | applied |
| C047 | 0002Q5 | Add `../auth/PasswordGuard.h` before the LoginDialogPane caller definition. | Very strong | Missing generated declaration. | UID0002Q5 formal CPP | incorporate | applied |
| C048 | 00030K | Add `../../auth/PasswordGuard.h` before NewArticle source. | Very strong | Missing generated declaration. | UID00030K formal CPP | incorporate | applied |
| C049 | 0003PY | Add `../../auth/PasswordGuard.h` before NewMail source while preserving all nine bodies. | Very strong | Missing generated declaration. | UID0003PY formal CPP | incorporate | applied |
| C050 | 00047G | Add `../auth/PasswordGuard.h` before PartySearch source. | Very strong | Missing generated declaration. | UID00047G formal CPP | incorporate | applied |
| C051 | 0001KW | Add `../../auth/PasswordGuard.h` before SpellString source. | Very strong | Missing generated declaration. | UID0001KW formal CPP | incorporate | applied |
| C052 | 000099 | Add `../auth/PasswordGuard.h` to the single SayInputPanes preamble before all six callers. | Very strong | Earliest owner preamble. | UID000099 formal CPP | incorporate | applied |
| C053 | 0001MC | Add `../auth/PasswordGuard.h` before ChatInputPane source in Chatting.cpp. | Very strong | Missing generated declaration. | UID0001MC formal CPP | incorporate | applied |
| C054 | 0000MG | Generated PasswordGuard CPP/H must contain two statics, three definitions, three declarations, exact order, includes, no raw/empty marker, and no duplicate. | Very strong | Complete expected output contract. | Gate 2A generated readback | incorporate | applied |
| C055 | 0000KX/0000HT/0000KZ/0000OZ/0000O0/0000N9/0000I5 | Generated consumers must have one effective PasswordGuard declaration route and all 14 calls total (one setter plus 13 validators); SayInputPanes specifically has six guard calls, one UID000406 definition, one UID0000C5 H declaration, and no helper shorthand or `[[No Children Attached]]`. | Certain | Complete caller inventory and clan topology audit. | Gate 2A consumer readback | incorporate | applied |
| C056 | 0000MG | Replace manual by-file coverage row with complete 94% whole-file summary. | Very strong | Current row is 86% and incomplete. | by-file/-coverage-report.md | incorporate | proposed |
| C057 | 0002VG | Replace stale manual memory row that says position 10/C++ blank with source-ready position 30 facts. | Certain | Current target metadata/source. | by-memory/-coverage-report.md | reject-stale | proposed |
| C058 | UID00055E | Insert assigned raw-helper child row between UID0002VG and UID0002VH after callback creation. | Certain | Address order. | by-memory/-coverage-report.md | incorporate | proposed |
| C059 | 0002VH | Replace stale manual memory row that says position 20/C++ blank with corrected position 50 facts. | Certain | Current and proposed source. | by-memory/-coverage-report.md | reject-stale | proposed |
| C060 | 00035L | Replace stale 87% manual seed row with exact source-ready 92% row. | Certain | Target metadata and fresh bytes. | by-memory/-coverage-report.md | reject-stale | proposed |
| C061 | 000290 | Replace stale 86%/position-30/manual-open row with exact source-ready 92%/position-10 row. | Certain | Target metadata and fresh bytes. | by-memory/-coverage-report.md | reject-stale | proposed |
| C062 | 000487/UID00055F | Correct parent string-pool PASS start and insert assigned exact child row under UID00024T in address order. | Certain | True UTF-16 start at 0x612e8c. | by-memory/-coverage-report.md | reject-stale | proposed |
| C063 | 0000A8 | Replace stale 78% medium manual class row with complete 92% Error-owned class/route summary. | Very strong | Current docs and repaired formal route. | by-class/-coverage-report.md | reject-stale | proposed |
| C064 | support | Quote current no-change manual rows for Error, File, DATFile, callers, aggregates, and exclusions; do not change scores merely for dependency sync. | Strong | Read-only comparison. | Section 28/manual coverage | already-present | proposed |
| C065 | 0002VG | I01 pure-rename `sub_4657D0` to `SetProtectedPasswordToken` with complete literal protection/readback. | Very strong | Exact function prestate and no collision. | IDA I01 | incorporate | proposed |
| C066 | 0002VH | I02 pure-rename `sub_465890` to `ValidateChatInputOrThrowPasswordError` with complete literal protection/readback. | Very strong | Exact function prestate and no collision. | IDA I02 | incorporate | proposed |
| C067 | UID00055E | I03 set only regular address comment at `0x465830`; keep no function/name/type/frame and AP absent. | Very strong | Raw code prestate. | IDA I03 | incorporate | proposed |
| C068 | 00035L | I04 pure-rename `word_66D410` to `g_passwordProtectSeed`; preserve item/type/bytes/xrefs/comments. | Very strong | Exact data prestate and no collision. | IDA I04 | incorporate | proposed |
| C069 | 000290 | I05 must literally distinguish `inspect_items` effective resolver name `unk_67A940` from the absent `entity_query(kind:names)` public entry, require the fresh exact successful pure-rename dry-run, then pure-rename only the head to `g_protectedPasswordToken` while preserving physical/semantic shape, comments, boundaries, and all refs. | Strong | Fresh canonical inspect/names/disassembly/collision reads and dry-run `ok:1`. | IDA I05 | incorporate | proposed |
| C070 | UID00055F | I06 must pure-rename public head `aPa_2` to `aPasswordGuardPassEngResourcePath`, then set only AR at `0x612e8c`, while preserving type `const wchar_t[]`, the unnamed `[0x612e90,0x612e94)` item, interior public `aEngStr` item, semantic bytes/hash, one xref, AP absence, alignment, and successor. | Very strong | Fresh canonical inspect/names/disassembly/item/xref reads and dry-run `ok:1`. | IDA I06 | incorporate | proposed |
| C071 | IDA | Execute I01-I06 in order, including I06 rename before I06 AR, with literal prestate/collision/dry-run/mutation/poststate hard stops and one complete final reread proving only two function names, three public data names, and two AR channels changed; any mismatch requires no further mutation and no save. | Certain | Deterministic fresh-current handoff for both disputed data resolvers. | IDA ordered transaction | incorporate | proposed |
| C072 | IDA | Protect every body/data hash, range, byte count, boundary, xref, frame row, and comment channel; preserve the I05 inspect-alias/public-name distinction and every I06 head/interior/alignment/successor item while allowing only the exact proposed head names and AR text. | Certain | Fresh literal items, names, disassembly, comments, bytes, and xrefs. | IDA readback manifest | incorporate | proposed |
| C073 | IDA | Perform no set_type, frame edit, function definition, data shaping, PASS/token range retyping, or interior/successor rename; I06's pure head rename does not create a source static. | Certain | Public rename/comment poststates are sufficient for IDA clarity without physical reshaping. | IDA no-change boundary | not-applicable | proposed |
| C074 | docs | Scoped-validate every changed ordinary destination serially only after callback authorization; record full receipts. | Certain | Workflow requirement. | Validator Results | incorporate | applied |
| C075 | generated | After fresh validator metadata, physically reread PasswordGuard CPP/H, Error CPP/H, File CPP/H, DATFile CPP/H, seven consumer CPPs, and SayInputPanes.h. | Certain | Generated closure requirement. | Gate 2A/Validator Results | incorporate | applied |
| C076 | report | Preserve implementation boundary: ordinary docs changed only through accepted callback and scoped validators; no manual coverage/generated, IDA, audit, or lifecycle mutation. | Certain | Assignment and observed actions. | Changed Files | already-present | already-present |
| C077 | report | Maintain 33 exact headings, 81/81 twin parity, only formal C++/H fences, zero executable fences, and exactly one terminal readiness marker. | Certain | Mechanical report contract. | Whole report | already-present | already-present |
| C078 | report | Keep lifecycle prose neutral; current path plus validator-owned status/history is sole execution/archive authority. | Certain | Workflow lifecycle rule. | Current/Final/Follow-Up | incorporate | applied |
| C079 | history | Preserve all valid prior research and explicitly historicalize contradicted two-function, future-helper, blank-H, ReadLineRaw, blank-C++, and unresolved FatalError assumptions. | Very strong | Current docs versus fresh evidence. | Target/support Changes sections | historicalize | applied |
| C080 | 0000C5 | Replace the stale manual by-class 82% row with the exact proposed 93% class/source-route summary, including UID000406 child emission and compiler-generated destructor disposition. | Certain | Current ordinary metadata and complete formal route repair. | by-class/-coverage-report.md | reject-stale | proposed |
| C081 | 000406 | Insert the missing manual by-memory row after UID0001LZ with the exact proposed 94% constructor/submit, validator-call, inline packet, layout, and repaired owner-route facts. | Certain | Current ordinary page, exact address order, live body, and generated omission audit. | by-memory/-coverage-report.md | incorporate | proposed |

## Positive Evidence Summary

- Three coherent source definitions form one local state machine: setter stores encoded token, decoder returns plaintext to caller storage, validator checks outbound text and throws on disclosure.
- Every seed and token xref is inside those three bodies. No neighboring Application or Error method touches either static.
- The raw helper has two arguments at `[ebp+8]` and `[ebp+0xc]`, a normal frame prologue, a `_wcsncpy_s` call, two return paths, and a destination-pointer return.
- The validator's initial 32-wchar decode is instruction-for-instruction equivalent to the raw helper specialized for count 32, strongly supporting same-TU inlining.
- Thirteen guard callsites cover article/mail text, party-search text, spell input, four direct-message variants, normal say, chat, and shout. This is file-level cross-UI policy, not pane ownership.
- Live UID000406 decompilation proves its clan submit performs the guard, sanitizer, two `WideCharToMultiByte` conversions, opcode `0x19` and two length prefixes, inline copies, unsent terminator, and socket send; no source `SendTargetMessagePacket` helper exists there.
- `PASS_ENG.STR`, DATFile construction/open/read, conversion, append, PasswordError allocation/construction, and C++ throw form one complete throw path.

## IDA MCP Facts

| Entity | Literal current facts |
| --- | --- |
| UID0002VG | `sub_4657D0`, `[0x004657d0,0x00465827)`, 87 bytes, 29 instructions, type `int __cdecl(wchar_t *Source)`, hash `4A39F094D96B94DC500339D35A80ABDA39790F057141B081CDC59C872918A458`, one inbound code xref `0x004fb60b`, sole callee `_wcsncpy_s`, AR/AP/FR/FP absent. |
| Gap G1 | `[0x00465827,0x00465830)`, 9 `cc` bytes, hash `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`. |
| UID00055E | `[0x00465830,0x0046588c)`, 92 bytes, hash `9BD60E8D2DD9C9884BF51BF2832478794893255660D651DB2F66DD500DF72582`, 40 decoded instructions, no function/name/type/frame/inbound xref, AR absent, AP absent, FR not applicable, FP not applicable. |
| Gap G2 | `[0x0046588c,0x00465890)`, 4 `cc` bytes, hash `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`. |
| UID0002VH | `sub_465890`, `[0x00465890,0x00465ae2)`, 594 bytes, 181 instructions, type `__int16 __cdecl(wchar_t *Str)`, hash `B146DDF03BFB7C64FBED4EFA773EA872AEB85E8331479DBE79FE26D7CF0BB363`, 13 inbound code xrefs, AR/AP/FR/FP absent. |
| Gap G3 | `[0x00465ae2,0x00465af0)`, 14 `cc` bytes, hash `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`. |
| UID00035L | Item `[0x0066d410,0x0066d412)`, name `word_66D410`, type absent, bytes `44 d5`, hash `B92E9B004E29713B234C44EF1795D31D18D341C1BF24A5400B18489111364011`, xrefs `0x4657e5`, `0x465866`, `0x4658d2`, AR absent, AP absent. |
| UID000290 | Fresh canonical pre-dry-run `inspect_items` physical head `[0x0067a940,0x0067a941)` has effective resolver name `unk_67A940`, type `wchar_t`, `is_code:false`, `is_data:false`; `entity_query(kind:names)` has no public named entry in the token range. The five exact operands render `unk_67A940`. Semantic `[0x0067a940,0x0067a980)` is 64 zero bytes, hash `F5A5FD42D16A20302798EF6ED309979B43003D2320D9F0E8EA9831A92759FB4B`, with five head refs. Separate `[0x0067a97e,0x0067a97f)` has effective inspect name `unk_67A97E` but no public named entry, type absent, non-code/non-data, and one xref `0x4657ee`; separate successor `[0x0067a980,0x0067a981)` has effective inspect name `unk_67A980` but no public named entry, type absent, and lies outside the token. AR/AP are absent at all three heads. |
| UID00055F | Fresh canonical head `[0x00612e8c,0x00612e90)` is size four, public name `aPa_2`, type `const wchar_t[]`, `is_code:false`, `is_data:true`; `[0x00612e90,0x00612e94)` is unnamed/untyped four-byte data; `[0x00612e94,0x00612ea6)` is 18-byte data with public name `aEngStr` and type absent. Together semantic UTF-16 `[0x00612e8c,0x00612ea6)` is `PASS_ENG.STR` plus NUL, 26 bytes, hash `30D258B7089D410DE374D94245465C8A7C82E45FC852B2687814BA343D7798D2`, with one data xref `0x46592d` whose disassembly is `push offset aPa_2; path`; AR/AP are absent on the physical heads. `[0x00612ea6,0x00612ea8)` is unnamed/untyped two-byte data alignment; successor `[0x00612ea8,0x00612eac)` is `off_612EA8`, type `const WCHAR`, non-code data. |

UID0002VG frame rows are exactly `__saved_registers@0x4/0x4/_DWORD`, `__return_address@0x8/0x4/_UNKNOWN *`, and `Source@0xc/0x4/wchar_t *`.

UID0002VH frame rows are exactly: `var_AC4@0xc/0x14/DATFile`; `Block@0x20/0x4/void *`; `pExceptionObject@0x24/0x4/_DWORD`; `Destination@0x28/0x2/wchar_t`; `var_AA6@0x2a/0x1/_BYTE`; `var_2AA@0x826/0x2/_WORD`; `WideCharStr@0x828/0x2/WCHAR`; `MultiByteStr@0x9b8/0xc8/CHAR[200]`; `SubStr@0xa80/0x2/wchar_t`; `var_12@0xabe/0x2/_WORD`; `var_10@0xac0/0x4/_DWORD`; `var_C@0xac4/0x4/_DWORD`; `var_4@0xacc/0x4/_DWORD`; `__saved_registers@0xad0/0x4/_DWORD`; `__return_address@0xad4/0x4/_UNKNOWN *`; `Str@0xad8/0x4/wchar_t *`; `arg_4@0xadc/0x4/int`.

## Function / Child Inventory

| Item | Kind | Owner/emitter/source position | CPP disposition | H disposition |
| --- | --- | --- | --- | --- |
| UID000290 `[0x67a940,0x67a980)` | file static buffer | UID0000MG / `10` | Exact static plus include preamble. | Blank; private storage. |
| UID00035L `[0x66d410,0x66d412)` | initialized file static | UID0000MG / `20` | Exact initialized static. | Blank; private storage. |
| UID0002VG `[0x4657d0,0x465827)` | setter definition | UID0000MG / `30` | Exact body. | Sole complete PasswordGuard H owner. |
| UID00055E `[0x465830,0x46588c)` | raw decoder definition | New exact child -> UID0000MG / `40` | Exact body. | Blank; declaration centralized in UID0002VG H. |
| UID0002VH `[0x465890,0x465ae2)` | throwing guard definition | UID0000MG / `50` | Corrected exact body. | Blank; declaration centralized in UID0002VG H. |
| UID00055F `[0x612e8c,0x612ea6)` | source literal | New exact child -> UID0000MG / `60` | Covered-by marker only; literal appears in UID0002VH. | Blank; no declaration. |
| G1/G2/G3 | alignment/padding | no owner/emitter | Blank. | Blank. |
| UID0000YS | mixed aggregate | non-emitting inventory | Blank. | Blank. |
| UID0002VI | Application fatal helper | UID0000HG | Excluded; existing Application source. | Excluded. |
| UID0002VJ/VK/VL | PasswordError source/compiler support | UID0000A8 -> UID0000J5 | Constructor/name emit through repaired child route; wrapper compiler-only. | Declaration centralized in UID00004J H. |
| UID0002NE/UID00047X | PasswordError vtable/literal | UID0000A8/Error | Compiler/source-use covered. | Covered by class declaration. |
| UID00004V/UID00003G | File/DATFile declarations | UID0000JB/UID0000IN | Owner includes plus children. | Complete support H blocks. |
| UID0000C5/UID000406 | clan-message caller topology | UID0000N9 | UID0000C5 CPP expands children; UID000406 complete inline constructor/submit definitions emit at namespace scope with the guard call preserved and no invented packet helper. | UID0000C5 owns the complete declaration; UID000406 H stays blank. |

Complete count: 3 PasswordGuard authored definitions, 2 PasswordGuard file statics, 1 PasswordGuard source literal, 3 internal padding spans, 1 non-emitting mixed aggregate, 4 Error-class method/compiler items, 2 Error data items, 2 direct declaration dependencies, and 2 clan-caller topology support items. No PasswordGuard class, object layout, vtable, RTTI, thunk, jump table, enum, resource table, or additional state exists.

## Direct Xref / Caller Inventory

| Exact site(s) or range | File-owned subject | Relationship / target | Evidence-backed disposition |
| --- | --- | --- | --- |
| `0x004fb60b` | UID0002VG setter | Sole inbound code xref from UID0002Q5 `SendLoginRequest`, generated in UID0000KX `login/LoginDialogPane.cpp`; inbound data xrefs are zero. | The call was already present at dated pre-callback inspection; current implemented output preserves it and contains the PasswordGuard H include. |
| `[0x004657d0,0x00465827)` | UID0002VG setter | Sole direct callee `_wcsncpy_s`; no other callee. | Source uses the normal bounded copy followed by local terminator/XOR logic; no invented helper or ABI call is emitted. |
| `0x00465830` | UID00055E decoder | Inbound code xrefs zero; inbound data xrefs zero; no retained direct caller. | Keep the complete externally retained helper because UID0002VH contains its instruction-equivalent fixed-size specialization; zero xrefs do not make the body dead or padding. |
| `0x00465852` | UID00055E decoder | Sole direct callee `_wcsncpy_s`. | Source emits one bounded copy on the positive-count path; the zero-count path calls nothing. |
| `0x00477606`, `0x00477612` | UID0002VH validator | Inbound calls from UID00030K `NewArticleDialogCore`, generated in UID0000HT `ui/dialogs/BoardDialogs.cpp`. | Calls were present before callback; current output preserves both and contains the required include. |
| `0x0047de03`, `0x0047de0f` | UID0002VH validator | Inbound calls from UID0003PY `NewMailDialogCore`, generated in UID0000KZ `ui/dialogs/MailDialogs.cpp`. | Both calls and the include were absent from dated pre-callback output; current output contains both and the required include. |
| `0x0059e480` | UID0002VH validator | Inbound call from UID00047G `PartySearchEditPaneOnAction`, generated in UID0000OZ `social/UserListDialogPane.cpp`. | Current output preserves the call and contains the required include. |
| `0x005ae0a0` | UID0002VH validator | Inbound call from UID0001KW `SpellStringInputPaneConfirmInput`, generated in UID0000O0 `ui/dialogs/SpellInputPanes.cpp`. | Current output preserves the call and contains the required include. |
| `0x005b1680` | UID0002VH validator | Inbound call from UID000401 legacy direct-message submit in UID0000N9 `social/SayInputPanes.cpp`. | Current output preserves the call and receives the declaration through the centralized UID000099 preamble. |
| `0x005b1aa0` | UID0002VH validator | Inbound call from UID000403 modern direct-message submit in UID0000N9. | Current output preserves the call and receives the declaration through the centralized UID000099 preamble. |
| `0x005b1fc0` | UID0002VH validator | Inbound call from UID0001LZ group-message submit in UID0000N9. | Current output preserves the call and receives the declaration through the centralized UID000099 preamble. |
| `0x005b23d0` | UID0002VH validator | Inbound call from UID000406 clan-message submit in UID0000N9. | Dated pre-callback output had shorthand/missing-child defects; current output preserves this call in the complete inline packet body and has no shorthand or empty-child marker. |
| `0x005b36d1` | UID0002VH validator | Inbound call from UID000416 normal-say submit in UID0000N9. | Current output preserves the call and receives the declaration through the centralized UID000099 preamble. |
| `0x005b3aa1` | UID0002VH validator | Inbound call from UID0001MC chat submit, generated in UID0000I5 `social/Chatting.cpp`. | Current output preserves the call and contains the required include. |
| `0x005b42b2` | UID0002VH validator | Inbound call from UID0001MF shout submit in UID0000N9 `social/SayInputPanes.cpp`. | Current output preserves the call and contains the centralized include. |
| `[0x00465890,0x00465ae2)` | UID0002VH validator | Inbound data xrefs zero; the 13 code callsites above are exhaustive. | Preserve shared PasswordGuard ownership; no caller pane owns the validator. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 1/12 | `_wcsncpy_s`. | Binary contains fixed-size decoder lowering; source calls UID00055E instead of duplicating that helper body. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 2/12 | `_wcsstr`. | Source emits `wcsstr(text, decodedPassword)`. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 3/12 | `DATFile__Constructor` at `0x0049c130`. | Source uses a concrete local `DATFile` object. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 4/12 | `DATFile_Open` at `0x0049c180`. | Source opens UID00055F `PASS_ENG.STR` through the canonical DATFile API. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 5/12 | `_memset`. | Source uses ordinary zero initialization for message and decoded buffers. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 6/12 | `DATFile_ReadLineChars` at `0x0049c370`. | Source uses canonical `ReadLineChars(char *, int)`, not stale `ReadLineRaw`. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 7/12 | `_wcsncat_s`. | Source appends each converted line with normal `wcsncat_s`. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 8/12 | `@__security_check_cookie@4`. | Compiler lowering only; no handwritten source call. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 9/12 | `___report_rangecheckfailure`. | Compiler range-check lowering only; natural indexed source is retained. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 10/12 | `NexusTK_operator_new`. | Source emits ordinary `new PasswordError(...)`. |
| `0x00465abe` | UID0002VH direct callee 11/12 | UID0002VJ `sub_467160`, source `PasswordError::PasswordError(const wchar_t *)`. | Constructor emits through Error; PasswordGuard remains allocation/throw consumer. |
| `[0x00465890,0x00465ae2)` | UID0002VH direct callee 12/12 | `__CxxThrowException@8`. | Source emits an ordinary C++ pointer throw, not the ABI helper. |
| Two indirect callsites in `[0x00465890,0x00465ae2)` | UID0002VH indirect API target | `MultiByteToWideChar`. | Source preserves two normal Win32 conversions in the DAT line loop. |
| `0x004657db`, `0x004657f7`, `0x004657fe`, `0x0046584b`, `0x004658c5` | UID000290 token head `[0x0067a940,0x0067a980)` | Exhaustive five token-head refs from setter, decoder, and validator. | All refs are PasswordGuard-local; no external data owner exists. |
| `0x004657ee` | UID000290 final word `0x0067a97e` | Sole forced-terminator ref to the separate final-word head. | Preserve index-31 NUL semantics inside the same 32-wchar static. |
| `0x004633db`, `0x00466b3c`, `0x00466d3f`, `0x00466e95` | UID000290 successor boundary `0x0067a980` | Refs target the successor/global, not the token range. | Exclude them from the token xref set and do not widen UID000290 beyond `0x0067a980`. |
| `0x004657e5`, `0x00465866`, `0x004658d2` | UID00035L seed `[0x0066d410,0x0066d412)` | Exhaustive setter/decoder/validator seed refs. | All refs are PasswordGuard-local; no non-PasswordGuard owner route is supported. |
| `0x0046592d` | UID00055F literal `[0x00612e8c,0x00612ea6)` | Sole data xref to UTF-16 `PASS_ENG.STR`; there is no second use. | Source spells the literal at the DATFile open site; no standalone string table emits. |
| `[0x00465827,0x00465830)` | G1 padding | Nine `cc` bytes, hash `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; code/data xrefs zero. | No owner/emitter and blank CPP/H; exact separator between setter and decoder. |
| `[0x0046588c,0x00465890)` | G2 padding | Four `cc` bytes, hash `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`; code/data xrefs zero. | No owner/emitter and blank CPP/H; exact separator between decoder and validator. |
| `[0x00465ae2,0x00465af0)` | G3 padding | Fourteen `cc` bytes, hash `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; code/data xrefs zero. | No owner/emitter and blank CPP/H; exact post-validator boundary before excluded code. |

This table is the complete file-owned function/data/padding relationship inventory: one setter caller and sole callee, decoder zero-xref disposition and sole callee, all 13 validator callers, all 12 direct validator callees plus the two indirect `MultiByteToWideChar` calls, every token/terminator/seed/literal xref and successor exclusion, and all three padding negative-xref dispositions. Source emits normal C++ and Win32/CRT calls, not compiler ABI helpers.

## Documentation Evidence And IDA Status

- At dated pre-callback inspection UID0000MG correctly owned the guard but still presented the historical two-function inventory, future-helper placeholder, and folder-open blocker as active defects. Current implemented ordinary/generated output has the complete two statics, three definitions, three declarations, exact raw-child and literal-child routes, required includes, and no future-helper or folder-open blocker.
- UID0002VG, UID00035L, and UID000290 have valid source bodies/declarations and strong evidence; their manual coverage rows are stale.
- UID0002VH's owner/signature direction was valid at dated pre-callback inspection, but its then-formal body and stale `ReadLineRaw` wording contradicted MCP evidence. Current implemented ordinary/generated output uses the corrected complete guard body, canonical `DATFile::ReadLineChars`, and the repaired declaration/include route; no active `ReadLineRaw` dependency remains.
- UID0000YS and UID000275 were valid non-emitting mixed inventories at dated pre-callback inspection, but the exact raw child route was then missing. Current implemented documentation retains both aggregate/split histories without merging and routes the exact decoder through assigned child UID00055E.
- The 2026-08-17 callback text in UID0000MG and UID0000YS transcribed all three padding hashes incorrectly while retaining the correct ranges, lengths, and `cc` bytes. This bounded repair corrects all six ordinary-page occurrences to the raw-byte values already recorded in Section 13; commands `000000025808` and `000000025809` scoped-validated the two corrected pages with `ok:1`.
- At dated pre-callback inspection UID000487 recorded only the interior `_ENG.STR` view at `0x612e94`, omitting the true PasswordGuard literal start at `0x612e8c`. Current implemented documentation records the exact `PASS_ENG.STR` literal through assigned child UID00055F and preserves the corrected source route.
- UID0000A8's dated pre-callback active marker suppressed its exact PasswordError children, while UID00004J was already the correct declaration owner. Current implemented ordinary/generated Error output uses the repaired child route, emits the constructor/name support, retains UID00004J as declaration owner, and has no empty-child marker.
- UID000406's dated pre-callback source preserved the constructor shape and validator call but abbreviated the inline packet body as undeclared `SendTargetMessagePacket`; UID0000C5 then had a missing children route and misplaced CPP declaration. Current implemented ordinary/generated output contains the complete conversion, length-prefix serialization, copy, terminator, and send body inside the `0x005b2390` definition, the complete `SayInputPanes.h` declaration, `[[CHILDREN]]` CPP route, namespace-scope UID000406 definitions, no explicit derived destructor, no shorthand helper, and no empty-child marker.
- IDA remains unchanged. Section 21 recommends exactly two pure function renames, three pure data-head renames, and two regular address comments; all type/frame/function-definition/data-shaping actions are intentionally excluded.

## Ranked Ownership Analysis

1. UID0000MG PasswordGuard: accepted. It alone owns both statics and all three guard behaviors, bridges login to outbound text policy, and already has the generated route.
2. UID0000J5 Error / UID0000A8 PasswordError: dependency only. It owns exception class ABI and message/name behavior, not token state or policy.
3. UID0000IN DATFile: dependency only. It supplies resource stream semantics, not guard policy.
4. Login/chat/dialog source roots: callers only. No single caller covers the 13-site policy fanout.
5. UID0000HG Application / UID0002VI FatalError: rejected. Adjacency comes from a mixed physical island, while state and callers are disjoint.

## Source Placement

- Keep exact staged path `NexusTK/auth/PasswordGuard.cpp` and add `PasswordGuard.h` beside it. The auth folder best captures login credential capture and policy reuse by UI callers.
- Source order is dependency-driven and address-consistent: includes/token/seed/setter/decoder/validator. The PASS literal is represented inside validator source; its exact data child emits only a coverage marker after source definitions.
- Header exports three free functions. Neither static is declared in H. Error and DATFile declarations remain in their owning headers.
- Consumer includes are relative to each generated translation unit and occur before the first call in that unit.
- `SayInputPanes.h` places UID0000C5's complete `SayToClanMessageInputPane` declaration after `SayToGroupMessageInputPane` and before UID0000C6 `SayToUserMessageInputPane`; UID0000C5 CPP contributes only `[[CHILDREN]]`, so UID000406 definitions remain namespace-scope source.

## Range / Split / Padding / Reclassification Analysis

- Exact authored code ranges are `[0x4657d0,0x465827)`, `[0x465830,0x46588c)`, and `[0x465890,0x465ae2)`. No function overlaps or tail sharing exists.
- Exact internal padding is 9, 4, and 14 bytes, all `0xcc`; no by-memory code child or C++ belongs there.
- `[0x465af0,0x465b6f)` writes separate global dynamic wide storage; `0x465b70`, `0x465b90`, and `0x465bb0` are separate Application/object helpers. They establish the successor boundary and are excluded.
- UID00035L is exactly two bytes; UID00035O owns `[0x66d412,0x66d414)` padding. UID000290 ends before Application timing state at `0x67a980`.
- UID00055F is the semantic 26-byte UTF-16 literal `[0x612e8c,0x612ea6)`; `[0x612ea6,0x612ea8)` is alignment and `0x612ea8` begins the separate `Aborted` literal used by UID0002VI.
- UID0000YS and UID000487 remain broad non-duplicating inventories with exact nested child routes; do not shrink them destructively or emit aggregate source.

## Negative Evidence Summary

- No inbound xref does not make UID00055E dead: the body is complete and its fixed-size specialization is present in UID0002VH.
- No source evidence supports a PasswordGuard class, namespace object, token wrapper type, static data table for PASS text, or Error ownership.
- No caller reads UID0002VG or UID0002VH return values; decompiler integer/short returns are incidental.
- No safe need exists to define UID00055E as an IDA function, set target types, reshape the token array, or retype the PASS range. I06's supported pure rename changes only the low-quality public head `aPa_2` to a descriptive IDA label and does not create a source static, alter the interior `aEngStr` item, or change physical data.
- `ReadLineRaw`, explicit `_invalid_parameter_noinfo_noreturn`, unconditional decoded-token clearing, and testing the first line before conversion are rejected as current source.
- No live call or callee supports UID000406's shorthand `SendTargetMessagePacket`; `0x005b2390` contains the conversions, copies, packet assembly, terminator, and send inline.
- FatalError's `Aborted` dialog/post-quit/debug-break route and all PasswordError vtable/RTTI mechanics remain outside PasswordGuard source.

## IDA Rename / Type / Comment Recommendations

Channel vocabulary is literal: AR = regular address comment; AP = repeatable address comment; FR = regular function comment; FP = repeatable function comment. Gate 2B must freshly enumerate and runtime-attest the canonical session, then execute I01-I06 in order, with I06's rename preceding its AR action. Dated session names are evidence only and must not be reused by assumption. The fresh supervisor preflight used canonical session `supervisor_uid0000hf_postdiscard_20260818`, runtime-attested `ok:true` at `2026-08-18T04:16:59.143673+00:00`; B001 re-enumerated and independently re-attested the same canonical session `ok:true` at `2026-08-18T04:21:23.725258+00:00`. The canonical path was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, and physical disk identity was SHA256 `8742915867D2D6DBC728AEA295DC830F9C5FE1CEA66099D532EF8EE6163D274E`, 143,210,685 bytes. Fresh public reads confirmed every I01-I04 literal prestate without drift and produced the corrected I05/I06 states below. Neither preflight nor B001 reanalysis performed mutation, backup, save, or process action; the only endpoint requests during reanalysis were the exact `dry_run:true` receipts in I05 and I06.

### I01 - Pure Function Rename At 0x004657d0

- Classification: apply.
- Endpoint: `rename` with `pure:true`.
- Literal prestate: name `sub_4657D0`; declaration `int __cdecl(wchar_t *Source)`; function `[0x004657d0,0x00465827)`, 87 bytes, SHA256 `4A39F094D96B94DC500339D35A80ABDA39790F057141B081CDC59C872918A458`; frame `__saved_registers@0x4/0x4/_DWORD`, `__return_address@0x8/0x4/_UNKNOWN *`, `Source@0xc/0x4/wchar_t *`; AR absent; AP absent; FR absent; FP absent; one inbound code xref `0x004fb60b` from `sub_4FB2D0 [0x004fb2d0,0x004fb62a)`; no inbound data xref; sole callee `_wcsncpy_s`; destination name `SetProtectedPasswordToken` has no collision.
- Exact request: `{"database":"<fresh runtime-attested canonical session ID>","batch":{"func":{"addr":"0x004657d0","name":"SetProtectedPasswordToken"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Expected immediate poststate: name `SetProtectedPasswordToken`; declaration, all three frame rows, AR absent, AP absent, FR absent, FP absent, range, size, body bytes/hash, one inbound code xref, zero inbound data xrefs, and sole callee unchanged.
- Hard stop: if any literal prestate/collision check differs, the mutation response is not one success, or immediate poststate differs, stop with no further mutation and no save.

### I02 - Pure Function Rename At 0x00465890

- Classification: apply.
- Ordered staged prestate: I01 already reads name `SetProtectedPasswordToken` with every protected I01 field unchanged. I02 remains name `sub_465890` and the complete literal state below.
- Endpoint: `rename` with `pure:true`.
- Literal I02 prestate: declaration `__int16 __cdecl(wchar_t *Str)`; function `[0x00465890,0x00465ae2)`, 594 bytes, SHA256 `B146DDF03BFB7C64FBED4EFA773EA872AEB85E8331479DBE79FE26D7CF0BB363`; AR absent; AP absent; FR absent; FP absent. Frame rows are exactly `var_AC4@0xc/0x14/DATFile`; `Block@0x20/0x4/void *`; `pExceptionObject@0x24/0x4/_DWORD`; `Destination@0x28/0x2/wchar_t`; `var_AA6@0x2a/0x1/_BYTE`; `var_2AA@0x826/0x2/_WORD`; `WideCharStr@0x828/0x2/WCHAR`; `MultiByteStr@0x9b8/0xc8/CHAR[200]`; `SubStr@0xa80/0x2/wchar_t`; `var_12@0xabe/0x2/_WORD`; `var_10@0xac0/0x4/_DWORD`; `var_C@0xac4/0x4/_DWORD`; `var_4@0xacc/0x4/_DWORD`; `__saved_registers@0xad0/0x4/_DWORD`; `__return_address@0xad4/0x4/_UNKNOWN *`; `Str@0xad8/0x4/wchar_t *`; `arg_4@0xadc/0x4/int`.
- Literal xrefs/callees: inbound code xrefs exactly `0x477606`, `0x477612`, `0x47de03`, `0x47de0f`, `0x59e480`, `0x5ae0a0`, `0x5b1680`, `0x5b1aa0`, `0x5b1fc0`, `0x5b23d0`, `0x5b36d1`, `0x5b3aa1`, `0x5b42b2`; zero inbound data xrefs. Direct callees exactly `_wcsncpy_s`, `_wcsstr`, `DATFile__Constructor`, `DATFile_Open`, `_memset`, `DATFile_ReadLineChars`, `_wcsncat_s`, `@__security_check_cookie@4`, `___report_rangecheckfailure`, `NexusTK_operator_new`, `sub_467160`, and `__CxxThrowException@8`; disassembly retains the two indirect `MultiByteToWideChar` calls. Destination name has no collision.
- Exact request: `{"database":"<fresh runtime-attested canonical session ID>","batch":{"func":{"addr":"0x00465890","name":"ValidateChatInputOrThrowPasswordError"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Expected immediate poststate: name `ValidateChatInputOrThrowPasswordError`; declaration, all 17 frame rows, AR absent, AP absent, FR absent, FP absent, range, size, body bytes/hash, all 13 code xrefs, zero data xrefs, and full callee set unchanged. I01 remains at its accepted poststate.
- Hard stop: any literal mismatch, collision, mutation error, or readback difference requires no further mutation and no save.

### I03 - Regular Address Comment At 0x00465830

- Classification: apply.
- Ordered staged prestate: I01 and I02 names are their proposed names with all protected fields unchanged. Item `[0x00465830,0x00465831)` is one-byte decoded code with name absent and type absent; there is no function, no frame, and no inbound xref. Semantic body `[0x00465830,0x0046588c)` is 92 bytes, 40 instructions, SHA256 `9BD60E8D2DD9C9884BF51BF2832478794893255660D651DB2F66DD500DF72582`; AR absent; AP absent; FR not applicable; FP not applicable. The body renders automatic token alias `unk_67A940` at `0x46584b`, references `word_66D410` at `0x465866`, and calls `_wcsncpy_s` at `0x465852`.
- Endpoint: `set_address_comments`.
- Exact request: `{"database":"<fresh runtime-attested canonical session ID>","items":{"addr":"0x00465830","comment":"PasswordGuard GetProtectedPasswordToken source helper; copies and XOR-decodes the protected token into caller storage."}}`.
- Expected immediate poststate: AR is exactly the proposed text; AP absent; FR not applicable; FP not applicable; item name absent; item type absent; no function; no frame; no inbound xref; semantic range/size/instructions/bytes/hash/references unchanged. I01/I02 remain at accepted poststates.
- Hard stop: any prestate, endpoint response, or poststate mismatch requires no further mutation and no save.

### I04 - Pure Seed Data Rename At 0x0066d410

- Classification: apply.
- Ordered staged prestate: I01/I02 names and I03 AR equal their proposed poststates. Seed item is exactly `[0x0066d410,0x0066d412)`, name `word_66D410`, type absent, data item true, bytes `44 d5`, SHA256 `B92E9B004E29713B234C44EF1795D31D18D341C1BF24A5400B18489111364011`; AR absent; AP absent; xrefs exactly `0x4657e5`, `0x465866`, `0x4658d2`; destination name has no collision.
- Endpoint: `rename` with `pure:true`.
- Exact request: `{"database":"<fresh runtime-attested canonical session ID>","batch":{"data":{"old":"word_66D410","new":"g_passwordProtectSeed"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Expected immediate poststate: name `g_passwordProtectSeed`; type absent; exact item/range/bytes/hash; AR absent; AP absent; all three xrefs unchanged. I01-I03 remain at accepted poststates.
- Hard stop: any literal prestate/collision, response, or poststate mismatch requires no further mutation and no save.

### I05 - Pure Token-Head Data Rename At 0x0067a940

- Classification: apply.
- Ordered staged prestate: I01-I04 equal their complete proposed poststates. Before any dry-run, `inspect_items(0x0067a940)` must return physical head `[0x0067a940,0x0067a941)`, effective name `unk_67A940`, type `wchar_t`, `is_code:false`, `is_data:false`; independently, `entity_query(kind:names)` must return no public named entry anywhere in `[0x0067a940,0x0067a981)`. In the current public schema these are two literal, non-conflicting fields: `inspect_items.name` is the effective display/resolver token accepted by `rename.batch.data.old`, while `entity_query(kind:names)` enumerates public named entries. This observed endpoint contract, not a cache exception, binds the transaction. Exact operands render `unk_67A940` at `0x4657db`, `0x4657f7`, `0x4657fe`, `0x46584b`, and `0x4658c5`. Semantic token `[0x0067a940,0x0067a980)` is 64 zero bytes, SHA256 `F5A5FD42D16A20302798EF6ED309979B43003D2320D9F0E8EA9831A92759FB4B`, with those exact five head xrefs. Separate one-byte terminator head `[0x0067a97e,0x0067a97f)` has effective inspect name `unk_67A97E`, no public named entry, type absent, `is_code:false`, `is_data:false`, and sole xref `0x4657ee`; separate successor head `[0x0067a980,0x0067a981)` has effective inspect name `unk_67A980`, no public named entry, type absent, `is_code:false`, `is_data:false`, lies outside the token, and has exact xrefs `0x4633db`, `0x466b3c`, `0x466d3f`, `0x466e95`. AR absent and AP absent at all three heads. Destination `g_protectedPasswordToken` has no public or effective-name collision.
- Fresh read-only resolution receipt: exact request `{"database":"supervisor_uid0000hf_postdiscard_20260818","batch":{"data":{"old":"unk_67A940","new":"g_protectedPasswordToken"},"pure":true,"allow_overwrite":false,"dry_run":true,"stop_on_error":true}}` returned `{"data":[{"addr":"0x67a940","old":"unk_67A940","new":"g_protectedPasswordToken","dry_run":true}],"summary":{"total":1,"ok":1,"failed":0,"stopped":false,"dry_run":true,"stop_on_error":true}}`. Immediate reread still returned effective inspect names `unk_67A940`, `unk_67A97E`, and `unk_67A980`; no public named entry in the range; no destination collision; unchanged absent comments; unchanged five head, one terminator, and four successor xrefs. The dry-run therefore resolves the exact effective alias without mutating public-name state or any protected field.
- Endpoint: `rename` with `pure:true`.
- Exact request: `{"database":"<fresh runtime-attested canonical session ID>","batch":{"data":{"old":"unk_67A940","new":"g_protectedPasswordToken"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Expected immediate poststate: `inspect_items.name` and `entity_query(kind:names)` both report `g_protectedPasswordToken` at head `0x0067a940`; head type remains `wchar_t`, `is_code:false`, `is_data:false`; physical and semantic item shapes, 64 bytes/hash, AR absent, AP absent, all five head xrefs, separate effective `unk_67A97E` terminator head with absent public name/type and its one xref, and separate effective `unk_67A980` successor with absent public name/type and its four xrefs remain unchanged. All five token operand renderings resolve to `g_protectedPasswordToken`; I01-I04 remain at accepted poststates.
- Hard stop: require the complete literal `inspect_items` effective-name and `entity_query(kind:names)` public-name prestate above, absent destination collision, and a fresh dry-run with exactly `total:1`, `ok:1`, `failed:0`, `stopped:false`, `dry_run:true` resolving address `0x67a940`. If any prestate differs, the real mutation response is not one success, either immediate name view differs from the proposed head name, or any protected field differs, stop with no further mutation and no save.

### I06 - Pure PASS Head Rename Then Regular Address Comment At 0x00612e8c

- Classification: apply.
- Ordered staged prestate: I01-I05 equal their complete proposed poststates. `inspect_items(0x00612e8c)` and public-name enumeration must return physical head `[0x00612e8c,0x00612e90)`, size `0x4`, public name `aPa_2`, type `const wchar_t[]`, `is_code:false`, `is_data:true`. Physical item `[0x00612e90,0x00612e94)` is size `0x4`, name absent, type absent, `is_code:false`, `is_data:true`. Physical item `[0x00612e94,0x00612ea6)` is size `0x12`, public name `aEngStr`, type absent, `is_code:false`, `is_data:true`. Together semantic literal `[0x00612e8c,0x00612ea6)` is 26 bytes for `PASS_ENG.STR` plus NUL, SHA256 `30D258B7089D410DE374D94245465C8A7C82E45FC852B2687814BA343D7798D2`; its sole inbound data xref is `0x46592d`, whose exact disassembly is `push offset aPa_2; path`. AR absent and AP absent at `0x612e8c`, `0x612e90`, and `0x612e94`. Separate alignment item `[0x00612ea6,0x00612ea8)` is two zero bytes, name absent, type absent, `is_code:false`, `is_data:true`, AR absent, AP absent, and has zero xrefs. Separate successor item `[0x00612ea8,0x00612eac)` is size `0x4`, effective inspect name `off_612EA8`, type `const WCHAR`, `is_code:false`, `is_data:true`, AR absent, AP absent, with sole xref `0x465cb5`; it begins the excluded `Aborted` literal. Destination `aPasswordGuardPassEngResourcePath` has no collision.
- Decision and evidence: use a human-quality pure data-head rename followed by the regular address comment. `aPa_2` is a real public name but is a truncated automatic-looking label that does not identify the exact PasswordGuard resource path. The exact bytes, sole guard xref, source-use child, collision absence, and successful resolver dry-run support `aPasswordGuardPassEngResourcePath`. Comment-only is weaker because it leaves the poor public operand label; no-change is weaker because the item is already safely and precisely nameable. This IDA label does not imply a standalone source static; formal source continues to use `L"PASS_ENG.STR"` at the callsite.
- Fresh read-only resolution receipt: exact request `{"database":"supervisor_uid0000hf_postdiscard_20260818","batch":{"data":{"old":"aPa_2","new":"aPasswordGuardPassEngResourcePath"},"pure":true,"allow_overwrite":false,"dry_run":true,"stop_on_error":true}}` returned `{"data":[{"addr":"0x612e8c","old":"aPa_2","new":"aPasswordGuardPassEngResourcePath","dry_run":true}],"summary":{"total":1,"ok":1,"failed":0,"stopped":false,"dry_run":true,"stop_on_error":true}}`. Immediate reread retained `aPa_2`, `const wchar_t[]`, `aEngStr`, all item boundaries/classifications, absent comments, exact xref/disassembly, and absent destination collision; the dry-run made no mutation.
- First endpoint: `rename` with `pure:true`. Exact request: `{"database":"<fresh runtime-attested canonical session ID>","batch":{"data":{"old":"aPa_2","new":"aPasswordGuardPassEngResourcePath"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Expected post-rename/pre-comment state: head name is `aPasswordGuardPassEngResourcePath` in both inspect and public-name views; type remains `const wchar_t[]`; AR absent; AP absent; exact disassembly becomes `push offset aPasswordGuardPassEngResourcePath; path`. The unnamed `[0x612e90,0x612e94)` item, public `aEngStr` item, semantic bytes/hash, sole xref, alignment item, and `off_612EA8` successor remain literal prestate-exact. I01-I05 remain at accepted poststates.
- Second endpoint: `set_address_comments`. Exact request: `{"database":"<fresh runtime-attested canonical session ID>","items":{"addr":"0x00612e8c","comment":"PasswordGuard PASS_ENG.STR warning-message resource path; source-covered by ValidateChatInputOrThrowPasswordError."}}`.
- Expected immediate poststate: AR at `0x00612e8c` is exactly the proposed text; AP absent; head name remains `aPasswordGuardPassEngResourcePath`; type remains `const wchar_t[]`; exact disassembly remains `push offset aPasswordGuardPassEngResourcePath; path`; all three semantic-literal physical items, semantic range/bytes/hash, sole xref, internal comments, two-byte alignment item, and `off_612EA8` successor item remain unchanged. I01-I05 remain at accepted poststates.
- Hard stop: require the complete literal item/name/type/comment/xref prestate, absent destination collision, and a fresh dry-run with exactly `total:1`, `ok:1`, `failed:0`, `stopped:false`, `dry_run:true` resolving address `0x612e8c`. If any prestate differs, the rename response is not one success, the post-rename readback differs, the comment response is not one success, or any final protected field differs, stop with no further mutation and no save.

### Ordered Final Readback

After I06, reread all six entities together and prove the only changes are two function names, three public data names, and two AR channels. AP on both commented addresses remains absent; AR/AP/FR/FP on both functions remain absent; function declarations/frames/ranges/hashes/xrefs/callees remain exact; raw helper remains no-function/no-frame. Seed becomes `g_passwordProtectSeed` with item/type/hash/xrefs/comments exact. Token head becomes `g_protectedPasswordToken` while its `wchar_t` one-byte non-code/non-data physical head, 64-byte semantic range/hash, five head xrefs, effective-name/public-name distinction before mutation, separate effective `unk_67A97E` terminator head with absent public name/type and one xref, and effective `unk_67A980` successor with absent public name/type and four xrefs remain exact. PASS head becomes `aPasswordGuardPassEngResourcePath`, remains `[0x00612e8c,0x00612e90)` / `const wchar_t[]` / non-code data, and receives only the exact AR; the unnamed `[0x612e90,0x612e94)` item, public `aEngStr` item, semantic range/hash/xref, alignment, and `off_612EA8` successor remain exact. Save only after this complete readback passes. No set_type, define_func, make_data, frame, AP, FR, FP, interior-name, or successor-name action is authorized by this report.

## First-Draft C++ Recommendation

### UID000290 Formal RECONSTRUCTION_CPP CODE - Position 10

```cpp
#include "PasswordGuard.h"
#include "../archive/DATFile.h"
#include "../util/Error.h"
#include <string.h>
#include <wchar.h>
#include <windows.h>

static wchar_t g_protectedPasswordToken[32];
```

UID000290 formal H remains blank because the static is CPP-private.

### UID00035L Formal RECONSTRUCTION_CPP CODE - Position 20

```cpp
static unsigned short g_passwordProtectSeed = 0xd544;
```

UID00035L formal H remains blank because the static is CPP-private.

### UID0002VG Formal RECONSTRUCTION_CPP CODE - Position 30

```cpp
void SetProtectedPasswordToken(const wchar_t *password)
{
    wcsncpy_s(g_protectedPasswordToken, 32, password, 32);
    g_protectedPasswordToken[31] = L'\0';

    unsigned int seed = g_passwordProtectSeed;
    for (wchar_t *scan = g_protectedPasswordToken;
         *scan != L'\0';
         ++scan, ++seed)
    {
        *scan = static_cast<wchar_t>(*scan ^ seed);
    }
}
```

### UID0002VG Formal RECONSTRUCTION_H CODE - Sole PasswordGuard Header Owner

```h
#ifndef NEXUSTK_AUTH_PASSWORD_GUARD_H
#define NEXUSTK_AUTH_PASSWORD_GUARD_H

#include <stddef.h>

void SetProtectedPasswordToken(const wchar_t *password);
wchar_t *GetProtectedPasswordToken(
    wchar_t *destination,
    size_t destinationChars);
void ValidateChatInputOrThrowPasswordError(const wchar_t *text);

#endif
```

### UID00055E Formal RECONSTRUCTION_CPP CODE - Position 40

```cpp
wchar_t *GetProtectedPasswordToken(
    wchar_t *destination,
    size_t destinationChars)
{
    if (destinationChars == 0)
    {
        destination[0] = L'\0';
        return destination;
    }

    wcsncpy_s(
        destination,
        destinationChars,
        g_protectedPasswordToken,
        destinationChars);
    destination[destinationChars - 1] = L'\0';

    unsigned int seed = g_passwordProtectSeed;
    for (wchar_t *scan = destination;
         *scan != L'\0';
         ++scan, ++seed)
    {
        *scan = static_cast<wchar_t>(*scan ^ seed);
    }

    return destination;
}
```

UID00055E formal H remains blank because UID0002VG owns the complete header.

### UID0002VH Formal RECONSTRUCTION_CPP CODE - Position 50

```cpp
void ValidateChatInputOrThrowPasswordError(const wchar_t *text)
{
    wchar_t decodedPassword[32];
    GetProtectedPasswordToken(decodedPassword, 32);

    if (text != NULL)
    {
        if (wcsstr(text, decodedPassword) != NULL)
        {
            DATFile passwordMessageFile;
            passwordMessageFile.Open(L"PASS_ENG.STR");

            wchar_t message[1024];
            memset(message, 0, sizeof(message));

            char line[200];
            wchar_t wideLine[200];
            for (;;)
            {
                int lineLength =
                    passwordMessageFile.ReadLineChars(line, 200);
                line[lineLength] = '\0';

                int wideChars = MultiByteToWideChar(
                    CP_ACP, 0, line, -1, wideLine, 199);
                wideLine[wideChars] = L'\0';

                if (lineLength <= 1)
                    break;

                wcsncat_s(message, 1024, wideLine, 200);
            }

            message[1023] = L'\0';
            throw new PasswordError(message);
        }

        memset(decodedPassword, 0, sizeof(decodedPassword));
    }
}
```

UID0002VH formal H remains blank because UID0002VG owns the complete header.

### UID00055F Formal RECONSTRUCTION_CPP CODE - Position 60

```cpp
// The exact PASS_ENG.STR data is source-covered by the literal in
// ValidateChatInputOrThrowPasswordError; no standalone table is emitted.
```

UID00055F formal H remains blank because a source-use literal requires no declaration.

### UID00004J Formal RECONSTRUCTION_H CODE - Complete Error Header Replacement

```h
#ifndef NEXUSTK_UTIL_ERROR_H
#define NEXUSTK_UTIL_ERROR_H

#include "LObject.h"
#include <stddef.h>
#include <windows.h>

class Error : public LObject
{
public:
    virtual ~Error()
    {
    }

    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const = 0;
    virtual const wchar_t *GetErrorName() const;
};

class MyError : public Error
{
public:
    MyError(const wchar_t *message);
    virtual ~MyError();

    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    wchar_t *m_messageText;
};

class PasswordError : public MyError
{
public:
    PasswordError(const wchar_t *message);
    virtual const wchar_t *GetErrorName() const;
};

class Win32Error : public Error
{
public:
    Win32Error();
    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    DWORD m_errorCode;
};

typedef char ErrorSizeMustBe0x4[
    sizeof(Error) == 0x4 ? 1 : -1];
typedef char MyErrorSizeMustBe0x8[
    sizeof(MyError) == 0x8 ? 1 : -1];
typedef char PasswordErrorSizeMustBe0x8[
    sizeof(PasswordError) == 0x8 ? 1 : -1];
typedef char Win32ErrorSizeMustBe0x8[
    sizeof(Win32Error) == 0x8 ? 1 : -1];

#endif
```

### UID0000A8 Formal RECONSTRUCTION_CPP CODE - Child Route Repair

```cpp
[[CHILDREN]]
```

UID0000A8 formal H remains blank because UID00004J is the sole coordinated Error.h owner.

### UID00004V Formal RECONSTRUCTION_CPP CODE - File Owner Route

```cpp
#include "File.h"

[[CHILDREN]]
```

### UID00004V Formal RECONSTRUCTION_H CODE - Complete File Declaration

```h
#ifndef NEXUSTK_UTIL_FILE_H
#define NEXUSTK_UTIL_FILE_H

#include "LObject.h"
#include "StringBase.h"
#include <stddef.h>

typedef mystr::StringBase<char, mystr::mychar_traits<char> > StringBaseA;
typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;

class File : public LObject
{
public:
    virtual ~File()
    {
    }

    virtual void Open(const wchar_t *path) = 0;
    virtual bool Close() = 0;
    virtual int GetPosition() = 0;
    virtual bool Seek(int offset, int origin) = 0;
    virtual int GetSize() = 0;
    virtual size_t Read(void *buffer, int count) = 0;
    virtual bool ReadLine(StringBaseA &line) = 0;
    virtual int ReadLineChars(char *buffer, int limit) = 0;

    StringBaseA ReadString(int count);
    bool ReadLine(StringBaseW &line);
};

#endif
```

### UID00003G Formal RECONSTRUCTION_CPP CODE - DATFile Owner Route

```cpp
#include "DATFile.h"

[[CHILDREN]]
```

### UID00003G Formal RECONSTRUCTION_H CODE - Complete DATFile Declaration

```h
#ifndef NEXUSTK_ARCHIVE_DAT_FILE_H
#define NEXUSTK_ARCHIVE_DAT_FILE_H

#include "../util/File.h"

class DATFile : public File
{
public:
    DATFile();
    virtual ~DATFile();

    virtual void Open(const wchar_t *path);
    virtual bool Close();
    virtual int GetPosition();
    virtual bool Seek(int offset, int origin);
    virtual int GetSize();
    virtual size_t Read(void *buffer, int count);
    virtual bool ReadLine(StringBaseA &line);
    virtual int ReadLineChars(char *buffer, int limit);

    int ReadEncodedTableInt(int *outValue);
    int ReadEncodedTableFloat(float *outValue);

private:
    void *m_archive;
    const unsigned char *m_entry;
    int m_position;
    int m_size;
};

typedef char DATFileSizeMustBe0x14[
    sizeof(DATFile) == 0x14 ? 1 : -1];

char *__stdcall LoadDatFileBuffer(
    const wchar_t *path, int prefixSize, int *outSize);

#endif
```

### UID0002Q5 Formal RECONSTRUCTION_CPP CODE Preamble Insertion

```cpp
#include "../auth/PasswordGuard.h"
```

### UID00030K Formal RECONSTRUCTION_CPP CODE Preamble Insertion

```cpp
#include "../../auth/PasswordGuard.h"
```

### UID0003PY Formal RECONSTRUCTION_CPP CODE - Include And Complete SendMail Replacement

```cpp
#include "../../auth/PasswordGuard.h"

int NewMailDialog::SendMail(short)
{
    wchar_t recipient[256];
    wchar_t subject[256];
    wchar_t body[4096];
    GetTextEditValue(3, recipient, 256);
    GetTextEditValue(4, subject, 256);
    GetTextEditValue(5, body, 4096);

    ValidateChatInputOrThrowPasswordError(subject);
    ValidateChatInputOrThrowPasswordError(body);
    FilterAsciiAlphaNumeric(recipient);
    SanitizeMailText(subject);
    SanitizeMailText(body);

    char recipientText[256];
    char subjectText[256];
    char bodyText[4096];
    const int recipientLength =
        WideTextToPacketText(recipient, recipientText, sizeof(recipientText));
    const int subjectLength =
        WideTextToPacketText(subject, subjectText, sizeof(subjectText));
    const int bodyLength =
        WideTextToPacketText(body, bodyText, sizeof(bodyText));

    const int packetLength =
        2 + 2 + 1 + recipientLength + 1 + subjectLength +
        2 + bodyLength + 1;
    if (packetLength >= 0x7fff)
        return 0;

    unsigned char packet[0x8000];
    unsigned char *out = packet;
    PacketBufferWriteUInt8(0x3b, out);
    PacketBufferWriteUInt8(0x06, out);
    PacketBufferWriteUInt16BE(m_session->GetMailListId(), out);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(recipientLength), out);
    PacketBufferWriteBytes(recipientText, recipientLength, out);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(subjectLength), out);
    PacketBufferWriteBytes(subjectText, subjectLength, out);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(bodyLength), out);
    PacketBufferWriteBytes(bodyText, bodyLength, out);
    PacketBufferWriteUInt8(IsControlChecked(6) ? 1 : 0, out);

    const int result =
        QueueAndSendPacket(g_packetSender, packet, packetLength);
    StartTimer(15000);
    return result;
}
```

All other UID0003PY formal bodies remain byte-for-byte/source-detail preserved around this replacement.

### UID00047G Formal RECONSTRUCTION_CPP CODE Preamble Insertion

```cpp
#include "../auth/PasswordGuard.h"
```

### UID0001KW Formal RECONSTRUCTION_CPP CODE Preamble Insertion

```cpp
#include "../../auth/PasswordGuard.h"
```

### UID000099 Formal RECONSTRUCTION_CPP CODE Preamble Replacement

```cpp
#include "../auth/PasswordGuard.h"
#include "../ui/core/BlackHole.h"
#include "SayInputPanes.h"

[[CHILDREN]]
```

### UID0000C5 Formal RECONSTRUCTION_CPP CODE Replacement

At UID0000C5's existing source-order position in `NexusTK/social/SayInputPanes.cpp`, replace the CPP-resident class shell with the child expansion below. UID000406 then emits its already-complete constructor and `OnSubmitInput` definitions at namespace scope; its formal H remains blank because UID0000C5 owns the declaration.

```cpp
[[CHILDREN]]
```

### UID0000C5 Formal RECONSTRUCTION_H CODE Replacement

Insert this complete declaration in `NexusTK/social/SayInputPanes.h` after `SayToGroupMessageInputPane` and before UID0000C6 `SayToUserMessageInputPane`. Omit the stale explicit derived-destructor declaration: the inherited virtual destructor is the narrow source cause of the observed compiler-generated wrapper, matching the accepted UID0000C6 sibling pattern.

```h
class SayToClanMessageInputPane : public LineInputPane
{
public:
    explicit SayToClanMessageInputPane(const wchar_t *clanName);

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_clanName[128]; // +0x108
};
```

### UID000406 Formal RECONSTRUCTION_CPP CODE Replacement

Replace the abbreviated `SendTargetMessagePacket` call with this complete inline constructor/submit source at namespace scope under UID0000C5. It preserves the exact two-buffer conversion, 300-byte packet, opcode/length-prefix order, compiler-lowered checked indices, validator-before-sanitizer order, and final unsent terminator. UID000406 formal H remains blank because UID0000C5 owns the complete class declaration.

```cpp
SayToClanMessageInputPane::SayToClanMessageInputPane(
    const wchar_t *clanName)
    : LineInputPane(0)
{
    wcscpy_s(m_clanName, _countof(m_clanName), clanName);
    SetPromptText(L"Clan => ");
}

void SayToClanMessageInputPane::OnSubmitInput()
{
    if (TextLength() <= 0)
        return;

    wchar_t messageText[256];
    char convertedText[256];
    unsigned char packet[300];

    CopyText(messageText, 255);
    ValidateChatInputOrThrowPasswordError(messageText);
    SanitizeWideTextForChat(messageText, wcslen(messageText));

    int packetLength = 0;
    PacketBufferWriteUInt8(0x19, packet + packetLength++);

    const unsigned int clanNameLength = WideCharToMultiByte(
        CP_ACP, 0, m_clanName,
        static_cast<int>(wcslen(m_clanName)),
        convertedText, sizeof(convertedText), 0, 0);
    convertedText[clanNameLength] = '\0';
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(clanNameLength),
        packet + packetLength++);
    memcpy(packet + packetLength, convertedText, clanNameLength);
    packetLength += clanNameLength;

    const unsigned int messageLength = WideCharToMultiByte(
        CP_ACP, 0, messageText,
        static_cast<int>(wcslen(messageText)),
        convertedText, sizeof(convertedText), 0, 0);
    convertedText[messageLength] = '\0';
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(messageLength),
        packet + packetLength++);
    memcpy(packet + packetLength, convertedText, messageLength);
    packetLength += messageLength;

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength));
}
```

### UID0001MC Formal RECONSTRUCTION_CPP CODE Preamble Insertion

```cpp
#include "../auth/PasswordGuard.h"
```

## Final Recommendation

Submit this callback-complete, padding-hash-corrected, current-schema I05/I06-repaired exact report for fresh mechanical Gate 1 before any new Gate 2B attempt. Ordinary claims C001-C055 and callback mechanics C074-C079 remain implemented and verified at report-level detail; UID00055E/UID00055F are assigned, UID0000C5/UID000406 is repaired, the six stale G1/G2/G3 hash occurrences are corrected in the only two affected ordinary pages, every changed page has a scoped validator receipt, and all named generated outputs have dated physical readbacks. The prior exact artifact passed all 61 B001-owned Gate 2A claims; this report-only prestate repair preserves those accepted ordinary artifacts. Dated generated and MCP identities are receipts rather than continuing authority and must be reread dynamically at later lifecycle actions.

The supervisor owns manual coverage reconciliation, I01-I06 Gate 2B mutation/readback/save, report execution/archive, and exact archived-artifact audit. Those are role dispositions, not assertions about current lifecycle state.

## Recommended Target Doc Changes

For `by-file/PasswordGuard.md` UID0000MG:

- Implemented metadata is `94/95`; owner `FILE` and path `NexusTK/auth/` are retained.
- The complete inventory now contains all three definitions, two statics, exact PASS literal, three gaps, Error/DATFile dependencies, and positions `10/20/30/40/50/60`.
- Exact MCP ranges, sizes, hashes, frames, xrefs, callers/callees, raw-helper behavior/liveness, PASS boundary, and adjacent exclusions are incorporated.
- The target's G1/G2/G3 inventory now uses the corrected raw hashes `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`, `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`, and `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; command `000000025808` scoped-validated the correction.
- Original-folder-open, helper-future, two-function-only, unresolved FatalError, blank-H, and generated-complete assumptions are explicitly historicalized.
- Dated generated readback proves the complete sibling H/declarations/includes, restored NewMail/clan calls, and absence of raw names, empty markers, and duplicates.

## Recommended Support Doc Changes

The following accepted support-document changes were implemented and scoped-validated during this callback; the table retains the accepted destination-specific payload rather than describing unperformed work.

| Destination | Exact accepted change |
| --- | --- |
| UID0002VG setter / `by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md` | Score `93/95`, preserve exact behavior/evidence, keep CPP body from Section 22, own complete PasswordGuard H, position `30`. |
| UID00055E raw child / `by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md` | Implemented exact `[0x465830,0x46588c)` page at `93/95`, owner/emitter UID0000MG, position `40`, complete behavior/hash/inlining history/formal CPP, centralized blank-H rationale. |
| UID0002VH validator / `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md` | Score `94/95`, position `50`, replace stale formal body exactly, preserve all 13 callers/frame/callees and historical assumptions. |
| UID00035L seed / `by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md` | Score `92/95`, preserve exact two bytes/xrefs/static and position `20`. |
| UID000290 token / `by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md` | Score `92/95`, preserve exact semantic range/physical-item caveat/xrefs/static and position `10`; add include preamble. |
| UID00055F literal child / `by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md` | Implemented exact `[0x612e8c,0x612ea6)` page at `92/95`, owner/emitter UID0000MG, position `60`, source-covered marker, exact bytes/hash/xref/boundaries. |
| UID0000YS aggregate / `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md` | Add UID00055E, the full exclusion map, and exact gaps G1/G2/G3 with corrected hashes `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`, `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`, and `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; remain non-emitting/ignored with score unchanged. |
| UID000487 string pool / `by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md` | Correct true `PASS_ENG.STR` start, route exact UID00055F child to PasswordGuard, preserve remaining mixed literals and score. |
| UID00004J Error / `by-class/Error.md` | Preserve all existing declaration/source detail; add exact PasswordError declaration/size assertion from Section 22, score unchanged. |
| UID0000A8 PasswordError / `by-class/PasswordError.md` | Score `92/95`; CPP becomes child expansion, H stays blank under UID00004J, preserve constructor/wrapper/name/vtable/descriptor evidence. |
| UID0002VJ/VK/VL / `by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md`; `by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md`; `by-memory/0x00467400-0x00467406.PasswordErrorGetErrorDescriptor.md` | Verify existing formal bodies/marker and emit through repaired class route; scores unchanged. |
| UID00004V File / `by-class/File.md` | Move existing complete declaration into formal H and use owner include/children CPP, preserving every method/layout/vtable/history fact and score. |
| UID00003G DATFile / `by-class/DATFile.md` | Add exact complete declaration/owner include route, use `ReadLineChars`, preserve all layout/method/vtable/history facts and score. |
| UID0002Q5 / `by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md` | Add exact PasswordGuard include before source; preserve entire login body and score. |
| UID00030K / `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md` | Add exact PasswordGuard include; preserve both current validator calls and all other source/detail/score. |
| UID0003PY / `by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md` | Add exact include and complete corrected SendMail body; preserve all other nine-body source/detail and score. |
| UID00047G / `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md` | Add exact include; preserve current validator call, complete body/detail, and score. |
| UID0001KW / `by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md` | Add exact include; preserve current validator call, complete body/detail, and score. |
| UID000099 / `by-class/NewSayToUserMessageInputPane.md` | Replace preamble exactly to centralize one SayInputPanes include before all six family callers; preserve H/class/children and score. |
| UID0000C5 / `by-class/SayToPlanMessageInputPane.md` | Move the complete `SayToClanMessageInputPane` declaration from CPP to formal H at the exact Section 22 position, remove the stale explicit derived destructor, make formal CPP exactly `[[CHILDREN]]`, preserve all plan/clan history/evidence, and score `87/90 -> 93/94`. |
| UID000406 / `by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md` | Replace the undeclared-helper shorthand with Section 22's complete inline constructor/submit CPP including the exact validator call, conversions, opcode `0x19` packet, compiler-lowered checks, and send; retain blank formal H, emit through UID0000C5 at namespace scope, and score `86/90 -> 94/95`. |
| UID0001MC / `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md` | Add exact include before ChatInputPane source; preserve current validator call, source/detail, and score. |
| UID0002VI / `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md`; UID000275 / `by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md` | Verify-only no-change: preserve Application/mixed split and scores; B001 does not move source. |

## Score And Metadata Recommendation

| UID/item | Historical pre-callback | Implemented | Rationale |
| --- | ---: | ---: | --- |
| 0000MG | 86/90 | 94/95 | Complete source family, source/H, callers, dependencies, gaps, and generated contract; names/path remain inferred. |
| 0002VG | 90/92 | 93/95 | Exact body plus sole complete H ownership. |
| 00055E | new | 93/95 | Exact full body and strong inlining/liveness inference; original name/linkage not recovered. |
| 0002VH | 88/90 | 94/95 | Exact corrected body, full frame/call/callee/resource/throw evidence. |
| 00035L | 88/91 | 92/95 | Exact value, width, ownership, source static, and all xrefs. |
| 000290 | 88/91 | 92/95 | Exact semantic range, bytes, all refs, source static, and boundary. |
| 00055F | new | 92/95 | Exact bytes/string/xref/source-use; physical item is partial. |
| 0000A8 | 86/90 | 92/95 | Complete declaration and functioning child route; broader Error hierarchy remains separate. |
| 0000C5 | 87/90 | 93/94 | Complete class H, compiler-generated destructor disposition, functioning child route, and retained plan/clan naming evidence. |
| 000406 | 86/90 | 94/95 | Exact constructor/submit ranges, complete inline body, validator call, packet layout, and repaired emission; spelling retains minor historical uncertainty. |
| 0000YS/000275/000487/00004J/00004V/00003G/callers | existing | unchanged | Inventory/declaration/include synchronization does not justify unrelated score movement. |

No proposed score reaches `95/95`; the formal source is substantially accurate, but original symbols and exact historical filename/linkage remain inference caps.

## Open Questions With Attempted Resolution

- Original raw-helper name: no symbol/source/PDB survives. Paired setter semantics, destination return, and header role make `GetProtectedPasswordToken` the highest-probability human name; rejected alternatives are `sub_465830`, `DecodeRaw`, and anonymous dead code.
- External versus static helper: zero calls alone favors static/dead, but retained out-of-line code under optimization and an inlined same-TU specialization favor external linkage. Header declaration is therefore recommended with strong, not certain, confidence.
- Exact source path/name: repository source tree and current owner route support `auth/PasswordGuard`; caller spread rejects a chat-only file. No stronger recovered-name evidence was found.
- Token/seed exact original names: no collisions or recovered symbols exist. Existing coordinated names are coherent and source-ready; preserve them rather than invent another alias.
- PASS-head IDA name: current public `aPa_2` is a truncated automatic-looking label, while exact bytes, the sole PasswordGuard xref, source-use ownership, collision absence, and the successful pure dry-run support `aPasswordGuardPassEngResourcePath`. The rename is IDA metadata only and does not promote the source literal into a static; comment-only and no-change dispositions were investigated and rejected as less clear.
- DATFile fields: accepted 0x14 layout and stream API are enough for a complete declaration. Field spellings remain descriptive and do not alter PasswordGuard behavior.
- No irreducible behavioral blocker remains. The remaining uncertainty changes confidence/spelling, not source completeness or owner placement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Do not edit manual coverage in the B callback. Supervisor-owned exact replacements follow.

- Replace `by-file/-coverage-report.md` UID0000MG row with: `- [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md) : reconstructable : 94% : very-strong : Complete NexusTK/auth PasswordGuard.cpp/.h source root with exact 32-wchar protected-token static, 0xd544 seed, setter, externally retained caller-buffer decoder, throwing outbound-text validator, PASS_ENG.STR source literal, three padding spans, one login setter caller, thirteen board/mail/social validator calls, complete Error/DATFile declarations and consumer include routes, corrected NewMail calls, and explicit Application/FatalError/Error-class exclusions.`
- Replace `by-memory/-coverage-report.md` UID0002VG row with: `        - [UID:0002VG][0x004657d0-0x00465827.SetProtectedPasswordToken](by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md) 0x004657d0-0x00465827 | function | SetProtectedPasswordToken : reconstructable : 93% : very-strong : Exact source-ready PasswordGuard setter at position 30; copies 32 wide chars, forces index 31 to NUL, XOR-obfuscates with incrementing 0xd544 seed, has sole login caller and sole _wcsncpy_s callee, and centrally owns complete PasswordGuard.h declarations.`
- Insert assigned UID00055E immediately after UID0002VG: `        - [UID:00055E][0x00465830-0x0046588c.GetProtectedPasswordTokenRaw](by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md) 0x00465830-0x0046588c | raw source helper | GetProtectedPasswordToken : reconstructable : 93% : very-strong : Exact 92-byte caller-buffer protected-token copy/decode helper at PasswordGuard position 40; two-argument ABI, zero-count return path, positive-count forced tail NUL, incrementing XOR decode, destination return, and fixed-size inlining into the validator resolve the prior zero-xref/raw blocker.`
- Replace UID0002VH row with: `        - [UID:0002VH][0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md) 0x00465890-0x00465ae2 | function | ValidateChatInputOrThrowPasswordError : reconstructable : 94% : very-strong : Exact source-ready PasswordGuard guard at position 50; obtains the decoded token, checks wide outbound text, reads and converts PASS_ENG.STR lines through DATFile::ReadLineChars, throws PasswordError on disclosure, conditionally clears the decoded stack copy, and has thirteen exact board/mail/social callers.`
- Replace UID00035L row with: `        - [UID:00035L][0x0066d410-0x0066d412.PasswordGuardXorSeed](by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md) 0x0066d410-0x0066d412 | initialized global data | PasswordGuardXorSeed : reconstructable : 92% : very-strong : Exact writable PasswordGuard file static g_passwordProtectSeed initialized to 0xd544 at position 20; bytes 44 d5 and all three xrefs are confined to setter/decoder/validator XOR loops.`
- Replace UID000290 row with: `    - [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md) 0x0067a940-0x0067a980 | password guard buffer | PasswordGuardProtectedToken : reconstructable : 92% : very-strong : Exact zero-initialized 32-wchar PasswordGuard file static at position 10 with five token-head refs, one final-word terminator ref, setter/decoder/validator ownership, source-ready declaration, and exact successor boundary at 0x0067a980.`
- In `by-memory/-coverage-report.md`, insert UID000487 as an address-ordered child of UID00024T immediately after UID000481 and immediately before UID00024U, using this complete literal row: `        - [UID:000487][0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData](by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md) 0x00612e54-0x00612f38 | source-use pooled string data | ApplicationPatchAndVersionStringData : reconstructable : 87% : very-strong : Exact mixed Application/PatchPane/PasswordGuard string pool covering .exe, license, error-format, PASS_ENG.STR, continuing-patch, runas, and patcher.exe literals; no canonical owner or standalone table, emitters UID0000HG/UID0000MH, exact nested UID00055F starts at 0x00612e8c while 0x00612e94 is only the historical interior _ENG.STR suffix, and all source-bearing literals route independently.`
- Insert assigned UID00055F immediately below UID000487 and before UID00024U in address order: `        - [UID:00055F][0x00612e8c-0x00612ea6.PasswordGuardPassEngString](by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md) 0x00612e8c-0x00612ea6 | UTF-16 source literal | PasswordGuardPassEngString : reconstructable : 92% : very-strong : Exact PASS_ENG.STR plus NUL, 26 bytes and one validator xref; source-covered by ValidateChatInputOrThrowPasswordError with two-byte alignment and Aborted successor excluded.`
- Replace `by-class/-coverage-report.md` UID0000A8 row with: `- [UID:0000A8][PasswordError](by-class/PasswordError.md) : reconstructable : 92% : very-strong : Complete Error-owned PasswordError : MyError declaration and 0x8 layout with source-ready constructor and GetErrorName children, compiler-generated scalar deleting destructor coverage, exact vtable/descriptor routes, repaired child emission through Error.cpp/Error.h, and PasswordGuard retained only as allocation/throw consumer.`
- Replace `by-class/-coverage-report.md` UID0000C5 row with: `- [UID:0000C5][SayToPlanMessageInputPane](by-class/SayToPlanMessageInputPane.md) : reconstructable : 93% : very-strong : Stable plan-named documentation owner with source-facing SayToClanMessageInputPane declaration in SayInputPanes.h, compiler-generated derived-destructor disposition, m_clanName[128] at +0x108, exact constructor/submit child UID000406, ! and Clan => evidence, opcode 0x19 target-message route, and namespace-scope child emission through CPP [[CHILDREN]].`
- Insert after UID0001LZ in `by-memory/-coverage-report.md`: `    - [UID:000406][0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods](by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md) 0x005b22d0-0x005b2562 | class-method-cluster | SayToClanMessageInputPaneMethods : reconstructable : 94% : very-strong : Exact clan-message constructor, two-byte alignment, and virtual OnSubmitInput cluster with ! and Clan => semantics, m_clanName[128] at +0x108, inline opcode 0x19 target/message packet serialization, exact PasswordGuard validator call 0x005b23d0, vtable-slot liveness, compiler-generated destructor route, complete formal CPP, blank child H, and namespace-scope emission through repaired UID0000C5.`

Exact current no-change rows read and retained: UID00004J Error `90%`, UID00004V File `92%`, UID00003G DATFile `89%`, UID0000YS `87%`, UID0002VI `87%`, UID000275 `88%`, UID0002VJ/VK/VL current rows, UID0002Q5 `90%`, UID00030K `85%`, UID0003PY `94%`, UID00047G `92%`, UID0001KW `80%`, UID000401/000403 `94%`, UID0001LZ `78%`, UID000416 `88%`, UID0001MC/0001MF `78%`. UID0000C5's stale manual row and UID000406's missing manual row are handled by the two exact supervisor-owned payloads above. Generated trackers remain validator-owned and are never manually edited.

## Follow-Up Actions

- B001 callback disposition: ordinary implementation, bounded correction of the six stale G1/G2/G3 hash transcriptions, short leases, serial scoped validation, UID assignment, and dated generated readback are complete; no further ordinary edit is prescribed by this report body.
- Supervisor actors: fresh exact-artifact Gate 1 and Gate 2A audit after this report repair, manual coverage reconciliation, I01-I06 Gate 2B mutation/save audit, report execution/archive, and archived-artifact audit. These are role allocations, not permanent current/pending assertions.
- Dynamic authority rule: generated and lifecycle state must be reread from current files and validator-owned metadata at the action time; dated report snapshots are evidence, not continuing authority.
- Gate 2B dynamic authority rule: enumerate and runtime-attest a fresh canonical session; reproduce I05's exact effective `unk_67A940` inspect alias versus absent public named entry and successful dry-run; reproduce I06's public `aPa_2` / `const wchar_t[]` head, unnamed middle item, public `aEngStr` suffix item, alignment/successor manifest, and successful dry-run before any mutation. Never reuse a dated session by assumption.
- Reassignment is supervisor workflow after complete lifecycle closure; this report makes no claim about B001's future assignment state.

## Confidence

- Behavior/ranges/bytes/callers/callees/ownership: very strong to certain.
- Formal source and declaration closure: very strong.
- Raw helper liveness/linkage and descriptive name: strong.
- Historical original filename/global/function spelling: strong project convention, not symbol certainty.
- Overall recommendation: completion `94`, confidence `95`, with no unresolved behavioral blocker.

## Validator Results

Both report-only I05/I06 Gate 2B contract repairs, including this fresh canonical-prestate and dry-run reconciliation, ran no validator. The earlier bounded ordinary correction ran exactly the two required scoped validators for UID0000MG and UID0000YS; no validator command was run during this report-only repair. The dated read-only MCP receipts remain recorded in Evidence Checked and Section 21 and did not mutate or save IDA.

All commands below ran serially from exact cwd `E:\NTK\GhidraBridge\source-3\project-documentation` using one scoped file target and `--apply --queue-timeout 240`. Every command exited `0`, returned `ok:1`, and reported `generated_refresh: deferred` with the same command ID/timestamp. Generated side effects were validator-owned; B001 did not edit generated output or registry/state files directly.

| Command ID / timestamp | Exact single-line command | Literal warnings/errors | Exact side effects |
| --- | --- | --- | --- |
| `000000025753` / `2026-08-17T19:31:08-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md --apply --queue-timeout 240` | none | Assigned/registered UID00055E, owner/emitter/position/formal route, projected stats/reference state; deferred generated refresh. |
| `000000025754` / `2026-08-17T19:31:15-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md --apply --queue-timeout 240` | none | Assigned/registered UID00055F, owner/emitter/position/formal route, corrected UID0002VI link, projected stats/reference state; deferred generated refresh. |
| `000000025758` / `2026-08-17T19:37:11-04:00` | `python .\tools\validator.py --mode file --file by-file\PasswordGuard.md --apply --queue-timeout 240` | none | Completion/confidence `94/95`; reference additions UID0000HG/00055E/00055F, removals UID0001LZ/0001MF; projected stats; deferred refresh. |
| `000000025760` / `2026-08-17T19:37:18-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004657d0-0x00465827.SetProtectedPasswordToken.md --apply --queue-timeout 240` | none | Completion/confidence `93/95`, autogen formal hash update, UID00055E reference, projected stats; deferred refresh. |
| `000000025761` / `2026-08-17T19:37:32-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md --apply --queue-timeout 240` | none | Completion/confidence `94/95`, position `40 -> 50`, formal hash and UID0002VJ/UID00055E/UID00055F link/reference updates, projected stats; deferred refresh. |
| `000000025762` / `2026-08-17T19:37:46-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0066d410-0x0066d412.PasswordGuardXorSeed.md --apply --queue-timeout 240` | none | Completion/confidence `92/95`, projected stats; deferred refresh. |
| `000000025763` / `2026-08-17T19:38:06-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0067a940-0x0067a980.PasswordGuardProtectedToken.md --apply --queue-timeout 240` | none | Completion/confidence `92/95`, autogen formal hash update, projected stats; deferred refresh. |
| `000000025766` / `2026-08-17T19:39:38-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004657d0-0x00467406.PasswordGuardAndFatalError.md --apply --queue-timeout 240` | none | UID00055E reference and projected stats; deferred refresh. |
| `000000025767` / `2026-08-17T19:39:45-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md --apply --queue-timeout 240` | none | Autogen formal hash plus UID0000MG/UID00055F references and projected stats; deferred refresh. |
| `000000025772` / `2026-08-17T19:41:52-04:00` | `python .\tools\validator.py --mode file --file by-class\Error.md --apply --queue-timeout 240` | none | UID0000A8 reference and projected stats; deferred refresh. |
| `000000025773` / `2026-08-17T19:42:11-04:00` | `python .\tools\validator.py --mode file --file by-class\PasswordError.md --apply --queue-timeout 240` | none | Completion/confidence `92/95`, autogen formal hash, UID00004J reference, projected stats; deferred refresh. |
| `000000025774` / `2026-08-17T19:42:19-04:00` | `python .\tools\validator.py --mode file --file by-class\File.md --apply --queue-timeout 240` | none | Autogen CPP/H formal hash and projected stats; deferred refresh. |
| `000000025776` / `2026-08-17T19:42:31-04:00` | `python .\tools\validator.py --mode file --file by-class\DATFile.md --apply --queue-timeout 240` | `missing_ref_uid 0003B7 by-class/DATFile.md UID reference is not present in validator.ini` repeated five times; no error | Autogen blank-to-block/formal hash update and projected stats; deferred refresh. Warning is pre-existing reference-registry state and did not prevent `ok:1`. |
| `000000025779` / `2026-08-17T19:44:57-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004fb2d0-0x004fb62a.SendLoginRequest.md --apply --queue-timeout 240` | none | Autogen formal hash and projected stats; deferred refresh. |
| `000000025780` / `2026-08-17T19:45:17-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00476c10-0x00477790.NewArticleDialogCore.md --apply --queue-timeout 240` | none | Autogen formal hash and projected stats; deferred refresh. |
| `000000025781` / `2026-08-17T19:45:29-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0047d050-0x0047e033.NewMailDialogCore.md --apply --queue-timeout 240` | `missing_ref_uid 0003O8 by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md UID reference is not present in validator.ini`; no error | Autogen formal hash and projected stats; deferred refresh. |
| `000000025783` / `2026-08-17T19:45:43-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md --apply --queue-timeout 240` | none | Autogen formal hash and projected stats; deferred refresh. |
| `000000025784` / `2026-08-17T19:46:00-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md --apply --queue-timeout 240` | none | Autogen formal hash and projected stats; deferred refresh. |
| `000000025785` / `2026-08-17T19:46:14-04:00` | `python .\tools\validator.py --mode file --file by-class\NewSayToUserMessageInputPane.md --apply --queue-timeout 240` | `missing_ref_uid 0003JQ by-class/NewSayToUserMessageInputPane.md UID reference is not present in validator.ini`; no error | Autogen formal hash and projected stats; deferred refresh. |
| `000000025787` / `2026-08-17T19:46:30-04:00` | `python .\tools\validator.py --mode file --file by-class\SayToPlanMessageInputPane.md --apply --queue-timeout 240` | `missing_ref_uid 000406 by-class/SayToPlanMessageInputPane.md UID reference is not present in validator.ini` repeated four times; no error | Completion/confidence `93/94`, autogen formal hash and projected stats; deferred refresh. UID000406 was registered by the following scoped command. |
| `000000025788` / `2026-08-17T19:46:44-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md --apply --queue-timeout 240` | `missing_ref_uid 0003JM by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md UID reference is not present in validator.ini`; `missing_ref_uid 0003JR by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md UID reference is not present in validator.ini`; no error | Registered existing UID000406 path/owner/emitter/formal state, completion/confidence `94/95`, added four references, projected stats; deferred refresh. |
| `000000025789` / `2026-08-17T19:46:57-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x005b3940-0x005b3bba.ChatInputPane.md --apply --queue-timeout 240` | none | Autogen formal hash and projected stats; deferred refresh. |
| `000000025808` / `2026-08-17T22:36:46-04:00` | `python .\tools\validator.py --mode file --file by-file\PasswordGuard.md --apply --queue-timeout 240` | none | `ok:1`; scanned one file; corrected G1/G2/G3 hashes retained with no metadata/source change; `stats_incremental_noop 0000MG`; projected stats update; `generated_refresh: deferred` under the same command ID/timestamp. |
| `000000025809` / `2026-08-17T22:37:15-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004657d0-0x00467406.PasswordGuardAndFatalError.md --apply --queue-timeout 240` | none | `ok:1`; scanned one file; corrected G1/G2/G3 hashes retained with no metadata/source change; `stats_incremental_noop 0000YS`; projected stats update; `generated_refresh: deferred` under the same command ID/timestamp. |

Dated callback generated readback after validator-owned foreground refresh command `000000025804` at `2026-08-17T19:52:18-04:00`:

| Generated output | SHA256 | Bytes / physical lines | Command metadata |
| --- | --- | ---: | --- |
| `auto-generated/NexusTK/auth/PasswordGuard.cpp` | `02EBAF5EF9C5F73A08BC54D6D061E92ECB99A5919C6790472301CF9E0F3326B3` | 3,455 / 108 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/auth/PasswordGuard.h` | `ED5C707A4878FA72D21761EF0B2C62C27F6E7EDDDA3212291EB2A892B401DC4D` | 741 / 19 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/util/Error.cpp` | `3ABC92F141711CB166E0CDB95D664A4DC77948151813CE64C0AC24A25B9D744F` | 10,058 / 113 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/util/Error.h` | `0377DBD809026F3E018FAAB667ED2764493C9A65B9B6AF7440DFFEA4348AC874` | 1,637 / 70 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/util/File.cpp` | `814EC9987EC02879D0CC7B5E209A4EC101F784AA65B498326905F1475BE6280C` | 1,779 / 46 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/util/File.h` | `AE2DC8DC87C216AC3908976A96E24324D47F8B20499D82A1A6DE4342ABCE7BC4` | 1,156 / 36 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/archive/DATFile.cpp` | `4B964D9ADEF0285DCCCC0A1710D35C6C34DA8EDC5A3B3EEF6EE494D63180E1D5` | 5,026 / 123 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/archive/DATFile.h` | `64AA86D10F6A57D251D2496DD8D13D8548C1D6333F6A7CB7268C1771E0A0AF12` | 1,443 / 48 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/login/LoginDialogPane.cpp` | `54D6D7805DFDA2F7F85D6B32726EFFBCDA278C96489A7E24CB3D212BA8B5C875` | 15,360 / 442 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` | `F0582733DD9B7CB9998E3FA6FD603637A488528CD5FB42191F340EEB9D4123EB` | 19,844 / 417 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/ui/dialogs/MailDialogs.cpp` | `A7A9F7B5530478470A9F7E938736D94FAAB66DB292F5D774B9A593B9E7CD22CD` | 29,820 / 856 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/social/UserListDialogPane.cpp` | `C0ABC3643EA4AD9DD33DB0D6B2EF6967F4B3E4BE6F088A7A410A827F8B31B6B5` | 41,654 / 1,200 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` | `99E3C1D8C822DE7673D520A5B5383A0B2EFFECC80D41AA55E4B69AC0E283689F` | 18,709 / 514 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/social/SayInputPanes.cpp` | `EE586482232F004723888748F7452820BE4427AEC810F8A267BB42B6A0F2703E` | 17,867 / 533 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/social/SayInputPanes.h` | `F2266856527000E1AC5702CC962369A425325135E5831DD2287EC3BF34AFD1FD` | 2,720 / 99 | `000000025804`, `2026-08-17T19:52:18-04:00` |
| `auto-generated/NexusTK/social/Chatting.cpp` | `73FB5A26A15184884BB21D08872F49F60C95867DA007F6AF49036C8E60EAF873` | 81,575 / 2,495 | `000000025804`, `2026-08-17T19:52:18-04:00` |

Physical semantic proof: PasswordGuard CPP contains exactly one token static, one seed static, and one each of the setter/decoder/validator definitions in positions `10/20/30/40/50/60`; its H has exactly three declarations. The seven consumer CPP roots each have one effective PasswordGuard include and together contain one setter plus 13 validator calls: Login `1/0`, Board `0/2`, Mail `0/2`, UserList `0/1`, Spell `0/1`, Say `0/6`, Chatting `0/1`. SayInputPanes has exactly one clan constructor definition, one clan submit definition, one H declaration, zero `SendTargetMessagePacket` shorthand, and zero `[[No Children Attached]]` in the relevant owner/child route. Error has one PasswordError class declaration/size assertion and one constructor plus one actual `GetErrorName` definition; File declaration appears only in H; DATFile H has one `ReadLineChars` and zero `ReadLineRaw`. No named generated target contains a UID0000MG empty marker or raw PasswordGuard IDA identifier. Command `000000025804` is a validator-owned foreground generated refresh, not a B001 scoped-validator invocation. These are dated callback receipts; latest generated authority is reread dynamically at Gate 2A and later lifecycle actions.

No lifecycle, report execution, manual coverage, IDA, or direct generated-file command belongs to B001.

## Changed Files

Ordinary destination identities after scoped validation:

| Classification | Destination | SHA256 | Bytes / physical lines |
| --- | --- | --- | ---: |
| Modified | `by-file/PasswordGuard.md` | `EA44F5AFBD5A9E7230482CE0BB67E966274014ECA22FEDC57E1735DC71F31EC4` | 25,047 / 141 |
| Modified | `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md` | `9D7F5270EA06C7998216B8A4390D58C46E103913D6446ECBCAC44BF83647B3FE` | 35,138 / 180 |
| Modified | `by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md` | `5FFF6F16C192A4C17F548FF1BE76ED57D8607E56037B6FCC86D0BC82555BB8F7` | 12,560 / 129 |
| Created | `by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md` UID00055E | `733E57FA6A29C9D7664A90F62F17382581C7DEA14C6E4FA1360E1A19D1D735CF` | 5,829 / 87 |
| Modified | `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md` | `8B64094202B44DA08E9D282C5803BA4A09A22719FA150BF4C17F48AA3D358CCB` | 18,870 / 179 |
| Modified | `by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md` | `81FE2505820F6ABBB64D9BDEBA5FA4F005F947542FF9F8806D7CFE40C3F8FF5C` | 10,117 / 106 |
| Modified | `by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md` | `3AC5A96389543CFFB03EE3BE7301C519653BCCEFB42D38B1A4AA9BA2B608235E` | 10,027 / 89 |
| Modified | `by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md` | `265535D915BDE9AC96828932EC3C1D4FA13AD8F92BC2062A4EB38AAAEA42C771` | 5,324 / 69 |
| Created | `by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md` UID00055F | `7CCC40306F9872D5FACE09A4DC12A8FC980BEF775528D918F6CAE0AD71E6C188` | 4,012 / 50 |
| Modified | `by-class/Error.md` | `88D9FDCB87F822280167F60F611103731E2A241B40943033308B615BA9DFA601` | 22,854 / 242 |
| Modified | `by-class/PasswordError.md` | `9CE6A556CC0222E0123A7883A6D2F0A9DBCD21D8B14B38E40B72B366D10F545E` | 19,705 / 125 |
| Modified | `by-class/File.md` | `313CD0979EC4E7146487024C21C2F57F9E5CDF952B7EE44D831BA1682A0DF201` | 13,651 / 154 |
| Modified | `by-class/DATFile.md` | `43052EFF0E1722E7B48C2F9C0EDDE550D4F0E70B58AC3BDAFEB5FD556CAF4A8F` | 17,163 / 201 |
| Modified | `by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md` | `6971B04D4DD1BC217D40BB7EC70318A64323646A930CB3A0FBC06637BF5337F7` | 14,255 / 171 |
| Modified | `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md` | `40F8DC090CF5DCDF4F0822D4070D1120CB9D34AF549BC8559CFCA42ED28EA2C1` | 23,843 / 337 |
| Modified | `by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md` | `ACC1D0E21DEF62D3B585EEB5C23B741E242F1030E07AF3812D5409B2D3E15898` | 14,686 / 257 |
| Modified | `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md` | `AFB8C9D6FEAEA012AF8D2E4ABC59C44AE67B71376DEE7BE1D59ECFDF4321A57C` | 12,778 / 177 |
| Modified | `by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md` | `E0EE07C077299312A34824DA0E2F2E43A4485383AFC39D0D96DA04D5A9964A0D` | 16,601 / 171 |
| Modified | `by-class/NewSayToUserMessageInputPane.md` | `BA4DC28224AC99A53F0D09669FD29B3F9C655FC0BB59E4BF144F3CD0E534BBF3` | 15,959 / 126 |
| Modified | `by-class/SayToPlanMessageInputPane.md` | `A2C9DAFF8657D28197339E5F8C16D9E1FA6278FBCE74FFC336378B828AC0BF94` | 14,972 / 125 |
| Modified | `by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md` | `94EBEDFAFE78A1BA7BB458ADAD6D3686DF56463841E232A636E8A1CFF18275CB` | 8,133 / 112 |
| Modified | `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md` | `593068757E6E3851B0371E31C4699054303EC756C3A47E9EB196668E476FCF17` | 27,170 / 265 |
| Modified | `tools/leaser/Agents/Agent-B001/research/0000MG-PasswordGuard-file-source-quality.md` | External final artifact identity is reported after the final write because embedding its SHA256 would be self-referential. | External final receipt |

Classification totals are `Created:2`, `Modified:21` including this report, and `Renamed:0`. The same existing report was updated additively after ordinary implementation, the bounded padding-hash correction, and the subsequent report-only current-schema Gate 2B prestate reconciliation. The present repair edited only this report; all accepted ordinary identities above remain unchanged. Validator-owned projected-stat/generated-refresh side effects are recorded in Section 31. No coverage page, generated file, validator registry/state, shared tracker/audit/catalog, goal/notes, IDA database, MCP/process state, or lifecycle/archive file was edited. Prior ordinary leases were released, the present report lease was released immediately after its write, and the final shared lease report contains no B001 entry. The report's current path plus validator-owned status/history metadata remains the only execution/archive authority.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C001 | 0000MG | Raise score `86/90 -> 94/95`; retain `NexusTK/auth/PasswordGuard.cpp` and add required sibling H. | Very strong | Complete code/data/caller/declaration audit. | UID0000MG metadata/Status | incorporate | applied |
| [x] | C002 | 0000MG | Record exhaustive inventory as three definitions, two file statics, one covered literal, and three internal gaps with exact raw hashes G1 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`, G2 `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`, and G3 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; no class/vtable/RTTI. | Certain | Complete bounded family scan and corrected raw-byte hash audit. | UID0000MG whole-file inventory / `by-file/PasswordGuard.md` | incorporate | applied |
| [x] | C003 | 0000MG | Historicalize dated generated omissions: no H, missing raw helper, incomplete validator, undeclared dependencies, two absent NewMail calls, and one suppressed clan-submit call. | Certain | Command 000000025640 physical readback. | UID0000MG generated-state history | historicalize | applied |
| [x] | C004 | 0000MG | Emit positions token `10`, seed `20`, setter `30`, UID00055E decoder `40`, validator `50`, UID00055F literal marker `60`. | Strong | Address order and dependency order. | UID0000MG source-order table | incorporate | applied |
| [x] | C005 | 0000MG | Keep direct owner/file placement in `auth/PasswordGuard`; reject Error, Application, login, and chat owners. | Very strong | State and caller confinement. | UID0000MG ownership/placement | already-present | already-present |
| [x] | C006 | 0002VG | Own complete guarded PasswordGuard H with all three declarations; other child H blocks stay blank to prevent duplicates. | Very strong | Cross-TU callers and raw external retention. | UID0002VG formal H | incorporate | applied |
| [x] | C007 | 000290 | Add PasswordGuard/DATFile/Error plus CRT/Win32 includes before token static. | Very strong | All emitted identifiers require declarations. | UID000290 formal CPP | incorporate | applied |
| [x] | C008 | 000290 | Preserve exact 32-wchar zero-initialized file static, bytes/hash/xrefs/boundary, and stale-alias history; score `88/91 -> 92/95`. | Certain | 64 bytes and five exact refs. | UID000290 metadata/evidence/formal CPP | incorporate | applied |
| [x] | C009 | 00035L | Preserve writable 16-bit file static initialized `0xd544`, three exact refs, and score `88/91 -> 92/95`. | Certain | Bytes `44 d5`, exact xrefs. | UID00035L metadata/evidence/formal CPP | incorporate | applied |
| [x] | C010 | 0002VG | Preserve exact setter copy, forced index-31 NUL, incrementing XOR, sole caller/callee, and source-void body; score `90/92 -> 93/95`. | Very strong | Exact body/frame/xrefs. | UID0002VG formal CPP/evidence | incorporate | applied |
| [x] | C011 | UID00055E | Create exact child `by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md`; replace label with assigned UID before readiness. | Certain | Complete raw code range and boundaries. | New exact by-memory child | incorporate | applied |
| [x] | C012 | UID00055E | Record zero-count write/return and positive-count copy, forced tail NUL, incrementing XOR decode, destination return, 40 instructions, and exact hash. | Certain | Full disassembly and bytes. | UID00055E behavior/evidence | incorporate | applied |
| [x] | C013 | UID00055E | Resolve zero-xref liveness as externally retained helper whose fixed-size call is inlined into UID0002VH; reject dead/padding classification. | Strong | Exact specialization equivalence. | UID00055E inference/history | reject-stale | applied |
| [x] | C014 | UID00055E | Emit complete decoder CPP at position `40`; H blank because UID0002VG centrally owns the declaration; recommend `93/95`. | Very strong | ABI/source reconstruction. | UID00055E metadata/formal channels | incorporate | applied |
| [x] | C015 | 0002VH | Replace validator with helper call, exact loop order, `ReadLineChars`, natural indexed source, exact conditional clear, and ordinary pointer throw. | Very strong | Full decompile/disassembly/callees. | UID0002VH formal CPP | reject-stale | applied |
| [x] | C016 | 0002VH | Keep source-void contract, move emitter `40 -> 50`, preserve 13 callers and complete stack/callee evidence, score `88/90 -> 94/95`. | Very strong | Caller use and exact frame. | UID0002VH metadata/evidence | incorporate | applied |
| [x] | C017 | UID00055F | Create exact child `by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md`; replace label with assigned UID before readiness. | Certain | Exact UTF-16 range/hash/xref. | New exact by-memory child | incorporate | applied |
| [x] | C018 | UID00055F | Route literal through UID0000MG as covered source use at position `60`; no standalone static and H blank; recommend `92/95`. | Very strong | One use in validator. | UID00055F formal channels/evidence | incorporate | applied |
| [x] | C019 | 0000YS | Record G1 `[0x465827,0x465830)` as nine `cc` bytes/hash `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`, G2 `[0x46588c,0x465890)` as four `cc` bytes/hash `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`, and G3 `[0x465ae2,0x465af0)` as fourteen `cc` bytes/hash `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, with blank CPP/H. | Certain | Exact `cc` byte reads, boundaries, and corrected raw-byte hashes. | `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md` split/padding inventory | incorporate | applied |
| [x] | C020 | 0000YS | Preserve mixed aggregate non-emitting status while adding UID00055E and corrected exact child/source ownership. | Certain | Mixed 34-function island. | UID0000YS inventory/history | incorporate | applied |
| [x] | C021 | 0002VI | Preserve Application ownership for FatalErrorDialogAndBreak; no PasswordGuard source or score change. | Certain | Fatal/application caller fan-in. | UID0002VI no-change support | already-present | already-present |
| [x] | C022 | 0000YS | Exclude `0x465af0`, `0x465b70`, `0x465b90`, `0x465bb0` and later Application functions from PasswordGuard. | Certain | Fresh decompilation and separate state. | UID0000YS exclusion inventory | incorporate | applied |
| [x] | C023 | 0000A8 | Preserve PasswordError as Error-owned class and PasswordGuard as allocation/throw consumer only. | Certain | Constructor/vtable/descriptor routes. | UID0000A8 ownership | already-present | already-present |
| [x] | C024 | 00004J | Add complete PasswordError declaration and 0x8 size assertion to the sole coordinated Error H; keep score unchanged. | Very strong | Generated H omission and exact hierarchy. | UID00004J formal H | incorporate | applied |
| [x] | C025 | 0000A8 | Replace class-level marker with `[[CHILDREN]]` CPP expansion; H remains blank because UID00004J owns declarations; score `86/90 -> 92/95`. | Very strong | Generated Error.cpp omits ready children. | UID0000A8 formal channels/metadata | reject-stale | applied |
| [x] | C026 | 0002VJ | Preserve existing constructor body and emit it through repaired UID0000A8 route; no direct PasswordGuard ownership. | Certain | Base call/vtable store/sole throw caller. | UID0002VJ already-present CPP | already-present | already-present |
| [x] | C027 | 0002VK | Preserve scalar deleting destructor as compiler-generated covered-by support; no handwritten wrapper. | Certain | Vtable-only route and cleanup/delete shape. | UID0002VK no-code evidence | already-present | already-present |
| [x] | C028 | 0002VL | Preserve existing `GetErrorName` definition and emit it through repaired UID0000A8 route. | Certain | Six-byte vtable-only accessor. | UID0002VL already-present CPP | already-present | already-present |
| [x] | C029 | 0002NE/00047X | Preserve vtable/descriptor data as compiler/source-use covered by Error declaration and name method; exclude from PasswordGuard. | Certain | Exact vtable/literal routes. | Error support pages | already-present | already-present |
| [x] | C030 | 00004V | Move the complete File declaration from formal CPP to guarded File H; CPP becomes include plus children; score unchanged. | Very strong | Generated File.h absent. | UID00004V formal CPP/H | incorporate | applied |
| [x] | C031 | 00003G | Add complete 0x14 DATFile declaration to DATFile H and owner include/children CPP route; score unchanged. | Very strong | Exact layout/vtable contract. | UID00003G formal CPP/H | incorporate | applied |
| [x] | C032 | 00003G/0002VH | Use canonical `ReadLineChars(char *, int)` and historicalize stale `ReadLineRaw` wording. | Certain | IDA callee `DATFile_ReadLineChars` and File slot map. | UID00003G and UID0002VH docs/source | reject-stale | applied |
| [x] | C033 | 0000MG | Record DATFile/Error/Win32/CRT dependencies and exact relative includes; no local duplicate type declarations. | Very strong | Compile-closure audit. | UID0000MG dependency inventory | incorporate | applied |
| [x] | C034 | 0002Q5 | Preserve sole setter call at `0x4fb60b` after login packet send; login is caller, not owner. | Certain | One target xref. | UID0002Q5/UID0000KX route | already-present | already-present |
| [x] | C035 | 00030K | Preserve validator calls `0x477606/0x477612` for article subject/body before sanitization. | Certain | Binary and dated generated source. | UID00030K caller evidence | already-present | already-present |
| [x] | C036 | 0003PY | Restore validator calls `0x47de03/0x47de0f` for mail subject/body immediately before sanitization. | Certain | Binary calls absent from dated generated source. | UID0003PY formal CPP/evidence | incorporate | applied |
| [x] | C037 | 00047G | Preserve validator call `0x59e480` in party-search source-text submission. | Certain | Binary/generated call. | UID00047G caller evidence | already-present | already-present |
| [x] | C038 | 0001KW | Preserve validator call `0x5ae0a0` in spell-string confirmation. | Certain | Binary/generated call. | UID0001KW caller evidence | already-present | already-present |
| [x] | C039 | 000401 | Preserve validator call `0x5b1680` in legacy direct-message submit. | Certain | Exact callsite. | UID000401 caller evidence | already-present | already-present |
| [x] | C040 | 000403 | Preserve validator call `0x5b1aa0` in modern direct-message submit. | Certain | Exact callsite. | UID000403 caller evidence | already-present | already-present |
| [x] | C041 | 0001LZ | Preserve validator call `0x5b1fc0` in group-message submit. | Certain | Exact callsite. | UID0001LZ caller evidence | already-present | already-present |
| [x] | C042 | 000406/0000C5 | Replace UID000406's undeclared-helper shorthand with the complete inline constructor/submit body while preserving validator call `0x5b23d0`; make UID0000C5 CPP expand `[[CHILDREN]]`, move the complete class without an explicit derived destructor to H, emit the child at namespace scope, and score `0000C5 87/90 -> 93/94`, `000406 86/90 -> 94/95`. | Certain | Live constructor/submit decompilation, exact callsite, and dated `[[No Children Attached]]` defect. | UID000406 formal CPP/evidence/metadata and UID0000C5 formal CPP/H/metadata | reject-stale | applied |
| [x] | C043 | 000416 | Preserve validator call `0x5b36d1` in normal say-chat submit. | Certain | Binary/generated call. | UID000416 caller evidence | already-present | already-present |
| [x] | C044 | 0001MC | Preserve validator call `0x5b3aa1` in chat submit. | Certain | Binary/generated call. | UID0001MC caller evidence | already-present | already-present |
| [x] | C045 | 0001MF | Preserve validator call `0x5b42b2` in shout submit. | Certain | Binary/generated call. | UID0001MF caller evidence | already-present | already-present |
| [x] | C046 | 0002VH | Record complete 13-callsite set, 11 owning definitions, no return consumers, and exact source-root mapping. | Certain | Unpaged target xrefs and caller reads. | UID0002VH callers | incorporate | applied |
| [x] | C047 | 0002Q5 | Add `../auth/PasswordGuard.h` before the LoginDialogPane caller definition. | Very strong | Missing generated declaration. | UID0002Q5 formal CPP | incorporate | applied |
| [x] | C048 | 00030K | Add `../../auth/PasswordGuard.h` before NewArticle source. | Very strong | Missing generated declaration. | UID00030K formal CPP | incorporate | applied |
| [x] | C049 | 0003PY | Add `../../auth/PasswordGuard.h` before NewMail source while preserving all nine bodies. | Very strong | Missing generated declaration. | UID0003PY formal CPP | incorporate | applied |
| [x] | C050 | 00047G | Add `../auth/PasswordGuard.h` before PartySearch source. | Very strong | Missing generated declaration. | UID00047G formal CPP | incorporate | applied |
| [x] | C051 | 0001KW | Add `../../auth/PasswordGuard.h` before SpellString source. | Very strong | Missing generated declaration. | UID0001KW formal CPP | incorporate | applied |
| [x] | C052 | 000099 | Add `../auth/PasswordGuard.h` to the single SayInputPanes preamble before all six callers. | Very strong | Earliest owner preamble. | UID000099 formal CPP | incorporate | applied |
| [x] | C053 | 0001MC | Add `../auth/PasswordGuard.h` before ChatInputPane source in Chatting.cpp. | Very strong | Missing generated declaration. | UID0001MC formal CPP | incorporate | applied |
| [x] | C054 | 0000MG | Generated PasswordGuard CPP/H must contain two statics, three definitions, three declarations, exact order, includes, no raw/empty marker, and no duplicate. | Very strong | Complete expected output contract. | Gate 2A generated readback | incorporate | applied |
| [x] | C055 | 0000KX/0000HT/0000KZ/0000OZ/0000O0/0000N9/0000I5 | Generated consumers must have one effective PasswordGuard declaration route and all 14 calls total (one setter plus 13 validators); SayInputPanes specifically has six guard calls, one UID000406 definition, one UID0000C5 H declaration, and no helper shorthand or `[[No Children Attached]]`. | Certain | Complete caller inventory and clan topology audit. | Gate 2A consumer readback | incorporate | applied |
| [ ] | C056 | 0000MG | Replace manual by-file coverage row with complete 94% whole-file summary. | Very strong | Current row is 86% and incomplete. | by-file/-coverage-report.md | incorporate | proposed |
| [ ] | C057 | 0002VG | Replace stale manual memory row that says position 10/C++ blank with source-ready position 30 facts. | Certain | Current target metadata/source. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | C058 | UID00055E | Insert assigned raw-helper child row between UID0002VG and UID0002VH after callback creation. | Certain | Address order. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C059 | 0002VH | Replace stale manual memory row that says position 20/C++ blank with corrected position 50 facts. | Certain | Current and proposed source. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | C060 | 00035L | Replace stale 87% manual seed row with exact source-ready 92% row. | Certain | Target metadata and fresh bytes. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | C061 | 000290 | Replace stale 86%/position-30/manual-open row with exact source-ready 92%/position-10 row. | Certain | Target metadata and fresh bytes. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | C062 | 000487/UID00055F | Correct parent string-pool PASS start and insert assigned exact child row under UID00024T in address order. | Certain | True UTF-16 start at 0x612e8c. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | C063 | 0000A8 | Replace stale 78% medium manual class row with complete 92% Error-owned class/route summary. | Very strong | Current docs and repaired formal route. | by-class/-coverage-report.md | reject-stale | proposed |
| [ ] | C064 | support | Quote current no-change manual rows for Error, File, DATFile, callers, aggregates, and exclusions; do not change scores merely for dependency sync. | Strong | Read-only comparison. | Section 28/manual coverage | already-present | proposed |
| [ ] | C065 | 0002VG | I01 pure-rename `sub_4657D0` to `SetProtectedPasswordToken` with complete literal protection/readback. | Very strong | Exact function prestate and no collision. | IDA I01 | incorporate | proposed |
| [ ] | C066 | 0002VH | I02 pure-rename `sub_465890` to `ValidateChatInputOrThrowPasswordError` with complete literal protection/readback. | Very strong | Exact function prestate and no collision. | IDA I02 | incorporate | proposed |
| [ ] | C067 | UID00055E | I03 set only regular address comment at `0x465830`; keep no function/name/type/frame and AP absent. | Very strong | Raw code prestate. | IDA I03 | incorporate | proposed |
| [ ] | C068 | 00035L | I04 pure-rename `word_66D410` to `g_passwordProtectSeed`; preserve item/type/bytes/xrefs/comments. | Very strong | Exact data prestate and no collision. | IDA I04 | incorporate | proposed |
| [ ] | C069 | 000290 | I05 must literally distinguish `inspect_items` effective resolver name `unk_67A940` from the absent `entity_query(kind:names)` public entry, require the fresh exact successful pure-rename dry-run, then pure-rename only the head to `g_protectedPasswordToken` while preserving physical/semantic shape, comments, boundaries, and all refs. | Strong | Fresh canonical inspect/names/disassembly/collision reads and dry-run `ok:1`. | IDA I05 | incorporate | proposed |
| [ ] | C070 | UID00055F | I06 must pure-rename public head `aPa_2` to `aPasswordGuardPassEngResourcePath`, then set only AR at `0x612e8c`, while preserving type `const wchar_t[]`, the unnamed `[0x612e90,0x612e94)` item, interior public `aEngStr` item, semantic bytes/hash, one xref, AP absence, alignment, and successor. | Very strong | Fresh canonical inspect/names/disassembly/item/xref reads and dry-run `ok:1`. | IDA I06 | incorporate | proposed |
| [ ] | C071 | IDA | Execute I01-I06 in order, including I06 rename before I06 AR, with literal prestate/collision/dry-run/mutation/poststate hard stops and one complete final reread proving only two function names, three public data names, and two AR channels changed; any mismatch requires no further mutation and no save. | Certain | Deterministic fresh-current handoff for both disputed data resolvers. | IDA ordered transaction | incorporate | proposed |
| [ ] | C072 | IDA | Protect every body/data hash, range, byte count, boundary, xref, frame row, and comment channel; preserve the I05 inspect-alias/public-name distinction and every I06 head/interior/alignment/successor item while allowing only the exact proposed head names and AR text. | Certain | Fresh literal items, names, disassembly, comments, bytes, and xrefs. | IDA readback manifest | incorporate | proposed |
| [ ] | C073 | IDA | Perform no set_type, frame edit, function definition, data shaping, PASS/token range retyping, or interior/successor rename; I06's pure head rename does not create a source static. | Certain | Public rename/comment poststates are sufficient for IDA clarity without physical reshaping. | IDA no-change boundary | not-applicable | proposed |
| [x] | C074 | docs | Scoped-validate every changed ordinary destination serially only after callback authorization; record full receipts. | Certain | Workflow requirement. | Validator Results | incorporate | applied |
| [x] | C075 | generated | After fresh validator metadata, physically reread PasswordGuard CPP/H, Error CPP/H, File CPP/H, DATFile CPP/H, seven consumer CPPs, and SayInputPanes.h. | Certain | Generated closure requirement. | Gate 2A/Validator Results | incorporate | applied |
| [x] | C076 | report | Preserve implementation boundary: ordinary docs changed only through accepted callback and scoped validators; no manual coverage/generated, IDA, audit, or lifecycle mutation. | Certain | Assignment and observed actions. | Changed Files | already-present | already-present |
| [x] | C077 | report | Maintain 33 exact headings, 81/81 twin parity, only formal C++/H fences, zero executable fences, and exactly one terminal readiness marker. | Certain | Mechanical report contract. | Whole report | already-present | already-present |
| [x] | C078 | report | Keep lifecycle prose neutral; current path plus validator-owned status/history is sole execution/archive authority. | Certain | Workflow lifecycle rule. | Current/Final/Follow-Up | incorporate | applied |
| [x] | C079 | history | Preserve all valid prior research and explicitly historicalize contradicted two-function, future-helper, blank-H, ReadLineRaw, blank-C++, and unresolved FatalError assumptions. | Very strong | Current docs versus fresh evidence. | Target/support Changes sections | historicalize | applied |
| [ ] | C080 | 0000C5 | Replace the stale manual by-class 82% row with the exact proposed 93% class/source-route summary, including UID000406 child emission and compiler-generated destructor disposition. | Certain | Current ordinary metadata and complete formal route repair. | by-class/-coverage-report.md | reject-stale | proposed |
| [ ] | C081 | 000406 | Insert the missing manual by-memory row after UID0001LZ with the exact proposed 94% constructor/submit, validator-call, inline packet, layout, and repaired owner-route facts. | Certain | Current ordinary page, exact address order, live body, and generated omission audit. | by-memory/-coverage-report.md | incorporate | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000025891","destination_path":"executed-b-agent-research/B001/0000MG-PasswordGuard-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0000MG-PasswordGuard-file-source-quality.md","timestamp":"2026-08-18T01:09:02-04:00","uid":"0000MG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
