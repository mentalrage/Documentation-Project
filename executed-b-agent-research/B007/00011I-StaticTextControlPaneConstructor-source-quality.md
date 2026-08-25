** TARGET-REPORT-UID:00011I **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 00011I StaticTextControlPaneConstructor Source-Quality Research


## Finalized Report / Current Recommendation

Implementation callback has been applied for [UID:00011I][by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md]. The target is now a source-ready emitting constructor through [UID:0000E3][by-class/StaticTextControlPane.md] / [UID:0000O8][by-file/StaticTextControlPane.md]. The owner/emitter route remains unchanged and the formal constructor C++ block is now present in the target page.

Applied target state: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000E3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E3`, blank `EMITTER_POSITION_OPTIONAL`, and formal source body inserted. Support docs now describe UID00011I as source-ready/emitting and preserve confidence caps for exact public parameter names, the packed `+0xfe/+0xff` control-state write, and inferred text-pane helper names.

## Supporting Research

This report supersedes an earlier paused checkpoint in this same file. The pause was supervisor cap-related; it was not an evidence contradiction. After resume, B007 rechecked the active MCP session read-only and completed the evidence pass against current IDA state.

Current read-only MCP availability used for final evidence:

- `initialize` and `tools/list` succeeded through `http://127.0.0.1:13337/mcp`.
- `idb_list` returned one active NexusTK session, `73c77998`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; the session was active, not analyzing, worker PID `12416`.
- `server_health(database='73c77998')` returned `status:ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

Local documentation reviewed:

- Target page [by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md].
- Class/file pages [by-class/StaticTextControlPane.md] and [by-file/StaticTextControlPane.md].
- Supporting owner and helper pages for [ControlPane](by-class/ControlPane.md), [TextEditControlPane](by-class/TextEditControlPane.md), [TextEditPane](by-class/TextEditPane.md), [RectBounds](by-type/by-struct/RectBoundsLayout.md), [Pane::SetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md), [IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md), [RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md), [TextEditPaneConstructor](by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md), and [TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md).
- Generated output [auto-generated/NexusTK/ui/controls/StaticTextControlPane.cpp]. Historical pre-callback header `validator-command-id: 000000006120`, `validator-refreshed-at: 2026-07-04T05:14:28-04:00` showed UID00011I as an Empty Emitter Marker. Post-callback generated header now records `validator-command-id: 000000006174`, `validator-refreshed-at: 2026-07-04T06:04:29-04:00`, and contains UID00011I constructor output.
- Archived B014 ClanStatusPane constructor research for the accepted descriptive behavior of `0x0058ea80` as the TextEditPane editable/active-state helper.

## Target

- UID: `00011I`.
- Target path: `by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md`.
- Current implemented state: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000E3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E3`, blank optional emitter position, formal constructor C++ block populated.
- Function range: `0x00499030-0x004991ec`; IDA function `sub_499030`, size `0x1bc`.
- Source owner: `StaticTextControlPane`, not the shared TextEditControlPane helper band, not TextEditPane, not base ControlPane, and not a no-owner raw helper.

## Current Target State

The target clears owner and emitter routing: `0000E3` is the canonical class owner and emitter. The target formal C++ block is populated and generated output now contains UID00011I constructor output rather than the previous Empty Emitter Marker.

Remaining limitations are confidence caps only: exact public parameter names, exact field spellings at `+0x108` and `+0x10c`, source-facing method names for TextEditPane child setup, and the packed final word store over `+0xfe/+0xff`. The MCP and support-doc evidence resolves the behavior enough for first-draft formal source with those caps documented.

## Executive Recommendation

Applied a source-ready constructor body for `StaticTextControlPane::StaticTextControlPane`. The body is normal source-like C++, not decompiler-shaped: it calls the `ControlPane` base constructor, allocates the embedded `TextEditPane`, initializes it with the computed dimensions/style/input-mode values, normalizes the child bounds, disables editing/activation, seeds initial text when non-empty, and sets the final inherited control state.

Do not create a standalone raw `sub_499030` helper, do not move ownership to TextEditPane or TextEditControlPane, and do not leave the target blank solely because exact original parameter names remain inferred.

## Supervisor Active Recheck

B007 used the active supervisor-provided MCP session read-only only. No `idb_open`, `idb_close`, or MCP/IDA process-management command was run. During the later authorized implementation callback, B007 edited only the accepted target/support by-* docs and this report, ran scoped file validators, and released the leases. No `execute_report`, lifecycle/archive/registry command, manual generated edit, coverage edit, validator-state edit, supervisor-ledger edit, or report move was run by B007.

The previous paused checkpoint has been historicalized by replacement with this final report. The report lifecycle is supervisor-owned outside this artifact.

## Inference Research Guidance Check

This target is a normal constructor with a large direct-caller fan-in and an existing owner/emitter route. Under the project source-quality rules, the correct resolution is not to preserve IDA names or leave the target blank because some source spellings are inferred. The report therefore uses accepted project names where they exist (`ControlPane`, `RectBounds`, `OffsetRect`, `Pane::SetMode`, `IsLegacyAssetMode`, `TextEditPane`, `m_textEditPane`) and conservative descriptive names where exact original names remain unproven.

