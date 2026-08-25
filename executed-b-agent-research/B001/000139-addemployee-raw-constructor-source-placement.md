** TARGET-REPORT-UID:000139 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000139 AddEmployeeItemDialog Raw Constructor Source-Placement Research

Assignment: `B001-goal2-addemployee-raw-constructor-source-placement-000139-20260615`

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000139] `AddEmployeeItemDialogRawConstructor` as `RECONSTRUCTABLE:TRUE` class-owned raw constructor evidence with current owner/emitter [UID:000006] `AddEmployeeItemDialog`, and keep final C++ blank.
- Final disposition: a retained, unique, source-authored constructor-shaped byte body for a real employee-specific dialog class, but not a proven live out-of-line constructor entry. Treat it as reconstructable evidence, not as dead/duplicate-only code and not as a standalone final C++ emission target yet.
- Required action: no target doc, support doc, score, owner/emitter, IDA DB, validation, generated-output, or `by-memory/-coverage-report.md` change is recommended.
- Confidence: high for the no-change classification; medium for the exact compiler/linker cause because no PDB, object files, linker map, COFF symbols, function-section map, or runtime trace is available.

## Supporting Research

## Target

- Target UID: [UID:000139]
- Target path: `by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:000006`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000006`, final C++ blank.
- Source queue/report row: `by-memory/-coverage-report.md` row under [UID:000138] `EmployeeDialogPanes`, currently noting A001's raw no-function/no-xref pass and saying the blank C++ is pending this B-agent source-placement decision.
- Current supervisor classification: heavy source-placement/reachability inference for a retained unreferenced raw constructor-shaped island.

## Executive Recommendation

The current docs/scores/routes should remain unchanged.

The best source model is: the bytes at `0x004a4ae0-0x004a4b1f` are a retained out-of-line constructor-shaped body for `AddEmployeeItemDialog`, while the only proven runtime construction path is the inline sequence inside [UID:0003KY] `EmployeeDialogPaneOnButtonAction` at `0x004a3381-0x004a33be`. This is the same middle-ground handling already used for nearby raw constructors: preserve the executable class-construction evidence, route it through the true class owner, and keep final C++ blank until the final source strategy can decide whether to write a normal constructor definition, rely on inlined construction from the call site, or let the compiler emit both.

Do not reclassify [UID:000139] to ignored/non-emitting-only. Do not merge it into [UID:00013A]. Do not create an IDA function at `0x004a4ae0`. Do not emit standalone constructor C++ from this page yet.

## Supervisor Active Recheck

- The supervisor asked B001 to extend A001's raw-start work with broader source/build heuristics, neighboring constructor patterns, source-file placement comparisons, and additional IDA/binary evidence.
- This target did not require split repair. The exact target range already exists and has a class owner/emitter route.
- B001 made no direct by-* edits and no IDA DB edits. This report is the only output.

## Inference Research Guidance Check

- `by-structure.md` says `CANONICAL_OWNER` is the narrowest true semantic owner. A constructor-shaped class body belongs directly to [UID:000006] `AddEmployeeItemDialog`, not directly to the file root.
- `EMITTER_UIDS` is output routing, not ownership. The current route through [UID:000006] is still correct because the class page routes to [UID:0000J0] `EmployeeDialogPane`.
- `RECONSTRUCTABLE:TRUE` is appropriate when IDA/MCP evidence shows NexusTK-owned source that must be rebuilt even when exact final source shape or C++ is not ready.
- The final C++ gate is minimum eligibility only. Here, source placement and reachability are still not good enough to write final source despite `85/90` and a valid emitter route.
- `inference_research.md` says source-file ownership cannot be proven without debug/source/build metadata and must be phrased probabilistically. This pass found no PDB/source path/COFF symbol evidence sufficient to prove the original compilation unit or dead-code cause.
- I did not use Wave2/Wave3 source data. Existing docs that mention generated/Wave3 labels were treated only as documentation history, not as direct source evidence.

## Evidence Standards Used

Evidence checked in this B001 pass:

- Fresh read-only IDA MCP calls against session `c001_midiplayer_rdata_20260615`.
- Fresh local PE parsing and raw scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Existing target/support docs: [UID:000139], [UID:000006], [UID:0000TT], [UID:0000J0], [UID:0000KE], [UID:0001TN], [UID:0002MH], [UID:00013A], [UID:000138], and `by-project-structure/proposed-source-tree.md`.
- Neighbor pattern docs: employee raw helper islands [UID:0003L0]/[UID:0003L2], raw constructor [UID:00014Q] `ExchangeItemListPaneRawConstructor`, raw constructor [UID:00021X] `ClanItemDialogRawConstructor`, and the executed B001 report for [UID:0002NX]/[UID:0002O1].

## IDA MCP Facts

Fresh IDA MCP session state:

- `server_health` returned `status: ok`, input `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache ready.

