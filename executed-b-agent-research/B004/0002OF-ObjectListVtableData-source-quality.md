** TARGET-REPORT-UID:0002OF **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002OF ObjectList Vtable Data Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0002OF] as the exact reconstructable `source-declared/generated-binary` representation of the `ObjectList` RTTI-complete-object-locator pointer and three-slot primary vtable at `[0x00620284,0x00620294)`, owned and emitted through [UID:00009Q] `by-class/ObjectList.md` into [UID:0000M4] `by-file/ObjectList.md`.
- Final disposition: do not hand-author a vtable array. Normalize the target CPP channel to the exact covered-by marker `// Emitted code for this range is covered by [UID:00009Q].`; keep the target H channel blank because this binary range has no independent source declaration. Move the complete human-written `ObjectList` declaration from the class CPP channel into a complete guarded H channel and reduce the class CPP channel to `#include "ObjectList.h"` plus `[[CHILDREN]]`.
- Ordinary callback and supervisor closure state: the exact range, RTTI, hierarchy, slots, lifecycle, source placement, negative evidence, formal source, score, and history findings are incorporated across all seven authorized destinations and serially validated from physical readback. Supervisor Gate 2B applied and verified all thirteen IDA actions at the dated DADC save checkpoint, applied exact manual operations M01-M05, retained N01-N02 unchanged, and validated all four affected manual coverage files with commands20019-20022. After the unrelated accepted UID0004EO-only save advanced the shared IDB to `DAA59745...2C17`, a fresh bounded read-only target/dependency/protected-state pass found no UID0002OF drift. Remaining actions are fresh supervisor Gate 1, final Gate 2 currentness verification, generated/currentness closure as needed, and supervisor-owned lifecycle execution/archive.
- Confidence: very strong. Binary identity, range, RTTI hierarchy, slot meanings, constructor/destructor vptr stores, scalar-wrapper behavior, and owner route are direct facts. Original private identifier spelling remains inferred, but no compiler/decompiler label is proposed for final source.

## Supporting Research

