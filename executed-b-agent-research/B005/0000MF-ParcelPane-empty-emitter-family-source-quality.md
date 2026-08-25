# 0000MF ParcelPane Empty-Emitter Family Source-Quality Report
** TARGET-REPORT-UID:0000MF **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: malformed TARGET-REPORT-UID header **

**TARGET-REPORT-UID:** 0000MF  
**ASSIGNMENT:** Report-first research for `by-file/ParcelPane.md` empty-emitter family; accepted implementation callback applied 2026-06-30.  
**IMPLEMENTATION CALLBACK STATUS:** Accepted target/support by-* details applied. Scoped validators passed. Generated `ParcelPane.cpp` inspected fresh at validator command `000000002089` with `0` remaining `Empty Emitter Marker` hits.  
**MCP STATUS:** Available and used. Active database `supervisor_resume_20260629`.

## Final Recommendation

Implement the complete current `ParcelPane.cpp` empty-emitter family in one bounded callback. The current generated output has 18 empty markers. Eight are source function/global rows and should receive source-facing formal insertion text. The remaining ten are class/type/vtable/scalar-wrapper/exact-storage rows and should receive explicit comment-only no-code markers with target-specific proof so they stop emitting empty placeholders without inventing handwritten source for compiler-generated or duplicate artifacts.

Primary source owner stays `by-file/ParcelPane.md` (`NexusTK/ui/panels/ParcelPane.cpp`). Existing method children already cover the constructor, painting, mouse/key handlers, flying-parcel animation, and slot data setup; this callback should fill the remaining lifecycle, packet callback, timer/helper, singleton-global, and support rows.

## Current Generated Inventory

Generated file inspected:

`source-3/project-documentation/auto-generated/NexusTK/ui/panels/ParcelPane.cpp`

Current generated header:

```text
// validator-command-id: 000000001900
// validator-refreshed-at: 2026-06-30T00:56:39-04:00
// by-file UID: 0000MF
// source_root: NexusTK/ui/panels/
// source_subdir: <root>
// source_file: ParcelPane.cpp
```

Current empty marker count: 18.

| UID | Current generated target | Current score | Disposition |
|---|---|---:|---|
| 000058 | `by-class/FlyingParcelPane.md` | 88/91 | Comment-only no-code marker. Class support page only; implemented child methods already emit source. |
| 0001EN | `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md` | 86/91 | Comment-only no-code marker. MSVC scalar deleting destructor glue; ordinary destructor source is UID0002R5. |
| 0000A5 | `by-class/ParcelIconPane.md` | 85/86 | Comment-only class support marker, with pointers to constructor/destructor/callback children. |
| 0001EI | `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md` | 86/90 | First-draft C++ ordinary destructor body. |
| 0001EJ | `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md` | 86/90 | First-draft C++ packet/update callback body. |
| 0001EO | `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md` | 86/90 | Comment-only no-code marker. MSVC scalar deleting destructor glue; ordinary destructor source is UID0001EI. |
| 0000A6 | `by-class/ParcelPane.md` | 88/90 | Comment-only class support marker, with pointers to constructor/event/timer/helper children. |
| 0001EK | `by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md` | 85/89 | First-draft C++ ordinary destructor body. |
| 0002KF | `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md` | 87/91 | First-draft C++ timer body. |
| 0002KH | `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md` | 88/91 | First-draft C++ helper body. |
| 0002KI | `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md` | 89/92 | First-draft C++ helper body. |
| 0000RX | `by-global/g_pParcelIconPane.md` | 86/90 | First-draft global source declaration. |
| 0002W9 | `by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md` | 88/93 | Comment-only no-code marker covered by UID0000RX to avoid duplicate definition. |
| 0000RY | `by-global/g_pParcelPane.md` | 85/90 | First-draft global source declaration. |
| 0002OH | `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md` | 86/92 | Comment-only no-code marker. Compiler/linker vtable data, not handwritten source bytes. |
| 0002ZO | `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md` | 86/90 | Comment-only no-code marker covered by UID0000RY to avoid duplicate definition. |
| 0001VI | `by-type/by-struct/ParcelNotificationPaneLayouts.md` | 88/90 | Comment-only support marker. Layout evidence belongs in class/member docs, not standalone emitted source. |
| 0001YE | `by-type/by-vtable/ParcelNotificationVtableFamily.md` | 86/92 | Comment-only support marker. Vtables are regenerated from declarations/methods. |

## Evidence Checked

Project and assignment inputs:

- `goal.md` in `Agent-B005` confirms assignment `B005-report-0000MF-ParcelPane-empty-emitter-family-20260630`.
- Project-level `ntk-b-agent-workflow` skill and report/score standards were read before research.
- `Agent-B005/notes.md` contains no active notes.
- Direct tracker row for `UID0000MF` in `auto-generated/-ag-research-tracker.md` shows `ParcelPane`, total 29, filled 11, empty 18, `37.9%`, generated file `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`.

