** TARGET-REPORT-UID:0001HB **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0001HB LegendPane Source-Quality Report

## Finalized Report / Current Recommendation

UID0001HB should move from an empty emitter marker to source-ready constructor output in `by-memory/0x0056c400-0x0056c493.LegendPane.md`.

Recommended target metadata is `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000074`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000074`, blank optional emitter position. The formal target `RECONSTRUCTION_CPP CODE` block should contain the first-draft constructor body in this report. This is not a no-code aggregate: current MCP session `aa3930bd` proves one modeled constructor function with source-shaped body, three normal direct constructor callers, and only two already-documented callees. The prior blank-C++ reason is now a support-declaration problem, not a target-specific no-code proof.

The remaining confidence cap is field/name support: `TextEditPane` already has a source-facing constructor declaration, `g_useEpfAssets` already owns `byte_66DA97`, and `IsLegacyAssetMode` already owns `0x004b60b0`; the callback should add/confirm a source-visible `LegendPane` constructor declaration and a neutral inherited/base field name for the direct `this+0x104 = 63` write. Do not fold UID0001HB into SelfLookPane, SelfLookPane2, UserLookPane, GroupPane, or the vtable-data UID.

## Supporting Research

Primary MCP evidence was collected from active IDA MCP session `aa3930bd` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. A fresh read-only `idb_list` returned exactly one active session `aa3930bd`, not analyzing, worker-backed, owned/adopted. `server_health` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Current docs inspected:

- Target: `by-memory/0x0056c400-0x0056c493.LegendPane.md`, currently `85/89`, owner/emitter `000074`, reconstructable true, formal C++ blank.
- Class/file support: `by-class/LegendPane.md`, `by-file/LegendPane.md`, and `by-project-structure/proposed-source-tree.md` place LegendPane as a shared look/status child pane under `ui/panels/LegendPane.cpp`.
- Adjacent support: `by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md`, `by-memory/0x00624384-0x00624438.LegendPaneVtableData.md`, and `by-type/by-vtable/LegendPaneVtables.md` already split the false virtual stubs and vtable data out of the constructor.
- Base/helper support: `by-class/TextEditPane.md` declares the 12-argument `TextEditPane` constructor; `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md` is the constructor-body authority; `by-global/g_useEpfAssets.md` owns `byte_66DA97`; `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` owns the helper called from UID0001HB.
- Generated/tracker context: `auto-generated/NexusTK/ui/panels/LegendPane.cpp` currently contains empty emitter markers for by-class LegendPane, UID0001HB, and UID00023W. `auto-generated/-ag-research-tracker.md` records UID0001HB as `85/89`, reports `0`, and LegendPane.cpp as `3` contributors, `0` filled.
- Prior executed B reports for SelfLookPane, SelfLookPane2, UserLookPane, and LookPane vtable family confirm LegendPane is shared support constructed by those owners, not owned by them. No executed B report was found for UID0001HB itself.

## Target

- UID: `0001HB`
- Target path: `by-memory/0x0056c400-0x0056c493.LegendPane.md`
- Current assignment-time metadata: `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:000074`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000074`, blank optional position, blank formal C++.
- Current IDA MCP function: `sub_56C400`, start `0x0056c400`, size `0x93` / 147 bytes, exclusive end `0x0056c493`.
- Function kind: source constructor for `LegendPane`.
- Recommended metadata after callback: `COMPLETION:88`, `CONFIDENCE:91`, owner/emitter unchanged, formal constructor C++ inserted.

## Current Target State

The target is documented but still emits no C++. The target doc already records the main behavior: resolution-dependent geometry from `byte_66DA97`, call to `sub_4B60B0`, call to `sub_58DCE0`, three `LegendPane` vtable stores, and `this+0x104 = 63`. The stale part is the conclusion that helper/global/base naming and standalone-vs-merged source shape justify a blank target C++ block.

Current MCP evidence resolves the source shape strongly enough for a first-draft constructor:

- `lookup_funcs` confirms the target is exactly a modeled function at `0x0056c400` of size `0x93`; `0x0056c493` is not a function.
- `get_bytes` for `0x0056c400` size `147` matches the constructor body and returns clean end padding after `0x0056c493`.
- `xrefs_to 0x0056c400` returns exactly three direct constructor calls: `0x0056571c` in `sub_565610`, `0x0056ff6e` in `sub_56FE80`, and `0x0059f428` in `sub_59F260`.
- `callees 0x0056c400` returns only `0x004b60b0` and `0x0058dce0`.
- `xrefs_to 0x00624388`, `0x00624400`, and `0x00624430` return the three vtable stores from the constructor at `0x0056c466`, `0x0056c46e`, and `0x0056c478`.
- `lookup_funcs` confirms the adjacent false stubs are separate modeled functions at `0x0056c4a0` and `0x0056c4b0`, each size `0x5`; they are not part of UID0001HB.

The current target state is therefore source-ready with support declarations, not aggregate/no-code.

## Heuristic / Inference Reanalysis And Validation

The original empty-emitter blockers were: unresolved helper/global names, unresolved base constructor signature, unclear direct field name for `this+0x104`, and a possible standalone-vs-merged LegendPane source-placement question. Current evidence reduces those blockers:

- Global mode selector: `byte_66DA97` is already owned by `by-global/g_useEpfAssets.md` as `g_useEpfAssets`. UID0001HB reads it twice. The constructor uses EPF/current-asset geometry when the byte equals `1`, choosing `width/maxWidth 175`, `height/maxHeight 229`, and `contentWidth 160`; otherwise it chooses `145`, `180`, and `145`.
- Legacy helper: `0x004b60b0` is already split as `IsLegacyAssetMode`, exact behavior `byte_66DA97 != 1`. UID0001HB passes that boolean result through the `unsigned short`/font-format slot of the `TextEditPane` constructor. The helper body may remain its own support item, but UID0001HB can call the source-facing helper.
- Base constructor: `by-class/TextEditPane.md` already declares `TextEditPane(int maxWidth, int maxHeight, int contentWidth, int contentHeight, int backgroundColor, int scrollColor, char hasHorizontalScrollbar, char hasVerticalScrollbar, unsigned int styleFlags, unsigned short fontId, char isReadOnly, char inputMode)`. UID0001HB's call shape exactly matches that declaration: geometry, `128`, `0`, `false`, `true`, `6`, legacy-mode word, `true`, `0`.
- Field write: `this[65] = 63` is a direct dword write at `this+0x104`. Existing docs describe it as fixed scroll/mode state but do not provide a final original member name. This should cap confidence, not block code entirely. Implementation should introduce or confirm a neutral support field such as `m_textMode`/`m_displayMode` in the relevant base support docs, with UID0001HB evidence attached, or choose the already accepted stronger name if one exists during callback.
- Source placement: project structure and prior executed reports reject absorbing LegendPane into SelfLookPane, SelfLookPane2, UserLookPane, or GroupPane. `ui/panels/LegendPane.cpp` is already the generated source root. Shared construction by three callers strengthens separate LegendPane placement.

Rejected alternatives:

- Keep blank C++ because of accepted-support prerequisites: rejected. The support declarations are inferable from current by-* docs and MCP evidence.
- Merge into SelfLookPane/SelfLookPane2/UserLookPane: rejected by three direct callers and existing project-structure notes.
- Assign to GroupPane or GroupPane-family source: rejected. The successor at `0x0056c4c0` is GroupPane, but UID0001HB ends at `0x0056c493` and the false-stub support doc's old Group wording is stale.
- Emit decompiler-shaped vtable stores or raw offsets in C++: rejected. Vtable writes are compiler output from normal inheritance; the only target-specific source body is a base initializer plus one member assignment.
- Move false virtual stubs into UID0001HB C++: rejected. The stubs are separate functions at `0x0056c4a0` and `0x0056c4b0` and belong to UID00023W/support vtable work.

## Evidence Standards Used

I used current by-* documentation plus narrow, schema-current IDA MCP calls. MCP calls were read-only and paged/bounded: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `decompile`, and local doc searches. I did not use fallback-only evidence.

I treated exact modeled function boundaries, byte ranges, caller/callee lists, vtable data xrefs, and existing class/global support docs as hard evidence. I treated source-facing helper and member names as inference only when they are not already accepted by support docs, and I carried those names as implementation-ready support recommendations rather than claiming they are final original names.

## Evidence Checked

MCP session `aa3930bd`:

- `idb_list`: one active NexusTK IDB session `aa3930bd`, not analyzing.
- `server_health`: `ok`, Hex-Rays ready, strings cache ready, imagebase `0x400000`.
- `lookup_funcs`: `0x0056c400 -> sub_56C400 size 0x93`; `0x0056c493 -> Not a function`; `0x0056c4a0 -> sub_56C4A0 size 0x5`; `0x0056c4b0 -> sub_56C4B0 size 0x5`.
- `xrefs_to 0x0056c400`: exactly three code xrefs, from `0x0056571c`, `0x0056ff6e`, and `0x0059f428`.
- `callees 0x0056c400`: exactly `sub_4B60B0` and `sub_58DCE0`; false stubs have no callees.
- `xrefs_to vtable addresses`: `0x00624388` from `0x0056c466`, `0x00624400` from `0x0056c46e`, `0x00624430` from `0x0056c478`.
- `get_bytes 0x0056c400 size 147`: confirms the full constructor body, including byte reads of `0x0066da97`, helper call, `TextEditPane` constructor call, vtable stores, `this+0x104 = 0x3f`, and `ret`.
- `get_bytes 0x0056c493 size 45`: confirms `0xcc` padding, then false stub `32 c0 c2 04 00` at `0x0056c4a0`, more padding, false stub `32 c0 c2 04 00` at `0x0056c4b0`, and padding before the successor.
- `get_bytes 0x0066da97 size 1`: current byte value `0x1`; behavior uses equality test, not current runtime value as a constant.
- `decompile 0x0056c400`: shows geometry selection, helper call, `sub_58DCE0(this, v4, v2, v5, v2, 128, 0, 0, 1, 6, v7, 1, 0)`, three `LegendPane` vtable assignments, and `this[65] = 63`.

Local documentation checks:

- `by-class/TextEditPane.md` already contains a source-facing 12-argument constructor declaration matching the target call.
- `by-global/g_useEpfAssets.md` already owns `byte_66DA97` and warns that `g_useHighResLayout` is too narrow.
- `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` already provides the source-facing helper name for the target's first callee.
- `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md` lists UID0001HB as a caller and describes the 12-argument call shape.
- `by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md` contains useful stub evidence but has stale `Group.cpp` wording in its item summary.
- `by-memory/0x00624384-0x00624438.LegendPaneVtableData.md` and `by-type/by-vtable/LegendPaneVtables.md` already split and document the vtable facts at same-or-greater detail.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0001HB-01 | UID0001HB is exactly `0x0056c400-0x0056c493`, size `0x93`, modeled as `sub_56C400`. | High | MCP `lookup_funcs` and `get_bytes` from session `aa3930bd`. | `by-memory/0x0056c400-0x0056c493.LegendPane.md` / Status, Evidence, Score Rationale, Changes. | applied. | Applied in target with current MCP session `aa3930bd`; validator `000000006051` and wait-generated validator `000000006056` ok. |
| C-0001HB-02 | The constructor has exactly three direct callers: SelfLookPane, SelfLookPane2, and UserLookPane construction paths at `0x0056571c`, `0x0056ff6e`, `0x0059f428`. | High | MCP `xrefs_to 0x0056c400` from session `aa3930bd`. | Target Ownership/Positive Evidence; `by-class/LegendPane.md` constructor notes; `by-file/LegendPane.md` source-placement notes. | applied. | Applied in target, class, and file docs; validators `000000006051`, `000000006052`, `000000006053`, `000000006061` ok. |
| C-0001HB-03 | UID0001HB calls only `IsLegacyAssetMode` candidate `0x004b60b0` and `TextEditPane` constructor `0x0058dce0`. | High | MCP `callees 0x0056c400` from session `aa3930bd`. | Target Raw Code Evidence; `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`; `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md`. | applied/already-present. | Applied to target/class/file; TextEditPane and IsLegacyAssetMode support identities were already present at same-or-greater detail, so no support edits were needed. |
| C-0001HB-04 | Geometry depends on `g_useEpfAssets`/`byte_66DA97`: current/EPF path uses `175,229,160,229`; legacy path uses `145,180,145,180`. | High | MCP decompile and constructor bytes from session `aa3930bd`; `by-global/g_useEpfAssets.md`. | Target formal C++, Raw Code Evidence, and Positive Evidence; `by-global/g_useEpfAssets.md` consumer note if needed. | applied/already-present. | Applied in target formal C++ and evidence; `g_useEpfAssets` declaration/support already present, no global edit needed. |
| C-0001HB-05 | `TextEditPane` construction arguments are `maxWidth, maxHeight, contentWidth, contentHeight, 128, 0, false, true, 6, IsLegacyAssetMode(), true, 0`. | High | MCP decompile from session `aa3930bd`; `by-class/TextEditPane.md` existing constructor declaration. | Target formal C++; `by-class/TextEditPane.md` and TextEditPane constructor child support sections. | applied/already-present. | Applied in target C++; TextEditPane declaration was already present in `by-class/TextEditPane.md`, so no TextEditPane edit needed. |
| C-0001HB-06 | The three vtable writes at `+0`, `+0xa0`, and `+0xa4` are compiler output for normal class construction, not source code. | High | MCP xrefs to `0x00624388`, `0x00624400`, `0x00624430`; LegendPane vtable docs. | Target Negative Evidence; `by-memory/0x00624384-0x00624438.LegendPaneVtableData.md`; `by-type/by-vtable/LegendPaneVtables.md`. | applied/already-present. | Target now rejects raw vtable C++; vtable-data and vtable-family docs were already present at same-or-greater detail, no edits needed. |
| C-0001HB-07 | Direct `this+0x104 = 63` is the only post-base source state write and needs a neutral source-facing member name before callback implementation. | Medium-high | MCP decompile and bytes from session `aa3930bd`; current target/class docs describe fixed scroll/mode state without final original name. | Target formal C++; `by-class/LegendPane.md` and the relevant base/layout support section for the accepted `+0x104` member name. | applied. | Applied using report-approved placeholder `m_displayMode`; target/class/file docs explicitly cap confidence because it is a source-facing placeholder for observed `this+0x104`. |
| C-0001HB-08 | Adjacent false stubs at `0x0056c4a0` and `0x0056c4b0` are separate UID00023W work, not part of constructor output. | High | MCP `lookup_funcs`, `get_bytes`, and `callees`; `by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md`. | Target Negative Evidence; UID00023W stub doc Item Summary/Status; LegendPane vtable docs. | applied/already-present. | Target/class/file preserve split; UID00023W item summary stale Group wording corrected; vtable support already present. |
| C-0001HB-09 | Generated LegendPane.cpp currently emits three empty markers and no source. | High | Local generated file and tracker read: `auto-generated/NexusTK/ui/panels/LegendPane.cpp`, `auto-generated/-ag-research-tracker.md`. | Report Current Target State and Recommended Target Doc Changes; generated output should refresh only through validator after callback. | applied/superseded. | Pre-callback empty-marker state preserved in evidence; validator-owned generated refresh now supersedes it with UID0001HB constructor output in `LegendPane.cpp` at command `000000006061`. |

## Positive Evidence Summary

- The function is a single compact modeled constructor with exact byte boundary, three normal direct callers, two normal callees, and no raw-helper liveness ambiguity.
- The class and file ownership route is already established: `LegendPane` under `ui/panels/LegendPane.cpp`, shared by SelfLookPane, SelfLookPane2, and UserLookPane.
- The base constructor signature needed for source is already present in `by-class/TextEditPane.md`, and UID0001HB's call exactly matches it.
- `byte_66DA97` and `0x004b60b0` have current support identities: `g_useEpfAssets` and `IsLegacyAssetMode`.
- Vtable data is already split into dedicated support docs, so the target constructor can omit vtable scaffolding.
- The adjacent false virtual stubs are separate functions with clean padding, so they do not block constructor source.

## Negative Evidence Summary

- No evidence supports a standalone no-code proof for UID0001HB. The target is neither a compiler wrapper nor an aggregate.
- No evidence supports GroupPane ownership. The GroupPane successor begins later at `0x0056c4c0`; UID0001HB ends before the false-stub island.
- No evidence supports moving the constructor into SelfLookPane, SelfLookPane2, or UserLookPane. All three are callers, which is consumer evidence, not ownership.
- No evidence supports hand-emitting vtable stores, RTTI pointers, raw offsets, or decompiler temporary variables in source C++.
- No evidence supports using current byte value `0x1` at `0x0066da97` as a compile-time constant; the source behavior must preserve the runtime branch.

