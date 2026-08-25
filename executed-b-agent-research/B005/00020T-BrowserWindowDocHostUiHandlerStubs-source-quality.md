** TARGET-REPORT-UID:00020T **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID00020T BrowserWindowDocHostUiHandlerStubs Source Quality Report


Report state: implementation callback applied after supervisor Gate 1 pass for SHA `D5F0111A5084E3A5B11DA42B329DD42A80E63B0FC8B73D2849B8754AFEF6E798`; target/support `by-*` docs were updated in scope, scoped validators ran, leases are clear, and this artifact is ready for supervisor execute review.

Target: [UID:00020T] `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md`

Assigned report path: `tools/leaser/Agents/Agent-B005/research/00020T-BrowserWindowDocHostUiHandlerStubs-source-quality.md`

## Finalized Report / Current Recommendation

UID00020T has been updated from a documented-but-empty BrowserWindow DocHost callback cluster to a source-ready, method-body target:

- Implemented target metadata: `COMPLETION:88`, `CONFIDENCE:92`.
- Preserve `CANONICAL_OWNER:00001B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001B`, blank optional emitter position, and the existing Browser source route through [UID:0000HV].
- Inserted the formal first-draft `RECONSTRUCTION_CPP CODE` block below on the target page during the implementation callback.
- Keep the range as one source-bearing cluster. Do not split into 17 child pages unless a later supervisor specifically requests method-per-page coverage.
- Synced support docs that lacked current method-body, vtable-slot, and QueryInterface detail.

The only remaining source-quality uncertainty is exact class-field spelling for the byte at `this + 0x15`. Current IDA proves the behavior: nonzero leaves scrollbars enabled, zero adds `DOCHOSTUIFLAG_SCROLL_NO`. The recommended first-draft C++ uses descriptive `m_enableScrollBars`; implementation prose should call out that the name is descriptive pending a full BrowserWindow field-layout pass.

## Supporting Research

This is the repaired same-report artifact for UID00020T after supervisor Gate 1 found the previous SHA `B4695467CDAAE9FC8CE858EA86466D3C2C9704C72E53003DD26EF537D0884FC8` under-spec on final-report headings and C++ block shape. The research content below is preserved and reorganized; it is not a rewrite from scratch.

Current lifecycle truth:

- Current state: implementation callback completed for UID00020T after supervisor Gate 1 approval; this report is awaiting supervisor execute review.
- Edited by-* docs: target `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md`, plus support docs `by-class/BrowserWindow.md`, `by-file/Browser.md`, `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`, and `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`.
- Read/check-only docs remained unedited: successor UID00020U, GUID constants UID0003OH, and InlineIsEqualGUID UID000218.
- Scoped validators ran only for the five edited by-* docs, from `source-3/project-documentation`.
- Leases were taken for the five edited by-* docs and released/cleared after the edit/validator batch; `python leaser.py Agent-B005 unlease` reported `Agent-B005: No active leases`.
- No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, registry report command, manual report move, or subagent was used.
- No manual generated-file, coverage-report, supervisor-ledger, validator-state, queue/lock, lifecycle/header/footer, archive, or unrelated-doc edit was made. Generated `Browser.cpp` was refreshed only by the authorized scoped validator path.

Research retained from the first artifact:

- Live IDA MCP session `ef57d27f` supplied the function, xref, decompile, bytes, integer-read, and entity-query facts used by this report.
- Existing target/support docs were checked read-only: UID00020T target, BrowserWindow class, Browser file, BrowserVtablesAndStrings, BrowserWindowCore, and successor UID00020U.
- Old-report search found no dedicated prior UID00020T report; relevant executed reports were used only as supporting context for Browser, BrowserControlPane, InlineIsEqualGUID, and adjacent BrowserWindow ranges.
- Generated output and generated tracker were read-only inputs during Gate 1 research. After implementation, validator command `000000007894` refreshed `auto-generated/NexusTK/browser/Browser.cpp`, which now contains UID00020T method C++ at `88/92`; no manual generated edit was made.

## Target

- Target UID: `00020T`.
- Target path: `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md`.
- Target range: half-open `0x0046a3d0-0x0046a505`.
- Source queue/report row before implementation: `85/91`, combined `88.0`, reconstructable `true`, direct report count `0`.
- Current supervisor classification: Gate 1 passed, implementation callback applied, awaiting supervisor execute review.
- Current direct owner/emitter state: [UID:00001B] `BrowserWindow`, emitted through Browser source route [UID:0000HV].
- Current result: target remains single, is now `88/92`, and contains formal first-draft BrowserWindow DocHost callback method C++.

## Current Target State

Target metadata before implementation:

- `COMPLETION:85`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00001B`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00001B`
- Existing `RECONSTRUCTION_CPP CODE` body is blank.

Documentation state before implementation:

- The target already identifies a BrowserWindow COM host callback cluster with 17 modeled functions.
- It already records one BrowserWindow vtable data xref per stub, no function at `0x0046a505`, and successor `0x0046a510`.
- It leaves C++ blank because older text treated method names, full COM inheritance/header layout, and the byte at `this+0x15` as unresolved.
- Generated output mirrored that blank state with an empty UID00020T emitter marker in `auto-generated/NexusTK/browser/Browser.cpp`.

Current implementation state:

- Target metadata is now `COMPLETION:88`, `CONFIDENCE:92`; owner/emitter/reconstructable metadata is preserved.
- Target formal C++ contains the accepted method-only BrowserWindow `IDocHostUIHandler` / `IDocHostShowUI` bodies.
- Target and support docs include MCP session `ef57d27f` evidence, boundary proof, vtable slot proof, QueryInterface proof, negative evidence, and score rationale.
- Validators have run and passed for every edited by-* doc.
- Generated `auto-generated/NexusTK/browser/Browser.cpp` header shows validator command `000000007894`, refreshed at `2026-07-07T15:07:33-04:00`, and includes UID00020T C++.

## Executive Recommendation

Gate 1 disposition: proceed to implementation after supervisor approval.

The target is not a helper island, not compiler padding, and not generic Browser/OLE support. It is a BrowserWindow COM callback cluster reached only through BrowserWindow vtable entries. Current MCP session `ef57d27f` proves:

- Exact target half-open range `0x0046a3d0-0x0046a505`.
- Exactly 17 functions inside the target.
- No function at `0x0046a505`.
- Successor `sub_46A510` starts at `0x0046a510` and has zero direct xrefs.
- Each target function has exactly one data xref from a BrowserWindow vtable slot.
- BrowserWindow constructor stores the relevant vtable slices at object offsets `+0x0c` and `+0x10`.
- BrowserWindow `QueryInterface` compares `IID_IDocHostUIHandler` (`0x00631630`) and `IID_IDocHostShowUI` (`0x00631640`) and returns adjusted `this + 0x0c` / `this + 0x10` interface views.

Therefore the standard SDK slot names are strong enough for source-facing method names, and the target should emit the exact method-only C++ block. Do not add vtable declarations, GUID declarations, class aggregate declarations, raw `sub_` labels, `IDocHostUIHandler2`, or a generic helper route to this page.

## Supervisor Active Recheck

- Active assignment: UID00020T only.
- Phase: implementation callback complete after supervisor Gate 1 pass; awaiting supervisor execute review.
- Required provenance is present: `TARGET-REPORT-UID:00020T`, `AUTHOR-AGENT-ID:B005`, and `AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh`.
- IDA MCP was mandatory and was used live.
- Current IDA MCP session used for evidence: `ef57d27f`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health` returned `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, `strings_cache_size: 2067`.
- Target/support `by-*` docs were edited only within the callback scope listed in the checklist.
- No manual generated-file, coverage-report, supervisor-ledger, validator-state, queue/lock, lifecycle/header/footer, archive, or unrelated-doc edits were made.
- Scoped validators ran for the five edited by-* docs and are recorded in `Validator Results`.
- No `execute_report`, execute dry-run/probe, lifecycle/archive command, manual report move, registry report command, or subagent was used.

## Inference Research Guidance Check

IDA facts used directly:

- Function starts/sizes from `lookup_funcs` and `entity_query`.
- Stub instruction bodies from `disasm`.
- Key decompiler outputs from `decompile` for `0x0046a400`, `0x0046a420`, and BrowserWindow `QueryInterface` at `0x00469f60`.
- Target bytes, predecessor/jump-table bytes, successor padding bytes, and vtable dwords from `get_bytes` / `get_int`.
- Data xrefs from target methods to vtable slots and GUID xrefs from `xrefs_to`.

Documentation evidence used as support:

- Current target page already records the same basic range, likely slot names, and no-code rationale.
- [UID:00001B] `BrowserWindow` and [UID:0000HV] `Browser` support the owner/emitter route.
- [UID:0001OB] `BrowserVtablesAndStrings` supports the BrowserWindow vtable group.
- [UID:0003OH] `BrowserComGuidConstants` and [UID:000218] `InlineIsEqualGUID` identify `0x00631630` as `IID_IDocHostUIHandler` and `0x00631640` as `IID_IDocHostShowUI`.
- Executed B006 UID000332 and B010 UID0000Z6 reports provide sibling Browser and BrowserControlPane DocHost slot-order precedents.

