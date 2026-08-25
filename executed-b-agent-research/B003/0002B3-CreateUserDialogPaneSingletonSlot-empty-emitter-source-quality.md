** TARGET-REPORT-UID:0002B3 **
** TARGET-REPORT-ADDITIONAL-UIDS:0002SI **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002B3 CreateUserDialogPane Singleton Slot Empty-Emitter Source-Quality Report


## Finalized Report / Current Recommendation

- [UID:0002B3] `by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md` is now `92/94`, owned by semantic [UID:0004Y3] `by-global/g_pCreateUserDialogPane.md`, false/non-emitting, with blank position/CPP/H and no generated target marker. The historical assignment baseline was `86/91`, owner/emitter UID0000IJ, reconstructable true.
- [UID:0002SI] `by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md` is now `92/94`, owned by [UID:00003B] `CreateUserDialogPane`, false/non-emitting, with blank position/CPP/H and no generated target marker. The historical assignment baseline was `88/91`, owner/emitter UID00003B, reconstructable true.
- Semantic [UID:0004Y3] is the sole externally linked, explicitly zero-initialized definition in `NexusTK/login/CreateUserDialogPane.cpp`, emitted at position `0`:

```cpp
class CreateUserDialogPane;

CreateUserDialogPane *g_pCreateUserDialogPane = 0;
```

- The class declaration is implemented in UID00003B H at position `10`, with RTTI-proven direct `Singleton<CreateUserDialogPane>` inheritance after `DialogPane`, exactly one matching `extern CreateUserDialogPane *g_pCreateUserDialogPane;`, and `[[CHILDREN]]`; UID00003B CPP is blank.
- The constructor now expresses `Singleton<CreateUserDialogPane>()` as a direct base initializer and does not handwrite `g_pCreateUserDialogPane = this;`. It zero-initializes only `m_waitingForCharacterReply` before later initialization logic; unobserved early zeroes for `m_initialAppearanceRoll`, `m_bodyShapeIndex`, and `m_isFemale` were removed.
- The stale `0xffffffff` claim is rejected. Live IDA reads `00 00 00 00`; PE `.data` raw backing ends at VA `0x0067a800`, while the virtual extent continues through `0x0069ce24`. The target starts `0x21090` bytes beyond raw backing and is loader-zero-filled. There are no physical file bytes at this VA and no integer-sentinel startup state.
- Direct RTTI resolves the source cause: `CreateUserDialogPane` has direct bases `DialogPane` and `Singleton<CreateUserDialogPane>`. The Singleton base PMD is `{0x26c,-1,0}`, attributes `0x40`; old-MSVC empty-base optimization permits the empty base and the first derived field at `+0x26c` to share the offset without changing the exact `0x280` complete-object size.
- Final pre-execution state is `APPLIED_VERIFIED`: ordinary implementation and Gate2A passed, command 18148 regenerated the accepted CPP/H topology, and supervisor Gate2B applied/read back I01-I13 and saved/cataloged the IDB. Only fresh final Gate 1, execution/archive, post-execution manual coverage/validation, and post-archive audit remain.
- No report-level blocker remains. Residual exact lexical uncertainty about the original null token or external-global spelling is resolved by the highest-probability project/family convention (`g_pCreateUserDialogPane`, external, `= 0`) and reflected below the 95 barrier rather than left as an open task.

## Supporting Research

### Current project evidence read

- Primary target [UID:0002B3] and required additional target [UID:0002SI].
- Direct class/file owners [UID:00003B] `by-class/CreateUserDialogPane.md` and [UID:0000IJ] `by-file/CreateUserDialogPane.md`.
- Exact constructor [UID:00046E], raw constructor-cleanup [UID:00046F], split/index [UID:0002QT], and compiler lifecycle island [UID:0002QU].
- Exact source virtual children [UID:00046Q] `OnDialogAction`, [UID:00046R] `OnKeyEvent`, [UID:00046S] `OnCreateUserReplyEvent`, and [UID:00046T] `OnDialogShow`.
- Mixed read-only-data index [UID:00025Z], sibling vtable target [UID:0002SJ], sibling singleton storage/global pages, and current semantic-global precedents including `g_pBackStoryDialogPane` and `g_pSoundManager`.
- Assignment-time generated `auto-generated/NexusTK/login/CreateUserDialogPane.cpp`, research tracker, and all four supervisor-owned coverage reports were read-only; dated checkpoints 18080, 18087, and 18113 plus final pre-execution refresh 18148 are recorded separately below.
- Current skill/template and B-agent inference/source-quality rules. Historical Wave2/Wave3 language was ignored as instructed and was not used as current authority.

### Prior-report reconciliation

| Report | Classification | Valid detail retained or correction made |
| --- | --- | --- |
| `executed-b-agent-research/B004/00003B-CreateUserDialogPane-class-source-quality.md` | direct class report | Retained exact class purpose, field/control map, constructor callers, packet/reply behavior, vtable/singleton ownership, source file, and scalar-wrapper exclusion. Corrected the missing direct Singleton base, stale physical initializer, CPP-vs-H declaration route, and explicit singleton publication in draft source. |
| `executed-b-agent-research/B008/0002QT-CreateUserDialogPaneCore-source-quality.md` | direct method/source split | Retained all exact child ranges, two constructor callers, raw cleanup body, singleton refs, class/file route, and no-code compiler split. Reclassified the raw `0x0052e6f0` clear as implicit reverse Singleton cleanup, not a reason to handwrite a global clear. |
| `executed-b-agent-research/B010/0001CR-CreateUserDialogVariants-source-quality.md` | family split/index | Retained old/new variant separation and non-emitting aggregate policy. Rejected the old `0xffffffff` target summary using current IDA and PE evidence. |
| `executed-b-agent-research/B001/0002SJ-NewCreateUserDialogPaneVtableData-source-quality.md` | exact sibling precedent | Applied the accepted source/compiler split: decorated vtable data becomes false/non-emitting; class declaration plus virtual children regenerate it; no raw function-address arrays or empty marker. |
| `executed-b-agent-research/B002/00046T-CreateUserDialogPaneOnDialogShow-source-quality.md` | direct secondary-vtable child | Retained exact 9-byte bridge, slot `0x0061fea0`, no code caller, source signature, boundary, and inherited delegation. |
| `executed-b-agent-research/B015/00046S-CreateUserDialogPaneOnCreateUserReplyEvent-source-quality.md` | direct secondary-vtable child | Retained packet-event payload/marker behavior, slot `0x0061feac`, source signature, and vtable-only route. |
| Current semantic-global reports for `g_pBackStoryDialogPane`, `g_pSoundManager`, and other direct Singleton classes | current one-definition precedent | Applied the semantic-global definition plus false physical backing, H-channel `extern`, direct Singleton base, no explicit publication/clear, and no duplicate source/marker policy. |

No newer report supersedes this target-specific conclusion. UID0002B3 and UID0002SI both had zero direct report rows in the current research tracker before this report.

## Target

- Primary target UID: `0002B3`.
- Primary path: `by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md`.
- Required additional target UID: `0002SI`.
- Additional path: `by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md`.
- Assigned source root: [UID:0000IJ] `CreateUserDialogPane`, `NexusTK/login/CreateUserDialogPane.cpp`.
- Direct semantic class: [UID:00003B] `CreateUserDialogPane`.
- Historical assignment-time target state: UID0002B3 `86/91`, owner/emitter UID0000IJ, reconstructable true, blank CPP/H, empty generated marker.
- Historical assignment-time required-support state: UID0002SI `88/91`, owner/emitter UID00003B, reconstructable true, blank CPP/H, empty generated marker.
- Historical callback authorization: Gate 1 passed exact report SHA256 `6AAFAE4574E2512AAE1D233C20AD5467DD3073DC70AB90CA7DA0972F57DB085D`; ordinary implementation and serial scoped validation then completed. Exact post-callback report SHA256 `66791ECDF6BAFC42F044F35402DC9300EDA060941C74CE77C16A7E27F9B0C4CE` failed a renewed narrow Gate 1 because it treated dated command 18080 as current after command 18087 refreshed the physical generated files. Exact repaired report SHA256 `93D53C2F6078FD32BD1BB4044B04F711E6EA85FC9F791E6F28656825C3B09798` then failed only because it treated dated command 18087 as indefinitely current after supervisor checkpoint 18113. Supervisor Gate2A has now passed, foreground generated refresh 18148 has completed, and Gate2B I01-I13 have been applied, read back, saved, and cataloged. This final same-report reconciliation now awaits only a fresh exact-artifact supervisor Gate 1 before execution/archive; post-execution manual coverage/coverage validation and post-archive audit remain supervisor-owned. B003 did not mutate IDA or run a lifecycle command.

## Current Target State

- Ordinary UID0002B3 is now `92/94`, owner UID0004Y3, false/non-emitting, blank emitter/position/CPP/H, with exact loader-zero PE proof, the five-reference lifecycle, direct Singleton source cause, boundary proof, IDA prestate, generated disposition, and superseded all-ones history.
- Ordinary UID0002SI is now `92/94`, owner UID00003B, false/non-emitting, blank emitter/position/CPP/H, with all 36 function slots, three in-range COL words, three-by-three lifecycle stores, predecessor/successor boundaries, source-cause links, and no-code proof.
- Gate2B is `APPLIED_VERIFIED` in live session `5a570ede`: I01-I13 were applied and read back as recommended. UID0002B3 is one four-byte `CreateUserDialogPane *` item named `g_pCreateUserDialogPane`; all accepted function names/types/comments and vtable comments persist. I07 was explicitly restored after temporary rename-side type propagation to exact declaration `char __thiscall(int this, _BYTE *)`. The existing `CreateUserDialogPane` UDT was preserved without duplication or layout mutation.
- The exact physical window still reads four zero bytes. Active target prose reflects loader-zero initialization; old `ff ff ff ff` / `0xffffffff` text survives only as explicitly superseded history. Supervisor-owned manual coverage and its coverage validation remain pending until after report execution.
- Exactly five references reach `0x0069b890`: constructor publication/fallback at `0x0052dd87` and `0x0052dd8e`, raw constructor-unwind cleanup at `0x0052e71a`, Singleton clear helper at `0x0052f710`, and scalar deleting destructor clear at `0x0052f82d`.
- UID0002SI has three decorated vtable address points at `0x0061fe3c`, `0x0061fe9c`, and `0x0061fecc`. Each has exactly three lifecycle installation references from constructor, raw unwind cleanup, and scalar deleting destructor.
- UID0002SI physically contains 36 function slots, two internal `CreateUserDialogPane` Complete Object Locator pointers, and the following object's COL at `0x0061fed4`. The primary COL at `0x0061fe38` lies immediately before the target. This is contiguous MSVC layout, not a handwritten array.
- Historical generated command `000000018006` placed the class declaration in CPP, contained explicit `g_pCreateUserDialogPane = this;`, lacked the global definition and H file, and emitted UID0002SI/UID0002B3 empty markers. Dated commands 18080, 18087, and 18113 progressively refreshed the corrected output. Final pre-execution foreground refresh command `000000018148` completed after Gate2A: CPP SHA256 `D44A4F6723783F59AF0813C9E779C551A753BB6F134E9F415D4AAFEF3BFF927A`, 14,949 bytes, 475 lines; H SHA256 `AE502FE13F5671A6BFEB272080000C47EC1ECA4AA37FB45F61E5D355DE90BFAF`, 1,617 bytes, 45 lines. Accepted body topology is unchanged from command 18113: one UID0004Y3 definition precedes UID00046E; UID00003B supplies the H declaration/extern; UID0002B3 and UID0002SI have no markers; the sole CPP empty marker is intentional UID00003B support because the class source is H-only. Only validator refresh metadata changed.

## Executive Recommendation

1. Completed: created semantic UID0004Y3 first through scoped validator UID allocation; it owns the sole external definition at file position `0`.
2. Completed: reparented UID0002B3 to UID0004Y3 and made the physical storage false/non-emitting with blank formal channels.
3. Completed: made UID0002SI false/non-emitting under class UID00003B while retaining full vtable/COL evidence and blank formal channels.
4. Completed: moved the complete class declaration to UID00003B H, added direct `Singleton<CreateUserDialogPane>` inheritance and one matching extern, left class CPP blank, and set position `10`.
5. Completed: corrected UID00046E to initialize the direct Singleton base and removed explicit publication plus unobserved early field-zero stores.
6. Completed: synchronized raw constructor-unwind, clear-helper, adjustor-thunk, scalar-wrapper, vptr, and vtable/COL pages as compiler/template manifestations without hand-authoring them.
7. Completed: preserved existing method/packet/control behavior, verified UID00046Q/R/S/T read-only, and changed no conditional method page because no concrete stale contradiction was found.

