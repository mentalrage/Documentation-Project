** TARGET-REPORT-UID:0004EF **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004EF PrettyButtonControlPane2 OnPaint Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:0004EF] `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md` from a blank non-emitting child to an emitting `PrettyButtonControlPane2::OnPaint()` method through direct class owner [UID:0000AS] `PrettyButtonControlPane2`.
- Final disposition: source-authored class2 virtual paint method. Current MCP session `9fb70afc` confirms exact function range `0x0054baa0-0x0054bb48`, vtable-only reachability through slot `0x006223c0`, frame selection from constructor-provided fields, resource lookup/render helper calls, and `0xcc` padding after the function. The previous blank-C++ blocker is resolved to implementation-ready inferred member names and accepted helper roles.
- Required action after supervisor acceptance: update target metadata to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000AS`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AS`, and insert the formal C++ block in `## First-Draft C++ Recommendation`.
- Confidence: high for range, owner, vtable slot, behavior, field offsets, and disabled-frame-vs-overlay distinction; medium-high for exact original member spellings because field names remain inferred from constructor/setter/paint behavior rather than recovered symbols.

## Supporting Research

- This is a report-only pass for assignment `B005-report-0004EF-PrettyButtonControlPane2OnPaint-20260703`.
- Supervisor restored MCP and verified endpoint `http://127.0.0.1:13337/mcp`; this report redoes MCP evidence against active IDB session `9fb70afc`.
- Gate 1 was later accepted by supervisor callback for implementation. B005 edited only the leased by-* target/support docs and this B005 report; generated outputs were refreshed only by scoped validators.
- No `execute_report`, execute-report dry-run/probing/status variant, registry lifecycle command, manual report move, archive command, or equivalent lifecycle command was run.

## Target

- Target UID: `0004EF`.
- Target path: `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md`.
- Current queue row at assignment time: `auto-generated/-ag-research-tracker.md` by-memory not-covered reconstructable row, `84/88`, average `86.0`, reports `0`.
- Current supervisor classification: report-only source-quality, ownership/emitter route, disabled behavior, frame/resource constants, member naming, and C++ readiness research.
- Direct owner/support state: target owner [UID:0000AS] `PrettyButtonControlPane2` is `87/89`, reconstructable, and emits through [UID:0000MP] `PrettyButtonControlPane` / `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

## Current Target State

- Existing metadata: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000AS`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Existing summary: exact class2 paint child split from [UID:0001F9]; old evidence says function `0x0054baa0` size `0xa8`, calls EPF/PAL frame helpers, and vtable page [UID:0002UX] records slot `0x006223c0 -> 0x0054baa0`.
- Existing blocker text: C++ remains blank pending accepted frame/resource constants and member names.
- Current artifact/lifecycle status: this report is active in `tools/leaser/Agents/Agent-B005/research/` for supervisor Gate 1 review only.

## Heuristic / Inference Reanalysis And Validation

- Frame/resource blocker is resolved. Constructor `0x0054b8c0` stores four frame IDs at complete-object offsets `+0x10c`, `+0x110`, `+0x114`, and `+0x118`; paint consumes exactly those fields. The report should use member fields, not hard-coded resource/frame constants.
- State-byte blocker is resolved enough for a first draft. UID0004EC already resolves byte `+0x11c` as the selected byte written by `PrettyButtonControlPane2::SetSelected(bool selected)`. Current MCP decompile/disasm of `0x0054ba30` confirms byte `+0x11d` is set to `1` only for visual state `0x0b` and reset otherwise around the inherited timer path.
- Disabled behavior is not the class1 overlay path. Class1 UID0004E8 draws a disabled overlay when `+0x101` is false. Class2 UID0004EF instead selects frame field `+0x118` before initializing `EPFTileContext`, then calls the same lookup/render helpers. It does not call `GrafPort::SetDrawColor`, does not write draw-mode byte `+0x70`, and does not dispatch Surface slot `0x0069b3fc`.
- Helper-name blocker is resolved through existing accepted support docs. `dword_67A744` is [UID:0000QU] `g_pEPFLib`; `0x00457a60` is `EPFTileContext` initialization; `0x004d02f0` is `ResourceLayoutTable::LookupLayoutEntry`; `0x004b9980` is the shared tile/frame render helper; `0x00584540` returns string data for the stored resource-string fields.
- Rejected alternatives: leaving raw `sub_4D02F0`, `sub_457A60`, `sub_4B9980`, `sub_584540`, or `dword_67A744` as final blockers is no longer justified. Moving ownership to [UID:0000MP] directly is weaker than class owner [UID:0000AS]. Moving ownership to `ButtonControlPane`, ImageLib/ResourceLayoutTable, EPFTileContext, or CreateUser dialog consumers is rejected because those are dependencies or callers, not owners of the vtable paint method.
- Remaining uncertainty: exact original field spellings and final class declaration names are inferred. That caps confidence below final-audit quality but does not justify a blank emitter.

