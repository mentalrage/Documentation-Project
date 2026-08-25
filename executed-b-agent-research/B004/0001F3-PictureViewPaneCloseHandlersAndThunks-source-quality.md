** TARGET-REPORT-UID:0001F3 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0001F3 PictureViewPane Close Handlers And Thunks Source-Quality Research

## Finalized Report / Current Recommendation

- Current implemented result: [UID:0001F3] `[0x00549b00,0x00549b63)` is split into exact source-bearing `PictureViewPane` EventHandler overrides UID0004RN/UID0004RO and non-emitting compiler-thunk child UID0004RP while UID0001F3 remains the mixed-range index.
- Final disposition: UID0001F3 is `92/94`, retains semantic owner [UID:0000AH] `PictureViewPane`, is `RECONSTRUCTABLE:FALSE`, has blank `EMITTER_UIDS`/position/formal C++, and retains `Nested:0`. The two handler children emit through UID0000AH; the thunk child is compiler-only, non-reconstructable, non-emitting, and formally blank.
- Exact source identities: `bool PictureViewPane::HandlePointerOrMouseEvent(Event *event)` at `[0x00549b00,0x00549b22)` and `bool PictureViewPane::HandleKeyOrTextEvent(Event *event)` at `[0x00549b30,0x00549b4d)`.
- Exact non-source interval: `[0x00549b4d,0x00549b63)` contains two MSVC complete-object destructor adjustor thunks and no handwritten function body.
- Exact internal alignment: `[0x00549b22,0x00549b30)` is fourteen `0xcc` bytes and remains under [UID:0000VN] `by-memory/-ignored.md`; `[0x00549b63,0x00549b70)` is thirteen `0xcc` bytes outside the target and remains ignored before the scalar deleting destructor.
- Source-graph closure: exact source-bearing children UID0004RJ, UID0004RK, UID0004RL, and UID0004RM now cover `PhotoPane::PhotoPane`, `PhotoPane::OnPaint`, `PictureViewPane::PictureViewPane`, and `PictureViewPane::~PictureViewPane`. These four children close every handwritten interval after broad UID0001F2 became non-emitting.
- PhotoPane destructor disposition: do not declare or define a handwritten `PhotoPane::~PhotoPane`. The current raw cleanup child and scalar deleting wrapper are compiler output caused by the implicit virtual destructor, the embedded `GrafPort m_snapshotPort`, and the explicit `PictureViewPane` base destructor. UID0002R8 retains a compiler marker with that exact source cause.
- Coherent generated unit: command `000000013193` emits `PictureViewPane` before derived `PhotoPane`, one definition for each of the six accepted source methods, and one UID0002R8 compiler marker, with no affected Empty Emitter Marker, broad-index marker, vtable body, adjustor body, deleting-wrapper body, explicit PhotoPane destructor, or declared-but-undefined accepted method.
- Source route: keep `PictureViewPane` in [UID:0000MK] `NexusTK/map/PhotoPane.cpp`. A separate adjacent `PictureViewPane.cpp` is the bounded runner-up, not the selected route.
- Exact relative nesting is applied: UID0004RJ opens the outer UID0001F2 child indentation with `Nested:+4`; later outer siblings including UID0001F3 retain `0`; UID0004RN opens the second four-space level with `Nested:+4`; UID0004RO/UID0004RP retain `0`; UID0001F4 restores the pre-UID0001F2 cumulative indentation with `Nested:-8`.
- Confidence: very strong for ranges, bytes, vtable slots, Event contract, behavior, ABI/no-code classification, parent/child nesting, and `Pane::MarkForDeletion`; strong for the selected combined source file and public access spelling.

## Supporting Research

- Current same-report implementation artifact: `tools/leaser/Agents/Agent-B004/research/0001F3-PictureViewPaneCloseHandlersAndThunks-source-quality.md`. B004 edited only the sixteen accepted ordinary destinations and this report. B004 made no manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, archive, or IDA edit; generated/index changes are validator side effects recorded below.
- Mandatory MCP evidence was collected from NexusTK database `64c11373` through streamable transport session `bf162efd-f422-4522-ad3e-d4f2d0c77f85`. At evidence time `idb_list` returned that database, `server_health` reported `ok` with analysis, Hex-Rays, and string cache ready, and bounded function, byte, decompilation, disassembly, xref, and vtable reads succeeded.
- A first local client attempt passed an empty database because a PowerShell helper accidentally used the reserved `$args` variable. The server returned `database required`; this was a client-serialization error, not an MCP outage. The helper was corrected and every mandatory IDB-backed check was repeated successfully against database `64c11373`.
- The additive Gate 1 repair opened fresh streamable transport session `b11637c0-513e-4642-a1b6-7ed971eb218c`; `idb_list`, `server_health`, and bounded lookups/decompilations/xrefs/byte reads for all four added source functions and both named helper controls succeeded against the same database. Transport-session IDs are evidence-time identifiers, not claims of indefinite current availability.
- Historical pre-callback by-* baselines opened and preserved for rebase proof:
  - target SHA256 `5E34948365DF9947F6ADEE6C4F221035DA94040C4616A85B6B49074DF38BC0A3`;
  - [UID:0000AH] class SHA256 `45DB3A7924C3FB434ABD305CE3077283179E621393303FA9F4DC8D7B472B06BB`;
  - [UID:0000MK] file SHA256 `25B4A0A18BE2DA63CB2FD996838D03A0C722EE362B1CDB1D43722FAEC8E8C39F`;
  - [UID:0001F2] aggregate SHA256 `8EFD2B43CEA360456644887700F7AFE480F79EB64457BAD5D4399BD636443379`;
  - [UID:0003OW] vtable child SHA256 `B06BA869B66884B70B89EDEFA6B10B6470F9C9251F73CE9EF42E0917CF842F6E`;
  - [UID:000265] read-only aggregate SHA256 `4F6D41FA1A11AC73B87B7D3CAEC9D2AF259CECEE6EC207BC1708CF592A5C5AB6`;
  - [UID:0000VN] ignored page SHA256 `FA2EBDDEDFA4CAF79AE7ACEDC7B152439FE9D037A92F2AEBCD2D6F110CC80568` at the final report-only destination rehash; concurrent unrelated content remained outside the bounded update.
- Additional historical pre-callback destination baselines: [UID:0000AG] PhotoPane class SHA256 `F9BA8BBCA2B81FFF75CFA835143F6CD6B0374DD71205C3BE865509A23A328EFC`; [UID:0002R8] raw cleanup SHA256 `58F325FC56C7C2A5663CF867E485E42AC4E29D2095BE61F9D774707797D85969`; [UID:0001F4] successor SHA256 `FCF93CDB2E90BCE25E04F7ACCB52FF197B37C63D295FE62397475B0CE9E7CA64`; and verify-only [UID:0003OU] PhotoPane vtable SHA256 `65919A21CC0421AA25EF14435587714EB2614E2DFC9430B4B2FDB96FF49C9D4E`. Supervisor command 13227 later inserted only the required metadata-header separator and restored the legacy UID/path/owner/autogen/reference mapping, producing current SHA256 `155F7DFF38BB113686F38C4B1FEA24145D9613457B5E6116D3994D67B9746540` without changing UID0003OU research semantics, score, metadata values, or formal disposition.
- Current post-callback ordinary hashes are recorded under `Changed Files`; all thirteen accepted formal blocks compare byte-for-byte equal after CRLF normalization, and all seven provisional UID tokens are absent.
- Historical B004 callback proof for shared `by-memory/-ignored.md` is validator 13190 and SHA256 `9F5E59D1720F06867FA77272B039B3C8F92CF0293725634DB8C90A39F26BC6CF`. Unrelated retained B001 PowerListPane work advanced that shared page through external command `000000013232` at `2026-07-15T15:33:50-04:00`; current SHA256 is `896D92EB6EFF0AB3F700CC67F3BC2832A49A419878A97CE854B50332F1F4A4EF`, 1,038,521 bytes, 5,091 lines, last write `2026-07-15T15:33:46.1324658-04:00`. B004 made no shared-page edit during this repair, and every accepted Photo/Picture ignored fact remains exact as proved below.
- Remaining UID-addressed verify-only baselines were rehashed at the same checkpoint: [UID:0001EA] PaneCore `D118C5B2EF39D35359C57003DB2593FCD87CAB3B3111293AE3466DC0EA4EE5E6`; [UID:00004N] EventHandler `38033240D695B08EB3404F722953F1243DD2DE6B2C2724FB7B59995873AD9EB1`; [UID:00004L] Event `D18D26ABE86BE73E0C97CAD29E1CE676CF282A91124763E989188514F35EF95B`; and [UID:0000A2] Pane `B9686C65CE4A1E868E8FD3B9AF8478F36EBB5F764F585A12BB0B3A58E7CCAC10`.
- Verify-only dependency class baselines were rehashed without edit: `MapTileImageLib.md` `B2D85ED71180142EAD1B8210A001550A42C931783CB656445C1C89F49AB18CFF`; `StaticObjImageLib.md` `724BCE2A2B8C80253D27922A462B65F1E523301374D032D3A28A22E4EAEC8455`; `NewHumanImageLib.md` `1924DA7AD9D549145D6CFF40F43C14F44EB64AC97A7E4D908D3FABAE7C52873A`; `DATFile.md` `50E0D6A318631532A3EDD605479F44851FF3518BE82A0FAEACE2157A3A6E927F`; `SimpleUString.md` `1A5B079579C3981E55336D21DAC28077D84E56CEB67A2DC2C693E24A0BFA6458`; `ObjectStatusBlob.md` `110F06C13CB4F5006910B5A553C3E9DCE5A4901E7A14CF0F9C096502DE51D39E`; `RectBounds.md` `710057507F3BCBAC7528CFC299AC57C6652068EBB24F1CEF06D60C513BAF370E`; and `GrafPort.md` `F1AD63407DAD2CCE4891E755A9F6271F259D3BEB40E9780A74A250A52B16053C`.
- Historical report-only nesting controls were UID0001F2 `0`, first child UID0002R8 `+4`, UID0001F3 `0`, and UID0001F4 `-4`. Current applied headers are UID0001F2 `0`, first outer child UID0004RJ `+4`, UID0001F3 `0`, first target child UID0004RN `+4`, and UID0001F4 `-8`. `tools/validator_background.py` line 6458 applies each value directly as a raw indentation-space delta.
- Historical pre-callback generated baseline command `000000013151` produced PhotoPane.cpp SHA256 `2B0F9A8543A02C2FEE5CEC5F6344D00D18F4402AC524EC438307FA97B86ACD90`, with UID0002R8/UID0001F2 markers, three affected Empty Emitter Markers, and none of the six accepted definitions. Header normalization to commands 13141/13122 preserved those historical semantics. Command 13193 supersedes that target state.
- Supervisor reconciliation snapshots were by-memory command-13228 SHA256 `31DE8A59A08ECB98A6E57AFC4163FB0260FB30E9415467FE30811F9B078A88BA`, by-class command-13225 SHA256 `DA137B8A0F4DD0C5D653B03FF94F9BFBA00A5CBCE7134D8F081C29EC85C3AAE6`, and by-file command-13226 SHA256 `622F7D86C7F79DF7653211999F161E2EE7115333173158B62742687B3FFC638E`. Later unrelated external commands 13234/13235/13236 advanced the full-file hashes to by-memory `30108F6F17D13E401E344F36570D7782E03AB7875108CCAAF18C94BC97A1903F`, by-class `177E9CDDCC21E52918D7962E9152E0B63E82E13BD4ACAE394639F720B953FF69`, and by-file `3EC509AA92378C15437367BEE35C8961DB7E1515F7EBDAEC0C800F41D0E14F89` without changing this target-family block. Current read-only comparison finds all 20 exact by-memory handoff rows, both exact class rows, and the exact file row once; requested UIDs 0004RJ/RK/RL/RM/RN/RO/RP, 0003OU, 0003OW, 0000AG, 0000AH, and 0000MK each occur once in their affected file, and the obsolete standalone b4d-b63 thunk row is absent. B004 made no coverage edit.
- Historical shared generated baselines were command 13151 for generated memory coverage and command 13152 for the tracker. B004's waited refresh is command `000000013193`/PhotoPane SHA `4BBA93DBD6EAD618E42317A7C2E0270040C16B1693CAF54824AF2142205CCF2F`. External commands 13205 and 13207 later refreshed only generated provenance for this file; normalizing command 13207's command/time headers reproduces the exact command-13193 SHA and source semantics. Later supervisor command 13227 restored UID0003OU registry visibility and consequently exposed one UID0003OU Empty Emitter Marker from that unchanged legacy blank-emitter page; the six accepted source definitions and zero UID0001F3/UID0004RP marker assertions remain unchanged. This is an external metadata-recovery side effect, not a change to the accepted UID0001F3 implementation or command-13193 proof.
- Concrete prior-report search terms: `UID0001F3`, `0x00549b00`, `0x00549b63`, `PictureViewPaneCloseHandlersAndThunks`, `PictureViewPane`, `PhotoPane`, `OnMouseEvent`, `OnKeyEvent`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, `BulletinSession`, `MarkForDeletion`, EventHandler, close-handler, vtable, and source-family/owner terms.
- Active B001-B005 roots: no direct UID/address/target/family match in B001, B002, or B003; B004 matched only this goal; B005's then-active UID0003UB report was a broad-term false positive and contains no target UID/address/name evidence. No active shared destination plan was found.
- `tools/leaser/Agents/Older-Research/**`: searched with the concrete terms above; no matching Markdown report.
- `tools/leaser/Agents/SpecialReports/**`: searched with the concrete terms above; no matching Markdown report.
- Actual project archive root `archived/**`: inspected and contained zero Markdown reports, therefore no direct or indirect report match.
- Directly relevant executed report `executed-b-agent-research/B014/0001F2-PhotoAndPicturePanes-source-quality.md`, SHA256 `B9B097E0A0719526FA49AA2DC9B73077FC9D718471BE3EFFBEB590B5C90D0C33`: opened as a historical lead. It correctly proposed the three-way target split, rejected Bulletin ownership, and resolved `Pane::MarkForDeletion`, but it left the exact handler virtual names open and retained historical `HandleClose...`/`On...` candidates. Current Event/EventHandler contracts now resolve that gap.
- Directly relevant executed report `executed-b-agent-research/B005/0002R8-PhotoPaneCleanupDestructorBodyRaw-source-quality.md`, SHA256 `FBC17379EC81C4EC8B3854D17B31108776E02EE5074C9F4A3EDD2FAEE6B5DE3A`: opened as a historical lead. It independently establishes `0x00549ae0` as PictureViewPane base teardown, the raw PhotoPane cleanup as compiler destructor-family support, and no source ownership for vptr/adjustor mechanics.
- Relevant executed source-placement controls opened: B001 `0001AW-mappane-packet-source-split-audit.md` records the no-direct-caller PhotoPane factory companion; B015 `00037T-MapPanePacketDispatcher-source-quality.md` confirms the live `0x00508bc1` PhotoPane construction route; B003 `000167-SurfaceSpriteBlitHelper-source-quality.md` confirms PhotoPane paint as a generic GrafPort consumer. These support `PhotoPane.cpp` placement but do not own the target handlers.
- Incidental executed matches involving StaticObjImageLib/MapTileImageLib merely name PhotoPane as a consumer and were classified as non-owner evidence.

## Target

- Target UID: `0001F3`.
- Target path: `by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md`.
- Historical pre-callback tracker row at command 13152 listed UID0001F3 as `86/90`, reconstructable, and unsplit. Validator commands 13155-13193 supersede that ordinary/generated state; tracker/report lifecycle status remains external supervisor/validator-owned.
- Current ordinary classification: non-emitting mixed handler/thunk index routed semantically through UID0000AH.
- Current scores and parent state: target `92/94`, owner `0000AH`, blank emitter/position/formal C++, reconstructable false, `Nested:0`; UID0001F2 is also a non-emitting outer index.
- Exact target bytes: 99 bytes, SHA256 `0CF9BDD75316DA3D0A52CF5A86FD5CD401276BB1DF88A97C2C65EBFC723AD915`.

## Current Target State

- Historical pre-callback metadata asked one page to be both source emitter and ABI container and generated Empty Emitter Markers. The applied split eliminates that contradiction while preserving all historical evidence.
- UID0004RN and UID0004RO use the current EventHandler contracts `HandlePointerOrMouseEvent(Event *)` and `HandleKeyOrTextEvent(Event *)`; Event `m_type` values 3/6/8 map to left-button-up, right-button-up, and key-down. Historical `HandleClose...`/`On...` aliases remain rejected prose only.
- UID0001F2 and UID0001F3 are blank non-emitting indexes. UID0000AH/UID0000AG now contain complete source-clean class declarations before `[[CHILDREN]]`, and command 13193 emits their exact children without Empty Emitter Markers.
- UID0000MK now records all six source definitions, typed map data, implicit PhotoPane destruction, exact current handler names, and `0x00549ae0` as `PictureViewPane::~PictureViewPane`.
- UID0003OW is false/non-emitting/blank generated-vtable evidence; current UID0000VN shared page SHA `896D92EB...A4EF` still links real thunk child UID0004RP and records every exact Photo/Picture alignment hash. External command 13232 added unrelated PowerListPane material without changing B004 facts.
- Current raw-space arithmetic is mechanical from ordinary headers: let `I` be the cumulative indentation before UID0001F2. UID0001F2 `0` renders at `I`; UID0004RJ `+4` opens `I+4`; UID0002R8/UID0004RK/UID0004RL/UID0004RM/UID0001F3 retain `0`; UID0004RN `+4` opens `I+8`; UID0004RO/UID0004RP retain `0`; UID0001F4 `-8` restores `I`.
- Implementation and scoped validation are complete. Supervisor-owned manual coverage synchronization is also complete and independently verified by commands 13224-13228; report validation/execution/archive/count state remains external supervisor/validator-owned and is not asserted or directed by this artifact.
- B004 target-specific generated proof is command 13193/SHA `4BBA93DBD6EAD618E42317A7C2E0270040C16B1693CAF54824AF2142205CCF2F`; finalization-time external command 13207 is header-equivalent and does not alter source semantics. Command 13227's later registry recovery made the unchanged UID0003OU blank-emitter page visible as one generated UID0003OU Empty Emitter Marker while preserving all six accepted definitions and zero UID0001F3/UID0004RP marker state.

