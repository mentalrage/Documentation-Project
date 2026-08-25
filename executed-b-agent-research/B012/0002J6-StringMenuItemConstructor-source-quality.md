** TARGET-REPORT-UID:0002J6 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002J6 StringMenuItemConstructor Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0002J6] as a source-bearing `StringMenuItem` constructor and populate first-draft C++.
- Best direct owner: [UID:0000E8][StringMenuItem](../../../../../by-class/StringMenuItem.md).
- Source route: emit through [UID:0000E8] into [UID:0000MN][PopupMenuControls](../../../../../by-file/PopupMenuControls.md), generated as `NexusTK/ui/menu/PopupMenuControls.cpp`.
- Best source-facing constructor shape: `StringMenuItem::StringMenuItem(const wchar_t *text) : MenuItem() { wcscpy_s(m_text, _countof(m_text), text); }`.
- Best field interpretation: `MenuItem` base construction initializes `m_bounds`, `m_enabled`, and `m_selected`; `StringMenuItem` owns an inline `wchar_t m_text[0x80]` buffer at offset `+0x18`.
- Metadata recommendation: raise from `84/90` to `87/91`, keep `CANONICAL_OWNER:0000E8`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000E8`, and populate `RECONSTRUCTION_CPP CODE`.
- Final disposition: no split, no merge, no no-code proof. The previous blank-C++ language was a follow-up caveat, not an active blocker under the current combined-score/emitter gate.

## Target
- Target UID: `0002J6`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00516ff0-0x00517070.StringMenuItemConstructor.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\0002J6-StringMenuItemConstructor-source-quality.md`
- Current target metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000E8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E8`, blank C++.
- Current parent/gate state: target average is already `87`; [UID:0000E8] `StringMenuItem` is `88/90`; [UID:0000MN] `PopupMenuControls` is `86/85`. The route clears the active code-entry gate.

## Evidence Checked
- Rule sources: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `Agent-B012/goal.md`, `by-structure.md`, and `inference_research.md`.
- Target/support docs: target page, [UID:0000E8] `StringMenuItem`, [UID:00007V] `MenuItem`, [UID:0000CY] `SeparatorMenuItem`, [UID:0000MN] `PopupMenuControls`, [UID:0001BK] `MenuPaneAndItems`, [UID:0001V5] `MenuItemLayouts`, [UID:0001Y4] `MenuItemVtables`, [UID:000195] `LObjectRuntimeShell`, [UID:00015S] `RectGeometryHelpers`, sibling pages [UID:0002J3], [UID:0002J7], [UID:0002J8], [UID:0002J9], [UID:0002JA], [UID:0002JB], and [UID:0002JG].
- Prior work checked: B003 popup-menu source-quality report for `0002J5/0002J9/0002JA/0002JC/0002JD/0002JF/0002JG`; it correctly rerouted `0002J6` to `StringMenuItem` but explicitly left constructor-source C++ as a follow-up.
- Exported function data: `resources/exported_data/functions/0x00516ff0.json`, plus supporting records for `0x00516f00`, `0x00517070`, `0x00517090`, `0x005170d0`, `0x005170f0`, `0x005171b0`, `0x004f4a80`, and `0x004b7c50`.
- Caller context docs: `0x004b1590-0x004b1b87.FolderSelectDialog`, `0x00528e60-0x0052a535.MusicControlDialog`, `0x0058af50-0x0058c350.TerminalPaneAndSetup`, and `0x00599cc0-0x0059bc8b.UserInfoDialogPane`.
- Generated/coverage checks: `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `project-level/-resolved.md`, `project-level/-unresolved.md`, and `by-memory/-coverage-report.md`.
- Numeric conversions: `0x80` = 128, `0x18` = 24, `0x14` = 20, `0x15` = 21, `0x04` = 4, `0x10` = 16, and `0x118` = 280. Verified with `int_convert.py`.
- Live MCP status: direct MCP call to `127.0.0.1:13337/mcp` was unavailable in this session with "Unable to connect to the remote server." This report uses existing recorded live IDA evidence, exported IDA/Ghidra JSON, current support docs, and local generated reports. The key constructor facts are consistent across those sources.