Current support docs inspected:

- `by-file/ParcelPane.md`
- `by-class/FlyingParcelPane.md`
- `by-class/ParcelIconPane.md`
- `by-class/ParcelPane.md`
- all 18 current empty-marker support targets listed in the inventory table

Prior reports used as leads, not as a substitute for this direct by-file report:

- B001 `0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality.md`
- B001 `0002KG-ParcelPaneOnPaint-source-quality.md`
- B001 `0002KK-FlyingParcelPaneAnimateStep-source-quality.md`
- B002 `0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md`
- B002 `0002KB-ParcelPaneConstructor-source-quality.md`
- B002 `0002KC-ParcelPaneSetParcelSlotData-source-quality.md`
- B002 `0002KE-ParcelPaneOnMouseEvent-source-quality.md`
- B003 `0002A0-ParcelAndPatchPaneSingletonSlots-memory-range-report.md`
- B003 `0002KL-FlyingParcelPaneDrawParcelOrLetter-source-quality.md`
- B004 `0002R5-FlyingParcelPaneCleanupDestructorBody-source-quality.md`
- B006 `0001EG-ParcelIconPaneConstructor-empty-emitter-source-quality.md`
- B006 `0002KM-ClearParcelIconPaneSingleton-source-quality.md`
- B006 `0002KN-ClearParcelPaneSingleton-source-quality.md`
- B007 `0001EH-ParcelNotificationPanes-source-quality.md`
- B007 `0002KJ-FlyingParcelPaneConstructor-source-quality.md`
- B007 `0002R6-FlyingParcelPaneStartAnimation-source-quality.md`
- B008 `0001EP-ParcelPaneScalarDeletingDestructor-empty-emitter-source-quality.md`
- B011 `0002KD-ParcelPaneOnKeyDown-source-quality.md`
- B012 `000058-FlyingParcelPane-class-source-quality.md`

Direct-report search result: no prior executed report with `TARGET-REPORT-UID:0000MF` was found in the narrowed executed/agent report search. The prior reports above are incorporated only as support leads.

## MCP Evidence

MCP endpoint checked through JSON-RPC at `http://127.0.0.1:13337/mcp`.

Active IDB session:

```text
session_id: supervisor_resume_20260629
filename: NexusTK.exe.i64
input_path: E:\NTK\Resources\NexusTK\NexusTK.exe.i64
owned/adopted worker pid: 17592
```

`server_health(database='supervisor_resume_20260629')` returned ok:

```text
module: NexusTK.exe
input_path: C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
```

Executable empty-row function identities:

| Address | MCP function | Size | Source interpretation |
|---:|---|---:|---|
| 0x00546070 | `sub_546070` | 0x78 | `ParcelIconPane::~ParcelIconPane` ordinary destructor |
| 0x005461c0 | `sub_5461C0` | 0xcd | `ParcelIconPane` parcel packet/update callback |
| 0x00546440 | `sub_546440` | 0x6c | `ParcelPane::~ParcelPane` ordinary destructor |
| 0x00546810 | `sub_546810` | 0x78 | `ParcelPane::OnTimer` / process slot animations |
| 0x00546970 | `sub_546970` | 0x6b | `ParcelPane::AdvanceButtonAnimation` |
| 0x005469e0 | `sub_5469E0` | 0xcb | `ParcelPane::ResolveButtonFrameIndex` |
| 0x00546ed0 | `sub_546ED0` | 0x67 | `FlyingParcelPane` scalar deleting destructor wrapper |
| 0x00546f40 | `sub_546F40` | 0xb9 | `ParcelIconPane` scalar deleting destructor wrapper |

Important data evidence:

- `0x0069b4d0` bytes: `00 00 00 00`; xrefs at `0x005048d5`, `0x00545e91`, `0x00545e98`, `0x005460c9`, `0x00546e70`, `0x00546fa0`. Source global is `ParcelIconPane *g_pParcelIconPane`.
- `0x0069ba28` bytes: starts with `00 00 00 00`; xrefs at `0x00545f03`, `0x00545f0a`, `0x005462e1`, `0x005462e8`, `0x0054648d`, `0x00546dbc`, `0x00546dd2`, `0x00546e80`, `0x00547054`. Source global is `ParcelPane *g_pParcelPane`.
- `0x00621bb0-0x00621d50` is the contiguous MSVC vtable region for the parcel notification pane family. It has data xrefs from constructors/destructors and callback-table slots, including `0x00621bb4`, `0x00621c10`, `0x00621c3c`, `0x00621c84`, `0x00621c88`, `0x00621cc4`, and `0x00621ccc`.

## Source-Shape Notes

Late VC-era source constraints used for the formal blocks:

- Use `NULL`, not `nullptr`.
- Use explicit simple integral types (`unsigned char`, `unsigned short`, `signed char`) where the binary stores byte fields.
- No `auto`, range-for, lambdas, `std::array`, `std::size`, `enum class`, or C++17 helpers.
- Ordinary destructor source omits vtable writes and implicit base destructor calls. The compiler emits those.
- Scalar deleting destructors are compiler wrappers and should be comment-only no-code markers unless the corresponding ordinary destructor is absent. Here the ordinary destructors are present or already emitted.

Wrapper-like names and confidence impact:

- `g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(...)` is not report scaffolding. It is the established source-facing name for `dword_67A74C` plus `sub_469180` from prior accepted cleanup-queue work and current destructor data flow. UID0001EI decompilation loads `this[63]` (`m_parcelPane`) and calls that queue helper before unregistering the icon pane.
- `RemoveFromLayer()` is the established inherited `Pane` source helper for `sub_544CE0`. UID0001EK calls it before unregistering.
- `UnregisterEventHandler()` is the established inherited `Pane` source helper for `sub_544D70`. UID0001EI and UID0001EK both call it.
- `PaneEvent::packetData` in UID0001EJ is the one first-draft source-facing wrapper name in this report. The exact binary data flow is `const unsigned char *packet = *(const unsigned char **)(event + 0x0c)`. The final project event type/member name is not fully proved by this row, so this caps confidence below final-source level, but it is a better source-shaped first draft than leaving a real callback empty. If the implementation reviewer has a settled event wrapper type, keep the body and substitute only the accepted type/member spelling.

## First-Draft C++ Recommendation

Insert the following formal `RECONSTRUCTION_CPP` bodies or comment-only markers into the listed target/support docs during the implementation callback.

### UID000058 `by-class/FlyingParcelPane.md`

```cpp
// No standalone class-page source body for FlyingParcelPane.
// The source methods for this implementation-private pane emit through the
// method pages in ParcelPane.cpp; this page records ownership and layout.
```

Proof: constructor UID0002KJ, ordinary cleanup destructor UID0002R5, `StartAnimation` UID0002R6, `AnimateStep` UID0002KK, and `DrawParcelOrLetter` UID0002KL already emit source. This class page is a support/ownership surface, not an additional executable body.

### UID0001EN `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md`

```cpp
// No handwritten source body: this is the MSVC scalar deleting destructor
// wrapper for FlyingParcelPane. The ordinary destructor source is emitted by
// UID0002R5, and the compiler regenerates this wrapper.
```

Proof: MCP decompile of `0x00546ed0` is scalar-deleting glue with vtable restoration, ordinary cleanup behavior, optional `operator delete`, and wrapper return semantics.

### UID0000A5 `by-class/ParcelIconPane.md`

```cpp
// No standalone class-page source body for ParcelIconPane.
// Constructor, destructor, parcel update callback, and compiler wrapper rows
// carry the source or no-code markers for this class.
```

Proof: constructor UID0001EG already emits; destructor UID0001EI and callback UID0001EJ should receive formal bodies below; scalar wrapper UID0001EO is compiler-generated.

### UID0001EI `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md`

```cpp
ParcelIconPane::~ParcelIconPane()
{
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(m_parcelPane);
    UnregisterEventHandler();
    g_pParcelIconPane = NULL;
}
```

Proof: MCP decompile loads `this[63]` (`m_parcelPane` at owner offset `+0xfc`), calls the cleanup queue helper (`dword_67A74C`/`sub_469180`), calls `sub_544D70` (`Pane::UnregisterEventHandler`), clears `unk_69B4D0`, then enters base cleanup. Vtable writes and base destructor call are compiler effects and should not be written in source.

### UID0001EJ `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md`

```cpp
bool ParcelIconPane::OnParcelUpdate(const PaneEvent *event)
{
    const unsigned char *packet;
    unsigned char flags;
    unsigned short countOffset;
    unsigned char packedCount;
    unsigned char leftCount;
    unsigned char rightCount;
    unsigned char totalCount;
    unsigned char previousTotal;

    packet = event->packetData;
    if (packet[0] != 8)
        return false;

    flags = packet[1];
    countOffset = (flags & 0x40) ? 31 : 2;
    if (flags & 0x20)
        countOffset += 8;
    if (flags & 0x10)
        countOffset += 9;
    if (flags & 0x08)
        countOffset += 5;

    packedCount = packet[countOffset];
    leftCount = packedCount & 0x0f;
    rightCount = packedCount >> 4;
    totalCount = leftCount + rightCount;

    previousTotal = m_totalParcelCount;
    m_totalParcelCount = totalCount;

    if (previousTotal > totalCount ||
        m_leftParcelCount < leftCount ||
        m_rightParcelCount < rightCount) {
        m_leftParcelCount = leftCount;
        m_rightParcelCount = rightCount;
        m_parcelPane->SetParcelSlotData(totalCount, leftCount, rightCount);
    }

    return false;
}
```

