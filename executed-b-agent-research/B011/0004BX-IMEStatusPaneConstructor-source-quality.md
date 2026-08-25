** TARGET-REPORT-UID:0004BX **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0004BX] IMEStatusPaneConstructor Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: convert [UID:0004BX] `IMEStatusPane::IMEStatusPane()` from an exact split child with blank emitter/code into an emitting [UID:00006I] `IMEStatusPane` method child routed through [UID:0000K5] `IMEPanes`.
- Final disposition: source-authored `IMEStatusPane` constructor, not an aggregate marker, no-code placeholder, `Pane` helper, `g_pIMEPane`/root-pane method, read-only-data owner, or `MainUiLayerSlots` owner.
- Required action after supervisor validation: update the target metadata to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:00006I`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00006I`, keep `EMITTER_POSITION_OPTIONAL` blank, and insert the formal constructor C++ block below. Refresh only concise support rows/notes in the class/file/aggregate docs if the supervisor wants mirrored state; the target page should carry the full proof.
- Confidence: high for range, constructor identity, base construction, `statusText[256]` zeroing, `Closed` setup, inherited layer/order helper calls, owner route, and first-draft source shape; capped below final audit because original stripped helper/member spellings for `Pane(0)`, zero-rect initialization, `AddToLayer`, and `SetPaneOrder` remain source-facing descriptive names supported by current docs rather than recovered PDB names.

## Target

