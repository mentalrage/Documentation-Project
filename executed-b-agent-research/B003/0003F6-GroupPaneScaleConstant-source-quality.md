# UID0003F6 GroupPane Scale Constant Source-Quality Report
** TARGET-REPORT-UID:0003F6 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Primary target: [UID:0003F6][by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md].
- Assignment history: the first phase was report-only research. The accepted ordinary callback subsequently updated and scoped-validated the target plus four support documents without editing manual coverage, IDA, generated files directly, tracker/audit state, or lifecycle state.
- Applied source-quality disposition: [UID:0000JS] `Group.md` remains canonical owner and emitter, `RECONSTRUCTABLE:TRUE` remains, and this compiler-pooled constant is represented through the two existing `100.0` expressions in [UID:0004Z5] `NewGroupPane::OnPaint` plus the exact covered-by marker.
- Physical range disposition: `0x00624bd0-0x00624bd8` is the unique little-endian IEEE-754 double `100.0`; `0x00624bd8-0x00624be0` is eight unreferenced zero alignment bytes before the 16-byte item at `0x00624be0`.
- Formal target CPP state: the covered-by marker is installed; emitting a named static object would invent source structure and duplicate the two exact use-site literals.
- Formal target H state: blank; the original source requires no declaration for a pooled numeric literal or alignment bytes.
- Applied metadata: completion `94`, confidence `96`, canonical owner `0000JS`, reconstructable `TRUE`, emitter `0000JS`, blank optional position.
- All identified ownership, placement, liveness, range, code, header, naming, generated-output, score, and coverage questions are resolved below. No blocker is deferred.

## Supporting Research

- Assignment-time target receipt (pre-callback): SHA256 `628249AAB03453AC3F9759E495BABC44F15671904BD739CBF7F06DD8132AFE17`, 3,138 bytes, 52 physical lines.
- Assignment-time/pre-callback support-page snapshots:
  - [UID:0004Z5] `by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md`, SHA256 `5CFF72818A0EDA17BF9744071D57CFEBC6D1B2E14C774D5E99165143A2F5AF9E`.
  - [UID:000090] `by-class/NewGroupPane.md`, SHA256 `649D87E9CCB3792C05902C442BAE0BB5E8A4395AF95D7060E911F26B1F090041`.
  - [UID:0000JS] `by-file/Group.md`, SHA256 `3E3DFAB9757588CF301EE2D72FA31AD51BC69E2697F6A8B9D1B3415B81F49C6C`.
  - [UID:0002V2] `by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md`, SHA256 `AACD8753E15751AF7DCE828586F80B8BFC1B15E768EA6D8BDE2BC2A80BBD17BB`.
  - [UID:0001HC] `by-memory/0x0056c4c0-0x0056e939.GroupPanes.md`.
- Matching older research was checked for provenance and superseded assumptions: B001's UID0002V2 split report, B002's UID000090 class report, and the analogous pooled-literal/covered-by reports already incorporated into nearby children. Their useful provenance is preserved; their generic `GroupPane family` wording is narrowed here to `NewGroupPane::OnPaint`.
- Dated generated read-only snapshot: `auto-generated/NexusTK/social/Group.cpp`, validator command `000000023950`, refreshed `2026-08-15T04:26:59-04:00`, SHA256 `C0678D8B5196000362FB820E3D718BD37D3D1D95E2B110C1325CEA69B0178263`, 52,287 bytes, 1,430 lines.
- That pre-callback snapshot already contained both complete `* 100.0` expressions at lines 299-300 and 346-347, but line 1428 still held an empty emitter marker for UID0003F6.
- Applied ordinary destinations after scoped validation: target SHA256 `7BE11493D11510401FFE3CE863AD03A1C7352AC2318DF241EDBA61EF18CF2A6F`; UID0004Z5 SHA256 `6DAB2D739B4D5F39E5E73A991391D14CA79D0BC4FD4F38935222A909547F0006`; UID000090 SHA256 `2ED259FAD17E938302EAA214AF3806ADFEB380E57AD869061F45D3687FC9DE20`; UID0000JS SHA256 `C9D131F21D48AABDA324E6EB8349061BD2E06E62CF7AB6A7EDBCCBC87E5D269B`; UID0002V2 SHA256 `1352A7DEA0DD29EFA57D2FBF72C56ED6EE26DD426DD10D244551CE8BDFCC89D5`.
- Dated callback generated receipt: validator command `000000024201`, refreshed `2026-08-15T07:38:29-04:00`; `Group.cpp` SHA256 `4C221E2164AC11F69275923B0DC04171678A9AD4623BA73C5F2AA7AE42053D56`, 52,510 bytes, 1,432 lines; `Group.h` SHA256 `2ABFC4AE921D83F78A0F63B5F42D17012EEEFEA4AE2F1CFF0385D22F11CFC5F3`, 1,851 bytes, 50 lines.
- Nearby precedent [UID:0003F7] represents compiler-pooled data through a formal covered-by marker and a source-local use-site expression rather than a duplicate static object. This target uses the same project convention.

## Target

- UID: `0003F6`.
- Path: `by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md`.
- Half-open range: `[0x00624bd0, 0x00624be0)`, exactly 16 bytes.
- Current title: `GroupPane Scale Constant`.
- Assignment-time metadata was completion `85`, confidence `88`, canonical owner `0000JS`, reconstructable `TRUE`, emitter `0000JS`, blank optional position, blank formal CPP, and blank formal H.
- Applied metadata is completion `94`, confidence `96`, canonical owner `0000JS`, reconstructable `TRUE`, emitter `0000JS`, blank optional position, nonblank covered-by CPP, and blank formal H.
- The assignment-time queue condition was an uncovered reconstructable target with an empty generated emitter marker. Callback command `000000024201` replaced that empty marker with the accepted non-empty covered-by marker.
- Primary semantic consumer: `NewGroupPane::OnPaint`, not a generic base `GroupPane` method.

## Current Target State

- The target now records the exact two expressions, full 16-byte split, eight-byte alignment tail, unique literal bytes, exact xref sites, `NewGroupPane` consumer, ownership ranking, rejected alternatives, and generated closure.
- The stale C++ deferral is historicalized. The formal CPP contains the exact covered-by marker and formal H remains blank.
- Callback command `000000024201` generated one non-empty UID0003F6 marker at `Group.cpp` lines 1413-1414 while retaining the HP and MP `100.0` expressions at lines 299-300 and 346-347.
- The current by-memory manual coverage report remains unchanged by B003 and has no UID0003F6 row; C-F6-024 supplies the exact supervisor-owned insertion.
- The accepted IDA source-quality actions remain supervisor-owned under C-F6-025 through C-F6-030. This report does not claim a current Gate 2B state.

## Executive Recommendation

1. Applied: document the exact physical split, one `double 100.0` plus eight zero alignment bytes.
2. Applied: document both direct reads and their HP/MP percentage roles in `NewGroupPane::OnPaint`.
3. Applied: retain the Group file owner/emitter route and identify [UID:000090] and [UID:0004Z5] as semantic class/method consumers rather than competing physical owners.
4. Applied: install the exact covered-by comment in target formal CPP and keep formal H blank.
5. Applied: raise only the target to `94/96`; support-page scores remain unchanged.
6. Supervisor-owned: apply the exact missing by-memory manual coverage row supplied below.
7. Supervisor-owned Gate 2B: apply the separate collision-checked IDA rename, type, and repeatable-comment actions to the literal, add the repeatable alignment comment to the tail, and protect the consumer function and successor item unchanged.

