** TARGET-REPORT-UID:0002Y7 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002Y7 TextButtonExControlPane Scalar Deleting Destructor Source Quality Research


## Finalized Report / Current Recommendation

- Current applied state: [UID:0002Y7] is semantic-owner compiler evidence at `COMPLETION:94`, `CONFIDENCE:97`, `CANONICAL_OWNER:0000EK`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank formal CPP, blank formal H, and `Nested:0`.
- Final disposition: `[0x0049b860,0x0049b8c7)` is an MSVC complete-object scalar deleting destructor wrapper generated from `TextButtonExControlPane`'s virtual destructor declaration and ordinary destructor. It is not an authored source method and must not emit a wrapper body or a comment as pseudo-source.
- Applied source action: [UID:0003NA] `[0x004955e0,0x00495615)` now emits the exact ordinary `TextButtonExControlPane::~TextButtonExControlPane()` source body containing only `delete m_labelTextBox;`; [UID:0000EK]'s H channel now contains the complete class declaration including `virtual ~TextButtonExControlPane();`.
- Applied support action: [UID:00001E]'s existing complete `ButtonControlPane` declaration moved byte-for-text from CPP to H; UID0000HY remains the source route; stale `ShowControl`/`HideControl` and `OnAttachToParent`/`OnDetachFromParent` terminology is historicalized in favor of inherited `Enable`/`Disable` and `AddToLayer`/`RemoveFromLayer`; UID0002Y6/UID0002Y7/vtable/RTTI support is explicitly compiler-only.
- Confidence: very strong for exact wrapper and ordinary-destructor bytes, boundaries, cleanup, hidden flags, object size, vtable/RTTI identity, owner, and source/compiler split; strong for the selected human field and private-helper spellings. Original private spelling is not recoverable from the binary, so the best source-consistent names are selected rather than retaining IDA labels.

## Supporting Research

- This report began as a report-only artifact. After supervisor Gate 1 passed exact SHA256 `7152D9D2FF7CEC8989F6B7A4BCBFA382719791DAD0710C3CA1E845BD9B68A0CA`, B004 applied the accepted ordinary-document callback under serial short-lived leases and scoped validators. B004 did not mutate IDA, edit manual coverage/generated/audit/catalog/lifecycle state directly, or run/probe `execute_report`.
- Live read-only IDA MCP session `5a570ede` was healthy during research: `status:ok`, active worker PID `15448`, `is_analyzing:false`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays ready, and required lookup/decompile/xref/byte/type/comment queries succeeded. `auto_analysis_ready:false` was treated only as context under the standing supervisor override because all bounded IDB-backed reads succeeded.
- Assignment-time target artifact: SHA256 `EAE28DA22D66CFB99B8AFCA1C0DDB8230880D65B641805CD7FFCD1C4CD0DF952`, 3,602 bytes, 51 lines. Historical callback-applied target artifact: SHA256 `7CC93BF0FCB032485A3E5E77C832BE88B085327EF7B3C80DE298B49A2B2BA7CD`, 9,281 bytes, 85 lines. Current post-IDA-reconciliation target artifact: SHA256 `FB8C3A9BA1FA7B638FBABC34B03273135599DD603ED7B14199051C7C124CD6B1`, 11,601 bytes, 98 lines.
- Historical pre-callback generated evidence was validator command `000000018341`: CPP SHA256 `64C2738537D378A0F779ADA858A98253149BD499B8088544A36A3923465298AD`, 9,051 bytes/278 lines; H SHA256 `8FA202B3976E28E697355A26B90DABDC9ECF87485597DF752742ED8C5853539A`, 862 bytes/28 lines. B004 callback command `000000018453` generated CPP SHA256 `6769A664A8D0BB87B0C542A99A4D191CA9CB1150577F5F1F7A35AA2D31AED9DA`, 7,724 bytes/234 lines, and H SHA256 `FDBEBD09AAC2C3AB34E237B397A3ECA5C350428766C7FA7067ECD4E6DEDA6861`, 3,478 bytes/128 lines. A later validator-owned deferred refresh, command `000000018462` at `2026-07-28T16:43:24-04:00`, changed only generated provenance while retaining the verified topology; at that dated implementation-time checkpoint CPP SHA256 was `035364FE4C456607991E4325F804FEB9733A691452A6FC915EA4033C7D0F4522`, 7,724 bytes/234 lines, and H SHA256 was `1C6EEBC8B84092F00B603B87A274D70F12250C4E9763C063D0EB538217587995`, 3,478 bytes/128 lines. Later supervisor/global validator refreshes may advance generated command metadata, header timestamps, and hashes; this report does not chase those later global identities. Final supervisor lifecycle-time generated readback/closure remains pending and will be authoritative.
- Historical B010 empty-emitter work and B001/B006 scalar-wrapper reports were used only as evidence leads. Their generic comment-marker treatment is superseded here by the newer reviewed RadioGroup ordinary-source/compiler-support split and the current instruction to eliminate comment-only pseudo-source.
- Historical Wave2/Wave3 mentions occur in broad class/file documentation. They were ignored as stale workflow labels; only current ordinary documentation, generated state, raw bytes, and live IDA MCP evidence informed this recommendation.

## Target

- Target UID: `0002Y7`.
- Additional target UIDs: none. Support pages are destinations, not additional report targets.
- Declared-target inventory: [UID:0002Y7] `by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md`, exact compiler deleting-wrapper evidence.
- Target path: `by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md`.
- Source queue/report row at assignment time: `auto-generated/-ag-research-tracker.md` `## by-memory` / `### Not-Covered Files - Reconstructable`, `87/89`, zero direct/additional reports.
- Current supervisor classification: ordinary-document callback is complete; supervisor Gate 2A commands `000000018683-000000018691` passed; Gate 2B is applied, saved, and reconciled; authoritative catalog entry 0348 is exactly `APPLIED_VERIFIED_RECONCILED`. The supervisor independently confirmed all nine modified ordinary-document hashes and both verify-only hashes exactly match this report. Only fresh supervisor gates on this repaired artifact, manual coverage, final generated closure, execute/archive, and registry/tracker confirmation remain pending.
- Assignment-time scores and parent state: `87/89`, owner/emitter [UID:0000EK], `RECONSTRUCTABLE:TRUE`, blank position/H, CPP containing only a prose warning not to author the wrapper, and stale `Nested:8`.

## Current Target State

- Current target metadata is `94/97`, owner `0000EK`, FALSE, blank emitter/position/CPP/H, populated exact Item Summary, and `Nested:0`; scoped validator command `000000018431` exited `0` with `ok:1` and recorded the TRUE-to-FALSE/non-emitting transition.
- Current source-bearing state is UID0003NA `95/97`, owner/emitter `0000EK`, TRUE, position `20`, exact destructor CPP, blank H; UID0000EK `94/96`, owner/emitter `0000HY`, TRUE, position `20`, blank CPP, complete H with one source marker. Validators `000000018438` and `000000018442` both exited `0` with `ok:1`.
- Current name/source contract uses `SetVisualState`, `Enable`/`Disable`, and `AddToLayer`/`RemoveFromLayer`; stale state/show/hide/attach/detach labels remain only in explicit historical discussion.
- All assignment-time score blockers were actively investigated and resolved: raw-body liveness, wrapper flags, one-byte helper role, exact object size, class declaration shape, field type/name, source file, owner/emitter semantics, vtable/RTTI route, adjustor route, and formal CPP/H placement.
- Related docs checked: UID0000EK, UID0000HY, UID0003NA, UID0002Y6, UID00011Y, UID000118, UID000252, UID00001E, UID000038, UID0003NC, sibling UID0002YE, RadioGroup UID0002YB/UID0002YC/UID0004X2/UID0000BI, current manual coverage rows, generated CPP/H, and historical B001/B006/B010 reports.
- Current artifact/lifecycle status: exact pre-callback Gate 1, accepted ordinary callback, original serial validators, dated generated checkpoints, supervisor Gate 2A commands `000000018683-000000018691`, supervisor Gate 2B, IDB save, catalog entry 0348 state `APPLIED_VERIFIED_RECONCILED`, B004 post-IDA ordinary-doc reconciliation, serial no-generated-refresh validators `000000018698-000000018706`, and independent exact-hash verification of all eleven ordinary/verify-only artifacts are complete. Only fresh supervisor gates on this repaired artifact, manual coverage, final generated closure, execute/archive, and registry/tracker confirmation remain pending.

## Executive Recommendation

- Applied: semantic class owner [UID:0000EK] is retained because the primary vtable, two adjusted views, constructor, ordinary teardown, member cleanup, and RTTI all identify `TextButtonExControlPane`.
- Applied: the exact wrapper is `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS`; semantic ownership does not make compiler ABI machinery authored source.
- Applied: UID0003NA emits `TextButtonExControlPane::~TextButtonExControlPane() { delete m_labelTextBox; }`, and UID0000EK emits the complete class declaration only in H.
- Applied: UID0000HY remains the `NexusTK/ui/controls/ButtonControlPane.cpp/.h` source route; no speculative narrower file was created.
- Applied: UID0002Y6 remains no-owner/FALSE/non-emitting at `93/96`, with exact bytes/xrefs/flags/compiler evidence and blank formals.
- Applied: UID00011Y/UID000118/UID000252 remain non-emitting indexes and now carry the exact TextButtonEx source/compiler split and full 26/11/2 vtable mapping without duplicate source.

## Supervisor Active Recheck

- The current supervisor instruction explicitly requires resolving the wrapper/compiler-generation/source-route/metadata/formal CPP/H and score blockers and forbids preserving contradictory TRUE/emitting plus comment-only pseudo-source.
- No split creation is required: exact wrapper UID0002Y7, exact adjustor UID0002Y6, and exact ordinary destructor UID0003NA already exist with closed half-open ranges.
- The source-bearing child that was incomplete is UID0003NA; this report supplies its exact destructor source and class/header route.
- The only binary-only support pages are UID0002Y6, UID0002Y7, and the UID000252 vtable/RTTI island. They receive explicit non-emitting dispositions, not deferred questions.

## Inference Research Guidance Check

- `by-structure.md` requires source-authored items to emit source, compiler-generated items to stay out of handwritten source, and declarations to live in H independently of CPP definitions. Those rules select UID0003NA CPP plus UID0000EK H, not UID0002Y7 wrapper source.
- The structure rules permit exact covered-by markers in some TRUE pages, but that mechanism is unnecessary and misleading here because the exact ordinary source child exists and the reviewed RadioGroup precedent classifies the complete-object deleting wrapper FALSE/non-emitting. The current supervisor assignment also rejects comment-only pseudo-source.
- Existing documentation assumptions were treated as uncertain: `ShowControl`, `HideControl`, `OnAttachToParent`, `OnDetachFromParent`, broad declaration withholding, TRUE wrapper coverage, and the generic source-file split were all rechecked.
- Direct IDA facts are ranges, bytes, xrefs, vtable cells, prototypes/comments, decompilation, stack-frame width, RTTI names, and type presence. Documentation evidence supplies established class/member/subsystem context. Inference selects human source names/access/source shape from those facts and consistent project style.
- Wave2/Wave3 labels were found only in historical prose and ignored.

## Heuristic / Inference Reanalysis And Validation