## Supervisor Active Recheck

- Historical Gate 1 passed on exact SHA256 `6AAFAE4574E2512AAE1D233C20AD5467DD3073DC70AB90CA7DA0972F57DB085D` before ordinary edits. The final reconciled artifact requires a fresh exact-artifact Gate 1 before execution/archive.
- `APPLIED_VERIFIED`: the callback created semantic UID0004Y3 first, replaced every provisional global UID reference, and supervisor Gate2A verified every ordinary claim. Scoped confirmation commands 18124-18147 all exited `0` with `ok:1`; duplicate confirmations caused by draining the original serial loop were harmless.
- `APPLIED_VERIFIED`: supervisor Gate2B applied/read back I01-I13 in session `5a570ede`, preserved the existing UDT, saved IDB SHA256 `9B1382E39799069EE002B70919732CE6EBE4E8800B1CA43BF4B4989B7B92C3CB`, and recorded catalog entry 0331.
- B003 must not run `execute_report`, archive/move this report, edit coverage/generated/audit/catalog state, or mutate IDA.

## Inference Research Guidance Check

- Binary facts and source inference are separated. Exact bytes, PE sections, addresses, xrefs, RTTI descriptors, PMDs, item states, types, comments, slot values, function bounds, and generated artifacts are factual evidence. Linkage spelling, null-token style, and human variable names are source inference.
- Raw/decompiler names are not treated as source. `unk_69B890`, `dword_69B890`, `sub_52DD30`, and `sub_52F800` remain historical/search aliases only.
- A missing exact source symbol is not used to preserve an IDA-looking name. The best project-consistent human name is selected from type, lifecycle, source family, sibling conventions, and direct RTTI.
- Runtime equivalence has priority: loader-zero initialization, compiler-lowered Singleton publication/clear, vtable generation, member initialization timing, and one-definition behavior must match. Human C++ must also look like plausible mid-2000s source rather than decompiler output.
- Consistency is subordinate to runtime equivalence and human source shape but supports `g_pCreateUserDialogPane`, `= 0`, direct Singleton inheritance, and H/CPP separation.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and resolution | Status / score impact |
| --- | --- | --- |
| `0xffffffff` startup state | Live IDA reads zero; target is outside `.data` raw extent and therefore loader-zero-filled. Old all-ones text is stale, not an alternate runtime state. | Resolved; remove active all-ones claims and preserve them only as corrected history. |
| Pointer type | Constructor stores the complete CreateUserDialogPane pointer; scalar cleanup and RTTI/vtables agree; IDA already has exact `CreateUserDialogPane` UDT size `0x280`. | Resolved as `CreateUserDialogPane *`. |
| Variable spelling | Existing class/file/core docs use `g_pCreateUserDialogPane`; sibling globals use `g_p<Class>`; no competing IDA symbol or semantic owner exists. | Resolved as `g_pCreateUserDialogPane`; raw aliases rejected. |
| Linkage | All five surviving refs are in the same source family, so binary refs alone do not prove linkage. Project-wide direct-Singleton definitions and sibling create-user globals are external semantic globals with header declarations. | High-probability resolution: external definition plus one H `extern`; file-static/anonymous/template-static alternatives rejected. Confidence remains below 95. |
| Null initializer token | Loader behavior cannot distinguish implicit zero, `0`, or `NULL`. Current project C++03 singleton definitions consistently use explicit `= 0`. | Resolved as `= 0`; lexical uncertainty is a confidence cap, not a blocker. |
| Direct inheritance | RTTI class hierarchy has eight entries and attributes `1`; `CreateUserDialogPane` BCD is followed by DialogPane ancestry and direct `Singleton<CreateUserDialogPane>` BCD at PMD `+0x26c`. | Resolved as `public DialogPane, public Singleton<CreateUserDialogPane>`. |
| `+0x26c` field collision | The Singleton direct base is empty and has PMD `+0x26c`; derived field `m_initialAppearanceRoll` also occupies `+0x26c`. | Resolved as old-MSVC EBO overlap; keep the field and direct base, no authored padding. |
| Explicit constructor publication | The `lea this+0x26c; add -0x26c; store global` sequence is the inlined Singleton constructor, not an authored body statement. | Remove `g_pCreateUserDialogPane = this;`; initialize Singleton base. |
| Explicit clear/helper source | Raw unwind and scalar wrapper clear the same global during reverse base teardown; `0x0052f710` is EH-only Singleton cleanup. | Compiler/template support; no handwritten clear helper or destructor assignment. |
| Vtable C++ | Three address points, COLs, thunks, inherited slots, and deleting destructor are normal MSVC output. | UID0002SI becomes false/non-emitting; class H and method children regenerate it. |
| Vtable range | The target begins at the primary address point, includes internal COLs at `0x61fe98`/`0x61fec8`, and includes the successor COL at `0x61fed4`; successor address point is exactly `0x61fed8`. | Preserve exact half-open range; document boundary ownership, do not extend or hand-split ABI records. |
| Early field initializers | Binary initializes `m_waitingForCharacterReply` early but writes appearance/body/female state later. Current draft zeroes all four before those writes. | Correct constructor initializer list to avoid unobserved stores and preserve exact legacy behavior, including the preassignment body-shape read. |
| Class declaration channel | Current class is embedded in CPP and no H exists; project rule requires draft declarations in H. | Move declaration/extern/`[[CHILDREN]]` to H; CPP blank. |

## Evidence Standards Used

- Exact half-open address ranges and item boundaries.
- Live IDA MCP read-only evidence from session `5a570ede`, with status `ok`, Hex-Rays ready, module `NexusTK.exe`, imagebase `0x400000`, and active worker PID `15448`.
- Exact PE section parsing from input SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Exact xref counts and instruction addresses, not representative-only counts.
- RTTI Complete Object Locator, Class Hierarchy Descriptor, Base Class Array, BCD, PMD, and decorated-name evidence.
- Current documentation union plus executed-report history, with stale assumptions retained as explicitly superseded history.
- Assignment-time generated output and supervisor-owned manual reports were read-only research inputs; no generated/manual file was treated as authoritative when it contradicted live evidence. Dated commands 18080, 18087, and 18113 preserve intermediate generated checkpoints. Gate2A and final foreground refresh command 18148 establish the final pre-execution generated identity and unchanged semantic topology below.
- Source-era C++03 style, exact runtime behavior, and no raw ABI/vtable/global duplication.

## Evidence Checked

### Live IDA MCP