## Executive Recommendation

- Applied result retains the original UID0001F3 path/UID as a non-emitting structural index over the exact 99-byte interval.
- Seven children were registered serially in ascending address order with validator-issued UIDs:
  - `UID0004RJ` for `[0x00549620,0x00549911)`;
  - `UID0004RK` for `[0x00549950,0x005499a2)`;
  - `UID0004RL` for `[0x00549a30,0x00549ad6)`;
  - `UID0004RM` for `[0x00549ae0,0x00549aff)`;
  - `UID0004RN` for `[0x00549b00,0x00549b22)`;
  - `UID0004RO` for `[0x00549b30,0x00549b4d)`;
  - `UID0004RP` for `[0x00549b4d,0x00549b63)`.
- Every provisional UID token is replaced in the report before final cross-reference incorporation; no token remains.
- Exactly the PhotoPane constructor/OnPaint, PictureViewPane constructor/ordinary destructor, and two human handlers emit. Parent, alignment, thunk pair, scalar wrappers, vptr stores, complete-object arithmetic, and deletion flags do not emit; UID0002R8 retains only its accepted compiler marker.
- Complete source-clean `PictureViewPane` and `PhotoPane` declarations precede their children in `NexusTK/map/PhotoPane.cpp`, with the base class first.
- UID0001F2 and UID0003OW are non-emitting evidence/index pages with full histories retained. `0x00549ae0` is corrected to `PictureViewPane::~PictureViewPane`; PhotoPane cleanup remains implicit/compiler-caused.
- Raw-space deltas are applied exactly as `+4/0/.../+4/0/0/-8`, producing cumulative `I -> I+4 -> I+8 -> I`.

## Supervisor Active Recheck

- Historical Gate 1 required a report-only mixed-range split and source-identity resolution before any ordinary edit; exact report SHA `9876AB1945B50BE94C2224C2ACB596EF100ED964FD0D6D8C91E3B8317199A63B` was accepted before implementation.
- Every source-bearing interval inside UID0001F3 and every directly affected handwritten interval orphaned by the accepted class/file/UID0001F2 reclassification has a complete destination block. Every non-source byte has a concrete padding or compiler/no-code disposition.
- No source-bearing child remains deferred in the affected `PhotoPane`/`PictureViewPane` executable island.
- Historical temporary UID tokens were registration-only. They are now replaced by UID0004RJ through UID0004RP; the accepted ranges, paths, metadata, source bodies, and raw-space deltas are applied unchanged.

## Inference Research Guidance Check

- `by-structure.md`/validator nesting rules were applied literally: `Nested` is an address-order relative indentation-space delta, not child count or logical-level count. `validator_background.py` adds the integer directly to `indent_spaces`; therefore the target-child transition is `+4`, and the successor correction is `-4 -> -8` after two cumulative four-space child levels.
- Existing generated names were treated as uncertain: `BulletinSession::MarkForDeletion`, `HandleClose...`, `OnMouseEvent`, `OnKeyEvent`, and `PaneMessage` were not accepted without slot/type controls.
- Direct IDA fact, current documentation contract, and inference are separated below. The source method names are a strong project-contract inference from exact vtable slots; the event codes, ranges, bytes, call, and return are direct binary facts.
- Historical B014/B005 reports were revalidated as leads, not copied as authority. Their still-valid facts are preserved and their stale name/file/destructor claims are historicalized.
- No Wave2/Wave3 artifact was used. Any broad project-level legacy mention encountered during searches was ignored as stale absent a current explicit override.

## Heuristic / Inference Reanalysis And Validation

| Issue | Positive and control evidence | Ranked alternatives | Selected resolution and confidence |
| --- | --- | --- | --- |
| First handler identity | Address appears at PhotoPane secondary vtable `0x00622084` and PictureViewPane secondary vtable `0x00622120`; both are EventHandler slot `+0x04`. Current EventHandler declaration names this slot `HandlePointerOrMouseEvent(Event *)`. | 1. `HandlePointerOrMouseEvent(Event *)`; 2. `OnMouseEvent(Event *)`; 3. descriptive `HandleCloseMouseEvent(PaneMessage *)`. | Select `HandlePointerOrMouseEvent(Event *)`, 0.93. `OnMouseEvent` remains a historical alias; `HandleClose...` overfits one behavior and uses a rejected parameter type. |
| Second handler identity | Address appears at `0x00622088` and `0x00622124`, EventHandler slot `+0x08`; current declaration names it `HandleKeyOrTextEvent(Event *)`. | 1. `HandleKeyOrTextEvent(Event *)`; 2. `OnKeyEvent(Event *)`; 3. descriptive `HandleCloseKeyEvent(PaneMessage *)`. | Select `HandleKeyOrTextEvent(Event *)`, 0.93. |
| Return type | Both functions write `al=1` and `retn 4`; base virtuals and sibling controls use Boolean handled results. | `bool`, `char`, `int`. | Select `bool`, 0.97. The one-byte ABI return alone is ambiguous, but the exact base contract removes that ambiguity. |
| Parameter type | One pointer argument; dereference at `+0x04`; current Event class has `m_type` exactly there; sibling EventHandler overrides use mutable `Event *`. | `Event *`, `const Event *`, `PaneMessage *`, raw byte pointer. | Select `Event *`, 0.96. `const` is source-plausible but contradicts the accepted base declaration. |
| Event constants | Direct byte compares are `3`, `6`, `8`; Event enum maps them exactly to left-button-up, right-button-up, key-down. | Enum names, literal integers, old message constants. | Use current enum names in formal source while preserving numeric values in prose, 0.95. |
| Complete-object adjustment | Handler entry `this` is secondary EventHandler view at complete `+0xa0`; compiler emits `this-0xa0` before the Pane call. | Explicit pointer subtraction, cast helper, normal inherited call. | Source is normal `MarkForDeletion()` on `this`; explicit subtraction is rejected compiler ABI, 0.99. |
| Close helper | Callee `0x00544690` is Pane core deletion marker with broad 89-caller fanout and no bulletin state. | `Pane::MarkForDeletion`, BulletinSession helper, generic free/delete. | Select inherited `Pane::MarkForDeletion()`, 0.99. It marks pending deletion; it does not free immediately. |
| First-handler semantics | Close call occurs only for codes 3 or 6; every path returns true. | Close on button-up; close on all pointer events; propagate false when ignored. | Preserve exact two-code close and unconditional true, 0.99. |
| Second-handler semantics | Close call occurs only for code 8; every path returns true. | Close on key-down; escape-specific test hidden elsewhere; propagate false. | Preserve exact type-only key-down close and unconditional true. No key payload is read, 0.99. |
| Access/virtual spelling | Base interface methods are public pure virtuals; sibling panes declare/define public virtual overrides; no access metadata survives in binary. | public, protected, private. | Use public `virtual` methods without C++11 `override`, 0.78. Access spelling is the principal declaration-level cap. |
| Source era/style | Project source model and existing exact children use brace-on-next-line, explicit `virtual`, raw pointers, no `override`, and enum names. | Modern C++11 override/const style; decompiler-shaped C. | Use accepted project style, 0.90. |
| Target split | Historical pre-callback state mixed two function bodies, fourteen-byte padding, and two exact thunk functions under one emitter. | Three children; two source children plus leave thunks only in ignored; one mixed emitting page. | Selected and applied all three exact children. The compiler child gives durable range/no-code evidence while ignored retains byte-classification context, 0.98. |
| Relative nesting | Historical pre-callback address order was UID0001F2 `0`, UID0002R8 `+4`, UID0001F3 `0`, UID0001F4 `-4`; validator code adds each delta directly as spaces. Registered children now place UID0001F3 at outer cumulative `I+4`, and its pointer child opens `I+8`. | Raw-space `+4/-8`; rejected logical-level-count arithmetic; rejected flattening of target children at the outer level. | Selected and applied pointer `Nested:+4`, later target children `0`, and UID0001F4 `Nested:-8`, 1.00. This exactly matches the intended four-space manual hierarchy and restores the pre-UID0001F2 indentation. |
| Thunk source disposition | b4d subtracts `0xa0`, b58 subtracts `0xa4`; both tail-jump to scalar wrapper b70; each only has a vtable data xref. | Handwritten helper, adjustor thunk, padding. | Compiler-only destructor adjustor thunks; false/non-emitting/blank, 0.99. |
| Parent disposition | Parent contains two source bodies, padding, and ABI thunks; any one C++ block would duplicate children or hand-port glue. | Emitting aggregate, comment marker, false index. | False/non-emitting/blank index, 0.98. |
| Outer aggregate disposition | UID0001F2 spans many methods, padding, raw cleanup, thunks, and deleting wrappers; its historical pre-callback broad marker was not source. | Keep broad emitted comment, emit copied methods, false index. | Selected and applied false/non-emitting/blank while preserving full inventory, 0.94. Exact methods/classes remain the only emission route. |
| Vtable disposition | UID0003OW is pure RTTI/vtable data; class declaration and compiler own its regeneration. | Hand-port data, empty emitter marker, false generated-binary evidence. | False/non-emitting/blank, 0.99. |
| Source file | Contiguous PictureView/Photo island, sole PictureView constructor caller PhotoPane, shared vtable/destructor chain, existing map route, inherited handler addresses copied into PhotoPane table. | combined `PhotoPane.cpp`; adjacent `PictureViewPane.cpp`; generic Pane/EventHandler file; BulletinSession. | Combined `NexusTK/map/PhotoPane.cpp`, 0.84. Adjacent PictureViewPane.cpp remains 0.15; all others total below 0.01. |
| Adjacent destructor identity | `0x00549ae0` writes all three PictureView vtables; PhotoPane cleanup and scalar wrapper call/tail-jump to it after member cleanup; Picture scalar wrapper uses same base body. | PictureView ordinary destructor; PhotoPane destructor; generic teardown helper. | `PictureViewPane::~PictureViewPane`, 0.98. The historical pre-callback file/aggregate PhotoPane label was stale and is corrected. |
| PictureView constructor source | Exact `0xa6` body has one caller from PhotoPane construction, constructs `Pane(0)`, reads `g_activeMapPane` bounds, calls accepted `SetPaneOrder(NULL, g_activeMapPane)`, then `AddToLayer` with the current main-layer head. Vptr stores are compiler-only. | explicit constructor child; inline in PhotoPane; broad aggregate body; no-code. | Exact source child `PictureViewPane::PictureViewPane()`, 0.93. Sole derived-constructor caller, vtable stores, inherited helpers, and no derived field writes reject inline/no-code. |
| PictureView ordinary destructor source | Exact `0x1f` body is reached by PhotoPane raw cleanup, PhotoPane scalar wrapper, and constructor EH; it performs only compiler vptr reset plus Pane teardown. | explicit empty virtual destructor; implicit generated destructor; ABI pseudo-body. | Emit an explicit empty out-of-line `PictureViewPane::~PictureViewPane()` child, 0.90. This is the strongest project-consistent human source anchor; vptr/base lowering stays excluded. Implicit generation is the bounded runner-up, not an unresolved blocker. |
| PhotoPane constructor source | Exact `0x2f1` body, two packet/factory callers, `0x198` allocation, `C%04d.MAP`, 8-byte prefix plus 255 six-byte cells, 17-by-15 terrain/static loops, partial human descriptor seed, cached GrafPort, and exact render dependencies. | typed constructor child; raw byte/offset decompile; keep broad marker; no-code. | Emit an exact typed constructor child, 0.92. Use file-private `PhotoMapFileData`/`PhotoMapCell` declarations to preserve the opaque 8-byte header and six-byte records without byte-offset/stride arithmetic in the body. |
| PhotoPane temporary ObjectStatus source shape | Binary writes only status kind, appearance, body, weapon, shield/arrow, full-body, composition mode, display status, face color, and body color before the draw calls; other bytes are not seeded. | partial stack object; value-initialize whole blob; memset then assign; constructor helper. | Preserve a default/uninitialized local plus only the observed field writes, 0.95. Value initialization/memset is rejected because it would change the observed unseeded bytes consumed by the renderer. |
| PhotoPane OnPaint source | Exact one-block `0x52` method has one vtable ref and calls cached-port GetBounds, visible-port EndPaint, BlitSurface, then UpdateSurfaceInfo. | exact virtual OnPaint; inline generic paint; no-code. | Emit exact `PhotoPane::OnPaint()`, 0.96. The `EndPaint`/blit/reopen order is behavior, not a helper-name caveat. |
| PhotoPane destructor source cause | UID0002R8 raw cleanup and scalar wrapper both destroy `m_snapshotPort` then route to PictureView base teardown; no independent source-authored Photo destructor body is proved. | implicit virtual destructor; explicit empty destructor; handwritten ABI cleanup. | Omit a PhotoPane destructor declaration/body and let the compiler synthesize it from the virtual base and member, 0.94. Update UID0002R8 marker to say `implicit PhotoPane destructor`; explicit ABI cleanup is rejected. |
| Source body for destructor glue | Thunks and scalar wrappers encode vptr resets, flag tests, optional delete, and complete-object adjustments. | Emit pseudo-destructor body; emit proof comments; exact source destructor/implicit source cause. | Emit only the empty PictureView ordinary destructor and implicit Photo destructor source cause. Parent/thunk/scalar/vtable blocks stay blank; UID0002R8 retains one bounded compiler marker, 0.99. |
| Class/file emission order | PhotoPane derives from PictureViewPane; historical pre-callback output emitted Empty Markers for both classes, so the exact children required deterministic per-class ordering. | Picture then Photo; Photo then Picture with forward declaration; interleave children. | Applied PictureViewPane class position 10 and PhotoPane class position 20; Picture children use ctor/dtor/pointer/key positions 10/20/30/40, and Photo children use ctor/paint/raw-marker positions 10/20/30. This produces the coherent single source unit proved by command 13193, 0.97. |
| Bulletin ownership | No article/session/global fields, no Bulletin caller/table, broad Pane helper fanout, exact Picture/Photo vtable refs. | PictureViewPane; BulletinSession. | PictureViewPane direct class owner; BulletinSession is rejected generated-name pollution, 0.99. |

No investigable target or associated source-emitter blocker remains. Residual uncertainty is limited to original file split, access spelling, the opaque meanings of the map header/reserved cell word, and explicit-versus-implicit spelling of the empty PictureView destructor; each is ranked, source-shaped, and score-capped without changing range, behavior, owner/emitter, generated ABI, or selected formal bodies.

## Evidence Standards Used

- Direct binary evidence: current-session MCP function boundaries, raw bytes, decompilation, disassembly, CFG block counts, xrefs, vtable cells, constructor/destructor stores, caller/callee profiles, and adjacent padding.
- Current contract evidence: accepted `EventHandler`, `Event`, `Pane`, sibling handler children, class/file/aggregate/vtable docs, and source-emitter routing.
- Generated evidence: historical pre-callback command-13151 `PhotoPane.cpp`/memory readbacks and command-13152 tracker readback establish the old state; target-specific command 13193 establishes B004 callback truth, and external command 13205 is header-equivalent. Commands 13151/13141/13148/13122/13105/13067 remain historical checkpoints.
- Mechanical metadata evidence: current ordinary `Nested` headers plus `validator_background.py` line 6458 establish raw-space cumulative arithmetic independently of source/ABI inference.
- Historical evidence: opened executed B014/B005 plus bounded source-placement controls, revalidated against current MCP/current docs.
- Negative evidence: no code callers for handlers, vtable-only liveness, no bulletin state, no raw-start direct route for cleanup, no alternate derived PictureView class, no embedded source filename, no active B-agent destination collision, and no direct Older-Research/SpecialReports/archive report.
- Evidence ladder application: bytes/ranges/xrefs/vtable slots are exact facts; handler names/types use accepted current interface contracts; source file/access are ranked inferences and cap confidence below final-proof levels.

## Evidence Checked