Proof: MCP decompile reads the packet pointer from event offset `+0x0c`, rejects packet type other than `8`, computes the count-byte offset from flag byte `packet[1]` using `0x40`, `0x20`, `0x10`, and `0x08`, splits the packed count byte into low/high nibbles, stores total at owner offset `+0xf8`, and forwards to `ParcelPane::SetParcelSlotData(total, left, right)` only when the previous total decreased or either decoded slot count increased past the locally stored value. `event->packetData` is the first-draft source-facing field name for the observed `*(event + 0x0c)` packet pointer.

### UID0001EO `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md`

```cpp
// No handwritten source body: this is the MSVC scalar deleting destructor
// wrapper for ParcelIconPane. The ordinary destructor source is emitted by
// UID0001EI, and the compiler regenerates this wrapper.
```

Proof: MCP decompile of `0x00546f40` contains wrapper glue, vtable restoration, ordinary destructor cleanup, optional delete, and scalar-deleting return semantics.

### UID0000A6 `by-class/ParcelPane.md`

```cpp
// No standalone class-page source body for ParcelPane.
// Constructor, slot-data, input, paint, destructor, timer, and helper rows
// carry the source for this class.
```

Proof: constructor UID0002KB, `SetParcelSlotData` UID0002KC, `OnKeyDown` UID0002KD, `OnMouseEvent` UID0002KE, and `OnPaint` UID0002KG already emit. Destructor and helper rows below should finish the remaining source bodies.

### UID0001EK `by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md`

```cpp
ParcelPane::~ParcelPane()
{
    RemoveFromLayer();
    UnregisterEventHandler();
    g_pParcelPane = NULL;
}
```

Proof: MCP decompile calls `sub_544CE0` (`Pane::RemoveFromLayer`), `sub_544D70` (`Pane::UnregisterEventHandler`), clears `unk_69BA28`, then calls base cleanup. Vtable writes and base destructor are compiler effects.

### UID0002KF `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md`

```cpp
bool ParcelPane::OnTimer(int, int, int)
{
    if (m_leftParcelCount != 0 && !m_leftSlotAcknowledged)
        AdvanceButtonAnimation(&m_leftButtonState, &m_leftAnimationFrame, false);
    if (m_rightParcelCount != 0 && !m_rightSlotAcknowledged)
        AdvanceButtonAnimation(&m_rightButtonState, &m_rightAnimationFrame, true);

    InvalidateRect(&m_bounds);
    m_timerHandler.ScheduleTimer(0, 200, 0, 0);
    return true;
}
```

Proof: MCP decompile at `0x00546810` tests owner bytes `+0xf9/+0xfa` and `+0x120/+0x121`, calls the animation helper on left/right state/frame byte pairs, invalidates the pane bounds through the primary vtable slot, schedules another timer with delay `200`, and returns `1`.

### UID0002KH `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md`

```cpp
void ParcelPane::AdvanceButtonAnimation(ParcelButtonState *state,
                                        signed char *frame,
                                        bool rightSide)
{
    if (*state == kParcelButtonIdle) {
        if (*frame < 0) {
            ++*frame;
            return;
        }

        *state = kParcelButtonAnimating;
        *frame = rightSide ? 20 : 6;
        return;
    }

    if (*state == kParcelButtonAnimating) {
        ++*frame;
        if (rightSide) {
            if (*frame > 27) {
                *frame = 20;
                *state = kParcelButtonIdle;
            }
        } else {
            if (*frame > 13) {
                *frame = 6;
                *state = kParcelButtonIdle;
            }
        }
    }
}
```

Proof: MCP decompile at `0x00546970` mutates the byte state pointer and signed frame pointer. Idle state with a negative frame increments toward zero. Idle with a nonnegative frame enters animation and seeds frame `6` for left or `20` for right. Animating state increments the frame and wraps/reset to idle after `13` for left or `27` for right.

### UID0002KI `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md`

```cpp
int ParcelPane::ResolveButtonFrameIndex(const ParcelButtonState *state,
                                        unsigned char slotCount,
                                        bool rightSide) const
{
    switch (*state) {
    case kParcelButtonIdle:
        if (slotCount != 0)
            return rightSide ? 17 : 3;
        return rightSide ? 14 : 0;

    case kParcelButtonHover:
        if (slotCount != 0)
            return rightSide ? 18 : 4;
        return rightSide ? 15 : 1;

    case kParcelButtonPressed:
        if (slotCount != 0)
            return rightSide ? 19 : 5;
        return rightSide ? 16 : 2;

    case kParcelButtonAnimating:
        return rightSide ? m_rightAnimationFrame : m_leftAnimationFrame;

    default:
        return 0;
    }
}
```

Proof: MCP decompile at `0x005469e0` switches on the byte state. Idle/hover/pressed return frame triplets for left empty/occupied (`0/1/2` and `3/4/5`) or right empty/occupied (`14/15/16` and `17/18/19`). Animating returns `m_leftAnimationFrame` at owner offset `+0xfe` or `m_rightAnimationFrame` at `+0xff`.

