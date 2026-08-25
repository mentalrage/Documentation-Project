** TARGET-REPORT-UID:0002JJ **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0002JJ MenuItem GetBounds Source-Quality Report

## Finalized Report / Current Recommendation

- Treat `[0x00516fb0,0x00516fc1)` as a retained, out-of-line, nonvirtual `MenuItem` member function, not compiler-generated copy glue, an inline-only duplicate, dead padding, or code covered by the byte-identical function at `0x00554ae0`.
- The accepted callback renamed the UID-preserving target page from `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md` to `by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md`. `MenuItemCopyBoundsRect` remains historical behavior/search vocabulary.
- Use the source-facing declaration `RectBounds *GetBounds(RectBounds *outBounds) const;` and the exact destination-managed definition supplied below. `GetBounds` is stronger than `CopyBounds` or `GetRect`; the pointer return is stronger than the existing `void` draft because the helper leaves `outBounds` in `EAX` and the accepted byte-shape comparator `GrafPort::GetBounds` uses the same return contract.
- UID0002JJ is now `92/94` with `CANONICAL_OWNER:00007V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007V`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0` preserved.
- Keep [UID:00007V] `MenuItem` as direct semantic owner and [UID:0000MN] `PopupMenuControls` as the current source root for `NexusTK/ui/menu/PopupMenuControls.cpp`. The possible historical `MenuItem.cpp` split remains a bounded physical-source uncertainty, not a routing blocker.
- Sibling [UID:0002JK] is now the paired retained `void MenuItem::SetBounds(const RectBounds *bounds)` method at the UID-preserving `MenuItemSetBounds.md` path and `90/93`, with its exact formal preserved.
- The ordinary-document callback, independent supervisor Gate 2A verification, and exact supervisor Gate 2B IDA application/readback/save are complete. B005 did not mutate IDA, directly edit manual coverage, or run/probe/dry-run any report lifecycle command. Manual coverage, execution, and archive remain supervisor-owned and pending.

## Supporting Research

- Assignment-time target checkpoint: [UID:0002JJ] `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md`, SHA256 `B03FF170865C14FD3CE0AA1495DA2CE90D0AE309ACED666754B856DDA90FB224`, `9934` bytes, `93` lines.
- Assignment-time setter checkpoint: [UID:0002JK] `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md`, SHA256 `CB6A22FCD9A4A3A77D9A6723B08ABCF2663C7418E6453660CCF46ECC1117D95A`, `9983` bytes, `93` lines.
- Assignment-time direct-owner/source-root/support hashes and scores were UID00007V `D443C0CF97A76839334F16528A51730975458182D5971052F26788EC9CF9D13C` at `90/92`, UID0000MN `E385A2B88FBF789D10BD56838F021C98165F17ABD41D2E04419F6692F4A966DB` at `86/85`, UID0001BK `5836AF159775B45D68067C935B2B8D64396BA930D437C1E23F20B2391B155F1B` at `88/90`, UID0001V5 `3ADD029B7F916D1A87E50ACF3B1A3F0D4D990A8AFAA33DDA2A8AAE59B89B1EDD` at `89/92`, UID0001Y4 `D5A35E94E26D7AA25045AE4777E86808692AB4C9E1484209166886661F957B78` at `86/91`, and UID00036I `1195B4C67E265FFDB454A61CFE1D339A1D499D25A443A7EE02AB37A3DA60F65D` at `86/91`.
- Assignment-time generated checkpoint: `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`, SHA256 `C3462CF93ADA6AEBCAB8A7F002B66E380F2D36FA859D3661A16F51E958457C42`, `14945` bytes, `433` lines, write time `2026-07-24T09:29:23.9699136-04:00`; one UID0002JJ marker/body and zero target empty markers.
- Current ordinary destination checkpoints after supervisor commands `000000017237` through `000000017244`: UID0002JJ `73ED697372AC81FC3EB95E7EAA6902AED3B3C555F6DC47A37D98602CDC401242`; UID0002JK `681D3B17286322D7F3F702E165BBB26A36B8873F72BE0BC591B361313E33FB59` after validator-normalized UID00036I link text; UID00007V `E9BB955D01CB2D6CB312B408B715B1E9A07158A5863D143E2F2FC8B273F39504`; UID0001BK `F417CFA80403EE896E2AB80991A6C7728344774176730B793945EA70106AD899`; UID0001V5 `70ECC8D87671DEAD523B7452977435F252F3C8690125857CD08E4234894A3EE8`; UID0001Y4 `040B5DCE9D5B7D2BE7392936D80D65B582DE8B66E0DF89D22F396694A4F98EA0`; UID00036I `4F6D1B0B40A91A7645C5A01B05E3416451E0319E4F36421FD5221C7B49780B5B`; UID0000MN `6CE622EF4495DF695D8E81695326380C2F2047F615795DE2FD653B45F87621C6`.
- Post-callback waited generated checkpoint under command `000000017234`: `PopupMenuControls.cpp` SHA256 `99528B117750A9EB3A85811A6EFA2A461E51D36EAF3D51B1629D078122267A29`, `15107` bytes, `436` lines, one UID0002JJ marker/body, one UID0002JK marker/body, and zero target or setter empty-emitter markers.
- Matching archived research was searched before broad reading. B008 report `executed-b-agent-research/B008/0000MN-PopupMenuControls-empty-emitter-family-source-quality.md` supplied the existing `void` draft and source-root decision; B003 report `executed-b-agent-research/B003/0002JH-MenuItemSetEnabled-source-quality.md` supplied the retained raw nonvirtual-method family analysis; B014 report `executed-b-agent-research/B014/0001FW-RegionAndMotionRect-source-quality.md` supplied the documented role of the byte-identical `0x00554ae0` comparator. Each inherited conclusion was independently rechecked below.
- Stale Wave2/Wave3 references were encountered in old reports and current vtable history. They were ignored as authority under the project skill; only current docs, live MCP, raw PE evidence, and current generated/manual state drive this recommendation.

## Target

- UID: `0002JJ` only. UID0002JK and all other UIDs in this report are support destinations, not additional report targets.
- Assignment-time path/title: `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md` / `MenuItem Copy Bounds Rect`.
- Recommended UID-preserving path/title: `by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md` / `MenuItem GetBounds`.
- Exact half-open range: `[0x00516fb0,0x00516fc1)`.
- Exact size: `17` decimal equals `0x11` `(Verified with int_convert.py)`.
- Exact target SHA256: `EA9AEECC35E759BF98B38B96CC4E91ED0B2D7916497F84EC4F663FDF693AB315` over the 17 target bytes.
- Assignment-time metadata: `86/91`, owner/emitter `00007V`, reconstructable true, nonblank `void` formal, blank emitter position, `Nested:0`.
- Recommended metadata: `92/94`, same owner/emitter/reconstructable/position/nesting, corrected pointer-return formal.

## Current Target State

- The assignment-time page emitted `void MenuItem::GetBounds(RectBounds *bounds) const { *bounds = m_bounds; }` while its prose still called final C++ absent, the source name unresolved, and the retained-source versus inline/compiler disposition open. The accepted callback preserved those statements as historical defects and replaced the current formal with the pointer-return `GetBounds` body.
- Current UID0002JJ is `by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md`, `92/94`, SHA256 `73ED697372AC81FC3EB95E7EAA6902AED3B3C555F6DC47A37D98602CDC401242`, with UID/range/owner/emitter/reconstructability/position/nesting preserved. Current UID0002JK is `MenuItemSetBounds.md`, `90/93`, SHA256 `681D3B17286322D7F3F702E165BBB26A36B8873F72BE0BC591B361313E33FB59` after supervisor validation normalized one UID link.
- Current IDA now has exact functions `MenuItem_GetBounds` at `[0x00516fb0,0x00516fc1)` and `MenuItem_SetBounds` at `[0x00516fd0,0x00516fe1)`, with the accepted prototypes, stack arguments, regular/function-repeatable comments, unchanged fences/bytes, and zero target/sibling incoming xrefs.
- Current live IDA UDTs already define `MenuItem` as `0x18` bytes with `RectBounds m_bounds` at `+0x04`, `bool m_enabled` at `+0x14`, `bool m_selected` at `+0x15`, and two tail-padding bytes at `+0x16`; `RectBounds` is `0x10` bytes with four `int` members.
- Current generated output at validator command `000000017234` has one nonempty UID0002JJ definition, one UID0002JK definition, and no empty marker for either, so these remain source-emitting methods rather than covered-by/no-code records.
- The manual by-memory coverage row is stale at `80%` and still says the final source name is unresolved. The source page is already `86/91`; this report recommends `92/94` after resolution.
- During the accepted callback B005 changed only the eight listed ordinary destinations and this report. Scoped validators and the waited refresh updated validator-owned generated/registry/projected state and propagated UID path links, including validator-managed link text in manual coverage; B005 made no direct manual coverage edit. IDA, audit/supervisor/goal state, and report lifecycle/archive state were not changed by B005.

## Executive Recommendation

Create and type the raw IDA function at the exact proven boundary, preserve it as a direct nonvirtual `MenuItem` member, rename the page and method to `GetBounds`, correct the return type to `RectBounds *`, and incorporate the exhaustive positive/negative evidence into the target and bounded support pages. The source-level operation is one rectangle assignment followed by returning the output pointer. Do not emit SSE intrinsics, `_OWORD`, raw offsets, a compiler helper, a covered-by marker, or a second body from the byte-identical comparator.

## Supervisor Active Recheck

- At `2026-07-24T09:31:55-04:00`, live MCP server health returned `status:ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and strings cache ready.
- Current MCP database session was `037f7d04`, active and not analyzing. The MCP transport session used for bounded calls was `96e2f257-7cfa-415e-b925-7d8a83d6c1e3`.
- Read-only IDB checkpoint at `2026-07-24T09:31:55-04:00`: SHA256 `A85394C8B4EB94DFFC1D9DD5D44C1C8137876263ABF5426F9EC919A81A0B7BF5`, `143185485` bytes, last write `2026-07-24T09:30:52.2647831-04:00`. This is an evidence-time shared-IDB checkpoint, not a perpetual current identity; unrelated supervisor saves may advance it.
- Fresh bounded calls used `server_health`, `lookup_funcs`, `entity_query`, `func_profile`, `analyze_batch`, `get_bytes`, `get_int`, `find_bytes`, `find`, `xrefs_to`, `xref_query`, `xrefs_to_field`, `type_query`, `stack_frame`, and `insn_query`.
- MCP remained available throughout the pass. B005 performed no IDA mutation, save, start, stop, restart, or process action.

