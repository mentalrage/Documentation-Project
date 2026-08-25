*** UID:00005G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FrameMgr.h"

FrameHandler::~FrameHandler()
{
    g_frameRegistry->RemoveFrame(this);
}

void FrameHandler::ScheduleNextFrame()
{
    g_frameRegistry->Insert(this, g_frameRegistry->m_context.currentFrame + 1);
}

void FrameHandler::RemoveFrame()
{
    g_frameRegistry->RemoveFrame(this);
}

void FrameHandler::ScheduleFrameCallback(int delayFrames)
{
    g_frameRegistry->Insert(
        this, g_frameRegistry->m_context.callbackFrame + delayFrames);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_FRAMEMGR_H
#define NEXUSTK_UI_CORE_FRAMEMGR_H

#include "../../util/LObject.h"
#include "../../util/Singleton.h"
#include <list>

struct FrameUpdateContext
{
    unsigned int callbackFrame;
    unsigned int currentFrame;
    bool dispatching;
};

class FrameHandler
{
public:
    virtual ~FrameHandler();

    void ScheduleNextFrame();
    void RemoveFrame();

protected:
    void ScheduleFrameCallback(int delayFrames);
    virtual void OnFrameUpdate(const FrameUpdateContext *context) = 0;
};

struct FrameScheduleEntry
{
    FrameHandler *handler;
    unsigned int dueFrame;
};

class FrameMgr;

typedef char FrameUpdateContextSizeMustBe12[
    sizeof(FrameUpdateContext) == 0x0c ? 1 : -1];
typedef char FrameScheduleEntrySizeMustBe8[
    sizeof(FrameScheduleEntry) == 0x08 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FrameHandler

## 2026-08-14 B003 ScreenPane Dependency Closure

- The formal CPP includes `FrameMgr.h` before children; the exact FrameHandler H is now guarded and preserves every method/access declaration.
- This creates the generated declaration route required by ScreenPane's multiple inheritance without changing UID00005G scores (`85/91`) or moving FrameMgr scheduler bodies.

## Status

- Confidence: strong for behavior, class name, direct [UID:0000JM][FrameMgr](by-file/FrameMgr.md) source placement, current wrapper/destructor boundaries, and decorated `FrameHandler` RTTI/vtable data.
- Likely source file: [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- Address range: [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- Scheduler singleton: [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) at `0x0069ae10`
- Vtable data: [UID:0002V3][0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData.md)
- Evidence basis: live IDA MCP `py_eval` on 2026-06-04 against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`).

## Class Purpose

`FrameHandler` is the small base object used by frame-driven classes. Its destructor unregisters the handler from [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md), preventing stale scheduled callbacks after the owner is destroyed.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~FrameHandler` | `0x004b6cb0-0x004b6cf3` | Resets vtable and unregisters from `g_frameRegistry`. |
| `ScheduleNextFrame` | `0x004b6d00-0x004b6d14` | Inserts this handler into `g_frameRegistry` for `currentFrame + 1`; callers span living-object, screen, look, world-map, and weather-style frame users. |
| `RemoveFrame` wrapper | `0x004b6d20-0x004b6d2d` | Removes this handler from `g_frameRegistry`; callers span the same broad frame-driven owner set. |
| `ScheduleFrameCallback` | `0x004b6d30-0x004b6d4c` | Inserts this handler into `g_frameRegistry` at a caller-supplied frame delay; [UID:0004YW][0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate](by-memory/0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate.md) uses delay `50`. The spelling is source-facing inference, not a recovered symbol. |
| `ScalarDeletingDestructor` | `0x004b6d50-0x004b6db3` | Restores `FrameHandler` vtable, unregisters, and optionally frees the handler. |

## Evidence Notes

- IDA labels the destructor address as a Boost exception symbol, but the body calls `g_frameRegistry->RemoveFrame(this)`.
- `ScreenPane` and `WorldMapPane` both embed/use frame-handler state.
- `0x004b6d00` has callers from living-object, screen, look, world-map, and weather-style paths; `0x004b6d20` has frame-handler, world-map, and other frame-driven callers. The wrapper behavior is generic rather than feature-owned.
- 2026-06-04 live IDA confirms `FrameHandler` RTTI at `0x0061a7dc` and vtable base at `0x0061a7e0`, with slots `0x004b6d50` and `__purecall`.
- Vtable stores to `0x0061a7e0` occur in the handler destructor (`0x004b6cd2`), scalar deleting destructor (`0x004b6d75`), `ScreenPane` construction (`0x00556949`), `GroupListPane` construction (`0x0056bb86`/`0x0056bc1a`), and `WorldMapPane` construction (`0x005c2b05`).
- Live decompilation confirms `0x004b6d00` calls `FrameMgr::Insert(g_frameRegistry, this, g_frameRegistry->currentDispatchFrame + 1)`, `0x004b6d20` calls `FrameMgr::RemoveFrame(g_frameRegistry, this)`, and both destructors unregister before returning or freeing.
- 2026-06-16 A002 live IDA MCP refresh on `c001_midiplayer_rdata_20260615` reconfirmed handler destructor `0x004b6cb0` size `0x43`, schedule wrapper `0x004b6d00` size `0x14`, remove wrapper `0x004b6d20` size `0x0d`, delayed schedule wrapper `0x004b6d30` size `0x1c`, scalar deleting destructor `0x004b6d50` size `0x63`, and the surrounding padding before `0x004b6cb0` as one `0xcc` byte.
- Current xrefs prove the destructor and wrappers are generic frame-handler infrastructure: `xrefs_to 0x004b6cb0` reports callers from multiple frame-driven teardown paths, while `xrefs_to 0x0061a7e0` reports vtable stores from the handler destructor, scalar deleting destructor, `ScreenPane`, `GroupListPane`, and `WorldMapPane` construction sites.
- The same pass checked decompilation for `0x004b6d00` and `0x004b6d30`; both forward to `FrameMgr::Insert` through `g_frameRegistry` using next-frame or delayed-frame counters. `callees` confirms wrapper internals call only `FrameMgr::Insert`/`RemoveFrame` plus allocator cleanup in destructors, so no feature-specific owner is hidden inside the wrapper bodies.
- IDA still labels `0x004b6cb0` as a Boost exception destructor. That label remains rejected because the body writes the FrameHandler vtable and unregisters through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md), and decorated RTTI/vtable data identifies the class as `FrameHandler`.

## Blocker Investigation

- Source placement: checked broad wrapper callers, vtable store sites, `g_frameRegistry`, and the direct file page [UID:0000JM][FrameMgr](by-file/FrameMgr.md). The class belongs with `FrameMgr.cpp`, not with any embedding owner, because `ScreenPane`, `GroupListPane`, and `WorldMapPane` only install/use subobjects.
- Name/prototype quality: decorated RTTI proves the class name. Exact lexical wrapper spellings were lost, so the formal declaration uses consistent source-facing names `ScheduleNextFrame`, `RemoveFrame`, and `ScheduleFrameCallback`; retaining raw labels would be lower-quality source. Complete dispatcher and derived-callback evidence proves both the delayed wrapper and pure callback are `void`; the earlier `bool` interpretation is historical and superseded.
- Layout blockers: this pass checked vtable stores in embedding constructors but did not prove every embedding owner's member offset/name. That limits final class declaration quality but no longer blocks 85+ documentation completion for this class.

## Cross-References

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:0002V3][0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData.md)

## Changes

- 2026-07-29 Agent-B001 UID0001HA support callback:
  - Added a complete formal H declaration containing the virtual destructor, next-frame/remove wrappers, protected delayed scheduler, and pure frame-update callback. No handwritten CPP body, scalar-deleting destructor, vtable, RTTI, or registry internals were added.
  - Linked exact [UID:0004YW][0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate](by-memory/0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate.md), whose receiver adjustment proves the FrameHandler subobject and whose final call supplies the exact `50`-frame delayed-scheduler use.
  - Score/owner/emitter remain `85/91`, UID0000JM/UID0000JM. The historical spelling caveat remains evidence provenance, but no longer blocks a realistic source-facing declaration.

- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: base handler role, unregister behavior, schedule/remove wrappers, destructor methods, and generated-name caveats are documented, but the final class name and all owner embeddings are still medium-confidence. Evidence: scheduler range `0x004b6cb0-0x004b7112`, `g_frameRegistry`, caller notes for `0x004b6d00`/`0x004b6d20`, and FrameMgr/ScreenPane cross-references.
- 2026-06-04: Raised from `72/78` to `84/90`.
  - What existed before: the page described the frame-handler behavior but treated the class name as medium-confidence and used stale generated-name caveats.
  - Changed to: documented the current IDA binary identity, decorated `FrameHandler` RTTI/vtable data, exact method endpoints, broad wrapper caller sets, vtable store sites in owner constructors/destructors, and live decompilation of schedule/remove/destructor behavior.
  - Reason for score increase: class identity is now backed by live decorated RTTI/vtable evidence and generic caller behavior rather than caller-biased names; completion remains below final reconstruction because field names and all embedding-owner layouts are not yet source-quality.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JM][FrameMgr](by-file/FrameMgr.md) because the class is `84/90` and the parent is `82/84`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x004b6cb0`, `0x004b6d00`, `0x004b6d20`, and `0x004b6d50`; current `callers` confirms broad frame-driven constructor/destructor and scheduling use.
- 2026-06-16 A002 file-completion support refresh:
  - Before: scores were `84/90`; the class had strong evidence but sat just below the current completion gate used by direct support pages.
  - Changed to: scores `85/91`; parent/emitter remain [UID:0000JM][FrameMgr](by-file/FrameMgr.md).
  - Summary/evidence: live IDA reconfirmed exact destructor/wrapper/scalar-destructor boundaries, generic caller/vtable-store spread, wrapper calls through `g_frameRegistry` into `FrameMgr`, the rejected Boost label, and the remaining source-quality blockers for method spellings, callback prototype, and embedding-owner member names.

## 2026-08-24 B001 UID0000JM Accepted Callback

- Raised `85/91 -> 94/94`, preserved owner/emitter UID0000JM and reconstructable state, and assigned contributor position `0` in the six-part FrameMgr route.
- The formal H now opens the one guarded `FrameMgr.h`, includes `LObject`, `Singleton`, and `std::list` dependencies, defines exact `FrameUpdateContext` (`callbackFrame +0x00`, `currentFrame +0x04`, `dispatching +0x08`, size `0x0c`) and `FrameScheduleEntry` (`handler +0x00`, `dueFrame +0x04`, size `0x08`), declares the virtual destructor and three wrappers, and uses the proven void callback contract.
- The formal CPP now emits the authored destructor plus next-frame, remove, and delayed scheduling wrappers. The destructor unregisters this handler; next-frame uses `currentFrame + 1`; delayed scheduling uses `callbackFrame + delayFrames`; all calls route through `g_frameRegistry` into FrameMgr private methods via friendship.
- Exact bodies remain `[0x004b6cb0,0x004b6cf3)`, `[0x004b6d00,0x004b6d14)`, `[0x004b6d20,0x004b6d2d)`, and `[0x004b6d30,0x004b6d4c)`. The `[0x004b6d50,0x004b6db3)` scalar deleting destructor, RTTI, vtable, EH, cookie, and delete machinery remain compiler-generated and have no handwritten source.
- ScreenPane, GroupListPane/SpelledPane, WorldMapPane, living-object, look, and weather-style users establish generic scheduler ownership. Historical Boost naming and caller-biased ScreenPane/WorldMap aliases remain rejected provenance, not current source identities.
- Final callback reconciliation removed the unattached CPP `[[CHILDREN]]` token. No child contributor is routed beneath UID00005G, so retaining it emitted a generated `[[No Children Attached]]` placeholder rather than authored source; contributor order and all four handwritten bodies are unchanged.

## 2026-07-29 SpelledPane Gate 2B Callback Reconciliation

- Supervisor Gate 2B applied A10 at `[0x0056c300,0x0056c3f1)` as `SpelledPane__OnFrameUpdate` with exact prototype `bool __thiscall(SpelledPane *this, const FrameUpdateContext *context)`.
- A10's applied regular function comment is: SpelledPane FrameHandler callback; decrements positive entry lifetimes, removes expired entries, rebuilds text while restoring scroll, and reschedules after 50 frames.
- Gate 2B declared `FrameUpdateContext` as an incomplete analysis type. It did not infer or add an unsupported layout, and it changed no FrameHandler scheduler/helper prototype, registry data, vtable cell, or dependent function.
- A10 remains `0xf1` bytes with one incoming xref and SHA256 `7A99329BF7E33B18CA4CC60C7EDD365E24BA1A2CC4FB32CE2C5AFDF7D342B68C`. Its surrounding `0xcc` padding and callback/vtable route are unchanged.
- Authoritative saved IDB: session `1da2b2ae`, SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, 143,190,636 bytes, `2026-07-29T13:59:50.138-04:00`; prestate backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B001-UID0001HA-20260729-135636.i64`; catalog entry `0361`. Agent-B001 made no IDA mutation or save.

## 2026-07-29 SpelledPane Shared IDB Currentness Recheck

- `0E0AF938...AB481` is historical and current authoritative session `1da2b2ae` is `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, saved `2026-07-29T14:12:44.7229687-04:00`; `03F102...DBE5DA` and earlier are historical prestates.
- Read-only recheck preserved A10 name/type/comment/hash/xref, incomplete `FrameUpdateContext`, callback vtable route, and unchanged `sub_4B6D30` name/prototype/comments with eight callers. Agent-B001 did not mutate/save IDA.
- Currentness supersession: `3C8F3178...5B69` is historical. Current authoritative session `1da2b2ae` is `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, last write `2026-07-29T14:22:15.9735862-04:00`; FrameHandler/dependency evidence again matched.
- Currentness supersession: `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B` and every earlier identity are now dated history. Current authoritative session `1da2b2ae` is saved SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, last write `2026-07-29T14:42:53.5091352-04:00`; bounded read-only target/dependency readback again found zero UID0001HA drift across exact names, ranges, prototypes, four comment channels, body hashes, xref counts, padding, callback slots, literals, helper identities, and relevant type state. A02/A03 retain exact typed analysis with the same bounded Hex-Rays failures at `0x0056bc15` and `0x0056bc84`. Agent-B001 did not mutate or save IDA.
