** TARGET-REPORT-UID:0001FE **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0001FE PursuitMessageDialogPaneConstructor Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain the implemented exact out-of-line human constructor `PursuitMessageDialogPane::PursuitMessageDialogPane() : DialogPane(L"", 1, 1) {}` and the complete class/helper/proxy source closure applied by this callback.
- Final disposition: implemented source-authored retained constructor, not padding, dead data, compiler-only glue, or a rare no-code case.
- Applied target state: [UID:0001FE] is `92/94`, direct semantic owner/emitter class [UID:0000BE], `RECONSTRUCTABLE:TRUE`, blank position, exact range, `Nested:0`, and exact Destination 1.
- Class/source closure: [UID:0000BE] is the direct base class not only for the four MessageDialogs message/menu classes but also for `TextDialog` and anonymous-namespace `NexonclubProxyDialog`; its shared packet state occupies `+0x26c..+0x277`, and the three formerly ownerless navigation helpers at `0x0054cc30-0x0054ce0f` are base-class methods. Pursuit declares no destructor: its implicitly declared destructor is virtual because `DialogPane::~DialogPane()` is virtual. The proxy source likewise has a complete source-position-zero anonymous class declaration, no derived data members, an implicitly declared virtual destructor, and legal body assignments for inherited state.
- Compiler boundary: the three constructor vptr stores, returned `this`, implicitly generated Pursuit/proxy ordinary destructor forwarding, shared scalar deleting destructor, adjustor thunks, RTTI, vtable bytes, SEH, and alignment are compiler/linker output and do not belong in handwritten constructor source. The source-authored ordinary cleanup anchor remains `DialogPane::~DialogPane()` at `0x0049d9f0`.
- Source placement: declaration and target/helper definitions route through [UID:0000BE] into [UID:0000LA] `NexusTK/ui/dialogs/MessageDialogs.cpp`; no standalone `PursuitMessageDialogPane.cpp` is warranted.
- Confidence: `94/100` for target range, bytes, ABI, source signature/body, direct class ownership, derived-constructor inlining explanation, layout, and source route.

## Supporting Research

- Historical assignment basis: canonical B004 `goal.md` first assigned report-only direct-target source-quality research for [UID:0001FE]. Supervisor Gate 1 accepted exact SHA256 `CB1A7569CD5D2142DEE6932C6D29EA61957E82210049DE258C2A918BBF658A3F`, after which the bounded implementation callback applied C1FE-001 through C1FE-046.
- Current target artifact at evidence time:
  - `by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md`
  - SHA256 `5648A5A8366FC19CF7CDE98FD883C0C98768B5C9E8B6538A59ED449A6831B033`
  - 11,358 bytes / 120 lines.
- Current direct support snapshots at evidence time:
  - [UID:0000BE] `by-class/PursuitMessageDialogPane.md`: SHA256 `2D8956ECA1A7C0E1CC78DFEF98DF9897C2C0086C7A00F3F5FAADB43533881A5D`, 10,772 / 95.
  - [UID:0001YI] `by-type/by-vtable/PursuitMessageDialogPaneVtables.md`: SHA256 `B22BC4FC28AC800FBD7E5DC5885C726661E74931E2CB95A64C278CA5FC001B78`, 10,424 / 94.
  - [UID:0000LA] `by-file/MessageDialogs.md`: SHA256 `DDE559AE5DEAEAE2E7E49E170CF93AADFFC126670454B73E5D7BB6546271647A`, 57,233 / 259.
  - [UID:0001FF] `by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md`: SHA256 `26E7A9CAB19CECF3F81E6742591E134A156E943C4A403AD855017192187F384A`, 13,514 / 137.
  - [UID:0001FH] `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`: SHA256 `02CE1102D2AEBF16131E13CE8C434020F196D7AA6C70F1F53DFF1F8507C8FEC8`, 32,672 / 178.
  - [UID:0001FG] `by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md`: SHA256 `CAA661A663556CDF45CDAE65284D16578A294EA0CE1BCD2D37573F5F58A93642`, 16,883 / 152.
  - [UID:0002OM] `by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md`: SHA256 `931949F7A84B10B9032E3A1C6FC9DAF7D8E487CAFA7D6C020FF7CCE26B461776`, 10,769 / 96.
  - [UID:00003T] `by-class/DialogPane.md`: SHA256 `DF90323E46B2F791A4B8ADEE6071CB3CC8804BFF8DA117D4D242C7B664125B1B`, 35,102 / 302.
  - [UID:0000IT] `by-file/DialogPane.md`: SHA256 `C7156E203B457A16B15456BB0847EE5CEEF20AE850733A6B581DE21BE0190998`, 23,927 / 142.
- Related class/source snapshots:
  - `by-class/TextDialog.md`: SHA256 `FCE85FE30B8909B5C28B5C07C52E9DFCF4A83A64181F42B0F7BD8BE506DF00FE`, 7,626 / 69.
  - `by-file/TextDialog.md`: SHA256 `8EF4F6668A353F43BF83B4905D721F63CCE68D94ABDFC52E73F228F17A278B61`, 11,595 / 84.
  - [UID:0003VQ] TextDialog constructor: SHA256 `19D81750B932EF621B8438FE720E0FC0ED84D49389925840E8996E32158B2B60`, 13,122 / 85.
  - `by-class/NexonclubProxyDialog.md`: SHA256 `DE40D11699F3C704CB541FD3F6E69E0A6C003C22960F5D833661BBBE761FDB6E`, 15,050 / 118.
  - `by-file/NexonclubProxyDialog.md`: SHA256 `840650C271D9EADF4639122BC3A3D8FD24275FD045DEEF19F3965A8648E4D2DA`, 14,106 / 99.
  - [UID:0003GL] proxy callback: SHA256 `A53C18F5F8BD83EA1A32EE3BCEA1B20A9CD70D03284CCFA9EEBA3BA8272CD34F`, 10,394 / 115.
  - [UID:0001FK] proxy constructor: SHA256 `7B4355A0D69EF08DFB2F6F8C5922E233E7CA73C9CD25F8D73510FDADE1D99F3D`, 19,281 / 228.
- Current generated baseline at evidence time:
  - `auto-generated/NexusTK/ui/dialogs/MessageDialogs.cpp`
  - current validator header command `000000013678`, refreshed `2026-07-16T08:54:37-04:00`
  - SHA256 `E9C36BCBD22B9A296ABECD258D1C7CC8DB09306F511211558AA01C1F173243FA`
  - 11,428 bytes / 349 lines.
  - It contains one [UID:0000BE] class declaration, one constructor declaration, one undefined explicit `virtual ~PursuitMessageDialogPane();` declaration, one [UID:0001FE] stale comment-only line, one [UID:0001FF] body, and one [UID:0001YI] no-code comment. It has no constructor or Pursuit destructor definition.
  - `TextDialog.cpp` is command `000000013678`, SHA256 `FB3D0FE33F2CA02565F770E96B7BC92D9ED01FB7984BFBB496222F7766E5393E`, 532 / 9, with class and constructor empty markers.
  - `NexonclubProxyDialog.cpp` is command `000000013678`, SHA256 `22797570C8355AA94D33D9671AB91C654A1118E8928720B64BD7719A50C3AD35`, 4,346 / 137, with one callback definition, one constructor definition, zero class declarations, zero explicit proxy destructors, and the UID00009H plus UID0003DE empty markers.
  - Historical generated commands `000000013645` and `000000013665` are superseded only as generated snapshots; their ordinary source facts remain valid history, and the accepted repair was later applied by the completed callback.
- Relevant prior-report searches used exact terms `UID0001FE`, `0001FE`, `0x0054cab0`, `0x0054cae9`, `PursuitMessageDialogPaneConstructor`, `PursuitMessageDialogPane`, `MessageDialogs`, `DialogPane`, `DialogNavigationPacketHelpers`, `TextDialog`, and `NexonclubProxyDialog`.
- Relevant reports opened and classified:
  - `executed-b-agent-research/B010/0000LA-MessageDialogs-empty-emitter-family-source-quality.md`, SHA256 `325FC55BF4580BEACE1AAFC079D1EA2EF6ED53F6403EAE329657AF1FD038309B`: historical source-family report. It correctly established MessageDialogs placement and source-shaped target bytes, but its no-code decision relied on no function/no xref before the derived-constructor and RTTI inheritance controls in this report.
  - `executed-b-agent-research/B001/0001FH-npc-message-menu-question-source-split.md`, SHA256 `F2E3DBDABA85DC90EBF01FA9DCD3AE62DA7C9448ADA4597B018D255EB43F7EFB`: accepted family split and exact derived constructor boundaries; supports MessageDialogs placement and four direct derived classes.
  - `executed-b-agent-research/B007/0001C0-SharedDialogDefaultScalarDestructor-source-quality.md`, SHA256 `758474F4BE53A9D8F5A3E2C463F1B5AEAFBA4A7C7DA67BED6B117840A0DA629D`: proves shared deleting-destructor/adjustor code is compiler glue and records the `0x278` object-size operand.
  - `executed-b-agent-research/B001/0003TP-MapPaneHandleObjectWorldMapCreationPacket-source-quality.md`, SHA256 `089014A525DD1EE3A4E945D54768416F8082157802924116278EE5587AAA6C62`: current MessageDialogs creator/member union and accepted precedent that zero inbound xrefs do not force no-code when a full source body and source route survive.
  - `executed-b-agent-research/B012/0001FG-DialogNavigationPacketHelpers-source-quality.md`, SHA256 `52272DCC7B0F8BD138A496D1213045BD56B723C5575D4FD679BC32D22F14A10A`: then-correct no-owner result because the shared receiver declaration was missing. This report supplies the missing RTTI-backed receiver and field layout, so that blocker is superseded rather than ignored.
  - `executed-b-agent-research/B005/000179-ObjectStatusBlobParsers-source-quality.md`, SHA256 `157E38B6F911C803660B9F7F39E9107B8F4F6D018922504FF12C8AA4CD2B3D9D`: current [UID:0001FF] ObjectStatusBlob member/body correction to preserve.
  - `executed-b-agent-research/B008/0001FK-NexonclubProxyDialogConstructor-source-quality.md`, SHA256 `8B6BB8CA038DED9BD40BC74FEDF16D9680A64168322FC97D95E7ABA08D7C9C30`: source-ready proxy constructor/callback report; its direct `DialogPane` initializer is corrected by current RTTI.
  - `executed-b-agent-research/B012/0003VQ-TextDialogConstructor-source-quality.md`, SHA256 `7C07B21D8391586758C96DF6235959433C4FCF6DCE3BF6100A99C509701A81AD`: current TextDialog constructor evidence and exact reason its large body remains blank.
- Per-root old-report results:
  - `tools/leaser/Agents/Older-Research/**`: 3 Markdown files; zero matches for every exact UID/address/name/source-family term above.
  - `tools/leaser/Agents/SpecialReports/**`: 5 Markdown files; zero matches for every exact UID/address/name/source-family term above.
  - Actual project archive root `archived/**`: zero Markdown reports at inspection time. Incidental validator `.log` files mentioning dialog names are not reports and were excluded.
  - Active B001-B005 research roots: no direct target report. The then-current B005 UID0003TK artifact mentions MessageDialogs only as an already-executed MapPane dependency and does not claim this target or its support pages.
- Lifecycle boundary: B004 performed report-only research and no report lifecycle command. Validation, execution, counting, movement, and archive state are external supervisor/validator-owned facts and are not asserted by this artifact.

## Target

- Target UID: `0001FE`.
- Target path: `by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md`.
- Queue row: `auto-generated/-ag-research-tracker.md`, by-memory Not-Covered Files - Reconstructable, `86/90`, zero registered reports at assignment time.
- Current classification: reconstructable raw constructor with comment-only formal output.
- Current metadata: completion `86`, confidence `90`, canonical owner `0000LA`, emitter `0000LA`, reconstructable true, blank position, `Nested:0`.
- Recommended metadata: completion `92`, confidence `94`, canonical owner `0000BE`, emitter `0000BE`, reconstructable true, blank position, `Nested:0`.
- Recommended source identity: `PursuitMessageDialogPane::PursuitMessageDialogPane()`.
- Recommended human body: one `DialogPane(L"", 1, 1)` base initializer and an empty body.

## Current Target State

- Exact half-open range is `[0x0054cab0,0x0054cae9)`, `0x39` / 57 bytes (Verified with `tools/int_convert.py`).
- Exact body SHA256 is `215A0ACBA54ACF38C46725622051FB67E655EED6DD824F8B42B2FB99928AA439`.
- Exact fixed signature is unique in the current IDB:
  `55 8B EC 51 56 6A 01 6A 01 8B F1 68 20 DB 60 00 89 75 FC E8 D8 0D F5 FF C7 06 28 24 62 00 8B C6 C7 86 A0 00 00 00 88 24 62 00 C7 86 A4 00 00 00 B8 24 62 00 5E 8B E5 5D C3`.
