** TARGET-REPORT-UID:0003VQ **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0003VQ TextDialogConstructor Source Quality Research

## Target
- Target UID: `0003VQ`
- Target path: `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md`
- Target title: `0x00552110-0x0055317a TextDialog Constructor`
- Assignment ID: `B012-report-0003VQ-TextDialogConstructor-20260702`
- Required mode: report-only research first. No by-* docs, generated files, coverage reports, validator state, lifecycle files, archives, or supervisor files were edited.
- Expected report path: `tools/leaser/Agents/Agent-B012/research/0003VQ-TextDialogConstructor-source-quality.md`

## Current Target State
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000EL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EL`, blank emitter position, blank formal C++.
- Current `Item Summary` is blank.
- Current prose correctly treats `sub_552110` as a reconstructable `TextDialog` constructor owned by [UID:0000EL] `TextDialog`, with [UID:0000OL] `TextDialog` as source module context and [UID:0001FJ] `TextDialogCore` as the split-index parent.
- Current prose preserves the B010 wrapper support sync: [UID:00023M] reaches the constructor through `TextDialog(payload, true, false)`, `TextDialog(payload, false, false)`, `TextDialog(payload, true, true)`, and `TextDialog(payload, false, true)`, while this constructor page owns final internal flag semantics and packet/control parsing.
- Current final-C++ gate is appropriate: keep formal C++ blank until packet field names, constructor flag meanings, layout variant names, child member fields, and cleanup-state structure are source-grade.

## Evidence Checked
- Workflow inputs:
  - Read `tools/leaser/Agents/Agent-B012/goal.md`.
  - Read project-level `ntk-b-agent-workflow` instructions and required B-agent research workflow.
  - Read `by-structure.md` IDA MCP Output Discipline and used narrow, exact-address, paged MCP calls only.
- Target/support docs checked:
  - `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md`
  - `by-class/TextDialog.md`
  - `by-file/TextDialog.md`
  - `by-memory/0x00552110-0x005534a0.TextDialogCore.md`
  - `by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md`
  - `by-memory/0x00622954-0x006229f0.TextDialogVtableData.md`
  - `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md`
  - `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md`
  - `by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md`
  - `by-memory/0x006229f0-0x00622c54.DlgmsgResourceStrings.md`
- Prior/current report searches:
  - Searched `tools/leaser/Agents`, `executed-b-agent-research`, and project markdown for `0003VQ`, `0x00552110`, `0x0055317a`, `TextDialogConstructor`, `TextDialog Constructor`, `sub_552110`, `DLGMSG5`, `DLGMSG51`, and `DLGMSG6`.
  - Relevant prior reports found: B001 `0001FJ-textdialog-core-source-quality.md`, B001 superseded split audit, B007 `0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md`, and B010 `0000LA-MessageDialogs-empty-emitter-family-source-quality.md`.
  - No existing B012 report at this path existed before this report.
- MCP session/state:
  - Supervisor resumed MCP after pause. Fresh `idb_list` found canonical session `b010_0002r7_20260702` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active and not analyzing.
  - `server_health` for `b010_0002r7_20260702` returned `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, `strings_cache_size: 2067`, imagebase `0x400000`.
  - Stale session `1f24c222` was not used.
- Narrow MCP calls used:
  - `lookup_funcs` for `0x00552110`, `0x0055317a`, `0x00553180`, the four wrapper starts, and `0x00622954`.
  - `func_profile` for `0x00552110`.
  - `xrefs_to` for `0x00552110`, `0x00622958`, `0x006229b8`, and `0x006229e8`.
  - `callees` for `0x00552110`.
  - `get_bytes` for `0x00553170`, `0x005520e0`, and `0x00622954`.
  - `disasm` windows at `0x00552140`, `0x005521d0`, `0x00553140`, `0x0054c8a0`, `0x0054c900`, `0x0054c960`, and `0x0054c9c0`.
  - `search_text` for `DLGMSG5` and `DLGMSG6` inside the documented resource string range returned no hits in this MCP session, so resource-string names are supported by the existing `DlgmsgResourceStrings` doc and constructor constant/xref evidence rather than by new string-search hits.

## Positive Evidence Summary
- Function boundary:
  - `lookup_funcs` reports `0x00552110` as `sub_552110`, size `0x106a`, half-open end `0x0055317a`.
  - `lookup_funcs` reports `0x0055317a` is not a function.
  - `lookup_funcs` reports the following function starts at `0x00553180` as `sub_553180`, size `0x1b8`.
- Scale and complexity:
  - `func_profile` reports `sub_552110` has `1341` instructions, `190` basic blocks, `4` callers, `30` callees, `411` constants, and prototype `_DWORD *__fastcall(_DWORD *, int, int, char, char)`.
  - The stack frame includes large local buffers: `CHAR[32768]`, two `WCHAR[256]` buffers, SEH/security-cookie state, and cleanup locals. This supports the current no-formal-C++ gate for cleanup-state and local-layout uncertainty.
