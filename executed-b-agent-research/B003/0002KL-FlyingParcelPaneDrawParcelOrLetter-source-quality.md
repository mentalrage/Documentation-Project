** TARGET-REPORT-UID:0002KL **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002KL] FlyingParcelPaneDrawParcelOrLetter Source-Quality Research

Agent: B003  
Assignment: `B003-report-0002KL-flying-parcel-pane-draw-parcel-or-letter-20260625`  
Mode: report-only research first  
Target: `by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md`  
Report path: `tools/leaser/Agents/Agent-B003/research/0002KL-FlyingParcelPaneDrawParcelOrLetter-source-quality.md`

## Executive Recommendation

Implement a target-level source-quality refresh for UID `0002KL`.

Recommended target metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `88` | `91` |
| `CONFIDENCE` | `91` | `92` |
| `CANONICAL_OWNER` | `000058` | keep `000058` |
| `RECONSTRUCTABLE` | `TRUE` | keep `TRUE` |
| `EMITTER_UIDS` | `000058` | keep `000058` |
| `EMITTER_POSITION_OPTIONAL` | blank | keep blank |

Recommended target item summary:

`Draws the FlyingParcelPane parcel/letter sprite: initializes an EPFTileContext, uses m_isParcel to select ALERTBTN.EPF frame 5 or LETTER.EPF frame 0 with the matching palette, and renders into inherited m_bounds via RenderTileFrame.`

Recommended source placement remains [UID:000058] `FlyingParcelPane`, emitted through [UID:0000MF] `ParcelPane` / `NexusTK/ui/panels/ParcelPane.cpp`. Do not create a standalone `FlyingParcelPane.cpp` route. The target should now carry first-draft method C++; the class page [UID:000058] should remain formal-C++ blank for its separate declaration/raw-sibling/destructor-shape issues.

## Current State Checked

The target source page currently has:

- `COMPLETION:88`, `CONFIDENCE:91`.
- `CANONICAL_OWNER:000058`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000058`.
- Blank `EMITTER_POSITION_OPTIONAL`.
- Blank formal `RECONSTRUCTION_CPP CODE`.
- Summary: `Draws either ALERTBTN parcel art or LETTER art using matching palette resources.`

The target body is mostly correct on ownership and behavior, but it still has two stale source-quality blockers:

- It says final C++ remains blank because the old reconstruction-code gate required `95/95`. That gate is obsolete for this target. The target is reconstructable, has a nonblank emitter route, has a combined score above 85, and the helper/source names are now strong enough for target-level first-draft C++.
- It treats the second `RenderTileFrame` argument as a vague `scratch`/local buffer. Current EPFTileContext support and live stack layout show the argument at `ebp-0x1c` is `tileContext + 0x10`, i.e. `&tileContext.bounds`, not an independent scratch object.

Generated/tracker state is stale and must be refreshed by validators during implementation:

- `auto-generated/-ag-research-tracker.md` still lists UID `0002KL` as `74/84`, average `79.0`, not covered, with no report.
- `auto-generated/-ag-coverage-report-by-memory.md` still lists UID `0002KL` as `emits_code:false`, `74%`, with the old terse summary.
- `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` currently has validator command id `000000000821`, refresh timestamp `2026-06-25T00:51:56-04:00`, and still emits UID `0002KL` as `Completion:74 | Confidence:84 | Empty Emitter Marker`.
- Do not edit generated files manually. The implementation callback should use the normal validator-generated refresh path after source docs are updated.

## Documentation Inputs Checked

Target and source-route docs:

- `by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md`
- `by-class/FlyingParcelPane.md`
- `by-file/ParcelPane.md`
- `by-type/by-struct/ParcelNotificationPaneLayouts.md`
- `by-type/by-vtable/ParcelNotificationVtableFamily.md`
- `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`

Dependency docs:

- `by-global/g_pEPFLib.md`
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-class/EPFTileContext.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
- `by-global/SurfaceRenderCallbackTable.md`

Sibling and prior accepted report leads:

- `by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md`
- `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md`
- `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`
- `by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md`
- `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md`
- `by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md`
- `executed-b-agent-research/B012/000058-FlyingParcelPane-class-source-quality.md`
- `executed-b-agent-research/B007/0002KJ-FlyingParcelPaneConstructor-source-quality.md`
- `executed-b-agent-research/B002/0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md`
- `executed-b-agent-research/B001/0002KG-ParcelPaneOnPaint-source-quality.md`

## Live IDA MCP Evidence

MCP session:

- `idb_list`, JSON-RPC id `3`: active session `80de0a67`, file `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, `is_analyzing:false`.
- `server_health`, JSON-RPC id `4`: `status:ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.

Target boundary and neighbors:

- `lookup_funcs`, id `10`: `0x00546df0` is `sub_546DF0`, size `0x7b` / 123 bytes. `0x00546e6b` is not a function. Successor `0x00546e70` is `sub_546E70`, size `0xb`.
- Same id `10`: predecessor `0x00546d70` is `sub_546D70`, size `0x7e`; `0x00546dee` is not a function. Constructor `0x00546ac0` is `sub_546AC0`, size `0xb4`; raw starts `0x00546b80`, `0x00546bc0`, and `0x00546d64` are not function starts. Scalar deleting destructor `0x00546ed0` is `sub_546ED0`, size `0x67`.
- `get_bytes`, id `18`: `0x00546dee-0x00546df0` is two `0xcc` bytes before the target; the target body then ends in `retn` at `0x00546e6a`; `0x00546e6b-0x00546e70` is five `0xcc` bytes. The preceding raw-start padding at `0x00546d64-0x00546d70` is twelve `0xcc` bytes.

Target decompile/disassembly:

- `analyze_function`, id `11`: prototype recovered as `int __thiscall(_BYTE *this)`, size `123`, no ordinary callers, one data xref from `0x00621d10`, callees `sub_457A60`, `sub_4D02F0`, `sub_4B9980`, and `@__security_check_cookie@4`, four basic blocks, cyclomatic complexity 2.
- `decompile`, id `12`: the body initializes local storage with `sub_457A60(v4)`, branches on `this[252]`, uses `g_pEPFLib` / `dword_67A744`, loads either `ALERTBTN.EPF` frame `5` and `ALERTBTN.PAL` or `LETTER.EPF` frame `0` and `LETTER.PAL`, then calls `sub_4B9980((int)v4, (int)v5, (int)(this + 68), 1, paletteName, 0)`.
- `disasm`, id `13`: confirms the exact instruction sequence:
  - `0x00546e07`: call `sub_457A60`.
  - `0x00546e0c`: `cmp byte ptr [esi+0FCh], 0`.
  - `0x00546e16`: load `dword_67A744`.
  - `0x00546e1c`: `lea edi, [esi+44h]`, the inherited Pane bounds destination.
  - `0x00546e24`/`0x00546e2e`: `ALERTBTN.EPF` / `ALERTBTN.PAL`.
  - `0x00546e37`/`0x00546e41`: `LETTER.EPF` / `LETTER.PAL`.
  - `0x00546e4c`: `lea eax, [ebp+var_1C]`, which is `tileContext + 0x10`.
  - `0x00546e56`: call `sub_4B9980`.
  - `0x00546e62`: security-cookie check.
- `callees`, id `14`: only `sub_457A60`, `sub_4D02F0`, `sub_4B9980`, and `@__security_check_cookie@4`.

Resource, global, and vtable evidence:

- `xrefs_to`, id `15`: `0x00546df0` has exactly one xref, a data xref from `0x00621d10`.
- Same id `15`: `ALERTBTN.EPF` at `0x00621d50` has three xrefs: two from `ParcelPaneOnPaint` (`0x005468e7`, `0x00546937`) and one from this target (`0x00546e24`).
- Same id `15`: `ALERTBTN.PAL` at `0x00621d6c` has three xrefs: two from `ParcelPaneOnPaint` (`0x005468f3`, `0x00546943`) and one from this target (`0x00546e2e`).
- Same id `15`: `LETTER.EPF` at `0x00621d88` has one xref, from this target at `0x00546e37`.
- Same id `15`: `LETTER.PAL` at `0x00621da0` has one xref, from this target at `0x00546e41`.
- Same id `15`: `0x0067a744` has `231` xrefs in total. The target-specific use is the `0x00546e16` load shown by target disassembly.
- `get_int`, id `16`: vtable dwords confirm `0x00621d10 -> 0x00546df0`, `0x00621d4c -> 0x00546d70`, `0x00621ccc -> 0x00546ed0`, `0x00621d18 -> 0x00546e8b`, and `0x00621d48 -> 0x00546e96`. The dword at `0x00621d50` is string bytes, not a valid vtable slot.
- `get_string`, id `17`: strings decode as `ALERTBTN.EPF`, `ALERTBTN.PAL`, `LETTER.EPF`, and `LETTER.PAL`.

Helper evidence:

- `analyze_function`, id `20`: `0x004b9980` is a 49-byte palette-resolving wrapper. It calls `sub_543D70(dword_67A7E0, Source)` and then dispatches through `unk_69B3E8`; it has `311` xrefs/callers in total, so feature-local/fitting-room ownership is rejected. Source-facing target prose should call this shared dependency `RenderTileFrame`.
- `decompile`, id `26`: `0x004d02f0` searches/lazy-loads the resource entry, bounds-checks frame index `a3`, and writes EPFTileContext-like fields including pixel/stride/bounds/mask fields into the output pointer. Source-facing target prose should use `g_pEPFLib->LookupLayoutEntry(...)`.
- `decompile`, id `27`: `0x00457a60` initializes an EPFTileContext-like 0x28-byte record: sets format/state, zeroes pointer fields, initializes the rectangle at `this + 4*4`, and clears tail fields. Source-facing target prose should use `EPFTileContext tileContext; tileContext.Initialize();`.

Sibling and thunk evidence:

- `xrefs_to`, id `24`: no direct xrefs to constructor `0x00546ac0` or raw start `0x00546bc0`; this preserves existing negative reachability context and does not weaken target ownership because UID `0002KL` is vtable-reached.
- Same id `24`: `0x00546d70` has data xref from `0x00621d4c`; `0x00546ed0` has code jumps from adjustors `0x00546e91` and `0x00546e9c` plus data xref from `0x00621ccc`.
- Same id `24`: `0x00621ccc`, `0x00621d18`, and `0x00621d48` are written by constructor `0x00546ac0`, raw cleanup sites `0x00546b89/0x00546b8f/0x00546b99`, and scalar deleting destructor `0x00546ed0`.
- `disasm`, ids `28` and `29`: adjustor thunks are exactly `sub ecx, 0xa0; jmp 0x00546ed0` and `sub ecx, 0xa4; jmp 0x00546ed0`.

Conversion checks:

- `int_convert`, id `30`: `0x7b` is 123, `0x44` is 68, `0xfc` is 252, `0xa0` is 160, `0xa4` is 164, and `0x18` is 24.
- `int_convert`, id `25`: `5533168` converts to `0x546df0`, `5533040` to `0x546d70`, `5533392` to `0x546ed0`, `5533323` to `0x546e8b`, and `5533334` to `0x546e96`.

## Source Shape Resolution

The source-level method is best represented as:

- `void FlyingParcelPane::DrawParcelOrLetter()`
- Stack local: `EPFTileContext tileContext; tileContext.Initialize();`
- Branch flag: `m_isParcel` at `this + 0xfc`.
- Destination rectangle: inherited Pane bounds at `this + 0x44`, source-facing `m_bounds`.
- Source rectangle: `&tileContext.bounds`, not a scratch buffer.
- Resource receiver: `g_pEPFLib`, source-facing as an ImageLib/ResourceLayout-style receiver exposing `LookupLayoutEntry`.
- Render dependency: shared `RenderTileFrame` wrapper at `0x004b9980`.

The return type should be `void` in formal source, despite the decompiler's `int` prototype. UID `0002KG` `ParcelPane::OnPaint()` already resolved the same pattern for the parcel paint/draw virtual: the final helper return remains in `eax`, so Hex-Rays infers `int`, but pane paint/draw source slots should not return the render helper value. A `void` method ending with a `RenderTileFrame(...)` call is compatible with the observed binary epilogue leaving the callee return value in `eax`.

Do not add a `ReleaseBuffers` call or destructor cleanup for the stack EPFTileContext. There is no cleanup call in this function. The lookup path populates the draw descriptor for rendering; adding release/destructor behavior would invent source logic not present in the target.

The compiler security-cookie frame is generated by the stack local tile context/rectangle storage. Document it as compiler frame protection, not source behavior.

## Exact Formal C++ Recommendation

Populate UID `0002KL` with this exact formal block during the implementation callback:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FlyingParcelPane::DrawParcelOrLetter()
{
    EPFTileContext tileContext;
    tileContext.Initialize();

    const wchar_t *paletteName;
    if (m_isParcel) {
        g_pEPFLib->LookupLayoutEntry(L"ALERTBTN.EPF", 5, &tileContext);
        paletteName = L"ALERTBTN.PAL";
    } else {
        g_pEPFLib->LookupLayoutEntry(L"LETTER.EPF", 0, &tileContext);
        paletteName = L"LETTER.PAL";
    }

    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &m_bounds,
                    1,
                    paletteName,
                    0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation caveat: keep the EPFTileContext declaration spelling consistent with current accepted generated source. UID `0002KG` already emits `tileContext.Initialize()` and `&tileContext.bounds`, so UID `0002KL` should use the same spellings unless a coordinated EPFTileContext support pass changes both.

## Ownership, Placement, and Emitter Route

Keep direct canonical owner [UID:000058] `FlyingParcelPane`.

Evidence:

- Primary vtable draw slot `0x00621d10 -> 0x00546df0`.
- The branch flag is FlyingParcelPane payload field `+0xfc`, accepted as `m_isParcel`.
- Constructor/start/animate/destructor sibling pages use the same payload region and vtable family.
- Class/file docs already place `FlyingParcelPane` as an implementation-private or file-local helper under `ParcelPane.cpp`.

Keep emitting route [UID:000058] and file route through [UID:0000MF] `ParcelPane` / `NexusTK/ui/panels/ParcelPane.cpp`.

Do not move ownership to:

- `EPFTileContext`, `ResourceLayoutTable`, `ImageLib`, or `g_pEPFLib`: they own shared resource lookup and tile-context support only.
- `Surface`, `GrafPort`, or `SurfaceRenderCallbackTable`: they own the shared render wrapper/callback table only.
- `PaneParcelReadOnlyData`, `ParcelNotificationVtableData`, or `ParcelNotificationVtableFamily`: those are compiler/generated data inventories and slot-layout evidence, not source method owners.
- A standalone `FlyingParcelPane.cpp`: no source/header route or separate executable island proves that placement.

Keep `EMITTER_POSITION_OPTIONAL` blank. The current header and generated coverage use a blank position, and `ParcelPane.cpp` already orders UID `0002KL` after the FlyingParcelPane siblings by the existing route. The older target prose saying position `50` should be removed or rewritten as stale history rather than reintroduced into metadata.

## Rejected Alternatives and Negative Evidence

- Reject `DrawParcel` as the target's source-facing name when used alone. It hides the `LETTER` branch. Keep `DrawParcelOrLetter`.
- Reject generated `RenderBuffer`, `SpriteFrame`, `AssetManager`, `ObjectPane`, `RemoveFromObjectList`, and `DeliverParcel` names. B012 and current helper evidence show actual dependencies are EPFTileContext/resource lookup/shared rendering plus the FlyingParcelPane layer/timer siblings.
- Reject `m_isFlying` for `+0xfc`. The byte selects `ALERTBTN.*` when nonzero and `LETTER.*` when zero.
- Reject modeling `var_1C` / `v5` as an independent scratch buffer. It is the source rectangle inside the initialized EPFTileContext.
- Reject hand-authored static vtable data or compiler wrapper source for this target. UID `0002KL` is source-authored method body; vtables and adjustor/scalar destructor glue are separate generated artifacts.
- No direct code caller exists for `0x00546df0`; that is expected for a primary vtable draw virtual and does not block reconstruction.
- No direct xrefs to raw starts `0x00546bc0` or `0x00546b80` remain a raw-sibling/class-level caveat only. They do not block this vtable-reached draw target.

## Remaining Limits After Recommended Implementation

No target-level blocker remains for first-draft C++.

Residual caveats that should cap the score below final audit:

- Exact original method spelling is not source-file proven; `DrawParcelOrLetter` is the accepted source-facing descriptive name.
- Exact public type of `g_pEPFLib` remains support-level (`ImageLib*`, `ResourceLayoutTable*`, or a facet/base), but `g_pEPFLib->LookupLayoutEntry(...)` is the accepted target-level call shape.
- Exact declaration location for `FlyingParcelPane` remains private/file-local versus private-header, so the class page should keep its formal C++ block blank.
- Exact render callback typedef names remain Surface/GrafPort support caveats, but `RenderTileFrame` is sufficiently resolved for this target body.

These caveats justify `91/92` rather than final-audit scores; they should not keep the target C++ blank.

## Implementation Checklist For Callback

Implementation callback status as of 2026-06-25: complete after supervisor verification. The earlier `PAUSED_VALIDATOR_METADATA_CONFLICT` was traced to a stale in-memory validator-worker default. After the supervisor stopped the idle worker and reran the scoped normal target validator, command `000000000883` preserved the corrected manual coverage/default row, accepted target `Item Summary`, target metadata, formal C++ block, generated by-memory auto-coverage row, and matching E:/C: target copies. This report is ready for supervisor execution.

- [x] Lease only exact files immediately before editing them. Proof: initial B003 lease command succeeded for `by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md`, `by-class/FlyingParcelPane.md`, and `by-file/ParcelPane.md`; retry target-only leases also succeeded, including the post-supervisor-fix target lease before command `000000000865`. B003 released the target lease successfully after command `000000000865`, and `current_leases.md` after release listed no active leases. During earlier cleanup, `by-class/FlyingParcelPane.md` and `by-file/ParcelPane.md` had become B001 leases created `2026-06-25T05:18:43Z` expiring `2026-06-25T05:23:43Z`, so no further support edits were attempted.
- [x] Target UID `0002KL`: update metadata to `COMPLETION:91`, `CONFIDENCE:92`; keep `CANONICAL_OWNER:000058`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000058`, and blank `EMITTER_POSITION_OPTIONAL`. Proof: supervisor post-validator readback after command `000000000883` shows `91/92`, owner/emitter [UID:000058], reconstructable `TRUE`, and the formal C++ block survived.
- [x] Target UID `0002KL`: replace the item summary with the exact recommended summary from this report. Proof: the exact accepted summary was applied before normal target validation. Earlier commands `000000000830`, `000000000843`, and B003 retry `000000000865` restored the stale summary because the validator worker still had a stale in-memory default. Supervisor stopped the idle worker and reran the normal target validator as command `000000000883`; supervisor readback confirms the target now preserves `Draws the FlyingParcelPane parcel/letter sprite: initializes an EPFTileContext, uses m_isParcel to select ALERTBTN.EPF frame 5 or LETTER.EPF frame 0 with the matching palette, and renders into inherited m_bounds via RenderTileFrame.`
- [x] Target UID `0002KL`: add current MCP session `80de0a67` evidence for command ids `3`, `4`, `10` through `18`, `20`, and `24` through `30`, including lookup/decompile/disasm/xrefs/bytes/vtable/helper/string/thunk proof. Proof: target `Live IDA MCP Evidence` section now records the session, health, boundary/bytes, decompile/disasm/callees, resource/global/vtable/string evidence, helper decompiles, sibling/thunk evidence, and int conversions.
- [x] Target UID `0002KL`: replace stale blank-C++/`95/95` gate prose with the target-specific first-draft C++ rationale. Proof: target `Status` now states the current reconstructable/nonblank-emitter/code-entry gate and marks the old final-code gate prose superseded.
- [x] Target UID `0002KL`: replace the old `scratch` wording with `&tileContext.bounds`, and document that the stack local is a single initialized EPFTileContext record whose `bounds` field supplies the source rectangle. Proof: target `Behavior`, `Source Shape Resolution`, and formal C++ use `&tileContext.bounds` and describe the ambiguous local as the bounds field inside the initialized `EPFTileContext`.
- [x] Target UID `0002KL`: insert the exact formal C++ block from this report. Proof: target formal `RECONSTRUCTION_CPP CODE` block and generated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` both contain `void FlyingParcelPane::DrawParcelOrLetter()` with the accepted `EPFTileContext`, `m_isParcel`, `g_pEPFLib->LookupLayoutEntry`, `RenderTileFrame`, `&tileContext.bounds`, and `&m_bounds` body.
- [x] Target UID `0002KL`: add negative evidence/rejected alternatives for `DrawParcel`, `m_isFlying`, generated `RenderBuffer`/`SpriteFrame`/`AssetManager`/`ObjectPane` names, no `ReleaseBuffers`, security cookie as compiler frame protection, and dependency-only helper owners. Proof: target `Rejected Alternatives And Negative Evidence`, `Source Shape Resolution`, and `Boundary, Owner, And Emitter Decision` sections document each rejection.
- [x] `by-class/FlyingParcelPane.md`: update UID `0002KL` method row/evidence/open-question text to say the method-level render-helper/source-shape blocker is resolved and target-level first-draft C++ is now appropriate, while the class page formal block remains blank for declaration/raw-sibling/destructor-shape reasons. Proof: class method row, B003 evidence bullet, class-level formal C++ no-code proof, assignment gate, closed questions, and change log all record the target-level resolution and class-level blank block distinction.
- [x] `by-class/FlyingParcelPane.md`: keep `DrawParcelOrLetter`, `m_isParcel`, `m_animationLayer`/`m_screenLayerEntry`, raw start negative evidence, and scalar deleting destructor policy unchanged except for the new UID `0002KL` target-specific resolution. Proof: class layout/method/evidence sections preserve those names and policies; no scalar deleting destructor source C++ was added.
- [x] `by-file/ParcelPane.md`: add a concise B003 sync note that UID `0002KL` now emits first-draft `FlyingParcelPane::DrawParcelOrLetter()` through `NexusTK/ui/panels/ParcelPane.cpp`, and preserve the implementation-private/file-local helper-class caveat. Proof: file `File Role`, `Migration Notes`, and `Changes` sections contain the B003 sync note and retain the private/file-local helper caveat.
- [x] Check `ParcelNotificationPaneLayouts`, `ParcelNotificationVtableFamily`, `ParcelNotificationVtableData`, `g_pEPFLib`, `EPFTileContext`, `SurfacePaintHelpers`, and `SurfaceRenderCallbackTable` during implementation. Proof: read-only contradiction scan found no direct contradiction; no support docs outside the accepted target/class/file set were edited.
- [x] Do not edit generated files, project-level files, validator state/cache, IDA DB, or any `-coverage-report.md` file. Proof: only target/support by-* docs and this B003 report were manually edited; generated/project-level changes were validator-owned side effects.
- [x] Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc. Proof:
  - Target: `python .\tools\validator.py --mode file --file by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000000830`; `command_timestamp: 2026-06-25T01:18:45-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`; `generated_refresh_command_id: 000000000830`; generated timestamp `2026-06-25T01:18:45-04:00`.
  - Class: `python .\tools\validator.py --mode file --file by-class\FlyingParcelPane.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000000832`; `command_timestamp: 2026-06-25T01:19:00-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`; `generated_refresh_command_id: 000000000832`; generated timestamp `2026-06-25T01:19:00-04:00`.
  - File: `python .\tools\validator.py --mode file --file by-file\ParcelPane.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000000836`; `command_timestamp: 2026-06-25T01:19:20-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`; `generated_refresh_command_id: 000000000836`; generated timestamp `2026-06-25T01:19:20-04:00`.
  - Target retry after summary reapply: `python .\tools\validator.py --mode file --file by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000000843`; `command_timestamp: 2026-06-25T01:20:38-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`; `generated_refresh_command_id: 000000000843`; generated timestamp `2026-06-25T01:20:38-04:00`.
  - Supervisor-owned manual coverage/default-row correction for UID `0002KL`: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`; `command_id: 000000000857`; `command_timestamp: 2026-06-25T01:23:47-04:00`; exit code `0`; `ok: 1`. B003 did not edit the coverage report.
  - Target retry after supervisor correction and worker restart: `python .\tools\validator.py --mode file --file by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000000865`; `command_timestamp: 2026-06-25T01:27:27-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`; `generated_refresh_command_id: 000000000865`; generated timestamp `2026-06-25T01:27:27-04:00`.
  - Supervisor-side clear validation after stopping the idle stale worker: `python .\tools\validator.py --mode file --file by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000000883`; `command_timestamp: 2026-06-25T01:31:00-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`.
