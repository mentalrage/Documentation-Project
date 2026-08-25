** TARGET-REPORT-UID:0003N9 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003N9 **
# 0003N9 ControlPaneDrawActiveFrameHelper MCP Source-Quality Redo

Report-only B-agent research for supervisor review. I did not edit target/support by-* docs, generated/project-level files, IDA DB/tool state, or any `-coverage-report.md` file. This report supersedes the prior moved-back report text for [UID:0003N9] with current IDA MCP evidence from active session `261fb29b`.

## Finalized Report / Current Recommendation

- Target: [UID:0003N9] `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`.
- Assignment ID: `B001-redo-controlpane-draw-active-frame-helper-source-quality-0003N9-mcp-20260623`.
- Current and recommended metadata: keep `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP`.
- C++ recommendation: keep formal C++ blank. The helper is source-shaped and ControlPane-owned, but current MCP still finds no function object, no source-grade caller/entry route, no data/table/vtable pointer to the start, and no declaration/name proof.
- Implementation recommendation: no by-* edits required. The current target/support docs already contain the valid facts at same-or-greater detail: exact range, bytes/signature, six-byte pre-padding, successor boundary, no-function/no-xref/no-vtable/no-pointer/no-branch route, ControlPane owner/emitter route, rejected owners, field/helper meanings, best future `ControlPane::DrawActiveFrame()` source-name candidate, score rationale, and no-code proof. Adding session `261fb29b` to by-* docs would be an audit-trail note only, not a missing factual claim.
- Supervisor-owned coverage text: none. Current `by-memory/-coverage-report.md` already has the matching nested `0003N9` row and should remain unchanged.

## Target

- Target UID: `0003N9`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`.
- Current score: `85/86`.
- Direct owner/emitter: [UID:000038] `ControlPane`, emitted through [UID:0000IG] `ControlPane` / `auto-generated/NexusTK/ui/core/ControlPane.cpp`.
- Current generated output: `auto-generated/NexusTK/ui/core/ControlPane.cpp` contains `// UID:0003N9 ... Completion:85 | Confidence:86 | Empty Emitter Marker`.
- Physical parent/container: [UID:0002PD] `0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers`, a non-reconstructable/non-emitting mixed aggregate.

## Current Target State

The target page already records this as a raw/unpromoted source-authored candidate helper with no IDA function object. It documents the exact behavior: check `this+0x101` and `this+0x102`, push color `0x80`, call `0x004b9660`, clear inherited GrafPort draw/blit mode byte `this+0x70`, pass `this+0x44` to `0x004ba450`, then return.

The current support chain is also synchronized:

- [UID:000038] `by-class/ControlPane.md` lists `0003N9` as an active-frame helper over local visible/active state bytes with C++ blank because no function object, xrefs, vtable slot, pointer encoding, or caller/declaration evidence exists.
- [UID:0000IG] `by-file/ControlPane.md` routes the raw helper through `NexusTK/ui/core/ControlPane.cpp` as an empty marker and preserves the rejected ProgressBar/Button/GrafPort/no-owner routes.
- [UID:0002PD] aggregate lists the child as `ControlPane`-owned source-shaped raw helper, while the aggregate itself remains non-emitting.
- [UID:000162] and [UID:000168] describe the helper callees as `GrafPort` draw-state and rectangle-frame primitives.
- [UID:0003J8]/[UID:0003J9] record the ControlPane vtable data/type pages and do not contain a slot for `0x00494c50`.

## MCP Evidence Pass

Current MCP session and readiness:

- Endpoint used: `http://127.0.0.1:13337/mcp`.
- Session used: `261fb29b`.
- `idb_list`: one active owned/adopted worker session, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, `pid:12132`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `tools/list`: read-only tools used included `lookup_funcs`, `entity_query`, `get_bytes`, `make_signature_for_range`, `xrefs_to`, `xref_query`, `insn_query`, `decompile`, `disasm`, `callees`, `find`, `find_bytes`, `search_text`, `get_int`, and `analyze_function`.

Function and boundary evidence:

- `lookup_funcs`:
  - `0x00494c30`: `sub_494C30`, size `0x1a`.
  - `0x00494c4a`: not a function.
  - `0x00494c50`: not a function.
  - `0x00494c51`: not a function.
  - `0x00494c53`: not a function.
  - `0x00494c7e`: not a function.
  - `0x00494c80`: `sub_494C80`, size `0x12a`.
  - `0x004b9660`: `sub_4B9660`, size `0x0d`.
  - `0x004ba450`: `sub_4BA450`, size `0xeb`.