- Constructor/class ownership:
  - Early disassembly moves `ecx` to `edi`, calls the base/setup helper, then stores TextDialog vtables:
    - `0x00552161`: `[edi] = 0x00622958` / `??_7TextDialog@@6B@`
    - `0x00552167`: `[edi+0xa0] = 0x006229b8` / adjusted TextDialog vtable
    - `0x00552171`: `[edi+0xa4] = 0x006229e8` / adjusted TextDialog vtable
  - `xrefs_to` confirms those three vtable data xrefs originate from `sub_552110`.
  - [UID:0003DC] `TextDialogVtableData` independently records the same constructor-store xrefs and identifies the vtable data as `TextDialog`.
- Packet/dialog field evidence:
  - `0x005521a0`: stores a byte from the packet conversion path to `this+0x26c`.
  - `0x005521af`: stores a dword parsed from `arg_0+1` to `this+0x270`.
  - `0x005521ff`: stores a word to `this+0x274`.
  - `0x00552212`: stores a word to `this+0x276`.
  - Prior accepted B001 evidence records the duplicated second layout/parser branch stores at `0x0055293c`, `0x0055294b`, `0x0055299b`, and `0x005529ae`; current target prose can cite these as prior accepted support if not re-disassembled in the implementation callback.
- Wrapper/caller evidence:
  - `xrefs_to 0x00552110` confirms four code xrefs:
    - `0x0054c8b7`, inside wrapper start `0x0054c870`.
    - `0x0054c917`, inside wrapper start `0x0054c8d0`.
    - `0x0054c977`, inside wrapper start `0x0054c930`.
    - `0x0054c9d7`, inside wrapper start `0x0054c990`.
  - Narrow wrapper disassembly confirms the four flag shapes:
    - `0x0054c8b7`: pushes packet, then `1`, `0` before calling `sub_552110`, matching `TextDialog(payload, true, false)`.
    - `0x0054c917`: pushes packet, then `0`, `0`, matching `TextDialog(payload, false, false)`.
    - `0x0054c977`: pushes packet, then `1`, `1`, matching `TextDialog(payload, true, true)`.
    - `0x0054c9d7`: pushes packet, then `0`, `1`, matching `TextDialog(payload, false, true)`.
  - The wrapper names in IDA include two misleading compiler/generated names, but their call bodies and [UID:00023M] support docs establish their dispatcher wrapper role. Do not promote IDA wrapper names into source names.
- Callee evidence:
  - `callees` reports constructor calls to setup/string/control/helper functions including `sub_49D8A0`, `sub_516030`, `sub_575470`, `sub_5754C0`, `sub_575480`, `sub_516220`, `MultiByteToWideChar`, UI/control constructors/helpers around `0x49d*`, `0x498*`, `0x499*`, `0x4b7c50`, `0x4f4aa0`, `0x520540`, security cookie check, and range-check failure.
  - This callee set matches the documented behavior: packet parsing, multibyte/wide string conversion, layout/control construction, and guarded cleanup.
- Resource/layout evidence:
  - Current early disassembly shows `byte_66DA97` branch selection at `0x0055217b` and the branch to `0x0055292b`.
  - Existing accepted B001 evidence and [UID:0003VQ] current prose record the duplicated layout/resource branches using `DLGMSG5`, `DLGMSG51`, `DLGMSG6`, `.EPF`, `.EPD`, and `NPAL8.PAL`.
  - [UID:0003DD] `DlgmsgResourceStrings` records the contiguous DLGMSG table from `DLGMSG1.PAL` through `DLGMSG6.EPD`, with representative constructor xrefs at `0x00552420`, `0x00552908`, and `0x00553102`.
- Boundary evidence:
  - `get_bytes 0x00553170 size 0x20` returns bytes ending the constructor with `pop ebp; retn 0Ch`, a range-check-failure call at `0x00553175`, then six `0xcc` bytes at `0x0055317a-0x00553180`, followed by the `sub_553180` prologue.
  - This preserves the split decision: constructor ends at `0x0055317a`; `0x0055317a-0x00553180` belongs to ignored padding; `0x00553180` starts the action handler.