- Report-only research used live read-only IDA MCP endpoint `http://127.0.0.1:13337/mcp`, original protocol session `7bde3c5a-a0a2-4230-bffe-9d35d5397105`, D7D29 reconciliation session `903bc963-2dbd-4fb8-97f2-ec2b6073212e`, and 836A reconciliation session `f74ea6e0-0184-4ddc-bcfb-18683fc0ffd8`; the earlier active database/session identity `1da2b2ae` is historical. Those bounded sessions returned `status:"ok"`, module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, strings cache ready, and `auto_analysis_ready:false`; every bounded target query remained stable and successful. Supervisor Gate 2B and the current DAA597 no-drift reread used healthy current session `07b29e1b` with IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Current shared-IDB authority at this reconciliation: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `DAA597458433CFB4230D3EE96AA0BCE8683FEFB5CDD6D88E22B33D1687462C17`, 143,192,163 bytes, saved `2026-07-30T12:47:29.2294093-04:00`, session `07b29e1b`. This identity includes accepted unrelated UID0004EO-only Gate 2B work; B004 neither repeated nor altered that work. Fresh bounded readback under DAA597 verified the exact UID0002OF poststate and all declared protected dependencies unchanged.
- Dated UID0002OF supervisor Gate 2B save checkpoint: after a controlled restore/restart removed an unsafe duplicate-frame experiment, `idb_save` returned `ok:true` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; historical SHA256 `DADC487F51F66A37C85D62C994F49C545E170AB2F18061AEEDC679828967C6A4`, 143,192,050 bytes, last write `2026-07-30T12:33:26.5781084-04:00`. The byte-identical prestate backup is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0002OF-prestate-20260730-122729`, SHA256 `836ABCFA986AF47A3CAC9EC1D46A31BE6B9B29DA83B6BCA797E7817F2CCF489F`.
- Dated historical checkpoints remain: D7D29 SHA256 `D7D29DEB8CDA07A6693B36BEF32A544ABD1921D3A0C9B306A47DFCC350D08CCA`, 143,194,156 bytes, last write `2026-07-30T15:35:19.0223971Z`; final pre-callback `3892BDA899A18612985539399C9AC1C97B5AE6F7F9FD5D1DF2859C96472798D1`, 143,194,020 bytes, last write `2026-07-30T10:38:13.8949946-04:00`; assignment checkpoint `4EDEC1553CDF85F5EDE5F40475BACA27EE26B3538E22313CED616FE3A4B5D09F`, 143,194,010 bytes, saved `2026-07-30T09:56:01.8527844-04:00`. These hashes are dated evidence provenance rather than permanent global-current assertions.
- The 836A prestate byte reread returned `B4 CC 64 00 90 72 53 00 10 4B 4F 00 C0 B6 41 00`, matching the earlier evidence pass and SHA256 `0185B14135A28B9F2A66A7A9B1CD92708552A7AE4346769D5678477A166DDC2E` for the exact 16-byte target. Supervisor post-action readback preserved those bytes, widths, values, item boundaries, and xrefs exactly.
- Existing reports reviewed for non-loss support evidence: `executed-b-agent-research/B001/000260-ObjectPaneReadOnlyData.md`, `B003/0001D4-ObjectListScalarDeletingDestructor-source-quality.md`, `B005/0001D1-ObjectListLifecycle-source-quality.md`, `B008/0000M4-ObjectList-empty-emitter-family-source-quality.md`, and `B002/0002BB-ObjectListTypeSpecificEncodedKeyLookupHelpers-source-quality.md`. They support the family route but do not directly cover UID0002OF.
- Historical assumptions retained and corrected: `0x00620280` is not a separate terminal `0x44` dword; it is the final UTF-16 `D` plus terminator within `L"DLGEXC3.EPD"`. Historical `sub_4F4B10` and `nullsub_18` labels are superseded by `LObject__GetRuntimeClass` and `LObject__OnChangeMessage`. The existing custom vtable comment is valid in concept but not the validator's exact covered-by form.

Report-time ordinary/generated artifact inventory:

| UID / artifact | Path | SHA256 | Bytes / lines |
| --- | --- | --- | --- |
| 0002OF | `by-memory/0x00620284-0x00620294.ObjectListVtableData.md` | `8EE44AF99949978BA34229A5C3B281C39520D7A88B817536BA85176E42FB4293` | 8,387 / 90 |
| 00009Q | `by-class/ObjectList.md` | `816C7DDB9AED677CD6C6CCB0BC0A9AA2BABBFC2122AA19722F87CB4FBB4FDAB1` | 53,742 / 373 |
| 0000M4 | `by-file/ObjectList.md` | `901DE1AA6201D8EC1842BC1213C7D5646ACCD5A46AE9F6F2FF05DBF7771B00E1` | 52,729 / 298 |
| 0001YB | `by-type/by-vtable/ObjectList_vtable.md` | `F05ED7D10777502FE40FBB45CD796190537750F6D053AB79AC0A3934AF52018A` | 8,363 / 100 |
| 0001VG | `by-type/by-struct/ObjectListLayout.md` | `4F29F5F1EA16F609616C0931F59611971034C0423BE3DD517822FBC0E7B92C07` | 24,510 / 219 |
| 0001D4 | `by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md` | `227A5C5C6AC4DDD7C4593AF7DB65206D8330BB2A9EF64579534E0B595433F442` | 14,092 / 151 |
| 0002JS | `by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md` | `8586CD7212342A1C16A06731395264B8BBD044545B48E1956B986F3E94CD4125` | 18,368 / 196 |
| 0002JT | `by-memory/0x00531260-0x00531473.ObjectListDestructor.md` | `8A67BDAC201A86DAE15FE1C6BB4C871544E3759AD9B2700ABF71F8DF2ED63FA8` | 18,205 / 217 |
| 0001D1 | `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md` | `71CD1FDE48F061EA36423D3A361D39E5CDE478F0D41CE223FF0C1FA8F595B0EC` | 20,123 / 146 |
| 000260 | `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md` | `909F6A7E1FC9C23E58A5791FCCFD1572DEDAD5791791DA680A35E43FA85343EC` | 34,403 / 156 |
| LObject support | `by-class/LObject.md` | `5A2FFB5C2491ACAD532AE94A20A51A3F40A3410EBA375EB3D173E50F0058538B` | 22,681 / 173 |
| LObject generated H | `auto-generated/NexusTK/util/LObject.h` | `48EBB0B4DE0FB1768080EC6D7812D43FE686F8753A63D1B0698F90FD5CB28D26` | 993 / 28 |
| ObjectList generated CPP | `auto-generated/NexusTK/map/ObjectList.cpp` | `262B93D950E3D1D2AAEA91D2984FFEE285586C5D75FF17459D66A801D867407A` | 30,650 / 951 |

Ordinary callback physical readback after final scoped validation:

| UID | Path | SHA256 | Bytes / lines | Callback disposition |
| --- | --- | --- | --- | --- |
| 0002OF | `by-memory/0x00620284-0x00620294.ObjectListVtableData.md` | `8D53EC966BBD914BD0BB725AAD19C3C368674B016376C14F56AFE496D3DF7F66` | 13,646 / 120 | applied `92/94`, exact class covered-by CPP, blank H |
| 00009Q | `by-class/ObjectList.md` | `59BB84F6E9B8C08AB546DF383FCB6807BD7CD68470132FD545F5E817337D91BB` | 55,700 / 389 | applied `92/93`, CPP include/children root, complete guarded H |
| 0000M4 | `by-file/ObjectList.md` | `0011A136D02C1715E6CC2AD9F41FB6E335FFE9706E562641A6C188A239F863D7` | 57,483 / 312 | applied `92/93`, prose-only H/CPP source-root topology |
| 0001YB | `by-type/by-vtable/ObjectList_vtable.md` | `DA52EF2C8D51E22485A98F8E30ED699727B39A2F3F2218D7E93C2A71AFED41D8` | 11,339 / 112 | applied `92/94`, exact vtable covered-by CPP, blank H |
| 0001D4 | `by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md` | `9986116E7FDDC9F0A692DB8DA2896932089A82130B0523F9D3711E8BF5B4BAEB` | 16,576 / 159 | applied `90/94`, exact wrapper covered-by CPP, blank H |
| 0001D1 | `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md` | `F2088A267E774A47C99DD7D1479F4D6C46054E9CB3CA1050E531D40DB64D1B53` | 24,429 / 161 | applied detail; retained `87/92` aggregate child route |
| 000260 | `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md` | `C3587F2E5A4370A6142662BBAFE1109125AD4C1F1F8F113D1A1670DAEC5677F1` | 36,501 / 163 | applied child detail; retained `90/92`, non-reconstructable/blank parent |

Inspect-only destinations remained byte-identical: UID0001VG SHA256 `4F29F5F1EA16F609616C0931F59611971034C0423BE3DD517822FBC0E7B92C07`, UID0002JS `8586CD7212342A1C16A06731395264B8BBD044545B48E1956B986F3E94CD4125`, and UID0002JT `8A67BDAC201A86DAE15FE1C6BB4C871544E3759AD9B2700ABF71F8DF2ED63FA8`; shared LObject pages were not edited. No contradiction required scope expansion.

Dated command19993 generated/tracker closure readback, refreshed `2026-07-30T11:58:57-04:00` from `foreground-generated-refresh`: `auto-generated/NexusTK/map/ObjectList.cpp` SHA256 `A14A9482BADE774DC75DAC4ED2F05FE51239E434994E830112E16AE468A1315E`, 28,465 bytes/886 lines; `ObjectList.h` SHA256 `04186AC4BC6743C2A2AE8C3385187AAE6B5A9A0D0D11408FF5A8259C81D36997`, 2,684 bytes/80 lines; `auto-generated/-ag-memory-coverage.md` SHA256 `4F54811E022C0EEED7E77BF85AFFBF36B25E7E97A41BD9E20878C148A4393C5F`, 1,420,185 bytes/4,950 lines. At that checkpoint CPP includes `ObjectList.h`, H contains the complete class and exact `FindStaticObjectPaneAt`, and CPP contains the UID0001D4/0002OF/0001YB covered-by routes. Commands20019-20022 deliberately skipped generated refresh, so they did not replace this semantic checkpoint; final global currentness remains a fresh supervisor readback concern.

## Target

- Target UID: `0002OF`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0002OF] `by-memory/0x00620284-0x00620294.ObjectListVtableData.md`, exact RTTI/COL-pointer and primary-vtable binary range.
- Target path: `by-memory/0x00620284-0x00620294.ObjectListVtableData.md`.
- Latest tracker authority established for this report before the supervisor Gate2B/manual transaction was `auto-generated/-ag-research-tracker.md` command `000000019993`, refreshed `2026-07-30T11:58:57-04:00`, SHA256 `69EEECA87A63E245662EAC7CE72D3EA46C0C41712DC513FE8F805AFBA19F76FA`, 1,679,725 bytes/6,634 lines. At that dated checkpoint UID0002OF is line3325 at `92/94`, reconstructable true, with zero direct/additional/total B reports (`0/0/0`). Commands20019-20022 skipped generated refresh and therefore did not supersede this semantic checkpoint. Command19933/SHA `A1FA9680D296AF86A2BDBB7C6994413256035E5292ADECB4FB42E985B04958D1` / 1,679,360 / 6,633 is earlier post-callback history; command19928 and its line1680 `85/92` state are pre-callback history; command19926/SHA `618A0280...E0` is earlier history. Physical global currentness is supervisor-owned moving state.
- Historical queue classification at report creation was new report-only research for a reconstructable, not-covered by-memory item. Current lifecycle truth remains authoritative only from the physical report path and validator-owned status/history metadata.
- Current ordinary metadata and parent state after callback: target `92/94`; `CANONICAL_OWNER:00009Q`; `EMITTER_UIDS:00009Q`; `RECONSTRUCTABLE:TRUE`; blank position; `Nested:4`.

## Current Target State

- Current target metadata is `92/94`, owner/emitter [UID:00009Q], reconstructable true, and no position override; the score and route changes were confirmed after validator command `000000019949`.
- Current target CPP is the validator-normalized linked form of the exact generic UID00009Q covered-by marker; H remains blank. The earlier custom marker is preserved as historical pre-callback state.
- Current Item Summary/prose now include exact direct inheritance, predecessor correction, canonical inherited slots, source/header topology, scalar-wrapper/lifecycle evidence, negative evidence, and the literal IDA handoff with saved applied/readback disposition.
- The separate-terminal-`0x44`, `sub_4F4B10`, and `nullsub_18` assumptions remain in history with explicit rejection. Current prose uses the complete `L"DLGEXC3.EPD"` predecessor and canonical LObject method names.
- Related target/support docs checked: UID00009Q class, UID0000M4 file, UID0001YB vtable summary, UID0001VG layout, UID0001D4 scalar wrapper, UID0002JS constructor, UID0002JT destructor, UID0001D1 lifecycle, UID000260 parent `.rdata` aggregate, and LObject class/generated header.
- Physical report lifecycle truth is authoritative only from this report's actual path and validator-owned status/history metadata. Report creation and the no-mutation research pass are historical facts; execution/archive state is supervisor-owned.
- Bounded pre-action reconciliation against saved-IDB checkpoint `836ABCFA...F489F` found no target-specific semantic drift. Supervisor Gate 2B then applied IDA-2OF-001..013 from that exact prestate, read back each intended name/prototype/comment/frame result and every protected dependency, and saved the dated UID0002OF transaction checkpoint as `DADC487F...C6A4` in session `07b29e1b`. After unrelated UID0004EO-only work advanced the save to current `DAA59745...2C17`, B004 re-read only the declared UID0002OF target/dependencies/protected entities and found the saved poststate unchanged.
- The pre-application filesystem pass after UID0003P4 insertion re-read every M01-M05/N01-N02 row and immediate anchor. Supervisor subsequently applied all five exact no-loss replacements, re-read and retained UID000260/UID0001VG unchanged, and validated the four modified manual coverage files with commands20019-20022. The literal prestate anchors and payloads remain below as historical transaction evidence.
- Command19993 generated closure was physically present and semantically correct at its dated checkpoint: ObjectList.cpp used the header route, ObjectList.h contained the complete declaration, and the three compiler-output pages emitted covered-by markers. Final global readback/refresh remains supervisor-owned.

## Executive Recommendation

- Direct source owner: [UID:00009Q] `ObjectList`, emitted under [UID:0000M4] `NexusTK/map/ObjectList.cpp` with a new generated `ObjectList.h` formal channel.
- The target remains a narrow by-memory binary-evidence page. It should not become a handwritten global array, a standalone source file, or an owned child with independent declarations.
- The recovered human source shape is `class ObjectList : public LObject` with a virtual destructor and inherited `GetRuntimeClass`/`OnChangeMessage` slots. The compiler emits the COL/vtable and scalar deleting destructor.
- Promote UID0002OF to `92/94`; promote the directly affected class/file/vtable/wrapper support scores as specified below. Retain owner, emitter, reconstructable, range, and nesting metadata.
- Supervisor Gate 1 accepted exact report SHA256 `44FE14660A54CB23443341D7438819DC883D890539FE875D31F034E7DE112466`, after which B004 completed the authorized ordinary callback. Supervisor then completed and saved Gate 2B IDA-2OF-001..013 and applied/validated M01-M05 while retaining N01-N02. Fresh report Gate 1/final Gate 2 currentness verification, generated closure if required, and lifecycle execution/archive remain supervisor-owned.

## Supervisor Active Recheck

- The current goal specifically requires deep RTTI/vtable bytes, slots, class declarations, owner/source route, and comment-marker versus blank policy analysis. Each is resolved below.
- No split repair is required: the target is exactly four dwords; predecessor and successor item boundaries prove both endpoints.
- Every source-bearing relation is assigned: the binary table routes to UID00009Q; the declaration belongs in UID00009Q H; definitions remain exact by-memory children; the source root is UID0000M4.
- No source-bearing child remains deferred. The only stripped-original uncertainty is private naming style, addressed with project-consistent descriptive identifiers and a confidence cap rather than raw labels.
- The 836A pre-Gate-2 recheck independently reconfirmed the four data-item prestates, three function names/declarations/comment channels/frames, proposed-name collision absence, UDT size/members, inherited shared-function state, and predecessor/successor fences. Supervisor post-action readback confirmed the accepted mutations and protected state at the dated DADC save; the current DAA597 reread reconfirmed those exact results after the unrelated UID0004EO-only save.

## Inference Research Guidance Check

- `by-structure.md` classifies vtables and compiler deleting wrappers as `source-declared/generated-binary`: recover the source declaration that causes them, but do not paste decompiler-shaped compiler output.
- Existing documentation was treated as evidence, not authority. The predecessor `0x44` statement, historical slot labels, CPP/H placement, and custom-marker policy were independently checked and corrected.
- Direct IDA facts: bytes, names, items, RTTI fields, hierarchy, vptr stores, function bounds, xrefs, frames, comments, and UDT members. Documentation facts: UID routes, metadata, formal channels, and generated topology. Inference: plausible header/source split, private identifier spelling, and source-facing class method names.
- No current Wave2/Wave3 requirement applies. Any such legacy mention is rejected as stale under the standing workflow rule.

## Heuristic / Inference Reanalysis And Validation

- Range role: the first dword is the MSVC complete-object-locator pointer immediately preceding the named primary vftable. Exact predecessor/successor item boundaries reject padding, mixed data, and a fourth slot.
- RTTI/type: the COL, type descriptor `.?AVObjectList@@`, two-base CHD, and PMD records prove `ObjectList` directly and singly derives from `LObject`; no secondary-base vtable exists.
- Slots: slot 0 is the compiler scalar deleting destructor; slot 1 is inherited `LObject::GetRuntimeClass`; slot 2 is inherited `LObject::OnChangeMessage`. The canonical names come from current IDA and class/interface evidence, not guessed `sub_` names.
- Lifecycle names/types: constructor vptr store and two MapPane callers support `ObjectList::ObjectList(int gridWidth, int gridHeight)`. Destructor/wrapper linkage supports ordinary `ObjectList::~ObjectList()` plus compiler wrapper. The proposed IDA names are descriptive, collision-free, and source-consistent.
- Fields: UDT ordinal 619, size `0x44`, exact constructor stores, and family docs support `m_minX`, `m_minY`, `m_gridWidth`, `m_gridHeight`, then semantic `List`/row-list fields. Raw `_DWORD`/`void *` labels are not final source names.
- Source placement: map subsystem callers, class/file routes, and current generated path support `NexusTK/map/ObjectList.h` and `.cpp`, not LObject, ObjectPane, a generic compiler-artifact file, or the broad `.rdata` aggregate.
- Comment-marker policy: blank CPP would create an empty-emitter defect and lose intentional duplicate-coverage identity; a custom prose marker is semantically right but noncanonical. The exact `// Emitted code for this range is covered by [UID:00009Q].` marker is the deterministic policy-compliant result.
- Class formal topology: declarations in the current CPP block produce a source file that looks reverse-engineered and leave no header. A normal mid-2000s C++ project would put the guarded class declaration in `ObjectList.h` and definitions/children in `ObjectList.cpp`.
- Rejected alternatives: handwritten vtable array; blank target CPP; separate vtable source file; complete invented LObject IDA UDT; renaming inherited shared functions; treating `0x620294` as a fourth slot; retaining `nullsub_18`; and keeping the class declaration in CPP.
- No material heuristic blocker remains. Original private name spelling cannot be recovered literally, but project-wide semantic names are more plausible than IDA labels and preserve exact execution.

## Evidence Standards Used

- Evidence types: live MCP health, bytes, item boundaries, names/types/comments, integer dwords, RTTI descriptors, hierarchy records, function lookup/decompile/disassembly, frame layouts, constructor/destructor vptr stores, xrefs, collision checks, UDT inspection, adjacent data, generated output, manual coverage, by-* docs, and executed family reports.
- The strongest chain is binary: exact bytes -> decorated COL/type/CHD -> direct LObject hierarchy -> three function pointers -> lifecycle vptr stores -> scalar-wrapper call -> class/source route.
- Confidence is not 100 because original source-private identifiers and exact historical include-guard spelling are stripped. That does not justify raw labels or compiler arrays in source.
- `auto_analysis_ready:false` is recorded as a tool-state limitation; targeted results were stable, internally cross-checked, and corroborated by bytes/docs.

## Evidence Checked