## Current Binary Facts
- IDA target name: `sub_516FF0`; Ghidra target name: `StringMenuItem`; OOAnalyzer identifies it as constructor-like.
- Exact range: `0x00516ff0-0x00517070`, size `0x80` / 128 bytes. Verified with `int_convert.py`.
- Observed ABI: `thiscall`; IDA signature `int __thiscall(int this, wchar_t *Source)`, Ghidra signature `StringMenuItem * __thiscall StringMenuItem(StringMenuItem *this, wchar_t *param_1)`.
- Stack/return shape: `this` in `ecx`, one explicit argument at `[ebp+0x08]`, returns `this`, and ends with `retn 4`.
- Direct callees: `0x004f4a80` (`LObject::LObject` constructor shell), `0x004b7c50` (`InitRectBounds`), and imported `_wcscpy_s`/`wcscpy_s`.
- IDA decompiler shape:

```cpp
int __thiscall sub_516FF0(int this, wchar_t *Source)
{
    sub_4F4A80((_DWORD *)this);
    *(_DWORD *)this = &MenuItem::`vftable';
    sub_4B7C50((_DWORD *)(this + 4), 0, 0, 0, 0);
    *(_WORD *)(this + 20) = 1;
    *(_DWORD *)this = &StringMenuItem::`vftable';
    wcscpy_s((wchar_t *)(this + 24), 0x80u, Source);
    return this;
}
```

- Boundary evidence: predecessor [UID:0000VN] covers `0x00516fe1-0x00516ff0` as fifteen `0xcc` alignment bytes; successor [UID:0002J7] begins exactly at `0x00517070`. No trailing padding belongs to this constructor and no following helper bytes are part of the constructor.
- Vtable evidence: base vtable write `0x0061eb98` at `0x00517031`; final `StringMenuItem` vtable write `0x0061ebb4` at `0x0051704e`.
- Final vtable slots from current docs: `0x0061ebb4` scalar deleting destructor, `0x0061ebb8` inherited runtime slot, `0x0061ebbc` shared no-op slot, `0x0061ebc0` measure-text, `0x0061ebc4` get-text, and `0x0061ebc8` draw-item.
- Direct xrefs: exported IDA data lists 54 direct construction xrefs, with unique caller functions including `0x004b1590`, `0x004b1a00`, `0x00528e60`, `0x0052a010`, `0x0058b650`, and `0x00599cc0`.

## Constructor Source Shape
- The source-ready shape is a normal derived constructor:

```cpp
StringMenuItem::StringMenuItem(const wchar_t *text)
    : MenuItem()
{
    wcscpy_s(m_text, _countof(m_text), text);
}
```

- The compiled function contains the `MenuItem` base construction sequence inline or compiler-expanded:
  - `LObject::LObject()`
  - temporary/base `MenuItem` vtable installation
  - `InitRectBounds(&m_bounds, 0, 0, 0, 0)`
  - state word write `1` at offset `+0x14`
  - final `StringMenuItem` vtable installation
- In source, the base-state steps should be attributed to `MenuItem()` rather than hand-written again inside the derived constructor. This matches the separate [UID:0002J3] `MenuItemConstructor` page and keeps the source plausible for mid-2000s C++.
- The state word write `1` should no longer remain an unknown "state word" caveat. Per [UID:0001V5], `+0x14` is the low-byte `m_enabled` flag and `+0x15` is the high-byte `m_selected` flag; a word write of `1` means `m_enabled = true` and `m_selected = false`.
- The label argument should be `const wchar_t *text` in source. The binary does not modify it, and `wcscpy_s` takes a const source pointer. IDA's `wchar_t *Source` is a decompiler type weakness, not evidence of mutation.
- Use `wcscpy_s(m_text, _countof(m_text), text)` rather than raw `_wcscpy_s((wchar_t *)(this + 24), 0x80, Source)` in final source. The immediate `0x80` is explained by the inline `wchar_t m_text[0x80]` buffer.

## Field / Buffer Ownership
- `m_text` is inline storage owned by `StringMenuItem`, not heap memory, a caller-owned string, or a `mystr` object.
- The buffer starts at `this + 0x18`, which is offset 24 decimal. Verified with `int_convert.py`.
- The buffer capacity is `0x80` wide characters, 128 decimal. Verified with `int_convert.py`.
- `StringMenuItem` minimum object size remains `0x118` / 280 decimal due to the base `MenuItem` state plus the `0x100` byte UTF-16 buffer. Verified with `int_convert.py`.
- Sibling evidence:
  - [UID:0002J7] copies from `this + 0x18` into caller buffers.
  - [UID:0002J8] measures text from `this + 0x18` and computes item dimensions.
  - [UID:0002J9] already has source C++ returning `wcscpy_s(destination, sizeInWords, m_text)`.
  - [UID:0002JA] already has source C++ drawing `m_text`.
  - [UID:0002JG] has no label cleanup because `m_text` is inline storage.