## Negative Evidence Summary
- No evidence supports changing canonical ownership away from [UID:0000EL] `TextDialog`.
- No evidence supports folding the constructor into [UID:00023M] `MessageDialogPacketDispatcherAndWrappers`; [UID:00023M] owns allocation/dispatcher wrappers, while `0x00552110` installs TextDialog vtables and parses TextDialog instance fields.
- No evidence supports folding the constructor into [UID:0000JT] `HeadSelectDialog`; the preceding `0x005520e5-0x00552110` span is documented switch/alignment data before the TextDialog constructor, and the constructor immediately installs TextDialog vtables.
- No evidence supports extending this constructor through `0x00553180`; `0x0055317a` is not a function, `0x0055317a-0x00553180` is six `0xcc` bytes, and `sub_553180` begins at `0x00553180`.
- No evidence supports including the later `0x00553350-0x00553495` raw submit-packet island in this constructor; B007 and current support docs preserve it as no-route/non-emitting unless a caller, pointer, vtable slot, callback wrapper, or runtime trace proves liveness.
- No evidence supports final source-grade constructor parameter or member names for the two wrapper flags, packet struct, child-control members, layout variant names, or cleanup-state locals.
- New MCP `search_text` did not return `DLGMSG5`/`DLGMSG6` hits in the resource range, so the implementation should not claim fresh string-search proof for those strings. It may cite current docs and the accepted B001/DlgmsgResourceStrings evidence instead.

## Ranked Ownership Analysis
1. [UID:0000EL] `TextDialog` class: accept as direct canonical owner.
   - Evidence for: `sub_552110` is a constructor-shaped `this` receiver function; early code moves `ecx` into `edi`, invokes base/setup behavior, then writes all three TextDialog vtables at `0x00552161`, `0x00552167`, and `0x00552171`. The body writes TextDialog-family fields at `this+0x26c`, `this+0x270`, `this+0x274`, and `this+0x276`, builds TextDialog UI controls, and returns `this`.
   - Evidence against: none for ownership. Remaining uncertainty is internal source naming, not ownership.
   - Decision: keep `CANONICAL_OWNER:0000EL`, `EMITTER_UIDS:0000EL`, and class-constructor wording.
2. [UID:0000OL] `TextDialog` source file: accept as source module/emitter route, not direct owner.
   - Evidence for: current file doc places the constructor/action source methods in `NexusTK/ui/dialogs/TextDialog.cpp`; class doc and file doc both treat this constructor as the TextDialog class implementation.
   - Evidence against: by-structure favors the narrow semantic class owner for exact methods when a class doc exists and clears the gate. Directly owning the by-memory item from the file page would weaken the class/method relationship already proven by vtables.
   - Decision: cite as `Source module context`; do not change direct owner from class to file.
3. [UID:00023M] `MessageDialogPacketDispatcherAndWrappers`: reject as semantic owner, keep as caller/support page.
   - Evidence for: four wrapper functions allocate `0x278` bytes and call `0x00552110` with the four proven flag shapes. [UID:00023M] owns those allocation/dispatch wrappers and is the immediate construction route from the message-dialog dispatcher family.
   - Evidence against: the wrapper bodies stop at allocation, `ecx` setup, and `call sub_552110`; the constructor itself installs TextDialog vtables and owns all packet/control parsing after entry. The wrapper file does not own TextDialog instance layout or child controls.
   - Decision: preserve B010 support wording and caller evidence, but reject dispatcher/wrapper ownership.
4. [UID:0000JT] `HeadSelectDialog` / adjacent preceding ownership: reject.
   - Evidence for: address locality before `0x00552110`; the preceding HeadSelect range is near this constructor.
   - Evidence against: [UID:0001FI] and ignored rows document `0x005520e5-0x00552110` as HeadSelect switch/alignment data. Current `get_bytes 0x005520e0` shows switch/table-like bytes and final `0xcc` padding before the TextDialog prologue. The first real constructor instructions at `0x00552110` install TextDialog vtables, not HeadSelect vtables.
   - Decision: do not fold this target into HeadSelect or any adjacent predecessor.
5. [UID:0001FJ] `TextDialogCore` split-index parent: keep as non-emitting parent/index, not owner/emitter.
   - Evidence for: exact parent split index covers the TextDialog constructor/action/raw-island neighborhood and records the local child inventory and padding boundaries.
   - Evidence against: [UID:0001FJ] intentionally does not emit source C++ and mixes exact child methods, padding, switch data, and a no-route raw island. It is an index over ownership decisions, not a source-level owner for emitted code.
   - Decision: keep as `Parent split index` only; do not assign `EMITTER_UIDS:0001FJ`.
6. [UID:0001FG] `DialogNavigationPacketHelpers`: reject as owner, keep as related packet-helper infrastructure.
   - Evidence for: the action handler later calls the shared previous/next/current helpers; packet fields overlap with the same opcode `0x3a` dialog reply family.
   - Evidence against: those helpers are not constructor callers, not vtable owners, and are explicitly shared by MessageDialog/MenuQuestion/TextDialog/Nexonclub paths. They serialize navigation replies, while this constructor parses inbound payload and builds UI controls.
   - Decision: no support edit required for this target; keep helper page as related context only.