### UID0000RX `by-global/g_pParcelIconPane.md`

```cpp
ParcelIconPane *g_pParcelIconPane = NULL;
```

Proof: exact storage child at `0x0069b4d0` is four zero bytes with six xrefs; constructor and destructor rows read/write this singleton slot. Use the by-global row as the single source declaration.

### UID0002W9 `by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md`

```cpp
// No separate source definition here. The exact storage at 0x0069b4d0 is
// covered by the source global declaration in UID0000RX:
//     ParcelIconPane *g_pParcelIconPane = NULL;
```

Proof: this memory row is the exact storage child for the by-global declaration. Emitting a second definition would duplicate the source global.

### UID0000RY `by-global/g_pParcelPane.md`

```cpp
ParcelPane *g_pParcelPane = NULL;
```

Proof: exact storage child at `0x0069ba28` is a zero-initialized singleton slot with constructor/destructor and external singleton-manager xrefs. Use the by-global row as the single source declaration.

### UID0002OH `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`

```cpp
// No handwritten vtable-byte source for ParcelNotificationVtableData.
// The MSVC vtables are regenerated from the class declarations and virtual
// method bodies for ParcelIconPane, ParcelPane, and FlyingParcelPane.
```

Proof: the region is contiguous vtable/callback-table data. Constructors/destructors write pointers into this region, and child method xrefs identify virtual slot ownership. It is not source-authored byte data.

### UID0002ZO `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md`

```cpp
// No separate source definition here. The exact storage at 0x0069ba28 is
// covered by the source global declaration in UID0000RY:
//     ParcelPane *g_pParcelPane = NULL;
```

Proof: this memory row is the exact storage child for the by-global declaration. Emitting a second definition would duplicate the source global.

### UID0001VI `by-type/by-struct/ParcelNotificationPaneLayouts.md`

```cpp
// No standalone source body for ParcelNotificationPaneLayouts.
// This support page records recovered member offsets and enum/layout facts;
// the actual source fields belong with the ParcelIconPane, ParcelPane, and
// FlyingParcelPane class declarations.
```

Proof: the page is a type/layout aggregation surface. The currently recoverable fields are already consumed by child source methods, including `m_parcelPane`, parcel counts, button states, animation frames, slot rectangles, and acknowledgement flags.

### UID0001YE `by-type/by-vtable/ParcelNotificationVtableFamily.md`

```cpp
// No handwritten source body for ParcelNotificationVtableFamily.
// The compiler regenerates this vtable family from the class declarations,
// virtual destructors, callbacks, and virtual method overrides.
```

Proof: this page documents the vtable family, callback slots, and ownership route. It is not a handwritten source construct.

## Score And Metadata Recommendation

Recommended post-implementation score movement, subject to supervisor validation:

| UID | Recommended score | Reason |
|---|---:|---|
| 0000MF | 90/90 | All current empty emitters have bounded source/no-code dispositions; callback/event type remains first-draft. |
| 000058 | 88/91 | Keep stable; class page is no-code support and child methods already carry source. |
| 0001EN | 86/91 | Keep stable; compiler wrapper no-code marker. |
| 0000A5 | 88/90 | Class support strengthened once destructor/callback rows are inserted. |
| 0001EI | 88/91 | Ordinary destructor body is source-shaped and evidence-backed. |
| 0001EJ | 88/91 | Packet callback body is evidence-backed; event wrapper name caps confidence. |
| 0001EO | 86/90 | Keep stable; compiler wrapper no-code marker. |
| 0000A6 | 90/91 | Class support strengthened once destructor/timer/helper rows are inserted. |
| 0001EK | 88/91 | Ordinary destructor body is source-shaped and evidence-backed. |
| 0002KF | 90/92 | Timer behavior and scheduling are directly recovered. |
| 0002KH | 90/92 | Animation state/frame mutation is directly recovered. |
| 0002KI | 91/92 | Frame mapping is directly recovered and already aligned with paint source. |
| 0000RX | 88/91 | Singleton global declaration is direct from exact storage/xrefs. |
| 0002W9 | 88/93 | Keep stable; exact storage child covered by UID0000RX. |
| 0000RY | 88/91 | Singleton global declaration is direct from exact storage/xrefs. |
| 0002OH | 86/92 | Keep stable; vtable data no-code marker, not source bytes. |
| 0002ZO | 86/90 | Keep stable; exact storage child covered by UID0000RY. |
| 0001VI | 88/90 | Keep stable; layout support no-code marker. |
| 0001YE | 86/92 | Keep stable; vtable-family support no-code marker. |

No row should be promoted to final/high-90s in this callback because the exact packet event type/member spelling and complete class header declaration shape remain first-draft.

## Claim And Incorporation Ledger

