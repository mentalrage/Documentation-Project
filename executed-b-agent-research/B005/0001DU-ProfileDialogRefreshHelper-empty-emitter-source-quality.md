** TARGET-REPORT-UID:0001DU **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001DU ProfileDialog Refresh Helper Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation and applied ordinary state: [UID:0001DU] is reconstructable and emitting through [UID:0000MR] `ProfileDialog.cpp` as the retained file-local helper `RefreshProfileData`, with exact formal CPP and `93/95` metadata.
- Final disposition: the exact `0x0053fe90-0x0053fe9b` range is one source-authored forwarding helper, not padding, a vtable thunk, an ABI wrapper, or a second copy of the sidecar implementation. It loads `g_activeMapPane` and tail-forwards to a nonvirtual `MapPane::RefreshSelectedProfileData()` member at `0x005063e0`.
- Applied support correction: [UID:0001AS] is not a free `ProfileStorage.cpp` cdecl helper. All three live invocation sites prepare a `MapPane` receiver. UID0001AS now has class owner/emitter [UID:00007Q] `MapPane`; its sole file-local extension table [UID:00027P] and source-generated literal child [UID:0003IV] now route through [UID:0000L3] `MapPane.cpp`; the complete accepted sidecar/JPF/packet behavior is preserved.
- Applied one-definition topology: UID0001DU owns one `static void RefreshProfileData()` definition in `ProfileDialog.cpp`; UID0001AS owns one `void MapPane::RefreshSelectedProfileData()` definition through UID00007Q; UID00027P owns the one file-local extension table in `MapPane.cpp`; UID0003IV is covered by those source literals and does not emit a duplicate data block.
- Confidence: very strong for bytes, bounds, tail-forwarding behavior, active global identity, callee receiver contract, sidecar behavior, and source-module placement; strong for the inferred original helper/member spellings and retained-after-inlining source cause.

## Supporting Research

- This report began as the report-only Gate 1 artifact assigned in `Agent-B005/goal.md`. Supervisor Gate 1 accepted exact SHA `84B3B003FD1590F3A4ED0AD6F0DA78DDB93F0F68824FFCFBE3E1DF7852AF6844`, after which B005 applied the authorized ordinary-document callback. B005 did not mutate coverage, supervisor state, report lifecycle, or IDA; the supervisor subsequently completed and verified Gate 2A, Gate 2B, and manual coverage as recorded below.
- Healthy live IDA MCP session `5a570ede` supplied current read-only function, byte, disassembly, decompile, xref, item, name, type, comment, collision, and UDT evidence. `server_health` returned `status:ok`; the known `auto_analysis_ready:false` state did not prevent bounded live IDB queries.
- Historical report `executed-b-agent-research/B008/0001DT-ProfileDialog-source-quality.md` correctly preserved the exact target boundary and non-merge decision, but its ProfileStorage/free-cdecl conclusion depended on the stale B003 prototype inference.
- Historical report `executed-b-agent-research/B003/0001AS-profile-sidecar-refresh-source-quality.md` supplied extensive valid filesystem, JPF, image-validation, packet, and source-era C++ research. Its free `void __cdecl()` and ProfileStorage ownership inference is superseded because it did not give controlling weight to the receiver prepared by every live call site.
- The complete accepted body already present in UID0001AS is preserved. This report changes source ownership, member signature, and the related table/string route; it does not prune the sidecar behavior or replace it with a short wrapper.

## Target

- Target UID: `0001DU`.
- Additional target UIDs: `none`; every other UID in this report is a support destination, not a co-primary report target.
- Declared-target inventory: [UID:0001DU] `by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md`, exact eleven-byte forwarding helper.
- Target path: `by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md`.
- Source queue/report row: assignment selected the target from `auto-generated/-ag-research-tracker.md` empty emitters and reconstructable not-covered by-memory work.
- Current supervisor classification: Gate-1-accepted ordinary callback complete; supervisor Gate 2A, Gate 2B, manual coverage, and saved-IDB closure passed; ready only for the supervisor's final exact-artifact review and execute/archive lifecycle.
- Applied target state: `COMPLETION:93`, `CONFIDENCE:95`, `CANONICAL_OWNER:0000MR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MR`, emitter position `40`, exact formal CPP, and blank formal H.

## Current Target State

- UID0001DU is now `93/95`, reconstructable, owned/emitted by UID0000MR at position `40`, with the exact file-local `RefreshProfileData` CPP and blank H. Its exact bytes, two-instruction behavior, padding fences, exhaustive no-route evidence, inlining rationale, rejected alternatives, and bounded lexical uncertainty are preserved.
- UID0001AS is now `92/94`, owned/emitted by UID00007Q as `void MapPane::RefreshSelectedProfileData()`. UID00007Q's complete declaration moved byte-for-text from CPP to H and contains the member declaration once; class score/layout remain `93/94` and `0x910`.
- UID00027P remains `90/93`, reconstructable, position `1`, with the same exact table CPP, but now routes through UID0000L3 MapPane. UID0003IV is `90/94`, MapPane-owned, non-reconstructable/non-emitting, with blank formal channels and complete source-literal covered-by evidence.
- ProfileStorage is now `89/90` and retains every persistence/JPF/sidecar semantic fact while current implementation ownership for UID0001AS/UID00027P/UID0003IV is corrected to MapPane. ProfileDialog class/file/action/item and both active-map global/storage pages carry the accepted detailed routes.
- Foreground generated command `000000018248` at `2026-07-28T13:39:55-04:00` is current for all affected outputs. `ProfileDialog.cpp` SHA `226BA2417DC97F06A87FE512ADDA9697A1875143A45A27FD067F4B38A061769B`, 1341 bytes/32 lines, contains UID0001DU once, no UID0001DU empty marker, and the five unrelated pre-existing empty markers. `MapPane.cpp` SHA `E5700A15D224C83D7276331738ECB92ADFC99A03BE7D539D84D7C0A3E7BCCFD7`, 143293 bytes/4349 lines, contains UID0001AS once and UID00027P once, no UID0003IV marker, and five unrelated empty markers. `MapPane.h` SHA `83D3C47CEBB869749938487E82E02B1BF020A0BA42CC316BB45C4C71AE2C1128`, 12408 bytes/348 lines, contains the MapPane declaration and `RefreshSelectedProfileData` once with zero empty markers. `ProfileStorage.cpp` SHA `E4F8F7FD93A56CB099EF84D42FFD8C6FC0E996898C639E0FBC35855ADA88858C`, 12343 bytes/375 lines, contains zero UID0001AS/UID00027P/UID0003IV routes.
- Current lifecycle state: exact-artifact Gate 1 and the accepted ordinary callback passed; serial scoped validators/generated readback are complete; supervisor Gate 2A passed through commands `18325`-`18341`; Gate 2B mutation/readback/save passed on IDB `5a570ede`; and manual coverage is `APPLIED_VERIFIED` through commands `18342`-`18346`. Only the supervisor's final exact-artifact review and execute/archive lifecycle remain.

### Assignment-Time Pre-Callback State

- Assignment-time metadata was `86/92`, reconstructable through `ProfileDialog.cpp`, with blank position/formal CPP/H and an empty target marker.
- Assignment-time prose used raw `dword_67A764` and ProfileStorage cdecl framing; current IDA/global/caller evidence resolved those as `MapPane *g_activeMapPane` and a MapPane member contract.
- Generated command `000000018160` was the pre-callback baseline: ProfileDialog.cpp SHA `4763C7914EE040D3075B86BF7F74383C4C21002B405BA53954E4F4C9B4278148` had the target empty marker; ProfileStorage.cpp SHA `4BF3A43EC4432A3D08C75D7B72B26448FB95F4C573C3B0FDB0FDC8292D155A76` carried UID0001AS/UID00027P; MapPane.cpp SHA `6BEA53EDCF534E2ACEFD2DFCEDA5658FC0402628A23EC7111A0563CA69F36146` lacked UID0001AS; MapPane.h did not exist. These are retained only as historical pre-callback evidence.

### Ordinary document pre-callback artifact identities