The formal body intentionally omits compiler artifacts: vtable stores, EH state locals, security-cookie check, allocator null branch shape, raw `this` return, and direct stack-frame temporaries. It preserves every user-visible side effect in source form.

## Heuristic / Inference Reanalysis And Validation

The constructor uses a stable, high-fan-in UI control construction pattern. Caller samples push the same seven source parameters in consistent order, then call `sub_499030` on a freshly allocated `0x114`-byte StaticTextControlPane object:

- `text` pointer.
- Style flag selecting TextEditPane style flags `4` or `6`.
- Two integer color/style values.
- `RectBounds *bounds`.
- Boolean selecting content width `1000` instead of the actual width.
- Final input-mode byte passed through to TextEditPane.

The IDA decompile and bounded disassembly agree on the internal state sequence: `ControlPane(5, bounds)`, clear `+0x108/+0x109`, set `+0xff`, compute width and height from inherited bounds, allocate `372` bytes, call `TextEditPane` constructor `0x0058dce0`, store the child pointer at `+0x10c`, offset a child-local rect to origin, call the child bounds virtual slot, set child mode `1`, call the TextEditPane editable/active-state helper with `false, false`, optionally seed non-empty text through `0x0058e270`, store final control state at `+0xfe/+0xff`, and call `Pane::SetMode(4)` on the wrapper.

## Evidence Standards Used

- Current IDA MCP evidence was required and satisfied by active session `73c77998`.
- MCP calls were narrow and schema-current: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `callees`, `xrefs_to`, and `entity_query` over exact addresses/ranges.
- Local by-* docs were used as accepted naming and ownership evidence only where they already carry source-facing names or field roles.
- Generated output was read for current marker state only; generated files were not edited.
- Inferences are documented as confidence caps when exact original names or declarations are not directly proven.

## Evidence Checked