## Ranked Ownership Analysis

1. `by-class/LegendPane.md` / `by-file/LegendPane.md`: strongest owner and emitter route. The function constructs a `LegendPane`, writes `LegendPane` vtables, and is shared by multiple look-panel owners.
2. `by-class/TextEditPane.md` / `by-file/TextEditPane.md`: support only. UID0001HB delegates to the TextEditPane constructor, but the constructed dynamic type is LegendPane.
3. SelfLookPane, SelfLookPane2, UserLookPane: callers only. They allocate or construct LegendPane but do not own the constructor's source.
4. Vtable-data UID and false-stub UID: support/sibling output only. They prove layout and virtual slots but are not the constructor's source owner.
5. GroupPane: rejected. The adjacent successor and stale support wording do not override constructor vtable identity, callers, or existing project-structure placement.

## Source Placement

Source placement should remain `auto-generated/NexusTK/ui/panels/LegendPane.cpp` through `by-file/LegendPane.md` / `by-class/LegendPane.md`. The project-structure note already says LegendPane is constructed by both self-look classes and UserLookPane and should stay a shared look/status child source candidate. UID0001HB should emit as `LegendPane::LegendPane()` in that file.

Do not place this constructor in `SelfLookPane.cpp`, `UserLookPane.cpp`, `GroupPane.cpp`, `TextEditPane.cpp`, or a vtable-data source file.

## First-Draft C++ Recommendation

Insert the following exact formal target C++ after the support callback chooses or confirms the field name for `this+0x104`. If no stronger already-accepted support name exists, use the neutral inherited/base support name `m_displayMode` and document that it is a source-facing placeholder for `this+0x104`.

```cpp
LegendPane::LegendPane()
    : TextEditPane(g_useEpfAssets ? 175 : 145,
                   g_useEpfAssets ? 229 : 180,
                   g_useEpfAssets ? 160 : 145,
                   g_useEpfAssets ? 229 : 180,
                   128,
                   0,
                   false,
                   true,
                   6,
                   static_cast<unsigned short>(IsLegacyAssetMode()),
                   true,
                   0)
{
    m_displayMode = 63;
}
```

Required support declarations for this code path:

```cpp
extern bool g_useEpfAssets;
bool IsLegacyAssetMode();

class LegendPane : public TextEditPane
{
public:
    LegendPane();
};
```

The field declaration should live in the existing class/base support where `+0x104` belongs. If callback inspection finds a stronger accepted member name than `m_displayMode`, use that name in the formal C++ and ledger it as an already-present stronger support name.

## Final Recommendation

Proceed with implementation callback. UID0001HB should no longer remain blank solely because support names were incomplete. The source body can be emitted as a normal constructor initializer plus a single member assignment, with support docs carrying the name caveats. The confidence cap remains because `this+0x104` still needs final source-facing field placement/name confirmation and the false virtual stubs remain separate blank support work, but neither blocks this constructor.

## Recommended Target Doc Changes

For `by-memory/0x0056c400-0x0056c493.LegendPane.md`:

- Set `COMPLETION:88`, `CONFIDENCE:91`; keep `CANONICAL_OWNER:000074`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000074`, blank optional position.
- Replace the formal `RECONSTRUCTION_CPP CODE` block with the `LegendPane::LegendPane()` constructor from this report, using the accepted support member name for `+0x104`.
- Update Item Summary and Reconstruction Status to say the target is source-ready through `LegendPane.cpp`, not an empty marker pending broad naming work.
- Add MCP session `aa3930bd` facts: function start/size/end, exact caller list, callee list, byte boundary/padding, vtable stores, `byte_66DA97` geometry branch, `IsLegacyAssetMode` helper use, `TextEditPane` constructor argument shape, false-stub separation, and generated empty-marker current state.
- Replace stale blocker text with remaining confidence caps: final `+0x104` field name, helper/global naming consistency, and sibling false-stub virtual slot naming. These cap score but do not keep formal C++ blank.
- Preserve rejected alternatives: SelfLookPane/SelfLookPane2/UserLookPane ownership, GroupPane ownership, vtable/raw-offset/decompiler-source output, false-stub folding, and constant-folding the current `byte_66DA97` value.

## Recommended Support Doc Changes

For `by-class/LegendPane.md`:

- Record UID0001HB as source-ready at `88/91` through `LegendPane::LegendPane()`.
- Add constructor support details: `TextEditPane` base construction, `g_useEpfAssets` geometry, `IsLegacyAssetMode()` word argument, three vtable views, and direct `+0x104 = 63` state write.
- Add or confirm a `LegendPane();` constructor declaration. Do not invent unrelated LegendPane fields.

For `by-file/LegendPane.md`:

- Record that UID0001HB should now emit in `ui/panels/LegendPane.cpp`, while UID00023W false virtual stubs may remain blank until virtual slot names are accepted.
- Keep the shared source-placement rationale: constructed by SelfLookPane, SelfLookPane2, and UserLookPane, not absorbed by any one caller.

For `by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md`:

- Correct the stale item-summary/source wording that still points at `Group.cpp`/Group family if it remains present at callback time.
- Keep the stubs separate from UID0001HB and blank unless virtual slot names are accepted.

For `by-memory/0x00624384-0x00624438.LegendPaneVtableData.md` and `by-type/by-vtable/LegendPaneVtables.md`:

- Mark vtable-store facts as already present if current text remains at same-or-greater detail. Do not duplicate raw vtable bytes in the constructor target.

For `by-class/TextEditPane.md` and `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md`:

- Mark the 12-argument constructor declaration/signature as already present. If callback needs a consumer note, add UID0001HB as a clean consumer of the accepted constructor shape.

For `by-global/g_useEpfAssets.md` and `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`:

- Mark `g_useEpfAssets` and `IsLegacyAssetMode()` support as already present, or add a narrow consumer note that UID0001HB reads the global twice and passes the helper result through the `TextEditPane` font/default-format word.

## Score And Metadata Recommendation

Recommend `COMPLETION:88`, `CONFIDENCE:91`.

Completion increases because the target now has a formal first-draft constructor body, exact MCP-backed range/caller/callee/byte evidence, and implementation-ready support recommendations. Confidence increases because the binary behavior is direct and all significant dependencies have support identities. Confidence should not exceed low 90s until the `+0x104` member name/owning base is accepted, sibling false-stub virtual names are resolved, and generated output after callback is verified.

Metadata should remain `CANONICAL_OWNER:000074`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000074`, blank optional emitter position.

## Open Questions With Attempted Resolution

- Is `this+0x104` safe to represent in source? Yes, but only with a support-declared member name. Current evidence proves the write and value (`63`) but not a final original name. Use an accepted stronger support name if present during callback; otherwise introduce a neutral source-facing placeholder such as `m_displayMode` and document the exact offset.
- Should `IsLegacyAssetMode()` block constructor output because its own body is blank? No. It is already split, named, and exact enough for a support declaration. UID0001HB should call it rather than inline a raw `byte_66DA97 != 1` expression if preserving source call shape is preferred.
- Should geometry use `g_useEpfAssets` or a high-resolution layout name? Use `g_useEpfAssets`. The global doc explicitly warns that `g_useHighResLayout` is too narrow, and UID0001HB tests the same global selector used by asset-mode support.
- Should false stubs be emitted with this constructor? No. They have their own UID, starts, sizes, vtable refs, and unresolved virtual slot names.
- Should this remain blank because generated LegendPane.cpp is empty now? No. The generated file is an input showing current coverage deficiency; it is not evidence that source C++ is unsafe.

## Validator Results