## Inference Research Guidance Check

- Binary facts and source-shape inference are separated throughout this report.
- Missing original symbols are not used as an excuse to retain `sub_`, raw-offset, `_OWORD`, or behavior-label names in proposed source.
- The method name, return contract, parameter, constness, owner, source root, and retained-source disposition were each compared against adjacent methods, layout evidence, vtable evidence, exact duplicates, and accepted subsystem conventions.
- Runtime behavior has priority: exact receiver, stack argument, 16-byte copy, operation order, `EAX` state, and `retn 4` are preserved. Human source shape is then inferred as plausible late-1999 through mid-2000s MSVC C++.
- Style consistency is secondary to execution fidelity and human-looking source. `GetBounds`, `SetBounds`, `RectBounds`, `m_bounds`, and `outBounds` align with current accepted project vocabulary.
- No in-scope blocker is deferred as merely needing investigation. Residual uncertainties are lexical/source-history confidence caps with best current answers.

## Heuristic / Inference Reanalysis And Validation

- Retained out-of-line method versus inline/compiler helper: the target is isolated by exact `int3` fences, has a complete ordinary prologue/body/epilogue, sits directly beside four accepted nonvirtual `MenuItem` methods and its inverse `SetBounds`, and is emitted as its own 17-byte body. It is retained source-authored code. Zero surviving callers does not convert an intact source-family method into compiler glue.
- Duplicate-body analysis: exact body search returns only `0x00516fb0` and modeled `0x00554ae0`. The latter has ten code xrefs from nine live functions and belongs to a separate Region/Motion rectangle family. Identical optimized code proves a common rectangle-accessor source shape; it does not establish shared ownership, inlining, or covered-by status.
- Name ranking: `GetBounds` is strongest because the class already has `m_bounds`, the inverse body is `SetBounds`, current generated/class declarations already use this pair, and `GrafPort` uses accepted `GetBounds` vocabulary. `CopyBounds` describes implementation but is a weaker API name. `GetRect` is reserved by the separate Region/Motion comparator and conflicts with the current MenuItem API vocabulary.
- Return ranking: return-by-reference is rejected because the body copies to a caller pointer rather than exposing internal storage. A no-argument return-by-value API is rejected by the explicit `[EBP+8]` pointer and `retn 4`; a value-return hidden-sret lowering is ABI-possible but less consistent with the adjacent explicit pointer setter and accepted project getter conventions. `void GetBounds(RectBounds *)` is binary-compatible because the final store leaves the argument pointer in `EAX`, but accepted `GrafPort::GetBounds` has the same seven-instruction shape and source-facing pointer return. `RectBounds *GetBounds(RectBounds *) const` is therefore the highest-probability answer.
- Constness: the target reads `this+0x04` only. The output is nonconst; the receiver is const. The paired setter accepts a pointer to const input and writes the receiver.
- Layout: one unaligned 16-byte load/store is a whole `RectBounds` assignment. It is not four independent fields in source and not an SSE intrinsic in authored code.
- Virtuality: all seven current `MenuItem` vtable/COL cells from `0x0061eb98` through `0x0061ebb0` resolve to the destructor, inherited slots, purecalls, and the next COL. Neither `0x00516fb0` nor `0x00516fd0` appears. Both are nonvirtual direct members.
- Header/source placement: declaration belongs in the complete `MenuItem` class declaration; the out-of-line body belongs in the current `PopupMenuControls.cpp` source root. There is no binary or source artifact proving a physical `MenuItem.cpp` split now.

## Evidence Standards Used

- Direct IDA fact: current function/name/type/stack/xref/byte/instruction/vtable/UDT state from healthy live MCP.
- Direct raw-binary fact: PE section mapping, byte slices, SHA256, whole-file address-pattern scans, and `.text` relative-branch scans against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, `2679296` bytes.
- Documentation evidence: current by-memory/class/file/type/vtable/source-tree/manual/generated pages and matching archived B reports.
- Inference: source-facing spelling, pointer-return source contract, access declaration, and current physical source bucket. Each inference is ranked against rejected alternatives and confidence-capped below final symbol-proven range.
- Base conversions use `tools/int_convert.py` and are annotated where used.

## Evidence Checked