- IDA does not model `0x0054cab0` as a function and reports zero direct xrefs.
- VA pattern `B0 CA 54 00` and RVA pattern `B0 CA 14 00` have zero matches.
- The body calls `sub_49D8A0`, the exact `DialogPane` constructor, after pushing `1`, `1`, and `word_60DB20`.
- `word_60DB20` starts with two UTF-16 null code units; the source argument is `L""`.
- The body stores three `PursuitMessageDialogPane` vtable bases at object offsets `+0x00`, `+0xa0` / 160, and `+0xa4` / 164 (offset conversions Verified with `tools/int_convert.py`).
- The body returns `this` in `eax`; this is constructor ABI lowering, not a source return statement.
- Seven `0xcc` bytes precede the body and seven `0xcc` bytes follow it. Each seven-byte run has SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`.
- Current ordinary padding documentation already contains `[0x0054caa9,0x0054cab0)` and `[0x0054cae9,0x0054caf0)`; no padding edit is required.
- Current formal output is the exact retained constructor body. The historical no-code comment and no-function/no-xref conclusion are preserved as superseded history.
- Current [UID:0000BE] declaration contains the constructor, shared response virtual, three protected navigation methods, exact packet-tail members, no explicit destructor, and `[[CHILDREN]]`.
- Current [UID:0001FG] is class-owned/emitted by UID0000BE with the exact three-method formal; the historical missing-receiver no-owner result is superseded.
- Current ordinary implementation is complete across the 15 authorized destinations. B004 changed no manual coverage, generated source by hand, IDA, validator-state, or lifecycle file.

## Executive Recommendation

- The raw body is implemented as a retained out-of-line class constructor that was inlined into all six observed derived constructors.
- Direct class ownership/emission is applied: `CANONICAL_OWNER:0000BE`, `EMITTER_UIDS:0000BE`.
- Keep [UID:0000LA] as the containing source-file root only.
- The shared packet-header fields are present on `PursuitMessageDialogPane` in source order:
  `unsigned char m_dialogType; unsigned int m_dialogId; unsigned short m_dialogState; unsigned short m_dialogPageIndex;`.
- The three navigation helpers are attached to `PursuitMessageDialogPane` and emit exact source methods there.
- TextDialog and NexonclubProxyDialog documentation now records direct inheritance from `PursuitMessageDialogPane`.
- The proxy constructor now uses only `PursuitMessageDialogPane()` in its initializer list, assigns inherited packet fields in exact observed body order, and follows a source-position-zero anonymous class declaration; its callback uses inherited member calls.
- Keep TextDialog's large constructor/action bodies blank until their separate control/local-layout blockers are solved; the direct base and field names are no longer blockers.
- Keep vtable data and deleting-destructor mechanics no-code/generated-binary.
- The explicit `PursuitMessageDialogPane` destructor declaration is removed. The class relies on its implicitly declared virtual destructor and source-owned `DialogPane::~DialogPane()` cleanup contract.

## Supervisor Active Recheck

- The supervisor assigned one direct target and explicitly rejected no-xref/no-function as a sufficient no-code rationale.
- No target split is required: the 57-byte range is one coherent constructor body bracketed by already-documented padding.
- All source-bearing behavior inside the target is represented by Destination 1.
- Triggered receiver/helper source closure is represented by Destinations 2 through 8.
- No child registration, rename, IDA mutation, manual coverage edit, or new source file was required. The accepted implementation callback is complete; supervisor/validator-owned report lifecycle state remains external to this artifact.

## Inference Research Guidance Check

- IDA facts: bytes, instructions, ranges, function-model status, xrefs, vtable names, RTTI descriptors, base-class arrays, and constructor call sites.
- Documentation facts: current class/file/memory/type metadata, accepted source bodies, current generated outputs, current manual rows, and executed report history.
- Inference: exact human initializer spelling, field names, helper names, and source packaging.
- The source recommendation avoids `sub_`, raw vptr stores, explicit `this` returns, offset comments, synthetic ABI wrappers, and decompiler temporaries.
- Current generated/Wave-era files were treated as leads only. Historical Wave2/Wave3 statements were not used as authority.
- The constructor name and direct inheritance are original-symbol/RTTI evidence. Field and helper names are high-confidence descriptive source names, not claimed original spellings.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Result |
| --- | --- | --- |
| No IDA function object | Raw bytes form a complete prologue/call/vtable-store/epilogue constructor and have a unique exact signature. | Not a no-code reason. Keep exact raw by-memory coverage and emit human source. |
| Zero inbound xrefs and pointer hits | All six derived constructors directly reproduce the same `DialogPane(L"", 1, 1)` sequence and install only their final vtables. | Best explanation is optimizer inlining of the base constructor while retaining an out-of-line copy. |
| Constructor source body | Only source-authored operation is base construction; vptr stores and returned `this` are compiler lowering. | Empty-body initializer-list constructor is exact and human plausible. |
| Direct owner | Current target bypasses its class to file owner `0000LA`. | Direct semantic owner and emitter are class `0000BE`; file remains final source root. |
| Class layout tail | `DialogPane` ends at `0x26c`; all six derived constructor families store the same byte/dword/word/word tail. | Tail is `PursuitMessageDialogPane` shared state, naturally producing size `0x278` with compiler alignment. |
| TextDialog inheritance | Current prose says DialogPane-derived, but TextDialog RTTI base array has eight entries and its second descriptor is exact `PursuitMessageDialogPane` descriptor `0x0064e3a4`. | Correct direct base to `PursuitMessageDialogPane`. |
| NexonclubProxyDialog inheritance | Current constructor formal calls `DialogPane` directly, but RTTI base array also has second descriptor `0x0064e3a4`. | Correct direct base to `PursuitMessageDialogPane`; direct DialogPane call is inlined base lowering. |
| Navigation-helper owner | Prior report correctly found no support-backed shared receiver. RTTI now supplies the receiver and current field consumers agree. | Assign [UID:0001FG] to class `0000BE`; emit three nonvirtual protected methods. |
| Shared response owner | Current formal is already a `PursuitMessageDialogPane` method but metadata bypasses to the file. | Change [UID:0001FF] owner/emitter to `0000BE`; preserve body. |
| Vtable inventory owner | Current type page bypasses to the file while exact vtable-data page already uses class ownership. | Change [UID:0001YI] owner/emitter to `0000BE`; preserve no-code disposition. |
| Pursuit ordinary destructor source | Fresh MCP shows the shared wrapper at `0x00520b70` directly calls source-owned `DialogPane::~DialogPane()` at `0x0049d9f0`, then performs only scalar-delete flag handling. Pursuit has only POD packet fields and no class-specific cleanup. Current MessageDialog/larger/menu declarations omit explicit destructors while sharing the same wrapper. | Remove `virtual ~PursuitMessageDialogPane();` from Destination 2. Its implicitly declared destructor is virtual through the base class virtual destructor contract and needs no separate handwritten definition. |
| Deleting-wrapper/adjustor source | Primary Pursuit/message/text/proxy vtables share `0x00520b70`; secondary/tertiary views use `0x00520aa5`, `0x00520ab0`, `0x005539c3`, and `0x005539ce`. | Keep all wrappers/thunks no-code compiler output; they are not an ordinary destructor definition. |
| Source placement | Target, shared fields, helpers, and response virtual are class members in the MessageDialogs family. | Emit through class to `NexusTK/ui/dialogs/MessageDialogs.cpp`; reject new file. |
| `Pursuit` semantic meaning | RTTI proves the spelling but not gameplay meaning. | Preserve exact class name without inventing a semantic expansion. |
| `DialogObjectAction` type | Existing accepted handler uses this inferred wrapper and direct payload field. | Preserve type; remove reverse-engineering offset comment from formal class source. |
| TextDialog large constructor | Direct base and fields are now resolved, but control members, flag semantics, cleanup, and 1,341-instruction body remain separate blockers. | Update inheritance/field prose and score modestly; keep body blank in this callback plan. |
| Proxy constructor legality | Fresh repair-time MCP decompilation/disassembly shows local `ObjectStatusBlob` construction, then stores `m_dialogType` at `0x00553699` and `m_dialogId` at `0x005536a8`, packet-mode mutation, display-byte setup, parse, and only then `m_dialogState`/`m_dialogPageIndex` at `0x005536ee`/`0x00553701`. | Use only `PursuitMessageDialogPane()` in the initializer list; assign inherited type/id in the body before parsing, retain state/page assignments only on parse success, and remove unsupported zero initializers. |
| Proxy class source closure | Current class formal is blank even though two qualified method definitions emit. Allocation size is exactly the Pursuit base size `0x278`; RTTI proves direct Pursuit inheritance; shared primary/adjusted deleting-destructor slots are compiler glue. | Emit a source-position-zero anonymous class declaration with public constructor, private `OnReplyText`, no derived fields, implicit virtual destructor, required headers, and `[[CHILDREN]]` before the definitions. |
| Proxy callback legality | `SendCurrentDialogPacket()` is protected on Pursuit and `CloseDialog()` is public on DialogPane; both are accessible from a private derived callback. | Destination 7 remains a legal member definition once Destination 8 supplies the declaration and direct base. |

Rejected alternatives:

- Leave target C++ blank because no xrefs survive: rejected by six independent inlined derived-constructor controls and the retained unique out-of-line body.
- Emit vptr stores or `return this`: rejected as compiler constructor lowering.
- Define target as a free initializer helper: rejected by `ecx` receiver, RTTI name, three class-vtable stores, and constructor ABI.
- Keep owner/emitter on the file: rejected by by-structure's narrowest-owner rule and the direct class declaration.
- Create `PursuitMessageDialogPane.cpp`: rejected because all adjacent class declarations, derived constructors, dispatcher, shared virtual, and resources are in the MessageDialogs family.
- Put packet fields on `DialogPane`: rejected because current DialogPane layout ends before `+0x26c`, and the fields occur only in the Pursuit-derived dialog branch.
- Keep navigation helpers no-owner: superseded by exact TextDialog/Nexonclub RTTI arrays and common field layout.
- Handwrite vtable arrays, RTTI, scalar deleting destructor, adjustor thunks, or object-size delete guards: rejected as generated binary/toolchain output.
- Retain `virtual ~PursuitMessageDialogPane();` without a definition: rejected as incomplete C++03 source and unnecessary for virtual dispatch.
- Add an empty out-of-line `PursuitMessageDialogPane::~PursuitMessageDialogPane() {}`: rejected because no distinct ordinary destructor body or Pursuit-specific cleanup survives, all direct siblings omit explicit destructors, and the shared wrapper already lowers directly to `DialogPane` cleanup.
- Add explicit padding fields after `m_dialogType`: rejected because ordinary MSVC alignment naturally places the following dword at `+0x270`.
- Declare proxy copies of the four packet fields: rejected because the proxy allocation is exactly `0x278`, the same as the Pursuit base, and all four offsets already lie in inherited base storage.
- Keep `m_dialogState(0)` / `m_dialogPageIndex(0)` in the proxy initializer list or move them to unconditional body stores: rejected because fresh disassembly has no such stores and writes both words only after tagged-status parsing succeeds.
- Add a handwritten proxy destructor body: rejected because the base destructor is virtual, the derived class needs no custom cleanup, and the exact primary/adjustor deleting-destructor bodies are shared compiler output.
- Raise every message-dialog sibling score: rejected as unrelated inflation. Only pages whose target-facing source contract changes are rescored.

## Evidence Standards Used

- Highest-weight evidence: current live IDA MCP bytes, exact instruction listings, unique signature, xrefs, named vtables, RTTI complete-object locators, class hierarchy descriptors, base arrays, and direct constructor stores.
- Corroborating evidence: exact current by-* docs, current generated source, accepted executed reports, current manual coverage rows, source-family ordering, and sibling constructor controls.
- Negative evidence retained: no target function object, no xrefs, no pointer hits, no direct target call, no independent source file evidence, and no handwritten vtable/destructor evidence.
- Confidence remains below 95 because private field/helper spellings and original header packaging are inferred, even though the source behavior and class hierarchy are strong.

## Evidence Checked

- MCP transport and database:
  - fresh `initialize -> tools/list -> tools/call` flow;
  - active IDB database `64c11373`, worker PID `21508`;
  - evidence-time transport sessions included `8dfa8fa2-dd30-4612-80ce-3309d2d4e27a`, `d8b385ab-afb0-4eaa-8811-308e638cf96a`, `f3bad16d-845e-473d-a245-6962ca674ff6`, and `5a1702bf-57a6-4f03-a6b9-72ed61db1e3a`;
  - `server_health` returned `status:ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, string cache ready with 2,067 strings.