Function/range facts from `lookup_funcs`:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x004a4adb` | `Not a function` | Previous modeled body ends before five `0xcc` bytes. |
| `0x004a4ae0` | `Not a function` | Raw constructor start is still not an IDA function. |
| `0x004a4b1f` | `Not a function` | Alignment byte before next modeled function. |
| `0x004a4b20` | `sub_4A4B20`, size `0x191` | Real `AddEmployeeItemDialog` action method. |
| `0x004a3240` | `sub_4A3240`, size `0x198` | `EmployeeDialogPane::OnButtonAction`. |
| `0x004a339f` | inside `sub_4A3240` | Live inline base-constructor call. |
| `0x004a4aee` | `Not a function` | Raw base-constructor call has no containing function. |
| `0x004ae4c0` | `sub_4AE4C0`, size `0x435` | Generic `AddItemDialog` base constructor. |
| `0x004a4afe` | `Not a function` | Raw primary vtable store has no containing function. |

Xref facts:

| Target | Fresh IDA result | Meaning |
| --- | --- | --- |
| `0x004a4ae0` | zero code refs, zero data refs, `trace_data_flow` depth 0 only | No static raw-start reachability. |
| `0x004ae4c0` | code refs at `0x004a339f`, `0x004a4aee`, `0x004ad124`, `0x004af924`, `0x004b0031` | Raw and inline AddEmployee paths both call the same base constructor; other refs belong to neighboring item-dialog flows. |
| `0x006190d4` | data refs at `0x004a33a4`, `0x004a4afe` | Primary AddEmployee vtable written by live inline path and raw body. |
| `0x00619134` | data refs at `0x004a33aa`, `0x004a4b04` | Secondary AddEmployee vtable written by live inline path and raw body. |
| `0x00619164` | data refs at `0x004a33b4`, `0x004a4b0e` | Tertiary AddEmployee vtable written by live inline path and raw body. |
| `0x004a4b20` | data ref at `0x0061911c` | Action method is vtable-dispatched, not statically called. |
| `0x004a4d00` | refs from vtable `0x006190d4` and adjustor thunks `0x004a4cb7`/`0x004a4cc2` | Destructor path is real class vtable behavior. |

Byte facts from `get_bytes 0x004a4adb size 69`:

- Five `0xcc` bytes precede the raw prologue.
- The raw body starts with `55 8b ec 51 56`, saves `this`, pushes two zero arguments, and calls `0x004ae4c0`.
- It stores the explicit constructor argument into `[this+0x270]`.
- It writes vtables `0x006190d4`, `0x00619134`, and `0x00619164`.
- It ends with `5e 8b e5 5d c2 04 00`, then one `0xcc` before `0x004a4b20`.

Live inline path facts:

- Decompilation of `0x004a3240` shows the `Block == 0` branch allocating `628` bytes at `0x004a3381`, calling `sub_4AE4C0(0, 0)` at `0x004a339f`, writing the same three `AddEmployeeItemDialog` vtables at `0x004a33a4`/`0x004a33aa`/`0x004a33b4`, and storing `this` at dword index `156` at `0x004a33be`.
- Disassembly of the same window confirms the raw instruction shape: `push 274h`, call allocator, two zero pushes, `mov ecx, edi`, call base constructor, three vtable stores, and `mov [edi+270h], esi`.
- Disassembly of `0x004a4b20` confirms the action method reads the owner pointer with `mov ebx, [esi+270h]` at `0x004a4be6`, clears owner state at `+0x420`, checks item metadata at `+0x1ec`, and either opens `EmployeeQuantityInputDialogPane` or dispatches command helper `0x005975e0`.

## Local PE / Build-Metadata Facts

Fresh raw PE scan facts:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x400000`
- Sections: `.text`, `.rdata`, `.data`, `.rsrc`
- COFF symbol table: absent (`NumberOfSymbols == 0`, pointer `0x0`)
- PE debug directory: one entry at `RVA 0x240270`, type `13`, size `0x390`; payload begins with section/subsection names such as `.text`, `.text$di`, and `.text$mn`, but does not identify source files or functions.
- Markers searched and not found: `RSDS`, `NB10`, `.pdb`, `.PDB`, `.cpp`, `.CPP`, `.obj`, `.OBJ`.
- RTTI type-name strings for `EmployeeDialogPane` and `AddEmployeeItemDialog` exist under `.rdata`; these prove type identity, not source file placement.