- `entity_query functions 0x00494a80-0x00494ec0`: modeled starts are `0x00494b50`, `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494bf0`, `0x00494c00`, `0x00494c10`, `0x00494c30`, `0x00494c80`, `0x00494de0`, and `0x00494eb0`; no function starts at `0x00494c50`.
- `get_bytes 0x00494c4a size 54`: six `0xcc` bytes followed by the full helper body.
- `get_bytes 0x00494c80 size 16`: successor begins `55 8B EC 6A FF ...`, matching a normal prologue for `sub_494C80`.
- `make_signature_for_range 0x00494c50-0x00494c80`, `wildcard_operands:false`: signature is unique and exactly `56 8B F1 80 BE 01 01 00 00 00 74 22 80 BE 02 01 00 00 00 74 19 68 80 00 00 00 E8 F1 49 02 00 8D 46 44 C6 46 70 00 50 8B CE E8 D2 57 02 00 5E C3`.
- `int_convert.py`: decimal `48` is `0x30` and decimal `128` is `0x80` (Verified with `int_convert.py`).

Scoped disassembly/decompile/callee evidence:

```text
0x00494c4a  align 10h
0x00494c50  push esi
0x00494c51  mov esi, ecx
0x00494c53  cmp byte ptr [esi+101h], 0
0x00494c5a  jz short loc_494C7E
0x00494c5c  cmp byte ptr [esi+102h], 0
0x00494c63  jz short loc_494C7E
0x00494c65  push 80h
0x00494c6a  call sub_4B9660
0x00494c6f  lea eax, [esi+44h]
0x00494c72  mov byte ptr [esi+70h], 0
0x00494c76  push eax
0x00494c77  mov ecx, esi
0x00494c79  call sub_4BA450
0x00494c7e  pop esi
0x00494c7f  retn
```

- `insn_query 0x00494c4a-0x00494c80` returns the alignment directive plus sixteen raw helper instructions, all with `fn:null`.
- `disasm 0x00494c50` labels the item as `<no function>` and decodes the raw helper before continuing into the successor `sub_494C80`; this confirms decode shape but not a modeled function.
- `decompile 0x00494c50`: `Decompilation failed at 0x494c50`.
- `callees 0x00494c50`: `No function found`.
- The outgoing calls are therefore body/disassembly facts, not IDA function-callee facts.

Xref and route evidence:

- `xrefs_to 0x00494c50`: zero xrefs, message `No cross-references to this address`.
- `xrefs_to 0x00494c51`: one local flow xref from `0x00494c50`.
- `xrefs_to 0x00494c53`: one local flow xref from `0x00494c51`.
- `xrefs_to 0x00494c7e`: three local code xrefs from `0x00494c79`, `0x00494c5a`, and `0x00494c63`; the meaningful branch facts are the two short early exits, plus local fall-through after the draw call.
- `xrefs_to 0x00494c80`: one code xref from `0x005472d7` inside `sub_5470B0`, confirming the successor constructor has a normal entry route while `0003N9` does not.
- `find code_ref`: no hits for `0x00494c50`, `0x00494c51`, or `0x00494c53`; only internal hits to `0x00494c7e`, one hit to successor `0x00494c80`, six hits to positive-control neighbor `0x00494b80`, and two hits to positive-control neighbor `0x00494c30`.
- `find data_ref`: no hits for `0x00494c50`, `0x00494c51`, `0x00494c53`, `0x00494c7e`, or `0x00494c80`; positive-control neighbors `0x00494b80` and `0x00494c30` return vtable/table data refs including `0x00617ad8` and `0x00617aec`.
- `find immediate`: no hits for `0x00494c50`, `0x00494c51`, `0x00494c53`, `0x00494c7e`, `0x00494c80`, `0x00494b80`, or `0x00494c30`.
- `find_bytes`: no hits for absolute-VA bytes `50 4C 49 00`, RVA bytes `50 4C 09 00`, or plausible interior/exit/successor pointer bytes `51 4C 49 00`, `53 4C 49 00`, `7E 4C 49 00`, and `80 4C 49 00`.
- `search_text 0x00494a80-0x00494ec0` for `00494C50`: one local listing hit at `.text:00494C50 push esi`; no source/debug/name route.

Vtable/table evidence:

- `get_int` selected ControlPane vtable cells:
  - `0x00617ad8 -> 0x00494b80`.
  - `0x00617adc -> 0x00494bb0`.
  - `0x00617ae0 -> 0x00494bd0`.
  - `0x00617ae4 -> 0x00494c00`.
  - `0x00617ae8 -> 0x00494c10`.
  - `0x00617aec -> 0x00494c30`.
  - `0x00617af0 -> 0x0041d690`.
  - `0x00617b30 -> 0x0064590c` (ProgressBarControlPane RTTI/locator boundary).
  - `0x00617b34 -> 0x0049b170`, `0x00617b9c -> 0x0049af3d`, `0x00617bcc -> 0x0049af48` for ProgressBarControlPane vtable starts/adjustor slots.
- The decimal values above were converted with `tools/int_convert.py` (Verified with `int_convert.py`).
- There is no selected ControlPane slot to `0x00494c50`, and the broader `find data_ref` / `find_bytes` checks find no table or raw pointer route to the helper start.

Callee/helper meaning evidence:

- `analyze_function 0x004b9660`: one-block `__thiscall` leaf storing the argument to `[ecx+0x74]`, matching a reusable GrafPort draw/fill color state setter.
- `decompile 0x004b9660`: `this[29] = a2`, which is object offset `0x74`.
- `analyze_function 0x004ba450`: `sub_4BA450`, size `0xeb`, broad caller set, one explicit rectangle pointer argument, reads draw-enabled state, clips/intersects a 16-byte rectangle, calls draw-line callback four times, and restores cursor fields; this matches [UID:000168] `GrafPort::DrawRectFrame`.
- `decompile 0x004ba450`: confirms rectangle-frame semantics over the supplied 16-byte rectangle argument.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Status |
| --- | --- | --- | --- |
| `0x00494c4a-0x00494c50` | [UID:0000VN] `by-memory/-ignored.md` | Six-byte alignment padding | Keep ignored; MCP bytes show `0xcc` run / `align 10h`. |
| `0x00494c50-0x00494c80` | [UID:0003N9] target | Raw active/focus frame draw helper | Keep reconstructable, `ControlPane` owner/emitter, blank C++. |
| `0x00494c80-0x00494daa` | [UID:000119] `ProgressBarControlPaneConstructor` | Successor constructor | Separate successor; has normal function object and one code xref. |

No split, merge, range repair, or child creation is supported. The only internal branch target is the shared epilogue at `0x00494c7e`.

## Behavior And Data Flow

Confirmed behavior:

- Receiver is in `ECX`, copied to `ESI`.
- `this+0x101` must be nonzero or the helper returns.
- `this+0x102` must be nonzero or the helper returns.
- Immediate `0x80` is passed to `0x004b9660`, the draw/fill color setter for GrafPort state offset `+0x74`.
- `this+0x44` is passed as the rectangle pointer to `0x004ba450`, currently reconstructed as `GrafPort::DrawRectFrame(const RectBounds *rect)`.
- `this+0x70` is cleared to `0` immediately before the frame call; current docs correctly treat this as inherited GrafPort draw/blit mode, not a local ControlPane boolean.

Best current field/helper meanings:

| Field/helper | Current source-quality meaning | Status |
| --- | --- | --- |
| `this+0x101` | ControlPane-local visible/shown state byte | Strong meaning, final spelling provisional. |
| `this+0x102` | ControlPane-local active/focus state byte | Strong meaning, final spelling provisional. |
| `this+0x44` | inherited bounds rectangle | Strong meaning, likely `m_bounds` / `RectBounds`, final spelling provisional. |
| `this+0x70` | inherited GrafPort draw/blit mode byte | Strong meaning, best prose `m_drawMode`, final spelling provisional. |
| `0x004b9660` | GrafPort draw/fill color setter storing to `this+0x74` | Confirmed by current MCP decompile. |
| `0x004ba450` | GrafPort rectangle-frame drawer | Confirmed by current MCP decompile and [UID:000168]. |
| immediate `0x80` | active/focus/frame color index 128 | Meaning strong; named palette constant not proven. |

## Positive Evidence Summary

- Current MCP confirms the raw body decodes cleanly as a coherent `thiscall` helper despite no IDA function object.
- The exact `0x30`-byte signature is unique under MCP `make_signature_for_range`.
- The helper uses base `ControlPane` state bytes `+0x101/+0x102`, inherited bounds `+0x44`, and inherited draw-mode byte `+0x70`.
- The two outgoing calls are to shared GrafPort draw-state and frame-drawing support.
- The helper sits after modeled/assigned base `ControlPane` active-state virtual/helper code and before the `ProgressBarControlPane` constructor boundary.
- Current support docs and generated output consistently route the target through [UID:000038] `ControlPane` while keeping C++ blank.