Inference kept separate:

- `m_enableScrollBars` is a recommended descriptive source field name for the byte at `this + 0x15`; IDA proves the flag behavior but not the original spelling.
- `BrowserWindow::ShowMessage` vs `BrowserWindow::ShowHelp` order is inferred from the standard `IDocHostShowUI` slot order and current vtable dwords after the adjusted IUnknown entries.
- Broader class declaration form remains a class-level follow-up; the method-body target does not need to solve the whole BrowserWindow inheritance/header layout.

Stale Wave2/Wave3 references were not used as authority. Historical notes were treated only as provenance when they matched current IDA or current by-doc evidence.

## Heuristic / Inference Reanalysis And Validation

The main source-quality blockers were rechecked against current IDA facts and current documentation:

| Issue | Reanalysis | Evidence used | Resolution / impact |
|---|---|---|---|
| Raw `sub_46A*` labels | Raw labels are IDA/generated labels only; they are not source-facing names. | Vtable dwords, SDK method order, stack cleanup, QueryInterface exposure. | Replace in prose/source recommendations with `BrowserWindow::IDocHostUIHandler` / `IDocHostShowUI` method names. |
| Interface identity | Older target text says "likely" DocHost UI/ShowUI names. Current QI evidence is stronger. | BrowserWindow QI returns `this+0x0c` for `IID_IDocHostUIHandler` and `this+0x10` for `IID_IDocHostShowUI`; UID0003OH names GUIDs; SDK slot order matches. | Treat method names as source-facing, high-confidence, not merely descriptive. |
| `this+0x15` field name | IDA proves behavior but not original spelling. | `GetHostInfo` decompile checks byte `a1+21`; zero changes flags from `0x10097` to `0x1009f`, adding `DOCHOSTUIFLAG_SCROLL_NO`. | Use descriptive `m_enableScrollBars` in first-draft C++; document unresolved original spelling and cap score below 95. |
| Range/split | One cluster versus 17 children was re-evaluated. | All functions are adjacent, tiny COM callbacks, share vtable/QI evidence, have no normal callers, and are already one UID. | Keep single target; no split child pages for this callback. |
| Source placement | Browser, BrowserWindow, BrowserControlPane, and generic helper placement were considered. | Current xrefs are BrowserWindow vtable slots; Browser and BrowserControlPane have separate analogous ranges; successor helper has zero direct xrefs. | Keep [UID:00001B] BrowserWindow owner/emitter and Browser source route. |
| Formal C++ readiness | Prior target blank C++ rationale was checked against current score/code-entry gate. | Reconstructable TRUE, emitter route present, combined score above 85, exact method bodies and SDK signatures available. | Recommend formal first-draft method-body C++. |
| Generated-output pollution | Before implementation, generated output was an empty marker. | Read-only generated `Browser.cpp` check before implementation; post-validator generated header after callback. | Stale generated baseline was resolved only through scoped validators; do not edit generated file manually. |

Rejected alternatives remain target-specific: Browser UID000332 ownership, BrowserControlPane UID0000Z6 ownership, generic helper ownership, accelerator-helper ownership, `IDocHostUIHandler2`, adjustor thunk classification, padding classification, and child splitting.

## Evidence Standards Used

Evidence ladder applied:

1. Current binary/IDA facts: MCP `lookup_funcs`, `entity_query`, `disasm`, `decompile`, `xrefs_to`, `get_bytes`, and `get_int`.
2. Current target/support by-* documentation: target page, BrowserWindow class, Browser file, BrowserWindowCore, BrowserVtablesAndStrings, successor UID00020U, GUID and InlineIsEqualGUID docs.
3. Generated output and generated tracker as stale-state/source-route confirmation only, not authority.
4. Old executed B reports as searched contextual precedent only, rechecked against current UID00020T MCP where material.
5. SDK header method/flag order for `IDocHostUIHandler`, `IDocHostShowUI`, `DOCHOSTUIINFO`, and `DOCHOSTUIFLAG_*`.

Why the evidence is strong enough:

- The vtable dword reads and one-xref-per-stub results bind every target method to the BrowserWindow vtable.
- BrowserWindow `QueryInterface` directly consumes `IID_IDocHostUIHandler` and `IID_IDocHostShowUI`, making UID00020T stronger than the analogous Browser UID000332 caveat.
- The function bodies are tiny and fully explained by HRESULT returns and simple out-parameter writes.
- Boundary evidence separates predecessor jump-table/data bytes and successor accelerator helper padding.

What prevents stronger confidence:

- The exact original field spelling for `this+0x15` is not proven.
- The full BrowserWindow class/header declaration is broader than this target.
- Generated output is now fresh for UID00020T through scoped validator command `000000007894`; future generated uncertainty is outside this exact callback.

## IDA MCP Facts

Current MCP session summary:

| Fact | Current result |
|---|---|
| `idb_list` | One active session, `ef57d27f`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, backend `worker`, pid/worker pid `7176`. |
| `server_health` | `ok`; module `NexusTK.exe`; imagebase `0x400000`; Hex-Rays ready; strings cache ready; strings cache size `2067`. |
| Target lookup | `0x0046a3d0` through `0x0046a500` are functions; `0x0046a505` is not a function; `0x0046a510` is `sub_46A510`, size `0x107`. |
| Target entity query | `0x0046a3d0-0x0046a505` contains exactly 17 functions, zero names beyond function labels, and zero strings. |
| Predecessor boundary | `sub_46A250` is size `0x14c` and ends at `0x0046a39c`; bytes `0x0046a39c-0x0046a3d0` are jump-table/data bytes ending in `cc cc cc`. |
| Successor boundary | `0x0046a505-0x0046a510` is eleven `cc` bytes; successor `sub_46A510` begins at `0x0046a510`. |
| Vtable base xrefs | `0x00613288` and `0x006132d4` have data refs from `sub_469640` constructor stores at `0x004696cb` and `0x004696d2`, and destructor/vtable reset refs from `0x00469a56` and `0x00469a5d`. |
| QueryInterface evidence | `sub_469F60` compares `0x00631630` and returns `a1 + 12`; compares `0x00631640` and returns `a1 + 16`. |
| GUID xrefs | `0x00631630` has xrefs from BrowserWindow QI `0x0046a049` and BrowserControlPane QI `0x0046c75a`; `0x00631640` has xrefs from BrowserWindow QI `0x0046a063` and BrowserControlPane QI `0x0046c771`. |

Important decompiler facts:

- `sub_46A400`: `*a2 = 0; return -2147467263;` (`E_NOTIMPL`), so `GetExternal` clears `IDispatch **` before returning not implemented.
- `sub_46A420`: sets `*a2 = 20`, `a2[1] = 65687` (`0x10097`), changes `a2[1]` to `65695` (`0x1009f`) if `!*(BYTE *)(a1 + 21)`, and returns `0`.
- `sub_469F60`: returns `this + 0x0c` for `IID_IDocHostUIHandler` and `this + 0x10` for `IID_IDocHostShowUI`, with AddRef through vslot `+4`; unmatched IID returns `E_NOINTERFACE` with nulled output.

Bounded byte checks:

- `get_bytes 0x0046a39c size 52`: predecessor tail/jump table bytes ending `... 06 06 06 05 cc cc cc`.
- `get_bytes 0x0046a3d0 size 309`: exact target body bytes; compact stubs separated by `cc` fill; final bytes at `0x0046a500` are `33 c0 c2 20 00`.
- `get_bytes 0x0046a505 size 11`: all `cc`.
- `get_bytes 0x00613294 size 84`: vtable dwords match the method slots listed below, then the adjacent `IDocHostShowUI` slice.

## Positive Evidence Summary

Direct facts supporting the recommendation:

- Current MCP session `ef57d27f` confirms exactly 17 modeled functions inside `0x0046a3d0-0x0046a505`.
- Each function has exactly one data xref from a BrowserWindow vtable slot; there are no normal code callers to explain these as ordinary helpers.
- BrowserWindow constructor stores vtable slice `0x00613288` at object offset `+0x0c` and vtable slice `0x006132d4` at object offset `+0x10`.
- BrowserWindow `QueryInterface` compares `IID_IDocHostUIHandler` (`0x00631630`) and returns `this+0x0c`; it compares `IID_IDocHostShowUI` (`0x00631640`) and returns `this+0x10`.
- The 15 slots after adjusted IUnknown in the `0x00613288` slice match standard `IDocHostUIHandler` order, and the two target slots in the `0x006132d4` slice match `IDocHostShowUI::ShowMessage` / `ShowHelp`.
- `sub_46A400` and `sub_46A420` decompile to exact, source-shape out-parameter behavior: clear `IDispatch **`, fill `DOCHOSTUIINFO`, and return HRESULTs.
- Predecessor and successor boundaries are clean: predecessor tail data/padding ends before `0x0046a3d0`; eleven `cc` bytes separate target end `0x0046a505` from successor `0x0046a510`.