- `server_health`: `status:ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready. `auto_analysis_ready:false` is the known saved-analysis state and did not impair bounded live reads.
- Current IDB SHA256 at evidence time: `2F63E3F97C411E2E67C0BC173F58C001EB8CDCEDB42291CD958A0440D8FEFCFF`, 143,188,952 bytes, last write `2026-07-26T06:05:10.0702744-04:00`.
- `survey_binary`: `.data` loaded range `[0x0066d000,0x0069d000)`; precise PE parsing narrows the section virtual end to `0x0069ce24`.
- `get_bytes/get_int/get_global_value`: target and neighbors are zero; vtable bases resolve to `0x0052f800`, `0x0052f73b`, and `0x0052f746`.
- `inspect_items/get_comments`: target is undefined and unnamed; three vtable bases are named 4-byte data with blank types/comments; all actionable function comment channels were read.
- `xref_query/xrefs_to`: exact target, neighbor, vtable-base, constructor, virtual-slot, clear-helper, thunk, and scalar-wrapper reference sets.
- `decompile/disasm`: constructor publication/base sequence, singleton clear, scalar deleting destructor, and raw cleanup bytes.
- `find_bytes`: exact absolute VA pattern `90 b8 69 00` occurs only at `0x0052dd88`, `0x0052dd90`, `0x0052e71c`, `0x0052f712`, and `0x0052f82f`; RVA pattern `90 b8 29 00` has zero matches.
- `type_query/type_inspect`: `CreateUserDialogPane` exists at exact size `0x280`; `DialogPane` exists at size `0x26c`; `KeyEvent`, `PacketEvent`, and a local `Singleton<CreateUserDialogPane>` UDT do not exist.
- `entity_query`: no `g_pCreateUserDialogPane` collision and no collision for the proposed CreateUserDialogPane function names; decorated RTTI/vtable names remain canonical and protected.

### PE section proof

- PE32 imagebase: `0x00400000`.
- `.data`: RVA `0x0026d000`, VA `0x0066d000`, virtual size `0x2fe24`, virtual end `0x0069ce24`, raw pointer `0x26ac00`, raw size `0xd800`, raw-backed VA end `0x0067a800`, characteristics `0xc0000040`.
- UID0002B3 offset within `.data`: `0x2e890`; distance beyond raw-backed VA end: `0x21090`.
- The loader supplies zero for this virtual tail. The raw executable contains no target bytes to support an all-ones initializer.

### Assignment-time artifact snapshots (historical)

| Path | SHA256 | Bytes / lines | Relevant current state |
| --- | --- | ---: | --- |
| UID0002B3 target | `18D21E300023297B6DA4B7B9EF74F2BDF0E07A45AAACB209154574C67EEE9C56` | 8,979 / 96 | stale all-ones text, true empty emitter |
| UID0002SI target | `488AEE42B4D56811B28448756FA58F843A52DFEE4AE7E19F383D9697A0D0ABE1` | 10,714 / 89 | true empty emitter |
| UID00003B class | `CDC88CB93F60FD66796A1064AC17998C51073D9EC04CBEB1E66620BDFB59A0CC` | 37,873 / 251 | CPP class, missing Singleton base |
| UID0000IJ file | `5BDE5E1CF9EFC7C1E20C8906004C2A74E9466D233E31F0E8D048DA26E5E52D92` | 27,739 / 155 | two empty emitters |
| UID00046E constructor | `D5FBC182309F0223E27FBAD602CF98DC1CE9E06596DB54E6C29BBA2713BFD31B` | 4,686 / 109 | explicit global store and extra early zero initializers |
| generated CPP | `E9B1C94909DBCB68EB8C824CFD7440BB9B9A223C8456CEFB6FF8BE971F97C37C` | 16,163 / 509 | command 18006; no global definition; two empty markers |

### Current artifact snapshots

| Path | SHA256 | Bytes / lines | Exact callback-current state |
| --- | --- | ---: | --- |
| [UID:0004Y3] `by-global/g_pCreateUserDialogPane.md` | `684611312080DC431F4E6FD5D3237B17CCB7AE21BBEC2D72D03A7889DD109201` | 13,113 / 126 | `92/93`, UID0000IJ owner/emitter, position 0, sole CPP definition, blank H. |
| UID0002B3 target | `77A870803357084FC6F1CB2164EC29B3B6B079884DBFB6622E51468FC4430F16` | 12,026 / 108 | `92/94`, owner UID0004Y3, false/non-emitting, blank position/CPP/H. |
| UID0002SI target | `FF69E81E90EAF55C09187A70F55E5E0786EA1C0777C5440380BF1DE76DC37CAA` | 16,930 / 156 | `92/94`, owner UID00003B, false/non-emitting, blank position/CPP/H. |
| UID00003B class | `F91E8CEA1DADEC4E3902BD79EEB0FA4F58070B94B3A5DF0877FA5B06A5541353` | 40,568 / 270 | `92/93`, position 10, blank CPP, accepted H declaration. |
| UID0000IJ file | `AE7F70D9803D2315F48F286C5BCA16569CFBC9EB96271B5019E6C5DABD11EF1B` | 31,656 / 175 | `92/93`, exact position 0/10/20 source union and generated criteria. |
| UID00046E constructor | `A631BF67D4A0A0E86A6B9AF55CE73BF8EA1F0A847BFD7907C6DAACCFDF8010C5` | 7,935 / 132 | `92/93`, position 20, direct Singleton initializer, only early wait-state zero. |
| UID00046F cleanup support | `3D3E37775D0DA581E98B212F41B3D7FA763CC367EF43E26655FD4578EEB243FF` | 4,668 / 46 | score/route unchanged; exact reverse-Singleton cleanup and five-ref route synchronized. |
| UID0002QT core support | `ADF03A3D8F7ADE4DBFA055535CB5E0D54C870FA363EAE257CDE3030D68903291` | 18,771 / 108 | score/route unchanged; semantic/physical/compiler split and constructor correction synchronized. |
| UID0002QU lifecycle support | `71A3BD2510FF575B65DEB1E0284805A6486E7DA43E8E6C020247881804E0480B` | 18,023 / 140 | score/route unchanged; exact current raw IDA prestates and generated source causes synchronized. |
| UID00025Z mixed rdata support | `3F0279DD3A5C2EC348CECA4E8BC71497E86000648178179997EC63DA28E812A4` | 30,131 / 162 | score/route unchanged; exact UID0002SI COL/address-point boundaries synchronized. |
| generated CPP historical callback checkpoint | `07579B74A185364D29197ADA9BA43816D443E26F23343F5B94B09F438A3B4838` | 14,951 / 475 | command 18080; historical first post-callback readback with one UID0004Y3 definition, corrected constructor, and no UID0002B3/UID0002SI marker. |
| generated H historical callback checkpoint | `BD82D17B5E0D275F2EDA2D77D0F30F4DAA2A61795D0CB2FEA95571B48DC65F45` | 1,619 / 45 | command 18080; historical first post-callback UID00003B extern/direct-Singleton class declaration. |
| generated CPP dated supervisor checkpoint | `5F44A0B4729F0950502B20793E4AF6E9C0A142C990435EA195162F3EAF4D149F` | 14,951 / 475 | command 18087, refreshed `2026-07-26T07:21:12-04:00`; dated readback with one exact `CreateUserDialogPane *g_pCreateUserDialogPane = 0;` definition under UID0004Y3 before UID00046E, no UID0002B3/UID0002SI marker, and the intentional UID00003B CPP empty marker for the H-only class. |
| generated H dated supervisor checkpoint | `ABD4E532131BCC84A5D1E32269828F36410F4AA199E91551319E0C71080E78AC` | 1,619 / 45 | command 18087, refreshed `2026-07-26T07:21:12-04:00`; dated readback with one UID00003B class/extern source and no UID0002B3/UID0002SI marker. |
| generated CPP dated supplied supervisor checkpoint | `AD2C2E3C2C70CDA4D82B2D1CEAF81AFA8073394EAF36A3484C74FB829DB26836` | 14,951 / 475 | command 18113, timestamp `2026-07-26T07:42:27-04:00`; one exact UID0004Y3 definition before UID00046E, no UID0002B3/UID0002SI marker, and one intentional UID00003B CPP empty marker because the class source is H-only. |
| generated H dated supplied supervisor checkpoint | `8197D6EF2C1007C2FE3FDF99A82A7698519023EA97308B89A1D658DAAB98E70F` | 1,619 / 45 | command 18113, timestamp `2026-07-26T07:42:27-04:00`; one UID00003B class/extern source and no UID0002B3/UID0002SI marker. |
| generated CPP final pre-execution refresh | `D44A4F6723783F59AF0813C9E779C551A753BB6F134E9F415D4AAFEF3BFF927A` | 14,949 / 475 | foreground command 18148 completed after Gate2A; accepted body topology unchanged from 18113 and only refresh metadata changed. |
| generated H final pre-execution refresh | `AE502FE13F5671A6BFEB272080000C47EC1ECA4AA37FB45F61E5D355DE90BFAF` | 1,617 / 45 | foreground command 18148 completed after Gate2A; accepted H class/extern topology unchanged from 18113 and only refresh metadata changed. |

## Claim And Incorporation Ledger

| Claim | Atomic accepted fact or change | Confidence | Evidence | Destination | Verification state |
| --- | --- | --- | --- | --- | --- |
| C01 | UID0002B3 range remains exactly `[0x0069b890,0x0069b894)`, four bytes. | exact | target, PE, IDA bytes/xrefs, neighbor xrefs | UID0002B3 Range | APPLIED_VERIFIED; Gate2A and I01 readback passed |
| C02 | Current loaded value is zero; active `0xffffffff` claims are false. | exact | get_bytes/get_int, PE virtual tail | UID0002B3 Summary/Evidence/History | APPLIED_VERIFIED; stale claim historicalized and I01 bytes remain zero |
| C03 | Assignment-time target had no persistent name/type/item; `unk_69B890` was synthesized. | exact | inspect_items, entity_query, decompile | UID0002B3 IDA Status | APPLIED_VERIFIED; historical prestate preserved and I01 now reads back exact item/name/type/comment |
| C04 | Exact semantic type/name are `CreateUserDialogPane *g_pCreateUserDialogPane`. | very strong | ctor/scalar refs, UDT, RTTI, project convention | UID0004Y3 + target | APPLIED_VERIFIED; UID0004Y3 issued and I01 persisted |
| C05 | Best source linkage is external and best initializer is `= 0`. | strong | family/global precedents and source style | UID0004Y3 | APPLIED_VERIFIED; Gate2A and command 18148 confirm exact definition |
| C06 | Semantic global UID0004Y3 owns the sole CPP definition at position 0. | very strong | one-definition policy, generated omission | UID0004Y3 | APPLIED_VERIFIED; Gate2A and command 18148 confirm one definition before UID00046E |
| C07 | Physical UID0002B3 becomes false/non-emitting and owns no duplicate formal code. | exact source topology | semantic/physical precedent | UID0002B3 metadata/formal | APPLIED_VERIFIED; Gate2A and command 18148 confirm no target marker |
| C08 | Target has exactly five lifecycle refs at the five listed instruction addresses. | exact | xref_query/find_bytes/decompile | UID0002B3 Xrefs | APPLIED_VERIFIED across target/global/support docs and Gate2A |
| C09 | Constructor writes are direct Singleton base lowering, not handwritten publication. | very strong | RTTI PMD +0x26c and disassembly | UID00046E/class/target | APPLIED_VERIFIED by ordinary validators, Gate2A, and command 18148 |
| C10 | Raw cleanup/helper/scalar clears are reverse Singleton/EH/compiler lowering. | very strong | raw bytes, xrefs, scalar decompile | UID00046F/UID0002QU/target | APPLIED_VERIFIED by ordinary validators and Gate2A |
| C11 | Class direct bases are DialogPane then Singleton<CreateUserDialogPane>. | exact RTTI | CHD/BCA/BCD/PMD | UID00003B H/prose | APPLIED_VERIFIED by Gate2A and command 18148 H |
| C12 | Empty-base PMD +0x26c may overlap m_initialAppearanceRoll +0x26c without padding. | exact layout/source inference | RTTI and UDT | UID00003B layout | APPLIED_VERIFIED without synthetic padding; UDT preserved in Gate2B |
| C13 | Class H carries one extern; class CPP is blank; class position is 10. | source-quality | header rule/current precedent | UID00003B formal/metadata | APPLIED_VERIFIED; Gate2A and command 18148 confirm H source and intentional H-only CPP marker |
| C14 | Constructor adds Singleton base initializer and removes explicit singleton assignment. | source-quality | C09 and exact compiler sequence | UID00046E CPP | APPLIED_VERIFIED; Gate2A and command 18148 preserve corrected constructor after UID0004Y3 |
| C15 | Constructor retains only observed early wait-state zeroing; no early appearance/body/female zeros. | exact behavior | decompile/disasm vs current draft | UID00046E CPP/evidence | APPLIED_VERIFIED; Gate2A and command 18148 preserve exact body topology |
| C16 | UID0002SI range stays `[0x0061fe3c,0x0061fed8)`. | exact | names/bytes/COL/successor | UID0002SI Range | APPLIED_VERIFIED; Gate2A and I02-I04 boundary readback passed |
| C17 | UID0002SI contains 36 function slots and three in-range COL words, including successor COL at 0x61fed4. | exact | 39 dword inventory | UID0002SI Layout | APPLIED_VERIFIED in full by Gate2A and Gate2B preserved boundaries |
| C18 | Three CreateUserDialogPane address points have exactly three lifecycle stores each. | exact | xref_query | UID0002SI Evidence | APPLIED_VERIFIED in full by Gate2A |
| C19 | UID0002SI is compiler-generated class support and becomes false/non-emitting. | exact source topology | decorated symbols, RTTI, lifecycle | UID0002SI metadata/formal | APPLIED_VERIFIED; Gate2A and command 18148 confirm no target marker |
| C20 | Raw vtable arrays, COL objects, adjustor thunks, and scalar wrappers must not be handwritten. | source-quality | MSVC ABI evidence | UID0002SI/class/UID0002QU | APPLIED_VERIFIED across accepted scope and generated output |
| C21 | Primary own override slot is 0x61fe84 -> 0x52ea80 OnDialogAction. | exact | dword/lookup/xref/child | UID0002SI Slot Inventory | APPLIED_VERIFIED in exact inventory and I06 readback |
| C22 | Secondary own slots include OnDialogShow, OnKeyEvent, and OnCreateUserReplyEvent. | exact | dword/lookup/child docs | UID0002SI Slot Inventory | APPLIED_VERIFIED; UID00046Q/R/S/T and I07-I09 readbacks agree |
| C23 | Tertiary view contains deleting-destructor adjustor and inherited Pane_OnTimer. | exact | dwords/lookup | UID0002SI Slot Inventory | APPLIED_VERIFIED in exact inventory and I12/I13 readback |
| C24 | The following vtable begins at 0x61fed8 and is not absorbed. | exact | name/xrefs/COL | UID0002SI Boundary | APPLIED_VERIFIED in Gate2A and I04 boundary readback |
| C25 | Exact IDA target and function renames/comments are safe; target pointer type depends on existing size-0x280 UDT. | strong/exact | collision/type/comment prestate | IDA handoff | APPLIED_VERIFIED; I01-I13 applied/read back in session 5a570ede and saved |
| C26 | KeyEvent and PacketEvent source signatures remain valid docs, but local IDA types are absent; I07/I08 retain exact raw declarations. | exact prestate/readback | type_inspect and Gate2B readback | IDA handoff | APPLIED_VERIFIED; I07 restored to `char __thiscall(int this, _BYTE *)` after temporary propagation and I08 remained exact |
| C27 | CreateUserDialogPane UDT stays size 0x280; no synthetic padding or fake nonempty Singleton member is added. | exact | type_inspect/PMD EBO | IDA handoff/class layout | APPLIED_VERIFIED; existing UDT preserved unchanged in Gate2B |
| C28 | Generated acceptance requires one global definition, class H, no UID0002B3/UID0002SI marker, and preserved method children. | exact target state | generated output and source topology | generated verification | APPLIED_VERIFIED; foreground command 18148 preserves accepted topology with metadata-only refresh differences |
| C29 | Stale all-ones and no-Singleton assumptions remain in explicit historical-correction sections, not deleted. | documentation policy | current docs/reports | all affected docs | APPLIED_VERIFIED by scoped validators and Gate2A |
| C30 | Manual coverage rows must be updated only by supervisor after report execution. | workflow | project skill/current callback order | four coverage reports | SUPERVISOR_PENDING_POST_EXECUTION; B003 made no manual coverage edit |

## Positive Evidence Summary

- The exact target storage is isolated by unrelated predecessor MIDI scratch refs at `0x0069b88c` and successor LivingObjectPane pool refs at `0x0069b894`.
- Five direct target xrefs close the full observed lifetime: publish/fallback, constructor-unwind clear, EH Singleton clear, and scalar destruction clear.
- Constructor caller xrefs at `0x004f7a82` and `0x004f8ff8` establish live old-dialog construction.
- RTTI exact type descriptors name `CreateUserDialogPane` and `Singleton<CreateUserDialogPane>`.
- CHD attributes and BCA/BCD ordering establish multiple inheritance and direct base order.
- Singleton PMD `+0x26c` explains the adjusted-null publication pattern and EBO overlap.
- Three decorated vtable address points, exact COLs, 36 function slots, and three lifecycle stores per base close UID0002SI ownership.
- Existing source children already express the unique authored virtual methods; the class declaration and children are sufficient to regenerate vtables.
- Current project semantic-global precedents establish one typed module definition, one H extern, false physical storage, and no duplicate emitter.

## IDA MCP Facts

### UID0002B3 storage and boundaries

| Entity | Current exact state |
| --- | --- |
| `[0x0069b890,0x0069b894)` | `00 00 00 00`; u32 `0`; one four-byte item named `g_pCreateUserDialogPane`, exact type `CreateUserDialogPane *`, accepted address-regular lifecycle comment, other channels blank/not applicable |
| predecessor `0x0069b88c` | zero; two refs from `MidiDocument_FillStreamBuffer` at `0x005272b1`/`0x0052730b` |
| successor `0x0069b894` | zero; typed `PoolAllocator`; five independent pool refs at `0x0041a107`, `0x00506071`, `0x00514c85`, `0x0053d542`, `0x0060c380` |
| absolute VA pattern | five matches, exactly corresponding to target refs |
| RVA pattern | zero matches |

### RTTI direct-base proof

- Primary COL `0x0064c8ec`: signature `0`, offset `0`, cdOffset `0`, type descriptor `0x00677fc8`, class descriptor `0x0064c900`.
- Class hierarchy descriptor `0x0064c900`: attributes `1`, base count `8`, base array `0x0064c910`.
- Complete-class BCD `0x0064c934`: type descriptor `0x00677fc8`, seven contained bases, PMD `{0,-1,0}`, attributes `0x40`.
- Direct Singleton BCD `0x0064c950`: type descriptor `0x00677fec`, PMD `{0x26c,-1,0}`, attributes `0x40`, own hierarchy descriptor `0x0064c96c`.
- Secondary/tertiary COLs `0x0064c9a0`/`0x0064c9b4` carry object offsets `0xa0`/`0xa4` and point to the same complete-class type/hierarchy.

## Function / Child Inventory

| Range | Current IDA name/type | Source/compiler role | Direct route |
| --- | --- | --- | --- |
| `[0x0052dd30,0x0052e6eb)` | `CreateUserDialogPane_Constructor`, `CreateUserDialogPane *__thiscall(CreateUserDialogPane *this)` | authored constructor plus compiler prologue/base/vptr/EH lowering | callers `0x004f7a82`, `0x004f8ff8` |
| `[0x0052e6f0,0x0052e72a)` | no function record | constructor-unwind cleanup; compiler-only | no direct entry xref; target clear at `0x52e71a` |
| `[0x0052ea80,0x0052ec80)` | `CreateUserDialogPane_OnDialogAction`, `void __thiscall(CreateUserDialogPane *this, int commandId, int action)` | `OnDialogAction` | vtable slot `0x61fe84` |
| `[0x0052ecc0,0x0052ecc9)` | `CreateUserDialogPane_OnKeyEvent`, `char __thiscall(int this, _BYTE *)` | `OnKeyEvent` bridge | vtable slot `0x61fea4` |
| `[0x0052ecd0,0x0052ecf6)` | `CreateUserDialogPane_OnCreateUserReplyEvent`, `char __thiscall(void *this, int)` | `OnCreateUserReplyEvent` | vtable slot `0x61feac` |
| `[0x0052ed00,0x0052ed09)` | `CreateUserDialogPane_OnDialogShow`, `bool __thiscall(CreateUserDialogPane *this, int reason)` | `OnDialogShow` bridge | vtable slot `0x61fea0` |
| `[0x0052f710,0x0052f71b)` | `ClearCreateUserDialogPaneSingleton`, `void __cdecl(void)` | Singleton constructor-EH clear | one EH xref `0x604c17` associated with ctor |
| `[0x0052f73b,0x0052f746)` | `CreateUserDialogPane_ScalarDeletingDestructorAdjustorA0`, `void *__thiscall(char *secondaryThis, unsigned int flags)` | `this-0xa0` deleting-destructor adjustor | vtable slot `0x61fe9c` |
| `[0x0052f746,0x0052f751)` | `CreateUserDialogPane_ScalarDeletingDestructorAdjustorA4`, `void *__thiscall(char *tertiaryThis, unsigned int flags)` | `this-0xa4` deleting-destructor adjustor | vtable slot `0x61fecc` |
| `[0x0052f800,0x0052f86c)` | `CreateUserDialogPane_ScalarDeletingDestructor`, `void *__thiscall(CreateUserDialogPane *this, unsigned int flags)` | scalar deleting destructor/compiler wrapper | primary slot plus both adjustor tails |

### Complete UID0002SI slot and COL inventory

| Address | Value/current target | Exact role |
| --- | --- | --- |
| `0x61fe3c` | `0x52f800 CreateUserDialogPane_ScalarDeletingDestructor` | primary deleting destructor slot/address point |
| `0x61fe40` | `0x4f4b10 LObject__GetRuntimeClass` | inherited primary slot |
| `0x61fe44` | `0x41b6c0 LObject__OnChangeMessage` | inherited primary slot |
| `0x61fe48` | `0x4b8e20 sub_4B8E20` | inherited primary slot |
| `0x61fe4c` | `0x41d680 Pane_DrawOnTarget` | inherited primary slot |
| `0x61fe50` | `0x544730 sub_544730` | inherited primary slot |
| `0x61fe54` | `0x544750 sub_544750` | inherited primary slot |
| `0x61fe58` | `0x5447a0 Pane_GetParentPane` | inherited primary slot |
| `0x61fe5c` | `0x544800 Pane_InvalidateRect` | inherited primary slot |
| `0x61fe60` | `0x544a20 Pane_GetDescription` | inherited primary slot |
| `0x61fe64` | `0x544b80 sub_544B80` | inherited primary slot |
| `0x61fe68` | `0x544bd0 sub_544BD0` | inherited primary slot |
| `0x61fe6c` | `0x49dfd0 sub_49DFD0` | inherited DialogPane slot |
| `0x61fe70` | `0x544cb0 sub_544CB0` | inherited primary slot |
| `0x61fe74` | `0x49e1c0 DialogPane_OnDestroy` | inherited DialogPane slot |
| `0x61fe78` | `0x49e190 sub_49E190` | inherited DialogPane slot |
| `0x61fe7c` | `0x49e210 DialogPane_OnHide` | inherited DialogPane slot |
| `0x61fe80` | `0x49f090 DialogPane_OnPaint` | inherited DialogPane slot |
| `0x61fe84` | `0x52ea80 CreateUserDialogPane_OnDialogAction` | `CreateUserDialogPane::OnDialogAction` |
| `0x61fe88` | `0x41b6a0 @_guard_check_icall_nop@4` | retained exact primary slot value |
| `0x61fe8c` | `0x49f1d0 DialogPane_DrawBackground` | inherited DialogPane slot |
| `0x61fe90` | `0x49f2e0 DialogPane_DrawBorder` | inherited DialogPane slot |
| `0x61fe94` | `0x49fc00 DialogPane_SetHoverControl` | inherited DialogPane slot |
| `0x61fe98` | `0x64c9a0 ??_R4CreateUserDialogPane@@6B@_0` | secondary Complete Object Locator, not a method slot |
| `0x61fe9c` | `0x52f73b CreateUserDialogPane_ScalarDeletingDestructorAdjustorA0` | secondary deleting-destructor adjustor/address point |
| `0x61fea0` | `0x52ed00 CreateUserDialogPane_OnDialogShow` | `OnDialogShow` |
| `0x61fea4` | `0x52ecc0 CreateUserDialogPane_OnKeyEvent` | `OnKeyEvent` |
| `0x61fea8` | `0x49ea60 DialogPane_HandleImeEvent` | inherited secondary slot |
| `0x61feac` | `0x52ecd0 CreateUserDialogPane_OnCreateUserReplyEvent` | `OnCreateUserReplyEvent` |
| `0x61feb0` | `0x544df0 sub_544DF0` | inherited secondary slot |
| `0x61feb4` | `0x544e00 sub_544E00` | inherited secondary slot |
| `0x61feb8` | `0x4a89f0 sub_4A89F0` | inherited secondary slot |
| `0x61febc` | `0x544e10 sub_544E10` | inherited secondary slot |
| `0x61fec0` | `0x544e30 sub_544E30` | inherited secondary slot |
| `0x61fec4` | `0x544e70 sub_544E70` | inherited secondary slot |
| `0x61fec8` | `0x64c9b4 ??_R4CreateUserDialogPane@@6B@_1` | tertiary Complete Object Locator, not a method slot |
| `0x61fecc` | `0x52f746 CreateUserDialogPane_ScalarDeletingDestructorAdjustorA4` | tertiary deleting-destructor adjustor/address point |
| `0x61fed0` | `0x544e90 Pane_OnTimer` | inherited tertiary slot |
| `0x61fed4` | `0x64ca14 ??_R4?$PlainMemberFunctionObject0@P8NewUserDialogPane2@@AEXXZV1@@@6B@` | successor object's COL; exact in-range boundary word, not CreateUserDialogPane slot |
| `0x61fed8` | `0x4671f0` at successor decorated address point | exclusive successor; separate object with refs `0x52a8e5`/`0x52a98e` |

## Direct Xref / Caller Inventory

### UID0002B3

| Xref | Parent | Exact meaning |
| --- | --- | --- |
| `0x0052dd87` | constructor `[0x52dd30,0x52e6eb)` | adjusted complete-object publication |
| `0x0052dd8e` | constructor | null fallback branch |
| `0x0052e71a` | raw cleanup `[0x52e6f0,0x52e72a)` | constructor-unwind reverse Singleton clear |
| `0x0052f710` | clear helper `[0x52f710,0x52f71b)` | EH-only Singleton clear |
| `0x0052f82d` | scalar wrapper `[0x52f800,0x52f86c)` | reverse Singleton clear before DialogPane teardown |

No read consumer survives. This limits direct binary proof of external linkage but does not create a source-placement blocker after project/family inference.

### UID0002SI address points

| Base | Constructor store | Raw unwind store | Scalar wrapper store |
| --- | --- | --- | --- |
| `0x0061fe3c` primary | `0x0052dda2` | `0x0052e6f9` | `0x0052f80c` |
| `0x0061fe9c` secondary | `0x0052dda8` | `0x0052e6ff` | `0x0052f812` |
| `0x0061fecc` tertiary | `0x0052ddb2` | `0x0052e709` | `0x0052f81c` |

## Documentation Evidence And IDA Status

- At assignment time, source-facing docs already agreed on old-dialog identity, `g_pCreateUserDialogPane`, source root, method children, and compiler-vtable exclusion.
- At assignment time, ordinary docs disagreed with live state on initialization, persistent IDA naming, direct Singleton inheritance, constructor source shape, and semantic/physical emission. The callback corrected these ordinary-document disagreements.
- Historically UID0002SI prose rejected handwritten vtables but remained reconstructable/emitting and created an empty marker. It is now false/non-emitting; dated checkpoints 18080, 18087, and 18113 plus final pre-execution command 18148 contain no UID0002SI marker.
- Historically UID00003B modeled authored methods/fields but omitted the direct Singleton base and placed first-draft class code in CPP. It now carries the accepted direct base and declaration in H with CPP blank.
- Historically UID00046E explicitly assigned the global and added three unobserved early zero initializers. The callback replaced those reverse-engineered approximations with the accepted direct-Singleton source shape.
- Current saved IDA has source-useful UDT coverage for the target pointer, all I01-I13 names/comments, and the accepted exact declarations. It still lacks local KeyEvent/PacketEvent types by design; I07/I08 preserve raw declarations rather than fake layouts.

## Ranked Ownership Analysis

1. **Semantic [UID:0004Y3][g_pCreateUserDialogPane](by-global/g_pCreateUserDialogPane.md) under UID0000IJ - accepted and implemented.** It is the exact source declaration/definition carrier and allows physical storage to remain non-emitting.
2. **UID00003B class - accepted semantic class owner for UID0002SI and H extern/declaration.** It regenerates vtables through normal virtual methods and direct bases.
3. **UID0000IJ file - accepted source module/root.** It owns generated `NexusTK/login/CreateUserDialogPane.cpp/.h`, but should not replace the direct semantic-global or class ownership layers.
4. **UID0002B3 as direct code emitter - rejected.** It conflates physical storage with semantic source and leaves no H contract.
5. **UID0002SI as code emitter - rejected.** Raw vtable/COL source is compiler-shaped and duplicates class output.
6. **UID0000IK CreateUserDialogs family - rejected as direct owner.** It is a non-emitting multi-variant index.
7. **Sibling NewCreateUserDialogPane/NewUserDialogPane2 globals/classes - rejected.** Their addresses, vtables, lifecycle refs, and source files are separate.
8. **MainMenuPane - rejected as definition owner.** It calls the constructor but has no target storage read; constructor use does not transfer ownership.
9. **Template static member or class static data member - rejected as final project source route.** RTTI proves Singleton behavior, but current project source vocabulary and one-definition policy consistently use a separately named `g_p<Class>` semantic global.
10. **Anonymous/file-static pointer - rejected.** It is a weaker local-only inference and conflicts with the established direct-Singleton global/header convention; no positive symbol evidence favors it.

## Source Placement

- CPP definition: semantic [UID:0004Y3][g_pCreateUserDialogPane](by-global/g_pCreateUserDialogPane.md), [UID0000IJ] `NexusTK/login/CreateUserDialogPane.cpp`, position `0`.
- H declaration/class: [UID00003B], `NexusTK/login/CreateUserDialogPane.h`, position `10`.
- Constructor definition: [UID00046E], CPP position `20`.
- Exact virtual/method children remain attached through UID00003B and preserve their current source order.
- Physical UID0002B3 and compiler UID0002SI emit nothing.
- No declaration belongs in `CreateUserDialogs.cpp`, MainMenu source, a raw globals file, or generated vtable source.

## Range / Split / Padding / Reclassification Analysis

- UID0002B3 remains exactly four bytes. Predecessor MIDI scratch ends at `0x0069b890`; successor LivingObjectPane pool begins at `0x0069b894`. Separate xref families reject merge in either direction.
- UID0002SI remains exactly `[0x0061fe3c,0x0061fed8)`. Its target convention begins at the primary vftable address point rather than the preceding primary COL. Internal secondary/tertiary COLs and the successor COL are documented explicitly.
- Do not shift UID0002SI backward to `0x61fe38` or forward through `0x61fed8`; either change would collide with established sibling ranges and decorated address-point boundaries.
- No new ignored/padding child is required. COL words are meaningful compiler data, not padding.

## Negative Evidence Summary

- No raw executable bytes support `0xffffffff`; target lies outside raw-backed `.data`.
- No persistent IDA `dword_69B890` or `g_pCreateUserDialogPane` symbol exists at evidence time.
- No target RVA pointer pattern exists; all five absolute-VA matches are already accounted for.
- No read consumer, aggregate-table indexing, pointer arithmetic, or sibling alias reaches the target.
- No evidence supports integer, handle, sentinel, pointer-to-pointer, array, or PoolAllocator typing.
- No evidence supports explicit handwritten constructor/destructor singleton writes once RTTI/PMD and EH cleanup are considered.
- No evidence supports raw vtable arrays, COL declarations, adjustor-thunk functions, scalar-delete flag source, or manual vptr stores.
- No evidence supports merging UID0002SI into sibling NewCreateUserDialogPane or following callback vtable data.
- No evidence supports synthetic authored padding at `+0x26c`; EBO resolves the offset overlap.
- No evidence supports keeping the class in CPP or leaving first-draft/example code outside the H channel.

## IDA Rename / Type / Comment Recommendations

These were supervisor-owned Gate 2B actions. The exact prestate/action/readback table is retained as operation history; supervisor Gate2B has now completed and the applied disposition is recorded below.

Fresh read-only Gate 2B prestate reconciliation ran at `2026-07-26T06:48:42.0657242-04:00` against live MCP session `5a570ede`. `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays ready, and no active analysis task. The rows below intentionally preserve every pre-mutation address and function comment channel separately; an empty channel is represented literally as `""`. Any `current` wording retained inside those table cells refers specifically to that dated historical prestate, not the final saved IDB.