7. [UID:00009H]/[UID:0000LZ] `NexonclubProxyDialog`: reject.
   - Evidence for: later neighbor `0x005534a0` shares dialog reply helper vocabulary and is near the TextDialog core range.
   - Evidence against: current TextDialog constructor ends at `0x0055317a`; [UID:0003GL] and [UID:0001FK] document that the proxy callback/constructor starts later and is installed by the Nexonclub constructor path. There is no route from proxy ownership back to `0x00552110`.
   - Decision: preserve the existing split excluding NexonclubProxyDialog from this constructor.

## Source Placement
- Best placement: `TextDialog::TextDialog(...)` under [UID:0000EL] `TextDialog`, emitted through [UID:0000OL] `TextDialog.cpp` in `NexusTK/ui/dialogs/`.
- Why this route is correct:
  - Source-facing class placement is proven by constructor shape, `ecx` receiver use, return of `this`, and TextDialog vtable stores.
  - Source-file placement is supported by current [UID:0000OL] file doc, the proposed source tree, and the fact that neighboring exact source-bearing child [UID:0003VR] is the TextDialog action handler.
  - The target parses the TextDialog inbound packet payload, initializes persistent TextDialog state, chooses TextDialog resources/layout branches, and constructs the TextDialog child controls. Those are class-constructor responsibilities, not dispatcher or helper responsibilities.
- Why wrappers/support pages are not semantic owners:
  - [UID:00023M] wrapper functions allocate memory and supply two boolean arguments. They do not interpret packet fields after entry, install vtables, build controls, or own the `this+0x26c` field family.
  - [UID:0001FJ] is deliberately a non-emitting split index; assigning source placement there would recreate the earlier mixed-range problem B001 split apart.
  - [UID:0001FG] owns/stages shared outbound navigation packet helpers, not inbound constructor parsing or UI construction.
  - Resource-string and vtable-data pages are data support pages. They support source placement but do not own executable constructor code.
- No new source file is recommended. A future shared dialog packet-helper source file could be considered for [UID:0001FG], but this constructor is too class-specific for such a grouping.

## Heuristic / Inference Reanalysis And Validation
- Constructor parameter shape:
  - Direct evidence: IDA reports `_DWORD *__fastcall(_DWORD *, int, int, char, char)`. Wrapper disassembly shows stack pushes in the effective call shapes `TextDialog(payload, true, false)`, `TextDialog(payload, false, false)`, `TextDialog(payload, true, true)`, and `TextDialog(payload, false, true)`.
  - Best inference: `ecx` is `this`; the first stack argument is the packet/payload pointer; the two boolean/byte arguments select constructor variants. It is safe to document the four boolean values, but not safe to assign final source names to the flags.
  - Evidence attempted for flag naming: `arg_4` is tested near `0x00552239` after base dialog fields are parsed and before an optional variable-length packet segment is consumed. That supports a content/optional-payload gating role for one flag, but the current bounded windows do not prove the original name or whether the source author framed it as object-image, input, paging, or layout state. `arg_8` participates later in the large control/layout construction path, but this report did not obtain enough exact branch-local evidence to source-name it without importing decompiler-shaped speculation.
  - Validation outcome: keep wrapper call shapes exact; do not use invented names such as `hasObject`, `large`, `hasInput`, or `isHighResolution` in formal C++ or metadata.
- Packet field and protocol names:
  - Direct evidence: stores to `this+0x26c`, `this+0x270`, `this+0x274`, and `this+0x276` occur in the constructor; the action handler and shared packet helpers later serialize the same field family into opcode `0x3a` replies.
  - Best inference: `+0x26c` is a dialog reply type/subtype byte, `+0x270` is a dialog/session/object identifier, `+0x274` is a dialog state/sequence word, and `+0x276` is a current page/index word. These meanings are safe as descriptive prose because the outbound helpers independently use them that way.
  - Source-grade limit: those are not proven original member names. The constructor is an inbound parser and the action/helper pages are outbound serializers, so cross-use validates semantics but not exact type declarations, signedness, endian abstraction names, or member spelling.
- Child-control members:
  - Direct evidence: current docs and callee set identify EPF image panes, image buttons, static text, editable text controls, and optional object image controls. The action handler later reads a child at `this+0x1fc` for typed text.
  - Best inference: the constructor probably initializes persistent member pointers for at least the text edit control and navigation/action controls, plus transient/local control construction helpers. It is safe to document the control categories and the action handler's dependency on the edit control.
  - Source-grade limit: the constructor's large body has many UI helper calls around `0x498*`, `0x499*`, `0x49d*`, `0x4b7c50`, and `0x520540`; this report did not resolve each call to a stable member field, ownership lifetime, or source name. Formal C++ would either omit required controls or invent member names.
