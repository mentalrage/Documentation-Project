** TARGET-REPORT-UID:0002J3 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Source-Quality Report: [UID:0002J3] MenuItemConstructor

## Assignment

- Agent: B002
- Date: 2026-06-19
- Target UID: `0002J3`
- Target name: `MenuItemConstructor`
- Primary doc: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00516f00-0x00516f67.MenuItemConstructor.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0002J3-MenuItemConstructor-source-quality.md`
- Workflow: report-only first. I did not edit target/support by-* docs, generated source, project coverage, or `by-memory/-coverage-report.md`.

## Final Recommendation

Raise the target from `84/90` to `86/91`, keep `RECONSTRUCTABLE:TRUE`, keep direct class owner/emitter `[UID:00007V] MenuItem`, and emit first-draft C++ for the constructor through the existing `PopupMenuControls.cpp` route.

The unresolved state-word caveat from the current target doc can be closed at source-quality level. The binary writes `word ptr [this+0x14], 1`, but sibling accessors and layout docs show that storage is two adjacent byte booleans: `m_enabled` at `+0x14` initialized `true`, and `m_selected` at `+0x15` initialized `false`. The 16-bit store is a compiler coalescing of those adjacent initializations, not evidence for source-facing `m_stateWord = 1` code.

Recommended first-draft C++:

```cpp
MenuItem::MenuItem()
    : LObject()
{
    InitRectBounds(&m_bounds, 0, 0, 0, 0);
    m_enabled = true;
    m_selected = false;
}
```

Do not model the vtable write, SEH frame, security cookie, local unwind state, or handler address in source C++; they are compiler-generated constructor/unwind scaffolding.

## Evidence Checked

- Active B-agent instructions:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B002/goal.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
  - `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- Primary target:
  - `source-3/project-documentation/by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md`
- Direct owner/source docs:
  - `source-3/project-documentation/by-class/MenuItem.md`
  - `source-3/project-documentation/by-file/PopupMenuControls.md`
  - `source-3/project-documentation/by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`
  - `source-3/project-documentation/by-memory/0x00516f70-0x00516f74.MenuItemIsEnabled.md`
  - `source-3/project-documentation/by-memory/0x00516f80-0x00516f88.MenuItemSetEnabled.md`
  - `source-3/project-documentation/by-memory/0x00516f90-0x00516f94.MenuItemIsSelected.md`
  - `source-3/project-documentation/by-memory/0x00516fa0-0x00516fa8.MenuItemSetSelected.md`
  - `source-3/project-documentation/by-memory/0x00517000-0x00517090.StringMenuItemConstructor.md`
  - `source-3/project-documentation/by-memory/0x005171c0-0x00517220.SeparatorMenuItemConstructor.md`
  - `source-3/project-documentation/by-memory/0x005172e0-0x0051731f.MenuItemScalarDeletingDestructor.md`
- Layout/vtable support:
  - `source-3/project-documentation/by-memory/0x0061eb98-0x0061ebec.MenuItemVtables.md`
  - `source-3/project-documentation/by-memory/0x00516f00-0x00517440.MenuItemLayouts.md`
  - `source-3/project-documentation/by-memory/0x004f4a80-0x004f4b20.LObjectRuntimeShell.md`
  - `source-3/project-documentation/by-memory/0x004b7c50-0x004b7f3b.RectGeometryHelpers.md`
- Prior popup-menu work checked:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/executed/0002J5-0002J9-0002JA-0002JC-0002JD-0002JF-0002JG-popup-menu-controls-source-quality.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/executed/0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck.md`
- Generated and coverage state:
  - `source-3/project-documentation/auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`
  - `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
  - `source-3/project-documentation/by-memory/-coverage-report.md` read only.
- Raw executable recheck:
  - PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5: `4247e04e20b65d6414c7238aa8ff5515`
  - Image base: `0x00400000`
  - `.text`: `0x00401000-0x0060c4ac`
  - `.rdata`: `0x0060d000-0x0066c0be`
  - `.data`: `0x0066d000-0x0069ce24`