- MCP target checks:
  - `lookup_funcs` on `0x0054cab0`, `0x0054caf0`, and `0x0049d8a0`;
  - `get_bytes` on target plus both seven-byte padding spans and `word_60DB20`;
  - bounded `insn_query` for target and six derived constructors;
  - `xrefs_to` target and three vtable bases;
  - `find_bytes` for target VA/RVA pointer forms;
  - bounded `search_text` for all `sub_49D8A0` calls in MessageDialogs, TextDialog, and proxy ranges;
  - `make_signature_for_range` for exact target.
- MCP repair checks:
  - fresh `idb_list` rediscovered active database `64c11373`;
  - repair-time `server_health` returned `status:ok`, imagebase `0x400000`, auto-analysis/Hex-Rays/string caches ready;
  - `lookup_funcs` reconfirmed proxy constructor `0x00553610-0x005538fd`, callback `0x005534a0-0x00553609`, shared scalar deleting destructor `0x00520b70-0x00520bab`, and late adjustor thunk `0x005539c3-0x005539ce`;
  - bounded `get_bytes`, `decompile`, and `insn_query` on `0x00553610-0x00553720` proved the exact source-relevant order: local status-object construction, inherited type store, inherited id store, packet-mode mutation, display-byte setup, tagged-status parse, then inherited state and page stores only on parse success;
  - exact store instructions are `0x00553699 mov [ebx+26Ch],al`, `0x005536a8 mov [ebx+270h],eax`, `0x005536ee mov [ebx+274h],ax`, and `0x00553701 mov [ebx+276h],ax`;
  - no store initializes `+0x274` or `+0x276` before the parser-negative return path.
- MCP destructor-source closure checks:
  - a second fresh `idb_list` retained active database `64c11373`; `server_health` again returned `status:ok` with analysis, Hex-Rays, and strings ready;
  - `lookup_funcs` confirmed ordinary DialogPane cleanup `0x0049d9f0-0x0049dacb`, shared scalar deleting wrapper `0x00520b70-0x00520bab`, early adjustors `0x00520aa5/0x00520ab0`, and late proxy adjustors `0x005539c3/0x005539ce`;
  - bounded decompile/disassembly of `0x0049d9f0` proves the source-owned DialogPane destructor cleanup: restore DialogPane vtables, decrement active-dialog state, release controls, destroy tile context, and call Pane teardown;
  - bounded decompile/disassembly of `0x00520b70` proves no Pursuit-specific ordinary destructor body: it calls `0x0049d9f0` directly, tests scalar-delete flags, optionally calls delete/runtime support, and returns;
  - `xrefs_to` reports 17 primary references to `0x00520b70`, including Pursuit `0x00622428`, four message/menu classes, TextDialog `0x00622958`, proxy `0x00622c58`, and unrelated merchant/menu classes;
  - early adjustors have 12 secondary/tertiary vtable references each, while proxy-only late adjustors have one reference each at `0x00622cb8` and `0x00622ce8`;
  - current MessageDialog, MessageDialogLarger, MenuQuestionDialog, and MenuQuestionDialogLarger formal declarations omit explicit destructors while their vtables use this same wrapper family, providing direct source-shape controls for implicit derived destructors.
- MCP RTTI checks:
  - `list_globals` for `PursuitMessageDialogPane`, `TextDialog`, and `NexonclubProxyDialog`;
  - complete-object locator bytes at `0x0064e360`, `0x0064e7bc`, `0x0064e848`;
  - class hierarchy descriptors at `0x0064e374`, `0x0064e7d0`, `0x0064e85c`;
  - base arrays at `0x0064e384`, `0x0064e7e0`, `0x0064e86c`;
  - shared Pursuit base descriptor at `0x0064e3a4`.
- Current docs checked:
  target, class, type-vtable, exact vtable data, MessageDialogs file, shared response, navigation helpers, family split index, DialogPane class/file/aggregate, four message/menu derived classes and constructors, TextDialog class/file/constructor/action/vtable, proxy class/file/constructor/callback/vtable, ignored padding, dispatcher/creator, and MapPane pursuit adapter.
- Current generated files checked:
  `MessageDialogs.cpp`, `TextDialog.cpp`, and `NexonclubProxyDialog.cpp`.
- Current manual files checked:
  `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md`.
- Prior reports checked with concrete findings under Supporting Research.
- Failed/skipped checks:
  - One initial PowerShell `Invoke-WebRequest` call failed locally because `-UseBasicParsing` was omitted; no MCP outage occurred.
  - One schema test used obsolete `get_bytes`/`xrefs_to` argument names and returned required-parameter errors; schema-current retries succeeded.
  - One repair-time PowerShell wrapper used the reserved automatic variable `$args`, causing MCP to receive no tool arguments and return `database is required`; the corrected bounded retry supplied `database=64c11373` and every requested IDB-backed call succeeded.
  - IDA mutation, function creation, type application, renaming, comments, and process management were intentionally not performed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1FE-001 | Target range is exactly `[0x0054cab0,0x0054cae9)`, 57 bytes, SHA256 `215A...A439`. | confirmed | MCP bytes/signature/hash | UID0001FE range/evidence/summary | incorporate | applied |
| C1FE-002 | Seven `0xcc` bytes bracket both sides and are already covered in `-ignored.md`. | confirmed | MCP bytes/current ignored row | UID0001FE boundary; `-ignored.md` verify-only | already-present | already-present |
| C1FE-003 | IDA does not model target as a function. | confirmed | `lookup_funcs` | UID0001FE historical/negative evidence | incorporate | applied |
| C1FE-004 | Target has zero direct xrefs and zero VA/RVA pointer hits. | confirmed | `xrefs_to`, `find_bytes` | UID0001FE liveness/negative evidence | incorporate | applied |
| C1FE-005 | Exact target signature is unique. | confirmed | `make_signature_for_range` | UID0001FE binary identity | incorporate | applied |
| C1FE-006 | Target calls `DialogPane(L"", 1, 1)`. | confirmed | instructions, empty UTF-16 storage, DialogPane signature | UID0001FE behavior/formal | incorporate | applied |
| C1FE-007 | Three vptr stores are compiler lowering, not handwritten source. | confirmed | named vtable stores/RTTI | UID0001FE compiler boundary | incorporate | applied |
| C1FE-008 | Returned `this` is constructor ABI lowering. | confirmed | `mov eax,esi`, epilogue | UID0001FE compiler boundary | incorporate | applied |
| C1FE-009 | Human target source is the empty-body initializer-list constructor in Destination 1. | high | target plus derived controls | UID0001FE formal | incorporate | applied |
| C1FE-010 | Historical B010 no-code conclusion is superseded, while its no-xref facts remain valid history. | high | B010 report/current target | UID0001FE history; class/file history | historicalize | applied |
| C1FE-011 | Four MessageDialogs derived constructors inline the same base initialization. | confirmed | calls at `54ce5c`, `54dbdc`, `54e972`, `54fb82` | UID0001FE liveness; UID1FH/file | incorporate | applied |
| C1FE-012 | TextDialog constructor inlines the same base initialization and installs final TextDialog vtables. | confirmed | `55214d-552171` | TextDialog class/constructor/file | incorporate | applied |
| C1FE-013 | NexonclubProxyDialog constructor inlines the same base initialization and installs final proxy vtables. | confirmed | `55364d-55367e` | proxy class/constructor/file | incorporate | applied |
| C1FE-014 | Pursuit RTTI CHD has seven base entries. | confirmed | `0x64e374/0x64e384` | class/vtable evidence | incorporate | applied |
| C1FE-015 | TextDialog RTTI CHD has eight entries and second descriptor `0x64e3a4` is Pursuit. | confirmed | `0x64e7d0/0x64e7e0` | TextDialog support | incorporate | applied |
| C1FE-016 | Proxy RTTI CHD has eight entries and second descriptor `0x64e3a4` is Pursuit. | confirmed | `0x64e85c/0x64e86c` | proxy support | incorporate | applied |
| C1FE-017 | Pursuit owns byte/dword/word/word fields at `+0x26c/+0x270/+0x274/+0x276`. | high | six derived constructors and shared consumers | UID0000BE formal/prose | incorporate | applied |
| C1FE-018 | Natural alignment of those fields yields exact `0x278` class size. | high | DialogPane `0x26c`, field types, deleting-wrapper size | UID0000BE layout | incorporate | applied |
| C1FE-019 | UID0001FG's receiver is PursuitMessageDialogPane. | high | RTTI plus caller/field matrix | UID0001FG owner/emitter/prose | incorporate | applied |
| C1FE-020 | UID0001FG should emit three protected member bodies in Destination 3. | high | exact helper behavior/callers | UID0001FG formal | incorporate | applied |
| C1FE-021 | UID0001FE canonical owner is UID0000BE. | high | direct class method | UID0001FE metadata | incorporate | applied |
| C1FE-022 | UID0001FE emitter is UID0000BE, which routes to UID0000LA. | high | class/file emitter chain | UID0001FE metadata | incorporate | applied |
| C1FE-023 | UID0001YI canonical owner/emitter should be UID0000BE. | high | direct class vtable inventory | UID0001YI metadata/prose | incorporate | applied |
| C1FE-024 | UID0001FF canonical owner/emitter should be UID0000BE. | high | exact base-class method definition/vtable inheritance | UID0001FF metadata/prose | incorporate | applied |
| C1FE-025 | UID0001FG canonical owner/emitter should be UID0000BE. | high | exact shared base receiver | UID0001FG metadata | incorporate | applied |
| C1FE-026 | UID0000LA remains the source file root, not the target's direct semantic owner. | high | source family/current path | MessageDialogs file | incorporate | applied |
| C1FE-027 | No standalone Pursuit source file is supported. | high | address/source family and class users | source placement | reject-invalid | excluded-with-reason |
| C1FE-028 | Destination 2 is the complete source-clean Pursuit class block and intentionally omits an explicit destructor declaration; its implicitly declared destructor is virtual through `DialogPane::~DialogPane()`. | confirmed | class/RTTI/layout/method union, DialogPane destructor, sibling declarations | UID0000BE formal | incorporate | applied |
| C1FE-029 | Destination 1 is the complete target formal block. | high | exact target behavior | UID0001FE formal | incorporate | applied |
| C1FE-030 | Destination 3 is the complete navigation-helper formal block. | high | exact helper behavior | UID0001FG formal | incorporate | applied |
| C1FE-031 | Destination 4 preserves the current ObjectStatusBlob-corrected response body. | confirmed | current UID0001FF/B005 report | UID0001FF formal | already-present | already-present |
| C1FE-032 | Destination 5 remains a source-declared/generated-binary vtable marker. | confirmed | vtable/RTTI/toolchain behavior | UID0001YI formal | incorporate | applied |
| C1FE-033 | Shared deleting destructor and adjustor thunks remain no-code compiler output; they call the ordinary DialogPane cleanup and are not a Pursuit source definition. | confirmed | fresh MCP wrapper/decompile/xrefs and B007 consumer matrix | class/file/vtable/destructor history | already-present | already-present |
| C1FE-034 | TextDialog docs must say direct Pursuit inheritance and inherited packet fields. | confirmed | RTTI/base array | TextDialog class/file/constructor/action | incorporate | applied |
| C1FE-035 | TextDialog constructor/action formals remain blank because their separate UI/local blockers persist. | high | current exact reports | TextDialog constructor/action | not-applicable | excluded-with-reason |
| C1FE-036 | Proxy docs and Destination 8 must provide a source-position-zero anonymous class declaration with direct Pursuit base, public constructor, private `OnReplyText`, no derived fields, `[[CHILDREN]]`, required headers, and an implicitly declared virtual destructor through the base class virtual destructor contract. | confirmed | RTTI/base array, exact `0x278` allocation, class/vtable/destructor pages, fresh wrapper evidence | proxy class/file/formal | incorporate | applied |
| C1FE-037 | Proxy constructor Destination 6 uses only `PursuitMessageDialogPane()` in the initializer list, then assigns inherited type/id in the observed body order and state/page only after successful parsing; no zero initializers are source-supported. | confirmed | repair-time decompile/disassembly and exact stores | UID0001FK formal/prose | incorporate | applied |
| C1FE-038 | Proxy callback Destination 7 legally uses inherited protected `SendCurrentDialogPacket()` and public `CloseDialog()` after Destination 8 declares it as a private member. | high | Pursuit/DialogPane declarations and callback body | UID0003GL formal/prose | incorporate | applied |
| C1FE-039 | UID0001FH remains `88/90`, false, blank, non-emitting split index. | confirmed | current exact children | UID0001FH prose only | already-present | already-present |
| C1FE-040 | DialogPane declaration/signature/layout are already sufficient and remain unchanged. | confirmed | UID00003T/UID00012R | DialogPane verify-only | already-present | already-present |
| C1FE-041 | UID0002OM already has correct class owner/emitter and no-code formal. | confirmed | current page | UID0002OM verify-only | already-present | already-present |
| C1FE-042 | Target/support score changes are bounded to source-contract improvements listed below. | high | blocker closure matrix | metadata destinations | incorporate | applied |
| C1FE-043 | Current manual rows are stale/absent and require exact supervisor-owned text below. | confirmed | four manual files | manual coverage handoff | incorporate | applied |
| C1FE-044 | Final generated checks must prove one target ctor, three helpers, one handler, zero explicit Pursuit destructor declarations/definitions, one proxy class declaration before one constructor/one callback definition, no explicit proxy destructor, no proxy class empty marker, and no target stale marker. | high | current generator routes and implicit-destructor source closure | generated readback | incorporate | applied |
| C1FE-045 | Old reports are leads/history, not substitutes for current target evidence. | confirmed | root searches/report reads | research/history | historicalize | applied |
| C1FE-046 | No split, rename, new UID, padding change, IDA edit, or new source file is required. | high | complete range/source analysis | target/support checklist | not-applicable | excluded-with-reason |