Corroborating documentation evidence:

- Current UID00020T target already records BrowserWindow ownership, likely DocHost callback role, one vtable xref per stub, and the blank-C++ blocker.
- UID0003OH and UID000218 already identify the relevant DocHost UI/ShowUI GUID constants and BrowserWindow comparison sites.
- Browser UID000332 and BrowserControlPane UID0000Z6 executed reports provide analogous method-order precedent while remaining separate owners/ranges.

Strongest inference chain:

BrowserWindow constructor stores DocHost vtables -> BrowserWindow QI returns those adjusted views for standard DocHost IIDs -> every UID00020T function is referenced only from those slots -> SDK slot order and stack cleanups identify source-facing methods -> small bodies map directly to `S_OK`, `E_NOTIMPL`, `GetExternal`, and `GetHostInfo` C++.

## Function / Child Inventory

The target should stay one child page. The functions are small, adjacent COM callback bodies with common vtable ownership and no independent callers.

| Range | IDA label | Vtable slot | Source-facing method | Behavior | Stack cleanup |
|---|---|---:|---|---|---:|
| `0x0046a3d0-0x0046a3d8` | `sub_46A3D0` | `0x006132a8` | `BrowserWindow::EnableModeless` | `E_NOTIMPL` | `retn 8` |
| `0x0046a3e0-0x0046a3e8` | `sub_46A3E0` | `0x006132cc` | `BrowserWindow::FilterDataObject` | `E_NOTIMPL` | `retn 0x0c` |
| `0x0046a3f0-0x0046a3f8` | `sub_46A3F0` | `0x006132c0` | `BrowserWindow::GetDropTarget` | `E_NOTIMPL` | `retn 0x0c` |
| `0x0046a400-0x0046a415` | `sub_46A400` | `0x006132c4` | `BrowserWindow::GetExternal` | writes `*ppDispatch = 0`, returns `E_NOTIMPL` | `retn 8` |
| `0x0046a420-0x0046a449` | `sub_46A420` | `0x00613298` | `BrowserWindow::GetHostInfo` | writes `cbSize = 0x14`; writes `dwFlags = 0x10097` or `0x1009f`; returns `S_OK` | `retn 8` |
| `0x0046a450-0x0046a458` | `sub_46A450` | `0x006132bc` | `BrowserWindow::GetOptionKeyPath` | `E_NOTIMPL` | `retn 0x0c` |
| `0x0046a460-0x0046a468` | `sub_46A460` | `0x006132a0` | `BrowserWindow::HideUI` | `E_NOTIMPL` | `retn 4` |
| `0x0046a470-0x0046a478` | `sub_46A470` | `0x006132ac` | `BrowserWindow::OnDocWindowActivate` | `E_NOTIMPL` | `retn 8` |
| `0x0046a480-0x0046a488` | `sub_46A480` | `0x006132b0` | `BrowserWindow::OnFrameWindowActivate` | `E_NOTIMPL` | `retn 8` |
| `0x0046a490-0x0046a498` | `sub_46A490` | `0x006132b4` | `BrowserWindow::ResizeBorder` | `E_NOTIMPL` | `retn 0x10` |
| `0x0046a4a0-0x0046a4a5` | `sub_46A4A0` | `0x00613294` | `BrowserWindow::ShowContextMenu` | `S_OK` no-op | `retn 0x14` |
| `0x0046a4b0-0x0046a4b8` | `sub_46A4B0` | `0x0061329c` | `BrowserWindow::ShowUI` | `E_NOTIMPL` | `retn 0x18` |
| `0x0046a4c0-0x0046a4c8` | `sub_46A4C0` | `0x006132b8` | `BrowserWindow::TranslateAccelerator` | `E_NOTIMPL` | `retn 0x10` |
| `0x0046a4d0-0x0046a4d8` | `sub_46A4D0` | `0x006132c8` | `BrowserWindow::TranslateUrl` | `E_NOTIMPL` | `retn 0x10` |
| `0x0046a4e0-0x0046a4e8` | `sub_46A4E0` | `0x006132a4` | `BrowserWindow::UpdateUI` | `E_NOTIMPL` | `retn 4` |
| `0x0046a4f0-0x0046a4f5` | `sub_46A4F0` | `0x006132e4` | `BrowserWindow::ShowHelp` | `S_OK` no-op | `retn 0x20` |
| `0x0046a500-0x0046a505` | `sub_46A500` | `0x006132e0` | `BrowserWindow::ShowMessage` | `S_OK` no-op | `retn 0x20` |

Vtable dwords currently read:

| Slot | Dword |
|---:|---:|
| `0x00613294` | `0x0046a4a0` |
| `0x00613298` | `0x0046a420` |
| `0x0061329c` | `0x0046a4b0` |
| `0x006132a0` | `0x0046a460` |
| `0x006132a4` | `0x0046a4e0` |
| `0x006132a8` | `0x0046a3d0` |
| `0x006132ac` | `0x0046a470` |
| `0x006132b0` | `0x0046a480` |
| `0x006132b4` | `0x0046a490` |
| `0x006132b8` | `0x0046a4c0` |
| `0x006132bc` | `0x0046a450` |
| `0x006132c0` | `0x0046a3f0` |
| `0x006132c4` | `0x0046a400` |
| `0x006132c8` | `0x0046a4d0` |
| `0x006132cc` | `0x0046a3e0` |
| `0x006132e0` | `0x0046a500` |
| `0x006132e4` | `0x0046a4f0` |

## Direct Xref / Caller Inventory

There are no normal code callers. These functions are callback bodies reached through COM interface vtables.

| Target function | Direct xrefs | Current split |
|---:|---|---|
| `0x0046a3d0` | one data xref from `0x006132a8` | `IDocHostUIHandler::EnableModeless` slot |
| `0x0046a3e0` | one data xref from `0x006132cc` | final `IDocHostUIHandler::FilterDataObject` slot |
| `0x0046a3f0` | one data xref from `0x006132c0` | `GetDropTarget` slot |
| `0x0046a400` | one data xref from `0x006132c4` | `GetExternal` slot |
| `0x0046a420` | one data xref from `0x00613298` | `GetHostInfo` slot |
| `0x0046a450` | one data xref from `0x006132bc` | `GetOptionKeyPath` slot |
| `0x0046a460` | one data xref from `0x006132a0` | `HideUI` slot |
| `0x0046a470` | one data xref from `0x006132ac` | `OnDocWindowActivate` slot |
| `0x0046a480` | one data xref from `0x006132b0` | `OnFrameWindowActivate` slot |
| `0x0046a490` | one data xref from `0x006132b4` | `ResizeBorder` slot |
| `0x0046a4a0` | one data xref from `0x00613294` | first `IDocHostUIHandler` method, `ShowContextMenu` |
| `0x0046a4b0` | one data xref from `0x0061329c` | `ShowUI` slot |
| `0x0046a4c0` | one data xref from `0x006132b8` | `TranslateAccelerator` slot |
| `0x0046a4d0` | one data xref from `0x006132c8` | `TranslateUrl` slot |
| `0x0046a4e0` | one data xref from `0x006132a4` | `UpdateUI` slot |
| `0x0046a4f0` | one data xref from `0x006132e4` | second `IDocHostShowUI` method, `ShowHelp` |
| `0x0046a500` | one data xref from `0x006132e0` | first `IDocHostShowUI` method, `ShowMessage` |
| `0x0046a510` | zero direct xrefs | successor helper UID00020U, not part of this target |

Vtable-slice xrefs:

- `0x00613288`: constructor store at `0x004696cb` to `[esi+0x0c]`, destructor/reset store at `0x00469a56`.
- `0x006132d4`: constructor store at `0x004696d2` to `[esi+0x10]`, destructor/reset store at `0x00469a5d`.
- `0x00613294` and `0x006132e0` themselves are method slots, not independent vtable bases, and have no incoming xrefs.

## Documentation Evidence And IDA Status

Current target page status:

- UID00020T already identifies the range as BrowserWindow COM host callback stubs and assigns it to [UID:00001B].
- It already records the 17 function starts, one vtable xref per stub, no function at `0x0046a505`, successor `0x0046a510`, and a blank C++ block.
- It currently keeps C++ blank because method names, class inheritance, and `this + 0x15` field naming were not final. Current evidence resolves method/interface names and supports first-draft method bodies; exact field spelling remains a prose caveat, not a body blocker.

Support doc status:

- `by-class/BrowserWindow.md`: current support already lists UID00020T as BrowserWindow DocHost UI-handler stubs and records the parent gate. It should be expanded with exact `IDocHostUIHandler`/`IDocHostShowUI` slice mapping, `QueryInterface` evidence for `IID_IDocHostUIHandler`/`IID_IDocHostShowUI`, and the `this+0x15` scroll flag caveat.
- `by-file/Browser.md`: current file page distinguishes Browser UID000332 from BrowserWindow UID00020T. It should sync UID00020T as source-ready first-draft method bodies under BrowserWindow, still distinct from Browser and BrowserControlPane.
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`: current vtable page records BrowserWindow vtable slices. It should add the exact UID00020T slot map and the two adjusted slices at `0x00613288` / `0x006132d4`.
- `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`: current core page records `QueryInterface` GUID comparisons and vtable stores. It should clarify that `0x00631630` maps to `this+0x0c`/`IDocHostUIHandler` and `0x00631640` maps to `this+0x10`/`IDocHostShowUI`, feeding UID00020T.
- `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`: read/check only unless implementation finds a contradiction. Current successor boundary and zero-xref retained-helper status already match this report.
- `by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md` and `by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md`: already provide same-or-greater GUID and helper evidence; no edit is required for this callback unless supervisor wants an explicit UID00020T consumer line.

IDA label status:

- IDA still uses raw `sub_46A3D0` through `sub_46A500` labels in the target.
- `entity_query` found zero additional names and zero strings in the target range.
- No IDA DB rename/type/comment edits were made or requested as part of this B005 task.

Generated state:

- Before implementation, `auto-generated/NexusTK/browser/Browser.cpp` contained an empty emitter marker for UID00020T under the BrowserWindow aggregate area.
- After the scoped validators, `Browser.cpp` header shows validator command `000000007894` and refreshed-at `2026-07-07T15:07:33-04:00`, with UID00020T C++ emitted at `88/92`.
- No generated file was edited manually.

## Evidence Checked

Files read:

- `tools/leaser/Agents/Agent-B005/goal.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `references/b-agent-research-and-implementation-workflow.md`
- `references/b-agent-report-template.md`
- `references/score-blocker-audit-standard.md`
- `references/by-structure.md`
- `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md`
- `by-class/BrowserWindow.md`
- `by-file/Browser.md`
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
- `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`
- `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`
- `by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md`
- `by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/NexusTK/browser/Browser.cpp` read-only generated output
- Executed reports listed below under old-report search results
- Windows SDK header `C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um\MsHtmHst.h` for `DOCHOSTUIFLAG_*`, `IDocHostUIHandler`, and `IDocHostShowUI` method order

IDA MCP calls used:

- `idb_list`
- `server_health`
- `lookup_funcs`
- `disasm`
- `decompile`
- `xrefs_to`
- `get_bytes`
- `get_int`
- `entity_query`

One broad `search_text` attempt over the Browser-family range timed out at the shell timeout. It was not required evidence and was not used as a negative result. All required bounded MCP calls succeeded afterward.

## Old Report / Duplicate Search Results

Required search terms were checked before concluding this report: `TARGET-REPORT-UID:00020T`, `00020T`, `BrowserWindowDocHostUiHandlerStubs`, `0x0046a3d0`, `0x0046a505`, `0x0046a510`, `BrowserWindow`, `BrowserWindowCore`, `BrowserVtablesAndStrings`, `IDocHostUIHandler`, `IDocHostShowUI`, `GetHostInfo`, `ShowContextMenu`, `ShowUI`, `GetExternal`, `TranslateAccelerator`, `TranslateUrl`, `EnableModeless`, `FilterDataObject`, `GetDropTarget`, `GetOptionKeyPath`, `HideUI`, `UpdateUI`, `DOCHOSTUIINFO`, and slot addresses `0x00613294` through `0x006132e4`.

Result:

- No existing report with `TARGET-REPORT-UID:00020T` was found.
- No dedicated prior UID00020T executed B-agent report was found.
- Current assignment/notes hits were found in `tools/leaser/Agents/SupervisorAssignments.md`, `tools/leaser/Agents/Supervisor_notes.md`, and `tools/leaser/Agents/Agent-B005/goal.md`.
- Relevant executed reports found and used as context, not as substitutes for current MCP:
  - `executed-b-agent-research/B006/000332-BrowserDocHostShowUiStubs-source-quality.md`: sibling Browser `IDocHostUIHandler` / `IDocHostShowUI` method-order and first-draft C++ precedent.
  - `executed-b-agent-research/B007/000013-Browser-class-source-quality.md`: Browser class/interface declaration precedent and DocHost slice caveat for Browser.
  - `executed-b-agent-research/B010/0000Z6-BrowserControlPaneCore-source-quality.md`: BrowserControlPane COM map proving the same standard DocHost UI/ShowUI GUID and slot pattern.
  - `executed-b-agent-research/B002/000218-InlineIsEqualGUID.md`: identifies BrowserWindow calls at `0x0046a04f` / `0x0046a069` as `IID_IDocHostUIHandler` / `IID_IDocHostShowUI` comparisons.
  - `executed-b-agent-research/B001/00020U-browser-accelerator-source-quality.md`: successor helper context for `0x0046a510`.
  - `executed-b-agent-research/B010/000216-BrowserWindowReleaseAdjustorTailThunks-source-quality.md`: BrowserWindow adjustor thunk context, useful for not misclassifying UID00020T as adjustor glue.
  - `executed-b-agent-research/B009/00020V-00020W-BrowserWindowWndProcClone-source-quality.md` and `executed-b-agent-research/B010/00020W-BrowserRawWindowProcClone-empty-emitter-source-quality.md`: adjacent BrowserWindow source-route context.
  - `executed-b-agent-research/B004/0002T5-g_pActiveBrowserWindow-source-quality.md`: BrowserWindow active global context.

Search conclusion: this is a new B005 UID00020T source-quality report. Existing Browser/BrowserControlPane work is strong supporting evidence, but current UID00020T findings are backed by live MCP session `ef57d27f`.

## Range / Split / Padding / Reclassification Analysis

Keep the range half-open as `0x0046a3d0-0x0046a505`.

Predecessor:

- `sub_46A250` is `0x0046a250` size `0x14c`, ending at `0x0046a39c`.
- `0x0046a39c-0x0046a3d0` is not a function. Bounded bytes show table-like dwords (`75 a2 46 00`, `e6 a2 46 00`, `08 a3 46 00`, etc.) followed by small selector bytes and `cc cc cc`. This belongs with the predecessor core/switch machinery, not UID00020T source.

Target:

- `0x0046a3d0-0x0046a505` contains 17 real function starts and internal `cc` alignment bytes.
- All 17 functions share one source role: BrowserWindow DocHost UI/ShowUI COM callbacks.
- Splitting into 17 pages would duplicate common vtable/QI/SDK evidence and is not needed for source quality. A single target page can list the individual functions and emit method bodies.

Successor:

- `0x0046a505-0x0046a510` is eleven `cc` bytes.
- `0x0046a510` is `sub_46A510`, size `0x107`, successor UID00020U, with zero direct xrefs in the current MCP xref pass.
- UID00020U remains a BrowserWindow accelerator/TranslateMessage helper and should not absorb UID00020T.

Reclassification:

- Reclassify from "likely DocHost stubs, no-code pending final names" to "source-bearing BrowserWindow `IDocHostUIHandler` / `IDocHostShowUI` callback methods with first-draft C++ ready."
- Do not reclassify as compiler-generated adjustor thunk data, raw jump table, generic OLE helper, Browser legacy method cluster, or BrowserControlPane method cluster.

## Ranked Ownership Analysis

Rank 1 accepted/applied owner: [UID:00001B] `BrowserWindow`.

- UID00020T is the direct BrowserWindow DocHost UI/ShowUI callback method cluster. The vtable slices are stored into BrowserWindow object offsets `+0x0c` and `+0x10` by `sub_469640`, with constructor stores at `0x004696cb` and `0x004696d2`.
- BrowserWindow `QueryInterface` consumes `IID_IDocHostUIHandler` (`0x00631630`) and `IID_IDocHostShowUI` (`0x00631640`) and returns the same adjusted object views, `this+0x0c` and `this+0x10`.
- Each target function has exactly one data xref from the BrowserWindow vtable slots `0x00613294-0x006132cc` and `0x006132e0-0x006132e4`; there are no ordinary code callers that would make these reusable helpers.
- The target implementation keeps [UID:00020T] as a single source-bearing child because all 17 tiny methods share the same BrowserWindow vtable/QI proof and SDK method-order evidence.

Rank 2 practical source-root route: [UID:0000HV] `Browser`.

- The Browser file/root page remains the practical source-root route for the broader browser host family and generated output path. This route explains why UID00020T method bodies emit in `auto-generated/NexusTK/browser/Browser.cpp`.
- This is not a competing semantic owner. BrowserWindow remains the direct class owner/emitter for the target; Browser is the file/source-root container while the exact one-file `Browser.cpp` versus possible `BrowserWindow.cpp` source split remains unresolved.
- Browser's own legacy DocHost callback range [UID:000332][0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs](by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md) has separate vtable addresses and separate class evidence, so Browser UID000332 does not own UID00020T.