- Exact bytes at `[0x00516fb0,0x00516fc1)`: `55 8b ec 8b 45 08 0f 10 41 04 0f 11 00 5d c2 04 00`.
- Exact instructions: `push ebp`; `mov ebp, esp`; `mov eax, [ebp+8]`; `movups xmm0, xmmword ptr [ecx+4]`; `movups xmmword ptr [eax], xmm0`; `pop ebp`; `retn 4`.
- Exact boundary bytes from MCP: three `0xcc` bytes at `[0x00516fad,0x00516fb0)`, the 17-byte target, fifteen `0xcc` bytes at `[0x00516fc1,0x00516fd0)`, then the paired 17-byte setter.
- Local structured PE mapping: `.text` RVA `0x00001000`, raw pointer `0x00000400`, virtual size `0x0020b4ac`, raw size `0x0020b600`. Target VA/RVA/raw are `0x00516fb0` / `0x00116fb0` / `0x001163b0`; setter VA/RVA/raw are `0x00516fd0` / `0x00116fd0` / `0x001163d0`; duplicate VA/RVA/raw are `0x00554ae0` / `0x00154ae0` / `0x00153ee0`.
- `python .\tools\int_convert.py --text 17 --size 4 --single` returned decimal `17`, hex `0x11`, bytes `11 00 00 00`; `16` returned `0x10`; `3` returned `0x3`; `15` returned `0xf` `(Verified with int_convert.py)`.
- `python .\tools\int_convert.py --text 0x00516fb0 --size 4 --single` returned decimal `5337008` and bytes `b0 6f 51 00`; target RVA returned `b0 6f 11 00`; target raw offset returned `b0 63 11 00` `(Verified with int_convert.py)`.
- Whole-file raw scans found zero target/setter VA, RVA, or raw-offset four-byte patterns. MCP `find_bytes` independently found zero for all six patterns. A complete `.text` scan found zero `E8`/`E9`/near-conditional rel32 destinations to either start.
- MCP `find code_ref`, `data_ref`, and `immediate` returned zero for both starts. `xrefs_to` returned zero at both starts, both returns, both exclusive ends, and target/sibling padding boundaries. `xref_query both` found only each first instruction's internal fallthrough edge.
- `xrefs_to_field(MenuItem,m_bounds)` returned no IDA struct-field xrefs, which is expected because the raw functions are currently untyped; bounded instruction evidence and typed neighboring functions provide the field proof.
- Complete target-body search returned `0x00516fb0` and `0x00554ae0`; the setter-body search returned only `0x00516fd0`.
- Target and `0x00554ae0` share SHA256 `EA9AEECC35E759BF98B38B96CC4E91ED0B2D7916497F84EC4F663FDF693AB315`; setter SHA256 is `C21224F940494FD4BBCB8BBC163A8652492375B88E6A936AFAC51678977F7076`.
- `0x00554ae0` is a modeled 17-byte `sub_554AE0` with prototype `_OWORD *__thiscall(int this, _OWORD *)`, stack `arg_0` `_DWORD`, exact same seven instructions, ten xrefs, and nine unique caller functions. It is separate comparator evidence.
- Constructor `0x00516f00` initializes `this+4` through `InitRectBounds`; raw relayout instruction `0x00516da9` writes one xmmword to `[esi+4]`; `StringMenuItem::DrawItem` reads `[edi+4]`, `[edi+0x10]`, and passes `edi+4` as `RectBounds *`; separator construction initializes `esi+4`. These are independent producers/consumers of the same field.
- Live UDT query returned exact `MenuItem` size `24`/`0x18` and `RectBounds` size `16`/`0x10` with the accepted members.
- Live vtable dwords converted to `0x005172e0`, `0x004f4b10`, `0x0041b6c0`, and three `0x005ca28c` purecalls, followed at `0x0061ebb0` by the StringMenuItem COL pointer `0x0064b6d4`; neither bounds member is virtual `(Verified with int_convert.py)`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- | --- |
| C2JJ-01 | Exact target is `[0x00516fb0,0x00516fc1)`, 17/`0x11` bytes, SHA256 `EA9A...AB315`. | MCP bytes/disassembly; raw PE slice; int conversion. | UID0002JJ | incorporate | applied |
| C2JJ-02 | Exact fences are 3 predecessor and 15 successor `0xcc` bytes; neither fence belongs to the body. | MCP `get_bytes`/`insn_query`; ignored-range docs. | UID0002JJ, UID0001BK | incorporate | applied |
| C2JJ-03 | Body copies one 16-byte value from `this+4` to caller storage in exact load/store order. | Seven instructions; no branch/callee. | UID0002JJ, UID00007V, UID0001V5 | incorporate | applied |
| C2JJ-04 | ABI is `__thiscall`, const receiver in `ECX`, one `RectBounds *` stack argument, `retn 4`, output pointer retained in `EAX`. | Instruction sequence and comparator. | UID0002JJ | incorporate | applied |
| C2JJ-05 | Current IDA raw start/end have no function object, name, prototype, frame, or semantic comment. | `lookup_funcs`, `entity_query`, `stack_frame`, bounded disasm. | UID0002JJ report/IDA handoff | incorporate | applied |
| C2JJ-06 | No code/data/immediate/xref route survives to target or setter. | `xrefs_to`, `xref_query`, `find`. | UID0002JJ, UID0002JK | incorporate | applied |
| C2JJ-07 | No target/setter VA, RVA, raw-offset, member-pointer, or vtable pointer route survives. | MCP `find_bytes`; whole-file raw scans; vtable reads. | UID0002JJ, UID0002JK, UID0001Y4 | incorporate | applied |
| C2JJ-08 | No direct rel32 branch/call reaches either raw start. | Whole `.text` E8/E9/Jcc rel32 scan. | UID0002JJ, UID0002JK | incorporate | applied |
| C2JJ-09 | Exact target body has one byte-identical comparator at `0x00554ae0`; setter body is unique. | Full-body `find_bytes`; SHA256. | UID0002JJ | incorporate | applied |
| C2JJ-10 | Comparator is a separate live modeled function with ten xrefs/nine callers, not target ownership or covered-by proof. | `func_profile`, `analyze_batch`, xrefs, Region/Motion docs. | UID0002JJ, UID0001BK | incorporate | applied |
| C2JJ-11 | Target is retained out-of-line source-authored code, not compiler glue or inline-only code. | Fences, family adjacency, inverse setter, exact body, generated body. | UID0002JJ | incorporate | applied |
| C2JJ-12 | Direct semantic owner/emitter remains MenuItem UID00007V. | Receiver layout, adjacent MenuItem methods, class declaration. | UID0002JJ | already-present | already-present |
| C2JJ-13 | Current source root remains PopupMenuControls UID0000MN. | Family locality, source tree, no proven physical split. | UID0002JJ, UID0000MN | already-present | already-present |
| C2JJ-14 | `this+4` is exact `RectBounds m_bounds`; object is `0x18` bytes. | Live UDTs, constructor, relayout, draw consumers. | UID0002JJ, UID00007V, UID0001V5 | incorporate | applied |
| C2JJ-15 | Bounds producers/consumers include constructors, relayout `0x516da9`, and StringMenuItem draw. | Fresh bounded MCP instruction reads. | UID0002JJ, UID0001BK, UID0001V5 | incorporate | applied |
| C2JJ-16 | Getter/setter are nonvirtual. | Exact MenuItem vtable cells; no pointer hits. | UID0002JJ, UID0002JK, UID0001Y4, UID00036I | incorporate | applied |
| C2JJ-17 | Highest-probability method name is `GetBounds`; `CopyBounds` and `GetRect` are rejected alternatives. | Paired `SetBounds`, class API, GrafPort convention, separate comparator family. | UID0002JJ, UID00007V | incorporate | applied |
| C2JJ-18 | Highest-probability return is `RectBounds *`, returning `outBounds`. | `EAX` retention and byte-identical accepted GrafPort getter convention. | UID0002JJ, UID00007V | incorporate | applied |
| C2JJ-19 | Signature is const receiver plus nonconst output pointer; return-by-reference and no-arg value return are rejected. | Read-only receiver, explicit stack pointer, copy semantics. | UID0002JJ | incorporate | applied |
| C2JJ-20 | Exact formal is the complete pointer-return `GetBounds` block below. | Behavior/ABI/source inference. | UID0002JJ | incorporate | applied |
| C2JJ-21 | Sibling is retained `void SetBounds(const RectBounds *)`; behavior-label filename/source uncertainty is stale. | Exact inverse body and family analysis. | UID0002JK | incorporate | applied |
| C2JJ-22 | Complete class declaration must use `RectBounds *GetBounds(RectBounds *outBounds) const;`. | Target formal and existing class API. | UID00007V | incorporate | applied |
| C2JJ-23 | UID0002JJ should become `92/94`; owner/emitter/reconstructable/position/nesting remain. | Closed evidence blockers and residual caps. | UID0002JJ | incorporate | applied |
| C2JJ-24 | UID0002JK should become `90/93`; same owner/emitter/reconstructable/position/nesting. | Paired exact evidence; lower support-only ceiling. | UID0002JK | incorporate | applied |
| C2JJ-25 | UID00007V should become `91/93`; source root/aggregate/layout/vtable scores remain unchanged. | Finalized bounds API improves class completeness without resolving physical file split. | UID00007V and supports | incorporate | applied |
| C2JJ-26 | Prior no-final-C++, unresolved-name, source-authored-or-inline, and 95+ code-gate statements are historical/stale. | Current formal, current by-structure rule, this evidence pass. | UID0002JJ, UID0002JK | historicalize | applied |
| C2JJ-27 | UID-preserving target/sibling page renames improve source-facing identity. | Resolved method names and durable UID rules. | UID0002JJ, UID0002JK and references | incorporate | applied |
| C2JJ-28 | IDA can safely create exact target/sibling functions without absorbing alignment. | Complete instruction bodies and empty modeled ranges. | Supervisor Gate 2B | incorporate | applied-verified |
| C2JJ-29 | IDA should name/type/comment target and sibling; UDTs/vtables remain no-change. | Exact handoff table below. | Supervisor Gate 2B | incorporate | applied-verified |
| C2JJ-30 | Comparator `0x00554ae0` remains protected/no-change in this target pass due separate ownership/type conflict. | Live current Motion UDT and separate Region/Motion docs. | Supervisor Gate 2B | reject-invalid | excluded-with-reason |
| C2JJ-31 | Manual memory/class rows are stale and need exact supervisor replacements. | Read-only manual coverage comparison. | Manual coverage files | incorporate | proposed |
| C2JJ-32 | Generated output should contain one renamed UID0002JJ body, one UID0002JK body, and zero target empty markers after callback. | Current generated baseline and route. | Generated readback | incorporate | applied |
| C2JJ-33 | No split, merge, new child, new owner, or covered-by route is warranted. | Exact range/body/owner/source evidence. | All destinations | reject-invalid | excluded-with-reason |
| C2JJ-34 | Stale Wave2/Wave3 material is not current evidence. | Project skill and current by-structure guidance. | Report/support history | reject-stale | excluded-with-reason |

