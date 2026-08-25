*** UID:0000DH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../util/PoolAllocator.h"

class SoundObjectPane : public ObjectPane
{
public:
    struct SoundDescriptor
    {
        int kind;
        unsigned int sampleId;
        int volumeScale;
    };

    struct SoundOrigin
    {
        enum Type
        {
            kObject = 0,
            kMapPosition = 1,
            kNone = 2
        };

        int type;
        union
        {
            ObjectPane *object;
            int mapX;
        };
        int mapY;
    };

    enum PlaybackMode
    {
        kDestroyWithoutPlayback = 0,
        kPlayOnceAndDestroy = 1,
        kPlayOnce = 2,
        kRepeatPlayback = 3,
        kRandomRepeatPlayback = 4
    };

    enum LifetimePolicy
    {
        kPersistent = 0,
        kPlayCount = 1,
        kTimeout = 2
    };

    enum TimerId
    {
        kRepeatTimer = 0,
        kLifetimeTimer = 1
    };

    SoundObjectPane(int mapX,
                    int mapY,
                    const SoundDescriptor &sound,
                    const SoundOrigin &origin,
                    int playbackMode,
                    int repeatDelayMilliseconds,
                    float playProbability,
                    int lifetimePolicy,
                    int lifetimeValue);
    virtual ~SoundObjectPane();

    void StartPlayback();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    SoundDescriptor m_sound;
    SoundOrigin m_origin;
    int m_playbackMode;
    int m_repeatDelayMilliseconds;
    float m_playProbability;
    int m_lifetimePolicy;
    int m_lifetimeValue;
    int m_remainingPlayCount;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SoundObjectPane

## Status

- Confidence: very strong for exact `0x158` layout, typed records/enums, four source methods, TimerHandler callback route, ObjectPane link lifecycle, pool/vtable/compiler boundaries, and source placement.
- Likely source file: [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md)
- Source route: `NexusTK/map/SoundObjectPane.cpp`; old `source-3/simroot_v2/class_SoundObjectPane.cpp` is historical recovery provenance, not current source authority.

## Class Purpose

`SoundObjectPane` is the map-object wrapper for positional or object-linked sound effects. It derives through [UID:00009R][ObjectPane](by-class/ObjectPane.md), stores sound position and trigger parameters, starts playback after construction, and either destroys itself or schedules follow-up triggers depending on its sound mode.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0004PV][0x0053ca20-0x0053cab4.SoundObjectPaneConstructor](by-memory/0x0053ca20-0x0053cab4.SoundObjectPaneConstructor.md) | `0x0053ca20-0x0053cab4`, position 20 | Builds ObjectPane type 11/id 0, copies typed sound/origin records, and initializes mode/delay/probability/policy/value without initializing remaining count. |
| [UID:0004PW][0x0053cac0-0x0053cb48.SoundObjectPaneDestructor](by-memory/0x0053cac0-0x0053cb48.SoundObjectPaneDestructor.md) | `0x0053cac0-0x0053cb48`, position 30 | Clears the typed owner link, removes the pane from active MapPane, and relies on automatic base teardown. |
| [UID:0004PX][0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback](by-memory/0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback.md) | `0x0053cb50-0x0053cc5c`, position 40 | Implements all five playback modes and persistent/count/timeout setup while regenerating the compiler switch table. |
| [UID:0004PY][0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer](by-memory/0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer.md) | `0x0053cc70-0x0053ce3c`, position 50 | Live TimerHandler callback with exact deterministic/random/count/timeout behavior and unconditional handled return. Historical `OnTriggerSound` is rejected. |
| [UID:000387][0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor](by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md) | `0x0053d660-0x0053d739` | Compiler scalar deleting wrapper; semantic relationship retained but no handwritten source emitter. |
| [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md) | `0x00620ae4-0x00620b90`, position 60 | Primary/EventHandler/TimerHandler RTTI-vtable views and adjustors covered by this declaration. |

## Exact Layout And Source Contract

| Offset | Source field | Evidence-backed role |
| --- | --- | --- |
| `+0x000..+0x127` | `ObjectPane` base | Exact `0x128` base, including EventHandler view `+0xa0` and TimerHandler view `+0xa4`. |
| `+0x128/+0x12c/+0x130` | `SoundDescriptor m_sound` | Copied kind, sample id, and volume scale; only sample id and volume are passed to PlaySample. |
| `+0x134/+0x138/+0x13c` | `SoundOrigin m_origin` | Type plus object-pointer/map-X union and map Y; destructor uses object origin to clear the typed owner link. |
| `+0x140` | `m_playbackMode` | Values zero through four select destroy, one-shot, repeat, and random-repeat behavior. |
| `+0x144` | `m_repeatDelayMilliseconds` | Exact repeat reschedule delay; historical probability-at-this-offset wording is superseded. |
| `+0x148` | `m_playProbability` | Random-repeat multiplier used with exact `32767.0f`. |
| `+0x14c` | `m_lifetimePolicy` | Persistent/count/timeout values zero through two. |
| `+0x150` | `m_lifetimeValue` | Count or timeout seconds according to policy. |
| `+0x154` | `m_remainingPlayCount` | Initialized only when repeated counted playback starts. |
| `+0x158` | end of object | Matches static pool block size 344 bytes. |