- IDA MCP checks: `server_health`; bounded `get_bytes`; item/name/type/comment queries for `0x62026c-0x620298`; COL/type/CHD/base descriptors; slot function bounds/declarations/comments/xrefs; constructor/destructor/wrapper decompile, disassembly, frames, callers/callees, vptr stores; UDT ordinal 619; name-collision queries.
- Documentation checked: all target/support by-* pages listed above, command19993 ObjectList generated CPP/H, current LObject H, command19993 research tracker/ag-memory report, all five relevant manual coverage files with exact pre-application anchors and payloads, and five prior ObjectList-family B reports. Supervisor application/readback plus commands20019-20022 close the manual operations without making those dated anchor lines permanent current-state claims.
- Negative checks: no fourth slot; no secondary base; no direct wrapper caller; no independent source vtable; no source declaration for the target range; no proposed-name collisions; no reason to mutate inherited shared functions; no separate `0x620280` item.
- Failed/unavailable checks: no required MCP query failed. Original PDB/source files are unavailable; exact private spelling and historical guard macro therefore remain inference rather than proof.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0002OF | Range is exactly `[0x00620284,0x00620294)` with four exact dwords and byte SHA256 `0185B141...DDC2E`. | very strong | live bytes/items | `by-memory/0x00620284-0x00620294.ObjectListVtableData.md` / Range, IDA Evidence | incorporate | applied |
| C02 | 0002OF | `0x620280` belongs to predecessor UTF-16 `L"DLGEXC3.EPD"`; the separate-terminal-`0x44` claim is stale. | very strong | predecessor item `[0x62026c,0x620284)` | target / Summary, historical assumptions | historicalize | applied |
| C03 | 0002OF | Successor `0x620294` is ObjectPane COL and exact exclusive boundary. | very strong | item/value/name readback | target / Vtable Layout | incorporate | applied |
| C04 | 0002OF | COL/type/CHD/base descriptors prove direct single `ObjectList : LObject`. | very strong | decorated RTTI records | target / RTTI Hierarchy | incorporate | applied |
| C05 | 0002OF | Slots are scalar deleting destructor, inherited GetRuntimeClass, inherited OnChangeMessage. | very strong | pointers/functions/xrefs | target / Vtable Layout | incorporate | applied |
| C06 | 0002OF | Constructor writes vptr at `0x530f19`. | very strong | disassembly/xref | target / Lifecycle Evidence | incorporate | applied |
| C07 | 0002OF | Destructor writes vptr at `0x531288`. | very strong | disassembly/xref | target / Lifecycle Evidence | incorporate | applied |
| C08 | 0002OF | Scalar wrapper is vtable-only, calls ordinary destructor, handles flags, and returns this. | very strong | wrapper disassembly/xrefs | target / Lifecycle Evidence | incorporate | applied |
| C09 | 0002OF | Classification remains reconstructable source-declared/generated-binary. | very strong | by-structure policy/binary role | target / Range, Reconstruction Notes | incorporate | applied |
| C10 | 0002OF | Owner/emitter remains UID00009Q and source root UID0000M4. | very strong | class/file/lifecycle route | target / metadata, Assignment Gate | already-present | already-present |
| C11 | 0002OF | Score becomes `92/94`. | strong | blocker-resolution pass | target / metadata, Score Rationale | incorporate | applied |
| C12 | 0002OF | Item Summary becomes exact no-duplicate source-quality summary. | strong | complete report evidence | target / Item Summary | incorporate | applied |
| C13 | 0002OF | CPP becomes exact covered-by UID00009Q marker. | very strong | duplicate-emitter policy | target / RECONSTRUCTION_CPP CODE | incorporate | applied |
| C14 | 0002OF | H remains blank because range has no independent declaration. | very strong | compiler-artifact classification | target / RECONSTRUCTION_H CODE | already-present | already-present |
| C15 | 0002OF | Historical raw labels/custom marker/old boundary claims remain documented as superseded. | strong | current vs historical comparison | target / Changes | historicalize | applied |
| C16 | 0002OF | IDA-2OF-001 exact COL-cell repeatable comment was applied, read back literally, and saved at dated DADC; current DAA597 reread confirms name/type/width/value/bounds and the comment remain exact. | very strong | exact prestate, supervisor session07b29e1b DADC transaction, current DAA597 no-drift readback | target / IDA handoff | incorporate | applied |
| C17 | 0002OF | IDA-2OF-002 exact slot-0 repeatable comment was applied, read back literally, and saved at dated DADC; current DAA597 reread confirms the compiler name/type/width/value/bounds and comment remain exact. | very strong | exact prestate, supervisor session07b29e1b DADC transaction, current DAA597 no-drift readback | target / IDA handoff | incorporate | applied |
| C18 | 0002OF | IDA-2OF-003 exact slot-1 repeatable comment was applied, read back literally, and saved at dated DADC; current DAA597 reread confirms name/type/width/value/bounds and the comment remain exact. | very strong | exact prestate, supervisor session07b29e1b DADC transaction, current DAA597 no-drift readback | target / IDA handoff | incorporate | applied |
| C19 | 0002OF | IDA-2OF-004 exact slot-2 repeatable comment was applied, read back literally, and saved at dated DADC; current DAA597 reread confirms name/type/width/value/bounds and the comment remain exact. | very strong | exact prestate, supervisor session07b29e1b DADC transaction, current DAA597 no-drift readback | target / IDA handoff | incorporate | applied |
| C20 | 00009Q | Class inherits LObject and declares virtual destructor/source virtual surface. | very strong | RTTI/vtable/class docs | `by-class/ObjectList.md` / declaration/status | incorporate | applied |
| C21 | 00009Q | CPP becomes `#include "ObjectList.h"` plus `[[CHILDREN]]`. | strong | human source topology | class / RECONSTRUCTION_CPP CODE | incorporate | applied |
| C22 | 00009Q | H becomes exact complete guarded ObjectList declaration. | strong | current declaration/layout/generated headers | class / RECONSTRUCTION_H CODE | incorporate | applied |
| C23 | 00009Q | Class score becomes `92/93`. | strong | header-channel blocker removed | class / metadata/score | incorporate | applied |
| C24 | 00009Q | Prose records generated-binary ownership and header/source topology. | strong | report synthesis | class / Status, Evidence, Changes | incorporate | applied |
| C25 | 00009Q | IDA-2OF-005 constructor rename was applied, read back, and durably saved. | strong | vptr/callers/collision check plus supervisor saved readback | class / IDA handoff | incorporate | applied |
| C26 | 00009Q | IDA-2OF-006 constructor prototype was applied and read back with `gridWidth`/`gridHeight` at `+0x34/+0x38` as IDA-rendered `signed __int32`. | strong | frame/stores/class layout plus supervisor saved readback | class / IDA handoff | incorporate | applied |
| C27 | 00009Q | IDA-2OF-007 exact constructor function-regular comment was applied, read back literally, and durably saved. | strong | exact lifecycle behavior plus supervisor saved readback | class / IDA handoff | incorporate | applied |
| C28 | 00009Q | IDA-2OF-008 ordinary-destructor rename was applied, read back, and durably saved. | very strong | wrapper call/vptr store plus supervisor saved readback | class / IDA handoff | incorporate | applied |
| C29 | 00009Q | IDA-2OF-009 ordinary-destructor prototype was applied and read back with protected bounds/callers/frame state. | very strong | decompile/frame plus supervisor saved readback | class / IDA handoff | incorporate | applied |
| C30 | 00009Q | IDA-2OF-010 exact destructor function-regular comment was applied, read back literally, and durably saved. | strong | cleanup behavior plus supervisor saved readback | class / IDA handoff | incorporate | applied |
| C31 | 0001D4 | Wrapper behavior/source-generated disposition is fully documented. | very strong | live wrapper analysis | `by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md` / Behavior | incorporate | applied |
| C32 | 0001D4 | Wrapper score becomes `90/94`. | strong | exact ABI/owner/no-code resolution | scalar page / metadata/Score | incorporate | applied |
| C33 | 0001D4 | CPP becomes exact covered-by UID00009Q marker. | very strong | compiler-wrapper policy | scalar page / RECONSTRUCTION_CPP CODE | incorporate | applied |
| C34 | 0001D4 | H remains blank because the wrapper has no source declaration. | very strong | compiler-wrapper policy | scalar page / RECONSTRUCTION_H CODE | already-present | already-present |
| C35 | 0001D4 | Item Summary and prose reject "final C++ blank" wording. | strong | marker policy | scalar page / Item Summary/Reconstruction Notes | incorporate | applied |
| C36 | 0001D4 | IDA-2OF-011 scalar-wrapper rename was applied, read back, and durably saved. | very strong | vtable-only function/collision check plus supervisor saved readback | scalar page / IDA handoff | incorporate | applied |
| C37 | 0001D4 | IDA-2OF-012 exact wrapper prototype was applied and read back with `deleteFlags +0xc/4 unsigned int`. | very strong | wrapper ABI/frame plus supervisor saved readback | scalar page / IDA handoff | incorporate | applied |
| C38 | 0001D4 | IDA-2OF-013 exact wrapper function-regular comment was applied, read back literally, and durably saved. | strong | exact compiler behavior plus supervisor saved readback | scalar page / IDA handoff | incorporate | applied |
| C39 | 0001YB | Vtable page gains exact RTTI hierarchy/slot identities. | very strong | direct binary evidence | `by-type/by-vtable/ObjectList_vtable.md` / Slots/Evidence | incorporate | applied |
| C40 | 0001YB | Vtable score becomes `92/94`. | strong | blockers resolved | vtable page / metadata/status | incorporate | applied |
| C41 | 0001YB | CPP becomes exact covered-by UID00009Q marker. | very strong | duplicate-emitter policy | vtable page / RECONSTRUCTION_CPP CODE | incorporate | applied |
| C42 | 0001YB | H remains blank because the vtable has no source declaration independent of UID00009Q. | very strong | duplicate-emitter policy | vtable page / RECONSTRUCTION_H CODE | already-present | already-present |
| C43 | 0001YB | Historical helper labels are replaced by canonical inherited names in current prose. | very strong | current IDA identities | vtable page / Slots/Changes | historicalize | applied |
| C44 | 0000M4 | Source route is `NexusTK/map/ObjectList.h` plus `.cpp`. | strong | subsystem/caller/class evidence | `by-file/ObjectList.md` / Header And Source Placement | incorporate | applied |
| C45 | 0000M4 | File page records declaration-in-H and definitions/children-in-CPP topology. | strong | formal channel audit | file / File Role/Source-Structure Decision | incorporate | applied |
| C46 | 0000M4 | File score becomes `92/93`. | strong | topology blocker removed | file / Status/Assignment Gate | incorporate | applied |
| C47 | 0000M4 | Generated command19926 CPP-only/absent-H baseline is dated history; command19993 now physically confirms ObjectList.h plus header-routed CPP and covered-by children. | very strong | command19926 historical and command19993 current physical generated files | `by-file/ObjectList.md` / Generated Output Audit | incorporate | applied |
| C48 | 0001VG | Existing size `0x44`/17-member UDT and class-field marker remain correct. | very strong | UDT/readback/layout page | `by-type/by-struct/ObjectListLayout.md` / Layout/status | already-present | already-present |
| C49 | 0001VG | Layout score `92/94` and coverage row remain unchanged. | strong | no remaining target-specific defect | layout / metadata/coverage | already-present | already-present |
| C50 | 0002JS | Existing formal constructor body remains the source definition. | very strong | constructor analysis/current formal | `by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md` / formal/behavior | already-present | already-present |
| C51 | 0002JT | Existing formal ordinary-destructor body remains the source definition. | very strong | destructor analysis/current formal | `by-memory/0x00531260-0x00531473.ObjectListDestructor.md` / formal/behavior | already-present | already-present |
| C52 | 0001D1 | Lifecycle aggregate route remains correct and gains current naming cross-reference only. | strong | ctor/dtor/wrapper synthesis | `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md` / inventory/history | incorporate | applied |
| C53 | 00009Q | Inherited GetRuntimeClass identity/comment is protected unchanged. | very strong | 489 refs/shared LObject slot | `by-class/ObjectList.md` / inherited virtual evidence | already-present | already-present |
| C54 | 00009Q | Inherited OnChangeMessage identity/comment is protected unchanged. | very strong | 517 refs/shared LObject slot | class / inherited virtual evidence | already-present | already-present |
| C55 | 000260 | Parent aggregate child row gains exact target detail. | strong | exact child evidence | `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md` / child inventory | incorporate | applied |
| C56 | 000260 | Parent remains `90/92`, non-reconstructable, parent-blank/non-emitting. | strong | mixed `.rdata` ownership | parent / metadata/status | already-present | already-present |
| C57 | 0002OF | Supervisor applied exact M01 target manual by-memory replacement at the verified UID000260/UID0002SK anchor and command20019 validated it. | strong | exact prestate/anchors, literal payload, supervisor application, command20019 | `by-memory/-coverage-report.md` / UID0002OF row | incorporate | applied |
| C58 | 0001D4 | Supervisor applied exact no-loss M02 scalar-wrapper merge preserving the `0x38` boundary, `0x00620288` vtable xref, constructor/destructor vptr writes, destructor delegation, explicit OperatorDeleteWrapper route, `0x44` guard, padding, and class attachment while adding exact compiler-wrapper ABI/covered-by/no-handwritten-emission conclusions; command20019 validated it. | strong | exact prestate/padding anchors, literal payload, supervisor application, command20019 | `by-memory/-coverage-report.md` / UID0001D4 row | incorporate | applied |
| C59 | 00009Q | Supervisor applied exact no-loss M03 class merge preserving the complete LObject-derived `0x44` declaration, semantic storage, lifecycle/dispatch/accessor/private-key methods, exact `FindStaticObjectPaneAt` spelling, child-only definitions, and compiler exclusions while adding guarded-H and RTTI/vtable-owner conclusions; command20020 validated it. | strong | exact prestate/anchors, literal payload, supervisor application, command20020 | `by-class/-coverage-report.md` / UID00009Q row | incorporate | applied |
| C60 | 0000M4 | Supervisor applied exact no-loss M04 file merge preserving the complete declaration, semantic storage taxonomy, lifecycle/dispatch/accessor/private-key methods, exact `FindStaticObjectPaneAt` child, remaining helper splits, child-only emission, and compiler exclusions while adding the H/CPP split and compiler-regeneration conclusions; command20021 validated it. | strong | exact prestate/anchors, literal payload, supervisor application, command20021 | `by-file/-coverage-report.md` / UID0000M4 row | incorporate | applied |
| C61 | 0001YB | Supervisor applied exact no-loss M05 vtable merge preserving UID00009Q parent/UID0000M4 file attachment, prior gate history, RTTI pointer, three slots, exact constructor/destructor stores, scalar-wrapper data reference, child range, and adjacent ObjectPane boundary while adding exact COL/hierarchy/slot/fence/covered-by conclusions; command20022 validated it. | strong | exact prestate/anchors, literal payload, supervisor application, command20022 | `by-type/by-vtable/-coverage-report.md` / UID0001YB row | incorporate | applied |
| C62 | 000260 | Supervisor re-read N01 and retained the exact parent manual coverage row unchanged. | strong | exact prestate row/anchors plus supervisor no-op readback | `by-memory/-coverage-report.md` / UID000260 row | already-present | already-present |
| C63 | 0001VG | Supervisor re-read N02 and retained the exact layout manual coverage row unchanged. | strong | exact prestate row/anchors plus supervisor no-op readback | `by-type/by-struct/-coverage-report.md` / UID0001VG row | already-present | already-present |
| C64 | 0000M4 | Dated generated command19993 physically confirmed ObjectList.h, header-routed ObjectList.cpp, complete declaration/FindStaticObjectPaneAt, and UID0001D4/0002OF/0001YB covered-by children; command19926 is earlier baseline history and final global currentness is supervisor-owned. | very strong | exact command19993 generated CPP/H hashes/topology | `by-file/ObjectList.md` / Generated Output Audit | already-present | already-present |
| C65 | 0002OF | Dated tracker command19993 line3325 reported `92/94`, reconstructable true, and direct/additional/total coverage `0/0/0`; commands20019-20022 skipped generated refresh, and final moving-artifact currentness is supervisor-owned. | very strong | physical command19993 tracker readback plus manual-validator no-refresh results | `tools/leaser/Agents/Agent-B004/research/0002OF-ObjectListVtableData-source-quality.md` / Target | already-present | already-present |
| C66 | 0002OF | Live MCP evidence binds the original prestates, dated supervisor DADC application/save, and current DAA597 no-drift readback; all thirteen actions and protected boundaries remain exact after unrelated UID0004EO-only work. | very strong | health/bytes/items/functions/frames/comments/xrefs/types/collisions/prestate backup/DADC history/current DAA597 readback | `tools/leaser/Agents/Agent-B004/research/0002OF-ObjectListVtableData-source-quality.md` / Supporting Research and IDA MCP Facts | incorporate | applied |