## Supervisor Active Recheck

- Reread the target and all proposed support destinations before accepting implementation.
- Recheck the exact 16 target bytes, item heads, target/padding/successor xrefs, and the two `mulsd` sites in the active canonical IDB.
- Confirm `NewGroupPane_PercentScale` still has no exact or case-insensitive collision before any rename.
- Execute Section 21 actions strictly in dependency order and stop on any prestate or intermediate-readback mismatch; do not adapt by discovery.
- Independently verify the applied formal CPP/H channels, source-route metadata, score changes, validator receipts, generated closure, and exact still-unapplied manual coverage row.
- Treat generated output as mutable validator-owned projection: physically reread the current `Group.cpp` rather than treating the dated command `000000023950` snapshot as permanent authority.
- Report execution/archive truth is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Inference Research Guidance Check

- Binary fact establishes value, bytes, item boundaries, xrefs, consuming instructions, and the absence of a referenced second object.
- Documentation fact establishes the Group/NewGroupPane source tree, canonical owner conventions, and complete method-level formal source.
- Inference is required only for the lost lexical source shape and IDA-facing descriptive name.
- The strongest source-shape inference is two inline `100.0` literals in the owning method because the existing formal source places them directly in the HP and MP expressions and no binary evidence requires a named C++ object.
- The strongest IDA-facing descriptive name is `NewGroupPane_PercentScale`; it records the actual consumer and semantic unit while not claiming recovery of an original symbol.
- Wave2/Wave3 terminology encountered in older material is ignored as stale workflow framing and is not evidence.

## Heuristic / Inference Reanalysis And Validation

- Candidate: standalone `static const double`. Rejected. It would create a source object and declaration absent from the recovered source shape; both observed uses are naturally written as `100.0`.
- Candidate: one local named `percentScale` variable in `OnPaint`. Possible but less likely. The compiler-pooled storage can arise from repeated identical literals, and the source currently has two direct literal expressions. There is no address-taking, write, or third use that favors a named variable.
- Candidate: two unrelated constants accidentally pooled. Source-equivalent and binary-consistent, but still represented correctly by two inline `100.0` literals.
- Candidate: second `double 0.0` at `0x00624bd8`. Rejected. It has no name, no xrefs, and occupies the exact padding needed to align the next 16-byte item at `0x00624be0`.
- Candidate owner [UID:000090] or [UID:0004Z5]. These are the semantic consumer/class and should receive dependency detail, but current project routing assigns compiler-pooled source-local data to the emitting file. No metadata route change is needed.
- Candidate no-owner/non-emitting disposition. Rejected because the source use is exactly reconstructable and already emitted by [UID:0004Z5].

## Evidence Standards Used

- Direct IDA facts: exact item boundaries, bytes, decoded value, xrefs, function identity/type/range, comments, and decompilation/disassembly.
- Direct filesystem facts: current by-* metadata/content, manual coverage absence, and dated generated source/hash.
- Documentation facts: source owner hierarchy, complete formal `NewGroupPane::OnPaint` source, and neighboring covered-by convention.
- Heuristic conclusions are labeled and ranked; none overrides contradictory direct evidence.
- Scores reflect both behavioral certainty and source-shape closure, not merely the presence of a plausible prose description.

## Evidence Checked

