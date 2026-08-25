** TARGET-REPORT-UID:0002PH **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 0002PH SoftwareRenderCompatSpriteBlitCallback Source-Quality Report

## Target

- Target UID: `0002PH`
- Target path: `by-memory/0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md`
- Assignment: `B012-report-0002PH-SoftwareRenderCompatSpriteBlitCallback-20260702`
- Mode: report-only research. No by-* docs, generated files, validator state, archives, or supervisor files were edited.
- Current target role: compat/RGB555 implementation for `SurfaceRenderCallbackTable` slot `0x0069b3e8` / `dword_69B3E8`.

## Current Target State

- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank formal C++.
- Current generated/research tracker row: `auto-generated/-ag-research-tracker.md` lists UID0002PH as `85/88`, average `86.5`, reconstructable `true`, direct report count `0`, and no executed report coverage.
- Current owner/emitter route is already valid: [UID:0000OC] `Surface` is `88/85`, routes to `NexusTK/render/Surface.cpp`, and already lists UID0002PH as an exact compat callback child. [UID:0000TN] and [UID:0001PI] document slot 2 as Surface-owned callback dispatch routed through Surface.
- Current target page is mostly accurate but stale/incomplete in three source-quality areas:
  - it still has legacy prose using `AUTOGEN_PARENT_UID` rather than current `CANONICAL_OWNER` / `EMITTER_UIDS`;
  - it does not carry the newer accepted slot-2 typedef direction from July 2 support docs: `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, `int` return, destination receiver in `ecx`, and nullable `const SurfaceSpriteBlitOptions *options`;
  - it does not record the compat target's current MCP option-pointer reads from the final stack argument at selector `+0`, palette/tint byte `+8`, and dword `+0x0c`.

## Evidence Checked

- Required docs read:
  - `tools/leaser/Agents/Agent-B012/goal.md`
  - project skill `ntk-b-agent-workflow`
  - `references/b-agent-research-and-implementation-workflow.md`
  - `references/score-blocker-audit-standard.md`
  - `by-structure.md`, especially IDA MCP discipline and current owner/emitter/C++ gate wording
  - target page `by-memory/0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md`
- Support docs read:
  - `by-file/Surface.md`
  - `by-global/SurfaceRenderCallbackTable.md`
  - `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
  - `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`
  - `by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md`
  - `by-file/SoftwareBlend16.md`
- Tracker/support evidence:
  - `auto-generated/-ag-research-tracker.md`, row for UID0002PH.
- Prior-report search terms:
  - `0002PH`, `0x004bc090`, `004bc090`, `SoftwareRenderCompatSpriteBlitCallback`, `sub_4BC090`, `dword_69B3E8`, `SurfaceRenderCallbackTable`, `SoftwareRenderCompatCallbacks`, `00041R`, `00041U`, `ItemObjImageLibDrawItemImage`, and `ItemObjImageLibDrawItemImageScaled`.
- Relevant prior reports opened or checked:
  - `executed-b-agent-research/B001/00016J-SoftwareRenderCompatCallbacks.md`
  - `executed-b-agent-research/B005/0000OC-Surface-empty-emitter-family-source-quality.md`
  - `executed-b-agent-research/B003/00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md` was found by search as the accepted July 2 UID00041R support repair; the current table docs already incorporate its slot-2 result.
  - Exact guessed paths for non-existent `00041U-ItemObjImageLibDrawItemImageScaled-source-quality.md` and `00041R-ItemObjImageLibDrawItemImage-source-quality.md` were checked and failed; this is nonblocking because current by-* support docs and the UID00041R executed report carry the accepted evidence.
- IDA MCP current session:
  - `initialize` and `tools/list` succeeded.
  - `idb_list` returned active database `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`.
  - `py_eval` is not available in this MCP build; all MCP evidence below uses schema-current bounded `lookup_funcs`, `analyze_function`, `xrefs_to`, `callees`, `disasm`, and `search_text`.