## Caller / Reachability
- The constructor is widely reused by menu/dialog code, which supports class ownership rather than a feature-local helper owner.
- Exported IDA xrefs list 54 direct calls. Representative contexts:
  - `0x004b1590` and `0x004b1a00` in `FolderSelectDialog` drive/list population paths.
  - `0x00528e60` and `0x0052a010` in `MusicControlDialog` construction and drive-popup population paths.
  - `0x0058b650` in `TerminalSetupPane::TerminalSetupPane`, with many setup-menu entries.
  - `0x00599cc0` in `UserInfoDialogPane` construction, with many selection/list entries.
- These callers are consumers of reusable popup-menu controls. None is a better direct source owner than `StringMenuItem`.
- No evidence suggests indirect-only reachability, dead code, a retained raw helper, or compiler-generated glue.

## Owner / Emitter / Source File Routing
- Keep `CANONICAL_OWNER:0000E8` and `EMITTER_UIDS:0000E8`.
- [UID:0000E8] routes to [UID:0000MN] `PopupMenuControls`, whose proposed path is `NexusTK/ui/menu/`.
- Generated marker check shows `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` currently has an empty marker for `0002J6`. Implementation should replace that marker with constructor source once the supervisor accepts this report.
- Rejected owner alternatives:
  - [UID:0000MN] direct file owner: too broad; the constructor is a concrete class method with a vtable and class layout.
  - `FolderSelectDialog`, `MusicControlDialog`, `TerminalSetupPane`, or `UserInfoDialogPane`: those are callers only.
  - [UID:00007V] `MenuItem`: the compiled function finishes with the `StringMenuItem` vtable and label copy; the base class only contributes construction state.
  - `RectGeometryHelpers` or `LObject`: these are callees/dependencies only.

## Heuristic / Inference Reanalysis And Validation
- Source-bearing versus no-code:
  - Evidence checked: exact function range, real constructor ABI, final class vtable store, broad construction xrefs, inline field writes, reconstructable metadata, and valid emitter chain.
  - Decision: source-bearing code. This is not scalar deleting destructor glue, padding, a thunk, or pure compiler output.
- Constructor name/signature:
  - Evidence checked: IDA/Ghidra constructor shapes, vtable installation, one explicit source-string arg, `retn 4`, and sibling class docs.
  - Best name: `StringMenuItem::StringMenuItem`.
  - Best signature: `StringMenuItem::StringMenuItem(const wchar_t *text)`.
  - Rejected alternatives: `sub_516FF0`, `StringMenuItem(wchar_t *Source)` as final source, `CopyText` helper, or free function.
- `_wcscpy_s` source shape:
  - Evidence checked: target import call, immediate capacity `0x80`, sibling `GetText` C++ using `wcscpy_s`, and inline buffer docs.
  - Decision: use `wcscpy_s`, not a hand-written copy loop and not `StringBase`.
  - Best final source: `_countof(m_text)` for the size expression. Literal `0x80` remains acceptable as a fallback if the broader codebase standard avoids `_countof`, but `_countof` better represents the likely MSVC secure CRT source style.
- State word:
  - Evidence checked: constructor word write, base/separator constructor contrast, `MenuItemLayouts`, `MenuItem` accessors, and `StringMenuItemDrawItem`.
  - Decision: the word write initializes two byte fields: `m_enabled = true`, `m_selected = false`.
  - Rejected alternatives: unknown flags dword, draw-color enum, or string-owned state.
- Exception/unwind glue:
  - Evidence checked: prologue with SEH registration, security cookie, and Ghidra EH locals.
  - Decision: compiler-generated construction/unwind scaffolding. Do not source-port `SEH_516FF0`, security-cookie references, or cleanup labels.
- Range/split/merge:
  - Evidence checked: target body bytes, predecessor padding, next function start, exported function size, ignored padding ledger, and aggregate page.
  - Decision: exact half-open range `0x00516ff0-0x00517070`; no split/merge changes.
- Prior-report assumptions:
  - B003's owner/emitter reroute to `StringMenuItem` is still correct.
  - B003's `m_text[0x80]`, `GetText`, `DrawItem`, and ordinary/default destructor policy remain valid.
  - B003's "constructor-source follow-up" caveat is now resolved enough for first-draft C++.
