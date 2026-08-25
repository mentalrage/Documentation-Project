** TARGET-REPORT-UID:00030C **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID00030C TextEditPaneOnDraw Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: reconstruct [UID:00030C] as the source-authored virtual member `void TextEditPane::OnDraw()` over exact range `0x00590810-0x005909e3` and emit the complete human source through [UID:0000EO] `TextEditPane` in [UID:0000ON] `NexusTK/ui/controls/TextEditPane.cpp`.
- Final disposition applied: target moved from `86/90` to `92/94`; owner/emitter UID0000EO, `RECONSTRUCTABLE:TRUE`, blank optional position, exact range, and callback-authorized `Nested:0` are retained in current destination truth; Destination 1 is installed exactly.
- Split closure applied serially: validator assigned [UID:0004T1] to `0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles.md` under command 14734 and [UID:0004T2] to `0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY.md` under command 14735. Every temporary token was replaced before dependent validation and no placeholder remains.
- Support closure applied: the complete TextEditPane union is preserved with the two private helper declarations, the complete `TextRunDrawState` definition resides in the class/header destination, editor-flag names are unified, the draw callback uses inherited `m_drawMode` plus exact `g_pfnFillRect`, both TextBoxPane comparator bodies are rebased, UID00030D is source-ready, and the slot-7 Surface callback declaration is present without changing unrelated slots.
- Confidence: very strong for range, bytes, ABI, virtual slot, branch behavior, field widths, helper contracts, List lifetime, callback state, and source placement; strong for source-facing helper and flag spellings. Unknown original lexical spelling is reflected in the confidence cap and does not justify blank C++.
- Current report state: the accepted implementation callback is complete in canonical `source-3/project-documentation`. B004 changed the fifteen authorized destination groups, created/registered UID0004T1 and UID0004T2, ran scoped validators 14734-14739, 14741, 14744, 14746, 14751-14758, and released every lease. The supervisor subsequently applied and independently validated the exact B004 manual coverage handoff under commands 14778-14782. B005 then completed its serialized shared-lane callback and the supervisor historically executed UID000478 under command 14835; later unrelated external activity advanced generated and tracker authority through command 14859 and advanced manual coverage through the separately identified WorldMap synchronization recorded below without changing the B004 union. This bounded report-only rebase confirms the resulting B001/B003/B004/B005 union is same-or-greater. B004 did not manually edit ordinary/coverage/generated/tracker/audit/supervisor/validator-state files, mutate IDA, or run any report lifecycle command during reconciliation; report validation/execution/archive/count state remains external supervisor/validator-owned.

## Supporting Research

- Historical pre-callback UID00030C was a useful boundary shell whose blank formal and blocker prose said draw state, selection-list types, helper names, and flag meanings remained unresolved. Live target/comparator analysis closed every point, and the current target page contains the accepted source-ready body and complete evidence.
- Executed B004 report `executed-b-agent-research/B004/0000ON-TextEditPane-empty-emitter-family-source-quality.md`, SHA256 `B205C3143C71DE518C1FF0259FACDD3926522FE48C1E75049D884DD53C3458D7`, is a broad historical family lead. It deliberately left UID00030C blank at an earlier evidence epoch and is not direct current target authority.
- Executed B005 report `executed-b-agent-research/B005/0000EO-TextEditPane-class-source-quality.md`, SHA256 `88FD5933A9A50969FFD819C7C9D407CF14CCE1FA4733985E7817266E234F956D`, establishes class/vtable/source placement. Current class bytes have since advanced and control the complete declaration union.
- Executed B001 constructor report `executed-b-agent-research/B001/0002ZY-TextEditPaneConstructor-source-quality.md`, SHA256 `4F82A22DDBCF3710F997EE6196A6B5172232773D565060B22DB3FC8181D51ED3`, supplies the current table layouts and constructor union; this report narrows the stale flag-`0x04` name and adds only draw-relevant constants.
- Executed B006 report `executed-b-agent-research/B006/0001JR-DrawTextRunCallback-source-quality.md`, SHA256 `E4A9BBEDE7C8137492FE472711C9C3F2CB92E446AEC96DA6DA3F7A0F71E7E1A9`, supplied the exact cdecl iterator callback ABI and state layout. Its earlier `m_renderMode` and `g_pfnFillOrInvalidateRect` tokens are now explicitly historical: current UID0001JR formal source uses inherited `m_drawMode` and exact `g_pfnFillRect`.
- Executed B007 report `executed-b-agent-research/B007/0001JQ-TextRunMeasureCallback-source-quality.md`, SHA256 `772AFC7EBEB58F1304C6039B3F9DCCF1F4DCE3165EBC1CF2555E0DC4C12E25D3`, independently confirms the 16-byte line records, iterator contract, and callback source placement.
- Executed B001 GrafPort report `executed-b-agent-research/B001/000162-GrafPortDrawStateAccessors-source-quality.md`, SHA256 `F40F99489BF0CDA29736A3E487860C4F5C68F31DAC36DF7CEDDE5E574D3FA00B`, resolves inherited `m_drawMode`, `m_drawColor`, `SetDrawColor`, and clip state.
- Executed B003 CompositePixels report `executed-b-agent-research/B003/000169-CompositePixels16-source-quality.md`, SHA256 `47674C67235BE4C07B0FB3EA09244019BC8D57ED601B95D01E967EFBE91375F4`, resolves the selection-rectangle operation at `0x004ba540` and rejects a target-local resource or pixel-buffer parameter.
- Executed B005 input/navigation report `executed-b-agent-research/B005/0001JS-TextEditPaneInputNavigationWrapAndTextRunHelpers-source-quality.md`, SHA256 `613D33ABCE855846B15C2694C1499E9130BFF9140135F669D05A3EE37466989F`, is neighboring TextEditPane source/layout support only.
- Executed B005 UID000478 artifact `executed-b-agent-research/B005/000478-UserListDialogPaneHandleKeyOrTextEvent-source-quality.md`, SHA256 `5AFC509272899F621192229CF475F07EB0426A5CB60E91DA0A7168BC46D698AE`, records the serialized shared-lane completion and historical supervisor execution command 14835. Its additive TextEdit delta is exact file-local UID0004T8 `PutScrapToClipboard`, two alignment rows, TextEditScrap support, and file/aggregate/caller synchronization; it explicitly preserves the complete B001/B003/B004 draw/serialization/destructor/helper union.
- Finalized B001 serialization artifact `executed-b-agent-research/B001/0001JN-TextEditPaneSerialization-source-quality.md`, current archived SHA256 `11633D4340C8D62E43112AE3A455D65ECDF30A5B506DF7BF5F423A7E067C281D`, records the accepted UID0001JN callback, its then-current command-14702 generated refresh, its command-14703/14704 manual rows, zero leases, and supervisor execution command 14705. That bundled 14702-14704 checkpoint is historical predecessor provenance after unrelated external commands 14712, 14713, 14720, 14732, and 14733; command 14704 is retained as historical by-item row provenance, while current whole-file by-item authority is external command 14782 and preserves the relevant rows. The complete current read-only state is recorded below. Its earlier active SHA `D3D1D11120E2D4E9A9DB1891AE01945E82698D409DE12E564635600D0ACEB29A` is historical report-only coordination evidence.
- Finalized B003 destructor artifact `executed-b-agent-research/B003/0002ZZ-TextEditPaneDestructor-source-quality.md`, current archived SHA256 `6CC99704A40C5BFD8F13199E3F175811B53A6282473AFD905BC9194DEA7FFA93`, records the accepted destructor/private-helper/signed-record/vtable union and supervisor execution command 14684. Its earlier active SHA `A2EA871F67D547102BC7AD4B3E6B236F842B150DB2A234583FCBF1642687BE77` is historical coordination evidence.
- The shared predecessor work was settled rather than active. During this callback B004 reread the durable class/file/aggregate and both finalized artifacts before editing and preserved the complete constructor, ordinary destructor, private `ReleaseFormatObjects`, signed `TextEditFormatRecord::referenceCount`, compiler-vtable, source-ready `EncodeState`, wrapper, and by-item mirror union. No B001/B003 declaration, source body, score, history, or evidence was removed.
- Exact search terms used across active, executed, `tools/leaser/Agents/Older-Research/**`, `tools/leaser/Agents/SpecialReports/**`, and project `archived/**` roots were `UID00030C`, `TARGET-REPORT-UID:00030C`, `0x00590810`, `TextEditPaneOnDraw`, `TextEditPane::OnDraw`, `DrawTextRunCallback`, `0x00591520`, `0x00592bb0`, `TextEditPane`, `GrafPort`, and `SurfaceRenderCallbackTable`.
- The pre-creation search found no pre-existing direct UID00030C report in the active, executed, Older-Research, SpecialReports, or archive roots; this assigned report is the only current direct artifact and was excluded from that duplicate check. Older-Research, SpecialReports, and archive roots returned no direct target match. The listed executed reports are support or historical leads and were opened/classified individually.
- Historical `by-memory/-report.old.md` maps `0x00590810` to `TextEditPane::OnDraw` but used a stale broader endpoint. It supports the source identity only as a lead; current IDA/PE prove exclusive end `0x005909e3`.

## Target

- Target UID: `00030C`.
- Target path: `by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md`.
- Historical pre-callback target SHA256: `BCF39AE0DDDC618F0EA3538FEA20EF78D9C429C84080B1507606B924651177AD`, 6,173 bytes, 65 lines.
- Historical pre-callback metadata was `86/90`, owner/emitter UID0000EO, reconstructable true, blank position/formal C++, `Nested:8`. Current callback state is `92/94`, the same owner/emitter/reconstructable/blank-position contract, complete Destination 1, and supervisor-authorized `Nested:0`.
- Exact source identity: `virtual void TextEditPane::OnDraw()` in `NexusTK/ui/controls/TextEditPane.cpp`.
- Exact binary interval: `[0x00590810,0x005909e3)`, `0x1d3` / 467 bytes.
- Applied target state: `92/94`, owner/emitter UID0000EO, reconstructable true, blank position, `Nested:0`, with Destination 1 emitted exactly once.

## Current Target State

- Current completed ordinary checkpoint: target `1B1ACEE0...7EB9`; registered helpers UID0004T1 `9AFBFD01...C1F3` and UID0004T2 `4C1C247B...E942`; class `258763ED...EE71` at `93/94`; post-B005 file `602378CF...F50E` at `93/93`; pre-TextBox aggregate `7A6AB8A5...9D14` at `87/91`; constructor `6E9F9390...77CD`; ordinary destructor `99F80E53...044F4`; private helper `8D8EA435...2D534`; serialization `25FF6AE6...BBC8`; wrapper `C1FC9E44...E8FF`; vtable `31E15A0C...15A`; draw callback `C95AF6B6...000B`; cursor comparator `3AD1ADD4...E78`; UID00030D `1592AFFF...6441`; post-TextBox aggregate `CDBE5FCE...665`; formatting aggregate `CEE8C233...049B`; Surface global `EE572204...9F6C`; Surface storage `6B4804AD...5AEC`; callback item mirror `8C984BF4...3F6`; post-B005 ignored ledger `A5AD04AE...C7E`.