## Positive Evidence Summary

- The exact body is a conventional source-method leaf with ordinary frame setup, a single whole-object assignment, and ordinary stack cleanup.
- Exact adjacent functions form a coherent nonvirtual `MenuItem` API: `IsEnabled`, `SetEnabled`, `IsSelected`, `SetSelected`, target getter, and inverse setter.
- Current accepted UDTs, constructor initialization, relayout writes, and draw reads all agree that `+0x04..+0x13` is one `RectBounds m_bounds` object.
- The accepted class declaration and generated translation unit already use `GetBounds`/`SetBounds`, giving strong local naming consistency.
- The byte-identical live comparator and accepted `GrafPort::GetBounds` establish that this seven-instruction form is normal human-authored rectangle-accessor code after MSVC optimization.
- Exact vtable exclusion establishes nonvirtual placement; exact owner/emitter chains reach a valid source root and generated body.

## IDA MCP Facts

- Active database session: `037f7d04`; health `ok`; module `NexusTK.exe`; image base `0x00400000`.
- `lookup_funcs` returned `Not a function` for target start, return, exclusive end, sibling start, sibling return, and sibling exclusive end. It returned modeled `sub_554AE0`, size `0x11`, for the comparator.
- `entity_query` over `0x00516f00-0x00517000` returned modeled functions at `0x00516f00`, `0x00516f70`, `0x00516f80`, `0x00516f90`, `0x00516fa0`, and `0x00516ff0`, with no target/sibling name.
- `insn_query` decoded target and sibling completely despite absent function objects and represented all intervening `0xcc` fences as alignment.
- `func_profile` typed neighboring methods as `bool __thiscall(const MenuItem *this)` and `void __thiscall(MenuItem *this, bool ...)`, supporting the same member-family ABI.
- Current `MenuItem` and `RectBounds` UDT declarations/members are exact as listed above. No UDT mutation is needed.
- Current MenuItem vtable names `??_7MenuItem@@6B@`, `??_7StringMenuItem@@6B@`, and `??_7SeparatorMenuItem@@6B@` are decorated compiler identities and must be preserved.
- Current comparator `sub_554AE0` has raw prototype `_OWORD *__thiscall(int this, _OWORD *)` and stack `arg_0` `_DWORD`; this report does not authorize changing it because its separate source owner/type merits its own Gate 2B continuity check.

## Function / Child Inventory

| Range | Current IDA state | Source-facing role | Disposition |
| --- | --- | --- | --- |
| `0x00516f70-0x00516f74` | modeled `MenuItem_IsEnabled`, 4 bytes | `bool MenuItem::IsEnabled() const` | accepted neighboring nonvirtual method |
| `0x00516f80-0x00516f8d` | modeled one-byte-size function entry plus raw decoded tail | `void MenuItem::SetEnabled(bool)` | accepted neighboring nonvirtual method |
| `0x00516f90-0x00516f94` | modeled `MenuItem_IsSelected`, 4 bytes | `bool MenuItem::IsSelected() const` | accepted neighboring nonvirtual method |
| `0x00516fa0-0x00516fad` | modeled one-byte-size function entry plus raw decoded tail | `void MenuItem::SetSelected(bool)` | accepted neighboring nonvirtual method |
| `0x00516fad-0x00516fb0` | alignment | three `int3` bytes | exclude from target |
| `0x00516fb0-0x00516fc1` | decoded raw code, no function | `RectBounds *MenuItem::GetBounds(RectBounds *) const` | primary target; create/type/name in IDA |
| `0x00516fc1-0x00516fd0` | alignment | fifteen `int3` bytes | exclude from both methods |
| `0x00516fd0-0x00516fe1` | decoded raw code, no function | `void MenuItem::SetBounds(const RectBounds *)` | paired support; create/type/name in IDA |
| `0x00516fe1-0x00516ff0` | alignment | fifteen `int3` bytes | exclude from setter/successor |
| `0x00554ae0-0x00554af1` | modeled `sub_554AE0`, 17 bytes | separate Region/Motion rect getter comparator | no owner merge; protected support |

## Direct Xref / Caller Inventory

- UID0002JJ target: zero incoming xrefs at start, return, and exclusive end; zero `find` code/data/immediate matches; zero VA/RVA/raw pointer patterns; zero `.text` direct rel32 routes.
- UID0002JK sibling: same all-zero route result at start, return, and exclusive end.
- `xref_query both` at each raw start reports only its internal first-instruction fallthrough; this is not an external caller.
- Target field producers/consumers are offset-based rather than calls to the raw accessor: constructor `0x00516f34`/`InitRectBounds`, raw relayout store `0x00516da9`, StringMenuItem draw reads at `0x00517117`, `0x00517136`, and `0x00517172`, and separator constructor initialization at `0x005171e4`.
- Comparator `0x00554ae0` has ten xrefs from nine caller functions: `GrafPort_GetClipRect`, `Layer_RenderRecursive` twice, `Layer_UpdateDirtyRegionsRecursive`, `MapPane_OnPaint`, `sub_50C240`, `sub_50DE10`, `ScreenPane_RenderPresentation`, `sub_5583A0`, and `sub_55B2D0`.
- The target's no-caller state is therefore a genuine retained binary fact, not MCP failure or broad-query omission.

## Documentation Evidence And IDA Status

- Assignment-time target/sibling pages contained strong byte/range evidence but retained stale unresolved-source prose and historical claims that prior semantic comments were saved. The callback historicalized that prose while preserving fresh bounded IDA readback showing no semantic regular/repeatable comment at either raw start; the old save claim remains historical evidence, not current state.
- UID00007V already defined `m_bounds` and formerly declared a void getter/setter pair. The callback corrected only the getter return/declarator and method-map/support wording while preserving unrelated class members and children.
- UID0001V5 already had the exact `0x18` layout and required no score or emitted-type change; the callback added bounded confirmation that the getter/setter use the accepted field and whole-object assignment.
- UID0001Y4/UID00036I already proved the methods are not vtable slots. The callback added exact bounded no-slot evidence while preserving compiler-generated/decorated vtable handling; the stale by-vtable manual row's old 95/95 blank-C++ claim still requires supervisor correction.
- UID0000MN and proposed source tree already choose `PopupMenuControls.cpp`; no new file/source-tree edit is justified.
- Assignment-time generated output proved the route was live but contained the weaker void-return draft and historical path marker. Current command-17234 output contains the corrected pointer-return getter, preserved setter, current paths/scores, and no target/setter empty marker.