## Negative Evidence Summary

- Current MCP finds no function object at `0x00494c50`, `0x00494c51`, `0x00494c53`, or `0x00494c7e`.
- Current MCP finds no code or data xrefs to `0x00494c50`.
- Current MCP `find code_ref` finds no caller/branch route to the helper start or plausible interior entries.
- Current MCP `find data_ref` and `find_bytes` find no table, pointer, VA, or RVA route to `0x00494c50`, `0x00494c51`, `0x00494c53`, or `0x00494c7e`.
- Selected current MCP vtable dwords point to the modeled ControlPane state helpers and fixed virtual, then to ProgressBarControlPane boundary data; none point to `0x00494c50`.
- `decompile`, `callees`, and function-level analysis cannot operate on `0x00494c50` because it is not an IDA function.
- No source/debug/source-file declaration evidence or final source spelling for the helper/fields/color constant was found.

## Heuristic / Inference Reanalysis And Validation

Claim: `0x00494c50-0x00494c80` is one exact raw helper.

- Confidence: confirmed.
- Evidence: MCP bytes, unique signature, scoped disassembly, no internal independent entry, `retn` at `0x00494c7f`, successor prologue at `0x00494c80`.
- Counter-evidence checked: function inventory, interior lookup, xrefs, code refs, data refs, raw pointer bytes.
- Remaining uncertainty: none for the half-open range.

Claim: direct semantic owner remains `ControlPane`.

- Confidence: strongly inferred.
- Evidence: `+0x101/+0x102` are ControlPane-local visible/active state bytes; sibling ControlPane helpers set/clear these bytes; the helper draws inherited bounds through shared GrafPort primitives; support docs and generated output already route through ControlPane.
- Counter-evidence checked: ProgressBar adjacency, Button/choice family adjacency, GrafPort primitive dependency, no-owner historical route, vtable data.
- Remaining uncertainty: exact source declaration and liveness route.

Claim: no source-grade entry route is currently proven.

- Confidence: confirmed for checked static routes.
- Evidence: current MCP no function, no xrefs to start, no code_ref/data_ref/immediate/VA/RVA hits, no vtable slot, no decompile/callee object.
- Counter-evidence checked: positive controls show code/data refs for neighboring helpers and successor constructor, so the zero result for `0x00494c50` is meaningful.
- Remaining uncertainty: an indirect runtime-only route, intentionally retained dead helper, or lost source declaration could still exist but is not evidenced.

Claim: best future source-facing name is `ControlPane::DrawActiveFrame()`.

- Confidence: medium inference.
- Evidence: body draws a frame only when local visible and active/focus state bytes are set.
- Counter-evidence checked: `DrawActiveFrameHelper`, virtual method route, standalone free helper, ProgressBar/Button/GrafPort names.
- Remaining uncertainty: no caller/source declaration proves the exact spelling or method visibility.

Claim: formal C++ should remain blank.

- Confidence: strong.
- Evidence: no route/declaration/final-name proof despite source-shaped behavior and valid owner/emitter route.
- Counter-evidence checked: reference-only body is mechanically simple, but inserting it would overstate source liveness and declaration shape.
- Remaining uncertainty: could change only after caller/table/vtable/source declaration recovery or an explicit retained-helper emission policy.

## Ranked Ownership And Source-Placement Analysis

### 1. [UID:000038] `ControlPane`

- Evidence for: target gates on ControlPane local state bytes; sibling helpers define the same state field family; inherited bounds/draw state use is normal for a `ControlPane` drawing helper; current support docs and generated marker already use this route.
- Evidence against: no function object, caller, table, vtable slot, or original source declaration.
- Decision: keep as owner/emitter. The negative route evidence blocks formal C++, not semantic ownership.

### 2. `ProgressBarControlPane`

- Evidence for: successor constructor starts immediately after `0x00494c80`.
- Evidence against: target ends before the constructor, has six-byte pre-padding, does not touch ProgressBar fields, and current MCP shows no slot/pointer/data route to this raw helper.
- Decision: reject.

### 3. `GrafPort`

- Evidence for: the helper calls GrafPort draw-state and rectangle-frame methods and touches inherited draw state.
- Evidence against: policy gates are ControlPane state bytes; behavior is active-control frame policy, not a generic primitive GrafPort API.
- Decision: reject as direct owner; keep GrafPort as dependency owner for callees/fields.