| Current path | SHA256 | Bytes / lines |
| --- | --- | ---: |
| `by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md` | `1B1ACEE0CB49776A4B84771FD63068CA72446D0563DFB588230BE8D8E1697EB9` | 13,681 / 163 |
| `by-memory/0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles.md` | `9AFBFD01CB6F92B08F1E2654CF7BEC7516A5836CF7D8C96A23B5114BE5A4C1F3` | 8,771 / 123 |
| `by-memory/0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY.md` | `4C1C247B3785CF2939D0D6413161CA77B50B72600AADC3F2237AED7700D9E942` | 6,765 / 99 |
| `by-class/TextEditPane.md` | `258763ED2A6D87804B663CD1FBF724864BD3C10813E786F5D3B622C51094EE71` | 75,537 / 589 |
| `by-file/TextEditPane.md` | `602378CF5C8EF32C6309AE5E1BFF783A327C1A505A97837260D69A1E058DF50E` | 87,456 / 433 |
| `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md` | `7A6AB8A533636A273D159C24E9EF78DFBB95779DC7849A4B8DC2FC958AAE9D14` | 34,437 / 188 |
| `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md` | `6E9F93904FFD59CD31234F190488A4BEB2F6F37F278125EC110AF383D17B77CD` | 18,191 / 247 |
| `by-memory/0x0058e140-0x0058e228.TextEditPaneDestructor.md` | `99F80E5348A099D915344776E9F49DBDBBC8EDB97111E6FAE581C8C05D7044F4` | 16,598 / 158 |
| `by-memory/0x005912b0-0x005912fe.TextEditPaneReleaseFormatObjects.md` | `8D8EA43560F38EC5B387900F140B412EBCB9E1A1A274E0ADE6A81BB5DDF2D534` | 10,803 / 134 |
| `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md` | `25FF6AE6AC4D36A0D7AF9B270DCEF60E8BB5177284AC9937E6417D8724CEBBC8` | 27,632 / 204 |
| `by-item/EncodeTextEditState_0058E490.md` | `166A795092F5C6A104717931A6B75642BE99148A7DA726000A730F78080D2FC7` | 17,878 / 126 |
| `by-memory/0x00498c40-0x00498c5f.TextEditControlPaneStateSerialization.md` | `C1FC9E440AB97DD6879861980D1E61451ED0C92DF854D284F7367716BB27E8FF` | 4,739 / 62 |
| `by-memory/0x0062df94-0x0062e048.TextEditPaneVtableData.md` | `31E15A0CFF58B9FE88C4A39A31C2D74088D379573E93C7823622ACFD0CFC515A` | 6,849 / 68 |
| `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md` | `C95AF6B6A4B3A39F58CEB56AE09AC4572265CAB75F9B731522D6B9880502000B` | 23,589 / 211 |
| `by-memory/0x00591300-0x005913f9.TextBoxPaneCursorInvalidationOverrides.md` | `3AD1ADD404F2E7611D531ABE95759C89F1FE82708C4E242729FDA8CAAD903E78` | 18,287 / 159 |
| `by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md` | `1592AFFF40BF20F4BF5C265D3DF3181BC8D8671C21377AC828C23B100BA76441` | 7,530 / 80 |
| `by-memory/0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane.md` | `CDBE5FCE3EFF3BB9E5E3028ACF4A093152501EE6DA759905CAD22B50A30FB665` | 11,422 / 91 |
| `by-memory/0x005917d0-0x00591a1c.PutScrapToClipboard.md` | `13C874D265DC21797B16780850CE1E9593F024259B691F7FFC3D4BCCE4521236` | 13,018 / 160 |
| `by-memory/0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap.md` | `342550D8956E77678668407C74FA8872AC6AE0D7067427A6E666B8C0C3624341` | 28,218 / 177 |
| `by-memory/0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent.md` | `7FF4F7FF31B561CB6B3E9BC223360599F29C1FBA359F25DCC9F60B6570CADFAC` | 8,131 / 76 |
| `by-class/TextEditScrap.md` | `CA5B60DAC7A9DDC60688FC8CEC88DC11C45D87D4252018257837F41E31A10405` | 18,606 / 167 |
| `by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md` | `CEE8C233D35473BB95A8AE2743BED7AC7F89F8D339D8401E12CF1561CE0B049B` | 21,105 / 185 |
| `by-global/SurfaceRenderCallbackTable.md` | `EE572204BB6675B1DFF0ADB91E2D2B80F81AA7572FEAF99A11396D64DBC89F6C` | 60,789 / 320 |
| `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` | `6B4804AD14ECAF45B6D7BDBC0BC9F52BA21E626B1B412AD67B570F801AEE5AEC` | 53,580 / 304 |
| `by-item/DrawTextRunCallback_00593DB0.md` | `8C984BF424EC8C59401D874A2898E27353812BFBDC23E1D5B91A7E854DE0D3F6` | 18,367 / 129 |
| `by-memory/-ignored.md` | `A5AD04AE4FBAA3FAE1D32A766365EC42EB02180147AB9A8BF3E9235A9B83AC7E` | 1,063,063 / 5,192 |
- Current generated `TextEditPane.cpp` readback is external validator command/header `000000014859`, refreshed `2026-07-20T02:33:55-04:00`, SHA256 `F5D885E5E6CD3DD74071167B440CC012B5AE63CC3C7CAA1641DB57C9C5730360`, 32,999 bytes / 924 lines. The complete B001/B003/B004/B005 union is same-or-greater: exactly one UID trace/definition each for UID00030C `OnDraw`, UID0004T1 `BuildTextRangeRectangles`, UID0004T2 `GetLineIndexForY`, UID00030D `InvalidateTextRegion`, and UID0004T8 `PutScrapToClipboard`; one constructor, `EncodeState`, ordinary destructor, and `ReleaseFormatObjects` definition; one DrawTextRunCallback definition plus one prototype; and one PutScrapToClipboard definition plus one prototype. UID00030C/UID0004T1/UID0004T2/UID0004T8 empty-marker counts are zero. Six remaining Empty Emitter Markers belong only to unrelated UID0001JM/UID00030F/UID00030E/UID0003N0/UID0001JP/UID0001JS split debt. B004 tokens remain exact, while the additive B005 helper contains `DuplicateText`, `DuplicatePayload`, CR-to-CRLF normalization, `CP_ACP`, `GMEM_DDESHARE`, and `CF_TEXT`; zero `sub_5917D0`, `m_renderMode`, `g_pfnFillOrInvalidateRect`, `dword_69B3FC`, cookie/SEH/vftable/operator-delete/manual-List-destructor artifacts occur.
- B004's authorized waited implementation checkpoint remains command/header `000000014758`, refreshed `2026-07-20T00:00:51-04:00`, SHA256 `EBCEA2848219CE3A008603696AD4EDBECAE27457AE3D360777E05EF9BADA2EF2`, 31,008 bytes / 857 lines. External commands 14789, B005 waited 14814, external 14817, historical post-B005 command 14831/SHA256 `63C7133189FDEAA66388453ADF6B9FBB6C992E798D393993EB2F85B40B2CD1F1`, historical command 14846/SHA256 `C4369776AB3F6D20A724935B1CED076BAB203F7A5E761CBF4BB67B397F533246`, and historical command 14857/SHA256 `E862DFAC1D15EC7053CD455388F60B8C47C3C12DD52890975CBDA92B3723143D` successively superseded that generated snapshot; current command 14859 supersedes all of them while preserving every scoped B004 assertion. Commands 14655, 14661, 14667, 14702, and pre-callback 14732 are earlier historical checkpoints.
- Current tracker authority is external validator header/command `000000014859`, refreshed `2026-07-20T02:33:55-04:00`, SHA256 `5082C2A587D24DED39F4C6908EA561FE6E06920C50ED63B5F9022B21657597CB`, 1,517,620 bytes / 6,158 lines. UID00030C/UID0004T1/UID0004T2 remain consecutive at lines 3,232-3,234 with `92/94`, combined `93.0`, reconstructable true, zero direct reports, and blank external lifecycle fields. UID00030D/UID0004T8 remain consecutive at lines 3,021-3,022 with `91/93`, combined `92.0`, reconstructable true, zero direct reports, and blank external lifecycle fields. Support rows retain UID0000EO `93/94`, UID0000ON `93/93`, UID0000TN `89/86`, and UID0000UK `91/91`; historical command 14857/SHA256 `63DED0512383825D29D170252D72040A97DA693D736AD2697AEF8260A6199DEF`, command 14851/SHA256 `816C1C4ECA3861171A19DE3037E285DC40B14E93652854B5AA5A23A85E4AFCE4`, historical post-B005 command 14835/SHA256 `BED461DA500A5FAA3CC48BADC187A0E040B04061F72F40D757488087B0DFC75D`, commands 14794/14791/14784/14768/14767, B004 callback command 14758, and 14733 are historical tracker checkpoints.
- Current supervisor-owned manual checkpoints, reread after command 14859 and unchanged from the command-14857 rebase, are by-memory SHA256 `648C96BC0CF3AC950310399BBB69ADDCF9D955035B314F6C57FF263A6CF9690E`, 1,815,581 bytes / 4,327 lines; by-class SHA256 `CF71F86225D5A027627EE50C49236C7C0A1863DD622C6845F1698B2C059C864C`, 235,871 / 623; by-file SHA256 `22316E877291B68B3D0AA99ECD5CB1C6457E0EBB71B7FEC4E222CE5E1665297B`, 134,565 / 316; by-global SHA256 `B1D9DE82100DEFA76A964C097A808F0DAC6781CF4D51F6D670000F21B6AC3357`, 90,593 / 213; and unchanged by-item command-14782 SHA256 `66C86AAFBA920F09B29B5E6C5B1C5E477255362F2A4A2A009402DA8428079EA6`, 28,963 / 87. B004 rows remain unique and exact at by-memory lines 3,295, 3,302, 3,307, 3,308, 3,309, 3,314, 3,315, and 3,317; class/file/global/item lines remain 550/284/194/43. B005 adds UID0001JO/UID0004T8 and padding at lines 3,305/3,310-3,312; the current file row is same-or-greater and explicitly preserves the final UID00030C draw union. Commands 14778-14782 and the prior post-B005, UserStatusPane, and command-14847-14851-era coverage hashes remain historical provenance below.
- The current whole-file coverage drift is unrelated WorldMap synchronization, recorded separately from TextEdit evidence: by-memory preserves WorldMapPane executable/source rows at lines 3,716-3,730, the read-only-data parent and exact children at lines 4,024-4,027, and storage UID00029E at line 4,229; by-class preserves UID0000G8/UID0000G9/UID0000GA at lines 605-607; by-file preserves UID0000PB at line 307; by-global adds unique UID0004T9 `g_pWorldMapPane` at line 159; by-item has no WorldMap row. None alters a TextEdit row, ordinary destination hash, formal, score, or generated assertion.
- B001/B003/B004 shared implementation and the additive executed B005 UID000478 union remain preserved in current ordinary/generated/manual files. B004 reread every affected shared destination and external output for this bounded reconciliation; hashes are evidence-time facts rather than indefinite availability claims.
- B004 manual coverage application/validation is historically complete under supervisor commands 14778-14782 and remains incorporated at same-or-greater detail through the current externally advanced manual snapshot. Exact report validation/execution/archive/count state remains external supervisor/validator-owned and authoritative only in external audit/history; this artifact neither asserts nor directs a lifecycle outcome.

## Executive Recommendation

- Emit the exact OnDraw source in Destination 1. The body is ordinary project source, not a wrapper, compiler helper, retained inline duplicate, no-route island, or data entry.
- The two exact source helpers were registered serially before cross-linking: Destination 2 closes rectangle construction and Destination 3 closes visible-line lookup. Both now have real validator-issued UIDs, ordinary callers, stable ABI, exact bodies, and no source/compiler ambiguity.
- Destinations 4-9 are installed as complete no-loss formal values. Destinations 10-15 synchronize prose, split indexes, padding, callback mirror, and source route without turning mixed aggregates into emitters.
- Preserve the finalized B001 serialization and B003 destructor/helper/signed-record/vtable union by full destination rereads and same-or-greater incorporation.

## Supervisor Active Recheck

- Direct-report search found no prior direct UID00030C target artifact and no active duplicate assignment.
- The canonical B004 lease file showed no live B004 lease. Its displayed entries are stale 2026-06-18 Supervisor rows and are not active B004 ownership.
- B001 UID0001JN, B003 UID0002ZZ, and B005 UID000478 are finalized supervisor-executed predecessor/coordination artifacts, not active callback owners. None owns UID00030C; their accepted class/file/aggregate/helper deltas are required current baseline facts.
- The historical pre-callback freshness reread used external generated command 14732, tracker command 14733, and manual commands 14712/14713/14720/14704. Their scoped TextEdit semantics and rows preserved the accepted predecessor union. Historical post-B005 reconciliation used generated command 14831 and tracker/execution command 14835; commands 14846/14851 and 14857 are later historical generated/tracker authorities. This final artifact rebase uses current external generated/tracker command 14859 and the current manual hashes recorded in Current Target State; B004's waited command 14758 remains its implementation proof, and every later epoch preserves the complete scoped UID00030C union.
- Supervisor authorized the implementation callback against exact report SHA `2B5A2840ED3C3699E67B7C29207E3C8B4B850F87A29CC7CF69647F062EC83473`; B004 completed it and preserved the predecessor union. Exact reconciled SHA `585EEFFDF3BCE85F22D537AED854F0FC2E370F9EBAADD1864F4AA3FC98FCC3D1` historically failed fresh Gate 1 while B005 was advancing the shared lane, and exact SHA `198DA52004DD4A93C2FEFC553AEBB0B0C3750951E2B6975B6AA7C05C47494134` later failed fresh Gate 1 only for stale external authorities and pre-registration planning language. B005's command-14835 execution and commands 14846/14851/14857 are historical; this bounded command-14859 same-or-greater rebase closes the remaining artifact defect without an ordinary implementation change or predecessor wait.

## Inference Research Guidance Check

- Binary facts and inferred source spellings are separated. Exact bytes, offsets, calls, branches, and storage widths are facts. `BuildTextRangeRectangles`, `GetLineIndexForY`, and flag labels are strongest source-facing names, not recovered symbols.
- Current-call equivalence was not used as full-domain proof. Signed selection comparisons are retained as signed `short`; flag tests remain unsigned masks; Y arithmetic remains signed `int`; List elements remain by-value 16-byte rectangles.
- No decompiler labels, raw offsets, vtable arithmetic, security-cookie code, EH registrations, manual destructor calls, or reverse-engineering comments appear in formal C++.
- The no-code alternative was tested and rejected: the target is a nine-vtable-entry virtual method with ordinary source control flow and project helper calls.

## Heuristic / Inference Reanalysis And Validation

| Question | Controls checked | Resolution |
| --- | --- | --- |
| Method identity | Nine primary-vtable slot references, class declaration, old report lead, neighboring virtuals | `TextEditPane::OnDraw`, `void`, no explicit arguments |
| Draw state | GrafPort accepted docs and calls at `0x004b9660/0x004b96c0` | inherited `m_drawMode`, `m_drawColor`, `SetDrawColor`, `GetClipRect` |
| Slot `0x0069b3fc` | Surface initializer/storage docs, installed RGB targets, 206 consumers, rectangle ABI | `g_pfnFillRect(GrafPort *, const RectBounds *)`; lock/load/invalidate aliases rejected |
| Flag `0x02` | target and DrawTextRunCallback background branches, TextBox constructor style use | black-background style |
| Flag `0x04` | OnKey mutation gates, OnDraw caret suppression, TextBox IME unregister behavior | read-only mode; stale `NoImeFocus` is incomplete |
| Flag `0x40` | callback-state boolean and per-run color branch | use current/uniform text color rather than run colors |
| Flag `0x80` | OnMouse entry gate and OnDraw selection/caret gate | interactive selection/input enable |
| Line lookup | three xrefs, 16-byte line records, binary search over current/next tops | `short GetLineIndexForY(int y) const` |
| Range rectangles | three callers, Point `{y,x}`, one/multi-line branches, List append ABI | `void BuildTextRangeRectangles(short, short, List *) const` |
| Selection container | exact List ctor `(16,16)`, count, GetElementAt, automatic cleanup | automatic `List` of `RectBounds`, not vector/array/resource storage |
| Selection operation | accepted CompositePixels report and per-rectangle call | `CompositePixels`, not a target-local pixel/resource argument |
| Callback state | two 16-byte rectangles plus bool, zero-initialized before iteration | complete `TextRunDrawState` belongs in shared declaration before OnDraw |
| Source placement | constructor, class, callbacks, vtables, generated route | `NexusTK/ui/controls/TextEditPane.cpp` via class emitter UID0000EO |

## Evidence Standards Used

- Current live IDA MCP facts from session `9b0396a3` with `database` supplied on every IDB tool call.
- Local PE bytes from `E:/NTK/Resources/NexusTK/NexusTK.exe`, mapped through image base `0x00400000` and `.text` raw/RVA relation.
- Current ordinary docs and complete managed blocks, not generated prose alone.
- Executed accepted reports used as support only; finalized B001/B003 artifacts and current destination bytes were treated as settled no-loss baseline evidence, not as substitutes for UID00030C target proof.
- Current generated and manual coverage files read-only; neither is implementation authority over direct binary evidence.

## Evidence Checked