## Ranked Ownership Analysis

### Candidate 1 - MenuItem UID00007V

- Rank: accepted, very strong.
- Evidence: exact receiver layout, adjacent MenuItem method family, paired getter/setter, class declaration, field producers/consumers, and generated route.
- Result: direct canonical owner and emitter.

### Candidate 2 - PopupMenuControls UID0000MN

- Rank: accepted only as source-file root.
- Evidence: contiguous menu-item family, current proposed source tree, and complete generated translation unit.
- Result: indirect file owner through UID00007V; do not bypass the class emitter.

### Candidate 3 - Region/Motion Comparator Family

- Rank: rejected as target owner.
- Evidence for comparison only: exact duplicate bytes at `0x00554ae0` and documented rectangle-getter role.
- Rejection: different address, modeled function, ten xrefs, separate object/type/source family, and no route joining it to MenuItem.

### Candidate 4 - Compiler-Generated Copy Helper Or Inline-Only Body

- Rank: rejected.
- Rejection: ordinary isolated method body, exact inverse setter, source-family adjacency, unique retained target copy, and valid owner/emitter/generated body.

## Source Placement

- Header declaration: complete `MenuItem` class declaration currently emitted by [UID:00007V].
- Definition: current `NexusTK/ui/menu/PopupMenuControls.cpp` source root under [UID:0000MN].
- Historical possibility: `MenuItem.h`/`MenuItem.cpp` may have existed separately, as current file/source-tree docs already note. No binary artifact or surviving source proves that split, so the current consolidated route is the highest-probability actionable choice.
- Do not place the target in Region/Motion, GrafPort, generic rectangle utilities, a compiler-helper file, the vtable data page, or the aggregate page.

## Range / Split / Padding / Reclassification Analysis

- Keep one exact method page for `[0x00516fb0,0x00516fc1)`; rename it by UID without changing bounds.
- Keep one exact sibling page for `[0x00516fd0,0x00516fe1)`; rename it by UID without changing bounds.
- Preserve predecessor `[0x00516fad,0x00516fb0)`, inter-method `[0x00516fc1,0x00516fd0)`, and successor `[0x00516fe1,0x00516ff0)` as alignment owned by the ignored/padding documentation, not by either method.
- No split, merge, range extension, child creation, aggregate absorption, or covered-by relation is warranted.
- The target remains reconstructable and source-emitting. Reclassifying it as nonreconstructable or compiler-generated would lose authored API behavior.

## Negative Evidence Summary

- No surviving direct caller, code xref, data xref, immediate, VA pointer, RVA pointer, raw-offset pointer, member-pointer, vtable slot, or rel32 branch reaches the target or sibling.
- No original PDB/source symbol proves lexical spelling or return declaration.
- IDA currently has no target/sibling function object, stack frame, signature, name, or semantic comment.
- The byte-identical comparator is not evidence of common ownership or inlining; its separate live caller set rejects that shortcut.
- The target has no branch, callee, EH region, cleanup, local object, jump table, string, global, or hidden data island.
- These negatives cap confidence below 95 but do not block a high-probability source reconstruction because behavior, bounds, class, field, method pair, source root, and generated route are independently strong.

## IDA Rename / Type / Comment Recommendations

B005 made no IDA mutation. The following is the complete supervisor Gate 2B handoff from current live readback. Every actionable row has one exact entity/address or range.

| Entity/address | Exact current pre-state | Proposed supervisor action | Safety constraint/evidence | Expected APPLIED_VERIFIED readback |
| --- | --- | --- | --- | --- |
| Function range `[0x00516fb0,0x00516fc1)` | Defined instructions; no function object at start/interior/end; name absent; declaration absent; frame/local state absent; regular comment absent; repeatable comment absent. | Create exactly one function with start `0x00516fb0`, exclusive end `0x00516fc1`. | Do not absorb `0x00516fad-0x00516fb0` or `0x00516fc1-0x00516fd0` alignment. Exact seven instructions end in `retn 4`. | Function exists exactly at `0x00516fb0`, size `0x11`, end `0x00516fc1`; both fences remain alignment. |
| Function `0x00516fb0` | After current readback: no function/name/type. Current decoded operands are `[ebp+8]`, `[ecx+4]`, and `[eax]`; comments absent. | Rename to `MenuItem_GetBounds`; apply `RectBounds *__thiscall MenuItem_GetBounds(const MenuItem *this, RectBounds *outBounds)`. | Use one underscore to match current `MenuItem_IsEnabled`/`SetEnabled` IDA style. Do not use C++ decorated name or `_OWORD`. | Name and exact prototype read back; decompile shows `m_bounds`/`RectBounds` copy and pointer return. |
| Stack argument at `0x00516fb0`, offset `+0x08` | No frame exists; decoded access is raw `[ebp+8]`. | Name `outBounds`, type `RectBounds *`, after function creation/type application. | One 4-byte explicit argument; `retn 4`; destination is written. | Stack frame shows `outBounds` at `+0x08`, size 4, type `RectBounds *`. |
| Comments at `0x00516fb0` | Regular comment: absent. Repeatable comment: absent. Function comment: unavailable because no function exists. | Regular: `MenuItem::GetBounds copies m_bounds (+0x04, 16 bytes) to outBounds and returns outBounds.` Repeatable: `Retained nonvirtual MenuItem bounds getter; exact range 0x00516fb0-0x00516fc1; no surviving direct/pointer/vtable route.` | Apply after exact function creation; do not claim original symbol provenance. | Both literal comments read back at the target function/start. |
| Function range `[0x00516fd0,0x00516fe1)` | Defined instructions; no function object at start/interior/end; name/declaration/frame absent; regular/repeatable comments absent. | Create exactly one function at `0x00516fd0`, exclusive end `0x00516fe1`. | Do not absorb either 15-byte alignment fence. Exact seven instructions end in `retn 4`. | Function exists at `0x00516fd0`, size `0x11`, exact end `0x00516fe1`; fences unchanged. |
| Function `0x00516fd0` | No function/name/type. Decoded operands are `[ebp+8]`, `[eax]`, and `[ecx+4]`; comments absent. | Rename to `MenuItem_SetBounds`; apply `void __thiscall MenuItem_SetBounds(MenuItem *this, const RectBounds *bounds)`. | Paired inverse of target; do not infer a return value from incidental `EAX`. | Name/prototype read back; decompile shows assignment to `m_bounds`. |
| Stack argument at `0x00516fd0`, offset `+0x08` | No frame exists; decoded access is raw `[ebp+8]`. | Name `bounds`, type `const RectBounds *`. | Source is read only; receiver is written. | Frame shows `bounds` at `+0x08`, size 4, exact const pointer type. |
| Comments at `0x00516fd0` | Regular comment: absent. Repeatable comment: absent. Function comment unavailable. | Regular: `MenuItem::SetBounds copies the caller RectBounds into m_bounds (+0x04, 16 bytes).` Repeatable: `Retained nonvirtual MenuItem bounds setter; exact range 0x00516fd0-0x00516fe1; no surviving direct/pointer/vtable route.` | Apply after exact function creation; do not claim original symbol provenance. | Both literal comments read back at the sibling function/start. |
| UDT `MenuItem` | Size `0x18`; `lpVtbl +0x00`, `RectBounds m_bounds +0x04`, bools `+0x14/+0x15`, padding `+0x16`. | No change. | Exact current layout is sufficient and used by proposed signatures. | Same size/member names/types/offsets read back. |
| UDT `RectBounds` | Size `0x10`; four `int` members at `+0x00/+0x04/+0x08/+0x0c`. | No change. | Exact whole-field copy matches this type. | Same declaration and members read back. |
| MenuItem vtable run `0x0061eb98-0x0061ebb0` | Decorated names preserved; values resolve to `0x005172e0`, `0x004f4b10`, `0x0041b6c0`, three `0x005ca28c` purecalls, then StringMenuItem COL. | No change to names, types, comments, or bytes. | Target and sibling are nonvirtual and absent from the run. | Decorated identities and exact dwords unchanged. |
| Comparator `0x00554ae0` | Modeled `sub_554AE0`, size `0x11`; prototype `_OWORD *__thiscall(int this, _OWORD *)`; stack `arg_0` `_DWORD`; regular/repeatable comments absent; ten xrefs. | Protected no-change in this report. | Separate Region/Motion ownership and current `Motion` UDT conflict require its own exact owner/type continuity audit; do not use it to cover or rename UID0002JJ. | Identity/type/comments/bytes remain unchanged during UID0002JJ Gate 2B. |