- MCP setup: fresh `idb_list`; `server_health(database=64c11373)`; bounded `lookup_funcs`, `get_bytes`, `decompile`, `disassemble`, function analysis/profile, `xrefs_to`, vtable-name/byte, constructor/destructor, and helper-call checks. All valid bounded calls completed against database `64c11373` after correcting the local serialization error.
- Target/closure function checks: `0x00549620`, `0x00549950`, `0x00549a30`, `0x00549ae0`, `0x00549b00`, `0x00549b30`, `0x00549b4d`, `0x00549b58`, scalar wrapper `0x00549b70`, `GetStaticObjectBounds` `0x004dd850`, `Pane::SetPaneOrder` `0x00544d30`, and `Pane::MarkForDeletion` `0x00544690`.
- Byte checks: all four new source-child intervals, the four exact alignment gaps around them, exact target subranges, target full interval, and post-target alignment. Hashes and bytes are recorded in `IDA MCP Facts`.
- Closure decompilation/caller checks: complete PhotoPane constructor, PhotoPane OnPaint, PictureViewPane constructor, PictureViewPane ordinary destructor, `GetStaticObjectBounds`, and `SetPaneOrder`; xrefs to all four new source functions; typed ObjectStatusBlob/StaticObjImageLib/MapTileImageLib/GrafPort contracts; and compiler cleanup parity through UID0002R8/scalar/EH.
- Vtable checks: PhotoPane/PictureViewPane bases `0x00622034`, `0x00622080`, `0x006220b0`, `0x006220d0`, `0x0062211c`, `0x0062214c`; handler cells `0x00622084`, `0x00622088`, `0x00622120`, `0x00622124`; thunk cells `0x0062211c`, `0x0062214c`.
- Current docs opened: UID0001F3, UID0000AH, UID0000MK, UID0001F2, UID000265, UID0003OW, UID0001EA, UID0000AG, UID0002R8, UID00004N, UID00004L, UID0000A2, UID0001F4, UID0000VN, and exact sibling pointer/key handler children.
- Historical report-only nesting check reread UID0001F2/UID0002R8/UID0001F3/UID0001F4 as `0/+4/0/-4`, inspected `tools/validator_background.py` line 6458, and calculated `I -> I+4 -> I+8 -> I`. Current ordinary headers are UID0001F2 `0`, UID0004RJ `+4`, later outer siblings `0`, UID0004RN `+4`, UID0004RO/UID0004RP `0`, and UID0001F4 `-8`; validators 13155-13192 applied the exact arithmetic.
- Historical generated/tracker checks used commands 13151/13152 only to establish the pre-callback baseline. Current target-specific generated proof is waited command 13193; B004 did not manually edit generated or tracker files.
- Manual coverage roots were reread read-only after supervisor reconciliation and later external commands 13234-13236: current `by-memory/-coverage-report.md` SHA256 `30108F6F17D13E401E344F36570D7782E03AB7875108CCAAF18C94BC97A1903F`; `by-class/-coverage-report.md` SHA256 `177E9CDDCC21E52918D7962E9152E0B63E82E13BD4ACAE394639F720B953FF69`; `by-file/-coverage-report.md` SHA256 `3EC509AA92378C15437367BEE35C8961DB7E1515F7EBDAEC0C800F41D0E14F89`. Exact-line comparison found 20/20 by-memory handoff rows, 2/2 class rows, and 1/1 file row present exactly once, with zero copies of the obsolete standalone thunk row.
- Shared-page drift check reread current `by-memory/-ignored.md` SHA `896D92EB...A4EF` and proved the complete B004 inventory remains: `[0x00549911,0x00549920)` fifteen `0xcc`/`54CC...624C`; `[0x005499b8,0x005499c0)` alignment/no source; `[0x00549a22,0x00549a30)` fourteen `0xcc`/`1E87...4356`; `[0x00549ad6,0x00549ae0)` ten `0xcc`/`22E5...045`; `[0x00549aff,0x00549b00)` one `0xcc`/`1DD8...D6`; `[0x00549b22,0x00549b30)` fourteen `0xcc`/`1E87...4356`; `[0x00549b63,0x00549b70)` thirteen `0xcc`/`0D0B...F1CE`; and UID0004RP `[0x00549b4d,0x00549b63)` exact 22-byte `7ABE...9E67` adjustor-thunk/no-source record with `this-0xa0`/`this-0xa4`, scalar-wrapper target `0x00549b70`, and vtable-only liveness. New PowerListPane padding/reference material is unrelated external B001 content.
- Prior-report roots searched with the exact term set: active B001-B005, central `executed-b-agent-research`, `Older-Research`, `SpecialReports`, and actual `archived`. Relevant paths and outcomes are listed in `Supporting Research`.
- Negative checks: no ordinary code caller to either handler; no caller except thunk jumps to the scalar wrapper from this interval; no bulletin/session fields or routes; no independent source semantic in either thunk; no source filename string; no alternate active report/lease evidence.
- Historical report-only phase skipped IDA mutation, ordinary edits, leases, validators, and generated refresh as required. The authorized callback used only ordinary leases/scoped validators and one waited refresh; it still performed no IDA mutation, manual coverage edit, or report lifecycle/count/probe/execute/move/archive action.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1F3-001 | Target exact interval is `[0x00549b00,0x00549b63)`, 99 bytes, SHA256 `0CF9...915`. | Exact | MCP bytes/functions | UID0001F3 range/evidence | incorporate | applied |
| C1F3-002 | `[0x00549b00,0x00549b22)` is a 34-byte source handler, SHA256 `ABD2...AAD`. | Exact | MCP bytes/lookup | new pointer child | incorporate | applied |
| C1F3-003 | `[0x00549b22,0x00549b30)` is fourteen `0xcc`, SHA256 `1E87...356`. | Exact | MCP bytes | UID0000VN and parent inventory | incorporate | applied |
| C1F3-004 | `[0x00549b30,0x00549b4d)` is a 29-byte source handler, SHA256 `3998...9AE`. | Exact | MCP bytes/lookup | new key child | incorporate | applied |
| C1F3-005 | `[0x00549b4d,0x00549b63)` is a 22-byte two-thunk interval, SHA256 `7ABE...E67`. | Exact | MCP bytes/functions | new thunk child | incorporate | applied |
| C1F3-006 | `[0x00549b63,0x00549b70)` is thirteen `0xcc`, SHA256 `0D0B...F1CE`, outside target. | Exact | MCP bytes | UID0000VN/support inventory | already-present | already-present |
| C1F3-007 | First handler is EventHandler secondary slot `+0x04` in both PhotoPane and PictureViewPane vtables. | Exact | vtable cells/xrefs | new pointer child, UID0003OW | incorporate | applied |
| C1F3-008 | First source identity is `HandlePointerOrMouseEvent(Event *)`. | Very high | current EventHandler contract plus exact slot | child/class/file | incorporate | applied |
| C1F3-009 | First handler closes only on event types 3 and 6 and always returns true. | Exact | decomp/disassembly | new pointer child | incorporate | applied |
| C1F3-010 | Event types 3 and 6 are `kEventLeftButtonUp` and `kEventRightButtonUp`. | Very high | current Event enum and byte compares | new pointer child | incorporate | applied |
| C1F3-011 | Second handler is EventHandler secondary slot `+0x08` in both vtables. | Exact | vtable cells/xrefs | new key child, UID0003OW | incorporate | applied |
| C1F3-012 | Second source identity is `HandleKeyOrTextEvent(Event *)`. | Very high | current EventHandler contract plus exact slot | child/class/file | incorporate | applied |
| C1F3-013 | Second handler closes only on type 8 and always returns true. | Exact | decomp/disassembly | new key child | incorporate | applied |
| C1F3-014 | Event type 8 is `kEventKeyDown`; no key payload is inspected. | Very high | current Event enum and binary access set | new key child | incorporate | applied |
| C1F3-015 | Source return type is bool, not raw char/int. | Very high | base virtual contract and AL return | both handler children | incorporate | applied |
| C1F3-016 | Source parameter is mutable `Event *`, not PaneMessage/raw byte/const Event. | Very high | base contract and Event layout | children/class | incorporate | applied |
| C1F3-017 | `this-0xa0` is compiler normalization from the secondary EventHandler subobject. | Exact | layout/vtable/disassembly | target/children/class | incorporate | applied |
| C1F3-018 | Human source calls inherited `MarkForDeletion()` without explicit adjustment. | Very high | Pane helper identity and C++ ABI | both bodies | incorporate | applied |
| C1F3-019 | `0x00544690` is `Pane::MarkForDeletion`, not BulletinSession behavior. | Exact | PaneCore and 89-caller fanout | all owner/support docs | incorporate | applied |
| C1F3-020 | BulletinSession owner/helper labels are rejected generated pollution. | Very high | no state/route plus exact class vtables | target/class/file/history | reject-stale | applied |
| C1F3-021 | b4d subtracts `0xa0` and tail-jumps to b70. | Exact | disassembly | thunk child | incorporate | applied |
| C1F3-022 | b58 subtracts `0xa4` and tail-jumps to b70. | Exact | disassembly | thunk child | incorporate | applied |
| C1F3-023 | Both thunk starts are vtable-only compiler destructor glue. | Exact | xrefs/vtables/shape | thunk child/ignored | incorporate | applied |
| C1F3-024 | b70 is the `0x55`-byte scalar deleting wrapper reached by both thunks. | Exact | lookup/xrefs/decomp | thunk/target/class support | incorporate | applied |
| C1F3-025 | Thunk child must be false/non-emitting/blank with no pseudo-source/proof comment. | Very high | compiler-only no-code proof | new thunk child | incorporate | applied |
| C1F3-026 | UID0001F3 must become false/non-emitting/blank split index at 92/94. | Very high | mixed-range and generator evidence | UID0001F3 | incorporate | applied |
| C1F3-027 | UID0001F3 retains semantic owner UID0000AH and Nested 0. | Very high | vtable/class and hierarchy | UID0001F3 | incorporate | applied |
| C1F3-028 | Pointer child is true, owner/emitter UID0000AH, position 30, score 92/94. | High | exact body and source order after ctor/dtor | new pointer child | incorporate | applied |
| C1F3-029 | Key child is true, owner/emitter UID0000AH, position 40, score 92/94. | High | exact body and source order after ctor/dtor/pointer | new key child | incorporate | applied |
| C1F3-030 | Thunk child is false, owner UID0000AH, blank emitter/position, score 93/95. | Very high | exhaustive compiler proof | new thunk child | incorporate | applied |
| C1F3-031 | The first UID0001F3 child uses `Nested:+4` because validator nesting is a raw indentation-space delta; later target children use `0`. | Exact | current predecessor chain plus validator line 6458 | three new pages | incorporate | applied |
| C1F3-032 | UID0001F4 `Nested` must change `-4` to `-8` to unwind both cumulative four-space child levels and restore the pre-UID0001F2 indentation. | Exact | raw-space cumulative calculation `I -> I+4 -> I+8 -> I` | UID0001F4 header/generated hierarchy | incorporate | applied |
| C1F3-033 | UID0000AH class becomes 92/94, emitter position 10, with a complete class-before-children block. | High | interface/layout/source evidence | by-class/PictureViewPane.md | incorporate | applied |
| C1F3-034 | Class formal declares constructor, virtual destructor, and both public virtual handlers. | High | constructor/destructor/vtable/base controls | class formal block | incorporate | applied |
| C1F3-035 | UID0000MK remains selected `NexusTK/map/PhotoPane.cpp`, raised to 92/94 after exact source closure. | High | contiguous island/caller/inheritance and complete emitter graph | by-file/PhotoPane.md | incorporate | applied |
| C1F3-036 | Adjacent `0x00549ae0` is PictureViewPane ordinary destructor/base teardown, not PhotoPane destructor. | Very high | vtable stores and caller chain | class/file/aggregate | reject-stale | applied |
| C1F3-037 | UID0001F2 becomes 92/94 false/non-emitting/blank mixed index after all handwritten intervals receive exact children. | High | mixed aggregate and complete exact-child policy | aggregate | incorporate | applied |
| C1F3-038 | UID0003OW becomes 91/94 false/non-emitting/blank generated-vtable evidence. | Very high | pure RTTI/vtable data | vtable child | incorporate | applied |
| C1F3-039 | UID000265 remains 86/92 false/no-owner and receives no ordinary edit. | Exact | current header/support sufficiency | verify-only | already-present | already-present |
| C1F3-040 | UID0001EA, Event, EventHandler, Pane, UID0003OU, UID000265, UID00004N, UID00004L, and UID0000A2 remain verify-only; PhotoPane and UID0002R8 are now bounded edits required for closure. | High | current same-or-greater detail and failed-gate recheck | verify-only/edit scope | incorporate | applied |
| C1F3-041 | Historical command-13151 output contained affected Empty Emitter Markers and a broad UID0001F2 marker that the accepted docs eliminated. | Exact | command-13151 semantic and index readbacks plus command-13193 proof | callback generated checks | incorporate | applied |
| C1F3-042 | Final generated output must contain exactly one definition of all six accepted source methods and no parent/thunk/vtable body or marker; generated memory coverage must render outer children four spaces below UID0001F2, target children four more below UID0001F3, and UID0001F4 back at the pre-UID0001F2 indentation. | High | complete emitter plan plus validator raw-space arithmetic | callback generated checks | incorporate | applied |
| C1F3-043 | No emitted source may contain `this-0xa0`, vptr stores, scalar flags, adjustor code, raw addresses, or BulletinSession owner text. | Very high | source-vs-ABI decision | formals/generated checks | incorporate | applied |
| C1F3-044 | UID0000VN retains padding facts and points thunk evidence to the real child after registration. | High | current ignored entries and exact bytes | by-memory/-ignored.md | incorporate | applied |
| C1F3-045 | Supervisor-owned manual coverage now contains the exact target/parent/two-class/file/vtable updates, seven child additions, four-space target-child indentation matching `Nested:+4`, padding reindent, and obsolete ignored-thunk row deletion. | Exact | current read-only exact-line comparison plus commands 13224-13228 | supervisor coverage handoff | incorporate | applied |
| C1F3-046 | Historical B014/B005 facts and rejected names remain preserved with current conclusions marked as superseding them. | High | opened executed reports/current checks | all changed docs/report | historicalize | applied |
| C1F3-047 | PhotoPane constructor is exact `[0x00549620,0x00549911)`, 753 bytes, SHA256 `FFED27EE3CA1F851EB57DBA68EEF6BCBACD153C24336FAB562FC380C046C2820`. | Exact | fresh MCP lookup/get_bytes/decompile | new PhotoPane constructor child | incorporate | applied |
| C1F3-048 | PhotoPane OnPaint is exact `[0x00549950,0x005499a2)`, 82 bytes, SHA256 `62A976504B80B7719FA2D9C1F0CED80951ACAB44A4E56128EDF7360D621E4228`. | Exact | fresh MCP lookup/get_bytes/decompile | new PhotoPane OnPaint child | incorporate | applied |
| C1F3-049 | PictureViewPane constructor is exact `[0x00549a30,0x00549ad6)`, 166 bytes, SHA256 `B4C06A216D7DB02FD058E2DDC284BE720E0AD98CA6908D28889C9545AAD5BE7E`. | Exact | fresh MCP lookup/get_bytes/decompile | new PictureView constructor child | incorporate | applied |
| C1F3-050 | PictureViewPane ordinary destructor is exact `[0x00549ae0,0x00549aff)`, 31 bytes, SHA256 `C006663591B5CB770F02C6576190D6290FE5057A439AC8DD3D1BC88D76CF3DE5`. | Exact | fresh MCP lookup/get_bytes/decompile/xrefs | new PictureView destructor child | incorporate | applied |
| C1F3-051 | PhotoPane constructor has exactly two code callers, while OnPaint has one vtable data xref; both are live source methods. | Exact | fresh MCP xrefs | children/class/file | incorporate | applied |
| C1F3-052 | PictureView constructor has the sole PhotoPane constructor caller; ordinary destructor has raw cleanup, scalar-wrapper, and constructor-EH routes. | Exact | fresh MCP xrefs | children/class/file | incorporate | applied |
| C1F3-053 | Photo map payload is an opaque 8-byte header followed by 15x17 six-byte records `{terrainTileId,reserved,staticObjectId}`. | Very high | pointer start, loop bounds, stride, field reads | constructor formal/type notes | incorporate | applied |
| C1F3-054 | Constructor preserves the observed partial ObjectStatusBlob seed and must not zero/value-initialize unseeded bytes. | Very high | exact write set and renderer consumption | constructor formal/negative evidence | incorporate | applied |
| C1F3-055 | OnPaint exact order is cached GetBounds, visible EndPaint, BlitSurface, then UpdateSurfaceInfo. | Exact | decompile/callees | OnPaint formal | incorporate | applied |
| C1F3-056 | PictureView constructor source is `Pane(0)`, active-map bounds, `SetPaneOrder(NULL,g_activeMapPane)`, and `AddToLayer` through the main layer head. | High | decompile plus accepted Pane helper contracts | constructor formal | incorporate | applied |
| C1F3-057 | PictureView ordinary destructor source is an empty out-of-line virtual destructor; vptr/base teardown is compiler lowering. | High | exact body plus project destructor controls | destructor formal/class | incorporate | applied |
| C1F3-058 | PhotoPane source omits an explicit destructor; UID0002R8/raw/scalar cleanup is generated from implicit virtual destruction, `m_snapshotPort`, and the PictureView base. | High | raw/scalar/constructor-EH parity | Photo class and UID0002R8 marker | incorporate | applied |
| C1F3-059 | Four source children must register before the three accepted target children, all in ascending address order, with every temporary UID replaced before cross-linking. | Exact | validator registration rule/address order | callback sequence/report/coverage | incorporate | applied |
| C1F3-060 | Photo ctor child is 92/93, owner/emitter UID0000AG, position 10, Nested +4; OnPaint is 92/94, position 20, Nested 0. | High | exact source behavior/order/nesting | two Photo children | incorporate | applied |
| C1F3-061 | Picture ctor child is 92/94, owner/emitter UID0000AH, position 10, Nested 0; destructor is 93/95, position 20, Nested 0. | High | exact source behavior/order/nesting | two Picture children | incorporate | applied |
| C1F3-062 | UID0000AG becomes 92/93 at file-emitter position 20 with complete source-clean class block and implicit destructor; UID0000AH remains before it at position 10. | High | inheritance and source graph | class pages/generated order | incorporate | applied |
| C1F3-063 | UID0002R8 retains 90/92 and its compiler marker, changes Nested 4 to 0, takes class-child position 30, and says implicit PhotoPane destructor. | High | existing accepted evidence plus new first child | UID0002R8 | incorporate | applied |
| C1F3-064 | Four exact ignored padding spans remain no-source: 15, 14, 10, and 1 `0xcc` bytes around the new methods with recorded hashes. | Exact | fresh MCP get_bytes and current ignored page | UID0000VN/aggregate inventory | incorporate | applied |
| C1F3-065 | UID0003OU PhotoPane vtable remains verify-only source-declared/generated-binary support; the Photo class/method children regenerate it without hand-porting data. | Very high | current vtable page and emission plan | verify-only UID0003OU | already-present | already-present |
| C1F3-066 | Historical pre-callback generated baseline command 13151/SHA `2B0F...CD90` normalizes to command-13141 SHA `4432...2B2C`, whose target semantics equal historical command 13122/SHA `EBEC...22AD`; command 13193 supersedes that target state. | Exact | generated header/hash/readback plus normalized-header comparison and command 13193 | report/validator baseline | historicalize | applied |
| C1F3-067 | Final generated source must order PictureViewPane before PhotoPane and contain no explicit PhotoPane destructor definition or accepted declared-but-undefined method. | High | inheritance/implicit-destructor plan | generated checks | incorporate | applied |
| C1F3-068 | UID0000MK and UID0001F2 can rise to 92/94 only because all source-bearing methods now have exact children and the compiler-only ranges have exact source causes. | High | complete source graph and score blocker closure | file/aggregate score rationale | incorporate | applied |