## Evidence Standards Used

- IDA MCP: current JSON-RPC `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, bounded `disasm`, `xrefs_to`, `get_bytes`, `callees`, bounded `entity_query`, and `int_convert`.
- Local documentation: current target page, direct class/file/parent/vtable support docs, generated tracker/memory coverage as read-only state, and executed B-agent reports as leads after search-gated opening.
- Negative evidence: no direct code callers to `0x0054baa0`; only data xref from vtable slot `0x006223c0`; no disabled-overlay helper calls in this body.
- Numeric conversion: `int_convert` verified field-offset conversions `257 == 0x101`, `268 == 0x10c`, `272 == 0x110`, `276 == 0x114`, `280 == 0x118`, `284 == 0x11c`, `285 == 0x11d`, `288 == 0x120`, and `292 == 0x124`. The first attempt to convert `168`/`0xa8` without a larger size produced a one-byte-size error; the function size is still directly reported by MCP `lookup_funcs` as `0xa8`.

## Evidence Checked

- MCP session:
  - `idb_list`: active session `9fb70afc`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker PID `5524`, `is_analyzing:false`.
  - `server_health`: `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, imagebase `0x400000`.
  - `lookup_funcs`: `0x0054baa0` -> `sub_54BAA0` size `0xa8`; constructor `0x0054b8c0` size `0xcd`; visual-state setter `0x0054ba30` size `0x62`; click `0x0054bb50` size `0x39`; helper starts `0x004d02f0`, `0x00457a60`, `0x004b9980`, and `0x00584540` all resolve. `0x0054b9e0` is not an IDA-modeled function, matching UID0004EC's raw-span docs.
  - `analyze_function` / `decompile 0x0054baa0`: body loads `dword_67A744`; if byte `+0x101` is false chooses frame `+0x118`; otherwise byte `+0x11d` chooses frame `+0x110`, byte `+0x11c` chooses frame `+0x114`, default chooses frame `+0x10c`. It initializes a local tile context, passes string `+0x120` to `sub_4D02F0`, string `+0x124` to `sub_4B9980`, renders into bounds `this+0x44`, and returns the render helper result.
  - `disasm 0x0054baa0`: 56 instructions; branch sequence at `0x54babb`, `0x54bacc`, and `0x54badd`; frame loads at `0x54bac4`, `0x54bad5`, `0x54bae6`, and `0x54baee`; resource-string calls at `0x54bb01` and `0x54bb16`; render call at `0x54bb32`; no disabled overlay call sequence.
  - `decompile/disasm 0x0054b8c0`: constructor stores frame IDs at `+0x10c/+0x110/+0x114/+0x118`, zeroes word `+0x11c`, constructs strings at `+0x120/+0x124`, stores constructor flag at `+0xff`, clears `+0x100`, and clears callback pointer `+0x128`.
  - `decompile/disasm 0x0054ba30`: visual-state path compares inherited visual-state byte `+0x103`; for state `0x0b` writes byte `+0x11d = 1`, schedules timer helper `0x005975e0` with `0x96` / 150 ms, and delegates to `0x00494b80`; otherwise clears `+0x11d`, removes timer helper `0x00597600`, then delegates.
  - `xrefs_to`: `0x0054baa0` has one data xref from `0x006223c0`; no direct code callers. `0x006223c0` has no xrefs to the slot address itself. Class2 vtable bases `0x0062237c`, `0x006223e4`, and `0x00622414` each have constructor/destructor/scalar-wrapper store xrefs.
  - `get_bytes`: `0x006223c0` bytes `a0 ba 54 00` encode the target pointer; `0x0054bb48-0x0054bb50` is eight `0xcc` bytes; `0x0054ba92-0x0054baa0` is fourteen `0xcc` bytes.
  - `callees`: target calls `0x00457a60`, `0x00584540`, `0x004d02f0`, `0x004b9980`, and `@__security_check_cookie@4`.
  - Bounded `entity_query`: functions in `0x0054b8c0-0x0054bc40` include constructor, visual-state setter, target paint, click, thunks, and scalar wrappers; names in `0x00622378-0x0062241c` include the three `PrettyButtonControlPane2` vtable bases.
