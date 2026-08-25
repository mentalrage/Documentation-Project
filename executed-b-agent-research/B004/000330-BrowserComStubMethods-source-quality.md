** TARGET-REPORT-UID:000330 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000330 BrowserComStubMethods Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000330] `by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md` as one reconstructable Browser COM method-stub child owned by [UID:000013][Browser](by-class/Browser.md) and emitted through [UID:000013]. Do not split the target.
- Final disposition: source-quality repair is recommended, not ownership repair. The existing owner/emitter route is correct, but the target should replace generated `sub_` labels with exact or best-supported COM method names, add current PE/vtable/import evidence, and include first-draft method-body C++ once the Browser class declaration support is updated in the same implementation pass.
- Required action: update the target and support docs listed in the implementation checklist; leave `by-memory/-coverage-report.md` to the supervisor with the exact replacement row in this report.
- Confidence: high for owner, range, source placement, vtable slot mapping, fixed-return behavior, and `GetWindow`/`GetWindowContext`; medium-high for final source declaration spelling because the Browser class multiple-inheritance declaration is still not fully implemented in by-* C++.

## Supporting Research

## Target

- Target UID: `000330`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0046f670-0x0046f808.BrowserComStubMethods.md`
- Source queue/report row: assignment `B004-goal2-browser-com-stub-methods-source-quality-000330-20260619`, coverage row at `by-memory/-coverage-report.md:707`.
- Current supervisor classification: reconstructable Browser class COM method-stub child, `85/87`, owner/emitter [UID:000013][Browser](by-class/Browser.md).
- Current metadata:
  - `COMPLETION:85`
  - `CONFIDENCE:87`
  - `CANONICAL_OWNER:000013`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:000013`
  - formal C++ block blank
- Recommended metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:000013` unchanged
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `EMITTER_UIDS:000013` unchanged
  - formal C++ should be populated only together with Browser class declaration/header support; the method bodies themselves are source-ready at first-draft level.

## Executive Recommendation

The existing parent is correct: this range is part of the legacy `Browser` COM object, not `BrowserWindow`, not `BrowserControlPaneOld`, not `BrowserThread`, and not a free helper. The current documentation is under-detailed because it groups most functions as `sub_46Fxxx` fixed stubs and does not resolve the COM interface slot names. Current local PE evidence plus existing IDA-backed docs support the following exact source-facing mapping:

- `0x0046f670`: `Browser::AddRef`, fixed return `2`.
- `0x0046f680`: `Browser::Release`, fixed return `1`.
- `0x0046f690-0x0046f6e8`: `IOleClientSite` methods `SaveObject`, `GetMoniker`, `GetContainer`, `ShowObject`, `OnShowWindow`, and `RequestNewObjectLayout`, all `E_NOTIMPL`.
- `0x0046f6f0-0x0046f7d8`: `IOleInPlaceSite` / inherited `IOleWindow` methods, including real `GetWindow`, real `GetWindowContext`, three `S_OK` no-op methods, and several `E_NOTIMPL` stubs.
- `0x0046f7e0-0x0046f808`: `IDispatch` metadata methods: `GetIDsOfNames`, `GetTypeInfo`, and `GetTypeInfoCount`, all `E_NOTIMPL`.

The target should not be split because every function in `0x0046f670-0x0046f808` belongs to the same Browser object vtable group and the same source class. The ABI adjustor thunks that call `AddRef` and `Release` are already separate non-emitting pages and should stay there.

## Supervisor Active Recheck

- Supervisor instruction: produce a report-only B004 source-quality research file for [UID:000330] and do not edit by-* docs or `by-memory/-coverage-report.md`.
- Report path required by assignment: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\000330-BrowserComStubMethods-source-quality.md`.
- Split repair required before reporting: no. The parent aggregate [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md) is already split. The target range is an exact child and current PE evidence confirms its half-open range.
- Live IDA MCP status in this session: unavailable. The direct endpoint request returned `Unable to connect to the remote server`. This report therefore separates current-session local PE evidence from prior IDA MCP documentation evidence. The removed literal PowerShell command is preserved only in the linked inert archive.
- Current-session binary used for local verification: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.

## Inference Research Guidance Check

`by-structure.md` requires direct semantic ownership, not merely file routing. This target is class-owned because the vtable slots belong to Browser's COM interface slices, while final generated output routes through the Browser source root. `EMITTER_UIDS` should remain [UID:000013] because the Browser class is itself emitted through [UID:0000HV][Browser](by-file/Browser.md).

`inference_research.md` warns that adjacency alone is weak. This recommendation does not depend on adjacency alone. It uses:

- vtable slot addresses in `.rdata`,
- exact local PE disassembly and IAT import resolution,
- existing IDA-backed Browser constructor/destructor/setup docs,
- QueryInterface pointer-adjustment evidence,
- separate thunk-page evidence for compiler-generated adjustors,
- negative evidence against direct code callers outside vtable/thunk routes.

Existing docs were treated as leads. The current target's statement that the last three methods are "service/show-UI style stubs" is stale for this range. The vtable order proves they are the three `IDispatch` metadata methods immediately preceding `Browser::Invoke`.

## Heuristic / Inference Reanalysis And Validation

### Generated method names