### Callback Claim Proof

- **C1F3-001**: UID0001F3 range/hash retained; 13176 applied 92/94 false/non-emitting.
- **C1F3-002**: UID0004RN exact 34-byte child registered and validated by 13163.
- **C1F3-003**: UID0000VN 13190 preserves fourteen-byte alignment and hash.
- **C1F3-004**: UID0004RO exact 29-byte child registered and validated by 13164.
- **C1F3-005**: UID0004RP registered by 13166 and cleanly revalidated by 13167.
- **C1F3-006**: UID0000VN retains thirteen-byte post-target alignment and hash.
- **C1F3-007**: UID0003OW 13187 records secondary slots and real handler UIDs.
- **C1F3-008**: UID0004RN/class formal and command 13193 use HandlePointerOrMouseEvent(Event *).
- **C1F3-009**: UID0004RN preserves type 3/6 checks, MarkForDeletion, and true return.
- **C1F3-010**: UID0004RN maps values to left/right-button-up enums.
- **C1F3-011**: UID0003OW 13187 records +0x08 slot and UID0004RO.
- **C1F3-012**: UID0004RO/class formal and 13193 use HandleKeyOrTextEvent(Event *).
- **C1F3-013**: UID0004RO preserves type 8 check, MarkForDeletion, and true return.
- **C1F3-014**: UID0004RO uses kEventKeyDown and reads no key payload.
- **C1F3-015**: Both formals/class use bool; 13193 emits exact bool definitions.
- **C1F3-016**: Both formals/class use mutable Event *.
- **C1F3-017**: Handler pages retain ABI evidence; 13193 emits no explicit adjustment.
- **C1F3-018**: Generated handlers call inherited MarkForDeletion() normally.
- **C1F3-019**: Target/class/file preserve Pane::MarkForDeletion ownership evidence.
- **C1F3-020**: Histories reject BulletinSession; 13193 contains zero such text.
- **C1F3-021**: UID0004RP records exact -0xa0 thunk and jump.
- **C1F3-022**: UID0004RP records exact -0xa4 thunk and jump.
- **C1F3-023**: UID0004RP/UID0003OW retain vtable-only compiler liveness.
- **C1F3-024**: UID0004RP retains scalar-wrapper target 0x00549b70.
- **C1F3-025**: UID0004RP is 93/95 false/blank; Destination 8 equality passed.
- **C1F3-026**: UID0001F3 13176 applied 92/94 false/non-emitting/blank.
- **C1F3-027**: UID0001F3 retains owner 0000AH and Nested:0.
- **C1F3-028**: UID0004RN is 92/94, owner/emitter 0000AH, position30, Nested:+4.
- **C1F3-029**: UID0004RO is 92/94, owner/emitter 0000AH, position40, Nested:0.
- **C1F3-030**: UID0004RP is 93/95, owner0000AH, false/blank, Nested:0.
- **C1F3-031**: UID0004RN Nested:+4 advances cumulative I+4 to I+8.
- **C1F3-032**: UID0001F4 13192 changed only Nested:-4 to -8, restoring I.
- **C1F3-033**: UID0000AH 13178 applied 92/94, position10, class-before-children.
- **C1F3-034**: Destination 9 equality passed with all accepted declarations.
- **C1F3-035**: UID0000MK 13182 applied 92/94 and preserved PhotoPane.cpp route.
- **C1F3-036**: Support pages identify 0x00549ae0 as PictureViewPane teardown.
- **C1F3-037**: UID0001F2 13185 applied 92/94 false/blank complete index.
- **C1F3-038**: UID0003OW 13187 applied 91/94 false/blank vtable evidence.
- **C1F3-039**: UID000265 stayed read-only at SHA 4F6D41FA...A5C5AB6.
- **C1F3-040**: Bounded edits applied; listed Event/Pane/vtable dependencies stayed read-only.
- **C1F3-041**: Command 13193 removed affected Empty Emitter and broad markers.
- **C1F3-042**: 13193 emits six definitions; headers prove I -> I+4 -> I+8 -> I.
- **C1F3-043**: PhotoPane.cpp has zero Bulletin/this-0xa0/vptr/adjustor source.
- **C1F3-044**: UID0000VN command 13190/SHA `9F5E...C6CF` is historical callback proof; current post-13232 SHA `896D92EB...A4EF` preserves all seven Photo/Picture padding intervals, five exact hash values, and the complete UID0004RP 22-byte adjustor-thunk/no-source link and evidence.
- **C1F3-045**: Supervisor commands 13224-13228 applied and verified the real-UID/+4 manual hierarchy; 20/20 by-memory, 2/2 class, and 1/1 file expected rows occur exactly once, the obsolete thunk row occurs zero times, and B004 made no coverage edit.
- **C1F3-046**: B014/B005 histories remain with stale names superseded.
- **C1F3-047**: UID0004RJ 13155 registered exact 753-byte constructor/hash.
- **C1F3-048**: UID0004RK 13157 registered exact 82-byte OnPaint/hash.
- **C1F3-049**: UID0004RL 13159 registered exact 166-byte constructor/hash.
- **C1F3-050**: UID0004RM 13161 registered exact 31-byte destructor/hash.
- **C1F3-051**: UID0004RJ/UID0004RK preserve caller and vtable liveness.
- **C1F3-052**: UID0004RL/UID0004RM preserve constructor and destructor routes.
- **C1F3-053**: UID0004RJ uses opaque header[8] and 15x17 six-byte typed cells.
- **C1F3-054**: UID0004RJ preserves observed ObjectStatusBlob writes only.
- **C1F3-055**: UID0004RK preserves GetBounds/EndPaint/Blit/Update order.
- **C1F3-056**: UID0004RL preserves Pane(0), bounds, order, and layer source.
- **C1F3-057**: UID0004RM is exact empty source destructor; no ABI source emits.
- **C1F3-058**: UID0000AG omits destructor; UID0002R8 names implicit source cause.
- **C1F3-059**: 13155/157/159/161/163/164/166 registered children in address order.
- **C1F3-060**: UID0004RJ/UID0004RK match accepted scores/positions/nesting/formals.
- **C1F3-061**: UID0004RL/UID0004RM match accepted scores/positions/nesting/formals.
- **C1F3-062**: UID0000AG 13180 applied 92/93 position20; 13193 orders base first.
- **C1F3-063**: UID0002R8 13188 retained 90/92, position30/Nested0/exact marker.
- **C1F3-064**: UID0000VN 13190 records exact accepted padding hashes.
- **C1F3-065**: UID0003OU research semantics stayed verify-only; supervisor command 13227 inserted only the required metadata-header separator, restored its legacy registry/reference mapping, and produced current SHA `155F7DFF...6540` without changing score, metadata values, or formal disposition.
- **C1F3-066**: Command 13151 and earlier are historical; current target proof is 13193.
- **C1F3-067**: 13193 orders classes, emits no PhotoPane destructor, defines all methods.
- **C1F3-068**: UID0000MK/UID0001F2 13182/13185 applied 92/94 after full closure.

## Positive Evidence Summary

- The two source bodies have exact function objects, distinct vtable slots, one Event argument, direct event-type tests, one Pane method call, and unconditional handled return.
- The same handler addresses occur in both PictureViewPane and derived PhotoPane secondary tables, proving inheritance from PictureViewPane rather than PhotoPane-local duplication.
- Current EventHandler and Event definitions resolve both method signatures and all three constants without inventing types.
- Both ABI thunks are tiny subtract-and-tail-jump bodies with only vtable data refs and a shared scalar wrapper target, the canonical MSVC adjustor pattern.
- The single PictureViewPane constructor caller, contiguous class island, shared destructor chain, and inherited PhotoPane vtable cells strongly support the existing `map/PhotoPane.cpp` route.
- Fresh closure evidence proves four additional handwritten functions: the PhotoPane constructor has two packet/factory callers, PhotoPane OnPaint occupies a live vtable slot, the PictureView constructor has the sole derived-constructor caller, and the PictureView ordinary destructor is reached by raw cleanup, scalar destruction, and constructor EH.
- The PhotoPane constructor's exact 8-byte-prefix/6-byte-cell access pattern supports typed `PhotoMapFileData` and `PhotoMapCell` source declarations. The two 15x17 loops consume terrain and static-object fields without raw body offsets or byte strides.
- The PhotoPane destructor source cause is complete without a handwritten body: an implicit virtual destructor plus `m_snapshotPort` and the explicit PictureView base destructor regenerates the raw cleanup/scalar/vtable mechanics while avoiding an undefined declaration.
- Historical command 13151 demonstrated the practical blocker: blank source-bearing class blocks produced Empty Emitter Markers instead of methods. Command 13193 supersedes that state with exact declarations/definitions and no affected empty marker.
- Current ordinary metadata and validator code prove the hierarchy arithmetic: one outer child level is four raw spaces, one UID0001F3 child level adds four more, and UID0001F4 subtracts eight to return to the original cumulative indentation.

## IDA MCP Facts

- Database: `64c11373`; original target transport session `bf162efd-f422-4522-ad3e-d4f2d0c77f85`; additive source-closure transport session `b11637c0-513e-4642-a1b6-7ed971eb218c`; server health was `ok` at both evidence checkpoints.
- Function boundaries:
  - `0x00549620-0x00549911`, size `0x2f1`, PhotoPane constructor;
  - `0x00549950-0x005499a2`, size `0x52`, PhotoPane OnPaint;
  - `0x00549a30-0x00549ad6`, size `0xa6`, PictureViewPane constructor;
  - `0x00549ae0-0x00549aff`, size `0x1f`, PictureViewPane ordinary destructor;
  - `0x00549b00-0x00549b22`, size `0x22`, 13 instructions, four blocks;
  - `0x00549b30-0x00549b4d`, size `0x1d`, 10 instructions, three blocks;
  - `0x00549b4d-0x00549b58`, size `0x0b`, two instructions;
  - `0x00549b58-0x00549b63`, size `0x0b`, two instructions;
  - `0x00549b70-0x00549bc5`, size `0x55`, scalar deleting wrapper;
  - `0x00549a30-0x00549ad6`, size `0xa6`, PictureViewPane constructor (listed above as an affected source child and retained here in address-family context).