## Positive Evidence Summary

- Exact decorated RTTI connects the binary table to `ObjectList`, and the CHD/base descriptors prove the direct `LObject` base.
- Constructor and destructor both store the exact vftable address; the scalar wrapper is referenced only by slot 0 and calls the ordinary destructor.
- Current class/layout/family pages independently agree on size `0x44`, virtual destructor ownership, semantic storage, and map source placement.
- Exact predecessor and successor items fence the range without padding or ambiguity.
- The inference chain from compiler data to human source is sufficient: `virtual ~ObjectList()` creates the deleting wrapper/slot; inherited LObject virtuals create slots 1-2; no array belongs in original source.

## IDA MCP Facts

- Function/range facts: target bytes are `B4 CC 64 00 90 72 53 00 10 4B 4F 00 C0 B6 41 00`; slots point to `[0x537290,0x5372c8)`, `[0x4f4b10,0x4f4b16)`, and `[0x41b6c0,0x41b6c3)`.
- Data/table facts: `0x620284 -> 0x64ccb4` COL, `0x620288 -> 0x537290`, `0x62028c -> 0x4f4b10`, `0x620290 -> 0x41b6c0`; each item is four bytes.
- COL `0x64ccb4` exact fields: signature `0`, offset `0`, constructor displacement `0`, type descriptor `0x67830c`, class hierarchy descriptor `0x64ccc8`.
- Type descriptor `0x67830c` is `??_R0?AVObjectList@@@8` with literal name `.?AVObjectList@@`.
- CHD `0x64ccc8` exact fields: signature `0`, attributes `0`, base count `2`, base array `0x64ccd8`.
- ObjectList base descriptor `0x64cce4` is `??_R1A@?0A@EA@ObjectList@@8`: type `0x67830c`, contained bases `1`, PMD `0/-1/0`, attributes `0x40`.
- LObject base descriptor `0x640348` is `??_R1A@?0A@EA@LObject@@8`: type `0x6738c0` / `??_R0?AVLObject@@@8`, contained bases `0`, PMD `0/-1/0`, attributes `0x40`.
- Xref facts: vptr stores at `0x530f19` and `0x531288`; scalar wrapper sole data xref from `0x620288`; constructor callers `0x50bc55` and `0x5106e2`; ordinary destructor sole caller `0x537296`.
- RTTI/type facts: type descriptor `.?AVObjectList@@`, two-base CHD, ObjectList PMD `0/-1/0`, LObject PMD `0/-1/0`, no secondary views. UDT ordinal 619 is size `0x44` with exact members `_lobjectBase +0x00 unsigned char[4]`, `m_minX +0x04 int`, `m_minY +0x08 int`, `m_gridWidth +0x0c int`, `m_gridHeight +0x10 int`, `m_itemObjects +0x14 List *`, `m_flyingObjects +0x18 List *`, `m_primaryEffectRows +0x1c List **`, `m_secondaryEffectRows +0x20 List **`, `m_livingObjectRows +0x24 List **`, `m_staticObjectRows +0x28 List **`, `m_balloonObjects +0x2c List *`, `m_hitBarObjects +0x30 List *`, `m_damageNumberObjects +0x34 List *`, `m_objectInfoObjects +0x38 List *`, `m_lightingObjects +0x3c List *`, and `m_soundObjects +0x40 List *`.
- Negative IDA facts: no fourth slot, no secondary base, no direct scalar-wrapper caller, no proposed-name collision, and no target item type/comment prestate that must be overwritten.
- 836A pre-action reconciliation: protocol session `f74ea6e0-0184-4ddc-bcfb-18683fc0ffd8` re-read all four data items and comments, all three actionable function identities/prototypes/comments/frames, exact xrefs/callers, ObjectList UDT size/member layout, proposed-name collisions, COL state, inherited LObject functions, predecessor string, and successor ObjectPane COL/vtable. IDA-2OF-001..013 and every protected constraint matched the literal prestates below; D7D29 is retained only as dated history.
- Supervisor Gate 2B applied the accepted rows in restored-safe session `07b29e1b`. Exact post-action readback verified all four literal repeatable data comments, constructor/destructor/wrapper names and prototypes, all three literal function-regular comments, constructor `gridWidth`/`gridHeight` frame arguments at `+0x34/+0x38` as IDA-rendered `signed __int32`, wrapper `deleteFlags +0xc/4 unsigned int`, and every protected byte/range/value/xref/caller/nonargument-frame/dependency invariant. `idb_save` returned `ok:true`; dated UID0002OF save SHA256 is `DADC487F51F66A37C85D62C994F49C545E170AB2F18061AEEDC679828967C6A4`.
- Current DAA597 read-only no-drift pass in the same session reverified target bytes `B4 CC 64 00 90 72 53 00 10 4B 4F 00 C0 B6 41 00`; exact item boundaries/names/types/values; all four literal data comments; exact function bounds/names/prototypes/regular comments; constructor frame including `gridWidth`/`gridHeight` `signed __int32`; destructor protected frame including analysis-only `arg_4`; wrapper `deleteFlags unsigned int`; constructor callers, destructor sole caller, wrapper sole vtable xref; inherited slot functions; predecessor `aDlgexc3Epd`; successor ObjectPane COL/vtable; and ObjectList ordinal619, 17 members, size `0x44`. No UID0002OF semantic drift or collision was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00620284-0x00620294` | UID0002OF target | COL pointer plus primary vtable | true | UID00009Q | `85/92 -> 92/94` | exact target |
| `0x00530ee0-0x0053125d` | UID0002JS constructor | source constructor/vptr install | true | UID0001D1/00009Q | `90/92` | retain formal body |
| `0x00531260-0x00531473` | UID0002JT destructor | source ordinary destructor/vptr restore | true | UID0001D1/00009Q | `90/92` | retain formal body |
| `0x00537290-0x005372c8` | UID0001D4 wrapper | compiler scalar deleting destructor | true | UID00009Q | `86/92 -> 90/94` | marker only |
| `0x00620288` | UID0001YB vtable summary | type-level vtable evidence | true | UID00009Q | `85/91 -> 92/94` | marker only |
| `ObjectList` | UID00009Q class | source declaration/owner | true | UID0000M4 | `91/93 -> 92/93` | move declaration to H |
| `ObjectList` | UID0000M4 file | `map/ObjectList.h/.cpp` root | true | source tree | `91/93 -> 92/93` | synchronize topology |
| `0x00620284-0x00620c74` | UID000260 parent | mixed `.rdata` inventory | false | none | `90/92` | retain parent-blank |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x620288` | stores at `0x530f19`, `0x531288` | constructor/destructor install ObjectList vptr |
| `0x537290` | data xref only from `0x620288` | slot-0 compiler wrapper, no source caller |
| `0x537296` | calls `0x531260` | wrapper delegates to ordinary destructor |
| `0x4f4b10` | exact slot ref at `0x62028c`; 489 data refs total | inherited shared `LObject::GetRuntimeClass` |
| `0x41b6c0` | exact slot ref at `0x620290`; 517 data refs total | inherited shared `LObject::OnChangeMessage` |
| `0x530ee0` | callers `0x50bc55`, `0x5106e2` | MapPane constructs ObjectList with grid dimensions |
| `0x531260` | sole caller `0x537296` | ordinary destructor only reached by deleting wrapper in current binary |

## Documentation Evidence And IDA Status

