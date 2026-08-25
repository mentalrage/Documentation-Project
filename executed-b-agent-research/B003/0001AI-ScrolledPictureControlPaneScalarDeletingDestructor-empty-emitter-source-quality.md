** TARGET-REPORT-UID:0001AI **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001AI ScrolledPictureControlPane Scalar Deleting Destructor Empty-Emitter Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented disposition: [UID:0001AI] is the exact non-emitting MSVC scalar-deleting-destructor clone for `ScrolledPictureControlPane`, now `92/94`, canonical class owner [UID:0000CH], `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position and formal C++, and `Nested:0`.
- Final source model: the wrapper is compiler output caused by a source-level virtual `ScrolledPictureControlPane::~ScrolledPictureControlPane()`. It duplicates the ordinary destructor cleanup and adds deleting-destructor flag handling, storage release, SEH/cookie setup, and multiple-inheritance receiver routes. None of those compiler mechanics is a second source destructor.
- Implemented source route: the complete human source representation is exclusively in ordinary core [UID:00019Y], class [UID:0000CH], and file [UID:0000NH]. Their current blocks express the live constructor types, exact `0x154` layout, and one ordinary virtual destructor; R0, R3, and R4 remain blank no-code destinations.
- Confidence: very strong. Live IDA MCP session `1feab207` proves the exact bytes, function/CFG, flag paths, vtable cells, adjustor thunks, callees, and absence of any ordinary source call route to the scalar wrapper.

## Supporting Research

- Historical research phase boundary: before the authorized callback, B003 modified only this report. During the callback B003 changed the six ordinary by-* destinations recorded below under one-file leases and invoked their scoped validators; B003 did not manually edit any manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, queue, lock, archive, or IDA file.
- Exact historical search terms: `UID0001AI`, `UID:0001AI`, `0x00502ab0`, `00502ab0`, `ScrolledPictureControlPaneScalarDeletingDestructor`, and `sub_502AB0`.
- `source-3/project-documentation/executed-b-agent-research/**` produced three relevant matches:
  - B004 `00019Y-ScrolledPictureControlPaneCore-source-quality.md`: direct source-family support. It correctly identified the ordinary destructor as the source body and UID0001AI as companion scalar glue, but its evidence pass explicitly recorded MCP unavailable. Its raw hashes and field leads were independently revalidated live here; its constructor parameter and palette names are not accepted unchanged.
  - B006 `0000K1-ImageFrameTable-empty-emitter-family-source-quality.md`: helper-family support. Its `DestroyOwnedImageBlock` source ownership and two-level cleanup body agree with the live target call at `0x00502b02`; it is not a direct target report.
  - B005 `0001AH-0001AJ-NewHistoryStaffsDialogPaneDestructorPair-source-quality.md`: destructor-ABI analogy only. That report cannot determine UID0001AI disposition because those ranges have different source/body decomposition. It supports the general need to separate scalar-wrapper mechanics from ordinary destructor source.
- `source-3/project-documentation/archived/**`, `tools/leaser/Agents/Older-Research/**`, and `tools/leaser/Agents/SpecialReports/**` each returned no match for the exact search terms.
- Active `tools/leaser/Agents/**` matches were B003's current assignment, A007 notes, supervisor assignment/notes, and the Rule 26 tracker. No active B-agent direct-target research report was found.
- No Wave2/Wave3 source or instruction was used. Any stale generated names from those eras remain rejected lead material.

## Target

- Target UID: `0001AI`.
- Target path: `by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md`.
- Historical source queue state at assignment: by-memory reconstructable empty-emitter target, `86/90`, generated UID0001AI `Empty Emitter Marker`.
- Exact executable range: `[0x00502ab0,0x00502b58)`, size `0xa8` / 168 bytes (Verified with `int_convert.py`).
- Historical pre-callback owner/emitter state: `CANONICAL_OWNER:0000CH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CH`, blank optional position, blank formal C++, `Nested:0`.
- Implemented state: `92/94`, `CANONICAL_OWNER:0000CH`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, blank formal C++, `Nested:0`.

## Current Target State

- UID0001AI now retains the exact title/range and exhaustive ABI evidence while correctly classifying the range as non-reconstructable compiler output. Its historical reconstructable-wrapper, indirect-guard, and unresolved helper/type wording is explicitly preserved as superseded history.
- UID00019Y now has exact R1 with the bounds pointer, wide resource names, correct base-constructor order, `DLPalette *m_palette`, and byte direction. It remains the sole source-emitting destructor destination.
- UID0000CH now has exact R2 and the complete natural-alignment `0x154` class layout; UID0000NH is `91/92` with the complete source/compiler inventory and preserved unresolved feature-level caller history.
- UID0001AD is `90/94`, class-owned by UID0000CH, non-reconstructable, and blank; its current guidance correctly identifies the ordinary virtual destructor as the human source cause.
- Historical pre-callback generated `auto-generated/NexusTK/ui/controls/ScrolledPictureControlPane.cpp`, observed under validator header command `000000011217` refreshed `2026-07-14T09:28:56-04:00`, SHA256 `730022410618813A8B616DC7E35D1E0AAAE51A128040365F291D722EC27A3467`, contained [UID:00019Y] definitions once and two empty markers: class [UID:0000CH] and target [UID:0001AI]. It is retained only as pre-callback verification history and is superseded by B003 waited command `11279` and the later read-only observation below.
- Latest read-only validator-generated state observed after a concurrent external refresh is command `000000011289`, refreshed `2026-07-14T09:58:29-04:00`, `auto-generated/NexusTK/ui/controls/ScrolledPictureControlPane.cpp` SHA256 `F1AE65AED93EF7B311DEE80015A90D236AA7B1D01EF0A290F5C98308BA62846E`: one class declaration closed before four qualified definitions, one constructor/destructor/timer/paint, and zero UID0000CH/UID0001AI empty markers or compiler-only handwritten bodies. The later validator-owned header refresh does not alter B003's recorded successful waited command `11279`.
- B003 completed the authorized ordinary-doc implementation and scoped validation but performed no report execution, report probe/count/revalidation, lifecycle, move, or archive command. External report path/count/status and manual coverage state remain supervisor/validator-owned and are neither asserted nor directed here.

## Executive Recommendation

- Keep the narrowest semantic owner as class [UID:0000CH]. Canonical ownership remains useful even though this exact compiler wrapper must not emit.
- UID0001AI is reclassified without split/merge or covered-by pseudo-body. `RECONSTRUCTABLE:FALSE` plus exhaustive no-code proof is the implemented validator-safe representation.
- One source destructor definition emits from [UID:00019Y] through [UID:0000CH] and [UID:0000NH]. The class declaration declares a public virtual destructor; that source contract regenerates the primary scalar wrapper and the two adjusted vtable entries.
- The core/class/file/thunk support pages are synchronized at the accepted scores. Helper/type dependencies were reread and remain verify-only because current text equals or exceeds the live evidence.

## Supervisor Active Recheck

- The assignment required a healthy live-MCP direct-target pass and independent revalidation of older UID00019Y support. That evidence pass was completed against adopted NexusTK IDB session `1feab207` at evidence-collection time.
- No split-first implementation was authorized or needed. UID0001AI is one exact physical function; its preceding and following padding remain excluded.
- The only source-bearing destructor destination is existing [UID:00019Y]. No new child page or UID is needed.
- The authorized callback is complete. Every accepted implementation item has destination-specific proof below; no B003 implementation item remains.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest true semantic owner, separates `CANONICAL_OWNER` from `EMITTER_UIDS`, and requires `RECONSTRUCTABLE:FALSE` pages to have blank emitters/formals. Those rules directly produce the target recommendation.
- Direct IDA facts are addresses, bytes, instructions, flag tests, vtable constants, xrefs, callees, receiver adjustments, return convention, and object-size immediate. Documentation evidence supplies existing UIDs/routes and established helper/type names. Inference supplies only original-source spellings, access control, and the most plausible human source organization.
- Existing assumptions treated as uncertain and rechecked: reconstructable scalar-wrapper status, `flags & 4` as a real delete/guard operation, `dword_67A744` as meaningful source state, constructor first parameter as a parent, narrow asset names, palette-state type, and equality of `FrameDrawRecord` with `EPFTileContext`.
- Rejected generated/polluted labels include fitting-room/head-selection ownership and a `TextButtonExControlPane` base destructor name. The body is a generic image-scrolling control with exact class vtables and source file support.
- No stale Wave2/Wave3 evidence affected the conclusion.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and validation | Result |
| --- | --- | --- |
| Scalar wrapper versus source destructor | Compared all target cleanup instructions with ordinary destructor `[0x004ff970,0x004ff9d7)`, its hash, vptr writes, `DestroyOwnedImageBlock`, and `Pane` teardown. The target adds only ABI flags, storage release/no-op flag-4 path, return-this, and compiler frame support. | UID0001AI is compiler generated; UID00019Y owns source destruction. |
| Receiver and return types | Primary vtable points directly to target; secondary and tertiary entries use `this-0xa0`/`this-0xa4` thunks. Both exits move complete `this` from `esi` to `eax` and use `retn 4`. | `__thiscall`, complete-object receiver, one stack `unsigned int flags`, complete-object pointer return. |
| Flag 4 semantics | Disassembled the direct call at `0x00502b3c`; callee `0x0041b6a0` is `_guard_check_icall_nop@4`, a one-byte `ret`. There is no indirect call target and no storage free on this path. | Preserve as compiler/runtime ABI evidence; do not model sized delete or a source helper call. |
| `dword_67A744` load | The target loads it into `ecx` before a `__stdcall` cleanup helper that obtains its own memory manager. No later source-visible use exists. | Compiler/decompiler context residue, not a destructor field/global statement. |
| Owned field/type | Constructor stores `LoadImageFrameTable` result at `+0x114`; ordinary and scalar destructors pass that exact pointer to shared `DestroyOwnedImageBlock`. UID0000UN defines `ArchiveMetadataTable`. | `ArchiveMetadataTable *m_frameTable` at `+0x114`. |
| Embedded record type | UID0000UN proves 40-byte `FrameDrawRecord` projection semantics. Equal size and shared zero-initialization with `EPFTileContext` do not erase distinct fields/consumers. | Keep `FrameDrawRecord`, reject `EPFTileContext` aliasing. |
| Palette field and helpers | Live constructor calls `0x00543d70` and `0x00543d40`; current PaletteLib docs identify `GetPaletteByName` and `GetCurrentPalette`, both returning `DLPalette *`. | `DLPalette *m_palette` at `+0x140`; reject vague palette-state names. |
| Constructor signature | Live decompile plus `retn 0x18` proves six stack parameters. The first pointer is passed as bounds to `ControlPane(unsigned char,const RectBounds*)`; next two are wide strings; final direction is one byte. | `const RectBounds *`, two `const wchar_t *`, two `int`, one `unsigned char`; `ControlPane(8,bounds)`. |
| Layout and size | Base is `0x108`; derived writes/reads and the wrapper's `push 0x154` close the layout exactly. Natural alignment supplies `+0x111..+0x113` and final size needs no raw padding member. | Exact source-quality `0x154` declaration is ready. |
| Visibility/virtual contract | Primary, secondary, and tertiary deleting entries and existing public control construction/destruction conventions prove virtual destruction; the binary cannot encode the original access token. | Recommend public virtual destructor, with access spelling inference explicitly score-capped. |
| Source placement | Method cluster, class, file route, vtables, image helpers, timer, and render behavior all converge on the existing control module. | `NexusTK/ui/controls/ScrolledPictureControlPane.cpp`; no new file. |
| Range/split | Lookup, raw bytes, disassembly, neighbors, padding, xrefs, and CFG agree on one exact function. | No split/merge/rename. Preserve title and range. |

Exact class layout closed by the live target's `0x154` object-size immediate:

| Offset / span | Size | Source-facing member | Evidence and alignment disposition |
| --- | ---: | --- | --- |
| `+0x000..+0x107` | `0x108` | `ControlPane` base | Current ControlPane layout and derived constructor call; includes inherited primary/secondary/tertiary facets. |
| `+0x108..+0x10b` | `0x04` | `int m_scrollInterval` | Constructor argument store; timer reschedule reads it. |
| `+0x10c..+0x10f` | `0x04` | `int m_scrollStep` | Constructor argument store; timer direction cases use signed deltas. |
| `+0x110` | `0x01` | `unsigned char m_scrollDirection` | Sixth stack argument is byte-sourced; constructor and timer switches use values `0..3`. |
| `+0x111..+0x113` | `0x03` | natural alignment | Implicit padding before the next 32-bit pointer; no source member. |
| `+0x114..+0x117` | `0x04` | `ArchiveMetadataTable *m_frameTable` | Constructor stores loader result; both destructors pass it to `DestroyOwnedImageBlock`. |
| `+0x118..+0x13f` | `0x28` / 40 | `FrameDrawRecord m_frameDrawRecord` | Projection helper and render consumer contract; size conversion verified with `int_convert.py`. |
| `+0x140..+0x143` | `0x04` | `DLPalette *m_palette` | `GetPaletteByName`/`GetCurrentPalette` return route and paint use. |
| `+0x144..+0x153` | `0x10` | `RectBounds m_destinationRect` | Constructor off-screen placement and timer offset operations. |
| total `+0x000..+0x153` | `0x154` / 340 | complete object | Wrapper immediate and field closure agree; conversion verified with `int_convert.py`. |

Rejected alternatives:

- Handwrite a scalar-deleting member: rejected because C++ source does not declare this MSVC helper, it would duplicate the ordinary destructor and can conflict with compiler emission.
- Keep target `RECONSTRUCTABLE:TRUE` with a covered-by comment: rejected because that historical state made the generator treat the page as a source-bearing child and made the pre-callback empty marker an artificial obligation.
- Move source destruction into UID0001AI and blank UID00019Y: rejected because UID00019Y is the ordinary source body and the target is only vtable/ABI glue.
- Treat flag 4 as vector delete, sized delete, or guarded indirect deletion: rejected by the direct no-op callee and lack of any indirect call/storage release.
- Set target owner to `NONE`: rejected because three exact class vtable views and identical ordinary cleanup prove class semantics even though emission is inapplicable.
- Keep narrow strings, parent pointer, `m_paletteState`, `GetPaletteState`, or `GetDefaultPaletteState`: rejected by live constructor operands and current ControlPane/PaletteLib APIs.
- Collapse `FrameDrawRecord` into `EPFTileContext`: rejected by UID0000UN's current distinct semantic declarations and consumers.

No in-scope source-quality blocker remains. Original private/public token and exact member spellings are not recoverable from stripped code, but the selected names are current project conventions backed by exact semantics; this limits scores rather than blocking source.

## Evidence Standards Used

- Mandatory direct evidence: streamable IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `disasm`, `basic_blocks`, decompile, xrefs, bounded instruction search, data/pointer search, callees, and neighbor lookups.
- Binary identity evidence: exact range lengths and SHA256 over bytes read from the active IDB; target prologue/tail bytes; ordinary destructor and thunk hashes as positive controls.
- Structural evidence: three vtable views, two adjusted receiver entries, primary direct entry, exact object offsets, constructor/destructor write symmetry, and ordinary/scalar cleanup equivalence.
- Documentation evidence: current target/core/class/file/thunk/helper/type/vtable pages, current manual coverage rows, and current generated C++ read-only state.
- Historical evidence: only exact-match executed reports were opened, and every reused binary conclusion was independently rechecked live.
- Negative evidence has equal weight here: no ordinary direct caller, no second source body, no target-RVA pointer, no real flag-4 call target, no unique target semantics, and no reason to hand-author vptr/SEH/cookie/vtable data.
- Confidence stays below 95 because stripped binary evidence cannot recover exact original identifiers/access tokens or prove compiler-version flags beyond observed ABI behavior.

## Evidence Checked

- IDA MCP discovery on 2026-07-14 returned one active adopted database: session `1feab207`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `20008`.
- `server_health` at `2026-07-14T09:27:53-04:00` returned `status:ok`, image base `0x400000`, module `NexusTK.exe`, and `auto_analysis_ready`, `hexrays_ready`, and `strings_cache_ready` all true; cache size was 2067.
- Fresh bounded `lookup_funcs` returned target `sub_502AB0` size `0xa8`, ordinary destructor `sub_4FF970` size `0x67`, and thunks `sub_502550`/`sub_50255B` size `0xb` each.
- Fresh bounded `get_bytes` at `2026-07-14T09:30:44-04:00` read all 168 target bytes, all 103 ordinary-destructor bytes, and all 22 thunk bytes and reproduced all three hashes in this report.
- Checked target disassembly, physical/local instruction inventory, IDA external handler-tail presentation, local/external CFG blocks, four direct callees, ordinary destructor, thunks, constructor signature/body, palette helpers, ControlPane constructor, Pane teardown, storage-delete helper, and no-op guard helper.
- Checked code/data xrefs, primary/secondary/tertiary vtable cells, literal target pointer and RVA patterns, bounded jump operands, constructor/destructor vptr stores, timer/paint vtable entries, and target predecessor/successor functions/padding.
- Current docs checked: UID0001AI, UID00019Y, UID0001AD, UID0000CH, UID0000NH, UID00025Q, UID0002P5, UID0002P6, UID0000UN, UID0002PB, UID000038, UID0000A2/Pane support, UID000197/operator-delete support, PaletteLib/DLPalette support, and current generated `ScrolledPictureControlPane.cpp`.
- Manual coverage checked read-only: `by-memory/-coverage-report.md` rows UID0001AI/00019Y/0001AD/00025Q, `by-class/-coverage-report.md` UID0000CH, and `by-file/-coverage-report.md` UID0000NH.
- Historical roots/terms and classifications are recorded under `Supporting Research`.
- One earlier broad instruction query exceeded a 30-second shell bound. The listener/session remained healthy and a narrowed `[0x00502000,0x00503000)` operand query completed with exactly the two thunk jumps. This was an overbroad-query replacement, not an MCP outage.
- One malformed read-only `get_bytes` request used `address` instead of schema field `addr` and returned two parse errors. `tools/list` was reread and the corrected bounded calls succeeded immediately. No evidence relies on the malformed request.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Mandatory evidence was captured from healthy adopted IDB session `1feab207` with analysis, Hex-Rays, and strings ready. | Very high | `idb_list`, `server_health`, bounded lookup/bytes. | UID0001AI Evidence; affected support change notes. | incorporate | applied | Exact session-time health/request facts remain in UID0001AI and the support evidence; scoped validators `11249`, `11252`, `11262`, `11273`, `11275`, and `11279` accepted the evidence-bearing destinations. |
| C02 | UID0001AI is exactly `[0x00502ab0,0x00502b58)`, `0xa8`/168 bytes, SHA256 `3bc9...b1f`; adjacent pads are excluded. | Very high | Lookup, full bytes/hash, neighbor lookup. | UID0001AI Boundary/Range/Score. | incorporate | applied | UID0001AI now records the exact half-open range, explicit `0xa8`/168-byte size, full hash, endpoint bytes, predecessor/successor, and excluded pads; validator `11249` exit 0, `ok:1`. |
| C03 | ABI is x86 `__thiscall`, complete-object `this` in ECX, one stack flags dword, pointer return in EAX, `retn 4`; adjusted receivers enter through thunks. | Very high | Disassembly, vtable cells, thunk bytes. | UID0001AI ABI; UID0001AD; UID0000CH. | incorporate | applied | ABI/adjusted-entry prose is synchronized across UID0001AI (`11249`), UID0001AD (`11252`), and UID0000CH (`11273`); R0/R3 stay blank and R2 supplies only the virtual source contract. |
| C04 | The physical body has 50 local instructions and five local CFG blocks; IDA's 58/9 totals include eight external handler instructions/four external blocks. | Very high | `disasm(include_total)`, `basic_blocks`. | UID0001AI Instruction/CFG evidence. | incorporate | applied | UID0001AI contains the exhaustive 50-instruction local inventory and five-local versus 58/9 IDA external-handler accounting; validator `11249` accepted the page. |
| C05 | Flag behavior is exact: bit 1 clear returns after teardown; bit 1 set/bit 4 clear frees storage; bits 1+4 call no-op helper and do not free; return is always complete `this`. | Very high | Branch/instruction audit, callee audit. | UID0001AI Behavior. | incorporate | applied | Exact flag matrix and complete-this return are current in UID0001AI (`11249`) and source/compiler inventory in UID0000NH (`11279`); generated output contains no scalar flags or delete body. |
| C06 | Target restores vtable bases at `+0/+0xa0/+0xa4`; primary cell `0x61d890` points directly, secondary/tertiary cells route through `0x502550/0x50255b`. | Very high | Disassembly, raw vtable bytes, xrefs. | UID0001AI; UID0001AD; UID0000CH; UID00025Q. | incorporate | applied | Exact stores/routes/cells are preserved in UID0001AI `11249`, UID0001AD `11252`, UID0000CH `11273`, and bounded UID00025Q `11275`; no raw vtable array emits under `11279`. |
| C07 | `this+0x114` is owned `ArchiveMetadataTable *m_frameTable`; both ordinary/scalar paths call `DestroyOwnedImageBlock` before base teardown. | High | Constructor/destructor data flow; UID0002P5/0000UN. | UID0001AI; UID00019Y; UID0000CH; UID0000NH. | incorporate | applied | Ownership/decomposition is current in target `11249`, core R1 `11262`, class R2/layout `11273`, and file inventory `11279`; UID0002P5/UID0000UN were reread unchanged and remain supporting definitions. |
| C08 | Vptr stores, `Pane::~Pane` call, SEH/cookie work, and return epilogues are compiler lowering, not manual source statements. | Very high | Ordinary/scalar comparison, Pane support. | UID0001AI no-code proof; core/class history. | incorporate | applied | Target no-code proof and source/core/class/file histories distinguish all lowering; B003 waited SHA `28C2...9CB8` and later observed SHA `F1AE...846E` both have zero vptr/vftable, explicit base-destructor, cookie, or EH terms. |
| C09 | `0x4f4ac0` is MemoryMan-backed storage delete; `0x41b6a0` is one-byte `_guard_check_icall_nop@4`, not sized deletion or an indirect call. | Very high | Callee disassembly/decompile and branch audit. | UID0001AI behavior/negative evidence. | incorporate | applied | Correct helper roles and rejected interpretations are exhaustive in UID0001AI `11249` and synchronized in UID0000NH `11279`; verify-only UID000197 was reread unchanged. |
| C10 | Reachability is exactly two thunk code refs and one primary vtable data ref; there is no ordinary direct call, target-RVA pointer, or second source route. | Very high | `xrefs_to`, bounded operand search, byte/pointer search. | UID0001AI; UID0001AD; UID0000NH. | incorporate | applied | Target xref inventory `11249`, exact thunk routes `11252`, and file negative/source-placement evidence `11279` preserve the one-primary/two-adjusted route and all absent alternatives. |
| C11 | Ordinary destructor `[0x004ff970,0x004ff9d7)` SHA256 `4571...a354` owns the sole source destructor body `DestroyOwnedImageBlock(m_frameTable)`. | Very high | Full bytes/hash, instruction comparison, source family docs. | UID00019Y formal R1; UID0001AI relationship. | incorporate | applied | UID00019Y R1 is byte-for-byte exact under validator `11262`; generated command `11279` emits that destructor exactly once and emits no UID0001AI body. |
| C12 | Thunks `[0x00502550,0x00502566)` SHA256 `89bb...48f`, adjust by `0xa0`/`0xa4`, and are compiler-only class-owned entries. | Very high | Full bytes/hash, disassembly, vtable refs. | UID0001AD metadata/prose/formal R3. | incorporate | applied | UID0001AD is `90/94`, owner 0000CH, false, blank emitter/position/R3, with exact combined/per-thunk bytes and routes; validator `11252` exit 0, `ok:1`. |
| C13 | `ScrolledPictureControlPane` has exact `0x154` layout with base `0x108`, interval/step/direction, natural 3-byte alignment, frame table, 40-byte frame record, palette pointer, and destination rect. | High | Constructor offsets, target size immediate, support types. | UID0000CH formal R2/layout. | incorporate | applied | UID0000CH R2 and exact offset/size table are current and byte-for-byte matched; validator `11273` exit 0, `ok:1`, and generated class closes before definitions. |
| C14 | Source constructor is bounds + two wide resource names + two ints + byte direction; palette field/API is `DLPalette *` via `GetPaletteByName`/`GetCurrentPalette`. | High | Live decompile, `retn 0x18`, UID0002PB, PaletteLib support. | UID00019Y formal R1; UID0000CH declaration. | incorporate | applied | Exact constructor and palette model is in core R1 `11262`, class R2 `11273`, and file inventory `11279`; UID0002PB, PaletteLib, and DLPalette were reread unchanged with no contradiction. |
| C15 | Canonical/source placement remains class UID0000CH and file UID0000NH at `NexusTK/ui/controls/ScrolledPictureControlPane.cpp`; no feature-dialog move is supported. | High | Vtables, method family, existing route, negative caller evidence. | UID0001AI/00019Y/0000CH/0000NH. | incorporate | applied | Owner/emitter/path metadata and rejected feature-dialog alternatives are synchronized across validators `11249`, `11262`, `11273`, and `11279`; no rename, split, merge, or route change occurred. |
| C16 | UID0001AI is `92/94`, false, owner 0000CH, blank emitter/position/formal, Nested 0, with compiler-only Item Summary and exhaustive no-code proof. | Very high | C02-C12 plus by-structure rules. | UID0001AI metadata/formal R0. | incorporate | applied | UID0001AI has the exact accepted metadata, Item Summary, exhaustive evidence, and blank R0; validator `11249` exit 0, `ok:1`; generated command `11279` contains no target marker/body. |
| C17 | Support scores/state are UID00019Y `92/93`, UID0000CH `91/93`, UID0000NH `91/92`, UID0001AD `90/94` owner 0000CH; routes otherwise remain exact. | High | Blocker audit and current support comparison. | Four named support pages. | incorporate | applied | Current metadata is exact on UID00019Y `11262`, UID0000CH `11273`, UID0000NH `11279`, and UID0001AD `11252`; accepted routes/positions/nesting remain unchanged. |
| C18 | Exact ScrolledPicture vtable-data subrange is `[0x0061d88c,0x0061d930)`; UID00025Q's historical pre-callback `0x61d748-0x61d928` row truncated this class's tertiary timer cell. | Very high | Raw vtable bytes, constructor stores, data refs. | UID00025Q observed-contents bounded correction. | incorporate | applied | UID00025Q now records `[0x0061d88c,0x0061d930)`, all three locator/base pairs and target/thunk/timer/paint cells while preserving `86/92`, false/NONE/blank R4 and unrelated content; validator `11275` exit 0, `ok:1`. |
| C19 | Generated callback verification yields one class declaration closed before child definitions, one constructor/destructor/timer/paint definition, zero UID0001AI/class empty markers, and no handwritten scalar/vtable/RTTI/EH/cookie code. | High | Historical command-11217 readback and formal routing model. | Final waited by-file validator/readback. | incorporate | applied | B003 waited command `11279` refreshed at `2026-07-14T09:53:11-04:00`, SHA `28C2...9CB8`; later external command `11289` refreshed the header at `09:58:29`, SHA `F1AE...846E`, with identical source assertions: class-close offset 1090 precedes first definition 1326, four methods each count 1, UID0001AI/UID0001AD/UID00025Q/empty-marker counts 0, and forbidden compiler/decompiler term counts 0. |
| C20 | Six manual coverage rows were stale; the exact supervisor-owned replacement text is supplied below and B003 did not edit those manual files. | Very high | Read-only manual row comparison. | Manual by-memory/by-class/by-file coverage. | incorporate | applied | The six exact replacement rows remain verbatim below. B003 did not edit any manual coverage file; external manual synchronization state is not asserted by this artifact. |

## Positive Evidence Summary

- The exact scalar wrapper has a primary vtable entry, two adjustment-thunk entries, deleting flags, complete-object pointer return, and `retn 4`: a canonical MSVC deleting-destructor shape.
- The ordinary destructor and scalar wrapper share the same three vptr stores, same `m_frameTable` cleanup, and same `Pane` teardown. The wrapper has no additional game behavior.
- The wrapper's only executable entrants are the two vtable adjustors; no source call site reaches it.
- Constructor, ordinary destructor, scalar wrapper, and vtable cells agree on the complete/secondary/tertiary subobject model.
- The existing core source body already expresses the one genuine destructor statement, while current helper/type pages now support source-grade names and layout.
- The exact object-size immediate `0x154` closes the class layout and independently corroborates all derived field offsets.

## IDA MCP Facts

- Database: session `1feab207`, NexusTK IDB, image base `0x00400000`, healthy at evidence collection time.
- Target: `sub_502AB0`, `[0x502ab0,0x502b58)`, size `0xa8`/168 (Verified with `int_convert.py`).
- Target SHA256: `3bc9b5a6d6473fcb02f292bd85915664c7e142c020cf115a43ffae13f5ecab1f`.
- First 16 bytes: `55 8b ec 6a ff 68 00 68 5f 00 64 a1 00 00 00 00`.
- Last 16 bytes: `f4 64 89 0d 00 00 00 00 59 5e 8b e5 5d c2 04 00`.
- Ordinary destructor: `[0x4ff970,0x4ff9d7)`, size `0x67`/103 (Verified with `int_convert.py`), SHA256 `45718a4c81f4bbb4cc88586b8165a98d61d223898576e6edb9915e14e63ea354`.
- Thunks: `[0x502550,0x502566)`, two `0xb`/11-byte functions (Verified with `int_convert.py`), SHA256 `89bbb2ac87ba551b3cb0995d1df502986ceffe1548274093f2bd637d41dfa48f`.
- Target callees: `0x4d15d0` `DestroyOwnedImageBlock`, `0x544580` compiler-lowered `Pane::~Pane`, `0x4f4ac0` storage-delete wrapper, and `0x41b6a0` `_guard_check_icall_nop@4`.
- IDA reports 58 total instructions because it appends eight handler/support instructions at `0x5c91f2` and `0x5f6800..0x5f6816`. The target's physical range contains exactly these 50 instructions:

```text
502ab0 push ebp
502ab1 mov ebp, esp
502ab3 push 0FFFFFFFFh
502ab5 push offset SEH_5C03A0
502aba mov eax, large fs:0
502ac0 push eax
502ac1 push esi
502ac2 mov eax, ___security_cookie
502ac7 xor eax, ebp
502ac9 push eax
502aca lea eax, [ebp+var_C]
502acd mov large fs:0, eax
502ad3 mov esi, ecx
502ad5 push dword ptr [esi+114h]
502adb mov dword ptr [esi], 61D890h
502ae1 mov dword ptr [esi+0A0h], 61D8F8h
502aeb mov dword ptr [esi+0A4h], 61D928h
502af5 mov ecx, dword_67A744
502afb mov [ebp+var_4], 0
502b02 call 4D15D0h
502b07 mov ecx, esi
502b09 call 544580h
502b0e mov eax, [ebp+arg_0]
502b11 test al, 1
502b13 jz 502B44h
502b15 test al, 4
502b17 jnz 502B36h
502b19 push esi
502b1a call 4F4AC0h
502b1f add esp, 4
502b22 mov eax, esi
502b24 mov ecx, [ebp+var_C]
502b27 mov large fs:0, ecx
502b2e pop ecx
502b2f pop esi
502b30 mov esp, ebp
502b32 pop ebp
502b33 retn 4
502b36 push 154h
502b3b push esi
502b3c call 41B6A0h
502b41 add esp, 8
502b44 mov eax, esi
502b46 mov ecx, [ebp+var_C]
502b49 mov large fs:0, ecx
502b50 pop ecx
502b51 pop esi
502b52 mov esp, ebp
502b54 pop ebp
502b55 retn 4
```

- Five physical CFG blocks:
  - `[0x502ab0,0x502b15)` -> bit-1 fallthrough or common return.
  - `[0x502b15,0x502b19)` -> normal delete or flag-4 path.
  - `[0x502b19,0x502b36)` -> storage delete and return.
  - `[0x502b36,0x502b44)` -> no-op guard helper and common return.
  - `[0x502b44,0x502b58)` -> no-delete/common return.
- IDA's nine-block count additionally includes external terminate/SEH blocks at `0x5c91f2`, `0x5f6800`, and zero-size external stubs at `0x5dce60`/`0x5c956c`; those are not target bytes.
- Xrefs to target: code at `0x502556` and `0x502561`, data at `0x61d890`, no others. Bounded operand query `[0x502000,0x503000)` scanned 1203 instructions and found only those two jumps.
- Literal pointer search: little-endian VA `b0 2a 50 00` occurs at `0x61d890`; target RVA `b0 2a 10 00` has zero hits. The generic prologue occurs many times and is not used as identity evidence.
- Vtable raw range `[0x61d88c,0x61d930)`, size `0xa4`/164 (Verified with `int_convert.py`): primary locator at `0x61d88c`, primary base/target cell at `0x61d890`; secondary locator/base at `0x61d8f4/0x61d8f8`; tertiary locator/base at `0x61d924/0x61d928`; timer entry `0x61d92c -> 0x4ff9e0`; paint entry `0x61d8d4 -> 0x4ffa60`.
- Thunk 1 subtracts `0xa0`/160 and jumps to target; thunk 2 subtracts `0xa4`/164 (conversions verified with `int_convert.py`) and jumps to target.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004ff970,0x004ff9d7)` | UID00019Y within `ScrolledPictureControlPaneCore.md` | Ordinary source destructor | TRUE | UID0000CH | `88/90 -> 92/93` | Existing source destination; formal replacement R1. |
| `[0x00502550,0x0050255b)` | UID0001AD | Secondary-view destructor adjustor | FALSE | `NONE -> 0000CH` | `85/90 -> 90/94` | Existing compiler child; blank R3. |
| `[0x0050255b,0x00502566)` | UID0001AD | Tertiary-view destructor adjustor | FALSE | `NONE -> 0000CH` | same page | Existing compiler child; blank R3. |
| `[0x00502ab0,0x00502b58)` | UID0001AI | Scalar deleting destructor clone | `TRUE -> FALSE` | UID0000CH | `86/90 -> 92/94` | Existing exact target; no split; blank R0. |
| `[0x0061d88c,0x0061d930)` | UID00025Q bounded subrange | Three class vtable/RTTI views | FALSE aggregate | mixed aggregate | unchanged `86/92` | Bounded support correction only; aggregate remains blank R4. |
| `ScrolledPictureControlPane` | UID0000CH | Source class declaration/layout | TRUE | UID0000NH | `85/88 -> 91/93` | Existing class formal destination R2. |
| `ScrolledPictureControlPane.cpp` | UID0000NH | Source root | TRUE route | FILE | `88/85 -> 91/92` | Existing file root; no managed C++ header. |

There are no new children. The target remains `Nested:0`; no relative nesting level changes are triggered.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061d890` | primary vtable cell -> `0x00502ab0` | Complete-object deleting entry. |
| `0x0061d8f8` | secondary vtable cell -> `0x00502550` | Adjusted receiver subtracts `0xa0`. |
| `0x0061d928` | tertiary vtable cell -> `0x0050255b` | Adjusted receiver subtracts `0xa4`. |
| `0x00502556` | jump -> `0x00502ab0` | First and only secondary code xref. |
| `0x00502561` | jump -> `0x00502ab0` | Second and only tertiary code xref. |
| `0x00502b02` | call -> UID0002P5 `0x004d15d0` | Frees nested frame records then frame-table block. |
| `0x00502b09` | call -> `0x00544580` | Compiler-lowered base `Pane` teardown. |
| `0x00502b1a` | call -> UID000197 `0x004f4ac0` | Storage release when bit 1 set and bit 4 clear. |
| `0x00502b3c` | direct call -> `0x0041b6a0` | One-byte no-op guard stub; not an indirect call or storage release. |
| `0x0061d8d4` | vtable -> `0x004ffa60` | Source paint callback. |
| `0x0061d92c` | vtable -> `0x004ff9e0` | Source timer callback. |

No direct source caller reaches `0x00502ab0` or `0x004ff970`. This is expected: virtual deletion reaches the deleting entry, while the ordinary body is duplicated into the compiler wrapper in this build.

## Documentation Evidence And IDA Status

- UID0001AI's exact ABI evidence is preserved and its current source classification is non-reconstructable compiler output with no empty-emitter obligation.
- UID00019Y's raw destructor hash and source/body decomposition agree with live MCP. Its historical B004 offline-MCP limitation is superseded by this direct pass, and its current R1 contains the bounded source-type corrections.
- UID0001AD retains exact thunk bytes/ranges and false/blank disposition; current class ownership and ordinary-source-destructor guidance are corrected.
- UID0000CH and UID0000NH retain the correct class/file family and now carry source-ready inferred names and exact current types while preserving old blocker statements as history.
- UID00025Q remains a mixed non-emitting aggregate. Its current observed scrolled-control row and evidence record the exact ScrolledPicture subrange through timer cell `0x61d92c` to exclusive end `0x61d930`.
- UID0002P5, UID0002P6, UID0000UN, UID0002PB, PaletteLib, DLPalette, Pane, and OperatorDelete support already carry same-or-greater helper/type evidence and are verify-only.
- Historical pre-callback generated state under command `000000011217` contained one UID00019Y destructor definition and empty markers for class UID0000CH and target UID0001AI. B003 waited command `000000011279` provided the exact corrected result; later external command `000000011289` preserved the same generated source assertions while advancing validator-owned header metadata.

## Ranked Ownership Analysis

### 1. Class UID0000CH as target canonical owner; UID00019Y as source body

- Evidence for: exact class vtable names at all three target stores; primary and adjusted deleting entries; identical ordinary cleanup; exact class layout; existing class/file route; no unrelated caller.
- Evidence against: no original PDB and no direct constructor call route. Neither affects class identity or virtual destruction.
- Decision: accepted. UID0001AI keeps class canonical owner but loses source emission; UID00019Y remains the source-bearing method cluster.

### 2. File UID0000NH as direct target owner/emitter

- Evidence for: this is the correct source module and final generated source root.
- Evidence against: by-structure requires the narrower class owner for a class ABI artifact; file ownership would bypass the proven class.
- Decision: rejected as direct owner. Keep it as the class's source root.

### 3. No owner / standalone compiler island

- Evidence for: the range is compiler generated and lives in a later deleting-destructor island.
- Evidence against: compiler generation does not erase semantic class ownership; vtable constants and receiver thunks prove exactly one class.
- Decision: reject `CANONICAL_OWNER:NONE`. Use class owner with no emitter.

### 4. Feature-dialog or ImageFrameTable ownership

- Evidence for: stale generated feature labels and a call to ImageFrameTable cleanup.
- Evidence against: those are consumers/dependencies. The target installs `ScrolledPictureControlPane` vtables and tears down its complete object.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Not applicable. The existing class/file/core pages are exact. A new scalar-wrapper source file or helper grouping would be decompiler-shaped and would duplicate compiler output.

## Source Placement

- Recommended source placement: class declaration in the existing `ScrolledPictureControlPane` header/source context and definitions in `NexusTK/ui/controls/ScrolledPictureControlPane.cpp` through UID0000NH.
- The ordinary constructor/destructor/timer/paint definitions belong to UID00019Y routed through class UID0000CH. The target and thunks remain executable evidence only.
- ImageFrameTable owns shared loader/projector/cleanup helpers; PaletteLib owns palette lookup. Their use does not transfer the control's class ownership.
- Rejected placements: fitting room, head selection, text editing, ImageFrameTable source, and a standalone deleting-destructor source file.
- Remaining uncertainty: exact historical include/header layout and original member spellings are not encoded. They do not change the selected module or behavior.

## Range / Split / Padding / Reclassification Analysis

- Target exact range is `[0x00502ab0,0x00502b58)`; full-byte hash and both `retn 4` exits prove the end.
- Predecessor is unrelated `sub_502A70`, `[0x00502a70,0x00502aab)`, a NewUserShapeSelectControlPane deleting wrapper. Five `cc` bytes `[0x00502aab,0x00502ab0)` remain excluded alignment padding.
- Eight `cc` bytes `[0x00502b58,0x00502b60)` remain excluded alignment padding. Successor `sub_502B60`, `[0x00502b60,0x00502c0d)`, is UID0003LW ScrolledTextControlPane scalar deleting destructor.
- No function exists at `0x502aaf`, `0x502b58`, or `0x502b5f`. Neither padding span belongs in UID0001AI and neither warrants a new child page.
- Ordinary destructor remains `[0x004ff970,0x004ff9d7)` within UID00019Y. Its nine-byte `cc` pad `[0x004ff9d7,0x004ff9e0)` remains parent-internal compiler alignment before `OnTimerEvent`.
- Do not merge target into UID00019Y across unrelated executable code. The semantic relation is documented cross-range ownership, not physical range merging.
- Reclassification only: UID0001AI `TRUE -> FALSE`; no rename, split, child creation, endpoint change, optional position change, or nesting change.

## Negative Evidence Summary

- No ordinary direct call or source pointer reaches the target; only vtable and adjustor routes exist.
- No target RVA pointer exists, and literal target VA appears only at the primary vtable cell.
- No unique game-state mutation exists beyond the ordinary destructor. The frame-table cleanup and base teardown are duplicated source consequences.
- No `flags & 4` storage release, indirect call, vector-element loop, array count, or size-consuming deallocator exists. The direct callee is a no-op.
- No evidence supports a second destructor declaration, explicit scalar wrapper method, handwritten vptr stores, manual base destructor call, manual SEH/cookie code, or raw vtable/RTTI arrays.
- No evidence supports `Pane *parentPane`, narrow asset names, a generic palette-state field, or `EPFTileContext` at `+0x118`.
- Physical adjacency to unrelated deleting wrappers is compiler/linker layout evidence, not source-file ownership.
- Consumer helper calls do not make ImageFrameTable or PaletteLib the control owner.
- Absence of a direct constructor caller limits feature-use attribution only; it does not weaken the vtable/class/source relationship.

## IDA Rename / Type / Comment Recommendations

- No IDA mutation is requested or permitted.
- Keep the documentation title `ScrolledPictureControlPaneScalarDeletingDestructor`; it accurately describes ABI role without pretending to be a source member.
- Recommended source-facing types/names: `const RectBounds *bounds`, `const wchar_t *frameResourceName`, `const wchar_t *paletteName`, `unsigned char scrollDirection`, `ArchiveMetadataTable *m_frameTable`, `FrameDrawRecord m_frameDrawRecord`, `DLPalette *m_palette`, and `RectBounds m_destinationRect`.
- Keep `DestroyOwnedImageBlock`, `LoadImageFrameTable`, `LoadFrameDrawRecord`, `GetPaletteByName`, and `GetCurrentPalette` as current project-consistent descriptive names. Exact original spellings are not symbol-proven and remain documented as inferred.
- Do not propagate raw labels `sub_502AB0`, `Block`, `dword_67A744`, `var_4`, `arg_0`, or vftable address constants into human C++.

## First-Draft C++ Recommendation

Eligible source destinations are UID00019Y and UID0000CH. UID0001AI, UID0001AD, and UID00025Q are compiler/non-emitting evidence and must have blank managed bodies.

### R0 - UID0001AI exact blank formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: the target is reached only as a deleting vtable entry, takes compiler flags, returns the complete object, duplicates ordinary destruction, conditionally frees storage, contains SEH/cookie lowering, and is reached through compiler adjustors. A public virtual ordinary destructor declaration plus R1 causes equivalent compiler output; explicit source would be a duplicate ABI artifact.

### R1 - UID00019Y complete replacement formal block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum ScrolledPictureDirection {
    kScrollUp = 0,
    kScrollRight = 1,
    kScrollDown = 2,
    kScrollLeft = 3
};

ScrolledPictureControlPane::ScrolledPictureControlPane(
    const RectBounds *bounds,
    const wchar_t *frameResourceName,
    const wchar_t *paletteName,
    int scrollInterval,
    int scrollStep,
    unsigned char scrollDirection)
    : ControlPane(8, bounds),
      m_scrollInterval(scrollInterval),
      m_scrollStep(scrollStep),
      m_scrollDirection(scrollDirection),
      m_frameTable(NULL),
      m_palette(NULL)
{
    memset(&m_frameDrawRecord, 0, sizeof(m_frameDrawRecord));

    m_frameTable = LoadImageFrameTable(frameResourceName, 0);
    LoadFrameDrawRecord(m_frameTable, 0, &m_frameDrawRecord);

    if (paletteName != NULL)
        m_palette = g_pPaletteLib->GetPaletteByName(paletteName);
    else
        m_palette = g_pPaletteLib->GetCurrentPalette();

    int frameWidth = m_frameDrawRecord.sourceRect.right - m_frameDrawRecord.sourceRect.left;
    int frameHeight = m_frameDrawRecord.sourceRect.bottom - m_frameDrawRecord.sourceRect.top;
    int paneWidth = m_bounds.right - m_bounds.left;
    int paneHeight = m_bounds.bottom - m_bounds.top;
    int centeredLeft = (paneWidth / 2) - (frameWidth / 2);
    int centeredTop = (paneHeight / 2) - (frameHeight / 2);

    switch (m_scrollDirection) {
    case kScrollUp:
        InitRectBounds(&m_destinationRect, centeredLeft, m_bounds.bottom,
            centeredLeft + frameWidth, m_bounds.bottom + frameHeight);
        break;
    case kScrollRight:
        InitRectBounds(&m_destinationRect, -frameWidth, centeredTop,
            0, centeredTop + frameHeight);
        break;
    case kScrollDown:
        InitRectBounds(&m_destinationRect, centeredLeft, -frameHeight,
            centeredLeft + frameWidth, 0);
        break;
    case kScrollLeft:
        InitRectBounds(&m_destinationRect, m_bounds.right, centeredTop,
            m_bounds.right + frameWidth, centeredTop + frameHeight);
        break;
    }

    m_timerHandler.ScheduleTimer(0, m_scrollInterval, 0, 0);
}

ScrolledPictureControlPane::~ScrolledPictureControlPane()
{
    DestroyOwnedImageBlock(m_frameTable);
}

bool ScrolledPictureControlPane::OnTimerEvent(int eventId, int param1, int param2)
{
    int dx = 0;
    int dy = 0;

    switch (m_scrollDirection) {
    case kScrollUp:
        dy = -m_scrollStep;
        break;
    case kScrollRight:
        dx = m_scrollStep;
        break;
    case kScrollDown:
        dy = m_scrollStep;
        break;
    case kScrollLeft:
        dx = -m_scrollStep;
        break;
    }

    OffsetRect(&m_destinationRect, dx, dy);
    InvalidateRect(&m_bounds);
    m_timerHandler.ScheduleTimer(0, m_scrollInterval, 0, 0);
    return true;
}

void ScrolledPictureControlPane::OnPaintFrame()
{
    SetDrawColor(0);
    PrepareRenderRegion(this, &m_bounds);
    BlitFrame(this, &m_frameDrawRecord, &m_frameDrawRecord.sourceRect,
        &m_destinationRect, 1, m_palette, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R1 preserves all current core behavior while correcting only source-shape blockers proven in this pass. `memset` expresses the observed 40-byte zero-initialization without falsely changing `FrameDrawRecord` into `EPFTileContext`. Unused event parameters remain named because the ABI accepts them; no decompiler casts, offsets, vptr stores, base-destructor calls, or scalar flags appear.

### R2 - UID0000CH exact class formal block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScrolledPictureControlPane : public ControlPane
{
public:
    ScrolledPictureControlPane(
        const RectBounds *bounds,
        const wchar_t *frameResourceName,
        const wchar_t *paletteName,
        int scrollInterval,
        int scrollStep,
        unsigned char scrollDirection);
    virtual ~ScrolledPictureControlPane();
    virtual void OnPaintFrame();
    virtual bool OnTimerEvent(int eventId, int param1, int param2);

private:
    int m_scrollInterval;
    int m_scrollStep;
    unsigned char m_scrollDirection;
    ArchiveMetadataTable *m_frameTable;
    FrameDrawRecord m_frameDrawRecord;
    DLPalette *m_palette;
    RectBounds m_destinationRect;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R2 closes the class before `[[CHILDREN]]`. Natural 32-bit alignment supplies the three bytes after `m_scrollDirection`; no reverse-engineering padding member or raw offset comment belongs in source.

### R3 - UID0001AD exact blank formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The compiler regenerates both receiver-adjusting entries from R2's virtual contract and the inherited three-view class layout.

### R4 - UID00025Q preserved blank aggregate formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The broad mixed `.rdata` aggregate remains non-emitting. R2 and the method definitions are the source causes of its exact ScrolledPicture vtable bytes.

## Final Recommendation

- C01-C20 are implemented without compressing the exact bytes, instruction/CFG, flag, vtable, helper, negative, source-placement, layout, or historical evidence.
- UID0001AI is non-reconstructable compiler output under class owner UID0000CH with blank emitter, exact title/range/position/nesting, and blank R0.
- UID00019Y owns one ordinary source destructor and complete R1; no scalar wrapper declaration or definition was created.
- Class R2 and thunk R3 are exact, aggregate R4 remains blank, and all accepted support scores/current-state prose are applied.
- UID00025Q's bounded ScrolledPicture endpoint/cells are corrected without splitting or otherwise changing the broad aggregate.
- Leave all verify-only helper/type/base/operator-delete pages unchanged because current evidence is same-or-greater and no contradiction was found.
- There is no target-specific future research blocker. Exact original spellings/access token remain documented confidence caps only.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md`.
- Metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000CH`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, R0 blank, `Nested:0`.
- Exact Item Summary: `Compiler-generated MSVC scalar-deleting destructor clone for ScrolledPictureControlPane; duplicates ordinary frame-table cleanup and Pane teardown, implements exact bit-1/bit-4 deletion ABI, returns complete this, and is reached only by the primary vtable plus two adjusted vtable thunks. Human source is the one virtual ordinary destructor in UID00019Y.`
- Implemented detail includes exact range/size/hash, first/last bytes, predecessor/successor/padding, full instruction inventory, five-local versus nine-IDA CFG explanation, ABI, flag matrix, vtable writes, complete xref/callee inventory, helper roles, ordinary-body comparison, and no-code proof.
- Historical reconstructable-wrapper and indirect-guard wording is explicitly superseded while useful earlier evidence and correction history remain.
- Rejected alternatives and all negative evidence remain, especially no direct caller, no unique source behavior, no real flag-4 deletion, and no handwritten compiler mechanics.

## Recommended Support Doc Changes

- `by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md` UID00019Y:
  - Implemented `88/90 -> 92/93`; owner/emitter UID0000CH, true, blank position, `Nested:0`, exact aggregate range/tables/padding and all unrelated behavior are preserved.
  - R1 is exact. Live ordinary hash/comparison, corrected constructor signature/types, `DLPalette *m_palette` helper evidence, and sole-source-destructor ownership are current.
  - The B004 offline-MCP limitation and stale constructor/palette names are historicalized without erasing useful raw evidence.
- `by-class/ScrolledPictureControlPane.md` UID0000CH:
  - Implemented `85/88 -> 91/93`; owner/emitter UID0000NH, true, and blank position are preserved.
  - R2 is exact with class closed before `[[CHILDREN]]`; the `0x154` layout table, three-view virtual-destruction evidence, compiler/source decomposition, and access/name confidence caps are current.
- `by-file/ScrolledPictureControlPane.md` UID0000NH:
  - Implemented `88/85 -> 91/92`; path `NexusTK/ui/controls/` and `CANONICAL_OWNER:FILE` are preserved.
  - Current inventory is synchronized: UID00019Y emits constructor/ordinary destructor/timer/paint; UID0001AI and UID0001AD are compiler-only, class-owned, blank, and non-duplicative. Unresolved feature-level constructor reachability remains a nonblocking history fact.
- `by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md` UID0001AD:
  - Implemented `85/90 -> 90/94` and canonical owner `NONE -> 0000CH`; false, blank emitter/position/formal, `Nested:0`, exact range and both bytes/routes are preserved.
  - R3 remains blank and guidance models the source virtual ordinary destructor, not the scalar wrapper.
  - Exact Item Summary: `Two compiler-generated destructor adjustor entries subtract 0xa0 and 0xa4 from secondary/tertiary receivers and tail-jump to UID0001AI; exact vtable routes and bytes are preserved while human source remains the ordinary virtual destructor.`
- `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` UID00025Q:
  - Scores/metadata/routes/formal stay `86/92`, owner NONE, false, blank, `Nested:0`, R4 blank.
  - Bounded prose now gives exact ScrolledPicture subrange `[0x0061d88c,0x0061d930)`, primary/secondary/tertiary bases and target/thunk/timer/paint cells. All unrelated mixed aggregate/resource content is preserved.
- Verify-only reread found no contradiction: UID0002P5, UID0002P6, UID0000UN, UID0002PB, UID000038, UID0000A2, UID000197, PaletteLib, DLPalette, and current Pane layout/vtable support remain unchanged.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Implemented | Metadata result | Reason not higher |
| --- | --- | --- | --- | --- |
| UID0001AI target | `86/90`, true, owner/emitter 0000CH | `92/94`, false, owner 0000CH, blank emitter | Exact compiler-only no-code target; range/title/position/Nested unchanged. | No original compiler source symbol/version proof and no need to claim source reconstructability. |
| UID00019Y core | `88/90` | `92/93` | Owner/emitter 0000CH, true, blank position/Nested unchanged. | Exact original identifiers and feature-level constructor route remain unavailable. |
| UID0000CH class | `85/88` | `91/93` | Owner/emitter 0000NH, true, R2. | Original access/member spellings and header organization are inferred. |
| UID0000NH file | `88/85` | `91/92` | Existing path/FILE owner unchanged. | Direct feature construction route remains absent. |
| UID0001AD thunks | `85/90`, owner NONE | `90/94`, owner 0000CH | False, blank emitter/formal/position, Nested unchanged. | Compiler artifacts are fully understood but not source code. |
| UID00025Q aggregate | `86/92` | unchanged | False/NONE/blank; bounded vtable prose correction. | Broad aggregate still contains many unrelated source families. |

Score-improvement audit:

- Range/boundary blocker: resolved by live lookup, full bytes/hash, neighbor functions, and exact padding.
- CFG/instruction blocker: resolved by full local listing and external-handler accounting.
- Flag/helper blocker: resolved by both branch paths and direct callee bodies, including no-op flag-4 proof.
- Ownership/emitter blocker: resolved by three vtable views and ordinary/scalar comparison; source and compiler destinations are now separated.
- Field/type/layout blocker: resolved through constructor writes, exact support types, palette helpers, base constructor, and `0x154` size immediate.
- C++ blocker: resolved with complete R1/R2 and blank R0/R3/R4 no-code proof.
- Source placement blocker: existing class/file route is proven; only feature-level reachability remains absent and does not limit reconstruction.
- Name/access blocker: best current source-facing names and public virtual access are selected; lack of PDB proof is a score cap, not a deferral.

## Open Questions With Attempted Resolution

- Was UID0001AI partly source authored? Compared every physical instruction and state effect with ordinary destructor, storage delete, thunks, and compiler handlers. Resolution: no unique source statement exists; it is entirely compiler ABI glue.
- Does flag 4 perform sized/guarded deletion? Inspected branch, arguments, direct callee, and absence of indirect call/free. Resolution: no; it calls a one-byte no-op and returns `this`.
- Is `dword_67A744` a source dependency? Traced use into a stdcall helper that gets its own memory manager. Resolution: no source-visible effect in this body.
- What is the exact constructor shape? Rechecked six stack args, `retn 0x18`, first-arg flow into `ControlPane`, wide-string uses, and byte direction. Resolution: R1/R2 signature.
- What is the field at `+0x140`? Rechecked both PaletteLib callees and current class return types. Resolution: `DLPalette *m_palette`.
- Is the 40-byte record `EPFTileContext`? Compared current UID0000UN declarations/consumers. Resolution: distinct `FrameDrawRecord`; equal size and shared zeroing are insufficient for type identity.
- Is public destructor access original-proof? No stripped-binary mechanism encodes the exact token. Public virtual is the best source-facing convention supported by vtable deletion/lifecycle use; this is documented inference and only caps confidence.
- Are exact original member/helper spellings recoverable now? Current IDB, docs, historical reports, generated source, xrefs, and strings contain no PDB/source symbols. The selected project-consistent names are behaviorally exact. No unresolved issue blocks C++ or metadata.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only comparison found six stale manual rows at research/callback audit time. B003 did not apply these rows directly. The exact replacement text below is retained as durable supervisor-owned manual coverage synchronization evidence; its external application state is not asserted here.

File: `by-memory/-coverage-report.md`.

Replace UID0001AI row with:

```text
    - [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md) 0x00502ab0-0x00502b58 | compiler scalar deleting destructor | ScrolledPictureControlPaneScalarDeletingDestructor : ignored : 92% : very-strong : Exact 168-byte MSVC deleting-destructor clone with three class vtable restores, owned frame-table cleanup, Pane teardown, complete bit-1/bit-4 ABI, primary plus two adjusted vtable routes, complete-object return, and blank no-code disposition; UID00019Y owns the sole source destructor.
```

Replace UID00019Y row with:

```text
    - [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md) 0x004ff7d0-0x004ffa9f | class method cluster | ScrolledPictureControlPaneCore : reconstructable : 92% : very-strong : Source-ready constructor, sole ordinary virtual destructor, timer and paint definitions with exact method/table/padding boundaries, corrected bounds/wide-resource signature, 0x154 class layout, frame-table ownership, DLPalette route, vtable evidence, and compiler-wrapper separation.
```

Replace UID0001AD row with:

```text
    - [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md) 0x00502550-0x00502566 | compiler destructor adjustor thunks | ScrolledPictureControlPaneDestructorThunks : ignored : 90% : very-strong : Exact 0xa0/0xa4 receiver-adjusting vtable entries for UID0001AI; class-owned compiler output with blank emitter/formal C++ and source cause in the ordinary virtual destructor.
```

Replace UID00025Q row with:

```text
    - [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) 0x0061d264-0x0061e5b4 | mixed vtable/string-data aggregate | MainMenuNewUserReadOnlyData : ignored : 86% : very-strong : Non-emitting mixed index for main-menu, account, scrolled-control, staff/history, selector, and resource data; exact children/source classes carry ownership, including the bounded ScrolledPictureControlPane three-view vtable subrange 0x0061d88c-0x0061d930.
```

File: `by-class/-coverage-report.md`.

Replace UID0000CH row with:

```text
- [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md) : reconstructable : 91% : very-strong : Exact 0x154 ControlPane-derived layout and source-ready class declaration for bounds/wide-resource construction, one virtual ordinary destructor, timer/paint callbacks, frame-table/frame-record/DLPalette state, and compiler-generated three-view deleting-wrapper routes.
```

File: `by-file/-coverage-report.md`.

Replace UID0000NH row with:

```text
- [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md) : reconstructable : 91% : very-strong : Source-ready ui/controls module for the ScrolledPictureControlPane class and constructor/ordinary destructor/timer/paint definitions; deleting wrapper, adjustor thunks, vtables, SEH, and cookie mechanics remain documented compiler output with no duplicate source emission.
```

Reason B003 must not apply them: all manual `-coverage-report.md` files are supervisor-owned and explicitly outside this assignment's write scope. Validator-owned generated coverage refresh does not replace this manual synchronization.

## Follow-Up Actions

- The bounded technical callback is complete: target/support changes and R0-R4 were applied exactly, each changed ordinary by-* page received scoped validation, and waited by-file refresh/readback proved C19.
- Verify-only dependency reread found no concrete contradiction and no scope expansion was made.
- External report validation, execution, count, path, move, archive, and manual coverage state are supervisor/validator-owned and are neither asserted nor directed by this artifact.
- No additional B003 research target is started by this report.

## Confidence

- Recommendation confidence: `94/100` for compiler-only target disposition, class ownership, ABI, and no-code result.
- Score confidence: high. Target/core/class/file/thunk scores reflect exact evidence breadth while retaining realistic caps for stripped identifiers and original access/header details.
- Remaining uncertainty: exact original member/helper spellings, exact destructor access token, historical header/include organization, and feature-level construction route. None changes behavior, ownership, range, source placement, or emission disposition.

## Validator Results

- UID0001AI target: command `000000011249`, timestamp `2026-07-14T09:42:29-04:00`, scoped `--apply --queue-timeout 240`, exit `0`, `ok:1`. Applied `92/94`, true-to-false reconstruction state, emitter `0000CH -> blank`, reference updates, and deferred generated refresh. Warning: `missing_ref_uid 0003LW`; the linked successor page exists with UID0003LW, but that UID is absent from validator-owned registry state. No manual registry edit was made.
- UID0001AD thunks: command `000000011252`, timestamp `2026-07-14T09:43:36-04:00`, scoped apply, exit `0`, `ok:1`. Applied `90/94`, owner `NONE -> 0000CH`, reference update, and deferred generated refresh.
- UID00019Y core: command `000000011262`, timestamp `2026-07-14T09:46:02-04:00`, scoped apply, exit `0`, `ok:1`. Applied `92/93`, refreshed formal hash/reference state, and deferred generated refresh; R1 exact comparison passed before validation.
- UID0000CH class: first command `000000011271`, timestamp `2026-07-14T09:49:10-04:00`, reached `ok:1` and applied `91/93` plus blank-to-block formal registry state, but the shell wrapper terminated at 11 seconds with transport exit `124`. The lease was retained solely for clean confirmation. Retry command `000000011273`, timestamp `2026-07-14T09:49:35-04:00`, same scoped apply, exit `0`, `ok:1`, no incremental metadata defect; R2 exact comparison passed and the lease was then released.
- UID00025Q aggregate: command `000000011275`, timestamp `2026-07-14T09:50:44-04:00`, scoped apply, exit `0`, `ok:1`. Scores/routes/R4 remained unchanged; references were indexed and generated refresh deferred. Warning: pre-existing `missing_ref_uid 00036V` from unchanged DirectionButton support; no validator-state edit was made.
- UID0000NH file and final waited refresh: command `000000011279`, timestamp `2026-07-14T09:53:11-04:00`, scoped apply with `--wait-generated`, exit `0`, `ok:1`. Applied `91/92`, rebuilt validator-owned autogen registry, refreshed validator-owned generated metadata/tracker outputs, and completed generated refresh. Broad project diagnostics (`autogen_children_marker_missing`, `autogen_emitter_has_no_code`, and fallback inserts) concern unrelated pages and do not contradict this destination.
- Generated readback: `auto-generated/NexusTK/ui/controls/ScrolledPictureControlPane.cpp`, validator header command `000000011279`, refreshed `2026-07-14T09:53:11-04:00`, file last-write `2026-07-14T09:53:22.4407674-04:00`, length `4187`, SHA256 `28C2F28F52F2C15ED38C048C12501D8F0E955817B491B0E0E179FC655D1F9CB8`.
- Generated assertions: class start offset `412`, class close offset `1090`, first qualified definition offset `1326`; class closes first. Class declaration count `1`; constructor/destructor/timer/paint counts `1` each; UID00019Y count `1`; UID0001AI/UID0001AD/UID00025Q counts `0`; `Empty Emitter Marker` count `0`. R1 is an exact generated substring and the R2 class body without the consumed `[[CHILDREN]]` marker is exact. Counts for raw offset comments, explicit base-destructor calls, storage deletion, scalar flags, vptr/vftable, RTTI, security cookie, C++ frame handler, target raw address, `sub_`, and `dword_` are all `0`.
- Later concurrent validator-owned refresh observed read-only: header command `000000011289`, refreshed `2026-07-14T09:58:29-04:00`, file last-write `2026-07-14T09:58:41.8657822-04:00`, length `4187`, SHA256 `F1AE65AED93EF7B311DEE80015A90D236AA7B1D01EF0A290F5C98308BA62846E`. Every structure/formal/count/forbidden-term assertion above remained identical; B003 did not invoke or modify this later external refresh.
- All six changed ordinary pages have a clean scoped `ok:1` validator result. No implementation validator remains.

## Changed Files

- Report updated in place: `tools/leaser/Agents/Agent-B003/research/0001AI-ScrolledPictureControlPaneScalarDeletingDestructor-empty-emitter-source-quality.md`.
- Modified ordinary pages:
  - `by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md`
  - `by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md`
  - `by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md`
  - `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`
  - `by-class/ScrolledPictureControlPane.md`
  - `by-file/ScrolledPictureControlPane.md`
- Validator-owned side effects from the authorized scoped commands include registry/reference/stat metadata and the waited generated/tracker refresh recorded above. B003 did not manually edit those files.
- Renamed: none.
- Leases: each ordinary page was leased only while rereading/editing/validating that page, then released before the next lease. Final `current_leases.md` audit contains no B003 lease.
- Forbidden/manual set unchanged by B003: all manual `-coverage-report.md`, generated C++, tracker, audit, supervisor, validator-state, lifecycle, queue, lock, archive, and IDA files.
- Report execution/probe/count/revalidation/lifecycle/move/archive: no B003 command was run.

## Implementation Tracking Checklist

Completed research and implementation callback:

- [x] Exact report provenance, target path, historical/current metadata, lifecycle boundary, and healthy session-time MCP facts independently verified.
- [x] C01-C20 accepted atomically; each row uses legal action `incorporate`, legal final state `applied`, and claim-specific destination/validator/generated proof.
- [x] UID0001AI metadata changed to `92/94`, owner 0000CH, false, blank emitter/position/formal, `Nested:0`, exact title/range retained.
- [x] UID0001AI Item Summary and exhaustive range/hash/bytes/instruction/CFG/ABI/flags/vtable/xref/callee/helper/no-code evidence incorporated at report-level detail.
- [x] UID0001AI historical reconstructable-wrapper, indirect-guard, field/helper blocker, and empty-emitter wording corrected without deleting useful history.
- [x] R0 applied exactly and confirmed blank; no scalar wrapper, vptr, base-destructor, SEH, cookie, delete-flag, vtable, or RTTI source emitted.
- [x] UID00019Y raised to `92/93`, all exact aggregate ranges/tables/padding/unrelated behavior preserved, live ordinary hash/source ownership added, and R1 applied byte-for-byte.
- [x] UID0000CH raised to `91/93`, exact `0x154` layout/evidence/access caps added, and R2 applied with class closed before `[[CHILDREN]]`.
- [x] UID0000NH raised to `91/92`, existing path/FILE owner retained, complete source/compiler inventory and historical constructor-route caveat synchronized.
- [x] UID0001AD raised to `90/94`, canonical owner changed to 0000CH, false/blank/position/Nested/range retained, exact bytes/routes preserved, R3 confirmed blank, and source guidance corrected.
- [x] UID00025Q scores/metadata/route/R4 preserved; only exact ScrolledPicture subrange `[0x0061d88c,0x0061d930)` and bounded cell evidence added without changing unrelated aggregate content.
- [x] Verify-only UID0002P5, UID0002P6, UID0000UN, UID0002PB, UID000038, UID0000A2, UID000197, PaletteLib, DLPalette, and Pane/vtable support reread and left unchanged after no contradiction was found.
- [x] All source-facing constructor/field/helper/type names and rejected alternatives incorporated consistently across target/core/class/file/thunk support.
- [x] Exact predecessor/successor padding, ordinary internal padding, no-split/no-merge/no-rename, optional-position, and relative `Nested:0` dispositions preserved.
- [x] Every historical search root/term/match classification, B004 offline-MCP limitation, stale generated-name rejection, and positive/negative evidence preserved.
- [x] One short lease held only for each actively edited existing ordinary page; each page was reread after acquisition, scoped-validated, and released before the next page.
- [x] Scoped validators ran for every changed ordinary by-* page; command IDs/timestamps/exits/ok/warnings/side effects are recorded above.
- [x] Final waited UID0000NH refresh completed; generated header freshness, file timestamp/length/SHA256, structure, formal, and count assertions are recorded.
- [x] Generated `ScrolledPictureControlPane.cpp` closes the class before definitions, contains R1 constructor/destructor/timer/paint exactly once, has zero UID0000CH/UID0001AI Empty Emitter Markers, no scalar wrapper body, and no handwritten vtable/RTTI/EH/cookie code.
- [x] Exact supervisor-owned manual coverage replacement rows remain supplied above and no manual coverage file was edited by B003.
- [x] Changed-files, validator, generated, lease, current-state, recommendations, and checklist sections reflect durable implementation-complete truth without asserting or directing external lifecycle state.
- [x] No B003 lease remains and no generated/coverage/tracker/audit/supervisor/validator-state/lifecycle/archive file was manually edited.
- [x] Exact Gate-1 report artifact was accepted for this bounded implementation callback.
- [x] All accepted target/support details and R0-R4 were incorporated without Rule 26 compression.
- [x] All accepted metadata/score/owner/emitter/formal changes were applied exactly; no accepted item required exclusion or blocking.
- [x] Every accepted historical correction, rejected alternative, and negative fact remains.
- [x] No B003 implementation item remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000011299","destination_path":"executed-b-agent-research/B003/0001AI-ScrolledPictureControlPaneScalarDeletingDestructor-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001AI-ScrolledPictureControlPaneScalarDeletingDestructor-empty-emitter-source-quality.md","timestamp":"2026-07-14T10:11:11-04:00","uid":"0001AI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