- Exact bytes/hashes:
  - PhotoPane constructor: 753 bytes; SHA256 `FFED27EE3CA1F851EB57DBA68EEF6BCBACD153C24336FAB562FC380C046C2820`.
  - PhotoPane OnPaint: 82 bytes; SHA256 `62A976504B80B7719FA2D9C1F0CED80951ACAB44A4E56128EDF7360D621E4228`.
  - PictureViewPane constructor: 166 bytes; SHA256 `B4C06A216D7DB02FD058E2DDC284BE720E0AD98CA6908D28889C9545AAD5BE7E`.
  - PictureViewPane ordinary destructor: 31 bytes; SHA256 `C006663591B5CB770F02C6576190D6290FE5057A439AC8DD3D1BC88D76CF3DE5`.
  - a11-a20 padding: fifteen `cc`; SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`.
  - a22-a30 padding: fourteen `cc`; SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
  - ad6-ae0 padding: ten `cc`; SHA256 `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`.
  - aff-b00 padding: one `cc`; SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`.
  - b00 child: `55 8b ec 8b 45 08 8a 40 04 3c 03 74 04 3c 06 75 0b 81 c1 60 ff ff ff e8 74 ab ff ff b0 01 5d c2 04 00`; SHA256 `ABD2DA3A7EEC64A90DED652F2C0DE1AD6210BE8D54AEA83B2854733DF35B7AAD`.
  - b22 padding: fourteen `cc`; SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
  - b30 child: `55 8b ec 8b 45 08 80 78 04 08 75 0b 81 c1 60 ff ff ff e8 49 ab ff ff b0 01 5d c2 04 00`; SHA256 `3998295CB2DD9BD7560D41825D39604801F85A00EC3FD093CA1CB685EF2949AE`.
  - b4d thunk interval: `81 e9 a0 00 00 00 e9 18 00 00 00 81 e9 a4 00 00 00 e9 0d 00 00 00`; SHA256 `7ABECA077468FC37DAA15918CF0EAD3B3CCF6376E7E813BFED54518339FB9E67`.
  - b63 padding: thirteen `cc`; SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`.
  - b00-b63 full target SHA256 `0CF9BDD794E7499BCBCFB705BC318EC41B4B755F9FC2067A932CF2123F7AD915`.
- First-handler decompilation: read `event+4`; for values 3 or 6 call `sub_544690(this-160)`; return 1.
- Second-handler decompilation: read `event+4`; for value 8 call `sub_544690(this-160)`; return 1.
- Thunk disassembly: b4d subtracts `0xa0`; b58 subtracts `0xa4`; both tail-jump to b70.
- Vtable cells:
  - PhotoPane secondary `0x00622080`: destructor adjustor at `+0`, b00 at `+4`, b30 at `+8`;
  - PictureViewPane secondary `0x0062211c`: b4d at `+0`, b00 at `+4`, b30 at `+8`;
  - PictureViewPane tertiary `0x0062214c`: b58 at `+0`, inherited default `0x00544e90` at `+4`.
- Xrefs: b00 has data refs at `0x00622084`/`0x00622120`; b30 at `0x00622088`/`0x00622124`; b4d at `0x0062211c`; b58 at `0x0062214c`; b70 has thunk code refs at b53/b5e and primary vtable ref `0x006220d0`.
- Negative MCP facts: no ordinary code caller for b00 or b30; no independent semantic caller for either thunk; no bulletin state/global access; no alternate call besides Pane deletion marker; no body uses key or pointer payload beyond `m_type`.
- Fresh closure call/xref facts: PhotoPane constructor has exactly `0x00508bc1` and `0x00514461`; OnPaint has only vtable data xref `0x00622078`; PictureView constructor has only `0x0054965d`; PictureView ordinary destructor has raw cleanup `0x0054994b`, scalar-wrapper `0x005499ed`, and constructor-EH `0x006060c3` routes.
- PhotoPane constructor source facts: `PictureViewPane()` then `m_snapshotPort`; `C%04d.MAP`; exact partial ObjectStatusBlob seed; typed 8-byte prefix plus 255 six-byte map cells; 17-by-15 terrain and static-object loops; `GetStaticObjectBounds`, `RenderStaticObject`, `CalculateBounds`, `Draw`, and `EndPaint`.
- PhotoPane OnPaint source facts: cached-port `GetBounds`, visible `EndPaint`, `BlitSurface`, then `UpdateSurfaceInfo` in one block.
- PictureView constructor source facts: `Pane(0)`, active-map bounds, accepted `SetPaneOrder(NULL, g_activeMapPane)`, then `AddToLayer` using the main UI layer head. MCP decompilation of `0x00544d30` reconfirms EventHandler-subobject registration/order and rejects create/show shorthand.
- PictureView destructor source facts: no derived member cleanup or handwritten side effect; only compiler vptr resets and base teardown, supporting an empty source body and excluding ABI pseudo-source.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x00549620,0x00549911)` | `UID0004RJ` / `by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md` | source constructor | true | UID0000AG | 92/93 | registered child; emit position 10; Nested +4 |
| `[0x00549911,0x00549920)` | UID0000VN ignored | alignment | false | UID0001F2 structural interval | 100/strong | existing; fifteen `0xcc`; unchanged source disposition |
| `[0x00549920,0x00549950)` | UID0002R8 existing path | compiler destructor cleanup/unwind | true comment marker | UID0000AG | 90/92 | retain UID/path/score; position 30; Nested becomes 0; marker says implicit destructor |
| `[0x00549950,0x005499a2)` | `UID0004RK` / `by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md` | source virtual | true | UID0000AG | 92/94 | registered child; emit position 20; Nested 0 |
| `[0x00549a22,0x00549a30)` | UID0000VN ignored | alignment | false | UID0001F2 structural interval | 100/strong | existing; fourteen `0xcc`; unchanged source disposition |
| `[0x00549a30,0x00549ad6)` | `UID0004RL` / `by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md` | source constructor | true | UID0000AH | 92/94 | registered child; emit position 10; Nested 0 |
| `[0x00549ad6,0x00549ae0)` | UID0000VN ignored | alignment | false | UID0001F2 structural interval | 100/strong | existing; ten `0xcc`; unchanged source disposition |
| `[0x00549ae0,0x00549aff)` | `UID0004RM` / `by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md` | source ordinary destructor | true | UID0000AH | 93/95 | registered child; emit position 20; Nested 0 |
| `[0x00549aff,0x00549b00)` | UID0000VN ignored | alignment | false | UID0001F2 structural interval | 100/strong | existing; one `0xcc`; unchanged source disposition |
| `[0x00549b00,0x00549b63)` | UID0001F3 existing path | mixed split index | false | UID0000AH semantic owner | 92/94 | retain UID/path; blank/no emitter |
| `[0x00549b00,0x00549b22)` | `UID0004RN` / `by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md` | source virtual | true | UID0000AH | 92/94 | registered child; emit position 30; Nested +4 raw spaces |
| `[0x00549b22,0x00549b30)` | UID0000VN ignored | alignment | false | UID0001F3 structural interval | 100/strong | existing; reindent manual row under split parent |
| `[0x00549b30,0x00549b4d)` | `UID0004RO` / `by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md` | source virtual | true | UID0000AH | 92/94 | registered child; emit position 40; Nested 0 |
| `[0x00549b4d,0x00549b63)` | `UID0004RP` / `by-memory/0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md` | compiler ABI | false | UID0000AH semantic owner | 93/95 | registered child; blank/no emitter; Nested 0 |
| `[0x00549b63,0x00549b70)` | UID0000VN ignored | alignment outside target | false | UID0001F2 interval | 100/strong | unchanged |
| `[0x00549b70,0x00549bc5)` | existing aggregate/class evidence | scalar deleting wrapper | compiler-only source consequence | UID0000AH | existing | no target child/no body |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00508bc1`, `0x00514461` | two code calls -> PhotoPane constructor | exact live packet/factory construction routes; no third caller. |
| `0x00622078` | PhotoPane primary vtable -> OnPaint | exact virtual source liveness; no ordinary code caller required. |
| `0x0054965d` | PhotoPane constructor -> PictureViewPane constructor | sole direct construction relation and source placement evidence. |
| `0x0054994b`, `0x005499ed`, `0x006060c3` | PhotoPane raw/scalar/EH -> PictureViewPane ordinary destructor | exact base teardown/source-cause route. |
| `0x00622084` | PhotoPane secondary table -> b00 | inherited pointer/mouse override remains PictureViewPane source. |
| `0x00622088` | PhotoPane secondary table -> b30 | inherited key/text override remains PictureViewPane source. |
| `0x00622120` | PictureViewPane secondary table -> b00 | exact class/slot ownership. |
| `0x00622124` | PictureViewPane secondary table -> b30 | exact class/slot ownership. |
| `0x0062211c` | PictureViewPane secondary table -> b4d | destructor adjustor thunk, no source method identity. |
| `0x0062214c` | PictureViewPane tertiary table -> b58 | destructor adjustor thunk, no source method identity. |
| `0x00549b17` | b00 -> `0x00544690` | conditional inherited `Pane::MarkForDeletion`. |
| `0x00549b42` | b30 -> `0x00544690` | conditional inherited `Pane::MarkForDeletion`. |
| `0x00549b53`/`0x00549b5e` | thunk jmps -> b70 | scalar deleting destructor route. |
| `0x004dd850`, `0x004dd2c0` | PhotoPane constructor -> StaticObjImageLib bounds/render | typed static-object snapshot rendering dependency. |
| `0x004e09e0`, `0x004e06a0` | PhotoPane constructor -> NewHumanImageLib bounds/draw | exact avatar descriptor consumer and placement dependency. |
| `0x004b98c0`, `0x004ba250`, `0x004b9820` | PhotoPane OnPaint -> EndPaint/BlitSurface/UpdateSurfaceInfo | exact cached-to-visible paint sequence. |

## Documentation Evidence And IDA Status

- Historical pre-callback documentation state: UID0001F3 had strong behavior evidence but stale names and a structurally invalid mixed emitter state. The accepted callback retained its UID/path/range and repaired it as the 92/94 false, non-emitting, blank split index over real children UID0004RN through UID0004RP.
- Historical pre-callback documentation state: UID0000AH had exact constructor/vtable/destructor evidence but lacked a class formal, current Event contract names, and a resolved stale-name caveat. The accepted callback installed the complete PictureViewPane declaration and current handler identities while preserving that evidence.
- Historical pre-callback documentation state: UID0000MK had the correct map source route and complete cluster inventory but mislabeled `0x00549ae0` as `PhotoPane::~PhotoPane` and retained historical handler aliases. The accepted callback corrected the ordinary destructor to `PictureViewPane::~PictureViewPane` and synchronized the real child graph and current EventHandler names.
- Historical pre-callback documentation state: UID0000AG had strong constructor/layout/destructor-family evidence but no class formal or exact constructor/paint children, and generated output contained its Empty Emitter Marker. The accepted callback installed Destinations 2, 3, and 10 through UID0004RJ/UID0004RK and removed that marker in waited command 13193.
- Historical pre-callback documentation state: UID0002R8 already had accepted exhaustive compiler evidence and a comment-only formal, but its marker used generic `PhotoPane::~PhotoPane` wording and `Nested:+4`. The accepted callback preserved its score/binary proof, rebased the source cause to the implicit PhotoPane destructor, and applied `Nested:0` beneath real first child UID0004RJ.
- Historical pre-callback documentation state: UID0001F2 contained all ranges but still emitted a broad marker instead of acting as the source-cluster index. The accepted callback made it false/non-emitting/blank and synchronized exact real-child links and corrected identities.
- Historical pre-callback documentation state: UID0003OW supplied exact table cells and stores but still had an emitting disposition. The accepted callback preserved that evidence and applied the 91/94 false/no-emitter/blank generated-binary state regenerated through the class declaration.
- Historical pre-callback documentation state: UID000265 already had the correct false/no-owner aggregate disposition and required no ordinary callback edit. It remained verify-only; supervisor commands 13224/13228 externally applied and verified its exact aggregate/vtable manual coverage rows without a B004 edit.
- Generated commands 13067/13105/13122/13141/13148/13151 and tracker command 13152 are historical checkpoints. B004 foreground command `000000013193` at `2026-07-15T14:50:20-04:00` produced PhotoPane.cpp SHA256 `4BBA93DBD6EAD618E42317A7C2E0270040C16B1693CAF54824AF2142205CCF2F`, 6,644 bytes, with the accepted source semantics. External command 13205 later changed only provenance headers.
- Command-13193 readback proves one PictureViewPane class before one PhotoPane class; one each PhotoPane constructor/OnPaint and PictureViewPane constructor/destructor/pointer/key definition; one updated UID0002R8 marker; zero then-visible affected Empty Emitter Markers; zero UID0001F2/UID0001F3/UID0003OW/UID0004RP marker or body; zero explicit PhotoPane destructor; zero stale alias/Bulletin owner definition; and no accepted declaration without its exact definition. Command 13227 later exposed only the unchanged legacy UID0003OU Empty Emitter Marker through registry recovery. Ordinary Nested headers and the externally applied real-UID manual coverage encode UID0001F2 at `I`, outer children at `I+4`, target children at `I+8`, and UID0001F4 restored to `I`.

## Ranked Ownership Analysis

### 1. UID0000AH PictureViewPane

- Evidence for: exact PictureViewPane secondary slots, constructor stores, ordinary/scalar destructor stores, complete-object adjustment from its EventHandler subobject, and inheritance into PhotoPane tables.
- Evidence against: no original source filename string and no direct non-vtable caller to the virtuals.
- Decision: direct semantic/source class owner and handler emitter; very high confidence.

### 2. UID0000AG PhotoPane

- Evidence for: derived table contains the same two handler addresses; it is the sole confirmed derived class and sole PictureViewPane constructor caller.
- Evidence against: handlers first belong to PictureViewPane slots and read no PhotoPane member; inherited address reuse is not source ownership.
- Decision: derived consumer/inheritor only; verify-only support.

### 3. Pane/EventHandler infrastructure

- Evidence for: supplies base contracts and `MarkForDeletion` implementation.
- Evidence against: target functions are concrete PictureViewPane overrides in Picture/Photo vtables, not base defaults.
- Decision: contract/helper support, not target owner.

### 4. BulletinSession

- Evidence for: only historical generated-name pollution.
- Evidence against: no vtable, field, caller, source route, state, or feature semantic; broad Pane helper fanout.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- No new source file is recommended. Keep both classes in `NexusTK/map/PhotoPane.cpp` for current reconstruction.
- The new by-memory pages are exact function/range children, not a new source module.
- An adjacent `NexusTK/map/PictureViewPane.cpp` remains the runner-up only because the binary has no source filename evidence; it is not selected and no split file should be created.

## Source Placement

- Recommended placement: [UID:0000MK] `NexusTK/map/PhotoPane.cpp`, with [UID:0000AH] `PictureViewPane` declared/emitted before derived [UID:0000AG] `PhotoPane`.
- Fit: PictureViewPane and PhotoPane are contiguous, constructor/destructor linked, share inherited handler addresses, and serve the map-photo viewer feature. The existing file route already owns the derived snapshot constructor/paint flow.
- Rejected `Pane.cpp`/`EventHandler.cpp`: these supply generic base contracts but do not own concrete vtables.
- Rejected `BulletinSession.cpp`: no evidence beyond a stale generated helper label.
- Rejected standalone generic viewer file: weaker than the existing combined module absent another derived class or filename string.
- Remaining uncertainty: combined versus adjacent PictureViewPane source file. It caps file confidence at 93 but does not block current emission through UID0000MK.

## Range / Split / Padding / Reclassification Analysis

- Exact half-open split:
  1. source `[0x00549620,0x00549911)` PhotoPane constructor;
  2. ignored alignment `[0x00549911,0x00549920)`;
  3. compiler cleanup `[0x00549920,0x00549950)` UID0002R8;
  4. source `[0x00549950,0x005499a2)` PhotoPane OnPaint;
  5. existing PhotoPane adjustor/scalar support through `[0x00549a22)`;
  6. ignored alignment `[0x00549a22,0x00549a30)`;
  7. source `[0x00549a30,0x00549ad6)` PictureViewPane constructor;
  8. ignored alignment `[0x00549ad6,0x00549ae0)`;
  9. source `[0x00549ae0,0x00549aff)` PictureViewPane ordinary destructor;
  10. ignored alignment `[0x00549aff,0x00549b00)`;
  11. UID0001F3 target interval, internally:
  1. source `[0x00549b00,0x00549b22)`;
  2. ignored alignment `[0x00549b22,0x00549b30)`;
  3. source `[0x00549b30,0x00549b4d)`;
  4. compiler ABI `[0x00549b4d,0x00549b63)`.
- No byte overlaps or gaps exist in either the accepted target split or the directly affected source island. The target ends exactly before thirteen-byte post-target alignment.
- UID0001F3 remains at the same path/range/UID as a split index and was not renamed to either handler.
- All seven pages were registered serially in ascending address order as UID0004RJ, UID0004RK, UID0004RL, UID0004RM, UID0004RN, UID0004RO, and UID0004RP. Every current cross-reference and externally applied supervisor-owned manual coverage row uses those real UIDs; no temporary Gate 1 planning placeholder remains.
- Parent metadata: false, no emitter, no position, blank formal, owner UID0000AH, Nested 0.
- Island nesting uses raw spaces. Let `I` be the indentation before UID0001F2: UID0001F2 `0` leaves `I`; PhotoPane constructor `+4` opens the outer child level; UID0002R8, PhotoPane OnPaint, PictureView constructor/destructor, and UID0001F3 `0` retain `I+4`; pointer child `+4` opens the target-child level at `I+8`; key/thunk children `0` retain `I+8`; UID0001F4 `-8` closes both levels and returns to `I`.
- Internal b22 padding remains in ignored docs, and no padding page was created. Existing b4d ignored prose was retained as supporting classification linked to real compiler child UID0004RP; supervisor command 13224 applied deletion of its obsolete standalone manual ignored row, and command 13228 verified the row remains absent.
- Outer UID0001F2 is now a false/non-emitting/blank source-cluster index with all source/history/range evidence retained.
- UID0003OW is source-declared/generated-binary evidence, but the page itself is non-emitting; the compiler regenerates tables from class declarations/definitions.
- UID0003OU remains verify-only generated-binary evidence. Supervisor command 13227 restored its legacy registry mapping and inserted only the metadata-header separator; research semantics did not change. Registry visibility now exposes its unchanged blank-emitter metadata as one generated UID0003OU Empty Emitter Marker, while the PhotoPane class/constructor/OnPaint plus implicit destructor source cause remain the accepted table-regeneration route without hand-authored data bytes.

## Negative Evidence Summary

- No direct code caller reaches either handler; liveness is vtable-only. This supports virtual source methods, not dead/no-route helpers.
- No target body reads BulletinSession, article, board, session, map, PhotoPane snapshot, or feature globals.
- No handler performs immediate delete/free; `MarkForDeletion` marks Pane state.
- No key payload or pointer coordinates are read, so names such as escape-handler or click-hit-test overstate the binary.
- No thunk has a stack frame, argument read, branch semantic, or independent caller; handwritten helper classification is rejected.
- No evidence supports explicit `this-0xa0`, `this-0xa4`, vptr assignment, scalar flag, `operator delete`, or tail-jump source.
- No source filename string distinguishes `PhotoPane.cpp` from `PictureViewPane.cpp`; the report ranks rather than fabricates that proof.
- No evidence supports zero/value initialization of the whole local ObjectStatusBlob; only ten exact field assignments occur before the human-render calls.
- No evidence gives semantic names to the map file's first eight bytes or middle cell word; typed `header[8]`/`reserved` preserves exact layout without fabricated semantics.
- No separate handwritten PhotoPane destructor body exists. The compiler raw/scalar paths are fully explained by implicit virtual destruction, `m_snapshotPort`, and the PictureView base; an explicit Photo destructor definition would add unsupported source.
- No active B001-B005 report owns the target/shared destinations at search time; no lease was acquired or inferred from report absence.
- No direct matching report exists in Older-Research, SpecialReports, or the actual empty Markdown archive root.

## IDA Rename / Type / Comment Recommendations

- Applied documentation source-facing names: `PhotoPane::PhotoPane`, `PhotoPane::OnPaint`, `PictureViewPane::PictureViewPane`, `PictureViewPane::~PictureViewPane`, `PictureViewPane::HandlePointerOrMouseEvent`, `PictureViewPane::HandleKeyOrTextEvent`, and descriptive compiler page `PictureViewPaneDestructorAdjustorThunks`.
- Applied local/type vocabulary: `PhotoMapFileData`, `PhotoMapCell`, `terrainTileId`, `reserved`, `staticObjectId`, `mapFileName`, `mapFile`, `appearance`, `snapshotBounds`, `tileBounds`, `objectBounds`, and `avatarBounds`; none is an IDA label or raw-offset alias.
- Applied structural metadata: pointer child `Nested:+4`, key/thunk children `Nested:0`, and UID0001F4 `Nested:-8`. These remain raw indentation-space deltas and are not logical level counts.
- Applied parameter/type vocabulary: `Event *event`, `bool`, `event->m_type`, and current `EventType` enum constants.
- Applied support identity correction: `0x00549ae0` -> `PictureViewPane::~PictureViewPane` / ordinary base teardown.
- Preserve exact descriptive aliases only in historical/rejected-alternative prose: `HandleCloseMouseEvent`, `HandleCloseKeyEvent`, `OnMouseEvent`, `OnKeyEvent`, `PaneMessage`, and `BulletinSession::MarkForDeletion`.
- IDA database changes were neither requested nor authorized. The accepted names/types were applied only to documentation/source reconstruction destinations.

## First-Draft C++ Recommendation

Thirteen complete managed destination blocks follow. These are the only C++ in this artifact.

### Destination 1: UID0001F3 mixed parent

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2: `UID0004RJ`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
struct PhotoMapCell
{
    unsigned short terrainTileId;
    unsigned short reserved;
    unsigned short staticObjectId;
};

struct PhotoMapFileData
{
    unsigned char header[8];
    PhotoMapCell cells[15][17];
};
}

PhotoPane::PhotoPane(unsigned short mapId,
                     unsigned char avatarShape,
                     int avatarTileX,
                     int avatarTileY,
                     unsigned char avatarDirection)
    : PictureViewPane(),
      m_snapshotPort()
{
    SimpleUString mapFileName;
    mapFileName.Format(L"C%04d.MAP", mapId);

    DATFile mapFile;
    mapFile.Open(mapFileName);

    ObjectStatusBlob appearance;
    appearance.m_statusKind = ObjectStatusBlob::HumanObject;
    appearance.m_appearanceId = avatarShape;
    appearance.m_bodyId = 0;
    appearance.m_weaponId = 0xffff;
    appearance.m_shieldOrArrowId = 0x00ff;
    appearance.m_fullBodyId = 0xffff;
    appearance.m_compositionMode = 0;
    appearance.m_displayStatusByte = 0x50;
    appearance.m_faceColor = 0;
    appearance.m_bodyColor = 0;

    const PhotoMapFileData *mapData =
        (const PhotoMapFileData *)mapFile.GetDataPointer();

    RectBounds snapshotBounds;
    InitRectBounds(&snapshotBounds,
                   0,
                   0,
                   18 * g_mapTilePixelWidth,
                   16 * g_mapTilePixelHeight);
    SetBounds(&snapshotBounds, 0);
    OffsetRectBounds(&snapshotBounds,
                     -snapshotBounds.left,
                     -snapshotBounds.top);
    m_snapshotPort.SetBounds(&snapshotBounds);
    m_snapshotPort.UpdateSurfaceInfo();

    int row;
    int column;
    for (row = 0; row < 15; ++row)
    {
        for (column = 0; column < 17; ++column)
        {
            RectBounds tileBounds;
            InitRectBounds(&tileBounds,
                           column * g_mapTilePixelWidth,
                           row * g_mapTilePixelHeight,
                           (column + 1) * g_mapTilePixelWidth,
                           (row + 1) * g_mapTilePixelHeight);

            g_pMapTileImageLib->DrawTile(
                &m_snapshotPort,
                &tileBounds,
                mapData->cells[row][column].terrainTileId);
        }
    }

    for (row = 0; row < 15; ++row)
    {
        for (column = 0; column < 17; ++column)
        {
            const unsigned short staticObjectId =
                mapData->cells[row][column].staticObjectId;
            if (staticObjectId != 0)
            {
                RectBounds objectBounds;
                g_pStaticObjImageLib->GetStaticObjectBounds(
                    staticObjectId,
                    &objectBounds);
                OffsetRectBounds(&objectBounds,
                                 column * g_mapTilePixelWidth,
                                 row * g_mapTilePixelHeight);
                g_pStaticObjImageLib->RenderStaticObject(
                    &m_snapshotPort,
                    &objectBounds,
                    staticObjectId,
                    0,
                    0.0f,
                    false);
            }
        }
    }

    RectBounds avatarBounds;
    g_pNewHumanImageLib->CalculateBounds(
        &appearance,
        avatarDirection,
        0,
        0,
        &avatarBounds,
        0,
        true,
        true,
        0);
    OffsetRectBounds(&avatarBounds,
                     avatarTileX * g_mapTilePixelWidth,
                     avatarTileY * g_mapTilePixelHeight);
    g_pNewHumanImageLib->Draw(
        &m_snapshotPort,
        &avatarBounds,
        &appearance,
        avatarDirection,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        true,
        true,
        0);

    m_snapshotPort.EndPaint();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3: `UID0004RK`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PhotoPane::OnPaint()
{
    RectBounds bounds;
    m_snapshotPort.GetBounds(&bounds);
    EndPaint();
    BlitSurface(&m_snapshotPort, &bounds, &bounds, 0);
    UpdateSurfaceInfo();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4: `UID0004RL`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PictureViewPane::PictureViewPane()
    : Pane(0)
{
    RectBounds bounds;
    g_activeMapPane->GetBounds(&bounds);
    SetPaneOrder(0, g_activeMapPane);
    AddToLayer(&bounds, 0, g_activeMapPane, g_mainUiLayerSlotsHead);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5: `UID0004RM`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PictureViewPane::~PictureViewPane()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6: `UID0004RN`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PictureViewPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonUp ||
        event->m_type == kEventRightButtonUp)
        MarkForDeletion();

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7: `UID0004RO`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PictureViewPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
        MarkForDeletion();

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8: `UID0004RP`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9: UID0000AH PictureViewPane class

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class PictureViewPane : public Pane
{
public:
    PictureViewPane();
    virtual ~PictureViewPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 10: UID0000AG PhotoPane class

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PhotoPane : public PictureViewPane
{
public:
    PhotoPane(unsigned short mapId,
              unsigned char avatarShape,
              int avatarTileX,
              int avatarTileY,
              unsigned char avatarDirection);

    virtual void OnPaint();

private:
    GrafPort m_snapshotPort;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 11: UID0001F2 outer aggregate

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 12: UID0003OW vtable data

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 13: UID0002R8 PhotoPane compiler cleanup marker

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted PhotoPane destructor cleanup/unwind body.
// Source-level cleanup is generated from the implicit PhotoPane destructor,
// the embedded GrafPort m_snapshotPort member, and the PictureViewPane base
// destructor; no standalone handwritten helper should be emitted for this
// raw non-function range.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: all six source definitions map one-to-one to the exact constructor/paint/destructor/handler behavior. The partial ObjectStatusBlob seed deliberately leaves the same unseeded bytes untouched; enum constants preserve values 3/6/8; normal member calls let the compiler regenerate complete-object adjustment and destructor lowering.
- Typed map source shape: the opaque eight-byte file header and six-byte cell layout eliminate body-level byte offsets, byte strides, and pointer indexing while preserving both 15x17 loops and the directly read terrain/static-object fields. `reserved` is intentionally not assigned a guessed semantic.
- Era/source shape: no C++11 `override`, no explicit vptr/delete flags, no decompiler variables, no address/offset evidence comments, and brace style follows current accepted NexusTK child formals.
- No-code proof for Destinations 1/8/11/12: target and outer aggregate mix ownership/range roles; thunk child is pure compiler glue; vtable child is compiler-generated data. Any body or proof marker would duplicate exact source children or emit reconstruction evidence as product source.
- UID0002R8 is the single bounded exception: its already-accepted comment marker records generated-binary cleanup without pretending to be a handwritten method. Destination 13 changes only the source cause from a generic named PhotoPane destructor to the directly supported implicit destructor/member/base relationship.
- Destination metadata paired with the formal blocks: Destination 1 UID0001F3 retains `Nested:0`; Destination 2 PhotoPane constructor uses `+4`; Destinations 3-5 use `0`; Destination 6 pointer handler uses `+4`; Destinations 7-8 use `0`; Destinations 9-13 retain the metadata stated in their ordinary recommendations. UID0001F4 has no formal destination and receives only the exact `-8` successor unwind.
- Third-party import directive: not applicable. All bytes are NexusTK project code/compiler output; no `third_party_embeds/...` source exists or is indicated.

## Final Recommendation

- The exact seven-child registration plan is applied in ascending address order with real UIDs 0004RJ through 0004RP; UID0001F3 is retained as a false/non-emitting index.
- Current EventHandler names/signatures are applied; historical aliases remain rejected evidence only.
- Exactly six human source definitions emit: PhotoPane constructor/OnPaint, PictureViewPane constructor/ordinary destructor, and the two accepted handlers.
- PictureViewPane emits before derived PhotoPane; PhotoPane's destructor remains implicit so compiler cleanup follows from `m_snapshotPort` and the explicit PictureViewPane destructor.
- The thunk child, target parent, outer aggregate, and vtable child are formally blank/non-emitting.
- Both class pages and file/aggregate/vtable/ignored/UID0002R8 support facts are corrected at report-level detail, including `0x00549ae0`, typed map-cell source, partial ObjectStatusBlob seed, and `+4/0/.../+4/0/0/-8` nesting.
- All accepted bytes, hashes, xrefs, vtable cells, historical findings, rejected alternatives, source-placement ranking, and compiler no-code proof are preserved.
- No implementation or manual-coverage item remains. B004 performed no report execution/move/archive/count/probe or manual coverage action; supervisor commands 13224-13228 externally applied and verified coverage, while report lifecycle state remains external supervisor/validator-owned and is neither asserted nor directed here.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md`.
- Header: `92/94`, owner `0000AH`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, Nested 0.
- Item Summary: `Non-emitting PictureViewPane close-handler/thunk split index with exact HandlePointerOrMouseEvent and HandleKeyOrTextEvent source children, fourteen-byte internal alignment, two compiler destructor-adjustor thunks, vtable-only liveness, Pane::MarkForDeletion behavior, Event type 3/6/8 contracts, and PhotoPane.cpp source routing.`
- Applied exact child inventory, bytes/hashes, source-vs-ABI reasoning, slot identities, source-name ranking, padding ownership, generated proof, and no-code proof.
- Retained target `Nested:0`; UID0004RN opens the second hierarchy level with `Nested:+4`, while UID0004RO/UID0004RP retain `0`.
- Preserved historical B014/B005 facts while labeling old names and Bulletin ownership rejected/superseded.