- Wrapper role: exact hidden `flags`, return-`this`, three vptr stores, optional operator delete, and the bit-4 object-size/no-op branch are MSVC destructor lowering. Best classification: compiler-generated complete-object deleting wrapper, not source-authored.
- Ordinary body: `[0x004955e0,0x00495615)` repeats only derived cleanup and then tail-chains Pane teardown. Best source reconstruction: `delete m_labelTextBox;`; vptr writes, virtual deleting dispatch, and base destructor call are compiler lowering.
- Field type/name: constructor allocates `0x174` bytes, calls the documented TextBoxPane constructor, stores the result at `+0x10c`, and later text/layer/state methods consume it. `TextBoxPane *m_labelTextBox` is the strongest human spelling. `m_textBoxPane` is weaker because the field's class-specific role is the button label.
- Object size: ButtonControlPane occupies `0x10c`; one pointer at `+0x10c` closes TextButtonEx at `0x110`. The wrapper independently pushes `0x110` on its bit-4 path.
- Method names: vtable offset `+0x48` inherits `ControlPane::SetVisualState`; `+0x4c/+0x50` inherit `Enable/Disable`; primary `+0x30/+0x38/+0x44` are `AddToLayer/RemoveFromLayer/OnPaint`. Old Show/Hide and attach/detach labels are descriptive history, not the best source names.
- Constructor shape: live decompile has exactly two source arguments after `this`: wide label text and a bounds pointer/reference. Current ButtonControlPane source style supports `TextButtonExControlPane(const wchar_t *text, const RectBounds &bounds)`.
- Vtable facets: base ButtonControlPane already carries primary, `+0xa0`, and `+0xa4` interface views. No additional source inheritance is added to TextButtonEx; the derived class inherits those facets through ButtonControlPane.
- File route: dense address adjacency and existing by-file ownership support ButtonControlPane.cpp/.h. A separate TextButtonEx source file is possible historically but has no positive symbol/section/build evidence, so current route is retained.
- Raw liveness: zero xrefs and zero VA/RVA/raw-offset pointer hits do not make UID0003NA padding. Unique coherent class teardown, exact vtable triplet, constructor pairing, wrapper cleanup prefix, and closed padding prove retained source.
- Guard/no-op helper: `0x0041b6a0` is exactly one `ret`, is shared broadly by deleting wrappers, and already carries a correction stating it is not sized delete, vector delete, guarded delete, or a deallocator. The `0x110` path therefore performs no storage release.
- Rejected alternative: retain target TRUE with a covered-by marker. This leaves a compiler body in the reconstructable queue despite exact ordinary source existing and conflicts with the newer reviewed family split.
- Rejected alternative: handwritten scalar wrapper. It would expose hidden flags, vptr assignments, base calls, adjusted entries, and project delete mechanics that the original developer did not write.
- Rejected alternative: blank ordinary destructor. It is the source-bearing item that resolves the wrapper cause and score blocker.
- Rejected alternative: no-owner wrapper. The exact binary has unambiguous semantic class ownership even though it is non-emitting.
- Rejected alternative: `ShowControl`/`HideControl` or `OnAttachToParent`/`OnDetachFromParent` in finalized declarations. Slot inheritance and behavior favor canonical base names.
- Rejected alternative: preserve raw names `sub_49B860`, `sub_495450`, `_DWORD *Block`, `char a2`, and raw offsets in source. Descriptive source/IDA names below are better supported.

## Evidence Standards Used