- Supporting docs correctly establish class/file/layout/lifecycle ownership, exact three-slot shape, and no-handwritten-wrapper policy.
- Ordinary documentation now resolves the predecessor boundary, raw-label history, class declaration H placement, exact covered-by markers, scores, vtable/RTTI detail, source topology, and wrapper/lifecycle handoffs. Manual coverage remained supervisor-owned and was subsequently updated exactly through M01-M05, with N01-N02 retained unchanged and commands20019-20022 verifying the resulting files.
- Generated command `000000019993` is the dated semantic closure checkpoint established for this report: ObjectList.cpp SHA `A14A9482...15E` included `ObjectList.h` and covered-by children; ObjectList.h SHA `04186AC4...997` contained the complete class and exact `FindStaticObjectPaneAt`. Command19926's CPP-only/absent-H topology is earlier pre-callback history; final global generated identity is supervisor-owned moving state.
- Tracker command `000000019993` is the dated checkpoint established for this report: SHA256 `69EEECA87A63E245662EAC7CE72D3EA46C0C41712DC513FE8F805AFBA19F76FA`, 1,679,725 bytes/6,634 lines, with UID0002OF at line3325 as `92/94`, reconstructable true, `0/0/0`. Command19933 is earlier post-callback history; command19928 is pre-callback history; command19926 is earlier history. Commands20019-20022 deliberately skipped generated refresh. All generated/tracker identities are validator-owned moving artifacts rather than durable current or lifecycle assertions.
- IDA recommendations remain fully specified with literal historical prestates. Supervisor Gate 2B applied them in session `07b29e1b`, verified the exact poststates and protected constraints, and saved the dated UID0002OF transaction as `DADC487F...C6A4`. Current shared authority is `DAA59745...2C17`; bounded read-only reread found all UID0002OF poststates/protections unchanged after the unrelated UID0004EO-only save. B004 performed no IDA mutation or save.

## Ranked Ownership Analysis

### 1. UID00009Q ObjectList class

- Evidence for: decorated ObjectList RTTI, ObjectList constructor/destructor vptr stores, scalar wrapper from virtual destructor, direct LObject hierarchy, exact size/layout, existing owner/emitter metadata.
- Evidence against: none material; only original private spelling is stripped.
- Decision: direct owner and emitter.

### 2. UID0000M4 ObjectList source root

- Evidence for: map callers, existing route, generated path, full method family, plausible `ObjectList.h/.cpp` split.
- Evidence against: it is a file owner, not the direct class emitter for binary vtable data.
- Decision: retain as class parent/source root.

### 3. UID000260 ObjectPaneReadOnlyData parent

- Evidence for: physically contains this and neighboring RTTI/vtable data.
- Evidence against: mixed ObjectPane-family data with multiple source owners; intentionally non-reconstructable and non-emitting.
- Decision: inventory parent only, never source owner.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new by-file page; formal source topology is existing UID0000M4 as `NexusTK/map/ObjectList.h` and `.cpp`.
- Likely full contents: guarded class declaration in H; `#include "ObjectList.h"` and exact child definitions in CPP.
- Related items included: UID00009Q and method/lifecycle children already routed there.
- Rejected: compiler tables, RTTI descriptors, and deleting wrappers as hand-authored source.
- Inference: narrow conventional header/source split, strongly supported by existing generated project organization.

## Source Placement

- Recommended placement: `NexusTK/map/ObjectList.h` for declaration and `NexusTK/map/ObjectList.cpp` for method definitions/children.
- This matches map subsystem callers, current UID0000M4 route, neighboring ObjectPane source family, and the human-written class abstraction that generates the binary table.
- Rejected placements: `LObject` (base/shared slots only), `ObjectPane` (successor class), broad `.rdata` parent (binary inventory), and compiler-artifact source file.
- Remaining uncertainty: exact original include-guard spelling is not recoverable; `NEXUSTK_MAP_OBJECTLIST_H` is deterministic and project-consistent. This does not affect runtime behavior.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `[0x620284,0x620294)`, four aligned dwords, no padding.
- Predecessor `[0x62026c,0x620284)` is one `const wchar_t` item `L"DLGEXC3.EPD"`; do not split at `0x620280`.
- Successor starts at `0x620294` with ObjectPane COL and vtable at `0x620298`; do not merge it.
- Internal split is semantic only: COL pointer then three slots. No child by-memory pages are needed because one compiler-generated table and one source owner cover the exact range.
- Reclassification remains `vtable-data`, reconstructable, source-declared/generated-binary; no raw code/function promotion applies.

## Negative Evidence Summary

- No binary or source evidence supports a fourth ObjectList slot, multiple inheritance, secondary vtable, handwritten table array, separate compiler-artifact source file, or independent target H declaration.
- The large shared xref counts for slots 1-2 prove inherited shared defaults, not ObjectList ownership of those function bodies.
- The scalar wrapper has no direct code caller; that is expected for a vtable-only compiler helper and does not make it dead.
- The predecessor string and successor ObjectPane COL reject both historical boundary claims.
- An incomplete LObject IDA type does not justify inventing a complete base layout in IDA; preserve the protected current dependency.

## IDA Rename / Type / Comment Recommendations

Supervisor prerequisites and completed disposition: preserve bytes, item boundaries, pointer values, xrefs, decorated RTTI names, UDT ordinal 619/size `0x44`, inherited functions, predecessor string, successor ObjectPane data, and all nonargument frame entries. Every missing comment channel below is written literally as `absent`. Bounded read-only MCP reconciliation against prestate checkpoint `836ABCFA...F489F` matched every literal prestate in IDA-2OF-001..013. Supervisor session `07b29e1b` then applied each action, read back the exact poststate and protected invariants, and saved dated checkpoint `DADC487F...C6A4`; classifications below are therefore `applied_verified` while retaining each original prestate. Current shared checkpoint `DAA59745...2C17` was boundedly reread and preserves every listed poststate/protection exactly.

| ID | Exact entity/range | Literal current prestate | Classification and exact action | Evidence / confidence / constraints | Literal expected readback |
| --- | --- | --- | --- | --- | --- |
| IDA-2OF-001 | data item `[0x620284,0x620288)` | historical prestate: name absent; type absent; width 4; value `0x64ccb4`; address regular comment absent; address repeatable comment absent; function regular/repeatable comments not applicable | applied_verified: set address repeatable comment to `MSVC RTTI complete-object-locator pointer for ObjectList; the primary vftable begins at 0x00620288. Compiler-generated from the ObjectList class declaration.` | decorated COL/type/CHD, exact adjacency; very strong; do not rename/type/resize | saved readback: same name/type/width/value/boundaries; AR absent; AP exact literal; bytes/xrefs unchanged |
| IDA-2OF-002 | data item `[0x620288,0x62028c)` | historical prestate: name `??_7ObjectList@@6B@`; type absent; width 4; value `0x537290`; AR absent; AP absent; function comments not applicable | applied_verified: set AP to `ObjectList primary vftable slot 0: MSVC scalar deleting destructor at 0x00537290, generated from virtual ~ObjectList().` | decorated vftable, wrapper analysis; very strong; preserve compiler name | saved readback: same name/type/width/value/boundaries; AR absent; AP exact literal; bytes/xrefs unchanged |
| IDA-2OF-003 | data item `[0x62028c,0x620290)` | historical prestate: name absent; type absent; width 4; value `0x4f4b10`; AR absent; AP absent; function comments not applicable | applied_verified: set AP to `ObjectList primary vftable slot 1: inherited LObject::GetRuntimeClass at 0x004f4b10.` | canonical shared function/current declaration; very strong; do not rename/type data cell | saved readback: same name/type/width/value/boundaries; AR absent; AP exact literal; bytes/xrefs unchanged |
| IDA-2OF-004 | data item `[0x620290,0x620294)` | historical prestate: name absent; type absent; width 4; value `0x41b6c0`; AR absent; AP absent; function comments not applicable | applied_verified: set AP to `ObjectList primary vftable slot 2: inherited LObject::OnChangeMessage at 0x0041b6c0.` | canonical shared function/current declaration; very strong; do not rename/type data cell | saved readback: same name/type/width/value/boundaries; AR absent; AP exact literal; bytes/xrefs unchanged |
| IDA-2OF-005 | function `[0x530ee0,0x53125d)` | historical prestate: name `sub_530EE0`; declaration `_DWORD *__thiscall(_DWORD *this, char *Block, char *)`; AR absent; AP absent; FR absent; FP absent; frame: `var_1C +0x10 void *`, `var_18 +0x14 _DWORD`, `var_14 +0x18 void *`, `var_10 +0x1c _DWORD`, `var_C +0x20 _DWORD`, `var_4 +0x28 _DWORD`, saved registers `+0x2c`, return `+0x30`, `Block +0x34 void *`, `block +0x38 void *` | applied_verified: rename to `ObjectList__Constructor` | vptr store/callers/collision-free; strong; UDT ordinal619 prerequisite; name action only | saved readback: name `ObjectList__Constructor`; final declaration `ObjectList *__thiscall ObjectList__Constructor(ObjectList *this, int gridWidth, int gridHeight)`; AR/AP/FP absent; FR exact IDA-2OF-007 literal; protected nonargument frame unchanged; `gridWidth +0x34/4 signed __int32`, `gridHeight +0x38/4 signed __int32`; bytes/bounds/callers unchanged |
| IDA-2OF-006 | function `[0x530ee0,0x53125d)` | historical prestate: name `sub_530EE0`; declaration `_DWORD *__thiscall(_DWORD *this, char *Block, char *)`; AR absent; AP absent; FR absent; FP absent; frame: `var_1C +0x10 void *`, `var_18 +0x14 _DWORD`, `var_14 +0x18 void *`, `var_10 +0x1c _DWORD`, `var_C +0x20 _DWORD`, `var_4 +0x28 _DWORD`, saved registers `+0x2c`, return `+0x30`, `Block +0x34 void *`, `block +0x38 void *` | applied_verified: set declaration `ObjectList *__thiscall ObjectList__Constructor(ObjectList *this, int gridWidth, int gridHeight)` | constructor stores width/height into `+0x0c/+0x10`; strong; preserve UDT size0x44/nonargument frame | saved readback: name `ObjectList__Constructor`; declaration exact; AR/AP/FP absent; FR exact IDA-2OF-007 literal; protected nonargument frame unchanged; `gridWidth +0x34/4 signed __int32`, `gridHeight +0x38/4 signed __int32` (IDA rendering of source `int`); bytes/bounds/callers unchanged |
| IDA-2OF-007 | function `[0x530ee0,0x53125d)` | historical prestate: name `sub_530EE0`; declaration `_DWORD *__thiscall(_DWORD *this, char *Block, char *)`; AR absent; AP absent; FR absent; FP absent; frame: `var_1C +0x10 void *`, `var_18 +0x14 _DWORD`, `var_14 +0x18 void *`, `var_10 +0x1c _DWORD`, `var_C +0x20 _DWORD`, `var_4 +0x28 _DWORD`, saved registers `+0x2c`, return `+0x30`, `Block +0x34 void *`, `block +0x38 void *` | applied_verified: set FR to `ObjectList constructor. Installs the ObjectList vftable, initializes the 0x44-byte LObject-derived map object index, and allocates semantic item, flying, effect, living, static, and overlay List storage from padded grid dimensions.` | exact decompile/layout; strong; comment-only row | saved readback: name/prototype exact; AR/AP/FP absent; FR exact literal; protected nonargument frame unchanged; `gridWidth +0x34/4 signed __int32`, `gridHeight +0x38/4 signed __int32`; bytes/bounds/callers unchanged |
| IDA-2OF-008 | function `[0x531260,0x531473)` | historical prestate: name `sub_531260`; declaration `void __thiscall(int this)`; AR absent; AP absent; FR absent; FP absent; frame `var_10 +0x10 _DWORD`, `var_C +0x14 _DWORD`, saved registers `+0x20`, return `+0x24`, `arg_4 +0x2c _DWORD` | applied_verified: rename to `ObjectList__Destructor` | wrapper call/vptr store/collision-free; very strong; name only | saved readback: name `ObjectList__Destructor`; final declaration `void __thiscall ObjectList__Destructor(ObjectList *this)`; AR/AP/FP absent; FR exact IDA-2OF-010 literal; bounds/callers/protected frame state unchanged |
| IDA-2OF-009 | function `[0x531260,0x531473)` | historical prestate: name `sub_531260`; declaration `void __thiscall(int this)`; AR absent; AP absent; FR absent; FP absent; frame `var_10 +0x10 _DWORD`, `var_C +0x14 _DWORD`, saved registers `+0x20`, return `+0x24`, `arg_4 +0x2c _DWORD` | applied_verified: set declaration `void __thiscall ObjectList__Destructor(ObjectList *this)` | ordinary destructor decompile; very strong; preserve no explicit source args | saved readback: name/prototype exact; AR/AP/FP absent; FR exact IDA-2OF-010 literal; bounds/callers/protected frame state unchanged; no explicit source argument was added |
| IDA-2OF-010 | function `[0x531260,0x531473)` | historical prestate: name `sub_531260`; declaration `void __thiscall(int this)`; AR absent; AP absent; FR absent; FP absent; frame `var_10 +0x10 _DWORD`, `var_C +0x14 _DWORD`, saved registers `+0x20`, return `+0x24`, `arg_4 +0x2c _DWORD` | applied_verified: set FR to `ObjectList ordinary destructor. Restores the ObjectList vftable, releases semantic row and direct List storage, conditionally releases damage-number storage, and then destroys the LObject base; deleting-wrapper flag handling is separate compiler output.` | exact cleanup behavior; strong | saved readback: name/prototype exact; AR/AP/FP absent; FR exact literal; bounds/callers/protected frame state unchanged |
| IDA-2OF-011 | function `[0x537290,0x5372c8)` | historical prestate: name `sub_537290`; declaration `void *__thiscall(void *Block, char)`; AR absent; AP absent; FR absent; FP absent; frame saved registers `+0x4`, return `+0x8`, `arg_0 +0xc int` | applied_verified: rename to `ObjectList__scalar_deleting_destructor` | sole vtable xref, ordinary-dtor call, collision-free; very strong; name only | saved readback: name `ObjectList__scalar_deleting_destructor`; final declaration `ObjectList *__thiscall ObjectList__scalar_deleting_destructor(ObjectList *this, unsigned int deleteFlags)`; AR/AP/FP absent; FR exact IDA-2OF-013 literal; saved registers/return protected; `deleteFlags +0xc/4 unsigned int`; bytes/bounds/xref/constants unchanged |
| IDA-2OF-012 | function `[0x537290,0x5372c8)` | historical prestate: name `sub_537290`; declaration `void *__thiscall(void *Block, char)`; AR absent; AP absent; FR absent; FP absent; frame saved registers `+0x4`, return `+0x8`, `arg_0 +0xc int` | applied_verified: set declaration `ObjectList *__thiscall ObjectList__scalar_deleting_destructor(ObjectList *this, unsigned int deleteFlags)` | flags/return/retn4 ABI; very strong | saved readback: name/prototype exact; AR/AP/FP absent; FR exact IDA-2OF-013 literal; saved registers/return protected; `deleteFlags +0xc/4 unsigned int`; bytes/bounds/sole vtable xref/constants unchanged |
| IDA-2OF-013 | function `[0x537290,0x5372c8)` | historical prestate: name `sub_537290`; declaration `void *__thiscall(void *Block, char)`; AR absent; AP absent; FR absent; FP absent; frame saved registers `+0x4`, return `+0x8`, `arg_0 +0xc int` | applied_verified: set FR to `MSVC ObjectList scalar deleting destructor. Calls ObjectList::~ObjectList(), conditionally frees this for deleteFlags bit 0, and preserves the deleteFlags bit 2 guard path for the exact 0x44-byte object. Compiler-generated; not a source method declaration.` | exact instructions/flags; strong | saved readback: name/prototype exact; AR/AP/FP absent; FR exact literal; saved registers/return protected; `deleteFlags +0xc/4 unsigned int`; bytes/bounds/sole vtable xref/constants unchanged |