- Function and boundary lookup for `0x00498dd0`, `0x00498f50`, `0x00499021`, `0x00499030`, `0x004991ec`, and `0x004991f0`.
- Exact byte checks at the predecessor padding, target prologue, target epilogue, and successor boundary.
- Decompile and disassembly for `0x00499030`.
- Callee inventory for constructor dependencies.
- Vtable-name query around `0x006181a4`, `0x0061820c`, and `0x0061823c`.
- Xref inventory for `0x00499030` and the StaticTextControlPane vtable entries.
- Helper checks for `0x0058e270`, `0x0058fc30`, and `0x0058ea80`.
- Caller-site samples at `0x472ca0`, `0x4753e0`, `0x59bc90`, `0x552110`, and `0x489600`.
- StaticTextControlPane, TextEditControlPane, TextEditPane, ControlPane, RectBounds, Pane::SetMode, IsLegacyAssetMode, and RectGeometry helper docs.
- Historical and post-callback generated `StaticTextControlPane.cpp` states: UID00011I was an Empty Emitter Marker at command `000000006120`; after scoped validation it is constructor output at command `000000006174`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| C-00011I-01 | UID00011I is an IDA function at `0x00499030-0x004991ec`, size `0x1bc`, separated from predecessor helper code by padding and from successor by padding/successor prologue. | 99 | MCP `lookup_funcs`, `get_bytes`, and `disasm`: predecessor `0x00499021` not a function; target `sub_499030`; successor `sub_4991F0`; predecessor padding `cc` x15; target epilogue `c2 1c 00`; four `cc` before successor prologue. | Target `IDA MCP Boundary And Xref Audit`; class/file evidence notes. | incorporate | applied: target records `73c77998` range/size and boundary bytes; class/file support notes carry the current range/size/padding summary. |
| C-00011I-02 | StaticTextControlPane remains the correct owner and emitter route. | 97 | Current target metadata uses `CANONICAL_OWNER:0000E3` and `EMITTER_UIDS:0000E3`; MCP vtable writes target `??_7StaticTextControlPane@@6B@`, `_0`, and `_1`; vtable xrefs are the constructor writes. | Target metadata; class/file rows. | incorporate | applied: target owner/emitter preserved; class/file rows state UID00011I emits through StaticTextControlPane; reparenting alternatives remain rejected. |
| C-00011I-03 | The constructor calls `ControlPane(5, bounds)` and then finalizes inherited control state with final control type/state word `6` and mode `4`. | 93 | MCP decompile/disasm: `push 5` before `sub_4949E0`; final `mov word ptr [esi+0FEh], 6`; final `sub_5446B0(this,4)`; ControlPane constructor report supplies `ControlPane(unsigned char, const RectBounds *)`; PaneSetMode doc supplies `Pane::SetMode`. | Target formal C++ block and constructor evidence. | incorporate | applied: formal C++ uses `ControlPane(5, bounds)`, final `m_controlType = 6`, `m_controlFlags = 0`, and `SetMode(4)` with packed-state caveat. |
| C-00011I-04 | `+0x10c` is the embedded `TextEditPane *` child pointer and can be represented as `m_textEditPane` with inferred StaticText field spelling. | 91 | MCP store `mov [esi+10Ch], eax` after `sub_58DCE0`; all later child calls load `[esi+10Ch]`; TextEditControlPane docs accept the same `+0x10c` role/name. | Target formal C++ block, touched state, class notes. | incorporate | applied: formal C++ uses `m_textEditPane`; target/class notes cap exact StaticText spelling. |
| C-00011I-05 | The constructor computes child dimensions from inherited bounds and uses `1000` as a fixed content width when the width-policy byte is true. | 94 | MCP disasm: width from `[esi+4c]-[esi+44]`, height from `[esi+50]-[esi+48]`, `cmovnz` selecting `0x3e8`, then `sub_58DCE0` call. Caller samples confirm the sixth parameter is a boolean-like byte. | Target formal C++ block and constructor evidence. | incorporate | applied: formal C++ defines `kStaticTextWideContentWidth = 1000` and computes `contentWidth` from `useWideContentWidth`. |
| C-00011I-06 | The TextEditPane constructor argument order is width, height, content width, height, two color/style ints, no scrollbars, style flags `4/6`, legacy-mode helper, read-only/locked byte `1`, and input-mode byte. | 90 | MCP disasm push sequence before `sub_58DCE0`; TextEditPaneConstructor page documents the 12-argument role set; caller samples vary the two ints and pass the final bytes consistently. | Target formal C++ block; target/class/file evidence notes. | incorporate | applied: formal C++ passes the documented argument order; target/class/file notes preserve exact-name caps. |
| C-00011I-07 | `0x004b60b0` is the accepted `IsLegacyAssetMode()` helper and belongs as an ordinary source call in the TextEditPane constructor argument list. | 95 | IsLegacyAssetMode page documents helper returns `byte_66DA97 != 1`; MCP disasm calls `sub_4B60B0` immediately before pushing the mode/default-format argument. | Target formal C++ block. | incorporate | applied: formal C++ calls `IsLegacyAssetMode()`; support helper page was already present, so no edit was needed. |
| C-00011I-08 | The child bounds are a copy of input bounds offset to origin through `OffsetRect`, then passed to a child bounds setter slot with `false`. | 90 | MCP decompile copies `*bounds` into local `__m128i`, calls `sub_4B7E10(&local, -left, -top)`, then invokes child vtable slot `+0x2c` with `&local` and `0`; RectGeometry docs accept `OffsetRect`. | Target formal C++ block; target caveats. | incorporate | applied: formal C++ uses `RectBounds childBounds`, `OffsetRect`, and `SetBounds(&childBounds, false)` with setter-name cap. |
| C-00011I-09 | The child is set to mode `1`, editable/active flags `false,false`, and optional initial text only when text is non-null and non-empty. | 92 | MCP decompile/disasm: `sub_5446B0(child,1)`, `sub_58EA80(child,0,0)`, text null/first-word checks, and `sub_58E270(child,text,0)`. Helper recheck: `sub_58E270` calls `sub_58FC30(text,wcslen(text),0,0)`; `sub_58EA80` toggles edit/active bits and selection refresh. | Target formal C++ block; target/class notes. | incorporate | applied: formal C++ emits `SetMode(1)`, `SetTextEditMode(false,false)`, and guarded `SetText(text,0)` with exact overload cap. |
| C-00011I-10 | The pre-callback generated output was empty only because the target formal block was blank; after callback, UID00011I generates constructor output. | 95 | Historical `StaticTextControlPane.cpp` at command `000000006120` had UID00011I Empty Emitter Marker; final generated header at `000000006174` contains UID00011I constructor output. | Target generated-output notes; by-file source-output note; Validator Results. | incorporate | applied: target/file notes historicalize the old marker; generated output is fresh at `000000006174` and contains the constructor body. |
| C-00011I-11 | Rejected alternatives are TextEditControlPane/shared-helper ownership, TextEditPane ownership, ControlPane ownership, no-owner/non-emitting, raw `sub_499030` naming, and broad merge with adjacent shared helper band. | 96 | Vtable writes and class/file docs route to StaticTextControlPane; predecessor UID0003LQ is documented as shared TextEditControlPane inherited helper band; target has 104 direct constructor xrefs and source owner already assigned. | Target caveats; class/file support. | incorporate | applied: target/class/file preserve rejected alternatives and keep UID0003LQ split. |
| C-00011I-12 | Metadata moved from `86/88` to `88/91`, not higher, because behavior/source route are source-ready but exact parameter/field/helper spellings remain inferred. | 90 | Evidence resolves range, owner, body behavior, caller parameter order, generated marker cause, and formal source body; unresolved names/caps remain documented. | Target metadata and score rationale. | incorporate | applied: target metadata is `COMPLETION:88`, `CONFIDENCE:91`; score rationale records confidence caps. |

## Positive Evidence Summary

MCP session `73c77998` confirms UID00011I is a real constructor function with exact boundaries and heavy caller use. The body installs StaticTextControlPane vtables, uses the accepted ControlPane base constructor, constructs an embedded TextEditPane child, and performs wrapper/child state setup. Direct vtable xrefs and current by-* ownership already align with StaticTextControlPane. The former generated Empty Emitter Marker was therefore a source-quality artifact, not a no-code proof; post-callback generated output contains the constructor body.

