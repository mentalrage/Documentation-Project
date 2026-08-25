** TARGET-REPORT-UID:0004A6 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004A6 NewMacroEditControlPaneGetKey Source Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: implemented and verified. UID0004A6 remains the source-authored, nonvirtual `NewMacroEditControlPane::GetKey` accessor owned and emitted by UID000095 in the UID0000KY MacroDialogs source family.
- Final disposition: the accepted lifecycle-consistent `wchar_t` spelling is applied to the target return, `m_key` field, constructor parameter, and setter parameter. The method and field names, `const` qualifier, access level, exact range, owner/emitter, reconstructable state, optional position, and nesting remain unchanged.
- Completed action: Destinations 1-4 are byte-for-byte present in the target, class, constructor, and setter pages; UID0004A6 is `92/94`; UID000095 is `92/94`; UID0004A8 and UID0004AA keep their accepted scores; UID0001IK and UID0000KY contain the bounded no-loss support synchronization.
- Confidence: very strong for behavior, ABI, field offset and width, caller/storage lifecycle, owner/emitter, source file, and source order; strong for the exact private lexical spellings and the `wchar_t` source type because original symbols are unavailable and `wchar_t` is machine-equivalent to an unsigned 16-bit integer in this binary.
- Current lifecycle state: B005's implementation callback is complete and independently reviewable. Six ordinary pages passed scoped validation, waited generated command `000000014258` completed, manual coverage remains supervisor-owned and unedited by B005, no report lifecycle command was run, and zero B005 lease remains.

## Supporting Research

- The assigned queue row is current `86/90`, reconstructable true, and has direct report count zero in `auto-generated/-ag-research-tracker.md`.
- Exact old-report search terms used were: `0004A6`, `0x0057f9b0`, `NewMacroEditControlPaneGetKey`, `NewMacroEditControlPane`, `GetKey`, `m_key`, `CompactShortcutRecord`, `MacroDialogs`, and `MacroEditControlPanes`.
- Search roots actually checked:
  - `executed-b-agent-research`
  - `tools/leaser/Agents/Agent-B001/research`
  - `tools/leaser/Agents/Agent-B002/research`
  - `tools/leaser/Agents/Agent-B003/research`
  - `tools/leaser/Agents/Agent-B004/research`
  - `tools/leaser/Agents/Agent-B005/research`
  - `archived/b-agent-reports-20260623`
  - `tools/leaser/Agents/Older-Research`
- All five active B-agent research roots existed and contained no direct UID0004A6 report. The archive and older-research roots also contained no direct target-specific report.
- Matching reports opened:
  - `executed-b-agent-research/B001/0001IK-MacroEditControlPanes-empty-emitter-source-quality.md`: direct split/child-creation support, not a target-specific source-quality report. It established the exact target child range, direct class route, current provisional 16-bit source spelling, and internal padding inventory. Its provisional target type is superseded by the current full record lifecycle.
  - `executed-b-agent-research/B010/0001DR-MacroDialogs-source-quality.md`: direct caller and storage support. It established NewMacroDialog construction/save/load and the separate compact-record table. Its older generic key/modifier wording is useful history; current Config/type documentation resolves `code/isSpellMode`.
  - `executed-b-agent-research/B003/0004A5-SpellMacroEditControlPaneIsSelectable-source-quality.md`: incidental sibling and boundary evidence. It confirms the exact eleven-byte predecessor alignment and the New row EventHandler key store.
  - `executed-b-agent-research/B003/00049G-SpellMacroDialogNonDeletingDestructor-source-quality.md`: direct current class-closure support. It supplied the complete UID000095 declaration, ten-method inventory, source order, and natural layout, but retained the earlier `uint16_t` type.
  - `executed-b-agent-research/B003/0003UA-UserPaneDispatchConfiguredShortcutHotkey-source-quality.md`: direct compact-record type and full runtime-lifecycle evidence. This is the current authoritative support for `CompactShortcutRecord` as `wchar_t code` plus `unsigned char isSpellMode` and natural tail alignment.
  - `executed-b-agent-research/B002/0001IM-NewMacroEditControlPaneTeardownHelper-empty-emitter-source-quality.md`: incidental class/compiler-boundary support. It proves the teardown island is compiler-retained glue rather than a source destructor body.
  - `executed-b-agent-research/B003/0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality.md`: incidental owner/vtable support. It maps the New class vtable views and confirms the target is not a virtual slot.
  - `executed-b-agent-research/B005/0003UB-UserPaneExecuteHotkeyAction-source-quality.md`: related but distinct integrated-macro storage evidence. It is useful negative evidence against confusing the twenty compact records with the thirty `MacroHotkeyRecord` rows.
  - `executed-b-agent-research/B013/0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality.md`: older, superseded runtime ownership report. It remains a historical lead but is not current authority after the B003 UID0003UA report and current UserPane/Config union.
- Evidence-based prior-report conclusion: no prior direct UID0004A6 target-specific report exists. Existing reports cover the parent split, surrounding class, storage records, or consumers and therefore remain support evidence only.
- Historical lifecycle note: this report-only artifact passed exact-artifact Gate 1 at SHA256 `0EDE879241B5886F7475E690CDDEF6047433BC845117B27A91E0C42578B7D539`. The later implementation callback applied C01-C40 and Destinations 1-4; the original report-only `proposed` state is retained only as evidence-time provenance.

## Target

- Target UID: `0004A6`.
- Target path: `by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`, current row `86/90`, reconstructable true, direct report count zero.
- Current supervisor classification: new report-only direct source-quality audit.
- Current scores and parent state: target `92/94`; direct class UID000095 `92/94`; source file UID0000KY `92/92`; non-emitting split index UID0001IK `91/93`.

## Current Target State

- Current target metadata: `92/94`, owner UID000095, reconstructable true, emitter UID000095, blank optional emitter position, `Nested:0`.
- Current target C++: exact Destination 1 with `wchar_t GetKey() const`; full exact bytes/hash/PE, ABI/CFG, unique signature, sole caller, xref negatives, alignment, field lifecycle, type/name ranking, ownership/source placement, rejected alternatives, score rationale, and superseded integer-type history are present.
- Current class state: UID000095 is `92/94`; Destination 2 declares a natural `0x110` class with `wchar_t m_key` at `+0x10c`, byte mode at `+0x10e`, all ten methods, unchanged inheritance/compiler history, and class closure before `[[CHILDREN]]`.
- Current constructor/setter state: UID0004A8 and UID0004AA contain Destinations 3 and 4, retain `87/90` and `86/90`, and record the exact `CompactShortcutRecord::code` call/load/store lifecycle.
- Current support state: UID0001IK remains `91/93`, false, blank emitter/formal, `Nested:-4`, and complete; UID0000KY remains `92/92`, same path and source order. Both preserve all unrelated Macro/Spell/Integrate, raw-helper, compiler, vtable, padding, and physical-file evidence.
- Current generated state is read-only `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`, external validator command `000000014303`, refreshed `2026-07-16T15:51:05-04:00`, SHA256 `17287DE536CB3F9D06AE1FE91A569FF93C9E1F45A7FB71EB11789B796D39CA0E`, 34,779 bytes, 1,048 physical lines. B005's own final waited callback checkpoint remains command `14258`.
- Generated structural proof: UID000095 class line 725 closes at line 746 before first UID0004A6 definition at line 749; one class and one UID0004A6/UID0004A8/UID0004AA definition exist; all accepted key declarations/definitions use `wchar_t`; `record.code` occurs exactly three times in unchanged construction/save/load paths; old key types, UID0004A6 marker, raw `+0x10c`, vptr, duplicate record declaration, and decompiler names each count zero.
- Current artifact status: B005 changed the six accepted ordinary pages and this report only. Validator-owned generated/tracker/metadata outputs refreshed as side effects; B005 manually edited none of them. Zero B005 lease remains.

## Executive Recommendation

- Applied owner/emitter disposition: UID000095 remains the direct canonical owner and emitter. The target reads a private class field, is called as a normal member from NewMacroDialog save logic, and is absent from every NewMacroEditControlPane vtable.
- Applied source route/order: UID0000KY MacroDialogs remains the source-family file and UID000095 remains position `50` in deterministic `10/20/30/40/50/60` order.
- Applied split/nesting disposition: UID0001IK remains a non-emitting split index with `Nested:-4`; UID0004A6 remains `Nested:0`; no split, merge, rename, new UID, range, or padding change occurred.
- Applied source type: the key API and field use `wchar_t`, preserving exact two-byte ABI/layout and the `CompactShortcutRecord::code` lifecycle.
- Applied names: `GetKey` and `m_key` remain current; storage-facing `code` remains distinct from row-control-facing `key`.
- Applied score disposition: UID0004A6 and UID000095 are `92/94`; all other support scores remain unchanged.

## Supervisor Active Recheck