- Fresh MCP `idb_list` returned one active NexusTK session `9b0396a3`, PID/worker PID `15732`, `is_analyzing:false`.
- `server_health(database=9b0396a3)` returned `status:ok`, module `NexusTK.exe`, image base `0x00400000`, auto-analysis/Hex-Rays/string cache ready, cache size 2,067.
- Valid bounded `lookup_funcs(0x00590810)` returned `sub_590810`, size `0x1d3`; valid bounded `get_bytes(0x00590810,16)` returned `55 8b ec 6a ff 68 b3 97 60 00 64 a1 00 00 00 00`.
- The current-state rebase repeated `idb_list`, `server_health`, `lookup_funcs(0x00590810)`, and `get_bytes(0x00590810,16)` through transport session `9a40248b-ddf9-48d2-9819-13b5cd918326`; IDB session `9b0396a3` remained the sole active NexusTK database, health remained `ok`, and the function/range/prologue results were unchanged. This documentation rebase introduced no binary contradiction.
- `analyze_function` was run for target `0x00590810`, rectangle helper `0x00591520`, line helper `0x00592bb0`, TextBox comparators `0x00591300/0x00591370`, and UID00030D `0x00591740`.
- Target current docs, all Destinations 1-15, verify-only GrafPort/List/RectBounds/CompositePixels/GetClipRect/Surface-storage pages, generated `TextEditPane.cpp`, tracker, and affected manual coverage rows were opened.
- The historical final report-only freshness pass reopened generated `TextEditPane.cpp` at external command/header 14732 and tracker command/header 14733, then B004 command 14758 established the implementation checkpoint. Later 14767/14768/14784/14791/14794/14851/14857 tracker, 14789/14846/14857 generated, and post-B005 commands 14831/14835 are historical. This final bounded pass opened executed UID000478 SHA `5AFC5092...98AE`, every affected ordinary destination, generated/tracker command 14859, and all five current manual coverage roots; it confirmed the complete B001/B003/B004/B005 union at same-or-greater detail and classified the non-TextEdit manual drift as unrelated WorldMap synchronization.
- Prior-report terms and roots listed in Supporting Research were searched. Relevant executed/active paths were opened and classified; Older-Research, SpecialReports, and archive roots yielded explicit no-direct-report results.
- One invalid local `get_bytes` wrapper request used `address` instead of schema key `addr`; it was a client-argument error, not an MCP outage. The corrected valid bounded call succeeded and controls this report.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C30C-001 | Target is exact `[0x00590810,0x005909e3)`, 467 bytes. | very strong | IDA size, PE mapping/hash | D1 UID00030C / validator 14736 | incorporate | applied |
| C30C-002 | Target bytes hash to `5886CF08...FC85` and occur once in the local PE. | very strong | local PE full-range scan | D1 binary evidence / 14736 | incorporate | applied |
| C30C-003 | Source ABI is `virtual void TextEditPane::OnDraw()` with no explicit arguments. | very strong | thiscall body, plain ret, vtable slot | D1/D4 / 14736/14737 | incorporate | applied |
| C30C-004 | Target has 19 blocks, cyclomatic 7, 168 instructions, no strings/resources. | very strong | MCP analyze/disasm | D1 evidence / 14736 | incorporate | applied |
| C30C-005 | Nine primary-vtable `+0x6c` cells route to the same inherited OnDraw implementation. | very strong | nine exact data xrefs | D1/D4/D10 / 14736/14737/14751 | incorporate | applied |
| C30C-006 | Owner/emitter UID0000EO and file UID0000ON are correct. | very strong | class/vtable/generated route | D1/D4/D10 / 14736/14737/14751 | already-present | already-present |
| C30C-007 | `m_drawMode`, `m_drawColor`, `m_bounds`, `m_textColor`, and `m_textBackColor` are inherited/current fields. | very strong | accepted GrafPort/class docs and offsets | D1/D4 / 14736/14737 | incorporate | applied |
| C30C-008 | Flag `0x02` selects black rather than configured background. | very strong | target/callback branches | D1/D5/D6 / 14736/14738/14739 | incorporate | applied |
| C30C-009 | OnDraw saves color, sets mode zero, fills bounds, then restores color. | very strong | exact instruction/call order | D1 / 14736 | incorporate | applied |
| C30C-010 | Slot `0x0069b3fc` is exact `g_pfnFillRect`, not lock/load/invalidate. | very strong | storage/initializer/consumer ABI | D1/D6/D9/D13 / 14736/14739/14746/14755 | incorporate | applied |
| C30C-011 | Visible last line uses `clip.bottom - m_textAreaTop - 1`. | very strong | target decompile/disasm | D1 / 14736 | incorporate | applied |
| C30C-012 | Visible first line uses `clip.top - m_textAreaTop`. | very strong | target decompile/disasm | D1 / 14736 | incorporate | applied |
| C30C-013 | `0x00592bb0` is a signed-short line index binary search over current/next line tops. | very strong | helper decompile, three xrefs | D3/D4/D12 / 14735/14737/14754 | incorporate | applied |
| C30C-014 | Empty/invalid clip suppresses text-run iteration only. | very strong | target CFG and Rect helper | D1 / 14736 | incorporate | applied |
| C30C-015 | Draw state is two RectBounds plus one bool, zero-initialized. | very strong | stack layout and callback ABI | D1/D4/D6 / 14736/14737/14739 | incorporate | applied |
| C30C-016 | Flag `0x40` controls whether callback applies each run's text color. | strong | target writes boolean, callback consumes it | D1/D5/D6 / 14736/14738/14739 | incorporate | applied |
| C30C-017 | `IterateTextRuns(first,last,DrawTextRunCallback,&state)` is exact. | very strong | address-taking xref and callback ABI | D1/D4/D6/D12 / 14736/14737/14739/14754 | incorporate | applied |
| C30C-018 | Flag `0x80` gates all selection/caret drawing and mouse interaction. | very strong | OnDraw/OnMouse controls | D1/D5 / 14736/14738 | incorporate | applied |
| C30C-019 | Selection endpoints at `+0x144/+0x146` are signed `short`. | very strong | signed compare, class union | D1/D4 / 14736/14737 | incorporate | applied |
| C30C-020 | Noncollapsed selection uses automatic `List(sizeof(RectBounds),16)`. | very strong | List ctor/count/get/cleanup | D1/D8 / 14736/14744 | incorporate | applied |
| C30C-021 | `0x00591520` normalizes endpoints and builds one to three exact rectangles. | very strong | helper body and three callers | D2/D4/D7/D8/D11 / 14734/14737/14741/14744/14752 | incorporate | applied |
| C30C-022 | Range helper source return is `void`; decompiler EAX is final Append residue. | strong | all callers ignore return, List Append void | D2/D4 / 14734/14737 | incorporate | applied |
| C30C-023 | Selection rectangles are passed to inherited `CompositePixels`. | very strong | target call and accepted helper | D1/D8 / 14736/14744 | incorporate | applied |
| C30C-024 | Collapsed caret branch runs only when interactive and not read-only. | very strong | exact flag CFG | D1 / 14736 | incorporate | applied |
| C30C-025 | Flag `0x04` is read-only; `NoImeFocus` is a partial historical label. | strong | OnKey, OnDraw, TextBox IME controls | D1/D5 / 14736/14738 | incorporate | applied |
| C30C-026 | `GetCaretLocalPoint(Point *, short)` uses project Point `{y,x}`. | very strong | helper contract and RectBounds layout | D1/D2/D7 / 14736/14734/14741 | already-present | already-present |
| C30C-027 | Caret left decrements only when text-area left is less than x; right stays x+1. | very strong | target and `0x00591300` | D1/D7 / 14736/14741 | incorporate | applied |
| C30C-028 | Caret bottom is y plus line height; final color is `m_textColor`. | very strong | target calls/fields | D1 / 14736 | incorporate | applied |
| C30C-029 | Caret branch intentionally does not restore the prior draw color. | very strong | terminal call/return order | D1 history/behavior / 14736 | incorporate | applied |
| C30C-030 | Target owns no resource, palette, pixel buffer, or external selection allocation. | very strong | no strings/globals beyond slot, automatic List | D1 negative evidence / 14736 | reject | excluded-with-reason |
| C30C-031 | Predecessor `[0x00590804,0x00590810)` is 12 `0xcc` bytes. | very strong | PE bytes/hash | D15 ignored ledger / 14757 | incorporate | applied |
| C30C-032 | Successor `[0x005909e3,0x005909f0)` is 13 `0xcc` bytes. | very strong | PE bytes/hash | D15 ignored ledger / 14757 | incorporate | applied |
| C30C-033 | Target score should be `92/94`; other target metadata remains exact. | strong | blocker closure and lexical cap | D1 metadata / 14736 | incorporate | applied |
| C30C-034 | New rectangle-helper child is `92/94`, owner/emitter UID0000EO, Nested 0. | strong | exact body/callers/current sibling delta | D2 UID0004T1 / 14734 | incorporate | applied |
| C30C-035 | New line-helper child is `92/94`, owner/emitter UID0000EO, Nested 0. | strong | exact body/callers/current sibling delta | D3 UID0004T2 / 14735 | incorporate | applied |
| C30C-036 | Class must define TextRunDrawState before OnDraw and declare both private helpers. | very strong | source order/complete-type requirement | D4 / 14737 | incorporate | applied |
| C30C-037 | Constructor constants must use shared draw flags and rename flag 4 to read-only. | strong | cross-method semantics | D5 / 14738 | incorporate | applied |
| C30C-038 | Draw callback must use `m_drawMode` and `g_pfnFillRect` and not redeclare draw state. | very strong | accepted field/global contracts | D6 / 14739 | incorporate | applied |
| C30C-039 | TextBox comparator bodies require no-loss helper/type/container rebase. | very strong | direct comparator MCP | D7 / 14741 | incorporate | applied |
| C30C-040 | UID00030D shares the solved rectangle/List contract and is source-ready at `91/93`. | very strong | body-equivalent helper loop | D8 / 14744 | incorporate | applied |
| C30C-041 | File and three aggregates remain source indexes; mixed aggregate formals stay blank. | very strong | range inventories and source split | D10-D12 / 14751-14754 | incorporate | applied |
| C30C-042 | Surface global may add exact slot-7 declaration without changing broader score/slots. | very strong | existing slot evidence and target consumer | D9/D13 / 14746/14755 | incorporate | applied |
| C30C-043 | Callback item mirror is prose-only support; its no-signature-blocker text is stale. | strong | UID0001JR current formal | D14 / 14756 | incorporate | applied |
| C30C-044 | Finalized B001/B003 work and additive executed B005 UID000478 shared work require same-or-greater preservation, with no active predecessor wait remaining. | very strong | executed artifacts, current ordinary union, generated 14859 | report and D4/D10-D12 | incorporate | applied |
| C30C-045 | Expected generated state is one target plus two B004 helper definitions, corrected callback tokens, no target marker, no duplicate source, unchanged serializer/destructor/private-helper definitions, and additive B005 UID0004T8 without B004 regression. | strong | command-14758 implementation readback; historical 14831/14846/14857; current external command 14859 union | final waited/current assertions | incorporate | applied |
| C30C-046 | Exact B004 manual rows are supervisor-owned; registered real-UID text was applied under commands 14778-14782 and remains exact or same-or-greater through the current WorldMap-advanced manual snapshot without a B004 manual edit. | very strong | historical commands, current hashes, unique row audit | applied coverage rows/checklist | incorporate | applied |

## Positive Evidence Summary

- Exact unique project-code body with standard `thiscall` method prologue, 19-block control flow, source helper calls, automatic List lifetime, and ordinary return.
- Nine class-primary-vtable cells all point to `0x00590810` at the same `+0x6c` slot: ClanInfoListPane `0x00615664`, SelfSaveOKPane `0x0061e810`, GroupListPane `0x00624280`, SpelledPane `0x00624334`, LegendPane `0x006243f4`, TextEditPane `0x0062e000`, TextBoxPane `0x0062e0dc`, MoreInfoPane `0x0062edc4`, and ProfilePane `0x0062ee78`.
- Every target field is already part of the accepted TextEditPane/GrafPort union: bounds `+0x44`, mode `+0x70`, draw color `+0x74`, text color `+0x7c`, background color `+0x80`, text area left/top/right `+0x120/+0x124/+0x128`, selection words `+0x144/+0x146`, and editor flags `+0x15c`.
- Exact helpers have coherent multiple-consumer contracts: `0x00591520` has target, TextBox invalidation, and UID00030D callers; `0x00592bb0` has coordinate conversion plus two target calls.
- Callback address `0x00593db0` is taken directly at `0x005908e6`, and its accepted ABI consumes the exact stack state constructed by the target.
- Surface slot 7 is a heavily live fixed global populated by both compat and RGB565 initializers and called with receiver plus one `RectBounds *` by this target and many pane/render consumers.

## IDA MCP Facts

- Session: `9b0396a3`; worker PID 15732; live health `ok`; image base `0x00400000`; Hex-Rays, auto-analysis, and strings ready.
- Target: `sub_590810`, size `0x1d3`, 19 basic blocks, cyclomatic complexity 7, 168 instructions, no strings, no ordinary direct callers, nine data/vtable xrefs.
- Target callees: `0x004b9660`, `0x004baaa0`, `0x004b7eb0`, `0x004f3060`, global `0x0069b3fc`, `0x0058f740`, `0x00592bb0`, `0x004ba540`, security check, `0x00593500`, `0x004f30e0`, `0x004f32b0`, `0x00591520`, and `0x004b96c0`.
- `0x00591520`: size `0x119`, 8 blocks/cyclomatic 4, callers `0x00590810`, `0x00591370`, `0x00591740`; helper calls caret mapping, RectBounds initialization, line height, and List virtual Append.
- `0x00592bb0`: size `0x70`, 9 blocks/cyclomatic 5, xrefs `0x0058f6e9`, `0x0059088c`, `0x005908a0`; binary-searches current and next line tops.
- `0x00591300`: size `0x6a`, exact caret rectangle and InvalidateRect virtual call; `0x00591370`: size `0x89`, exact List/range-rect/InvalidateRect loop; `0x00591740`: size `0x89`, same List/range-rect loop with CompositePixels.
- Compiler-only target artifacts are SEH registration, security-cookie setup/check, stack zeroing lowerings, and the automatic List cleanup funclet at `0x006097ab` with handler at `0x006097b3`. None belongs in human source.

## Function / Child Inventory