- Live IDA MCP: `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `stack_frame`, `get_bytes`, `get_comments`, `xrefs_to`, `entity_query`, `type_inspect`, `find_bytes`, and `make_signature_for_range`.
- Binary evidence: exact bytes/hashes, closed padding, function sizes, stack argument width, direct refs, vtable stores/cells, RTTI decorated names, constructor/destructor pairing, and one-byte helper behavior.
- Documentation evidence: current class/file/memory/read-only-data pages, structure rules, generated CPP/H, manual coverage, tracker row, and reviewed sibling ordinary-source/compiler-wrapper precedents.
- Negative evidence: no ordinary wrapper callers, no raw ordinary-destructor xrefs, no VA/RVA/raw-offset pointer hits, no proposed-name collisions, no current TextButtonEx/ButtonControlPane/TextBoxPane IDA types, and no evidence for a narrower physical file.
- Evidence ladder: exact bytes/xrefs/vtables outrank decompiler names; consistent constructor/member/destructor behavior outranks missing raw-helper xrefs; human names are selected only after behavior and project naming conventions converge.

## Evidence Checked

- IDA MCP/manual checks: healthy session; target/adjustor/constructor/base/delete/no-op lookups; target and all class method decompiles; exact bytes for wrapper, ordinary body, adjustors, boundaries, and vtable island; xrefs to wrapper/adjustors/raw start/vtables/no-op helper; type presence; comments; stack frames; proposed-name collisions; raw-start pointer patterns; unique raw-body signature.
- by-* and generated checks: target, class, file, raw destructor, adjustors, aggregate/core/read-only indexes, base classes, label helpers, sibling wrapper/source splits, generated ButtonControlPane CPP/H, research tracker, and three manual coverage reports.
- Negative checks: raw start xrefs zero; patterns `E0 55 49 00`, `E0 55 09 00`, and `E0 49 09 00` each returned zero; proposed five IDA names each returned `total:0`; target has no ordinary callers; wrapper reachability is only two adjusted jumps and one primary vtable cell.
- Initial report-only research intentionally skipped validators and generated refresh. After exact-artifact Gate 1 acceptance, B004 ran only the authorized serial scoped ordinary-document validators and final validator-owned generated refresh recorded below. B004 performed no write-capable IDA operation or save, no coverage edit, no lifecycle command, and no `execute_report` probe or execution.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2Y7-001 | 0002Y7 | Exact wrapper is `[0x0049b860,0x0049b8c7)`, 103 bytes, SHA256 `DF9417C218C9788041FAC2CCBB45368797637A11FD0D9FDA11B84787F20AE536`. | exact | live bytes/function | target exact range/evidence | incorporated | implemented/read back; target SHA `7CC93B...BA7CD`, validator 18431 ok1 |
| C2Y7-002 | 0002Y7 | Pre-padding `[0x0049b854,0x0049b860)` is 12 CC bytes; post-padding `[0x0049b8c7,0x0049b8d0)` is 9 CC bytes, SHA256 `57C1...51CE`. | exact | bytes/neighbor functions | target boundary section | incorporated | implemented/read back; validator 18431 ok1 |
| C2Y7-003 | 0002Y7 | Wrapper reachability is exactly `0x49b077`, `0x49b082`, and primary vtable cell `0x617d24`; no normal caller exists. | exact | xrefs/analyze | target xref section | incorporated | implemented/read back; validator 18431 ok1 |
| C2Y7-004 | 0002Y7 | Wrapper restores vptrs `0x617d24/0x617d90/0x617dc0`, deletes child `+0x10c`, invokes Pane teardown, and dispatches hidden bits 1/4. | exact | asm/decompile/bytes | target behavior | incorporated | implemented/read back; validator 18431 ok1 |
| C2Y7-005 | 0002Y7 | Bit-4 branch passes size `0x110` to one-byte no-op `0x41b6a0`; it is not a deallocator. | exact | asm/helper body/comment/fanout | target compiler boundary | corrected/incorporated | implemented/read back; validator 18431 ok1 |
| C2Y7-006 | 0002Y7 | Target is compiler-generated, semantic-owner class evidence; FALSE/non-emitting/blank formals is the correct source disposition. | very strong | source/compiler comparison | target metadata/formals | reclassified | implemented/read back; validator 18431 records TRUE -> FALSE and emitter removal |
| C2Y7-007 | 0002Y7 | Item Summary must state exact source/compiler split; `Nested` must be `0`. | exact | exact child page | target metadata | replaced | implemented/read back; validator 18431 ok1 |
| C2Y7-008 | 0003NA | Exact ordinary body is `[0x004955e0,0x00495615)`, 53 bytes, SHA256 `79C8CC6513105F1AC4BD4DBAD650CF17FB1ED9CA7EC22825358AFFA4F245DF9C`. | exact | live bytes/signature | raw destructor | incorporated | implemented/read back; SHA `3D08B1...E335E`, validator 18438 ok1 |
| C2Y7-009 | 0003NA | Ordinary body is source-authored `~TextButtonExControlPane`; source body is only `delete m_labelTextBox;`. | very strong | cleanup equivalence/source lowering | raw CPP/status | populated | implemented/read back; validator 18438 ok1 |
| C2Y7-010 | 0003NA | Historical pre-Gate2B raw start had no function/name/xref/pointer hit but was retained unique class teardown, not padding; Gate 2B now models the exact destructor without changing zero-xref/pointer state. | exact/very strong | lookup/entity/xref/find/signature plus catalog 0348 readback | raw negative evidence/current IDA state | incorporated/reconciled | exact `TextButtonExControlPane__Destructor` `[0x4955e0,0x495615)`; authoritative `__return_address +0x4`, auto local `void (__thiscall ***v2)(_DWORD)`; validator 18699 ok1 |
| C2Y7-011 | 0003NA | Recommend `95/97`, owner/emitter 0000EK, TRUE, position `20`, exact CPP, blank H, Nested 0. | strong | complete source route | raw metadata/formals | applied | implemented/read back; validator 18438 ok1 |
| C2Y7-012 | 0000EK | Complete object is `0x110`: ButtonControlPane `0x10c` plus `TextBoxPane *m_labelTextBox` at `+0x10c`. | very strong | constructor/wrapper/base docs | class layout | incorporated | implemented/read back; SHA `6D4737...03ACF`, validator 18442 ok1 |
| C2Y7-013 | 0000EK | Complete declaration belongs in H and includes virtual destructor, exact inherited overrides, helpers, and one pointer field. | strong | vtable/method/decompile/source style | class H | applied | implemented/read back; validator 18442 ok1 |
| C2Y7-014 | 0000EK | Correct source names are `SetVisualState`, `Enable`, `Disable`, `AddToLayer`, `RemoveFromLayer`, `OnPaint`, `GetText`, and `CalculateLabelRect`. | strong | slot inheritance/behavior | class method table/H | corrected | implemented/read back; validator 18442 ok1 |
| C2Y7-015 | 0000EK | Recommend `94/96`, owner/emitter 0000HY, TRUE, position `20`, blank CPP, complete H. | strong | resolved class contract | class metadata | applied | implemented/read back; validator 18442 ok1 |
| C2Y7-016 | 00001E | Existing complete ButtonControlPane declaration is header source and must move unchanged from CPP to H. | exact channel correction | current formal/by-structure | base class formals | moved byte-for-text | implemented/read back; SHA `709A1D...FA3C`, validator 18443 ok1 |
| C2Y7-017 | 0002Y6 | Two 11-byte thunks subtract `0xa0/0xa4`, only vtable-referenced, and remain NONE/FALSE/non-emitting. | exact | bytes/xrefs | adjustor page | expanded/rescored 93/96 | implemented/read back; SHA `A6CD2E...A3D9`, validator 18444 ok1 |
| C2Y7-018 | 00011Y | Aggregate remains FALSE/no-owner; row must record TextButtonEx ordinary source plus compiler support. | strong | exact children | destructor aggregate | incorporated | implemented/read back; SHA `3EF5EF...95D0`, validator 18446 ok1 |
| C2Y7-019 | 000118 | Core remains FALSE/no-owner; TextButtonEx entry must state exact ordinary/source and compiler split. | strong | exact children | core inventory | incorporated | implemented/read back; SHA `4DF8F3...8108`, validator 18447 ok1 |
| C2Y7-020 | 000252 | Exact TextButtonEx read-only island is `[0x617d20,0x617dc8)`, 168 bytes, SHA256 `E2D7...C4E7C`, with 26/11/2 slots. | exact | bytes/names/slot map | read-only-data index | incorporated with full maps | implemented/read back; SHA `A53FE4...5408`, validator 18451 ok1 |
| C2Y7-021 | 0000HY | Current source root remains ButtonControlPane.cpp/.h; add TextButtonEx class/ordinary/compiler split and raise to 91/93. | strong | neighborhood/current route | by-file | applied | implemented/read back at callback SHA `FA57AC...5E68`, validators 18445/18453 ok1; later current artifact SHA `AF4DB0...1646` preserves the complete accepted TextButtonEx section while adding unrelated concurrent support detail |
| C2Y7-022 | 0002Y7 | Current generated comments must disappear; target must have zero generated source/empty marker after FALSE reclassification. | exact expected topology | current autogen/rules | generated verification | validator-owned refresh/readback | callback command 18453 and later dated implementation-time checkpoint 18462 both had zero UID0002Y7 source and zero target empty markers; final supervisor lifecycle-time generated readback/closure remains pending and will be authoritative |
| C2Y7-023 | 0000EK/0003NA | Generated H must contain one TextButtonEx declaration and CPP one ordinary destructor plus two helper definitions, no raw wrapper. | strong expected topology | accepted formal plan | generated verification | validator-owned refresh/readback | callback 18453 and later dated implementation-time checkpoint 18462: H class 1; CPP destructor 1/helpers 2; no TextButtonEx ABI wrapper; final supervisor lifecycle-time generated readback/closure remains pending and will be authoritative |
| C2Y7-024 | 0002Y7 family | Gate 2B handoff includes exact historical prestates, collision checks, safe types/comments, raw function creation, and protected compiler/data boundaries. | exact | live IDA reads plus authoritative catalog entry 0348 | supervisor IDA | applied/read back/saved/reconciled | complete under exact catalog state `APPLIED_VERIFIED_RECONCILED`: incomplete class type; five exact functions/names/signatures/function-repeatable comments; raw exact range; three stale comments cleared; automatic frame entries; bounded raw frame/local normalization; protected state unchanged; IDB SHA `408F7392...61A7` |
| C2Y7-025 | coverage | Manual memory/class/file rows are absent or stale and require exact supervisor-owned replacements below. | exact | current manual reports | coverage reports | supervisor edit | supervisor pending |

## Positive Evidence Summary

- Wrapper function object is exact: applied name `TextButtonExControlPane__ScalarDeletingDestructor`, `[0x49b860,0x49b8c7)`, size `0x67`, seven basic blocks, cyclomatic complexity three; historical pre-Gate2B name was `sub_49B860`.
- Three inbound routes are exactly the class's two adjusted deleting entries and primary vtable deleting slot.
- Wrapper and ordinary body install the same TextButtonEx vptr triplet and delete the same `+0x10c` child before Pane teardown.
- Constructor installs the same vptr triplet, allocates a `0x174` TextBoxPane, and stores it at `+0x10c`.
- Exact `0x110` size branch independently confirms the complete derived layout.
- Decorated RTTI/type/vtable names identify TextButtonExControlPane without relying on decompiler owner names.
- RadioGroup's already-reviewed split is byte/behavior-equivalent: class virtual declaration + ordinary source body generate adjusted/deleting compiler support, with semantic owner retained on the FALSE wrapper.

## IDA MCP Facts

- Target raw bytes: `55 8B EC 56 8B F1 8B 8E 0C 01 00 00 C7 06 24 7D 61 00 C7 86 A0 00 00 00 90 7D 61 00 C7 86 A4 00 00 00 C0 7D 61 00 85 C9 74 06 8B 01 6A 01 FF 10 8B CE E8 E9 8C 0A 00 8B 45 08 A8 01 74 22 A8 04 75 10 56 E8 18 92 05 00 83 C4 04 8B C6 5E 5D C2 04 00 68 10 01 00 00 56 E8 E3 FD F7 FF 83 C4 08 8B C6 5E 5D C2 04 00`.
- Historical pre-Gate2B target prototype was `Pane *__thiscall(Pane *Block, char)`. Applied signature is `TextButtonExControlPane *__thiscall TextButtonExControlPane__ScalarDeletingDestructor(TextButtonExControlPane *this, unsigned int flags)`, with automatic persistent `flags +0xc`; only low bits are tested, but the ABI stack argument is four bytes.
- Applied target comment state: address regular/repeatable and function regular absent; function repeatable contains the accepted exact compiler-role payload. Historical stale interior address-regular comments `0x49b863: int`, `0x49b890: this`, and `0x49b8a2: block` are now cleared.
- Ordinary bytes: `56 8B F1 8B 8E 0C 01 00 00 C7 06 24 7D 61 00 C7 86 A0 00 00 00 90 7D 61 00 C7 86 A4 00 00 00 C0 7D 61 00 85 C9 74 06 8B 01 6A 01 FF 10 8B CE 5E E9 6B EF 0A 00`.
- Ordinary pre-fence `[0x4955dc,0x4955e0)` is four CC bytes, SHA256 `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`; post-fence `[0x495615,0x495620)` is eleven CC bytes, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- Historical pre-Gate2B ordinary start was not a function and had no persistent name, address comments, xrefs, or VA/RVA/raw-offset pointer pattern. It is now exact function `TextButtonExControlPane__Destructor` `[0x4955e0,0x495615)` with accepted signature/function-repeatable comment, while zero xrefs/pointer hits and the unique wildcarded signature remain unchanged.
- Adjustor bytes are `81 E9 A0 00 00 00 E9 E4 07 00 00` and `81 E9 A4 00 00 00 E9 D9 07 00 00`; each is 11 bytes and only referenced by its vtable cell.
- Vtable island `[0x617d20,0x617dc8)` has primary COL pointer then 26 entries `[0x617d24,0x617d8c)`, secondary COL then 11 entries `[0x617d90,0x617dbc)`, and tertiary COL then two entries `[0x617dc0,0x617dc8)`.
- Primary deleting slot `0x617d24 -> 0x49b860`; secondary `0x617d90 -> 0x49b071`; tertiary `0x617dc0 -> 0x49b07c`.
- Relevant decorated data names: `??_R4TextButtonExControlPane@@6B@` `0x645a0c`, `??_R3TextButtonExControlPane@@8` `0x645a20`, `??_R2TextButtonExControlPane@@8` `0x645a30`, `??_R1A@?0A@EA@TextButtonExControlPane@@8` `0x645a54`, secondary/tertiary COLs `0x645a70/0x645a84`, and type descriptor `??_R0?AVTextButtonExControlPane@@@8` `0x6757ac`.
- `type_inspect`: `TextButtonExControlPane`, `ButtonControlPane`, and `TextBoxPane` absent; `Pane` exists as size `0xf8`; `RectBounds` exists as size `0x10` with four `int` members at `0/4/8/c`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Recommended Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x00495450,0x004955dc)` | UID000118 index / UID0000EK class | source constructor | true through class | 0000EK | class `94/96` | exact modeled function, one caller |
| `[0x004955dc,0x004955e0)` | ignored padding | alignment | false | none | n/a | four CC bytes |
| `[0x004955e0,0x00495615)` | UID0003NA | authored ordinary destructor | true | 0000EK | `95/97` | exact CPP required |
| `[0x00495615,0x00495620)` | ignored padding | alignment | false | none | n/a | eleven CC bytes |
| `[0x00495620,0x00495a95)` | UID000118 index / UID0000EK class | source virtual methods | true through class | 0000EK | class `94/96` | exact modeled functions |
| `[0x00495aa0,0x00495be3)` | UID0003NC | retained private label helpers | true | 0000EK | keep `88/89` | existing draft CPP, no direct route |
| `[0x0049b071,0x0049b087)` | UID0002Y6 | compiler adjusted entries | false | none | `93/96` | blank source |
| `[0x0049b854,0x0049b860)` | ignored padding | alignment | false | none | n/a | twelve CC bytes |
| `[0x0049b860,0x0049b8c7)` | UID0002Y7 | compiler complete-object deleting wrapper | false | semantic 0000EK | `94/97` | target, blank source |
| `[0x0049b8c7,0x0049b8d0)` | ignored padding | alignment | false | none | n/a | nine CC bytes |
| `[0x00617d20,0x00617dc8)` | UID000252 index | compiler RTTI/vtable island | false | none | keep index `86/93` | 26/11/2 topology |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x49b860` | code `0x49b077` in `TextButtonExControlPane__ScalarDeletingDestructorAdjustorA0` | `this-0xa0` adjusted deleting entry |
| `0x49b860` | code `0x49b082` in `TextButtonExControlPane__ScalarDeletingDestructorAdjustorA4` | `this-0xa4` adjusted deleting entry |
| `0x49b860` | data `0x617d24` | primary TextButtonEx deleting slot |
| `0x49b071` | data `0x617d90` only | secondary deleting slot, no normal caller |
| `0x49b07c` | data `0x617dc0` only | tertiary deleting slot, no normal caller |
| `0x4955e0` | no xrefs | retained ordinary body, not live direct-call proof |
| `0x617d24` | stores/refs `0x4954dc`, `0x4955e9`, `0x49b86c` | constructor, ordinary destructor, wrapper identity |
| `0x617d90` | stores/refs `0x4954e2`, `0x4955ef`, `0x49b872` | same secondary identity |
| `0x617dc0` | stores/refs `0x4954ec`, `0x4955f9`, `0x49b87c` | same tertiary identity |
| `0x495450` | caller `0x518d9c` in `sub_517F30` | one live construction route; consumer does not own class source |
| `0x49b892` | callee `Pane__Destructor` `0x544580` | compiler base teardown |
| `0x49b8a3` | callee `NexusTK_operator_delete_wrapper` `0x4f4ac0` | normal storage-release branch |
| `0x49b8b8` | callee one-byte `0x41b6a0` | bit-4 no-op size path, not deallocation |

## Documentation Evidence And IDA Status

- Assignment-time supporting docs correctly identified the class, vtable triplet, `+0x10c` child, exact raw ordinary body, and adjustors, but their target/class source disposition was stale. UID0000EK's method table also retained stale inherited state/layer names, UID0003NA withheld source pending class design, UID0002Y6 was under-scored and lacked an Item Summary/current IDA handoff, and UID00011Y/UID000118/UID000252 lacked the complete ordinary-source/compiler-support split.
- The accepted callback corrected those ordinary-document defects. UID0002Y7 is now FALSE/non-emitting at `94/97`; UID0003NA emits the exact ordinary destructor at `95/97`; UID0000EK now emits the complete class declaration through H at `94/96`; UID0002Y6 is a fully documented `93/96` compiler adjustor pair; UID0000HY is `91/93`; and UID00011Y/UID000118/UID000252 carry the bounded source/compiler and complete 26/11/2 topology evidence without duplicate source.
- Historical generated command `000000018341` showed the pre-callback contradiction: class-withheld comments, two helper bodies requiring the missing declaration, target compiler-warning comments, and no TextButtonEx H declaration. B004 callback command `000000018453` corrected that topology; later validator-owned command `000000018462` is a dated implementation-time physical checkpoint that preserved one TextButtonEx class declaration in H, one ordinary destructor and two retained helper definitions in CPP, zero UID0002Y7 source or target empty markers, and no TextButtonEx ABI-wrapper source. Later supervisor/global refreshes may advance generated metadata/header hashes, so final supervisor lifecycle-time generated readback/closure remains pending and will be authoritative.
- Current ordinary artifacts and their scoped callback readbacks are recorded in C2Y7-001 through C2Y7-023 and `Validator Results`. The later current UID0000HY ordinary artifact and command-18462 dated implementation-time generated identities are distinguished from B004's historical callback hashes in `Supporting Research`, `Validator Results`, and `Changed Files`; command-18462 hashes are not asserted as final physical identities after subsequent global refreshes.
- B004 did not mutate IDA. Supervisor Gate 2B commands applied and verified the accepted IDA-Y7-T01/001-008 handoff; authoritative catalog entry 0348 is exactly `APPLIED_VERIFIED_RECONCILED` and records exact prestate/action/readback, protected-state preservation, and saved IDB SHA256 `408F73923C6BDD17931E828365DC0D7D67F583FE6F0FDDA50103F45FB84461A7`. This report and all nine affected ordinary docs reflect that applied state, and the supervisor independently confirmed all eleven ordinary/verify-only hashes match the report.
- Manual coverage remains supervisor-owned and pending: memory rows for UID0003NA/UID0002Y6/UID0002Y7 and replacements for UID00011Y/UID000252, plus current class/file replacements for UID0000EK/UID0000HY, are supplied verbatim below but were not edited by B004.

## Ranked Ownership Analysis

### 1. TextButtonExControlPane semantic owner with separate source/compiler children

- Evidence for: exact decorated RTTI/vtables, constructor and both destructor forms share all three vptrs, child field and cleanup agree, object size agrees, and adjusted routes use inherited facets.
- Evidence against: no original source symbol proves private names or physical filename.
- Decision: accepted. UID0000EK owns source declaration/ordinary source route; UID0002Y7 retains semantic owner only and emits nothing.

### 2. ButtonControlPane or ButtonControlPane.cpp as direct wrapper owner

- Evidence for: TextButtonEx derives from ButtonControlPane and current physical source route is UID0000HY.
- Evidence against: wrapper installs derived vptrs and deletes a derived-only child. File/module ownership is not direct method ownership.
- Decision: rejected as target owner; accepted only as transitive source root.

### 3. No owner or broad destructor aggregate

- Evidence for: compiler glue often has no source owner; aggregate indexes the address band.
- Evidence against: exact class identity is unambiguous and current project precedent retains semantic class owner on class-specific compiler wrappers.
- Decision: rejected. Keep `CANONICAL_OWNER:0000EK`, but remove emitter/reconstructable state.

### Proposed new file/grouping, if applicable

- No new file is justified. Retain `NexusTK/ui/controls/ButtonControlPane.cpp` and `.h` under UID0000HY.
- Likely full TextButtonEx source contents are the class declaration, constructor, ordinary destructor, state/enable/disable/layer/paint/text methods, and private label-bound helpers.
- Compiler wrapper, adjustors, vtables, RTTI, hidden flags, and alignment are excluded from authored files.

## Source Placement

- Recommended placement: `TextButtonExControlPane` declaration in `NexusTK/ui/controls/ButtonControlPane.h`; ordinary destructor and method/helper definitions in `ButtonControlPane.cpp`.
- Current dense source neighborhood and by-file ownership support the route. It also places ButtonControlPane before derived TextButtonEx in H.
- A standalone `TextButtonExControlPane.cpp` or historical combined TextButton file is plausible but unsupported; retaining current broad route avoids speculative movement.
- UID0002Y7 has no source placement because it is compiler output. Its documentation remains under by-memory only.

## Range / Split / Padding / Reclassification Analysis

- Wrapper range is closed and requires no split: exact modeled `[0x49b860,0x49b8c7)`.
- Preceding 12-byte and following 9-byte CC runs remain ignored alignment and are not absorbed.
- Ordinary range is closed by four CC bytes before and eleven CC bytes after. Creating an IDA function must use exact `[0x4955e0,0x495615)` and must not consume either fence.
- Adjustor range remains two exact 11-byte functions with no padding inside.
- Vtable island ends at `0x617dc8`; `0x617dc8` is the next class's COL pointer and must be protected.
- Target reclassification TRUE to FALSE removes generated pseudo-source without losing binary documentation. No page deletion or merge is recommended.
- Target `Nested:8` is stale because the exact page has no nested children. Recommend `Nested:0`.

## Negative Evidence Summary

- No normal caller reaches the wrapper; only vtable/thunk routes do.
- No xref or encoded VA/RVA/raw pointer reaches the ordinary start.
- No original symbols prove `m_labelTextBox`, `CalculateLabelRect`, or the physical source filename.
- No evidence makes the one-byte helper a storage deallocator; its body is only `ret`.
- No evidence supports hand-authored hidden flags, explicit vptr writes, direct Pane destructor calls, raw virtual delete dispatch, or manual `operator delete` in source.
- No proposed IDA name currently collides.
- No evidence supports extra inheritance beyond the facets already present in ButtonControlPane.
- These negatives do not block the chosen direction: they distinguish compiler lowering from authored source and cap only original-spelling/file certainty.

## IDA Rename / Type / Comment Recommendations

The following section preserves the exact historical pre-Gate2B handoff and records the authoritative applied result. B004 did not mutate IDA. Supervisor Gate 2B commands `000000018683-000000018691` passed, and catalog entry 0348 exact state `APPLIED_VERIFIED_RECONCILED` is authoritative for action/readback/save/reconciliation disposition.

Historical read-only MCP recheck used healthy session `5a570ede`: `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x400000`, `hexrays_ready:true`, and every bounded `lookup_funcs`, `inspect_items`, `stack_frame`, `analyze_function`, `decompile`, `insn_query`, and `get_comments` request below succeeded. The prestate MCP `stack_frame` result had no frame-member comment properties; each listed historical persistent member therefore had exact stack-member regular `absent` and repeatable `absent` state. Hex-Rays output likewise contained no local-user comments for the listed receiver, parameters, or locals. Register-location annotations such as `// ecx`, `// si`, `// eax`, and `// edx` were Hex-Rays auto-location annotations, not local-user comments.