| Path | SHA-256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md` | `2CBFB9AC09CEFAF9827842C4E6CEE8B9BC2ACD53B29A00A3B734FE6F71BCD065` | 4821 | 67 |
| `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md` | `59AABAB4657AA2733744DBF25E8A9136E6DE85BC509145C08F62ED88F36E750C` | 18187 | 271 |
| `by-class/ProfileDialog.md` | `A10D33B06DD135FEF05E87EAC370307E88EF70536E17649F7305403CF8A7CEF8` | 8751 | 81 |
| `by-file/ProfileDialog.md` | `11925C4EA3688B0EBC50073F639F05F47D4FF56D42032F7834F5ED3DC1BAA03C` | 8926 | 75 |
| `by-memory/0x0053f940-0x0053fe87.ProfileDialog.md` | `272693B5507BB80B0D5D2C971F9BBDCEAA72661B5BD00B0E63398D6CF21983DC` | 15524 | 140 |
| `by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md` | `02DD06FD8B244CBBCFFEB5ECB0C3F499685BE9F4529CF698471E65C5B8ED60D1` | 5729 | 67 |
| `by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md` | `0054287523E00AF0E63029C3A5BC0BA3C6DCA28359D7C08DE4844F22D9EDAD25` | 4879 | 58 |
| `by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md` | `60B4DF580BE0A9FA0B2E7C3C89A1B46A6B77188E9D8F2A231800BEC84A513ED5` | 5705 | 83 |
| `by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md` | `5981A726183947442C31315856FF3568F5D5EF8A53B21D1A86BACC23700DCD72` | 7079 | 73 |
| `by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md` | `0637C102FFB8D9F931DAF8F2A4BCA0BC3D23D038C266A07AC2037CA4CA0C006A` | 14274 | 101 |
| `by-class/MapPane.md` | `C5B4240B4380453828BFD5ACE0E7AB3CE2DE7BFA7F6A0E177DE8D59707D62782` | 189255 | 1044 |
| `by-file/MapPane.md` | `720F0AE24A97A730AE9B6051B817192E8103D1A1C0D2AFAB07510B4025C1DEDA` | 195698 | 805 |
| `by-file/ProfileStorage.md` | `49701BA735F28266817DA688EA902F556413D0553668BB87741D5EF2ED2F2525` | 16885 | 149 |
| `by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md` | `F8E6AE86AA47234FB69C13F043C4ADEE5E23D09B9C891127ED2B7FF1019FE5E8` | 13458 | 117 |
| `by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md` | `2915983382454BA895DBE562D005436986F93459CEDA2B2782649EAFC7E105B0` | 3627 | 50 |
| `by-global/g_activeMapPane.md` | `51CC83B3FFC44D7F461994673E7646D1DC118D9033964DA8B7190B51AE943F30` | 12542 | 109 |
| `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md` | `591FC348B048F8A37864E80DF6416CF94577E2B289494C899AD908980A4B2008` | 11643 | 84 |
| `by-meta/client_profile_storage.md` | `087C536116FF7DF7DB642612C571DBEEB81DA0B02CA686377A1AD6A874E64C04` | 12038 | 134 |

## Executive Recommendation

- Accepted recommendation is applied in ordinary docs: UID0001DU remains in `ProfileDialog.cpp` as the narrow file-local helper `RefreshProfileData`, its source body is `g_activeMapPane->RefreshSelectedProfileData();`, and its formal H block is blank because file-local functions have no header declaration.
- Retain UID0001DU as one exact emitting range. Do not merge it into the action handler, UID0001DT aggregate, UID0001AS body, padding, or compiler-support coverage.
- UID0001AS is corrected to the nonvirtual member `MapPane::RefreshSelectedProfileData()`, owned/emitted by UID00007Q. The incoming receiver is optimized unused, but every caller establishes the member-call ABI.
- UID00027P and UID0003IV have moved from ProfileStorage source ownership to MapPane source ownership. UID00027P remains the one formal table declaration; UID0003IV is non-emitting source-generated literal evidence, avoiding an empty marker or duplicate literal block.
- Preserve ProfileStorage as the modern `.usr` / legacy `.cfg` persistence module. Remove only the sidecar refresh function/table/string ownership claim from it; retain cross-module behavior and historical correction text.
- UID00007Q's complete class declaration has been migrated byte-for-text from CPP to H and `void RefreshSelectedProfileData();` appears once in the private helper declaration group. Foreground command `000000018248` verifies the generated MapPane.h topology, preserved `0x910` layout, and distinct child definitions.

## Supervisor Active Recheck

- Current supervisor callback rechecked: exact SHA `84B3B003FD1590F3A4ED0AD6F0DA78DDB93F0F68824FFCFBE3E1DF7852AF6844` passed Gate 1 and authorized every accepted ordinary-document C1DU claim. B005 edited only ordinary by-* destinations under short leases, ran serial scoped validators, and performed read-only generated verification.
- Split repair is not required for UID0001DU. The target is exactly one modeled function and the adjacent bytes are separate `0xcc` padding items.
- No new by-memory child is needed. The source-bearing target and dependency already have exact pages; the required repair is source identity and routing.
- Source-bearing support is implemented: target helper CPP, full UID0001AS member CPP, UID00027P table CPP, UID00007Q header migration/declaration, and UID0003IV covered-by disposition are present and validated.
- B005 did not mutate IDA, edit manual coverage/generated/audit/catalog/tracker/supervisor/validator lifecycle state, or run/probe `execute_report`. The supervisor has now completed Gate 2A, Gate 2B, IDB save/catalog, and manual coverage verification; execute/archive remains supervisor-only and pending.

## Inference Research Guidance Check

- IDA facts, documentation facts, and inference are separated throughout this report. Bytes, ranges, xrefs, item boundaries, names, types, comments, and callers are direct IDA facts. Existing UID ownership and generated output are documentation facts. Original source names and inlining cause are explicit source-shape inference.
- Existing documentation was treated as evidence, not authority. The stale `dword_67A764`, free-cdecl, ProfileStorage owner, and `ECX is not semantic ownership evidence` claims were independently rechecked.
- The evidence ladder gives calling-site ABI preparation and physical translation-unit clustering greater weight than an erased decompiler prototype. The decompiler's `void()` display is not original type proof.
- Missing target xrefs were investigated through code xrefs, data xrefs, immediate and raw pointer patterns, vtable routes, function-pointer routes, signature peers, adjacent code, and inlined-equivalent behavior. The no-route result is retained as evidence rather than used as an excuse to leave the emitter blank.
- Wave2/Wave3 wording in historical material was ignored as stale process language. No current recommendation depends on it.

## Heuristic / Inference Reanalysis And Validation

- Generated target name: `sub_53FE90` is replaced in source reasoning by `RefreshProfileData`. This is a descriptive, source-era name, not an original-symbol claim.
- Global name: `dword_67A764` is resolved, not guessed. Current IDA names and types it `MapPane *g_activeMapPane`; current global/storage docs independently support the same identity.
- Target role: exact bytes load `g_activeMapPane` into `ECX` and tail-jump. The strongest source explanation is a small ProfileDialog.cpp helper whose only source call was inlined into `ProfileDialog::HandleDialogAction`, leaving the out-of-line body without a surviving executable xref.
- Static versus nonvirtual ProfileDialog member: both can lower to the observed body. File-local static is selected because no surviving route supplies or requires a ProfileDialog receiver, the body uses only the active MapPane global, and it avoids inventing a ProfileDialog UDT/class declaration that current evidence cannot complete. A nonvirtual member remains the second-ranked historical-source possibility and caps lexical/source-shape confidence.
- Callee calling convention: all three call sites prepare a MapPane receiver. `0x005089e3` restores a complete MapPane pointer with `lea ecx,[esi-0xa0]`; `0x0053fe65` loads `g_activeMapPane`; UID0001DU does the same before its tail jump. The callee overwrites ECX before reading it, so optimized machine code need not use `this`. Best source form is a nonvirtual `MapPane` member, not cdecl.
- Callee source name: `RefreshSelectedProfileData` remains the best current source-facing name because the accepted body refreshes the selected profile portrait/name packet. It is descriptive, stable across existing docs, and does not preserve an IDA label.
- Callee source file: function-neighborhood evidence places `0x005063e0` between MapPane-owned code, and its only static table sits between MapPane data tables. The behavior is profile-sidecar work, but behavior alone does not override the stronger MapPane receiver and physical source evidence.
- Table source file: UID00027P has exactly one table-base consumer inside UID0001AS. Once UID0001AS is MapPane-owned, the table follows that function into `MapPane.cpp`; adjacent MapPane tables provide corroborating placement.
- String source file: UID0003IV's exact literals are consumed by UID0001AS/table. They follow the function to `MapPane.cpp` but remain source-generated literals, not a separately emitted byte array.
- One-definition blocker resolved: assignment-time output placed the free function/table in ProfileStorage while the target was empty. Current command `000000018248` places one target definition in ProfileDialog, one UID0001AS member and UID00027P table in MapPane, no UID0003IV marker, and zero corresponding ProfileStorage routes.
- Header blocker resolved: assignment-time UID00007Q emitted the complete class declaration in CPP. Current ordinary state is the byte-for-text CPP-to-H migration plus one private declaration, and current generated MapPane.h contains that declaration once.
- Rejected: ProfileStorage ownership based solely on filesystem behavior. The function's ABI and physical placement contradict it.
- Rejected: a vtable callback or adjustor thunk at UID0001DU. No target pointer, vtable, data, or incoming code route exists, and the body does not adjust `this`.
- Rejected: compiler-only/non-emitting target. The body expresses a source-level operation, has a natural two-line C++ reconstruction, and its lack of xrefs has a plausible inlining explanation.
- Rejected: merge target into UID0004E2. Nine bytes of `0xcc` alignment and a separate function boundary prove separate bodies.
- Rejected: merge target into UID0001AS. The two ranges are in different translation-unit neighborhoods and represent caller/forwarder versus implementation.

## Evidence Standards Used

- Live IDA MCP: `server_health`, `lookup_funcs`, `inspect_items`, `get_bytes`, `disasm`, `decompile`, `analyze_function`, `xrefs_to`, `xref_query`, `find_bytes`, `get_comment`, `type_query`, and exact-name collision queries.
- Binary evidence: exact eleven-byte body, displacement-resolved global and jump target, exclusive endpoints, adjacent `0xcc` fences, caller instruction windows, callee prologue/body, and raw VA/RVA pointer searches.
- Source-routing evidence: all caller receiver preparations, adjacent MapPane code/data families, ProfileDialog action sequence, generated output, existing by-* owner chains, and archived B-agent reports.
- Negative evidence: zero target xrefs, zero target pointer forms, no vtable route, no ProfileDialog UDT, no target merge evidence, and no second consumer of the extension table.
- Evidence strength: direct machine facts make behavior and ABI high confidence. Original lexical spellings and whether the tiny helper was `static` or a private nonvirtual member cannot be proven from the stripped executable, so the most plausible human form is selected and confidence is capped below certainty.

## Evidence Checked

- IDA target checks: `sub_53FE90` identity/range, exact bytes, two instructions, decompile, four comment channels, both adjacent item boundaries, incoming xrefs, pointer patterns, immediate patterns, and signature peers.
- IDA callee checks: `sub_5063E0` exact range, decompile, disassembly, all three xrefs, caller windows, first ECX use, four comment channels, neighboring padding, and proposed-name collision.
- IDA global checks: `0x0067a764` exact item, current `g_activeMapPane` name, `MapPane *` type, zero bytes/value, current regular comment, absent repeatable comment, and high-fanout xrefs.
- IDA type checks: existing `MapPane` UDT ordinal 614 and exact size `0x910`; no current `ProfileDialog` UDT; two allocation sites use exact size `0x26c`.
- Documentation checked: UID0001DU, UID0000MR, UID0000AU, UID0001DT, UID0004E0, UID0004E1, UID0004E2, UID00038G, UID0000V9, UID0001AS, UID0000MS, UID00007Q, UID0000L3, UID00027P, UID0003IV, UID0000PR, UID0001OW, and UID0001QL.
- Generated sources checked twice: assignment-time command `000000018160` supplied the historical baseline; foreground callback command `000000018248` supplied current ProfileDialog.cpp, MapPane.cpp/H, and ProfileStorage.cpp hashes and exact occurrence/marker counts.
- Historical reports checked: B003 UID0001AS and B008 UID0001DT.
- Manual coverage checked: the exact accepted rows for UID0001DU, UID0001AS, UID00027P, UID0003IV, UID0000AU, UID0000MR, UID0000MS, UID0000V9, and UID0001QL were subsequently applied and supervisor-verified through commands `18342`-`18346`; UID0004E2 remains represented through its parent family as recommended.
- Initial report-only phase intentionally skipped every write-capable MCP operation, validator, generated refresh, report lifecycle command, and ordinary-document edit. The accepted callback later used only ordinary-document edits, scoped validators, and read-only generated inspection. The supervisor, not B005, subsequently performed the accepted IDA, coverage, save, catalog, and Gate 2 verification actions; report execution/archive remains supervisor-owned and pending.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C1DU-01 | 0001DU | Exact range is `[0x0053fe90,0x0053fe9b)`, size `0xb`. | Certain | Live lookup/item/bytes/disasm. | UID0001DU Covered Range / IDA Evidence | Replace stale summary with exact range and size. | applied/validated `18187` |
| C1DU-02 | 0001DU | Exact body is `mov ecx,[0x67a764]; jmp 0x5063e0`. | Certain | Bytes `8b 0d 64 a7 67 00 e9 45 65 fc ff`. | UID0001DU behavior / formal CPP | Emit one forwarding helper. | applied/validated `18187`; generated `18248` |
| C1DU-03 | 0001DU | Adjacent ranges are separate 9-byte and 5-byte `0xcc` padding items. | Certain | Live item and byte reads. | UID0001DU range/history; UID0000VN links | Preserve boundaries; no split/merge. | applied/validated `18187` |
| C1DU-04 | 0001DU | No incoming code/data/pointer/immediate/vtable route survives. | Very high | xrefs and VA/RVA/raw-pattern searches all zero. | UID0001DU negative evidence | Preserve exact no-route result. | applied/validated `18187` |
| C1DU-05 | 0001DU | Best source role is retained file-local `RefreshProfileData` in ProfileDialog.cpp. | Strong | Physical adjacency, inlined equivalent, no ProfileDialog receiver route, natural source form. | UID0001DU metadata/CPP; UID0000MR | Keep file owner/emitter, set position 40, add formal CPP. | applied/validated `18187`,`18204`; generated `18248` |
| C1DU-06 | 0001DU | Target remains reconstructable/emitting, not compiler-only. | Very high | Exact natural source operation and independent function boundary. | UID0001DU metadata | Keep TRUE and UID0000MR emitter. | applied/validated `18187` |
| C1DU-07 | 0001DU | `0x67a764` is `MapPane *g_activeMapPane`. | Certain | Current IDA name/type/comment/value plus UID0000PR/UID0001OW. | UID0001DU and ProfileDialog supports | Replace raw dword label everywhere in current prose/code. | applied/validated `18187`,`18193`,`18199`,`18204`,`18208`,`18211`,`18246`,`18247` |
| C1DU-08 | 0001AS | `0x5063e0` obeys a MapPane member-call contract. | Very high | All three callers explicitly prepare MapPane ECX. | UID0001AS Status/Behavior/CPP | Change to `MapPane::RefreshSelectedProfileData`. | applied/validated `18217`; generated `18248` |
| C1DU-09 | 0001AS | Incoming `this` is optimized unused; erased decompiler `void()` is not cdecl proof. | Very high | First callee ECX use overwrites ECX with a local address. | UID0001AS historical correction | Preserve optimization fact and reject stale inference. | applied/validated `18217`,`18221`,`18223`,`18242`,`18244` |
| C1DU-10 | 0001AS | Sidecar/JPF/opcode-79 behavior remains complete and unchanged. | Very high | Existing complete body plus live decompile/callees. | UID0001AS formal CPP and behavior | Preserve full body; change only ownership/member signature and dependencies. | applied/validated `18217`,`18242`,`18244` |
| C1DU-11 | 0001AS | Source owner/emitter changes from UID0000MS to UID00007Q. | Very high | Receiver ABI plus MapPane code/data neighborhood. | UID0001AS metadata; UID00007Q/UID0000L3 | Route one member definition through MapPane. | applied/validated `18217`,`18221`,`18223`; generated `18248` |
| C1DU-12 | 00027P | Extension table belongs with its sole MapPane member consumer. | Very high | Sole table-base ref at 0x5064d0 and corrected consumer owner. | UID00027P metadata/prose; UID0000L3 | Owner/emitter UID0000L3, retain position 1 and CPP. | applied/validated `18228`,`18223`; generated `18248` |
| C1DU-13 | 0003IV | Sidecar literals are MapPane.cpp source-generated data. | Very high | Direct refs only from UID0001AS/table. | UID0003IV metadata/prose | Owner UID0000L3, false/nonemitting, blank CPP/H. | applied/validated `18236`,`18223`; absent from generated `18248` |
| C1DU-14 | 00007Q | Complete MapPane declaration must live in H and declare the member once. | High | Assignment-time declaration was in generated CPP and MapPane.h was absent. | UID00007Q formal blocks | Byte-for-text CPP-to-H migration plus private method declaration. | applied/validated `18221`; generated H verified `18248` |
| C1DU-15 | 0000L3 | MapPane.cpp receives method, table, literals, and required includes exactly once. | High | Corrected owner topology. | UID0000L3 source-route notes | Add complete cross-doc source route and generated expectations. | applied/validated `18223`; generated CPP/H verified `18248` |
| C1DU-16 | 0000MS | ProfileStorage retains persistence but loses sidecar function/table/string ownership. | Very high | Corrected ABI/placement does not affect persistence functions. | UID0000MS status/contents/history | Preserve behavior; historicalize old ownership. | applied/validated `18242`,`18244`; generated zero-route verified `18248` |
| C1DU-17 | 0000AU | ProfileDialog class calls/hosts the helper context but does not own the MapPane member body. | High | Physical helper placement and action sequence. | UID0000AU method notes | Add static-helper relation and corrected callee/global names. | applied/validated `18199`,`18204` |
| C1DU-18 | 0004E2 | Action handler's direct call is to MapPane member on g_activeMapPane. | Certain | Disassembly at 0x53fe5f/0x53fe65. | UID0004E2 evidence/source notes | Replace ProfileStorage trigger wording; preserve handler behavior. | applied/validated `18208` |
| C1DU-19 | 0000V9 | Helper item must distinguish source helper, MapPane member, and compiler destructor wrappers. | High | Exact ranges and corrected ownership. | UID0000V9 status/helper table | Replace stale ProfileStorage split and uncertainty. | applied/validated `18211` |
| C1DU-20 | 0001QL | Profile sidecar behavior remains relevant, but implementation source is MapPane.cpp. | High | Corrected source route with unchanged storage semantics. | UID0001QL ownership/history | Preserve full behavior and correct source owner. | applied/validated `18244` |
| C1DU-21 | 0001DU | Target score should be `93/95`. | High | All assigned blockers resolved; lexical static/member uncertainty remains. | UID0001DU metadata/coverage | Raise score with exact rationale. | ordinary metadata applied/validated `18187`; manual coverage `APPLIED_VERIFIED` `18342` |
| C1DU-22 | support | Generated topology must contain no UID0001DU empty marker or duplicate UID0001AS/table. | High | Assignment command `18160` baseline and current command `18248` readback. | Generated verification after validators | Verify exact occurrence/marker counts; never edit generated directly. | applied/verified foreground generated `18248` |
| C1DU-23 | 0001DU | Source-quality IDA identity is `ProfileDialog_RefreshProfileData` with canonical `void __cdecl()` and the exact accepted function-repeatable comment. | Certain after readback | Supervisor Gate 2B on IDB `5a570ede`. | IDA function identity/type/comment | Apply and read back exact accepted action. | `APPLIED_VERIFIED`; saved IDB/catalog entry `0337` |
| C1DU-24 | 0001AS | Source-quality IDA identity is `MapPane__RefreshSelectedProfileData` with canonical `void __thiscall(MapPane *this)` and the exact accepted function-repeatable comment. | Certain after readback | Supervisor Gate 2B on IDB `5a570ede`. | IDA function identity/type/comment | Apply and read back exact accepted action. | `APPLIED_VERIFIED`; saved IDB/catalog entry `0337` |
| C1DU-25 | support | `g_activeMapPane` and all four padding fences must remain unchanged. | Certain after readback | Supervisor protected-item Gate 2B comparison. | IDA protected-state verification | Preserve exact name/type/value/comments, fence bounds, and bytes. | `APPLIED_VERIFIED`; all protected state unchanged |
| C1DU-26 | support | Independent ordinary-document Gate 2A must pass after callback. | Certain | Supervisor commands `18325`-`18341`. | All callback ordinary destinations | Revalidate claim by claim. | `GATE2A_PASSED` |
| C1DU-27 | support | Exact manual coverage payloads must be applied only by the supervisor and validated. | Certain | Supervisor commands `18342`-`18346` and recorded file hashes. | by-memory/by-class/by-file/by-item/by-meta coverage | Apply and verify accepted payloads. | `APPLIED_VERIFIED` |

## Positive Evidence Summary

- Direct target facts: one exact 11-byte function, one global load, one tail jump, separate padding on both sides, and no hidden body or child range.
- Direct global facts: the loaded dword is already a typed, named active MapPane pointer with 360 documented references and stable storage evidence.
- Direct callee facts: every live caller prepares a MapPane receiver. Two callers load the active MapPane global; the packet-dispatch caller reverses a `-0xa0` secondary-facet adjustment to recover the complete MapPane object.
- Physical source facts: UID0001AS sits in a MapPane code cluster; UID00027P sits between MapPane data tables. Profile-sidecar semantics explain the method's work but do not prove ProfileStorage translation-unit ownership.
- Compiler/source-shape facts: the target's two source operations naturally produce the observed load plus tail jump. The direct sequence in UID0004E2 is compatible with the same trivial helper being inlined while an out-of-line copy remains.
- Corroborating docs: UID0000PR and UID0001OW prove `g_activeMapPane`; UID00007Q/UID0000L3 prove the MapPane source root; UID0001AS/UID00027P/UID0003IV preserve the complete behavior and data inventory.

## IDA MCP Facts

- Assignment-time target prestate: name `sub_53FE90`; `[0x0053fe90,0x0053fe9b)`; size `0xb`; two instructions; type `void()`; decompiler rendered a single call.
- Target bytes: `8b 0d 64 a7 67 00 e9 45 65 fc ff`.
- Target disassembly: `0x0053fe90 mov ecx, g_activeMapPane`; `0x0053fe96 jmp sub_5063E0`.
- Assignment-time target comments: address regular absent; address repeatable absent; function regular absent; function repeatable absent.
- Target xrefs: zero incoming. Raw little-endian target VA `90 fe 53 00`, target RVA `90 fe 13 00`, dependency VA `e0 63 50 00`, and dependency RVA `e0 63 10 00` produce no pointer-pattern route to the target.
- Signature peers: the global-load/tail-jump shape appears at 0x53fe90, 0x553e50, and inside 0x599bc3. The 0x553e50 peer is an eleven-byte class callback forwarding through a global, proving the machine shape is compatible with ordinary C++.
- Assignment-time callee prestate: name `sub_5063E0`; `[0x005063e0,0x00506962)`; size `0x582`; type `void()`; four comment channels absent.
- Callee xrefs: 0x5089e3 from `sub_507C90`, 0x53fe65 from `sub_53FDC0`, and target tail jump at 0x53fe96.
- Callee receiver evidence: `lea ecx,[esi-0xa0]`, `mov ecx,g_activeMapPane`, and `mov ecx,g_activeMapPane`, respectively.
- Callee first ECX use: 0x50640d loads a local address into ECX before any incoming-ECX read. This proves optimized `this` non-use, not a source cdecl contract.
- Callee padding: five `0xcc` bytes at `[0x5063db,0x5063e0)` and fourteen at `[0x506962,0x506970)`.
- Global item: `[0x0067a764,0x0067a768)`, width four, current name `g_activeMapPane`, type `MapPane *`, bytes/value zero.
- MapPane UDT: present, ordinal 614, exact size `0x910`/2320. ProfileDialog UDT: absent. ProfileDialog allocations at 0x53e11c and 0x5bd252 use exact size `0x26c`.
- Supervisor Gate 2B current readback on IDB `5a570ede`: target name is `ProfileDialog_RefreshProfileData` with canonical `void __cdecl()`; callee name is `MapPane__RefreshSelectedProfileData` with canonical `void __thiscall(MapPane *this)`; each function-repeatable comment equals its exact accepted text in the recommendation table; `g_activeMapPane` and all four padding fences are unchanged.
- Gate 2B persistence: byte-preserving backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0001DU-prestate-20260728-151308`; saved IDB SHA-256 `823941722288F7B2BAAE0E9B2923B22B0505DCFFD28C33990F25E4A45399083D`, 143190099 bytes, mtime `2026-07-28T15:13:45.2018477-04:00`; catalog entry `0337`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0053fe90-0x0053fe9b` | UID0001DU target | retained ProfileDialog.cpp forward helper | true | UID0000MR | current applied 93/95 | exact CPP applied/validated; generated once |
| `0x0053fe87-0x0053fe90` | UID0000VN padding | nine-byte function fence | false/ignored | none | 100 | preserve |
| `0x0053fe9b-0x0053fea0` | UID0000VN padding | five-byte function fence | false/ignored | none | 100 | preserve |
| `0x005063e0-0x00506962` | UID0001AS | MapPane selected-profile refresh member | true | current UID00007Q | current applied 92/94 | complete member CPP applied/validated; generated once |
| `0x0066dd60-0x0066dd78` | UID00027P | file-local extension table plus zero padding | true | current UID0000L3 | current applied 90/93 | table CPP applied/validated; generated once |
| `0x0061e964-0x0061e9fc` | UID0003IV | source-generated profile sidecar literals | current false/nonemitting | current UID0000L3 | current applied 90/94 | covered by source literals; no independent emitter/marker |
| `0x0067a764-0x0067a768` | UID0001OW / UID0000PR | active MapPane pointer storage/semantic global | true | existing MapPane route | 90/93 and 91/92 | already resolved; no change |
| `0x0053fdc0-0x0053fe87` | UID0004E2 | ProfileDialog accept/cancel action handler | true | UID0000AU | current applied 89/92 | support wording applied/validated |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053fe90` | no incoming xrefs | no surviving executable caller, vtable slot, pointer, or relocation route |
| `0x0053fe96` | tail jump to `0x005063e0` | exact target forwarding operation |
| `0x005089e3` | `sub_507C90` calls `0x005063e0` after `lea ecx,[esi-0xa0]` | MapPane packet case 73 restores complete MapPane receiver |
| `0x0053fe65` | UID0004E2 calls `0x005063e0` after loading `g_activeMapPane` | ProfileDialog accept path invokes MapPane member directly/inlined helper equivalent |
| `0x0053fe96` | UID0001DU jumps after loading `g_activeMapPane` | retained forwarding helper invokes same MapPane member |
| `0x005064d0` | sole table-base ref to `0x0066dd60` | UID00027P belongs with the member consumer |
| `0x0067a764` | 360 documented refs; bounded live sample includes 0x4244a1, 0x450e43, 0x452a49, 0x452ea9, 0x464e7b | active high-fanout MapPane pointer, not ProfileStorage state |

