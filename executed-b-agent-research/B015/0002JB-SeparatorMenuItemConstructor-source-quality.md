** TARGET-REPORT-UID:0002JB **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B015 Report - [UID:0002JB] SeparatorMenuItemConstructor Source Quality

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0002JB-SeparatorMenuItemConstructor-source-quality.md`

Target: `source-3/project-documentation/by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md`

Assignment: B-agent source-quality / heuristic research for `SeparatorMenuItemConstructor`.

No target/support `by-*` docs, generated files, IDA database state, or `by-memory/-coverage-report.md` were edited during this report pass. Existing B015 reports, including `00013G`, `00014F`, `0002IR`, `0002PY`, and `0001DH`, were preserved.

## Summary Recommendation

`0x005171b0-0x0051721d` is source-authored `SeparatorMenuItem` constructor code with compiler-generated MSVC EH/security-cookie scaffolding. It should not remain a blank-code constructor page now that the current gate is reconstructable + valid emitter + average score above 85.

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:92
CANONICAL_OWNER:0000CY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CY
```

Recommended source route:

- Direct owner/emitter: [UID:0000CY] `SeparatorMenuItem`.
- Source-file root: [UID:0000MN] `PopupMenuControls`, generated at `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.
- No new `SeparatorMenuItem.cpp` or `MenuItem.cpp` split is justified by current evidence. Keep the possible source-file split as a source-tree caveat only.

Recommended first-draft C++ for the target page:

```cpp
SeparatorMenuItem::SeparatorMenuItem()
    : MenuItem()
{
    m_enabled = false;
}
```

This is source-style C++, not instruction-shaped pseudocode. The binary expands the base `MenuItem` construction sequence inline, zeroes bounds through `InitRectBounds`, clears the shared state word at `+0x14`, and installs the final `SeparatorMenuItem` vtable. Source should express ordinary base construction plus separator-specific non-interactive state; compiler codegen supplies vtable stores, EH registration, security-cookie checks, and construction-unwind cleanup.

## Evidence Checked

Instruction/context docs checked:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B015/goal.md`
- `.codex/AGENTS.md`

Target and direct support docs checked:

- [UID:0002JB] `by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md`
- [UID:0000CY] `by-class/SeparatorMenuItem.md`
- [UID:00007V] `by-class/MenuItem.md`
- [UID:0000MN] `by-file/PopupMenuControls.md`
- [UID:0001BK] `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`
- [UID:0001V5] `by-type/by-struct/MenuItemLayouts.md`
- [UID:0001Y4] `by-type/by-vtable/MenuItemVtables.md`
- [UID:00036I] `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`
- Generated `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`
- Current `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md` rows

Related support checked:

- [UID:0002J3] `MenuItemConstructor`
- [UID:0002J6] `StringMenuItemConstructor`
- [UID:0002J4] `MenuItemStateFlag0Accessor`
- [UID:0002JH] `MenuItemSetStateFlag0`
- [UID:000377] `MenuPaneFindPreviousEnabledItemRaw`
- [UID:000378] `MenuPaneFindNextEnabledItemRaw`
- [UID:0002JC] `SeparatorMenuItemGetDefaultDimensions`
- [UID:0002JD] `SeparatorMenuItemGetStyleFlags`
- [UID:0002JE] `SeparatorMenuItemDrawSeparator`
- [UID:0002JF] `MenuItemScalarDeletingDestructor`
- [UID:00036Z] `LObjectConstructor`
- [UID:000370] `LObjectDestructorBody`
- [UID:00015S] `RectGeometryHelpers`
- `by-project-structure/proposed-source-tree.md`
- Prior B003 executed report `0002J5-0002J9-0002JA-0002JC-0002JD-0002JF-0002JG-popup-menu-controls-source-quality.md`
- Prior B003 executed report `0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck.md`

Current-session IDA MCP status:

- `http://127.0.0.1:13337/mcp` timed out.
- `Get-NetTCPConnection -LocalPort 13337` returned no listener.
- I did not rely on live IDA RPC for new facts. Current-session evidence is from existing IDA-backed docs plus fresh raw PE checks.

Current raw PE checks:

- PE used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- SHA-256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c4ac`
- Target maps to `.text`, raw file offset `0x001165b0`, length `0x6d` / 109 bytes (Verified with `int_convert.py`).
- Preceding padding `0x005171a2-0x005171b0` is fourteen `0xcc` bytes, `0x0e` / 14 bytes (Verified with `int_convert.py`).
- Following padding `0x0051721d-0x00517220` is three `0xcc` bytes, `0x03` / 3 bytes (Verified with `int_convert.py`).
- Whole-file pointer scan found zero dword hits for target VA `0x005171b0`, target RVA `0x001171b0`, and target raw file offset `0x001165b0`.
- `.text` rel32 call/jump scan found zero direct branches/calls to `0x005171b0`.
- Dword scan for `MenuItem` vtable VA `0x0061eb98` found the expected five immediates in the base constructor, string-item base-construction path, separator base-construction path, and two destructor resets.
- Dword scan for `SeparatorMenuItem` vtable VA `0x0061ebd0` found only the final separator vtable install immediate inside this constructor.

Fresh target bytes:

```text
55 8b ec 6a ff 68 df 31 60 00 64 a1 00 00 00 00 50 51 56 a1 24 2f 67 00 33 c5 50 8d 45 f4 64 a3 00 00 00 00 8b f1 89 75 f0 e8 a2 d8 fd ff 6a 00 6a 00 6a 00 8d 46 04 c7 45 fc 00 00 00 00 6a 00 50 c7 06 98 eb 61 00 e8 54 0a fa ff 83 c4 14 66 c7 46 14 00 00 c7 06 d0 eb 61 00 8b c6 8b 4d f4 64 89 0d 00 00 00 00 59 5e 8b e5 5d c3
```

Fresh disassembly:

```asm
005171b0  push   ebp
005171b1  mov    ebp, esp
005171b3  push   -1
005171b5  push   0x6031df
005171ba  mov    eax, dword ptr fs:[0]
005171c0  push   eax
005171c1  push   ecx
005171c2  push   esi
005171c3  mov    eax, dword ptr [0x672f24]
005171c8  xor    eax, ebp
005171ca  push   eax
005171cb  lea    eax, [ebp - 0xc]
005171ce  mov    dword ptr fs:[0], eax
005171d4  mov    esi, ecx
005171d6  mov    dword ptr [ebp - 0x10], esi
005171d9  call   0x004f4a80
005171de  push   0
005171e0  push   0
005171e2  push   0
005171e4  lea    eax, [esi + 4]
005171e7  mov    dword ptr [ebp - 4], 0
005171ee  push   0
005171f0  push   eax
005171f1  mov    dword ptr [esi], 0x0061eb98
005171f7  call   0x004b7c50
005171fc  add    esp, 0x14
005171ff  mov    word ptr [esi + 0x14], 0
00517205  mov    dword ptr [esi], 0x0061ebd0
0051720b  mov    eax, esi
0051720d  mov    ecx, dword ptr [ebp - 0xc]
00517210  mov    dword ptr fs:[0], ecx
00517217  pop    ecx
00517218  pop    esi
00517219  mov    esp, ebp
0051721b  pop    ebp
0051721c  ret
```

Vtable dwords rechecked from raw PE:

```text
0x0061eb94 -> 0x0064b604  MenuItem COL
0x0061eb98 -> 0x005172e0  MenuItem scalar deleting destructor
0x0061eb9c -> 0x004f4b10  inherited LObject/runtime slot
0x0061eba0 -> 0x0041b6c0  no-op virtual
0x0061eba4 -> 0x005ca28c  __purecall
0x0061eba8 -> 0x005ca28c  __purecall
0x0061ebac -> 0x005ca28c  __purecall
0x0061ebb0 -> 0x0064b6d4  StringMenuItem COL
0x0061ebb4 -> 0x00517400  StringMenuItem scalar deleting destructor
0x0061ebb8 -> 0x004f4b10
0x0061ebbc -> 0x0041b6c0
0x0061ebc0 -> 0x00517090
0x0061ebc4 -> 0x005170d0
0x0061ebc8 -> 0x005170f0
0x0061ebcc -> 0x0064b724  SeparatorMenuItem COL
0x0061ebd0 -> 0x005172e0  inherited MenuItem scalar deleting destructor
0x0061ebd4 -> 0x004f4b10
0x0061ebd8 -> 0x0041b6c0
0x0061ebdc -> 0x005ca28c
0x0061ebe0 -> 0x005ca28c
0x0061ebe4 -> 0x00517250
0x0061ebe8 -> 0x00517220
0x0061ebec -> 0x00517240
```

EH/unwind evidence:

- The constructor pushes handler address `0x006031df`.
- Raw disassembly around `0x006031df` shows compiler EH/security-cookie handler logic that validates the EH cookie and jumps into the C++ frame handler using scope data `0x00660d5c`.
- The associated cleanup funclet immediately before it at `0x006031d7` loads `ecx` from `[ebp-0x10]` and tail-jumps to [UID:000370] `LObjectDestructorBody` at `0x004f4a90`.
- This confirms the current target text: construction-unwind cleanup can run the `LObject` base cleanup if construction unwinds. It is compiler/runtime scaffolding, not source-authored separator logic.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best defensible conclusion | Evidence checked | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| Source owner/emitter | Keep direct owner/emitter [UID:0000CY] `SeparatorMenuItem`; [UID:0000MN] `PopupMenuControls` remains source-file root. | Target metadata already uses `0000CY`; `SeparatorMenuItem` class clears `86/90`; `PopupMenuControls` clears `86/85`; constructor installs `0x0061ebd0`; class/vtable pages map the separator methods. | Direct file owner `0000MN`; feature-dialog owner; separate new source file. | No metadata owner change needed. |
| Source placement | Keep `NexusTK/ui/menu/PopupMenuControls.cpp` for now. | `PopupMenuControls`, proposed-source-tree, `MenuPaneAndItems`, `MenuItemVtables`, and `MenuItemLayouts` all group `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem` in the reusable menu source family. | New `MenuItem.cpp` or `SeparatorMenuItem.cpp` split in this pass. | Preserve source-root route; record split as caveat only. |
| Boundary | Keep exact half-open range `0x005171b0-0x0051721d`. | Existing IDA-backed docs and fresh raw PE agree on 0x6d-byte body; prepad and postpad are all `0xcc`. | Merge with preceding `StringMenuItemDrawItem`, following dimensions method, or padding rows. | No split/merge repair needed. |
| Constructor relation to `MenuItem` | Source is a `SeparatorMenuItem` derived constructor whose base `MenuItem` construction sequence is expanded inline. | Body calls `LObject::LObject`, installs temporary `MenuItem` vtable, initializes `MenuItem` bounds, then installs final separator vtable. It does not call standalone [UID:0002J3] `MenuItemConstructor`. String constructor uses the same expanded-base pattern. | Modeling source as explicit calls to `sub_4F4A80`, `InitRectBounds`, or fixed vtable stores; claiming no base relationship because `0x00516f00` is not called. | First-draft source should use `: MenuItem()`, while notes explain the inlined/expanded codegen. |
| Noninteractive state field | Use `m_enabled` as the high-probability source-facing field role for byte `+0x14`; the word-zero write also leaves `m_selected` false. | `MenuItemLayouts` and `MenuItem` docs now resolve `+0x14` as enabled/interactable, `+0x15` as selected/highlighted; previous/next enabled scans test `item+0x14`; base and string constructors seed word `1`; separator constructor writes word `0`. | Generic `stateFlag0`; `m_interactive` as primary name; style flags; selected/highlighted byte. | Constructor source should say `m_enabled = false`, with raw behavior documenting the 16-bit word clear. |
| Separator-specific fields | No confirmed fields beyond the shared `MenuItem` base. | Layout page states no separator-specific data; destructor wrapper reused from `MenuItem` uses object size `0x18`; separator behavior is through vtable slots. | Adding a separator state field, type tag, or custom destructor field. | C++ constructor should not initialize extra separator storage. |
| Constructor reachability | No static direct construction route is currently proven. | Existing docs report no `callers`/`xrefs_to`; fresh target VA/RVA/raw pointer scan and `.text` rel32 scan found zero hits. | Claiming representative constructor call sites exist; treating no-xref as proof of padding/dead bytes. | Keep no-direct-caller/pointer-hit caveat. It caps final confidence but does not block source-quality because the class/vtable source family is real. |
| Vtable routing | Constructor belongs to `SeparatorMenuItem`; destructor slot is inherited/reused from `MenuItem`. | Raw vtable run has `0x0061ebd0` for separator, slot `+0x00` points to [UID:0002JF], slots `+0x14/+0x18/+0x1c` point to separator methods; constructor writes `0x0061ebd0` at `0x00517205`. | Separate `SeparatorMenuItem` deleting destructor; file-global constructor helper. | Supports class owner and ordinary source constructor. |
| EH/security scaffolding | Compiler-generated C++ EH and security-cookie support, not source code. | Prologue stores FS exception registration and cookie; handler `0x006031df`; cleanup funclet tail-jumps to `LObjectDestructorBody`. | Handwritten `try`/`catch`, manual security-cookie calls, source helper named `SEH_5171B0`. | Formal C++ should omit EH labels and security cookie machinery. |
| `sub_4F4A80` | Exact child [UID:00036Z] `LObjectConstructor`, source role `LObject::LObject`. | Support page documents the vtable-only constructor body and broad derived-constructor callers. | Unknown helper; MenuItem-owned helper. | Use source/base-constructor wording. |
| `sub_4B7C50` | `InitRectBounds` / rectangle initializer for `{left, top, right, bottom}`. | Raw disassembly writes four caller-provided rectangle edges; `MenuItemLayouts` maps this field at `+0x04`. | Unknown helper; memset; separator-specific bounds function. | Source should rely on base `MenuItem` bounds initialization, not hand-call raw helper unless writing low-level notes. |
| Current blank formal C++ | Stale and should be replaced with first-draft source C++. | Target is reconstructable, owner/emitter route is valid, current average score is already 87, and source shape is resolved enough for draft code. | No-code proof; keeping blank because old below-95 policy. | Populate target `RECONSTRUCTION_CPP` block. |
| Score | Raise to `87/92`. | Exact boundary/raw bytes, field names, owner route, source placement, no-code rejection, and first-draft C++ are now resolved. | Leave `84/90`; push to final-audit score. | Clears low-completion/stale no-code status while preserving open caller/name caveats. |

## First-Draft C++ Readiness

The target is ready for first-draft C++ on the exact by-memory page.

Recommended target `RECONSTRUCTION_CPP`:

```cpp
SeparatorMenuItem::SeparatorMenuItem()
    : MenuItem()
{
    m_enabled = false;
}
```

Notes to include near the code:

- The binary writes a 16-bit zero to `this + 0x14`; the source-facing interpretation is `m_enabled = false` for a non-interactive separator, with `m_selected` also false after construction.
- `MenuItem()` is source-style shorthand for the expanded base construction sequence observed in this binary. The emitted code does not call `0x00516f00`; it duplicates/inlines the base setup.
- Do not include fixed vtable stores, `sub_4F4A80`, `sub_4B7C50`, `SEH_5171B0`, `___security_cookie`, or hard-coded vtable addresses in formal C++.

## Recommended Target Doc Changes

Apply to `source-3/project-documentation/by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md` after supervisor acceptance:

1. Header metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CANONICAL_OWNER:0000CY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Populate the formal C++ block with:

```cpp
SeparatorMenuItem::SeparatorMenuItem()
    : MenuItem()
{
    m_enabled = false;
}
```

3. Replace the stale status sentence that says C++ remains unpopulated with:

```text
Formal C++ now carries first-draft source-quality `SeparatorMenuItem::SeparatorMenuItem()` code. The constructor body is source-authored, while the SEH registration, security cookie, temporary/final vtable stores, and construction-unwind cleanup are compiler-generated codegen effects.
```

4. Update the state wording to avoid passive provisional names:

```text
The raw body writes word `0` at `this + 0x14`. Current support docs resolve byte `+0x14` as `MenuItem::m_enabled` / enabled-interactable state and byte `+0x15` as `m_selected` / selected-highlighted draw state. For source C++, model the separator-specific behavior as `m_enabled = false`; the emitted word clear also leaves `m_selected` false.
```

5. Add a source-quality note:

```text
Source shape: `SeparatorMenuItem::SeparatorMenuItem() : MenuItem() { m_enabled = false; }`. The observed body expands the base `MenuItem` setup inline rather than calling [UID:0002J3] `MenuItemConstructor`: it calls [UID:00036Z] `LObjectConstructor`, installs the temporary [UID:0001Y4] `MenuItem` vtable, initializes the shared bounds rectangle through [UID:00015S] `InitRectBounds`, clears the shared state word, and installs the final `SeparatorMenuItem` vtable. These instruction-level effects should remain evidence, not handwritten source.
```

6. Add or refresh reachability wording:

```text
Current static reachability remains limited: existing IDA docs report no direct callers or xrefs to `0x005171b0`, and B015's raw PE scan found no target VA/RVA/raw-offset pointer hits plus no `.text` rel32 calls or jumps to the constructor start. This is a caller-surface caveat for final audit, not a reason to blank the source body; class ownership is supported by the vtable install, class page, layout page, and source-family route.
```

7. Add or refresh score rationale:

```text
Raised from `84/90` to `87/92` after B015 rechecked the raw PE bytes, exact padding, vtable immediates, no-pointer/no-direct-caller evidence, EH cleanup route, and current support-page field names. The old blank-C++ reason is stale under the current gate: this is source-authored constructor logic with compiler-generated scaffolding, so the target can carry first-draft `SeparatorMenuItem::SeparatorMenuItem()` C++ while keeping original field spelling, constructor call-site reachability, and final source-file split below final-audit confidence.
```

## Recommended Support Doc Changes

Apply after supervisor acceptance. No support metadata score changes are required.

### `by-class/SeparatorMenuItem.md`

Replace the constructor row in the B003 source-quality incorporation table with:

```text
| Constructor | `SeparatorMenuItem::SeparatorMenuItem()` | Source-authored constructor: expands `MenuItem` base setup, leaves shared bounds zeroed, sets `m_enabled` false for non-interactive separator behavior, and relies on compiler codegen for vtable stores. | No direct constructor callers/pointer refs are currently proven; EH/security-cookie scaffolding is compiler support, not source. |
```

Add this note under Evidence Notes or B003 Source-Quality Incorporation:

```text
B015 source-quality recheck for [UID:0002JB] resolves the constructor source shape as `SeparatorMenuItem::SeparatorMenuItem() : MenuItem() { m_enabled = false; }`. The emitted word clear at `+0x14` is best understood through the shared `MenuItem` state layout: low byte `m_enabled` becomes false so separators are skipped by enabled-item scans, while high byte `m_selected` remains false. The constructor has no confirmed direct callers or pointer-table refs, so final call-site reachability remains a below-final-audit caveat.
```

### `by-type/by-struct/MenuItemLayouts.md`

Add this note under `SeparatorMenuItem Extension`:

```text
[UID:0002JB] `SeparatorMenuItemConstructor` is the concrete constructor proof for separator non-interactivity: it clears the shared state word at `+0x14` after base setup. Current source-style wording should describe this as `m_enabled = false`; no separator-specific data member is introduced, and `m_selected` remains false through the same word clear.
```

### `by-file/PopupMenuControls.md`

Add this optional note under Assignment Gate Notes:

```text
B015 [UID:0002JB] recheck keeps `SeparatorMenuItem` constructor ownership on [UID:0000CY] and source-file routing through this `PopupMenuControls.cpp` root. The constructor is now first-draft C++ ready; the possible later `MenuItem.cpp`/`MenuPane.cpp` split remains a source-layout caveat, not a blocker for the current route.
```

### `by-type/by-vtable/MenuItemVtables.md`

No required change. Optional insertion under Constructor And Destructor Evidence:

```text
B015 raw PE recheck for [UID:0002JB] found the `SeparatorMenuItem` vtable immediate `0x0061ebd0` only in the constructor's final vptr store at `0x00517205`, while the separator vtable itself continues to route slot `+0x00` to the inherited [UID:0002JF] `MenuItem` scalar deleting destructor wrapper.
```

## Coverage Report Replacement Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` in the B-agent pass. If the supervisor accepts the report, replace the existing [UID:0002JB] row in the `0x00516290-0x00517441.MenuPaneAndItems` nested region with this exact row:

```text
        - [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) 0x005171b0-0x0051721d | constructor | SeparatorMenuItemConstructor : reconstructable : 87% : very-strong : B015 2026-06-19 raw PE/source-quality recheck confirms the exact `0x6d` / 109-byte constructor (Verified with `int_convert.py`), fourteen-byte prepad and three-byte postpad (Verified with `int_convert.py`), full body bytes/disassembly, calls to [UID:00036Z][0x004f4a80-0x004f4a89.LObjectConstructor](by-memory/0x004f4a80-0x004f4a89.LObjectConstructor.md) `LObjectConstructor` and [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) `InitRectBounds`, temporary base `MenuItem` vtable write at `0x005171f1`, final `SeparatorMenuItem` vtable install at `0x00517205`, shared `MenuItem` state word `+0x14` clear modeled as `m_enabled=false` for non-interactive separators while `m_selected` remains false, compiler EH handler `0x006031df` and unwind cleanup through [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md) classified as generated glue, no target VA/RVA/raw-offset pointer hits and no `.text` rel32 direct callers, direct SeparatorMenuItem class owner/emitter with PopupMenuControls source root, and first-draft `SeparatorMenuItem::SeparatorMenuItem() : MenuItem() { m_enabled = false; }` C++ with original field spelling/base-constructor inlining still below final-audit.
```