- Number conversion helper:
  - `source-3/project-documentation/tools/int_convert.py` was run successfully in JSON input mode for `0x0f` / 15, `0x08` / 8, `0x01` / 1, and `0x09` / 9.
  - Earlier target-doc values `0x67` / 103, `0x18` / 24, `0x14` / 20, `0x04` / 4, and `0x10` / 16 were already present in the checked docs and remain consistent with the raw disassembly.
- IDA/MCP status:
  - The local IDA MCP endpoint was unavailable in-session (`Unable to connect to the remote server`), so this pass used existing live-IDA notes plus direct PE/Capstone-style raw inspection and file evidence.

## Boundary And Inventory

| Range | Size | Finding | Recommendation |
|---|---:|---|---|
| `0x00516ee8-0x00516ef0` | `0x08` / 8 | Raw `0xcc` padding before an undocumented MenuPane thunk. | Support coverage/documentation cleanup, not part of `0002J3`. |
| `0x00516ef0-0x00516eff` | `0x0f` / 15 | Undocumented raw method-shaped thunk: loads `ecx = [ecx+0xfc]`, reads item vtable, tail-jumps `vtable+0x0c`. | Create/split a support child later, likely under `MenuPane`; do not merge into `0002J3`. |
| `0x00516eff-0x00516f00` | `0x01` / 1 | Raw `0xcc` padding. | Support cleanup only. |
| `0x00516f00-0x00516f67` | `0x67` / 103 | Exact `MenuItem::MenuItem()` constructor body. | Keep target exact; no split/merge. |
| `0x00516f67-0x00516f70` | `0x09` / 9 | Raw `0xcc` postpad before `MenuItem::IsEnabled`. | Keep as padding, outside constructor. |

No child split is needed inside `0x00516f00-0x00516f67`. The adjacent undocumented `0x00516ef0` thunk should be handled by support docs/coverage, but it does not change this target's exact range or ownership.

## Raw Function Facts

Target raw bytes at file offset `0x116300`:

```text
55 8b ec 6a ff 68 99 31 60 00 64 a1 00 00 00 00
50 51 56 a1 24 2f 67 00 33 c5 50 8d 45 f4 64 a3
00 00 00 00 8b f1 89 75 f0 e8 52 db fd ff 6a 00
6a 00 6a 00 8d 46 04 c7 45 fc 00 00 00 00 6a 00
50 c7 06 98 eb 61 00 e8 04 0d fa ff 83 c4 14 66
c7 46 14 01 00 8b c6 8b 4d f4 64 89 0d 00 00 00
00 59 5e 8b e5 5d c3
```

Key disassembly:

```asm
00516f00  push ebp
00516f01  mov ebp, esp
00516f03  push -1
00516f05  push 0x603199
00516f0a  mov eax, dword ptr fs:[0]
00516f10  push eax
00516f11  push ecx
00516f12  push esi
00516f13  mov eax, dword ptr [0x672f24]
00516f18  xor eax, ebp
00516f1a  push eax
00516f1b  lea eax, [ebp-0xc]
00516f1e  mov dword ptr fs:[0], eax
00516f24  mov esi, ecx
00516f26  mov dword ptr [ebp-0x10], esi
00516f29  call 0x4f4a80
00516f2e  push 0
00516f30  push 0
00516f32  push 0
00516f34  lea eax, [esi+4]
00516f37  mov dword ptr [ebp-4], 0
00516f3e  push 0
00516f40  push eax
00516f41  mov dword ptr [esi], 0x61eb98
00516f47  call 0x4b7c50
00516f4c  add esp, 0x14
00516f4f  mov word ptr [esi+0x14], 1
00516f55  mov eax, esi
00516f57  mov ecx, dword ptr [ebp-0xc]
00516f5a  mov dword ptr fs:[0], ecx
00516f61  pop ecx
00516f62  pop esi
00516f63  mov esp, ebp
00516f65  pop ebp
00516f66  ret
```

Direct reference checks:

- `.text` rel32 call/jump scan to `0x00516f00`: no hits.
- Whole-file little-endian dword search for VA `0x00516f00`: no hits.
- Whole-file little-endian dword search for RVA `0x00116f00`: no hits.
- Whole-file little-endian dword search for raw offset `0x00116300`: no hits.
- Search for vtable VA `0x0061eb98`: five hits, all expected constructor/destructor vtable writes:
  - `0x00516f43`: target `MenuItem` constructor.
  - `0x00517033`: `StringMenuItem` constructor base-vtable write.
  - `0x005171f3`: `SeparatorMenuItem` constructor base-vtable write.
  - `0x005172e8`: `MenuItem` destructor reset.
  - `0x00517408`: `StringMenuItem` destructor reset.