## Documentation Evidence And IDA Status

- UID0001DU's assignment-time page had correct range/padding/tail-jump facts but stale raw global naming, ProfileStorage callee ownership, blank CPP, and unresolved source-visibility prose. The ordinary callback corrected each item, and the supervisor subsequently applied and verified its manual coverage row.
- UID0001AS's assignment-time page had valuable complete behavior/formal C++ but a stale free-cdecl signature, ProfileStorage owner/emitter, and an incorrect statement that prepared ECX was not ownership evidence. The current page is `92/94`, UID00007Q-owned, member-shaped, and preserves the complete behavior.
- UID00027P's exact bytes, pointer targets, loop bound, table CPP, and clean boundaries remain unchanged. Current source owner/emitter is UID0000L3, and its supervisor-owned manual coverage row is applied and verified.
- UID0003IV retains exact literal payloads and consumers and now has a complete Item Summary, UID0000L3 owner, `90/94`, and false/non-emitting covered-by disposition. Its new manual coverage row is applied and verified.
- UID0000PR and UID0001OW already resolve the global correctly; no metadata or IDA mutation is needed there.
- UID00007Q and UID0000L3 are the correct class/file source root. The assignment-time CPP-channel declaration debt is resolved: the complete class declaration now lives in H and includes the member once.
- UID0000MS and UID0001QL remain complete profile-persistence/sidecar behavior documents. Their former source-owner claims are preserved as explicit corrected history, while current implementation ownership routes to MapPane.cpp.
- Current IDA state after supervisor Gate 2B names/types the global and both functions at source quality: `ProfileDialog_RefreshProfileData` has canonical `void __cdecl()`, `MapPane__RefreshSelectedProfileData` has canonical `void __thiscall(MapPane *this)`, and both exact accepted function-repeatable comments read back successfully. The protected global and four padding fences remain unchanged; the IDB was saved and cataloged as entry `0337`.