- Open questions:
  - Exact original parameter spelling is not symbol-proven; use `text`.
  - Exact source macro for the buffer count is not proven; `_countof(m_text)` is the best MSVC-era source expression.
  - Whether the compiler inlined `MenuItem()` or the original base constructor was header-defined is not symbol-proven. This does not block source-style C++; the derived constructor should still call the base constructor in source.
  - These are source spelling/modeling caveats, not behavior, owner, route, or C++ blockers.

## First-Draft C++ Recommendation
Populate [UID:0002J6] `RECONSTRUCTION_CPP CODE` with this source-style draft:

```cpp
StringMenuItem::StringMenuItem(const wchar_t *text)
    : MenuItem()
{
    wcscpy_s(m_text, _countof(m_text), text);
}
```

Source-shape notes:
- This draft intentionally omits explicit vtable stores, SEH setup, security-cookie cleanup, and unwind labels.
- The `MenuItem()` base constructor should carry the bounds and enabled/selected initialization. If [UID:0002J3] later receives C++, its source-ready body should initialize `m_bounds` to `{0, 0, 0, 0}`, set `m_enabled = true`, and clear `m_selected`.
- If the final project style does not use `_countof`, replace it with the project-local array-count macro. A raw `0x80` literal should be the fallback only if no count macro exists.
- The code assumes class declarations include `wchar_t m_text[0x80]` and the base `MenuItem` constructor declaration.

## Exact Metadata / Target Doc Recommendations
Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:0000E8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000E8
RECONSTRUCTION_CPP CODE: populate with the first-draft C++ above
```

Recommended target status replacement:

```text
- Entity kind: class constructor.
- Owner: [UID:0000E8] `StringMenuItem`.
- Source route: [UID:0000E8] -> [UID:0000MN] `PopupMenuControls`, generated as `NexusTK/ui/menu/PopupMenuControls.cpp`.
- Formal C++: source-ready under the active combined-score/emitter gate. The previous blank-C++ caveat is resolved by the constructor-source pass; remaining uncertainty is limited to exact parameter spelling and array-count macro spelling.
```

Recommended behavior wording additions/replacements:

```text
- Source-facing behavior: constructs the `MenuItem` base, then copies `text` into the inline `wchar_t m_text[0x80]` buffer with `wcscpy_s`.
- Binary construction detail: the emitted constructor contains compiler/base construction steps: `LObject::LObject`, temporary `MenuItem` vtable installation, `InitRectBounds(&m_bounds, 0, 0, 0, 0)`, word write `1` at `+0x14` (`m_enabled=true`, `m_selected=false`), final `StringMenuItem` vtable installation, and the label copy.
- Rebuild handling: source-authored constructor body plus compiler-generated EH/security-cookie/unwind scaffolding. Do not hand-port `SEH_516FF0` or the security-cookie references.
```

Recommended generated-name cleanup in the target:

```text
Replace final-source mentions of `sub_516FF0` with `StringMenuItem::StringMenuItem`.
Replace final-source mentions of `sub_4F4A80` / raw `0x004f4a80` with `LObject::LObject` where the source role is discussed.
Replace final-source mentions of `sub_4B7C50` / raw `0x004b7c50` with `InitRectBounds`.
Keep raw addresses only in evidence sections where they are needed for audit/search.
```

## Exact Support-Doc Recommendations
- [UID:0000E8] `StringMenuItem`: replace the method-map constructor row with:

```text
| [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) | `StringMenuItem::StringMenuItem(const wchar_t *text)` | Initializes the base menu item and copies label text into inline `m_text[0x80]`; first-draft C++ is ready on the target page. |
```

- [UID:0000E8] `StringMenuItem`: add a short source-shape note:

```text
The constructor source should be `StringMenuItem::StringMenuItem(const wchar_t *text) : MenuItem() { wcscpy_s(m_text, _countof(m_text), text); }`. The binary expands/contains base construction, but the source representation should not duplicate base vtable/EH scaffolding inside the derived constructor.
```

- [UID:0001V5] `MenuItemLayouts`: no mandatory factual change. Optional cleanup: mention [UID:0002J6] as a constructor that writes word `1` and therefore initializes `m_enabled=true` and `m_selected=false`.
- [UID:0002J3] `MenuItemConstructor`: no mandatory change for this report, but its later source-quality pass should align with the same base constructor interpretation: `InitRectBounds`, `m_enabled=true`, `m_selected=false`, no handwritten vtable/EH glue.
- [UID:0000MN] `PopupMenuControls`: no route change. Optional contents note: `StringMenuItem` constructor is now source-ready while adjacent copy/measure constructor-family pages may still need their own source-quality pass.
- `project-level/-unresolved.md`: after target implementation, the `sub_516FF0`, `sub_4F4A80`, and `sub_4B7C50` unresolved text entries for this target should disappear through normal validator/resolved regeneration. Do not hand-edit project-level reports unless the supervisor asks.

## Exact by-memory Coverage Replacement Row
Supervisor-owned replacement for the current [UID:0002J6] row in `by-memory/-coverage-report.md`; B012 did not edit the file:

```text
        - [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) 0x00516ff0-0x00517070 | constructor | StringMenuItemConstructor : reconstructable : 87% : very strong : B012 2026-06-19 source-quality reanalysis resolves code-ready `StringMenuItem::StringMenuItem(const wchar_t *text)`: exact 0x80 / 128-byte constructor (Verified with int_convert.py), 54 direct construction xrefs across FolderSelectDialog, MusicControlDialog, TerminalSetupPane, and UserInfoDialogPane contexts, no split/merge with preceding 0xcc padding or following CopyText child, compiler SEH/security-cookie/unwind glue excluded from source, base `MenuItem` construction initializes `m_bounds` and state word +0x14 / 20 as `m_enabled=true` and `m_selected=false` (Verified with int_convert.py), final StringMenuItem vtable 0x0061ebb4, inline `m_text[0x80]` at +0x18 / 24 bytes (Verified with int_convert.py), `wcscpy_s` capacity 0x80 / 128 wide characters (Verified with int_convert.py), direct StringMenuItem owner/emitter through PopupMenuControls.cpp, and first-draft constructor C++ readiness under the active combined-score/emitter gate.