Rank 3 rejected class/UI owner alternatives: `BrowserControlPane` and other UI owners.

- BrowserControlPane UID0000Z6 has its own newer-pane constructor, `QueryInterface`, vtable addresses, and DocHost callback methods. Those separate slices prove analogy, not ownership transfer.
- Other UI/window owners are weaker because the only target xrefs are BrowserWindow vtable data refs and the target is exposed by BrowserWindow `QueryInterface`, not by a generic pane, Application, or shared UI helper route.

Rank 4 rejected helper/no-owner/successor routes.

- Generic helper ownership is rejected because the functions have no normal callers and are referenced as COM vtable slots only.
- No-owner/non-emitting is rejected because the callback bodies are concrete source-bearing `HRESULT` methods and the owner/emitter route is strong enough to emit first-draft method C++.
- Accelerator-successor ownership is rejected because `0x0046a510` is UID00020U, separated by eleven `cc` bytes, has zero direct xrefs in the current pass, and implements a different BrowserWindow accelerator/TranslateMessage helper.

Rank 5 rejected compiler/data classifications.

- Compiler adjustor-thunk ownership is rejected because UID00020T contains real callback bodies returning `HRESULT` values or filling out parameters. The adjusted IUnknown/Release entries are neighboring vtable slots outside the target bodies.
- Padding/jump-table/data ownership is rejected because IDA models 17 functions inside the target range. Predecessor jump-table/data bytes end before `0x0046a3d0`, and successor padding starts after the half-open target endpoint `0x0046a505`.
- `IDocHostUIHandler2` is rejected because the slot count/order is the base `IDocHostUIHandler` sequence followed by adjacent `IDocHostShowUI::ShowMessage` / `ShowHelp`, with no extension-slot evidence.

## Source Placement

Implemented source placement:

- Class owner: [UID:00001B] `BrowserWindow`.
- Source file/root owner: [UID:0000HV] `Browser`.
- Target emission: [UID:00020T] method bodies in the BrowserWindow area of `auto-generated/NexusTK/browser/Browser.cpp`; post-callback generated output now contains UID00020T C++ after validator command `000000007894`.

Placement rationale:

- UID00020T belongs with BrowserWindow's DocHost UI-handler/source-ready method stubs because BrowserWindow stores and exposes the `IDocHostUIHandler` and `IDocHostShowUI` views, and the target methods are the corresponding SDK-order callbacks.
- The source file/root placement stays under the Browser source route because current project documentation routes BrowserWindow declarations and real methods through the Browser browser-host source root while preserving the unresolved one-file versus split-file browser-folder question.
- UID00020T should emit method bodies only. Vtable data belongs to [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md); GUID constants belong to [UID:0003OH][0x00631580-0x00631660.BrowserComGuidConstants](by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md) / SDK declarations; adjusted Release thunks belong to [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md); successor accelerator logic remains UID00020U.
- The emitted C++ uses `m_enableScrollBars` as a descriptive first-draft name for byte `this+0x15`. The behavior is proven by `GetHostInfo` flags `0x10097` / `0x1009f`, but the original field spelling remains a BrowserWindow field-layout caveat.
- Support docs were synced at report-level detail: `by-class/BrowserWindow.md` records the interface-slice/QI proof, `by-file/Browser.md` records source-root separation from Browser UID000332 and BrowserControlPane UID0000Z6, `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` records the exact slot map, and `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md` records the QI-to-UID00020T mapping.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were requested or made during this assignment.

If a later supervisor-authorized IDA rename/type pass is allowed, the following are safe source-facing recommendations:

| Address | Current IDA label | Recommended source-facing name/type |
|---:|---|---|
| `0x0046a4a0` | `sub_46A4A0` | `BrowserWindow::ShowContextMenu` / `HRESULT STDMETHODCALLTYPE(DWORD, POINT *, IUnknown *, IDispatch *)` |
| `0x0046a420` | `sub_46A420` | `BrowserWindow::GetHostInfo` / `HRESULT STDMETHODCALLTYPE(DOCHOSTUIINFO *)` |
| `0x0046a4b0` | `sub_46A4B0` | `BrowserWindow::ShowUI` |
| `0x0046a460` | `sub_46A460` | `BrowserWindow::HideUI` |
| `0x0046a4e0` | `sub_46A4E0` | `BrowserWindow::UpdateUI` |
| `0x0046a3d0` | `sub_46A3D0` | `BrowserWindow::EnableModeless` |
| `0x0046a470` | `sub_46A470` | `BrowserWindow::OnDocWindowActivate` |
| `0x0046a480` | `sub_46A480` | `BrowserWindow::OnFrameWindowActivate` |
| `0x0046a490` | `sub_46A490` | `BrowserWindow::ResizeBorder` |
| `0x0046a4c0` | `sub_46A4C0` | `BrowserWindow::TranslateAccelerator` |
| `0x0046a450` | `sub_46A450` | `BrowserWindow::GetOptionKeyPath` |
| `0x0046a3f0` | `sub_46A3F0` | `BrowserWindow::GetDropTarget` |
| `0x0046a400` | `sub_46A400` | `BrowserWindow::GetExternal` |
| `0x0046a4d0` | `sub_46A4D0` | `BrowserWindow::TranslateUrl` |
| `0x0046a3e0` | `sub_46A3E0` | `BrowserWindow::FilterDataObject` |
| `0x0046a500` | `sub_46A500` | `BrowserWindow::ShowMessage` |
| `0x0046a4f0` | `sub_46A4F0` | `BrowserWindow::ShowHelp` |

Recommended vtable/comment names:

- `0x00613288`: `BrowserWindow::IDocHostUIHandler_vftable` or equivalent descriptive vtable slice name.
- `0x006132d4`: `BrowserWindow::IDocHostShowUI_vftable` or equivalent descriptive vtable slice name.
- `this + 0x15`: comment as "scrollbars enabled flag used by `GetHostInfo`; zero adds `DOCHOSTUIFLAG_SCROLL_NO`." Do not assert exact original field spelling in IDA.

Rejected IDA/source-facing names:

- Keep raw `sub_46A*` labels only as historical/generated labels, not source names.
- Do not use `IDocHostUIHandler2`; the slot count matches base `IDocHostUIHandler` plus adjacent `IDocHostShowUI`, not the extension interface.
- Do not name `0x0046a510` as part of this DocHost cluster; it is the successor accelerator/TranslateMessage helper.

## Recommended Target Doc Changes

File: `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md`

Apply after supervisor callback:

1. Set metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:92`
   - Preserve `CANONICAL_OWNER:00001B`
   - Preserve `RECONSTRUCTABLE:TRUE`
   - Preserve `EMITTER_UIDS:00001B`
   - Preserve blank optional emitter position unless supervisor gives a placement callback
2. Replace the current no-code rationale with source-ready first-draft method-body rationale while preserving remaining caveat on `this+0x15` field spelling.
3. Insert the exact formal C++ block from `First-Draft C++ Recommendation`.
4. Update item summary with current MCP session `ef57d27f`, exact health state, 17-function inventory, vtable-slot xrefs, BrowserWindow `QueryInterface` proof, boundary/padding proof, and generated-empty baseline.
5. Expand the function table with the exact source-facing method names, vtable slots, return values, stack cleanup, and nontrivial side effects for `GetExternal` and `GetHostInfo`.
6. Add direct negative evidence:
   - no normal code callers;
   - no function at `0x0046a505`;
   - successor `0x0046a510` has zero direct xrefs and is not part of this target;
   - no strings/names in the target beyond function labels;
   - no `IDocHostUIHandler2` slot evidence;
   - no Browser or BrowserControlPane ownership.
7. Add score rationale for `88/92` and why not higher than 92/95.

## Recommended Support Doc Changes

Apply after supervisor callback only where current docs lack same-or-greater detail:

| Support doc | Recommended update |
|---|---|
| `by-class/BrowserWindow.md` | Add exact UID00020T method inventory and COM interface slice proof: object offset `+0x0c` is `IDocHostUIHandler`, object offset `+0x10` is `IDocHostShowUI`, constructor stores vtables at `0x004696cb` / `0x004696d2`, `QueryInterface` returns those views for `IID_IDocHostUIHandler` / `IID_IDocHostShowUI`, and UID00020T now has source-ready first-draft callback bodies. Preserve `this+0x15` field spelling as descriptive only. |
| `by-file/Browser.md` | Sync BrowserWindow support row/paragraph so it says UID00020T is the BrowserWindow DocHost callback cluster with source-ready first-draft methods. Preserve separation from Browser UID000332 and BrowserControlPane UID0000Z6. Do not move declarations or source root. |
| `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` | Add exact BrowserWindow vtable slot map for `0x00613294-0x006132cc` and `0x006132e0-0x006132e4`, with adjusted IUnknown entries at `0x00613288-0x00613290` and `0x006132d4-0x006132dc`. Preserve non-emitting mixed `.rdata` policy. |
| `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md` | Update QueryInterface evidence to explicitly connect `0x00631630` -> `this+0x0c` -> UID00020T `IDocHostUIHandler` methods and `0x00631640` -> `this+0x10` -> UID00020T `IDocHostShowUI` methods. Preserve aggregate no-body policy for the core page. |
| `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md` | Read/check only unless stale boundary language conflicts. Current boundary and zero-xref successor status appears sufficient. |
| `by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md` | No required edit; already names `IID_IDocHostUIHandler` and `IID_IDocHostShowUI` and documents BrowserWindow/BrowserControlPane consumers. Optional cross-link to UID00020T only if supervisor wants a consumer row. |
| `by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md` | No required edit; already records BrowserWindow QI calls at `0x0046a04f` and `0x0046a069` for the two DocHost IIDs. |

## Rejected Alternatives

1. Leave formal C++ blank:
   - Rejected for this report. Current MCP plus SDK evidence resolves method names and bodies enough for first-draft target-range C++. Exact `this+0x15` field spelling remains a caveat but does not block a descriptive first-draft body.
2. Split into 17 child pages:
   - Rejected. All methods are a compact BrowserWindow DocHost callback cluster with shared vtable/QI evidence and no direct callers. A single page can track the inventory cleanly.
3. Move to Browser UID000332:
   - Rejected. Browser owns a separate legacy range and vtable slice. UID00020T xrefs are BrowserWindow vtable slots.
4. Move to BrowserControlPane UID0000Z6:
   - Rejected. BrowserControlPane has separate vtables, QueryInterface body, and source range.
5. Treat as compiler adjustor thunks:
   - Rejected. The functions are concrete callback method bodies returning `HRESULT` values or filling out parameters. Adjusted IUnknown entries are adjacent vtable slots outside the target method bodies.
6. Treat as padding or jump-table data:
   - Rejected. The target contains 17 IDA functions. Padding/jump-table data is outside the target: `0x0046a39c-0x0046a3d0` and `0x0046a505-0x0046a510`.
7. Use `IDocHostUIHandler2`:
   - Rejected. The standard 15 `IDocHostUIHandler` methods appear before the `IDocHostShowUI` slice; there is no extra extension method evidence.
8. Add raw vtable/GUID/class aggregate declarations to UID00020T:
   - Rejected. UID00020T should emit only target-range method bodies. GUIDs belong to UID0003OH / SDK declarations; vtable/read-only data belongs to BrowserVtablesAndStrings; class declarations belong to BrowserWindow class/file support.

## Negative Evidence Summary

Checked and rejected ownership/source alternatives:

- Browser UID000332 does not own UID00020T: Browser has a separate legacy DocHost callback range at `0x0046fb80-0x0046fca5`, separate vtable slots, and a different class target.
- BrowserControlPane UID0000Z6 does not own UID00020T: BrowserControlPane has separate constructor/QI/vtable addresses and its own DocHost callback methods.
- Generic helper/source-file ownership is not supported: all target xrefs are vtable data refs, not ordinary code calls to reusable helpers.
- Accelerator-helper ownership is not supported: successor `0x0046a510` has zero direct xrefs in the current pass and belongs to UID00020U, separated by eleven `cc` bytes.
- Compiler adjustor thunk classification is wrong: target functions implement real HRESULT callback bodies; adjusted IUnknown entries sit in adjacent vtable slots outside this body cluster.
- Padding/data classification is wrong: IDA models 17 functions in the target; padding/data is outside the half-open target at predecessor `0x0046a39c-0x0046a3d0` and successor `0x0046a505-0x0046a510`.
- `IDocHostUIHandler2` is unsupported: current slot count/order is base `IDocHostUIHandler` followed by adjacent `IDocHostShowUI`, with no extension-slot evidence.
- Raw names such as `sub_46A3D0`, generic names like `BrowserWindowDocHostStub`, or raw vtable/GUID declarations are not final source shape. They remain historical/IDA labels only.

Negative checks performed:

- `lookup_funcs` confirms `0x0046a505` is not a function.
- `entity_query` finds zero strings and zero extra names in the target range.
- `xrefs_to 0x0046a510` returns zero direct xrefs, keeping the successor out of scope.
- `xrefs_to` for the 17 target functions returns one data xref each, all from the BrowserWindow vtable slot range, not from caller code.
- Before implementation, generated `Browser.cpp` still had an empty UID00020T marker and could not be used as proof that C++ was implemented; after the scoped validators, command `000000007894` refreshed `Browser.cpp` with UID00020T method bodies.

## First-Draft C++ Recommendation

Implementation inserted this exact formal block into the target page's `RECONSTRUCTION_CPP CODE` field.

Notes:

- The code is limited to UID00020T method bodies.
- It does not emit vtables, GUID constants, class declarations, thunks, padding, or successor helper code.
- `m_enableScrollBars` is a descriptive first-draft name for byte `this+0x15`; prose must preserve that original spelling is not proven.
- Do not add null guards if preserving binary behavior. The binary writes through `info` and `dispatch` directly.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
STDMETHODIMP BrowserWindow::ShowContextMenu(DWORD, POINT *, IUnknown *, IDispatch *)
{
    return S_OK;
}

STDMETHODIMP BrowserWindow::GetHostInfo(DOCHOSTUIINFO *info)
{
    info->cbSize = sizeof(DOCHOSTUIINFO);
    info->dwFlags =
        DOCHOSTUIFLAG_DIALOG |
        DOCHOSTUIFLAG_DISABLE_HELP_MENU |
        DOCHOSTUIFLAG_NO3DBORDER |
        DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE |
        DOCHOSTUIFLAG_FLAT_SCROLLBAR |
        DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION;

    if (!m_enableScrollBars) {
        info->dwFlags |= DOCHOSTUIFLAG_SCROLL_NO;
    }

    return S_OK;
}

STDMETHODIMP BrowserWindow::ShowUI(DWORD, IOleInPlaceActiveObject *,
                                   IOleCommandTarget *, IOleInPlaceFrame *,
                                   IOleInPlaceUIWindow *)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::HideUI()
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::UpdateUI()
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::EnableModeless(BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::OnDocWindowActivate(BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::OnFrameWindowActivate(BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::ResizeBorder(LPCRECT, IOleInPlaceUIWindow *, BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::TranslateAccelerator(LPMSG, const GUID *, DWORD)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::GetOptionKeyPath(LPOLESTR *, DWORD)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::GetDropTarget(IDropTarget *, IDropTarget **)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::GetExternal(IDispatch **dispatch)
{
    *dispatch = 0;
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::TranslateUrl(DWORD, OLECHAR *, OLECHAR **)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::FilterDataObject(IDataObject *, IDataObject **)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::ShowMessage(HWND, LPOLESTR, LPOLESTR, DWORD,
                                        LPOLESTR, DWORD, LRESULT *)
{
    return S_OK;
}

STDMETHODIMP BrowserWindow::ShowHelp(HWND, LPOLESTR, UINT, DWORD, POINT,
                                     IDispatch *)
{
    return S_OK;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

Exact recommended target changes after supervisor Gate 1 approval:

- Keep UID00020T as the single exact target for `0x0046a3d0-0x0046a505`.
- Preserve [UID:00001B] `BrowserWindow` as canonical owner and emitter.
- Update target metadata to `COMPLETION:88` and `CONFIDENCE:92`.
- Replace the blank-C++ rationale with the formal C++ insertion block above.
- Preserve current negative evidence, range/boundary proof, successor separation, and rejected alternatives.
- Do not create split child pages, new UIDs, vtable/GUID declarations, or aggregate class C++ in UID00020T.

Implemented support-doc disposition:

- BrowserWindow class, Browser file, BrowserVtablesAndStrings, and BrowserWindowCore were synced because they lacked current report-level detail.
- Successor UID00020U, UID0003OH, and UID000218 were read/check-only; no contradiction was found, so they are already-present/no-edit.
- Generated `Browser.cpp` refreshed only through scoped validators; generated coverage, manual coverage, manual validator-state edits, and supervisor ledgers were untouched.

Out-of-scope future work:

- Full BrowserWindow class/header declaration finalization.
- Original spelling proof for the byte at `this+0x15`.
- Any IDA DB rename/type/comment changes.

## Score And Metadata Recommendation

Recommended target metadata after accepted implementation:

| Field | Current | Recommended | Reason |
|---|---:|---:|---|
| `COMPLETION` | `85` | `88` | All 17 methods now have exact current function/range evidence, vtable slots, SDK method names, return behavior, boundary proof, and formal first-draft C++ bodies. |
| `CONFIDENCE` | `91` | `92` | Confidence increases because current BrowserWindow `QueryInterface` directly proves `IID_IDocHostUIHandler` and `IID_IDocHostShowUI` exposure, unlike the Browser UID000332 caveat. |
| `CANONICAL_OWNER` | `00001B` | `00001B` | BrowserWindow object/vtable/QI evidence is direct. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Method bodies are source-bearing callback implementations. |
| `EMITTER_UIDS` | `00001B` | `00001B` | BrowserWindow remains the class emitter under Browser source route. |

Why not higher:

- Exact original spelling for the `this+0x15` scrollbars flag is still unresolved.
- Broader BrowserWindow class declaration/header layout is not fully formalized.
- UID00020T should not claim ownership of GUID declarations, vtables, adjustor thunks, or successor accelerator helper code.
- Generated BrowserWindow output is currently empty until implementation and validator refresh.

## Open Questions With Attempted Resolution

| Open question | Evidence checked | Best current resolution | Score/C++ impact |
|---|---|---|---|
| Exact field name for byte `this+0x15` | MCP `decompile/disasm 0x0046a420`; current target/support docs; BrowserWindow class docs; generated output; text searches in current docs for `0x15`, `10097`, `1009f`, scroll flag language. | Behavior is resolved: zero adds `DOCHOSTUIFLAG_SCROLL_NO`; nonzero leaves base flags. Exact original field spelling is not proven. Use descriptive `m_enableScrollBars` in first-draft C++ with a caveat. | Does not block first-draft C++; caps confidence below 95. |
| BrowserWindow class/header layout | MCP constructor stores, QI adjusted returns, vtable dwords; BrowserWindow class/file docs; Browser/BrowswerControlPane precedents. | UID00020T does not need to solve the whole class declaration. It should emit only method bodies; support docs can record that full header layout remains broader class work. | Does not block method C++; prevents aggregate class/header C++ in this target. |
| Generated output freshness | Read-only generated `auto-generated/NexusTK/browser/Browser.cpp`; generated tracker row before implementation; post-validator header after callback. | Generated output was stale before implementation and had an empty UID00020T marker. It changed only through scoped validator refresh; `Browser.cpp` now shows command `000000007894` and contains UID00020T method bodies. | No manual generated edit; generated freshness is now satisfied for UID00020T. |
| Whether to split 17 methods | MCP function/xref inventory; target range; predecessor/successor bytes. | Keep one target: the methods share a common callback cluster and vtable/QI proof. | No split/blocker; avoids child UID creation in this report. |
| Whether `ShowMessage` and `ShowHelp` order is safe | Vtable dwords at `0x006132e0/0x006132e4`; SDK `IDocHostShowUI` order; stack cleanup parity. | Safe high-confidence source-facing order: `0x0046a500` is `ShowMessage`, `0x0046a4f0` is `ShowHelp`. | Supports formal C++; no remaining blocker. |
| Whether Browser UID000332 caveat applies | B006/B007 Browser reports; current BrowserWindow QI decompile/xrefs. | Browser's no-direct-QI caveat does not transfer to BrowserWindow; BrowserWindow directly compares the DocHost UI/ShowUI IIDs. | Raises confidence to 92 rather than keeping old likely-only language. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No B005 manual coverage or tracker edit was required during this callback, and none was made.

If a supervisor-owned manual coverage/tracker summary needs text after implementation, recommended substance is:

```text
[UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md) 0x0046a3d0-0x0046a505 | class COM/UI stubs | BrowserWindowDocHostUiHandlerStubs : reconstructable : 88% : very strong : BrowserWindow IDocHostUIHandler and IDocHostShowUI callback bodies assigned to [UID:00001B][BrowserWindow]; B005 source-quality reanalysis with MCP session ef57d27f maps vtable slice 0x00613288 to the 15 IDocHostUIHandler methods and slice 0x006132d4 to ShowMessage/ShowHelp, verifies BrowserWindow QueryInterface returns those views for IID_IDocHostUIHandler/IID_IDocHostShowUI, verifies GetHostInfo writes cbSize 0x14 and flags 0x10097/0x1009f through the this+0x15 scroll flag, recommends first-draft method C++, and keeps predecessor jump-table bytes, padding, adjustor thunks, vtables, GUID data, and successor accelerator helper non-emitting.
```

Generated tracker/read-only note:

- `auto-generated/-ag-research-tracker.md` currently lists UID00020T at `85/91`, combined `88.0`, reconstructable `true`, direct report count `0`.
- This report does not edit generated tracker files.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|
| C-00020T-01 | UID00020T is exactly `0x0046a3d0-0x0046a505` with 17 functions and no function at `0x0046a505`. | High | MCP `lookup_funcs`, `entity_query`, `get_bytes`; target doc agrees. | Target range/inventory sections | incorporated | applied - target Scope, Evidence, Covered Functions, and Changes now state exact range/17 starts/no function at `0x0046a505`; validator `000000007890` ok. |
| C-00020T-02 | `0x0046a505-0x0046a510` is `cc` padding and successor `0x0046a510` is UID00020U, not part of this target. | High | MCP `get_bytes 0x0046a505 size 11`, `lookup_funcs 0x0046a510`, successor doc. | Target boundary notes; successor read/check | incorporated/read-checked | applied - target Item Summary, Evidence, Negative Evidence, and Changes include eleven `cc` bytes and successor exclusion; UID00020U was read/check-only and already had no-conflict boundary/zero-xref wording. |
| C-00020T-03 | Predecessor bytes `0x0046a39c-0x0046a3d0` are predecessor jump-table/data bytes plus padding, not UID00020T source. | High | MCP `lookup_funcs 0x0046a250`, `get_bytes 0x0046a39c size 52`; BrowserWindowCore doc. | Target range/split; BrowserWindowCore support | incorporated | applied - target Evidence/Changes include predecessor jump-table/padding; BrowserWindowCore QueryInterface support was updated without moving predecessor bytes into UID00020T; validators `000000007890` and `000000007894` ok. |
| C-00020T-04 | Every target function has exactly one data xref from a BrowserWindow vtable slot. | High | MCP `xrefs_to` for all 17 starts. | Target xref inventory; BrowserVtables support | incorporated | applied - target Evidence lists all 17 slot xrefs; BrowserVtablesAndStrings has exact BrowserWindow DocHost/ShowUI slot map; validators `000000007890` and `000000007893` ok. |
| C-00020T-05 | `0x00613288` is the BrowserWindow `IDocHostUIHandler`-shaped vtable slice and `0x006132d4` is the `IDocHostShowUI`-shaped slice. | High | MCP constructor stores at `0x004696cb` / `0x004696d2`, vtable dwords, QueryInterface returns, SDK method order. | Target evidence; BrowserWindow class; BrowserVtables | incorporated | applied - target, BrowserWindow, Browser file, and BrowserVtables support docs now record `+0x0c`/`+0x10`, stores `0x004696cb`/`0x004696d2`, and exact slot map; validators `000000007890`-`000000007893` ok. |
| C-00020T-06 | BrowserWindow `QueryInterface` directly exposes `IID_IDocHostUIHandler` through `this+0x0c` and `IID_IDocHostShowUI` through `this+0x10`. | High | MCP `decompile 0x00469f60`, `xrefs_to 0x00631630/0x00631640`, UID0003OH and UID000218 docs. | BrowserWindowCore; BrowserWindow class; target evidence | incorporated/read-checked | applied - target, BrowserWindow, BrowserWindowCore, Browser file, and BrowserVtables docs now record the QI mapping; UID0003OH/UID000218 were read/check-only and already present for GUID names/call sites. Validators `000000007890`-`000000007894` ok. |
| C-00020T-07 | SDK method order proves the source-facing method names for all 17 stubs. | High | Windows SDK `MsHtmHst.h`, MCP vtable dwords/stack cleanups, B006/B010 precedents. | Target function table; BrowserVtables support | incorporated | applied - target Covered Functions and C++ block use source-facing method names; BrowserVtables has exact slot map; validators `000000007890` and `000000007893` ok. |
| C-00020T-08 | `GetExternal` clears the output dispatch pointer before returning `E_NOTIMPL`. | High | MCP `decompile 0x0046a400`, disasm and vtable slot `0x006132c4`. | Target behavior table; C++ block | incorporated | applied - target Covered Functions, Evidence, Reconstruction Notes, and C++ block include `*dispatch = 0; return E_NOTIMPL;`; validator `000000007890` ok. |
| C-00020T-09 | `GetHostInfo` writes `cbSize = 0x14`, writes `dwFlags = 0x10097`, changes to `0x1009f` when byte `this+0x15` is zero, and returns `S_OK`. | High | MCP `decompile/disasm 0x0046a420`; SDK flag values. | Target behavior table; C++ block; BrowserWindow class field caveat | incorporated | applied - target Covered Functions, Evidence, C++ block, and BrowserWindow support record flags and descriptive `m_enableScrollBars` caveat; validators `000000007890` and `000000007891` ok. |
| C-00020T-10 | First-draft target C++ should be emitted as method bodies only. | Medium-high | C++ eligibility rule, owner/emitter route, current score above 85, exact body evidence. | Target `RECONSTRUCTION_CPP CODE` | incorporated | applied - target formal C++ contains method bodies only; generated Browser.cpp refresh now includes UID00020T method bodies; validator `000000007890` ok and generated refresh header `000000007894`. |
| C-00020T-11 | Target score should become `88/92`, not 95+. | High | Evidence completeness plus remaining field-spelling/class-declaration/generated-refresh caveats. | Target metadata/score rationale; tracker text | incorporated | applied - target metadata is `88/92`, Score Rationale and Changes explain why not higher; validator `000000007890` recorded completion/confidence updates. |
| C-00020T-12 | Browser, BrowserControlPane, generic helper, adjustor thunk, `IDocHostUIHandler2`, split-child, and padding classifications are rejected. | High | Current vtable/QI/xref/range facts; sibling docs. | Target negative evidence; support docs | incorporated/read-checked | applied - target Negative Evidence and Changes preserve rejected alternatives; Browser/BrowserWindow/BrowseVtables support docs preserve separation from Browser UID000332 and BrowserControlPane UID0000Z6; validators ok. |
| C-00020T-13 | Generated `Browser.cpp` had an empty UID00020T marker before implementation and required validator refresh. | High | Read-only generated output check before implementation; post-validator generated check. | Target generated-state note; final implementation notes | incorporated | applied - report now records stale baseline and post-validator refresh; generated `auto-generated/NexusTK/browser/Browser.cpp` header shows command `000000007894` / `2026-07-07T15:07:33-04:00` and contains UID00020T C++ at `88/92`. |

## Validator Results

Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command ID | Timestamp | Exit | Result | Warnings / notes | Generated state |
|---|---:|---|---:|---|---|---|
| `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md` | `000000007890` | `2026-07-07T15:06:58-04:00` | 0 | `ok: 1` | Completion update `88`, confidence update `92`, autogen registry block update, UID link inserts for `000332` and `0000Z6`; no missing-ref warning in output. | `generated_refresh: deferred`; command id/timestamp recorded. |
| `by-class/BrowserWindow.md` | `000000007891` | `2026-07-07T15:07:07-04:00` | 0 | `ok: 1` | Stats row updates only. | `generated_refresh: deferred`; command id/timestamp recorded. |
| `by-file/Browser.md` | `000000007892` | `2026-07-07T15:07:17-04:00` | 0 | `ok: 1` | Existing `missing_ref_uid: 15`, including unsynced references such as `000408`, `00040B`, `0003OH`, `000407`, `000409`, `00040A`, `00040C`; output suppressed five more rows. | `generated_refresh: deferred`; command id/timestamp recorded. |
| `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` | `000000007893` | `2026-07-07T15:07:27-04:00` | 0 | `ok: 1` | Existing `missing_ref_uid: 3` for `000408`, `0003OH`, `000408`. | `generated_refresh: deferred`; command id/timestamp recorded. |
| `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md` | `000000007894` | `2026-07-07T15:07:33-04:00` | 0 | `ok: 1` | Stats incremental noop only. | `generated_refresh: deferred`; final generated `Browser.cpp` header shows command `000000007894`, timestamp `2026-07-07T15:07:33-04:00`, source `deferred-generated-refresh`. |

Generated freshness check:

- `auto-generated/NexusTK/browser/Browser.cpp` was not edited manually.
- After validators, its header reads `validator-command-id: 000000007894`, `validator-refreshed-at: 2026-07-07T15:07:33-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- It now contains `// UID:00020T | by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md | Completion:88 | Confidence:92` followed by the UID00020T BrowserWindow method bodies, including `BrowserWindow::ShowContextMenu`, `BrowserWindow::GetHostInfo`, and descriptive `m_enableScrollBars`.