- Dated read-only IDA MCP observation at `2026-08-15T05:32:10-04:00`: session/database `483f8a19` and IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` were observed for this research pass. This is historical evidence only and is not current, active, sole, or canonical Gate 2B authority; the supervisor must obtain fresh public `runtime_attestation`, session, health, and item-prestate readback before Gate 2B.
- In that dated observation, server health was `status:ok`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `auto_analysis_ready:false` did not block the bounded reads, item inspection, xrefs, bytes, comments, or decompilation recorded as historical report evidence.
- `inspect_items` at `0x00624bc8`, `0x00624bd0`, `0x00624bd8`, `0x00624be0`, `0x0056d5b8`, and `0x0056d876`.
- `get_bytes` over the target and both consumer instruction windows.
- `xrefs_to` for the literal, alignment tail, and successor item.
- `get_comments` for the literal, tail, successor, and consumer function.
- Fresh decompilation of `NewGroupPane__OnPaint`.
- Global-name searches for `NewGroupPane`/`PercentScale` collision candidates and the current raw label.
- Current target/support documents, generated Group source, manual by-memory coverage, and matching historical reports.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|---|
| C-F6-001 | 0003F6 | The target is the exact 16-byte half-open range 0x00624bd0-0x00624be0 with SHA256 3F2F2A9DC01360F3C383FA53B3F2C5B2860A2A6D38F0197C2327BE38DAF280F0. | very-strong | Live bytes and item boundaries | Target Range and IDA Evidence | incorporate | applied |
| C-F6-002 | 0003F6 | Bytes 0x00624bd0-0x00624bd8 are the unique loaded-image little-endian double 100.0. | very-strong | Bytes 00 00 00 00 00 00 59 40 and unique byte search | Target Summary and Behavior | incorporate | applied |
| C-F6-003 | 0003F6 | Bytes 0x00624bd8-0x00624be0 are eight zero alignment bytes, not a source-level 0.0 object. | very-strong | Separate unnamed item, zero xrefs, 16-byte-aligned successor | Target Range and Negative Evidence | incorporate | applied |
| C-F6-004 | 0003F6 | The exact 100.0 byte pattern occurs once in the loaded binary. | very-strong | Live find-bytes result | Target IDA Evidence | incorporate | applied |
| C-F6-005 | 0003F6 | qword_624BD0 has exactly two data xrefs at 0x0056d5b8 and 0x0056d876, both in NewGroupPane__OnPaint. | very-strong | Live xrefs_to | Target Xrefs | incorporate | applied |
| C-F6-006 | 0003F6 | The first use computes currentHitPoints divided by maximumHitPoints times 100.0 before unsigned conversion and percent formatting. | very-strong | Live disassembly and decompilation | Target Behavior and UID0004Z5 | incorporate | applied |
| C-F6-007 | 0003F6 | The second use computes currentManaPoints divided by maximumManaPoints times 100.0 before unsigned conversion and percent formatting. | very-strong | Live disassembly and decompilation | Target Behavior and UID0004Z5 | incorporate | applied |
| C-F6-008 | 0004Z5 | The sole consumer function is NewGroupPane__OnPaint at 0x0056ce50-0x0056da03 with exact current type void __thiscall(NewGroupPane *this). | very-strong | Live function/decompile/item evidence | UID0004Z5 IDA and dependency sections | incorporate | applied |
| C-F6-009 | 0003F6 | The predecessor remains outside the target and the successor begins exactly at 0x00624be0 as xmmword_624BE0 for SelfLookPane_OnPaint. | very-strong | Item boundaries and xrefs | Target Boundaries | incorporate | applied |
| C-F6-010 | 0003F6 | Original source shape is two inline 100.0 expressions; no standalone C++ data object is emitted. | strong | Exact uses plus compiler-pooling inference | Target Source Placement | incorporate | applied |
| C-F6-011 | 0003F6 | Canonical owner and emitter remain Group file UID0000JS. | strong | Current routing and file-local pooled-data convention | Target metadata | already-present | already-present |
| C-F6-012 | 000090 | NewGroupPane UID000090 and method UID0004Z5 are semantic consumers, not replacement canonical owners for the pooled range. | strong | Sole function consumer and project routing | Class dependency notes | incorporate | applied |
| C-F6-013 | 0003F6 | RECONSTRUCTABLE remains TRUE because both source uses are exact and already represented. | very-strong | Complete formal method source and binary behavior | Target metadata | already-present | already-present |
| C-F6-014 | 0003F6 | Formal CPP contains only the exact covered-by marker for NewGroupPane::OnPaint HP and MP percentage expressions. | strong | No standalone source object; exact use-site source | Target formal CPP | incorporate | applied |
| C-F6-015 | 0003F6 | Formal H remains exactly blank because no declaration is required. | very-strong | Compiler-pooled literal/alignment disposition | Target formal H | already-present | already-present |
| C-F6-016 | 0003F6 | Target score is completion 94 and confidence 96 with owner/emitter/reconstructable/position otherwise unchanged. | strong | All blockers resolved and source closure exact | Target metadata | incorporate | applied |
| C-F6-017 | 0003F6 | Target prose incorporates full bytes, xrefs, behavior, range split, ownership, source placement, rejected alternatives, and no-code proof. | very-strong | Report evidence | Target all relevant sections | incorporate | applied |
| C-F6-018 | 0004Z5 | OnPaint support links both literal reads and physical UID0003F6 pool while preserving its complete formal source and metadata. | very-strong | Exact xrefs and current complete source | UID0004Z5 support detail | incorporate | applied |
| C-F6-019 | 000090 | NewGroupPane class support records the percentage-pool dependency without changing class ownership, emitter route, scores, or formal H. | strong | Sole class consumer | UID000090 dependency detail | incorporate | applied |
| C-F6-020 | 0000JS | Group file support contains percentage-scale closure and preserves existing file metadata and source order. | strong | File ownership and generated source | UID0000JS data/source closure | incorporate | applied |
| C-F6-021 | 0002V2 | Mixed parent describes the child as NewGroupPane 100.0 plus alignment rather than a generic GroupPane scale constant. | very-strong | Exact split and consumer | UID0002V2 child inventory | incorporate | applied |
| C-F6-022 | 0001HC | Broad GroupPanes aggregate already links UID0004Z5 and UID0000JS; UID0004Z5 now supplies UID0003F6 linkage, so no aggregate metadata, formal, or emitter edit is required. | strong | Existing child routing and applied UID0004Z5 dependency | UID0001HC cross-reference | already-present | already-present |
| C-F6-023 | 0003F6 | Validator output preserves the two existing 100.0 expressions and replaces the empty UID0003F6 marker with the formal covered-by marker. | strong | Dated generated callback readback | Generated Group.cpp readback | incorporate | applied |
| C-F6-024 | 0003F6 | Manual by-memory coverage closure is supervisor-owned and uses the exact Section 28 row after UID0003F5 and before the next top-level row. | very-strong | Dated read-only coverage receipts and exact placement text | by-memory/-coverage-report.md | incorporate | proposed |
| C-F6-025 | 0003F6 | IDA literal item should be collision-checked and renamed NewGroupPane_PercentScale. | strong | Sole semantic use and zero candidate collisions | Supervisor Gate 2B IDA-F6-01 | incorporate | proposed |
| C-F6-026 | 0003F6 | IDA literal item should receive exact type double after rename readback. | very-strong | Exact eight-byte IEEE-754 use | Supervisor Gate 2B IDA-F6-02 | incorporate | proposed |
| C-F6-027 | 0003F6 | IDA literal item should receive the exact repeatable semantic comment in IDA-F6-03. | strong | Two exact percentage uses | Supervisor Gate 2B IDA-F6-03 | incorporate | proposed |
| C-F6-028 | 0003F6 | The alignment tail should receive the exact repeatable alignment comment in IDA-F6-04 and remain unnamed/untyped. | very-strong | Zero xrefs and successor alignment | Supervisor Gate 2B IDA-F6-04 | incorporate | proposed |
| C-F6-029 | 0004Z5 | NewGroupPane__OnPaint name, type, comments, function range, bytes, and xrefs must remain protected unchanged. | very-strong | Fresh current function prestate | Supervisor Gate 2B IDA-F6-05 | already-present | proposed |
| C-F6-030 | 0003F7 | xmmword_624BE0 and its SelfLookPane xref remain protected and outside UID0003F6. | very-strong | Fresh item/xref boundary evidence | Supervisor Gate 2B IDA-F6-06 | already-present | proposed |
| C-F6-031 | 0003F6 | Every changed ordinary by-star page received scoped apply validation and fresh Group.cpp/Group.h physical readback under commands 24197-24201. | very-strong | Callback validator receipts and generated hashes | Validator Results | incorporate | applied |
| C-F6-032 | 0003F6 | All in-scope naming, type, owner, emitter, range, padding, liveness, source, code, header, score, generated, and coverage questions are resolved without deferral. | strong | Exhaustive evidence and ranked analysis | Open Questions | already-present | already-present |

## Positive Evidence Summary

- The target's first eight bytes decode exactly as `100.0`.
- The literal has exactly two reads and both belong to one source method.
- Both reads occur after floating-point division and immediately before unsigned conversion/percent formatting.
- The decompiler recovers field semantics for current/maximum HP and MP, and current formal source already uses those names.
- The physical literal pattern is unique in the loaded image.
- The trailing eight bytes have no xrefs and cleanly align the next 16-byte item.
- The current source tree and emitter hierarchy already provide an exact human-written destination.
- A neighboring compiler-pooled data child establishes a compatible formal covered-by convention.

## IDA MCP Facts

- Dated research observation at `2026-08-15T05:32:10-04:00`: session/database `483f8a19`, worker PID `16192`, and IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` were observed.
- In that dated observation, health was status OK, Hex-Rays ready, and image base `0x00400000`; all required bounded public reads completed successfully. The session, PID, path, and health values are historical evidence only and are not current, active, sole, or canonical Gate 2B authority; fresh supervisor public `runtime_attestation`, session, health, collision, and literal item-prestate readback is mandatory before any Gate 2B mutation.
- Target bytes: `00 00 00 00 00 00 59 40 00 00 00 00 00 00 00 00`.
- Target-range SHA256: `3F2F2A9DC01360F3C383FA53B3F2C5B2860A2A6D38F0197C2327BE38DAF280F0`.
- `0x00624bd0`: item `[0x00624bd0,0x00624bd8)`, size 8, name `qword_624BD0`, type absent, data, AR absent, AP absent.
- `0x00624bd8`: item `[0x00624bd8,0x00624be0)`, size 8, name absent, type absent, data, AR absent, AP absent.
- `0x00624be0`: item `[0x00624be0,0x00624bf0)`, size 16, name `xmmword_624BE0`, type absent, data, AR absent, AP absent.
- `0x00624bd0` xrefs: exactly `0x0056d5b8` and `0x0056d876`, both data reads in `NewGroupPane__OnPaint`.
- `0x00624bd8` xrefs: zero.
- `0x00624be0` xrefs: exactly `0x005676c7` in `SelfLookPane_OnPaint`.
- `NewGroupPane__OnPaint`: `[0x0056ce50,0x0056da03)`, size `0xBB3`, 728 instructions, current type `void __thiscall(NewGroupPane *this)`, AR absent, AP absent, FR absent, FP `Renders NewGroupPane background, member rows, names, status, HP/MP bars, and numeric glyph strings.`
- The exact literal pattern `00 00 00 00 00 00 59 40` has one loaded-image match at `0x00624bd0`.
- Searches found no `NewGroupPane_PercentScale` or `PercentScale` collision.

