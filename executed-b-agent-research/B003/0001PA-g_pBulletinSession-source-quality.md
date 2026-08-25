** TARGET-REPORT-UID:0001PA **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0001PA g_pBulletinSession Source-Quality Report

## Finalized Report / Current Recommendation

The accepted implementation callback is complete. [UID:0001PA] is now the exact `92/94` false/non-emitting four-byte loader-zero physical slot in the virtual tail of `.data`, with semantic owner [UID:0000QG], blank emitter/optional position, retained `Nested:-4`, a physically blank R0 formal, and its exact no-duplicate proof retained in prose. [UID:0000QG] is now the sole externally linked C++03 position-0 definition, `BulletinSession *g_pBulletinSession = 0;`, emitted through [UID:0000HX]. The historical dual-emitter and `0xffffffff` sentinel conclusions are preserved only as rejected provenance.

Fresh RTTI proves `BulletinSession : public DialogSession, public Singleton<BulletinSession>`. The direct empty Singleton base has PMD `+0x100/-1/0` and overlaps the source byte at `+0x100` through MSVC EBO. That compiler/source fact supersedes handwritten `g_pBulletinSession = this` and `g_pBulletinSession = NULL` in the constructor/destructor drafts: direct Singleton construction/destruction generates publication and clearing, including unwind and scalar-wrapper paths. The complete R2 declaration uses `m_pendingListResponse` at `+0x100`, natural padding at `+0x101`, and `unsigned short m_activeListId` at `+0x102`, closing exact size `0x104`.

The callback registered two exact children without guessed UIDs. [UID:0004US] is `0x005a50a0-0x005a5103.EnsureNormalBulletinSession`, a `90/93` source-ready externally linked UserPane/local-player helper with four direct callers, exact R6, and validator-valid first-child `Nested:4`; following UID0002RX is `Nested:0`. [UID:0004UT] is exact `0x00613b1c-0x00613ba4.BulletinSessionVtableData`, `92/94` false/non-emitting compiler data with a physically blank R7 formal, full no-array proof in prose, and first-child `Nested:4`; following UID0002MI is `Nested:0`. [UID:0004FY] now emits exact R5 `HandlePacketEvent(Event *)`, and [UID:0003Q4] is false/non-emitting compiler deleting-wrapper support with a physically blank R8 formal and full wrapper proof in prose. C01-C20 and all 48 callback checklist rows are terminal and proven below.

B003 changed the 18 ordinary destinations listed under Changed Files using one-file lease/reread/edit/scoped-validator/release cycles. Validators generated current source/tracker state and made their recorded owned side effects; B003 did not manually edit manual coverage, generated/tracker, audit/supervisor, validator-state, IDA, lifecycle, or archive files. B003 ran no `execute_report`, report probe/count, move/archive, or lifecycle command. Exact later validation, path, count, execution, and archive state remains external supervisor/validator-owned state and is not asserted by this artifact.

## Supporting Research

Implemented destinations at the final ordinary readback:

| UID | Path | SHA256 | Bytes / lines | Current role |
| --- | --- | --- | --- | --- |
| 0001PA | `by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md` | `6EA66C96FE9F2DCFDF2BEB255F51D7B8F6D4663AF921592B9CA282155871E364` | 9,117 / 69 | implemented `92/94`, false/no-emitter with physically blank R0 formal; loader-zero and full xref/source-route/no-duplicate proof remain in prose |
| 0000QG | `by-global/g_pBulletinSession.md` | `F1797D3F427E9A785825EB02FF1F76CFA1277DA042A4A54D13D476BEE04BAA8E` | 9,406 / 81 | implemented `92/94`, position-0 sole definition R1 |
| 00001D | `by-class/BulletinSession.md` | `0224D9C46639757EABCF610276EC673B2A2A961AC0CBBFCE15C3D1408EE92F7B` | 40,503 / 199 | implemented `92/94` complete R2 class, Singleton/EBO/extern/type closure |
| 0000HX | `by-file/BulletinSession.md` | `CFEF643566E64BA32E9ADEE03AA345D8DE4897D0F8F15F41844A3D9A456846C8` | 36,889 / 149 | implemented `91/93` no-loss `BulletinSession.cpp` source/compiler union |
| 0000ZH | `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md` | `38ACFAB47655E4DE5D13A5118E0EAFEF9187DDE9B0D719F49FC8B17908D82146` | 36,750 / 135 | unchanged `88/91` false split index with synchronized full 17-child source/compiler inventory |
| 0004FS | `by-memory/0x00471150-0x0047126c.BulletinSessionConstructor.md` | `9AF3D719E88E074E3C49CE54A8E820B9473290B2F968EFD87145A18DA2F20704` | 11,202 / 105 | implemented `91/94` R3 with implicit publication and unified fields/types |
| 0004FT | `by-memory/0x00471270-0x00471299.BulletinSessionCleanup.md` | `7E5D5D43294B26D0AB9B5BF0AB316FDE5A0F37972E7E0C02B7D5141B9D5DA4C8` | 8,374 / 71 | implemented `91/94` authored-empty R4 with implicit reverse Singleton clear |
| 0003Q1 | `by-memory/0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear.md` | `D94EA652EE9917201EE7369D7BECA67D846EBE60C957611F246A5AE913B3E095` | 2,448 / 45 | already false compiler unwind clear; verify-only |
| 0003Q4 | `by-memory/0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor.md` | `D522B58214623D47362F7DD04ADE8EE40FF1BE0710C4DC83D0589E971A86636E` | 8,857 / 80 | implemented `92/94` false/no-emitter compiler wrapper with physically blank R8 formal and prose no-code proof |
| 0004FY | `by-memory/0x00471480-0x004714a3.BulletinSessionPacketForwarder.md` | `5A48F0DE01407B7BCD5981090A045DF9B2666D85CD76C0CE1E22A15506E46BF2` | 9,938 / 94 | implemented `92/94` class-emitted `HandlePacketEvent(Event *)` R5 |
| 0004US | `by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md` | `B90659CC6AE6335984DA3EC4F73C89D79F1580EF741763D1976A423D4740FBCE` | 7,904 / 90 | registered `90/93` UserPane-emitted helper R6, `Nested:4` |
| 0001KL | `by-memory/0x005a2530-0x005b8395.UserPane.md` | `151BA81756A0A35C9CEC7E765055458CADE4EB2D05BDF6FE4850F4704133DAD9` | 56,536 / 309 | unchanged `91/93` broad UserPane union plus exact helper support |
| 0001KM | `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `7F0DD0AEBDE7F4199DD66DF421B70211C9BCB9D6EDFBA46F364B712B47F9933F` | 144,399 / 617 | unchanged `90/92` false extension index plus helper support |
| 0001KO | `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` | `2756EC07C39B63B3245B1292EE3616D84925A0D5756D0E1E38C7EB67A14D2BF9` | 17,586 / 135 | unchanged `86/88` false index, now inventories UID0004US as non-say source |
| 0002RX | `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md` | `15463F9BC9B380F96A181B905E749A730CCD3E3DB038AB09CA7628D97D8CF9A1` | 12,010 / 142 | score/route/formal unchanged; only `Nested:4 -> 0` plus predecessor history |
| 0000P1 | `by-file/UserPane.md` | `DEF087A16BF5B2F19A23DE9AD1053ABFD7BE0CDBAADC8C5C4763E10EAD3787FB` | 108,856 / 445 | unchanged `93/94` full shared union plus exact R6 source route |
| 0004UT | `by-memory/0x00613b1c-0x00613ba4.BulletinSessionVtableData.md` | `878879115B21E10AB1CF8A921025493E35C04B82A3021A262EDBEB773D358766` | 7,814 / 80 | registered `92/94` false/no-emitter compiler data with physically blank R7 formal, prose no-array proof, and `Nested:4` |
| 00024W | `by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md` | `43F067548C9BE4BAFA9CE105E96E026613D3080414A7A0E4DE4ACDC9F98BC9C6` | 15,710 / 105 | unchanged `85/91` false mixed index with exact UID0004UT child |
| 0002MI | `by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md` | `39565580B1467803786834F52CCFA5A056FE51EC0F20764CD1EE97FCC79E96AF` | 16,601 / 152 | score/route/formal unchanged; only `Nested:4 -> 0` plus predecessor evidence |

Historical-report searches used the exact terms `UID0001PA`, `0001PA`, `0x0067adc0`, `g_pBulletinSession`, `dword_67ADC0`, `unk_67ADC0`, `0xffffffff`, `EnsureBulletinSession`, `EnsureNormalBulletinSession`, and `0x005a50a0`.

| Root | Exact outcome and target-specific classification |
| --- | --- |
| `executed-b-agent-research/**` | No dedicated executed UID0001PA report. Relevant leads were B003 UID0004FS constructor, B004 UID0004FT cleanup, B005 UID0004FU screen dimmer, B004 UID0004FY packet forwarder, B009 UID0003Q4 scalar wrapper, B012 UID0000ZH core, B001 MailDialogs/unwind split, B006 adjustor/alert family, B002 ParcelPane/IconsPane consumers, B003 UserPane key handler, B004 UserPane panel-switch handler, and B012 IconsPane raw dispatch. Their target-local bytes/callers were revalidated; their explicit constructor/destructor global writes are historical source-shape conclusions superseded by current direct-Singleton RTTI. Executed B003 UID0001P2 g_pFontImageLib was read as a structural one-definition/Singleton precedent, not copied evidence. |
| `tools/leaser/Agents/Agent-B001/research/**` through `Agent-B005/research/**` | No exact term match in the four active reports present at evidence time; no active same-target report or accepted shared BulletinSession callback was found. |
| `tools/leaser/Agents/Older-Research/**` | No exact term match. |
| `tools/leaser/Agents/SpecialReports/**` | No exact term match. |
| `tools/leaser/Agents/archived/**` | Root absent in the canonical tree; executed history was searched under `executed-b-agent-research/**`. |

The useful historical conclusions are preserved: exact core/child ranges, six constructor calls, 11 global refs, `0x104` allocation, state offsets, EventHandler/TimerHandler facets, vtable views, and compiler wrapper identities. Fresh PE/RTTI evidence supersedes only stale initializer and handwritten-lifecycle conclusions.

## Target

- UID: `0001PA`.
- Path: `by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md`.
- Exact half-open range: `0x0067adc0-0x0067adc4`, size `0x4` / 4 bytes.
- Current IDB bytes: `00 00 00 00`; SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- PE input: `NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes.
- Entity: physical loader-zero storage for externally linked `BulletinSession *g_pBulletinSession`.
- Semantic owner: [UID:0000QG].
- Source route: [UID:0000HX] `NexusTK/ui/dialogs/BulletinSession.cpp` with declaration in `BulletinSession.h`.

## Current Target State

Implemented ordinary state is internally coherent. UID0001PA is `92/94`, owner UID0000QG, `RECONSTRUCTABLE:FALSE`, blank emitter/optional position, a physically blank R0 formal, and retained `Nested:-4`; its current page rejects the old `0xffffffff` assertion using exact loader-zero/no-duplicate proof in prose. UID0000QG is `92/94`, true under UID0000HX at position `0`, with exact R1. UID00001D is `92/94` with complete R2 and class closure before children. UID0003Q4 is `92/94`, false/non-emitting with a physically blank R8 formal and compiler-wrapper proof in prose. UID0004FY is `92/94` with exact class-emitted R5. Issued child UID0004US has exact R6. Issued child UID0004UT has a physically blank R7 formal, full compiler-data proof in prose, and stored `Nested:4`; following UID0002RX/UID0002MI are stored `Nested:0`.

Historical pre-callback generated `BulletinSession.cpp` commands `15604` and external `15609` retained the seven-definition/no-class/explicit-publication/explicit-clear/three-marker defect state; historical `UserPane.cpp` retained calls without an R6 definition. Historical callback commands `15706` and external `15715` first proved the corrected source semantics before the formal-block repair. Final B003 waited command `000000015733`, refreshed `2026-07-21T10:45:13-04:00`, produced `BulletinSession.cpp` SHA256 `36B2AFF423C961E57C859139AA18E449E776329182B9B8A7D2D4406A17ABC1E4`, 5,784 bytes / 167 lines; `UserPane.cpp` SHA256 `C724E2B1B451B84E0E6345F4503AF05EFDD7BE01160F70A160AD59BE093FD503`, 92,016 bytes / 2,784 lines; and `IconsPane.cpp` SHA256 `89985DE03B386850601DFC34BB2A35ACE698CD3390DC7ABD13D0086074134BC8`, 7,839 bytes / 283 lines. BulletinSession has one R1 definition, one extern, a complete class closed before eight qualified definitions, R3/R4/R5 once, only the one source-definition assignment to `g_pBulletinSession`, zero UID0001PA/UID0004UT/UID0003Q4 text, zero Empty Emitter Markers, and no handwritten RTTI/vtable/PMD/adjustor/scalar/EH/cookie/base-teardown output. UserPane has exact R6 once; generated IconsPane retains two calls and generated UserPane retains one modeled call, while the fourth raw caller remains documented binary evidence rather than a duplicate generated source body. Command `15733` is the final callback-time generated checkpoint, not an indefinite lifecycle assertion.

Historical external tracker command `15613` retained pre-callback metadata, while callback command `15708` first captured the implemented union. Latest observed read-only tracker command `000000015716`, refreshed `2026-07-21T10:07:24-04:00`, has SHA256 `612E863B3D135D169A5BB7ABCE4CFB14CBBB22914457AF201D728CE976E401B3`, 1,537,650 bytes / 6,225 lines, and contains real UID0004US/UID0004UT plus the implemented target/class/code/compiler scores and reconstructability states. This is a captured external checkpoint, not an indefinite-current lifecycle assertion.

Supervisor-owned manual coverage is also complete. External supervisor commands `15723` through `15726` applied and validated the exact no-loss by-memory/by-global/by-class/by-file handoff; current root hashes and unique row positions are recorded in the Exact Manual section. B003 did not edit any coverage root.

## Executive Recommendation

Use a three-part one-definition route: false/non-emitting physical UID0001PA, one position-0 semantic definition on UID0000QG, and one matching extern in the complete UID00001D class/header block. Model direct `Singleton<BulletinSession>` inheritance and let compiler-generated base lifetime publish/clear the global. Synchronize constructor/destructor source, promote the Event packet override, add the exact lazy helper under UserPane, create exact BulletinSession vtable-data support, and reclassify the scalar wrapper as compiler-only. Preserve all unrelated core children, raw/no-route helpers, board/mail data, UserPane shared content, padding, and routes.

## Supervisor Active Recheck

- `tools/leaser/Agents/Agent-B003/current_leases.md` shows zero B003 leases after all serial edit/validation cycles.
- No accepted same-target report displaced this callback; all shared UserPane and board/mail destinations were reread after lease acquisition and rebased without loss.
- Every implemented destination hash is listed above. Each ordinary file was leased only for its own reread/edit/scoped validation and released before the next lease.
- Validator registration issued UID0004US first and UID0004UT second. All provisional tokens were replaced before dependent validation; a full report/destination search now finds zero provisional assignment placeholders.
- This report does not assert or direct later validation, report path/count, move/archive, or execution state. Those are external supervisor/validator-owned states.

## Inference Research Guidance Check

The pass did not accept `0xffffffff`, a blank-formal physical emitter, handwritten global lifecycle, incomplete class output, or `needs another pass` as stopping points. It tested PE raw/virtual mapping, all references, six constructor routes, direct Singleton RTTI/PMD/EBO, Event payload/slot order, vtable data, source order/linkage, helper caller ownership, neighboring exact ranges, current docs, current generated output, prior reports, and project one-definition precedents. Remaining uncertainty is limited to original lexical tokens, not behavior, type width, ownership, range, linkage, or formal source disposition.

## Heuristic / Inference Reanalysis And Validation

1. `0x0067adc0` is not raw-backed initialized data. `.data` begins RVA `0x26d000`, virtual size `0x2fe24`, raw size `0xd800`, raw pointer `0x26ac00`. Target RVA `0x27adc0` is delta `0xddc0`, `0x5c0` beyond raw `.data`. The loader supplies zero fill. Applying a raw-offset formula beyond `SizeOfRawData` lands in `.rsrc` and caused the historical false `ff ff ff ff` interpretation.
2. Current IDB bytes are four zeros and every read guard uses null/non-null. No code compares this global to `-1`; `0xffffffff` is rejected as initializer or runtime sentinel.
3. The constructor's odd adjusted-pointer/null fallback is direct Singleton-base lowering. RTTI gives `Singleton<BulletinSession>` PMD `+0x100/-1/0`; the compiler forms the `this+0x100` base, converts it back to the complete object for publication, and retains a null fallback. It is not authored pointer arithmetic.
4. The ordinary destructor's only derived-looking global clear is reverse Singleton-base teardown between derived vtable restoration and `DialogSession` cleanup. Empty authored `~BulletinSession()` is the strongest source form. The unwind clear and scalar wrapper independently corroborate compiler-managed base lifetime.
5. The class hierarchy descriptor has eight entries: `BulletinSession`, `DialogSession`, `Pane`, `GrafPort`, `LObject`, inherited `EventHandler`, inherited `TimerHandler`, and direct `Singleton<BulletinSession>`. EventHandler/TimerHandler remain Pane facets at `+0xa0/+0xa4`, not additional direct BulletinSession bases.
6. Singleton PMD `+0x100` and writes/reads at `+0x100` are compatible through EBO. Source order `bool m_pendingListResponse; unsigned short m_activeListId;` gives byte `+0x100`, natural pad `+0x101`, word `+0x102`, and end `+0x104`. No raw padding member is needed.
7. `m_pendingListResponse` is stronger than constructor-only `m_requestState`: constructor mode 0 and mode 1/subcommand 9 set it; `ActivateScreenDimmer` sets it; dispatcher cases 2/4 test and clear it when creating list dialogs. `m_activeListId` is written from dialog `+0x274` and has exact 16-bit accesses.
8. `0x00471480` is EventHandler packet slot `+0x10`. Current `Event` places `m_payload.m_packet.m_data` at object `+0x0c`; the body tests packet byte `0x31` and forwards to the primary `BulletinSession` dispatcher. Source `HandlePacketEvent(Event *)` naturally removes compiler `this-0xa0` adjustment.
9. `0x005a50a0` is an externally linked UI action helper, not a private class method: four callers span IconsPane, UserPane key handling, and UserPane panel-switch handling. Its address lies in the UserPane local-player helper island, so UserPane.cpp is stronger than BulletinSession.cpp. Its body is exactly a null guard plus `new BulletinSession(1, 0, false)`.
10. The physical target is immediately after the aggregate/children ending at `0x0067adc0`, so current `Nested:-4` correctly exits [UID:0002AI]; it is not a child count. Successor `0x0067adc4` starts a new aggregate/child sequence and is excluded.
11. New helper `0x005a50a0` becomes the first exact child inside the address span of UID0001KO, so it receives `Nested:+4`; following UID0002RX changes `+4 -> 0`. New vtable data becomes the first exact child of UID00024W with `Nested:+4`; following UID0002MI changes `+4 -> 0`.

## Evidence Standards Used

- Fresh read-only IDA MCP against the configured NexusTK IDB.
- Exact bytes, PE section arithmetic, hashes, bounded decompilation, xrefs, function ranges, RTTI/COL/CHD/BCD/PMD values, and vtable dwords.
- Current ordinary docs, generated source, tracker, manual coverage, current leases, and report archives.
- Source/compiler separation based on C++03-era MSVC direct-base/EBO behavior and current project singleton precedents.
- Positive and negative route analysis; raw names and decompiler expressions remain evidence aliases only.
- Destination-ready managed C++ or destination-specific no-code proof, with no code outside formal blocks.

## Evidence Checked

### Live MCP

- Fresh MCP initialize returned client session `aee6c3dc-af4c-43f1-838e-c0c5ed3b2905`.
- Fresh `idb_list` returned active database `9b0396a3`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `15732`.
- `server_health` at `2026-07-21T08:27:00-04:00` returned `status:ok`, module `NexusTK.exe`, image base `0x00400000`, and auto-analysis, Hex-Rays, and strings cache ready with 2,067 cached strings.
- Bounded `get_bytes(0x0067adb0,48)` returned all zeros across the target neighborhood. `lookup_funcs` returned not-a-function for `0x0067adc0` and `0x00613b1c`, and modeled `0x005a50a0` as size `0x63`.
- One malformed initial multi-address decompile request returned a parameter error requiring singular `addr`; it was discarded and is not evidence. Subsequent bounded calls succeeded; no MCP outage occurred.

### Binary, docs, generated, and historical roots

- `xrefs_to(0x0067adc0)` returned exactly 11, `more:false`; `xrefs_to(0x00471150)` returned exactly six constructor callers.
- Decompile/readback covered constructor `0x00471150`, ordinary cleanup `0x00471270`, unwind clear `0x0047e840`, scalar wrapper `0x0047ea90`, MapPane dispatcher `0x00507c90`, compact packet helper `0x00513bb0`, ParcelPane `0x00546610`, lazy helper `0x005a50a0`, UserPane key handler `0x005a5bd0`, and menu-variety handler `0x005bd000`.
- RTTI names/values covered COL `0x006433bc`, CHD `0x006433d0`, eight-entry base array `0x006433e0`, self BCD `0x00643404`, DialogSession BCD `0x00643420`, Singleton BCD `0x00643468`, secondary/tertiary COLs `0x006434b8/0x006434cc`, and type descriptors at `0x00674c64/0x00674ca0`.
- Exact vtable-data candidate `0x00613b1c-0x00613ba4` is `0x88` / 136 bytes, SHA256 `A1B77ACF81E70E3D7E0178D68A4209EB2FEF38108A7CF3150FED3F91835DF3AA`.
- Exact lazy helper `0x005a50a0-0x005a5103` is `0x63` / 99 bytes, SHA256 `AB984DCF3498C673B8D3D7E39EB5528E8A6F5BA3A633EEB1D85C50C0CD3631A7`; `0x005a5103-0x005a5110` is thirteen `0xcc` bytes.
- Current target/support/formal pages, generated BulletinSession/UserPane sources, tracker, four applicable manual coverage roots, neighboring physical slots, DialogSession/Event/EventHandler declarations, UserPane helper indexes, and all historical roots listed above were reread.

## Claim And Incorporation Ledger

| Claim | Atomic accepted fact | Confidence | Destination | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence comes from healthy MCP database `9b0396a3`; bounded health, bytes, lookup, xref, decompile, name, and integer calls succeeded. | High | changed evidence sections | incorporate | applied | Target/global/class/core/helper/vtable pages retain exact session, health, bounded-call and evidence-time facts; their scoped validators passed. |
| C02 | UID0001PA is exact `0x0067adc0-0x0067adc4`, four zero bytes, hash `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, no function. | High | UID0001PA/QG/HX | incorporate | applied | UID0001PA hash `6EA66C96...1E364`, QG `F1797D3F...BAA8E`, HX `CFEF6435...846C8`; warning-free target validator `15732` and retained validators `15667/15685` exit 0/ok 1. |
| C03 | PE `.data` virtual-tail arithmetic proves loader-zero storage and disproves the historical raw `0xffffffff` read. | High | UID0001PA/QG/HX/manual handoff | reject-stale | applied | Ordinary pages historicalize the bad raw-offset read and preserve section arithmetic; supervisor commands `15723`-`15726` externally applied and validated the exact replacement union retained below as audit history. |
| C04 | The global has exactly 11 refs in ten functions: five lifecycle writes/clears and six null-guard reads. | High | UID0001PA/QG/class/file | incorporate | applied | Full xref table and classifications are present across target/global/class/file; generated output has only the one source definition assignment. |
| C05 | Six constructor callers use modes 0/1 and null guards; no route uses a `-1` sentinel. | High | target/global/constructor/file | incorporate | applied | UID0004FS and target/global/file retain all six caller addresses/modes and negative sentinel evidence; command `15671` passed. |
| C06 | UID0001PA is physical storage only: `92/94`, owner QG, false, blank emitter/position, physically blank R0 formal, Nested -4; no-duplicate rationale remains in prose. | High | UID0001PA | incorporate | applied | Exact metadata, blank managed body, prose proof, and unchanged range/nesting are present at hash `6EA66C96...1E364`; validator `15732` exit 0/ok 1 with no `emitter_inactive_has_data` diagnostic. |
| C07 | UID0000QG owns the sole external definition at position 0 with exact R1 under UID0000HX. | High | UID0000QG | incorporate | applied | QG metadata/R1 exact; validator `15667` passed; command `15706` generated one definition before one extern. |
| C08 | UID00001D directly inherits DialogSession and Singleton<BulletinSession>; RTTI has eight entries and PMD +0x100. | High | class/vtable/file/core | incorporate | applied | R2 and complete RTTI/PMD evidence are in UID00001D, UID0004UT, HX and ZH; validators `15669/15729/15685/15696` passed, with UID0004UT's false-page formal physically blank. |
| C09 | EBO overlaps Singleton at +0x100 with `bool m_pendingListResponse`; natural pad +0x101 and `unsigned short m_activeListId` +0x102 close size 0x104. | High | class/ctor/FU/dispatcher/file | incorporate | applied | Exact declaration order/types and prose layout are present; generated class has the two natural members and no raw padding field. |
| C10 | Complete R2 declares one extern, accepted methods, Event override, private dispatcher, exact members, and closes before `[[CHILDREN]]`. | High | UID00001D | incorporate | applied | UID00001D hash `0224D9C4...92F7B`; final waited command `15733` places `};` before the first qualified definition. |
| C11 | UID0004FS R3 uses `const unsigned char *`, direct Singleton initialization, unified fields, and no explicit global publication. | High | UID0004FS/class/core/file | reject-stale | applied | R3 exact in UID0004FS; validators `15671/15669/15696/15685` passed; generated constructor contains no global write. |
| C12 | UID0004FT R4 is an empty authored ordinary destructor; reverse Singleton teardown supplies the clear. | High | UID0004FT/class/core/file/global | reject-stale | applied | R4 exact in UID0004FT; validator `15674` passed; generated destructor is empty and contains no explicit clear. |
| C13 | UID0003Q1 remains false compiler unwind support; its clear corroborates implicit Singleton lifetime. | High | UID0003Q1 and bounded links | already-present | already-present | Verify-only hash remains `D94EA652...E095`; only bounded links/prose were added elsewhere. |
| C14 | UID0003Q4 is `92/94`, class owner, false, blank emitter/position, physically blank R8 formal; the complete scalar-wrapper no-code proof remains in prose. | High | UID0003Q4/class/file/core | incorporate | applied | UID0003Q4 hash `D522B582...6636E`; validator `15730` exit 0/ok 1 with no `emitter_inactive_has_data` diagnostic; command `15733` emits no UID0003Q4 text or marker. |
| C15 | UID0004FY blocker is closed by Event/EventHandler; `92/94`, class owner/emitter, exact R5. | High | UID0004FY/class/file/core | incorporate | applied | UID0004FY hash `5A48F0DE...46BF2`; validator `15676` passed; generated R5 occurs once. |
| C16 | Register UID0004US exact helper at `0x005a50a0-0x005a5103`, `90/93`, UserPane owner/emitter, R6, Nested +4. | High | UID0004US/UserPane indexes/file | incorporate | applied | Validator `15650` issued UID0004US; final command `15702` preserves stored `Nested:4`; R6 hash `B90659CC...0FBCE`; command `15706` emits it once. |
| C17 | UID0002RX changes only Nested +4 to 0; UID0001KO remains false and inventories the helper as non-say source. | High | UID0001KO/UID0002RX | incorporate | applied | Hashes `2756EC07...D2BF9` and `15463F9B...F9A1`; commands `15654/15655` passed; score/route/formal readback unchanged. |
| C18 | Register UID0004UT exact vtable data at `0x00613b1c-0x00613ba4`, `92/94`, class owner, false/no-emitter, physically blank R7 formal with full no-array proof in prose, Nested +4; UID0002MI becomes 0. | High | UID0004UT/UID00024W/UID0002MI/class/file | incorporate | applied | Validator `15651` issued UID0004UT; repair validator `15729` preserves stored `Nested:4`, hash `87887911...8766`, and reports no `emitter_inactive_has_data`; UID0002MI command `15692` preserves `Nested:0`; parent/class/file validators passed. |
| C19 | Generated output has one global definition/extern, class closure, R3/R4/R5/R6 once, zero false-page text/target markers, and no handwritten ABI glue. | High | waited generated readback | incorporate | applied | Final waited repair command `15733` exit 0/ok 1; exact BulletinSession/UserPane/IconsPane hashes and semantic counts are recorded under Validator Results. |
| C20 | Exact score/manual handoff is supervisor-owned; B003 must not edit coverage. | High | score table/manual section | already-present | already-present | Supervisor commands `15723`-`15726` applied and validated every exact by-memory/by-global/by-class/by-file row uniquely. Current hashes are recorded below; B003 made no manual coverage edit. |

## Positive Evidence Summary

- Exact PE mapping and current zeros independently prove BSS-style storage.
- All 11 references form one coherent pointer lifecycle; all guards use zero/nonzero.
- Six allocation sites all allocate exactly 260 / `0x104` bytes and call one constructor.
- RTTI independently proves the direct Singleton base and exact `+0x100` PMD.
- Constructor adjusted-pointer publication, unwind clear, ordinary clear, and scalar clear match Singleton lifetime at every exception/destruction boundary.
- EventHandler slot order and current Event layout resolve the packet forwarder without raw ABI arithmetic.
- Four direct xrefs and address-family placement resolve `EnsureNormalBulletinSession` as an externally linked UserPane/local-player helper.
- Vtable bases, COL offsets, table counts, constructor/destructor stores, and adjustor thunks agree on primary/`+0xa0`/`+0xa4` views.

## IDA MCP Facts

### Exact singleton references

| Address | Function | Access and source meaning |
| --- | --- | --- |
| `0x004711a2` | constructor `0x00471150` | publish complete object through direct Singleton base lowering |
| `0x004711a9` | same constructor | compiler null fallback, not a second source write or sentinel |
| `0x0047128a` | ordinary destructor `0x00471270` | reverse Singleton-base clear |
| `0x0047e840` | constructor unwind helper | compiler exception cleanup clear |
| `0x0047eab0` | scalar wrapper `0x0047ea90` | inlined deleting-destructor Singleton clear |
| `0x00508776` | MapPane dispatcher | null guard before mode-0 packet construction |
| `0x00513bd3` | compact packet helper | null and `!(packet[2]&1)` guard before mode-0 construction |
| `0x005466e8` | ParcelPane mouse handler | right-action null guard before mode-1/predefined construction |
| `0x005a50c3` | lazy helper | null guard before mode-1/normal construction |
| `0x005a60c8` | UserPane key handler | key `0x4d` direct null guard before mode-1/predefined construction |
| `0x005bd0f4` | menu-variety handler | selection 2 null guard before mode-1/predefined construction |

### Six constructor calls

| Call | Caller/source role | Exact source-facing construction |
| --- | --- | --- |
| `0x005087b6` | MapPane packet opcode `0x31`, requires global null and `(packet[2]&1)==0` | `new BulletinSession(0, packet, false)` |
| `0x00513c07` | compact packet helper, same gate | `new BulletinSession(0, packet, false)` |
| `0x00546718` | ParcelPane right action | `new BulletinSession(1, 0, true)` |
| `0x005a50ef` | `EnsureNormalBulletinSession` | `new BulletinSession(1, 0, false)` |
| `0x005a60ff` | UserPane key `0x4d` | `new BulletinSession(1, 0, true)` |
| `0x005bd120` | menu-variety selection 2 | `new BulletinSession(1, 0, true)` |

### RTTI and vtable

- CHD `0x006433d0` reports eight entries. Direct self and DialogSession BCDs are `0x00643404/0x00643420`; the direct Singleton BCD is `0x00643468` with PMD `mdisp=0x100`, `pdisp=-1`, `vdisp=0`, attributes `0x40`.
- Primary COL `0x006433bc` has offset `0`; secondary COL `0x006434b8` has offset `0xa0`; tertiary COL `0x006434cc` has offset `0xa4`.
- Exact data range `0x00613b1c-0x00613ba4` contains 18 primary, 11 secondary, and 2 tertiary slots. First cells are scalar wrapper `0x0047ea90`, secondary adjustor `0x0047e8c3`, and tertiary adjustor `0x0047e8ce`.
- Each table base has exactly three lifecycle refs from constructor, ordinary destructor, and scalar wrapper. No handwritten table or raw RTTI array is source-authored.

## Function / Child Inventory

| Range | UID | Source identity | Implemented disposition |
| --- | --- | --- | --- |
| `0x00471150-0x00471ff1` | 0000ZH | BulletinSession mixed core index | unchanged false split index; add coherent singleton/class/type history |
| `0x00471150-0x0047126c` | 0004FS | constructor | `91/94`, exact R3, implicit Singleton publication |
| `0x00471270-0x00471299` | 0004FT | ordinary destructor | `91/94`, exact empty R4, implicit Singleton clear |
| `0x004712a0-0x004712ac` | 0004FU | `ActivateScreenDimmer` | verified formal/source route unchanged; shared `m_pendingListResponse` spelling is synchronized through class/core support |
| `0x00471480-0x004714a3` | 0004FY | `HandlePacketEvent(Event *)` | `92/94`, exact R5, class emitter |
| `0x00471550-0x00471872` | 0004G1 | packet dispatcher | retain documented live body/blank child formal; class declares private `bool DispatchPacket(const unsigned char *)` |
| `0x004718a0-0x00471956` | 0004G3 | board-list opener | existing source body unchanged |
| `0x00471c00-0x00471dcd` | 0004G6 | predefined-form action | existing source body unchanged |
| `0x0047e840-0x0047e84b` | 0003Q1 | unwind clear | unchanged false compiler support |
| `0x0047ea90-0x0047eaef` | 0003Q4 | scalar deleting destructor | `92/94`, false/no-emitter, physically blank R8 formal, prose compiler proof |
| `0x005a50a0-0x005a5103` | UID0004US | `EnsureNormalBulletinSession` | registered/implemented source helper `90/93`, UserPane emitter, R6, stored Nested 4 |
| `0x00613b1c-0x00613ba4` | UID0004UT | BulletinSession RTTI/vtable data | registered/implemented false compiler-data child `92/94`, physically blank R7 formal, prose no-array proof, stored Nested 4 |
| `0x0067adc0-0x0067adc4` | 0001PA | physical global storage | `92/94`, false/no-emitter, physically blank R0 formal, prose no-duplicate proof |

## Direct Xref / Caller Inventory

The 11 global refs are exhaustive and shown above. Their grouping is five compiler/lifecycle writes or clears plus six consumer null-guard reads. The six constructor callsites are likewise exhaustive. `xrefs_to(0x005a50a0)` returns four calls: `0x004cf6fd` from IconsPane, raw duplicate-site `0x004cf92e`, `0x005a6d18` from UserPane key handling, and `0x005abe8c` from the UserPane panel-switch packet handler. Those four calls require external linkage or a shared inline definition; one modeled external helper body is present, so a non-static UserPane.cpp definition is the least assumptive source shape.

## Documentation Evidence And IDA Status

- Historical pre-callback UID0001PA and its manual row were stale on bytes, initializer, source role, and emitting metadata. The ordinary target now has exact loader-zero/false metadata, a physically blank R0 formal, and full no-duplicate proof in prose; supervisor command `15723` applied and validated the corresponding manual row at its current unique position.
- Historical UID0000QG had the correct semantic name but no definition/position/PE/direct-Singleton one-definition closure. Current UID0000QG has exact position-0 R1 and full evidence.
- Historical UID00001D emitted no class. Current UID00001D has complete R2; current generated source closes the class before all child definitions.
- Historical UID0004FS/UID0004FT drafts treated compiler Singleton publication/clear as handwritten. Current R3/R4 retain authored behavior and exclude only compiler lowering.
- UID0004FU remains unchanged and supplies the shared `m_pendingListResponse` spelling that supersedes historical constructor-local `m_requestState`.
- UID0004FY's former Event/interface blocker is closed; current metadata/emitter/R5 are applied and generated once.
- UID0003Q1 remains correctly false/unchanged. UID0003Q4 is now false/non-emitting with a physically blank R8 formal, complete compiler-wrapper rationale in prose, and no generated marker.
- UID0001KO still excludes `0x005a50a0` from say-mode ownership; exact UID0004US now preserves that exclusion while providing the UserPane source route.
- UID00024W now inventories exact UID0004UT without changing its mixed parent route; UID0002MI remains the following unchanged BulletinDialog child except for the accepted relative nesting delta.

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Reason |
| --- | --- | --- | --- |
| 1 | semantic UID0000QG emitted by UID0000HX | accepted | exact external name/type, source module, consumers, lifecycle, one-definition precedent |
| 2 | physical UID0001PA emits through QG | rejected | duplicate source carrier for one linker slot; physical page is byte/range evidence only |
| 3 | `BulletinSession::s_instance` static member | rejected | no decorated static-member evidence; current project/global consumers use external `g_pBulletinSession` |
| 4 | direct `Singleton<BulletinSession>` owns publication/clear mechanics | accepted as compiler/source cause, not separate definition carrier | exact RTTI PMD, adjusted store, unwind and reverse-clear behavior |
| 5 | MapPane/ParcelPane/UserPane/MenuVariety owns the global | rejected | they are consumers/allocators; none supplies storage, RTTI, or lifecycle clear |
| 6 | no owner / compiler-only global | rejected | external pointer definition is real source; only base lifetime mechanics are compiler-lowered |

## Source Placement

- `NexusTK/ui/dialogs/BulletinSession.h`: complete R2 class, direct `DialogSession` and `Singleton<BulletinSession>` bases, one `extern BulletinSession *g_pBulletinSession;`, accepted method declarations, and exact fields.
- `NexusTK/ui/dialogs/BulletinSession.cpp`: one position-0 R1 definition, then class child definitions including R3/R4/R5 and existing source methods. UID0001PA/UID0003Q4/UID0004UT emit no raw storage/ABI/table source.
- `NexusTK/ui/panels/UserPane.cpp`: externally linked R6 `EnsureNormalBulletinSession`, because address order and three modeled caller families place it in the UserPane/local-player action-helper island. A compatible declaration belongs in a shared UI/BulletinSession-facing header; raw `sub_5A50A0` and historical `EnsureBulletinSession_5A50A0` remain aliases only.
- `NexusTK/ui/dialogs/BulletinSession.cpp` is rejected for R6 physical ownership because it would ignore the `0x005a4db0-0x005a5a80` local-player action-helper neighborhood. Semantic dependency on BulletinSession does not override the executable/source-family placement evidence.

## Range / Split / Padding / Reclassification Analysis

- UID0001PA remains exact `0x0067adc0-0x0067adc4`; no split/rename/range expansion. Predecessor exact child ends at `0x0067adc0`; successor aggregate/exact children begin at `0x0067adc4`. `Nested:-4` remains the correct cumulative delta exiting UID0002AI.
- UID0004US is exact modeled function `0x005a50a0-0x005a5103`, size `0x63`; predecessor code ends at `0x005a5091`, `0x005a5091-0x005a50a0` is fifteen `0xcc` bytes, and successor pad `0x005a5103-0x005a5110` is thirteen `0xcc` bytes. Pads remain parent-only; no function range absorbs them.
- UID0004US becomes first exact child within UID0001KO's address span: new child `Nested:+4`, following UID0002RX `Nested:0`. UID0001KO remains `Nested:-4`; broader UID0001KL/UID0001KM levels remain unchanged.
- UID0004UT is exact `0x00613b1c-0x00613ba4`, beginning at the primary COL pointer and ending before BulletinDialog COL `0x00613ba4`. It is the first exact UID00024W child: new child `Nested:+4`, following UID0002MI `Nested:0`; UID0002VE and later children remain `Nested:0`.
- UID0003Q4 is reclassification only, not range/split/rename. UID0004FY is emitter/formal/type promotion only. No existing UID is renamed.

## Negative Evidence Summary

- No raw file bytes back UID0001PA; `ff ff ff ff` came from invalid section arithmetic.
- No global read compares against `-1`; all six reads are null guards.
- No function covers UID0001PA or UID0004UT.
- No evidence supports a second definition, class-static member, duplicate physical emitter, or source-authored vtable/RTTI arrays.
- No evidence supports explicit `g_pBulletinSession` writes in authored constructor/destructor once direct Singleton RTTI is considered.
- No evidence makes EventHandler or TimerHandler direct BulletinSession bases; RTTI ancestry and offsets remain inherited Pane facets.
- No evidence makes the lazy helper a BulletinSession member, a say-mode helper, a ParcelPane helper, or a static one-TU-only function.
- No source should contain raw `this-0xa0`, vptr stores, scalar flags, storage deletion, SEH/cookie code, RTTI descriptors, COLs, or dword arrays.

## IDA Rename / Type / Comment Recommendations

- Rename IDA data `unk_67ADC0`/`dword_67ADC0` to `g_pBulletinSession` and type it `BulletinSession *` only in a separate supervisor-authorized IDA phase; this report does not mutate IDA.
- Rename `sub_5A50A0` to `EnsureNormalBulletinSession` and type it `void __cdecl(void)` in that same optional phase.
- Type `sub_471480` as source override `bool BulletinSession::HandlePacketEvent(Event *)`; retain secondary-view adjustment as compiler commentary, not source expression.
- Comment RTTI Singleton BCD `0x00643468` with PMD `+0x100/-1/0`, EBO overlap with `m_pendingListResponse`, and implicit publication/clear.
- Retain raw `sub_471150`, `sub_471270`, `sub_47E840`, `sub_47EA90`, `a1/a2/a3`, and numeric globals only as historical evidence aliases.

## First-Draft C++ Recommendation

### R0 - UID0001PA physical storage, exact no-code disposition

UID0001PA emits no independent C++ object. The sole source definition is owned by [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) as `g_pBulletinSession`; this page preserves the exact loader-zero storage, range, and xref evidence. Because the page is `RECONSTRUCTABLE:FALSE` with a blank emitter, its managed formal body must be physically blank.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R1 - UID0000QG sole module definition

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BulletinSession;

BulletinSession *g_pBulletinSession = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R2 - UID00001D complete class/header declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class ScreenDimmer;
class BulletinSession;

extern BulletinSession *g_pBulletinSession;

class BulletinSession : public DialogSession,
                        public Singleton<BulletinSession>
{
public:
    BulletinSession(unsigned char initializationMode,
                    const unsigned char *initialPacket,
                    bool requestPredefinedForms);
    virtual ~BulletinSession();

    virtual bool HandlePacketEvent(Event *event);

    void OpenNewArticleDialog(const wchar_t *title);
    void OpenReplyDialog(const wchar_t *recipientText,
                         const wchar_t *quoteText,
                         short quoteLength);

private:
    ScreenDimmer *ActivateScreenDimmer();
    void OpenBoardListDialog(const unsigned char *packetData);
    void HandlePredefinedFormAction(const unsigned char *packet);
    bool DispatchPacket(const unsigned char *packet);

    bool m_pendingListResponse;
    unsigned short m_activeListId;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R3 - UID0004FS constructor with implicit Singleton publication

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
BulletinSession::BulletinSession(unsigned char initializationMode,
                                 const unsigned char *initialPacket,
                                 bool requestPredefinedForms)
    : DialogSession(),
      Singleton<BulletinSession>(),
      m_pendingListResponse(false),
      m_activeListId(0)
{
    if (initializationMode == 1) {
        const unsigned char request[3] = {
            0x3b,
            static_cast<unsigned char>(requestPredefinedForms ? 9 : 1),
            0
        };

        SendPacketBytes(request, 2);

        if (requestPredefinedForms)
            m_pendingListResponse = true;
    } else if (initializationMode == 0) {
        m_pendingListResponse = true;
        DispatchPacket(initialPacket);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R4 - UID0004FT authored ordinary destructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
BulletinSession::~BulletinSession()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R5 - UID0004FY packet-event override

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool BulletinSession::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] != 0x31)
        return false;

    return DispatchPacket(packet);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R6 - UID0004US UserPane-owned lazy helper

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void EnsureNormalBulletinSession()
{
    if (g_pBulletinSession == 0)
        new BulletinSession(1, 0, false);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R7 - UID0004UT exact compiler vtable/RTTI data

UID0004UT is compiler-generated RTTI and primary/secondary/tertiary vtable data. It is regenerated from the `BulletinSession` declaration and virtual methods; COL, RTTI, PMD, adjustor-thunk, and vtable dword arrays must not be handwritten. Because the page is `RECONSTRUCTABLE:FALSE` with a blank emitter, its managed formal body must be physically blank.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R8 - UID0003Q4 scalar deleting destructor compiler support

UID0003Q4 is the MSVC scalar deleting destructor wrapper for `BulletinSession`. Source behavior is covered by `virtual ~BulletinSession()`, direct Singleton base teardown, and normal `operator delete` lowering; no wrapper body is handwritten. Because the page is `RECONSTRUCTABLE:FALSE` with a blank emitter, its managed formal body must be physically blank.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

## Final Recommendation

C01-C20 and R0-R8 were applied without compression. Validator registration issued UID0004US and UID0004UT serially before dependent validation; all provisional tokens were removed. The complete shared UserPane and board/mail unions, exact target/global ranges, predecessor/successor children, parent-only padding, unrelated BulletinSession children, and current consumer behavior are preserved. Current generated source has one global definition, one extern, one complete class, implicit Singleton lifecycle, one packet-event override, one lazy helper, and no physical/scalar/vtable duplicate emission.

## Recommended Target Doc Changes

For UID0001PA, the following accepted changes are implemented:

- `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000QG`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, physically blank R0 formal with exact prose no-duplicate proof, and retained `Nested:-4`.
- Every `0xffffffff`/static-image assertion is historicalized and superseded by exact PE virtual-tail zero-fill proof, bytes/hash, no-function fact, and error explanation.
- All 11 refs are preserved and classified as five lifecycle stores/clears plus six reads.
- Direct Singleton cause, one-definition route, six constructor calls, predecessor/successor boundaries, negative evidence, score rationale, and generated no-marker contract are present.

## Recommended Support Doc Changes

All accepted support changes below are implemented or, for verify-only rows, independently confirmed unchanged:

1. UID0000QG: `92/94`, position `0`, exact R1, sole-definition/header extern policy, PE zero-fill, 11-ref table, direct Singleton lifecycle, rejected sentinel/static-member/duplicate-owner alternatives.
2. UID00001D: `92/94`, exact R2, direct bases and eight-entry RTTI, PMD/EBO layout, accepted fields/access, Event override, all current child declarations/history, class close before `[[CHILDREN]]`.
3. UID0000HX: `91/93`, preserve source route and full method/raw/table inventory; add sole global definition/class header order, helper cross-file placement, implicit Singleton lifecycle, exact vtable child, generated assertions, and remaining duplicate-inline child no-code facts.
4. UID0004FS: `91/94`, exact R3 and item/evidence/history synchronization; remove only explicit publication and stale `m_requestState`/`PacketBuffer *`, retaining all mode/opcode/send/dispatcher/caller/boundary facts.
5. UID0004FT: `91/94`, exact R4 and direct Singleton reverse-clear proof; preserve exact range, vtable stores/base cleanup as compiler lowering, no-direct-route evidence, and scalar relationship.
6. UID0004FY: `92/94`, owner/emitter UID00001D, exact R5, Event packet layout/slot/source signature, no raw `this-0xa0`, and prior blocker historicalization.
7. UID0003Q4: `92/94`, owner UID00001D, false, blank emitter/position, physically blank R8 formal with full ABI/vtable/flags/free no-code evidence in prose; remove generated marker.
8. UID0003Q1: verify-only unchanged; add links only where another changed page refers to its compiler unwind role.
9. UID0004US: exact path/range, issued UID, `90/93`, owner/emitter UID0000P1, true, blank position, R6, `Nested:+4`, body hash/callers/padding/source placement/negative evidence.
10. UID0001KO: retain `86/88`, NONE/false/blank and `Nested:-4`; inventory UID0004US as non-say UserPane-owned exact child. UID0002RX changes only `Nested:+4 -> 0` and preserves score/route/formal/evidence.
11. UID0001KL, UID0001KM, and UID0000P1: add UID0004US range/body/caller/source ordering without losing any B001/B002/B004/B005/current shared UserPane facts or changing existing scores/routes/formals.
12. UID0004UT: exact path/range, issued UID, `92/94`, owner UID00001D, false, blank emitter/position, physically blank R7 formal, `Nested:+4`, exact hash/table/RTTI/PMD/lifecycle/no-array proof in prose.
13. UID00024W: retain `85/91`, NONE/false/blank and all mixed contents; add UID0004UT exact child. UID0002MI changes only `Nested:+4 -> 0`, preserving BulletinDialog content/score/route/formal.
14. UID0000ZH: score/route/formal unchanged; synchronize constructor/destructor/packet/scalar/global/vtable source/compiler decisions while preserving all 17 children, raw pockets, jump table, ranges, padding, and unrelated methods.
15. Consumer pages for MapPane, compact packet helper context, ParcelPane, IconsPane, UserPane key/panel packet, and MenuVariety are verify-only unless a current direct contradiction appears; no broad rewrite is authorized by this report.

## Score And Metadata Recommendation

| Destination | Before callback | Implemented | Exact tuple/rationale |
| --- | --- | --- | --- |
| UID0001PA | 86/90 | 92/94 | QG owner, false, blank emitter/position, physically blank R0 formal, Nested -4; exact PE/bytes/xrefs/one-definition proof in prose |
| UID0000QG | 87/90 | 92/94 | HX owner/emitter, true, position 0, R1; sole definition and complete lifecycle |
| UID00001D | 85/87 | 92/94 | HX owner/emitter, true, blank position, R2; complete hierarchy/layout/declaration |
| UID0000HX | 85/87 | 91/93 | file route unchanged; complete one-definition/class/compiler/helper policy, broader duplicate-inline debt retained |
| UID0004FS | 89/92 | 91/94 | class owner/emitter, true, R3; exact source/compiler lifecycle and unified field/packet types |
| UID0004FT | 88/92 | 91/94 | class owner/emitter, true, R4; exact authored-empty versus implicit base teardown |
| UID0004FY | 88/93 | 92/94 | class owner/emitter, true, R5; Event/interface blockers closed |
| UID0003Q4 | 88/92 | 92/94 | class owner, false, blank emitter/position, physically blank R8 formal; compiler-wrapper proof in prose |
| UID0004US | absent | 90/93 | UID0000P1 owner/emitter, true, blank position, R6, Nested +4 |
| UID0001KO | 86/88 | unchanged | NONE/false/blank, Nested -4; mixed index only |
| UID0002RX | 90/92 | unchanged | owner/emitter UID0000N9, true, existing formal; only Nested +4 -> 0 |
| UID0004UT | absent | 92/94 | UID00001D owner, false, blank emitter/position, physically blank R7 formal with prose no-array proof, Nested +4 |
| UID00024W | 85/91 | unchanged | NONE/false/blank mixed data index |
| UID0002MI | 89/92 | unchanged | BulletinDialog owner/emitter/formal unchanged; only Nested +4 -> 0 |
| UID0000ZH/UID0001KL/UID0001KM/UID0000P1/UID0003Q1 | current scores | unchanged | bounded evidence/index synchronization only |

## Open Questions With Attempted Resolution

1. **Was the slot initialized to `0xffffffff`?** Resolved no. Target is beyond `.data` raw size and loader-zero-filled; current bytes and all guards are zero semantics.
2. **Should physical or semantic page emit?** Resolved semantic UID0000QG only. Physical UID0001PA is false/no-emitter.
3. **Is the global a class-static Singleton member?** Rejected. RTTI proves the base mechanism, but current externally linked global naming/use and project route support one module definition plus extern.
4. **Are constructor/destructor global assignments authored?** Resolved no. PMD, adjusted publication, reverse clear, unwind clear, and scalar duplicate prove direct Singleton lowering.
5. **What is the `+0x100` field?** Resolved best source name `m_pendingListResponse`, type `bool`; exact role is request/list-response state across constructor, screen dimmer, and dispatcher.
6. **What is `+0x102`?** Resolved `unsigned short m_activeListId`; dialog `+0x274` copies and 16-bit accesses close type/role.
7. **Can packet forwarder emit?** Resolved yes through `HandlePacketEvent(Event *)`; current Event and EventHandler close payload and slot blockers.
8. **Where does `0x005a50a0` belong?** Resolved UserPane/local-player action helper, externally linked `EnsureNormalBulletinSession`; BulletinSession is dependency, not physical source owner.
9. **Should scalar/vtable data emit?** Resolved no. Source class/destructor regenerate both; raw wrapper/arrays are compiler output.
10. **Do parent levels change?** Resolved only the first-child deltas: NEW helper/vtable `+4`, following existing children `0`; target remains `-4`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 did not manually edit coverage. Supervisor commands `15723` through `15726` subsequently applied and validated the exact handoff. Current read-only root state is:

| Root | SHA256 | Bytes / lines | Relevant current row |
| --- | --- | --- | --- |
| `by-memory/-coverage-report.md` | `9CE3FC30E4044223E32AF350E335749165FCCF3243439E815CE1CF63ED4489C4` | 1,885,034 / 4,437 | command `15723`; applied rows are unique at UID0001KO/UID0004US/UID0002RX lines 3559-3561, UID00024W/UID0004UT/UID0002MI lines 3868-3870, and UID0001PA line 4279 |
| `by-global/-coverage-report.md` | `642D74472052A7151C1FCC41072DF99538DB2F341B7AC3541E8648FDF9671380` | 93,268 / 214 | command `15724`; applied UID0000QG row is unique at line 59 |
| `by-class/-coverage-report.md` | `B25AD1844D78C766EBC8E18E6DE9FB93E786D399117296DE7588D639F06C4E25` | 244,927 / 623 | command `15725`; applied UID00001D row is unique at line 75 |
| `by-file/-coverage-report.md` | `44613BF3C357A09A0005DAEFF582814184EC77D7C9A8064FFAC0DCC00184C4DE` | 142,768 / 316 | command `15726`; applied UID0000HX/UID0000P1 rows are unique at lines 41/297, including the complete bounded R6 clause |

The prior callback-time roots and absent/stale-row findings are historical evidence only. Command `15700` reported a validator-owned `memory_coverage_metadata_update` while normalizing new-child metadata but did not apply the complete handoff. External supervisor commands `15723`-`15726` later applied and validated every proposed row against the no-loss current union. The exact handoff text is retained below verbatim as applied audit evidence, not as a pending instruction:

```text
by-memory replacement UID0001PA:
    - [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md) 0x0067adc0-0x0067adc4 | physical singleton storage | g_pBulletinSession : not_reconstructable : 92% : very-strong : Exact four-byte loader-zero virtual-.data storage for BulletinSession *g_pBulletinSession, SHA256 DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119, with eleven exact refs, six null-guard consumers, direct Singleton<BulletinSession> PMD +0x100 lifecycle cause, sole semantic definition on UID0000QG, false/no-emitter no-duplicate disposition, preserved predecessor/successor boundaries, and historical 0xffffffff raw-offset error rejected.

by-memory replacement UID0001KO and child union:
    - [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md) 0x005a4b60-0x005a5791 | non-emitting mixed helper index | SayModeHelpers : not_reconstructable : 86% : strong : Mixed say-mode and adjacent UI action helper neighborhood with nineteen modeled functions, exact source-ready UID0002RX say-mode child, exact UserPane-owned UID0004US EnsureNormalBulletinSession child, boundary padding, caller/source-family distinctions, non-say ownership exclusions, and no synthetic aggregate source body.
        - [UID:0004US][0x005a50a0-0x005a5103.EnsureNormalBulletinSession](by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md) 0x005a50a0-0x005a5103 | externally linked UI action helper | EnsureNormalBulletinSession : reconstructable : 90% : very-strong : Exact 0x63-byte UserPane.cpp helper, SHA256 AB984DCF3498C673B8D3D7E39EB5528E8A6F5BA3A633EEB1D85C50C0CD3631A7, with four direct IconsPane/UserPane caller sites, null guard, 0x104 allocation lowered to new BulletinSession(1, 0, false), thirteen-byte successor padding, and complete C++03 source body.
        - [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) 0x005a5110-0x005a5337 | source-ready say-input dispatcher | OpenInputPaneForCurrentSayMode : reconstructable : 90% : very-strong : Exact current say-mode input dispatcher owned by SayInputPanes.cpp with accepted source body, current mode/field/helper evidence, and unchanged score/owner/emitter/formal; relative Nested changes from +4 to 0 only because UID0004US is now the first exact address-sorted child.

by-memory additions for changed BulletinSession code/compiler children:
        - [UID:0004FS][0x00471150-0x0047126c.BulletinSessionConstructor](by-memory/0x00471150-0x0047126c.BulletinSessionConstructor.md) 0x00471150-0x0047126c | source constructor | BulletinSessionConstructor : reconstructable : 91% : very-strong : Exact 0x11c constructor with six callers, direct DialogSession and Singleton<BulletinSession> initialization, implicit singleton publication, m_pendingListResponse/m_activeListId state, mode 0 packet dispatch, mode 1 opcode 0x3b subcommand 1/9 send, exact boundaries/padding, and compiler vptr/EH exclusion.
        - [UID:0004FT][0x00471270-0x00471299.BulletinSessionCleanup](by-memory/0x00471270-0x00471299.BulletinSessionCleanup.md) 0x00471270-0x00471299 | ordinary virtual destructor | BulletinSessionDestructor : reconstructable : 91% : very-strong : Exact authored-empty virtual BulletinSession destructor with reverse Singleton<BulletinSession> implicit clear, compiler vptr restores and DialogSession base teardown, exact range/no-direct-route evidence, and scalar-wrapper separation.
        - [UID:0004FY][0x00471480-0x004714a3.BulletinSessionPacketForwarder](by-memory/0x00471480-0x004714a3.BulletinSessionPacketForwarder.md) 0x00471480-0x004714a3 | EventHandler packet override | BulletinSessionHandlePacketEvent : reconstructable : 92% : very-strong : Exact EventHandler +0x10 bool HandlePacketEvent(Event *) override with Event packet-data +0x0c, top-level byte 0x31 gate, source DispatchPacket call, compiler secondary-this adjustment exclusion, vtable-only route, and complete source C++.
        - [UID:0003Q4][0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor](by-memory/0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor.md) 0x0047ea90-0x0047eaef | MSVC scalar deleting destructor | BulletinSessionScalarDeletingDestructor : not_reconstructable : 92% : very-strong : Compiler-only wrapper with three vtable restores, implicit Singleton clear, DialogSession teardown, scalar flags, optional delete, vtable/adjustor reachability, source covered by virtual ~BulletinSession(), false/no-emitter no-code disposition, and no handwritten ABI body.

by-memory replacement/additions for board-mail data union:
    - [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md) 0x00613ab0-0x00614cd0 | non-emitting mixed vtable/string-data index | BoardMailReadOnlyData : not_reconstructable : 85% : very-strong : Exact mixed WebBoard strings, BulletinSession/BulletinDialog/BoardList/Article/NewArticle/NewPredefined/transfer-alert/mail RTTI-vtable bands, GBBS/mail resources, ChangeMan successor, 141 named heads, source-owner exclusions, and exact child routing including UID0004UT BulletinSession vtable data, with no aggregate source object.
        - [UID:0004UT][0x00613b1c-0x00613ba4.BulletinSessionVtableData](by-memory/0x00613b1c-0x00613ba4.BulletinSessionVtableData.md) 0x00613b1c-0x00613ba4 | compiler RTTI/vtable data | BulletinSessionVtableData : not_reconstructable : 92% : very-strong : Exact 0x88-byte data, SHA256 A1B77ACF81E70E3D7E0178D68A4209EB2FEF38108A7CF3150FED3F91835DF3AA, with 18/11/2 primary/EventHandler/TimerHandler slots, COL offsets 0/+0xa0/+0xa4, eight-entry RTTI, direct Singleton<BulletinSession> PMD +0x100 EBO, constructor/destructor/scalar stores, adjustor thunks, and no handwritten RTTI/vtable arrays.
        - [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md) 0x00613ba4-0x00613c44 | BulletinDialog compiler vtable data | BulletinDialogVtableData : reconstructable : 89% : very-strong : Current exact BulletinDialog RTTI and three vtable views, raw constructor-store evidence, exact previous UID0004UT and successor BoardListDialog boundaries, existing owner/emitter/formal unchanged, and relative Nested changes from +4 to 0 only.

by-global replacement UID0000QG:
- [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) : reconstructable : 92% : very-strong : Sole externally linked BulletinSession *g_pBulletinSession = 0 definition at BulletinSession.cpp position 0, with local forward declaration, one matching class-header extern, exact loader-zero UID0001PA backing storage, eleven-reference lifecycle map, six null-guard construction routes, direct Singleton<BulletinSession> PMD +0x100 implicit publication/clear, rejected 0xffffffff sentinel and duplicate/static-member routes, and generated one-definition/no-marker contract.

by-class replacement UID00001D:
- [UID:00001D][BulletinSession](by-class/BulletinSession.md) : reconstructable : 92% : very-strong : Complete 0x104 BulletinSession declaration with direct DialogSession and empty Singleton<BulletinSession> bases, eight-entry RTTI, PMD +0x100 EBO overlap with bool m_pendingListResponse, natural +0x101 pad, unsigned short m_activeListId at +0x102, EventHandler packet override, accepted constructor/destructor/dialog methods and private dispatcher, one g_pBulletinSession extern, exact child route, class closure before children, and compiler unwind/scalar/vtable/adjustor exclusions.

by-file replacement UID0000HX:
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md) : reconstructable : 91% : very-strong : NexusTK/ui/dialogs/BulletinSession.cpp source root with one position-0 g_pBulletinSession definition, complete DialogSession plus Singleton<BulletinSession> class/header route, exact 0x104 EBO layout, six constructor modes/callers, authored constructor and empty ordinary destructor with implicit singleton lifetime, source-ready Event packet override and existing seven method bodies, retained dispatcher/inline-duplicate/raw-helper no-code distinctions, exact core ranges/padding, UID0004UT compiler vtable data, UID0004US UserPane-owned cross-file lazy helper relationship, and no physical/scalar/vtable duplicate emission.

by-file replacement UID0000P1, retaining the complete current shared union and adding only the final bounded clause:
- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 93% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, corrected helper declarations, signed plain-char StartDirectionalAnimation(char direction) with signed-short MonsterObject frame-duration image-table/group/frame path, signed non-monster scaled-delay arithmetic, event-20 scheduling, branch-specific ordering, and branch-local MapPane refresh, corrected opcode-0x13 movement-target sender using MapPane collect/sort with exact count-versus-nine cap/local terminator behavior, preserved action/adjacent-target fields, packet ABI, movement-history, server, target, and caller evidence, source-ready opcode-0x0f ParseInventorySlotUpdatePacket using signed one-based slots, three explicit ACP text conversions, the exact 508-byte inventory record with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, active UserStatusPane slot-count bound, exact write order, and preserved invalid-slot/always-false behavior, source-ready opcode-0x08 settings parsing with exact state indices, 2/31 offset arithmetic, packet cursor/store order, blindness invalidation, movement-state/TryStepForward order, ten ordered direct config stores, SoundManager enable/mirror order, active GeneralPurposePanel child-6 OnActivate refresh, and adjacent movement-reply index-3 versus index-4 corrections, source-ready opcode-0x05 HandleServerEntryPacket with duplicated EPF/legacy SpelledPane refresh, sender re-enable, transfer-overlay deferred deletion, object/facing/status-icon application, MapPane bounds refresh, and block/listen replay, plus exact HandleKeyOrTextEvent(Event *) entry gates/modifier and key switches/handled returns/packet order and source body, two slot-range methods, opcode-7 sender, current B002 UID0004R9 preservation, target-selection cross-TU declarations, compiler switch/vtable exclusions, retained raw/inline-equivalent history, exact source order, no UID0003V9 empty emitter or duplicate body, UID0003UB's exact source position, three-page caller route, 30-row Text/Spell/Item behavior, helper/packet dependencies, retained UID0000FQ emitter route, complete Config table declarations, exact retained UID0003UA compact-shortcut source, and exact final-byte plus 68-byte m_currentAppearance tail used by MapPane; UID0003UB's earlier blank-formal artifact remains separate historical debt rather than a current Config blocker; retains exact private IsGroupMember and AdvanceMovementSendTick definitions with class closure, source order, and compiler exclusions; adds typed +0x3cb1 hunters-list flag, +0x3cb2 wchar_t[256] party-search source text, two residual bytes, and inline accessors without changing the 0x13eb84 layout or any prior source union fact; exposes the inline const GetSpellPromptText(char) source accessor for cross-TU spell prompt consumers without changing the SpellCommandSlotRecord layout, object size, generated route, or any existing UserPane behavior; exact UserPane +0x210 pending-target ObjectPane pointer and inline ClearPendingTargetObject() used by UID000364, with all later offsets and complete 0x13eb84 union preserved. The callback adds the exact ClearDeferredUserListPacket definition in source order; it frees and clears pointer/count/deadline only, preserves size and active state, is called by UID0003TY after the transition send, and leaves the complete current UserPane union unchanged; adds exact externally linked EnsureNormalBulletinSession at 0x005a50a0-0x005a5103 with four IconsPane/UserPane callers, null guard, source new BulletinSession(1, 0, false), exact hash/padding, UserPane-local-player helper placement, and no change to UserPane class layout or any existing shared source fact.
```

No by-struct coverage root is affected. Tracker regeneration is validator-owned; do not hand-edit it.

## Follow-Up Actions

- The accepted callback applied C01-C20/R0-R8 and every ordinary destination using serial one-file leases, scoped validators, immediate releases, validator-issued UID0004US/UID0004UT, and waited generated refreshes.
- No B003 implementation item remains. External supervisor commands `15723`-`15726` applied and validated the exact manual coverage handoff; B003 did not edit those roots.
- Exact later validation, report count/path, execution, move/archive, and lifecycle state is external supervisor/validator-owned state and is neither asserted nor directed by this artifact.

## Confidence

- Target bytes/range/PE meaning/xrefs: very strong.
- Physical/semantic ownership and one-definition route: very strong.
- Direct Singleton inheritance/PMD/EBO/lifecycle source cause: very strong.
- Class size/member widths and `m_pendingListResponse`/`m_activeListId` descriptive names: strong to very strong; exact original lexical spellings remain inferred.
- Packet override signature/Event access: very strong for ABI/type/behavior, strong for descriptive method name already fixed by EventHandler convention.
- Lazy helper source name/placement: strong; behavior/linkage/callers are exact, original lexical spelling is unavailable.
- Scores are capped below perfect for lexical/header factoring and broader non-emitting duplicate-inline BulletinSession children, not unresolved target behavior.

## Validator Results

All listed scoped commands ran from canonical `source-3/project-documentation` with `--apply --queue-timeout 240`; each returned exit `0`, `ok:1`, and deferred generation unless marked waited. Each existing ordinary page was leased only for its own reread/edit/validation and released immediately. New pages were registered serially through the validator workflow before dependent links were validated.

| Destination | Validator command / timestamp | Result and side effects |
| --- | --- | --- |
| UID0004US new helper | `15650` / `2026-07-21T09:29:16-04:00`; final metadata `15702` / `09:51:51` | Issued real UID0004US, then validated final R6 and stored `Nested:4`; exit 0/ok 1. Intermediate `15700` normalized invalid literal `+4`, reported one validator-owned coverage-metadata repair, and was superseded by clean `15702`. |
| UID0004UT new compiler data | `15651` / `09:30:29`; repair `15729` / `2026-07-21T10:41:39-04:00` | Command `15651` issued real UID0004UT. Repair command `15729` validated hash `878879115B21E10AB1CF8A921025493E35C04B82A3021A262EDBEB773D358766`, stored `Nested:4`, physically blank R7 formal, and retained prose no-array proof; exit 0/ok 1 with no `emitter_inactive_has_data`. Side effects were validator-owned registry block-to-blank and projected-stats updates; generated refresh deferred. |
| UID0001KO / UID0002RX | `15654` / `09:32:17`; `15655` / `09:32:52` | Both exit 0/ok 1; helper inventory added and successor-only nesting correction applied. Validator also normalized stale renamed UID0003UR links on UID0001KO. |
| UID0001KL / UID0001KM / UID0000P1 | `15657` / `09:33:46`; `15660` / `09:34:55`; `15661` / `09:35:33` | Exit 0/ok 1; complete shared UserPane union preserved. Missing-reference warnings for unrelated historical UID0003V8/UID0003VC/UID0003JN/UID0003J2 remain external pre-existing debt. |
| UID0001PA / UID0000QG / UID00001D | target repair `15728` / `2026-07-21T10:39:46-04:00`; final target prose repair `15732` / `10:44:58`; retained QG/class `15667/15669` | UID0001PA command `15728` changed the registry block to blank; command `15732` validated final hash `6EA66C96FE9F2DCFDF2BEB255F51D7B8F6D4663AF921592B9CA282155871E364`, physically blank R0 formal, and prose no-duplicate proof. Both exit 0/ok 1 with no `emitter_inactive_has_data`; `15732` had projected-stats/no-op side effects and deferred generation. QG/R1 and class/R2 remain unchanged and validated. |
| UID0004FS / UID0004FT / UID0004FY / UID0003Q4 | retained `15671/15674/15676`; UID0003Q4 repair `15730` / `2026-07-21T10:42:43-04:00` | R3/R4/R5 remain exact. Repair command `15730` validated UID0003Q4 hash `D522B58214623D47362F7DD04ADE8EE40FF1BE0710C4DC83D0589E971A86636E`, physically blank R8 formal, and retained prose wrapper proof; exit 0/ok 1 with no `emitter_inactive_has_data`. Side effects were validator-owned registry block-to-blank and projected-stats updates; generated refresh deferred. |
| UID0000HX / UID00024W / UID0002MI / UID0000ZH | `15685` / `09:44:35`; `15687` / `09:45:39`; `15692` / `09:47:48`; `15696` / `09:50:26` | All exit 0/ok 1; full BulletinSession, board/mail, sibling-nesting, and 17-child core unions preserved. |
| Final waited BulletinSession | repair checkpoint `15731` / `2026-07-21T10:42:55-04:00`; final after target prose readback `15733` / `10:45:13` | Both exit 0/ok 1 with completed generated refresh. Command `15733` is authoritative for this repair; its project-wide fallback/marker/no-code diagnostics concern unrelated UIDs, while UID0001PA/UID0004UT/UID0003Q4 have no `emitter_inactive_has_data`. Generated BulletinSession/UserPane/IconsPane semantics remain unchanged. |

Supervisor waited command `15727` is preserved as the historical Gate 2 failure that correctly rejected comment-bearing false-page formals. It is superseded by warning-free scoped commands `15729`, `15730`, and `15732` plus waited command `15733`; the earlier `15664/15679/15704` inactive-emitter diagnostics are historical rejected states, not expected or accepted warnings. Validator-owned deferred tracker command `15708` was the first post-callback metadata snapshot; deferred external command `15716`, refreshed `2026-07-21T10:07:24-04:00`, remains the captured evidence-time tracker checkpoint. B003 did not edit validator state, tracker, generated source, or manual coverage directly.

External supervisor coverage commands `15723`, `15724`, `15725`, and `15726` applied and validated the exact by-memory, by-global, by-class, and by-file rows respectively. Current root hashes/metrics and unique row positions are recorded in the Exact Manual section. These are supervisor actions and read-only evidence, not B003 validator or coverage edits.

Final managed-block comparison proves R1-R6 byte-for-byte parity with their emitting destinations and proves R0/R7/R8 each have a physically blank body between the literal BEGIN/END lines. Their complete no-duplicate/compiler/no-array rationales remain outside the formals in report and ordinary prose. No source statement, no-code disposition, or accepted behavior changed.

Generated assertions proven at final B003 waited command `15733`:

- `BulletinSession.cpp` SHA256 `36B2AFF423C961E57C859139AA18E449E776329182B9B8A7D2D4406A17ABC1E4`, 5,784 bytes / 167 lines, header command `15733`: one R1 definition at line 10, one extern at line 17, complete class closed at line 43 before eight qualified definitions, R3 line 46, R4 line 72, R5 line 114, and each other accepted method once. The only `g_pBulletinSession =` is the sole definition; no constructor/destructor write exists. UID0001PA/UID0004UT/UID0003Q4 text count, Empty Emitter Marker count, and forbidden handwritten RTTI/vtable/PMD/adjustor/scalar/EH/cookie/base-teardown count are all zero.
- `UserPane.cpp` SHA256 `C724E2B1B451B84E0E6345F4503AF05EFDD7BE01160F70A160AD59BE093FD503`, 92,016 bytes / 2,784 lines, header command `15733`: UID0004US/R6 exactly once at lines 2692-2697, one modeled UserPane call, and no UID0004US marker or duplicate body. `IconsPane.cpp` SHA256 `89985DE03B386850601DFC34BB2A35ACE698CD3390DC7ABD13D0086074134BC8`, 7,839 bytes / 283 lines, retains two source calls; the fourth raw caller remains binary-only evidence. The sole unrelated UID0003UB marker does not concern this callback.
- Tracker command `15716`: SHA256 `612E863B3D135D169A5BB7ABCE4CFB14CBBB22914457AF201D728CE976E401B3`, real UIDs UID0004US/UID0004UT, exact implemented scores/true-false/owners/emitters, and zero provisional assignment placeholder. A full report/by-memory scan also found zero provisional token.

## Changed Files

- Callback report: `tools/leaser/Agents/Agent-B003/research/0001PA-g_pBulletinSession-source-quality.md`.
- New ordinary pages: UID0004US `B90659CC6AE6335984DA3EC4F73C89D79F1580EF741763D1976A423D4740FBCE`; UID0004UT `878879115B21E10AB1CF8A921025493E35C04B82A3021A262EDBEB773D358766` after the focused blank-R7 repair.
- Changed BulletinSession ordinary pages: UID0001PA `6EA66C96FE9F2DCFDF2BEB255F51D7B8F6D4663AF921592B9CA282155871E364`; UID0000QG `F1797D3F427E9A785825EB02FF1F76CFA1277DA042A4A54D13D476BEE04BAA8E`; UID00001D `0224D9C46639757EABCF610276EC673B2A2A961AC0CBBFCE15C3D1408EE92F7B`; UID0000HX `CFEF643566E64BA32E9ADEE03AA345D8DE4897D0F8F15F41844A3D9A456846C8`; UID0000ZH `38ACFAB47655E4DE5D13A5118E0EAFEF9187DDE9B0D719F49FC8B17908D82146`; UID0004FS `9AF3D719E88E074E3C49CE54A8E820B9473290B2F968EFD87145A18DA2F20704`; UID0004FT `7E5D5D43294B26D0AB9B5BF0AB316FDE5A0F37972E7E0C02B7D5141B9D5DA4C8`; UID0004FY `5A48F0DE01407B7BCD5981090A045DF9B2666D85CD76C0CE1E22A15506E46BF2`; UID0003Q4 `D522B58214623D47362F7DD04ADE8EE40FF1BE0710C4DC83D0589E971A86636E`.
- Changed UserPane support: UID0001KO `2756EC07C39B63B3245B1292EE3616D84925A0D5756D0E1E38C7EB67A14D2BF9`; UID0002RX `15463F9BC9B380F96A181B905E749A730CCD3E3DB038AB09CA7628D97D8CF9A1`; UID0001KL `151BA81756A0A35C9CEC7E765055458CADE4EB2D05BDF6FE4850F4704133DAD9`; UID0001KM `7F0DD0AEBDE7F4199DD66DF421B70211C9BCB9D6EDFBA46F364B712B47F9933F`; UID0000P1 `DEF087A16BF5B2F19A23DE9AD1053ABFD7BE0CDBAADC8C5C4763E10EAD3787FB`.
- Changed board/mail support: UID00024W `43F067548C9BE4BAFA9CE105E96E026613D3080414A7A0E4DE4ACDC9F98BC9C6`; UID0002MI `39565580B1467803786834F52CCFA5A056FE51EC0F20764CD1EE97FCC79E96AF`.
- Focused Gate 2 formal-block repair changed exactly `by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md`, `by-memory/0x00613b1c-0x00613ba4.BulletinSessionVtableData.md`, and `by-memory/0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor.md`; no other ordinary page changed during this repair.
- Verify-only unchanged: UID0003Q1 SHA256 `D94EA652EE9917201EE7369D7BECA67D846EBE60C957611F246A5AE913B3E095`; UID0002VE SHA256 `171B2476FED0CFA2277BED72F92B76F23E8FDC0AD52D9D507FDCB80ED382B9A1`, stored `Nested:0`; consumer/source dependencies were reread and not edited.
- Current supervisor-owned coverage roots are by-memory `9CE3FC30E4044223E32AF350E335749165FCCF3243439E815CE1CF63ED4489C4`, by-global `642D74472052A7151C1FCC41072DF99538DB2F341B7AC3541E8648FDF9671380`, by-class `B25AD1844D78C766EBC8E18E6DE9FB93E786D399117296DE7588D639F06C4E25`, and by-file `44613BF3C357A09A0005DAEFF582814184EC77D7C9A8064FFAC0DCC00184C4DE`; commands `15723`-`15726` applied them externally.
- This reconciliation changed only this report. B003 manually changed no coverage, ordinary, generated/tracker, audit/supervisor, validator-state, IDA, lifecycle, or archive file and ran no validator. Final lease ledger contains zero B003 rows.

## Implementation Tracking Checklist

- [x] Re-read goal, accepted exact report hash, current leases, and every destination immediately before callback.
- [x] Confirmed no material IDB epoch change required a new MCP evidence conclusion; the accepted healthy-session evidence remains the implemented provenance.
- [x] Registered UID0004US serially through validator-supported new-file workflow; command `15650` issued the UID without guessing.
- [x] Replaced every provisional helper token before dependent validation; no provisional assignment placeholder remains.
- [x] Created UID0004US exact path/range/metadata/R6/evidence and validated final state with command `15702`.
- [x] Registered UID0004UT serially; command `15651` issued the UID without guessing.
- [x] Replaced every provisional vtable token before dependent validation; no provisional assignment placeholder remains.
- [x] Created UID0004UT exact path/range/metadata, physically blank R7 formal, prose no-array evidence, and validated final state warning-free with command `15729`.
- [x] Applied UID0001PA `92/94`, false/no-emitter, physically blank R0 formal, exact prose zero/PE/xref/no-duplicate/history evidence, retained Nested -4, and validated final state warning-free with command `15732`.
- [x] Applied UID0000QG `92/94`, position 0, exact R1, sole-definition and direct-Singleton lifecycle evidence.
- [x] Applied UID00001D `92/94`, exact complete R2, class closure, hierarchy/layout/access/history evidence.
- [x] Applied UID0000HX `91/93` no-loss source/compiler/global/helper/vtable union.
- [x] Applied UID0004FS `91/94` exact R3 and all retained caller/mode/boundary evidence.
- [x] Applied UID0004FT `91/94` exact R4 and all retained range/no-route/compiler evidence.
- [x] Applied UID0004FY `92/94` exact R5/Event/interface/vtable/source evidence.
- [x] Applied UID0003Q4 `92/94`, false/no-emitter, physically blank R8 formal and full compiler ABI/no-code evidence in prose; validator `15730` is warning-free for this target.
- [x] Verified UID0003Q1 unchanged at SHA256 `D94EA652EE9917201EE7369D7BECA67D846EBE60C957611F246A5AE913B3E095` and linked it only through bounded compiler-lifetime prose.
- [x] Synchronized UID0000ZH without score/route/formal/range/child/padding loss.
- [x] Synchronized UID0001KL and UID0001KM with UID0004US without shared-union loss.
- [x] Synchronized UID0001KO, retained false/mixed/no-code state, and inventoried UID0004US as non-say source.
- [x] Changed UID0002RX only stored `Nested:4 -> 0` plus predecessor/history; score/owner/emitter/formal/evidence are preserved.
- [x] Synchronized UID0000P1 after one-file lease reread/rebase; preserved every current shared UserPane fact.
- [x] Synchronized UID00024W with UID0004UT while preserving all 141-head/mixed-source data facts.
- [x] Changed UID0002MI only stored `Nested:4 -> 0` plus predecessor link; preserved score/owner/emitter/formal/evidence.
- [x] Verified UID0002VE and later board/mail children remain Nested 0 and otherwise unchanged; UID0002VE hash is recorded above.
- [x] Verified predecessor/successor physical slot pages and aggregate levels remain unchanged around UID0001PA.
- [x] Verified MapPane opcode-0x31 null/bit guard and mode-0 construction unchanged.
- [x] Verified compact `0x00513bb0` packet helper null/bit guard and mode-0 construction unchanged.
- [x] Verified ParcelPane direct `new BulletinSession(1,0,true)` route unchanged.
- [x] Verified IconsPane raw/modeled calls use `EnsureNormalBulletinSession` and retain all other action helpers.
- [x] Verified UserPane key and panel-switch caller evidence preserves current behavior and R6 routing.
- [x] Verified MenuVariety selection-2 direct construction remains unchanged.
- [x] Ran one scoped validator per actually changed/new ordinary by-* page while its short lease was held; focused formal repair commands are UID0001PA `15728/15732`, UID0004UT `15729`, and UID0003Q4 `15730`.
- [x] Released each ordinary lease immediately after edit/scoped validation and held no batch leases.
- [x] Ran final authorized waited BulletinSession generated refresh after all focused repairs, command `15733`.
- [x] Ran final waited UserPane generated refresh for UID0004US, command `15706`.
- [x] Proved one R1 definition, one extern, complete class closure, R3/R4/R5 once, and each existing method once.
- [x] Proved R6 once, three generated caller expressions plus the retained fourth raw caller, and zero duplicate helper bodies.
- [x] Proved zero UID0001PA/UID0004UT/UID0003Q4 text or Empty Emitter Markers, plus zero UID0000QG/UID00001D Empty Emitter Markers, at command `15733`.
- [x] Proved zero handwritten vtable/RTTI/PMD/adjustor/scalar/EH/cookie/base-teardown output.
- [x] Confirmed no provisional assignment placeholder remains anywhere in the report or by-memory destinations.
- [x] Updated C01-C20 to legal claim-specific terminal states with exact destination and validator/generated proof.
- [x] Updated Current Target State, R0/R7/R8, C06/C14/C18/C19, Validator Results, Changed Files, hashes, generated assertions, and lifecycle-neutral wording to the warning-free command-15733 repair epoch.
- [x] Preserved the exact supervisor-owned manual coverage handoff as applied audit text, verified every row uniquely in current roots, recorded external commands `15723`-`15726`, and did not manually edit coverage.
- [x] Checked each checklist row only after independent readback proved it.
- [x] Confirmed no B003 lease remains.
- [x] Confirmed B003 did not run/probe `execute_report` or any lifecycle/move/archive command.
- [x] Ended the callback artifact with the exact supervisor-requested readiness marker only after every accepted item was complete.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000015749","destination_path":"executed-b-agent-research/B003/0001PA-g_pBulletinSession-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001PA-g_pBulletinSession-source-quality.md","timestamp":"2026-07-21T11:09:42-04:00","uid":"0001PA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