| Range/address | Classification | Source disposition |
| --- | --- | --- |
| `0x00590804-0x00590810` | 12-byte alignment | ignored compiler padding, no source body |
| `0x00590810-0x005909e3` | exact modeled virtual | Destination 1 `TextEditPane::OnDraw` |
| `0x005909e3-0x005909f0` | 13-byte alignment | ignored compiler padding, no source body |
| `0x005909f0-0x00590dc5` | existing sibling UID00030F | verify-only, no target ownership |
| `0x00591300-0x0059136a` | existing TextBox method | Destination 7 no-loss source cleanup |
| `0x00591370-0x005913f9` | existing TextBox method | Destination 7 no-loss source cleanup |
| `0x00591520-0x00591639` | exact modeled helper | Destination 2 new exact child |
| `0x00591740-0x005917c9` | existing UID00030D | Destination 8 source closure |
| `0x00592bb0-0x00592c20` | exact modeled helper | Destination 3 new exact child |
| `0x00593500-0x005936d9` | existing iterator inside UID0001JP | support contract, aggregate stays blank |
| `0x00593db0-0x00593ef5` | existing UID0001JR callback | Destination 6 exact token/state rebase |

- Registered child [UID:0004T1] means only exact `0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles.md`; validator command 14734 assigned it serially before dependent cross-links.
- Registered child [UID:0004T2] means only exact `0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY.md`; validator command 14735 assigned it serially after UID0004T1 and before dependent cross-links.
- Historical pre-registration drafts used temporary UID tokens only as templates. Registration is complete: commands 14734 and 14735 issued real UIDs 0004T1 and 0004T2 serially, every temporary token was replaced before dependent cross-link validation, and both exact child pages are current.

## Direct Xref / Caller Inventory

- Target direct callers: none. This is positive virtual-dispatch evidence, not a liveness failure.
- Target vtable/data routes: the nine exact cells listed under Positive Evidence Summary.
- Draw callback route: address push at `0x005908e6`, then call to `0x00593500`; sibling raw callback route at `0x0059168c` is separate support evidence.
- Rectangle helper callers: `0x00590943` in OnDraw, `0x005913b9` in TextBoxPane::InvalidateLineRange, and `0x00591789` in TextEditPane::InvalidateTextRegion.
- Line helper callers: `0x0058f6e9` in coordinate-to-caret logic and target calls `0x0059088c/0x005908a0`.
- Surface slot 7 target uses: background fill at `0x00590864` and caret fill at `0x005909c2`; callback use at `0x00593e3c`.

## Documentation Evidence And IDA Status

- Historical pre-callback UID00030C retained the exact identity/range/owner but had a blank formal and blocker prose. Current UID00030C retains that identity/range/owner with the accepted source-ready Destination 1 body and historicalized blocker text.
- Current TextEditPane class/file formals are the no-loss base. Destination 4 preserves all current constructor, callback, serialization, destructor/helper, fields, friends, and sibling declarations and adds only target-required declarations/state placement.
- Finalized B003 work created UID0004T0 `TextEditPaneReleaseFormatObjects`, the ordinary destructor, signed record field, and compiler-vtable disposition; finalized B001 work added source-ready UID0001JN `EncodeState`, corrected class/file/aggregate prose, wrapper/mirror detail, and adjacent ignored padding. All are current baseline content rather than concurrent proposals.
- Destination 4 was mechanically rebased against historical pre-callback class SHA `29D5240A...53B4`: after accounting only for the intended replacement of `struct TextRunDrawState;` with its complete definition and insertion of the two new private declarations, every managed line remained in the same order. Current class SHA `258763ED...EE71` preserves that complete block exactly. The current `EncodeState(unsigned short *outSize) const`, ordinary destructor, `ReleaseFormatObjects`, signed record, fields, friends, and unrelated declarations are not pruned.
- Historical pre-callback generated command 14732 is read-only evidence of the settled pre-UID00030C implementation state, not a command run by B004 and not a durable post-callback authority; command 14702 is retained only as the historical B001 predecessor checkpoint. B004 waited callback command 14758 is the exact historical implementation checkpoint, external commands 14831, 14846, and 14857 are later historical evidence, and external command 14859 is the current generated authority recorded below.

## Ranked Ownership Analysis

1. **TextEditPane class UID0000EO / TextEditPane.cpp UID0000ON**: exact vtable slot, fields, callbacks, helper corridor, and generated route. Accepted.
2. **GrafPort**: owns inherited drawing primitives and state, but target reads TextEditPane fields and calls private editor helpers. Dependency only.
3. **Surface**: owns `g_pfnFillRect` provider declaration/targets, but not the editor draw policy. Dependency only.
4. **TextBoxPane or derived panes**: inherit the target implementation through their vtables; no distinct target body ownership. Rejected as direct owner.
5. **DrawTextRunCallback**: file-local callback invoked by target, not target owner. Rejected as direct owner.

## Source Placement

- Human definitions for Destinations 1-3 and 8 belong in `NexusTK/ui/controls/TextEditPane.cpp` and emit through UID0000EO.
- Destination 4 is the complete TextEditPane declaration/header union already routed through UID0000ON.
- Destination 6 remains a file-local callback in TextEditPane.cpp.
- Destination 7 remains TextBoxPane source under its current owner/emitter; only shared helper/type names are synchronized.
- Destination 9 belongs to Surface source at existing emitter position 20; it declares the slot and does not move installed callback targets.
- The two alignment gaps belong only to `by-memory/-ignored.md` and manual coverage handoff.

## Range / Split / Padding / Reclassification Analysis

- Target bounds are exact. The old historical endpoint beyond `0x005909e3` is rejected because 13 `0xcc` bytes precede the modeled sibling at `0x005909f0`.
- Local PE is 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. Target RVA is `0x00190810`, raw offset `0x0018fc10` under image base `0x00400000` and `.text` mapping.
- Target SHA256 is `5886CF08D0EA0F4FE8577C40611DA1FF1A995B009757C528B48C2900D38EFC85`; the exact sequence occurs once. First 32 bytes are `55 8B EC 6A FF 68 B3 97 60 00 64 A1 00 00 00 00 50 83 EC 68 A1 24 2F 67 00 33 C5 89 45 F0 56 57`; final 32 are `15 FC B3 69 00 8B 4D F4 64 89 0D 00 00 00 00 59 5F 5E 8B 4D F0 33 CD E8 50 6D 03 00 8B E5 5D C3`.
- Pre-padding hash is `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`; post-padding hash is `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`.
- Destination 2 uses exact modeled `[0x00591520,0x00591639)`, separate from raw pockets `0x005914d0-0x0059151f` and `0x00591640-0x0059173f`; it does not reclassify either raw pocket.
- Destination 3 uses exact modeled `[0x00592bb0,0x00592c20)`, after existing five-byte `0xcc` alignment and before the next exact function.
- Both new pages use `Nested:0`, matching the current address-sorted sibling delta at their insertion points and avoiding any cumulative indentation shift to existing successors.
- UID0001JM, UID0003N0, and UID0001JP remain mixed/index pages with blank formals. New children reduce their unresolved inventory but do not make broad aggregates valid emitters.

## Negative Evidence Summary

- No ordinary direct caller exists; nine vtable cells prove liveness.
- No strings, resources, packet data, file I/O, allocation beyond automatic List storage, or target-owned global data exist.
- No evidence supports `OnPaint`, `Draw`, `Render`, a free callback, or a constructor/destructor identity over `OnDraw`.
- No evidence supports unsigned selection endpoints; the target uses signed comparison.
- No evidence supports `std::vector`, fixed array, Region, or custom target-local rectangle type; exact List ABI is present.
- No evidence supports `g_pfnLockSurface`, `g_pfnLoadSurface`, `RefreshPaneRegion`, or `g_pfnFillOrInvalidateRect`; slot targets and ABI are FillRect.
- No evidence supports writing security cookies, vptrs, SEH nodes, cleanup funclets, raw offsets, or manual List destruction in source.
- No evidence supports restoring draw color after the caret fill; adding such a restore would change exact behavior.

## IDA Rename / Type / Comment Recommendations

- Rename `sub_590810` to `TextEditPane__OnDraw` only if a later authorized IDA mutation pass exists; this report performs no IDA mutation.
- Rename `sub_591520` to `TextEditPane__BuildTextRangeRectangles` and type it `void __thiscall(TextEditPane *, short, short, List *)` in a later authorized IDA pass.
- Rename `sub_592BB0` to `TextEditPane__GetLineIndexForY` and type it `short __thiscall(const TextEditPane *, int)` in a later authorized IDA pass.
- Type `0x0069b3fc` as `SurfaceFillRectProc`; preserve all other callback-table slots.
- Use comments only for exact behavior facts in docs. Do not add decompiler variable names, offsets, or speculative original-symbol claims to formal C++.

## First-Draft C++ Recommendation