Authoritative applied state:

- Added only incomplete pointer-only `TextButtonExControlPane`; no guessed members or source inheritance were encoded in IDA.
- Applied five exact function identities, signatures, and function-repeatable comments: constructor, ordinary destructor, complete-object scalar deleting wrapper, and both deleting-destructor adjustors. Address-regular/address-repeatable/function-regular channels remain blank at all five starts.
- Exact raw function is `[0x004955e0,0x00495615)`. Its sole authoritative frame entry is `__return_address +0x4`, not predicted `+0x0`; its authoritative auto local is `void (__thiscall ***v2)(_DWORD)`, not the predicted two-argument form. This bounded normalization is observed poststate and was not coerced.
- Signature application automatically materialized constructor `text +0x50` and `bounds +0x54`, wrapper `flags +0xc`, and adjustor `flags +0x4` entries. No manual `declare_stack` or unsafe duplicate-frame operation was used.
- Cleared only stale address-regular comments at `0x0049b863`, `0x0049b890`, and `0x0049b8a2`. Exact bytes, function/range/fence boundaries, successor, xrefs, UDTs, dependency names/types/comments, vtable/RTTI identities/comments, and unrelated entities are unchanged.
- `idb_save` succeeded. Persisted IDB SHA256 is `408F73923C6BDD17931E828365DC0D7D67F583FE6F0FDDA50103F45FB84461A7`, 143,189,897 bytes, saved `2026-07-29T01:35:34.0191420-04:00`.

**IDA-Y7-001 historical literal frame and Hex-Rays prestate**

- Historical pre-Gate2B function was exactly `[0x49b860,0x49b8c7)`, size `0x67`, name `sub_49B860`, prototype `Pane *__thiscall(Pane *Block, char)`, with address-regular, address-repeatable, function-regular, and function-repeatable comments all absent.
- Persistent frame members are exactly: `__saved_registers`, frame offset `+0x4`, size/extent `0x4` / `[+0x4,+0x8)`, type `_DWORD`; `__return_address`, `+0x8`, `0x4` / `[+0x8,+0xc)`, type `_UNKNOWN *`; and `arg_0`, `+0xc`, `0x4` / `[+0xc,+0x10)`, type `_DWORD`. Each member has regular/repeatable stack-member comments absent.
- Current Hex-Rays receiver is `Block`, type `Pane *`, width `0x4`, register `ECX`, no stack offset/extent, local-user comment absent. Current explicit parameter is `a2`, type `char`, logical width `0x1`, backed by the low byte of persistent four-byte frame member `arg_0` at `+0xc/[+0xc,+0x10)`, local-user comment absent. Current sole local is `v3`, type `void (__thiscall ***)(_DWORD, int)`, width `0x4`, register `ECX`, no stack offset/extent, local-user comment absent.
- Historical predicted post-action target: receiver `this`, type `TextButtonExControlPane *`, width `0x4`, `ECX`, no stack extent; parameter `flags`, type `unsigned int`, width `0x4`, persistent frame member `flags` at `+0xc/[+0xc,+0x10)`; local `v3` unchanged at `void (__thiscall ***)(_DWORD, int)`, width `0x4`, `ECX`. `__saved_registers` and `__return_address` were to remain byte-for-byte as above. Authoritative readback matched this target and is recorded in IDA-Y7-001.

**IDA-Y7-003 historical literal frame and Hex-Rays prestate**

- Historical pre-Gate2B constructor was exactly `[0x495450,0x4955dc)`, size `0x18c`, name `sub_495450`, prototype `int __thiscall(int this, const unsigned __int16 *, int *)`, with all four function-start comment channels absent.
- Persistent frame members are exactly: `var_38` `+0x10`, size `0x4`, extent `[+0x10,+0x14)`, type `_DWORD *`; `Block` `+0x14`, `0x4`, `[+0x14,+0x18)`, type `void *`; `secondBounds` `+0x18`, `0x10`, `[+0x18,+0x28)`, type `struct RectBounds`; `outBounds` `+0x28`, `0x10`, `[+0x28,+0x38)`, type `RectBounds`; `var_10` `+0x38`, `0x4`, `[+0x38,+0x3c)`, type `_DWORD`; `var_C` `+0x3c`, `0x4`, `[+0x3c,+0x40)`, type `_DWORD`; `var_4` `+0x44`, `0x4`, `[+0x44,+0x48)`, type `_DWORD`; `__saved_registers` `+0x48`, `0x4`, `[+0x48,+0x4c)`, type `_DWORD`; `__return_address` `+0x4c`, `0x4`, `[+0x4c,+0x50)`, type `_UNKNOWN *`; `arg_0` `+0x50`, `0x4`, `[+0x50,+0x54)`, type `_DWORD`; and `arg_4` `+0x54`, `0x4`, `[+0x54,+0x58)`, type `_DWORD`. Each listed persistent member has stack-member regular/repeatable comments absent; `[+0x40,+0x44)` is an unnamed gap and not a modeled member.
- Current Hex-Rays receiver/parameters are: receiver `this`, type `int`, width `0x4`, `ECX`, no stack extent; `a2`, type `const unsigned __int16 *`, width `0x4`, backed by `arg_0 +0x50/[+0x50,+0x54)`; and `a3`, type `int *`, width `0x4`, backed by `arg_4 +0x54/[+0x54,+0x58)`. Their local-user comments are absent.
- Current Hex-Rays locals are exactly: `v4`, `__int16`, width `0x2`, register `SI`; `v5`, `void *`, width `0x4`, register `ECX`; `v6`, `int *`, width `0x4`, register `EAX`; `v7`, `int`, width `0x4`, register `EDX`; `secondBounds`, `struct RectBounds`, width `0x10`, persistent extent `[+0x18,+0x28)`; `outBounds`, `RectBounds`, width `0x10`, persistent extent `[+0x28,+0x38)`; and `v11`, `int`, width `0x4`, persistent member `var_4` at `[+0x44,+0x48)`. Every listed lvar has local-user comment absent.
- Historical predicted post-action target: receiver `this`, `TextButtonExControlPane *`, width `0x4`, `ECX`; parameter `text`, `const wchar_t *`, width `0x4`, persistent member `text` at `+0x50/[+0x50,+0x54)`; parameter `bounds`, `const RectBounds *`, width `0x4`, persistent member `bounds` at `+0x54/[+0x54,+0x58)`. Authoritative readback matched this target, preserving all nonargument members and seven locals, and is recorded in IDA-Y7-003.