- The supervisor accepted exact report SHA `0EDE879241B5886F7475E690CDDEF6047433BC845117B27A91E0C42578B7D539` and authorized C01-C40 plus Destinations 1-4.
- Split repair remained unnecessary. The exact child range, both adjacent alignment spans, ignored coverage, and UID0001IK inventory stayed unchanged.
- Every source-bearing dependency has completed disposition:
  - target getter: Destination 1 applied and validated by commands `14250` and final `14258`;
  - complete class declaration: Destination 2 applied and validated by `14251`;
  - constructor synchronization: Destination 3 applied and validated by `14252`;
  - setter synchronization: Destination 4 applied and validated by `14253`;
  - UID0001IK support: applied and validated by `14254`;
  - UID0000KY support: applied and validated by `14256`;
  - save/load/NewMacroDialog, Config/type/runtime, compiler teardown/scalars/thunks/vtables/padding: reread and verified same-or-greater without edits.

## Inference Research Guidance Check

- `by-structure.md` ownership rules favor the immediate declaring class over a caller or storage type. The class field access and ordinary member call therefore keep UID000095 as owner/emitter; NewMacroDialog is a consumer, not the getter owner.
- Existing documentation assumptions were treated as hypotheses. Specifically, the current `uint16_t` spelling, older `GetKeyBinding` alias, and generic "key binding code" prose were rechecked against the binary and the now-complete Config/record lifecycle.
- Direct IDA facts are separated below from documentation evidence and source inference. The exact word load, AX return, caller store, field offset, xrefs, and boundaries are direct. The choice of `wchar_t`, `GetKey`, and `m_key` is high-probability source inference constrained by those facts and current source-family conventions.
- No current Wave2/Wave3 material was used as authority. The one Wave3 cross-reference retained in a support type page is stale project history and was ignored for this recommendation.

## Heuristic / Inference Reanalysis And Validation

1. **Function identity and source status.** IDA models `sub_57F9B0` as an exact eight-byte function containing one word load and one return. It has a real direct caller and is not an interior tail, duplicate inline copy, thunk, vtable entry, raw helper, or compiler-only fragment. The source-authored accessor disposition is retained.
2. **Return ABI.** The body loads only `AX` from `[ECX+0x10c]` and returns. The sole caller stores `AX` directly without reading or extending the upper half of `EAX`. The exact ABI is a 16-bit scalar return through `AX`; no signed extension behavior is observed.
3. **Field offset and width.** Constructor, getter, setter, input handler, and paint handler independently reference complete-object `+0x10c` as a two-byte field. The adjacent mode is one byte at `+0x10e`. No path reads or writes a four-byte key field, bitfield, pointer, or packed composite.
4. **Source type.** `wchar_t` is the strongest source-era type:
   - the complete Config declaration defines `CompactShortcutRecord::code` as `wchar_t`;
   - NewMacroDialog construction reads that word and passes it as the row key;
   - page load passes the same record field to `SetKey`;
   - page save stores getter `AX` back into the same record field;
   - input editing narrows an ASCII input byte and widens it into the two-byte row field;
   - paint zero-extends the two-byte field before normalization;
   - defaults, persistence, and runtime dispatch preserve the same code-unit role.
   `uint16_t`, `unsigned short`, and `wchar_t` are ABI-equivalent here, so the binary cannot prove the typedef spelling alone. The complete lifecycle and current project declaration make `wchar_t` more plausible than retaining a storage-agnostic integer type.
5. **Method name.** `GetKey` is retained. It matches `SetKey`, neighboring `GetMode`/`SetMode`, NewMacroDialog caller terminology, and the row-control UI role. `GetKeyBinding` is retained only as a historical descriptive alias. `GetCode`, `GetShortcutKey`, and `GetKeyCode` are rejected because no symbol or local convention supports them better.
6. **Field name.** `m_key` is retained. The control edits and displays a key, while the record stores the same value under the storage-oriented `code` role. Renaming the class field to `m_code` would weaken the UI class vocabulary and would not improve binary fidelity.
7. **Constness and access.** The getter does not write object state and is consumed externally by NewMacroDialog. Public `const` membership is the strongest source shape. A protected/private getter plus friendship has no evidence.
8. **Class layout.** Replacing a two-byte unsigned integer with two-byte `wchar_t` is layout-neutral on this x86/MSVC target. `m_recordIndex` remains `+0x108`, `m_key` remains `+0x10c`, `m_mode` remains `+0x10e`, and `+0x10f` remains natural tail alignment. No explicit padding member is needed.
9. **Direct versus virtual liveness.** The target has one code call and zero data/vtable xrefs. The three New class vtable heads are referenced only by constructor, compiler teardown, and scalar deleting destructor stores. The target remains an ordinary nonvirtual public member.
10. **Source placement.** Address clustering, direct callers, class declaration, positioned file route, vtable family, and generated order all support the existing MacroDialogs source placement. A separate key-helper file, Config method, NewMacroDialog method, or free helper would contradict the receiver and field access.
11. **Record distinction.** The twenty `CompactShortcutRecord` rows begin at Config `+0x28f29c`, have four-byte stride, and hold a code unit plus byte mode. The thirty `MacroHotkeyRecord` rows begin at `+0x28f2ec`, have `0x108` stride, and belong to IntegrateMacroDialog/runtime integrated macros. They must not be merged.
12. **Generated source quality.** The accepted shape should emit one coherent class declaration and one definition each for the target, constructor, and setter with matching `wchar_t` types. It should not emit casts, raw offsets, explicit tail bytes, decompiler temporaries, vptr mechanics, wrappers, or duplicate record declarations.

Rejected alternatives:

- Keep `uint16_t`: ABI-correct but source-inconsistent with the exact accepted record declaration and complete lifecycle.
- Use `unsigned short`: equally ABI-correct but less semantically aligned with the direct `wchar_t code` producer/consumer contract.
- Use `char` or `unsigned char`: rejected by the two-byte constructor/getter/setter field and word storage.
- Use `int` or an enum: rejected by exact 16-bit return/storage and absent conversion.
- Rename to `GetKeyBinding`/`m_keyBinding`: historical descriptive terminology only; current source-family API consistently uses `GetKey`/`SetKey`.
- Rename to `GetCode`/`m_code`: storage-facing terminology does not match the row-control method family.
- Make the method virtual: rejected by zero target data/vtable xrefs and the complete vtable inventory.
- Move ownership to NewMacroDialog, Config, RegistryConfig, or UserPane: rejected by direct `this+0x10c` New row field access and class-local setter/constructor symmetry.
- Add explicit padding, raw field offsets, casts, wrapper accessors, or a duplicate compact-record declaration: rejected as decompiler/layout scaffolding or duplicate source.

Unresolved issue:

- Original private lexical spelling cannot be proven without symbols. This does not block source emission because `GetKey`, `SetKey`, `m_key`, and `wchar_t` are mutually consistent, source-clean, ABI-exact, and supported by the complete consumer/storage lifecycle. It caps confidence below 95.

## Evidence Standards Used

- Direct evidence: healthy IDA MCP function lookup, decompilation, disassembly, analysis, xrefs, exact bytes, signature generation, bounded text/immediate search, vtable globals, and bounded caller/callee inspection.
- Independent raw evidence: current NexusTK PE bytes at the mapped file offset, whole-file SHA256, target-byte SHA256, PE imagebase, and `.text` placement.
- Structural evidence: exact class allocation/layout, constructor stores, adjacent getter/setter widths, handler writes, paint reads, vtable heads, source order, parent split, and ignored padding.
- Lifecycle evidence: Config defaults and declaration, NewMacroDialog construction, page load, input mutation, paint use, page save, profile persistence, and runtime shortcut dispatch.
- Documentation evidence: current by-* pages, current generated MacroDialogs source, manual coverage rows, tracker row, and matching executed B reports.
- Negative evidence: no target data xref, no vtable entry, no alternate caller, no second field width, no explicit tail-byte access, no nested-profile route, no MacroHotkeyRecord overlap, and no direct prior target report.
- The evidence is strong enough for source-ready C++ because behavior, type width, field placement, lifecycle, owner, file, order, and class layout all converge. Confidence remains capped only for exact private lexical spelling and machine-equivalent type spelling.

## Evidence Checked

- Fresh MCP availability recheck on 2026-07-16:
  - JSON-RPC `idb_list` request `232` returned one active/adopted/owned worker session `64c11373` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, PID/worker PID `21508`, `is_analyzing:false`.
  - Schema-current `server_health` request `242` with `database=64c11373` returned `status:ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and 2,067 cached strings.
  - Schema-current bounded `get_bytes` request `262` with region `0x0057f9b0`, size 16 returned the expected target bytes followed by eight `0xcc` bytes.
  - Earlier calls using the obsolete argument name `database_session` were rejected before IDB access and were not used as evidence. A Windows PowerShell/curl quoting/parser issue also occurred before valid MCP parsing and is not an MCP outage.
- Comprehensive bounded MCP evidence pass under database session `64c11373` checked:
  - target lookup, disassembly, decompilation, analysis, xrefs, exact signature, and bytes;
  - predecessor/successor boundaries and padding;
  - NewMacroDialog save and load helpers;
  - NewMacroDialog constructor callsite;
  - target constructor, setter, mode getter/setter, input handler, and paint handler;
  - New class vtable heads and their constructor/teardown/scalar-wrapper stores;
  - bounded `+0x10c` field-reference search within the New row method island.
- Raw PE checks:
  - executable `E:\NTK\Resources\NexusTK\NexusTK.exe`;
  - SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`;
  - size 2,679,296 bytes;
  - PE32 x86, imagebase `0x00400000`;
  - target RVA `0x17f9b0`, `.text` file offset `0x17edb0`;
  - exact target bytes `66 8B 81 0C 01 00 00 C3`;
  - target-byte SHA256 `E530E57FAAED293FEF0A8B0145F6234BED015D7389F78441F4D4C8EB713A3885`.