The direct caller fan-in is especially strong: `xrefs_to 0x00499030` returned 104 xrefs with `more:false`. Sample callers all allocate the StaticTextControlPane object and pass seven constructor arguments in a stable order, supporting a normal public constructor signature rather than a local raw helper.

## IDA MCP Facts

- `lookup_funcs`:
  - `0x00498dd0` -> `sub_498DD0`, size `0x3e`.
  - `0x00498f50` -> `sub_498F50`, size `0xd1`.
  - `0x00499021` -> not a function.
  - `0x00499030` -> `sub_499030`, size `0x1bc`.
  - `0x004991ec` -> not a function.
  - `0x004991f0` -> `sub_4991F0`, size `0xb8`.
- Bytes:
  - `0x00499021` length 15: `cc` x15.
  - `0x00499030` begins `55 8b ec 6a ff 68 e2 d0 5f 00 64 a1 00 00 00 00 50 83 ec 38 a1 24 2f 67 00 33 c5 89 45 f0 56 57`.
  - The target epilogue ends with `8b e5 5d c2 1c 00`, followed by four `cc` bytes and successor prologue `55 8b ec 6a`.
- `decompile 0x00499030` shows `sub_4949E0(this,5,bounds)`, clear `*(WORD *)(this+264)`, set `*(BYTE *)(this+255)`, install StaticText vtables, allocate `372`, call `sub_58DCE0`, store `this+268`, set child bounds/mode/edit state/text, write `*(WORD *)(this+254)=6`, call `sub_5446B0(this,4)`, return `this`.
- `disasm 0x00499030` returned 153 total instructions and confirms the exact stack argument use, push order, constants, child pointer store, and final `retn 1Ch`.
- `callees 0x00499030`: `sub_4949E0`, `sub_4F4AA0`, `sub_4B60B0`, `sub_58DCE0`, `sub_4B7E10`, `sub_5446B0`, `sub_58EA80`, `sub_58E270`, and `@__security_check_cookie@4`.
- `entity_query names` around the vtable range returned `??_7StaticTextControlPane@@6B@` at `0x006181a4`, `_0` at `0x0061820c`, and `_1` at `0x0061823c`.
- `xrefs_to` those vtables each returned a constructor write inside `sub_499030`: `0x4990be`, `0x4990c4`, and `0x4990ce`.
- `lookup_funcs/decompile 0x0058e270`: helper size `0x32`; thin wrapper that calls `sub_58FC30(this,text,wcslen(text),0,0)`.
- `lookup_funcs/decompile 0x0058fc30`: helper size `0x263`; sanitizes/inserts wide text, updates selection/end positions, and refreshes layout.
- `lookup_funcs/decompile 0x0058ea80`: helper size `0xab`; toggles TextEditPane editable/active flags and selection state, supporting the descriptive `SetTextEditMode(false,false)` call.

## Function / Child Inventory

| Address/range | Function/role | Current source interpretation |
|---|---|---|
| `0x00499030-0x004991ec` | `sub_499030` | StaticTextControlPane constructor; source-ready target UID00011I. |
| `0x00498dd0-0x00499021` | `sub_498DD0`, `sub_498F50` shared helper band | TextEditControlPane inherited/shared state and border helpers, not part of this constructor. |
| `0x004991f0-0x004992a8` | `sub_4991F0` | Successor StaticTextControlPane method outside UID00011I. |
| `0x004949e0` | `sub_4949E0` | Accepted ControlPane constructor dependency. |
| `0x0058dce0` | `sub_58DCE0` | TextEditPane constructor dependency. |
| `0x004b60b0` | `sub_4B60B0` | Accepted `IsLegacyAssetMode()` helper. |
| `0x004b7e10` | `sub_4B7E10` | Accepted `OffsetRect` helper. |
| `0x005446b0` | `sub_5446B0` | Accepted `Pane::SetMode(unsigned char)`. |
| `0x0058ea80` | `sub_58EA80` | TextEditPane edit/active-state helper; use descriptive `SetTextEditMode`. |
| `0x0058e270` | `sub_58E270` | TextEditPane initial text wrapper over the deeper text insertion helper. |

## Direct Xref / Caller Inventory

`xrefs_to 0x00499030` returned exactly 104 xrefs with `more:false`. Top caller groups included `0x59bc90` with 11 calls, `0x4753e0` with 8 calls, `0x47b220` with 6 calls, `0x552110` with 6 calls, `0x489600` with 5 calls, and `0x4ac8a0` with 5 calls.

Sampled caller sites support the same source signature:

- `0x472ca0` at `0x473253`: after allocating `0x114`, pushes final bytes `0,0`, bounds local, integer values `0` and `0x25`, flag `1`, and a text pointer at `edi+0x276`.
- `0x4753e0` at `0x475967`: same shape with a local text buffer, `0x25/0`, style flag `1`, final bytes `0,0`.
- `0x59bc90` at `0x59bec4`: same shape with a computed text pointer and `0x25/0`.
- `0x552110` at `0x5526b3`: same shape with text local and integer values `0x80/0x8f`.
- `0x489600` at `0x489a35`, `0x489a99`, `0x489afd`, and `0x489b64`: repeated local StaticText construction with text locals, style flag `1`, integer values `0x80/0`, same bounds, final bytes `0,0`.

