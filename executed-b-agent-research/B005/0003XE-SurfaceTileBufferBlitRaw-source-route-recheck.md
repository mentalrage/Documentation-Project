** TARGET-REPORT-UID:0003XE **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003XE **
# [UID:0003XE] SurfaceTileBufferBlitRaw Source-Route Recheck

Agent: B005  
Date: 2026-06-18  
Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md`  
Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\0003XE-SurfaceTileBufferBlitRaw-source-route-recheck.md`  
Assignment type: retry report-only B-preferred source-route/source-quality and heuristic/inference pass.

## Retry Supervisor Recheck

Final retry recommendation: route [UID:0003XE] to [UID:00005V] `GrafPort`, raise completion to `85`, keep confidence `88`, and keep formal C++ blank.

Recommended metadata:

```text
COMPLETION:85
CONFIDENCE:88
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:00005V
EMITTER_UIDS:00005V
RECONSTRUCTION_CPP CODE: blank
```

This retry found a defensible path to `85/85+`. The earlier B005 report repeated the B002/B003 Surface-family no-owner conclusion too conservatively. The stronger current evidence is not the broad `dword_69B3E8` callback dependency; it is the receiver model:

- The raw body calls `call dword ptr [this->vtable + 0x0c]` at `0x004bb278`.
- The documented exact `GrafPort` vtable at `0x0061a8a8` has slot `+0x0c` (`0x0c`, decimal 12, Verified with `int_convert.py`) pointing to `0x004b8e20`, documented as `GrafPort::UpdateRenderRegion`.
- The raw body writes `this+0x20`, `this+0x28`, and `this+0x2c`, matching the accepted `GrafPort` embedded surface context fields documented by [UID:000169] `CompositePixels16` and [UID:00005V] `GrafPort`: pixel buffer at `+0x20` (`0x20`, decimal 32, Verified with `int_convert.py`), row stride at `+0x28` (`0x28`, decimal 40, Verified with `int_convert.py`), and bounds/rectangle state at `+0x2c` (`0x2c`, decimal 44, Verified with `int_convert.py`).
- Nearby precedent [UID:0003XB] and [UID:0003XC] already assigns raw no-entry GrafPort helper clusters to [UID:00005V] when receiver-layout proof is strong, while keeping formal C++ blank because entry/signature proof is still missing.

No metadata reclassification to `RECONSTRUCTABLE:FALSE` or ignored is recommended. This is not a container, padding range, compiler artifact, runtime helper, table, or mixed index. It is exact source-authored NexusTK `.text` code with a recoverable class receiver and behavior. Lowering completion/confidence would also be misleading: the missing evidence is not byte/range/behavior confidence, but live entry and source-signature finality. The corrected state is a routed but no-code GrafPort raw helper at `85/88`, not a no-owner 84 item and not ignored coverage-only evidence.

Formal C++ should remain blank even after assigning the owner/emitter. The target clears the minimum combined score/emitter gate, but the original source declaration and source-use path are still not proven. This mirrors [UID:0003XB]/[UID:0003XC]: owner/emitter route is justified by class-layout evidence, while final C++ is withheld because no caller or source signature proves whether the original source had a private method, retained dead out-of-line helper, or another nonpublic helper shape.

## Materials Re-read And Additional Retry Work

Policy and mandate:

- `tools/leaser/Agents/Agent-B005/goal.md`
- `tools/leaser/Agents/Agent-B005/notes.md`
- `tools/leaser/Agents/Supervisor.md`
- `project-documentation/by-structure.md`
- `project-documentation/inference_research.md`

Target/support docs and generated context:

- [UID:0003XE] `by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md`
- [UID:000160] `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`
- [UID:00005V] `by-class/GrafPort.md`
- [UID:0000JR] `by-file/GrafPort.md`
- [UID:0003BE] `by-memory/0x0061a8a4-0x0061a8b8.GrafPortVtableData.md`
- [UID:000169] `by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md`
- [UID:000167] `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`
- [UID:00016A] `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`
- [UID:0003XB] `by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md`
- [UID:0003XC] `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md`
- [UID:0003XD] `by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md`
- [UID:00016H] `by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md`
- [UID:0003XF] `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`
- [UID:00016I] `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`
- [UID:0000OC] `by-file/Surface.md`
- [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`
- [UID:0001PI] `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- [UID:00039V] `by-memory/0x00558690-0x0055883d.SurfaceRenderCallbackInitializerRaw.md`
- [UID:00039W] `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`
- [UID:00016J] `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`
- [UID:0002PH] `by-memory/0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md`
- [UID:0000RW] `by-global/g_pPaletteLib.md`
- [UID:0000A1] `by-class/PaletteLib.md`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- `by-memory/-coverage-report.md`
- current/generated source tree searches for `004bb260`, `sub_4BB260`, and `SurfaceTileBufferBlitRaw`

Prior executed reports revalidated and challenged:

- `Agent-B002/research/executed/0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis.md`
- `Agent-B002/research/executed/0003XE-0003XF-grafport-raw-island-ownership-reanalysis.md`
- `Agent-B003/research/executed/000160-00022M-grafport-source-quality.md`
- `Agent-B003/research/executed/000167-SurfaceSpriteBlitHelper-source-quality.md`

Current-session IDA MCP note: `127.0.0.1:13337` did not accept a TCP connection during this retry, so I did not add new live IDA claims. I used existing IDA-backed docs and executed reports, then pushed non-IDA evidence with loaded-memory byte scans, route scans, exact callback literal scans, generated-output searches, and cross-document field/vtable validation.

## Exact Bytes, Range, And Padding

Range remains exact: `0x004bb260-0x004bb2d7`, half-open. Length is `0x77`, decimal 119 bytes (Verified with `int_convert.py`).

Loaded-memory bytes:

```text
004bb250: 5d c3 cc cc cc cc cc cc cc cc cc cc cc cc cc cc
004bb260: 55 8b ec 53 56 57 8b f1 e8 c3 ad 05 00 8b 7d 08
004bb270: 8b 06 8d 4f 10 51 8b ce ff 50 0c 8b 5d 0c 85 db
004bb280: 75 0d 8b 0d e0 a7 67 00 e8 b3 8a 08 00 8b d8 8b
004bb290: 4f 1c 2b 4f 14 0f af 4f 0c 03 c9 51 ff 76 20 e8
004bb2a0: 8c ad 05 00 8b c8 e8 e5 ae 05 00 6a 00 89 46 20
004bb2b0: 8d 4f 10 8b 47 0c 53 89 46 28 8d 46 2c 0f 10 01
004bb2c0: 6a 00 50 51 57 8b ce 0f 11 00 ff 15 e8 b3 69 00
004bb2d0: 5f 5e 5b 5d c2 08 00 cc cc cc cc cc cc cc cc cc
004bb2e0: 55 8b ec 83 ec 0c 53 56 8b 75 08 57 8b 7d 10 57
```

Boundary conclusions:

- `0x004bb252-0x004bb260` is fourteen bytes of `cc` prepad after the predecessor epilogue `5d c3`.
- `0x004bb260` starts a normal `thiscall`-shaped raw prologue and saves `ecx` in `esi`.
- `0x004bb2d4-0x004bb2d6` is the complete `c2 08 00` / `ret 8`; the earlier `0x004bb260-0x004bb2d5` cut was invalid.
- `0x004bb2d7-0x004bb2e0` is nine bytes of `cc` postpad.
- `0x004bb2e0` starts [UID:00016H] `LineClipHelpers`.
- No split is required. A rename is recommended only as a supervisor-applied follow-up because the current title overstates Surface ownership.

## Raw Start, Reachability, And Route Checks

The entry remains raw/no-modeled-function, but that no longer blocks GrafPort ownership because receiver-layout proof now matches accepted raw-helper precedent.

Static route results:

```text
004bb260 | VA=0 | RVA=0 | REL32=0
004bb2d7 | VA=0 | RVA=0 | REL32=0
004bb2e0 | VA=0 | RVA=0 | REL32=2 | 004bbc81:e8, 004c0b71:e8
004bb5b0 | VA=0 | RVA=0 | REL32=0
004bb5e0 | VA=0 | RVA=0 | REL32=2 | 004bab57:e8, 004bac8a:e8
004b99c0 | VA=0 | RVA=0 | REL32=0
004b99f0 | VA=0 | RVA=0 | REL32=3 | 004b5917:e8, 005c3b60:e8, 005c3db0:e8
004ba250 | VA=0 | RVA=0 | REL32=8 | 004f12b4:e8, 0050978f:e8, 00549986:e8, 0055b27b:e8, 0055b45f:e8, 0055b592:e8, 0055b930:e8, 0055b9c7:e8
004bc090 | VA=2 | 00558741, 00558b9a | RVA=0 | REL32=0
004c0f80 | VA=2 | 0055882f, 00558eb6 | RVA=0 | REL32=0
0069b3e8 | VA=114 | broad slot references; exact indirect-call pattern appears 111 times
0067a7e0 | VA=83 | broad palette singleton references
00543d40 | VA=0 | RVA=0 | REL32=18 | includes 004bb288:e8
00516030 | VA=0 | RVA=0 | REL32=612 | includes 004bb268:e8
00516190 | VA=0 | RVA=0 | REL32=10 | includes 004bb2a6:e8
```

Additional retry route checks:

- Exact `ff 15 e8 b3 69 00` calls to `dword_69B3E8`: 111 occurrences. This proves the slot is too broad to own or name [UID:0003XE] by itself.
- Exact callback initializer/target docs show slot `dword_69B3E8` targets are `0x004bc090` and `0x004c0f80`, not `0x004bb260`.
- Surface callback initializer docs list target families starting at `0x004bb8d0` and `0x004c0770`; [UID:0003XE] is before those callback families and is not assigned into the callback table.
- Generated source and generated coverage searches found [UID:0003XE] only in no-owner/non-emits rows. No generated C++ body, stale source-map owner, `sub_4BB260`, or feature-pane alias was found. Simroot hits containing `4bb260` were hash-substring false positives, not addresses.
- Broad short-branch scan found no external branch route into `0x004bb260-0x004bb2d7`.

Reachability conclusion:

- Direct entry liveness remains unproven.
- Indirect entry liveness remains unproven.
- The missing entry route still blocks formal C++ and final source signature.
- The missing entry route no longer justifies `CANONICAL_OWNER:NONE`, because the receiver class is now defensibly identified through vtable-slot and field-layout evidence.

## GrafPort Receiver Breakthrough

The key retry evidence is the vtable call at `0x004bb278`:

```text
004bb270: 8b 06          mov eax, [esi]
004bb272: 8d 4f 10       lea ecx, [edi+0x10]
004bb275: 51             push ecx
004bb276: 8b ce          mov ecx, esi
004bb278: ff 50 0c       call dword ptr [eax+0x0c]
```

Loaded-memory vtable bytes for [UID:0003BE] `GrafPortVtableData`:

```text
0061a8a4: d4 7d 64 00 e0 b7 4b 00 10 4b 4f 00 c0 b6 41 00 20 8e 4b 00
0061a8a4 -> 0x00647dd4 RTTI locator
0061a8a8 -> 0x004bb7e0 GrafPort scalar deleting destructor
0061a8ac -> 0x004f4b10 inherited/base virtual slot
0061a8b0 -> 0x0041b6c0 inherited/base virtual slot
0061a8b4 -> 0x004b8e20 GrafPort::UpdateRenderRegion
```

`call [vtable + 0x0c]` on a receiver with this vtable dispatches to `GrafPort::UpdateRenderRegion`. The raw body passes `record+0x10`, the same source-rectangle/bounds subobject later copied into `this+0x2c`. This is class-receiver evidence, not mere adjacency.

Field-match evidence:

- [UID:000169] documents `this+0x20` as `m_surfaceContext.pixelData`, `this+0x28` as `m_surfaceContext.rowStride`, and `this+0x2c/+0x30` as `m_surfaceContext.bounds.left/top` in accepted `GrafPort::CompositePixels`.
- [UID:000167] documents `GrafPort::BlitSurface` touching the same `+0x20/+0x28` embedded `EPFTileContext`/surface context fields in software render paths.
- [UID:00016A] documents `GrafPort::DrawTiledBackground` forwarding draw/blit mode and alpha state into the same `dword_69B3E8` callback ecosystem.
- [UID:0003XB] already treats raw no-entry setters to `this+0x20` and `this+0x28` as GrafPort state helpers when the surrounding receiver layout proves the class.

The target's previous descriptive `SurfaceTileScratch` receiver should be rejected. It was plausible when only the local body was considered, but it is weaker than the exact `GrafPort` vtable-slot and field-layout match.

## Body Semantics And Source-Quality Names

Instruction-level behavior:

- Saves `ecx` receiver as `esi`; best receiver is now `GrafPort *this`.
- Calls `GetMemoryMan` at `0x00516030`.
- Loads first stack argument as a frame/tile draw record in `edi`.
- Calls `this->UpdateRenderRegion(&record->sourceRect)` through vtable slot `+0x0c`.
- Loads second stack argument as an optional palette/context pointer.
- If the palette is null, loads `g_pPaletteLib` at `0x0067a7e0` and calls `PaletteLib::GetCurrentPalette` at `0x00543d40`.
- Computes `(record->sourceRect.bottom - record->sourceRect.top) * record->rowStride * 2`.
- Reallocates `m_surfaceContext.pixelData` at `this+0x20` through memory manager helper `0x00516190`.
- Copies `record->rowStride` from `record+0x0c` to `this+0x28`.
- Copies 16 bytes from `record+0x10` to `this+0x2c`.
- Calls `dword_69B3E8` with `ecx=this`, the source record, source rectangle, destination/context rectangle, a zero mode/flags argument, the resolved palette, and a trailing zero argument.
- Returns with `ret 8`, proving two explicit stack arguments.

Best source-facing model after retry:

```text
Receiver:        GrafPort *this
record arg:      FrameDrawRecord * or TileFrameDrawRecord *; `FrameDrawRecord` is stronger because accepted GrafPort docs use it for `DrawTiledBackground`
palette arg:     DLPalette * or equivalent optional palette/context pointer
this+0x20:       m_surfaceContext.pixelData
this+0x28:       m_surfaceContext.rowStride
this+0x2c:       m_surfaceContext.bounds / destination rectangle cache
record+0x0c:     source row stride / pitch
record+0x10..1f: source rectangle
dword_69B3E8:    primary tile/frame/sprite blit callback, descriptive `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`
```

Recommended documentation title if renamed: `GrafPortSurfaceContextBlitRaw` or `GrafPortFrameRecordBlitRaw`. I prefer `GrafPortSurfaceContextBlitRaw` because the body's most distinctive action is replacing the receiver surface context and then dispatching the blit. This rename is optional and supervisor-owned; the current path can remain if the supervisor wants to avoid rename churn.

## Dependency Roles

`g_pPaletteLib` / `PaletteLib::GetCurrentPalette`:

- Confirms the second argument is optional palette state.
- Supports render-helper semantics.
- Does not own the function. PaletteLib is a service dependency.

`SurfaceRenderCallbackTable` / `dword_69B3E8`:

- Confirms this helper participates in the shared tile/frame/sprite rendering path.
- Does not own the function. The target consumes the slot; it is not a table target or initializer.
- Retry broad scan found 111 exact indirect calls to the slot pattern, so the slot is a system-wide dependency rather than an ownership signal.

`SurfaceRenderCallbackInitializerRaw` and `SurfaceMinimapRenderInitializer`:

- Positive controls for table-target ownership.
- They explicitly contain target-address literals for callback families including `0x004bc090` and `0x004c0f80`.
- They do not contain `0x004bb260`, which rejects callback-target classification for [UID:0003XE].

`GrafPort` vtable:

- Accepted as the decisive source-owner evidence.
- The target's receiver virtual call matches `GrafPort::UpdateRenderRegion`, and the field writes match accepted GrafPort surface context fields.

## Prior B002/B003 Claims: Revalidated, Challenged, Superseded

Revalidated B002/B003 claims:

- Exact range is `0x004bb260-0x004bb2d7`; old `0x004bb2d5` end was invalid.
- Bytes are source-shaped executable code, not padding or compiler glue.
- No direct VA/RVA/rel32/short-branch/table entry route to `0x004bb260` is currently known.
- `dword_69B3E8` is a dependency, not a callback-table owner.
- `PaletteLib` is a dependency, not an owner.
- `NumericString`, `LineClipHelpers`, `SurfaceRenderCallbackTable`, and callback target pages are not owners.
- Formal C++ is unsafe while entry/signature proof remains missing.

Challenged and superseded B002/B003 claims:

- Old claim: best forced family is Surface/render tile-buffer support, owner remains `NONE`.
- Retry result: Surface/render is still the dependency family, but direct owner should be [UID:00005V] `GrafPort`. The old no-owner result underweighted the `call [vtable+0x0c]` evidence and did not connect it to the exact `GrafPort` vtable slot `UpdateRenderRegion`.
- Old claim: `this+0x20/+0x28/+0x2c` are a descriptive unknown scratch receiver layout.
- Retry result: those offsets match accepted `GrafPort` `m_surfaceContext` fields in current [UID:000169], [UID:000167], and [UID:00005V] docs.
- Old claim: a new `SurfaceTileScratch` helper class/file is the best class-like explanation.
- Retry result: reject `SurfaceTileScratch`; no separate class is needed once the `GrafPort` receiver is recognized.

Newly checked candidates:

- Generated source/source-map alias: rejected. No generated C++ or real source-map owner exists for `0x004bb260`; simroot address searches only produced hash-substring false positives.
- Callback initializer target: rejected. Initializer docs and literal scans identify `0x004bc090`/`0x004c0f80`, not `0x004bb260`.
- Software render callback child family: rejected. [UID:00016J]/[UID:0002PH] are actual callback targets after `0x004bb8d0`, while [UID:0003XE] is a caller/consumer before that family.
- GrafPort raw no-entry precedent: accepted as analogous. [UID:0003XB]/[UID:0003XC] show that raw no-entry status can coexist with GrafPort owner/emitter routing when receiver layout proof is strong, while C++ remains blank.

## Candidate Owner Ranking

1. [UID:00005V] `GrafPort` / [UID:0000JR] `GrafPort.cpp`: accepted.

Evidence:

- Exact vtable slot match to `GrafPort::UpdateRenderRegion`.
- Exact surface-context field match at `this+0x20/+0x28/+0x2c`.
- Related accepted GrafPort methods consume the same fields and callback ecosystem.
- Parent class/file scores clear the gate.
- Precedent exists for raw no-entry GrafPort helper clusters with blank C++.

Impact:

- Raise target to `85/88`.
- Set owner/emitter to `00005V`.
- Keep C++ blank pending entry/signature proof.

2. [UID:0000OC] `Surface`: reject as direct owner; retain as dependency context.

Evidence for:

- Uses `dword_69B3E8`.
- Uses optional palette fallback.
- Surface docs track the callback table and software render families.

Evidence against:

- Callback slot is broad and used by GrafPort-owned methods.
- Callback initializers do not target `0x004bb260`.
- Receiver vtable/field evidence points to `GrafPort`, not a Surface free helper.

3. New `SurfaceTileScratch` / `SurfaceTileBuffer` class or helper file: reject.

Evidence for:

- Earlier local-only field interpretation looked like a scratch buffer object.

Evidence against:

- No constructor/vtable/RTTI/sibling exists for such a class.
- Known `GrafPort` vtable/fields explain the same evidence more directly.

4. `SurfaceRenderCallbackTable`: reject.

Evidence:

- [UID:0003XE] calls the slot. It is not installed in the table and is not a target.

5. `PaletteLib`: reject.

Evidence:

- Only a null-palette fallback service dependency.

6. `NumericStringGlyphTileContextInit`: reject.

Evidence:

- Immediate predecessor only. No NumericString caller/resource/text constants in the target.

7. `LineClipHelpers`: reject.

Evidence:

- Immediate successor only. Different semantics and independent caller/callee shape.

8. Non-reconstructable/ignored: reject.

Evidence:

- Exact source-authored `.text` helper, not aggregate/padding/compiler/runtime.
- Now has a defensible class owner.

## Heuristic / Inference Reanalysis And Validation

Issue: can the target break through the 85 completion gate?

- Evidence checked: current target page, auto stats, generated memory coverage, old B002/B003 reports, loaded-memory route scans, GrafPort vtable data, GrafPort class field docs, accepted sibling GrafPort methods, raw no-entry GrafPort helper precedent.
- Rejected alternatives: leaving no-owner solely because direct caller is absent; assigning Surface solely because of callback dependency; demoting to ignored/non-reconstructable because the entry is raw.
- Final inference: yes. Owner/emitter can be assigned to `GrafPort` at `85/88`, but formal C++ remains blank.
- Score/source impact: `84/88 -> 85/88`; owner/emitter `NONE`/blank -> `00005V`/`00005V`; no range split; no formal C++.

Issue: direct entry liveness.

- Evidence checked: VA/RVA/rel32 scans, short-branch scan, generated source/searches, callback initializer target literals, positive controls for live neighboring functions and callback targets.
- Rejected alternatives: hidden direct caller, callback-table target, external short-branch target, generated source alias.
- Final inference: entry liveness remains unproven. This prevents final source signature and formal C++ but not owner assignment, because raw no-entry class helpers are accepted locally when receiver proof is strong.
- Score/source impact: caps completion at 85 and confidence at 88; C++ blank.

Issue: receiver type.

- Evidence checked: target `ff 50 0c` vtable call, `GrafPortVtableData` slot `0x0061a8b4 -> 0x004b8e20`, GrafPort class docs, `CompositePixels16`, `BlitSurface`, `DrawTiledBackground`, raw GrafPort helper clusters.
- Rejected alternatives: unknown `SurfaceTileScratch`, file-local Surface receiver, generic callback object, PaletteLib receiver.
- Final inference: receiver is best documented as `GrafPort *this`.
- Score/source impact: unlocks owner/emitter route and rejects old no-owner state.

Issue: field names.

- Evidence checked: body stores at `this+0x20`, `this+0x28`, `this+0x2c`; accepted GrafPort field docs; related methods reading/writing the same offsets.
- Rejected alternatives: independent scratch-object `m_scratchPixels/m_sourcePitch/m_sourceRect` names as primary source names.
- Final inference: use `m_surfaceContext.pixelData`, `m_surfaceContext.rowStride`, and `m_surfaceContext.bounds` as best source-facing names. `m_scratchPixels` remains only a historical descriptive interpretation.
- Score/source impact: supports GrafPort routing; formal C++ still blank because method name/signature and entry use remain unknown.

Issue: callback slot role.

- Evidence checked: 111 exact `ff 15 e8 b3 69 00` call sites, 114 broad slot refs, callback table docs, callback initializer docs, software-render callback target docs.
- Rejected alternatives: [UID:0003XE] as callback target; callback-table owner; feature-specific callback alias.
- Final inference: `dword_69B3E8` is the primary tile/frame/sprite blit callback consumed by this GrafPort helper. Best descriptive names remain `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`.
- Score/source impact: dependency only; does not override GrafPort ownership.

Issue: palette argument.

- Evidence checked: stack argument at `[ebp+0x0c]`, null check, `g_pPaletteLib` load, `PaletteLib::GetCurrentPalette` call, related GrafPort/Surface palette docs.
- Rejected alternatives: mandatory palette argument; PaletteLib ownership.
- Final inference: second argument is optional palette/context pointer, likely `DLPalette *`.
- Score/source impact: improves signature model but not enough for formal C++.

Issue: source file placement.

- Evidence checked: GrafPort file/class docs, Surface file docs, callback table docs, generated coverage, related accepted methods.
- Rejected alternatives: `Surface.cpp`, new `SurfaceTileScratch.cpp`, `PaletteLib.cpp`, callback table data page, NumericString file, LineClip helper page.
- Final inference: source route should be through [UID:00005V] `GrafPort`, emitted via [UID:0000JR] `NexusTK/render/GrafPort.cpp`.
- Score/source impact: owner/emitter route clears parent gate.

Issue: formal C++ readiness.

- Evidence checked: active C++ gate, raw no-entry status, local [UID:0003XB]/[UID:0003XC] precedent, current method/signature uncertainty.
- Rejected alternatives: populate final C++ now; leave no draft/model at all.
- Final inference: include a descriptive non-emitting sketch in the report, but instruct supervisor not to populate the formal target C++ block yet.
- Score/source impact: target can be routed but stays no-code.

Issue: metadata reclassification.

- Evidence checked: by-structure reconstructable guidance, ignored-ledger policy, aggregate/container examples, current target exact source-shaped body, recovered GrafPort receiver.
- Rejected alternatives: `RECONSTRUCTABLE:FALSE`, ignored, coverage-only retained no-owner evidence, lower score.
- Final inference: keep `RECONSTRUCTABLE:TRUE`; update owner/emitter instead. `FALSE` would be wrong because the item is not an aggregate and now has class-owner proof.
- Score/source impact: no demotion; break through to `85/88`.

## First-Draft C++ Decision

Do not populate the formal `RECONSTRUCTION_CPP CODE` block yet, even after setting `EMITTER_UIDS:00005V`.

Target-specific no-code proof:

- No direct caller, table target, pointer literal, or branch route proves the source-use path.
- No original method name or declaration site is known.
- The body is raw/no-modeled-function; local precedent [UID:0003XB]/[UID:0003XC] routes similar raw GrafPort helper evidence while keeping formal C++ blank.
- A formal method definition would be plausible, but it would still choose an unproven private method name and signature.

Descriptive non-emitting sketch for future review only:

```cpp
// Descriptive only. Do not place in RECONSTRUCTION_CPP until entry/signature proof is found.
void __thiscall GrafPort::BlitFrameRecordToSurfaceContext(
    const FrameDrawRecord *record,
    DLPalette *paletteOrNull)
{
    GetMemoryMan();
    UpdateRenderRegion(&record->sourceRect);

    DLPalette *palette = paletteOrNull;
    if (palette == NULL) {
        palette = g_pPaletteLib->GetCurrentPalette();
    }

    const int byteCount =
        (record->sourceRect.bottom - record->sourceRect.top) *
        record->rowStride * 2;

    m_surfaceContext.pixelData =
        GetMemoryMan()->ReallocateOrThrow(m_surfaceContext.pixelData, byteCount);
    m_surfaceContext.rowStride = record->rowStride;
    m_surfaceContext.bounds = record->sourceRect;

    g_pfnBlitSprite(
        this,
        record,
        &record->sourceRect,
        &m_surfaceContext.bounds,
        0,
        palette,
        0);
}
```

The sketch intentionally keeps placeholder names: `BlitFrameRecordToSurfaceContext`, `FrameDrawRecord`, `DLPalette`, `GetMemoryMan()->ReallocateOrThrow`, and `g_pfnBlitSprite` need a final signature/name pass before formal output.

## Recommended Metadata And Rename

Required metadata recommendation:

```text
COMPLETION:85
CONFIDENCE:88
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:00005V
EMITTER_UIDS:00005V
RECONSTRUCTION_CPP CODE: blank
```

Optional supervisor rename recommendation:

```text
from: by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md
to:   by-memory/0x004bb260-0x004bb2d7.GrafPortSurfaceContextBlitRaw.md
title: 0x004bb260-0x004bb2d7 GrafPort Surface Context Blit Raw
```

If avoiding rename churn, keep the existing filename and update the title/status to say the old Surface name is historical and the owner is now GrafPort.

## Support-Doc Incorporation Plan

Do not edit by-* docs directly from this B005 report. The supervisor should incorporate the following exact changes claim-by-claim.

### Target Page

Placement: at the top of `## Status`, replacing the current no-owner policy bullets.

```text
- Disposition: reconstructable source-authored raw `GrafPort` helper; raw entry liveness remains unproven, so formal C++ stays blank.
- Direct owner: [UID:00005V][GrafPort](by-class/GrafPort.md), emitted through [UID:0000JR][GrafPort](by-file/GrafPort.md) `NexusTK/render/GrafPort.cpp`.
- Score after B005 retry: `85/88`.
- Source-facing role: raw helper that updates the `GrafPort` render region from a frame/tile record rectangle, reallocates and replaces `m_surfaceContext.pixelData`, stores `m_surfaceContext.rowStride`, copies `m_surfaceContext.bounds`, resolves an optional palette, and dispatches the primary tile/frame/sprite blit callback.
- C++ status: keep formal `RECONSTRUCTION_CPP` blank. The owner/emitter route is now proven by receiver vtable and field-layout evidence, but no caller/table/source-declaration route proves the original method name or signature.
```

Placement: add to or replace `## Ownership Decision`.

```text
2026-06-18 B005 retry supersedes the earlier Surface-family no-owner conclusion. The decisive evidence is receiver identity: the raw body calls `call [this->vtable + 0x0c]` at `0x004bb278`, and [UID:0003BE][GrafPortVtableData](by-memory/0x0061a8a4-0x0061a8b8.GrafPortVtableData.md) documents `GrafPort` vtable slot `+0x0c` as `0x004b8e20` / `GrafPort::UpdateRenderRegion`. The body also writes the accepted `GrafPort` embedded surface context fields documented by [UID:000169][CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md): `this+0x20` as `m_surfaceContext.pixelData`, `this+0x28` as `m_surfaceContext.rowStride`, and `this+0x2c` as `m_surfaceContext.bounds`. Therefore the direct owner/emitter should be [UID:00005V][GrafPort](by-class/GrafPort.md), not `NONE`.
```

Placement: add to `## Evidence`.

```text
- B005 retry loaded-memory vtable check confirms `0x0061a8a8 -> 0x004bb7e0`, `0x0061a8ac -> 0x004f4b10`, `0x0061a8b0 -> 0x0041b6c0`, and `0x0061a8b4 -> 0x004b8e20`; the target instruction `ff 50 0c` at `0x004bb278` calls the fourth GrafPort virtual slot, `GrafPort::UpdateRenderRegion`.
- B005 retry generated-source search found no stale emitted C++ or source-map owner for `0x004bb260`; generated coverage lists the item only as no-owner/non-emitting before this recommended metadata repair.
- B005 retry broad callback scan found 111 exact `ff 15 e8 b3 69 00` calls to `dword_69B3E8`, proving the callback slot is a broad render dependency and not an ownership route. Callback initializer docs identify `0x004bc090` and `0x004c0f80` as slot target literals, not `0x004bb260`.
```

### GrafPort Class Page

Placement: after the [UID:00016A] / [UID:0003XF] discussion in `by-class/GrafPort.md`.

```text
[UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) should now be treated as a raw no-entry `GrafPort` helper rather than a Surface no-owner orphan. B005 retry found that the body calls the `GrafPort` vtable slot `+0x0c` (`GrafPort::UpdateRenderRegion`) with the record rectangle, then reallocates and stores the accepted `m_surfaceContext.pixelData` / `rowStride` / `bounds` fields at `this+0x20/+0x28/+0x2c` before dispatching `dword_69B3E8`. This mirrors [UID:0003XB]/[UID:0003XC] raw no-entry GrafPort helper policy: owner/emitter route to GrafPort is justified, but formal C++ remains blank until caller/signature proof is found.
```

### GrafPort File Page

Placement: proposed contents table in `by-file/GrafPort.md`.

```text
| [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) | `0x004bb260-0x004bb2d7` | raw no-entry `GrafPort` surface-context/frame blit helper | B005 retry routes this formerly no-owner Surface-family candidate to [UID:00005V][GrafPort](by-class/GrafPort.md): the body calls `GrafPort::UpdateRenderRegion` through vtable slot `+0x0c`, replaces `m_surfaceContext.pixelData`, stores `m_surfaceContext.rowStride`, copies `m_surfaceContext.bounds`, resolves an optional palette, and dispatches `dword_69B3E8`. Keep formal C++ blank pending entry/signature proof. |
```

### GrafPort Split Index

Placement: replace the [UID:0003XE] child inventory row in [UID:000160].

```text
| `0x004bb260-0x004bb2d7` | [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) | Raw no-entry `GrafPort` surface-context/frame blit helper; B005 retry identifies the receiver via `call [vtable+0x0c]` to `GrafPort::UpdateRenderRegion` and accepted `m_surfaceContext` fields at `+0x20/+0x28/+0x2c`. Owner/emitter should route to [UID:00005V][GrafPort](by-class/GrafPort.md), with formal C++ blank pending entry/signature proof. |
```

Placement: replace the `0x004bb260` row in `## Raw Island Closure`.

```text
| `0x004bb260` | [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) | Exact child now routes to [UID:00005V][GrafPort](by-class/GrafPort.md) after B005 retry connected `call [vtable+0x0c]` to `GrafPort::UpdateRenderRegion` and `this+0x20/+0x28/+0x2c` to `m_surfaceContext` fields; raw entry liveness still blocks formal C++. |
```

### Surface File Page

Placement: replace the current [UID:0003XE] row/note in `by-file/Surface.md`.

```text
| [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) | `0x004bb260-0x004bb2d7` | GrafPort-owned callback consumer, retained dependency context only | B005 retry supersedes the no-owner Surface-family conclusion: the body consumes `g_pPaletteLib` and `dword_69B3E8`, but receiver evidence points to [UID:00005V][GrafPort](by-class/GrafPort.md) through vtable slot `+0x0c` / `GrafPort::UpdateRenderRegion` and accepted `m_surfaceContext` fields. Surface remains the callback/palette/render dependency context, not the direct owner. |
```

### SurfaceRenderCallbackTable

Placement: replace the [UID:0003XE] orphan note in [UID:0001PI] and [UID:0000TN] if present.

```text
- B005 2026-06-18 retry reclassifies [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) from no-owner Surface-family orphan to `GrafPort`-owned raw callback consumer. It calls slot `dword_69B3E8` at `0x004bb2ca`, but it is not a callback-table target or initializer; the direct owner evidence is the receiver's `GrafPort::UpdateRenderRegion` vtable call and `m_surfaceContext` field writes.
```

### No-Owner Tracker

Placement: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, replace or append to the `0003XE` row after supervisor applies metadata.

```text
| `0003XE` | 0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw | `by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md` | Agent-B005 | 2026-06-18 | complete-reroute | `Agent-B005/research/0003XE-SurfaceTileBufferBlitRaw-source-route-recheck.md` | Retry found owner/emitter breakthrough: `84/88`, owner `NONE`, blank emitters -> recommended `85/88`, owner/emitter [UID:00005V] `GrafPort`, formal C++ blank. Evidence: receiver vtable slot `+0x0c` resolves to `GrafPort::UpdateRenderRegion`; `this+0x20/+0x28/+0x2c` match accepted `GrafPort::m_surfaceContext` fields; callback/palette remain dependencies only. |
```

## Coverage Row Recommendation

Do not edit `by-memory/-coverage-report.md` directly from this B005 report. Replace the current [UID:0003XE] row with:

```text
    - [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) 0x004bb260-0x004bb2d7 | raw code | SurfaceTileBufferBlitRaw : reconstructable : 85% : strong : B005 2026-06-18 retry reroutes this formerly no-owner Surface-family raw body to [UID:00005V][GrafPort](by-class/GrafPort.md). Exact bytes/range remain `0x004bb260-0x004bb2d7` with fourteen-byte prepad, nine-byte postpad, and full `ret 8` at `0x004bb2d4-0x004bb2d6`; route scans still find no direct VA/RVA/rel32/table/short-branch entry route, so formal C++ remains blank. The breakthrough evidence is receiver identity: the body calls `call [vtable+0x0c]` at `0x004bb278`, and [UID:0003BE][GrafPortVtableData](by-memory/0x0061a8a4-0x0061a8b8.GrafPortVtableData.md) records `GrafPort` slot `+0x0c` as `0x004b8e20` / `GrafPort::UpdateRenderRegion`; the body then reallocates/stores `m_surfaceContext.pixelData` at `this+0x20`, copies `m_surfaceContext.rowStride` to `this+0x28`, copies `m_surfaceContext.bounds` to `this+0x2c`, resolves a null palette through `g_pPaletteLib` / `PaletteLib::GetCurrentPalette`, and dispatches `dword_69B3E8`. Surface/callback-table/palette are dependencies only; owner/emitter should be `00005V`, with C++ blank pending caller/signature proof.
```

If the supervisor also renames the page to `GrafPortSurfaceContextBlitRaw`, adjust the markdown link label and filename in the coverage row accordingly.

## Final State

This retry does not leave [UID:0003XE] as a bare blocker. The unresolved pieces are now specific and scoped:

- entry liveness remains unproven;
- original private method name/signature remains unproven;
- formal C++ remains unsafe;
- direct owner/source route is now defensibly `GrafPort`.

The active supervisor should accept the target as a breakthrough from no-owner/non-emitting `84/88` to routed `GrafPort` `85/88` with blank formal C++. This is stronger than keeping sub-85 and more faithful to by-structure than demoting an exact source-authored `.text` helper to ignored or non-reconstructable.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003XE","source_path":"executed-b-agent-research/B005/0003XE-SurfaceTileBufferBlitRaw-source-route-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