## Changed Files

Created: none.

Modified:

- `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md`
- `by-class/BrowserWindow.md`
- `by-file/Browser.md`
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
- `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`
- `tools/leaser/Agents/Agent-B005/research/00020T-BrowserWindowDocHostUiHandlerStubs-source-quality.md`

Validator-refreshed generated output:

- `auto-generated/NexusTK/browser/Browser.cpp` refreshed through scoped validator/deferred generated refresh; no manual edit.

Read/check only and not modified:

- `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`
- `by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md`
- `by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md`

Not manually modified:

- No coverage reports.
- No supervisor ledgers.
- No validator state files.
- No queue/lock files.
- No lifecycle/archive files.
- No unrelated docs.

Lease state:

- Lease command succeeded for all five edited by-* docs before edits.
- Explicit per-file unlease after validators returned `Rejected[No active lease]` for each file, and follow-up `python leaser.py Agent-B005 unlease` reported `Agent-B005: No active leases`.

Report execution: not run. No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, registry report command, manual report move, or subagent was run.

## Implementation Tracking Checklist

Every ledger row has been updated to `applied` or `already-present` proof. No row remains `proposed`.

- [x] Supervisor Gate 1 re-reviewed this repaired current report artifact before implementation: passed with SHA `D5F0111A5084E3A5B11DA42B329DD42A80E63B0FC8B73D2849B8754AFEF6E798`.
- [x] Current state is implementation callback complete, not report-only; by-* docs were edited in scope and validators ran.
- [x] Leased all five edited by-* docs immediately before editing; lease tool confirms `Agent-B005: No active leases` after the edit/validator batch.
- [x] Target metadata updated to `COMPLETION:88` and `CONFIDENCE:92`; owner/emitter/reconstructable fields preserved.
- [x] Target item summary and evidence sections include current MCP session `ef57d27f`, health, 17 starts, xrefs, vtable slots, QueryInterface GUIDs, predecessor/successor boundaries, no strings/names, and stale-to-refreshed generated baseline.
- [x] Target function inventory includes all 17 method names, ranges, vtable slots, behaviors, and stack cleanups.
- [x] Target `RECONSTRUCTION_CPP CODE` field contains the exact formal method-body block from this report.
- [x] Target negative evidence rejects Browser ownership, BrowserControlPane ownership, helper ownership, `IDocHostUIHandler2`, split children, padding ownership, raw labels, and successor inclusion.
- [x] `by-class/BrowserWindow.md` updated with exact UID00020T interface-slice/QI/method-body detail.
- [x] `by-file/Browser.md` updated so UID00020T is source-ready while preserving separation from Browser UID000332 and BrowserControlPane UID0000Z6.
- [x] `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` updated with the exact BrowserWindow vtable slot map.
- [x] `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md` updated with the exact DocHost QI-to-UID00020T mapping.
- [x] `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md` read/check-only; no contradiction found, so already-present boundary/zero-xref status stands.
- [x] UID0003OH/UID000218 support read/check-only; DocHost IID names and BrowserWindow QI call sites were already present, so no edit was needed.
- [x] Scoped validators ran only for by-* files actually edited, from `source-3/project-documentation`, using the authorized `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240` shape.
- [x] Validator command IDs, timestamps, exit codes, ok counts, warnings, and generated-refresh state are recorded above.
- [x] Generated `auto-generated/NexusTK/browser/Browser.cpp` freshness rechecked after validators; it refreshed through validator command `000000007894` and was not edited manually.
- [x] All leases clear and this report ledger/checklist has applied/already-present proof before returning `READY_FOR_SUPERVISOR_EXECUTE`.