- Layout/resource variant names:
  - Direct evidence: `byte_66DA97` splits the duplicated layout/resource branch; existing accepted evidence records `DLGMSG5`, `DLGMSG51`, `DLGMSG6`, `.EPF`, `.EPD`, and `NPAL8.PAL` use. New MCP `search_text` did not produce fresh string hits, but current support docs contain prior live IDA xrefs to the resource table.
  - Best inference: the constructor has normal and alternate/high-resolution resource/layout variants, and `byte_66DA97` is a global display/resource-mode selector.
  - Source-grade limit: source-facing names for the global selector and the two layout variants are not proven. The target may describe branch behavior, but formal C++ should not introduce final names such as `highResolution`, `classicLayout`, or `useEpdResources` without stronger project-wide naming evidence.
- Cleanup-state structure:
  - Direct evidence: the function uses SEH, a security cookie, large local buffers, cleanup `Block` locals, and out-of-line cleanup landing pads in the `0x606c*` area. `func_profile` reports `190` blocks and `30` callees; disassembly shows range-check failure and security-cookie paths.
  - Best inference: this is compiler-generated constructor cleanup for partially constructed UI children and temporary string buffers around a human-written constructor body.
  - Source-grade limit: the cleanup state is not source-authored control flow and should not be manually reconstructed as decompiler-style state variables. Formal C++ is unsafe until the real source-level object lifetimes and RAII/cleanup ownership are understood well enough to avoid emitting compiler-artifact logic.
- Score implication:
  - These investigations support raising documentation quality to `87/90` because boundary, owner, wrapper, field, scale, and no-code rationale can be made much more exact.
  - They also justify not raising higher and not emitting C++: the unresolved pieces are not merely missing labels; they affect constructor signature, member declarations, protocol structs, layout branch names, and cleanup/lifetime behavior.

## Open Questions With Attempted Resolution
- What do the two boolean constructor flags mean?
  - Evidence checked: four wrapper disassembly windows and constructor disassembly around `arg_4` use at `0x00552239`.
  - Best defensible inference: first flag (`arg_4`) gates an optional payload/content branch because the code tests it after parsing core packet fields and before consuming an additional counted segment. The second flag (`arg_8`) is a separate constructor variant selected by dispatcher wrappers, likely affecting layout/control behavior.
  - Why not safe for final names: the bounded evidence does not prove original source names or whether the flags correspond to visual size, object art, text input, paging, or dispatcher message subtype. Score impact: cap below `90` completion and keep formal C++ blank.
- What are the source member names/types for `this+0x26c/+0x270/+0x274/+0x276`?
  - Evidence checked: constructor stores, action handler behavior, raw island packet layout, and shared navigation helper packet layout.
  - Best defensible inference: dialog reply type/subtype byte, dialog/session/object id, dialog state/sequence word, and current page/index word. This should be documented as semantic prose.
  - Why not safe for formal names: no source symbol, struct declaration, or project-wide naming convention proves final member names, and the constructor/action/helper evidence does not by itself fix exact typedefs or signedness. Score impact: prose can improve, C++ cannot.
- Which child controls become persistent members?
  - Evidence checked: constructor callee set and current docs for EPF image panes, buttons, static text, edit controls, object image controls; action handler read of the text edit child at `this+0x1fc`.
  - Best defensible inference: the edit control is persistent and action-visible; some navigation/action buttons and display panes are likely member-owned or pane-owned children. Control categories are safe; exact member list is not.
  - Why not safe for formal names: current evidence does not map every constructed control to a member offset, owned child list entry, or temporary. Score impact: no first-draft constructor body.
- What are the layout variant/source names?
  - Evidence checked: `byte_66DA97` branch, accepted B001 resource branch facts, current `DlgmsgResourceStrings` xrefs, and new `search_text` failure.
  - Best defensible inference: a global client/resource mode selects between duplicated normal/alternate resource construction branches using `DLGMSG5`/`DLGMSG51`/`DLGMSG6` assets.
  - Why not safe for final names: the current MCP string search did not independently reinforce names, and `byte_66DA97` lacks a current source-grade global name. Score impact: keep resource prose, avoid C++ names for the selector/variants.
- How should constructor cleanup be represented?
  - Evidence checked: SEH prologue, security cookie, local stack layout, cleanup blocks, range-check tail, callee set.
  - Best defensible inference: cleanup is compiler-emitted around source-level object construction and temporary buffers. Documentation should mention cleanup-state complexity rather than port decompiler cleanup labels.
  - Why not safe for formal C++: emitting a body now would likely either miss exception cleanup behavior or encode compiler artifacts as source. Score impact: strong no-code proof, not a reconstructability downgrade.
- Does any support page require immediate correction before target implementation?
  - Evidence checked: TextDialog class/file, split index, dispatcher wrapper page, vtable data, action handler, raw island, navigation helper page.
  - Best defensible inference: no mandatory support edit is needed for [UID:0003VQ]. [UID:0003DC] has historical `AUTOGEN_PARENT_UID` wording, but that is a separate support terminology cleanup and does not contradict this target's owner/emitter state.
  - Score impact: target can improve without support edits; optional support cleanup should remain outside this report-only callback unless supervisor scopes it.