### Data and vtable rows

| ID | Exact historical Gate2B prestate | Exact accepted action and protection | Complete expected/applied readback |
| --- | --- | --- | --- |
| I01 | Range `[0x0069b890,0x0069b894)`, width `0x4`/4 bytes. IDA currently models four separate undefined bytes; `inspect_items(0x0069b890)` returns head `0x69b890`, end `0x69b891`, size `1`, `is_data:false`, literal synthetic display name `unk_69B890`, persistent item name absent, and data declaration/type absent (`type:""`). Current bytes are `00 00 00 00`; `u32le` value is `0x00000000`/0/null. Address-regular comment is `""`. Address-repeatable comment is `""`. Function-regular comment is not applicable because this is nonfunction data. Function-repeatable comment is not applicable because this is nonfunction data. | Define exactly one 4-byte data item over `[0x0069b890,0x0069b894)`, rename it `g_pCreateUserDialogPane`, and apply exact data declaration/type `CreateUserDialogPane *`. Set only the address-regular comment to `Loader-zeroed CreateUserDialogPane singleton backing storage; direct Singleton<CreateUserDialogPane> publication and reverse teardown.` Preserve address-repeatable as `""`; do not create function comments. Exact `list_globals(filter="g_pCreateUserDialogPane")` returned zero rows, so the proposed data name has no current collision. Reuse the existing `CreateUserDialogPane` UDT of size `0x280`; do not create a duplicate UDT. Preserve the predecessor and successor boundaries. | Head `0x69b890`, end `0x69b894`, size `0x4`; persistent name exactly `g_pCreateUserDialogPane`; data declaration/type exactly `CreateUserDialogPane *`; bytes still `00 00 00 00`; `u32le` value still 0/null. Address-regular comment equals the proposed sentence exactly. Address-repeatable remains `""`. Function-regular remains not applicable. Function-repeatable remains not applicable. No byte, predecessor, successor, or UDT-size change. |
| I02 | Range `[0x0061fe3c,0x0061fe40)`, width `0x4`/4 bytes. Current persistent name is exactly `??_7CreateUserDialogPane@@6B@`. Current data declaration/type is absent (`type:""`); `is_data:true`. Current bytes are `00 f8 52 00`; `u32le` value is `0x0052f800`, pointing to `sub_52F800`. Address-regular comment is `""`. Address-repeatable comment is `""`. Function-regular comment is not applicable because this is nonfunction data. Function-repeatable comment is not applicable because this is nonfunction data. | Preserve exact name `??_7CreateUserDialogPane@@6B@`, absent data declaration/type, bytes, and pointer value. Set only the address-regular comment to `CreateUserDialogPane primary vftable address point; compiler-generated from the class declaration and virtual method definitions.` Preserve address-repeatable as `""`; do not create function comments. No rename is proposed, so a proposed-name collision lookup is not applicable. Do not apply a raw-array type. Preserve preceding COL dword `[0x0061fe38,0x0061fe3c)`. | Range, width, and item boundaries remain `[0x0061fe3c,0x0061fe40)` and `0x4`; name remains exactly `??_7CreateUserDialogPane@@6B@`; data declaration/type remains absent; bytes remain `00 f8 52 00`; pointer remains `0x0052f800`. Address-regular comment equals the proposed sentence exactly. Address-repeatable remains `""`. Function-regular remains not applicable. Function-repeatable remains not applicable. Preceding COL and all vtable slots remain unchanged. |
| I03 | Range `[0x0061fe9c,0x0061fea0)`, width `0x4`/4 bytes. Current persistent name is exactly `??_7CreateUserDialogPane@@6B@_0`. Current data declaration/type is absent (`type:""`); `is_data:true`. Current bytes are `3b f7 52 00`; `u32le` value is `0x0052f73b`, pointing to `sub_52F73B`. Address-regular comment is `""`. Address-repeatable comment is `""`. Function-regular comment is not applicable because this is nonfunction data. Function-repeatable comment is not applicable because this is nonfunction data. | Preserve exact name `??_7CreateUserDialogPane@@6B@_0`, absent data declaration/type, bytes, and pointer value. Set only the address-regular comment to `CreateUserDialogPane secondary vftable address point; compiler-generated multiple-inheritance view.` Preserve address-repeatable as `""`; do not create function comments. No rename is proposed, so a proposed-name collision lookup is not applicable. Do not apply a raw-array type. Preserve preceding COL dword `[0x0061fe98,0x0061fe9c)`. | Range, width, and item boundaries remain `[0x0061fe9c,0x0061fea0)` and `0x4`; name remains exactly `??_7CreateUserDialogPane@@6B@_0`; data declaration/type remains absent; bytes remain `3b f7 52 00`; pointer remains `0x0052f73b`. Address-regular comment equals the proposed sentence exactly. Address-repeatable remains `""`. Function-regular remains not applicable. Function-repeatable remains not applicable. Preceding COL and all vtable slots remain unchanged. |
| I04 | Range `[0x0061fecc,0x0061fed0)`, width `0x4`/4 bytes. Current persistent name is exactly `??_7CreateUserDialogPane@@6B@_1`. Current data declaration/type is absent (`type:""`); `is_data:true`. Current bytes are `46 f7 52 00`; `u32le` value is `0x0052f746`, pointing to `sub_52F746`. Address-regular comment is `""`. Address-repeatable comment is `""`. Function-regular comment is not applicable because this is nonfunction data. Function-repeatable comment is not applicable because this is nonfunction data. | Preserve exact name `??_7CreateUserDialogPane@@6B@_1`, absent data declaration/type, bytes, and pointer value. Set only the address-regular comment to `CreateUserDialogPane tertiary vftable address point; compiler-generated multiple-inheritance view.` Preserve address-repeatable as `""`; do not create function comments. No rename is proposed, so a proposed-name collision lookup is not applicable. Do not apply a raw-array type. Preserve preceding COL dword `[0x0061fec8,0x0061fecc)` and successor COL dword `[0x0061fed4,0x0061fed8)`. | Range, width, and item boundaries remain `[0x0061fecc,0x0061fed0)` and `0x4`; name remains exactly `??_7CreateUserDialogPane@@6B@_1`; data declaration/type remains absent; bytes remain `46 f7 52 00`; pointer remains `0x0052f746`. Address-regular comment equals the proposed sentence exactly. Address-repeatable remains `""`. Function-regular remains not applicable. Function-repeatable remains not applicable. Both adjacent COL dwords and all vtable slots remain unchanged. |