| Claim ID | Claim | Destination | Required action | Verification state |
|---|---|---|---|---|
| C-0000MF-01 | Current generated `ParcelPane.cpp` had 18 empty markers under validator command `000000001900`. | `by-file/ParcelPane.md` | Add B005 support note and implementation inventory. | applied - B005 implementation note/inventory inserted; final validator `000000002088`, `2026-06-30T01:38:55-04:00`, exit `0`, `ok: 1`; generated `ParcelPane.cpp` command `000000002089` now has `0` empty markers. |
| C-0000MF-02 | `FlyingParcelPane` class row is support-only because all handwritten methods emit through child rows. | `by-class/FlyingParcelPane.md` | Insert comment-only no-code marker. | applied - formal comment-only support marker inserted; final validator `000000002089`, `2026-06-30T01:39:05-04:00`, exit `0`, `ok: 1`. |
| C-0000MF-03 | `0x00546ed0` is MSVC scalar deleting destructor glue for `FlyingParcelPane`. | `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md` | Insert compiler-wrapper no-code marker. | applied - compiler-wrapper no-code marker inserted; validator `000000002018`, exit `0`, `ok: 1`. |
| C-0000MF-04 | `ParcelIconPane` class row is support-only after constructor/destructor/callback/scalar rows are handled. | `by-class/ParcelIconPane.md` | Insert comment-only class support marker and link child rows. | applied - class marker and B005 support text inserted; validator `000000002019`, exit `0`, `ok: 1`. |
| C-0000MF-05 | `0x00546070` is ordinary `ParcelIconPane::~ParcelIconPane` and queues `m_parcelPane`, unregisters, and clears `g_pParcelIconPane`. | `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md` | Insert formal destructor C++ body. | applied - formal destructor body inserted; validator `000000002020`, exit `0`, `ok: 1`. |
| C-0000MF-06 | `0x005461c0` is the parcel packet/update callback and decodes counts from packet data at event offset `+0x0c`. | `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md` | Insert formal callback C++ body with documented first-draft event wrapper. | applied - formal callback body inserted with `PaneEvent::packetData` caveat; validator `000000002021`, exit `0`, `ok: 1`. |
| C-0000MF-07 | `0x00546f40` is MSVC scalar deleting destructor glue for `ParcelIconPane`. | `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md` | Insert compiler-wrapper no-code marker. | applied - compiler-wrapper no-code marker inserted and stale blank-C++ prose normalized; validator `000000002022`, exit `0`, `ok: 1`. |
| C-0000MF-08 | `ParcelPane` class row is support-only once child method rows carry source. | `by-class/ParcelPane.md` | Insert comment-only class support marker and link child rows. | applied - class marker and child-source notes inserted; validator `000000002023`, exit `0`, `ok: 1`. |
| C-0000MF-09 | `0x00546440` is ordinary `ParcelPane::~ParcelPane`, removing from layer, unregistering, and clearing `g_pParcelPane`. | `by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md` | Insert formal destructor C++ body. | applied - formal destructor body inserted; validator `000000002024`, exit `0`, `ok: 1`. |
| C-0000MF-10 | `0x00546810` is the timer/process-slot-animation body and reschedules itself for 200ms. | `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md` | Insert formal timer C++ body. | applied - formal timer body inserted; validator `000000002025`, exit `0`, `ok: 1`. |
| C-0000MF-11 | `0x00546970` advances idle/animating button states and wraps animation frames. | `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md` | Insert formal helper C++ body. | applied - formal animation helper body inserted; validator `000000002026`, exit `0`, `ok: 1`. |
| C-0000MF-12 | `0x005469e0` maps button state/count/side to frame indices and returns active animation frame in state 3. | `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md` | Insert formal helper C++ body. | applied - formal frame resolver body inserted; validator `000000002027`, exit `0`, `ok: 1`. |
| C-0000MF-13 | `0x0069b4d0` is the singleton source global `ParcelIconPane *g_pParcelIconPane = NULL;`. | `by-global/g_pParcelIconPane.md` | Insert formal global declaration. | applied - formal global declaration inserted; validator `000000002028`, exit `0`, `ok: 1`. |
| C-0000MF-14 | Exact storage child for `g_pParcelIconPane` must not emit a duplicate source definition. | `by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md` | Insert covered-by-global no-code marker. | applied - covered-by-global no-code marker inserted; validator `000000002029`, exit `0`, `ok: 1`. |
| C-0000MF-15 | `0x0069ba28` is the singleton source global `ParcelPane *g_pParcelPane = NULL;`. | `by-global/g_pParcelPane.md` | Insert formal global declaration. | applied - formal global declaration inserted; validator `000000002030`, exit `0`, `ok: 1`. |
| C-0000MF-16 | Exact storage child for `g_pParcelPane` must not emit a duplicate source definition. | `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md` | Insert covered-by-global no-code marker. | applied - covered-by-global no-code marker inserted; validator `000000002032`, exit `0`, `ok: 1`. |
| C-0000MF-17 | `0x00621bb0-0x00621d50` is compiler/linker vtable data, not handwritten source bytes. | `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md` | Insert vtable-data no-code marker. | applied - vtable-data no-code marker inserted; validator `000000002031`, exit `0`, `ok: 1`. |
| C-0000MF-18 | `ParcelNotificationPaneLayouts` is a layout support page, not a standalone source body. | `by-type/by-struct/ParcelNotificationPaneLayouts.md` | Insert layout-support no-code marker. | applied - layout-support no-code marker inserted; validator `000000002033`, exit `0`, `ok: 1`. |
| C-0000MF-19 | `ParcelNotificationVtableFamily` is vtable-family support, not handwritten source. | `by-type/by-vtable/ParcelNotificationVtableFamily.md` | Insert vtable-family no-code marker. | applied - vtable-family no-code marker inserted; validator `000000002034`, exit `0`, `ok: 1`. |
| C-0000MF-20 | Implementation should not edit generated files or coverage reports manually. | Implementation callback | Run validators from `source-3/project-documentation` and inspect regenerated `ParcelPane.cpp`. | applied - no manual generated/coverage edits; scoped validators `000000002016`-`000000002034` plus follow-up `000000002088`/`000000002089` all exit `0`/`ok: 1`; final generated file is fresh at `000000002089` and has `0` `Empty Emitter Marker` hits. |