Callback destination proof:

| Claims | Destination and terminal proof |
| --- | --- |
| C1FE-001..011, 021..022, 029 | UID0001FE SHA256 `38CA29556755D44A4C8B98A8345F3AA80F948156350C5E9069A5B32D8981FA73`; validator `000000013686` exit 0 / ok 1; exact Destination 1 parity; range/hash/signature/negative/liveness/compiler-boundary detail applied. |
| C1FE-014, 017..018, 028, 033 | UID0000BE SHA256 `614D71C5A27D0DB6850F489D460BD6107266E5250B4355D2EDE21A8FA041B042`; validator `000000013687`; exact Destination 2 parity; no explicit destructor and complete class/layout/helper declaration. |
| C1FE-023, 032..033 | UID0001YI SHA256 `FCAC495584A7582B64236B9B2072A82F301DA095B01A0391E402A3D21D883E20`; validator `000000013688`; exact Destination 5 parity and class owner/emitter. |
| C1FE-011, 026..027, 033, 042, 045 | UID0000LA SHA256 `A3860E74F5DB88918806F9B2B58FF7B602C4209DCEF90859B76E54E6C89F32A7`; validator `000000013689`; complete Pursuit/message/text/proxy source union preserved. |
| C1FE-024, 031 | UID0001FF SHA256 `6929F58AF933F445AD5ACF626A1F04C30D00DFC732C85E51E48A7529F404ABD5`; validator `000000013690`; Destination 4 remains byte-for-byte equal to the accepted B005-corrected block. |
| C1FE-019..020, 025, 030 | UID0001FG SHA256 `F95EEABD5BE628B5AF13BEE0D210ABD6019EF34F44764281D7FF0F855C590954`; validator `000000013691`; exact Destination 3 parity and historical no-owner premise superseded. |
| C1FE-011, 039 | UID0001FH SHA256 `EDA39F49D6AFD02CA2E31E67722CA321626DCDE4C3CB767776BC8F2A3799E89A`; validator `000000013692`; metadata/formal unchanged and four inlined-base relationships added. |
| C1FE-012, 015, 034..035 | TextDialog class/file/constructor/action hashes `C4212E...35D2`, `EEE194...CD1B`, `BB54EB...4A3D`, `4A45A7...A120`; validators `000000013693`, `000000013694`, `000000013695`, `000000013698`; direct Pursuit inheritance and inherited fields/helpers applied while both exact formals remain blank. |
| C1FE-013, 016, 036 | Proxy class/file hashes `710ABF...10CD`, `1FBFD4...F93F`; validators `000000013703`, `000000013706`; Destination 8 parity, source position zero, complete include/declaration order, no fields/destructor. |
| C1FE-037 | UID0001FK SHA256 `721CC2E661E58E918CBF1150BD456AB5468E0A2BC1D420D9DA23C4A4E43B86E4`; validator `000000013711`; exact Destination 6 parity and parser-negative store semantics. |
| C1FE-038 | UID0003GL SHA256 `0F71A228AAEC7F9F13F1EC09E5B0834D93A785E78C3D282A0293A46E13CC2D5C`; validator `000000013714`; exact Destination 7 parity and legal inherited calls. |
| C1FE-002, 040..041, 046 | DialogPane class/file/aggregate, UID0002OM, and `by-memory/-ignored.md` were read-only verify-only; exact padding rows remain present and no split/rename/new UID/source file/IDA edit occurred. |
| C1FE-043 | Current four manual coverage snapshots and exact stale/absent replacement text remain recorded under the supervisor-owned handoff; B004 made no manual edit. |
| C1FE-044 | Final waited validator `000000013716` exited 0 / ok 1. A later externally owned generated refresh produced evidence-time headers `000000013727` without ordinary-file drift; the target/proxy/TextDialog assertions below remained true on that readback. Unrelated later project validators may advance global generated headers without changing this callback proof. |

## Positive Evidence Summary

- Exact raw body is a conventional MSVC constructor shape with one project base-constructor call and three final class-vtable stores.
- Target signature is unique and boundaries are exact.
- All four message/menu derived constructors call the same DialogPane base initializer directly and install only their final derived vtables.
- TextDialog and proxy constructors do the same.
- RTTI proves TextDialog and proxy directly include Pursuit as their second/base descriptor before the identical six inherited descriptors.
- Shared helper consumers all read the exact Pursuit tail fields.
- DialogPane's existing declaration provides the exact base constructor signature.
- DialogPane has a concrete source-owned ordinary destructor body at `0x0049d9f0`; the shared wrapper calls that body directly and performs no Pursuit cleanup.
- Four emitted MessageDialogs derived declarations omit explicit destructors while their vtables share the same deleting-wrapper/adjustor family, directly supporting implicit derived destructor source shape.
- Current source tree already has a stable MessageDialogs class/file route.
- Existing shared destructor research cleanly separates handwritten source from compiler glue.

## IDA MCP Facts

- Evidence-time database: `64c11373`.
- Health: `status:ok`; auto-analysis, Hex-Rays, and string cache ready.
- Target:
  - no function at `0x0054cab0`;
  - next function `sub_54CAF0`, size `0x13f`;
  - base `sub_49D8A0`, size `0x148`;
  - zero xrefs to target;
  - one xref to each Pursuit vtable base, all from target stores.
- Target instructions:
  - `push 1`, `push 1`, `push offset word_60DB20`;
  - `call sub_49D8A0`;
  - vtable stores at `0x54cac8`, `0x54cad0`, `0x54cada`;
  - return at `0x54cae8`.
- MessageDialogs `sub_49D8A0` calls:
  - target `0x54cac3`;
  - MessageDialog `0x54ce5c`;
  - MessageDialogLarger `0x54dbdc`;
  - MenuQuestionDialog `0x54e972`;
  - MenuQuestionDialogLarger `0x54fb82`.
- Additional inlined calls:
  - TextDialog `0x55215c`;
  - proxy `0x553662`.
- RTTI:
  - Pursuit COL `0x64e360`, CHD `0x64e374`, base array `0x64e384`, 7 entries.
  - Text COL `0x64e7bc`, CHD `0x64e7d0`, base array `0x64e7e0`, 8 entries; second entry `0x64e3a4`.
  - Proxy COL `0x64e848`, CHD `0x64e85c`, base array `0x64e86c`, 8 entries; second entry `0x64e3a4`.
  - `0x64e3a4` begins with type descriptor `0x67890c`, named `??_R0?AVPursuitMessageDialogPane@@@8`.
- Repair-time proxy constructor:
  - local status-object construction call at `0x00553688`;
  - inherited `m_dialogType` store at `0x00553699`;
  - inherited `m_dialogId` store at `0x005536a8`;
  - packet-mode check/mutation at `0x005536ba-0x005536c1`;
  - status display-byte setup at `0x005536cb` and parse call at `0x005536d2`;
  - parser-negative return branch begins at `0x005536d9`;
  - inherited `m_dialogState` and `m_dialogPageIndex` stores occur only at `0x005536ee` and `0x00553701`;
  - no pre-parse zero stores exist for either inherited word.
- Destructor source closure:
  - `0x0049d9f0-0x0049dacb` is the ordinary source-owned DialogPane destructor cleanup body despite its polluted local symbol;
  - `0x00520b70-0x00520bab` calls that ordinary body directly and adds only deleting-destructor flag/delete/runtime handling;
  - primary vtable users include Pursuit, four message/menu siblings, TextDialog, proxy, and unrelated dialog classes;
  - the Pursuit/message/text primary slot is the same shared `0x00520b70`, with `0x00520aa5/0x00520ab0` adjusted views; proxy uses its late copies `0x005539c3/0x005539ce`;
  - no separate modeled Pursuit ordinary destructor body, custom cleanup call, field teardown, or source-only destructor route exists.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0054caa9-0x0054cab0` | UID0000VN `-ignored.md` | alignment | false | none | 100 | unchanged |
| `0x0054cab0-0x0054cae9` | UID0001FE target | Pursuit constructor | true | UID0000BE | `92/94` current | source-ready |
| `0x0054cae9-0x0054caf0` | UID0000VN `-ignored.md` | alignment | false | none | 100 | unchanged |
| `0x0054caf0-0x0054cc2f` | UID0001FF | base shared virtual | true | UID0000BE | `91/94` current | body preserved |
| `0x0054cc30-0x0054ce0f` | UID0001FG | three base helpers | true | UID0000BE | `92/94` current | source-ready |
| `0x0054ce10-0x00551021` | UID0001FH | family split index | false | UID0000LA | `88/90` | unchanged container |
| `0x00622424-0x006224c0` | UID0002OM | exact vtable data | true/generated-binary | UID0000BE | `86/91` | unchanged |
| type inventory | UID0001YI | class vtable inventory | true/generated-binary | UID0000BE | `90/94` current | owner correction |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0054cab0` | zero inbound xrefs | retained out-of-line copy has no surviving direct call |
| `0x00622428` | `0x0054cac8` only | primary vtable stored by target |
| `0x00622488` | `0x0054cad0` only | secondary vtable stored by target |
| `0x006224b8` | `0x0054cada` only | tertiary vtable stored by target |
| `0x0054ce10` | direct DialogPane call | derived MessageDialog inlines Pursuit base construction |
| `0x0054db90` | direct DialogPane call | derived MessageDialogLarger inlines Pursuit base construction |
| `0x0054e920` | direct DialogPane call | derived MenuQuestionDialog inlines Pursuit base construction |
| `0x0054fb30` | direct DialogPane call | derived MenuQuestionDialogLarger inlines Pursuit base construction |
| `0x00552110` | direct DialogPane call | RTTI-proven derived TextDialog inlines Pursuit base construction |
| `0x00553610` | direct DialogPane call | RTTI-proven derived proxy inlines Pursuit base construction |

## Documentation Evidence And IDA Status

- Current target accurately preserves raw bytes, vtable stores, no-function/no-xref facts, and padding.
- Current target is stale only in its source conclusion, owner/emitter route, score, and formal comment.
- Current class accurately declares the constructor/response virtual but unnecessarily declares an undefined explicit destructor; it also omits the shared tail fields/navigation helpers and contains a reverse-engineering offset comment inside formal C++.
- Current exact vtable-data page already uses class owner/emitter and remains the correct direct-parent precedent.
- Current type-vtable page bypasses to file owner/emitter and should match the exact vtable-data page.
- Current response virtual body is source-ready after B005's ObjectStatusBlob correction; only owner/emitter/prose/score change.
- Current navigation-helper no-owner proof was correct under its evidence at the time, but its missing-receiver premise is now false.
- Current TextDialog and proxy docs do not record their exact RTTI-proven direct base.
- Current proxy class formal is blank, has blank source position, and explicitly defers the declaration even though generated output emits two qualified definitions before a UID00009H Empty Emitter Marker.
- Current proxy constructor formal has a direct `DialogPane` initializer plus four member initializers that describe optimized machine lowering and illegally name inherited members; its state/page zero initializers also have no machine stores.
- Current manual coverage is stale for target, class, file, vtable, response, helper, TextDialog split/children, and proxy pages.
- Current MCP remained healthy throughout the completed bounded pass.

## Ranked Ownership Analysis

### 1. [UID:0000BE] PursuitMessageDialogPane

- Evidence for: exact RTTI name, target `ecx` constructor, three class vtable stores, source declaration, six direct derived RTTI/construction controls, shared tail fields, and member-form response virtual.
- Evidence against: no direct target xref and no modeled function.
- Decision: direct canonical owner and emitter for target, response virtual, navigation helpers, and vtable inventory.

### 2. [UID:0000LA] MessageDialogs

- Evidence for: stable source path, class declaration root, dispatcher, derived message/menu classes, resources, current generated file, and existing emitter chain.
- Evidence against: it is broader than the class and should not replace the narrow semantic owner.
- Decision: final source-file root only; class emits through it.

### 3. DialogPane

- Evidence for: direct constructor callee and physical base layout.
- Evidence against: target installs Pursuit vtables, RTTI has a distinct Pursuit class, and shared tail fields begin after DialogPane.
- Decision: dependency/base class, not target owner.