- Three views at `0x00620ae8`, `0x00620b58`, and `0x00620b88` and adjustors subtracting `0xa0/0xa4` are compiler ABI generated from inheritance. OnTimer liveness is the vtable cell at `0x00620b8c`.
- Source order is pool position `0`, class `10`, constructor `20`, destructor `30`, StartPlayback `40`, OnTimer `50`, class-covered vtable marker `60`, and class-covered threshold literal `70`.
- The two `0xcc` alignment spans, five-entry switch table, vptr stores, EH/cookie paths, scalar delete flags, base teardown sequence, adjustor thunks, RTTI/vtable arrays, and pool-free wrapper are not handwritten source.
- No source null checks guard active MapPane, SoundManager, or TimerMgr; destruction contains no explicit timer cancellation. Unknown selectors return without invented behavior.
- Original enum/member spelling is stripped. These descriptive names are the highest-probability period-appropriate source shape; behavior, layout, types, and placement are resolved.

## Evidence Notes

- Constructor callers are the map packet/object handlers at `0x0050ec30` and `0x00512f20`.
- `StartPlayback` callers at `0x0050edb7` and `0x005132e0` occur immediately after construction paths, matching the class startup contract.
- 2026-06-11 IDA refresh confirms the exact scalar deleting destructor child [UID:000387][0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor](by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md) at `0x0053d660-0x0053d739`, with adjustor refs `0x0053cf78`/`0x0053cf83`, primary vtable ref `0x00620ae8`, map unregister call `0x00506cc0`, base cleanup `0x005373a0`, and SoundObjectPane pool free through `0x004b14c0`.
- 2026-06-12 Batch 279 routes the exact vtable child [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md) to this class. The vtable child records three SoundObjectPane table views at `0x00620ae8`, `0x00620b58`, and `0x00620b88`, constructor/destructor/scalar-destructor vptr refs, and the `0x00620b90` BowGauge string successor boundary.
- Evidence-time generated output omitted the ordinary destructor and class source. The callback installs exact child source and the complete declaration; final waited generated readback is recorded in the implementation report rather than asserted by this page before refresh.

## Cross-References

- [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md)
- [UID:0001DJ][0x0053ca20-0x0053ce3c.SoundObjectPaneCore](by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md)
- [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)
- [UID:000387][0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor](by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md)
- [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)

## Changes

- 2026-07-14 B002 UID0001DJ callback:
  - Raised `85/89 -> 92/94`, set class position `10`, and installed the complete `0x158` ObjectPane-derived declaration with typed records, enums, exact fields, four method declarations, and child insertion.
  - Registered exact children UID0004PV/UID0004PW/UID0004PX/UID0004PY at positions 20/30/40/50; corrected `OnTriggerSound` to `OnTimer` and probability/delay offsets; recorded pool/vtable/threshold order, typed ObjectPane link lifecycle, compiler exclusions, negative evidence, and superseded recovery assumptions.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `88`.
- Evidence: the page documents object-sound role, constructor/destructor/playback/trigger/scalar-destructor ranges, constructor/startup callers, active generated omission, and core owner cross-references; remaining completion gap is source-ready field naming and C++ rewrite detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the documented constructor, non-deleting destructor, playback starter, trigger handler, scalar destructor, and adjustor thunk anchors at `0x0053ca20`, `0x0053cac0`, `0x0053cb50`, `0x0053cc70`, `0x0053d660`, `0x0053cf72`, and `0x0053cf7d`; both class (`84/88`) and parent file (`82/86`) meet the 80/80 gate.
- 2026-06-11 A008 Batch 171: Raised completion/confidence from `84/88` to `85/89` after exact scalar destructor child [UID:000387][0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor](by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md) split and live IDA confirmation of destructor boundary, vtable/adjustor refs, map unregister, base cleanup, and pool-free behavior. Direct parent/file gate now clears `85/85`.
- 2026-06-12 A003 Batch 279: Kept class score at `85/89` and added the exact assigned vtable child [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md). No class score increase because IDA MCP was unavailable for a fresh parent-wide audit during this pass.