## Validator Needs

No validators were run because this was a report-only pass.

After supervisor implementation, run:

> Executable block R001 was removed from this report and preserved verbatim in [0002JB-SeparatorMenuItemConstructor-source-quality-removed.md](0002JB-SeparatorMenuItemConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected outcome:

- Target page validates at `87/92` with first-draft constructor C++.
- Autogen refresh adds a [UID:0002JB] constructor body to `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.
- `project-level/-auto-completion-stats.md` no longer lists `0002JB` as a stale low-completion constructor.
- Coverage row reflects the replacement text above if supervisor applies it.

## IDA Rename / Type / Comment Recommendations

Recommended only if the supervisor later authorizes IDA edits:

| Address / item | Recommendation | Confidence | Reason |
| --- | --- | ---: | --- |
| `0x005171b0` `sub_5171B0` | Rename to `SeparatorMenuItem_ctor` or equivalent IDA-safe `SeparatorMenuItem::SeparatorMenuItem` name. | High | Final vtable install, class page, and source route all identify the constructor. |
| `0x005171b0` type | `SeparatorMenuItem *__thiscall SeparatorMenuItem_ctor(SeparatorMenuItem *this)` for IDA; source signature `SeparatorMenuItem::SeparatorMenuItem()`. | High | Returns `this` in `eax`, no explicit stack args, receiver in `ecx`. |
| `0x005171d9` call | Comment as `LObject::LObject` reached during expanded `MenuItem` base construction. | High | Exact child [UID:00036Z] documents the constructor. |
| `0x005171f1` vptr store | Comment as temporary `MenuItem` vtable during base construction. | High | Matches `0x0061eb98` and vtable xrefs. |
| `0x005171f7` call | Comment as `InitRectBounds(&m_bounds, 0, 0, 0, 0)`. | High | Exact helper writes four rect fields. |
| `0x005171ff` word store | Comment as `m_enabled=false; m_selected=false` / separator non-interactive state word clear. | Medium-high | `m_enabled` role is strongly supported; exact original spelling remains inferred. |
| `0x00517205` vptr store | Comment as final `SeparatorMenuItem` vtable install. | High | Only raw occurrence of `0x0061ebd0` immediate and vtable data confirms class table. |
| `0x006031df` | Do not rename as project source; comment as compiler EH handler for `SeparatorMenuItem` constructor. | High | Handler validates EH cookie and routes to C++ frame handler. |
| `0x006031d7` | Optional comment as constructor-unwind cleanup funclet tail-jumping to `LObjectDestructorBody`. | Medium-high | Raw disassembly loads saved `this` and jumps `0x004f4a90`. |
| `MenuItem +0x04` | Use `RectBounds m_bounds`. | High | Layout and copy/set helpers prove 16-byte rectangle. |
| `MenuItem +0x14` | Use `bool m_enabled` as source-facing field; preserve `state word` raw note. | Medium-high | Enabled scans consume this byte and constructors seed it. |
| `MenuItem +0x15` | Use `bool m_selected` / selected-highlighted draw state. | Medium-high | String draw path consumes this byte. |
| `SeparatorMenuItem` layout | No fields beyond `MenuItem`; likely size remains `0x18`. | Medium-high | No separator-specific data refs; inherited `MenuItem` deleting wrapper uses base size. |

## Open Questions With Attempted Resolution

- Exact original field spelling: attempted by checking `MenuItem`, `MenuItemLayouts`, state accessors/setters, and `MenuPane` enabled scans. Best current spelling is `m_enabled`; exact original spelling remains inferred, so confidence stays below final-audit.
- Exact constructor call-site reachability: attempted via existing IDA docs plus fresh VA/RVA/raw pointer and `.text` rel32 scans. No direct route was found. Keep as caveat; do not invent callers.
- Base constructor inlining vs explicit call: binary does not call [UID:0002J3]. Current best source shape still uses `: MenuItem()` because the emitted body exactly expands the base setup and derived constructor codegen can inline/coalesce adjacent state writes. Keep this as a codegen note, not a blocker.
- Original source file split: checked `PopupMenuControls`, proposed source tree, class pages, vtable/layout pages, and B003 prior report. Current best route remains consolidated `PopupMenuControls.cpp`; later `MenuItem.cpp` split is plausible but unproven.
- Exact SEH labels/source names: raw EH area was checked. `0x006031df` and adjacent cleanup code are compiler-generated; do not promote labels such as `SEH_5171B0` into source names.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0002JB-SeparatorMenuItemConstructor-source-quality.md`
- Modified: none.
- No by-* docs, generated files, IDA database state, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/0002JB-SeparatorMenuItemConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"0002JB"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002JB-SeparatorMenuItemConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/0002JB-SeparatorMenuItemConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002JB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