- Issue checked: target still uses `sub_46F670`, `sub_46F680`, `sub_46F690`, and similar compiler/generated names.
- Evidence checked: local PE disassembly of `0x0046f670-0x0046f808`, Browser vtable dwords at `0x00613830-0x00613918`, existing [UID:00032Z][BrowserQueryInterface](by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md), existing [UID:0001OB][BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md), and B007 Browser class source-quality report as a lead.
- Best-supported names:
  - `sub_46F670` -> `Browser::AddRef` (`confirmed by IUnknown slot order and fixed ULONG return`).
  - `sub_46F680` -> `Browser::Release` (`confirmed by IUnknown slot order and secondary Release thunks`).
  - `sub_46F690` -> `Browser::SaveObject`.
  - `sub_46F6A0` -> `Browser::GetMoniker`.
  - `sub_46F6B0` -> `Browser::GetContainer`.
  - `sub_46F6C0` -> `Browser::ShowObject`.
  - `sub_46F6D0` -> `Browser::OnShowWindow`.
  - `sub_46F6E0` -> `Browser::RequestNewObjectLayout`.
  - `sub_46F6F0` -> `Browser::GetWindow`.
  - `sub_46F710` -> `Browser::ContextSensitiveHelp`.
  - `sub_46F720` -> `Browser::CanInPlaceActivate`.
  - `sub_46F730` -> `Browser::OnInPlaceActivate`.
  - `sub_46F740` -> `Browser::OnUIActivate`.
  - `sub_46F750` -> `Browser::GetWindowContext`.
  - `sub_46F780` -> `Browser::Scroll`.
  - `sub_46F790` -> `Browser::OnUIDeactivate`.
  - `sub_46F7A0` -> `Browser::OnInPlaceDeactivate`.
  - `sub_46F7B0` -> `Browser::DiscardUndoState`.
  - `sub_46F7C0` -> `Browser::DeactivateAndUndo`.
  - `sub_46F7D0` -> `Browser::OnPosRectChange`.
  - `sub_46F7E0` -> `Browser::GetIDsOfNames`.
  - `sub_46F7F0` -> `Browser::GetTypeInfo`.
  - `sub_46F800` -> `Browser::GetTypeInfoCount`.
- Rejected alternatives:
  - `0x0046f7e0/0x0046f7f0/0x0046f800` as `QueryService`, `QueryStatus`, or `TranslateAccelerator` are rejected for this range. The vtable slice at `0x0061389c` is the `IDispatch` view: `QueryInterface`, `AddRef`, `Release`, then the three metadata methods, then `Invoke` at `0x006138b4`.
  - Treating all fixed-return methods as anonymous "not implemented stubs" is too shallow. The byte bodies are tiny, but vtable order gives defensible source method names.
- Remaining blocker: original project spelling for comments/macros is not proven. Use standard COM method names, not custom names.

### Interface and vtable slice names

- Issue checked: exact Browser interface slices.
- Evidence checked: vtable dwords in local PE at `0x00613830-0x00613918`, existing Browser class and QueryInterface docs, GUID constants in [UID:0003OH][BrowserComGuidConstants](by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md).
- Best-supported slices:
  - `0x00613830`: `Browser::IOleClientSite_vftable`.
  - `0x0061385c`: `Browser::IOleInPlaceSite_vftable`; includes inherited `IOleWindow::GetWindow`.
  - `0x0061389c`: `Browser::IDispatch_vftable` / event-sink view used for `DIID_DWebBrowserEvents2`.
  - `0x006138bc`: `Browser::IDocHostUIHandler`-shaped vtable, outside this target except for relationship.
  - `0x00613908`: `Browser::IDocHostShowUI`-shaped vtable, outside this target except for relationship.
- Rejected alternatives:
  - A separate `IUnknown` vtable is rejected; `IUnknown` slots are inherited into every COM interface vtable.
  - A separate `IOleWindow` concrete base is not needed; `IOleWindow` is the base of `IOleInPlaceSite`.
- Remaining blocker: Browser `QueryInterface` docs currently record no direct `IID_IDocHostUIHandler` or `IID_IDocHostShowUI` returns even though those vtable slices exist. This affects class declaration notes, not this target's target-range method names.

### Field and helper meanings

- Issue checked: target field offsets and helper imports.
- Evidence checked: local disassembly and import table; Browser destructor/constructor docs.
- Best-supported field/helper meanings:
  - Target `GetWindow` loads `[this + 0x10]` from the adjusted `IOleInPlaceSite` view. Because that view starts at Browser base `+0x04`, the source field is Browser base `+0x14`, already documented as `m_hWnd`.
  - Target `GetWindowContext` uses `[edi + 0x10]` from the adjusted view, again Browser base `+0x14` / `m_hWnd`.
  - PE import table resolves IAT `0x0060d47c` to `USER32.dll!GetClientRect`; both calls in `GetWindowContext` use that import.
  - Supporting Browser field names from existing docs remain valid context: `+0x18` `m_webBrowser`, `+0x1c` `m_adviseCookie`, `+0x228` navigation string pointer/buffer, `+0x22c` state flags, and `+0x230` wide/current URL string member. Only `m_hWnd` is directly read by this target.
- Rejected alternatives:
  - Treating `[this + 0x10]` as Browser base `+0x10` is rejected because the target is called through the `IOleInPlaceSite` secondary interface view at base `+0x04`.
  - Treating the IAT call as an unknown helper is rejected; import parsing identifies `GetClientRect`.
- Remaining blocker: exact project type for the wide string member at `+0x230` is outside this target. It does not block the target's `m_hWnd` use.

### Caller/reachability

- Issue checked: direct callers, vtable-only reachability, and adjustor thunks.
- Evidence checked: local dword reference scan over the PE, direct `E8`/`E9` rel32 scan in `.text`, and disassembly of `0x0047084f-0x004708c7` plus `0x00470fdc-0x0047107c`.
- Findings:
  - Every target start has a dword reference from the Browser vtable group and no other absolute dword hits in current PE output.
  - Direct `E8`/`E9` hits into the target exist only for `AddRef` and `Release`, and they are compiler adjustor thunks:
    - `0x00470854`, `0x0047085e`, `0x00470868`, `0x00470872` tail-jump to `0x0046f670`.
    - `0x00471059`, `0x00471063`, `0x0047106d`, `0x00471077` tail-jump to `0x0046f680`.
  - Other target methods are vtable-only in the scanned local PE evidence.