```

## IDA Rename / Type / Comment Recommendations
- Rename `sub_516FF0` to `StringMenuItem::StringMenuItem` if the IDA naming policy accepts C++ constructor names; otherwise use `StringMenuItem_ctor`.
- Apply/record target type: `StringMenuItem *__thiscall StringMenuItem_ctor(StringMenuItem *this, const wchar_t *text)` for IDA compatibility, with source note `StringMenuItem::StringMenuItem(const wchar_t *text)`.
- Rename/type `sub_4F4A80` as `LObject::LObject` if not already applied in the IDB.
- Rename/type `sub_4B7C50` as `InitRectBounds` if not already applied; source-facing type should be equivalent to `void InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom)`.
- Add constructor comment: `Constructs StringMenuItem; source shape is MenuItem() base plus wcscpy_s(m_text, _countof(m_text), text).`
- Add field comment at `this + 0x18`: `StringMenuItem::m_text[0x80]`.
- Add field comment at `this + 0x14`: `MenuItem state bytes: +0x14 m_enabled, +0x15 m_selected; word write 1 means enabled=true, selected=false.`
- Mark `SEH_516FF0`/security-cookie cleanup as compiler-generated construction-unwind scaffolding, not a source helper name.

## Validation Commands Needed After Implementation
Run file-mode validation for every edited by-* doc, then refresh generated output/coverage:

> Executable block R001 was removed from this report and preserved verbatim in [0002J6-StringMenuItemConstructor-source-quality-removed.md](0002J6-StringMenuItemConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run the optional support-doc validation commands for files actually edited. If the supervisor applies the banned coverage-row replacement separately, validate that file under supervisor ownership:

> Executable block R002 was removed from this report and preserved verbatim in [0002J6-StringMenuItemConstructor-source-quality-removed.md](0002J6-StringMenuItemConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files
- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\0002J6-StringMenuItemConstructor-source-quality.md`
- Modified: none outside Agent-B012 research.
- Not edited: target by-memory doc, support by-* docs, generated output, and `by-memory/-coverage-report.md`.

## Confidence
- Recommendation confidence: high for behavior, range, owner/emitter route, field roles, inline buffer ownership, base-state interpretation, and C++ readiness.
- Remaining uncertainty: exact original parameter name, exact source macro used for the array count, and whether the base constructor source was header-defined/inlined or simply optimized into the derived constructor body.
- Score confidence: `87/91` is justified by exact binary behavior, broad xref evidence, resolved class/source route, and source-ready constructor shape while staying below final-audit scores because original source spelling is still inferred rather than symbol-proven.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0002J6-StringMenuItemConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0002J6"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002J6-StringMenuItemConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/0002J6-StringMenuItemConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002J6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