### Destination 1 - UID00030C Target

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TextEditPane::OnDraw()
{
    const unsigned int oldDrawColor = m_drawColor;
    m_drawMode = 0;
    SetDrawColor((m_editorFlags & kTextEditBlackBackground) != 0
                     ? 0
                     : m_textBackColor);
    g_pfnFillRect(this, &m_bounds);
    SetDrawColor(oldDrawColor);

    RectBounds clipBounds;
    GetClipRect(&clipBounds);
    const short lastVisibleLine =
        GetLineIndexForY(clipBounds.bottom - m_textAreaTop - 1);
    const short firstVisibleLine =
        GetLineIndexForY(clipBounds.top - m_textAreaTop);

    GetClipRect(&clipBounds);
    if (!IsRectEmptyOrInvalid(&clipBounds)) {
        TextRunDrawState drawState = { 0 };
        drawState.applyRunTextColor =
            (m_editorFlags & kTextEditUseCurrentTextColor) == 0;
        IterateTextRuns(firstVisibleLine,
                        lastVisibleLine,
                        DrawTextRunCallback,
                        &drawState);
    }

    if ((m_editorFlags & kTextEditInteractive) == 0)
        return;

    if (m_selectionStart < m_selectionEnd) {
        List selectionRects(sizeof(RectBounds), 16);
        BuildTextRangeRectangles(m_selectionStart,
                                 m_selectionEnd,
                                 &selectionRects);
        for (int index = 0; index < selectionRects.GetCount(); ++index) {
            CompositePixels(static_cast<const RectBounds *>(
                selectionRects.GetElementAt(index)));
        }
        return;
    }

    if ((m_editorFlags & kTextEditReadOnly) != 0)
        return;

    Point caretPoint;
    GetCaretLocalPoint(&caretPoint, m_selectionStart);

    RectBounds caretBounds;
    caretBounds.left = caretPoint.x;
    if (m_textAreaLeft < caretPoint.x)
        --caretBounds.left;
    caretBounds.top = caretPoint.y;
    caretBounds.right = caretPoint.x + 1;
    caretBounds.bottom = caretPoint.y + GetLineHeight();

    SetDrawColor(m_textColor);
    g_pfnFillRect(this, &caretBounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - Registered UID0004T1

Registered current path: `by-memory/0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles.md`. Historical pre-registration drafts used a temporary token; validator command 14734 issued UID0004T1 and every token was replaced before dependent validation.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TextEditPane::BuildTextRangeRectangles(short start,
                                            short end,
                                            List *rectangles) const
{
    if (end < start) {
        const short savedStart = start;
        start = end;
        end = savedStart;
    }

    Point startPoint;
    Point endPoint;
    GetCaretLocalPoint(&startPoint, start);
    GetCaretLocalPoint(&endPoint, end);

    RectBounds bounds;
    if (startPoint.y == endPoint.y) {
        bounds.left = startPoint.x;
        bounds.top = startPoint.y;
        bounds.right = endPoint.x;
        bounds.bottom = endPoint.y + GetLineHeight();
        rectangles->Append(1, &bounds);
        return;
    }

    bounds.left = startPoint.x;
    bounds.top = startPoint.y;
    bounds.right = m_textAreaRight;
    bounds.bottom = startPoint.y + GetLineHeight();
    rectangles->Append(1, &bounds);

    if (startPoint.y + GetLineHeight() < endPoint.y) {
        bounds.left = m_textAreaLeft;
        bounds.top = startPoint.y + GetLineHeight();
        bounds.right = m_textAreaRight;
        bounds.bottom = endPoint.y;
        rectangles->Append(1, &bounds);
    }

    bounds.left = m_textAreaLeft;
    bounds.top = endPoint.y;
    bounds.right = endPoint.x;
    bounds.bottom = endPoint.y + GetLineHeight();
    rectangles->Append(1, &bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - Registered UID0004T2

Registered current path: `by-memory/0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY.md`. Historical pre-registration drafts used a temporary token; validator command 14735 issued UID0004T2 and every token was replaced before dependent validation.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
short TextEditPane::GetLineIndexForY(int y) const
{
    short low = 0;
    short high = static_cast<short>(m_lineTable->GetCount() - 1);
    short lineIndex = 0;

    if (high <= 0)
        return 0;

    do {
        lineIndex = static_cast<short>((low + high) / 2);
        const TextEditLineRecord *line =
            static_cast<const TextEditLineRecord *>(
                m_lineTable->GetElementAt(lineIndex));
        if (line->top > y) {
            high = lineIndex;
        } else if (y < line[1].top) {
            return lineIndex;
        } else {
            low = static_cast<short>(lineIndex + 1);
        }
    } while (low < high);

    return lineIndex;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - Complete `by-class/TextEditPane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class List;
class TextEditObject;
class TextEditPane;
class TextEditScrap;
struct Point;
struct TextRunMeasureState;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}

struct TextEditLineRecord
{
    unsigned short startIndex;
    unsigned short reserved02;
    int top;
    int remainingWidth;
    unsigned short wrapState;
    unsigned short reserved0e;
};

struct TextRunFormatData
{
    unsigned short legacyAssetMode;
    unsigned short reserved02;
    unsigned int textColor;
    TextEditObject *object;
};

struct TextEditFormatRecord
{
    short referenceCount;
    unsigned short reserved02;
    TextRunFormatData format;
};

struct TextEditFormatRun
{
    unsigned short startIndex;
    short formatIndex;
};

struct TextRunMeasureState
{
    int availableWidth;
    int remainingWidth;
    int scratch;
};

struct TextRunDrawState
{
    RectBounds lineRect;
    RectBounds clippedLineRect;
    bool applyRunTextColor;
};

typedef bool (__cdecl *TextRunIteratorCallback)(TextEditLineRecord *line,
                                                const TextRunFormatData *format,
                                                const wchar_t *text,
                                                int textOffset,
                                                unsigned short charCount,
                                                unsigned short segmentFlags,
                                                void *context,
                                                TextEditPane *pane);

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane);

static bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                        const TextRunFormatData *format,
                                        const wchar_t *text,
                                        int textOffset,
                                        unsigned short charCount,
                                        unsigned short segmentFlags,
                                        void *context,
                                        TextEditPane *pane);

class TextEditPane : public ScrollablePane
{
public:
    TextEditPane(int viewportWidth,
                 int viewportHeight,
                 int textAreaWidth,
                 int textAreaHeight,
                 int textColor,
                 int textBackColor,
                 bool hasHorizontalScrollbar,
                 bool hasVerticalScrollbar,
                 unsigned int editorFlags,
                 unsigned short legacyAssetMode,
                 bool useDefaultAlignment,
                 bool useThousandsSeparator);
    virtual ~TextEditPane();

    short CopyWideText(wchar_t *outText, short capacity) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > GetText() const;
    short GetTextLength() const;
    void GetCaretRange(short *start, short *end) const;
    void GetCaretLocalPoint(Point *point, short caretIndex) const;
    unsigned char *EncodeState(unsigned short *outSize) const;
    void DecodeState(const unsigned char *data, unsigned short size);

    void InsertText(const wchar_t *text, int flags);
    void SetText(const wchar_t *text, short length, short selectStart, short selectEnd);
    void ClearText();
    void SetSelectionRange(short start, short end);
    void SelectAll();
    void ApplySelectionFormat(unsigned char formatMask, const void *formatData);
    void InsertEmbeddedObject(TextEditObject *object, int width, int height);
    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText();
    void SetEditActiveState(bool editActive, bool selectAll);
    bool IsEmpty() const;
    void ScrollToTop();
    unsigned char GetMode() const { return m_mode; }

    void PasteFromClipboard(TextEditScrap *scrap);
    short GetLineCount() const;
    void SetViewportBounds(const RectBounds *bounds);
    void GetTextAreaBounds(RectBounds *bounds) const;
    void SetTextAreaBounds(const RectBounds *bounds);
    virtual void OnDraw();

protected:
    virtual int OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);

    void InvalidateTextRegion(short start, short end);
    void DeleteSelection();
    void FindWordBoundary(short index, short *wordStart, short *wordEnd) const;
    void AutoScrollSelectionToPoint(int x, int y);

private:
    friend bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                               const TextRunFormatData *format,
                                               const wchar_t *text,
                                               int textOffset,
                                               unsigned short charCount,
                                               unsigned short segmentFlags,
                                               void *context,
                                               TextEditPane *pane);
    friend bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                            const TextRunFormatData *format,
                                            const wchar_t *text,
                                            int textOffset,
                                            unsigned short charCount,
                                            unsigned short segmentFlags,
                                            void *context,
                                            TextEditPane *pane);

    void ReleaseFormatObjects();
    void RebuildLineTable(short *firstLine, short *lastLine);
    void IterateTextRuns(short firstLine,
                         short lastLine,
                         TextRunIteratorCallback callback,
                         void *context);
    void RefreshTextRange(short start, short end);
    void ApplyFormatRange(short start,
                          short end,
                          unsigned char formatMask,
                          const TextRunFormatData *format);
    void LoadCurrentFormat();
    void BuildTextRangeRectangles(short start, short end, List *rectangles) const;
    short GetLineIndexForY(int y) const;

    int m_activeLineIndex;
    List *m_textStorage;
    List *m_lineTable;
    List *m_formatTable;
    List *m_formatRuns;
    short m_selectionStart;
    short m_selectionEnd;
    short m_savedSelectionStart;
    short m_savedSelectionEnd;
    TextRunFormatData m_currentFormat;
    bool m_dragSelectionActive;
    bool m_currentFormatValid;
    unsigned int m_editorFlags;
    unsigned char m_mouseMode;
    bool m_dirty;
    bool m_maskedText;
    short m_maxLength;
    short m_maxLines;
    unsigned short m_inputState;
    bool m_useDefaultAlignment;
    bool m_useThousandsSeparator;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - Complete UID0002ZY Constructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
const int kTextEditScrollbarSize = 12;
const unsigned int kTextEditPreserveActiveEditor = 0x104;
const unsigned int kTextEditBlackBackground = 0x02;
const unsigned int kTextEditApplyInitialColor = 0x20;
const unsigned int kTextEditReadOnly = 0x04;
const unsigned int kTextEditUseCurrentTextColor = 0x40;
const unsigned int kTextEditInteractive = 0x80;
const unsigned int kTextEditInitialStateFlags = 0x81;
const unsigned char kTextEditColorFormatMask = 2;
const unsigned char kTextEditCompleteFormatMask = 3;
const short kTextEditDefaultLimit = 30000;
}

TextEditPane::TextEditPane(int viewportWidth,
                           int viewportHeight,
                           int textAreaWidth,
                           int textAreaHeight,
                           int textColor,
                           int textBackColor,
                           bool hasHorizontalScrollbar,
                           bool hasVerticalScrollbar,
                           unsigned int editorFlags,
                           unsigned short legacyAssetMode,
                           bool useDefaultAlignment,
                           bool useThousandsSeparator)
    : ScrollablePane(hasHorizontalScrollbar, hasVerticalScrollbar)
{
    m_useThousandsSeparator = useThousandsSeparator;
    if ((editorFlags & kTextEditPreserveActiveEditor) == 0)
        g_pActiveTextEditPane = this;

    m_activeLineIndex = -1;
    m_useDefaultAlignment = useDefaultAlignment;
    if (!m_useDefaultAlignment)
        m_textAlignment = 2;

    m_inputState = 0;
    SetLegacyAssetMode(legacyAssetMode);

    m_textStorage = new List(sizeof(wchar_t), 128);

    m_lineTable = new List(sizeof(TextEditLineRecord), 16);
    TextEditLineRecord initialLines[2] = { 0 };
    m_lineTable->Append(2, initialLines);

    m_formatTable = new List(sizeof(TextEditFormatRecord), 16);
    TextEditFormatRecord initialFormat = { 0 };
    initialFormat.referenceCount = 1;
    initialFormat.format.legacyAssetMode = legacyAssetMode;
    initialFormat.format.textColor = textColor;
    initialFormat.format.object = NULL;
    m_formatTable->Append(1, &initialFormat);

    m_formatRuns = new List(sizeof(TextEditFormatRun), 16);
    TextEditFormatRun initialRuns[2] = {
        { 0, 0 },
        { 1, -1 }
    };
    m_formatRuns->Append(2, initialRuns);

    m_selectionStart = 0;
    m_selectionEnd = 0;

    short firstLine = 0;
    short lastLine = 0x7fff;
    RebuildLineTable(&firstLine, &lastLine);

    if (m_textAlignment != 0) {
        TextRunMeasureState state = {
            m_textAreaRight - m_textAreaLeft,
            0,
            0
        };
        IterateTextRuns(firstLine,
                        lastLine,
                        TextRunMeasureCallback,
                        &state);
    }

    RectBounds textArea = { 0, 0, textAreaWidth, textAreaHeight };
    SetTextAreaBounds(&textArea);

    RectBounds viewport = {
        0,
        0,
        viewportWidth - (hasVerticalScrollbar ? kTextEditScrollbarSize : 0),
        viewportHeight - (hasHorizontalScrollbar ? kTextEditScrollbarSize : 0)
    };
    const RectBounds oldBounds = m_bounds;
    LayoutScrollbars(&viewport);
    if (oldBounds.left == m_bounds.left &&
        oldBounds.top == m_bounds.top &&
        oldBounds.right == m_bounds.right &&
        oldBounds.bottom != m_bounds.bottom) {
        OffsetRect(&textArea, 0, m_bounds.bottom - oldBounds.bottom);
        SetTextAreaBounds(&textArea);
    }

    RefreshTextRange(m_selectionStart, m_selectionEnd);
    m_editorFlags = editorFlags | kTextEditInitialStateFlags;

    TextRunFormatData colorFormat = { 0 };
    colorFormat.textColor = textColor;
    if ((editorFlags & kTextEditApplyInitialColor) != 0) {
        ApplyFormatRange(0,
                         static_cast<short>(m_textStorage->GetCount()),
                         kTextEditColorFormatMask,
                         &colorFormat);
        m_currentFormatValid = false;
        RefreshTextRange(0, static_cast<short>(m_textStorage->GetCount()));
    } else if (m_selectionStart == m_selectionEnd) {
        LoadCurrentFormat();
        m_currentFormat.textColor = textColor;
        if (m_textStorage->GetCount() == 0) {
            ApplyFormatRange(0,
                             0,
                             kTextEditCompleteFormatMask,
                             &m_currentFormat);
        }
    } else {
        m_dirty = true;
        ApplyFormatRange(m_selectionStart,
                         m_selectionEnd,
                         kTextEditColorFormatMask,
                         &colorFormat);
        RefreshTextRange(m_selectionStart, m_selectionEnd);
    }

    m_maskedText = false;
    SetTextColor(textColor);
    SetTextBackColor(textBackColor);
    m_maxLength = kTextEditDefaultLimit;
    m_maxLines = kTextEditDefaultLimit;

    if (s_styledUnicodeClipboardFormat == 0) {
        s_styledUnicodeClipboardFormat =
            RegisterClipboardFormatW(L"Nexon.StyledUnicodeText");
        if (s_styledUnicodeClipboardFormat == 0)
            throw new Win32Error;
    }

    if ((m_editorFlags & kTextEditReadOnly) == 0) {
        SetFocusRegistration(true);
        g_pIMEPane->SetFocusPane(this, true);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - Complete UID0001JR DrawTextRunCallback

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum TextEditPaneTextAlignment
{
    kTextEditAlignLeft = 0,
    kTextEditAlignCenter = 1,
    kTextEditAlignRight = 2,
    kTextEditAlignTrimFinalWhitespace = 3
};

static bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                        const TextRunFormatData *format,
                                        const wchar_t *text,
                                        int textOffset,
                                        unsigned short charCount,
                                        unsigned short segmentFlags,
                                        void *context,
                                        TextEditPane *pane)
{
    (void)textOffset;
    TextRunDrawState *state = static_cast<TextRunDrawState *>(context);
    unsigned short visibleCount = charCount;

    if (segmentFlags <= kTextRunHasNextSegment) {
        state->lineRect.left = pane->m_textAreaLeft;
        state->lineRect.top = pane->m_textAreaTop + line->top;
        state->lineRect.right = pane->m_textAreaRight;
        state->lineRect.bottom = pane->m_textAreaTop + line[1].top;

        pane->GetClipRect(&state->clippedLineRect);
        IntersectRects(&state->clippedLineRect,
                       &state->lineRect,
                       &state->clippedLineRect);

        const unsigned int oldDrawColor = pane->m_drawColor;
        pane->m_drawMode = 0;
        pane->SetDrawColor((pane->m_editorFlags & kTextEditBlackBackground) == 0
                               ? pane->m_textBackColor
                               : 0);
        g_pfnFillRect(pane, &state->clippedLineRect);
        pane->SetDrawColor(oldDrawColor);

        int horizontalOffset = 0;
        if (pane->m_textAlignment == kTextEditAlignCenter)
            horizontalOffset = line->remainingWidth / 2;
        else if (pane->m_textAlignment == kTextEditAlignRight)
            horizontalOffset = line->remainingWidth;

        pane->MoveTo(state->lineRect.left + horizontalOffset,
                     state->lineRect.top + pane->GetLineHeight());
    }

    if (state->applyRunTextColor)
        pane->SetTextColor(format->textColor);

    if (format->object != NULL) {
        format->object->OnUpdate();
        return false;
    }

    if (pane->m_textAlignment == kTextEditAlignTrimFinalWhitespace &&
        (segmentFlags & kTextRunHasNextSegment) == 0) {
        visibleCount = static_cast<unsigned short>(
            AdjustVisibleCountForTrailingWhitespace(text, visibleCount));
    }

    pane->DrawTextRunSegment(text, visibleCount, 0, segmentFlags);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 7 - Complete UID0002RU TextBoxPane Comparator Block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TextBoxPane::EnsureCursorVisible()
{
    Point caretPoint;
    GetCaretLocalPoint(&caretPoint, m_selectionStart);

    RectBounds caretBounds;
    caretBounds.left = caretPoint.x;
    if (m_textAreaLeft < caretPoint.x)
        --caretBounds.left;
    caretBounds.top = caretPoint.y;
    caretBounds.right = caretPoint.x + 1;
    caretBounds.bottom = caretPoint.y + GetLineHeight();

    InvalidateRect(&caretBounds);
}

void TextBoxPane::InvalidateLineRange(short start, short end)
{
    List lineBounds(sizeof(RectBounds), 16);
    BuildTextRangeRectangles(start, end, &lineBounds);
    for (int index = 0; index < lineBounds.GetCount(); ++index) {
        InvalidateRect(static_cast<RectBounds *>(
            lineBounds.GetElementAt(index)));
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 8 - Complete UID00030D TextEditPaneInvalidateTextRegion

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TextEditPane::InvalidateTextRegion(short start, short end)
{
    List invalidBounds(sizeof(RectBounds), 16);
    BuildTextRangeRectangles(start, end, &invalidBounds);
    for (int index = 0; index < invalidBounds.GetCount(); ++index) {
        CompositePixels(static_cast<const RectBounds *>(
            invalidBounds.GetElementAt(index)));
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 9 - Complete `by-global/SurfaceRenderCallbackTable.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GrafPort;
struct RectBounds;

typedef void (__thiscall *SurfaceDrawPixelProc)(
    GrafPort *port,
    int x,
    int y,
    unsigned int colorIndex);

typedef void (__thiscall *SurfaceFillRectProc)(
    GrafPort *port,
    const RectBounds *bounds);

SurfaceDrawPixelProc g_pfnDrawPixel;
SurfaceFillRectProc g_pfnFillRect;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destinations 10-15 intentionally have no nonblank formal value: they are source/index/support/ignored ledgers, and emitting broad aggregate or storage proof as C++ would be wrong.

## Final Recommendation

- Destinations 1-15 and C30C-001 through C30C-046 were applied as one report-level callback without compression.
- Destinations 2 and 3 were registered first, serially, as UID0004T1 and UID0004T2; all temporary tokens were eliminated before dependent cross-link validation.
- All nine complete managed blocks are installed exactly. No snippet-only value, duplicate state definition, or example C++ exists outside formal values.
- The executed B001/B003 artifacts and settled current files were used as the callback baseline; current shared-union facts were reread/rebased and preserved rather than replaced.
- Manual coverage application/validation is complete under external supervisor commands 14778-14782; report lifecycle remains external to B004.

## Recommended Target Doc Changes

### Destination 1 - UID00030C

- Applied `92/94` while preserving UID, exact path/range, owner/emitter UID0000EO, reconstructable true, blank optional position, and callback-authorized `Nested:0`.
- Replaced the blank managed value with exact Destination 1 under validator command 14736.
- Replaced the Item Summary with exact source-ready OnDraw behavior: draw-state save/fill/restore, visible-line calculation, callback iteration, selection CompositePixels loop, caret branch, and solved helper/global contracts.
- Incorporated all exact binary, vtable, field, flag, helper, List, compiler-only, negative, source-placement, historical, and score-cap evidence from this report without compression.

### Destination 2 - New exact rectangle helper

- Applied: created `by-memory/0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles.md`, registered it serially as UID0004T1 under validator command 14734, and used that real UID in every dependent report/ordinary reference.
- Applied `92/94`, owner/emitter UID0000EO, reconstructable true, blank position, `Nested:0`, and exact Destination 2.
- Documented all three callers, endpoint normalization, project Point `{y,x}`, one/split/middle/final rectangles, repeated line-height calls, List Append behavior, exact range, compiler-only cookie, and raw-pocket exclusions.

### Destination 3 - New exact line helper

- Applied: created `by-memory/0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY.md`, registered it serially as UID0004T2 under validator command 14735, and used that real UID in every dependent report/ordinary reference.
- Applied `92/94`, owner/emitter UID0000EO, reconstructable true, blank position, `Nested:0`, and exact Destination 3.
- Documented 16-byte line records, signed-short result/indexes, current/next top tests, all three xrefs, zero/one-line handling, exact range, and neighboring aggregate/padding boundaries.

## Recommended Support Doc Changes

### Destination 4 - `by-class/TextEditPane.md`

- Preserved the full finalized B001/B003/B004 union after callback-time same-or-greater rebase; validator command 14737 passed.
- Added complete `TextRunDrawState` before the class, removed only its forward declaration, added both private helpers, and retained exact `EncodeState(unsigned short *outSize) const`, ordinary destructor, `ReleaseFormatObjects`, signed `TextEditFormatRecord::referenceCount`, compiler-vtable boundary, serialization fields/wrappers/mirror route, and every unrelated method/field/friend.
- Added target/helper/flag/slot evidence while preserving `93/94`.

### Destination 5 - UID0002ZY constructor

- Preserved `92/94`, all existing constructor behavior/evidence, and Destination 5 complete body under validator command 14738.
- Added draw-shared constants `0x02/0x40/0x80`; renamed only `kTextEditNoImeFocus` to behavior-complete `kTextEditReadOnly`; preserved exact bit `0x04` and final focus branch.

### Destination 6 - UID0001JR callback

- Preserved `91/93`, exact range/ABI/body/history/raw-neighbor evidence under validator command 14739.
- Installed Destination 6: removed duplicate `TextRunDrawState`, replaced `m_renderMode` with `m_drawMode`, replaced `g_pfnFillOrInvalidateRect` with `g_pfnFillRect`, and replaced literal flag 2 with the shared constant.

### Destination 7 - UID0002RU TextBox comparator

- Preserved `88/90`, both exact ranges, owner/emitter, and unrelated evidence under validator command 14741.
- Installed Destination 7 using `Point`, `GetCaretLocalPoint`, individual text-area fields, exact caret-right behavior, `List(sizeof(RectBounds),16)`, `BuildTextRangeRectangles`, and `GetElementAt`.

### Destination 8 - UID00030D

- Raised `86/90` to `91/93`; preserved UID/range/owner/emitter/reconstructable/position/`Nested:0` under validator command 14744.
- Installed Destination 8 and replaced stale list/helper blocker prose with exact shared contract, zero direct-caller fact, compiler cleanup separation, and source-ready rationale.

### Destination 9 - `by-global/SurfaceRenderCallbackTable.md`

- Preserved `89/86`, owner/emitter/position, all twelve slots and all existing target/consumer/history detail under validator command 14746.
- Installed Destination 9, retained slot-0 declaration, and added only exact slot-7 typedef/global without finalizing unrelated slots or inflating score.

### Destination 10 - `by-file/TextEditPane.md`

- B004 preserved `93/93`, the finalized B001/B003 source union, class closure/order, and all unrelated evidence under scoped validator 14751 and waited validator 14758, then added OnDraw plus both helper definitions to source inventory with corrected shared flags, callback state placement, Surface slot, selection/caret behavior, UID00030D closure, exact EncodeState stream/allocation, ordinary destructor, private helper, signed record, wrapper/mirror, and compiler-vtable boundaries.
- Post-B005 current SHA `602378CF5C8EF32C6309AE5E1BFF783A327C1A505A97837260D69A1E058DF50E` is same-or-greater: it preserves every B004 file fact and adds only UID0004T8 PutScrapToClipboard source order/call/failure/compiler evidence plus the finalized B005 caller route.

### Destination 11 - UID0001JM pre-TextBox aggregate

- Preserved `87/91`, source-bearing split-index status, blank formal, owner/emitter, `Nested:0`, and all sibling inventory under validator command 14752.
- Updated the target row to source-ready and added UID0004T1/UID0004T2 cross-references while explicitly recording that both helper addresses are outside this aggregate.

### Destination 12 - UID0003N0 and UID0001JP aggregates

- Preserved UID0003N0 `85/88`, UID0001JP `88/92`, both blank formals, raw pockets, padding, and unrelated child inventory under validators 14753/14754.
- Added exact UID0004T1 and UID0004T2 children respectively; historicalized only the helper-signature blockers those children resolve.
- Post-B005 UID0003N0 SHA `CDBE5FCE3EFF3BB9E5E3028ACF4A093152501EE6DA759905CAD22B50A30FB665` preserves that complete B004 tail union and adds only the exact UID0004T8 predecessor-padding/helper successor boundary; UID0001JP remains byte-identical.

### Destination 13 - Surface storage UID0001PI

- Preserved `89/88`, blank formal, all twelve storage slots, initializer/target history, and scores under validator command 14755.
- Added UID00030C and UID0001JR as exact slot-7 consumers and cross-linked UID0000TN's declaration without emitting storage bytes or duplicate globals.

### Destination 14 - Callback item mirror UID0000UK

- Preserved current score/owner and callback identity/xrefs/raw-neighbor evidence under validator command 14756.
- Replaced the stale missing-signature/state statement with UID0001JR's source-ready body and corrected state/global tokens; no separate C++ emitter was added.

### Destination 15 - `by-memory/-ignored.md`

- Added `[0x00590804,0x00590810)` as 12 `0xcc` compiler alignment bytes, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`, between predecessor code and UID00030C.
- Added `[0x005909e3,0x005909f0)` as 13 `0xcc` compiler alignment bytes, SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`, between UID00030C and UID00030F.
- Preserved the finalized B001 serializer-adjacent padding and all unrelated entries under validator command 14757; the B004 callback checkpoint was SHA `11E044625335DE63050FCE02FCCB1978CAA219A34A1B5F181DDCD8AA7ACF41AC`.
- Post-B005 current SHA `A5AD04AE4FBAA3FAE1D32A766365EC42EB02180147AB9A8BF3E9235A9B83AC7E` preserves both B004 padding rows and adds only B005's exact seven-byte/four-byte UID0004T8 boundary rows plus unrelated accepted external entries.

### Verify-Only / Excluded

- Verify-only: GrafPort class/file, List class/file, RectBounds class/layout, GetClipRect, CompositePixels, existing Surface target children, TextRunMeasureCallback, raw callback variants, vtable data, TextBoxPane class/file, UID00030F/UID00030E, and unrelated TextEditPane methods.
- Excluded: manual coverage, generated source, tracker, audit/supervisor/validator state, active reports, IDA mutation, and lifecycle state.

## Score And Metadata Recommendation

| Destination | Current | Recommended | Metadata decision |
| --- | ---: | ---: | --- |
| UID00030C | 92/94 applied | 92/94 | retained owner/emitter 0000EO, true, blank position; callback-authorized Nested 0 |
| `UID0004T1` | registered/applied | 92/94 | owner/emitter 0000EO, true, blank position, Nested 0; exact Destination 2 |
| `UID0004T2` | registered/applied | 92/94 | owner/emitter 0000EO, true, blank position, Nested 0; exact Destination 3 |
| UID00030D | 91/93 applied | 91/93 | retained all metadata, installed body |
| UID0000EO | 93/94 | unchanged | no-loss complete declaration union |
| UID0000ON | 93/93 | unchanged | source route/inventory only |
| UID0002ZY | 92/94 | unchanged | flag-name/shared-constant correction only |
| UID0001JR | 91/93 | unchanged | exact token/state placement correction |
| UID0002RU | 88/90 | unchanged | complete formal rebase only |
| UID0000TN | 89/86 | unchanged | exact slot-7 declaration, broader cap retained |
| UID0001PI | 89/88 | unchanged | storage/support prose only |
| UID0001JM / UID0003N0 / UID0001JP | 87/91, 85/88, 88/92 | unchanged | mixed split indexes stay blank/non-emitting |

## Open Questions With Attempted Resolution

- **Exact original helper spellings:** symbols are absent. Caller/body controls rank `BuildTextRangeRectangles` above `BuildLineInvalidationRects`, `GetSelectionRects`, and raw-address names because all three callers pass text offsets, not line numbers, and the helper creates rectangles for both selection and invalidation. `GetLineIndexForY` is preferred over `FindLine` because the sole input is a local Y coordinate and the return is the line index. Confidence is capped, but code is not blocked.
- **Flag 4 name:** `NoImeFocus` describes only the constructor consequence. OnKey mutation rejection and OnDraw caret suppression prove read-only semantics. `kTextEditReadOnly` is the strongest whole-program source name.
- **Flag 0x40 name:** the exact spelling is unknown. The boolean passed to the callback is the inverse and controls run text-color application. `kTextEditUseCurrentTextColor` is chosen because the set bit suppresses per-run colors without disabling text drawing.
- **Flag 0x80 name:** constructor forces it, OnMouse requires it, and OnDraw requires it for selection/caret. `kTextEditInteractive` covers the shared behavior better than selection-only or mouse-only labels.
- **Rectangle helper return:** Hex-Rays infers `int` because EAX retains the final virtual Append result, but accepted List::Append is void and every caller ignores EAX. Human source return is `void`.
- **OnDraw color restoration:** the background branch restores prior color; the caret branch does not. This asymmetry is retained as observed behavior rather than normalized.
- **Shared callback declaration order:** OnDraw instantiates `TextRunDrawState` before the current callback body emits its definition. Moving the complete struct to Destination 4 and removing the duplicate from Destination 6 is the only source-clean no-duplication arrangement.
- **Settled shared state:** B001 UID0001JN and B003 UID0002ZZ are finalized executed predecessor artifacts, and B005 UID000478 is a finalized executed additive shared-lane artifact under historical command 14835. No active predecessor collision remains; callback-time and current rereads preserve the complete serialization/destructor/private-helper/signed-record/vtable/draw/clipboard union at same-or-greater detail.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current supervisor-owned hashes, reread after command 14859 and unchanged from the command-14857 rebase, are by-memory `648C96BC0CF3AC950310399BBB69ADDCF9D955035B314F6C57FF263A6CF9690E`, by-class `CF71F86225D5A027627EE50C49236C7C0A1863DD622C6845F1698B2C059C864C`, by-file `22316E877291B68B3D0AA99ECD5CB1C6457E0EBB71B7FEC4E222CE5E1665297B`, by-global `B1D9DE82100DEFA76A964C097A808F0DAC6781CF4D51F6D670000F21B6AC3357`, and unchanged by-item command-14782 `66C86AAFBA920F09B29B5E6C5B1C5E477255362F2A4A2A009402DA8428079EA6`. Historical B004 coverage commands 14778-14782 all exited 0 / ok 1; their exact then-current hashes, the prior post-B005/UserStatusPane/commands-14847-14851 hashes, and earlier command-14712/14713/14720/14703/14682/14683/14704 epochs remain recorded under Validator Results and Current Target State.
- Current direct-row audit: UID0001JM is line 3,295; UID0001JN remains line 3,300; B004 padding/target/padding rows remain lines 3,301-3,303; UID0004T0 is line 3,304; B005's UID0001JO is line 3,305; UID0002RU is line 3,306; UID0003N0/UID0004T1/UID00030D remain lines 3,307/3,308/3,309; B005 padding/UID0004T8/padding are lines 3,310-3,312; UID0001JP/UID0004T2/UID0001JR are lines 3,314/3,315/3,317. The eight B004 by-memory source rows are unique at lines 3,295, 3,302, 3,307, 3,308, 3,309, 3,314, 3,315, and 3,317. Class UID0000EO, file UID0000ON, global UID0000TN, item UID0000UK, and mirror UID0000UM remain unique at lines 550/284/194/43/45.
- The unrelated WorldMap manual delta is segregated from this handoff: current by-memory lines 3,716-3,730 and 4,024-4,027 preserve the executable/STL/read-only WorldMap union, by-memory line 4,229 preserves storage UID00029E, by-class lines 605-607 preserve UID0000G8/UID0000G9/UID0000GA, by-file line 307 preserves UID0000PB, and by-global line 159 adds UID0004T9 `g_pWorldMapPane`; by-item has no WorldMap row. These rows explain the external whole-file hash drift and do not modify the TextEdit rows retained below.
- The following exact handoff text is retained as historical B004 application provenance using validator-issued UIDs 0004T1 and 0004T2. Current readback confirms byte-for-byte parity for every listed by-memory/class/global/item row and both B004 padding rows. The current file row is same-or-greater: it preserves this complete UID00030C union and adds only the accepted UID0004T8 clipboard-helper union. B004 did not edit any manual coverage file.

### `by-memory/-coverage-report.md`

Supervisor command 14778 applied this exact UID0001JM replacement at current line 3,295:

```text
    - [UID:0001JM][0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane](by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md) 0x0058dce0-0x00591300 | source-bearing split aggregate | TextEditPaneCoreBeforeTextBoxPane : reconstructable : 87% : very-strong : Exact TextEditPane pre-TextBox source-bearing split index with source-ready constructor UID0002ZY, ordinary destructor UID0002ZZ, private ReleaseFormatObjects helper [UID:0004T0][0x005912b0-0x005912fe.TextEditPaneReleaseFormatObjects](by-memory/0x005912b0-0x005912fe.TextEditPaneReleaseFormatObjects.md), source-ready UID0001JN EncodeState preserving the low-word text/16-16-4 table stream and allocator/output contract, copy/draw/key/mouse children, raw helper pockets, switch-table data, by-value wide StringBase GetText, exact text-area APIs/boundaries, all internal padding retained parent-only, and signed TextEditFormatRecord reference counts; UID00030C adds behavior-exact OnDraw source with exact draw-state/flag/visible-line/callback/selection/caret contracts and two exact helper children, while aggregate C++ remains blank because unrelated method/helper slices remain unsplit.
```

Supervisor command 14778 applied these exact padding/target/padding rows at current lines 3,301-3,303, between UID0001JN line 3,300 and UID0004T0 line 3,304:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00590804-0x00590810 | padding | Pre-TextEditPane OnDraw alignment : ignored : 100% : very-strong : Twelve exact `0xcc` compiler alignment bytes, SHA256 A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902.
        - [UID:00030C][0x00590810-0x005909e3.TextEditPaneOnDraw](by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md) 0x00590810-0x005909e3 | virtual method | TextEditPaneOnDraw : reconstructable : 92% : very-strong : Source-ready virtual TextEditPane::OnDraw with exact unique 467-byte body, nine primary-vtable routes, inherited draw-state save/fill/restore, visible-line lookup, TextRunDrawState and DrawTextRunCallback iteration, signed-short selection range, automatic RectBounds List, CompositePixels selection, read-only-aware caret geometry, exact g_pfnFillRect ABI, compiler-only EH/cookie cleanup separation, and no target empty marker after callback.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005909e3-0x005909f0 | padding | TextEditPane OnDraw to OnKeyEvent alignment : ignored : 100% : very-strong : Thirteen exact `0xcc` compiler alignment bytes, SHA256 0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE.
```

Supervisor command 14778 applied the exact UID0002RU replacement at line 3,306 and the post-TextBox parent/helper/UID00030D rows at lines 3,307-3,309 before UID0002RV, preserving the enclosing UID0001JO audit row:

```text
        - [UID:0002RU][0x00591300-0x005913f9.TextBoxPaneCursorInvalidationOverrides](by-memory/0x00591300-0x005913f9.TextBoxPaneCursorInvalidationOverrides.md) 0x00591300-0x005913f9 | method group | TextBoxPaneCursorInvalidationOverrides : reconstructable : 88% : very-strong : Exact source-ready TextBoxPane cursor and line invalidation overrides with Point {y,x}, GetCaretLocalPoint, exact right-edge caret behavior, individual text-area fields, automatic List(sizeof(RectBounds),16), shared BuildTextRangeRectangles, GetElementAt, InvalidateRect dispatch, exact ranges/xrefs, and preserved compiler cleanup separation.
        - [UID:0003N0][0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane](by-memory/0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane.md) 0x00591400-0x005917c9 | source-bearing split aggregate | TextEditPaneCoreAfterTextBoxPane : reconstructable : 85% : strong : Post-TextBox TextEditPane helper index retaining raw pockets and blank aggregate C++; exact child UID0004T1 closes the shared range-rectangle source contract and UID00030D now emits the exact invalidation loop without reclassifying neighboring raw code.
        - [UID:0004T1][0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles](by-memory/0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles.md) 0x00591520-0x00591639 | private method | TextEditPaneBuildTextRangeRectangles : reconstructable : 92% : very-strong : Exact source method normalizes signed-short endpoints, maps project Point {y,x}, emits one to three 16-byte RectBounds records across same-line/first/middle/final spans, appends through List, has three exact callers, excludes adjacent raw pockets, and emits one human definition under validator-issued UID0004T1.
        - [UID:00030D][0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion](by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md) 0x00591740-0x005917c9 | private method | TextEditPaneInvalidateTextRegion : reconstructable : 91% : very-strong : Source-ready exact TextEditPane invalidation helper using automatic List(sizeof(RectBounds),16), shared BuildTextRangeRectangles, GetElementAt, per-rectangle CompositePixels, automatic cleanup, exact range, zero ordinary callers, and compiler-only cookie/EH separation.
```

Supervisor command 14778 applied the exact UID0001JP/UID0004T2/UID0001JR rows; they remain current at lines 3,314/3,315/3,317, with UID0001JQ preserved at line 3,316:

```text
    - [UID:0001JP][0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters](by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md) 0x00591d60-0x00593c20 | method cluster | TextEditPaneFormattingRuns : reconstructable : 88% : very-strong : TextEditPane formatting/range-editing/run-iteration aggregate retaining exact 2/16/16/4-byte tables, callbacks, raw pockets, and blank aggregate C++; exact child UID0004T2 closes the signed-short Y-to-line binary-search contract without reclassifying unrelated raw helpers.
    - [UID:0004T2][0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY](by-memory/0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY.md) 0x00592bb0-0x00592c20 | private method | TextEditPaneGetLineIndexForY : reconstructable : 92% : very-strong : Exact signed-short line-index binary search over 16-byte TextEditLineRecord current/next top bounds, three exact xrefs, zero/one-line behavior, exact 0x70-byte range, and one source-ready const member definition under validator-issued UID0004T2.
    - [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) 0x00593db0-0x00593ef5 | file-local callback | DrawTextRunCallback : reconstructable : 91% : very-strong : Source-ready TextEditPane draw callback with shared header-defined TextRunDrawState, exact line/format/context ABI, inherited m_drawMode, exact g_pfnFillRect slot-7 declaration, black-background flag, clip/fill/alignment/object/trailing-whitespace behavior, two address-taking routes, lower renderer forwarding, and preserved raw-neighbor exclusion.
```

### `by-class/-coverage-report.md`

Supervisor command 14779 applied this exact UID0000EO row at current line 550:

```text
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md) : reconstructable : 93% : very-strong : Complete TextEditPane declaration preserving the exact constructor, ordinary destructor, source-ready EncodeState(unsigned short *outSize) const, low-word text/16-16-4 serialization fields, private ReleaseFormatObjects, compiler-vtable boundary, exact 2/16/16/4-byte tables, signed format reference counts, complete TextRunDrawState before OnDraw, exact callback friends, source-ready OnDraw, private BuildTextRangeRectangles/GetLineIndexForY helpers, caret/text-area/selection/scroll APIs, class closure before children, and residual unrelated raw-helper caps only.
```

### `by-file/-coverage-report.md`

Supervisor command 14780 applied this exact UID0000ON baseline row at line 284. Current line 284 remains same-or-greater and preserves every clause below while adding UID0004T8 PutScrapToClipboard source/caller behavior:

```text
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md) : reconstructable : 93% : very-strong : Rich text editor source module preserving the exact constructor, ordinary destructor, private ReleaseFormatObjects, signed format records, compiler-vtable boundary, source-ready EncodeState low-word text/16-16-4 stream and allocator/output contract, wrapper/mirror route, and complete callback union while adding source-ready TextEditPane::OnDraw, BuildTextRangeRectangles, GetLineIndexForY, and InvalidateTextRegion; exact shared draw flags, TextRunDrawState, g_pfnFillRect, selection/caret/List behavior, active-editor/clipboard globals, support-object split, and unrelated raw-helper islands remain no-loss and separately bounded.
```

### `by-global/-coverage-report.md`

Supervisor command 14781 applied this exact UID0000TN row, now at current line 194 after the unrelated UID0004T9 WorldMap insertion, without changing score:

```text
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) : reconstructable : 89% : strong : Documentation/source owner for twelve fixed Surface render callback globals; complete formal preserves slot-0 SurfaceDrawPixelProc/g_pfnDrawPixel and adds exact slot-7 SurfaceFillRectProc/g_pfnFillRect with GrafPort receiver plus const RectBounds pointer, installed compat/RGB565 targets, initializer/storage routes, and exact TextEditPane OnDraw/DrawTextRunCallback consumers, while unrelated slot typedefs retain their independent confidence limits.
```

### `by-item/-coverage-report.md`

Supervisor command 14782 applied this exact UID0000UK row at current line 43:

```text
- [UID:0000UK][DrawTextRunCallback_00593DB0](by-item/DrawTextRunCallback_00593DB0.md) : reconstructable : 86% : strong : TextEditPane file-local draw callback mirror with exact 0x00593db0 source child, two iterator address-takes including UID00030C, complete shared TextRunDrawState and callback ABI, corrected m_drawMode/g_pfnFillRect source tokens, PE-confirmed reachability, exact raw-neighbor/padding separation, and no independent emitter or remaining signature/state blocker.
```

- Tracker text is validator-generated and was not manually edited. Waited command 14758 derived target `92/94`, both real helper UIDs, UID00030D `91/93`, and the callback-time source-owner counts; supervisor execution command/header 14835 and external command/headers 14851/14857 are historical tracker evidence. Current external command/header 14859 preserves UID00030C/UID0004T1/UID0004T2 at lines 3,232-3,234 and UID00030D/UID0004T8 at lines 3,021-3,022 with the exact current scores and blank external lifecycle fields recorded above. No historical pre-callback owner count is frozen as permanent truth.

## Follow-Up Actions

- No binary or implementation blocker remains. Destinations 1-15 are applied, the two helper pages are serially registered, every placeholder is removed, and all ordinary/generated assertions pass.
- B004 used one short ordinary lease at a time, validated within each window, and released every lease immediately. The current lease report shows zero B004 leases.
- Scoped validators 14734-14739, 14741, 14744, 14746, and 14751-14757 plus final waited command 14758 are recorded below with exact results.
- B005 UID000478 was supervisor-executed under historical command 14835; current external generated/tracker command 14859 and the current manual snapshot preserve the B004 union at same-or-greater detail. Commands 14846/14851/14857 and the commands-14847-14851 manual snapshot are historical. Supervisor-owned B004 manual coverage application/validation remains complete, and no implementation or manual-coverage handoff item remains. Report validation/execution/count/path/move/archive state remains external supervisor/validator-owned and is neither asserted nor directed by this artifact.

## Confidence

- Range/bytes/ABI/vtable/source identity: 98%.
- Branch/field/List/callback/helper behavior: 97%.
- Ownership/emitter/source placement: 97%.
- Human helper/flag spellings: 88-92% depending on token.
- Overall target recommendation: `92/94`; confidence stays below final certainty only because original private helper and flag lexical spellings are not recoverable.

## Validator Results

- Historical report-only phase: no scoped validator, generated refresh, report validator, lifecycle command, or IDA mutation was run by B004 before Gate 1. Implementation began only after exact-artifact supervisor authorization.
- Current generated readback is external command/header 14859, refreshed `2026-07-20T02:33:55-04:00`, SHA256 `F5D885E5E6CD3DD74071167B440CC012B5AE63CC3C7CAA1641DB57C9C5730360`, 32,999 bytes / 924 lines. B004's waited command 14758 / SHA256 `EBCEA2848219CE3A008603696AD4EDBECAE27457AE3D360777E05EF9BADA2EF2` remains the exact implementation checkpoint; 14789, B005 waited 14814, external 14817, command 14831 / SHA256 `63C7133189FDEAA66388453ADF6B9FBB6C992E798D393993EB2F85B40B2CD1F1`, command 14846 / SHA256 `C4369776AB3F6D20A724935B1CED076BAB203F7A5E761CBF4BB67B397F533246`, and command 14857 / SHA256 `E862DFAC1D15EC7053CD455388F60B8C47C3C12DD52890975CBDA92B3723143D` are historical epochs. Current command 14859 preserves every B004 assertion and includes exactly one UID0004T8 definition/prototype with zero helper marker or compiler/decompiler artifact.
- MCP validation is separate from documentation validation: valid `idb_list`, `server_health`, `lookup_funcs`, corrected bounded `get_bytes`, and target/helper `analyze_function` calls succeeded against database `9b0396a3`.
- Every callback validator exited `0` with `ok:1`; warnings were pre-existing missing-reference or project-wide generated diagnostics, not destination failures:

| Command | Timestamp (America/New_York) | Destination/result | Warnings and authorized side effects |
| --- | --- | --- | --- |
| `14734` | `2026-07-19T23:35:59-04:00` | UID0004T1 registration, exit 0 / ok 1 | two then-missing UID0003N0 refs; assigned UID0004T1; deferred generated |
| `14735` | `2026-07-19T23:37:19-04:00` | UID0004T2 registration, exit 0 / ok 1 | no reported warning; assigned UID0004T2; deferred generated |
| `14736` | `2026-07-19T23:39:32-04:00` | UID00030C, exit 0 / ok 1 | score/formal updates; deferred generated |
| `14737` | `2026-07-19T23:41:51-04:00` | by-class TextEditPane, exit 0 / ok 1 | eight pre-existing missing refs across UID00040S/00040T/0003M8/0003FC/0003FD; added helper refs |
| `14738` | `2026-07-19T23:43:16-04:00` | UID0002ZY constructor, exit 0 / ok 1 | no warning; deferred generated |
| `14739` | `2026-07-19T23:44:42-04:00` | UID0001JR callback, exit 0 / ok 1 | nine pre-existing raw-neighbor missing refs; deferred generated |
| `14741` | `2026-07-19T23:46:08-04:00` | UID0002RU comparator, exit 0 / ok 1 | one then-missing UID0003N0 ref; normal link propagation |
| `14744` | `2026-07-19T23:47:33-04:00` | UID00030D, exit 0 / ok 1 | three then-missing UID0003N0 refs; score/formal updates |
| `14746` | `2026-07-19T23:48:57-04:00` | Surface global UID0000TN, exit 0 / ok 1 | three pre-existing UID0003XE refs; deferred generated |
| `14751` | `2026-07-19T23:53:17-04:00` | by-file TextEditPane, exit 0 / ok 1 | 59 pre-existing missing refs; added UID0004T1/0004T2 refs and removed stale UID00030E/00030F refs |
| `14752` | `2026-07-19T23:54:49-04:00` | UID0001JM aggregate, exit 0 / ok 1 | five then-missing UID0003N0 refs; added helper refs |
| `14753` | `2026-07-19T23:56:05-04:00` | UID0003N0 aggregate, exit 0 / ok 1 | authorized missing mapping registration/header normalization and six reference-index additions |
| `14754` | `2026-07-19T23:56:59-04:00` | UID0001JP aggregate, exit 0 / ok 1 | four pre-existing refs (UID0003FC/0003FD/0003GI); added UID0004T2 ref |
| `14755` | `2026-07-19T23:58:08-04:00` | Surface storage UID0001PI, exit 0 / ok 1 | five pre-existing UID0003XE/0003PN refs; added UID00030C/0001JR refs |
| `14756` | `2026-07-19T23:59:01-04:00` | callback item UID0000UK, exit 0 / ok 1 | one pre-existing UID0003FD ref; expected registry hash refresh |
| `14757` | `2026-07-20T00:00:02-04:00` | by-memory/-ignored.md, exit 0 / ok 1 | 251 pre-existing ledger missing refs; added UID00030C/00030F refs |
| `14758` | `2026-07-20T00:00:51-04:00` | final by-file/TextEditPane `--wait-generated`, exit 0 / ok 1 | 59 pre-existing refs and project-wide generated warnings; registry rebuild, metadata/tracker/generated refresh completed |

- Post-B005 byte comparison, with line endings normalized only for comparison, reconfirmed Destinations 1-9 exactly equal to their named managed `RECONSTRUCTION_CPP` blocks (lengths 2,193; 1,570; 896; 7,501; 5,457; 2,807; 980; 576; and 551 bytes respectively). Generated `DrawTextRunCallback` has one declaration and exactly one definition; the declaration is not counted as a duplicate definition.
- Supervisor-owned B004 manual coverage reconciliation was independently applied and validated after Gate 1/Gate 2. B004 did not invoke these commands; the manual files do not encode command timestamps, so no timestamp is invented here. The table records the historical applied B004 baseline:

| Supervisor command | Manual destination/result | Applied baseline SHA256 / size |
| --- | --- | --- |
| `14778` | by-memory coverage, exit 0 / ok 1 | `CE1859B0B1308912A01A10C1B63C754DA9F9AF8C06BE8C5B57C4C09ED507C1A5`, 1,809,152 bytes / 4,311 lines |
| `14779` | by-class coverage, exit 0 / ok 1 | `DF1976C5366848594B5E8C890CB0FC8D1CFF2E7CDCDBBE299E6FB297C45232B1`, 234,817 / 623 |
| `14780` | by-file coverage, exit 0 / ok 1 | `25E8C29C1A1254F9719D2A1957174C3962558A2E61B1D893B5AABB3A70D12A44`, 134,253 / 316 |
| `14781` | by-global coverage, exit 0 / ok 1 | `CC4B84DE2CF9CA08A16F2AAA2E694ADAF00C5B363CD8767449F504FB2CCD3975`, 90,195 / 212 |
| `14782` | by-item coverage, exit 0 / ok 1 | `66C86AAFBA920F09B29B5E6C5B1C5E477255362F2A4A2A009402DA8428079EA6`, 28,963 / 87 |

- Historical post-B005 readback advanced by-memory to `B2D90EE83DB9AE8F953FD5B59AD22CA179A627843DBF7059E07DC4EE96C1F17D`, by-class to `D71E09E87C26B5BB276C0E27E5B05E23BAF99E72B3DC44AE072A48A681B64730`, by-file to `629C9E94D82D9D088387C21EDD3FB36DB12553C6DC1967C662F8AAEFB1FD55E6`, and by-global/by-item to the command-14781/14782 hashes above. A later unrelated B001 UserStatusPane epoch advanced by-memory/by-class/by-file/by-global to `C8202C988A6C0AD282B4C43B4D4EBB4F72449EB2F0739F91E2B6431C39DD743E` / `862E9BE235064C33459EC225C96742B03829D18ECB39A53FF599ACCB2657F75B` / `6E32409881C7D5C8D11792F140B775AF022D3A3D01BE808FBD632CF58DFB367F` / `3F831C9FA2FB5CD22E1DD2796DFA0E73731B115FC03E33EC8D3744B886AB6238`. The current unrelated WorldMap synchronization advances those same roots to `648C96BC0CF3AC950310399BBB69ADDCF9D955035B314F6C57FF263A6CF9690E` / `CF71F86225D5A027627EE50C49236C7C0A1863DD622C6845F1698B2C059C864C` / `22316E877291B68B3D0AA99ECD5CB1C6457E0EBB71B7FEC4E222CE5E1665297B` / `B1D9DE82100DEFA76A964C097A808F0DAC6781CF4D51F6D670000F21B6AC3357`; by-item remains `66C86AAFBA920F09B29B5E6C5B1C5E477255362F2A4A2A009402DA8428079EA6`. Every B004 memory/class/global/item row remains byte-equal and unique; the file row is same-or-greater and explicitly preserves UID00030C while adding UID0004T8. The separately listed WorldMap rows explain the current whole-file drift without a B004 delta.

## Changed Files

- B004 changed exactly these ordinary docs: UID00030C; new UID0004T1; new UID0004T2; by-class/TextEditPane.md; UID0002ZY; UID0001JR; UID0002RU; UID00030D; by-global/SurfaceRenderCallbackTable.md; by-file/TextEditPane.md; UID0001JM; UID0003N0; UID0001JP; UID0001PI Surface storage; UID0000UK callback item; and by-memory/-ignored.md. Their exact current hashes are recorded in Current Target State.
- B004 also updated only this same report in its own research folder, including the bounded post-B005 reconciliation and this final command-14859 current-state rebase. No ordinary/manual coverage/generated/tracker/audit/supervisor/validator-state/IDA/goal/registry/lifecycle/archive file was edited by B004 during this callback; external validator and supervisor side effects are attributed explicitly.
- Verify-only UID0002ZZ, UID0004T0, UID0001JN, UID0000UM, UID0004K6, and UID0003DV retain exact hashes in Current Target State. Current external generated/tracker command 14859 preserves all B004 definitions/tokens and tracker states over the historical command-14758 implementation checkpoint; the current WorldMap-advanced coverage hashes are the external manual reconciliation snapshot. Historical generated/tracker commands 14831/14835, 14846/14851, and 14857 remain provenance only. The B004 handoff remains fully incorporated at exact or same-or-greater detail.

## Implementation Tracking Checklist

Report-only / Gate 1 phase:

- [x] Supervisor accepted exact pre-callback report SHA `2B5A2840ED3C3699E67B7C29207E3C8B4B850F87A29CC7CF69647F062EC83473` for implementation.
- [x] C30C-001 through C30C-046 were independently reviewed claim by claim and retain explicit terminal ledger rows.
- [x] All nine complete managed blocks were checked for exact destination equality after real-UID substitution.
- [x] Destination 1 target score/metadata/body/evidence was accepted and applied under command 14736.
- [x] Destination 2 exact range/name/score/body/Nested decision was accepted and registered as UID0004T1 under command 14734.
- [x] Destination 3 exact range/name/score/body/Nested decision was accepted and registered as UID0004T2 under command 14735.
- [x] Destination 4 preserves the complete finalized B001/B003/B004 TextEditPane union and the additive B005 file-local clipboard work now present at same-or-greater detail in current bytes; B004 command 14737 passed.
- [x] Destination 5 shared constants/read-only rename preserves constructor behavior; command 14738 passed.
- [x] Destination 6 callback state placement and two token corrections are applied; command 14739 passed.
- [x] Destination 7 TextBox comparator rebase preserves both exact bodies; command 14741 passed.
- [x] Destination 8 UID00030D source closure is applied at `91/93`; command 14744 passed.
- [x] Destination 9 slot-7 declaration preserves slot 0 and unrelated table state; command 14746 passed.
- [x] Destinations 10-15 prose/index/padding/support changes are applied under commands 14751-14757.
- [x] Historical new-child placeholders were replaced everywhere by real UIDs 0004T1 and 0004T2; zero token remains.
- [x] Exact manual supervisor-owned handoff rows were applied and independently validated under commands 14778-14782; current WorldMap-advanced hashes, anchors, uniqueness, exact memory/class/global/item parity, and same-or-greater file-row parity were reread after command 14859 while prior post-B005/UserStatusPane/commands-14847-14851 hashes remain historical.
- [x] Finalized B001 serialization artifact and historical commands 14702-14704 and 14732/14733, B004 command-14758 implementation checkpoint, historical generated/tracker epochs 14789/14794, 14831/14835, 14846/14851, and 14857, current external generated/tracker command 14859, supervisor coverage commands 14778-14782, historical executed-B005 command 14835, and the current ordinary union were reviewed.
- [x] Finalized B003 destructor/private-helper/signed-record/vtable artifact, executed B005 UID000478 additive artifact, and current ordinary union were reviewed and preserved.
- [x] Verify-only and forbidden boundaries were reviewed; no verify-only ordinary page or forbidden state was edited.
- [x] The exact pre-callback artifact received supervisor Gate 1 acceptance and the ordinary implementation received written Gate 2 acceptance; exact reconciled SHA `585EEFFDF3BCE85F22D537AED854F0FC2E370F9EBAADD1864F4AA3FC98FCC3D1` historically failed fresh Gate 1 during B005 shared-lane drift, and exact SHA `198DA52004DD4A93C2FEFC553AEBB0B0C3750951E2B6975B6AA7C05C47494134` later failed fresh Gate 1 for stale mutable authorities and pre-registration wording. This final artifact ends with one Gate 1 review marker without asserting a review outcome or report lifecycle state.

Implementation callback phase:

- [x] Explicit supervisor UID00030C callback authorization was received before any shared TextEditPane lease.
- [x] Finalized executed B001/B003/B005 artifacts and current shared class/file/aggregate/serializer/destructor/helper/vtable/clipboard-helper bytes were reread and hashed.
- [x] Every Destination 1-15 ordinary page was reread immediately before its edit.
- [x] Destination 2 page was created without inventing a UID.
- [x] Destination 2 was validator-registered as UID0004T1 under command 14734.
- [x] Every historical rectangle-helper placeholder was replaced before dependent validation.
- [x] Destination 3 page was created without inventing a UID.
- [x] Destination 3 was validator-registered as UID0004T2 under command 14735.
- [x] Every historical line-helper placeholder was replaced before dependent validation.
- [x] No temporary UID token remains in report or ordinary destinations.
- [x] UID00030C is exactly `92/94` with accepted metadata and `Nested:0`.
- [x] Destination 1 managed body is exact and appears once in generated source.
- [x] Destination 2 metadata/body/evidence is complete and validated.
- [x] Destination 3 metadata/body/evidence is complete and validated.
- [x] TextEditPane class complete block preserves the current union and closes before `[[CHILDREN]]`.
- [x] `TextRunDrawState` is defined once before OnDraw and is not duplicated in callback source.
- [x] Constructor complete block preserves all current behavior and uses shared flag names once.
- [x] DrawTextRunCallback complete block preserves all behavior and exact corrected tokens.
- [x] TextBox comparator complete block preserves exact caret-right and invalidation behavior.
- [x] UID00030D is exactly `91/93` with accepted body/evidence.
- [x] TextEditPane file page preserves the complete finalized B001/B003/B004/B005 source union, including exact EncodeState stream/allocation behavior and additive UID0004T8 PutScrapToClipboard source/caller facts.
- [x] UID0001JM split index is synchronized without emitting aggregate C++.
- [x] UID0003N0 split index preserves B004 synchronization and B005's exact UID0004T8 predecessor-padding/helper successor boundary without reclassifying raw pockets.
- [x] UID0001JP split index is synchronized without reclassifying unrelated raw helpers.
- [x] Surface global complete block preserves slot 0 and adds only slot 7.
- [x] Surface storage and callback item prose are synchronized without score/body inflation.
- [x] Both exact B004 ignored-padding rows remain present without unrelated ledger loss; current bytes also preserve B005's exact UID0004T8 boundary rows.
- [x] Every changed ordinary page was leased only for its edit/validator window.
- [x] Every changed ordinary page received one scoped file validator; by-file additionally received final waited validation.
- [x] Every lease was released immediately after its scoped validator.
- [x] Exact validator command IDs/timestamps/exits/ok/warnings/side effects are recorded.
- [x] B004's final authorized TextEditPane validator command 14758 used `--wait-generated`; external commands 14831, 14846, and 14857 are historical evidence and external command 14859 is the current read-only generated authority.
- [x] Current command-14859 TextEditPane.cpp contains exactly one UID00030C trace/definition.
- [x] Current command-14859 TextEditPane.cpp contains exactly one UID0004T1 BuildTextRangeRectangles definition.
- [x] Current command-14859 TextEditPane.cpp contains exactly one UID0004T2 GetLineIndexForY definition.
- [x] Current command-14859 TextEditPane.cpp contains exactly one UID00030D definition.
- [x] Current command-14859 TextEditPane.cpp retains exactly one DrawTextRunCallback definition and one prototype, plus exactly one UID0004T8 PutScrapToClipboard definition and one prototype.
- [x] Current command-14859 TextEditPane.cpp has zero UID00030C/UID0004T1/UID0004T2/UID0004T8 Empty Emitter Markers.
- [x] Current command-14859 TextEditPane.cpp has zero stale `g_pfnFillOrInvalidateRect` tokens.
- [x] Current command-14859 TextEditPane.cpp uses exact `g_pfnFillRect` and inherited `m_drawMode`.
- [x] Current command-14859 TextEditPane.cpp has no raw offset/sub/vtable/cookie/SEH/manual List-cleanup source.
- [x] Current command-14859 TextEditPane.cpp has no duplicate helper/callback/class/source body and retains one each of EncodeState, ordinary destructor, and ReleaseFormatObjects source.
- [x] Current manual coverage contains the exact real-UID handoff at unique accepted anchors after historical supervisor commands 14778-14782: all B004 memory/class/global/item rows are exact, the file row is same-or-greater, and unrelated WorldMap rows are separately classified; no B004 manual edit occurred.
- [x] B004 did not manually edit any manual coverage or generated file.
- [x] C30C-001 through C30C-046 have legal terminal callback states with destination/validator proof.
- [x] Validator Results and Changed Files record exact current ordinary, command-14859 generated/tracker, and WorldMap-advanced manual coverage hashes and scope; commands 14831/14835, 14846/14851, and 14857 remain explicitly historical.
- [x] Every accepted callback checklist item is terminal and truthful.
- [x] No B004 lease remains.
- [x] B004 ran no execute_report, lifecycle/probe/count/move/archive command.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000014863","destination_path":"executed-b-agent-research/B004/00030C-TextEditPaneOnDraw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00030C-TextEditPaneOnDraw-source-quality.md","timestamp":"2026-07-20T02:48:16-04:00","uid":"00030C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