## Function / Child Inventory

| ID | UID/path/address | Role and evidence | Ownership/emitter/reconstructability | CPP disposition | H disposition | Generated state | Score/completion disposition | Required edit |
|---|---|---|---|---|---|---|---|---|
| T01 | UID0003F6 target `[0x00624bd0,0x00624be0)` | Exact literal plus alignment child | Owner/emitter 0000JS; reconstructable | Covered-by marker installed | Blank | Non-empty marker at dated callback lines 1413-1414 | Applied 94/96 | Applied |
| D01 | `0x00624bd0-0x00624bd8` | Unique double 100.0; two reads | Group file physical route; method use-site source | No standalone object | No declaration | Both uses retained | Complete covered-by closure | Applied target detail |
| D02 | `0x00624bd8-0x00624be0` | Eight zero alignment bytes; zero xrefs | Compiler/linker layout, no independent owner | No code | No code | Does not emit | Complete no-code disposition | Applied target detail |
| F01 | UID0004Z5 `0x0056ce50-0x0056da03` | Complete `NewGroupPane::OnPaint` consumer | Owner/emitter 000090; reconstructable | Existing complete method body retained | Class declaration already in UID000090 | Full definition and both literals retained | Metadata unchanged | Dependency detail applied |
| X01 | `0x0056d5b8` | HP percentage literal read | Inside UID0004Z5 | Existing inline `100.0` | None | Present at dated callback lines 299-300 | Complete | Physical pool linked |
| X02 | `0x0056d876` | MP percentage literal read | Inside UID0004Z5 | Existing inline `100.0` | None | Present at dated callback lines 346-347 | Complete | Physical pool linked |
| B01 | `0x00624bc8-0x00624bd0` | Predecessor/tail outside target | Previous child/data context | No target code | No target code | Unchanged | Excluded by exact boundary | None |
| B02 | UID0003F7 `0x00624be0-0x00624bf0` | Next 16-byte SelfLook constant; one other-function xref | SelfLook source route; reconstructable | Existing covered-by route | Blank | Separate marker/source | Metadata unchanged | Protect boundary |
| S01 | UID000090 `by-class/NewGroupPane.md` | Declares class and OnPaint override | Owner/emitter 0000JS | Children/source assembly retained | Complete class H retained | Feeds Group source/header | Metadata unchanged | Dependency note applied |
| S02 | UID0000JS `by-file/Group.md` | Source owner and source assembly | Canonical file owner | Percentage-scale closure prose added | Existing file assembly retained | Group.cpp owner | Metadata unchanged | Data closure applied |
| S03 | UID0002V2 mixed parent | Physical parent/index | NONE/non-emitting/not reconstructable | Blank | Blank | No direct source | 88/92 unchanged | Child description corrected |
| S04 | UID0001HC GroupPanes aggregate | Broad method/range index already links UID0004Z5 and UID0000JS | Non-emitting aggregate | No direct code | No direct code | UID0004Z5 now carries UID0003F6 dependency | Unchanged | Verified already present; no edit |
| G01 | Generated `social/Group.cpp` | Validator-owned source projection | UID0000JS | Method code retained; empty marker replaced | No target H | Dated callback command 24201 | Closure physically read | Applied/verified |

No function, helper, thunk, RTTI object, vtable item, writable global, additional constant, or source-bearing declaration is hidden inside the 16-byte target. The inventory is exhaustive for the target and all affected support routes.

## Direct Xref / Caller Inventory

| Target | Xref site | Function | Instruction/role | Source expression |
|---|---|---|---|---|
| `0x00624bd0` | `0x0056d5b8` | `NewGroupPane__OnPaint` | `mulsd xmm0, ds:qword_624BD0` after `divsd` | `currentHitPoints / maximumHitPoints * 100.0` |
| `0x00624bd0` | `0x0056d876` | `NewGroupPane__OnPaint` | `mulsd xmm0, ds:qword_624BD0` after `divsd` | `currentManaPoints / maximumManaPoints * 100.0` |
| `0x00624bd8` | none | none | no xref | alignment only |

- Both percentage results pass through `__dtoui3`, then the same percent-format path and `NewGroupPane::DrawNumberString`.
- `NewGroupPane__OnPaint` itself has one data/vtable reference at `0x00624598`; the percentage constant does not create a separate call route.
- No write xref, address-taken use, relocation-like pointer hit, immediate/pointer alias, or third consumer was found.

## Documentation Evidence And IDA Status

- The target's initial B001-derived prose correctly split the scalar constant from its mixed parent but left the consumer generic and CPP blank; the callback preserved that history while replacing its stale conclusions.
- UID0004Z5 now records the exact physical dependency while preserving exact source-facing field names, complete behavior, and both inline expressions.
- UID000090 now records the class-level dependency without changing its declaration or metadata.
- UID0000JS now records the exact file-level source/covered-by closure without changing file metadata or source order.
- UID0002V2 now identifies the exact NewGroupPane percentage double plus alignment while remaining a mixed no-owner/non-emitting container.
- The accepted IDA recommendations preserve their dated report prestate and deterministic supervisor transaction contracts. Current Gate 2B authority requires fresh supervisor readback; ordinary callback work did not mutate IDA.

## Ranked Ownership Analysis

1. **[UID:0000JS] Group file - accepted canonical owner/emitter.** The range is compiler-pooled read-only data used only by a method emitted through Group.cpp, and current project convention routes source-local pooled data through the source file.
2. **[UID:000090] NewGroupPane class - accepted semantic consumer, rejected as metadata replacement.** It owns the method but does not require a class member or declaration for the literal.
3. **[UID:0004Z5] NewGroupPane::OnPaint - accepted use-site source representation, rejected as a separate canonical by-memory owner.** Both literal uses belong in this method.
4. **Standalone static/global object - rejected.** No address-taking, write, named declaration need, or independent use supports it.
5. **[UID:0002V2] mixed physical parent - rejected.** It is an index over unrelated owners and intentionally non-emitting.
6. **SelfLookPane/adjacent constant owner - rejected.** The successor has its own item boundary and unrelated sole xref.

## Source Placement

- Source file: `NexusTK/social/Group.cpp` through [UID:0000JS].
- Semantic placement: inside `NewGroupPane::OnPaint`, once in the HP percentage expression and once in the MP percentage expression.
- Target-page placement: formal CPP covered-by marker after/through the file's child assembly; no independent definition or declaration.
- Header placement: none. The literal and alignment are implementation details and require no `Group.h` declaration.
- Source order: the target marker can remain in its current source/data child order after the complete method definitions; the marker documents physical coverage and must not duplicate runtime code.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is 16 bytes, not a single 8-byte object.
- Subrange A `[0x00624bd0,0x00624bd8)`: one IDA data item, semantic double `100.0`, two xrefs.
- Subrange B `[0x00624bd8,0x00624be0)`: one IDA data item, eight zeros, no name/type/xrefs.
- The tail is best classified as alignment because it places `xmmword_624BE0` on a 16-byte boundary and has no independent evidence.
- No new by-memory split is warranted: the target page should cover the literal and its immediately associated alignment as one exact compiler-layout child.
- Predecessor content ends at `0x00624bd0`; successor UID0003F7 begins exactly at `0x00624be0`. Neither should be absorbed.
- Reclassification from generic `numeric constant` to `compiler-pooled double literal plus alignment` is recommended in prose/coverage, not by changing the file path.