- by-* docs checked: target [UID:0004EF], parent split/index [UID:0001F9], class [UID:0000AS], file [UID:0000MP], class1 paint [UID:0004E8], class2 visual-state setter [UID:0004EE], vtable child [UID:0002UX], helper docs for `g_pEPFLib`, `EPFTileContext`, `ResourceLayoutTable::LookupLayoutEntry`, and shared render/GrafPort dependencies.
- Generated/tracker docs checked: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and generated by-memory coverage rows for UID0004EF as read-only state.
- Existing report search terms: `0004EF`, `0x0054baa0`, `0054baa0`, `PrettyButtonControlPane2OnPaint`, `PrettyButtonControlPane2 OnPaint`, `PrettyButtonControlPane2::OnPaint`, `sub_54BAA0`, `0001F9`, `0000AS`, `0000MP`, `0002UX`, `sub_4D02F0`, `sub_457A60`, `sub_4B9980`, `sub_584540`, `EPFTileContext`, `RenderTileFrame`, `g_pEPFLib`, and disabled/frame/resource terms.
- Relevant old reports opened:
  - Executed B002 UID0004E8 class1 OnPaint report. Used as comparison evidence only; it proves the class1 overlay path and explicitly left UID0004EF for its own later pass.
  - Executed B011 UID0001F9 split report. Used as split/child inventory evidence for exact range ownership and no aggregate C++.
  - Executed B013 UID0004ED and B011 UID0004EC report matches. Used as class2 callback/selected-byte support context, not as target proof.
- Failed/unavailable checks:
  - Initial pre-override MCP attempts failed before supervisor restored MCP; those failures are not used as target evidence. After supervisor override, all MCP evidence above was collected from live session `9fb70afc`.
  - `xrefs_to` and `get_bytes` first failed with singular `addr` parameters; retried successfully with current schema's `addrs` and `regions` parameters.
  - `tools/leaser/Agents/Agent-B004/research/0004EE-PrettyButtonControlPane2SetVisualState-source-quality.md` did not exist when checked, so no active B004 report artifact was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| EF-C01 | UID0004EF should emit through direct class owner [UID:0000AS], not remain blank-emitter. | High | Owner already [UID:0000AS], vtable slot `0x006223c0 -> 0x0054baa0`, class/file emitter chain exists, helper/member blockers resolved. | Target metadata and C++ policy; class/file support notes; generated source after callback | incorporate | applied: target now has `EMITTER_UIDS:0000AS`; generated `PrettyButtonControlPane.cpp` command `000000005042` emits UID0004EF under `PrettyButtonControlPane2::OnPaint()` |