### Function rows

| ID | Exact historical function prestate and collision result | Exact accepted action | Complete expected/applied readback and boundary protection |
| --- | --- | --- | --- |
| I05 | Range `[0x0052dd30,0x0052e6eb)`, size `0x9bb`/2491 bytes. Current name exactly `sub_52DD30`. Current declaration exactly `int __thiscall(int this)`. Address-regular comment `""`; address-repeatable comment `""`; function-regular comment `""`; function-repeatable comment `""`. Exact `lookup_funcs("CreateUserDialogPane_Constructor")` returned `fn:null`, `error:"Not found"`; no proposed-name collision. | Rename to `CreateUserDialogPane_Constructor`. Apply exact declaration `CreateUserDialogPane *__thiscall(CreateUserDialogPane *this)`. Set only function-regular comment to `Constructs the old DLGNEW3 create-user dialog; direct DialogPane and Singleton<CreateUserDialogPane> bases generate publication and vptr/EH lowering.` Preserve address-regular, address-repeatable, and function-repeatable as `""`. Reuse existing `CreateUserDialogPane` UDT. | Name exactly `CreateUserDialogPane_Constructor`; declaration exactly `CreateUserDialogPane *__thiscall(CreateUserDialogPane *this)`. Address-regular `""`; address-repeatable `""`; function-regular equals the proposed sentence exactly; function-repeatable `""`. Function start `0x0052dd30`, end `0x0052e6eb`, and size `0x9bb` remain unchanged; no boundary absorption. |
| I06 | Range `[0x0052ea80,0x0052ec80)`, size `0x200`/512 bytes. Current name exactly `sub_52EA80`. Current declaration exactly `void __thiscall(int this, int, int)`. Address-regular comment `""`; address-repeatable comment `""`; function-regular comment `""`; function-repeatable comment `""`. Exact `lookup_funcs("CreateUserDialogPane_OnDialogAction")` returned `fn:null`, `error:"Not found"`; no proposed-name collision. | Rename to `CreateUserDialogPane_OnDialogAction`. Apply exact declaration `void __thiscall(CreateUserDialogPane *this, int commandId, int action)`. Set only function-regular comment to `Handles old create-user dialog commands, selector updates, preview refresh, submission, and close.` Preserve address-regular, address-repeatable, and function-repeatable as `""`. Reuse existing `CreateUserDialogPane` UDT. | Name exactly `CreateUserDialogPane_OnDialogAction`; declaration exactly `void __thiscall(CreateUserDialogPane *this, int commandId, int action)`. Address-regular `""`; address-repeatable `""`; function-regular equals the proposed sentence exactly; function-repeatable `""`. Function start `0x0052ea80`, end `0x0052ec80`, and size `0x200` remain unchanged; no boundary absorption. |
| I07 | Range `[0x0052ecc0,0x0052ecc9)`, size `0x9`/9 bytes. Current name exactly `sub_52ECC0`. Current declaration exactly `char __thiscall(int this, _BYTE *)`. Address-regular comment `""`; address-repeatable comment `""`; function-regular comment `""`; function-repeatable comment `""`. Exact `lookup_funcs("CreateUserDialogPane_OnKeyEvent")` returned `fn:null`, `error:"Not found"`; no proposed-name collision. | Rename to `CreateUserDialogPane_OnKeyEvent`. Preserve exact current declaration `char __thiscall(int this, _BYTE *)`; do not apply a type because local `KeyEvent` is absent and an invented UDT is prohibited. Set only function-regular comment to `CreateUserDialogPane key-event bridge delegating to DialogPane::OnKeyEvent.` Preserve address-regular, address-repeatable, and function-repeatable as `""`. | Name exactly `CreateUserDialogPane_OnKeyEvent`; declaration remains exactly `char __thiscall(int this, _BYTE *)`. Address-regular `""`; address-repeatable `""`; function-regular equals the proposed sentence exactly; function-repeatable `""`. Function start `0x0052ecc0`, end `0x0052ecc9`, and size `0x9` remain unchanged; no boundary absorption. |
| I08 | Range `[0x0052ecd0,0x0052ecf6)`, size `0x26`/38 bytes. Current name exactly `sub_52ECD0`. Current declaration exactly `char __thiscall(void *this, int)`. Address-regular comment `""`; address-repeatable comment `""`; function-regular comment `""`; function-repeatable comment `""`. Exact `lookup_funcs("CreateUserDialogPane_OnCreateUserReplyEvent")` returned `fn:null`, `error:"Not found"`; no proposed-name collision. | Rename to `CreateUserDialogPane_OnCreateUserReplyEvent`. Preserve exact current declaration `char __thiscall(void *this, int)`; do not apply a type because local `PacketEvent` is absent and an invented UDT is prohibited. Set only function-regular comment to `Create-user PacketEvent bridge: accepts payload marker 0x02 and tail-dispatches HandleCreateUserReply.` Preserve address-regular, address-repeatable, and function-repeatable as `""`. | Name exactly `CreateUserDialogPane_OnCreateUserReplyEvent`; declaration remains exactly `char __thiscall(void *this, int)`. Address-regular `""`; address-repeatable `""`; function-regular equals the proposed sentence exactly; function-repeatable `""`. Function start `0x0052ecd0`, end `0x0052ecf6`, and size `0x26` remain unchanged; no boundary absorption. |
| I09 | Range `[0x0052ed00,0x0052ed09)`, size `0x9`/9 bytes. Current name exactly `sub_52ED00`. Current declaration exactly `char __thiscall(int this, int)`. Address-regular comment `""`; address-repeatable comment `""`; function-regular comment `""`; function-repeatable comment `""`. Exact `lookup_funcs("CreateUserDialogPane_OnDialogShow")` returned `fn:null`, `error:"Not found"`; no proposed-name collision. | Rename to `CreateUserDialogPane_OnDialogShow`. Apply exact declaration `bool __thiscall(CreateUserDialogPane *this, int reason)`. Set only function-regular comment to `CreateUserDialogPane dialog-show bridge delegating to DialogPane::OnDialogShow.` Preserve address-regular, address-repeatable, and function-repeatable as `""`. Reuse existing `CreateUserDialogPane` UDT. | Name exactly `CreateUserDialogPane_OnDialogShow`; declaration exactly `bool __thiscall(CreateUserDialogPane *this, int reason)`. Address-regular `""`; address-repeatable `""`; function-regular equals the proposed sentence exactly; function-repeatable `""`. Function start `0x0052ed00`, end `0x0052ed09`, and size `0x9` remain unchanged; no boundary absorption. |
| I10 | Range `[0x0052f710,0x0052f71b)`, size `0xb`/11 bytes. Current name exactly `sub_52F710`. Current declaration exactly `void()`. Address-regular comment `""`; address-repeatable comment `""`; function-regular comment `""`; function-repeatable comment `""`. Exact `lookup_funcs("ClearCreateUserDialogPaneSingleton")` returned `fn:null`, `error:"Not found"`; no proposed-name collision. | Rename to `ClearCreateUserDialogPaneSingleton`. Apply exact declaration `void __cdecl(void)`. Set only function-regular comment to `Compiler-generated Singleton<CreateUserDialogPane> constructor-unwind clear; no handwritten source helper.` Preserve address-regular, address-repeatable, and function-repeatable as `""`; preserve the EH-only xref. | Name exactly `ClearCreateUserDialogPaneSingleton`; declaration exactly `void __cdecl(void)`. Address-regular `""`; address-repeatable `""`; function-regular equals the proposed sentence exactly; function-repeatable `""`. Function start `0x0052f710`, end `0x0052f71b`, and size `0xb` remain unchanged; EH route and adjacent bytes remain unchanged. |
| I11 | Range `[0x0052f73b,0x0052f746)`, size `0xb`/11 bytes. Current name exactly `sub_52F73B`. Current declaration exactly `void *__thiscall(char *this, char)`. Address-regular comment exactly `Block`; address-repeatable comment `""`; function-regular comment `""`; function-repeatable comment `""`. Exact `lookup_funcs("CreateUserDialogPane_ScalarDeletingDestructorAdjustorA0")` returned `fn:null`, `error:"Not found"`; no proposed-name collision. | Rename to `CreateUserDialogPane_ScalarDeletingDestructorAdjustorA0`. Apply exact declaration `void *__thiscall(char *secondaryThis, unsigned int flags)`. Clear only the stale address-regular comment `Block`; preserve address-repeatable as `""`. Set function-regular comment to `Compiler-generated this-0xa0 adjustor thunk to the CreateUserDialogPane scalar deleting destructor.` Preserve function-repeatable as `""`. The proposed declaration uses built-in types only. | Name exactly `CreateUserDialogPane_ScalarDeletingDestructorAdjustorA0`; declaration exactly `void *__thiscall(char *secondaryThis, unsigned int flags)`. Address-regular `""`; address-repeatable `""`; function-regular equals the proposed sentence exactly; function-repeatable `""`. Function start `0x0052f73b`, end `0x0052f746`, and size `0xb` remain unchanged; target and fall-through boundaries remain unchanged. |
| I12 | Range `[0x0052f746,0x0052f751)`, size `0xb`/11 bytes. Current name exactly `sub_52F746`. Current declaration exactly `void *__thiscall(char *this, char)`. Address-regular comment exactly `Block`; address-repeatable comment `""`; function-regular comment `""`; function-repeatable comment `""`. Exact `lookup_funcs("CreateUserDialogPane_ScalarDeletingDestructorAdjustorA4")` returned `fn:null`, `error:"Not found"`; no proposed-name collision. | Rename to `CreateUserDialogPane_ScalarDeletingDestructorAdjustorA4`. Apply exact declaration `void *__thiscall(char *tertiaryThis, unsigned int flags)`. Clear only the stale address-regular comment `Block`; preserve address-repeatable as `""`. Set function-regular comment to `Compiler-generated this-0xa4 adjustor thunk to the CreateUserDialogPane scalar deleting destructor.` Preserve function-repeatable as `""`. The proposed declaration uses built-in types only. | Name exactly `CreateUserDialogPane_ScalarDeletingDestructorAdjustorA4`; declaration exactly `void *__thiscall(char *tertiaryThis, unsigned int flags)`. Address-regular `""`; address-repeatable `""`; function-regular equals the proposed sentence exactly; function-repeatable `""`. Function start `0x0052f746`, end `0x0052f751`, and size `0xb` remain unchanged; target and successor boundaries remain unchanged. |
| I13 | Range `[0x0052f800,0x0052f86c)`, size `0x6c`/108 bytes. Current name exactly `sub_52F800`. Current declaration exactly `void *__thiscall(void *Block, char)`. Address-regular comment `""`; address-repeatable comment `""`; function-regular comment `""`; function-repeatable comment `""`. Exact `lookup_funcs("CreateUserDialogPane_ScalarDeletingDestructor")` returned `fn:null`, `error:"Not found"`; no proposed-name collision. | Rename to `CreateUserDialogPane_ScalarDeletingDestructor`. Apply exact declaration `void *__thiscall(CreateUserDialogPane *this, unsigned int flags)`. Set only function-regular comment to `Compiler-generated CreateUserDialogPane scalar deleting destructor: member/base teardown, Singleton clear, delete-flag handling, and optional free.` Preserve address-regular, address-repeatable, and function-repeatable as `""`. Reuse existing `CreateUserDialogPane` UDT. | Name exactly `CreateUserDialogPane_ScalarDeletingDestructor`; declaration exactly `void *__thiscall(CreateUserDialogPane *this, unsigned int flags)`. Address-regular `""`; address-repeatable `""`; function-regular equals the proposed sentence exactly; function-repeatable `""`. Function start `0x0052f800`, end `0x0052f86c`, and size `0x6c` remain unchanged; adjacent function/data boundaries remain unchanged. |