## Recommended Support Doc Changes

- Created UID0004RJ `by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md` first with accepted 92/93 owner/emitter/position/Nested/formal/evidence.
- Created UID0004RK `by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md` second with accepted 92/94 owner/emitter/position/Nested/formal/evidence.
- Created UID0004RL `by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md` third with accepted 92/94 owner/emitter/position/Nested/formal/evidence.
- Created UID0004RM `by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md` fourth with accepted 93/95 owner/emitter/position/Nested/formal/evidence.
- Created UID0004RN `by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md` fifth with accepted 92/94 owner/emitter/position/`Nested:+4`/formal/evidence.
- Created UID0004RO `by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md` sixth with accepted 92/94 owner/emitter/position/Nested/formal/evidence.
- Created UID0004RP `by-memory/0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md` seventh with accepted 93/95 false/non-emitting/blank/Nested/no-code evidence.
- `by-class/PictureViewPane.md` was rebased to 92/94 while retaining owner/emitter UID0000MK; file-emitter position 10, Destination 9 before `[[CHILDREN]]`, exact EventHandler names, constructor/destructor/handler links and behavior, source order, the no-ABI rule, and corrected `0x00549ae0` identity are applied.
- `by-class/PhotoPane.md` was rebased to 92/93 while retaining owner/emitter UID0000MK; file-emitter position 20, Destination 10 before `[[CHILDREN]]`, exact constructor/OnPaint links, typed map/layout behavior, `m_snapshotPort`, implicit destructor disposition, and compiler-cleanup explanation are applied.
- `by-file/PhotoPane.md` was rebased to 92/94 while preserving map-photo details and unrelated scores/formals; all four closure children, both class declarations, corrected `0x00549ae0`, current handler identities/signatures, typed map source, partial descriptor behavior, generated result, combined-vs-adjacent ranking, and rejected Bulletin route are applied.
- `by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md` was rebased to 92/94, retained owner UID0000MK, and became false with blank emitter/position/formal; Destination 11, the exact complete child index, corrected destructor identities, and removal of stale future-child wording are applied while complete unrelated cluster evidence is preserved. Item Summary: `Non-emitting PhotoPane/PictureViewPane executable index with exact source and compiler children, constructor/paint/destructor/handler families, typed map rendering, padding, vtable/string refs, caller/callee evidence, implicit PhotoPane cleanup, explicit PictureViewPane destructor, and map/PhotoPane.cpp routing.`
- `by-memory/0x006220cc-0x00622154.PictureViewPaneVtableData.md` was rebased to 91/94, retained owner UID0000AH, and became false with blank emitter/position/formal; Destination 12 and exact constructor/destructor/handler slot names are applied. Item Summary: `Non-emitting PictureViewPane primary/secondary/tertiary RTTI-vtable island with constructor/destructor stores, exact HandlePointerOrMouseEvent and HandleKeyOrTextEvent cells, compiler destructor-adjustor slots, and source regeneration through the PictureViewPane declaration.`
- `by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md` retained 90/92/owner/emitter and all exhaustive evidence; position 30, Nested 0, and Destination 13 are applied so its compiler marker names the implicit PhotoPane destructor/member/base source cause rather than implying an independent undefined body.
- `by-memory/-ignored.md`: validator 13190/callback SHA `9F5E...C6CF` preserved the grouped record/unrelated facts, added exact per-span hashes, and linked real thunk child UID0004RP while retaining no-source rationale. External B001 command 13232 added unrelated PowerListPane material; current SHA `896D92EB...A4EF` retains every B004 interval/hash/thunk fact unchanged.
- `by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md`: validator 13192 changed only `Nested:-4` to `Nested:-8`; score, owner, formal, and allocator content remain unchanged.
- Verify-only ordinary docs remained research-semantically unchanged: UID000265, UID0001EA, UID00004N, UID00004L, UID0000A2, MapTileImageLib, StaticObjImageLib, NewHumanImageLib, DATFile, SimpleUString, ObjectStatusBlob, RectBounds, and GrafPort. UID0003OU changed externally only by the command-13227 metadata-header separator/registry recovery recorded below; callback and reconciliation rereads found no semantic contradiction requiring scope expansion.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Applied | Metadata result | Why not higher |
| --- | --- | --- | --- | --- |
| UID0001F3 | 86/90 true/emitter AH | 92/94 false/no emitter | retain owner AH, blank position/formal, Nested 0 | original source file split remains inferred; parent is index, not source body. |
| UID0004RJ Photo ctor | absent | 92/93 true/emitter AG | position 10, Nested +4 | opaque map-header/reserved-cell semantics and exact helper spellings remain inferred. |
| UID0004RK Photo OnPaint | absent | 92/94 true/emitter AG | position 20, Nested 0 | exact original source spelling is inferred; behavior is exact. |
| UID0004RL Picture ctor | absent | 92/94 true/emitter AH | position 10, Nested 0 | exact layer/order helper spellings and file split remain inferred. |
| UID0004RM Picture dtor | absent | 93/95 true/emitter AH | position 20, Nested 0 | explicit-empty versus implicit source spelling cannot be recovered, though source cause/body is bounded. |
| UID0004RN pointer child | absent | 92/94 true/emitter AH | position 30, Nested +4 raw spaces | exact original access spelling/source filename not proved. |
| UID0004RO key child | absent | 92/94 true/emitter AH | position 40, Nested 0 | same cap. |
| UID0004RP thunk child | absent | 93/95 false/no emitter | blank position/formal, Nested 0 | compiler selection can vary, though current ABI identity/no-code is exact. |
| UID0000AH | 86/88 | 92/94 | retain owner/emitter MK, position 10 | combined-vs-adjacent file and access spelling remain inferred. |
| UID0000AG | 86/88 | 92/93 | retain owner/emitter MK, position 20 | opaque map-header/reserved-cell meanings and helper spellings cap confidence. |
| UID0002R8 | 90/92 | unchanged | position 30, Nested 0, corrected marker source cause | exhaustive compiler evidence already supports score; only source graph/nesting changes. |
| UID0000MK | 88/88 | 92/94 | path unchanged | no embedded source filename or second derived-class control. |
| UID0001F2 | 87/89 true/emitter MK | 92/94 false/no emitter | retain owner MK, blank formal | complete index is exact; original file split remains inferred. |
| UID0003OW | 86/91 true/emitter AH | 91/94 false/no emitter | retain semantic owner AH | exact original declaration order/access can only be inferred from compiler tables. |
| UID0001F4 | 87/91 | unchanged | Nested -8 only | unrelated allocator evidence/formal untouched; exact raw-space unwind restores pre-UID0001F2 indentation. |

- Score-improvement work removed all accepted UID0001F3/source-graph blockers: exact hashes/ranges, four formerly missing source emitters, typed map payload, partial descriptor writes, paint order, explicit/implicit destructor source causes, Event type/signature, slot order, owner/helper, compiler split, class/file order, nesting, target-generated pollution, and the now externally applied manual coverage delta. Command 13227's later UID0003OU Empty Emitter Marker is separately recorded as a legacy registry-visibility side effect; it does not change the accepted target evidence or scores.
- Completion remains below 95 because exact original file split/access labels are not recoverable from current binary evidence, not because of deferred target research.
- Confidence remains below final-proof levels for source spelling, while thunk confidence reaches 95 under exhaustive bytes/xrefs/vtable/no-code proof.

## Open Questions With Attempted Resolution

- Combined `PhotoPane.cpp` versus adjacent `PictureViewPane.cpp`: checked constructor/destructor contiguity, derived caller/table reuse, existing source route, strings, RTTI, active reports, and historical reports. No filename string or alternate derived class exists. Select combined file; retain adjacent file only as bounded runner-up and score cap.
- Public versus protected handler declarations: checked base interface and sibling class formals. Binary cannot encode access. Select public because the accepted base slots and project sibling declarations are public; this does not alter ABI/body.
- Literal integers versus enum constants: checked current Event enum and exact values. Select enum constants; numbers remain documented as binary facts.
- `virtual` plus no `override`: checked project era/current formal style. Select explicit `virtual`; C++11 `override` is rejected as less plausible original source.
- PictureView ordinary destructor source spelling: exact body cannot distinguish explicit empty from implicit generation. Select explicit empty because the project models ordinary virtual destructor anchors as source methods and the class declaration otherwise names one; implicit is the bounded runner-up. No ABI pseudo-source is emitted.
- PhotoPane destructor source spelling: the absence of a separate source body plus exact raw/scalar/member/base parity selects an implicit virtual destructor. Do not add a declaration or definition merely to mirror compiler cleanup.
- Map payload declaration: exact body proves an 8-byte prefix and 255 six-byte cells; only terrain at +0 and static object at +4 are read. Select typed `PhotoMapFileData` with opaque header bytes and `reserved` middle word; semantic names for the header/middle word are rejected as unsupported.
- ObjectStatusBlob initialization: select only the exact observed field assignments. Value initialization, aggregate `{}`, memset, and helper construction are rejected because they seed bytes the binary leaves unseeded before renderer consumption.
- StaticObjImageLib request spelling: current dependency docs call the second render parameter `StaticObjectDrawRequest *`, while this caller directly supplies the bounds-shaped object consumed through left/top/right/bottom words. Destination 2 preserves direct `RectBounds` source semantics; the dependency's descriptive type spelling is a confidence cap, not an emitter gap or license for raw offsets/casts in the final class graph.
- Relative nesting arithmetic: inspected current predecessor headers and validator line 6458. Logical-level-count arithmetic is rejected because values are raw spaces. Select PhotoPane constructor `+4`, later outer siblings through UID0001F3 `0`, pointer child `+4`, key/thunk `0`, and UID0001F4 `-8`; cumulative indentation is exactly `I -> I+4 -> I+8 -> I`.
- No target or associated source-emitter question remains at `needs investigation`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-reconciliation baselines were by-memory `ECADB986...44CBE`, by-class `06B6EE6C...B470`, and by-file `E1DD2E37...0438`; at that checkpoint the affected rows were stale. Supervisor commands 13224-13228 subsequently applied and verified the exact handoff, producing snapshots `31DE8A59...88BA`, `DA137B8A...AAE6`, and `622F7D86...638E`. Later unrelated external commands 13234-13236 advanced the current full-file hashes to by-memory `30108F6F...1903F`, by-class `177E9CDD...FF69`, and by-file `3EC509AA...F89`, with the exact target rows unchanged.
- The following exact text is retained as the historical/expected supervisor-owned handoff with validator-issued UIDs 0004RJ through 0004RP already substituted. B004 did not apply manual coverage. Current exact-line comparison proves every expected row is present exactly once.

Historical expected `by-memory/-coverage-report.md` UID0001F2 replacement row, now present exactly once:

```text
    - [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md) 0x00549620-0x00549bc5 | mixed executable index | PhotoAndPicturePanes : non-reconstructable : 92% : very-strong : Non-emitting PhotoPane/PictureViewPane executable index preserving exact constructor/paint/destructor/handler source children, compiler cleanup/adjustor/scalar support, typed map rendering, partial avatar-descriptor seed, padding, vtable/string refs, caller/callee evidence, implicit PhotoPane cleanup, explicit PictureViewPane destructor, map/PhotoPane.cpp routing, and historical/rejected alternatives without broad duplicate C++.
```