## Score And Metadata Recommendation
- Recommended metadata for [UID:0003VQ]:
  - `COMPLETION:87`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000EL`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000EL`
  - `EMITTER_POSITION_OPTIONAL:` blank
  - `RECONSTRUCTION_CPP CODE:[[[]]]`
  - Formal `RECONSTRUCTION_CPP CODE` block remains blank.
- Rationale:
  - Raise completion from `85` to `87` because the target can be materially improved with a filled `Item Summary`, current MCP session evidence, exact wrapper flag-push call shapes, field-store addresses, callee/scale evidence, and boundary bytes.
  - Raise confidence from `88` to `90` because fresh MCP confirms the original B001 split facts and B010 wrapper relationship in the current canonical IDB.
  - Do not raise above `87/90` because final source-grade constructor C++ is still blocked by unresolved packet field names, constructor flag meanings, layout variant names, child-control member fields, and cleanup-state structure.
- Recommended `Item Summary` wording:
  - `0x00552110-0x0055317a | class constructor | TextDialogConstructor : reconstructable : 87% : very-strong : Current MCP recheck confirms sub_552110 exact size 0x106a, half-open range ending at 0x0055317a, 1341-instruction/190-block scale, four dispatcher-wrapper callers at 0x0054c8b7/0x0054c917/0x0054c977/0x0054c9d7 with TextDialog(payload, true, false)/(false, false)/(true, true)/(false, true) call shapes, TextDialog vtable stores at 0x00552161/0x00552167/0x00552171, dialog packet field stores to this+0x26c/+0x270/+0x274/+0x276, conversion/control/layout callee set, and boundary bytes showing the range-check tail through 0x0055317a followed by six 0xcc padding bytes before sub_553180; keep formal C++ blank pending source-grade packet struct, flag, child-control member, layout variant, and cleanup-state names.`

## First-Draft C++ Recommendation
- Recommendation: do not add formal C++ for this target in the implementation callback.
- Target-specific no-code proof:
  - Function scale is not incidental: `0x106a` bytes, `1341` instructions, `190` basic blocks, `30` callees, large multibyte/wide buffers, SEH state, security-cookie state, range-check paths, and out-of-line cleanup all appear in the current IDA evidence. A small hand-written constructor sketch would omit meaningful behavior.
  - Signature attempt: the safest source-shaped signature would be a `TextDialog` constructor taking a packet/payload pointer plus two boolean/byte mode arguments, with `this` in `ecx`. However, IDA only proves `_DWORD *__fastcall(_DWORD *, int, int, char, char)` and wrapper call shapes. The report can recommend prose like `TextDialog(payload, true, false)` but cannot name the parameters.
  - Flag-name attempt: `arg_4` is tested around `0x00552239` and appears to guard an optional consumed packet segment; `arg_8` distinguishes another wrapper-selected variant. Those are useful inferences but not enough to name the flags in C++ or to decide whether they are constructor booleans, enum bits, overload selectors, or decompiled byte parameters.
  - Packet-field attempt: the best prose meanings for `this+0x26c/+0x270/+0x274/+0x276` are reply type/subtype byte, dialog/session/object id, state/sequence word, and page/index word. Those meanings are cross-validated by the action handler and navigation helpers, but the exact member declarations and source names are not proven.
  - Child-control attempt: control categories are known, and the edit control is action-visible, but the constructor contains enough pane/control construction that a first-draft body would need member offsets/names for image panes, buttons, static text, edit control, optional object-image control, and child ownership/lifetime. Current evidence does not resolve that map.
  - Layout/resource attempt: `byte_66DA97` and DLGMSG resources prove branch behavior, but not the source name for the global display/resource mode or the layout variants. Using invented names in formal C++ would create false precision.
  - Cleanup/lifetime attempt: the cleanup landing pads are compiler output for partially constructed objects and temporaries. A faithful source draft would need source-level ownership/RAII reconstruction; a decompiler-shaped cleanup-state port would not be acceptable project source.
  - Conclusion: leave `RECONSTRUCTION_CPP CODE:[[[]]]` and the formal block blank. Add target-specific no-code proof and detailed prose evidence only. Do not include illustrative C++ anywhere in the target because any such sample would either omit behavior or introduce non-source-grade names.