**IDA-Y7-004 historical literal frame and Hex-Rays prestate**

- Historical pre-Gate2B adjustor was exactly `[0x49b071,0x49b07c)`, size `0xb`, name `sub_49B071`, prototype `Pane *__thiscall(_DWORD *this, char)`, with all four start comment channels absent.
- Persistent frame contains exactly one member: `__return_address`, offset `+0x0`, size `0x4`, extent `[+0x0,+0x4)`, type `_UNKNOWN *`, stack-member regular/repeatable comments absent. There is currently no persistent `arg_0` member.
- Hex-Rays nevertheless exposes receiver `this`, type `_DWORD *`, width `0x4`, `ECX`, no stack extent, plus parameter `a2`, type `char`, logical width `0x1`, sourced from the low byte of the untouched caller four-byte argument slot at entry `[ESP+0x4,ESP+0x8)`. The thunk does not read or adjust ESP; `sub ecx,0xa0` followed by a tail jump forwards that caller slot unchanged to UID0002Y7. Thus current `char a2` is a decompiler low-byte representation, not proof of a one-byte ABI stack slot. Both lvar-user comments are absent; there are no other locals.
- Historical predicted post-action target: receiver `adjustedThis`, `void *`, width `0x4`, `ECX`; parameter `flags`, `unsigned int`, width `0x4`, represented by persistent `flags +0x4/[+0x4,+0x8)`; return entry and all bytes/routes preserved. Authoritative readback materialized `flags +0x4` automatically and is recorded in IDA-Y7-004.

**IDA-Y7-005 historical literal frame and Hex-Rays prestate**

- Historical pre-Gate2B adjustor was exactly `[0x49b07c,0x49b087)`, size `0xb`, name `sub_49B07C`, prototype `Pane *__thiscall(_DWORD *this, char)`, with all four start comment channels absent.
- Persistent frame contains exactly `__return_address` at `+0x0`, size `0x4`, extent `[+0x0,+0x4)`, type `_UNKNOWN *`, stack-member regular/repeatable comments absent; no persistent argument member currently exists.
- Hex-Rays receiver is `this`, `_DWORD *`, width `0x4`, `ECX`, no stack extent; parameter is `a2`, `char`, logical width `0x1`, sourced from the low byte of the unchanged caller four-byte slot `[ESP+0x4,ESP+0x8)`. The thunk only subtracts `0xa4` from ECX and tail-jumps, so the full caller slot is forwarded. Both lvar-user comments are absent and there are no other locals.
- Historical predicted post-action target: receiver `adjustedThis`, `void *`, width `0x4`, `ECX`; `flags`, `unsigned int`, width `0x4`, persistent frame member at `+0x4/[+0x4,+0x8)`; return entry, subtraction, tail jump, bytes, range, and vtable xref preserved. Authoritative readback materialized `flags +0x4` automatically and is recorded in IDA-Y7-005.

**IDA-Y7-002 complete historical instruction-item partition**

Historical pre-Gate2B `lookup_funcs(0x4955e0)` returned `Not a function`. `insn_query` returned exactly 14 instruction heads with `fn:null`. `inspect_items` and `get_comments` established this complete prestate partition; every row had `is_code:true`, `is_data:false`, type absent, address-regular absent, address-repeatable absent, and function-regular/function-repeatable not applicable because no containing function existed:

| Head | End | Size | Instruction/classification | Persistent name | Type | Address comments | Function comments |
| --- | --- | ---: | --- | --- | --- | --- | --- |
| `0x4955e0` | `0x4955e1` | `0x1` | code `push esi` | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x4955e1` | `0x4955e3` | `0x2` | code `mov esi, ecx` | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x4955e3` | `0x4955e9` | `0x6` | code `mov ecx, [esi+10Ch]` | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x4955e9` | `0x4955ef` | `0x6` | code primary TextButtonEx vptr store | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x4955ef` | `0x4955f9` | `0xa` | code `+0xa0` TextButtonEx vptr store | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x4955f9` | `0x495603` | `0xa` | code `+0xa4` TextButtonEx vptr store | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x495603` | `0x495605` | `0x2` | code `test ecx, ecx` | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x495605` | `0x495607` | `0x2` | code `jz short loc_49560D` | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x495607` | `0x495609` | `0x2` | code `mov eax, [ecx]` | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x495609` | `0x49560b` | `0x2` | code `push 1` | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x49560b` | `0x49560d` | `0x2` | code `call dword ptr [eax]` | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x49560d` | `0x49560f` | `0x2` | code `mov ecx, esi` | `loc_49560D` | absent | regular absent; repeatable absent | not applicable; no function |
| `0x49560f` | `0x495610` | `0x1` | code `pop esi` | absent | absent | regular absent; repeatable absent | not applicable; no function |
| `0x495610` | `0x495615` | `0x5` | code tail `jmp Pane__Destructor` | absent | absent | regular absent; repeatable absent | not applicable; no function |

Historical boundary readback was exact: pre-fence `[0x4955dc,0x4955e0)` was one four-byte data item with no name/type/comments; post-fence `[0x495615,0x495620)` was one eleven-byte data item with no name/type/comments; successor `sub_495620` was `[0x495620,0x49574c)`, size `0x12c`, and had all four start comment channels absent. The raw prestate had no stack frame, receiver, Hex-Rays locals, or local-user comments because it was not yet a function. The fences/successor remain unchanged after exact function creation.

| ID | Entity/range | Exact historical prestate | Applied action | Authoritative poststate and safety readback |
| --- | --- | --- | --- | --- |
| IDA-Y7-T01 | type `TextButtonExControlPane` | `type_inspect(name=TextButtonExControlPane, include_members=true)` -> `exists:false`, literal `Type not found: TextButtonExControlPane`; exact type-name collision absent. | Added incomplete `struct TextButtonExControlPane;` for pointer-only prototypes; no flat reverse-engineered member array was invented. | Named incomplete tag exists, has no members, and safely parses `TextButtonExControlPane *`. Documentation, not this analysis-only tag, owns exact source inheritance and `0x110` layout. No existing type was overwritten. |
| IDA-Y7-001 | function `[0x49b860,0x49b8c7)`, size `0x67` | Historical literal frame/receiver/parameter/local prestate is recorded above and is part of this row. Name `sub_49B860`; prototype `Pane *__thiscall(Pane *Block, char)`; all four start comment channels absent; exact collision query for `TextButtonExControlPane__ScalarDeletingDestructor` returned `total:0`. | Renamed `TextButtonExControlPane__ScalarDeletingDestructor`; applied `TextButtonExControlPane *__thiscall TextButtonExControlPane__ScalarDeletingDestructor(TextButtonExControlPane *this, unsigned int flags)`; materialized `flags`/`unsigned int` at `+0xc`; set function-repeatable comment exactly: `Compiler-generated TextButtonExControlPane scalar deleting destructor. Restores the primary, +0xa0, and +0xa4 vptr views, deletes owned TextBoxPane *m_labelTextBox at +0x10c, chains Pane teardown, and dispatches hidden flags between no free, operator delete, and the 0x110-byte no-op path.` | Exact name/type/comment read back. Address regular/repeatable and function regular remain blank; the literal function-repeatable comment is present. Receiver is `TextButtonExControlPane *this`; persistent `unsigned int flags` is `+0xc`; saved-register/return-address entries and auto local are unchanged. Range, bytes, xrefs, and nonargument frame state are preserved. |
| IDA-Y7-002 | raw executable `[0x4955e0,0x495615)`, size `0x35` | Complete historical 14-item partition, per-item names/types/comments, fences, successor, and no-frame/no-lvar prestate are recorded above. Bytes SHA256 `79C8...DF9C`; unique signature; zero xrefs/pointer hits. Collision query for `TextButtonExControlPane__Destructor` returned `total:0`. | Defined exactly `[0x4955e0,0x495615)`; renamed `TextButtonExControlPane__Destructor`; applied `void __thiscall TextButtonExControlPane__Destructor(TextButtonExControlPane *this)`; set function-repeatable comment exactly: `Source ordinary TextButtonExControlPane destructor. Deletes owned TextBoxPane *m_labelTextBox at +0x10c, then compiler lowering chains Pane teardown. Vptr stores/base call are compiler generated; source body is delete m_labelTextBox.` | Exact function/name/type/comment read back; address regular/repeatable and function regular remain blank. Receiver is `TextButtonExControlPane *this`; no source parameters. Authoritative auto local is `void (__thiscall ***v2)(_DWORD)` and sole frame entry is `__return_address +0x4`, not predicted two-argument/`+0x0`; no coercion was attempted. All 14 heads, bytes, fences, successor, zero xrefs, and pointer negatives are preserved. |
| IDA-Y7-003 | constructor `[0x495450,0x4955dc)`, size `0x18c` | Historical complete persistent frame and Hex-Rays receiver/parameters/seven-local prestate is recorded above. Name `sub_495450`; prototype `int __thiscall(int this, const unsigned __int16 *, int *)`; all four start channels absent; exact collision query returned `total:0`. | Renamed `TextButtonExControlPane__Constructor`; applied `TextButtonExControlPane *__thiscall TextButtonExControlPane__Constructor(TextButtonExControlPane *this, const wchar_t *text, const RectBounds *bounds)`; materialized `text +0x50` and `bounds +0x54`; set function-repeatable comment exactly: `Source TextButtonExControlPane constructor. Installs the primary, +0xa0, and +0xa4 vptr views, allocates a 0x174-byte TextBoxPane from the wide label text and bounds, and stores the owned pointer at +0x10c.` | Exact name/type/comment and `this`/`text`/`bounds` read back; address regular/repeatable and function regular remain blank. Every nonargument frame member, all seven locals, range, caller, bytes, vtable writes, and interior comments are preserved. |
| IDA-Y7-004 | adjustor `[0x49b071,0x49b07c)`, size `0xb` | Historical exact one-member frame and Hex-Rays `this`/`a2` prestate, including the low-byte view of untouched caller slot `[ESP+0x4,ESP+0x8)`, is recorded above. Name `sub_49B071`; all four channels absent; sole inbound data ref `0x617d90`; collision query returned `total:0`. | Renamed `TextButtonExControlPane__ScalarDeletingDestructorAdjustorA0`; applied `TextButtonExControlPane *__thiscall TextButtonExControlPane__ScalarDeletingDestructorAdjustorA0(void *adjustedThis, unsigned int flags)`; automatically materialized `flags +0x4`; set function-repeatable comment exactly: `Compiler-generated TextButtonExControlPane scalar-deleting-destructor adjustor for the +0xa0 interface view. Subtracts 0xa0 from adjustedThis and tail-jumps to TextButtonExControlPane__ScalarDeletingDestructor with the unchanged four-byte flags argument.` | Exact name/type/comment and `adjustedThis`/`flags +0x4` read back; regular/address channels remain blank. Exact bytes, range, sole vtable ref, subtraction, and tail jump are preserved; no unsafe manual frame operation was used. |
| IDA-Y7-005 | adjustor `[0x49b07c,0x49b087)`, size `0xb` | Historical exact one-member frame and Hex-Rays `this`/`a2` prestate, including the low-byte view of caller slot `[ESP+0x4,ESP+0x8)`, is recorded above. Name `sub_49B07C`; all four channels absent; sole inbound data ref `0x617dc0`; collision query returned `total:0`. | Renamed `TextButtonExControlPane__ScalarDeletingDestructorAdjustorA4`; applied `TextButtonExControlPane *__thiscall TextButtonExControlPane__ScalarDeletingDestructorAdjustorA4(void *adjustedThis, unsigned int flags)`; automatically materialized `flags +0x4`; set function-repeatable comment exactly: `Compiler-generated TextButtonExControlPane scalar-deleting-destructor adjustor for the +0xa4 interface view. Subtracts 0xa4 from adjustedThis and tail-jumps to TextButtonExControlPane__ScalarDeletingDestructor with the unchanged four-byte flags argument.` | Exact name/type/comment and `adjustedThis`/`flags +0x4` read back; regular/address channels remain blank. Exact bytes, range, sole vtable ref, subtraction, and tail jump are preserved; no unsafe manual frame operation was used. |
| IDA-Y7-006 | interior address `0x49b863` | Historical address regular literal `int`; address repeatable absent. | Deleted only the stale address-regular comment. | Address regular/repeatable absent; containing target function/comment/type unchanged. |
| IDA-Y7-007 | interior address `0x49b890` | Historical address regular literal `this`; address repeatable absent. | Deleted only the stale address-regular comment. | Address regular/repeatable absent; instruction/call unchanged. |
| IDA-Y7-008 | interior address `0x49b8a2` | Historical address regular literal `block`; address repeatable absent. | Deleted only the stale address-regular comment. | Address regular/repeatable absent; instruction/call unchanged. |

Protected/no-change dependencies:

- `RectBounds`: current exact size `0x10`, four `int` members `left/top/right/bottom` at `0/4/8/c`; no change.
- `Pane`: current UDT size `0xf8`; no change. Do not complete or restructure it in this callback.
- `0x544580 Pane__Destructor`: exact current function-regular comment states derived calls are compiler-generated base teardown; preserve name/type/range/all comments.
- `0x4f4ac0 NexusTK_operator_delete_wrapper`: exact function-regular comment identifies global delete support; preserve.
- `0x41b6a0 @_guard_check_icall_nop@4`: exact one-byte range and two-line function-regular correction must remain; do not rename or type it as a deallocator.
- Vtable/RTTI data names and comments at `0x617d20/24/90/c0`, `0x645a0c/20/30/54/70/84`, and `0x6757ac` are protected. Do not create source arrays, change bounds, or overwrite decorated names.
- `0x617dc8` is outside the TextButtonEx island and must remain untouched.

## First-Draft C++ Recommendation

- Target UID0002Y7 eligible for draft C++: no. It is compiler-generated ABI output.
- Target CPP disposition: blank.
- Target H disposition: blank.
- Exact no-code proof: the target is reached only through primary/adjusted vtable routes, performs vptr restoration, hidden bit dispatch, optional global storage release, return-`this` ABI, explicit base teardown, and the one-byte `0x110` path. Those mechanisms regenerate from the virtual destructor declaration and ordinary source body.
- UID0003NA exact CPP insertion:

```cpp
TextButtonExControlPane::~TextButtonExControlPane()
{
    delete m_labelTextBox;
}
```

- UID0003NA H insertion: blank because the declaration belongs to UID0000EK.
- UID0000EK CPP insertion: blank. Child method bodies remain attached through `[[CHILDREN]]` in H routing.
- UID0000EK exact H insertion:

```cpp
class Layer;
class TextBoxPane;