Menu item family vtable facts:

```text
MenuItem vtable       0x0061eb98: 0x005172e0, 0x004f4b10, 0x0041b6c0, 0x005ca28c, 0x005ca28c, 0x005ca28c
StringMenuItem vtable 0x0061ebb4: 0x00517400, 0x004f4b10, 0x0041b6c0, 0x00517090, 0x005170d0, 0x005170f0
SeparatorMenuItem     0x0061ebd0: 0x005172e0, 0x004f4b10, 0x0041b6c0, 0x005ca28c, 0x005ca28c, 0x00517250, 0x00517220, 0x00517240
```

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence | Confidence |
|---|---|---|---|
| Source placement | Keep source root `[UID:0000MN] PopupMenuControls`, generated path `NexusTK/ui/menu/PopupMenuControls.cpp`. | `PopupMenuControls.md`, proposed source tree, generated file markers, MenuItem family docs. | High |
| Direct owner/emitter | Keep `[UID:00007V] MenuItem` as `CANONICAL_OWNER` and `EMITTER_UIDS`. | Constructor is a class constructor for `MenuItem`, owner doc already maps fields and methods, generated route resolves class emitter to the file. | High |
| Caller/reachability | No direct callers or pointer refs found; still source-authored and reconstructable. | Raw scan found no rel32/VA/RVA/raw-offset references to `0x00516f00`. Sibling derived constructors duplicate base setup instead of calling this out-of-line base constructor. | High |
| Range/split/merge | `0x00516f00-0x00516f67` is exact and self-contained; no target split. | Body starts with normal ctor prologue and ends with `ret`; postpad begins immediately at `0x00516f67`. | High |
| Pre-target gap | Support docs should not silently skip `0x00516ef0-0x00516eff`. | Raw PE has a 15-byte thunk between padding islands. It is outside target and likely belongs to `MenuPane`. | Medium-high |
| `sub_516F00` name | Rename/source-name as `MenuItem::MenuItem()` / IDA `MenuItem_ctor`. | Body installs `MenuItem` vtable `0x0061eb98`, initializes base fields, returns `this`. | High |
| `sub_4F4A80` helper | Use `LObject::LObject()` / `LObjectConstructor`, not raw `sub_4F4A80`. | `LObjectRuntimeShell` exact child ownership and call at `0x00516f29`. | High |
| `sub_4B7C50` helper | Use `InitRectBounds(&m_bounds, 0, 0, 0, 0)` or the established RectBounds initializer name. | `RectGeometryHelpers` support doc, pushes four zero coordinates plus `this+4`. | High |
| State word at `+0x14` | Source-facing fields are `m_enabled` at `+0x14` and `m_selected` at `+0x15`. Constructor initializes enabled true, selected false. | `MenuItemLayouts`, `MenuItem` class doc, `IsEnabled`/`SetEnabled` use byte `+0x14`, `IsSelected`/`SetSelected` use byte `+0x15`; selected-index helper writes `+0x15`. | High |
| `word [this+0x14] = 1` source shape | Treat as compiler coalescing of two adjacent bool stores, not source `m_stateWord = 1`. | Sibling methods expose byte-granular booleans and the constructor writes exactly value `1`, which maps to low byte true and high byte false. | High |
| SEH labels and handler `0x00603199` | Compiler-only constructor EH/unwind and cookie scaffolding; document but do not emit. | Prologue pushes `-1`, handler address, `fs:[0]`, security cookie `[0x672f24]`, and sets local state after `LObject::LObject`. | High |
| Prior popup-menu assumptions | B003's `m_enabled`/`m_selected` and PopupMenuControls routing are valid for this target. | Rechecked against sibling docs, raw bytes, generated route, and family vtables. | High |
| No-code alternative | Reject. This is not pure compiler glue; it is a source-authored base constructor with meaningful field initialization. | It calls base ctor and Rect initializer, installs class vtable, initializes source fields, and has a valid emitter route. | High |
| Direct-file owner alternative | Reject. File `[UID:0000MN]` is the source root, but direct source owner should be the class `[UID:00007V]`. | Existing class doc owns constructor and generated markers route through class to file. | High |
| New `MenuItem.cpp` split alternative | Reject for this pass. | Proposed tree and file doc group `MenuItem`, `StringMenuItem`, `SeparatorMenuItem`, `MenuPane`, and popup callback in `PopupMenuControls.cpp`; no evidence for separate original file. | Medium-high |
| Derived-class owner alternative | Reject. | `StringMenuItemConstructor` and `SeparatorMenuItemConstructor` duplicate base setup but install their own final vtables; the target installs base `MenuItem` vtable only. | High |

