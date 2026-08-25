*** UID:00005H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FrameMgr::FrameMgr()
{
    m_context.dispatching = false;
    m_context.callbackFrame = 0;
    m_context.currentFrame = 0;
}

void FrameMgr::Insert(FrameHandler *handler, unsigned int dueFrame)
{
    FrameScheduleEntry entry;
    entry.handler = handler;
    entry.dueFrame = dueFrame;

    std::list<FrameScheduleEntry>::iterator position = m_callbacks.begin();
    while (position != m_callbacks.end() &&
           position->dueFrame <= dueFrame) {
        ++position;
    }
    m_callbacks.insert(position, entry);
}

void FrameMgr::RemoveFrame(FrameHandler *handler)
{
    std::list<FrameScheduleEntry>::iterator position = m_callbacks.begin();
    while (position != m_callbacks.end()) {
        if (position->handler == handler)
            position = m_callbacks.erase(position);
        else
            ++position;
    }
}

void FrameMgr::DispatchDueFrameCallbacks(unsigned int currentFrame)
{
    const unsigned int previousFrame = m_context.currentFrame;
    m_context.currentFrame = currentFrame;
    if (previousFrame == currentFrame) {
        m_context.callbackFrame = currentFrame;
        return;
    }

    m_context.dispatching = true;
    while (!m_callbacks.empty() &&
           m_callbacks.front().dueFrame < currentFrame) {
        m_context.callbackFrame = m_callbacks.front().dueFrame;
        FrameHandler *handler = m_callbacks.front().handler;
        m_callbacks.pop_front();
        handler->OnFrameUpdate(&m_context);
    }

    m_context.dispatching = false;
    while (!m_callbacks.empty() &&
           m_callbacks.front().dueFrame == currentFrame) {
        m_context.callbackFrame = m_callbacks.front().dueFrame;
        FrameHandler *handler = m_callbacks.front().handler;
        m_callbacks.pop_front();
        handler->OnFrameUpdate(&m_context);
    }
    m_context.callbackFrame = currentFrame;
}