### 4. Button/concrete-control owners

- Evidence for: analogous raw frame helpers exist in nearby concrete control families.
- Evidence against: no button, choice, radio, selection, or concrete-control-only fields are used; current boundaries place those families elsewhere.
- Decision: reject.

### 5. `CANONICAL_OWNER:NONE` / non-emitting

- Evidence for: old no-owner reports were reasonable under stricter caller-required policy.
- Evidence against: current raw-helper policy and docs allow owner routing from strong field/source-family evidence; no-owner would now discard meaningful ControlPane ownership.
- Decision: reject as current metadata, preserve only as historical policy context and final-C++ caution.

Recommended source placement remains [UID:0000IG] `NexusTK/ui/core/ControlPane.cpp`. No standalone helper file, `ProgressBarControlPane.cpp`, `ButtonControlPane.cpp`, or `GrafPort.cpp` placement is supported.

## Source-Facing Names, Types, And Constants

- Keep documentation label `ControlPaneDrawActiveFrameHelper`.
- Best future source-facing declaration candidate: `ControlPane::DrawActiveFrame()`.
- Do not promote `DrawActiveFrameHelper` or `ControlPaneDrawActiveFrameHelper` as final source spelling.
- Keep `this+0x101`, `this+0x102`, `this+0x44`, and `this+0x70` final field spellings provisional. Their meanings are strong, but exact original names are not proven.
- Keep immediate `0x80` as active/focus/frame color index 128. Do not invent a named palette constant without broader palette-table proof.
- No IDA rename/type/comment edits are requested.

## First-Draft C++ Recommendation

Formal `RECONSTRUCTION_CPP` should remain blank.

Reference-only future shape, not for insertion:

```cpp
// Reference only. Do not emit for [UID:0003N9] until a caller/source
// declaration or retained-helper source policy is proven.
void ControlPane::DrawActiveFrame()
{
    if (!m_controlVisible || !m_controlActive) {
        return;
    }

    SetDrawColor(128);
    m_drawMode = 0;
    DrawRectFrame(&m_bounds);
}
```

No-code proof: the helper has a valid semantic owner and a simple recoverable body, but current MCP still shows no IDA function, no entry xrefs, no vtable/table/pointer route, no decompilable function object, and no original source declaration. Adding formal C++ now would represent an unproven callable `ControlPane` method and could convert retained/dead raw code into polluted pseudo-source.

## Score And Metadata Recommendation

- Keep target `COMPLETION:85`, `CONFIDENCE:86`.
- Keep `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000038`.
- Keep split/range unchanged: `0x00494c50-0x00494c80`.
- Keep C++ blank.

Reason not higher:

- Current MCP adds provenance, not a new positive source route.
- Function object, caller, table/vtable slot, pointer/ref route, source declaration, final helper spelling, and final field/constant names remain unresolved.

Reason not lower:

- Current MCP strongly confirms exact range, source-shaped body, unique signature, field/helper meanings, ControlPane semantic ownership, and meaningful no-route controls.
- Target/support docs and generated output are internally consistent.

## Documentation Gap / Incorporation Analysis

No by-* implementation edits are recommended.

Current target/support docs already contain same-or-greater factual detail for:

- Exact bytes and `0x30` size.
- Six `0xcc` bytes at `0x00494c4a-0x00494c50`.
- Successor function at `0x00494c80`.
- No IDA function object.
- No xrefs to the start.
- No vtable slot, pointer, direct branch/call route.
- ControlPane owner/emitter/source placement.
- Field/helper meanings for `+0x101`, `+0x102`, `+0x44`, `+0x70`, `0x004b9660`, `0x004ba450`, and `0x80`.
- Rejected ProgressBar, Button/concrete-control, GrafPort-owner, standalone-file, and no-owner routes.
- Best future `ControlPane::DrawActiveFrame()` name.
- Blank-C++ rationale.

The only difference is audit provenance: this report uses current MCP session `261fb29b`. Because the facts are the same, no by-* edit is needed unless the supervisor wants an optional dated audit note. I do not recommend that optional note because it would not improve target facts or score.

## Exact Supervisor-Owned Coverage Text

- File/placement: none.
- Exact replacement/insert/delete text: none.
- Reason: current `by-memory/-coverage-report.md` already contains a nested [UID:0003N9] row under [UID:0002PD] with `85%`, reconstructable, ControlPane route, no-function/xrefs/vtable/pointer/direct-branch route, and blank-C++ disposition. No coverage edit is needed.