| EF-C02 | Exact range is `0x0054baa0-0x0054bb48`; adjacent `0x0054ba92-0x0054baa0` and `0x0054bb48-0x0054bb50` are `0xcc` padding. | High | `lookup_funcs` size `0xa8`; `get_bytes` padding checks. | Target evidence/range notes; parent split row if synchronized | incorporate | applied: target evidence and parent row record exact range, size `0xa8`, and pre/post padding |
| EF-C03 | Frame selection is disabled-frame first when `+0x101` is false, otherwise state byte `+0x11d` -> frame `+0x110`, selected byte `+0x11c` -> frame `+0x114`, default -> frame `+0x10c`. | High | Target decompile/disasm plus constructor and setter checks. | Target behavior/field table and C++ | incorporate | applied: target formal C++ and support rows preserve the disabled/state11/selected/normal frame order |
| EF-C04 | Resource strings are at `+0x120` for EPF/resource name and `+0x124` for palette name. | High | Constructor initializes strings at those offsets; paint passes them through `sub_584540` to lookup/render helpers. | Target field table and C++ | incorporate | applied: target field/helper table and C++ use `m_epfResourceName` and `m_paletteResourceName`; support docs cite `+0x120/+0x124` |
| EF-C05 | No disabled overlay branch exists in class2 OnPaint. | High | Target callee set lacks `0x004b9660`/Surface slot; disasm returns after `sub_4B9980`; disabled branch selects frame `+0x118`. | Target negative evidence and support comparison with UID0004E8 | incorporate | applied: target, class, file, parent, and vtable support explicitly reject the class1 overlay route |
| EF-C06 | Raise target from `84/88` to `88/90`; do not raise higher. | Medium-high | Behavior/emitter blockers resolved; original member spellings/class declaration remain inferred. | Target metadata and score rationale | incorporate | applied: target metadata is `COMPLETION:88`, `CONFIDENCE:90`; target score rationale keeps inferred-spelling confidence cap |
| EF-C07 | Parent [UID:0001F9] remains non-emitting split/index; no new split/child page is needed. | High | B011 split report and current parent inventory; target is already exact. | Parent/support docs only if callback sync is desired | already-present | applied: parent row synced while parent metadata, blank aggregate C++, and non-emitting split/index disposition remain unchanged |

## Positive Evidence Summary

- Direct MCP facts support the recommendation: exact target function, single vtable data xref, no direct callers, constructor field origins, state setter byte origin, render helper callee set, and padding boundaries are all current-session verified.
- Documentation evidence supports the source route: [UID:0000AS] is the direct class owner and emits through [UID:0000MP] into `NexusTK/ui/controls/PrettyButtonControlPane.cpp`; [UID:0002UX] records the matching vtable slot.
- The strongest inference chain is local and coherent: constructor supplies the four frame IDs and two resource strings; setter supplies one paint state byte; UID0004EC supplies the other selected byte; paint selects the frame, looks up the EPF layout, and renders through accepted helper roles.

## IDA MCP Facts

- Function/range facts: `lookup_funcs 0x0054baa0` returns `sub_54BAA0`, size `0xa8`, half-open range `0x0054baa0-0x0054bb48`.
- Vtable facts: `xrefs_to 0x0054baa0` reports one data xref from `0x006223c0`; `get_bytes 0x006223c0` returns `a0 ba 54 00`.
- Behavior facts: decompilation/disassembly select one of four frame fields, initialize a stack tile context, call the resource-layout lookup, then render through `sub_4B9980`.
- Boundary facts: bytes before and after the target are `0xcc` padding.
- Negative IDA facts: no direct code callers; no disabled-overlay helper call; no Surface callback dispatch; no separate owner or free-function route.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0054b8c0-0x0054b98d` | [UID:0004EA] class2 constructor | sets frame/resource/state/callback fields | true | [UID:0000AS] | `84/89` | support evidence |
| `0x0054b9e0-0x0054b9f9` | [UID:0004EC] class2 selected setter | writes selected byte `+0x11c` and invalidates | true | [UID:0000AS] | `88/90` | support evidence |
| `0x0054ba30-0x0054ba92` | [UID:0004EE] class2 visual-state setter | writes state-11 byte `+0x11d` and schedules timer | true | [UID:0000AS] | `84/88` current | support evidence |
| `0x0054ba92-0x0054baa0` | parent inventory only | padding | false | none | n/a | MCP refreshed |
| `0x0054baa0-0x0054bb48` | [UID:0004EF] target | class2 paint, EPF/PAL frame draw | true | [UID:0000AS] | `84/88` current, `88/90` recommended | should emit |
| `0x0054bb48-0x0054bb50` | parent inventory only | padding | false | none | n/a | MCP refreshed |
| `0x0054bb50-0x0054bb89` | [UID:0004EG] class2 click | click/notification | true | [UID:0000AS] | `84/88` | sibling evidence |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006223c0` | data xref to `0x0054baa0`; bytes `a0 ba 54 00` | class2 primary vtable paint slot |
| `0x0054b91f`, `0x0054b999`, `0x0054bbcc` | store refs to primary vtable base `0x0062237c` | class2 constructor/destructor/scalar-wrapper restore pattern |
| `0x0054baf7` | call `0x00457a60` | initializes local `EPFTileContext` |
| `0x0054bb01` / `0x0054bb07` | `this+0x120` string data via `sub_584540` | resource/EPF name for layout lookup |
| `0x0054bb0f` | call `0x004d02f0` | `g_pEPFLib`/ResourceLayoutTable lookup with selected frame |
| `0x0054bb16` / `0x0054bb1c` | `this+0x124` string data via `sub_584540` | palette name for rendering |
| `0x0054bb32` | call `0x004b9980` | shared tile/frame render helper |