## Ranked Ownership Analysis

### 1. ProfileDialog.cpp file-local helper for UID0001DU; MapPane member for UID0001AS

- Evidence for: exact ProfileDialog physical neighborhood, natural global-load/forward source, direct inlined-equivalent sequence in UID0004E2, no target pointer/vtable route, all callee invocations prepare MapPane, and MapPane code/data adjacency.
- Evidence against: stripped binary cannot prove the original target spelling or distinguish file-local static from an unused nonvirtual ProfileDialog method with certainty.
- Decision: selected. It produces valid human source, preserves exact behavior, avoids a speculative ProfileDialog class layout, and gives the callee the ABI all callers use.

### 2. Nonvirtual ProfileDialog member forwarding to MapPane

- Evidence for: an externally visible nonvirtual member can remain after its only local call is inlined; physical adjacency after ProfileDialog methods supports class association.
- Evidence against: no surviving caller supplies a ProfileDialog receiver, target immediately replaces ECX, no ProfileDialog UDT exists, and a declaration cannot be placed safely in the currently incomplete class without broader class recovery.
- Decision: plausible historical alternative, not selected. Preserve it in source-shape rationale and use it as the confidence cap.

### 3. ProfileStorage free helper, vtable thunk, or compiler-only body

- Evidence for: behavior performs profile sidecar IO; current decompiler prints `void()`; target has no incoming refs.
- Evidence against: behavior is not source ownership, every callee invocation prepares MapPane, physical code/data placement is MapPane, no target vtable/pointer route exists, and exact source C++ is natural.
- Decision: rejected and historicalized.

### Proposed new file/grouping, if applicable

- No new source file is warranted.
- `ProfileDialog.cpp` keeps UID0001DU only as the narrow forwarding helper.
- `MapPane.cpp` receives UID0001AS, UID00027P, and source-generated UID0003IV literals through existing UID00007Q/UID0000L3 routes.
- `ProfileStorage.cpp` retains load/save/import persistence and loses only the incorrectly routed sidecar refresh family.

## Source Placement

- UID0001DU placement: `NexusTK/profile/ProfileDialog.cpp`, namespace-scope internal linkage, after the action-handler source family.
- UID0001AS placement: `NexusTK/map/MapPane.cpp` as `MapPane::RefreshSelectedProfileData()` in physical function order near the opcode-0x0c helper and before later MapPane input/packet/render methods.
- UID00027P placement: file-local declaration in `MapPane.cpp` before UID0001AS so the member's extension loop sees one declaration.
- UID0003IV placement: generated by the table/function string literals in `MapPane.cpp`; no separate emitted byte array.
- Required header placement: UID00007Q's complete `MapPane` declaration belongs in `MapPane.h`; add one private `void RefreshSelectedProfileData();` declaration there.
- Rejected placements: ProfileStorage.cpp for UID0001AS/table/strings, ProfileDialog class ownership for the sidecar implementation, a new ProfileRefresh.cpp file, an emitted raw string-data object, and any generated-file direct edit.

## Range / Split / Padding / Reclassification Analysis

- Target exact range is `[0x0053fe90,0x0053fe9b)`. It is one function and requires no split.
- Predecessor `[0x0053fe87,0x0053fe90)` is exactly nine `0xcc` bytes and remains UID0000VN ignored padding.
- Successor `[0x0053fe9b,0x0053fea0)` is exactly five `0xcc` bytes and remains UID0000VN ignored padding.
- UID0001AS remains `[0x005063e0,0x00506962)` with its five-byte and fourteen-byte `0xcc` fences unchanged.
- UID00027P remains `[0x0066dd60,0x0066dd78)`: five pointers occupy 0x14 bytes and the final dword is zero padding, not a sixth entry.
- UID0003IV remains `[0x0061e964,0x0061e9fc)` and separate from later MapPane `/users/` asset strings. Its reconstruction classification changes to false/nonemitting because the exact bytes are compiler-generated from source literals already represented in the function/table source.
- UID0001DT remains the non-emitting split/index parent and does not absorb UID0001DU.

## Negative Evidence Summary

- No incoming target xref was found by code, data, immediate, VA, RVA, raw-offset, or signature-route checks.
- No vtable entry, RTTI record, function-pointer table, relocation, unwind-only route, or adjustor operation points to UID0001DU.
- No evidence supports merging the target across either padding fence.
- No evidence supports treating `g_activeMapPane` as a ProfileStorage pointer, config field, or unknown dword.
- No callee invocation omits MapPane receiver preparation. The erased current type is therefore weaker than the unanimous call-site contract.
- No target or callee byte requires a handwritten thunk, assembly, raw address, or decompiler label in final source.
- No second table consumer supports generic image-module or ProfileStorage table ownership.
- No exact original symbol survives. Human names are therefore explicitly inferred from behavior and project naming style, not presented as original-symbol proof.

## IDA Rename / Type / Comment Recommendations

### Actionable function rows