- IDA MCP calls used:
  - `lookup_funcs` for `0x004bc090`, `0x004bd3e8`, `0x004c0f80`.
  - `analyze_function` for `0x004bc090`, `include_asm:false`.
  - `xrefs_to` for `0x004bc090` and `0x0069b3e8`, using current `addrs` parameter.
  - `callees` for `0x004bc090`, using current `addrs` parameter.
  - bounded `disasm` pages for `0x004bc090` at offsets `0`, `120`, `1620`, and nearby sampled offsets.
  - bounded `search_text` over `0x004bc090-0x004bd3e8` for `arg_14`, `[ebp+arg_14]`, `[eax+8]`, `[eax+0Ch]`, and switch-table boundary text.

## Positive Evidence Summary

- Current MCP `lookup_funcs` reconfirms `sub_4BC090` at `0x004bc090` with size `0x1358`; `0x004bd3e8` is not a function start; RGB565 peer `sub_4C0F80` remains at `0x004c0f80` with size `0x21a3`.
- Current MCP `analyze_function` reports `sub_4BC090` size `4952`, `280` basic blocks, cyclomatic complexity `159`, no direct callers, target xrefs from `0x00558740` and `0x00558b94`, and callees matching the target page: `sub_516030`, palette helpers `0x00543d40` / `0x00543d20`, clip/rect helpers `0x004b96c0`, `0x004b7cc0`, `0x004b7eb0`, `_memmove`, `BlendRgb555` at `0x004c0710`, and RGB555/compat helpers `0x0045fa00`, `0x0045fb80`, `0x0045fe40`.
- Current MCP `xrefs_to 0x004bc090` gives exactly two data refs: raw/setup `0x00558740` and `sub_558840` at `0x00558b94`. This preserves callback-table target status and rejects ordinary feature-method ownership.
- Current MCP `xrefs_to 0x0069b3e8` returns at least the first 100 refs with `more:true`; representative refs include render wrappers at `0x004b9910`, `0x004b9980`, `0x004b99f0`, `0x004ba250`, `0x004ba6b0`, ItemObjImageLib draw paths at `0x004dee50` and `0x004df2c0`, BlueAlertPane at `0x00500e20`, MapTileImageLib at `0x004d1a20`, and initializer refs at `0x00558b94` / `0x00558eb0`. The current support docs retain the full historical `114` direct-ref count.
- Current bounded disassembly reconfirms the early callback shape: saves `ecx` as destination receiver, checks destination draw-enabled byte `[ecx+0x71]`, checks source descriptor `[edi]`, falls back through `dword_67A7E0` / `0x00543d40` when the palette argument is null, calls `0x00543d20`, fetches the active clip rectangle through `0x004b96c0`, intersects rectangles with `0x004b7cc0` / `0x004b7eb0`, and computes source/destination row pointers before dispatch.
- Current bounded disassembly reconfirms the top-level mode switch on `arg_C` at `0x004bc215-0x004bc21e`, including `jpt_4BC21E` at `0x004bd3e8`, so the tail bytes are local switch data generated by control flow.
- Current bounded disassembly/search adds target-specific option evidence:
  - `0x004bc2e6`: load `arg_14`, null-check it, then read selector byte `[ecx]` at `0x004bc2f1`.
  - `0x004bc305-0x004bc30f`: selector dispatch has eight cases after `dec eax`.
  - `0x004bc327-0x004bc32a`: reload `arg_14` and read byte `[eax+8]`.
  - `0x004bcb51-0x004bcb54`: reload `arg_14` and read dword `[eax+0Ch]`; another `[eax+0Ch]` read appears at `0x004bcb9c`.