### 4. TextDialog or NexonclubProxyDialog

- Evidence for: both consume inherited fields/helpers.
- Evidence against: RTTI places Pursuit above each, and target predates both.
- Decision: derived consumers, not owners.

### 5. New standalone source file

- Evidence for: target has a distinct class symbol.
- Evidence against: every declaration, derived class, handler, helper, vtable, resource, and dispatcher route belongs to existing dialog source modules.
- Decision: rejected.

## Source Placement

- Declaration and target/helper/response definitions: `NexusTK/ui/dialogs/MessageDialogs.cpp` and its declaration surface.
- TextDialog source remains `NexusTK/ui/dialogs/TextDialog.cpp`, including or otherwise consuming the Pursuit declaration.
- Proxy source remains `NexusTK/ui/dialogs/NexonclubProxyDialog.cpp`, including or otherwise consuming the Pursuit declaration.
- Best source-facing include surface for the complete local proxy translation unit is the exact Destination 8 list; `MessageDialogs.h` supplies the complete base declaration, `StringBase.h` supplies the callback string type, and the remaining headers supply the already-accepted constructor/callback dependencies. Exact historical header packaging remains inferred and is confidence-capped rather than deferred.
- Rejected: `DialogPane.cpp`, `MapPane.cpp`, `TextDialog.cpp` as helper owner, `NexonclubProxyDialog.cpp` as helper owner, and a new Pursuit-only source file.
- Remaining uncertainty: exact original header filename and whether the tiny base declaration lived in `MessageDialogs.h` or a broader dialog header. This does not affect current file emitter routing.

## Range / Split / Padding / Reclassification Analysis

- No range change: `[0x0054cab0,0x0054cae9)` remains exact.
- No split: all 57 bytes are one constructor body.
- No child creation: target already has an exact singular page.
- No rename: current filename and title identify the source method correctly.
- Reclassification: comment-only raw constructor -> source-ready raw constructor with exact human body.
- Padding:
  - `[0x0054caa9,0x0054cab0)` unchanged;
  - `[0x0054cae9,0x0054caf0)` unchanged.
- Parent/container impact:
  - target owner/emitter changes to UID0000BE;
  - UID0001YI and UID0001FF also route through UID0000BE;
  - UID0001FG becomes a UID0000BE child;
  - UID0001FH remains a false/non-emitting split index.

## Negative Evidence Summary

- No target caller, function object, pointer table, export, import, vtable slot, or relocation survives.
- No evidence supports a directly instantiated Pursuit object.
- No source body initializes the packet tail fields in the base constructor; derived constructors initialize them from packets.
- No evidence supports explicit source vptr writes, explicit `return this`, explicit RTTI/vtable tables, or deleting-wrapper code.
- No evidence supports a distinct Pursuit ordinary destructor symbol or any cleanup beyond the inherited DialogPane destructor.
- No source need supports retaining an explicit Pursuit destructor declaration; sibling classes with the same wrapper omit one.
- No evidence supports proxy-owned copies of the four inherited fields or any proxy object size beyond `0x278`.
- No instruction supports pre-parse zero initialization of `m_dialogState` or `m_dialogPageIndex`.
- No class-specific cleanup supports an explicit proxy destructor body; the shared wrapper/adjustors are compiler evidence only.
- No evidence supports putting the fields on DialogPane.
- No evidence supports a new source file.
- No evidence recovers original private helper/field spellings; report names are descriptive and behavior-preserving.
- No evidence supports changing UID0001FH's false/non-emitting parent disposition.
- No evidence supports filling TextDialog's large constructor/action bodies in this target-specific callback.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing identities:
  - `PursuitMessageDialogPane::PursuitMessageDialogPane()`;
  - `m_dialogType`, `m_dialogId`, `m_dialogState`, `m_dialogPageIndex`;
  - `SendPreviousDialogPacket`, `SendNextDialogPacket`, `SendCurrentDialogPacket`.
  - anonymous-namespace `NexonclubProxyDialog` with public constructor and private `OnReplyText`.
- Keep exact RTTI class name `PursuitMessageDialogPane`.
- Remove the formal-source comment `// binary field at event/action object +0x0c` from `DialogObjectAction::payload`; preserve the offset fact in prose.
- Do not request IDA function creation or rename for `0x0054cab0` in this assignment.
- No IDA DB edit is safe or necessary for report acceptance.

## First-Draft C++ Recommendation

- Eligible: yes.
- Formal destination count: 8 complete managed blocks.
- The following blocks are exact callback insertion/replacement text, not illustrative snippets.

### Destination 1 - UID0001FE target

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PursuitMessageDialogPane::PursuitMessageDialogPane()
    : DialogPane(L"", 1, 1)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - UID0000BE class

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct DialogObjectAction
{
    const unsigned char *payload;
};

class PursuitMessageDialogPane : public DialogPane
{
public:
    PursuitMessageDialogPane();
    virtual bool HandleDialogObjectResponse(const DialogObjectAction *action);

protected:
    void SendPreviousDialogPacket();
    void SendNextDialogPacket();
    void SendCurrentDialogPacket();

    unsigned char m_dialogType;
    unsigned int m_dialogId;
    unsigned short m_dialogState;
    unsigned short m_dialogPageIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID0001FG navigation helpers

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PursuitMessageDialogPane::SendPreviousDialogPacket()
{
    unsigned char packet[11];
    PacketBufferWriteUInt8(0x3a, packet);
    PacketBufferWriteUInt8(m_dialogType, packet + 1);
    PacketBufferWriteUInt32BE(m_dialogId, packet + 2);
    PacketBufferWriteUInt16BE(m_dialogState, packet + 6);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(m_dialogPageIndex - 1),
        packet + 8);
    packet[10] = 0;
    g_packetSender->QueueAndSendPacket(packet, 10);
}

void PursuitMessageDialogPane::SendNextDialogPacket()
{
    unsigned char packet[11];
    PacketBufferWriteUInt8(0x3a, packet);
    PacketBufferWriteUInt8(m_dialogType, packet + 1);
    PacketBufferWriteUInt32BE(m_dialogId, packet + 2);
    PacketBufferWriteUInt16BE(m_dialogState, packet + 6);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(m_dialogPageIndex + 1),
        packet + 8);
    packet[10] = 0;
    g_packetSender->QueueAndSendPacket(packet, 10);
}