| Entity | Exact assignment-time pre-state, preserved | Collision result | Accepted supervisor action | Exact expected readback contract |
| --- | --- | --- | --- | --- |
| Function `[0x0053fe90,0x0053fe9b)`, size `0xb` | Current name `sub_53FE90`; current declaration/type `void()`; decompiler `void sub_53FE90()`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. | Exact `lookup_funcs`/name-regex check for `ProfileDialog_RefreshProfileData` returned no function/name collision. | Rename to `ProfileDialog_RefreshProfileData`; apply declaration `void __cdecl ProfileDialog_RefreshProfileData(void)`; apply exact function-repeatable comment: `ProfileDialog.cpp retained refresh helper: loads g_activeMapPane and tail-forwards to MapPane::RefreshSelectedProfileData; no direct xref, pointer, immediate, or vtable route survives.` | Range/bytes remain exact; name equals `ProfileDialog_RefreshProfileData`; declaration equals `void __cdecl ProfileDialog_RefreshProfileData(void)`; address-regular remains absent; address-repeatable remains absent; function-regular remains absent; function-repeatable equals the exact proposed text; decompile remains one source-equivalent forward call. |
| Function `[0x005063e0,0x00506962)`, size `0x582` | Current name `sub_5063E0`; current declaration/type `void()`; decompiler `void sub_5063E0()`; address-regular comment absent; address-repeatable comment absent; function-regular comment absent; function-repeatable comment absent. | Exact name-regex check for `MapPane__RefreshSelectedProfileData` returned no function/name collision. Existing UDT `MapPane` is ordinal 614, size `0x910`. | Rename to `MapPane__RefreshSelectedProfileData`; apply declaration `void __thiscall MapPane__RefreshSelectedProfileData(MapPane *this)`; apply exact function-repeatable comment: `MapPane selected-profile sidecar refresh member; all three call sites prepare a MapPane receiver although optimized code does not read this. Builds NexusTK user sidecar paths, validates JPF portrait data, and sends opcode 79.` | Range/bytes/xrefs remain exact; name equals `MapPane__RefreshSelectedProfileData`; declaration shows one MapPane pointer receiver; address-regular remains absent; address-repeatable remains absent; function-regular remains absent; function-repeatable equals the exact proposed text; decompile retains complete behavior and may omit semantic uses of `this` because incoming ECX is not read. |

### Supervisor Gate 2B applied and verified readback

| Entity | Current source-quality identity/type | Current comment-channel readback | Preserved state |
| --- | --- | --- | --- |
| Function `[0x0053fe90,0x0053fe9b)` | `ProfileDialog_RefreshProfileData`; canonical `void __cdecl()` (`void __cdecl ProfileDialog_RefreshProfileData(void)`) | address-regular absent; address-repeatable absent; function-regular absent; function-repeatable exactly `ProfileDialog.cpp retained refresh helper: loads g_activeMapPane and tail-forwards to MapPane::RefreshSelectedProfileData; no direct xref, pointer, immediate, or vtable route survives.` | exact range, bytes, no-route result, predecessor, and successor unchanged |
| Function `[0x005063e0,0x00506962)` | `MapPane__RefreshSelectedProfileData`; canonical `void __thiscall(MapPane *this)` (`void __thiscall MapPane__RefreshSelectedProfileData(MapPane *this)`) | address-regular absent; address-repeatable absent; function-regular absent; function-repeatable exactly `MapPane selected-profile sidecar refresh member; all three call sites prepare a MapPane receiver although optimized code does not read this. Builds NexusTK user sidecar paths, validates JPF portrait data, and sends opcode 79.` | exact range, bytes, xrefs, behavior, predecessor, and successor unchanged |

### Already-present data row

| Entity | Exact current pre-state | Proposed supervisor action | Exact expected readback |
| --- | --- | --- | --- |
| Data `[0x0067a764,0x0067a768)`, width 4 | Current name `g_activeMapPane`; current data declaration/type `MapPane *`; current bytes/value `00 00 00 00` / zero; address-regular comment is exactly `Accepted active MapPane singleton/context pointer used by LivingObjectPane linked-object teardown and render-region refresh.` then `Active MapPane singleton used for group-member HitBar refresh/removal.` then `Externally linked active MapPane singleton used across translation units; source-facing type MapPane * and canonical name g_activeMapPane.` then `Active MapPane pointer; RightButtonMenuPane destructor accesses m_highlightedObjectPane at +0x104 without a global null guard.`; address-repeatable comment absent; function-regular comment not applicable; function-repeatable comment not applicable. | Classification: already present, no change. Do not rename, retype, rewrite comments, or create a duplicate global. | Name, type, width, bytes/value, exact address-regular comment, absent address-repeatable comment, and all xrefs remain unchanged. Function comment channels remain not applicable. |

The literal current `0x0067a764` address-regular comment text is:

```text
Accepted active MapPane singleton/context pointer used by LivingObjectPane linked-object teardown and render-region refresh.
Active MapPane singleton used for group-member HitBar refresh/removal.
Externally linked active MapPane singleton used across translation units; source-facing type MapPane * and canonical name g_activeMapPane.
Active MapPane pointer; RightButtonMenuPane destructor accesses m_highlightedObjectPane at +0x104 without a global null guard.
```

### Supporting type and protected-item prestate

- `MapPane` UDT: current exact state is present, ordinal 614, size `0x910`; preserve size and all existing members. No new UDT is required.
- `ProfileDialog` UDT: current exact state is absent. Do not create a speculative UDT for this static-helper recommendation. Exact 0x26c allocations are documentation evidence only.

| Protected entity | Current name/type | Current bytes/value | Address regular | Address repeatable | Function regular | Function repeatable | Required readback |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `[0x0053fe87,0x0053fe90)`, 9-byte data/padding item | name absent; data declaration/type absent | nine `cc` bytes | absent | absent | not applicable | not applicable | unchanged item bounds, bytes, blank name/type/comments |
| `[0x0053fe9b,0x0053fea0)`, 5-byte data/padding item | name absent; data declaration/type absent | five `cc` bytes | absent | absent | not applicable | not applicable | unchanged item bounds, bytes, blank name/type/comments |
| `[0x005063db,0x005063e0)`, 5-byte data/padding item | name absent; data declaration/type absent | five `cc` bytes | absent | absent | not applicable | not applicable | unchanged item bounds, bytes, blank name/type/comments |
| `[0x00506962,0x00506970)`, 14-byte data/padding item | name absent; data declaration/type absent | fourteen `cc` bytes | absent | absent | not applicable | not applicable | unchanged item bounds, bytes, blank name/type/comments |

- Negative constraints: do not merge functions with padding; do not create a target vtable xref; do not convert UID0001DU to a MapPane method; do not create a ProfileStorage UDT/member; do not alter `g_activeMapPane`; do not resize MapPane; do not overwrite bytes, xrefs, neighboring names, or unrelated comments.
- B005 remained read-only. The rows above preserve the exact prestate and accepted supervisor Gate 2B contract. The supervisor subsequently applied and read back both function names, canonical types, and exact function-repeatable comments on IDB `5a570ede`; preserved `g_activeMapPane` and the four padding fences unchanged; saved the IDB at SHA-256 `823941722288F7B2BAAE0E9B2923B22B0505DCFFD28C33990F25E4A45399083D`; and cataloged entry `0337`.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target body is exact and source-simple; the callee's complete accepted body is already present and only needs owner/member correction.
- UID0001DU CPP formal insertion text:

```cpp
namespace {

void RefreshProfileData()
{
    g_activeMapPane->RefreshSelectedProfileData();
}

} // namespace
```

- UID0001DU H formal insertion text: blank. A file-local static helper has no header declaration.
- UID0001AS CPP formal insertion text: preserve the current complete block byte-for-text except that the public function definition becomes `void MapPane::RefreshSelectedProfileData()`. The resulting complete destination block is:

```cpp
namespace {

const unsigned char kProfileRefreshOpcode = 79;
const unsigned int kMaxProfileJpfBytes = 0x2710;
const int kProfilePortraitWidth = 48;
const int kProfilePortraitHeight = 56;
const DWORD kFaceRipperWaitMs = 10000;
const int kProfileSidecarExtensionCount = 5;

void SendProfileRefreshPacket(const unsigned char* jpfBytes, unsigned int jpfSize, bool includeJpf)
{
    unsigned char stackPacket[1024];
    AutoBuffer<unsigned char> heapPacket;
    unsigned char* packet = stackPacket;

    if (includeJpf) {
        heapPacket.Allocate(10010);
        packet = heapPacket.Data();
    }

    int cursor = 0;
    PacketBufferAppendUInt8(kProfileRefreshOpcode, packet, &cursor);
    PacketBufferAppendUInt16BE(
        includeJpf ? static_cast<unsigned short>(jpfSize) : 0,
        packet,
        &cursor);

    if (includeJpf) {
        memcpy(packet + cursor, jpfBytes, jpfSize);
        cursor += static_cast<int>(jpfSize);
    }

    PacketBufferAppendWideStringAsAnsi8(
        g_pConfig->userProfile.selectedProfileName,
        packet,
        &cursor);
    QueueAndSendPacket(g_packetSender, packet, cursor);
}

bool CreateDirectoryIfNeeded(const wchar_t* path)
{
    if (CreateDirectoryW(path, NULL)) {
        return true;
    }
    return GetLastError() == ERROR_ALREADY_EXISTS;
}

} // namespace

void MapPane::RefreshSelectedProfileData()
{
    WideString localPlayerName;
    GetLocalPlayerNameString(localPlayerName);

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK) {
        return;
    }

    wchar_t nexusDir[MAX_PATH];
    FormatWide(nexusDir, MAX_PATH, L"%s\\NexusTK", documentsPath);
    if (!CreateDirectoryIfNeeded(nexusDir)) {
        return;
    }

    wchar_t usersDir[MAX_PATH];
    FormatWide(usersDir, MAX_PATH, L"%s\\NexusTK\\users", documentsPath);
    if (!CreateDirectoryIfNeeded(usersDir)) {
        return;
    }

    WideString sidecarPath;
    for (int extensionIndex = 0;
         extensionIndex < kProfileSidecarExtensionCount;
         ++extensionIndex) {
        const wchar_t* extension =
            kProfileSidecarExtensions[extensionIndex];
        FormatWide(sidecarPath, L"%s/%s.%s", usersDir, localPlayerName.c_str(), extension);
        if (!FileExists(sidecarPath.c_str())) {
            continue;
        }

        WideString commandLine;
        FormatWide(commandLine, L"FaceRipper.exe %s", sidecarPath.c_str());

        STARTUPINFOW startupInfo = { 0 };
        PROCESS_INFORMATION processInfo = { 0 };
        startupInfo.cb = sizeof(startupInfo);
        if (CreateProcessW(
                NULL,
                const_cast<wchar_t*>(commandLine.c_str()),
                NULL,
                NULL,
                FALSE,
                CREATE_NEW_CONSOLE,
                NULL,
                NULL,
                &startupInfo,
                &processInfo)) {
            WaitForSingleObject(processInfo.hProcess, kFaceRipperWaitMs);
        }
        break;
    }

    WideString jpfPath;
    FormatWide(jpfPath, L"%s/%s.jpf", usersDir, localPlayerName.c_str());
    if (!FileExists(jpfPath.c_str())) {
        FormatWide(jpfPath, L"./users/%s.jpf", localPlayerName.c_str());
        if (!FileExists(jpfPath.c_str())) {
            SendProfileRefreshPacket(NULL, 0, false);
            return;
        }
    }

    FILE* file = OpenBinaryFile(jpfPath.c_str());
    if (file == NULL) {
        SendProfileRefreshPacket(NULL, 0, false);
        return;
    }

    unsigned char ignoredHeader[4];
    fread(ignoredHeader, 1, sizeof(ignoredHeader), file);
    fseek(file, 0, SEEK_END);
    unsigned int jpfSize = static_cast<unsigned int>(ftell(file));

    if (jpfSize >= kMaxProfileJpfBytes) {
        fclose(file);
        SendProfileRefreshPacket(NULL, 0, false);
        return;
    }

    AutoBuffer<unsigned char> packetBytes;
    packetBytes.Allocate(10010);

    int cursor = 0;
    PacketBufferAppendUInt8(kProfileRefreshOpcode, packetBytes.Data(), &cursor);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(jpfSize),
        packetBytes.Data(),
        &cursor);

    fseek(file, 0, SEEK_SET);
    cursor += static_cast<int>(fread(packetBytes.Data() + cursor, 1, jpfSize, file));
    fclose(file);

    ImageDrawContext decodedImage;
    InitializeImageDrawContext(&decodedImage);
    DecodeJpfImageToTileContext(packetBytes.Data() + 3, jpfSize, &decodedImage);

    const bool hasExpectedPortraitBounds =
        decodedImage.bounds.Width() == kProfilePortraitWidth &&
        decodedImage.bounds.Height() == kProfilePortraitHeight;

    if (hasExpectedPortraitBounds) {
        PacketBufferAppendWideStringAsAnsi8(
            g_pConfig->userProfile.selectedProfileName,
            packetBytes.Data(),
            &cursor);
    } else {
        cursor = 1;
        PacketBufferAppendUInt16BE(0, packetBytes.Data(), &cursor);
        PacketBufferAppendWideStringAsAnsi8(
            g_pConfig->userProfile.selectedProfileName,
            packetBytes.Data(),
            &cursor);
    }

    QueueAndSendPacket(g_packetSender, packetBytes.Data(), cursor);
    DestroyImageDrawContext(&decodedImage);
}
```

- UID0001AS H formal insertion text: blank on the method page because the complete UID00007Q class declaration is the sole declaration owner.
- UID00007Q formal migration: move its existing complete `RECONSTRUCTION_CPP CODE` payload byte-for-text into `RECONSTRUCTION_H CODE`, clear the CPP payload, and insert `void RefreshSelectedProfileData();` once in the private helper declaration group. Do not duplicate or partially restate the class.
- UID00027P formal CPP remains its exact existing file-local `kProfileSidecarExtensions` array. H remains blank.
- UID0003IV formal CPP/H remain blank because exact bytes are generated by the above source literals/table and must not be duplicated.
- The target code preserves exact behavior: internal helper call selects `g_activeMapPane`, the x86 compiler can load it into ECX and perform a tail jump to the MapPane member.
- The shape is plausible mid-2000s C++03: namespace-scope internal helpers, `NULL`, explicit loops, Win32 APIs, and class member syntax; no IDA labels, raw addresses, invented modern language constructs, or decompiler temporaries remain.
- Naming convention: `g_` prefix for established external global, PascalCase methods consistent with MapPane/ProfileDialog docs, `k` prefix for file constants, and lower camel-case locals.

## Final Recommendation

- The exact target metadata/body and full support-route corrections accepted at Gate 1 are applied in ordinary docs and serially validated.
- UID0001DU remains separate and emits through UID0000MR at deterministic source position 40.
- UID0001AS has UID00007Q owner/emitter with its complete member body; every accepted behavior and negative fact is preserved.
- UID00027P has UID0000L3 owner/emitter, position 1, and the exact table CPP.
- UID0003IV has UID0000L3 owner, `RECONSTRUCTABLE:FALSE`, blank emitter and formal code because source literals regenerate it.
- ProfileDialog action/class/file/item docs and ProfileStorage/meta docs carry the accepted report-level detail and corrected historical assumptions without pruning.
- UID00007Q's complete declaration is in H and contains the member declaration once; generated command `18248` verifies the one-definition topology.
- Supervisor Gate 2A, Gate 2B, saved-IDB/catalog, and manual coverage application/verification are complete. B005 did not perform those supervisor-owned stages. Only the supervisor's final exact-artifact review and execute/archive lifecycle remain.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md`.
- Applied metadata: `COMPLETION:93`, `CONFIDENCE:95`, `CANONICAL_OWNER:0000MR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MR`, `EMITTER_POSITION_OPTIONAL:40`.
- Applied CPP: exact `namespace { void RefreshProfileData() ... }` formal block. H remains blank with explicit file-local proof.
- Applied Item Summary: `Exact retained ProfileDialog.cpp refresh helper that loads established MapPane *g_activeMapPane and tail-forwards to MapPane::RefreshSelectedProfileData; exact 11-byte body, padding fences, exhaustive no-route result, inferred inlined-call source cause, one-definition topology, and source-quality IDA handoff are complete.`
- Applied detail includes exact bytes, two-instruction disassembly, absent xrefs/pointers/vtable route, global prestate, callee member proof, comparable forwarding shape, static-vs-member ranking, padding, score rationale, generated expectations, and historical correction.
- The old ProfileStorage/free-cdecl conclusion is preserved only as dated corrected history with the receiver evidence that supersedes it.
- Current target SHA is `EB66DAD1C2B5577893E11888FA1B42E6D6D7FAEE31CC826A92AAFC61D4AC0841`; scoped validator `000000018187` passed `exit 0`, `ok 1`.

## Recommended Support Doc Changes

All accepted support recommendations below are now applied in ordinary docs. The imperative wording records the accepted Gate 1 contract; the callback result and exact validators are recorded in the ledger, Validator Results, and Changed Files sections.

- `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md` UID0001AS: set `92/94`, owner/emitter UID00007Q, member CPP above, H blank because UID00007Q owns the declaration; preserve the full behavior, table, strings, callers, bytes, padding, and source-era rationale; historicalize cdecl/ProfileStorage claims.
- `by-class/MapPane.md` UID00007Q: keep `93/94`, migrate complete class declaration CPP-to-H byte-for-text, add private `void RefreshSelectedProfileData();`, add exact caller/optimized-this/source-route evidence, and preserve exact 0x910 layout/all unrelated methods.
- `by-file/MapPane.md` UID0000L3: keep `92/92`; add UID0001AS/UID00027P/UID0003IV source route, complete dependencies/includes, physical code/data placement, and no-duplicate generated topology.
- `by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md` UID00027P: keep `90/93`, change owner/emitter to UID0000L3, retain position 1/table CPP, and replace ProfileStorage ownership with sole MapPane member-consumer evidence.
- `by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md` UID0003IV: set `90/94`, owner UID0000L3, `RECONSTRUCTABLE:FALSE`, blank emitter/position/CPP/H; populate Item Summary and add covered-by source-literal rationale while preserving exact strings/range/consumer evidence.
- `by-file/ProfileStorage.md` UID0000MS: set `89/90`; preserve all load/save/import and sidecar semantic detail, remove UID0001AS/table/string from current proposed contents, add MapPane cross-module source route, and retain prior ProfileStorage ownership as corrected history.
- `by-meta/client_profile_storage.md` UID0001QL: preserve full profile storage contract and sidecar behavior; correct method/table/string implementation source to MapPane.cpp and dialog trigger to ProfileDialog.cpp.
- `by-class/ProfileDialog.md` UID0000AU: set `88/90`; describe UID0001DU as file-local source support, `g_activeMapPane`, and MapPane member call; do not claim ProfileDialog owns the sidecar body.
- `by-file/ProfileDialog.md` UID0000MR: set `90/92`; add exact target helper body/position, inlined-equivalent action path, corrected MapPane dependency, generated topology, and historical ProfileStorage boundary correction.
- `by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md` UID0004E2: set `89/92`; state direct `g_activeMapPane->RefreshSelectedProfileData()` behavior and preserve unresolved callback/field-name limits.
- `by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md` UID0000V9: set `89/93`; distinguish source helper from compiler destructor wrappers, use current names/owners, and preserve every exact thunk/destructor range.
- UID0001DT, UID0004E0, UID0004E1, and UID00038G: inspect during callback for stale current ProfileStorage/helper wording; update only affected links/prose, preserve their independent metadata/code unless exact contradiction requires repair.
- `by-global/g_activeMapPane.md` UID0000PR and `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md` UID0001OW: no metadata/code change; add target/callee cross-links only if absent without duplicating their existing evidence.

## Score And Metadata Recommendation

- UID0001DU assignment-time state was `86/92`, owner/emitter UID0000MR, true, blank position/CPP/H. Applied state is `93/95`, same owner/emitter/true, position 40, exact CPP, blank H.
- UID0001AS assignment-time state was `88/91`, owner/emitter UID0000MS. Applied state is `92/94`, owner/emitter UID00007Q, exact member CPP, blank method H.
- UID00027P assignment-time state was `90/93`, owner/emitter UID0000MS, position 1. Applied state keeps the score/position/CPP and changes owner/emitter to UID0000L3.
- UID0003IV assignment-time state was `87/92`, owner/emitter UID0000MS, true. Applied state is `90/94`, owner UID0000L3, false, blank emitter/position/CPP/H.
- Applied support scores are UID0000MR `90/92`, UID0000AU `88/90`, UID0004E2 `89/92`, UID0000V9 `89/93`, and UID0000MS `89/90`. UID00007Q and UID0000L3 remain `93/94` and `92/92`.
- Reason target is higher: every assigned binary, global, helper role, reachability, source placement, emitter, formal C++, and IDA blocker has a concrete resolution and destination.
- Reason target is not above 95 confidence: the stripped binary cannot prove original lexical spelling or conclusively distinguish a file-local static helper from a nonvirtual ProfileDialog member whose only local call was inlined.
- Reason target is not lower: behavior and routing are exact, the global is proven, no range/split ambiguity remains, the no-route state is exhaustive, and formal human source can reproduce the exact load/tail-forward semantics.
- Score-improvement result: raw global blocker resolved from current IDA/global docs; callee owner/calling-convention blocker resolved from all callers; source visibility blocker resolved by ranked static/member analysis; no-xref blocker exhausted through all route classes; empty-emitter blocker resolved with formal CPP; one-definition blocker resolved across ProfileDialog/MapPane/ProfileStorage. The fully specified IDA handoff is now applied, read back, saved, and cataloged by the supervisor.