### Gate2B applied/readback disposition

- `APPLIED_VERIFIED`: supervisor applied and read back I01-I13 in live MCP session `5a570ede`; all accepted names, declarations, selected comment channels, blank preserved channels, item widths, ranges, and boundaries match the table's expected readback.
- I07 temporarily inherited an unwanted rename-side type propagation. Supervisor explicitly restored the exact accepted declaration `char __thiscall(int this, _BYTE *)` and re-read it successfully; the final saved state therefore matches I07 exactly rather than the transient propagated declaration.
- The existing `CreateUserDialogPane` UDT remained present and unchanged; no duplicate UDT, `KeyEvent`, `PacketEvent`, raw-vtable array type, synthetic padding, or fake Singleton storage was created.
- Pre-mutation backup `E:\NTK\Resources\NexusTK\NexusTK.pre-B003-0002B3-20260726-0823.i64` has SHA256 `E750777D5910FD196D4B905FD8B26C947F17D0A2C65F3A39C7F0F729020B2B07`.
- Saved IDB SHA256 is `9B1382E39799069EE002B70919732CE6EBE4E8800B1CA43BF4B4989B7B92C3CB`, 143,189,808 bytes, last write `2026-07-26T08:25:14.4077853-04:00`; supervisor catalog entry is `0331`.
- B003 performed no IDA mutation or save; this section reconciles the supervisor-owned Gate2B result.

### UDT/type dependency disposition

- Gate2B preserved `CreateUserDialogPane` UDT ordinal `592`, size `0x280`, current eight data members and exact offsets. No synthetic padding or fake nonzero Singleton member was added.
- Record direct Singleton inheritance in source docs and function/vtable comments. The empty base has no independent storage member and overlaps the `+0x26c` derived field under old-MSVC EBO.
- Gate2B did not create `KeyEvent` or `PacketEvent` UDTs. Their source-facing signatures remain documented, while I07/I08 preserve the accepted exact raw IDA declarations.
- Gate2B did not type the vtable spans as handwritten arrays. Decorated address-point names, dword values, COL boundaries, comments, and class/method source remain sufficient.

## First-Draft C++ Recommendation

### Destination 1 - semantic UID0004Y3 global CPP

```cpp
class CreateUserDialogPane;

CreateUserDialogPane *g_pCreateUserDialogPane = 0;
```

H channel on the semantic global remains blank. The matching extern belongs to the class H.

### Destination 2 - UID00003B H

