*** UID:0000LM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MSGHandler

## Status

- Confidence: very strong for behavior, exact function/rdata anchors, Application exchange dependency, complete reachability, class layout, and the standalone source route.
- Proposed module: `app/MSGHandler.cpp` with `app/MSGHandler.h`. The dedicated method island, independent RTTI/vtable identity, and reuse as an Application and Browser secondary base resolve the former fold-into-Application question in favor of this standalone app module.
- Current generated source: `auto-generated/NexusTK/app/MSGHandler.cpp`
- Primary class doc: [UID:00008S][MSGHandler](by-class/MSGHandler.md)
- Main address doc: [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md)

## File Role

Current source/header route: `app/MSGHandler.cpp` contains the three authored method bodies and compiler-product marker, while `app/MSGHandler.h` owns the complete Win32-visible class declaration consumed by `Application.h` and legacy browser classes. The source includes `MSGHandler.h` and complete `Application.h`; this resolves the former CPP-local declaration without moving the exact method bodies or vtable ownership.

`MSGHandler` is a tiny application message-handler swap object. Construction swaps this handler into the [UID:0000HG][Application](by-file/Application.md), destruction restores the previous handler, and virtual dispatch forwards through the active target object.

This is app infrastructure. Route it as a standalone Application-adjacent helper in `app/MSGHandler.cpp` with a small declaration/header visible to both [UID:00000D][Application](by-class/Application.md) and [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md). The historical possibility that the original source placed this helper textually inside or beside `Application.cpp` is preserved, but current reconstruction should not block code emission on that layout question.

B006 2026-06-21 resolves the source-level names used by this file route: the saved pointer at object slot `+0x4` is best documented as `MSGHandler *m_previousHandler`, and the virtual slot at `0x0061fbfc` is `LRESULT DispatchMessage(MSG *message)`. The current Win32-visible header and the independently typed Application override establish `LRESULT`; the older `int` fallback is retained only as a superseded historical staging assumption.

B009 2026-06-19 clears the active first-draft C++ route: the class declaration emits on [UID:00008S][MSGHandler](by-class/MSGHandler.md), the constructor/destructor/dispatch bodies emit on [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md), the scalar deleting destructor and vtable data remain compiler-generated no-code, and [UID:0002GR][0x00465650-0x00465686.ApplicationExchangeMSGHandler](by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md) remains Application-owned because it exchanges `Application+0x844`.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `MSGHandler` | `0x00528d60-0x00528e55` | RAII-style application message handler swapper and dispatch wrapper. |
| `MSGHandler` read-only data | `0x0061fbf8-0x0061fc00` | Exact two-slot vtable child split from the mixed work-thread/notification `.rdata` span. The adjacent `0x0061fc00-0x0061fc04` dword is [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md), not MSGHandler-owned data. |
| `Application::ExchangeMSGHandler` dependency | `0x00465650-0x00465686` | Application-owned swap of `m_activeMessageHandler` at `Application+0x844`; its three callers are the MSGHandler constructor, destructor, and scalar deleting wrapper. |
| Browser secondary-base bridge | `0x00528de0-0x00528dec` | Browser-owned direct-call bridge through the inherited `MSGHandler::m_previousHandler`; excluded from this file because it has no generic MSGHandler vtable reference. |
| Compiler products | `0x00528df0-0x00528e55`, `0x0061fbf4-0x0061fc00`, and the RTTI graph | Scalar deleting destructor, locator, vtable, COL/CHD/base-array/BCD/TypeDescriptor data regenerated from the class declaration; no handwritten arrays or wrapper body. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Handler swap | `0x00528d60`, `0x00528d80` | Constructor/destructor call `Application::ExchangeMSGHandler` and restore the previous target. |
| Dispatch | `0x00528dd0` | Forwards through target virtual slot 1. |
| Destruction | `0x00528df0` | MSVC scalar deleting destructor wrapper generated from `virtual ~MSGHandler()`; it repeats the restore path and optionally frees storage, but should not be handwritten as a source method. |