Reachability and body-shape scan facts:

| Check | Result |
| --- | --- |
| Exact raw body `0x004a4ae0-0x004a4b1f` | one occurrence, at `0x004a4ae0` only |
| Little-endian VA hits for `0x004a4adb`, `0x004a4ae0`, `0x004a4b1f` | zero |
| Little-endian RVA hits for `0x000a4adb`, `0x000a4ae0`, `0x000a4b1f` | zero |
| Little-endian pointer values to any address inside `0x004a4ae0-0x004a4b1f` | zero |
| `.text` relative `E8`/`E9`/near conditional branches to `0x004a4ae0` | zero |
| `.text` relative branches to any address inside `0x004a4ae0-0x004a4b1f` | zero |
| Relative calls to base constructor `0x004ae4c0` | `0x004a339f`, `0x004a4aee`, `0x004ad124`, `0x004af924`, `0x004b0031` |
| Exact primary vtable store patterns | one inline at `0x004a33a4`, one raw at `0x004a4afe` |
| Exact secondary vtable store patterns | one inline at `0x004a33aa`, one raw at `0x004a4b04` |
| Exact tertiary vtable store patterns | one inline at `0x004a33b4`, one raw at `0x004a4b0e` |
| Exact inline owner store pattern `[edi+0x270]` | one hit at `0x004a33be` |
| Exact raw base-call relative encoding | one hit at `0x004a4aee` |
| Exact inline base-call relative encoding | one hit at `0x004a339f` |

The PE scan strengthens both sides of the decision: the raw body is unique, coherent, and class-specific, but no direct static entry route to the raw body or its interior was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Status |
| --- | --- | --- | --- | --- | --- |
| `0x004a3381-0x004a33be` | [UID:0000TT] `by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md` | Live inline construction sequence inside `EmployeeDialogPane::OnButtonAction` | `FALSE` standalone | [UID:0003KY] | Correct as source-map anchor only |
| `0x004a4ae0-0x004a4b1f` | [UID:000139] target | Raw constructor-shaped AddEmployee body | `TRUE` | [UID:000006] | Keep current metadata, blank C++ |
| `0x004a4b20-0x004a4d3b` | [UID:00013A] `AddEmployeeItemDialog` | Confirmed action/destructor range | `TRUE` | [UID:000006] | Separate from raw constructor |
| `0x006190d0-0x0061916c` | [UID:0002MH] `AddEmployeeItemDialogVtableData` | Exact AddEmployee vtable data | `TRUE` | [UID:0001XH] | Confirms class identity and raw/inline vtable pairings |
| `AddEmployeeItemDialogLayout` | [UID:0001TN] | Class layout: base plus owner pointer at `+0x270` | `TRUE` | [UID:000006] | Confirms one derived owner member |

## Documentation Evidence And IDA Status

Existing docs that support the recommendation:

- [UID:000139] already records raw no-function/no-xref status, exact constructor-shaped bytes, class owner/emitter route, and a blank final C++ block.
- [UID:000006] `AddEmployeeItemDialog` treats the raw constructor as a no-runtime/no-xref caveat while assigning the class to the employee-dialog module.
- [UID:0000TT] identifies the live construction path inside `EmployeeDialogPane::OnButtonAction` and marks it non-reconstructable as a standalone item.
- [UID:0001TN] records the class layout and explicitly says source should model a small derived class over `AddItemDialog` with an `EmployeeDialogPane*` owner.
- [UID:0002MH] records the exact vtable data and the paired live/raw vtable-store refs.
- [UID:0000J0] `EmployeeDialogPane` lists `AddEmployeeItemDialog` as part of the employee-shop feature module while keeping generic item picker construction in [UID:0000KE] `ItemDialogs`.
- [UID:0000KE] says `AddEmployeeItemDialog` reuses `AddItemDialog` but its owner pointer and command path are employee-specific, so it should not be used as generic `ItemDialogs.cpp` ownership proof.
- `proposed-source-tree.md` repeats the same split: base picker in `ItemDialogs.cpp`, employee-specific subclass with `EmployeeDialogPane.cpp`.

Neighboring pattern evidence:

- [UID:0003L0] and [UID:0003L2] are employee raw helper islands with no modeled IDA function starts/xrefs, but are kept reconstructable because their bytes are employee-dialog source behavior.
- [UID:00014Q] `ExchangeItemListPaneRawConstructor` is a raw/non-IDA constructor start with no direct raw-start refs, class-owned route, reconstructable `TRUE`, and blank final C++.
- [UID:00021X] `ClanItemDialogRawConstructor` is a class-owned raw constructor body with no function object/xrefs and no PE pointer/branch hits, kept reconstructable with blank final C++.
- The executed B001 clan report for [UID:0002NX]/[UID:0002O1] reached the same policy conclusion for comparable retained unreferenced raw constructor bodies: class-owned reconstructable evidence, blank final C++, no ignored/non-emitting reclassification.

Existing docs that are potentially stale but do not require direct change:

- `by-memory/-coverage-report.md` still says final C++ is pending this B-agent decision. This report is the closure for that decision. Because no metadata or coverage-state change is recommended, no coverage row replacement is required for correctness.

## Ranked Ownership / Disposition Analysis

### 1. Keep As Reconstructable Raw Constructor Evidence With Blank Final C++

Evidence for:

- The raw bytes are executable project-code bytes, not padding, a thunk, or a container.
- The body has normal constructor shape: prologue, `this` save, base `AddItemDialog` constructor call, derived owner-pointer store, derived vtable installs, and `retn 4`.
- The body is unique in the PE and exactly bracketed by `0xcc` padding/successor boundary.
- The raw body and live inline path share the same base constructor, three derived vtables, and owner-pointer slot.
- The action method consumes the `+0x270` owner pointer written by both paths.
- Neighboring raw constructor docs and prior B001 reports use this same classification for no-function/no-xref constructor-shaped bodies when class identity is strong.
- `by-structure.md` allows `RECONSTRUCTABLE:TRUE` when source ownership is real but final source shape is not ready.

Evidence against:

- No raw-start function object exists in IDA.
- No static raw-start or interior raw-body branch/pointer reachability was found.
- The live runtime path is the inline construction sequence in `EmployeeDialogPane::OnButtonAction`.

Decision:

Accepted. The negative reachability evidence blocks final standalone C++ emission, not reconstructable classification or class ownership.

### 2. Emit A Standalone Constructor Body In Final C++ Now

Evidence for:

- The byte behavior maps cleanly to a likely source constructor such as `AddEmployeeItemDialog(EmployeeDialogPane*)`.
- The direct class owner and emitter route are valid, and `85/90` clears the numeric minimum code-entry gate.

Evidence against:

- Numeric eligibility is not enough. The final source shape still conflicts with the proven inline construction path.
- No static caller or address-taken reference proves the original program uses the raw body as a callable out-of-line constructor.
- Emitting this page as standalone C++ now could double-represent construction if final `EmployeeDialogPane::OnButtonAction` is later written as the source-level creation path.
- A source-quality constructor would not manually write vtables; it would rely on normal C++ construction. That requires the final class/base declarations and constructor strategy to be settled first.

Decision:

Rejected for now. Keep the C++ block blank.

### 3. Treat As Dead/Duplicate Retained Code Caused By The Inline Path

Evidence for:

- No raw-start xrefs, no pointer values to any raw-body address, and no relative branches into the raw body were found.
- The inline path duplicates the source-level effects.
- A compiler/linker could retain an out-of-line function body while inlining all observed call sites.

Evidence against:

- No PDB, object file, linker map, COFF symbols, COMDAT grouping, or function-section record proves this body is discarded, stale, duplicate-only, or unreachable by original design.
- The body is not a duplicate byte clone; it is the single exact out-of-line AddEmployee constructor-shaped body.
- It is class-specific source behavior, not ABI glue.
- The binary contains other raw no-function employee helper islands that are retained as reconstructable source evidence, so no-xref alone is not enough to mark project code dead.
- If the original source declared an out-of-line constructor and the compiler inlined the only local construction site, the retained body is still useful original-source evidence even if not currently referenced.

Decision:

Rejected as a metadata change. It is fair to say "retained out-of-line body with all proven call sites inlined"; it is not safe to say "dead/duplicate-only" strongly enough to ignore or de-route it.

### 4. Reclassify To Non-Emitting / Ignored Evidence Only

Evidence for:

- Final C++ should stay blank.
- Static reachability is unproven.

Evidence against:

- `RECONSTRUCTABLE:FALSE` is for padding, containers, compiler/runtime groups, or items that should not become source-level objects. This target is a real class constructor-shaped source body.
- Ignored/non-emitting classification would lose the direct class ownership evidence and obscure the class construction semantics.
- Current blank final C++ already prevents accidental source emission while preserving source evidence.
- The current `EMITTER_UIDS:000006` is useful future routing if the final source model writes a normal constructor in the class.

Decision:

Rejected. Keep reconstructable `TRUE`, owner/emitter [UID:000006], C++ blank.

### 5. Move Direct Ownership To `EmployeeDialogPane`, `ItemDialogs`, Or `NONE`

Evidence for `EmployeeDialogPane` file:

- The live construction path is inside `EmployeeDialogPane::OnButtonAction`.
- The owner pointer and command path are employee-specific.
- The class routes through [UID:0000J0] `EmployeeDialogPane`.

Evidence against direct file ownership:

- `by-structure.md` requires the narrowest true direct semantic owner. A constructor-shaped class body belongs directly to the class, with the class then routing to the file.

Evidence for `ItemDialogs`:

- The raw and inline bodies call the generic `AddItemDialog` base constructor.
- The vtable layout matches the generic item-dialog three-view shape.

Evidence against `ItemDialogs`:

- The derived state is `EmployeeDialogPane*`, the live creator is the employee dialog, and the action method dispatches employee commands.
- `ItemDialogs.md` explicitly keeps generic base picker code here but not the employee-specific subclass.

Evidence for `NONE`:

- Raw reachability is unproven.

Evidence against `NONE`:

- Class identity is strongly proven by the three vtables and owner slot.
- The direct class page clears the owner gate and already routes to a valid file root.

Decision:

Rejected. Keep direct owner/emitter [UID:000006].

### 6. Split, Merge, Or Reclassify The Range

Evidence for merge with [UID:00013A]:

- The raw constructor is adjacent to the confirmed AddEmployee method/destructor range.
- Both belong to the same class.

Evidence against merge:

- The raw body is separated from the next function by a `0xcc` byte and lacks IDA function status; [UID:00013A] is a confirmed method/destructor range beginning at `0x004a4b20`.
- Keeping [UID:000139] separate cleanly documents the disputed constructor boundary without contaminating the confirmed method range.

Evidence for splitting:

- None. The raw body is already an exact, coherent constructor-shaped item.

Decision:

Rejected. No split/merge/reclassification is recommended.

### 7. Create Or Rename An IDA Function At `0x004a4ae0`

Evidence for:

- The bytes are instruction-aligned and constructor-shaped.

Evidence against:

- IDA has no existing function object, no raw-start xrefs, no pointer refs, and no branch refs into the range.
- Creating a function would make a database assertion stronger than the current evidence.
- The documentation can preserve the raw evidence without changing IDA.

Decision:

Rejected. No IDA DB changes.

## Source / Build Heuristic Conclusion

The most plausible build-level explanation is a retained out-of-line constructor body whose observed construction site was inlined into `EmployeeDialogPane::OnButtonAction`. That explains why the raw body and live inline path share exact class-construction effects while no call to the raw start exists.

However, the binary does not reveal why the body was retained. The available PE metadata does not expose source files, object files, COMDAT group ownership, function-level link elimination decisions, or a linker map. The body could be retained because the build did not eliminate unreferenced functions, because the original constructor had external/linkage constraints, because the object was included wholesale, or because the final linked binary preserved a local out-of-line body despite all visible call sites being inlined. None of those possibilities is provable from the current static evidence.

The practical reconstruction answer is therefore:

- Use [UID:0000TT] and [UID:0003KY] as the runtime construction anchor.
- Keep [UID:000139] as class constructor evidence.
- When final source is written, prefer normal C++ class construction semantics over manual vtable-patching source.
- Do not write that constructor source until `AddItemDialog`, `AddEmployeeItemDialog`, and the `EmployeeDialogPane::OnButtonAction` source shape are ready to be reconciled together.

## Negative Evidence Summary

Checked and resolved negatively:

- IDA function object at raw start/end: none.
- IDA xrefs to raw start: none.
- IDA code/data refs to raw start through `find`: none.
- IDA data-flow refs to raw start: none.
- Absolute VA/RVA pointer hits to raw start and neighbors: none.
- Absolute pointer values to any address inside the raw constructor body: none.
- Relative call/jump/near conditional branch targets to raw start: none.
- Relative branch targets to any address inside the raw body: none.
- Exact duplicate raw constructor body elsewhere in the PE: none.
- Embedded PDB/source path/COFF symbol evidence for source placement: none.
- Stronger generic `ItemDialogs` ownership: rejected because derived owner state and action path are employee-specific.
- Stronger file-level direct owner than class owner: rejected under `by-structure.md` narrow-owner rules.