### Supervisor Gate 2B Execution Record

- Session/path: healthy live IDA MCP session `1ce787ed`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Backup before mutation: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0002JJ-20260724-101600.bak`, 143,186,885 bytes, SHA256 `BB95C8268208A62AC39955CE34A7D51495523F606500124C955CFB0D0AFCBFC7`.
- Exact prestate matched the handoff: target and sibling had decoded instruction items but no function, name, prototype, frame, or comments; comparator remained `sub_554AE0` with `_OWORD *__thiscall(int this, _OWORD *)`, `arg_0`, no comments, and ten xrefs; `MenuItem` and `RectBounds` layouts matched exactly.
- Applied target: created exactly `[0x00516fb0,0x00516fc1)`, renamed `MenuItem_GetBounds`, applied `RectBounds *__thiscall MenuItem_GetBounds(const MenuItem *this, RectBounds *outBounds)`, declared stack argument `outBounds` at `+0x08` as `RectBounds *`, and applied both literal comments.
- Applied sibling: created exactly `[0x00516fd0,0x00516fe1)`, renamed `MenuItem_SetBounds`, applied `void __thiscall MenuItem_SetBounds(MenuItem *this, const RectBounds *bounds)`, declared stack argument `bounds` at `+0x08` as `const RectBounds *`, and applied both literal comments.
- Readback: both functions are exactly `0x11` bytes; decompilation resolves `this->m_bounds`, the getter pointer return, and the setter assignment. Stack names/types and regular/function-repeatable comments match the handoff. Target and sibling incoming-xref counts remain zero.
- Integrity/protection: `[0x516fad,0x516ff0)` remains SHA256 `05F0CC556F377233B228CB450C40521722704C7141028C70ADA72C07066173DB`; all three alignment fences retain exact sizes. Comparator bytes remain SHA256 `EA9AEECC35E759BF98B38B96CC4E91ED0B2D7916497F84EC4F663FDF693AB315`, its identity/type/comments/ten xrefs are unchanged, and MenuItem vtable bytes remain SHA256 `8529E32DFF98D0573C592FA4BD9BFB345172597457521507930B40B3DB3AE959`. `MenuItem` and `RectBounds` UDTs remain unchanged.
- Save: `idb_save` returned `ok:true`; saved IDB is 143,185,386 bytes, timestamp `2026-07-24 10:17:16 -04:00`, SHA256 `8C59555478FAD4C784B992478CA08E805AEC276D9A848BB7923FA4F8BD481ED1`.
- Gate result: C2JJ-28 and C2JJ-29 are `APPLIED_VERIFIED`; C2JJ-30 is `NO_CHANGE_VERIFIED`. No range was broadened and no protected entity was modified.

## First-Draft C++ Recommendation

Exact complete replacement content for UID0002JJ `RECONSTRUCTION_CPP CODE`:

```cpp
RectBounds *MenuItem::GetBounds(RectBounds *outBounds) const
{
    *outBounds = m_bounds;
    return outBounds;
}
```

- Exact behavior: one 16-byte copy from receiver offset `+0x04` to the explicit output pointer; no validation, branch, callback, side effect, or state update.
- ABI: `ECX` receiver, one 4-byte stack argument, caller cleanup encoded by `retn 4`, and returned pointer in `EAX`.
- Source quality: ordinary C++03 member definition; no `_OWORD`, `movups`, raw address, synthetic helper, decompiler local, or explicit SSE.
- Header declaration to install in UID00007V: `RectBounds *GetBounds(RectBounds *outBounds) const;`.
- The current sibling formal remains exact destination content after its UID-preserving rename:

```cpp
void MenuItem::SetBounds(const RectBounds *bounds)
{
    m_bounds = *bounds;
}
```

- Reason code is nonblank: the target is reconstructable, has a confirmed emitter route through UID00007V to UID0000MN, clears the combined score gate, and represents retained source-authored behavior.

## Final Recommendation

- The accepted callback applied C2JJ-01 through C2JJ-27 and C2JJ-32 without summary loss, preserved C2JJ-12/13 as already-present routing, and recorded C2JJ-30/33/34 as excluded with exact reasons.
- The target and sibling UID-preserving renames, pointer-return target formal/header, exact scores, unchanged owner/emitter/range routes, support-page evidence, and waited generated output are complete.
- Exact route negatives, duplicate classification, field producers/consumers, vtable exclusion, source placement, rejected alternatives, and historical B008/older assumptions are present in the ordinary destinations at report-level specificity.
- C2JJ-28/29 are applied and independently verified in IDA; C2JJ-31 remains proposed for supervisor-owned manual coverage. Report execution/archive remain pending.

## Recommended Target Doc Changes

- Assignment-time path: `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md`.
- Implemented path: `by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md` with UID0002JJ preserved.
- Metadata: `COMPLETION:92`, `CONFIDENCE:94`, owner `00007V`, reconstructable true, emitter `00007V`, blank position, `Nested:0`.
- Replace the managed C++ block with the exact pointer-return formal above.
- Replace Item Summary with: `Exact 17-byte retained nonvirtual MenuItem::GetBounds leaf copying the 16-byte m_bounds field at +0x04 to caller storage and returning that output pointer; exact int3 fences, exhaustive no-route proof, paired SetBounds API, byte-identical separate comparator, owner/emitter, and PopupMenuControls source route are resolved.`
- Add exact PE VA/RVA/raw/hash, seven-instruction body, all-route negatives, duplicate/caller comparison, constructor/relayout/draw field evidence, vtable exclusion, source-signature ranking, IDA current state, and generated baseline.
- Historicalize old claims that no formal C++ exists, source name is unresolved, source-authored versus inline is open, 95+ is required, and an old saved comment is current.

## Recommended Support Doc Changes

- `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md`: UID-preserving rename implemented; now `90/93` with the same owner/emitter/reconstructable/position/nesting, exact void formal, exhaustive paired route/body/fence/source-name evidence, and historicalized unresolved/no-C++ prose.
- `by-class/MenuItem.md`: `91/93`; change only getter declaration to `RectBounds *GetBounds(RectBounds *outBounds) const;`; retain setter; identify exact UID0002JJ/UID0002JK names and nonvirtual roles; add return/source/range evidence; preserve all unrelated class content and `[[CHILDREN]]` placement.
- `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`: keep `88/90`; update exact child links/titles and add bounded retained bounds-API/duplicate/no-route conclusions without duplicating method bodies.
- `by-type/by-struct/MenuItemLayouts.md`: keep `89/92`; add bounded live UDT and whole-object getter/setter evidence; preserve support structs/formal.
- `by-type/by-vtable/MenuItemVtables.md`: keep `86/91`; add explicit nonvirtual exclusion of UID0002JJ/UID0002JK; remove no current content. Preserve compiler-generated vtable policy and decorated symbols.
- `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`: keep `86/91`; add only the bounded no-slot proof if needed; do not emit or change raw vtable C++.
- `by-file/PopupMenuControls.md`: keep `86/85`; add finalized bounds-pair/source-root evidence while preserving physical-split uncertainty and all unrelated popup work.
- `by-project-structure/proposed-source-tree.md`: already says PopupMenuControls owns MenuItem; no edit required unless concurrent content contradicts that state.
- `by-memory/-ignored.md`: exact padding is already represented; no content change required beyond validator-managed link propagation after renames.

## Score And Metadata Recommendation

- UID0002JJ assignment-time baseline: `86/91`, owner/emitter `00007V`, reconstructable true, nonblank void formal, blank position, `Nested:0`.
- UID0002JJ current callback state: `92/94`, same routing/state, pointer-return formal, UID-preserving source-facing page rename.
- UID0002JK assignment-time/current callback state: `86/91` -> `90/93`, same routing/state and formal, UID-preserving source-facing page rename.
- UID00007V assignment-time/current callback state: `90/92` -> `91/93`; owner/emitter/file route unchanged.
- UID0000MN stays `86/85`; UID0001BK stays `88/90`; UID0001V5 stays `89/92`; UID0001Y4 and UID00036I stay `86/91`.
- Reason not higher: stripped original symbols do not prove lexical spelling or pointer-return declaration; no target/sibling caller survives; physical `MenuItem.cpp` split is not proven. These are confidence caps, not unresolved behavior/ownership/code blockers.
- Reason not lower: exact bytes/hash/bounds/fences/ABI/field/owner/emitter are proven; route searches are exhaustive; inverse method and class API resolve naming; current UDTs resolve types; accepted GrafPort comparator resolves the strongest return convention; generated source route is live.
- Score-improvement attempt: every former blocker was directly investigated. Caller/reachability became exhaustive all-zero route evidence; source-authored status was resolved from family/range/duplicate evidence; name from paired API; return from ABI/comparator; type/member from live UDT and field consumers; virtuality from exact vtable reads; source placement from current family/source tree. The target therefore moves materially.

## Open Questions With Attempted Resolution

- Original method spelling: no PDB/source symbol survives. `GetBounds` is accepted at high probability from the inverse `SetBounds`, existing class/generated vocabulary, `m_bounds`, and subsystem `GrafPort::GetBounds`; `CopyBounds` and `GetRect` are rejected.
- Original return declaration: `void` and pointer-return can compile to this leaf because the output pointer is already in `EAX`. The accepted byte-identical GrafPort getter and conventional chaining-friendly API make `RectBounds *` the strongest answer. The residual ambiguity caps confidence but does not justify retaining the weaker draft.
- Retained liveness without callers: exhaustive MCP and raw PE routes are zero. Family adjacency, exact fences, inverse setter, and intact generated-source API make retained unreferenced source the best answer; dead padding/compiler glue are rejected.
- Physical source file: current `PopupMenuControls.cpp` is accepted because all family evidence and project source-tree routing converge there. A separate historical `MenuItem.cpp` remains possible but unproven and does not block current reconstruction.
- Byte-identical comparator owner/type: current docs call it Region/Motion `GetRect`, while current live `Motion` UDT does not itself expose a `RectBounds` at `+0x04`. This separate-family type issue is explicitly protected from this target's IDA action. It does not weaken the comparator's byte-shape evidence or transfer ownership.
- Remaining unresolved blocking questions: none.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The following current manual rows were inspected read-only: UID0002JJ/UID0002JK/UID0001BK in `by-memory/-coverage-report.md`, UID00007V in `by-class/-coverage-report.md`, UID0000MN in `by-file/-coverage-report.md`, UID0001V5 in `by-type/by-struct/-coverage-report.md`, and UID0001Y4 in `by-type/by-vtable/-coverage-report.md`. B005 must not edit them.

File/placement: `by-memory/-coverage-report.md`. Replace UID0002JJ row with:

```text
        - [UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemGetBounds](by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md) 0x00516fb0-0x00516fc1 | method/accessor | MenuItemGetBounds : reconstructable : 92% : very-strong : Exact 17-byte retained nonvirtual MenuItem::GetBounds leaf copying RectBounds m_bounds at +0x04 to caller storage and returning that pointer; exact int3 fences, SHA256, exhaustive no-xref/pointer/rel32/vtable routes, paired SetBounds API, separate byte-identical live comparator, owner/emitter UID00007V, and PopupMenuControls source route are resolved with complete formal C++.