## Boundary Notes

- IDA confirms exact starts at `0x00528d60`, `0x00528d80`, `0x00528dd0`, and `0x00528df0`.
- Constructor/destructor xrefs include application and browser/OLE message handling paths, but the object itself belongs to application dispatch infrastructure.
- `list missing-ref --class MSGHandler` returns zero entries.
- IDA MCP confirms `??_7MSGHandler@@6B@` at `0x0061fbf8`, with constructor/destructor/deleting-destructor xrefs from the executable `MSGHandler` range.
- 2026-06-14 C001 IDA MCP session `b001_0003gy` reconfirmed the current function table: `0x00528d60` size `0x1c`, `0x00528d80` size `0x45`, `0x00528dd0` size `0x0c`, and `0x00528df0` size `0x65`; `0x00528e55` is not a function and remains the exclusive end before padding/successor data.
- The same session shows the three app-exchange calls to `0x00465650` from `0x00528d70`, `0x00528db1`, and `0x00528e2b`, and the three `??_7MSGHandler@@6B@` references from the constructor, destructor, and scalar deleting destructor at `0x00528d64`, `0x00528da5`, and `0x00528e18`.
- IDA `entity_query(kind=names)` over `0x0061fbf0-0x0061fc10` places `??_7MSGHandler@@6B@` exactly between `MonitorCondition` read-only data at `0x0061fbf0` and `MusicControlDialog` read-only data at `0x0061fc04`, supporting the narrow rdata split used by [UID:0002GL][0x0061fbf8-0x0061fc00.MSGHandlerVtableData](by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md).
- B006 split the former physical boundary dword at `0x0061fc00` into [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md). That dword points to `??_R4MusicControlDialog@@6B@`, has no expected direct xrefs, and should route through [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md).
- 2026-06-16 A001 live IDA MCP reconfirmed the current function table: `0x00528d60` size `0x1c`, `0x00528d80` size `0x45`, `0x00528dd0` size `0x0c`, browser-owned bridge `0x00528de0` size `0x0c`, scalar deleting destructor `0x00528df0` size `0x65`, no function at `0x00528e55`, and the successor `MusicControlDialog` function at `0x00528e60`.
- The same refresh reconfirmed constructor xrefs from `0x00463380` and `0x0046ff93`, destructor xrefs from application/browser cleanup paths, three `Application::ExchangeMSGHandler` calls at `0x00528d70`, `0x00528db1`, and `0x00528e2b`, and `??_7MSGHandler@@6B@` writes from constructor/destructor/scalar deleting destructor at `0x00528d64`, `0x00528da5`, and `0x00528e18`.
- `analyze_component` over the four MSGHandler methods found no internal calls among them, shared only the vtable at `0x0061fbf8` plus the security cookie for destructor wrappers, and kept the unresolved source split as a declaration/placement question rather than a behavior or reachability blocker.
- `make_signature_for_range 0x00528e55-0x00528e60` reconfirmed eleven `0xcc` bytes before the successor function, preserving the exact exclusive end.

## Complete File Inventory And Source Order

| Source/binary order | Range or item | Authored-source disposition |
| ---: | --- | --- |
| 1 | `0x00528d60-0x00528d7c` | `MSGHandler::MSGHandler()`; installs `this` and saves the previous active handler. |
| 2 | `0x00528d80-0x00528dc5` | `MSGHandler::~MSGHandler()`; restores `m_previousHandler`. |
| 3 | `0x00528dd0-0x00528ddc` | `LRESULT MSGHandler::DispatchMessage(MSG *)`; tail-forwards the unchanged message to the saved handler. |
| excluded | `0x00528de0-0x00528dec` | BrowserControlPaneOld-owned bridge, not an authored MSGHandler definition. |
| compiler-covered | `0x00528df0-0x00528e55` | MSVC scalar deleting destructor generated from `virtual ~MSGHandler()`. |
| compiler-covered | `0x0061fbf4-0x0061fc00` and RTTI records | Locator/vtable/RTTI generated from the class declaration. [UID:0002GL][0x0061fbf8-0x0061fc00.MSGHandlerVtableData](by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md) emits only its formal covered-by comment. |