## Documentation Evidence And IDA Status

The target page already documents the major constructor sequence and assigns the target to StaticTextControlPane. The class and file docs also route UID00011I to the StaticTextControlPane source family but still frame final source as blocked by field names, vtable slot names, and parent/class gate reconciliation. Current MCP evidence resolves the class route and enough helper roles for first-draft source; the remaining unknowns are confidence caps, not blockers.

ControlPane docs supply accepted inherited field names and the base constructor shape. TextEditControlPane and TextEditPane docs supply the accepted embedded TextEditPane role and constructor parameter family. RectBounds and RectGeometry docs supply the source-facing rect type and `OffsetRect`. PaneSetMode docs supply the source-facing `SetMode` call. B014 precedent supports descriptive `SetTextEditMode` for `0x0058ea80`.

## Ranked Ownership Analysis

1. `StaticTextControlPane` / UID0000E3: accepted. The constructor installs StaticTextControlPane vtables, writes StaticText wrapper state, constructs its embedded TextEditPane child, and has direct constructor caller fan-in. Current target metadata and by-class/by-file docs already point here.
2. `StaticTextControlPane.cpp` / UID0000O8 file route: accepted source placement. The file page lists StaticTextControlPane and UID00011I, and callback edits replaced the generated-output note that previously left UID00011I as an Empty Emitter Marker.
3. `TextEditPane`: rejected as owner. It is the allocated child object and callee family, not the object whose vtables are installed or whose constructor callers allocate `0x114`.
4. `TextEditControlPane`: rejected as owner. It shares inherited helper fields and the `m_textEditPane` pattern, but the vtable writes and constructor start are StaticTextControlPane-specific. The predecessor shared helper band remains separate UID0003LQ.
5. `ControlPane`: rejected as owner. It is the base constructor and inherited state provider, not the derived constructor owner.
6. No-owner/non-emitting/raw helper: rejected. The target has a concrete function, 104 direct xrefs, a class owner, an emitter route, and source-like constructor behavior.

## Source Placement

Place the source body under `StaticTextControlPane` through the existing UID0000E3 emitter route and `NexusTK/ui/controls/StaticTextControlPane.cpp` file route. The constructor belongs beside the existing StaticTextControlPane class source, not in TextEditPane, TextEditControlPane, ControlPane, or a standalone raw helper module.

Support docs now describe UID00011I as source-ready and emitted through UID0000E3. The generated `StaticTextControlPane.cpp` Empty Emitter Marker disappeared after scoped validation/generation refresh because `EMITTER_UIDS` was already set and the formal block is no longer blank.

## Range / Split / Padding / Reclassification Analysis

No split correction is recommended. UID00011I starts at the real IDA function `0x00499030` and ends at the exclusive target end `0x004991ec`. The predecessor range `0x00498dd0-0x00499021` is a separate shared helper band, followed by 15 bytes of `cc` padding before the constructor. The successor starts at `0x004991f0` after the target epilogue and four `cc` bytes.

The current range is therefore exact and should stay as-is. Do not merge UID00011I backward into UID0003LQ and do not merge it forward into `sub_4991F0`.

## Negative Evidence Summary

No evidence supports leaving UID00011I blank after this pass. The unresolved items are name-quality caps, not no-code proof:

- Exact original public parameter names are not known, but caller order and roles are stable.
- Exact StaticText member spellings for `+0x108` and `+0x10c` are inferred. `m_textEditPane` is supported by the accepted TextEditControlPane pattern, but StaticText-specific original spelling remains unproven.
- The final `mov word ptr [this+0xfe],6` packs inherited control state over `m_controlType` and `m_controlFlags`; source should express the observable final state without pretending exact original spelling is proven.
- `SetBounds`, `SetTextEditMode`, and the two-argument `SetText` wrapper are source-facing descriptive names for known child behavior; exact original names remain open.
- The compiler artifacts in IDA output should not be emitted as source: vtable stores, EH locals, security cookie, allocator null branch, and raw return-this shape.

## IDA Rename / Type / Comment Recommendations

- `sub_499030`: document as `StaticTextControlPane::StaticTextControlPane`.
- `this+0x10c`: document as `m_textEditPane` with inferred StaticText spelling.
- `this+0x108/+0x109`: document as a packed static-text/text-state word; first-draft C++ uses `m_textStateFlags`.
- Constructor parameters: `text`, `useAlternateStyle`, `textColor`, `shadowColor`, `bounds`, `useWideContentWidth`, and `inputMode` are descriptive and should be kept confidence-capped.
- `sub_58EA80`: descriptive `TextEditPane::SetTextEditMode(bool editActive, bool selectAll)` or equivalent accepted project spelling.
- `sub_58E270`: descriptive `TextEditPane::SetText(const wchar_t *text, int flags)` wrapper over deeper insertion; exact overload name/signature confidence-capped.

## First-Draft C++ Recommendation

