** TARGET-REPORT-UID:0001A5 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0001A5 BlueAlertPaneCore Source-Quality Report

## Target

- Target doc: `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md`
- UID: `0001A5`
- Current title/range: `0x005008c0-0x0050114d BlueAlertPaneCore`
- Current owner/emitter: [UID:00000Y] `BlueAlertPane`
- Current related source file: [UID:0000HE] `AlertPanes`
- Current assignment: report-only source-quality reanalysis for constructor reachability, class/file ownership, method split, vtable-only handler refs, `BDFRAME.EPF` rendering, callback/field names, and first-draft C++ versus no-code disposition.

## Current Target State

- Current metadata in the target doc is `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00000Y`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000Y`.
- Current formal C++ is a marker comment only, not a method-body draft. The marker correctly states that IDA confirms constructor, action handler, draw methods, vtable-only handler reachability, `BDFRAME.EPF` rendering, and layout-reference storage, but not a safe source class/body rewrite.
- Current covered function cluster:
  - `0x005008c0-0x00500c24`: `sub_5008C0`, constructor-shaped `BlueAlertPane::BlueAlertPane`, size `0x364`.
  - `0x00500c24-0x00500c30`: `0xcc` alignment.
  - `0x00500c30-0x00500c70`: `sub_500C30`, action-button handler, size `0x40`.
  - `0x00500c70-0x00500d6e`: `sub_500C70`, selected-item-frame draw method, size `0xfe`.
  - `0x00500d6e-0x00500d70`: `0xcc` alignment.
  - `0x00500d70-0x00500e19`: `sub_500D70`, content draw method, size `0xa9`.
  - `0x00500e19-0x00500e20`: `0xcc` alignment.
  - `0x00500e20-0x0050114d`: `sub_500E20`, border-frame draw method, size `0x32d`.
  - `0x0050114d-0x00501150`: successor alignment before [UID:0001A6] `UserCreateAppearanceSelectorControls`.
- Support docs are already broadly synchronized: [UID:00000Y] `BlueAlertPane`, [UID:0000HE] `AlertPanes`, [UID:0001X3] `BlueAlertPaneVtables`, [UID:0002M6] `BlueAlertPaneVtableData`, [UID:0001TO] `AlertPaneLayout`, [UID:0001R5] `alert-dialog-resources`, and [UID:0000SV] `g_uiTileRenderer`.

## Evidence Checked

- Read target doc `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md`.
- Read support docs:
  - `by-class/BlueAlertPane.md`
  - `by-file/AlertPanes.md`
  - `by-type/by-vtable/BlueAlertPaneVtables.md`
  - `by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md`
  - `by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md`
  - `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`
  - `by-type/by-struct/AlertPaneLayout.md`
  - `by-resource/alert-dialog-resources.md`
  - `by-global/g_uiTileRenderer.md`
  - `by-class/AlertPane.md`
  - `by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md`
  - `by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md`
  - `by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md`
- Used IDA MCP session `supervisor_resume_20260629`.
- MCP health/session state:
  - `idb_list`: one active worker session, `session_id:"supervisor_resume_20260629"`, input IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, `pid:14860`, `worker_pid:14860`, `is_analyzing:false`.
  - `server_health`: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- MCP exact boundary lookup:
  - `lookup_funcs 0x005008b9`: not a function.
  - `lookup_funcs 0x005008c0`: `sub_5008C0`, size `0x364`.
  - `lookup_funcs 0x00500c23`: inside `sub_5008C0`.
  - `lookup_funcs 0x00500c24`: not a function.
  - `lookup_funcs 0x00500c30`: `sub_500C30`, size `0x40`.
  - `lookup_funcs 0x00500c70`: `sub_500C70`, size `0xfe`.
  - `lookup_funcs 0x00500d6e`: not a function.
  - `lookup_funcs 0x00500d70`: `sub_500D70`, size `0xa9`.
  - `lookup_funcs 0x00500e19`: not a function.
  - `lookup_funcs 0x00500e20`: `sub_500E20`, size `0x32d`.
  - `lookup_funcs 0x0050114c`: inside `sub_500E20`.
  - `lookup_funcs 0x0050114d`: not a function.
  - `lookup_funcs 0x00501150`: successor `sub_501150`, size `0x15f`.
- MCP xrefs:
  - `xrefs_to 0x005008c0`: zero xrefs.
  - `find_bytes "c0 08 50 00"`: zero raw little-endian pointer hits for the constructor address.
  - `xrefs_to 0x00500c30`: one data xref at `0x0061dd20`, primary BlueAlertPane vtable slot.
  - `xrefs_to 0x00500c70`: one data xref at `0x0061dd1c`, primary BlueAlertPane vtable slot.
  - `xrefs_to 0x00500d70`: one data xref at `0x0061dd28`, primary BlueAlertPane vtable slot.
  - `xrefs_to 0x00500e20`: one data xref at `0x0061dd2c`, primary BlueAlertPane vtable slot.
  - `xrefs_to 0x0061dcd8`, `0x0061dd40`, `0x0061dd70`: constructor stores at `0x00500920`, `0x00500926`, and `0x00500930`.
  - `xrefs_to 0x0061e554`: nine `BDFRAME.EPF` refs at `0x00500ded`, `0x00500e91`, `0x00500f03`, `0x00500f6b`, `0x00500fd8`, `0x00501029`, `0x00501079`, `0x005010c5`, and `0x00501119`.
  - `xref_query 0x0069b3e8`: 114 data refs; BlueAlertPane border refs include `0x00500eb4`, `0x00500f24`, `0x00500f89`, `0x00500ff6`, `0x0050104b`, `0x00501097`, `0x005010e3`, and `0x00501137`.
  - `xrefs_to 0x0069b3ec`: eleven direct data refs, including BlueAlertPane `DrawContent` at `0x00500dcb`.
  - `xref_query 0x0069b3fc`: 206 data refs; BlueAlertPane content/nearby refs include `0x00500da4`.
- MCP callee sets:
  - `sub_5008C0`: `0x0049d8a0`, `0x00516030`, `0x005447c0`, `0x004b8e00`, `0x004ba9a0`, `0x0058ee90`, `0x004b7c50`, `0x004f4aa0`, `0x00499030`, `0x0049dc10`, `0x00495040`, `0x0049dd80`, `0x0049ddd0`, `0x0049dfd0`, `0x0049e190`, `0x0049eac0`, and `@__security_check_cookie@4`.
  - `sub_500C30`: `0x0049eb90`, `0x0049dad0`.
  - `sub_500C70`: `0x004b7e30`, `0x004b9660`, `0x004ba450`, and `@__security_check_cookie@4`.
  - `sub_500D70`: `0x00457a60`, `0x004b9660`, `0x0069b3fc`, `0x0069b3ec`, `@__security_check_cookie@4`, `0x004d02f0`, and `0x004ba6b0`.
  - `sub_500E20`: `0x00457a60`, `0x004b7c50`, `0x004b7e10`, `0x004d02f0`, `0x0069b3e8`, and `@__security_check_cookie@4`.
- MCP block and instruction counts:
  - `sub_5008C0`: 54 blocks, 338 instructions.
  - `sub_500C30`: 5 blocks, 28 instructions.
  - `sub_500C70`: 6 blocks, 91 instructions.
  - `sub_500D70`: 3 blocks, 61 instructions.
  - `sub_500E20`: 11 blocks, 302 instructions.
  - Cluster total: 79 basic blocks and 820 instructions.
- MCP decompiler prototype artifacts:
  - `sub_5008C0`: `boost::exception *__thiscall sub_5008C0(`, 184 decompiler lines, proving current type-owner pollution and unresolved constructor signature/base spelling.
  - `sub_500C30`: `void __userpurge sub_500C30(int *a1@<ecx>, int a2@<ebx>, int a3, int a4)`, 15 lines, proving non-final ABI artifact for the action callback.
  - `sub_500C70`: `void __usercall sub_500C70(_DWORD *a1@<ecx>, int a2@<esi>)`, 38 lines, proving non-final draw-method prototype artifact.
  - `sub_500D70`: `void __thiscall sub_500D70(int this)`, 19 lines.
  - `sub_500E20`: `_DWORD *__thiscall sub_500E20(_DWORD *this)`, 79 lines.
- MCP byte and string evidence:
  - `0x005008b9-0x005008c0`: `cc cc cc cc cc cc cc`.
  - `0x00500c24-0x00500c30`: twelve `cc` bytes.
  - `0x00500d6e-0x00500d70`: `cc cc`.
  - `0x00500e19-0x00500e20`: seven `cc` bytes.
  - `0x0050114d-0x00501150`: `cc cc cc`.
  - `0x0061e554`: UTF-16 bytes for `BDFRAME.EPF`, and `get_string 0x0061e554` returns `BDFRAME.EPF`.

## Positive Evidence Summary

- The exact target range is live and internally coherent: five modeled functions, exact `0xcc` gaps, exact predecessor padding, and exact successor padding before [UID:0001A6] at `0x00501150`.
- The constructor is a real `0x364` function, installs the three `BlueAlertPane` vtable views at `+0x00`, `+0xa0`, and `+0xa4`, and stores the vtable bases `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70` at `0x00500920`, `0x00500926`, and `0x00500930`.
- The constructor stores/reuses the alert-family layout reference at `+0x26c`, matching [UID:0001TO] `AlertPaneLayout` and the parent `AlertPane` field name `m_layoutReference`.
- The four custom methods are not orphaned random code: each is referenced from the primary `BlueAlertPane` vtable and has an exact method role already recorded by [UID:0001X3] and [UID:0002M6].
- The action handler at `0x00500c30` dispatches only the primary/secondary alert action path and then closes/dismisses through alert/dialog helpers; it is a BlueAlertPane override of the action-button handling behavior, not a standalone utility.
- `DrawContent` at `0x00500d70` has the exact two-path behavior currently documented: if `this+0x260` is nonzero, it uses the alternate content/draw callbacks through `dword_69B3FC` and `dword_69B3EC`; otherwise it resolves `BDFRAME.EPF` frame `8` through `dword_67A744` / `sub_4D02F0` and draws through the broad surface/tile helper path.
- `DrawBorderFrame` at `0x00500e20` skips the border drawing when `this+0x260` is nonzero. Otherwise it resolves and draws `BDFRAME.EPF` frames `1`, `6`, `3`, `4`, `0`, `2`, `5`, and `7`, matching horizontal edge, vertical edge, and corner roles in [UID:0001R5] `alert-dialog-resources`.
- Render callbacks are current-session verified: `dword_69B3E8` has 114 direct data refs and is used by the border draw loop; `dword_69B3EC` has eleven direct data refs and is used by `DrawContent`; `dword_69B3FC` is broad/high-fanout and is used by the alternate content path.
- The generated `g_uiTileRenderer` name remains correctly rejected: live evidence shows `dword_67A744`, `sub_4D02F0`, and surface callback slots, not a backing `g_uiTileRenderer` storage object.
- Support ownership is already strong enough: `BlueAlertPane` is attached to [UID:0000HE] `AlertPanes`; `BlueAlertPaneVtables` and `BlueAlertPaneVtableData` tie the executable methods to class-level virtual slots; `AlertPaneLayout` supplies `m_layoutReference` at `+0x26c`; `alert-dialog-resources` supplies the `BDFRAME.EPF` frame contract.

## Negative Evidence Summary

- Constructor reachability remains unresolved. Current MCP reports zero xrefs to `0x005008c0`, and `find_bytes "c0 08 50 00"` finds zero raw little-endian pointer hits for the constructor address in the IDB.
- The four non-constructor methods remain vtable-only in direct xrefs. That is acceptable for virtual overrides but not enough to prove a constructor allocation/call route or the runtime feature entry point for the BlueAlertPane instance.
- Decompiler prototypes are not source-quality:
  - The constructor returns `boost::exception *`, a known stale/type-polluted artifact.
  - The action handler is printed as `__userpurge` with an `ebx` artifact.
  - The selected-frame draw method is printed as `__usercall` with an `esi` artifact.
  - `DrawContent` still uses `int this`, and `DrawBorderFrame` returns `_DWORD *`.
- Exact constructor parameter names and types are not source-quality. The body clearly uses a layout/reference pane and alert/dialog construction helpers, but no live caller fixes the original signature or argument order.
- `this+0x260` remains behaviorally known as the alternate/custom-draw mode or frame-suppression flag, but the source-facing field name and owning base/member are not final.
- The target body depends on several still-provisional helper names and callback typedefs: EPF tile context setup (`0x00457a60`), rect helpers (`0x004b7c50`, `0x004b7e10`, `0x004b7e30`), draw-context setup (`0x004b9660`, `0x004ba450`, `0x004ba6b0`, `0x004ba9a0`), and `SurfaceRenderCallbackTable` callback signatures.
- The constructor calls `0x0049d8a0`/DialogPane-family setup rather than a clean decompiled `AlertPane::AlertPane` call, so the exact C++ inheritance spelling is still unsafe as either a simple `AlertPane(...)` base initializer or a direct `DialogPane(...)` initializer.
- No support page checked shows stale contradictory text requiring immediate report-only support-doc changes. Existing support docs already say BlueAlertPane is structural/live but no class shell or method-body rewrite is safe.

## Heuristic / Inference Reanalysis And Validation

- Heuristic: vtable installation plus vtable-only method refs can establish class ownership even when constructor callers are missing.
  - Validation: `xrefs_to` ties `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70` directly to constructor stores, and the primary table slots at `0x0061dd1c`, `0x0061dd20`, `0x0061dd28`, and `0x0061dd2c` point to the four custom methods. This supports [UID:00000Y] as direct owner.
  - Limit: this does not resolve allocation/caller route or source constructor signature.
- Heuristic: generated object-like renderer names should be rejected when IDA shows only global callback/table loads.
  - Validation: current `DrawContent`/`DrawBorderFrame` refs show `dword_67A744`, `sub_4D02F0`, `dword_69B3FC`, `dword_69B3EC`, and `dword_69B3E8`; no `g_uiTileRenderer` storage is present. This validates existing ignored-alias handling.
- Heuristic: no direct constructor refs might mean dead code.
  - Validation: reject the dead-code conclusion. The constructor installs live class vtables, the vtable data is exact and class-attached, and four custom methods have primary-vtable refs. The safer conclusion is "live class structure with unresolved construction route", not "unowned or dead".
- Heuristic: the containing [UID:0001A4] `SpecializedButtonPanes` aggregate might own this range by address adjacency.
  - Validation: reject. [UID:0001A4] explicitly treats this subrange as a separate BlueAlertPane child routed through alert-pane docs. The predecessor `0x00500640-0x005008c0` and successor `0x00501150-0x00502383` belong to different source families.
- Heuristic: method split could improve emission.
  - Validation: do not require a split for this callback. The exact target range is a coherent BlueAlertPane method cluster with precise padding and no mixed-owner executable bodies. Separate method children might be useful in a later method-body source-quality pass, but splitting now would not solve the constructor route, base-class spelling, callback typedef, or helper-name blockers.

## Ranked Ownership Analysis

| Rank | Candidate owner | Disposition | Evidence and reason |
| ---: | --- | --- | --- |
| 1 | [UID:00000Y] `BlueAlertPane` | Accept direct owner/emitter | The constructor stores the three BlueAlertPane vtable views; the primary vtable points to `HandleActionButton`, `DrawSelectedItemFrame`, `DrawContent`, and `DrawBorderFrame`; the class page already documents `m_layoutReference` and the same method cluster. |
| 2 | [UID:0000HE] `AlertPanes` | Accept source-file owner/support parent | `BlueAlertPane` is an alert/dialog class in the shared alert-pane family; `AlertPanes` owns the class source placement and already clears the support gate. |
| 3 | [UID:00000B] `AlertPane` / [UID:0001TO] `AlertPaneLayout` | Accept support, reject direct owner | Supplies base callback names `OnPrimaryButton`/`OnSecondaryButton`, `m_layoutReference`, shared destructor, and three-view layout. The Blue class overrides and frame rendering are not base `AlertPane` code. |
| 4 | [UID:0001X3] `BlueAlertPaneVtables` and [UID:0002M6] `BlueAlertPaneVtableData` | Accept support, reject direct source owner | These pages prove vtable slots and data range. They are compiler-emitted/type evidence, not the source owner for executable method bodies. |
| 5 | [UID:0001R5] `alert-dialog-resources` and [UID:0000QU] `g_pEPFLib` | Accept support/resource context, reject direct owner | They own or index `BDFRAME.EPF` resource lookup context. They do not own BlueAlertPane frame-selection code. |
| 6 | [UID:0000TN] `SurfaceRenderCallbackTable` / [UID:0000OC] `Surface` | Accept render callback support, reject direct owner | `dword_69B3E8`, `dword_69B3EC`, and `dword_69B3FC` are callback slots used by the methods. The Blue class chooses frame ids and positions. |
| 7 | [UID:0001A4] `SpecializedButtonPanes` | Reject aggregate owner | It is a broad mixed-owner container and explicitly delegates this subrange to BlueAlertPane/AlertPanes. |
| 8 | [UID:0001A6] `UserCreateAppearanceSelectorControls` | Reject successor owner | It starts at `0x00501150`, after `0x0050114d-0x00501150` padding. No split or ownership bleed into UID0001A5. |
| 9 | [UID:0000SV] `g_uiTileRenderer` | Reject invalid generated alias | Current evidence shows EPF lookup and surface callback globals, not a backing renderer singleton. |
| 10 | Generated Ranking/callsite ownership | Reject stale/insufficient | Constructor has no direct xrefs, and handler refs are vtable data only. Ranking/callsite heuristics cannot override class/vtable/file evidence. |

## Source Placement

- Recommended source placement remains [UID:0000HE] `AlertPanes`, likely `NexusTK/ui/dialogs/AlertPanes.cpp`, through the [UID:00000Y] `BlueAlertPane` class page.
- UID0001A5 should remain an executable method-cluster evidence page attached to `BlueAlertPane`, not a separate top-level source file.
- The original source probably declared `BlueAlertPane` beside `AlertPane`, `VersatileAlertPane`, and `UrlAlertPane`, but current evidence still does not prove a safe full `class BlueAlertPane : public AlertPane` shell because the constructor decompilation does not show a clean base-constructor call and no caller proves the original constructor signature.
- Keep render helper placement split:
  - Resource lookup belongs to EPF/ImageLib/ResourceLayout support.
  - Blitting belongs to Surface/SurfaceRenderCallbackTable support.
  - Frame id selection, border/content placement, and alternate-mode branching belong to `BlueAlertPane`.
- Keep aggregate placement split:
  - `0x00500640-0x005008c0` belongs to specialized gender/direction button control docs.
  - `0x005008c0-0x0050114d` belongs to BlueAlertPane.
  - `0x0050114d-0x00501150` is padding.
  - `0x00501150` begins user-create appearance controls.

## Score And Metadata Recommendation

- Recommended target metadata after implementation callback:
  - `COMPLETION:87`
  - `CONFIDENCE:90`
  - Keep `CANONICAL_OWNER:00000Y`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00000Y`
  - Keep blank/no-body formal C++, but replace the current generic marker with a target-specific no-code proof.
- Rationale for raising completion from `85` to `87`: current MCP evidence now explicitly records health/session state, exact function and padding boundaries, zero constructor xrefs plus zero raw constructor pointer hits, vtable-only method refs, full callee sets, block/instruction totals, decompiler prototype artifacts, current callback/global/resource evidence, and exact source-placement/ownership rejection logic.
- Rationale for raising confidence from `88` to `90`: the class/vtable/range/resource facts are internally consistent across live IDA and support docs. Confidence remains below final-source because constructor reachability, constructor signature, exact base initializer spelling, `+0x260` field name, and callback/helper typedefs are unresolved.

## First-Draft C++ Recommendation

Do not add method-body C++ for UID0001A5 during callback. Add a concrete no-code proof in the target's existing formal C++ block instead.

Recommended marker content, preserving the target's existing `RECONSTRUCTION_CPP CODE:BEGIN` / `END` markers:

```cpp
// BlueAlertPane executable method-cluster evidence only.
// Current IDA session supervisor_resume_20260629 confirms the constructor at
// 0x005008c0, action handler at 0x00500c30, selected-frame draw at 0x00500c70,
// content draw at 0x00500d70, border draw at 0x00500e20, exact inter-method
// padding, three BlueAlertPane vtable stores, vtable-only handler reachability,
// m_layoutReference storage at +0x26c, BDFRAME.EPF frame 0-8 use, and render
// callback use through dword_69B3E8/dword_69B3EC/dword_69B3FC.
// No source body is emitted yet because the constructor still has no direct
// xrefs or raw pointer hits, Hex-Rays prints non-source prototypes, the exact
// constructor signature/base-initializer spelling is unproven, +0x260 still
// lacks a final field name, and the EPF/surface callback typedefs and draw
// helper names are not source-quality.
```

Specific blockers that this marker must preserve:

- Constructor route blocker: `xrefs_to 0x005008c0` is empty and raw little-endian pointer search for `c0 08 50 00` has zero hits. A source constructor body would need an original signature and caller/allocation route that current evidence does not provide.
- Class-shell blocker: the owning `BlueAlertPane` class page still cannot safely emit `class BlueAlertPane : public AlertPane` because the constructor decompile calls DialogPane-family setup directly and no caller proves original constructor parameters.
- Callback typedef blocker: `dword_69B3E8`, `dword_69B3EC`, and `dword_69B3FC` are real callback slots, but final function pointer typedefs and argument names are still owned by Surface/SurfaceRenderCallbackTable work.
- Field-name blocker: `+0x26c` can be named `m_layoutReference` from AlertPane support, but `+0x260` should remain a behavior field/alternate-mode flag until the class layout pass names it.
- Helper-name blocker: resource lookup and drawing helpers (`sub_4D02F0`, `sub_457A60`, `sub_4B7C50`, `sub_4B7E10`, `sub_4B9660`, `sub_4BA450`, `sub_4BA6B0`, `sub_4BA9A0`) are not final enough for a source-quality method body in this target.
- Method-cluster blocker: the target contains five methods plus padding. A later method-specific split could emit individual bodies once the above dependencies are resolved, but emitting all bodies here now would freeze non-source prototypes and helper aliases.

## Recommended Target Doc Changes

- Update metadata:
  - `COMPLETION:87`
  - `CONFIDENCE:90`
  - Keep `CANONICAL_OWNER:00000Y`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00000Y`
- Replace the current formal C++ marker with the target-specific no-code proof under `## First-Draft C++ Recommendation`. Do not duplicate the formal C++ header/footer marker lines.
- Add current MCP evidence from session `supervisor_resume_20260629`:
  - health/session state;
  - exact lookup results for target starts, padding points, and successor `0x00501150`;
  - zero constructor xrefs and zero `c0 08 50 00` raw pointer hits;
  - vtable-only handler xrefs;
  - vtable-store xrefs at `0x00500920`, `0x00500926`, `0x00500930`;
  - `BDFRAME.EPF` string at `0x0061e554` and nine xrefs;
  - callee sets for all five functions;
  - 79 blocks and 820 instructions, with per-function counts;
  - decompiler prototype artifacts;
  - exact padding bytes at all boundaries;
  - callback global counts/uses for `dword_69B3E8`, `dword_69B3EC`, and `dword_69B3FC`.
- Add explicit ownership reanalysis:
  - accept direct owner [UID:00000Y] `BlueAlertPane`;
  - accept file/source placement [UID:0000HE] `AlertPanes`;
  - accept support roles for `AlertPane`, `AlertPaneLayout`, vtable docs, resource docs, EPF/ImageLib/ResourceLayout, and SurfaceRenderCallbackTable;
  - reject direct ownership by `SpecializedButtonPanes`, `UserCreateAppearanceSelectorControls`, `g_uiTileRenderer`, generated Ranking/callsite heuristics, BDFRAME resource docs, and generic Surface callback docs.
- Preserve split/range facts:
  - predecessor `0x005008b9-0x005008c0` is padding after the specialized button-control child range;
  - successor `0x0050114d-0x00501150` is padding before UID0001A6;
  - no UID0001A5 range split is recommended for this callback.

## Recommended Support Doc Changes

- No support-doc edits are recommended for this callback unless the implementer finds direct stale/conflicting text while editing the target.
- `by-class/BlueAlertPane.md` is already consistent: it records the class as structural/live, attached to AlertPanes, with no direct constructor caller/allocation route and no safe class shell.
- `by-file/AlertPanes.md` is already consistent: it records BlueAlertPane as a real alert-family class but keeps live construction and exact source declarations open.
- `by-type/by-vtable/BlueAlertPaneVtables.md` and `by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md` are already consistent with the vtable stores, slot refs, and constructor reachability caveat.
- `by-type/by-struct/AlertPaneLayout.md` is already consistent with `m_layoutReference` at `+0x26c` and with leaving final class sizes/base declarations open.
- `by-resource/alert-dialog-resources.md` and `by-global/g_uiTileRenderer.md` are already consistent with `BDFRAME.EPF` frame usage and rejection of `g_uiTileRenderer` as a backing singleton.
- `by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md` and `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md` are already consistent with the predecessor/successor split.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| A5-C01 | Target metadata should move to `COMPLETION:87`, `CONFIDENCE:90`, while keeping `CANONICAL_OWNER:00000Y`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000Y`. | High | Current MCP adds exact session, range, xref, callee, block, instruction, byte, resource, and no-route evidence beyond the current `85/88` target text. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` metadata block and score rationale | incorporate | applied |
| A5-C02 | UID0001A5 should remain owned/emitted by [UID:00000Y] `BlueAlertPane`. | High | Constructor stores three BlueAlertPane vtables and primary vtable slots reference all four custom methods. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` status, ownership, and score rationale sections | already-present | already-present |
| A5-C03 | Constructor reachability remains unresolved and should be stated with exact current evidence. | High | `xrefs_to 0x005008c0` has zero xrefs, and `find_bytes c0 08 50 00` has zero raw little-endian pointer hits. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` evidence and formal no-code proof sections | incorporate | applied |
| A5-C04 | Handler reachability is vtable-only, not direct caller-based. | High | Each custom handler has exactly one data xref from primary vtable slots `0x0061dd1c`, `0x0061dd20`, `0x0061dd28`, or `0x0061dd2c`. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` evidence and ownership reanalysis sections | incorporate | applied |
| A5-C05 | The range boundaries and padding should be preserved without splitting UID0001A5 during this callback. | High | MCP lookup and byte evidence prove the five functions and padding gaps; support aggregate and successor docs already agree. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` covered ranges and boundary notes | incorporate | applied |
| A5-C06 | The first-draft C++ disposition should remain no-code, but the marker should become target-specific and proof-based. | High | Decompiler prototypes, missing constructor route, `+0x260`, callback typedefs, and helper names block safe method-body emission. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` formal `RECONSTRUCTION_CPP CODE` block | incorporate | applied |
| A5-C07 | `BDFRAME.EPF` frame evidence should include the current string address and nine xrefs. | High | `get_string 0x0061e554` returns `BDFRAME.EPF`; xrefs show one content fill ref and eight border-frame refs. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` render evidence and resource notes | incorporate | applied |
| A5-C08 | Callback/global evidence should name `dword_69B3E8`, `dword_69B3EC`, and `dword_69B3FC` without creating `g_uiTileRenderer`. | High | Current xrefs/callees and support docs agree that the code uses EPF lookup and surface callback slots, not a backing renderer singleton. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` render evidence and support caveats | incorporate | applied |
| A5-C09 | [UID:0001A4] `SpecializedButtonPanes` should remain rejected as direct owner. | High | The support aggregate explicitly delegates this child to BlueAlertPane/AlertPanes and is a mixed-owner container. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` ownership reanalysis section | incorporate | applied |
| A5-C10 | [UID:0001A6] successor ownership should remain rejected and separated by `0x0050114d-0x00501150` padding. | High | Lookup/byte evidence proves successor `sub_501150` starts at `0x00501150`; successor doc agrees. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` boundary notes and ownership reanalysis section | incorporate | applied |
| A5-C11 | `g_uiTileRenderer` should remain an ignored generated alias. | High | Current evidence shows EPF lookup and callback slots, with no backing renderer global. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` support caveat; `by-global/g_uiTileRenderer.md` verified already consistent unless stale text is found | already-present | already-present |
| A5-C12 | Support docs do not require report-driven edits unless callback verification discovers a direct contradiction. | Medium-high | Checked support docs are consistent with the new evidence: `BlueAlertPane`, `AlertPanes`, `BlueAlertPaneVtables`, `BlueAlertPaneVtableData`, `AlertPaneLayout`, `alert-dialog-resources`, `g_uiTileRenderer`, `SpecializedButtonPanes`, and `UserCreateAppearanceSelectorControls`. | Support docs listed in `## Recommended Support Doc Changes` | not-applicable | excluded-with-reason |
| A5-C13 | Generated Ranking/callsite ownership should be rejected for this target. | High | Constructor has no callsite/xref route, and handlers are vtable data refs only; ranking/callsite heuristics cannot override class/vtable/file evidence. | `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` ownership reanalysis section | incorporate | applied |

## Implementation Tracking Checklist

- [x] Edited only `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md`; callback verification found no directly stale/conflicting support-doc statement requiring support edits. Covers A5-C01 through A5-C13.
- [x] Updated target metadata to `COMPLETION:87` and `CONFIDENCE:90`; preserved `CANONICAL_OWNER:00000Y`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000Y`. Covers A5-C01 and preserves A5-C02.
- [x] Replaced only the content between the target's existing `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` markers with the target-specific no-code proof from this report; no duplicate marker lines were inserted. Covers A5-C03, A5-C04, A5-C06, A5-C07, and A5-C08.
- [x] Added current MCP session evidence for `supervisor_resume_20260629`: active worker/session state, `server_health` state, exact lookup boundaries, zero constructor xrefs, zero `c0 08 50 00` raw pointer hits, vtable-only handler xrefs, vtable store refs, `BDFRAME.EPF` xrefs/string, callee sets, block/instruction counts, decompiler prototype artifacts, callback refs/counts, and boundary bytes. Covers A5-C01, A5-C03, A5-C04, A5-C05, A5-C07, and A5-C08.
- [x] Preserved behavior details at report specificity: constructor vtable stores and `+0x26c` layout-reference store; action ids/primary-secondary dispatch; `DrawContent` `+0x260` alternate path through `dword_69B3FC`/`dword_69B3EC` versus frame `8`; `DrawBorderFrame` `+0x260` skip path and frame ids `1,6,3,4,0,2,5,7`; render through `dword_69B3E8`. Covers A5-C02, A5-C04, A5-C07, and A5-C08.
- [x] Added explicit ownership reanalysis rejecting direct ownership by `SpecializedButtonPanes`, `UserCreateAppearanceSelectorControls`, `Surface`, `SurfaceRenderCallbackTable`, `BDFRAME.EPF` resources, `g_uiTileRenderer`, and generated Ranking/callsite heuristics while accepting [UID:00000Y] and source placement through [UID:0000HE]. Covers A5-C02, A5-C08, A5-C09, A5-C10, A5-C11, A5-C12, and A5-C13.
- [x] Preserved split/range facts: predecessor `0x00500640-0x005008c0` and `0x005008b9-0x005008c0` padding belong outside UID0001A5; successor `0x0050114d-0x00501150` is padding before UID0001A6; no split is recommended for this callback. Covers A5-C05, A5-C09, and A5-C10.
- [x] Verified support docs listed in `## Recommended Support Doc Changes` read-only; no direct stale/conflicting statement was found, so no support doc was edited or validated. Covers A5-C11 and A5-C12.
- [x] Ran scoped validator from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory\0x005008c0-0x0050114d.BlueAlertPaneCore.md --apply --queue-timeout 240`; command_id `000000004695`, command_timestamp `2026-07-02T16:48:29-04:00`, exit code `0`, ok `1`, warnings none reported.
- [x] Confirmed generated refresh state from validator output: `generated_refresh: deferred`, generated_refresh_command_id `000000004695`, generated_refresh_timestamp `2026-07-02T16:48:29-04:00`. No generated C++ body comparison was required because the formal block remains marker/no-code and generated output was not used as implementation evidence.
- [x] Updated the `## Claim And Incorporation Ledger` rows by stable claim ID: A5-C01/A5-C03/A5-C04/A5-C05/A5-C06/A5-C07/A5-C08/A5-C09/A5-C10/A5-C13 are `applied`; A5-C02/A5-C11 are `already-present`; A5-C12 is `excluded-with-reason` because support verification found no direct stale/conflicting text requiring support edits.
- [x] Acquired a short B013 lease for `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md` immediately before the edit/validator batch and released it immediately after validation. No support leases were used.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004701","destination_path":"executed-b-agent-research/B013/0001A5-BlueAlertPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0001A5-BlueAlertPaneCore-source-quality.md","timestamp":"2026-07-02T16:55:49-04:00","uid":"0001A5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