Protected no-change dependencies:

- Preserve COL `0x64ccb4` name `??_R4ObjectList@@6B@`, current regular comment `signature`, repeatable comment absent, RTTI type/CHD/base descriptor names and bytes.
- Preserve UDT `ObjectList` ordinal 619, size `0x44`, and all 17 exact members. Do not invent a complete LObject UDT from the currently incomplete type.
- Preserve `LObject__GetRuntimeClass` and `LObject__OnChangeMessage` names, declarations, comments, bytes, bounds, and all shared xrefs.
- Preserve predecessor `L"DLGEXC3.EPD"`, successor ObjectPane COL/vtable, all item boundaries, bytes, vptr stores, callers, and xrefs.
- Pre-action 836A, dated post-action DADC, and current DAA597 session07b29e1b readbacks all confirmed these protected dependencies unchanged: the predecessor remains one `[0x62026c,0x620284)` `const wchar_t` item; the successor remains ObjectPane COL at `0x620294 -> 0x64ce90` and decorated vftable at `0x620298`; inherited functions remain `[0x4f4b10,0x4f4b16)` and `[0x41b6c0,0x41b6c3)`; ObjectList remains a 17-member `0x44` UDT; and constructor/destructor/wrapper bytes, bounds, callers/xrefs, constants, comments, and protected frame state remain unchanged.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, but only the human source declarations/routes. Compiler vtable/RTTI/deleting-wrapper artifacts use exact covered-by markers.
- Target UID0002OF CPP exact insertion:

```cpp
// Emitted code for this range is covered by [UID:00009Q].
```

- Target UID0002OF H: blank. The range itself has no declaration; the generating class declaration belongs to UID00009Q H.
- UID0001YB CPP exact insertion:

```cpp
// Emitted code for this range is covered by [UID:00009Q].
```

- UID0001YB H: blank.
- UID0001D4 CPP exact insertion:

```cpp
// Emitted code for this range is covered by [UID:00009Q].
```

- UID0001D4 H: blank.
- UID00009Q CPP exact resulting content:

```cpp
#include "ObjectList.h"

[[CHILDREN]]
```

- UID00009Q H exact resulting content:

```cpp
#ifndef NEXUSTK_MAP_OBJECTLIST_H
#define NEXUSTK_MAP_OBJECTLIST_H

#include "../util/LObject.h"

typedef unsigned int ObjectListKey;

class List;
class ObjectPane;
class StaticObjectPane;

class ObjectList : public LObject
{
public:
    ObjectList(int gridWidth, int gridHeight);
    virtual ~ObjectList();

    bool HasValidGridOrigin();
    void AddObjectPane(ObjectPane *object);
    void RemoveObjectPane(ObjectPane *object);
    ObjectPane *ResolveObjectListKey(ObjectListKey key);
    ObjectListKey GetTypedObjectKey(ObjectPane *object);
    ObjectPane *FindByObjectId(int objectId);
    bool ContainsTypedObject(ObjectPane *object);
    void DetachAll(ObjectPane *preserveObject);
    void RemoveMarkedVisibleObjects();

    List *GetPrimaryCellList();
    List *GetSecondaryCellList();
    List *GetPrimaryRowBucket(int row);
    List *GetSecondaryRowBucket(int row);
    List *GetVisibleObjectList();
    List *GetSecondaryGlobalList();
    List *GetAlternateGlobalList();
    List *GetTertiaryGlobalList();
    List *GetQuaternaryGlobalList();
    List *GetQuinaryGlobalList();
    List *GetFrontRowBucket(int row);
    List *GetBackRowBucket(int row);
    StaticObjectPane *FindStaticObjectPaneAt(int tileX, int tileY);

private:
    static const ObjectListKey kObjectListKeyNotFound = 0xffffffffu;

    ObjectListKey FindStaticObjectKey(ObjectPane *object);
    ObjectListKey FindLivingObjectKey(ObjectPane *object);
    ObjectListKey FindItemObjectKey(ObjectPane *object);
    ObjectListKey FindFlyingObjectKey(ObjectPane *object);
    ObjectListKey FindPrimaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindSecondaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindBalloonObjectKey(ObjectPane *object);
    ObjectListKey FindHitBarObjectKey(ObjectPane *object);
    ObjectListKey FindDamageNumberObjectKey(ObjectPane *object);

    int m_minX;
    int m_minY;
    int m_gridWidth;
    int m_gridHeight;
    List *m_itemObjects;
    List *m_flyingObjects;
    List **m_primaryEffectRows;
    List **m_secondaryEffectRows;
    List **m_livingObjectRows;
    List **m_staticObjectRows;
    List *m_balloonObjects;
    List *m_hitBarObjects;
    List *m_damageNumberObjects;
    List *m_objectInfoObjects;
    List *m_lightingObjects;
    List *m_soundObjects;
};

#endif
```

- Runtime fidelity: the compiler regenerates the same RTTI/vtable/deleting-wrapper from the inherited class and virtual destructor; method children retain exact behavior.
- Human source shape: a guarded header, forward declarations, base include, class declaration, and ordinary CPP definitions match plausible mid-2000s C++ development. No `sub_`, `nullsub`, `_DWORD`, raw address, or manual vtable syntax enters final source.
- Naming style: existing project PascalCase classes/methods, `m_` fields, `k` constant, and `ObjectListKey` typedef are retained for consistency; execution and human source quality remain higher priority than style alone.
- Third-party import: not applicable; this is first-party NexusTK class/compiler output.

## Final Recommendation