## Negative Evidence Summary

- No original symbol exists for the literal.
- No source declaration, address-taking use, or write supports a named standalone C++ object.
- No xref reaches the trailing eight bytes.
- No evidence supports decoding the tail as an independently authored `0.0`.
- No xref from GroupPane, GroupPane2, or another method reaches this constant; both reads are in `NewGroupPane::OnPaint`.
- No collision exists for the recommended descriptive IDA name at report time.
- No evidence supports moving the canonical metadata owner away from Group.cpp.
- No target-specific header code is required.
- No unresolved item blocks a score increase or formal covered-by closure.

## IDA Rename / Type / Comment Recommendations

These are deterministic supervisor Gate 2B handoff rows, not executable automation. The supervisor must re-read every prestate and stop on any mismatch.

| ID | Classification and dependency | Exact literal prestate | Public endpoint and exact action | Deterministic expected readback | Stop/rollback constraints |
|---|---|---|---|---|---|
| IDA-F6-01 | apply; first | `0x00624bd0`; data item `[0x00624bd0,0x00624bd8)` size 8; name `qword_624BD0`; type absent; AR absent; AP absent; FR not applicable; FP not applicable; bytes `00 00 00 00 00 00 59 40`; xrefs exactly `{0x0056d5b8 data, 0x0056d876 data}`; exact and case-insensitive `NewGroupPane_PercentScale` collisions absent | Public endpoint `rename`; literal current request shape and exact field names: `database:"<fresh supervisor runtime-attested session ID>", batch:{data:{old:"qword_624BD0",new:"NewGroupPane_PercentScale"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}` | Name exactly `NewGroupPane_PercentScale`; type absent; AR absent; AP absent; same data head/range/size/bytes/xref set | Stop before mutation if any prestate or collision differs. After rename, stop and rollback if any expected field, bytes, range, or xref differs. Do not overwrite another name. |
| IDA-F6-02 | apply; depends on verified F6-01 | Same item/range/bytes/xrefs; name exactly `NewGroupPane_PercentScale`; type absent; AR absent; AP absent; FR/FP not applicable | Public endpoint `set_type`; literal current request shape and exact field names: `database:"<fresh supervisor runtime-attested session ID>", edits:{addr:"0x00624bd0",ty:"double"}`. Optional schema fields `kind`, `name`, `signature`, and `variable` are intentionally omitted so the verified data item is auto-detected | Name exactly `NewGroupPane_PercentScale`; type exactly `double`; AR absent; AP absent; same data head/range/size/bytes/xref set | Stop if F6-01 readback is not exact. Stop and rollback if type is not exact or item/bytes/xrefs change. Do not use `const double` unless a later separately approved report changes the contract. |
| IDA-F6-03 | apply; depends on verified F6-02 | Same item/range/bytes/xrefs; name `NewGroupPane_PercentScale`; type `double`; AR absent; AP absent; FR/FP not applicable | Public endpoint `set_address_repeatable_comments`; literal current request shape and exact field names: `database:"<fresh supervisor runtime-attested session ID>", items:{addr:"0x00624bd0",comment:"Compiler-pooled 100.0 multiplier used by NewGroupPane::OnPaint HP and MP percentage calculations."}` | Name/type unchanged; AR absent; AP exactly proposed text; FR/FP not applicable; same item/range/size/bytes/xref set | Stop if F6-02 readback differs. Stop and rollback if comment text is not exact or protected state changes. Do not add a regular comment. |
| IDA-F6-04 | apply; independent after target prestate recheck | `0x00624bd8`; data item `[0x00624bd8,0x00624be0)` size 8; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; bytes eight zeros; xref count zero/set empty | Public endpoint `set_address_repeatable_comments`; literal current request shape and exact field names: `database:"<fresh supervisor runtime-attested session ID>", items:{addr:"0x00624bd8",comment:"Eight zero alignment bytes before the 16-byte constant at 0x00624BE0; not a source object."}` | Name absent; type absent; AR absent; AP exactly proposed text; FR/FP not applicable; same item/range/size/eight zero bytes; xref count zero/set empty | Stop if any prestate differs. Stop and rollback if name/type is created, bytes/item boundary changes, or any xref appears. Do not rename or type the alignment item. |
| IDA-F6-05 | no change recommended; protected consumer | `0x0056ce50`; function `NewGroupPane__OnPaint`; range `[0x0056ce50,0x0056da03)` size `0xBB3`; type `void __thiscall(NewGroupPane *this)`; AR absent; AP absent; FR absent; FP exactly `Renders NewGroupPane background, member rows, names, status, HP/MP bars, and numeric glyph strings.`; target reads at `0x0056d5b8` and `0x0056d876`; one function data/vtable xref at `0x00624598` | No endpoint call | Exact prestate remains unchanged | Any change to name, type, comments, range, target-read instructions, or xrefs is unauthorized. |
| IDA-F6-06 | no change recommended; protected successor | `0x00624be0`; data item `[0x00624be0,0x00624bf0)` size 16; name `xmmword_624BE0`; type absent; AR absent; AP absent; FR/FP not applicable; one data xref exactly `0x005676c7` in `SelfLookPane_OnPaint` | No endpoint call | Exact prestate remains unchanged | Do not rename, type, comment, merge, undefine, or resize the successor under this report. |

- Supporting type declaration: built-in `double`; no UDT declaration is needed.
- Gate 2B must preserve all executable bytes and all data bytes.
- The IDA name is descriptive project metadata. It must not be emitted as the C++ source identifier.

## First-Draft C++ Recommendation