## Implementation Tracking Checklist

- [x] Acquire short leases only immediately before editing accepted target/support docs. Proof: `leaser.py B005 lease` returned `Success` for all 19 accepted by-* paths before edit/validator batch.
- [x] Update `by-file/ParcelPane.md` with the B005 accepted report note, current inventory resolution, and recommended metadata movement. Proof: final validator `000000002088`, exit `0`, `ok: 1`.
- [x] Insert UID000058 comment-only no-code marker in `by-class/FlyingParcelPane.md`. Proof: final validator `000000002089`, exit `0`, `ok: 1`.
- [x] Insert UID0001EN scalar-wrapper no-code marker in `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md`. Proof: validator `000000002018`, exit `0`, `ok: 1`.
- [x] Insert UID0000A5 class support no-code marker in `by-class/ParcelIconPane.md`. Proof: validator `000000002019`, exit `0`, `ok: 1`.
- [x] Insert UID0001EI `ParcelIconPane::~ParcelIconPane` formal C++ body in `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md`. Proof: validator `000000002020`, exit `0`, `ok: 1`.
- [x] Insert UID0001EJ `ParcelIconPane::OnParcelUpdate` formal C++ body in `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md`. Proof: validator `000000002021`, exit `0`, `ok: 1`.
- [x] Insert UID0001EO scalar-wrapper no-code marker in `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md`. Proof: validator `000000002022`, exit `0`, `ok: 1`.
- [x] Insert UID0000A6 class support no-code marker in `by-class/ParcelPane.md`. Proof: validator `000000002023`, exit `0`, `ok: 1`.
- [x] Insert UID0001EK `ParcelPane::~ParcelPane` formal C++ body in `by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md`. Proof: validator `000000002024`, exit `0`, `ok: 1`.
- [x] Insert UID0002KF `ParcelPane::OnTimer` formal C++ body in `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md`. Proof: validator `000000002025`, exit `0`, `ok: 1`.
- [x] Insert UID0002KH `ParcelPane::AdvanceButtonAnimation` formal C++ body in `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md`. Proof: validator `000000002026`, exit `0`, `ok: 1`.
- [x] Insert UID0002KI `ParcelPane::ResolveButtonFrameIndex` formal C++ body in `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md`. Proof: validator `000000002027`, exit `0`, `ok: 1`.
- [x] Insert UID0000RX global declaration in `by-global/g_pParcelIconPane.md`. Proof: validator `000000002028`, exit `0`, `ok: 1`.
- [x] Insert UID0002W9 covered-by-global no-code marker in `by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md`. Proof: validator `000000002029`, exit `0`, `ok: 1`.
- [x] Insert UID0000RY global declaration in `by-global/g_pParcelPane.md`. Proof: validator `000000002030`, exit `0`, `ok: 1`.
- [x] Insert UID0002OH vtable-data no-code marker in `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`. Proof: validator `000000002031`, exit `0`, `ok: 1`.
- [x] Insert UID0002ZO covered-by-global no-code marker in `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md`. Proof: validator `000000002032`, exit `0`, `ok: 1`.
- [x] Insert UID0001VI layout-support no-code marker in `by-type/by-struct/ParcelNotificationPaneLayouts.md`. Proof: validator `000000002033`, exit `0`, `ok: 1`.
- [x] Insert UID0001YE vtable-family no-code marker in `by-type/by-vtable/ParcelNotificationVtableFamily.md`. Proof: validator `000000002034`, exit `0`, `ok: 1`.
- [x] Update this report ledger from `proposed` to `applied`, `already-present`, or `excluded-with-reason` with exact proof. Proof: this section and the ledger above record applied states.
- [x] Run scoped validators for every changed target/support doc from `source-3/project-documentation`; record command id, timestamp, exit, and ok status. Proof: validator table below.
- [x] Inspect regenerated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` freshness and remaining `Empty Emitter Marker` count. Proof: final generated header `validator-command-id: 000000002089`, refreshed `2026-06-30T01:39:05-04:00`, foreground-generated-refresh; empty marker count `0`.
- [x] Release leases immediately after edit/validator batch and record release or expiry proof. Proof: final `leaser.py B005 unlease` returned `Success` for `by-file/ParcelPane.md` and `by-class/FlyingParcelPane.md`; `current_leases.md` then reported `No active leases`.

## Validator Status

Scoped validators were run from `source-3/project-documentation`; every changed by-* doc returned exit `0` and `ok: 1`.

| File | command_id | command_timestamp | exit | ok |
|---|---|---|---:|---:|
| `by-file/ParcelPane.md` | `000000002088` | `2026-06-30T01:38:55-04:00` | 0 | 1 |
| `by-class/FlyingParcelPane.md` | `000000002089` | `2026-06-30T01:39:05-04:00` | 0 | 1 |
| `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md` | `000000002018` | `2026-06-30T01:29:16-04:00` | 0 | 1 |
| `by-class/ParcelIconPane.md` | `000000002019` | `2026-06-30T01:29:18-04:00` | 0 | 1 |
| `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md` | `000000002020` | `2026-06-30T01:29:19-04:00` | 0 | 1 |
| `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md` | `000000002021` | `2026-06-30T01:29:21-04:00` | 0 | 1 |
| `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md` | `000000002022` | `2026-06-30T01:29:23-04:00` | 0 | 1 |
| `by-class/ParcelPane.md` | `000000002023` | `2026-06-30T01:29:25-04:00` | 0 | 1 |
| `by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md` | `000000002024` | `2026-06-30T01:29:27-04:00` | 0 | 1 |
| `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md` | `000000002025` | `2026-06-30T01:29:28-04:00` | 0 | 1 |
| `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md` | `000000002026` | `2026-06-30T01:29:30-04:00` | 0 | 1 |
| `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md` | `000000002027` | `2026-06-30T01:29:32-04:00` | 0 | 1 |
| `by-global/g_pParcelIconPane.md` | `000000002028` | `2026-06-30T01:29:33-04:00` | 0 | 1 |
| `by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md` | `000000002029` | `2026-06-30T01:29:35-04:00` | 0 | 1 |
| `by-global/g_pParcelPane.md` | `000000002030` | `2026-06-30T01:29:37-04:00` | 0 | 1 |
| `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md` | `000000002031` | `2026-06-30T01:29:39-04:00` | 0 | 1 |
| `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md` | `000000002032` | `2026-06-30T01:29:40-04:00` | 0 | 1 |
| `by-type/by-struct/ParcelNotificationPaneLayouts.md` | `000000002033` | `2026-06-30T01:29:42-04:00` | 0 | 1 |
| `by-type/by-vtable/ParcelNotificationVtableFamily.md` | `000000002034` | `2026-06-30T01:29:44-04:00` | 0 | 1 |

Final generated refresh completed during the follow-up `by-class/FlyingParcelPane.md` validator: command_id `000000002089`, command_timestamp `2026-06-30T01:39:05-04:00`, exit `0`, `generated_refresh: completed`. Final `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` reports `validator-command-id: 000000002089`, `validator-refresh-source: foreground-generated-refresh`, and `0` `Empty Emitter Marker` hits. The generated file currently renders the direct file/class/global/support source surface; exact method bodies are applied and registered as `block`/`coded` in their by-* targets and validator metadata.

## Implementation Changed Files

Changed target/support docs:

- `by-file/ParcelPane.md`
- `by-class/FlyingParcelPane.md`
- `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md`
- `by-class/ParcelIconPane.md`
- `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md`
- `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md`
- `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md`
- `by-class/ParcelPane.md`
- `by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md`
- `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md`
- `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md`
- `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md`
- `by-global/g_pParcelIconPane.md`
- `by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md`
- `by-global/g_pParcelPane.md`
- `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`
- `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md`
- `by-type/by-struct/ParcelNotificationPaneLayouts.md`
- `by-type/by-vtable/ParcelNotificationVtableFamily.md`
- `tools/leaser/Agents/Agent-B005/research/0000MF-ParcelPane-empty-emitter-family-source-quality.md`

No manual coverage-report, IDA DB, executed archive, supervisor ledger, or lock-file edits were made. Generated output was refreshed only by the validator/autogen commands and then inspected.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000MF-ParcelPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0000MF-ParcelPane-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T02:37:08","uid":"0000MF"} -->
<!-- {"agent":"B005","command_id":"000000023041","details":"report marked for revalidation","event":"needs-revalidation","issue":"malformed TARGET-REPORT-UID header","source_path":"executed-b-agent-research/B005/0000MF-ParcelPane-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:49:38-04:00","uid":"0000MF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
