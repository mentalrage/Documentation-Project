*** UID:00008S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MSGHandler.h"
#include "Application.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_APP_MSGHANDLER_H
#define NEXUSTK_APP_MSGHANDLER_H

#include <windows.h>

class MSGHandler
{
public:
    MSGHandler();
    virtual ~MSGHandler();

    virtual LRESULT DispatchMessage(MSG *message);

private:
    MSGHandler *m_previousHandler;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MSGHandler

## UID0003D9 Header Ownership Closure - 2026-08-16

The complete guarded declaration now emits through `app/MSGHandler.h`, while `MSGHandler.cpp` includes that header plus complete `Application.h` before expanding the constructor/destructor/dispatch children. The guard is required because `Application.h` itself consumes `MSGHandler.h`; it prevents the normal source include sequence from redefining the class. This preserves the exact two-slot vtable and `m_previousHandler` layout and lets `Application` inherit a complete secondary base without copying a private message-handler shell into `Application.h`. The prior CPP-local class declaration is retained below as historical staging and is superseded for current generation.

## Summary

`MSGHandler` is a tiny application message-handler swap object. Construction registers the object with `Application::ExchangeMSGHandler`, destruction restores the previous target, and virtual dispatch forwards to the target object's dispatch slot.

Best current class shape:

```cpp
class MSGHandler
{
public:
    MSGHandler();
    virtual ~MSGHandler();

    virtual LRESULT DispatchMessage(MSG *message);

private:
    MSGHandler *m_previousHandler;
};
```

`LRESULT` is the accepted source return type. The independently typed `Application::DispatchMessage(MSG *)` override, 32-bit Win32 message chain, and complete `<windows.h>` header route supersede the older temporary `int` fallback. The field at object slot `+0x4` is best named `m_previousHandler`: the constructor stores the old active Application handler returned by `ExchangeMSGHandler(this)`, and the destructor/scalar deleting destructor restore that saved pointer.

## Likely Original Placement

- Current reconstruction source: [UID:0000LM][MSGHandler](by-file/MSGHandler.md), staged as `NexusTK/app/MSGHandler.cpp`.
- Historical caveat: earlier passes considered private placement beside `Application`; the dedicated method island, class RTTI/vtable, and two independent derived users now reject that as the current source route.
- Confidence: very strong for class identity, exact 8-byte layout, method set, virtual ABI, compiler products, and standalone `app/MSGHandler.cpp/.h` placement.

## Methods

- `0x00528d60-0x00528d7c` constructor - sets vtable and swaps itself into `Application`.
- `0x00528d80-0x00528dc5` destructor - restores the previous handler target.
- `0x00528dd0-0x00528ddc` `LRESULT DispatchMessage(MSG *)` - forwards through target virtual slot 1.
- `0x00528df0-0x00528e55` scalar deleting destructor - compiler wrapper that unregisters and optionally deletes the 8-byte object.
- `0x0061fbf8-0x0061fc00` read-only vtable data - exact two-slot generated table for the `MSGHandler` virtual table.

## Exact Layout And ABI

| Offset / item | Accepted source meaning | Independent evidence |
| --- | --- | --- |
| `+0x0` | `MSGHandler` vptr | Stores at `0x00528d64`, `0x00528da5`, and `0x00528e18`; vtable `0x0061fbf8`. |
| `+0x4` | `MSGHandler *m_previousHandler` | Constructor stores the previous Application handler; destructor and scalar wrapper restore it; generic dispatch loads and calls through it. |
| size `8` | Complete base object size | Scalar deleting wrapper frees 8 bytes; the two pointer-sized fields account for the complete layout. |
| virtual slot 0 | `virtual ~MSGHandler()` compiler deleting wrapper | `0x0061fbf8 -> 0x00528df0`; handwritten source remains the ordinary virtual destructor. |
| virtual slot 1 | `virtual LRESULT DispatchMessage(MSG *message)` | `0x0061fbfc -> 0x00528dd0`; Application override and message loop independently establish `MSG *`/`LRESULT`. |

- RTTI self graph: COL `0x0064c5fc`, CHD `0x006420b8`, one-entry base array `0x006420c8`, self BCD `0x006420d0`, and TypeDescriptor `0x00674644` (`.?AVMSGHandler@@`).
- Application reuse BCD `0x0064209c` gives PMD `{4,-1,0}`. Browser reuse BCD `0x00643364` gives PMD `{0x108,-1,0}`. The independent offsets prove a reusable base class rather than an Application-private helper.
- The Browser bridge at `0x00528de0-0x00528dec` is excluded from the generic method set: it has one Browser caller and no reference from this vtable.

## Evidence

- IDA MCP confirms all four functions and shows constructor/destructor call `Application::ExchangeMSGHandler` at `0x00465650`.
- IDA MCP confirms `??_7MSGHandler@@6B@` at `0x0061fbf8` and xrefs from the constructor/destructor/deleting-destructor vtable writes.
- 2026-06-14 C001 IDA MCP session `b001_0003gy` reconfirmed function sizes `0x1c`, `0x45`, `0x0c`, and `0x65` for `0x00528d60`, `0x00528d80`, `0x00528dd0`, and `0x00528df0`; `0x00528e55` is not a function and remains the class-range exclusive end.
- `analyze_component` reports the shared class vtable `??_7MSGHandler@@6B@` at `0x0061fbf8` as accessed by constructor/destructor/scalar-deleting destructor, with no hidden internal calls among the four methods except the app exchange dependency.
- `xrefs_to 0x00465650` shows the three `Application::ExchangeMSGHandler` call sites at `0x00528d70`, `0x00528db1`, and `0x00528e2b`; `xrefs_to 0x0061fbf8` shows vtable writes/refs at `0x00528d64`, `0x00528da5`, and `0x00528e18`.
- `entity_query(kind=names)` places the class vtable at `0x0061fbf8` between `MonitorCondition` and `MusicControlDialog` read-only data. B006 2026-06-21 narrows the logical `MSGHandler` vtable child to `0x0061fbf8-0x0061fc00`; the adjacent [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md) is `MusicControlDialog` `vftable[-1]` data, not a third `MSGHandler` slot.
- Slot 0 is the MSVC scalar deleting destructor generated from `virtual ~MSGHandler()`. Slot 1 is `DispatchMessage(MSG*)`, supported by the Application message loop calling the active handler vtable slot `+4` with a Win32 `MSG*`.
- Generated source and RTTI prove `Application` embeds `MSGHandler` at `+0x4`; BrowserControlPaneOld embeds the same secondary base at `+0x108`.
- The source-root page [UID:0000LM][MSGHandler](by-file/MSGHandler.md) is now `94/95` and stages under `NexusTK/app/`, so the class parent attachment is valid. The exact executable aggregate [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md) and vtable data [UID:0002GL][0x0061fbf8-0x0061fc00.MSGHandlerVtableData](by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md) provide the current authoritative method/data evidence.

## Reconstruction Gate

Keep `RECONSTRUCTABLE:TRUE` and the parent assignment to [UID:0000LM][MSGHandler](by-file/MSGHandler.md). The related executable aggregate [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md) now clears the active 85/85 code gate, so this class page emits the declaration-level first draft above.

Standalone `MSGHandler.cpp/.h` placement is resolved for reconstruction. The dedicated method island and independent Application/Browser base reuse outweigh proximity to Application-owned dependencies. The generated route keeps `MSGHandler` as a small app helper declaration/header used by `Application` and by the `BrowserControlPaneOld` secondary base.

Compiler products remain covered rather than handwritten: the scalar deleting destructor is generated by `virtual ~MSGHandler()`, and [UID:0002GL][0x0061fbf8-0x0061fc00.MSGHandlerVtableData](by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md) emits only the exact covered-by comment. Padding and the adjacent Music locator emit no MSGHandler source.

## Open Questions

- No source-quality question remains open within this class scope. Exact original spelling cannot be symbol-proven, but `MSGHandler`, `m_previousHandler`, and `LRESULT DispatchMessage(MSG *)` are the highest-probability human-source reconstruction supported by behavior and project style.
- Historical alternatives remain recorded: an Application-private class and `int` return fallback were staging possibilities before the independent RTTI/PMD and Application override evidence. They are not current output options.

## Score Rationale

- Completion `94`: exact layout, complete method set, virtual slots, compiler-product dispositions, standalone CPP/H route, formal source, derived-use PMDs, and cross-owner exclusions are documented and implemented. The final point below 95 remains reserved for supervisor validation/generated readback.
- Confidence `95`: vptr writes, delete size, member accesses, vtable slots, RTTI, and two derived PMDs independently support the same source shape. Remaining archival spelling uncertainty does not justify decompiler labels or a lower behavioral confidence.

## Cross-References

- File: [UID:0000LM][MSGHandler](by-file/MSGHandler.md)
- Caller/module context: [UID:0000HG][Application](by-file/Application.md)
- Related class: [UID:00000D][Application](by-class/Application.md)
- Memory: [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md), [UID:0002GL][0x0061fbf8-0x0061fc00.MSGHandlerVtableData](by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md)
- Neighbor boundary data: [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md)

## Changes

- 2026-08-22 B007 UID0000LM class implementation:
  - Changed `91/93 -> 94/95`; preserved the exact formal CPP/H payloads; made `LRESULT` and standalone `app/MSGHandler.cpp/.h` authoritative; added the 8-byte layout, virtual ABI, complete RTTI/PMD proof, Browser exclusion, compiler-covered dispositions, resolved-question audit, and score rationale.

- 2026-06-21 B009 Rule 26 source-quality incorporation:
  - Before: the declaration was documented in prose but the reconstruction block stayed blank because the standalone-vs-Application-private split was treated as an active code blocker.
  - Changed to: declaration-level first-draft C++ is emitted for `MSGHandler`, including `virtual ~MSGHandler()`, `virtual LRESULT DispatchMessage(MSG *message)`, `MSGHandler *m_previousHandler`, and `[[CHILDREN]]` for the exact method bodies.
  - Summary/evidence: B009 rechecked the executable aggregate, Application message-loop dispatch, Application exchange helper, BrowserControlPaneOld secondary-base use, and vtable-data split. The constructor/destructor/dispatch method bodies now emit on [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md), the scalar deleting destructor/vtable regenerate from this declaration, [UID:0002GR][0x00465650-0x00465686.ApplicationExchangeMSGHandler](by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md) remains Application-owned, and original source-file placement remains historical uncertainty rather than an active blocker.
- Before: the memory cross-reference pointed to an endpoint ending at `0x00528e54`.
- Changed to: the memory cross-reference points to `0x00528d60-0x00528e55`.
- Summary/evidence: 2026-05-28 IDA MCP confirms the scalar deleting destructor includes the `retn 4` operand byte at `0x00528e54`, so the exclusive end is `0x00528e55`.
- Completion/confidence score update: existed before as `0/0`; changed to `70/74`. Summary: the tiny message-handler swap object has purpose, likely placement, method list, and IDA evidence documented, but the original standalone-vs-private declaration remains unresolved. Evidence: constructor/destructor calls to `Application::ExchangeMSGHandler`, forwarding dispatch slot, and corrected memory range.
- 2026-06-03 score and code-gate correction:
  - What existed before: the class was scored `70/74` but already contained final-looking C++ despite being below the project reconstruction-code threshold.
  - Changed to: scores `82/86`; `RECONSTRUCTION_CPP CODE` is empty while the reconstructable flag and parent UID stay in place.
  - Summary/evidence: linked source, executable-range, and vtable pages now document enough class identity, method set, app ownership, and staging evidence for medium-high confidence. Final C++ remains gated by the unresolved standalone-vs-private source split and the active code-entry policy.
- 2026-06-14 C001 refreshed low-confidence batch:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: live IDA MCP reconfirmed all four method boundaries, the exact `0x00528e55` end, the app-exchange call sites, the vtable tail neighbor boundaries, and constructor/destructor/scalar-deleting-destructor vtable references. C++ remains blank because declaration visibility and final source placement still do not clear the `90/90+` code-entry standard.
- 2026-06-21 B006 Rule 26 vtable-data split:
  - Before: the class page still described the read-only data as `0x0061fbf8-0x0061fc04` and left the `MSGHandler+0x4` field/name inference underdeveloped.
  - Changed to: `88/90`, logical vtable data is now [UID:0002GL][0x0061fbf8-0x0061fc00.MSGHandlerVtableData](by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md), and [UID:00040O][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md) carries the successor RTTI locator.
  - Summary/evidence: B006 rechecked recorded bytes, vtable-write xrefs, Application message-loop dispatch through slot `+4`, local exported function sizes, and the `MusicControlDialog` successor boundary. `m_previousHandler` and `DispatchMessage(MSG*)` are now the preferred source names; final C++ stays blank pending original source-placement resolution.