- Eligible for formal target CPP: yes, as exact no-duplicate covered-by source representation.
- Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
// Covered by NewGroupPane::OnPaint() HP and MP percentage expressions.
```

- Exact formal `RECONSTRUCTION_H CODE` insertion text: empty.
- Runtime behavior remains in the complete method-level source, whose two expressions each multiply by `100.0`.
- This matches plausible mid-2000s human source better than a reverse-engineered `qword_624BD0` object or invented `static const double`.
- No IDA/compiler-generated name appears in emitted C++.
- The alignment bytes produce no C++.

## Final Recommendation

- Applied ordinary closure: all target/support detail changes in Sections 24 and 25 are present at report depth in the five changed ordinary documents.
- Applied route: owner/emitter/reconstructable remain `0000JS`/`0000JS`/`TRUE`.
- Applied score: only UID0003F6 changed, from `85/88` to `94/96`.
- Applied source: the exact formal CPP marker is installed and H remains blank.
- Verified generated closure: the complete UID0004Z5 method body and both inline `100.0` expressions remain; the empty UID0003F6 marker is gone.
- Supervisor-owned IDA closure: the four approved actions and two protected no-change checks remain C-F6-025 through C-F6-030.
- Supervisor-owned manual closure: the exact coverage row remains C-F6-024.
- No item remains no-owner by mistake, and no source-bearing behavior remains unrepresented.

## Recommended Target Doc Changes

- Path: `by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md`.
- Applied metadata: `COMPLETION:94`, `CONFIDENCE:96`, `CANONICAL_OWNER:0000JS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JS`, and blank `EMITTER_POSITION_OPTIONAL`.
- Applied Item Summary: `Compiler-pooled double literal 100.0 used twice by NewGroupPane::OnPaint for HP/MP percentage text, followed by eight zero alignment bytes; source is covered by the method use sites through Group.cpp.`
- Applied formal CPP: exact covered-by marker from Section 22.
- Applied formal H: blank.
- Applied detail: exact 16-byte range/hash, two item heads, decoded value, uniqueness, xref table, instruction/expression behavior, predecessor/successor boundaries, alignment proof, owner ranking, use-site placement, generated closure, rejected alternatives, and score rationale.
- Preserved B001 split history; generic `GroupPane family drawing/setup math` and stale final-C++ deferral are explicitly superseded.

## Recommended Support Doc Changes

- `by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md` [UID:0004Z5]: applied a physical pooled-literal dependency subsection with UID0003F6, both xref instructions, exact value/range/hash, alignment, HP/MP expressions, and authoritative inline-source/no-object disposition. Metadata, owner/emitter, formal CPP, and blank H are unchanged.
- `by-class/NewGroupPane.md` [UID:000090]: applied UID0003F6 class dependency evidence and the no-member/static/H-declaration disposition. Metadata, class H, child assembly, and source owner are unchanged.
- `by-file/Group.md` [UID:0000JS]: applied `NewGroupPane Percentage Scale Closure` with exact range split, xrefs, source representation, covered-by route, no-static-object rationale, and generated CPP/H acceptance. File score/metadata and source order are unchanged.
- `by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md` [UID:0002V2]: corrected both inventory descriptions and added an exact synchronization section. Its no-owner/non-emitting/not-reconstructable `88/92` metadata remains unchanged.
- `by-memory/0x0056c4c0-0x0056e939.GroupPanes.md` [UID:0001HC]: verified already-present UID0004Z5 and UID0000JS links. The newly applied UID0004Z5 dependency supplies the UID0003F6 linkage, so no aggregate edit, metadata change, formal code, owner change, or emitter change was required.
- No direct generated file edit is authorized.

## Score And Metadata Recommendation

| Field | Assignment-time | Applied |
|---|---|---|
| Completion | 85 | 94 |
| Confidence | 88 | 96 |
| Canonical owner | 0000JS | 0000JS |
| Reconstructable | TRUE | TRUE |
| Emitters | 0000JS | 0000JS |
| Optional position | blank | blank |
| Formal CPP | blank | exact covered-by marker |
| Formal H | blank | blank |

- Reason not lower: all 16 bytes, item boundaries, literal value, uniqueness, xrefs, consuming expressions, source owner, source placement, C++ disposition, H disposition, generated defect, coverage absence, and deterministic IDA handoff are closed.
- Reason completion is not 95+: the target is compiler-pooled evidence represented by a covered-by marker rather than a recoverable original declaration, and final project-wide lexical style remains inferred.
- Reason confidence is 96: binary behavior and range are direct facts; only lost lexical spelling and whether the original author repeated the literal or used a local constant remain inferential, without behavioral or emitted-source impact.
- Score-improvement blockers resolved:
  - Generic consumer name: resolved to `NewGroupPane::OnPaint`.
  - Unknown trailing bytes: resolved as alignment.
  - Blank formal C++: resolved with covered-by marker.
  - Original declaration uncertainty: resolved by rejecting an unsupported declaration.
  - Missing coverage: exact supervisor text supplied.
  - IDA compiler label/type/comments: deterministic handoff supplied.

## Open Questions With Attempted Resolution

- **Is the range one or two source constants?** Checked item boundaries, bytes, all xrefs, successor alignment, and nearby ownership. Resolution: one source-level `100.0` literal pool plus eight alignment bytes.
- **Which function uses it?** Checked all direct xrefs and decompiled both sites. Resolution: only `NewGroupPane::OnPaint`.
- **What do the two uses mean?** Traced surrounding fields, division, conversion, formatting, and generated source. Resolution: HP and MP percentage text.
- **Should C++ contain a static/global declaration?** Checked liveness, address-taking, writes, declarations, and source conventions. Resolution: no; retain two inline literals and a covered-by marker.
- **Who owns/emits it?** Ranked file, class, method, mixed parent, and standalone routes. Resolution: canonical/emitter UID0000JS; semantic use UID0004Z5.
- **Does it require header code?** Checked source shape and class declaration needs. Resolution: no.
- **Should the target split again?** Checked physical role and immediate alignment. Resolution: no; documenting the internal 8+8 split is sufficient.
- **What IDA source-quality changes are safe?** Checked literal prestate, comments, collisions, bytes, xrefs, and boundaries. Resolution: separate rename/type/comment plus alignment comment, with protected neighbors.
- Remaining unresolved questions: none in scope. Lost original lexical choice between repeated literals and a local constant is resolved to the highest-probability human source representation and does not justify deferral or a lower route.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected file: `by-memory/-coverage-report.md`, read-only.
- Dated callback-time receipt: SHA256 `3D7CAB8A214CECF99908DB6EBB39FD7BCEE65988840299CBB00D479D50E7DD69`, 2,232,606 bytes / 4,983 lines; UID0003F6 was absent, UID0003F5 was line 4588, and UID00026F was line 4589.
- Dated post-callback receipt observed `2026-08-15T08:13:17.0939628-04:00` after a later supervisor insertion: file last-write `2026-08-15T07:50:10.4368812-04:00`, SHA256 `03CB54181F4D5ACA43C5EBE7528F164C4A6C41A60A66FF3AD32E398EF22FC276`, 2,233,263 bytes / 4,984 lines; UID0003F6 was still absent, UID0003F5 was line 4589, and the next top-level UID00026F row was line 4590.
- Semantic supervisor placement is stable: place the exact UID0003F6 row after UID0003F5 and before the next top-level row. Line numbers and current coverage identity are supervisor-dynamic and must be reread at application time.
- Exact row:

`            - [UID:0003F6][0x00624bd0-0x00624be0.GroupPaneScaleConstant](by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md) 0x00624bd0-0x00624be0 | compiler-pooled double literal plus alignment | GroupPaneScaleConstant : reconstructable : 94% : very-strong : Exact 16-byte range containing double 100.0 at 0x00624bd0 plus eight zero alignment bytes; two NewGroupPane::OnPaint reads at 0x0056d5b8 and 0x0056d876 feed HP/MP percentage conversions; source is represented inline by UID0004Z5 and a formal covered-by marker, with no duplicate static object.`

- No by-class or by-file manual coverage row needs replacement because support metadata/scores remain unchanged; support prose changes do not alter their current row-level identity.
- B003 must not apply this row because manual coverage files are supervisor-owned collision points.

## Follow-Up Actions

- B003 ordinary callback receipt: five ordinary pages were updated, scoped-validated, reread, and reconciled; UID0001HC required read-only verification only.
- Supervisor authority: Gate 1/Gate 2A, current generated continuity, Gate 2B Section 21 actions, manual coverage application, and report lifecycle state are authoritative only from current supervisor audits, destination state, and validator-owned metadata/history.
- Section 28 supplies the exact supervisor-owned by-memory coverage row and semantic placement; current coverage identity and application state remain external authority.
- No A-agent or separate B-agent research is required for this target.

## Confidence

- Recommendation confidence: `very-strong`.
- Score confidence: `strong`.
- Exact binary range/behavior confidence: `very-strong`.
- Source-shape confidence: `strong`; two inline `100.0` expressions are more plausible than an invented named object and preserve exact behavior.
- Remaining uncertainty: original lexical spelling only; it does not affect target placement, behavior, formal covered-by closure, or score recommendation.

## Validator Results

- Callback working directory for every command: `E:\NTK\GhidraBridge\source-3\project-documentation`; validator-reported canonical root: `C:\FastStorage\NTK_Sources\source-3\project-documentation`.

| Command | Timestamp | Exact command | Result and command-specific side effects |
|---|---|---|---|
| `000000024197` | `2026-08-15T07:38:04-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`, `ok: 1`; applied completion `94`, confidence `96`, formal registry blank-to-block update, normalized two UID0004Z5 link labels, added UID000090/UID0003F7/UID0004Z5 reference-index entries, refreshed projected stats; generated refresh skipped by explicit flag. |
| `000000024198` | `2026-08-15T07:38:10-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`, `ok: 1`; added UID0000JS/UID0003F6 reference-index entries and refreshed projected stats; generated refresh skipped by explicit flag. |
| `000000024199` | `2026-08-15T07:38:16-04:00` | `python .\tools\validator.py --mode file --file by-class/NewGroupPane.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`, `ok: 1`; normalized the UID0004Z5 link label, added UID0003F6 reference-index entry, refreshed projected stats; generated refresh skipped by explicit flag. |
| `000000024200` | `2026-08-15T07:38:23-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`, `ok: 1`; normalized the UID0004Z5 link label and refreshed projected stats; generated refresh skipped by explicit flag. |
| `000000024201` | `2026-08-15T07:38:29-04:00` | `python .\tools\validator.py --mode file --file by-file/Group.md --apply --queue-timeout 240 --wait-generated` | exit `0`, `ok: 1`; normalized UID0004Z5 link label, added UID0003F6 reference-index entry, rebuilt validator registry, refreshed generated metadata/reports/tracker/automatic memory coverage, and updated validator-owned `Group.cpp`; generated refresh completed. Existing project-wide child-marker/header/no-code warnings were emitted but no target validation error occurred. |

- Dated pre-callback generated receipt remains historical: command `000000023950`, timestamp `2026-08-15T04:26:59-04:00`, `Group.cpp` SHA256 `C0678D8B5196000362FB820E3D718BD37D3D1D95E2B110C1325CEA69B0178263`, 52,287 bytes, 1,430 lines, with both source expressions and an empty UID0003F6 marker.
- Dated callback generated receipt: command/header `000000024201`, timestamp `2026-08-15T07:38:29-04:00`, refresh source `foreground-generated-refresh`; `Group.cpp` SHA256 `4C221E2164AC11F69275923B0DC04171678A9AD4623BA73C5F2AA7AE42053D56`, 52,510 bytes, 1,432 lines; `Group.h` SHA256 `2ABFC4AE921D83F78A0F63B5F42D17012EEEFEA4AE2F1CFF0385D22F11CFC5F3`, 1,851 bytes, 50 lines.
- Physical callback readback: HP `100.0` remains at `Group.cpp` lines 299-300; MP `100.0` remains at lines 346-347; UID0003F6 marker/header is at line 1413 and exact covered-by comment at line 1414. There is no UID0003F6 empty-emitter marker, target static/global object, target placeholder/TODO/stub, ownership leakage, or target H marker/declaration.
- UID0001HC was physically verified to already route UID0004Z5 and UID0000JS; no edit or validator command was needed.
- Manual coverage remains supervisor-owned and was only reread; no B003 coverage validator was run.

## Changed Files

- Reconciled report: `tools/leaser/Agents/Agent-B003/research/0003F6-GroupPaneScaleConstant-source-quality.md`.
- Changed ordinary documents:
  - `by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md`: SHA256 `7BE11493D11510401FFE3CE863AD03A1C7352AC2318DF241EDBA61EF18CF2A6F`, 7,999 bytes, 84 lines.
  - `by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md`: SHA256 `6DAB2D739B4D5F39E5E73A991391D14CA79D0BC4FD4F38935222A909547F0006`, 19,550 bytes, 267 lines.
  - `by-class/NewGroupPane.md`: SHA256 `2ED259FAD17E938302EAA214AF3806ADFEB380E57AD869061F45D3687FC9DE20`, 30,279 bytes, 218 lines.
  - `by-file/Group.md`: SHA256 `C9D131F21D48AABDA324E6EB8349061BD2E06E62CF7AB6A7EDBCCBC87E5D269B`, 57,539 bytes, 303 lines.
  - `by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md`: SHA256 `1352A7DEA0DD29EFA57D2FBF72C56ED6EE26DD426DD10D244551CE8BDFCC89D5`, 30,087 bytes, 225 lines.
- Read-only support verification: UID0001HC SHA256 `83E0814A7E5D28ED8E56E6D53D6E1630FE615C545AEF8734535D421381A50CF8`, 50,571 bytes, 308 lines.
- Validator-owned generated side effects include `Group.cpp`, generated metadata/reports, research tracker, automatic memory coverage, registry, and projected stats; B003 did not edit them directly.
- Manual `by-memory/-coverage-report.md` was not edited. Dated callback-time receipt: SHA256 `3D7CAB8A214CECF99908DB6EBB39FD7BCEE65988840299CBB00D479D50E7DD69`, 2,232,606 bytes / 4,983 lines, with UID0003F6 absent.
- Dated post-callback/rejection receipt observed `2026-08-15T08:13:17.0939628-04:00`: SHA256 `03CB54181F4D5ACA43C5EBE7528F164C4A6C41A60A66FF3AD32E398EF22FC276`, 2,233,263 bytes / 4,984 lines, with UID0003F6 absent. This is an observation, not permanent current authority; later supervisor coverage insertions may change identity and line numbers.
- Renamed/moved: none.
- IDA mutation/save: none.
- Report execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|---|---|
| [x] | C-F6-001 | 0003F6 | The target is the exact 16-byte half-open range 0x00624bd0-0x00624be0 with SHA256 3F2F2A9DC01360F3C383FA53B3F2C5B2860A2A6D38F0197C2327BE38DAF280F0. | very-strong | Live bytes and item boundaries | Target Range and IDA Evidence | incorporate | applied |
| [x] | C-F6-002 | 0003F6 | Bytes 0x00624bd0-0x00624bd8 are the unique loaded-image little-endian double 100.0. | very-strong | Bytes 00 00 00 00 00 00 59 40 and unique byte search | Target Summary and Behavior | incorporate | applied |
| [x] | C-F6-003 | 0003F6 | Bytes 0x00624bd8-0x00624be0 are eight zero alignment bytes, not a source-level 0.0 object. | very-strong | Separate unnamed item, zero xrefs, 16-byte-aligned successor | Target Range and Negative Evidence | incorporate | applied |
| [x] | C-F6-004 | 0003F6 | The exact 100.0 byte pattern occurs once in the loaded binary. | very-strong | Live find-bytes result | Target IDA Evidence | incorporate | applied |
| [x] | C-F6-005 | 0003F6 | qword_624BD0 has exactly two data xrefs at 0x0056d5b8 and 0x0056d876, both in NewGroupPane__OnPaint. | very-strong | Live xrefs_to | Target Xrefs | incorporate | applied |
| [x] | C-F6-006 | 0003F6 | The first use computes currentHitPoints divided by maximumHitPoints times 100.0 before unsigned conversion and percent formatting. | very-strong | Live disassembly and decompilation | Target Behavior and UID0004Z5 | incorporate | applied |
| [x] | C-F6-007 | 0003F6 | The second use computes currentManaPoints divided by maximumManaPoints times 100.0 before unsigned conversion and percent formatting. | very-strong | Live disassembly and decompilation | Target Behavior and UID0004Z5 | incorporate | applied |
| [x] | C-F6-008 | 0004Z5 | The sole consumer function is NewGroupPane__OnPaint at 0x0056ce50-0x0056da03 with exact current type void __thiscall(NewGroupPane *this). | very-strong | Live function/decompile/item evidence | UID0004Z5 IDA and dependency sections | incorporate | applied |
| [x] | C-F6-009 | 0003F6 | The predecessor remains outside the target and the successor begins exactly at 0x00624be0 as xmmword_624BE0 for SelfLookPane_OnPaint. | very-strong | Item boundaries and xrefs | Target Boundaries | incorporate | applied |
| [x] | C-F6-010 | 0003F6 | Original source shape is two inline 100.0 expressions; no standalone C++ data object is emitted. | strong | Exact uses plus compiler-pooling inference | Target Source Placement | incorporate | applied |
| [x] | C-F6-011 | 0003F6 | Canonical owner and emitter remain Group file UID0000JS. | strong | Current routing and file-local pooled-data convention | Target metadata | already-present | already-present |
| [x] | C-F6-012 | 000090 | NewGroupPane UID000090 and method UID0004Z5 are semantic consumers, not replacement canonical owners for the pooled range. | strong | Sole function consumer and project routing | Class dependency notes | incorporate | applied |
| [x] | C-F6-013 | 0003F6 | RECONSTRUCTABLE remains TRUE because both source uses are exact and already represented. | very-strong | Complete formal method source and binary behavior | Target metadata | already-present | already-present |
| [x] | C-F6-014 | 0003F6 | Formal CPP contains only the exact covered-by marker for NewGroupPane::OnPaint HP and MP percentage expressions. | strong | No standalone source object; exact use-site source | Target formal CPP | incorporate | applied |
| [x] | C-F6-015 | 0003F6 | Formal H remains exactly blank because no declaration is required. | very-strong | Compiler-pooled literal/alignment disposition | Target formal H | already-present | already-present |
| [x] | C-F6-016 | 0003F6 | Target score is completion 94 and confidence 96 with owner/emitter/reconstructable/position otherwise unchanged. | strong | All blockers resolved and source closure exact | Target metadata | incorporate | applied |
| [x] | C-F6-017 | 0003F6 | Target prose incorporates full bytes, xrefs, behavior, range split, ownership, source placement, rejected alternatives, and no-code proof. | very-strong | Report evidence | Target all relevant sections | incorporate | applied |
| [x] | C-F6-018 | 0004Z5 | OnPaint support links both literal reads and physical UID0003F6 pool while preserving its complete formal source and metadata. | very-strong | Exact xrefs and current complete source | UID0004Z5 support detail | incorporate | applied |
| [x] | C-F6-019 | 000090 | NewGroupPane class support records the percentage-pool dependency without changing class ownership, emitter route, scores, or formal H. | strong | Sole class consumer | UID000090 dependency detail | incorporate | applied |
| [x] | C-F6-020 | 0000JS | Group file support contains percentage-scale closure and preserves existing file metadata and source order. | strong | File ownership and generated source | UID0000JS data/source closure | incorporate | applied |
| [x] | C-F6-021 | 0002V2 | Mixed parent describes the child as NewGroupPane 100.0 plus alignment rather than a generic GroupPane scale constant. | very-strong | Exact split and consumer | UID0002V2 child inventory | incorporate | applied |
| [x] | C-F6-022 | 0001HC | Broad GroupPanes aggregate already links UID0004Z5 and UID0000JS; UID0004Z5 now supplies UID0003F6 linkage, so no aggregate metadata, formal, or emitter edit is required. | strong | Existing child routing and applied UID0004Z5 dependency | UID0001HC cross-reference | already-present | already-present |
| [x] | C-F6-023 | 0003F6 | Validator output preserves the two existing 100.0 expressions and replaces the empty UID0003F6 marker with the formal covered-by marker. | strong | Dated generated callback readback | Generated Group.cpp readback | incorporate | applied |
| [ ] | C-F6-024 | 0003F6 | Manual by-memory coverage closure is supervisor-owned and uses the exact Section 28 row after UID0003F5 and before the next top-level row. | very-strong | Dated read-only coverage receipts and exact placement text | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C-F6-025 | 0003F6 | IDA literal item should be collision-checked and renamed NewGroupPane_PercentScale. | strong | Sole semantic use and zero candidate collisions | Supervisor Gate 2B IDA-F6-01 | incorporate | proposed |
| [ ] | C-F6-026 | 0003F6 | IDA literal item should receive exact type double after rename readback. | very-strong | Exact eight-byte IEEE-754 use | Supervisor Gate 2B IDA-F6-02 | incorporate | proposed |
| [ ] | C-F6-027 | 0003F6 | IDA literal item should receive the exact repeatable semantic comment in IDA-F6-03. | strong | Two exact percentage uses | Supervisor Gate 2B IDA-F6-03 | incorporate | proposed |
| [ ] | C-F6-028 | 0003F6 | The alignment tail should receive the exact repeatable alignment comment in IDA-F6-04 and remain unnamed/untyped. | very-strong | Zero xrefs and successor alignment | Supervisor Gate 2B IDA-F6-04 | incorporate | proposed |
| [ ] | C-F6-029 | 0004Z5 | NewGroupPane__OnPaint name, type, comments, function range, bytes, and xrefs must remain protected unchanged. | very-strong | Fresh current function prestate | Supervisor Gate 2B IDA-F6-05 | already-present | proposed |
| [ ] | C-F6-030 | 0003F7 | xmmword_624BE0 and its SelfLookPane xref remain protected and outside UID0003F6. | very-strong | Fresh item/xref boundary evidence | Supervisor Gate 2B IDA-F6-06 | already-present | proposed |
| [x] | C-F6-031 | 0003F6 | Every changed ordinary by-star page received scoped apply validation and fresh Group.cpp/Group.h physical readback under commands 24197-24201. | very-strong | Callback validator receipts and generated hashes | Validator Results | incorporate | applied |
| [x] | C-F6-032 | 0003F6 | All in-scope naming, type, owner, emitter, range, padding, liveness, source, code, header, score, generated, and coverage questions are resolved without deferral. | strong | Exhaustive evidence and ranked analysis | Open Questions | already-present | already-present |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000024245","destination_path":"executed-b-agent-research/B003/0003F6-GroupPaneScaleConstant-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003F6-GroupPaneScaleConstant-source-quality.md","timestamp":"2026-08-15T08:37:54-04:00","uid":"0003F6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