## Open Questions With Attempted Resolution

- Was UID0001DU originally `static` or a private nonvirtual ProfileDialog member? Evidence checked: all xref classes, body, action-handler sequence, ProfileDialog physical cluster, comparable forwarder, UDT state, and source retention. Resolution: use file-local static because no ProfileDialog receiver survives or is required and it yields valid source without speculative class layout; retain member form as a lower-ranked historical possibility and confidence cap.
- Is UID0001AS cdecl because incoming ECX is unused? Evidence checked: every caller window and the callee's first ECX use. Resolution: no. Source ABI is a MapPane member; optimization erased `this` use.
- Does profile-sidecar behavior prove ProfileStorage.cpp ownership? Evidence checked: receiver ABI, code neighborhood, table neighborhood, sole table consumer, current docs. Resolution: no. Keep behavioral cross-links but route implementation to MapPane.cpp.
- Should UID0001DU be non-emitting because no xref exists? Evidence checked: complete pointer/vtable/immediate/raw-route search and source-equivalent inlining. Resolution: no. It is an exact retained source helper and gets formal CPP.
- Should UID0003IV emit raw data? Evidence checked: literal consumers and proposed source blocks. Resolution: no. The compiler regenerates exact strings from ordinary source literals; emitting a second raw block would duplicate source.
- Does MapPane need a new UDT? Evidence checked: current type database. Resolution: no; exact 0x910 UDT already exists. ProfileDialog UDT remains absent and is unnecessary for the selected target signature.
- Remaining uncertainty: exact original lexical names and access specifiers are unrecoverable from current stripped evidence. Best human names are selected now; no raw `sub_`, `dword_`, or address labels remain in final source. This bounded uncertainty caps confidence but does not block implementation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- B005 inspected and supplied the exact manual coverage payloads below without editing any `-coverage-report.md`. The supervisor subsequently applied and validated them: by-memory command `18342`, SHA-256 `C94BEFADB97CE59FC4CAA023542B1DC2325A73FCED1D4CEE961E2A376B0B61C2`; by-class command `18343`, SHA-256 `DD3061654CC703B4671AE3D21DA3022408637D4421BC3BE6FCF72FCB9B56737A`; by-file command `18344`, SHA-256 `8C5E33B2C11D2774AFCE2FA90BE80B96A760CA29E164FE023CAE4A596B904FF2`; by-item command `18345`, SHA-256 `B97D83BA66BCB975DE6AC4CC56A981026845639A3B437AE4C21B83D39D7D48B8`; and by-meta command `18346`, SHA-256 `ABDCB5CA773A680D44C9A9C3D88190939FE0C2C4EFD9131D9748FDE4B07CDF9C`. The imperative payload wording is retained as historical accepted input, not as pending current work.
- `by-memory/-coverage-report.md` line currently containing UID0001DU: replace with:

```text
    - [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) : reconstructable : 93% : very-strong : Exact retained ProfileDialog.cpp RefreshProfileData helper with an eleven-byte g_activeMapPane load and tail-forward to MapPane::RefreshSelectedProfileData, exhaustive no-route proof, protected padding, natural source C++, corrected MapPane member dependency, one-definition topology, and complete IDA handoff.
```

- `by-memory/-coverage-report.md` current UID0001AS row: replace with:

```text
    - [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) : reconstructable : 92% : very-strong : Source-ready MapPane::RefreshSelectedProfileData member with unanimous MapPane receiver preparation across three callers, optimized-unused this explanation, exact FaceRipper/JPF validation flow, opcode 79 packet behavior, complete C++03 source, protected padding, and corrected table/string ownership.
```

- `by-memory/-coverage-report.md` current UID00027P row: replace with:

```text
    - [UID:00027P][0x0066dd60-0x0066dd78.ImageExtensionPointerTable](by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md) 0x0066dd60-0x0066dd78 | pointer table | ImageExtensionPointerTable : reconstructable : 90% : very-strong : Exact MapPane.cpp file-local five-entry sidecar extension table for bmp, pcx, jpg, jpeg, and pnm; one MapPane::RefreshSelectedProfileData table-base consumer, five-entry loop bound, four-byte zero padding, protected neighbors, and single formal declaration are complete.
```

- `by-memory/-coverage-report.md` has no individual UID0003IV row under UID0002ST. Insert immediately after the UID0002ST row:

```text
            - [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md) 0x0061e964-0x0061e9fc | source-generated string data | ProfileSidecarImageStrings : not_reconstructable : 90% : very-strong : Exact MapPane.cpp sidecar extensions, path formats, FaceRipper command, and JPF fallback literals consumed by MapPane::RefreshSelectedProfileData; source literals regenerate the bytes, so no duplicate raw-data emitter is used.
```

- UID0004E2 currently has no individual manual by-memory row under UID0001DT. No insertion is recommended solely for this support wording/score repair because the manual report currently represents that exact child family through UID0001DT; supervisor may refresh the parent row if current policy changes.
- `by-class/-coverage-report.md` UID0000AU row: replace with:

```text
- [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md) : reconstructable : 88% : strong : ProfileDialog class with exact constructor/destructor/action split, retained file-local RefreshProfileData helper context, established g_activeMapPane dependency, corrected MapPane::RefreshSelectedProfileData call, vtable/caller evidence, and preserved callback/layout confidence limits.
```

- `by-file/-coverage-report.md` UID0000MR row: replace with:

```text
- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md) : reconstructable : 90% : very-strong : ProfileDialog.cpp source root with exact split children, retained RefreshProfileData forwarding helper, g_activeMapPane-to-MapPane member route, inlined-equivalent accept path, deterministic one-definition source order, generated-empty-marker closure plan, and preserved independent constructor/action/destructor work.
```

- `by-file/-coverage-report.md` UID0000MS row: replace with:

```text
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) : reconstructable : 89% : strong : Profile persistence source root for modern .usr load/save and legacy .cfg import with complete section/layout/failure behavior; selected-profile sidecar semantics remain documented, while live receiver and source-neighborhood evidence corrects RefreshSelectedProfileData, its extension table, and literals to MapPane.cpp ownership.
```

- `by-item/-coverage-report.md` UID0000V9 row: replace with:

```text
- [UID:0000V9][ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90](by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md) : reconstructable : 89% : very-strong : Exact ProfileDialog destructor/thunk and retained refresh-helper index separating source destructor coverage, compiler scalar/adjustor wrappers, file-local RefreshProfileData, established g_activeMapPane, and the MapPane::RefreshSelectedProfileData dependency with complete boundaries and historical ownership correction.
```

- `by-meta/-coverage-report.md` UID0001QL row: replace with:

```text
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md) : reconstructable : 50% : medium : Complete modern .usr and legacy .cfg profile-storage contract with exact sections, optional-tail/migration and failure behavior; selected-profile sidecar/JPF/opcode-79 semantics remain complete, with implementation ownership corrected to MapPane.cpp and the ProfileDialog.cpp trigger helper documented separately.
```

- UID00007Q, UID0000L3, UID0000PR, and UID0001OW manual rows remain valid at their current scores. Their descriptions may be extended during supervisor application, but no exact replacement is required for score/path/state correctness.

## Follow-Up Actions

- Ordinary implementation callback is complete, and independent supervisor Gate 2A claim verification passed through commands `18325`-`18341`.
- Supervisor Gate 2B is complete on IDB `5a570ede`: both exact function rename/type/comment actions passed readback, the global and four protected padding items remained unchanged, and the saved mutation is catalog entry `0337`.
- Exact manual coverage is `APPLIED_VERIFIED` through commands `18342`-`18346` and the five recorded coverage hashes. B005's foreground generated command `18248` remains the accepted topology checkpoint.
- Supervisor only: perform the final exact-artifact review, then execute/archive the report. No further research, ordinary implementation, IDA, or coverage work is pending.
- No separate A-agent action is needed. No further B-agent research is required unless Gate 1 identifies a literal missing prestate or contradictory current document.

## Confidence

- Recommendation confidence: very strong for disposition and ownership correction; strong for target static-helper source shape.
- Score confidence: high for target `93/95`, callee `92/94`, and unchanged table `90/93`; moderate-high for support aggregate score increments because they retain independent unresolved work.
- Remaining uncertainty: stripped original spellings/access specifiers and target static-versus-nonvirtual-member source form. The selected names are realistic human source names and no finalized code retains reverse-engineering labels.

## Validator Results

- Every changed ordinary by-* page passed a serial scoped command from `source-3/project-documentation`; each command exited `0` with `ok: 1`.

| Command ID | Timestamp | Scoped file | Result |
| --- | --- | --- | --- |
| `000000018187` | `2026-07-28T13:20:29-04:00` | `by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md` | exit 0 / ok 1 |
| `000000018193` | `2026-07-28T13:21:53-04:00` | `by-memory/0x0053f940-0x0053fe87.ProfileDialog.md` | exit 0 / ok 1 |
| `000000018199` | `2026-07-28T13:22:47-04:00` | `by-class/ProfileDialog.md` | exit 0 / ok 1 |
| `000000018204` | `2026-07-28T13:23:48-04:00` | `by-file/ProfileDialog.md` | exit 0 / ok 1 |
| `000000018208` | `2026-07-28T13:24:29-04:00` | `by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md` | exit 0 / ok 1 |
| `000000018211` | `2026-07-28T13:25:12-04:00` | `by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md` | exit 0 / ok 1 |
| `000000018213` | `2026-07-28T13:25:40-04:00` | `by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md` | exit 0 / ok 1 |
| `000000018217` | `2026-07-28T13:27:06-04:00` | `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md` | exit 0 / ok 1 |
| `000000018221` | `2026-07-28T13:31:16-04:00` | `by-class/MapPane.md` | exit 0 / ok 1 |
| `000000018223` | `2026-07-28T13:32:35-04:00` | `by-file/MapPane.md` | exit 0 / ok 1 |
| `000000018228` | `2026-07-28T13:33:35-04:00` | `by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md` | exit 0 / ok 1 |
| `000000018236` | `2026-07-28T13:34:31-04:00` | `by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md` | exit 0 / ok 1 |
| `000000018242` | `2026-07-28T13:36:08-04:00` | `by-file/ProfileStorage.md` | exit 0 / ok 1 |
| `000000018244` | `2026-07-28T13:37:25-04:00` | `by-meta/client_profile_storage.md` | exit 0 / ok 1 |
| `000000018246` | `2026-07-28T13:38:11-04:00` | `by-global/g_activeMapPane.md` | exit 0 / ok 1 |
| `000000018247` | `2026-07-28T13:38:52-04:00` | `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md` | exit 0 / ok 1 |