class TextButtonExControlPane : public ButtonControlPane
{
public:
    TextButtonExControlPane(const wchar_t *text, const RectBounds &bounds);
    virtual ~TextButtonExControlPane();

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();

    virtual void Enable();
    virtual void Disable();
    virtual short GetText(wchar_t *destination, short maxCharacters);

protected:
    virtual void SetVisualState(unsigned char visualState);
    virtual void OnPaint();

private:
    void CalculateLabelRect(RectBounds *outRect);
    void CalculateLabelRect(RectBounds *outRect, const wchar_t *text);

    TextBoxPane *m_labelTextBox;
};

[[CHILDREN]]
```

- UID00001E channel correction: move its complete existing declaration byte-for-text from CPP to H; leave CPP blank. Do not otherwise change its accepted source.
- Behavior preservation: `delete m_labelTextBox` produces the observed null-safe virtual deleting call; the compiler inserts derived vptr restoration and implicit Pane base teardown. A virtual destructor declaration causes the primary and adjusted deleting entries required by the three vtables.
- Human source shape: class declaration, private owned pointer, virtual override names inherited from base, and one-line RAII cleanup match late-1990s/mid-2000s MSVC game source. No IDA address, offset, hidden flag, vtable literal, or generated helper appears in source.
- Naming style: project class/method PascalCase, `m_` member prefix, lower camel parameter names, `NULL`-era pointer semantics in behavior docs. `m_labelTextBox` aligns with current class documentation and role.

## Final Recommendation

- UID0002Y7 is now `94/97`, owner 0000EK, FALSE, with no emitter/position, blank CPP/H, populated Item Summary, and Nested 0.
- UID0003NA is now `95/97`, owner/emitter 0000EK, TRUE, position 20, with the exact destructor CPP and blank H.
- UID0000EK is now `94/96`, owner/emitter 0000HY, TRUE, position 20, with blank CPP and the complete H declaration containing one `[[CHILDREN]]`.
- UID00001E remains `91/93` with its owner/emitter/position unchanged; its complete declaration moved byte-for-text from CPP to H without textual loss.
- UID0002Y6 is now `93/96`, NONE/FALSE/non-emitting, with blank formals and exact compiler-adjustor evidence.
- UID0000HY is now `91/93` on the same file route and carries the exact source/compiler split and generated topology evidence.
- UID00011Y/UID000118/UID000252 retain their accepted metadata/scores and now contain the bounded exact TextButtonEx facts without source emission.
- IDA: supervisor applied the bounded handoff after exact prestate/collision checks and backup, verified all five names/signatures/function-repeatable comments plus the incomplete type, raw exact function, automatic frame entries, three comment clearings, protected state, and saved/cataloged IDB SHA256 `408F73923C6BDD17931E828365DC0D7D67F583FE6F0FDDA50103F45FB84461A7`. Catalog entry 0348 is exactly `APPLIED_VERIFIED_RECONCILED`. The raw destructor's authoritative `__return_address +0x4` and `void (__thiscall ***v2)(_DWORD)` presentation is accepted without coercion.
- Future work outside assignment: constructor and five broader modeled method bodies still lack exact by-memory children/formal CPP. This does not block the destructor source route or wrapper reclassification; it should be selected later from the uncovered queue rather than broadening this declared target.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md`.
- Applied and read back: metadata is exactly `94/97`, owner `0000EK`, FALSE, blank emitter/position/formals, and Nested 0.
- Applied and read back: Item Summary includes the exact wrapper range/hash, three vptr views, child deletion, Pane teardown, bits 1/4, no-op size path, thunk/vtable-only reachability, and source route via UID0003NA/UID0000EK.
- Applied and read back: stale Assignment Gate and B010 marker dispositions are preserved only as historical superseded assumptions beneath the current compiler-only/non-emitting decision.
- Applied and read back: exact bytes, padding, xrefs, vtable/RTTI island, object layout, source cause, rejected alternatives, and authoritative applied-IDA state are present.
- Applied and read back: formal CPP/H are blank; the pseudo-source comment was removed and not replaced. Current post-IDA-reconciliation target SHA256 is `FB8C3A9BA1FA7B638FBABC34B03273135599DD603ED7B14199051C7C124CD6B1`; validator command `000000018698` exited `0` with `ok:1` and skipped generated refresh.

## Recommended Support Doc Changes

- `by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md`: C2Y7-008 through C2Y7-011, exact CPP, score/position, source/compiler rationale, exact applied destructor IDA state, and bounded `+0x4`/single-argument-local normalization are applied/read back; SHA256 `7623FAAA6C27C7C649DCEE3CBFBF4111116DCC3E6A09BE00B630AB4C5393299E`, validator `000000018699` ok1 with generated refresh skipped.
- `by-class/TextButtonExControlPane.md`: C2Y7-012 through C2Y7-015, complete H, corrected virtual names, exact layout, ordinary/wrapper split, historicalized declaration withholding, and the complete applied five-function IDA family are applied/read back; SHA256 `0EEB85159348230AEB6EE060D9F707B1645350CFD32B59DB919E3EB13AC1CBD0`, validator `000000018700` ok1 with generated refresh skipped.
- `by-class/ButtonControlPane.md`: the existing declaration remains byte-for-text in H, score/content are preserved, and the applied exact TextButtonEx derived-constructor identity/frame/comment state is recorded; SHA256 `560CD931F1B0D17B8E3E884D420CC270CE54510E9EF86856AB98E363DF3D11F5`, validator `000000018701` ok1 with generated refresh skipped.
- `by-file/ButtonControlPane.md`: `91/93`, exact TextButtonEx source/compiler split, complete applied five-function IDA state, bounded raw normalization, and source topology are current; SHA256 `A6F5FA021B16B516C9D74C4078E9193EF4C8A2339FA9D198558E6E8F0DF2ED82`, validator `000000018703` ok1 with generated refresh skipped. Historical callback/current-before-reconciliation hashes remain recorded in `Supporting Research` and `Changed Files`.
- `by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md`: `93/96`, Item Summary, exact bytes/xrefs, both applied names/signatures/function-repeatable comments, automatic `flags +0x4`, and unchanged NONE/FALSE/blank formals are applied/read back; SHA256 `FC58502B69AAEE74ED34FD274960B5E21557C9E085C046DABA7509EAA535204B`, validator `000000018702` ok1 with generated refresh skipped.
- `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md`: aggregate metadata is preserved and exact current TextButtonEx ordinary-source/compiler-support plus applied IDA state is read back; SHA256 `A7B4A22E7D95E3D5C92E07557304F52E747C9CDE07A1E06F343A226F88EE8C2C`, validator `000000018704` ok1 with generated refresh skipped.
- `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`: aggregate metadata is preserved; the band now correctly records nine modeled TextButtonEx functions and the authoritative applied family state; SHA256 `73F55BA2B58F2AE6E91E94491D7EB3D53345D65AD3A9DD5A278950BFB27351AD`, validator `000000018705` ok1 with generated refresh skipped.
- `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md`: FALSE/no-owner/score and exact island/maps are preserved; applied primary/adjusted function identities, frame state, bounded normalization, and protected-data readback are current; SHA256 `0605C9B4CD2937D4E54A18E37CB777A44F987CF0F92BA6FCFF7937FF2654940E`, validator `000000018706` ok1 with generated refresh skipped and the same pre-existing UID0003J8 missing-reference warnings.
- `by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md`: verify-only readback passed; its formal signatures match the new H declarations, so its SHA256 `9E854123E169238AAE1FDC6B01CFE63E64E06D792AD39430779AC75A6E2B3C4B` and score/route/body remain unchanged.
- `by-project-structure/proposed-source-tree.md`: verify-only readback passed; UID0000HY already has the accepted route, so SHA256 `4823946CE895697E54E0A2D1F1B57196564371F61F20002C9D529973D3E3F189` remains unchanged.