- Rejected alternatives:
  - The adjustor thunks are not additional source methods and should not be merged into this target's C++.
  - Lack of direct code callers is not a no-route blocker because COM virtual dispatch is the expected route.
- Remaining blocker: indirect runtime calls are not enumerable from static PE byte search alone, but vtable placement is direct source-level reachability evidence for COM callbacks.

### Range and split decision

- Issue checked: whether `0x0046f670-0x0046f808` is overbroad or mixed.
- Evidence checked: target bytes, vtable groups, adjacent child docs.
- Decision: keep as one exact source-bearing child. All contained functions are Browser COM virtual methods from three adjacent Browser interface slices. The page should not be split by interface because the methods are small and share one class/source owner; splitting would produce many tiny pages without improving ownership accuracy.
- Rejected alternatives:
  - Merge into [UID:00032Z][BrowserQueryInterface] is rejected; `QueryInterface` is a full method body with GUID decision logic and separate range.
  - Merge into [UID:000331][BrowserInvokeAndSwitchTable] is rejected; `Invoke` is a separate source method plus switch table.
  - Merge into [UID:000332][BrowserDocHostShowUiStubs] is rejected; that page starts after `Invoke` and covers different vtable slices.
  - Merge with adjustor thunk pages is rejected because those are compiler-generated ABI artifacts.

### Source placement

- Issue checked: Browser file vs BrowserWindow, BrowserControlPaneOld, BrowserThread, or new `BrowserLegacy.cpp`.
- Evidence checked: Browser class page, Browser file page, parent aggregate split, constructor/destructor docs, vtable docs, and proposed source tree.
- Best placement: [UID:000013][Browser](by-class/Browser.md), emitted through [UID:0000HV][Browser](by-file/Browser.md) under `NexusTK/browser/Browser.cpp`.
- Rejected alternatives:
  - `BrowserWindow`: owns modern host/window code and separate COM stubs, but this target's vtable group is the legacy `Browser` object initialized at Browser object offsets and linked to [UID:000013].
  - `BrowserControlPaneOld`: allocates and stores a `Browser *`, but it does not own the Browser COM methods.
  - `BrowserThread`: creates/uses the Browser object during host setup, but does not own the Browser class.
  - New `BrowserLegacy.cpp`: plausible future source split, but not proven enough to change current owner/emitter. The current validated source root is [UID:0000HV].

### Final C++ readiness

- Issue checked: whether formal C++ should remain blank.
- Evidence checked: target score/emitter gate, method mappings, existing generated `auto-generated/NexusTK/browser/Browser.cpp`, and Browser class declaration state.
- Decision: the method bodies are ready for first-draft C++ at target level, but implementation should include or coordinate a Browser class declaration/support update. Adding only method definitions without a declared `Browser` class/interface list would leave generated source structurally incomplete.
- Rejected alternatives:
  - Keeping target C++ blank solely because the methods are stubs is rejected. Stubs are source-authored COM overrides.
  - Emitting adjustor thunk source is rejected. Correct C++ is method definitions plus multiple-interface class declarations that let the compiler regenerate thunks.
- Remaining blocker: final class declaration/header split and exact `Browser` interface exposure notes remain below final audit. This caps scores below `95`, not below first-draft C++ eligibility.

## Evidence Standards Used

- Current-session local PE evidence:
  - PE section mapping for `.text` and `.rdata`.
  - Capstone disassembly of `0x0046f670-0x0046f808`.
  - Browser vtable dword dump at `0x00613830-0x00613918`.
  - full-file dword hit scan for target starts.
  - `.text` direct `E8`/`E9` hit scan.
  - import-table parse proving `0x0060d47c` is `USER32.dll!GetClientRect`.