- Current support docs already incorporate the July 2 slot-2 repair: slot 2 is `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, has an `int` status return, uses the destination draw receiver in `ecx`, takes source context, source/destination `RectBounds`, mode, palette/null, and nullable `const SurfaceSpriteBlitOptions *options`.

## Negative Evidence Summary

- No direct callers were found for `0x004bc090`; all runtime call evidence is through the callback slot.
- No evidence ties the target to `RankingEventListPane` beyond stale/generated callsite-biased names.
- No evidence makes `SoftwareBlend16` the direct owner. UID0000NT is the correct owner for stateless helpers such as `BlendRgb555` and the `0x0045fa00` helper island children, but UID0002PH is a table-installed callback body with Surface/GrafPort state and a broad dispatch fanout.
- No current evidence supports creating a new source file solely for UID0002PH. A future `SoftwareRenderCallbacks.cpp` style file may be plausible for the whole callback subsystem, but current docs already have a valid Surface route and no current by-file page for a narrower source root.
- No current evidence is strong enough for final formal C++. The callback has 1747 instructions, 280 blocks, nested mode/option dispatch, row-encoded transparency handling, source-context/palette fields, and local switch data. Emitting source now would require decompiler-shaped branch labels and a partially inferred `SurfaceSpriteBlitOptions` layout.

## Ranked Ownership Analysis

1. [UID:0000OC] `Surface` / `NexusTK/render/Surface.cpp`:
   - Evidence for: target is installed into `SurfaceRenderCallbackTable` by Surface initializer refs; target has no direct callers; slot `0x0069b3e8` has broad render fanout; target operates on destination surface/GrafPort state, palette context, clipping, row copies, and software-render callback modes; Surface already clears `88/85` and lists UID0002PH as exact proposed content.
   - Evidence against: final original source file could have been a narrower software-render callback file, but the project currently models Surface as the render callback root and no narrower source-root page clears a stronger gate.
   - Decision: keep `CANONICAL_OWNER:0000OC` and `EMITTER_UIDS:0000OC`.
2. [UID:0000TN] / [UID:0001PI] `SurfaceRenderCallbackTable`:
   - Evidence for: direct slot storage and initializer relationship.
   - Evidence against: table pages own the global dispatch storage, not the callback implementation body. UID0002PH is the function installed into slot 2, not the table declaration.
   - Decision: support context only, not canonical owner.
3. [UID:0000NT] `SoftwareBlend16`:
   - Evidence for: UID0002PH calls `BlendRgb555` and helper spans at `0x0045fa00`, `0x0045fb80`, and `0x0045fe40`; behavior includes 16-bit pixel math.
   - Evidence against: the target is not a stateless leaf helper. It consumes destination receiver state, source descriptor/mask data, palette context, clipping, and callback option dispatch. SoftwareBlend16 docs explicitly scope larger callback families to Surface/render dispatch.
   - Decision: dependency/helper owner only.
4. [UID:0000BN] `RankingEventListPane` or feature-pane owners:
   - Evidence for: historical generated output projected callsite-biased names under RankingEventListPane.
   - Evidence against: current MCP shows no direct feature-pane callers, only callback-table installation plus broad slot users across panes, image libraries, map/tile drawing, and presentation.
   - Decision: reject as generated-owner pollution.
5. New source file candidate, e.g. `SoftwareRenderCallbacks.cpp`:
   - Evidence for: both compat and RGB565 callback families form a coherent render subsystem and may ultimately deserve a narrower file than broad `Surface.cpp`.
   - Evidence against: no current by-file page exists; creating one for one target would split the already accepted Surface route without proving a better whole-family owner.
   - Decision: no new file in this pass. Record as optional future family-wide source-structure audit only.

## Source Placement

- Recommended source route remains `NexusTK/render/Surface.cpp` through [UID:0000OC].
- Support docs should continue treating `SurfaceRenderCallbackTable` as the table/global owner and `SoftwareBlend16` as math-helper dependency context.
- If a future family-wide report creates a dedicated render-callback by-file page, UID0002PH should migrate only with the whole compat/RGB565 callback family and table initializer context, not as a single isolated move.

## Range/Split/Padding/Reclassification

- Keep exact function range `0x004bc090-0x004bd3e8`.
- Keep `0x004bd3e8-0x004bd420` classified as local switch/jump-table data generated from this function's control flow. Current MCP `lookup_funcs` says `0x004bd3e8` is not a function, and current disassembly references `jpt_4BC21E` at `0x004bd3e8`.
- No child split is recommended in this pass. The target is one large source-authored callback implementation; splitting internal switch cases into separate by-memory pages would invent boundaries not present as functions or standalone source objects.
- No generated/padding/ignored reclassification is recommended for the target body.

## Function / Child Inventory

| Item | Range / address | Current role | Recommendation |
| --- | --- | --- | --- |
| UID0002PH | `0x004bc090-0x004bd3e8` | compat/RGB555 slot-2 sprite/tile/frame blit callback | Keep exact page; update current MCP and option-pointer evidence; keep owner/emitter Surface. |
| Local switch data | `0x004bd3e8-0x004bd420` | compiler-generated jump tables for UID0002PH control flow | Keep documented as local switch data, not separate source data. |
| UID0002PK | `0x004c0f80-0x004c3123` | RGB565 slot-2 peer | Already documents parallel role and remains useful support context; no edit required by this report. |
| UID0000TN / UID0001PI | `0x0069b3e8` slot inside callback table | storage/dispatch route | Already carry July 2 slot-2 typedef and options-pointer support evidence; no required metadata change. |

## Heuristic / Inference Reanalysis And Validation

- The main score blocker named by the target page is final callback signature/branch naming. Current support docs and MCP evidence resolve part of that blocker: the slot is now safely describable as `SurfaceSpriteBlitProc` / `g_pfnBlitSprite`, with an `int` return, destination receiver in `ecx`, and nullable options pointer rather than scalar flags.
- The blocker is not fully closed. The final concrete option struct remains unsafe because support docs show UID00041R and UID00041U initialize different subsets of fields, while installed targets read fields that are not initialized by every non-null caller. Current UID0002PH-specific evidence adds compat reads at selector `+0`, byte `+8`, and dword `+0x0c`, but does not prove a complete source-safe struct layout or initialization policy.
- The target's source-facing branch map can be improved without writing code: straight row-copy, indexed/palette copy, row-encoded mask handling, RGB555 blend/transparent blend, and option-dispatched transforms should be documented as branch families. However, there is not enough current branch naming evidence to emit a final C++ switch or helper decomposition.
- The current owner and emitter are defensible. This is not a no-owner/non-emitting case, not a parent-gate issue, and not a split issue.
- The best current improvement is a target-page source-quality refresh rather than a structural reroute: add current MCP session facts, option-pointer read sites, July 2 slot-2 typedef direction, and current metadata wording.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `86` | Current MCP reconfirms exact bounds, callee/caller/xref state, CFG size, early setup, switch-table boundary, and adds option-pointer read sites; support docs now resolve the slot-2 final-argument model from scalar flags to nullable options pointer. Completion should rise slightly but remain below high-final range because detailed branch labels and formal C++ are still unresolved. |
| `CONFIDENCE` | `88` | `89` | Current MCP agrees with the target/support docs and strengthens the signature/option model. Confidence should remain below `90+` because the concrete option struct and final source names are still inferred. |
| `CANONICAL_OWNER` | `0000OC` | `0000OC` | Surface remains the best direct semantic owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored callback body selected by runtime table. |
| `EMITTER_UIDS` | `0000OC` | `0000OC` | Valid output route through Surface. |
| `RECONSTRUCTION_CPP CODE` | blank | blank | See first-draft no-code proof below. |

- Support docs [UID:0000OC], [UID:0000TN], [UID:0001PI], [UID:00016J], [UID:0002PK], and [UID:0000NT] do not require score or metadata changes for this report. They already contain sufficient owner/table/helper context.

## First-Draft C++ Recommendation

Do not add formal C++ for UID0002PH in this pass.

Target-specific no-code proof:

- Numerical eligibility alone is not enough. UID0002PH has a valid emitter route and `(85 + 88) / 2 > 85`, but the function is a 1747-instruction, 280-block callback with nested mode dispatch, option dispatch, encoded-mask traversal, palette fallback, row-copy and blend paths, helper-dispatched span transforms, and local switch-table data.
- Current evidence supports the callback typedef direction but not a complete concrete `SurfaceSpriteBlitOptions` definition. UID0002PH reads `arg_14` selector `+0`, byte `+8`, and dword `+0x0c`; support docs also prove other slot-2 users and the RGB565 peer involve fields such as alpha `+0x04` and secondary `+0x1c`. Because not all non-null callers initialize all read fields, a concrete source record and initialization policy would be speculative.
- Branch/source names remain descriptive rather than source-ready. The page should use branch-family labels, not emit a decompiler-shaped switch body.
- The local switch-table bytes at `0x004bd3e8-0x004bd420` must be regenerated from source control flow. Hand-porting or commenting raw table data would be wrong.

Formal C++ should remain blank until a dedicated branch/signature pass resolves the mode enum, option record policy, source-context field names, and source-shaped decomposition for both UID0002PH and the RGB565 peer UID0002PK.

## Recommended Target/Support Doc Changes

- `by-memory/0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md`:
  - Raise metadata to `COMPLETION:86`, `CONFIDENCE:89`; keep owner/emitter/reconstructable unchanged.
  - Add current MCP evidence from session `supervisor_resume_20260629`: exact `sub_4BC090` size `0x1358`, `0x004bd3e8` not a function, no direct callers, two target-address data refs at `0x00558740` and `0x00558b94`, callee set, 280 blocks / 1747 instructions, early draw-enabled/palette/clip setup, and local `jpt_4BC21E` at `0x004bd3e8`.
  - Add a "Touched State / Option Record Evidence" table or equivalent prose recording `ecx` destination receiver, destination byte `+0x71`, destination row/origin fields already visible in the current page, source descriptor fields `+0x20/+0x24` for encoded masks, and option pointer reads at `arg_14 +0`, `+8`, and `+0x0c`.
  - Synchronize slot-2 source-facing wording with [UID:0000TN]/[UID:0001PI]: `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, `int` return, destination receiver in `ecx`, source context, source/destination rects, mode, palette/null, and nullable opaque `const SurfaceSpriteBlitOptions *options`.
  - Replace stale `AUTOGEN_PARENT_UID` prose with current `CANONICAL_OWNER` / `EMITTER_UIDS` wording. If historical changes retain old terms, mark them as legacy wording rather than current metadata.
  - Preserve the no-code proof above and keep formal C++ blank.