- Ordinary C01-C15, C20-C24, C31-C35, C39-C47, C52, and C55 are physically applied; C10/C14/C34/C42/C48-C51/C53-C54/C56/C64-C65 were independently confirmed already present. Supervisor-applied C16-C19/C25-C30/C36-C38 and reconciled C66 are `applied` after exact session07b29e1b readback and dated DADC save; current DAA597 reread proves that poststate survived the unrelated UID0004EO-only save. Supervisor-applied C57-C61 are `applied`; C62-C63 are verified `already-present` no-ops.
- Manual operations M02-M05 were applied as exact no-loss merges rather than shortened summaries: they retain every still-valid prestate-row fact and add only the accepted stronger wrapper, source-topology, RTTI/slot, and covered-by conclusions. M01 was applied exactly; N01-N02 were re-read and retained unchanged. Commands20019-20022 all returned exit `0` / `ok:1` with generated refresh deliberately skipped.
- UID0002OF remains the sole declared target and is fully resolved: exact range, classification, owner/emitter, marker, score, and evidence.
- Preserve parent assignments: UID0002OF -> UID00009Q -> UID0000M4. Do not attach directly to UID000260.
- No item remains no-owner. UID000260 remains non-emitting because it is a mixed inventory, not because target ownership is unknown.
- Future work outside scope: none required for this vtable/source-quality decision. Broader exact-private-name refinement can occur only if original symbols/source emerge and does not block implementation.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00620284-0x00620294.ObjectListVtableData.md`.
- Incorporate exact bytes/hash, four-dword interpretation, RTTI hierarchy, canonical slot names, lifecycle/xrefs, predecessor/successor correction, source-declared/generated-binary policy, protected-state/IDA handoff, source route, negative evidence, and report-time generated/tracker provenance.
- Metadata: completion `92`, confidence `94`; retain owner `00009Q`, emitter `00009Q`, reconstructable true, blank position, `Nested:4`.
- Formal: exact UID00009Q covered-by CPP marker; blank H.
- Item Summary exact replacement: `Exact 16-byte ObjectList RTTI/COL-pointer plus three-slot primary vtable with direct LObject hierarchy, constructor/destructor stores, compiler scalar deleting destructor, inherited GetRuntimeClass and OnChangeMessage slots, exact DLGEXC3.EPD/ObjectPane fences, class/header source route, and no-handwritten-vtable covered-by disposition.`
- Preserve stale assumptions under history: old terminal-`0x44`, `sub_4F4B10`, `nullsub_18`, custom marker, and low-gate rationale, each with rejection evidence.

## Recommended Support Doc Changes

- `by-class/ObjectList.md` UID00009Q: preserve the complete LObject-derived `0x44` declaration, semantic storage, exact lifecycle/dispatch/accessor/private-key methods, exact `FindStaticObjectPaneAt` spelling, child-only definitions, and compiler exclusions; move the complete declaration to the exact guarded H payload, keep CPP include/children only, and add RTTI/vtable/source topology plus IDA handoff; `92/93`.
- `by-file/ObjectList.md` UID0000M4: preserve the complete declaration, semantic storage taxonomy, exact lifecycle/dispatch/accessor/private-key methods, exact `FindStaticObjectPaneAt` child, remaining helper splits, child-only emission, and compiler exclusions; document the `ObjectList.h/.cpp` split, generated-header expectation, compiler RTTI/vtable/deleting-wrapper regeneration, and report-time generated state; `92/93`.
- `by-type/by-vtable/ObjectList_vtable.md` UID0001YB: preserve UID00009Q parent/UID0000M4 file attachment, the prior parent-chain gate history, exact RTTI pointer/three-slot evidence, constructor/destructor stores, scalar-wrapper data reference, child `.rdata` range, and adjacent ObjectPane boundary; add exact COL/direct-LObject hierarchy, canonical slots/fences, covered-by marker, and `92/94`.
- `by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md` UID0001D4: preserve the exact `0x38` boundary, sole vtable xref `0x00620288`, constructor/destructor vptr writes, ordinary-destructor delegation, explicit OperatorDeleteWrapper route, `0x44` guard, adjacent padding, and class attachment; add exact wrapper ABI/flags, covered-by/no-handwritten-emission policy, item-summary correction, and `90/94`.
- `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md` UID0001D1: synchronize current constructor/destructor/wrapper names and source-generated route; retain score.
- `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md` UID000260: expand exact child row; retain non-reconstructable parent-blank metadata.
- Inspect and retain without ordinary change: UID0001VG layout, UID0002JS constructor formal, UID0002JT destructor formal, and shared LObject functions.

## Score And Metadata Recommendation

- UID0002OF: `85/92 -> 92/94`; owner/emitter/reconstructable/range/nesting unchanged.
- UID00009Q: `91/93 -> 92/93`; owner/emitter unchanged. Completion rises because declaration moves to H and CPP becomes a proper source root; confidence remains capped by stripped private spelling.
- UID0000M4: `91/93 -> 92/93`; source root unchanged.
- UID0001YB: `85/91 -> 92/94`; owner/marker policy unchanged in kind but normalized.
- UID0001D4: current metadata `86/92 -> 90/94`; class owner/reconstructable unchanged.
- Retain UID0001VG `92/94`, UID0002JS `90/92`, UID0002JT `90/92`, UID0001D1 `87/92`, and UID000260 `90/92`.
- Reason not lower: exact binary range, hierarchy, slots, lifecycle, xrefs, owner, source classification, and formal source route are closed.
- Reason not higher: original private identifier/guard spelling is stripped; constructor/destructor drafts remain first-draft rather than compiler-verified 1:1 rebuild source; shared LObject IDA UDT is incomplete and intentionally not invented.
- Score-improvement work resolved every listed blocker: exact predecessor/successor, liveness, slot identities, inheritance, wrapper role, owner, formal channel, marker policy, generated topology, and IDA handoff.

## Open Questions With Attempted Resolution

- Is `0x620280` separate data? Resolved no: exact predecessor item/string boundary includes it.
- Is there a fourth vtable slot? Resolved no: `0x620294` is ObjectPane COL.
- Are slots 1-2 ObjectList overrides? Resolved no: canonical shared LObject functions and high shared xref counts prove inherited slots.
- Is scalar wrapper dead? Resolved no: vtable-only reachability is exact and expected.
- Should target CPP be blank or custom prose? Resolved: exact covered-by marker is required; blank causes empty-emitter ambiguity, custom prose is noncanonical.
- Where does class source belong? Resolved: UID00009Q H and UID0000M4 `map/ObjectList.h/.cpp`.
- Should LObject be completed in IDA? Resolved no: no exact full layout proof is needed for this action; preserve incomplete dependency.
- Remaining unresolved: literal original private identifier and guard spelling. Exhaustive binary/docs/report checks cannot recover them; descriptive project-consistent names are the highest-probability human-source reconstruction. This caps confidence but does not block code or source placement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Historical pre-application manual identities and exact transaction anchors:

- Final bounded pre-application recheck after UID0003P4 insertion:
  - `by-memory/-coverage-report.md`: SHA256 `82A918D06B56759FB52713751D1BD4E171379BBC4239229C5616168CB49F0C8E`, 2,108,263 bytes/4,769 lines.
  - `by-class/-coverage-report.md`: SHA256 `396DAD20C73A2A54EAF045320B17ECA1FF877B02D36FF4CE204D4BA0D8D0A9E9`, 272,277 bytes/625 lines.
  - `by-file/-coverage-report.md`: SHA256 `736B2900338FDFE34C44CD18CF9DF0C7791820D28D42DAB7B5E9DD0691EB6BFE`, 162,964 bytes/317 lines.
  - `by-type/by-vtable/-coverage-report.md`: SHA256 `D68E24B090F48570D17727658EE3020292D544C0866DFE1D1CB784EECB6E9571`, 67,386 bytes/146 lines.
  - `by-type/by-struct/-coverage-report.md`: SHA256 `04608E802C5217FFA3B6A615427345E8EF89B57253DBE2B3549A37F24726E537`, 59,231 bytes/137 lines.
- Dated `2026-07-30` pre-UID0003P4 checkpoint retained as history: by-memory `C5E4E81C9EBC12C6A0A73D187100657F9406043C2B826C1519B8A21BED62BAC5` / 2,107,677 / 4,768 and by-class `64862329F2FCE0B5AEF01B349E0D5A5D2F09F0B319C8A9EB173521F5F385BC03` / 272,272 / 625. Earlier pre-B007/B001 history remains by-memory `22BB0BB3366ED1A445E99E03D6CED32D1F263E12940D400AEA68D1D19EC705F2` / 2,101,781 / 4,754; by-class `EE896367FAA8DF9113167918E06166EE932342C986E0BA7A5FA32C674CD74565` / 272,165 / 625; by-file `21886E924A4062AB4A82892CB36754634CB933B41683810A8D185553123A24E2` / 162,812 / 317; by-vtable `E8AB42D1B4B93A6F3C27F703E10D25706BAF5C7F90D5D34B452520BF1C7F3938` / 67,290 / 146. The five replacement payloads were subsequently applied; these identities therefore remain transaction prestates, not present-current hashes.

Exact pre-application anchors and completed dispositions:

- M01: supervisor replaced UID0002OF at its verified line4302 prestate anchor, immediately after UID000260 line4301 and before UID0002SK, with the exact payload below; command20019 accepted the resulting by-memory coverage file.
- M02: supervisor replaced UID0001D4 at its verified line2724 prestate anchor between the UID0000VN `0x0053728e-0x00537290` and `0x005372c8-0x005372d0` padding rows with the exact no-loss merge below; command20019 accepted the resulting by-memory coverage file.
- M03: supervisor replaced UID00009Q at its verified line374 prestate anchor between UID00009P and UID00009R with the exact no-loss merge below; command20020 accepted the resulting by-class coverage file.
- M04: supervisor replaced UID0000M4 at its verified line193 prestate anchor between UID0000M3 and UID0000M5 with the exact no-loss merge below; command20021 accepted the resulting by-file coverage file.
- M05: supervisor replaced UID0001YB at its verified line100 prestate anchor between UID0003IR and UID0003JA with the exact no-loss merge below; command20022 accepted the resulting by-vtable coverage file.
- N01: supervisor re-read UID000260 at its prestate line4301 anchor between UID0002SI and UID0002OF and retained the exact mixed-parent non-reconstructable row unchanged.
- N02: supervisor re-read UID0001VG at its prestate line87 anchor between UID0001VF and UID0001VH and retained the exact `92% : very-strong` `0x44` layout row unchanged.

Applied operation M01 historical payload, used to replace UID0002OF at prestate line4302 directly after UID000260 line4301 and before UID0002SK:

```text
        - [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md) 0x00620284-0x00620294 | vtable-data | ObjectListVtableData : reconstructable : 92% : very-strong : Exact 16-byte ObjectList source-declared/generated-binary RTTI/COL pointer plus three-slot primary vtable; direct LObject hierarchy, constructor/destructor vptr stores, scalar-deleting-destructor wrapper, inherited GetRuntimeClass/OnChangeMessage slots, exact DLGEXC3.EPD predecessor and ObjectPane successor fences, class/header owner route, and covered-by marker with no handwritten vtable array.
```

Applied operation M02 historical payload, used to replace UID0001D4 at prestate line2724 between the exact UID0000VN pre/post padding anchors:

```text
    - [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) 0x00537290-0x005372c8 | scalar deleting destructor | ObjectListScalarDeletingDestructor : reconstructable : 90% : very-strong : Exact `0x38`-byte ObjectList vtable-slot-only MSVC scalar deleting destructor wrapper with sole vtable data xref at `0x00620288`, constructor/destructor vptr writes, ordinary ObjectList destructor delegation, optional OperatorDeleteWrapper route for the delete-flags bit-0 free path, preserved bit-2/size-`0x44` guard, returned-`this`/`retn 4` ABI, exact adjacent padding, and class-parent attachment; compiler-generated wrapper behavior is represented by the exact class covered-by marker with no independent handwritten wrapper emission.