Historical expected complete address-ordered real-UID block, now present as sixteen exact rows with each row occurring once:

```text
        - [UID:0004RJ][0x00549620-0x00549911.PhotoPaneConstructor](by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md) 0x00549620-0x00549911 | constructor | PhotoPaneConstructor : reconstructable : 92% : very-strong : Exact PhotoPane snapshot constructor; opens C%04d.MAP, preserves the observed partial ObjectStatusBlob seed, renders 15x17 typed terrain/static cells plus one avatar into m_snapshotPort, and excludes compiler vptr/EH lowering from source.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00549911-0x00549920 | padding | PhotoPane constructor to raw cleanup alignment : ignored : 100% : strong : Fifteen confirmed 0xcc bytes; SHA256 54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C.
        - [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) 0x00549920-0x00549950 | compiler destructor cleanup | PhotoPaneCleanupDestructorBodyRaw : reconstructable : 90% : very-strong : Retained generated-binary cleanup/unwind marker sourced by the implicit PhotoPane destructor, embedded GrafPort m_snapshotPort, and PictureViewPane base destructor; no standalone handwritten helper body.
        - [UID:0004RK][0x00549950-0x005499a2.PhotoPaneOnPaint](by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md) 0x00549950-0x005499a2 | method | PhotoPaneOnPaint : reconstructable : 92% : very-strong : Exact virtual OnPaint; obtains cached bounds, ends visible drawing, blits m_snapshotPort to the same bounds, then refreshes visible surface access.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005499b8-0x005499c0 | padding | PhotoPane adjustor thunks to scalar deleting destructor alignment : ignored : 100% : strong : Confirmed 0xcc alignment; no source body.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00549a22-0x00549a30 | padding | PhotoPane scalar deleting destructor to PictureViewPane constructor alignment : ignored : 100% : strong : Fourteen confirmed 0xcc bytes; SHA256 1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356.
        - [UID:0004RL][0x00549a30-0x00549ad6.PictureViewPaneConstructor](by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md) 0x00549a30-0x00549ad6 | constructor | PictureViewPaneConstructor : reconstructable : 92% : very-strong : Exact Pane(0)-derived constructor; reads g_activeMapPane bounds, registers pane order against it, attaches through the main UI layer head, and excludes compiler vptr stores.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00549ad6-0x00549ae0 | padding | PictureViewPane constructor to ordinary destructor alignment : ignored : 100% : strong : Ten confirmed 0xcc bytes; SHA256 22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045.
        - [UID:0004RM][0x00549ae0-0x00549aff.PictureViewPaneDestructor](by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md) 0x00549ae0-0x00549aff | ordinary destructor | PictureViewPaneDestructor : reconstructable : 93% : very-strong : Exact empty source destructor reached by PhotoPane raw cleanup/scalar deletion/constructor EH; compiler vptr resets and Pane base teardown are excluded from handwritten source.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00549aff-0x00549b00 | padding | PictureViewPane destructor to close-handler alignment : ignored : 100% : strong : One confirmed 0xcc byte; SHA256 1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6.
        - [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md) 0x00549b00-0x00549b63 | mixed handler/thunk index | PictureViewPaneCloseHandlersAndThunks : non-reconstructable : 92% : very-strong : Non-emitting split index with exact HandlePointerOrMouseEvent and HandleKeyOrTextEvent source children, fourteen-byte internal alignment, two compiler destructor-adjustor thunks, vtable-only liveness, Pane::MarkForDeletion behavior, Event type 3/6/8 contracts, and PhotoPane.cpp source routing.
            - [UID:0004RN][0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent](by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md) 0x00549b00-0x00549b22 | method | PictureViewPaneHandlePointerOrMouseEvent : reconstructable : 92% : very-strong : Exact EventHandler +0x04 override; closes on left/right button-up through inherited Pane::MarkForDeletion and always returns true, with compiler complete-object adjustment excluded from source.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00549b22-0x00549b30 | padding | PictureViewPane close-handler alignment : ignored : 100% : strong : Fourteen confirmed 0xcc bytes between exact source handlers; SHA256 1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356.
            - [UID:0004RO][0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent](by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md) 0x00549b30-0x00549b4d | method | PictureViewPaneHandleKeyOrTextEvent : reconstructable : 92% : very-strong : Exact EventHandler +0x08 override; closes on key-down through inherited Pane::MarkForDeletion and always returns true, with no key-payload read or compiler adjustment in source.
            - [UID:0004RP][0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks](by-memory/0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md) 0x00549b4d-0x00549b63 | compiler destructor support | PictureViewPaneDestructorAdjustorThunks : non-reconstructable : 93% : very-strong : Exact two-thunk interval; subtracts 0xa0/0xa4 and tail-jumps to the scalar deleting wrapper, has vtable-only refs, and emits no handwritten C++ or proof marker.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00549b63-0x00549b70 | padding | PictureViewPane thunks to scalar deleting destructor alignment : ignored : 100% : strong : Thirteen confirmed 0xcc bytes; SHA256 0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE.
```

Historical expected obsolete duplicate standalone-row deletion; current exact and phrase counts are both zero:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) : ignored : 80% : strong : Recorded in -ignored.md: `0x00549b4d-0x00549b63` - `PictureViewPane` secondary/tertiary adjustor thunks.
```

Historical expected UID000265/vtable replacement block, now present as three exact rows with each row occurring once:

```text
    - [UID:000265][0x00622034-0x00622154.PhotoPictureReadOnlyData](by-memory/0x00622034-0x00622154.PhotoPictureReadOnlyData.md) 0x00622034-0x00622154 | mixed-rdata index | PhotoPictureReadOnlyData : non-reconstructable : 86% : very-strong : Reviewed non-emitting PhotoPane/PictureViewPane read-only aggregate with exact vtable and C%04d.MAP children, executable xrefs, corrected 0x00622154 successor boundary, and source regeneration through map/PhotoPane.cpp declarations rather than hand-ported RTTI/vtable bytes.
        - [UID:0003OU][0x00622034-0x006220b8.PhotoPaneVtableData](by-memory/0x00622034-0x006220b8.PhotoPaneVtableData.md) 0x00622034-0x006220b8 | compiler vtable data | PhotoPaneVtableData : reconstructable : 86% : very-strong : Source-declared/generated-binary PhotoPane primary/secondary/tertiary vtables with constructor/raw-cleanup/scalar stores, inherited PictureView handlers, OnPaint, implicit-destructor source cause, C%04d.MAP successor boundary, and no hand-authored table bytes.
        - [UID:0003OW][0x006220cc-0x00622154.PictureViewPaneVtableData](by-memory/0x006220cc-0x00622154.PictureViewPaneVtableData.md) 0x006220cc-0x00622154 | compiler vtable data | PictureViewPaneVtableData : non-reconstructable : 91% : very-strong : Non-emitting PictureViewPane primary/secondary/tertiary RTTI-vtable island with constructor/destructor stores, exact HandlePointerOrMouseEvent and HandleKeyOrTextEvent cells, compiler destructor-adjustor slots, successor boundary, and source regeneration through the PictureViewPane declaration.