- No support doc edits are mandatory. If the supervisor wants tighter cross-doc synchronization, add only a short already-current note to [UID:0000TN] / [UID:0001PI] that UID0002PH current MCP confirms compat option reads at `+0`, `+8`, and `+0x0c`; however the table pages already contain the broader July 2 option model.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002PH-001 | UID0002PH is exactly `sub_4BC090` at `0x004bc090-0x004bd3e8`; `0x004bd3e8` is not a function start. | high | Current MCP `lookup_funcs`; current target page | UID0002PH Address Range / IDA MCP Evidence | incorporate | applied: target IDA MCP Evidence records the current `supervisor_resume_20260629` lookup result, exact size `0x1358`, and non-function end. |
| C-0002PH-002 | The target has no direct callers and only target-address data refs at `0x00558740` and `0x00558b94`. | high | Current MCP `analyze_function`, `xrefs_to 0x004bc090` | UID0002PH IDA MCP Evidence / Ownership Notes | incorporate | applied: target IDA MCP Evidence and Ownership Notes record no direct callers and the two data refs. |
| C-0002PH-003 | Slot `0x0069b3e8` fanout is broad render infrastructure, not RankingEventListPane ownership. | high | Current MCP `xrefs_to 0x0069b3e8`; [UID:0000TN], [UID:0001PI], [UID:00016J] | UID0002PH Ownership Notes / Cross-References | incorporate | applied: target IDA MCP Evidence includes representative slot users and Ownership Notes explicitly reject RankingEventListPane/generated feature owners. |
| C-0002PH-004 | Surface remains the correct owner/emitter; SoftwareBlend16 is only helper/math context. | high | Surface, SoftwareBlend16, callback-table docs, B001 aggregate report | UID0002PH Ownership Notes / Reconstruction Notes | incorporate | applied: metadata remains owner/emitter `0000OC`; Ownership Notes reject SoftwareBlend16 as direct owner while preserving helper context. |
| C-0002PH-005 | Current MCP confirms early setup: draw-enabled guard, palette fallback, clip rectangle, rectangle intersection, and row pointer setup. | high | Current bounded disasm offset 0 | UID0002PH IDA MCP Evidence / Branch Role Map | incorporate | applied: target IDA MCP Evidence records current bounded disassembly early setup details. |
| C-0002PH-006 | Current MCP confirms `arg_14` is a nullable options pointer with compat reads at selector `+0`, byte `+8`, and dword `+0x0c`. | high | Current bounded `search_text` and `disasm` around `0x004bc2e6`, `0x004bc327`, `0x004bcb51` | UID0002PH Touched State And Option Record Evidence | incorporate | applied: target now has `Touched State And Option Record Evidence` with exact read sites and offsets. |
| C-0002PH-007 | The current source-facing slot-2 typedef direction is `SurfaceSpriteBlitProc` / `g_pfnBlitSprite`, `int` return, destination receiver in `ecx`, and nullable opaque options pointer. | medium-high | [UID:0000TN], [UID:0001PI], UID00041R executed support repair, current MCP option reads | UID0002PH Touched State And Option Record Evidence / Reconstruction Notes | incorporate | applied: target option section and Reconstruction Notes use the current slot-2 wording and reject scalar flags. |
| C-0002PH-008 | Formal C++ remains unsafe because branch/mode names and the concrete options record are not source-ready. | high | Current MCP scale and option evidence; support docs showing partially initialized option records | UID0002PH Reconstruction Notes / RECONSTRUCTION_CPP remains blank | incorporate | applied: formal block remains blank and Reconstruction Notes include target-specific no-code proof. |
| C-0002PH-009 | Score should move from `85/88` to `86/89` with no metadata route change. | medium-high | Current MCP recheck plus new option evidence; comparison with RGB565 peer UID0002PK `86/89` | UID0002PH metadata and Score Rationale | incorporate | applied: metadata is `86/89`; route metadata unchanged; Score Rationale updated. |
| C-0002PH-010 | Legacy `AUTOGEN_PARENT_UID` wording should be replaced or historicalized under current `CANONICAL_OWNER` / `EMITTER_UIDS` terminology. | high | Current by-structure owner/emitter rules; target prose still says `AUTOGEN_PARENT_UID` | UID0002PH Reconstruction Notes / Changes | incorporate | applied: current Reconstruction Notes use `CANONICAL_OWNER` / `EMITTER_UIDS`; old AUTOGEN wording remains only in historical Changes entries. |