- Current ordinary docs opened: target; UID000095; UID0000KY; UID0001IK; UID0004A7/4A8/4A9/4AA/4AB/4AC/4AD/4AE/4AF; UID00049J/49N/49O; NewMacroDialog class; Config class/file; RegistryConfigUserProfileBlock; ignored padding.
- Historical report-only generated baseline opened read-only: `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`, command `14231`, SHA256 `A7033A468E0C5B747D77A59447DEBC4B0F8871E857FF146EE13A5B2EF5B2BF09`. B005 callback proof is waited command `14258`; external command `14262` was an intermediate post-callback checkpoint, and current external generated authority is command `14303`, which preserves the same assertions.
- Current manual coverage opened read-only: by-memory, by-class, by-file, and by-struct coverage reports.
- Current tracker opened read-only: `auto-generated/-ag-research-tracker.md`.
- Negative checks performed:
  - target xrefs contain exactly one code call and no data refs;
  - target address does not occur in New class vtable data;
  - no source path other than MacroDialogs has a coherent class-local route;
  - no lifecycle path treats compact-record byte `+3` as a source field;
  - no current direct target report exists.
- Failed or unavailable research checks:
  - IDA has no modeled function at runtime compact-dispatch address `0x005a3a20`, although bounded bytes exist there. This is not a target blocker because current executed UID0003UA evidence, Config/type docs, and direct NewMacroDialog save/load paths independently close the record contract.
  - During the original report-only pass, no IDA mutation, symbol rename, type application, implementation validator, generated refresh, lifecycle command, or report execution was attempted. That no-validator statement is historical report-only provenance, not the current callback state.
- Completed callback checks:
  - scoped target validation `14250`, `2026-07-16T15:28:32-04:00`, exit `0`, `ok:1`;
  - scoped class validation `14251`, `2026-07-16T15:29:38-04:00`, exit `0`, `ok:1`;
  - scoped constructor validation `14252`, `2026-07-16T15:30:19-04:00`, exit `0`, `ok:1`;
  - scoped setter validation `14253`, `2026-07-16T15:31:01-04:00`, exit `0`, `ok:1`;
  - scoped aggregate validation `14254`, `2026-07-16T15:32:16-04:00`, exit `0`, `ok:1`;
  - scoped file validation `14256`, `2026-07-16T15:33:52-04:00`, exit `0`, `ok:1`;
  - final waited target refresh `14258`, `2026-07-16T15:34:46-04:00`, exit `0`, `ok:1`, generated refresh completed.