void FrameMgr::AdvanceCallbackFrame(bool dispatching)
{
    const unsigned int currentFrame = m_context.currentFrame;
    m_context.dispatching = dispatching;
    while (!m_callbacks.empty() &&
           m_callbacks.front().dueFrame <= currentFrame) {
        FrameHandler *handler = m_callbacks.front().handler;
        m_callbacks.pop_front();
        handler->OnFrameUpdate(&m_context);
    }
    ++m_context.callbackFrame;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FrameMgr : public LObject, public Singleton<FrameMgr>
{
public:
    FrameMgr();
    void DispatchDueFrameCallbacks(unsigned int currentFrame);

private:
    friend class FrameHandler;

    void Insert(FrameHandler *handler, unsigned int dueFrame);
    void RemoveFrame(FrameHandler *handler);
    void AdvanceCallbackFrame(bool dispatching);

    FrameUpdateContext m_context;
    std::list<FrameScheduleEntry> m_callbacks;
};

typedef char FrameMgrSizeMustBe24[
    sizeof(FrameMgr) == 0x18 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FrameMgr

## Status

- Confidence: very strong for scheduler class identity, singleton ownership, exact `0x18` layout, method behavior/boundaries, vtable refs, and direct file parent; original private lexical spellings remain inferred.
- Source file parent: [UID:0000JM][FrameMgr](by-file/FrameMgr.md), now assigned after both class and file clear the corrected `85/85` gate.
- Address range: [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- Singleton/global: [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) at `0x0069ae10`
- Vtable data: [UID:0002V3][0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData.md)

## Class Purpose

`FrameMgr` owns the global frame-callback queue exposed through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md). It keeps a circular linked list of scheduled `FrameHandler` entries, inserts callbacks sorted by due frame, removes all entries for a handler, dispatches due callbacks, and clears the singleton on destruction.

The circular-list storage uses shared [UID:0000KR][LinkedList](by-file/LinkedList.md) / `std::list` support helpers. Keep generic node allocation and list cleanup non-emitting; keep frame scheduling policy here.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FrameMgr::FrameMgr` | `0x004b6dc0-0x004b6e63` | Initializes `LObject`, installs `g_frameRegistry`, creates the empty linked list, initializes frame counters, and stores the `FrameMgr` vtable. |
| `Insert` | `0x004b6ea0-0x004b6f0e` | Inserts a `FrameHandler` into due-frame order using shared `LinkedList` node allocation. |
| `RemoveFrame` | `0x004b6f10-0x004b6f56` | Removes every queued entry owned by a handler. |
| `DispatchDueFrameCallbacks` | `0x004b6f60-0x004b703d` | Called from application idle work; advances queue state and dispatches due handler callbacks. |
| `AdvanceCallbackFrame` | `0x004b7040-0x004b70a5` | Retained source-authored drain: applies dispatching state, removes callbacks due through the current frame, invokes them after popping, and increments callbackFrame. The name is provisional because no original symbol or caller survives. |
| `ScalarDeletingDestructor` | `0x004b70c0-0x004b7112` | Destroys the linked list, clears `g_frameRegistry`, restores base state, and optionally deletes. |

## Cross-References

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:0002V3][0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData.md)
- [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)

## Evidence And Assignment Gate

- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md) records the current scheduler aggregate as `94/94` and assigned to [UID:0000JM][FrameMgr](by-file/FrameMgr.md), with live IDA confirmation of all `FrameHandler` and `FrameMgr` function endpoints.
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md) is the direct source root at `94/94`, covering both `FrameHandler` wrappers and `FrameMgr` queue policy under `NexusTK/ui/core/FrameMgr.cpp`.
- IDA-backed evidence ties this class to `g_frameRegistry` construction/clear xrefs, application idle dispatch, broad wrapper callers, `LinkedList` helper use, and the `FrameMgr` vtable base at `0x0061a7ec`.
- Assignment decision: `AUTOGEN_PARENT_UID:0000JM` is justified because this class is the manager half of the scheduler source module and both child and direct parent meet the corrected `85/85` gate.
- Complete formal CPP/H is now installed from the accepted UID0000JM whole-file reconstruction. Field roles and layouts are binary-exact; source-facing private spellings remain inferred and cap confidence without requiring raw labels.

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the scheduler methods at `0x004b6dc0`, `0x004b6ea0`, `0x004b6f10`, `0x004b6f60`, and `0x004b70c0`. Left `AUTOGEN_PARENT_UID` blank because this class is still below the 80 completion gate even though the likely file parent [UID:0000JM][FrameMgr](by-file/FrameMgr.md) is plausible.
- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: global frame queue ownership, circular-list policy, singleton, key methods, and LinkedList boundary are documented with strong confidence; remaining work is deeper structure field naming and final source reconstruction. Evidence: scheduler range `0x004b6cb0-0x004b7112`, `g_frameRegistry`, method table, and LinkedList/FrameHandler references.
- 2026-06-07 Batch 089 class-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000JM`.
  - Summary/evidence: linked the reviewed scheduler aggregate, vtable-data page, singleton/global refs, application idle dispatch evidence, and direct file parent [UID:0000JM][FrameMgr](by-file/FrameMgr.md), which already clears `85/86`. C++ remains blank under the final-source gate.

## 2026-08-24 B001 UID0000JM Accepted Callback

- Raised `85/88 -> 94/94`, preserved owner/emitter UID0000JM and reconstructable state, and assigned contributor position `30`.
- Installed the exact class declaration: direct `LObject` plus `Singleton<FrameMgr>` bases, public constructor and due-dispatch entry point, private friend-backed insert/remove/drain methods, `FrameUpdateContext` at `+0x04` (`0x0c` bytes), and old-Dinkumware `std::list<FrameScheduleEntry>` state at `+0x10` (`0x08` bytes). The size guard requires exact `0x18`.
- Installed all four authored manager bodies. Insert is stable ascending and advances past equal due frames; RemoveFrame erases every matching handler; DispatchDueFrameCallbacks updates currentFrame, drains `< target` while dispatching true, drains `== target` while false, pops before callbacks, and ends with callbackFrame equal to the target; AdvanceCallbackFrame drains `<= currentFrame` then increments callbackFrame.
- No authored destructor is declared or defined. Implicit list, Singleton, and LObject teardown regenerates `[0x004b6e70,0x004b6e93)` ordinary cleanup, `[0x004b70b0,0x004b70bb)` constructor-EH Singleton cleanup, and `[0x004b70c0,0x004b7112)` scalar wrapper with the RTTI/vtable/EH machinery.
- `AdvanceCallbackFrame` is retained despite zero current start xrefs because its complete 45-instruction body is coherent FrameMgr source behavior. Its spelling/access are best-evidence reconstruction and remain the lexical/liveness score cap; no IDA function creation is authorized by this documentation callback.