- Foreground generated refresh command `000000018248`, timestamp `2026-07-28T13:39:55-04:00`, was a scoped `by-file/ProfileDialog.md` validator with `--wait-generated`; it exited `0`, reported `ok: 1`, and completed generated refresh.
- Current generated verification: ProfileDialog.cpp has UID0001DU exactly once, zero target empty markers, and five unrelated retained markers; MapPane.cpp has UID0001AS exactly once, UID00027P exactly once, no UID0003IV marker, and five unrelated retained markers; MapPane.h has one class/member declaration and zero empty markers; ProfileStorage.cpp has zero UID0001AS/UID00027P/UID0003IV routes.
- Validator warnings on MapPane pages were unrelated pre-existing missing-reference rows; command `18236` registered UID0003IV and all commands still returned `ok: 1`. B005 did not edit validator state manually.
- Independent supervisor Gate 2A revalidation passed through commands `18325`-`18341`; every callback ordinary-document claim and destination was accepted. These are supervisor verification commands and do not replace or erase the original B005 command history above.
- Supervisor manual coverage validation also passed: `18342` by-memory, `18343` by-class, `18344` by-file, `18345` by-item, and `18346` by-meta. Their exact post-validation hashes are recorded in Changed Files.

## Changed Files

- The report remains at `tools/leaser/Agents/Agent-B005/research/0001DU-ProfileDialogRefreshHelper-empty-emitter-source-quality.md` and is reconciled in place after this callback.
- Changed ordinary docs and post-validator SHA-256 values:

| Path | SHA-256 |
| --- | --- |
| `by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md` | `EB66DAD1C2B5577893E11888FA1B42E6D6D7FAEE31CC826A92AAFC61D4AC0841` |
| `by-memory/0x0053f940-0x0053fe87.ProfileDialog.md` | `36BE2D2B216FB20DB060BFFCE5ECF6A286D5BC94606C5955D212593057AFB058` |
| `by-class/ProfileDialog.md` | `EB5500328C7DB212014551050090C12193B17B5A1CD1CD566AF52B3CE5D9FBFD` |
| `by-file/ProfileDialog.md` | `D25E57BED52DD535177F7239D321ED2D7733984B8A2CC0B49D0CF140306CF6F4` |
| `by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md` | `D90068DB504CA76C93CD9998E05849843BAC32D2180CC093549D3F34D4C52155` |
| `by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md` | `D978A78F9A69C34F27ED092307D736B27D6C9B4AD61A5ED9D7E28686232549C5` |
| `by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md` | `378D5D160C3F49333A8E9EA010FBD830BE23C2F8D29E425A2DA8DA7BD179F2D5` |
| `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md` | `F15A2EFF64EEE3243CD35E76559892BA014972C8BB234E666B85CC7C57268699` |
| `by-class/MapPane.md` | `58BF5AA2AC9F6CA446628964985561836A71B5374FC13F159B0E474B22B5DACE` |
| `by-file/MapPane.md` | `855680B2F71E9408D81A6269D7E8A6D9E56E31F56896FFD7F319924406AB5AF0` |
| `by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md` | `4AB28AC4231F09C68EAE7D9CD1C25279F1E9C10E0E589DC2FC2B626DAA7CB2AC` |
| `by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md` | `C93DD9D12A7677F30D2649EE16824EC153B0D751180B8C2B1A5C023B20DE003D` |
| `by-file/ProfileStorage.md` | `890B7F1E0EDF6823A35007DBA461701E6E683948D0E89191ED3D5226E7DCE097` |
| `by-meta/client_profile_storage.md` | `09F7E65D7A194F8AEF22F15465C70BDB38A20920C6D9C59E426B5321A7FED838` |
| `by-global/g_activeMapPane.md` | `6D84A04CC9AFAFDA3D743C2718C15949A74DA8FA64D30637DFE4C2046E35BFE0` |
| `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md` | `5A536A9B355A560761B6B977B8C029561750C7665A423BEA845E8E538AAC1040` |

- UID0004E1 and UID00038G were inspected and not edited because they contained no stale current ProfileStorage/helper route. UID0001DT and UID0004E0 required bounded current-prose corrections and are included above; their independent metadata/formal code remain unchanged.
- All leases were acquired only immediately before each ordinary edit/validator batch and released immediately afterward. `current_leases.md` shows no active lease.
- B005 did not edit any manual coverage or generated file directly, mutate IDA, edit audit/catalog/tracker/supervisor/lifecycle/validator state, move/archive the report, or run/probe/dry-run `execute_report` or any report-lifecycle command.
- Supervisor-owned artifacts reconciled by this report-only update, without B005 modifying them:

| Supervisor-owned artifact/state | Command / identity | Verified current result |
| --- | --- | --- |
| Gate 2A ordinary callback verification | `18325`-`18341` | `GATE2A_PASSED` |
| IDB prestate backup | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0001DU-prestate-20260728-151308` | preserved before Gate 2B |
| Saved IDB | session `5a570ede`, catalog `0337` | SHA-256 `823941722288F7B2BAAE0E9B2923B22B0505DCFFD28C33990F25E4A45399083D`; 143190099 bytes; mtime `2026-07-28T15:13:45.2018477-04:00` |
| `by-memory/-coverage-report.md` | `18342` | SHA-256 `C94BEFADB97CE59FC4CAA023542B1DC2325A73FCED1D4CEE961E2A376B0B61C2` |
| `by-class/-coverage-report.md` | `18343` | SHA-256 `DD3061654CC703B4671AE3D21DA3022408637D4421BC3BE6FCF72FCB9B56737A` |
| `by-file/-coverage-report.md` | `18344` | SHA-256 `8C5E33B2C11D2774AFCE2FA90BE80B96A760CA29E164FE023CAE4A596B904FF2` |
| `by-item/-coverage-report.md` | `18345` | SHA-256 `B97D83BA66BCB975DE6AC4CC56A981026845639A3B437AE4C21B83D39D7D48B8` |
| `by-meta/-coverage-report.md` | `18346` | SHA-256 `ABDCB5CA773A680D44C9A9C3D88190939FE0C2C4EFD9131D9748FDE4B07CDF9C` |
- This final reconciliation changes only this same report; all ordinary, generated, coverage, IDA, audit, catalog, validator, goal, notes, and lifecycle artifacts were read as supervisor-supplied facts and not modified by B005.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact SHA `84B3B003FD1590F3A4ED0AD6F0DA78DDB93F0F68824FFCFBE3E1DF7852AF6844` before implementation.
- [x] Target/support docs to update: UID0001DU, UID0000MR, UID0000AU, UID0001DT current links/history as needed, UID0004E0/UID0004E1/UID0004E2 current dependency prose as needed, UID00038G current links/history as needed, UID0000V9, UID0001AS, UID0000MS, UID00007Q, UID0000L3, UID00027P, UID0003IV, UID0001QL, and optional cross-links in UID0000PR/UID0001OW.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: no additional target UID declared; support UIDs are individually ledgered.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply are exact.
- [x] Score-limiting blockers researched to a concrete high-probability resolution; no future-investigation placeholder remains.
- [x] Owner/emitter/reconstructable changes to apply are exact.
- [x] Split/rename/new-child changes to apply: no target split/new child; exact source/IDA renames and UID0003IV reclassification recorded.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment changes are fully specified.
- [x] Supervisor Gate 2B applied and read back both exact function name/type/comment actions, preserved `g_activeMapPane` and four padding fences, saved IDB SHA `823941722288F7B2BAAE0E9B2923B22B0505DCFFD28C33990F25E4A45399083D`, and cataloged entry `0337`; B005 did not perform these supervisor-owned actions.
- [x] First-draft CPP block text/no-code proof and H block text/no-header-code proof are supplied.
- [x] Third-party import directive confirmed not applicable; this is NexusTK project code, not a vetted third-party embed.
- [x] Exact target/support doc facts to incorporate are supplied at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve are identified.
- [x] Wave2/Wave3 mentions encountered in historical material and ignored as stale process artifacts.
- [x] Open questions are resolved to best-supported source forms with bounded lexical uncertainty and score impact.
- [x] Validators to run after acceptance are identified; none were run in report-only phase.
- [x] Generated refresh expectations and exact manual supervisor-owned coverage text are supplied.

Implementation callback pass:
- [x] Supervisor-owned IDA changes are `APPLIED_VERIFIED` on IDB `5a570ede`; exact readback, backup, saved hash/size/mtime, protected-item state, and catalog entry are reconciled above.
- [x] Report accepted by supervisor for implementation at exact Gate 1 SHA `84B3B003FD1590F3A4ED0AD6F0DA78DDB93F0F68824FFCFBE3E1DF7852AF6844`.
- [x] All accepted target/support ordinary-doc details incorporated at report-level detail.
- [x] Primary UID0001DU and every support UID verified independently against the ledger and destination docs; UID0004E1/UID00038G were correctly unchanged after current-content inspection.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/position/CPP/H and UID00007Q CPP-to-H migration applied exactly; no split/new child was required.
- [x] Historical/stale assumptions, rejected alternatives, range/padding facts, and negative evidence preserved.
- [x] Open questions remain resolved to the accepted high-probability source forms with only bounded lexical uncertainty.
- [x] Serial scoped validators `18187` through `18247` ran for every changed ordinary page; all exited 0 with ok 1.
- [x] Foreground generated refresh/readback command `18248` verifies the expected ProfileDialog/MapPane/ProfileStorage one-definition and empty-marker topology.
- [x] Supervisor Gate 2A commands `18325`-`18341`, Gate 2B IDA readback/save/catalog, and manual coverage commands `18342`-`18346` are complete and reconciled claim by claim.
- [ ] Supervisor-only final exact-artifact execute/archive lifecycle remains pending.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000018349","destination_path":"executed-b-agent-research/B005/0001DU-ProfileDialogRefreshHelper-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001DU-ProfileDialogRefreshHelper-empty-emitter-source-quality.md","timestamp":"2026-07-28T15:24:40-04:00","uid":"0001DU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