## Implementation Tracking Checklist

- [x] Update `by-memory/0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md` metadata from `85/88` to `86/89`; keep `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank emitter position, and blank formal C++. Proof: target metadata now has `COMPLETION:86`, `CONFIDENCE:89`, unchanged owner/emitter/reconstructable fields, blank position, and blank formal C++.
- [x] Add current MCP evidence for session `supervisor_resume_20260629`: lookup result, no-function end, no direct callers, two target data refs, callee set, 280-block / 1747-instruction scale, and bounded disassembly evidence for early setup and switch table. Proof: target `IDA MCP Evidence` section includes the B012 current MCP bullets and exact facts.
- [x] Add option-pointer evidence: `arg_14` null/selector read at `0x004bc2e6-0x004bc2f1`, eight-case option dispatch at `0x004bc305-0x004bc30f`, `[arg_14+8]` read at `0x004bc327-0x004bc32a`, and `[arg_14+0x0c]` reads at `0x004bcb54` / `0x004bcb9c`. Proof: target `Touched State And Option Record Evidence` records each accepted site and offset.
- [x] Synchronize UID0002PH wording with current slot-2 support docs: `SurfaceSpriteBlitProc` / `g_pfnBlitSprite`, `int` return, destination receiver in `ecx`, nullable opaque `const SurfaceSpriteBlitOptions *options`, and rejected scalar-flags wording. Proof: target option evidence section and Reconstruction Notes carry this wording and reject scalar flags.
- [x] Preserve rejected ownership alternatives: RankingEventListPane is generated/callsite pollution; SoftwareBlend16 owns helper callees only; callback table owns storage only; no new source file is recommended in this pass. Proof: target Ownership Notes now list these rejected alternatives.
- [x] Preserve range/split decision: keep `0x004bc090-0x004bd3e8` exact body and `0x004bd3e8-0x004bd420` local switch data; no new child files or range splits. Proof: target Address Range, Local Switch Data, and Changes sections keep exact range/local switch classification; no files created.
- [x] Replace current-prose `AUTOGEN_PARENT_UID` with `CANONICAL_OWNER` / `EMITTER_UIDS` wording, or mark old `AUTOGEN_PARENT_UID` text as historical in the Changes section. Proof: current Reconstruction Notes use `CANONICAL_OWNER` / `EMITTER_UIDS`; old AUTOGEN wording remains only in historical Changes entries.
- [x] Keep `RECONSTRUCTION_CPP CODE` blank and add the target-specific no-code proof from this report. Proof: target formal block remains blank; Reconstruction Notes include target-specific no-code proof.
- [x] Update UID0002PH Score Rationale to explain `86/89` and why it should not go higher. Proof: target Score Rationale now has `Completion 86` and `Confidence 89` rows with caps.
- [x] Update Claim And Incorporation Ledger states from `proposed` to callback states during implementation. Proof: ledger rows C-0002PH-001 through C-0002PH-010 are now `applied`.
- [x] Run scoped validator after accepted implementation callback: `python .\tools\validator.py --mode file --file by-memory\0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md --apply --queue-timeout 240`. Proof: command completed with exit code 0.
- [x] Record validator command id, timestamp, exit code, `ok` count, generated refresh side effects, and whether generated reports/output headers are equal/newer if generated output matters. Proof: command_id `000000004623`, command_timestamp `2026-07-02T15:48:40-04:00`, exit code `0`, `ok: 1`, warnings `0`; generated_refresh `deferred` with generated_refresh_command_id `000000004623` and generated_refresh_timestamp `2026-07-02T15:48:40-04:00`. Validator also reported `completion_update: 1`, `confidence_update: 1`, `projected_stats_update: 1`, `reference_index_add: 3`, `stats_rescore_recommended: 1`, and `stats_row_remove: 1`; no manual generated-output edits were made.
- [x] Supervisor-owned/generated expectation: auto-generated research tracker and coverage reports should refresh through validator/report lifecycle only; do not manually edit them. Supervisor should execute this report only after Gate 1 validation, implementation callback verification, and scoped validator success. Proof: no generated reports, generated C++, coverage reports, validator state, archives, or supervisor ledgers were manually edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004628","destination_path":"executed-b-agent-research/B012/0002PH-SoftwareRenderCompatSpriteBlitCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0002PH-SoftwareRenderCompatSpriteBlitCallback-source-quality.md","timestamp":"2026-07-02T15:58:45-04:00","uid":"0002PH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