## Follow-Up Actions

Completed in this callback:

1. Applied target metadata, evidence, and formal C++ changes.
2. Synced only support docs that lacked current detail.
3. Preserved exact source-route separation between BrowserWindow UID00020T, Browser UID000332, and BrowserControlPane UID0000Z6.
4. Kept the `this+0x15` field name as descriptive until a BrowserWindow field-layout/class-header pass proves original spelling.
5. Ran only scoped validators for edited by-* docs.
6. Did not run `execute_report`, lifecycle/archive commands, registry report commands, manual report moves, manual generated edits, coverage edits, manual validator-state edits, supervisor-ledger edits, or subagents.

## Confidence

Recommendation confidence: high.

Score confidence: high for `88/92`.

Remaining uncertainty:

- Exact original BrowserWindow field spelling for byte `this+0x15`.
- Exact final class/header declaration form for BrowserWindow multiple COM interface inheritance.
- Generated output is refreshed by scoped validator command `000000007894`; remaining generated uncertainty is limited to any future non-UID00020T refresh/state outside this callback.

These uncertainties cap the recommendation below 95+ but do not block first-draft target-range method C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000007919","destination_path":"executed-b-agent-research/B005/00020T-BrowserWindowDocHostUiHandlerStubs-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00020T-BrowserWindowDocHostUiHandlerStubs-source-quality.md","timestamp":"2026-07-07T15:31:08-04:00","uid":"00020T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