```

Historical expected `by-class/-coverage-report.md` replacement rows, now both present exactly once:

```text
- [UID:0000AG][PhotoPane](by-class/PhotoPane.md) : reconstructable : 92% : very-strong : Complete source-clean derived PhotoPane declaration with exact constructor and OnPaint children, typed C%04d.MAP 15x17 snapshot composition, partial ObjectStatusBlob seed, embedded GrafPort m_snapshotPort, implicit virtual destructor source cause, compiler cleanup separation, and map/PhotoPane.cpp routing.
- [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md) : reconstructable : 92% : very-strong : Complete source-clean PictureViewPane declaration with Pane inheritance, constructor/virtual destructor, exact HandlePointerOrMouseEvent and HandleKeyOrTextEvent overrides, split source/ABI children, Event type 3/6/8 behavior, Pane::MarkForDeletion ownership, vtable/destructor evidence, and map/PhotoPane.cpp routing.
```

Historical expected `by-file/-coverage-report.md` replacement row, now present exactly once:

```text
- [UID:0000MK][PhotoPane](by-file/PhotoPane.md) : reconstructable : 92% : very-strong : Source-complete map photo/viewer module with ordered PictureViewPane and PhotoPane declarations, exact PhotoPane snapshot constructor/OnPaint, explicit PictureViewPane constructor/destructor/close handlers, implicit PhotoPane destructor source cause, typed map-cell rendering, exact source-versus-compiler split, vtable/source evidence, and bounded combined-file versus adjacent-file ranking.
```

- Current `by-memory` coverage retains exact outer b63-b70 and bC5-bD0 padding rows; the first is included in the applied replacement block for address-order clarity. The applied block renders outer children four spaces below UID0001F2 and pointer/key/thunk rows four additional spaces below UID0001F3; this visual hierarchy corresponds to ordinary deltas `+4` and `+4`, not logical-level counts. UID0001F4's ordinary-page `Nested:-8` correction returns to the pre-UID0001F2 indentation without changing its manual row text/score/path.
- No tracker text was supplied or applied: the research tracker is generated/validator-owned. Manual coverage edits were performed only by the supervisor and remained forbidden to B004.

## Follow-Up Actions

- Supervisor-owned state: manual coverage application and verification are complete under commands 13224-13228. Report validation, execution, path movement, archive, and counting remain external to this artifact and authoritative only in supervisor/validator records.
- A-agent actions: none required by current evidence.
- B004 implementation state: all accepted ordinary edits, child registrations, validations, formal blocks, generated checks, ledger states, and checklist items are complete; no B004 implementation item remains.
- Manual coverage: exact real-UID by-memory/by-class/by-file handoff text remains as historical/expected evidence. Current read-only comparison proves external synchronization: 20/20 by-memory, 2/2 class, and 1/1 file rows occur exactly once, and the obsolete thunk row is absent. B004 did not perform the edits or validators.
- Generated freshness: target-specific command 13193 is the authoritative PhotoPane.cpp proof. Shared generated metadata may advance through unrelated validator work; those external header/hash changes do not change the recorded target semantics.

## Confidence

- Recommendation confidence: 94/100 overall.
- Score confidence: high; scores reflect exact binary/contract evidence while retaining source-file/access caps.
- Exact split/source-vs-ABI confidence: 98/100.
- Relative nesting confidence: 100/100 for pointer `+4`, key/thunk `0`, and UID0001F4 `-8`; current headers and the validator's direct raw-space addition make the cumulative arithmetic mechanical rather than inferential.
- Handler signature confidence: 93/100 for exact project-facing spelling; 97/100 for bool/Event pointer contract.
- Source-graph closure confidence: 92/100 for PhotoPane constructor, 96/100 for PhotoPane OnPaint, 93/100 for PictureViewPane constructor, 90/100 for explicit-empty PictureViewPane destructor spelling, and 94/100 for implicit PhotoPane destructor source cause.
- Source placement confidence: 84/100 for combined PhotoPane.cpp; 15/100 adjacent PictureViewPane.cpp; below 1/100 all rejected alternatives combined.

## Validator Results

- B004 callback commands 13155-13193 ran from `source-3/project-documentation` with scoped file validation; every command exited 0 with `ok:1`, and generated refresh completed on final waited command 13193. Supervisor-owned reconciliation commands 13224-13228 were not run by B004; each also exited 0 with `ok:1` and is recorded separately below.

| Command | Timestamp | Scoped final path | Exit / ok | Warnings and material side effects |
| --- | --- | --- | --- | --- |
| `000000013155` | `2026-07-15T14:29:39-04:00` | `by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md` | 0 / 1 | Registered UID0004RJ; path/registry/reference/stats updates; deferred generated refresh. |
| `000000013157` | `2026-07-15T14:30:39-04:00` | `by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md` | 0 / 1 | Registered UID0004RK; path/registry/reference/stats updates; deferred generated refresh. |
| `000000013159` | `2026-07-15T14:31:53-04:00` | `by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md` | 0 / 1 | Registered UID0004RL; path/registry/reference/stats updates; deferred generated refresh. |
| `000000013161` | `2026-07-15T14:33:00-04:00` | `by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md` | 0 / 1 | Registered UID0004RM; path/registry/reference/stats updates; deferred generated refresh. |
| `000000013163` | `2026-07-15T14:33:59-04:00` | `by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md` | 0 / 1 | Registered UID0004RN; path/registry/reference/stats updates; deferred generated refresh. |
| `000000013164` | `2026-07-15T14:34:50-04:00` | `by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md` | 0 / 1 | Registered UID0004RO; path/registry/reference/stats updates; deferred generated refresh. |
| `000000013166` | `2026-07-15T14:35:48-04:00` | `by-memory/0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md` | 0 / 1 | Registered UID0004RP; one `missing_ref_uid 0003OW` warning exposed an absent legacy registry mapping. No validator state was edited manually. |
| `000000013167` | `2026-07-15T14:36:08-04:00` | same UID0004RP path | 0 / 1 | Clean corrective rescan after replacing only that unresolved UID link with a path-only legacy-vtable link; warning cleared. |
| `000000013176` | `2026-07-15T14:40:26-04:00` | UID0001F3 target | 0 / 1 | Applied 92/94 true-to-false/no-emitter reclassification, real-child links, and references. |
| `000000013178` | `2026-07-15T14:42:05-04:00` | `by-class/PictureViewPane.md` | 0 / 1 | Applied 92/94, position 10, formal block hash, child links, and references. |
| `000000013180` | `2026-07-15T14:43:18-04:00` | `by-class/PhotoPane.md` | 0 / 1 | Applied 92/93, position 20, formal block hash, child links, and references. |
| `000000013182` | `2026-07-15T14:44:46-04:00` | `by-file/PhotoPane.md` | 0 / 1 | Applied 92/94 and seven real-child references; removed stale ignored-only reference. |
| `000000013185` | `2026-07-15T14:46:41-04:00` | UID0001F2 aggregate | 0 / 1 | Applied 92/94 true-to-false/no-emitter/blank reclassification and seven child references. |
| `000000013187` | `2026-07-15T14:47:32-04:00` | UID0003OW vtable page | 0 / 1 | Recovered its missing validator UID mapping, applied 91/94 false/blank state, inserted header separator, and indexed owner/file/aggregate refs. |
| `000000013188` | `2026-07-15T14:48:15-04:00` | UID0002R8 cleanup page | 0 / 1 | Applied emitter position 30 and exact updated marker hash; score/owner/emitter retained. |
| `000000013190` | `2026-07-15T14:49:19-04:00` | `by-memory/-ignored.md` | 0 / 1 | Indexed UID0004RP/UID0003OW. Reported 275 pre-existing unresolved UID references on this shared million-byte page; changed references validated, no new blocker. |
| `000000013192` | `2026-07-15T14:49:56-04:00` | UID0001F4 successor | 0 / 1 | Scoped validation passed after the sole `Nested:-8` change; unrelated metadata/formal unchanged. |
| `000000013193` | `2026-07-15T14:50:20-04:00` | UID0001F3 target with `--wait-generated` | 0 / 1 | Rebuilt 4,990 metadata nodes/4,019 edges; completed generated refresh; refreshed 280 generated metadata files and tracker; warnings were repository-wide autogen marker diagnostics, not target errors. |
| `000000013224` | `2026-07-15T15:27:30-04:00` | supervisor-owned `by-memory/-coverage-report.md` | 0 / 1 | Applied the exact by-memory handoff and obsolete-row deletion; exposed the previously missing legacy UID0003OU registry mapping. Generated side effects refreshed memory coverage, research tracker, and by-memory generated coverage with a 4,992-node/4,022-edge registry. |
| `000000013225` | `2026-07-15T15:27:37-04:00` | supervisor-owned `by-class/-coverage-report.md` | 0 / 1 | Applied the exact UID0000AG/UID0000AH rows; generated side effects refreshed class coverage and research tracker with the same 4,992-node/4,022-edge registry. |
| `000000013226` | `2026-07-15T15:27:39-04:00` | supervisor-owned `by-file/-coverage-report.md` | 0 / 1 | Applied the exact UID0000MK row; generated side effects refreshed file coverage and research tracker with the same 4,992-node/4,022-edge registry. |
| `000000013227` | `2026-07-15T15:28:25-04:00` | supervisor-scoped UID0003OU vtable page | 0 / 1 | Inserted only the required metadata-header separator and restored UID/path/owner/autogen/reference mapping; registry became 4,993 nodes/4,023 edges. Side effects refreshed one C++ unit, one generated report, memory auto coverage, and tracker. The restored visibility exposes one UID0003OU Empty Emitter Marker without changing its research semantics or the six accepted source definitions. |
| `000000013228` | `2026-07-15T15:28:32-04:00` | supervisor-owned `by-memory/-coverage-report.md` rerun | 0 / 1 | Confirmed UID0003OU indexed and the exact applied rows valid. Remaining missing-reference warnings UID0003MT, UID00039L, and UID0003T6 are unrelated pre-existing coverage rows; generated side effects refreshed memory coverage, research tracker, and by-memory generated coverage with the 4,993-node/4,023-edge registry. |
| `000000013232` | `2026-07-15T15:33:50-04:00` | external B001 `by-memory/-ignored.md` shared-page update | 0 / external | Added unrelated retained PowerListPane padding/reference material and advanced the shared-page full hash to `896D92EB...A4EF`; generated-refresh result exited 0 and rebuilt a 4,994-node/4,024-edge registry plus memory coverage/tracker outputs. Independent reread proves all B004 Photo/Picture intervals, hashes, and UID0004RP no-source evidence unchanged. B004 did not run this command. |

- Formal equality: all thirteen accepted managed blocks compare exact after CRLF normalization against Destinations 1-13.
- Generated source: `auto-generated/NexusTK/map/PhotoPane.cpp`, command 13193, SHA256 `4BBA93DBD6EAD618E42317A7C2E0270040C16B1693CAF54824AF2142205CCF2F`, 6,644 bytes. Counts are one PictureViewPane class, one PhotoPane class, one each of six accepted definitions, one UID0002R8 marker, zero explicit PhotoPane destructor, zero UID0001F3/UID0004RP/Empty Emitter Marker, and zero stale Bulletin/ABI source text.
- Finalization freshness read: external foreground command `000000013207` at `2026-07-15T15:06:43-04:00` produced PhotoPane.cpp SHA256 `A49DA88E3307EBB7F973045715A3983D12831DE99A734E1568E1D7927A42A2FB`; replacing only command/time headers with 13193 values reproduces exact SHA `4BBA93DB...CF2F`, and all source counts remain identical. At that evidence time generated memory coverage was SHA `680F1AAC867779B95B14965964D1B820891855CF11F1A3572F7085EE95EB3185`, 1,265,743 bytes/4,527 lines, and tracker SHA `DE8C207F4F9455B2F8B5A51BFD5C1904FBFEC63A29B8030F74009AF4F1636493`; those shared hashes are time-scoped, not lifecycle assertions.
- Manual coverage reconciliation read: command snapshots remain by-memory `31DE8A59...88BA`, by-class `DA137B8A...AAE6`, and by-file `622F7D86...638E`. Later external generated-refresh results exited 0 for command `000000013234` at `2026-07-15T15:39:48-04:00`, command `000000013235` at `2026-07-15T15:39:51-04:00`, and command `000000013236` at `2026-07-15T15:39:53-04:00`; current full-file SHAs are by-memory `30108F6F17D13E401E344F36570D7782E03AB7875108CCAAF18C94BC97A1903F`, by-class `177E9CDDCC21E52918D7962E9152E0B63E82E13BD4ACAE394639F720B953FF69`, and by-file `3EC509AA92378C15437367BEE35C8961DB7E1515F7EBDAEC0C800F41D0E14F89`. Exact-line counts remain 20/20, 2/2, and 1/1 respectively; requested UID rows occur once and the obsolete thunk row occurs zero times.
- Hierarchy proof: ordinary headers are UID0001F2 `0`, UID0004RJ `+4`, later outer siblings `0`, UID0004RN `+4`, UID0004RO/UID0004RP `0`, UID0001F4 `-8`; raw-space addition yields `I -> I+4 -> I+8 -> I`. The externally applied manual coverage now renders that exact hierarchy with all real UIDs. Generated memory coverage remains a flat metadata table.
- Warnings remaining in B004 implementation scope: none. Supervisor command 13224's UID0003OU registry warning was repaired by 13227 and confirmed by 13228; the three command-13228 missing-reference warnings for UID0003MT/UID00039L/UID0003T6 are unrelated pre-existing manual rows. Repository-wide autogen diagnostics did not fail any scoped validator.
- Shared ignored-page freshness: callback validator 13190 produced historical B004 SHA `9F5E59D1720F06867FA77272B039B3C8F92CF0293725634DB8C90A39F26BC6CF`; external B001 command 13232 advanced current full-file SHA to `896D92EB6EFF0AB3F700CC67F3BC2832A49A419878A97CE854B50332F1F4A4EF` with metrics 1,038,521 bytes/5,091 lines and mtime `2026-07-15T15:33:46.1324658-04:00`. Exact B004 content comparison passed; no B004 edit or validator occurred during drift repair.

## Changed Files

- Created ordinary pages:
  - UID0004RJ `by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md`, SHA256 `9ABE6088889DB91F7467FDA3A6EF7D90F1250E59EE94C9EAEF0C3FE50217C43C`.
  - UID0004RK `by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md`, SHA256 `145B84A542DE0CA0ADC34C82A9A5206DAED449AAD7570D81780447D67EAF0CA7`.
  - UID0004RL `by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md`, SHA256 `CEA73F5B0EC284E80563281D6DBD16D063867B31DD437AF1B856AD2EDBDA3FB7`.
  - UID0004RM `by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md`, SHA256 `068930E41C158A10E8492A3249547B83D6575D6CA251FD8176BF11838A6EA285`.
  - UID0004RN `by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md`, SHA256 `FAC50B7C7F5E7D2C4E172E72A21168D438171A90F3929854D391E403D0111299`.
  - UID0004RO `by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md`, SHA256 `AFC45278852559F0A927CB2C8A98DFA5A646F1BBFAFE70279281A8BD97587149`.
  - UID0004RP `by-memory/0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md`, SHA256 `EE2BD7EEE84E1205080A0A6943515FEDC279804B816BE32236566F1FCA60CB1A`.
- Modified ordinary pages:
  - UID0001F3 target, SHA256 `B14A9FE8D5F1A39BF47E918AD6FDD02B61491402BAEB49916916AD4F6CFA4250`.
  - `by-class/PictureViewPane.md`, SHA256 `4325983DBE1C53353378041418D7E0B85696298FA622294C2A2B2122174AFB0A`.
  - `by-class/PhotoPane.md`, SHA256 `08864374B65909652A084F36FB0F43635FBCA4C55AF7D3AA3D861D7DF73980B8`.
  - `by-file/PhotoPane.md`, SHA256 `94F2F2FA134347831CC5BC36CA3F6B6D7E172F0FE2BF246E0406CEC3FCA24B3F`.
  - UID0001F2 aggregate, SHA256 `8E12268C4E3D5D2EA65A9C88A71EA304A33AC2BCF934C95D8FEFC79CDB1943DC`.
  - UID0003OW vtable data, SHA256 `68232A7D8596A7CA297CD85E34064BB6559FCBE3856A9A2E98FCB81AE5E51701`.
  - UID0002R8 cleanup marker, SHA256 `60F4930A0322B69EF947DEECD8502E9B44B89E34C6555322D869B40E43B650C9`.
  - `by-memory/-ignored.md`: historical B004 callback SHA256 `9F5E59D1720F06867FA77272B039B3C8F92CF0293725634DB8C90A39F26BC6CF`; current post-external-command-13232 SHA256 `896D92EB6EFF0AB3F700CC67F3BC2832A49A419878A97CE854B50332F1F4A4EF`. External PowerListPane additions are unrelated; all B004 Photo/Picture intervals/hashes and UID0004RP evidence remain exact.
  - UID0001F4 successor, SHA256 `2D94CCB44D4DA19C65E169CCAB82A82E512D3F1786A9F701C7063B7B933AC06A`.
- Verify-only ordinary research semantics remained unchanged: UID000265 `4F6D41FA...A5C5AB6`, UID0001EA `D118C5B2...E5E6`, Event `D18D26AB...F95B`, EventHandler `38033240...AD9EB1`, Pane `B9686C65...AC10`, and the listed dependency classes. Supervisor command 13227 changed UID0003OU only by the metadata-header separator/registry recovery; current SHA is `155F7DFF38BB113686F38C4B1FEA24145D9613457B5E6116D3994D67B9746540`.
- Supervisor-owned external reconciliation, not B004 edits: snapshots `31DE8A59...88BA`/`DA137B8A...AAE6`/`622F7D86...638E`; current post-13234/13235/13236 hashes `30108F6F...1903F`/`177E9CDD...FF69`/`3EC509AA...F89`; UID0003OU SHA `155F7DFF...6540`. Commands 13224-13228 and relevant later freshness are recorded under Validator Results.
- Manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/IDA edits by B004: zero. Validator-generated side effects are recorded under Validator Results.
- Leases: each changed ordinary path was leased only for its edit/validation window and released immediately. `tools/leaser/Agents/current_leases.md` contains no Agent-B004 entry at final verification.
- Report execution: not run by B004. No execute/probe/count/revalidation/move/archive command was run.

## Implementation Tracking Checklist

Initial report-only and accepted callback proof:
- [x] Historical pre-callback supervisor validation was completed before implementation.
- [x] UID0001F3 target updated to 92/94 false/non-emitting split-index state with Destination 1.
- [x] PhotoPane constructor child registered first at `[0x00549620,0x00549911)` and real UID captured.
- [x] PhotoPane OnPaint child registered second at `[0x00549950,0x005499a2)` and real UID captured.
- [x] PictureViewPane constructor child registered third at `[0x00549a30,0x00549ad6)` and real UID captured.
- [x] PictureViewPane ordinary destructor child registered fourth at `[0x00549ae0,0x00549aff)` and real UID captured.
- [x] Pointer handler child registered fifth at `[0x00549b00,0x00549b22)` and real UID captured.
- [x] Key handler child registered sixth at `[0x00549b30,0x00549b4d)` and real UID captured.
- [x] Destructor-thunk child registered seventh at `[0x00549b4d,0x00549b63)` and real UID captured.
- [x] Every former PhotoPane-constructor placeholder replaced with validator-issued UID0004RJ after registration.
- [x] Every former PhotoPane-OnPaint placeholder replaced with validator-issued UID0004RK after registration.
- [x] Every former PictureViewPane-constructor placeholder replaced with validator-issued UID0004RL after registration.
- [x] Every former PictureViewPane-destructor placeholder replaced with validator-issued UID0004RM after registration.
- [x] Every former pointer-handler placeholder replaced with validator-issued UID0004RN after registration.
- [x] Every former key-handler placeholder replaced with validator-issued UID0004RO after registration.
- [x] Every former destructor-thunk placeholder replaced with validator-issued UID0004RP after registration.
- [x] New PhotoPane constructor child receives 92/93, owner/emitter UID0000AG, position 10, Nested +4, Destination 2, and complete evidence.
- [x] New PhotoPane OnPaint child receives 92/94, owner/emitter UID0000AG, position 20, Nested 0, Destination 3, and complete evidence.
- [x] New PictureViewPane constructor child receives 92/94, owner/emitter UID0000AH, position 10, Nested 0, Destination 4, and complete evidence.
- [x] New PictureViewPane destructor child receives 93/95, owner/emitter UID0000AH, position 20, Nested 0, Destination 5, and complete evidence.
- [x] New pointer child receives 92/94, owner/emitter UID0000AH, position 30, Nested +4 raw spaces, Destination 6, and complete evidence.
- [x] New key child receives 92/94, owner/emitter UID0000AH, position 40, Nested 0, Destination 7, and complete evidence.
- [x] New thunk child receives 93/95, owner UID0000AH, false/no emitter/position, Nested 0, Destination 8, and exhaustive no-code proof.
- [x] UID0000AH class rebased to 92/94, file-emitter position 10, with complete Destination 9 before `[[CHILDREN]]`.
- [x] UID0000AG class rebased to 92/93, file-emitter position 20, with complete Destination 10, exact children/member, and implicit destructor source cause.
- [x] UID0002R8 retains 90/92, receives position 30/Nested 0 and exact implicit-destructor Destination 13 marker while preserving all proof.
- [x] UID0000MK file rebased to 92/94 with complete source graph, exact names, typed map/partial descriptor facts, source ranking, child links, and `0x00549ae0` correction.
- [x] UID0001F2 aggregate rebased to 92/94 false/non-emitting with Destination 11 and complete inventory/history.
- [x] UID0003OW rebased to 91/94 false/non-emitting with Destination 12 and exact slots/stores.
- [x] UID0003OU verified research-semantically unchanged as PhotoPane source-declared/generated-binary vtable support; supervisor command 13227 added only the metadata-header separator and registry/reference recovery.
- [x] UID0000VN padding/thunk evidence rebased with all four new padding hashes and real thunk child UID.
- [x] UID0001F4 Nested changed from -4 to -8 with all unrelated content unchanged and the pre-UID0001F2 cumulative indentation restored.
- [x] UID000265/UID0001EA/Event/EventHandler/Pane and listed dependency pages verified unchanged; UID0003OU's metadata-only supervisor recovery is recorded without claiming a semantic change.
- [x] Pre-callback commands 13138-13152 remain historical evidence; current target-specific command 13193 and later external shared-index freshness are recorded without conflating generated side effects with report lifecycle state.
- [x] C1F3-001 through C1F3-068 destination and verification states updated claim by claim.
- [x] Historical B014/B005 facts preserved; stale names and Bulletin ownership historicalized/rejected.
- [x] Source-placement ranking and combined PhotoPane.cpp decision preserved.
- [x] Target split, four closure functions, padding ownership, explicit/implicit destructor source causes, source-vs-ABI/no-code decision, and raw-space cumulative nesting `I -> I+4 -> I+8 -> I` preserved.
- [x] Typed PhotoMapFileData/PhotoMapCell body contains no raw map byte offset, record stride, or guessed header/reserved semantics.
- [x] Partial ObjectStatusBlob initialization remains exact; no value initialization, memset, or unsupported field seed is introduced.
- [x] No source formal contains `this-0xa0`, `this-0xa4`, vptr stores, scalar flags, raw addresses, IDA labels, or address/offset evidence comments.
- [x] Third-party import directive confirmed not applicable; no inline import added.
- [x] Manual coverage pre-registration placeholders were replaced with real UIDs before supervisor application.
- [x] Exact supervisor-owned by-memory/by-class/by-file replacement/addition/deletion text is retained with all seven real UIDs; commands 13224-13228 externally applied and verified it, and B004 did not edit coverage.
- [x] Every changed ordinary page leased only immediately before edit, reread under lease, scoped-validated, and released immediately.
- [x] One scoped validator recorded for every changed ordinary destination.
- [x] Final target validator run with authorized `--wait-generated` only after all ordinary edits and produces target-specific provenance newer than the current maximum external baseline command 13152.
- [x] Generated PhotoPane.cpp contains one PictureViewPane class before one PhotoPane class and exactly one each PhotoPane constructor/OnPaint and PictureViewPane constructor/destructor/pointer/key definition.
- [x] Ordinary `Nested` headers mechanically encode UID0001F2 at `I`, outer children at `I+4`, target children at `I+8`, and UID0001F4 back at `I`; generated memory metadata indexes all real UIDs and externally applied supervisor-owned manual coverage renders the exact hierarchy.
- [x] Generated PhotoPane.cpp contains one updated UID0002R8 compiler marker and zero explicit PhotoPane destructor definition.
- [x] Command-13193 PhotoPane.cpp contains zero then-visible affected Empty Emitter Marker, zero UID0001F3 marker, zero thunk body/marker, zero broad aggregate marker, and zero vtable body/marker; external command 13227 later exposed only the unchanged legacy UID0003OU Empty Emitter Marker through registry recovery while preserving the accepted target output.
- [x] Generated PhotoPane.cpp has no accepted declared-but-undefined source method and no duplicate class/method definition.
- [x] Generated PhotoPane.cpp contains no stale old-name/Bulletin owner definition and no explicit ABI mechanics.
- [x] Validator Results and Changed Files record the real UID map, hashes, timestamps, exits, ok/warnings, side effects, lease releases, historical 13151/13152 baselines, and current target command 13193 proof.
- [x] No Wave2/Wave3 artifact incorporated.
- [x] No unresolved investigable blocker remains.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support detail incorporated without compression.
- [x] All seven children registered serially in ascending address order and all placeholder tokens eliminated.
- [x] All thirteen managed destination blocks exactly match accepted report text.
- [x] Metadata/score/owner/emitter/nesting/reclassification changes applied exactly or excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, hashes, and source-placement caps preserved.
- [x] C1F3-001 through C1F3-068 use legal terminal callback verification states with exact destination proof.
- [x] All scoped validators pass and are recorded.
- [x] Final waited command 13193 is newer than the accepted pre-callback baseline and passes every target source positive/negative assertion; ordinary headers and real-UID handoff prove the exact hierarchy.
- [x] Ordinary metadata proves outer-child `+4`, target-child `+4`, sibling `0`, and UID0001F4 `-8` produce cumulative `I -> I+4 -> I+8 -> I`; flat generated metadata indexes the real UIDs without claiming manual hierarchy application.
- [x] Manual coverage uses the real registered UIDs and was applied/verified only through supervisor commands 13224-13228.
- [x] No accepted B004 implementation or manual-coverage item remains; report lifecycle remains supervisor-owned.
- [x] Every lease released and zero lease remains.
- [x] No forbidden file or report lifecycle command touched.

Supervisor-owned coverage reconciliation pass:
- [x] Command-13228 by-memory snapshot `31DE8A59...88BA` and current post-13234 hash `30108F6F...1903F` both preserve the target block; current exact-line comparison contains all 20 expected handoff rows once and zero obsolete standalone thunk rows.
- [x] Current post-13235 by-class hash `177E9CDD...FF69` contains exact UID0000AG/UID0000AH rows once each; current post-13236 by-file hash `3EC509AA...F89` contains the exact UID0000MK row once.
- [x] Supervisor command 13227 restored UID0003OU registry/reference visibility with only the metadata-header separator; current hash `155F7DFF...6540` and research semantics are reconciled.
- [x] Commands 13224-13228 are recorded with timestamps, exits, ok counts, relevant warnings, generated/registry side effects, and actor ownership.
- [x] B004 performed zero non-report edit, lease, validator, lifecycle, generated, tracker, coverage, audit, supervisor, validator-state, archive, or IDA action during reconciliation.

External shared-page drift reconciliation:
- [x] Historical callback `by-memory/-ignored.md` SHA `9F5E...C6CF` and current post-13232 SHA `896D92EB...A4EF` are correctly time-scoped; all seven B004 padding intervals, five exact hash values, and UID0004RP 22-byte adjustor-thunk/no-source evidence are present, while added PowerListPane material is attributed to external B001 work and B004 performed no non-report action.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000013240","destination_path":"executed-b-agent-research/B004/0001F3-PictureViewPaneCloseHandlersAndThunks-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001F3-PictureViewPaneCloseHandlersAndThunks-source-quality.md","timestamp":"2026-07-15T16:01:37-04:00","uid":"0001F3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