void PursuitMessageDialogPane::SendCurrentDialogPacket()
{
    unsigned char packet[11];
    PacketBufferWriteUInt8(0x3a, packet);
    PacketBufferWriteUInt8(m_dialogType, packet + 1);
    PacketBufferWriteUInt32BE(m_dialogId, packet + 2);
    PacketBufferWriteUInt16BE(m_dialogState, packet + 6);
    PacketBufferWriteUInt16BE(m_dialogPageIndex, packet + 8);
    packet[10] = 0;
    g_packetSender->QueueAndSendPacket(packet, 10);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID0001FF response virtual

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PursuitMessageDialogPane::HandleDialogObjectResponse(const DialogObjectAction *action)
{
    const unsigned char *payload = action->payload;

    if (payload[0] == 0x2f)
        return true;
    if (payload[0] != 0x30)
        return false;

    ObjectStatusBlob objectStatus;
    objectStatus.m_displayStatusByte = 0x50;

    const unsigned char responseType = payload[2];
    const unsigned int objectId = PacketBufferReadUInt32BE(payload + 3);
    const int parsedStatusLength = objectStatus.ParseTaggedStatus(payload + 8);
    const int trailingOffset = (parsedStatusLength >= 0) ? parsedStatusLength + 12 : 12;
    const unsigned short responseValue1 = PacketBufferReadUInt16BE(payload + trailingOffset);
    const unsigned short responseValue2 = PacketBufferReadUInt16BE(payload + trailingOffset + 2);

    unsigned char packet[11];
    PacketBufferWriteUInt8(0x3a, packet);
    PacketBufferWriteUInt8(responseType, packet + 1);
    PacketBufferWriteUInt32BE(objectId, packet + 2);
    PacketBufferWriteUInt16BE(responseValue1, packet + 6);
    PacketBufferWriteUInt16BE(responseValue2, packet + 8);
    packet[10] = 0;

    g_packetSender->QueueAndSendPacket(packet, 10);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID0001YI vtable inventory

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// PursuitMessageDialogPane vtables, RTTI, implicit virtual destructor dispatch, and deleting wrappers are compiler-generated from the class declaration; do not hand-port the table bytes or ABI wrappers as handwritten source.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8 - UID00009H proxy class

This class destination has source position `0`, so the declaration and its include surface emit before the constructor/callback children. The class has no derived data members: exact allocation size `0x278` equals the complete Pursuit base size, and the four packet fields are inherited protected state. No destructor is declared explicitly. `DialogPane::~DialogPane()` is virtual, so the implicitly declared Pursuit destructor and the implicitly declared proxy destructor are virtual through ordinary destructor overriding; the shared scalar deleting destructor and `+0xa0/+0xa4` adjustors remain compiler-generated.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <string.h>
#include <windows.h>

#include "FunctionObjects.h"
#include "MessageDialogs.h"
#include "NexonclubRegistrationDialog.h"
#include "ObjectStatusBlob.h"
#include "PacketBuffer.h"
#include "Socket.h"
#include "StringBase.h"

namespace
{
class NexonclubProxyDialog : public PursuitMessageDialogPane
{
public:
    explicit NexonclubProxyDialog(unsigned char *packet);

private:
    void OnReplyText(const StringBaseW& text);
};

[[CHILDREN]]
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID0001FK proxy constructor

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NexonclubProxyDialog::NexonclubProxyDialog(unsigned char *packet)
    : PursuitMessageDialogPane()
{
    ObjectStatusBlob objectStatus;

    m_dialogType = packet[0];
    m_dialogId = PacketBufferReadUInt32BE(packet + 1);

    if (packet[5] == 2)
        packet[6] = 2;

    objectStatus.m_displayStatusByte = 0x50;

    int statusBytes = objectStatus.ParseTaggedStatus(packet + 6);
    if (statusBytes < 0)
        return;

    unsigned char *cursor = packet + statusBytes + 10;

    m_dialogState = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    m_dialogPageIndex = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    unsigned char dialogWidthByte = *cursor++;
    unsigned char dialogHeightByte = *cursor++;
    (void)dialogWidthByte;
    (void)dialogHeightByte;

    unsigned short messageLength = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    char messageBytes[0x8000];
    wchar_t messageText[0x8000];
    memmove(messageBytes, cursor, messageLength);
    cursor += messageLength;
    messageBytes[messageLength] = '\0';

    int messageChars = MultiByteToWideChar(
        0,
        0,
        messageBytes,
        messageLength,
        messageText,
        _countof(messageText));
    messageText[messageChars] = L'\0';

    unsigned char firstButtonLength = *cursor++;
    char buttonBytes[0x8000];
    wchar_t firstButtonText[256];
    memmove(buttonBytes, cursor, firstButtonLength);
    cursor += firstButtonLength;
    buttonBytes[firstButtonLength] = '\0';

    int firstButtonChars = MultiByteToWideChar(
        0,
        0,
        buttonBytes,
        firstButtonLength,
        firstButtonText,
        _countof(firstButtonText));
    firstButtonText[firstButtonChars] = L'\0';

    unsigned char unusedButtonSeparator = *cursor++;
    (void)unusedButtonSeparator;

    unsigned char secondButtonLength = *cursor++;
    wchar_t secondButtonText[256];
    memmove(buttonBytes, cursor, secondButtonLength);
    buttonBytes[secondButtonLength] = '\0';

    int secondButtonChars = MultiByteToWideChar(
        0,
        0,
        buttonBytes,
        secondButtonLength,
        secondButtonText,
        _countof(secondButtonText));
    secondButtonText[secondButtonChars] = L'\0';

    FunctionObjectT<const StringBaseW&> *callback =
        new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(
            this,
            &NexonclubProxyDialog::OnReplyText);

    new NexonclubRegistrationDialog(messageText, callback);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7 - UID0003GL proxy callback

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NexonclubProxyDialog::OnReplyText(const StringBaseW& text)
{
    if (text.empty()) {
        SendCurrentDialogPacket();
        CloseDialog();
        return;
    }

    unsigned char packet[0x200];
    int packetLength = 0;

    PacketBufferWriteUInt8(0x3a, packet + packetLength);
    packetLength += 1;

    PacketBufferWriteUInt8(m_dialogType, packet + packetLength);
    packetLength += 1;

    PacketBufferWriteUInt32BE(m_dialogId, packet + packetLength);
    packetLength += 4;

    PacketBufferWriteUInt16BE(m_dialogState, packet + packetLength);
    packetLength += 2;

    PacketBufferWriteUInt16BE(m_dialogPageIndex + 1, packet + packetLength);
    packetLength += 2;

    PacketBufferWriteUInt8(2, packet + packetLength);
    packetLength += 1;

    PacketBufferAppendWideStringAsAnsi8(text.c_str(), packet, &packetLength);

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<unsigned short>(packetLength));

    CloseDialog();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior match:
  - Destination 1 emits only the base call represented by target bytes.
  - Destination 2 supplies the RTTI/layout-backed declaration without explicit padding or an undefined explicit destructor; the compiler implicitly declares its virtual destructor from the DialogPane base contract.
  - Destination 3 preserves exact packet fields, previous/next/current arithmetic, terminator, and ten-byte send.
  - Destination 4 is byte-flow-equivalent to the accepted current handler.
  - Destination 5 keeps vtable/RTTI compiler-generated.
  - Destination 8 emits the anonymous proxy declaration at source position `0`, includes the required base/string/body dependency surface, declares no duplicate fields, and relies on implicitly declared virtual destructor dispatch to regenerate shared compiler glue.
  - Destination 6 matches the exact repair-time store order: local status object, inherited type/id assignments, packet-mode adjustment, display-byte setup, parse, then inherited state/page assignments only on success.
  - Destination 7 is legal under Destination 8: its private member body can call the protected Pursuit helper and public DialogPane close method.

## Final Recommendation

- Destinations 1 through 8 are implemented exactly and remain the recommended terminal source representation.
- Target owner/emitter is class UID0000BE at `92/94`; UID0000BE contains the shared fields/helper declarations at `92/94`.
- The undefined explicit Pursuit destructor declaration is removed. Implicit virtual destruction and source-owned DialogPane ordinary cleanup are the terminal source contract.
- UID0001FG belongs to UID0000BE and emits its three methods at `92/94`.
- UID0001FF and UID0001YI route through UID0000BE; the response body and generated-binary vtable policy are preserved.
- UID0000LA remains the final source root at `92/92` with the complete current source-family union.
- TextDialog and proxy documentation records direct Pursuit inheritance.
- The source-position-zero proxy declaration precedes its exact constructor/callback children.
- TextDialog constructor/action bodies remain blank for separate blockers; UID0001FH remains false/blank; UID0002OM and DialogPane remain verify-only unchanged.
- The exact manual coverage handoff remains supervisor-owned and unapplied by B004.

## Recommended Target Doc Changes

- Path: `by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md`.
- Applied metadata:
  - `86/90 -> 92/94`;
  - `CANONICAL_OWNER:0000LA -> 0000BE`;
  - `EMITTER_UIDS:0000LA -> 0000BE`;
  - retain true, blank position, `Nested:0`.
- Formal: Destination 1 installed exactly.
- Item Summary: exact range/hash, unique signature, DialogPane initializer, six inlined derived-constructor controls, class owner/emitter, compiler vptr/return exclusion, and accepted human source are recorded.
- Applied prose:
  - preserve exact bytes, stores, xrefs, pointer negatives, and padding;
  - historicalize B010 no-code conclusion;
  - add RTTI/direct-base/source-liveness explanation;
  - reject free helper, standalone file, explicit vptr, and no-code alternatives.

## Recommended Support Doc Changes

- `by-class/PursuitMessageDialogPane.md` applied:
  - `86/88 -> 92/94`;
  - install Destination 2;
  - add exact shared layout and six direct derived classes;
  - remove `virtual ~PursuitMessageDialogPane();` and document the implicitly declared virtual destructor route through source-owned `DialogPane::~DialogPane()`;
  - remove stale no-code/open route wording;
  - preserve response/payload history and distinguish ordinary DialogPane cleanup from compiler deleting-wrapper/adjustor history.
- `by-type/by-vtable/PursuitMessageDialogPaneVtables.md` applied:
  - `86/90 -> 90/94`;
  - owner/emitter `0000LA -> 0000BE`;
  - install Destination 5;
  - add RTTI hierarchy, source-constructor linkage, and implicit-destructor/generated-wrapper source boundary.
- `by-file/MessageDialogs.md` applied:
  - `91/88 -> 92/92`;
  - retain path/file owner;
  - replace target no-code row with source-ready constructor;
  - record class-owned fields/helpers and TextDialog/proxy direct inheritance;
  - record that Pursuit and direct derived classes rely on implicit virtual destructors while DialogPane owns ordinary cleanup and shared wrappers remain compiler output;
  - preserve all unrelated current dialog union.
- `by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md` applied:
  - `90/92 -> 91/94`;
  - owner/emitter `0000LA -> 0000BE`;
  - preserve Destination 4 byte-for-byte;
  - add inherited virtual relationship across six derived classes.
- `by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md` applied:
  - `88/90 -> 92/94`;
  - owner `NONE -> 0000BE`;
  - emitter blank -> `0000BE`;
  - install Destination 3;
  - historicalize prior no-owner proof and state the new RTTI receiver evidence.
- `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md` applied:
  - keep `88/90`, false, blank;
  - add that four constructor children inline Pursuit base initialization;
  - preserve all split/raw/padding/history evidence.
- `by-class/TextDialog.md` applied:
  - `87/88 -> 88/92`;
  - retain owner/emitter/file and blank formal;
  - correct direct base to Pursuit and inherited field/helper source;
  - remove shared-helper no-owner statement while preserving Text-specific body blockers.
- `by-file/TextDialog.md` applied:
  - `89/88 -> 89/90`;
  - record dependency on the Pursuit declaration and inherited helper route;
  - preserve separate file ownership and all current constructor/action/raw-island detail.
- `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md` applied:
  - `87/90 -> 88/92`;
  - retain owner/emitter and blank formal;
  - correct human direct base to Pursuit and state direct DialogPane call is inlined lowering;
  - preserve every large-body blocker.
- `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` applied:
  - `86/90 -> 87/92`;
  - retain owner/emitter and blank formal;
  - replace shared-helper source-placement blocker with inherited base-method calls;
  - preserve typed-text inline behavior and raw-island exclusion.
- `by-class/NexonclubProxyDialog.md` applied:
  - `88/90 -> 91/94`;
  - retain owner/emitter, set source position `0`, and install Destination 8;
  - declare the direct Pursuit base, public constructor, private `OnReplyText`, no derived fields, implicitly declared virtual destructor disposition through DialogPane, required includes, and `[[CHILDREN]]`;
  - remove the later-class-declaration deferral and preserve anonymous-namespace, exact `0x278` size, shared compiler-destructor, callback, and registration-handoff evidence.
- `by-file/NexonclubProxyDialog.md` applied:
  - `87/90 -> 89/93`;
  - record the complete source-position-zero local class declaration, required dependency surface, and Pursuit header route before child definitions;
  - preserve separate source placement and registration-flow merge caveat.
- `by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md` applied:
  - `90/92 -> 92/94`;
  - install Destination 6;
  - preserve all packet/text/callback behavior and rejected alternatives;
  - record exact body-store order and reject inherited-field member initializers, unsupported state/page zero stores, and duplicate derived fields.
- `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md` applied:
  - `89/92 -> 90/94`;
  - install Destination 7;
  - preserve packet layout, empty fallback, send length, callback binding, and close behavior;
  - record that protected `SendCurrentDialogPacket()` and public `CloseDialog()` are legal inherited calls from the declared private member.
- Verify-only confirmed:
  - UID0002OM exact vtable data remains `86/91`, owner/emitter `0000BE`, current marker.
  - UID00003T/UID00012R/UID0000IT DialogPane remain unchanged.
  - `by-memory/-ignored.md` remains unchanged.

## Score And Metadata Recommendation

| UID | Before callback | Current | Owner/emitter change | Rationale |
| --- | --- | --- | --- | --- |
| 0001FE | 86/90 | 92/94 | `0000LA -> 0000BE` both | exact source body, liveness explanation, class ownership |
| 0000BE | 86/88 | 92/94 | none | complete base layout/method declaration, implicit virtual destructor closure, and RTTI family |
| 0001YI | 86/90 | 90/94 | `0000LA -> 0000BE` both | direct class vtable inventory and exact RTTI |
| 0001FF | 90/92 | 91/94 | `0000LA -> 0000BE` both | existing exact body plus corrected base ownership |
| 0001FG | 88/90 | 92/94 | `NONE/blank -> 0000BE/0000BE` | missing receiver/source route resolved |
| 0000LA | 91/88 | 92/92 | none | target family source graph now coherent |
| 0000EL | 87/88 | 88/92 | none | direct base and inherited state resolved; body still blank |
| 0000OL | 89/88 | 89/90 | none | source dependency corrected |
| 0003VQ | 87/90 | 88/92 | none | base/fields resolved; large body blockers remain |
| 0003VR | 86/90 | 87/92 | none | helper source route resolved; own body blockers remain |
| 00009H | 88/90 | 91/94 | position blank -> `0` | complete anonymous class declaration, no derived fields, implicit virtual destructor, child ordering |
| 0000LZ | 87/90 | 89/93 | none | complete local-class/dependency/source ordering corrected |
| 0001FK | 90/92 | 92/94 | none | legal direct-base initializer and exact inherited-field body-store order |
| 0003GL | 89/92 | 90/94 | none | inherited member calls replace free helper shape |
| 0001FH | 88/90 | unchanged | none | already-correct non-emitting split index |
| 0002OM | 86/91 | unchanged | none | already-correct class-owned generated-binary page |

Score-limiting blockers and resolution:

- No target caller: resolved as retained out-of-line copy with six inlined derived controls; confidence remains below 95 because original build/link options are unavailable.
- No original private field/helper spellings: resolved with consistent source-facing names; confidence capped at 94.
- Original header packaging unknown: source file route is stable; confidence cap only.
- TextDialog body complexity: not a target blocker; exact direct base and fields resolved, body remains separately blank with conservative scores.
- Pursuit ordinary destructor source: resolved by omitting the explicit declaration. The implicitly declared destructor is virtual because DialogPane's destructor is virtual, and its only ordinary cleanup is the existing DialogPane body.
- Vtable/deleting-destructor source: resolved separately as generated binary/compiler glue; no wrapper or adjustor source body is required.
- Proxy class declaration/order: resolved by Destination 8 at source position `0`; the constructor and callback now have a declaration before definitions and the class marker is no longer an accepted endpoint.
- Proxy derived layout/destructor: resolved as no added fields and no explicit destructor declaration; exact `0x278` allocation plus implicit virtual destructor dispatch regenerate the shared primary/adjustor deleting-destructor code.

## Open Questions With Attempted Resolution

- Why is the out-of-line constructor retained with zero calls?
  - Checked xrefs, pointer patterns, exact signature, all derived constructors, and source-era optimizer behavior.
  - Best resolution: compiler emitted an externally visible out-of-line definition while inlining it into all observed derived constructors.
  - Impact: no target C++ blocker; confidence cap only.
- What did `Pursuit` mean in product semantics?
  - Checked class family, packet creator, MapPane adapter, dialogs, RTTI, and prior reports.
  - No safe expansion exists. Preserve exact symbol name without invented semantics.
  - Impact: none.
- Are the field names original?
  - Checked constructor stores, helper serialization, proxy callback, menu/message docs, and type widths.
  - Names are highest-probability descriptive source names; exact spelling is unrecoverable.
  - Impact: confidence below 95, not a C++ blocker.
- Did the original source use a separate header?
  - Checked current file routes and cross-file derived classes.
  - A shared declaration surface is required, but exact filename is unavailable.
  - Impact: file documentation note only.
- Should TextDialog's full class/body be emitted now?
  - Checked the exact B012 constructor report and action page.
  - No. This report resolves base/fields/helper placement but not its large UI/control/local cleanup body.
  - Impact: TextDialog target formals remain blank with evidence-backed score cap.
- Should Pursuit explicitly declare or define a destructor?
  - Checked live `0x0049d9f0` DialogPane ordinary cleanup, live `0x00520b70` deleting-wrapper lowering, all early/late adjustor routes, the 17-primary-consumer matrix, Pursuit/message/text/proxy vtables, and current sibling class declarations.
  - No. Destination 2 must omit an explicit destructor. `DialogPane::~DialogPane()` is virtual, so C++03 implicitly declares a virtual Pursuit destructor; because Pursuit owns only POD packet fields, its ordinary destruction requires no handwritten work beyond inherited DialogPane cleanup.
  - Impact: no unresolved destructor definition remains, and the shared scalar deleting wrapper/adjustors stay compiler output rather than source substitutes.
- Should proxy class declaration be emitted now?
  - Checked current blank class formal, generated child-before-class ordering, exact `0x278` allocation, RTTI direct base, callback binding, shared deleting-destructor consumer matrix, and repair-time constructor disassembly.
  - Yes. Destination 8 is the complete source-position-zero anonymous declaration. It has no derived fields, declares the public constructor and private callback, and intentionally relies on the implicitly declared virtual destructor inherited from Pursuit.
  - Impact: no proxy declaration/source-order blocker remains; generated output must place the declaration before definitions and contain no UID00009H Empty Emitter Marker.
- Can Destination 6 initialize inherited packet fields in its member-initializer list?
  - No. C++ only permits a constructor initializer to name eligible base-class subobjects and members of the class being constructed. Fresh MCP additionally proves there are no state/page zero stores.
  - Best resolution: retain only `PursuitMessageDialogPane()` in the initializer list; construct the local status object, assign inherited type/id in the body, preserve mode/display/parser order, and assign state/page only after successful parsing.
  - Impact: Destination 6 is now legal C++03 and preserves the parser-negative binary path.
- Are Destination 7 inherited calls accessible?
  - Yes. Destination 2 declares `SendCurrentDialogPacket()` protected, and current DialogPane declares `CloseDialog()` public.
  - Impact: a private `NexonclubProxyDialog::OnReplyText` definition can call both without free helpers or casts.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current inspected manual snapshots from the post-callback readback:

- `by-memory/-coverage-report.md`: SHA256 `0F53BD71C344B862EA58BA12BE64ABAECE6D3579BBF13566A8197E506DCB1344`, 1,746,578 bytes / 4,213 lines.
- `by-class/-coverage-report.md`: SHA256 `E61DB3F079B38666072FDC89D71737BAB9CFBD85C00A3DC7A836D7DB6E34DCD5`, 225,165 / 622.
- `by-file/-coverage-report.md`: SHA256 `A1B73657FCC4F2A5F131C7E3F355E8D007538D0323397DFD7F026F64A59DF882`, 128,817 / 316.
- `by-type/by-vtable/-coverage-report.md`: SHA256 `2D8E369A8447F8B31D5AE5A0C5EF79BEC4A85D0192EB789DD6A1D4E77663C444`, 66,052 / 142.
- An external supervisor-owned refresh at `2026-07-16T09:06:18-04:00` advanced the first three manual snapshots. Current reread confirms that the relevant rows remain stale or absent: UID0001FE/UID0001FF/UID0001FG/UID0001FH/UID0001FJ/UID0001FK are at by-memory lines 2819/2821/2823/2825/2829/2831; UID0003VQ/UID0003VR/UID0003VS/UID0003GL remain absent; UID00009H/UID0000BE/UID0000EL are at by-class lines 364/432/546; UID0000LA/UID0000LZ/UID0000OL are at by-file lines 163/188/282; and UID0001YI remains at by-vtable line 105. The exact replacements/additions below therefore remain current and no-loss.

Supervisor-owned exact by-memory replacements/additions:

- Replace current UID0001FE row between the two existing padding rows with:

`    - [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md) 0x0054cab0-0x0054cae9 | raw constructor | PursuitMessageDialogPaneConstructor : reconstructable : 92% : very-strong : Exact 57-byte retained out-of-line PursuitMessageDialogPane constructor with unique SHA/signature, DialogPane(L"", 1, 1) base initialization, three compiler vtable stores, six RTTI/constructor-proven inlined derived uses, direct class owner/emitter UID0000BE, complete human formal C++, preserved zero-xref/pointer negative evidence, and unchanged seven-CC boundaries.`

- Replace current UID0001FF row with:

`    - [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md) 0x0054caf0-0x0054cc2f | virtual handler | MessageDialogObjectResponseVirtual : reconstructable : 91% : very-strong : Source-ready PursuitMessageDialogPane::HandleDialogObjectResponse with exact eight inherited vtable refs, DialogObjectAction payload flow, ObjectStatusBlob tagged-status parse, opcode 0x3a reply layout, g_packetSender/QueueAndSendPacket route, direct class owner/emitter UID0000BE, and preserved current formal body.`

- Replace current UID0001FG row with:

`    - [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md) 0x0054cc30-0x0054ce0f | class method cluster | PursuitMessageDialogPane navigation packet methods : reconstructable : 92% : very-strong : Exact previous/next/current opcode 0x3a packet methods now assigned to RTTI-proven shared base PursuitMessageDialogPane, with inherited m_dialogType/m_dialogId/m_dialogState/m_dialogPageIndex fields, complete formal C++, all six derived caller families, exact boundaries/padding, sender/helper dependencies, and historical no-owner premise superseded by current base-array evidence.`

- Replace current UID0001FH row with:

`    - [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) 0x0054ce10-0x00551021 | split-index | NpcMessageAndMenuQuestionDialogs : ignored/non-emitting : 88% : very-strong : Exact non-emitting message/menu-question family index over registered constructor/action/list/raw/padding children; four constructor children inline the shared PursuitMessageDialogPane base initialization, while exact child pages retain source ownership and the parent remains false with blank C++.`

- Replace current stale UID0001FJ row with:

`    - [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md) 0x00552110-0x005534a0 | split-index | TextDialogCore : ignored/non-emitting : 88% : very-strong : Non-emitting exact TextDialog constructor/action/raw-island index; current RTTI proves TextDialog directly derives from PursuitMessageDialogPane and inherits the shared dialog packet fields/helpers, while exact children retain their own body/no-code dispositions and the proxy callback begins separately at 0x005534a0.`

- Preserve the raw-space hierarchy from the current `Nested` metadata. Let the existing UID0001FJ row be cumulative indentation `I`: UID0003VQ applies `+8` (`I+8`), UID0003VR applies `0` (`I+8`), UID0003VS applies `-4` (`I+4`), UID0003GL applies `+8` (`I+12`), and UID0001FK applies `0` (`I+12`). In the current manual file, `I` is four leading spaces, so the exact rows below use 12, 12, 8, 16, and 16 leading spaces respectively.

- Immediately under UID0001FJ, add/update these child rows in address order:

`            - [UID:0003VQ][0x00552110-0x0055317a.TextDialogConstructor](by-memory/0x00552110-0x0055317a.TextDialogConstructor.md) 0x00552110-0x0055317a | constructor | TextDialogConstructor : reconstructable : 88% : very-strong : Exact large TextDialog constructor with four factory call forms, TextDialog vtable stores, RTTI-proven direct PursuitMessageDialogPane base, inherited dialog packet fields at +0x26c/+0x270/+0x274/+0x276, exact boundary, and preserved blank formal pending separate UI/control/local cleanup reconstruction.`

`            - [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md) 0x00553180-0x00553338 | virtual handler | TextDialogHandleDialogAction : reconstructable : 87% : very-strong : Exact typed-text/action handler with inline submit packet and inherited PursuitMessageDialogPane previous/next/current member calls; shared helper source placement is resolved while command/control/body names remain a separate formal-C++ blocker.`

`        - [UID:0003VS][0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw](by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md) 0x00553350-0x00553495 | no-route raw code island | TextDialogUnreferencedSubmitPacketRaw : ignored/non-emitting : 88% : very-strong : Preserved source-shaped opcode 0x3a text-submit clone with no function/xref/VA/RVA/direct-branch route, action switch targets confined to the live handler, owner NONE, reconstructable false, blank emitter/C++, and exact liveness condition unchanged.`

- Immediately after the UID0001FJ block and before `0x00553609-0x00553610` padding, add:

`                - [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md) 0x005534a0-0x00553609 | callback method | NexonclubProxyDialogReplyCallback : reconstructable : 90% : very-strong : Source-ready private anonymous-namespace NexonclubProxyDialog::OnReplyText callback declared before definition, with RTTI-proven PursuitMessageDialogPane inheritance, inherited packet fields, protected SendCurrentDialogPacket fallback, exact opcode 0x3a text reply, g_packetSender send, callback binding, and public CloseDialog member calls.`

- Replace current UID0001FK row with:

`                - [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md) 0x00553610-0x005538fd | constructor | NexonclubProxyDialogConstructor : reconstructable : 92% : very-strong : Complete legal proxy constructor with only the RTTI-proven direct PursuitMessageDialogPane base initializer, inherited type/id body assignments in exact observed order, state/page assignments only after successful ObjectStatusBlob parsing, no unsupported zero initializers, narrow/wide text conversion, callback wrapper to OnReplyText, registration-dialog handoff, and exact vtable/boundary evidence.`

Supervisor-owned exact by-class replacements:

`- [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md) : reconstructable : 92% : very strong : Complete DialogPane-derived shared message/text/proxy base with exact constructor, RTTI/vtable hierarchy, 0x278 byte/dword/word/word packet-tail layout, three source-ready navigation packet methods, shared object-response virtual, six direct derived classes, source-closed implicitly declared virtual destructor through DialogPane, compiler-only deleting-wrapper/vtable exclusions, and MessageDialogs source route.`

`- [UID:0000EL][TextDialog](by-class/TextDialog.md) : reconstructable : 88% : very strong : RTTI-proven PursuitMessageDialogPane-derived text/input dialog with inherited dialog packet fields/navigation methods, exact constructor/action/raw-island children and source-file route; large constructor/action formals remain blank only for their separate UI/control/local cleanup blockers.`

`- [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md) : reconstructable : 91% : very strong : Complete source-position-zero anonymous-namespace class declaration deriving directly from PursuitMessageDialogPane, with public packet constructor, private OnReplyText callback, no derived data fields, inherited dialog packet/navigation state, implicitly declared virtual destructor through DialogPane, required includes, [[CHILDREN]] ordering, exact vtables/callback wrapper, and registration-dialog handoff.`

Supervisor-owned exact by-file replacements:

`- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) : reconstructable : 92% : very strong : Message/menu-question source family with complete creator/dispatcher/class union; adds source-ready PursuitMessageDialogPane constructor, RTTI-backed shared packet-tail layout, previous/next/current packet methods, class-owned response virtual/vtable routing, implicitly declared virtual destructors over source-owned DialogPane cleanup, six direct derived classes including TextDialog/proxy cross-file consumers, and preserved split/raw/compiler/history boundaries.`

`- [UID:0000OL][TextDialog](by-file/TextDialog.md) : reconstructable : 89% : strong : Packet-driven TextDialog source module now documented as consuming the shared PursuitMessageDialogPane declaration and inherited packet/navigation surface; exact constructor/action/raw-island ownership remains local, with large body C++ still conservatively blank.`

`- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md) : reconstructable : 89% : very strong : Compact anonymous-namespace proxy adapter source module with complete declaration-before-definition ordering, MessageDialogs/StringBase and body dependency surface, corrected direct-base constructor source, inherited packet/navigation fields, private OnReplyText callback, callback object and registration handoff, implicitly declared virtual destructor plus compiler-generated deleting wrappers/vtables, and preserved separate-file caveat.`

Supervisor-owned exact by-type/by-vtable replacement:

`- [UID:0001YI][PursuitMessageDialogPaneVtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md) : reconstructable : 90% : very strong : Class-owned source-declared/generated-binary PursuitMessageDialogPane RTTI/vtable inventory with exact three views/stores/slots, seven-entry base hierarchy, six RTTI-proven derived classes, implicit virtual destructor source closure over DialogPane cleanup, shared compiler deleting-wrapper/adjustor disposition, source-ready constructor/navigation/response methods, direct owner/emitter UID0000BE, and no handwritten vtable-table policy.`

- No by-struct manual file is involved.
- B004 must not apply these rows directly; manual coverage is supervisor-owned.

## Follow-Up Actions

- The implementation callback is complete and no accepted claim is blocked.
- Manual coverage remains supervisor-owned and was not applied by B004.
- B004 ran no report execution, lifecycle, move, or archive command.
- The following marker records only B004's completed handoff for independent supervisor Gate 2; all validation, execution, count, path, movement, and archive state remains external supervisor/validator-owned:

READY_FOR_SUPERVISOR_GATE2_REVIEW

- External supervisor/validator processes own report validation, execution, count, path, movement, archive, and manual-coverage state; this artifact neither asserts nor directs those lifecycle outcomes.
- No implementation item remains. The 15 authorized ordinary destinations were reread, edited, scoped-validated, and released one at a time.
- The exact stale/absent manual coverage replacement text remains the only supervisor-owned documentation handoff; B004 did not edit manual coverage.
- A-agent action: none required; no IDA mutation is recommended.
- B004 future research action: none for the target or proxy source closure. TextDialog's large constructor/action bodies remain separate existing targets, not unresolved UID0001FE work.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: `93/100`.
- Direct facts: target bytes/range/hash, no function/xrefs, base call, vtable stores, derived call sites, RTTI hierarchy, current metadata.
- High-confidence inference: retained out-of-line constructor plus inlining, field names, helper names, source header route.
- Residual uncertainty: original private spellings, exact header filename, original optimizer/linker flags, and product meaning of `Pursuit`.

## Validator Results

- All commands ran from `source-3/project-documentation`; every scoped command exited `0` with `ok:1`.

| Command | Timestamp | Scoped file | Result / warnings / side effects |
| --- | --- | --- | --- |
| `000000013686` | `2026-07-16T09:27:30-04:00` | UID0001FE | completion/confidence/owner/emitter/formal registry updates; generated deferred |
| `000000013687` | `2026-07-16T09:28:33-04:00` | UID0000BE | completion/confidence/formal update; one reference-index add; generated deferred |
| `000000013688` | `2026-07-16T09:29:12-04:00` | UID0001YI | completion/confidence/owner/emitter/formal update; generated stats row removed/rescore recommended; generated deferred |
| `000000013689` | `2026-07-16T09:30:33-04:00` | UID0000LA | score update; one UID link normalization; 70 pre-existing missing-UID reference warnings; generated deferred |
| `000000013690` | `2026-07-16T09:31:24-04:00` | UID0001FF | completion/confidence/owner/emitter update; generated deferred |
| `000000013691` | `2026-07-16T09:32:20-04:00` | UID0001FG | completion/confidence/owner/emitter/formal update; 2 pre-existing missing-UID warnings; generated deferred |
| `000000013692` | `2026-07-16T09:33:04-04:00` | UID0001FH | prose/reference update; 61 pre-existing missing-UID warnings; generated deferred |
| `000000013693` | `2026-07-16T09:33:39-04:00` | UID0000EL | completion/confidence/reference update; 2 pre-existing missing-UID warnings; generated deferred |
| `000000013694` | `2026-07-16T09:34:22-04:00` | UID0000OL | confidence/reference update; 3 pre-existing missing-UID warnings; generated deferred |
| `000000013695` | `2026-07-16T09:35:17-04:00` | UID0003VQ | completion/confidence/reference update; 3 pre-existing missing-UID warnings; generated deferred |
| `000000013698` | `2026-07-16T09:35:52-04:00` | UID0003VR | completion/confidence plus validator-managed UID path/header registration; 2 pre-existing missing-UID warnings; generated deferred |
| `000000013703` | `2026-07-16T09:36:45-04:00` | UID00009H | completion/confidence/position/formal update; generated deferred |
| `000000013706` | `2026-07-16T09:37:33-04:00` | UID0000LZ | completion/confidence/reference update; generated deferred |
| `000000013711` | `2026-07-16T09:39:10-04:00` | UID0001FK | completion/confidence/formal update; generated deferred |
| `000000013714` | `2026-07-16T09:39:51-04:00` | UID0003GL | completion/confidence/formal update; generated deferred |
| `000000013716` | `2026-07-16T09:40:42-04:00` | UID0001FE `--wait-generated` | exit 0 / ok 1; generated refresh completed; global pre-existing `autogen_children_*` / no-code warnings reported outside target scope |

- B004's final waited validator was command `000000013716` at `2026-07-16T09:40:42-04:00`, exit 0 / ok 1. A later externally owned generated refresh produced the recorded evidence-time headers at command `000000013727` on `2026-07-16T09:50:07-04:00`; all 15 ordinary destination hashes remained stable. Unrelated later project validators may advance global generated headers.
- `MessageDialogs.cpp`: evidence-time command/header `000000013727`, SHA256 `30CF92B8FEF5FBD75DF627C34EA8EAE745AF70FD84DB7EADBC1059A2B21CE6AE`, 13,027 bytes / 402 lines. It has one Pursuit class, one UID0001FE constructor, one UID0001FF response, one each previous/next/current definition, zero Pursuit destructor declaration/definition, zero target stale/empty marker, and zero explicit vptr/RTTI/returned-this/scalar-delete/adjustor source.
- `NexonclubProxyDialog.cpp`: evidence-time command/header `000000013727`, SHA256 `FB6110CC4BC1442A426892D2B2CAF6D258794145491ED27802A3F6CB7E0B3F88`, 4,695 / 160. One class declaration precedes one callback and one constructor; UID00009H has no empty marker; there is no explicit proxy/Pursuit destructor, direct DialogPane initializer, inherited member initializer, state/page zero store, free current/close helper, vptr/RTTI/deleting-wrapper/adjustor source. The unrelated verify-only UID0003DE Empty Emitter Marker remains.
- `TextDialog.cpp`: evidence-time command/header `000000013727`, SHA256 `5B7B5A6E96DFD28B09E2B37C5B4CA22C87E6FB1597EBDC956D41BECA5927720A`, 668 / 11. It contains zero UID0001FG markers and zero previous/next/current definitions; only the accepted TextDialog class/constructor/action empty markers remain.
- No report validator, lifecycle command, report probe/count, execute command, move, or archive command was run.

## Changed Files

- Modified ordinary destinations and final SHA256:
  - UID0001FE `38CA29556755D44A4C8B98A8345F3AA80F948156350C5E9069A5B32D8981FA73`
  - UID0000BE `614D71C5A27D0DB6850F489D460BD6107266E5250B4355D2EDE21A8FA041B042`
  - UID0001YI `FCAC495584A7582B64236B9B2072A82F301DA095B01A0391E402A3D21D883E20`
  - UID0000LA `A3860E74F5DB88918806F9B2B58FF7B602C4209DCEF90859B76E54E6C89F32A7`
  - UID0001FF `6929F58AF933F445AD5ACF626A1F04C30D00DFC732C85E51E48A7529F404ABD5`
  - UID0001FG `F95EEABD5BE628B5AF13BEE0D210ABD6019EF34F44764281D7FF0F855C590954`
  - UID0001FH `EDA39F49D6AFD02CA2E31E67722CA321626DCDE4C3CB767776BC8F2A3799E89A`
  - UID0000EL `C4212EBC5D00AF03B164F04DED72292387E32BA0535E6B1738469602BA4235D2`
  - UID0000OL `EEE194AB2D17B1631A937C7ED04ED8208C930413C525BED12FD1102F3B88CD1B`
  - UID0003VQ `BB54EB45D45B02BF82B5D0B94DD01CBEF04E189A2F8FE5FBF9F3ABFD64E84A3D`
  - UID0003VR `4A45A72865FF665592DD87BEE1D5490ED7074ECB8ECF7542555DE882E32EA120`
  - UID00009H `710ABF4793D435E69AE1ABC94DA6D65D899B05B83A6D3B04BB0CDB0A053C10CD`
  - UID0000LZ `1FBFD4F707D4E05ED3CAB1DDA98AA92393538F28E0F8E262745A4C5A1BA8F93F`
  - UID0001FK `721CC2E661E58E918CBF1150BD456AB5468E0A2BC1D420D9DA23C4A4E43B86E4`
  - UID0003GL `0F71A228AAEC7F9F13F1EC09E5B0834D93A785E78C3D282A0293A46E13CC2D5C`
- Modified report: this same artifact only.
- Created/renamed: none.
- Verify-only unchanged: DialogPane class/file/aggregate, UID0002OM, and `by-memory/-ignored.md`.
- Manual coverage/generated/tracker/audit/supervisor/validator-state/IDA files were not manually edited.
- Report execution/lifecycle/move/archive: not run.
- Leases: each ordinary destination was leased only for its edit/validator window and released immediately; final shared lease report has zero B004 rows.

## Implementation Tracking Checklist

Initial report-only phase:

- [x] Supervisor validation required before implementation.
- [x] Reread UID0001FE immediately before callback edit and preserve concurrent content.
- [x] Apply UID0001FE `92/94`, owner/emitter UID0000BE, true, blank position, Nested 0.
- [x] Install Destination 1 exactly in UID0001FE.
- [x] Incorporate target range/hash/signature/base-call/vtable-store/inlining/liveness/compiler-boundary detail without compression.
- [x] Historicalize the old no-function/no-xref no-code conclusion while preserving its negative facts.
- [x] Reread UID0000BE and install Destination 2 exactly.
- [x] Apply UID0000BE `92/94` and preserve owner/emitter UID0000LA, position 10, and unrelated class content.
- [x] Remove the explicit `virtual ~PursuitMessageDialogPane();` declaration and record that the implicitly declared destructor is virtual through `DialogPane::~DialogPane()`.
- [x] Preserve `0x0049d9f0` as the source-owned ordinary DialogPane cleanup anchor and `0x00520b70` plus adjustors as compiler-only deleting-destructor evidence.
- [x] Record the shared `m_dialogType/m_dialogId/m_dialogState/m_dialogPageIndex` layout and six derived classes.
- [x] Reread UID0001FG and apply owner/emitter UID0000BE plus `92/94`.
- [x] Install Destination 3 exactly and preserve every helper range/caller/callee/padding/packet fact.
- [x] Reread UID0001FF, change owner/emitter to UID0000BE, apply `91/94`, and preserve Destination 4 exactly.
- [x] Reread UID0001YI, change owner/emitter to UID0000BE, apply `90/94`, and install Destination 5 exactly.
- [x] Preserve UID0002OM unchanged as verify-only class-owned generated-binary evidence.
- [x] Reread UID0000LA and apply the complete source-family/current-union update at `92/92`.
- [x] Reread UID0001FH, preserve `88/90` false/blank, and add only the inlined-base relationship.
- [x] Reread TextDialog class/file/constructor/action pages and apply the exact direct-base/inherited-field/helper corrections without filling their blank bodies.
- [x] Apply TextDialog bounded scores `88/92`, `89/90`, `88/92`, and `87/92` as listed.
- [x] Reread proxy class/file/constructor/callback pages and preserve all accepted B008 content.
- [x] Apply proxy bounded scores `91/94`, `89/93`, `92/94`, and `90/94`.
- [x] Set UID00009H source position `0` and install Destination 8 exactly before its child definitions.
- [x] Preserve exact anonymous-namespace direct Pursuit base, public constructor, private callback, no derived fields, implicitly declared virtual destructor through DialogPane, required include surface, and `[[CHILDREN]]`.
- [x] Install Destination 6 exactly in UID0001FK.
- [x] Verify Destination 6 has only the direct base initializer, inherited type/id body assignments in exact order, and state/page assignments only after parse success, with no unsupported zero initialization.
- [x] Install Destination 7 exactly in UID0003GL.
- [x] Verify Destination 7 legally calls protected `SendCurrentDialogPacket()` and public `CloseDialog()` through the completed class/base declarations.
- [x] Preserve anonymous-namespace, callback wrapper, ObjectStatusBlob, string conversion, packet layout, send length, and registration handoff evidence.
- [x] Verify DialogPane class/file/aggregate remain unchanged and still provide the exact base signature/layout.
- [x] Verify `by-memory/-ignored.md` padding rows remain unchanged.
- [x] Update every accepted Claim Ledger row to legal callback terminal state with destination proof.
- [x] Use one short lease per ordinary file immediately before editing; validate while leased; release immediately.
- [x] Run one scoped file validator for every changed ordinary by-* page and record command id/timestamp/exit/ok/warnings/side effects.
- [x] Run one final authorized waited target validation after all ordinary edits.
- [x] Verify generated MessageDialogs.cpp contains one class declaration, one UID0001FE constructor definition, one each of the three UID0001FG methods, one UID0001FF body, and zero target stale comment/Empty Emitter Marker.
- [x] Verify generated MessageDialogs.cpp contains zero explicit `PursuitMessageDialogPane` destructor declarations/definitions and no unresolved source destructor dependency.
- [x] Verify generated MessageDialogs.cpp has no explicit target vptr stores, RTTI/vtable arrays, constructor `return this`, scalar deleting wrapper, adjustor thunk, or duplicate bodies.
- [x] Verify generated NexonclubProxyDialog.cpp contains one anonymous class declaration before one constructor/one callback definition, corrected `PursuitMessageDialogPane()` initializer, exact inherited body assignments, `SendCurrentDialogPacket()`, and `CloseDialog()` calls.
- [x] Verify generated NexonclubProxyDialog.cpp has zero UID00009H Empty Emitter Markers, zero inherited member initializers, zero state/page zero stores, zero explicit proxy destructor declarations/definitions, and no old free helper/direct DialogPane initializer.
- [x] Verify TextDialog.cpp does not receive duplicate UID0001FG helper bodies.
- [x] Reread current manual coverage files and preserve/update exact supervisor-owned row text without editing them.
- [x] Confirm no new UID, split, rename, source file, IDA mutation, or padding change occurred.
- [x] Confirm all leases are released.

Implementation callback phase:

- [x] Exact report accepted by supervisor for implementation.
- [x] All accepted target/support details incorporated at report-level depth.
- [x] All eight formal destination blocks match exactly.
- [x] Destination 2 has no explicit Pursuit destructor declaration/definition, and generated readback confirms implicit-destructor source closure.
- [x] C1FE-001 through C1FE-046 have legal terminal verification states and claim-by-claim proof.
- [x] Metadata/score/owner/emitter changes applied exactly or excluded with exact reason.
- [x] Historical/rejected/negative evidence preserved.
- [x] Validators and generated readback recorded.
- [x] Exact changed-file hashes and lease releases recorded.
- [x] Manual coverage handoff re-read and recorded as supervisor-owned.
- [x] No implementation item remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000013754","destination_path":"executed-b-agent-research/B004/0001FE-PursuitMessageDialogPaneConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001FE-PursuitMessageDialogPaneConstructor-source-quality.md","timestamp":"2026-07-16T10:01:56-04:00","uid":"0001FE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