- Target UID: [UID:0004BX]
- Target path: `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md`
- Assignment: `B011-report-0004BX-IMEStatusPaneConstructor-20260630`
- Source queue basis: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, row observed by supervisor as `82/88`, combined `85.0`, reconstructable `true`, reports `0`.
- Direct owner/support pages checked: [UID:00006I] `by-class/IMEStatusPane.md`, [UID:0000K5] `by-file/IMEPanes.md`, [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, [UID:0004BW] `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md`, [UID:00025J] `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md`, `Pane`/`PaneCore`, and `MainUiLayerSlots` support.

## Current Target State

| Field | Current value |
| --- | --- |
| `COMPLETION` | `82` |
| `CONFIDENCE` | `88` |
| `CANONICAL_OWNER` | `00006I` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | blank |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Formal C++ | blank |

The current target page correctly identifies the exact split child and class/source route, and it records the base-pane construction, vtable installation, `statusText[256]` zeroing, `Closed` setup, and "root attachment" at a high level. The score/source-quality blocker is stale callback wording: `EMITTER_UIDS` stays blank and formal C++ remains blank until a child-specific body is accepted. Current MCP evidence resolves that blocker. The only wording to correct is that the constructor does not attach through `g_pIMEPane`; current MCP shows it initializes a zero bounds object and calls inherited `Pane::AddToLayer(..., g_mainUiLayerSlots.fpsOverlayLayerContext)` followed by `Pane::SetPaneOrder(0, 0)`.

Related current generated state:

- `auto-generated/NexusTK/input/IMEPanes.cpp` header observed after concurrent IME work: `validator-command-id: 000000003193`, `validator-refreshed-at: 2026-06-30T16:22:35-04:00`, source by-file UID `0000K5`.
- Generated output already contains [UID:00006I] `class IMEStatusPane` with `IMEStatusPane();`, `virtual ~IMEStatusPane();`, `SetText`, `OnIMEModeChange`, `OnPaintFrame`, and `wchar_t statusText[256]`.
- Generated output currently contains [UID:0004BY] `IMEStatusPane::~IMEStatusPane()` and [UID:0004C0] `IMEStatusPane::OnPaintFrame()`, but no [UID:0004BX] marker/body because this target has blank `EMITTER_UIDS` and blank formal C++.

## Supervisor Active Recheck

This is a report-only assignment. No by-* target/support docs, generated files, coverage reports, validator/tool state, IDA DB, archives, queue files, supervisor ledgers, or lock files were edited, and no leases were taken. The target is a single modeled function with clean padding boundaries; no split, rename, new child UID, or TMP reference workflow is needed.

## Evidence Checked

Current by-* docs and generated state checked:

- [UID:0004BX] target `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md`
- [UID:00006I] `by-class/IMEStatusPane.md`
- [UID:0000K5] `by-file/IMEPanes.md`
- [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
- [UID:0004BW] `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md`
- [UID:0004BY] `by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md`
- [UID:0004C0] `by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md`
- [UID:00025J] `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md`
- [UID:0001EA] `by-memory/0x00544460-0x00545086.PaneCore.md`, `by-class/Pane.md`, and `by-file/Pane.md`
- `by-global/MainUiLayerSlots.md`, [UID:0001PG] `by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md`, and [UID:0003B4] `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`
- `auto-generated/NexusTK/input/IMEPanes.cpp`

Workflow/structure guidance checked:

- `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `references/b-agent-research-and-implementation-workflow.md`
- `references/score-blocker-audit-standard.md`
- `references/b-agent-report-template.md`
- `by-structure.md` current metadata/emitter/C++ gate and IDA MCP output-discipline sections
- `by-memory/-guidance.md`, `by-class/-guidance.md`, and `by-file/-guidance.md` were used as local routing guidance for this by-memory method-body report.

Old/current report searches:

- Search terms included `0004BX`, `0x004e71c0`, `0x004e728a`, `IMEStatusPaneConstructor`, `IMEStatusPane::IMEStatusPane`, `sub_4E71C0`, `Closed`, `statusText`, `IMEPanes`, `IMEPaneFamily`, `0x0061c580`, `0x0069b37c`, `Pane::AddToLayer`, and `Pane::SetPaneOrder`.
- Relevant executed report lead: `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`. It created [UID:0004BX] as an exact split child and recorded current MCP facts for `0x004e71c0`, but intentionally left child-specific body C++ out of that split callback.
- Relevant executed sibling precedent: `executed-b-agent-research/B007/0004BY-IMEStatusPaneOrdinaryDestructor-source-quality.md`. It treats zero inbound xrefs to a class lifecycle method as a confidence caveat, not no-code proof, when the method is an exact class child and the class declaration/source route needs the definition.
- Relevant executed sibling/style lead: `executed-b-agent-research/B007/0004C0-IMEStatusPaneOnPaintFrame-source-quality.md`. It establishes the accepted [UID:00006I] -> [UID:0000K5] route and status-pane method emission through the class shell.
- Relevant active lead: `tools/leaser/Agents/Agent-B009/research/0004BW-IMEStatusPaneSetText-source-quality.md`. It confirms [UID:0004BX] is one of exactly two `SetText` callers and provides compatible `statusText[256]`/helper style leads. It is active lead material only until supervisor execution.

Current IDA MCP evidence:

- MCP session availability was checked using schema-current JSON-RPC. `idb_list` id `10` reported one active worker session `supervisor_resume_20260629` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, PID/worker PID `24256`, `is_analyzing:false`, active true. `server_health` id `11` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- `lookup_funcs` id `12` reported `0x004e71c0 -> sub_4E71C0`, size `0xca`; `0x004e728a` is not a function; predecessor `0x004e70f0 -> sub_4E70F0`, size `0xcc`; successor `0x004e7290 -> sub_4E7290`, size `0x1f`; later status methods `0x004e72b0` size `0x48` and `0x004e7300` size `0x7b`; aggregate end `0x004e8433` is not a function.
- `decompile 0x004e71c0` id `13` showed `sub_544460((char *)this, 0)`, three `IMEStatusPane` vtable writes at `this+0x00`, `this+0xa0`, and `this+0xa4`, `_memset(this+0xf8, 0, 0x200)`, `sub_4B7C50(&v3, 0, 0, 0, 0)`, `sub_4E70F0(this, L"Closed", 6)`, `sub_544C70(this, &v3, 0, 0, unk_69B37C)`, `sub_544D30(this, 0, 0)`, and `return this`.
- `disasm 0x004e71c0` id `20` confirmed the same sequence at instruction level: base constructor call at `0x004e71f3`, vtable stores at `0x004e720d/0x004e7213/0x004e721d`, `_memset` at `0x004e7227`, zero rect initializer at `0x004e7238`, `SetText(L"Closed", 6)` at `0x004e7249`, `unk_69B37C` layer argument at `0x004e724e`, `Pane::AddToLayer` at `0x004e725e`, `Pane::SetPaneOrder` at `0x004e7269`, and return before `0x004e728a`.
- `get_bytes` id `19` over `0x004e71b8` showed four `0xcc` bytes before the constructor, the complete constructor bytes, six `0xcc` bytes from `0x004e728a-0x004e7290`, and then the ordinary destructor begins at `0x004e7290`.
- `xrefs_to` id `16`/`21`: `0x004e71c0` has zero inbound xrefs; `0x004e70f0` has exactly two code xrefs, the constructor call at `0x004e7249` and mode-change call at `0x004e72ec`.
- Vtable xrefs: `0x0061c364` has constructor `0x004e720d`, ordinary destructor `0x004e7290`, scalar wrapper `0x004e8806`; `0x0061c3b0` has constructor `0x004e7213`, ordinary destructor `0x004e7296`, scalar wrapper `0x004e880c`; `0x0061c3e0` has constructor `0x004e721d`, ordinary destructor `0x004e72a0`, scalar wrapper `0x004e8816`.
- `xrefs_to 0x0061c580` reported the `Closed` literal xref from constructor `0x004e7244`.
- `entity_query` id `17` over `0x0061c360-0x0061c5a0` returned exactly 15 names: twelve IME pane vtable bases and `aClosed`, `aIme`, `aEng`. `get_string` id `18` decoded `0x0061c580` as `Closed`, `0x0061c590` as `IME`, and `0x0061c598` as `ENG`.
- `xrefs_to 0x0069b458` reported 17 refs to `g_pIMEPane` across IME composition/candidate/root/text/startup/shutdown paths, with no constructor `0x004e71c0` xref.
- `xrefs_to 0x0069b37c` reported 11 refs, including constructor `0x004e724e`, composition constructor `0x004e7416`, candidate constructor `0x004e7c2c`, `IMEPane::HandleIMEMessage` `0x004e8281/0x004e8377`, startup, and shutdown. Current support identifies this as `g_mainUiLayerSlots.fpsOverlayLayerContext`, not an IME-owned singleton.
- `analyze_function 0x00544c70` id `22` matches current `Pane::AddToLayer`: it selects `a4+0xa8` when a parent pane exists, otherwise uses the explicit layer context pointer, calls the layer add-child helper, and stores the layer pointer at `this+0xa8`.
- `analyze_function 0x00544d30` id `23` matches current `Pane::SetPaneOrder`/dispatcher-order helper: it registers the pane's event subobject at `this+0xa0` with optional before/after pane arguments adjusted by `+0xa0`.
- `analyze_function 0x004e70f0` id `24` confirms `IMEStatusPane::SetText` clamps length to 255, measures the text, builds a lower-right `RectBounds`, calls inherited `SetBounds`, copies into `statusText[256]`, writes a trailing nul, and invalidates. This constructor's `SetText(L"Closed", 6)` call is therefore behaviorally meaningful, not just an initializer label.
- `analyze_function 0x004b7c50` id `25` confirms a four-dword bounds initializer with all-zero arguments in the constructor.
- `analyze_function 0x004e7f20` id `26` confirms the root `IMEPane` constructor writes `g_pIMEPane`; this is separate from [UID:0004BX], which has no direct `g_pIMEPane` xref.

Negative checks performed:

- No function starts at `0x004e728a`, so the target half-open end is not a second body.
- No direct xrefs to constructor entry `0x004e71c0`; this is expected for a retained class lifecycle function and remains a confidence caveat, not no-code proof.
- No `g_pIMEPane` xref in the constructor; the constructor's attachment dependency is `0x0069b37c` layer context, not root singleton publication.
- Status vtable xrefs are limited to constructor/destructor/scalar-wrapper stores and the vtable island; they prove class identity but should not be hand-authored as source statements.

Failed/unavailable checks: none. MCP was available and healthy for this pass. No fallback-only research was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:0004BX] is one complete modeled function at `0x004e71c0-0x004e728a`, size `0xca`, with padding before and six `0xcc` bytes before successor `0x004e7290`. | High | MCP `lookup_funcs` id `12`, `disasm` id `20`, `get_bytes` id `19`; current target/aggregate docs. | Target `Status`, `Evidence`, `Range / Split`, `Score Rationale`; aggregate row. | incorporate | applied - target `Evidence` and aggregate covered/split rows record size, half-open end, and padding. |
| C02 | Direct semantic owner remains [UID:00006I] `IMEStatusPane`; source route is [UID:00006I] -> [UID:0000K5] `IMEPanes`; aggregate support is [UID:000189]. | High | Target/class/file/aggregate docs; vtable triad xrefs; class field `statusText[256]`; generated class shell. | Target metadata/status; class/file/aggregate support rows. | incorporate | applied - target metadata/status, class method row, file proposed contents/change note, and aggregate rows route [UID:00006I] -> [UID:0000K5]. |
| C03 | The body calls `Pane::Pane(0)`/base construction before installing `IMEStatusPane` vtable views. | High | MCP `decompile` id `13`, `disasm` id `20`, PaneCore docs. | Target `Behavior`, `Evidence`, formal C++; no support edit required. | incorporate | applied - target `Behavior`, `Evidence`, formal C++, class/file/aggregate notes all preserve `Pane(0)`. |
| C04 | The vtable stores at `+0x00/+0xa0/+0xa4` are compiler-generated class-construction effects and must be documented as evidence, not emitted as handwritten C++ statements. | High | MCP `decompile` id `13`, vtable xrefs id `21`, [UID:00025J], sibling destructor [UID:0004BY]. | Target `Evidence`, `Reconstruction Notes`, `Rejected Alternatives`; read-only-data support already-present. | incorporate | applied - target `Behavior`, `Evidence`, and `Reconstruction Notes` document compiler-only vtable stores; formal C++ omits handwritten vtable writes. |
| C05 | Constructor clears `statusText[256]` by `_memset(this+0xf8, 0, 0x200)` before setting the displayed text. | High | MCP `decompile` id `13`, `disasm` id `20`; class field [UID:00006I]. | Target `Behavior`, `Evidence`, formal C++; class support note optional. | incorporate | applied - target formal C++ uses `memset(statusText, 0, sizeof(statusText))`; class/file/aggregate sync notes mention `statusText[256]` clear. |
| C06 | Constructor initializes display text by calling [UID:0004BW] `SetText(L"Closed", 6)`; `Closed` comes from [UID:00025J] `0x0061c580`, and `SetText` is also called by mode-change handler only. | High | MCP ids `13`, `16`, `18`, `21`, `24`; target and read-only docs. | Target `Behavior`, `Evidence`, formal C++; class/file/aggregate support rows. | incorporate | applied - target `Behavior`/`Evidence` and formal C++ preserve `SetText(L"Closed", 6)`; class/file/aggregate rows mention `Closed`; read-only data left unchanged as already-present. |
| C07 | Constructor initializes a zero bounds object through `0x004b7c50` and attaches through inherited `Pane::AddToLayer(&bounds, 0, 0, g_mainUiLayerSlots.fpsOverlayLayerContext)`. | High | MCP `decompile` id `13`, `disasm` id `20`, `analyze_function` ids `22` and `25`, `xrefs_to 0x0069b37c`. | Target `Behavior`, `Evidence`, formal C++; MainUiLayerSlots support already-present. | incorporate | applied - target formal C++ uses `InitRectBounds` and `AddToLayer(...fpsOverlayLayerContext)`; target/class/file/aggregate notes preserve layer-slot route; MainUiLayerSlots left unchanged as already-present. |
| C08 | Constructor calls `Pane::SetPaneOrder(0, 0)` after attachment. | Medium-high | MCP `decompile` id `13`, `disasm` id `20`, `analyze_function` id `23`; Pane docs name helper as `SetPaneOrder`/dispatcher-order helper. | Target `Behavior`, `Evidence`, formal C++. | incorporate | applied - target formal C++ and `Behavior`/`Evidence` use `SetPaneOrder(0, 0)`; support sync notes preserve order helper route. |
| C09 | The constructor does not publish or consume `g_pIMEPane`; older "root attachment" wording should be clarified to layer-slot attachment and order registration. | High | MCP `xrefs_to 0x0069b458` has no constructor ref; `xrefs_to 0x0069b37c` includes constructor ref; [UID:0004CA] root constructor writes `g_pIMEPane`. | Target `Reconstruction Notes`, `Rejected Alternatives`; file/class support optional. | incorporate | applied - target replaces root-attachment wording with layer-slot attachment and records no direct `g_pIMEPane` xref; file/aggregate notes mirror the caveat. |
| C10 | Zero inbound xrefs to `0x004e71c0` are a reachability caveat, not no-code proof. | Medium-high | MCP `xrefs_to 0x004e71c0` id `16`; exact class lifecycle body; sibling B007 [UID:0004BY] precedent; generated class declaration needs constructor definition. | Target `Evidence`, `Score Rationale`, `Rejected Alternatives`. | incorporate | applied - target `Evidence`, `Score Rationale`, and support rows preserve zero-xref caveat while formal C++ emits. |
| C11 | Recommended formal C++ is the source-level constructor block in this report; no standalone vector/body marker or no-code comment should replace it. | High | Current MCP body, class shell, code-entry gate, score-blocker audit. | Target formal `RECONSTRUCTION_CPP CODE` block. | incorporate | applied - target formal `RECONSTRUCTION_CPP CODE` contains only the accepted constructor body; generated `IMEPanes.cpp` line 446 has [UID:0004BX] body and no empty marker. |
| C12 | Metadata should move from `82/88`, blank emitter to `88/90`, `EMITTER_UIDS:00006I`, owner/reconstructable unchanged, blank position. | High | Score blocker reanalysis, owner/emitter route, C++ readiness. | Target metadata and score rationale. | incorporate | applied - target metadata is `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00006I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006I`, blank position; validator 000000003211 applied the metadata. |
| C13 | [UID:00006I], [UID:0000K5], and [UID:000189] may receive concise sync notes, but [UID:00025J], `MainUiLayerSlots`, `PaneCore`, [UID:0004BW], and `g_pIMEPane` support are already present at same-or-greater supporting detail. | Medium-high | Current docs read; generated class/file route checked. | Support docs/checklist. | already-present or incorporate only if edited | applied/already-present - class/file/aggregate sync notes added; [UID:00025J], MainUiLayerSlots, Pane/PaneCore, [UID:0004BW]/[UID:0004BZ], [UID:0004CA], and `g_pIMEPane` docs left unchanged as already-present support or excluded dependency-owner edits. |

## Positive Evidence Summary

- The target is a real modeled function at `0x004e71c0`, size `0xca`, ending exactly at `0x004e728a` with `0xcc` alignment before `0x004e7290`.
- The body is constructor-shaped: base construction with argument `0`, vtable installation for `IMEStatusPane`, member buffer zeroing, source-level initialization with a string literal, layer attachment, order registration, and return `this`.
- The class route is already established: [UID:00006I] declares `IMEStatusPane();`, owns `statusText[256]`, and emits through [UID:0000K5] `IMEPanes` with `[[CHILDREN]]`.
- The string/literal route is exact: `Closed` decodes at `0x0061c580` and has a constructor xref at `0x004e7244`.
- The helper/callee route is now source-ready: `SetText` has exactly two class-local callers; `AddToLayer` and `SetPaneOrder` are inherited `Pane` dependencies; `0x0069b37c` is a main UI layer context dependency, not a direct IME owner.

## IDA MCP Facts

| Item | Current MCP fact |
| --- | --- |
| Function boundary | `lookup_funcs` id `12`: `0x004e71c0 -> sub_4E71C0`, size `0xca`; `0x004e728a` not a function; successor `0x004e7290 -> sub_4E7290`. |
| Padding | `get_bytes` id `19`: four `0xcc` bytes before constructor and six `0xcc` bytes from `0x004e728a-0x004e7290`. |
| Base construction | `decompile` id `13` and `disasm` id `20`: calls `sub_544460(this, 0)` before vtable stores. |
| Vtable writes | Stores `0x0061c364`, `0x0061c3b0`, and `0x0061c3e0` into `+0x00/+0xa0/+0xa4`; vtable xrefs id `21` tie same tables to constructor, ordinary destructor, and scalar wrapper. |
| Buffer clear | `_memset(this+0xf8, 0, 0x200)` clears `statusText[256]`. |
| Initial text | Calls `SetText` at `0x004e7249` with `aClosed` / `L"Closed"` and length `6`. |
| Bounds/layer | `sub_4B7C50` initializes zero bounds; `sub_544C70` attaches using explicit layer context pointer `unk_69B37C`. |
| Ordering | `sub_544D30(this, 0, 0)` registers pane order/dispatcher ordering. |
| Xrefs | Constructor entry has zero inbound xrefs; `SetText` has exactly two callers; `g_pIMEPane` has no constructor xref; `0x0069b37c` has constructor and sibling pane attachment xrefs. |
| Read-only data | `entity_query`/`get_string` ids `17`/`18`: IME vtable island plus `Closed`, `IME`, `ENG`. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e70f0-0x004e71bc` | [UID:0004BW] `IMEStatusPaneSetText` | Class helper called by constructor and mode-change handler. | TRUE | [UID:00006I] | current target page `82/88`; active B009 report recommends `89/91` | Sibling lead; not edited by B011. |
| `0x004e71c0-0x004e728a` | [UID:0004BX] target | `IMEStatusPane::IMEStatusPane()` constructor. | TRUE | [UID:00006I] | current `82/88`; recommended `88/90` | Ready for emitting constructor body. |
| `0x004e7290-0x004e72af` | [UID:0004BY] `IMEStatusPaneOrdinaryDestructor` | Source-level destructor body; compiler vtable/base teardown. | TRUE | [UID:00006I] | `88/91` after B007 | Executed sibling precedent. |
| `0x004e72b0-0x004e72f8` | [UID:0004BZ] `OnIMEModeChange` | Event type `11`; switches `IME`/`ENG` label. | TRUE | [UID:00006I] | current sibling pending | Caller to SetText, no edit. |
| `0x004e7300-0x004e737b` | [UID:0004C0] `OnPaintFrame` | Paints status label. | TRUE | [UID:00006I] | `88/90` after B007 | Executed sibling style lead. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004e71c0` | zero inbound xrefs | Retained constructor entry has no direct call in current IDA xrefs; not padding/no-code because body is exact class constructor and class declaration needs source definition. |
| `0x004e7249` | calls `0x004e70f0` | Constructor initializes status label through `IMEStatusPane::SetText(L"Closed", 6)`. |
| `0x004e72ec` | calls `0x004e70f0` | Mode-change handler is the only other direct `SetText` caller. |
| `0x004e7244` | literal xref to `0x0061c580` | Uses `Closed` UTF-16 literal. |
| `0x004e724e` | data xref to `0x0069b37c` | Uses main UI layer slot context as explicit layer argument. |
| `0x0061c364/0x0061c3b0/0x0061c3e0` | vtable refs from constructor/destructor/scalar wrapper | Confirms class identity and compiler lifecycle lowering. |

## Heuristic / Inference Reanalysis And Validation

The old "child-specific C++ later" rationale is no longer valid. The current pass rechecked the exact function, dependencies, owner route, generated class shell, and sibling reports. The constructor has enough evidence for formal C++ under the current `by-structure.md` code-entry gate: it is `RECONSTRUCTABLE:TRUE`, has a confirmed emitter route through [UID:00006I] to [UID:0000K5], and the recommended score average is greater than `85`.

Source-facing inference choices:

- `IMEStatusPane::IMEStatusPane()` is direct class method C++. The vtable stores are compiler output; the source block should not assign vtables.
- `Pane(0)` is the most conservative constructor initializer for `sub_544460(this, 0)`. Current docs also describe this as `Pane::Pane(unsigned char mode)` / `Pane(PaneMode mode)`, but no accepted mode enum name is proven for zero here.
- `statusText[256]` is the accepted class field at `+0xf8`; `memset(statusText, 0, sizeof(statusText))` preserves the exact `0x200` zeroing.
- `RectBounds attachBounds` plus `InitRectBounds(&attachBounds, 0, 0, 0, 0)` is the source-facing shape for the four-dword zero initializer. This matches current RectBounds/Panes style and avoids decompiler temporaries.
- `SetText(L"Closed", 6)` is source-ready because the class declares `SetText`, MCP proves the call/literal/length, and [UID:0004BW] documents the callee behavior.
- `AddToLayer(&attachBounds, 0, 0, g_mainUiLayerSlots.fpsOverlayLayerContext)` is the best current source-facing expression for `sub_544C70(this, &bounds, 0, 0, unk_69B37C)`. Support docs already identify `0x0069b37c` as `g_mainUiLayerSlots.fpsOverlayLayerContext`; using `g_pIMEPane` here would be wrong.
- `SetPaneOrder(0, 0)` is the accepted descriptive helper name for `sub_544D30(this, 0, 0)`. The exact original spelling remains a confidence cap, not a blocker.

Rejected alternatives:

- Keeping `EMITTER_UIDS` blank is rejected. The child-specific body, owner, and source route are now sufficiently documented.
- A no-code/proof comment is rejected. The target is a source-authored constructor body with meaningful source statements beyond compiler vtable stores.
- Routing directly to [UID:0000K5] as emitter is rejected. The narrow owner is the class [UID:00006I], which already routes through [UID:0000K5] using `[[CHILDREN]]`.
- Assigning to `Pane`/`PaneCore` is rejected. `Pane` supplies inherited construction/attachment/order dependencies; the body owns `IMEStatusPane` field initialization and literal setup.
- Assigning to [UID:0000R7] `g_pIMEPane`, [UID:00006H] `IMEPane`, or root [UID:0004CA] is rejected. MCP shows no `g_pIMEPane` xref in the constructor; the root singleton constructor at `0x004e7f20` is a separate method.
- Assigning to `MainUiLayerSlots` is rejected. `0x0069b37c` is an input layer context used by several UI panes; consumer use does not transfer ownership away from `IMEStatusPane`.
- Hand-authoring raw vtables or [UID:00025J] data is rejected. Class declarations and method bodies produce vtables/literals; [UID:00025J] already has a no-raw-table proof.
- Splitting or merging the target is rejected. MCP proves one modeled constructor body with clean padding and no nested function/data range.

## Ranked Ownership Analysis

### 1. [UID:00006I] `IMEStatusPane`

- Evidence for: class declaration already contains `IMEStatusPane();`; body writes `IMEStatusPane` vtables; body clears accepted field `statusText[256]`; body calls class helper `SetText`; sibling destructor and paint body emit through same class route.
- Evidence against: constructor entry has zero inbound xrefs; helper names are inferred, not original-symbol proof.
- Decision: best and narrowest owner. Zero inbound xrefs only cap confidence; they do not outweigh constructor body identity.

### 2. [UID:0000K5] `IMEPanes`

- Evidence for: file owns the IME pane source family and generated `NexusTK/input/IMEPanes.cpp`; [UID:00006I] routes through this file.
- Evidence against: direct owner would be too broad. `by-structure.md` says class methods should use the narrow class owner and route output through `EMITTER_UIDS`, not bypass the class to the file.
- Decision: source-file route/emitter chain destination, not direct canonical owner.

### 3. [UID:000189] `IMEPaneFamily`

- Evidence for: aggregate contains the source-order cluster and `[[CHILDREN]]` insertion point.
- Evidence against: aggregate explicitly rejects broad bodies; exact child pages own method bodies.
- Decision: support/source-order container only.

### 4. `Pane` / `PaneCore`

- Evidence for: body calls base constructor and inherited layer/order helpers.
- Evidence against: those are dependencies; this body initializes `IMEStatusPane` state and literal.
- Decision: rejected as owner; cite helper roles as support.

### 5. `MainUiLayerSlots`, `g_pIMEPane`, root `IMEPane`, or read-only data

- Evidence for: constructor consumes `0x0069b37c`, writes class vtables, and uses `Closed`.
- Evidence against: consumer/dependency xrefs are not ownership; constructor has no `g_pIMEPane` ref; vtables/literals are generated/source-declared support.
- Decision: rejected as direct owner.

## Source Placement

Recommended placement is [UID:00006I] `IMEStatusPane` method body under [UID:0000K5] `NexusTK/input/IMEPanes.cpp`. The constructor should sit after the [UID:00006I] class declaration and near sibling `IMEStatusPane` methods in generated output. Existing class/file/aggregate docs already establish this family source order: `SetText`, constructor, ordinary destructor, mode-change handler, paint handler.

No new source file or header is recommended. No source tree path change is recommended. No supervisor-owned manual tracker text is needed; validator-owned generated reports should refresh through scoped validation after callback.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x004e71c0-0x004e728a`, one modeled function, size `0xca`.
- Predecessor: [UID:0004BW] `SetText` ends at `0x004e71bc`; four `0xcc` bytes pad into constructor start.
- Successor: [UID:0004BY] ordinary destructor starts at `0x004e7290`; six `0xcc` bytes pad from constructor end to successor start.
- No child split or merge is required. The function contains only constructor statements plus compiler lowering. The vtable writes are not separate data/code children.
- Reclassification: remain `RECONSTRUCTABLE:TRUE`; change only score/emitter/formal C++.

## Negative Evidence Summary

- Zero inbound xrefs to `0x004e71c0` were checked and preserved as a caveat. This does not make the constructor dead/no-code because class lifecycle methods can be retained and referenced indirectly through compiler/runtime construction paths not captured as direct xrefs, and the generated class currently declares but lacks the constructor definition.
- `g_pIMEPane` was checked and rejected as a dependency for this target. The constructor does not read/write `0x0069b458`; root singleton publication belongs to [UID:0004CA] `IMEPane::IMEPane()`.
- `0x0069b37c` xrefs were checked and treated as layer-slot support. Several pane constructors use the same layer context; this is not owner proof for `MainUiLayerSlots`.
- The read-only vtable/string island was checked and kept source-declared/generated-binary. The constructor should use a class declaration and `L"Closed"`, not raw vtable assignments or raw string-table declarations.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Recommended code for supervisor-approved insertion into [UID:0004BX] formal `RECONSTRUCTION_CPP CODE`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMEStatusPane::IMEStatusPane()
    : Pane(0)
{
    RectBounds attachBounds;

    memset(statusText, 0, sizeof(statusText));
    InitRectBounds(&attachBounds, 0, 0, 0, 0);
    SetText(L"Closed", 6);
    AddToLayer(&attachBounds, 0, 0, g_mainUiLayerSlots.fpsOverlayLayerContext);
    SetPaneOrder(0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact original behavior:

- `Pane(0)` matches `sub_544460(this, 0)`.
- `memset(statusText, 0, sizeof(statusText))` matches `_memset(this+0xf8, 0, 0x200)`.
- `InitRectBounds(&attachBounds, 0, 0, 0, 0)` matches the four-zero bounds initializer call.
- `SetText(L"Closed", 6)` matches the exact call, literal, and length. The explicit `6` preserves the observed counted call including the terminating UTF-16 nul behavior accepted by the callee docs.
- `AddToLayer(&attachBounds, 0, 0, g_mainUiLayerSlots.fpsOverlayLayerContext)` matches `sub_544C70(this, &bounds, 0, 0, unk_69B37C)` and avoids the stale `g_pIMEPane`/root wording.
- `SetPaneOrder(0, 0)` matches `sub_544D30(this, 0, 0)`.
- Vtable stores are omitted because they are compiler output from the constructor/class declaration.

Reason it matches plausible precompiled source shape:

- It is an ordinary late-1990s/early-2000s C++ constructor body with a base initializer, stack bounds object, member-buffer clear, class helper call, inherited layer attach, and order registration.
- It uses accepted project-local names already present in nearby docs/generated output: `RectBounds`, `InitRectBounds`, `SetText`, `AddToLayer`, `SetPaneOrder`, and `g_mainUiLayerSlots.fpsOverlayLayerContext`.
- It avoids decompiler labels, artificial `this+offset` expressions, vtable stores, and raw `unk_`/`sub_` names.

No third-party import directive is applicable.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md`

Apply these changes after supervisor validation:

- Metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00006I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006I`, blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal constructor C++ block above.
- Replace stale text saying formal C++ remains blank for a later child-specific pass with the resolved constructor-body evidence.
- Expand `Behavior` to include `Pane(0)`, compiler vtable installation evidence, `statusText[256]` zeroing, zero `RectBounds` initialization, `SetText(L"Closed", 6)`, layer attachment through `g_mainUiLayerSlots.fpsOverlayLayerContext`, and `SetPaneOrder(0, 0)`.
- Preserve exact MCP evidence: `sub_4E71C0` size `0xca`, no function at `0x004e728a`, four-byte predecessor padding and six-byte successor padding, zero inbound constructor xrefs, vtable xrefs, `Closed` literal xref, no direct `g_pIMEPane` xref, and `0x0069b37c` layer-slot xref.
- Preserve rejected alternatives: no direct [UID:0000K5] owner/emitter bypass, no `Pane`/`MainUiLayerSlots`/`g_pIMEPane`/read-only-data ownership, no hand-authored vtable stores, no no-code marker, no split/merge.
- Update score rationale to explain that the C++ blocker is resolved but confidence stays below final audit due to inferred original spellings for inherited helper names and zero direct constructor xrefs.
- Add a `Changes` entry for this B011 report if supervisor sends an implementation callback.

## Recommended Support Doc Changes

Mandatory support updates are intentionally light because the current support pages already carry most owner/source-route facts. If the supervisor accepts a callback, use current file state and avoid overwriting concurrent B007/B009/B010 changes.

- `by-class/IMEStatusPane.md` [UID:00006I]:
  - Optional concise sync: update the constructor method row or evidence notes to mention [UID:0004BX] `88/90`, formal C++ populated, zeroes `statusText[256]`, calls `SetText(L"Closed", 6)`, attaches via `g_mainUiLayerSlots.fpsOverlayLayerContext`, and preserves zero-inbound-xref caveat.
  - No class metadata change required; current `88/90`, class shell, `statusText[256]`, and `[[CHILDREN]]` route are already sufficient.
- `by-file/IMEPanes.md` [UID:0000K5]:
  - Optional concise sync: add/change note that [UID:0004BX] now emits formal `IMEStatusPane::IMEStatusPane()` through [UID:00006I] into `NexusTK/input/IMEPanes.cpp`.
  - No file score/metadata/path change required.
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` [UID:000189]:
  - Optional support row sync: update the `0x004e71c0-0x004e728a` row to mention [UID:0004BX] `88/90`, formal C++ populated, `statusText[256]` clear, `Closed` setup, explicit layer-slot attachment, and [UID:00006I] -> [UID:0000K5] route.
  - No aggregate score/metadata change required; many sibling child bodies remain pending and this aggregate remains a `[[CHILDREN]]` insertion container.
- Already-present support, no edit required unless supervisor explicitly wants cross-link updates:
  - [UID:00025J] `IMEPaneReadOnlyData` already records the vtable/string island and no-raw-table proof.
  - `by-global/MainUiLayerSlots.md` and [UID:0001PG] `MainUiLayerSlotsTail` already record `0x0069b37c` as a main UI layer slot used by IME pane constructors.
  - `Pane`/`PaneCore` docs already support `Pane::Pane`, `AddToLayer`, and `SetPaneOrder`/dispatcher ordering.
  - [UID:0004BW] `SetText` and [UID:0004BZ] mode-change docs already establish the class-local text helper route; B009 owns [UID:0004BW] details.
  - [UID:0004CA] root `IMEPane` constructor/g_pIMEPane docs already own singleton publication and should not be edited for this target.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `82` | `88` | Current MCP resolves the exact constructor body, range/padding, vtable evidence, field zeroing, literal setup, inherited helper roles, layer-slot dependency, no-direct-xref caveat, rejected alternatives, and first-draft formal C++. Keep below 90+ because `SetText` sibling body is still separately tracked and exact original helper/member spellings remain inferred. |
| `CONFIDENCE` | `88` | `90` | Direct MCP and support docs strongly agree on behavior and source route. Confidence remains capped by zero inbound constructor xrefs and stripped original helper names for `Pane(0)`, `InitRectBounds`, `AddToLayer`, and `SetPaneOrder`. |
| `CANONICAL_OWNER` | `00006I` | `00006I` | Correct narrow class owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Live NexusTK UI source code. |
| `EMITTER_UIDS` | blank | `00006I` | Emit through owning class shell into [UID:0000K5]. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | Existing class child scan/source order is sufficient. |

Score-improvement audit:

- C++ blocker: resolved with current MCP and exact formal insertion text.
- Owner/emitter blocker: resolved to [UID:00006I] -> [UID:0000K5].
- Helper-name blocker: resolved enough for first-draft C++; remaining exact original spellings are confidence caps only.
- Root attachment wording blocker: resolved by distinguishing `g_mainUiLayerSlots.fpsOverlayLayerContext` from `g_pIMEPane`.
- Range/split blocker: resolved; no split needed.
- Zero-inbound-xref blocker: documented as confidence caveat, not no-improvement/no-code proof, with exact negative evidence.

## Open Questions With Attempted Resolution

- Exact original enum/name for `Pane(0)`: current docs support base Pane construction with mode argument `0`, but no accepted enum label is proven for this constructor. Use `Pane(0)` in formal C++ rather than inventing a mode constant. This caps confidence only.
- Exact original helper spelling for `InitRectBounds`, `AddToLayer`, and `SetPaneOrder`: current Pane/RectBounds support and MCP behavior make these source-facing names safe enough for first draft. If a future unified Pane pass renames these helpers project-wide, only spelling should change, not behavior or ownership.
- Whether `IMEPane::HandleIMEMessage` constructs status panes directly: not needed to emit this target. Current `xrefs_to 0x004e71c0` reports zero inbound constructor xrefs, and vtable xrefs do not show a later dispatcher reference. Do not use uncertain root-dispatch wording in this target.

No in-scope blocker remains. The remaining uncertainties are documented confidence caps, not implementation blockers.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

None. This report recommends by-* source-doc edits and scoped validators only. Auto-generated tracker/coverage files should be refreshed by validator/executed-report workflows, not manually edited by B011.

## Validator Results

Report-only pass: no validators were run and no leases were taken.

Implementation callback validators from `source-3/project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md --apply --wait-generated --queue-timeout 240`
  - Exit code: `0`; `command_id: 000000003211`; `command_timestamp: 2026-07-01T03:49:04-04:00`; `ok: 1`; `generated_refresh: completed`.
  - Target-specific updates: completion `88`, confidence `90`, registry emitter `00006I`, code block registered, UID links normalized.
  - Validator-owned side effects: `validator.ini` registry rebuild, generated C++ metadata refresh, projected stats update, research tracker update, by-memory auto coverage update, and autogen backups.
- `python .\tools\validator.py --mode file --file by-class/IMEStatusPane.md --apply --wait-generated --queue-timeout 240`
  - Exit code: `0`; `command_id: 000000003212`; `command_timestamp: 2026-07-01T03:49:21-04:00`; `ok: 1`; `generated_refresh: completed`.
  - Target-specific updates: reference index add for [UID:0004BX].
  - Validator-owned side effects: `validator.ini` registry rebuild, generated metadata refresh, projected stats update, and autogen backups.
- `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240`
  - Exit code: `0`; `command_id: 000000003223`; `command_timestamp: 2026-07-01T03:53:56-04:00`; `ok: 1`; `generated_refresh: completed`.
  - Target-specific updates: reference index add for [UID:0004BX].
  - Validator-owned side effects: `validator.ini` registry rebuild, generated metadata refresh, projected stats update, and autogen backups.
- `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --wait-generated --queue-timeout 240`
  - Exit code: `0`; `command_id: 000000003224`; `command_timestamp: 2026-07-01T03:54:15-04:00`; `ok: 1`; `generated_refresh: completed`.
  - Validator-owned side effects: `validator.ini` registry rebuild, generated metadata refresh, projected stats update, and autogen backups.

Generated freshness after callback:

- `auto-generated/NexusTK/input/IMEPanes.cpp` header is `validator-command-id: 000000003224`, `validator-refreshed-at: 2026-07-01T03:54:15-04:00`, equal to the final relevant validator command metadata.
- Generated output contains `// UID:0004BX | by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md | Completion:88 | Confidence:90` followed by `IMEStatusPane::IMEStatusPane()` with the accepted body.
- No [UID:0004BX] empty-emitter marker was found by `rg -n "UID:0004BX|IMEStatusPane::IMEStatusPane|empty|EMPTY|NO CODE|emitter" auto-generated/NexusTK/input/IMEPanes.cpp`.

Expected implementation callback validators from `source-3/project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md --apply --wait-generated --queue-timeout 240`
- If class support is edited: `python .\tools\validator.py --mode file --file by-class/IMEStatusPane.md --apply --wait-generated --queue-timeout 240`
- If file support is edited or final generated freshness matters: `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240`
- If aggregate support is edited: `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --wait-generated --queue-timeout 240`

Generated freshness expectation after callback:

- Inspect `auto-generated/NexusTK/input/IMEPanes.cpp` after the final `--wait-generated` validator.
- Confirm the generated header `validator-command-id`/`validator-refreshed-at` is equal/newer than the final relevant validator command.
- Confirm a `// UID:0004BX | by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md` marker appears and contains `IMEStatusPane::IMEStatusPane()`.
- Confirm no [UID:0004BX] empty-emitter marker remains.
- Confirm constructor output appears through the [UID:00006I] class route and does not duplicate vtable stores, raw `Closed` table data, `g_pIMEPane` singleton publication, or layer-slot declarations.

## Changed Files

Implementation callback changed:

- `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md`
- `by-class/IMEStatusPane.md`
- `by-file/IMEPanes.md`
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
- `tools/leaser/Agents/Agent-B011/research/0004BX-IMEStatusPaneConstructor-source-quality.md`

Validator-owned generated/tool-state side effects occurred through scoped validators only: `auto-generated/NexusTK/input/IMEPanes.cpp`, generated metadata/report refreshes, projected stats, research tracker/by-memory auto coverage on the target run, autogen backups, and `validator.ini` registry rebuilds. B011 did not manually edit generated files, generated reports, manual coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, or lock files.

Leases:

- First batch: B011 leased `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md` and `by-class/IMEStatusPane.md` at `2026-07-01T07:47:38Z`; released both after validators.
- Second batch: B011 leased `by-file/IMEPanes.md` and `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` after B007's lease expired; released both after validators.
- Final lease check: `current_leases.md` reports `No active leases.`

Preserved older B011 research files unchanged: `00016I-GrafPortDrawGlyph-source-quality.md` and `0001ZS-JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter-source-quality.md`.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: current assignment `B011-implement-0004BX-IMEStatusPaneConstructor-20260630` is an implementation callback for the accepted report.
- [x] Target metadata: update [UID:0004BX] `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md` from `82/88`, blank emitter to `88/90`, `EMITTER_UIDS:00006I`, owner unchanged `00006I`, reconstructable unchanged `TRUE`, optional position blank. Proof: target metadata updated; validator `000000003211` applied completion/confidence and registry emitter.
- [x] Target formal C++: insert the exact formal `IMEStatusPane::IMEStatusPane()` block from this report into the target `RECONSTRUCTION_CPP CODE` block. Proof: target formal block populated; generated `IMEPanes.cpp` lines 446-457 contain the [UID:0004BX] marker and accepted constructor body.
- [x] Target behavior/evidence: preserve current MCP ids `10`-`13` and `16`-`27`, including active session health, schema-current call shape, exact function size `0xca`, no function at `0x004e728a`, padding, zero inbound constructor xrefs, vtable-store evidence, `statusText[256]` clear, `Closed` literal, zero bounds, layer-slot attach, and order registration. Proof: target `Evidence` carries the applied MCP facts and negative checks.
- [x] Target source-shape notes: state that vtable stores are compiler output and should not be emitted as handwritten C++; source body uses base initializer, `memset`, `InitRectBounds`, `SetText`, `AddToLayer`, and `SetPaneOrder`. Proof: target `Reconstruction Notes` and formal C++ carry this.
- [x] Target dependency correction: replace or qualify stale "root attachment" wording with `g_mainUiLayerSlots.fpsOverlayLayerContext` layer attachment and preserve that there is no direct `g_pIMEPane` xref. Proof: target `Behavior`/`Evidence`/`Reconstruction Notes` and support notes now use layer-slot attachment and no direct `g_pIMEPane` xref.
- [x] Target score rationale: replace stale "child-specific C++ later" rationale with the resolved `88/90` score-blocker rationale and reason not higher/lower. Proof: target `Score Rationale` updated.
- [x] Target rejected alternatives: preserve no direct [UID:0000K5] emitter bypass, no no-code marker, no `Pane`/`MainUiLayerSlots`/`g_pIMEPane`/read-only-data ownership, no hand-authored vtables/literals, and no split/merge. Proof: target `Reconstruction Notes` records rejected alternatives.
- [x] `by-class/IMEStatusPane.md`: optional support sync if callback/supervisor wants it: update constructor method row/evidence note with [UID:0004BX] `88/90`, formal C++ populated, `statusText[256]` clear, `SetText(L"Closed", 6)`, layer-slot attachment, and zero-xref caveat; no class metadata change required. Proof: class method row, evidence note, and changes entry updated; validator `000000003212` ok.
- [x] `by-file/IMEPanes.md`: optional support sync if callback/supervisor wants it: add concise change note that [UID:0004BX] now emits formal `IMEStatusPane::IMEStatusPane()` through [UID:00006I] into `NexusTK/input/IMEPanes.cpp`; no file metadata change. Proof: file proposed-contents row, evidence note, and changes entry updated; validator `000000003223` ok.
- [x] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`: optional support row sync if callback/supervisor wants it: update the [UID:0004BX] covered range row with `88/90`, formal C++ populated, zeroing/Closed/layer-slot behavior, and route [UID:00006I] -> [UID:0000K5]; no aggregate metadata change. Proof: aggregate covered-range row, evidence note, split/source-placement row, and changes entry updated; validator `000000003224` ok.
- [x] Already-present support docs: leave [UID:00025J], MainUiLayerSlots docs, Pane/PaneCore docs, [UID:0004BW], [UID:0004BZ], [UID:0004CA], and `g_pIMEPane` docs unchanged unless callback/supervisor explicitly requests cross-link wording; record as already-present or excluded-with-reason during callback. Proof: left unchanged; target/support notes cite them as dependencies/already-present and reject ownership edits.
- [x] Claim And Incorporation Ledger: update every row from `proposed` to `applied`, `already-present`, `excluded-with-reason`, or `blocked` with proof during callback. Proof: ledger rows C01-C13 updated above; no blocked row remains.
- [x] Validators: run scoped validators listed above for each changed by-* file, using `--wait-generated` on the target/final file validation where generated `IMEPanes.cpp` freshness matters. Proof: validators `000000003211`, `000000003212`, `000000003223`, and `000000003224` all exited `0` with `ok: 1` and `generated_refresh: completed`.
- [x] Generated freshness: inspect `auto-generated/NexusTK/input/IMEPanes.cpp` after validator completion for current header, [UID:0004BX] marker/body, and no [UID:0004BX] empty-emitter marker. Proof: header `validator-command-id: 000000003224`, `validator-refreshed-at: 2026-07-01T03:54:15-04:00`; [UID:0004BX] marker/body present; no empty marker found.
- [x] No manual generated/coverage/validator-state edits: confirm implementation changed only accepted by-* docs and this report, with validator-owned side effects only. Proof: B011 edited only four by-* docs and this report; validator-owned side effects are listed under `Changed Files`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` accepted report and implementation callback.
- [x] All accepted target/support doc details incorporated at report-level detail or recorded as already-present/excluded-with-reason. Proof: target/class/file/aggregate changed; already-present support docs left unchanged with reason in checklist/ledger.
- [x] Claim And Incorporation Ledger updated with callback proof for every accepted claim. Proof: rows C01-C13 updated.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with concrete reason. Proof: target metadata/formal C++ applied; support metadata unchanged by design.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve compiler-vtable evidence, no direct `g_pIMEPane`, zero-xref caveat, no direct-file/dependency-owner/no-code/split alternatives.
- [x] Scoped validators run and command id/timestamp/exit/ok/generated-refresh state recorded. Proof: validator result block above.
- [x] Leases, if any, taken only for immediate by-* edit/validator batches and released immediately. Proof: two short B011 lease batches listed above; final current lease report says no active leases.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: no unapplied accepted items and no blockers remain.

## Blockers

No implementation blocker remains for [UID:0004BX]. MCP was available and healthy, the exact constructor body is modeled, the class/file route is current, no split/new UID is needed, and the formal constructor C++ is implementation-ready pending supervisor validation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0004BX-IMEStatusPaneConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0004BX-IMEStatusPaneConstructor-source-quality.md","timestamp":"2026-07-01T03:58:37","uid":"0004BX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