## Unresolved Issues And Why They Cannot Be Safely Resolved Here

### Exact Original Build Cause

Evidence checked:

- PE section list and debug directory.
- COFF symbol table absence.
- PDB/CodeView/source extension marker scan.
- Raw branch/pointer scans.
- Neighbor raw-constructor and raw-helper patterns.

Why unresolved:

The linked PE does not contain the object-file/source/debug metadata needed to distinguish "retained unused out-of-line constructor" from "linker/codegen artifact after inlining" with final certainty. Resolving this would require a matching PDB, linker map, object files, compiler/linker flags, another build with different optimization, or runtime trace entering `0x004a4ae0`.

### Final C++ Shape

Evidence checked:

- Raw body bytes.
- Live inline construction decompile/disassembly.
- Class layout and vtable docs.
- `EmployeeDialogPane` and `ItemDialogs` source-placement docs.

Why unresolved:

The source-level final form must be decided with the surrounding class declarations and `EmployeeDialogPane::OnButtonAction` rewrite. Emitting this page alone would overclaim source structure. The current blank C++ is the correct state.

### Original Source File Split

Evidence checked:

- [UID:0000J0] `EmployeeDialogPane`, [UID:0000KE] `ItemDialogs`, and proposed source tree.
- Live inline construction site, owner pointer, and employee command dispatch.

Why unresolved:

The class strongly belongs with the employee-dialog module in the current reconstruction, while the generic base belongs in `ItemDialogs`. The exact original file split could have been `EmployeeDialogPane.cpp` alone or a small adjacent employee item-dialog source file. That does not require changing [UID:000139] because its direct owner remains the class.

## Final Recommendation

Make no direct documentation or IDA changes.

Keep [UID:000139] exactly as:

- `COMPLETION:85`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:000006`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000006`
- blank final C++

Keep support docs unchanged:

- [UID:000006] `AddEmployeeItemDialog`
- [UID:0000J0] `EmployeeDialogPane`
- [UID:0000KE] `ItemDialogs`
- [UID:0000TT] `AddEmployeeItemDialogInlineConstruction_004A339F`
- [UID:0001TN] `AddEmployeeItemDialogLayout`
- [UID:0002MH] `AddEmployeeItemDialogVtableData`
- [UID:00013A] `AddEmployeeItemDialog`

Do not:

- Reclassify [UID:000139] to ignored or `RECONSTRUCTABLE:FALSE`.
- Clear owner/emitter metadata.
- Merge it into [UID:00013A] or [UID:000138].
- Move direct owner to [UID:0000J0] or [UID:0000KE].
- Add final reconstruction C++.
- Create an IDA function, rename, or type at `0x004a4ae0`.
- Replace the `by-memory/-coverage-report.md` row. The row's pending wording is resolved by this report and can be handled by supervisor tracking without a required coverage-state edit.

## Follow-Up Actions

Supervisor actions:

- Mark this assignment complete/no-change in supervisor tracking.
- No target/support/shared-row/IDA changes are recommended.
- No validation command is required because only this research report was created.

A-agent actions:

- None for [UID:000139].
- Future final-source work for `EmployeeDialogPane::OnButtonAction`, `AddItemDialog`, and `AddEmployeeItemDialog` should reconcile the inline construction path and raw constructor evidence together before adding C++.

B001 future research actions:

- None required for this target unless new PDB/object/linker-map/runtime evidence appears.

## Confidence

- Recommendation confidence: high.
- Classification confidence: high that [UID:000139] is class-owned reconstructable evidence with blank final C++.
- Build-cause confidence: medium. Retained out-of-line constructor plus inlined call site is the best explanation, but current static evidence cannot prove the linker/codegen reason.
- Score confidence: current `85/90` is appropriate. The new checks strengthen the negative reachability and metadata story, but they do not resolve final source shape enough to justify a score increase. No score decrease is justified because class identity and byte semantics remain very strong.

## Validator Results

Not run. No by-* documentation, generated report, project-level report, coverage report, or IDA DB item was changed.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/000139-addemployee-raw-constructor-source-placement.md`

Modified:

- None outside this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000139-addemployee-raw-constructor-source-placement.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"000139"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