Scoped validators run from `source-3/project-documentation` for every edited by-* file. No `execute_report`, dry-run/probe lifecycle command, archive command, manual generated edit, manual coverage edit, validator-state edit, or supervisor-ledger edit was run.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0056c400-0x0056c493.LegendPane.md` | `python .\tools\validator.py --mode file --file by-memory/0x0056c400-0x0056c493.LegendPane.md --apply --queue-timeout 240` | `000000006051` | `2026-07-04T04:13:36-04:00` | 0 | 1 | Completion/confidence updated; autogen registry updated; stats row removed/rescore recommended; generated refresh deferred. |
| `by-class/LegendPane.md` | `python .\tools\validator.py --mode file --file by-class/LegendPane.md --apply --queue-timeout 240` | `000000006052` | `2026-07-04T04:13:41-04:00` | 0 | 1 | `missing_ref_uid 00038P` warnings already tied to validator registry; generated refresh deferred. |
| `by-file/LegendPane.md` | `python .\tools\validator.py --mode file --file by-file/LegendPane.md --apply --queue-timeout 240` | `000000006053` | `2026-07-04T04:13:43-04:00` | 0 | 1 | `missing_ref_uid 00038P` warnings; generated refresh deferred. |
| `by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md` | `python .\tools\validator.py --mode file --file by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md --apply --queue-timeout 240` | `000000006054` | `2026-07-04T04:13:45-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x0056c400-0x0056c493.LegendPane.md` | `python .\tools\validator.py --mode file --file by-memory/0x0056c400-0x0056c493.LegendPane.md --apply --queue-timeout 240 --wait-generated` | `000000006056` | `2026-07-04T04:14:13-04:00` | 0 | 1 | Validator-owned generated refresh completed; broad generated metadata refresh/backup side effects reported by validator. |
| `by-file/LegendPane.md` | `python .\tools\validator.py --mode file --file by-file/LegendPane.md --apply --queue-timeout 240 --wait-generated` | `000000006061` | `2026-07-04T04:14:42-04:00` | 0 | 1 | `missing_ref_uid 00038P` warnings; validator-owned generated refresh completed and refreshed `auto-generated/NexusTK/ui/panels/LegendPane.cpp`. |

Generated freshness proof: `auto-generated/NexusTK/ui/panels/LegendPane.cpp` has `validator-command-id: 000000006061`, `validator-refreshed-at: 2026-07-04T04:14:42-04:00`, `validator-refresh-source: foreground-generated-refresh`, and contains the UID0001HB `LegendPane::LegendPane()` constructor body with `Completion:88 | Confidence:91`. UID00023W remains an Empty Emitter Marker.

## Changed Files

- `by-memory/0x0056c400-0x0056c493.LegendPane.md` - metadata, formal constructor C++, evidence, score rationale, and change history updated.
- `by-class/LegendPane.md` - constructor declaration and UID0001HB source-ready support notes added.
- `by-file/LegendPane.md` - UID0001HB source-emission route and current MCP evidence added.
- `by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md` - stale Group.cpp/group-family item-summary wording corrected.
- `tools/leaser/Agents/Agent-B009/research/0001HB-LegendPane-source-quality.md` - ledger, validators, changed files, and checklist updated after callback.

Validator-owned generated refresh side effects occurred during `--wait-generated`, including `auto-generated/NexusTK/ui/panels/LegendPane.cpp` freshness and broader generated metadata refreshes reported by validator. These were not edited by hand.

## Implementation Tracking Checklist

- [x] Target metadata updated to `88/91`, owner/emitter/reconstructable unchanged.
- [x] Target formal `RECONSTRUCTION_CPP CODE` receives the exact `LegendPane::LegendPane()` constructor body from this report, using accepted placeholder `m_displayMode` for `+0x104`.
- [x] Target evidence sections updated with MCP session `aa3930bd`: range, size, bytes, padding, callers, callees, vtable stores, global/helper/base constructor behavior, and false-stub separation.
- [x] Target stale blank-C++ blocker replaced with support-declaration confidence caps.
- [x] `by-class/LegendPane.md` records UID0001HB as source-ready and adds constructor declaration/support notes.
- [x] `by-file/LegendPane.md` records UID0001HB source emission through `ui/panels/LegendPane.cpp`.
- [x] UID00023W false-stub support doc stale Group wording fixed.
- [x] Vtable-data and vtable-family docs ledgered already-present; no edits needed because same-or-greater detail already existed.
- [x] TextEditPane, `g_useEpfAssets`, and `IsLegacyAssetMode` support declarations ledgered already-present; no edits needed because same-or-greater support detail already existed.
- [x] Scoped validators run after by-* edits; generated `auto-generated/NexusTK/ui/panels/LegendPane.cpp` checked and foreground-refreshed at command `000000006061` with UID0001HB constructor output.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000006111","destination_path":"executed-b-agent-research/B009/0001HB-LegendPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001HB-LegendPane-source-quality.md","timestamp":"2026-07-04T04:50:10-04:00","uid":"0001HB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