## Documentation Evidence And IDA Status

- [UID:0004EF] already has correct direct owner and reconstructable state, but no emitter and no formal C++.
- [UID:0000AS] documents the method row as class2 `OnPaint`, currently blank pending resource/frame names.
- [UID:0000MP] documents the file route and says class2 method children keep C++ blank until class layout, field names, resource constants, and virtual names are accepted.
- [UID:0002UX] records vtable slot `0x006223c0` as the class2 paint slot and class2 vtable-base store xrefs.
- [UID:0004E8] / B002 is the class1 comparison: it emits class1 `OnPaint()` but has a disabled overlay branch. UID0004EF has a distinct disabled-frame path and must be documented separately.

## Ranked Ownership Analysis

### 1. [UID:0000AS] PrettyButtonControlPane2

- Evidence for: target is installed in class2 vtable slot `0x006223c0`, consumes class2 constructor fields, and shares state bytes with class2 methods UID0004EC and UID0004EE.
- Evidence against: exact original member spellings are inferred, but this affects confidence and final declaration polish rather than ownership.
- Decision: best direct owner and recommended emitter.

### 2. [UID:0000MP] PrettyButtonControlPane source file

- Evidence for: file root emits both styled button classes under `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- Evidence against: by-structure direct-owner rule prefers the class page for a method body; file page is the source route, not the narrow semantic owner.
- Decision: keep as source-file route through class owner.

### 3. [UID:0000HY] ButtonControlPane / inherited control layer

- Evidence for: class2 constructor calls the shared base button-control path and paint uses inherited bounds/state fields.
- Evidence against: base class is a dependency; target vtable slot and frame/resource fields belong to class2.
- Decision: rejected as direct owner.

### 4. ImageLib / ResourceLayoutTable / EPFTileContext / render helpers

- Evidence for: target calls their helpers.
- Evidence against: they are shared render/resource dependencies with broad callers; target owns no helper implementation.
- Decision: rejected as owner; cite as dependencies.

### 5. CreateUser dialog construction contexts

- Evidence for: class2 constructor has two direct callers in `0x0052c360` per support docs.
- Evidence against: construction consumers do not own this vtable paint method or class layout.
- Decision: rejected as owner; consumer context only.

## Source Placement

- Recommended source placement: `PrettyButtonControlPane2::OnPaint()` in `NexusTK/ui/controls/PrettyButtonControlPane.cpp`, routed through [UID:0000AS] and [UID:0000MP].
- Why this placement fits: method is a class2 vtable paint slot, uses class2-local frame/resource/state fields, and depends on generic render helpers already documented as shared dependencies.
- Rejected placements: `ButtonControlPane.cpp`, ImageLib/ResourceLayoutTable/EPFTileContext render files, and CreateUser dialog files.
- Remaining placement uncertainty: none material for this target.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `0x0054baa0-0x0054bb48`, size `0xa8`.
- Preceding padding: `0x0054ba92-0x0054baa0` is fourteen `0xcc` bytes.
- Following padding: `0x0054bb48-0x0054bb50` is eight `0xcc` bytes.
- No new split, merge, rename, or child page is recommended. [UID:0001F9] remains the non-emitting physical split/index parent.
- Rebuild handling: target is source-authored `.text`; vtable slot is source-declared/generated-binary data handled by the class declaration.

## Negative Evidence Summary

- No direct code callers were found; target is vtable-only. This supports method ownership rather than dialog-callsite ownership.
- No disabled overlay call sequence exists. The disabled path selects frame `+0x118`, unlike class1 UID0004E8 which calls `GrafPort::SetDrawColor`, writes draw mode, and dispatches Surface callback slot 7.
- No new source file is needed. Existing class/file route is already valid.
- No final-audit score is recommended. Original member names and exact declaration spelling remain inferred.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names for docs/formal C++:
  - `PrettyButtonControlPane2::OnPaint` for `sub_54BAA0`.
  - `m_normalFrameId` at `+0x10c`.
  - `m_pressedFrameId` or `m_state11FrameId` at `+0x110`; this is selected when byte `+0x11d` is active.
  - `m_selectedFrameId` at `+0x114`; this is selected when byte `+0x11c` is active and `+0x11d` is clear.
  - `m_disabledFrameId` at `+0x118`.
  - `m_selected` at `+0x11c`, matching UID0004EC.
  - `m_state11VisualActive` at `+0x11d`, matching the `0x0054ba30` state-11/timer path.
  - `m_epfResourceName` at `+0x120`.
  - `m_paletteResourceName` at `+0x124`.
  - inherited `m_enabled` / visible-enabled byte at `+0x101` and inherited `m_bounds` at `+0x44`.
- IDA DB edits: not requested and not performed.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID0004EF is reconstructable, has a confirmed owner route, should have nonblank `EMITTER_UIDS:0000AS`, and `(88 + 90) / 2 > 85` after accepted incorporation.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` insertion text for the target page:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int PrettyButtonControlPane2::OnPaint()
{
    int frameId;

    if (!m_enabled) {
        frameId = m_disabledFrameId;
    } else if (m_state11VisualActive) {
        frameId = m_pressedFrameId;
    } else if (m_selected) {
        frameId = m_selectedFrameId;
    } else {
        frameId = m_normalFrameId;
    }

    EPFTileContext tileContext;
    tileContext.Init();

    g_pEPFLib->LookupLayoutEntry(m_epfResourceName.c_str(), frameId, &tileContext);

    FrameDrawRecord drawRecord;
    return RenderTileFrame(&tileContext,
                           &drawRecord,
                           &m_bounds,
                           1,
                           m_paletteResourceName.c_str(),
                           0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves observed behavior: branch order, disabled-frame selection, state-frame selection, selected-frame selection, normal-frame fallback, EPF lookup, render arguments, and return value match current MCP decompilation/disassembly.
- Reason it matches plausible source shape: class method with member fields and shared helper calls, parallel to accepted class1 UID0004E8 source style but preserving class2's configured disabled-frame behavior.
- Inferred names/types: field names are descriptive source-quality names, not recovered original symbols. Future class declaration polish may refine them without changing behavior.
- Exact no-code proof if not eligible: not applicable.

## Final Recommendation

- Update target metadata: `COMPLETION:84 -> 88`, `CONFIDENCE:88 -> 90`, `CANONICAL_OWNER:0000AS` unchanged, `RECONSTRUCTABLE:TRUE` unchanged, `EMITTER_UIDS:` blank -> `0000AS`, formal C++ populated.
- Keep source placement through [UID:0000MP] `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- No split, rename, new child page, new owner page, or manual coverage/tracker edit is recommended.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md`.
- Incorporate current MCP evidence: session `9fb70afc`, health/session state, function size/range, vtable xref, no direct code callers, decompilation/disassembly branch order, constructor/setter support, helper names, byte padding, rejected owner alternatives, score rationale, and formal C++.
- Add a field/helper table for `+0x101`, `+0x10c`, `+0x110`, `+0x114`, `+0x118`, `+0x11c`, `+0x11d`, `+0x120`, `+0x124`, and `+0x44`.
- Preserve the historical blocker as superseded: old blank C++ was due to unresolved frame/resource/member names; this report resolves them to inferred source-quality names while capping confidence.

## Recommended Support Doc Changes

- `by-class/PrettyButtonControlPane2.md`: update UID0004EF row from blank pending resource/frame names to source-ready `PrettyButtonControlPane2::OnPaint()` emission through UID0000AS; add concise field/helper evidence and disabled-frame-vs-overlay distinction. Consider no class score change unless the supervisor wants a support-only sync.
- `by-file/PrettyButtonControlPane.md`: update the executable split inventory/source-output note to list UID0004EF as a class2 source-ready OnPaint method, preserving UID0001F9 as non-emitting split/index and keeping file metadata unchanged unless broader class2 support scoring is reviewed.
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`: optional sync only; update the UID0004EF row from generic `Paint` to source-ready class2 paint with configured disabled frame. Do not change parent reconstructable/emitter state.
- `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`: optional sync only; current slot evidence is already sufficient, but a callback may add that slot `0x006223c0` now points to source-ready/emitting UID0004EF. No score/owner/emitter change required.
- No edit recommended for `by-file/ButtonControlPane.md`, ImageLib/ResourceLayoutTable/EPFTileContext/GrafPort helper docs, or manual `-coverage-report.md` files.

## Score And Metadata Recommendation

- Current score/metadata: `84/88`, `CANONICAL_OWNER:0000AS`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Recommended score/metadata: `88/90`, `CANONICAL_OWNER:0000AS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AS`, formal C++ populated.
- Rationale:
  - Raise completion because this pass resolves the named blockers: frame/resource fields, member roles, disabled behavior, vtable route, helper roles, padding, emitter route, and formal C++ readiness.
  - Raise confidence because current MCP independently reconfirms behavior, range, xrefs, constructor/setter support, and negative disabled-overlay evidence.
  - Do not raise above `90` because exact original member spellings and final class declaration shape remain inferred.

## Open Questions With Attempted Resolution

- Whether blank emitter is still justified: resolved as no. Current MCP plus support docs prove enough behavior and source shape for a first-draft method body.
- Whether class2 has class1-style disabled overlay behavior: resolved as no. MCP confirms disabled state selects the configured frame `+0x118` and then follows the ordinary lookup/render path.
- Whether frame/resource constants are unknown literals: resolved as no. The constructor supplies frame ids and resource strings, so C++ should use fields.
- Whether `+0x11c` and `+0x11d` names are proven original spellings: partially resolved. Their behavior is proven; source-facing names are inferred and should cap confidence.
- Whether helper names are source-grade enough: resolved enough for this target through accepted support docs and class1 paint precedent.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. No manual `-coverage-report.md` or supervisor tracker edit is recommended during this report-only pass. Validator-owned generated reports should refresh from scoped target/support validators after an implementation callback.

## Follow-Up Actions

- Supervisor Gate 1 accepted this report for implementation callback.
- B005 applied accepted target/support edits under leases, updated this checklist/ledger, ran scoped validators, and is returning `READY_FOR_SUPERVISOR_EXECUTE`.
- No A-agent action is required for this report.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact original field/member spellings and final class declaration placement for the inferred names; not material to ownership, range, or emitter eligibility.

## Validator Results

- Target validator: command `000000005008`, timestamp `2026-07-03T02:47:54-04:00`, exit code `0`, `ok: 1`; validator applied autogen registry/completion/confidence/reference/projected-stats updates; `generated_refresh: deferred`.
- Class support validator: command `000000005030`, timestamp `2026-07-03T02:53:07-04:00`, exit code `0`, `ok: 1`; `generated_refresh: deferred`.
- Vtable support validator: command `000000005035`, timestamp `2026-07-03T02:54:11-04:00`, exit code `0`, `ok: 1`; `generated_refresh: deferred`.
- File support validator: command `000000005042`, timestamp `2026-07-03T03:02:24-04:00`, exit code `0`, `ok: 1`; `generated_refresh: deferred`.
- Parent split/index validator: command `000000005043`, timestamp `2026-07-03T03:02:24-04:00`, exit code `0`, `ok: 1`; `generated_refresh: deferred`.
- Queue/freshness check: command `000000005044`, timestamp `2026-07-03T03:02:59-04:00`, exit code `0`; worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- Relevant generated freshness observed: `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` refreshed at command `000000005042` and emits UID0004EF; `auto-generated/-ag-memory-coverage.md` refreshed at command `000000005043` and marks UID0004EF coded through `0000AS`.
- Unresolved validator warnings/errors: none observed in scoped validator outputs.

## Changed Files

- Created earlier: `tools/leaser/Agents/Agent-B005/research/0004EF-PrettyButtonControlPane2OnPaint-source-quality.md`.
- Modified by B005 implementation callback: `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md`, `by-class/PrettyButtonControlPane2.md`, `by-file/PrettyButtonControlPane.md`, `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`, `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`, and this report.
- Validator-owned generated outputs refreshed automatically; B005 did not hand-edit generated files or any manual/generated `-coverage-report.md`.
- Renamed: none.
- Leases used/released: target lease acquired and later already expired before release attempt; class support lease acquired/released; vtable support lease acquired/released; file and parent support leases acquired after B006 lease expiry and released. B005 has no active leases; a final post-release read showed B004 later acquired `by-file/PrettyButtonControlPane.md` and `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` through `2026-07-03T07:09:22Z`.
- Report execution: not run. B005 did not run `execute_report`, execute-report dry-run/probing/status variants, registry lifecycle commands, manual report moves, archive commands, or equivalents.

## Implementation Tracking Checklist

Implementation callback checklist after supervisor Gate 1 acceptance.

- [x] Supervisor Gate 1 validation required before any by-* implementation.
- [x] Target doc update: `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md`.
- [x] Target metadata update: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000AS` unchanged, `RECONSTRUCTABLE:TRUE` unchanged, `EMITTER_UIDS:0000AS`.
- [x] Target formal C++ insertion: exact `PrettyButtonControlPane2::OnPaint()` block from `## First-Draft C++ Recommendation`.
- [x] Target evidence incorporation: MCP session `9fb70afc`, function size/range, vtable xref, no direct callers, decompile/disasm behavior, constructor/setter support, helper roles, padding bytes, and rejected owners.
- [x] Target field/source-quality table: `+0x101`, `+0x10c`, `+0x110`, `+0x114`, `+0x118`, `+0x11c`, `+0x11d`, `+0x120`, `+0x124`, and `+0x44`, with inferred-name caveats.
- [x] Preserve negative evidence: no class1 disabled-overlay path; no `GrafPort::SetDrawColor`, no `+0x70` draw-mode write, no Surface slot `0x0069b3fc` dispatch.
- [x] Support sync if accepted: `by-class/PrettyButtonControlPane2.md` UID0004EF row/method notes.
- [x] Optional support sync if accepted and stale: `by-file/PrettyButtonControlPane.md`, `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`, and `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`.
- [x] Claim And Incorporation Ledger update during callback: set every accepted claim to `applied`, `already-present`, or `excluded-with-reason` with proof.
- [x] Scoped validator for changed target after callback: `python .\tools\validator.py --mode file --file by-memory\0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md --apply --queue-timeout 240`.
- [x] Scoped validators for each changed support doc after callback.
- [x] Generated refresh check after validators if target begins emitting: confirm generated memory coverage and `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` are refreshed at or after the returned validator command metadata.
- [x] Do not edit generated reports, generated C++, project-level generated reports, manual coverage reports, validator state, queues, archives, or supervisor ledgers by hand.
- [x] Do not run `execute_report` or any lifecycle/archive command; supervisor owns final report execution after Gate 2.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000005056","destination_path":"executed-b-agent-research/B005/0004EF-PrettyButtonControlPane2OnPaint-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0004EF-PrettyButtonControlPane2OnPaint-source-quality.md","timestamp":"2026-07-03T03:19:20-04:00","uid":"0004EF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