- The final generated readback checked class closure/order, exact accepted declarations/definitions, old-type/marker/scaffolding negatives, and unchanged `record.code` construction/save/load behavior. All assertions passed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0004A6 is exactly `[0x0057f9b0,0x0057f9b8)`, eight bytes, with bytes `66 8B 81 0C 01 00 00 C3` and SHA256 `E530E57FAAED293FEF0A8B0145F6234BED015D7389F78441F4D4C8EB713A3885`. | Very strong | Target exact binary section; SHA `9BF192...4472`; validator `14250`, final `14258` | UID0004A6 | incorporate | applied |
| C02 | IDA models one two-instruction function: word load from complete-object `+0x10c` into AX, then return; one block, complexity 1, thiscall receiver in ECX, no stack arguments. | Very strong | Target ABI/CFG section; validator `14250` | UID0004A6 | incorporate | applied |
| C03 | The target is executable `.text` code at RVA `0x17f9b0`, raw file offset `0x17edb0`, in the current 2,679,296-byte x86 PE. | Very strong | Target PE evidence; validator `14250` | UID0004A6 | incorporate | applied |
| C04 | Exact signature `66 8B 81 0C 01 00 00 C3` is unique in the analyzed image and needs no wildcard bytes. | Very strong | Target binary evidence; validator `14250` | UID0004A6 | incorporate | applied |
| C05 | Eleven `0xcc` bytes occupy `[0x0057f9a5,0x0057f9b0)` and eight `0xcc` bytes occupy `[0x0057f9b8,0x0057f9c0)`; both remain ignored alignment outside the target. | Very strong | UID0004A6/UID0001IK synchronized; ignored SHA `2348CA...1199` unchanged | UID0004A6/UID0001IK/ignored | already-present | already-present |
| C06 | The sole direct target caller is NewMacroDialog save at callsite `0x0053f1d2` in the function beginning `0x0053f180`. | Very strong | Target/class/file evidence; validators `14250`,`14251`,`14256` | UID0004A6/UID000095/UID0000KY | incorporate | applied |
| C07 | The target has zero data xrefs, zero vtable-slot refs, and no second code caller; it is an ordinary nonvirtual method. | Very strong | Target/class negative evidence; generated target marker count zero | UID0004A6/UID000095 | incorporate | applied |
| C08 | The save caller stores returned AX unchanged into the compact row word before separately storing the mode byte. | Very strong | Target/class/file lifecycle; unchanged generated line 695 | UID0004A6/UID000095/UID0000KY | incorporate | applied |
| C09 | NewMacroDialog load reads the compact row word with zero extension and passes it to UID0004AA before loading the byte mode and refreshing the row. | Very strong | Target/setter/class/file lifecycle; generated lines 712-717 | UID0004A6/UID0004AA/UID000095/UID0000KY | incorporate | applied |
| C10 | NewMacroDialog construction reads `record.code` as a zero-extended word and supplies it as the first UID0004A8 constructor argument. | Very strong | Constructor/class/file evidence; generated lines 622-627 | UID0004A8/UID000095/UID0000KY | incorporate | applied |
| C11 | Constructor, target, setter, input handler, and paint handler all agree that the key field is exactly two bytes at complete-object `+0x10c`. | Very strong | Target/class/constructor/setter evidence; validators `14250`-`14253` | Four changed key destinations | incorporate | applied |
| C12 | The input handler accepts ASCII letters, widens the narrowed byte into the `+0x10c` field, and writes the item/spell mode byte at `+0x10e`. | Very strong | UID0004AE reread SHA `290A2D...B6C7`; class/file synchronization | UID0004AE and support | already-present | already-present |
| C13 | OnPaint reads the key field as an unsigned two-byte value before normalization and uses the mode byte to choose item versus spell display data. | Very strong | UID0004AD reread SHA `C1FB8B...449C`; class/file synchronization | UID0004AD and support | already-present | already-present |
| C14 | `wchar_t` is the strongest source type because the same value is `CompactShortcutRecord::code` across defaults, constructor, load, input, paint, save, persistence, and runtime dispatch. | Strong | Destinations 1-4 exact parity; validators `14250`-`14253`; generated old-type counts zero | Target/class/constructor/setter/support | incorporate | applied |
| C15 | Current `uint16_t` and alternative `unsigned short` spellings are ABI-compatible but source-inferior; `char`, `int`, enum, pointer, packed field, and raw-offset forms are invalid. | Strong | Rejected/history sections in target/class/constructor/setter/aggregate/file | Six changed pages | reject-invalid | applied |
| C16 | Retain source method name `GetKey`; reject historical `GetKeyBinding` and weaker `GetCode`, `GetShortcutKey`, and `GetKeyCode` alternatives. | Strong | Target/class/file current naming and historicalization | UID0004A6/UID000095/UID0000KY | reject-stale | applied |
| C17 | Retain private field name `m_key`; reject `m_code` because `code` is the storage-record role while the row-control role is a key. | Strong | Class/target/aggregate/file vocabulary | UID000095 and support | incorporate | applied |
| C18 | Retain public visibility and `const`; no friendship, protected-only route, state write, or alternate access pattern is supported. | Strong | Destination 2 and generated class/definition | UID000095/UID0004A6 | already-present | already-present |
| C19 | Canonical owner/emitter remains UID000095 NewMacroEditControlPane; no owner or emitter metadata change is needed. | Very strong | Target metadata after `14250`; generated route | UID0004A6 | already-present | already-present |
| C20 | Source file remains UID0000KY MacroDialogs and class position remains 50 in the current 10/20/30/40/50/60 declaration order. | Very strong | Class/file metadata; generated class line 725 | UID000095/UID0000KY | already-present | already-present |
| C21 | UID0001IK remains a non-emitting split index with `Nested:-4`; UID0004A6 remains `Nested:0`; no split, merge, rename, or new UID is required. | Very strong | UID0001IK validator `14254`; target validator `14250` | Target/aggregate | already-present | already-present |
| C22 | The target remains reconstructable source code and must not become blank, covered-by, inline-only, raw-helper, compiler-no-code, or non-emitting metadata. | Very strong | Destination 1; generated one definition/zero marker | UID0004A6 | reject-invalid | applied |
| C23 | Raise UID0004A6 `86/90 -> 92/94`; preserve owner, emitter, true, blank optional position, title/path/range, and nesting. | Strong | Validator `14250` score updates; final generated metadata `92/94` | UID0004A6 | incorporate | applied |
| C24 | Raise UID000095 `91/93 -> 92/94`; its complete natural `0x110` declaration remains layout-identical after the two-byte type correction. | Strong | Validator `14251`; generated class lines 725-746 | UID000095 | incorporate | applied |
| C25 | Destination 1 is the complete source-clean target definition and contains no raw offsets, casts, extension scaffolding, or compiler mechanics. | Very strong | Formal SHA `2B7925...137A9` matches report/doc; generated getter count 1 | UID0004A6 formal | incorporate | applied |
| C26 | Destination 2 is the complete current class block with only the accepted key type changes and unchanged placement of `[[CHILDREN]]` after the class. | Strong | Formal SHA `80F424...0503` matches; class closes line 746 before definition line 749 | UID000095 formal | incorporate | applied |
| C27 | Destination 3 changes only UID0004A8's first parameter type; constructor order, base call, fields, selectable state, metadata, and score remain unchanged. | Strong | Formal SHA `1F667A...7882`; validator `14252`; generated constructor count 1 | UID0004A8 | incorporate | applied |
| C28 | Destination 4 changes only UID0004AA's parameter type; the exact assignment, metadata, score, range, and ownership remain unchanged. | Very strong | Formal SHA `209CB3...62D5`; validator `14253`; generated setter count 1 | UID0004AA | incorporate | applied |
| C29 | UID0004A7/UID0004AB mode API remains `uint8_t`; arbitrary byte copy and zero/nonzero runtime meaning reject narrowing it to `bool`. | Very strong | Verify-only hashes `9EAC49...F5CA` and `8E593A...27A`; generated unchanged | Mode pages | already-present | already-present |
| C30 | UID00049J/UID00049N/UID00049O already use `CompactShortcutRecord::code` and require no formal-body change; only bounded dependency prose/link verification is needed. | Very strong | Verify-only hashes unchanged; generated `record.code` count 3 | NewMacroDialog pages | already-present | already-present |
| C31 | UID0004AD/UID0004AE remain behaviorally and source-shape compatible with `wchar_t m_key`; their formal bodies and scores need no change. | Strong | Verify-only hashes unchanged; generated paint/input readback | Paint/input pages | already-present | already-present |
| C32 | Config class/file and UID0001VR already declare the exact compact row and need no C++ or score change. | Very strong | Verify-only hashes `9ECA99...B473`,`91984E...D577`,`3A449A...3AB8` | Config/type docs | already-present | already-present |
| C33 | CompactShortcutRecord and MacroHotkeyRecord remain distinct tables, offsets, strides, UIs, persistence roles, and runtime paths. | Very strong | Six changed pages preserve distinction; Config/type verify-only union | Target/class/file/aggregate | incorporate | applied |
| C34 | New class vtable data does not contain UID0004A6; vtable head xrefs are limited to constructor, compiler teardown, and scalar deleting destructor stores. | Very strong | Target/class evidence; vtable docs reread unchanged | UID0004A6/UID000095 | incorporate | applied |
| C35 | Internal padding ledger entries remain exact and require no duplicate ignored row or source representation. | Very strong | Ignored SHA `2348CA...1199` unchanged; UID0001IK applied wording | UID0001IK/ignored | already-present | already-present |
| C36 | Expected generated output is one complete class plus one target/constructor/setter definition with matched `wchar_t` types, unchanged save/load logic, and no target empty marker or raw ABI source. | Strong | B005 waited command `14258`; current external command `14303`, SHA `17287D...A0E`; all structural/count negatives passed | Generated readback | incorporate | applied |
| C37 | Manual coverage requires one by-memory insertion for UID0004A6 and one no-loss by-class replacement for UID000095; inspected file/struct/parent rows remain verify-only. | Strong | Current manual hashes/rows reread after `14258`; exact canonical-token handoff retained | Supervisor-owned handoff | incorporate | applied |
| C38 | Callback validation requires one scoped file validator per changed ordinary page and one final waited generated refresh; B005 must not edit generated or manual coverage files. | Very strong | Commands `14250`-`14256`, final `14258`; no manual restricted edits | Validator/results | incorporate | applied |
| C39 | Prior parent/class/storage reports are supporting or historical evidence only; none substitutes for this target report, and provisional `uint16_t` conclusions are superseded without deleting their useful split/layout proof. | Strong | Historical sections preserved across all changed pages | Supporting/history sections | historicalize | applied |
| C40 | No third-party import, IDA mutation, new source file, new class, new record type, report lifecycle action, or report execution applies. | Very strong | No such action occurred; zero lifecycle command; same existing source route | Checklist/follow-up | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- The target is a unique, modeled, directly called two-instruction function with exact raw bytes and exact field displacement.
- Constructor/getter/setter/input/paint evidence independently agrees on a two-byte key at `+0x10c`.
- NewMacroDialog constructor/load/save forms a closed bidirectional path between the row field and `CompactShortcutRecord::code`.
- Current Config and profile-layout declarations establish that record field as `wchar_t`, while runtime shortcut dispatch preserves it as a code unit rather than an opaque integer.
- The complete NewMacroEditControlPane class, vtable family, compiler destructor support, source file, and generated order are already resolved.
- The strongest inference chain is therefore: exact word field -> exact compact-record word -> accepted `wchar_t code` declaration -> source-consistent row API and field type. That chain changes no binary layout or behavior.

## IDA MCP Facts

- Database session: `64c11373`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active/adopted/owned worker PID `21508`.
- Health: `status:ok`; imagebase `0x400000`; auto-analysis, Hex-Rays, and strings cache ready.
- Target identity: `sub_57F9B0`, start `0x0057f9b0`, size `0x8`.
- Target instructions:
  - `mov ax, [ecx+10Ch]`
  - `retn`
- Target CFG: two instructions, one basic block, cyclomatic complexity 1, no strings/constants/callees.
- Target decompile: direct two-byte member return from element 134 in the IDA word-pointer view.
- Target ABI: x86 thiscall receiver in ECX; no stack arguments; 16-bit return in AX.
- Target xrefs: one code call at `0x0053f1d2` from the function beginning `0x0053f180`; zero data xrefs.
- Adjacent modeled functions:
  - predecessor pointer/mouse handler at `0x0057f9a0`, size `0x5`, ending `0x0057f9a5`;
  - successor mode getter at `0x0057f9c0`, size `0x7`.
- Padding:
  - `[0x0057f9a5,0x0057f9b0)`: eleven `0xcc`;
  - `[0x0057f9b8,0x0057f9c0)`: eight `0xcc`.