```cpp
class CreateUserDialogPane;
extern CreateUserDialogPane *g_pCreateUserDialogPane;

class CreateUserDialogPane : public DialogPane,
                             public Singleton<CreateUserDialogPane>
{
public:
    CreateUserDialogPane();
    virtual ~CreateUserDialogPane();

    void SelectBodyShape(short bodyShapeIndex);
    void SelectMale();
    void SelectFemale();
    unsigned char SetHairColorIndex(unsigned char colorIndex);
    unsigned char SetFaceColorIndex(unsigned char colorIndex);

protected:
    void OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration);
    void OnNexonclubRegistrationResult(const SimpleUString &text);

    virtual void OnDialogAction(int commandId, int action);
    virtual bool OnKeyEvent(KeyEvent *event);
    virtual bool OnCreateUserReplyEvent(const PacketEvent *event);
    virtual bool OnDialogShow(int reason);

    void SubmitCreateUser();
    void SendCreateCharacterRequest();
    bool HandleCreateUserReply(const unsigned char *packet);

private:
    int m_initialAppearanceRoll;
    int m_bodyShapeIndex;
    unsigned char m_waitingForCharacterReply;
    unsigned char m_isFemale;
    SimpleUString m_createUserExtraText;
};

[[CHILDREN]]
```

UID00003B CPP channel becomes exactly blank.

### Destination 3 - UID00046E constructor correction

The callback replaced the historical initializer/preamble with:

```cpp
CreateUserDialogPane::CreateUserDialogPane()
    : DialogPane(L"NE", -1, 4),
      Singleton<CreateUserDialogPane>(),
      m_waitingForCharacterReply(0)
{
    m_createUserExtraText.clear();
```

The remainder of the accepted constructor body, including later `rand()` assignments, is preserved. No explicit singleton assignment, early zero initializers for the other three fields, vptr stores, EH cleanup, or raw member/base destruction was reinserted.

### Destination 4 - UID0002B3 and UID0002SI

Both CPP and H channels are exactly blank because they are false/non-emitting physical/compiler evidence. Dated checkpoints 18080, 18087, and 18113 first confirmed that neither target emits an empty-marker comment; final pre-execution command 18148 reconfirms the same target-marker absence. The UID00003B CPP empty marker is intentional and unrelated because the class source is H-only.

## Final Recommendation

- Historical Gate 1 accepted exact SHA256 `6AAFAE4574E2512AAE1D233C20AD5467DD3073DC70AB90CA7DA0972F57DB085D`, and the semantic-global/class/constructor/physical/vtable ordinary callback is complete exactly as ledgered. Supervisor Gate2A passed.
- UID0002B3 and UID0002SI ceased to be empty emitters by becoming correctly false/non-emitting, not by inserting placeholder comments or raw ABI code.
- Final pre-execution foreground command 18148 source output has one real UID0004Y3 global definition before UID00046E and one UID00003B header declaration/class shape; compiler/template output remains represented by source causes rather than copied machine artifacts. Body topology is unchanged from dated command 18113; only refresh metadata changed.
- Supervisor Gate2B is `APPLIED_VERIFIED`: I01-I13 were applied/read back, I07 was restored to exact `char __thiscall(int this, _BYTE *)`, the existing UDT was preserved, the IDB was saved at the recorded hash, and catalog entry 0331 was written. B003 did not mutate IDA.
- The report is ready for a fresh final exact-artifact supervisor Gate 1. Execution/archive, post-execution manual coverage/coverage validation, and post-archive audit remain supervisor-owned.

## Recommended Target Doc Changes

### UID0002B3

- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0004Y3`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank CPP/H, `Nested:0` preserved.
- Applied loader-zero physical backing, exact PE section math, five-ref lifecycle, direct Singleton source cause, semantic-global route, boundary proof, one-definition/no-duplicate policy, and generated-marker removal.
- Preserved old `0xffffffff` and `dword_69B890` claims only in `Historical And Superseded Assumptions`, with exact current correction adjacent.
- Preserved the historical no-name/type/item prestate and now records supervisor Gate2B I01 `APPLIED_VERIFIED` current name/type/item/comment readback.

### UID0002SI

- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, owner UID00003B, `RECONSTRUCTABLE:FALSE`, blank emitter/position/CPP/H, `Nested:0` preserved.
- Added the full 36-slot and three in-range COL inventory, exact three-by-three lifecycle refs, primary preceding COL, successor COL/address point boundary, direct class/source route, and no-handwritten-vtable proof.
- Preserved all existing valid method-role and sibling-boundary evidence and corrected prose so `0x61fe98`, `0x61fec8`, and `0x61fed4` are never active method-slot claims.

## Recommended Support Doc Changes

1. Applied: created [UID:0004Y3] `by-global/g_pCreateUserDialogPane.md` at `92/93`, owner/emitter UID0000IJ, position `0`, true, Destination 1 CPP, blank H, and full accepted evidence/history.
2. Applied: UID00003B is `92/93`, position `10`, CPP blank, Destination 2 H, with direct Singleton/PMD/EBO evidence, one extern, false physical/vtable children, and no explicit lifecycle lowering.
3. Applied: UID0000IJ is `92/93` with semantic global at 0, class H at 10, constructor at 20, both former target empty emitters resolved, generated criteria, and full source union.
4. Applied: UID00046E is `92/93`, position `20`, with Destination 3 and exact publication/initializer correction history.
5. Applied without score/route change: UID00046F identifies compiler reverse-Singleton cleanup and links UID0004Y3/UID0002B3.
6. Applied without role change: UID0002QT records the direct Singleton/global/vtable physical split and constructor correction.
7. Applied without false/non-emitting change: UID0002QU records the accepted historical IDA prestates and compiler regeneration of old-dialog clear/thunk/scalar bodies; this report records the later Gate2B current readback.
8. Applied without mixed-index route change: UID00025Z records UID0002SI's current false/generated disposition and exact COL/address-point boundaries.
9. Verified read-only: UID00046Q/R/S/T retain same-or-greater behavior/signature detail and contain no concrete stale vtable/source-route contradiction; no edit was made.
10. Historical callback validator command 18080 refreshed generated output and B003 made no manual generated edit. Commands 18087 and 18113 are retained as dated checkpoints. Supervisor Gate2A passed and foreground command 18148 produced the final pre-execution generated identity with accepted body topology unchanged. No B003 generated edit occurred.

## Score And Metadata Recommendation

| UID/path | Historical baseline | Applied/current | Owner/emitter/reconstructable/formal |
| --- | ---: | ---: | --- |
| UID0002B3 physical slot | `86/91` | `92/94` | owner UID0004Y3; emitter blank; false; CPP/H blank |
| UID0002SI vtable data | `88/91` | `92/94` | owner UID00003B; emitter blank; false; CPP/H blank |
| [UID:0004Y3] `by-global/g_pCreateUserDialogPane.md` | absent | `92/93` | owner/emitter UID0000IJ; position 0; true; CPP definition |
| UID00003B class | `88/89` | `92/93` | owner/emitter UID0000IJ; position 10; true; H declaration/CPP blank |
| UID0000IJ file | `88/89` | `92/93` | source root preserved |
| UID00046E constructor | `87/89` | `92/93` | owner/emitter UID00003B; position 20; corrected CPP |
| UID00046F/UID0002QT/UID0002QU/UID00025Z | existing scores/routes | unchanged | prose/source-route synchronization only |

- UID0002B3 completion reaches 92 because exact physical state, PE initialization, type/name/linkage, five-ref lifetime, direct Singleton source cause, source root, semantic ownership, one-definition policy, range, completed IDA disposition, and generated disposition are resolved.
- UID0002SI completion reaches 92 because every function slot/COL, address point, lifecycle xref, source class/method cause, range boundary, and no-code disposition is resolved.
- Confidence remains below 95 because stripped original lexical naming, explicit-zero token, and linkage spelling cannot be proven byte-for-byte, even though the selected source shape is high probability and no IDA-looking placeholder remains.
- No code-emitting page is recommended above 95.

## Open Questions With Attempted Resolution

- **Was startup value `0xffffffff`?** No. Exact PE/IDA proof resolves loader zero; old all-ones text is stale.
- **Is the storage a pointer or integer?** Exact constructor/scalar/RTTI evidence resolves `CreateUserDialogPane *`.
- **Is it a file static, template static member, or external project global?** Direct refs alone cannot distinguish linkage, but current project direct-Singleton conventions, sibling create-user globals, and the established `g_pCreateUserDialogPane` vocabulary make one external semantic global plus H extern the highest-probability human source. This is selected, not deferred.
- **Should the constructor explicitly assign the pointer?** No. PMD/EBO and EH reverse-clear prove direct Singleton base lowering. Source initializes the base.
- **Does Singleton consume `+0x26c` and invalidate the field?** No. It is an empty direct base; old-MSVC EBO overlaps the derived field at the same offset.
- **Should vtables emit arrays or comments?** No. Class H and exact virtual children regenerate them. Physical UID0002SI becomes false/non-emitting; prose preserves the complete ABI evidence.
- **Should UID0002SI range change around COLs?** No. Existing address-point page convention and exact predecessor/successor boundaries justify the current half-open range; internal/successor COLs are explicitly inventoried.
- **Can IDA function types use KeyEvent/PacketEvent now?** Source signatures are resolved, but current IDA lacks those shared types. Gate2B safely renamed/commented the functions and preserved the exact raw declarations; I07 was explicitly restored after temporary propagation. No fake UDT was created. This does not block target source or score because the exact source pages already own the typed signatures.
- No in-scope ownership, source placement, range, type, initialization, emission, or C++ blocker remains.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The following is supervisor-owned post-execution pending text. B003 must not edit coverage files.

### by-memory replacement for UID0002B3

`    - [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md) 0x0069b890-0x0069b894 | singleton backing storage | CreateUserDialogPaneSingletonSlot : not_reconstructable : 92% : very-strong : Exact four-byte loader-zeroed physical backing for the sole CreateUserDialogPane *g_pCreateUserDialogPane definition; five direct refs cover direct Singleton<CreateUserDialogPane> publication/fallback, constructor-unwind clear, EH clear, and scalar teardown; RTTI proves the +0x26c empty direct Singleton base, semantic UID0004Y3 owns source emission, and this physical page is false/non-emitting with stale 0xffffffff wording superseded.`

### by-memory replacement for UID0002SI

`        - [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md) 0x0061fe3c-0x0061fed8 | compiler-generated vtable/COL support | CreateUserDialogPaneVtableData : not_reconstructable : 92% : very-strong : Exact non-emitting MSVC CreateUserDialogPane vtable block with primary/secondary/tertiary address points at 0x0061fe3c/0x0061fe9c/0x0061fecc, 36 function slots, internal COLs at 0x0061fe98/0x0061fec8, successor COL at 0x0061fed4, three constructor/unwind/scalar stores per address point, scalar/adjustor/OnDialogAction/OnDialogShow/OnKeyEvent/OnCreateUserReplyEvent routes, exact successor 0x0061fed8, direct DialogPane plus Singleton<CreateUserDialogPane> source hierarchy, and class/virtual source regeneration instead of raw arrays or an empty marker.`

### by-class replacement for UID00003B

`- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) : reconstructable : 92% : very-strong : Complete old CreateUserDialogPane header declaration under UID0000IJ with direct DialogPane plus RTTI-proven Singleton<CreateUserDialogPane> inheritance, +0x26c EBO overlap, one g_pCreateUserDialogPane extern, exact 0x280 layout, 22-child source/compiler split, corrected constructor base/publication semantics, full control/field/packet/reply/callback behavior, three-view vtable and loader-zero singleton backing, H-channel C++ with CPP children, and no handwritten vptr/EH/thunk/scalar/vtable data.`

### by-file replacement for UID0000IJ

`- [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) : reconstructable : 92% : very-strong : Complete NexusTK/login/CreateUserDialogPane source root with one zero-initialized g_pCreateUserDialogPane definition at position 0, complete class H at position 10, corrected direct Singleton constructor at position 20, exact method-child source union, DLGNEW3 controls and appearance flow, registration callback and packet/reply behavior, loader-zero physical storage, three-view compiler vtable/COL block, lifecycle/thunk exclusions, and zero remaining UID0002B3/UID0002SI empty markers.`

### by-global insertion after validator allocates the UID

`- [UID:0004Y3][g_pCreateUserDialogPane](by-global/g_pCreateUserDialogPane.md) : reconstructable : 92% : very-strong : Sole externally linked zero-initialized CreateUserDialogPane * definition in NexusTK/login/CreateUserDialogPane.cpp at position 0, backed by false/non-emitting UID0002B3; exact five-reference direct Singleton<CreateUserDialogPane> publish/clear lifecycle, +0x26c RTTI/EBO source cause, class-header extern contract, one-definition policy, stale 0xffffffff correction, and no duplicate physical/template/static emitter.`

## Follow-Up Actions

1. Historical: Gate 1 passed exact SHA256 `6AAFAE4574E2512AAE1D233C20AD5467DD3073DC70AB90CA7DA0972F57DB085D` before the ordinary callback. Post-callback SHA256 `66791ECDF6BAFC42F044F35402DC9300EDA060941C74CE77C16A7E27F9B0C4CE` and repaired SHA256 `93D53C2F6078FD32BD1BB4044B04F711E6EA85FC9F791E6F28656825C3B09798` each failed only narrow generated-checkpoint currentness defects; all research and implementation evidence remained valid.
2. `APPLIED_VERIFIED`: ordinary callback implementation is complete and supervisor Gate2A passed. Scoped confirmation commands 18124-18147 all exited `0`/`ok:1`; duplicate commands from draining the original serial loop were harmless.
3. `APPLIED_VERIFIED`: foreground generated refresh command 18148 completed with final pre-execution CPP/H identities and accepted body topology unchanged from 18113.
4. `APPLIED_VERIFIED`: supervisor Gate2B applied/read back I01-I13 in session `5a570ede`, restored I07's exact raw declaration, preserved the existing UDT, saved the IDB at the recorded hash, and cataloged entry 0331.
5. Pending supervisor: run fresh final exact-artifact Gate 1 on this reconciled report.
6. Pending supervisor: issue `execute_report` and archive only after that Gate 1 passes.
7. Pending supervisor after execution: apply the exact manual coverage text and run coverage validation.
8. Pending supervisor after archive: perform the exact archived-artifact audit.

## Confidence

- **UID0002B3 physical facts: 94.** Exact bytes, PE mapping, range, xrefs, type, lifetime, RTTI/PMD, neighbors, and compiler lowering agree.
- **UID0002SI compiler facts: 94.** Exact decorated bases, all 39 in-range dwords, 36 function slots, three COL words, lifecycle refs, boundaries, and source regeneration agree.
- **Human source spelling/linkage: 93.** `g_pCreateUserDialogPane`, external linkage, explicit `= 0`, direct Singleton base, and header/source placement are the strongest project-consistent inference; stripped symbols prevent 95+ lexical certainty.
- **Overall recommendation: very strong and implementation-ready below the 95 barrier.**

## Validator Results

- `000000018038` at `2026-07-26T06:56:26-04:00`: scoped create/validate `by-global/g_pCreateUserDialogPane.md`; exit `0`, `ok:1`; validator issued UID0004Y3.
- `000000018040` at `2026-07-26T06:58:09-04:00`: scoped UID0002B3 target validation; exit `0`, `ok:1`; `92/94`, owner UID0004Y3, false/non-emitting.
- `000000018053` at `2026-07-26T06:59:50-04:00`: scoped UID0002SI validation; exit `0`, `ok:1`; `92/94`, owner UID00003B, false/non-emitting.
- `000000018057` at `2026-07-26T07:01:22-04:00`: scoped UID00003B class validation; exit `0`, `ok:1`; `92/93`, position 10, blank CPP, accepted H.
- `000000018060` at `2026-07-26T07:02:50-04:00`: scoped UID0000IJ file validation; exit `0`, `ok:1`; `92/93` source root.
- `000000018061` at `2026-07-26T07:05:05-04:00`: scoped UID00046E constructor validation; exit `0`, `ok:1`; `92/93`, position 20.
- `000000018070` at `2026-07-26T07:06:46-04:00`: initial scoped UID00046F support validation; exit `0`, `ok:1`. A report-to-page address transcription was then corrected.
- `000000018073` at `2026-07-26T07:08:14-04:00`: final scoped UID00046F validation after restoring exact five target xrefs `0x52dd87`, `0x52dd8e`, `0x52e71a`, `0x52f710`, `0x52f82d`; exit `0`, `ok:1`.
- `000000018072` at `2026-07-26T07:07:33-04:00`: scoped UID0002QT support validation; exit `0`, `ok:1`.
- `000000018074` at `2026-07-26T07:10:21-04:00`: scoped UID0002QU support validation; exit `0`, `ok:1`.
- `000000018075` at `2026-07-26T07:11:11-04:00`: scoped UID00025Z support validation; exit `0`, `ok:1`.
- `000000018080` at `2026-07-26T07:11:56-04:00`: historical callback validator autogen refresh; exit `0`; `generated_refresh:completed`. Its then-current readback confirmed one UID0004Y3 definition, corrected UID00046E constructor, accepted UID00003B H, preserved child bodies, and no UID0002B3/UID0002SI empty marker.
- `000000018087` at `2026-07-26T07:21:12-04:00`: dated unrelated supervisor refresh, not run by B003 during this repair. Supervisor-provided read-only facts recorded CPP SHA256 `5F44A0B4729F0950502B20793E4AF6E9C0A142C990435EA195162F3EAF4D149F` and H SHA256 `ABD4E532131BCC84A5D1E32269828F36410F4AA199E91551319E0C71080E78AC`; sizes/lines were 14,951/475 and 1,619/45. Semantic topology was unchanged from command 18080.
- `000000018113` at `2026-07-26T07:42:27-04:00`: dated supervisor read-only checkpoint, not run by B003. CPP SHA256 `AD2C2E3C2C70CDA4D82B2D1CEAF81AFA8073394EAF36A3484C74FB829DB26836`, 14,951 bytes, 475 lines; H SHA256 `8197D6EF2C1007C2FE3FDF99A82A7698519023EA97308B89A1D658DAAB98E70F`, 1,619 bytes, 45 lines. Semantic topology remained accepted.
- `000000018124` through `000000018147`: supervisor Gate2A scoped validator confirmation batch; every command exited `0` with `ok:1`. Some duplicate confirmations resulted from draining the original serial loop and were harmless. Gate2A passed every accepted ordinary-document claim.
- `000000018148`: foreground generated refresh completed. Current `CreateUserDialogPane.cpp` SHA256 `D44A4F6723783F59AF0813C9E779C551A753BB6F134E9F415D4AAFEF3BFF927A`, 14,949 bytes, 475 lines; current H SHA256 `AE502FE13F5671A6BFEB272080000C47EC1ECA4AA37FB45F61E5D355DE90BFAF`, 1,617 bytes, 45 lines. Accepted body topology is unchanged from command 18113; only refresh metadata changed.
- No validator or lifecycle command was run by B003 during this final same-report reconciliation. No `execute_report`, broad remove-missing command, manual coverage edit, or B003 IDA mutation occurred.

## Changed Files

- Created [UID:0004Y3] `by-global/g_pCreateUserDialogPane.md`.
- Updated `by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md` (UID0002B3).
- Updated `by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md` (UID0002SI).
- Updated `by-class/CreateUserDialogPane.md` (UID00003B).
- Updated `by-file/CreateUserDialogPane.md` (UID0000IJ).
- Updated `by-memory/0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor.md` (UID00046E).
- Updated `by-memory/0x0052e6f0-0x0052e72a.CreateUserDialogPaneConstructorCleanupRaw.md` (UID00046F).
- Updated `by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md` (UID0002QT).
- Updated `by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md` (UID0002QU).
- Updated `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md` (UID00025Z).
- Read-only verified UID00046Q, UID00046R, UID00046S, and UID00046T; none had a concrete stale Singleton/vtable/source-route contradiction, so none was edited or validated.
- Dated validator commands 18080, 18087, and 18113 refreshed generated artifacts historically; B003 did not edit those files manually.
- Supervisor Gate2A commands 18124-18147 validated the accepted ordinary scope, and foreground command 18148 refreshed generated CPP/H to the final pre-execution identity. These are supervisor/validator-owned artifacts, not B003 edits during this reconciliation.
- Supervisor Gate2B changed the IDB under the recorded pre-mutation backup, saved hash, and catalog entry 0331. B003 did not mutate or save IDA.
- Updated only this same report for final current-state reconciliation. Ordinary/support docs, coverage, generated files, audit/catalog/lifecycle files, goal/notes/assignments, validator state, and IDA were not changed by B003 in this callback.

## Implementation Tracking Checklist

Initial report-only pass and ordinary implementation callback:

- [x] Read complete updated B003 goal, project skill, references, and literal report template.
- [x] Record exact primary/additional UID provenance and declare UID0002SI only after fully covering it.
- [x] Read primary target, additional target, direct class/file, exact constructor/lifecycle/method support, sibling precedents, generated output, tracker, and manual coverage read-only.
- [x] Search/open/reconcile prior direct and sibling reports without deleting valid detail.
- [x] Complete healthy live IDA MCP read-only storage/xref/function/vtable/RTTI/type/comment/collision evidence.
- [x] Resolve stale all-ones initializer through exact PE raw/virtual section proof.
- [x] Resolve pointer type, source name, linkage, initializer, direct Singleton base, EBO overlap, lifetime, source placement, and one-definition policy.
- [x] Complete exact UID0002SI 36-slot/three-COL inventory, lifecycle refs, and predecessor/successor boundary proof.
- [x] Produce atomic claim/incorporation ledger and exact target/support destination plan.
- [x] Produce destination-ready CPP/H with class code in H and physical/compiler formals blank.
- [x] Produce exact score/metadata plan and exact supervisor-owned coverage rows.
- [x] Produce exact IDA Gate2B prestate/action/collision/type-dependency/comment/readback plan.
- [x] Record planned ordinary callback validators and generated acceptance without running them.
- [x] Supervisor validated exact Gate 1 SHA256 `6AAFAE4574E2512AAE1D233C20AD5467DD3073DC70AB90CA7DA0972F57DB085D`.
- [x] Supervisor Gate2B applied/read back I01-I13, restored exact I07 type, preserved the existing UDT, saved IDB SHA256 `9B1382E39799069EE002B70919732CE6EBE4E8800B1CA43BF4B4989B7B92C3CB`, and cataloged entry 0331.
- [x] B003 received the implementation callback for this same accepted report.
- [x] Created/validated semantic UID0004Y3 first and replaced every provisional UID reference.
- [x] Applied UID0002B3 physical false/non-emitting metadata/prose/history.
- [x] Applied UID0002SI compiler false/non-emitting metadata/full vtable evidence/history.
- [x] Applied UID00003B H/CPP/direct-Singleton/extern/layout/source changes.
- [x] Applied UID00046E exact constructor source correction.
- [x] Applied UID00046F, UID0002QT, UID0002QU, and UID00025Z support claims without score/route changes or detail loss.
- [x] Read-only verified UID00046Q/R/S/T and found no concrete stale contradiction requiring edit.
- [x] Ran serial scoped validators for every ordinary page actually created/changed.
- [x] Ran documented autogen command 18080 during the historical callback and verified its then-current CPP/H plus target marker topology.
- [x] Reconciled the same report to dated supervisor command 18087 CPP/H hashes and unchanged semantic topology without running a validator or editing generated files.
- [x] Reconciled the same report to dated supervisor checkpoint command 18113 CPP/H hashes and unchanged semantic topology without running a validator or editing generated files.
- [x] Reconciled report current state, UID, hashes, ledger, changed files, validator results, and checklist after callback.
- [x] Supervisor Gate2A verified ordinary implementation claim-by-claim; scoped commands 18124-18147 all exited `0`/`ok:1`, including harmless duplicate confirmations from the drained serial loop.
- [x] Supervisor foreground generated refresh command 18148 completed and current CPP/H hashes/topology were reconciled.
- [x] Reconciled this same report to final pre-execution ordinary, Gate2A, generated, Gate2B, saved-IDB, and catalog truth.
- [ ] Supervisor performs fresh final exact-artifact Gate 1 on this reconciled report.
- [ ] Supervisor alone issues `execute_report` and archives the report after Gate 1 passes.
- [ ] Supervisor applies the exact manual coverage rows and runs coverage validation after execution.
- [ ] Supervisor performs the post-archive exact-artifact audit.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"additional_uids":["0002SI"],"agent":"B003","command_id":"000000018156","destination_path":"executed-b-agent-research/B003/0002B3-CreateUserDialogPaneSingletonSlot-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002B3-CreateUserDialogPaneSingletonSlot-empty-emitter-source-quality.md","timestamp":"2026-07-28T12:52:44-04:00","uid":"0002B3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