## Source Family Relationship

`MenuItem` is the base item class used by `StringMenuItem` and `SeparatorMenuItem`. The base constructor is emitted as an out-of-line source-authored function, but the observed derived constructors do not call it directly. They inline or duplicate the same base setup before installing their final derived vtables:

- `MenuItemConstructor`:
  - calls `LObject::LObject()`
  - installs `MenuItem::vftable`
  - initializes `m_bounds` to zero rect
  - initializes `m_enabled=true`, `m_selected=false`
- `StringMenuItemConstructor`:
  - performs the same base setup
  - installs `StringMenuItem::vftable`
  - copies label text into the inline wide buffer at `+0x18`
- `SeparatorMenuItemConstructor`:
  - performs the same base setup
  - writes the shared state word to `0`, making `m_enabled=false`, `m_selected=false`
  - installs `SeparatorMenuItem::vftable`

This relationship supports keeping `0002J3` as base-class source, even with no direct callers. It also supports first-draft C++ rather than no-code compiler-glue treatment.

## First-Draft C++ Readiness

The target satisfies the by-structure code-entry rule after this pass:

- `RECONSTRUCTABLE:TRUE` already set.
- Nonblank emitter route exists: `[UID:00007V] MenuItem` routes to `[UID:0000MN] PopupMenuControls`.
- Generated output already has `0002J3` markers in `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.
- Recommended score `86/91` gives an average above the `85` source-output gate.
- Remaining raw details are compiler-generated or source-style spelling nits, not blockers.

Recommended emitted C++ body:

```cpp
MenuItem::MenuItem()
    : LObject()
{
    InitRectBounds(&m_bounds, 0, 0, 0, 0);
    m_enabled = true;
    m_selected = false;
}
```

Notes for implementer:

- If local headers expose the rectangle initializer under a more established source name, use that project name while preserving the semantics: initialize `m_bounds` at `this+0x04` with left/top/right/bottom all zero.
- Do not emit `m_vftable = ...`; the compiler will regenerate vtable writes.
- Do not emit `m_stateWord = 1`; use the source-facing boolean names already resolved by `MenuItem` layout and accessors.
- Do not emit SEH/cookie/unwind labels.

## Recommended Target Doc Changes

For `source-3/project-documentation/by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md`:

- Header/metadata:
  - Change `COMPLETION: 84` to `COMPLETION: 86`.
  - Change `CONFIDENCE: 90` to `CONFIDENCE: 91`.
  - Keep `CANONICAL_OWNER: 00007V`.
  - Keep `RECONSTRUCTABLE: TRUE`.
  - Keep `EMITTER_UIDS: 00007V`.
- Summary/body:
  - Replace "final state-word/source-signature caveats keep C++ blank" with a resolved source-quality statement:
    - `+0x14` low byte is `m_enabled`, initialized true.
    - `+0x15` high byte is `m_selected`, initialized false.
    - The word store is compiler coalescing of adjacent bool initialization.
  - Name `0x004f4a80` as `LObject::LObject()` / `LObjectConstructor`.
  - Name `0x004b7c50` as `InitRectBounds` / RectBounds zero initializer.
  - Name `0x0061eb98` as `MenuItem::vftable`.
  - Describe the SEH handler `0x00603199`, cookie load `[0x00672f24]`, and `[ebp-4]` state write as compiler-only constructor-unwind scaffolding.
  - Keep the no-direct-callers evidence, but state why this does not imply ignored/no-code status.
- C++ block:
  - Populate the first-draft C++ shown above.
- Open questions:
  - Downgrade the exact source spelling of the Rect helper to an implementation-time naming check, not a source-quality blocker.
  - Add a support-note that the adjacent `0x00516ef0-0x00516eff` thunk needs a separate MenuPane child/coverage fix, outside this target.

## Recommended Support Doc Changes

- `by-class/MenuItem.md`
  - Add the constructor as source-ready:
    - `MenuItem::MenuItem()` calls `LObject::LObject()`, zero-initializes `m_bounds`, sets `m_enabled=true`, and sets `m_selected=false`.
  - Keep `m_stateWord` only as a storage/layout alias if mentioned; do not present it as the source-facing initializer name.
- `by-file/PopupMenuControls.md`
  - Mark `MenuItem::MenuItem()` as ready for emitted source in `NexusTK/ui/menu/PopupMenuControls.cpp`.
  - Keep the aggregate file grouping; no new `MenuItem.cpp` split is recommended from this target.
- `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`
  - Update the target row for `0002J3` with the resolved constructor source shape.
  - Add or flag a missing child for `0x00516ef0-0x00516eff`; the parent currently skips this raw thunk between documented ranges.
- `MenuItemLayouts.md`
  - If not already explicit enough, state that constructor `word [this+0x14] = 1` initializes `m_enabled=true` and `m_selected=false`.
- `MenuItemVtables.md`
  - Optional: cross-reference `MenuItemConstructor` as the base constructor that writes `0x0061eb98`.
- Generated source:
  - In `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`, replace the empty `0002J3` marker with the first-draft constructor after supervisor acceptance.

## Exact Coverage Row Text

Do not edit `by-memory/-coverage-report.md` during this report-only pass. If supervisor accepts the recommendation, replace the current `0002J3` row with:

```text
        - [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) 0x00516f00-0x00516f67 | constructor | MenuItemConstructor : reconstructable : 86% : very-strong : B002 2026-06-19 source-quality pass confirms the exact `0x67` / 103-byte source-authored `MenuItem::MenuItem()` constructor, raw PE body bytes/disassembly, `LObject::LObject` call at `0x004f4a80`, `MenuItem` vtable install at `0x0061eb98`, `InitRectBounds(&m_bounds, 0, 0, 0, 0)` through `0x004b7c50`, state storage write `word [this+0x14] = 1` resolved as `m_enabled = true` and `m_selected = false`, compiler-only EH/security-cookie construction-unwind scaffolding through handler `0x00603199`, nine-byte postpad, no direct `.text` rel32 callers or VA/RVA/raw-offset pointer hits, direct [UID:00007V][MenuItem](by-class/MenuItem.md) owner/emitter with [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) source root, rejected direct-file/new-file/no-code alternatives, and first-draft constructor C++ readiness.