## Score And Metadata Recommendation

- Applied transition: UID0002Y7 assignment-time `87/89 TRUE/emitter/comment` is now `94/97 FALSE/non-emitting/blank` with semantic owner retained.
- Applied transition: UID0003NA assignment-time `86/89` is now `95/97`, same owner/emitter/TRUE, position 20, exact CPP.
- Applied transition: UID0000EK assignment-time `88/89` is now `94/96`, same owner/emitter/TRUE, position 20, complete H/blank CPP.
- Applied transition: UID0002Y6 assignment-time `86/90` is now `93/96`, same NONE/FALSE/blank.
- Applied transition: UID0000HY assignment-time `90/92` is now `91/93`, same FILE/path.
- UID00001E, UID00011Y, UID000118, and UID000252 retain their accepted scores/metadata; their bounded channel/prose detail is applied.
- Reason target not higher: no original private symbol/source file and exact MSVC compilation switches are available. Those do not affect classification or behavior, but cap completion below exhaustive final audit.
- Reason target not lower: exact bytes, bounds, all refs, cleanup, flags, object size, vtables, RTTI, ordinary source cause, and owner are independently convergent.
- Score-improvement attempts: no-xref raw start was exhausted through xrefs and three pointer encodings; method names were resolved through vtable slot inheritance; member type/name through constructor and all consumers; file route through neighborhood/docs and rejected alternatives; guard path through exact one-byte body; target metadata through current structure rules and reviewed family precedent.
- The unresolved original spelling problem is handled by best-source inference, not by retaining `sub_`, `Block`, or offset labels.

## Open Questions With Attempted Resolution

- Was UID0002Y7 authored source? Resolved no: all distinctive operations are compiler ABI lowering and reachability is vtable/thunk-only.
- Should target remain TRUE with marker coverage? Resolved no for this family: exact ordinary source exists, reviewed sibling policy uses semantic-owner FALSE, and current assignment rejects pseudo-source.
- What source body deletes the child? Resolved: UID0003NA's exact human body is `delete m_labelTextBox;`.
- Is raw UID0003NA dead junk because it has no xrefs? Resolved no: unique coherent bytes, exact vptr triplet, wrapper prefix equivalence, and closed fences prove retained ordinary destructor source.
- What is `+0x10c`? Resolved `TextBoxPane *m_labelTextBox`; constructor type/size and all consumers agree.
- What are `0x4957c0/0x495840`? Resolved `Enable/Disable`, not show/hide, by inherited slots and `m_enabled` behavior.
- What are `0x4958c0/0x495920`? Resolved `AddToLayer/RemoveFromLayer`, not invented attach/detach names.
- What does bit 4 do? Resolved: branches to one-byte no-op after pushing `0x110` and `this`; it does not release storage.
- Does a narrower source file need creation? Resolved no for current reconstruction: no evidence exceeds the established UID0000HY route.
- What remains genuinely unknown? Only exact historical private/helper spellings and physical file split. Best supported names/current route are selected; these are confidence caps, not blockers or "needs investigation" deferrals.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual rows were read. B004 must not apply these edits.

- `by-memory/-coverage-report.md`: insert under UID000118 in address order:

```text
    - [UID:0003NA][0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown](by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md) 0x004955e0-0x00495615 | source ordinary destructor | TextButtonExControlPaneDestructor : reconstructable : 95% : very-strong : Exact 53-byte retained TextButtonExControlPane ordinary destructor with closed CC fences, unique signature, three derived vptr restores, owned TextBoxPane *m_labelTextBox deletion at +0x10c, and compiler Pane tail teardown; human source is only delete m_labelTextBox, while UID0002Y6/UID0002Y7 carry non-emitting adjusted/deleting ABI support.
```

- `by-memory/-coverage-report.md`: replace UID00011Y row with:

```text
    - [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) 0x0049af11-0x0049b8d5 | destructor/thunk aggregate | ButtonChoiceControlDestructors : ignored : 86% : strong : Reviewed non-reconstructable multi-owner destructor/thunk index whose exact children carry source or compiler disposition; RadioGroup and TextButtonEx now each route human cleanup through an exact ordinary destructor/class declaration while their adjusted/deleting entries remain compiler-only, and UID0002XW remains the shared four-class compiler deleting entry.
```

- Immediately after that aggregate row, insert in address/relationship order:

```text
    - [UID:0002Y6][0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks](by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md) 0x0049b071-0x0049b087 | compiler adjustor thunk pair | TextButtonExControlPaneAdjustorThunks : not_reconstructable : 93% : very-strong : Exact two 11-byte thunks subtract this by 0xa0/0xa4 and tail-jump to UID0002Y7 from secondary/tertiary TextButtonExControlPane vtable views; NONE/FALSE/non-emitting with blank source because the class declaration and UID0003NA ordinary destructor regenerate them.
    - [UID:0002Y7][0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor](by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md) 0x0049b860-0x0049b8c7 | compiler complete-object deleting wrapper | TextButtonExControlPaneScalarDeletingDestructor : not_reconstructable : 94% : very-strong : Exact 103-byte class-owned compiler wrapper restores three TextButtonExControlPane vptr views, deletes owned TextBoxPane *m_labelTextBox at +0x10c, invokes Pane teardown, and dispatches hidden flags between no free, operator delete, or the 0x110-byte one-byte no-op path; human source is UID0000EK's virtual declaration plus UID0003NA's ordinary body, so this page emits no C++.
```

- Replace UID000252 row with:

```text
    - [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md) 0x00617a38-0x00618858 | mixed vtable/string-data index | ControlPaneReadOnlyData : not_reconstructable : 86% : very-strong : Non-emitting mixed control-family read-only-data index with current named anchors and exact child boundaries; TextButtonExControlPane island 0x00617d20-0x00617dc8 is byte/hash documented with 26/11/2 entries routing primary UID0002Y7 and secondary/tertiary UID0002Y6 deleting support, RadioGroup has its corresponding reviewed island, and unrelated unsplit vtable/string neighbors remain explicit completion caps.
```

- `by-class/-coverage-report.md`: replace UID0000EK row with:

```text
- [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md) : reconstructable : 94% : very-strong : Complete 0x110 ButtonControlPane-derived declaration with TextBoxPane *m_labelTextBox at +0x10c, exact constructor/state/enable/disable/layer/paint/text/helper surface, virtual destructor declaration, retained ordinary source destructor UID0003NA, and explicit compiler-only UID0002Y6/UID0002Y7 plus 26/11/2 RTTI/vtable support; source emits through ButtonControlPane.h/.cpp without raw ABI wrapper code.
```

- `by-file/-coverage-report.md`: replace UID0000HY row with:

```text
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) : reconstructable : 91% : very-strong : Reusable button/choice-control module under NexusTK/ui/controls with complete header declarations and exact method children; RadioGroupControlPane and TextButtonExControlPane now each emit one human ordinary destructor while their adjusted/deleting/vtable/RTTI support remains compiler-only, and the possible final ChoiceControlPane or narrower text-button source split remains explicit.
```

- Reason B agent must not apply directly: all `-coverage-report.md` files are supervisor-owned collision points and require post-callback/manual validation.

## Follow-Up Actions

- Completed historical stages: strict pre-callback exact-artifact Gate 1 passed SHA256 `7152D9D2FF7CEC8989F6B7A4BCBFA382719791DAD0710C3CA1E845BD9B68A0CA`; B004 then implemented every accepted ordinary-document ledger claim under per-file leases, ran serial scoped validators, released every lease, verified generated CPP/H physically, and reconciled this same report.
- Supervisor: perform the fresh exact-artifact gates required for this repaired report.
- Completed supervisor Gate 2A: commands `000000018683-000000018691` passed on the pre-IDA-reconciliation ordinary implementation.
- Completed supervisor Gate 2B: exact prestate/collision/backup/action/readback/save/catalog flow passed; catalog entry 0348 exact state `APPLIED_VERIFIED_RECONCILED` and IDB SHA256 `408F73923C6BDD17931E828365DC0D7D67F583FE6F0FDDA50103F45FB84461A7` are authoritative.
- Completed B004 post-IDA reconciliation: all nine ordinary docs and this report now reflect applied state; serial commands `000000018698-000000018706` passed with `--no-generated-refresh`.
- Remaining supervisor closure only: complete fresh gates on this repaired artifact, apply and validate exact manual coverage, perform final lifecycle-time generated closure/readback, execute/archive the report, and confirm registry/tracker state.
- Future queue: exact constructor and other modeled TextButtonEx method pages may be split/researched later; do not block this completed destructor/compiler repair on that broader source recovery.

## Confidence

- Recommendation confidence: 97/100 for target wrapper classification and source/compiler split.
- Score confidence: high; all assignment-time blockers were actively investigated and either resolved or converted to bounded historical-spelling confidence caps.
- C++ confidence: very strong for destructor body and layout; strong for complete declaration names/access. The declaration contains no raw IDA artifacts and matches inherited slots.
- Remaining uncertainty: exact original spelling and narrower physical file organization only. Neither changes runtime behavior, owner, emitter, or wrapper disposition.

## Validator Results

- Scoped ordinary-document commands, all run serially from `source-3/project-documentation` with `--mode file --file <path> --apply --queue-timeout 240`, all exited `0` with `ok:1`:

| Command | Timestamp | Path / purpose | Result |
| --- | --- | --- | --- |
| `000000018431` | `2026-07-28T16:24:58-04:00` | UID0002Y7 target | exit 0, ok1; registered FALSE/non-emitting transition |
| `000000018438` | `2026-07-28T16:26:01-04:00` | UID0003NA ordinary destructor | exit 0, ok1 |
| `000000018442` | `2026-07-28T16:27:30-04:00` | UID0000EK class | exit 0, ok1 |
| `000000018443` | `2026-07-28T16:28:04-04:00` | UID00001E base class | exit 0, ok1 |
| `000000018444` | `2026-07-28T16:28:47-04:00` | UID0002Y6 adjustor thunks | exit 0, ok1 |
| `000000018445` | `2026-07-28T16:29:59-04:00` | UID0000HY file route | exit 0, ok1 |
| `000000018446` | `2026-07-28T16:31:07-04:00` | UID00011Y destructor aggregate | exit 0, ok1 |
| `000000018447` | `2026-07-28T16:32:08-04:00` | UID000118 core aggregate | exit 0, ok1 |
| `000000018451` | `2026-07-28T16:34:57-04:00` | UID000252 read-only data | exit 0, ok1; pre-existing unresolved reference UID0003J8 was reported but did not invalidate this scoped page |
| `000000018453` | `2026-07-28T16:35:26-04:00` | B004 final UID0000HY `--wait-generated` | exit 0, ok1; callback generated refresh completed |