```

Applied operation M03 historical payload, used to replace UID00009Q at prestate line374 between UID00009P and UID00009R:

```text
- [UID:00009Q][ObjectList](by-class/ObjectList.md) : reconstructable : 92% : very-strong : Complete guarded ObjectList.h declaration for the direct LObject-derived `0x44` map object index, preserving semantic storage, exact lifecycle/dispatch/accessor/private-key methods, the exact typed `FindStaticObjectPaneAt` static-row lookup, and child-only ObjectList.cpp definitions; exact RTTI/vtable ownership and compiler table/cookie/vtable/scalar-wrapper exclusions regenerate binary artifacts without handwritten compiler output.
```

Applied operation M04 historical payload, used to replace UID0000M4 at prestate line193 between UID0000M3 and UID0000M5:

```text
- [UID:0000M4][ObjectList](by-file/ObjectList.md) : reconstructable : 92% : very-strong : NexusTK/map/ObjectList.h and ObjectList.cpp source root with the complete guarded ObjectList declaration in H, include/child definition route in CPP, semantic storage taxonomy, exact lifecycle/dispatch/accessor/private-key methods, exact typed `FindStaticObjectPaneAt` child, preserved remaining helper splits, and child-only emission; compiler RTTI/vtable/scalar-wrapper artifacts are regenerated rather than handwritten.
```

Applied operation M05 historical payload, used to replace UID0001YB at prestate line100 between UID0003IR and UID0003JA:

```text
- [UID:0001YB][ObjectList_vtable](by-type/by-vtable/ObjectList_vtable.md) : reconstructable : 92% : very-strong : Attached to [UID:00009Q][ObjectList](by-class/ObjectList.md) under [UID:0000M4][ObjectList](by-file/ObjectList.md), preserving the prior class/file parent-chain gate history and exact ObjectList RTTI pointer, three-slot vtable, constructor/destructor vptr stores, scalar-deleting-destructor data reference, exact child `.rdata` range, and adjacent ObjectPane RTTI boundary; exact COL/type/CHD direct-LObject hierarchy resolves the slots as compiler scalar deleting destructor plus inherited LObject::GetRuntimeClass and LObject::OnChangeMessage, with exact DLGEXC3.EPD/ObjectPane fences and a class covered-by marker instead of a handwritten vtable array.
```

Verified no-op N01: supervisor retained UID000260 unchanged; it already accurately describes the mixed non-reconstructable parent and exact-child ownership.

Verified no-op N02: supervisor retained UID0001VG unchanged; its `92% : very-strong` exact `0x44` layout summary is complete.

These files are collision-prone manual supervisor property. B004 did not apply any operation directly; the supervisor applied M01-M05 and verified N01-N02. Validator-owned `auto-generated/-ag-*` rows received no manual edit.

## Follow-Up Actions

- Supervisor: independently perform fresh Gate 1 on this DAA597/command19993/post-Gate2B/manual-coverage reconciled artifact, then final Gate 2 currentness verification against the callback hashes, saved IDA poststate, and applied claim states.
- Supervisor: re-read the durably saved IDA-2OF-001..013 poststate and protected constraints as final Gate 2 currentness proof; the application/readback/save transaction itself is complete.
- Supervisor: treat M01-M05 and N01-N02 as applied/verified under commands20019-20022, refresh or re-read generated/tracker state as required for final closure, and independently execute/archive through validator-owned lifecycle only after fresh gates.
- A-agent actions: none.
- B004 future research: none unless supervisor returns exact Gate 1 defects or implementation reconciliation findings.

## Confidence

- Recommendation confidence: very strong (`94`) for target binary/source disposition.
- Score confidence: strong; applied/retained scores reflect resolved target blockers and preserve caps for stripped original spelling/first-draft broader source.
- Remaining uncertainty: original private identifiers and include-guard spelling only; no uncertainty remains about runtime role, owner, range, slots, inheritance, or generated-binary policy.

## Validator Results

- Every final ordinary validation used `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240 --no-generated-refresh`, ran serially under a short lease, returned exit `0` / `ok:1`, and reported `generated_refresh: skipped` with detail `disabled by --no-generated-refresh`.
- `000000019949`, timestamp `2026-07-30T11:10:36-04:00`, target `by-memory/0x00620284-0x00620294.ObjectListVtableData.md`: exit `0`, `ok:1`, no warnings/errors; final target metadata/formal registry readback accepted.
- `000000019951`, timestamp `2026-07-30T11:10:43-04:00`, class `by-class/ObjectList.md`: exit `0`, `ok:1`, no warnings/errors.
- `000000019942`, timestamp `2026-07-30T11:07:01-04:00`, file `by-file/ObjectList.md`: exit `0`, `ok:1`; one unrelated existing `missing_ref_uid 0003IO` warning, no target failure.
- `000000019944`, timestamp `2026-07-30T11:07:31-04:00`, vtable `by-type/by-vtable/ObjectList_vtable.md`: exit `0`, `ok:1`, no warnings/errors.
- `000000019935`, timestamp `2026-07-30T11:04:03-04:00`, scalar wrapper `by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md`: exit `0`, `ok:1`, no warnings/errors.
- `000000019945`, timestamp `2026-07-30T11:07:56-04:00`, lifecycle `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md`: exit `0`, `ok:1`, no warnings/errors.
- `000000019941`, timestamp `2026-07-30T11:06:25-04:00`, parent `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`: exit `0`, `ok:1`, no warnings/errors.
- Earlier implementation-time commands `000000019929`, `000000019930`, `000000019931`, `000000019932`, `000000019937`, and correction commands `000000019942`, `000000019944`, `000000019945` established the serial edit history; final authoritative per-file records are the seven rows above. The target/class final reruns avoid relying on an unretained initial terminal timestamp. No validator command refreshed generated output or executed the report.
- Supervisor manual-coverage validation command `000000020019`, timestamp `2026-07-30T12:34:41-04:00`, `by-memory/-coverage-report.md`: exit `0`, `ok:1`, generated refresh deliberately skipped; only existing unrelated UID00039L/UID0003T6 missing-reference warnings, no UID0002OF-family failure.
- Supervisor manual-coverage validation command `000000020020`, timestamp `2026-07-30T12:34:44-04:00`, `by-class/-coverage-report.md`: exit `0`, `ok:1`, generated refresh deliberately skipped, no target warning.
- Supervisor manual-coverage validation command `000000020021`, timestamp `2026-07-30T12:34:47-04:00`, `by-file/-coverage-report.md`: exit `0`, `ok:1`, generated refresh deliberately skipped, no target warning.
- Supervisor manual-coverage validation command `000000020022`, timestamp `2026-07-30T12:34:49-04:00`, `by-type/by-vtable/-coverage-report.md`: exit `0`, `ok:1`, generated refresh deliberately skipped; only existing unrelated missing-reference warnings, no UID0002OF-family failure.
- None of commands20019-20022 refreshed generated output or performed report lifecycle execution.

## Changed Files

- Modified ordinary destinations, with exact callback readback: UID0002OF `8D53EC966BBD914BD0BB725AAD19C3C368674B016376C14F56AFE496D3DF7F66`; UID00009Q `59BB84F6E9B8C08AB546DF383FCB6807BD7CD68470132FD545F5E817337D91BB`; UID0000M4 `0011A136D02C1715E6CC2AD9F41FB6E335FFE9706E562641A6C188A239F863D7`; UID0001YB `DA52EF2C8D51E22485A98F8E30ED699727B39A2F3F2218D7E93C2A71AFED41D8`; UID0001D4 `9986116E7FDDC9F0A692DB8DA2896932089A82130B0523F9D3711E8BF5B4BAEB`; UID0001D1 `F2088A267E774A47C99DD7D1479F4D6C46054E9CB3CA1050E531D40DB64D1B53`; UID000260 `C3587F2E5A4370A6142662BBAFE1109125AD4C1F1F8F113D1A1670DAEC5677F1`.
- Modified report: `tools/leaser/Agents/Agent-B004/research/0002OF-ObjectListVtableData-source-quality.md`.
- Renamed: none.
- Supervisor-owned UID0002OF Gate 2B changed and saved the dated transaction described above: prestate backup `NexusTK.exe.i64.bak-UID0002OF-prestate-20260730-122729` SHA `836ABCFA...F489F`, restored-safe historical save SHA `DADC487F...C6A4`, session `07b29e1b`, `idb_save ok:true`. Current shared authority is SHA `DAA59745...2C17`, 143,192,163 bytes, saved `2026-07-30T12:47:29.2294093-04:00` after accepted unrelated UID0004EO-only work. B004 did not mutate/save IDA or repeat/alter UID0004EO actions; bounded target-only reread found no UID0002OF drift.
- Supervisor-owned manual closure changed `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md` through exact M01-M05; `by-type/by-struct/-coverage-report.md` and UID000260's by-memory row were verified no-op. Commands20019-20022 accepted the resulting files with generated refresh skipped. B004 did not edit any coverage file.
- This reconciliation callback changed only this report. It did not change ordinary or inspect-only docs, generated/tracker artifacts, supervisor audit/catalog, goal/notes, validator/lifecycle state, coverage, or IDA. Command19993 remains the dated generated/tracker checkpoint recorded by the report pending final supervisor currentness closure.
- Report execution/archive status is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact SHA `44FE14660A54CB23443341D7438819DC883D890539FE875D31F034E7DE112466` and authorized the ordinary callback; remaining gates are supervisor-owned.
- [x] Ordinary target/support destinations and associated handoffs are listed by exact UID/path/section in C01-C56.
- [x] Additional target UID requirement checked: none declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger remains contiguous/atomic C01-C66 and distinguishes physical callback/supervisor `applied` states from verified `already-present` states.
- [x] Metadata/score changes are exact for UID0002OF/00009Q/0000M4/0001YB/0001D4 and retain dispositions are explicit.
- [x] Score-limiting blockers were actively researched and resolved or narrowly confidence-capped.
- [x] Owner/emitter/reconstructable dispositions are exact and preserve UID00009Q route.
- [x] Range/split/rename/source-placement/generated-binary decisions are exact.
- [x] IDA handoff lists thirteen atomic rows with exact historical prestate, applied action, saved readback, and protected dependencies; all were applied/verified in supervisor session07b29e1b at dated DADC, and current DAA597 bounded reread confirms the full poststate survived unrelated UID0004EO-only work.
- [x] Supervisor Gate 2B IDA-2OF-001..013 application/readback/save completed: four exact data comments, constructor/destructor/wrapper names/prototypes/comments, constructor signed-`int` argument rendering, wrapper `deleteFlags`, and all protected invariants were verified; `idb_save` returned `ok:true`.
- [x] Exact formal CPP/H payloads and blank-channel reasons are supplied.
- [x] Third-party import is explicitly not applicable.
- [x] Exact report-level target/support facts are supplied without summary loss.
- [x] Historical/stale assumptions and rejected alternatives are preserved.
- [x] Wave2/Wave3 artifacts are rejected as stale absent explicit override.
- [x] Open questions are resolved or narrowly evidence-capped.
- [x] Validator plan was followed with serial scoped file validators, `--no-generated-refresh`, exact IDs/timestamps/results, and no lifecycle command.
- [x] Five exact manual coverage replacements and two exact no-ops were prepared from the post-UID0003P4 identities/anchors; M02-M05 are explicit Rule26 no-loss merges preserving every valid prestate-row fact, exact `FindStaticObjectPaneAt` spelling, parent/file attachment, helper splits, stores/xrefs/bounds/padding, and adding only accepted stronger conclusions. Supervisor applied M01-M05, retained N01-N02, and validated commands20019-20022. Tracker command19993/line3325 `92/94`/true/`0/0/0` remains a dated generated checkpoint, with command19933/19928 retained as earlier history.

Implementation callback pass:

- [x] Supervisor acceptance for ordinary implementation callback is recorded from the exact callback instruction.
- [x] All accepted target/support details were incorporated at report-level detail across the seven authorized destinations.
- [x] UID0002OF was independently verified against the ledger, exact bytes, metadata, formals, and destination docs.
- [x] Ledger verification states were updated only from physical implementation/inspect-only readback.
- [x] Accepted metadata/score/owner/emitter/formal changes were applied or explicitly retained.
- [x] Historical assumptions/negative evidence were preserved and explicitly superseded in ordinary docs.
- [x] Open-question dispositions were reconciled into ordinary docs without inventing stripped identifiers.
- [x] Serial scoped validators ran and exact final IDs/timestamps/results/hashes are recorded.
- [x] Command19993 generated CPP/H and tracker closure is recorded lifecycle-neutrally as a dated physical checkpoint; final supervisor Gate 2 owns currentness recheck/refresh as needed.
- [x] Manual coverage M01-M05 was applied exactly and N01-N02 was verified unchanged by the supervisor; commands20019-20022 returned exit `0` / `ok:1` with generated refresh skipped and only stated unrelated warnings.
- [x] No research or implementation claim remains proposed: IDA C16-C19/C25-C30/C36-C38, manual C57-C61, no-op C62-C63, and reconciliation C66 are applied/verified or already-present. Remaining work is only fresh supervisor Gate 1/final Gate 2 currentness and validator-owned generated/lifecycle closure.
- [x] Report body is lifecycle-neutral and does not claim a durable execution/archive state.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000020034","destination_path":"executed-b-agent-research/B004/0002OF-ObjectListVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002OF-ObjectListVtableData-source-quality.md","timestamp":"2026-07-30T13:03:39-04:00","uid":"0002OF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