- Existing IDA-backed documentation evidence:
  - [UID:000013][Browser](by-class/Browser.md)
  - [UID:0000HV][Browser](by-file/Browser.md)
  - [UID:0000ZF][BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
  - [UID:00032Z][BrowserQueryInterface](by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md)
  - [UID:0001OB][BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)
  - [UID:0003OH][BrowserComGuidConstants](by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md)
  - [UID:00033G][BrowserComAdjustorThunks](by-memory/0x0047084f-0x004708c7.BrowserComAdjustorThunks.md)
  - [UID:00033M][BrowserOleAdjustorAndDelegationThunks](by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md)
- Generated output used only as a state check:
  - `auto-generated/NexusTK/browser/Browser.cpp` currently shows [UID:000330] as an empty emitter marker, not source truth.

## Current-Session Local PE Facts

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- File size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Target section: `.text`, mapped at VA `0x00401000-0x0060d000`.
- Vtable section: `.rdata`, mapped at VA `0x0060e000-0x0066d000`.
- Target bytes: `0x198` / 408 bytes at `0x0046f670-0x0046f808`.
- Target SHA-256: `06837329c647d09c73110dde56b0ceadc69a015f8781d4b1d5e16194b6879d2e`.
- First 32 target bytes: `b802000000c20400ccccccccccccccccb801000000c20400cccccccccccccccc`.
- Last 32 target bytes: `ccccccccccccccccb801400080c21000ccccccccccccccccb801400080c20800`.
- Import verification: IAT `0x0060d47c` resolves to `USER32.dll!GetClientRect`.

## Vtable Slot Map

Local PE dword dump for the Browser vtable group relevant to this target:

| Vtable address | Function address | Best source slot |
| --- | ---: | --- |
| `0x00613830` | `0x0046f540` | `IOleClientSite::QueryInterface` implemented by `Browser::QueryInterface` |
| `0x00613834` | `0x0046f670` | `IOleClientSite::AddRef` / `Browser::AddRef` |
| `0x00613838` | `0x0046f680` | `IOleClientSite::Release` / `Browser::Release` |
| `0x0061383c` | `0x0046f690` | `IOleClientSite::SaveObject` |
| `0x00613840` | `0x0046f6a0` | `IOleClientSite::GetMoniker` |
| `0x00613844` | `0x0046f6b0` | `IOleClientSite::GetContainer` |
| `0x00613848` | `0x0046f6c0` | `IOleClientSite::ShowObject` |
| `0x0061384c` | `0x0046f6d0` | `IOleClientSite::OnShowWindow` |
| `0x00613850` | `0x0046f6e0` | `IOleClientSite::RequestNewObjectLayout` |
| `0x0061385c` | `0x00470fdc` | `IOleInPlaceSite::QueryInterface` adjustor thunk |
| `0x00613860` | `0x0047084f` | `IOleInPlaceSite::AddRef` adjustor thunk |
| `0x00613864` | `0x00471054` | `IOleInPlaceSite::Release` adjustor thunk |
| `0x00613868` | `0x0046f6f0` | `IOleWindow::GetWindow` |
| `0x0061386c` | `0x0046f710` | `IOleWindow::ContextSensitiveHelp` |
| `0x00613870` | `0x0046f720` | `IOleInPlaceSite::CanInPlaceActivate` |
| `0x00613874` | `0x0046f730` | `IOleInPlaceSite::OnInPlaceActivate` |
| `0x00613878` | `0x0046f740` | `IOleInPlaceSite::OnUIActivate` |
| `0x0061387c` | `0x0046f750` | `IOleInPlaceSite::GetWindowContext` |
| `0x00613880` | `0x0046f780` | `IOleInPlaceSite::Scroll` |
| `0x00613884` | `0x0046f790` | `IOleInPlaceSite::OnUIDeactivate` |
| `0x00613888` | `0x0046f7a0` | `IOleInPlaceSite::OnInPlaceDeactivate` |
| `0x0061388c` | `0x0046f7b0` | `IOleInPlaceSite::DiscardUndoState` |
| `0x00613890` | `0x0046f7c0` | `IOleInPlaceSite::DeactivateAndUndo` |
| `0x00613894` | `0x0046f7d0` | `IOleInPlaceSite::OnPosRectChange` |
| `0x0061389c` | `0x00470fe6` | `IDispatch::QueryInterface` adjustor thunk |
| `0x006138a0` | `0x00470859` | `IDispatch::AddRef` adjustor thunk |
| `0x006138a4` | `0x0047105e` | `IDispatch::Release` adjustor thunk |
| `0x006138a8` | `0x0046f800` | `IDispatch::GetTypeInfoCount` |
| `0x006138ac` | `0x0046f7f0` | `IDispatch::GetTypeInfo` |
| `0x006138b0` | `0x0046f7e0` | `IDispatch::GetIDsOfNames` |
| `0x006138b4` | `0x0046f810` | `IDispatch::Invoke` |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046f670-0x0046f808` | [UID:000330] `by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md` | Browser `IOleClientSite`, `IOleInPlaceSite`, and `IDispatch` COM stub/method cluster | true | [UID:000013] `Browser` | current `85/87`, recommended `88/91` | exact child, keep assigned and source-bearing |
| `0x0047084f-0x00470877` | [UID:00033G] `by-memory/0x0047084f-0x004708c7.BrowserComAdjustorThunks.md` | Browser secondary-interface `AddRef` adjustor thunks to `0x0046f670` | false | parent blank; semantic Browser | `86/90` | support evidence only, do not emit |
| `0x00471054-0x0047107c` | [UID:00033M] `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md` | Browser secondary-interface `Release` adjustor thunks to `0x0046f680` | false | parent blank; semantic Browser | `86/90` | support evidence only, do not emit |

## Target Function Inventory

| Range | Source-facing method | Binary behavior | Confidence |
| --- | --- | --- | --- |
| `0x0046f670-0x0046f678` | `ULONG Browser::AddRef()` | `mov eax, 2; ret 4` | High |
| `0x0046f680-0x0046f688` | `ULONG Browser::Release()` | `mov eax, 1; ret 4` | High |
| `0x0046f690-0x0046f698` | `HRESULT Browser::SaveObject()` | `E_NOTIMPL; ret 4` | High |
| `0x0046f6a0-0x0046f6a8` | `HRESULT Browser::GetMoniker(DWORD, DWORD, IMoniker **)` | `E_NOTIMPL; ret 0x10` | High |
| `0x0046f6b0-0x0046f6b8` | `HRESULT Browser::GetContainer(IOleContainer **)` | `E_NOTIMPL; ret 8` | High |
| `0x0046f6c0-0x0046f6c8` | `HRESULT Browser::ShowObject()` | `E_NOTIMPL; ret 4` | High |
| `0x0046f6d0-0x0046f6d8` | `HRESULT Browser::OnShowWindow(BOOL)` | `E_NOTIMPL; ret 8` | High |
| `0x0046f6e0-0x0046f6e8` | `HRESULT Browser::RequestNewObjectLayout()` | `E_NOTIMPL; ret 4` | High |
| `0x0046f6f0-0x0046f704` | `HRESULT Browser::GetWindow(HWND *)` | writes hosted HWND from adjusted-view `+0x10` / Browser base `m_hWnd` and returns `S_OK` | High |
| `0x0046f710-0x0046f718` | `HRESULT Browser::ContextSensitiveHelp(BOOL)` | `E_NOTIMPL; ret 8` | High |
| `0x0046f720-0x0046f725` | `HRESULT Browser::CanInPlaceActivate()` | `S_OK; ret 4` | High |
| `0x0046f730-0x0046f735` | `HRESULT Browser::OnInPlaceActivate()` | `S_OK; ret 4` | High |
| `0x0046f740-0x0046f748` | `HRESULT Browser::OnUIActivate()` | `E_NOTIMPL; ret 4` | High |
| `0x0046f750-0x0046f776` | `HRESULT Browser::GetWindowContext(...)` | calls `GetClientRect(m_hWnd, lprcPosRect)`, calls `GetClientRect(m_hWnd, lprcClipRect)`, returns `S_OK` | High |
| `0x0046f780-0x0046f788` | `HRESULT Browser::Scroll(SIZE)` | `E_NOTIMPL; ret 0x0c` | High |
| `0x0046f790-0x0046f798` | `HRESULT Browser::OnUIDeactivate(BOOL)` | `E_NOTIMPL; ret 8` | High |
| `0x0046f7a0-0x0046f7a5` | `HRESULT Browser::OnInPlaceDeactivate()` | `S_OK; ret 4` | High |
| `0x0046f7b0-0x0046f7b8` | `HRESULT Browser::DiscardUndoState()` | `E_NOTIMPL; ret 4` | High |
| `0x0046f7c0-0x0046f7c8` | `HRESULT Browser::DeactivateAndUndo()` | `E_NOTIMPL; ret 4` | High |
| `0x0046f7d0-0x0046f7d8` | `HRESULT Browser::OnPosRectChange(LPCRECT)` | `E_NOTIMPL; ret 8` | High |
| `0x0046f7e0-0x0046f7e8` | `HRESULT Browser::GetIDsOfNames(...)` | `E_NOTIMPL; ret 0x18` | High |
| `0x0046f7f0-0x0046f7f8` | `HRESULT Browser::GetTypeInfo(...)` | `E_NOTIMPL; ret 0x10` | High |
| `0x0046f800-0x0046f808` | `HRESULT Browser::GetTypeInfoCount(UINT *)` | `E_NOTIMPL; ret 8` | High |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00613834` | dword value `0x0046f670` | Primary Browser `IOleClientSite::AddRef` vtable slot. |
| `0x00613838` | dword value `0x0046f680` | Primary Browser `IOleClientSite::Release` vtable slot. |
| `0x0061383c-0x00613850` | dwords to `0x0046f690-0x0046f6e0` | `IOleClientSite` non-IUnknown method slots. |
| `0x00613868-0x00613894` | dwords to `0x0046f6f0-0x0046f7d0` | `IOleInPlaceSite` / `IOleWindow` method slots. |
| `0x006138a8-0x006138b0` | dwords to `0x0046f800`, `0x0046f7f0`, `0x0046f7e0` | `IDispatch` metadata method slots. |
| `0x00470854`, `0x0047085e`, `0x00470868`, `0x00470872` | direct `jmp 0x46f670` after subtracting `4`, `8`, `0x10`, or `0x0c` from stack `this` | Multiple-inheritance `AddRef` adjustor thunks. |
| `0x00471059`, `0x00471063`, `0x0047106d`, `0x00471077` | direct `jmp 0x46f680` after subtracting `4`, `8`, `0x10`, or `0x0c` from stack `this` | Multiple-inheritance `Release` adjustor thunks. |
| `0x0046f750` | calls through IAT `0x0060d47c` twice | `GetWindowContext` fills both position and clipping rectangles with `USER32.dll!GetClientRect(m_hWnd, ...)`. |
| Other target starts | no direct `E8`/`E9` branch hits found in local `.text` scan | Expected COM virtual-call-only reachability, not a dead-code signal. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:000013][Browser](by-class/Browser.md) records Browser as the legacy WebBrowser COM object/event sink and lists the five vtable slices at offsets `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10`.
- [UID:0000HV][Browser](by-file/Browser.md) places Browser under `NexusTK/browser/Browser.cpp` with BrowserWindow, BrowserThread, BrowserControlPane, BrowserControlPaneOld, BrowserDialog, BrowserPane, and browser notification support.
- [UID:0000ZF][BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md) already classifies this range as an exact Browser child in a mixed parent inventory.
- [UID:00032Z][BrowserQueryInterface](by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md) confirms Browser `QueryInterface` returns adjusted interface pointers `this`, `this + 4`, and `this + 8`.
- [UID:0001OB][BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records Browser vtable slice refs from construction/destruction/setup families.
- [UID:0003OH][BrowserComGuidConstants](by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md) identifies `IID_IUnknown`, `IID_IOleClientSite`, `IID_IOleWindow`, `IID_IOleInPlaceSite`, `IID_IDispatch`, and `DIID_DWebBrowserEvents2` in the browser COM GUID band.
- [UID:00033G][BrowserComAdjustorThunks](by-memory/0x0047084f-0x004708c7.BrowserComAdjustorThunks.md) and [UID:00033M][BrowserOleAdjustorAndDelegationThunks](by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md) already classify adjustor thunks as non-emitting ABI artifacts.

Existing docs that are stale or incomplete:

- [UID:000330] currently names the final three functions only as `sub_46F7E0`, `sub_46F7F0`, and `sub_46F800` and describes them as "service/show-UI style stubs." That is stale. Vtable order proves `GetIDsOfNames`, `GetTypeInfo`, and `GetTypeInfoCount`.
- [UID:000013][Browser](by-class/Browser.md) still lists `0x0046f7e0`, `0x0046f7f0`, and `0x0046f800` as `QueryService_NotImpl`, `QueryStatus_NotImpl`, and `TranslateAccelerator_NotImpl`. That method list should be corrected.
- The target does not currently record local PE byte hash, vtable slot table, or exact import evidence for `GetClientRect`.
- The target lacks first-draft C++ despite meeting the current combined score/emitter eligibility gate and having now-resolved method names.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently reports [UID:000330] as `emits` through `auto-generated/NexusTK/browser/Browser.cpp`.
- `auto-generated/NexusTK/browser/Browser.cpp` currently contains only an empty emitter marker for [UID:000330].
- `by-memory/-coverage-report.md` has a supervisor-owned row for [UID:000330] that should be replaced after implementation. Do not edit it from B004 during this report-only pass.

## Ranked Ownership Analysis

### 1. [UID:000013] Browser

- Evidence for:
  - All target function pointers sit in the Browser vtable group at `0x00613830-0x006138b4`.
  - Browser `QueryInterface` support returns interface views matching the target's interface slices.
  - Browser destructor/scalar destructor/setup docs reference the same five Browser interface-view vtables.
  - `BrowserControlPaneOld` constructor allocates a `0x234` byte Browser object, installs five Browser vtable slices, and stores it as the legacy pane's Browser host object.
  - Existing Browser class and file pages clear `85/85` and source-route to `NexusTK/browser/Browser.cpp`.
- Evidence against:
  - Final Browser class declaration/header split is not complete.
  - Direct QueryInterface exposure for DocHost UI/ShowUI slices remains not observed, but those are adjacent support slices and not a blocker for this target's first three interface slices.
- Decision: accepted. Keep `CANONICAL_OWNER:000013` and `EMITTER_UIDS:000013`.

### 2. [UID:0000HV] Browser file as direct owner

- Evidence for:
  - The Browser file root is the generated source path and browser subsystem owner.
  - Browser file owns free helpers and source module grouping.
- Evidence against:
  - `by-structure.md` requires the narrowest semantic owner. These are class virtual methods, not file-level free helpers.
- Decision: reject as canonical owner, keep as source root reached through the Browser class emitter route.

### 3. [UID:000016] BrowserControlPaneOld

- Evidence for:
  - BrowserControlPaneOld allocates/stores the Browser object and uses it in the legacy browser path.
- Evidence against:
  - The vtables, methods, destructor, `QueryInterface`, `Invoke`, and `Navigate` are Browser object methods. The old control pane is a holder/consumer.
- Decision: rejected.

### 4. [UID:00001B] BrowserWindow / [UID:000015] BrowserControlPane

- Evidence for:
  - BrowserWindow and BrowserControlPane have analogous COM stubs and WebBrowser host behavior.
- Evidence against:
  - Their vtables are separate addresses and their analogous methods have separate code ranges. This target's vtable data is Browser-owned.
- Decision: rejected.

### 5. New source file such as `BrowserLegacy.cpp`

- Evidence for:
  - The Browser object, BrowserThread, BrowserControlPaneOld, and BrowserDialogOld are a legacy path and could have lived in a separate legacy source in the original project.
- Evidence against:
  - Current proposed source tree and by-file docs support `NexusTK/browser/Browser.cpp` as the validated source root; no source-path/PDB/map evidence proves a separate `BrowserLegacy.cpp`.
- Decision: plausible future source-tree refinement, but not strong enough to change owner/emitter now.

## Negative Evidence Summary

- Address locality alone was not used as ownership proof. The target is assigned to Browser because of vtable slots, QueryInterface interface views, constructor/destructor vptr stores, and method semantics.
- Direct code-call absence is not negative reachability for COM methods. The method route is vtable dispatch.
- The direct branch hits into `AddRef` and `Release` are not source callers; they are stack-adjusting thunks that should be regenerated by the compiler from multiple-interface inheritance.
- The target should not absorb the adjacent [UID:000332] DocHost/ShowUI stubs because those are after `Browser::Invoke` and use separate vtable slices.
- The target should not be downgraded to compiler-generated/no-code. The adjustors are compiler-generated, but these method bodies are ordinary source-authored COM overrides.
- `GetWindowContext` not filling `ppFrame`, `ppDoc`, or `lpFrameInfo` looks minimal, but it is exact binary behavior and still belongs to the source method body.

## Source Placement / Range / Split Decision

- Range: keep `0x0046f670-0x0046f808` half-open.
- Filename: keep `0x0046f670-0x0046f808.BrowserComStubMethods.md`; a more descriptive title inside the page should say this covers Browser `IOleClientSite`, `IOleInPlaceSite`, and `IDispatch` stub methods. A file rename is optional and not required.
- Split: no split recommended.
- Parent inventory: keep [UID:0000ZF] as parent inventory context only.
- Canonical owner: keep [UID:000013][Browser](by-class/Browser.md).
- Emitter route: keep [UID:000013] so generated C++ flows through [UID:0000HV][Browser](by-file/Browser.md) to `auto-generated/NexusTK/browser/Browser.cpp`.
- Adjacent support:
  - [UID:00033G] and [UID:00033M] stay non-emitting thunk pages.
  - [UID:000331] keeps `Browser::Invoke` and its switch table.
  - [UID:000332] keeps post-Invoke DocHost/ShowUI stubs.

## First-Draft C++ Recommendation

The following is suitable first-draft method-body C++ for [UID:000330] once the Browser class/interface declaration is present or updated in the same implementation pass. It should not include adjustor thunks; the compiler should generate those from the class's multiple COM interface bases.

```cpp
ULONG STDMETHODCALLTYPE Browser::AddRef()
{
    return 2;
}

ULONG STDMETHODCALLTYPE Browser::Release()
{
    return 1;
}

HRESULT STDMETHODCALLTYPE Browser::SaveObject()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetMoniker(DWORD /*dwAssign*/, DWORD /*dwWhichMoniker*/, IMoniker ** /*ppmk*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetContainer(IOleContainer ** /*ppContainer*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::ShowObject()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::OnShowWindow(BOOL /*fShow*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::RequestNewObjectLayout()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetWindow(HWND *phwnd)
{
    *phwnd = m_hWnd;
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::ContextSensitiveHelp(BOOL /*fEnterMode*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::CanInPlaceActivate()
{
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::OnInPlaceActivate()
{
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::OnUIActivate()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetWindowContext(
    IOleInPlaceFrame ** /*ppFrame*/,
    IOleInPlaceUIWindow ** /*ppDoc*/,
    LPRECT lprcPosRect,
    LPRECT lprcClipRect,
    LPOLEINPLACEFRAMEINFO /*lpFrameInfo*/)
{
    ::GetClientRect(m_hWnd, lprcPosRect);
    ::GetClientRect(m_hWnd, lprcClipRect);
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::Scroll(SIZE /*scrollExtent*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::OnUIDeactivate(BOOL /*fUndoable*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::OnInPlaceDeactivate()
{
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::DiscardUndoState()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::DeactivateAndUndo()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::OnPosRectChange(LPCRECT /*lprcPosRect*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetTypeInfoCount(UINT * /*pctinfo*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetTypeInfo(UINT /*iTInfo*/, LCID /*lcid*/, ITypeInfo ** /*ppTInfo*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetIDsOfNames(
    REFIID /*riid*/,
    LPOLESTR * /*rgszNames*/,
    UINT /*cNames*/,
    LCID /*lcid*/,
    DISPID * /*rgDispId*/)
{
    return E_NOTIMPL;
}
```

Implementation notes for C++:

- This code is intentionally ordinary COM source, not decompiler-shaped code.
- `m_hWnd` is Browser base offset `+0x14`; the target's machine code accesses it as adjusted-interface offset `+0x10`.
- `AddRef`/`Release` fixed returns are exact binary behavior and should be preserved unless a broader lifetime pass proves a hidden source macro/policy.
- The `GetWindowContext` source should not invent `ppFrame`, `ppDoc`, or `lpFrameInfo` writes absent from the binary.
- Scores should remain below `95` until Browser's class declaration, interface exposure, fields, and header/source split are final-audit quality.

## Coverage Row Text

Supervisor-owned current row in `by-memory/-coverage-report.md`:

```text
      - [UID:000330][0x0046f670-0x0046f808.BrowserComStubMethods](by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md) 0x0046f670-0x0046f808 | class COM methods | BrowserComStubMethods : reconstructable : 85% : strong : Browser AddRef/Release/not-implemented COM stub methods assigned to [UID:000013][Browser](by-class/Browser.md); source-bearing stubs stay on the Browser child while ABI-only thunks stay non-emitting.
```

Recommended exact replacement row after target/support implementation:

```text
      - [UID:000330][0x0046f670-0x0046f808.BrowserComStubMethods](by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md) 0x0046f670-0x0046f808 | class COM methods | BrowserComStubMethods : reconstructable : 88% : very strong : B004 source-quality pass resolves the Browser COM stub island as IOleClientSite AddRef/Release/SaveObject/GetMoniker/GetContainer/ShowObject/OnShowWindow/RequestNewObjectLayout, IOleInPlaceSite GetWindow/ContextSensitiveHelp/CanInPlaceActivate/OnInPlaceActivate/OnUIActivate/GetWindowContext/Scroll/OnUIDeactivate/OnInPlaceDeactivate/DiscardUndoState/DeactivateAndUndo/OnPosRectChange, and IDispatch GetTypeInfoCount/GetTypeInfo/GetIDsOfNames stubs under [UID:000013][Browser](by-class/Browser.md); local PE bytes and vtable/IAT scans confirm fixed HRESULT returns, m_hWnd/GetClientRect behavior, and that ABI adjustor thunks remain non-emitting.
```

## Target / Support Implementation Checklist

Apply these only after supervisor acceptance and normal lease/validation handling. This report pass did not edit by-* docs.

1. Target [UID:000330] `by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md`
   - Change score from `85/87` to `88/91`.
   - Keep `CANONICAL_OWNER:000013`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000013`.
   - Replace generic `sub_` inventory with the method-name table from this report.
   - Add current-session PE evidence: binary path, image base, MD5/SHA-256, target length/hash, `.text`/`.rdata` mapping, vtable dword refs, no direct branch hits except adjustor thunks for `AddRef`/`Release`, and IAT `0x0060d47c = USER32.dll!GetClientRect`.
   - Add `GetWindow` adjusted-this note: machine offset `+0x10` from `IOleInPlaceSite` view equals Browser base `m_hWnd` at `+0x14`.
   - Add `GetWindowContext` details: fills both position and clipping rectangles using `GetClientRect(m_hWnd, ...)`, ignores `ppFrame`, `ppDoc`, and `lpFrameInfo`, returns `S_OK`.
   - Replace stale final-row wording that implies `0x0046f7e0/0x0046f7f0/0x0046f800` are service/show-UI style stubs. They are `IDispatch` metadata methods.
   - Add the first-draft C++ block above if Browser declaration support is also implemented. If the supervisor chooses not to implement Browser declaration support yet, add a `First-Draft C++ Deferred` note with the exact reason and preserve the C++ in documentation text for the next class-declaration pass.

2. Support [UID:000013] `by-class/Browser.md`
   - Correct method list:
     - replace `0x0046f7e0 QueryService_NotImpl` with `0x0046f7e0 GetIDsOfNames_NotImpl`.
     - replace `0x0046f7f0 QueryStatus_NotImpl` with `0x0046f7f0 GetTypeInfo_NotImpl`.
     - replace `0x0046f800 TranslateAccelerator_NotImpl` with `0x0046f800 GetTypeInfoCount_NotImpl`.
   - Add or update Browser interface-view mapping:
     - `+0x00`: `IOleClientSite`
     - `+0x04`: `IOleInPlaceSite` / inherited `IOleWindow`
     - `+0x08`: `IDispatch` / `DIID_DWebBrowserEvents2` event-sink view
     - `+0x0c`: `IDocHostUIHandler`-shaped
     - `+0x10`: `IDocHostShowUI`-shaped
   - Add note that [UID:000330] now resolves the pre-Invoke stub names and that ABI adjustors remain non-emitting pages.
   - If adding formal C++ support, add or update the Browser class declaration enough for this target's method definitions to be structurally meaningful. Include the caveat that exact DocHost UI/ShowUI QueryInterface exposure remains not observed.

3. Support [UID:00032Z] `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md`
   - Add the exact IID-to-pointer table if not already present:
     - `IUnknown` / `IOleClientSite` -> Browser base `this`.
     - `IOleWindow` / `IOleInPlaceSite` -> `this + 4`.
     - `IDispatch` / `DIID_DWebBrowserEvents2` -> `this + 8`.
   - Add negative evidence that direct `IID_IDocHostUIHandler` and `IID_IDocHostShowUI` returns are not observed in the checked QueryInterface docs, even though vtable slices exist.

4. Support [UID:0001OB] `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
   - Add the target vtable slot map or a compact cross-link to [UID:000330] documenting the resolved slot names.
   - Preserve the mixed-container non-emitting status for the `.rdata` aggregate.

5. Support [UID:00033G] and [UID:00033M] thunk docs
   - No metadata changes recommended.
   - Add cross-link or note only if needed: their Browser `AddRef`/`Release` thunks explain secondary interface calls to [UID:000330], but they remain compiler-generated and non-emitting.

6. Supervisor-owned `by-memory/-coverage-report.md`
   - Replace the current row at line 707 with the exact replacement row in the `Coverage Row Text` section above after target implementation and validation.

7. Generated/autogen expectations
   - After validator refresh, [UID:000330] should still route through `auto-generated/NexusTK/browser/Browser.cpp`.
   - If C++ is inserted, the generated Browser.cpp should no longer show [UID:000330] as only an empty emitter marker. If the Browser declaration is not implemented, generated output may still be structurally incomplete; record that as a Browser class declaration dependency rather than a target behavior blocker.

8. Validation commands expected after implementation
   - Run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [000330-BrowserComStubMethods-source-quality-removed.md](000330-BrowserComStubMethods-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run the QueryInterface/vtable support validators if those support docs are edited. `by-memory/-coverage-report.md` remains supervisor-owned under the active ban.

## Follow-Up Actions

- Supervisor actions:
  - Review/accept or reject this source-quality report.
  - If accepted, send B004 an implementation checklist based on the checklist above.
  - Apply the supervisor-owned `by-memory/-coverage-report.md` row after the B004 implementation callback validates the target/support docs.
- A-agent actions:
  - None required before B004 implementation. Later A-agent class-layout work can refine Browser's full interface declaration and header/source split.
- B004 future research actions:
  - If asked to implement, update [UID:000330] and the listed support docs claim by claim, run scoped validators, and report exact row text for supervisor-owned coverage work.
  - If asked for a follow-up source-tree pass, investigate whether Browser remained in one `Browser.cpp` file or a separate `BrowserLegacy.cpp` file existed. Current evidence is insufficient to move the owner/emitter.

## Confidence

- Recommendation confidence: `91/100`. Ownership, range, and method mapping are strong because local PE bytes, vtable order, import resolution, and existing IDA-backed docs agree.
- Score confidence: recommended `88/91`. Completion rises because the method names, vtable map, field/helper meanings, reachability, and first-draft C++ are now understood. Confidence rises because the current target behavior is simple and directly verifiable. Scores stay below final audit because live IDA MCP was unavailable in this session and the Browser class declaration/source split remains unfinished.
- Remaining uncertainty:
  - Exact original source file split: current best remains `NexusTK/browser/Browser.cpp`; `BrowserLegacy.cpp` remains plausible but unproven.
  - Exact class declaration for DocHost UI/ShowUI exposure: vtables exist, but QueryInterface returns for those IIDs are not currently documented as observed.
  - Exact original comments/macros around fixed `AddRef`/`Release`: binary behavior is fixed returns, but the source lifetime policy name is not proven.
  - `GetWindowContext` source comments are inferred from binary behavior; no original comment explains why `ppFrame`, `ppDoc`, and frame info are ignored.

## Validator Results

- No validator was run because this is a report-only pass and no by-* documentation was edited.
- Current-session local verification commands were read-only Python/PowerShell checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA MCP was checked and unavailable through `http://127.0.0.1:13337/mcp`; existing IDA MCP documentation was used as prior evidence and revalidated where possible against local PE bytes.

## Changed Files

- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\000330-BrowserComStubMethods-source-quality.md`
- Modified:
  - none
- Renamed:
  - none
- Moved to executed:
  - none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/000330-BrowserComStubMethods-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"000330"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000330-BrowserComStubMethods-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/000330-BrowserComStubMethods-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000330"} -->
<!-- {"agent":"B004","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000330-BrowserComStubMethods-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/000330-BrowserComStubMethods-source-quality.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"000330"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