- Exact `0xCC` gaps are `0x00528d51-0x00528d60`, `0x00528d7c-0x00528d80`, `0x00528dc5-0x00528dd0`, `0x00528ddc-0x00528de0`, `0x00528dec-0x00528df0`, and `0x00528e55-0x00528e60`; none emits source.
- The RTTI graph is COL `0x0064c5fc-0x0064c610`, CHD `0x006420b8-0x006420c8`, one-entry base array `0x006420c8-0x006420cc`, self BCD `0x006420d0-0x006420ec`, and TypeDescriptor `0x00674644-0x00674660` (`.?AVMSGHandler@@`). Application reuse BCD `0x0064209c` has PMD `{4,-1,0}`; Browser reuse BCD `0x00643364` has PMD `{0x108,-1,0}`.
- Complete searches found no file-owned global, static, string, resource, import wrapper, table, or undisposed executable byte beyond this inventory. The Application exchange method/field/lock, Browser bridge, and Music successor remain with their direct owners.

## Reachability And Interaction Evidence

| Target | Complete direct evidence |
| --- | --- |
| constructor `0x00528d60` | Calls from `0x00463380` and `0x0046ff93`; calls `Application::ExchangeMSGHandler` at `0x00528d70`. |
| destructor `0x00528d80` | Calls from `0x004639ac`, `0x0046726f`, `0x0046f209`, `0x0047051c`, `0x005fa5e2`, and `0x005faf51`; calls the exchange helper at `0x00528db1`. |
| dispatch `0x00528dd0` | Vtable data reference from `0x0061fbfc`; indirect tail call through `m_previousHandler` slot `+4`. |
| Browser bridge `0x00528de0` | Sole code caller `0x0046f36d`; no generic vtable reference. |
| scalar wrapper `0x00528df0` | Vtable data reference from `0x0061fbf8`; calls the exchange helper at `0x00528e2b` and conditionally frees the 8-byte object. |
| vtable `0x0061fbf8` | Writes at `0x00528d64`, `0x00528da5`, and `0x00528e18`; slots point to `0x00528df0` and `0x00528dd0`. |

## Historical And Rejected Assumptions

- Stale Wave2/Wave3 labels and workflow conclusions are non-authoritative. Current documentation, live IDA evidence, and validator routing govern this page.
- Folding the helper into `Application.cpp` is rejected: Application embeds the base at `+0x4`, but Browser independently embeds it at `+0x108`, and MSGHandler has its own RTTI/vtable and method island.
- Folding it into Browser source is rejected: only `0x00528de0` is Browser-owned; the generic class is reused by Application.
- Handwriting the scalar deleting destructor, vtable, or RTTI arrays is rejected because those are compiler products of the ordinary destructor and virtual class declaration.
- The former `int` return fallback and uncertain file split remain historical staging notes, not current source blockers.

## Score Rationale

- `94/95` records complete whole-file inventory, exact ranges and padding, complete direct caller/xref sets, 8-byte class layout, independent Application/Browser PMDs, resolved standalone placement, formal CPP/H routing, and the compiler-covered vtable repair. Completion remains below 95 until supervisor validation and generated readback complete the accepted callback.
- Confidence is 95 because binary relationships and source routing converge independently. Original identifier/include spelling cannot be recovered literally, but the selected names and source shape are the strongest human-source reconstruction and no raw IDA labels remain in formal code.

## Cross-References