## Validators Expected After Implementation

- No validators are required for this report-only no-change recommendation because no by-* docs should be edited.
- If the supervisor nevertheless requests an optional target audit note, run:

> Executable block R001 was removed from this report and preserved verbatim in [0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md](0003N9-ControlPaneDrawActiveFrameHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validate any additional touched support doc individually if a later callback explicitly authorizes edits.

## Open Questions With Attempted Resolution

- Raw helper reachability: current MCP no-function/no-xref/code_ref/data_ref/immediate/find_bytes/vtable checks found no source-grade entry route. This remains the main score/C++ blocker.
- Helper declaration shape: `ControlPane::DrawActiveFrame()` is the best candidate, but no caller/source declaration proves member visibility, exact spelling, or whether it was retained unused code.
- Final field names: meanings for `+0x101`, `+0x102`, `+0x44`, and `+0x70` are strong, but original field names remain provisional.
- Color constant: `0x80` / 128 is an active/focus/frame color index; no named palette constant is proven.
- Ownership: current MCP supports keeping ControlPane over alternatives; no ownership change is recommended.

## Changed Files

- Updated report only: `tools/leaser/Agents/Agent-B001/research/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md`.
- No by-* docs, generated/project-level files, IDA DB/tool state, or `-coverage-report.md` files were changed.

## Implementation Tracking Checklist

Initial report-only MCP redo:

- [ ] Supervisor validation required before any implementation callback.
- [ ] Target/support docs to update: no required by-* update; current target and support docs already contain the accepted facts at same-or-greater detail. Optional dated MCP-audit note is not recommended because it would not add a missing factual claim.
- [ ] Current MCP-backed evidence recorded: session `261fb29b` health/listing, function/no-function state, bytes/signature, scoped disassembly, decompile/callee no-function result, xrefs/code_ref/data_ref/immediate/find_bytes no-route checks, positive neighbor controls, vtable dwords, callee analyses, generated marker, coverage row, and current target/support docs are recorded in this report.
- [ ] Metadata/score changes to apply: none; keep `COMPLETION:85`, `CONFIDENCE:86`.
- [ ] Owner/emitter/reconstructable changes to apply: none; keep `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`.
- [ ] Split/rename/new-child changes to apply: none; keep exact half-open range `0x00494c50-0x00494c80`; keep `0x00494c4a-0x00494c50` ignored padding; do not create child splits.
- [ ] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: confirm not applicable; source placement remains `NexusTK/ui/core/ControlPane.cpp`; no IDA DB edits requested.
- [ ] First-draft C++ or no-code proof to apply: keep formal C++ blank; no-code proof is no function object, no source-grade caller/table/vtable/pointer route, no declaration proof, and provisional names despite a simple source-shaped body.
- [ ] Exact target/support doc facts to incorporate at report-level detail: no incorporation required because target/support docs already include the valid facts at same-or-greater detail; if supervisor requests a dated audit note, add only that note to the target and validate it.
- [ ] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: current docs already preserve older no-owner reports as superseded metadata, stale `FUN_00494c50`/`sub_494C50` labels as aliases only, rejected ProgressBar/Button/GrafPort/no-owner/source-file alternatives, and no-function/xref/pointer/branch/vtable evidence.
- [ ] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: stale `FUN_00494c50`/`sub_494C50` entries in `by-memory/-report.old.md` and `project-level/-unresolved.md` remain unresolved alias noise only; no Wave2/Wave3 evidence was used as authority.
- [ ] Open questions to close or document as evidence-backed unresolved: reachability, declaration shape, final field names, `0x80` constant name, and retained-helper source policy remain evidence-backed unresolved with score/C++ impact.
- [ ] Validators to run after accepted implementation: none for the recommended no-change disposition; run scoped validator only if a later callback authorizes an optional by-* note.
- [ ] Supervisor-owned coverage-report/tracker text to apply: none; current coverage already matches this disposition and B001 must not edit `-coverage-report.md` files.

Implementation callback pass:

- [ ] Report accepted by supervisor for implementation:
- [ ] All accepted target/support doc details incorporated at report-level detail or checked as already present:
- [ ] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason:
- [ ] Historical/stale assumptions, rejected alternatives, and negative evidence preserved:
- [ ] Open questions resolved or documented with evidence-backed unresolved rationale:
- [ ] Validators run and results recorded:
- [ ] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged:
- [ ] Remaining unapplied accepted items listed with exact blocker:

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003N9","source_path":"executed-b-agent-research/B001/0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