- Unique target signature: exact eight bytes, no wildcards.
- Save caller: call target, then store AX into the compact record word; call mode getter, then store AL into the compact record byte.
- Load caller: load compact record word with zero extension, call SetKey; load mode byte, call SetMode; call Refresh.
- NewMacroDialog constructor callsite: load `record.code` with zero extension, pass it as the first New row constructor argument, pass record index and `record.isSpellMode`.
- New row constructor: stores record index at `+0x108`, key word at `+0x10c`, mode byte at `+0x10e`, writes three class vtable views, and sets inherited selectable state.
- SetKey: stores the low word argument at `+0x10c` and returns with one four-byte stack argument consumed.
- Input handler: adjusted EventHandler receiver stores accepted narrowed ASCII input into complete-object `+0x10c` and writes mode at `+0x10e`.
- OnPaint: zero-extends the word at `+0x10c` before normalization.
- New class vtable globals: heads `0x0062d288`, `0x0062d2f0`, and `0x0062d320`; none contains the target address.
- Vtable-head xrefs are restricted to constructor, complete-object teardown helper, and scalar deleting destructor vptr stores.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0057f9b0-0x0057f9b8` | UID0004A6 target | Key getter | true | UID000095 | `92/94` | Destination 1 applied; validators `14250`,`14258` |
| `0x0057f9c0-0x0057f9c7` | UID0004A7 | Mode getter | true | UID000095 | `86/90` | verify-only, unchanged |
| `0x0057f9d0-0x0057fa2b` | UID0004A8 | Constructor | true | UID000095 | `87/90` | Destination 3 applied; validator `14252` |
| `0x0057fa30-0x0057fa40` | UID0004A9 | Record-index setter | true | UID000095 | `86/90` | verify-only, unchanged |
| `0x0057fa40-0x0057fa52` | UID0004AA | Key setter | true | UID000095 | `86/90` | Destination 4 applied; validator `14253` |
| `0x0057fa60-0x0057fa70` | UID0004AB | Mode setter | true | UID000095 | `86/90` | verify-only, unchanged |
| `0x0057fa70-0x0057fa7a` | UID0004AC | Refresh helper | true | UID000095 | `86/90` | verify-only, unchanged |
| `0x0057fa80-0x0057fa9e` | UID0001IM | Compiler complete-object teardown artifact | true/no standalone body | UID000095 semantics | `78/90` | verify-only no-code |
| `0x0057faa0-0x0057fc76` | UID0004AD | Paint | true | UID000095 | `88/91` | verify-only, unchanged |
| `0x0057fc80-0x0057fcff` | UID0004AE | Key/text handler | true | UID000095 | `90/93` | verify-only, unchanged |
| `0x0057fd00-0x0057fd05` | UID0004AF | Pointer/mouse handler | true | UID000095 | `91/94` | verify-only, unchanged |
| New class | UID000095 `by-class/NewMacroEditControlPane.md` | Complete class declaration | true | UID0000KY | `92/94` | Destination 2 applied; validator `14251` |
| Macro edit-control island | UID0001IK | Non-emitting split index | false | UID0000KY | `91/93` | bounded prose sync applied; validator `14254` |
| MacroDialogs source | UID0000KY | Source family/file | n/a | FILE | `92/92` | bounded prose sync applied; validator `14256` |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053f1d2` | NewMacroDialog save -> UID0004A6 | Sole direct target call; result stored as record word. |
| `0x0053f1e0` | NewMacroDialog save -> UID0004A7 | Adjacent mode getter; result stored as record byte. |
| `0x0053f27e` | NewMacroDialog load -> UID0004AA | Loads record code word into row key. |
| `0x0053f28d` | NewMacroDialog load -> UID0004AB | Loads record mode byte into row mode. |
| `0x0053ef2c` | NewMacroDialog constructor -> UID0004A8 | Constructs each row from record code/mode. |
| target data/vtable refs | none | Confirms ordinary nonvirtual method. |
| vtable heads | constructor/teardown/scalar-wrapper stores only | Confirms class identity without making target virtual. |

## Documentation Evidence And IDA Status

- Current target metadata, range, full evidence, score, and `wchar_t` body are applied and validator-confirmed.
- UID000095 is structurally complete at `92/94`; its class block and layout prose use the accepted `wchar_t` key spelling and preserve the complete class/compiler union.
- UID0004A8 and UID0004AA have the exact accepted parameter type and full lifecycle evidence while retaining their prior scores and metadata.
- UID00049J, UID00049N, and UID00049O already use direct `CompactShortcutRecord::code` / `isSpellMode` source and are behaviorally correct.
- Current Config class/file and UID0001VR already define the exact four-byte compact record and direct Config placement. They are verify-only dependencies, not new declaration destinations.
- Current UID0004AE and UID0004AD provide independent field-write/read evidence and remain source-compatible with a `wchar_t` field.
- Current generated MacroDialogs source is fresh at external command `14303`, SHA256 `17287DE536CB3F9D06AE1FE91A569FF93C9E1F45A7FB71EB11789B796D39CA0E`, and verifies the accepted source shape. B005 waited command `14258` is the completed callback checkpoint; historical command `14231` exposed the pre-callback mismatch, and external command `14262` is a superseded post-callback checkpoint.
- Manual by-memory coverage has no UID0004A6 row. Manual by-class coverage has a UID000095 row at `91%` that does not state the resolved `wchar_t` lifecycle. File and struct rows already describe the current complete source family and compact-record type.
- IDA remained healthy for fresh bounded checks. No fallback-only conclusion is present, and the callback did not mutate IDA.

## Ranked Ownership Analysis

### 1. UID000095 NewMacroEditControlPane

- Evidence for: direct `this+0x10c` access, symmetric constructor/setter/paint/input field use, complete class declaration, class-specific generated definition, and direct NewMacroDialog member call.
- Evidence against: none material. The method is nonvirtual, but nonvirtual public methods still belong to the declaring class.
- Decision: retain canonical owner and emitter UID000095.

### 2. UID000094 NewMacroDialog

- Evidence for: the sole target caller is NewMacroDialog save, and NewMacroDialog construction/load/save owns the compact-record UI flow.
- Evidence against: NewMacroDialog does not own the receiver field; it calls through a child `NewMacroEditControlPane *`.
- Decision: consumer only; preserve links and behavior evidence, do not assign ownership or emission.

### 3. UID000031 Config / CompactShortcutRecord

- Evidence for: Config owns the persistent compact-record storage and fixes the strongest key type.
- Evidence against: the target does not receive a Config object and accesses only NewMacroEditControlPane state.
- Decision: type/storage support only; no target ownership or new C++ destination.

### Proposed new file/grouping, if applicable

- Not applicable. UID0000KY MacroDialogs already contains the complete class and all related source definitions in deterministic order.
- A separate key helper, compact-record helper file, or NewMacroEditControlPane-only file would fragment the accepted family without binary or source-tree evidence.

## Source Placement

- Recommended source placement: UID000095 declaration and UID0004A6 body in `NexusTK/ui/dialogs/MacroDialogs.cpp` under UID0000KY, class position `50`.
- This placement fits the adjacent MacroDialogs method island, NewMacroDialog callers, shared resources, vtables, current file inventory, and generated ordering.
- Rejected placements:
  - Config/RegistryConfig/ProfileStorage: own persistence storage, not the row-control member.
  - UserPane: runtime consumer of compact records, not the editor class.
  - a new MacroEditControlPane file: current source family and declaration order already close the complete island.
  - header-only inline accessor: the binary retains a unique out-of-line function with a direct call.
- Remaining placement uncertainty: none that affects implementation. The broader historical question of whether all Macro dialog generations shared one original physical file remains a file-level confidence caveat, but current project source placement is established.

## Range / Split / Padding / Reclassification Analysis

- Exact target range remains `[0x0057f9b0,0x0057f9b8)`.
- Predecessor source method ends at `0x0057f9a5`; `[0x0057f9a5,0x0057f9b0)` is eleven-byte alignment.
- Successor source method starts at `0x0057f9c0`; `[0x0057f9b8,0x0057f9c0)` is eight-byte alignment.
- The target is neither an interior tail nor an aggregate boundary artifact. It has a unique function identity and direct caller.
- No new child, merge, rename, range repair, reclassification, or ignored entry is needed.
- UID0001IK remains the exact non-emitting parent inventory. Its current cumulative child organization and `Nested:-4` are unchanged.
- UID0004A6 remains `Nested:0`; the report does not reinterpret nesting as child count.

## Negative Evidence Summary

- No target data xref or vtable slot exists.
- No second caller, alternate receiver, free-function route, or source-module route exists.
- No key read/write uses four bytes, one byte, a pointer, or a bitfield.
- No caller consumes upper EAX bits or requires signed extension.
- No compact-record path treats the fourth byte as source state.
- No evidence supports `bool` for the mode byte; arbitrary nonzero values remain valid runtime spell mode.
- No evidence supports `m_userProfile`, RegistryConfig-only storage, a derived cast, raw-offset accessor, duplicate row type, or integrated `MacroHotkeyRecord` use.
- No symbols prove original lexical spelling; this limits confidence but does not justify an integer placeholder or blank source.
- No direct prior report exists; support reports cannot replace the direct target evidence pass.

## IDA Rename / Type / Comment Recommendations

- Source-facing method: `NewMacroEditControlPane::GetKey` retained and verified.
- Source-facing field: `m_key` retained and verified.
- Source-facing type: target return, class field/declaration, constructor first parameter, and setter parameter now use `wchar_t`.
- Keep `m_recordIndex` as `int`, `m_mode` as `uint8_t`, and the mode API unchanged.
- Keep target IDA database name unchanged during this assignment. The current IDB function is still `sub_57F9B0`; applying an IDA rename/type is not requested and B005 did not mutate IDA.
- Applied target documentation identifies the exact two-instruction `wchar_t` key accessor at `+0x10c`, sole NewMacroDialog save caller, direct compact-record code lifecycle, and nonvirtual class/file route.
- Intentionally unchanged: owner/emitter, range, nesting, source position, class inheritance, destructor source/compiler split, vtable pages, padding, and support record declarations.

## First-Draft C++ Recommendation

- Eligible for human C++: yes. The target is source-authored and directly called; all ABI, field, type, name, placement, and declaration blockers are closed.
- The following four accepted destination blocks are applied byte-for-byte. Their normalized report/doc SHA256 values are D1 `2B79257D35FBBE3D0C1F488DE5B29FC36A53D658E63118AD672B51FFA47137A9`, D2 `80F424455266A84B877C89EECD25C22DDCCF424C9AC6D8F4D4F5C6100EAA0503`, D3 `1F667A48951DFE4ECA06C92800CA4021B5562EA5004EF5ED7796B3D37FC57882`, and D4 `209CB3B7A04E759299899B1B39E48C9C0915AB73628316925DC33FEFE08F62D5`.