- [x] Record validator command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state in this report checklist after implementation. Proof: recorded above.
- [x] Re-read target and generated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` after validation. Confirm target metadata `91/92`, summary, C++ block, and generated source body remain intact after normal refresh. Proof: B003 post-command `000000000865` readback confirmed target `91/92`, formal C++ block, and generated `ParcelPane.cpp` header `validator-command-id: 000000000865` with `FlyingParcelPane::DrawParcelOrLetter()` body using `EPFTileContext`, `m_isParcel`, `g_pEPFLib->LookupLayoutEntry`, `RenderTileFrame`, `&tileContext.bounds`, and `&m_bounds`; only the target summary remained stale at that point. Supervisor post-command `000000000883` readback confirms the accepted summary now survives, metadata remains `91/92` with owner/emitter [UID:000058] and reconstructable true, formal `FlyingParcelPane::DrawParcelOrLetter()` C++ survived, generated by-memory auto coverage row has the accepted summary, and E:/C: target copies hash the same.

## Report-Only Proof

- No leases were taken for this report-only pass.
- No target/support by-* docs were edited.
- No generated files, project-level files, coverage reports, validator state/cache, or IDA database state were edited.
- Validators were not run because this pass only created the B003 research report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002KL-FlyingParcelPaneDrawParcelOrLetter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002KL-FlyingParcelPaneDrawParcelOrLetter-source-quality.md","timestamp":"2026-06-25T01:39:48","uid":"0002KL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