- Supervisor Gate 2A commands `000000018683-000000018691` passed independently across the same nine ordinary documents before IDA mutation.
- Post-IDA reconciliation validators were run serially from `source-3/project-documentation` with exact command form `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240 --no-generated-refresh`:

| Command | Timestamp | Path | Result |
| --- | --- | --- | --- |
| `000000018698` | `2026-07-29T01:46:24-04:00` | `by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md` | exit 0, ok1; generated refresh skipped |
| `000000018699` | `2026-07-29T01:46:27-04:00` | `by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md` | exit 0, ok1; generated refresh skipped |
| `000000018700` | `2026-07-29T01:46:29-04:00` | `by-class/TextButtonExControlPane.md` | exit 0, ok1; generated refresh skipped |
| `000000018701` | `2026-07-29T01:46:31-04:00` | `by-class/ButtonControlPane.md` | exit 0, ok1; generated refresh skipped |
| `000000018702` | `2026-07-29T01:46:34-04:00` | `by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md` | exit 0, ok1; generated refresh skipped |
| `000000018703` | `2026-07-29T01:46:36-04:00` | `by-file/ButtonControlPane.md` | exit 0, ok1; generated refresh skipped |
| `000000018704` | `2026-07-29T01:46:39-04:00` | `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md` | exit 0, ok1; generated refresh skipped |
| `000000018705` | `2026-07-29T01:46:41-04:00` | `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` | exit 0, ok1; generated refresh skipped |
| `000000018706` | `2026-07-29T01:46:43-04:00` | `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md` | exit 0, ok1; generated refresh skipped; same pre-existing UID0003J8 missing-reference warnings |

- Command `000000018431` initially observed missing UID0003NA registration because the new source child had not yet been validated; serial command `000000018438` registered and validated that page. No callback claim remains unvalidated by B004's scoped passes.
- Command `000000018453` callback artifacts are dated callback provenance. At the later dated implementation-time checkpoint command `000000018462`, refreshed `2026-07-28T16:43:24-04:00`, generated `ButtonControlPane.cpp` had SHA256 `035364FE4C456607991E4325F804FEB9733A691452A6FC915EA4033C7D0F4522`, 7,724 bytes, 234 lines, mtime `2026-07-28T16:43:32.0375507-04:00`.
- At the same dated implementation-time checkpoint command `000000018462`, generated `ButtonControlPane.h` had SHA256 `1C6EEBC8B84092F00B603B87A274D70F12250C4E9763C063D0EB538217587995`, 3,478 bytes, 128 lines, mtime `2026-07-28T16:43:32.0687660-04:00`.
- Later supervisor/global validator refreshes may advance generated command metadata, header timestamps, and hashes without changing the verified semantic topology. Do not chase a newer global hash in this report; final supervisor lifecycle-time generated CPP/H closure/readback remains pending and will be authoritative.
- Physical topology readback: one TextButtonEx class H, one ordinary TextButtonEx destructor CPP, two retained `CalculateLabelRect` helper definitions, zero UID0002Y7 source/empty-emitter markers, no TextButtonEx ABI-wrapper source, and no related loss or duplication. The unrelated existing UID0000EK class-channel marker in CPP and unrelated ImageButton scalar-wrapper commentary are not UID0002Y7 output.

## Changed Files

- Modified ordinary documents:
  - `by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md` - callback SHA256 `7CC93BF0FCB032485A3E5E77C832BE88B085327EF7B3C80DE298B49A2B2BA7CD`; post-IDA SHA256 `FB8C3A9BA1FA7B638FBABC34B03273135599DD603ED7B14199051C7C124CD6B1`.
  - `by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md` - callback SHA256 `3D08B17C92F245FF0FA8DB3DA4BAB954647E2F506460A20E82FB0CEF207E335E`; post-IDA SHA256 `7623FAAA6C27C7C649DCEE3CBFBF4111116DCC3E6A09BE00B630AB4C5393299E`.
  - `by-class/TextButtonExControlPane.md` - callback SHA256 `6D473717959D533E68A38E77A0099900F90320A56CFA617474B0FB2C25203ACF`; post-IDA SHA256 `0EEB85159348230AEB6EE060D9F707B1645350CFD32B59DB919E3EB13AC1CBD0`.
  - `by-class/ButtonControlPane.md` - callback SHA256 `709A1DDE139888176B81EB4333F19C7887B1D175CC21A213F33DEA9499F0FA3C`; post-IDA SHA256 `560CD931F1B0D17B8E3E884D420CC270CE54510E9EF86856AB98E363DF3D11F5`.
  - `by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md` - callback SHA256 `A6CD2E5F842E0DFB8AE48B96FD4D1241516BA611E9FC18758BEC653F5B26A3D9`; post-IDA SHA256 `FC58502B69AAEE74ED34FD274960B5E21557C9E085C046DABA7509EAA535204B`.
  - `by-file/ButtonControlPane.md` - callback SHA256 `FA57AC9B0B649FD6E14F664952BA3514C25733DF769326FDF16A0156BD235E68`; later unrelated-update SHA256 `AF4DB0A3A5252B4804DCD77FA1A040056058D316717348B895285B11BBED1646`; post-IDA SHA256 `A6F5FA021B16B516C9D74C4078E9193EF4C8A2339FA9D198558E6E8F0DF2ED82`.
  - `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md` - callback SHA256 `3EF5EF1FAC97E677961F42F2F034560B8973E82586218113FC3E31B2F57295D0`; post-IDA SHA256 `A7B4A22E7D95E3D5C92E07557304F52E747C9CDE07A1E06F343A226F88EE8C2C`.
  - `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` - callback SHA256 `4DF8F3C328860010EE85307AC29A2E1C36FFFDCC17654EAF26CF806B3D648108`; post-IDA SHA256 `73F55BA2B58F2AE6E91E94491D7EB3D53345D65AD3A9DD5A278950BFB27351AD`.
  - `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md` - callback SHA256 `A53FE44A2964880229CE3EA2F4BFB50E3AC0398AA706EEA3CD92F20C57055408`; post-IDA SHA256 `0605C9B4CD2937D4E54A18E37CB777A44F987CF0F92BA6FCFF7937FF2654940E`.
- Verify-only and unchanged: `by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md` SHA256 `9E854123E169238AAE1FDC6B01CFE63E64E06D792AD39430779AC75A6E2B3C4B`; `by-project-structure/proposed-source-tree.md` SHA256 `4823946CE895697E54E0A2D1F1B57196564371F61F20002C9D529973D3E3F189`.
- Supervisor independent current-state verification: all nine modified ordinary-document hashes and both verify-only hashes above exactly match this report; catalog entry 0348 is exactly `APPLIED_VERIFIED_RECONCILED`.
- Modified report only for this narrow lifecycle repair: `tools/leaser/Agents/Agent-B004/research/0002Y7-TextButtonExControlPaneScalarDeletingDestructor-source-quality.md`, repaired in place from failed artifact SHA256 `173D92F18092DE79B0C3D51A4A1EE5C05455CA7200C588E0646CF39E8489F265`; current identity is returned externally after final reconciliation because a file cannot embed its own stable hash.
- Renamed/moved: none. Every ordinary-file lease was acquired only for the edit/serial validator batch and then released immediately; no B004 lease remains.
- Report execution: not run. B004 did not run, probe, dry-run, move, archive, or issue any lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor exact-artifact Gate 1 validation passed SHA256 `7152D9D2FF7CEC8989F6B7A4BCBFA382719791DAD0710C3CA1E845BD9B68A0CA` and authorized implementation.
- [x] Target/support planning complete: UID0002Y7, UID0003NA, UID0000EK, UID00001E, UID0000HY, UID0002Y6, UID00011Y, UID000118, UID000252, with UID0003NC/proposed-source-tree verify-only.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: no additional target UIDs declared; all support destinations are itemized.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply itemized.
- [x] Score-limiting blockers researched to resolution or bounded best-source inference; no "needs investigation" deferral remains.
- [x] Owner/emitter/reconstructable changes to apply itemized.
- [x] Split/rename/new-child changes: no new child required; exact existing ranges retained; IDA names itemized.
- [x] Source-placement, range/split/padding/reclassification, and IDA changes itemized.
- [x] Supervisor Gate 2B IDA handoff lists every exact address/entity, historical pre-state, applied action, supporting type, safety constraint, and authoritative readback; catalog entry 0348 exact state `APPLIED_VERIFIED_RECONCILED` and saved IDB SHA are reconciled.
- [x] First-draft CPP/H block text and target no-code proof supplied.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail supplied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve supplied.
- [x] Wave2/Wave3 mentions encountered and ignored as stale.
- [x] Open questions closed or bounded with best-supported inference.
- [x] Validator planning completed and was followed: one serial scoped file validator per changed ordinary by-* page plus source-bearing command `000000018453` with generated wait/readback; commands `000000018453` and `000000018462` remain dated implementation-time checkpoints rather than claims about post-refresh final physical hashes.
- [x] Generated refresh expectations and exact supervisor-owned manual coverage text supplied.

Implementation callback pass:
- [x] Supervisor-owned IDA changes were applied by the supervisor, verified through catalog entry 0348 exact state `APPLIED_VERIFIED_RECONCILED`, saved, and reconciled by B004; B004 performed no IDA mutation.
- [x] Report accepted by supervisor for implementation at exact pre-callback SHA256 `7152D9D2FF7CEC8989F6B7A4BCBFA382719791DAD0710C3CA1E845BD9B68A0CA`.
- [x] All accepted target/support ordinary-document details incorporated at report-level detail.
- [x] Every declared primary/support UID verified independently against the ledger and destination documents; supervisor current-state verification confirms all nine modified ordinary hashes and both UID0003NC/proposed-source-tree verify-only hashes exactly match this report.
- [x] Claim And Incorporation Ledger updated to implemented/validated states for C2Y7-001 through C2Y7-024; only C2Y7-025 manual coverage remains supervisor-owned/pending.
- [x] Metadata/score/owner/emitter/reconstructable/position/CPP/H/channel changes applied exactly or verify-only disposition recorded.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved in ordinary docs at the accepted evidence level.
- [x] Original callback validators and post-IDA serial scoped validators `000000018698-000000018706` run; exact commands/results recorded with `--no-generated-refresh` for reconciliation.
- [x] Generated CPP/H semantic topology was physically verified at dated implementation-time commands `000000018453` and `000000018462`: one TextButtonEx class H, one ordinary destructor CPP, existing helper bodies retained, zero UID0002Y7 source/empty markers, no TextButtonEx ABI-wrapper source, and no related loss/duplication. Later supervisor/global refreshes may advance metadata/header hashes; final supervisor lifecycle-time generated closure/readback remains pending and will be authoritative.
- [x] Supervisor-owned Gate 2B IDA actions C2Y7-024 are applied/read back/saved/cataloged under exact state `APPLIED_VERIFIED_RECONCILED`; B004 performed no IDA mutation and reconciled the authoritative state into all nine ordinary docs.
- [ ] Supervisor-owned manual coverage changes C2Y7-025 remain unapplied; B004 edited no `-coverage-report.md` file.
- [ ] Only fresh supervisor gates on this repaired artifact, supervisor-owned manual coverage, final lifecycle-time generated closure, execute/archive, and registry/tracker confirmation remain pending; prior independent Gate 2A and applied/reconciled Gate 2B are complete.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000018739","destination_path":"executed-b-agent-research/B004/0002Y7-TextButtonExControlPaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002Y7-TextButtonExControlPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-29T02:31:02-04:00","uid":"0002Y7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