### Destination 1 - `by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
wchar_t NewMacroEditControlPane::GetKey() const
{
    return m_key;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - `by-class/NewMacroEditControlPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct Rect;

class NewMacroEditControlPane : public ControlPane
{
public:
    NewMacroEditControlPane(wchar_t key, int recordIndex, uint8_t mode, const Rect &bounds);

    wchar_t GetKey() const;
    uint8_t GetMode() const;
    void SetRecordIndex(int recordIndex);
    void SetKey(wchar_t key);
    void SetMode(uint8_t mode);
    void Refresh();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    int m_recordIndex;
    wchar_t m_key;
    uint8_t m_mode;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - `by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewMacroEditControlPane::NewMacroEditControlPane(wchar_t key, int recordIndex, uint8_t mode, const Rect &bounds)
    : ControlPane(8, bounds),
      m_recordIndex(recordIndex),
      m_key(key),
      m_mode(mode)
{
    SetSelectable(true);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - `by-memory/0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroEditControlPane::SetKey(wchar_t key)
{
    m_key = key;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: `wchar_t` remains a two-byte x86/MSVC scalar, so all offsets, calls, return registers, stack widths, object size, and row-record copies remain unchanged.
- Source-shape rationale: the code uses ordinary class fields and methods, matches the accepted Config record declaration, and contains no IDA labels, raw offsets, casts, ABI scaffolding, explicit padding, or duplicate record declaration.
- Naming convention: terse `GetKey`/`SetKey` and `GetMode`/`SetMode` pairs match the current MacroDialogs class-local style; `m_` private fields match the complete class declaration.
- Third-party import: not applicable. This is first-party game UI source and all managed blocks contain direct human C++.

## Final Recommendation

- Four exact managed blocks and bounded report-level evidence synchronization are applied and verified.
- Target metadata is `92/94`, owner UID000095, emitter UID000095, reconstructable true, blank optional position, `Nested:0`.
- Class metadata is `92/94`, owner/emitter UID0000KY, position 50, reconstructable true, complete class block with children after closure.
- UID0004A8 and UID0004AA retain their accepted scores with applied type/evidence synchronization.
- UID0004A7, UID0004A9, UID0004AB, UID0004AC, UID0004AD, UID0004AE, UID0004AF, UID00049J, UID00049N, UID00049O, NewMacroDialog, Config, UID0001VR, compiler support, vtables, and ignored padding were reread and verified without edits.
- Owner, emitter, path, split, range, nesting, title, UID, vtable, ignored-padding, and compiler-artifact routes remain unchanged.
- No B005 implementation item remains. Original private lexical spelling remains a confidence cap rather than an open blocker.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md`.
- Applied metadata:
  - completion `86 -> 92`;
  - confidence `90 -> 94`;
  - owner UID000095 unchanged;
  - reconstructable true unchanged;
  - emitter UID000095 unchanged;
  - blank optional position unchanged;
  - `Nested:0` unchanged.
- Formal: Destination 1 applied exactly and validated by commands `14250` and `14258`.
- Applied exact Item Summary:
  - `Exact two-instruction NewMacroEditControlPane wchar_t key accessor loading the +0x10c field into AX; sole NewMacroDialog save caller stores it unchanged into CompactShortcutRecord::code, with unique bytes/signature, exact alignment, direct class/file route, and no vtable/data xrefs.`
- Full exact bytes/hash/PE placement, function/ABI/CFG, sole caller, xref negatives, padding, constructor/load/save/input/paint lifecycle, type/name ranking, class/file ownership, direct/nonvirtual disposition, rejected alternatives, and score rationale are incorporated.
- Historical `uint16_t` body is preserved as superseded source spelling evidence, not current truth.

## Recommended Support Doc Changes

- `by-class/NewMacroEditControlPane.md`
  - Destination 2 applied exactly; formal parity SHA `80F424...0503`;
  - raised `91/93 -> 92/94` by validator `14251`;
  - preserve owner/emitter UID0000KY, position 50, true, inheritance, ten-method inventory, vtables, implicit virtual-destructor source cause, compiler helper/scalar/thunk separation, and children placement;
  - change current `+0x10c` field/type prose to `wchar_t`, retain `+0x10f` as natural tail alignment, and add exact constructor/load/save/input/paint/runtime record lifecycle;
  - historicalize the earlier `uint16_t` conclusion and older `GetKeyBinding` role alias.
- `by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md`
  - Destination 3 applied exactly; formal parity SHA `1F667A...7882`;
  - keep `87/90`, owner/emitter, range, title, true, blank position, and nesting;
  - add exact first-argument provenance from `CompactShortcutRecord::code`, zero-extended callsite load, two-byte store at `+0x10c`, and layout-neutral `wchar_t` rationale.
- `by-memory/0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey.md`
  - Destination 4 applied exactly; formal parity SHA `209CB3...62D5`;
  - keep `86/90`, owner/emitter, range, title, true, blank position, and nesting;
  - add exact load-page caller, two-byte stack argument/store, and compact-record code lifecycle.
- `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`
  - score, metadata, blank formal, `Nested:-4`, child inventory, and compiler/padding facts unchanged;
  - synchronized the New row closure to `wchar_t` key at `+0x10c`, preserved all ten source methods and implicit-destructor cause, and historicalized the provisional integer spelling; validator `14254` passed.
- `by-file/MacroDialogs.md`
  - score/path/file metadata/formal state unchanged;
  - synchronized the New row source inventory and generated expectations to the exact `wchar_t` getter/constructor/setter/class declaration; validator `14256` passed;
  - preserve all six class positions, every unrelated Macro/Spell/Integrate fact, and the broader physical-file caveat.
- Verified same-or-greater/no change after reread:
  - UID0004A7/4A9/4AB/4AC/4AD/4AE/4AF;
  - UID00049J/49N/49O and NewMacroDialog class;
  - Config class/file and UID0001VR;
  - UID0001IM, UID0004AV, UID0003DB, UID0001Y1;
  - `by-memory/-ignored.md`;
  - generated MacroDialogs output.

## Score And Metadata Recommendation

- Target before callback: `86/90`, owner/emitter UID000095, true, blank optional position, `Nested:0`.
- Target current/applied: `92/94`, all non-score metadata unchanged; validator `14250` accepted the score change.
- Class before callback: `91/93`, owner/emitter UID0000KY, position 50, true.
- Class current/applied: `92/94`, all non-score metadata unchanged; validator `14251` accepted the score change.
- UID0004A8 and UID0004AA scores remain `87/90` and `86/90`; this report synchronizes their type dependency without claiming independent near-final audits of every local behavior detail.
- Score rationale:
  - target completion rose because exact bytes/hash, ABI, CFG, caller, xrefs, boundaries, field lifecycle, source type/name, owner/emitter, source placement, generated shape, and formal body are closed;
  - target confidence rose because direct binary and independent lifecycle evidence converge;
  - class completion/confidence rose one point because its only declaration-level contradiction was resolved without layout or method-inventory uncertainty.
- Reason not higher:
  - no original symbol identifies the exact private method/field spelling;
  - x86/MSVC encodes `wchar_t`, `unsigned short`, and `uint16_t` identically here;
  - the broader physical-file history remains inferred even though current source placement is stable.
- Score-blocker audit:
  - exact function/range blocker: removed by MCP/raw bytes;
  - caller/liveness blocker: removed by sole direct xref and caller disassembly;
  - field offset/width blocker: removed by five independent class-local accesses;
  - source type blocker: removed by complete compact-record lifecycle;
  - name blocker: resolved by class-local API/storage vocabulary ranking;
  - owner/emitter/file blocker: removed by receiver, class, vtable, callers, and source order;
  - split/padding blocker: removed by exact adjacent functions and ignored ledger;
  - C++ blocker: removed by four complete managed destinations;
  - remaining lexical uncertainty is confidence-only and does not block the completed implementation.
- Metadata outcome: only UID0004A6 and UID000095 scores changed. Every owner, emitter, reconstructable, position, nesting, path, range, title, and UID field remained unchanged.

## Open Questions With Attempted Resolution

- **Is the field `wchar_t`, `uint16_t`, or unsigned short?**
  - Checked exact width, return ABI, caller stores, load/constructor inputs, input writes, paint reads, Config declaration, persistence, and runtime dispatch.
  - Resolution: `wchar_t` is the strongest source type; integer spellings remain ABI-equivalent rejected alternatives.
- **Should the method be named GetKey or GetKeyBinding?**
  - Checked setter/getter symmetry, neighboring method names, NewMacroDialog source, class history, and old reports.
  - Resolution: retain `GetKey`; preserve `GetKeyBinding` only as historical role wording.
- **Should the field be named m_key or m_code?**
  - Checked UI behavior versus storage record role.
  - Resolution: retain `m_key` in the row control and `code` in the compact record.
- **Should the method be virtual or inline?**
  - Checked all target xrefs, vtable slots, generated output, and exact retained function body.
  - Resolution: ordinary out-of-line nonvirtual public const member.
- **Does the target belong to NewMacroDialog or Config?**
  - Checked receiver setup, direct field access, class declaration, caller relationship, and storage ownership.
  - Resolution: UID000095 owns/emits; NewMacroDialog and Config are consumers/support.
- **Does the type change alter layout?**
  - Checked x86/MSVC widths/alignment and exact current object offsets.
  - Resolution: no; the field remains two bytes and class size remains `0x110`.
- **Any unresolved implementation blocker?**
  - None. Only exact original lexical spelling remains unknowable from current artifacts, and that uncertainty is explicitly reflected in confidence `94`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual files inspected read-only:
  - `by-memory/-coverage-report.md`, current SHA256 `8B3FC64B040B307C319CA458E8D6F51F366A13243289BF229703B3198DD71E21`, 1,781,989 bytes, 4,265 lines;
  - `by-class/-coverage-report.md`, current SHA256 `7140D6E7CEBA9F552984CD66EFAD01A7DD9693D2196C4498ACBC92032E7D46BE`, 230,570 bytes, 622 lines;
  - `by-file/-coverage-report.md`, current SHA256 `79DBB32440FA1EEB3DA22C3E00004B7883F05788296DBB95F1A3AB80642459DB`, 132,263 bytes, 316 lines;
  - `by-type/by-struct/-coverage-report.md`, current SHA256 `C1EF6744AC86BFE2A271E24F59541E4805FDDAF1C5D1106430221F74FB08BA0C`, 57,221 bytes, 137 lines.
- These current manual snapshots were reread after final command `14258`. The earlier terminal-audit by-memory snapshot `5C8033E8C25C274D1D138D25E4499524806A3AFB8C7A0618B7DC39F13E607BF3`, 1,781,759 bytes, was superseded by unrelated external/supervisor work; the current reread confirms every UID0004A6-scope row remains in the same semantic state described below.
- By-memory current placement:
  - parent UID0001IK is line 3197;
  - UID0004A5 is line 3200;
  - UID0004AE follows at line 3201;
  - no UID0004A6 row exists.
- Exact by-memory insertion after current UID0004A5 and before current UID0004AE:

```text
        - [UID:0004A6][0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey](by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md) 0x0057f9b0-0x0057f9b8 | method | NewMacroEditControlPaneGetKey : reconstructable : 92% : very-strong : Exact two-instruction wchar_t key accessor loading the +0x10c field into AX, with raw SHA256/unique signature, sole NewMacroDialog save caller, CompactShortcutRecord::code lifecycle, exact alignment boundaries, direct NewMacroEditControlPane/MacroDialogs emission, and no vtable/data xrefs.
```

- Current by-class UID000095 row is line 352 at `91%`.
- Exact no-loss by-class replacement:

```text
- [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md) : reconstructable : 92% : very-strong : Complete natural 0x110 ControlPane-derived new macro row declaration at position 50 with wchar_t key field/API at +0x10c, byte item/spell mode at +0x10e, int record index at +0x108, constructor, key/mode getters, record/key/mode setters, refresh, paint, canonical pointer/key EventHandler overrides, exact compact-record constructor/save/load lifecycle, vtable routes, implicit virtual destructor source cause, compiler helper/scalar/thunk separation, and MacroDialogs ownership.
```

- Verify-only rows requiring no replacement:
  - by-memory UID0001IK remains exact as the non-emitting split inventory;
  - by-file UID0000KY remains exact at `92%` and already states the complete source family/order;
  - by-struct UID0001VR remains exact at `90%` and already states `wchar_t code`, byte mode, natural tail alignment, and direct Config placement;
  - no manual rows exist for UID0004A8 or UID0004AA, and their proposed scores do not change.
- The generated research tracker is validator-owned and must not receive manual row text. Target `Item Summary` and `Nested` changes belong in the target page and will flow through validator generation after an accepted callback.
- B005 did not apply these manual rows. They remain exact supervisor-owned handoff text and are not pending B005 report work.

## Follow-Up Actions

- Supervisor-owned external state:
  - independent post-callback artifact and implementation review remains outside B005's completed responsibilities;
  - the exact manual coverage insertion/replacement remains available for supervisor-owned coverage handling without requiring a report rewrite;
  - report execution, archive movement, and lifecycle registration remain supervisor-owned.
- A-agent: no action required by this report.
- B005 callback work: complete. Every accepted destination was reread, leased individually, edited, scoped-validated, and released; final generated refresh and report reconciliation are complete.
- No additional B005 target was started during this lifecycle.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong.
- Exact behavior confidence: very strong.
- Owner/emitter/source-file confidence: very strong.
- Field width/offset confidence: very strong.
- Source type confidence: strong, capped because machine-equivalent typedef spellings are not distinguishable in codegen.
- Method/field lexical confidence: strong, capped because original symbols are absent.
- Remaining uncertainty has no range, behavior, layout, owner, emitter, C++, or validator-plan impact.

## Validator Results

- Historical report-only state: no implementation validator was run before Gate 1. That statement no longer describes the completed callback.

| Command | Timestamp | Scope | Exit / ok | Result and side effects |
| --- | --- | --- | --- | --- |
| `000000014250` | `2026-07-16T15:28:32-04:00` | UID0004A6 target | `0 / 1` | Accepted `92/94`, registry hash update, 13 reference-index additions, projected stats update, generated refresh deferred. |
| `000000014251` | `2026-07-16T15:29:38-04:00` | UID000095 class | `0 / 1` | Accepted `92/94`, registry hash update, three reference-index additions, projected stats update, generated refresh deferred. |
| `000000014252` | `2026-07-16T15:30:19-04:00` | UID0004A8 constructor | `0 / 1` | Accepted exact formal/prose with score unchanged, registry hash update, seven reference-index additions, projected stats update, generated refresh deferred. |
| `000000014253` | `2026-07-16T15:31:01-04:00` | UID0004AA setter | `0 / 1` | Accepted exact formal/prose with score unchanged, registry hash update, eight reference-index additions, projected stats update, generated refresh deferred. |
| `000000014254` | `2026-07-16T15:32:16-04:00` | UID0001IK aggregate | `0 / 1` | Accepted bounded support synchronization with metadata/formal unchanged; projected stats no-op; generated refresh deferred. |
| `000000014256` | `2026-07-16T15:33:52-04:00` | UID0000KY file | `0 / 1` | Accepted bounded support synchronization with score/path unchanged; projected stats no-op; generated refresh deferred. |
| `000000014258` | `2026-07-16T15:34:46-04:00` | final target `--wait-generated` | `0 / 1` | Generated refresh completed; registry rebuilt; generated metadata refreshed; validator-owned research tracker and generated reports refreshed. |

- B005 waited generated checkpoint:
  - command `000000014258`, refreshed `2026-07-16T15:34:46-04:00`, SHA256 `B2CF810C0461AE9823161F60ABF23C7E3557F371D82C861F831FDBEDFA70C628`;
  - this is the authorized callback refresh recorded in the validator table.
- Current generated output after a later external validator:
  - path `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`;
  - command/header `000000014303`;
  - refreshed `2026-07-16T15:51:05-04:00`;
  - SHA256 `17287DE536CB3F9D06AE1FE91A569FF93C9E1F45A7FB71EB11789B796D39CA0E`;
  - 34,779 bytes / 1,048 physical lines.
  - external command `14262`, SHA256 `367AA5DBE6FBC8DC765062E7659B5B4C011681761A09E27656E4C1FB06AADB34`, is retained as the superseded prior current-state checkpoint.
- Generated assertions:
  - one `class NewMacroEditControlPane`;
  - class line `725`, closing brace line `746`, first UID0004A6 definition line `749`;
  - one UID0004A6 getter definition, one UID0004A8 constructor definition, and one UID0004AA setter definition;
  - matched `wchar_t` class/getter/constructor/setter declarations and definitions;
  - exactly three `record.code` uses in unchanged construction/save/load paths;
  - zero stale getter/constructor/setter/field `uint16_t` key spellings;
  - zero UID0004A6 Empty Emitter Markers;
  - zero raw `+0x10c`, vptr/vftable, duplicate `CompactShortcutRecord`, or decompiler-label spellings;
  - B005 waited-command `14258` NewMacroEditControlPane segment SHA256 `EEBD3CBEABD7B226F8CBE828B2F020EA8AF2AA51FE8739939945C576E54679FD`;
  - current command `14303` normalized-LF lines `721-780` (UID000095 class comment through the UID0004AA setter closing brace), including the trailing LF, SHA256 `DE0BC23D775DF721C0CDA222701E4A98B50EEA6518A7782B51B536247646F6AC`.
- Final command warnings are pre-existing project-wide autogen diagnostics: 13 fallback child insertions, 84 missing preferred child markers, and 143 emitters with child-only code. None identifies UID0004A6, UID000095, UID0004A8, UID0004AA, UID0001IK, or UID0000KY as an error.
- Validator-owned side effects included generated metadata, registry, projected stats, tracker, and generated coverage refreshes. B005 manually edited none of those files and did not edit any manual `-coverage-report.md`.

## Changed Files

- Created during the original report-only pass:
  - `tools/leaser/Agents/Agent-B005/research/0004A6-NewMacroEditControlPaneGetKey-source-quality.md`.
- Modified ordinary files:
  - `by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md` -> SHA256 `9BF192429E07080CBB05A4C53013ACFB3F168EF2B589130F50A1A1E4CFE74472`, 9,551 bytes / 87 lines, validators `14250`,`14258`;
  - `by-class/NewMacroEditControlPane.md` -> SHA256 `CDE0AAE40F5007292221F27575CAC52EAC5850490C43E1B70FDFE520848D39A1`, 29,259 bytes / 183 lines, validator `14251`;
  - `by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md` -> SHA256 `F7B373B58D504DC3265380597BA836D6EF76A58D5C62FCB10788582913E77C2A`, 5,662 bytes / 64 lines, validator `14252`;
  - `by-memory/0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey.md` -> SHA256 `A593F3BE7A572E2C1F6F2BBC65E4360545108B974758A00F59D59694712677BB`, 4,740 bytes / 53 lines, validator `14253`;
  - `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md` -> SHA256 `17EAAC26D726D584B5A91207BA9E3A1B59D36929E639CBF59D78E44A3E5B1EA7`, 38,942 bytes / 187 lines, validator `14254`;
  - `by-file/MacroDialogs.md` -> SHA256 `CC455FACAED6DABF583083DFFB7964B6BB0F054B3F80D288BCE130C85F58BEC1`, 80,970 bytes / 271 lines, validator `14256`.
- Modified report artifact: this same report, reconciled from report-only proposal to completed callback proof.
- Manually modified restricted/generated/manual files: none.
- Validator-owned current generated output: MacroDialogs.cpp command `14303`, SHA256 `17287DE536CB3F9D06AE1FE91A569FF93C9E1F45A7FB71EB11789B796D39CA0E`. B005's waited command `14258` remains historical callback proof; external command `14262` remains a superseded checkpoint.
- Renamed files: none.
- Leases acquired and released serially: the six ordinary paths listed above, one at a time. Every lease command succeeded; each release succeeded immediately after the corresponding scoped validator.
- Leases held at report completion: zero.
- Current verify-only hashes:
  - UID0004A7 `9EAC494A1A938284B85E2AF84C21C6F50A81AD6708FFE9076A7575F22150F5CA`;
  - UID0004A9 `7F558CBB475D44B0F953FDA06F7F844C55C285A75A5A3344594489EBF7ABD4CB`;
  - UID0004AB `8E593A56B5C731459670AC43D7FD9F9183EBA38561BCE73442CF8BA935FAD27A`;
  - UID0004AC `C670DDCA2AD0D03941A05E58A04D19C762E737DA0D55A94BF4C31D04ED3FF14C`;
  - UID0004AD `C1FB8B60C10888EC71C296F927E63BA12328A457D3C74C1DED72D8737F17449C`;
  - UID0004AE `290A2D51077BA8A07544AB1C46088F8B120682684FF8776A98F5A7D15ABDB6C7`;
  - UID0004AF `944B82747FF8616B17A9C92069A106651EA11EFC3988F49193C423FFF82BF592`;
  - UID00049J `0CE2B28756C775AEB6A27620137214484AE57D5CC928BD9030B7C565CDC98C65`;
  - UID00049N `B1A463D637E372A8CA44806DAAD2A2FEDD433786E45812D8D7E0F1AC5014EB4D`;
  - UID00049O `51802ECFD5516F703958ED2F4F13621BB3801607AB0F552725719996759280F9`;
  - NewMacroDialog class `49553430DFE1CD0651559FBC1C2C01DE166DF0AC1C2CBEBF066C3BDBCBE5853E`;
  - Config class `9ECA99799904B0DD1E6D14E0C84DC784B578E2C31555C3AD7472C9B7A304B473`;
  - Config file `91984E67C9F7E99F2252203A65C892654531030AF190C7DAB7E2F0497FE3D577`;
  - UID0001VR `3A449A0CB8645B26CA76842C6E3C5D491C6079669CC443AC4DC10E25197B3AB8`;
  - UID0001IM `782E2E53BA212C0CE1703CF05D4631C3DE5B38B8DB657BF6205E456D83CFBC9A`;
  - UID0004AV `C1C60B4B35A5B46828DDD9A512301B2636731A915196D4C46CC3B9F4BD1FC101`;
  - UID0003DB `D5D87A8A4E9085F673697F302CDB9DD8F58DE2FC700FFBF95D180FC8E2D000C0`;
  - UID0001Y1 `0D6E643E14F6318656F52572DEE48AB3AAE4BCBE341007180AEE7CA2DEF697E0`;
  - ignored ledger `2348CAA2ADF662D969DAC2310CAB829A574B6546C2457F29AB3ED62AA6ED1199`.
- Report execution: not run. No lifecycle probe, move, archive, or execution command was issued.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: exact report-only SHA `0EDE8792...D539` passed Gate 1.
- [x] UID0004A6 is `92/94` with exact Item Summary, Destination 1, and full evidence; validators `14250`,`14258`.
- [x] UID000095 is `92/94` with Destination 2, exact `wchar_t` lifecycle, complete preserved class/compiler history, and closure before children; validator `14251`.
- [x] UID0004A8 has Destination 3 and exact constructor argument provenance with score/metadata unchanged; validator `14252`.
- [x] UID0004AA has Destination 4 and exact load-page/word-store evidence with score/metadata unchanged; validator `14253`.
- [x] UID0001IK synchronized at report-level detail with score, blank formal, `Nested:-4`, all children, raw-helper, compiler, and padding evidence preserved; validator `14254`.
- [x] UID0000KY synchronized at report-level detail with score/path, six positions, full family inventory, and unrelated Macro/Spell/Integrate facts preserved; validator `14256`.
- [x] UID0004A7/4A9/4AB/4AC/4AD/4AE/4AF reread at recorded hashes and verified same-or-greater with no formal or score change.
- [x] UID00049J/49N/49O and NewMacroDialog class reread at recorded hashes; direct `record.code`/`isSpellMode` flow remains source-ready and unchanged.
- [x] Config class/file and UID0001VR reread at recorded hashes; exact `wchar_t code`, byte mode, natural tail alignment, and no duplicate record declaration remain current.
- [x] Target exact bytes/hash/PE placement, unique signature, ABI/CFG, sole caller, xref negatives, and exact padding are incorporated in UID0004A6.
- [x] Constructor/load/save/input/paint lifecycle and direct/nonvirtual source status are incorporated without behavior loss.
- [x] Historical `uint16_t` and `GetKeyBinding` assumptions are explicitly superseded with rejected-alternative rationale.
- [x] CompactShortcutRecord versus MacroHotkeyRecord distinction and all storage/runtime negative evidence are preserved.
- [x] UID000095 owner/emitter, UID0000KY route, position 50, exact ranges, and nesting are preserved.
- [x] No split, rename, new child, new type page, ignored-row duplication, IDA mutation, or third-party import occurred.
- [x] Exact supervisor-owned manual by-memory insertion and by-class replacement remain in this report with canonical `very-strong`; B005 edited no coverage file.
- [x] One scoped validator ran for each changed ordinary file under a short one-file lease; all six releases succeeded immediately.
- [x] Final waited refresh `14258` completed and every listed MacroDialogs.cpp structural/type/count assertion passed.
- [x] C01-C40 use legal terminal callback states with claim-specific destination/validator/generated proof.
- [x] Current Target State, recommendations, Validator Results, Changed Files, hashes, and durable lifecycle wording are reconciled in this same report.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact report-only SHA `0EDE8792...D539`.
- [x] All accepted target/support details incorporated at report-level detail without compressing current or historical evidence.
- [x] Destinations 1-4 match their exact ordinary pages byte-for-byte; normalized SHA proof is recorded above.
- [x] Metadata/score/owner/emitter/nesting/source-order changes applied exactly or retained with explicit proof.
- [x] Every accepted historical assumption, rejected alternative, and negative fact is preserved.
- [x] Every open question is resolved as recorded; lexical uncertainty remains only as a confidence cap.
- [x] Scoped validators and final generated refresh are recorded with command IDs, timestamps, exit/ok, warnings, and side effects.
- [x] Exact changed-file hashes and all verify-only current baselines are recorded after callback.
- [x] Manual coverage handoff is retained exactly with current snapshots and coverage files left unedited by B005.
- [x] All leases were released; current lease report contains zero B005 match.
- [x] Report remains unexecuted and unmoved for independent supervisor review.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000014336","destination_path":"executed-b-agent-research/B005/0004A6-NewMacroEditControlPaneGetKey-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0004A6-NewMacroEditControlPaneGetKey-source-quality.md","timestamp":"2026-07-16T16:04:27-04:00","uid":"0004A6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