- [UID:00008S][MSGHandler](by-class/MSGHandler.md)
- [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md)
- [UID:0002GL][0x0061fbf8-0x0061fc00.MSGHandlerVtableData](by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md)
- [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- 2026-08-22 B007 UID0000LM accepted-report implementation:
  - Changed `88/89 -> 94/95`, resolved standalone `app/MSGHandler.cpp/.h` placement, made `LRESULT DispatchMessage(MSG *)` authoritative, and incorporated the complete authored/compiler/excluded inventory, exact gaps, RTTI graph, PMDs, reachability, negative evidence, and rejected alternatives.
  - Formal source remains owned by [UID:00008S][MSGHandler](by-class/MSGHandler.md) and [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md); [UID:0002GL][0x0061fbf8-0x0061fc00.MSGHandlerVtableData](by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md) supplies the compiler-covered child marker, while Application, Browser, and Music support ranges retain their direct owners.

- 2026-06-21 B009 Rule 26 source-quality incorporation:
  - Before: this file route still allowed `Application.cpp` private placement to act as a practical code-emission blocker.
  - Changed to: `app/MSGHandler.cpp` is the current reconstruction route, with a declaration/header visible to `Application` and `BrowserControlPaneOld`; original textual placement remains a historical caveat only.
  - Summary/evidence: B009 reviewed the executable aggregate, class page, Application exchange helper, BrowserControlPaneOld bridge, and narrowed vtable-data child. It confirms `m_previousHandler` at `+0x4`, `DispatchMessage(MSG*)`, Application ownership of the active-handler exchange at `Application+0x844`, no-code scalar deleting destructor/vtable handling, and no Browser ownership move for the generic helper.
- Before: the main address doc ended at `0x00528e54`.
- Changed to: the main address doc ends at `0x00528e55`.
- Summary/evidence: 2026-05-28 IDA MCP shows the scalar deleting destructor's `retn 4` operand ends at `0x00528e55`; padding begins at `0x00528e55`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: application message-handler swap behavior, method families, exact starts, Application boundary, zero missing refs, and range correction are documented; confidence is capped by whether the tiny helper was standalone or private to `Application.cpp`.
- 2026-06-14 C001 refreshed low-confidence batch:
  - Before: `COMPLETION:84`, `CONFIDENCE:82`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP reconfirmed all four executable method bodies, the exclusive `0x00528e55` end, the vtable tail boundaries, three app-exchange calls, and constructor/destructor/scalar-deleting-destructor vtable writes. The score stays below final-audit quality because the standalone `MSGHandler.cpp` versus private `Application` helper split remains unresolved.
- 2026-06-16 A001 file-confidence refresh:
  - Before: `86/85`, with current function and vtable evidence but no file-root refresh of constructor/destructor reachability or the browser bridge/source-split blocker.
  - Changed to: `87/86`.
  - Summary/evidence: live IDA MCP reconfirmed all MSGHandler function sizes, the adjacent browser-owned bridge, the exact `0x00528e55` end and padding, constructor/destructor callers, three `Application::ExchangeMSGHandler` call sites, vtable writes, and the `MonitorCondition`/`MusicControlDialog` rdata neighbors. The original standalone-versus-private `Application` source placement remains unresolved because evidence proves app ownership but not declaration/file layout.
- 2026-06-21 B006 Rule 26 vtable-data split:
  - Before: the file page still described `0x0061fbf8-0x0061fc04` as a single MSGHandler read-only-data span.
  - Changed to: `88/89`, with `MSGHandler` owned read-only data narrowed to `0x0061fbf8-0x0061fc00` and the successor [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md) routed to [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md).
  - Summary/evidence: B006 rechecked the recorded vtable bytes, Application slot-`+4` dispatch of `MSG*`, scalar-deleting-destructor role, `m_previousHandler` field inference, and exact RTTI-boundary precedent. `MSGHandler.cpp` remains the current reconstruction route, with only standalone-versus-Application-private placement unresolved.