```

Replace UID0002JK row with:

```text
        - [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBounds](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md) 0x00516fd0-0x00516fe1 | method/setter | MenuItemSetBounds : reconstructable : 90% : very-strong : Exact 17-byte retained nonvirtual MenuItem::SetBounds leaf copying a const caller RectBounds into m_bounds at +0x04; exact int3 fences, unique body, exhaustive no-xref/pointer/rel32/vtable routes, paired GetBounds API, owner/emitter UID00007V, and PopupMenuControls source route support the existing complete formal C++.
```

Replace UID0001BK row with:

```text
    - [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md) 0x00516290-0x00517441 | aggregate/class-method-cluster | MenuPaneAndItems : reconstructable : 88% : strong : PopupMenuControls MenuPane/MenuItem aggregate with exact modeled/raw/table/padding inventory, retained nonvirtual enabled/selected and GetBounds/SetBounds APIs, exact MenuItem layout/vtable/compiler distinctions, constructor/relayout/draw field evidence, source route through UID0000MN, and non-duplicating aggregate marker; exact child pages own all method bodies.
```

File/placement: `by-class/-coverage-report.md`. Replace UID00007V row with:

```text
- [UID:00007V][MenuItem](by-class/MenuItem.md) : reconstructable : 91% : very-strong : Complete abstract LObject-derived MenuItem declaration and 0x18 layout with RectBounds m_bounds at +0x04, bool m_enabled/m_selected at +0x14/+0x15, natural tail padding, exact constructor/state/bounds/destructor children, retained nonvirtual RectBounds-returning GetBounds and const-pointer SetBounds pair, compiler vtable/deleting-wrapper separation, UID0000MN source route, and class closure before child definitions; original lexical spellings and physical MenuItem.cpp split remain bounded confidence caps.
```

File/placement: `by-file/-coverage-report.md`. Replace UID0000MN row with:

```text
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) : reconstructable : 86% : strong : Consolidated NexusTK/ui/menu/PopupMenuControls.cpp source root for PopupMenuControlPane, MenuPane, MenuItem, StringMenuItem, and SeparatorMenuItem; exact MenuItem enabled/selected and retained nonvirtual GetBounds/SetBounds APIs, complete class declarations, menu-item layout/vtable/compiler distinctions, current popup support, and generated no-empty-marker route are documented while preserving the plausible later MenuPane.cpp/MenuItem.cpp physical split as the source-placement confidence cap.
```

File/placement: `by-type/by-vtable/-coverage-report.md`. Replace UID0001Y4 row to remove its stale blank-below-95 claim:

```text
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md) : reconstructable : 86% : strong : Exact MenuItem/StringMenuItem/SeparatorMenuItem COL pointers, decorated vtable bases, slot targets, constructor/destructor vptr-store xrefs, exact data child UID00036I, and MENUBACK.EPF successor boundary; GetBounds/SetBounds are proven nonvirtual and absent from the tables, while compiler-generated vtable bytes remain regenerated from source declarations rather than handwritten.
```

No replacement is required for the UID0001V5 by-struct row; it already accurately describes the layout and score. Generated `auto-generated/-ag-*` rows must refresh only through validator operations after callback.

## Follow-Up Actions

- Supervisor Gate 1 accepted exact pre-callback SHA `01251141151C20D0ADE43944BA725B8D08A3B5DAACACA98AAFD50D5B46BF0597`, and B005 completed the ordinary callback.
- Supervisor completed fresh exact-artifact Gate 1 review and Gate 2A claim-by-claim verification of every destination/hash/validator/generated result.
- Supervisor applied and read back the exact C2JJ-28/29 Gate 2B IDA handoff with backup/save evidence; B005 made no IDA mutation.
- Supervisor must apply/validate the exact C2JJ-31 manual coverage payloads, then execute/archive only through the validator lifecycle after all gates pass.
- A-agent actions: none.
- B005 future research: none before supervisor final review; do not run or probe lifecycle commands.

## Confidence

- Recommendation confidence: `94/100` for exact behavior/range/type/owner/emitter/source disposition and `91/100` for the pointer-return lexical source contract.
- Score confidence: high for `92/94`; the values reflect resolved implementation blockers and retain a real sub-95 symbol/source-history cap.
- Remaining uncertainty: original PDB spelling, ABI-equivalent void versus pointer return, and physical MenuItem.cpp split. Best current answers are supplied for all three; none blocks implementation.
- Blocking open questions: `0`.

## Validator Results

- Historical report-only pass: no validator was run; its generated checkpoint was `C3462CF93ADA6AEBCAB8A7F002B66E380F2D36FA859D3661A16F51E958457C42` with one UID0002JJ body and zero target empty markers.
- Callback scoped validators all exited `0` with `ok: 1`: target/path command `000000017224`; setter/path `000000017227`; UID00007V `000000017228`; UID0001BK `000000017229`; UID0001V5 `000000017230`; UID0001Y4 `000000017231`; UID00036I `000000017232`; UID0000MN `000000017233`.
- Waited target validation command `000000017234` exited `0`, `ok: 1`, rebuilt validator registry/reference state, refreshed generated metadata, and completed foreground generated refresh at `2026-07-24T09:58:47-04:00`.
- Waited generated readback: `PopupMenuControls.cpp` SHA256 `99528B117750A9EB3A85811A6EFA2A461E51D36EAF3D51B1629D078122267A29`, `15107` bytes, `436` lines, header command `000000017234`, one UID0002JJ marker/body, one UID0002JK marker/body, and zero empty markers for either.
- Known warnings were unrelated existing missing-reference/children-marker/emitter warnings. No target-specific validation error remains. Validator-managed side effects included path/reference propagation, projected stats/registry/generated metadata refresh, and UID link propagation in manual coverage; B005 made no direct manual coverage edit.
- Independent supervisor validators `000000017237` through `000000017244` each exited `0` with `ok:1`. Command `17238` normalized the UID00036I link label in UID0002JK, producing the reconciled hash below; no behavioral/formal/metadata claim changed.

## Changed Files

- Initial report-only artifact: `tools/leaser/Agents/Agent-B005/research/0002JJ-MenuItemCopyBoundsRect-source-quality.md`; this same report is being reconciled in place.
- Renamed/modified UID0002JJ: `by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md`, SHA256 `73ED697372AC81FC3EB95E7EAA6902AED3B3C555F6DC47A37D98602CDC401242`, `15122` bytes, `121` lines, validators `17224/17234`.
- Renamed/modified UID0002JK: `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md`, current SHA256 `681D3B17286322D7F3F702E165BBB26A36B8873F72BE0BC591B361313E33FB59`, `13713` bytes, `116` lines, validators `17227/17238`; supervisor command `17238` normalized one UID00036I link label.
- Modified UID00007V: `by-class/MenuItem.md`, SHA256 `E9BB955D01CB2D6CB312B408B715B1E9A07158A5863D143E2F2FC8B273F39504`, `22821` bytes, `168` lines, validator `17228`.
- Modified UID0001BK: `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`, SHA256 `F417CFA80403EE896E2AB80991A6C7728344774176730B793945EA70106AD899`, `29397` bytes, `176` lines, validator `17229`.
- Modified UID0001V5: `by-type/by-struct/MenuItemLayouts.md`, SHA256 `70ECC8D87671DEAD523B7452977435F252F3C8690125857CD08E4234894A3EE8`, `20895` bytes, `155` lines, validator `17230`.
- Modified UID0001Y4: `by-type/by-vtable/MenuItemVtables.md`, SHA256 `040B5DCE9D5B7D2BE7392936D80D65B582DE8B66E0DF89D22F396694A4F98EA0`, `20850` bytes, `139` lines, validator `17231`.
- Modified UID00036I: `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`, SHA256 `4F6D1B0B40A91A7645C5A01B05E3416451E0319E4F36421FD5221C7B49780B5B`, `15341` bytes, `126` lines, validator `17232`.
- Modified UID0000MN: `by-file/PopupMenuControls.md`, SHA256 `6CE622EF4495DF695D8E81695326380C2F2047F615795DE2FD653B45F87621C6`, `37075` bytes, `220` lines, validator `17233`.
- Read-only verified unchanged supports: `by-project-structure/proposed-source-tree.md` SHA256 `21A0BD20E475876C5B4DD6D6B2E7AF47BB8A3710E71A877A77991072D4B39EE2`; `by-memory/-ignored.md` SHA256 `3C142D38CCB8F7F318F19D94CD24D77ACE942A82C8CCB4F297D159FC5E55C426` with exact padding and validator-propagated renamed links.
- Validator-generated output/state refreshed through command `17234`; no generated file was edited manually. Manual coverage received validator-managed UID path propagation only; its accepted score/description payload remains supervisor-owned.
- Leases: each of the eight ordinary destinations was leased only for its immediate edit/scoped-validator batch and released immediately afterward; final `current_leases.md` showed no B005 lease.
- IDA mutation/save: not run by B005; supervisor Gate 2B applied/read back/saved the exact accepted actions as recorded above.
- Report execution/probe/dry-run/move/archive: not run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact pre-callback SHA `01251141151C20D0ADE43944BA725B8D08A3B5DAACACA98AAFD50D5B46BF0597` before implementation.
- [x] Renamed UID0002JJ to `by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md` without changing UID/range.
- [x] Renamed support UID0002JK to `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md` without changing UID/range.
- [x] Applied UID0002JJ `92/94`, exact summary, complete evidence, history, and pointer-return formal.
- [x] Applied UID0002JK `90/93`, exact paired evidence/history, and preserved its complete setter formal.
- [x] Applied UID00007V `91/93` and exact pointer-return header declaration while preserving unrelated class content.
- [x] Applied bounded report-level facts to UID0001BK, UID0001V5, UID0001Y4, UID00036I, and UID0000MN without duplicating method bodies.
- [x] Preserved already-correct source tree, padding ownership, owner/emitter routes, reconstruction states, positions, and nesting.
- [x] Historicalized stale no-C++/unresolved-name/inline-or-source/95+-gate/current-comment assumptions.
- [x] Reconciled every C2JJ-01 through C2JJ-34 claim: ordinary/generated claims are applied or already present; C2JJ-28/29 are supervisor-applied and verified; C2JJ-31 remains supervisor-owned post-execution coverage work; C2JJ-30/33/34 are excluded with recorded reasons.
- [x] Confirmed no additional target UID is declared; UID0002JK remains a support destination.
- [x] Supervisor Gate 2B verified each exact function/range/stack/comment/type/vtable/comparator prestate, applied the accepted target/sibling actions, protected no-change entities, and saved the IDB.
- [ ] Apply exact supervisor-owned manual coverage rows after ordinary verification; B005 must not edit them.
- [x] Ran serial scoped validators only during the accepted callback, with immediate per-file leases and releases; commands `17224`, `17227`-`17234` all returned `ok: 1`.
- [x] Performed waited generated readback under command `17234`: one target marker/body, one setter marker/body, corrected paths/signatures/scores, and zero empty markers.
- [ ] Keep all report lifecycle and execution operations supervisor-only.

Implementation callback pass:

- [x] Supervisor Gate 2A exact documentation verification passed for all eight destinations; commands `17237` through `17244` returned `ok:1`.
- [x] Supervisor-owned C2JJ-28/29 IDA actions were applied/read back/saved; C2JJ-30 protected state was independently verified unchanged.
- [x] Report was accepted by supervisor for implementation at the exact pre-callback SHA.
- [x] All accepted ordinary target/support details were incorporated without summary loss.
- [x] Every destination was reread independently and every ledger claim reconciled to a legal callback state.
- [x] Metadata, score, rename, owner/emitter, range, and C++ actions were applied exactly or excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, positive evidence, and negative evidence were preserved.
- [x] All ordinary-file leases were acquired only immediately before edit/validation and released immediately afterward.
- [x] Scoped validators completed serially and exact command IDs/results are recorded.
- [x] Generated output was refreshed/read back and exact hash/counts are recorded.
- [x] Exact manual coverage payload is retained for supervisor; B005 made no direct coverage edit, while validator-managed path propagation is disclosed.
- [x] Remaining unapplied accepted items are exactly: C2JJ-31 manual coverage and supervisor lifecycle execution/archive.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000017245","destination_path":"executed-b-agent-research/B005/0002JJ-MenuItemCopyBoundsRect-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002JJ-MenuItemCopyBoundsRect-source-quality.md","timestamp":"2026-07-24T10:21:29-04:00","uid":"0002JJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