The accepted implementation inserted this exact formal block text into the target's formal `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
const int kStaticTextWideContentWidth = 1000;
const unsigned int kStaticTextPaneStyle = 4;
const unsigned int kStaticTextPaneAlternateStyle = 6;
}

StaticTextControlPane::StaticTextControlPane(const wchar_t *text,
                                             bool useAlternateStyle,
                                             int textColor,
                                             int shadowColor,
                                             const RectBounds *bounds,
                                             bool useWideContentWidth,
                                             bool inputMode)
    : ControlPane(5, bounds),
      m_textStateFlags(0),
      m_textEditPane(NULL)
{
    m_controlFlags = 1;

    const int width = m_bounds.right - m_bounds.left;
    const int height = m_bounds.bottom - m_bounds.top;
    const int contentWidth = useWideContentWidth ? kStaticTextWideContentWidth : width;
    const unsigned int paneStyle = useAlternateStyle ? kStaticTextPaneAlternateStyle : kStaticTextPaneStyle;

    m_textEditPane = new TextEditPane(width,
                                      height,
                                      contentWidth,
                                      height,
                                      textColor,
                                      shadowColor,
                                      false,
                                      false,
                                      paneStyle,
                                      IsLegacyAssetMode(),
                                      true,
                                      inputMode);

    RectBounds childBounds = *bounds;
    OffsetRect(&childBounds, -childBounds.left, -childBounds.top);

    m_textEditPane->SetBounds(&childBounds, false);
    m_textEditPane->SetMode(1);
    m_textEditPane->SetTextEditMode(false, false);

    if (text != NULL && text[0] != L'\0')
        m_textEditPane->SetText(text, 0);

    m_controlType = 6;
    m_controlFlags = 0;
    SetMode(4);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note: when editing the by-* target, replace the existing formal block contents with the body between the project header markers as required by the local file format; do not duplicate header marker lines if the target page already supplies them. The code above is the formal insertion text requested by the report template, not a standalone illustrative snippet.

## Final Recommendation

Final disposition: UID00011I is implemented as a source-ready emitting constructor under StaticTextControlPane. Target metadata is `COMPLETION:88`, `CONFIDENCE:91`, owner `0000E3`, reconstructable true, `EMITTER_UIDS:0000E3`, blank optional position, with the formal C++ constructor block inserted.

Parent assignment disposition: class owner [UID:0000E3][StaticTextControlPane] and file route [UID:0000O8][StaticTextControlPane.md] are preserved. Support docs now reflect that UID00011I has a constructor body and is no longer blocked solely by the generated Empty Emitter Marker.

No-owner/non-emitting disposition: rejected. The target has a real function, vtable-owner evidence, broad direct constructor xrefs, and an existing emitter route.

Future work outside the UID00011I source-quality decision: exact original names for the style flag, two color/style parameters, `m_textStateFlags`, the child bounds virtual method, and the two-argument text setter can be improved when stronger declaration evidence appears. Those refinements should not block the first-draft constructor body.

## Recommended Target Doc Changes

Implementation callback applied:

- Set `COMPLETION:88` and `CONFIDENCE:91`.
- Kept `CANONICAL_OWNER:0000E3`.
- Kept `RECONSTRUCTABLE:TRUE`.
- Kept `EMITTER_UIDS:0000E3`.
- Kept `EMITTER_POSITION_OPTIONAL:` blank.
- Inserted the formal `RECONSTRUCTION_CPP CODE` block above for `StaticTextControlPane::StaticTextControlPane`.
- Updated the item summary and evidence body with MCP session `73c77998` facts: active session/health, exact function range/size, padding/boundary bytes, 104 direct xrefs, StaticText vtable refs, callee/helper set, caller parameter order, historical generated Empty Emitter Marker state, current generated constructor output, and confidence caps.
- Replaced stale blocker wording that said final C++ was blocked by field names/vtable names/class gate. Remaining issues are confidence caps on exact names, not source readiness blockers.
- Preserved rejected alternatives: TextEditControlPane shared-helper ownership, TextEditPane ownership, ControlPane ownership, no-owner/non-emitting, broad raw-helper merge, and raw `sub_499030` source naming.

## Recommended Support Doc Changes

Implementation callback support handling:

- `by-class/StaticTextControlPane.md`: applied. UID00011I method row/support notes now state source-ready constructor emission through UID0000E3, preserve inferred-name caps, and no longer treat exact field/parameter names as a blank-code blocker for UID00011I.
- `by-file/StaticTextControlPane.md`: applied. Proposed contents/generated-output notes now state UID00011I emits constructor output after generation refresh and is not blank solely because of the previous formal block.
- `auto-generated/NexusTK/ui/controls/StaticTextControlPane.cpp`: not manually edited. Scoped validators refreshed it to `validator-command-id: 000000006174`, `validator-refreshed-at: 2026-07-04T06:04:29-04:00`, with UID00011I constructor output.
- `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`: already-present/excluded-with-reason. It already supports shared-helper separation from UID00011I and was not stale or contradictory, so no edit was made.
- `by-class/TextEditControlPane.md`, `by-class/TextEditPane.md`, `by-class/ControlPane.md`, `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md`, `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`, `by-memory/0x005446b0-0x005446d4.PaneSetMode.md`, and RectBounds/RectGeometry pages: already-present/excluded-with-reason. They already provide the accepted support names/roles used by the constructor; no direct stale UID00011I contradiction was found.

## Score And Metadata Recommendation

Implemented target metadata:

- `COMPLETION:88`.
- `CONFIDENCE:91`.
- `CANONICAL_OWNER:0000E3`.
- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:0000E3`.
- `EMITTER_POSITION_OPTIONAL:` blank.

Rationale: owner, range, route, behavior, caller parameter order, helper roles, previous generated-marker cause, and post-callback generated constructor output are strong enough for first-draft source. The score is capped below higher final-source values because exact original names and declarations remain partly inferred, especially `m_textStateFlags`, the style flag, color/style parameter names, child bounds setter spelling, and `SetText(text,0)` overload spelling.

## Open Questions With Attempted Resolution

- Exact public constructor parameter names: attempted through MCP decompile, disasm, and caller samples. Roles are stable; names remain descriptive.
- `+0x108/+0x109` field spelling: attempted through target and shared helper docs. The write clears a word; `+0x109` has accepted border/frame-gate evidence from shared helpers, but source field grouping remains inferred.
- `+0xfe/+0xff` final word store: attempted through ControlPane constructor docs and target disasm. Source body expresses final `m_controlType=6` and `m_controlFlags=0`; exact original packed-source spelling remains capped.
- TextEditPane text setter name/signature: attempted through decompile of `0x0058e270` and `0x0058fc30`. Behavior is exact; two-argument wrapper spelling remains descriptive.
- Child bounds virtual slot name: attempted through target disasm and RectBounds docs. Behavior is exact; source name `SetBounds` remains inferred.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or tracker edit is requested. Implementation edited by-* docs only and ran scoped validators. Generated output, autogen registry updates, and projected stats changes were validator-owned side effects, not manual edits.

## Follow-Up Actions

Implementation callback completion notes:

1. Leased target, class, and file support docs as B007 for the immediate edit/validator batch.
2. Applied target metadata and formal C++ block exactly.
3. Updated target evidence/caveats at report-level detail.
4. Updated `by-class/StaticTextControlPane.md` and `by-file/StaticTextControlPane.md` stale UID00011I wording.
5. Marked helper/support docs already-present or excluded-with-reason in this report ledger/checklist.
6. Ran scoped validators for every edited by-* file with `--apply --queue-timeout 240`; revalidated target/file after generated-freshness wording repair.
7. Checked `StaticTextControlPane.cpp` freshness; UID00011I now has constructor output at command `000000006174`.

## Confidence

Overall recommendation confidence: 91.

The behavioral reconstruction is high confidence because MCP decompile, disasm, byte boundaries, xrefs, vtable refs, helper decompiles, caller samples, and support docs agree. The exact-source confidence is capped by unresolved original naming, not by unresolved behavior or ownership.

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* file.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
|---|---|---|---|---:|---:|---|
| `by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md --apply --queue-timeout 240` | `000000006167` | `2026-07-04T06:03:22-04:00` | 0 | 1 | First target validator after code insertion. Reported `completion_update 00011I 88`, `confidence_update 00011I 91`, autogen registry update to block hash, `missing_ref_uid 0003LQ` x3, projected stats update, generated refresh deferred. |
| `by-class/StaticTextControlPane.md` | `python .\tools\validator.py --mode file --file by-class/StaticTextControlPane.md --apply --queue-timeout 240` | `000000006168` | `2026-07-04T06:03:30-04:00` | 0 | 1 | Reported `missing_ref_uid 0003LQ` x5, projected stats update, stats row updates for UID0000E3, generated refresh deferred. |
| `by-file/StaticTextControlPane.md` | `python .\tools\validator.py --mode file --file by-file/StaticTextControlPane.md --apply --queue-timeout 240` | `000000006169` | `2026-07-04T06:03:39-04:00` | 0 | 1 | First file-page validator. Reported `missing_ref_uid 0003LQ` x3, stats incremental noop for UID0000O8, projected stats update, generated refresh deferred. Generated output refreshed to UID00011I constructor at this point. |
| `by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md --apply --queue-timeout 240` | `000000006173` | `2026-07-04T06:04:23-04:00` | 0 | 1 | Revalidation after generated-freshness wording repair. Reported `missing_ref_uid 0003LQ` x3, stats incremental noop, projected stats update, generated refresh deferred. |
| `by-file/StaticTextControlPane.md` | `python .\tools\validator.py --mode file --file by-file/StaticTextControlPane.md --apply --queue-timeout 240` | `000000006174` | `2026-07-04T06:04:29-04:00` | 0 | 1 | Revalidation after generated-freshness wording repair. Reported `missing_ref_uid 0003LQ` x3, stats incremental noop, projected stats update, generated refresh deferred. |

Generated freshness check:

- `auto-generated/NexusTK/ui/controls/StaticTextControlPane.cpp` header records `validator-command-id: 000000006174`, `validator-refreshed-at: 2026-07-04T06:04:29-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- UID00011I appears at the top of generated output as `Completion:88 | Confidence:91` followed by the constructor body. It is not an Empty Emitter Marker.
- Queue-status check `python .\tools\validator.py --queue-status` returned command `000000006170` at `2026-07-04T06:03:52-04:00`, exit 0, with worker running, zero queued jobs, zero processing jobs, zero queued generated refresh jobs, and zero processing generated refresh jobs.

Known validator warning: `missing_ref_uid 0003LQ` appears in each scoped validator for existing UID0003LQ links. B007 did not edit validator state or run lifecycle cleanup commands; the warning is reported for supervisor handling if needed.

No `execute_report`, dry-run/probing execute variant, lifecycle/archive/registry command, manual generated edit, coverage edit, validator-state edit, supervisor-ledger edit, or report move was run by B007.

## Changed Files

By-* docs edited under B007 lease and validated:

- `by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md`
- `by-class/StaticTextControlPane.md`
- `by-file/StaticTextControlPane.md`
- `tools/leaser/Agents/Agent-B007/research/00011I-StaticTextControlPaneConstructor-source-quality.md`

Validator-owned side effects observed and not manually edited by B007:

- `auto-generated/NexusTK/ui/controls/StaticTextControlPane.cpp` refreshed with UID00011I constructor output.
- `project-level/-auto-completion-stats.md` projected stats/row updates were reported by scoped validators.
- Autogen registry/hash update for UID00011I was reported by the first target validator.

No generated file, coverage report, validator state, lifecycle/archive file, report archive, report move, or supervisor ledger was manually edited by B007.

Leases:

- Leased as B007: target `by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md`, `by-class/StaticTextControlPane.md`, and `by-file/StaticTextControlPane.md`.
- Released immediately after edit/validator batch with `python .\tools\leaser\leaser.py B007 unlease ...`; current lease report no longer lists B007.

## Implementation Tracking Checklist

- [x] Target metadata: set `COMPLETION:88`, `CONFIDENCE:91`, kept `CANONICAL_OWNER:0000E3`, kept `RECONSTRUCTABLE:TRUE`, kept `EMITTER_UIDS:0000E3`, kept blank optional position. Proof: target header and validator `000000006167`.
- [x] Target formal C++: inserted the exact formal `StaticTextControlPane::StaticTextControlPane` block from `## First-Draft C++ Recommendation`. Proof: target formal block and generated output at command `000000006174`.
- [x] Target evidence: incorporated MCP session `73c77998`, function range/size, padding bytes, decompile/disasm behavior, callee/helper set, vtable refs, 104 direct xrefs, caller argument-order samples, historical generated marker state, current generated constructor output, and score caps. Proof: target `IDA MCP Boundary And Xref Audit`, `Constructor Evidence`, `Touched State`, `Callee Evidence`, and `Score Rationale`.
- [x] Target caveats: preserved inferred parameter/field/helper-name caps and the packed `+0xfe/+0xff` control-state caveat. Proof: target `Remaining Confidence Caps` and score rationale.
- [x] Target rejected alternatives: preserved rejection of TextEditControlPane/shared-helper ownership, TextEditPane ownership, ControlPane ownership, no-owner/non-emitting, raw `sub_499030` naming, and broad helper merge. Proof: target Changes and support docs preserve UID0003LQ split and owner route.
- [x] `by-class/StaticTextControlPane.md`: updated UID00011I row/support notes to source-ready emitting constructor through UID0000E3. Proof: method row and 2026-07-04 evidence/change notes; validator `000000006168`.
- [x] `by-file/StaticTextControlPane.md`: updated proposed contents/generated-output note so UID00011I is no longer described as blank after constructor body insertion. Proof: proposed contents row, evidence note, current caveat, 2026-07-04 change note; validator `000000006174`.
- [x] Shared/helper docs: marked TextControlSharedStateAndBorderHelpers, TextEditControlPane, TextEditPane, ControlPane, TextEditPaneConstructor, PaneSetMode, IsLegacyAssetMode, RectBounds, and RectGeometry support as already-present/excluded-with-reason. Proof: no direct stale contradiction found; class/file/target notes cite already-present support names and preserve UID0003LQ split.
- [x] Validators: ran scoped validator for every edited by-* file with `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Proof: commands `000000006167`, `000000006168`, `000000006169`, plus revalidations `000000006173` and `000000006174`.
- [x] Generated freshness: checked `auto-generated/NexusTK/ui/controls/StaticTextControlPane.cpp`; UID00011I moved from Empty Emitter Marker to constructor output. Proof: header `validator-command-id: 000000006174`, `validator-refreshed-at: 2026-07-04T06:04:29-04:00`.
- [x] Report callback update: updated this Claim And Incorporation Ledger and checklist row by row to applied/already-present/excluded-with-reason proof. No accepted item remains blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000006206","destination_path":"executed-b-agent-research/B007/00011I-StaticTextControlPaneConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00011I-StaticTextControlPaneConstructor-source-quality.md","timestamp":"2026-07-04T06:21:06-04:00","uid":"00011I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