```

Support coverage insert templates for the adjacent gap, pending a supervisor-assigned UID and exact child creation:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516ee8-0x00516ef0 | padding | MenuPane helper alignment padding : ignored : 100% : strong : B002 raw PE recheck confirms eight `0xcc` bytes before an undocumented MenuPane forwarding thunk at `0x00516ef0`.
        - [UID:<new>][0x00516ef0-0x00516eff.MenuPaneCurrentItemMetricsThunk](by-memory/0x00516ef0-0x00516eff.MenuPaneCurrentItemMetricsThunk.md) 0x00516ef0-0x00516eff | raw method thunk | MenuPaneCurrentItemMetricsThunk : reconstructable : 82% : strong : B002 raw PE recheck found an undocumented 15-byte raw MenuPane helper that loads `MenuPane+0xfc`, reads the pointed item's vtable, and tail-jumps to slot `+0x0c`; no rel32 callers or VA/RVA/raw-offset pointer hits were found, and the source role is inferred as a current/selected item metrics forwarding helper under [UID:00007W][MenuPane](by-class/MenuPane.md), requiring exact child creation and source-role validation before raising above the 85/85 gate.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00516eff-0x00516f00 | padding | MenuPane thunk to MenuItem constructor alignment padding : ignored : 100% : strong : B002 raw PE recheck confirms one `0xcc` byte before [UID:0002J3].
```

## IDA Rename / Type / Comment Recommendations

High-confidence renames:

- `sub_516F00` -> `MenuItem_ctor` or `MenuItem::MenuItem`.
- `0x0061eb98` -> `MenuItem_vftable`.
- Local/source comments:
  - At `0x00516f29`: `call LObject::LObject()`.
  - At `0x00516f37`: `ctor unwind state: LObject base constructed`.
  - At `0x00516f41`: `compiler vftable store for MenuItem`.
  - At `0x00516f47`: `InitRectBounds(&m_bounds, 0, 0, 0, 0)`.
  - At `0x00516f4f`: `m_enabled=true; m_selected=false; coalesced word store`.
  - At handler pointer `0x00603199`: `MenuItem_ctor EH/unwind handler`, compiler-generated, no source body.

Recommended prototype:

```cpp
MenuItem *__thiscall MenuItem_ctor(MenuItem *this);
```

Source-facing declaration:

```cpp
class MenuItem : public LObject {
public:
    MenuItem();
};
```

Support/medium-confidence rename for later work:

- `0x00516ef0` -> provisional `MenuPane_CurrentItemMetricsThunk` or `MenuPane_SelectedItemMetricsThunk`.
- Reason: it loads pointer at `MenuPane+0xfc` and tail-jumps to pointed item vtable slot `+0x0c`; exact source name remains below final confidence because no callers/pointers were found in this pass.

## Open Questions With Attempted Resolution

- Exact original source spelling for the rectangle helper:
  - Evidence checked: `RectGeometryHelpers`, target pushes, sibling constructor setup.
  - Best direction: use established `InitRectBounds` or the local RectBounds zero-initializer name. This is a naming polish issue, not a blocker.
- Why no direct callers reach `MenuItem::MenuItem()`:
  - Evidence checked: rel32 scan, VA/RVA/raw pointer scans, sibling derived constructors.
  - Best direction: retained out-of-line base constructor emitted by original source, while derived constructors inline/duplicate base construction. Do not mark ignored.
- Whether to emit `m_stateWord = 1`:
  - Evidence checked: accessors, setters, layout docs, selected-index helper.
  - Resolution: reject as source-facing code. Emit `m_enabled=true`, `m_selected=false`.
- Whether `0x00516ef0` should alter this target:
  - Evidence checked: raw bytes and disassembly around pre-target gap.
  - Resolution: no target impact. It needs a separate support child under `MenuPane`.
- Whether this should be no-code compiler glue:
  - Evidence checked: constructor body, field initialization, owner/emitter route, generated marker.
  - Resolution: no. Only EH/cookie/vtable mechanics are compiler-generated; the constructor itself is source-authored and ready for C++.

## Validation Commands Needed

After supervisor accepts implementation, run the normal doc/generation validators used for this repository, plus targeted checks:

Use JSON input mode for multiple constants, for example:

> Executable block R001 was removed from this report and preserved verbatim in [0002J3-MenuItemConstructor-source-quality-removed.md](0002J3-MenuItemConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended post-implementation content checks:

> Executable block R002 was removed from this report and preserved verbatim in [0002J3-MenuItemConstructor-source-quality-removed.md](0002J3-MenuItemConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA/PE validation recommended if MCP is available:

```text
server_health
lookup_funcs 0x00516f00
analyze_function 0x00516f00
xrefs_to 0x00516f00
xrefs_to 0x0061eb98
get_bytes 0x00516f00 0x67
get_bytes 0x00516ef0 0x0f
get_int 0x0061eb98 u32le
get_int 0x0061eb9c u32le
get_int 0x0061eba0 u32le
```

No project validator was run in this report-only pass because no by-* docs or generated files were modified.

## Implementation Readiness

Ready for implementation callback.

Required implementation work after acceptance:

1. Update the target doc metadata and evidence wording.
2. Add the first-draft `MenuItem::MenuItem()` C++ body to the target and generated source route.
3. Update `MenuItem` and `PopupMenuControls` support docs to close the state-word/source-shape caveat.
4. Replace the `0002J3` coverage row with the exact text above.
5. Track the adjacent `0x00516ef0-0x00516eff` raw thunk as separate support work, not as a blocker for `0002J3`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002J3-MenuItemConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002J3"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002J3-MenuItemConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002J3-MenuItemConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002J3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