## Recommended Target Doc Changes
- Update metadata to `COMPLETION:87`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000EL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EL`, blank emitter position, and blank formal C++.
- Fill `Item Summary` with the wording proposed above or an equivalent report-level-specific summary.
- Expand `Evidence` with current MCP session details:
  - `b010_0002r7_20260702`, canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, health ok, auto-analysis and Hex-Rays ready.
  - `sub_552110` exact size/range, `0x0055317a` not a function, `0x00553180` next function.
  - `1341` instructions, `190` blocks, `4` callers, `30` callees.
  - Three TextDialog vtable stores at `0x00552161`, `0x00552167`, `0x00552171`.
  - Four direct caller xrefs and flag-push shapes at `0x0054c8b7`, `0x0054c917`, `0x0054c977`, `0x0054c9d7`.
  - Field-store addresses `0x005521a0`, `0x005521af`, `0x005521ff`, and `0x00552212`; optionally cite accepted B001 duplicated branch addresses `0x0055293c`, `0x0055294b`, `0x0055299b`, and `0x005529ae`.
  - Boundary byte proof for `0x0055317a-0x00553180` padding.
- Add or refine no-code proof under the C++ gate/Boundary/Evidence prose. Do not insert illustrative C++.
- Preserve the B010 wrapper wording and state that the current page owns internal flag semantics and packet/control parsing.

## Recommended Support Doc Changes
- Required support edits for this target: none proven in this report-only pass.
- Support docs are already synchronized on the central ownership/range decisions:
  - [UID:0000EL] `TextDialog` owns constructor/action methods and records wrapper call forms.
  - [UID:0000OL] `TextDialog` keeps TextDialog constructor/action ownership separate from HeadSelect and NexonclubProxyDialog.
  - [UID:0001FJ] `TextDialogCore` is a non-emitting split index with exact children and padding/raw-island boundaries.
  - [UID:00023M] owns dispatcher/wrapper call sites and leaves TextDialog internal constructor semantics to this target.
  - [UID:0001FG] keeps shared dialog navigation helpers separate from TextDialog-private methods.
  - [UID:0003VS] remains no-owner/non-emitting.
- Optional future cleanup outside this target: [UID:0003DC] `TextDialogVtableData` still contains historical `AUTOGEN_PARENT_UID` wording in its Assignment prose. This does not block [UID:0003VQ] implementation and should not be touched in this callback unless the supervisor explicitly scopes a support terminology cleanup.

## Claim And Incorporation Ledger
| Claim | Evidence | Callback incorporation state |
| --- | --- | --- |
| Constructor boundary is exact `0x00552110-0x0055317a`. | `lookup_funcs` reports `sub_552110` at `0x00552110`, size `0x106a`; `0x0055317a` is not a function; boundary bytes show tail/padding. | `applied` in `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md` `Evidence` and `Boundary`; range unchanged, `0x0055317a-0x00553180` padding proof added. |
| Owner remains [UID:0000EL] `TextDialog`. | Vtable stores to `??_7TextDialog` at `0x00552161/0x00552167/0x00552171`; TextDialog field stores; support class/file docs. | `applied` in target metadata and `Ownership And Source Placement`; `CANONICAL_OWNER:0000EL`, `EMITTER_UIDS:0000EL`, `RECONSTRUCTABLE:TRUE` preserved. |
| Dispatcher wrappers are callers only. | `xrefs_to` lists four call sites; wrapper disassembly shows flag pushes and `call sub_552110`; [UID:00023M] owns wrappers. | `applied` in target `Behavior`, `Evidence`, and `Ownership And Source Placement`; B010 wording preserved and wrapper ownership rejected. |
| Packet/dialog fields are parsed into `this+0x26c/+0x270/+0x274/+0x276`. | Current disassembly at `0x005521a0`, `0x005521af`, `0x005521ff`, `0x00552212`; accepted B001 duplicated-branch addresses. | `applied` in target `Evidence` and `Open Questions And No-Code Proof`; exact stores and prose-only field meanings added without final source names. |
| Resource/layout branch remains documented but final names are not source-grade. | `byte_66DA97` branch at `0x0055217b`; current target/B001/DlgmsgResourceStrings docs for DLGMSG resources. | `applied` in target `Evidence` and `Open Questions And No-Code Proof`; support-doc resource proof retained and fresh `search_text` limitation recorded. |
| Ranked owner/source placement is TextDialog class in TextDialog.cpp. | Vtable stores and field/control behavior support [UID:0000EL]; wrappers, HeadSelect, split-index, helpers, and Nexonclub were checked and rejected. | `applied` in target `Ownership And Source Placement`; accepted TextDialog/TextDialog.cpp route and rejected alternatives named. |
| Open questions are investigated but not source-grade. | Flag, field, control, layout, resource, and cleanup blockers were checked against wrapper disassembly, constructor disassembly, support docs, and prior accepted reports. | `applied` in target `Open Questions And No-Code Proof`; blockers tied to `87/90` score cap and blank formal C++. |
| Formal C++ must remain blank. | Best-inference attempts still leave unresolved constructor signature, flag names, member names/types, layout names, control ownership, and cleanup/lifetime source shape. | `applied` in target metadata/formal block and `Open Questions And No-Code Proof`; `RECONSTRUCTION_CPP CODE:[[[]]]` and multiline formal block remain blank; no illustrative C++ added. |
| No support docs require mandatory edits. | Reviewed TextDialog class/file, core split, dispatcher wrappers, vtable data, action handler, raw island, navigation helpers. | `already-present`/`excluded-with-reason`: support docs verified and consistent; optional [UID:0003DC] `AUTOGEN_PARENT_UID` terminology cleanup is out of scope and not a direct contradiction for this target. |

## Implementation Tracking Checklist
- [x] Edit `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md` metadata to `COMPLETION:87`, `CONFIDENCE:90`; preserve owner/emitter/reconstructable/blank formal C++ fields. Proof: target header updated; `CANONICAL_OWNER:0000EL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EL`, blank emitter position, `RECONSTRUCTION_CPP CODE:[[[]]]`, and blank formal block preserved.
- [x] Fill the target `Item Summary` with report-specific evidence. Proof: target `Item Summary` now records current MCP range/scale/caller/vtable/field/callee/boundary/no-code evidence.
- [x] Add current MCP session evidence, function scale, vtable stores, wrapper call shapes, field-store addresses, callee summary, and boundary bytes to the target prose. Proof: target `Evidence` and `Boundary` sections updated with session `b010_0002r7_20260702`, `0x106a`, `1341` instructions, `190` blocks, vtable stores, wrapper shapes, field stores, callee summary, and `0xcc` padding proof.
- [x] Add ranked ownership/source-placement prose to the target or preserve equivalent existing prose: [UID:0000EL] accepted, [UID:00023M] wrappers rejected as owner, [UID:0000JT] adjacency rejected, [UID:0001FJ] kept as split index only, shared helpers/proxy/resource-data pages treated as support only. Proof: target `Ownership And Source Placement`.
- [x] Add open-question/no-code proof covering attempted resolution of constructor flag meanings, packet field meanings, child-control member uncertainty, layout/resource variant naming, and cleanup-state source-shape blockers. Proof: target `Open Questions And No-Code Proof`.
- [x] Preserve B010 wrapper wording and TextDialog ownership of internal flag semantics. Proof: existing B010 paragraph remains in target `Behavior`; new evidence reiterates this page owns internals.
- [x] Preserve rejected ownership alternatives: MessageDialog dispatcher/wrappers, HeadSelectDialog, NexonclubProxyDialog, shared navigation helpers, and raw no-route island. Proof: target `Ownership And Source Placement` and `Open Questions And No-Code Proof`.
- [x] Keep `RECONSTRUCTION_CPP CODE` blank and add target-specific no-code proof. Proof: formal header/block blank; target no-code proof added.
- [x] Do not add illustrative C++ outside the formal block. Proof: no C++ snippet added to target or report during callback.
- [x] Do not edit by-* support docs unless supervisor explicitly scopes optional support terminology cleanup. Proof: support docs verified; no support docs edited. [UID:0003DC] terminology cleanup excluded as out-of-scope/nonblocking.
- [x] Run scoped file validator during implementation callback. Proof: `python .\tools\validator.py --mode file --file by-memory\0x00552110-0x0055317a.TextDialogConstructor.md --apply --queue-timeout 240`, command `000000004804`, timestamp `2026-07-02T18:50:00-04:00`, exit code `0`, `ok:1`, generated refresh `deferred`.

## Validator Results
- Implementation callback scoped validator run:
  - Command: `python .\tools\validator.py --mode file --file by-memory\0x00552110-0x0055317a.TextDialogConstructor.md --apply --queue-timeout 240`
  - `command_id`: `000000004804`
  - `command_timestamp`: `2026-07-02T18:50:00-04:00`
  - Exit code: `0`
  - `ok`: `1`
  - Notable output: `completion_update 0003VQ ... 87`, `confidence_update 0003VQ ... 90`, `uid_link_insert` for `00009H`, `0000LZ`, and `0000EL`, `reference_index_add` for linked support UIDs, `projected_stats_update`.
  - Warnings/diagnostics: `missing_ref_uid 0003DC` and `missing_ref_uid 0003DD` reported as UID references not present in `validator.ini`; these are support UID registry diagnostics and not target-content failures. No manual validator-state repair performed.
  - Generated refresh: `deferred`, `generated_refresh_command_id: 000000004804`, `generated_refresh_timestamp: 2026-07-02T18:50:00-04:00`. Queue status command `000000004805` at `2026-07-02T18:50:34-04:00` reported `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, and `processing generated refresh jobs: 0`.

## Changed Files
- `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md`
- `tools/leaser/Agents/Agent-B012/research/0003VQ-TextDialogConstructor-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004808","destination_path":"executed-b-agent-research/B012/0003VQ-TextDialogConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0003VQ-TextDialogConstructor-source-quality.md","timestamp":"2026-07-02T18:52:09-04:00","uid":"0003VQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
